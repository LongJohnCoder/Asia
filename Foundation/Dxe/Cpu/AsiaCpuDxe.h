//**************************************************************************
//**************************************************************************
//**                                                                  **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**************************************************************************
//**************************************************************************

#ifndef _ASIA_CPU_INTERFACE_H_
#define _ASIA_CPU_INTERFACE_H_

#include EFI_PROTOCOL_DEFINITION(AsiaCpuProtocol)
/* */
EFI_STATUS  MicrocodeCheckAndTriger(
    IN ACPU_MICROCODE_UPDATE_HEADER  *MicrocodeHeader,
    OUT UINT32 *UpdateRevision
);

/*init CPU feature */
void CpuFeatureInitialize(ASIA_CPU_CONFIGURATION *Feature);

//use TSC to delay
void TscDelay( UINTN Microseconds);

/*get CPU supported feature */
void GetACpuSupportFeature(ASIA_CPU_CONFIGURATION  *SupportFeature);

/*get Version Infomation */
void  GetACpuVersionInfo(ACPU_VERSION_INFO  *VersionInfo);

/*get Brand string*/
void  GetACpuBrandString(CHAR8 *String);

/*Cpu construction information*/
UINT8 GetACpuCores();

/*logical cpu number */
UINT8  GetACpuHts();

/*speed infomation */
void  GetACpuSpeedInfo(ACPU_SPEED_INFO  *SpeedInfo);

/*microcode infomation*/
UINT32  GetACpuMicrocodeRevision();

/* */
void  GetACpuCacheInfo(ACPU_CACHE_INFO  *CacheInfo);

/* */
EFI_STATUS GetCpuPState (ACPU_PSTATE_TABLE *Header);

/* */
UINT16 GetCPUBaseClock();

UINT8 GetCpuBrand(BOOLEAN IsC5r);

UINT8 GetACpuCoresAdapter();

EFI_STATUS GetCpuPStateAdapter (IN ACPU_PSTATE_TABLE *Header);

UINT8 GetCpuClusters();

#endif
