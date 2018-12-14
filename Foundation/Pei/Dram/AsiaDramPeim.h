//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef _ASIA_DRAM_PEIM_H_
#define _ASIA_DRAM_PEIM_H_

#include "Pei.h"
#include "PPI\AsiaDramPpi\AsiaDramPpi.h"

#define ASIA_DRAM_PEI_PRIVATE_DATA_SIGNATURE  EFI_SIGNATURE_32 ('M', 'V', 'I', 'S')

typedef struct _ASIA_DRAM_PEI_PRIVATE_DATA_{
    UINT32  Signature;
	//UINT8   Data[8]; //save internal parameter 
	EFI_ASIA_DRAM_PPI AsiaDramPpi;
	EFI_PEI_PPI_DESCRIPTOR PpiDesc;
	VOID    *DramAttr;
}ASIA_DRAM_PEI_PRIVATE_DATA;

#define GET_PRIVATE_DATA_FROM_THIS(a) PEI_CR(a, ASIA_DRAM_PEI_PRIVATE_DATA, AsiaDramPpi, ASIA_DRAM_PEI_PRIVATE_DATA_SIGNATURE)

EFI_STATUS InitDramPrivateData(
    IN EFI_PEI_SERVICES **PeiServices,
    OUT ASIA_DRAM_PEI_PRIVATE_DATA *PrivateData
);

EFI_STATUS DramNormalInit(
    IN EFI_PEI_SERVICES      **PeiServices,
    IN EFI_ASIA_DRAM_PPI     *This
//    IN VOID  *ConfigData// ASIA_DRAM_CONFIGURATION
);

EFI_STATUS DramS3Init(
    IN EFI_PEI_SERVICES      **PeiServices,
    IN EFI_ASIA_DRAM_PPI     *This
);

EFI_STATUS DramGetInfo(
    IN EFI_PEI_SERVICES      **PeiServices,
    IN EFI_ASIA_DRAM_PPI     *This,
    OUT VOID       *DramInfo//ASIA_DRAM_INFO
);

#endif