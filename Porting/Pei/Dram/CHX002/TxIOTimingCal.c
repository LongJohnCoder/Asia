//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


//#include "TxIOTimingCal.h"
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


// DQO Calibrtion Related
VOID TX_DQO_ClearDataset(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
	)
{
	UINT8  ByteIndex;
    UINT8 RankIndex;
	
	for(RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex ++)
	{
		for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++) // clear all
		{
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW = 0 ;
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH = 0 ;

			DramAttr->DramAutoCal[RankIndex][ByteIndex].CalResult= FALSE;
		}
	}
}


UINT16 Tx_DQO_Convert_To_Value(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16)
{
	UINT64 Address = 0x00;
	UINT8 Rtim_flag = 0; 
	UINT16 Ph_dclock = 0;
	UINT16 Rtxds2dqph = 0;

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

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
	Rtxds2dqph = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

	return (Value16 +(Rtim_flag*8) + Ph_dclock + Rtxds2dqph)&0x3F ;
}


UINT16 Tx_DQO_Convert_To_Index(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16)
{
	UINT64 Address = 0x00;
	UINT8 Rtim_flag = 0; 
	UINT16 Ph_dclock = 0;
	UINT16 Rtxds2dqph = 0;
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

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
	Rtxds2dqph = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

	ValueTmp = ((Rtim_flag*8) + Ph_dclock + Rtxds2dqph)&0x3F;

	return  (Value16+(0x40 - ValueTmp))%0x40;

}

VOID Tx_DQO_LCU_SaveDataSet(
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
	UINT8 ByteIndex;
	UINT8 ByteBegin = 0;
	UINT8 ByteEnd = 0;
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
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "===BEG:Debug Message for DQO  SaveDataSet=== \r\n\n"));	
	//HIGH Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH = Value16*0x40; // convert wholeT to phase

		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH += Value16; // convert wholeT to phase

		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d DQO_HIGH = %d P \r\n",RankIndex, ByteIndex,DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH));	
	}
	//LOW Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW = Value16*0x40; // convert wholeT to phase

		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW += Value16; // convert wholeT to phase

		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d DQO_LOW = %d P \r\n",RankIndex, ByteIndex,DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW));	
	}
	//RKD-debug only
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "===END:Debug Message for DQO SaveDataSet=== \r\n\n"));	
}


BOOLEAN Tx_DQO_LCU_CheckRange(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,	
		IN BOOLEAN ECC_ENABLE,
		OUT UINT16 *DQORange)
{
	BOOLEAN Flag = TRUE;
	UINT8  ByteIndex;
	UINT16 DQO_LOW;
	UINT16 DQO_HIGH;

	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		DQO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW;
		DQO_HIGH =DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH;

		if(DQO_LOW > DQO_HIGH)
		{
			Flag = FALSE;
			DQORange[ByteIndex] = 0;
			//break;
		}
		else{
			if(DQO_HIGH - DQO_LOW < DQO_VREF_THRESHOLD)
			{
				Flag = FALSE;
				DQORange[ByteIndex] = 0;
				//break;
			}
			else
			{
				DQORange[ByteIndex] = DQO_HIGH - DQO_LOW;
			}
		}
		ByteIndex+=1;
	}
	return Flag;
}

BOOLEAN TX_DQO_LCU_SetRegister_CHA(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN BOOLEAN ECC_ENABLE)
{

	UINT8 ByteIndex = 0;
	UINT8 RankIndex = 0;

	UINT16 DQO_infS=0, DQO_supS=0xFFFF;	
	UINT16 DQO_LOW;
	UINT16 DQO_HIGH;
	UINT16 Value16;
	UINT16 DQSOIndex;
	UINT16 DQSOWholeT;
	UINT16 DQSOPhase;
	UINT16 DiffIndex;
	UINT8 CheckReult = TRUE;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\r\r=========CHA DQO Seting byChannel=========\r\n"));		
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		DQO_infS=0;
		DQO_supS=0xFFFF;	
		for(RankIndex = 0; RankIndex < 4; RankIndex++){
			if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){
				DQO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW;
				DQO_HIGH =DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH;  
				if(DQO_supS > DQO_HIGH)
					DQO_supS = DQO_HIGH;
				if(DQO_infS < DQO_LOW)
					DQO_infS = DQO_LOW;
			} 
		}
		DQO_infS += DQO_supS;
		DQO_infS >>= 1;

		//set DQO WHOLET
		//check DQSO WHOLET
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOPhase);
		DQSOIndex = ValueToIndex(PeiServices, DramAttr, 0, DQSOWholeT, DQSOPhase, IO_DQSO);
		DiffIndex = DQO_infS > DQSOIndex? DQO_infS-DQSOIndex : DQSOIndex-DQO_infS;

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte%0x:DQSOIndex %0x,DQOIndex %0x\r\n",ByteIndex,DQSOIndex, DQO_infS));
		if(DiffIndex >= 0x10){
			CheckReult = FALSE;
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "****ERROR, Byte%0x DQSO-DQO ERROR,DiffIndex=%0x****\r\n",ByteIndex, DiffIndex));
			if(DiffIndex >= 0x30){
			if (DQO_infS > DQSOIndex){
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
				DQSOWholeT+=1;
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
			}else{
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
				DQSOWholeT-=1;
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
				}
			}

			
		}



		
		Value16 = DQO_infS / 0x40; 
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		PEI_DEBUG((PeiServices, EFI_D_WARN, "RKD-DEBUG:CHA,Byte%d, DQO WholeT:%d  ",ByteIndex,Value16));		
		//set DQO Phase
		Value16 = DQO_infS % 0x40; 
		Value16= Tx_DQO_Convert_To_Value(PeiServices, DramAttr,0,Value16);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		PEI_DEBUG((PeiServices, EFI_D_WARN, "PHASE:0x%x\r\n",Value16));		
		ByteIndex++;
	}
	PEI_DEBUG((PeiServices, EFI_D_WARN, "=========END:DQO Seting byChannel=========\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
	return CheckReult;
}

BOOLEAN TX_DQO_LCU_SetRegister_CHB(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN BOOLEAN ECC_ENABLE)
{

	//add by RKD 20161009
	UINT8 ByteIndex = 0;
	UINT8 RankIndex = 0;
	UINT16 DQO_infS=0, DQO_supS=0xFFFF;	
	UINT16 DQO_LOW;
	UINT16 DQO_HIGH;
	UINT16 Value16;
	UINT16 DQSOIndex;
	UINT16 DQSOWholeT;
	UINT16 DQSOPhase;
	UINT16 DiffIndex;
	UINT8 CheckReult = TRUE;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\r\r=========CHB DQO Seting byChannel=========\r\n"));	
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		DQO_infS=0;
		DQO_supS=0xFFFF;	
		for(RankIndex = 4; RankIndex < ASIA_MAX_RANKS; RankIndex++){
			if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){
				//Value2Index(UINT16 IoTiming, UINT8 Invert)		
				DQO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW;
				DQO_HIGH = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH; 
				if(DQO_supS > DQO_HIGH)
					DQO_supS = DQO_HIGH;
				if(DQO_infS < DQO_LOW)
					DQO_infS = DQO_LOW;
			} 
		}

		DQO_infS += DQO_supS;
		DQO_infS >>= 1;

		//set DQO WHOLET
		
		//check DQSO WHOLET
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOPhase);
		DQSOIndex = ValueToIndex(PeiServices, DramAttr, 4, DQSOWholeT, DQSOPhase, IO_DQSO);
		DiffIndex = DQO_infS > DQSOIndex? DQO_infS-DQSOIndex : DQSOIndex-DQO_infS;
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte%0x: DQSOIndex %0x,DQOIndex %0x\r\n",ByteIndex,DQSOIndex, DQO_infS));
		if(DiffIndex >= 0x10){
			CheckReult = FALSE;
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "****ERROR, Byte%0x DQSO-DQO ERROR,DiffIndex=%0x****\r\n",ByteIndex, DiffIndex));
			if(DiffIndex >= 0x30){
			if (DQO_infS > DQSOIndex){
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
				DQSOWholeT+=1;
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
			}else{
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, READ, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
				DQSOWholeT-=1;
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSOWholeT);
				}
			}
		}
		
		Value16 = DQO_infS / 0x40 ;
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		//Set DQO PHASE
		Value16 = DQO_infS % 0x40; 
		Value16= Tx_DQO_Convert_To_Value(PeiServices, DramAttr,4,Value16);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		ByteIndex++;
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);

	return CheckReult;
}

VOID Tx_DQO_SetWholet(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 *WHOLE_T)
{
	UINT8 ByteIndex = 0;
	UINT8 *Value8 = WHOLE_T;
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, (UINT16 *)&Value8[ByteIndex]);
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID Tx_DQO_SetPhase(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 *PHASE)
{
	UINT8 ByteIndex = 0;
	UINT8 *Value8 = PHASE;
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, (UINT16 *)&Value8[ByteIndex]);
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID Tx_DQO_LCU_Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 DqoStep)
{
	UINT16 PageMode = 0, Inorder = 0;
	UINT64 Address;
	UINT16 Temp16;
	UINT16  SavedREFC = 0;
	UINT16 SaveBGDelay = 0;
	//BOOLEAN SHOWLOG = TRUE;

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
    //set bankgroup delay = 01
	SaveRestoreBGDelay(PeiServices, pPCIPPI, DramAttr, TRUE, &SaveBGDelay);

	//1)	Set RERRSCREN to 0, ECC 1 bit correctable error will not generate a write to bus
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);

	//2)	Set REFC[7:0] to 0, disabling auto refresh
	SaveRestoreREFCDQSO(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);

	//3)	Set RDMTSA[31:3] ('h00) and RTSA_STP[18:3] ('h10) for calibration address
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//4)	Set RSRW_LENGTH[31:0] for the scan times of every pointer  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x10);

	//5)set RLCUBSTLENGTH[31:0] to 8 for burst length of every scan - use default  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x40);

	//6)	Set RPGEN to 1, enabling multi-page mode
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);
	
	//7)	Set RDMLCUEN to 1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMLCUEN, D0F3_RDMLCUEN);

	//8)	Set RINORDER to 1
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);

	//9)	Set RDWADVOS[2:0]_BEG & RDWADVOS[2:0]_END for the DQSO whole T scan range begin = 1, end = 0x07
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDWADVOS_2_0_BEG, ShiftToMaskBit(D0F3_RDWADVOS_2_0_BEG,1));
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDWADVOS_2_0_END, ShiftToMaskBit(D0F3_RDWADVOS_2_0_END,7));

	//10)Set RDQO_STEP for DQO scan step
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQO_STEP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQO_STEP_6_0, ShiftToMaskBit(D0F3_RDQO_STEP_6_0,DqoStep));

	//11)Set RSCAN_END for scan end pointer 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqoStep)*DqoStep));

	//12)Set RADDRLOOPEN to 0 or 1, selecting the desired address change mode -- as IRS use default
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RADDRLOOPEN, D0F3_RADDRLOOPEN);

	//13)	Set RTIMCHKSEL to 0 or 1 based on the required timing check mode 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);

	//14)	Set RDQCAL to 1 for calibration mode 
	if(RankIndex < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL, D0F3_RDQCAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL_CHB, D0F3_RDQCAL_CHB);
	}

	//15)	Trigger reg_RSCNTXCLKD_CHA to active DRAMCA TX DCLKD LCU
	//16)	Wait for reg_ RSCNTXCLKD_CHA being cleared by HW
	if(RankIndex < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNTXCLKD_CHA, D0F3_REG_RSCNTXCLKD_CHA);
		//delay some time
		WaitForMicroSec(PeiServices, 500);	//delay 500us
		//waiting for LCU completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNTXCLKD_CHA)!= 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNTXCLKD_CHB, D0F3_REG_RSCNTXCLKD_CHB);
		//delay some time
		WaitForMicroSec(PeiServices, 500);	//delay 500us
		//waiting for LCU completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNTXCLKD_CHB)!= 0);
	}
	//17)	Set RDQCAL to 0 for manual setting 
	if(RankIndex < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL_CHB, 0);
	}
	//Set RDMLCUEN = 0 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMLCUEN, 0);
	//restore page mode
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	//restore inorder mode 
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, FALSE, &Inorder);
	//restore REFC
	SaveRestoreREFCDQSO(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//restore BGdelay
	SaveRestoreBGDelay(PeiServices, pPCIPPI, DramAttr, FALSE, &SaveBGDelay);


#if 0
	if(RankIndex < 4){
		//Read  CHA  LOW Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQO_LOW);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHA DQO LOW BOUND\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));

		{
			//RX33A-AE4  
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA Byte:%d, RX%x= %04x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i, AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
		//Read  CHA   HIGH  Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQO_HIGH);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHA DQO HIGH BOUND\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAD3-AE4  
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA Byte:%d, RX%x= %04x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
	}
	else{
		//Read  CHB  LOW Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQO_LOW);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHB DQO LOW BOUND\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB Byte:%d, RX%x= %02x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
		//Read  CHB  HIGH   Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQO_HIGH);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHB DQO HIGH BOUND\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB Byte:%d, RX%x= %02x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
	}
	
	//read perbit result
	if(SHOWLOG)
	{
		UINT8 DMIOSEL_BIT; 
		UINT16 HIGH_BOUDN,LOW_BOUDN;
		/*UINT16 DQSI_CENTER = 0;*/
		UINT8 ByteIndex =0;
		//ECC byte
		for(ByteIndex = 0; ByteIndex <ASIA_MAX_BYTES ;ByteIndex++)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR,"TX DQ Perbit log ByteIndex = %d\n",ByteIndex));
			//PEI_DEBUG((PeiServices, EFI_D_ERROR,"           [low]   [high]\n"));
			for(DMIOSEL_BIT = 0X00; DMIOSEL_BIT < ASIA_MAX_BIT; DMIOSEL_BIT++){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "A%d Bit %d:",ByteIndex,DMIOSEL_BIT));

				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 0 + 0x18);

				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, ((RankIndex<4)?D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1:D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 )+ ByteIndex*2);
				HIGH_BOUDN = AsiaPcieRead16(DramAttr->PcieBaseAddress,Address);

				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SW_REQ_NUM);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_BIT_5_0, DMIOSEL_BIT*2 + 1 + 0x18);

				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, ((RankIndex<4)?D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1:D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1 )+ ByteIndex*2);
				LOW_BOUDN = AsiaPcieRead16(DramAttr->PcieBaseAddress,Address);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%02X -- %02X] \n ", LOW_BOUDN, HIGH_BOUDN));
			}
		}
	}
	
#endif

	
}

// DQSO Calibrtion Related
VOID TX_DQSO_ClearDataset(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8  ByteIndex;
	UINT8 RankIndex;

	for(RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex ++)
	{
		for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++) // clear all
		{
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW = 0 ;
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH = 0 ;

			DramAttr->DramAutoCal[RankIndex][ByteIndex].CalResult= FALSE;
		}
	}
}

UINT16 Tx_DQSO_Convert_To_Value(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16)
{
	UINT64 Address = 0x00;
	UINT8 Rtim_flag = 0; 
	UINT16 Ph_dclock = 0;
	UINT16 Rtxds2dqph = 0;

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

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
	Rtxds2dqph = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

	return (Value16 + (Rtim_flag*8) + 0x10 + Ph_dclock)&0x3F ;
}


UINT16 Tx_DQSO_Convert_To_Index(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16)
{
	UINT64 Address = 0x00;
	UINT8 Rtim_flag = 0; 
	UINT16 Ph_dclock = 0;
	UINT16 Rtxds2dqph = 0;
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

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
	Rtxds2dqph = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

	ValueTmp = ((Rtim_flag*8) + 0x10 + Ph_dclock )&0x3F;

	return  (Value16+(0x40 - ValueTmp))%0x40;

}

VOID Tx_DQSO_LCU_SaveDataSet(
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
	UINT8  ByteIndex;
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
		
	//HIGH Bound
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH = Value16*0x40; // convert wholeT to phase

		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		/*Value16= Tx_DQSO_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);*/
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH += Value16; //add phase 
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d DQSO_HIGH = %d P \r\n",RankIndex, ByteIndex,DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH));	
	}

	
	//LOW Bound 
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW = Value16*0x40; // convert wholeT to phase

		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		/*Value16= Tx_DQSO_Convert_To_Value(PeiServices, DramAttr,RankIndex,Value16);*/
		DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW += Value16; //add phase 
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%d Byte%d DQSO_LOW = %d P \r\n",RankIndex, ByteIndex,DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW));	
	}

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "===END:Debug Message for DQSO SaveDataSet=== \r\n\n"));	
}

BOOLEAN Tx_DQSO_LCU_CheckRange(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,	
		IN BOOLEAN ECC_ENABLE,
		OUT UINT16 *DQSORange)
{
	BOOLEAN Flag = TRUE;
	UINT8   ByteIndex;
	UINT16  DQSO_LOW;
	UINT16  DQSO_HIGH;

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n\r\n===BEG:Debug Message for DQSO CheckRange=== \n"));	
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		DQSO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;
		DQSO_HIGH =DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH;
			

		if(DQSO_LOW >= DQSO_HIGH)
		{
			Flag = FALSE;
			DQSORange[ByteIndex] = 0;
		}
		else{
			if(DQSO_HIGH - DQSO_LOW < DQSO_THRESHOLD)
			{
				Flag = FALSE;
				DQSORange[ByteIndex] = 0;
			}
			else
			{
				DQSORange[ByteIndex] = DQSO_HIGH - DQSO_LOW;
			}
		}

		ByteIndex+=1;
	}
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "===END:Debug Message for DQSO CheckRange=== \r\n\r\\n"));	
	return Flag;	
}

VOID TX_DQSO_LCU_SetRegister_CHA(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN BOOLEAN ECC_ENABLE)
{

	//add by RKD 20151009
	UINT8 ByteIndex = 0;
	UINT8 RankIndex = 0;

	UINT16 DQSO_infS=0, DQSO_supS=0xFFFF;	
	UINT16 DQSO_LOW;
	UINT16 DQSO_HIGH;

	UINT16 Value16;

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\r\r=========BEG:DQSO Seting byChannel=========\r\n"));		
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		DQSO_infS=0;
		DQSO_supS=0xFFFF;	
		for(RankIndex = 0; RankIndex < 4; RankIndex++){
			if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){

				DQSO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;
				DQSO_HIGH =DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH;  

				if(DQSO_supS > DQSO_HIGH)
					DQSO_supS = DQSO_HIGH;

				if(DQSO_infS < DQSO_LOW)
					DQSO_infS = DQSO_LOW;
			} 
		}
		DQSO_infS += DQSO_supS;
		DQSO_infS >>= 1;

		//set DQSO WHOLET
		Value16 = DQSO_infS / 0x40 ; 
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:CHA,Byte%d, DQSO WholeT:%d  ",ByteIndex,Value16));		
		//set DQSO Phase
		Value16 = DQSO_infS % 0x40 ; 
		Value16= Tx_DQSO_Convert_To_Value(PeiServices, DramAttr,0,Value16);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "PHASE:0x%x\r\n",Value16));		
		ByteIndex++;
	}
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "=========END:DQSO Seting byChannel=========\r\n\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID TX_DQSO_LCU_SetRegister_CHB(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN BOOLEAN ECC_ENABLE)
{

	//add by RKD 20161009
	UINT8 ByteIndex = 0;
	UINT8 RankIndex = 0;
	UINT16 DQSO_infS=0, DQSO_supS=0xFFFF;	
	UINT16 DQSO_LOW;
	UINT16 DQSO_HIGH;
	UINT16 Value16;

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\r\r=========BEG:DQSO Seting byChannel=========\r\n"));		
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);) 
	{
		DQSO_infS=0;
		DQSO_supS=0xFFFF;	
		for(RankIndex = 4; RankIndex < ASIA_MAX_RANKS; RankIndex++){
			if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){
				//Value2Index(UINT16 IoTiming, UINT8 Invert)		
				DQSO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;
				DQSO_HIGH = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH; 
				if(DQSO_supS > DQSO_HIGH)
					DQSO_supS = DQSO_HIGH;
				if(DQSO_infS < DQSO_LOW)
					DQSO_infS = DQSO_LOW;
			} 
		}

		DQSO_infS += DQSO_supS;
		DQSO_infS >>= 1;

		//set DQSO WHOLET
		Value16 = DQSO_infS / 0x40 ; 
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "RKD-DEBUG:CHB,Byte%d, DQSO WholeT:%d  ",ByteIndex,Value16));		

		//Set DQSO PHASE
		Value16 = DQSO_infS % 0x40 ; 
		Value16= Tx_DQSO_Convert_To_Value(PeiServices, DramAttr,4,Value16);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "PHASE:0x%x\r\n",Value16));		

		ByteIndex++;
	}
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "=========END:DQSO Seting byChannel=========\r\n"));		
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID Tx_DQSO_SetWholet(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT16 WHOLET)
{
	UINT8 ByteIndex = 0;
	UINT16 Value16;

	Value16 = WHOLET;
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES ; ByteIndex++)
	{
		//set DQSO WholeT
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);

}

VOID Tx_DQSO_SetPhase(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 *Phase)
{
	UINT8 ByteIndex = 0;
	UINT8 *Value8 = Phase;

	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		//set DQSO Phase
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, (UINT16 *)&Value8[ByteIndex]);
	}
	//Important:  trigger Load Register 		
	TriggerLoadReg(PeiServices, DramAttr);
}




VOID Tx_DQSO_LCU_Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsoStep)
{
	UINT16 PageMode = 0, Inorder = 0;
	UINT64 Address;	
	UINT16  Temp16;
	UINT16  SavedREFC = 0;
	UINT16 SaveBGDelay = 0;

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~256MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);

	//set bankgroup delay = 01
	SaveRestoreBGDelay(PeiServices, pPCIPPI, DramAttr, TRUE, &SaveBGDelay);
	
	//1)	Set RERRSCREN to 0, ECC 1 bit correctable error will not generate a write to bus  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN,0);

	//2)	Set REFC[7:0] to 0, disabling auto refresh
	SaveRestoreREFCDQSO(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);

	//3)	Set RDMTSA[31:3] ('h00) and RTSA_STP[18:3] ('h10) for calibration address 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_IO_CALIBRATION);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,0x1FFFFFFF, 0);

	//set address in a 8QW (burst) Set RTSA_STP   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x10);

	//set address inter 2 8QW (burst) Set RTSA_STP_OS ????  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);//byron advise

	//4)	Set RSRW_LENGTH[31:0] for the scan times of every pointer 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, 0x10);//default0x01

	//5) set RLCUBSTLENGTH[31:0] to 8 for burst length of every scan - use default  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_LCU_INITIAL_DATA_PATTERN);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RLCUBSTLENGTH_31_0, 0x40);

	//6)	Set RPGEN to 1, enabling multi-page mode
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &PageMode);
	
	//7)	Set RDMLCUEN to 1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMLCUEN, D0F3_RDMLCUEN);

	//8)	Set RINORDER to 1
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, TRUE, &Inorder);

	//9)	Set RDWADVOS[2:0]_BEG & RDWADVOS[2:0]_END for the DQSO whole T scan range. begin = 1, end = 0x07 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDWADVOS_2_0_BEG, ShiftToMaskBit(D0F3_RDWADVOS_2_0_BEG,1));
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDWADVOS_2_0_END, ShiftToMaskBit(D0F3_RDWADVOS_2_0_END,7));
	AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);

	//10)Set for DQSO scan step. step to a value = 0x01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQSO_STEP_DQSI_STEP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSO_STEP_6_0, ShiftToMaskBit(D0F3_RDQSO_STEP_6_0,DqsoStep));

	//11)Set RSCAN_END for scan end pointer 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqsoStep)*DqsoStep));

	//12)Set RADDRLOOPEN to 0 or 1, selecting the desired address change mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RADDRLOOPEN, D0F3_RADDRLOOPEN);

	//13)set RTIMCHKSEL  to 0 or 1, based on the required timing check mode  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);

	//14)Set RDQCAL and RDQSCAL to 1 for calibration mode  
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL|D0F3_RDQSCAL, D0F3_RDQCAL|D0F3_RDQSCAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL_CHB|D0F3_RDQSCAL_CHB, D0F3_RDQCAL_CHB|D0F3_RDQSCAL_CHB);
	}
	//15)	Set RTXDS2DQPH[5:0] to 20h for T/4 phase delay between DQs and DQ-use defaut value
	//Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
	//AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTXDS2DQPH_5_0, 0x20);
	
	//16)	Trigger reg_RSCNTXCLKS_CHA to active DRAMCA TX DCLKS LCU function
	//17)	Wait for reg_RSCNTXCLKS_CHA being cleared by HW
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNTXCLKS_CHA, D0F3_REG_RSCNTXCLKS_CHA);
		//delay some time
			WaitForMicroSec(PeiServices, 500);	//delay 500us
		//waiting for LCU completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNTXCLKS_CHA)!= 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RSCNTXCLKS_CHB, D0F3_REG_RSCNTXCLKS_CHB);
		//delay some time
			WaitForMicroSec(PeiServices, 500);	//delay 500us
		//waiting for LCU completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RSCNTXCLKS_CHB)!= 0);
	}
	//18)	Set RDQCAL and RDQSCAL to 0 for manual setting 
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL|D0F3_RDQSCAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQCAL_CHB|D0F3_RDQSCAL_CHB, 0);
	}
	//Set RDMLCUEN = 0 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMLCUEN, 0);
	//restore page mode
	SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, FALSE, &PageMode);
	//restore inorder mode 
	SaveRestoreInorder(PeiServices, pPCIPPI, DramAttr, FALSE, &Inorder);
	//restore REFC
	SaveRestoreREFCDQSO(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);	
	//restore BGdelay
	SaveRestoreBGDelay(PeiServices, pPCIPPI, DramAttr, FALSE, &SaveBGDelay);

#if 0
	if(RankNo < 4){
		//Read  CHA   HIGH  Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQSO_HIGH);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHA DQSO HIGH BOUND\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %04x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAD3-AE4  
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte %d, RX%x= %04x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
		//Read  CHA  LOW Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQSO_LOW);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHA DQSO LOW BOUND\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAD3-AE4  
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte %d, RX%x= %04x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
	}
	else{
		//Read  CHB  HIGH   Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQSO_HIGH);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHB DQSO HIGH BOUND\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte %d, RX%x= %04x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
		//Read  CHB  LOW Bound
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_DQSO_LOW);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read CHB DQSO LOW BOUND\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RX262[4:0]= %04x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));
		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < ASIA_MAX_BYTES; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte %d, RX%x= %04x\r\n",i, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}
	}
#endif	
	
}



VOID Tx_DQSO_WriteLeveling(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsoStep)
{
	UINT16  SavedREFC = 0;
	UINT16  SavedOnTheFly = 0;
	UINT16  SavedSelfRef = 0;
	//UINT16  SavedOdt = 0;
	UINT16 SaveODTLookupTable = 0;
	UINT16 SavedBARASelect = 0;
	UINT32 Buffer32=0, DummyReadBase=0x00;
	UINT32 MrsSet32;
	UINT64 Address;
	UINT8 Index;
	UINT16 Temp16;
	
	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;
	//Save BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//2)	Set RWLBSTNUM[7:0] for scan times of every ptr   
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_SCAN_TIMES_FOR_EVERY_PTR);
    //LGE20180622 Patch wlvl issue
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RWLBSTNUM_7_0, 0x40);
	
	//3)	Set {REFC7,REFC6,REFC5,REFC4,REFC3,REFC2,REFC1,REFC0} to 0, disabling issuing refresh command
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//Save Selfrefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedSelfRef);
	
	//Save ODT Lookup
	SaveRestoreNBODTLookup(PeiServices, pPCIPPI, DramAttr,RankNo, TRUE, &SaveODTLookupTable);
	//Save On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOnTheFly);
	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//4)	Set RDYNCKE to 0, disabling dynamic CKE
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDYNCKE_BYRANK,0);
	
	//5)	Set RDWADVOS[2:0]_BEG & RDWADVOS[2:0]_END for the write leveling whole T scan range;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
	//LGE20180615 set begin=2,end=3.Patch WLVL ISSUE
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDWADVOS_2_0_BEG, ShiftToMaskBit(D0F3_RDWADVOS_2_0_BEG,2));
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDWADVOS_2_0_END, ShiftToMaskBit(D0F3_RDWADVOS_2_0_END,3));
	//6)	Set {RDQSO_STEP5, RDQSO_STEP4, RDQSO_STEP3, RDQSO_STEP2, RDQSO_STEP1, RDQSO_STEP0} for wlvl scan step
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQSO_STEP_DQSI_STEP);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSO_STEP_6_0,ShiftToMaskBit(D0F3_RDQSO_STEP_6_0,DqsoStep)); 

	//7)	Set {RSCAN_END5,RSCAN_END4,RSCAN_END3,RSCAN_END2,RSCAN_END1,RSCAN_END0} for scan end pointer
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CALIBRATION_BURN_IN_MODE_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCAN_END_5_0,ShiftToMaskBit(D0F3_RSCAN_END_5_0,(0x3F/DqsoStep)*DqsoStep));
	//8)	Set RDQSCAL to 1 for DQSO calibration setting  
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQSCAL, D0F3_RDQSCAL);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQSCAL_CHB, D0F3_RDQSCAL_CHB);
	}
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
	FlushCfgWrite(PeiServices, DramAttr, Address);	
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|0x10);	// Dummy Read
	WaitForMicroSec(PeiServices, 100);	//delay 100us
	ClearAllRankSize(DramAttr);
	
	//9)	Set {RSDM2,RSDM1,RSDM0} = 3'b011, issue MR1 to enable DRAM wlvl mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	FlushCfgWrite(PeiServices, DramAttr, Address);
	//
	//set target WLVL rank: MRS1 (WLVL = enabled) and (Rtt_Nom = 120ohm)
	//set other rank: MRS1 (WLVL = enabled) and (Qoff = disabled)
	
	for (Index = 0; Index < ASIA_MAX_RANKS; Index++){
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << Index)) {	
			////set PR=VR and set size to 0~256MB
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26+Index*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x04);		
			SetVrMap(PeiServices, pPCIPPI, DramAttr, Index, Index, TRUE);
			FlushCfgWrite(PeiServices, DramAttr, Address);

			if(Index == RankNo){

		#if 1		
				//Dsiable RTTWR
				Buffer32 = GetDDR4MR2(PeiServices, DramAttr, RankNo, MR2_RTTWR_DIS);
				MrsSet32 = Buffer32;
				if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
					MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);			
				Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read            
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR2:%x\n", MrsSet32));
				WaitForMicroSec(PeiServices, 10);	//delay 10us

				if(DramAttr->RegDimm == IS_REG_DIMM)
				{
					//Init RDIMM SIDE B 
					MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
					Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR2:%x\n", MrsSet32));
					WaitForMicroSec(PeiServices, 10);	//delay 10us
				}

		#endif

				//set MRS1 to (WLVL = enabled) and (Rtt_Nom = 120ohm)
				Buffer32 = GetDDR4MR1(PeiServices, DramAttr, Index, MR1_WLVL_UNDERCALPR);
				MrsSet32 = Buffer32;
				if (DramAttr->Rank1Mapping[DramAttr->AttrNo][Index] == RANK1_MAPPING_MIRRORED)
					MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);			
				Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read			
				WaitForMicroSec(PeiServices, 10);	//delay 10us
				if(DramAttr->RegDimm == IS_REG_DIMM)
				{
					//Init RDIMM SIDE B 
					MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
					Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
					WaitForMicroSec(PeiServices, 10);	//delay 10us
				}
			}
			else{	 			
				//set MRS1 to (WLVL = enabled) and QOff_DIS
				Buffer32 = GetDDR4MR1(PeiServices, DramAttr, Index, MR1_WLVL_OTHERPR);
				MrsSet32 = Buffer32;
				if (DramAttr->Rank1Mapping[DramAttr->AttrNo][Index] == RANK1_MAPPING_MIRRORED)
					MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);				
				Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read				
				WaitForMicroSec(PeiServices, 10);	//delay 10us
				if(DramAttr->RegDimm == IS_REG_DIMM)
				{
					//Init RDIMM SIDE B 
					MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
					Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
					WaitForMicroSec(PeiServices, 10);	//delay 10us
				}
			}
			//Clear rank size
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26+Index*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);       
		}
	}

	
	//Set Normal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//10)	Set RDQIEN and RCMPENDQ_ON to 1, always enable RX DQ input
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQIEN|D0F3_RCMPENDQ_ON, D0F3_RDQIEN|D0F3_RCMPENDQ_ON);

	//11)	Set RTIMCHKSEL to 0 or 1 based on the required timing check mode  
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTIMCHKSEL, 0x00);
	//

	//12)	Trigger reg_RDMWLEN_CHA to active DRAMCA wlvl function
	//13)	Wait for reg_ RDMWLEN_CHA being cleared by HW
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RDMWLEN_CHA, D0F3_REG_RDMWLEN_CHA);
		//delay some time
			WaitForMicroSec(PeiServices, 500);	//delay 500us
		//waiting for write leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RDMWLEN_CHA)!= 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REG_RDMWLEN_CHB, D0F3_REG_RDMWLEN_CHB);
		//delay some time
			WaitForMicroSec(PeiServices, 500);	//delay 500us
		//waiting for write leveling completion
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_REG_RDMWLEN_CHB)!= 0);
	}

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankNo);
	//17)  Disable write leveling
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);	
	FlushCfgWrite(PeiServices, DramAttr, Address);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
	ClearAllRankSize(DramAttr);

	//Set MRS Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);	
	for (Index = 0; Index < ASIA_MAX_RANKS; Index++){
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << Index)) {	
			//set PR=VR and set size to 0~256MB
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26+Index*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x04);		
			SetVrMap(PeiServices, pPCIPPI, DramAttr, Index, Index, TRUE);
			//set MRS1 to (WLVL = enabled) and (Rtt_Nom = 120ohm)
			Buffer32 = GetDDR4MR1(PeiServices, DramAttr, Index, DDR4_MR1_INIT);
			MrsSet32 = Buffer32;
			if (DramAttr->Rank1Mapping[DramAttr->AttrNo][Index] == RANK1_MAPPING_MIRRORED)
				MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);			
			Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read		
			WaitForMicroSec(PeiServices, 10);	//delay 1ms
			if(DramAttr->RegDimm == IS_REG_DIMM)
			{
				//Init RDIMM SIDE B 
				MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
				Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
				WaitForMicroSec(PeiServices, 10);	//delay 1ms
			}
#if 1
            if(Index == RankNo)
			{
				Buffer32 = GetDDR4MR2(PeiServices, DramAttr, RankNo, DDR4_MR2_INIT);
				MrsSet32 = Buffer32;
				if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankNo] == RANK1_MAPPING_MIRRORED)
					MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);			
				Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
            				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR2:%x\n", MrsSet32));

				WaitForMicroSec(PeiServices, 10);	//delay 10us
				if(DramAttr->RegDimm == IS_REG_DIMM)
				{
					//Init RDIMM SIDE B 
					MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
					Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR2:%x\n", MrsSet32));
					WaitForMicroSec(PeiServices, 10);	//delay 10us
				}
			}
#endif			
			//Clear rank size
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26+Index*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);		 
		}
	}
	
	//Set Normal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	
	FlushCfgWrite(PeiServices, DramAttr, Address);



    //15)	Set RDQSCAL to 0 for DQSO manual setting
	if(RankNo < 4)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQSCAL, 0);
	}
	else
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_B);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RDQSCAL_CHB, 0);
	}

	//16)Set RDQIEN and RCMPENDQ_ON to 0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQIEN|D0F3_RCMPENDQ_ON, 0);

	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//Restore Selfrefresh
	SaveRestoreSelfRef(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedSelfRef);
	
	//Restore  ODT Lookup
	SaveRestoreNBODTLookup(PeiServices, pPCIPPI, DramAttr,RankNo, FALSE, &SaveODTLookupTable);
	//Restore On the fly 
	SaveRestoreOnTheFly(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedOnTheFly);


#if 1
	if(RankNo < 4){
		//Read CHA RESULT
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_WLVL);
		PEI_DEBUG((PeiServices, EFI_D_WARN, "Read CHA DQSO WLVL\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_WARN, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));

		{
			//RXAD3-AE4  
			UINT8 i = 0;
			for(i =0;i < 8; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_WARN, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}

	}
	else {
		//Read CHB Result
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0, D0F3_DMIOSEL_WLVL); 
		PEI_DEBUG((PeiServices, EFI_D_WARN, "Read CHB DQSO WLVL\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_WARN, "RX262[4:0]= %02x\r\n", AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&0x1F));

		{
			//RXAE5-AF6
			UINT8 i = 0;
			for(i =0;i < 8; i++)
			{
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i);
				PEI_DEBUG((PeiServices, EFI_D_WARN, "RX%x= %04x\r\n",D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*i,AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
			}
		}

	}
#endif	
}

BOOLEAN Tx_DQSO_WriteLeveling_Filter(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
	//IN TX_IO_CALIBRATION_INFO *CalDQSOResult
	)
{
#if 0
	UINT8 FilterResult = TRUE;
	UINT8 WlvlSum = 0;
	UINT8 WlvlAvg = 0;
	UINT8 ErrorNum = 0;
	UINT8 CheckByteNum = ASIA_MAX_BYTES -1;
	UINT8 ByteIndex;
    //IF ECC Enable Then Check ECC Byte
	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)	CheckByteNum = ASIA_MAX_BYTES;		
		else      							CheckByteNum = ASIA_MAX_BYTES -1;			
	}

	//for()
#endif
	


    return TRUE;
}

VOID Tx_DQSO_WriteLeveling_SaveDataSet(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr,
    IN UINT8 SaveMode,
    IN UINT8 RankIndex,
    IN UINT8 ByteNo)
{
   
   UINT8 ByteIndex;
   UINT8 ByteBegin = 0;
   UINT8 ByteEnd = 0;
   UINT16 Value16 = 0;
  
  
   //FOR X8/X4 DIMM 
   
   if(ByteNo == ALLBYTE){
	   ByteBegin = 0;
	   ByteEnd = ASIA_MAX_BYTES;
   }
   else
   {
	   ByteBegin = ByteNo;
	   ByteEnd = ByteNo+1;
   }

   if(SaveMode == IOCTL_LOWHIGH)
   {

   #if 0
	    //LOW Bound 
	    for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	    {
	 
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WLVL, IOCTL_LOW, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW = Value16; 
	    } 

		 //HIGH Bound 
	    for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	    {
	 
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WLVL, IOCTL_HIGH, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH = Value16; 
	    }
	#else
		  
	    for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	    {
	        //step = 08 center 
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WLVL, IOCTL_CENTER, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);           
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH = Value16;
	    } 
	#endif

	
   }
   else if(SaveMode == IOCTL_CENTER)
   {
		//Center 
	    for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex ++)
	    {
	 
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WLVL, IOCTL_CENTER, READ, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);			
			DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_Setting = Value16;
	    } 

   }


  
}

VOID TX_DQSO_WriteLeveling_SetPhase(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,	
  IN UINT8 CheckByteNum,
  IN UINT8 DqsoStep,
  IN UINT8 Channel)
{
	UINT8 ByteIndex = 0;  	
	UINT16 DQSO_PHASE = 0;
	UINT16 TMP1,TMP2, DIFF;
	//UINT16 DQSO_SUM = 0;
	UINT16 Value16;

	//UINT8 RankIndex = 0;
	//UINT8 RankNum = 0;
	/*UINT8 RankNo1st = 0;*/
	UINT8 RankBegin = 0;
	//UINT8 RankEnd = 0;
	
	TMP1 = 0;TMP2 = 0;DIFF = 0;

    if(Channel == CHANNELA)
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "S32CHA DQSO AVG Phase:"));
	else if(Channel == CHANNELB)
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "S32CHB DQSO AVG Phase:"));
	for(ByteIndex = 0; ByteIndex < CheckByteNum; ByteIndex++)
	{ 

		//CHA Cal WLVL AVG
		if(Channel == CHANNELA)
		{
			 RankBegin = 0;
			if((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) && ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x01) == 0x01))
			{
				DQSO_PHASE = DramAttr->DramAutoCal[0][ByteIndex].DQSO_Setting & 0x3F;
			}
			else if((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) && ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x04) == 0x04))
			{
				DQSO_PHASE = DramAttr->DramAutoCal[2][ByteIndex].DQSO_Setting & 0x3F;
			}
			else if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2)
			{
				TMP1 = DramAttr->DramAutoCal[0][ByteIndex].DQSO_Setting & 0x3F;
				TMP2 = DramAttr->DramAutoCal[2][ByteIndex].DQSO_Setting & 0x3F;
				DIFF = ((TMP1 > TMP2) ? TMP1 -TMP2 : TMP2 - TMP1);
				if(DIFF > 0x28)
					DQSO_PHASE = ((TMP1 + TMP2 + 0X40) / 2)%0x40;
				else
					DQSO_PHASE = (TMP1 + TMP2)/2;
			}
		}
		else if(Channel == CHANNELB)
		{
			 RankBegin = 4;
			if((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) && ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x10) == 0x10))
			{
				DQSO_PHASE = DramAttr->DramAutoCal[4][ByteIndex].DQSO_Setting & 0x3F;
			}
			else if((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) && ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x40) == 0x40))
			{
				DQSO_PHASE = DramAttr->DramAutoCal[6][ByteIndex].DQSO_Setting & 0x3F;
			}
			else if(DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2)
			{
				TMP1 = DramAttr->DramAutoCal[4][ByteIndex].DQSO_Setting & 0x3F;
				TMP2 = DramAttr->DramAutoCal[6][ByteIndex].DQSO_Setting & 0x3F;
				DIFF = ((TMP1 > TMP2) ? TMP1 -TMP2 : TMP2 - TMP1);
				if(DIFF > 0x28)
					DQSO_PHASE = ((TMP1 + TMP2 + 0X40) / 2)%0x40;
				else
					DQSO_PHASE = (TMP1 + TMP2)/2;

				}
		}

		DQSO_PHASE = (DQSO_PHASE/DqsoStep)*DqsoStep;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%04X ", DQSO_PHASE));

		Value16 = Tx_DQSO_Convert_To_Value(PeiServices, DramAttr,RankBegin, DQSO_PHASE);		
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankBegin, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);   	
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(wlvl center) "));			
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
	//Important:	trigger Load Register		  
	TriggerLoadReg(PeiServices, DramAttr);
}

VOID TX_DQSO_WriteLeveling_SetWholeT(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,	
  IN UINT8 CheckByteNum,
  IN UINT8 Channel)
{
	UINT8 RankIndex;
	UINT8 RankBegin = 0;
	UINT8 RankEnd = 0;
	UINT8 RankNo1st = 0;
	UINT8 ByteIndex;
	UINT16 DQSO_WHOLET = 0;
	UINT16 DQSO_WHOLET_Value[ASIA_MAX_BYTES];

	UINT16 DQSO_LOW = 0, DQSO_HIGH = 0;
	UINT16 DQSO_infS=0, DQSO_supS=0xFFFF;
	 
	 if(Channel == CHANNELA)
	{		 
	  RankBegin = 0;
	  RankEnd = 4;
	}
	else if(Channel == CHANNELB)
	{		 
	  RankBegin = 4;
	  RankEnd = ASIA_MAX_RANKS;
	
	}
	for(RankIndex = RankBegin; RankIndex < RankEnd; RankIndex++){
		  if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){
			RankNo1st = RankIndex;
			break;
			}
		}	


	for(ByteIndex = 0; ByteIndex < CheckByteNum; ByteIndex++)
	{	
	 	DQSO_infS=0;
    	DQSO_supS=0xFFFF;
		DQSO_WHOLET = 0xFF;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "byte %02X: ", ByteIndex));
		for(RankIndex = RankBegin; RankIndex < RankEnd; RankIndex++){
			if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){
				DQSO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;
				DQSO_HIGH = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH;
				if(DQSO_supS > DQSO_HIGH)   DQSO_supS = DQSO_HIGH;
        		if(DQSO_infS < DQSO_LOW)    DQSO_infS = DQSO_LOW;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02XT->%02XT,", DQSO_LOW,DQSO_HIGH));
				 
			}
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"    Public:%02XT->%02XT\r\n", DQSO_infS, DQSO_supS));
		//use public WHOLET of ALL RANK
		 //DQSO_WHOLET = (DQSO_supS + DQSO_infS)/2;
		 
		 //LGE20180617 Another strategy
		 if(DQSO_supS >= (DQSO_infS + 1))
		 	DQSO_WHOLET = DQSO_supS-1;
		 else if(DQSO_supS == DQSO_infS)
		 	DQSO_WHOLET = DQSO_supS;
         else
		 	PEI_DEBUG((PeiServices, EFI_D_ERROR," ERROR!!! NO Public\r\n"));
         //LGE20180617 Another strategy

		
		 DQSO_WHOLET_Value[ByteIndex] = DQSO_WHOLET;
		//Rankindex is not care
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankNo1st, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSO_WHOLET);  
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "S17 DQSO SetWholeT Rank%02x : ", RankNo1st));
	for(ByteIndex = 0; ByteIndex < CheckByteNum; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"%02X ",DQSO_WHOLET_Value[ByteIndex]));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n "));


}


BOOLEAN Tx_DQSO_WriteLeveling_CheckRange(
  IN EFI_PEI_SERVICES **PeiServices,
  IN DRAM_ATTRIBUTE *DramAttr,
  IN UINT8 RankIndex,	
  IN UINT16    TxCalNum,
  IN BOOLEAN ECC_ENABLE)
{
   BOOLEAN Flag = TRUE;
   BOOLEAN WLVLCROSST = FALSE;
   UINT16 Type = 0;
   UINT16 WLVLError; 
   UINT16 WLVLFound;
   UINT16 WLVLECCByte; 
   UINT16  WLVLHigh = 0, WLVLCenter = 0, WLVLDiff = 0;
   UINT8 ByteIndex;
   UINT64 Address;


   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_WLVL_STA);
   WLVLError= AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0xFF;

   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_STA_OF_CALIBRATION_USING_WRITE_LEVELING);
   WLVLFound= AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);

   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_WRITE_LEVELING_ERR_LOG_GRP_DLL_CTL);
   WLVLECCByte= AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
   
   //WLVLError= AsiaPcieRead16(DramAttr->PcieBaseAddress, CHX002_DRAM|((UINT64)(D0F3_WLVL_STA) << 32))&0xFF;  
   //WLVLFound= AsiaPcieRead16(DramAttr->PcieBaseAddress, CHX002_DRAM|((UINT64)(D0F3_STA_OF_CALIBRATION_USING_WRITE_LEVELING) << 32));
   //WLVLECCByte= AsiaPcieRead16(DramAttr->PcieBaseAddress, CHX002_DRAM|((UINT64)(D0F3_WRITE_LEVELING_ERR_LOG_GRP_DLL_CTL) << 32));

    //LGE20180813 Check write leveling wholet cross T 
    for(ByteIndex = 0; ByteIndex < ((ECC_ENABLE)?ASIA_MAX_BYTES : ASIA_MAX_BYTES-1); ByteIndex ++)
   {
   		//wholet ==3
   		if(((DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_Setting & 0x1C0)>>6) == 0x03)
			WLVLCROSST = TRUE;
   }
   
   	//NON ECC Byte
	   if(RankIndex < 4){
		    if(WLVLError&0xFF && !WLVLCROSST){
		    	Flag = FALSE;
		      	Type = 0x01;
	        }
		    if((WLVLFound&0xFF) != 0xFF)
		    {
		       Flag = FALSE;
		       Type = 0x02;
		    }  
	   }
	   else
	   {
		    if(WLVLError&0xFF00 && !WLVLCROSST){
			      Flag = FALSE;
			      Type = 0x10;
		      }
		    if((WLVLFound&0xFF00) != 0xFF00)
		    {
		       Flag = FALSE;
		       Type = 0x20;
		    }
	   }
   
   if(ECC_ENABLE)
   {
    //ECC Enable case, check ECC Byte
    if(RankIndex < 4){
		if(WLVLECCByte & D0F3_WLVL_ERR_A8 && !WLVLCROSST)
		{
			Flag =  FALSE;
			Type = 0x04;

		}
		if(!(WLVLECCByte & D0F3_WLVL_FOUND_A8))
		{
			Flag =  FALSE;
			Type = 0x08;
		}	
      
    }
 	else
	{
		if(WLVLECCByte & D0F3_WLVL_ERR_B8 && !WLVLCROSST)
	    {
	        Flag =  FALSE;
	        Type = 0x40;
	    }

		if(!(WLVLECCByte & D0F3_WLVL_FOUND_B8))
		{
			Flag =  FALSE;
			Type = 0x80;
		}	

    }
   }

   
   if(Flag == FALSE)
  {
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank %02X: ", RankIndex));			
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "WLVLError(Detect two 0 ->1,expect 0x00)%04X, ", WLVLError));	  
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "WLVLFound(Detect one 0 ->1,expect 0xFF)%04X, ",  WLVLFound));  
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "WLVLECCByte=%04X, ", WLVLECCByte));
    
    if(Type&BIT0)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Any of byte 0~7 in CHA has twice DQ toggle) "));		
    if(Type&BIT1)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Any of byte 0~7 in CHA has no DQ toggle) "));		
    if(Type&BIT2)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Byte 8 in CHA has twice DQ toggle) "));		
    if(Type&BIT3)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Byte 8 in CHA has no DQ toggle) "));			
    if(Type&BIT4)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Any of byte 0~7 in CHB has twice DQ toggle) "));		
    if(Type&BIT5)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Any of byte 0~7 in CHB has no DQ toggle) "));		
    if(Type&BIT6)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Byte 8 in CHB has twice DQ toggle) "));		
    if(Type&BIT7)	PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Byte 8 in CHB has no DQ toggle) "));		
  }





  //check wlvl result
   for(ByteIndex = 0; ByteIndex < ((ECC_ENABLE)?ASIA_MAX_BYTES : ASIA_MAX_BYTES-1); ByteIndex ++)
   {
  #if 0 
   		WLVLLow = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;
		WLVLHigh = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH;
		WLVLCenter = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_Setting;
		if(WLVLHigh < WLVLLow)
			WLVLHigh += 0x40;
		if(WLVLCenter < WLVLLow)
			WLVLCenter += 0x40;			

		if(!(WLVLCenter >= WLVLLow && WLVLCenter <= WLVLHigh))
		{
			Flag =  FALSE;
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR: Write leveling Byte%02x check fail\r\n",  ByteIndex));
		}
   #else
		//WLVLLow = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;
		WLVLHigh = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH;
		WLVLCenter = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_Setting;
		if(WLVLCenter >= WLVLHigh)
			WLVLDiff = WLVLCenter - WLVLHigh;
		else
			WLVLDiff = WLVLHigh - WLVLCenter; 

		if((WLVLDiff > 0x0F && WLVLDiff < 0x34)|| (WLVLDiff > 0x4F))
		{
			Flag =  FALSE;
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR: Write leveling Byte%02x check fail,WLVLDiff=%04x.\r\n",  ByteIndex,WLVLDiff));
		}

   #endif
		
   }



   return Flag;
}


VOID Tx_DQSO_WriteLeveling_SaveTemp(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr,
    IN UINT8 RankIndex,
    IN UINT8 wlvlIndex)
{
	UINT8 ByteIndex;	
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	  DramAttr->WLVL_Result[wlvlIndex][ByteIndex] = (UINT8)DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW;	
}



VOID HW_DQO_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr) 
{
	UINT8		RankIndex = 0;
	UINT16		TxCalNum;
	BOOLEAN		TxResult = TRUE;	 	
	UINT16		DQORange[ASIA_MAX_BYTES];
	BOOLEAN     ECC_ENABLE = FALSE;
	UINT8		DqoStep = 2;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin DQO LCU Calibration\r\n"));
	for(TxCalNum = 0; TxCalNum<= 0x03; TxCalNum++)
	{
		TxResult = TRUE;
		//Do RDSIT Read Leveling and save results at dataset
		TX_DQO_ClearDataset(PeiServices, pPCIPPI, DramAttr);
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin DQO LCU Calibration - RankIndex:%d\r\n",RankIndex));
				//Clear dataset
				Tx_DQO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, DqoStep);

				Tx_DQO_LCU_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

				DramAttr->DramAutoCal[RankIndex][0].CalResult =Tx_DQO_LCU_CheckRange(PeiServices, DramAttr,RankIndex,ECC_ENABLE,DQORange);

				DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQO, DQORange,RankIndex, 0x22);
				if(DramAttr->DramAutoCal[RankIndex][0].CalResult == FALSE)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR!!! Calibration FAIL!!\r\n"));		
					TxResult = FALSE ;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "Calibration PASS!!\r\n"));		
				}
			}
		}
		if(TxResult==TRUE)
		{
			//setting 
			if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F)
			{
				if(!TX_DQO_LCU_SetRegister_CHA(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE))
					TxResult = FALSE;
			}	
			if(DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0)
			{
				if(!TX_DQO_LCU_SetRegister_CHB(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE))
					TxResult = FALSE;
			}
			if(TxResult==TRUE)
				break;
		}
		/*DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_RDSIT, 0x10);*/
	}

	 if(!TxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_DQO);	

	 }
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin DQO LCU Calibration - End\r\n"));
	
}

VOID HW_DQSO_LCU_2D(
       IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
       IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
       IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
       IN DRAM_ATTRIBUTE *DramAttr) 
{
	UINT8      RankIndex = 0;
	//UINT16     TxCalNum;
	BOOLEAN    TxResult;      
	UINT16     DQSORange[13][ASIA_MAX_BYTES];
	UINT16     DQSOMaxRange = 0;
	UINT16     DQSOTempRange = 0;	
	BOOLEAN    ECC_ENABLE = FALSE;
	UINT8      DqsoStep = 2;
	UINT64     Address;
	UINT16     RTXDS2DQPH = 0x00;
	UINT16      RTXDS2DQPHsave[ASIA_MAX_RANKS];
	UINT16     RTXDS2DQPH1st = 0x00;
	UINT8      RTXDS2DQPHIndex = 0;
	UINT8      ByteIndex = 0;
	UINT8 CheckByteNum = ASIA_MAX_BYTES -1;

    if(DramAttr->ECCSupport)
    {
          if(DramAttr->ConfigData.DRAMECC)
          	{
                 ECC_ENABLE = TRUE;
				 CheckByteNum = ASIA_MAX_BYTES;
          	}	 
    }

   PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin DQSO LCU 2D Calibration\r\n"));

   //Clear 0
	(*PeiServices)->SetMem( DQSORange, ASIA_MAX_BYTES * 13 * sizeof(UINT16), 0);
    (*PeiServices)->SetMem( RTXDS2DQPHsave, ASIA_MAX_RANKS * sizeof(UINT16), 0);
	
        TxResult = TRUE;
          //Do RDSIT Read Leveling and save results at dataset
         TX_DQSO_ClearDataset(PeiServices, pPCIPPI, DramAttr);
          for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
          {
			 if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			 {
			 	//clear DQSOMaxRange
				DQSOMaxRange = 0;
				
			 	 for(RTXDS2DQPH = 0x10,  RTXDS2DQPHIndex = 0;RTXDS2DQPH < 0x40;RTXDS2DQPH += 0x04, RTXDS2DQPHIndex++)
				{
					//clear DQSOTempRange 
					DQSOTempRange = 0;
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
					AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTXDS2DQPH_5_0, RTXDS2DQPH);
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank%x,RTXDS2DQPH%x",RankIndex, RTXDS2DQPH));
					    
			        //Clear dataset
			        Tx_DQSO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsoStep);

			        Tx_DQSO_LCU_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

			        DramAttr->DramAutoCal[RankIndex][0].CalResult =Tx_DQSO_LCU_CheckRange(PeiServices, DramAttr,RankIndex,ECC_ENABLE,DQSORange[RTXDS2DQPHIndex]);

			        if(DramAttr->DramAutoCal[RankIndex][0].CalResult == FALSE)
			            PEI_DEBUG((PeiServices, EFI_D_ERROR, "(X) : "));                   
			        else                        
			            PEI_DEBUG((PeiServices, EFI_D_ERROR, "(O) : "));              
			        
					//Dump range
					for(ByteIndex = 0; ByteIndex < CheckByteNum; ByteIndex ++)
					{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x,", DQSORange[RTXDS2DQPHIndex][ByteIndex]));
                        if(DramAttr->DramAutoCal[RankIndex][0].CalResult == TRUE) 
							DQSOTempRange+= DQSORange[RTXDS2DQPHIndex][ByteIndex];
					}					
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));

					if(DQSOTempRange > DQSOMaxRange)
					{
						DQSOMaxRange = DQSOTempRange;
						RTXDS2DQPHsave[RankIndex] = RTXDS2DQPH;
					}
					
			 }
				
				if(RTXDS2DQPH1st == 0)
					RTXDS2DQPH1st = RTXDS2DQPHsave[RankIndex];
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank%0x RTXDS2DQPH = %0x\r\n",RankIndex, RTXDS2DQPHsave[RankIndex]));
				 
			}
         
	}
 
       //hard code First rank RTXDS2DQPH
       Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION);
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTXDS2DQPH_5_0, RTXDS2DQPH1st);
	   PEI_DEBUG((PeiServices, EFI_D_ERROR, "Final RTXDS2DQPH = %0x\r\n", RTXDS2DQPH1st));
	   
       PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSO LCU 2D Calibration - End\r\n"));
       
}

VOID HW_DQSO_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr) 
{
	UINT8		RankIndex = 0;
	UINT16		TxCalNum;
	BOOLEAN		TxResult = TRUE;	 	
	UINT16		DQSORange[ASIA_MAX_BYTES];
	BOOLEAN     ECC_ENABLE = FALSE;
	UINT8		DqsoStep = 2;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin DQSO LCU Calibration\r\n"));
	for(TxCalNum = 0; TxCalNum<= 0x03; TxCalNum++)
	{
		TxResult = TRUE;
		//Do RDSIT Read Leveling and save results at dataset
	  	TX_DQSO_ClearDataset(PeiServices, pPCIPPI, DramAttr);
		for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
		{
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
			{
				//Clear dataset
				Tx_DQSO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsoStep);

				Tx_DQSO_LCU_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

				DramAttr->DramAutoCal[RankIndex][0].CalResult =Tx_DQSO_LCU_CheckRange(PeiServices, DramAttr,RankIndex,ECC_ENABLE,DQSORange);

				DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQSO, DQSORange,RankIndex,0x33);
				if(DramAttr->DramAutoCal[RankIndex][0].CalResult == FALSE)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR!!! TX DQSO Calibration FAIL!!\r\n"));		
					TxResult = FALSE ;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "TX DQSO Calibration PASS!!\r\n"));		
				}
			}
		}
		if(TxResult==TRUE)
		{
			//setting 
			if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F)
				TX_DQSO_LCU_SetRegister_CHA(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE);
			if(DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0)
				TX_DQSO_LCU_SetRegister_CHB(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE);
			break;
		}
		
	}
	 if(!TxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_DQSO);	

	 }
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSO LCU Calibration - End\r\n"));
	
}


VOID HW_DQSO_WriteLeveling(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr)
{	
	 UINT8 RankIndex = 0;
	 UINT16 TxCalNum = 0;	 
	 UINT8 CheckByteNum = ASIA_MAX_BYTES -1;
	 UINT8 DQSOStep = 0;
	// UINT8 WlvlIndex = 0;
	 UINT16 DQSOCalNum = 0;
	 //BOOLEAN CheckResult = TRUE;
	 BOOLEAN ECC_ENABLE = FALSE;
	 
	 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin DQSO Writeleveling Calibration\r\n"));   
	
		 
	 //IF ECC Enable Then Check ECC Byte
	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
		{
			ECC_ENABLE = TRUE;
			CheckByteNum = ASIA_MAX_BYTES;
			}	
	}	
	
	 
	 //Clear dataset
	 TX_DQSO_ClearDataset(PeiServices, pPCIPPI, DramAttr);
	
	 

	 for(RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex ++)
	 {
		 if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
		 {				  
			 if(1){
		
				// do {				 
					 //for(WlvlIndex = 0; WlvlIndex < WLVL_Repeat_MAX; WlvlIndex++){
					 	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Writeleveling%02x: ", WlvlIndex));						 
						 //Do DQSO Write leveling 
						 for(DQSOCalNum = 0; DQSOCalNum <= 0x10; DQSOCalNum++){
						 	 DQSOStep = 0x08;
							 Tx_DQSO_WriteLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DQSOStep);							 
							 Tx_DQSO_WriteLeveling_SaveDataSet(PeiServices, pPCIPPI, DramAttr, IOCTL_LOWHIGH, RankIndex, ALLBYTE);
                             //A0PATCH set DQSOStep=04 instead DQSOStep = 02 for WLVL ISSUE
							if(ASIA_NB_REVISION == 0)
							{		
							 	DQSOStep = 0x04;
								PEI_DEBUG((PeiServices, EFI_D_ERROR, "A0 Limitation\r\n"));
							}
							else
							{
								DQSOStep = 02;								
							}
							 Tx_DQSO_WriteLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DQSOStep);							 
							 Tx_DQSO_WriteLeveling_SaveDataSet(PeiServices, pPCIPPI, DramAttr, IOCTL_CENTER, RankIndex, ALLBYTE);

							 
							 DramAttr->DramAutoCal[RankIndex][0].CalResult = Tx_DQSO_WriteLeveling_CheckRange(PeiServices, DramAttr, RankIndex,TxCalNum,ECC_ENABLE);
							 DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQSO, NULL,RankIndex,0x30);
							 //check DQSO range Pass or Not
							 if(DramAttr->DramAutoCal[RankIndex][0].CalResult)								  
							 {	 
								 //Tx_DQSO_WriteLeveling_SaveTemp(PeiServices, pPCIPPI, DramAttr, RankIndex, WlvlIndex);
								 break;  
							 }
						 }
						 if(!DramAttr->DramAutoCal[RankIndex][0].CalResult)
						 {
						 	CalErrorReboot(PeiServices, DramAttr, IO_WLVL);	

						 }
					//}
					 
					 //CheckResult = Tx_DQSO_WriteLeveling_Filter(PeiServices, DramAttr);
				 //} while (!CheckResult);
	
			 }
			 else
			 {	
			  #if 0
			 	//Only for debug
				 PEI_DEBUG((PeiServices, EFI_D_ERROR, "HARD CODE Write leveling\r\n"));
				 
				 if(RankIndex<4) //Channel A
				 {
					 for (FindIndex = 0; FindIndex < WLVLIndexValTblLen; FindIndex++)
					 {
						 if ((WLVLIndexValTbl[FindIndex].DramFreq == DramAttr->DramFreq)&&
								 (WLVLIndexValTbl[FindIndex].RawCardType == DramAttr->ChARawCardType[DramAttr->AttrNo])&&
								 (WLVLIndexValTbl[FindIndex].ChannelIndex == ChA))
						 {							 
							 break;
						 }
					 }
				 }
				 else
				 {
					 for (FindIndex = 0; FindIndex < WLVLIndexValTblLen; FindIndex++)
					 {
						 if ((WLVLIndexValTbl[FindIndex].DramFreq == DramAttr->DramFreq)&&
								 (WLVLIndexValTbl[FindIndex].RawCardType == DramAttr->ChBRawCardType[DramAttr->AttrNo])&&
								 (WLVLIndexValTbl[FindIndex].ChannelIndex == ChB))
						 {
							 break;
						 }
					 }
				 }
				 for (ByteIndex = 0; ByteIndex < 18; ByteIndex++)
				 {
					 DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW = WLVLIndexValTbl[FindIndex].IndexVal[ByteIndex];
				 }
				#endif	
			 }			   
			
			 }			
		}
	
	
	 //Set DQSO
	 DQSOStep = 0x04;
	 if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0)
		TX_DQSO_WriteLeveling_SetPhase(PeiServices, pPCIPPI, DramAttr, CheckByteNum, DQSOStep,CHANNELA);
	 if(DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0) 		   
		TX_DQSO_WriteLeveling_SetPhase(PeiServices, pPCIPPI, DramAttr, CheckByteNum, DQSOStep,CHANNELB);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQSO Writeleveling - end\r\n"));  


}

VOID HW_TX_WriteLeveling(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16 TxCalNum = 0;
	BOOLEAN TxResult = TRUE;
	UINT8 RankIndex;
	UINT8 ByteIndex;
	UINT8 CheckByteNum = ASIA_MAX_BYTES -1;
	UINT16 DQSOWHOLET = 0;
  	UINT16 DQSOWHOLET_BEG = 1;
  	UINT16 DQSOWHOLET_END = 7;
	UINT16 DQSOWHOLET_LOW = 0xFF;
	UINT16 DQSOWHOLET_HIGH = 0x00;
    UINT16 DQORange[7][ASIA_MAX_BYTES];//7 is WHOLET Range
	BOOLEAN     ECC_ENABLE = FALSE;
	UINT8		DqoStep = 2;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
		{
			ECC_ENABLE = TRUE;
			CheckByteNum = ASIA_MAX_BYTES;
		}	
	}

	
	
	for(TxCalNum = 0; TxCalNum<= 0x03; TxCalNum++){
		TxResult = TRUE;
	    //Clear dataset
	    TX_DQSO_ClearDataset(PeiServices, pPCIPPI, DramAttr);
	    TX_DQO_ClearDataset(PeiServices, pPCIPPI, DramAttr);	         	
	    for(RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex ++)
	    {
			if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
	       {
				//Clear 0
			    (*PeiServices)->SetMem(DQORange, ASIA_MAX_BYTES * 7 * sizeof(UINT16), 0);
				 for(DQSOWHOLET = DQSOWHOLET_BEG; DQSOWHOLET <= DQSOWHOLET_END; DQSOWHOLET++)
				 {
					Tx_DQSO_SetWholet(PeiServices, pPCIPPI, DramAttr, RankIndex, DQSOWHOLET);

					Tx_DQO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, DqoStep);

					Tx_DQO_LCU_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

					Tx_DQO_LCU_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, DQORange[DQSOWHOLET-1]);
					

					//DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQO, DQORange[DQSOWHOLET-1],RankIndex, 0x22);
				
				 }

                //dump range     
				 
				for(DQSOWHOLET = DQSOWHOLET_BEG; DQSOWHOLET <= DQSOWHOLET_END; DQSOWHOLET++)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank%02x|WHOLET%02x:", RankIndex, DQSOWHOLET));
					for(ByteIndex = 0; ByteIndex < CheckByteNum; ByteIndex ++)
					{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x,", DQORange[DQSOWHOLET-1][ByteIndex]));
					}
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
				}
				

                 for(ByteIndex = 0; ByteIndex < CheckByteNum; ByteIndex ++)
                 {
                 	 DQSOWHOLET_LOW = 0xFF;
					 DQSOWHOLET_HIGH = 0x00;
					 for(DQSOWHOLET = DQSOWHOLET_BEG; DQSOWHOLET <= DQSOWHOLET_END; DQSOWHOLET++)
					 {
						if(DQORange[DQSOWHOLET-1][ByteIndex])
						{
						    if(DQSOWHOLET_LOW > DQSOWHOLET)
								DQSOWHOLET_LOW = DQSOWHOLET;
							if(DQSOWHOLET_HIGH < DQSOWHOLET)
								DQSOWHOLET_HIGH = DQSOWHOLET;
						}		                 

					 }
					 DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_LOW = DQSOWHOLET_LOW;
					 DramAttr->DramAutoCal[RankIndex][ByteIndex].DQSO_HIGH = DQSOWHOLET_HIGH; 
					 if(DQSOWHOLET_LOW == 0xFF)
					 	TxResult = FALSE;
					
                 }
				
	       }

	    }	


		if(TxResult == TRUE)
			break;
	}
	 if(!TxResult)
	 {
	  	CalErrorReboot(PeiServices, DramAttr, IO_DQO);	

	 }
	
		//Set DQSO
	 if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0)
		TX_DQSO_WriteLeveling_SetWholeT(PeiServices, pPCIPPI, DramAttr, CheckByteNum, CHANNELA);
	 if(DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0) 		   
		TX_DQSO_WriteLeveling_SetWholeT(PeiServices, pPCIPPI, DramAttr, CheckByteNum, CHANNELB);
		
}



