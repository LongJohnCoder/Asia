//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

///
///
#include "DramInit.h" 
#include "UmaSet.h"
#include "Pei.h"
#include "SvadDvad.h"
#include "SIDramTbl.h"
#include "DramUtil.h"
#include "DramS3Init.h"
#include "UpdateRankAddr.h"
#include "IOTimingControl.h"


#include EFI_PPI_CONSUMER(AsiaNbPpi)


EFI_STATUS DramS3Init(
   IN EFI_PEI_SERVICES             **PeiServices,
   IN EFI_ASIA_DRAM_PPI          *This
)
{ 
    EFI_STATUS Status;
    EFI_ASIA_NB_PPI* AsiaNbPPI;
    EFI_GUID AsiaNbPPIGuid = EFI_ASIA_NB_PPI_GUID;

    ASIA_DRAM_CONFIGURATION *pDramCfg;
    ASIA_DRAM_PEI_PRIVATE_DATA *pPrvData = NULL;
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    PEI_PCI_CFG_PPI *pPCIPPI;

#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI;
#endif
    DRAM_ATTRIBUTE	*pDramAttr;
    UINT16 Temp16;
	UINT32 Temp32;
	UINT32 PcieBase;
	UINT64 Address;
    EFI_BOOT_MODE   BootMode;	
	
    pPCIPPI = (**PeiServices).PciCfg;

    pPrvData = GET_PRIVATE_DATA_FROM_THIS(This);
    pDramAttr = (DRAM_ATTRIBUTE*)(pPrvData->DramAttr);
    pDramCfg = (ASIA_DRAM_CONFIGURATION*)(This->DramCfg);

   


	 PcieBase = AsiaPciRead32(CHX002_HIF | D0F2_MMIOCFG_DECODER) & D0F2_RSVAD_MMIOCFGBASE_39_26 ;
	PcieBase = (PcieBase >> 4) << 26;
	pDramAttr->PcieBaseAddress = PcieBase;	
	pDramAttr->CHX002_BUS_NUM = CHX002_HB_BUS;

	


    //Trigger load IO Timing register	
	TriggerLoadReg(PeiServices, pDramAttr);
	
    (*PeiServices)->GetBootMode (PeiServices, &BootMode);
    if(BootMode == BOOT_ON_S3_RESUME)
	{
		Address = AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DCLKD_DQSI_AUTO_SEL);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "S3 DCLK & MA & DQ & DQS = %x\r\n",AsiaPcieRead16(pDramAttr->PcieBaseAddress,Address)));		
		SetDdrcomp(PeiServices,pPCIPPI, pDramAttr,TRUE);
	}  

	

	//Restore SVAD & DVAD Setting	
	//restore MMIOB2G D0F2_RX44[15:0] From D0F6_RX60[15:0] 
	Address =  AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_9);
    
	Temp16 = AsiaPcieRead16(pDramAttr->PcieBaseAddress, Address);
	Address =  AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_BELOW_2G_MMIOB2G);
	AsiaPcieWrite16(pDramAttr->PcieBaseAddress, Address, Temp16);

	//restore MMIO2T4G D0F2_RX46[15:0] From  D0F6_RX62[15:0]  for S3 Resume
	Address =  AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_9 + 2);
   
	Temp16 = AsiaPcieRead16(pDramAttr->PcieBaseAddress, Address);
	Address =  AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_2G_TO_4G_MMIO2T4G);
	AsiaPcieWrite16(pDramAttr->PcieBaseAddress, Address, Temp16);

	//restore RtopA D0F2_RXA4[31:0] From D0F6_RX64[31:0]
	Address =  AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_10);
	
	Temp32 = AsiaPcieRead32(pDramAttr->PcieBaseAddress, Address);
	Address = AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	AsiaPcieWrite32(pDramAttr->PcieBaseAddress, Address, Temp32);

	//restore  LowTopa D0F2_RxA8[15:0] From D0F6Rx68[15:0]
	Address =  AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_11);
    
	Temp16 = AsiaPcieRead16(pDramAttr->PcieBaseAddress, Address);
	Address = AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
	AsiaPcieWrite16(pDramAttr->PcieBaseAddress, Address, Temp16);

	//set SVAD Entry
	//UpdateSVAD(PeiServices, pPCIPPI, pDramAttr);
	UpdateSVADMemEntry(PeiServices, pDramAttr);

	//set DVAD Entry
	//UpdateDVAD(PeiServices, pPCIPPI, pDramAttr);
	UpdateDVAD(PeiServices,pDramAttr);

	
    // Restore setting in FinalTableProgramming();
    if (pDramAttr ->ConfigData.DynamicCKE){
        AsiaPciModify8( CHX002_NPMC|D0F4_DRAMC_PM_REG_1,
			            D0F4_RDYNCKE,
			            D0F4_RDYNCKE);
    }else{
        AsiaPciModify8( CHX002_NPMC|D0F4_DRAMC_PM_REG_1,
			            D0F4_RDYNCKE,
			            0);
    }


	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaNbPPIGuid, 0, NULL, &AsiaNbPPI);

	PEI_ASSERT(PeiServices, (!EFI_ERROR(Status)));

	if(((ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg))->UMAEn == TRUE) {
		UmaEnableS3(PeiServices, pDramAttr, (ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg));
	}
	else {
		UmaDisable(PeiServices, pDramAttr, (ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg));
	}


	//////////////////////////S3 ISSUE With CAL Mode Debug/////////////////////////////////////////
	if(pDramAttr->ConfigData.CALEn)
	{
		//RSWINIT_CAL 0-->1(D0F3_Rx246[4])
		Address = AsiaPciAddress(pDramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MISC_CTL);
		AsiaPcieModify16(pDramAttr->PcieBaseAddress, Address, D0F3_RSWINIT_CAL, 0);
		
		WaitForMicroSec(PeiServices, 200);
		
		AsiaPcieModify16(pDramAttr->PcieBaseAddress, Address, D0F3_RSWINIT_CAL, D0F3_RSWINIT_CAL);
	}
    if(BootMode == BOOT_ON_S3_RESUME)
	{
		SetDdrcomp(PeiServices,pPCIPPI, pDramAttr,FALSE);
	} 
#if 0
	PEI_DEBUG((PeiServices, EFI_D_INFO, "DKS-Dump D0F2 & D0F3 from S3 mode!!!!!!!!!\n"));
	DumpD0F2(PeiServices,pDramAttr);
	DumpD0F3(PeiServices,pDramAttr);
#endif
	////////////////////////////////////////////////////////////////////////////////


  	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin Memtest\r\n"));
	//VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0x5A5A5A5A);
	//VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0x3C3C3C3C);
	//VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0xFEFEFEFE);
	//VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0x7F7F7F7F);
	//VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0xB4B4B4B4);
	//VT_DramBaseTest( PeiServices, 0x200000, 0x40000, 0xD2D2D2D2);
  
   return EFI_SUCCESS;
}

