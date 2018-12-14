//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef ASIA_IO_SAVE_LIB_H
#define ASIA_IO_SAVE_LIB_H

#include "EfiCommon.h"
#include EFI_PROTOCOL_DEFINITION(BootScriptSave)
#include "AsiaIoLib.h"

extern EFI_BOOT_SCRIPT_SAVE_PROTOCOL* gBootScriptSave;

// I/O write
VOID AsiaIoWriteSave8(UINT16 Address, UINT8 Data);
VOID AsiaIoWriteSave16(UINT16 Address, UINT16 Data);
VOID AsiaIoWriteSave32(UINT16 Address, UINT32 Data);
EFI_STATUS
AsiaIoWriteSave(ASIA_IO_WIDTH Width, UINT16 Address, UINTN Count, VOID* pBuffer);
// I/O modify
VOID AsiaIoModifySave8(UINT16 Address, UINT8 Mask, UINT8 Value);
VOID AsiaIoModifySave16(UINT16 Address, UINT16 Mask, UINT16 Value);
VOID AsiaIoModifySave32(UINT16 Address, UINT32 Mask, UINT32 Value);
EFI_STATUS
AsiaIoModifySave(ASIA_IO_WIDTH Width, UINT16 Address, VOID* pMask, VOID* pValue);
// Memory write
VOID AsiaMemoryWriteSave8(UINT64 Address, UINT8 Data);
VOID AsiaMemoryWriteSave16(UINT64 Address, UINT16 Data);
VOID AsiaMemoryWriteSave32(UINT64 Address, UINT32 Data);
VOID AsiaMemoryWriteSave64(UINT64 Address, UINT64 Data);
EFI_STATUS
AsiaMemoryWriteSave(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Memory modify
VOID AsiaMemoryModifySave8(UINT64 Address, UINT8 Mask, UINT8 Value);
VOID AsiaMemoryModifySave16(UINT64 Address, UINT16 Mask, UINT16 Value);
VOID AsiaMemoryModifySave32(UINT64 Address, UINT32 Mask, UINT32 Value);
VOID AsiaMemoryModifySave64(UINT64 Address, UINT64 Mask, UINT64 Value);
EFI_STATUS
AsiaMemoryModifySave(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue);
// Pci write
VOID AsiaPciWriteSave8(UINT64 Address, UINT8 Data);
VOID AsiaPciWriteSave16(UINT64 Address, UINT16 Data);
VOID AsiaPciWriteSave32(UINT64 Address, UINT32 Data);
EFI_STATUS
AsiaPciWriteSave(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Pci modify
VOID AsiaPciModifySave8(UINT64 Address, UINT8 Mask, UINT8 Value);
VOID AsiaPciModifySave16(UINT64 Address, UINT16 Mask, UINT16 Value);
VOID AsiaPciModifySave32(UINT64 Address, UINT32 Mask, UINT32 Value);
EFI_STATUS
AsiaPciModifySave(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue);
// Pcie write
VOID AsiaPcieWriteSave8(UINT64 Bar, UINT64 Address, UINT8 Data);
VOID AsiaPcieWriteSave16(UINT64 Bar, UINT64 Address, UINT16 Data);
VOID AsiaPcieWriteSave32(UINT64 Bar, UINT64 Address, UINT32 Data);
VOID AsiaPcieWriteSave64(UINT64 Bar, UINT64 Address, UINT64 Data);
EFI_STATUS
AsiaPcieWriteSave(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Pcie modify
VOID AsiaPcieModifySave8(UINT64 Bar, UINT64 Address, UINT8 Mask, UINT8 Value);
VOID AsiaPcieModifySave16(UINT64 Bar, UINT64 Address, UINT16 Mask, UINT16 Value);
VOID AsiaPcieModifySave32(UINT64 Bar, UINT64 Address, UINT32 Mask, UINT32 Value);
VOID AsiaPcieModifySave64(UINT64 Bar, UINT64 Address, UINT64 Mask, UINT64 Value);
EFI_STATUS
AsiaPcieModifySave(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue);
/* IndexedIo space access */
//VOID AsiaIndexedIoWriteSave(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Data);
//VOID AsiaIndexedIoModifySave(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Mask, UINT8 Value);

//Asia Stall
//VOID AsiaStallSave(UINTN MicroSecs);

#endif