/** @file
   ZX-E(CHX002) Asia SbDxe library functions : IoeDxeUsb.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef _IOE_DXE_USB_
#define _IOE_DXE_USB_

#include "CND003Reg.h"

#include "IoeDxeInit.h"
EFI_STATUS EFIAPI  IOEUsbDxeInit(
	ASIA_SB_CONFIGURATION* SbCfg 
  );
#endif
