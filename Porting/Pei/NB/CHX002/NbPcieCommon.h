/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbPcieCommon.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

#ifndef __NB_PCIE_COMMON__
#define __NB_PCIE_COMMON__


#ifdef ZX_DUALSOCKET
#define PCIE_CF_M  0
#define PCIE_CF_S  0x80
#else
#define PCIE_CF_M  0
#endif


/*+ DSZ_Porting -- (JIH-2017021401) Add Pcie Patch PCIEBadListWorkaround*/
typedef enum {
  INITIME_GEN1 = 0,
  RUNTIME_AUTO
} PCIeInitialPhaseCtl;

//JIH - 2017021301 - 3rd party PCIE Bridge on SOC PCIE  occur BSOD issue Patch - s
typedef struct _BAD_PCIE_LINKUP_TBL {
    UINT16  VendorId;
    UINT16  DeviceId;
    UINT16  DeviceIdMask;
    UINT16  PatchSolution;
} BAD_PCIE_LINKUP_TBL;

typedef enum {
  //ForceGen2 = 0,
  ForceDelay100ms,
  ForceSIAnlogSwitchInternal,
  ForceX4,
  ExtraPERST,
  UnsupportL1,
  ForceGen1 = 0
  
} BadListPatchType;



#ifdef ZX_DUALSOCKET	
//#ifdef DUAL_SOCKET_CODE
typedef enum {
  IGD = 0,
  PE0,
  PE1,
  PE2,
  PE3,
  PE4,
  PE5,
  PE6,
  PE7,
  PE0_SLAVE,
  PE1_SLAVE,
  PE2_SLAVE,
  PE3_SLAVE,
  PE4_SLAVE,
  PE5_SLAVE,
  PE6_SLAVE,
  PE7_SLAVE,
  PCI,
  DISPLAY_DEVICE_MAX
} DISPLAY_DEVICE;
#else
typedef enum {
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
  DISPLAY_DEVICE_MAX
} DISPLAY_DEVICE;
#endif



//;cjw_debug - start
typedef enum {
        PE_NA = 0,
        PE_GEN1,
        PE_GEN2,
        PE_GEN3
} PCIE_Cap;

typedef enum {
        PECFG_0 = 0,
        PECFG_1,
        PECFG_2,
        PECFG_3,
        PECFG_4,
        PECFG_5,
        PECFG_6,
        PECFG_7,
        PECFG_8,
        PECFG_9,
        PECFG_10,
        PECFG_11,
//        PECFG_12,
//        PECFG_13,
//        PECFG_14,
//        PECFG_15
} PCIE_CFG;




void PEI_PCIE_NB_80_PORT(IN EFI_PEI_SERVICES **PeiServices, UINT8 Data);


UINT16 
ShiftToMaskBit(
    IN UINT16 MaskBit,
    IN UINT16 ShiftData);


EFI_STATUS
PeiNbPcieStall (
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINTN Millisecond
);


VOID
PCIeDumpMem(
	IN EFI_PEI_SERVICES **PeiServices, 
	UINT32 MemBase, 
	UINT16 DCount);



VOID
PCIeDumpCfg(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount);

UINT8 PCIeCommonBusParser(UINT64 PciAddress);
UINT8 PCIeCommonDevParser(UINT64 PciAddress);
UINT8 PCIeCommonFuncParser(UINT64 PciAddress);

EFI_STATUS 
PCIEBadListWorkaround(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    OUT PCIE_Cap *PcieCap);

EFI_STATUS
PCIeCommonLinkStatus(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr);

EFI_STATUS
PCIeCommonCrsStrategy(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr);

EFI_STATUS
PCIeCommonASPMEnable(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr);

EFI_STATUS
PCIeCommonCrsHandle(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr);


EFI_STATUS
PCIeCommonSpeSetting(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT8 CodeFlag);


EFI_STATUS
CheckAndInitializePcieVga (
    IN     EFI_PEI_SERVICES       **PeiServices,
    IN     UINT8                  Bus,
    IN     UINT8                  Dev,
    IN     UINT8                  Func
);



VOID
CheckPcieVgaCard(
    IN     EFI_PEI_SERVICES             **PeiServices,
    IN     ASIA_NB_CONFIGURATION        *NbConfig,
    IN OUT DISPLAY_DEVICE               *PrimaryDisplay
);

void SyncConfigToRegsiter(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig
);

EFI_STATUS
PCIeCommonEphyPatch(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PhyBar);

VOID
PCIEDnOrderingQueueTiming(
	IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8	RpBusNum,
    IN UINT8	RpDeviceNum,
    IN UINT8	RpFuncNum,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT8    PortSPEValue);

EFI_STATUS
PCIeCommonPERST (
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT64 PciAddress
);

EFI_STATUS
PeiNbPcieS3DoEQ(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	UINT64 PciAddress);

#endif

