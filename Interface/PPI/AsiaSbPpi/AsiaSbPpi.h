//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef ASIA_SB_PPI_H
#define ASIA_SB_PPI_H


#define EFI_ASIA_SB_PPI_GUID \
{ \
  0x532fb050, 0x68da, 0x4c6c, 0x98, 0xbf, 0x5b, 0xa9, 0xf8, 0xb2, 0x36, 0x93\
}

struct _EFI_ASIA_SB_PPI;

typedef
EFI_STATUS
(EFIAPI *EFI_ASIA_SB_PPI_INIT) (
    IN EFI_PEI_SERVICES **PeiServices,
    IN struct _EFI_ASIA_SB_PPI *This
);

typedef
struct _EFI_ASIA_SB_PPI{
	VOID * SbCfg;  //ASIA_SB_CONFIGURATION
    EFI_ASIA_SB_PPI_INIT PreMemoryInit;
    EFI_ASIA_SB_PPI_INIT PostMemoryInit;
    EFI_ASIA_SB_PPI_INIT PostMemoryInitS3;
} EFI_ASIA_SB_PPI;

extern EFI_GUID gAsiaSbPpiGuid;

#endif