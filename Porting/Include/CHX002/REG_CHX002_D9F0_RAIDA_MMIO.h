//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		RAIDA_MMIO					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D9F0_RAIDA_MMIO_R100(A0).doc(final)MOD_RDA1MMIO.xls
#ifndef _CHX002_D9F0_RAIDA_MMIO_H
#define _CHX002_D9F0_RAIDA_MMIO_H
//RDA1 MMIO
#define RDA1_MMIO_RAIDA1_UPPER_8BITS_OF_RDASTATADR		0x00	//RAIDA1 Upper 8bits of RDASTATADR
    #define RDA1_MMIO_RSV_00			0xFFFFFF00	//0/x/x/x Reserved
    #define RDA1_MMIO_RRDA1STATADR_39_32			0xFF	//0/x/x/x RAIDA Upper 8bits Of RDASTATADR
#define RDA1_MMIO_RAIDA1_LOWER_32BITS_OF_RDASTATADR		0x04	//RAIDA1 Lower 32bits of RDASTATADR
    #define RDA1_MMIO_RRDA1STATADR_31_0			0xFFFFFFFF	//0/x/x/x RAIDA Lower 32bits Of RDASTATADR
#define RDA1_MMIO_RAIDA1_CURRENT_ADR_LOW_32BITS		0x08	//RAIDA1 Current Address Low 32bits
    #define RDA1_MMIO_RRDA1CURADR_31_0			0xFFFFFFFF	//HwInit/x/x/x RAIDA Current Address Low 32bits
#define RDA1_MMIO_RAIDA1_CURRENT_ADR_UPPER_8BITS		0x0C	//RAIDA1 Current Address Upper 8bits
    #define RDA1_MMIO_RSV_0C			0xFFFFFF00	//0/x/x/x Reserved
    #define RDA1_MMIO_RRDA1CURADR_39_32			0xFF	//HwInit/x/x/x RAIDA Current Address Upper 8bits
#define RDA1_MMIO_RAIDA1_RESUME_MODE		0x10	//RAIDA1 Resume Mode
    #define RDA1_MMIO_RSV_10			0xFFFFFFFF	//0/x/x/x Reserved
#define RDA1_MMIO_RAIDA1_RESUME_MODE_Z1		0x14	//RAIDA1 Resume Mode
    #define RDA1_MMIO_RRDA1ADDDSCP			0xFFFFFFFF	//0h/x/x/x Add Number Of Descriptor
#define RDA1_MMIO_RAIDA1_CTL_INFORMATION		0x18	//RAIDA1 Control Information
    #define RDA1_MMIO_RSV_18			0xFFFFFFE0	//0/x/x/x Reserved
    #define RDA1_MMIO_RAIDA1_ERROR			BIT4	//0/x/x/x RAIDA Descriptor Format Error
    #define RDA1_MMIO_RSV_18_3			BIT3	//0/x/x/x Reserved
    #define RDA1_MMIO_RAIDA1_IS			BIT2	//0/x/x/x RAIDA Interrupt Status
    #define RDA1_MMIO_RSV_18_1			BIT1	//0/x/x/x Reserved
    #define RDA1_MMIO_RRDA1CTIVE			BIT0	//0/x/x/x RAIDA Active
#define RDA1_MMIO_RAIDA_CTL_REGS		0x20	//RAIDA Control Registers
    #define RDA1_MMIO_R1SV_20_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define RDA1_MMIO_RRDA1UPDDESEN			BIT7	//1b/x/x/x Update Descriptor Status Enable (RRDAUPDDESEN)
    #define RDA1_MMIO_RRDA1HOTRST			BIT6	//0/x/x/x RAIDA Hot Reset
    #define RDA1_MMIO_RRAIDA1_IM			BIT5	//0/x/x/x RAIDA Interrupt Mode
    #define RDA1_MMIO_RRAIDA1_IE			BIT4	//0/x/x/x RAIDA Interrupt Enable
    #define RDA1_MMIO_RRDA1FSHREN			BIT3	//0/x/x/x Flush Read Enable (RRDAFSHREN)
    #define RDA1_MMIO_RSV_1C_2_1			(BIT1 + BIT2)	//0/x/x/x Reserved
    #define RDA1_MMIO_RRDA1MSIFSHWEN			BIT0	//0/x/x/x RAIDA1 MSIFLUSHWEN
#define RDA1_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0		0x40	//Message Address for MSI-X Table Entries of Vector0
    #define RDA1_MMIO_R1VEC0MSGADDR_31_2			0xFFFFFFFC	//0/x/x/x System-Specified Message Lower Address
    #define RDA1_MMIO_R1VEC0MSGADDR_1_0			(BIT0 + BIT1)	//0/R/x/x Reserved
#define RDA1_MMIO_MSG_UPPER_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0		0x44	//Message Upper Address for MSI-X Table Entries of Vector0
    #define RDA1_MMIO_R1VEC0MSGADDR_63_32			0xFFFFFFFF	//0/x/x/x System-Specified Message Upper Address
#define RDA1_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0_Z1		0x48	//Message Address for MSI-X Table Entries of Vector0
    #define RDA1_MMIO_R1VEC0MSGDATA_31_0			0xFFFFFFFF	//0/x/x/x System-Specified Message Data
#define RDA1_MMIO_VECTOR_CTL_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0		0x4C	//Vector Control for MSI-X Table Entries of Vector0
    #define RDA1_MMIO_RSV_2C			0xFFFFFFFE	//0/x/x/x Reserved
    #define RDA1_MMIO_R1VEC0MSK			BIT0	//1b/x/x/x Vector 0 Mask Bit
#define RDA1_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1		0x50	//Message Address for MSI-X Table Entries of Vector1
    #define RDA1_MMIO_R1VEC1MSGADDR_31_2			0xFFFFFFFC	//0/x/x/x System-Specified Message Lower Address
    #define RDA1_MMIO_R1VEC1MSGADDR_1_0			(BIT0 + BIT1)	//0/R/x/x Reserved
#define RDA1_MMIO_MSG_UPPER_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1		0x54	//Message Upper Address for MSI-X Table Entries of Vector1
    #define RDA1_MMIO_R1VEC1MSGADDR_63_32			0xFFFFFFFF	//0/x/x/x System-Specified Message Upper Address
#define RDA1_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1_Z1		0x58	//Message Address for MSI-X Table Entries of Vector1
    #define RDA1_MMIO_R1VEC1MSGDATA_31_0			0xFFFFFFFF	//0/x/x/x System-Specified Message Data
#define RDA1_MMIO_VECTOR_CTL_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1		0x5C	//Vector Control for MSI-X Table Entries of Vector1
    #define RDA1_MMIO_RSV_3C			0xFFFFFFFE	//0/x/x/x Reserved
    #define RDA1_MMIO_R1VEC1MSK			BIT0	//1b/x/x/x Vector 1 Mask Bit
#define RDA1_MMIO_PENDING_BITS_FOR_MSI_X_PBA_ENTRIES		0x80	//Pending Bits for MSI-X PBA Entries
    #define RDA1_MMIO_RDA1PENDBIT_31_2			0xFFFFFFFC	//0/x/x/x Reserved
    #define RDA1_MMIO_RDA1PENDBIT_1			BIT1	//HwInit/x/x/x MSIX Pending Bit For Vector 1
    #define RDA1_MMIO_RDA1PENDBIT_0			BIT0	//HwInit/x/x/x MSIX Pending Bit For Vector 0
#define RDA1_MMIO_PENDING_BITS_FOR_MSI_X_PBA_ENTRIES_Z1		0x84	//Pending Bits for MSI-X PBA Entries
    #define RDA1_MMIO_RDA1PENDBIT_63_32			0xFFFFFFFF	//0/x/x/x Reserved
#endif
