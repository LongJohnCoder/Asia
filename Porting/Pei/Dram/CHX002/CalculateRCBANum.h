//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#ifndef _CALCUTATERCBANUM_H
#define _CALCUTATERCBANUM_H

EFI_STATUS Sizing(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
);



#endif
