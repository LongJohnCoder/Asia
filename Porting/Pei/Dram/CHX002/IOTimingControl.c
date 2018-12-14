//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

////
////
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


EFI_GUID gAsiaIoTimingInfoGuid = { 0xe1c2c2a6, 0x2cd0, 0x4834, { 0xa5, 0x4e, 0x61, 0xae, 0x6c, 0x2e, 0x9f, 0xa7 }};
extern EFI_GUID  gPeiReadOnlyVariable2PpiGuid1;
extern EFI_GUID  gPeiReadOnlyVariablePpiGuid1;






//Binary code To Gray code
UINT8 Binary2Gray(UINT8 Binary)
{
  return ((Binary >> 1) ^ Binary);
}
//Gray code To Binary code
UINT8 Gray2Binary(UINT8 Gray)
{
  UINT8 Binary = Gray;
  UINT8 i;
  for(i = 1; i < 8; i++)
  {
    Binary = Binary ^ (Gray >> i);
  }
  return  Binary;
}




//RX_VREF_INFO ChaRxVrefInfo[ASIA_MAX_RANKS/2][18][255];
//RX_VREF_INFO ChbRxVrefInfo[ASIA_MAX_RANKS/2][18][255];

#define Rank0_ODT				0
#define Rank1_ODT				1
#define Rank2_ODT				2
#define Rank3_ODT				3
#define NA_ODT					0

UINT8 OdtWlvlSelRank[8][5] =
{
//	RankMAP        Rank 0          Rank 1             Rank 2             Rank 3	
  { 0x01,   Rank0_ODT,  Rank1_ODT,    Rank2_ODT,    Rank3_ODT},
  { 0x03,   Rank1_ODT,  Rank0_ODT,    Rank2_ODT,    Rank3_ODT},
  { 0x04,   Rank0_ODT,  Rank1_ODT,    Rank2_ODT,    Rank3_ODT},
  { 0x05,   Rank2_ODT,  Rank1_ODT,    Rank0_ODT,    Rank3_ODT},
  { 0x07,   Rank2_ODT,  Rank2_ODT,    Rank0_ODT,    Rank3_ODT},
  { 0x0c,   Rank0_ODT,  Rank1_ODT,    Rank3_ODT,    Rank2_ODT},
  { 0x0d,   Rank2_ODT,  Rank1_ODT,    Rank0_ODT,    Rank0_ODT},
  { 0x0f,   Rank2_ODT,  Rank3_ODT,    Rank0_ODT,    Rank1_ODT}
};






//BEGIN:Add by RKD 20180508--use for stagger readleveling
UINT8 nibble_map[25][4]=
{
	{0,0,0,0},//0x00
	{0,1,2,3},//0x01
	{0,1,3,2},//0x02
	{0,2,1,3},//0x03
	{0,2,3,1},//0x04
	{0,3,1,2},//0x05
	{0,3,2,1},//0x06
	{1,0,2,3},//0x07
	{1,0,3,2},//0x08
	{1,2,0,3},//0x09
	{1,2,3,0},//0x0A
	{1,3,0,2},//0x0B
	{1,3,2,0},//0x0C
	{2,0,1,3},//0x0D
	{2,0,3,1},//0x0E
	{2,1,0,3},//0x0F
	{2,1,3,0},//0x10
	{2,3,0,1},//0x11
	{2,3,1,0},//0x12
	{3,0,1,2},//0x13
	{3,0,2,1},//0x14
	{3,1,0,2},//0x15
	{3,1,2,0},//0x16
	{3,2,0,1},//0x17
	{3,2,1,0} //0x18
};

VOID DramToConnector_Convert(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 ByteIndex, 
	IN UINT8 ByteValue,
	IN OUT UINT8 *ConvertValue)
{
	//1st step, use byte and spd find the bit map table
	UINT8 config0,config1;
	UINT8 index = 0 ;
	UINT8 shift[8];
	UINT8 Convert_temp = 0;

	(*PeiServices)->SetMem(shift, sizeof(shift), 0);

	if(ByteIndex < 4)
	{
		config0 = DramAttr->SpdData[DramAttr->AttrNo][RankIndex/2].Buffer[ByteIndex*2 + 0x3C];
		config1 = DramAttr->SpdData[DramAttr->AttrNo][RankIndex/2].Buffer[ByteIndex*2 + 0x3D];
	}
	else
	{
		config0 = DramAttr->SpdData[DramAttr->AttrNo][RankIndex/2].Buffer[ByteIndex*2 + 0x3C + 2];
		config1 = DramAttr->SpdData[DramAttr->AttrNo][RankIndex/2].Buffer[ByteIndex*2 + 0x3D + 2];
	}
	//patch ECC byte
	if(ByteIndex == 8)
	{
		config0 = DramAttr->SpdData[DramAttr->AttrNo][RankIndex/2].Buffer[0x44];
		config1 = DramAttr->SpdData[DramAttr->AttrNo][RankIndex/2].Buffer[0x45];
	}


	for(index = 0; index <4; index++)
	{
		if(config0>0x20)
		{
			shift[index] = nibble_map[config0 - 0x20][index]+4; 
		}
		else
		{
			shift[index] = nibble_map[config0][index]; 
		}
	}

	for(index = 0; index <4; index++)
	{
		if(config1>0x20)
		{
			shift[index + 4] = nibble_map[config1 - 0x20][index]+4; 
		}
		else
		{
			shift[index + 4] = nibble_map[config1][index]; 
		}
	}

	for(index =0; index<8; index++)
	{
		if(ByteValue&(1<<index))
			Convert_temp |= 1<<shift[index];
	}

	if(RankIndex%2 != 0) //even rank,need mirror
	{
		for(index =0; index<8; index++)
		{
			if(index%2 == 0)
				*ConvertValue |= (Convert_temp&(1<<index))<<1;
			else
				*ConvertValue |= (Convert_temp&(1<<index))>>1;
		}
	}else
		*ConvertValue = Convert_temp;
}

//END: Add by RKD 20180508--use for stagger readleveling

VOID CalErrorReboot(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8   IOTimingMode)
{

	switch(IOTimingMode){
		case IO_DQSI:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: DQSI ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;
		case IO_TNI:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: TNI ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;
        case IO_RXVREF:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: RXVREF ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;
		case IO_DQSO:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: DQSO ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;
		case IO_DQO:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: DQO ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;
		case IO_TXVREF:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: TXVREF ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;
		case IO_WLVL:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "*   DRAM ERROR: Writeleveling ERROR,RESET NOW   *\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;	
		case IO_2D_ByDQSI:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "* DRAM ERROR: RX 2D by DQSI ERROR,RESET NOW  *\r\n"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "***************************\r\n"));
			break;

	}
		
	//reboot
	AsiaIoWrite8(0xcf9, 0x06);//pci reboot
}


UINT16 CalValueToIndex(UINT16 WholeT, UINT16 Phase)
{
	return WholeT * 0x40 + Phase;
}

VOID IndexToValue(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	UINT16 Index, 
	UINT16 *pWholeT, 
	UINT16 *pPhase, 
	UINT16 Flag)
{
	UINT16 ValueTmp;

	*pWholeT = Index / 0x40;
	
	switch (Flag)
	{
		case IO_TNI: //TNI
		{
			ValueTmp = Index % 0x40;
			ValueTmp = Rx_TNI_Convert_To_Value(PeiServices, DramAttr, RankIndex, ValueTmp);
			*pPhase = ValueTmp;
			break;
		}
		case IO_DQSO: //DQSO
		{
			ValueTmp = Index % 0x40;
			ValueTmp = Tx_DQSO_Convert_To_Value(PeiServices, DramAttr, RankIndex, ValueTmp);
			*pPhase = ValueTmp;
			break;
		}
		case IO_DQO: //DQO
		{
			ValueTmp = Index % 0x40;
			ValueTmp = Tx_DQO_Convert_To_Value(PeiServices, DramAttr, RankIndex, ValueTmp);
			*pPhase = ValueTmp;
			break;
		}
	}
}


UINT16 ValueToIndex(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex, 
	UINT16 WholeT, 
	UINT16 Phase, 
	UINT16 Flag)
{
	UINT16 ValueTmp = 0;

	switch (Flag)
	{
		case IO_TNI: //TNI
		{
			ValueTmp = Rx_TNI_Convert_To_Index(PeiServices, DramAttr, RankIndex, Phase);
			break;
		}
		case IO_DQSO: //DQSO
		{
			ValueTmp = Tx_DQSO_Convert_To_Index(PeiServices, DramAttr, RankIndex, Phase);
			break;
		}
		case IO_DQO: //DQO
		{
			ValueTmp = Tx_DQO_Convert_To_Index(PeiServices, DramAttr, RankIndex, Phase);
			break;
		}
	}

	return WholeT * 0x40 + ValueTmp;
}

VOID TriggerLoadReg(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
	)
{
    UINT64 Address;
	//Trigger Load IO Timing register  for CHX002
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RMSETDONE | D0F3_REG_RMSETDONE_CHB, 0);
    //delay some time
	WaitForMicroSec(PeiServices, 10);

	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RMSETDONE | D0F3_REG_RMSETDONE_CHB, D0F3_REG_RMSETDONE | D0F3_REG_RMSETDONE_CHB);
}

VOID ClearAllRankSize(IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8 Index = 0;
    UINT64 Address;

	for (Index = 0; Index < ASIA_MAX_RANKS; Index++)
	{
	    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + Index*2);
        AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,0xFFF, 0X00); //RX108-RX10F        
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                    D0F3_DRAM_RANK0_ENDING_ADR_37_26 + Index*2);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,0xFFF, 0X00); //RX100-RX107
	}
}

VOID EnableTargetRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo)
{
	UINT8 RankIndex;

	for (RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex++) {
			if(RankIndex == RankNo)
			   SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIndex, RankIndex,TRUE);
			else
			   SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIndex, RankIndex,FALSE);
	}
}

VOID SetTargetRankToFirst256MB(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo)
{
	UINT64 Address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26+RankNo*2);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,0xFFF, 0x04);		
	SetVrMap(PeiServices, pPCIPPI, DramAttr, RankNo, RankNo, TRUE);
}

//disable interlevel
VOID SaveRestoreBARASelect(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
	UINT64 Address;
	if(Save)
	{
		// Ensure RSINGLECH/R2C4RINLVEN/	R2C2RINLVEN/R2C1RINLVEN/R1C4RINLVEN/R1C2RINLVEN =0
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSINGLECH| D0F3_R2C4RINLVEN|D0F3_R2C2RINLVEN|D0F3_R2C1RINLVEN|D0F3_R1C4RINLVEN|D0F3_R1C2RINLVEN, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, *SavedByte);	
	}
}

VOID SaveRestoreREFC(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
#if 0
	UINT64 Address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
	if(Save)
	{
		//save refresh counter value to 1
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_REFC_7_0;
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, 1 << 8); //may need update later
		WaitForMicroSec(PeiServices, 100);	//delay 100us
			
		//disable  refresh counter value  
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, 0); //may need update later
	}
	else
	{
		//restore refresh counter value (enable)
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, *SavedByte);//may need update later
	}
#endif
}


VOID SaveRestoreREFCDQSO(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
#if 1
	UINT64 Address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
	if(Save)
	{
		//save refresh counter value to 1
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_REFC_7_0;
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, 0X61 << 8); //may need update later

		WaitForMicroSec(PeiServices, 100);	//delay 100us
		
		//disable  refresh counter value  
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, 0); //may need update later
	}
	else
	{
		//restore refresh counter value (enable)
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, *SavedByte);//may need update later
	}
#endif
}


VOID SaveRestoreSelfRef(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
    UINT64 Address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BY_RANK_SELF_REFRESH_RELATED_REGS_II_I);
	if(Save){
		//save selfrefresh
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0xFF;
	    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 0xFF, 0);
	}
	else
	{
	    //restore refresh counter value (enable)
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,0xFF, *SavedByte);
	}
}
VOID SaveRestoreOdt(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
	UINT64 Address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
	if(Save){
		////save ODT
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RODTEN;
		//Disable ODT
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, 0);
	}
	else
	{
		//restore refresh counter value (enable)
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, *SavedByte);
	}
}


VOID SaveRestoreNBODTLookup(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte)
{
	UINT64 Address;//RX11E
	UINT16 Temp16 = 0;
	UINT8 SelectRank = 0;
	UINT8 Index = 0;
	UINT16 ODTMask = 0;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_DRAM_ODT_LOOKUP_TABLE_FOR_CHN_B_A);

	switch(RankIndex)	{
	case 0:
		ODTMask = 0x03;
		break;
	case 1:
		ODTMask = 0x0C;
		break;
	case 2:
		ODTMask = 0x30;
		break;
	case 3:
		ODTMask = 0xC0;
		break;
	case 4:		
		ODTMask = 0x0300;
		break;
	case 5:		
		ODTMask = 0x0C00;
		break;
	case 6:		
		ODTMask = 0x3000;
		break;
	case 7:		
		ODTMask = 0xC000;
		break;
	default:
		ODTMask = 0x00;
		break;	

	}
	//Only for Writeleveling
	if(Save)
	{
		//Save ODT lookup table
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		//The setting  rule is so so uncftb        
		if(RankIndex < 4)		
		{
			for(Index = 0;Index < 8;Index++ ){
				if ((DramAttr->RankPresent[DramAttr->AttrNo] & CHA_BITMAP) == OdtWlvlSelRank[Index][0]){	
					SelectRank = OdtWlvlSelRank[Index][RankIndex + 1];
					break;
				}
			}
			Temp16 = (SelectRank << 6) +  (SelectRank << 4) + (SelectRank << 2) + SelectRank;
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 0xFF, Temp16);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, ODTMask, ShiftToMaskBit(ODTMask, RankIndex));
		}
		else
		{
			for(Index = 0;Index < 8;Index++ ){
				if ((DramAttr->RankPresent[DramAttr->AttrNo] & CHB_BITMAP)>>4 == OdtWlvlSelRank[Index][0]){	
					SelectRank = OdtWlvlSelRank[Index][RankIndex - 3];
					break;
				}
			}
			Temp16 = (SelectRank << 6) +  (SelectRank << 4) + (SelectRank << 2) + SelectRank;	
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 0xFF00, ShiftToMaskBit(0xFF00, Temp16));
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, ODTMask, ShiftToMaskBit(ODTMask, RankIndex - 4));
			
		}

		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "LOOKUPTABLE = %0x\r\n", AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
	}
	else
	{
		//Restore ODT lookup table
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 0xFFFF, *SavedByte);
	}
}

VOID SaveRestoreInorder(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte)
{
   UINT64 Address;
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
   if(Save){
       *SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_RINORDER;
       AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RINORDER, D0F3_RINORDER);
   	} 
   else
   	  AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RINORDER, *SavedByte);
}

VOID SaveRestoreOnTheFly(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
	UINT64 Address;
	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);
	 if(Save){
	   *SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_RDMBCOTF;
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMBCOTF, 0); // disable BC
	 } 
	 else
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMBCOTF, *SavedByte);

}

VOID SaveRestorePageMode(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
    UINT64 Address;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	if(Save)
	{
		//save page mode
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress,  Address) & D0F3_RPGEN;
		//Enable page mode
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RPGEN, D0F3_RPGEN);
	}
	else
	{
		//restore page mode setting
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RPGEN, *SavedByte);
	}
}

VOID SaveRestoreBAScramble(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT UINT16	*SavedByte
)
{
	UINT64 Address;//RX11E
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RANK_INTERLEAVE_ADR_SEL_BANK_SCRAMBLE);
	if(Save)
	{
		//save BA scramble
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)& D0F3_RBKSCMB;
		//disable BA scramble
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBKSCMB, 0);
	}
	else
	{
		//restore page mode setting
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBKSCMB, *SavedByte);
	}
}


VOID SaveRestoreBGDelay(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN BOOLEAN	Save,
		IN OUT UINT16	*SavedByte
	)
{
	UINT64 Address;
    //RDIFFBG_DELY_CAL1,RDIFFBG_DELY_CAL0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
								D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING);
			
	if(Save)
	{
		//save
		*SavedByte = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&(D0F3_RDIFFBG_DELY_CAL_CHA_1_0 | D0F3_RDIFFBG_DELY_CAL_CHB_1_0);
		//
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDIFFBG_DELY_CAL_CHA_1_0+D0F3_RDIFFBG_DELY_CAL_CHB_1_0,0x05);  //set 1
	}
	else
	{
		//restore
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIFFBG_DELY_CAL_CHA_1_0+D0F3_RDIFFBG_DELY_CAL_CHB_1_0, *SavedByte);
	}
}



VOID DRAMIOCTL(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8   IOTimingMode,
	IN UINT8   IOSelectionMode,// manul mode(W/R) or calibration mode(R)
	IN BOOLEAN IsWrite,
	IN UINT8   RankIndex,//RankIndex cha:(0->3) chb:(4->7)
	IN UINT8   ByteIndex,
	IN UINT8   BitSelect, //mask!!! 0x01 for bit0, 0x02 for bit1,0x03 for bit0 and bit1 ....
	IN UINT8   IsPos,   //only use  for TX_DQSO RX_DQSI phase select
	IN OUT UINT16  *Value16)
{
	//CHX002 -- code  Add By RKD
	UINT16  WriteMask = 0; // used for maual mode both for write and read
	UINT16  ReadMask = 0; // only used for calibration reuslt
	UINT64  ManualAddress = 0 ,CalReadAddr =0;
	UINT8   BitIndex =0;
	UINT8   OrData = 0;
	UINT64 Address = 0;

	if(RankIndex<4) // Channel A
		CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*ByteIndex);
	else // Channel B
		CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*ByteIndex);

	switch(IOTimingMode){
		case IO_DQSI_PHASE: //DQSI is special one
			if(IsPos == TRUE)
			{
				WriteMask = 0X3F00;
			} else
			{
				WriteMask = 0X003F;
			}
			if(IOSelectionMode == IOCTL_MANUAL)
			{
				for(BitIndex=0;BitIndex<8;BitIndex++)
				{
					if((BitSelect>>BitIndex) & 0x01 )
					{
						ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*(9*16) + ByteIndex*16 + D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_0_CHN_A + BitIndex*2);
						if (IsWrite){
							AsiaPcieModify16(DramAttr->PcieBaseAddress,ManualAddress, WriteMask,ShiftToMaskBit(WriteMask,*Value16));
						}
						else{
							*Value16 = (AsiaPcieRead16(DramAttr->PcieBaseAddress,ManualAddress) & WriteMask)>>(RegisterOffset16bit(WriteMask));
						}
					}
				}
			}
			else//read out calibration result
			{
				//posedge
				if(IsPos == TRUE)
				{
					CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
					AsiaPcieModify16(DramAttr->PcieBaseAddress, CalReadAddr, D0F3_DMIOSEL_BIT_5_0, RegisterOffset16bit(BitSelect)*2 + 0);
                    if(RankIndex < 4)
						CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);
					else
						CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 + ByteIndex*2);
					if(IOSelectionMode == IOCTL_HIGH )
					{
						*Value16 = AsiaPcieRead16(DramAttr->PcieBaseAddress,CalReadAddr)>>6;
					}
					if(IOSelectionMode == IOCTL_LOW )
					{
						*Value16 = AsiaPcieRead16(DramAttr->PcieBaseAddress,CalReadAddr)&0x3F;
					}
				}
				else//negedge
				{
					CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
					AsiaPcieModify16(DramAttr->PcieBaseAddress, CalReadAddr, D0F3_DMIOSEL_BIT_5_0, RegisterOffset16bit(BitSelect)*2 + 1);
					if(RankIndex < 4)
						CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1 + ByteIndex*2);
                    else
						CalReadAddr = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 + ByteIndex*2);
					if(IOSelectionMode == IOCTL_HIGH )
					{
						*Value16 = AsiaPcieRead16(DramAttr->PcieBaseAddress,CalReadAddr)>>6;
					}
					if(IOSelectionMode == IOCTL_LOW )
					{
						*Value16 = AsiaPcieRead16(DramAttr->PcieBaseAddress,CalReadAddr)&0x3F;
					}
				}
			}
			return;//DQSI is special one

		case IO_TNI_PHASE:
			/*if(ByteIndex == 8)*/
				/*ByteIndex++;*/
			WriteMask = 0X3F;

			if(IOSelectionMode == IOCTL_LOW )
				OrData =D0F3_DMIOSEL_TNI_LOW;
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData =D0F3_DMIOSEL_TNI_HIGH;

			ReadMask = 0x3F;

			/*ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*0xA + ByteIndex + D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A);*/
			ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*0xA + ((ByteIndex == 8)?(ByteIndex+1):ByteIndex) + D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A);
			break;
		case IO_TNI_WHOLE_T:
			if(ByteIndex %2 == 0)//mask  0x0F
			{
				WriteMask = 0X0F;
			}
			if(ByteIndex %2 == 1)//mask  0xF0
			{
				WriteMask = 0XF0;
			}

			if(IOSelectionMode == IOCTL_LOW )
				OrData =D0F3_DMIOSEL_TNI_LOW;
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData =D0F3_DMIOSEL_TNI_HIGH;

			ReadMask = 0x3C0;

			ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*6 + ByteIndex/2 + D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A0_A1_A2_A3_CHN_A);
			break; 	
		case IO_DQO_PHASE:
			WriteMask = 0x3F;

			if(IOSelectionMode == IOCTL_LOW )
				OrData =D0F3_DMIOSEL_DQO_LOW;
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData =D0F3_DMIOSEL_DQO_HIGH;

			ReadMask = 0x3F;


			//force TX Rankindex 0(CHA)or 4(CHB)
			if(RankIndex < 4)
				RankIndex = 0;
			else
				RankIndex = 4;

			//DKS-add 20180302 +S
			if(ByteIndex == 8 || ByteIndex == 6)
			{
				ByteIndex++;
			}
			else if (ByteIndex == 7)
			{
				ByteIndex--;
			}
			//DKS-add 20180302 +E
			
			ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, (RankIndex>0?0xA:0) + ByteIndex + D0F3_TX_CLK_PI_PHASE_CTL_A0_A1_CHN_A);
			break; 
		case IO_DQO_WHOLE_T:
			WriteMask = 0X0F;

			if(IOSelectionMode == IOCTL_LOW )
				OrData =D0F3_DMIOSEL_DQO_LOW;
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData =D0F3_DMIOSEL_DQO_HIGH;

			ReadMask = 0x1C0;
			//
			//force TX Rankindex 0(CHA)or 4(CHB)
			if(RankIndex < 4)
				RankIndex = 0;
			else
				RankIndex = 4;

			ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, (RankIndex>0?0xA:0) + ByteIndex + D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A);
			break;      
		case IO_DQSO_PHASE:
			WriteMask = 0x3F;

			if(IOSelectionMode == IOCTL_LOW )
				OrData =D0F3_DMIOSEL_DQSO_LOW;
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData =D0F3_DMIOSEL_DQSO_HIGH;

			ReadMask = 0x3F;
			//force TX Rankindex 0(CHA)or 4(CHB)
			if(RankIndex < 4)
				RankIndex = 0;
			else
				RankIndex = 4;

			//DKS-add 20180302 +S
			if(ByteIndex == 8 || ByteIndex == 6)
			{
				ByteIndex++;
			}
			else if (ByteIndex == 7)
			{
				ByteIndex--;
			}
			//DKS-add 20180302 +E
			
			ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, (RankIndex>0?0xA:0) + ByteIndex + D0F3_TX_CLK_PI_PHASE_CTL_A0_A1_CHN_A_Z1);
			break;
		case IO_DQSO_WHOLE_T:
			WriteMask = 0XF0;

			if(IOSelectionMode == IOCTL_LOW )
				OrData =D0F3_DMIOSEL_DQSO_LOW;
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData =D0F3_DMIOSEL_DQSO_HIGH;

			ReadMask = 0x1C0;
			//force TX Rankindex 0(CHA)or 4(CHB)
			if(RankIndex < 4)
				RankIndex = 0;
			else
				RankIndex = 4;

			ManualAddress = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, (RankIndex>0?0xA:0) + ByteIndex + D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A);
			break; 
		case IO_DQSO_WLVL:		
            if(IOSelectionMode == IOCTL_LOW)
				OrData = D0F3_DMIOSEL_WLVL_LAST_ZERO; 
			else if(IOSelectionMode == IOCTL_HIGH)
				OrData = D0F3_DMIOSEL_WLVL_FIRST_ONE;
			else if(IOSelectionMode == IOCTL_CENTER)
				OrData = D0F3_DMIOSEL_WLVL;
			
			//ReadMask = 0x3F;
			ReadMask = 0x1FF;
			break;
		default:
			break;
	}
	if (IsWrite){
		AsiaPcieModify16(DramAttr->PcieBaseAddress,ManualAddress, WriteMask,ShiftToMaskBit(WriteMask,*Value16));
	}
	else{
		if(IOSelectionMode == IOCTL_MANUAL) //read out manual setting
			*Value16 =(AsiaPcieRead16(DramAttr->PcieBaseAddress,ManualAddress) & WriteMask)>>(RegisterOffset16bit(WriteMask));
		else //read out calibration result
		{
			//RKD-debug
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, ShiftToMaskBit(D0F3_DMIOSEL_4_0,OrData));

			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RankIndex %d ByteIndex %d Register Offset %x  ReadMask %x\r\n",RankIndex,ByteIndex,(UINT32)(RShiftU64(CalReadAddr,32)), ReadMask));	
			*Value16 =(AsiaPcieRead16(DramAttr->PcieBaseAddress,CalReadAddr) & ReadMask)>>(RegisterOffset16bit(ReadMask));
		}
	}
	return;
}

VOID DumpTXRX(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,	
  IN UINT8 IOTimingMode,
  IN UINT16 *Range,
  IN UINT8 RankNo,
  IN UINT8 MarkNo)
{
	UINT16  Value16=0,TmpT=0;
	UINT8   RankIndex = 0, ByteIndex =0, BitIndex =0;

	switch(IOTimingMode)
	{
		case IO_TNI: //calibration result
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI Rank%02X ", RankNo));
			if(DramAttr->DramAutoCal[RankNo][0].CalResult == TRUE) 
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) : "));
			else
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) : "));
			for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].TNI_HIGH;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(upper bdd) "));

			for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].TNI_LOW;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(lower bdd) "));                

			for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].TNI_HIGH - DramAttr->DramAutoCal[RankNo][ByteIndex].TNI_LOW;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(range)\n"));                

			break;          

		case IO_DQSI: //calibration result

			for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES ; ByteIndex++)
			{
				//===========Header Start =================//
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "For DQSI Rank%02X", RankNo));

				if(DramAttr->DramAutoCal_DQSI[RankNo].CalResult == TRUE)
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) "));
				else
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) "));

				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte%02X ", ByteIndex));
				//===========Header End =================//

				//POS -- high/low/range
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "POS : "));
				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(upper bdd) "));

				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(lower bdd) "));

				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH - DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(range) ")); 
				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = (DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH - DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW)/2 + DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));	
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Center)\n")); 		
				//NEG -- high/low/range
				//===========Header Start =================//
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "For DQSI Rank%02X", RankNo));

				if(DramAttr->DramAutoCal_DQSI[RankNo].CalResult == TRUE)
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) "));
				else
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) "));

				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte%02X ", ByteIndex));
				//===========Header End =================//
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "NEG : "));
				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(upper bdd) "));

				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(lower bdd) "));
				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH - DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(range) ")); 
				for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					Value16 = (DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH - DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW)/2 + DramAttr->DramAutoCal_DQSI[RankNo].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));	
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Center)\n")); 					
			}

			break;     

		case IO_DQO: //calibration result
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQO Rank%02X", RankNo));
			if(DramAttr->DramAutoCal[RankNo][0].CalResult == TRUE) 
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) : "));
			else
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) : "));
			for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQO_HIGH;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(upper bdd) "));

			for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQO_LOW;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(lower bdd) "));

			for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				Value16 =DramAttr->DramAutoCal[RankNo][ByteIndex].DQO_HIGH - DramAttr->DramAutoCal[RankNo][ByteIndex].DQO_LOW;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(range)"));

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
			break;     

		case IO_DQSO: //calibration result
			if(MarkNo==0x30)//WLVL
			{
#if 1
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\nS%02x ", 0x31));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSO Rank%02X ",RankNo));				
				if(DramAttr->DramAutoCal[RankNo][0].CalResult == TRUE) 
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) : "));
				else
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) : "));

				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_HIGH;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(upper bdd) "));

				//for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				//{
					//Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_LOW;
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
				//}
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "(lower bdd) "));

				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\nS%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSO Rank%02X ",RankNo));				
				if(DramAttr->DramAutoCal[RankNo][0].CalResult == TRUE) 
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) : "));
				else
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) : "));
				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_Setting;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(wlvl center) "));			
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
#endif 
			}
			else
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\nS%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSO Rank%02X",RankNo));
				if(DramAttr->DramAutoCal[RankNo][0].CalResult == TRUE) 
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) : "));
				else
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) : "));

				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_HIGH;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(upper bdd) "));

				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					Value16 = DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(lower bdd) "));
				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					Value16 =DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_HIGH - DramAttr->DramAutoCal[RankNo][ByteIndex].DQSO_LOW;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(range) "));                 
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
			}

			break;       

			//Show manual setting
		case IO_MANUAL:
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "------------------------------------------\r\n"));
			//CHA
			//TNI
			if(MarkNo==0x52)
			{			
				for(RankIndex = 0; RankIndex<4; RankIndex++)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA TNI Manual VR%x : ", RankIndex));
					for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
					{
						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X", Value16));
						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
					}
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
				}
			}
			else//S53 Show Index value
			{
				for(RankIndex = 0; RankIndex<4; RankIndex++)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA TNI Manual VR%x : ", RankIndex));
					for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
					{
						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						TmpT=Value16;
						DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", TmpT*0x40+Rx_TNI_Convert_To_Index(PeiServices, DramAttr, RankIndex, Value16)));
					}				
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
				}				
			}		
			//DQSI 
			if(MarkNo==0x52)
			{				
				for(RankIndex = 0; RankIndex<ASIA_MAX_RANKS/2; RankIndex++)
				{
					for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
					{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DQSI Manual VR%x Byte%x POS : ", RankIndex , ByteIndex));
						//POS
						for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
						{
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, 1<<BitIndex, POS, &Value16);
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
						}
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));

						PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DQSI Manual VR%x Byte%x NEG : ", RankIndex , ByteIndex));
						//NEG
						for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
						{
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, 1<<BitIndex, NEG, &Value16);
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
						}
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
					}
				}
			}
			//DQO
			if(MarkNo==0x52)
			{				
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DQO Manual : "));
				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X", Value16));
					DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));					
			}
			else//S53 Show Index value 
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DQO Manual : "));
				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					TmpT=Value16;
					DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", TmpT*0x40+Tx_DQO_Convert_To_Index(PeiServices, DramAttr, 0, Value16)));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
			}

            //DQSO
            if(MarkNo==0x52)
            {					
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DQSO Manual : "));
                for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                {
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X", Value16));
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
                }
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
            }
            else
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DQSO Manual : "));
                for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                {
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    TmpT=Value16;
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", TmpT*0x40+Tx_DQSO_Convert_To_Index(PeiServices, DramAttr, 0, Value16)));
                }
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
            }
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));				
            //CHB
            //TNI
            if(MarkNo==0x52)
            {				
                for(RankIndex = 4; RankIndex< ASIA_MAX_RANKS; RankIndex++)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB TNI Manual VR%x : ", RankIndex-4));
                    for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                    {
                        DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X", Value16));
                        DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
                    }
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
                }
            }
            else
            {
                for(RankIndex = 4; RankIndex< ASIA_MAX_RANKS; RankIndex++)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB TNI Manual VR%x : ", RankIndex-4));
                    for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                    {
                        DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                        TmpT=Value16;
                        DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", TmpT*0x40+Rx_TNI_Convert_To_Index(PeiServices, DramAttr, RankIndex, Value16)));
                    }	
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
                }
            }
            // DQSI
            if(MarkNo==0x52)
            {				
                for(RankIndex = 4; RankIndex<ASIA_MAX_RANKS; RankIndex++)
                {
                    for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                    {
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DQSI Manual VR%x Byte%x POS : ", RankIndex-4, ByteIndex));
                        //POS
                        for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
                        {
                            DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, 1<<BitIndex, POS, &Value16);
                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
                        }
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));

                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DQSI Manual VR%x Byte%x NEG : ", RankIndex-4 , ByteIndex));
                        //NEG
                        for (BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
                        {
                            DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, READ, RankIndex, ByteIndex, 1<<BitIndex, NEG, &Value16);
                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", Value16));
                        }
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
                    }
                }
            }
            //DQO
            if(MarkNo==0x52)
            {				
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DQO Manual : "));
                for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                {
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X", Value16));
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
                }
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
            }
            else
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DQO Manual : "));
                for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
                {
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    TmpT=Value16;
                    DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", TmpT*0x40+Tx_DQO_Convert_To_Index(PeiServices, DramAttr, 4, Value16)));
                }
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
            }

			//DQSO
			if(MarkNo==0x52)
			{			
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DQSO Manual : "));
				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X", Value16));
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ", Value16));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
			}
			else
			{			
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "S%02x ", MarkNo));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DQSO Manual : "));
				for (ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
				{
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					TmpT=Value16;
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", TmpT*0x40+Tx_DQSO_Convert_To_Index(PeiServices, DramAttr, 4, Value16)));
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));				
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "------------------------------------------\r\n"));
			break;
			//End case IO_MANUAL

		default:
			break;
	}

}

/*
  *	Purpose: Set or Clear Physical Rank to Virtual Rank mapping
  *	PrIdx: Physical Rank index
  *	VrIdx: Virtual Rank index
  *	Enable: enable / disable VRank
  */
VOID SetVrMap(	
	IN EFI_PEI_SERVICES	**PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI	*pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr,
    IN UINT8		PrIdx,
	IN UINT8		VrIdx,
	IN BOOLEAN      Enable
)
{
    UINT64  Address;
	UINT16	RegIndex = D0F3_PHYSICAL_TO_VIRTUAL_RANK_MAPPING;
	UINT8	Data;

	RegIndex += (UINT16)((PrIdx & 0x06) >> 1);

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
	Data = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);

	//Physical Rank 1, 3, 5, 7, put it at register [7:4]
	if (PrIdx & 0x01){
		//clear bit [7:4]
		Data &= 0x0F;
		Data |= (VrIdx & 0x07) << 4;
		if (Enable)
			Data |= 0x80;
		else
			Data &= ~0x80;
	}
	//Physical Rank 0, 2, 4, 6, put it at register [3:0]
	else {
		//clear bit [3:0]
		Data &= 0xF0;
		Data |= VrIdx & 0x07;
		if (Enable)
			Data |= 0x08;
		else
			Data &= ~0x08;
	}
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
    AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, Data);
	return;
}







/********************************************************************************
 * Dump RxVref And TxVref Finnal Value :
 * 
 * 1. Rx_Vref_SaveAllBit[bitindex] = VrefC(high 4 bit)+vref(low 4 bit).
 * 	  Store all 64bit Rxvref value per Chanel
 * 2. TxVref value will use slection byte value as the finnal setting
 * *****************************************************************************/
VOID DumpRxVrefAndTxVref(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8 Rx_Vref_SaveAllBit[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	
	UINT8 ByteIndex;
	UINT8 RankIndex;
	UINT8 Byte_Sel=0;
	BOOLEAN ECC_ENABLE = FALSE;
	UINT8  BitIndex;
	struct RxVref_Register_Setting Save_RxVref[2*ASIA_MAX_BYTES] ; //store CHA/B RXVREF Setting

	//Save RXVREF Setting
	(*PeiServices)->SetMem(Save_RxVref,sizeof(Save_RxVref), 0);
	SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, TRUE, &Save_RxVref[0]);  // 
	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	//RxVref CHA (Rx_Vref_SaveAllBit is gray value)
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS52 CHA Rx_Vref Byte%02x Manual : ",ByteIndex));
		for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++)
		{
			Rx_Vref_SaveAllBit[ByteIndex][BitIndex] =(UINT8) (((Save_RxVref[ByteIndex].VREFF&((0x0000000F)<<(4*BitIndex)))>>(4*BitIndex) ) | ((Save_RxVref[ByteIndex].VREFC&(0x0F))<< 4));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ",Gray2Binary(Rx_Vref_SaveAllBit[ByteIndex][BitIndex])));
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS52 CHA Rx_Vref Overlap : %x ",DramAttr->CHAOverlap));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS52 CHA Rx_Vref CoarseMode : %x ",DramAttr->CHACoarseMode));
	//RxVref CHB (Rx_Vref_SaveAllBit is gray value)
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS52 CHB Rx_Vref Byte%02x Manual : ",ByteIndex));
		for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++)
		{
			Rx_Vref_SaveAllBit[ByteIndex][BitIndex] =(UINT8) (((Save_RxVref[ASIA_MAX_BYTES+ByteIndex].VREFF&((0x0000000F)<<(4*BitIndex)))>>(4*BitIndex) ) | ((Save_RxVref[ASIA_MAX_BYTES+ByteIndex].VREFC&(0x0F))<< 4));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ",Gray2Binary(Rx_Vref_SaveAllBit[ByteIndex][BitIndex])));
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS52 CHB Rx_Vref Overlap : %x ",DramAttr->CHBOverlap));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS52 CHB Rx_Vref CoarseMode : %x \r\n",DramAttr->CHBCoarseMode));
	//TxVref
	for(RankIndex = 0; RankIndex < 4; RankIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "S52 CHA TxVref Manual VR%x : ", RankIndex));

        if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)) 
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER));
        else
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", 0x0));
        
        for(ByteIndex=Byte_Sel; ByteIndex <ASIA_MAX_BYTES-1; ByteIndex++)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", 0x0));
        }
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
    }

	for(RankIndex = 0; RankIndex < 4; RankIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "S52 CHB TxVref Manual VR%x : ", RankIndex));

        if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << (RankIndex + 4))) 
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", DramAttr->TxVrefInfo[RankIndex + 4].TxVrefCENTER));
        else
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", 0x0));
        
        for(ByteIndex=Byte_Sel; ByteIndex <ASIA_MAX_BYTES-1; ByteIndex++)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", 0x0));
        }
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
    }


	//Dump CHA TxVref
	for(RankIndex = 0; RankIndex < 4; RankIndex++)
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex))
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "S53 CHA TxVref Manual VR%x : ", RankIndex));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "TxVrefIndex = %0x, TxVrefRange = %0x, TxVrefValue = %0x    ",
												DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER, 
												((TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x40) >> 6) + 1, 
												TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x3F));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n")); 
		}
	}

	//Dump CHB TxVref
	for(RankIndex = 0; RankIndex < 4; RankIndex++)
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex))
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "S53 CHB TxVref Manual VR%x : ", RankIndex));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "TxVrefIndex = %0x, TxVrefRange = %0x, TxVrefValue = %0x    ",
												DramAttr->TxVrefInfo[RankIndex + 4].TxVrefCENTER, 
												((TxVrefTable[DramAttr->TxVrefInfo[RankIndex + 4].TxVrefCENTER] & 0x40) >> 6) + 1, 
												TxVrefTable[DramAttr->TxVrefInfo[RankIndex + 4].TxVrefCENTER] & 0x3F));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n")); 
		}
	}
	
}

VOID DumpRxVrefIndex(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN BOOLEAN ECC_ENABLE){

	UINT8 	VrefCHAIndex[ASIA_MAX_BYTES][ASIA_MAX_BIT];	//for S36 Print
	UINT8 	VrefCHBIndex[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	UINT8	ByteIndex = 0;
	UINT8	BitIndex  = 0;

	(*PeiServices)->SetMem(VrefCHAIndex, sizeof(VrefCHAIndex), 0);
 	(*PeiServices)->SetMem(VrefCHBIndex, sizeof(VrefCHBIndex), 0);

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n S36 CHA Rx_Vref Byte%02x SyncIndex : ",ByteIndex));
		for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++)
		{
			VrefCHAIndex[ByteIndex][BitIndex] = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,0,ByteIndex,BitIndex); //RankIndex = 0 indicate CHA.
		}
		if(DramAttr->CHAOverlap & (1<<ByteIndex)){
			for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++){
				VrefCHAIndex[ByteIndex][BitIndex] -= 8;
			}
		}		
		if(DramAttr->CHACoarseMode & (1<<ByteIndex)){
			for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++){
				VrefCHAIndex[ByteIndex][BitIndex] = (VrefCHAIndex[ByteIndex][BitIndex]-8)*2 + 1;
			}
		}
		for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ",VrefCHAIndex[ByteIndex][BitIndex]));
		}
	}
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n S36 CHB Rx_Vref Byte%02x SyncIndex : ",ByteIndex));
		for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++)
		{
			VrefCHBIndex[ByteIndex][BitIndex] = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,4,ByteIndex,BitIndex); //RankIndex = 4 indicate CHB.
		}
		if(DramAttr->CHBOverlap & (1<<ByteIndex)){
			for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++){
				VrefCHBIndex[ByteIndex][BitIndex] -= 8;
			}
		}		
		if(DramAttr->CHBCoarseMode & (1<<ByteIndex)){
			for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++){
				VrefCHBIndex[ByteIndex][BitIndex] = (VrefCHBIndex[ByteIndex][BitIndex]-8)*2 + 1;
			}
		}
		for(BitIndex=0; BitIndex < ASIA_MAX_BIT; BitIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ",VrefCHBIndex[ByteIndex][BitIndex]));
		}
	}

}






BOOLEAN IoTimingRestore(
  IN EFI_PEI_SERVICES **PeiServices,
  #if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr)
{
  EFI_STATUS                       Status;
  BOOLEAN    RestoreDone;
  UINTN         VarSize;
  UINT16 RegIndex = 0;
  UINT16 RegValue = 0;
  UINT16 Index = 0;
  UINT8 RankIndex;
  UINT64 Address = 0;
  UINT8 ByteIndex;
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    EFI_PEI_READ_ONLY_VARIABLE_PPI	  *VarPpi;
#else
   EFI_PEI_READ_ONLY_VARIABLE2_PPI	 *Var2Ppi;
#endif
  IO_TIMING *iotiming; 
  PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin to Restore IOTiming \r\n")); 
  Status = (*PeiServices)->AllocatePool(
         PeiServices,
         sizeof(IO_TIMING),
         &iotiming
       );
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariablePpiGuid1, 0, NULL, (VOID**)&VarPpi); 
  VarSize = sizeof(IO_TIMING); 
  Status  = VarPpi->PeiGetVariable (
            PeiServices,
            NVINFO_IO_VAR_NAME,
            &gAsiaIoTimingInfoGuid,
            NULL,
            &VarSize,
            iotiming
            );
#else
  Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariable2PpiGuid1, 0, NULL, (VOID**)&Var2Ppi);
  VarSize = sizeof(IO_TIMING);
  Status  = Var2Ppi->GetVariable (
		    Var2Ppi,
		    NVINFO_IO_VAR_NAME,
		    &gAsiaIoTimingInfoGuid,
		    NULL,
		    &VarSize,
		    iotiming
		    );
#endif
  
	if(!EFI_ERROR(Status)){
		//RX
		//TNI 0x46C-0x4BA
		for(RegIndex = 0x46C, Index = 0; RegIndex <= 0x4BA; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->TNIVAL[Index];
			AsiaPcieWrite16(0xE0000000,Address,RegValue);
		}
		//DQSI 0x4FC-0x97A
		for(RegIndex = 0x4FC, Index = 0; RegIndex <= 0x97A; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->DQSIVAL[Index];
			AsiaPcieWrite16(0xE0000000, Address,RegValue);
		}
		//RXWholeT 0xA0C-0xA3A
		for(RegIndex = 0xA0C, Index = 0; RegIndex <= 0xA3A; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->RXWholeT[Index];
			AsiaPcieWrite16(0xE0000000, Address,RegValue);
		}
		//RXVREF  0xA98-0xB02 
		for(RegIndex = 0xA98, Index = 0; RegIndex <= 0xB02; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->RxVref[Index];
			AsiaPcieWrite16(0xE0000000, Address,RegValue);
		}
		DramAttr->CHAOverlap = iotiming->CHAOverlap; //for S52 print 
		DramAttr->CHBOverlap = iotiming->CHBOverlap;
		DramAttr->CHACoarseMode = iotiming->CHACoarseMode; //for S52 print 
		DramAttr->CHBCoarseMode = iotiming->CHBCoarseMode;
		Rx_Vref_ClearModeStatus(PeiServices,pPCIPPI,DramAttr); // clear for SIDRAMTbl May SET this bit.
		for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES;ByteIndex++){
			if(iotiming->CHAOverlap&(1<<ByteIndex)){
				Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,TRUE); // 0 indicate CHA.
			}
			if(iotiming->CHACoarseMode&(1<<ByteIndex)){
				Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,TRUE); // 0 indicate CHA.
			}
			if(iotiming->CHBOverlap&(1<<ByteIndex)){
				Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,TRUE); // 4 indicate CHB.
			}
			if(iotiming->CHBCoarseMode&(1<<ByteIndex)){
				Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,TRUE); // 4 indicate CHB.
			}			
		}
		SetVrefRange(PeiServices,pPCIPPI,DramAttr);
		//TX	
		//DQSO Phase 0x438-0x44A
		for(RegIndex = 0x438, Index = 0; RegIndex <= 0x44A; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->DQSOPhase[Index];
			AsiaPcieWrite16(0xE0000000, Address,RegValue);
		}
		//DQO Phase 0x424-0x436
		for(RegIndex = 0x424, Index = 0; RegIndex <= 0x436; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->DQOPhase[Index];
			AsiaPcieWrite16(0xE0000000, Address,RegValue);
		}
		//TXWholeT 0xA3C-0xA4E
		for(RegIndex = 0xA3C, Index = 0; RegIndex <= 0xA4E; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			RegValue = iotiming->TXWholeT[Index];
			AsiaPcieWrite16(0xE0000000, Address,RegValue);
		} 
		//trigger Load Register 		
		TriggerLoadReg(PeiServices, DramAttr);
		#if 1
			//TxVref
			for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
			{
				if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
				{	
					if(!(TxVrefTable[iotiming->TxVref[RankIndex]]&0x40)) 
						SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefTable[iotiming->TxVref[RankIndex]]&0x3F);
					else 
						SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE2, TxVrefTable[iotiming->TxVref[RankIndex]]&0x3F);

					// PEI_DEBUG((PeiServices, EFI_D_ERROR, "S47 Rank %02X TxVref Value is (TxVrefIndex %0x : TxVrefRange %0x : TxVrefValue %0x)<========>%d.%d%%  \n", //DKS -20161221 modify
					// 						RankIndex, 
					// 						iotiming->TxVref[RankIndex], 
					// 						((TxVrefTable[iotiming->TxVref[RankIndex]]&0x40)>>6) + 1, 
					// 						TxVrefTable[iotiming->TxVref[RankIndex]]&0x3F,
					// 						TxVrefTableWholt[iotiming->TxVref[RankIndex]].TxVrefValuePercent / 100,
					// 						TxVrefTableWholt[iotiming->TxVref[RankIndex]].TxVrefValuePercent % 100));
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "S47 Rank %02X TxVrefIndex %0x\r\n",RankIndex,iotiming->TxVref[RankIndex]));  
					DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = iotiming->TxVref[RankIndex];
				}
			}
		#endif
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Restore IOTiming success\r\n"));   
		RestoreDone = TRUE;
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Get IOTiming form Variable Fail\r\n"));
		RestoreDone = FALSE;
	}
	return RestoreDone;
}

//daisy add patch for RX2DSCAN
void SetRxVref(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr)
{
       //UINT8  FreqIdx =0;
       switch (DramAttr->DramFreq)
       {

              case DRAM_FREQ_1600:
              case DRAM_FREQ_2133:
			  case DRAM_FREQ_2400:
			  case DRAM_FREQ_2666:
			  case DRAM_FREQ_3200:
                     //1S1R
                     if(((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
                               (DramAttr->ChARankNumber[DramAttr->AttrNo] == 1))||
                               ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
                               (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1))){
                               Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 0, 0x52,VREF_FINE_MODE); 
                               Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 4, 0x52,VREF_FINE_MODE); 
                             }
                     //2S2R
                     else if(((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
                               (DramAttr->ChARankNumber[DramAttr->AttrNo]== 2))||
                               ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
                              (DramAttr->ChBRankNumber[DramAttr->AttrNo]== 2))){
                              Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 0, 0x62,VREF_FINE_MODE);  
                              Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 4, 0x62,VREF_FINE_MODE); 
                             }

                     //1S2R
                     else if(((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
                               (DramAttr->ChARankNumber[DramAttr->AttrNo] == 2))||
                               ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
                               (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2))){
                              Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 0, 0x52,VREF_FINE_MODE);
                              Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 4, 0x52,VREF_FINE_MODE); 
                             }

                     //2S4R
                     else if(((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
                               (DramAttr->ChARankNumber[DramAttr->AttrNo] == 4))||
                               ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
                               (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 4))){
                              Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 0, 0x72,VREF_FINE_MODE);  
                              Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 4, 0x72,VREF_FINE_MODE);
                            }
          	break;
			default:
					Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 0, 0x52,VREF_FINE_MODE);
					Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, 4, 0x52,VREF_FINE_MODE);
			break;
       }
       
}


VOID SetRRDelay(
  IN EFI_PEI_SERVICES **PeiServices,
  IN DRAM_ATTRIBUTE *DramAttr   
    )
{

    UINT64 Address;
    UINT8 RRankRDelay = 0;
    UINT8 RRankWDelay = 0;
       UINT8 DramCL=0;
       UINT8 DramCWL=0;
       DramCL = DramAttr->CL[DramAttr->AttrNo]  +  9;
       DramCWL = DramAttr->CWL[DramAttr->AttrNo] + 9;
       
      switch(DramAttr->DramFreq){
              case DRAM_FREQ_1600:
                     RRankRDelay = 5;
                     break;
              case DRAM_FREQ_1866:
                     RRankRDelay = 5;
                     break;
              case DRAM_FREQ_2133:
                     RRankRDelay = 5;
                     break;
              case DRAM_FREQ_2400:
                     RRankRDelay = 5;
                     break;
              case DRAM_FREQ_2666:
                     RRankRDelay = 6;
                     break;
			  case DRAM_FREQ_3200:
                     RRankRDelay = 8;
                     break;
              default:
                     RRankRDelay = 5;
                     break;
       }

    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RRANK_DELA_RCS);
    AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RRANK_DELAY_3_0,RRankRDelay<<12); 

       RRankWDelay = DramCL + RRankRDelay - DramCWL;

    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RRANK_DELA_RCS);
    AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RRANK_DELAY_W_3_0,RRankWDelay<<8);

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "RRankRDelay=%d,RRankWDelay=%d\r\n",RRankRDelay, RRankWDelay));

}
VOID SetDdrcomp(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN BOOLEAN RAUTO)
{
	UINT64 	Address=0;
	UINT16  SavedREF = 0;
	UINT8 	ByteIndex=0;	
	if (RAUTO == TRUE)
	{
		if(DramAttr->ConfigData.DDRComp == DDRCOMP_ENABLE)
		{
			//CHA
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DCLKD_DQSI_AUTO_SEL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDCLKADV_AUTO,D0F3_RDCLKADV_AUTO);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RMAADV_AUTO,D0F3_RMAADV_AUTO);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQADV_AUTO,D0F3_RDQADV_AUTO);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQSADV_AUTO,D0F3_RDQSADV_AUTO);
			//CHB
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDCLKBDV_AUTO,D0F3_RDCLKBDV_AUTO);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RMABDV_AUTO,D0F3_RMABDV_AUTO);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQBDV_AUTO,D0F3_RDQBDV_AUTO);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQSBDV_AUTO,D0F3_RDQSBDV_AUTO);
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "DCLK & MA & DQ & DQS = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));
			
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RAUTO,D0F3_RAUTO);	
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "AUTO = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));	

			//*_NS[3:0]/ *_PS[3:0]  set 0
			for(ByteIndex=0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
			{
				//CHA DQ&DQS *_NS[3:0]/ *_PS[3:0]  set 0
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_REG_SETTING_A0_CHN_A + ByteIndex*2);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x0000);	
				//CHB DQ&DQS *_NS[3:0]/ *_PS[3:0]  set 0				
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_REG_SETTING_B0_CHN_B + ByteIndex*2);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x0000);	
			}
			//CHA RMAADV & RDCLKDV set 0
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMD_PAD_CTL_CHN_A_Z2);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x0000);
			//CHB RMAADV & RDCLKDV set 0
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMD_PAD_CTL_CHN_B_Z2);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x0000);
			//CHA&CHB RCSDV set 0
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMD_PAD_CTL_CHN_A_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x0000);
			
			// DumpD0F3(PeiServices,DramAttr);

			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_AUTO_COMP_RELATED_CTL_Z1);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RCOMP_TIME_EN,D0F3_RCOMP_TIME_EN);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RODT_FLAG,D0F3_RODT_FLAG);		
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "COMP_TIME_EN & RODT_FLAG = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));				
			
			//Wait RODTPOK & RODTNOK = 1
			WaitForMicroSec(PeiServices, 15);		
			SaveRestoreREFCDQSO(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREF);	
			while(1)	
			{		
				//Wait refresh cmd		
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RODTPOK & RODTNOK = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));			

				if(AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)&0x30)
				{
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_AUTO_COMP_RELATED_CTL_Z1);
					AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RODT_FLAG,0);	
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "COMP_TIME_EN & RODT_FLAG = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));			
					break;
				}
			}	
			SaveRestoreREFCDQSO(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREF);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "NOTE: DDRCOMP Enable\r\n"));
		}
	}
	else
	{
		if(DramAttr->ConfigData.DDRComp == DDRCOMP_ENABLE)
		{			
			//CHA
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DCLKD_DQSI_AUTO_SEL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDCLKADV_AUTO,0);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RMAADV_AUTO,0);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQADV_AUTO,0);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQSADV_AUTO,0);
			//CHB
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDCLKBDV_AUTO,0);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RMABDV_AUTO,0);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQBDV_AUTO,0);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RDQSBDV_AUTO,0);
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Disable DCLK & MA & DQ & DQS = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));
			
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RAUTO,0);	
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Disable AUTO = %x\r\n",AsiaPcieRead16(DramAttr->PcieBaseAddress,Address)));	

			//*_NS[3:0]/ *_PS[3:0]  set 0
			for(ByteIndex=0; ByteIndex<ASIA_MAX_BYTES ;ByteIndex++)
			{
				//CHA DQ&DQS *_NS[3:0]/ *_PS[3:0]  set 0
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_REG_SETTING_A0_CHN_A + ByteIndex*2);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x8888);	
				//CHB DQ&DQS *_NS[3:0]/ *_PS[3:0]  set 0				
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_REG_SETTING_B0_CHN_B + ByteIndex*2);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x8888);	
			}
			//CHA RMAADV & RDCLKDV set 0
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMD_PAD_CTL_CHN_A_Z2);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x8888);
			//CHB RMAADV & RDCLKDV set 0
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMD_PAD_CTL_CHN_B_Z2);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x8888);
			//CHA&CHB RCSDV set 0
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMD_PAD_CTL_CHN_A_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xffff,0x8888);
			// DumpD0F3(PeiServices,DramAttr);

		}
	}
}

EFI_STATUS IOTimingControl(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	BOOLEAN    RestoreDone = FALSE;
	UINT8 Data;

	if(DramAttr->ConfigData.TNIHighPulse){
		//CHA
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_TNI_SEL_A,D0F3_TNI_SEL_A); 
	    //CHB
	    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK4_CHN_B);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_TNI_SEL_B,D0F3_TNI_SEL_B);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "NOTE: TNI USE High Pulse\r\n"));
	}
	SetDdrcomp(PeiServices,pPCIPPI, DramAttr,TRUE);
        if (DramAttr->ConfigData.SwapByte78){ 
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
			AsiaPcieWrite8(DramAttr->PcieBaseAddress,Address,0xD9); 

        	}	
#ifdef DDR4_800	
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_A0_CHN_A_Z1);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_ODTMODE_2_0_A, 0x00);
#endif

	
	//LGE20180904 Patch 1S1R  Two ODT toggle issue -S
		//CS_n can go to float state when rank_n is not present.
		//RX14A[7:0]
		Data = DramAttr->RankPresent[DramAttr->AttrNo];
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 0xFF00, Data << 8);
		//LGE20180904 Patch 1S1R  Two ODT toggle issue -E
	
	//enable BY RANK
	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RPSTODT);
	 AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RRKSELEN, D0F3_RRKSELEN);
	 
	SetRRDelay(PeiServices, DramAttr);

	if(DramAttr->ConfigData.DramRxTxTimingHardCode == DRAM_RXTX_TIMING_HARDCODE_DISABLE)
	{		
		if(DramAttr->DramFastBoot == DRAM_FAST_BOOT_AUTO)
		{	
			AsiaIoWrite8(0x80, 0x22);
			RestoreDone = IoTimingRestore(PeiServices, pPCIPPI, DramAttr);
		}
		else if(DramAttr->DramFastBoot == DRAM_FAST_BOOT_DISABLE || (!RestoreDone))
		{	
			//RX_SI_SI
			if ((DramAttr->ConfigData.RxIoTimingMethod == RX_SI_SI)||(DramAttr->ConfigData.RxIoTimingMethod == RX_SI_RLVL))
			{
				SI_TNI(PeiServices, pPCIPPI, DramAttr,ReadTimingTbl,ReadTimingTblItems);
			}	
			if ((DramAttr->ConfigData.RxIoTimingMethod == RX_SI_SI)||(DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_SI))
			{
				SI_DQSI(PeiServices, pPCIPPI, DramAttr,ReadTimingTbl,ReadTimingTblItems);
			}

			SetRxVref(PeiServices, pPCIPPI, DramAttr);

			//TNI
			AsiaIoWrite8(0x80, 0x22);
			if(DramAttr->ConfigData.RxIoTimingMethod == RX_3D_SCAN)
			{

				RX_3DScan_By_DQSI(PeiServices, pPCIPPI, DramAttr);
			}
			else if(DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_RLVL)
			{
				RX_Scan_with_SI_Rxvref(PeiServices, pPCIPPI, DramAttr);//RX_2DSCAN
			}
			else if(DramAttr->ConfigData.RxIoTimingMethod == RX_DQSI_READPREAMBLE)
			{
				//CHA
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_TNI_SEL_A,0); 
	    		//CHB
	    		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK4_CHN_B);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_TNI_SEL_B,0);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "NOTE: TNI USE Low Pulse\r\n"));
				Rx_VrefDQSI_PREAMBLE_Cal(PeiServices, pPCIPPI, DramAttr);
				if(DramAttr->ConfigData.TNIHighPulse){
				//CHA
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_TNI_SEL_A,D0F3_TNI_SEL_A); 
	    		//CHB
	    		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK4_CHN_B);
				AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_TNI_SEL_B,D0F3_TNI_SEL_B);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "NOTE: TNI USE High Pulse\r\n"));
				}	

			}

			//RXVERF
			AsiaIoWrite8(0x80, 0x23);
			if((DramAttr->ConfigData.RxVref == RX_VREF_CAL_BY_RANK)&&(DramAttr->ConfigData.RxIoTimingMethod != RX_DQSI_READPREAMBLE))
			{	
				Rx_VrefDQSI_Cal(PeiServices, pPCIPPI, DramAttr);	
				//Rx_VrefDQSI_Cal_New(PeiServices, pPCIPPI, DramAttr);	
			}
			if((DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_SI)||(DramAttr->ConfigData.RxIoTimingMethod == RX_DQSI_READPREAMBLE))
			{	
				HW_TNI(PeiServices, pPCIPPI, DramAttr);
				
			}	
			//DQSI
			AsiaIoWrite8(0x80, 0x24);
			if((DramAttr->ConfigData.RxIoTimingMethod == RX_SI_RLVL)||(DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_RLVL)||(DramAttr->ConfigData.RxIoTimingMethod == RX_3D_SCAN))
			{	
				HW_DQSI(PeiServices, pPCIPPI, DramAttr);

			}	

#if 0
			//TNI ONCEMORE
			AsiaIoWrite8(0x80, 0x25);
			if((DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_RLVL)||(DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_SI)||(DramAttr->ConfigData.RxIoTimingMethod == RX_3D_SCAN))
			{	
			
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX_HW_TNI\r\n"));	
				HW_TNI(PeiServices, pPCIPPI, DramAttr);	
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "End of TNI OnceMore,End of RX\r\n"));	
			}
#endif
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "End of Rx\r\n"));

			//TXVREF_SI or SETUP
            AsiaIoWrite8(0x80, 0x25);
            if(DramAttr->ConfigData.TxVref == TX_VREF_SI || DramAttr->ConfigData.TxVref == TX_VREF_CAL)   
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "SET SI Txvref -S\r\n"));
				Tx_Manual_Vref(PeiServices, pPCIPPI, DramAttr);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "SET SI Txvref -E\r\n"));
			}
			else
			{
				Setup_SetTxVref(PeiServices, pPCIPPI, DramAttr);
			}

			//TX_SI_SI
			if (DramAttr->ConfigData.TxIoTimingMethod == TX_SI_SI)
			{
				SI_DQSO(PeiServices, pPCIPPI, DramAttr,OutputTimingTbl,OutputTimingTblItems);
				SI_DQO(PeiServices, pPCIPPI, DramAttr,OutputTimingTbl,OutputTimingTblItems);			
			}
			//DQSO
			AsiaIoWrite8(0x80, 0x26);
			if(DramAttr->ConfigData.TxIoTimingMethod == TX_WLVL_LCU)
			{
				HW_DQSO_WriteLeveling(PeiServices, pPCIPPI, DramAttr);
				HW_TX_WriteLeveling(PeiServices, pPCIPPI, DramAttr);			
			}
			else if(DramAttr->ConfigData.TxIoTimingMethod == TX_LCU_LCU)
			{
				HW_DQSO_LCU_2D(PeiServices, pPCIPPI, DramAttr);
				HW_DQSO_LCU(PeiServices, pPCIPPI, DramAttr);

			}

			//TXVREF
			AsiaIoWrite8(0x80, 0x27);
			if(DramAttr->ConfigData.TxVref == TX_VREF_CAL)
			{		
				Tx_VrefDQO_Cal(PeiServices, pPCIPPI, DramAttr);
			}

			//DQO
			AsiaIoWrite8(0x80, 0x28);		
			if((DramAttr->ConfigData.TxIoTimingMethod == TX_WLVL_LCU)||(DramAttr->ConfigData.TxIoTimingMethod == TX_LCU_LCU))
			{			
				HW_DQO_LCU(PeiServices,  pPCIPPI, DramAttr); 		
			}	
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "End of Tx\r\n"));

            
            if((DramAttr->ConfigData.RxIoTimingMethod == RX_RLVL_RLVL)||(DramAttr->ConfigData.RxIoTimingMethod == RX_3D_SCAN))
            {
                HW_TNI_LCU(PeiServices, pPCIPPI, DramAttr);
                HW_DQSI_LCU(PeiServices,  pPCIPPI, DramAttr); 
            }
            //HW_DQSO_LCU(PeiServices, pPCIPPI, DramAttr);
            //HW_DQO_LCU(PeiServices,  pPCIPPI, DramAttr);
            
        }
    }	
    else if(DramAttr->ConfigData.DramRxTxTimingHardCode == DRAM_RXTX_TIMING_HARDCODE_AUTO)
    {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "Beginning IO HARDCODE\r\n"));
        Setting_Timing_Value_TxRx(PeiServices, pPCIPPI, DramAttr,TX_Value_Tbl,TX_Value_Tbl_Items);	//Hardcode DQSO/DQO/TxVref
        Setting_Timing_Value_TxRx(PeiServices, pPCIPPI, DramAttr,Rx_TNI_Value_Tbl,Rx_TNI_Value_Tbl_Items);	//Hardcode TNI
        Setting_DQSI_Value_Rx(PeiServices, pPCIPPI, DramAttr);	//Hardcode DQSI
        Setting_RxVref_Value_Rx(PeiServices, pPCIPPI, DramAttr);	//HardCode RxVref
    }
    
    DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_MANUAL, NULL, 0,0x52);
    DumpRxVrefAndTxVref(PeiServices, pPCIPPI, DramAttr);	
    DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_MANUAL, NULL, 0,0x53);
	SetDdrcomp(PeiServices,pPCIPPI, DramAttr,FALSE);

	TriggerLoadReg(PeiServices, DramAttr);


	//Power_On_Off (PeiServices);

	return EFI_SUCCESS;

}

