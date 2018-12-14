/** @file
   ZX-E(CHX002) Asia SbDxe library functions : Hdac.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "HdAc.h"
#include "EfiDriverLib.h"
#include "CHX002Reg.h"
#include "AsiaIoLib.h"
#include "AsiaIoSaveLib.h"
#include "EfiScriptLib.h"

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
InitAzaliaAudio (
    IN  ASIA_SB_CONFIGURATION             *SbCfg
)
{
    UINT64                          Address;
    UINT8                           TmpdataB;
    UINT32                          TmpdataD;
    EFI_PHYSICAL_ADDRESS            TmpAddress;
    EFI_PHYSICAL_ADDRESS            HDAudioBar;
    
    //read HDAC MMIO upper base address
    Address = (CHX002_HDAC | D20F0_HDAC_UPPER_BASE_ADR);
    TmpAddress = (UINT64)AsiaPciRead32(Address);
    TmpAddress = LShiftU64(TmpAddress, 32);

    //read HDAC MMIO Lowerbase address
    Address = (CHX002_HDAC | D20F0_HDAC_LOWER_BASE_ADR);
    TmpdataD = AsiaPciRead32(Address);
    TmpAddress = TmpAddress | TmpdataD;

	//calculate base address
    HDAudioBar = TmpAddress & (~0x0F); 

	//save lower base address for S3 resume
    TmpdataD = TmpdataD & (~0x0F);
    SCRIPT_PCI_CFG_WRITE(
            EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
            EfiBootScriptWidthUint32,
            Address,
            0x01,
            &TmpdataD
            );
    
	//enable memory access and bus master
    Address = (CHX002_HDAC | D20F0_PCI_CMD);
    TmpdataB = 0x06;
    AsiaPciWriteSave8(Address, TmpdataB);

    return EFI_SUCCESS;
}
