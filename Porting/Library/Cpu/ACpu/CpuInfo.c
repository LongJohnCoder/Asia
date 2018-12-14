//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************

#include "Tiano.h"
#include "EfiCommonLib.h"
#include "CpuIA32.h"
#include "CState.h"
#include "EpsInit.h"
#include "ExecuteDisable.h"
#include "FastString.h"
#include "Ferr.h"
#include "MachineCheck.h"
#include "MicrocodeUpdate.h"
#include "MonitorMWait.h"
#include "Prefetcher.h"
#include "Prochot.h"
#include "ThermalMonitor.h"
#include "TPREcho.h"
#include "Vt.h"
#include "pmon.h"
#include <Ppi\AsiaCpuPpi\AsiaCpuPpi.h>

extern UINT16 GetCPUBaseClock();


UINT8 GetACpuFamily()
{
	return 0x01; //Always return 0x01 (Other)
}


/*===================================================================
Function   : GetACpuVersionInfo()
Precondition :
Input      :
              VersionInfo: pointer to ACPU_VERSION_INFO
Output     :
Purpose    : get processor's version infomation
Reference  : None
note:
===================================================================*/

void GetACpuVersionInfo(ACPU_VERSION_INFO * VersionInfo)
{
    EFI_CPUID_REGISTER CpuidInfo;

    //get cpuid version info
    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
    VersionInfo->Signature = CpuidInfo.RegEax;
    VersionInfo->MiscInfo = CpuidInfo.RegEbx;
    VersionInfo->FeatureEcx = CpuidInfo.RegEcx;
    VersionInfo->FeatureEdx = CpuidInfo.RegEdx;
    VersionInfo->Family= GetACpuFamily();

    //get cpuid extend feature info
    EfiCpuid(EFI_CPUID_EXTENDED_CPU_SIG, &CpuidInfo);
    VersionInfo->ExtFeatureEdx = CpuidInfo.RegEdx;

    return;
}

/*===================================================================
Function   : GetACPUBrandString()
Precondition :
Input      : void
Output     :
                String: pointer to brand string
Purpose    : get processor's brand string
Reference  : None
note:
===================================================================*/

VOID GetACpuBrandString(CHAR8 *String)
{
    EFI_CPUID_REGISTER    CpuidInfo;
    CHAR8     *BrandString;

    //judge if cpu support brand string
    EfiCpuid(EFI_CPUID_EXTENDED_FUNCTION, &CpuidInfo);

    //processor not support brand string
    if (CpuidInfo.RegEax < EFI_CPUID_BRAND_STRING3)
    {
        *String = '\0';
        return;
    }

    BrandString = String;

    EfiCpuid(EFI_CPUID_BRAND_STRING1, &CpuidInfo);
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEax;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEbx;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEcx;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEdx;
    BrandString += 4;
    EfiCpuid(EFI_CPUID_BRAND_STRING2, &CpuidInfo);
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEax;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEbx;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEcx;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEdx;
    BrandString += 4;
    EfiCpuid(EFI_CPUID_BRAND_STRING3, &CpuidInfo);
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEax;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEbx;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEcx;
    BrandString += 4;
    *(UINT32*)(UINTN)BrandString = CpuidInfo.RegEdx;
    BrandString += 4;

    *BrandString = '\0';

    //Remove leading spaces.
    BrandString = String;	
    while (*String == ' ')String++;
    while (*String != '\0'){
	*BrandString = *String;
	String++;
	BrandString++;
    }
    *BrandString = '\0';

    return;
}


UINT8 GetACpuCores()
{

    EFI_CPUID_REGISTER    CpuidInfo;
    UINT32 Temp;
    
    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
    
    Temp = CpuidInfo.RegEbx;

    return (UINT8)((Temp>>16) & 0xff);
    
}

UINT8 GetCpuClusters()
{
    
    UINT8 Temp;

	Temp = (UINT8)EfiReadMsr(0x1610);
    Temp = (Temp >> 0x6) & 3;
	if(Temp == 3)
		return 2;
    
    return 1;
}

UINT8 GetACpuHts()
{
    return 1;
}


/*===================================================================
Function   : GetCpuVoltage()
Precondition :
Input      : void
Output     :
Purpose    : get processor's core voltage
Reference  : None
note:           unit in MV
===================================================================*/

UINT32  GetCpuVoltage()
{
    UINT8     CurrentFid;
    UINT64   MsrVal;
    UINT32   Voltage;

    MsrVal = EfiReadMsr(0x198);
    CurrentFid = (UINT8)((RShiftU64(MsrVal, 32))& 0xFF);

	if (CurrentFid < 7) {
		CurrentFid = 0;
	}
	else {
		CurrentFid -= 7;
	}
	Voltage = CurrentFid * 125;

    return Voltage;
}

/*===================================================================
Function   : GetACpuSpeedInfo()
Precondition :
Input      :
               SpeedInfo: pointer to ACPU_SPEED_INFO
Output     :
Purpose    : get processor's bus ratio
Reference  : None
note:        because ACPU real Bus ratio is half of reported ratio from MSR198
             if the reported ratio is odd, the real bus ratio is fraction,
             this can not be demonstrated in EFI.So double the bus ratio in
             SpeedInfo struct.
===================================================================*/

void  GetACpuSpeedInfo(ACPU_SPEED_INFO  *SpeedInfo)
{
    UINT64  MsrVal;


    MsrVal = EfiReadMsr(0x198);

    SpeedInfo->MaxVID = (UINT8)(RShiftU64(MsrVal, 32) & 0xFF);
    SpeedInfo->MaxBusRatio = (UINT8)(RShiftU64(MsrVal, 40) & 0xFF);
    SpeedInfo->MinVID = (UINT8)(RShiftU64(MsrVal, 48) & 0xFF);
    SpeedInfo->MinBusRatio = (UINT8)(RShiftU64(MsrVal, 56) & 0xFF);
    SpeedInfo->CurrentBusRatio = (UINT8)(RShiftU64(MsrVal, 8) & 0xFF);
	
    SpeedInfo->CPUBusSpeed = GetCPUBaseClock();
    SpeedInfo->Voltage = GetCpuVoltage();

    return;
}

/*===================================================================
Function   : GetACpuMicrocodeRevision()
Precondition :
Input      : void
Output     :
Purpose    : get processor's latest microcode update revision
Reference  : None
note:
===================================================================*/
UINT32 GetACpuMicrocodeRevision()
{
    UINT64    MsrVal;
    EFI_CPUID_REGISTER  CpuidInfo;

    //execute a CpuID instruction sub-function of 1, and then  read
    //IA32_BIOS_SIGN_ID(MSR 0x8B).The high 32-bits of the MSR will
    //be the update's ID value
    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
    MsrVal = EfiReadMsr(EFI_MSR_IA32_BIOS_SIGN_ID);

        MsrVal = RShiftU64(MsrVal, 32);
        return (UINT32)MsrVal;

}

/*===================================================================
Function   : GetACpuCacheInfo()
Precondition :
Input      :
                CacheInfo: pointer to the array of ACPU_CACHE_INFO
Output     :
Purpose    : collect processor's cache information
Reference  : None
note:
===================================================================*/

void  GetACpuCacheInfo(ACPU_CACHE_INFO  *CacheInfo)
{
    EFI_CPUID_REGISTER     CpuidInfo;

    //get L1 cache info
    EfiCpuid(0x80000005, &CpuidInfo);
    //L1 Data cache
    //Cpuid. ECX
    //register format
    //bit 7:0 Line Size(Bytes)
    //bit15:8 Lines per Tag
    //bit23:16  Data Cache associativity
    //bit 31:24  Data Cache Size(KBytes)
    CacheInfo[0].Level = ACPU_CACHE_LEVEL_L1;
    CacheInfo[0].Type = ACPU_CACHE_TYPE_DATA;
    CacheInfo[0].LineSize = (UINT8)(CpuidInfo.RegEcx & 0xFF);
    CacheInfo[0].Associativity = (UINT8)((CpuidInfo.RegEcx >> 16) & 0xFF);
    CacheInfo[0].CacheSize = (UINT16)((CpuidInfo.RegEcx >> 24) & 0xFF);

    //L1 instruction cache
    //Cpuid.EDX
    CacheInfo[1].Level = ACPU_CACHE_LEVEL_L1;
    CacheInfo[1].Type = ACPU_CACHE_TYPE_CODE;
    CacheInfo[1].LineSize = (UINT8)(CpuidInfo.RegEdx & 0xFF);
    CacheInfo[1].Associativity = (UINT8)((CpuidInfo.RegEdx >> 16) & 0xFF);
    CacheInfo[1].CacheSize = (UINT16)((CpuidInfo.RegEdx >> 24) & 0xFF);

    // get L2 cache info
    EfiCpuid(0x80000006, &CpuidInfo);
    //L2 unified cache
    //cpuid. ECX
    //register format
    //bit 7:0: cache line size
    //bit  15:12: cache associativity
    //bit  31:16: cache size(KBytes)
    CacheInfo[2].Level = ACPU_CACHE_LEVEL_L2;
    CacheInfo[2].Type = ACPU_CACHE_TYPE_UNIFIED;
    CacheInfo[2].LineSize = (UINT8)(CpuidInfo.RegEcx & 0xFF);
    CacheInfo[2].CacheSize = (UINT16)((CpuidInfo.RegEcx >> 16) & 0xFFFF);
    switch ((CpuidInfo.RegEcx >> 12) & 0x0F)
    {
    case 1:
        //direct map
        CacheInfo[2].Associativity = 1;
        break;
    case 2:
        CacheInfo[2].Associativity = 2;
        break;
    case 4:
        CacheInfo[2].Associativity = 4;
        break;
    case 6:
        CacheInfo[2].Associativity = 8;
        break;
    case 8:
        CacheInfo[2].Associativity = 16;
        break;
    case 10:
        CacheInfo[2].Associativity = 32;
        break;
    default:
        CacheInfo[2].Associativity = 0;
    }
    return;
}

/*===================================================================
Function   : GetACpuSupportFeature()
Precondition :
Input      :
                SupportFeature: pointer to ASIA_CPU_CONFIGURATION;
Output     :
Purpose    : get processor's information
Reference  : None
note:
===================================================================*/

void  GetACpuSupportFeature(
    IN OUT ASIA_CPU_CONFIGURATION   *SupportFeature
)
{
    EFI_CPUID_REGISTER    CpuidInfo;

    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
    
    SupportFeature->FastString = TRUE;
    SupportFeature->NAPSNAPEnalbe = FALSE;
    SupportFeature->EpsEnable = IsEpsSupport();
    SupportFeature->FerrInterruptReporting = IsFerrSupport();

#if ZX_SECRET_CODE
    // secret-code +S
    SupportFeature->KillAp = 0;
    // secret-code +E
#endif


    SupportFeature->Msr3AEnable = TRUE;
    SupportFeature->ProcessorCxeEnable = TRUE;
    //SupportFeature->PmonEnable = FALSE;
    SupportFeature->VrmSupport = 0;

    SupportFeature->LimitCpuidMaximumValue = FALSE;
	
    SupportFeature->ExecuteDisableBit = IsExecuteDisableSupport();
    SupportFeature->MachineCheckEnable = IsMceSupport();
    SupportFeature->MonitorMWaitEnable = IsMonitorMWaitSupport();
    SupportFeature->TPREchoEnable = IsTPREchoSupport();
    SupportFeature->VtEnable = IsVtSupport();
    
    // the default value origined in CPU dxe driver
    SupportFeature->BootWithMaxFrequence = TRUE;

}
