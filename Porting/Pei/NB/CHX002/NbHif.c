
/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbHif.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/


#include "NBHif.h"


STATIC ASIA_IO_TABLE_6408_REV mHIFPeiInitSTbl[]= {
	//mVer	MVer	Reg Offset														Mask	Value
	0xFF, 	0x00,	0x00,															0x00,  	0x00
};

/**
   This Function do HIF init.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/

EFI_STATUS
PeiHIFInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	UINT64						PcieBase;
	UINT64						Address;
	EFI_BOOT_MODE				BootMode;
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiNbHIFInit()\n"));

	PcieBase = NbConfig->PcieBar;

    // Process V4IF init table
    PROCESS_NB_PCIE_R6408M_TABLE(PcieBase, mHIFPeiInitSTbl, sizeof(mHIFPeiInitSTbl)/sizeof(ASIA_IO_TABLE_6408_REV));

	//Base on the setup option to enable/disable the Round-Robin Mechanism
	if(NbConfig->RoundRobin)
	{
		//If enalbe?
		//Set D0F2RxCE[2] = 1b
		AsiaPciModify8(CHX002_HIF|D0F2_TPR_CTL,
				D0F2_RAPICROEN,
				D0F2_RAPICROEN);		
	}

    (*PeiServices)->GetBootMode (PeiServices, &BootMode);

    if(BootMode != BOOT_ON_S3_RESUME) 
   	{
		//Set RFBBS[39:21] = 256M temporarily to avoid DRAM Initial casue DVAD error.
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL);
	    AsiaPcieModify32(PcieBase, Address, D0F3_RFBBS_35_21, 0x100<<1);
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	    AsiaPcieModify32(PcieBase, Address, D0F3_RFBBS_39_36, 0x00);
   	}

    return EFI_SUCCESS;

}

