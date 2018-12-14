//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _SIVALUEPROGRAMMING_H
#define _SIVALUEPROGRAMMING_H


#include "SIDRAMTbl.h"


VOID ODTProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID BasicIOTimingProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID DrivingProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);


VOID DrivingSelectionProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID ClkPhaseProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID ClkDutyProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID EQPCtrlProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);
    
VOID RxEqProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID VrefProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID DdrPhyProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);

VOID VcdlOutputClkProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr);
    
VOID ProgramDramcRegister(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8              FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr,
    IN SI_DRAMC_REGISTER_SETTING *Item);

VOID SetDramcRegister(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8              FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr,
    IN SI_DRAMC_REGISTER_SETTING  *Item);

UINT8 FreqIdxInTable(	
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr);

VOID SI_TNI(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN SI_DRAMC_REGISTER_SETTING ReadTimingTbl[],
  IN UINT32 ReadTimingTblItems);


VOID SI_DQSI(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN SI_DRAMC_REGISTER_SETTING ReadTimingTbl[],
  IN UINT32 ReadTimingTblItems);


VOID SI_DQSO(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN SI_DRAMC_REGISTER_SETTING OutputTimingTbl[],
  IN UINT32 OutputTimingTblItems);


VOID SI_DQO(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN SI_DRAMC_REGISTER_SETTING OutputTimingTbl[],
  IN UINT32 OutputTimingTblItems);

VOID Tx_Manual_Vref(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr); 

void Setup_SetTxVref(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr);

EFI_STATUS SIValueProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr);


#endif

