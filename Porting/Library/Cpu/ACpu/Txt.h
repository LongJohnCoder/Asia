//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _TXT_H
#define _TXT_H

#include "Tiano.h"
#include "CpuIa32.h"

#ifdef ZX_TXT_SUPPORT

#define SYSTEM_RESET_S5              0x0E

#define ACPU_FEATURE_SMX             0x40
#define ACPU_CR4_SMX_ENABLE          0x4000

#define ACPU_MSR_IA32_FEATURE_CONTROL                       0x3A
#define ACPU_MSR_IA32_FEATURE_CONTROL_LOCK                  0x01
#define ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_VMX_IN_SMX     0x02
#define ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_SENTER         0x8000
#define ACPU_MSR_IA32_FEATURE_CONTROL_SENTER_PARAM_CTL      0x7F00

EFI_STATUS TxtInitialize(BOOLEAN TxtEnable);

UINTN EfiReadCr4(VOID);
UINTN EfiWriteCr4(UINTN Cr4);

#endif // ZX_TXT_SUPPORT
#endif