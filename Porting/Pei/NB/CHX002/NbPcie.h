/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbPcie.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

 #ifndef _ASIA_NBPCIE_PPI_INTERFACE_H_
#define _ASIA_NBPCIE_PPI_INTERFACE_H_

//#include "Ppi\AsiaPciePpi\AsiaPciePpi.h"

//DaisyZhang added 20170622, move from REG_CHX002_PCIEPHY.h
//@self defined macro begin
#define PHYLS_State_L0 0x8A
//@self defined macro end
/*typedef enum {
  IGD = 0,
  PE0,
  PE1,
  PE2,
  PE3,
  PE4,
  PE5,
  PE6,
  PE7,
  PCI,
  DISPLAY_DEVICE_SLAVE_NO_USE_MAX
} DISPLAY_DEVICE_SLAVE_NO_USE;
*/
//VOID
//CheckAndInitializePegVga (
  //IN     EFI_PEI_SERVICES                 **PeiServices,
  //IN     PEI_CPU_IO_PPI                   *CpuIo,
//IN     PEI_POLICY_IGD                   *NbIgdPolicy,
  //IN OUT DISPLAY_DEVICE                   *PrimaryDisplay
  //);
/*
EFI_STATUS
PeiNbEnablePcieConfiguration (
  IN EFI_PEI_SERVICES **PeiServices,
   IN ASIA_NB_CONFIGURATION *NbConfig
  );

EFI_STATUS
PeiNbSetPciePort (
  IN EFI_PEI_SERVICES **PeiServices,
  IN BOOLEAN EnableDisable,
  IN UINT64 PciAddress					
  );
*/
EFI_STATUS
PeiNbCheckPcieLinkStatus (
  IN EFI_PEI_SERVICES **PeiServices,
  IN ASIA_NB_CONFIGURATION *NbConfig,
  IN UINT64 PciAddress,					
  IN UINT8 TempBus						
  );

EFI_STATUS
PeiNbResetPciePort (
  IN EFI_PEI_SERVICES **PeiServices,
  IN UINT64 PciAddress					
  );

EFI_STATUS
PeiNbCheckPcieErrorStatus (
  IN EFI_PEI_SERVICES **PeiServices,
  IN ASIA_NB_CONFIGURATION *NbConfig,
  IN UINT64 PciAddress
  );


EFI_STATUS
SetPcieXLink(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,    
    IN UINT8 PhaseCtl
    );

EFI_STATUS PeRstWhenLinkFail(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 Address
    );//3

EFI_STATUS
PeiNbPcieInit(
  IN EFI_PEI_SERVICES **PeiServices,
  IN ASIA_NB_CONFIGURATION *NbConfig
); 




/*
//CJW_20170510 removed
VOID 
ClearTempBusNo(
    IN     EFI_PEI_SERVICES       **PeiServices,
    IN     UINT8                  Bus
	); 
*/
#endif //_ASIA_NBPCIE_PPI_INTERFACE_H_

