//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

///
///
#include "Pei.h"
#include "PeiDebug.h"
#include EFI_PPI_CONSUMER(Smbus)
#include EFI_PPI_CONSUMER(CpuIo)
#include EFI_PPI_CONSUMER(PciCfg)
#include EFI_PPI_CONSUMER(AsiaNbPpi)
#include "DramInit.h"
#include "DramUtil.h"
#include "UmaSet.h"
#include "AsiaCommon.h" 
#include "debug/DramDebug.h"
#include "AsiaInitCfgStructDefval.h"

#include "CalculateRCBANum.h"
#include "DRAMFreqProgramming.h"
#include "DramInfo.h"
#include "DRAMInitTable.h"
#include "DramS3Init.h"
#include "DramSetupECC.h"
#include "DRAMTimingProgramming.h"
#include "FinalTableProgramming.h"
#include "GetBasicInformation.h"
#include "InitDRAMByRank.h"
#include "IOTimingControl.h"
#include "NBODTLookUpProgramming.h"
#include "SetDramFeature.h"
#include "SetRefreshCounter.h"
#include "SIValueProgramming.h"
#include "UmaSet.h"
#include "UpdateRankAddr.h"
#include "VrefCalibration.h"
#include "DramBlock.h"


//ASIA_DRAM_CONFIGURATION      mDramSetupData = ASIA_DRAM_DEFAULT_CONFIGURATION;

extern BOOLEAN VT_DramBaseTest(IN struct _EFI_PEI_SERVICES **PeiServices,
                     IN UINT32                        BaseAdd, 
                     IN UINT32                        Length,
                     IN UINT32		Pattern
);


extern VOID EnCache(IN EFI_PEI_SERVICES **PeiServices);
extern VOID DisCache(IN EFI_PEI_SERVICES **PeiServices);



/*wjb20110608 using createhob to allocate memory, after install memory we can find DramAttr struct*/
EFI_STATUS CreateAsiaDramAttrHob (
	IN EFI_PEI_SERVICES **PeiServices,
	OUT VOID **Buffer
)
{
	EFI_STATUS Status;
	VOID* pDramAttrHob;
	EFI_PEI_HOB_POINTERS DramAttrHobPtr;
	EFI_GUID AsiaDramAttrGuid = ASIA_DRAM_ATTR_HOB_GUID;
	DRAM_ATTRIBUTE * pDramAttr;
	// Create Hob for DramAttr.
	Status = (*PeiServices)->CreateHob(
		PeiServices,
		EFI_HOB_TYPE_GUID_EXTENSION,
		sizeof(EFI_HOB_GUID_TYPE) + sizeof(DRAM_ATTRIBUTE),
		&pDramAttrHob
		);
	if(EFI_ERROR(Status))
		return Status;

	DramAttrHobPtr.Raw = pDramAttrHob;
	DramAttrHobPtr.Guid->Name = AsiaDramAttrGuid; // Use ASIA_NB_CFG_HOB_GUID
	// Output content pointer of the hob
	*Buffer = (VOID*)((UINT8*)(&(DramAttrHobPtr.Guid->Name)) + sizeof(EFI_GUID));
	pDramAttr = (DRAM_ATTRIBUTE*)(*Buffer);

	// Initialize NbCfg to all 0
	(*PeiServices)->SetMem(*Buffer, sizeof(DRAM_ATTRIBUTE), 0);

	return EFI_SUCCESS;
}

////
VOID DumpDramCfgStructDefaultValue(
       IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_DRAM_CONFIGURATION* pDramCfg)
{
	//// Dump ASIA DRAM Cfg struct's default value
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n\n Begin to dump Asia Dram Cfg Struct default value \n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"************************ \n"));
	//pDramCfg->Signature=ASIA_DRAM_CONFIGURATION_SIGNATURE;
	//pDramCfg->DramClk=DRAM_CLK_BY_SPD;
	//pDramCfg->ACTimingOption=ACTIMING_AUTO;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->DramCL = %x \n",pDramCfg->DramCL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->DramTrcd = %x \n",pDramCfg->DramTrcd));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->DramTrp = %x \n",pDramCfg->DramTrp));
	//pDramCfg->DramTras=TRAS_AUTO;
	//pDramCfg->RxIoTimingMethod=RX_SI_SI;
	//pDramCfg->DQSIByRank=BYRANK_ENABLE;
	//pDramCfg->TxIoTimingMethod=TX_SI_SI;
	//pDramCfg->LimitRankSize=LIMIT_SIZE_AUTO;
	//pDramCfg->BankIntlv=BANK_INTERLEAVE_NONPAGE;
	//pDramCfg->MemoryChipODTDebug=MEM_CHIP_ODT_DBG_AUTO;
	//pDramCfg->MemoryChipODTWRDebug=MEM_CHIP_ODT_DBG_AUTO;
	//pDramCfg->MemoryChipODTParkDebug=MEM_CHIP_ODT_DBG_AUTO;
	//pDramCfg->VRIntlv=VRANK_INTERLEAVE_DISABLED;
	//pDramCfg->ChannelIntlv=CHAN_INTERLEAVE_DISABLED;
	//pDramCfg->BASelect=SELECT_A16;
	//pDramCfg->DataScmb=FALSE;
	//pDramCfg->RDRDY=RDRDY_DEFAULT;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->ConversionCircuit = %x \n",pDramCfg->ConversionCircuit));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->BurstLength = %x \n",pDramCfg->BurstLength));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->CmdRate = %x \n",pDramCfg->CmdRate));	
	//pDramCfg->VGAShareMemory=VGA_SHARE_MEM_256M;
	//pDramCfg->DramInitMethod=DRAM_INIT_METHOD_AUTO;
	//pDramCfg->DramSelfRefresh=TRUE;
	//pDramCfg->DynamicCKE=TRUE;
	//pDramCfg->RemapEn=TRUE;
	//pDramCfg->PCIMemoryStart=0x800;
	//pDramCfg->ScanIOTiming=FALSE;
	//pDramCfg->DRAMECC=FALSE;
	//pDramCfg->ECCClearMemory=FALSE;
	//pDramCfg->EccPatrolScrub=FALSE;
	//pDramCfg->EccRetry=FALSE;
	//pDramCfg->DRAMErrControl=ECC_DISABLE;
	//pDramCfg->CRCEn=FALSE;
	//pDramCfg->CRCErrControl=CRC_DISABLE;
	//pDramCfg->CAParEn=FALSE;
	//pDramCfg->CAParPerEn=FALSE;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->ParErrControl = %x \n",pDramCfg->ParErrControl));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->CRCParRetryEn = %x \n",pDramCfg->CRCParRetryEn));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->WPREA = %x \n",pDramCfg->WPREA));	
	//pDramCfg->RPREA=RPREA1CLK;
	//pDramCfg->CALEn=FALSE;
	//pDramCfg->CPU_FSBC_ON=FALSE;
	//pDramCfg->DramFastBoot=DRAM_FAST_BOOT_DISABLE;
	//pDramCfg->DramRxTxTimingHardCode=DRAM_RXTX_TIMING_HARDCODE_DISABLE;
	//pDramCfg->CHdecode=DRAM_CH_DECODE_AUTO;
	//pDramCfg->BankGroupBit0Decode=BG_DECODE_A7_A14;
	//pDramCfg->TxVref=TX_VREF_SI;
	//pDramCfg->TxVrefAllByte=TX_VREFALLBYTE_DISABLE;
	//pDramCfg->RxVref=RX_VREF_SI;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->RRankRDelay = %x \n",pDramCfg->RRankRDelay));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->RRankWDelay = %x \n",pDramCfg->RRankWDelay));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pDramCfg->ZxeDualSocket = %x \n",pDramCfg->ZxeDualSocket));	

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n ************************ \n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of dump Asia Dram Cfg Struct default value \n"));   
}
////

////

EFI_STATUS InitDramPrivateData(
	IN EFI_PEI_SERVICES **PeiServices,
	OUT ASIA_DRAM_PEI_PRIVATE_DATA *PrivateData
)
{
	EFI_STATUS Status = 0;
	ASIA_DRAM_CONFIGURATION * pDramCfg;
	DRAM_ATTRIBUTE   *pDramAttr;
	if (NULL == PrivateData || (ASIA_DRAM_PEI_PRIVATE_DATA_SIGNATURE != PrivateData->Signature))
        return EFI_INVALID_PARAMETER;
	//Allocate pool for PrivateData->DramAttr
	//Status = (*PeiServices)->AllocatePool(
	//PeiServices,
	//sizeof(DRAM_ATTRIBUTE),
	//&(PrivateData->DramAttr)
	//&pDramAttr
	//);
    
	//wjb20110608 using create hob to replace allocatepool
	CreateAsiaDramAttrHob(PeiServices,&pDramAttr);
	//if (NULL == PrivateData->DramAttr)
	if (NULL == pDramAttr)
             return EFI_OUT_OF_RESOURCES;
	//(*PeiServices)->SetMem(PrivateData->DramAttr,0x00, sizeof(DRAM_ATTRIBUTE));
	(*PeiServices)->SetMem(pDramAttr, sizeof(DRAM_ATTRIBUTE),0x00);

	//Show SPD information
	PrivateData->DramAttr = (DRAM_ATTRIBUTE *)pDramAttr;
	
	//init Dram configuration structure
	//Status = (*PeiServices)->AllocatePool(
	//           PeiServices,
	//           sizeof(ASIA_DRAM_CONFIGURATION),
	//           &(PrivateData->AsiaDramPpi.DramCfg)
	//       );
	//if (NULL == PrivateData->AsiaDramPpi.DramCfg)
	//return EFI_OUT_OF_RESOURCES;

	//pDramCfg = (ASIA_DRAM_CONFIGURATION*)&(PrivateData->DramAttr->ConfigData);
	pDramCfg = &(pDramAttr->ConfigData);
	PrivateData->AsiaDramPpi.DramCfg = pDramCfg;
	//(*PeiServices)->SetMem(PrivateData->AsiaDramPpi.DramCfg,0x00, sizeof(ASIA_DRAM_CONFIGURATION));
	//(*PeiServices)->CopyMem(pDramCfg, &mDramSetupData, sizeof(ASIA_DRAM_CONFIGURATION));
	InitDramCfgStructDefaultValue(pDramCfg); // AsiaPlatformLib implement it. TGR-20180509001
	DumpDramCfgStructDefaultValue(PeiServices,pDramCfg);  
	  
	return Status;
}

VOID DramCheckPoint(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	//IN PEI_SMBUS_PPI *pSMBusPPI,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DramStepNo
)
{
	//EFI_STATUS Status = TRUE;
	AsiaIoWrite8(0x084, DramStepNo);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Dram Step %x \n", DramStepNo));
	main_loop(PeiServices, pPCIPPI, DramAttr);
	return;
}
    
EFI_STATUS EFIAPI DramNormalInit(
	IN EFI_PEI_SERVICES             **PeiServices,
	IN EFI_ASIA_DRAM_PPI          *This
)
{
	EFI_STATUS Status;
	PEI_CPU_IO_PPI *pCPUPPI;
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	PEI_PCI_CFG_PPI *pPCIPPI;
#else
	EFI_PEI_PCI_CFG2_PPI *pPCIPPI;
#endif
	PEI_SMBUS_PPI *pSMBusPPI;
	EFI_GUID SMBusGUID = PEI_SMBUS_PPI_GUID;
	DRAM_ATTRIBUTE	*pDramAttr;
	ASIA_DRAM_CONFIGURATION *pDramCfg;
	ASIA_DRAM_PEI_PRIVATE_DATA *pPrvData = NULL;
	EFI_ASIA_NB_PPI* AsiaNbPPI;
	EFI_GUID AsiaNbPPIGuid = EFI_ASIA_NB_PPI_GUID;

	if (NULL == *PeiServices)   
		return EFI_INVALID_PARAMETER;

	Status = EFI_SUCCESS;

	PEI_DEBUG((PeiServices, EFI_D_INFO,"PEI_DRAM_INIT \r"));

	pPrvData = GET_PRIVATE_DATA_FROM_THIS(This);  //use internal param

	pDramCfg = (ASIA_DRAM_CONFIGURATION*)(This->DramCfg);
	pDramAttr = (DRAM_ATTRIBUTE*)(pPrvData->DramAttr);
	//Get cpu IO operator :
	pCPUPPI =  (**PeiServices).CpuIo;
	PEI_ASSERT(PeiServices, (pCPUPPI != NULL));

	//Get PCI IO operator :
	pPCIPPI = (**PeiServices).PciCfg;
	PEI_ASSERT(PeiServices, (pPCIPPI != NULL));

	//Get SMBUS operator :
	Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
	ASSERT_PEI_ERROR (PeiServices, Status);

	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaNbPPIGuid, 0, NULL, &AsiaNbPPI);
	PEI_ASSERT(PeiServices, (!EFI_ERROR(Status)));

	
	//Step1 GetBasicInformation
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step1 GetBasicInformation\n"));
	Status = GetBasicInformation(PeiServices, pPCIPPI, pDramAttr);
	//Status = GetBasicInformation(PeiServices, pPCIPPI, pSMBusPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
	//Step2 DRAMInitTable
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step2 DRAMInitTable\n"));
	Status = DRAMInitTable(PeiServices, pPCIPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
	 //Step3 SetDramFeature
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step3 SetDramFeature\n"));
    Status = SetDramFeature(PeiServices, pPCIPPI, pDramAttr);
    if(EFI_SUCCESS != Status )		return Status;
	
	//Step4 SIValueProgramming
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step4 SIValueProgramming\n"));
	Status = SIValueProgramming ( PeiServices, pPCIPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
	//Step5 NBODTLookUpProgramming
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step5 NBODTLookUpProgramming\n"));
	Status = NBODTLookUpProgramming ( PeiServices, pPCIPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
	//Step6 DRAMTimingProgramming
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step6 DRAMTimingProgramming\n"));
	Status = DRAMTimingProgramming(PeiServices, pPCIPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
		
	//Step7 DRAMFreqProgramming  Low Freq
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step7 DRAMFreqProgramming\n"));
	Status = DRAMFreqProgramming(PeiServices, pPCIPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
	
	//Step8 InitDRAMByRank	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step8 InitDRAMByRank\n"));
	Status = InitDRAMByRank(PeiServices, pCPUPPI, pPCIPPI, pDramAttr);	
	if(EFI_SUCCESS != Status )		return Status;	
	
		
	//Step9 IOTimingControl
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step9 IOTimingControl\n"));
	Status = IOTimingControl(PeiServices,pPCIPPI,pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;

	//Step10 SetRefreshCounter
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step10 SetRefreshCounter\n"));
	Status = SetRefreshCounter(PeiServices, pPCIPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;

	
	//Step11 Sizing
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step11 Sizing\n"));
	Status = Sizing(PeiServices, pCPUPPI, pPCIPPI, pDramAttr);	
	if(EFI_SUCCESS != Status )		return Status;
	
	//Step12 UpdateRankAddr
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step12 UpdateRankAddr\n"));
	Status = UpdateRankAddr(PeiServices, pPCIPPI, (ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg), pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;

		
	
	//Step13 FinalTableProgramming
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Step13 FinalTableProgramming\n"));
	Status = FinalTableProgramming(PeiServices, pPCIPPI,pSMBusPPI, pDramAttr);
	if(EFI_SUCCESS != Status )		return Status;
	
	GetDramInfoForUma(PeiServices, pDramAttr);

	//On-board UMA init   
	if(((ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg))->UMAEn == TRUE)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "UMA Enable \n"));
		UmaEnable(PeiServices, pDramAttr, (ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg));
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "UMA Disable \n"));
		UmaDisable(PeiServices, pDramAttr, (ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg));
	}
	
	if (pDramAttr->ConfigData.DramSelfRefresh){
			((ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg))->DramSelfRefresh =  TRUE;
	}
	else
	{
			((ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg))->DramSelfRefresh =  FALSE;
	}

	DumpD0F2(PeiServices,pDramAttr);
	DumpD0F3(PeiServices,pDramAttr);
	//DumpD0F3Perbit(PeiServices,pDramAttr);
	//setup ECC
	DramSetupECC(PeiServices, pCPUPPI, pPCIPPI, pDramAttr);

#ifdef ZX_TXT_SUPPORT
	Status = DramBlockClean(PeiServices, pDramAttr);
	PEI_ASSERT(PeiServices, (!EFI_ERROR(Status)));
#endif
	if(pDramAttr->ConfigData.Dram_Console == CONSOLE_ENABLE) 
	{
	//PEI_DEBUG_CODE(
   		DramCheckPoint(PeiServices, pPCIPPI, pDramAttr, 0x16); // debug	
    //)
	}
 #if 1
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin Memtest\r\n"));
	VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0x5A5A5A5A);
	VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0x3C3C3C3C);
	VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0xFEFEFEFE);
	VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0x7F7F7F7F);
	VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0xB4B4B4B4);
	VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0xD2D2D2D2);
	
#endif	
	AsiaIoWrite8(0x80, 0x2D);

	return Status;
}
