//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		SVADDVAD					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F2_SVADDVAD_R093(A0).doc(final)MOD_D0F2.xls
#ifndef _CHX002_D0F2_SVADDVAD_H
#define _CHX002_D0F2_SVADDVAD_H
//D0F2
#define D0F2_VID		0x00	//Vendor ID
    #define D0F2_VENDORID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define D0F2_DID		0x02	//Device ID
    #define D0F2_DEVID_15_0			0xFFFF	//31B1h/x/x/x Device ID
#define D0F2_PCI_CMD		0x04	//PCI Command
    #define D0F2_RX04_15_10			0xFC00	//0/R/x/x Reserved
    #define D0F2_RFBACK			BIT9	//0/R/x/x Fast Back-to-back Cycle Enable
    #define D0F2_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D0F2_RSETP			BIT7	//0/R/x/x Address/Data Stepping
    #define D0F2_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D0F2_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F2_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D0F2_RSPCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D0F2_RMSTR			BIT2	//1b/R/x/x PCI Master Function
    #define D0F2_RENMEM			BIT1	//1b/R/x/x Memory Space Access
    #define D0F2_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F2_PCI_STA		0x06	//PCI Status
    #define D0F2_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F2_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F2_SMABORT			BIT13	//0/R/x/x Received Master-abort (Except Special Cycle)
    #define D0F2_STABORTM			BIT12	//0/R/x/x Received Target-abort
    #define D0F2_STABORTS			BIT11	//0/R/x/x Target-abort Assertion
    #define D0F2_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D0F2_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F2_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-back as a Target
    #define D0F2_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F2_R66M			BIT5	//0/R/x/x 66MHz Capability
    #define D0F2_RCAP			BIT4	//0/R/x/x Support New Capability List
    #define D0F2_RX04_19_16			0xF	//0/R/x/x Reserved
#define D0F2_REV_ID		0x08	//Revision ID
    #define D0F2_RX08_7_0			0xFF	//04h/x/x/x Revision Code
#define D0F2_CLASS_CODE		0x09	//Class Code
    #define D0F2_CLASSCODE_23_0			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F2_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F2_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D0F2_PCI_MASTER_LATENCY_TIMER		0x0D	//PCI Master Latency Timer
    #define D0F2_RX0C_15_8			0xFF	//0/R/x/x Maximum Time Slice for This Function as a Master on the PCI Bus
#define D0F2_HEADER_TYPE		0x0E	//Header Type
    #define D0F2_RX0C_23_16			0xFF	//80h/R/x/x Header Type
#define D0F2_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D0F2_RX0C_31_24			0xFF	//0/R/x/x BIST Support
#define D0F2_BASE_ADR_REGS_0		0x10	//Base Address Registers 0
    #define D0F2_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address 0
#define D0F2_BASE_ADR_REGS_1		0x14	//Base Address Registers 1
    #define D0F2_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address 1
#define D0F2_BASE_ADR_REGS_2		0x18	//Base Address Registers 2
    #define D0F2_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address 2
#define D0F2_BASE_ADR_REGS_3		0x1C	//Base Address Registers 3
    #define D0F2_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address 3
#define D0F2_BASE_ADR_REGS_4		0x20	//Base Address Registers 4
    #define D0F2_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address 4
#define D0F2_BASE_ADR_REGS_5		0x24	//Base Address Registers 5
    #define D0F2_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address 5
#define D0F2_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F2_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F2_SVID		0x2C	//Subsystem Vendor ID
    #define D0F2_RX2C_15_0			0xFFFF	//0/x/x/x Subsystem Vendor ID
#define D0F2_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F2_RX2C_31_16			0xFFFF	//0/x/x/x Subsystem ID
#define D0F2_RESERVED		0x30	//Reserved
    #define D0F2_RX30_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z1		0x31	//Reserved
    #define D0F2_RX31_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z2		0x32	//Reserved
    #define D0F2_RX32_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z3		0x33	//Reserved
    #define D0F2_RX33_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_CAP_POINTER		0x34	//Capability Pointer
    #define D0F2_CAPPTR_7_0			0xFF	//0/R/x/x Capability List Pointer
#define D0F2_RESERVED_Z4		0x35	//Reserved
    #define D0F2_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z5		0x36	//Reserved
    #define D0F2_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z6		0x37	//Reserved
    #define D0F2_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z7		0x38	//Reserved
    #define D0F2_RX38_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z8		0x39	//Reserved
    #define D0F2_RX39_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z9		0x3A	//Reserved
    #define D0F2_RX3A_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_RESERVED_Z10		0x3B	//Reserved
    #define D0F2_RX3B_7_0			0xFF	//0/R/x/x Reserved
#define D0F2_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F2_RX3C_15_8			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F2_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F2_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F2_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D0F2_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D0F2_MMIOCFG_DECODER		0x40	//MMIOCFG Decoder
    #define D0F2_RX40_31			BIT31	//0/x/x/x RDID_RID_LOCK_D0F2
    #define D0F2_RSVAD_LOCK			BIT30	//0/x/x/x Lock Bit for SVAD Related Register
    #define D0F2_RVID_DID_LOCK_D0F2			BIT29	//0/x/x/x RVID_DID_LOCK_D0F2
    #define D0F2_RSVID_TSEGPRT_LOCK			BIT28	//0/x/x/x C2M Tseg Range Protection Control 
    #define D0F2_RCLASS_CODE_LOCK_D0F2			BIT27	//0/x/x/x RCLASS_CODE_LOCK_D0F2
    #define D0F2_RX40_26_18			0x7FC0000	//0/R/x/x Reserved
    #define D0F2_RSVAD_MMIOCFGBASE_39_26			0x3FFF0	//0/x/x/x MMIOCFG Base
    #define D0F2_RX40_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F2_RSVAD_MMIOCFGSEL_1_0			(BIT0 + BIT1)	//0/x/x/x MMIOCFG/IOCFG Size
#define D0F2_MMIO_BELOW_2G_MMIOB2G		0x44	//MMIO below 2G (MMIOB2G)
    #define D0F2_RX44_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F2_RSVAD_MMIOB2GBASE_30_28			(BIT4 + BIT5 + BIT6)	//0/x/x/x MMIO Below 2G (MMIOB2G) Base Address
    #define D0F2_RSVAD_MMIOB2GTMVEQ1			BIT3	//0/x/x/x MMIOB2G Target Mapping Value EQU1
    #define D0F2_RSVAD_MMIOB2GTMVEQ0			BIT2	//0/x/x/x MMIOB2G Target Mapping Value EQU0
    #define D0F2_RSVAD_MMIOB2GTAS_1_0			(BIT0 + BIT1)	//11b/x/x/x MMIOB2G Target Address Select
//@self defined macro begin
#define  MMIOB2G_TARGET_SELECT_A28		 0x00 
#define	MMIOB2G_TARGET_SELECT_A29		0x01
#define	MMIOB2G_TARGET_SELECT_A30		0x02
#define	MMIOB2G_DIS 			0x03
//@self defined macro end
#define D0F2_MMIO_2G_TO_4G_MMIO2T4G		0x46	//MMIO 2G to 4G (MMIO2T4G)
    #define D0F2_RX46_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F2_RSVAD_MMIO2T4GBASE_30_28			(BIT4 + BIT5 + BIT6)	//0/x/x/x MMIO 2 to 4G (MMIO2T4G) Base Address
    #define D0F2_RSVAD_MMIO2T4GTMVEQ1			BIT3	//0/x/x/x MMIO2T4G Target Mapping Value EQU1
    #define D0F2_RSVAD_MMIO2T4GTMVEQ0			BIT2	//0/x/x/x MMIO2T4G Target Mapping Value EQU0
    #define D0F2_RSVAD_MMIO2T4GTAS_1_0			(BIT0 + BIT1)	//0/x/x/x MMIO2T4G Target Address Select
//@self defined macro begin
#define  MMIO2T4G_TARGET_SELECT_A28 	  0x00 
#define	MMIO2T4G_TARGET_SELECT_A29		 0x01
#define	MMIO2T4G_TARGET_SELECT_A30		 0x02 
//@self defined macro end
#define D0F2_RESERVED_Z11		0x48	//Reserved
    #define D0F2_RX48_31_0			0xFFFFFFFF	//0/R/x/x Reserved
#define D0F2_MEM_ENT0		0x4C	//MEM_ENT0
    #define D0F2_RX4C_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX4C_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME0ATTR			BIT19	//0/x/x/x MEM Entry0 Attritbue
    #define D0F2_RSVAD_ME0HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry0 Hash Select
    #define D0F2_RSVAD_ME0HEN			BIT16	//0/x/x/x MEM Entry0 Hash Enable
    #define D0F2_RSVAD_ME0LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry0 Low Order Select
//@self defined macro begin
#define LOW_ORDER_SEL_A6   0x0000
	   #define LOW_ORDER_SEL_A7   0x4000
	   #define LOW_ORDER_SEL_A8   0x8000
	   #define LOW_ORDER_SEL_NO_INTERLEAVE	 0xC000
//@self defined macro end
    #define D0F2_RSVAD_ME0TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry0 Target List
    #define D0F2_RSVAD_ME0LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry0 Limit Address
#define D0F2_MEM_ENT1		0x50	//MEM_ENT1
    #define D0F2_RX50_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX50_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME1ATTR			BIT19	//0/x/x/x MEM Entry1 Attribute
    #define D0F2_RSVAD_ME1HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry1 Hash Select
    #define D0F2_RSVAD_ME1HEN			BIT16	//0/x/x/x MEM Entry1 Hash Enable
    #define D0F2_RSVAD_ME1LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry1 Low Order Select
    #define D0F2_RSVAD_ME1TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry1 Target List
    #define D0F2_RSVAD_ME1LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry1 Limit Address
#define D0F2_MEM_ENT2		0x54	//MEM_ENT2
    #define D0F2_RX54_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX54_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME2ATTR			BIT19	//0/x/x/x MEM Entry2 Attribute
    #define D0F2_RSVAD_ME2HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry2 Hash Select
    #define D0F2_RSVAD_ME2HEN			BIT16	//0/x/x/x MEM Entry2 Hash Enable
    #define D0F2_RSVAD_ME2LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry2 Low Order Select
    #define D0F2_RSVAD_ME2TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry2 Target List
    #define D0F2_RSVAD_ME2LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry2 Limit Address
#define D0F2_MEM_ENT3		0x58	//MEM_ENT3
    #define D0F2_RX58_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX58_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME3ATTR			BIT19	//0/x/x/x MEM Entry3 Attribute
    #define D0F2_RSVAD_ME3HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry3 Hash Select
    #define D0F2_RSVAD_ME3HEN			BIT16	//0/x/x/x MEM Entry3 Hash Enable
    #define D0F2_RSVAD_ME3LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry3 Low Order Select
    #define D0F2_RSVAD_ME3TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry3 Target List
    #define D0F2_RSVAD_ME3LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry3 Limit Address
#define D0F2_MEM_ENT4		0x5C	//MEM_ENT4
    #define D0F2_RX5C_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX5C_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME4ATTR			BIT19	//0/x/x/x MEM Entry4 Attribute
    #define D0F2_RSVAD_ME4HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry4 Hash Select
    #define D0F2_RSVAD_ME4HEN			BIT16	//0/x/x/x MEM Entry4 Hash Enable
    #define D0F2_RSVAD_ME4LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry4 Low Order Select
    #define D0F2_RSVAD_ME4TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry4 Target List
    #define D0F2_RSVAD_ME4LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry4 Limit Address
#define D0F2_MEM_ENT5		0x60	//MEM_ENT5
    #define D0F2_RX60_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX60_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME5ATTR			BIT19	//0/x/x/x MEM Entry5 Attribute
    #define D0F2_RSVAD_ME5HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry5 Hash Select
    #define D0F2_RSVAD_ME5HEN			BIT16	//0/x/x/x MEM Entry5 Hash Enable
    #define D0F2_RSVAD_ME5LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry5 Low Order Select
    #define D0F2_RSVAD_ME5TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry5 Target List
    #define D0F2_RSVAD_ME5LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry5 Limit Address
#define D0F2_MEM_ENT6		0x64	//MEM_ENT6
    #define D0F2_RX64_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX64_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME6ATTR			BIT19	//0/x/x/x MEM Entry6 Attribute
    #define D0F2_RSVAD_ME6HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry6 Hash Select
    #define D0F2_RSVAD_ME6HEN			BIT16	//0/x/x/x MEM Entry6 Hash Enable
    #define D0F2_RSVAD_ME6LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry6 Low Order Select
    #define D0F2_RSVAD_ME6TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry6 Target List
    #define D0F2_RSVAD_ME6LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry6 Limit Address
#define D0F2_MEM_ENT7		0x68	//MEM_ENT7
    #define D0F2_RX68_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX68_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME7ATTR			BIT19	//0/x/x/x MEM Entry7 Attribute
    #define D0F2_RSVAD_ME7HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry7 Hash Select
    #define D0F2_RSVAD_ME7HEN			BIT16	//0/x/x/x MEM Entry7 Hash Enable
    #define D0F2_RSVAD_ME7LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry7 Low Order Select
    #define D0F2_RSVAD_ME7TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry7 Target List
    #define D0F2_RSVAD_ME7LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry7 Limit Address
#define D0F2_MEM_ENT8		0x6C	//MEM_ENT8
    #define D0F2_RX6C_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX6C_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME8ATTR			BIT19	//0/x/x/x MEM Entry8 Attribute
    #define D0F2_RSVAD_ME8HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry8 Hash Select
    #define D0F2_RSVAD_ME8HEN			BIT16	//0/x/x/x MEM Entry8 Hash Enable
    #define D0F2_RSVAD_ME8LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry8 Low Order Select
    #define D0F2_RSVAD_ME8TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry8 Target List
    #define D0F2_RSVAD_ME8LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry8 Limit Address
#define D0F2_MEM_ENT9		0x70	//MEM_ENT9
    #define D0F2_RX70_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX70_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME9ATTR			BIT19	//0/x/x/x MEM Entry9 Attribute
    #define D0F2_RSVAD_ME9HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry9 Hash Select
    #define D0F2_RSVAD_ME9HEN			BIT16	//0/x/x/x MEM Entry9 Hash Enable
    #define D0F2_RSVAD_ME9LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry9 Low Order Select
    #define D0F2_RSVAD_ME9TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry9 Target List
    #define D0F2_RSVAD_ME9LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry9 Limit Address
#define D0F2_MEM_ENT10		0x74	//MEM_ENT10
    #define D0F2_RX74_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX74_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME10ATTR			BIT19	//0/x/x/x MEM Entry10 Attrbute
    #define D0F2_RSVAD_ME10HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry10 Hash Select
    #define D0F2_RSVAD_ME10HEN			BIT16	//0/x/x/x MEM Entry10 Hash Enable
    #define D0F2_RSVAD_ME10LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry10 Low Order Select
    #define D0F2_RSVAD_ME10TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry10 Target List
    #define D0F2_RSVAD_ME10LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry10 Limit Address
#define D0F2_MEM_ENT11		0x78	//MEM_ENT11
    #define D0F2_RX78_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX78_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME11ATTR			BIT19	//0/x/x/x MEM Entry11 Attribute
    #define D0F2_RSVAD_ME11HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry11 Hash Select
    #define D0F2_RSVAD_ME11HEN			BIT16	//0/x/x/x MEM Entry11 Hash Enable
    #define D0F2_RSVAD_ME11LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry11 Low Order Select
    #define D0F2_RSVAD_ME11TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry11 Target List
    #define D0F2_RSVAD_ME11LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry11 Limit Address
#define D0F2_MEM_ENT12		0x7C	//MEM_ENT12
    #define D0F2_RX7C_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX7C_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME12ATTR			BIT19	//0/x/x/x MEM Entry12 Attribute
    #define D0F2_RSVAD_ME12HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry12 Hash Select
    #define D0F2_RSVAD_ME12HEN			BIT16	//0/x/x/x MEM Entry12 Hash Enable
    #define D0F2_RSVAD_ME12LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry12 Low Order Select
    #define D0F2_RSVAD_ME12TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry12 Target List
    #define D0F2_RSVAD_ME12LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry12 Limit Address
#define D0F2_MEM_ENT13		0x80	//MEM_ENT13
    #define D0F2_RX80_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX80_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME13ATTR			BIT19	//0/x/x/x MEM Entry13 Attribute
    #define D0F2_RSVAD_ME13HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry13 Hash Select
    #define D0F2_RSVAD_ME13HEN			BIT16	//0/x/x/x MEM Entry13 Hash Enable
    #define D0F2_RSVAD_ME13LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry13 Low Order Select
    #define D0F2_RSVAD_ME13TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry13 Target List
    #define D0F2_RSVAD_ME13LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry13 Limit Address
#define D0F2_MEM_ENT14		0x84	//MEM_ENT14
    #define D0F2_RX84_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX84_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME14ATTR			BIT19	//0/x/x/x MEM Entry14 Attribute
    #define D0F2_RSVAD_ME14HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry14 Hash Select
    #define D0F2_RSVAD_ME14HEN			BIT16	//0/x/x/x MEM Entry14 Hash Enable
    #define D0F2_RSVAD_ME14LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry14 Low Order Select
    #define D0F2_RSVAD_ME14TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry14 Target List
    #define D0F2_RSVAD_ME14LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry14 Limit Address
#define D0F2_MEM_ENT15		0x88	//MEM_ENT15
    #define D0F2_RX88_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX88_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME15ATTR			BIT19	//0/x/x/x MEM Entry15 Attribute
    #define D0F2_RSVAD_ME15HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry15 Hash Select
    #define D0F2_RSVAD_ME15HEN			BIT16	//0/x/x/x MEM Entry15 Hash Enable
    #define D0F2_RSVAD_ME15LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry15 Low Order Select
    #define D0F2_RSVAD_ME15TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry15 Target List
    #define D0F2_RSVAD_ME15LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry15 Limit Address
#define D0F2_MEM_ENT16		0x8C	//MEM_ENT16
    #define D0F2_RX8C_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX8C_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME16ATTR			BIT19	//0/x/x/x MEM Entry16 Attribute
    #define D0F2_RSVAD_ME16HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry16 Hash Select
    #define D0F2_RSVAD_ME16HEN			BIT16	//0/x/x/x MEM Entry16 Hash Enable
    #define D0F2_RSVAD_ME16LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry16 Low Order Select
    #define D0F2_RSVAD_ME16TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry16 Target List
    #define D0F2_RSVAD_ME16LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry16 Limit Address
#define D0F2_MEM_ENT17		0x90	//MEM_ENT17
    #define D0F2_RX90_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX90_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME17ATTR			BIT19	//0/x/x/x MEM Entry17 Attribute
    #define D0F2_RSVAD_ME17HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry17 Hash Select
    #define D0F2_RSVAD_ME17HEN			BIT16	//0/x/x/x MEM Entry17 Hash Enable
    #define D0F2_RSVAD_ME17LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry17 Low Order Select
    #define D0F2_RSVAD_ME17TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry17 Target List
    #define D0F2_RSVAD_ME17LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry17 Limit Address
#define D0F2_MEM_ENT18		0x94	//MEM_ENT18
    #define D0F2_RX94_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX94_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME18ATTR			BIT19	//0/x/x/x MEM Entry18 Attribute
    #define D0F2_RSVAD_ME18HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry18 Hash Select
    #define D0F2_RSVAD_ME18HEN			BIT16	//0/x/x/x MEM Entry18 Hash Enable
    #define D0F2_RSVAD_ME18LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry18 Low Order Select
    #define D0F2_RSVAD_ME18TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry18 Target List
    #define D0F2_RSVAD_ME18LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry18 Limit Address
#define D0F2_MEM_ENT19		0x98	//MEM_ENT19
    #define D0F2_RX98_31_23			0xFF800000	//0/R/x/x Reserved
    #define D0F2_RX98_22_20			(BIT20 + BIT21 + BIT22)	//0/R/x/x Reserved
    #define D0F2_RSVAD_ME19ATTR			BIT19	//0/x/x/x MEM Entry19 Attribute
    #define D0F2_RSVAD_ME19HSEL_1_0			(BIT17 + BIT18)	//0/x/x/x MEM Entry19 Hash Select
    #define D0F2_RSVAD_ME19HEN			BIT16	//0/x/x/x MEM Entry19 Hash Enable
    #define D0F2_RSVAD_ME19LOSEL_1_0			(BIT14 + BIT15)	//0/x/x/x MEM Entry19 Low Order Select
    #define D0F2_RSVAD_ME19TLIST_1_0			(BIT12 + BIT13)	//0/x/x/x MEM Entry19 Target List
    #define D0F2_RSVAD_ME19LADDR_39_28			0xFFF	//FFFh/x/x/x MEM Entry19 Limit Address
#define D0F2_VGA_DECODING		0x9C	//VGA Decoding
    #define D0F2_RX9C_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F2_RSVAD_TSEGPRTDIS			BIT4	//0/x/x/x C2M Tseg Range Protection Control
    #define D0F2_RSVAD_ABSEG_MMIO_TGT			BIT3	//0/x/x/x A/B SEG (VGA Memory) Decode for Target to MMIO - for Memory Address Range in A0000h to BFFFFh
    #define D0F2_RSVAD_ABSEG_SEL			(BIT1 + BIT2)	//0/x/x/x A/B & T SEG Access Control to System Memory or MMIO
    #define D0F2_RSVAD_VGA_TGT			BIT0	//0/x/x/x Legacy VGA IO Target Select - in IO Range 3B0h-3BBh, 3C0h-3DFh
#define D0F2_MEM_HOLE_MHOLE		0x9D	//Memory Hole (MHOLE)
    #define D0F2_RX9D_7_2			0xFC	//0/x/x/x Reserved
    #define D0F2_RHOLE_1_0			(BIT0 + BIT1)	//0/x/x/x Memory Hole
#define D0F2_SMM		0x9E	//SMM
    #define D0F2_RX9E_15_3			0xFFF8	//0/x/x/x Reserved
    #define D0F2_RTSMMEN			BIT2	//0/*/*/* Top SM Memory Enable
    #define D0F2_SM_SIZE_1_0			(BIT0 + BIT1)	//0/*/*/* Top SM Memory Size
#define D0F2_C_D_E_F_SEG		0xA0	//C/D/E/F SEG
    #define D0F2_RSVAD_CDEFSEG_MMIO_TGT			BIT31	//0/x/x/x C/D/E/F SEG Decode Control when Target to MMIO Controlled by RxA0[25:0]
    #define D0F2_RXA0_30_26			0x7C000000	//0/x/x/x Reserved
    #define D0F2_SENFF_1_0			(BIT24 + BIT25)	//0/x/x/x F0000-FFFFFh Memory Space Access Control
    #define D0F2_SENE0_1_0			(BIT22 + BIT23)	//0/x/x/x E0000-E3FFFh Memory Space Access Control
    #define D0F2_SENE4_1_0			(BIT20 + BIT21)	//0/x/x/x E4000-E7FFFh Memory Space Access Control
    #define D0F2_SENE8_1_0			(BIT18 + BIT19)	//0/x/x/x E8000-EBFFFh Memory Space Access Control
    #define D0F2_SENEC_1_0			(BIT16 + BIT17)	//0/x/x/x EC000-EFFFFh Memory Space Access Control
    #define D0F2_SEND0_1_0			(BIT14 + BIT15)	//0/x/x/x D0000-D3FFFh Memory Space Access Control
    #define D0F2_SEND4_1_0			(BIT12 + BIT13)	//0/x/x/x D4000-D7FFFh Memory Space Access Control
    #define D0F2_SEND8_1_0			(BIT10 + BIT11)	//0/x/x/x D8000-DBFFFh Memory Space Access Control
    #define D0F2_SENDC_1_0			(BIT8 + BIT9)	//0/x/x/x DC000-DFFFFh Memory Space Access Control
    #define D0F2_SENC0_1_0			(BIT6 + BIT7)	//0/x/x/x C0000-C3FFFh Memory Space Access Control
    #define D0F2_SENC4_1_0			(BIT4 + BIT5)	//0/x/x/x C4000-C7FFFh Memory Space Access Control
    #define D0F2_SENC8_1_0			(BIT2 + BIT3)	//0/x/x/x C8000-CBFFFh Memory Space Access Control
    #define D0F2_SENCC_1_0			(BIT0 + BIT1)	//0/x/x/x CC000-CFFFFh Memory Space Access Control
#define D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G		0xA4	//Highest SVAD Limit Target to Memory (DRAM Limit Address over 4G)
    #define D0F2_RTOPA_39_20			0xFFFFF000	//00FFFh/x/x/x TOP of System Memory Address over 4G
    #define D0F2_RXA4_11_1			0xFFE	//0/x/x/x Reserved
    #define D0F2_RTOPA_LOCK			BIT0	//0/x/x/x Lock Bit for RTOPA&RLOWTOPA Related Register
#define D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G		0xA8	//Below 4G Highest Memory Limit (DRAM Limit Address below 4G)
    #define D0F2_RLOWTOPA_31_20			0xFFF0	//FF0h/x/x/x TOP of System Memory Address below 4G
    #define D0F2_RXA8_3_0			0xF	//0/x/x/x Reserved
#define D0F2_RESERVED_Z12		0xAA	//Reserved
    #define D0F2_RXAB_15_1			0xFFFE	//0/x/x/x Reserved
    #define D0F2_DUAL_SOCKET_ACTIVE_CTL			BIT0	//0/x/x/x Dual Socket BIOS initial Done
#define D0F2_RESERVED_Z13		0xCC	//Reserved
    #define D0F2_RXCC_15_0			0xFFFF	//0/x/x/x Reserved
#define D0F2_TPR_CTL		0xCE	//TPR Control
    #define D0F2_RXCE_15_5			0xFFE0	//0/x/x/x Reserved
    #define D0F2_RAPICROMODESEL			BIT4	//0/0/x/x APIC Round-Robin Mode Select
    #define D0F2_RAPICCMS			BIT3	//0/0/x/x Reserved
    #define D0F2_RAPICROEN			BIT2	//0/0/x/x Reserved
    #define D0F2_RAPICCMSWEN			BIT1	//0/0/x/x Reserved
    #define D0F2_RAPIC0			BIT0	//0/0/0/x Reserved
#define D0F2_DVAD_ENTRY_0		0xD0	//DVAD Entry 0
    #define D0F2_RDVAD0LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 0 TOP Address
    #define D0F2_RDVAD0BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 0 DRAM Base Address of DVA
    #define D0F2_RXD0_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD0ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 0 Interleave
    #define D0F2_RXD0_2_1			(BIT1 + BIT2)	//0/x/x/x Reserved
    #define D0F2_RDVAD0NXM			BIT0	//0/x/x/x DVAD Entry 0 Not Existed
#define D0F2_DVAD_ENTRY_1		0xD4	//DVAD Entry 1
    #define D0F2_RDVAD1LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 1 TOP Address
    #define D0F2_RDVAD1BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 1 DRAM Base Address of DVA
    #define D0F2_RXD4_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD1ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 1 Interleave
    #define D0F2_RXD4_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD1NXM			BIT0	//0/x/x/x DVAD Entry 1 Not Existed
#define D0F2_DVAD_ENTRY_2		0xD8	//DVAD Entry 2
    #define D0F2_RDVAD2LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 2 TOP Address
    #define D0F2_RDVAD2BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 2 DRAM Base Address of DVA
    #define D0F2_RXD8_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD2ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 2 InterleaveIt should be from SVAD interleave mode settings. But how to set when SVAD interleave mode be set to hash enable([A18|A17|A16]^[A8|A7|A6])[Tony] the same as [ES5]
    #define D0F2_RXD8_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD2NXM			BIT0	//0/x/x/x DVAD Entry 2 Not Existed
#define D0F2_DVAD_ENTRY_3		0xDC	//DVAD Entry 3
    #define D0F2_RDVAD3LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 3 TOP Address
    #define D0F2_RDVAD3BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 3 DRAM Base Address of DVA
    #define D0F2_RXDC_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD3ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 3 InterleaveIt should be from SVAD interleave mode settings. But how to set when SVAD interleave mode be set to hash enable([A18|A17|A16]^[A8|A7|A6])[Tony] the same as [ES5]
    #define D0F2_RXDC_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD3NXM			BIT0	//0/x/x/x DVAD Entry 3 Not Existed
#define D0F2_DVAD_ENTRY_4		0xE0	//DVAD Entry 4
    #define D0F2_RDVAD4LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 4 TOP Address
    #define D0F2_RDVAD4BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 4 DRAM Base Address of DVA
    #define D0F2_RXE0_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD4ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 4 InterleaveIt should be from SVAD interleave mode settings. But how to set when SVAD interleave mode be set to hash enable([A18|A17|A16]^[A8|A7|A6])[Tony] the same as [ES5]
    #define D0F2_RXE0_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD4NXM			BIT0	//0/x/x/x DVAD Entry 4 Not Existed
#define D0F2_DVAD_ENTRY_5		0xE4	//DVAD Entry 5
    #define D0F2_RDVAD5LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 5 TOP Address
    #define D0F2_RDVAD5BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 5 DRAM Base Address of DVA
    #define D0F2_RXE4_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD5ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 5 InterleaveIt should be from SVAD interleave mode settings. But how to set when SVAD interleave mode be set to hash enable([A18|A17|A16]^[A8|A7|A6])[Tony] the same as [ES5]
    #define D0F2_RXE4_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD5NXM			BIT0	//0/x/x/x DVAD Entry 5 Not Existed
#define D0F2_DVAD_ENTRY_6		0xE8	//DVAD Entry 6
    #define D0F2_RDVAD6LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 6 TOP Address
    #define D0F2_RDVAD6BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 6 DRAM Base Address of DVA
    #define D0F2_RXE8_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD6ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 6 InterleaveIt should be from SVAD interleave mode settings. But how to set when SVAD interleave mode be set to hash enable([A18|A17|A16]^[A8|A7|A6])[Tony] the same as [ES5]
    #define D0F2_RXE8_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD6NXM			BIT0	//0/x/x/x DVAD Entry 6 Not Existed
#define D0F2_DVAD_ENTRY_7		0xEC	//DVAD Entry 7
    #define D0F2_RDVAD7LIMIT_39_28			0xFFF00000	//0/x/x/x DVAD Entry 7 TOP Address
    #define D0F2_RDVAD7BASE_40_27			0xFFFC0	//0/x/x/x DVAD Entry 7 DRAM Base Address of DVA
    #define D0F2_RXEC_5			BIT5	//0/x/x/x Reserved
    #define D0F2_RDVAD7ITLVB_1_0			(BIT3 + BIT4)	//0/x/x/x DVAD Entry 7 InterleaveIt should be from SVAD interleave mode settings. But how to set when SVAD interleave mode be set to hash enable([A18|A17|A16]^[A8|A7|A6])[Tony] the same as [ES5]
    #define D0F2_RXEC_2_1			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define D0F2_RDVAD7NXM			BIT0	//0/x/x/x DVAD Entry 7 Not Existed
#define D0F2_DVAD_LOCK_BIT		0xF0	//DVAD Lock Bit
    #define D0F2_RXF0_31_1			0xFFFFFFFE	//0/x/x/x Reserved
    #define D0F2_RDVAD_LOCK			BIT0	//0/x/x/x Lock Bit for DAVD Related Register
#define D0F2_DVAD_ERR_LOG		0xF4	//DVAD Error Log
    #define D0F2_RDVADERRADDR_31_0			0xFFFFFFFF	//HwInit/x/x/x DVAD Error Address Error Log
#define D0F2_DVAD_ERR_LOG_Z1		0xF8	//DVAD Error Log
    #define D0F2_RDVADERRADDR_39_32			0xFF	//HwInit/x/x/x DVAD Error Address Error Log
#define D0F2_DVAD_ERR_STA		0xF9	//DVAD Error Status
    #define D0F2_RDVADERRSTATUS			BIT7	//0/x/x/x DVAD Address Error Status
    #define D0F2_RXF9_6_3			0x78	//0/R/x/x Reserved
    #define D0F2_RDVADERRSMIEN			BIT2	//0/x/x/x DVAD Address Error SMI Enable bit
    #define D0F2_RDVADERRNMIEN			BIT1	//0/x/x/x DVAD Address Error NMI Enable
    #define D0F2_RDVADERRSCIEN			BIT0	//0/x/x/x DVAD Address Error SCI Enable
#define D0F2_DVAD_ERR_INJECTION		0xFA	//DVAD Error Injection
    #define D0F2_RDVADERRINJEN			BIT7	//0/x/x/x DVAD Address Error Injection Enable
    #define D0F2_RXFA_6_0			0x7F	//0/R/x/x Reserved
#define D0F2_DVAD_ERR_INJECTION_Z1		0xFB	//DVAD Error Injection
    #define D0F2_RDVADERRINJADDR_39_32			0xFF	//0/x/x/x DVAD Error Address Error Injection Data
#define D0F2_DVAD_ERR_INJECTION_Z2		0xFC	//DVAD Error Injection
    #define D0F2_RDVADERRINJADDR_31_0			0xFFFFFFFF	//0/x/x/x DVAD Error Address Error Injection Data
#endif
