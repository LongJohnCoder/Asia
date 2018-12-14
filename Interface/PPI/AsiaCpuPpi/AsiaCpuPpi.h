//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _ASIA_CPU_PPI_H_
#define _ASIA_CPU_PPI_H_

#include "AsiaCpuPpiProtocol.h"

// {2bc92c61-2094-463e-8F75-38AD7F8AE968}
#define EFI_ASIA_CPU_PPI_PROTOCOL_GUID \
{ \
0x2bc92c61, 0x2094, 0x463e, 0x8f, 0x75, 0x38, 0xad, 0x7f, 0x8a, 0xe9, 0x68 \
}

#define EFI_ASIA_CPU_PPI EFI_ASIA_CPU_PPI_PROTOCOL

extern EFI_GUID gAsiaCpuPpiGuid; 

#endif