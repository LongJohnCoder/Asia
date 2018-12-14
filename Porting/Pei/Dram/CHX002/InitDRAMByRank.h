//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _INITDRAMBYRANK_H
#define _INITDRAMBYRANK_H

VOID SwInitDRAMByRank(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

VOID SwInitDdr4Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN INT8 RankIndex);

UINT32 GetDDR4MR0(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8);

UINT32 GetDDR4MR1(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8);

UINT32 GetDDR4MR2(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8);

UINT32 GetDDR4MR3(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 ActionType16);
UINT32 GetDDR4MR4(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8);
UINT32 GetDDR4MR5(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8);
UINT32 GetDDR4MR6(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8,
	IN UINT32 VrefDQ);

UINT32 GetMrsNo(UINT32 MRSetting, UINT8 MrsNo);


UINT32 Rank1AddressMirror(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 MRSValue32);

UINT32 SideBAddressInvert(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT32 MRSValue32);

VOID HwInitDRAMByRank(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

VOID HwInitDdr4Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
 	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 ChIndex,
	IN UINT8 RankIndex);
VOID SwInitRCDByDimm(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

VOID SwSetCALMode(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

EFI_STATUS InitDRAMByRank(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);



#endif

