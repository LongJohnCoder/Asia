//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _CHX001_ASIA_DRAM_H_
#define _CHX001_ASIA_DRAM_H_

// {FE3E277D-1559-4de2-B10A-FC74DC75EFD3}
#define EFI_ASIA_DRAM_PPI_GUID \
{ 0x5e3e277d, 0x8559, 0x4de2, 0x51, 0xa, 0xfc, 0x74, 0xdc, 0x75, 0x7f, 0xd8}

EFI_FORWARD_DECLARATION (EFI_ASIA_DRAM_PPI);

typedef
EFI_STATUS
(EFIAPI *EFI_ASIA_DRAM_PPI_NORMAL_INIT)(
    IN EFI_PEI_SERVICES **PeiServices,
    IN struct _EFI_ASIA_DRAM_PPI *This
//    IN VOID *ConfigData //ASIA_DRAM_CONFIGURATION -- this struct defined in XXXCfg.h file
);

typedef
EFI_STATUS
(EFIAPI *EFI_ASIA_DRAM_PPI_S3_INIT)(
    IN EFI_PEI_SERVICES **PeiServices,
    IN struct _EFI_ASIA_DRAM_PPI *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_ASIA_DRAM_PPI_GET_INFO)(
    IN EFI_PEI_SERVICES **PeiServices,
    IN struct _EFI_ASIA_DRAM_PPI *This,
    OUT  VOID *DramInfo//ASIA_DRAM_INFO -- this struct defined in XXXCfg.h file
);

typedef struct _EFI_ASIA_DRAM_PPI {
	VOID * DramCfg; //ASIA_DRAM_CONFIGURATION
    EFI_ASIA_DRAM_PPI_NORMAL_INIT DramNormalInit;
    EFI_ASIA_DRAM_PPI_S3_INIT DramS3Init;
    EFI_ASIA_DRAM_PPI_GET_INFO DramGetInfo;
} EFI_ASIA_DRAM_PPI;

extern EFI_GUID gAsiaDramPpiGuid;

#endif
