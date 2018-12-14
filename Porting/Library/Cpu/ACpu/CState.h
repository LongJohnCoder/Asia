//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _C_STATE_H
#define _C_STATE_H

#include "Tiano.h"
#include "CpuIa32.h"
#include "Ppi\AsiaCpuPpi\AsiaCpuPpi.h"

#define SLEW_RATE 0x0A
#define CHIP_RECOVERY_TIME 35

#define MSR_PM_CFG_CTRL   0xE2
#define MSR_IO_BASE_ADDR  0xE3
#define MSR_IO_CAPT_ADDR  0xE4

EFI_STATUS CxeInitialize(BOOLEAN CxeEnable);

EFI_STATUS WorkAroundForC4State(ASIA_CPU_CONFIGURATION *Feature);

EFI_STATUS CStatesInitialize(ASIA_CPU_CONFIGURATION *Feature);
EFI_STATUS NAPSNAPInit(BOOLEAN NapSnapEnable);
#endif
