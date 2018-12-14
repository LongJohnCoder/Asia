/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoeDebugSignal.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/
//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef __IOE_DBG_SIGNAL__
#define __IOE_DBG_SIGNAL__

#include "CND003Reg.h"


#if IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_SB
EFI_STATUS
IoeDebugSignalSel(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_SB_CONFIGURATION *SbCfg);

#elif IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_NB

EFI_STATUS
IoeDebugSignalSel(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg);


EFI_STATUS
IoeDebugSignalSelPostCfgDone(	
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg);

#endif
UINTN IoeSmbusDebugPathEnable(IN EFI_PEI_SERVICES **PeiServices,UINT8 flag);

UINTN
IoeSmbusCfgDebugRead8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 bus,
	IN UINT8 dev,
	IN UINT8 fun,
	IN UINT16 regoffset,
	IN OUT UINT8* Gdata
);

UINTN
IoeSmbusCfgDebugWrite8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 bus,
	IN UINT8 dev,
	IN UINT8 fun,
	IN UINT16 regoffset,
	IN OUT UINT8 Gdata
);
UINTN
IoeSmbusCfgDebugModify8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 bus,
	IN UINT8 dev,
	IN UINT8 fun,
	IN UINT16 regoffset,
	IN UINT8 Mask,
	IN UINT8 Val);
UINTN
IoeSmbusDebugModify8(IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 address,//cfg address,or mem addr,or io addr
	IN UINT8 flag,//0 for cfg,1 for mem,2 for io
	IN UINT8 Mask,
	IN OUT UINT8 Gdata//for now,we support single byte write only
	);

EFI_STATUS
IoeDbgCapSetup(
	IN EFI_PEI_SERVICES **PeiServices, 
	ASIA_NB_CONFIGURATION *NbCfg);


EFI_STATUS
IoePatchDbgSignal(	
	IN EFI_PEI_SERVICES **PeiServices, 
	ASIA_NB_CONFIGURATION *NbCfg);




VOID
IoeSmbusDumpCfg(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig,
	UINT8 bus, 
	UINT8 dev, 
	UINT8 func,
	UINT16 Start,
	UINT16 Dcount);

#endif