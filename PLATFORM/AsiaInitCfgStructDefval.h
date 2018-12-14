//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef __ASIA_INIT_DEFVAL_PLATFORM_H__
#define __ASIA_INIT_DEFVAL_PLATFORM_H__

EFI_STATUS
AsiaPlatformPrePciInit(
    IN ASIA_SB_CONFIGURATION *SbCfg );

////
VOID InitNbCfgStructDefaultValue(
	IN ASIA_NB_CONFIGURATION* pNbCfg);

VOID InitSbCfgStructDefaultValue(
	IN ASIA_SB_CONFIGURATION* pSbCfg);

VOID InitDramCfgStructDefaultValue(
	IN ASIA_DRAM_CONFIGURATION* pDramCfg);

////
#endif
