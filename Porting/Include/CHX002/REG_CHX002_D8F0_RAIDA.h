//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		RAIDA					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D8F0_RAIDA_R101(A0).doc(final)MOD_D8F0.xls
#ifndef _CHX002_D8F0_RAIDA_H
#define _CHX002_D8F0_RAIDA_H
//D8F0
#define D8F0_VID		0x00	//Vendor ID
    #define D8F0_VENDORID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define D8F0_DID		0x02	//Device ID
    #define D8F0_DEVID_15_0			0xFFFF	//9045h/x/x/x Device ID
#define D8F0_PCI_CMD		0x04	//PCI Command
    #define D8F0_RX04_15_11			0xF800	//0/R/x/x Reserved
    #define D8F0_R0INTDIS			BIT10	//0/x/x/x Interrupt Disable
    #define D8F0_RFBACK			BIT9	//0/R/x/x Fast Back-To-Back Cycle Enable
    #define D8F0_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D8F0_RSETP			BIT7	//0/R/x/x Address / Data Stepping
    #define D8F0_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D8F0_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D8F0_RMWINV			BIT4	//0/R/x/x Memory Write And Invalidate
    #define D8F0_RSPCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D8F0_R0MSTR			BIT2	//0/x/x/x PCI Master Function
    #define D8F0_R0ENMEM			BIT1	//0/x/x/x Memory Space Access
    #define D8F0_R0ENIO			BIT0	//0/R/x/x I/O Space Access
#define D8F0_PCI_STA		0x06	//PCI Status
    #define D8F0_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D8F0_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D8F0_SMABORT			BIT13	//0/R/x/x Received Master-Abort (Except Special Cycle)
    #define D8F0_STABORTM			BIT12	//0/R/x/x Received Target-Abort
    #define D8F0_STABORTS			BIT11	//0/R/x/x Target-Abort Assertion
    #define D8F0_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D8F0_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D8F0_RFBKS			BIT7	//0/R/x/x Capable Of Accepting Fast Back-To-Back As A Target
    #define D8F0_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D8F0_R66M			BIT5	//0/R/x/x 66 MHz Capable
    #define D8F0_RCAP			BIT4	//1b/R/x/x Support New Capability List
    #define D8F0_RRDA0INTSS			BIT3	//HwInit/x/x/x RRDAINTSS
    #define D8F0_RX06_2_0			(BIT0 + BIT1 + BIT2)	//0/R/x/x Reserved
#define D8F0_REV_ID		0x08	//Revision ID
    #define D8F0_RX08_7_0			0xFF	//02h/x/x/x Revision Code
#define D8F0_CLASS_CODE		0x09	//Class Code
    #define D8F0_RX08_31_8			0xFFFFFF	//060000h/*/x/x Class Code
#define D8F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D8F0_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D8F0_PCI_MASTER_LATENCY_TIMER		0x0D	//PCI Master Latency Timer
    #define D8F0_RX0C_15_8			0xFF	//0/R/x/x Maximum Time Slice For This Function As A Master On The PCI Bus
#define D8F0_HEADER_TYPE		0x0E	//Header Type
    #define D8F0_RX0C_23_16			0xFF	//00h/R/x/x Header Type
#define D8F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D8F0_RX0C_31_24			0xFF	//0/R/x/x BIST Support
#define D8F0_MMIO_LOW_SPACE_BASE_ADR		0x10	//MMIO Low Space Base Address
    #define D8F0_R0MMIOBA_31_12			0xFFFFF000	//0/x/x/x MMIO Space Base Address
    #define D8F0_R0MMIOBA_11_4			0xFF0	//0/R/x/x MMIO Space Range
    #define D8F0_R0MMIOBA_3			BIT3	//0/R/x/x Prefetchable
    #define D8F0_R0MMIOBA_2_1			(BIT1 + BIT2)	//10b/R/x/x Type
    #define D8F0_R0MMIOBA_0			BIT0	//0/R/x/x Memory Space Indicator
#define D8F0_MMIO_UPPER_BASE_ADR		0x14	//MMIO Upper Base Address
    #define D8F0_R0MMIOBA_63_32			0xFFFFFFFF	//0/x/x/x MMIO Space Upper Base Address
#define D8F0_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D8F0_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D8F0_SVID		0x2C	//Subsystem Vendor ID
    #define D8F0_RX2C_15_0			0xFFFF	//1106h/*/x/x Subsystem Vendor ID
#define D8F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D8F0_RX2C_31_16			0xFFFF	//9045h/*/x/x Subsystem ID
#define D8F0_POINTER		0x34	//Pointer
    #define D8F0_RX34_7_0			0xFF	//A0h/*/x/x Capability List Pointer
#define D8F0_RESERVED		0x35	//Reserved
    #define D8F0_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D8F0_RESERVED_Z1		0x36	//Reserved
    #define D8F0_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D8F0_RESERVED_Z2		0x37	//Reserved
    #define D8F0_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D8F0_INTR_LINE		0x3C	//Interrupt Line
    #define D8F0_RINTLINE_7_0			0xFF	//0/x/x/x Interrupt Line
#define D8F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D8F0_RX3D_7_3			0xF8	//0/R/x/x Reserved
    #define D8F0_RINTPIN_2_0			(BIT0 + BIT1 + BIT2)	//001b/R/x/x Interrupt Pin
#define D8F0_RAIDA_CTL_REGS		0x40	//RAIDA Control Registers
    #define D8F0_VID_DID_LOCK_BIT			BIT15	//0/x/x/x Reserved
    #define D8F0_RDA0GRDBIT			BIT14	//0/x/x/X Reserved
    #define D8F0_RSV_40_13_0			0x3FFF	//0/x/x/x Reserved
#define D8F0_RAIDA_TIME_CTL_REGS_MOVE_TO_MMIO_SPACE		0x42	//RAIDA Time Control Registers (Move to MMIO space)
    #define D8F0_RSV_42_7_0			0xFF	//0/x/x/x Reserved
#define D8F0_RAIDA_UPPER_8BITS_OF_RDASTATADR_MOVE_TO_MMIO_SPACE		0x43	//RAIDA Upper 8bits of RDASTATADR (Move to MMIO space)
    #define D8F0_RSV_43_7_0			0xFF	//0/x/x/x Reserved
#define D8F0_PM_CAPS		0xA0	//Power Management Capabilities
    #define D8F0_R0PMCPME_4_0			0xF8000000	//00000b/0/x/x PME Support
    #define D8F0_R0PMCD2S			BIT26	//0/0/x/x D2 Support
    #define D8F0_R0PMCD1S			BIT25	//0/0/x/x D1 Support
    #define D8F0_R0PMCAUXC_2_0			(BIT22 + BIT23 + BIT24)	//0/0/x/x AUX Current
    #define D8F0_R0PMCDSI			BIT21	//1b/1/x/x Device Specific Initialization
    #define D8F0_RSV_53_1_0			(BIT19 + BIT20)	//0/R/x/x Reserved
    #define D8F0_R0TBD_34_2_0			(BIT16 + BIT17 + BIT18)	//010b/R/x/x Version
    #define D8F0_R0TBD_35_7_0			0xFF00	//C0h/x/x/x Next Capability Pointer
    #define D8F0_R0TBD_36_7_0			0xFF	//01h/R/x/x Capability ID
#define D8F0_PM_STA_CTL		0xA4	//Power Management Status / Control
    #define D8F0_R0TBD_37_7_0			0xFF000000	//0/R/x/x Power Management Data
    #define D8F0_R0TBD_38			BIT23	//0/x/x/x Enable Bus Power / Clock Control
    #define D8F0_R0TBD_39			BIT22	//0/x/x/x B2 / B3 Support
    #define D8F0_RSV_54_5_0			0x3F0000	//0/R/x/x Reserved
    #define D8F0_R0PMESD			BIT15	//0/0/x/x PME Status
    #define D8F0_R0TBD_40_1_0			(BIT13 + BIT14)	//0/R/x/x Data Scale
    #define D8F0_R0TBD_41_3_0			0x1E00	//0/R/x/x Data Select
    #define D8F0_R0PMEEN			BIT8	//0/0/x/x PME Enable
    #define D8F0_RSV_55_5_0			0xFC	//0/R/x/x Reserved
    #define D8F0_R0PWSD_1_0			(BIT0 + BIT1)	//00b/0/x/x Power State
#define D8F0_FLR_CAP_ID		0xB0	//FLR Capability ID
    #define D8F0_R0AF_NXT_PTR_7_0			0xFF00	//00h/x/x/x Next Capability Pointer
    #define D8F0_R0AF_CAP_ID_7_0			0xFF	//13h/x/x/x Capability ID
#define D8F0_FLR_CAP_LEN_AND_VER		0xB2	//FLR Capability Length and Version
    #define D8F0_R0AF_LENGTH_7_0			0xFF	//06h/R/x/x Vendor-Specific Capability ID 
#define D8F0_AF_CAPS		0xB3	//AF Capabilities
    #define D8F0_RSV_B3_7_2			0xFC	//0/x/x/x Reserved
    #define D8F0_R0AF_FLR_CAP			BIT1	//1b/x/x/x Support Function Level Reset
    #define D8F0_R0AF_TP_CAP			BIT0	//1b/x/x/x Support Transactions Pending
#define D8F0_AF_CTL_STA_REG		0xB4	//AF Control & Status Register
    #define D8F0_RSV_B5_7_1			0xFE00	//0/x/x/x Reserved
    #define D8F0_R0AF_TP			BIT8	//HwInit/x/x/x Transactions Pending
    #define D8F0_RSV_B4_7_1			0xFE	//0/x/x/x Reserved
    #define D8F0_R0AF_INITIATE_FLR			BIT0	//0/x/x/x Initiate FLR
#define D8F0_RESERVED_FOR_ECO		0xB6	//Reserved(( for ECO))
    #define D8F0_R0RSV_ECO_15_0			0xFFFF	//0/x/x/x Reserved
#define D8F0_MSI_X_CAP_ID		0xC0	//MSI-X Capability ID
    #define D8F0_R0CAPID_7_0			0xFF	//11h/R/x/x MSI-X Capability ID
#define D8F0_MSI_X_NEXT_POINTER		0xC1	//MSI-X Next Pointer
    #define D8F0_R0CAPNXTPTR_7_0			0xFF	//B0h/x/x/x MSI-X Next Pointer
#define D8F0_MSI_X_MSG_CTL		0xC2	//MSI-X Message Control
    #define D8F0_R0MSIXEN			BIT15	//0/x/x/x MSI-X Enable
    #define D8F0_R0MSIXFUNCMSK			BIT14	//0/x/x/x Function Mask
    #define D8F0_RSV_C2			(BIT11 + BIT12 + BIT13)	//0/x/x/x Reserved.
    #define D8F0_R0MSIXTBSZ_10_0			0x7FF	//1h/R/x/x Table Size
#define D8F0_TABLE_OFFSET_TABLE_BIR_FOR_MSI_X		0xC4	//Table Offset/Table BIR for MSI-X
    #define D8F0_R0MSIXTABOFT_31_3			0xFFFFFFF8	//8h/R/x/x Table Offset
    #define D8F0_R0MSIXTABBIR_2_0			(BIT0 + BIT1 + BIT2)	//000b/R/x/x Table BIR
#define D8F0_PBA_OFFSET_PBA_BIR_FOR_MSI_X		0xC8	//PBA Offset/PBA BIR for MSI-X
    #define D8F0_R0MSIXPBAOFT_31_3			0xFFFFFFF8	//10h/R/x/x PBA Offset
    #define D8F0_R0MSIXPBABIR_2_0			(BIT0 + BIT1 + BIT2)	//000b/R/x/x PBA BIR
#define D8F0_RESUME_MODE_MOVE_TO_MMIO_SPACE		0xCC	//Resume Mode (Move to MMIO space)
    #define D8F0_RSV_CC			0xFFFFFFFF	//0/x/x/x Reserved
#define D8F0_RAIDA0_BUS_NUM		0xD8	//RAIDA0 Bus Number
    #define D8F0_RSV_D8			0xFFF80000	//0/x/x/x Reserved
    #define D8F0_IOV_SID_LOCK_BIT			BIT18	//0/x/x/x Reserved
    #define D8F0_RDA0BUSNUM			0x3FC00	//0/x/x/x RAIDA0 Bus Number for IOV SID Decode
    #define D8F0_RDA0DEVNUM			0x3E0	//8h/x/x/x RAIDA0 Device Number for IOV SID Decode
    #define D8F0_RDA0FUNNUM			0x1F	//0/x/x/x RAIDA0 Function Number for IOV SID Decode

#endif
