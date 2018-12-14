//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
//Ver	Date			Name	Note
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#include "Pei.h"
#include "Draminit.h"
#include "VrefCalibration.h"
#include "InitDRAMByRank.h"
#include "IOTimingControl.h"
#include "UpdateRankAddr.h"
#include "DramUtil.h"



/************************************
**                                                               
**  Txvref calibration code
**                                                                
**************************************/
	//TxVref Value Scan Table
	UINT8 TxVrefTable[74] = 
	{
	  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
	  0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x0,
	  0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE,
	  0xF, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A,
	  0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 
	  0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32
	
	};
	
	//DKS -20161220 add -s
	TX_VREF_TBL TxVrefTableWholt[74] =
	{
	  {2, 0x40, 4500},{2, 0x41, 4565},{2, 0x42, 4630},{2, 0x43, 4695},{2, 0x44, 4760},{2, 0x45, 4825},
	  {2, 0x46, 4890},{2, 0x47, 4955},{2, 0x48, 5020},{2, 0x49, 5085},{2, 0x4A, 5150},{2, 0x4B, 5215},
	  {2, 0x4C, 5280},{2, 0x4D, 5345},{2, 0x4E, 5410},{2, 0x4F, 5475},{2, 0x50, 5540},{2, 0x51, 5605},
	  {2, 0x52, 5670},{2, 0x53, 5735},{2, 0x54, 5800},{2, 0x55, 5865},{2, 0x56, 5930},{1, 0x0,	6000},
	  {1, 0x1,	6065},{1, 0x2,	6130},{1, 0x3,	6195},{1, 0x4,	6260},{1, 0x5,	6325},{1, 0x6,	6390},
	  {1, 0x7,	6455},{1, 0x8,	6520},{1, 0x9,	6585},{1, 0xA,	6650},{1, 0xB,	6715},{1, 0xC,	6780},
	  {1, 0xD,	6845},{1, 0xE,	6910},{1, 0xF,	6975},{1, 0x10, 7040},{1, 0x11, 7105},{1, 0x12, 7170},
	  {1, 0x13, 7235},{1, 0x14, 7300},{1, 0x15, 7365},{1, 0x16, 7430},{1, 0x17, 7495},{1, 0x18, 7560},
	  {1, 0x19, 7625},{1, 0x1A, 7690},{1, 0x1B, 7755},{1, 0x1C, 7820},{1, 0x1D, 7885},{1, 0x1E, 7950},
	  {1, 0x1F, 8015},{1, 0x20, 8080},{1, 0x21, 8145},{1, 0x22, 8210},{1, 0x23, 8275},{1, 0x24, 8340},
	  {1, 0x25, 8405},{1, 0x26, 8470},{1, 0x27, 8535},{1, 0x28, 8600},{1, 0x29, 8665},{1, 0x2A, 8730},
	  {1, 0x2B, 8795},{1, 0x2C, 8860},{1, 0x2D, 8925},{1, 0x2E, 8990},{1, 0x2F, 9055},{1, 0x30, 9120},
	  {1, 0x31, 9185},{1, 0x32, 9250}
	};
	//DKS -20161220 add -e

EFI_STATUS SwSetTxVref(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 VrefRange,
	IN UINT32 VrefDQ)
{
	UINT64 Address;
	UINT32 Buffer32 = 0x00, MrsSet32 = 0x00, DummyReadBase=0x00;
	UINT16  SavedREFC = 0;
	UINT16 SavedBARASelect = 0;
	
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankIndex=%d\n", RankIndex));
	//UINT8  SavedBANKSEL = 0;
	//UINT8  SavedDataWidth = 0;
	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;
	//Save BA /RA Select

	//SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect, &SavedBANKSEL, &SavedDataWidth);
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);

	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);

	//Clear all VRank size
	ClearAllRankSize(DramAttr);	

	// Map each Physical Rank N to Virtual Rank N
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

#if 1
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read

	WaitForMicroSec(PeiServices, 100);	//delay 1ms
#endif

	//Set MRS Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

	//AsiaIoWrite8(0x80, 0xC1);
	//TODO only test
	Buffer32 = 0x00;
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankIndex=%d\n", RankIndex));
	PEI_DEBUG((PeiServices, EFI_D_WARN, "VREF_TRAIN_EN=%d, VREF_RANGE=%d\n", VREF_TRAIN_EN, VrefRange));
	Buffer32 = GetDDR4MR6(PeiServices, DramAttr, RankIndex, VREF_TRAIN_EN | VrefRange, VrefDQ);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Enable Txvref Buffer32 MR6:%x\n", Buffer32));
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
	{
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	    PEI_DEBUG((PeiServices, EFI_D_WARN, "Enable Txvref MrsSet32 MR6:%x\n", MrsSet32));
	}
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

	WaitForMicroSec(PeiServices, 100);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
	}

	WaitForMicroSec(PeiServices, 100);	//delay 100us
	
	Buffer32 = 0x00;
	PEI_DEBUG((PeiServices, EFI_D_WARN, "RankIndex=%d\n", RankIndex));
	PEI_DEBUG((PeiServices, EFI_D_WARN, "VREF_TRAIN_EN=%d, VREF_RANGE=%d\n", VREF_TRAIN_EN, VrefRange));
	Buffer32 = GetDDR4MR6(PeiServices, DramAttr, RankIndex, VREF_TRAIN_EN | VrefRange, VrefDQ);
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Enable Txvref Buffer32 MR6:%x\n", Buffer32));
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
	{
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	    PEI_DEBUG((PeiServices, EFI_D_WARN, "Enable Txvref MrsSet32 MR6:%x\n", MrsSet32));
	}
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

	WaitForMicroSec(PeiServices, 100);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
	}

	WaitForMicroSec(PeiServices, 100);	//delay 100us

#if 0
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS); 
#endif

	//Disable Vref training
	Buffer32 = GetDDR4MR6(PeiServices, DramAttr, RankIndex, DDR4_MR6_INIT | VrefRange, VrefDQ);
	MrsSet32 = Buffer32;
	PEI_DEBUG((PeiServices, EFI_D_WARN, "Disable Txvref Buffer32 MR6:%x\n", Buffer32));
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
	{
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
		PEI_DEBUG((PeiServices, EFI_D_WARN, "Disable Txvref MrsSet32 MR6:%x\n", MrsSet32));
	}
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

	WaitForMicroSec(PeiServices, 100);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		//Init RDIMM SIDE B 
		MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
	}

	WaitForMicroSec(PeiServices, 100);	//delay 100us
	
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "Disable Txvref MrsSet32 MR6:%x\n", MrsSet32));*/
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	FlushCfgWrite(PeiServices, DramAttr, Address);
	
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);

	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);

	PEI_DEBUG((PeiServices, EFI_D_WARN, "RKD : TX VREF SETTING - MRS comand end\n"));

	return EFI_SUCCESS;
}




/***********************************************
 * The PerByte Txvref value will store in:
 * TX_VREF_DQO_INFO[TXVERF_VALUE][ASIA_MAX_BYTES]
 * 
 * 1. scan txverf to find the best center value
 * 2. Valid check vref distance within one byte.
 * 3. need to save the low or high to print eye???
 * *******************************************/
UINT16 TxVref_From_Tx_Eye(
    IN EFI_PEI_SERVICES **PeiServices,
    IN DRAM_ATTRIBUTE *DramAttr,
    IN UINT8 ByteIndex,
    IN OUT TX_VREF_DQO_INFO TxVref_Info[74][ASIA_MAX_BYTES])
{
    UINT16 TxVrefAvg = 0;
    UINT8 TxVrefIndex = 0;

    UINT16 DQORange = 0;
    UINT16 BiggestRange = 0;
    UINT16 NextDQORange = 0;


    UINT8 JitterRangeCnt = 0;
    UINT8 FirstNeedTxVref = 0;
    UINT8 LastNeedTxVref = 0;
    UINT8 BestTxVref = 0;

    // find all byte first biggest Txvref.
    for (TxVrefIndex = TXVREF_INDEX_BEGIN; TxVrefIndex < TXVREF_INDEX_END;)
    {
        DQORange = TxVref_Info[TxVrefIndex][ByteIndex].DQORange;
        NextDQORange = TxVref_Info[TxVrefIndex + TXVREF_INDEX_STEP][ByteIndex].DQORange;
        if ((DQORange > BiggestRange) && (NextDQORange <= DQORange + 6))
        { //filter the abnormal Txvref.
            BiggestRange = DQORange;
            BestTxVref = (UINT8)TxVrefIndex;
        }
        TxVrefIndex += TXVREF_INDEX_STEP;
    } //  end for first biggest Txvref ...
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\rFind DQO Byte=%d biggest Txvref=%x", ByteIndex, BestTxVref));
    // Up search
    JitterRangeCnt = 0;
    for (TxVrefIndex = BestTxVref; TxVrefIndex < TXVREF_INDEX_END;)
    {
        DQORange = TxVref_Info[TxVrefIndex][ByteIndex].DQORange;
        if ((DQORange + DQO_VREF_THRESHOLD) >= BiggestRange)
        {
            FirstNeedTxVref = (UINT8)TxVrefIndex;
            JitterRangeCnt = 0;
        }
        else
        {
            JitterRangeCnt += 1;
            if (JitterRangeCnt >= 3)
            {
                break;
            }
        }
        TxVrefIndex += TXVREF_INDEX_STEP;
    }
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\rUp Search FirstNeedTxVref = %x", FirstNeedTxVref));
    //end Up Search
    // Down search
    JitterRangeCnt = 0;
    for (TxVrefIndex = BestTxVref; TxVrefIndex > TXVREF_INDEX_BEGIN;)
    {
        DQORange = TxVref_Info[TxVrefIndex][ByteIndex].DQORange;
        if ((DQORange + DQO_VREF_THRESHOLD) >= BiggestRange)
        {
            LastNeedTxVref = (UINT8)TxVrefIndex;
            JitterRangeCnt = 0;
        }
        else
        {
            JitterRangeCnt += 1;
            if (JitterRangeCnt >= 3)
            {
                break;
            }
        }
		if(TxVrefIndex < TXVREF_INDEX_STEP)
		{
			LastNeedTxVref = (UINT8)TxVrefIndex;
            break;
		}
        TxVrefIndex -= TXVREF_INDEX_STEP;
    }
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\rDown Search LastNeedTxVref = %x \n", LastNeedTxVref));
    //end Down Search

    //calculate the setting Txvref
    TxVrefAvg = (LastNeedTxVref + FirstNeedTxVref) / 2;
	if (TxVref_Info[BestTxVref][ByteIndex].DQORange > TxVref_Info[TxVrefAvg][ByteIndex].DQORange)
		TxVrefAvg = BestTxVref;
    return TxVrefAvg;
}



// #define SHOW_ALL_BYTE 0x55
VOID Tx_VrefDQO_Cal(
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr)
{
    BOOLEAN ECC_ENABLE = FALSE;
    UINT8 RankIndex = 0;
    UINT8 ByteIndex = 0;

    UINT8 TxVrefIndex = 0;
    UINT16 TxVrefMidAvg = 0;
    UINT16 TxVrefAvg = 0;

    //BOOLEAN TxResult;
    TX_VREF_DQO_INFO Show_Info[74][ASIA_MAX_BYTES];
    UINT16 DQORange[ASIA_MAX_BYTES];

    BOOLEAN DQOResult = FALSE;
    BOOLEAN SHOWLOG = TRUE;
    UINT8 ShowLogByte = 0;

    BOOLEAN TXVREF_ALL = DramAttr->ConfigData.TxVrefAllByte;
    UINT8 TxVref_Sel_Byte = 0;
	UINT8 TxVrefCenter[ASIA_MAX_RANKS][ASIA_MAX_BYTES];
    UINT16 Print_Index = 0;

    UINT8 DqoStep = 2;

    if (DramAttr->ECCSupport)
    {
        if (DramAttr->ConfigData.DRAMECC)
            ECC_ENABLE = TRUE;
    }

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin TxVref Calibration...\r\n"));
    //MCM20180425 modify
    for (RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex++)
    {

#ifdef TXVREF_SHOW_LOG
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank %02x\r\n", RankIndex));
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
#endif
         (*PeiServices)->SetMem(Show_Info, sizeof(Show_Info), 0);
         (*PeiServices)->SetMem(TxVrefCenter, sizeof(TxVrefCenter), 0);
		 TxVrefMidAvg = 0;		 
        if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex))
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank %0x\r\n", RankIndex));


            //step1 Scan TXVref and Save DQO LB and HB data
            for (TxVrefIndex = TXVREF_INDEX_BEGIN; TxVrefIndex < TXVREF_INDEX_END;)
            {
                (*PeiServices)->SetMem(DQORange, sizeof(DQORange), 0);
                //Step1-1  Set TXVref
                if (!(TxVrefTable[TxVrefIndex] & 0x40))
                    SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefTable[TxVrefIndex] & 0x3F);
                else
                    SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE2, TxVrefTable[TxVrefIndex] & 0x3F);
            	//Step1-2  DQO_LCU Sequence
				Tx_DQO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, DqoStep);
				//Step1-3  DQO_LCU SaveDataSet
                Tx_DQO_LCU_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);
                //Step1-4  Save DQO LB and HB data
                DQOResult = Tx_DQO_LCU_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, DQORange);
				DramAttr->DramAutoCal[RankIndex][0].CalResult = DQOResult;
				//DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_DQO, NULL,RankIndex, 0x50);                
				for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE) ? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++)
                {
                    /* --------------------------Save TxVref Log Information----------------------- */
                    Show_Info[TxVrefIndex][ByteIndex].DQO_LOW = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_LOW;
                    Show_Info[TxVrefIndex][ByteIndex].DQO_HIGH = DramAttr->DramAutoCal[RankIndex][ByteIndex].DQO_HIGH;
                    Show_Info[TxVrefIndex][ByteIndex].DQORange = DQORange[ByteIndex];
                    /* ------------------------------------------------------------------------ */
                }
                TxVrefIndex += TXVREF_INDEX_STEP;
            } //  end for TXVREF_INDEX_END

            /*-------------- Find Txvref ------------------------*/
			//Step2  find the best txvref index
            if (TXVREF_ALL == TRUE)
            {
                for (ByteIndex = 0;  ByteIndex < ((ECC_ENABLE) ? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++)
                {
                	PEI_DEBUG((PeiServices, EFI_D_ERROR, "*********Rank%2x TxVref Calibration Selection byte is %x*********\n", RankIndex, ByteIndex));	
                    //Step2-1 calculate the setting Txvref when scan all byte
                    TxVrefAvg = TxVref_From_Tx_Eye(PeiServices, DramAttr, ByteIndex, Show_Info);
					TxVrefCenter[RankIndex][ByteIndex] = (UINT8)TxVrefAvg ;
                    DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = (UINT8)TxVrefAvg;
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQO Rank=%d Byte=%d TxVrefCENTER=%x \n ", RankIndex, ByteIndex, DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER));
                    //end calculate
                }
				//Step2-2 calculate the average value 
                for (ByteIndex = 0;  ByteIndex < ((ECC_ENABLE) ? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++)
                {
                    TxVrefMidAvg += TxVrefCenter[RankIndex][ByteIndex];
                }
                // PEI_DEBUG((PeiServices, EFI_D_ERROR, "TxVrefMidAvg = %04x \r\n",TxVrefMidAvg));
                TxVrefMidAvg = TxVrefMidAvg / ((ECC_ENABLE) ? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1));

				DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = (UINT8)TxVrefMidAvg;				
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "Setting AllByte Best TxVerfValue =%x!!!\r\n", TxVrefMidAvg));
                //Step2-3 setting result
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Setting Result!!!\r\n"));
                    if (!(TxVrefTable[TxVrefMidAvg] & 0x40))
                        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefTable[TxVrefMidAvg] & 0x3F);
                    else
                        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE2, TxVrefTable[TxVrefMidAvg] & 0x3F);

                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "########## Setting Value is ==> "));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Allbyte TxVrefIndex = %0x, TxVrefRange = %0x, TxVrefValue = %0x ##########",
                               TxVrefMidAvg,
                               ((TxVrefTable[TxVrefMidAvg] & 0x40) >> 6) + 1,
                               TxVrefTable[TxVrefMidAvg] & 0x3F));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
                }
            }
            else
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "*********Rank%2x TxVref Calibration Selection byte is %x*********\n", RankIndex, TxVref_Sel_Byte));
                //Step2-1 calculate the setting Txvref when scan selection byte
                TxVrefAvg = TxVref_From_Tx_Eye(PeiServices, DramAttr, TxVref_Sel_Byte, Show_Info);
                DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = (UINT8)TxVrefAvg;
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "DQO Rank=%d TxVref_Sel_Byte=%d TxVrefCENTER=%x \n ", RankIndex, TxVref_Sel_Byte, DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER));
                //end calculate
                //Step2-2 setting result
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Setting Result!!!\r\n"));
                    if (!(TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x40))
                        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x3F);
                    else
                        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE2, TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x3F);

                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "########## Setting Value is ==> "));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "TxVrefIndex = %0x, TxVrefRange = %0x, TxVrefValue = %0x ##########",
                               DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER,
                               ((TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x40) >> 6) + 1,
                               TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER] & 0x3F));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
                }
            }
            //show log
            if (SHOWLOG == TRUE)
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "*********Showing Log...*********\r\n"));

                if (DramAttr->ConfigData.TxVrefAllByte)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Showing All Byte Log!!!\r\n"));
                    for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE) ? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++)
                    {
 						 PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nPrint Txvref Byte%2d 2D Scan log\r\n",ByteIndex));
                       
						for (TxVrefIndex = TXVREF_INDEX_BEGIN; TxVrefIndex < TXVREF_INDEX_END; TxVrefIndex++)
                        {
                        	PEI_DEBUG((PeiServices, EFI_D_ERROR, "S18 Rank%02x Byte%02x ", RankIndex, ByteIndex));
                            Print_Index =Show_Info[TxVrefCenter[RankIndex][ByteIndex]][ByteIndex].DQO_LOW - 0x10;
                            while (Print_Index < Show_Info[TxVrefIndex][ByteIndex].DQO_LOW)
                            {
                                PEI_DEBUG((PeiServices, EFI_D_ERROR, "_"));
                                Print_Index++;
                            }
                            while (Print_Index < Show_Info[TxVrefIndex][ByteIndex].DQO_HIGH)
                            {
                                PEI_DEBUG((PeiServices, EFI_D_ERROR, "O"));
                                Print_Index++;
                            }
                       		 while (Print_Index < (Show_Info[TxVrefCenter[RankIndex][ByteIndex]][ByteIndex].DQO_HIGH+0x20))
                            {
                                PEI_DEBUG((PeiServices, EFI_D_ERROR, "_"));
                                Print_Index++;
                            }

                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "  TxVrefIndex = %0x, TxVrefRange = %0x, TxVrefValue = %0x, DQO_LOW = %02x  DQO_HIGH = %02x    ",
                                       TxVrefIndex, ((TxVrefTable[TxVrefIndex] & 0x40) >> 6) + 1, TxVrefTable[TxVrefIndex] & 0x3F, Show_Info[TxVrefIndex][ByteIndex].DQO_LOW, Show_Info[TxVrefIndex][ByteIndex].DQO_HIGH));
                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
                        }
                    }
				}
                else
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Showing Selecting Byte %0x!!!\r\n", ShowLogByte));
                    if (ShowLogByte >= ((ECC_ENABLE) ? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)))
                    {
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "Byte error!!!\r\n"));
                    }

                    for (TxVrefIndex = TXVREF_INDEX_BEGIN; TxVrefIndex < TXVREF_INDEX_END; TxVrefIndex++)
                    {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "S18 Rank%02x Byte%02x ", RankIndex,ShowLogByte));
                        Print_Index = Show_Info[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER][0].DQO_LOW - 0x10;
                        while (Print_Index < Show_Info[TxVrefIndex][ShowLogByte].DQO_LOW)
                        {
                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "_"));
                            Print_Index++;
                        }
                        while (Print_Index < Show_Info[TxVrefIndex][ShowLogByte].DQO_HIGH)
                        {
                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "O"));
                            Print_Index++;
                        }
                        while (Print_Index < (Show_Info[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER][0].DQO_HIGH+0x20))
                        {
                            PEI_DEBUG((PeiServices, EFI_D_ERROR, "_"));
                            Print_Index++;
                        }

                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "  TxVrefIndex = %0x TxVrefRange = %0x TxVrefValue = %0x DQO_LOW = %02x  DQO_HIGH = %02x ",
                                   TxVrefIndex, ((TxVrefTable[TxVrefIndex] & 0x40) >> 6) + 1, TxVrefTable[TxVrefIndex] & 0x3F, Show_Info[TxVrefIndex][ShowLogByte].DQO_LOW, Show_Info[TxVrefIndex][ShowLogByte].DQO_HIGH));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
                    }
                }
			
				PEI_DEBUG((PeiServices, EFI_D_INFO, "S19 Rank%2x TxVref Value is TxVrefIndex = %0x TxVrefRange = %0x TxVrefValue = %0x ",
											RankIndex, DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER, ((TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER]&0x40)>>6) + 1, TxVrefTable[DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER]&0x3F));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n")); 
            } //end show info
        }
    }
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "End TxVref Calibration...\r\n"));
}




/************************************
**                                                               
**  Rxvref calibration code
**                                                                
**************************************/



UINT16 RxVref_CHA_RxVreff[ASIA_MAX_BYTES] =
{
	D0F3_VREF_CTL_A0_CHN_A,
	D0F3_VREF_CTL_A1_CHN_A,
	D0F3_VREF_CTL_A2_CHN_A,
	D0F3_VREF_CTL_A3_CHN_A,
	D0F3_VREF_CTL_A4_CHN_A,
	D0F3_VREF_CTL_A5_CHN_A,
	D0F3_VREF_CTL_A6_CHN_A,
	D0F3_VREF_CTL_A7_CHN_A,
	D0F3_VREF_CTL_A8_CHN_A
};

UINT16 RxVref_CHB_RxVreff[ASIA_MAX_BYTES] =
{
	D0F3_VREF_CTL_B0_CHN_B,
	D0F3_VREF_CTL_B1_CHN_B,
	D0F3_VREF_CTL_B2_CHN_B,
	D0F3_VREF_CTL_B3_CHN_B,
	D0F3_VREF_CTL_B4_CHN_B,
	D0F3_VREF_CTL_B5_CHN_B,
	D0F3_VREF_CTL_B6_CHN_B,
	D0F3_VREF_CTL_B7_CHN_B,
	D0F3_VREF_CTL_B8_CHN_B
};

UINT16 RXDIO_Control_Register_CHA[ASIA_MAX_BYTES] =
{
	D0F3_RXDIO_CTL_REG_A0_CHN_A,
	D0F3_RXDIO_CTL_REG_A1_CHN_A,
	D0F3_RXDIO_CTL_REG_A2_CHN_A,
	D0F3_RXDIO_CTL_REG_A3_CHN_A,
	D0F3_RXDIO_CTL_REG_A4_CHN_A,
	D0F3_RXDIO_CTL_REG_A5_CHN_A,
	D0F3_RXDIO_CTL_REG_A6_CHN_A,
	D0F3_RXDIO_CTL_REG_A7_CHN_A,
	D0F3_RXDIO_CTL_REG_A8_CHN_B
};
UINT16 RXDIO_Control_Register_CHB[ASIA_MAX_BYTES] =
{
	D0F3_RXDIO_CTL_REG_B0_CHN_B,
	D0F3_RXDIO_CTL_REG_B1_CHN_B,
	D0F3_RXDIO_CTL_REG_B2_CHN_B,
	D0F3_RXDIO_CTL_REG_B3_CHN_B,
	D0F3_RXDIO_CTL_REG_B4_CHN_B,
	D0F3_RXDIO_CTL_REG_B5_CHN_B,
	D0F3_RXDIO_CTL_REG_B6_CHN_B,
	D0F3_RXDIO_CTL_REG_B7_CHN_B,
	D0F3_RXDIO_CTL_REG_B8_CHN_B
};

//RX Vref Related
VOID Rx_Set_TNI_WholeT(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT16 TNITemp,
	IN UINT8 RankIndex)
{
//	UINT16  Value16 = 0x10;
	UINT8   ByteIndex = 0;
	BOOLEAN ECC_ENABLE = FALSE;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	for(ByteIndex = 0; ByteIndex <((ECC_ENABLE)?ASIA_MAX_BYTES:ASIA_MAX_BYTES-1);ByteIndex++) 
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x** ",TNITemp));		
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &TNITemp);


	}
	

}

VOID Rx_Vref_SetVal_ByByte(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 RxVrefValue[],//bit0 -> bit7
	IN UINT8 VrefMode)
{
	UINT8 BitIndex = 0;
	UINT32 RXVREFF = 0;
	UINT64 Address = 0;

	//need check rxvrefvalue?? 
	//all rxvref seting upper 4bit should be same

	for(BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)	
	{
		RXVREFF |= (Binary2Gray(RxVrefValue[BitIndex]) & 0x0F)<<(BitIndex*4);
	}
	if(RankIndex < 4)//CHA	
	{
		//rxvreff 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex]);
		AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, RXVREFF);
		//rxvrefc all 8 bit should use same VREFC
		if(VrefMode == VREF_FINE_MODE){
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x04);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3F, (Binary2Gray(RxVrefValue[0])&0xF0)>>4);	
		}
		else{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x04);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3E, ((Binary2Gray(RxVrefValue[0])&0xF0)>>4)<<1);	
		}

	}
	else
	{
		//rxvreff 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex]);
		AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, RXVREFF);
		//rxvrefc all 8 bit should use same VREFC
		if(VrefMode == VREF_FINE_MODE){
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x04);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3F, (Binary2Gray(RxVrefValue[0])&0xF0)>>4);
		}
		else{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x04);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3E, ((Binary2Gray(RxVrefValue[0])&0xF0)>>4)<<1);
		}
	}
}

VOID Rx_Vref_SetVal_ByBit_WholeByte(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 RxVrefValue)//bit0 -> bit7
{
	UINT8 BitIndex = 0;
	UINT32 RXVREFF = 0;
	UINT64 Address = 0;

	//need check rxvrefvalue?? 
	//all rxvref seting upper 4bit should be same
	Internal_VREF_Range_Select(DramAttr, RankIndex, ByteIndex, RxVrefValue); 

	for(BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)	
	{
		RXVREFF |= (Binary2Gray(RxVrefValue) & 0x0F)<<(BitIndex*4);
	}
	if(RankIndex < 4)//CHA	
	{
		//rxvreff 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex]);
		AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, RXVREFF);
		//rxvrefc 
		//all 8 bit should use same VREFC VREFC_Ax_CTRLL
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x04);
		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3F, (Binary2Gray(RxVrefValue)&0xF0)>>4);
		//VREFC_Ax_CTRLH
//		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x05);
//		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3F, (Binary2Gray(RxVrefValue)&0xF0)>>4);
	}
	else
	{
		//rxvreff 
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex]);
		AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, RXVREFF);
		//rxvrefc 
		//all 8 bit should use same VREFC VREFC_A0_CTRLL
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x04);
		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3F, (Binary2Gray(RxVrefValue)&0xF0)>>4);
		//VREFC_Bx_CTRLH
//		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x05);
//		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x3F, (Binary2Gray(RxVrefValue)&0xF0)>>4);
	}
}



UINT8 Rx_Vref_GetVal(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 BitIndex)
{

	UINT64 Address = 0;
	UINT8 VREFF;
	UINT8 VREFC;
	UINT8 VrefMode;
	
	if(RankIndex<4){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHA[ByteIndex]);
		VrefMode = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_VREF_MODE_A0)>>10;
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex]);
		VREFF = (UINT8)((AsiaPcieRead32(DramAttr->PcieBaseAddress, Address)&(0XF<<(BitIndex*4)))>>(BitIndex*4));
		//ReadOut VREFC
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x04);
		if(VrefMode == VREF_FINE_MODE){
			VREFC = (UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0xF);
		}
		else{
			VREFC = (UINT8)((AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0xF)>>1);
		}

	}
	else{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHB[ByteIndex]);
		VrefMode = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_VREF_MODE_B0)>>10;
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex]);
		VREFF = (UINT8)((AsiaPcieRead32(DramAttr->PcieBaseAddress, Address)&(0XF<<(BitIndex*4)))>>(BitIndex*4));
		//ReadOut VREFC
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x04);
		if(VrefMode == VREF_FINE_MODE){
			VREFC = (UINT8)(AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0xF);
		}
		else{
			VREFC = (UINT8)((AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0xF)>>1);
		}

	}
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Rx_Vref_GetVal %x",Gray2Binary((VREFC<<4)|VREFF)));
	return Gray2Binary((VREFC<<4)|VREFF); 
}
//set the same rxvref value for a rank
VOID Rx_Vref_SetVal(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 RxVrefValue,
		IN UINT8 VrefMode)
{
	UINT8 RxVrefValue_Byte[8]={0};
	UINT8 BitIndex = 0;
	UINT8 ByteIndex = 0;
	BOOLEAN ECC_ENABLE = FALSE;

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	Internal_VREF_Range_Select(DramAttr, RankIndex, ByteIndex, RxVrefValue); 
	for( ByteIndex = 0; ByteIndex< (ECC_ENABLE ? ASIA_MAX_BYTES: (ASIA_MAX_BYTES-1)); ByteIndex++)
	{
		for(BitIndex = 0; BitIndex<8; BitIndex++)
			RxVrefValue_Byte[BitIndex] = RxVrefValue;
		//set same rxvrefvalue in a byte
		Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex,&RxVrefValue_Byte[0],VrefMode);
	}
}



VOID SaveRestoreRxVref(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN	Save,
	IN OUT struct RxVref_Register_Setting *SaveByte)
{
	UINT8 ByteIndex = 0;
	UINT64 Address = 0;

	//save all byte rxvref setting include ecc byte
	if(Save == TRUE)
	{
		//CHA
		for( ByteIndex = 0; ByteIndex<  ASIA_MAX_BYTES; ByteIndex++)
		{
			//readout VREFF
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex]);
			SaveByte[ByteIndex].VREFF = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
			//ReadOut VREFC
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x04);
			SaveByte[ByteIndex].VREFC = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}
		//CHB
		for( ByteIndex = 0; ByteIndex< ASIA_MAX_BYTES; ByteIndex++)
		{
			//readout VREFF
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex]);
			SaveByte[ByteIndex + ASIA_MAX_BYTES].VREFF = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
			//ReadOut VREFC
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x04);
			SaveByte[ByteIndex + ASIA_MAX_BYTES].VREFC = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}
	}else
	{
		//CHA
		for( ByteIndex = 0; ByteIndex<  ASIA_MAX_BYTES; ByteIndex++)
		{
			//restore VREFF
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex]);
			AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address,SaveByte[ByteIndex].VREFF);
			//restore VREFC
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHA_RxVreff[ByteIndex] + 0x04);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , VREFC_MASK, SaveByte[ByteIndex].VREFC);
		}
		//CHB
		for( ByteIndex = 0; ByteIndex< ASIA_MAX_BYTES; ByteIndex++)
		{
			//restore VREFF
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex]);
			AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address,SaveByte[ByteIndex + ASIA_MAX_BYTES].VREFF);
			//restore VREFC
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RxVref_CHB_RxVreff[ByteIndex] + 0x04);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , VREFC_MASK, SaveByte[ByteIndex + ASIA_MAX_BYTES].VREFC);
		}
	}

}

//Base on  pRxVref_Start find the spec range 
//if not find return -1
INT8 Get_Rxvref_DQSI_Range(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 ByteIndex,
		IN UINT8 BitIndex,
		IN UINT8 RxVrefIndex,
		IN UINT8 Edge,  //pos or neg
		IN struct RxVref_Result *pRxVref_Start)
{
	do{
		if(pRxVref_Start->RankIndex == RankIndex && pRxVref_Start->RxVrefValue == RxVrefIndex)
		{
			return pRxVref_Start->DQSIRange[RankIndex][BitIndex][Edge];
		}
		pRxVref_Start = pRxVref_Start->next;
	} while(pRxVref_Start->next != NULL);

	return -1;
}

//Base on  pRxVref_Start  Find the Vref whose DQSI Range is Largest & show rxvref log
VOID CalVrefDqsi(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RxVrefStart,
		IN UINT8 RxVrefEnd,
		IN UINT8 RxVrefStep,
		IN struct RxVref_Result *pRxVref_Start)
{
	//example code
	/*Get_Rxvref_DQSI_Range(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, BitIndex, RxVrefStart, posedge, pRxVref_Start);*/
}

#ifdef PRINT_RX_EYE
VOID Rx_VrefDQSI_Cal_Print_Rx_Eye(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN BOOLEAN ECC_ENABLE,
	IN DQSI_Vref *pRxVref_Start,
	IN OUT UINT8 (*RxVref_PerBit)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Infs)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Sups)[ASIA_MAX_BYTES][ASIA_MAX_BIT],	
	IN UINT8 BlockNum,
	IN UINT16 Cal_Byte){

	UINT8 ByteIndex = 0;
	UINT8 BitIndex = 0;
	UINT8 DQSI_High = 0;
	UINT8 DQSI_Low = 0;
	UINT8 Print_Index = 0;
	UINT8 edge = 0;
	UINT8 DQSI_High_Pos = 0;
	UINT8 DQSI_Low_Pos = 0;
	UINT8 DQSI_High_Neg = 0;
	UINT8 DQSI_Low_Neg = 0;
	UINT8 Overlap_Low = 0;
	UINT8 Overlap_High = 0;
	DQSI_Vref *pBlock = NULL;

	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nS1A[RankIndex][ByteIndex][BitIndex][Edge]"));

	for (ByteIndex = RXEYE_PRINT_BYTE_BEG; ByteIndex < RXEYE_PRINT_BYTE_END; ByteIndex++){
		if(Cal_Byte & (1<<ByteIndex)){
			for(BitIndex = RXEYE_PRINT_BIT_BEG; BitIndex < RXEYE_PRINT_BIT_END; BitIndex++){
				for(edge =0; edge<RXVREF_POS_NEG_EYE; edge++)
				{	
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n ByteIndex = %x  BitIndex = %x ",ByteIndex,BitIndex));
					if(edge == 1)
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n POS"));
					else
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n NEG"));	
					for(pBlock = pRxVref_Start;pBlock < (pRxVref_Start+BlockNum);pBlock++){
						DQSI_Low = pBlock->DQSIRange[ByteIndex][BitIndex][edge] & 0xFF;				// High 8 bits indicate high; low 8 bits indicate low.
						DQSI_High = (pBlock->DQSIRange[ByteIndex][BitIndex][edge]&0xFF00) >> 8;
						
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\nS1A[%x][%x][%x]",RankIndex,ByteIndex,BitIndex));
						if(edge == 1)
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x] : ",edge));
						else
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x] : ",edge));
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "RxVref = %02x  DQSI_LOW = %02x  DQSI_HIGH = %02x  ",pBlock->RxVrefValue,DQSI_Low,DQSI_High));	
						Print_Index = 0;
						while(Print_Index < DQSI_Low)	
						{
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "-")); 
							Print_Index ++ ;
						}
						while(Print_Index < DQSI_High)	
						{
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "0")); 
							Print_Index ++ ;
						}
						while(Print_Index <0x40 )	
						{
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "-")); 
							Print_Index ++ ;
						} 					
					}
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n\r\n Rank%02x Byte%02x Bit%02x InfsVref = 0x%02x SupsVref = 0x%02x RxVref = 0x%02x ",
													RankIndex,ByteIndex,BitIndex,
													RxVref_PerBit_Infs[RankIndex][ByteIndex][BitIndex],
													RxVref_PerBit_Sups[RankIndex][ByteIndex][BitIndex],
													RxVref_PerBit[RankIndex][ByteIndex][BitIndex]));
				for(pBlock = pRxVref_Start;pBlock < (pRxVref_Start+BlockNum);pBlock++){
					DQSI_Low_Pos   = pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0XFF;
					DQSI_High_Pos  = (pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0xFF00) >> 8;
					DQSI_Low_Neg   = pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0XFF;
					DQSI_High_Neg  = (pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0xFF00) >> 8;
					
					if((DQSI_High_Pos < DQSI_Low_Neg) || (DQSI_High_Neg < DQSI_Low_Pos)){
						Overlap_Low  = 0;
						Overlap_High = 0;
					}
					else{
						Overlap_Low  = DQSI_Low_Pos > DQSI_Low_Neg ? DQSI_Low_Pos : DQSI_Low_Neg;
						Overlap_High = DQSI_High_Pos > DQSI_High_Neg ? DQSI_High_Neg : DQSI_High_Pos;
					}
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref = 0x%02x  DQSI_LOW = 0x%02x  DQSI_HIGH = 0x%02x  ",pBlock->RxVrefValue,Overlap_Low,Overlap_High));	
					Print_Index = 0;
					while(Print_Index < Overlap_Low)	
					{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "-")); 
						Print_Index ++ ;
					}
					while(Print_Index < Overlap_High)	
					{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "0")); 
						Print_Index ++ ;
					}
					while(Print_Index <0x40 )	
					{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "-")); 
						Print_Index ++ ;
					} 
				}	 
			}		
		}
	}
}	
#endif

/********************************************************************************
 * The best per bit rxvref value will store in:
 * RxVref_PerBit[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT]
 * 
 * 1. Temporarily select according DQSI POS range per bit.
 * 2. Sanity check vref distance within one byte.
 * 3. need to save the low or high to print eye???
 * *****************************************************************************/
VOID Select_RxVref_From_Rx_Eye(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN BOOLEAN ECC_ENABLE,
	IN DQSI_Vref *RxVref_Start,
	IN OUT UINT8 (*RxVref_PerBit)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Infs)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Sups)[ASIA_MAX_BYTES][ASIA_MAX_BIT],	
	IN UINT8 BlockNum,
	IN UINT16 Cal_Byte){

	UINT8 ByteIndex = 0;
	UINT8 BitIndex = 0;

	DQSI_Vref *pMaxResult[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	DQSI_Vref *pSupSResult[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	DQSI_Vref *pInfSResult[ASIA_MAX_BYTES][ASIA_MAX_BIT];

	DQSI_Vref *pBlock = NULL;

	UINT8 JitterRangeCnt = 0;
	UINT8 JitterCnt = 0;

	UINT8 VrefMax = 0x0;
	UINT8 VrefMin = 0xFF;
	UINT8 SupSVreftemp = 0x0;
	UINT8 InfsVreftemp = 0x0;

	UINT8 RangeMax[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	UINT8 RxVrefOverlap[ASIA_MAX_BYTES][ASIA_MAX_BIT];

	UINT8 DQSI_High_Pos = 0;
	UINT8 DQSI_Low_Pos = 0;
	UINT8 DQSI_High_Neg = 0;
	UINT8 DQSI_Low_Neg = 0;
	UINT8 Overlap_Range = 0;

	pBlock = RxVref_Start;

	(*PeiServices)->SetMem(RangeMax, sizeof(RangeMax), 0);
	(*PeiServices)->SetMem(RxVrefOverlap, sizeof(RxVrefOverlap), 0);
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Select RxVref From Rx_Eye Begin\r\n")); 

	//initialize the pointers
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
			pMaxResult[ByteIndex][BitIndex] = RxVref_Start; 
			pSupSResult[ByteIndex][BitIndex] = RxVref_Start;
			pInfSResult[ByteIndex][BitIndex] = RxVref_Start;

		}		
	}
	// loop all value for biggest dqsi range, MAXRangePOS points to POS,MAXRangeNEG points to NEG.
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(Cal_Byte & (1<<ByteIndex)){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				for(pBlock = RxVref_Start;pBlock < (RxVref_Start + BlockNum);pBlock++){
					DQSI_Low_Pos   = pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0XFF;
					DQSI_High_Pos  = (pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0xFF00) >> 8;
					DQSI_Low_Neg   = pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0XFF;
					DQSI_High_Neg  = (pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0xFF00) >> 8;
					if((DQSI_High_Pos < DQSI_Low_Neg) || (DQSI_High_Neg < DQSI_Low_Pos)){
						Overlap_Range = 0;
					}
					else{
						Overlap_Range = (DQSI_High_Pos>DQSI_High_Neg?DQSI_High_Neg:DQSI_High_Pos) - (DQSI_Low_Pos>DQSI_Low_Neg?DQSI_Low_Pos:DQSI_Low_Neg);
					}				
					if(Overlap_Range > RangeMax[ByteIndex][BitIndex]){
						RangeMax[ByteIndex][BitIndex] = Overlap_Range;					
						pMaxResult[ByteIndex][BitIndex] = pBlock;				
					}		
				}
				if(RangeMax[ByteIndex][BitIndex] == 0x0){
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Rank%02x Byte%02X Bit%02x vref calibration Fail\r\n",RankIndex,ByteIndex,BitIndex));
					CalErrorReboot(PeiServices, DramAttr, IO_RXVREF); 
				}
			}
		}
	}
	// look backward to find supS
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(Cal_Byte & (1<<ByteIndex)){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				JitterRangeCnt = 0;
				JitterCnt = 0;
				for(pBlock = pMaxResult[ByteIndex][BitIndex];pBlock >= RxVref_Start; pBlock--){
					DQSI_Low_Pos   = pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0XFF;
					DQSI_High_Pos  = (pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0xFF00) >> 8;
					DQSI_Low_Neg   = pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0XFF;
					DQSI_High_Neg  = (pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0xFF00) >> 8;
					if((DQSI_High_Pos < DQSI_Low_Neg) || (DQSI_High_Neg < DQSI_Low_Pos)){
						Overlap_Range = 0;
					}
					else{
						Overlap_Range = (DQSI_High_Pos>DQSI_High_Neg?DQSI_High_Neg:DQSI_High_Pos) - (DQSI_Low_Pos>DQSI_Low_Neg?DQSI_Low_Pos:DQSI_Low_Neg);
					}
					if(Overlap_Range + DQSI_VREF_THRESHOLD >= RangeMax[ByteIndex][BitIndex]){
						if(Overlap_Range<RangeMax[ByteIndex][BitIndex]){
							JitterCnt++;
						}
						else if(Overlap_Range == RangeMax[ByteIndex][BitIndex]){
							JitterCnt = 0;
						}
						JitterRangeCnt = 0;
						pSupSResult[ByteIndex][BitIndex] = pBlock;
						if(JitterCnt >= 3){
							break;
						}				
					}
					else{
						JitterRangeCnt += 1;
						if(JitterRangeCnt >= DQSI_VREF_CONTINUOUS_STEP){
							break;
						}
					}
				}
			}
		}
	}
	// look forward to find infS
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(Cal_Byte & (1<<ByteIndex)){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				JitterRangeCnt = 0;
				JitterCnt = 0;			
				for(pBlock = pMaxResult[ByteIndex][BitIndex];pBlock < (RxVref_Start + BlockNum);pBlock++){
					DQSI_Low_Pos   = pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0XFF;
					DQSI_High_Pos  = (pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0xFF00) >> 8;
					DQSI_Low_Neg   = pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0XFF;
					DQSI_High_Neg  = (pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0xFF00) >> 8;
					if((DQSI_High_Pos < DQSI_Low_Neg) || (DQSI_High_Neg < DQSI_Low_Pos)){
						Overlap_Range = 0;
					}
					else{
						Overlap_Range = (DQSI_High_Pos>DQSI_High_Neg?DQSI_High_Neg:DQSI_High_Pos) - (DQSI_Low_Pos>DQSI_Low_Neg?DQSI_Low_Pos:DQSI_Low_Neg);
					}
					if(Overlap_Range + DQSI_VREF_THRESHOLD >= RangeMax[ByteIndex][BitIndex]){
						if(Overlap_Range<RangeMax[ByteIndex][BitIndex]){
							JitterCnt++;
						}
						else if(Overlap_Range == RangeMax[ByteIndex][BitIndex]){
							JitterCnt = 0;
						}
						JitterRangeCnt = 0;
						pInfSResult[ByteIndex][BitIndex] = pBlock;
						if(JitterCnt >= 3){
							break;
						}
					}
					else{
						JitterRangeCnt += 1;
						if(JitterRangeCnt >= DQSI_VREF_CONTINUOUS_STEP){
							break;
						}
					}
				}
			}	
		}
	}
	// calculate the final rxvref.
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(Cal_Byte & (1<<ByteIndex)){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				SupSVreftemp = pSupSResult[ByteIndex][BitIndex]->RxVrefValue;
				InfsVreftemp = pInfSResult[ByteIndex][BitIndex]->RxVrefValue;
				RxVref_PerBit_Infs[RankIndex][ByteIndex][BitIndex] = InfsVreftemp;
				RxVref_PerBit_Sups[RankIndex][ByteIndex][BitIndex] = SupSVreftemp;
				RxVrefOverlap[ByteIndex][BitIndex] = (UINT8)(((UINT16)SupSVreftemp + (UINT16)InfsVreftemp)/2);
				pBlock=pSupSResult[ByteIndex][BitIndex]+(UINT8)(((UINT16)SupSVreftemp - (UINT16)InfsVreftemp)/2);
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW=(UINT8)pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0XFF;
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH=(UINT8)((pBlock->DQSIRange[ByteIndex][BitIndex][POS] & 0XFF00)>>8);
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW=(UINT8)pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0XFF;
				DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH=(UINT8)((pBlock->DQSIRange[ByteIndex][BitIndex][NEG] & 0XFF00)>>8);
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Byte%x Bit%x SupSVreftemp 0x%x InfsVreftemp 0x%x RxVrefOverlap 0x%x",ByteIndex,BitIndex,SupSVreftemp,InfsVreftemp,RxVrefOverlap[ByteIndex][BitIndex]));		
			}	
		}
	}
	//sanity check for diff within one byte and output vref value per bit.
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(Cal_Byte & (1<<ByteIndex)){
			VrefMax = 0x0;
			VrefMin = 0xFF;
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				if(RxVrefOverlap[ByteIndex][BitIndex] > VrefMax){
					VrefMax = RxVrefOverlap[ByteIndex][BitIndex];
				}
				if(RxVrefOverlap[ByteIndex][BitIndex] < VrefMin){
					VrefMin = RxVrefOverlap[ByteIndex][BitIndex];
				}
				RxVref_PerBit[RankIndex][ByteIndex][BitIndex] = RxVrefOverlap[ByteIndex][BitIndex];// use POS&NEG overlap.						
			}
			if((VrefMax - VrefMin)>0x10){ //within one byte the rxvref should not exceed 0x10.
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n DQSI Byte %x  vref over coarse limmit = 0x%2x ",ByteIndex,VrefMax - VrefMin));			
			}
		}	
	}
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Select RxVref From Rx_Eye End\r\n")); 
}

//0.12-0.3v   0.3-0.6v     0.6-0.9v   0.9-1.08v
//                 0xf          0x51
//  							
VOID Internal_VREF_Range_Select(IN DRAM_ATTRIBUTE *DramAttr,UINT8 RankIndex,UINT8 ByteIndex, UINT8 VrefIndex){
	
	UINT64 Address;
	UINT8 OverlapMode = 0;
	UINT8 range1 = 0;
	UINT8 range2 = 0;
	UINT8 CoarseMode = 0;

	if(RankIndex<4){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHA[ByteIndex]);
		OverlapMode = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_VREF_OVERLAP_A0)>>9;
		CoarseMode = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_VREF_MODE_A0)>>10;			
	}
	else{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHB[ByteIndex]);
		OverlapMode = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_VREF_OVERLAP_A0)>>9;
		CoarseMode = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_VREF_MODE_B0)>>10; 
	}

	if(RankIndex<4){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_A0_CHN_A_Z1);
	}
	else{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_B0_CHN_B_Z1);
	}
	if(CoarseMode){
		if(OverlapMode){
			range1 = 0x18;
			range2 = 0x39;
		}
		else{
			range1 = 0x10;
			range2 = 0x31;
		}
	}
	else{
		if(OverlapMode){
			range1 = 0x17;
			range2 = 0x58;
		}
		else{
			range1 = 0x0F;
			range2 = 0x50;
		}
	}
	if(VrefIndex < range1){	
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , D0F3_RXMODE_1_0_A, 0x03<<8); //select range 1
	}
	else if(VrefIndex < range2){
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , D0F3_RXMODE_1_0_A, 0x03<<8); //select range 2
	}
	else{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , D0F3_RXMODE_1_0_A, 0x03<<8); //select range 3
	}
}

VOID Vref_Range_Select_For_Cal(IN DRAM_ATTRIBUTE *DramAttr,UINT8 RankIndex, UINT8 VrefIndex, UINT8 VrefMode){
	
	UINT64 Address;
	UINT8 range1 = 0;
	UINT8 range2 = 0;

	if(RankIndex<4){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_A0_CHN_A_Z1);
	}
	else{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_B0_CHN_B_Z1);

	}
	if(VrefMode == VREF_COARSE_MODE){
		range1 = 0x10;
		range2 = 0x31;
	}
	else{
		range1 = 0x0F;
		range2 = 0x50;
	}
	if(VrefIndex < range1){		
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , D0F3_RXMODE_1_0_A, 0x03<<8); //select range 1
	}
	else if(VrefIndex < range2){
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , D0F3_RXMODE_1_0_A, 0x03<<8); //select range 2
	}
	else{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address , D0F3_RXMODE_1_0_A, 0x03<<8); //select range 3
	}
}


VOID SetVrefRange(
	IN EFI_PEI_SERVICES **PeiServices,
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
	#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
	#endif
	IN DRAM_ATTRIBUTE *DramAttr){

	UINT8 VrefIndex;
	UINT8 RankIndex;
	UINT8 ByteIndex;
	UINT8 BitIndex;
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n SetVrefRange"));
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F){
		RankIndex = 0;
		ByteIndex = 0;
		BitIndex = 0;
		VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,RankIndex,ByteIndex,BitIndex);//rank0 byte0 
		Internal_VREF_Range_Select(DramAttr, RankIndex, ByteIndex,VrefIndex);
	}
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0){
		RankIndex = 4;
		ByteIndex = 0;
		BitIndex = 0;
		VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,RankIndex,ByteIndex,BitIndex);//rank4 byte0	
		Internal_VREF_Range_Select(DramAttr, RankIndex, ByteIndex,VrefIndex);
	}
}



VOID Enable_Disable_Vref_Overlap(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN BOOLEAN Status){

	UINT64 Address = 0;

	if(RankIndex < 4){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Enalbe CHA Byte%2X Vref Overlap",ByteIndex));
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHA[ByteIndex]);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_OVERLAP_A0, ShiftToMaskBit(D0F3_VREF_OVERLAP_A0,Status));	
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_OVERLAP_A0_TEST, ShiftToMaskBit(D0F3_VREF_OVERLAP_A0_TEST,Status));		
	}
	else{
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Enalbe CHB Byte%2X Vref Overlap",ByteIndex));
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHB[ByteIndex]);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_OVERLAP_B0, ShiftToMaskBit(D0F3_VREF_OVERLAP_B0,Status));
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_OVERLAP_B0_TEST, ShiftToMaskBit(D0F3_VREF_OVERLAP_B0_TEST,Status));		
	}
}

VOID Enable_Disable_Vref_Coarse_Mode(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN BOOLEAN Status){

	UINT64 Address = 0;

	if(RankIndex < 4){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHA[ByteIndex]);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_MODE_A0, ShiftToMaskBit(D0F3_VREF_MODE_A0,Status));			
	}
	else{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RXDIO_Control_Register_CHB[ByteIndex]);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_MODE_B0, ShiftToMaskBit(D0F3_VREF_MODE_B0,Status));	
	}
}

VOID Rx_Vref_ClearModeStatus(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr){

	UINT8 ByteIndex;

	for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES;ByteIndex++){
		Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,FALSE); // 0 indicate CHA.
		Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,FALSE); // 0 indicate CHA.
		Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,FALSE); // 4 indicate CHB.
		Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,FALSE); // 4 indicate CHB.	
	}
}

VOID VrefC_Sync_By_Mode_By_Byte(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN OUT UINT8 (*RxVref)[ASIA_MAX_BIT],
	IN UINT8 VrefMax[],
	IN UINT8 VrefMin[]){

	UINT8 cnt1 = 0;
	UINT8 cnt2 = 0;
	UINT8 bitcnt = 0;
	UINT8 BitIndex;
	UINT16 sum = 0;

	UINT8 VrefRange;

	VrefRange = VrefMax[ByteIndex] - VrefMin[ByteIndex];
	if(VrefRange > 0x10){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "  Over 16 Step",ByteIndex));
		//CalErrorReboot(PeiServices, DramAttr, IO_RXVREF);
	}
	for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
		if(RxVref[ByteIndex][0]>>4 == RxVref[ByteIndex][BitIndex]>>4){ 
			cnt1 += 1;// count the common with bit0 
			bitcnt |= 1<<BitIndex;	// the common with bit 0
			
		}
		else{
			cnt2 += 1;
		}
	}
	if(cnt1 != ASIA_MAX_BIT && cnt2 != ASIA_MAX_BIT ){
		if(VrefRange > 8){		
			if((VrefMax[ByteIndex]&0X0F) < 8 && (VrefMin[ByteIndex]&0x0F) >= 8 && VrefRange < 0x10){// case 2
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "  Over 8 Step  Enable Vref Overlap"));
				if(RankIndex<4){
					DramAttr->CHAOverlap |= 1<<ByteIndex;
				}
				else{
					DramAttr->CHBOverlap |= 1<<ByteIndex;
				}
			}
			else{
				//case 3&4.
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "  Enable Vref Coarse Mode"));
				if(RankIndex<4){
					if((DramAttr->CHACoarseMode & (1<<ByteIndex)) == 0){
						DramAttr->CHACoarseMode |= 1<<ByteIndex;
					}
					else{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "  Rank%02x Byte%02x Coarse Overlap Fail Calculate Average",RankIndex,ByteIndex));
						sum = 0;
						for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
							sum += RxVref[ByteIndex][BitIndex];
						}
						for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
							RxVref[ByteIndex][BitIndex] = (UINT8)(sum/ASIA_MAX_BIT);
						}
						//CalErrorReboot(PeiServices, DramAttr, IO_RXVREF);
					}
				}
				else{
					if((DramAttr->CHBCoarseMode & (1<<ByteIndex)) == 0){
						DramAttr->CHBCoarseMode |= 1<<ByteIndex;
					}
					else{
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "  Rank%02x Byte%02x Coarse Overlap Fail Calculate Average",RankIndex,ByteIndex));
						sum = 0;
						for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
							sum += RxVref[ByteIndex][BitIndex];
						}
						for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
							RxVref[ByteIndex][BitIndex] = (UINT8)(sum/ASIA_MAX_BIT);
						}
						//CalErrorReboot(PeiServices, DramAttr, IO_RXVREF);
					}					
				}
			}
		}
		else{
			//1. enable overlap 
			//2. add all bit value with 8
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "  Enable Vref Overlap"));//case1
			if(RankIndex<4){
				DramAttr->CHAOverlap |= 1<<ByteIndex;
			}
			else{
				DramAttr->CHBOverlap |= 1<<ByteIndex;
			}
		}
	}
}


VOID Check_VrefC_Within_Byte(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN OUT UINT8 (*RxVref_PerBit)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_CHA)[ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_CHB)[ASIA_MAX_BIT],
	IN UINT16 CHA_SettingByte,
	IN UINT16 CHB_SettingByte){

	UINT8 	channelflag = 0;
	INT8 	RankIndex;
	UINT8 	ByteIndex;
	UINT8 	BitIndex;
	UINT8 	RxVref_InfsCHA[ASIA_MAX_BYTES][ASIA_MAX_BIT] ;
	UINT8 	RxVref_SupsCHA[ASIA_MAX_BYTES][ASIA_MAX_BIT] ;

	UINT8 	RxVref_InfsCHB[ASIA_MAX_BYTES][ASIA_MAX_BIT] ;
	UINT8 	RxVref_SupsCHB[ASIA_MAX_BYTES][ASIA_MAX_BIT] ;

	UINT8 	CHAVrefMax[ASIA_MAX_BYTES];
	UINT8 	CHAVrefMin[ASIA_MAX_BYTES];
	UINT8 	CHBVrefMax[ASIA_MAX_BYTES];
	UINT8 	CHBVrefMin[ASIA_MAX_BYTES];
	UINT8 	CHAVrefRange[ASIA_MAX_BYTES];
	UINT8 	CHBVrefRange[ASIA_MAX_BYTES];

	(*PeiServices)->SetMem(RxVref_InfsCHA, sizeof(RxVref_InfsCHA), 0xFF);
	(*PeiServices)->SetMem(RxVref_SupsCHA, sizeof(RxVref_SupsCHA), 0x0);
	(*PeiServices)->SetMem(RxVref_InfsCHB, sizeof(RxVref_InfsCHB), 0xFF);
	(*PeiServices)->SetMem(RxVref_SupsCHB, sizeof(RxVref_SupsCHB), 0x0);
	(*PeiServices)->SetMem(CHAVrefMax, sizeof(CHAVrefMax), 0x0);
	(*PeiServices)->SetMem(CHAVrefMin, sizeof(CHAVrefMin), 0xFF);
	(*PeiServices)->SetMem(CHBVrefMax, sizeof(CHBVrefMax), 0x0);
	(*PeiServices)->SetMem(CHBVrefMin, sizeof(CHBVrefMin), 0xFF);
	(*PeiServices)->SetMem(CHAVrefRange, sizeof(CHAVrefRange), 0x0);
	(*PeiServices)->SetMem(CHBVrefRange, sizeof(CHBVrefRange), 0xFF);

	if(ECC_ENABLE){
		if(CHA_SettingByte == ALLBYTE){
			CHA_SettingByte = 0x1FF;
		}
		if(CHB_SettingByte == ALLBYTE){
			CHB_SettingByte = 0x1FF;
		}	
	}
	else{
		if(CHA_SettingByte == ALLBYTE){
			CHA_SettingByte = 0xFF;
		}
		if(CHB_SettingByte == ALLBYTE){
			CHB_SettingByte = 0xFF;
		}
	}

	// If enable "by channel",according the scan rank order to find the corresponding rank value.
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(CHA_SettingByte & (1<<ByteIndex)){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				// CHA_SettingByte fix conflict between Cal_RankPresent and DramAttr->RankPresent[DramAttr->AttrNo].
				for(RankIndex = ASIA_MAX_RANKS/2-1;RankIndex >= 0;RankIndex--){ //CHA
					channelflag = 0;
					if(DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)){ 
						if(RxVref_PerBit[RankIndex][ByteIndex][BitIndex] < RxVref_InfsCHA[ByteIndex][BitIndex]){
							RxVref_InfsCHA[ByteIndex][BitIndex] = RxVref_PerBit[RankIndex][ByteIndex][BitIndex];
						}
						if(RxVref_PerBit[RankIndex][ByteIndex][BitIndex] > RxVref_SupsCHA[ByteIndex][BitIndex]){
							RxVref_SupsCHA[ByteIndex][BitIndex] = RxVref_PerBit[RankIndex][ByteIndex][BitIndex];
						}
						channelflag = 1;
					}
					#ifdef RXVREF_BY_CHANNEL
						if(channelflag == 1)
							break;
					#endif
				}
				RxVref_CHA[ByteIndex][BitIndex] = (UINT8)(((UINT16)RxVref_InfsCHA[ByteIndex][BitIndex] + (UINT16)RxVref_SupsCHA[ByteIndex][BitIndex])/2);
			}
		}
	}
	//CHB 
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		if(CHB_SettingByte & (1<<ByteIndex)){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){			
				for(RankIndex = ASIA_MAX_RANKS-1;RankIndex >= ASIA_MAX_RANKS/2;RankIndex--){
					channelflag = 0;
					if(DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)){
						if(RxVref_PerBit[RankIndex][ByteIndex][BitIndex] < RxVref_InfsCHB[ByteIndex][BitIndex]){
							RxVref_InfsCHB[ByteIndex][BitIndex] = RxVref_PerBit[RankIndex][ByteIndex][BitIndex];
						}
						if(RxVref_PerBit[RankIndex][ByteIndex][BitIndex] > RxVref_SupsCHB[ByteIndex][BitIndex]){
							RxVref_SupsCHB[ByteIndex][BitIndex] = RxVref_PerBit[RankIndex][ByteIndex][BitIndex];
						}
						channelflag = 1;				
					}
					#ifdef RXVREF_BY_CHANNEL
						if(channelflag == 1)
							break;
					#endif
				}
				// Cal the rank (min+max)/2 average.
				RxVref_CHB[ByteIndex][BitIndex] = (UINT8)(((UINT16)RxVref_InfsCHB[ByteIndex][BitIndex] + (UINT16)RxVref_SupsCHB[ByteIndex][BitIndex])/2);
			}
		}		
	}

	// print CHA & CHB all per bit value
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F){
		for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
			if(CHA_SettingByte &(1<<ByteIndex)){
				for(RankIndex = 0;RankIndex < ASIA_MAX_RANKS/2;RankIndex++){
					if(DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref Rank%2x Byte%2x:",RankIndex,ByteIndex)); 
						for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
							PEI_DEBUG((PeiServices, EFI_D_ERROR, " %x",RxVref_PerBit[RankIndex][ByteIndex][BitIndex])); 
						}	 
					}
				}
			}
		}		
	}
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0){
		for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
			if(CHB_SettingByte &(1<<ByteIndex)){
				for(RankIndex = ASIA_MAX_RANKS/2;RankIndex < ASIA_MAX_RANKS;RankIndex++){
					if(DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref Rank%2x Byte%2x:",RankIndex,ByteIndex)); 
						for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
							PEI_DEBUG((PeiServices, EFI_D_ERROR, " %x",RxVref_PerBit[RankIndex][ByteIndex][BitIndex])); 
						}
					}
				}
			}
		}
	}
	// check vref with one byte
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref CHA Byte%2x:",ByteIndex));
		for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x",RxVref_CHA[ByteIndex][BitIndex]));
			if(RxVref_CHA[ByteIndex][BitIndex] > CHAVrefMax[ByteIndex]){
				CHAVrefMax[ByteIndex] = RxVref_CHA[ByteIndex][BitIndex];
			}
			if(RxVref_CHA[ByteIndex][BitIndex] < CHAVrefMin[ByteIndex]){
				CHAVrefMin[ByteIndex] = RxVref_CHA[ByteIndex][BitIndex];
			}
		}
		CHAVrefRange[ByteIndex] = CHAVrefMax[ByteIndex]-CHAVrefMin[ByteIndex];
		PEI_DEBUG((PeiServices, EFI_D_ERROR, " (%2x-%2x)%2x",CHAVrefMin[ByteIndex],CHAVrefMax[ByteIndex],CHAVrefRange[ByteIndex]));
		VrefC_Sync_By_Mode_By_Byte(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,RxVref_CHA,CHAVrefMax,CHAVrefMin);// rankindex = 0 indicate Channel A}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref CHB Byte%2x:",ByteIndex));
		for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " %2x",RxVref_CHB[ByteIndex][BitIndex]));
			if(RxVref_CHB[ByteIndex][BitIndex] > CHBVrefMax[ByteIndex]){
				CHBVrefMax[ByteIndex] = RxVref_CHB[ByteIndex][BitIndex];
			}
			if(RxVref_CHB[ByteIndex][BitIndex] < CHBVrefMin[ByteIndex]){
				CHBVrefMin[ByteIndex] = RxVref_CHB[ByteIndex][BitIndex];
			} 
		}
		CHBVrefRange[ByteIndex] = CHBVrefMax[ByteIndex]-CHBVrefMin[ByteIndex];
		PEI_DEBUG((PeiServices, EFI_D_ERROR, " (%2x-%2x)%2x",CHBVrefMin[ByteIndex],CHBVrefMax[ByteIndex],CHBVrefRange[ByteIndex]));
		VrefC_Sync_By_Mode_By_Byte(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,RxVref_CHB,CHBVrefMax,CHBVrefMin);// rankindex = 4 indicate Channel B		
	}
}





/************************************************************************************
 * Filter the data stored in:
 * RxVref_PerBit[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT]
 * 1. Get common range center if by rank.
 * 2. Convert to register format.
 * 3. Set Register.
 * 
 * **********************************************************************************/

VOID Rx_Vref_SetRegister(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN OUT UINT8 (*RxVref_CHA)[ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_CHB)[ASIA_MAX_BIT],
	IN UINT16 CHA_SettingByte,	
	IN UINT16 CHB_SettingByte){	

	UINT64	Address = 0;
	INT8 	RankIndex = 0;
	UINT8	ByteIndex = 0;
	UINT8	BitIndex  = 0;

	UINT8 	VrefByte[ASIA_MAX_BIT];//Byte vref temp value.

	if(ECC_ENABLE){
		if(CHA_SettingByte == ALLBYTE){
			CHA_SettingByte = 0x1FF;
		}
		if(CHB_SettingByte == ALLBYTE){
			CHB_SettingByte = 0x1FF;
		}	
	}
	else{
		if(CHA_SettingByte == ALLBYTE){
			CHA_SettingByte = 0xFF;
		}
		if(CHB_SettingByte == ALLBYTE){
			CHB_SettingByte = 0xFF;
		}
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Rx_Vref_SetRegister "));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n CHACoarseMode   = %x CHBCoarseMode   = %x ",DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n CHAOverlap      = %x CHBOverlap      = %x ",DramAttr->CHAOverlap,DramAttr->CHBOverlap));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n CHA_SettingByte = %x CHB_SettingByte = %x ",CHA_SettingByte,CHB_SettingByte));
	
	(*PeiServices)->SetMem(VrefByte, sizeof(VrefByte), 0x00);
	for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES;ByteIndex++){
		if(DramAttr->CHAOverlap & (1<<ByteIndex) && CHA_SettingByte & (1<<ByteIndex)){
			Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,TRUE); // 0 indicate CHA.
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				RxVref_CHA[ByteIndex][BitIndex] += 8;
			}
		}
		if(DramAttr->CHBOverlap & (1<<ByteIndex) && CHB_SettingByte &(1<<ByteIndex)){
			Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,TRUE); // 4 indicate CHB.
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				RxVref_CHB[ByteIndex][BitIndex] += 8;
			}
		}
	}


	for(ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref_CHA Byte%x",ByteIndex));
		for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " %x",RxVref_CHA[ByteIndex][BitIndex]));
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	for(ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref_CHB Byte%x",ByteIndex));
		for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " %x",RxVref_CHB[ByteIndex][BitIndex]));
		}
	}
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F){
		for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				VrefByte[BitIndex] = RxVref_CHA[ByteIndex][BitIndex];
			}
			if(DramAttr->CHACoarseMode & (1<<ByteIndex)){
				Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,VrefByte,VREF_COARSE_MODE);			
			}
			else{
				Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,VrefByte,VREF_FINE_MODE);
			}
		}
	}
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0){
		for (ByteIndex = 0; ByteIndex < ((ECC_ENABLE)? ASIA_MAX_BYTES : (ASIA_MAX_BYTES - 1)); ByteIndex++){
			for(BitIndex=0;BitIndex<ASIA_MAX_BIT;BitIndex++){
				VrefByte[BitIndex] = RxVref_CHB[ByteIndex][BitIndex];
			}			
			if(DramAttr->CHBCoarseMode & (1<<ByteIndex)){
				Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,VrefByte,VREF_COARSE_MODE);			
			}
			else{
				Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,VrefByte,VREF_FINE_MODE);
			}
		}
	}

	// set vref range select.
	for(RankIndex = 0;RankIndex < ASIA_MAX_RANKS/2;RankIndex++){
		if(DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref_CHA[0][0] = %x ",RxVref_CHA[0][0]));
			Internal_VREF_Range_Select(DramAttr, RankIndex, 0,RxVref_CHA[0][0]);// use byte 0 bit 0 vref to select the range.
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_A0_CHN_A_Z1);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n CHA Internal VREF Range Select = %x ",(AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_RXMODE_1_0_A)>>8));
			break;
		}
	}
	for(RankIndex = ASIA_MAX_RANKS/2;RankIndex < ASIA_MAX_RANKS;RankIndex++){
		if(DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref_CHB[0][0] = %x ",RxVref_CHB[0][0]));
			Internal_VREF_Range_Select(DramAttr, RankIndex, 0,RxVref_CHB[0][0]);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_B0_CHN_B_Z1);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n CHB Internal VREF Range Select = %x ",(AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_RXMODE_1_0_A)>>8));
			break;
		}
	}
	TriggerLoadReg(PeiServices, DramAttr);	
	
}


 
VOID LOOP_Vref_DO_DQSI_Calibration_Readpreamble(
	 IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 Cal_RankPresent,
	IN UINT8 RxVrefStep,
	IN UINT8 BlockNum,
	IN DQSI_Vref *RxVref_Start,
	IN OUT UINT8 (*RxVref_PerBit)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Infs)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Sups)[ASIA_MAX_BYTES][ASIA_MAX_BIT])
{

	INT8       RankIndex;
	UINT8      DqsiStep = 1; 
	UINT32     Default_MPR = 0xaa0F3355;
	UINT8   RxVrefStart = 50;
	UINT8	RxVrefEnd = 60;
	UINT8   RxVrefValue = 0;
	UINT8 	VrefIndex;
	UINT16 	Cal_Byte;
	UINT16 TNITempT;
	struct RxVref_Register_Setting Save_RxVref[2*ASIA_MAX_BYTES] ; //store CHA/B RXVREF Setting
	DQSI_Vref *pRxVref_Cal_Value = NULL;
	      switch (DramAttr->DramFreq)
       {

          case DRAM_FREQ_1600:
					TNITempT=4;
              break;

          case DRAM_FREQ_2133:
					TNITempT=5;
			  break;

		  case DRAM_FREQ_2400:
					TNITempT=6;
			  break;
		  case DRAM_FREQ_2666:
					TNITempT=7;
			  break;
		  case DRAM_FREQ_2933:
					TNITempT=8;
			  break;

		  case DRAM_FREQ_3200: 
					TNITempT=9;
			  break;				

			default:
					TNITempT=5;
			break;
	      	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n DramAttr->CHACoarseMode %x DramAttr->CHBCoarseMode %x ",DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n DramAttr->CHAOverlap    %x DramAttr->CHBOverlap    %x ",DramAttr->CHAOverlap,DramAttr->CHBOverlap));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Cal_RankPresent = 0x%02x ",Cal_RankPresent));
	for(RankIndex=ASIA_MAX_RANKS-1; RankIndex>=0; RankIndex--)//Rx vref use rank vref  
	{
		if (Cal_RankPresent & ( 1 << RankIndex)) 
		{
			Rx_Set_TNI_WholeT(PeiServices, pPCIPPI, DramAttr, TNITempT,RankIndex);
		
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Rx_Vref Calibration RankIndex = %x ",RankIndex));
			if(RankIndex < 4){
				VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,0,0,0);
			}
			else{
				VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,4,0,0);
			}
			if(DramAttr->CHACoarseMode == 0 && DramAttr->CHBCoarseMode == 0){ // Fine mode.
				RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI);
				RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;
				Cal_Byte = 0x1FF;
			}
			else{ 	// Coarse mode.
				RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x4F ? 0x4F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter.
				RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x8;
				if(RankIndex < 4){
					Cal_Byte = DramAttr->CHACoarseMode;
				}
				else{
					Cal_Byte = DramAttr->CHBCoarseMode;
				}
			}
			pRxVref_Cal_Value = RxVref_Start;  //initialize the Pool
			(*PeiServices)->SetMem(RxVref_Start, BlockNum*sizeof(DQSI_Vref), 0);
			SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, TRUE, &Save_RxVref[0]);  
			for(RxVrefValue = RxVrefEnd; RxVrefValue >= RxVrefStart; )
			{
				//Sets manual RX Vref value --same value: for all byte and select the range.
				if(DramAttr->CHACoarseMode == 0 && DramAttr->CHBCoarseMode == 0){
					Vref_Range_Select_For_Cal(DramAttr, RankIndex, RxVrefValue,VREF_FINE_MODE);
					Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex, RxVrefValue,VREF_FINE_MODE);
				}
				else{
					Vref_Range_Select_For_Cal(DramAttr, RankIndex, RxVrefValue,VREF_COARSE_MODE);
					Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex, RxVrefValue,VREF_COARSE_MODE);
				}
				TriggerLoadReg(PeiServices, DramAttr);
//				Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
				Rx_ReadPreamble_Training(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
				Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);
				Rx_DQSI_ReadLeveling_SaveRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, pRxVref_Cal_Value->DQSIRange);
				pRxVref_Cal_Value->RxVrefValue = RxVrefValue;
				pRxVref_Cal_Value++;
				RxVrefValue = RxVrefValue - RxVrefStep;
				if(RxVrefValue<RxVrefStep){
					break;
				}
			}
			SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, FALSE, &Save_RxVref[0]); 
			//Check range, show log and select a proper rxvref
			Select_RxVref_From_Rx_Eye(PeiServices, DramAttr, RankIndex, ECC_ENABLE, RxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups, BlockNum, Cal_Byte);			
		#ifdef PRINT_RX_EYE
			Rx_VrefDQSI_Cal_Print_Rx_Eye(PeiServices, DramAttr, RankIndex, ECC_ENABLE, RxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups, BlockNum, Cal_Byte);			
		#endif
			Rx_DQSI_SetRegister_byRank(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RankIndex);
		}
	}
}

 
VOID LOOP_Vref_DO_DQSI_Calibration(
	 IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN ECC_ENABLE,
	IN UINT8 Cal_RankPresent,
	IN UINT8 RxVrefStep,
	IN UINT8 BlockNum,
	IN DQSI_Vref *RxVref_Start,
	IN OUT UINT8 (*RxVref_PerBit)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Infs)[ASIA_MAX_BYTES][ASIA_MAX_BIT],
	IN OUT UINT8 (*RxVref_PerBit_Sups)[ASIA_MAX_BYTES][ASIA_MAX_BIT])
{

	INT8       RankIndex;
	UINT8      DqsiStep = 1; 
	UINT32     Default_MPR = 0xAA0F3355;
	UINT8   RxVrefStart = 50;
	UINT8	RxVrefEnd = 60;
	UINT8   RxVrefValue = 0;
	UINT8 	VrefIndex;
	UINT16 	Cal_Byte;
	UINT8 	Cnt = 0;
	struct RxVref_Register_Setting Save_RxVref[2*ASIA_MAX_BYTES] ; //store CHA/B RXVREF Setting
	DQSI_Vref *pRxVref_Cal_Value = NULL;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n DramAttr->CHACoarseMode %x DramAttr->CHBCoarseMode %x ",DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n DramAttr->CHAOverlap    %x DramAttr->CHBOverlap    %x ",DramAttr->CHAOverlap,DramAttr->CHBOverlap));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Cal_RankPresent = 0x%02x ",Cal_RankPresent));
	for(RankIndex=ASIA_MAX_RANKS-1; RankIndex>=0; RankIndex--)//Rx vref use rank vref  
	{
		if (Cal_RankPresent & ( 1 << RankIndex)) 
		{
		
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Rx_Vref Calibration RankIndex = %x ",RankIndex));
			if(RankIndex < 4){
				VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,0,0,0);
			}
			else{
				VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,4,0,0);
			}
			if(DramAttr->CHACoarseMode == 0 && DramAttr->CHBCoarseMode == 0){ // Fine mode.
				RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI);
				RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;
				Cal_Byte = 0x1FF;
			}
			else{ 	// Coarse mode.
				RxVrefEnd = 0x4F;//(VrefIndex + RXVREF_STEP_BASE_SI) > 0x4F ? 0x4F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter.
				RxVrefStart = 0x08;//VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x8;
				if(RankIndex < 4){
					Cal_Byte = DramAttr->CHACoarseMode;
				}
				else{
					Cal_Byte = DramAttr->CHBCoarseMode;
				}
			}
			pRxVref_Cal_Value = RxVref_Start;  //initialize the Pool
			(*PeiServices)->SetMem(RxVref_Start, BlockNum*sizeof(DQSI_Vref), 0);
			SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, TRUE, &Save_RxVref[0]);  
			for(RxVrefValue = RxVrefEnd, Cnt = 0; RxVrefValue >= RxVrefStart, Cnt < BlockNum; Cnt++)
			{
				//Sets manual RX Vref value --same value: for all byte and select the range.
				if(DramAttr->CHACoarseMode == 0 && DramAttr->CHBCoarseMode == 0){
					Vref_Range_Select_For_Cal(DramAttr, RankIndex, RxVrefValue,VREF_FINE_MODE);
					Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex, RxVrefValue,VREF_FINE_MODE);
				}
				else{
					Vref_Range_Select_For_Cal(DramAttr, RankIndex, RxVrefValue,VREF_COARSE_MODE);
					Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex, RxVrefValue,VREF_COARSE_MODE);
				}
				TriggerLoadReg(PeiServices, DramAttr);
				Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
				Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);
				Rx_DQSI_ReadLeveling_SaveRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, pRxVref_Cal_Value->DQSIRange);
				pRxVref_Cal_Value->RxVrefValue = RxVrefValue;
				pRxVref_Cal_Value++;
				RxVrefValue = RxVrefValue - RxVrefStep;
				if(RxVrefValue<RxVrefStep){
					break;
				}
			}
			SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, FALSE, &Save_RxVref[0]); 
			//Check range, show log and select a proper rxvref
			Select_RxVref_From_Rx_Eye(PeiServices, DramAttr, RankIndex, ECC_ENABLE, RxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups, BlockNum, Cal_Byte);			
		#ifdef PRINT_RX_EYE
			Rx_VrefDQSI_Cal_Print_Rx_Eye(PeiServices, DramAttr, RankIndex, ECC_ENABLE, RxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups, BlockNum, Cal_Byte);			
		#endif
		#ifdef RXVREF_BY_CHANNEL
		if(RankIndex/4 == 1){
			RankIndex = 4;
		}
		else if(RankIndex/4 == 0){
			RankIndex = 0;
		}
		#endif
		}
	}
}


BOOLEAN IsNeedVrefCoarseMode(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 *Cal_RankPresent)
{
	
	UINT8 ByteIndex;
	if(DramAttr->CHACoarseMode != 0 || DramAttr->CHBCoarseMode != 0){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Need to Enable Coarse Mode and Re-Calibration "));
		for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES;ByteIndex++){
			if(DramAttr->CHACoarseMode & (1<<ByteIndex)){
				Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,TRUE);
			}
			if(DramAttr->CHBCoarseMode & (1<<ByteIndex)){
				Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,TRUE);
			}
		}
		*Cal_RankPresent = (DramAttr->RankPresent[DramAttr->AttrNo]&(DramAttr->CHACoarseMode > 0 ? 0XF : 0))|(DramAttr->RankPresent[DramAttr->AttrNo]&(DramAttr->CHBCoarseMode > 0 ? 0XF0 : 0));
		return TRUE;
	}
	else{	
		return FALSE;
	}

}

VOID Rx_VrefDQSI_PREAMBLE_Cal(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	EFI_STATUS Status;

	BOOLEAN ECC_ENABLE = FALSE;
	DQSI_Vref *pRxVref_Start = NULL;

	UINT8   RxVrefStart = 0;
	UINT8	RxVrefEnd = 0;


	UINT8 	NumCounter      = 0;
	UINT8 	NumCounter_F    = 0;
	UINT8 	NumCounter_C    = 0;
	UINT8 	Cal_RankPresent = 0;

	UINT8 	VrefIndex       = 0;
	UINT8 	RankNo;
	UINT8 	RxVref_CHA[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	UINT8 	RxVref_CHB[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	//struct RxVref_Register_Setting Save_RxVref[2*ASIA_MAX_BYTES] ; //store CHA/B RXVREF Setting

	UINT8 RxVref_PerBit[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT]; //8*9*8 = 526bytes
	UINT8 RxVref_PerBit_Infs[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT];
	UINT8 RxVref_PerBit_Sups[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT];

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	//Change MPR Pattern
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			//for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, 0x55, 3);
			}
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref DQSI Preamble Calibration Begin"));	
	//Save RXVREF Setting
	//(*PeiServices)->SetMem(Save_RxVref,sizeof(Save_RxVref), 0);
	//SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, TRUE, &Save_RxVref[0]);  // 

	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F){//CHA
		VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,0,0,0);// [RankIndex = 0 ByteIndex = 0 BitIndex = 0] rxvref value (SI) of channel.
	}
	else{//CHB
		VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,4,0,0);// [RankIndex = 4 ByteIndex = 0 BitIndex = 0] rxvref value (SI) of channel.
	}
	RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter. 
	RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;
	NumCounter_F = ((RxVrefEnd-RxVrefStart)/VREF_FINE_STEP) + 1;

	RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x4F ? 0x4F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter.
	RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x8;
	NumCounter_C = ((RxVrefEnd-RxVrefStart)/VREF_COARSE_STEP) + 1;

	NumCounter = NumCounter_F > NumCounter_C ? NumCounter_F : NumCounter_C;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n NumCounter_F = 0x%02x NumCounter_C = 0x%02x ",NumCounter_F,NumCounter_C));

	Status = (*PeiServices)->AllocatePool(
		PeiServices,
		NumCounter*sizeof(DQSI_Vref),
		&pRxVref_Start
		);
	if (EFI_SUCCESS != Status){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Allocate Pool Fail "));
		return;
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n NumCounter = %x Pool size = 0x%x ",NumCounter,NumCounter*sizeof(DQSI_Vref)));
	}	
	// initialize the variable
	(*PeiServices)->SetMem(RxVref_CHA,sizeof(RxVref_CHA), 0);
	(*PeiServices)->SetMem(RxVref_CHB,sizeof(RxVref_CHB), 0);
	(*PeiServices)->SetMem(RxVref_PerBit,sizeof(RxVref_PerBit), 0); 
	(*PeiServices)->SetMem(RxVref_PerBit_Sups,sizeof(RxVref_PerBit_Sups), 0);
	(*PeiServices)->SetMem(RxVref_PerBit_Infs,sizeof(RxVref_PerBit_Infs), 0);

	Rx_Vref_ClearModeStatus(PeiServices,pPCIPPI,DramAttr);
	Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, ALLRANK);
	Cal_RankPresent = DramAttr->RankPresent[DramAttr->AttrNo];
	LOOP_Vref_DO_DQSI_Calibration_Readpreamble(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, Cal_RankPresent, VREF_FINE_STEP, NumCounter, pRxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups);
	Check_VrefC_Within_Byte(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_PerBit,RxVref_CHA,RxVref_CHB,ALLBYTE,ALLBYTE);
	Rx_Vref_SetRegister(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_CHA,RxVref_CHB,ALLBYTE,ALLBYTE);

	if(IsNeedVrefCoarseMode(PeiServices, pPCIPPI, DramAttr,&Cal_RankPresent)){
		LOOP_Vref_DO_DQSI_Calibration(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, Cal_RankPresent, VREF_COARSE_STEP, NumCounter, pRxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups);
		Check_VrefC_Within_Byte(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_PerBit,RxVref_CHA,RxVref_CHB,DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode);
		Rx_Vref_SetRegister(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_CHA,RxVref_CHB,DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode);
	}
	//SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, FALSE, &Save_RxVref[0]);
    DumpRxVrefIndex(PeiServices, pPCIPPI, DramAttr,ECC_ENABLE);//S36
	pRxVref_Start = NULL; 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref DQSI Preamble Calibration  End \r\n"));
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			//for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, 0x00, 3);
			}
		}
	}	
}

VOID Rx_VrefDQSI_Cal(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	EFI_STATUS Status;

	BOOLEAN ECC_ENABLE = FALSE;
	DQSI_Vref *pRxVref_Start = NULL;

	UINT8   RxVrefStart = 0;
	UINT8	RxVrefEnd = 0;


	UINT8 	NumCounter      = 0;
	UINT8 	NumCounter_F    = 0;
	UINT8 	NumCounter_C    = 0;
	UINT8 	Cal_RankPresent = 0;

	UINT8 	VrefIndex       = 0;
	UINT8 	RankNo;
	UINT8 	RxVref_CHA[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	UINT8 	RxVref_CHB[ASIA_MAX_BYTES][ASIA_MAX_BIT];
	//struct RxVref_Register_Setting Save_RxVref[2*ASIA_MAX_BYTES] ; //store CHA/B RXVREF Setting

	UINT8 RxVref_PerBit[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT]; //8*9*8 = 526bytes
	UINT8 RxVref_PerBit_Infs[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT];
	UINT8 RxVref_PerBit_Sups[ASIA_MAX_RANKS][ASIA_MAX_BYTES][ASIA_MAX_BIT];

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	//Change MPR Pattern
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			//for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, 0x55, 3);
			}
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref DQSI RLVL Calibration Begin"));	
	//Save RXVREF Setting
	//(*PeiServices)->SetMem(Save_RxVref,sizeof(Save_RxVref), 0);
	//SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, TRUE, &Save_RxVref[0]);  // 

	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F){//CHA
		VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,0,0,0);// [RankIndex = 0 ByteIndex = 0 BitIndex = 0] rxvref value (SI) of channel.
	}
	else{//CHB
		VrefIndex = Rx_Vref_GetVal(PeiServices,pPCIPPI, DramAttr,4,0,0);// [RankIndex = 4 ByteIndex = 0 BitIndex = 0] rxvref value (SI) of channel.
	}
	RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter. 
	RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;
	NumCounter_F = ((RxVrefEnd-RxVrefStart)/VREF_FINE_STEP) + 1;

	RxVrefEnd = 0x4F;//(VrefIndex + RXVREF_STEP_BASE_SI) > 0x4F ? 0x4F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter.
	RxVrefStart = 0x08;//VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x8;
	NumCounter_C = ((RxVrefEnd-RxVrefStart)/VREF_COARSE_STEP) + 1;

	NumCounter = NumCounter_F > NumCounter_C ? NumCounter_F : NumCounter_C;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n NumCounter_F = 0x%02x NumCounter_C = 0x%02x ",NumCounter_F,NumCounter_C));

	Status = (*PeiServices)->AllocatePool(
		PeiServices,
		NumCounter*sizeof(DQSI_Vref),
		&pRxVref_Start
		);
	if (EFI_SUCCESS != Status){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Allocate Pool Fail "));
		return;
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n NumCounter = %x Pool size = 0x%x ",NumCounter,NumCounter*sizeof(DQSI_Vref)));
	}	
	// initialize the variable
	(*PeiServices)->SetMem(RxVref_CHA,sizeof(RxVref_CHA), 0);
	(*PeiServices)->SetMem(RxVref_CHB,sizeof(RxVref_CHB), 0);
	(*PeiServices)->SetMem(RxVref_PerBit,sizeof(RxVref_PerBit), 0); 
	(*PeiServices)->SetMem(RxVref_PerBit_Sups,sizeof(RxVref_PerBit_Sups), 0);
	(*PeiServices)->SetMem(RxVref_PerBit_Infs,sizeof(RxVref_PerBit_Infs), 0);

	Rx_Vref_ClearModeStatus(PeiServices,pPCIPPI,DramAttr);
	Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, ALLRANK);
	Cal_RankPresent = DramAttr->RankPresent[DramAttr->AttrNo];
	LOOP_Vref_DO_DQSI_Calibration(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, Cal_RankPresent, VREF_FINE_STEP, NumCounter, pRxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups);
	Check_VrefC_Within_Byte(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_PerBit,RxVref_CHA,RxVref_CHB,ALLBYTE,ALLBYTE);
	Rx_Vref_SetRegister(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_CHA,RxVref_CHB,ALLBYTE,ALLBYTE);

	if(IsNeedVrefCoarseMode(PeiServices, pPCIPPI, DramAttr,&Cal_RankPresent)){
		LOOP_Vref_DO_DQSI_Calibration(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, Cal_RankPresent, VREF_COARSE_STEP, NumCounter, pRxVref_Start, RxVref_PerBit, RxVref_PerBit_Infs, RxVref_PerBit_Sups);
		Check_VrefC_Within_Byte(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_PerBit,RxVref_CHA,RxVref_CHB,DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode);
		Rx_Vref_SetRegister(PeiServices, pPCIPPI, DramAttr, ECC_ENABLE, RxVref_CHA,RxVref_CHB,DramAttr->CHACoarseMode,DramAttr->CHBCoarseMode);
	}
	//SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, FALSE, &Save_RxVref[0]);
    DumpRxVrefIndex(PeiServices, pPCIPPI, DramAttr,ECC_ENABLE);//S36
	pRxVref_Start = NULL; 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref DQSI RLVL Calibration  End \r\n"));
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			//for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, 0x00, 3);
			}
		}
	}	
}

typedef struct 
{
	UINT16 DQSIRange[ASIA_MAX_BYTES][ASIA_MAX_BIT][2] ;
	UINT8 RxVrefValue[ASIA_MAX_BYTES][ASIA_MAX_BIT][2];
} DQSI_Vref_New;

VOID Rx_VrefDQSI_Cal_New(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	INT8	RankIndex;
	UINT8   DqsiStep = 2; 
	UINT32		Default_MPR = 0xAA0F3355;
	BOOLEAN ECC_ENABLE = FALSE;
	UINT8   RxVrefValue = 0;
	UINT8   RxVrefStart = 50;
	UINT8	RxVrefEnd = 60;
	UINT8	RxVrefStep = 1;
	UINT8	VrefIndexCHA = 0;
	UINT8	VrefIndexCHB = 0;

	UINT8	VrefIndex    = 0;
	UINT8   ByteIndex,BitIndex;
	UINT8 	RankNo;
	DQSI_Vref_New pRxVref_High ;
	DQSI_Vref_New pRxVref_Low ;

	UINT8		DQSIRange[ASIA_MAX_BYTES][ASIA_MAX_BIT][2];
	struct RxVref_Register_Setting Save_RxVref[2*ASIA_MAX_BYTES] ; //store CHA/B RXVREF Setting


	(*PeiServices)->SetMem(&pRxVref_High,sizeof(DQSI_Vref_New), 0); 
	(*PeiServices)->SetMem(&pRxVref_Low,sizeof(DQSI_Vref_New), 0xFF); 

	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
			ECC_ENABLE = TRUE;
	}
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			//for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, 0x55, 3);
			}
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVref  New-Method Calibration Begin"));	
	//Save RXVREF Setting
	(*PeiServices)->SetMem(Save_RxVref,sizeof(Save_RxVref), 0);
	SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, TRUE, &Save_RxVref[0]);  // 
	//Get RxVrefValue by read the [ByteIndex = 0 BitIndex = 0] rxvref value (SI) of channel.
	VrefIndexCHA = Gray2Binary((UINT8)((Save_RxVref[0].VREFC & 0x1F)<<4|(Save_RxVref[0].VREFF & 0xF)));
	VrefIndexCHB = Gray2Binary((UINT8)((Save_RxVref[0+ASIA_MAX_BYTES].VREFC & 0x1F)<<4|(Save_RxVref[0+ASIA_MAX_BYTES].VREFF & 0xF)));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n VrefIndexCHA = 0x%02x VrefIndexCHB = 0x%02x ",VrefIndexCHA,VrefIndexCHB));
	if(DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F){
		VrefIndex = VrefIndexCHA;
	}
	else{
		VrefIndex = VrefIndexCHB;
	}
	RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI); //just to calculate NumCounter. 
	RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVrefStart = 0x%02x RxVrefEnd = 0x%02x ",RxVrefStart,RxVrefEnd));

	Rx_DQSI_ClearDataset(PeiServices, pPCIPPI, DramAttr, ALLRANK);
	for(RankIndex=ASIA_MAX_RANKS-1; RankIndex>=0; RankIndex--)//Rx vref use rank vref  
	{
		(*PeiServices)->SetMem(&pRxVref_High,sizeof(DQSI_Vref_New), 0); 
		(*PeiServices)->SetMem(&pRxVref_Low,sizeof(DQSI_Vref_New), 0xFF); 
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n Rx_Vref Calibration RankIndex = %x ",RankIndex));

			if(RankIndex < 4){
				VrefIndex = VrefIndexCHA;
			}
			else{
				VrefIndex = VrefIndexCHB;
			}
			RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI);
			RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n RxVrefStart = 0x%02x RxVrefEnd = 0x%02x ",RxVrefStart,RxVrefEnd));

			for(RxVrefValue = RxVrefEnd; RxVrefValue >= RxVrefStart; )
			{
				//Sets manual RX Vref value --same value: for all byte and select the range.
				Internal_VREF_Range_Select(DramAttr, RankIndex, 0, RxVrefValue); 
				Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex, RxVrefValue,VREF_FINE_MODE);
				TriggerLoadReg(PeiServices, DramAttr);

				Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
				Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

				DramAttr->DramAutoCal_DQSI[RankIndex].CalResult = Rx_DQSI_ReadLeveling_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, DQSIRange);
				if(DramAttr->DramAutoCal_DQSI[RankIndex].CalResult == TRUE)
				{
					for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES-1; ByteIndex++)
					{
						for(BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
						{
							UINT16 Temp_Value =0;
							if(DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH >DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH)
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH;
							else
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH;

							if(Temp_Value > pRxVref_High.DQSIRange[ByteIndex][BitIndex][0])
							{
								pRxVref_High.DQSIRange[ByteIndex][BitIndex][0] =Temp_Value ; 
								pRxVref_High.RxVrefValue[ByteIndex][BitIndex][0] = RxVrefValue;
							}

							if(DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW >DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW)
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
							else
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;

							if(Temp_Value < pRxVref_Low.DQSIRange[ByteIndex][BitIndex][0])
							{
								pRxVref_Low.DQSIRange[ByteIndex][BitIndex][0] = Temp_Value ; 
								pRxVref_Low.RxVrefValue[ByteIndex][BitIndex][0] = RxVrefValue;
							}

						}
					}
				}
				RxVrefValue = RxVrefValue - RxVrefStep;
				if(RxVrefValue<RxVrefStep){
					break;
				}
			}

			RxVrefEnd = (VrefIndex + RXVREF_STEP_BASE_SI) > 0x8F ? 0x8F : (VrefIndex + RXVREF_STEP_BASE_SI);
			RxVrefStart = VrefIndex > RXVREF_STEP_BASE_SI ? (VrefIndex - RXVREF_STEP_BASE_SI) : 0x0;

			for(RxVrefValue = RxVrefStart; RxVrefValue <= RxVrefEnd; )
			{
				//Sets manual RX Vref value --same value: for all byte and select the range.
				Internal_VREF_Range_Select(DramAttr, RankIndex, 0, RxVrefValue); 
				Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex, RxVrefValue,VREF_FINE_MODE);
				TriggerLoadReg(PeiServices, DramAttr);

				Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, DqsiStep, Default_MPR, ECC_ENABLE);
				Rx_DQSI_SaveDataSet(PeiServices, pPCIPPI, DramAttr, RankIndex, ALLBYTE);

				DramAttr->DramAutoCal_DQSI[RankIndex].CalResult = Rx_DQSI_ReadLeveling_CheckRange(PeiServices, DramAttr, RankIndex, ECC_ENABLE, DQSIRange);
				if(DramAttr->DramAutoCal_DQSI[RankIndex].CalResult == TRUE)
				{
					for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES-1; ByteIndex++)
					{
						for(BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
						{
							UINT16 Temp_Value =0;
							if(DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH >DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH)
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_HIGH;
							else
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_HIGH;

							if(Temp_Value > pRxVref_High.DQSIRange[ByteIndex][BitIndex][1])
							{
								pRxVref_High.DQSIRange[ByteIndex][BitIndex][1] =Temp_Value ; 
								pRxVref_High.RxVrefValue[ByteIndex][BitIndex][1] = RxVrefValue;
							}

							if(DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW >DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW)
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][POS].DQSI_LOW;
							else
								Temp_Value = DramAttr->DramAutoCal_DQSI[RankIndex].ByteInfo[ByteIndex][BitIndex][NEG].DQSI_LOW;

							if(Temp_Value < pRxVref_Low.DQSIRange[ByteIndex][BitIndex][1])
							{
								pRxVref_Low.DQSIRange[ByteIndex][BitIndex][1] =Temp_Value ; 
								pRxVref_Low.RxVrefValue[ByteIndex][BitIndex][1] = RxVrefValue;
							}
						}
					}
				}
				RxVrefValue = RxVrefValue + RxVrefStep;
			}

			//caculate
			for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES-1; ByteIndex++)
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nRxVref - New Method RankIndex:%d  ByteIndex:%d ", RankIndex , ByteIndex));	
				for(BitIndex = 0; BitIndex < ASIA_MAX_BIT; BitIndex++)
				{
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ",(pRxVref_Low.RxVrefValue[ByteIndex][BitIndex][0]+ pRxVref_High.RxVrefValue[ByteIndex][BitIndex][0] +pRxVref_Low.RxVrefValue[ByteIndex][BitIndex][1] + pRxVref_High.RxVrefValue[ByteIndex][BitIndex][1])>>2 ));	
				}
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));	
			}
		}

	}
	SaveRestoreRxVref(PeiServices, pPCIPPI, DramAttr, FALSE, &Save_RxVref[0]);   
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nRxVref Calibration New-Method End \r\n"));
	for(RankNo=0; RankNo<ASIA_MAX_RANKS; RankNo++) 
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankNo)) 
		{
			//MprNo 0-->3
			//for(MprNo = 0;MprNo < 4; MprNo++)
			{
				WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankNo, 0x00, 3);
			}
		}
	}	
}






































VOID ReadMPR(
	IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 MPRPAGE,
	IN UINT8 MPR)
{
#if 1
	UINT64 Address;
	UINT32 Buffer32 = 0x00, MrsSet32 = 0x00, DummyReadBase=0x00;
	UINT16  SavedREFC = 0;
	UINT16 SavedBARASelect = 0;

	switch(MPRPAGE)
	{
		case 0:
			MPRPAGE = MR3_MPR_PAGE0;
			break;		
		case 1:
			MPRPAGE = MR3_MPR_PAGE1;
			break;
		case 2:
			MPRPAGE = MR3_MPR_PAGE2;
			break;
		case 3:
			MPRPAGE = MR3_MPR_PAGE3;
			break;
		default:
			break;
	}
	//UINT8  SavedBANKSEL = 0;
	//UINT8  SavedDataWidth = 0;
	//Save BA /RA Select
	//SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect, &SavedBANKSEL, &SavedDataWidth);
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//Clear all VRank size
	ClearAllRankSize(DramAttr);	
	// Map each Physical Rank N to Virtual Rank N
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 1ms
	//Set MRS Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	//AsiaIoWrite8(0x80, 0xC1);
	//Trigger MRS3 with MPR Enable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex,MR3_MPR_EN | MR3_MPR_STAGGER | MPRPAGE);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
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
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	//Restore BA /RA Select
	//SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect, &SavedBANKSEL, &SavedDataWidth);	
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
	//BG1      BG0      BA1         BA0    MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
	//15^20,  14^7,    18^23,	 17^22,     23	 22,  21, 20, 12,  11,	10,   9,8,	7, 	 6,	 5,  4, 	3 
	//MPR0 @ PAGE0,  BA1 = 0, BA0 = 0
	/*Address = 0;*/
	/*//MPR1 @ PAGE0*/
	/*Address = 0x20000;*/
	/*//MPR2 @ PAGE0*/
	/*Address = 0x40000;*/
	/*//MPR3 @ PAGE0*/
	/*Address = 0x60000;*/
	switch(MPR)
	{
		case 0:
			AsiaMemoryRead32(0);		
			break;		
		case 1:
			AsiaMemoryRead32(0x20000);		
			break;
		case 2:
			AsiaMemoryRead32(0x40000);		
			break;
		case 3:
			AsiaMemoryRead32(0x60000);		
			break;
		default:
			break;
	}
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);
	//Clear all VRank size
	ClearAllRankSize(DramAttr);	
	// Map each Physical Rank N to Virtual Rank N
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	//Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 1ms
	//Set MRS Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	//AsiaIoWrite8(0x80, 0xC1);
	//Trigger MRS3 with MPR Disable
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, DDR4_MR3_INIT);
	/*}*/
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
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
	//set Nomal Mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	//Restore BA /RA Select
	//SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect, &SavedBANKSEL, &SavedDataWidth);	
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);
#endif

}




VOID ReadMPR_Select(
	IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 MPRPAGE,
	IN BOOLEAN Enable)
{

    UINT64 Address;
	UINT32 Buffer32 = 0x00, MrsSet32 = 0x00, DummyReadBase=0x00;
	UINT16  SavedREFC = 0;
	UINT16 SavedBARASelect = 0;

	//Note: Disable RMW
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, BIT7, BIT7);
    
    //Save BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);

	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);

	//Clear all VRank size
	ClearAllRankSize(DramAttr);	
	
	
	// Map each Physical Rank N to Virtual Rank N
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

	switch(MPRPAGE)
	{
	  case 0:
	  	MPRPAGE = MR3_MPR_PAGE0;
        break;		
	  case 1:
	  	MPRPAGE = MR3_MPR_PAGE1;
		break;
	  case 2:
	  	MPRPAGE = MR3_MPR_PAGE2;
		break;
	  case 3:
	  	MPRPAGE = MR3_MPR_PAGE3;
		break;
	  default:
	  	break;

	}


    //Precharge all
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);

	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

#if 0
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
#endif
	//NOTE:   ~~~ Dummy Write~~~	
	*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;

	WaitForMicroSec(PeiServices, 10);	//delay 1ms

    //Set MRS Mode
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);

	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);

    //AsiaIoWrite8(0x80, 0xC1);

	if(Enable)
	{
	    //Trigger MRS3 with MPR Enable
	    Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex,MR3_MPR_EN | MR3_MPR_STAGGER | MPRPAGE);
	}
    else
    {
	    //Trigger MRS3 with MPR Disable
	    Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, DDR4_MR3_INIT);
	}
	
    MrsSet32 = Buffer32;
    if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
#if 0
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
#endif
	//NOTE:   ~~~ Dummy Write~~~	
	*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;

    WaitForMicroSec(PeiServices, 10);	//delay 1ms

	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
#if 0
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
#endif
		//NOTE:   ~~~ Dummy Write~~~	
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;

		WaitForMicroSec(PeiServices, 10);	//delay 1ms
    }
	

    //set Nomal Mode
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);

	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);


	//Note: Enable RMW
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, BIT7, 0);
	
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);


	//BG1 BG0   BA1  BA0 MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
	//7,	     6,      16,	     15,					   23	 22,   21,	   20,	  14,	 13,	12,    11,	  10,	 9, 	  8,	 5, 	 4, 	3 


	//MPR0 @ PAGE0,  BA1 = 0, BA0 = 0
	Address = 0;
	

    //MPR1 @ PAGE0
    Address = 0x8000;
	
	//MPR2 @ PAGE0
    Address = 0x10000;

	//MPR3 @ PAGE0
    Address = 0x18000;

}

VOID PDASetMRS(
	IN EFI_PEI_SERVICES **PeiServices,	 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ChipNo,
	IN UINT32 VrefDQ)
{
#if 1

     UINT64 Address;
	UINT32 Buffer32 = 0x00, MrsSet32 = 0x00, DummyReadBase=0x00;
	UINT16  SavedREFC = 0;
	UINT16 SavedBARASelect = 0;
	//UINT8  SavedBANKSEL = 0;
 	//UINT8  SavedDataWidth = 0;
	UINT8 Temp8 = 0;
    
    //Save BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);

	//Save Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);

	//Clear all VRank size
	ClearAllRankSize(DramAttr);	
	
	
	// Map each Physical Rank N to Virtual Rank N
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);


    //Note: Disable RMW
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, BIT7, BIT7);


   //Enable PDA MODE
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);
   AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDAEN, D0F3_RPDAEN);





    //Select chip NO
    switch(ChipNo)
    {
       case 0:
	   	 Temp8 = 0xFE;
	     break;
       case 1:
	   	 Temp8 = 0XFD;
	     break;
	   case 2:
	   	 Temp8 = 0XFB;
	     break;
	   case 3:
	   	 Temp8 = 0XF7;
	     break;
	   case 4:
	   	 Temp8 = 0XEF;
	     break;
	   case 5:
	   	Temp8 = 0XDF;
	     break;
	   case 6:
	   	Temp8 = 0XBF;
	     break;
       case 7:
	   	Temp8 = 0X7F;
	     break;
	   case 8:
	   	Temp8 = 0x00;
	     break;
	   default:
	   	 break;
	}

	//CHA

//	COMMENT OUT FOR TEMP
	if(RankIndex < 4){
	    if(ChipNo == 8){
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_A8, 0);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_CTL_CHA_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_A_7_0, 0xFF);
	    	}
		else
			{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_A8, D0F3_RPDA_A8);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_CTL_CHA_CHB);			
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_A_7_0, Temp8);
			}
	}
	//CHB
    else{
        if(ChipNo == 8){
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_B8, 0);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_CTL_CHA_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_B_7_0, 0xFF00);
	    	}
		else
			{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_B8, D0F3_RPDA_B8);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_CTL_CHA_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_B_7_0, Temp8 <<8);
			}

	}

    //Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
    AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
    
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);



    
	//STEP1 Enable PDA MODE
	//Trigger MR3[A4] = 1 
    Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, MR3_MPR_PDA);
    MrsSet32 = Buffer32;
    if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
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



#if 0


    //STEP2   Set Vref to the select chip No
    //Enable Vref training and Set Vref value
	Buffer32 = GetDDR4MR6(PeiServices, DramAttr, RankIndex, VREF_TRAIN_EN | VREF_RANGE1, VrefDQ);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);

	//NOTE:   ~~~ Dummy Write~~~	
	*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;		

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR6:%x\n", MrsSet32));
	//Wait for some time
	WaitForMicroSec(PeiServices, 100);

   
	
    if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		//NOTE:   ~~~ Dummy Write~~~	
	    *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;	
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
    }




    //STEP3   Disable Vref training
    Buffer32 = GetDDR4MR6(PeiServices, DramAttr, RankIndex, DDR4_MR6_INIT | VREF_RANGE1, VrefDQ);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);

	//NOTE:   ~~~ Dummy Write~~~	
	*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;	
	
	//Wait for some time
	WaitForMicroSec(PeiServices, 100);

	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);

		//NOTE:   ~~~ Dummy Write~~~	
	    *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;	
		
		WaitForMicroSec(PeiServices, 100);	//delay 1ms
    }


#endif



#if 1

    //LGE20160622 SET CL = 14   TO  CHIP0
    DramAttr->CL[DramAttr->AttrNo] = 14;
    
	Buffer32 = GetDDR4MR0(PeiServices, DramAttr, RankIndex, DDR4_MR0_INIT);
		MrsSet32 = Buffer32;
		if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
			MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	
		//NOTE:   ~~~ Dummy Write~~~	
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;		
	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR0:%x\n", MrsSet32));
		//Wait for some time
		WaitForMicroSec(PeiServices, 100);

#endif













     
   //STEP4 Disable PDA MODE
   //LGE20160628 NOTE: Use dummy write,  and all THE DQ PIN Is  0   
   //CHA
 //COMMENT OUT FOR TEMP
 
	if(RankIndex < 4){
	    
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_A8, 0);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_CTL_CHA_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_A_7_0, 0X00);
	    	
		
	}
	//CHB
    else{
       
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_B8, 0);
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_CTL_CHA_CHB);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDA_B_7_0, 0X00);
	    	
		
	}




  //LGE20160701 NOTE: Must flush CFG write  registers
	FlushCfgWrite(PeiServices, DramAttr, Address);


   //Trigger MR3[A4] = 0 
    Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, DDR4_MR3_INIT);
    MrsSet32 = Buffer32;
    if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);	

	//LGE20160628 NOTE:   ~~~ Dummy Write~~~	
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;	
	
    WaitForMicroSec(PeiServices, 10);	//delay 1ms
     if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);

		//LGE20160628 NOTE:   ~~~ Dummy Write~~~	
		*(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32) = 0X00;	
		
		WaitForMicroSec(PeiServices, 10);	//delay 1ms
    }




  //set Nomal Mode
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);

   //LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);



   //LGE20160622 Note: Enable RMW Again
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 0x19F);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, BIT7, 0);
  

  

    //Disable PDA MODE
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);
   AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RPDAEN, 0);
	   


	 //Restore BA /RA Select
	//SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect, &SavedBANKSEL, &SavedDataWidth);
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	 
	//Restore Refresh Counter
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedREFC);

	//Restore Rank Map and Rank size ?????????????????

	
#endif

}


