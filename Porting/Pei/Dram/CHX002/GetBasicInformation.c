//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
//Ver	Date					Note
//----------------------------------------------------------------------------

#include "Pei.h"
#include "PeiDebug.h"
#include "Draminit.h"
#include "spd.h"
#include "GetBasicInformation.h"
#include "VirtualSPD.h"
#include EFI_PPI_CONSUMER(AsiaNbPpi)


#define  CHA_R1xD1        0
#define  CHA_R1xD2        1
#define  CHA_R2xD1        2
#define  CHA_R2xD2        3
#define  CHB_R1xD1        0
#define  CHB_R1xD2        1
#define  CHB_R2xD1        2
#define  CHB_R2xD2        3

#define  CHA_DIMM_0       0  
#define  CHA_DIMM_1       1
#define  CHB_DIMM_0       0  
#define  CHB_DIMM_1       1

EFI_GUID gAsiaDramInfoSaveGuid = { 0xe1c2c2a6, 0x2cd0, 0x4834, { 0xa6, 0x4e, 0x62, 0xae, 0x6A, 0x2e, 0x96, 0xa7 }};
EFI_GUID  gPeiReadOnlyVariable2PpiGuid1 = EFI_PEI_READ_ONLY_VARIABLE2_PPI_GUID;
EFI_GUID  gPeiReadOnlyVariablePpiGuid1 = EFI_PEI_READ_ONLY_VARIABLE_PPI_GUID;

char DRAMCLK[11][16]={
        "Undefined", "400 MHz", "566 MHz", "667 MHz",\
        "800 MHz", "933 MHz", "1066 MHz", "1200 MHz",\
        "1333 MHz","1466 MHz","1600 MHz"
        };

char ModuleType[16][16]={
        "Reserved", "RDIMM", "UDIMM", "SO-DIMM",\
        "Micro-DIMM", "Mini-RDIMM", "Mini-UDIMM", "Reserved",\
        "72b-SO-RDIMM", "72b-SO-UDIMM", "Reserved", "Reserved",\
        "16b-SO-DIMM", "32b-SO-DIMM", "Reserved", "Reserved"
        };

char CmdRate[2][16]={"2T command", "1T command"};

char BL[2][16]={"On the fly", "BL8"};

char RDIMM[2][16]={"NOT present", "present"};

char ECCDIMM[2][16]={"NOT supported", "supported"};

char TSDIMM[2][16]={"NOT present", "present"};

char RawCardType[16][16]={
        "A", "B", "C", "D",\
        "E", "F", "G", "H",\
        "J", "K", "L", "M",\
        "N", "P", "R", "T"
        };

char CircleOrCross[2][16]={"X", "O"};

char mODZ[3][16]={"N/A", "RZQ/7", "RZQ/5"};

char mRnom[8][16]={"Disable", "60 ohm", "120 ohm", "40 ohm", "240 ohm", "48 ohm", "80 ohm", "34 ohm"};

char mRwr[5][16]={"Disable", "120 ohm", "240 ohm", "Hi-Z", "80 ohm"};

char mRpark[8][16]={"Disable", "60 ohm", "120 ohm", "40 ohm", "240 ohm", "48 ohm", "80 ohm", "34 ohm"};

UINT8 DCLKString(UINT32 DCLKSetting)
{
	UINT8 DCLKValue;

	if(DCLKSetting == DRAM_FREQ_800)				DCLKValue = 0x01;
	else if (DCLKSetting == DRAM_FREQ_1066)		DCLKValue = 0x02;		
	else if (DCLKSetting == DRAM_FREQ_1333)		DCLKValue = 0x03;		
	else if (DCLKSetting == DRAM_FREQ_1600)		DCLKValue = 0x04;	
	else if (DCLKSetting == DRAM_FREQ_1866)		DCLKValue = 0x05;	
	else if (DCLKSetting == DRAM_FREQ_2133)		DCLKValue = 0x06;	
	else if (DCLKSetting == DRAM_FREQ_2400)		DCLKValue = 0x07;
	else if (DCLKSetting == DRAM_FREQ_2666)		DCLKValue = 0x08;
	else if (DCLKSetting == DRAM_FREQ_2933)		DCLKValue = 0x09;
	else if (DCLKSetting == DRAM_FREQ_3200)		DCLKValue = 0x0A;
	else DCLKValue = 0x00;
	
	return DCLKValue;
}

UINT8 ODZ(UINT32 ODZSetting)
{
	UINT8 ODTValue;
	
	if(ODZSetting == MR1_DDR4_RZQ7)			ODTValue = 0x01;
	else if (ODZSetting == MR1_DDR4_RZQ5)	ODTValue = 0x02;		
	else										ODTValue = 0x00;
	return ODTValue;
}

UINT8 Rnom(UINT32 RnomSetting)
{
	UINT8 RnomValue;
	
	if(RnomSetting == MR1_DDR4_RTT_NOM_DIS)			RnomValue = 0x00;
	else if (RnomSetting == MR1_DDR4_RTT_NOM_60OHM)		RnomValue = 0x01;		
	else if (RnomSetting == MR1_DDR4_RTT_NOM_120OHM)	RnomValue = 0x02;		
	else if (RnomSetting == MR1_DDR4_RTT_NOM_40OHM)		RnomValue = 0x03;	
	else if (RnomSetting == MR1_DDR4_RTT_NOM_240OHM)	RnomValue = 0x04;	
	else if (RnomSetting == MR1_DDR4_RTT_NOM_48OHM)		RnomValue = 0x05;	
	else if (RnomSetting == MR1_DDR4_RTT_NOM_80OHM)		RnomValue = 0x06;	
	else if (RnomSetting == MR1_DDR4_RTT_NOM_34OHM)		RnomValue = 0x07;	
	else RnomValue = 0x00;
	
	return RnomValue;
}

UINT8 Rwr(UINT32 RwrSetting)
{
	UINT8 RwrValue;

	if(RwrSetting == MR2_DDR4_RTT_WR_DIS)			RwrValue = 0x00;
	else if (RwrSetting == MR2_DDR4_RTT_WR_120OHM)	RwrValue = 0x01;		
	else if (RwrSetting == MR2_DDR4_RTT_WR_240OHM)	RwrValue = 0x02;		
	else if (RwrSetting == MR2_DDR4_RTT_WR_HIGHZ)	RwrValue = 0x03;		
	else if (RwrSetting == MR2_DDR4_RTT_WR_80OHM)	RwrValue = 0x04;		
	else RwrValue = 0x00;
	
	return RwrValue;
}

UINT8 Rpark(UINT32 RparkSetting)
{
	UINT8 RparkValue;
	
	if(RparkSetting == MR5_DDR4_RTT_PARK_DIS)			RparkValue = 0x00;
	else if (RparkSetting == MR5_DDR4_RTT_PARK_60OHM)	RparkValue = 0x01;		
	else if (RparkSetting == MR5_DDR4_RTT_PARK_120OHM)	RparkValue = 0x02;		
	else if (RparkSetting == MR5_DDR4_RTT_PARK_40OHM)	RparkValue = 0x03;	
	else if (RparkSetting == MR5_DDR4_RTT_PARK_240OHM)	RparkValue = 0x04;	
	else if (RparkSetting == MR5_DDR4_RTT_PARK_48OHM)	RparkValue = 0x05;	
	else if (RparkSetting == MR5_DDR4_RTT_PARK_80OHM)	RparkValue = 0x06;	
	else if (RparkSetting == MR5_DDR4_RTT_PARK_34OHM)	RparkValue = 0x07;	
	else RparkValue = 0x00;

	return RparkValue;
}


//same as chx001
UINT8 GetDIMMType(
		IN UINT8 ModuleType,
		IN UINT8 RanksNumber,
		IN UINT8 DeviceWidth, 
		IN UINT8 BusWidth
	)
{
	UINT8 DIMMType = RAW_CARD_O;
	
	switch (ModuleType<<16|RanksNumber<<8|DeviceWidth) 
	{
	//RDIMM (detele x4 case)
		case 0x010108:
			DIMMType = RAW_CARD_D;
			break;
		case 0x010208:
			DIMMType = RAW_CARD_E;
			break;
	//UDIMM
		case 0x020108:
			DIMMType = RAW_CARD_A;
			if(BusWidth==0xB)
				DIMMType = RAW_CARD_D;
			break;
		case 0x020208:
			DIMMType = RAW_CARD_B;
			if(BusWidth==0xB)
				DIMMType = RAW_CARD_E;
			break;
		case 0x020110:
			DIMMType = RAW_CARD_C;
			if(BusWidth==0xB)
				DIMMType = RAW_CARD_O;
			break;
	//SODIMM
		case 0x030108:
			DIMMType = RAW_CARD_A;
			if(BusWidth==0xB)
				DIMMType = RAW_CARD_D;
			break;
		case 0x030208:
			DIMMType = RAW_CARD_B;
			if(BusWidth==0xB)
				DIMMType = RAW_CARD_G;
			break;
		case 0x030110:
			DIMMType = RAW_CARD_C;
			if(BusWidth==0xB)
				DIMMType = RAW_CARD_O;
			break;
		default:			
			DIMMType = RAW_CARD_O;
			break;
	}
		return DIMMType;
}

//same as chx001
UINT8 GetSpdRawcard(
		IN UINT8 ModuleType,
		IN UINT8 SpdRawCard
	)
{
	UINT8 RawcardType = RAW_CARD_O;
	RawcardType =  SpdRawCard;
		
	//RDIMM
	if(ModuleType == RDIMM_MODULE)
	{
		if(SpdRawCard == RAW_CARD_A)					
			RawcardType = RAW_CARD_B;
		else if(SpdRawCard == RAW_CARD_F)
			RawcardType = RAW_CARD_C;		
		else if(SpdRawCard == RAW_CARD_G)
			RawcardType = RAW_CARD_D;		
		else if(SpdRawCard == RAW_CARD_J)
			RawcardType = RAW_CARD_B;		
				
	}
	//UDIMM
	else if(ModuleType == UDIMM_MODULE)
	{
		if(SpdRawCard == RAW_CARD_F)					
			RawcardType = RAW_CARD_E;		
	
	}
	//SODIMM
	else if(ModuleType == SODIMM_MODULE)
	{
		if(SpdRawCard == RAW_CARD_E )					
			RawcardType = RAW_CARD_B;
	}	
	return RawcardType; 	
}


UINT32 ReadEfuseData32(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 Efuse_Index
)
{
	UINT32 HDABase32;
	UINT32 Tmp_Index = 0, Tmp_Enable =0, Tmp_Data = 0;
	UINT32 Index_Offset=0x82B8;
	UINT32 Enable_Offset = 0x82C0, Data_Offset = 0x82BC;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA_DRAM ReadEfuseData32(Efuse_Index=0x%x)\n",Efuse_Index));

	HDABase32 = AsiaPciRead32(CHX002_EUMA|0x10);
	HDABase32 = HDABase32&0xFFFFFFFC;
	
	//Start to read efuse data
	do{
		Tmp_Enable = AsiaMemoryRead32(HDABase32|Enable_Offset);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "data=0x%x)\n",(Tmp_Enable & 0x02000000)));
	}while ((Tmp_Enable & 0x02000000) == 0x02000000);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "STEP 2\n"));
	Tmp_Index = 0;
	Tmp_Index |= (UINT32)(0x6d << 16);
	//PEI_DEBUG((PeiServices, EFI_D_INFO, "Write Tmp_Index=%x\n", Tmp_Index));
	AsiaMemoryModify32(HDABase32|Index_Offset, 0x007F0000, Tmp_Index);
		
	Tmp_Enable = 0;
	Tmp_Enable |= (UINT32)(0x11 << 25);
	AsiaMemoryWrite32(HDABase32|Enable_Offset, Tmp_Enable);
	
	do{
		Tmp_Enable = AsiaMemoryRead32(HDABase32|Enable_Offset);
	}while ((Tmp_Enable & 0x02000000) == 0x02000000);
	
	Tmp_Index = 0;
	Tmp_Index |= (UINT32)(Efuse_Index << 16);
	//PEI_DEBUG((PeiServices, EFI_D_INFO, "Write Tmp_Index=%x\n", Tmp_Index));
	AsiaMemoryModify32(HDABase32|Index_Offset, 0x007F0000, Tmp_Index);
		
	Tmp_Enable = 0;
	Tmp_Enable |= (UINT32)(0x11 << 25);
	AsiaMemoryWrite32(HDABase32|Enable_Offset, Tmp_Enable);
	
	
	//Wait until ready
	do{
		Tmp_Enable = AsiaMemoryRead32(HDABase32|Enable_Offset);
		//PEI_DEBUG((PeiServices, EFI_D_INFO, "Tmp_Enable:%X\n", Tmp_Enable));
	}while ((Tmp_Enable & 0x02000000) == 0x02000000);

	//Start to read
	Tmp_Data = AsiaMemoryRead32(HDABase32|Data_Offset);

	//Tmp_Data = Tmp_Data >> 24;
	//PEI_DEBUG((PeiServices, EFI_D_INFO, "Tmp_Index : %X, Tmp_Enable : %X, Tmp_Data : %X\n", Tmp_Index, Tmp_Enable, Tmp_Data));

	return Tmp_Data;
}


UINT32 GetEfuseData(IN EFI_PEI_SERVICES **PeiServices,UINT8 Index)
{
	UINT32 HDABase32 = 0x80000000, Data32;

	AsiaPciWrite32(CHX002_EUMA|0x10, HDABase32);
	AsiaPciWrite8(CHX002_EUMA|0x04, 0x03);
	
	AsiaMemoryWrite8(HDABase32|0x850C, 0x02);
	AsiaMemoryWrite8(HDABase32|0x8AA0, 0x02);
	AsiaMemoryWrite16(HDABase32|0x8838, 0xa548);
	AsiaMemoryWrite8(HDABase32|0x8608, 0x06);

	Data32 = ReadEfuseData32(PeiServices, Index);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "DLA-eFuse index 0x%08x=0x%08x! \n",Index, Data32));

	AsiaPciWrite32(CHX002_EUMA|0x10, 0);
	AsiaPciWrite8(CHX002_EUMA|0x04, 0);
	return Data32;


}

BOOLEAN CheckDramChange(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
	)
{

   EFI_STATUS     Status;
   DRAM_INFO_SAVE *DramInfoSave;
   
   UINT8 Index8;
   BOOLEAN IsChange = FALSE;
   UINTN         VarSize;
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    EFI_PEI_READ_ONLY_VARIABLE_PPI	  *VarPpi;
#else
   EFI_PEI_READ_ONLY_VARIABLE2_PPI	 *Var2Ppi;
#endif

   Status = (*PeiServices)->AllocatePool(
	           PeiServices,
	           sizeof(DRAM_INFO_SAVE),
	           &DramInfoSave
	       );

#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariablePpiGuid1, 0, NULL, (VOID**)&VarPpi);     
	VarSize = sizeof(DRAM_INFO_SAVE); 
	Status  = VarPpi->PeiGetVariable (
						PeiServices,
						NVINFO_DRAMINFO_VAR_NAME,
						&gAsiaDramInfoSaveGuid,
						NULL,
						&VarSize,
						DramInfoSave
						);
#else
	Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariable2PpiGuid1, 0, NULL, (VOID**)&Var2Ppi);	
	VarSize = sizeof(DRAM_INFO_SAVE);
	Status	= Var2Ppi->GetVariable (
					Var2Ppi,
					NVINFO_DRAMINFO_VAR_NAME,
					&gAsiaDramInfoSaveGuid,
					NULL,
					&VarSize,
					DramInfoSave
					);
#endif	

	if(!EFI_ERROR(Status)){  
		for(Index8 = 0;Index8 < ASIA_MAX_SOCKETS; Index8++)
		{
			if(DramAttr->MfrInfo[DramAttr->AttrNo][Index8].MFR_ID !=  DramInfoSave->MfrInfo[DramAttr->AttrNo][Index8].MFR_ID)
			{ 
				IsChange = TRUE;
				PEI_DEBUG((PeiServices, EFI_D_INFO, "MFR_ID changed\r\n"));
				break;
			}
			if(DramAttr->MfrInfo[DramAttr->AttrNo][Index8].SERIAL_NO != DramInfoSave->MfrInfo[DramAttr->AttrNo][Index8].SERIAL_NO)
			{
				IsChange = TRUE;
				PEI_DEBUG((PeiServices, EFI_D_INFO, "SERIAL_NO changed\r\n"));
				break;
			}	  
		}
		//Clock Chage
		if(DramInfoSave->DramFreq != DramAttr->ConfigData.DramClk)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "DramFreq changed\r\n"));
		}
		// if(DramInfoSave->WPREA != DramAttr->ConfigData.WPREA)
		// {
		// 	IsChange = TRUE;
		// 	PEI_DEBUG((PeiServices, EFI_D_INFO, "WPREA changed\r\n"));
		// }
		// if(DramInfoSave->RPREA != DramAttr->ConfigData.RPREA)
		// {
		// 	IsChange = TRUE;
		// 	PEI_DEBUG((PeiServices, EFI_D_INFO, "RPREA changed\r\n"));
		// }
		// if( DramInfoSave->CAParEn != DramAttr->ConfigData.CAParEn)
		// {
		// 	IsChange = TRUE;
		// 	PEI_DEBUG((PeiServices, EFI_D_INFO, "CAParEn changed\r\n"));
		// }
		// if(DramInfoSave->CRCEn != DramAttr->ConfigData.CRCEn)
		// {
		// 	IsChange = TRUE;
		// 	PEI_DEBUG((PeiServices, EFI_D_INFO, "CRCEn changed\r\n"));
		// }
		// if( DramInfoSave->CALEn != DramAttr->ConfigData.CALEn)
		// {
		// 	IsChange = TRUE;
		// 	PEI_DEBUG((PeiServices, EFI_D_INFO, "CALEn changed\r\n"));
		// }
		if(DramInfoSave->DramFastBoot != DramAttr->ConfigData.DramFastBoot)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "DramFastBoot changed\r\n"));
		}
		if(DramInfoSave->DramECC != DramAttr->ConfigData.DRAMECC)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "DramECC changed\r\n"));
		}
		if(DramInfoSave->DQSIByRank != DramAttr->ConfigData.DQSIByRank)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "DQSIByRank changed\r\n"));
		}
		if(DramInfoSave->TxIoTimingMethod != DramAttr->ConfigData.TxIoTimingMethod)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "TxIoTimingMethod changed\r\n"));
		}
		if(DramInfoSave->RxIoTimingMethod != DramAttr->ConfigData.RxIoTimingMethod)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "RxIoTimingMethod changed\r\n"));
		}
		if(DramInfoSave->RxVref != DramAttr->ConfigData.RxVref)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "RxVref changed\r\n"));
		}
		if(DramInfoSave->TxVref != DramAttr->ConfigData.TxVref)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "TxVref changed\r\n"));
		}
		if(DramInfoSave->TxVrefAllByte != DramAttr->ConfigData.TxVrefAllByte)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "TxVrefAllByte changed\r\n"));
		}
		if(DramInfoSave->MemoryChipODTDebug != DramAttr->ConfigData.MemoryChipODTDebug)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "MemoryChipODTDebug changed\r\n"));
		}
		if(DramInfoSave->MemoryChipODTWRDebug != DramAttr->ConfigData.MemoryChipODTWRDebug)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "MemoryChipODTWRDebug changed\r\n"));
		}
		if(DramInfoSave->MemoryChipODTParkDebug != DramAttr->ConfigData.MemoryChipODTParkDebug)
		{
			IsChange = TRUE;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "MemoryChipODTParkDebug changed\r\n"));
		}										
		if(IsChange == TRUE)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "******DRAM INFO CHANGE*******\r\n"));  
		}
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "******Get DRAM INFO FAIL*******\r\n"));
		IsChange = TRUE;
	}
	return IsChange;
}

UINT32 GetVirtualSPDStructureSize(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN PEI_SMBUS_PPI *pSMBusPPI,	
	IN UINT8 SLOTINdex ,
	IN DRAM_INFO_SAVE DramInfoSave
)
{
	EFI_STATUS      Status  = EFI_CRC_ERROR;
	UINT32  		NumberOfSpd ;
	UINT8 			Index 		= 0;
	UINT16  		SPDIndex 	= 0;
	NumberOfSpd = 0;
	Index 		= SLOTINdex;
#if defined(HX002EL0_05)
{
	UINT8 	InstalledDimm ;
	UINT16 Index16;
	UINT32 Spd_addr;
	ZX_SPI_SPD_BLOCK *Spd;
	Spd_addr =  0x00108000 + 0xFF800000;
	Spd = (ZX_SPI_SPD_BLOCK *)(Spd_addr);
	if(ASIA_VIRTUAL_SPD_SIGNATURE != (Spd->Signature))
	{
		AsiaIoWrite8(0x80, 0x20);	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[MCM]Signature = %x",Spd->Signature));	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[MCM]SPD Data value invalid"));	
		while(1);
	}
	InstalledDimm = (Spd->Slot_type); //bit3=dimmA6, bit2=dimmA4, bit1=dimmA2, bit0=dimmA0		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "before Hardcode Slot_Type = %d SPD_type = %d \n",InstalledDimm,Spd->SPD_Type));
	if(InstalledDimm & (1<<Index))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Hardcode SPD @ DIMM %d\n",Index));
		if((Spd->SPD_Type)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Signal_Buffer SPD value = %d \n",Spd->Signal_Buffer[0]));
			for (Index16 = 0; Index16 < SPD_SIZE; Index16++){
				DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[Index16]=Spd->Signal_Buffer[Index16];
			}	
		}
		else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dual_Buffer SPD Value = %d \n",Spd->Dual_Buffer[0]));
			for (Index16 = 0; Index16 < SPD_SIZE; Index16++){
				DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[Index16]=Spd->Dual_Buffer[Index16];
			}					
		}			
		Status = EFI_SUCCESS;		
		DramAttr->SpdData[DramAttr->AttrNo][Index].SpdPresent = TRUE;
		NumberOfSpd = NumberOfSpd +1 ;
		Status = EFI_SUCCESS;
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Skip SPD @ DIMM %x\n", Index));
		DramAttr->SpdData[DramAttr->AttrNo][Index].SpdPresent = FALSE;
		for (SPDIndex = 0; SPDIndex < SPD_SIZE; SPDIndex++){
			DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[SPDIndex] = 0;
		}
		Status = EFI_NOT_READY;
	}		
	if(EFI_SUCCESS == Status){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "DIMM %x is OK \n",Index ));
	}
}
#else
{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Before Use SMBUS Get SPD\n"));
	Status = GetSPDData(PeiServices, pSMBusPPI, Index, SPD_SIZE, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer);		
	if(EFI_SUCCESS == Status){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "DIMM %x is OK \n",Index ));
		DramAttr->SpdData[DramAttr->AttrNo][Index].SpdPresent = TRUE;
		NumberOfSpd = NumberOfSpd +1 ;	
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Skip SPD @ DIMM %x\n", Index));
		DramAttr->SpdData[DramAttr->AttrNo][Index].SpdPresent = FALSE;
		for (SPDIndex = 0; SPDIndex < SPD_SIZE; SPDIndex++){
			DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[SPDIndex] = 0;	
		}	
	}
}
#endif
	return NumberOfSpd;
}

EFI_STATUS GetBasicInformation(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
)
{
	UINT8             Index = 0;
	UINT8             Data;
	UINT8 		    highest=0, highestFreq = 0, FreqOffset = 0;
	UINT16          highestDramCycle = 0;
	ASIA_SPD_DATA     *CurrentSpdData ;
	UINT32  		NumberOfSpd=0 ;
	EFI_STATUS         Status;   
	BOOLEAN            DimmPresent = FALSE;
   	DRAM_INFO_SAVE 	   DramInfoSave;
//LGE20180716 only for single-S	
	EFI_ASIA_NB_PPI    *AsiaNbPPI;
	EFI_GUID           AsiaNbPPIGuid = EFI_ASIA_NB_PPI_GUID;
//LGE20180716 only for single-e	
	UINT8              Dimm0Type, Dimm1Type;
	UINT64             Address;
	//LGE20180716 only for single-S
	PEI_SMBUS_PPI 	   *pSMBusPPI;
	EFI_GUID SMBusGUID = PEI_SMBUS_PPI_GUID;	
	UINTN              VarSize;

#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    EFI_PEI_READ_ONLY_VARIABLE_PPI	  *VarPpi;
#else
   EFI_PEI_READ_ONLY_VARIABLE2_PPI	 *Var2Ppi;
#endif
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariablePpiGuid1, 0, NULL, (VOID**)&VarPpi);     
	VarSize = sizeof(DRAM_INFO_SAVE); 
	Status  = VarPpi->PeiGetVariable (
						PeiServices,
						NVINFO_DRAMINFO_VAR_NAME,
						&gAsiaDramInfoSaveGuid,
						NULL,
						&VarSize,
						&DramInfoSave
						);
#else
	Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariable2PpiGuid1, 0, NULL, (VOID**)&Var2Ppi);	
	VarSize = sizeof(DRAM_INFO_SAVE);
	Status	= Var2Ppi->GetVariable (
					Var2Ppi,
					NVINFO_DRAMINFO_VAR_NAME,
					&gAsiaDramInfoSaveGuid,
					NULL,
					&VarSize,
					&DramInfoSave
					);
#endif

	//Get Pcie Base Address
	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaNbPPIGuid, 0, NULL, &AsiaNbPPI);
	PEI_ASSERT(PeiServices, (!EFI_ERROR(Status)));
	DramAttr->PcieBaseAddress = ((ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg))->PcieBar;
		
	DramAttr->CHX002_BUS_NUM = CHX002_HB_BUS;
	DramAttr->AttrNo = 0;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "+++ AttrNo=%d +++\n", DramAttr->AttrNo));
	Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
	ASSERT_PEI_ERROR (PeiServices, Status);	
	//LGE20180716 only for single-E 
		
	//Step 1. SPD data
	for(Index=0; Index < ASIA_MAX_SOCKETS; Index++){
		NumberOfSpd = GetVirtualSPDStructureSize(PeiServices,DramAttr,pSMBusPPI,Index,DramInfoSave);				
		if(NumberOfSpd){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "DIMM %x is OK \n",Index ));
			DimmPresent = TRUE;
		}
	
	}	

	if (!DimmPresent){
		return EFI_NOT_FOUND;
	}
  
	//Show SPD information
	PEI_DEBUG_CODE(
	{
		UINT8 Index1;
		UINT8 Index2;

		for (Index = 0; Index < ASIA_MAX_SOCKETS; Index++) {	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "SPD For DIMM %x\n", Index ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "--+-----------------------------------------------\n"));
			for (Index1 = 0; Index1 < 32; Index1++) {	
				if (Index1*16 < SPD_SIZE)
					PEI_DEBUG((PeiServices, EFI_D_INFO, "%02x|",Index1*16));	
			for (Index2 = 0; Index2 < 16; Index2++) {
				if (Index1 * 16 + Index2 < SPD_SIZE)
				  PEI_DEBUG((PeiServices,EFI_D_ERROR," %02x",DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[Index1 * 16 + Index2]));
				}
			if (Index1 * 16 + Index2 < SPD_SIZE)
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
			}
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
		}
  	}
  	)
    	
	//Step 2. Channel A (0) DRAM type  (1) DIMM number, (2) Raw card, (3) Presented Rank, and (4) data width
	DramAttr->ChARankNumber[DramAttr->AttrNo] = 0; //range: 0~4
	DramAttr->ChADRAMChipDataWidth[DramAttr->AttrNo] = 0;	//8: x8 chip, 16: x16 chip
	DramAttr->ChADIMMNumber[DramAttr->AttrNo] = 0; //range:0~2
	DramAttr->ChAChipNumber[DramAttr->AttrNo] = 0; //range:0~32
	DramAttr->RankPresent[DramAttr->AttrNo] = 0;	// Bit[3:0]/bit[7:4] indicates Rank Presence of Channel A/B
    DramAttr->DramType = RAMTYPE_SDRAMDDR4;
	
	Dimm0Type = 0;
	Dimm1Type = 0;
	for (Index = 0; Index < (ASIA_MAX_SOCKETS/2); Index++){	
		
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);

		if (CurrentSpdData->SpdPresent) {
			//(1) DIMM number
			DramAttr->ChADIMMNumber[DramAttr->AttrNo]++;	

			//(2) Raw card
			{ 		  
				UINT8 ModuleType = CurrentSpdData->Buffer[DDR4_SPD_MODULE_TYPE];
				UINT8 RanksNumber = ((CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x38) >> 3) + 1;
				UINT8 DeviceWidth = 4 << (CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x07);
				UINT8 BusWidth = CurrentSpdData->Buffer[DDR4_SPD_BUS_WIDTH] & 0x1F;
				
				if(1==Index){
					//Dimm1Type = CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F;
					Dimm1Type =	GetSpdRawcard(ModuleType ,CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F);
					PEI_DEBUG((PeiServices, EFI_D_INFO, "***CHA Dimm1Type rawcard = %x ***\n",Dimm1Type));
					if(Dimm1Type == RAW_CARD_ZZ)
					{
						Dimm1Type = GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth);
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard ZZ***\n"));
					}

					
					if(Dimm1Type!=GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth)){
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard doesn't match***\n"));
						AsiaIoWrite8(0x80, 0x2E);
						while(1);
					}
					
					if(Dimm1Type>=0x0F){
						Dimm1Type = RAW_CARD_O;
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: Not support rawcard***\n"));
						AsiaIoWrite8(0x80, 0x2F);
						while(1);
					}
				}
				else{
				
					//Dimm0Type = CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F;
                    Dimm0Type =	GetSpdRawcard(ModuleType ,CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F);
					PEI_DEBUG((PeiServices, EFI_D_INFO, "***CHA Dimm0Type rawcard = %x ***\n",Dimm0Type));

					if(Dimm0Type == RAW_CARD_ZZ)
					{
						Dimm0Type = GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth);
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard ZZ***\n"));
					}

					
					if(Dimm0Type!=GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth)){
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard doesn't match***\n"));
						AsiaIoWrite8(0x80, 0x2E);
						while(1);
					}
					
					if(Dimm0Type>=0x0F){
						Dimm0Type = RAW_CARD_O;
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: Not support rawcard***\n"));
						AsiaIoWrite8(0x80, 0x2F);
						while(1);
					}
				}	
			}
			DramAttr->Dimm0Type[DramAttr->AttrNo] = Dimm0Type;
			DramAttr->Dimm1Type[DramAttr->AttrNo] = Dimm1Type;

			//(3) Count presented rank
			Data = CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x38;
			Data >>= 3;
			Data++;	// Actual Ranks Numbers
			DramAttr->ChARankNumber[DramAttr->AttrNo] = DramAttr->ChARankNumber[DramAttr->AttrNo] + Data;
			if (Data == 2) 
				DramAttr->RankPresent[DramAttr->AttrNo] |=  (0x03 << (Index * 2));
			else
				DramAttr->RankPresent[DramAttr->AttrNo] |=  (0x01 << (Index * 2));

			// (4) data width
			// Question: How about x8 & x16 co-exist?
			Data = CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x07; 
			Data = (4 << Data);
			DramAttr->ChADRAMChipDataWidth[DramAttr->AttrNo] = Data;

		}else{

			if(1==Index)	Dimm1Type = RAW_CARD_O;
			else			Dimm0Type = RAW_CARD_O;
		}
	}
	DramAttr->ChARawCardType[DramAttr->AttrNo] = Dimm0Type | (Dimm1Type << 4);

	//if user plugs two different raw card types, force them to use the same raw card type setting
	if((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) && (Dimm0Type != Dimm1Type))
	{
		DramAttr->MixDimmType = TRUE;
		//SO-DIMM
		if ((Dimm0Type == RAW_CARD_F) || (Dimm1Type == RAW_CARD_F))
			DramAttr->ChARawCardType[DramAttr->AttrNo] = RAW_CARD_FF;
		else if ((Dimm0Type == RAW_CARD_A) || (Dimm1Type == RAW_CARD_A))
			DramAttr->ChARawCardType[DramAttr->AttrNo] = RAW_CARD_AA;
		else if ((Dimm0Type == RAW_CARD_B) || (Dimm1Type == RAW_CARD_B))
			DramAttr->ChARawCardType[DramAttr->AttrNo] = RAW_CARD_BB;
		else if ((Dimm0Type == RAW_CARD_C) || (Dimm1Type == RAW_CARD_C))
			DramAttr->ChARawCardType[DramAttr->AttrNo] = RAW_CARD_CC;
		else if ((Dimm0Type == RAW_CARD_D) || (Dimm1Type == RAW_CARD_D))
			DramAttr->ChARawCardType[DramAttr->AttrNo] = RAW_CARD_DD;
		else if ((Dimm0Type == RAW_CARD_E) || (Dimm1Type == RAW_CARD_E))
			DramAttr->ChARawCardType[DramAttr->AttrNo] = RAW_CARD_EE;
		
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"ChARawCardType!=%x\n",DramAttr->ChARawCardType[DramAttr->AttrNo]));
	}  

	//Calculate chip number
	if(DramAttr->ChADRAMChipDataWidth[DramAttr->AttrNo] != 0)
		DramAttr->ChAChipNumber[DramAttr->AttrNo] = (64 / DramAttr->ChADRAMChipDataWidth[DramAttr->AttrNo]) * DramAttr->ChARankNumber[DramAttr->AttrNo];

	//Step 3. Channel B (1) DIMM number, (2) Raw card, (3) Presented Rank, and (4) data width
	DramAttr->ChBRankNumber[DramAttr->AttrNo] = 0; //range: 0~4
  	DramAttr->ChBDRAMChipDataWidth[DramAttr->AttrNo] = 0x00;	//8: x8 chip, 16: x16 chip
  	DramAttr->ChBDIMMNumber[DramAttr->AttrNo] = 0; //range:0~2
  	DramAttr->ChBChipNumber[DramAttr->AttrNo] = 0; //range:0~32
	
	Dimm0Type = 0;
	Dimm1Type = 0;
	for (Index = 0; Index < (ASIA_MAX_SOCKETS/2); Index++){	
		
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index+2]);
	
		if (CurrentSpdData->SpdPresent){

			//(1) DIMM number
			DramAttr->ChBDIMMNumber[DramAttr->AttrNo]++;	

			//(2) Raw card
			{ 		  
				UINT8 ModuleType = CurrentSpdData->Buffer[DDR4_SPD_MODULE_TYPE];
				UINT8 RanksNumber = ((CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x38) >> 3) + 1;
				UINT8 DeviceWidth = 4 << (CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x07);
				UINT8 BusWidth = CurrentSpdData->Buffer[DDR4_SPD_BUS_WIDTH] & 0x1F;

				if(1==Index){
					//Dimm1Type = CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F;
					Dimm1Type =	GetSpdRawcard(ModuleType ,CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F);
					PEI_DEBUG((PeiServices, EFI_D_INFO, "***CHB Dimm1Type rawcard = %x ***\n",Dimm1Type));
					if(Dimm1Type == RAW_CARD_ZZ)
					{
						Dimm1Type = GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth);
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard ZZ***\n"));
					}

					if(Dimm1Type!=GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth)){
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard doesn't match***\n"));
						AsiaIoWrite8(0x80, 0x2E);
						while(1);
					}
					
					if(Dimm1Type>=0x0F){
						Dimm1Type = RAW_CARD_O;
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: Not support rawcard***\n"));
						AsiaIoWrite8(0x80, 0x2F);
						while(1);
					}

				}
				else{
					//Dimm0Type = CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F;
					Dimm0Type =	GetSpdRawcard(ModuleType ,CurrentSpdData->Buffer[DDR4_SPD_REFERENCE_RAW_CARD] & 0x1F);
					PEI_DEBUG((PeiServices, EFI_D_INFO, "***CHB Dimm0Type rawcard = %x ***\n",Dimm0Type));

					
					if(Dimm0Type == RAW_CARD_ZZ)
					{
						Dimm0Type = GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth);
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard ZZ***\n"));
					}	
					
					if(Dimm0Type!=GetDIMMType(ModuleType, RanksNumber, DeviceWidth, BusWidth)){
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: SPD Rawcard doesn't match***\n"));
						AsiaIoWrite8(0x80, 0x2E);
						while(1);
					}
					
					if(Dimm0Type>=0x0F){ 		  
						Dimm0Type = RAW_CARD_O;
						PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: Not support rawcard***\n"));
						AsiaIoWrite8(0x80, 0x2F);
						while(1);
					}
				}
			}	
			DramAttr->Dimm2Type[DramAttr->AttrNo] = Dimm0Type;
			DramAttr->Dimm3Type[DramAttr->AttrNo] = Dimm1Type;

			//(3) Count presented rank
			Data = CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x38;
			Data >>= 3;
			Data++;	// Actual Ranks Numbers
			DramAttr->ChBRankNumber[DramAttr->AttrNo] = DramAttr->ChBRankNumber[DramAttr->AttrNo] + Data;
			if (Data == 2) 
				DramAttr->RankPresent[DramAttr->AttrNo] |=  (0x03 << ((Index+2) * 2));
			else
				DramAttr->RankPresent[DramAttr->AttrNo] |=  (0x01 << ((Index+2) * 2));

			// (4) data width
			// Question: How about x8 & x16 co-exist?
			Data = CurrentSpdData->Buffer[DDR4_SPD_MODULE_ORG] & 0x07;
			Data = (4 << Data);
			DramAttr->ChBDRAMChipDataWidth[DramAttr->AttrNo] = Data;
		}else{
		
			if(1==Index)	Dimm1Type = RAW_CARD_O;
			else			Dimm0Type = RAW_CARD_O;
		}
	}
	DramAttr->ChBRawCardType[DramAttr->AttrNo] = Dimm0Type | (Dimm1Type << 4);	

	//if user plugs two different raw card types, force them to use the same raw card type setting
	if((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) && (Dimm0Type != Dimm1Type))
	{
		DramAttr->MixDimmType = TRUE;
		//SO-DIMM
		if ((Dimm0Type == RAW_CARD_F) || (Dimm1Type == RAW_CARD_F))
			DramAttr->ChBRawCardType[DramAttr->AttrNo] = RAW_CARD_FF;
		else if ((Dimm0Type == RAW_CARD_A) || (Dimm1Type == RAW_CARD_A))
			DramAttr->ChBRawCardType[DramAttr->AttrNo] = RAW_CARD_AA;
		else if ((Dimm0Type == RAW_CARD_B) || (Dimm1Type == RAW_CARD_B))
			DramAttr->ChBRawCardType[DramAttr->AttrNo] = RAW_CARD_BB;
		else if ((Dimm0Type == RAW_CARD_C) || (Dimm1Type == RAW_CARD_C))
			DramAttr->ChBRawCardType[DramAttr->AttrNo] = RAW_CARD_CC;
		else if ((Dimm0Type == RAW_CARD_D) || (Dimm1Type == RAW_CARD_D))
			DramAttr->ChBRawCardType[DramAttr->AttrNo] = RAW_CARD_DD;
		else if ((Dimm0Type == RAW_CARD_E) || (Dimm1Type == RAW_CARD_E))
			DramAttr->ChBRawCardType[DramAttr->AttrNo] = RAW_CARD_EE;
		
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"ChBRawCardType!=%x\n",DramAttr->ChBRawCardType[DramAttr->AttrNo]));
	}
	
	//Calculate chip number
	if(DramAttr->ChBDRAMChipDataWidth[DramAttr->AttrNo] != 0)
		DramAttr->ChBChipNumber[DramAttr->AttrNo] = (64 / DramAttr->ChBDRAMChipDataWidth[DramAttr->AttrNo]) * DramAttr->ChBRankNumber[DramAttr->AttrNo];

//D0F6 Rx49 CHA DIMM Combination 
	if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_3+1);
		if(DramAttr->ChARankNumber[DramAttr->AttrNo] == 1) 
			AsiaPcieModify8(DramAttr->PcieBaseAddress ,Address, 0x0F,CHA_R1xD1);   //rx49[3:0]
		else
			AsiaPcieModify8(DramAttr->PcieBaseAddress ,Address, 0x0F,CHA_R2xD1);		
	}
	else if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_3+1);
		if(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)
			AsiaPcieModify8(DramAttr->PcieBaseAddress ,Address, 0x0F,CHA_R1xD2);
		else
			AsiaPcieModify8(DramAttr->PcieBaseAddress ,Address, 0x0F,CHA_R2xD2);
	}
	//RxD0F6 Rx4C[0] Rx4C[1] indicate dimm exist
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_4);
	if(DramAttr->ChARankNumber[DramAttr->AttrNo] != 0){
		AsiaPcieModify8(DramAttr->PcieBaseAddress ,Address, 0x01,CHA_DIMM_1<<0);            //rx4c[0]
	}
	else{
		AsiaPcieModify8(DramAttr->PcieBaseAddress ,Address, 0x01,CHA_DIMM_0<<0);
	}	
	//D0F6 Rx4B CHB DIMM Combination 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_3+3);
	if(DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1){
		if(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1) 
			AsiaPcieModify8( DramAttr->PcieBaseAddress ,Address, 0x0F,CHB_R1xD1);   //rx4B[3:0]
		else
			AsiaPcieModify8( DramAttr->PcieBaseAddress ,Address, 0x0F,CHB_R2xD1);
	}
	else if(DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2){
		if(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)
			AsiaPcieModify8( DramAttr->PcieBaseAddress ,Address, 0x0F,CHB_R1xD2);
		else
			AsiaPcieModify8( DramAttr->PcieBaseAddress ,Address, 0x0F,CHB_R2xD2);
	}
	//RxD0F6 Rx4C[0] Rx4C[1] indicate dimm exist
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_4);
	if(DramAttr->ChBRankNumber[DramAttr->AttrNo] != 0){
		AsiaPcieModify8( DramAttr->PcieBaseAddress ,Address, 0x02,CHB_DIMM_1<<1);            //rx4c[1]
	}
	else{
		AsiaPcieModify8( DramAttr->PcieBaseAddress ,Address, 0x02,CHB_DIMM_0<<1);
	}	
   	
	//Step 4. DRAM Frequency and Cylcle Time
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN,D0F6_BIOS_SCRATCH_REG_3);
   
		//Data == F_SPD
		// Get frequency from SPD
		// 10	--> 1.25ns means DDR1600
		// 12	--> 1.5ns means DDR1333
		// 15	--> 1.875ns means DDR1066
		// 20	--> 2.5ns means DDR800
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
			CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
			if ( CurrentSpdData->SpdPresent ) {
				  Data = CurrentSpdData->Buffer[DDR4_SPD_MIN_CYCLE_TIME];
			if (Data > highest)
			{
				highest = Data;
				FreqOffset = CurrentSpdData->Buffer[DDR4_SPD_MIN_CYCLE_TIME_FINE_OFFSET];				
			}	
		}
      }
		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DRAM_FREQ2 :%x\n",highest));
    switch (highest) {
	  //Add 2933 support	
	    case 5:
			highestFreq = DRAM_FREQ_3200;
			highestDramCycle = DRAM_CYCLE_3200;
			AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 6);
			break;
		case 6:
			if(FreqOffset == 0xBC)
			{				
				highestFreq = DRAM_FREQ_2933;
				highestDramCycle = DRAM_CYCLE_2933;
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 5);
			}
			else
			{
				highestFreq = DRAM_FREQ_2666;
				highestDramCycle = DRAM_CYCLE_2666;
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 4);
			}
			break;
		case 7:
			highestFreq = DRAM_FREQ_2400;
			highestDramCycle = DRAM_CYCLE_2400;
			AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 3); 
			break;
        case 8:
			highestFreq = DRAM_FREQ_2133;
			highestDramCycle = DRAM_CYCLE_2133;
			AsiaPcieWrite8(DramAttr->PcieBaseAddress ,Address, 2); 
			break;
		case 9:
			highestFreq = DRAM_FREQ_1866;
			highestDramCycle = DRAM_CYCLE_1866;
			AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 1); 
			break;
		case 10:
			highestFreq = DRAM_FREQ_1600; 
			highestDramCycle = DRAM_CYCLE_1600; 
			AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 0);
			break;
		case 12:
			highestFreq = DRAM_FREQ_1333; 
			highestDramCycle = DRAM_CYCLE_1333; 
			break;
		case 15: 	
			highestFreq = DRAM_FREQ_1066; 
			highestDramCycle = DRAM_CYCLE_1066; 
			break;
		case 20: 	
			highestFreq = DRAM_FREQ_800; 
			highestDramCycle = DRAM_CYCLE_800; 
			break;
		default:		
			highestFreq = DRAM_FREQ_1600; 
			highestDramCycle = DRAM_CYCLE_1600;			
			break;
      }	
	Data = DramAttr->ConfigData.DramClk;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DRAM_FREQ1 :%x\n",Data));	
	if (Data != DRAM_CLK_BY_SPD) {
		switch (Data) {
			case DRAM_CLK_800MHZ: 
				DramAttr->DramFreq = DRAM_FREQ_1600; 
				DramAttr->DramCycle = DRAM_CYCLE_1600; 
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 0);
				break;
			case DRAM_CLK_933MHZ:
				DramAttr->DramFreq = DRAM_FREQ_1866; 
				DramAttr->DramCycle = DRAM_CYCLE_1866;
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 1); 
				break;
			case DRAM_CLK_1066MHZ:
				DramAttr->DramFreq = DRAM_FREQ_2133; 
				DramAttr->DramCycle = DRAM_CYCLE_2133;
				AsiaPcieWrite8(DramAttr->PcieBaseAddress ,Address, 2); 
				break;
			case DRAM_CLK_1200MHZ:
				DramAttr->DramFreq = DRAM_FREQ_2400; 
				DramAttr->DramCycle = DRAM_CYCLE_2400;
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 3); 
				break;
			//DKS-20170515 add -s
			case DRAM_CLK_1333MHZ:
				DramAttr->DramFreq = DRAM_FREQ_2666; 
				DramAttr->DramCycle = DRAM_CYCLE_2666; 
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 4);
				break;
			case DRAM_CLK_1466MHZ:
				DramAttr->DramFreq = DRAM_FREQ_2933; 
				DramAttr->DramCycle = DRAM_CYCLE_2933;
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 5); 
				break;
			case DRAM_CLK_1600MHZ:
				DramAttr->DramFreq = DRAM_FREQ_3200; 
				DramAttr->DramCycle = DRAM_CYCLE_3200; 
				AsiaPcieWrite8( DramAttr->PcieBaseAddress ,Address, 6);
				break;
			//DKS-20170515 add -e
			default:	
				DramAttr->DramFreq = DRAM_FREQ_800; 
				DramAttr->DramCycle = DRAM_CYCLE_800; 
				break;
		}
		if(DramAttr->DramFreq > highestFreq)
		{
            PEI_DEBUG((PeiServices, EFI_D_INFO, "***DRAM ERROR: DramFreq Setting out of MAX frequency***\n"));
			AsiaIoWrite8(0x80, 0x2B);
			while(1);
             
		}
	}
	else {			
		DramAttr->DramFreq = highestFreq;
		DramAttr->DramCycle = highestDramCycle;
	}
	
	//Step 5. DRAM command rate
	switch ( DramAttr ->ConfigData.CmdRate){
		case CMD_RATE_2T: 
			DramAttr->Dram1TCommandRate = CMD_2T; 
			break;			
		case CMD_RATE_1T://Force Enable
			DramAttr->Dram1TCommandRate = CMD_1T; 
			break; 
		default: 
			DramAttr->Dram1TCommandRate = CMD_2T; 
			break;
	}
 
	//Step 6. DRAM burst length
	if (DramAttr->ConfigData.BurstLength == BURST_LENGTH_8B)
		DramAttr->BurstLength8 = BL8;
	else
		DramAttr->BurstLength8 = BL_ONTHEFLY;

		
	//Step 8. Registered Dimm
	DramAttr->RegDimm= IS_REG_DIMM;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if ( CurrentSpdData->SpdPresent ) {
			   Data = CurrentSpdData->Buffer[DDR4_SPD_MODULE_TYPE] & 0x0F;
			DramAttr->ModuleType = Data;
			if (Data != 0x01){
				//No Register DIMM is presented
				DramAttr->RegDimm = NOT_REG_DIMM;
			}
		}
	}

	//ECC Dimm
	DramAttr->ECCSupport = Support_ECC;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if ( CurrentSpdData->SpdPresent ) {
			Data = CurrentSpdData->Buffer[DDR4_SPD_BUS_WIDTH] & 0x1F;
			if (Data != 0x0B){
				//A non-ECC DIMM is present
				DramAttr->ECCSupport = NO_ECC;
			}
		}
	}
    //3DS DRAM
    DramAttr->Dram3DS = DRAM_3DS;
    for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if ( CurrentSpdData->SpdPresent ) {
			Data = CurrentSpdData->Buffer[DDR4_SPD_PACKAGE_TYPE];
			if((Data & 0x03) == 0x02)
			{				
				DramAttr->DieCount = ((Data & 0x70) >> 4) + 1;
			}
			else
				DramAttr->Dram3DS = NOT_3DS;
		}
    }


	//Read & Write Preamble
	DramAttr->WPREA = WPREA1CLK;
	DramAttr->RPREA = RPREA1CLK;
	DramAttr->ConfigData.TNIHighPulse =  Low_Pulse;
	if(DramAttr->DramFreq >= DRAM_FREQ_2400)
	{
		DramAttr->WPREA = WPREA1CLK;
		
	}
	if(DramAttr->DramFreq >= DRAM_FREQ_2400)
	{   
		DramAttr->RPREA = RPREA2CLK;
		DramAttr->ConfigData.TNIHighPulse = High_Pulse;
	}

	
   
	
	//Step 9. Rank1 address mapping feature
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if ( CurrentSpdData->SpdPresent ) {
              if(DramAttr->RegDimm == IS_REG_DIMM)
			     Data = CurrentSpdData->Buffer[DDR4_RDIMM_SPD_RANK1_ADDRMAPPING] & 0x01;
			  else
			  	 Data = CurrentSpdData->Buffer[DDR4_UDIMM_SPD_RANK1_ADDRMAPPING] & 0x01;
			if (Data == 0x01){
				//Rank 1 address mirrored
				DramAttr->Rank1Mapping[DramAttr->AttrNo][Index*2] = RANK1_MAPPING_STANDARD;
				DramAttr->Rank1Mapping[DramAttr->AttrNo][Index*2+1] = RANK1_MAPPING_MIRRORED;
			} else {
	             		//Rank 1 address standard
	              	DramAttr->Rank1Mapping[DramAttr->AttrNo][Index*2] = RANK1_MAPPING_STANDARD;
	              	DramAttr->Rank1Mapping[DramAttr->AttrNo][Index*2+1] = RANK1_MAPPING_STANDARD;
	          	}
     		}
	}

	//Step 10. output driver impedance
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
        
		if ( CurrentSpdData->SpdPresent ) {
			//DDR4			
			DramAttr->OutputDriver[DramAttr->AttrNo][Index] = MR1_DDR4_RZQ7;
        }		
	}

	//DRAM chip ODT value
	if (DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1){
		if (DramAttr->ChARankNumber[DramAttr->AttrNo] == 1) {
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_DIS;
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_DIS;
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_120OHM;
			}
		}
		else if (DramAttr->ChARankNumber[DramAttr->AttrNo] == 2){
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_DIS;
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_DIS;
				//DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_120OHM;
				//Daisy patch for DDR2666 2R SODIMM FAIL ISSUE
				if((DramAttr->ModuleType==0x3)&&(DramAttr->DramFreq == DRAM_FREQ_2666))
					DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_80OHM;
				else
					DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_120OHM;
					
			}
		}
	} 
	else if( DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) {
		if (DramAttr->ChARankNumber[DramAttr->AttrNo] == 2) {
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_48OHM;
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_120OHM;
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_48OHM;
			}
		}
		else if (DramAttr->ChARankNumber[DramAttr->AttrNo] == 4){
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_34OHM;
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_240OHM;
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_80OHM;
			}
		}
	}

	if (DramAttr->ConfigData.MemoryChipODTDebug != MEM_CHIP_ODT_DBG_AUTO){
		for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++){
			if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_DISABLE)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_DIS;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_60OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_60OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_120OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_120OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_40OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_40OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_240OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_240OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_48OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_48OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_80OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_80OHM;
			else
				DramAttr->RttNominal[DramAttr->AttrNo][Index] = MR1_DDR4_RTT_NOM_34OHM;
		}
	}

	if (DramAttr->ConfigData.MemoryChipODTWRDebug != MEM_CHIP_ODT_DBG_AUTO){
		for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++){
			if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_DISABLE)
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_DIS;
			else if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_80OHM)
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_80OHM;
			else if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_120OHM)
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_120OHM;
			else if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_240OHM)
				DramAttr->RttWR[DramAttr->AttrNo][Index] = MR2_DDR4_RTT_WR_240OHM;
		}
	}

	
	if(DramAttr->ConfigData.MemoryChipODTParkDebug != MEM_CHIP_ODT_DBG_AUTO){
		for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++){
			if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_DISABLE)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_DIS;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_60OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_60OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_120OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_120OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_40OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_40OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_240OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_240OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_48OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_48OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_80OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_80OHM;
			else
				DramAttr->RttPark[DramAttr->AttrNo][Index] = MR5_DDR4_RTT_PARK_34OHM;
		}

	}


	if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1){
		if (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1) {
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_DIS;
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_DIS;
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_120OHM;
			}
		}
		else if (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2){
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_DIS;
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_DIS;
				//DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_120OHM;
				//Daisy patch for DDR2666 2R SODIMM FAIL ISSUE
				if((DramAttr->ModuleType==0x3)&&(DramAttr->DramFreq == DRAM_FREQ_2666))
					DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_80OHM;
				else
					DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_120OHM;
			}
		}
	} 
	else if( DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) {
		if (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2) {
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_48OHM;
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_120OHM;
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_48OHM;
			}
		}
		else if (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 4){
			for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++) {	
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_34OHM;
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_240OHM;
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_80OHM;
			}
		}		
	}

	if (DramAttr->ConfigData.MemoryChipODTDebug != MEM_CHIP_ODT_DBG_AUTO){
		for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++){
			if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_DISABLE)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_DIS;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_60OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_60OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_120OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_120OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_40OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_40OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_240OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_240OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_48OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_48OHM;
			else if (DramAttr->ConfigData.MemoryChipODTDebug == MEM_CHIP_ODT_DBG_80OHM)
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_80OHM;
			else
				DramAttr->RttNominal[DramAttr->AttrNo][Index+4] = MR1_DDR4_RTT_NOM_34OHM;
		}
	}

	if (DramAttr->ConfigData.MemoryChipODTWRDebug != MEM_CHIP_ODT_DBG_AUTO){
		for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++){
			if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_DISABLE)
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_DIS;
			else if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_80OHM)
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_80OHM;
			else if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_120OHM)
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_120OHM;
			else if (DramAttr->ConfigData.MemoryChipODTWRDebug == MEM_CHIP_ODT_DBG_240OHM)
				DramAttr->RttWR[DramAttr->AttrNo][Index+4] = MR2_DDR4_RTT_WR_240OHM;
		}
	}
	if(DramAttr->ConfigData.MemoryChipODTParkDebug != MEM_CHIP_ODT_DBG_AUTO){
		for (Index = 0; Index < (ASIA_MAX_RANKS/2); Index++){
			if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_DISABLE)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_DIS;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_60OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_60OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_120OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_120OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_40OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_40OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_240OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_240OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_48OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_48OHM;
			else if (DramAttr->ConfigData.MemoryChipODTParkDebug == MEM_CHIP_ODT_DBG_80OHM)
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_80OHM;
			else
				DramAttr->RttPark[DramAttr->AttrNo][Index+4] = MR5_DDR4_RTT_PARK_34OHM;
		}

	}

	// DramFastBoot
	DramAttr->DramFastBoot = DRAM_FAST_BOOT_DISABLE;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if ( CurrentSpdData->SpdPresent ) {
			DramAttr->MfrInfo[DramAttr->AttrNo][Index].MFR_ID = (CurrentSpdData->Buffer[DDR4_DPD_MODULE_MANUFACTURING_ID_MSB] << 8)
				|(CurrentSpdData->Buffer[DDR4_DPD_MODULE_MANUFACTURING_ID_LSB]); 
			DramAttr->MfrInfo[DramAttr->AttrNo][Index].SERIAL_NO = (CurrentSpdData->Buffer[DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE03] << 24)
				| (CurrentSpdData->Buffer[DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE02] << 16)
				| (CurrentSpdData->Buffer[DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE01] << 8)
				| (CurrentSpdData->Buffer[DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE00]);
		}
		else
		{
			DramAttr->MfrInfo[DramAttr->AttrNo][Index].MFR_ID = 0;
			DramAttr->MfrInfo[DramAttr->AttrNo][Index].SERIAL_NO = 0; 
		}
	}
	if(DramAttr->ConfigData.DQSIByRank == BYRANK_AUTO){
		if(DramAttr->ModuleType == SODIMM_MODULE){
			DramAttr->ConfigData.DQSIByRank = BYRANK_DISABLE;
		}
		else{
			DramAttr->ConfigData.DQSIByRank = BYRANK_ENABLE;
		}
	}
	if(DramAttr->ConfigData.DramFastBoot == DRAM_FAST_BOOT_AUTO)
	{
		//DIMM Change 
		if(CheckDramChange(PeiServices, DramAttr))
		{
			//Fast Boot disable, will execute Dram Io Calibration
			DramAttr->DramFastBoot = DRAM_FAST_BOOT_DISABLE;
		}
		else
		{
			//Fast Boot Enable, will not execute Dram Io Calibration
			DramAttr->DramFastBoot = DRAM_FAST_BOOT_AUTO;
		}
	}
	else
	{
		//Fast Boot disable, will execute Dram Io Calibration
		DramAttr->DramFastBoot = DRAM_FAST_BOOT_DISABLE;
	}


 PEI_DEBUG((PeiServices, EFI_D_INFO, "------------------------------------------\n")); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "DramClk						 = %a\n", DRAMCLK[DCLKString(DramAttr->DramFreq)]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ModuleType					 = %a\n", ModuleType[DramAttr->ModuleType]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "RankPresent					 = %08X\n", DramAttr->RankPresent[DramAttr->AttrNo])); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "Command Rate					 = %a\n", CmdRate[DramAttr->Dram1TCommandRate])); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "Burst Length					 = %a\n", BL[DramAttr->BurstLength8])); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "RDIMM is						  %a\n", RDIMM[DramAttr->RegDimm])); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ECC DIMM is					  %a\n", ECCDIMM[DramAttr->ECCSupport])); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "Thermal Sensor DIMM is		  %a\n", TSDIMM[DramAttr->TSDIMM])); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "Write preamble				 = %02xCLK\n", DramAttr->WPREA + 1));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "Read Preamble 				 = %02xCLK\n", DramAttr->RPREA + 1));
 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "-------Channel A info 	 --------------------\n")); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChADIMMNumber 				 = %02x\n", DramAttr->ChADIMMNumber[DramAttr->AttrNo]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChARankNumber 				 = %02x\n", DramAttr->ChARankNumber[DramAttr->AttrNo]));
 for (Index = 0; Index < ASIA_MAX_SOCKETS-2; Index++) 
 {
	 if(DramAttr->RankPresent[DramAttr->AttrNo] & (1<<Index*2))
	{
		switch(DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x15F])
		{
			case 0xCE:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Samsung technology\n", Index));
			break;
			case 0x43:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Ramaxel technology\n", Index));
			break;
			case 0x2D:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Hynix technology\n", Index));
			break;
			case 0xAD:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Hynix technology\n", Index));				
			break;
			case 0x2C:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Micron technology\n", Index));
			break;
			case 0x18:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Kingston technology\n", Index));
			break;
			default :
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Other technology\n", Index));
		}		
		switch(DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x141])
		{
			case 0xCE:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Samsung technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0x43:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Ramaxel technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0x2D:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Hynix technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0xAD:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Hynix technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;			
			case 0x2C:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Micron technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0x18:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Kingston technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			default :
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Other technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
		}

	}
 }	 

 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChADRAMChipDataWidth			 = %02x\n", DramAttr->ChADRAMChipDataWidth[DramAttr->AttrNo]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChAChipNumber 				 = %02x\n", DramAttr->ChAChipNumber[DramAttr->AttrNo]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChARawCardType DIMM1			 = %a\n", RawCardType[(DramAttr->ChARawCardType[DramAttr->AttrNo] & 0x0F)]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChARawCardType DIMM2			 = %a\n", RawCardType[((DramAttr->ChARawCardType[DramAttr->AttrNo] & 0xF0) >> 4)]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChA Mirror rank 0/1/2/3		 = %a/%a/%a/%a\n", CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][0])], \
			 CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][1])], CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][2])], CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][3])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChA Output Driver Z dimm 0/1	 = %a, %a\n", mODZ[ODZ(DramAttr->OutputDriver[DramAttr->AttrNo][0])], mODZ[ODZ(DramAttr->OutputDriver[DramAttr->AttrNo][1])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChA Rtt_nominal 0/1/2/3		 = %a, %a, %a, %a\n", mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][0])], \
			 mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][1])], mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][2])], mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][3])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChA Rtt_wr 0/1/2/3			 = %a, %a, %a, %a\n", mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][0])], \
			 mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][1])], mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][2])], mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][3])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChA Rtt_park 0/1/2/3			 = %a, %a, %a, %a\n", mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][0])], \
			 mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][1])], mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][2])], mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][3])]));
 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "-------Channel B info 	 --------------------\n")); 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChBDIMMNumber 				 = %02x\n", DramAttr->ChBDIMMNumber[DramAttr->AttrNo]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChBRankNumber 				 = %02x\n", DramAttr->ChBRankNumber[DramAttr->AttrNo]));
  for (Index = 2; Index < ASIA_MAX_SOCKETS; Index++) 
 {
	 if(DramAttr->RankPresent[DramAttr->AttrNo] & (1<<Index*2))
	{
		switch(DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x15F])
		{
			case 0xCE:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Samsung technology\n", Index));
			break;
			case 0x43:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Ramaxel technology\n", Index));
			break;
			case 0x2D:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Hynix technology\n", Index));
			break;
			case 0xAD:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Hynix technology\n", Index));				
			break;
			case 0x2C:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Micron technology\n", Index));
			break;
			case 0x18:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Kingston technology\n", Index));
			break;
			default :
				PEI_DEBUG((PeiServices, EFI_D_INFO, "DRAM Chip Manufacturer%02d         = Other technology\n", Index));
		}		
		switch(DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x141])
		{
			case 0xCE:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Samsung technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0x43:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Ramaxel technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0x2D:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Hynix technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0xAD:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Hynix technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;			
			case 0x2C:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Micron technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			case 0x18:
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Kingston technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
			break;
			default :
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Manual_Facturer%02d 		         = Other technology\n", Index));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Serial_Number%02d 		         = %02x%02x%02x%02x\n", Index, DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x145],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x146],\
							DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x147],DramAttr->SpdData[DramAttr->AttrNo][Index].Buffer[0x148]));
		}

	}
 }	
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChBDRAMChipDataWidth			 = %02x\n", DramAttr->ChBDRAMChipDataWidth[DramAttr->AttrNo]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChBChipNumber 				 = %02x\n", DramAttr->ChBChipNumber[DramAttr->AttrNo]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChBRawCardType DIMM1			 = %a\n", RawCardType[(DramAttr->ChBRawCardType[DramAttr->AttrNo] & 0x0F)]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChBRawCardType DIMM2			 = %a\n", RawCardType[((DramAttr->ChBRawCardType[DramAttr->AttrNo] & 0xF0) >> 4)]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChB Mirror rank 0/1/2/3		 = %a/%a/%a/%a\n", CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][4])], \
			 CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][5])], CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][6])], CircleOrCross[(DramAttr->Rank1Mapping[DramAttr->AttrNo][7])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChB Output Driver Z dimm 0/1	 = %a, %a\n", mODZ[ODZ(DramAttr->OutputDriver[DramAttr->AttrNo][2])], mODZ[ODZ(DramAttr->OutputDriver[DramAttr->AttrNo][3])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChB Rtt_nominal 0/1/2/3		 = %a, %a, %a, %a\n", mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][4])], \
			 mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][5])], mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][6])], mRnom[Rnom(DramAttr->RttNominal[DramAttr->AttrNo][7])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChB Rtt_wr 0/1/2/3			 = %a, %a, %a, %a\n", mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][4])], \
			 mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][5])], mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][6])], mRwr[Rwr(DramAttr->RttWR[DramAttr->AttrNo][7])]));
 PEI_DEBUG((PeiServices, EFI_D_INFO, "ChB Rtt_park 0/1/2/3			 = %a, %a, %a, %a\n", mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][4])], \
			 mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][5])], mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][6])], mRpark[Rpark(DramAttr->RttPark[DramAttr->AttrNo][7])]));
 
 PEI_DEBUG((PeiServices, EFI_D_INFO, "------------------------------------------\n"));	

  
// DramAttr->EfuseData[0] = GetEfuseData(PeiServices,0x79);
// DramAttr->EfuseData[1] = GetEfuseData(PeiServices,0x7A);
	return EFI_SUCCESS;
}
