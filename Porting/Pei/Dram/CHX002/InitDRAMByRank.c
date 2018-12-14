//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "Draminit.h"
#include "SIDramTbl.h"
#include "DramUtil.h"
#include "InitDRAMByRank.h"
#include "IOTimingControl.h"
#include "UpdateRankAddr.h"


EFI_STATUS InitDRAMByRank(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	
	if(DramAttr->RegDimm == IS_REG_DIMM){
	    SwInitRCDByDimm(PeiServices, pCPUPPI, pPCIPPI, DramAttr);	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Init RCD\r\n"));
	}
	if (DramAttr->ConfigData.DramInitMethod == DRAM_INIT_METHOD_AUTO){		
		  HwInitDRAMByRank(PeiServices, pCPUPPI, pPCIPPI, DramAttr);
		  PEI_DEBUG((PeiServices, EFI_D_ERROR, "execute HwInit\r\n"));		
	}
	else
	{
		  SwInitDRAMByRank(PeiServices, pCPUPPI, pPCIPPI, DramAttr);
		  PEI_DEBUG((PeiServices, EFI_D_ERROR, "execute SwInit\r\n"));
	}


	if(DramAttr->ConfigData.CALEn)
     
		SwSetCALMode(PeiServices, pCPUPPI, pPCIPPI, DramAttr);	


	
	return EFI_SUCCESS;
}


UINT32 GetRCDRC00(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC00Setting32 = MR7_RC00;

	 RC00Setting32 |= MR7_RC00_INVERSION_EN; 
     
     RC00Setting32 |= MR7_RC00_WEAK_DRIVE_DIS;

	 RC00Setting32 |= MR7_RC00_A_OUTPUT_EN;

	 RC00Setting32 |= MR7_RC00_B_OUTPUT_EN;


	  RC00Setting32 |= GetMrsNo(RC00Setting32, 7);
	  
     return RC00Setting32;
}
UINT32 GetRCDRC01(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC01Setting32 =  MR7_RC01;

	 //Should set RC01 Based on SPD[0X83]??????
	 RC01Setting32 |= MR7_RC01_Y0CLK_EN;
     RC01Setting32 |= MR7_RC01_Y1CLK_EN;
	 RC01Setting32 |= MR7_RC01_Y2CLK_EN;
	 RC01Setting32 |= MR7_RC01_Y3CLK_EN;
	 
	 RC01Setting32 |= GetMrsNo(RC01Setting32, 7);
     return RC01Setting32;
}
UINT32 GetRCDRC02(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC02Setting32 =  MR7_RC02;
     RC02Setting32 |= MR7_RC02_DA17_IBT_EN;
     RC02Setting32 |= MR7_RC02_DPAR_IBT_EN;
     RC02Setting32 |= MR7_RC02_TRANSPARENT_DIS;
	 RC02Setting32 |= MR7_RC02_FREQ_OPER;

	 
	 RC02Setting32 |= GetMrsNo(RC02Setting32, 7);
     return RC02Setting32;
}
UINT32 GetRCDRC03(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC03Setting32 =  MR7_RC03;
     ASIA_SPD_DATA	 *CurrentSpdData;
	 UINT8 Tmp = 0;
	 
	 CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][DimmIndex]);

	 //Based on SPD[137]
	 if (CurrentSpdData->SpdPresent){
			Tmp = CurrentSpdData->Buffer[DDR4_RDIMM_SPD_RCD_CA_DRIVE];
	 }

	 //Address/Command Drive
     switch((Tmp >> 4) & 0x03){
	 	case 0:
			RC03Setting32 |= MR7_RC03_ADDR_LIGHT_DRIVE;
			break;
	    case 1:
			RC03Setting32 |= MR7_RC03_ADDR_MODERATE_DRIVE;
			break;
		case 2:
			RC03Setting32 |= MR7_RC03_ADDR_STRONG_DRIVE;
			break;
		case 3:
			RC03Setting32 |= MR7_RC03_ADDR_VSTRONG_DRIVE;
			break;
		default: 
			 break;				
     }
	 //CS Signal Drive
     switch((Tmp >> 6) & 0x03){
	 	case 0:
			RC03Setting32 |= MR7_RC03_CS_LIGHT_DRIVE;
			break;
	    case 1:
			RC03Setting32 |= MR7_RC03_CS_MODERATE_DRIVE;
			break;
		case 2:
			RC03Setting32 |= MR7_RC03_CS_STRONG_DRIVE;
			break;
		case 3:
			RC03Setting32 |= MR7_RC03_CS_VSTRONG_DRIVE;
			break;
		default: 
			 break;				
     }

	 
	 RC03Setting32 |= GetMrsNo(RC03Setting32, 7);
	 return RC03Setting32;
}
UINT32 GetRCDRC04(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC04Setting32 =  MR7_RC04;
	 ASIA_SPD_DATA	 *CurrentSpdData;
	 UINT8 Tmp = 0;
	 
	 CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][DimmIndex]);
      //Based on SPD[137]
	 if (CurrentSpdData->SpdPresent){
			Tmp = CurrentSpdData->Buffer[DDR4_RDIMM_SPD_RCD_CA_DRIVE];
	 }

     //ODT  Drive
     switch((Tmp >> 2) & 0x03){
	 	case 0:
			RC04Setting32 |= MR7_RC04_ODT_LIGHT_DRIVE;
			break;
		case 1:
			RC04Setting32 |= MR7_RC04_ODT_MODERATE_DRIVE;
			break;
		case 2:
			RC04Setting32 |= MR7_RC04_ODT_STRONG_DRIVE;
			break;
		case 3:
			RC04Setting32 |= MR7_RC04_ODT_STRONG_DRIVE;
			break;
		default:
			break;
     }

	 //CKE Drive
	 switch(Tmp & 0x03){
	 	case 0:
			RC04Setting32 |= MR7_RC04_CKE_LIGHT_DRIVE;
			break;
		case 1:
			RC04Setting32 |= MR7_RC04_CKE_MODERATE_DRIVE;
			break;
		case 2:
			RC04Setting32 |= MR7_RC04_CKE_STRONG_DRIVE;
			break;
		case 3:
			RC04Setting32 |= MR7_RC04_CKE_STRONG_DRIVE;
			break;
		default:
			break;
     }

	 
	 RC04Setting32 |= GetMrsNo(RC04Setting32, 7);
	 return RC04Setting32;

}
UINT32 GetRCDRC05(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC05Setting32 =  MR7_RC05;
     ASIA_SPD_DATA	 *CurrentSpdData;
	 UINT8 Tmp = 0;
	 
	 CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][DimmIndex]);
      //Based on SPD[138]
	 if (CurrentSpdData->SpdPresent){
			Tmp = CurrentSpdData->Buffer[DDR4_RDIMM_SPD_RCD_CLK_DRIVE];
	 }

	 //Y1_CLK/Y3_CLK Drive
	 switch((Tmp >> 2) & 0x03){
        case 0:
			RC05Setting32 |= MR7_RC05_ACLK_LIGHT_DRIVE;
		 	break;
		case 1:
			RC05Setting32 |= MR7_RC05_ACLK_MODERATE_DRIVE;
			break;
		case 2:
			RC05Setting32 |= MR7_RC05_ACLK_STRONG_DRIVE;
			break;
		case 3:
			RC05Setting32 |= MR7_RC05_ACLK_STRONG_DRIVE;
			break;
		default:
			break;
	
	 	}
    //
    //Y0_CLK/Y2_CLK Drive
	 switch(Tmp & 0x03){
        case 0:
			RC05Setting32 |= MR7_RC05_BCLK_LIGHT_DRIVE;
		 	break;
		case 1:
			RC05Setting32 |= MR7_RC05_BCLK_MODERATE_DRIVE;
			break;
		case 2:
			RC05Setting32 |= MR7_RC05_BCLK_STRONG_DRIVE;
			break;
		case 3:
			RC05Setting32 |= MR7_RC05_BCLK_STRONG_DRIVE;
			break;
		default:
			break;
	
	 	}
	 
    RC05Setting32 |= GetMrsNo(RC05Setting32, 7);	 
	 return RC05Setting32;
}
UINT32 GetRCDRC06(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC06Setting32 =  MR7_RC06;
	 
     RC06Setting32 |= GetMrsNo(RC06Setting32, 7);	 
	 return RC06Setting32;
}
UINT32 GetRCDRC07(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC07Setting32 =  MR7_RC07;
	 
 	 RC07Setting32 |= GetMrsNo(RC07Setting32, 7);
	 return RC07Setting32;
}
UINT32 GetRCDRC08(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC08Setting32 =  MR7_RC08;

	 //C0/C1/C2 Disable 
     RC08Setting32 |= MR7_RC08_CHIP_ID_DIS; 

	 //QPAR
	 RC08Setting32 |= MR7_RC08_PAR_DIS;     //change DKS test 20180205
	 
     //A17 Disable
	 RC08Setting32 |= MR7_RC08_A17_DIS;

	  RC08Setting32 |= GetMrsNo(RC08Setting32, 7);
	 return RC08Setting32;
}
UINT32 GetRCDRC09(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC09Setting32 =  MR7_RC09;
     
     //cke power down mode disable
     RC09Setting32 |= MR7_RC09_CKE_POWER_DOWN_EN;   //change DKS test 20180205

	 
	 RC09Setting32 |= GetMrsNo(RC09Setting32, 7);
	 return RC09Setting32;
}
UINT32 GetRCDRC0A(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC0ASetting32 =  MR7_RC0A;

     switch(DramAttr->DramFreq){
	 	case DRAM_FREQ_1600:	
		  	   RC0ASetting32 |= MR7_RC0A_DDR41600;
			   break;
		  case DRAM_FREQ_1866:
		  	   RC0ASetting32 |= MR7_RC0A_DDR41866;
			   break;
		  case DRAM_FREQ_2133:
		  	   RC0ASetting32 |= MR7_RC0A_DDR42133;
			   break;
		  case DRAM_FREQ_2400:
		  	   RC0ASetting32 |= MR7_RC0A_DDR42400;
			   break;
		  case DRAM_FREQ_2666:
		  	   RC0ASetting32 |= MR7_RC0A_DDR42666;
			   break;
		  case DRAM_FREQ_2933:
		  	   RC0ASetting32 |= MR7_RC0A_DDR42933;
			   break;
		  case DRAM_FREQ_3200:
		  	   RC0ASetting32 |= MR7_RC0A_DDR43200;
			   break;
	      default: 
		  	   RC0ASetting32 |= MR7_RC0A_DDR41600;
			   break;
		}


	 RC0ASetting32 |= GetMrsNo(RC0ASetting32, 7);
	 return RC0ASetting32;
}

UINT32 GetRCDRC3X(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
    UINT32	RC3XSetting32 =  MR7_RC3X;

	// TODO: Add 2666& 3200 support
    switch(DramAttr->DramFreq){
	 	case DRAM_FREQ_1600:	
		  	   RC3XSetting32 |= MR7_RC3X_DDR41600;
			   break;
		  case DRAM_FREQ_1866:
		  	   RC3XSetting32 |= MR7_RC3X_DDR41866;
			   break;
		  case DRAM_FREQ_2133:
		  	   RC3XSetting32 |= MR7_RC3X_DDR42133;
			   break;
		  case DRAM_FREQ_2400:
		  	   RC3XSetting32 |= MR7_RC3X_DDR42400;
			   break;
		  case DRAM_FREQ_2666:
		  	   RC3XSetting32 |= MR7_RC3X_DDR42666;
			   break;
		  case DRAM_FREQ_2933:
		  	   RC3XSetting32 |= MR7_RC3X_DDR42933;
			   break;	   
		  case DRAM_FREQ_3200:
		  	   RC3XSetting32 |= MR7_RC3X_DDR43200;
			   break;
	      default: 
		  	   RC3XSetting32 |= MR7_RC3X_DDR41600;
			   break;
		}	 

	RC3XSetting32 |= GetMrsNo(RC3XSetting32, 7);
    return RC3XSetting32;
}

UINT32 GetRCDRC0B(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC0BSetting32 =  MR7_RC0B;

	 RC0BSetting32 |= MR7_RC0B_VDD12;

     //Vref source
	 RC0BSetting32 |= MR7_RC0B_INTER_VREF;

	 RC0BSetting32 |= GetMrsNo(RC0BSetting32, 7);
	 return RC0BSetting32;
}
UINT32 GetRCDRC0C(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC0CSetting32 =  MR7_RC0C;

	 RC0CSetting32 |= MR7_RC0C_NOMAL_MODE; 

	 RC0CSetting32 |= GetMrsNo(RC0CSetting32, 7);
	 return RC0CSetting32;
}
UINT32 GetRCDRC0D(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC0DSetting32 =  MR7_RC0D;
     
     //CS MODE
     RC0DSetting32 |=  MR7_RC0D_DUALCS_MODE;

	 //DIMM Type
	 RC0DSetting32 |= MR7_RC0D_RDIMM;

	 //LGE20160722 NOTE:Address Mirror Must Enable, Or RDIMM RANK1 INIT WILL FAIL
     RC0DSetting32 |= MR7_RC0D_ADD_MIRROR_EN;

	 RC0DSetting32 |= GetMrsNo(RC0DSetting32, 7);
	 return RC0DSetting32;
}
UINT32 GetRCDRC0E(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC0ESetting32 = MR7_RC0E;

     //RCD Parity check
     RC0ESetting32 |= MR7_RC0E_PAR_DIS;


	 RC0ESetting32 |= GetMrsNo(RC0ESetting32, 7);
	 return RC0ESetting32;
}

UINT32 GetRCDRC0F(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT8 ActionType8)
{
     UINT32	RC0FSetting32 = MR7_RC0F;


	if(ASIA_NB_REVISION == 0)
	{
		//Command Latency Adder
		//A0PATCH LGE20180906 set CLA = 0 Patch RDIMM TXWHOLET NOT enough issue
		RC0FSetting32 |= MR7_RC0F_CLA_0CLK;
		//A0PATCH LGE20180906 set CLA = 0 Patch RDIMM TXWHOLET NOT enough issue
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "A0 Limitation\r\n"));

	}
	else
	{
	 	RC0FSetting32 |= MR7_RC0F_CLA_1CLK;
	}
	 RC0FSetting32 |= GetMrsNo(RC0FSetting32, 7);
	 return RC0FSetting32;
}

UINT32 GetRCDRC4X(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 CW_ADDR,
	IN UINT8 FunSpace)
{
     UINT32	RC4XSetting32 = MR7_RC4X;


     switch(FunSpace)
     {
		case 1:
			RC4XSetting32 |= FUN_SPACE1;
			break;
		case 2:
			RC4XSetting32 |= FUN_SPACE2;
			break;
		case 3:
			RC4XSetting32 |= FUN_SPACE3;
			break;                    			 
		case 4:
			RC4XSetting32 |= FUN_SPACE4;
			break;
		case 5:
			RC4XSetting32 |= FUN_SPACE5;
			break;
		default:
			break;
	 }	 


	 RC4XSetting32 |= GetMrsNo(RC4XSetting32, 7);
	 return RC4XSetting32;

}

UINT32 GetRCDRC6X(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex,
	IN UINT32 CW_DATA)
{
     UINT32	RC6XSetting32 = MR7_RC6X;
	 
	 RC6XSetting32 |= CW_DATA;


	 RC6XSetting32 |= GetMrsNo(RC6XSetting32, 7);
	 return RC6XSetting32;

}


VOID SwInitRCDSequence(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 DimmIndex)
{
    UINT32	Buffer32=0, MrsSet32=0, DummyReadBase=0x00;
    UINT64 Address;
	
	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;
	
	// SDRAM initialization sequence
	// deassert RESET# and at least wait for 500 us
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, D0F3_RMEMRSTN);
	
	WaitForMicroSec(PeiServices, 10);	//delay 10us
	
	// Execute NOP
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NOP);

	//LGE20160420 flush CFG write for RSDM registers
   FlushCfgWrite(PeiServices, DramAttr, Address);
	
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read
		
	WaitForMicroSec(PeiServices, 10);	//delay 10us


    //Set MRS mode
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);

    //LGE20160420 flush CFG write for RSDM registers
   FlushCfgWrite(PeiServices, DramAttr, Address);

    //Issue MR7 RC00
    MrsSet32 = GetRCDRC00(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us


    //Issue MR7 RC01
    MrsSet32 = GetRCDRC01(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC02
    MrsSet32 = GetRCDRC02(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC03
    MrsSet32 = GetRCDRC03(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC04
    MrsSet32 = GetRCDRC04(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC05
    MrsSet32 = GetRCDRC05(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC08
    MrsSet32 = GetRCDRC08(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC09
    MrsSet32 = GetRCDRC09(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us
	//Issue MR7 RC0A
    MrsSet32 = GetRCDRC0A(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC0B
    MrsSet32 = GetRCDRC0B(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC0C
    MrsSet32 = GetRCDRC0C(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC0E
    MrsSet32 = GetRCDRC0E(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC0F
    MrsSet32 = GetRCDRC0F(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Issue MR7 RC3X
    MrsSet32 = GetRCDRC3X(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay10us

	//Issue MR7 RC0D
    MrsSet32 = GetRCDRC0D(PeiServices, DramAttr, DimmIndex,  DDR4_MR7_INIT);
    Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	WaitForMicroSec(PeiServices, 10);	//delay 10us






    //CAL MODE
    //Issue MR7 F1RC01
    // TODO:LGE20180118 Comment out for temp
    if(DramAttr->ConfigData.CALEn)
    {
	  //MrsSet32 = GetRCDRC4X(PeiServices, DramAttr, 0, SPACE1);
      //Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	  //WaitForMicroSec(PeiServices, 10);	//delay 10us

      
	  //MrsSet32 = GetRCDRC6X(PeiServices, DramAttr, DimmIndex, MR7_F1RC01 | MR7_F1RC01_CALSNOOP_EN);
	  //Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);  // Dummy Read
	  //WaitForMicroSec(PeiServices, 10); //delay 10us

	}



	

    // Normal
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//LGE20160420 flush CFG write for RSDM registers
   FlushCfgWrite(PeiServices, DramAttr, Address);
	
    return;
}

VOID SwInitRCDByDimm(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
    UINT16	PageMode;
	UINT8	RankIdx8;
	UINT64  Address;
	UINT16 SavedBARASelect = 0;
	//UINT8  SavedBANKSEL = 0;
 	//UINT8  SavedDataWidth = 0;

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin Init RDIMM RCD"));
	
	// Clear VRank size
    for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8*2);
        AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00);         
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                    D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00); 
	}

	

	// Clear all PR-to-VR Mapping
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++)
		SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, RankIdx8, FALSE);

    //Save BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
		
	// save page mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	PageMode = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RPGEN;

	// disable page mode
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, 0);
    
    
   /* 
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V); 
	if(!DramAttr->ConfigData.CPU_FSBC_ON)
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RRDFIFOEN,0);
	else
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RRDFIFOEN,D0F3_RRDFIFOEN);	
	*/
	//LGE-20151221
	// disable RODTEN
	//RX16A[7]
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, 0);

	 //LGE20160420 Disable Refresh counter
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_REFC_7_0, 0);


	if (DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0)
	{
		//LGE-20151225  Toggle RESET
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, 0);
		//delay 200us
		WaitForMicroSec(PeiServices, 200);	
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, D0F3_RMEMRSTN);
		//delay 500us
		WaitForMicroSec(PeiServices, 500);	
	}
	if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0)
	{
		//LGE-20151225  Toggle RESET
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN_CHB, 0);
		//delay 200us
		WaitForMicroSec(PeiServices, 200);	
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN_CHB, D0F3_RMEMRSTN_CHB);
		//delay 500us
		WaitForMicroSec(PeiServices, 500);	
	}
	
	
    // Map each Physical Rank N to Virtual Rank N in each loop
    // NOTE:  Only Rank0/Rank2/Rank4/Rank6 Need Init RCD
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8+=2) {
		if ( DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ) {	//Init Only when RankPresent
     			PEI_DEBUG((PeiServices, EFI_D_INFO, "Dram Software Initialization - Rank = %x\n", RankIdx8));

			
			//Put target rank N to rank N and 0~256M
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2); 
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x04);
			SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, RankIdx8, TRUE);

			//Software initial RCD
			SwInitRCDSequence(PeiServices, pCPUPPI, pPCIPPI, DramAttr, RankIdx8/2);

			//Clear begin-end address
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26 + + RankIdx8*2); 
            AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);
					
		}
	}
   
    // enable RODTEN
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, D0F3_RODTEN);


	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	
	//restore page mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, PageMode);
	return;   

}




VOID SwInitDRAMByRank(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	PageMode;
	UINT8	RankIdx8;
	UINT64  Address;

	UINT16 SavedBARASelect = 0;
    // Ensure RSINGLECH/R2C4RINLVEN/	R2C2RINLVEN/R2C1RINLVEN/R1C4RINLVEN/R1C2RINLVEN =0
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 
		D0F3_RSINGLECH| D0F3_R2C4RINLVEN|D0F3_R2C2RINLVEN|D0F3_R2C1RINLVEN|D0F3_R1C4RINLVEN|D0F3_R1C2RINLVEN, 0);

	// Clear VRank size
    for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8*2);
        AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00);         
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                    D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00); 
	}

	// Clear all PR-to-VR Mapping
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++)
		SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, 0x00, FALSE);


	//LGE20161109 Save BA /RA Select for X16
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);

	// save page mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	PageMode = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RPGEN;

	// disable page mode
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, 0);

	
    //LGE-20160509 HARD CODE D0F3_RRDFIFOEN = 0
	//172[1] = 0
   /*
   Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V); 
	if(!DramAttr->ConfigData.CPU_FSBC_ON)
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RRDFIFOEN,0);
	else
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RRDFIFOEN,D0F3_RRDFIFOEN);	
	*/
	//LGE-20160509

	// disable RODTEN
	//RX192[7]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, 0);

	//LGE20160420 Disable Refresh counter
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, 0);

    if(DramAttr->RegDimm != IS_REG_DIMM)
	{

		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0)
		{
			//LGE-20151225  Toggle RESET
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, 0);
			//delay 200us
			WaitForMicroSec(PeiServices, 200);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, D0F3_RMEMRSTN);
			//delay 500us
			WaitForMicroSec(PeiServices, 500);
		}
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0)
		{
			//LGE-20151225  Toggle RESET
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN_CHB, 0);
			//delay 200us
			WaitForMicroSec(PeiServices, 200);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN_CHB, D0F3_RMEMRSTN_CHB);
			//delay 500us
			WaitForMicroSec(PeiServices, 500);
		}
		
    }
	
	// Map each Physical Rank N to Virtual Rank 0(ChA)/4(ChB) in each loop
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		if ( DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ) {	//Init Only when RankPresent
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Dram Software Initialization - Rank = %x\n", RankIdx8));
			
			Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x04);			   
			SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, RankIdx8, TRUE);

			//Software initial sequence
			SwInitDdr4Sequence(PeiServices, pCPUPPI, pPCIPPI, DramAttr, RankIdx8);

			//Clear begin-end address
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
		    AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);		
		}
	}

	// enable RODTEN
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, D0F3_RODTEN);

	
	//Restore BA /RA Select
	SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);

	//restore page mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, PageMode);
	return;

}

VOID SwInitDdr4Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN INT8 RankIndex)
{
	UINT32	Buffer32=0, MrsSet32=0, DummyReadBase=0x00;
	UINT64 Address;

	if(DramAttr->AttrNo == 0) DummyReadBase=0x00;
	else if(DramAttr->AttrNo == 1) DummyReadBase=0x10000000;
	
	
	// SDRAM initialization sequence

	// Execute NOP
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NOP);

	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read

	WaitForMicroSec(PeiServices, 10);	//delay 10us

	//Set MRS mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);

	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	// Issue MR3
	Buffer32 = GetDDR4MR3(PeiServices, DramAttr, RankIndex, DDR4_MR3_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR3:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR3:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	//Issue MR6  
	//VREF_RANGE = RANGE1, VrefDQ = 0
	Buffer32 = GetDDR4MR6(PeiServices, DramAttr, RankIndex, DDR4_MR6_INIT | VREF_RANGE1, 0x00);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR6:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR6:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	//Issue MR5
	//ODT input buffer is activated
	Buffer32 = GetDDR4MR5(PeiServices, DramAttr, RankIndex, DDR4_MR5_INIT | ODT_PWD_ACT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR5:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR5:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	//Issue MR4
	Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankIndex, DDR4_MR4_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR4:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR4:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	// Issue MR2
	Buffer32 = GetDDR4MR2(PeiServices, DramAttr, RankIndex, DDR4_MR2_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR2:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR2:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	// Issue MR1
	Buffer32 = GetDDR4MR1(PeiServices, DramAttr, RankIndex, DDR4_MR1_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR1:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR1:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	// Issue MR0
	Buffer32 = GetDDR4MR0(PeiServices, DramAttr, RankIndex, DDR4_MR0_INIT);
	MrsSet32 = Buffer32;
	if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex] == RANK1_MAPPING_MIRRORED)
		MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR0:%x\n", MrsSet32));

	WaitForMicroSec(PeiServices, 10);	//delay 10us
	if(DramAttr->RegDimm == IS_REG_DIMM)
    {
        //Init RDIMM SIDE B 
        MrsSet32 = SideBAddressInvert(PeiServices, MrsSet32);
		Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR0:%x\n", MrsSet32));
		WaitForMicroSec(PeiServices, 10);	//delay 10us
    }

	// Issue ZQCL command to starting ZQ calibration
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_ZQCL);

	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase);	// Dummy Read

	WaitForMicroSec(PeiServices, 10);	//delay 10us

	// Normal
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
	//LGE20160420 flush CFG write for RSDM registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	
	return;
}



VOID SwSetCALMode(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	
	UINT8	RankIdx8;
	UINT64	Address;
	UINT32 Buffer32 = 0x00, MrsSet32 = 0x00, DummyReadBase=0x00, Buffer32SIDEB = 0;
	UINT16  SavedREFC = 0;
	UINT16 SavedBARASelect = 0;	
	UINT16  SavedOdt = 0;
	UINT16	SavedPageMode = 0;

	
    SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedBARASelect);
	//Disable REF
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);		
	//Save ODT and disable
	SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);    
    SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedPageMode);	
	//Clear all VRank size
	ClearAllRankSize(DramAttr);		

	// Clear all PR-to-VR Mapping
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++)
		SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, 0x00, FALSE);

	
	// Map each Physical Rank N to Virtual Rank 0(ChA)/4(ChB) in each loop
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		if ( DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ) {	//Init Only when RankPresent
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Dram Software Initialization - Rank = %x\n", RankIdx8));
			Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x04);				
			SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, RankIdx8, TRUE);

			//Precharge all
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_PREA);
			//LGE20160420 flush CFG write for RSDM registers
			FlushCfgWrite(PeiServices, DramAttr, Address);
			Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase); // Dummy Read
			WaitForMicroSec(PeiServices, 10);	//delay 1ms



            //Set MRS Mode
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_MRS);
			//LGE20160420 flush CFG write for RSDM registers
			FlushCfgWrite(PeiServices, DramAttr, Address);

			
			if(DramAttr->ConfigData.CALEn)
			 {
				Buffer32 = GetDDR4MR4(PeiServices, DramAttr, RankIdx8, MR4_CALEN);
				MrsSet32 = Buffer32;
			 
				if(DramAttr->RegDimm == IS_REG_DIMM)
				{
					//Init RDIMM SIDE B 
					Buffer32SIDEB = SideBAddressInvert(PeiServices, MrsSet32);
					Buffer32SIDEB = *(UINT32 volatile *)(UINT32)(DummyReadBase|Buffer32SIDEB);	  // Dummy Read
				
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "side B MR4:%x\n", Buffer32SIDEB));
					WaitForMicroSec(PeiServices, 10);	//delay 10us
				}
			
				//SIDEA
				if (DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIdx8] == RANK1_MAPPING_MIRRORED)
					 MrsSet32 = Rank1AddressMirror(PeiServices, Buffer32);
				Buffer32 = *(UINT32 volatile *)(UINT32)(DummyReadBase|MrsSet32);	// Dummy Read
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "MR4:%x\n", MrsSet32));
				
				WaitForMicroSec(PeiServices, 10);	//delay 10us
			
			
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MISC_CTL);
				AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSWINIT_CAL, 0);
				AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RSWINIT_CAL, D0F3_RSWINIT_CAL);
			
			 }	


			// Normal
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSDM_2_0, D0F3_RSDM_NORMAL);
			//LGE20160420 flush CFG write for RSDM registers
			FlushCfgWrite(PeiServices, DramAttr, Address);

	
			//Clear begin-end address
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x00);	
		}
	}

	

    SaveRestoreBARASelect(PeiServices, pPCIPPI, DramAttr, FALSE, &SavedBARASelect);
	//Disable REF
	SaveRestoreREFC(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedREFC);		
	//Save ODT and disable
	SaveRestoreOdt(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedOdt);    
    SaveRestorePageMode(PeiServices, pPCIPPI, DramAttr, TRUE, &SavedPageMode);	
	return;

}

UINT32 GetMrsNo(UINT32 MRSetting, UINT8 MrsNo)
{
//BG1 		BG0		 BA1	       	BA0
//15^20      14 ^7        18^23          17^22
	UINT32 BG1 = 0;
	UINT32 BG0 = 0;
	UINT32 BA1 = 0;
	UINT32 BA0 = 0;

    BG1 = (((MRSetting&BIT20) >> 20) ^ ((MrsNo&BIT3) >> 3)) << 15;
	BG0 = (((MRSetting&BIT7) >> 7) ^ ((MrsNo&BIT2) >> 2)) << 14;
    BA1 = (((MRSetting&BIT23) >> 23) ^ ((MrsNo&BIT1) >> 1)) << 18;
	BA0 = (((MRSetting&BIT22) >> 22) ^ (MrsNo&BIT0)) << 17;

    return (BG1 | BG0 | BA1 | BA0);

}

UINT32 GetDDR4MR0(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8)
{
	UINT32	MR0Setting32 = 0;
    //WR and RTP
    switch(DramAttr->Twr[DramAttr->AttrNo]){
		case 0:
			MR0Setting32 |= MR0_DDR4_WR_RTP_10_5;
			break;
	    case 1:
			MR0Setting32 |= MR0_DDR4_WR_RTP_12_6;
			break;
		case 2:
			MR0Setting32 |= MR0_DDR4_WR_RTP_14_7;
			break;
		case 3:
			MR0Setting32 |= MR0_DDR4_WR_RTP_16_8;
			break;
		case 4:
			MR0Setting32 |= MR0_DDR4_WR_RTP_18_9;
			break;
		case 5:
			MR0Setting32 |= MR0_DDR4_WR_RTP_20_10;
			break;
		case 6:
			MR0Setting32 |= MR0_DDR4_WR_RTP_24_12;
			break;
		case 7:
			MR0Setting32 |= MR0_DDR4_WR_RTP_22_11;
			break;
		case 8:
			MR0Setting32 |= MR0_DDR4_WR_RTP_26_13;
			break;	
		default:
			MR0Setting32 |= MR0_DDR4_WR_RTP_24_12;
			break;			

	}
    // DLL RESET
    MR0Setting32 |= MR0_DDR4_DLL_RESET;

	//CL
	switch(DramAttr->CL[DramAttr->AttrNo]){
		case 9:
	        MR0Setting32 |= MR0_DDR4_CL9;
		    break;
		case 10:
		    MR0Setting32 |= MR0_DDR4_CL10;
		    break;
		case 11:
		    MR0Setting32 |= MR0_DDR4_CL11;
		    break;
		case 12:
		    MR0Setting32 |= MR0_DDR4_CL12;
		    break;
		case 13:
			MR0Setting32 |= MR0_DDR4_CL13;
		    break;
		case 14:
			MR0Setting32 |= MR0_DDR4_CL14;
		    break;
		case 15:
			MR0Setting32 |= MR0_DDR4_CL15;
		    break;
		case 16:
			MR0Setting32 |= MR0_DDR4_CL16;
		    break;
		case 18:
			MR0Setting32 |= MR0_DDR4_CL18;
		    break;
		case 20:
			MR0Setting32 |= MR0_DDR4_CL20;
		    break;
		case 22:
			MR0Setting32 |= MR0_DDR4_CL22;
		    break;
		case 24:
			MR0Setting32 |= MR0_DDR4_CL24;
		    break;			
		case 23:
			MR0Setting32 |= MR0_DDR4_CL23;
		    break;
		case 17:
			MR0Setting32 |= MR0_DDR4_CL17;
		    break;
		case 19:
			MR0Setting32 |= MR0_DDR4_CL19;
		    break;
		case 21:
			MR0Setting32 |= MR0_DDR4_CL21;
		    break;
		case 25:
			MR0Setting32 |= MR0_DDR4_CL25;
		    break;
		case 26:
			MR0Setting32 |= MR0_DDR4_CL26;
		    break;
		case 27:
			MR0Setting32 |= MR0_DDR4_CL27;
		    break;
		case 28:
			MR0Setting32 |= MR0_DDR4_CL28;
		    break;
		case 30:
			MR0Setting32 |= MR0_DDR4_CL30;
		    break;
		case 32:
			MR0Setting32 |= MR0_DDR4_CL32;
		    break;	
		default:
			MR0Setting32 |= MR0_DDR4_CL24;
		    break;

	}

    //read burst type
    MR0Setting32 |= MR0_DDR4_READ_BURST_INVL;

    //Burst Length
	if (DramAttr->BurstLength8 == BL8)
		MR0Setting32 |= MR0_DDR4_BL8;
	else
		MR0Setting32 |= MR0_DDR4_ON_THE_FLY;


    //ADD MRS No. 
	MR0Setting32 |= GetMrsNo(MR0Setting32, 0);
    
	
	return MR0Setting32;
}

UINT32 GetDDR4MR1(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8)
{
	UINT32	MR1Setting32 = 0;

	//RTT_NOM
	if (ActionType8 == MR1_WLVL_UNDERCALPR)
		MR1Setting32 |= MR1_DDR4_RTT_NOM_120OHM;
	else
		MR1Setting32 |= (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex]);

	//Write leveling
	if (ActionType8 == MR1_WLVL_UNDERCALPR)
		MR1Setting32 |= MR1_DDR4_WLVL_EN;
	else if (ActionType8 == MR1_WLVL_OTHERPR)
		MR1Setting32 |= MR1_DDR4_WLVL_EN;

	if (ActionType8 == MR1_WLVL_OTHERPR)
		MR1Setting32 |= MR1_DDR4_QOff_DIS;

    //AL
    MR1Setting32 |= MR1_DDR4_AL_DIS;

	//Output Driver Impedance Control
    MR1Setting32 |= (DramAttr->OutputDriver[DramAttr->AttrNo][RankIndex>>1]);

    //DLL
	MR1Setting32 |= MR1_DDR4_DLL_EN;     

	//ADD MRS No. 
	   MR1Setting32 |= GetMrsNo(MR1Setting32, 1);


	return MR1Setting32;
}

UINT32 GetDDR4MR2(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8)
{
	UINT32	MR2Setting32 = 0;

    //write CRC
    if(DramAttr->ConfigData.CRCEn)
        MR2Setting32 |= MR2_DDR4_CRC_EN;

    //RttWR
    if (ActionType8 == MR2_RTTWR_DIS)
		MR2Setting32 |= MR2_DDR4_RTT_WR_DIS;
	else
	    MR2Setting32 |= DramAttr->RttWR[DramAttr->AttrNo][RankIndex];

	//Low Power Array Self Refresh
    MR2Setting32 |= MR2_DDR4_LPASR_NOM;

	//CWL	
	switch (DramAttr->CWL[DramAttr->AttrNo]) {
		case 9:
			MR2Setting32 |= MR2_DDR4_CWL_9;
			break;
		case 10:
			MR2Setting32 |= MR2_DDR4_CWL_10;
			break;
		case 11:
			MR2Setting32 |= MR2_DDR4_CWL_11;
			break;
		case 12:
			MR2Setting32 |= MR2_DDR4_CWL_12;
			break;
		case 14:
			MR2Setting32 |= MR2_DDR4_CWL_14;
			break;
		case 16:
			MR2Setting32 |= MR2_DDR4_CWL_16;
			break;
		case 18:
			MR2Setting32 |= MR2_DDR4_CWL_18;
			break;
		case 20:
			MR2Setting32 |= MR2_DDR4_CWL_20;
			break;
		default:
			MR2Setting32 |= MR2_DDR4_CWL_16;
			break;
	}


     //ADD MRS No. 
	MR2Setting32 |= GetMrsNo(MR2Setting32, 2);
	 
	return MR2Setting32;
}

UINT32 GetDDR4MR3(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 ActionType16)
{
	UINT32	MR3Setting32 = 0;

	//MPR related
	if(ActionType16 & MR3_MPR_EN)
		MR3Setting32 |= MR3_DDR4_MPR_EN;
	if(ActionType16 & MR3_MPR_SERIAL)
		MR3Setting32 |= MR3_DDR4_SERIAL; 
	else if(ActionType16 & MR3_MPR_PARALLEL)
		MR3Setting32 |= MR3_DDR4_PARALLEL;
	else if(ActionType16 & MR3_MPR_STAGGER)
		MR3Setting32 |= MR3_DDR4_STAGGER; 

	if(ActionType16 & MR3_MPR_PAGE0)
		MR3Setting32 |= MR3_DDR4_MPR_PAGE0;
	else if(ActionType16 & MR3_MPR_PAGE1)
		MR3Setting32 |= MR3_DDR4_MPR_PAGE1;
	else if(ActionType16 & MR3_MPR_PAGE2)
		MR3Setting32 |= MR3_DDR4_MPR_PAGE2;
	else if(ActionType16 & MR3_MPR_PAGE3)
		MR3Setting32 |= MR3_DDR4_MPR_PAGE3;

	//Fine Granularity Refresh Mode
	MR3Setting32 |= MR3_DDR4_FGRM_1X;

	//Temperature sensor readout

	//PDA mode
   if(ActionType16 & MR3_MPR_PDA)
			MR3Setting32 |= MR3_DDR4_PDA_EN;

	//Geardown mode
	MR3Setting32 |= MR3_DDR4_GEARDOWN_DIV2;

	//Write CMD Latency when CRC and DM are enabled

			MR3Setting32 |= MR3_DDR4_CRC_RWCL4;
	
 //ADD MRS No. 
	MR3Setting32 |= GetMrsNo(MR3Setting32, 3);

	return MR3Setting32;
}
UINT32 GetDDR4MR4(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8)
{
	UINT32	MR4Setting32 = 0;

	//Write Preamble
	if(DramAttr->WPREA == WPREA1CLK)
		MR4Setting32 |= MR4_DDR4_WR_PREAMBLE_1;
	else
		MR4Setting32 |= MR4_DDR4_WR_PREAMBLE_2;
	//Read Preamble
	if(DramAttr->RPREA == RPREA1CLK)
		MR4Setting32 |= MR4_DDR4_RD_PREAMBLE_1;
	else
		MR4Setting32 |= MR4_DDR4_RD_PREAMBLE_2;

	//Read Preamble Training Mode
	if(ActionType8 & MR4_RD_PREAMBLE_TRAIN)
		MR4Setting32 |= MR4_DDR4_RD_PREAMBLE_TRAIN;

	//Self Refresh Abort

	//CAL 
if(ActionType8 & MR4_CALEN){
	switch(DramAttr->CAL[DramAttr->AttrNo]){
		case 0:
			MR4Setting32 |= MR4_DDR4_CAL_DIS;
			break;
		case 3:
			MR4Setting32 |= MR4_DDR4_CAL_3;
			break;
		case 4:
			MR4Setting32 |= MR4_DDR4_CAL_4;
			break;
		case 5:
			MR4Setting32 |= MR4_DDR4_CAL_5;
			break;
		case 6:
			MR4Setting32 |= MR4_DDR4_CAL_6;
			break;
		case 8:
			MR4Setting32 |= MR4_DDR4_CAL_8;
			break;

		}
	}
	else
		MR4Setting32 |= MR4_DDR4_CAL_DIS;
	//Internal Vref Monitor

	//Temperature Controlled Refresh Mode

	//Temperature Controlled Refresh Range
	MR4Setting32 |= MR4_DDR4_TEMP_CTL_REF_NOM ;

	//Maximum Power Down mode
	if(ActionType8 & MR4_MPDM_EN)
		MR4Setting32 |= MR4_DDR4_MPDM_EN;

    MR4Setting32 |= GetMrsNo(MR4Setting32, 4); 
	return MR4Setting32;
}

UINT32 GetDDR4MR5(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8)
{
	UINT32	MR5Setting32 = 0;

	if(DramAttr->ConfigData.CAParPerEn)
		MR5Setting32 |= MR5_DDR4_CA_PAR_PERSISTENT;

	//RTT_PARK
	MR5Setting32 |= DramAttr->RttPark[DramAttr->AttrNo][RankIndex];

	//OTD input buffer during Power down mode
	if(ActionType8 == ODT_PWD_ACT)
		MR5Setting32 |= MR5_DDR4_ODT_PWD_ACT;
	else if(ActionType8 == ODT_PWD_DE_ACT)
		MR5Setting32 |= MR5_DDR4_ODT_PWD_DE_ACT;

	//Parity Latency
	MR5Setting32 |= MR5_DDR4_PL_DIS;
#if 0	
	if(!DramAttr->ConfigData.CAParEn)
		MR5Setting32 |= MR5_DDR4_PL_DIS;
	else{
		switch(DramAttr->PL){
			case 1:
				MR5Setting32 |= MR5_DDR4_PL4;
				break;
			case 2:
				MR5Setting32 |= MR5_DDR4_PL5;
				break;
			case 3:
				MR5Setting32 |= MR5_DDR4_PL6;
				break;
		}
	}
#endif	


    MR5Setting32 |= GetMrsNo(MR5Setting32, 5);
	return MR5Setting32;
}

UINT32 GetDDR4MR6(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ActionType8,
	IN UINT32 VrefDQ)
{
	UINT32	MR6Setting32 = 0;
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600: 
		case DRAM_FREQ_1866: 
			MR6Setting32 |= MR6_DDR4_TCCDL5;      //tCCD_L = 5 
			break;
		case DRAM_FREQ_2133: 
		case DRAM_FREQ_2400: 
			MR6Setting32 |= MR6_DDR4_TCCDL6;      //tCCD_L = 6
			break;
		case DRAM_FREQ_2666: 
			MR6Setting32 |= MR6_DDR4_TCCDL7;      //tCCD_L = 7
			break;
		case DRAM_FREQ_2933: 
			MR6Setting32 |= MR6_DDR4_TCCDL8;      //tCCD_L = 8
			break;
		case DRAM_FREQ_3200: 
			MR6Setting32 |= MR6_DDR4_TCCDL8;      //tCCD_L = 8
			break;
		default:
			MR6Setting32 |= MR6_DDR4_TCCDL6;
			break;		
	}

	if(ActionType8 & VREF_TRAIN_EN)
		MR6Setting32 |= MR6_DDR4_VREF_TRAIN_EN;

	if(ActionType8 & VREF_RANGE1)
		MR6Setting32 |= MR6_DDR4_VREF_RANGE1;
	else if(ActionType8 & VREF_RANGE2)
		MR6Setting32 |= MR6_DDR4_VREF_RANGE2;

	//VrefDQ Value
	//BG1      BG0      BA1         BA0    MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
	//15^20,  14^7,    18^23,	 17^22,     23	 22,  21, 20,   12,  11,  10,   9,  8,	 7,   6,   5,  4, 	3 
	//
	//MA05 MA04 MA03 MA02 MA01 MA00
	// 10,  9,   8,   5,   4,   3 	
    //MA02-MA00 
    /*MR6Setting32 |= ((VrefDQ & 0x07) << 3);*/

    /*MR6Setting32 |= ((VrefDQ & 0x38) << 5); */

	//modify by rkd
	//CHX002
	//MA05 MA04 MA03 MA02 MA01 MA00
	// 8,  7,   6,   5,   4,   3 	
    MR6Setting32 |= VrefDQ  << MA00;
	//or use those
    /*MR6Setting32 |= ((VrefDQ & 0x07) << MA00);*/
    /*MR6Setting32 |= ((VrefDQ & 0x38) << MA02); */
	
    MR6Setting32 |= GetMrsNo(MR6Setting32, 6);
	return MR6Setting32;
}

UINT32 Rank1AddressMirror(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT32 MRSValue32)
{
	//Typical MA mapping for a MRS command
	//MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
    //                   23    22,     21,     20,    12,    11,    10,    9,     8,       7,     6,     5,      4,     3 

	//For Rank1 Address Mapping, the address pin is mirroed as follows.
	//Standard	MA3    	MA4    	MA5    	MA6    	MA7    	MA8    	MA11     MA13    
	//			 6		 7		 8		 9		10		11		 21		  23       
	//-----------------------------------------------------------------------
	//Mirrored	MA3    	MA4    	MA5    	MA6    	MA7    	MA8    	MA11     MA13    
	//			 7		  6		 9		 8		11		10		 23	       21       

	UINT32 	MirroredMRSValue32=MRSValue32;
    UINT32 Tmp32 = 0;
	//Check Original MA3 (BIT 6), if 1 then Mirrored MA3 (BIT 7) = 1, else clear to 0
	if (MRSValue32 & BIT6)
		MirroredMRSValue32 |= BIT7;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT7);

	//Check Original MA4 (BIT 7), if 1 then Mirrored MA4 (BIT 6) = 1, else clear to 0
	if (MRSValue32 & BIT7)
		MirroredMRSValue32 |= BIT6;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT6);

	//Check Original MA5 (BIT 8), if 1 then Mirrored MA5 (BIT 9) = 1, else clear to 0
	if (MRSValue32 & BIT8)
		MirroredMRSValue32 |= BIT9;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT9);

	//Check Original MA6 (BIT 9), if 1 then Mirrored MA6 (BIT 8) = 1, else clear to 0
	if (MRSValue32 & BIT9)
		MirroredMRSValue32 |= BIT8;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT8);

	//Check Original MA7 (BIT 10, if 1 then Mirrored MA7 (BIT 11) = 1, else clear to 0
	if (MRSValue32 & BIT10)
		MirroredMRSValue32 |= BIT11;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT11);

	//Check Original MA8 (BIT 11), if 1 then Mirrored MA8 (BIT 10) = 1, else clear to 0
	if (MRSValue32 & BIT11)
		MirroredMRSValue32 |= BIT10;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT10);
	//Check Original MA11 (BIT 21), if 1 then Mirrored MA11 (BIT 23) = 1, else clear to 0
	if (MRSValue32 & BIT21)
		MirroredMRSValue32 |= BIT23;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT23);

	//Check Original MA13 (BIT 23), if 1 then Mirrored MA13 (BIT 21) = 1, else clear to 0
	if (MRSValue32 & BIT23)
		MirroredMRSValue32 |= BIT21;
	else
		MirroredMRSValue32 &= (UINT32)(~BIT21);






	
	//BG1 		BG0		 BA1	       	BA0
	//15^20      14 ^7        18^23          17^22

	//BA0--> BIT18
    Tmp32 = ((MRSValue32 & BIT17)>>17)^((MRSValue32 & BIT22)>>22);
    Tmp32 = Tmp32 ^ ((MirroredMRSValue32 & BIT23)>>23);
	if(Tmp32)
		MirroredMRSValue32 |= BIT18;
	else
	    MirroredMRSValue32 &= (UINT32)(~BIT18);
	


    //BA1--> BIT17
    Tmp32 = ((MRSValue32 & BIT18)>>18)^((MRSValue32 & BIT23)>>23);
    Tmp32 = Tmp32 ^ ((MirroredMRSValue32 & BIT22)>>22);
	if(Tmp32)
		MirroredMRSValue32 |= BIT17;
	else
	    MirroredMRSValue32 &= (UINT32)(~BIT17);
	

	//BG0--> BIT15
    Tmp32 = ((MRSValue32 & BIT7)>>7)^((MRSValue32 & BIT14)>>14);
    Tmp32 = Tmp32 ^ ((MirroredMRSValue32 & BIT20)>>20);
	if(Tmp32)
		MirroredMRSValue32 |= BIT15;
	else
	    MirroredMRSValue32 &= (UINT32)(~BIT15);


	//BG1--> BIT14
    Tmp32 = ((MRSValue32 & BIT15)>>15)^((MRSValue32 & BIT20)>>20);
    Tmp32 = Tmp32 ^ ((MirroredMRSValue32 & BIT7)>>7);
	if(Tmp32)
		MirroredMRSValue32 |= BIT14;
	else
	    MirroredMRSValue32 &= (UINT32)(~BIT14);
	

	

	return MirroredMRSValue32;
}

UINT32 SideBAddressInvert(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT32 MRSValue32)
{   
	//Inverted Address Pin
    //BG1 	   BG0	 BA1	      BA0     MA13 MA11 MA09 MA08 MA07 MA06 MA05 MA04 MA03
    //15^20   14 ^7   18^23   17^22     23,    21,   12,     11,    10,    9,     8,       7,     6,       	


    //Need invert CPU Address
    //BG1 	   BG0	 BA1	      BA0     MA13 MA11 MA09 MA08 MA07 MA06 MA05 MA04 MA03
    //15           NA       NA        17       23,    21,   12,     11,    10,    9,     8,       7,     6,       
	UINT32 InvertValue; 
	//1010 0010 1001 1111 1100 0000
	InvertValue = 0xA29FC0;


	//BA0--> BIT18
    //Tmp32 = ((MRSValue32 & BIT17)>>17)^((MRSValue32 & BIT22)>>22);
    //Tmp32 = Tmp32 ^ ((MRSValue32 & BIT23)>>23);
	//if(Tmp32)
		//MirroredMRSValue32 |= BIT18;
	//else
	    //MirroredMRSValue32 &= (UINT32)(~BIT18);

	return (MRSValue32 ^ InvertValue);
}

VOID HwInitDRAMByRank(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8  RankIdx8;
	UINT16  PageMode;
	UINT64 Address;

	// Clear all PR-to-VR Mapping
	for (RankIdx8=0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++)
		SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, 0x00, FALSE);

	// save page mode
	//RX145[3]
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	PageMode = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RPGEN;

	// disable page mode
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, 0);

	// disable RODTEN
	//RX192[7]
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, 0);

	// enable By-Rank Hardware Initialization control
	//RX196[7]
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMINIT_BYRANK, D0F3_RDMINIT_BYRANK);


	//Rx19A[1] = 0
	/*
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V); 
    if(!DramAttr->ConfigData.CPU_FSBC_ON)
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RRDFIFOEN,0);
	else
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RRDFIFOEN,D0F3_RRDFIFOEN);	
	*/
	

	if(DramAttr->RegDimm != IS_REG_DIMM)
	{
		if (DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0)
		{
			//LGE-20151225  Toggle RESET
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, 0);
			//delay 200us
			WaitForMicroSec(PeiServices, 200);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, D0F3_RMEMRSTN);
			//delay 500us
			WaitForMicroSec(PeiServices, 500);
		}
		
		if (DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0)
		{
			//LGE-20151225  Toggle RESET
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN_CHB, 0);
			//delay 200us
			WaitForMicroSec(PeiServices, 200);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN_CHB, D0F3_RMEMRSTN_CHB);
			//delay 500us
			WaitForMicroSec(PeiServices, 500);
		}	
		
    }
	
	// Map each Physical Rank N to Virtual Rank 0 in each loop
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ) {	//Init Only when RankPresent

			//LGE20160406 Enable TargetRank, and disable other rank, To avoid all the rank be disable
            EnableTargetRank(PeiServices, pPCIPPI, DramAttr, RankIdx8);	
			if(RankIdx8<4)//ChA
				HwInitDdr4Sequence(PeiServices, pCPUPPI, pPCIPPI, DramAttr, ChA, RankIdx8);
			else//ChB
				HwInitDdr4Sequence(PeiServices, pCPUPPI, pPCIPPI, DramAttr, ChB, RankIdx8);
		
		}
	}

	// Set Virtual Rank Enable and map as Physical Rank
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		if ( DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ) {
			SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, RankIdx8,TRUE);
		}
	}

	// disable Swap MA
	//RX194[10]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL); 
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMAMIR, 0);

	// disable By-Rank Hardware Initialization control
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMINIT_BYRANK, 0);

	// enable RODTEN
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTEN, D0F3_RODTEN);

	// restore page mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, PageMode);
	return;
}

VOID HwInitDdr4Sequence(
    IN EFI_PEI_SERVICES **PeiServices,
    IN PEI_CPU_IO_PPI *pCPUPPI,			
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr,
    IN UINT8 ChIndex,
    IN UINT8 RankIndex)
{
	UINT16  Temp16 = 0;
	UINT64  Address;

	//deassert RESET# Rx194[5]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);	
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RMEMRSTN, D0F3_RMEMRSTN);

	//Set MR1[A10,A9,A8],Rtt_Nom
	//RX196[6:4]
	if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_DIS)
		Temp16= D0F3_NOM_RTT_DIS;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_60OHM)
		Temp16= D0F3_NOM_RTT_60OHM;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_120OHM)
		Temp16= D0F3_NOM_RTT_120OHM;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_40OHM)
		Temp16= D0F3_NOM_RTT_40OHM;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_240OHM)
		Temp16= D0F3_NOM_RTT_240OHM;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_48OHM)
		Temp16= D0F3_NOM_RTT_48OHM;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_80OHM)
		Temp16= D0F3_NOM_RTT_80OHM;
	else if (DramAttr->RttNominal[DramAttr->AttrNo][RankIndex] == MR1_DDR4_RTT_NOM_34OHM)
		Temp16= D0F3_NOM_RTT_34OHM;

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRRTT_2_0, Temp16);

	//Set MR1[A2,A1],OutputDriver 
	//RX196[3:2]
	if(DramAttr->OutputDriver[DramAttr->AttrNo][RankIndex>>1] == MR1_DDR4_RZQ7)
		Temp16 = 0;
	else if(DramAttr->OutputDriver[DramAttr->AttrNo][RankIndex>>1] == MR1_DDR4_RZQ5)
		Temp16 = BIT2;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRODS_1_0, Temp16);

	//Set MR2[A10,A9],Rtt_WR
	//RX196[11:13] 
	if(DramAttr->RttWR[DramAttr->AttrNo][RankIndex]== MR2_DDR4_RTT_WR_DIS)
		Temp16 = D0F3_WR_RTT_DIS;
	else if(DramAttr->RttWR[DramAttr->AttrNo][RankIndex]== MR2_DDR4_RTT_WR_120OHM)
		Temp16 = D0F3_WR_RTT_120OHM;
	else if(DramAttr->RttWR[DramAttr->AttrNo][RankIndex]== MR2_DDR4_RTT_WR_240OHM)
		Temp16 = D0F3_WR_RTT_240OHM;
	else if(DramAttr->RttWR[DramAttr->AttrNo][RankIndex]== MR2_DDR4_RTT_WR_80OHM)
		Temp16 = D0F3_WR_RTT_80OHM;
	else if(DramAttr->RttWR[DramAttr->AttrNo][RankIndex]== MR2_DDR4_RTT_WR_HIGHZ)
		Temp16 = D0F3_WR_RTT_HIZ;
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMRRTTWR_2_0 , Temp16);

	//MR5[A8:A6],Rtt_PARK
	//RX198[8:10]
	if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_DIS)
		Temp16 = D0F3_PARK_RTT_DIS;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_60OHM)
		Temp16 = D0F3_PARK_RTT_60OHM;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_120OHM)
		Temp16 = D0F3_PARK_RTT_120OHM;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_40OHM)
		Temp16 = D0F3_PARK_RTT_40OHM;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_240OHM)
		Temp16 = D0F3_PARK_RTT_240OHM;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_48OHM)
		Temp16 = D0F3_PARK_RTT_48OHM;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_80OHM)
		Temp16 = D0F3_PARK_RTT_80OHM;
	else if(DramAttr->RttPark[DramAttr->AttrNo][RankIndex] == MR5_DDR4_RTT_PARK_34OHM)
		Temp16 = D0F3_PARK_RTT_34OHM;
	Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);    
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPARK_RTT_2_0, Temp16);

	//RX119[10]Swap MA
	if(DramAttr->Rank1Mapping[DramAttr->AttrNo][RankIndex]== RANK1_MAPPING_MIRRORED)        
		//LGE20160312
		Temp16 = D0F3_RDMAMIR;	
	else
		Temp16 = 0;		
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMAMIR, Temp16); 

	
	if(ChIndex==ChA)
	{
		//trigger, set RDMINIT 1
		//RX196[0]
		Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMINIT, D0F3_RDMINIT);
		
		//wait for CHA finish
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_RDMINIT_STATUS)!= 0);

		if(DramAttr->RegDimm == IS_REG_DIMM){
		
				//Set Init B side
				Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MISC_CTL);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBSIDE, D0F3_RBSIDE);			
				////trigger, set RDMINIT 1
				//RX16E[0]
				Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMINIT, D0F3_RDMINIT);
		
				//wait for CHA finish
				do{
					Temp16 = 0;
					Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
				}while((Temp16 & D0F3_RDMINIT_STATUS)!= 0);
				
				//Disable Init B side
				Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MISC_CTL);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBSIDE, 0);
			}
	}
	else//CHB
	{
		//trigger, set RDMINIT
		//RX196[14]
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
				D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMINIT_CHB, D0F3_RDMINIT_CHB);

		//wait for CHB finish
		do{
			Temp16 = 0;
			Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
		}while((Temp16 & D0F3_RDMINIT_STATUS_CHB)!= 0);

		if(DramAttr->RegDimm == IS_REG_DIMM){

			//Set Init B side
			Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MISC_CTL);
            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBSIDE, D0F3_RBSIDE);			
			//trigger, set RDMINIT		  
		    Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I);
		    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMINIT_CHB, D0F3_RDMINIT_CHB);
			//wait for CHB finish,RX16F[7]
			do{
				Temp16 = 0;
				Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress,Address);
			}while((Temp16 & D0F3_RDMINIT_STATUS_CHB)!= 0);

            //Disable Init B side
            Address = AsiaPciAddress( DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MISC_CTL);
            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBSIDE, 0);
			
		}

		
	}
	return;
}
