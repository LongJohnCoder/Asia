//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _VT_H
#define _VT_H

#include "Tiano.h"
#include "CpuIa32.h"
#define S5RESET                      0x0E
#define EFI_MSR_IA32_FEATURE_CONTROL 0x3A

#define ACPU_VMX_FLAG		0x20
#define ACPU_VMX_ENABLE		0x04
#define ACPU_VMX_LOCK		0x01

BOOLEAN IsVtSupport();
EFI_STATUS VtInitialize(BOOLEAN VtEnable);
#endif
