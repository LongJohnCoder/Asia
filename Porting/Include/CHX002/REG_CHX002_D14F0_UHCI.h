//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		USB11					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D14F0_USB11_R100(A0).docMOD_USBC.xls
#ifndef _CHX002_D14F0_USB11_H
#define _CHX002_D14F0_USB11_H
//D14F0
#define D14F0_VID		0x00	//Vendor ID
    #define D14F0_VID_Z1			0xFFFF	//1106h/R/x/x Vendor ID
#define D14F0_DID		0x02	//Device ID
    #define D14F0_DEVID			0xFFFF	//3038h/R/x/x Device ID
#define D14F0_PCI_CMD		0x04	//PCI Command
    #define D14F0_INTR_DIS			BIT10	//0/0/x/x Interrupt Control
    #define D14F0_FB2BKENR			BIT9	//0/R/x/x Reserved
    #define D14F0_SERREN			BIT8	//0/R/x/x Reserved
    #define D14F0_RSTEP			BIT7	//0/R/x/x Reserved
    #define D14F0_RPTYERR			BIT6	//0/R/x/x Reserved
    #define D14F0_VGASNP			BIT5	//0/R/x/x Reserved
    #define D14F0_MWRMEN			BIT4	//0/x/x/x Memory Write and Invalidate
    #define D14F0_SPCYL			BIT3	//0/R/x/x Respond To Special Cycle
    #define D14F0_BMASTREN			BIT2	//0/x/x/x Bus Master
    #define D14F0_MMSPACE			BIT1	//0/x/x/x Memory Space Access
    #define D14F0_IOSPACE			BIT0	//0/x/x/x I/O Space Access
#define D14F0_PCI_STA		0x06	//PCI Status
    #define D14F0_TSERRS			BIT14	//0/R/x/x Reserved
    #define D14F0_TMABORTS			BIT13	//0/0/x/x Received Master Abort (Except Special Cycle)
    #define D14F0_TTABORTR			BIT12	//0/0/x/x Received Target Abort
    #define D14F0_STABORT			BIT11	//0/R/x/x Reserved
    #define D14F0_DEVS			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D14F0_PSTATUS_8_4			0x1F0	//01h/R/x/x Fixed at 01h (for PCI PMI)
    #define D14F0_PSTATUS_3			BIT3	//0/0/x/x Interrupt Status
    #define D14F0_PSTATUS_2_0			(BIT0 + BIT1 + BIT2)	//0/R/x/x Fixed at 0 (for PCI PMI)
#define D14F0_REV_ID		0x08	//Revision ID
    #define D14F0_REVID_8			0xFF	//A0h/R/x/x Revision ID
#define D14F0_CLASS_CODE		0x09	//Class Code
    #define D14F0_CLS_COD			0xFFFFFF	//0C0300h/R/x/x Class Code
#define D14F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D14F0_CACHLINE			0xFF	//0/x/x/x Cache Line Size
#define D14F0_LATENCY_TIMER		0x0D	//Latency Timer
    #define D14F0_LAT_TM			0xFF	//0/x/x/x Latency Timer
#define D14F0_HEADER_TYPE		0x0E	//Header Type
    #define D14F0_HDTYPE			0xFF	//80h/R/x/x Header Type
#define D14F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D14F0_BIST			0xFF	//0/R/x/x BIST
#define D14F0_USB_IO_REG_BASE_ADR		0x20	//USB I/O Register Base Address
    #define D14F0_IOBASE_31_6			0xFFFF0000	//0/0/x/x Reserved
    #define D14F0_IOBASE_15_5			0xFFE0	//7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define D14F0_IOBASE_4_0			0x1F	//01h/R/x/x 32-Byte Aligned IO Space
#define D14F0_SVID		0x2C	//Subsystem Vendor ID
    #define D14F0_SUBVID			0xFFFF	//1106h/1106h/x/x Subsystem Vendor ID
#define D14F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D14F0_SUBSID			0xFFFF	//3038h/3038h/x/x Subsystem ID
#define D14F0_CAP_POINTER		0x34	//Capability Pointer
    #define D14F0_CAP_PTR			0xFF	//80h/R/x/x Capability Pointer
#define D14F0_INTR_LINE		0x3C	//Interrupt Line
    #define D14F0_INTLN_7_4			0xF0	//0/0/x/x Reserved
    #define D14F0_INTLN_3_0			0xF	//0000b/x/x/x USB Interrupt Routing
#define D14F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D14F0_RINTABCD			0xFF	//01h/R/x/x Interrupt Pin
#define D14F0_CTL_REG_1		0x40	//Control Register 1
    #define D14F0_CAHCFG			BIT7	//0/0/x/x Reserved
    #define D14F0_BABOPT			BIT6	//1b/1/x/x Babble Option
    #define D14F0_PAROPT			BIT5	//0/0/x/x Reserved
    #define D14F0_REDUCE			BIT4	//0/0/x/x Frame Interval Select
    #define D14F0_HCISPEC			BIT3	//0/0/x/x USB Data Length Option
    #define D14F0_DISIMPROVEFIFO			BIT2	//0/0/x/x Improve FIFO Latency
    #define D14F0_FCFG			BIT1	//0/0/x/x DMA Option
    #define D14F0_EN_FS_EYE_IMPROVE			BIT0	//0/0/x/x Reserved ((Random))
#define D14F0_CTL_REG_2		0x41	//Control Register 2
    #define D14F0_DISSTUFF			BIT7	//0/0/x/x USB 1.1 Improvement for EOP
    #define D14F0_DISPRST			BIT6	//0/0/x/x Reserved
    #define D14F0_DISEOP			BIT5	//0/0/x/x Reserved
    #define D14F0_ENOCPY			BIT4	//1b/1/x/x Reserved (Do Not Program)
    #define D14F0_TESTCNT			BIT3	//0/0/x/x Reserved
    #define D14F0_TRAPOPT			BIT2	//0/0/x/x I/ O Port 60/64 Trap Option
    #define D14F0_VIAPSS			BIT1	//1b/1/x/x A20Gate Pass Through Option
    #define D14F0_UIRQACT			BIT0	//0/R/x/x Reserved
#define D14F0_CTL_REG_3		0x42	//Control Register 3
    #define D14F0_DISPRXDISCON			BIT7	//0/0/x/x Reserved
    #define D14F0_ENTXDLY			(BIT5 + BIT6)	//0/0/x/x Reserved
    #define D14F0_SUBIDWE			BIT4	//0/0/x/x Enable Subsystem ID / Subsystem Vender ID Optional
    #define D14F0_DISPFUNDRN			BIT3	//0/0/x/x Reserved
    #define D14F0_DISTXDLY			BIT2	//0/0/x/x Hold Data Transmission till FIFO Reaches Transmission Threshold
    #define D14F0_OCUPY_SEL			(BIT0 + BIT1)	//11b/11b/x/x Reserved (Do Not Program) ((Random))
#define D14F0_CTL_REG_4		0x43	//Control Register 4
    #define D14F0_ENBMUSMRST			BIT7	//0/0/x/x Reserved
    #define D14F0_DISRXZERO			BIT6	//0/0/x/x Reserved
    #define D14F0_DISPFIFO2			BIT5	//0/0/x/x Reserved
    #define D14F0_DISPFIFO			BIT4	//0/0/x/x Reserved
    #define D14F0_DISFFCRC1			BIT3	//0/0/x/x Continue Transmitting Erroneous Data When FIFO Underrun ((Random))
    #define D14F0_DISFFCRC0			BIT2	//0/0/x/x Issue CRC Error Instead of Stuffing Error on FIFO Underrun ((Random))
    #define D14F0_DISTXDLY2			BIT1	//0/0/x/x Reserved
    #define D14F0_ENTXDLY_1			BIT0	//0/0/x/x Reserved
#define D14F0_CTL_REG_5		0x48	//Control Register 5
    #define D14F0_EN_NULLSOF_RSTNEW			BIT7	//1b/1/x/x Reserved (Do Not Program)
    #define D14F0_NULLSOF_SEL			(BIT5 + BIT6)	//00b/00b/x/x Reserved ((Random))
    #define D14F0_DISPLATSOF			BIT4	//0/0/x/x Reserved
    #define D14F0_DISPSTUFF			BIT3	//0/0/x/x Reserved
    #define D14F0_DISFFCRC3			BIT2	//0/0/x/x Issue Bad CRC5 in SOF after FIFO Underrun
    #define D14F0_ENLONGPRESOF			BIT1	//0/0/x/x Lengthen PreSOF Time ((Random))
    #define D14F0_DISFFCRC2			BIT0	//0/0/x/x Issue Non-Zero Bad CRC Code on FIFO Underrun ((Random))
#define D14F0_CTL_REG_6		0x49	//Control Register 6
    #define D14F0_EHCI_RX_OUT			BIT7	//0/0/x/x Reserved
    #define D14F0_EHCI_OUT_EN			BIT6	//0/0/x/x Reserved
    #define D14F0_SELSCLK			BIT5	//0/0/x/x Bypass 32KHz RTC Clock
    #define D14F0_TESTSG			BIT4	//0/0/x/x Reset USBC Internal 12MHz Clock for UHCI ((CLK12)) Divider from 48MHz Clock
    #define D14F0_EN_EHCI			BIT3	//1b/1/x/x Reserved (Do Not Program)
    #define D14F0_PAS_OSC			BIT2	//0/0/x/x Reserved (Do Not Program)
    #define D14F0_E_PME_EN			BIT1	//1b/1/x/x EHCI Supports PME Assertion in D3 Cold State
    #define D14F0_U_PME_EN			BIT0	//1b/1/x/x UHCI Supports PME Assertion in D3 Cold State
#define D14F0_CTL_REG_7		0x4A	//Control Register 7
    #define D14F0_TIMEOUT_PARM			0xF8	//14h/14h/x/x USB 1.1 Bus Timeout Parameter
    #define D14F0_DISPLSPRE			BIT2	//0/0/x/x Reserved
    #define D14F0_EN_STPBM_HALT			BIT1	//1b/1b/x/x Enable Stop Bus Master Cycle If HALT Bit Is Asserted
    #define D14F0_EXTCLK60M_EN			BIT0	//0/0/x/x Use External 60 MHz Clock
#define D14F0_CTL_REG_8		0x4B	//Control Register 8
    #define D14F0_NEW_CCA_EN			BIT7	//1b/1/x/x Reserved (Do Not Program)
    #define D14F0_UHCI_PCLK66_PD_EN			BIT6	//0/0/1/1 Enable 66MHz New UHCI Dynamic Scheme (UHCI_PCLK66_PD_EN)
    #define D14F0_UHCI_PCLK33_PD_EN			BIT5	//0/0/1/1 Enable 33MHz New UHCI Dynamic Scheme (UHCI_PCLK33_PD_EN)
    #define D14F0_REVID_BACKEN			BIT4	//0/0/x/x Reserved
    #define D14F0_EN_PATCH_CLKSTOP			BIT3	//1b/1/x/x Reserved (Do Not Program)
    #define D14F0_DEBUGB_2			BIT2	//0/0/x/x Reserved
    #define D14F0_EN_GLOBRST			BIT1	//1b/1/x/x Reserved (Do Not Program)
    #define D14F0_CLKOFF_EN			BIT0	//1b/1/1/1 Enable Clock Auto Stop
#define D14F0_CTL_REG_9		0x4C	//Control Register 9
    #define D14F0_REVID_BACK			0xFF	//A0h/a0h/x/x Reserved
#define D14F0_CTL_REG_10		0x4D	//Control Register 10
    #define D14F0_DEBUGC_7_4			0xF0	//0/0/x/x Reserved
    #define D14F0_DEBUGC_3_2			(BIT2 + BIT3)	//10b/10b/x/x UHCI FIFO Select
    #define D14F0_BMASTREN_SEL			BIT1	//1b/1/x/x Bus Master Enable Select
    #define D14F0_DEBUGC_0			BIT0	//0/x/x/x Reserved
#define D14F0_DID_OPTIONAL		0x4E	//Device ID optional
    #define D14F0_VID_OPTIONAL			0xFFFF	//1D17h/x/x/x Vendor ID Optional
#define D14F0_SERIAL_BUS_RELEASE_NUM		0x60	//Serial Bus Release Number
    #define D14F0_USBSPEC0			0xFF	//10h/R/x/x Serial Bus Release Number
#define D14F0_PM_CAP		0x80	//Power Management Capability
    #define D14F0_PMI_REG1			0xFFFFFFFF	//FFC29801h/R/x/x Power Management Capability
#define D14F0_PM_CAP_STA		0x84	//Power Management Capability Status
    #define D14F0_PME_STS			BIT15	//0/0/x/x PME Status
    #define D14F0_PME_EN			BIT8	//0/0/x/x PME Enable
    #define D14F0_PWR_STATE			(BIT0 + BIT1)	//0/0/x/x Power Management Capability Status
#define D14F0_FLR_CAP_ID		0x98	//FLR Capability ID
    #define D14F0_FLR_CID			0xFF	//13h/R/x/x FLR Capability ID
#define D14F0_NEXT_ITEM_POINTER_2		0x99	//Next Item Pointer 2
    #define D14F0_CAP_PTR_FLR			0xFF	//00h/R/x/x Next Item Pointer 2
#define D14F0_FLR_CAP_LEN_AND_VER_REG		0x9A	//FLR Capability Length and Version Register
    #define D14F0_FLR_CAP			BIT9	//1b/1/x/x FLR Capability
    #define D14F0_FLR_TXPCAP			BIT8	//1b/1/x/x TXP Capability
    #define D14F0_FLR_LEN			0xFF	//06h/06h/x/x Capability Length
#define D14F0_FLR_CTL_REG		0x9C	//FLR Control Register
    #define D14F0_INI_FLR			BIT0	//0/0/x/x Initiate FLR
#define D14F0_FLR_CAP_LEN_AND_VER_REG_Z1		0x9D	//FLR Capability Length and Version Register
    #define D14F0_FLR_TXP			BIT0	//0/0/x/x TXP Status Register
#define D14F0_FLR_PENDING_STA_REG		0x9E	//FLR Pending Status Register
    #define D14F0_FLR_STS			BIT0	//0/0/x/x FLR Pending Status
#define D14F0_FLR_AND_VID_OPTIONAL_REG		0x9F	//FLR and VID Optional Register
    #define D14F0_VID_OPTIONAL_SET			BIT2	//0/0/X/x Vendor ID Optional
    #define D14F0_FLR_CAP_OPTIONAL			BIT1	//0/0/x/x FLR Capability Attribute Change Optional Register
    #define D14F0_FLR_OPTIONAL			BIT0	//1b/1/x/x FLR Optional
#define D14F0_PORT_CONNECT_STA_GATING_REG		0xA0	//Port Connect Status Gating Register
    #define D14F0_TXSE0_26US_EN			BIT2	//0/0/x/X Fix TXSE0 2.6us Bug
    #define D14F0_PORT2_CCS_GATE			BIT1	//0/0/x/x Port 2 Connect Status Gating Register
    #define D14F0_PORT1_CCS_GATE			BIT0	//0/0/x/x Port 1 Connect Status Gating Register
#define D14F0_DID_OPTIONAL_Z1		0xA1	//Device ID optional
    #define D14F0_DID_OPTIONAL_Z2			0xFFFF	//3038h/x/x/x Device ID optional
#define D14F0_FRAME_INTERVAL_CONFIGURE_VALUE		0xA4	//Frame Interval Configure Value
    #define D14F0_REDUN_BIT			BIT15	//0/0/x/x Reserved
    #define D14F0_FMINTV_VAL_EN			BIT14	//0/x/x/x Frame Interval Configure Value Enable
    #define D14F0_FMINTV_VAL			0x3FFF	//49Fh/x/x/x Frame Interval Configure Value
#define D14F0_CCA_BUS_SRC_ID		0xA6	//CCA Bus Source ID
    #define D14F0_UBDF			0xFFFF	//0080h/x/x/x CCA BUS source ID
#define D14F0_LEGACY_SUPPORT_FOR_UHCI_V1_1_COMPLIANT		0xC0	//Legacy Support (for UHCI v1.1 Compliant)
    #define D14F0_A20PTS			BIT15	//0/x/x/x End of A20Gate Pass Through Status (A20PTS)
    #define D14F0_RESV_LEG			BIT14	//0/R/x/x Reserved
    #define D14F0_UIRQEN			BIT13	//1b/x/x/x USB PIRQ Enable (USBPIRQDEN)
    #define D14F0_LEGSUP_12			BIT12	//0/R/x/x USB IRQ Status (USBIRQS)
    #define D14F0_TBY64W			BIT11	//0/x/x/x Trap By 64h Write Status (TBY64W)
    #define D14F0_TBY64R			BIT10	//0/x/x/x Trap By 64h Read Status (TBY64R)
    #define D14F0_TBY60W			BIT9	//0/x/x/x Trap By 60h Write Status (TBY60W)
    #define D14F0_TBY60R			BIT8	//0/x/x/x Trap By 60h Read Status (TBY60R)
    #define D14F0_SMIEPTE			BIT7	//0/x/x/x SMI At End Of Pass Through Enable (SMIEPTE)
    #define D14F0_PSS			BIT6	//0/R/x/x Pass Through Status (PSS)
    #define D14F0_A20PTEN			BIT5	//0/x/x/x A20Gate Pass Through Enable (A20PTEN)
    #define D14F0_USMIEN			BIT4	//0/x/x/x Trap / SMI ON IRQ Enable (USBSMIEN)
    #define D14F0_U64WEN			BIT3	//0/x/x/x Trap / SMI On 64h Write Enable (64WEN)
    #define D14F0_U64REN			BIT2	//0/x/x/x Trap / SMI On 64h Read Enable (64REN)
    #define D14F0_U60WEN			BIT1	//0/x/x/x Trap / SMI On 60h Write Enable (60WEN)
    #define D14F0_U60REN			BIT0	//0/x/x/x Trap / SMI On 60h Read Enable (60REN)
//USB 1.1-IO
#define USB_11IO_USB_CMD		0x00	//USB Command
    #define USB_11IO_MAXP			BIT7	//0/x/x/x Max Packet
    #define USB_11IO_CF			BIT6	//0/x/x/x Configure Flag (CF)
    #define USB_11IO_SWDBG			BIT5	//0/x/x/x Software Debug (SWDBG)
    #define USB_11IO_FGR			BIT4	//0/x/x/x Force Global Resume (FGR)
    #define USB_11IO_EGSM			BIT3	//0/x/x/x Enter Global Suspend Mode (EGSM)
    #define USB_11IO_GRESET			BIT2	//0/x/x/x Global Reset (GRESET)
    #define USB_11IO_HCRESET			BIT1	//0/x/x/x Host Controller Reset (HCRESET)
    #define USB_11IO_RUN_CFG			BIT0	//0/x/x/x Run / Stop (RS)
#define USB_11IO_USB_STA		0x02	//USB Status
    #define USB_11IO_HCHALT			BIT5	//1b/R/x/x Host Controller Halted
    #define USB_11IO_HCPERR			BIT4	//0/X/x/x Host Controller Process Error
    #define USB_11IO_PCIERR			BIT3	//0/X/x/x Host System Error
    #define USB_11IO_RESUME			BIT2	//0/X/x/x Resume Detect
    #define USB_11IO_USBEI			BIT1	//0/X/x/x USB Error Interrupt
    #define USB_11IO_USBINT			BIT0	//0/X/x/x USB Interrupt (USBINT)
#define USB_11IO_USB_INTR_ENABLE		0x04	//USB Interrupt Enable
    #define USB_11IO_SPKTIEN			BIT3	//0/x/x/x Short Packet Interrupt Enable
    #define USB_11IO_IOCEN			BIT2	//0/x/x/x Interrupt On Complete (IOC) Enable
    #define USB_11IO_RESUMEN			BIT1	//0/x/x/x Resume Interrupt Enable
    #define USB_11IO_TMCRCEN			BIT0	//0/x/x/x Timeout / CRC Interrupt Enable
#define USB_11IO_FRAME_NUM		0x06	//Frame Number
    #define USB_11IO_FRNUM_31_27			0xF800	//0/R/x/x Reserved
    #define USB_11IO_FRNUM_26_16			0x7FF	//0/x/x/x Frame List Current Index / Frame Number
#define USB_11IO_FRAME_LIST_BASE_ADR		0x08	//Frame List Base Address
    #define USB_11IO_FRMBASE			0xFFFFF000	//0/x/x/x Frame List Base Address
#define USB_11IO_START_OF_FRAME_MODIFY		0x0C	//Start of Frame Modify
    #define USB_11IO_SOFMOD			0x7F	//40h/x/x/x Start of Frame Timing Value
#define USB_11IO_PORT_0_STA_CTL		0x10	//Port 0 Status / Control
    #define USB_11IO_PORTSC1_12			BIT12	//0/0/x/x Suspend
    #define USB_11IO_OCSCHG0			BIT11	//0/R/x/x Reserved
    #define USB_11IO_OC0I			BIT10	//1b/R/x/x Reserved
    #define USB_11IO_PORTRST1			BIT9	//0/0/x/x Port Reset
    #define USB_11IO_LSDEV1			BIT8	//0/R/x/x Low Speed Device Attached
    #define USB_11IO_PORTSC1_7			BIT7	//1b/R/x/x Reserved (Do Not Program)
    #define USB_11IO_PORTSC1_6			BIT6	//0/x/x/x Resume Detect
    #define USB_11IO_SPORT1			(BIT4 + BIT5)	//0/R/x/x Line Status
    #define USB_11IO_PORTEDC1			BIT3	//0/0/x/x Port Enable / Disable Change
    #define USB_11IO_PORTSC1_2			BIT2	//0/x/x/x Port Enabled / Disabled
    #define USB_11IO_CONSCHG1			BIT1	//0/0/x/x Connect Status Change
    #define USB_11IO_CONN1			BIT0	//0/R/x/x Current Connect Status
#define USB_11IO_PORT_1_STA_CTL		0x12	//Port 1 Status / Control
    #define USB_11IO_PORTSC2_12			BIT12	//0/0/x/x Suspend
    #define USB_11IO_OCSCHG1			BIT11	//0/R/x/x Reserved
    #define USB_11IO_OC1I			BIT10	//1b/R/x/x Reserved
    #define USB_11IO_PORTRST2			BIT9	//0/0/x/x Port Reset
    #define USB_11IO_LSDEV2			BIT8	//0/R/x/x Low Speed Device Attached
    #define USB_11IO_PORTSC2_7			BIT7	//1b/R/x/x Reserved (Do Not Program)
    #define USB_11IO_PORTSC2_6			BIT6	//0/x/x/x Resume Detect
    #define USB_11IO_SPORT2			(BIT4 + BIT5)	//0/R/x/x Line Status
    #define USB_11IO_PORTEDC2			BIT3	//0/0/x/x Port Enable / Disable Change
    #define USB_11IO_PORTSC2_2			BIT2	//0/x/x/x Port Enabled / Disabled
    #define USB_11IO_CONSCHG2			BIT1	//0/0/x/x Connect Status Change
    #define USB_11IO_CONN2			BIT0	//0/R/x/x Current Connect Status
#endif
