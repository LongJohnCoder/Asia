//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _TSC_DEAD_LINE_H
#define _TSC_DEAD_LINE_H

#include "Tiano.h"
#include "CpuIa32.h"
#include "Ppi\AsiaCpuPpi\AsiaCpuPpi.h"

#define TSC_DEAD_LINE_SUPPORT_BIT  (0x100000000000000)

BOOLEAN   IsPmonSupport(VOID);

EFI_STATUS TSCDeadLineInitialize(BOOLEAN TscDeadLineModeEnable);

#endif
