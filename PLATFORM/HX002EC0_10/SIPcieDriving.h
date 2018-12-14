//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//Ver	Date				Note
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#ifndef __SI_PCIE_DRIVING_H_
#define __SI_PCIE_DRIVING_H_

#include "Tiano.h"

///
#define PCIE_PHY_DRIVING_VER	003

//#define MB_PCIE_CFG	0x03

////
#define	GPIO_NA	0
//PCIERST0  PEG2 	GPIO_12 	Solt 2 	PHYC 4-7
//PCIERST1  PEG3 	GPIO_13 	Solt 1 	PHYC 0-3
//PCIERST2  PE1   	GPIO_14 	Solt 4 	PHYA 2
//PCIERST4  PE3   	GPIO_37 	OB LAN 	PHYA 0
//PCIERST5  PE2    	GPO_36 	OB USB 	PHYA 1
//PCIERST6  PEG   	GPO_37 	Solt6 	PHYA 4-7
//PCIERST7  PE0    	GPO_38 	Solt5 	PHYA 3
//PCIERST8  PEG0  	GPO_39 	Solt3 	PHYB 0-7



//#define GPO_Reset_PEG	GPO_37
#define GPO_Reset_PE0	GPIO_37
#define GPO_Reset_PE1	GPIO_NA
#define GPO_Reset_PE2	GPIO_NA
#define GPO_Reset_PE3	GPIO_NA
#define GPO_Reset_PE4	GPIO_13
#define GPO_Reset_PE5	GPIO_NA
#define GPO_Reset_PE6	GPIO_12
#define GPO_Reset_PE7	GPIO_14
////

#define PCIEPHYREGDETECT_DEF 0x00
#define PCIEPHYREGDETECT_CONT 0x01
#define PCIEPHYREGDETECT_EVEN 0x02
#define PCIEPHYREGDETECT_ODD 0x03
//#define PCIEPHYREGDETECT_PEG 0x04
#define PCIEPHYREGDETECT_PE4 0x05
#define PCIEPHYREGDETECT_PE5 0x06
#define PCIEPHYREGDETECT_PE6 0x07
#define PCIEPHYREGDETECT_PE7 0x08
#define PCIEPHYREGDETECT_PE0 0x09
#define PCIEPHYREGDETECT_PE1 0x0A
#define PCIEPHYREGDETECT_PE2 0x0B
#define PCIEPHYREGDETECT_PE3 0x0C

typedef struct{
    UINT8  RevisionMin;
    UINT8  RevisionMax;
    UINT16 RegisterNum;
    UINT8  RegType;
    UINT8  RegLoop;
    UINT8  Mask;
    UINT8  Value;
}SI_PCIE_RP_PHY_DRIVING_ITEM;



extern SI_PCIE_RP_PHY_DRIVING_ITEM PcieRpDrivingTbl[];
extern UINTN PcieRpDrivingTblItems;

extern SI_PCIE_RP_PHY_DRIVING_ITEM VpiDrivingTbl[];
extern UINTN VpiDrivingTblItems;


#endif
