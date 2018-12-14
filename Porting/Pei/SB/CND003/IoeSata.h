/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoeSata.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef __IOE_SATA_H__
#define __IOE_SATA_H__

#include "CND003Reg.h"

#include "IoePreInit.h"

EFI_STATUS
EFIAPI
IOESataPeiInit(
	IN EFI_PEI_SERVICES      **PeiServices, 
    IN ASIA_SB_CONFIGURATION *SbCfg
);

EFI_STATUS
EFIAPI
IOESataPeiInitS3(
	IN EFI_PEI_SERVICES      **PeiServices, 
    IN ASIA_SB_CONFIGURATION *SbCfg
);

#endif
