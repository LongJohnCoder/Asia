//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _ZX_VIRTUAL_SPD_H_
#define _ZX_VIRTUAL_SPD_H_

#define V_SPD_SIZE  512
#define ASIA_MAX_SOCKETS	4

#pragma pack(1)
#define ASIA_VIRTUAL_SPD_SIGNATURE EFI_SIGNATURE_32('V','S','P','D')


//
// ZX virtual SPD header.
//
//
// DRAM parameters to distinguish different SPD.
//
typedef struct {
	UINT8  DramType;            //SPD BYTE 0x02(2) 
	UINT8  ModuleType;          //SPD BYTE 0x03(3)
	UINT8  ModuleOrganization;  //SPD BYTE 0x0C(12)
	UINT8  BusWidth;            //SPD BYTE 0X0D(13)
	UINT8  MinCycleTime;        //SPD BYTE 0X12(18)
 	// UINT8  MaxCycleTime;        //SPD BYTE 0X12(19)   
	UINT8  RefRawCardUsed;      //SPD BYTE 0X82(130)
	UINT8  ModuleID_L;          //SPD BYTE 0X140(320)
	UINT8  ModuleID_H;          //SPD BYTE 0X141(321)
} ZX_VIRTUAL_SPD_DRAM_PARAMETER;

//
// ZX virtual SPD block.
//
typedef struct {
	UINT32  SpdPresent;	
	// Real SPD data.
	UINT8 Buffer[V_SPD_SIZE];

} ZX_VIRTUAL_SPD_BLOCK;

typedef struct {
	UINT32  Signature;	
	//SPD_type 0=dual side 1=signal
	UINT8 SPD_Type;
	//Slot_Type bit3=dimmA6, bit2=dimmA4, bit1=dimmA2, bit0=dimmA0
	UINT8 Slot_type;
	// Real dual side SPD data.
	UINT8 Dual_Buffer[V_SPD_SIZE];
	// Real singal side SPD data.	
	UINT8 Signal_Buffer[V_SPD_SIZE];
} ZX_SPI_SPD_BLOCK;



typedef struct {
	// ZX virtual SPD header signature
	//    char format: 'V' 'S' 'P' 'D', hex value: 0x44505356
	UINT32  Signature;
	
	// The size in byte of this header.
	UINT32  HeaderSize;
	
	// The total size in byte of the total virtual SPD region.
	UINT32  TotalSize;
	
	// How many valid SPD blocks in this virtual SPD region.
	UINT32  NumberOfSpd;
	
	// CRC32 value of the SPD blocks.
	UINT32  SpdBlockCRC32;

    // //Block information
    ZX_VIRTUAL_SPD_BLOCK VirtualSPDBlock[ASIA_MAX_SOCKETS];

	// Just padding the space to make sure the header size is 32 bytes.
	UINT32  Reserved[3];
	
} ZX_VIRTUAL_SPD_HEADER;



#pragma pack()

#endif