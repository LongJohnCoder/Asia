//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _PREFETCHER_H
#define _PREFETCHER_H

#include "Tiano.h"
#include "CpuIa32.h"

#define ACPU_PREFETCH_QUEUE_DISABLE			0x200
#define ACPU_ADJACENT_CACHE_PREFETCH_ENABLE	0x80000
EFI_STATUS PrefetcherInitialize(BOOLEAN HwPrefetcher,
                                                       BOOLEAN AdjacentCacheLinePrefetch
                                              );
#endif
