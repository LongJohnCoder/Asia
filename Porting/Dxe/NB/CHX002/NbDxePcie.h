/** @file
   ZX-E(CHX002) Asia NbDxe library functions : NbDxePcie.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
 #ifndef _NB_DXE_PCIE_H_
#define _NB_DXE_PCIE_H_

typedef struct _BAD_PCIE_ASPM_TBL {
    UINT16  VendorId;
    UINT16  DeviceId;
    UINT16  DeviceIdMask;
} BAD_PCIE_ASPM_TBL;

typedef struct _PROTECT_ENDP_DEV_TBL {
    UINT16  VendorId;
    UINT16  DeviceId;
} PROTECT_ENDP_DEV_TBL;
typedef struct _PCIE_EPHY_DRIVING_TBL {
    UINT16  VendorId;
    UINT16  DeviceId;
    UINT16  DeviceIdMask;
} PCIE_EPHY_DRIVING_TBL;

BOOLEAN CheckEphyDrivingIssueDevice(
    UINT64 Address
);



//CHX001-CJW-20151021 -start
/*
VOID EphyAggresivePmMode(
    IN	ASIA_NB_CONFIGURATION *NbCfg
);
*/
//CHX001-CJW-20151021 -end

//CJW_20170510 removed
//VOID ClearRpSlotStatus(
//    IN	ASIA_NB_CONFIGURATION *NbCfg
//);
VOID ProgramHpSlotCapability(
    IN	ASIA_NB_CONFIGURATION *NbCfg
);

VOID ProgramHpGPIPolarity(
    IN	ASIA_NB_CONFIGURATION *NbCfg
);



VOID PCIE_DXE_80_PORT(UINT8 Data);



VOID ProgramRPSlotPowerLimit(
    IN	ASIA_NB_CONFIGURATION *NbCfg,
    IN	UINT64	Address
);

VOID EnablePcieMsiCap();
BOOLEAN IsPciePresent(UINT64 Address);

typedef struct _PCIE_NODE_TBL {
    UINT8   BusNum;
    UINT8   DevNum;
    UINT8   FuncNum;
    UINT8	SecBusNum;
    //UINT8	SubOrdnBus;
    //UINT8	ParentBus;
    //UINT8	ParentBusDev;
    //UINT8	ParentFunc;
    UINT8   PcieCapOff;
    UINT8   AspmSupported;
	/*+ DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/

	UINT8   SlotClkCfg;
	/*- DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/

} PCIE_NODE_TBL;

// Limited to 0x100. If the number of PCIE Port behind the Root Port, there will be Error!
#define MAX_PCIE_PORT   0x100
typedef struct _PCIE_RESOURCE {
    UINTN	PcieNodeNum;
    UINT8 	MinMpsSupport;
    PCIE_NODE_TBL PcieNodeTbl[MAX_PCIE_PORT];
} PCIE_RESOURCE;

EFI_STATUS ProgramPcieTreeFeature(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8	RpBusNum,
    UINT8	RpDeviceNum,
    UINT8	RpFuncNum
);

EFI_STATUS ConfigPcieRPDoEq(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8	RpBusNum,
    UINT8	RpDeviceNum,
    UINT8	RpFuncNum
);


VOID
DumpMemDxe(
	UINT64 MemBase, 
	UINT16 DCount);

VOID
DumpCfgDxe(
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount);


EFI_STATUS
PcieEyeMonitorDbg(ASIA_NB_CONFIGURATION *NbCfg);


#endif
