//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************



#include "Pei.h"
#include "PeiLib.h"
#include "DramUtil.h"
#include "Draminit.h"
#include "SIDramTbl.h"
#include "debug/DramDebug.h"
#include "hardcode/Hardcode.h"
#include "debug/soft_reboot.h"
#include "IOTimingControl.h"
#include "InitDRAMByRank.h"
#include "VrefCalibration.h"
#include "SIValueProgramming.h"
#include "UpdateRankAddr.h"

UINT8 MaTableMRS[14] = 
{
//     BG1      BG0      BA1       BA0     MA13  MA12  MA11  MA10  MA09  MA08  MA07  MA06 MA05 MA04 MA03 MA02 MA01 MA00
//   15^20,  14^7,  18^23,  17^22,    23,      22,      21,      20,      12,       11,     10,       9,       8,        7,      6,       5,       4,       3
3,4,5,6,7,8,9,10,11,12,20,21,22,23
};

UINT32 GetMprAddr(
IN UINT8 NewPattern,
IN UINT8 MprNo	)
{
	UINT32 MprAddr = 0;
	UINT8 PatternAddr = 0;
	UINT8 i;
	UINT8 index;

	//SDRAM Address     A7  A6   A5   A4  A3   A2   A1   A0
	//UI                          UI0 UI1 UI2 UI3 UI4 UI5 UI6  UI7 
	for(i = 0; i < 8; i++)
	{
		PatternAddr |= (((NewPattern >> i) & 0x01) << (7 - i));
	}

	//A0 -A7
	for(i = 0; i <= 7; i++)
	{
		index = MaTableMRS[i];
		MprAddr |= ((PatternAddr >> i) & 0x01) << index; 
	}

	//BA1 : BA0
	MprAddr |= GetMrsNo(MprAddr, MprNo);

	return MprAddr;
}


VOID WriteMprPattern(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 NewPattern,
		IN UINT8 MprNo)
{
	UINT64 Address;
	UINT32 Buffer32 = 0x00, MrsSet32 = 0x00, DummyReadBase=0x00;
	UINT16  SavedREFC = 0;
	UINT16 SavedBARASelect = 0;
	UINT16  SavedSelfRef = 0;
	/*UINT16  SavedOdt = 0;*/

	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;

	//Set BA SEL  FIRST
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);

	//Disable REF
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);	

	//Save Selfrefresh and disable
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);

	//Save ODT and disable
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);*/

	//Clear all VRank size
	ClearAllRankSize(DramAttr);	

	//LGE20160420 Enable TargetRank and disable other rank --NOT USE NOW
	//EnableTargetRank(PeiServices, pPCIPPI, DramAttr, RankIndex); 

	// Map each Physical Rank N to Virtual Rank N
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

	//Enable Readleveling, RX201[7], RDMRLEN 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);

	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 1ms

	//Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//Enable MPR
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, MR3_MPR_EN | MR3_MPR_PAGE0);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	//Wait for some time --tMOD
	WaitForMicroSec(PeiServices, 100);

	//Set Normal mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);	
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	Buffer32 = GetMprAddr(NewPattern, MprNo);
	//Rank mirror
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		Buffer32 = Rank1AddressMirror(PeiServices, Buffer32);
	*(UINT32 volatile *)(UINT32)(Buffer32) = 0x00;   //Dummy Write
	
	//Wait for some time -- tWR_MPR
	WaitForMicroSec(PeiServices, 100);

	//Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//Disable MPR
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, DDR4_MR3_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

	//Wait for some time --tMOD
	WaitForMicroSec(PeiServices, 100);

	//Set Normal mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Precharge all
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);
		//LGE20160420 flush CFG write for RSDM registers
		FlushCfgWrite(PeiServices, DramAttr, Address);

		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 1ms

		//Set MRS mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
		//LGE20160420 flush CFG write for RSDM registers
		FlushCfgWrite(PeiServices, DramAttr, Address);

		//Enable MPR
		Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, MR3_MPR_EN | MR3_MPR_PAGE0);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 10us
		//Wait for some time --tMOD
		WaitForMicroSec(PeiServices, 100);

		//Set Normal mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);	
		//LGE20160420 flush CFG write for RSDM registers
		FlushCfgWrite(PeiServices, DramAttr, Address);

		Buffer32 = GetMprAddr(NewPattern, MprNo);
		//Rank mirror
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
			Buffer32 = Rank1AddressMirror(PeiServices, Buffer32);

		//Init RDIMM SIDE B 
		Buffer32 = SideBAddressInvert(PeiServices, Buffer32);
		*(UINT32 volatile *)(UINT32)(Buffer32) = 0x00;   //Dummy Write
		WaitForMicroSec(PeiServices, 10);	//delay 10us

		//Wait for some time -- tWR_MPR
		WaitForMicroSec(PeiServices, 100);

		//Set MRS mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
		//LGE20160420 flush CFG write for RSDM registers
		FlushCfgWrite(PeiServices, DramAttr, Address);

		//Disable MPR
		Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, DDR4_MR3_INIT);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 10us
		//Wait for some time --tMOD
		WaitForMicroSec(PeiServices, 100);

		//Set Normal mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
		//LGE20160420 flush CFG write for RSDM registers
		FlushCfgWrite(PeiServices, DramAttr, Address);
	}
	//Disable ReadLeveling
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);

	//Restore MA table
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);

	//Restore Refresh Counter    
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);

	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);

	//Restore ODT	
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOdt);*/

}


// TNI Calibraion Related
// clear -- save --set --calibration
// CLEAR
VOID Rx_TNI_ClearDataset(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex)
{
	UINT8 ByteIndex = 0;
	UINT8 RankBegin = 0, RankEnd = 0;

	if(RankIndex == ALLRANK)
	{
		RankBegin = 0;
		RankEnd = ASIA_MAX_RANKS ;
	}
	else
	{
		RankBegin = RankIndex ;
		RankEnd  = RankIndex + 1 ;
	}
	for(RankIndex = RankBegin ; RankIndex < RankEnd ; RankIndex++)
	{
		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES; ByteIndex++)//all Byte include ECC byte
		{
			DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_LOW = 0;
			DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_HIGH = 0;
			DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting = 0;
			DramAttr->DramAutoCal[RankIndex][ByteIndex].CalResult = FALSE;
		}
	}
}


UINT16 Rx_TNI_Convert_To_Value(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16)
{
	UINT64 Address = 0x00;
	UINT8 Rtim_flag = 0; 
	UINT16 Ph_dclock = 0;

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	if((AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_RTIMCHKSEL))
		Rtim_flag =1;
	else
		Rtim_flag =0;

	if(RankIndex < 4)
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_CLK_PI_PHASE_CTL_CHN_A);
	else
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_CLK_PI_PHASE_CTL_CHN_B);

	Ph_dclock = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

	return (Value16 +(Rtim_flag*8) + Ph_dclock)&0x3F ;
}

UINT16 Rx_TNI_Convert_To_Index(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16)
{
	UINT64 Address = 0x00;
	UINT8 Rtim_flag = 0; 
	UINT16 Ph_dclock = 0;
	UINT16 ValueTmp;
	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	if((AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_RTIMCHKSEL))
		Rtim_flag =1;
	else
		Rtim_flag =0;

	if(RankIndex < 4)
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_CLK_PI_PHASE_CTL_CHN_A);
	else
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_CLK_PI_PHASE_CTL_CHN_B);

	Ph_dclock = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

	ValueTmp = ((Rtim_flag * 8) + Ph_dclock)&0x3F;

	return  (Value16+(0x40 - ValueTmp))%0x40;
	
}

//Save
VOID Rx_TNI_SaveDataSet(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 ByteNo)
{
	UINT8  ByteIndex = 0;
	UINT8  ByteBegin = 0;
	UINT8  ByteEnd = 0;
	UINT16 Value16 = 0;

	if(ByteNo == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = ASIA_MAX_BYTES;
	}
	else
	{
		ByteBegin = ByteNo;
		ByteEnd = ByteNo+1;
	}

	//RKD-debug only
	PEI_DEBUG((PeiServices, EFI_D_WARN, "\r\n===BEG:Debug Message for TNI SaveDataSet=== \n"));	

	PEI_DEBUG((PeiServices, EFI_D_WARN, "\r\n===ReadOut TNI High Bound=== \n"));	
	//HIGH Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_HIGH = Value16*0x40; // convert wholeT to phase


		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE,   IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		//calibration value to index
		/*Value16= Rx_RDSIT_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);*/
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_HIGH += Value16; //add tni phase

		//RKD-debug only
		PEI_DEBUG((PeiServices, EFI_D_WARN, "Rank:%d Byte%d TNI_HIGH = %d P \r\n",RankIndex, ByteIndex,DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_HIGH));	
	}

	PEI_DEBUG((PeiServices, EFI_D_WARN, "\r\n===ReadOut TNI Low Bound=== \n"));	
	//LOW Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_LOW = Value16*0x40; // convert wholeT to phase
		
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE,   IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		/*Value16= Rx_RDSIT_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);*/
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_LOW += Value16; // add tni phase 
		//
		//RKD-debug only
		PEI_DEBUG((PeiServices, EFI_D_WARN, "Rank:%d Byte%d TNI_LOW = %d P \r\n",RankIndex, ByteIndex,DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_LOW));	
	}
	//RKD-debug only
	PEI_DEBUG((PeiServices, EFI_D_WARN, "===END:Debug Message for TNI SaveDataSet=== \r\n\n"));	
}

//CHECK
BOOLEAN Rx_TNI_ReadLeveling_CheckRange(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,	
		IN BOOLEAN ECC_ENABLE,
		OUT UINT16 *TNIRange)
{
	BOOLEAN Flag = TRUE;
	UINT8 ByteIndex;
	UINT16 TNI_LOW = 0;
	UINT16 TNI_HIGH = 0;

	PEI_DEBUG((PeiServices, EFI_D_WARN, "\r\n\r\n===BEG:Debug Message for TNI CheckRange=== \n"));	
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{	   		
		TNI_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_LOW;
		TNI_HIGH = DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_HIGH;
		//RKD-debug only
		PEI_DEBUG((PeiServices, EFI_D_WARN, "Rank%d Byte%d TNI Range = %d P \n\r",RankIndex, ByteIndex, TNI_HIGH - TNI_LOW ));	
		if(TNI_LOW >= TNI_HIGH)
		{
			Flag = FALSE;
			break;
		}
		else{
			if(TNI_HIGH - TNI_LOW < TNI_THRESHOLD)
			{
				Flag = FALSE;
				break;
			}
			else
			{
				TNIRange[ByteIndex] = TNI_HIGH - TNI_LOW;
			}
		}	
	if(DramAttr->ConfigData.TNIHighPulse){
	//LGE20180620 for HIGH PULSE	
		if (DramAttr->RPREA == RPREA1CLK)
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNI_HIGH - 0x18;				
		else
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNI_HIGH - 0x20;				
			
	}
	else
		DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=(TNI_LOW+TNI_HIGH)/2;
//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%4x ",DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting));	

		ByteIndex+=1;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "===END:Debug Message for TNI CheckRange=== \r\n\r\n"));	
	return Flag;
}

VOID Rx_TNI_Set_byChannel(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT16 TNI_Setting)
{
	UINT8	RankBegin,RankEnd,TmpRank;
	UINT16 Value16;
	if (RankIndex <4) {
		RankBegin=0;
		RankEnd=4;
	}else {
		RankBegin=4;
		RankEnd=8;

	}
	//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n\r\n=========BEG:TNI Seting byChannel=========\r\n"));		
	for(TmpRank = RankBegin;TmpRank < RankEnd ;TmpRank++) {
		for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES ;ByteIndex++) {

		Value16 = (TNI_Setting & 0x3C0)>>(RegisterOffset16bit(0x3C0));
		//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:Rank%d, Byte%d, TNI WholeT:%d  ",RankIndex,ByteIndex,Value16));		
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, TmpRank, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		Value16 = TNI_Setting % 0x40;
		Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);

		//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "PHASE:0x%x\r\n",Value16));		
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, TmpRank, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
	}
		}
	//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "=========END:TNI Seting byBrank=========\r\n\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID Rx_TNI_byChannel(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 RankIndex)
{
	UINT8  ByteIndex = 0;
	UINT16 TNI_Setting;

	UINT16 Value16;
	UINT8  RankBegin = 0, RankEnd=8,RankCount=0;
	RankBegin=RankIndex;
	RankEnd =RankIndex+4;
	TNI_Setting=0;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n=========BEG:TNI Seting byChannel=========\r\n"));		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI Rank%d,RankBegin:%x ",RankIndex,RankBegin));		
	RankCount=0;
	for(RankIndex = RankBegin; RankIndex <RankEnd;RankIndex++) 	{
	if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) {
	RankCount++;	
	
	if(RankIndex !=RankBegin) {
		for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
		{
//			TNI_Setting=0;
//			TNI_Setting+ = DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting;
			DramAttr->DramAutoCal[RankBegin][ByteIndex].TNI_Setting+= DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%x  ",DramAttr->DramAutoCal[RankBegin][ByteIndex].TNI_Setting));	
			
		}
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));		
		}
		}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankCount %d  ",RankCount)); 	
	
	for(RankIndex = RankBegin; RankIndex <RankEnd;RankIndex++) 	{

		for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
		{
			TNI_Setting = DramAttr->DramAutoCal[RankBegin][ByteIndex].TNI_Setting;
			TNI_Setting = TNI_Setting/RankCount;

			Value16 = (TNI_Setting & 0x3C0)>>(RegisterOffset16bit(0x3C0));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x",Value16));		
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

			Value16 = TNI_Setting % 0x40;
			Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x  ",Value16));		
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		}
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "=========END:TNI Seting byChannel=========\r\n\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID Rx_TNI_Set_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 RankIndex)
{
	UINT8  ByteIndex = 0;
	UINT16 TNI_Setting;

	UINT16 Value16;

	PEI_DEBUG((PeiServices, EFI_D_WARN, "\r\n=========BEG:TNI Seting byBrank=========\r\n"));		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI Rank%d ",RankIndex));		
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex))==0) {  
		if((RankIndex<4)&&(DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0)){	
			for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
			{
				Value16 = DramAttr->CHAWholeT[ByteIndex];
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x** ",Value16));		
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));		
		}else if((RankIndex>=4)&&(DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)){	
			for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
			{
				Value16 = DramAttr->CHBWholeT[ByteIndex];
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x** ",Value16));		
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}				
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));		
		}
	}
	else {
		for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
		{
			TNI_Setting = DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting;

			Value16 = (TNI_Setting & 0x3C0)>>(RegisterOffset16bit(0x3C0));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x",Value16));		
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

			Value16 = TNI_Setting % 0x40;
			Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x  ",Value16));		
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			ByteIndex++;
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));		
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "=========END:TNI Seting byBrank=========\r\n\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

//SET
//ALL CHA & CHB  can use this function set tni, CHA ->(0:3) CHB->(4:7)
VOID Rx_TNI_SetRegister_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 RankIndex)
{

	UINT8  ByteIndex = 0;
	UINT16 TNI_Setting;
//	UINT16 TNI_HIGH;

	UINT16 Value16;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n\r\n=========BEG:TNI Seting byBrank=========\r\n"));		
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		TNI_Setting = DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting;

		//set TNI WHOLET
		Value16 = TNI_Setting / 0x40 ;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:Rank%d, Byte%d, TNI WholeT:%d  ",RankIndex,ByteIndex,Value16));		
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		//set TNI Phase
		Value16 = TNI_Setting % 0x40;
		Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "PHASE:0x%x\r\n",Value16));		
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		ByteIndex++;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "=========END:TNI Seting byBrank=========\r\n\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}



VOID Rx_TNI_ReadLeveling_SetLowBound_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 RankIndex)
{
	
	UINT8 ByteIndex = 0;
	UINT16 TNI_LOW;
	UINT16 Value16;

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		TNI_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_LOW;
		//set DQO WHOLET
		Value16 = TNI_LOW / 0x40 ;
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		//set TNI Phase
		Value16 = TNI_LOW % 0x40;
		Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		ByteIndex++;
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

//Calibration
VOID Rx_TNI_ReadLeveling(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 TniStep,
	IN BOOLEAN EccByte,
	IN UINT8 CmpEdge, //useless in CHX002
	IN UINT32 DataPattern)//MRP3->MPR2->MPR1->MPR0(H->L)
{ 	
	UINT16  PageMode = 0, Inorder = 0;
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	/*UINT8  SavedOdt = 0;*/
	UINT16 SavedBARASelect = 0;
	UINT32 Buffer32=0, DummyReadBase=0x00;
	UINT32 MrsSet32;
	UINT64 Address = 0x00;
	UINT64 MPR_SIDA[4]={0x00};
	UINT64 MPR_SIDB[4]={0x00};
	INT8 Bit_Index = 7;

	UINT16  Temp16;
	UINT32  Temp32;
	UINT8 MPR_Pattern = 0x00;
	//Rank1 calibration:sweap second & third Datapattern
	//MPR0
	/*DataPattern = 0x55;*/
	
	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;

	MPR_Pattern = (UINT8)DataPattern;
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR0 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	

	//hardcode result
	/*MPR_SIDA[0] = 0xAAAAAAAAAAAAAAAA;//parallel*/
	/*MPR_SIDA[0] = 0xFF00FF00FF00FF00;//Serial*/
	/*MPR_SIDB[3] = 0xFF00FF00FF00FF00;*/
	/*MPR_SIDA[0] = 0xEE66CC44AA228800;//stagger*/
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "HardCode : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	*/
	//MPR1
	/*DataPattern = 0x33;*/
	//Rank1/3 calibration:sweap second & third Datapattern
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}

	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR1 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
	/*[>MPR_SIDA[1] = 0xC0C0C0C0C0C0C0C0;//parallel<]*/
	/*MPR_SIDA[1] = 0xFFFF0000FFFF0000;//serial*/
	/*MPR_SIDB[2] = 0xFFFF0000FFFF0000;*/

	/*[>MPR_SIDA[1] = 0xDDAA332299881100;//stagger<]*/
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	*/
	//MPR2
	/*DataPattern = 0x0F;*/
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR2 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
   /*MPR_SIDA[2] = 0xF0F0F0F0F0F0F0F0;//parallel*/
   /*MPR_SIDA[2] = 0xFFFFFFFF00000000;//serial*/
   /*MPR_SIDB[1] = 0xFFFFFFFF00000000;*/
	/*[>MPR_SIDA[2] = 0xDD99CC8855114400;//stagger<]*/

	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	*/
	//MPR3
	/*DataPattern = 0x00;*/
	MPR_Pattern = (UINT8)(DataPattern>>24);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR3 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>= 0)
	{
		MPR_SIDA[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	
	/*[>MPR_SIDA[3] = 0x0000000000000000;//parallel<]*/
	/*MPR_SIDA[3] = 0x0000000000000000;//serail*/
    /*MPR_SIDB[0] = 0x0000000000000000;//*/
	/*[>MPR_SIDA[3] = 0x7755220066442200;//stagger<]*/
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	*/

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Save BA /RA Select 
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	
	//RDIFFBG_DELY_CAL1,RDIFFBG_DELY_CAL0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDIFFBG_DELY_CAL_CHA_1_0+D0F3_RDIFFBG_DELY_CAL_CHB_1_0,0x5);  //set 1
	//1)
	//set RAUTO to 1 and wait 100us 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RAUTO,D0F3_RAUTO); 
	WaitForMicroSec(PeiServices, 100);	//delay 100us
	//2)
	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//Save Self-refresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	//Save ODT
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);*/
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//5)
	//1 bit correctable error will not generate a wirte to bus  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);
	//6)
	//set inorder
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);
	//7)
	//set RTNIDSIT_WOS[2:0]_BEG = 0x01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNIDSIT_WOS_BEG_3_0,ShiftToMaskBit(D0F3_RTNIDSIT_WOS_BEG_3_0,0x01)); 
	//set RTNIDSIT_WOS[2:0]_END = 0x0F
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNIDSIT_WOS_END_3_0,ShiftToMaskBit(D0F3_RTNIDSIT_WOS_END_3_0,0x0F)); 
	//8)
	//set TNI_STEP[6:0] = 0x01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_TNI_STEP); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNI_STEP_6_0, ShiftToMaskBit(D0F3_RTNI_STEP_6_0,TniStep)); 
	//9)
	//Set  IO calibration Address 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00); //byron advise
	//10)
	// set scan end pointer
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/TniStep)*TniStep));
	//11)
	//set the scan times for every pointer  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x01);
	//12)
	//set RLCUBSTLENGTH[31:0] to 8 for burst length of every scan - use default  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x08);
	//13)
	//Set calibration Data pattern, RM2IL/RM2IH/RM2I2L/RM2I2H
	//MPR0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[0]);
	//MPR1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[1]);
	//MPR2
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[2]);
	//MPR3
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[3]);
	//14)
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		PEI_DEBUG((PeiServices, EFI_D_WARN, "IN RDIMM ReadLeveling\n"));	
		//only test UDIMM for temp
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z8);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RB_8_0_SIDE, 0x1F0);//byte4-8 on side B

		//MPR0 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[0]);
		//MPR1 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[1]);
		//MPR2 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[2]);
		//MPR3 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[3]);
	}
	//15)
	//set RTIMCHKSEL  to 0 or 1, based on the required timing check mode 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//16)
	//save page mode and Disable it
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);
	//17)
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
	FlushCfgWrite(PeiServices, DramAttr, Address);

	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase) = Buffer32;	// Dummy Write 
	WaitForMicroSec(PeiServices, 1);	//delay 1ms
	//MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	FlushCfgWrite(PeiServices, DramAttr, Address);


	//Trigger MRS3 with MPR Enable
	/*Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_STAGGER | MR3_MPR_PAGE0);*/
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_SERIAL | MR3_MPR_PAGE0);
	/*Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_PARALLEL | MR3_MPR_PAGE0);*/
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//18)
	//Enable Readleveling, RX201[7], RDMRLEN 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//19)
	//Set TNI Calibration mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL, D0F3_RTNICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL_CHB, D0F3_RTNICAL_CHB);
	}
	//Enable SOC ODT 
	/*Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_ODT_CTL);*/
	/*AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPADODTEN | D0F3_RPADODTAON, D0F3_RPADODTAON);*/
	/*AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPADODTEN_CHB | D0F3_RPADODTAON_CHB, D0F3_RPADODTAON_CHB);*/
	AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);

	PEI_DEBUG((PeiServices, EFI_D_WARN, "Trigger TNI Read Leveling  \r\n"));	
	
	//20) & 21)
	//trigger scan and check if calibration is done
	if(RankNo < 4)
	{
		//RXAD1, REG_RSCNDSIDLY_CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIT_CHA,D0F3_REG_RSCNDSIT_CHA);
		//AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
		//delay some time
		for(Temp32=0; Temp32 <=500; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIT_CHA)!= 0);
	}
	else
	{
		//RXAD2,reg_RSCNDSIDLY_CHB 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIT_CHB, D0F3_REG_RSCNDSIT_CHB);
		//delay some time
		for(Temp32=0; Temp32 <=0x1000; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIT_CHB)!= 0);
	}

	//22)
	//Set TNI Manual mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL_CHB, 0);
	}

	//23)
	//Disable ReadLeveling
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
	//
	// 25)
	//Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	
	//Trigger MRS3 with MPR Disable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,DDR4_MR3_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	//Set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//RDIFFBG_DELY_CAL1,RDIFFBG_DELY_CAL0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDIFFBG_DELY_CAL_CHA_1_0+D0F3_RDIFFBG_DELY_CAL_CHB_1_0,0x0);  //set 0

	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	//Restore ODT	
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOdt);*/
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, FALSE, &Inorder);

#if 0
	//24)
	//Read HIGH Bound
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_TNI_HIGH);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankNo = %d ,Read  TNI HIGH BOUND\r\n",RankNo));

	PEI_DEBUG((PeiServices, EFI_D_WARN, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
	{
		//RXAE5-AF6
		UINT8 i = 0;
		for(i =0;i < 8; i++)
		{
			if(RankNo < 4)
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
			else
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);

			PEI_DEBUG((PeiServices, EFI_D_WARN, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
		}
	}

	//Read LOW Bound
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_TNI_LOW);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankNo = %d ,Read  TNI LOW BOUND\r\n",RankNo));
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
	{
		//RXAE5-AF6
		UINT8 i = 0;
		for(i =0;i < 8; i++)
		{
			if(RankNo < 4)
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
			else
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
			PEI_DEBUG((PeiServices, EFI_D_WARN, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
		}
	}
#endif 
	
}

VOID Rx_TNI_ReadLeveling_PreambleTraining(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankNo,
		IN UINT8 TniStep,
		IN BOOLEAN EccByte,
		IN UINT8 CmpEdge,
		IN UINT32 DataPattern)//MRP3->MPR2->MPR1->MPR0(H->L)
{ 
		//LGE20160519  Temp code
		UINT16  PageMode = 0, Inorder = 0;
		UINT16  SavedREFC = 0;
		UINT16  SavedOnTheFly = 0;
		UINT16  SavedSelfRef = 0;
		/*UINT16  SavedOdt = 0;*/
		UINT16 SavedBARASelect = 0;
		UINT32 Buffer32=0, DummyReadBase=0x00;
		UINT32 MrsSet32;
		UINT64 Address = 0x00;

		UINT64 MPR_SIDA[4]={0x00};
		UINT64 MPR_SIDB[4]={0x00};
		INT8 Bit_Index = 7;

		UINT16	Temp16;
		UINT32	Temp32;
		UINT8 MPR_Pattern = 0x00;
		//Rank1 calibration:sweap second & third Datapattern
		//MPR0
		/*DataPattern = 0x55;*/
        
		if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
		else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;
		
		MPR_Pattern = (UINT8)DataPattern;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR0 = 0x%2x \r\n",MPR_Pattern)); 

		Bit_Index =7;
		while(Bit_Index>0)
		{
			MPR_SIDA[0]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			MPR_SIDB[3]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			Bit_Index--;
		}
		MPR_SIDA[0] = 0xFF00FF00FF00FF00;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	
		//MPR1
		/*DataPattern = 0x33;*/
		MPR_Pattern = (UINT8)(DataPattern>>8);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR1 = 0x%2x \r\n",MPR_Pattern)); 

		Bit_Index =7;
		while(Bit_Index>0)
		{
			MPR_SIDA[1]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			MPR_SIDB[2]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			Bit_Index--;
		}
		MPR_SIDA[1] = 0xFFFF0000FFFF0000;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
		//MPR2
		/*DataPattern = 0x0F;*/
		MPR_Pattern = (UINT8)(DataPattern>>16);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR2 = 0x%2x \r\n",MPR_Pattern)); 

		Bit_Index =7;
		while(Bit_Index>0)
		{
			MPR_SIDA[2]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			MPR_SIDB[1]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			Bit_Index--;
		}
	   MPR_SIDA[2] = 0xFFFFFFFF00000000;

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
		//MPR3
		/*DataPattern = 0x00;*/
		MPR_Pattern = (UINT8)(DataPattern>>24);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR3 = 0x%2x \r\n",MPR_Pattern)); 

		Bit_Index =7;
		while(Bit_Index>0)
		{
			MPR_SIDA[3]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			MPR_SIDB[0]|= (MPR_Pattern &(1<<Bit_Index)? (0xFF<<((7-Bit_Index)*8)) : 0x00);
			Bit_Index--;
		}
		MPR_SIDA[3] = 0x0000000000000000;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	

		//Clear all VRank size
		ClearAllRankSize(DramAttr);
		//set PRn to VRn and set size to 0~256MB
		SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
		//Save BA /RA Select no use in CHX002
		SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
		//1)
		//set RAUTO to 1 and wait 100us 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD); 
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RAUTO,D0F3_RAUTO); 
		WaitForMicroSec(PeiServices, 1);	//delay 1ms
		//2)
		//Save Refresh Counter
		SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
		//Save Self-refresh
		SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
		//Save ODT
		/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);*/
		//Save On the fly 
		SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
		//5)
		//1 bit correctable error will not generate a wirte to bus	
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_ALERT_RELATED);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);

		//6)
		//set inorder
		SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);

		//7)
		//set RTNIDSIT_WOS[2:0]_BEG = 0x01
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE); 
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNIDSIT_WOS_BEG_3_0,ShiftToMaskBit(D0F3_RTNIDSIT_WOS_BEG_3_0,0x01)); 
		//set RTNIDSIT_WOS[2:0]_END = 0x0F
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE); 
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNIDSIT_WOS_END_3_0,ShiftToMaskBit(D0F3_RTNIDSIT_WOS_END_3_0,0x0F)); 
		//8)
		//set TNI_STEP[6:0] = 0x01
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_TNI_STEP); 
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNI_STEP_6_0, ShiftToMaskBit(D0F3_RTNI_STEP_6_0,TniStep)); 
		/*AsiaPcieRead8(DramAttr->PcieBaseAddress, Address); */

		//9)
		//Set  IO calibration Address 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

		//set address in a 8QW (burst) Set RTSA_STP   
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

		//set address inter 2 8QW (burst) Set RTSA_STP_OS ????	
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

		//10)
		// set scan end pointer
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/TniStep)*TniStep));

		//11)
		//set the scan times for every pointer	
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x01);

		//12)
		//set RLCUBSTLENGTH[31:0] to 8 for burst length of every scan - use default  
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x08);

		//13)
		//Set calibration Data pattern, RM2IL/RM2IH/RM2I2L/RM2I2H
		//MPR0
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[0]);
		//MPR1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[1]);
		//MPR2
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[2]);
		//MPR3
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[3]);
		//14)
		if(DramAttr->RegDimm == IS_REG_DIMM)
		{
			//only test UDIMM for temp
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z8);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RB_8_0_SIDE, 0x00);

			//MPR0 SIDE_B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B);
			AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[0]);
			//MPR1 SIDE_B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B);
			AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[1]);
			//MPR2 SIDE_B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B);
			AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[2]);
			//MPR3 SIDE_B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B);
			AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[3]);
		}
		//
		//15)
		//set RTIMCHKSEL  to 0 or 1, based on the required timing check mode  
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
		//16)
		//save page mode and Disable it
		SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);

		//17)
		//Precharge all
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
		FlushCfgWrite(PeiServices, DramAttr, Address);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read*/
		 *(UINT32 volatile *)(UINT32)(DummyReadBase) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 1);	//delay 1ms
		//MRS mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
		FlushCfgWrite(PeiServices, DramAttr, Address);
		/*AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);*/
		
		//Trigger MRS3 with MPR Enable
		Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_SERIAL | MR3_MPR_PAGE0);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 1);	//delay 1ms

		if(DramAttr->RegDimm == IS_REG_DIMM)
		{
			//Init RDIMM SIDE B 
			MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
			WaitForMicroSec(PeiServices, 10);	//delay 1ms
		}

		//////////////////Enable Read Preamble Training Mode/////////////////////////
		Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankNo, MR4_RD_PREAMBLE_TRAIN);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 1);	//delay 1ms
		////////////////////////////////////////////////////////////////////////

		//set Nomal Mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
		FlushCfgWrite(PeiServices, DramAttr, Address);

		//18)
		//Enable Readleveling, RX201[7], RDMRLEN 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);
		AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);

		//19)
		//Set RDSIT Calibration mode
		if(RankNo < 4)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL, D0F3_RTNICAL);
		}
		else
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL_CHB, D0F3_RTNICAL_CHB);
		}

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger TNI Read Leveling  \r\n")); 
		
		//20) & 21)
		//trigger scan and check if calibration is done
		if(RankNo < 4)
		{
			//RXAD1, REG_RSCNDSIDLY_CHA
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIT_CHA,D0F3_REG_RSCNDSIT_CHA);
			//AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
			//delay some time
			for(Temp32=0; Temp32 <=500; Temp32++)
			{
				AsiaIoWrite8(0x84,(UINT8)(0x01));
			}
			//waiting for read leveling completion
			do{
				Temp16 = 0;
				Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
			}while((Temp16 & D0F3_REG_RSCNDSIT_CHA)!= 0);
		}
		else
		{
			//RXAD2,reg_RSCNDSIDLY_CHB 
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIT_CHB, D0F3_REG_RSCNDSIT_CHB);
			//delay some time
			for(Temp32=0; Temp32 <=0x1000; Temp32++)
			{
				AsiaIoWrite8(0x84,(UINT8)(0x01));
			}
			//waiting for read leveling completion
			do{
				Temp16 = 0;
				Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
			}while((Temp16 & D0F3_REG_RSCNDSIT_CHB)!= 0);
		}

		//22)
		//Set TNI Manual mode
		if(RankNo < 4)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL, 0);
		}
		else
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL_CHB, 0);
		}

		//23)
		//Disable ReadLeveling
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
		//
		// 25)
		//Set MRS mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
		//LGE20160420 flush CFG write for RSDM registers
		/*FlushCfgWrite(PeiServices, DramAttr, Address);*/
		//Trigger MRS3 with MPR Disable
		Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,DDR4_MR3_INIT);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 1);	//delay 1ms

				if(DramAttr->RegDimm == IS_REG_DIMM)
				{
					//Init RDIMM SIDE B 
					MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
					WaitForMicroSec(PeiServices, 10);	//delay 1ms
				}
		//////////////////Disable Read Preamble Training Mode/////////////////////////
		Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankNo, DDR4_MR4_INIT);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 1);	//delay 1ms
		/////////////////////////////////////////////////////////////////////////

		//Set Nomal Mode
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
		//LGE20160420 flush CFG write for RSDM registers
		/*FlushCfgWrite(PeiServices, DramAttr, Address);*/
		//disable byte8 calibration
		//EndofByte8Calibration(PeiServices, pPCIPPI, DramAttr, EccByte);
		//Clear Data Pattern ??????
		//Restore On the fly 
		SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
		//Restore Refresh Counter
		SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
		//Restore SelfRefresh
		SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
		//Restore ODT	
		/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOdt);*/
		//Restore BA /RA Select
		SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
		SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
		SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, !TRUE, &Inorder);

		//24)
		/*if(RankNo <4)*/
		/*{*/
		//Read HIGH Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_TNI_HIGH);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankNo = %d ,Read  TNI HIGH BOUND\r\n",RankNo));

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < 8; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}

		//Read LOW Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_TNI_LOW);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankNo = %d ,Read  TNI LOW BOUND\r\n",RankNo));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < 8; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
		
}

VOID Rx_TNI_LCU(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 TniStep,
	IN UINT8 DataPattern)
{ 
	UINT16 PageMode = 0, Inorder = 0;
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	UINT16 SavedBARASelect = 0;
	UINT64 Address;
	UINT16  Temp16;
	UINT32 Temp32;

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Save BA /RA Select --> Disable Interleveling for CHX002
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);

	//RDIFFBG_DELY_CAL1,RDIFFBG_DELY_CAL0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDIFFBG_DELY_CAL_CHA_1_0+D0F3_RDIFFBG_DELY_CAL_CHB_1_0,0x5);  //set 1

	
	//Save Self-refresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//1)
	//1 bit correctable error will not generate a wirte to bus  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);
	//2)
	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//3)
	//Disable ReadLeveling
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
	//3)--should add in Pspec later
	//set inorder 
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);
	//4)
	//set RTNIDSIT_WOS[2:0]_BEG = 0x01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNIDSIT_WOS_BEG_3_0,ShiftToMaskBit(D0F3_RTNIDSIT_WOS_BEG_3_0,0x01)); 
	//set RTNIDSIT_WOS[2:0]_END = 0x0F
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNIDSIT_WOS_END_3_0,ShiftToMaskBit(D0F3_RTNIDSIT_WOS_END_3_0,0x0F)); 
	//5)
	//set TNI_STEP[6:0] = 0x01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_TNI_STEP); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTNI_STEP_6_0, ShiftToMaskBit(D0F3_RTNI_STEP_6_0,TniStep)); 

	//6)
	//Set  IO calibration Address 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//7)
	// set scan end pointer
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/TniStep)*TniStep));

	//8)
	//set the scan times for every pointer  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x01);

	//9)
	//set RLCUBSTLENGTH[31:0] to 8 for burst length of every scan - use default  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x08);

	//10)
	//set RADDRLOOPEN to 0 or 1,selecting the desired address change mode (use default value is OK)  use default  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RADDRLOOPEN, D0F3_RADDRLOOPEN);
	//
	//13) 
	//set RTIMCHKSEL  to 0 or 1, based on the required timing check mode(use default value is OK when debug in HAPS) 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//14)
	//save page mode and Enable it
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);

	//15)
	//Set TNI Calibration mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL, D0F3_RTNICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL_CHB, D0F3_RTNICAL_CHB);
	}

	PEI_DEBUG((PeiServices, EFI_D_WARN, "Trigger TNI LCU  \r\n"));	
	
	//16) & 17)
	//trigger scan and check if calibration is done
	if(RankNo < 4)
	{
		//RXAD1, REG_RSCNDSIDLY_CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIT_CHA,D0F3_REG_RSCNDSIT_CHA);
		//delay some time
		for(Temp32=0; Temp32 <=500; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIT_CHA)!= 0);
	}
	else
	{
		//RXAD2,reg_RSCNDSIDLY_CHB 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIT_CHB, D0F3_REG_RSCNDSIT_CHB);
		//delay some time
		for(Temp32=0; Temp32 <=0x1000; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIT_CHB)!= 0);
	}

	//18)
	//Set TNI Manual mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTNICAL_CHB, 0);
	}


	//RDIFFBG_DELY_CAL1,RDIFFBG_DELY_CAL0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDIFFBG_DELY_CAL_CHA_1_0+D0F3_RDIFFBG_DELY_CAL_CHB_1_0,0x0);  //set 0

	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	//Restore ODT	
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOdt);*/
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, !TRUE, &Inorder);

	//19)
#if 0
	//Read HIGH Bound
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_TNI_HIGH);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankNo = %d ,Read  TNI HIGH BOUND\r\n",RankNo));

	PEI_DEBUG((PeiServices, EFI_D_WARN, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
	{
		//RXAE5-AF6
		UINT8 i = 0;
		for(i =0;i < 8; i++)
		{
			if(RankNo < 4)
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
			else
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
			PEI_DEBUG((PeiServices, EFI_D_WARN, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
		}
	}
	//Read LOW Bound
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_TNI_LOW);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankNo = %d ,Read  TNI LOW BOUND\r\n",RankNo));
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
	{
		//RXAE5-AF6
		UINT8 i = 0;
		for(i =0;i < 8; i++)
		{
			if(RankNo < 4)
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
			else
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
			PEI_DEBUG((PeiServices, EFI_D_WARN, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
		}
	}
#endif
	
}


// DQSI Calibrtion Related
VOID Rx_DQSI_ClearDataset(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex)
{
	UINT8 ByteIndex = 0;
	UINT8 BitIndex = 0;
	UINT8 RankBegin = 0, RankEnd =0;

	if(RankIndex == ALLRANK)
	{
		RankBegin = 0;
		RankEnd = ASIA_MAX_RANKS ;
	}
	else
	{
		RankBegin = RankIndex ;
		RankEnd  = RankIndex + 1 ;
	}
	for(RankIndex = RankBegin ; RankIndex < RankEnd ; RankIndex++)
	{
		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES; ByteIndex++)//all Byte include ECC byte
		{
			for(BitIndex = 0; BitIndex <8; BitIndex++)
			{
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW = 0;
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH = 0;
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_Setting = 0;

				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW = 0;
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH = 0;
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_Setting = 0;

				DramAttr->DramAutoCal_DQSI[RankIndex].CalResult = FALSE;
			}
		}
	}
}

VOID Rx_DQSI_SaveDataSet(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 ByteNo)
{
	UINT8  ByteIndex = 0;
	UINT8  ByteBegin = 0;
	UINT8  ByteEnd = 0;
	UINT16 Value16 = 0;
	UINT8  BitIndex= 0;

	if(ByteNo == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = ASIA_MAX_BYTES;
	}
	else
	{
		ByteBegin = ByteNo;
		ByteEnd = ByteNo+1;
	}
	//HIGH Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		for(BitIndex = 0; BitIndex <ASIA_MAX_BIT; BitIndex++)
		{
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, (1<<BitIndex), POS, &Value16);
			DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH = (UINT8)Value16;
			//RKD-debug only
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d Bit:%d  DQSI POS HIGH = %d P \r\n",RankIndex, ByteIndex,BitIndex,DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH));	*/
			//NEG
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, (1<<BitIndex), NEG, &Value16);
			DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH = (UINT8)Value16;
			//RKD-debug only
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d Bit:%d  DQSI NEG HIGH = %d P \r\n",RankIndex, ByteIndex,BitIndex,DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH));	*/
		}
	}

	//LOW Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		for(BitIndex = 0; BitIndex <ASIA_MAX_BIT; BitIndex++)
		{
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, (1<<BitIndex), POS, &Value16);
			DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW = (UINT8)Value16;
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d Bit:%d DQSI POS LOW = %d P \r\n",RankIndex, ByteIndex,BitIndex,DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW));	*/
			//NEG
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE,IOCTL_LOW, READ, RankIndex, ByteIndex, (1<<BitIndex), NEG, &Value16);
			DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW = (UINT8)Value16;
			//RKD-debug only
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d Bit %d DQSI NEG LOW = %d P \r\n",RankIndex, ByteIndex,BitIndex,DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW));	*/
		}
	}
}


VOID Rx_DQSI_ReadLeveling_SaveRange(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,	
		IN BOOLEAN ECC_ENABLE,
		OUT IN UINT16 (*DQSIRange)[ASIA_MAX_BIT][2])  
{

	UINT8 ByteIndex;
	UINT8 DQSI_LOW = 0;
	UINT8 DQSI_HIGH = 0;
	UINT8 BitIndex =0;
	UINT8 edge = 0;

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
	{	   		
		for(BitIndex = 0; BitIndex  < ASIA_MAX_BIT; BitIndex++)
		{
			for(edge =0; edge<2; edge++)
			{
				DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][edge].DQSI_HIGH;
				DQSI_LOW = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][edge].DQSI_LOW;

				DQSIRange[ByteIndex][BitIndex][edge] = DQSI_LOW;
				DQSIRange[ByteIndex][BitIndex][edge] |= DQSI_HIGH << 8;
			}
		}
	}
}


BOOLEAN Rx_DQSI_ReadLeveling_CheckRange(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,	
		IN BOOLEAN ECC_ENABLE,
		OUT IN UINT8 (*DQSIRange)[ASIA_MAX_BIT][2])
{
	BOOLEAN Flag = TRUE;
	UINT8 ByteIndex;
	UINT8 DQSI_LOW = 0;
	UINT8 DQSI_HIGH = 0;
	UINT8 BitIndex =0;
	UINT8 edge = 0 ;

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{	   		
		for(BitIndex = 0; BitIndex  <ASIA_MAX_BIT; BitIndex++)
		{
			for(edge =0; edge<2; edge++)
			{
				DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][edge].DQSI_HIGH;
				DQSI_LOW = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][edge].DQSI_LOW;

				//BEG:RKD-debug only
				if(edge == 0)
					PEI_DEBUG((PeiServices, EFI_D_WARN, "Rank%d Byte%d Bit%d  DQSI POS Range = %d P \r\n",RankIndex, ByteIndex, BitIndex, DQSI_HIGH - DQSI_LOW ));	
				else
					PEI_DEBUG((PeiServices, EFI_D_WARN, "Rank%d Byte%d Bit%d  DQSI NEG Range = %d P \r\n",RankIndex, ByteIndex, BitIndex, DQSI_HIGH - DQSI_LOW ));	
				//END:RKD-debug only

				if(DQSI_LOW >= DQSI_HIGH)
				{
					Flag = FALSE;
					break;
				}
				else{
					if(DQSI_HIGH - DQSI_LOW < DQSI_THRESHOLD)
					{
						Flag = FALSE;
						break;
					}
					else
					{
						DQSIRange[ByteIndex][BitIndex][edge] = DQSI_HIGH - DQSI_LOW;
					}
				}
			}
		}
		ByteIndex+=1;
	}
    return Flag;
}



VOID Rx_DQSI_SetRegister_byChannel(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr, 
	IN BOOLEAN		ECC_ENABLE,
	IN UINT8		RankIndex)
{

	UINT8 ByteIndex = 0;
	UINT8 DQSI_LOW;
	UINT8 DQSI_HIGH;
	UINT8 BitIndex;
	UINT16 Value16;
	UINT8  RankBegin = 0, RankEnd=8;
	RankBegin=RankIndex;
	RankEnd =RankIndex+4;
	
//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:Rx_DQSI_SetRegister_byChannel\r\n"));		
//	RankCount=0;
	for(RankIndex = RankBegin; RankIndex <RankEnd;RankIndex++) 	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) {
//		RankCount++;	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:RankIndex:%x!!\r\n",RankIndex)); 	

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		for(BitIndex = 0; BitIndex < 8; BitIndex++)
		{
			//POS
			if(DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW<DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW)
			DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW  = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
//			if((DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH!=0)&(DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH==0))			
//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%x : %x!!",DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH,DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH));	

			if(((DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH>DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH)&&(DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH!=0)) || DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH==0)
			DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH;

//			Value16 = (UINT16)(DQSI_LOW + DQSI_HIGH)>>1;
			//set DQSI Phase
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16));		*/
//			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, POS, &(Value16));

			//NEG
			if(DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW<DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW)
			DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW  = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;
//			if(DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH>DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH)
			if(((DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH>DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH)&&(DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH!=0))||(DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH==0))
			DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH;

//			Value16 = (UINT16)(DQSI_LOW + DQSI_HIGH)>>1;
			//set DQSI Phase
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16));		*/
//			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, NEG, &Value16);
		}
		ByteIndex++;
	}
		}
		}
	for(RankIndex = RankBegin; RankIndex <RankEnd;RankIndex++) 	{
		for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
		{
			for(BitIndex = 0; BitIndex < 8; BitIndex++)
			{
				//POS
				DQSI_LOW  = DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
				DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH;
				Value16 = (UINT16)(DQSI_LOW + DQSI_HIGH)>>1;
				//set DQSI Phase
//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16)); 	
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, POS, &Value16);
		
				//NEG
				DQSI_LOW  = DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;
				DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankBegin].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH;
				Value16 = (UINT16)(DQSI_LOW + DQSI_HIGH)>>1;
				//set DQSI Phase
//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16)); 	
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, NEG, &Value16);
			}
			ByteIndex++;
		}

	}	
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}


VOID Set_DQSI_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr, 
	IN BOOLEAN		ECC_ENABLE,
	IN UINT8		RankIndex,
	IN UINT16		SetValue)
{

	UINT8 ByteIndex = 0;
	UINT8 BitIndex;
	UINT16 Value16;

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		for(BitIndex = 0; BitIndex < 8; BitIndex++)
		{
			//POS
			Value16 = SetValue;
			//set DQSI Phase
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16));		
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, POS, &(Value16));

			//NEG
			//set DQSI Phase
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16));		
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, NEG, &Value16);
		}
		ByteIndex++;
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}


VOID Rx_DQSI_SetRegister_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr, 
	IN BOOLEAN		ECC_ENABLE,
	IN UINT8		RankIndex)
{

	UINT8 ByteIndex = 0;
	UINT8 DQSI_LOW;
	UINT8 DQSI_HIGH;
	UINT8 BitIndex;
	UINT16 Value16;

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		for(BitIndex = 0; BitIndex < 8; BitIndex++)
		{
			//POS
			DQSI_LOW  = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
			DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH;
			Value16 = (UINT16)(DQSI_LOW + DQSI_HIGH)>>1;
			//set DQSI Phase
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16));		*/
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, POS, &(Value16));

			//NEG
			DQSI_LOW  = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;
			DQSI_HIGH = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH;
			Value16 = (UINT16)(DQSI_LOW + DQSI_HIGH)>>1;
			//set DQSI Phase
			/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:DQSI PHASE:0x%x!!\r\n",Value16));		*/
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, NEG, &Value16);
		}
		ByteIndex++;
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID Rx_DQSI_Delay(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DelayType)
{
	UINT16  Value16 = 0x10;
	UINT8   RankIndex = 0;
	BOOLEAN ECC_ENABLE = FALSE;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

	if(DelayType == DQSI_QUATER_T_DELAY)
	{
		//Set DQSI DLL 1/4 T delay, RX201[2] = 1, RDLLDSIDLY
		//Read DQSI
		//Write DQSI
		//Set DQSI Manual/Calibration , RX201[2] = 0, RDLLDSIDLY
		Value16=0x10;  //default 1/4T	

	}
	else if(DelayType == DQSI_HALF_T_DELAY)
	{
		//Set DQSI DLL 1/2 T delay
		//Read DQSI
		//Write DQSI
		//Set DQSI Manual/Calibration , RX201[2] = 0, RDLLDSIDLY	
		Value16=0x20;  //default 1/4T	
	}
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
		{
			Set_DQSI_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex,Value16);
		}
	}
	//Set DQSI Manual mode

}

VOID Rx_DQSI_ReadLeveling(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT32 DataPattern,
	IN BOOLEAN EccByte)
{ 
	
	UINT16 PageMode = 0, Inorder = 0;
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	UINT16 SavedBARASelect = 0;
	UINT32 Buffer32=0, DummyReadBase=0x00;
	UINT32 MrsSet32;
	UINT64 Address;
	UINT16  Temp16;
	UINT32 Temp32;

	BOOLEAN SHOWLOG = TRUE;

	UINT64 MPR_SIDA[4]={0x00};
	UINT64 MPR_SIDB[4]={0x00};
	INT8 Bit_Index = 7;
	UINT8 MPR_Pattern = 0x00;

	
	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;

	//MPR0
	MPR_Pattern = (UINT8)DataPattern;
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR0 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	

	//MPR1
	//Rank1/3 calibration:sweap second & third Datapattern
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR1 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
	//
	//MPR2
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR2 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
	
	//MPR3
	MPR_Pattern = (UINT8)(DataPattern>>24);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR3 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>= 0)
	{
		MPR_SIDA[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	
#if 0

	{
		UINT8 Stagger_Pattern;

		DataPattern = 0x000F3355;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			/*for(ByteIndex = 0; ByteIndex <8; ByteIndex++)*/
			/*{*/
			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[0]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	
			/*}*/
		}

		DataPattern = 0x55000F33;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			/*for(ByteIndex = 0; ByteIndex <8; ByteIndex++)*/
			/*{*/
			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[1]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
			/*}*/
		}

		DataPattern = 0x3355000F;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[2]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
		}

		DataPattern = 0x0F335500;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[3]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	
		}
	}


#endif

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Save BA /RA Select --> Disable IneterLeveling for CHX002 
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Save Self-refresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//1)	Set RX TNI setting according to RX TNI calibration result and set RTNICAL=0 for manual mode select.
	// no need
	//
	//2)	Set RERRSCREN to 0, ECC 1 bit correctable error will not generate a write to bus;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);
	//3)Set RINORDER to 1, making the CMD in DMQUE be served in order;
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);
	//4)	Set {REFC7,REFC6,REFC5,REFC4,REFC3,REFC2,REFC1,REFC0} to 0, disabling issuing refresh command;
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//5)	Set {RDQSI_STEP5,RDQSI_STEP4,RDQSI_STEP3,RDQSI_STEP2,RDQSI_STEP1,RDQSI_STEP0} for DQSI scan step;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQSO_STEP_DQSI_STEP); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSI_STEP_6_0, ShiftToMaskBit(D0F3_RDQSI_STEP_6_0,DqsiStep)); 

	//6)	Set RDMTSA[31:3] and RTSA_STP[18:3] for calibration address;
	//Set  IO calibration Address 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//7)	Set {RSCAN_END5,RSCAN_END4,RSCAN_END3,RSCAN_END2,RSCAN_END1,RSCAN_END0} for scan end pointer
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqsiStep)*DqsiStep));

	//8)	Set RSRW_LENGTH[31:0] for the scan times of every pointer;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x01);

	//9)	Set RLCUBSTLENGTH[31:0] to 4 for the burst length of every scan
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x08);

	//10)	Set the read leveling comparison pattern related registers based on the MPR readout format 
	//MPR0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[0]);
	//MPR1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[1]);
	//MPR2
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[2]);
	//MPR3
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[3]);
	//11)	Set {RB8SIDE, RB7SIDE, RB6SIDE, RB5SIDE, RB4SIDE, RB3SIDE, RB2SIDE, RB1SIDE, RB0SIDE} based on the Byte location
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		PEI_DEBUG((PeiServices, EFI_D_WARN, "RKD-Debug:In RDIMM DQSI Leveling\n"));	
		//only test UDIMM for temp
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z8);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RB_8_0_SIDE, 0x0F0);//byte4-8 on side B

		//MPR0 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[0]);
		//MPR1 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[1]);
		//MPR2 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[2]);
		//MPR3 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[3]);
	}
	//xx)  DQSI PSPEC does use this Reg
	//set RTIMCHKSEL  to 0 or 1, based on the required timing check mode - use default
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//12)	Set RPGEN to 1 to enable page mode
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);

	//13)issue MRS cmd using cpu 1QW write cycle, meanwhile, set RDISRMW=1 to disable RMW
	//add by rkd - disable rmw -- sync with byron
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDISRMW, D0F3_RDISRMW); 
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
	FlushCfgWrite(PeiServices, DramAttr, Address);

	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase) = Buffer32;	// Dummy Write 
	WaitForMicroSec(PeiServices, 1);	//delay 1ms
	//MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	
	//Trigger MRS3 with MPR Enable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_SERIAL | MR3_MPR_PAGE0);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	
	//14)Set RDMRLEN to 1, enabling DRAMC read leveling mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);

	//15)	Set RDSICAL to 1 for DQSI calibration setting
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, D0F3_RDSICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, D0F3_RDSICAL_CHB);
	}

	PEI_DEBUG((PeiServices, EFI_D_WARN, "Trigger DQSI Read Leveling  \r\n"));	
	
	//16) 	Trigger reg_RSCNDSIDLY_CHA to active DRAMCA DQSI calibration function (or reg_RSCNDSIDLY_CHB for DRAMCB);
	//17)	Wait for reg_RSCNDSIDLY_CHA being cleared by HW (or reg_RSCNDSIDLY_CHB for DRAMCB);
	//trigger scan and check if calibration is done
	if(RankNo < 4)
	{
		//RXAD1, REG_RSCNDSIDLY_CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHA,D0F3_REG_RSCNDSIDLY_CHA);
		//delay some time
		for(Temp32=0; Temp32 <=500; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHA)!= 0);
	}
	else
	{
		//RXAD2,reg_RSCNDSIDLY_CHB 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHB, D0F3_REG_RSCNDSIDLY_CHB);
		//delay some time
		for(Temp32=0; Temp32 <=0x1000; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHB)!= 0);
	}

	//18)Set RDSICAL to 0 for DQSI manual setting;
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, 0);
	}

	//19)Set RDMRLEN to 0, disabling DRAMC read leveling mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
	//
	// 21)	Set {RSDM2,RSDM1,RSDM0} = 3'b011, issue MR3 to disable DRAM MPR mode, and then set {RSDM2,RSDM1,RSDM0} = 3'b000;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//Trigger MRS3 with MPR Disable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,DDR4_MR3_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	//Set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, !TRUE, &Inorder);
	//add by rkd - enable rmw
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDISRMW, 0); 

	//20)	Read DMIOREG_BIT[11:0]_Ax for the calibration result and set to manual setting;
	if(SHOWLOG)
	{
		UINT8 DMIOSEL_BIT; 
		UINT8 Posedge_low =0,  negedge_low=0;
		UINT8 Posedge_high =0, negedge_high=0;
		UINT8 ByteIndex =0;

		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES ;ByteIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_WARN,"DQSI Perbit log ByteIndex = %d\n",ByteIndex));
			PEI_DEBUG((PeiServices, EFI_D_WARN,"          Pos[low   high]           Neg[low   high]\n"));
			for(DMIOSEL_BIT = 0X00; DMIOSEL_BIT < ASIA_MAX_BIT; DMIOSEL_BIT++){
				PEI_DEBUG((PeiServices, EFI_D_WARN, "Byte: %d Bit %d:",ByteIndex,DMIOSEL_BIT));

				//posedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 0);

				if(RankNo < 4) //CHA
				{
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);
				}
				else{//CHB
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 + ByteIndex*2);
				}
				Posedge_high = (UINT8)((AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6)&0x3F);
				Posedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);

				//negedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 1);
				if(RankNo < 4)//CHA
				{
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);

				}
				else{//CHB
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 + ByteIndex*2);
				}
				negedge_high = (UINT8)((AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6)&0x3F);
				negedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);
				PEI_DEBUG((PeiServices, EFI_D_WARN, "[%02X -- %02X] (%02x) C:%02x  -- [%02X -- %02X] (%02x) C:%02x \n ", Posedge_low,Posedge_high,Posedge_high-Posedge_low,(Posedge_high+Posedge_low)>>1,negedge_low,negedge_high,negedge_high-negedge_low,(negedge_high+negedge_low)>>1));
			}
		}
	}
	
}

VOID Rx_ReadPreamble_Training(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT32 DataPattern,
	IN BOOLEAN EccByte)
{ 
	
	UINT16 PageMode = 0, Inorder = 0;
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	UINT16 SavedBARASelect = 0;
	UINT32 Buffer32=0, DummyReadBase=0x00;
	UINT32 MrsSet32;
	UINT64 Address;
	UINT16  Temp16;
	UINT32 Temp32;

	BOOLEAN SHOWLOG = TRUE;

	UINT64 MPR_SIDA[4]={0x00};
	UINT64 MPR_SIDB[4]={0x00};
	INT8 Bit_Index = 7;
	UINT8 MPR_Pattern = 0x00;


	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;

	//MPR0
	MPR_Pattern = (UINT8)DataPattern;
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR0 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	

	//MPR1
	//Rank1/3 calibration:sweap second & third Datapattern
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR1 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
	//
	//MPR2
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR2 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
	
	//MPR3
	MPR_Pattern = (UINT8)(DataPattern>>24);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "MPR3 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>= 0)
	{
		MPR_SIDA[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Compute : MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	
#if 0

	{
		UINT8 Stagger_Pattern;

		DataPattern = 0x000F3355;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			/*for(ByteIndex = 0; ByteIndex <8; ByteIndex++)*/
			/*{*/
			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[0]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	
			/*}*/
		}

		DataPattern = 0x55000F33;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			/*for(ByteIndex = 0; ByteIndex <8; ByteIndex++)*/
			/*{*/
			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[1]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
			/*}*/
		}

		DataPattern = 0x3355000F;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[2]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
		}

		DataPattern = 0x0F335500;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Datapattern %08x \n", DataPattern));	
		for(Bit_Index = 8; Bit_Index >= 1;  Bit_Index--)
		{
			MPR_Pattern =(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<7)|(((((UINT8)(DataPattern>>24))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<3)|
				(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<6)|(((((UINT8)(DataPattern>>16))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<2)|
				(((((UINT8)(DataPattern>>8))&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<5)|((((UINT8)(DataPattern>>8)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<1)|
				((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<4)|((((UINT8)(DataPattern>>0)&(1<<(Bit_Index - 1)))>>(Bit_Index - 1))<<0);

			DramToConnector_Convert( PeiServices, DramAttr,RankNo,  ByteIndex, MPR_Pattern, &Stagger_Pattern);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex %d: %02x -- %02x\n ",ByteIndex, MPR_Pattern,Stagger_Pattern));	
			MPR_SIDA[3]|= LShiftU64(Stagger_Pattern,8*(8 - Bit_Index));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	
		}
	}


#endif

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Save BA /RA Select --> Disable IneterLeveling for CHX002 
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Save Self-refresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//1)	Set RX TNI setting according to RX TNI calibration result and set RTNICAL=0 for manual mode select.
	// no need
	//
	//2)	Set RERRSCREN to 0, ECC 1 bit correctable error will not generate a write to bus;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);
	//3)Set RINORDER to 1, making the CMD in DMQUE be served in order;
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);
	//4)	Set {REFC7,REFC6,REFC5,REFC4,REFC3,REFC2,REFC1,REFC0} to 0, disabling issuing refresh command;
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//5)	Set {RDQSI_STEP5,RDQSI_STEP4,RDQSI_STEP3,RDQSI_STEP2,RDQSI_STEP1,RDQSI_STEP0} for DQSI scan step;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQSO_STEP_DQSI_STEP); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSI_STEP_6_0, ShiftToMaskBit(D0F3_RDQSI_STEP_6_0,DqsiStep)); 

	//6)	Set RDMTSA[31:3] and RTSA_STP[18:3] for calibration address;
	//Set  IO calibration Address 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//7)	Set {RSCAN_END5,RSCAN_END4,RSCAN_END3,RSCAN_END2,RSCAN_END1,RSCAN_END0} for scan end pointer
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqsiStep)*DqsiStep));

	//8)	Set RSRW_LENGTH[31:0] for the scan times of every pointer;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x01);

	//9)	Set RLCUBSTLENGTH[31:0] to 4 for the burst length of every scan
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x08);

	//10)	Set the read leveling comparison pattern related registers based on the MPR readout format 
	//MPR0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[0]);
	//MPR1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[1]);
	//MPR2
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[2]);
	//MPR3
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[3]);
	//11)	Set {RB8SIDE, RB7SIDE, RB6SIDE, RB5SIDE, RB4SIDE, RB3SIDE, RB2SIDE, RB1SIDE, RB0SIDE} based on the Byte location
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		PEI_DEBUG((PeiServices, EFI_D_WARN, "RKD-Debug:In RDIMM DQSI Leveling\n"));	
		//only test UDIMM for temp
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z8);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RB_8_0_SIDE, 0x1F0);//byte4-8 on side B

		//MPR0 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[0]);
		//MPR1 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[1]);
		//MPR2 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[2]);
		//MPR3 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[3]);
	}
	//xx)  DQSI PSPEC does use this Reg
	//set RTIMCHKSEL  to 0 or 1, based on the required timing check mode - use default
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//12)	Set RPGEN to 1 to enable page mode
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);

	//13)issue MRS cmd using cpu 1QW write cycle, meanwhile, set RDISRMW=1 to disable RMW
	//add by rkd - disable rmw -- sync with byron
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDISRMW, D0F3_RDISRMW); 
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
	FlushCfgWrite(PeiServices, DramAttr, Address);

	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase) = Buffer32;	// Dummy Write 
	WaitForMicroSec(PeiServices, 1);	//delay 1ms
	//MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);

	
	//Trigger MRS3 with MPR Enable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_SERIAL | MR3_MPR_PAGE0);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write
	WaitForMicroSec(PeiServices, 100);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
	}
	/*
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);

	//14)Set RDMRLEN to 1, enabling DRAMC read leveling mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);

	//15)	Set RDSICAL to 1 for DQSI calibration setting
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, D0F3_RDSICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, D0F3_RDSICAL_CHB);
	} 
	*/
	//////////////////Enable Read Preamble Training Mode/////////////////////////
	//MRS mode
//	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
//	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);

	Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankNo, MR4_RD_PREAMBLE_TRAIN);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
	*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
	WaitForMicroSec(PeiServices, 100);	//delay 1ms
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
	}

	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//enable DQS and DQ pad input buffer constantly
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQIEN|D0F3_RDSIEN|D0F3_RCMPENDQ_ON|D0F3_RCMPENDQS_ON, D0F3_RDQIEN|D0F3_RDSIEN|D0F3_RCMPENDQ_ON|D0F3_RCMPENDQS_ON);
	////////////////////////////////////////////////////////////////////////

	PEI_DEBUG((PeiServices, EFI_D_WARN, "Trigger DQSI Read Leveling  \r\n"));	

	//14)Set RDMRLEN to 1, enabling DRAMC read leveling mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);

	//15)	Set RDSICAL to 1 for DQSI calibration setting
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, D0F3_RDSICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, D0F3_RDSICAL_CHB);
	} 


	
	//16) 	Trigger reg_RSCNDSIDLY_CHA to active DRAMCA DQSI calibration function (or reg_RSCNDSIDLY_CHB for DRAMCB);
	//17)	Wait for reg_RSCNDSIDLY_CHA being cleared by HW (or reg_RSCNDSIDLY_CHB for DRAMCB);
	//trigger scan and check if calibration is done
	if(RankNo < 4)
	{
		//RXAD1, REG_RSCNDSIDLY_CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHA,D0F3_REG_RSCNDSIDLY_CHA);
		//delay some time
		for(Temp32=0; Temp32 <=500; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHA)!= 0);
	}
	else
	{
		//RXAD2,reg_RSCNDSIDLY_CHB 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHB, D0F3_REG_RSCNDSIDLY_CHB);
		//delay some time
		for(Temp32=0; Temp32 <=0x1000; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHB)!= 0);
	}

	//18)Set RDSICAL to 0 for DQSI manual setting;
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, 0);
	}
	//disable DQS and DQ pad input buffer constantly
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQIEN|D0F3_RDSIEN|D0F3_RCMPENDQ_ON|D0F3_RCMPENDQS_ON, 0);

	//19)Set RDMRLEN to 0, disabling DRAMC read leveling mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
	//
	// 21)	Set {RSDM2,RSDM1,RSDM0} = 3'b011, issue MR3 to disable DRAM MPR mode, and then set {RSDM2,RSDM1,RSDM0} = 3'b000;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankNo, DDR4_MR4_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
	*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
	WaitForMicroSec(PeiServices, 100);	//delay 1ms
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
	}


	//Trigger MRS3 with MPR Disable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,DDR4_MR3_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
	 *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		/*Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read*/
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = Buffer32;	// Dummy Write 
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	
	//Set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	// flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, !TRUE, &Inorder);
	//add by rkd - enable rmw
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDISRMW, 0); 

	//20)	Read DMIOREG_BIT[11:0]_Ax for the calibration result and set to manual setting;
	if(SHOWLOG)
	{
		UINT8 DMIOSEL_BIT; 
		UINT8 Posedge_low =0,  negedge_low=0;
		UINT8 Posedge_high =0, negedge_high=0;
		UINT8 ByteIndex =0;

		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES ;ByteIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_WARN,"DQSI Perbit log ByteIndex = %d\n",ByteIndex));
			PEI_DEBUG((PeiServices, EFI_D_WARN,"          Pos[low   high]           Neg[low   high]\n"));
			for(DMIOSEL_BIT = 0X00; DMIOSEL_BIT < ASIA_MAX_BIT; DMIOSEL_BIT++){
				PEI_DEBUG((PeiServices, EFI_D_WARN, "Byte: %d Bit %d:",ByteIndex,DMIOSEL_BIT));

				//posedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 0);

				if(RankNo < 4) //CHA
				{
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);
				}
				else{//CHB
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 + ByteIndex*2);
				}
				Posedge_high = (UINT8)((AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6)&0x3F);
				Posedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);

				//negedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 1);
				if(RankNo < 4)//CHA
				{
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);

				}
				else{//CHB
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 + ByteIndex*2);
				}
				negedge_high = (UINT8)((AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6)&0x3F);
				negedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);
				PEI_DEBUG((PeiServices, EFI_D_WARN, "[%02X -- %02X] (%02x) C:%02x  -- [%02X -- %02X] (%02x) C:%02x \n ", Posedge_low,Posedge_high,Posedge_high-Posedge_low,(Posedge_high+Posedge_low)>>1,negedge_low,negedge_high,negedge_high-negedge_low,(negedge_high+negedge_low)>>1));
			}
		}
	}
	
}

VOID Rx_DQSI_Preamble_Training(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT32 DataPattern,
	IN BOOLEAN EccByte)
{ 

	UINT16 PageMode = 0, Inorder = 0;
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	/*UINT8  SavedOdt = 0;*/
	UINT16 SavedBARASelect = 0;
	UINT32 Buffer32=0, DummyReadBase=0x00;
	UINT32 MrsSet32;
	UINT64 Address;
	UINT16  Temp16;
	UINT32 Temp32;

	BOOLEAN SHOWLOG = TRUE;

	UINT64 MPR_SIDA[4]={0x00};
	UINT64 MPR_SIDB[4]={0x00};
	INT8 Bit_Index = 7;
	UINT8 MPR_Pattern = 0x00;

	
	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;

	//MPR0
	MPR_Pattern = (UINT8)DataPattern;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR0 = 0x%2x \r\n",MPR_Pattern));	

	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[0] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[0],32),(UINT32)(MPR_SIDA[0])));	

	//MPR1
	//Rank1/3 calibration:sweap second & third Datapattern
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR1 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[1] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[1],32),(UINT32)(MPR_SIDA[1])));	
	//
	//MPR2
	/*DataPattern = 0x0F;*/
	if(RankNo%2)
	{
		MPR_Pattern = (UINT8)(DataPattern>>8);
	}
	else
	{
		MPR_Pattern = (UINT8)(DataPattern>>16);
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR2 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>=0)
	{
		MPR_SIDA[2]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[1]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[2] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[2],32),(UINT32)(MPR_SIDA[2])));	
	//
	//MPR3
	/*DataPattern = 0x00;*/
	MPR_Pattern = (UINT8)(DataPattern>>24);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MPR3 = 0x%2x \r\n",MPR_Pattern));	
	Bit_Index =7;
	while(Bit_Index>= 0)
	{
		MPR_SIDA[3]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		MPR_SIDB[0]|= (MPR_Pattern &(1<<Bit_Index)? LShiftU64(0xFF,((7-Bit_Index)*8)) : 0x00);
		Bit_Index--;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Compute : MPR_SIDA[3] = 0x%08x %08x\n",(UINT32)RShiftU64(MPR_SIDA[3],32),(UINT32)(MPR_SIDA[3])));	

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Save BA /RA Select -- no use in CHX002
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Save Self-refresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	//Save ODT
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);*/
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//2)
	//1 bit correctable error will not generate a wirte to bus  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);
	//3)
	//set inorder
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);
	//4)
	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//5)
	//set RDQSI_STEP[6:0] = 0x01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQSO_STEP_DQSI_STEP); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSI_STEP_6_0, ShiftToMaskBit(D0F3_RDQSI_STEP_6_0,DqsiStep)); 
	/*AsiaPcieRead8(DramAttr->PcieBaseAddress, Address); */

	//6)
	//Set  IO calibration Address 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//7)
	// set scan end pointer
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqsiStep)*DqsiStep));

	//8)
	//set the scan times for every pointer  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x01);

	//9)
	//set RLCUBSTLENGTH[31:0] to 8 for burst length of every scan - use default  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x08);

	//Set calibration Data pattern, RM2IL/RM2IH/RM2I2L/RM2I2H
	//MPR0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[0]);
	//MPR1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[1]);
	//MPR2
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[2]);
	//MPR3
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A);
	AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDA[3]);
	//14)
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-Debug:I am in RDIMM DQSI Leveling\n"));	
		//only test UDIMM for temp
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z8);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RB_8_0_SIDE, 0x1F0);//byte4-8 on side B

		//MPR0 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[0]);
		//MPR1 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[1]);
		//MPR2 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[2]);
		//MPR3 SIDE_B
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B);
		AsiaPcieWrite64(DramAttr->PcieBaseAddress, Address, MPR_SIDB[3]);
	}
	//xx)  DQSI PSPEC does use this Reg
	//set RTIMCHKSEL  to 0 or 1, based on the required timing check mode  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//12)
	//save page mode and Enable it
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);

	//13)
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
	/*FlushCfgWrite(PeiServices, DramAttr, Address);*/
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms
	//MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	/*AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);*/
	
	//Trigger MRS3 with MPR Enable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,MR3_MPR_EN | MR3_MPR_SERIAL | MR3_MPR_PAGE0);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	/*FlushCfgWrite(PeiServices, DramAttr, Address);*/

	//14)
	//Enable Readleveling, RX201[7], RDMRLEN 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, D0F3_RDMRLEN);
	/*AsiaPcieRead8(DramAttr->PcieBaseAddress, Address); */

	// mode select ?????  no use in CHX002, mode is select in MRS comand
	/*Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);*/
	/*//Rx170[6], DDR4 Only support Serial  Mode */
	/*AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMPRRD_FORMAT, 0);*/

	//15)
	//Set TNI Calibration mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, D0F3_RDSICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, D0F3_RDSICAL_CHB);
	}

	//////////////////Enable Read Preamble Training Mode/////////////////////////
	//MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);

	Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankNo, MR4_RD_PREAMBLE_TRAIN);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);

	//enable DQS and DQ pad input buffer constantly
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQIEN|D0F3_RDSIEN|D0F3_RCMPENDQ_ON|D0F3_RCMPENDQS_ON, D0F3_RDQIEN|D0F3_RDSIEN|D0F3_RCMPENDQ_ON|D0F3_RCMPENDQS_ON);
	////////////////////////////////////////////////////////////////////////


	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger DQSI Read Leveling  \r\n"));	
	
	//16) & 17)
	//trigger scan and check if calibration is done
	if(RankNo < 4)
	{
		//RXAD1, REG_RSCNDSIDLY_CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHA,D0F3_REG_RSCNDSIDLY_CHA);
		//AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
		//delay some time
		for(Temp32=0; Temp32 <=500; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHA)!= 0);
	}
	else
	{
		//RXAD2,reg_RSCNDSIDLY_CHB 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHB, D0F3_REG_RSCNDSIDLY_CHB);
		//delay some time
		for(Temp32=0; Temp32 <=0x1000; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHB)!= 0);
	}

	//18)
	//Set DQSI Manual mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, 0);
	}

	//19)
	//Disable ReadLeveling
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
	//
	// 21)
	//Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	/*FlushCfgWrite(PeiServices, DramAttr, Address);*/
	//Trigger MRS3 with MPR Disable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankNo,DDR4_MR3_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
	}
	//Set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);


	//////////////////Disable Read Preamble Training Mode/////////////////////////
	//MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);

	Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankNo, DDR4_MR4_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 1);	//delay 1ms

	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);

	//enable DQS and DQ pad input buffer constantly
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQIEN|D0F3_RDSIEN|D0F3_RCMPENDQ_ON|D0F3_RCMPENDQS_ON,0);
	////////////////////////////////////////////////////////////////////////
	//LGE20160420 flush CFG write for RSDM registers
	/*FlushCfgWrite(PeiServices, DramAttr, Address);*/
	//disable byte8 calibration
	//EndofByte8Calibration(PeiServices, pPCIPPI, DramAttr, EccByte);
	//Clear Data Pattern ??????
	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	//Restore ODT	
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOdt);*/
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, !TRUE, &Inorder);

	if(SHOWLOG)
	{
		UINT8 DMIOSEL_BIT; 
		UINT8 Posedge_low =0, negedge_low=0;
		UINT8 Posedge_high =0, negedge_high=0;
		/*UINT16 DQSI_CENTER = 0;*/
		UINT8 ByteIndex =0;
		//ECC byte
		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES ;ByteIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"DQSI Perbit log ByteIndex = %d\n",ByteIndex));
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Pos[low high]   Neg[low high]\n"));
			for(DMIOSEL_BIT = 0X00; DMIOSEL_BIT < 0X08; DMIOSEL_BIT++){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "A%d Bit %d:",ByteIndex,DMIOSEL_BIT));

				//posedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 0);

				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);
				Posedge_high = (UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6);
				Posedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);
				//negedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 1);
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);

				negedge_high = (UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6);
				negedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%02X -- %02X] (%02x) C:%02x  -- [%02X -- %02X] (%02x) C:%02x \n ", Posedge_low,Posedge_high,Posedge_high-Posedge_low,(Posedge_high+Posedge_low)>>1,negedge_low,negedge_high,negedge_high-negedge_low,(negedge_high+negedge_low)>>1));
			}
		}
	}
	
}

VOID Rx_DQSI_LCU(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT8 DataPattern)
{ 
	//LGE20160519  Temp code
	UINT16 PageMode = 0, Inorder = 0;
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	/*UINT8  SavedOdt = 0;*/
	UINT16 SavedBARASelect = 0;
	UINT64 Address;
	UINT16  Temp16;
	UINT32 Temp32;
	BOOLEAN SHOWLOG = TRUE;

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Save BA /RA Select -- no use in CHX002
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Save Self-refresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	//Save ODT
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);*/
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//1)	Set RERRSCREN to 0, ECC 1 bit correctable error will not generate a write to bus;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);
	//2)	Set REFC[7:0] to 0, disabling auto refresh;
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//3)	Set RDMRLEN to 0, disabling DRAMC read leveling mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRLEN, 0);
	//3)--should add in Pspec later, sync with byron,need update p-spec
	//set inorder 
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);
	//4)	Set {RDQSI_STEP5,RDQSI_STEP4,RDQSI_STEP3,RDQSI_STEP2,RDQSI_STEP1,RDQSI_STEP0} for DQSI scan step;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQSO_STEP_DQSI_STEP); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSI_STEP_6_0, ShiftToMaskBit(D0F3_RDQSI_STEP_6_0,DqsiStep)); 

	//5)	Set RDMTSA[31:3]  and RTSA_STP[18:3]for calibration address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//6)	Set RSCAN_END[5:0] for the end scan pointer of every whole T 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqsiStep)*DqsiStep));

	//7)	Set RSRW_LENGTH[31:0] for the scan times of every pointer;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x04);

	//8)	Set RLCUBSTLENGTH[31:0] to 4 for the burst length of every scan
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x10);

	//9)	Set RADDRLOOPEN to 0 or 1, selecting the desired address change mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RADDRLOOPEN, D0F3_RADDRLOOPEN);
	//
	//12)	Set RTIMCHKSEL to 0 or 1 based on the required timing check mode;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//13)	Set RPGEN to 1, enabling multi-page mode;
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);

	//14)	Set RDSICAL to 1 for TNI calibration setting;
	//Set TNI Calibration mode
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, D0F3_RDSICAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, D0F3_RDSICAL_CHB);
	}

	PEI_DEBUG((PeiServices, EFI_D_WARN, "Trigger DQSI LCU  \r\n"));	
	
	//15)	Trigger reg_ RSCNDSIDLY_CHA to active DRAMCA TNI calibration function (or reg_ RSCNDSIDLY_CHB for DRAMCB);
	//16)	Wait for reg_ RSCNDSIDLY_CHA being cleared by HW (or reg_ RSCNDSIDLY_CHB for DRAMCB);
	if(RankNo < 4)
	{
		//RXAD1, REG_RSCNDSIDLY_CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHA,D0F3_REG_RSCNDSIDLY_CHA);
		//AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
		//delay some time
		for(Temp32=0; Temp32 <=500; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHA)!= 0);
	}
	else
	{
		//RXAD2,reg_RSCNDSIDLY_CHB 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNDSIDLY_CHB, D0F3_REG_RSCNDSIDLY_CHB);
		//delay some time
		for(Temp32=0; Temp32 <=0x1000; Temp32++)
		{
			AsiaIoWrite8(0x84,(UINT8)(0x01));
		}
		//waiting for read leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNDSIDLY_CHB)!= 0);
	}

	//17)	Set RDSICAL to 0 for DQSI manual setting;
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDSICAL_CHB, 0);
	}

	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore SelfRefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	//Restore ODT	
	/*SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOdt);*/
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, !TRUE, &Inorder);

	//18)	Read DMIOREG[8:0]_BITx_Ax for the calibration result and set to manual setting.
	//perbit result
	if(SHOWLOG)
	{
		UINT8 DMIOSEL_BIT; 
		UINT8 Posedge_low =0, negedge_low=0;
		UINT8 Posedge_high =0, negedge_high=0;
		/*UINT16 DQSI_CENTER = 0;*/
		UINT8 ByteIndex =0;
		//ECC byte
		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES ;ByteIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_WARN, "DQSI Perbit log ByteIndex = %d\n",ByteIndex));
			PEI_DEBUG((PeiServices, EFI_D_WARN,"Pos[low high]   Neg[low high]\n"));
			for(DMIOSEL_BIT = 0X00; DMIOSEL_BIT < 0X08; DMIOSEL_BIT++){
				PEI_DEBUG((PeiServices, EFI_D_WARN, "A%d Bit %d:",ByteIndex,DMIOSEL_BIT));

				//posedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 0);

				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);
				Posedge_high = (UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6);
				Posedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);
				//negedge
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 1);
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);

				negedge_high = (UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)>>6);
				negedge_low =(UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x3F);
				PEI_DEBUG((PeiServices, EFI_D_WARN, "[%02X -- %02X] (%02x) C:%02x  -- [%02X -- %02X] (%02x) C:%02x \n ", Posedge_low,Posedge_high,Posedge_high-Posedge_low,(Posedge_high+Posedge_low)>>1,negedge_low,negedge_high,negedge_high-negedge_low,(negedge_high+negedge_low)>>1));
			}
		}
	}
	
}

//Patch CHX002 Limitation
//1. wholeT need same for a given byte 
//2. wholeT need set when the rank not present
VOID TNI_WholeT_PatchCode(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 ChannelIndex,
	IN UINT8 ByteIndex,
	IN UINT16 TMPTNISetting)
{
	UINT8 RankIndex,RankBegin,RankEnd;

	if (ChannelIndex==0){
		RankBegin=0;
		RankEnd=4;
	}
	else{
		RankBegin=4;
		RankEnd=8;
	}

	if(TMPTNISetting%0x40==0){
		for(RankIndex=RankBegin; RankIndex<RankEnd; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				if (DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting <=TMPTNISetting)
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting =TMPTNISetting;
			}
		}
	}else{
		for(RankIndex=RankBegin; RankIndex<RankEnd; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				if (DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting >=TMPTNISetting)
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting =TMPTNISetting;
			}
		}
	}	
}

VOID TNI_WholeT_Adjust(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 ChannelIndex,
	IN UINT8 ByteIndex)
{
	UINT16	TMPTNISetting=0;	
	UINT16  CHANNELTNIHIGH[ASIA_MAX_BYTES];
	UINT16  CHANNELTNILOW[ASIA_MAX_BYTES];
	UINT8   RankIndex,RankBegin,RankEnd;

	if (ChannelIndex==CHANNELA){
		RankBegin=0;
		RankEnd=4;
	}else
	{
		RankBegin=4;
		RankEnd=8;
	}		
	(*PeiServices)->SetMem(CHANNELTNIHIGH, sizeof(CHANNELTNIHIGH), 0);
	(*PeiServices)->SetMem(CHANNELTNILOW,  sizeof(CHANNELTNILOW), 0xff);

	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		for(RankIndex=RankBegin; RankIndex<RankEnd; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				if (DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting > CHANNELTNIHIGH[ByteIndex])
					CHANNELTNIHIGH[ByteIndex]=DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting;
				if (DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting < CHANNELTNILOW[ByteIndex])
					CHANNELTNILOW[ByteIndex]=DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting;
			}
		}

		//can not patch CHX002 TNI limitation
		if(CHANNELTNIHIGH[ByteIndex]- CHANNELTNILOW[ByteIndex] > 0x40)
		{
			//TODO hang!!!
			return;
		}

		TMPTNISetting=(CHANNELTNIHIGH[ByteIndex]/0x40)*0x40;

		if((CHANNELTNIHIGH[ByteIndex]/0x40)!= (CHANNELTNILOW[ByteIndex]/0x40)){
			if(CHANNELTNIHIGH[ByteIndex]%0x40 > (0x40-CHANNELTNILOW[ByteIndex]%0x40))
				TMPTNISetting=(CHANNELTNIHIGH[ByteIndex]/0x40)*0x40;
			else
				TMPTNISetting=(CHANNELTNIHIGH[ByteIndex]/0x40)*0x40 -1;
				//modified by rkd
				/*TMPTNISetting=(CHANNELTNILOW[ByteIndex]/0x40)*0x40;*/

			TNI_WholeT_PatchCode(PeiServices, pPCIPPI, DramAttr,ChannelIndex,ByteIndex,TMPTNISetting);
		}
		if (ChannelIndex==CHANNELA)
			DramAttr->CHAWholeT[ByteIndex]=TMPTNISetting/0x40; //save CHB wholeT for un present rank use
		else
			DramAttr->CHBWholeT[ByteIndex]=TMPTNISetting/0x40; //save CHB wholeT for un present rank use
	}
}

VOID HW_TNI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex;
	UINT16		RxCalNum;
	BOOLEAN		RxResult = TRUE;	 	
	UINT32		Default_MPR = 0x000F3355;
	UINT16		*TNIRange = NULL;
	BOOLEAN		ECC_ENABLE = FALSE;
	UINT8		TniStep = 2;
	UINT8 ByteIndex = 0;
	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

#if 0
	//Change MPR Pattern
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, NewPattern, MprNo);
			}

		}
	}
#endif

#if 0
	//replace by Rx_DQSI_Delay --RKD-20180528 
	Value16=0x10;  //default 1/4T	
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
	if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
	{
	Set_DQSI_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex,Value16);
	}
	}
#endif
	//setting dqsi quater_t first -- for debug only
//	Rx_DQSI_Delay(PeiServices, pPCIPPI, DramAttr, DQSI_QUATER_T_DELAY);
	Rx_TNI_ClearDataset(PeiServices, pPCIPPI, DramAttr, ALLRANK);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "TNI Read Leveling - start\r\n"));		
	//Set DQSI 1/4T Delay
	/*Rx_DQSI_Delay(PeiServices, pPCIPPI, DramAttr, DQSI_QUATER_T_DELAY);*/
	for(RxCalNum = 0; RxCalNum<=0x03; RxCalNum++)
	{
		RxResult = TRUE;
		//Do TNI ReadLeveling and save results at dataset
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI Read Leveling -RankIndex :%d\r\n",RankIndex));		
				//Clear dataset
				Rx_TNI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
				//by rank calibration
#if 1
				Rx_TNI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, TniStep , ECC_ENABLE, READ_LEVELING_CMP_BOTH_EDGE, Default_MPR);
				Rx_TNI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);
#endif
				//by byte tni calibration patch stagger mode
#if 0
				{
					UINT8 ByteIndex =0;
					for( ByteIndex = 0; ByteIndex<(ECC_ENABLE ? ASIA_MAX_BYTES: (ASIA_MAX_BYTES-1)); ByteIndex++)
					{
						//caculate MPR pattern base on DQ map
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI ReadLeveling Byte :%d\r\n",ByteIndex));		
						Rx_TNI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, TniStep, ECC_ENABLE, READ_LEVELING_CMP_BOTH_EDGE, Default_MPR);
						Rx_TNI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex);
					}
				}
#endif

				DramAttr->DramAutoCal[RankIndex][0].CalResult = Rx_TNI_ReadLeveling_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, TNIRange);

				DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_TNI, NULL,RankIndex,0x11);
				if(DramAttr->DramAutoCal[RankIndex][0].CalResult == FALSE)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR!!! Rank%d TNI ReadLeveling  Calibration FAIL!!\r\n",RankIndex));		
					RxResult = FALSE ;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank%d  TNI ReadLeveling Calibration PASS!!\r\n", RankIndex));		
				}
			}
		}

		if(RxResult==TRUE)
			break;
	}

	 if(!RxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_TNI);	

	 }

	// =============================pacth code BEG============================
	// check wholeT, should setting the same value for a channle for a byte(CHX002 limitation)
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{	
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0) 
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELA,ByteIndex);
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)		
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELB,ByteIndex);

	}
	
	
	// =============================pacth code END============================

	//setting 
	if(DramAttr->ConfigData.DQSIByRank == BYRANK_ENABLE){	
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	}
		}
	else	{		
	
	if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf){
		RankIndex=0;
	Rx_TNI_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	
		}	
	if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf0){
		RankIndex=4;
	Rx_TNI_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	
		}	
		}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "TNI Read Leveling - end\r\n"));	
}

VOID HW_TNI_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex;
	UINT16		RxCalNum;
	BOOLEAN		RxResult = TRUE;	 	
	UINT16		*TNIRange = NULL;
	BOOLEAN     ECC_ENABLE = FALSE;
	UINT8		TniStep = 2;
//	UINT16		TMPTNISetting=0;
	UINT8 ByteIndex = 0;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "TNI LCU Calibration - start\r\n"));		
	Rx_TNI_ClearDataset(PeiServices, pPCIPPI, DramAttr, ALLRANK);

	for(RxCalNum = 0; RxCalNum<0x1; RxCalNum++)
	{
		RxResult = TRUE;
		//Do TNI LCU Calibration and save results at dataset
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI LCU Calibration  -RankIndex :%d\r\n",RankIndex));		
				//Clear dataset
				Rx_TNI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
				Rx_TNI_LCU(PeiServices, pPCIPPI, DramAttr, RankIndex, TniStep, 0XAA);

				Rx_TNI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);
				DramAttr->DramAutoCal[RankIndex][0].CalResult = Rx_TNI_ReadLeveling_CheckRange(PeiServices, DramAttr,RankIndex,ECC_ENABLE,TNIRange);

				DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_TNI, TNIRange,RankIndex,0x12);
				if(DramAttr->DramAutoCal[RankIndex][0].CalResult == FALSE)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR!!! Rank%d TNI LCU Calibration FAIL!!\r\n",RankIndex));		
					RxResult = FALSE ;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank%d Calibration TNI LCU  PASS!!\r\n", RankIndex));		
				}
			}
		}

		if(RxResult==TRUE)
			break;
	}
	 if(!RxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_TNI);	

	 }
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0) 
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELA,ByteIndex);
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELB,ByteIndex);
	}

	// =============================pacth code END============================

	//setting
	if(DramAttr->ConfigData.DQSIByRank == BYRANK_ENABLE){	
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	}
		}
	else	{		
	
	if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf){
		RankIndex=0;
	Rx_TNI_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	
		}	
	if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf0){
		RankIndex=4;
	Rx_TNI_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	
		}	
		}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "TNI LCU - end\r\n"));	
}

VOID RX_3DScan_By_TNI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex = 0;
	//	UINT16     	RxCalNum;
	BOOLEAN		RxResult;	
	//	UINT8		DqsiStep = 0X02;

	UINT32		Default_MPR = 0x000F3355;
	//	UINT8		(*DQSIRange)[ASIA_MAX_BIT][2] = NULL;
	BOOLEAN		ECC_ENABLE = FALSE;
	UINT8 ByteIndex = 0,ByteMax=8;
	UINT16      DQSITmp=0x0,DQSIStep=0x4,DQSITmpBegin=0x8,DQSITmpEnd=0x30;
	//	UINT16		Value16,DQSiPOSHigh,DQSiPOSLow,DQSiNEGHigh,DQSiNEGLow;
	UINT16		Value16,TNITmpMaxLow[ASIA_MAX_BYTES],TNITmpMaxHigh[ASIA_MAX_BYTES];
	UINT8      RxvrefTmp=0x28,RxvrefStep=0x8,RxvrefTmpMax[ASIA_MAX_BYTES];
	UINT8      RxvrefBegin=0x40,RxvrefEnd=0x88;
	//	UINT16		DQSIRange[(TNITmpEnd-TNITmpBegin)/TNIStep+1][(RxvrefEnd-RxvrefBegin)/RxvrefStep+1];
	UINT16		TNIRange[0x22][0x10];
	UINT16		TNILow[0x22][0x10],TNIHigh[0x22][0x10];
	UINT16		TNIRangeTmpMax[ASIA_MAX_BYTES],DQSITmpMax[ASIA_MAX_BYTES];
	UINT8		BitIndex=0,TniStep=2;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	if (ECC_ENABLE)
		ByteMax=9;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX 3D scan by TNI - start\r\n"));		

	//	for(RxCalNum = 0; RxCalNum<0x01; RxCalNum++)
	//	{
	RxResult = TRUE;
	Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
	//Do DQSI Read Leveling and save results at dataset
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankIndex: %2x ",RankIndex));							
			(*PeiServices)->SetMem(DQSITmpMax, sizeof(DQSITmpMax), 0);					
			(*PeiServices)->SetMem(RxvrefTmpMax, sizeof(RxvrefTmpMax), 0); 				
			(*PeiServices)->SetMem(TNIRangeTmpMax, sizeof(TNIRangeTmpMax), 0);					
			(*PeiServices)->SetMem(TNITmpMaxLow, sizeof(TNITmpMaxLow), 0);	
			(*PeiServices)->SetMem(TNITmpMaxHigh, sizeof(TNITmpMaxHigh), 0);	

			for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex: %2x\r\n",ByteIndex));							
				(*PeiServices)->SetMem(TNIRange,  sizeof(TNIRange), 0);					
				(*PeiServices)->SetMem(TNILow,sizeof(TNILow), 0x0);					
				(*PeiServices)->SetMem(TNIHigh,  sizeof(TNIHigh), 0);					
				for(RxvrefTmp=RxvrefBegin; RxvrefTmp<=RxvrefEnd; RxvrefTmp+=RxvrefStep) {
					Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,RxvrefTmp);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x: ",RxvrefTmp));							

					for(DQSITmp=DQSITmpBegin; DQSITmp<DQSITmpEnd; DQSITmp+=DQSIStep) 
					{

						//set TNI WholeT default start from 0x1
						Value16 = DQSITmp;
						for(BitIndex=0x0; BitIndex<8; BitIndex++)
						{
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, POS, &(Value16));
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, NEG, &(Value16));
						}
						TriggerLoadReg(PeiServices, DramAttr);
						PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x: ",DQSITmp));					


						//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI ReadLeveling Byte :%d\r\n",ByteIndex));		
						Rx_TNI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, TniStep, ECC_ENABLE, READ_LEVELING_CMP_BOTH_EDGE, Default_MPR);

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep] = Value16*0x40; // convert wholeT to phase

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE,	 IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep] += Value16; // convert wholeT to phase

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep] = Value16*0x40; // convert wholeT to phase

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE,	 IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep] += Value16; // convert wholeT to phase

						TNIRange[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]=TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]-TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep];	
						if (TNIRange[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]>=0x100)
							TNIRange[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]=0;
						PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x:(%2x-%2x) ",TNIRange[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep],TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep],TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]));							

						if (TNIRangeTmpMax[ByteIndex]<TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]-TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]){
							TNIRangeTmpMax[ByteIndex]=TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep]-TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep];
							RxvrefTmpMax[ByteIndex]=RxvrefTmp;
							DQSITmpMax[ByteIndex]=DQSITmp;
							TNITmpMaxLow[ByteIndex]=TNILow[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep];
							TNITmpMaxHigh[ByteIndex]=TNIHigh[(RxvrefTmp-RxvrefBegin)/RxvrefStep][(DQSITmp-DQSITmpBegin)/DQSIStep];					
						}
						//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));	

					}

					PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex:%2x : %2x (%02x -%02x) Rxvref:%2x Dqsi: %2x\r\n",ByteIndex,(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2,TNITmpMaxLow[ByteIndex],TNITmpMaxHigh[ByteIndex],RxvrefTmpMax[ByteIndex],DQSITmpMax[ByteIndex]));	
				}
				//#if 1
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));	

				//#endif

			}
			//set usable TNI and Rxvref for next step
			for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
//				RxvrefTmp=RxvrefTmpMax[ByteIndex];
//				Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,RxvrefTmp);
				if(DramAttr->ConfigData.TNIHighPulse){
					//LGE20180620 for HIGH PULSE
					if (DramAttr->RPREA == RPREA1CLK)
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNITmpMaxHigh[ByteIndex] - 0x18;				
					else
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNITmpMaxHigh[ByteIndex] - 0x20;				
					}	
				else
					//Low Pulse
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=(TNITmpMaxHigh[ByteIndex]+TNITmpMaxLow[ByteIndex])/2;  // average value

				PEI_DEBUG((PeiServices, EFI_D_ERROR, " %04x(%04x-%04x)",TNITmpMaxHigh[ByteIndex]-TNITmpMaxLow[ByteIndex],TNITmpMaxLow[ByteIndex],TNITmpMaxHigh[ByteIndex]));		

/*
				Value16=(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2;
				Value16 = (Value16 & 0x1C0)>>(RegisterOffset16bit(0x1C0));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CKS :Rank%x, Byte%x, TNI WholeT:%x  ",RankIndex,ByteIndex,Value16)); 	
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//set TNI Phase default start from 0x10
				Value16=(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2;
				Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);
//				Value16 = (Value16 & 0x3F)>>(RegisterOffset16bit(0x3F));  //assume is 0x10 
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "PHASE:0x%x\r\n",Value16));		
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
*/
			}				
		}
	}
	// check wholeT, should setting the same value for a channle for a byte(CHX002 limitation)
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{	
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0) 
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELA,ByteIndex);
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)		
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELB,ByteIndex);
	}
	//setting 
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	}	

	//		if(RxResult==TRUE)
	//			break;
	//	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX 3D scan by TNI -  end\r\n"));		
}

VOID RX_2DScan_By_TNI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex = 0;
	//	UINT16     	RxCalNum;
	BOOLEAN		RxResult;	
	//	UINT8		DqsiStep = 0X02;

	UINT32		Default_MPR = 0x000F3355;
	BOOLEAN		ECC_ENABLE = FALSE;
	UINT8 ByteIndex = 0,ByteMax=8;
	UINT16      DQSITmp=0x0,DQSIStep=0x4,DQSITmpBegin=0x0,DQSITmpEnd=0x40;
	UINT16		Value16,TNITmpMaxLow[ASIA_MAX_BYTES],TNITmpMaxHigh[ASIA_MAX_BYTES];
//	UINT16		TNIRange[0x10];
	UINT16		TNILow[0x10],TNIHigh[0x10],DQSITmpMax[ASIA_MAX_BYTES];
//	UINT16		TNIRangeTmpMax[ASIA_MAX_BYTES],DQSITmpMax[ASIA_MAX_BYTES];
	UINT8		BitIndex=0,TniStep=2;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	if (ECC_ENABLE)
		ByteMax=9;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX 3D scan by TNI - start\r\n"));		

	//	for(RxCalNum = 0; RxCalNum<0x01; RxCalNum++)
	//	{
	RxResult = TRUE;
	Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
	//Do DQSI Read Leveling and save results at dataset
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n\r\n  RankIndex: %2x ",RankIndex));							
			(*PeiServices)->SetMem(DQSITmpMax, sizeof(DQSITmpMax), 0);					
//			(*PeiServices)->SetMem(RxvrefTmpMax, sizeof(RxvrefTmpMax), 0); 				
//			(*PeiServices)->SetMem(TNIRangeTmpMax, sizeof(TNIRangeTmpMax), 0);					
			(*PeiServices)->SetMem(TNITmpMaxLow, sizeof(TNITmpMaxLow), 0);	
			(*PeiServices)->SetMem(TNITmpMaxHigh, sizeof(TNITmpMaxHigh), 0);	

			for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex: %2x",ByteIndex));							
//				(*PeiServices)->SetMem(TNIRange,  sizeof(TNIRange), 0);					
				(*PeiServices)->SetMem(TNILow,  sizeof(TNILow), 0xff);					
				(*PeiServices)->SetMem(TNIHigh,  sizeof(TNIHigh), 0);					
//				for(RxvrefTmp=RxvrefBegin; RxvrefTmp<=RxvrefEnd; RxvrefTmp+=RxvrefStep) {
//					Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,RxvrefTmp);
//					PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x: ",RxvrefTmp));							

					for(DQSITmp=DQSITmpBegin; DQSITmp<DQSITmpEnd; DQSITmp+=DQSIStep) 
					{

						//set TNI WholeT default start from 0x1
						Value16 = DQSITmp;
						for(BitIndex=0x0; BitIndex<8; BitIndex++)
						{
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, POS, &(Value16));
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 1<<BitIndex, NEG, &(Value16));
						}
						TriggerLoadReg(PeiServices, DramAttr);
						PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x: ",DQSITmp));					


						//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI ReadLeveling Byte :%d\r\n",ByteIndex));		
						Rx_TNI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, TniStep, ECC_ENABLE, READ_LEVELING_CMP_BOTH_EDGE, Default_MPR);

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep] = Value16*0x40; // convert wholeT to phase

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE,	 IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep] += Value16; // convert wholeT to phase

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep] = Value16*0x40; // convert wholeT to phase

						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE,	 IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep] += Value16; // convert wholeT to phase

//						TNIRange[(DQSITmp-DQSITmpBegin)/DQSIStep]=TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep]-TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep];	
//						if (TNIRange[(DQSITmp-DQSITmpBegin)/DQSIStep]>=0x100)
//							TNIRange[(DQSITmp-DQSITmpBegin)/DQSIStep]=0;
//						PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x:(%04x-%04x) ",TNIRange[(DQSITmp-DQSITmpBegin)/DQSIStep],TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep],TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep]));							
						PEI_DEBUG((PeiServices, EFI_D_ERROR, " (%04x-%04x) ",TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep],TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep]));							
/*
						if (TNIRangeTmpMax[ByteIndex]<TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep]-TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep]){
							TNIRangeTmpMax[ByteIndex]=TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep]-TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep];
							DQSITmpMax[ByteIndex]=DQSITmp;
							TNITmpMaxLow[ByteIndex]=TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep];
							TNITmpMaxHigh[ByteIndex]=TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep];					
						}
*/						
						//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));	
						if (TNITmpMaxHigh[ByteIndex]<TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep]){
							TNITmpMaxHigh[ByteIndex]=TNIHigh[(DQSITmp-DQSITmpBegin)/DQSIStep];
							DQSITmpMax[ByteIndex]=DQSITmp;							
							TNITmpMaxLow[ByteIndex]=TNILow[(DQSITmp-DQSITmpBegin)/DQSIStep];
							}
					}

//					PEI_DEBUG((PeiServices, EFI_D_ERROR, "  %2x (%04x -%04x) Dqsi: %2x\r\n",(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2,TNITmpMaxHigh[ByteIndex],TNITmpMaxLow[ByteIndex],DQSITmpMax[ByteIndex]));	
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "  (%04x -%04x) Dqsi: %2x\r\n",TNITmpMaxHigh[ByteIndex],TNITmpMaxLow[ByteIndex],DQSITmpMax[ByteIndex]));	

//				}
				//#if 1
//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));	

				//#endif

			}
			//set usable TNI and Rxvref for next step
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "2DByTNI Rank%2x  ",RankIndex));	
			for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
//				RxvrefTmp=RxvrefTmpMax[ByteIndex];
//				Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,RxvrefTmp);

				if(DramAttr->ConfigData.TNIHighPulse){
					//LGE20180620 for HIGH PULSE
					if (DramAttr->RPREA == RPREA1CLK)
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNITmpMaxHigh[ByteIndex] - 0x18;				
					else
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNITmpMaxHigh[ByteIndex] - 0x20;				
				}		
				else
					//Low Pulse
//					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=(TNIlowbound[ByteIndex]+TNIhighbound[ByteIndex])/2;  // average value
						DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2;//TODO RKD:need adjust 0x10 for bringup
				PEI_DEBUG((PeiServices, EFI_D_ERROR, " %02x(%04x-%04x)",TNITmpMaxHigh[ByteIndex]-TNITmpMaxLow[ByteIndex],TNITmpMaxLow[ByteIndex],TNITmpMaxHigh[ByteIndex]));		
/*
				Value16=(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2;
				Value16 = (Value16 & 0x1C0)>>(RegisterOffset16bit(0x1C0));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CKS :Rank%x, Byte%x, TNI WholeT:%x  ",RankIndex,ByteIndex,Value16)); 	
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//set TNI Phase default start from 0x10
				Value16=(TNITmpMaxLow[ByteIndex]+TNITmpMaxHigh[ByteIndex])/2;
				Value16= Rx_TNI_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);
//				Value16 = (Value16 & 0x3F)>>(RegisterOffset16bit(0x3F));  //assume is 0x10 
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "PHASE:0x%x\r\n",Value16));		
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
*/
			}				
		}
	}
	// check wholeT, should setting the same value for a channle for a byte(CHX002 limitation)
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{	
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0) 
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELA,ByteIndex);
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)		
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELB,ByteIndex);
	}
	//setting 
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	}	

	//		if(RxResult==TRUE)
	//			break;
	//	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX 3D scan by TNI -  end\r\n"));		
}

VOID RX_Scan_with_SI_Rxvref(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex = 0;
	BOOLEAN		RxResult;	
	UINT8		DqsiStep = 0X02;

	UINT32		Default_MPR = 0x000F3355;
	BOOLEAN		ECC_ENABLE = FALSE;
	UINT8 ByteIndex = 0,ByteMax=8;
	UINT16      TNITmp=0x80,TNIStep=0x4,TNITmpBegin=0x80,TNITmpEnd=0x2C0;
	UINT16		Value16,DQSIHigh[ASIA_MAX_BYTES],DQSILow[ASIA_MAX_BYTES];
	UINT16		DQSIRange[ASIA_MAX_BYTES][0x80];
	UINT16		DQSINEGLow[ASIA_MAX_BYTES][0x80],DQSINEGHigh[ASIA_MAX_BYTES][0x80],DQSIPOSLow[ASIA_MAX_BYTES][0x80],DQSIPOSHigh[ASIA_MAX_BYTES][0x80];
	UINT16		DQSIRangeTmpMax[ASIA_MAX_BYTES],TNITmpMax[ASIA_MAX_BYTES];
	UINT16		TNIlowbound[ASIA_MAX_BYTES],TNIhighbound[ASIA_MAX_BYTES];
	
	
	UINT8 TNIIndex = 0;
		   switch (DramAttr->DramFreq)
	{
	
	   case DRAM_FREQ_1600:
				 TNITmpBegin=0x80;
				 TNITmpEnd=0x240;					 
		   break;
	
	   case DRAM_FREQ_2133:
		   TNITmpBegin=0x80;
		   TNITmpEnd=0x260; 				   
		   break;
	
	   case DRAM_FREQ_2400:
		   TNITmpBegin=0xC0;
		   TNITmpEnd=0x2A0; 				   
		   break;
	   case DRAM_FREQ_2666:
		   TNITmpBegin=0xE0;
		   TNITmpEnd=0x2C0; 				   
		   break;
	   case DRAM_FREQ_2933:
		   TNITmpBegin=0x120;
		   TNITmpEnd=0x300; 				   
		   break;
	
	   case DRAM_FREQ_3200: 
		   TNITmpBegin=0x160;
		   TNITmpEnd=0x340; 				   
		   break;				 
	
		 default:
			 TNITmpBegin=0x110;
			 TNITmpEnd=0x300;					 
		 break;
		 }

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	if (ECC_ENABLE)
		ByteMax=9;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX scan by SI Rxvref - start\r\n"));		
	//DumpD0F3(PeiServices,DramAttr);

		RxResult = TRUE;
		Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
		//Do DQSI Read Leveling and save results at dataset
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				(*PeiServices)->SetMem(DQSIRangeTmpMax,  sizeof(DQSIRangeTmpMax), 0);					
				(*PeiServices)->SetMem(TNITmpMax, sizeof(TNITmpMax), 0);					
				(*PeiServices)->SetMem(TNIlowbound, sizeof(TNIlowbound), 0xff);					
				(*PeiServices)->SetMem(TNIhighbound, sizeof(TNIhighbound), 0);					
				(*PeiServices)->SetMem(DQSIHigh, sizeof(DQSIHigh), 0);					
				(*PeiServices)->SetMem(DQSILow, sizeof(DQSILow), 0x40);					
//				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankIndex: %2x ",RankIndex)); 						
			
//				for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
//					PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankIndex: %2x ByteIndex: %2x \r\n",RankIndex,ByteIndex));							
				(*PeiServices)->SetMem(DQSIRange,sizeof(DQSIRange), 0);					
				(*PeiServices)->SetMem(DQSINEGLow, sizeof(DQSINEGLow), 0);					
				(*PeiServices)->SetMem(DQSINEGHigh,sizeof(DQSINEGHigh), 0x40);					
				(*PeiServices)->SetMem(DQSIPOSLow, sizeof(DQSIPOSLow), 0);					
				(*PeiServices)->SetMem(DQSIPOSHigh, sizeof(DQSIPOSHigh), 0x40);					

				for(TNITmp=TNITmpBegin; TNITmp<=TNITmpEnd; TNITmp+=TNIStep) 
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, " %x: ",TNITmp));		
					Rx_TNI_Set_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex,ByteIndex,TNITmp);				

					TriggerLoadReg(PeiServices, DramAttr);

					Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
					for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES ;ByteIndex++) {

					DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, 1, POS, &Value16);
					DQSIPOSLow[ByteIndex][TNIIndex]=Value16;
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, 1, POS, &Value16);
					DQSIPOSHigh[ByteIndex][TNIIndex]=Value16;
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, 1, NEG, &Value16);
					DQSINEGLow[ByteIndex][TNIIndex]=Value16;
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, 1, NEG, &Value16);
					DQSINEGHigh[ByteIndex][TNIIndex]=Value16;
						
					if(DQSIPOSHigh[ByteIndex][TNIIndex]>DQSINEGHigh[ByteIndex][TNIIndex])
						DQSIHigh[ByteIndex]=DQSINEGHigh[ByteIndex][TNIIndex];
					else
						DQSIHigh[ByteIndex]=DQSIPOSHigh[ByteIndex][TNIIndex];

					if(DQSIPOSLow[ByteIndex][TNIIndex]<DQSINEGLow[ByteIndex][TNIIndex])
						DQSILow[ByteIndex]=DQSINEGLow[ByteIndex][TNIIndex];
					else
						DQSILow[ByteIndex]=DQSIPOSLow[ByteIndex][TNIIndex];

					DQSIRange[ByteIndex][TNIIndex]=DQSIHigh[ByteIndex]-DQSILow[ByteIndex];	
						if (DQSIRange[ByteIndex][TNIIndex]>=0x40)
							DQSIRange[ByteIndex][TNIIndex]=0;	
						else if(DQSIRange[ByteIndex][TNIIndex]>=0xa){
							if (TNIlowbound[ByteIndex]>TNITmp)
								TNIlowbound[ByteIndex]=TNITmp;
							if (TNIhighbound[ByteIndex]<TNITmp)
								TNIhighbound[ByteIndex]=TNITmp;
							}
					}		
					for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES ;ByteIndex++) {
							
					PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x:(%2x-%2x|%2x-%2x) ",DQSIRange[ByteIndex][TNIIndex],DQSIPOSLow[ByteIndex][TNIIndex],DQSIPOSHigh[ByteIndex][TNIIndex],DQSINEGLow[ByteIndex][TNIIndex],DQSINEGHigh[ByteIndex][TNIIndex]));							
						}
					if (DQSIRangeTmpMax[ByteIndex]<DQSIHigh[ByteIndex]-DQSILow[ByteIndex]){
						DQSIRangeTmpMax[ByteIndex]=DQSIHigh[ByteIndex]-DQSILow[ByteIndex];
						TNITmpMax[ByteIndex]=TNITmp;
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "CKS TNITmpMax[%2x]:%2x ",ByteIndex,TNITmp));							
						
					}


					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));	
				}

//			}
			//set usable TNI and Rxvref for next step
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "2DByDQSi Rank%2x  ",RankIndex));	
			for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
//				DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=TNITmpMax[ByteIndex]+0x10;
//				DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=TNIlowbound[ByteIndex]+0x10; //Lowbound +1/4T
				
				if(DramAttr->ConfigData.TNIHighPulse){
					//LGE20180620 for HIGH PULSE
					if (DramAttr->RPREA == RPREA1CLK)
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNIhighbound[ByteIndex] - 0x18;				
					else
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= TNIhighbound[ByteIndex] - 0x20;				
				}		
				else
					//Low Pulse
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=(TNIlowbound[ByteIndex]+TNIhighbound[ByteIndex])/2;  // average value
				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "%02x(%04x-%04x) ",TNIhighbound[ByteIndex]-TNIlowbound[ByteIndex],TNIlowbound[ByteIndex],TNIhighbound[ByteIndex]) );
			if(TNIhighbound[ByteIndex]==0)
				{
				CalErrorReboot(PeiServices, DramAttr, IO_2D_ByDQSI); 
				}
			}	
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));				
		}
	}
	// check wholeT, should setting the same value for a channle for a byte(CHX002 limitation)
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{	
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0) 
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELA,ByteIndex);
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)		
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELB,ByteIndex);

	}
	//setting 
	if(DramAttr->ConfigData.DQSIByRank == BYRANK_ENABLE){	
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	}
		}
	else	{		
	
	if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf){
		RankIndex=0;
	Rx_TNI_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	
		}	
	if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf0){
		RankIndex=4;
	Rx_TNI_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	
		}	
		}

//		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
//		{
//			Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
//		}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX scan by SI Rxvref -  end\r\n"));		
}

VOID RX_3DScan_By_DQSI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex = 0;
	BOOLEAN		RxResult;	
	UINT8		DqsiStep = 0X02;

	UINT32		Default_MPR = 0x000F3355;
	BOOLEAN		ECC_ENABLE = FALSE;
	UINT8		ByteIndex = 0,ByteMax=8,i=0;
	UINT16      TNITmp=0xE0,TNIStep=0x4,TNITmpBegin=0xE0,TNITmpEnd=0x240;
	UINT16		Value16,DQSIHigh,DQSILow;
	UINT8		RxvrefTmp=0x40,RxvrefStep=0x8,RxvrefTmpMax[ASIA_MAX_BYTES];
	UINT8		RxvrefBegin=0x40,RxvrefEnd=0x88;//daisy modify rxvref
	UINT16		DQSIRange[0x10][0x80];
	UINT16		DQSINEGLow[0x10][0x80],DQSINEGHigh[0x10][0x80],DQSIPOSLow[0x10][0x80],DQSIPOSHigh[0x10][0x80];
	UINT16		DQSIRangeTmpMax[ASIA_MAX_BYTES],TNITmpMax[ASIA_MAX_BYTES];
	UINT16		TMPTNIRangemax[ASIA_MAX_BYTES],TNIRange[0x10][ASIA_MAX_BYTES],TNIlowbound[0x10][ASIA_MAX_BYTES],TNIhighbound[0x10][ASIA_MAX_BYTES];
	UINT16		MinTNIlowbound[ASIA_MAX_BYTES],MaxTNIhighbound[ASIA_MAX_BYTES];

	UINT8 RxvrefIndex =0;
	UINT8 TNIIndex = 0;



	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	if (ECC_ENABLE)
		ByteMax=9;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX 3D scan by DQSi - start\r\n"));		
	//DumpD0F3(PeiServices,DramAttr);

	//	for(RxCalNum = 0; RxCalNum<0x01; RxCalNum++)
	//	{
	RxResult = TRUE;
	Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
	//Do DQSI Read Leveling and save results at dataset
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
		{
			(*PeiServices)->SetMem(DQSIRangeTmpMax,  sizeof(DQSIRangeTmpMax), 0);					
			(*PeiServices)->SetMem(RxvrefTmpMax,  sizeof(RxvrefTmpMax), 0); 				
			(*PeiServices)->SetMem(TNITmpMax, sizeof(TNITmpMax), 0);					
			(*PeiServices)->SetMem(TNIlowbound, sizeof(TNIlowbound), 0xff); 				
			(*PeiServices)->SetMem(TNIhighbound, sizeof(TNIhighbound), 0);	
			(*PeiServices)->SetMem(MinTNIlowbound, sizeof(MinTNIlowbound), 0xff); 				
			(*PeiServices)->SetMem(MaxTNIhighbound, sizeof(MaxTNIhighbound), 0);					
			(*PeiServices)->SetMem(TNIRange, sizeof(TNIRange), 0);					
			(*PeiServices)->SetMem(TMPTNIRangemax, sizeof(TMPTNIRangemax), 0);					
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankIndex: %2x ",RankIndex)); 						

			for(ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex: %2x \r\n",ByteIndex));							
				(*PeiServices)->SetMem(DQSIRange,sizeof(DQSIRange), 0);					
				(*PeiServices)->SetMem(DQSINEGLow, sizeof(DQSINEGLow), 0);					
				(*PeiServices)->SetMem(DQSINEGHigh,sizeof(DQSINEGHigh), 0x40);					
				(*PeiServices)->SetMem(DQSIPOSLow, sizeof(DQSIPOSLow), 0);					
				(*PeiServices)->SetMem(DQSIPOSHigh, sizeof(DQSIPOSHigh), 0x40);					


				for ( TNITmp=TNITmpBegin; TNITmp<=TNITmpEnd; TNITmp+=TNIStep )
				{
						PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "  %x           \t    ",TNITmp ) );
				}
				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "\r\n" ) );

				for(RxvrefTmp=RxvrefBegin; RxvrefTmp<=RxvrefEnd; RxvrefTmp+=RxvrefStep) {
						Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,RxvrefTmp);
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "%x: ",RxvrefTmp));		
				for ( TNITmp=TNITmpBegin; TNITmp<=TNITmpEnd; TNITmp+=TNIStep )
				{
//							PEI_DEBUG((PeiServices, EFI_D_ERROR, "%x:",TNITmp));		
					Rx_TNI_Set_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex,ByteIndex,TNITmp);				
						TriggerLoadReg(PeiServices, DramAttr);

						Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);

						RxvrefIndex = (UINT8)((RxvrefTmp-RxvrefBegin)/RxvrefStep); 
						TNIIndex = (UINT8)((TNITmp-TNITmpBegin)/TNIStep);

						DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, 1, POS, &Value16);
						DQSIPOSLow[RxvrefIndex][TNIIndex]=Value16;

						DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, 1, POS, &Value16);
						DQSIPOSHigh[RxvrefIndex][TNIIndex]=Value16;

						DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, 1, NEG, &Value16);
						DQSINEGLow[RxvrefIndex][TNIIndex]=Value16;

						DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, 1, NEG, &Value16);
						DQSINEGHigh[RxvrefIndex][TNIIndex]=Value16;

						if(DQSIPOSHigh[RxvrefIndex][TNIIndex]>DQSINEGHigh[RxvrefIndex][TNIIndex])
							DQSIHigh=DQSINEGHigh[RxvrefIndex][TNIIndex];
						else
							DQSIHigh=DQSIPOSHigh[RxvrefIndex][TNIIndex];

						if(DQSIPOSLow[RxvrefIndex][TNIIndex]<DQSINEGLow[RxvrefIndex][TNIIndex])
							DQSILow=DQSINEGLow[RxvrefIndex][TNIIndex];
						else
							DQSILow=DQSIPOSLow[RxvrefIndex][TNIIndex];

						DQSIRange[RxvrefIndex][TNIIndex]=(DQSIHigh>DQSILow)? (DQSIHigh-DQSILow) :0;	
						if(DQSIRange[RxvrefIndex][TNIIndex]>=0xa){
													if (TNIlowbound[RxvrefIndex][ByteIndex]>TNITmp)
														TNIlowbound[RxvrefIndex][ByteIndex]=TNITmp;
													if (TNIhighbound[RxvrefIndex][ByteIndex]<TNITmp)
														TNIhighbound[RxvrefIndex][ByteIndex]=TNITmp;
													}


						PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x:(%2x-%2x|%2x-%2x) ",DQSIRange[RxvrefIndex][TNIIndex],DQSIPOSLow[RxvrefIndex][TNIIndex],DQSIPOSHigh[RxvrefIndex][TNIIndex],DQSINEGLow[RxvrefIndex][TNIIndex],DQSINEGHigh[RxvrefIndex][TNIIndex]));							
				TNIRange[RxvrefIndex][ByteIndex]=	TNIhighbound[RxvrefIndex][ByteIndex]-TNIlowbound[RxvrefIndex][ByteIndex];		
						if (DQSIRangeTmpMax[ByteIndex] < DQSIRange[i][TNIIndex]){
							DQSIRangeTmpMax[ByteIndex] = DQSIRange[i][TNIIndex];
							RxvrefTmpMax[ByteIndex] = RxvrefTmp;
							TNITmpMax[ByteIndex] = TNITmp;
						}
					}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%2x-%2x\r\n",TNIlowbound[RxvrefIndex][ByteIndex],TNIhighbound[RxvrefIndex][ByteIndex]));
			

//					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));	
				}
				for(i=0; i<=(RxvrefEnd-RxvrefBegin)/RxvrefStep; i++) {
								MinTNIlowbound[ByteIndex]=(MinTNIlowbound[ByteIndex]>TNIlowbound[i][ByteIndex])? TNIlowbound[i][ByteIndex] :MinTNIlowbound[ByteIndex]; 
								MaxTNIhighbound[ByteIndex]=(MaxTNIhighbound[ByteIndex]<TNIhighbound[i][ByteIndex])? TNIhighbound[i][ByteIndex] :MaxTNIhighbound[ByteIndex]; 								}	
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte%2x: TNI Range %2x-%2x\r\n",ByteIndex,MinTNIlowbound[ByteIndex],MaxTNIhighbound[ByteIndex]));
				
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "3D Scan Byte:%2x Result:%2x\r\n",ByteIndex ) );
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "3D Scan Byte:%2x Result:%2x\r\n" ) );
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "Select TNI INDEX:%x RXVREF:%x MAX DQSI:%x\r\n",TNITmpMax[ByteIndex], RxvrefTmpMax[ByteIndex],DQSIRangeTmpMax[ByteIndex] ) );
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "\r\n" ) );
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "\r\n" ) );
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "\r\n" ) );
			}

			//set usable TNI and Rxvref for next step
			PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "S20 Rank%02x : ",RankIndex ) );
			for ( ByteIndex=0x0; ByteIndex<ByteMax; ByteIndex++ )
			{
				Rx_Vref_SetVal_ByBit_WholeByte ( PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,RxvrefTmpMax[ByteIndex] );
				if(DramAttr->ConfigData.TNIHighPulse){
					//LGE20180620 for HIGH PULSE
					if (DramAttr->RPREA == RPREA1CLK)
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= MaxTNIhighbound[ByteIndex] - 0x18;				
					else
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting= MaxTNIhighbound[ByteIndex] - 0x20;				
					}	
				else
					//Low Pulse
					DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting=(MaxTNIhighbound[ByteIndex]+MinTNIlowbound[ByteIndex])/2;  // average value
//				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "%04x|%02x(%04x-%04x) ",DramAttr->DramAutoCal[RankIndex][ByteIndex].TNI_Setting,MaxTNIhighbound[ByteIndex]-MinTNIlowbound[ByteIndex],MinTNIlowbound[ByteIndex],MaxTNIhighbound[ByteIndex]) );
				PEI_DEBUG ( ( PeiServices, EFI_D_ERROR, "%02x(%04x-%04x) ",MaxTNIhighbound[ByteIndex]-MinTNIlowbound[ByteIndex],MinTNIlowbound[ByteIndex],MaxTNIhighbound[ByteIndex]) );
			}
		}
	}
	// check wholeT, should setting the same value for a channle for a byte(CHX002 limitation)
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{	
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo]>0) 
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELA,ByteIndex);
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo]>0)		
			TNI_WholeT_Adjust(PeiServices, pPCIPPI, DramAttr,CHANNELB,ByteIndex);
	}
	//setting 
	for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
	{
		Rx_TNI_Set_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
	}	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX 3D scan by DQSi -  end\r\n"));		
}


VOID HW_DQSI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex = 0;
	UINT16     	RxCalNum;
	BOOLEAN		RxResult = TRUE;	
	UINT8		DqsiStep = 0X02;

	UINT32		Default_MPR = 0x000F3355;
	UINT8		DQSIRange[ASIA_MAX_BYTES][ASIA_MAX_BIT][2];
	BOOLEAN		ECC_ENABLE = FALSE;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

#if 0
	//Change MPR Pattern
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, NewPattern, MprNo);
			}

		}
	}
#endif
	PEI_DEBUG((PeiServices, EFI_D_INFO, "DQSI ReadLeveling - start\r\n"));		

	for(RxCalNum = 0; RxCalNum<= 0x03; RxCalNum++)
	{
		RxResult = TRUE;
		Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
		//Do DQSI Read Leveling and save results at dataset
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
				Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

				//by byte dqsicalibration patch stagger mode
#if 0
				for(UINT8 ByteIndex = 0; ByteIndex< ECC_ENABLE ? ASIA_MAX_BYTE S: (ASIA_MAX_BYTES-1); ByteIndex++)
				{
					//caculate MPR pattern base on DQ map
					Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, ECC_ENABLE, READ_LEVELING_CMP_BOTH_EDGE, Default_MPR);
					Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex);
				}
#endif
				DramAttr->DramAutoCal_DQSI[RankIndex].CalResult = Rx_DQSI_ReadLeveling_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, DQSIRange);
				if(DramAttr->DramAutoCal_DQSI[RankIndex].CalResult == FALSE)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR!!! DQSI ReadLeveling Calibration FAIL!!\r\n"));		
					RxResult = FALSE;
					//Rx_DQSI_SetRegister_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSI ReadLeveling Calibration PASS!!\r\n"));		
					//setting 
				if(DramAttr->ConfigData.DQSIByRank == BYRANK_ENABLE)								
					Rx_DQSI_SetRegister_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
				}
				DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQSI, NULL,RankIndex,0x10);				
			}
		}
	if(DramAttr->ConfigData.DQSIByRank == BYRANK_DISABLE){		
		if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf){
			RankIndex=0;
			Rx_DQSI_SetRegister_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);		

			}	
		if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf0){
			RankIndex=4;
			Rx_DQSI_SetRegister_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);		

			}	
		}
		if(RxResult==TRUE)
			break;
	}

	 if(!RxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_DQSI);	

	 }
	PEI_DEBUG((PeiServices, EFI_D_INFO, "DQSI ReadLeveling - end\r\n"));		
}


VOID HW_DQSI_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8		RankIndex = 0;
	UINT16     	RxCalNum;
	BOOLEAN		RxResult = TRUE;	
	UINT8		DqsiStep = 0X02;

	UINT8		DQSIRange[ASIA_MAX_BYTES][ASIA_MAX_BIT][2];
	BOOLEAN		ECC_ENABLE = FALSE;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RX DQSI LCU - start\r\n"));		

	for(RxCalNum = 0; RxCalNum <= 0x03; RxCalNum++)
	{
		RxResult = TRUE;
		Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, RankIndex);
		//Do DQSI Read Leveling and save results at dataset
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				Rx_DQSI_LCU(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, 0xAA);
				Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

				DramAttr->DramAutoCal_DQSI[RankIndex].CalResult = Rx_DQSI_ReadLeveling_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, DQSIRange);
				/*DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQSI, DQSIRange,RankIndex,0x15);*/
				if(DramAttr->DramAutoCal_DQSI[RankIndex].CalResult == FALSE)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSI LCU Calibration FAIL!!\r\n"));		
					RxResult = FALSE;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSI LCU  Calibration PASS!!\r\n"));		
					//setting 
					if(DramAttr->ConfigData.DQSIByRank == BYRANK_ENABLE)								
					Rx_DQSI_SetRegister_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
				}
				DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQSI, NULL,RankIndex,0x10);	
			}
		}
		if(DramAttr->ConfigData.DQSIByRank == BYRANK_DISABLE){		
		
		if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf){
			RankIndex=0;
			Rx_DQSI_SetRegister_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);		

			}	
		if (DramAttr->RankPresent[DramAttr->AttrNo] & 0xf0){
			RankIndex=4;
			Rx_DQSI_SetRegister_byChannel(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);		

			}	
			}
		if(RxResult==TRUE)
			break;
	}
	 if(!RxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_DQSI);	

	 }
	PEI_DEBUG((PeiServices, EFI_D_INFO, "DQSI LCU - end\r\n"));		
}


