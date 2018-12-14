//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "AsiaIoSaveLib.h"
#include "EfiBootScript.h"
#include "EfiScriptLib.h"

#pragma pack(1)
typedef struct {
  UINT8 Register;
  UINT8 Function;
  UINT8 Device;
  UINT8 Bus;
  UINT32 ExtendedRegister;
} EFI_PCI_ADDRESS;
#pragma pack()

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

// I/O write
VOID AsiaIoWriteSave8(UINT16 Address, UINT8 Data)
{
    AsiaIoWrite8(Address, Data);
    SCRIPT_IO_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,Address,1,&Data);
}

VOID AsiaIoWriteSave16(UINT16 Address, UINT16 Data)
{
    AsiaIoWrite16(Address, Data);
	SCRIPT_IO_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,Address,1,&Data);
}

VOID AsiaIoWriteSave32(UINT16 Address, UINT32 Data)
{
    AsiaIoWrite32(Address, Data);
	SCRIPT_IO_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,Address,1,&Data);
}

EFI_STATUS
AsiaIoWriteSave(ASIA_IO_WIDTH Width, UINT16 Address, UINTN Count, VOID* pBuffer)
{
    EFI_STATUS Status;
    Status = AsiaIoWrite(Width, Address, Count, pBuffer);
	if(EFI_SUCCESS == Status)
	{
		SCRIPT_IO_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,Address,Count,pBuffer);
	}
    return Status;
}

// I/O modify
VOID AsiaIoModifySave8(UINT16 Address, UINT8 Mask, UINT8 Value)
{
    AsiaIoModify8(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_IO_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,Address,&Value,&Mask);
}

VOID AsiaIoModifySave16(UINT16 Address, UINT16 Mask, UINT16 Value)
{
    AsiaIoModify16(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_IO_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,Address,&Value,&Mask);
}

VOID AsiaIoModifySave32(UINT16 Address, UINT32 Mask, UINT32 Value)
{
    AsiaIoModify32(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_IO_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,Address,&Value,&Mask);
}

EFI_STATUS
AsiaIoModifySave(ASIA_IO_WIDTH Width, UINT16 Address, VOID* pMask, VOID* pValue)
{
    EFI_STATUS Status;
    Status = AsiaIoModify(Width, Address, pMask, pValue);
	*(UINT8*)pMask =~(*(UINT8*)pMask);  //JW0827
	if(EFI_SUCCESS == Status)
	{
		SCRIPT_IO_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,Address,pValue,pMask);
	}
    return Status;
}

// Memory write
VOID AsiaMemoryWriteSave8(UINT64 Address, UINT8 Data)
{
    AsiaMemoryWrite8(Address, Data);
	SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,Address,1,&Data);
}

VOID AsiaMemoryWriteSave16(UINT64 Address, UINT16 Data)
{
    AsiaMemoryWrite16(Address, Data);
    SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,Address,1,&Data);
}

VOID AsiaMemoryWriteSave32(UINT64 Address, UINT32 Data)
{
    AsiaMemoryWrite32(Address, Data);
    SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,Address,1,&Data);
}

VOID AsiaMemoryWriteSave64(UINT64 Address, UINT64 Data)
{
    AsiaMemoryWrite64(Address, Data);
    SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint64,Address,1,&Data);
}

EFI_STATUS
AsiaMemoryWriteSave(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
    EFI_STATUS Status;
    Status = AsiaMemoryWrite(Width, Address, Count, pBuffer);
	if(EFI_SUCCESS == Status)
	{
		SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,Address,Count,pBuffer);
	}
    return Status;
}


// Memory modify
VOID AsiaMemoryModifySave8(UINT64 Address, UINT8 Mask, UINT8 Value)
{
    AsiaMemoryModify8(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,Address,&Value,&Mask);
}

VOID AsiaMemoryModifySave16(UINT64 Address, UINT16 Mask, UINT16 Value)
{
    AsiaMemoryModify16(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
    SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,Address,&Value,&Mask);
}

VOID AsiaMemoryModifySave32(UINT64 Address, UINT32 Mask, UINT32 Value)
{
    AsiaMemoryModify32(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
    SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,Address,&Value,&Mask);
}

VOID AsiaMemoryModifySave64(UINT64 Address, UINT64 Mask, UINT64 Value)
{
    AsiaMemoryModify64(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
    SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint64,Address,&Value,&Mask);
}

EFI_STATUS
AsiaMemoryModifySave(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue)
{
    EFI_STATUS Status;
    Status = AsiaMemoryModify(Width, Address, pMask, pValue);
	*(UINT8*)pMask =~(*(UINT8*)pMask);   //JW0827
	if(EFI_SUCCESS == Status)
	{
		SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,Address,pValue,pMask);
	}
    return Status;
}

// Pci write
VOID AsiaPciWriteSave8(UINT64 Address, UINT8 Data)
{
    AsiaPciWrite8(Address, Data);
	SCRIPT_PCI_CFG_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,Address,1,&Data);
}

VOID AsiaPciWriteSave16(UINT64 Address, UINT16 Data)
{
    AsiaPciWrite16(Address, Data);
	SCRIPT_PCI_CFG_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,Address,1,&Data);
}

VOID AsiaPciWriteSave32(UINT64 Address, UINT32 Data)
{
    AsiaPciWrite32(Address, Data);
    SCRIPT_PCI_CFG_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,Address,1,&Data);
}

EFI_STATUS
AsiaPciWriteSave(ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
    EFI_STATUS Status;
    Status = AsiaPciWrite(Width, Address, Count, pBuffer);
	if(EFI_SUCCESS == Status)
	{
		SCRIPT_PCI_CFG_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,Address,Count,pBuffer);
	}
    return Status;
}

// Pci modify
VOID AsiaPciModifySave8(UINT64 Address, UINT8 Mask, UINT8 Value)
{
    AsiaPciModify8(Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_PCI_CFG_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,Address,&Value,&Mask);
}

VOID AsiaPciModifySave16(UINT64 Address, UINT16 Mask, UINT16 Value)
{
    UINT64  AlignedAddress;
    UINT8    Offset;
    AsiaPciModify16(Address, Mask, Value);
    AlignedAddress = Address & 0xfffffffffffffffeULL;
    Offset = (UINT8)(Address & 0x1);
    Offset <<= 3;
    Value = Value << Offset;
    Mask = Mask << Offset;
    Mask = (~Mask);  //JW0827
    SCRIPT_PCI_CFG_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,AlignedAddress,&Value,&Mask);
}

VOID AsiaPciModifySave32(UINT64 Address, UINT32 Mask, UINT32 Value)
{
    UINT64  AlignedAddress;
    UINT8    Offset;
    AsiaPciModify32(Address, Mask, Value);
    AlignedAddress = Address & 0xfffffffffffffffcULL;
    Offset = (UINT8)(Address & 0x3);
    Offset <<= 3;
    Value = Value << Offset;
    Mask = Mask << Offset;
    Mask = (~Mask);  //JW0827
    SCRIPT_PCI_CFG_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,AlignedAddress,&Value,&Mask);
}

EFI_STATUS
AsiaPciModifySave(ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue)
{
    EFI_STATUS Status;
    Status = AsiaPciModify(Width, Address, pMask, pValue);
   *(UINT8*)pMask =~(*(UINT8*)pMask);  //JW0827	
    if(EFI_SUCCESS == Status)
	{
		SCRIPT_PCI_CFG_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,Address,pValue,pMask);
	}
    return Status;
}

// Pcie write
VOID AsiaPcieWriteSave8(UINT64 Bar, UINT64 Address, UINT8 Data)
{
    AsiaPcieWrite8(Bar, Address, Data);
	SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,AsiaGetPcieMmioAddress(Bar,Address),1,&Data);
}

VOID AsiaPcieWriteSave16(UINT64 Bar, UINT64 Address, UINT16 Data)
{
    AsiaPcieWrite16(Bar, Address, Data);
	SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,AsiaGetPcieMmioAddress(Bar,Address),1,&Data);
}

VOID AsiaPcieWriteSave32(UINT64 Bar, UINT64 Address, UINT32 Data)
{
    AsiaPcieWrite32(Bar, Address, Data);
	SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,AsiaGetPcieMmioAddress(Bar,Address),1,&Data);
}

VOID AsiaPcieWriteSave64(UINT64 Bar, UINT64 Address, UINT64 Data)
{
    AsiaPcieWrite64(Bar, Address, Data);
	SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint64,AsiaGetPcieMmioAddress(Bar,Address),1,&Data);
}

EFI_STATUS
AsiaPcieWriteSave(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, UINTN Count, VOID* pBuffer)
{
    EFI_STATUS Status;
    Status = AsiaPcieWrite(Bar, Width, Address, Count, pBuffer);
	if(EFI_SUCCESS)
	{
		SCRIPT_MEM_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,AsiaGetPcieMmioAddress(Bar,Address),Count,pBuffer);
	}
    return Status;
}

// Pcie modify
VOID AsiaPcieModifySave8(UINT64 Bar, UINT64 Address, UINT8 Mask, UINT8 Value)
{
    AsiaPcieModify8(Bar, Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint8,AsiaGetPcieMmioAddress(Bar,Address),&Value,&Mask);
}

VOID AsiaPcieModifySave16(UINT64 Bar, UINT64 Address, UINT16 Mask, UINT16 Value)
{
    AsiaPcieModify16(Bar, Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint16,AsiaGetPcieMmioAddress(Bar,Address),&Value,&Mask);
}

VOID AsiaPcieModifySave32(UINT64 Bar, UINT64 Address, UINT32 Mask, UINT32 Value)
{
    AsiaPcieModify32(Bar, Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint32,AsiaGetPcieMmioAddress(Bar,Address),&Value,&Mask);
}

VOID AsiaPcieModifySave64(UINT64 Bar, UINT64 Address, UINT64 Mask, UINT64 Value)
{
    AsiaPcieModify64(Bar, Address, Mask, Value);
	Mask = (~Mask);  //JW0827
	SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,EfiBootScriptWidthUint64,AsiaGetPcieMmioAddress(Bar,Address),&Value,&Mask);
}

EFI_STATUS
AsiaPcieModifySave(UINT64 Bar, ASIA_IO_WIDTH Width, UINT64 Address, VOID* pMask, VOID* pValue)
{
    EFI_STATUS Status;
    Status = AsiaPcieModify(Bar, Width, Address, pMask, pValue);
	*(UINT8*)pMask =~(*(UINT8*)pMask);   //JW0827
	if(EFI_SUCCESS == Status)
	{
		SCRIPT_MEM_READ_WRITE(EFI_ACPI_S3_RESUME_SCRIPT_TABLE,(EFI_BOOT_SCRIPT_WIDTH)Width,AsiaGetPcieMmioAddress(Bar,Address),pValue,pMask);
	}
    return Status;
}

//VOID
//AsiaStallSave(UINTN MicroSecs)
//{
    //SCRIPT_STALL(EFI_ACPI_S3_RESUME_SCRIPT_TABLE, MicroSecs);
//}
/* IndexedIo space access */
//VOID AsiaIndexedIoWriteSave(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Data)
//{
//    UINT8 A8 = (UINT8)Address;
//    AsiaIndexedIoWrite(IndexPort, DataPort, A8, Data);
//    if (gBootScriptSave != NULL)
//    {
//        gBootScriptSave->Write(
//            gBootScriptSave,
//            EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
//            EFI_BOOT_SCRIPT_IO_WRITE_OPCODE,
//            EfiBootScriptWidthUint8,
//            IndexPort,
//            1,
//            &A8
//        );
//        gBootScriptSave->Write(
//            gBootScriptSave,
//            EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
//            EFI_BOOT_SCRIPT_IO_WRITE_OPCODE,
//            EfiBootScriptWidthUint8,
//            DataPort,
//            1,
//            &Data
//        );
//    }
//}
//
//VOID AsiaIndexedIoModifySave(UINT16 IndexPort, UINT16 DataPort, UINT8 Address, UINT8 Mask, UINT8 Value)
//{
//    UINT8 A8 = (UINT8)Address;
//    AsiaIndexedIoModify(IndexPort, DataPort, A8, Mask, Value);
//    if (gBootScriptSave != NULL)
//    {
//        gBootScriptSave->Write(
//            gBootScriptSave,
//            EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
//            EFI_BOOT_SCRIPT_IO_WRITE_OPCODE,
//            EfiBootScriptWidthUint8,
//            IndexPort,
//            1,
//            &A8
//        );
//        gBootScriptSave->Write(
//            gBootScriptSave,
//            EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
//            EFI_BOOT_SCRIPT_IO_READ_WRITE_OPCODE,
//            EfiBootScriptWidthUint8,
//            DataPort,
//            &Value,
//            &Mask
//        );
//    }
//}
