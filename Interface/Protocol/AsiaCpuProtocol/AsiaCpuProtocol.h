//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
/*
*/

#ifndef _ASIA_CPU_PROTOCOL_H_
#define _ASIA_CPU_PROTOCOL_H_

#include "..\..\Ppi\AsiaCpuPpi\AsiaCpuPpiProtocol.h"

// {1CC92C61-2094-460d-8F75-38AD7F8AE96F}
#define EFI_ASIA_CPU_PROTOCOL_GUID \
{ \
0x1cc92c62, 0x2001, 0x4601, 0x8f, 0x75, 0x38, 0xad, 0x7f, 0x8a, 0xe9, 0x6f \
}

#define EFI_ASIA_CPU_PROTOCOL EFI_ASIA_CPU_PPI_PROTOCOL

extern EFI_GUID  gAsiaCpuProtocolGuid;

#endif