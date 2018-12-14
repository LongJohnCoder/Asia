//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _FINALTABLEPROGRAMMING_H
#define _FINALTABLEPROGRAMMING_H

EFI_STATUS FinalTableProgramming(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN PEI_SMBUS_PPI *pSMBusPPI,
	IN DRAM_ATTRIBUTE *DramAttr);


#endif

