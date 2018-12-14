//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		PMCTLANDCHIPTEST					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F4_PMCtlAndChipTest_R104(A0).doc(final)MOD_D0F4.xls
#ifndef _CHX002_D0F4_PMCTLANDCHIPTEST_H
#define _CHX002_D0F4_PMCTLANDCHIPTEST_H
//D0F4
#define D0F4_VID		0x00	//Vendor ID
    #define D0F4_VENDORID			0xFFFF	//1106h/x/x/x Vendor ID
#define D0F4_DID		0x02	//Device ID
    #define D0F4_DEVICEID			0xFFFF	//31B3h/x/x/x Device ID
#define D0F4_PCI_CMD		0x04	//PCI Command
    #define D0F4_RX05H			0xFC00	//0/R/x/x Reserved
    #define D0F4_RFBACK			BIT9	//0/R/x/x Fast Back-to-back Cycle Enable
    #define D0F4_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D0F4_RSETP			BIT7	//0/R/x/x Address/ Data Stepping
    #define D0F4_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D0F4_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F4_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D0F4_RSPCYC			BIT3	//0/R/x/x Respond to Special Cycle
    #define D0F4_RMSTR			BIT2	//1b/R/x/x PCI Master Function
    #define D0F4_RENMEM			BIT1	//1b/R/x/x Memory Space Access
    #define D0F4_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F4_PCI_STA		0x06	//PCI Status
    #define D0F4_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F4_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F4_SMABORT			BIT13	//0/R/x/x Received Master Abort (Except Special Cycle)
    #define D0F4_STABORTM			BIT12	//0/R/x/x Received Target Abort
    #define D0F4_STABORTS			BIT11	//0/R/x/x Target Abort Assertion
    #define D0F4_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D0F4_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F4_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-back as a Target
    #define D0F4_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F4_R66M			BIT5	//0/R/x/x 66MHz Capability
    #define D0F4_RCAP			BIT4	//0/R/x/x Support New Capability List
    #define D0F4_RX06H			0xF	//0/R/x/x Reserved
#define D0F4_REV_ID		0x08	//Revision ID
    #define D0F4_D0F4_08H			0xFF	//04h/x/x/x Revision Code
#define D0F4_CLASS_CODE		0x09	//Class Code
    #define D0F4_CLASSCODE_23_0			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F4_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F4_RX0CH			0xFF	//0/x/x/x Cache Line Size
#define D0F4_LATENCY_TIMER		0x0D	//Latency Timer
    #define D0F4_D0F4_0DH			0xFF	//0/R/x/x Latency Timer 
#define D0F4_HEADER_TYPE		0x0E	//Header Type
    #define D0F4_D0F4_0EH			0xFF	//80h/R/x/x Header Type
#define D0F4_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D0F4_D0F4_0FH			0xFF	//0/R/x/x BIST
#define D0F4_BASE_ADR_REGS_0		0x10	//Base Address Registers 0
    #define D0F4_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address 0
#define D0F4_BASE_ADR_REGS_1		0x14	//Base Address Registers 1
    #define D0F4_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address 1
#define D0F4_BASE_ADR_REGS_2		0x18	//Base Address Registers 2
    #define D0F4_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address 2
#define D0F4_BASE_ADR_REGS_3		0x1C	//Base Address Registers 3
    #define D0F4_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address 3
#define D0F4_BASE_ADR_REGS_4		0x20	//Base Address Registers 4
    #define D0F4_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address 4
#define D0F4_BASE_ADR_REGS_5		0x24	//Base Address Registers 5
    #define D0F4_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address 5
#define D0F4_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F4_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F4_SVID		0x2C	//Subsystem Vendor ID
    #define D0F4_D0F4_2CH			0xFFFF	//0/*/x/x Subsystem Vendor ID
#define D0F4_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F4_D0F4_2EH			0xFFFF	//0/*/x/x Subsystem ID
#define D0F4_CAP_POINTER		0x34	//Capability Pointer
    #define D0F4_CAPPTR_XBIT_7_0			0xFF	//0/R/x/x Capability List Pointer
#define D0F4_RESERVED		0x35	//Reserved
    #define D0F4_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D0F4_RESERVED_Z1		0x36	//Reserved
    #define D0F4_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F4_RESERVED_Z2		0x37	//Reserved
    #define D0F4_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F4_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F4_RX3C_15_8			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F4_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F4_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F4_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D0F4_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D0F4_PLL_TEST_MODE_0		0x40	//PLL Test Mode 0
    #define D0F4_PCIE_TST_MODE			BIT7	//0/0/0/0 PCIe EPHY Test Mode Enable
    #define D0F4_D0F4_40H0			0x78	//0/0/x/x Reserved
    #define D0F4_D0F4_RX40B2			BIT2	//0/x/x/x RCLASS_CODE_LOCK_D0F4
    #define D0F4_D0F4_RX40B1			BIT1	//0/x/x/x RVID_DID_LOCK_D0F4
    #define D0F4_D0F4_RX40B0			BIT0	//0/x/x/x RDID_RID_LOCK_D0F4
#define D0F4_PLL_TEST_MODE_1		0x41	//PLL Test Mode 1
    #define D0F4_D0F4_41H0			0xFF	//0/0/x/x Reserved
#define D0F4_CHIP_TEST_MODE		0x42	//Chip Test Mode
    #define D0F4_RSBDBG			BIT7	//0/0/x/x PCIe Port4 or Port0 Works under SB Debug Mode
    #define D0F4_RSBDBGSEL_1_0			(BIT5 + BIT6)	//0/0/x/x SB Debug Mode Channel Select
    #define D0F4_RFSBCDBG			BIT4	//0/0/x/x PCIe Port4 or Port0 Works under FSBC Debug Mode
    #define D0F4_RSBDBG_CLKEN			BIT3	//1b/1/x/x RSBDBG_CLKEN
    #define D0F4_RRDBGSBSELBYNB			BIT2	//0/x/x/x SM Debug Signal Selection Control
    #define D0F4_RP92D1SEL			BIT1	//0/x/x/x A20M# De-assertion Select
    #define D0F4_RENDBGLINK			BIT0	//0/x/x/x Debug Link Enable
#define D0F4_TEST_MODE_REG		0x43	//Test Mode Register
    #define D0F4_RPCCAOUTARB_1_0			(BIT6 + BIT7)	//00b/0/x/x SBDBGC: Selected Path Output Interface Arbiter
    #define D0F4_RSBDBG_FULL_BLK			BIT5	//0/0/x/x RSBDBG_FULL_BLK
    #define D0F4_RFSBCDRAMCDBG			BIT4	//1b/1/x/x FSBC-to-DRAM Debug Path with Dedicated CDC  CLK Enable
    #define D0F4_RFIXLPLT			BIT3	//0/0/x/x Make Loop Back Latency Fixed 
    #define D0F4_RLPLTCHK			BIT2	//0/0/x/x Check Whether Multi-Lane Link Has Too Much Latency Skew
    #define D0F4_RPHYEST			BIT1	//0/0/x/x PHYES (PHY Electrical Sub-module) Test Mode
    #define D0F4_RPHYTST			BIT0	//0/0/x/x PHY Layer Test Mode
#define D0F4_DEBUG_SEL_SIGNAL_0		0x44	//Debug Select Signal 0
    #define D0F4_RFSBC_OS			BIT31	//0/x/x/x FSBC Output Select
    #define D0F4_RRDBGMODE			BIT30	//0/x/x/x Debugging Mode
    #define D0F4_RRDBGNBSBSEL_G0_1_0			(BIT28 + BIT29)	//0/x/x/x Debugging Signal Output Selection
    #define D0F4_RRGFXDBGSEL_G1			BIT27	//0/x/x/x Debugging Signal Group 1 Selection
    #define D0F4_RRGFXDBGSEL_G0			BIT26	//0/x/x/x Debugging Signal Group 0 Selection
    #define D0F4_RDBGMX_NBTOP_G1_RSP_5_0			0x3F00000	//0/x/x/x Group 1 Debug Port Output Signal Select
    #define D0F4_RDBGMX_MODULE_G1_RSP_19_0			0xFFFFF	//0/x/x/x Group 1 Debug Port Output Signal Select
#define D0F4_DEBUG_SEL_SIGNAL_1		0x48	//Debug Select Signal 1
    #define D0F4_RDBGGFXSELSEL			BIT31	//0/x/x/x GFX Debug Selection from PAD or Register
    #define D0F4_RRDBGNBSBSEL_G1_1_0			(BIT29 + BIT30)	//0/x/x/x Debugging Signal Output Selection for Group1
    #define D0F4_RRDBGCHDVPSEL			BIT28	//0/x/x/x Debug Signal Output PAD Select for DVP PAD or other SUS PAD
    #define D0F4_RRDBGCHSEL_1_0			(BIT26 + BIT27)	//0/x/x/x Debug Signal Output Pad Select
    #define D0F4_RDBGMX_NBTOP_G0_RSP_5			BIT25	//0/x/x/x Group 0 Debug Port Output Signal Select
    #define D0F4_RDBGMX_NBTOP_G0_RSP_4			BIT24	//0/x/x/x Group 0 Debug Port Output Signal Select
    #define D0F4_RDBGMX_NBTOP_G0_RSP_3_0			0xF00000	//0/x/x/x Group 0 Debug Port Output Signal Select
    #define D0F4_RDBGMX_MODULE_G0_RSP_19_0			0xFFFFF	//0/x/x/x Group 0 Debug Port Output Signal Select
#define D0F4_ASYNCHRONOUS_CIRCUIT_TESTING_MODE_1		0x4C	//Asynchronous Circuit Testing Mode 1
    #define D0F4_RC2DBYPASS			BIT7	//0/0/x/x Bypass C2D (Host to DRAMC) Conversion
    #define D0F4_RD2CBYPASS			BIT6	//0/0/x/x Bypass D2C (DRAMC to Host) Conversion
    #define D0F4_RC2GBYPASS			BIT5	//0/0/x/x Bypass C2G (Host to PCI, 66Mhz) Conversion
    #define D0F4_RG2CBYPASS			BIT4	//0/0/x/x Bypass G2C (PCI, 66Mhz to Host) Conversion
    #define D0F4_RC2PBYPASS			BIT3	//0/0/x/x Bypass C2P (Host to NVC, 66Mhz) Conversion Circuit (For Speed Test)
    #define D0F4_RP2CBYPASS			BIT2	//0/0/x/x Bypass P2C (NVC, 66Mhz to Host) Conversion Circuit (For Speed Test)
    #define D0F4_RD2MBYPASS			BIT1	//0/0/x/x Bypass DRAM to MCU Conversion Circuit (For Speed Test)
    #define D0F4_RM2DBYPASS			BIT0	//0/0/x/x Bypass MCU to DRAM  Conversion Circuit (For Speed Test)
#define D0F4_ASYNCHRONOUS_CIRCUIT_TESTING_MODE_2		0x4D	//Asynchronous Circuit Testing Mode 2
    #define D0F4_RG2EBYPASS			BIT7	//0/0/x/x Bypass G2E (AGPC, 133Mhz to PCIe, 125Mhz) Conversion Circuit (For Speed Test)
    #define D0F4_RE2GBYPASS			BIT6	//0/0/x/x Reserved
    #define D0F4_RD2EBYPASS			BIT5	//0/0/x/x Bypass D2E (DRAMC to PCIe, 125Mhz) Conversion Circuit (For Speed Test)
    #define D0F4_RE2DBYPASS			BIT4	//0/0/x/x Bypass E2D (PCIe, 125Mhz to DRAMC) Conversion Circuit (For Speed Test)
    #define D0F4_RC2EBYPASS			BIT3	//0/0/x/x Bypass C2E (Host to PCIe, 125Mhz) Conversion Circuit (For Speed Test)
    #define D0F4_RE2CBYPASS			BIT2	//0/0/x/x Bypass E2C (PCIe, 125Mhz to Host) Conversion Circuit (For Speed Test)
    #define D0F4_RP2EBYPASS			BIT1	//0/0/x/x Reserved
    #define D0F4_RE2PBYPASS			BIT0	//0/0/x/x Reserved
#define D0F4_ASYNCHRONOUS_CIRCUIT_TESTING_MODE_3		0x4E	//Asynchronous Circuit Testing Mode 3
    #define D0F4_RC2XBYPASS			BIT7	//0/0/x/x Reserved
    #define D0F4_RX2CBYPASS			BIT6	//0/0/x/x Reserved
    #define D0F4_RC2XHBYPASS			BIT5	//0/0/x/x Bypass C2XH (Host to XHCLK, 125Mhz) Conversion Circuit (For Speed Test)
    #define D0F4_RXH2CBYPASS			BIT4	//0/0/x/x Bypass XH2C (XHCLK, 125Mhz to Host) Conversion Circuit (For Speed Test)
    #define D0F4_RC2AHBYPASS			BIT3	//0/0/x/x Bypass C2AH (Host to SACLK, 150Mhz) Conversion Circuit (For Speed Test)
    #define D0F4_RAH2CBYPASS			BIT2	//0/0/x/x Bypass AH2C (SACLK, 150Mhz to Host) Conversion Circuit (For Speed Test)
    #define D0F4_RB2CBYPASS			BIT1	//0/0/x/x Bypass BIU2C (BICLK, 300Mhz to Host) Conversion Circuit (For Speed Test)
    #define D0F4_D0F4_4EH			BIT0	//0/0/x/x Reserved
#define D0F4_RESERVED_Z3		0x4F	//Reserved
    #define D0F4_RSV_4F			0xFF	//0/0/x/x Reserved
#define D0F4_VDD_OFF_DEBUG_CTL		0x50	//VDD OFF Debug Control
    #define D0F4_RSV_50_7			BIT7	//0/0/x/x Reserved
    #define D0F4_D0F4_50H			0x7C	//0/0/x/x Reserved
    #define D0F4_RBLWFCD			BIT1	//0/0/x/x Block CPUIF WFIFO credit update to CPU
    #define D0F4_RSOCCAP_DUMP_EN			BIT0	//0/0/x/x SOCCAP Dump Mode Enable
#define D0F4_VDD_OFF_DEBUG_CTL_Z1		0x51	//VDD OFF Debug Control
    #define D0F4_RSV_51			0xFF	//0/0/x/x Reserved
#define D0F4_SOCCAP_DUMP_CTL		0x52	//SOCCAP Dump Control
    #define D0F4_RSOCCAP_DUMPSZ_2_0			(BIT13 + BIT14 + BIT15)	//0/0/x/x SOCCAP Dump Space Size in DRAM
    #define D0F4_RSOCCAP_DUMPBS_37_25			0x1FFF	//0/0/x/x SOCCAP Dump Base Address in DRAM
#define D0F4_DDRPHY_BIST_CTL_0		0x54	//DDRPHY BIST Control 0
    #define D0F4_DATA_RANDOM_SEED_7_0			0xFF	//59h/59h/x/x BIST Random Data Seed for DDRPHY BIST
#define D0F4_DDRPHY_BIST_CTL_1		0x55	//DDRPHY BIST Control 1
    #define D0F4_RBIST_LENGTH_7_0			0xFF	//18h/18h/x/x BIST Length (QW) for DDRPHY BIST
#define D0F4_DDRPHYA_BIST_CTL_0		0x56	//DDRPHYA BIST Control 0
    #define D0F4_DDRPHYA_BIST_FAIL_7_0			0xFF	//HwInit/x/x/x DDRPHYA BIST Result
#define D0F4_DDRPHYA_BIST_CTL_1		0x57	//DDRPHYA BIST Control 1
    #define D0F4_DDRPHYA7_BISTEN			BIT7	//0/0/x/x DDR PHYA7 BIST Enable
    #define D0F4_DDRPHYA6_BISTEN			BIT6	//0/0/x/x DDR PHYA6 BIST Enable
    #define D0F4_DDRPHYA5_BISTEN			BIT5	//0/0/x/x DDR PHYA5 BIST Enable
    #define D0F4_DDRPHYA4_BISTEN			BIT4	//0/0/x/x DDR PHYA4 BIST Enable
    #define D0F4_DDRPHYA3_BISTEN			BIT3	//0/0/x/x DDR PHYA3 BIST Enable
    #define D0F4_DDRPHYA2_BISTEN			BIT2	//0/0/x/x DDR PHYA2 BIST Enable
    #define D0F4_DDRPHYA1_BISTEN			BIT1	//0/0/x/x DDR PHYA1 BIST Enable
    #define D0F4_DDRPHYA0_BISTEN			BIT0	//0/0/x/x DDR PHYA0 BIST Enable
#define D0F4_DDRPHYA_BIST_CTL_2		0x58	//DDRPHYA BIST Control 2
    #define D0F4_DDRPHYA_BISTRST			BIT7	//0/0/x/x DDRPHYA BIST Reset
    #define D0F4_DDRPHYA8_BISTEN			BIT6	//0/0/x/x DDR PHYA8 BIST Enable
    #define D0F4_DDRPHYA_BIST_FAIL8			BIT5	//HwInit/x/x/x DDRPHYA8 BIST Result
    #define D0F4_PHYA_BIST_DLY_SEL_1_0			(BIT3 + BIT4)	//00b/0/x/X DDRPHYA BIST Input Capture Range Select
    #define D0F4_RX58_2_1			(BIT1 + BIT2)	//0/0/x/X Reserved 
    #define D0F4_DDRPHYA_BIST_DONE			BIT0	//HwInit/0/x/X DDRPHYA BIST Done
#define D0F4_DDRPHYB_BIST_CTL_0		0x59	//DDRPHYB BIST Control 0
    #define D0F4_DDRPHYB_BIST_FAIL_7_0			0xFF	//HwInit/x/x/x DDRPHYB BIST Result
#define D0F4_DDRPHYB_BIST_CTL_1		0x5A	//DDRPHYB BIST Control 1
    #define D0F4_DDRPHYB7_BISTEN			BIT7	//0/0/x/x DDR PHYB7 BIST Enable
    #define D0F4_DDRPHYB6_BISTEN			BIT6	//0/0/x/x DDR PHYB6 BIST Enable
    #define D0F4_DDRPHYB5_BISTEN			BIT5	//0/0/x/x DDR PHYB5 BIST Enable
    #define D0F4_DDRPHYB4_BISTEN			BIT4	//0/0/x/x DDR PHYB4 BIST Enable
    #define D0F4_DDRPHYB3_BISTEN			BIT3	//0/0/x/x DDR PHYB3 BIST Enable
    #define D0F4_DDRPHYB2_BISTEN			BIT2	//0/0/x/x DDR PHYB2 BIST Enable
    #define D0F4_DDRPHYB1_BISTEN			BIT1	//0/0/x/x DDR PHYB1 BIST Enable
    #define D0F4_DDRPHYB0_BISTEN			BIT0	//0/0/x/x DDR PHYB0 BIST Enable
#define D0F4_DDRPHYB_BIST_CTL_2		0x5B	//DDRPHYB BIST Control 2
    #define D0F4_DDRPHYB_BISTRST			BIT7	//0/0/x/X DDRPHYB BIST Reset
    #define D0F4_DDRPHYB8_BISTEN			BIT6	//0/0/x/X DDR PHYB8 BIST Enable
    #define D0F4_DDRPHYB_BIST_FAIL8			BIT5	//HwInit/0/x/X DDRPHYB8 BIST Result
    #define D0F4_PHYB_BIST_DLY_SEL_1_0			(BIT3 + BIT4)	//00b/0/x/X DDRPHYB BIST Input Capture Range Select
    #define D0F4_RX5B_2_1			(BIT1 + BIT2)	//0/0/x/X Reserved 
    #define D0F4_DDRPHYB_BIST_DONE			BIT0	//HwInit/0/x/X DDRPHYB BIST Done
#define D0F4_DDRPHYB_BIST_CTL_3		0x5C	//DDRPHYB BIST Control 3
    #define D0F4_D0F4_5CH			0xF0	//0/0/x/x Reserved
    #define D0F4_DDRPHYB_BIST_MODE			BIT3	//0/0/x/x Enable DDRPHY BIST Mode
    #define D0F4_DDRPHYA_BIST_MODE			BIT2	//0/0/x/x Enable DDRPHY BIST Mode
    #define D0F4_PHYA_PAD_SYNC_EN			BIT1	//0/0/x/x PHYA Bist Enable Control 
    #define D0F4_PHYB_PAD_SYNC_EN			BIT0	//0/0/x/x PHYB Bist Enable Control 
#define D0F4_RESERVED_Z4		0x5D	//Reserved
    #define D0F4_PHYB_TST_RXDLY_SEL_3_0			0xF0	//0/0/x/x DDRPHY BIST RX Capture->Compare Range Select 0
    #define D0F4_PHYA_TST_RXDLY_SEL_3_0			0xF	//0/0/x/x DDRPHY BIST RX Capture->Compare Range Select 1
#define D0F4_RESERVED_Z5		0x5E	//Reserved
    #define D0F4_PHYB_DEBUG_SEL_3_0			0xF0	//0/0/x/x DDRPHY Debug Group Select 0
    #define D0F4_PHYA_DEBUG_SEL_3_0			0xF	//0/0/x/x DDRPHY Debug Group Select 1
#define D0F4_RESERVED_Z6		0x5F	//Reserved
    #define D0F4_RX5F_7_6			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F4_PHYA_BIST_DBG_SEL_2_0			(BIT3 + BIT4 + BIT5)	//000b/0/x/X DDRPHYA BIST Debug Select
    #define D0F4_PHYB_BIST_DBG_SEL_2_0			(BIT0 + BIT1 + BIT2)	//000b/0/x/X DDRPHYB BIST Debug Select
#define D0F4_PM_MODE		0x60	//Power Management Mode
    #define D0F4_RDYNPM			BIT7	//0/0/1/1 Dynamic Clock Stop Feature for the Clocks in NM Block
    #define D0F4_D0F4_60H			0x78	//0/0/x/x Reserved
    #define D0F4_RNBPOPUP			BIT2	//0/0/x/x Reserved
    #define D0F4_RBMBZW_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F4_DYNAMIC_CLK_STOP_CTL		0x61	//Dynamic Clock Stop Control
    #define D0F4_RX61_7			BIT7	//0/0/x/x Reserved
    #define D0F4_RX61_6			BIT6	//0/*0/*0/*0 Reserved
    #define D0F4_RX61_5_3			(BIT3 + BIT4 + BIT5)	//0/0/x/x Reserved
    #define D0F4_RGFXPM			BIT2	//0/x/x/x Reserved
    #define D0F4_D0F4_61H3			BIT1	//0/0/x/x Reserved
    #define D0F4_RDYNCRMCAPM			BIT0	//0/0/1/1 Dynamic Clock Stop Control for CPUIF CRMCA Part
#define D0F4_RESERVED_Z7		0x62	//Reserved
    #define D0F4_D0F4_62H			0xFF	//0/0/x/x Reserved
#define D0F4_RESERVED_Z8		0x63	//Reserved
    #define D0F4_D0F4_63H			0xFE	//0/0/x/x Reserved
    #define D0F4_RFSBCTRIGINSERT			BIT0	//0/0/x/x FSBCTRIGDONE Cycle Insert Control
#define D0F4_PCIE_TRIGGER_ADR		0x64	//PCIe Trigger Address
    #define D0F4_RPCIE_TADDR_31_0			0xFFFFFFFF	//00000160h/00000160h/x/x Low 32-bit Trigger Address for PCIe
#define D0F4_PCIE_TRIGGER_ADR_Z1		0x68	//PCIe Trigger Address
    #define D0F4_RPCIE_TADDR_63_32			0xFFFFFFFF	//0/0/x/x High 32-bit Trigger Address for PCIe
#define D0F4_RESERVED_Z9		0x6C	//Reserved
    #define D0F4_D0F4_6CH			0xFF	//0/0/x/x Reserved
#define D0F4_RESERVED_Z10		0x6D	//Reserved
    #define D0F4_D0F4_6DH			0xFF	//0/0/x/x Reserved
#define D0F4_HOST_PAD_DYNAMIC_CTL		0x6E	//Host Pad Dynamic Control
    #define D0F4_D0F4_6EH			0xFF	//0/0/x/x Reserved
#define D0F4_RESERVED_Z11		0x6F	//Reserved
    #define D0F4_D0F4_6FH			0xFF	//0/0/x/x Reserved
#define D0F4_DRAM_DYNAMIC_CLK_CTL		0x70	//DRAM Dynamic Clock Control
    #define D0F4_D0F4_70			0xFF	//0/0/x/x Reserved
#define D0F4_DRAMC_PM_REG_1		0x71	//DRAMC Power Management Register 1
    #define D0F4_RDYNCKE			BIT7	//0/0/*/* Dynamic CKE when DRAM is Idle
    #define D0F4_RDMIOPWD			BIT6	//0/0/1/1 Dynamic DRAM I/O Pad Power-down (i.e., Float)
    #define D0F4_RMAHLD			BIT5	//0/0/1/1 Toggle Reduction on DRAM MA/SCMD Signals
    #define D0F4_D0F4_71H			0x1F	//0/x/x/x Reserved
#define D0F4_DRAMC_PM_REG_2		0x72	//DRAMC Power Management Register 2
    #define D0F4_RDMDCLKCSPM			BIT7	//0/0/1/1 Reserved
    #define D0F4_RDMDCLKSCMDPM			BIT6	//0/0/1/1 Reserved
    #define D0F4_RDCLKREQPM			BIT5	//0/0/1/1 Power Management for Reordered Request Queue ((DMREQ))
    #define D0F4_RDCLKWFFPUSHPM			BIT4	//0/0/1/1 Power Management for Write Data FIFO Input
    #define D0F4_RDCLKWFFPOPPM			BIT3	//0/0/1/1 Power Management for Write Data FIFO Output
    #define D0F4_RDMDCLKQUEPM			BIT2	//0/0/1/1 Power Management for DMQUE
    #define D0F4_RDMDCLKPAGPM			BIT1	//0/0/1/1 Power Management for Page Table
    #define D0F4_RDMDCLKPGTIMPM			BIT0	//0/0/1/1 Power Management for Page Timer
#define D0F4_DRAMC_PM_REG_3		0x73	//DRAMC Power Management Register 3
    #define D0F4_RDRAMCPM			BIT7	//0/0/1/1 Dynamic Clock Stop Control for DRAM Controller
    #define D0F4_RDMDCLKTXIOPM			BIT6	//0/0/1/1 Reserved
    #define D0F4_RREFCNTPM			BIT5	//0/0/0/0 Reserved
    #define D0F4_RREFAPM			BIT4	//0/0/1/1 Reserved
    #define D0F4_RDMDCLKRXIOPM			BIT3	//0/0/1/1 Reserved
    #define D0F4_RDMDCLKCKEPM			BIT2	//0/0/1/1 Reserved
    #define D0F4_RDMDCLKRXPM			BIT1	//0/0/1/1 Dynamical Clock Enable for the Control Block for the DRAM Read Cycle
    #define D0F4_RDMDCLKTXPM			BIT0	//0/0/1/1 Dynamical Clock Enable for the Control Block for the DRAM Write Cycle
#define D0F4_RAIDA_DYNAMIC_CLK_CTL		0x74	//RAIDA Dynamic clock control
    #define D0F4_D0F4_74H			0xFC	//0/0/x/x Reserved
    #define D0F4_RRDA1PM			BIT1	//0/0/1/1 RAIDA1 Dynamic Clock Enable
    #define D0F4_RRDA0PM			BIT0	//0/0/1/1 RAIDA0 Dynamic Clock Enable
#define D0F4_RESERVED_Z12		0x75	//Reserved
    #define D0F4_D0F4_75H			0xFF	//0/0/x/x Reserved
#define D0F4_GMINT_DYNAMIC_CLK_CTL		0x76	//Graphics-Memory Interface (GMINT) Dynamic Clock Control
    #define D0F4_D0F4_76H			0xF0	//0/0/x/x Reserved
    #define D0F4_RAGMINTPM			BIT3	//0/0/1/1 Enable All GMINTA Module Dynamic Clock
    #define D0F4_RBGMINTPM			BIT2	//0/0/1/1 Enable All GMINTB Module Dynamic Clock
    #define D0F4_RAGREQCPM			BIT1	//0/0/1/1 GMINTA Request Queue Control Clock Gating
    #define D0F4_RBGREQCPM			BIT0	//0/0/1/1 GMINTB Request Queue Control Clock Gating
#define D0F4_GMINT_DYNAMIC_CLK_CTL_Z1		0x77	//GMINT Dynamic Clock Control
    #define D0F4_RAGWFCPM			BIT7	//0/0/1/1 GMINTA Write FIFO Control Clock Gating
    #define D0F4_RBGWFCPM			BIT6	//0/0/1/1 GMINTB Write FIFO Control Clock Gating
    #define D0F4_RAGRDCPM			BIT5	//0/0/1/1 GMINTA Read Data Control Clock Gating
    #define D0F4_RBGRDCPM			BIT4	//0/0/1/1 GMINTB Read Data Control Clock Gating
    #define D0F4_D0F4_77H			0xF	//0/0/x/x Reserved
#define D0F4_PXPTRF_DYNAMIC_CLK_1		0x78	//Central Traffic Controller (PXPTRF) Dynamic Clock 1
    #define D0F4_RDYNPXPHPM			BIT7	//0/0/1/1 Level-1 Host Clock (HCLK) Enable
    #define D0F4_RDYNPXPGPM			BIT6	//0/0/1/1 Level-1 Global PCI Clock (GCLK, Running at 66MHz) Enable
    #define D0F4_RDYNPXPEPM			BIT5	//0/0/1/1 Level-1 PCIe Clock (ECLK, Running at 250MHz or 500MHz) Enable All for PEG, PE1, PE0, PE2 and PE3
    #define D0F4_RPXPC2PHPM			BIT4	//0/0/1/1 Down-stream HCLK Enable
    #define D0F4_RPXPC2PGPM			BIT3	//0/0/1/1 Down-stream GCLK Enable
    #define D0F4_RPXPC2PEPM			BIT2	//0/0/1/1 Down-stream ECLK (Running at 250MHz or 500MHz ) Enable for PEG PE1, PE0, PE2 and PE3
    #define D0F4_RPXPP2CHPM			BIT1	//0/*0/1/1 Up-stream HCLK Enable
    #define D0F4_RPXPP2CGPM			BIT0	//0/0/1/1 Up-stream GCLK Enable
#define D0F4_PXPTRF_DYNAMIC_CLK_2		0x79	//Central Traffic Controller (PXPTRF) Dynamic Clock 2
    #define D0F4_RDYNPXPVPIPM			BIT7	//0/0/1/1 Up-stream VPI clock Enable
    #define D0F4_RDYNPXPRAID0PM			BIT6	//0/0/1/1 Up-stream RAIDA0 (DCLK) Enable
    #define D0F4_RPXPAPICPM			BIT5	//0/0/1/1 Dynamic APIC Clock Control
    #define D0F4_RDYNPXPXPM			BIT4	//0/0/1/1 Level-1 GFX-ECLK (XCLK) Enable
    #define D0F4_RPXPC2PXPM			BIT3	//0/0/1/1 Down-stream GFX-ECLK (XCLK) Enable
    #define D0F4_RPXPP2CXPM			BIT2	//0/0/1/1 Up-stream GFX-ECLK (XCLK) Enable
    #define D0F4_RDYNPXPRAID1PM			BIT1	//0/0/1/1 Up-stream RAIDA1 (DCLK) Enable
    #define D0F4_RDYNPXPVPIGPM			BIT0	//0/0/1/1 Dynamic Clock Enable of VPI Downstream Path Clock in PXPTRF
#define D0F4_PXPTRF_DYNAMIC_CLK_3		0x7A	//Central Traffic Controller (PXPTRF) Dynamic Clock 3
    #define D0F4_RPXPTRFPM			BIT7	//0/0/1/1 Dynamic Clock Enable of Central Traffic Controller (PXPTRF)
    #define D0F4_RPXPCFGPM			BIT6	//0/0/1/1 Dynamic Stop for CFGCLK at PXPTRF Module
    #define D0F4_RDYNPXPAZPM			BIT5	//0/0/1/1 Level-1 Azalia Clock (GCLK, 66MHz) Enable
    #define D0F4_RTRFMCUPM			BIT4	//0/0/1/1 Dynamic Control for MCU Path in PXPTRF
    #define D0F4_RTRFDPM			BIT3	//0/0/1/1 Dynamic Clock Enable of DCLK
    #define D0F4_RDYNPXPXHGPM			BIT2	//0/0/1/1 Dynamic Clock Enable of XH_GCLK
    #define D0F4_RDYNPXPAHGPM			BIT1	//0/0/1/1 Dynamic Clock Enable of AH_GCLK
    #define D0F4_RDYNPXPPEMCUPM			BIT0	//0/0/1/1 Level-1 PEMCU_CLK Clock (GCLK200, 200MHz) Enable
#define D0F4_TACTL_DYNAMIC_CLK		0x7B	//TACTL Dynamic Clock
    #define D0F4_D0F4_7BH			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F4_RTATMOCKMUX			BIT5	//0/0/1/1 TACTL Time Out Counter Dynamic Clock Enable
    #define D0F4_RTACTLPM			BIT4	//0/0/1/1 TACTL Dynamic Clock Enable
    #define D0F4_RTAGPM			BIT3	//0/0/1/1 TACTL GCLK Dynamic Clock Enable
    #define D0F4_RTAPEREQPM			BIT2	//0/0/1/1 TACTL ECLK of Translation Request Dynamic Clock Enable
    #define D0F4_RTAPEINVPM			BIT1	//0/0/1/1 TACTL ECLK of Invalidation Request Dynamic Clock Enable
    #define D0F4_RTAHPM			BIT0	//0/0/1/1 TACTL HCLK Dynamic Clock Enable
#define D0F4_APICX_DYNAMIC_CLK		0x7C	//Advanced Programmed Interrupt Controller ((APICX)) Dynamic Clock
    #define D0F4_RAPICPM_FECLK			BIT7	//0/0/1/1 Dynamic PCIe Clock ((FECLK_PE*)) Running at 250MHz or 500Mhz of APIC
    #define D0F4_RAPICPM_FGCLKI			BIT6	//0/0/1/1 Dynamic Global PCI Clock ((FGCLKI)) Running at 66MHz of APIC
    #define D0F4_RAPICPM			BIT5	//0/0/1/1 APIC Interface Power Management
    #define D0F4_RMSIWKUPC3			BIT4	//0/0/1/x Reserved
    #define D0F4_D0F4_7CH			0xF	//0/0/x/x Reserved
#define D0F4_VKCFG_IF_PM		0x7D	//North Module Configuration ((VKCFG)) Interface Power Management
    #define D0F4_RVKCFGPM			BIT7	//0/0/1/1 North Module Configuration ((VKCFG)) Interface Power Management 
    #define D0F4_D0F4_7DH			0x7F	//0/0/1/x Reversed
#define D0F4_PXPTRF_DYNAMIC_CLK_4		0x7E	//Central Traffic Controller (PXPTRF) Dynamic Clock 4
    #define D0F4_D0F4_7EH			0xF8	//0/0/x/x Reserved
    #define D0F4_RDYNPXPMCAGPM			BIT2	//0/0/1/1 Down-stream MCA Dynamic Clock Enable
    #define D0F4_RDYNPXPAHPM			BIT1	//0/0/1/1 Up-stream AHCI Dynamic Clock Enable
    #define D0F4_RDYNPXPXHPM			BIT0	//0/0/1/1 Up-stream XHCI Dynamic Clock Enable
#define D0F4_MSG_CTLLER_MSGC_GCLK_PM		0x7F	//Message Controller ((MSGC)) GCLK Power Management
    #define D0F4_D0F4_7FH			0xFF	//0/0/x/x Reserved
#define D0F4_CPUIF_PM		0x80	//CPUIF Power Management
    #define D0F4_REFUSE_AUTO_DYN			BIT31	//0/0/1/1 Efuse_Autoload Module Clock Gating
    #define D0F4_D0F4_80H			0x7FFF0000	//0/0/x/x Reserved
    #define D0F4_RDYNCPUIFCKPM_11_0			0xFFF0	//0/0/FFFh/FFFh CKLATCH Enable Bit for CPUIF
    #define D0F4_RDYNCPUIFFSBCWPM			BIT3	//0/0/1/1 Dynamic Clock Stop Control for FSBCW Part
    #define D0F4_RDYNCPUIFPM			BIT2	//0/0/1/1 Dynamic Clock Stop Control for CPUIF Controller
    #define D0F4_RDYNCPUIFCPPM			BIT1	//0/0/1/1 Dynamic Clock Stop Control for CPUIF C2P Part
    #define D0F4_RDYNCPUIFCMPM			BIT0	//0/0/1/1 Dynamic Clock Stop Control for CPUIF C2M Part
#define D0F4_RESERVED_Z13		0x84	//Reserved
    #define D0F4_D0F4_84H			0xFFFFFFFF	//0/0/x/x Reserved
#define D0F4_RESERVED_Z14		0x88	//Reserved
    #define D0F4_D0F4_88H			0xFFFFFFFF	//0/0/x/x Reserved
#define D0F4_RESERVED_Z15		0x8C	//Reserved
    #define D0F4_D0F4_8CH			0xFFFFFFFF	//0/0/x/x Reserved
#define D0F4_C0_THROTTLING_C0T_PMU_CTL		0x90	//C0 Throttling (C0T) PMU Control
    #define D0F4_RC0T_EN			BIT7	//0/0/0/0 Reserved
    #define D0F4_D0F4_90H1			(BIT5 + BIT6)	//0/0/x/x Reserved
    #define D0F4_RC0T_NON_PGM_EN			BIT4	//0/0/0/0* Reserved
    #define D0F4_D0F4_90H2			0xF	//0/0/x/x Reserved
#define D0F4_C1_PMU_CTL		0x91	//C1 PMU Control
    #define D0F4_RC1_EN			BIT7	//0/0/0/0 Reserved 
    #define D0F4_D0F4_91H1			(BIT5 + BIT6)	//0/0/x/x Reserved
    #define D0F4_RC1_NON_PGM_EN			BIT4	//0/0/0/0* Reserved
    #define D0F4_D0F4_91H2			0xF	//0/0/x/x Reserved
#define D0F4_C2_PMU_CTL		0x92	//C2 PMU Control
    #define D0F4_RC2_EN			BIT7	//0/0/0/0 Reserved
    #define D0F4_D0F4_92H1			(BIT5 + BIT6)	//0/0/x/x Reserved
    #define D0F4_RC2_NON_PGM_EN			BIT4	//0/0/0/0* Reserved
    #define D0F4_D0F4_92H2			0xF	//0/0/x/x Reserved
#define D0F4_C3_PMU_CTL		0x93	//C3 PMU Control
    #define D0F4_RC3_EN			BIT7	//0/0/x/x Reserved
    #define D0F4_RC3_SLF_RF_GFXC3ST			BIT6	//0/0/x/x Reserved
    #define D0F4_RC3_SLF_RF_VBLANK			BIT5	//0/0/x/x Reserved
    #define D0F4_RC3_NON_PGM_EN			BIT4	//0/0/0/1 Reserved
    #define D0F4_D0F4_93H			0xF	//0/0/x/x Reserved
#define D0F4_NEW_PMU_FEATURES		0x94	//New PMU Features
    #define D0F4_RHNDSHKEN			BIT7	//0/*0/x/x Reserved
    #define D0F4_RPLL1GATE			BIT6	//0/0/0/1 Reserved
    #define D0F4_RPLL2GATE			BIT5	//0/0/0/1 Reserved
    #define D0F4_RGPLLGATE			BIT4	//0/0/0/1 Reserved
    #define D0F4_D0F4_94H1			BIT3	//0/x/x/x Reserved
    #define D0F4_RNP0_BUSY_EN			BIT2	//0/0/x/x Reserved
    #define D0F4_RC2TOC3TMER_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F4_NM_PMU_SLP_TIMING_CTL		0x95	//NM PMU SLP Timing Control
    #define D0F4_D0F4_95H			BIT7	//0/0/x/x Reserved
    #define D0F4_RNEWSBPMU			BIT6	//0/0/x/x Reserved
    #define D0F4_RBMIDLEEXT_1_0			(BIT4 + BIT5)	//0/0/x/x Reserved
    #define D0F4_RSLPACTTMER_1_0			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D0F4_RSLP2BMTMER_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F4_NEW_PMU_FUN_CTL		0x96	//New PMU Function Control
    #define D0F4_RC5_EN			BIT7	//1b/*1/x/1 NM C5 State Enable
    #define D0F4_RCLKREQOFFC0			BIT6	//0/0/x/1 PCIe Port CLK OFF in C0 Enable
    #define D0F4_RCLKREQOFFEN			BIT5	//0/0/x/1 PCIe Port CLK OFF Enable
    #define D0F4_REPLLOFFC0			BIT4	//0/0/x/x EPLL OFF in C0 Enable
    #define D0F4_REPLLOFFEN_PHYB			BIT3	//0/0/x/x EPLL OFF Enable for X2B EPHY
    #define D0F4_REPLLGATEEN_PHYB			BIT2	//0/0/x/1 EPLL Gate Enable for X2B EPHY
    #define D0F4_REPLLPME_PHYB			BIT1	//0/0/x/x EPLL Control Select for X2B EPHY
    #define D0F4_RC5STPCLK			BIT0	//0/0/x/x Reserved
#define D0F4_NEW_PMU_FUN_CTL_Z1		0x97	//New PMU Function Control
    #define D0F4_RC3SRFEN			BIT7	//0/0/x/1 Reserved 
    #define D0F4_RC4SRFEN			BIT6	//0/0/x/1 Reserved 
    #define D0F4_RPLLONEN			BIT5	//0/0/x/x Reserved
    #define D0F4_RC5OFF_SLPSYNC			BIT4	//0/0/x/x Reserved
    #define D0F4_RC5SLPSYNC			BIT3	//0/0/x/x Reserved
    #define D0F4_RDPLLGPMODE			BIT2	//0/0/0/0 Reserved
    #define D0F4_REXPARBDISTM_1_0			(BIT0 + BIT1)	//10b/10b/x/x The Timer to Expand SM ¡°C3ARBDIS1¡± when Exiting C3/C4
#define D0F4_PWR_GATING_CTL_0		0x98	//Power Gating Control 0
    #define D0F4_D0F4_98H			0xF0	//0/0/x/x Reserved
    #define D0F4_VPI_ISOEN			BIT3	//0/0/1/1 VPIL Isolation Cell Gating Enable
    #define D0F4_VPI_PSOEN			BIT2	//0/0/1/1 VPIL Power Gating Enable
    #define D0F4_RTAISOEN			BIT1	//0/0/1/1 TA Isolation Cell Gating Enable
    #define D0F4_RTAPSOEN			BIT0	//0/0/1/1 TA Power Gating Enable
#define D0F4_PWR_GATING_CTL_1		0x99	//Power Gating Control 1
    #define D0F4_D0F4_99H			0xFC	//0/x/x/x Reserved
    #define D0F4_VPI_PSOACK			BIT1	//HwInit/x/x/x VPIL Power Gating ACK
    #define D0F4_RTAPSOACK			BIT0	//HwInit/x/x/x TA Power Gating ACK
#define D0F4_NEW_PMU_FUNC_VPI		0x9A	//New PMU Function Control for VPI
    #define D0F4_RC5_EN_VPI			BIT7	//0/0/x/x Reserved
    #define D0F4_RCLKREQOFFC0_VPI			BIT6	//0/0/x/1 VPI Port CLK OFF in C0 Enable
    #define D0F4_RCLKREQOFFEN_VPI			BIT5	//0/0/x/1 VPI Port CLK OFF Enable
    #define D0F4_REPLLOFFC0_VPI			BIT4	//0/0/x/x EPLL OFF in C0 Enable
    #define D0F4_REPLLOFFEN_VPI			BIT3	//0/0/x/x EPLL OFF Enable
    #define D0F4_REPLLGATEEN_VPI			BIT2	//0/0/x/1 EPLL Gate Enable
    #define D0F4_REPLLPME_VPI			BIT1	//0/0/x/x EPLL Control Select
    #define D0F4_RC5STPCLK_VPI			BIT0	//0/0/x/x Reserved
#define D0F4_NEW_PMU_FUNC_PCIEPHY_X14_PLL		0x9B	//New PMU function control for PCIEPHY_14X PLL
    #define D0F4_D0F4_9BH			0xF0	//0/0/x/x Reserved
    #define D0F4_REPLLGATE_ITFC_EN			BIT3	//0/0/x/1 EPLL Gate interface Enable
    #define D0F4_REPLLOFFEN_PHYA			BIT2	//0/0/x/x EPLL OFF Enable for X14A EPHY
    #define D0F4_REPLLGATEEN_PHYA			BIT1	//0/0/x/1 EPLL Gate Enable for X14A EPHY
    #define D0F4_REPLLPME_PHYA			BIT0	//0/0/x/x EPLL Control Select for X14A EPHY
#define D0F4_DDRIO_THERMAL_SENSOR_CTL		0x9C	//DDRIO Thermal Sensor Control
    #define D0F4_D0F4_9CH_RSV			0xFFFFFFFF	//0/0/x/x Reserved
#define D0F4_GMINT_REG_0		0xA0	//GMINT Register 0
    #define D0F4_RGAASYNTST			BIT7	//0/0/x/x Reserved
    #define D0F4_RGAFLUSHNUM_2_0			(BIT4 + BIT5 + BIT6)	//100b/100b/x/x Reserved
    #define D0F4_RGANMRG			BIT3	//0b/0/x/x Reserved
    #define D0F4_RGARPW			BIT2	//0/0/x/x Reserved
    #define D0F4_RNDYSNP			BIT1	//1b/1/x/x All Read Cycle Snoop 
    #define D0F4_RCMSNP			BIT0	//1b/1/x/x Reserved
#define D0F4_GMINT_REG_1		0xA1	//GMINT Register 1
    #define D0F4_D0F4_F1			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F4_RGMISNPOEN			BIT4	//0/0/x/x Report G2M Access DVAD Error when Support GFX_Snoop_mode_only
    #define D0F4_RAGMIWMALLBE			BIT3	//0/0/x/x Support Update ALLBE when Do GMINTA Write Request 4QW to 8QW Merge
    #define D0F4_RBGMIWMALLBE			BIT2	//0/0/x/x Support Update ALLBE when Do GMINTB Write Request 4QW to 8QW Merge
    #define D0F4_RAGMINTWM			BIT1	//0/0/x/x Support GMINTA Write Request 4QW to 8QW Merge
    #define D0F4_RBGMINTWM			BIT0	//0/0/x/x Support GMINTB Write Request 4QW to 8QW Merge
#define D0F4_GMINT_REG_2		0xA2	//GMINT Register 2
    #define D0F4_D0F4_F2_7			BIT7	//0/0/x/x Reserved
    #define D0F4_RGMRSNP			BIT6	//1b/1/x/x Reserved
    #define D0F4_RG8QWMW			BIT5	//0/0/x/x Reserved
    #define D0F4_RGMINT8QW			BIT4	//1b/1/x/x Reserved
    #define D0F4_RC2PFLHCMW			BIT3	//1b/1/x/x Reserved
    #define D0F4_RC2PWFLHCMW			BIT2	//0/0/x/x Reserved
    #define D0F4_RGMLBYPASS			BIT1	//0/0/x/x Reserved
    #define D0F4_RGMHBYPASS			BIT0	//0/0/x/x Reserved
#define D0F4_DDRIO_THERMAL_SENSOR_CTL_Z1		0xA3	//DDRIO Thermal Sensor Control
    #define D0F4_D0F4_A3H_RSV			0xFF	//0/0/x/x Reserved
#define D0F4_GMINT_REG_3		0xA4	//GMINT Register 3
    #define D0F4_RGRRDYFLUSH0			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYFLUSH1			(BIT4 + BIT5)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYFLUSH2			(BIT2 + BIT3)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYFLUSH3			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define D0F4_GMINT_REG_4		0xA5	//GMINT Register 4
    #define D0F4_RGRRDYFLUSH4			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYFLUSH5			(BIT4 + BIT5)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYWAIT0			(BIT2 + BIT3)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYWAIT1			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define D0F4_GMINT_REG_5		0xA6	//GMINT Register 5
    #define D0F4_RGRRDYWAIT2			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYWAIT3			(BIT4 + BIT5)	//00b/00b/x/x Reserved
    #define D0F4_RGRRDYWAIT4			(BIT2 + BIT3)	//00b/00b/x/x SID 4 Read Ready Arbitration Promote Counter
    #define D0F4_RGRRDYWAIT5			(BIT0 + BIT1)	//00b/00b/x/x SID 5 Read Ready Arbitration Promote Counter
#define D0F4_GFX_MISC		0xA7	//GFX Misc.
    #define D0F4_RGFXRST			BIT7	//0/x/x/x Reset Internal GFX by BIOS
    #define D0F4_RPCICLKADJ			(BIT5 + BIT6)	//00b/x/x/x Reserved
    #define D0F4_RAGASYTSR			BIT4	//0/0/x/x For Test Mode
    #define D0F4_RBGASYTSR			BIT3	//0/0/x/x For Test Mode
    #define D0F4_RDECODECHBYA8			BIT2	//0/x/x/x Reserved
    #define D0F4_D0F4_F7_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D0F4_SUSPEND_DEBUG_CTL_0		0xA8	//Suspend Debug Control 0
    #define D0F4_RDBGMODE_SUS			BIT7	//0/0/x/x Suspend Debugging Mode
    #define D0F4_RDBGCHSEL_SUS_1_0			(BIT5 + BIT6)	//0/0/x/x Suspend Debug Signal Output Pad Select
    #define D0F4_RGFXDBGSEL_G1_SUS			BIT4	//0/0/x/x Suspend Debugging Signal Group 1 Selection
    #define D0F4_RGFXDBGSEL_G0_SUS			BIT3	//0/0/x/x Suspend Debugging Signal Group 0 Selection
    #define D0F4_RDBGNBSBSEL_G0_SUS_1_0			(BIT1 + BIT2)	//0/0/x/x Suspend Debugging Signal Output Selection for Group 0
    #define D0F4_RDBGSBSELBYNB_SUS			BIT0	//1b/1/x/x Suspend SM Debug Signal Selection Control
#define D0F4_SUSPEND_DEBUG_CTL_1		0xA9	//Suspend Debug Control 1
    #define D0F4_RDBGCHDVPSEL_SUS			BIT7	//0/0/x/x Suspend Debug Signal Output Pad Select DVP Pad or Other SUS Pad
    #define D0F4_RDBGNBSBSEL_G1_SUS_1_0			(BIT5 + BIT6)	//0/0/x/x Suspend Debugging Signal Output Selection for Group 1
    #define D0F4_RDBGMX_NBTOP_G0_SUS_4_0			0x1F	//0/0/x/x Suspend Group 0 Debug Port Output Signal Select
#define D0F4_SUSPEND_DEBUG_CTL_2		0xAA	//Suspend Debug Control 2
    #define D0F4_D0F4_AA			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F4_RDBGMX_NBTOP_G1_SUS_4_0			0x1F	//0/0/x/x Suspend Group 1 Debug Port Output Signal Select
#define D0F4_SUSPEND_DEBUG_CTL_3		0xAB	//Suspend Debug Control 3
    #define D0F4_RDBGMX_MODULE_G0_SUS_19_12			0xFF	//0/0/x/x Suspend Group 0 Debug Port Output Signal Select
#define D0F4_RESERVED_Z16		0xAC	//Reserved
    #define D0F4_RDBGMX_MODULE_G0_SUS_11_0			0xFFF00000	//0/0/x/x Suspend Group 0 Debug Port Output Signal Select
    #define D0F4_RDBGMX_MODULE_G1_SUS_19_0			0xFFFFF	//0/0/x/x Suspend Group 1 Debug Port Output Signal Select
#define D0F4_STRAPPING_REGS		0xB0	//Strapping Registers
    #define D0F4_RSV_B0_7			BIT7	//0/0/x/x Reserved
    #define D0F4_RPLLEAINITCTL			BIT6	//Dip/x/x/x PLLEA/B Initial Power-on Control
    #define D0F4_RPLLCPUREFSEL			BIT5	//Dip/x/x/x Select 100MHz Reference Clock Source for CPU and PLLM
    #define D0F4_RGCLKSEL			BIT4	//Dip/x/x/x Select GCLK Clock Source
    #define D0F4_RDCKINIT_SEL1			BIT3	//Dip/x/x/x Select DRAM Initial Clock
    #define D0F4_RDCKINIT_SEL0			BIT2	//Dip/x/x/x Select DRAM Initial Clock
    #define D0F4_RXTAL_SEL_1			BIT1	//Dip/x/x/x Select 27MHz Clock Source
    #define D0F4_RXTAL_SEL_0			BIT0	//Dip/x/x/x Select 27MHz Clock Source
#define D0F4_CKGSRC_PLLEA_CTL_0		0xB1	//CKGSRC PLLEA Control 0
    #define D0F4_RSRC_PLLEA_CP_TC_3_0			0xF0	//1111b/x/x/x CKGSRC PLLPCIEA CP Current Thermal Coefficient Setting 
    #define D0F4_RSRC_PLLEA_CP_3_0			0xF	//0011b/11/x/x CKGSRC PLLPCIEA CP Current Setting
#define D0F4_CKGSRC_PLLEA_CTL_1		0xB2	//CKGSRC PLLEA Control 1
    #define D0F4_RSRC_PLLEA_M_7_0			0xFF	//74h/x/x/x CKGSRC Divider Ratio (Integer Part)
#define D0F4_CKGSRC_PLLEA_CTL_2		0xB3	//CKGSRC PLLEA Control 2
    #define D0F4_RSRC_FSEL_TC_A_3_0			0xF0	//0010b/10/x/x VCO Temperature Coefficient Tuning Settings
    #define D0F4_RSRC_FSEL_ABS_A_3_0			0xF	//0100b/100/x/x VCO Frequency Tuning Settings
#define D0F4_CKGSRC_PLLEA_CTL_3		0xB4	//CKGSRC PLLEA Control 3
    #define D0F4_RSRC_PLLEA_FSEL_7_0			0xFF	//0/0/x/x VCO Frequency Tuning Settings
#define D0F4_CKGSRC_PLLEA_CTL_4		0xB5	//CKGSRC PLLEA Control 4
    #define D0F4_RSRC_SSCMA_A_3_0			0xF0	//1001b/1001/x/x PLLEA SSCG Magnitude
    #define D0F4_RSRC_SSCSPRD_A			BIT3	//0/x/x/x CKGSRC PLLPCIEA SSC Spread Mode
    #define D0F4_RSRC_SSCEN_A			BIT2	//1b/1/x/x CKGSRC PLLPCIEA SSC Enable
    #define D0F4_RSRC_FRACEN_A			BIT1	//1b/1/x/x CKGSRC PLLPCIEA FRAC Enable
    #define D0F4_RSRC_PLLEA_DIV_MODE			BIT0	//0/0/x/x PLLEA Divider Mode Selection
#define D0F4_CKGSRC_PLLEA_CTL_5		0xB6	//CKGSRC PLLEA Control 5
    #define D0F4_RSV_B6_7_5			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F4_RSRC_PLLEA100M_ANA_EN			BIT4	//1b/1/x/x Analog Domain 100M Clock Drive Enable.
    #define D0F4_RSRC_PLLEA100M_ANA_DRVSTR_1_0			(BIT2 + BIT3)	//10b/10/x/x Analog Domain 100M Clock Drive Strength Setting.
    #define D0F4_RSRC_PLLEA_SSCFINE_1_0			(BIT0 + BIT1)	//10b/10/x/x PLLEA SSCG Magnitude Fine Tune
#define D0F4_CKGSRC_PLLEB_CTL_0		0xB7	//CKGSRC PLLEB Control 0
    #define D0F4_RSRC_PLLEB_CP_TC_3_0			0xF0	//1111b/x/x/x CKGSRC PLLPCIEB CP Current thermal Coefficient Setting
    #define D0F4_RSRC_PLLEB_CP_3_0			0xF	//0011b/11/x/x CKGSRC PLLPCIEB CP Current Setting
#define D0F4_CKGSRC_PLLEB_CTL_1		0xB8	//CKGSRC PLLEB Control 1
    #define D0F4_RSRC_PLLEB_M_7_0			0xFF	//74h/x/x/x CKGSRC Divider Ratio (Integer Part)
#define D0F4_CKGSRC_PLLEB_CTL_2		0xB9	//CKGSRC PLLEB Control 2
    #define D0F4_RSRC_FSEL_TC_B_3_0			0xF0	//0010b/10/x/x VCO Temperature Coefficient Tuning Settings
    #define D0F4_RSRC_FSEL_ABS_B_3_0			0xF	//0100b/100/x/x VCO Frequency Tuning Settings
#define D0F4_CKGSRC_PLLEB_CTL_3		0xBA	//CKGSRC PLLEB Control 3
    #define D0F4_RSRC_PLLEB_FSEL_7_0			0xFF	//0/0/x/x VCO Frequency Tuning Settings
#define D0F4_CKGSRC_PLLEB_CTL_4		0xBB	//CKGSRC PLLEB Control 4
    #define D0F4_RSRC_SSCMA_B_3_0			0xF0	//1001b/1001/x/x PLLEB SSCG Magnitude
    #define D0F4_RSRC_SSCSPRD_B			BIT3	//0/x/x/x CKGSRC PLLPCIEB SSC Spread Mode
    #define D0F4_RSRC_SSCEN_B			BIT2	//1b/1/x/x CKGSRC PLLPCIEB SSC Enable
    #define D0F4_RSRC_FRACEN_B			BIT1	//1b/1/x/x CKGSRC PLLPCIEB FRAC Enable
    #define D0F4_RSRC_PLLEB_DIV_MODE			BIT0	//0/0/x/x PLLEB Divider Mode Selection
#define D0F4_CKGSRC_PLLEB_CTL_5		0xBC	//CKGSRC PLLEB Control 5
    #define D0F4_RSV_BC_7_5			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F4_RSRC_PLLEB100M_ANA_EN			BIT4	//1b/1/x/x Analog domain 100M clock drive enable.
    #define D0F4_RSRC_PLLEB100M_ANA_DRVSTR_1_0			(BIT2 + BIT3)	//10b/10/x/x Analog Domain 100M Clock Drive Strength Setting.
    #define D0F4_RSRC_PLLEB_SSCFINE_1_0			(BIT0 + BIT1)	//10b/10/x/x PLLEB SSCG Magnitude Fine Tune
#define D0F4_CKGSRC_IO_CTL_0		0xBD	//CKGSRC IO Control 0
    #define D0F4_RSRC_PU_IO7			BIT7	//1b/1/x/x CKGSRC IO[7] LDO Power Up
    #define D0F4_RSRC_PU_IO6			BIT6	//1b/1/x/x CKGSRC IO[6] LDO Power Up
    #define D0F4_RSRC_PU_IO5			BIT5	//1b/1/x/x CKGSRC IO[5] LDO Power Up
    #define D0F4_RSRC_PU_IO4			BIT4	//1b/1/x/x CKGSRC IO[4] LDO Power Up
    #define D0F4_RSRC_PU_IO3			BIT3	//1b/1/x/x CKGSRC IO[3] LDO Power Up
    #define D0F4_RSRC_PU_IO2			BIT2	//1b/1/x/x CKGSRC IO[2] LDO Power Up
    #define D0F4_RSRC_PU_IO1			BIT1	//1b/1/x/x CKGSRC IO[1] LDO Power Up
    #define D0F4_RSRC_PU_IO0			BIT0	//1b/1/x/x CKGSRC IO[0] LDO Power Up
#define D0F4_CKGSRC_IO_CTL_1		0xBE	//CKGSRC IO Control 1
    #define D0F4_RSRC_TNO_IO7			BIT7	//1b/1/x/x CKGSRC IO[7] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO6			BIT6	//1b/1/x/x CKGSRC IO[6] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO5			BIT5	//1b/1/x/x CKGSRC IO[5] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO4			BIT4	//1b/1/x/x CKGSRC IO[4] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO3			BIT3	//1b/1/x/x CKGSRC IO[3] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO2			BIT2	//1b/1/x/x CKGSRC IO[2] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO1			BIT1	//1b/1/x/x CKGSRC IO[1] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO0			BIT0	//1b/1/x/x CKGSRC IO[0] Buffer Output Enable
#define D0F4_CKGSRC_IO_CTL_2		0xBF	//CKGSRC IO Control 2
    #define D0F4_RSRC_CLKSEL_IO7			BIT7	//0/0/x/x CKGSRC IO[7] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO6			BIT6	//0/0/x/x CKGSRC IO[6] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO5			BIT5	//0/0/x/x CKGSRC IO[5] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO4			BIT4	//0/0/x/x CKGSRC IO[4] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO3			BIT3	//0/0/x/x CKGSRC IO[3] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO2			BIT2	//0/0/x/x CKGSRC IO[2] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO1			BIT1	//0/0/x/x CKGSRC IO[1] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO0			BIT0	//0/0/x/x CKGSRC IO[0] Clock Source Selection
#define D0F4_CKGSRC_IO_CTL_3		0xC0	//CKGSRC IO Control 3
    #define D0F4_RSV_C0_7			BIT7	//0/0/x/x Reserved
    #define D0F4_RSRC_PU_IO10			BIT6	//1b/1/x/x CKGSRC IO[10] LDO Power Up
    #define D0F4_RSRC_PU_IO9			BIT5	//1b/1/x/x CKGSRC IO[9] LDO Power Up
    #define D0F4_RSRC_PU_IO8			BIT4	//1b/1/x/x CKGSRC IO[8] LDO Power Up
    #define D0F4_RSV_C0_3			BIT3	//0/0/x/x Reserved
    #define D0F4_RSRC_TNO_IO10			BIT2	//1b/1/x/x CKGSRC IO[10] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO9			BIT1	//1b/1/x/x CKGSRC IO[9] Buffer Output Enable
    #define D0F4_RSRC_TNO_IO8			BIT0	//1b/1/x/x CKGSRC IO[8] Buffer Output Enable
#define D0F4_CKGSRC_IO_CTL_4		0xC1	//CKGSRC IO Control 4
    #define D0F4_RSV_C1_7_3			0xF8	//0/0/x/x Reserved
    #define D0F4_RSRC_CLKSEL_IO10			BIT2	//0/0/x/x CKGSRC IO[10] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO9			BIT1	//0/0/x/x CKGSRC IO[9] Clock Source Selection
    #define D0F4_RSRC_CLKSEL_IO8			BIT0	//0/0/x/x CKGSRC IO[8] Clock Source Selection
#define D0F4_CKGSRC_IO_CTL_5		0xC2	//CKGSRC IO Control 5
    #define D0F4_RSRC_VDDIO_2_0			(BIT5 + BIT6 + BIT7)	//100b/100/x/x CKGSRC IO Swing Control
    #define D0F4_RSRC_RFTIME_1_0			(BIT3 + BIT4)	//01b/1/x/x CKGSRC IO Rise/Fall Time Control
    #define D0F4_RSRC_TMODE_SEL_1_0			(BIT1 + BIT2)	//01b/1/x/x CKG_TEST Test Clock Selection
    #define D0F4_RSRC_TMODE_EN			BIT0	//0/0/x/x CKGSRC TMODE EN
#define D0F4_CKGSRC_IO_CTL_6		0xC3	//CKGSRC IO Control 6
    #define D0F4_RSRC_DRVSTR_P_3_0			0xF0	//1000b/1000b/x/x CKGSRC IO P-driving Strength Setting Input
    #define D0F4_RSRC_DRVSTR_N_3_0			0xF	//1000b/1000b/x/x CKGSRC IO N-driving Strength Setting Input
#define D0F4_SB_PLL14318_CTL_0		0xC4	//SB PLL14318 Control 0
    #define D0F4_RXC4_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F4_RPLL14318_FRACEN			BIT5	//1b/1/x/x Fractional Function Enable
    #define D0F4_RPLL14318_DIV_MODE			BIT4	//0/0/x/x PLL divider Mode Selection
    #define D0F4_RPLL14318_ICPSEL_3_0			0xF	//0101b/0101b/x/x Charge Pump Current Selection
#define D0F4_SB_PLL14318_CTL_1		0xC5	//SB PLL14318 Control 1
    #define D0F4_RXC4_7			BIT7	//0/x/x/x Reserved
    #define D0F4_RPLL14318_FBDLY_SEL_2_0			(BIT4 + BIT5 + BIT6)	//000b/000b/x/x PLL internal Fbclk Delay Setting
    #define D0F4_RSV_C5_3			BIT3	//0/0/x/x Reserved
    #define D0F4_RPLL14318_REFDLY_SEL_2_0			(BIT0 + BIT1 + BIT2)	//000b/000b/x/x REFCLKIN Delay Setting
#define D0F4_SB_PLL14318_CTL_2		0xC6	//SB PLL14318 Control 2
    #define D0F4_RPLL14318DIVM_7_0			0xFF	//41h/41h/x/x PLL14318 DIVM Value Setting
#define D0F4_SB_PLL14318_CTL_3		0xC7	//SB PLL14318 Control 3
    #define D0F4_RPLL14318DIVN_7_0			0xFF	//2Fh/2Fh/x/x PLL14318 DIVN Value Setting
#define D0F4_SB_PLL14318_CTL_3_Z1		0xC8	//SB PLL14318 Control 3
    #define D0F4_RSV_C9			0xF000	//0/R/x/x Reserved
    #define D0F4_RPLL14318DIVN_19_8			0xFFF	//DA1h/DA1h/x/x PLL14318 DIVN Value Setting
#define D0F4_SB_PLL14318_CTL_4		0xCA	//SB PLL14318 Control 4
    #define D0F4_RPLL14318_FVCO_TUNE_TC_3_0			0xF0	//0/0/x/x PLL Internal Analog Test or Debug Settings.
    #define D0F4_RPLL14318_FVCO_TUNE_ABS_3_0			0xF	//0/0/x/x PLL Internal Analog Test or Debug Settings.
#define D0F4_SB_PLL48_CTL_0		0xCB	//SB PLL48 Control 0
    #define D0F4_RXCB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F4_RPLL48_FRACEN			BIT5	//1b/1/x/x Fractional Function Enable
    #define D0F4_RPLL48_DIV_MODE			BIT4	//0/0/x/x PLL divider mode selection
    #define D0F4_RPLL48_ICPSEL_3_0			0xF	//0101b/0101b/x/x Charge Pump Current Selection
#define D0F4_SB_PLL48_CTL_1		0xCC	//SB PLL48 Control 1
    #define D0F4_RXCC_7			BIT7	//0/x/x/x Reserved
    #define D0F4_RPLL48_FBDLY_SEL_2_0			(BIT4 + BIT5 + BIT6)	//0/0/x/x PLL Internal Fbclk Delay Setting
    #define D0F4_RSV_CC_3			BIT3	//0/0/x/x Reserved
    #define D0F4_RPLL48_REFDLY_SEL_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x REFCLKIN Delay Setting
#define D0F4_SB_PLL48_CTL_2		0xCD	//SB PLL48 Control 2
    #define D0F4_RPLL48DIVM_7_0			0xFF	//6Fh/6Fh/x/x PLL48 DIVM Value Setting
#define D0F4_SB_PLL48_CTL_3		0xCE	//SB PLL48 Control 3
    #define D0F4_RPLL48DIVN_15_0			0xFFFF	//71C7h/71C7h/x/x PLL48 DIVN Value Setting
#define D0F4_SB_PLL48_CTL_3_Z1		0xD0	//SB PLL48 Control 3
    #define D0F4_RXD0			0xF0	//0/R/x/x Reserved
    #define D0F4_RPLL48DIVN_19_16			0xF	//Ch/Ch/x/x PLL48 DIVN Value Setting
#define D0F4_SB_PLL48_CTL_4		0xD1	//SB PLL48 Control 4
    #define D0F4_RPLL48_FVCO_TUNE_TC_3_0			0xF0	//0/0/x/x PLL Internal Analog Test or Debug Settings.
    #define D0F4_RPLL48_FVCO_TUNE_ABS_3_0			0xF	//0/0/x/x PLL Internal Analog Test or Debug Settings.
#define D0F4_PLLCPU_CTL_0		0xD2	//PLLCPU Control 0
    #define D0F4_RXC3_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F4_RPLLCPU_DIV_MODE			BIT4	//0/0/x/x PLL Divider Mode Selection
    #define D0F4_RPLLCPU_ICPSEL_3_0			0xF	//0101b/0101b/x/x Charge Pump Current Selection
#define D0F4_PLLCPU_CTL_1		0xD3	//PLLCPU Control 1
    #define D0F4_RXD1_7			BIT7	//0/x/x/x Reserved
    #define D0F4_RPLLCPU_FBDLY_SEL_2_0			(BIT4 + BIT5 + BIT6)	//0/0/x/x PLL Internal Fbclk Delay Setting
    #define D0F4_RSV_CB_3			BIT3	//0/0/x/x Reserved
    #define D0F4_RPLLCPU_REFDLY_SEL_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x REFCLKIN Delay Setting
#define D0F4_PLLCPU_CTL_2		0xD4	//PLLCPU Control 2
    #define D0F4_RPLLCPU_DIVM_7_0			0xFF	//39h/39h/x/x PLLCPU DIVM Value Setting
#define D0F4_PLLCPU_CTL_3		0xD5	//PLLCPU Control 3
    #define D0F4_RXCD			0xF00000	//0/R/x/x Reserved
    #define D0F4_RPLLCPU_DIVN_19_0			0xFFFFF	//425EDh/425EDh/x/x PLLCPU DIVN Value Setting
#define D0F4_PLLCPU_CTL_4		0xD8	//PLLCPU Control 4
    #define D0F4_RPLLCPU_FVCO_TUNE_TC_3_0			0xF0	//0/0/x/x PLL Internal Analog Test or Debug Settings.
    #define D0F4_RPLLCPU_FVCO_TUNE_ABS_3_0			0xF	//0/0/x/x PLL Internal Analog Test or Debug Settings.
#define D0F4_PLLCPU_CTL_5		0xD9	//PLLCPU Control 5
    #define D0F4_RPLLCPU_SSCMA_3_0			0xF0	//0111b/0111b/x/x SSC Magnitude
    #define D0F4_RPLLCPU_SSCEN			BIT3	//1b/1/x/x SSC Enable
    #define D0F4_RPLLCPU_SSCSPRD			BIT2	//0/0/x/x SSC Spread Mode
    #define D0F4_RPLLCPU_SSCFINE_1_0			(BIT0 + BIT1)	//0/0/x/x SSC magnitude fine tune
#define D0F4_PLLCPU_CTL_6		0xDA	//PLLCPU Control 6
    #define D0F4_RPLLM_PU			BIT7	//0/x/x/x DRAM Operating Frequency (PLLM) - Power up Control
    #define D0F4_RXDA_6_1			0x7E	//0/x/x/x Reserved
    #define D0F4_RPLLCPUMNOK			BIT0	//0/0/x/x PLLCPU M/N Sync for Hardware Design
#define D0F4_RESERVED_Z17		0xDB	//Reserved
    #define D0F4_RSV_DB			0xFF	//0/R/x/x Reserved
#define D0F4_CKGSRC_IO_CTL_7		0xDC	//CKGSRC IO Control 7
    #define D0F4_RSV_DC			0xF800	//0/R/x/x Reserved
    #define D0F4_RSRC_TFSEL_IO10			BIT10	//0/0/x/x CKGSRC IO[10] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO9			BIT9	//0/0/x/x CKGSRC IO[9] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO8			BIT8	//0/0/x/x CKGSRC IO[8] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO7			BIT7	//0/0/x/x CKGSRC IO[7] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO6			BIT6	//0/0/x/x CKGSRC IO[6] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO5			BIT5	//0/0/x/x CKGSRC IO[5] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO4			BIT4	//0/0/x/x CKGSRC IO[4] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO3			BIT3	//0/0/x/x CKGSRC IO[3] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO2			BIT2	//0/0/x/x CKGSRC IO[2] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO1			BIT1	//0/0/x/x CKGSRC IO[1] Test Frequency Selection
    #define D0F4_RSRC_TFSEL_IO0			BIT0	//0/0/x/x CKGSRC IO[0] Test Frequency Selection
#define D0F4_RESERVED_Z18		0xDE	//Reserved
    #define D0F4_RSV_DE			0xFFFF	//0/R/x/x Reserved
#define D0F4_DEBUG_GRP_SEL_FOR_DDRPHY_0		0xE0	//Debug Group Select for DDRPHY 0
    #define D0F4_PHYA_BIT_EN_SEL_7_0			0xFF	//11111111b/x/x/x Enable PHY¡¯s IO for Read Data Compare
#define D0F4_DEBUG_GRP_SEL_FOR_DDRPHY_1		0xE1	//Debug Group Select for DDRPHY 1
    #define D0F4_PHYB_BIT_EN_SEL_7_0			0xFF	//11111111b/x/x/x Enable PHY¡¯s IO for Read Data Compare
#define D0F4_DDR_PHY_DEBUG		0xE2	//DDR PHY DEBUG
    #define D0F4_PHYB_FIRST_FAIL_TSTATE_1_0			(BIT6 + BIT7)	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail Tstate
    #define D0F4_PHYA_FIRST_FAIL_TSTATE_1_0			(BIT4 + BIT5)	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail Tstate
    #define D0F4_PHYB_FIRST_FAIL_CURST_1_0			(BIT2 + BIT3)	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail Curst
    #define D0F4_PHYA_FIRST_FAIL_CURST_1_0			(BIT0 + BIT1)	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail Curst
#define D0F4_DDR_PHY_DEBUG_Z1		0xE3	//DDR PHY DEBUG
    #define D0F4_PHYA_FIRST_FAIL_DRL_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DR
#define D0F4_DDR_PHY_DEBUG_Z2		0xE4	//DDR PHY DEBUG
    #define D0F4_PHYA_FIRST_FAIL_DFL_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DF
#define D0F4_DDR_PHY_DEBUG_Z3		0xE5	//DDR PHY DEBUG
    #define D0F4_PHYB_FIRST_FAIL_DRL_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DR
#define D0F4_DDR_PHY_DEBUG_Z4		0xE6	//DDR PHY DEBUG
    #define D0F4_PHYB_FIRST_FAIL_DFL_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DF
#define D0F4_DDR_PHY_DEBUG_Z5		0xE7	//DDR PHY DEBUG
    #define D0F4_PHYA_FIRST_FAIL_CYCLE_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail Cycle
#define D0F4_DDR_PHY_DEBUG_Z6		0xE8	//DDR PHY DEBUG
    #define D0F4_PHYB_FIRST_FAIL_CYCLE_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail Cycle
#define D0F4_DDR_PHY_DEBUG_Z7		0xE9	//DDR PHY DEBUG
    #define D0F4_PHYA_FAIL_IO_ALL_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s Fail IO Indicator
#define D0F4_DDR_PHY_DEBUG_Z8		0xEA	//DDR PHY DEBUG
    #define D0F4_PHYB_FAIL_IO_ALL_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s Fail IO Indicator
#define D0F4_DDR_PHY_DEBUG_Z9		0xEB	//DDR PHY DEBUG
    #define D0F4_PHYA_FIRST_FAIL_DRH_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DR
#define D0F4_DDR_PHY_DEBUG_Z10		0xEC	//DDR PHY DEBUG
    #define D0F4_PHYA_FIRST_FAIL_DFH_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DF
#define D0F4_DDR_PHY_DEBUG_Z11		0xED	//DDR PHY DEBUG
    #define D0F4_PHYB_FIRST_FAIL_DRH_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DR
#define D0F4_DDR_PHY_DEBUG_Z12		0xEE	//DDR PHY DEBUG
    #define D0F4_PHYB_FIRST_FAIL_DFH_7_0			0xFF	//HwInit/0/x/x PHY_DEBUG_SEL Selected PHY¡¯s First Fail DF
#define D0F4_RESERVED_Z19		0xEF	//Reserved
    #define D0F4_RXF4_7_0			0xFF	//0/0/x/x Reserved
#define D0F4_RESERVED_Z20		0xF4	//Reserved
    #define D0F4_RSV_F4			0xFF	//0/R/x/x Reserved
#define D0F4_PCIE_SLOT_PWR_LIMIT_MSG_CTL		0xF5	//PCIe Slot Power Limit Message Control
    #define D0F4_RXF5_7_1			0xFE	//0/0/x/x Reserved
    #define D0F4_RDISSSPL			BIT0	//0/0/x/x Downstream Set Slot Power Limit Message Control for PCIe Root Ports
#define D0F4_INTERNAL_REV_ID		0xF6	//Internal Revision ID
    #define D0F4_RIRID_7_0			0xFF	//0/R/x/x Internal Revision ID
#define D0F4_FOUNDRY_ID		0xF7	//Foundry ID
    #define D0F4_RFID_7_0			0xFF	//0/R/x/x Foundry ID
#define D0F4_PECLK_CTL_0_1		0xF8	//PECLK Control 0 / 1
    #define D0F4_RPECLKREQ1SEL_3_0			0xF0	//0000b/x/x/x The Relationship of CKGSRC IO[1] and PCIe Port 
    #define D0F4_RPECLKREQ0SEL_3_0			0xF	//0000b/x/x/x The Relationship of CKGSRC IO[0] and PCIe Port 
#define D0F4_PECLK_CTL_2_3		0xF9	//PECLK Control 2 / 3
    #define D0F4_RPECLKREQ3SEL_3_0			0xF0	//0000b/x/x/x The Relationship of CKGSRC IO[3] and PCIe Port
    #define D0F4_RPECLKREQ2SEL_3_0			0xF	//0000b/x/x/x The Relationship of CKGSRC IO[2] and PCIe Port
#define D0F4_PECLK_CTL_4_5		0xFA	//PECLK Control 4 / 5
    #define D0F4_RPECLKREQ5SEL_3_0			0xF0	//0000b/x/x/x The Relationship of CKGSRC IO[5] and PCIe Port
    #define D0F4_RPECLKREQ4SEL_3_0			0xF	//0000b/x/x/x The Relationship of CKGSRC IO[4] and PCIe Port 
#define D0F4_PECLK_CTL_6_7		0xFB	//PECLK Control 6 / 7
    #define D0F4_RPECLKREQ7SEL_3_0			0xF0	//0000b/x/x/x The Relationship of CKGSRC IO[7] and PCIe Port
    #define D0F4_RPECLKREQ6SEL_3_0			0xF	//0000b/x/x/x The Relationship of CKGSRC IO[6] and PCIe Port
#define D0F4_PECLK_CTL_8_9		0xFC	//PECLK Control 8 / 9
    #define D0F4_RPECLKREQ9SEL_3_0			0xF0	//0000b/x/x/x The Relationship of CKGSRC IO[9] and PCIe Port
    #define D0F4_RPECLKREQ8SEL_3_0			0xF	//0000b/x/x/x The Relationship of CKGSRC IO[8] and PCIe Port
#define D0F4_PECLK_CTL_10		0xFD	//PECLK Control 10
    #define D0F4_RSV_FD			0xF0	//0/x/x/x Reserved
    #define D0F4_RPECLKREQ10SEL_3_0			0xF	//0000b/x/x/x The Relationship of CKGSRC IO[10] and PCIe Port
#define D0F4_PECLK_TNO_CTL		0xFE	//PECLK TNO Control
    #define D0F4_RPECLKREQ7HWEN			BIT7	//0/x/x/x CKGSRC IO[7] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ6HWEN			BIT6	//0/x/x/x CKGSRC IO[6] TNO Function is Hardware Control Enable 
    #define D0F4_RPECLKREQ5HWEN			BIT5	//0/x/x/x CKGSRC IO[5] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ4HWEN			BIT4	//0/x/x/x CKGSRC IO[4] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ3HWEN			BIT3	//0/x/x/x CKGSRC IO[3] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ2HWEN			BIT2	//0/x/x/x CKGSRC IO[2] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ1HWEN			BIT1	//0/x/x/x CKGSRC IO[1] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ0HWEN			BIT0	//0/x/x/x CKGSRC IO[0] TNO Function is Hardware Control Enable 
#define D0F4_PECLK_TNO_CTL_Z1		0xFF	//PECLK TNO Control
    #define D0F4_RXFF_7_3			0xF8	//0/x/x/x Reserved
    #define D0F4_RPECLKREQ10HWEN			BIT2	//0b/x/x/x CKGSRC IO[10] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ9HWEN			BIT1	//0b/x/x/x CKGSRC IO[9] TNO Function is Hardware Control Enable
    #define D0F4_RPECLKREQ8HWEN			BIT0	//0b/x/x/x CKGSRC IO[8] TNO Function is Hardware Control Enable
#endif
