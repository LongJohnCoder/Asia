//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "EfiCommon.h"
#include "AsiaIoLib.h"
#include "CpuIa32.h"

#define PCI_ADDRESS_PORT 0x0CF8
#define PCI_DATA_PORT 0x0CFC

// Auxiliary Founctions
STATIC EFI_STATUS AsiaGetAddressStride(
  IN ASIA_IO_WIDTH Width, OUT UINT32* pAddressStride, OUT UINT32* pBufferStride);
STATIC UINT32 AsiaGetCf8Value(IN UINT64 PciAddress);
STATIC UINT64 AsiaGetPcieMmioAddress(UINT64 BaseAddress, UINT64 PciAddress);

// I/O read & write are implemented in AsiaIoLibIa32.c
EFI_STATUS
AsiaIoRead(ASIA_IO_WIDTH Width, UINT16 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;

  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    switch(Width)
    {
      case AsiaIoWidthUint8:
        *((UINT8*)pBuffer) = AsiaIoRead8(Address);
        break;
      case AsiaIoWidthUint16:
        *((UINT16*)pBuffer) = AsiaIoRead16(Address);
        break;
      case AsiaIoWidthUint32:
        *((UINT32*)pBuffer) = AsiaIoRead32(Address);
        break;
      case AsiaIoWidthUint64:
        return EFI_UNSUPPORTED;
    }
    Address = (UINT16)(Address + AddressStride);
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}

EFI_STATUS
AsiaIoWrite(ASIA_IO_WIDTH Width, UINT16 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;

  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    switch(Width)
    {
      case AsiaIoWidthUint8:
        AsiaIoWrite8(Address, *(UINT8*)pBuffer);
        break;
      case AsiaIoWidthUint16:
        AsiaIoWrite16(Address, *(UINT16*)pBuffer);
        break;
      case AsiaIoWidthUint32:
        AsiaIoWrite32(Address, *(UINT32*)pBuffer);
        break;
      case AsiaIoWidthUint64:
        return EFI_UNSUPPORTED;
    }
    Address = (UINT16)(Address + AddressStride);
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// I/O modify
VOID AsiaIoModify8(UINT16 Address, UINT8 Mask, UINT8 Value)
{
  UINT8 D8 = AsiaIoRead8(Address);
  D8 = (D8 & (~Mask) | Value);
  AsiaIoWrite8(Address, D8);
}
VOID AsiaIoModify16(UINT16 Address, UINT16 Mask, UINT16 Value)
{
  UINT16 D16 = AsiaIoRead16(Address);
  D16 = (D16 & (~Mask) | Value);
  AsiaIoWrite16(Address, D16);
}
VOID AsiaIoModify32(UINT16 Address, UINT32 Mask, UINT32 Value)
{
  UINT32 D32 = AsiaIoRead32(Address);
  D32 = (D32 & (~Mask) | Value);
  AsiaIoWrite32(Address, D32);
}
EFI_STATUS
AsiaIoModify(ASIA_IO_WIDTH Width, UINT16 Address, VOID* pMask, VOID* pValue)
{
  switch(Width)
  {
    case AsiaIoWidthUint8:
      AsiaIoModify8(Address, *(UINT8*)pMask, *(UINT8*)pValue);
      break;
    case AsiaIoWidthUint16:
      AsiaIoModify16(Address, *(UINT16*)pMask, *(UINT16*)pValue);
      break;
    case AsiaIoWidthUint32:
      AsiaIoModify32(Address, *(UINT32*)pMask, *(UINT32*)pValue);
      break;
    default:
      return EFI_INVALID_PARAMETER;
  }
  return EFI_SUCCESS;
}
/* Memory space access
64bit address, 64bit data access supported.
Memory space access is implemented using flat mode pointers. */
// Memory read
UINT8 AsiaMemoryRead8(UINT64 Address)
{ return *((volatile UINT8*)(UINTN)Address); }
UINT16 AsiaMemoryRead16(UINT64 Address)
{ return *((volatile UINT16*)(UINTN)Address); }
UINT32 AsiaMemoryRead32(UINT64 Address)
{ return *((volatile UINT32*)(UINTN)Address); }
UINT64 AsiaMemoryRead64(UINT64 Address)
{ return *((volatile UINT64*)(UINTN)Address); }

EFI_STATUS
AsiaMemoryRead(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;

  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    switch(Width)
    {
      case AsiaIoWidthUint8:
        *((UINT8*)pBuffer) = AsiaMemoryRead8(Address);
        break;
      case AsiaIoWidthUint16:
        *((UINT16*)pBuffer) = AsiaMemoryRead16(Address);
        break;
      case AsiaIoWidthUint32:
        *((UINT32*)pBuffer) = AsiaMemoryRead32(Address);
        break;
      case AsiaIoWidthUint64:
        *((UINT64*)pBuffer) = AsiaMemoryRead64(Address);
        break;
    }
    Address += AddressStride;
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// Memory write
VOID AsiaMemoryWrite8(UINT64 Address, UINT8 Data)
{ *((volatile UINT8*)(UINTN)Address) = Data; }
VOID AsiaMemoryWrite16(UINT64 Address, UINT16 Data)
{ *((volatile UINT16*)(UINTN)Address) = Data; }
VOID AsiaMemoryWrite32(UINT64 Address, UINT32 Data)
{ *((volatile UINT32*)(UINTN)Address) = Data; }
VOID AsiaMemoryWrite64(UINT64 Address, UINT64 Data)
{ *((volatile UINT64*)(UINTN)Address) = Data; }

EFI_STATUS
AsiaMemoryWrite(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;

  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    switch(Width)
    {
      case AsiaIoWidthUint8:
        AsiaMemoryWrite8(Address, *(UINT8*)pBuffer);
        break;
      case AsiaIoWidthUint16:
        AsiaMemoryWrite16(Address, *(UINT16*)pBuffer);
        break;
      case AsiaIoWidthUint32:
        AsiaMemoryWrite32(Address, *(UINT32*)pBuffer);
        break;
      case AsiaIoWidthUint64:
        AsiaMemoryWrite64(Address, *(UINT64*)pBuffer);
        break;
    }
    Address += AddressStride;
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// Memory modify
VOID AsiaMemoryModify8(UINT64 Address, UINT8 Mask, UINT8 Value)
{
  UINT8 D8 = AsiaMemoryRead8(Address);
  D8 = (D8 & (~Mask) | Value);
  AsiaMemoryWrite8(Address, D8);
}
VOID AsiaMemoryModify16(UINT64 Address, UINT16 Mask, UINT16 Value)
{
  UINT16 D16 = AsiaMemoryRead16(Address);
  D16 = (D16 & (~Mask) | Value);
  AsiaMemoryWrite16(Address, D16);
}
VOID AsiaMemoryModify32(UINT64 Address, UINT32 Mask, UINT32 Value)
{
  UINT32 D32 = AsiaMemoryRead32(Address);
  D32 = (D32 & (~Mask) | Value);
  AsiaMemoryWrite32(Address, D32);
}
VOID AsiaMemoryModify64(UINT64 Address, UINT64 Mask, UINT64 Value)
{
  UINT64 D64 = AsiaMemoryRead64(Address);
  D64 = (D64 & (~Mask) | Value);
  AsiaMemoryWrite64(Address, D64);
}

EFI_STATUS
AsiaMemoryModify(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue)
{
  switch(Width)
  {
    case AsiaIoWidthUint8:
      AsiaMemoryModify8(Address, *(UINT8*)pMask, *(UINT8*)pValue);
      break;
    case AsiaIoWidthUint16:
      AsiaMemoryModify16(Address, *(UINT16*)pMask, *(UINT16*)pValue);
      break;
    case AsiaIoWidthUint32:
      AsiaMemoryModify32(Address, *(UINT32*)pMask, *(UINT32*)pValue);
      break;
    case AsiaIoWidthUint64:
      AsiaMemoryModify64(Address, *(UINT64*)pMask, *(UINT64*)pValue);
      break;
    default:
      return EFI_INVALID_PARAMETER;
  }
  return EFI_SUCCESS;
}
// Pci read
UINT8 AsiaPciRead8(UINT64 Address)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  UINT8 D8;
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  D8 = AsiaIoRead8(PCI_DATA_PORT + Stride);
  //EfiEnableInterrupts();
  return D8;
}
UINT16 AsiaPciRead16(UINT64 Address)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  UINT16 D16;
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  D16 = AsiaIoRead16(PCI_DATA_PORT + Stride);
  //EfiEnableInterrupts();
  return D16;
}
UINT32 AsiaPciRead32(UINT64 Address)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  UINT32 D32;
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  D32 = AsiaIoRead32(PCI_DATA_PORT + Stride);
  //EfiEnableInterrupts();
  return D32;
}
EFI_STATUS
AsiaPciRead(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;
  UINT32 Cf8Address = AsiaGetCf8Value(Address);
  UINT32 Cf8Val;
  UINT8 Stride;
  
  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    Cf8Val = (Cf8Address & 0xFFFFFFFC);
    Stride = (UINT8)(Cf8Address & 0x03);
    switch(Width)
    {
      case AsiaIoWidthUint8:
        //EfiDisableInterrupts();
        AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
        *((UINT8*)pBuffer) = AsiaIoRead8(PCI_DATA_PORT + Stride);
        //EfiEnableInterrupts();
        break;
      case AsiaIoWidthUint16:
        //EfiDisableInterrupts();
        AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
        *((UINT16*)pBuffer) = AsiaIoRead16(PCI_DATA_PORT + Stride);
        //EfiEnableInterrupts();
        break;
      case AsiaIoWidthUint32:
        //EfiDisableInterrupts();
        AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
        *((UINT32*)pBuffer) = AsiaIoRead32(PCI_DATA_PORT + Stride);
        //EfiEnableInterrupts();
        break;
      case AsiaIoWidthUint64:
        return EFI_UNSUPPORTED;
    }
    Cf8Address += AddressStride;
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// Pci write
VOID AsiaPciWrite8(UINT64 Address, UINT8 Data)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  AsiaIoWrite8(PCI_DATA_PORT + Stride, Data);
  //EfiEnableInterrupts();
}
VOID AsiaPciWrite16(UINT64 Address, UINT16 Data)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  AsiaIoWrite16(PCI_DATA_PORT + Stride, Data);
  //EfiEnableInterrupts();
}
VOID AsiaPciWrite32(UINT64 Address, UINT32 Data)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  AsiaIoWrite32(PCI_DATA_PORT + Stride, Data);
  //EfiEnableInterrupts();
}
EFI_STATUS
AsiaPciWrite(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;
  UINT32 Cf8Address = AsiaGetCf8Value(Address);
  UINT32 Cf8Val;
  UINT8 Stride;

  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    Cf8Val = (Cf8Address & 0xFFFFFFFC);
    Stride = (UINT8)(Cf8Address & 0x03);
    switch(Width)
    {
      case AsiaIoWidthUint8:
        //EfiDisableInterrupts();
        AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
        AsiaIoWrite8(PCI_DATA_PORT + Stride, *(UINT8*)pBuffer);
        //EfiEnableInterrupts();
        break;
      case AsiaIoWidthUint16:
        //EfiDisableInterrupts();
        AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
        AsiaIoWrite16(PCI_DATA_PORT + Stride, *(UINT16*)pBuffer);
        //EfiEnableInterrupts();
        break;
      case AsiaIoWidthUint32:
        //EfiDisableInterrupts();
        AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
        AsiaIoWrite32(PCI_DATA_PORT + Stride, *(UINT32*)pBuffer);
        //EfiEnableInterrupts();
        break;
      case AsiaIoWidthUint64:
        return EFI_UNSUPPORTED;
    }
    
    Cf8Address += AddressStride;
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// Pci modify
VOID AsiaPciModify8(UINT64 Address, UINT8 Mask, UINT8 Value)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  AsiaIoModify8(PCI_DATA_PORT + Stride, Mask, Value);
  //EfiEnableInterrupts();
}
VOID AsiaPciModify16(UINT64 Address, UINT16 Mask, UINT16 Value)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  AsiaIoModify16(PCI_DATA_PORT + Stride, Mask, Value);
  //EfiEnableInterrupts();
}
VOID AsiaPciModify32(UINT64 Address, UINT32 Mask, UINT32 Value)
{
  UINT32 Cf8Val = AsiaGetCf8Value(Address);
  UINT8 Stride = (UINT8)(Cf8Val & 0x03);
  Cf8Val &= 0xFFFFFFFC;
  //EfiDisableInterrupts();
  AsiaIoWrite32(PCI_ADDRESS_PORT, Cf8Val);
  AsiaIoModify32(PCI_DATA_PORT + Stride, Mask, Value);
  //EfiEnableInterrupts();
}
EFI_STATUS
AsiaPciModify(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue)
{
  switch(Width)
  {
    case AsiaIoWidthUint8:
      AsiaPciModify8(Address, *(UINT8*)pMask, *(UINT8*)pValue);
      break;
    case AsiaIoWidthUint16:
      AsiaPciModify16(Address, *(UINT16*)pMask, *(UINT16*)pValue);
      break;
    case AsiaIoWidthUint32:
      AsiaPciModify32(Address, *(UINT32*)pMask, *(UINT32*)pValue);
      break;
    default:
      return EFI_INVALID_PARAMETER;
  }
  return EFI_SUCCESS;
}
// Pcie read
UINT8 AsiaPcieRead8(UINT64 Bar, UINT64 Address)
{ return AsiaMemoryRead8(AsiaGetPcieMmioAddress(Bar, Address)); }
UINT16 AsiaPcieRead16(UINT64 Bar, UINT64 Address)
{ return AsiaMemoryRead16(AsiaGetPcieMmioAddress(Bar, Address)); }
UINT32 AsiaPcieRead32(UINT64 Bar, UINT64 Address)
{ return AsiaMemoryRead32(AsiaGetPcieMmioAddress(Bar, Address)); }
UINT64 AsiaPcieRead64(UINT64 Bar, UINT64 Address)
{ return AsiaMemoryRead64(AsiaGetPcieMmioAddress(Bar, Address)); }
EFI_STATUS
AsiaPcieRead(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;
  UINT64 PcieMmioAddress = AsiaGetPcieMmioAddress(Bar, Address);
  
  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    switch(Width)
    {
      case AsiaIoWidthUint8:
        *((UINT8*)pBuffer) = AsiaMemoryRead8(PcieMmioAddress);
        break;
      case AsiaIoWidthUint16:
        *((UINT16*)pBuffer) = AsiaMemoryRead16(PcieMmioAddress);
        break;
      case AsiaIoWidthUint32:
        *((UINT32*)pBuffer) = AsiaMemoryRead32(PcieMmioAddress);
        break;
      case AsiaIoWidthUint64:
        *((UINT64*)pBuffer) = AsiaMemoryRead64(PcieMmioAddress);
        break;
    }
    PcieMmioAddress += AddressStride;
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// Pcie write
VOID AsiaPcieWrite8(UINT64 Bar, UINT64 Address, UINT8 Data)
{ AsiaMemoryWrite8(AsiaGetPcieMmioAddress(Bar, Address), Data); }
VOID AsiaPcieWrite16(UINT64 Bar, UINT64 Address, UINT16 Data)
{ AsiaMemoryWrite16(AsiaGetPcieMmioAddress(Bar, Address), Data); }
VOID AsiaPcieWrite32(UINT64 Bar, UINT64 Address, UINT32 Data)
{ AsiaMemoryWrite32(AsiaGetPcieMmioAddress(Bar, Address), Data); }
VOID AsiaPcieWrite64(UINT64 Bar, UINT64 Address, UINT64 Data)
{ AsiaMemoryWrite64(AsiaGetPcieMmioAddress(Bar, Address), Data); }
EFI_STATUS
AsiaPcieWrite(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
  EFI_STATUS Status;
  UINT32 AddressStride, BufferStride;
  UINT64 PcieMmioAddress = AsiaGetPcieMmioAddress(Bar, Address);

  Status = AsiaGetAddressStride(Width, &AddressStride, &BufferStride);
  if(Status != EFI_SUCCESS)
    return Status;

  Width = (Width & 0x03);
  while(Count)
  {
    switch(Width)
    {
      case AsiaIoWidthUint8:
        AsiaMemoryWrite8(PcieMmioAddress, *(UINT8*)pBuffer);
        break;
      case AsiaIoWidthUint16:
        AsiaMemoryWrite16(PcieMmioAddress, *(UINT16*)pBuffer);
        break;
      case AsiaIoWidthUint32:
        AsiaMemoryWrite32(PcieMmioAddress, *(UINT32*)pBuffer);
        break;
      case AsiaIoWidthUint64:
        AsiaMemoryWrite64(PcieMmioAddress, *(UINT64*)pBuffer);
        break;
    }
    PcieMmioAddress += AddressStride;
    pBuffer = (UINT8*)pBuffer + BufferStride;
    Count--;
  }
  return Status;
}
// Pcie modify
VOID AsiaPcieModify8(UINT64 Bar, UINT64 Address, UINT8 Mask, UINT8 Value)
{ AsiaMemoryModify8(AsiaGetPcieMmioAddress(Bar, Address), Mask, Value); }
VOID AsiaPcieModify16(UINT64 Bar, UINT64 Address, UINT16 Mask, UINT16 Value)
{ AsiaMemoryModify16(AsiaGetPcieMmioAddress(Bar, Address), Mask, Value); }
VOID AsiaPcieModify32(UINT64 Bar, UINT64 Address, UINT32 Mask, UINT32 Value)
{ AsiaMemoryModify32(AsiaGetPcieMmioAddress(Bar, Address), Mask, Value); }
VOID AsiaPcieModify64(UINT64 Bar, UINT64 Address, UINT64 Mask, UINT64 Value)
{ AsiaMemoryModify64(AsiaGetPcieMmioAddress(Bar, Address), Mask, Value); }
EFI_STATUS
AsiaPcieModify(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue)
{
  switch(Width)
  {
    case AsiaIoWidthUint8:
      AsiaPcieModify8(Bar, Address, *(UINT8*)pMask, *(UINT8*)pValue);
      break;
    case AsiaIoWidthUint16:
      AsiaPcieModify16(Bar, Address, *(UINT16*)pMask, *(UINT16*)pValue);
      break;
    case AsiaIoWidthUint32:
      AsiaPcieModify32(Bar, Address, *(UINT32*)pMask, *(UINT32*)pValue);
      break;
    case AsiaIoWidthUint64:
      AsiaPcieModify64(Bar, Address, *(UINT64*)pMask, *(UINT64*)pValue);
      break;
    default:
      return EFI_INVALID_PARAMETER;
  }
  return EFI_SUCCESS;
}

//ASIA R0.91deleted this interface
// IndexedIo read/write/modify
//UINT8 AsiaIndexedIoRead(UINT16 IndexPort, UINT16 DataPort, UINT8 Address)
//{
  //UINT8 D8;
  //EfiDisableInterrupts();
  //AsiaIoWrite8(IndexPort, Address);
  //D8 = AsiaIoRead8(DataPort);
  //EfiEnableInterrupts();
  //return D8;
//}

//VOID AsiaIndexedIoWrite(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Data)
//{
  //EfiDisableInterrupts();
  //AsiaIoWrite8(IndexPort, Address);
  //AsiaIoWrite8(DataPort, Data);
  //EfiEnableInterrupts();
//}
//VOID AsiaIndexedIoModify(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Mask, UINT8 Value)
//{
  //EfiDisableInterrupts();
  //AsiaIoWrite8(IndexPort, Address);
  //AsiaIoModify8(DataPort, Mask, Value);
  //EfiEnableInterrupts();
//}
//// Auxiliary Founctions //////////////////////////////////////////////////////

STATIC EFI_STATUS
AsiaGetAddressStride(
  IN ASIA_IO_WIDTH Width,
  OUT UINT32* pAddressStride,
  OUT UINT32* pBufferStride
  )
{
  UINT32 Stride = (1 << (Width & 0x03));
  if(Width <= AsiaIoWidthUint64)
  {
    *pAddressStride = Stride;
    *pBufferStride = Stride;
  }
  else if(Width <= AsiaIoWidthFifoUint64)
  {
    *pAddressStride = 0;
    *pBufferStride = Stride;
  }
  else if(Width <= AsiaIoWidthFillUint64)
  {
    *pAddressStride = Stride;
    *pBufferStride = 0;
  }
  else
  {
    return EFI_INVALID_PARAMETER;
  }
  return EFI_SUCCESS;
}

#pragma pack(1)
typedef struct {
  UINT8 Register;
  UINT8 Function;
  UINT8 Device;
  UINT8 Bus;
  UINT32 ExtendedRegister;
} EFI_PCI_ADDRESS;
#pragma pack()

UINT64 AsiaPciAddress(UINT8 Bus, UINT8 Dev, UINT8 Fun, UINT16 Reg)
{
  EFI_PCI_ADDRESS PciAddr;
  UINT64* pResult;
  PciAddr.Bus = Bus;
  PciAddr.Device = Dev;
  PciAddr.Function = Fun;
  if(Reg > 0xFF)
  {
    PciAddr.ExtendedRegister = Reg;
    PciAddr.Register = 0;
  }
  else
  {
    PciAddr.Register = (UINT8)Reg;
    PciAddr.ExtendedRegister = 0;
  }
  pResult = (UINT64*)(&(PciAddr));
  return *pResult;
}

STATIC UINT32
AsiaGetCf8Value(IN UINT64 PciAddress)
{
  EFI_PCI_ADDRESS* pEfiAddress = (EFI_PCI_ADDRESS*)(&PciAddress);
  UINT8 Register;
  if(pEfiAddress->ExtendedRegister != 0)
    Register = (UINT8)(pEfiAddress->ExtendedRegister); // Just cut to byte
  else
    Register = pEfiAddress->Register;
  return (0x80000000 | (pEfiAddress->Bus << 16) | (pEfiAddress->Device << 11) |
    (pEfiAddress->Function << 8) | Register);
}

STATIC UINT64
AsiaGetPcieMmioAddress(UINT64 BaseAddress, UINT64 PciAddress)
{
  EFI_PCI_ADDRESS* pEfiAddress = (EFI_PCI_ADDRESS*)(&PciAddress);
  UINT32 Register;
  if(pEfiAddress->ExtendedRegister != 0)
    Register = (pEfiAddress->ExtendedRegister & 0x0FFF); // Just cut within 4k
  else
    Register = pEfiAddress->Register;
  return (BaseAddress | (pEfiAddress->Bus << 20) | (pEfiAddress->Device << 15) |
    (pEfiAddress->Function << 12) | Register);
}