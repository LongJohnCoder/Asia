/** @file
   ZX-E(CHX002) Asia SbPei library functions : UsbPei.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef __CHX002_USB_H__
#define __CHX002_USB_H__

#include "CHX002Reg.h"

EFI_STATUS
EFIAPI
UsbInitPei (
  IN EFI_PEI_SERVICES      **PeiServices, 
  IN ASIA_SB_CONFIGURATION *SbCfg
);

#endif
