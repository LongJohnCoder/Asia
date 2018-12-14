/** @file
   ZX-E(CHX002) Asia SbDxe library functions : SataDxe.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _CHX002_DXE_SATA_
#define _CHX002_DXE_SATA_

#include "CHX002Reg.h"

EFI_STATUS EFIAPI  SataInitDxe(
    ASIA_SB_CONFIGURATION* SbCfg 
  );

EFI_STATUS EFIAPI  SataInitPreBoot(
    ASIA_SB_CONFIGURATION* SbCfg 
  );

#endif
