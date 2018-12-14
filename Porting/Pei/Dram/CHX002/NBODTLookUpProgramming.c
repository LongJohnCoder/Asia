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
#include "Pei.h"
#include "Draminit.h"
#include "NBODTLookUpProgramming.h"




#define OdtLookupTblCount 8

#define Rank0_ODT				0
#define Rank1_ODT				1
#define Rank2_ODT				2
#define Rank3_ODT				3
#define NA_ODT					0

UINT8 OdtLookupTBL[OdtLookupTblCount][2] =
{
//	RankMAP        Rank 3             Rank 2             Rank 1           Rank 0	
    { 0x01, (Rank3_ODT << 6) +  (Rank2_ODT << 4) + (Rank0_ODT << 2) + Rank1_ODT},
    { 0x03, (Rank3_ODT << 6) +  (Rank2_ODT << 4) + (Rank0_ODT << 2) + Rank1_ODT},
    { 0x04, (Rank2_ODT << 6) +  (Rank3_ODT << 4) + (Rank1_ODT << 2) + Rank0_ODT},
    { 0x05, (Rank3_ODT << 6) +  (Rank0_ODT << 4) + (Rank1_ODT << 2) + Rank2_ODT},
    { 0x07, (Rank3_ODT << 6) +  (Rank0_ODT << 4) + (Rank2_ODT << 2) + Rank2_ODT},
    { 0x0c, (Rank2_ODT << 6) +  (Rank3_ODT << 4) + (Rank1_ODT << 2) + Rank0_ODT},
    { 0x0d, (Rank0_ODT << 6) +  (Rank0_ODT << 4) + (Rank1_ODT << 2) + Rank2_ODT},
    { 0x0f, (Rank1_ODT << 6) +  (Rank0_ODT << 4) + (Rank3_ODT << 2) + Rank2_ODT}
};


EFI_STATUS NBODTLookUpProgramming(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8       Index,RankPresent; 
	UINT64 	  Address;	
	// MAA ODT Lookup Table - CHA	
	RankPresent = DramAttr->RankPresent[DramAttr->AttrNo] & CHA_BITMAP;
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_LOOKUP_TABLE_FOR_CHN_B_A );
	
	for (Index = 0; Index < OdtLookupTblCount; Index++){
		if (RankPresent == OdtLookupTBL[Index][0]){ 
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,0x00FF, OdtLookupTBL[Index][1]);
		}
	}
	// MAA ODT Lookup Table - CHB
	RankPresent = DramAttr->RankPresent[DramAttr->AttrNo] & CHB_BITMAP;
	RankPresent >>= 4;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_LOOKUP_TABLE_FOR_CHN_B_A ); 
	for (Index = 0; Index < OdtLookupTblCount; Index++){
		if (RankPresent == OdtLookupTBL[Index][0]){ 
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,0xFF00, OdtLookupTBL[Index][1]<<8);
		}
	}
	return EFI_SUCCESS;
}
