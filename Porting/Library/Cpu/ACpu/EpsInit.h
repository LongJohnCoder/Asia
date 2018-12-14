//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _EPS_INIT_H
#define _EPS_INIT_H

#include "Tiano.h"
#include "CpuIa32.h"
#include "EfiCommonLib.h"

#define ACPU_EPS_FLAG		0x80
#define ACPU_EPS_ENABLE		0x10000
#define ACPU_EPS_LOCK		0x100000

BOOLEAN IsEpsSupport();
EFI_STATUS  EpsInitialize(BOOLEAN EpsEnable,
	                                     BOOLEAN MaxFrequence);

#endif
