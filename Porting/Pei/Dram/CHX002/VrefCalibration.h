//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _VREFCALIBRATION_H
#define _VREFCALIBRATION_H

EFI_STATUS SwSetTxVref(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 VrefRange,
	IN UINT32 VrefDQ);

VOID Rx_VrefDQSI_Cal(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr);

VOID Rx_VrefDQSI_PREAMBLE_Cal(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

VOID Rx_VrefDQSI_Cal_New(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr);


#endif

