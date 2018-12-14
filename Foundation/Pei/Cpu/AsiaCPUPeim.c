//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include <Tiano.h>
#include <Pei.h>
#include <PeiLib.h>
#include "AsiaCpuPpiInterface.h" /*Cpu feature init*/

#define ASIA_CPU_PEIM_SIGNATURE  EFI_SIGNATURE_32 ('A', 'S', 'I', 'A')

EFI_GUID gAsiaCpuPpiGuid = EFI_ASIA_CPU_PPI_PROTOCOL_GUID;

EFI_ASIA_CPU_PPI_PROTOCOL   gPeiAsiaCpuPpi =
{
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
    GetCpuPState,
    GetCpuClusters
};

static EFI_PEI_PPI_DESCRIPTOR       gAsiaCpuPpiDesc=
{
    (EFI_PEI_PPI_DESCRIPTOR_PPI |EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
    &gAsiaCpuPpiGuid,
    &gPeiAsiaCpuPpi
};

UINT8 GetACpuCoresAdapter()
{
    // we can't locate the PeiServices, 
    // so, we can't reload the function
    return GetACpuCores();
}

// Change ADDON_FEATURE hob to ASIA_CPU_CONFIGURATION hob
EFI_STATUS CreateAsiaCpuCfgStructHob (
    IN EFI_PEI_SERVICES **PeiServices,
    OUT VOID **Buffer
)
{
    EFI_STATUS Status;
    VOID* pCpuCfgHob;
    EFI_PEI_HOB_POINTERS CpuCfgHobPtr;
    EFI_GUID AsiaCpuCfgStructGuid = ASIA_CPU_CFG_HOB_GUID;
    ASIA_CPU_CONFIGURATION* pAsiaCpuCfgStruct;
    
    // Create Hob for NbCfg, link the buffer in the Hob to NbPpi.
    Status = (*PeiServices)->CreateHob(
                 PeiServices,
                 EFI_HOB_TYPE_GUID_EXTENSION,
                 sizeof(EFI_HOB_GUID_TYPE) + sizeof(ASIA_CPU_CONFIGURATION),
                 &pCpuCfgHob
             );
    if (EFI_ERROR(Status))
        return Status;

    CpuCfgHobPtr.Raw = pCpuCfgHob;
    CpuCfgHobPtr.Guid->Name = AsiaCpuCfgStructGuid; // Use ASIA_CPU_CFG_HOB_GUID
    // Output content pointer of the hob
    *Buffer = (VOID*)((UINT8*)(&(CpuCfgHobPtr.Guid->Name)) + sizeof(EFI_GUID));
    pAsiaCpuCfgStruct = (ASIA_CPU_CONFIGURATION*)(*Buffer);

    // Initialize AsiaCpuCfg to all 0
    (*PeiServices)->SetMem(*Buffer, sizeof(ASIA_CPU_CONFIGURATION), 0);

    return EFI_SUCCESS;
}


EFI_PEIM_ENTRY_POINT (AsiaCpuPeimEntry)

EFI_STATUS
AsiaCpuPeimEntry (
    IN EFI_FFS_FILE_HEADER       *FfsHeader,
    IN EFI_PEI_SERVICES          **PeiServices
)
{
    EFI_STATUS  Status;
    VOID *pCpuCfgStructHob;

    /*install ppi*/
    Status = (*PeiServices)->InstallPpi (PeiServices, &gAsiaCpuPpiDesc);
    ASSERT_PEI_ERROR (PeiServices, Status);

    Status = CreateAsiaCpuCfgStructHob(PeiServices, &pCpuCfgStructHob);        
	  ASSERT_PEI_ERROR (PeiServices, Status);
        
    return Status;
}
