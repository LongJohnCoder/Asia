//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "Draminit.h"
#include "UmaSet.h"


VOID SetSVADMMIOCFG(
    IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbCfg,
	IN DRAM_ATTRIBUTE *DramAttr,
	UINT16  MasterMemSize, //unit of 64M, =EndAddr16Temp[0]
	UINT16  SlaveMemSize //unit of 64M, =EndAddr16Temp[1]
);

VOID UpdateSVADMemEntry(
    IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr);


VOID UpdateDVAD(
    IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr);

