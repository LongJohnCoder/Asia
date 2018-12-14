/** @file
   ZX-E(CHX002) Asia SbPei library functions : SataPei.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef __CHX002_SATA_H__
#define __CHX002_SATA_H__

#include "CHX002Reg.h"

EFI_STATUS
EFIAPI
SataInitPei(
  IN EFI_PEI_SERVICES      **PeiServices, 
  IN ASIA_SB_CONFIGURATION *SbCfg
);

#endif
