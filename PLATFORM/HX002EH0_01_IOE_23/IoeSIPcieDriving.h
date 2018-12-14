//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef __IOE_SI_PCIE_DRIVING_H__
#define __IOE_SI_PCIE_DRIVING_H__


#include "Tiano.h"

//#; PCIE_ECONF=0x1, PE0: X2, PEG1: X2, PE1: X1, PE2: X1, PE3: X1, SATA: X12.
//#; PCIE_ECONF=0x2, PE0: X4, PE1: X1, PE2: X1, PE3: X1, SATA: X12,
//#; PCIE_ECONF=0x3, PE0: X4, PE1: X1, PE2: X1, PEG1: X1, PE3: X4, SATA: X14
//#; PCIE_ECONF=0x4, PE0: X4, PE1: X1, PE2: X1, PEG1: X1, PE3: X4, SATA: X8
//#; PCIE_ECONF=0x4B, PE0: X2, PEG1: X2, PE1: X1, PE2: X1, PE3: X1, PEG0: X4, SATA: X8
//#; PCIE_ECONF=0x5, PEG0: X8, PE0: X4, PE1: X1, SATA: X6
//#; PCIE_ECONF=0x5B, PEG0: X8, PE0: X2, PEG1: X2, PE1:X1, PE3: X4,  SATA: X2
//#; PCIE_ECONF=0x6, PEG0: X4, PEG1: X4, PE0: X4,PE1: X1, SATA: X6
//#; PCIE_ECONF=0x6B, PEG0: X4, PEG1: X4, PE0: X4, PE1: X1, PE3: X4, SATA: X2
//#; PCIE_ECONF=0x7, PEG0: X8, PE0: X4, PE1: X1, PE2: X1, PE3: X1, SATA: X4.
//#; PCIE_ECONF=0x7B, PEG0: X8, PE0: X2, PEG1: X2, PE1: X1, PE2: X1, PE3: X1, SATA: X4.
//#; PCIE_ECONF=0x8, PEG0: X4, PEG1: X4, PE0: X4, PE1: X1, PE2: X1, PE3: X1, SATA: X4.
//#; PCIE_ECONF=0x9, PEG0: X8, PE0: X4, PE1: X1, PE2: X1, PEG1: X1, PE3: X4.
/*
#define MB_PCIE_CFG	0x7B

#define PCIE_PHY_DRIVING_VER	000

#define GPO_Reset_PEG0	GPIO_12
#define GPO_Reset_PE0	GPIO_14
#define GPO_Reset_PE1	GPO_36
#define GPO_Reset_PE2	GPIO_13
#define GPO_Reset_PE3	GPIO_27
#define GPO_Reset_PEG1	GPIO_26
*/
#define PCIEPHYREGDETECT_DEF 0x00
#define PCIEPHYREGDETECT_CONT 0x01
#define PCIEPHYREGDETECT_EVEN 0x02
#define PCIEPHYREGDETECT_ODD 0x03


typedef struct{
    UINT8  RevisionMin;
    UINT8  RevisionMax;
    UINT16 RegisterNum;
    UINT8  RegType;
    UINT8  RegLoop;
    UINT8  Mask;
    UINT8  Value;
}SI_PCIE_PHY_CND003DRIVING_ITEM;

typedef struct{
    UINT8  RevisionMin;
    UINT8  RevisionMax;
    UINT16 RegisterNum;
    UINT8  RegType;
    UINT8  RegLoop;
    UINT16  Mask;
    UINT16  Value;
}SI_PCIE_PHY_CND003BISTDRIVING_ITEM;

extern SI_PCIE_PHY_CND003DRIVING_ITEM PcieCND003DrivingTbl_A0[];
extern SI_PCIE_PHY_CND003DRIVING_ITEM PcieCND003DrivingTbl_A1[];
extern SI_PCIE_PHY_CND003BISTDRIVING_ITEM PcieCND003BistDrivingTbl[];
extern UINTN PcieCND003DrivingTblItems_A0;
extern UINTN PcieCND003DrivingTblItems_A1;
extern UINTN PcieCND003DrivingBistTblItems;
#endif

