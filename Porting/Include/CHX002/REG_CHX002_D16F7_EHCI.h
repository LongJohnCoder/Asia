//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		USB20					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D16F7_USB20_R104(A0).docMOD_USBC.xls
#ifndef _CHX002_D16F7_USB20_H
#define _CHX002_D16F7_USB20_H
//D16F7
#define D16F7_VID		0x00	//Vendor ID
    #define D16F7_VID_Z1			0xFFFF	//1106h/R/x/x Vendor ID
#define D16F7_DID		0x02	//Device ID
    #define D16F7_DEVID			0xFFFF	//3104h/R/x/x Device ID Code
#define D16F7_PCI_CMD		0x04	//PCI Command
    #define D16F7_INTR_DIS			BIT10	//0/0/x/x Interrupt Control
    #define D16F7_MWRMEN			BIT4	//0/x/x/x Memory Write and Invalidate
    #define D16F7_SPCYL			BIT3	//0/R/x/x Reserved 
    #define D16F7_BMASTREN			BIT2	//0/x/x/x Bus Master
    #define D16F7_MMSPACE			BIT1	//0/x/x/x Memory Space
    #define D16F7_IOSPACE			BIT0	//0/x/x/x I/O Space
#define D16F7_PCI_STA		0x06	//PCI Status
    #define D16F7_TMABORTS			BIT13	//0/x/x/x Received Master Abort (Except Special Cycle)
    #define D16F7_TTABORTR			BIT12	//0/x/x/x Received Target Abort
    #define D16F7_DEVS			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D16F7_PSTATUS_8_4			0x1F0	//01h/R/x/x Fixed at 01h (for PCI PMI)
    #define D16F7_PSTATUS_3			BIT3	//0/x/x/x Interrupt Status
#define D16F7_REV_ID		0x08	//Revision ID
    #define D16F7_REVID_08			0xFF	//90h/R/x/x Revision ID
#define D16F7_CLASS_CODE		0x09	//Class Code
    #define D16F7_CLS_COD			0xFFFFFF	//0C0320h/R/x/x Class Code for USB2.0 EHCI Host Controller
#define D16F7_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D16F7_CACHLINE			0xFF	//0/x/x/x Cache Line Size
#define D16F7_LATENCY_TIMER		0x0D	//Latency Timer
    #define D16F7_LAT_TM			0xFF	//0/x/x/x Latency Timer
#define D16F7_HEADER_TYPE		0x0E	//Header Type
    #define D16F7_HDTYPE			0xFF	//80h/R/x/x Header Type
#define D16F7_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D16F7_BIST			0xFF	//0/R/x/x BIST
#define D16F7_EHCI_MEM_MAPPED_IO_BASE_ADR		0x10	//EHCI Memory Mapped I/O Base Address
    #define D16F7_IOBASE			0xFFFFFF00	//0/x/x/x EHCI Memory Mapped I/O Registers Base Address
    #define D16F7_CAP_64B			(BIT1 + BIT2)	//00b/R/x/x Memory Mapping
#define D16F7_EHCI_MEM_MAPPED_IO_BASE_ADR_HIGH_32_BIT		0x14	//EHCI Memory Mapped I/O Base Address (High 32-bit)
    #define D16F7_IOBASE_H			0xFFFFFFFF	//0/x/x/x EHCI Memory Mapped I/O Registers High 32-bit Base Address
#define D16F7_SVID		0x2C	//Subsystem Vendor ID
    #define D16F7_SUBVID			0xFFFF	//1106h/1106h/x/x Subsystem Vendor ID
#define D16F7_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D16F7_SUBSID			0xFFFF	//3104h/3104h/x/x Subsystem ID
#define D16F7_CAP_POINTER		0x34	//Capability Pointer
    #define D16F7_CAP_PTR			0xFF	//80h/R/x/x Capability Pointer
#define D16F7_INTR_LINE		0x3C	//Interrupt Line
    #define D16F7_INTLN_7_4			0xF0	//0/x/x/x Reserved
    #define D16F7_INTLN_3_0			0xF	//0000b/x/x/x USB Interrupt Routing
#define D16F7_INTR_PIN		0x3D	//Interrupt Pin
    #define D16F7_RINTABCD			0xFF	//04h/R/x/x Interrupt Pin
#define D16F7_MIN_GNT		0x3E	//Min_Gnt
    #define D16F7_MINGNT			0xFF	//0/R/x/x Minimal Burst Period
#define D16F7_MAX_LAT		0x3F	//Max_Lat
    #define D16F7_MAXLAT			0xFF	//0/R/x/x Frequency for Gain PCI Bus
#define D16F7_CTL_REG_1		0x40	//Control Register 1
    #define D16F7_CAHCFG			BIT7	//0/0/x/x ((For Internal Reference:0: Old method, use the same PDSUSMOD/PDALL to control USB2 EPHY and USB32EPHY. 
    #define D16F7_BABOPT			BIT6	//0/0/x/x Babble Option
    #define D16F7_PAROPT			BIT5	//0/0/x/x Reserved
    #define D16F7_REDUCE			BIT4	//0/0/x/x Micro-Frame Interval Select
    #define D16F7_HCISPEC			BIT3	//0/0/x/x Reserved
    #define D16F7_DAC_EN			BIT2	//0/0/x/x DAC Enable
    #define D16F7_FCFG			BIT1	//0/0/1/0 DMA Option ((Random))
    #define D16F7_C4P_REDU			BIT0	//0/0/x/x Reserved
#define D16F7_TEST_CTL_1		0x41	//Test Control 1
    #define D16F7_DISSTUFF			BIT7	//0/0/x/x Reserved
    #define D16F7_CHK_NULLSOF_SEL			BIT6	//0/0/x/x Reserved
    #define D16F7_EN_CHKPERIODEN			BIT5	//1b/1b/1/x Enable Evaluate PERIODIC Enable Bit only at the Beginning of Micro-Frame 0
    #define D16F7_ENOCPY			BIT4	//0/0/x/x Reserved
    #define D16F7_TESTCNT			BIT3	//0/0/x/x Reserved
    #define D16F7_TRAPOPT			BIT2	//0/0/x/x Reserved
    #define D16F7_TST_SQUELCH_EN			BIT1	//0/0/x/x Reserved
    #define D16F7_UIRQACT			BIT0	//0/R/x/x Reserved
#define D16F7_CTL_REG_2		0x42	//Control Register 2
    #define D16F7_SELEOF			BIT7	//0/0/x/x Reserved
    #define D16F7_EN_PRESOFCHK			BIT6	//1b/1b/1/x Enable Check PRESOF for ITD (Isochronous Transfer Descriptor) OUT Transaction During Fetching Data from DRAM
    #define D16F7_EN_ISOFF_RST_ANYTIME			BIT5	//0/0/x/x Reserved
    #define D16F7_SUBIDWE			BIT4	//0/0/x/x Reserved
    #define D16F7_ISOFF_RST_EN			BIT3	//0/0/x/x Reserved
    #define D16F7_OCUPY_SEL			(BIT0 + BIT1 + BIT2)	//011b/011b/011b/011b Reserved
#define D16F7_CTL_REG_3		0x43	//Control Register 3
    #define D16F7_DIS_TERM_ON_H			BIT7	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_G			BIT6	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_F			BIT5	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_E			BIT4	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_D			BIT3	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_C			BIT2	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_B			BIT1	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_A			BIT0	//0/0/x/x Reserved
#define D16F7_CTL_REG_4		0x44	//Control Register 4
    #define D16F7_DEBUG31_7_2			0xFC	//0/x/x/x Reserved
    #define D16F7_DIS_TERM_ON_J			BIT1	//0/0/x/x Reserved
    #define D16F7_DIS_TERM_ON_I			BIT0	//0/0/x/x ((For Internal Reference:
#define D16F7_CTL_REG_45		0x45	//Control Register 45
    #define D16F7_VIOD			0xFE	//0/x/x/x Reserved
    #define D16F7_HSRXACT_DLYEN			BIT0	//0/0/x/x ((For Internal Reference:EPHY HSTX/RXACT Delay Control
#define D16F7_CTL_REG_5		0x48	//Control Register 5
    #define D16F7_DISCHKEOPERR			BIT7	//1b/1/x/x USB 2.0 EOP Pattern (FEh) Error Check
    #define D16F7_ENISOHANDCHK			BIT6	//0/0/x/x Extra Handshake Error Checking in Isochronous Transaction
    #define D16F7_DIS_BURST			BIT5	//1b/1/0/x DMA Burst Access((Random))
    #define D16F7_EN_REF_RVLD			BIT4	//1b/1/x/x USB 2.0 Reference Bus Idle Status
    #define D16F7_EN_PATCH_HEAD			BIT3	//1b/1/x/x Reserved (Do Not Program)
    #define D16F7_EN_UTM_RESET			BIT2	//1b/1/x/x Reserved (Do Not Program) 
    #define D16F7_EN_CHKTOGCRC			BIT1	//1b/1/x/x USB 2.0 CRC16 Check Enable for Toggle Mismatch
    #define D16F7_HSENFB_DIS			BIT0	//0/0/x/x HS (High Speed) Port Align to Micro-Frame Boundary
#define D16F7_CTL_REG_6		0x49	//Control Register 6
    #define D16F7_TXDELAY_EN			BIT7	//0/0/x/x MAC Allows More Delay between Transactions
    #define D16F7_TXTMOUT_EN			BIT6	//1b/1/1/1 MAC Provides Timeout to Device When Receiver Detects Error
    #define D16F7_CLKOFF_EN			BIT5	//1b/1/x/1 EHCI Clock Auto Stop ((Random))
    #define D16F7_DISPDRCV			BIT4	//0/0/x/0 Auto Power Down Receiver Squelch Detector
    #define D16F7_NEW_USB_C4P_EN			BIT3	//1b/1/x/1 Reserved
    #define D16F7_C4P_48MPLLOFF			BIT2	//0/0/x/x Reserved
    #define D16F7_NEW_USB_NULLSOF_SEL			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define D16F7_MAC_INTER_TRANSACTION_DELAY_PARAMETER		0x4A	//MAC Inter-Transaction Delay Parameter
    #define D16F7_TXDELAY_PARM			0xFF	//0/0/x/x MAC Inter-Transaction Delay Parameter
#define D16F7_MAC_TURN_AROUND_TIME_PARAMETER		0x4B	//MAC Turn Around Time Parameter
    #define D16F7_DIS_NARROW_SOF			BIT7	//0/0/x/x SOF (Start of Frame) Disconnects Detection Period
    #define D16F7_SLEEPTIME_SEL			(BIT5 + BIT6)	//00b/00b/*10b/*11b EHCI Sleep Time Select ((Random))
    #define D16F7_DIS_SOF_RUN			BIT4	//0/0/x/x Disable Sending UTM_SOF (Start of Frame of USB Transceiver Macrolcell) When RUN Bit is Cleared
    #define D16F7_TURN_PARM			0xF	//9h/9h/x/x USB 2.0 MAC Transmit Turn Around Time Parameter
#define D16F7_PHY_CTL_1		0x4C	//PHY Control 1
    #define D16F7_C4PR_FASTACK			BIT7	//0/0/x/x Reserved
    #define D16F7_EN_BMASTR_AUTODIS			BIT6	//0/0/x/x Reserved
    #define D16F7_EN_UTM_SPDUP			BIT5	//0/0/x/x USB1.0 UTM (USB Transceiver Macrocell) Tx Speed Up
    #define D16F7_EN_DBG_PORT			BIT4	//1b/1/x/x USB2.0 EHCI Debug Port Support Enable
    #define D16F7_SYNC_FAST			BIT3	//0/0/x/x Reserved
    #define D16F7_SYNC_JEND			BIT2	//0/0/x/x Enable USB2.0 Receiver Sync Pattern Detect with ＆J＊_End 
    #define D16F7_DEBUGC_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D16F7_PHY_CTL_2		0x4D	//PHY Control 2
    #define D16F7_DBG_USBEN			BIT7	//1b/1/x/x Reserved (Do Not Program)
    #define D16F7_DBGMOD_SEL			(BIT5 + BIT6)	//0/0/x/x Reserved
    #define D16F7_HSPRESOF_SEL			(BIT3 + BIT4)	//10b/10b/10b/x Reserved ((Random))
    #define D16F7_FIFOSIZE_SEL			(BIT0 + BIT1 + BIT2)	//100b/100b/100b/x Reserved (Do Not Program)
#define D16F7_USB_CP4_CTL_0		0x4E	//USB CP4 Control 0
    #define D16F7_SUSPEND_TIME_SEL			BIT7	//0/0/x/x Reserved
    #define D16F7_RESUME_SEL			(BIT5 + BIT6)	//0/0/x/x Reserved ((Random))
    #define D16F7_EN_UCONNDET			BIT4	//0/0/x/x Reserved ((Random))
    #define D16F7_ASYNC_SLEEP_SEL			BIT3	//0/0/x/x Long Time Sleep Method Selection to Get the New Asynchronous List
    #define D16F7_ASYNC_IDLE_SEL			(BIT1 + BIT2)	//01b/01b/x/x Standard of Asynchronous List IDLE
    #define D16F7_EN_PATCH_GOLDENTREE			BIT0	//1b/1b/x/x Enable Patch Golden Tree
#define D16F7_USB_C4P_CTL_1		0x4F	//USB C4P Control 1
    #define D16F7_EN_RST_NULLSOF_AT_PORTRST			BIT7	//0/0/x/x Reserved
    #define D16F7_EN_C4P_LG1MF			BIT6	//0/0/x/x Reserved
    #define D16F7_C4P_RUNSET_SEL			BIT5	//0/0/x/x Resreved
    #define D16F7_EN_CLEAR_RUN			BIT4	//0/0/x/x Enable Clear RUN Bit When EHCI_IDLE If S/W Clears RUN Bit
    #define D16F7_EN_PORTRST_INC4P			BIT3	//0/0/x/x Reserved
    #define D16F7_NULLSOF_DET_SEL			BIT2	//0/0/x/x Reserved
    #define D16F7_EN_HALT_C4PSWT			BIT1	//0/0/x/x Reserved
    #define D16F7_EN_PDPHY_INPDPLL			BIT0	//0/0/x/x Reserved 
#define D16F7_TEST_CMD		0x50	//Test Command
    #define D16F7_EN_PATCH_DOORBELL			BIT7	//1b/1b/x/x USB 2.0 Doorbell Bit Function Patch
    #define D16F7_FORCE_CRCERR			BIT6	//0/0/x/x Reserved
    #define D16F7_TEST_EYE_EN			BIT5	//0/0/x/x Reserved
    #define D16F7_UTM_CHKERR			BIT4	//0/R/x/x Reserved
    #define D16F7_BIST_ERROR			BIT3	//0/R/x/x Reserved
    #define D16F7_BIST_RUN			BIT2	//0/R/x/x Reserved
    #define D16F7_SWDBG			BIT1	//0/0/x/x Reserved
    #define D16F7_TEST_COMMAND_0			BIT0	//0/R/x/x Reserved
#define D16F7_USB_2_0_MAC_TIMEOUT_PARAMETER		0x51	//USB 2.0 MAC Timeout Parameter
    #define D16F7_TMOUT_PARM			0xFF	//60h/60h/x/x USB 2.0 Receiver Timeout Parameter
#define D16F7_CTL_REG_6_Z1		0x52	//Control Register 6
    #define D16F7_SUS_DEBUG0			BIT7	//1b/1/x/x Reserved
    #define D16F7_SUS_DEBUG1			BIT6	//1b/1/x/x PLLOK Selection Control
    #define D16F7_EN_OUTC4P_NULLSOF_RST			BIT4	//1b/1/x/x Reserved
    #define D16F7_EN_C4P_IOCINT			BIT3	//0/0/x/x Reserved
    #define D16F7_EN_USB_C4P_NOD3			BIT2	//0/0/x/x Reserved
    #define D16F7_EN_NEW_PDAPLL			BIT1	//0/0/x/0 Enable New PLL Power Down Scheme 
    #define D16F7_EN_NEW_PDHSDRV			BIT0	//0/0/x/0 USB Physical Circuitry Power Down Condition
//D14F7
#define D14F7_PORT_CTL_REG_1		0x53	//Port Control Register 1
    #define D14F7_CONCHG_RSM_EN2			BIT7	//1b/1/x/x Port 2 Resume Enable (need set Rx53[1] to 1＊b0)
    #define D14F7_CONCHG_RSM_EN1			BIT6	//1b/1/x/x Port 1 Resume Enable (need set Rx53[0] to 1＊b0)
    #define D14F7_RX53_5			BIT5	//1b/x/x/x Reserved
    #define D14F7_RX53_4			BIT4	//1b/x/x/x Reserved
    #define D14F7_RESUME_EN4			BIT3	//1b/1/x/x Port 4 Resume Enable (need set Rx54[1] to 1＊b0)
    #define D14F7_RESUME_EN3			BIT2	//1b/1/x/x Port 3 Resume Enable (need set Rx54[0] to 1＊b0)
    #define D14F7_RESUME_EN2			BIT1	//1b/1/x/x Port 2 Resume Enable (need set Rx53[7] to 1＊b0)
    #define D14F7_RESUME_EN1			BIT0	//1b/1/x/x Port 1 Resume Enable (need set Rx53[6] to 1＊b0)
#define D14F7_PORT_CTL_REG_2		0x54	//Port Control Register 2
    #define D14F7_RSTAPLL_CTL			BIT7	//0/x/x/x EPHY RSTAPLL Control 
    #define D14F7_RSTAPLL_REG			BIT6	//0/x/x/x EPHY RSTAPLL Register Control Bit
    #define D14F7_DISPD_EPHY			BIT5	//0/x/x/x EPHY Power Down Select
    #define D14F7_RX54_4			BIT4	//0/x/x/x Reserved
    #define D14F7_RX54_3			BIT3	//0/x/x/x Reserved
    #define D14F7_CONN_EN_REG			BIT2	//1b/1/x/x Detect Device Connection If D+/D- = 1/1
    #define D14F7_CONCHG_RSM_EN4			BIT1	//1b/1/x/x Port 4 Resume Enable (need set Rx53[3] to 1＊b0)
    #define D14F7_CONCHG_RSM_EN3			BIT0	//1b/1/x/x Port 3 Resume Enable (need set Rx53[2] to 1＊b0)
//D16F7
#define D16F7_PHY_CTL_7		0x58	//PHY Control 7
    #define D16F7_IAAD_INT			BIT7	//1b/1/x/x Async Advance Interrupt Lost Issue Patch
    #define D16F7_ASYEN_SEL			BIT6	//1b/1b/x/x Async Enable Condition Selection
    #define D16F7_RX_BLOCK_DIS			BIT5	//0/0/x/x Reserved
    #define D16F7_TSTMOD			BIT4	//0/0/x/x Reserved
    #define D16F7_SOF_DISCONN_LATE			BIT3	//0b/0/x/x High-Speed Disconnect During SOF Period Time Select
    #define D16F7_SOF_DISCONN_CHK			BIT2	//1b/1/1/x Detect High-Speed Disconnect During SOF Period
    #define D16F7_CP1			BIT1	//0/0/x/x Reserved
    #define D16F7_CP0			BIT0	//0/0/x/x Reserved
#define D16F7_PHY_CTL_8		0x59	//PHY Control 8
    #define D16F7_PDPHY_DIS			BIT7	//0/0/x/0 Disable PHY Auto Power-Down Feature
    #define D16F7_SETPOWNER_DIS			BIT6	//0/0/x/x Transit POwner (Port Owner) Control
    #define D16F7_AUTOCHK			BIT5	//0/0/x/x Reserved
    #define D16F7_PHYOPT2_4_1			0x1E	//0/x/x/x Reserved
    #define D16F7_BYPASSDIV4			BIT0	//1b/1/x/x Reserved
#define D16F7_PHY_CTL_9		0x5C	//PHY Control 9
    #define D16F7_RXDATADLY_2			BIT6	//0/0/x/x High Speed Transmitter
    #define D16F7_RXDATADLY_1_0			(BIT4 + BIT5)	//00b/00b/x/x DPLL Input Data Delay Select
#define D16F7_SERIAL_BUS_RELEASE_NUM		0x60	//Serial Bus Release Number
    #define D16F7_USBSPEC			0xFF	//20h/R/x/x Serial Bus Release Number
#define D16F7_FRAME_LEN_ADJUSTMENT		0x61	//Frame Length Adjustment
    #define D16F7_FLADJ			0x3F	//20h/20h/x/x Frame Length Adjustment
#define D16F7_PORT_WAKE_CAP		0x62	//Port Wake Capability
    #define D16F7_PORTWAKECAP			0x7FE	//0/0/x/x Port Wake Up Capability Mask
    #define D16F7_PORTWAKECAP0			BIT0	//1b/R/x/x Port Wake Capability Register Implementation
#define D16F7_USB_CP4_CTL_1		0x64	//USB CP4 Control 1
    #define D16F7_SELFWAKE_MFSEL			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D16F7_SELFWAKE_TMSEL			(BIT4 + BIT5)	//0/0/x/x Reserved
    #define D16F7_SELFWAKE_EN			BIT3	//0/0/x/x Reserved ((Random))
    #define D16F7_NULLSOF_SEL_2			BIT2	//0/0/x/x Reserved
    #define D16F7_HSISO_C4INH_EN			BIT1	//1b/1b/x/x Reserved
    #define D16F7_UHCISO_C4INH_EN			BIT0	//1b/1b/x/x Reserved
#define D16F7_CTL_REG		0x65	//Control Register
    #define D16F7_REDUN_BIT1			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D16F7_NEW_PCLK33_PD_EN			BIT5	//1b/1/1/1 Enable 33MHz Dynamic Scheme ((Random))
    #define D16F7_NEW_PCLK66_PD_EN			BIT4	//1b/1/1/1 Enable 66MHz Dynamic Scheme ((Random))
    #define D16F7_QHCIGNT_SEL			BIT3	//1b/1/x/x Async Controller Bus Authority Selection
    #define D16F7_COMPL_EOT			BIT2	//1b/1/x/x Reserved
    #define D16F7_BMASTREN_SEL			BIT1	//0/0/1/x Bus Master Enable Select
    #define D16F7_DBGMODE_SEL_2			BIT0	//0/0/x/x Reserved
#define D16F7_CTL_REG_WAKE		0x66	//Control Register Wake
    #define D16F7_SUS_RSV667			BIT7	//0b/x/x/x Reserved
    #define D16F7_SUS_RSV666			BIT6	//0b/x/x/x Reserved
    #define D16F7_SUS_RSV6653			(BIT3 + BIT4 + BIT5)	//000b/x/x/x Reserved
    #define D16F7_SUS_RSV662			BIT2	//0b/x/x/x Reserved
    #define D16F7_SUS_RSV661			BIT1	//0b/x/x/x Reserved
    #define D16F7_SUS_RSV660			BIT0	//0b/x/x/x Reserved
#define D16F7_USB_LEGACY_SUPPORT_EXTENDED_CAP		0x68	//USB Legacy Support Extended Capability
    #define D16F7_OSOWNS			BIT24	//0/x/x/x USB Host Controller ((HC)) OS-owned Semaphore
    #define D16F7_BIOSOWNS			BIT16	//0/x/x/x USB Host Controller ((HC)) BIOS-owned Semaphore
    #define D16F7_USBLEGSUP_15_8			0xFF00	//0/R/x/x Next EHCI Extended Capability Pointer
    #define D16F7_USBLEGSUP_7_0			0xFF	//01h/R/x/x Capability ID
#define D16F7_USB_LEGACY_SUPPORT_CTL_STA		0x6C	//USB Legacy Support Control / Status
    #define D16F7_SMIONBAR			BIT31	//0/x/x/x SMI on BAR
    #define D16F7_SMIONPCMD			BIT30	//0/x/x/x SMI on PCI Command
    #define D16F7_SMIOSOWNCHG			BIT29	//0/x/x/x SMI on OS Ownership Change
    #define D16F7_USBSTS_5			BIT21	//0/R/x/x SMI on Ssync Advance
    #define D16F7_USBSTS_4			BIT20	//0/R/x/x SMI on Host System Error
    #define D16F7_USBSTS_3			BIT19	//0/R/x/x SMI on Frame List Rollover
    #define D16F7_USBSTS_2			BIT18	//0/R/x/x SMI on Port Change Detect
    #define D16F7_USBSTS_1			BIT17	//0/R/x/x SMI on USB Error
    #define D16F7_USBSTS_0			BIT16	//0/R/x/x SMI on USB Complete
    #define D16F7_SMIONBAR_EN			BIT15	//0/x/x/x SMI on BAR Enable
    #define D16F7_SMIONPCMD_EN			BIT14	//0/x/x/x SMI on PCI Command Enable
    #define D16F7_SMIOWN_EN			BIT13	//0/x/x/x SMI on OS Ownership Enable
    #define D16F7_SMIASYNC_EN			BIT5	//0/x/x/x SMI on Async Advance Enable
    #define D16F7_SMIHERR_EN			BIT4	//0/x/x/x SMI on Host System Error Enable
    #define D16F7_SMIFROVER_EN			BIT3	//0/x/x/x SMI on Frame List Rollover Enable
    #define D16F7_SMIPORTCHG_EN			BIT2	//0/x/x/x SMI on Port Change Enable
    #define D16F7_SMIUSBERR_EN			BIT1	//0/x/x/x SMI on USB Error Enable
    #define D16F7_USBSMI_EN			BIT0	//0/x/x/x USB SMI Enable
#define D16F7_SRAM_DIRECT_ACCESS_ADR		0x70	//SRAM Direct Access Address
    #define D16F7_SRAM_ADDR			0x1FF	//0/0/x/x SRAM Direct Access Address
#define D16F7_SRAM_DIRECT_ACCESS_CTL		0x73	//SRAM Direct Access Control
    #define D16F7_SRAM_SEL			(BIT4 + BIT5)	//0/0/x/x SRAM Select
    #define D16F7_SRAM_RUN			BIT1	//0/0/x/x SRAM Operation Start
    #define D16F7_SRAM_WR			BIT0	//0/0/x/x SRAM Read / Write Control
#define D16F7_SRAM_DATA		0x74	//SRAM Data
    #define D16F7_BIST_PATTERN			0xFFFFFFFF	//0/0/x/x SRAM Data
#define D16F7_EHCIOPTIONAL_BITS_CFG_ADR		0x78	//EHCI Optional Bits Configuration Address
    #define D16F7_EHCI_OPT_ADD_31_20			0xFFF00000	//0/x/x/x Reserved
    #define D16F7_OPTCFGADDR			0xFFFFF	//0/0/x/x EHCI Optional Bits Configuration Address
#define D16F7_EHCIOPTIONAL_BITS_CFG_DATA		0x7C	//EHCI Optional Bits Configuration Data
	#define D16F7_EHCIOPTIONAL_BITS_CFG_DATA_Byte0 0x7C
	#define D16F7_EHCIOPTIONAL_BITS_CFG_DATA_Byte1 0x7D
	#define D16F7_EHCIOPTIONAL_BITS_CFG_DATA_Byte2 0x7E
	#define D16F7_EHCIOPTIONAL_BITS_CFG_DATA_Byte3 0x7F
    #define D16F7_OPTCFGDATA			0xFFFFFFFF	//01001000h/01001000h/x/x EHCI Optional Bits Configuration Data
#define D16F7_PM_CAP_ID		0x80	//Power Management Capability ID
    #define D16F7_PMI_REG1_7_0			0xFF	//01h/R/x/x Power Management Capability ID
#define D16F7_NEXT_ITEM_POINTER_1		0x81	//Next Item Pointer 1
    #define D16F7_CAP_PTR2			0xFF	//88h/R/x/x Next Item Pointer 1
#define D16F7_PM_CAP		0x82	//Power Management Capability
    #define D16F7_PMI_REG1_31_16			0xFFFF	//FFC2h/R/x/x Power Management Capability
#define D16F7_PM_CAP_CTL_STA		0x84	//Power Management Capability Control / Status
    #define D16F7_PME_STS			BIT15	//0/x/x/x PME Status
    #define D16F7_PME_EN			BIT8	//0/0/x/x PME Enable
    #define D16F7_PWR_STATE			(BIT0 + BIT1)	//00b/00b/x/x Power State
#define D16F7_DEBUG_PORT_CAP_ID		0x88	//Debug Port Capability ID
    #define D16F7_DBG_REG_7_0			0xFF	//0Ah/R/x/x Debug Port Capability ID
#define D16F7_NEXT_ITEM_POINTER_2		0x89	//Next Item Pointer 2
    #define D16F7_DBG_REG_15_8			0xFF	//98h/R/x/x Next Item Pointer 2
#define D16F7_DEBUG_PORT_BASE_OFFSET		0x8A	//Debug Port Base Offset
    #define D16F7_DBG_REG_31_16			0xFFFF	//20A0h/R/x/x Debug Port Base Offset
#define D16F7_FLR_CAP_ID		0x98	//FLR Capability ID
    #define D16F7_FLR_CID			0xFF	//13h/R/x/x FLR Capability ID
#define D16F7_NEXT_ITEM_POINTER_2_Z1		0x99	//Next Item Pointer 2
    #define D16F7_CAP_PTR_FLR			0xFF	//00h/R/x/x Next Item Pointer 2
#define D16F7_FLR_CAP_LEN_AND_VER_REG		0x9A	//FLR Capability Length and Version Register
    #define D16F7_FLR_CAP			BIT9	//1b/1/x/x FLR Capability
    #define D16F7_FLR_TXPCAP			BIT8	//1b/1/x/x TXP Capability
    #define D16F7_FLR_LEN			0xFF	//06h/06h/x/x Capability Length
#define D16F7_FLR_CTL_REG		0x9C	//FLR Control Register
    #define D16F7_INI_FLR			BIT0	//0/0/x/x Initiate FLR
#define D16F7_FLR_CAP_LEN_AND_VER_REG_Z1		0x9D	//FLR Capability Length and Version Register
    #define D16F7_FLR_TXP			BIT0	//0/0/x/x TXP Status Register
#define D16F7_FLR_PENDING_STA_REG		0x9E	//FLR Pending Status Register
    #define D16F7_FLR_STS			BIT0	//0/0/x/x FLR Pending Status
#define D16F7_FLR_AND_VID_OPTIONAL_REG		0x9F	//FLR and VID OPTIONAL Register
    #define D16F7_DBGMOD_SEL3_2			0xF0	//0/0/x/x Debug Signal Select 2
    #define D16F7_DBGMOD_SEL3_1			BIT3	//0/0/x/x Debug Signal Select 1
    #define D16F7_VID_OPTIONAL			BIT2	//0/0/X/x Vendor ID OPTIONAL
    #define D16F7_FLR_CAP_OPTIONAL			BIT1	//0/0/x/x FLR Capability Attribute Change OPTIONAL Register
    #define D16F7_FLR_OPTIONAL			BIT0	//1b/1/x/x FLR OPTIONAL
#define D16F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS		0xA0	//Port OC Pin Mux Select and CCS Gating Registers
    #define D16F7_RXA30_32_28			0xF0000000	//0101b/x/x/x Reserved
    #define D16F7_RXA30_27_24			0xF000000	//0100b/x/x/x Reserved
    #define D16F7_PORTD_OC_MUX			0xF00000	//0011b/x/x/x Port 4 OC Pin Mux Select Register
    #define D16F7_PORTC_OC_MUX			0xF0000	//0010b/x/x/x Port 3 OC Pin Mux Select Register
    #define D16F7_PORTB_OC_MUX			0xF000	//0001b/x/x/x Port 2 OC Pin Mux Select Register
    #define D16F7_PORTA_OC_MUX			0xF00	//0000b/x/x/x Port 1 OC Pin Mux Select Register
    #define D16F7_REDUN_CELL			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D16F7_RXA30_5			BIT5	//0/x/x/x Reserved
    #define D16F7_RXA30_4			BIT4	//0/x/x/x Reserved
    #define D16F7_PORT4_CCS_GATE			BIT3	//0/0/x/x Port 4 Connect Status Gating Register
    #define D16F7_PORT3_CCS_GATE			BIT2	//0/0/x/x Port 3 Connect Status Gating Register
    #define D16F7_PORT2_CCS_GATE			BIT1	//0/0/x/x Port 2 Connect Status Gating Register
    #define D16F7_PORT1_CCS_GATE			BIT0	//0/0/x/x Port 1 Connect Status Gating Register
#define D16F7_FRAME_INTERVAL_CONFIGURE_VALUE		0xA4	//Frame Interval Configure Value
    #define D16F7_REDUN_BIT12			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D16F7_FMINTV_VAL_EN			BIT13	//0/x/x/x Frame Interval Configure Value Enable
    #define D16F7_FMINTV_VAL			0x1FFF	//743h/x/x/x Frame Interval Configure Value
#define D16F7_CCA_BUS_SRC_ID		0xA6	//CCA BUS Source ID
    #define D16F7_U2BDF			0xFFFF	//0087h/x/x/x CCA BUS Source ID
#define D16F7_PORT_6_7_8_OC_PIN_MUX_REG		0xA8	//Port 6/7/8 OC Pin Mux Register
    #define D16F7_JTOK_FILTER_SEL			(BIT8 + BIT9)	//0/0/x/x SDP/SDN Filter Glitch Setting
    #define D16F7_PDAPLL_DLYEN			BIT7	//0/0/x/x PDAPLL Delay Control
    #define D16F7_CRESUME_CDC_EN			BIT6	//0/0/x/x Fix Port CResume CDC Bug
    #define D16F7_DIS_FULL_HIGH_DEV6			BIT5	//0/x/x/x Reserved
    #define D16F7_DIS_FULL_HIGH_DEV5			BIT4	//0/x/x/x Reserved
    #define D16F7_DIS_FULL_HIGH_DEV4			BIT3	//0/x/x/x Reserved
    #define D16F7_DIS_FULL_HIGH_DEV3			BIT2	//0/x/x/x Reserved
    #define D16F7_DIS_FULL_HIGH_DEV2			BIT1	//0/x/x/x Reserved
    #define D16F7_DIS_FULL_HIGH_DEV1			BIT0	//0/x/x/x Reserved
#define D16F7_CCA_BUS_SRC_ID_Z1		0xAA	//CCA BUS source ID
    #define D16F7_REDUN_REG2			0xFF	//0/x/x/x Redundant Registers 2
#define D16F7_DID_OPTIONAL		0xAC	//Device ID OPTIONAL
    #define D16F7_DID_OPTIONAL_Z1			0xFFFF	//3104h/x/x/x Device ID OPTIONAL
#define D16F7_DID_OPTIONAL_Z2		0xAE	//Device ID OPTIONAL
    #define D16F7_VID_OPTIONAL_SEL			0xFFFF	//1d17h/x/x/x Vendor ID OPTIONAL
#define D16F7_REV_ID_OPTIONAL		0xF5	//Revision ID OPTIONAL
    #define D16F7_REVID_BACK			0xFF	//00h/0h/x/x Revision ID OPTIONAL
#define D16F7_INTERNAL_REV_ID		0xF6	//Internal Revision ID
    #define D16F7_REVID			0xFF	//B0h/R/x/x Internal Revision ID
#define D16F7_REV_ID_OPTIONAL_CTL		0xFC	//Revision ID OPTIONAL Control
    #define D16F7_CCA_REQ_GATE_EN			BIT1	//0/0/x/x CCA requeset gating enable for debug mode
    #define D16F7_BACK_EN			BIT0	//0/0/x/x Revision ID OPTIONAL Reflection Enable
//USB 2.0-MMIO
#define USB_20MMIO_CAP_REG_LEN		0x00	//Capability Register Length
    #define USB_20MMIO_CAPLENGTH			0xFF	//10h/x/x/x Capability Register Length
#define USB_20MMIO_IF_VER_NUM		0x02	//Interface Version Number
    #define USB_20MMIO_HCIVERSION			0xFFFF	//0100h/0100h/x/x Interface Version Number
#define USB_20MMIO_STRUCTURE_PARAMETERS		0x04	//Structure Parameters
    #define USB_20MMIO_HCSPARAMS			0xFFFFFFFF	//00102204h/00102204h/x/x Structure Parameters
#define USB_20MMIO_CAP_PARAMETERS		0x08	//Capability Parameters
    #define USB_20MMIO_HCCPARAMS			0xFFFFFFFF	//00006872h/00006872h/x/x Capability Parameters
#define USB_20MMIO_USB_CMD		0x10	//USB Command
    #define USB_20MMIO_INTTHRESHOLD			0xFF0000	//08h/08h/x/x Interrupt Threshold Control
    #define USB_20MMIO_LIGHTRST			BIT7	//0/0/x/x Light Host Controller Reset
    #define USB_20MMIO_INTDOORBELL			BIT6	//0/x/x/x Interrupt on Async Advance Doorbell
    #define USB_20MMIO_ASYNC_EN_TMP			BIT5	//0/x/x/x Asynchronous Schedule Enable
    #define USB_20MMIO_PERIOD_EN_TMP			BIT4	//0/x/x/x Periodic Schedule Enable
    #define USB_20MMIO_FRLSTSIZE			(BIT2 + BIT3)	//0/x/x/x Frame List Size
    #define USB_20MMIO_HCRESET			BIT1	//0/0/x/x Host Controller Reset
    #define USB_20MMIO_RUN_SW			BIT0	//0/x/x/x Run / Stop
#define USB_20MMIO_USB_STA		0x14	//USB Status
    #define USB_20MMIO_ASYNC_STS			BIT15	//0/R/x/x Asynchronous Schedule Status
    #define USB_20MMIO_PERIOD_STS			BIT14	//0/R/x/x Periodic Schedule Status
    #define USB_20MMIO_RECLAMATION			BIT13	//0/R/x/x Reclamation
    #define USB_20MMIO_HCHALT			BIT12	//1b/R/x/x Host Controller Halted
    #define USB_20MMIO_INTASYNC			BIT5	//0/x/x/x Interrupt on Async Advance
    #define USB_20MMIO_HSERR			BIT4	//0/x/x/x Host System Error
    #define USB_20MMIO_ROLLOVER			BIT3	//0/x/x/x Frame List Rollover
    #define USB_20MMIO_PORTCHG			BIT2	//0/x/X/x Port Change Detect
    #define USB_20MMIO_ERRINT			BIT1	//0/x/x/x USB Error Interrupt
    #define USB_20MMIO_USBINT			BIT0	//0/x/x/x USB Interrupt
#define USB_20MMIO_USB_INTR_ENABLE		0x18	//USB Interrupt Enable
    #define USB_20MMIO_USBINTR			0x3F	//0/x/x/x USB Interrupt Enable
#define USB_20MMIO_USB_FRAME_INDEX		0x1C	//USB Frame Index
    #define USB_20MMIO_FRNUM_SYNC			0x1FFF	//0/x/x/x USB Frame Index
#define USB_20MMIO_4G_SEGMENT_SELOR		0x20	//4G Segment Selector
    #define USB_20MMIO_CTRLDSSEGMENT			0xFFFFFFFF	//0/R/x/x 4G Segment Selector
#define USB_20MMIO_FRAME_LIST_BASE_ADR		0x24	//Frame List Base Address
    #define USB_20MMIO_FLBASE			0xFFFFF000	//0/x/x/x Frame List Base Address
#define USB_20MMIO_NEXT_ASYNCHRONOUS_LIST_ADR		0x28	//Next Asynchronous List Address
    #define USB_20MMIO_ASYNCLISTADDR_31_5			0xFFFFFFE0	//0/x/x/x Next Asynchronous List Address
#define USB_20MMIO_CONFIGURED_FLAG		0x50	//Configured Flag
    #define USB_20MMIO_CONFIGFLAG			BIT0	//0/x/x/x Configured Flag
#define USB_20MMIO_PORT_0_STA_CTL		0x54	//Port 0 Status / Control
    #define USB_20MMIO_WKOC_E_0			BIT22	//0/x/x/x Wake on Over-current Enable
    #define USB_20MMIO_WKDSCNNT_E_0			BIT21	//0/x/x/x Wake on Disconnect Enable
    #define USB_20MMIO_WKCNNT_E_0			BIT20	//0/x/x/x Wake on Connect Enable
    #define USB_20MMIO_PTSTCTRL_0			0xF0000	//0/x/x/x Port Test Control
    #define USB_20MMIO_POWNER_0			BIT13	//1b/x/x/x Port Owner
    #define USB_20MMIO_PP_0			BIT12	//1b/x/x/x Port Power
    #define USB_20MMIO_LINESTATUS_SYN_0			(BIT10 + BIT11)	//0/R/x/x Line Status
    #define USB_20MMIO_SPORTRST_SYN_0			BIT8	//0/x/x/x Port Reset
    #define USB_20MMIO_SSUSPEND_NRM_0			BIT7	//0/0/x/x Suspend
    #define USB_20MMIO_SRESUME_NRM_0			BIT6	//0/x/x/x Force Port Resume
    #define USB_20MMIO_OVERCURR_CHG_0			BIT5	//0/x/x/x Over-current Change
    #define USB_20MMIO_OVERCURR_0			BIT4	//0/R/x/x Over-current Active
    #define USB_20MMIO_PORTENDIS_CHG_0			BIT3	//0/x/x/x Port Enable / Disable Change
    #define USB_20MMIO_SPORTENDIS_0			BIT2	//0/0/x/x Port Enabled / Disabled
    #define USB_20MMIO_CONNSTATUS_CHG_0			BIT1	//0/x/x/x Connect Status Change
    #define USB_20MMIO_CONNSTATUS_0			BIT0	//0/R/x/x Current Connect Status
#define USB_20MMIO_PORT_1_STA_CTL		0x58	//Port 1 Status / Control
    #define USB_20MMIO_WKOC_E_1			BIT22	//0/x/x/x Wake on Over-current Enable
    #define USB_20MMIO_WKDSCNNT_E_1			BIT21	//0/x/x/x Wake on Disconnect Enable
    #define USB_20MMIO_WKCNNT_E_1			BIT20	//0/x/x/x Wake on Connect Enable
    #define USB_20MMIO_PTSTCTRL_1			0xF0000	//0/x/x/x Port Test Control
    #define USB_20MMIO_POWNER_1			BIT13	//1b/x/x/x Port Owner
    #define USB_20MMIO_PP_1			BIT12	//1b/R/x/x Port Power
    #define USB_20MMIO_LINESTATUS_SYN_1			(BIT10 + BIT11)	//0/R/x/x Line Status
    #define USB_20MMIO_SPORTRST_SYN_1			BIT8	//0/x/x/x Port Reset
    #define USB_20MMIO_SSUSPEND_NRM_1			BIT7	//0/0/x/x Suspend
    #define USB_20MMIO_SRESUME_NRM_1			BIT6	//0/x/x/x Force Port Resume
    #define USB_20MMIO_OVERCURR_CHG_1			BIT5	//0/x/x/x Over-current Change
    #define USB_20MMIO_OVERCURR_1			BIT4	//0/R/x/x Over-current Active
    #define USB_20MMIO_PORTENDIS_CHG_1			BIT3	//0/x/x/x Port Enable / Disable Change
    #define USB_20MMIO_SPORTENDIS_1			BIT2	//0/0/x/x Port Enabled / Disabled
    #define USB_20MMIO_CONNSTATUS_CHG_1			BIT1	//0/x/x/x Connect Status Change
    #define USB_20MMIO_CONNSTATUS_1			BIT0	//0/R/x/x Current Connect Status
#define USB_20MMIO_PORT_2_STA_CTL		0x5C	//Port 2 Status / Control
    #define USB_20MMIO_WKOC_E_2			BIT22	//0/x/x/x Wake on Over-current Enable
    #define USB_20MMIO_WKDSCNNT_E_2			BIT21	//0/x/x/x Wake on Disconnect Enable
    #define USB_20MMIO_WKCNNT_E_2			BIT20	//0/x/x/x Wake on Connect Enable
    #define USB_20MMIO_PTSTCTRL_2			0xF0000	//0/x/x/x Port Test Control
    #define USB_20MMIO_POWNER_2			BIT13	//1b/x/x/x Port Owner
    #define USB_20MMIO_PP_2			BIT12	//1b/R/x/x Port Power
    #define USB_20MMIO_LINESTATUS_SYN_2			(BIT10 + BIT11)	//0/R/x/x Line Status
    #define USB_20MMIO_SPORTRST_SYN_2			BIT8	//0/x/x/x Port Reset
    #define USB_20MMIO_SSUSPEND_NRM_2			BIT7	//0/0/x/x Suspend
    #define USB_20MMIO_SRESUME_NRM_2			BIT6	//0/x/x/x Force Port Resume
    #define USB_20MMIO_OVERCURR_CHG_2			BIT5	//0/0/x/x Over-current Change
    #define USB_20MMIO_OVERCURR_2			BIT4	//0/R/x/x Over-current Active
    #define USB_20MMIO_PORTENDIS_CHG_2			BIT3	//0/0/x/x Port Enable / Disable Change
    #define USB_20MMIO_SPORTENDIS_2			BIT2	//0/0/x/x Port Enabled / Disabled
    #define USB_20MMIO_CONNSTATUS_CHG_2			BIT1	//0/x/x/x Connect Status Change
    #define USB_20MMIO_CONNSTATUS_2			BIT0	//0/R/x/x Current Connect Status
#define USB_20MMIO_PORT_3_STA_CTL		0x60	//Port 3 Status / Control
    #define USB_20MMIO_WKOC_E_3			BIT22	//0/x/x/x Wake on Over-current Enable
    #define USB_20MMIO_WKDSCNNT_E_3			BIT21	//0/x/x/x Wake on Disconnect Enable
    #define USB_20MMIO_WKCNNT_E_3			BIT20	//0/x/x/x Wake on Connect Enable
    #define USB_20MMIO_PTSTCTRL_3			0xF0000	//0/x/x/x Port Test Control
    #define USB_20MMIO_POWNER_3			BIT13	//1b/x/x/x Port Owner
    #define USB_20MMIO_PP_3			BIT12	//1b/R/x/x Port Power
    #define USB_20MMIO_LINESTATUS_SYN_3			(BIT10 + BIT11)	//0/R/x/x Line Status
    #define USB_20MMIO_SPORTRST_SYN_3			BIT8	//0/x/x/x Port Reset
    #define USB_20MMIO_SSUSPEND_NRM_3			BIT7	//0/0/x/x Suspend
    #define USB_20MMIO_SRESUME_NRM_3			BIT6	//0/x/x/x Force Port Resume
    #define USB_20MMIO_OVERCURR_CHG_3			BIT5	//0/x/x/x Over-current Change
    #define USB_20MMIO_OVERCURR_3			BIT4	//0/R/x/x Over-current Active
    #define USB_20MMIO_PORTENDIS_CHG_3			BIT3	//0/x/x/x Port Enable / Disable Change
    #define USB_20MMIO_SPORTENDIS_3			BIT2	//0/0/x/x Port Enabled / Disabled
    #define USB_20MMIO_CONNSTATUS_CHG_3			BIT1	//0/x/x/x Connect Status Change
    #define USB_20MMIO_CONNSTATUS_3			BIT0	//0/R/x/x Current Connect Status
#define USB_20MMIO_DEBUG_PORT_CTL_STA		0xA0	//Debug Port Control / Status
    #define USB_20MMIO_DBG_OWNER			BIT30	//0/0/x/x Force the Ownership of the Debug Port to the EHCI Controller (Owner)
    #define USB_20MMIO_DBG_ENABLE			BIT28	//0/x/x/x Enable Debug Port (Enabled)
    #define USB_20MMIO_DBG_DONE			BIT16	//0/x/x/x Transaction Request Complete (Done)
    #define USB_20MMIO_DBG_INUSE			BIT10	//0/x/x/x Port In Use (In Use)
    #define USB_20MMIO_DBG_EXCEPTION			(BIT7 + BIT8 + BIT9)	//000b/R/x/x Exception Error Type (Exception)
    #define USB_20MMIO_DBG_ERRGD			BIT6	//0/R/x/x Error Status (Error / Good#)
    #define USB_20MMIO_DBG_GO			BIT5	//0/x/x/x Start a Request (Go)
    #define USB_20MMIO_DBG_WR			BIT4	//0/x/x/x Current Request Type (Write / Read#)
    #define USB_20MMIO_DBG_LENGTH			0xF	//0/x/x/x Data Length
#define USB_20MMIO_DEBUG_PORT_USB_PIDS_PACKET_IDENTIFIER		0xA4	//Debug Port USB PIDs (Packet Identifier)
    #define USB_20MMIO_DBG_RCVPID			0xFF0000	//0/R/x/x Received PID
    #define USB_20MMIO_DBG_TXPID			0xFF00	//0/x/x/x Send PID
    #define USB_20MMIO_DBG_TOKEN			0xFF	//0/x/x/x Token PID
#define USB_20MMIO_DEBUG_PORT_DATA_BUFFER		0xA8	//Debug Port Data Buffer
    #define USB_20MMIO_DBGPORT_BUF			0xFFFFFFFFFFFFFFFF	//FFFFFFFFFFFFFFFFh/x/x/x Debug Port Data Buffer
#define USB_20MMIO_DEBUG_PORT_DEV_ADR		0xB0	//Debug Port Device Address
    #define USB_20MMIO_DBG_ADDR			0x7F00	//7Fh/x/x/x USB Address
    #define USB_20MMIO_DBG_ENDP			0xF	//1h/x/x/x USB Endpoint
//OPTCFG_PHY
#define OPTCFGPHY_PHY_DPLL_CTL_1		0x00000	//PHY DPLL Control 1
    #define OPTCFGPHY_INDLY_1_0			(BIT6 + BIT7)	//00b/00b/x/x DPLL Non-Squelch (NSQ) Offset Setting
    #define OPTCFGPHY_DPLL_BISTOK_U3			BIT5	//0/R/x/x DPLL BIST Pattern Matching Flag From U3 EPHY
    #define OPTCFGPHY_DPLL_BISTOK			BIT4	//0/R/x/x DPLL BIST Pattern Matching Flag
    #define OPTCFGPHY_DPLL_BISTRST			BIT3	//0/0/x/x Reset DPLL for BIST
    #define OPTCFGPHY_DPLL_BISTS2			BIT2	//0/0/x/x DPLL BIST Setting for Different Test Pattern 2
    #define OPTCFGPHY_DPLL_BISTS1			BIT1	//0/0/x/x DPLL BIST Setting for Different Test Pattern 1
    #define OPTCFGPHY_DPLL_BISTS0			BIT0	//0/0/x/x DPLL BIST Setting for Different Test Pattern 0
#define OPTCFGPHY_PHY_DPLL_CTL_2		0x00001	//PHY DPLL Control 2
    #define OPTCFGPHY_FASTSTART			BIT7	//0/0/0/x DPLL Zero Phase Start Select
    #define OPTCFGPHY_RDOUT_ENB			BIT6	//0/0/x/x Reserved
    #define OPTCFGPHY_LBACK_ENB			BIT5	//0/0/x/x Reserved
    #define OPTCFGPHY_FASTLOCK			BIT4	//1b/1/x/x DPLL Fast Lock Enable
    #define OPTCFGPHY_TRKSPD_1_0			(BIT2 + BIT3)	//00b/00b/x/x DPLL Track Speed Select
    #define OPTCFGPHY_LOCKSPD_1_0			(BIT0 + BIT1)	//00b/00b/x/x DPLL Lock Speed Select
#define OPTCFGPHY_PHY_RXH_CTL		0x00002	//PHY RXH Control
    #define OPTCFGPHY_PHY_LPM_7_3			0xF8	//0/x/x/x Reserved
    #define OPTCFGPHY_HSTXACT_LPM			BIT2	//0/0/x/x High Speed Transmitting Clock (PISO Clock) Gated Control (for LPM) 
    #define OPTCFGPHY_INDATADLY_LPM_1_0			(BIT0 + BIT1)	//0/0/x/x DPLL Input Data Delay Select  (for LPM)
#define OPTCFGPHY_PHY_APLL_CTL		0x00003	//PHY APLL Control
    #define OPTCFGPHY_PHY_APLL_7_1			0xFE	//0/x/x/x Reserved
    #define OPTCFGPHY_TMODE			BIT0	//1b/1/x/x Disable PHY Receiver Including Squelch Detector Power up Time Improvement 
#define OPTCFGPHY_PHY_BG_CTL		0x00004	//PHY BG Control
    #define OPTCFGPHY_PHY_BG_7_2			0xFC	//0/x/x/x Reserved
    #define OPTCFGPHY_ITRIM_2_1			(BIT0 + BIT1)	//0/0/x/x Internal Current Source Increment ((R_Isource))
#define OPTCFGPHY_PHY_DPLL_LPM_1		0x00005	//PHY DPLL LPM 1
    #define OPTCFGPHY_INDLY1_LPM			(BIT6 + BIT7)	//00b/00b/x/x DPLL Non-Squelch (NSQ) Offset Setting (for LPM)
    #define OPTCFGPHY_DPLL_BISTOK_U3_LPM			BIT5	//0/R/x/x DPLL BIST Pattern Matching Flag From U3 EPHY (for LPM)
    #define OPTCFGPHY_DPLL_BISTOK_LPM			BIT4	//0/R/x/x DPLL BIST Pattern Matching Flag (for LPM)
    #define OPTCFGPHY_DPLL_BISTRST_LPM			BIT3	//0/0/x/x Reset DPLL for BIST (for LPM)
    #define OPTCFGPHY_DPLL_BIST2_LPM			BIT2	//0/0/x/x DPLL BIST Setting for Different Test Pattern 2 (for LPM)
    #define OPTCFGPHY_DPLL_BIST1_LPM			BIT1	//0/0/x/x DPLL BIST Setting for Different Test Pattern 1 (for LPM)
    #define OPTCFGPHY_DPLL_BIST0_LPM			BIT0	//0/0/x/x DPLL BIST Setting for Different Test Pattern 0 (for LPM)
#define OPTCFGPHY_PHY_DPLL_LPM_2		0x00006	//PHY DPLL LPM 2
    #define OPTCFGPHY_FASTSTART_LPM			BIT7	//0/0/0/x DPLL Zero Phase Start Select (for LPM)
    #define OPTCFGPHY_RDOUT_ENB_LPM			BIT6	//0/0/x/x Reserved  (For LPM)
    #define OPTCFGPHY_LBACK_ENB_LPM			BIT5	//0/0/x/x Reserved
    #define OPTCFGPHY_FASTLOCK_LPM			BIT4	//1b/1/x/x DPLL Fast Lock Enable (for LPM)
    #define OPTCFGPHY_TRKSPD_LPM_1_0			(BIT2 + BIT3)	//01b/01b/x/x DPLL Track Speed Select (for LPM)
    #define OPTCFGPHY_LOCKSPD_LPM_1_0			(BIT0 + BIT1)	//11b/11b/x/x DPLL Lock Speed Select (for LPM)
#define OPTCFGPHY_PHY_LPM_CTL		0x00007	//PHY LPM Control
    #define OPTCFGPHY_PHY_LPM_CTL_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_LPM_PORT_SEL_SUS_1_0			(BIT5 + BIT6)	//0/0/x/x Select Which Port to Act LPM Function for USB2 EPHY
    #define OPTCFGPHY_LPM_PORT_EN_SUS			BIT4	//0/0/x/x Enable LPM Function for USB32 EPHY
    #define OPTCFGPHY_LPM_PORT_SEL_CORE_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Select Which Port to Act LPM Function for USB2 EPHY
    #define OPTCFGPHY_LPM_PORT_EN_CORE			BIT0	//0/0/x/x Enable LPM Function for USB2 EPHY
#define OPTCFGPHY_PHY_APLL_CTL_1		0x00008	//PHY APLL Control 1
    #define OPTCFGPHY_PHY_APLL_CTL_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_REFDLY_SEL_APLL			(BIT4 + BIT5 + BIT6)	//0/0/x/x EPHY REFDLY_SEL_APLL Control
    #define OPTCFGPHY_ICPSEL_APLL			0xF	//0/0/x/x EPHY ICPSEL_APLL Control
#define OPTCFGPHY_PHY_APLL_CTL_2		0x00009	//PHY APLL Control 2
    #define OPTCFGPHY_PHY_APLL_CTL2_7_3			0xF8	//0/x/x/x Reserved
    #define OPTCFGPHY_FBDLY_SEL_APLL			(BIT0 + BIT1 + BIT2)	//0/0/x/x EPHY FBDLY_SEL_APLL Control
#define OPTCFGPHY_PHY_APLL_CTL_3		0x0000A	//PHY APLL Control 3
    #define OPTCFGPHY_DIV_M_APLL			0xFF	//4Eh/x/x/x EPHY DIV_M_APLL Control
#define OPTCFGPHY_PHY_APLL_CTL_4		0x0000B	//PHY APLL Control 4
    #define OPTCFGPHY_FVCO_TUNE_TC_APLL			0xF0	//0/0/x/x Reserved
    #define OPTCFGPHY_FVCO_TUNE_ABS_APLL			0xF	//0/0/x/x EPHY FVCO_TUNE_ABS_APLL Control
#define OPTCFGPHY_PHY_TEST_CTL		0x0000C	//PHY Test Control
    #define OPTCFGPHY_U2PHY_TEST			0xFFFFFFFF	//0/0/x/x EPHY PHYTEST Control
#define OPTCFGPHY_PHY_APLL_CTL_5		0x00010	//PHY APLL Control 5
    #define OPTCFGPHY_PHY_APLL_CTL5_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define OPTCFGPHY_IPTATUNE			(BIT3 + BIT4 + BIT5)	//0/0/x/x Reserved
    #define OPTCFGPHY_BG_TRIM			(BIT0 + BIT1 + BIT2)	//0/0/x/x EPHY BG_TRIM Control
#define OPTCFGPHY_PHY_APLL_CTL_6		0x00011	//PHY APLL Control 6
    #define OPTCFGPHY_PHY_APLL_CTL6_7_5			0xF8	//0/x/x/x Reserved
    #define OPTCFGPHY_IPTUNE			(BIT0 + BIT1 + BIT2)	//0/0/x/x EPHY IPTUNE Control
#define OPTCFGPHY_PHY_PORT_1_TXH_CTL		0x01000	//PHY Port 1 TXH Control
    #define OPTCFGPHY_TXHSRCTRL_A			(BIT5 + BIT6 + BIT7)	//100b/100b/x/x High Speed Driver Slew Rate Control
    #define OPTCFGPHY_TEST_HTX_A			BIT4	//0/0/x/x High Speed TX Test Mode Register
    #define OPTCFGPHY_CTRL_A_3_0			0xF	//1000b/*1000b/x/x Control bits for HS termination resistor fine tune
#define OPTCFGPHY_PHY_PORT_1_RXH_CTL		0x01001	//PHY Port 1 RXH Control
    #define OPTCFGPHY_PHY_PORT_RXH_A_7_4			0xF0	//0/x/x/x Reserved
    #define OPTCFGPHY_SQSET_A_1_0			(BIT2 + BIT3)	//10b/10b/x/x Squelch Detector Fine Tune
    #define OPTCFGPHY_DISCNT_A_1_0			(BIT0 + BIT1)	//10b/10b/x/x Disconnection Level Fine Tune 每 for Port 1
#define OPTCFGPHY_PHY_PORT_1_XCVR11_CTL_1		0x01002	//PHY Port 1 XCVR11 Control 1
    #define OPTCFGPHY_TEST_FLRX_A			BIT0	//0/R/x/x USB Port 1 RX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_1_XCVR11_CTL_2		0x01003	//PHY Port 1 XCVR11 Control 2
    #define OPTCFGPHY_TXFSRCTRL_A			(BIT5 + BIT6 + BIT7)	//011b/011b/x/x Full Speed Driver Slew Rate Control
    #define OPTCFGPHY_TXLSRCTRL_A			(BIT2 + BIT3 + BIT4)	//011b/011b/x/x Low Speed Driver Slew Rate Control
    #define OPTCFGPHY_PULLDOWNR_ON_A			BIT1	//1b/1/x/x Enable Pull-down 15K Resistor
    #define OPTCFGPHY_TEST_FLTX_A			BIT0	//0/0/x/x USB Port 1 TX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_1_SIGNALS_MONITORING_REG_1		0x01004	//PHY Port 1 Signals Monitoring Register 1
    #define OPTCFGPHY_PHYMON_EN_A			BIT0	//0/0/x/x Enable Port 1 PHY Signals Monitoring
#define OPTCFGPHY_PHY_PORT_1_SIGNALS_MONITORING_REG_2		0x01005	//PHY Port 1 Signals Monitoring Register 2
    #define OPTCFGPHY_RXDATA_A			BIT3	//0/R/x/x PHY Port 1 Signals Monitoring
    #define OPTCFGPHY_SQUELCH_A			BIT2	//0/R/x/x PHY Port 1 Signals Monitoring
    #define OPTCFGPHY_DISCONNECT_A			BIT1	//0/R/x/x PHY Port 1 Signals Monitoring
    #define OPTCFGPHY_TERMON_A			BIT0	//0/R/x/x PHY Port 1 Signals Monitoring
#define OPTCFGPHY_PHY_PORT_1_SIGNALS_MONITORING_REG_3		0x01006	//PHY Port 1 Signals Monitoring Register 3
    #define OPTCFGPHY_PHY_PORT_TXH_LPM_A_7_1			0xFE	//0/x/x/x Reserved
    #define OPTCFGPHY_TEST_HTX_LPM_A			BIT0	//0/0/x/x HS TX Test Mode Register
#define OPTCFGPHY_PHY_PORT_1_CTL_1		0x01008	//PHY Port 1 Control 1
    #define OPTCFGPHY_PHY_PORT1_CTL1_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_FS_UP_EN_1			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 1 FS_UP_EN Control
    #define OPTCFGPHY_FS_DN_EN_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x For port A high speed TRX use:
    #define OPTCFGPHY_FS_AUXB_1			BIT0	//0/0/x/x Port 1 FS_AUXB Control
#define OPTCFGPHY_PHY_PORT_1_CTL_2		0x01009	//PHY Port 1 Control 2
    #define OPTCFGPHY_FS_IDN_SEL_1			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_IUP_SEL_1			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_RESL_DN_1			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_1_CTL_3		0x0100A	//PHY Port 1 Control 3
    #define OPTCFGPHY_FS_RESL_UP_1			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_FS_VMID_TRIM_1			0x3C	//0111b/0111b/x/x Port 1 FS_VMID_TRIM Control
    #define OPTCFGPHY_TXFSR_MODE_1			(BIT0 + BIT1)	//01b/01b/x/x Port 1 TXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_1_CTL_4		0x0100C	//PHY Port 1 Control 4
    #define OPTCFGPHY_PHY_PORT1_CTL4_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_LS_UP_EN_1			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 1 LS_UP_EN Control
    #define OPTCFGPHY_LS_DN_EN_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_AUXB_1			BIT0	//0/0/x/x Port 1 LS_AUXB Control
#define OPTCFGPHY_PHY_PORT_1_CTL_5		0x0100D	//PHY Port 1 Control 5
    #define OPTCFGPHY_LS_IDN_SEL_1			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_IUP_SEL_1			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_RESL_DN_1			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_1_CTL_6		0x0100E	//PHY Port 1 Control 6
    #define OPTCFGPHY_LS_RESL_UP_1			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_LS_VMID_TRIM_1			0x3C	//0111b/0111b/x/x Port 1 LS_VMID_TRIM Control
    #define OPTCFGPHY_LXFSR_MODE_1			(BIT0 + BIT1)	//01b/01b/x/x Port 1 LXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_2_TXH_CTL		0x02000	//PHY Port 2 TXH Control
    #define OPTCFGPHY_TXHSRCTRL_B			(BIT5 + BIT6 + BIT7)	//100b/100b/x/x High Speed Driver Slew Rate Control
    #define OPTCFGPHY_TEST_HTX_B			BIT4	//0/0/x/x High Speed TX Test Mode Register
    #define OPTCFGPHY_CTRL_B_3_0			0xF	//1000b/1000b/x/x Control bits for HS termination resistor fine tune
#define OPTCFGPHY_PHY_PORT_2_RXH_CTL		0x02001	//PHY Port 2 RXH Control
    #define OPTCFGPHY_PHY_PORT_RXH_B_7_4			0xF0	//0/x/x/x Reserved
    #define OPTCFGPHY_SQSET_B_1_0			(BIT2 + BIT3)	//10b/10b/x/x Squelch Detector Fine Tune
    #define OPTCFGPHY_DISCNT_B_1_0			(BIT0 + BIT1)	//10b/10b/x/x Disconnection Level Fine Tune 每 for Port 2
#define OPTCFGPHY_PHY_PORT_2_XCVR11_CTL_1		0x02002	//PHY Port 2 XCVR11 Control 1
    #define OPTCFGPHY_TEST_FLRX_B			BIT0	//0/R/x/x USB Port 2 RX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_2_XCVR11_CTL_2		0x02003	//PHY Port 2 XCVR11 Control 2
    #define OPTCFGPHY_TXFSRCTRL_B			(BIT5 + BIT6 + BIT7)	//011b/011b/x/x Full Speed Driver Slew Rate Control
    #define OPTCFGPHY_TXLSRCTRL_B			(BIT2 + BIT3 + BIT4)	//011b/011b/x/x Low Speed Driver Slew Rate Control
    #define OPTCFGPHY_PULLDOWNR_ON_B			BIT1	//1b/1/x/x Enable Pull-down 15K Resistor
    #define OPTCFGPHY_TEST_FLTX_B			BIT0	//0/0/x/x USB Port 2 TX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_2_SIGNALS_MONITORING_REG_1		0x02004	//PHY Port 2 Signals Monitoring Register 1
    #define OPTCFGPHY_PHYMON_EN_B			BIT0	//0/0/x/x Enable Port 2 PHY Signals Monitoring
#define OPTCFGPHY_PHY_PORT_2_SIGNALS_MONITORING_REG_2		0x02005	//PHY Port 2 Signals Monitoring Register 2
    #define OPTCFGPHY_RXDATA_B			BIT3	//0/R/x/x PHY Port 2 Signals Monitoring
    #define OPTCFGPHY_SQUELCH_B			BIT2	//0/R/x/x PHY Port 2 Signals Monitoring
    #define OPTCFGPHY_DISCONNECT_B			BIT1	//0/R/x/x PHY Port 2 Signals Monitoring
    #define OPTCFGPHY_TERMON_B			BIT0	//0/R/x/x PHY Port 2 Signals Monitoring
#define OPTCFGPHY_PHY_PORT_2_SIGNALS_MONITORING_REG_3		0x02006	//PHY Port 2 Signals Monitoring Register 3
    #define OPTCFGPHY_PHY_PORT_TXH_LPM_B_7_1			0xFE	//0/x/x/x Reserved
    #define OPTCFGPHY_TEST_HTX_LPM_B			BIT0	//0/0/x/x HS TX Test Mode Register
#define OPTCFGPHY_PHY_PORT_2_CTL_1		0x02008	//PHY Port 2 Control 1
    #define OPTCFGPHY_PHY_PORT2_CTL1_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_FS_UP_EN_2			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 2 FS_UP_EN Control
    #define OPTCFGPHY_FS_DN_EN_2			(BIT1 + BIT2 + BIT3)	//0/x/x/x For port B high speed TRX use:
    #define OPTCFGPHY_FS_AUXB_2			BIT0	//0/0/x/x Port 2 FS_AUXB Control
#define OPTCFGPHY_PHY_PORT_2_CTL_2		0x02009	//PHY Port 2 Control 2
    #define OPTCFGPHY_FS_IDN_SEL_2			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_IUP_SEL_2			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_RESL_DN_2			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_2_CTL_3		0x0200A	//PHY Port 2 Control 3
    #define OPTCFGPHY_FS_RESL_UP_2			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_VMID_TRIM_2			0x3C	//0111b/0111b/x/x Port 2 FS_VMID_TRIM Control
    #define OPTCFGPHY_TXFSR_MODE_2			(BIT0 + BIT1)	//01b/01b/x/x Port 2 TXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_2_CTL_4		0x0200C	//PHY Port 2 Control 4
    #define OPTCFGPHY_PHY_PORT2_CTL4_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_LS_UP_EN_2			(BIT4 + BIT5 + BIT6)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_DN_EN_2			(BIT1 + BIT2 + BIT3)	//0/0/x/x For port B high speed TRX use:
    #define OPTCFGPHY_LS_AUXB_2			BIT0	//0/0/x/x Port 2 LS_AUXB Control
#define OPTCFGPHY_PHY_PORT_2_CTL_5		0x0200D	//PHY Port 2 Control 5
    #define OPTCFGPHY_LS_IDN_SEL_2			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_IUP_SEL_2			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_RESL_DN_2			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_2_CTL_6		0x0200E	//PHY Port 2 Control 6
    #define OPTCFGPHY_LS_RESL_UP_2			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_LS_VMID_TRIM_2			0x3C	//0111b/0111b/x/x Port 2 LS_VMID_TRIM Control
    #define OPTCFGPHY_LXFSR_MODE_2			(BIT0 + BIT1)	//01b/01b/x/x Port 2 LXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_3_TXH_CTL		0x03000	//PHY Port 3 TXH Control
    #define OPTCFGPHY_TXHSRCTRL_C			(BIT5 + BIT6 + BIT7)	//100b/100b/x/x High Speed Driver Slew Rate Control
    #define OPTCFGPHY_TEST_HTX_C			BIT4	//0/0/x/x High Speed TX Test Mode Register 
    #define OPTCFGPHY_CTRL_C_3_0			0xF	//1000b/1000b/x/x Control bits for HS termination resistor fine tune
#define OPTCFGPHY_PHY_PORT_3_RXH_CTL		0x03001	//PHY Port 3 RXH Control
    #define OPTCFGPHY_PHY_PORT_RXH_C_7_4			0xF0	//0/x/x/X Reserved
    #define OPTCFGPHY_SQSET_C_1_0			(BIT2 + BIT3)	//10b/10b/x/x Squelch Detector Fine Tune
    #define OPTCFGPHY_DISCNT_C_1_0			(BIT0 + BIT1)	//10b/10b/x/x Disconnection Level Fine Tune 每 for Port 3
#define OPTCFGPHY_PHY_PORT_3_XCVR11_CTL_1		0x03002	//PHY Port 3 XCVR11 Control 1
    #define OPTCFGPHY_TEST_FLRX_C			BIT0	//0/R/x/x USB Port 3 RX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_3_XCVR11_CTL_2		0x03003	//PHY Port 3 XCVR11 Control 2
    #define OPTCFGPHY_TXFSRCTRL_C			(BIT5 + BIT6 + BIT7)	//011b/011b/x/x Full Speed Driver Slew Rate Control
    #define OPTCFGPHY_TXLSRCTRL_C			(BIT2 + BIT3 + BIT4)	//011b/011b/x/x Low Speed Driver Slew Rate Control
    #define OPTCFGPHY_PULLDOWNR_ON_C			BIT1	//1b/1/x/x Enable Pull-down 15K Resistor
    #define OPTCFGPHY_TEST_FLTX_C			BIT0	//0/0/x/x USB Port 3 TX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_3_SIGNALS_MONITORING_REG_1		0x03004	//PHY Port 3 Signals Monitoring Register 1
    #define OPTCFGPHY_PHYMON_EN_C			BIT0	//0/0/x/x Enable Port 3 PHY Signals Monitoring
#define OPTCFGPHY_PHY_PORT_3_SIGNALS_MONITORING_REG_2		0x03005	//PHY Port 3 Signals Monitoring Register 2
    #define OPTCFGPHY_RXDATA_C			BIT3	//0/R/x/x PHY Port 3 Signals Monitoring
    #define OPTCFGPHY_SQUELCH_C			BIT2	//0/R/x/x PHY Port 3 Signals Monitoring
    #define OPTCFGPHY_DISCONNECT_C			BIT1	//0/R/x/x PHY Port 3 Signals Monitoring
    #define OPTCFGPHY_TERMON_C			BIT0	//0/R/x/x PHY Port 3 Signals Monitoring
#define OPTCFGPHY_PHY_PORT_1_SIGNALS_MONITORING_REG_3_Z1		0x03006	//PHY Port 1 Signals Monitoring Register 3
    #define OPTCFGPHY_PHY_PORT_TXH_LPM_C_7_1			0xFE	//0/x/x/x Reserved
    #define OPTCFGPHY_TEST_HTX_LPM_C			BIT0	//0/0/x/x HS TX Test Mode Register 
#define OPTCFGPHY_PHY_PORT_3_CTL_1		0x03008	//PHY Port 3 Control 1
    #define OPTCFGPHY_PHY_PORT3_CTL1_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_FS_UP_EN			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 3 FS_UP_EN Control
    #define OPTCFGPHY_FS_DN_EN			(BIT1 + BIT2 + BIT3)	//0/0/x/x For port C high speed TRX use:
    #define OPTCFGPHY_FS_AUXB			BIT0	//0/0/x/x Port 3 FS_AUXB Control
#define OPTCFGPHY_PHY_PORT_3_CTL_2		0x03009	//PHY Port 3 Control 2
    #define OPTCFGPHY_FS_IDN_SEL_3			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_IUP_SEL_3			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_RESL_DN_3			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_3_CTL_3		0x0300A	//PHY Port 3 Control 3
    #define OPTCFGPHY_FS_RESL_UP_3			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_FS_VMID_TRIM_3			0x3C	//0111b/0111b/x/x Port 3 FS_VMID_TRIM Control
    #define OPTCFGPHY_TXFSR_MODE_3			(BIT0 + BIT1)	//01b/01b/x/x Port 3 TXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_3_CTL_4		0x0300C	//PHY Port 3 Control 4
    #define OPTCFGPHY_PHY_PORT3_CTL4_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_LS_UP_EN_3			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 3 LS_UP_EN Control
    #define OPTCFGPHY_LS_DN_EN_3			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_AUXB_3			BIT0	//0/0/x/x Port 3 LS_AUXB Control
#define OPTCFGPHY_PHY_PORT_3_CTL_5		0x0300D	//PHY Port 3 Control 5
    #define OPTCFGPHY_LS_IDN_SEL_3			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_IUP_SEL_3			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_RESL_DN_3			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_3_CTL_6		0x0300E	//PHY Port 3 Control 6
    #define OPTCFGPHY_LS_RESL_UP_3			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_LS_VMID_TRIM_3			0x3C	//0111b/0111b/x/x Port 3 LS_VMID_TRIM Control
    #define OPTCFGPHY_LXFSR_MODE_3			(BIT0 + BIT1)	//01b/01b/x/x Port 3 LXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_4_TXH_CTL		0x04000	//PHY Port 4 TXH Control
    #define OPTCFGPHY_TXHSRCTRL_D			(BIT5 + BIT6 + BIT7)	//100b/100b/x/x High Speed Driver Slew Rate Control
    #define OPTCFGPHY_TEST_HTX_D			BIT4	//0/0/x/x High Speed TX Test Mode Register 
    #define OPTCFGPHY_CTRL_D_3_0			0xF	//1000b/*1000b/x/x Control bits for HS termination resistor fine tune
#define OPTCFGPHY_PHY_PORT_4_RXH_CTL		0x04001	//PHY Port 4 RXH Control
    #define OPTCFGPHY_PHY_PORT_RXH_D_7_4			0xF0	//0/x/x/x Reserved
    #define OPTCFGPHY_SQSET_D_1_0			(BIT2 + BIT3)	//10b/10b/x/x Squelch Detector Fine Tune
    #define OPTCFGPHY_DISCNT_D_1_0			(BIT0 + BIT1)	//10b/10b/x/x Disconnection Level Fine Tune 每 For Port 4
#define OPTCFGPHY_PHY_PORT_4_XCVR11_CTL_1		0x04002	//PHY Port 4 XCVR11 Control 1
    #define OPTCFGPHY_TEST_FLRX_D			BIT0	//0/R/x/x USB Port 4 RX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_4_XCVR11_CTL_2		0x04003	//PHY Port 4 XCVR11 Control 2
    #define OPTCFGPHY_TXFSRCTRL_D			(BIT5 + BIT6 + BIT7)	//011b/011b/x/x Full Speed Driver Slew Rate Control
    #define OPTCFGPHY_TXLSRCTRL_D			(BIT2 + BIT3 + BIT4)	//011b/011b/x/x Low Speed Driver Slew Rate Control
    #define OPTCFGPHY_PULLDOWNR_ON_D			BIT1	//1b/1/x/x Enable Pull-down 15K Resistor
    #define OPTCFGPHY_TEST_FLTX_D			BIT0	//0/0/x/x USB Port 4 TX Data for Test Mode
#define OPTCFGPHY_PHY_PORT_4_SIGNALS_MONITORING_REG_1		0x04004	//PHY Port 4 Signals Monitoring Register 1
    #define OPTCFGPHY_PHYMON_EN_D			BIT0	//0/0/x/x Enable Port 4 PHY Signals Monitoring
#define OPTCFGPHY_PHY_PORT_4_SIGNALS_MONITORING_REG_2		0x04005	//PHY Port 4 Signals Monitoring Register 2
    #define OPTCFGPHY_RXDATA_D			BIT3	//0/R/x/x PHY Port 4 Signals Monitoring
    #define OPTCFGPHY_SQUELCH_D			BIT2	//0/R/x/x PHY Port 4 Signals Monitoring
    #define OPTCFGPHY_DISCONNECT_D			BIT1	//0/R/x/x PHY Port 4 Signals Monitoring
    #define OPTCFGPHY_TERMON_D			BIT0	//0/R/x/x PHY Port 4 Signals Monitoring
#define OPTCFGPHY_PHY_PORT_1_SIGNALS_MONITORING_REG_3_Z2		0x04006	//PHY Port 1 Signals Monitoring Register 3
    #define OPTCFGPHY_PHY_PORT_TXH_LPM_D_7_1			0xFE	//0/x/x/x Reserved
    #define OPTCFGPHY_TEST_HTX_LPM_D			BIT0	//0/0/x/x HS TX Test Mode Register
#define OPTCFGPHY_PHY_PORT_4_CTL_1		0x04008	//PHY Port 4 Control 1
    #define OPTCFGPHY_PHY_PORT4_CTL1_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_FS_UP_EN_4			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 4 FS_UP_EN Control
    #define OPTCFGPHY_FS_DN_EN_4			(BIT1 + BIT2 + BIT3)	//0/0/x/x For port D high speed TRX use:
    #define OPTCFGPHY_FS_AUXB_4			BIT0	//0/0/x/x Port 4 FS_AUXB Control
#define OPTCFGPHY_PHY_PORT_4_CTL_2		0x04009	//PHY Port 4 Control 2
    #define OPTCFGPHY_FS_IDN_SEL_4			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_IUP_SEL_4			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_FS_RESL_DN_4			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_4_CTL_3		0x0400A	//PHY Port 4 Control 3
    #define OPTCFGPHY_FS_RESL_UP_4			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_FS_VMID_TRIM_4			0x3C	//0111b/0111b/x/x Port 4 FS_VMID_TRIM Control
    #define OPTCFGPHY_TXFSR_MODE_4			(BIT0 + BIT1)	//01b/01b/x/x Port 4 TXFSR_MODE Control
#define OPTCFGPHY_PHY_PORT_4_CTL_4		0x0400C	//PHY Port 4 Control 4
    #define OPTCFGPHY_PHY_PORT4_CTL4_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_LS_UP_EN_4			(BIT4 + BIT5 + BIT6)	//0/0/x/x Port 4 LS_UP_EN Control
    #define OPTCFGPHY_LS_DN_EN_4			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_AUXB_4			BIT0	//0/0/x/x Port 4 LS_AUXB Control
#define OPTCFGPHY_PHY_PORT_4_CTL_5		0x0400D	//PHY Port 4 Control 5
    #define OPTCFGPHY_LS_IDN_SEL_4			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_IUP_SEL_4			(BIT2 + BIT3 + BIT4)	//0/0/x/x Reserved
    #define OPTCFGPHY_LS_RESL_DN_4			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGPHY_PHY_PORT_4_CTL_6		0x0400E	//PHY Port 4 Control 6
    #define OPTCFGPHY_LS_RESL_UP_4			(BIT6 + BIT7)	//00b/00b/x/x Reserved
    #define OPTCFGPHY_LS_VMID_TRIM_4			0x3C	//0111b/0111b/x/x Port 4 LS_VMID_TRIM Control
    #define OPTCFGPHY_LXFSR_MODE_4			(BIT0 + BIT1)	//01b/01b/x/x Port 4 LXFSR_MODE Control
#define OPTCFGPHY_PHY_TEST_CTL_1		0x10000	//PHY Test Control 1
    #define OPTCFGPHY_FS_LPBK_TST			BIT7	//0/0/0/x USB2.0 Full Speed Loopback Mode
    #define OPTCFGPHY_HS_LPBK_TST			BIT6	//0/0/x/x USB2.0 High Speed Loopback Mode
    #define OPTCFGPHY_PHY_BIST_EN_TST			BIT5	//0/0/x/x USB2.0/1.1 PHYBIST Enable
    #define OPTCFGPHY_USB2_TEST_RESET_TST			BIT4	//0/0/x/x USB2.0/1.1 PHYBIST and Parameter Test Reset
    #define OPTCFGPHY_LS_SQ_TST			BIT3	//0/0/x/x Enable Transmitter Signal Quality Test in USB2.0 Low Speed Mode
    #define OPTCFGPHY_FS_SQ_TST			BIT2	//0/0/x/x Enable Transmitter Signal Quality Test in USB2.0 Full Speed Mode
    #define OPTCFGPHY_HS_SQ_TST			BIT1	//0/0/x/x Enable Transmitter Signal Quality Test in USB2.0 High Speed Mode
    #define OPTCFGPHY_USB2_TST_MODE_TST			BIT0	//0/0/x/x MUX Select of Test Data and Normal Data0: Normal data1: Test data
#define OPTCFGPHY_PHY_TEST_CTL_2		0x10001	//PHY Test Control 2
    #define OPTCFGPHY_PHY_TEST_2_7			BIT7	//0/x/x/x Reserved
    #define OPTCFGPHY_PDAPLL_TST			BIT6	//0/0/x/x USB2 EPHY Control in Test Mode
    #define OPTCFGPHY_PDSUSMOD_TST			BIT5	//0/0/x/x USB2 EPHY Control in Test Mode
    #define OPTCFGPHY_HSTXACT_TST			BIT4	//0/0/x/x High Speed Receiving Clock Gated Signal for USB2.0 PHY Test Mode
    #define OPTCFGPHY_BIST_PAT_SEL_TST_3_0			0xF	//0/0/x/x Select USB2.0 High Speed Loopback Mode Test Pattern
#define OPTCFGPHY_PHY_TEST_CTL_3		0x10002	//PHY Test Control 3
    #define OPTCFGPHY_OVER_FLOW_TST			BIT1	//0b/R/x/x When USB2.0 High Speed or Full Speed Test Begins
    #define OPTCFGPHY_BIST_FAIL_TST			BIT0	//0b/R/x/x When USB2.0 High Speed or Full Speed Test Begins
#define OPTCFGPHY_PHY_PORT_1_TEST_CTL_1		0x11000	//PHY Port 1 Test Control 1
    #define OPTCFGPHY_TERM_ON_A_TST			BIT7	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_FORCESQUELCH_A_TST			BIT6	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_LF_A_TST			BIT5	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_TXSE_A_TST			BIT4	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_SUSDISABLE_A_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_CHIRPDATA_A_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_CHIRPMODE_A_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_CHIRPENB_A_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
#define OPTCFGPHY_PHY_PORT_1_TEST_CTL_2		0x11001	//PHY Port 1 Test Control 2
    #define OPTCFGPHY_PORT_T_A_TST			BIT5	//0/0/x/x Enable Port 1 TX Data Path
    #define OPTCFGPHY_PORT_X_A_TST			BIT4	//0/0/x/x Enable Port 1 RX Data Path
    #define OPTCFGPHY_PDHSRCV_A_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_PDHSDRV_A_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_PDFSPORT_A_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
    #define OPTCFGPHY_PDHSPORT_A_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 1
#define OPTCFGPHY_PHY_PORT_2_TEST_CTL_1		0x12000	//PHY Port 2 Test Control 1
    #define OPTCFGPHY_TERM_ON_B_TST			BIT7	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_FORCESQUELCH_B_TST			BIT6	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_LF_B_TST			BIT5	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_TXSE_B_TST			BIT4	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_SUSDISABLE_B_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_CHIRPDATA_B_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_CHIRPMODE_B_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_CHIRPENB_B_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
#define OPTCFGPHY_PHY_PORT_2_TEST_CTL_2		0x12001	//PHY Port 2 Test Control 2
    #define OPTCFGPHY_PORT_T_B_TST			BIT5	//0/0/x/x Enable Port 2 TX Data Path
    #define OPTCFGPHY_PORT_X_B_TST			BIT4	//0/0/x/x Enable Port 2 RX Data Path
    #define OPTCFGPHY_PDHSRCV_B_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_PDHSDRV_B_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_PDFSPORT_B_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
    #define OPTCFGPHY_PDHSPORT_B_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 2
#define OPTCFGPHY_PHY_PORT_3_TEST_CTL_1		0x13000	//PHY Port 3 Test Control 1
    #define OPTCFGPHY_TERM_ON_C_TST			BIT7	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_FORCESQUELCH_C_TST			BIT6	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_LF_C_TST			BIT5	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_TXSE_C_TST			BIT4	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_SUSDISABLE_C_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_CHIRPDATA_C_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_CHIRPMODE_C_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_CHIRPENB_C_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
#define OPTCFGPHY_PHY_PORT_3_TEST_CTL_2		0x13001	//PHY Port 3 Test Control 2
    #define OPTCFGPHY_PORT_T_C_TST			BIT5	//0/0/x/x Enable Port 3 TX Data Path
    #define OPTCFGPHY_PORT_X_C_TST			BIT4	//0/0/x/x Enable Port 3 RX Data Path
    #define OPTCFGPHY_PDHSRCV_C_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_PDHSDRV_C_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_PDFSPORT_C_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
    #define OPTCFGPHY_PDHSPORT_C_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 3
#define OPTCFGPHY_PHY_PORT_4_TEST_CTL_1		0x14000	//PHY Port 4 Test Control 1
    #define OPTCFGPHY_TERM_ON_D_TST			BIT7	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_FORCESQUELCH_D_TST			BIT6	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_LF_D_TST			BIT5	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_TXSE_D_TST			BIT4	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_SUSDISABLE_D_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_CHIRPDATA_D_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_CHIRPMODE_D_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_CHIRPENB_D_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
#define OPTCFGPHY_PHY_PORT_4_TEST_CTL_2		0x14001	//PHY Port 4 Test Control 2
    #define OPTCFGPHY_PORT_T_D_TST			BIT5	//0/0/x/x Enable Port 4 TX Data Path
    #define OPTCFGPHY_PORT_X_D_TST			BIT4	//0/0/x/x Enable Port 4 RX Data Path
    #define OPTCFGPHY_PDHSRCV_D_TST			BIT3	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_PDHSDRV_D_TST			BIT2	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_PDFSPORT_D_TST			BIT1	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
    #define OPTCFGPHY_PDHSPORT_D_TST			BIT0	//0/0/x/x USB2 EPHY Control in Test Mode for Port 4
#endif
