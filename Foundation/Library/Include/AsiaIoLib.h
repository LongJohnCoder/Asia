//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef ASIA_IO_LIB_H
#define ASIA_IO_LIB_H

#include "EfiCommon.h"
/* ASIA_IO_WIDTH
Almost all I/O access interfaces in EFI provide their "width" definition, e.g.
CpuIoPpi -> CpuIoPpiWidth
PciCfgPpi -> PciCfgPpiWidth
CpuIoProtocol -> CpuIoProtocolWidth
PciRootBridgeIoProtocol -> PciRootBridgeProtocolWidth
PciIoProtocol -> PciIoProtocolWidth
The definitions are defining the same values, we should use none of them but
define a ASIA version. */
typedef enum {
  AsiaIoWidthUint8 = 0,
  AsiaIoWidthUint16,
  AsiaIoWidthUint32,
  AsiaIoWidthUint64,
  AsiaIoWidthFifoUint8,
  AsiaIoWidthFifoUint16,
  AsiaIoWidthFifoUint32,
  AsiaIoWidthFifoUint64,
  AsiaIoWidthFillUint8,
  AsiaIoWidthFillUint16,
  AsiaIoWidthFillUint32,
  AsiaIoWidthFillUint64,
  AsiaIoWidthMaximum
} ASIA_IO_WIDTH;

/* I/O space access
The I/O address space is the legacy of the Intel 8086 architecture. The space
uses 16bit address, so the capacity of the I/O space is only 64k bytes.
Many old fashioned devices map their registers onto the I/O space, mainly ISA
compatible devices, such as Timer, RTC, DMAC, INTC, and PS/2 keyboard & mouse
controllers. Many PCI devices also do that, such as VGA and Uhci controllers.
The I/O operations have to be implemented using assembly code. 64bit I/O access
is not supported. */
// I/O read
UINT8 AsiaIoRead8(UINT16 Address);
UINT16 AsiaIoRead16(UINT16 Address);
UINT32 AsiaIoRead32(UINT16 Address);
EFI_STATUS
AsiaIoRead(ASIA_IO_WIDTH Width, UINT16 Address, UINTN Count, VOID* pBuffer);
// I/O write
VOID AsiaIoWrite8(UINT16 Address, UINT8 Data);
VOID AsiaIoWrite16(UINT16 Address, UINT16 Data);
VOID AsiaIoWrite32(UINT16 Address, UINT32 Data);
EFI_STATUS
AsiaIoWrite(ASIA_IO_WIDTH Width, UINT16 Address, UINTN Count, VOID* pBuffer);
// I/O modify
VOID AsiaIoModify8(UINT16 Address, UINT8 Mask, UINT8 Value);
VOID AsiaIoModify16(UINT16 Address, UINT16 Mask, UINT16 Value);
VOID AsiaIoModify32(UINT16 Address, UINT32 Mask, UINT32 Value);
EFI_STATUS
AsiaIoModify(ASIA_IO_WIDTH Width, UINT16 Address, VOID* pMask, VOID* pValue);
/* Memory space access
64bit address, 64bit data access supported.
Memory space access is implemented using flat mode pointers. */
// Memory read
UINT8 AsiaMemoryRead8(UINT64 Address);
UINT16 AsiaMemoryRead16(UINT64 Address);
UINT32 AsiaMemoryRead32(UINT64 Address);
UINT64 AsiaMemoryRead64(UINT64 Address);
EFI_STATUS
AsiaMemoryRead(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Memory write
VOID AsiaMemoryWrite8(UINT64 Address, UINT8 Data);
VOID AsiaMemoryWrite16(UINT64 Address, UINT16 Data);
VOID AsiaMemoryWrite32(UINT64 Address, UINT32 Data);
VOID AsiaMemoryWrite64(UINT64 Address, UINT64 Data);
EFI_STATUS
AsiaMemoryWrite(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Memory modify
VOID AsiaMemoryModify8(UINT64 Address, UINT8 Mask, UINT8 Value);
VOID AsiaMemoryModify16(UINT64 Address, UINT16 Mask, UINT16 Value);
VOID AsiaMemoryModify32(UINT64 Address, UINT32 Mask, UINT32 Value);
VOID AsiaMemoryModify64(UINT64 Address, UINT64 Mask, UINT64 Value);
EFI_STATUS
AsiaMemoryModify(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue);
/* Conventional PCI configuration space access
64bit address, the address format is compatible with EFI standard.
Up to 32bit data access. Implemented thru CF8/CFC port access. */
UINT64 AsiaPciAddress(UINT8 Bus, UINT8 Dev, UINT8 Fun, UINT16 Reg);
// Pci read
UINT8 AsiaPciRead8(UINT64 Address);
UINT16 AsiaPciRead16(UINT64 Address);
UINT32 AsiaPciRead32(UINT64 Address);
EFI_STATUS
AsiaPciRead(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Pci write
VOID AsiaPciWrite8(UINT64 Address, UINT8 Data);
VOID AsiaPciWrite16(UINT64 Address, UINT16 Data);
VOID AsiaPciWrite32(UINT64 Address, UINT32 Data);
EFI_STATUS
AsiaPciWrite(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Pci modify
VOID AsiaPciModify8(UINT64 Address, UINT8 Mask, UINT8 Value);
VOID AsiaPciModify16(UINT64 Address, UINT16 Mask, UINT16 Value);
VOID AsiaPciModify32(UINT64 Address, UINT32 Mask, UINT32 Value);
EFI_STATUS
AsiaPciModify(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue);
/* PCI-Express configuration space access
64bit address, the address format is compatible with EFI standard.
Up to 64bit data access. Implemented thru MMIO space access. */
// Pcie read
UINT8 AsiaPcieRead8(UINT64 Bar, UINT64 Address);
UINT16 AsiaPcieRead16(UINT64 Bar, UINT64 Address);
UINT32 AsiaPcieRead32(UINT64 Bar, UINT64 Address);
UINT64 AsiaPcieRead64(UINT64 Bar, UINT64 Address);
EFI_STATUS
AsiaPcieRead(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Pcie write
VOID AsiaPcieWrite8(UINT64 Bar, UINT64 Address, UINT8 Data);
VOID AsiaPcieWrite16(UINT64 Bar, UINT64 Address, UINT16 Data);
VOID AsiaPcieWrite32(UINT64 Bar, UINT64 Address, UINT32 Data);
VOID AsiaPcieWrite64(UINT64 Bar, UINT64 Address, UINT64 Data);
EFI_STATUS
AsiaPcieWrite(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer);
// Pcie modify
VOID AsiaPcieModify8(UINT64 Bar, UINT64 Address, UINT8 Mask, UINT8 Value);
VOID AsiaPcieModify16(UINT64 Bar, UINT64 Address, UINT16 Mask, UINT16 Value);
VOID AsiaPcieModify32(UINT64 Bar, UINT64 Address, UINT32 Mask, UINT32 Value);
VOID AsiaPcieModify64(UINT64 Bar, UINT64 Address, UINT64 Mask, UINT64 Value);
EFI_STATUS
AsiaPcieModify(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue);

//Asia R0.9 deleted this interface
/* IndexedIo space access
8bit address and 8bit data. */
//UINT8 AsiaIndexedIoRead(UINT16 IndexPort, UINT16 DataPort, UINT8 Address);
//VOID AsiaIndexedIoWrite(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Data);
//VOID AsiaIndexedIoModify(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Mask, UINT8 Value);

/* 
ASIA IO TABLE
*/

#pragma pack(1) // Necessary!

// Modify, with revision control

typedef struct {
  UINT8 RevisionMin;
  UINT8 RevisionMax;
  UINT32 Address;
  UINT8 Mask;
  UINT8 Value;
} ASIA_IO_TABLE_3208_REV;

typedef struct {
  UINT8 RevisionMin;
  UINT8 RevisionMax;
  UINT64 Address;
  UINT8 Mask;    
  UINT8 Value;   
} ASIA_IO_TABLE_6408_REV;


typedef struct {
  UINT8 RevisionMin;
  UINT8 RevisionMax;
  UINT64 Address;
  UINT16 Mask;
  UINT16 Value;
} ASIA_IO_TABLE_6416_REV;

typedef struct {
  UINT64 Address;
  UINT8  Data;
} ASIA_IO_TABLE_6408_WO;

typedef struct {
  UINT8 RevisionMin;
  UINT8 RevisionMax;
  UINT64 Address;
  UINT32 Mask;
  UINT32 Value;
} ASIA_IO_TABLE_6432_REV;

typedef struct {
	UINT16 VendorId;
	UINT16 DeviceId;
}ASIA_PCI_DEV_ID;

typedef struct {
      UINT8 RevisionMin;
      UINT8 RevisionMax;

      UINT64 idx_Address;
      UINT32 idx_Mask;
      UINT32 idx_Value;

      UINT64 data_Address;
      UINT8 data_Mask;
      UINT8 data_Value;
} ASIA_IO_TABLE_64326408_REV;

typedef struct {
	UINT8  Device;
	UINT8  Function;
	UINT16 VIDLockReg;
	UINT16 DIDLockReg;
	UINT8  VIDLockBit;
	UINT8  DIDLockBit;
} ASIA_VID_DID_RID_LOCK;
#pragma pack()

#endif
