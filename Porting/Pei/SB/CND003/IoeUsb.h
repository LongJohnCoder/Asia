/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoeUsb.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef _IOE_PEI_USB_
#define _IOE_PEI_USB_


#include "IoePreInit.h"
EFI_STATUS
 EFIAPI
  IOEUsbPeiInit(IN EFI_PEI_SERVICES **PeiServices,
	ASIA_SB_CONFIGURATION* SbCfg 
  );

#endif
