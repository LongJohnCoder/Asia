//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include <tiano.h>
#include "EfiScriptLib.h"
#include "EfiDriverLib.h"
#include EFI_PROTOCOL_DEFINITION(AsiaCpuProtocol)

#include EFI_GUID_DEFINITION(Hob)
#include "EfiHobLib.h"

#include "AsiaCpuDxe.h"

static EFI_GUID mAsiaCpuProtocolGuid = EFI_ASIA_CPU_PROTOCOL_GUID;
static ASIA_CPU_CONFIGURATION * mCpuConfig = NULL;


static EFI_ASIA_CPU_PROTOCOL gAsiaCpuProtocol = {
    MicrocodeCheckAndTriger,
    CpuFeatureInitialize,
    TscDelay,
    GetACpuMicrocodeRevision,
    GetACpuSupportFeature,
    GetACpuVersionInfo,
    GetACpuCacheInfo,
    GetACpuBrandString,
    GetACpuSpeedInfo,
    GetACpuCoresAdapter,
    GetACpuHts,
    GetCpuPStateAdapter,
    GetCpuClusters
};

EFI_STATUS
GetCpuPStateAdapter (IN ACPU_PSTATE_TABLE *Header) {
    return GetCpuPState(Header);
}

UINT8 GetACpuCoresAdapter()
{
    // if the actual number is not 0
    // return the actual number
    // Change ADDON_FEATURE hob to ASIA_CPU_CONFIGURATION hob
    if (mCpuConfig != NULL) {
      if (mCpuConfig->ActiveCpuNum != 0) {
        return mCpuConfig->ActiveCpuNum;
      }
    }

    return GetACpuCores();
}

EFI_STATUS GetAsiaModuleCfgFromHob(
    OUT VOID** CpuCfg
)
{
    EFI_STATUS Status;
    EFI_HOB_GENERIC_HEADER *HobList;
    EFI_GUID EfiHobListGuid = EFI_HOB_LIST_GUID;
    EFI_GUID CpuCfgHobGuid = ASIA_CPU_CFG_HOB_GUID;
    VOID* pCpuCfg = NULL;

    Status = EfiLibGetSystemConfigurationTable(&EfiHobListGuid, &HobList);
    if (!EFI_ERROR(Status))
        Status = GetNextGuidHob(&HobList, &CpuCfgHobGuid, &pCpuCfg, NULL);

    ASSERT_EFI_ERROR(Status);

    *CpuCfg = pCpuCfg;
    return EFI_SUCCESS;
}

EFI_DRIVER_ENTRY_POINT (AsiaCpuDxeEntry)

EFI_STATUS
EFIAPI
AsiaCpuDxeEntry(
    IN EFI_HANDLE         ImageHandle,
    IN EFI_SYSTEM_TABLE   *SystemTable
)
{
    EFI_STATUS Status;
    EFI_HANDLE Handle = NULL;
    DxeInitializeDriverLib(ImageHandle, SystemTable);
    INITIALIZE_SCRIPT(ImageHandle, SystemTable);

	DEBUG((EFI_D_ERROR, "%a(%d) AsiaCPUDxe Entrypoint ++++++ +++++\n",__FILE__,__LINE__));

    GetAsiaModuleCfgFromHob(&mCpuConfig);
    
    Status = gBS->InstallProtocolInterface (
                 &Handle,
                 &mAsiaCpuProtocolGuid,
                 EFI_NATIVE_INTERFACE,
                 &gAsiaCpuProtocol
             );

    return Status;

}
