//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef ASIA_NB_PPI_H
#define ASIA_NB_PPI_H

#define EFI_ASIA_NB_PPI_GUID \
{ \
  0x68b3c0f6, 0x47b, 0x4e40, 0x97, 0x7c, 0xf7, 0xdf, 0x69, 0xd5, 0xba, 0x6c\
}

typedef struct _EFI_ASIA_NB_PPI EFI_ASIA_NB_PPI;

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_NB_PPI_INIT) (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_NB_PPI *This
  );

typedef struct _EFI_ASIA_NB_PPI{
  VOID* NbCfg; //ASIA_NB_CONFIGURATION
//  ASIA_NB_PPI_INIT PlatformEarlyInit;
  EFI_ASIA_NB_PPI_INIT PreMemoryInit;
  EFI_ASIA_NB_PPI_INIT PostMemoryInit;
  EFI_ASIA_NB_PPI_INIT PostMemoryInitS3;
} EFI_ASIA_NB_PPI;

extern EFI_GUID gAsiaNbPpiGuid;

#endif