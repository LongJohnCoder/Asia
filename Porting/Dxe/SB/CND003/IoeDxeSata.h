/** @file
   ZX-E(CHX002) Asia SbDxe library functions : IoeDxeSata.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef _IOE_DXE_SATA_
#define _IOE_DXE_SATA_

#include "CND003Reg.h"

#include "IoeDxeInit.h"

EFI_STATUS EFIAPI  IOESataDxeInit(
	ASIA_SB_CONFIGURATION* SbCfg 
  );

EFI_STATUS EFIAPI  IOESataDxePreBootInit(
	ASIA_SB_CONFIGURATION* SbCfg 
  );

#endif
