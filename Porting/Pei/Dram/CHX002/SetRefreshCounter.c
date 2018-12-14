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
#include "DramUtil.h"
#include "SetRefreshCounter.h"

/*
 *	Purpose: 
 *	Set DRAM refresh counter by DRAM frequency & MA Type
 */
EFI_STATUS SetRefreshCounter(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
    UINT64 Address;
    UINT16 REFC;
	//Refresh rate = 7.8 us
	//Program refresh counter value: (Refresh Count)*64*DCLK <= 7.8us	
	switch (DramAttr->DramFreq){
			case DRAM_FREQ_800:
				REFC = 0x30;
				break;
			case DRAM_FREQ_1066:			
				REFC = 0x40;
				break;		
			case DRAM_FREQ_1333:
				REFC = 0x51;
				break;
			case DRAM_FREQ_1600:
				REFC = 0x61;
				break;
			case DRAM_FREQ_1866:
				REFC = 0x71;
				break;
			case DRAM_FREQ_2133:
				REFC = 0x79;
				break;
			case DRAM_FREQ_2400:
				REFC = 0x92;
				break;
			case DRAM_FREQ_2666:
				REFC = 0xA2;
				break;	
			case DRAM_FREQ_2933:
				REFC = 0xB2;
				break;
			case DRAM_FREQ_3200:	
				REFC = 0xC3;			
				break;
			default:	
				REFC = 0x30;			
				break;			
		}

#ifdef	DDR4_800
	REFC = 0x30;
#endif

    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_REFC_7_0,ShiftToMaskBit(D0F3_REFC_7_0,REFC));
	
	return EFI_SUCCESS;
}


