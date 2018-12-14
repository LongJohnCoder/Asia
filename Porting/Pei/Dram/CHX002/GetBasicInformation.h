//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _GETBASICINFORMATION_H
#define _GETBASICINFORMATION_H

UINT8 DCLKString(UINT32 DCLKSetting);

UINT8 ODZ(UINT32 ODZSetting);

UINT8 Rnom(UINT32 RnomSetting);

UINT8 Rwr(UINT32 RwrSetting);

EFI_STATUS GetBasicInformation(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
);


#endif

