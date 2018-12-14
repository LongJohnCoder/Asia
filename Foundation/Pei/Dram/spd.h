//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
/*
SPD function
*/

#ifndef __SPD_H__
#define __SPD_H__

#include "PeiApi.h"
#include EFI_PPI_DEFINITION (Smbus)

#define SMBUS_ADDR_CH_A_1         0xA0        // Dimmx
#define SMBUS_ADDR_CH_A_2         0xA2        // Dimmx
#define SMBUS_ADDR_CH_B_1         0xA4        // Dimmx
#define SMBUS_ADDR_CH_B_2         0xA6        // Dimmx

/*read a byte*/
EFI_STATUS ReadSPDByte(IN EFI_PEI_SERVICES **PeiServices,
                       IN PEI_SMBUS_PPI *pSMBusPPI,
                       IN UINT8 Slot,
                       IN UINT16 Index,
                       OUT UINT8 *Val);
/*read data*/
EFI_STATUS GetSPDData(IN EFI_PEI_SERVICES **PeiServices,
                      IN PEI_SMBUS_PPI *pSMBusPPI,
                      IN UINT8 Slot,
                      IN UINT16 Length,
                      OUT UINT8 *Buf);


#endif //__SPD_H__
