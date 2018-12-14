//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "Ppi\AsiaNbPpi\AsiaNbPpi.h"
#include "AsiaNbPeim.h"
#include "Peilib.h" 
#include EFI_PPI_DEFINITION (MemoryDiscovered)
#include "AsiaCommon.h" 


EFI_GUID gAsiaNbLibPpiGuid = EFI_ASIA_NB_LIB_PPI_GUID; /*define in AsiaNbPeim.h"*/
static EFI_GUID mAsiaNbPpiGuid = EFI_ASIA_NB_PPI_GUID;
/* using callback function to convert config struct pointer after memory discovered*/
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
	EFI_GUID AsiaNbCfgGuid = ASIA_NB_CFG_HOB_GUID;
	VOID * NbConfig=NULL;
	EFI_ASIA_NB_PPI *AsiaNbPpi;
	Status = (*PeiServices)->GetHobList (PeiServices, &Hob.Raw);
	while (!END_OF_HOB_LIST (Hob)) 
	{
    	if (Hob.Header->HobType == EFI_HOB_TYPE_GUID_EXTENSION && CompareGuid (&Hob.Guid->Name, &AsiaNbCfgGuid)) 
    	{
        	NbConfig = (VOID *) (Hob.Raw + sizeof (EFI_HOB_GENERIC_HEADER) + sizeof (EFI_GUID));
            break;
    	}

	    Hob.Raw = GET_NEXT_HOB (Hob);
	}
    PEI_DEBUG((PeiServices, EFI_D_INFO, "after memory  NbConfig=%x.\n",NbConfig));
    ASSERT_PEI_ERROR(PeiServices, (NULL == NbConfig));
    if(NULL!= NbConfig)
	{
		Status = (**PeiServices).LocatePpi (
                             PeiServices,
                             &mAsiaNbPpiGuid,
                             0,
                             NULL,
                             &AsiaNbPpi
                             );
  		ASSERT_PEI_ERROR (PeiServices, Status);
		AsiaNbPpi->NbCfg = NbConfig;
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

EFI_STATUS EFIAPI
AsiaNbPeimEntryPoint (
    IN EFI_FFS_FILE_HEADER *FfsHeader,
    IN EFI_PEI_SERVICES **PeiServices
)
{
    EFI_STATUS Status;
    ASIA_NB_PEI_PRIVATE_DATA  *pPrvData = NULL;
    // In entry point of a ASIA peim, only install ppi
    PEI_DEBUG((PeiServices, EFI_D_INFO, "-----------------AsiaNbPei: Install PPIs.\n"));
    /*prepare PPI structure*/
    Status = (*PeiServices)->AllocatePool(
                 PeiServices,
                 sizeof ( ASIA_NB_PEI_PRIVATE_DATA ),
                 &pPrvData
             );
    if (EFI_SUCCESS != Status)
        return Status;

    pPrvData->Signature =  ASIA_NB_PEI_PRIVATE_DATA_SIGNATURE;

    /*init PPI descriptor*/
    pPrvData->PpiDesc[0].Flags = EFI_PEI_PPI_DESCRIPTOR_PPI;
    pPrvData->PpiDesc[0].Guid = &gAsiaNbLibPpiGuid;
    pPrvData->PpiDesc[0].Ppi = NULL; //this value will be init in InitNbPrivateData

    pPrvData->PpiDesc[1].Flags = EFI_PEI_PPI_DESCRIPTOR_PPI |EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST;
    pPrvData->PpiDesc[1].Guid = &mAsiaNbPpiGuid;
    pPrvData->PpiDesc[1].Ppi = &(pPrvData->AsiaNbPpi);

    /*init private parameter*/
    //porting part should provide the init function*/
    InitNbPrivateData(PeiServices, pPrvData);
    //must init NbCfg structre and provide default value.
	ASSERT_PEI_ERROR(PeiServices, (NULL == pPrvData->AsiaNbPpi.NbCfg));

    /*init PPI*/
    pPrvData->AsiaNbPpi.PreMemoryInit = PeiNbPreMemoryInit;
    pPrvData->AsiaNbPpi.PostMemoryInit = PeiNbPostMemoryInit;
    pPrvData->AsiaNbPpi.PostMemoryInitS3 = PeiNbPostMemoryInitS3;

    Status = (*PeiServices)->InstallPpi(PeiServices, &(pPrvData->PpiDesc[0]));
    ASSERT_PEI_ERROR(PeiServices, Status);

    /*Kelvin find a big error, after memory installed, the config structre pointer
    need convert to new position*/
    Status = (**PeiServices).NotifyPpi (PeiServices, &mNotifyList[0]);
    ASSERT_PEI_ERROR (PeiServices, Status);
    
//test, call the interface directly
//    {
//        EFI_ASIA_NB_PPI *AsiaNbPpi;
//        Status = (*PeiServices)->LocatePpi(PeiServices, &gAsiaNbPpiGuid, 0, NULL, &AsiaNbPpi);
//
//        PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d)---Locate AsiaNbPpi Status = %x .\n", __FILE__,__LINE__,Status));
//
//        if (EFI_SUCCESS == Status)
//        {
//            AsiaNbPpi->PreMemoryInit(PeiServices,AsiaNbPpi);
//            PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d)---AsiaNbPei call the interface directly .\n", __FILE__,__LINE__));
//        }
//    }
    return Status;
}
