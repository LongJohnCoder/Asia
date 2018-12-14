//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include EFI_PPI_DEFINITION(AsiaSbPpi)
#include "AsiaSbPeim.h"
#include "Peilib.h" //compareguid function
#include EFI_PPI_DEFINITION (MemoryDiscovered)
#include "AsiaCommon.h" //define ASIA_DRAM_ATTR_HOB_GUID

EFI_GUID gAsiaSbLibPpiGuid = EFI_ASIA_SB_LIB_PPI_GUID;
static EFI_GUID mAsiaSbPpiGuid = EFI_ASIA_SB_PPI_GUID;

/*using callback function to convert config struct pointer after memory discovered*/
EFI_STATUS
EFIAPI
ConvertCfgStructPointer (
  IN EFI_PEI_SERVICES           **PeiServices,
  IN EFI_PEI_NOTIFY_DESCRIPTOR  *NotifyDescriptor,
  IN VOID                       *Ppi
  )
{
	/*find the config structure hob*/
	EFI_STATUS Status;
	EFI_PEI_HOB_POINTERS Hob;
	EFI_GUID AsiaSbCfgGuid = ASIA_SB_CFG_HOB_GUID;
	VOID * SbConfig=NULL;
	EFI_ASIA_SB_PPI *AsiaSbPpi;
	Status = (*PeiServices)->GetHobList (PeiServices, &Hob.Raw);
	while (!END_OF_HOB_LIST (Hob)) 
	{
    	if (Hob.Header->HobType == EFI_HOB_TYPE_GUID_EXTENSION && CompareGuid (&Hob.Guid->Name, &AsiaSbCfgGuid)) 
    	{
        SbConfig = (VOID *) (Hob.Raw + sizeof (EFI_HOB_GENERIC_HEADER) + sizeof (EFI_GUID));
        break;
    	}

	    Hob.Raw = GET_NEXT_HOB (Hob);
	}
    PEI_DEBUG((PeiServices, EFI_D_INFO, "after memory SbConfig=%x.\n",SbConfig));
    ASSERT_PEI_ERROR(PeiServices, (NULL == SbConfig));
    if(NULL!= SbConfig)
	{
		Status = (**PeiServices).LocatePpi (
                             PeiServices,
                             &mAsiaSbPpiGuid,
                             0,
                             NULL,
                             &AsiaSbPpi
                             );
    ASSERT_PEI_ERROR (PeiServices, Status);
		AsiaSbPpi->SbCfg = SbConfig;
	}
	return Status;

}


static EFI_PEI_NOTIFY_DESCRIPTOR      mNotifyList[] = {
  {
    (EFI_PEI_PPI_DESCRIPTOR_NOTIFY_CALLBACK | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
    &gPeiMemoryDiscoveredPpiGuid,
    ConvertCfgStructPointer
  }
};

EFI_STATUS 
EFIAPI
AsiaSbPeimEntryPoint (
    IN EFI_FFS_FILE_HEADER *FfsHeader,
    IN EFI_PEI_SERVICES **PeiServices
)
{
    EFI_STATUS Status;
    ASIA_SB_PEI_PRIVATE_DATA *pPrvData = NULL;

    // In entry point of a ASIA peim, only install ppi
    PEI_DEBUG((PeiServices, EFI_D_INFO, "------------------AsiaSbPei: Install PPIs.\n"));
    /*prepare PPI structure*/
    Status = (*PeiServices)->AllocatePool(
                 PeiServices,
                 sizeof (ASIA_SB_PEI_PRIVATE_DATA),
                 &pPrvData
             );
    if (EFI_SUCCESS != Status)
        return Status;

    pPrvData->Signature = ASIA_SB_PEI_PRIVATE_DATA_SIGNATURE;
    /*init PPI descriptor*/
    pPrvData->PpiDesc[0].Flags = EFI_PEI_PPI_DESCRIPTOR_PPI;
	pPrvData->PpiDesc[0].Guid = &gAsiaSbLibPpiGuid;
    pPrvData->PpiDesc[0].Ppi = NULL; //init by InitSbPrivateData function

    pPrvData->PpiDesc[1].Flags = EFI_PEI_PPI_DESCRIPTOR_PPI |EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST;
    pPrvData->PpiDesc[1].Guid = &mAsiaSbPpiGuid;
    pPrvData->PpiDesc[1].Ppi = &(pPrvData->AsiaSbPpi);
    /*init private parameter*/
    //porting part should provide the init function*/
    InitSbPrivateData(PeiServices, pPrvData);

    /*init PPI*/
	pPrvData->AsiaSbPpi.PreMemoryInit = PeiSbPreMemoryInit;
	pPrvData->AsiaSbPpi.PostMemoryInit = PeiSbPostMemoryInit;
	pPrvData->AsiaSbPpi.PostMemoryInitS3 = PeiSbPostMemoryInitS3;

    Status = (*PeiServices)->InstallPpi(PeiServices, &(pPrvData->PpiDesc[0]));
    ASSERT_PEI_ERROR(PeiServices, Status);

    
    /*Kelvin find a big error, after memory installed, the config structre pointer
    need convert to new position*/
    Status = (**PeiServices).NotifyPpi (PeiServices, &mNotifyList[0]);
    ASSERT_PEI_ERROR (PeiServices, Status);

    return Status;
}
