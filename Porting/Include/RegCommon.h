//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/*
* license
* the common definition of vtxxxreg.h file.
*/

#ifndef REG_COMMON_H
#define REG_COMMON_H

// Address conversions, only used in vtxxxreg.h or xxxtable.c file.

#define ASIA_PCI_ADDRESS(bus, dev, func, reg)   \
	(UINT64) ((((UINTN) (bus)) << 24) | \
	(((UINTN) (dev)) << 16) | \
	(((UINTN) (func)) << 8) | \
	((reg) < 256 ? ((UINTN) (reg)): ((UINT64) (reg) << 32)))


#define  NON_ASIA_PCI_ADDRESS ASIA_PCI_ADDRESS
// Bit defs
#ifndef BIT0
#define BIT0 0x01
#endif

#ifndef BIT1
#define BIT1 0x02
#endif

#ifndef BIT2
#define BIT2 0x04
#endif

#ifndef BIT3
#define BIT3 0x08
#endif

#ifndef BIT4
#define BIT4 0x10
#endif

#ifndef BIT5
#define BIT5 0x20
#endif

#ifndef BIT6
#define BIT6 0x40
#endif

#ifndef BIT7
#define BIT7 0x80
#endif

#ifndef BIT8
#define BIT8 0x0100
#endif

#ifndef BIT9
#define BIT9 0x0200
#endif

#ifndef BIT10
#define BIT10 0x0400
#endif

#ifndef BIT11
#define BIT11 0x0800
#endif

#ifndef BIT12
#define BIT12 0x1000
#endif

#ifndef BIT13
#define BIT13 0x2000
#endif

#ifndef BIT14
#define BIT14 0x4000
#endif

#ifndef BIT15
#define BIT15 0x8000
#endif

#ifndef BIT16
#define BIT16 0x00010000
#endif

#ifndef BIT17
#define BIT17 0x00020000
#endif

#ifndef BIT18
#define BIT18 0x00040000
#endif

#ifndef BIT19
#define BIT19 0x00080000
#endif

#ifndef BIT20
#define BIT20 0x00100000
#endif

#ifndef BIT21
#define BIT21 0x00200000
#endif

#ifndef BIT22
#define BIT22 0x00400000
#endif

#ifndef BIT23
#define BIT23 0x00800000
#endif

#ifndef BIT24
#define BIT24 0x01000000
#endif

#ifndef BIT25
#define BIT25 0x02000000
#endif

#ifndef BIT26
#define BIT26 0x04000000
#endif

#ifndef BIT27
#define BIT27 0x08000000
#endif

#ifndef BIT28
#define BIT28 0x10000000
#endif

#ifndef BIT29
#define BIT29 0x20000000
#endif

#ifndef BIT30
#define BIT30 0x40000000
#endif

#ifndef BIT31
#define BIT31 0x80000000
#endif


#endif