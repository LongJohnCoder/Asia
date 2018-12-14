//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _DRAMBLOCK_H
#define _DRAMBLOCK_H

#ifdef ZX_TXT_SUPPORT
EFI_STATUS DramBlockClean(
    IN EFI_PEI_SERVICES **PeiServices,
    IN DRAM_ATTRIBUTE *DramAttr
);
#endif

#endif