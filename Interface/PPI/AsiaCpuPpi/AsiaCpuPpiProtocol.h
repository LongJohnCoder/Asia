//**************************************************************************
//**************************************************************************
//**                                                                  **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**************************************************************************
//**************************************************************************
#ifndef _ASIA_CPU_PPI_PROTOCOL_H_
#define _ASIA_CPU_PPI_PROTOCOL_H_


#define PSTATE_NUMBER        0x08
#define PSTATE_TRANSITION    0xC0

typedef struct _ASIA_CPU_CONFIGURATION {
    BOOLEAN                 FastString;
    BOOLEAN                 EpsEnable;
    BOOLEAN                 FerrInterruptReporting;
    BOOLEAN                 BootWithMaxFrequence;
    BOOLEAN                 NAPSNAPEnalbe;
    BOOLEAN                 LimitCpuidMaximumValue;
    BOOLEAN                 L3CacheEnable;
    BOOLEAN                 PeciEnable;
    BOOLEAN                 VtEnable;
    BOOLEAN                 LtEnable;
    BOOLEAN                 ExecuteDisableBit;
    BOOLEAN                 MachineCheckEnable;
    BOOLEAN                 HardwarePrefetcherEnable;
    BOOLEAN                 AdjacentCacheLinePrefetchEnable;
    BOOLEAN                 MonitorMWaitEnable;
    BOOLEAN                 TPREchoEnable;

	BOOLEAN                 TscDeadlineModeEnable;
    BOOLEAN                 Msr3AEnable;

    //PLVL2 IO base
    UINT16                  PLVL2IoBase;
    UINT16                  PLVL2IoBaseSlave;

    BOOLEAN                 ProcessorCxeEnable;

    //BOOLEAN                 PmonEnable;


	//Change VrmSupport definition as following:
    //VRM Type and phase
    // Bit4: 0 = PVID, 1 = SVID, Not used in AMIEFI, only for BYO to display in BIOS setup
    // Bit[3:0]: VRM Phases
    UINT8                   VrmSupport;

    // Change ADDON-FEATURE hob to ASIA_CPU_CONFIGURATION hob
    UINT8                   ActiveCpuNum;
    UINT8                   C5Control;

	BOOLEAN                 C5L2sizingControl;
	BOOLEAN                 CxIntFilterControl;
	UINT8					ProcessorCState;
#ifdef ZX_TXT_SUPPORT
    BOOLEAN                 TxtEnable;
#endif

   	BOOLEAN MCASupport;
    // secret-code +S
#ifdef ZX_SECRET_CODE
    UINT8                   KillAp;
#endif
    // secret-code +E
} ASIA_CPU_CONFIGURATION;

#define ASIA_CPU_CFG_HOB_GUID \
{ \
  0x65c4d50d, 0x27a4, 0x446a, 0x8f, 0x36, 0x4e, 0x3a, 0xfd, 0x88, 0x78, 0xcd \
}

typedef struct {
    UINT8                State;                          // State number (0 - (N-1))
    UINT8                VID;                            // VID_SEL value t
    UINT8                BusRatio;                       // BUS_RATIO_SEL
    UINT16               CoreFreq;                       // unit of MHZ
    UINT16               Power;                          // Typical power consumed by CPU in this state (mW)
} ACPU_PSTATE;

typedef struct _ACPU_PSTATE_TABLE_ {
    UINT8  StatesNum;
    ACPU_PSTATE PStateTable[PSTATE_NUMBER];
} ACPU_PSTATE_TABLE;

//cpu singature and version information
typedef struct _ACPU_VERSION_INFO {
    UINT32           Signature;
    UINT32           MiscInfo;
    UINT32           FeatureEdx;
    UINT32           FeatureEcx;
    UINT32           ExtFeatureEdx;
    UINT8            Family;
} ACPU_VERSION_INFO;

//cpu BrandString information
#define ACPU_BRAND_STRING_MAX_LENGTH     49

//Cpu Speed information
//note that bus ratio is double of the real bus ratio
typedef struct _ACPU_SPEED_INFO {
    UINT8         MaxVID;
    UINT8         MaxBusRatio;       //double the real
    UINT8         MinVID;
    UINT8         MinBusRatio;       //double the real
    UINT8         CurrentBusRatio;   //double the real
    UINT32        CPUBusSpeed;          //unit of MHZ
    UINT32        Voltage;
} ACPU_SPEED_INFO;

//cache information
#define  ACPU_CACHE_LEVEL_L1         1
#define  ACPU_CACHE_LEVEL_L2         2
#define  ACPU_CACHE_LEVEL_L3         3

#define ACPU_CACHE_TYPE_OTHER        1
#define ACPU_CACHE_TYPE_UNKNOWN      2
#define ACPU_CACHE_TYPE_CODE         3
#define ACPU_CACHE_TYPE_DATA         4
#define ACPU_CACHE_TYPE_UNIFIED      5

#define ACPU_CACHE_INFO_NUM       3

typedef struct  _ACPU_CACHE_INFO_ {
    UINT8    Level;              // 1: L1; 2:L2
    UINT8    Type;              // 1 : Data; 2:Instruction;3:Unified;
    UINT8    Associativity;
    UINT8    LineSize;
    UINT16   CacheSize;         //Unit of K
} ACPU_CACHE_INFO;

#define ACPU_MICROCODE_UPDATE_SIGNATURE   0x53415252

typedef struct  _ACPU_MICROCODE_UPDATE_HEADER{
     UINT32   Signature;
     UINT32   UpdateResion;
     UINT16   Year;
     UINT8    Day;
     UINT8    Month;
     UINT32   ProcessorId;
     UINT32   Checksum;           //checksum of the entire microcode update file excluding the header
     UINT32   LoaderRevision;
     UINT32   Reserved1;
     UINT32   DataSize;
     UINT32   TotalSize;
     UINT32   Reserved2;
     UINT32   Reserved3;
     UINT32   Reserved4;
}ACPU_MICROCODE_UPDATE_HEADER;

typedef EFI_STATUS (EFIAPI *ASIA_CPU_MICROCODE_UPDATE) (
    IN    ACPU_MICROCODE_UPDATE_HEADER *MicrocodeHeader,
    OUT UINT32                        *UpdateRevision
);

typedef UINT32 (EFIAPI *ASIA_GET_CPU_UPDATE_REVISION) ();

typedef VOID   (EFIAPI *ASIA_CPU_FEATURE_INIT) (
    IN ASIA_CPU_CONFIGURATION  *CpuFeature
);

//
typedef VOID   (EFIAPI *ASIA_CPU_TSC_DELAY) (
    IN UINTN      Microseconds
);
//

typedef VOID (EFIAPI * ASIA_GET_CPU_SUPPORT_FEATURE) (
    OUT ASIA_CPU_CONFIGURATION * CpuFeature
);

typedef VOID (EFIAPI * ASIA_GET_CPU_VERSION_INFO) (
    OUT ACPU_VERSION_INFO * CpuVerInfo
);

typedef VOID (EFIAPI * ASIA_GET_CPU_CAHCE_INFO) (
    OUT ACPU_CACHE_INFO CpuCacheInfo[]
);

typedef VOID (EFIAPI * ASIA_GET_CPU_BRAND_STRING) (
    OUT CHAR8 * CpuBrandString
);

typedef VOID (EFIAPI * ASIA_GET_CPU_SPEED_INFO) (
    OUT ACPU_SPEED_INFO * CpuSpeedInfo
);

typedef UINT8 (EFIAPI * ASIA_GET_CPU_CORES)();

typedef UINT8 (EFIAPI * ASIA_GET_CPU_HTS)();

typedef EFI_STATUS (EFIAPI * ASIA_GET_CPU_PSTATE_TABLE) (
    OUT ACPU_PSTATE_TABLE *Header
);

typedef UINT8 (EFIAPI * ASIA_GET_CPU_CLUSTERS)();
/*this interface will be used in both PEI and DXE phase*/
typedef struct _EFI_ASIA_CPU_PPI_PROTOCOL {
    ASIA_CPU_MICROCODE_UPDATE CpuMicrocodeUpdate;
    ASIA_CPU_FEATURE_INIT     CpuFeatureInit;
    ASIA_CPU_TSC_DELAY         TscDelay;
    ASIA_GET_CPU_UPDATE_REVISION  GetUpdateRevision;
    ASIA_GET_CPU_SUPPORT_FEATURE GetCpuSupportFeature;
    ASIA_GET_CPU_VERSION_INFO    GetCpuVersionInfo;
    ASIA_GET_CPU_CAHCE_INFO      GetCpuCacheInfo;
    ASIA_GET_CPU_BRAND_STRING    GetCpuBrandString;
    ASIA_GET_CPU_SPEED_INFO      GetCpuSpeedInfo;
    ASIA_GET_CPU_CORES           GetCpuCores;
    ASIA_GET_CPU_HTS             GetCpuHts;
    ASIA_GET_CPU_PSTATE_TABLE    GetCpuPstateTable;
	ASIA_GET_CPU_CLUSTERS        GetCpuClusters;


} EFI_ASIA_CPU_PPI_PROTOCOL;

#endif //