//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _MONITOR_MWAIT_H
#define _MONITOR_MWAIT_H

#include "Tiano.h"
#include "CpuIa32.h"

#define ACPU_MONITOR_MWAIT_FLAG   0x8
#define ACPU_MONITOR_MWAIT_ENABLE 0x40000

BOOLEAN IsMonitorMWaitSupport();
EFI_STATUS MonitorMWaitInitialize(BOOLEAN Monitor);
#endif
