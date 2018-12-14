//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _PMON_H
#define _PMON_H

#include "Tiano.h"
#include "CpuIa32.h"
#include "Ppi\AsiaCpuPpi\AsiaCpuPpi.h"

#define PMON_SUPPORT_BIT  (0x10000000000)

BOOLEAN   IsPmonSupport(VOID);

EFI_STATUS PmonInitialize(BOOLEAN PmonEnable, UINT8 VrmSupport);

#endif