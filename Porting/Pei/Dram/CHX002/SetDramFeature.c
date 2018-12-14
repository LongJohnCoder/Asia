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
#include "Draminit.h"
#include "AsiaNbPeim.h"
#include "SetDramFeature.h"


#define CHANNELA 0
#define CHANNELB 1



EFI_STATUS SetDramFeature(
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr)
{
   UINT64 Address;   
  

  /* -----------------------Setting Data Width----------------------------------------------*/
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDR4_DEV_CTL);
   //CHA Data With
   switch(DramAttr->ChADRAMChipDataWidth[DramAttr->AttrNo])
   {
	   case 8:
		   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMX16_A | D0F3_RDMX8_A, D0F3_RDMX8_A);
		   break;
		   
	   case 16:
		   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMX16_A | D0F3_RDMX8_A, D0F3_RDMX16_A);
		   break;
		   
	   default:
		   break;
   }

   //CHB Data With
   switch(DramAttr->ChBDRAMChipDataWidth[DramAttr->AttrNo])
   {
	   case 8:
		   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMX16_B | D0F3_RDMX8_B, D0F3_RDMX8_B); 
		   break;
		   
	   case 16:
		   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMX16_B | D0F3_RDMX8_B, D0F3_RDMX16_B); 
		   break;

	   default:
		   break;
   }
   /* ------------------------------------------------------------------------------------ */


   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
    ////Register DIMM 
   if(DramAttr->RegDimm)
   {      
       AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIMM, D0F3_RDIMM);
   }
   else
   {
      AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIMM, 0);
   }	
   
  //DDR4 3DS 
  if(DramAttr->Dram3DS == DRAM_3DS)
  {
	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);
	 AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDM3DS, D0F3_RDM3DS);
  }
  else
  {
	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);
	 AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDM3DS, 0);
  }

  //disable ZQCS patch BFT CHX002-201808018 2S4R REBOOT HANG Memory test
  Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_X);
  //set ZQCS period = 0ms
  //RX162[11:0]
  AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RZQCSNUM_11_0, 0x00);
  //RX162[15]  
  AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RZQCSEN, 0);
		

  	//MR2[A7:A6],Low power ASR  -- Hard code 0
	//RX196[8] 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRASR , 0);

	//MR2[A12],Write data CRC enable
	//RX198[7]
	// Must Set before DramInit, or SWinit will Miss setting this register
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCRCEN, 0);

	//MR3[A5],Temperature sensor readout --Hard code DISABLE
	//RX198[3]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTSSEN, 0);



	//MR4[A4],Internal Vref Monitor --Hard code DISABLE
	//RX198[0]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RINVREF_MON, 0);

	//MR4[A3], Temperature Controlled Refresh mode  --Hard code DISABLE  
	//RX198[15] 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTCREN, 0);

	//MR4[A2],Temperature Controlled Refresh range --Hard code 0
	//RX198[14]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTCRRANGE, 0);

	//MR5[A12] Read DBI Enable--Hard code DISABLE
	//RX198[13]
	//LGE20160527 Must Set before DramInit, or SWinit will Miss setting this register
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RRDBIEN, 0);

	//MR5[A11], Write DBI Enable--Hard code DISABLE 
	//RX119[12]
	//LGE20160527 Must Set before DramInit, or SWinit will Miss setting this register
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RWDBIEN, 0);

	//MR5[A9],CA parity persistent error Mode
	//RX198[11]
	//LGE20160527 Must Set before DramInit, or SWinit will Miss setting this register
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCAPARPEN, 0);

   
   //RX19A[2],NO DQM mode	--Hard code Enable NODQM mode
   //LGE20160527 Must Set before DramInit, or SWinit will Miss setting this register
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
		   D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);
   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RNODQMEN, D0F3_RNODQMEN);

	//MR5[A5],ODT input buffer during PWD ---Hard code 0
	//RX19A[7]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTBUFEN, 0);

	//MR3[A4]
	//RX19A[3],PDA mode    --Hard code 0    
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V);    
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPDAEN, 0);

    
    //Enable ECC
   //ECC must Set before IO Timing calibration
   if(DramAttr->ECCSupport){
		if(DramAttr->ConfigData.DRAMECC)
		{    	
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RECCEN | D0F3_RFBECCEN, D0F3_RECCEN | D0F3_RFBECCEN);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC Enable \n"));
		}
		else
	   	{
	   	PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC  disable\n"));
	   	}
   	}
   else
   	{
   	PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC  disable\n"));
   	}


	//DKS-20180109 set this register so that clk can stop when in selfrefresh
	/*if(DramAttr->RegDimm)*/
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{	 
		////////////////////////////////////RCD patch////////////////////////////////////////////
		//RDCLKOAPM = 1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRIO_CHN_A_B_DYNAMIC_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDCLKOAPM, D0F3_RDCLKOAPM);

		//RDCLKOBPM = 1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRIO_CHN_A_B_DYNAMIC_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDCLKOBPM, D0F3_RDCLKOBPM);

		//RDYNPM = 1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_PM_MODE);
		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDYNPM, D0F4_RDYNPM);

		//RDRAMCPM = 1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_DRAMC_PM_REG_3);
		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDRAMCPM, D0F4_RDRAMCPM);

		//RFLOATDIMCLK = 0(A0 need set 1,A2 need set 0)
		if(ASIA_NB_REVISION != 0)
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFLOATDIMCLK, 0);
		}
		else
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFLOATDIMCLK, D0F3_RFLOATDIMCLK);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "A0 Limitation\r\n"));

		}
		//move RDIMM_STAB = 02 to DramNormalInit, this is Haps need
		/////////////////////////////////////////////////////////////////////////////////////////
	}

	{
		//set those two register before refresh couner 
		EFI_STATUS				Status;   
		EFI_GUID				AsiaNbPPIGuid = EFI_ASIA_NB_PPI_GUID;
		EFI_ASIA_NB_PPI         *AsiaNbPPI;
		ASIA_NB_CONFIGURATION   *NbCfg;

		Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaNbPPIGuid, 0, NULL, &AsiaNbPPI);
		PEI_ASSERT(PeiServices, (!EFI_ERROR(Status)));

		NbCfg = (ASIA_NB_CONFIGURATION *)(AsiaNbPPI->NbCfg);
		//RDYNPM = 1
		if(NbCfg->D0F4SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) 
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_PM_MODE);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDYNPM, D0F4_RDYNPM);
			//RDRAMCPM = 1
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_DRAMC_PM_REG_3);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDRAMCPM, D0F4_RDRAMCPM);
		}
	}
	return EFI_SUCCESS;
}

