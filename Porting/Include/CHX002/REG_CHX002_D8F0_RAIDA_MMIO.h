//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		RAIDA_MMIO					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D8F0_RAIDA_MMIO_R100(A0).doc(final)MOD_RDA0MMIO.xls
#ifndef _CHX002_D8F0_RAIDA_MMIO_H
#define _CHX002_D8F0_RAIDA_MMIO_H
//RDA0 MMIO
#define RDA0_MMIO_RAIDA0_UPPER_8BITS_OF_RDASTATADR		0x00	//RAIDA0 Upper 8bits of RDASTATADR
    #define RDA0_MMIO_RSV_00			0xFFFFFF00	//0/x/x/x Reserved
    #define RDA0_MMIO_RRDA0STATADR_39_32			0xFF	//0/x/x/x RAIDA Upper 8bits of RDASTATADR
#define RDA0_MMIO_RAIDA0_LOWER_32BITS_OF_RDASTATADR		0x04	//RAIDA0 Lower 32bits of RDASTATADR
    #define RDA0_MMIO_RRDA0STATADR_31_0			0xFFFFFFFF	//0/x/x/x RAIDA Lower 32bits of RDASTATADR
#define RDA0_MMIO_RAIDA0_CURRENT_ADR_LOW_32BITS		0x08	//RAIDA0 Current Address Low 32bits
    #define RDA0_MMIO_RRDA0CURADR_31_0			0xFFFFFFFF	//HwInit/x/x/x RAIDA Current Address Low 32bits
#define RDA0_MMIO_RAIDA0_CURRENT_ADR_UPPER_8BITS		0x0C	//RAIDA0 Current Address Upper 8bits
    #define RDA0_MMIO_RSV_0C			0xFFFFFF00	//0/x/x/x Reserved
    #define RDA0_MMIO_RRDA0CURADR_39_32			0xFF	//HwInit/x/x/x RAIDA Current Address Upper 8bits
#define RDA0_MMIO_RAIDA0_RESUME_MODE		0x10	//RAIDA0 Resume Mode
    #define RDA0_MMIO_RSV_10			0xFFFFFFFF	//0/x/x/x Reserved
#define RDA0_MMIO_RAIDA0_RESUME_MODE_Z1		0x14	//RAIDA0 Resume Mode
    #define RDA0_MMIO_RRDA0ADDDSCP			0xFFFFFFFF	//0h/x/x/x Add Number of Descriptor
#define RDA0_MMIO_RAIDA0_CTL_INFORMATION		0x18	//RAIDA0 Control Information
    #define RDA0_MMIO_RSV_18			0xFFFFFFE0	//0/x/x/x Reserved
    #define RDA0_MMIO_RAIDA0_ERROR			BIT4	//0/x/x/x RAIDA Descriptor Format Error
    #define RDA0_MMIO_RSV_18_3			BIT3	//0/x/x/x Reserved
    #define RDA0_MMIO_RAIDA0_IS			BIT2	//0/x/x/x RAIDA Interrupt Status
    #define RDA0_MMIO_RSV_18_1			BIT1	//0/x/x/x Reserved
    #define RDA0_MMIO_RRDA0CTIVE			BIT0	//0/x/x/x RAIDA Active
#define RDA0_MMIO_RAIDA_CTL_REGS		0x20	//RAIDA Control Registers
    #define RDA0_MMIO_R0SV_20_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define RDA0_MMIO_RRDA0UPDDESEN			BIT7	//1b/x/x/x Update Descriptor Status Enable (RRDAUPDDESEN)
    #define RDA0_MMIO_RRDA0HOTRST			BIT6	//0/x/x/x RAIDA Hot Reset
    #define RDA0_MMIO_RRAIDA0_IM			BIT5	//0/x/x/x RAIDA Interrupt Mode
    #define RDA0_MMIO_RRAIDA0_IE			BIT4	//0/x/x/x RAIDA Interrupt Enable
    #define RDA0_MMIO_RRDA0FSHREN			BIT3	//0/x/x/x Flush Read Enable (RRDAFSHREN)
    #define RDA0_MMIO_RSV_1C_2_1			(BIT1 + BIT2)	//0/x/x/x Reserved
    #define RDA0_MMIO_RRDA0MSIFSHWEN			BIT0	//0/x/x/x RAIDA0 MSIFLUSHWEN
#define RDA0_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0		0x40	//Message Address for MSI-X Table Entries of Vector0
    #define RDA0_MMIO_R0VEC0MSGADDR_31_2			0xFFFFFFFC	//0/x/x/x System-Specified Message Lower Address
    #define RDA0_MMIO_R0VEC0MSGADDR_1_0			(BIT0 + BIT1)	//0/R/x/x Reserved
#define RDA0_MMIO_MSG_UPPER_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0		0x44	//Message Upper Address for MSI-X Table Entries of Vector0
    #define RDA0_MMIO_R0VEC0MSGADDR_63_32			0xFFFFFFFF	//0/x/x/x System-Specified Message Upper Address
#define RDA0_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0_Z1		0x48	//Message Address for MSI-X Table Entries of Vector0
    #define RDA0_MMIO_R0VEC0MSGDATA_31_0			0xFFFFFFFF	//0/x/x/x System-Specified Message Data
#define RDA0_MMIO_VECTOR_CTL_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR0		0x4C	//Vector Control for MSI-X Table Entries of Vector0
    #define RDA0_MMIO_RSV_2C			0xFFFFFFFE	//0/x/x/x Reserved
    #define RDA0_MMIO_R0VEC0MSK			BIT0	//1b/x/x/x Vector 0 Mask Bit
#define RDA0_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1		0x50	//Message Address for MSI-X Table Entries of Vector1
    #define RDA0_MMIO_R0VEC1MSGADDR_31_2			0xFFFFFFFC	//0/x/x/x System-Specified Message Lower Address
    #define RDA0_MMIO_R0VEC1MSGADDR_1_0			(BIT0 + BIT1)	//0/R/x/x Reserved
#define RDA0_MMIO_MSG_UPPER_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1		0x54	//Message Upper Address for MSI-X Table Entries of Vector1
    #define RDA0_MMIO_R0VEC1MSGADDR_63_32			0xFFFFFFFF	//0/x/x/x System-Specified Message Upper Address
#define RDA0_MMIO_MSG_ADR_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1_Z1		0x58	//Message Address for MSI-X Table Entries of Vector1
    #define RDA0_MMIO_R0VEC1MSGDATA_31_0			0xFFFFFFFF	//0/x/x/x System-Specified Message Data
#define RDA0_MMIO_VECTOR_CTL_FOR_MSI_X_TABLE_ENTRIES_OF_VECTOR1		0x5C	//Vector Control for MSI-X Table Entries of Vector1
    #define RDA0_MMIO_RSV_3C			0xFFFFFFFE	//0/x/x/x Reserved
    #define RDA0_MMIO_R0VEC1MSK			BIT0	//1b/x/x/x Vector 1 Mask Bit
#define RDA0_MMIO_PENDING_BITS_FOR_MSI_X_PBA_ENTRIES		0x80	//Pending Bits for MSI-X PBA Entries
    #define RDA0_MMIO_RDA0PENDBIT_31_2			0xFFFFFFFC	//0/x/x/X Reserved
    #define RDA0_MMIO_RDA0PENDBIT_1			BIT1	//HwInit/x/x/X MSIX Pending Bit for Vector 1
    #define RDA0_MMIO_RDA0PENDBIT_0			BIT0	//HwInit/x/x/X MSIX Pending Bit for Vector 0
#define RDA0_MMIO_PENDING_BITS_FOR_MSI_X_PBA_ENTRIES_Z1		0x84	//Pending Bits for MSI-X PBA Entries
    #define RDA0_MMIO_RDA0PENDBIT_63_32			0xFFFFFFFF	//0/x/x/x Reserved
#endif
