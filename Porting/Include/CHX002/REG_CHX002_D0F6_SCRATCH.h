//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		SCRATCH					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F6_Scratch_R102(A0).doc(final)MOD_D0F6.xls
#ifndef _CHX002_D0F6_SCRATCH_H
#define _CHX002_D0F6_SCRATCH_H
//D0F6
#define D0F6_VID		0x00	//Vendor ID
    #define D0F6_VENDORID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define D0F6_DID		0x02	//Device ID
    #define D0F6_DEVID_15_0			0xFFFF	//31B5h/x/x/x Device ID
#define D0F6_PCI_CMD		0x04	//PCI Command
    #define D0F6_RX04_15_10			0xFC00	//0/R/x/x Reserved
    #define D0F6_RFBACK			BIT9	//0/R/x/x Fast Back-To-Back Cycle Enable
    #define D0F6_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D0F6_RSETP			BIT7	//0/R/x/x Address / Data Stepping
    #define D0F6_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D0F6_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F6_RMWINV			BIT4	//0/R/x/x Memory Write And Invalidate
    #define D0F6_RSPCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D0F6_RMSTR			BIT2	//1b/R/x/x PCI Master Function
    #define D0F6_RENMEM			BIT1	//1b/R/x/x Memory Space Access
    #define D0F6_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F6_PCI_STA		0x06	//PCI Status
    #define D0F6_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F6_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F6_SMABORT			BIT13	//0/R/x/x Received Master-Abort (Except Special Cycle)
    #define D0F6_STABORTM			BIT12	//0/R/x/x Received Target-Abort
    #define D0F6_STABORTS			BIT11	//0/R/x/x Target-Abort Assertion
    #define D0F6_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D0F6_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F6_RFBKS			BIT7	//0/R/x/x Capable Of Accepting Fast Back-To-Back As A Target
    #define D0F6_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F6_R66M			BIT5	//0/R/x/x 66MHz Capability
    #define D0F6_RCAP			BIT4	//0/R/x/x Support New Capability List
    #define D0F6_RX04_19_16			0xF	//0/R/x/x Reserved
#define D0F6_REV_ID		0x08	//Revision ID
    #define D0F6_RX08_7_0			0xFF	//04h/x/x/x Revision Code
#define D0F6_CLASS_CODE		0x09	//Class Code
    #define D0F6_CLASSCODE_23_0			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F6_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F6_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D0F6_LATENCY_TIMER		0x0D	//Latency Timer
    #define D0F6_RX0C_15_8			0xFF	//0/R/x/x Maximum Time Slice For This Function As A Master On The PCI Bus
#define D0F6_HEADER_TYPE		0x0E	//Header Type
    #define D0F6_RX0C_23_16			0xFF	//80h/R/x/x Header Type
#define D0F6_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D0F6_RX0C_31_24			0xFF	//0/R/x/x BIST Support
#define D0F6_BASE_ADR_REGS_1		0x10	//Base Address Registers 1
    #define D0F6_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 1
#define D0F6_BASE_ADR_REGS_2		0x14	//Base Address Registers 2
    #define D0F6_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 2
#define D0F6_BASE_ADR_REGS_3		0x18	//Base Address Registers 3
    #define D0F6_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 3
#define D0F6_BASE_ADR_REGS_4		0x1C	//Base Address Registers 4
    #define D0F6_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 4
#define D0F6_BASE_ADR_REGS_5		0x20	//Base Address Registers 5
    #define D0F6_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 5
#define D0F6_BASE_ADR_REGS_6		0x24	//Base Address Registers 6
    #define D0F6_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 6
#define D0F6_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F6_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F6_SVID		0x2C	//Subsystem Vendor ID
    #define D0F6_RX2C_15_0			0xFFFF	//0/x/x/x Subsystem Vendor ID
#define D0F6_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F6_RX2C_31_16			0xFFFF	//0/x/x/x Subsystem ID
#define D0F6_CAP_POINTER		0x34	//Capability Pointer
    #define D0F6_RX34_7_0			0xFF	//0/R/x/x Capability List Pointer
#define D0F6_RESERVED		0x35	//Reserved
    #define D0F6_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D0F6_RESERVED_Z1		0x36	//Reserved
    #define D0F6_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F6_RESERVED_Z2		0x37	//Reserved
    #define D0F6_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F6_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F6_RX3C_15_8			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F6_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F6_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F6_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D0F6_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D0F6_BIOS_SCRATCH_REG_1		0x40	//BIOS Scratch Register 1
    #define D0F6_RSCRH4_31_0			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 1
#define D0F6_BIOS_SCRATCH_REG_2		0x44	//BIOS Scratch Register 2
    #define D0F6_RSCRH4_63_32			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 2
#define D0F6_BIOS_SCRATCH_REG_3		0x48	//BIOS Scratch Register 3
    #define D0F6_RSCRH4_95_64			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 3
#define D0F6_BIOS_SCRATCH_REG_4		0x4C	//BIOS Scratch Register 4
    #define D0F6_RSCRH4_127_96			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 4
#define D0F6_BIOS_SCRATCH_REG_5		0x50	//BIOS Scratch Register 5
    #define D0F6_RSCRH5_31_0			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 5
#define D0F6_BIOS_SCRATCH_REG_6		0x54	//BIOS Scratch Register 6
    #define D0F6_RSCRH5_63_32			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 6
#define D0F6_BIOS_SCRATCH_REG_7		0x58	//BIOS Scratch Register 7
    #define D0F6_RSCRH5_95_64			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 7
#define D0F6_BIOS_SCRATCH_REG_8		0x5C	//BIOS Scratch Register 8
    #define D0F6_RSCRH5_127_96			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 8
#define D0F6_BIOS_SCRATCH_REG_9		0x60	//BIOS Scratch Register 9
    #define D0F6_RSCRH6_31_0			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 9
#define D0F6_BIOS_SCRATCH_REG_10		0x64	//BIOS Scratch Register 10
    #define D0F6_RSCRH6_63_32			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 10
#define D0F6_BIOS_SCRATCH_REG_11		0x68	//BIOS Scratch Register 11
    #define D0F6_RSCRH6_95_64			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 11
#define D0F6_BIOS_SCRATCH_REG_12		0x6C	//BIOS Scratch Register 12
    #define D0F6_RSCRH6_127_96			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 12
#define D0F6_BIOS_SCRATCH_REG_13		0x70	//BIOS Scratch Register 13
    #define D0F6_RSCRH7_31_0			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 13
#define D0F6_BIOS_SCRATCH_REG_14		0x74	//BIOS Scratch Register 14
    #define D0F6_RSCRH7_63_32			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 14
#define D0F6_BIOS_SCRATCH_REG_15		0x78	//BIOS Scratch Register 15
    #define D0F6_RSCRH7_95_64			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 15
#define D0F6_BIOS_SCRATCH_REG_16		0x7C	//BIOS Scratch Register 16
    #define D0F6_RSCRH7_127_96			0xFFFFFFFF	//0/x/x/x BIOS Scratch Register 16
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_1		0x80	//BIOS Extended Scratch Registers 1
    #define D0F6_RESCRH0_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 1
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_2		0x84	//BIOS Extended Scratch Registers 2
    #define D0F6_RESCRH1_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 2
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_3		0x88	//BIOS Extended Scratch Registers 3
    #define D0F6_RESCRH2_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 3
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_4		0x8C	//BIOS Extended Scratch Registers 4
    #define D0F6_RESCRH3_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 4
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_5		0x90	//BIOS Extended Scratch Registers 5
    #define D0F6_RESCRH4_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 5
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_6		0x94	//BIOS Extended Scratch Registers 6
    #define D0F6_RESCRH5_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 6
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_7		0x98	//BIOS Extended Scratch Registers 7
    #define D0F6_RESCRH6_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 7
#define D0F6_BIOS_EXTENDED_SCRATCH_REGS_8		0x9C	//BIOS Extended Scratch Registers 8
    #define D0F6_RESCRH7_31_0			0xFFFFFFFF	//0/x/x/x BIOS Extended Scratch Registers 8
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_0		0xA0	//Control Register for CFG Shadow Registers 0
    #define D0F6_SHADOW_R0_MASK_7_0			0xFF000000	//0/x/x/x Register Mask Bits
    #define D0F6_SHADOW_R0_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R0_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R0_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R0_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R0_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R0_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R0_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_1		0xA4	//Control Register for CFG Shadow Registers 1
    #define D0F6_SHADOW_R1_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R1_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R1_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R1_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R1_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R1_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R1_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R1_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_2		0xA8	//Control Register for CFG Shadow Registers 2
    #define D0F6_SHADOW_R2_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R2_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R2_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R2_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R2_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R2_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH
    #define D0F6_SHADOW_R2_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R2_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_3		0xAC	//Control Register for CFG Shadow Registers 3
    #define D0F6_SHADOW_R3_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R3_TA			BIT23	//0/x/x/x Register Bits For Shadow TA
    #define D0F6_SHADOW_R3_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R3_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R3_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R3_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R3_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R3_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_4		0xB0	//Control Register for CFG Shadow Registers 4
    #define D0F6_SHADOW_R4_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R4_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R4_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R4_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R4_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R4_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R4_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R4_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_5		0xB4	//Control Register for CFG Shadow Registers 5
    #define D0F6_SHADOW_R5_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R5_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R5_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R5_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R5_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R5_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R5_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R5_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_6		0xB8	//Control Register for CFG Shadow Registers 6
    #define D0F6_SHADOW_R6_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R6_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R6_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R6_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R6_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R6_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R6_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R6_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_7		0xBC	//Control Register for CFG Shadow Registers 7
    #define D0F6_SHADOW_R7_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R7_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R7_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R7_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R7_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R7_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R7_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R7_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CFG_SHADOW_REG_0		0xC0	//CFG Shadow Register 0
    #define D0F6_SHADOW_R0_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 0
#define D0F6_CFG_SHADOW_REG_1		0xC1	//CFG Shadow Register 1
    #define D0F6_SHADOW_R1_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 1
#define D0F6_CFG_SHADOW_REG_2		0xC2	//CFG Shadow Register 2
    #define D0F6_SHADOW_R2_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 2
#define D0F6_CFG_SHADOW_REG_3		0xC3	//CFG Shadow Register 3
    #define D0F6_SHADOW_R3_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 3
#define D0F6_CFG_SHADOW_REG_4		0xC4	//CFG Shadow Register 4
    #define D0F6_SHADOW_R4_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 4
#define D0F6_CFG_SHADOW_REG_5		0xC5	//CFG Shadow Register 5
    #define D0F6_SHADOW_R5_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 5
#define D0F6_CFG_SHADOW_REG_6		0xC6	//CFG Shadow Register 6
    #define D0F6_SHADOW_R6_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 6
#define D0F6_CFG_SHADOW_REG_7		0xC7	//CFG Shadow Register 7
    #define D0F6_SHADOW_R7_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 7
#define D0F6_CFG_SHADOW_REG_8		0xC8	//CFG Shadow Register 8
    #define D0F6_SHADOW_R8_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 8
#define D0F6_CFG_SHADOW_REG_9		0xC9	//CFG Shadow Register 9
    #define D0F6_SHADOW_R9_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 9
#define D0F6_CFG_SHADOW_REG_10		0xCA	//CFG Shadow Register 10
    #define D0F6_SHADOW_R10_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 10
#define D0F6_CFG_SHADOW_REG_11		0xCB	//CFG Shadow Register 11
    #define D0F6_SHADOW_R11_DATA_7_0			0xFF	//0/x/x/x Configuration Shadow Register 11
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_8		0xCC	//Control Register for CFG Shadow Registers 8
    #define D0F6_SHADOW_R8_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R8_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R8_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R8_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R8_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R8_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R8_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R8_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_9		0xD4	//Control Register for CFG Shadow Registers 9
    #define D0F6_SHADOW_R9_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R9_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R9_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R9_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R9_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R9_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R9_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R9_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_10		0xD8	//Control Register for CFG Shadow Registers 10
    #define D0F6_SHADOW_R10_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R10_TA			BIT23	//0/x/x/x Register Bits For Shadow TA
    #define D0F6_SHADOW_R10_WC			BIT22	//0/x/x/x Write Enable Bit
    #define D0F6_SHADOW_R10_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R10_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R10_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R10_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R10_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_11		0xDC	//Control Register for CFG Shadow Registers 11
    #define D0F6_SHADOW_R11_MASK_7_0			0xFF000000	//0/x/x/x Write Mask Bits
    #define D0F6_SHADOW_R11_TA			BIT23	//0/x/x/x Register Bits For Shadow TA 
    #define D0F6_SHADOW_R11_WC			BIT22	//0/x/x/x Write Enable Bit 
    #define D0F6_SHADOW_R11_RC			BIT21	//0/x/x/x Read Enable Bit
    #define D0F6_SHADOW_R11_DEV_4_0			0x1F0000	//0/x/x/x Device Number
    #define D0F6_SHADOW_R11_RCRBH			BIT15	//0/x/x/x Register Bits For Shadow RCRBH 
    #define D0F6_SHADOW_R11_FUN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Function Number
    #define D0F6_SHADOW_R11_REG_11_0			0xFFF	//0/x/x/x Register Offset
#define D0F6_CTL_REG_FOR_RAIDA0_MMIO_CFG_SHADOW_REGS		0xE0	//Control Register for RAIDA0 MMIO CFG Shadow Registers
    #define D0F6_RXE0_31_12			0xFFFFF000	//0/x/x/x Reserved
    #define D0F6_SHADOW_R11_RDA0MMIO			BIT11	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R10_RDA0MMIO			BIT10	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R9_RDA0MMIO			BIT9	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R8_RDA0MMIO			BIT8	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R7_RDA0MMIO			BIT7	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R6_RDA0MMIO			BIT6	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R5_RDA0MMIO			BIT5	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R4_RDA0MMIO			BIT4	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R3_RDA0MMIO			BIT3	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R2_RDA0MMIO			BIT2	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R1_RDA0MMIO			BIT1	//0/x/x/x Register Bits For Shadow RAIDA0 
    #define D0F6_SHADOW_R0_RDA0MMIO			BIT0	//0/x/x/x Register Bits For Shadow RAIDA0 
#define D0F6_CTL_REG_FOR_RAIDA1_MMIO_CFG_SHADOW_REGS		0xE4	//Control Register for RAIDA1 MMIO CFG Shadow Registers
    #define D0F6_RXE4_31_12			0xFFFFF000	//0/x/x/x Reserved
    #define D0F6_SHADOW_R11_RDA1MMIO			BIT11	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R10_RDA1MMIO			BIT10	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R9_RDA1MMIO			BIT9	//0/x/x/x Register Bits For Shadow RAIDA1
    #define D0F6_SHADOW_R8_RDA1MMIO			BIT8	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R7_RDA1MMIO			BIT7	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R6_RDA1MMIO			BIT6	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R5_RDA1MMIO			BIT5	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R4_RDA1MMIO			BIT4	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R3_RDA1MMIO			BIT3	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R2_RDA1MMIO			BIT2	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R1_RDA1MMIO			BIT1	//0/x/x/x Register Bits For Shadow RAIDA1 
    #define D0F6_SHADOW_R0_RDA1MMIO			BIT0	//0/x/x/x Register Bits For Shadow RAIDA1 
#define D0F6_NM_PWR_STATE		0xE8	//NM Power State
    #define D0F6_RXE8_31_6			0xFFFFFFC0	//0/x/x/x Reserved
    #define D0F6_D0F6_RXE8B5			BIT5	//0/x/x/x RCLASS_CODE_LOCK_D0F6
    #define D0F6_D0F6_RXE8B4			BIT4	//0/x/x/x RVID_DID_LOCK_D0F6
    #define D0F6_D0F6_RXE8B3			BIT3	//0/x/x/x RDID_RID_LOCK_D0F6
    #define D0F6_RPOWER_ST_2_0			(BIT0 + BIT1 + BIT2)	//HwInit/0/x/x Chip Internal Power States
#define D0F6_RESERVED_Z3		0xEC	//Reserved
    #define D0F6_RXEC_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define D0F6_RESERVED_Z4		0xF0	//Reserved
    #define D0F6_RXF0_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#endif
