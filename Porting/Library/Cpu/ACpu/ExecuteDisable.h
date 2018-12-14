//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _EXECUTE_DISABLE_H
#define _EXECUTE_DISABLE_H

#include "Tiano.h"
#include "CpuIa32.h"

#define  ACPU_EXECUTE_DISABLE_FLAG  0x100000
#define  ACPU_EXECUTE_DISABLE_ENABLE  0x0400000000

BOOLEAN IsExecuteDisableSupport();
EFI_STATUS ExecuteDisableInitialize(BOOLEAN ExecuteDisable);
#endif
