/** @file
   ZX-E(CHX002) Asia SbPei library functions : SbPmio.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
/*
\license
*/
#include "Pei.h"
#include "CHX002Reg.h"
#include "AsiaIoLib.h"
#include "SbLibPpi.h"

// In CHX002 SB, we have 9 GPI,13 GPO and 51 GPIO
// GPIO 0~7       input: PMIO_Rx48[10:17]     output: PMIO_Rx4C[11:18]
// GPIO 10~13     input: PMIO_Rx48[20,23]  output: PMIO_Rx4C[21,24]
// GPIO 14		  input: PMIO_Rx48[28]  output: PMIO_Rx4C[27]
// GPIO 26~32      input: PMIO_Rx3C[9:15]      output: PMIO_Rx3C[25:31]
// GPIO 33     input: PMIO_Rx46[0]  output: PMIO_Rx47[0]
// GPIO 36~37      input: PMIO_Rx46[3:4]       output: PMIO_Rx47[3:4]
// GPIO 39~40,44~54,56,75~88     
// GPI  0~7       input: PMIO_Rx48[0:7]
// GPI  10   input: PMIO_Rx4B[0]
// GPO  0~7                                    output: PMIO_Rx4C[0:7]
// GPO  36~40                                  output: PMIO_Rx83[0:4]

/**
  SB PEIM Set GPO function.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Index
  @param Value

  @return EFI_STATUS.

**/

EFI_STATUS
PeiSbSetGpo (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_GPIO Index,
    IN BOOLEAN Value
)
{
    UINT16 PmioBar;
	UINT32 SbMmioBar,Buffer32;
	SbMmioBar = (AsiaPciRead32(CHX002_BUSC|D17F0_MMIO_SPACE_BASE_ADR))<<8;
	
	if(Index > GPO_40)
        return EFI_INVALID_PARAMETER;
	
    if((Index >=  GPI_00) && (Index <= GPI_10 ))  
        return EFI_UNSUPPORTED;
	
    PmioBar = AsiaPciRead16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE);
	PmioBar &= D17F0_PMU_PMIOBA;	

    switch(Index)
    {
        case GPIO_00:
			AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN0, BIT16); //Enable PCIe Port 0 CLK Request Contro
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17); //PAD Control Register:ADDR
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT6);// PMIO Rx8C[6] == 1'b0
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
	        AsiaIoModify8(PmioBar + GPIO_00_OUT_REG, BIT3, (Value ? GPIO_00_OUT_DAT : 0));//PMIO Rx4D[3]
			break;
        case GPIO_01:
			AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN1, BIT17); //Enable PCIe Port 1 CLK Request Contro
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT7);//PMIO Rx8C[7] == 1'b0
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
     	   AsiaIoModify8(PmioBar + GPIO_01_OUT_REG, BIT4, (Value ? GPIO_01_OUT_DAT : 0));//PMIO Rx4D[4]
			break;
        case GPIO_02:
			AsiaPciModify8(CHX002_BUSC | GPIO_02_SEL_REG, BIT6, GPIO_02_SEL_DAT);//D17F0 Rx97[6]* = 1 ((ENGPIO23))
            AsiaIoModify8(PmioBar + GPIO_02_OUT_REG, BIT5, (Value ? GPIO_02_OUT_DAT : 0));//PMIO Rx4D[5]
			break;
        case GPIO_03:
		   AsiaPciModify8(CHX002_BUSC | GPIO_03_SEL_REG, BIT6, GPIO_03_SEL_DAT);//D17F0 Rx97[6]* = 1 ((ENGPIO23))
			AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN5, 0);//PMIO RxBC[21] = 1'b0
           AsiaIoModify8(PmioBar + GPIO_03_OUT_REG, BIT6, (Value ? GPIO_03_OUT_DAT : 0));//PMIO Rx4D[6]
			break;
        case GPIO_04:
			AsiaPciModify8(CHX002_BUSC | GPIO_04_SEL_REG, BIT0, GPIO_04_SEL_DAT);//D17F0 Rx97[0]* = 1 ((ENGPIO45))
			 AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN3, 0);//PMIO RxBC[19] = 1'b0
            AsiaIoModify8(PmioBar + GPIO_04_OUT_REG, BIT7, (Value ? GPIO_04_OUT_DAT : 0));//PMIO Rx4D[7]
			break;
        case GPIO_05:
			AsiaPciModify8(CHX002_BUSC | GPIO_05_SEL_REG, BIT0, GPIO_05_SEL_DAT);//D17F0 Rx97[0]* = 1 ((ENGPIO45))
			 AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN4, 0);//PMIO RxBC[20] = 1'b0
          AsiaIoModify8(PmioBar + GPIO_05_OUT_REG, BIT0, (Value ? GPIO_05_OUT_DAT : 0));//PMIO Rx4E[0]
			break;
        case GPIO_06:
		  AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT16);// PMIO Rx94[27:0] == 28'h00010000 
		   //PAD Control Regsiter: Data
		  Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		  Buffer32 &= ~(BIT31+BIT30);
		  Buffer32 |= BIT30;//PMIO Rx8C[31:30] == 2'b01
		  AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		  AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		  AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		  AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
          AsiaIoModify8(PmioBar + GPIO_06_OUT_REG, BIT1, (Value ? GPIO_06_OUT_DAT : 0));//PMIO Rx4E[1]*
			break;
        case GPIO_07:
			AsiaIoModify8(PmioBar +GPIO_07_SEL_REG, PMIO_PAD_PCI_GPIO7, BIT0);//PMIO RxBC[0]  = 1'b1
            AsiaIoModify8(PmioBar + GPIO_07_OUT_REG, BIT2, (Value ? GPIO_07_OUT_DAT : 0));//PMIO Rx4C[18]
       
        case GPIO_10:
			AsiaIoModify32(PmioBar + GPIO_10_SEL_REG, PMIO_PAD_GPIO10_2_1_0, 0);//PMIO RxB4[18:16] = 3'b000
            AsiaIoModify8(PmioBar + GPIO_10_OUT_REG, BIT5, (Value ? GPIO_10_OUT_DAT : 0));//PMIO Rx4E[5]
			break;
        case GPIO_11:
			AsiaIoModify32(PmioBar + GPIO_11_SEL_REG, PMIO_PAD_GPIO11_2_1_0, 0);//PMIO RxB4[21:19] = 3'b000
            AsiaIoModify8(PmioBar + GPIO_11_OUT_REG, BIT6, (Value ? GPIO_11_OUT_DAT : 0));//PMIO Rx4E[6]
			break;
        case GPIO_12:
			AsiaIoModify32(PmioBar + GPIO_12_SEL_REG, PMIO_PAD_GPIO12_2_1_0, 0);//PMIO RxB4[26:24] = 3'b000
            AsiaIoModify8(PmioBar + GPIO_12_OUT_REG, BIT7, (Value ? GPIO_12_OUT_DAT : 0));//PMIO Rx4E[7]
			break;
        case GPIO_13:
			AsiaIoModify32(PmioBar +  GPIO_13_SEL_REG, PMIO_PAD_GPIO13_2_1_0, 0);  //PMIO RxB4[29:27] = 3'b000	
            AsiaIoModify8(PmioBar + GPIO_13_OUT_REG, BIT0, (Value ? GPIO_13_OUT_DAT : 0));//PMIO Rx4F[0]
			break;
        case GPIO_14:
			AsiaIoModify32(PmioBar +  GPIO_14_SEL_REG, PMIO_PAD_GPIO14_2_1_0, 0);  //PMIO RxB8[2:0] = 3'b000		
            AsiaIoModify8(PmioBar + GPIO_14_OUT_REG, BIT3, (Value ? GPIO_14_OUT_DAT : 0));//PMIO Rx4F[3]
			break;
       
		case GPIO_26:
			AsiaIoModify8(PmioBar +  GPIO_26_SEL_REG, PMIO_PAD_GPIO26_2_1_0, BIT3);////PMIO RxB8[5:3] = 3'b001 
            AsiaIoModify8(PmioBar + GPIO_26_OUT_REG, BIT1, (Value ? GPIO_26_OUT_DAT : 0));//PMIO Rx3C[25]
			break;
		case GPIO_27:
			AsiaIoModify32(PmioBar +  GPIO_27_SEL_REG, PMIO_PAD_GPIO27_2_1_0, BIT8);//PMIO RxB8[10:8] = 3'b001
            AsiaIoModify8(PmioBar + GPIO_27_OUT_REG, BIT2, (Value ? GPIO_27_OUT_DAT : 0));//PMIO Rx3C[26]
			break;
		case GPIO_28:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT27);// PMIO Rx94[27:0] == 28'h08000000 
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT26);
			Buffer32 |= BIT26;//PMIO Rx8C[26] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			AsiaIoModify8(PmioBar + GPIO_28_OUT_REG, BIT3, (Value ? GPIO_28_OUT_DAT : 0));////PMIO Rx3C[27]
			break;
		case GPIO_29:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT27);
			//PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT28);
			Buffer32 |= BIT28;//PMIO Rx8C[28] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
           AsiaIoModify8(PmioBar + GPIO_29_OUT_REG, BIT4, (Value ? GPIO_29_OUT_DAT : 0));//PMIO Rx3C[28]
			break;
		case GPIO_30:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT27);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT30);
			Buffer32 |= BIT30;//PMIO Rx8C[30] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPIO_30_OUT_REG, BIT5, (Value ? GPIO_30_OUT_DAT : 0));//PMIO Rx3C[29]
			break;
		case GPIO_31:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);//PMIO Rx94[27:0] == 28'h00020000 
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT23);
			Buffer32 |= BIT23;// PMIO Rx8C[23] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPIO_31_OUT_REG, BIT6, (Value ? GPIO_31_OUT_DAT : 0));//PMIO Rx3C[30]
			break;
		case GPIO_32:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);// PMIO Rx94[27:0] == 28'h00020000
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT30);
			Buffer32 |= BIT30;//PMIO Rx8C[30] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPIO_32_OUT_REG, BIT7, (Value ? GPIO_32_OUT_DAT : 0));//PMIO Rx3C[31]
			break;
		case GPIO_33:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);//PMIO Rx94[27:0] == 28'h00020000 
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT31);
			Buffer32 |= BIT31;// PMIO Rx8C[31] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPIO_33_OUT_REG, BIT0, (Value ? GPIO_33_OUT_DAT : 0));//PMIO Rx47[0]
			break;
		
        case GPIO_36:
			AsiaIoModify32(PmioBar + GPIO_36_SEL_REG, PMIO_P2G_GPIO36_2_1_0, 0);//PMIO Rx9B[2:0]=3'b000
            AsiaIoModify8(PmioBar + GPIO_36_OUT_REG, BIT3, (Value ? GPIO_36_OUT_DAT : 0));//PMIO Rx47[3]
			break;
        case GPIO_37:
			AsiaIoModify32(PmioBar + GPIO_37_SEL_REG, PMIO_P2G_GPIO37_2_1_0, 0);//PMIO Rx9A[2:0]=3'b000
            AsiaIoModify8(PmioBar + GPIO_37_OUT_REG, BIT4, (Value ? GPIO_37_OUT_DAT : 0));//PMIO Rx47[4]
			break;
		case GPIO_39:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT11+BIT12+BIT13);// PMIO Rx8C[13:11] == 3'b000
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
 			Buffer32 &= ~(BIT7);
			Buffer32 |= (Value ? BIT7 : 0);//PMIO Rx8C[7]
            AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF,Buffer32);
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
			break; 
	case GPIO_40:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT16+BIT17+BIT18);// PMIO Rx8C[18:16] == 3'b000
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT8);
		Buffer32 |= (Value ? BIT8 : 0);//PMIO Rx8C[8] 
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	
	case GPIO_44:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);//PMIO Rx94[27:0] == 28'h00040000
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT0+BIT1+BIT2);// PMIO Rx8C[2:0] == 3'b000
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT12);
		Buffer32 |= (Value ? BIT12 : 0);//PMIO Rx8C[12]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_45:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT3+BIT4+BIT5);//PMIO Rx8C[5:3] == 3'b000
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT13);
		Buffer32 |= (Value ? BIT13 : 0);//PMIO Rx8C[13]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_46:		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT14);//PMIO Rx8C[14] 
		Buffer32 |= (Value ? BIT14 : 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_47:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT11+BIT12+BIT13);
		Buffer32 |=BIT11;// PMIO Rx8C[13:11] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);		
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT15);
		Buffer32 |= (Value ? BIT15 : 0);// PMIO Rx8C[15]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_48:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT16+BIT17+BIT18);
		Buffer32 |= BIT16;//PMIO Rx8C[18:16] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT16);
		Buffer32 |= (Value ? BIT16 : 0);//PMIO Rx8C[16]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_49:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT19+BIT20+BIT21);
		Buffer32 |= BIT19;// PMIO Rx8C[21:19] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT17);
		Buffer32 |= (Value ? BIT17 : 0);//PMIO Rx8C[17]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_50:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT24+BIT25+BIT26);
		Buffer32 |= BIT24;// PMIO Rx8C[26:24] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT18);
		Buffer32 |= (Value ? BIT18 : 0);//PMIO Rx8C[18] 
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_51:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT27+BIT28+BIT29);
		Buffer32 |= BIT27;//PMIO Rx8C[29:27] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT19);
		Buffer32 |= (Value ? BIT19 : 0);// PMIO Rx8C[19] 
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_52:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT0+BIT1+BIT2);
		Buffer32 |= BIT0;//PMIO Rx8C[2:0] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT20);
		Buffer32 |= (Value ? BIT20 : 0);//PMIO Rx8C[20]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_53:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT3+BIT4+BIT5);
		Buffer32 |= BIT3;// PMIO Rx8C[5:3] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT21);
		Buffer32 |= (Value ? BIT21 : 0);//PMIO Rx90[21]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_54:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT8+BIT9+BIT10);
		Buffer32 |= BIT8;// Rx8C[10:8] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT22);
		Buffer32 |= (Value ? BIT22 : 0);//PMIO Rx90[22]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;

	case GPIO_55:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT23);
		Buffer32 |= (Value ? BIT23 : 0);//PMIO Rx90[23]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			


	case GPIO_56:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT16+BIT17+BIT18);
		Buffer32 |= BIT16;// PMIO Rx8C[18:16] == 3'b001
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT21);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT24);
		Buffer32 |= (Value ? BIT24 : 0);////PMIO Rx90[24]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	
	case GPIO_75:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT31);
		Buffer32 |= BIT31;//PMIO Rx8C[31] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT11);
		Buffer32 |= (Value ? BIT11: 0);///PMIO Rx90[11]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_76:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT6);
		Buffer32 |= BIT6;//PMIO Rx8C[6] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT12);
		Buffer32 |= (Value ? BIT12: 0);////PMIO Rx90[12]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_77:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT7);
		Buffer32 |= BIT7;//PMIO Rx8C[7] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT13);
		Buffer32 |= (Value ? BIT13: 0);////PMIO Rx90[13]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_78:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT14);
		Buffer32 |= BIT14;//PMIO Rx8C[14] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);

		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT14);
		Buffer32 |= (Value ? BIT14: 0);//PMIO Rx90[14]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_79:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT15);
		Buffer32 |= BIT15;//PMIO Rx8C[15] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT15);
		Buffer32 |= (Value ? BIT15: 0);//PMIO Rx90[15]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_80:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT22);
		Buffer32 |= BIT22;//PMIO Rx8C[22] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT16);
		Buffer32 |= (Value ? BIT16: 0);//PMIO Rx90[16]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	
	case GPIO_83:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT31);
		Buffer32 |= BIT31;// PMIO Rx8C[31] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT19);
		Buffer32 |= (Value ? BIT19: 0);//PMIO Rx90[19]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_84:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT6);
		Buffer32 |= BIT6;//PMIO Rx8C[6] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT20);
		Buffer32 |= (Value ? BIT20: 0);//PMIO Rx90[20]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_85:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT7);
		Buffer32 |= BIT7;//PMIO Rx8C[7] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT21);
		Buffer32 |= (Value ? BIT21: 0);//PMIO Rx90[21]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_86:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT14);
		Buffer32 |= BIT14;//PMIO Rx8C[14] == 1'b1
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT22);
		Buffer32 |= (Value ? BIT22: 0);//PMIO Rx90[22]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_87:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT22+BIT23);
		Buffer32 |= BIT22;//PMIO Rx8C[23:22] == 2'b01
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT23);
		Buffer32 |= (Value ? BIT23: 0);//PMIO Rx90[23]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
	case GPIO_88:
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
		 //PAD Control Regsiter: Data
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT30+BIT31);
		Buffer32 |= BIT30;//PMIO Rx8C[31:30] == 2'b01
		AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
		
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT22);
		Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
		Buffer32 &= ~(BIT24);
		Buffer32 |= (Value ? BIT24: 0);//PMIO Rx90[24]
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
		AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			
		break;
        case GPO_00:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MULTI_FUN_SEL_2, D17F0_PMU_ENGPO123, BIT1);//D17F0 RxE4[1] = 1
            AsiaIoModify8(PmioBar + GPO_00_OUT_REG, BIT0, (Value ? GPO_00_OUT_DAT : 0));//PMIO Rx4C[0]
			break;
        case GPO_01:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MULTI_FUN_SEL_2, D17F0_PMU_ENGPO123, BIT1);//D17F0 RxE4[1] = 1
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT16);// PMIO Rx94[27:0] == 28'h00010000
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT30+BIT31);
			Buffer32 |= BIT30;//Rx8C[31:30] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPO_01_OUT_REG, BIT1, (Value ? GPO_01_OUT_DAT : 0));//PMIO Rx4C[1]
			break;
        case GPO_02:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MULTI_FUN_SEL_2, D17F0_PMU_ENGPO123, BIT1);//D17F0 RxE4[1] = 1
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT15);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT29+BIT28);
			Buffer32 |= BIT28;// PMIO Rx8C[29:28] == 2'b01
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPO_02_OUT_REG, BIT2, (Value ? GPO_02_OUT_DAT : 0));//PMIO Rx4C[2]
			break;
        case GPO_03:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MULTI_FUN_SEL_2, D17F0_PMU_ENGPO123, BIT1);//D17F0 RxE4[1] = 1
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT15);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT31+BIT30);
			Buffer32 |= BIT30;//PMIO Rx8C[31:30] == 2'b01
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPO_03_OUT_REG, BIT3, (Value ? GPO_03_OUT_DAT : 0));//PMIO Rx4C[3]
			break;
		case GPO_04:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MISC_CFG_2_PWR_WELL, D17F0_PMU_ENGPO4, GPO_04_SEL_DAT);// D17F0 Rx95[1]* =1'b1
			AsiaIoModify8(PmioBar + PMIO_SUSPEND_PWR_DOMAIN, PMIO_ENSUSSTAT, 0);//PMIO Rx6F[0]*=1'b0
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MISC_CFG_1_PWR_WELL, D17F0_PMU_GPO4S1S0, 0);//D17F0 Rx94[1:0]* = 2'b00
			AsiaIoModify8(PmioBar + GPO_04_OUT_REG, BIT4, (Value ? GPO_04_OUT_DAT : 0));
			break;
        case GPO_05:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MISC_CFG_1_PWR_WELL, D17F0_PMU_ENGPO56, BIT2);//D17F0 Rx94[2] = 1
            AsiaIoModify8(PmioBar + GPO_05_OUT_REG, BIT5, (Value ? GPO_05_OUT_DAT : 0));//PMIO Rx4C[5]
			break;
        case GPO_06:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MISC_CFG_1_PWR_WELL, D17F0_PMU_ENGPO56, BIT2);//D17F0 Rx94[2] = 1
            AsiaIoModify8(PmioBar + GPO_06_OUT_REG, BIT6, (Value ? GPO_06_OUT_DAT : 0));//PMIO Rx4C[6]
			break;
        case GPO_07:
			AsiaIoModify32(PmioBar +PMIO_UART_PAD_CTL, PMIO_PAD_VRDSLP_GPO7, 0);//PMIO RxC0[27]=0
            AsiaIoModify8(PmioBar + GPO_07_OUT_REG, BIT7, (Value ? GPO_07_OUT_DAT : 0));
			break;
        case GPO_36:
			AsiaIoModify32(PmioBar +PMIO_GPIO_PAD_CTL, PMIO_PAD_GPO36_2_1_0, 0);//PMIO RxB8[13:11] =0
			AsiaIoModify32(PmioBar + GPO_36_SEL_REG, PMIO_PAD_GPO36_2_1_0, GPO_36_SEL_DAT);
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT14);//PMIO Rx94[27:0] == 28'h00004000 
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT27);
			Buffer32 |= BIT27; //PMIO Rx8C[27] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			AsiaIoModify8(PmioBar + GPO_36_OUT_REG, BIT0, (Value ? GPO_36_OUT_DAT : 0));//PMIO Rx83[0]
			break;
        case GPO_37:
			AsiaIoModify32(PmioBar +PMIO_GPIO_PAD_CTL, PMIO_PAD_GPO37_2_1_0, 0);//PMIO RxB8[18:16] =0
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT14);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT28);
			Buffer32 |= BIT28;//PMIO Rx8C[28] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPO_37_OUT_REG, BIT1, (Value ? GPO_37_OUT_DAT : 0));//PMIO Rx83[1]
			break;
        case GPO_38:
			AsiaIoModify32(PmioBar +PMIO_GPIO_PAD_CTL, PMIO_PAD_GPO38_2_1_0, 0);//PMIO RxB8[21:19] =0
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT14);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT29);
			Buffer32 |= BIT29;
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPO_38_OUT_REG, BIT2, (Value ? GPO_38_OUT_DAT : 0));//PMIO Rx83[2]
			break;
        case GPO_39:
			AsiaIoModify32(PmioBar +PMIO_GPIO_PAD_CTL, PMIO_PAD_GPO39_2_1_0, 0);//PMIO RxB8[26:24] =0
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT14);
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT14);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT30);
			Buffer32 |= BIT30;//PMIO Rx8C[30] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			AsiaIoModify8(PmioBar + GPO_39_OUT_REG, BIT3, (Value ? GPO_39_OUT_DAT : 0));//PMIO Rx83[3]
			break;
        case GPO_40:
			AsiaIoModify32(PmioBar +PMIO_GPIO_PAD_CTL, PMIO_PAD_GPO40_2_1_0, 0);//PMIO RxB8[29:27] =0
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT31);
			Buffer32 |= BIT31;//PMIO Rx8C[31] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
            AsiaIoModify8(PmioBar + GPO_40_OUT_REG, BIT4, (Value ? GPO_40_OUT_DAT : 0));//PMIO Rx83[4]
			break;
        default:
			break;
	}

    return EFI_SUCCESS;
}

/**
  SB PEIM Get GPI function.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Index
  @param Value

  @return EFI_STATUS.

**/

EFI_STATUS
PeiSbGetGpi (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_GPIO Index,
    OUT BOOLEAN* Value
)
	{
		UINT16 PmioBar;
		UINT8 Reg8;
		UINT32 Reg32,Buffer32;
		
		if(Index > GPO_00)
			return EFI_INVALID_PARAMETER;
		
		PmioBar = AsiaPciRead16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE);
		PmioBar &= D17F0_PMU_PMIOBA;	
	
		switch(Index)
		{
			case GPIO_00:
				AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN0, BIT16); //Enable PCIe Port 0 CLK Request Contro
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17); //PAD Control Register:ADDR
				 //PAD Control Regsiter: Data
				Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				Buffer32 &= ~(BIT6);// PMIO Rx8C[6] == 1'b0
				AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				Reg8 = AsiaIoRead8(PmioBar + GPIO_00_IN_REG);
				*Value = (Reg8 & BIT2) ? TRUE : FALSE;//PMIO Rx49[2]
				break;
			case GPIO_01:
				AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN1, BIT17); //Enable PCIe Port 1 CLK Request Contro
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);
				 //PAD Control Regsiter: Data
				Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				Buffer32 &= ~(BIT7);//PMIO Rx8C[7] == 1'b0
				AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				Reg8 = AsiaIoRead8(PmioBar + GPIO_01_IN_REG);
				*Value = (Reg8 & BIT3) ? TRUE : FALSE;//PMIO Rx49[3]
				break;
			case GPIO_02:
				AsiaPciModify8(CHX002_BUSC | GPIO_02_SEL_REG, BIT6, GPIO_02_SEL_DAT);//D17F0 Rx97[6]* = 1 ((ENGPIO23))
				Reg8 = AsiaIoRead8(PmioBar + GPIO_02_IN_REG);
				*Value = (Reg8 & BIT4) ? TRUE : FALSE;//PMIO Rx49[4]
				break;
			case GPIO_03:
				AsiaPciModify8(CHX002_BUSC | GPIO_03_SEL_REG, BIT6, GPIO_03_SEL_DAT);//D17F0 Rx97[6]* = 1 ((ENGPIO23))
				 AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN5, 0);//PMIO RxBC[21] = 1'b0
				Reg8 = AsiaIoRead8(PmioBar + GPIO_03_IN_REG);
				*Value = (Reg8 & BIT5) ? TRUE : FALSE;//PMIO Rx49[5]
				break;
			case GPIO_04:
				AsiaPciModify8(CHX002_BUSC | GPIO_04_SEL_REG, BIT0, GPIO_04_SEL_DAT);//D17F0 Rx97[0]* = 1 ((ENGPIO45))
				 AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN3, 0);//PMIO RxBC[19] = 1'b0
				Reg8 = AsiaIoRead8(PmioBar + GPIO_04_IN_REG);
				*Value = (Reg8 & BIT6) ? TRUE : FALSE;//PMIO Rx49[6]
				break;
			case GPIO_05:
				AsiaPciModify8(CHX002_BUSC | GPIO_05_SEL_REG, BIT0, GPIO_05_SEL_DAT);//D17F0 Rx97[0]* = 1 ((ENGPIO45))
				 AsiaIoModify32(PmioBar + PMIO_CKGPCI_SMB_PAD_CTL, PMIO_CLKREQ_PAD_EN4, 0);//PMIO RxBC[20] = 1'b0
				Reg8 = AsiaIoRead8(PmioBar + GPIO_05_IN_REG);
				*Value = (Reg8 & BIT7) ? TRUE : FALSE;//PMIO Rx49[7]
				break;
			case GPIO_06:
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT16);// PMIO Rx94[27:0] == 28'h00010000 
				 //PAD Control Regsiter: Data
				Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				Buffer32 &= ~(BIT31+BIT30);
				Buffer32 |= BIT30;//PMIO Rx8C[31:30] == 2'b01
				AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				Reg8 = AsiaIoRead8(PmioBar + GPIO_06_IN_REG);
				*Value = (Reg8 & BIT0) ? TRUE : FALSE;//PMIO Rx4A[0]
				break;
			 case GPIO_07:
				 AsiaIoModify8(PmioBar +GPIO_07_SEL_REG, PMIO_PAD_PCI_GPIO7, BIT0);//PMIO RxBC[0]  = 1'b1
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_07_IN_REG);
				 *Value = (Reg8 & BIT1) ? TRUE : FALSE;//PMIO Rx4A[1]
				 break;
			 
			case GPIO_10:
				 AsiaIoModify32(PmioBar + GPIO_10_SEL_REG, PMIO_PAD_GPIO10_2_1_0, 0);//PMIO RxB4[18:16] = 3'b000
				Reg8 = AsiaIoRead8(PmioBar + GPIO_10_IN_REG);
				*Value = (Reg8 & BIT4) ? TRUE : FALSE;//PMIO Rx4A[4]
				break;
			case GPIO_11:
				 AsiaIoModify32(PmioBar + GPIO_11_SEL_REG, PMIO_PAD_GPIO11_2_1_0, 0);//PMIO RxB4[21:19] = 3'b000
				Reg8 = AsiaIoRead8(PmioBar + GPIO_11_IN_REG);
				*Value = (Reg8 & BIT5) ? TRUE : FALSE;//PMIO Rx4A[5]
				break;
			case GPIO_12:
				 AsiaIoModify32(PmioBar + GPIO_12_SEL_REG, PMIO_PAD_GPIO12_2_1_0, 0);//PMIO RxB4[26:24] = 3'b000
				Reg8 = AsiaIoRead8(PmioBar + GPIO_12_IN_REG);
				*Value = (Reg8 & BIT6) ? TRUE : FALSE;//PMIO Rx4A[6]
				break;
			case GPIO_13:
				 AsiaIoModify32(PmioBar +  GPIO_13_SEL_REG, PMIO_PAD_GPIO13_2_1_0, 0);	//PMIO RxB4[29:27] = 3'b000	 
				Reg8 = AsiaIoRead8(PmioBar + GPIO_13_IN_REG);
				*Value = (Reg8 & BIT7) ? TRUE : FALSE;//PMIO Rx4A[7]
				break;
			case GPIO_14:
				 AsiaIoModify32(PmioBar +  GPIO_14_SEL_REG, PMIO_PAD_GPIO14_2_1_0, 0);	//PMIO RxB8[2:0] = 3'b000		 
				Reg8 = AsiaIoRead8(PmioBar + GPIO_14_IN_REG);
				*Value = (Reg8 & BIT4) ? TRUE : FALSE;//PMIO Rx4B[4]
				break;
			 
			 case GPIO_26:
				 AsiaIoModify8(PmioBar +  GPIO_26_SEL_REG, PMIO_PAD_GPIO26_2_1_0, BIT3);////PMIO RxB8[5:3] = 3'b001	
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_26_IN_REG);
				 *Value = (Reg8 & BIT1) ? TRUE : FALSE;//PMIO Rx3C[9]
				 break;
			 case GPIO_27:
				 AsiaIoModify32(PmioBar +  GPIO_27_SEL_REG, PMIO_PAD_GPIO27_2_1_0, BIT8);//PMIO RxB8[10:8] = 3'b001
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_27_IN_REG);
				 *Value = (Reg8 & BIT2) ? TRUE : FALSE;//PMIO Rx3C[10]
				 break;
			 case GPIO_28:
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT27);// PMIO Rx94[27:0] == 28'h08000000 
				  //PAD Control Regsiter: Data
				 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				 Buffer32 &= ~(BIT26);
				 Buffer32 |= BIT26;//PMIO Rx8C[26] == 1'b1
				 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_28_IN_REG);
				 *Value = (Reg8 & BIT3) ? TRUE : FALSE;//PMIO Rx3C[12]
				 break;
			 case GPIO_29:
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT27);
				 //PAD Control Regsiter: Data
				 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				 Buffer32 &= ~(BIT28);
				 Buffer32 |= BIT28;//PMIO Rx8C[28] == 1'b1
				 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_29_IN_REG);
				 *Value = (Reg8 & BIT4) ? TRUE : FALSE;//PMIO Rx3C[12]
				 break;
			 case GPIO_30:
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT27);
				  //PAD Control Regsiter: Data
				 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				 Buffer32 &= ~(BIT30);
				 Buffer32 |= BIT30;//PMIO Rx8C[30] == 1'b1
				 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_30_IN_REG);
				 *Value = (Reg8 & BIT5) ? TRUE : FALSE;//PMIO Rx3C[13]
				 break;
			 case GPIO_31:
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);//PMIO Rx94[27:0] == 28'h00020000 
				  //PAD Control Regsiter: Data
				 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				 Buffer32 &= ~(BIT23);
				 Buffer32 |= BIT23;// PMIO Rx8C[23] == 1'b1
				 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_31_IN_REG);
				 *Value = (Reg8 & BIT6) ? TRUE : FALSE;//PMIO Rx3C[14]
				 break;
			 case GPIO_32:
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);// PMIO Rx94[27:0] == 28'h00020000
				 //PAD Control Regsiter: Data
				Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				Buffer32 &= ~(BIT30);
				Buffer32 |= BIT30;//PMIO Rx8C[30] == 1'b1
				AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_32_IN_REG);
				 *Value = (Reg8 & BIT7) ? TRUE : FALSE;//PMIO Rx3C[15]
				 break;
			 case GPIO_33:
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);//PMIO Rx94[27:0] == 28'h00020000 
				  //PAD Control Regsiter: Data
				 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				 Buffer32 &= ~(BIT31);
				 Buffer32 |= BIT31;// PMIO Rx8C[31] == 1'b1
				 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
				 Reg8 = AsiaIoRead8(PmioBar + GPIO_33_IN_REG);
				 *Value = (Reg8 & BIT0) ? TRUE : FALSE;//PMIO Rx46[0]
				 break;
			 
			case GPIO_36:
				 AsiaIoModify32(PmioBar + GPIO_36_SEL_REG, PMIO_P2G_GPIO36_2_1_0, 0);//PMIO Rx9B[2:0]=3'b000
				Reg8 = AsiaIoRead8(PmioBar + GPIO_36_IN_REG);
				*Value = (Reg8 & BIT3) ? TRUE : FALSE;//PMIO Rx46[3]
				break;
			case GPIO_37:
				 AsiaIoModify32(PmioBar + GPIO_37_SEL_REG, PMIO_P2G_GPIO37_2_1_0, 0);//PMIO Rx9A[2:0]=3'b000
				Reg8 = AsiaIoRead8(PmioBar + GPIO_37_IN_REG);
				*Value = (Reg8 & BIT4) ? TRUE : FALSE;//PMIO Rx46[4]
				 break;
			 case GPIO_39:
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);
				  //PAD Control Regsiter: Data
				 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
				 Buffer32 &= ~(BIT11+BIT12+BIT13);// PMIO Rx8C[13:11] == 3'b000
				 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
	
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);//PMIO Rx94[27:0] == 28'h00800000
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
				 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
				 *Value = (Reg32 & BIT7) ? TRUE : FALSE;//PMIO Rx90[7]
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
				 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
				 break; 
		 case GPIO_40:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT17);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT16+BIT17+BIT18);// PMIO Rx8C[18:16] == 3'b000
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT8) ? TRUE : FALSE;//PMIO Rx90[8
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
				break;
		 
		 case GPIO_44:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);//PMIO Rx94[27:0] == 28'h00040000
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT0+BIT1+BIT2);// PMIO Rx8C[2:0] == 3'b000
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT12) ? TRUE : FALSE;//PMIO Rx90[12]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_45:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT3+BIT4+BIT5);//PMIO Rx8C[5:3] == 3'b000
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT13) ? TRUE : FALSE;//PMIO Rx90[13]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_46:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT14) ? TRUE : FALSE;//PMIO Rx90[14]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_47:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT11+BIT12+BIT13);
			 Buffer32 |=BIT11;// PMIO Rx8C[13:11] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT15) ? TRUE : FALSE;//PMIO Rx90[15]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_48:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT16+BIT17+BIT18);
			Buffer32 |= BIT16;//PMIO Rx8C[18:16] == 3'b001
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT16) ? TRUE : FALSE;//PMIO Rx90[16]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_49:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT19+BIT20+BIT21);
			 Buffer32 |= BIT19;// PMIO Rx8C[21:19] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT17) ? TRUE : FALSE;//PMIO Rx90[17]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_50:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT24+BIT25+BIT26);
			Buffer32 |= BIT24;// PMIO Rx8C[26:24] == 3'b001
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT18) ? TRUE : FALSE;//PMIO Rx90[18]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_51:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT27+BIT28+BIT29);
			 Buffer32 |= BIT27;//PMIO Rx8C[29:27] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT19) ? TRUE : FALSE;//PMIO Rx90[19] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_52:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT0+BIT1+BIT2);
			Buffer32 |= BIT0;//PMIO Rx8C[2:0] == 3'b001
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT20) ? TRUE : FALSE;//PMIO Rx90[20]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_53:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT3+BIT4+BIT5);
			 Buffer32 |= BIT3;// PMIO Rx8C[5:3] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT21) ? TRUE : FALSE;//PMIO Rx90[21] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_54:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT8+BIT9+BIT10);
			 Buffer32 |= BIT8;// Rx8C[10:8] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT22) ? TRUE : FALSE;//PMIO Rx90[22]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_55:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT11+BIT12+BIT13);
			 Buffer32 |= BIT11;//PMIO Rx8C[13:11] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT23) ? TRUE : FALSE;//PMIO Rx90[23]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_56:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT16+BIT17+BIT18);
			 Buffer32 |= BIT16;// PMIO Rx8C[18:16] == 3'b001
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT23);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT24) ? TRUE : FALSE;//PMIO Rx90[24] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		
		 case GPIO_75:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT18);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT31);
			Buffer32 |= BIT31;//PMIO Rx8C[31] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);// PMIO Rx94[27:0] == 28'h01000000
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT11) ? TRUE : FALSE;//PMIO Rx90[11]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_76:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT6);
			Buffer32 |= BIT6;//PMIO Rx8C[6] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT12) ? TRUE : FALSE;//PMIO Rx90[12] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_77:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT7);
			 Buffer32 |= BIT7;//PMIO Rx8C[7] == 1'b1
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT13) ? TRUE : FALSE;//PMIO Rx90[13]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_78:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT14);
			 Buffer32 |= BIT14;//PMIO Rx8C[14] == 1'b1
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT14) ? TRUE : FALSE;//PMIO Rx90[14] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_79:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT15);
			Buffer32 |= BIT15;//PMIO Rx8C[15] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT15) ? TRUE : FALSE;//PMIO Rx90[15] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_80:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT22);
			Buffer32 |= BIT22;//PMIO Rx8C[22] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT16) ? TRUE : FALSE;//PMIO Rx90[16] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
	
		 case GPIO_83:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT19);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT31);
			Buffer32 |= BIT31;// PMIO Rx8C[31] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT19) ? TRUE : FALSE;//PMIO Rx90[19] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_84:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT6);
			 Buffer32 |= BIT6;//PMIO Rx8C[6] == 1'b1
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT20) ? TRUE : FALSE;//PMIO Rx90[20]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_85:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT7);
			Buffer32 |= BIT7;//PMIO Rx8C[7] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT21) ? TRUE : FALSE;//PMIO Rx90[21] 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_86:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT14);
			Buffer32 |= BIT14;//PMIO Rx8C[14] == 1'b1
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT22) ? TRUE : FALSE;//PMIO Rx90[22]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_87:
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
			 //PAD Control Regsiter: Data
			Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			Buffer32 &= ~(BIT22+BIT23);
			Buffer32 |= BIT22;//PMIO Rx8C[23:22] == 2'b01
			AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT23) ? TRUE : FALSE;//PMIO Rx90[23]
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		 case GPIO_88:
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT20);
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT30+BIT31);
			 Buffer32 |= BIT30;//PMIO Rx8C[31:30] == 2'b01
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			 
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT24);
			 Reg32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
			 *Value = (Reg32 & BIT24) ? TRUE : FALSE;//PMIO Rx90[24
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);			 
			 break;
		case GPI_00:
			AsiaPciModify8(CHX002_BUSC | GPI_00_SEL_REG, BIT1, GPI_00_SEL_DAT);
		 	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, BIT16);//PMIO Rx94[27:0] == 28'h00010000
			  //PAD Control Regsiter: Data
			 Buffer32 = AsiaIoRead32(PmioBar+PMIO_PAD_CTL_REG_READ_DATA);
			 Buffer32 &= ~(BIT30+BIT31);
			 Buffer32 |= BIT30;//PMIO Rx8C[31:30] == 2'b01
			 AsiaIoModify32(PmioBar +PMIO_PAD_CTL_REG_WRITE_DATA, 0xFFFFFFFF, Buffer32); // write them all
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);// trigger to write access
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0); //Write Enable Bit in PAD Control Register: Disable
			 AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, 0);
			Reg8 = AsiaIoRead8(PmioBar + GPI_00_IN_REG);
			*Value = (Reg8 & BIT0) ? TRUE : FALSE;//PMIO Rx48[0]
			break;
		 case GPI_01:
			 Reg8 = AsiaIoRead8(PmioBar + GPI_01_IN_REG);
			 *Value = (Reg8 & BIT1) ? TRUE : FALSE;//PMIO Rx48[1]
			  break;
		 case GPI_02:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MISC_CFG_4_PWR_WELL, D17F0_PMU_GPI23, GPI_02_SEL_DAT);//D17F0 Rx94[29] == 1
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE, PMIO_BATSMIEN, 0);//PMIO Rx25[4] == 0
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE, PMIO_BATSCIEN, 0);	//PMIO Rx23[4] == 0		   
			Reg8 = AsiaIoRead8(PmioBar + GPI_02_IN_REG);
			*Value = (Reg8 & BIT2) ? TRUE : FALSE;//PMIO Rx48[2]
			break;
		 case GPI_03:
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_MISC_CFG_4_PWR_WELL, D17F0_PMU_GPI23, GPI_03_SEL_DAT);//D17F0 Rx94[29] == 1
			AsiaIoModify8(PmioBar + PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE, PMIO_ESMI_SM, 0);//PMIO Rx24[4] == 0
			AsiaIoModify8(PmioBar + PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE, PMIO_ESMI_SC, 0);//PMIO Rx22[4] == 0			   
			Reg8 = AsiaIoRead8(PmioBar + GPI_03_IN_REG);
			*Value = (Reg8 & BIT3) ? TRUE : FALSE;//PMIO Rx48[3]
			break;
		case GPI_04:
			AsiaIoModify8(PmioBar + PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE, PMIO_INTRU_SM, 0);//PMIO Rx24[6] = 1'b0
			AsiaIoModify8(PmioBar + PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE, PMIO_INTRU_SC, 0); //PMIO Rx22[6] = 1'b0	
			Reg8 = AsiaIoRead8(PmioBar + GPI_04_IN_REG);
			*Value = (Reg8 & BIT4) ? TRUE : FALSE;
			break;
		case GPI_05:
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE, PMIO_LID_SC, 0);//PMIO Rx25[3] = 1'b0
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE, PMIO_LID_SC, 0);//PMIO Rx23[3] = 1'b0 	
			Reg8 = AsiaIoRead8(PmioBar + GPI_05_IN_REG);
			*Value = (Reg8 & BIT5) ? TRUE : FALSE;
			break;
		case GPI_06:
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE, PMIO_RI_SM, 0);//PMIO Rx25[0] =  1'b0
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE, PMIO_RI_SC, 0);//PMIO Rx23[0] =  1'b0
		    Reg8 = AsiaIoRead8(PmioBar + GPI_06_IN_REG);
		    *Value = (Reg8 & BIT6) ? TRUE : FALSE;
		    break;	
		case GPI_07:
		 	AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE, PMIO_THRM_SM, 0);//PMIO Rx25[2] =  1'b0
			AsiaPciModify8(CHX002_BUSC | D17F0_PMU_HOST_PM_CTL, D17F0_PMU_ENTHRM1, 0);//D17F0 Rx8C[3] =1'b0
			AsiaIoModify16(PmioBar + PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE, PMIO_THRM_SC, 0); //PMIO Rx23[2] =  1'b0
			Reg8 = AsiaIoRead8(PmioBar + GPI_07_IN_REG);
			*Value = (Reg8 & BIT7) ? TRUE : FALSE;
			break;
			
		case GPI_10:
			AsiaIoModify32(PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_4, BIT25, BIT25);//PMIO Rx6C[25] = 1'b1
			AsiaIoModify8(PmioBar + PMIO_GPI_SCI_RESUME_ENABLE, PMIO_SGPI10_SC, 0); //PMIO Rx56[0] =  1'b0
		    Reg8 = AsiaIoRead8(PmioBar + GPI_10_IN_REG);
			*Value = (Reg8 & BIT0) ? TRUE : FALSE;
			break;
		default:
			break;
		}
	
		return EFI_SUCCESS;
	}


/**
  SB PEIM GetAcpiTimerValue function.

  Value - The Current Value of ACPI Timer
  Extended - when the timer is 24-bit, Extended is FALSE; when it is 32-bit, Extended is TRUE.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param This point to ASIA_SB_LIB_PPI
  @param Value
  @param Extended

  @return EFI_STATUS.

**/
EFI_STATUS
EFIAPI
PeiGetAcpiTimerValue(
  IN EFI_PEI_SERVICES **PeiServices,
  IN ASIA_SB_LIB_PPI *This,
  OUT UINT32 *Value,
  OUT BOOLEAN *Extended OPTIONAL
  )
{
    UINT16 PmioBar;
    UINT8 Data8;
    
#if 1
	// [CJW_20170601]
	// run Nb->PreMemoryInit() before Sb->PreMemoryInit(), we need to get PMIO base 
	// address from Rx88 if we need to access PMIO register in Nb part, this is 
	// because the 'Real' This->PmioBaseAddress initialization is in Sb part.
	{
		PmioBar = AsiaPciRead16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE);
		PmioBar &= 0xFF00;
		if(PmioBar == 0x0000){
			//ASSERT("ERROR: PmioBaseAddress was not set\n");
		}
	}
#else
    PmioBar = This->PmioBaseAddress;
#endif
    *Value = AsiaIoRead32(PmioBar+PMIO_ACPI_TIMER);

    if(Extended!=NULL)
    {
        Data8 = AsiaPciRead8(CHX002_BUSC | D17F0_PMU_PM_GENERAL_CFG_2);
        Data8 &= D17F0_PMU_TMR32;
        if(Data8 == 0x00)
        {
            *Extended = FALSE;
        }
        else
        {
            *Extended = TRUE;
        }
          
    }

    return EFI_SUCCESS;
}
