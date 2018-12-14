//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Draminit.h"
#include "DramUtil.h"
#include "DRAMFreqProgramming.h"

EFI_STATUS DRAMFreqProgramming(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64	Address;

	UINT16 ClockRange;
	UINT16 ClockDiv;
	UINT16 Temp16;
	UINT32 Temp32 = 0;

	switch(DramAttr->DramFreq){
    case DRAM_FREQ_1600:          
       ClockRange = 6;
	   ClockDiv = 2;
       break;
    case DRAM_FREQ_1866:		   
       ClockRange = 6;
	   ClockDiv = 1;      
       break;
    case DRAM_FREQ_2133:		   
       ClockRange = 6;
	   ClockDiv = 1;
       break;
    case DRAM_FREQ_2400:           
       ClockRange = 7;
	   ClockDiv = 1;
       break;
	case DRAM_FREQ_2666:
	   ClockRange = 7;
	   ClockDiv = 1 ;
	   break;
	case DRAM_FREQ_2933:
	   ClockRange = 7;
	   ClockDiv = 1 ;
	   break;	   
	case DRAM_FREQ_3200:
	   ClockRange = 7;
	   ClockDiv = 1;
	   break;
    default:
       ClockRange = 7;
	   ClockDiv = 2;
       break;

    }


#ifdef	DDR4_800
	ClockRange = 4;
	ClockDiv = 3;
#endif	
	
    //step0 set RDIV_M_PLLIN
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_CTL_Z1);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIV_M_PLLIN_7_0, ShiftToMaskBit(D0F3_RDIV_M_PLLIN_7_0,DramAttr->DramFreq));

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLINDDR_CTL_Z1);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIV_M_PLLINDDR_7_0, ShiftToMaskBit(D0F3_RDIV_M_PLLINDDR_7_0,DramAttr->DramFreq));

#ifdef DDR4_800
 	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_CTL_Z1);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIV_M_PLLIN_7_0, ShiftToMaskBit(D0F3_RDIV_M_PLLIN_7_0, DRAM_FREQ_800));

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLINDDR_CTL_Z1);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIV_M_PLLINDDR_7_0, ShiftToMaskBit(D0F3_RDIV_M_PLLINDDR_7_0, DRAM_FREQ_800));	
#endif

    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_CTL_Z2);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCKOUT1_DIVN_PLLIN_2_0, ShiftToMaskBit(D0F3_RCKOUT1_DIVN_PLLIN_2_0, ClockDiv));

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLINDDR_CTL_Z2);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCKOUT1_DIVN_PLLINDDR_2_0, ShiftToMaskBit(D0F3_RCKOUT1_DIVN_PLLINDDR_2_0, ClockDiv));


    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_VCDL_FUN_FOR_CHN_A);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDLL_CKRANGE_2_0, ShiftToMaskBit(D0F3_RDLL_CKRANGE_2_0, ClockRange));

    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_VCDL_FUN_FOR_CHN_B);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDLL_CKRANGE_2_0_CHB, ShiftToMaskBit(D0F3_RDLL_CKRANGE_2_0_CHB, ClockRange));

	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADLL_S24_MUX_PI_FOR_TX_CHN_A);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DLL_A_CKRANGE_2_0, ShiftToMaskBit(D0F3_DLL_A_CKRANGE_2_0, ClockRange));
	
	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ADLL_S24_MUX_PI_FOR_TX_CHN_B);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DLL_B_CKRANGE_2_0, ShiftToMaskBit(D0F3_DLL_B_CKRANGE_2_0, ClockRange));

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,	D0F3_PLLINDDR_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFBDLY_SEL_PLLINDDR_3_0, 0x07);

	

    //Step1 set RPLLIN_PU = 1 and RPLLINDDR_PU =1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPLLIN_PU|D0F3_RPLLINDDR_PU, D0F3_RPLLIN_PU|D0F3_RPLLINDDR_PU);

	   
	//LGE20180514 delay 2000us for Patch ISSUE "PLLM OK, switch clock cause glitch "
	  while(Temp32 < 0x8F000)
		Temp32++;


//LGE20180427 USELESS -S
    //Step 2 - set RPLLIN_RST = 1'b1;RPLLINDDR_RST = 1'b1; after 10us at least
     //Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    //AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPLLIN_RST, D0F3_RPLLIN_RST);

	 //Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    //AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RPLLINDDR_RST, D0F3_RPLLINDDR_RST);    
    //  WaitForMicroSec(PeiServices, 20);
//LGE20180427 USELESS -E	

   //Step 3 wait for RPLLIN_PLLOK = 1 and RPLLINDDR_PLLOK =1
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_COMP_ESD);
   do{
   	  Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & (D0F3_RPLLIN_PLLOK | D0F3_RPLLINDDR_PLLOK); 
   }while(Temp16 != (D0F3_RPLLIN_PLLOK | D0F3_RPLLINDDR_PLLOK));

	WaitForMicroSec(PeiServices, 500);

	//Step Bias Current Enable CHA
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF_S24_CKOUT1_CHN_A);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT1_A, D0F3_RBIASEN_CKOUT1_A); //modify bit2 =1	
	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_A_FOR_BYTE0_1_2_3_8);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT1_BUF2_A_L, D0F3_RBIASEN_CKOUT1_BUF2_A_L); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_A_FOR_BYTE4_5_6_7);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT1_BUF2_A_H, D0F3_RBIASEN_CKOUT1_BUF2_A_H); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF_S24_CKOUT3_CHN_A);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT3_A, D0F3_RBIASEN_CKOUT3_A); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_A_FOR_BYTE0_1_2_3_8);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT3_BUF2_A_L, D0F3_RBIASEN_CKOUT3_BUF2_A_L); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_A_FOR_BYTE4_5_6_7);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT3_BUF2_A_H, D0F3_RBIASEN_CKOUT3_BUF2_A_H); //modify bit2 =1	


	//Step Bias Current Enable CHB
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF_S24_CKOUT1_CHN_B);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT1_B, D0F3_RBIASEN_CKOUT1_B); //modify bit2 =1	
	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_B_FOR_BYTE0_1_2_3_8);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT1_BUF2_B_L, D0F3_RBIASEN_CKOUT1_BUF2_B_L); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_B_FOR_BYTE4_5_6_7);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT1_BUF2_B_H, D0F3_RBIASEN_CKOUT1_BUF2_B_H); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF_S24_CKOUT3_CHN_B);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT3_B, D0F3_RBIASEN_CKOUT3_B); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_B_FOR_BYTE0_1_2_3_8);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT3_BUF2_B_L, D0F3_RBIASEN_CKOUT3_BUF2_B_L); //modify bit2 =1	

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_B_FOR_BYTE4_5_6_7);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RBIASEN_CKOUT3_BUF2_B_H, D0F3_RBIASEN_CKOUT3_BUF2_B_H); //modify bit2 =1	



	WaitForMicroSec(PeiServices, 500);

	
    //Step4 - set DLL_EN_A=1'b1, DLL_EN_B=1'b1 and RDLL_EN = 1'b1, RDLL_EN_CHB = 1'b1 for enabling VCDL_CA_S24 and DDRPHYA_S24	
     Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_DLL_EN_A, D0F3_DLL_EN_A);

	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DLL_EN_B, D0F3_DLL_EN_B);

	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDLL_EN, D0F3_RDLL_EN);

	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDLL_EN_CHB, D0F3_RDLL_EN_CHB);

	while ((AsiaPcieRead32(DramAttr->PcieBaseAddress, AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_DRIVING_TEST)) & D0F3_RDLL_LOCKOK_DDRPHYA_8_0) != D0F3_RDLL_LOCKOK_DDRPHYA_8_0){
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Wait reset OK %8x \r\n",AsiaPcieRead32(DramAttr->PcieBaseAddress, AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_DRIVING_TEST)) & D0F3_RDLL_LOCKOK_DDRPHYA_8_0));

		 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_DLL_EN_A, 0);
		WaitForMicroSec(PeiServices, 1000);
		 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_DLL_EN_A, D0F3_DLL_EN_A);
		WaitForMicroSec(PeiServices, 3000);

		}

while ((AsiaPcieRead32(DramAttr->PcieBaseAddress, AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_DRIVING_TEST_Z1)) & D0F3_RDLL_LOCKOK_DDRPHYB_8_0) != D0F3_RDLL_LOCKOK_DDRPHYB_8_0){

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Wait reset OK %8x \r\n",AsiaPcieRead32(DramAttr->PcieBaseAddress, AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_DRIVING_TEST_Z1)) & D0F3_RDLL_LOCKOK_DDRPHYB_8_0));
	  Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
	 AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DLL_EN_B, 0);
	WaitForMicroSec(PeiServices, 1000);
	 Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLL_OK_AND_VCDL_ENABLE);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DLL_EN_B, D0F3_DLL_EN_B);
	WaitForMicroSec(PeiServices, 3000);

	}

	
	return EFI_SUCCESS;
}
