//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _TPR_ECHO_H
#define _TPR_ECHO_H

#include "Tiano.h"
#include "CpuIa32.h"

#define ACPU_TPR_ECHO_FLAG			0x4000
#define ACPU_TPR_ECHO_DISABLE		0x800000

BOOLEAN IsTPREchoSupport();
EFI_STATUS TPREchoInitialize(BOOLEAN TPREcho);
#endif

