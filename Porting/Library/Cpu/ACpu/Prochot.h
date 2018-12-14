//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _PROCHOT_H
#define _PROCHOT_H

#include "Tiano.h"
#include "CpuIa32.h"

#define ACPU_PROCHOT_ENABLE  0x20000

EFI_STATUS ProchotInitialize(BOOLEAN Prochot);
#endif
