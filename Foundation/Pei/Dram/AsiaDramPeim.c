//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "Pei.h"
//#include "PeiDebug.h"

#include "AsiaDramPeim.h"
#include "PPI\AsiaDramPpi\AsiaDramPpi.h"
#include "AsiaCommon.h" //define ASIA_DRAM_ATTR_HOB_GUID
#include "Peilib.h" //compareguid function  
#include EFI_PPI_DEFINITION (MemoryDiscovered)//

static EFI_GUID mAsiaDramPpiGuid = EFI_ASIA_DRAM_PPI_GUID;

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
	EFI_GUID AsiaDramAttrGuid = ASIA_DRAM_ATTR_HOB_GUID;
	VOID * DramAttr=NULL;
	EFI_ASIA_DRAM_PPI *AsiaDramPpi;
    
	ASIA_DRAM_PEI_PRIVATE_DATA *pPrvData = NULL;

	Status = (*PeiServices)->GetHobList (PeiServices, &Hob.Raw);
	while (!END_OF_HOB_LIST (Hob)) 
	{
    	if (Hob.Header->HobType == EFI_HOB_TYPE_GUID_EXTENSION && CompareGuid (&Hob.Guid->Name, &AsiaDramAttrGuid)) 
    	{
        DramAttr = (VOID *) (Hob.Raw + sizeof (EFI_HOB_GENERIC_HEADER) + sizeof (EFI_GUID));
        break;
    	}

	    Hob.Raw = GET_NEXT_HOB (Hob);
	}
  ASSERT_PEI_ERROR(PeiServices, (NULL == DramAttr));
	Status = (**PeiServices).LocatePpi (
                         PeiServices,
                         &mAsiaDramPpiGuid,
                         0,
                         NULL,
                         &AsiaDramPpi
                         );
	ASSERT_PEI_ERROR (PeiServices, Status);
    
    pPrvData = GET_PRIVATE_DATA_FROM_THIS(AsiaDramPpi);
    PEI_DEBUG((PeiServices, EFI_D_INFO,"old DramAttr=%x new DramAttr=%x \r",pPrvData->DramAttr, DramAttr));
	pPrvData->DramAttr=DramAttr;
	return Status;

}


static EFI_PEI_NOTIFY_DESCRIPTOR      mNotifyList[] = {
  {
    (EFI_PEI_PPI_DESCRIPTOR_NOTIFY_CALLBACK | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
    &gPeiMemoryDiscoveredPpiGuid,
    ConvertCfgStructPointer
  }
};

EFI_STATUS AsiaDramPeimEntryPoint (
    IN EFI_FFS_FILE_HEADER		  *FfsHeader,
    IN struct _EFI_PEI_SERVICES	**PeiServices
)
{
    EFI_STATUS Status;
    ASIA_DRAM_PEI_PRIVATE_DATA *pPrvData = NULL;

    PEI_DEBUG((PeiServices, EFI_D_INFO,"AsiaDramPPI install EntryPoint().\n"));
	
    /*prepare PPI structure*/
    Status = (*PeiServices)->AllocatePool(
                 PeiServices,
                 sizeof (ASIA_DRAM_PEI_PRIVATE_DATA),
                 &pPrvData
             );
    if (EFI_SUCCESS != Status)
        return Status;

    pPrvData->Signature = ASIA_DRAM_PEI_PRIVATE_DATA_SIGNATURE;
    /*init private parameter
    porting part should provide the init function*/
    InitDramPrivateData(PeiServices,pPrvData);

    /*init PPI descriptor*/
    pPrvData->PpiDesc.Flags = EFI_PEI_PPI_DESCRIPTOR_PPI |EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST;
    pPrvData->PpiDesc.Guid = &mAsiaDramPpiGuid;
    pPrvData->PpiDesc.Ppi = &(pPrvData->AsiaDramPpi);
    /*init PPI*/
    pPrvData->AsiaDramPpi.DramNormalInit = DramNormalInit;
    pPrvData->AsiaDramPpi.DramS3Init = DramS3Init;
    pPrvData->AsiaDramPpi.DramGetInfo = DramGetInfo;
    /* Install PPI*/
    Status = (*PeiServices)->InstallPpi (PeiServices, &(pPrvData->PpiDesc));
    ASSERT_PEI_ERROR (PeiServices, Status);
    
    /*Kelvin find a big error, after memory installed, the config structre pointer
    need convert to new position*/
    Status = (**PeiServices).NotifyPpi (PeiServices, &mNotifyList[0]);
    ASSERT_PEI_ERROR (PeiServices, Status);

    return Status;
}
