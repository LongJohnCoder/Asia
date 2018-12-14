//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _FERR_IS_PBE_H
#define _FERR_IS_PBE_H
#include "Tiano.h"
#include "CpuIa32.h"

#define ACPU_FERR_FLAG		0x80000000
#define ACPU_FERR_ENABLE	0x400

BOOLEAN IsFerrSupport();
EFI_STATUS FerrInitialize(BOOLEAN FerrInterruptReporting);
#endif

