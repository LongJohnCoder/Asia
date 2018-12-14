//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _DRAMINFO_H
#define _DRAMINFO_H

EFI_STATUS DramGetInfo(
    IN EFI_PEI_SERVICES           **PeiServices,
    IN EFI_ASIA_DRAM_PPI          *This,
    OUT VOID                      *DramInfo
);


#endif

