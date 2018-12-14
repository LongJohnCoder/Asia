/** @file
   ZX-E(CHX002) Asia SbPei library functions : SbLibPpi.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef __SB_LIB_PPI_H_
#define __SB_LIB_PPI_H_

#include "AsiaSbPeim.h" /*SbLibPpiGuid defined in this file*/

EFI_FORWARD_DECLARATION(ASIA_SB_LIB_PPI);
// In CHX002 SB, we have 9 GPI,13 GPO and 51 GPIO
// GPIO 0~7       input: PMIO_Rx48[10:17]     output: PMIO_Rx4C[11:18]
// GPIO 10~13     input: PMIO_Rx48[20,23]  output: PMIO_Rx4C[21,24]
// GPIO 14		  input: PMIO_Rx48[28]  output: PMIO_Rx4C[27]
// GPIO 26~32      input: PMIO_Rx3C[9:15]      output: PMIO_Rx3C[25:31]
// GPIO 33     input: PMIO_Rx46[0]  output: PMIO_Rx47[0]
// GPIO 36~37      input: PMIO_Rx46[3:4]       output: PMIO_Rx47[3:4]
// GPIO 39~40,44~54,56,75~88     
// GPO  0~7                                    output: PMIO_Rx4C[0:7]
// GPO  36~40                                  output: PMIO_Rx83[0:4]
// GPI  0~7       input: PMIO_Rx48[0:7]
// GPI  10   input: PMIO_Rx4B[0]

typedef enum {
    // GPIO
    GPIO_00, GPIO_01, GPIO_02, GPIO_03, GPIO_04, GPIO_05, GPIO_06, GPIO_07,
    GPIO_10, GPIO_11, GPIO_12, GPIO_13, GPIO_14, GPIO_26, GPIO_27, GPIO_28,    
    GPIO_29, GPIO_30, GPIO_31, GPIO_32, GPIO_33, GPIO_36, GPIO_37, GPIO_39,
    GPIO_40, GPIO_44, GPIO_45, GPIO_46, GPIO_47, GPIO_48, GPIO_49, GPIO_50, 
    GPIO_51, GPIO_52, GPIO_53, GPIO_54, GPIO_55, GPIO_56, GPIO_75, GPIO_76, 
    GPIO_77, GPIO_78, GPIO_79, GPIO_80, GPIO_83, GPIO_84, GPIO_85, GPIO_86, 
    GPIO_87, GPIO_88,  // GPI
    GPI_00, GPI_01, GPI_02, GPI_03, GPI_04, GPI_05, GPI_06, GPI_07,GPI_10,
    // GPO
    GPO_00, GPO_01, GPO_02, GPO_03, GPO_04, GPO_05, GPO_06, GPO_07,
    GPO_36, GPO_37, GPO_38, GPO_39, GPO_40
} ASIA_GPIO;
 
/*SB Lib PPI define*/
typedef
EFI_STATUS
(EFIAPI *ASIA_SB_LIB_SET_GPO) (
  IN EFI_PEI_SERVICES **PeiServices,
//  IN struct _ASIA_SB_LIB_PPI *This,
  IN ASIA_GPIO Index,
  IN BOOLEAN Value
  );

typedef
EFI_STATUS
(EFIAPI *ASIA_SB_LIB_GET_GPI) (
  IN EFI_PEI_SERVICES **PeiServices,
//  IN struct _ASIA_SB_LIB_PPI *This,
  IN ASIA_GPIO Index,
  OUT BOOLEAN* Value
  );

typedef
EFI_STATUS
(EFIAPI *ASIA_SB_LIB_GET_ACPI_TIMER_VALUE) (
  IN EFI_PEI_SERVICES **PeiServices,
  IN ASIA_SB_LIB_PPI *This,
  OUT UINT32 *Value,
  OUT BOOLEAN *Extended OPTIONAL
  );

typedef
struct _ASIA_SB_LIB_PPI {
  UINT16 PmioBaseAddress;
  ASIA_SB_LIB_SET_GPO SetGpo;
  ASIA_SB_LIB_GET_GPI GetGpi;
  ASIA_SB_LIB_GET_ACPI_TIMER_VALUE GetAcpiTimerValue;
} ASIA_SB_LIB_PPI;

#endif
