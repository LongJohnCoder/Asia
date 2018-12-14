//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _UMA_SET_H
#define _UMA_SET_H

/////

EFI_STATUS UmaDisable(
  IN EFI_PEI_SERVICES **PeiServices,
  IN DRAM_ATTRIBUTE *DramAttr,
  IN ASIA_NB_CONFIGURATION *SetupData
);

EFI_STATUS UmaEnable(
  IN EFI_PEI_SERVICES **PeiServices,
  IN DRAM_ATTRIBUTE *DramAttr,
  IN ASIA_NB_CONFIGURATION *SetupData
);

EFI_STATUS UmaEnableS3(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN ASIA_NB_CONFIGURATION *SetupData
);


UINT16 GetRealUmaSize(
  IN EFI_PEI_SERVICES **PeiServices,
  IN DRAM_ATTRIBUTE *DramAttr,
  IN ASIA_NB_CONFIGURATION *SetupData
);

EFI_STATUS GetDramInfoForUma(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
);

#endif
