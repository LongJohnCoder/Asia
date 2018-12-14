//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef __DRAM_UTIL_H__
#define __DRAM_UTIL_H__

#include "EfiTypes.h"
#include "PeiApi.h"

#define		STEPSPAN        0x100000            //the span when test memory in spare mode  
#define		TESTCOUNT       0x10                // the test count in each range when test memory in spare mode  
#define		SkipCacheRange	0x10000				//Skip cache range to avoid code crash

#define   TEST_PATTERN    0x5A5A5A5A             //the test pattern 

typedef  enum   __DRAM_TEST_MODE{
    EXTENSIVE,
    SPARE,
    MAXMODE
} DRAM_TEST_MODE;

VOID WaitForMicroSec(IN EFI_PEI_SERVICES **PeiServices,
                  IN UINTN MicroSeconds);

BOOLEAN DramBaseTest(IN struct _EFI_PEI_SERVICES **PeiServices,
                     IN UINT32                     BaseAdd, 
                     IN UINT32                     Length,
                     IN DRAM_TEST_MODE             mode,
                     IN BOOLEAN                    PrintFlag);

VOID DumpRegisters(	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
                    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
                    IN INTN DevNum,
                    IN INTN FuncNum	);

VOID DumpPcieRegisters(IN struct _EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    				IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    				IN UINT64 PcieBaseAddr,
    				IN UINTN  DevNum,
    				IN UINTN  FuncNum,
    				IN UINTN  RegNum,
    				IN UINTN  Count);

UINT16 ShiftToMaskBit(IN UINT16 MaskBit,
					 IN UINT16 ShiftData);
UINT8  RegisterOffset8bit( IN      UINT8        MaskBit);
UINT16  RegisterOffset16bit( IN    UINT16     MaskBit);


#endif
