//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		XHCICTRL					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D18F0_xHCICtrl_R102(A0).doc(final)MOD_XHCI_PCIS.xls
#ifndef _CHX002_D18F0_XHCICTRL_H
#define _CHX002_D18F0_XHCICTRL_H
//D18F0
#define D18F0_VID		0x00	//Vendor ID
    #define D18F0_VID_Z1			0xFFFF	//1D17h/x/x/x Vendor ID
#define D18F0_DID		0x02	//Device ID
    #define D18F0_DEVID			0xFFFF	//9204h/x/x/x Device ID Code
#define D18F0_PCI_CMD		0x04	//PCI Command
    #define D18F0_RESERVED			0xF800	//0/R/x/x Reserved
    #define D18F0_INTRDIS			BIT10	//0/0/x/x Interrupt Disable
    #define D18F0_RESERVED_Z1			BIT9	//0/R/x/x Reserved
    #define D18F0_SERREN			BIT8	//0/0/x/x SERR Enable
    #define D18F0_RESERVED_Z2			BIT7	//0/R/x/x Reserved
    #define D18F0_RPTYERR			BIT6	//0/0/x/x Parity Error Response
    #define D18F0_RESERVED_Z3			BIT5	//0/R/x/x Reserved
    #define D18F0_MWRMEN			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D18F0_RESERVED_Z4			BIT3	//0/R/x/x Reserved 
    #define D18F0_BMASTREN			BIT2	//0/x/x/x Bus Master
    #define D18F0_MMSPACE			BIT1	//0/x/x/x Memory Space
    #define D18F0_IOSPACE			BIT0	//0/x/x/x I/O Space
#define D18F0_PCI_STA		0x06	//PCI Status
    #define D18F0_DPRTYERR			BIT15	//0/x/x/x Detected Parity Error
    #define D18F0_SSYSERR			BIT14	//0/x/x/x Signaled System Error
    #define D18F0_TMABORTS			BIT13	//0/x/x/x Received Master Abort (Except Special Cycle)
    #define D18F0_TTABORTR			BIT12	//0/x/x/x Received Target Abort
    #define D18F0_STABORT			BIT11	//0/x/x/x Signaled Target Abort
    #define D18F0_DEVSELTM			(BIT9 + BIT10)	//0/x/x/x DEVSEL# Timing
    #define D18F0_MDPRTYERR			BIT8	//0/x/x/x Master Data Parity Error
    #define D18F0_RESERVED_Z5			0xF0	//01h/R/x/x Fixed at 01h (for PCI PMI)
    #define D18F0_INTRSTS			BIT3	//0/x/x/x Interrupt Status
    #define D18F0_RESERVED_Z6			(BIT0 + BIT1 + BIT2)	//0/R/x/x Reserved
#define D18F0_REV_ID		0x08	//Revision ID
    #define D18F0_REVID			0xFF	//00h/x/x/x Revision ID
#define D18F0_CLASS_CODE		0x09	//Class Code
    #define D18F0_CLSCODE			0xFFFFFF	//0C0330h/x/x/x Class Code for USB3.0 xHCI Host Controller
#define D18F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D18F0_CACHLINE			0xFF	//0/x/x/x Cache Line Size
#define D18F0_LATENCY_TIMER		0x0D	//Latency Timer
    #define D18F0_LATTM			0xFF	//0/R/x/x Latency Timer
#define D18F0_HEADER_TYPE		0x0E	//Header Type
    #define D18F0_HDTYPE			0xFF	//00h/x/x/x Header Type
#define D18F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D18F0_BIST			0xFF	//0/x/x/x BIST
#define D18F0_XHCI_MEM_MAPPED_IO_LOW_BASE_ADR		0x10	//xHCI Memory Mapped I/O Low Base Address
    #define D18F0_BASEADDR0_LO			0xFFFFF000	//0/x/x/x xHCI Memory Mapped I/O Registers Low Base Address
    #define D18F0_RESERVED_Z7			0xFF8	//0/R/x/x Reserved
    #define D18F0_BARTYPE0			(BIT1 + BIT2)	//10b/x/x/x Base Address Type
    #define D18F0_RESERVED_Z8			BIT0	//0/R/x/x Reserved
#define D18F0_XHCI_MEM_MAPPED_IO_HIGH_BASE_ADR		0x14	//xHCI Memory Mapped I/O High Base Address
    #define D18F0_BASEADDR0_HI			0xFFFFFFFF	//0/x/x/x xHCI Memory Mapped I/O Registers High Base Address
#define D18F0_SVID		0x2C	//Subsystem Vendor ID
    #define D18F0_SYSVID			0xFFFF	//1D17h/x/x/x Subsystem Vendor ID
#define D18F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D18F0_SUBSID			0xFFFF	//9204h/x/x/x Subsystem ID
#define D18F0_CAP_POINTER		0x34	//Capability Pointer
    #define D18F0_CAPPTR			0xFF	//80h/R/x/x Capability Pointer
#define D18F0_INTR_LINE		0x3C	//Interrupt Line
    #define D18F0_INTLN			0xFF	//0/x/x/x USB Interrupt Routing
#define D18F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D18F0_INTPIN			0xFF	//01h/R/x/x Interrupt Pin
#define D18F0_XHCIOPTION_BITS_RX40_XHCOPTRX40		0x40	//xHCI Option Bits Rx40 (XHCOPTRX40)
    #define D18F0_XHCI_DBG_SEL			0xFF	//0/0/x/x xHCI Debug Signal Group Select Low 32 Bits
#define D18F0_XHCIOPTION_BITS_RX41_XHCOPTRX41		0x41	//xHCI Option Bits Rx41 (XHCOPTRX41)
    #define D18F0_TOP_DBG_SEL			0xFF	//0/0/x/x TOP Debug Signal Group Select
#define D18F0_XHCIOPTION_BITS_RX42_XHCOPTRX42		0x42	//xHCI Option Bits Rx42 (XHCOPTRX42)
    #define D18F0_XHCI_DBG_SEL2			0xFF	//0/0/x/x xHCI Debug Signal Group Select High 32 Bits
#define D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43		0x43	//xHCI Option Bits Rx43 (XHCOPTRX43)
    #define D18F0_RESERVED_Z9			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D18F0_XHCI_DBG_SEL_EXT			BIT4	//0/x/x/x xHCI_DBG_SEL Extend to 512 Groups
    #define D18F0_RESERVED_Z10			(BIT1 + BIT2 + BIT3)	//0/x/x/x Reserved
    #define D18F0_CPU_OPTCFG			BIT0	//0/x/x/x CPU Configure Optional Register Enable (BIOS Configure)
#define D18F0_XHCIOPTION_BITS_RX44_XHCOPTRX44		0x44	//xHCI Option Bits Rx44 (XHCOPTRX44)
    #define D18F0_RESERVED_Z11			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D18F0_FLRCAPWE			BIT4	//0/0/x/x Reserved
    #define D18F0_RESERVED_Z12			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D18F0_SVID_SID_SEL			BIT0	//0/0/x/x Reserved
#define D18F0_XHCIOPTION_BITS_RX45_XHCOPTRX45		0x45	//xHCI Option Bits Rx45 (XHCOPTRX45)
    #define D18F0_RESERVED_Z13			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D18F0_DID_RID_LOCK			BIT4	//0/x/x/x Reserved
    #define D18F0_RESERVED_Z14			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D18F0_VID_LOCK			BIT0	//0/x/x/x Reserved
#define D18F0_XHCI_SYSTEM_ENTER_SUSPEND_STA		0x46	//xHCI System Enter Suspend Status
    #define D18F0_RESERVED_Z15			0xFE	//0/R/x/x Reserved
    #define D18F0_SWSYSTEMSUS			BIT0	//0/x/x/x xHCI System Enter Suspend (S3/S4/S5) Status
#define D18F0_XHCI_MIRROR_REG_FOR_SW_WRITE_XHCIOPTION_RXE0_EF_INTR_STA		0x47	//xHCI Mirror Register for SW Write XHCI Option RxE0~EF Interrupt Status
    #define D18F0_RESERVED_Z16			0xFE	//0/R/x/x Reserved
    #define D18F0_SW_WR_INT_STS			BIT0	//0/x/x/x xHCI Mirror Register for SW Write XHCI Option RxE0
#define D18F0_XHCI_CRCR_MIRROR_LOW_REG		0x48	//xHCI CRCR Mirror Low Register
    #define D18F0_CRCR_MIRROR_LO			0xFFFFFFFF	//0/x/x/x xHCI CRCR Mirror Low Register
#define D18F0_XHCI_CRCR_MIRROR_HIGH_REG		0x4C	//xHCI CRCR Mirror High Register
    #define D18F0_CRCR_MIRROR_HI			0xFFFFFFFF	//0/x/x/x xHCI CRCR Mirror High Register
#define D18F0_XHCI_MCU_FW_VER		0x50	//xHCI MCU Firmware Version
    #define D18F0_FW_VERSION			0xFFFFFFFF	//0/x/x/x xHCI MCU Firmware Version
#define D18F0_XHCIOPTION_BITS_RX54_XHCOPTRX54		0x54	//xHCI Option Bits Rx54 (XHCOPTRX54)
    #define D18F0_FWNOTE			0xFF	//0/x/x/x Used for FW to Store Some Internal Information
#define D18F0_XHCIOPTION_BITS_RX55_XHCOPTRX55		0x55	//xHCI Option Bits Rx55 (XHCOPTRX55)
    #define D18F0_RESERVED_Z17			0xF8	//0/R/x/x Reserved
    #define D18F0_R_PLLOK_SEL			(BIT1 + BIT2)	//0/0/x/x USB3.0 PHY PLLOK Selection
    #define D18F0_SUSCLKSEL			BIT0	//1b/1b/x/x Suspend Clock Selection
#define D18F0_XHCIOPTION_BITS_RX56_XHCOPTRX56		0x56	//xHCI Option Bits Rx56 (XHCOPTRX56)
    #define D18F0_R_XHCI_PTN_DBG_SEL_G1			0xF0	//0/x/x/x xHCI PTN Top Debug Signal G1 Selection
    #define D18F0_R_XHCI_PTN_DBG_SEL_G0			0xF	//0/x/x/x XHCI PTN Top Debug Signal G0 Selection
#define D18F0_XHCIOPTION_BITS_RX57_XHCOPTRX56		0x57	//xHCI Option Bits Rx57 (XHCOPTRX56)
    #define D18F0_R_XHCI_PTN_DBG_SEL_G3			0xF0	//0/x/x/x xHCI PTN Top Debug Signal G3 Selection
    #define D18F0_R_XHCI_PTN_DBG_SEL_G2			0xF	//0/x/x/x xHCI PTN Top Debug Signal G2 Selection
#define D18F0_XHCIOPTION_BITS_RX58_XHCOPTRX54		0x58	//xHCI Option Bits Rx58 (XHCOPTRX54)
    #define D18F0_HSTTX2_DBG_SEL			0xFF	//0/x/x/x HSTTX2 Debug Signal Group Select
#define D18F0_XHCIOPTION_BITS_RX59		0x59	//xHCI Option Bits Rx59
    #define D18F0_RESERVED_Z18			0xFC	//0/R/x/x Reserved
    #define D18F0_U2P2DISABLE			BIT1	//0/x/x/x USB2.0 Port 2 Disable
    #define D18F0_U2P1DISABLE			BIT0	//0/x/x/x USB2.0 Port 1 Disable
#define D18F0_XHCIOPTION_BITS_RX5A		0x5A	//xHCI Option Bits Rx5A
    #define D18F0_RESERVED_Z19			0xFC	//0/R/x/x Reserved
    #define D18F0_U3P2DISABLE			BIT1	//0/x/x/x USB3.0 Port 2 Disable
    #define D18F0_U3P1DISABLE			BIT0	//0/x/x/x USB3.0 Port 1 Disable
#define D18F0_SVID_FOR_SW		0x5C	//Subsystem Vendor ID For SW
    #define D18F0_SYSVID_OPT			0xFFFF	//1D17h/1D17h/x/x Subsystem Vendor ID (SW/FW can update)
#define D18F0_SUBSYSTEM_ID_FOR_SW		0x5E	//Subsystem ID For SW
    #define D18F0_SUBSID_OPT			0xFFFF	//9204h/9204h/x/x Subsystem ID (SW/FW can update)
#define D18F0_SERIAL_BUS_RELEASE_NUM_SBRN		0x60	//Serial Bus Release Number (SBRN)
    #define D18F0_SBRN			0xFF	//31h/x/x/x Serial Bus Specification Release Number
#define D18F0_FRAME_LEN_ADJUSTMENT_FLADJ		0x61	//Frame Length Adjustment (FLADJ)
    #define D18F0_RESERVED_Z20			BIT7	//0/R/x/x Reserved
    #define D18F0_NFC			BIT6	//0/x/x/x No Frame Length Timing Capability (NFC)
    #define D18F0_FLADJ			0x3F	//20h/20h/x/x Frame Length Timing Value
#define D18F0_DBESLD_AND_DBESL		0x62	//DBESLD and DBESL
    #define D18F0_DBESLD			0xF0	//0/x/x/x Default Best Effort Service Latency Deep
    #define D18F0_DBESL			0xF	//0/x/x/x Default Best Effort Service Latency 
#define D18F0_XHCIOPTION_BITS_RX64_XHCOPTRX64		0x64	//xHCI Option Bits Rx64 (XHCOPTRX64)
    #define D18F0_MCU_DBG_SEL2			0xF0	//0/x/x/x MCU Debug Signal Group Select High 32 Bits
    #define D18F0_MCU_DBG_SEL			0xF	//0/x/x/x MCU Debug Signal Group Select Low 32 Bits
#define D18F0_XHCIOPTION_BITS_RX65_XHCOPTRX65		0x65	//xHCI Option Bits Rx65 (XHCOPTRX65)
    #define D18F0_RESERVED_Z21			0xFE	//0/R/x/x Reserved
    #define D18F0_MCU_DBGEN			BIT0	//0/x/x/x MCU Debug Signal Enable
#define D18F0_XHCI_SRC_ID_BACKDOOR		0x70	//xHCI Source ID Backdoor
    #define D18F0_SID			0xFFFF	//0090h/0090h/x/x SID (SW attribute :RWL  HW attribute: RO)
#define D18F0_XHCIOPTIONAL_BITS_CFG_ADR		0x78	//xHCI Optional Bits Configuration Address
    #define D18F0_RESERVED_Z22			0xFFF00000	//0/R/x/x Reserved
    #define D18F0_OPTCFGADDR			0xFFFFF	//0/x/x/x xHCI Option Bits Configuration Address
#define D18F0_XHCIOPTIONAL_BITS_CFG_DATA		0x7C	//xHCI Optional Bits Configuration Data
	#define D18F0_XHCIOPTIONAL_BITS_CFG_DATA_Byte0 0x7C
	#define D18F0_XHCIOPTIONAL_BITS_CFG_DATA_Byte1 0x7D
	#define D18F0_XHCIOPTIONAL_BITS_CFG_DATA_Byte2 0x7E
	#define D18F0_XHCIOPTIONAL_BITS_CFG_DATA_Byte3 0x7F
    #define D18F0_OPTCFGDATA			0xFFFFFFFF	//0/x/x/x xHCI Option Bits Configuration Data
#define D18F0_PM_CAP_ID		0x80	//Power Management Capability ID
    #define D18F0_PMCAPID			0xFF	//01h/x/x/x Power Management Capability ID
#define D18F0_NEXT_ITEM_POINTER_1		0x81	//Next Item Pointer 1
    #define D18F0_PMNXTPTR			0xFF	//90h/x/x/x Next Item Pointer 1
#define D18F0_PM_CAP		0x82	//Power Management Capability
    #define D18F0_PMCAP			0xFFFF	//F9C3h/x/x/x Power Management Capability
#define D18F0_PM_CAP_CTL_STA		0x84	//Power Management Capability Control / Status
    #define D18F0_PMESTATUS			BIT15	//0/x/x/x PME Status
    #define D18F0_RESERVED_Z23			0x7E00	//0/R/x/x Reserved
    #define D18F0_PMEEN			BIT8	//0/0/x/x PME Enable
    #define D18F0_RESERVED_Z24			0xFC	//0/R/x/x Reserved
    #define D18F0_PMSTATE			(BIT0 + BIT1)	//00b/00b/x/x Power State
#define D18F0_MSI_CAP_ID		0x90	//MSI Capability ID
    #define D18F0_MSIID			0xFF	//05h/x/x/x MSI Capability ID
#define D18F0_NEXT_ITEM_POINTER_2		0x91	//Next Item Pointer 2
    #define D18F0_MSINXTPTR			0xFF	//A0h/x/x/x Next Item Pointer 2
#define D18F0_MSI_MSG_CTL		0x92	//MSI Message Control
    #define D18F0_RESERVED_Z25			0xFE00	//0/R/x/x Reserved
    #define D18F0_MSIMSKCAP			BIT8	//0/x/x/x Per-vector Masking Capable
    #define D18F0_MSIADDR64CAP			BIT7	//1b/x/x/x 64 Bit Address Capable
    #define D18F0_MSIMLTEN			(BIT4 + BIT5 + BIT6)	//0/0/x/x Multiple Message Enable
    #define D18F0_MSIMULCAP			(BIT1 + BIT2 + BIT3)	//010b/x/x/x Multiple Message Capable
    #define D18F0_MSIEN			BIT0	//0/0/x/x MSI Enable
#define D18F0_MSI_MSG_ADR_LOW		0x94	//MSI Message Address Low
    #define D18F0_MSIADDRLO			0xFFFFFFFC	//0/0/x/x Message Address (Low 32 Bits).
    #define D18F0_RESERVED_Z26			(BIT0 + BIT1)	//0/R/x/x Reserved
#define D18F0_MSI_MSG_ADR_HIGH		0x98	//MSI Message Address High
    #define D18F0_MSIADDRHI			0xFFFFFFFF	//0/0/x/x Message Address (High 32 Bits)
#define D18F0_MSI_DATA		0x9C	//MSI Data
    #define D18F0_MSIDATA			0xFFFF	//0/0/x/x Message Data
#define D18F0_FUN_LEVEL_RESET_CAP_ID		0xA0	//Function Level Reset Capability ID
    #define D18F0_FLRID			0xFF	//13h/x/x/x Function Level Reset Capability ID
#define D18F0_NEXT_ITEM_POINTER_3		0xA1	//Next Item Pointer 3
    #define D18F0_FLRNXTPTR			0xFF	//00h/x/x/x Next Item Pointer 3
#define D18F0_FUN_LEVEL_RESET_CAP_LEN_AND_VER		0xA2	//Function Level Reset Capability Length and Version
    #define D18F0_RESERVED_Z27			0xFC00	//0/R/x/x Reserved
    #define D18F0_FLRCAP			BIT9	//1b/x/x/x FLR Capability
    #define D18F0_FLRTXPCAP			BIT8	//1b/x/x/x TXP Capability
    #define D18F0_FLRLENGTH			0xFF	//06h/x/x/x Capability Length
#define D18F0_FUN_LEVEL_RESET_CTL_REG		0xA4	//Function Level Reset Control Register
    #define D18F0_RESERVED_Z28			0xFE	//0/R/x/x Reserved
    #define D18F0_FLRINIT			BIT0	//0/x/x/x Initiate FLR
#define D18F0_FUN_LEVEL_RESET_STA_REG		0xA5	//Function Level Reset Status Register
    #define D18F0_RESERVED_Z29			0xFE	//0/R/x/x Reserved
    #define D18F0_FLRTXP			BIT0	//0/x/x/x Transaction Pending (TXP)
#define D18F0_FW_TO_SW_MSG_DW0		0xB0	//FW to SW Message DW0
    #define D18F0_FWSWMSG0			0xFFFFFFFF	//0/x/x/x MCU FW Debug Message to SW DW0
#define D18F0_FW_TO_SW_MSG_DW1		0xB4	//FW to SW Message DW1
    #define D18F0_FWSWMSG1			0xFFFFFFFF	//0/x/x/x MCU FW Debug Message to SW DW1
#define D18F0_FW_TO_SW_MSG_DW2		0xB8	//FW to SW Message DW2
    #define D18F0_FWSWMSG2			0xFFFFFFFF	//0/x/x/x MCU FW Debug Message to SW DW2
#define D18F0_FW_TO_SW_MSG_DW3		0xBC	//FW to SW Message DW3
    #define D18F0_FWSWMSG3			0xFFFFFFFF	//0/x/x/x MCU FW Debug Message to SW DW3
//USB3.0-MMIO
#define USB30MMIO_CAP_REGS_LEN_CAPLEN		0x00	//Capability Registers Length (CAPLENGTH)
    #define USB30MMIO_CAPLENGTH			0xFF	//20h/R/x/x Capability Registers Length
//USB3.0£­MMIO
#define USB30£­MMIO_HOST_CTLLER_IF_VER_NUM_HCIVER		0x02	//Host Controller Interface Version Number (HCIVERSION)
    #define USB30£­MMIO_HCIVERSION			0xFFFF	//0110h/x/x/x Host Controller Interface Version Number
#define USB30£­MMIO_STRUCTURAL_PARAMETERS_1_HCSPARAMS1		0x04	//Structural Parameters 1 (HCSPARAMS1)
    #define USB30£­MMIO_MAXPORTS			0xFF000000	//04h/x/x/x Number of Ports (MaxPorts)
    #define USB30£­MMIO_HCSP1_RSVD_BIT_23			BIT23	//0/x/x/x HCSPARAMS1 Reserved Bit 23
    #define USB30£­MMIO_HCSP1_RSVD_BIT_22			BIT22	//0/x/x/x HCSPARAMS1 Reserved Bit 22
    #define USB30£­MMIO_HCSP1_RSVD_BIT_21			BIT21	//0/x/x/x HCSPARAMS1 Reserved Bit 21
    #define USB30£­MMIO_HCSP1_RSVD_BIT_20			BIT20	//0/x/x/x HCSPARAMS1 Reserved Bit 20
    #define USB30£­MMIO_HCSP1_RSVD_BIT_19			BIT19	//0/x/x/x HCSPARAMS1 Reserved Bit 19
    #define USB30£­MMIO_MAXINTRS			0x7FF00	//04h/x/x/x Number of Interrupters (MaxIntrs)
    #define USB30£­MMIO_MAXSLOTS			0xFF	//20h/x/x/x Number of Device Slots (MaxSlots) 
#define USB30£­MMIO_STRUCTURAL_PARAMETERS_2_HCSPARAMS2		0x08	//Structural Parameters 2 (HCSPARAMS2)
    #define USB30£­MMIO_MAXSCRBUF_LO			0xF8000000	//1Fh/x/x/x Max Scratchpad Buffers (Max Scratchpad Bufs Lo)
    #define USB30£­MMIO_SPR			BIT26	//1b/x/x/x Scratchpad Restore (SPR)
    #define USB30£­MMIO_MAXSCRBUF_HI			0x3E00000	//0/x/x/x Max Scratchpad Buffers (Max Scratchpad Bufs Hi)
    #define USB30£­MMIO_HCSP2_RSVD_BIT_20			BIT20	//0/x/x/x HCSPARAMS2 Reserved Bit 20
    #define USB30£­MMIO_HCSP2_RSVD_BIT_19			BIT19	//0/x/x/x HCSPARAMS2 Reserved Bit 19
    #define USB30£­MMIO_HCSP2_RSVD_BIT_18			BIT18	//0/x/x/x HCSPARAMS2 Reserved Bit 18
    #define USB30£­MMIO_HCSP2_RSVD_BIT_17			BIT17	//0/x/x/x HCSPARAMS2 Reserved Bit 17
    #define USB30£­MMIO_HCSP2_RSVD_BIT_16			BIT16	//0/x/x/x HCSPARAMS2 Reserved Bit 16
    #define USB30£­MMIO_HCSP2_RSVD_BIT_15			BIT15	//0/x/x/x HCSPARAMS2 Reserved Bit 15
    #define USB30£­MMIO_HCSP2_RSVD_BIT_14			BIT14	//0/x/x/x HCSPARAMS2 Reserved Bit 14
    #define USB30£­MMIO_HCSP2_RSVD_BIT_13			BIT13	//0/x/x/x HCSPARAMS2 Reserved Bit 13
    #define USB30£­MMIO_HCSP2_RSVD_BIT_12			BIT12	//0/x/x/x HCSPARAMS2 Reserved Bit 12
    #define USB30£­MMIO_HCSP2_RSVD_BIT_11			BIT11	//0/x/x/x HCSPARAMS2 Reserved Bit 11
    #define USB30£­MMIO_HCSP2_RSVD_BIT_10			BIT10	//0/x/x/x HCSPARAMS2 Reserved Bit 10
    #define USB30£­MMIO_HCSP2_RSVD_BIT_9			BIT9	//0/x/x/x HCSPARAMS2 Reserved Bit 9
    #define USB30£­MMIO_HCSP2_RSVD_BIT_8			BIT8	//0/x/x/x HCSPARAMS2 Reserved Bit 8
    #define USB30£­MMIO_MAXERST			0xF0	//3h/x/x/x Event Ring Segment Table Max (ERST Max)
    #define USB30£­MMIO_IST			0xF	//1h/x/x/x Isochronous Scheduling Threshold (IST)
#define USB30£­MMIO_STRUCTURAL_PARAMETERS_3_HCSPARAMS3		0x0C	//Structural Parameters 3 (HCSPARAMS3)
    #define USB30£­MMIO_U2DEVEXTLT			0xFFFF0000	//00E7h/x/x/x U2 Device Exit Latency
    #define USB30£­MMIO_HCSP3_RSVD_BIT_15			BIT15	//0/x/x/x HCSPARAMS3 Reserved Bit 15
    #define USB30£­MMIO_HCSP3_RSVD_BIT_14			BIT14	//0/x/x/x HCSPARAMS3 Reserved Bit 14
    #define USB30£­MMIO_HCSP3_RSVD_BIT_13			BIT13	//0/x/x/x HCSPARAMS3 Reserved Bit 13
    #define USB30£­MMIO_HCSP3_RSVD_BIT_12			BIT12	//0/x/x/x HCSPARAMS3 Reserved Bit 12
    #define USB30£­MMIO_HCSP3_RSVD_BIT_11			BIT11	//0/x/x/x HCSPARAMS3 Reserved Bit 11
    #define USB30£­MMIO_HCSP3_RSVD_BIT_10			BIT10	//0/x/x/x HCSPARAMS3 Reserved Bit 10
    #define USB30£­MMIO_HCSP3_RSVD_BIT_9			BIT9	//0/x/x/x HCSPARAMS3 Reserved Bit 9
    #define USB30£­MMIO_HCSP3_RSVD_BIT_8			BIT8	//0/x/x/x HCSPARAMS3 Reserved Bit 8
    #define USB30£­MMIO_U1DEVEXTLT			0xFF	//04h/x/x/x U1 Device Exit Latency
#define USB30£­MMIO_CAP_PARAMETERS_1_HCCPARAMS1		0x10	//Capability Parameters 1 (HCCPARAMS1)
    #define USB30£­MMIO_XECP			0xFFFF0000	//0020h/x/x/x xHCI Extended Capabilities Pointer (xECP) 
    #define USB30£­MMIO_MAXPSASIZE			0xF000	//5h/x/x/x Maximum Primary Stream Array Size (MaxPSASize)
    #define USB30£­MMIO_CFC			BIT11	//1b/x/x/x Contiguous Frame ID Capability (CFC)
    #define USB30£­MMIO_SEC			BIT10	//1b/x/x/x Stopped EDLTA Capability (SEC)
    #define USB30£­MMIO_SPC			BIT9	//1b/x/x/x Stopped - Short Packet Capability (SPC)
    #define USB30£­MMIO_PAE			BIT8	//1b/x/x/x Parse All Event Data (PAE)
    #define USB30£­MMIO_NSS			BIT7	//1b/x/x/x No Secondary SID Support (NSS)
    #define USB30£­MMIO_LTC			BIT6	//1b/x/x/x Latency Tolerance Messaging Capability (LTC)
    #define USB30£­MMIO_LHRC			BIT5	//1b/x/x/x Light HC Reset Capability (LHRC)
    #define USB30£­MMIO_PIND			BIT4	//0/x/x/x Port Indicators (PIND)
    #define USB30£­MMIO_PPC			BIT3	//0/x/x/x Port Power Control (PPC)
    #define USB30£­MMIO_CSZ			BIT2	//0/x/x/x Context Size (CSZ)
    #define USB30£­MMIO_BNC			BIT1	//1b/x/x/x BW Negotiation Capability (BNC)
    #define USB30£­MMIO_AC64			BIT0	//1b/x/x/x 64-bit Addressing Capabilitya (AC64)
#define USB30£­MMIO_DOORBELL_OFFSET_DBOFF		0x14	//Doorbell Offset (DBOFF)
    #define USB30£­MMIO_DBOFF			0xFFFFFFFC	//40h/x/x/x Doorbell Array Offset
    #define USB30£­MMIO_RESERVED			(BIT0 + BIT1)	//0/R/x/x Reserved
#define USB30£­MMIO_RUNTIME_REG_SPACE_OFFSET_RTSOFF		0x18	//Runtime Register Space Offset (RTSOFF)
    #define USB30£­MMIO_RTSOFF			0xFFFFFFE0	//10h/R/x/x Runtime Register Space Offset
    #define USB30£­MMIO_RESERVED_Z1			0x1F	//0/R/x/x Reserved
#define USB30£­MMIO_CAP_PARAMETERS_2_HCCPARAMS2		0x1C	//Capability Parameters 2 (HCCPARAMS2)
    #define USB30£­MMIO_HCCP2_RSVD_BIT_31			BIT31	//0/x/x/x HCCPARAMS2 Reserved Bit 31
    #define USB30£­MMIO_HCCP2_RSVD_BIT_30			BIT30	//0/x/x/x HCCPARAMS2 Reserved Bit 30
    #define USB30£­MMIO_HCCP2_RSVD_BIT_29			BIT29	//0/x/x/x HCCPARAMS2 Reserved Bit 29
    #define USB30£­MMIO_HCCP2_RSVD_BIT_28			BIT28	//0/x/x/x HCCPARAMS2 Reserved Bit 28
    #define USB30£­MMIO_HCCP2_RSVD_BIT_27			BIT27	//0/x/x/x HCCPARAMS2 Reserved Bit 27
    #define USB30£­MMIO_HCCP2_RSVD_BIT_26			BIT26	//0/x/x/x HCCPARAMS2 Reserved Bit 26
    #define USB30£­MMIO_HCCP2_RSVD_BIT_25			BIT25	//0/x/x/x HCCPARAMS2 Reserved Bit 25
    #define USB30£­MMIO_HCCP2_RSVD_BIT_24			BIT24	//0/x/x/x HCCPARAMS2 Reserved Bit 24
    #define USB30£­MMIO_HCCP2_RSVD_BIT_23			BIT23	//0/x/x/x HCCPARAMS2 Reserved Bit 23
    #define USB30£­MMIO_HCCP2_RSVD_BIT_22			BIT22	//0/x/x/x HCCPARAMS2 Reserved Bit 22
    #define USB30£­MMIO_HCCP2_RSVD_BIT_21			BIT21	//0/x/x/x HCCPARAMS2 Reserved Bit 21
    #define USB30£­MMIO_HCCP2_RSVD_BIT_20			BIT20	//0/x/x/x HCCPARAMS2 Reserved Bit 20
    #define USB30£­MMIO_HCCP2_RSVD_BIT_19			BIT19	//0/x/x/x HCCPARAMS2 Reserved Bit 19
    #define USB30£­MMIO_HCCP2_RSVD_BIT_18			BIT18	//0/x/x/x HCCPARAMS2 Reserved Bit 18
    #define USB30£­MMIO_HCCP2_RSVD_BIT_17			BIT17	//0/x/x/x HCCPARAMS2 Reserved Bit 17
    #define USB30£­MMIO_HCCP2_RSVD_BIT_16			BIT16	//0/x/x/x HCCPARAMS2 Reserved Bit 16
    #define USB30£­MMIO_HCCP2_RSVD_BIT_15			BIT15	//0/x/x/x HCCPARAMS2 Reserved Bit 15
    #define USB30£­MMIO_HCCP2_RSVD_BIT_14			BIT14	//0/x/x/x HCCPARAMS2 Reserved Bit 14
    #define USB30£­MMIO_HCCP2_RSVD_BIT_13			BIT13	//0/x/x/x HCCPARAMS2 Reserved Bit 13
    #define USB30£­MMIO_HCCP2_RSVD_BIT_12			BIT12	//0/x/x/x HCCPARAMS2 Reserved Bit 12
    #define USB30£­MMIO_HCCP2_RSVD_BIT_11			BIT11	//0/x/x/x HCCPARAMS2 Reserved Bit 11
    #define USB30£­MMIO_HCCP2_RSVD_BIT_10			BIT10	//0/x/x/x HCCPARAMS2 Reserved Bit 10
    #define USB30£­MMIO_HCCP2_RSVD_BIT_9			BIT9	//0/x/x/x HCCPARAMS2 Reserved Bit 9
    #define USB30£­MMIO_HCCP2_RSVD_BIT_8			BIT8	//0/x/x/x HCCPARAMS2 Reserved Bit 8
    #define USB30£­MMIO_HCCP2_RSVD_BIT_7			BIT7	//0/x/x/x HCCPARAMS2 Reserved Bit 7
    #define USB30£­MMIO_ETC			BIT6	//1b/1b/x/x Extended TBC Capability (ETC) - RO
    #define USB30£­MMIO_CIC			BIT5	//1b/1b/x/x Configuration Information Capability (CIC)
    #define USB30£­MMIO_LEC			BIT4	//1b/1b/x/x Large ESIT Payload Capability (LEC)
    #define USB30£­MMIO_CTC			BIT3	//1b/1b/x/x Compliance Transition Capability (CTC)
    #define USB30£­MMIO_FSC			BIT2	//1b/1b/x/x Force Save Context Capability (FSC)
    #define USB30£­MMIO_CMC			BIT1	//1b/1b/x/x Configure Endpoint Command Max Exit Latency Too Large Capability (CMC)
    #define USB30£­MMIO_U3C			BIT0	//1b/1b/x/x U3 Entry Capability (U3C)
#define USB30£­MMIO_USB_CMD_REG_USBCMD		0x20	//USB Command Register (USBCMD)
    #define USB30£­MMIO_RESERVED_Z2			0xFFFF8000	//0/R/x/x Reserved
    #define USB30£­MMIO_ETE			BIT14	//0/0/x/x Extended TBC Enable (ETE)
    #define USB30£­MMIO_CME			BIT13	//0/0/x/x CEM Enable (CME)
    #define USB30£­MMIO_RESERVED_Z3			BIT12	//0/R/x/x Reserved
    #define USB30£­MMIO_EU3S			BIT11	//0/0/x/x Enable U3 MFINDEX Stop (EU3S) - RW
    #define USB30£­MMIO_EWE			BIT10	//0/0/x/x Enable Wrap Event (EWE) - RW
    #define USB30£­MMIO_CRS			BIT9	//0/0/x/x Controller Restore State (CRS) - RW
    #define USB30£­MMIO_CSS			BIT8	//0/0/x/x Controller Save State (CSS) - RWS
    #define USB30£­MMIO_LHCRST			BIT7	//0/0/x/x Light Host Controller Reset (LHCRST) - RW
    #define USB30£­MMIO_RESERVED_Z4			(BIT4 + BIT5 + BIT6)	//0/R/x/x Reserved
    #define USB30£­MMIO_HSEE			BIT3	//0/0/x/x Host System Error Enable (HSEE) - RW
    #define USB30£­MMIO_INTE			BIT2	//0/0/x/x Interrupter Enable (INTE) - RW
    #define USB30£­MMIO_HCRST			BIT1	//0/0/x/x Host Controller Reset (HCRST) - RW
    #define USB30£­MMIO_RUNSTOP			BIT0	//0/x/x/x Run/Stop (R/S) - RW
#define USB30£­MMIO_USB_STA_REG_USBSTS		0x24	//USB Status Register (USBSTS)
    #define USB30£­MMIO_RESERVED_Z5			0xFFFFE000	//0/R/x/x Reserved
    #define USB30£­MMIO_HCE			BIT12	//0/x/x/x Host Controller Error (HCE) - RO
    #define USB30£­MMIO_CNR			BIT11	//1b/x/x/x Controller Not Ready (CNR) - RO
    #define USB30£­MMIO_SRE			BIT10	//0/x/x/x Save/Restore Error (SRE) - RW1C
    #define USB30£­MMIO_RSS			BIT9	//0/x/x/x Restore State Status (RSS) - RO
    #define USB30£­MMIO_SSS			BIT8	//0/x/x/x Save State Status (SSS) - RO
    #define USB30£­MMIO_RESERVED_Z6			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define USB30£­MMIO_PCD			BIT4	//0/x/x/x Port Change Detect (PCD) - RW1C
    #define USB30£­MMIO_EINT			BIT3	//0/x/x/x Event Interrupt (EINT) - RW1C
    #define USB30£­MMIO_HSE			BIT2	//0/x/x/x Host System Error (HSE) - RW1C
    #define USB30£­MMIO_RESERVED_Z7			BIT1	//0/R/x/x Reserved
    #define USB30£­MMIO_HCHALTED			BIT0	//1b/x/x/x HCHalted (HCH) - RO
#define USB30£­MMIO_PAGE_SIZE_REG_PAGESIZE		0x28	//Page Size Register (PAGESIZE)
    #define USB30£­MMIO_RESERVED_Z8			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_PAGESIZE			0xFFFF	//0001h/x/x/x Page Size - RO
#define USB30£­MMIO_DEV_NOTIFICATION_CTL_REG_DNCTRL		0x34	//Device Notification Control Register (DNCTRL)
    #define USB30£­MMIO_RESERVED_Z9			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_DNCTRL			0xFFFF	//0/0/x/x Notification Enable (N0-N15) - RW
#define USB30£­MMIO_CMD_RING_CTL_REG_0_CRCR0		0x38	//Command Ring Control Register 0 (CRCR0)
    #define USB30£­MMIO_CDRINGPOINTERLO			0xFFFFFFC0	//0/0/x/x Command Ring Pointer (Low 32 Bits) - RW
    #define USB30£­MMIO_RESERVED_Z10			(BIT4 + BIT5)	//0/R/x/x Reserved
    #define USB30£­MMIO_CRR			BIT3	//0/x/x/x Command Ring Running (CRR) - RO
    #define USB30£­MMIO_CA			BIT2	//0/0/x/x Command Abort (CA) - RW
    #define USB30£­MMIO_CS			BIT1	//0/0/x/x Command Stop (CS) - RW
    #define USB30£­MMIO_RCS			BIT0	//0/0/x/x Ring Cycle State (RCS) - RW
#define USB30£­MMIO_CMD_RING_CTL_REG_1_CRCR1		0x3C	//Command Ring Control Register 1 (CRCR1)
    #define USB30£­MMIO_CDRINGPOINTERHI			0xFFFFFFFF	//0/0/x/x Command Ring Pointer (High 32 Bits) - RW
#define USB30£­MMIO_DEV_CONTEXT_BASE_ADR_ARRAY_POINTER_REG_0_DCBAAP0		0x50	//Device Context Base Address Array Pointer Register 0 (DCBAAP0)
    #define USB30£­MMIO_DCBAAPLO			0xFFFFFFC0	//0/x/x/x Device Context Base Address Array Pointer (Low 32 Bits) - RW
    #define USB30£­MMIO_RESERVED_Z11			0x3F	//0/R/x/x Reserved
#define USB30£­MMIO_DEV_CONTEXT_BASE_ADR_ARRAY_POINTER_REG_1_DCBAAP1		0x54	//Device Context Base Address Array Pointer Register 1 (DCBAAP1)
    #define USB30£­MMIO_DCBAAPHI			0xFFFFFFFF	//0/x/x/x Device Context Base Address Array Pointer (High 32 Bits) - RW
#define USB30£­MMIO_CONFIGURE_REG_CONFIG		0x58	//Configure Register (CONFIG)
    #define USB30£­MMIO_RESERVED_Z12			0xFFFFFC00	//0/R/x/x Reserved
    #define USB30£­MMIO_CIE			BIT9	//0/0/x/x Configuration Information Enable (CIE)
    #define USB30£­MMIO_U3E			BIT8	//0/0/x/x U3 Entry Enable (U3E)
    #define USB30£­MMIO_MAXSLOTEN			0xFF	//0/x/x/x Max Device Slots Enabled (MaxSlotsEn) - RW
#define USB30£­MMIO_USB_LEGACY_SUPPORT_CAP_REG_USBLEGSUP		0x80	//USB Legacy Support Capability Register (USBLEGSUP)
    #define USB30£­MMIO_RESERVED_Z13			0xFE000000	//0/R/x/x Reserved
    #define USB30£­MMIO_HCOSOWNS			BIT24	//0/0/x/x HC OS Owned Semaphore - RW
    #define USB30£­MMIO_RESERVED_Z14			0xFE0000	//0/R/x/x Reserved
    #define USB30£­MMIO_HCBIOSOWNS			BIT16	//0/x/x/x HC BIOS Owned Semaphore - RW
    #define USB30£­MMIO_USBLEGNXTPTR			0xFF00	//08h/x/x/x Next Capability Pointer - RO
    #define USB30£­MMIO_USBLEGID			0xFF	//01h/x/x/x Capability ID - RO
#define USB30£­MMIO_USB_LEGACY_SUPPORT_CTL_AND_STA_REG_USBLEGCTLSTS		0x84	//USB Legacy Support Control and Status Register (USBLEGCTLSTS)
    #define USB30£­MMIO_SMIONBAR			BIT31	//0/x/x/x SMI on BAR - RW1C
    #define USB30£­MMIO_SMIONPCMD			BIT30	//0/x/x/x SMI on PCI Command - RW1C
    #define USB30£­MMIO_SMIOSOWNCHG			BIT29	//0/x/x/x SMI on OS Ownership Change - RW1C
    #define USB30£­MMIO_RESERVED_Z15			0x1FE00000	//0/R/x/x Reserved
    #define USB30£­MMIO_SMIHSERR			BIT20	//0/x/x/x SMI on Host System Error - RO
    #define USB30£­MMIO_RESERVED_Z16			(BIT17 + BIT18 + BIT19)	//0/R/x/x Reserved
    #define USB30£­MMIO_SMIEVENTINT			BIT16	//0/x/x/x SMI on Event Interrupt - RO
    #define USB30£­MMIO_SMIONBAREN			BIT15	//0/0/x/x SMI on BAR Enable - RW
    #define USB30£­MMIO_SMIONPCMDEN			BIT14	//0/0/x/x SMI on PCI Command Enable - RW
    #define USB30£­MMIO_SMIOSOWNEN			BIT13	//0/0/x/x SMI on OS Ownership Enable - RW
    #define USB30£­MMIO_RESERVED_Z17			0x1FE0	//0/R/x/x Reserved
    #define USB30£­MMIO_SMIHSERREN			BIT4	//0/0/x/x SMI on Host System Error Enable - RW
    #define USB30£­MMIO_RESERVED_Z18			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define USB30£­MMIO_USBSMIEN			BIT0	//0/0/x/x USB SMI Enable - RW
#define USB30£­MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_EXTENDED_CAP_USB2PROTOCOLCAP		0xA0	//xHCI Supported USB2.0 Protocol Extended Capability (USB2PROTOCOLCAP)
    #define USB30£­MMIO_USB2PRTMAJREV			0xFF000000	//02h/x/x/x Major Revision - RO
    #define USB30£­MMIO_USB2PRTMINREV			0xFF0000	//00h/x/x/x Minor Revision - RO
    #define USB30£­MMIO_USB2PRTNXTPTR			0xFF00	//08h/x/x/x Next Capability Pointer - RO
    #define USB30£­MMIO_USB2PRTID			0xFF	//02h/x/x/x Capability ID - RO
#define USB30£­MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_NAMING_STRING_USB2PROTOCOLNAMESTR		0xA4	//xHCI Supported USB2.0 Protocol Naming String (USB2PROTOCOLNAMESTR)
    #define USB30£­MMIO_USB2NAMESTR			0xFFFFFFFF	//20425355h/x/x/x Name String - RO
#define USB30£­MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_CAP_USB2PROTOCOLCAP		0xA8	//xHCI Supported USB2.0 Protocol Capability (USB2PROTOCOLCAP)
    #define USB30£­MMIO_USB2PSIC			0xF0000000	//3h/x/x/x Protocol Speed ID Count (PSIC) - RO
    #define USB30£­MMIO_USB2MHD			(BIT25 + BIT26 + BIT27)	//0/0/x/x Hub Depth (MHD) - RO
    #define USB30£­MMIO_USB2PC2_RSVD_BIT_24			BIT24	//0/x/x/x USB2.0 Protocol Capability Reserved Bit 24
    #define USB30£­MMIO_USB2PC2_RSVD_BIT_23			BIT23	//0/x/x/x USB2.0 Protocol Capability Reserved Bit 23
    #define USB30£­MMIO_USB2PC2_RSVD_BIT_22			BIT22	//0/x/x/x USB2.0 Protocol Capability Reserved Bit 22
    #define USB30£­MMIO_USB2PC2_RSVD_BIT_21			BIT21	//0/x/x/x USB2.0 Protocol Capability Reserved Bit 21
    #define USB30£­MMIO_BLC			BIT20	//1b/x/x/x BESL LPM Capability (BLC) - RO
    #define USB30£­MMIO_HLC			BIT19	//1b/x/x/x Hardware LMP Capability (HLC) - RO
    #define USB30£­MMIO_IHI			BIT18	//0b/x/x/x Integrated Hub Implemented (IHI) - RO
    #define USB30£­MMIO_HSO			BIT17	//0b/x/x/x High-Speed Only (HSO) - RO
    #define USB30£­MMIO_USB2PC2_RSVD_BIT_16			BIT16	//0b/x/x/x USB2.0 Protocol Capability Reserved Bit 16
    #define USB30£­MMIO_USB2PORTCNT			0xFF00	//02h/x/x/x Compatible Port Count - RO
    #define USB30£­MMIO_USB2PORTOFF			0xFF	//01h/x/x/x Compatible Port Offset - RO
#define USB30£­MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_CAP_USB2PROTOCOLPST		0xAC	//xHCI Supported USB2.0 Protocol Capability (USB2PROTOCOLPST)
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_31			BIT31	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 31
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_30			BIT30	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 30
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_29			BIT29	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 29
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_28			BIT28	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 28
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_27			BIT27	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 27
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_26			BIT26	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 26
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_25			BIT25	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 25
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_24			BIT24	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 24
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_23			BIT23	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 23
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_22			BIT22	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 22
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_21			BIT21	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 21
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_20			BIT20	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 20
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_19			BIT19	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 19
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_18			BIT18	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 18
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_17			BIT17	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 17
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_16			BIT16	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 16
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_15			BIT15	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 15
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_14			BIT14	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 14
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_13			BIT13	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 13
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_12			BIT12	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 12
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_11			BIT11	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 11
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_10			BIT10	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 10
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_9			BIT9	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 9
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_8			BIT8	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 8
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_7			BIT7	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 7
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_6			BIT6	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 6
    #define USB30£­MMIO_USB2PC3_RSVD_BIT_5			BIT5	//0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 5
    #define USB30£­MMIO_USB2PST			0x1F	//0/x/x/x Protocol Slot Type
#define USB30£­MMIO_XHCI_USB2PSI1_HIGH_SPEED		0xB0	//xHCI USB2PSI1 (High Speed)
    #define USB30£­MMIO_USB2PSIM1			0xFFFF0000	//1E0h/x/x/x Protocol Speed ID Mantissa (PSIM)
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_15			BIT15	//0/0/x/x USB2PSI1 Reserved Bit 15
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_14			BIT14	//0/0/x/x USB2PSI1 Reserved Bit 14
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_13			BIT13	//0/0/x/x USB2PSI1 Reserved Bit 13
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_12			BIT12	//0/0/x/x USB2PSI1 Reserved Bit 12
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_11			BIT11	//0/0/x/x USB2PSI1 Reserved Bit 11
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_10			BIT10	//0/0/x/x USB2PSI1 Reserved Bit 10
    #define USB30£­MMIO_USB2PSI1_RSVD_BIT_9			BIT9	//0/0/x/x USB2PSI1 Reserved Bit 9
    #define USB30£­MMIO_USB2PFD1			BIT8	//0/x/x/x PSI Full-duplex (PFD)
    #define USB30£­MMIO_USB2PLT1			(BIT6 + BIT7)	//0/x/x/x PSI Type (PLT)
    #define USB30£­MMIO_USB2PSIE1			(BIT4 + BIT5)	//10b/x/x/x Protocol Speed ID Exponent (PSIE)
    #define USB30£­MMIO_USB2PSIV1			0xF	//3h/x/x/x Protocol Speed ID Value (PSIV)
#define USB30£­MMIO_XHCI_USB2PSI2_FULL_SPEED		0xB4	//xHCI USB2PSI2 (Full Speed)
    #define USB30£­MMIO_USB2PSIM2			0xFFFF0000	//000Ch/x/x/x Protocol Speed ID Mantissa (PSIM)
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_15			BIT15	//0/0/x/x USB2PSI2 Reserved Bit 15
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_14			BIT14	//0/0/x/x USB2PSI2 Reserved Bit 14
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_13			BIT13	//0/0/x/x USB2PSI2 Reserved Bit 13
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_12			BIT12	//0/0/x/x USB2PSI2 Reserved Bit 12
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_11			BIT11	//0/0/x/x USB2PSI2 Reserved Bit 11
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_10			BIT10	//0/0/x/x USB2PSI2 Reserved Bit 10
    #define USB30£­MMIO_USB2PSI2_RSVD_BIT_9			BIT9	//0/0/x/x USB2PSI2 Reserved Bit 9
    #define USB30£­MMIO_USB2PFD2			BIT8	//0/x/x/x PSI Full-duplex (PFD)
    #define USB30£­MMIO_USB2PLT2			(BIT6 + BIT7)	//0/x/x/x PSI Type (PLT)
    #define USB30£­MMIO_USB2PSIE2			(BIT4 + BIT5)	//10b/x/x/x Protocol Speed ID Exponent (PSIE)
    #define USB30£­MMIO_USB2PSIV2			0xF	//1h/x/x/x Protocol Speed ID Value (PSIV)
#define USB30£­MMIO_XHCI_USB2PSI3_LOW_SPEED		0xB8	//xHCI USB2PSI3 (Low Speed)
    #define USB30£­MMIO_USB2PSIM3			0xFFFF0000	//05DCh/x/x/x Protocol Speed ID Mantissa (PSIM)
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_15			BIT15	//0/0/x/x USB2PSI3 Reserved Bit 15
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_14			BIT14	//0/0/x/x USB2PSI3 Reserved Bit 14
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_13			BIT13	//0/0/x/x USB2PSI3 Reserved Bit 13
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_12			BIT12	//0/0/x/x USB2PSI3 Reserved Bit 12
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_11			BIT11	//0/0/x/x USB2PSI3 Reserved Bit 11
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_10			BIT10	//0/0/x/x USB2PSI3 Reserved Bit 10
    #define USB30£­MMIO_USB2PSI3_RSVD_BIT_9			BIT9	//0/0/x/x USB2PSI3 Reserved Bit 9
    #define USB30£­MMIO_USB2PFD3			BIT8	//0/x/x/x PSI Full-duplex (PFD)
    #define USB30£­MMIO_USB2PLT3			(BIT6 + BIT7)	//0/x/x/x PSI Type (PLT)
    #define USB30£­MMIO_USB2PSIE3			(BIT4 + BIT5)	//01b/x/x/x Protocol Speed ID Exponent (PSIE)
    #define USB30£­MMIO_USB2PSIV3			0xF	//2h/x/x/x Protocol Speed ID Value (PSIV)
#define USB30£­MMIO_XHCI_RESERVED_USB2PSI4		0xBC	//xHCI Reserved USB2PSI4
    #define USB30£­MMIO_USB2PSI4			0xFFFFFFFF	//0/x/x/x USB2PSI4
#define USB30£­MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_EXTENDED_CAP_USB3PROTOCOLCAP		0xC0	//xHCI Supported USB3.0 Protocol Extended Capability (USB3PROTOCOLCAP)
    #define USB30£­MMIO_USB3PRTMAJREV			0xFF000000	//03h/x/x/x Major Revision - RO
    #define USB30£­MMIO_USB3PRTMINREV			0xFF0000	//10h/x/x/x Minor Revision - RO
    #define USB30£­MMIO_USB3PRTNXTPTR			0xFF00	//90h/x/x/x Next Capability Pointer - RO
    #define USB30£­MMIO_USB3PRTID			0xFF	//02h/x/x/x Capability ID - RO
#define USB30£­MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_NAMING_STRING_USB3PROTOCOLNAMESTR		0xC4	//xHCI Supported USB3.0 Protocol Naming String (USB3PROTOCOLNAMESTR)
    #define USB30£­MMIO_USB3NAMESTR			0xFFFFFFFF	//20425355h/x/x/x Name String - RO
#define USB30£­MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_CAP_USB3PROTOCOLCAP		0xC8	//xHCI Supported USB3.0 Protocol Capability (USB3PROTOCOLCAP)
    #define USB30£­MMIO_USB3PSIC			0xF0000000	//1h/x/x/x Protocol Speed ID Count (PSIC) - RO
    #define USB30£­MMIO_USB3MHD			(BIT25 + BIT26 + BIT27)	//0/0/x/x Hub Depth (MHD) - RO
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_24			BIT24	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 24
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_23			BIT23	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 23
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_22			BIT22	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 22
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_21			BIT21	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 21
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_20			BIT20	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 20
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_19			BIT19	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 19
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_18			BIT18	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 18
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_17			BIT17	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 17
    #define USB30£­MMIO_USB3PC2_RSVD_BIT_16			BIT16	//0/0/x/x USB3.0 Protocol Capability Reserved Bit 16
    #define USB30£­MMIO_USB3PORTCNT			0xFF00	//02h/x/x/x Compatible Port Count - RO
    #define USB30£­MMIO_USB3PORTOFF			0xFF	//03h/x/x/x Compatible Port Offset - RO
#define USB30£­MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_CAP_USB3PROTOCOLPST		0xCC	//xHCI Supported USB3.0 Protocol Capability (USB3PROTOCOLPST)
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_31			BIT31	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 31
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_30			BIT30	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 30
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_29			BIT29	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 29
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_28			BIT28	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 28
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_27			BIT27	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 27
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_26			BIT26	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 26
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_25			BIT25	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 25
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_24			BIT24	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 24
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_23			BIT23	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 23
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_22			BIT22	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 22
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_21			BIT21	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 21
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_20			BIT20	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 20
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_19			BIT19	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 19
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_18			BIT18	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 18
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_17			BIT17	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 17
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_16			BIT16	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 16
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_15			BIT15	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 15
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_14			BIT14	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 14
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_13			BIT13	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 13
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_12			BIT12	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 12
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_11			BIT11	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 11
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_10			BIT10	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 10
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_9			BIT9	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 9
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_8			BIT8	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 8
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_7			BIT7	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 7
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_6			BIT6	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 6
    #define USB30£­MMIO_USB3PC3_RSVD_BIT_5			BIT5	//0/x/x/x USB3.0 Protocol Capability Reserved Bit 5
    #define USB30£­MMIO_USB3PST			0x1F	//0/x/x/x Protocol Slot Type
#define USB30£­MMIO_XHCI_USB3PSI1_SUPER_SPEED		0xD0	//xHCI USB3PSI1 (Super Speed)
    #define USB30£­MMIO_USB3PSIM1			0xFFFF0000	//5h/x/x/x Protocol Speed ID Mantissa (PSIM)
    #define USB30£­MMIO_USB3LP1			(BIT14 + BIT15)	//0/0/x/x Link Protocol (LP) - RO. 
    #define USB30£­MMIO_USB3PSI1_RSVD_BIT_13			BIT13	//0/0/x/x USB3PSI1 Reserved Bit 13
    #define USB30£­MMIO_USB3PSI1_RSVD_BIT_12			BIT12	//0/0/x/x USB3PSI1 Reserved Bit 12
    #define USB30£­MMIO_USB3PSI1_RSVD_BIT_11			BIT11	//0/0/x/x USB3PSI1 Reserved Bit 11
    #define USB30£­MMIO_USB3PSI1_RSVD_BIT_10			BIT10	//0/0/x/x USB3PSI1 Reserved Bit 10
    #define USB30£­MMIO_USB3PSI1_RSVD_BIT_9			BIT9	//0/0/x/x USB3PSI1 Reserved Bit 9
    #define USB30£­MMIO_USB3PFD1			BIT8	//1b/x/x/x PSI Full-duplex (PFD)
    #define USB30£­MMIO_USB3PLT1			(BIT6 + BIT7)	//0/x/x/x PSI Type (PLT)
    #define USB30£­MMIO_USB3PSIE1			(BIT4 + BIT5)	//11b/x/x/x Protocol Speed ID Exponent (PSIE)
    #define USB30£­MMIO_USB3PSIV1			0xF	//4h/x/x/x Protocol Speed ID Value (PSIV)
#define USB30£­MMIO_XHCI_RESERVED_USB3PSI2		0xD4	//xHCI Reserved USB3PSI2
    #define USB30£­MMIO_USB3PSI2			0xFFFFFFFF	//0h/x/x/x USB3PSI2
#define USB30£­MMIO_XHCI_RESERVED_USB3PSI3		0xD8	//xHCI Reserved USB3PSI3
    #define USB30£­MMIO_USB3PSI3			0xFFFFFFFF	//0h/x/x/x USB3PSI3
#define USB30£­MMIO_XHCI_RESERVED_USB3PSI4		0xDC	//xHCI Reserved USB3PSI4
    #define USB30£­MMIO_USB3PSI4			0xFFFFFFFF	//0h/x/x/x USB3PSI4
#define USB30£­MMIO_CMD_RING_DOORBELL_REG		0x100	//Command Ring Doorbell Register
    #define USB30£­MMIO_DBSTMID0			0xFFFF0000	//0/0/x/x DB Stream ID - RW
    #define USB30£­MMIO_RESERVED_Z19			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET0			0xFF	//0/0/x/x DB Target - RW
#define USB30£­MMIO_DEV_SLOT_1_DOORBELL_REG		0x104	//Device Slot 1 Doorbell Register
    #define USB30£­MMIO_DBSTMID1			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z20			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET1			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_2_DOORBELL_REG		0x108	//Device Slot 2 Doorbell Register
    #define USB30£­MMIO_DBSTMID2			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z21			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET2			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_3_DOORBELL_REG		0x10C	//Device Slot 3 Doorbell Register
    #define USB30£­MMIO_DBSTMID3			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z22			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET3			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_4_DOORBELL_REG		0x110	//Device Slot 4 Doorbell Register
    #define USB30£­MMIO_DBSTMID4			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z23			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET4			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_5_DOORBELL_REG		0x114	//Device Slot 5 Doorbell Register
    #define USB30£­MMIO_DBSTMID5			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z24			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET5			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_6_DOORBELL_REG		0x118	//Device Slot 6 Doorbell Register
    #define USB30£­MMIO_DBSTMID6			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z25			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET6			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_7_DOORBELL_REG		0x11C	//Device Slot 7 Doorbell Register
    #define USB30£­MMIO_DBSTMID7			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z26			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET7			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_8_DOORBELL_REG		0x120	//Device Slot 8 Doorbell Register
    #define USB30£­MMIO_DBSTMID8			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z27			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET8			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_9_DOORBELL_REG		0x124	//Device Slot 9 Doorbell Register
    #define USB30£­MMIO_DBSTMID9			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z28			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET9			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_10_DOORBELL_REG		0x128	//Device Slot 10 Doorbell Register
    #define USB30£­MMIO_DBSTMID10			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z29			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET10			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_11_DOORBELL_REG		0x12C	//Device Slot 11 Doorbell Register
    #define USB30£­MMIO_DBSTMID11			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z30			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET11			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_12_DOORBELL_REG		0x130	//Device Slot 12 Doorbell Register
    #define USB30£­MMIO_DBSTMID12			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z31			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET12			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_13_DOORBELL_REG		0x134	//Device Slot 13 Doorbell Register
    #define USB30£­MMIO_DBSTMID13			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z32			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET13			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_14_DOORBELL_REG		0x138	//Device Slot 14 Doorbell Register
    #define USB30£­MMIO_DBSTMID14			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z33			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET14			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_15_DOORBELL_REG		0x13C	//Device Slot 15 Doorbell Register
    #define USB30£­MMIO_DBSTMID15			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z34			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET15			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_16_DOORBELL_REG		0x140	//Device Slot 16 Doorbell Register
    #define USB30£­MMIO_DBSTMID16			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z35			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET16			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_17_DOORBELL_REG		0x144	//Device Slot 17 Doorbell Register
    #define USB30£­MMIO_DBSTMID17			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z36			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET17			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_18_DOORBELL_REG		0x148	//Device Slot 18 Doorbell Register
    #define USB30£­MMIO_DBSTMID18			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z37			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET18			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_19_DOORBELL_REG		0x14C	//Device Slot 19 Doorbell Register
    #define USB30£­MMIO_DBSTMID19			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z38			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET19			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_20_DOORBELL_REG		0x150	//Device Slot 20 Doorbell Register
    #define USB30£­MMIO_DBSTMID20			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z39			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET20			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_21_DOORBELL_REG		0x154	//Device Slot 21 Doorbell Register
    #define USB30£­MMIO_DBSTMID21			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z40			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET21			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_22_DOORBELL_REG		0x158	//Device Slot 22 Doorbell Register
    #define USB30£­MMIO_DBSTMID22			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z41			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET22			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_23_DOORBELL_REG		0x15C	//Device Slot 23 Doorbell Register
    #define USB30£­MMIO_DBSTMID23			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z42			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET23			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_24_DOORBELL_REG		0x160	//Device Slot 24 Doorbell Register
    #define USB30£­MMIO_DBSTMID24			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z43			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET24			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_25_DOORBELL_REG		0x164	//Device Slot 25 Doorbell Register
    #define USB30£­MMIO_DBSTMID25			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z44			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET25			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_26_DOORBELL_REG		0x168	//Device Slot 26 Doorbell Register
    #define USB30£­MMIO_DBSTMID26			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z45			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET26			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_27_DOORBELL_REG		0x16C	//Device Slot 27 Doorbell Register
    #define USB30£­MMIO_DBSTMID27			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z46			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET27			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_28_DOORBELL_REG		0x170	//Device Slot 28 Doorbell Register
    #define USB30£­MMIO_DBSTMID28			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z47			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET28			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_29_DOORBELL_REG		0x174	//Device Slot 29 Doorbell Register
    #define USB30£­MMIO_DBSTMID29			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z48			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET29			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_30_DOORBELL_REG		0x178	//Device Slot 30 Doorbell Register
    #define USB30£­MMIO_DBSTMID30			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z49			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET30			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_31_DOORBELL_REG		0x17C	//Device Slot 31 Doorbell Register
    #define USB30£­MMIO_DBSTMID31			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z50			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET31			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_DEV_SLOT_32_DOORBELL_REG		0x180	//Device Slot 32 Doorbell Register
    #define USB30£­MMIO_DBSTMID32			0xFFFF0000	//0/0/x/x DB Stream ID
    #define USB30£­MMIO_RESERVED_Z51			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DBTARGET32			0xFF	//0/0/x/x DB Target
#define USB30£­MMIO_MICROFRAME_INDEX_REG_MFINDEX		0x200	//Microframe Index Register (MFINDEX)
    #define USB30£­MMIO_RESERVED_Z52			0xFFFFC000	//0/R/x/x Reserved
    #define USB30£­MMIO_MFINDEX			0x3FFF	//0/x/x/x Microframe Index - RO
#define USB30£­MMIO_INTRER_0_MANAGEMENT_REG_IMAN0		0x220	//Interrupter 0 Management Register (IMAN0)
    #define USB30£­MMIO_RESERVED_Z53			0xFFFFFFFC	//0/x/x/x Reserved
    #define USB30£­MMIO_INTEN0			BIT1	//0/x/x/x Interrupt Enable (IE) - RW 
    #define USB30£­MMIO_INTPENDING0			BIT0	//0/x/x/x Interrupt Pending (IP) - RW1C
#define USB30£­MMIO_INTRER_0_MODERATION_REG_IMOD0		0x224	//Interrupter 0 Moderation Register (IMOD0)
    #define USB30£­MMIO_IMODC0			0xFFFF0000	//0/0/x/x Interrupt Moderation Counter (IMODC) - RW
    #define USB30£­MMIO_IMODI0			0xFFFF	//0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) - RW
#define USB30£­MMIO_EVENT_RING_0_SEGMENT_TABLE_SIZE_REG_ER0STSZ		0x228	//Event Ring 0 Segment Table Size Register (ER0STSZ)
    #define USB30£­MMIO_RESERVED_Z54			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_ER0STSZ			0xFFFF	//0/x/x/x Event Ring Segment Table Size - RW
#define USB30£­MMIO_EVENT_RING_0_SEGMENT_TABLE_BASE_ADR_REG_0_ER0STBA0		0x230	//Event Ring 0 Segment Table Base Address Register 0 (ER0STBA0)
    #define USB30£­MMIO_ER0STBALO			0xFFFFFFC0	//0/x/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) - RW
    #define USB30£­MMIO_RESERVED_Z55			0x3F	//0/R/x/x Reserved
#define USB30£­MMIO_EVENT_RING_0_SEGMENT_TABLE_BASE_ADR_REG_1_ER0STBA1		0x234	//Event Ring 0 Segment Table Base Address Register 1 (ER0STBA1)
    #define USB30£­MMIO_ER0STBAHI			0xFFFFFFFF	//0/x/x/x Event Ring Segment Table Base Address Register (High 32 Bits) - RW
#define USB30£­MMIO_EVENT_RING_0_DEQUEUE_POINTER_REG_0_ER0DP0		0x238	//Event Ring 0 Dequeue Pointer Register 0 (ER0DP0)
    #define USB30£­MMIO_ER0DPLO			0xFFFFFFF0	//0/x/x/x Dequeue Pointer (Low 32 Bits) - RW
    #define USB30£­MMIO_EHB0			BIT3	//0/x/x/x Event Handler Busy (EHB) - RW1C
    #define USB30£­MMIO_DESI0			(BIT0 + BIT1 + BIT2)	//0/x/x/x Dequeue ERST Segment Index (DESI)
#define USB30£­MMIO_EVENT_RING_0_DEQUEUE_POINTER_REG_1_ER0DP1		0x23C	//Event Ring 0 Dequeue Pointer Register 1 (ER0DP1)
    #define USB30£­MMIO_ER0DPHI			0xFFFFFFFF	//0/x/x/x Dequeue Pointer (High 32 Bits) - RW
#define USB30£­MMIO_INTRER_1_MANAGEMENT_REG_IMAN1		0x240	//Interrupter 1 Management Register (IMAN1)
    #define USB30£­MMIO_RESERVED_Z56			0xFFFFFFFC	//0/R/x/x Reserved
    #define USB30£­MMIO_INTEN1			BIT1	//0/x/x/x Interrupt Enable (IE) - RW
    #define USB30£­MMIO_INTPENDING1			BIT0	//0/x/x/x Interrupt Pending (IP) - RW1C
#define USB30£­MMIO_INTRER_1_MODERATION_REG_IMOD1		0x244	//Interrupter 1 Moderation Register (IMOD1)
    #define USB30£­MMIO_IMODC1			0xFFFF0000	//0/0/x/x Interrupt Moderation Counter (IMODC) - RW
    #define USB30£­MMIO_IMODI1			0xFFFF	//0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) - RW. 
#define USB30£­MMIO_EVENT_RING_1_SEGMENT_TABLE_SIZE_REG_ER1STSZ		0x248	//Event Ring 1 Segment Table Size Register (ER1STSZ)
    #define USB30£­MMIO_RESERVED_Z57			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_ER1STSZ			0xFFFF	//0/x/x/x Event Ring Segment Table Size - RW
#define USB30£­MMIO_EVENT_RING_1_SEGMENT_TABLE_BASE_ADR_REG_0_ER1STBA0		0x250	//Event Ring 1 Segment Table Base Address Register 0 (ER1STBA0)
    #define USB30£­MMIO_ER1STBALO			0xFFFFFFC0	//0/x/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) - RW
    #define USB30£­MMIO_RESERVED_Z58			0x3F	//0/R/x/x Reserved
#define USB30£­MMIO_EVENT_RING_1_SEGMENT_TABLE_BASE_ADR_REG_1_ER1STBA1		0x254	//Event Ring 1 Segment Table Base Address Register 1 (ER1STBA1)
    #define USB30£­MMIO_ER1STBAHI			0xFFFFFFFF	//0/x/x/x Event Ring Segment Table Base Address Register (High 32 Bits) - RW
#define USB30£­MMIO_EVENT_RING_1_DEQUEUE_POINTER_REG_0_ER1DP0		0x258	//Event Ring 1 Dequeue Pointer Register 0 (ER1DP0)
    #define USB30£­MMIO_ER1DPLO			0xFFFFFFF0	//0/x/x/x Dequeue Pointer (Low 32 Bits) - RW
    #define USB30£­MMIO_EHB1			BIT3	//0/x/x/x Event Handler Busy (EHB) - RW1C
    #define USB30£­MMIO_DESI1			(BIT0 + BIT1 + BIT2)	//0/x/x/x Dequeue ERST Segment Index (DESI)
#define USB30£­MMIO_EVENT_RING_1_DEQUEUE_POINTER_REG_1_ER1DP1		0x25C	//Event Ring 1 Dequeue Pointer Register 1 (ER1DP1)
    #define USB30£­MMIO_ER1DPHI			0xFFFFFFFF	//0/x/x/x Dequeue Pointer (High 32 Bits) - RW
#define USB30£­MMIO_INTRER_2_MANAGEMENT_REG_IMAN2		0x260	//Interrupter 2 Management Register (IMAN2)
    #define USB30£­MMIO_RESERVED_Z59			0xFFFFFFFC	//0/R/x/x Reserved
    #define USB30£­MMIO_INTEN2			BIT1	//0/x/x/x Interrupt Enable (IE) - RW
    #define USB30£­MMIO_INTPENDING2			BIT0	//0/x/x/x Interrupt Pending (IP) - RW1C
#define USB30£­MMIO_INTRER_2_MODERATION_REG_IMOD2		0x264	//Interrupter 2 Moderation Register (IMOD2)
    #define USB30£­MMIO_IMODC2			0xFFFF0000	//0/0/x/x Interrupt Moderation Counter (IMODC) - RW
    #define USB30£­MMIO_IMODI2			0xFFFF	//0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) - RW. 
#define USB30£­MMIO_EVENT_RING_2_SEGMENT_TABLE_SIZE_REG_ER2STSZ		0x268	//Event Ring 2 Segment Table Size Register (ER2STSZ)
    #define USB30£­MMIO_RESERVED_Z60			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_ER2STSZ			0xFFFF	//0/x/x/x Event Ring Segment Table Size - RW
#define USB30£­MMIO_EVENT_RING_2_SEGMENT_TABLE_BASE_ADR_REG_0_ER2STBA0		0x270	//Event Ring 2 Segment Table Base Address Register 0 (ER2STBA0)
    #define USB30£­MMIO_ER2STBALO			0xFFFFFFC0	//0/x/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) - RW
    #define USB30£­MMIO_RESERVED_Z61			0x3F	//0/R/x/x Reserved
#define USB30£­MMIO_EVENT_RING_2_SEGMENT_TABLE_BASE_ADR_REG_1_ER2STBA1		0x274	//Event Ring 2 Segment Table Base Address Register 1 (ER2STBA1)
    #define USB30£­MMIO_ER2STBAHI			0xFFFFFFFF	//0/x/x/x Event Ring Segment Table Base Address Register (High 32 Bits) - RW
#define USB30£­MMIO_EVENT_RING_2_DEQUEUE_POINTER_REG_0_ER2DP0		0x278	//Event Ring 2 Dequeue Pointer Register 0 (ER2DP0)
    #define USB30£­MMIO_ER2DPLO			0xFFFFFFF0	//0/x/x/x Dequeue Pointer (Low 32 Bits) - RW
    #define USB30£­MMIO_EHB2			BIT3	//0/x/x/x Event Handler Busy (EHB) - RW1C
    #define USB30£­MMIO_DESI2			(BIT0 + BIT1 + BIT2)	//0/x/x/x Dequeue ERST Segment Index (DESI)
#define USB30£­MMIO_EVENT_RING_2_DEQUEUE_POINTER_REG_1_ER2DP1		0x27C	//Event Ring 2 Dequeue Pointer Register 1 (ER2DP1)
    #define USB30£­MMIO_ER2DPHI			0xFFFFFFFF	//0/x/x/x Dequeue Pointer (High 32 Bits) - RW
#define USB30£­MMIO_INTRER_3_MANAGEMENT_REG_IMAN3		0x280	//Interrupter 3 Management Register (IMAN3)
    #define USB30£­MMIO_RESERVED_Z62			0xFFFFFFFC	//0/R/x/x Reserved
    #define USB30£­MMIO_INTEN3			BIT1	//0/x/x/x Interrupt Enable (IE) - RW
    #define USB30£­MMIO_INTPENDING3			BIT0	//0/x/x/x Interrupt Pending (IP) - RW1C
#define USB30£­MMIO_INTRER_3_MODERATION_REG_IMOD3		0x284	//Interrupter 3 Moderation Register (IMOD3)
    #define USB30£­MMIO_IMODC3			0xFFFF0000	//0/0/x/x Interrupt Moderation Counter (IMODC) - RW
    #define USB30£­MMIO_IMODI3			0xFFFF	//0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) - RW
#define USB30£­MMIO_EVENT_RING_3_SEGMENT_TABLE_SIZE_REG_ER3STSZ		0x288	//Event Ring 3 Segment Table Size Register (ER3STSZ)
    #define USB30£­MMIO_RESERVED_Z63			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_ER3STSZ			0xFFFF	//0/x/x/x Event Ring Segment Table Size - RW
#define USB30£­MMIO_EVENT_RING_3_SEGMENT_TABLE_BASE_ADR_REG_0_ER3STBA0		0x290	//Event Ring 3 Segment Table Base Address Register 0 (ER3STBA0)
    #define USB30£­MMIO_ER3STBALO			0xFFFFFFC0	//0/x/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) - RW
    #define USB30£­MMIO_RESERVED_Z64			0x3F	//0/R/x/x Reserved
#define USB30£­MMIO_EVENT_RING_3_SEGMENT_TABLE_BASE_ADR_REG_1_ER3STBA1		0x294	//Event Ring 3 Segment Table Base Address Register 1 (ER3STBA1)
    #define USB30£­MMIO_ER3STBAHI			0xFFFFFFFF	//0/x/x/x Event Ring Segment Table Base Address Register (High 32 Bits)- RW
#define USB30£­MMIO_EVENT_RING_3_DEQUEUE_POINTER_REG_0_ER3DP0		0x298	//Event Ring 3 Dequeue Pointer Register 0 (ER3DP0)
    #define USB30£­MMIO_ER3DPLO			0xFFFFFFF0	//0/x/x/x Dequeue Pointer (Low 32 Bits) - RW
    #define USB30£­MMIO_EHB3			BIT3	//0/x/x/x Event Handler Busy (EHB) - RW1C
    #define USB30£­MMIO_DESI3			(BIT0 + BIT1 + BIT2)	//0/x/x/x Dequeue ERST Segment Index (DESI)
#define USB30£­MMIO_EVENT_RING_3_DEQUEUE_POINTER_REG_1_ER3DP1		0x29C	//Event Ring 3 Dequeue Pointer Register 1 (ER3DP1)
    #define USB30£­MMIO_ER3DPHI			0xFFFFFFFF	//0/x/x/x Dequeue Pointer (High 32 Bits) - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_ID_REG_DCID		0x300	//xHCI Debug Capability ID Register (DCID)
    #define USB30£­MMIO_RESERVED_Z65			0xFFE00000	//0/R/x/x Reserved
    #define USB30£­MMIO_DCERSTMAX			0x1F0000	//03h/x/x/x Debug Capability Event Ring Segment Table Max (DCERST Max) - RO. Default = Implementation Dependent. Valid Values are 1 - 15
    #define USB30£­MMIO_DCPRTNXTPTR			0xFF00	//00h/x/x/x Next Capability Pointer - RO
    #define USB30£­MMIO_DCPRTID			0xFF	//0Ah/x/x/x Capability ID - RO
#define USB30£­MMIO_XHCI_DEBUG_CAP_DOORBELL_REG_DCDB		0x304	//xHCI Debug Capability Doorbell Register (DCDB)
    #define USB30£­MMIO_RESERVED_Z66			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_DCDBTGT			0xFF00	//0/0/x/x Doorbell Target (DB Target) - RW
    #define USB30£­MMIO_RESERVED_Z67			0xFF	//0/R/x/x Reserved
#define USB30£­MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_SIZE_REG_DCERSTSZ		0x308	//xHCI Debug Capability Event Ring Segment Table Size Register (DCERSTSZ)
    #define USB30£­MMIO_RESERVED_Z68			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_DCERSTSZ			0xFFFF	//0/x/x/x Event Ring Segment Table Size - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_BASE_ADR_REG_DCERSTBALO		0x310	//xHCI Debug Capability Event Ring Segment Table Base Address Register (DCERSTBALO)
    #define USB30£­MMIO_DCERSTBALO			0xFFFFFFF0	//0/x/x/x Event Ring Segment Table Base Address Register - RW
    #define USB30£­MMIO_RESERVED_Z69			0xF	//0/R/x/x Reserved
#define USB30£­MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_BASE_ADR_REG_DCERSTBAHI		0x314	//xHCI Debug Capability Event Ring Segment Table Base Address Register (DCERSTBAHI)
    #define USB30£­MMIO_DCERSTBAHI			0xFFFFFFFF	//0/x/x/x Event Ring Segment Table Base Address Register - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_EVENT_RING_DEQUEUE_POINTER_RESITER_DCERDPLO		0x318	//xHCI Debug Capability Event Ring Dequeue Pointer Resiter (DCERDPLO)
    #define USB30£­MMIO_DCERDPLO			0xFFFFFFF0	//0/x/x/x Dequeue Pointer - RW
    #define USB30£­MMIO_RESERVED_Z70			BIT3	//0/R/x/x Reserved
    #define USB30£­MMIO_DCDESI			(BIT0 + BIT1 + BIT2)	//0/0/x/x Dequeue ERST Segment Index (DESI) - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_EVENT_RING_DEQUEUE_POINTER_RESITER_DCERDPHI		0x31C	//xHCI Debug Capability Event Ring Dequeue Pointer Resiter (DCERDPHI)
    #define USB30£­MMIO_DCERDPHI			0xFFFFFFFF	//0/x/x/x Dequeue Pointer - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_CTL_REG_DCCTRL		0x320	//xHCI Debug Capability Control Register (DCCTRL)
    #define USB30£­MMIO_DBC_DCE			BIT31	//0/0/x/x Debug Capability Enable (DCE) - RW
    #define USB30£­MMIO_DBC_DEVADDR			0x7F000000	//0/x/x/x Device Address - RO
    #define USB30£­MMIO_DBC_MAXBSZ			0xFF0000	//0/x/x/x Debug Max Burst Size - RO
    #define USB30£­MMIO_RESERVED_Z71			0xFFE0	//0/R/x/x Reserved
    #define USB30£­MMIO_DBC_DRC			BIT4	//0/x/x/x DbC Run Change (DRC) - RW1C
    #define USB30£­MMIO_DBC_HIT			BIT3	//0/0/x/x Halt IN TR (HIT) - RW1S
    #define USB30£­MMIO_DBC_HOT			BIT2	//0/0/x/x Halt OUT TR (HOT) - RW1S
    #define USB30£­MMIO_DBC_LSE			BIT1	//0/0/x/x Link Status Event Enable (LSE) - RW
    #define USB30£­MMIO_DBC_DCR			BIT0	//0/x/x/x DbC Run (DCR) - RO
#define USB30£­MMIO_XHCI_DEBUG_CAP_STA_REG_DCST		0x324	//xHCI Debug Capability Status Register (DCST)
    #define USB30£­MMIO_DBC_PORTNUM			0xFF000000	//0/x/x/x Debug Port Number - RO
    #define USB30£­MMIO_RESERVED_Z72			0xFFFFFC	//0/R/x/x Reserved
    #define USB30£­MMIO_DBC_SBR			BIT1	//0/x/x/x DbC System Bus Reset (SBR) - RO
    #define USB30£­MMIO_DBC_ERNOTEMPTY			BIT0	//0/x/x/x Event Ring Not Empty (ER) - RO
#define USB30£­MMIO_XHCI_DEBUG_CAP_PORT_STA_AND_CTL_REG_DCPORTSC		0x328	//xHCI Debug Capability Port Status and Control Register (DCPORTSC)
    #define USB30£­MMIO_RESERVED_Z73			0xFF000000	//0/R/x/x Reserved
    #define USB30£­MMIO_DBC_CEC			BIT23	//0/x/x/x Port Config Error Change (CEC) - RW1C
    #define USB30£­MMIO_DBC_PLC			BIT22	//0/x/x/x Port Link Status Change (PLC) = RW1C
    #define USB30£­MMIO_DBC_PRC			BIT21	//0/x/x/x Port Reset Change (PRC) - RW1C
    #define USB30£­MMIO_RESERVED_Z74			(BIT18 + BIT19 + BIT20)	//0/R/x/x Reserved
    #define USB30£­MMIO_DBC_CSC			BIT17	//0/x/x/x Connect Status Change (CSC) - RW1C
    #define USB30£­MMIO_RESERVED_Z75			(BIT14 + BIT15 + BIT16)	//0/R/x/x Reserved
    #define USB30£­MMIO_DBC_PORTSPEED			0x3C00	//0/x/x/x Port Speed (Port Speed) - RO
    #define USB30£­MMIO_RESERVED_Z76			BIT9	//0/x/x/x Reserved
    #define USB30£­MMIO_DBC_PLS			0x1E0	//0101b/x/x/x Port Link State (PLS) - RO
    #define USB30£­MMIO_DBC_PR			BIT4	//0/x/x/x Port Reset (PR) - RO
    #define USB30£­MMIO_RESERVED_Z77			(BIT2 + BIT3)	//0/R/x/x Reserved
    #define USB30£­MMIO_DBC_PED			BIT1	//0/0/x/x Port Enabled/Disabled (PED) - RW
    #define USB30£­MMIO_DBC_CCS			BIT0	//0/x/x/x Current Connect Status (CCS) - RO
#define USB30£­MMIO_XHCI_DEBUG_CAP_CONTEXT_POINTER_REG_DCCPLO		0x330	//xHCI Debug Capability Context Pointer Register (DCCPLO)
    #define USB30£­MMIO_DCCPLO			0xFFFFFFF0	//0/0/x/x Debug Capability Context Pointer Register - RW
    #define USB30£­MMIO_RESERVED_Z78			0xF	//0/R/x/x Reserved
#define USB30£­MMIO_XHCI_DEBUG_CAP_CONTEXT_POINTER_REG_DCCPHI		0x334	//xHCI Debug Capability Context Pointer Register (DCCPHI)
    #define USB30£­MMIO_DCCPHI			0xFFFFFFFF	//0/0/x/x Debug Capability Context Pointer Register - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_DEV_DESCRIPTOR_INFO_REG_1DCDDI1		0x338	//xHCI Debug Capability Device Descriptor Info Register 1(DCDDI1)
    #define USB30£­MMIO_DCVID			0xFFFF0000	//0h/0h/x/x Vendor ID - RW
    #define USB30£­MMIO_RESERVED_Z79			0xFF00	//0/R/x/x Reserved
    #define USB30£­MMIO_DCDBGPROTOCOL			0xFF	//0/0/x/x DbC Protocol - RW
#define USB30£­MMIO_XHCI_DEBUG_CAP_DEV_DESCRIPTOR_INFO_REG_2DCDDI2		0x33C	//xHCI Debug Capability Device Descriptor Info Register 2(DCDDI2)
    #define USB30£­MMIO_DCDEVREV			0xFFFF0000	//0h/0h/x/x Device Revision - RW
    #define USB30£­MMIO_DCPRODUCTID			0xFFFF	//0/0/x/x Product ID - RW
#define USB30£­MMIO_USB2_PORT_1_STA_AND_CTL_REG_PORTSC		0x420	//USB2 Port 1 Status and Control Register (PORTSC)
    #define USB30£­MMIO_RESERVED_Z80			BIT31	//0/R/x/x Reserved
    #define USB30£­MMIO_DR1			BIT30	//0/x/x/x Device Removable (DR) - RO
    #define USB30£­MMIO_RESERVED_Z81			(BIT28 + BIT29)	//0/R/x/x Reserved
    #define USB30£­MMIO_WOE1			BIT27	//0/0/x/x Wake on Over-current Enable (WOE) - RWS
    #define USB30£­MMIO_WDE1			BIT26	//0/0/x/x Wake on Disconnect Enable (WDE) - RWS
    #define USB30£­MMIO_WCE1			BIT25	//0/0/x/x Wake on Connect Enable (WCE) - RWS
    #define USB30£­MMIO_RESERVED_Z82			BIT24	//0/R/x/x Reserved
    #define USB30£­MMIO_RESERVED_Z83			BIT23	//0/R/x/x Reserved
    #define USB30£­MMIO_PLC1			BIT22	//0/x/x/x Port Link State Change (PLC) - RW1CS
    #define USB30£­MMIO_PRC1			BIT21	//0/x/x/x Port Reset Change (PRC) - RW1CS
    #define USB30£­MMIO_OCC1			BIT20	//0/x/x/x Over-current Change (OCC) - RW1CS
    #define USB30£­MMIO_RESERVED_Z84			BIT19	//0/R/x/x Reserved
    #define USB30£­MMIO_PEC1			BIT18	//0/x/x/x Port Enabled/Disabled Change (PEC) - RW1CS
    #define USB30£­MMIO_CSC1			BIT17	//0/x/x/x Connect Status Change (CSC) - RW1CS
    #define USB30£­MMIO_LWS1			BIT16	//0/x/x/x Port Link State Write Strobe (LWS) - RW
    #define USB30£­MMIO_PIC1			(BIT14 + BIT15)	//0/x/x/x Port Indicator Control (PIC) - RWS
    #define USB30£­MMIO_PORTSPEED1			0x3C00	//0/x/x/x Port Speed (Port Speed) - ROS
    #define USB30£­MMIO_PP1			BIT9	//1b/1b/x/x Port Power (PP) - RWS
    #define USB30£­MMIO_PLS1			0x1E0	//5h/x/x/x Port Link State (PLS) - RWS
    #define USB30£­MMIO_PR1			BIT4	//0/x/x/x Port Reset (PR) - RW1S
    #define USB30£­MMIO_OCA1			BIT3	//0/x/x/x Over-current Active (OCA) - RO
    #define USB30£­MMIO_RESERVED_Z85			BIT2	//0/R/x/x Reserved
    #define USB30£­MMIO_PED1			BIT1	//0/x/x/x Port Enabled/Disabled (PED) - RW1CS
    #define USB30£­MMIO_CCS1			BIT0	//0/x/x/x Current Connect Status (CCS) - RO
#define USB30£­MMIO_USB2_PORT_1_PM_STA_AND_CTL_REG_PORTPMSC		0x424	//USB2 Port 1 PM Status and Control Register (PORTPMSC)
    #define USB30£­MMIO_PTESTCTL1			0xF0000000	//0/0/x/x Port Test Control - RW
    #define USB30£­MMIO_RESERVED_Z86			0xFFE0000	//0/R/x/x Reserved
    #define USB30£­MMIO_HLE1			BIT16	//0/0/x/x Hardware LPM Enable (HLE)
    #define USB30£­MMIO_L1DEVSLT1			0xFF00	//0/0/x/x L1 Device Slot - RW
    #define USB30£­MMIO_BESL1			0xF0	//0/0/x/x Best Effort Service Latency (BESL) - RW
    #define USB30£­MMIO_RWE1			BIT3	//0/0/x/x Remote Wake Enable (RWE) - RW
    #define USB30£­MMIO_L1S1			(BIT0 + BIT1 + BIT2)	//0/0/x/x L1 Status (L1S) - RO
#define USB30£­MMIO_USB2_PORT_1_USB2_PROTOCOL_PORTHLPMC_PORTHLPMC		0x42C	//USB2 Port 1 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define USB30£­MMIO_RESERVED_Z87			0xFFFFC000	//0/R/x/x Reserved
    #define USB30£­MMIO_BESLD1			0x3C00	//0/0/x/x Best Effort Service Latency Deep (BESLD) - RWS 
    #define USB30£­MMIO_L1TMOUT1			0x3FC	//0/0/x/x L1 Timeout - RWS
    #define USB30£­MMIO_HIRDM1			(BIT0 + BIT1)	//0/0/x/x Host Initiated Resume Duration Mode (HIRDM)
#define USB30£­MMIO_USB2_PORT_2_STA_AND_CTL_REG_PORTSC		0x430	//USB2 Port 2 Status and Control Register (PORTSC)
    #define USB30£­MMIO_RESERVED_Z88			BIT31	//0/R/x/x Reserved
    #define USB30£­MMIO_DR2			BIT30	//0/x/x/x Device Removable (DR) - RO
    #define USB30£­MMIO_RESERVED_Z89			(BIT28 + BIT29)	//0/R/x/x Reserved
    #define USB30£­MMIO_WOE2			BIT27	//0/0/x/x Wake on Over-current Enable (WOE) - RWS
    #define USB30£­MMIO_WDE2			BIT26	//0/0/x/x Wake on Disconnect Enable (WDE) - RWS
    #define USB30£­MMIO_WCE2			BIT25	//0/0/x/x Wake on Connect Enable (WCE) - RWS
    #define USB30£­MMIO_RESERVED_Z90			BIT24	//0/R/x/x Reserved
    #define USB30£­MMIO_RESERVED_Z91			BIT23	//0/R/x/x Reserved
    #define USB30£­MMIO_PLC2			BIT22	//0/x/x/x Port Link State Change (PLC) - RW1CS
    #define USB30£­MMIO_PRC2			BIT21	//0/x/x/x Port Reset Change (PRC) - RW1CS
    #define USB30£­MMIO_OCC2			BIT20	//0/x/x/x Over-current Change (OCC) - RW1CS
    #define USB30£­MMIO_RESERVED_Z92			BIT19	//0/R/x/x Reserved
    #define USB30£­MMIO_PEC2			BIT18	//0/x/x/x Port Enabled/Disabled Change (PEC) - RW1CS
    #define USB30£­MMIO_CSC2			BIT17	//0/x/x/x Connect Status Change (CSC) - RW1CS
    #define USB30£­MMIO_LWS2			BIT16	//0/x/x/x Port Link State Write Strobe (LWS) - RW
    #define USB30£­MMIO_PIC2			(BIT14 + BIT15)	//0/x/x/x Port Indicator Control (PIC) - RWS
    #define USB30£­MMIO_PORTSPEED2			0x3C00	//0/x/x/x Port Speed (Port Speed) - ROS
    #define USB30£­MMIO_PP2			BIT9	//1b/1b/x/x Port Power (PP) - RWS
    #define USB30£­MMIO_PLS2			0x1E0	//5h/x/x/x Port Link State (PLS) - RWS
    #define USB30£­MMIO_PR2			BIT4	//0/x/x/x Port Reset (PR) - RW1S
    #define USB30£­MMIO_OCA2			BIT3	//0/x/x/x Over-current Active (OCA) - ROS
    #define USB30£­MMIO_RESERVED_Z93			BIT2	//0/R/x/x Reserved
    #define USB30£­MMIO_PED2			BIT1	//0/x/x/x Port Enabled/Disabled (PED) - RW1CS
    #define USB30£­MMIO_CCS2			BIT0	//0/x/x/x Current Connect Status (CCS) - ROS
#define USB30£­MMIO_USB2_PORT_2_PM_STA_AND_CTL_REG_PORTPMSC		0x434	//USB2 Port 2 PM Status and Control Register (PORTPMSC)
    #define USB30£­MMIO_PTESTCTL2			0xF0000000	//0/0/x/x Port Test Control - RW
    #define USB30£­MMIO_RESERVED_Z94			0xFFE0000	//0/R/x/x Reserved
    #define USB30£­MMIO_HLE2			BIT16	//0/0/x/x Hard Ware LPM Enable (HLE)
    #define USB30£­MMIO_L1DEVSLT2			0xFF00	//0/0/x/x L1 Device Slot - RW
    #define USB30£­MMIO_BESL2			0xF0	//0/0/x/x Best Effort Service Latency (BESL) - RW
    #define USB30£­MMIO_RWE2			BIT3	//0/0/x/x Remote Wake Enable (RWE) - RW
    #define USB30£­MMIO_L1S2			(BIT0 + BIT1 + BIT2)	//0/0/x/x L1 Status (L1S) - RO
#define USB30£­MMIO_USB2_PORT_2_USB2_PROTOCOL_PORTHLPMC_PORTHLPMC		0x43C	//USB2 Port 2 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define USB30£­MMIO_RESERVED_Z95			0xFFFFC000	//0/R/x/x Reserved
    #define USB30£­MMIO_BESLD2			0x3C00	//0/0/x/x Best Effort Service Latency Deep (BESLD) - RWS
    #define USB30£­MMIO_L1TMOUT2			0x3FC	//0/0/x/x L1 Timeout - RWS
    #define USB30£­MMIO_HIRDM2			(BIT0 + BIT1)	//0/0/x/x Host Initiated Resume Duration Mode (HIRDM) 
#define USB30£­MMIO_USB3_PORT_1_STA_AND_CTL_REG_PORTSC		0x440	//USB3 Port 1 Status and Control Register (PORTSC)
    #define USB30£­MMIO_WPR6			BIT31	//0/x/x/x Warm Port Reset (WPR) - RW1S/RsvdZ
    #define USB30£­MMIO_DR6			BIT30	//0/x/x/x Device Removable (DR) - RO
    #define USB30£­MMIO_RESERVED_Z96			(BIT28 + BIT29)	//0/R/x/x Reserved
    #define USB30£­MMIO_WOE6			BIT27	//0/0/x/x Wake on Over-current Enable (WOE) - RWS
    #define USB30£­MMIO_WDE6			BIT26	//0/0/x/x Wake on Disconnect Enable (WDE) - RWS
    #define USB30£­MMIO_WCE6			BIT25	//0/0/x/x Wake on Connect Enable (WCE) - RWS
    #define USB30£­MMIO_CAS6			BIT24	//0/x/x/x Cold Attach Status (CAS) - RO
    #define USB30£­MMIO_CEC6			BIT23	//0/x/x/x Port Config Error Change (CEC) - RW1CS/RsvdZ
    #define USB30£­MMIO_PLC6			BIT22	//0/x/x/x Port Link State Change (PLC) - RW1CS
    #define USB30£­MMIO_PRC6			BIT21	//0/x/x/x Port Reset Change (PRC) - RW1CS
    #define USB30£­MMIO_OCC6			BIT20	//0/x/x/x Over-current Change (OCC) - RW1CS
    #define USB30£­MMIO_WRC6			BIT19	//0/x/x/x Warm Port Reset Change (WRC) - RW1CS/RsvdZ
    #define USB30£­MMIO_PEC6			BIT18	//0/x/x/x Port Enable/Disable Change (PEC) - RW1CS
    #define USB30£­MMIO_CSC6			BIT17	//0/x/x/x Connect Status Change (CSC) - RW1CS
    #define USB30£­MMIO_LWS6			BIT16	//0/x/x/x Port Link State Write Strobe (LWS) - RW
    #define USB30£­MMIO_PIC6			(BIT14 + BIT15)	//0/x/x/x Port Indicator Control (PIC) - RWS
    #define USB30£­MMIO_PORTSPEED6			0x3C00	//0/x/x/x Port Speed (Port Speed) - ROS
    #define USB30£­MMIO_PP6			BIT9	//1b/1b/x/x Port Power (PP) - RWS
    #define USB30£­MMIO_PLS6			0x1E0	//5h/x/x/x Port Link State (PLS) - RWS
    #define USB30£­MMIO_PR6			BIT4	//0/x/x/x Port Reset (PR) - RW1S
    #define USB30£­MMIO_OCA6			BIT3	//0/x/x/x Over-current Active (OCA) - ROS
    #define USB30£­MMIO_RESERVED_Z97			BIT2	//0/R/x/x Reserved
    #define USB30£­MMIO_PED6			BIT1	//0/x/x/x Port Enabled/Disabled (PED) - RW1CS
    #define USB30£­MMIO_CCS6			BIT0	//0/x/x/x Current Connect Status (CCS) - ROS
#define USB30£­MMIO_USB3_PORT_1_PM_STA_AND_CTL_REG_PORTPMSC		0x444	//USB3 Port 1 PM Status and Control Register (PORTPMSC)
    #define USB30£­MMIO_RESERVED_Z98			0xFFFE0000	//0/R/x/x Reserved
    #define USB30£­MMIO_FLA6			BIT16	//0/0/x/x Force Link PM Accept (FLA) - RW
    #define USB30£­MMIO_U2TIMEOUT6			0xFF00	//0/0/x/x U2 Timeout - RWS
    #define USB30£­MMIO_U1TIMEOUT6			0xFF	//0/0/x/x U1 Timeout - RWS
#define USB30£­MMIO_USB3_PORT_1_PORT_LINK_INFO_REG_PORTLI		0x448	//USB3 Port 1 Port Link Info Register (PORTLI)
    #define USB30£­MMIO_RESERVED_Z99			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_LINKERRCNT6			0xFFFF	//0/x/x/x Link Error Count - RO
#define USB30£­MMIO_USB3_PORT_2_STA_AND_CTL_REG_PORTSC		0x450	//USB3 Port 2 Status and Control Register (PORTSC)
    #define USB30£­MMIO_WPR7			BIT31	//0/x/x/x Warm Port Reset (WPR) - RW1S/RsvdZ
    #define USB30£­MMIO_DR7			BIT30	//0/x/x/x Device Removable (DR) - RO
    #define USB30£­MMIO_RESERVED_Z100			(BIT28 + BIT29)	//0/R/x/x Reserved
    #define USB30£­MMIO_WOE7			BIT27	//0/0/x/x Wake on Over-current Enable (WOE) - RWS
    #define USB30£­MMIO_WDE7			BIT26	//0/0/x/x Wake on Disconnect Enable (WDE) - RWS
    #define USB30£­MMIO_WCE7			BIT25	//0/0/x/x Wake on Connect Enable (WCE) - RWS
    #define USB30£­MMIO_CAS7			BIT24	//0/x/x/x Cold Attach Status (CAS) - RO
    #define USB30£­MMIO_CEC7			BIT23	//0/x/x/x Port Config Error Change (CEC) - RW1CS/RsvdZ
    #define USB30£­MMIO_PLC7			BIT22	//0/x/x/x Port Link State Change (PLC) - RW1CS
    #define USB30£­MMIO_PRC7			BIT21	//0/x/x/x Port Reset Change (PRC) - RW1CS
    #define USB30£­MMIO_OCC7			BIT20	//0/x/x/x Over-current Change (OCC) - RW1CS
    #define USB30£­MMIO_WRC7			BIT19	//0/x/x/x Warm Port Reset Change (WRC) - RW1CS/RsvdZ
    #define USB30£­MMIO_PEC7			BIT18	//0/x/x/x Port Enable/Disable Change (PEC) - RW1CS
    #define USB30£­MMIO_CSC7			BIT17	//0/x/x/x Connect Status Change (CSC) - RW1CS
    #define USB30£­MMIO_LWS7			BIT16	//0/x/x/x Port Link State Write Strobe (LWS) - RW
    #define USB30£­MMIO_PIC7			(BIT14 + BIT15)	//0/x/x/x Port Indicator Control (PIC) - RWS
    #define USB30£­MMIO_PORTSPEED7			0x3C00	//0/x/x/x Port Speed (Port Speed) - ROS
    #define USB30£­MMIO_PP7			BIT9	//1b/1b/x/x Port Power (PP) - RWS
    #define USB30£­MMIO_PLS7			0x1E0	//5h/x/x/x Port Link State (PLS) - RWS
    #define USB30£­MMIO_PR7			BIT4	//0/x/x/x Port Reset (PR) - RW1S
    #define USB30£­MMIO_OCA7			BIT3	//0/x/x/x Over-current Active (OCA) - ROS
    #define USB30£­MMIO_RESERVED_Z101			BIT2	//0/R/x/x Reserved
    #define USB30£­MMIO_PED7			BIT1	//0/x/x/x Port Enabled/Disabled (PED) - RW1CS
    #define USB30£­MMIO_CCS7			BIT0	//0/x/x/x Current Connect Status (CCS) - ROS
#define USB30£­MMIO_USB3_PORT_2_PM_STA_AND_CTL_REG_PORTPMSC		0x454	//USB3 Port 2 PM Status and Control Register (PORTPMSC)
    #define USB30£­MMIO_RESERVED_Z102			0xFFFE0000	//0/R/x/x Reserved
    #define USB30£­MMIO_FLA7			BIT16	//0/0/x/x Force Link PM Accept (FLA) - RW
    #define USB30£­MMIO_U2TIMEOUT7			0xFF00	//0/0/x/x U2 Timeout - RWS
    #define USB30£­MMIO_U1TIMEOUT7			0xFF	//0/0/x/x U1 Timeout - RWS
#define USB30£­MMIO_USB3_PORT_2_PORT_LINK_INFO_REG_PORTLI		0x458	//USB3 Port 2 Port Link Info Register (PORTLI)
    #define USB30£­MMIO_RESERVED_Z103			0xFFFF0000	//0/R/x/x Reserved
    #define USB30£­MMIO_LINKERRCNT7			0xFFFF	//0/x/x/x Link Error Count - RO
//OPTCFG_XHCI
#define OPTCFGXHCI_XHCIOPTION_RX01		0x01	//xHCI Option RX01
    #define OPTCFGXHCI_RESERVED			0xF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_SS_REDUCE			BIT3	//0/0/x/x Frame Timer Reduce Mode
    #define OPTCFGXHCI_CROSSMF_EN			BIT2	//0/0/x/x Cross MicroFrame Enable
    #define OPTCFGXHCI_CROSSMF_CNT			(BIT0 + BIT1)	//0/0/x/x Cross MicroFrame Count
#define OPTCFGXHCI_XHCIOPTION_RX03		0x03	//xHCI Option RX03
    #define OPTCFGXHCI_DCERXRPRI			(BIT6 + BIT7)	//0/0/x/x Debug Capability Event Ring Upstream Read Priority
    #define OPTCFGXHCI_DCERXWPRI			(BIT4 + BIT5)	//0/0/x/x Debug Capability Event Ring Upstream Write Priority
    #define OPTCFGXHCI_DCBMXRPRI			(BIT2 + BIT3)	//0/0/x/x Debug Capability Buffer Management Upstream Read Priority
    #define OPTCFGXHCI_DCBMXWPRI			(BIT0 + BIT1)	//0/0/x/x Debug Capability Buffer Management Upstream Write Priority
#define OPTCFGXHCI_XHCIOPTION_RX04		0x04	//xHCI Option RX04
    #define OPTCFGXHCI_HDXRPRI			(BIT30 + BIT31)	//0/0/x/x HSBI Data Upstream Read Priority
    #define OPTCFGXHCI_HDXWPRI			(BIT28 + BIT29)	//0/0/x/x HSBI Data Upstream Write Priority
    #define OPTCFGXHCI_HBXRPRI			(BIT26 + BIT27)	//0/0/x/x HSBI Schedule Upstream Read Priority
    #define OPTCFGXHCI_HBXWPRI			(BIT24 + BIT25)	//0/0/x/x HSBI Schedule Upstream Write Priority
    #define OPTCFGXHCI_S0XRPRI			(BIT22 + BIT23)	//0/0/x/x SSBI Schedule Upstream Read Priority
    #define OPTCFGXHCI_S0XWPRI			(BIT20 + BIT21)	//0/0/x/x SSBI Schedule Upstream Write Priority
    #define OPTCFGXHCI_B0XRPRI			(BIT18 + BIT19)	//0/0/x/x Buffer Management Upstream Read Priority
    #define OPTCFGXHCI_B0XWPRI			(BIT16 + BIT17)	//0/0/x/x Buffer Management Upstream Write Priority
    #define OPTCFGXHCI_PTXRPRI			(BIT14 + BIT15)	//0/0/x/x PIPETLB Upstream Read Priority
    #define OPTCFGXHCI_PTXWPRI			(BIT12 + BIT13)	//0/0/x/x PIPETLB Upstream Write Priority
    #define OPTCFGXHCI_ERXRPRI			(BIT10 + BIT11)	//0/0/x/x Event Ring Upstream Read Priority
    #define OPTCFGXHCI_ERXWPRI			(BIT8 + BIT9)	//0/0/x/x Event Ring Upstream Write Priority
    #define OPTCFGXHCI_DAXRPRI			(BIT6 + BIT7)	//0/0/x/x Normal DMA Upstream Read Priority
    #define OPTCFGXHCI_DAXWPRI			(BIT4 + BIT5)	//0/0/x/x Normal DMA Upstream Write Priority
    #define OPTCFGXHCI_CDXRPRI			(BIT2 + BIT3)	//0/0/x/x Command Ring Upstream Read Priority
    #define OPTCFGXHCI_CDXWPRI			(BIT0 + BIT1)	//0/0/x/x Command Ring Upstream Write Priority
#define OPTCFGXHCI_XHCIOPTION_RX08		0x08	//xHCI Option RX08
    #define OPTCFGXHCI_SSISOPRI			(BIT14 + BIT15)	//01b/01b/x/x SSBI ISO Transaction Upstream Request Priority
    #define OPTCFGXHCI_HSISOPRI			(BIT12 + BIT13)	//01b/01b/x/x HSBI ISO Transaction Upstream Request Priority
    #define OPTCFGXHCI_TCXRPRI			(BIT10 + BIT11)	//01b/01b/x/x TRB Cache Upstream Read Priority
    #define OPTCFGXHCI_TCXWPRI			(BIT8 + BIT9)	//0/0/x/x TRB Cache Upstream Write Priority
    #define OPTCFGXHCI_MDXRPRI			(BIT6 + BIT7)	//0/0/x/x MCU Data Upstream Read Priority 
    #define OPTCFGXHCI_MDXWPRI			(BIT4 + BIT5)	//0/0/x/x MCU Data Upstream Write Priority
    #define OPTCFGXHCI_MIXRPRI			(BIT2 + BIT3)	//0/0/x/x MCU Instruction Upstream Read Priority
    #define OPTCFGXHCI_MIXWPRI			(BIT0 + BIT1)	//0/0/x/x MCU Instruction Upstream Write Priority
#define OPTCFGXHCI_XHCIOPTION_RX0A		0x0A	//xHCI Option RX0A
    #define OPTCFGXHCI_B1XRPRI			(BIT6 + BIT7)	//0/0/x/x Buffer Management Upstream Read (Path 1) Priority
    #define OPTCFGXHCI_B1XWPRI			(BIT4 + BIT5)	//0/0/x/x Buffer Management Upstream Write (Path 0) Priority
    #define OPTCFGXHCI_DTKEEPEN			BIT3	//0/0/0/x Data Keep Enable
    #define OPTCFGXHCI_NONESNOOPEN			BIT2	//1b/1b/X/x xHCI Non-Snoop Enable
    #define OPTCFGXHCI_XHCIPW256B_EN			BIT1	//1b/1b/1b/x xHCI Upstream Write Max 256Bytes Capability Enable
    #define OPTCFGXHCI_XHCIPR256B_EN			BIT0	//1b/1b/1b/x xHCI Upstream Read Max 256Bytes Capability Enable
#define OPTCFGXHCI_XHCIOPTION_RX0B		0x0B	//xHCI Option RX0B
    #define OPTCFGXHCI_RESERVED_Z1			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_NRDYNOEMPTY_THRESH			(BIT3 + BIT4 + BIT5)	//0/0/x/x NRDY Address List Not Empty Interrupt MCU Threshold Setting
    #define OPTCFGXHCI_NRDYLIST_THRESH			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x NRDY Address List Full Threshold Setting
#define OPTCFGXHCI_XHCIOPTION_RX0C		0x0C	//xHCI Option RX0C
    #define OPTCFGXHCI_ERDYNUMP_CHKEN			BIT7	//0/0/x/x SS ERDY NumP Field Check Enable
    #define OPTCFGXHCI_ISOFRAMEID_BYPASS			BIT6	//0/0/x/x ISO TRB ¡°Frame ID¡± Bypass Check Enable
    #define OPTCFGXHCI_CTRLDIR_CHKEN			BIT5	//0/0/x/x Enable to Check DIR Bit in Control Transfer TP/DP
    #define OPTCFGXHCI_TUSTMOUT_CHKEN			BIT4	//1b/1b/x/x Enable to Check 10 us TimeOut
    #define OPTCFGXHCI_SCHATMFBNDRY			BIT3	//0/0/x/x Schedule Async Transaction at MicroFrame Boundary
    #define OPTCFGXHCI_NTRBTD1SO_EN			BIT2	//1b/1b/x/x Enable to Combine ISO Non-Transfer TD with Next TD in 1 SO
    #define OPTCFGXHCI_PIPEPREFETCH_EN			BIT1	//0/0/x/x Enable to Pre-Fetch Pipe
    #define OPTCFGXHCI_TDQEMPTY_CHKEN			BIT0	//0/0/x/x Periodic TD Queue Empty Check Enable
#define OPTCFGXHCI_XHCIOPTION_RX0D		0x0D	//xHCI Option RX0D
    #define OPTCFGXHCI_BLKENT_EN			BIT7	//0/0/x/x Enable to Block Event TRB Send to System Memory Before S/W Clearing EHB Bit
    #define OPTCFGXHCI_MCUHWRST_EN			BIT6	//0/0/x/x MCU HW Reset Enable if HCRST/LHCRST
    #define OPTCFGXHCI_DMAMUXRST_EN			BIT5	//1b/1b/x/x DMAMUX Reset Enable if HCRST/LHCRST
    #define OPTCFGXHCI_PSCEG_PENDING_EN			BIT4	//0/0/x/x Generate Another ¡°Port Status Change¡± Event for Pending Status Change Bit after S/W W1C One Change Bit
    #define OPTCFGXHCI_BYPASS_IPLHCRST			BIT3	//1b/1b/x/x Bypass LHCRST to SSIP XH_RESET_
    #define OPTCFGXHCI_DSMCUSELHDL_EN			BIT2	//0/0/x/x MCU Selective Handle Downstream Cycle
    #define OPTCFGXHCI_DSMCUHDL_EN			BIT1	//0/0/x/x MCU Handle Downstream Cycle
    #define OPTCFGXHCI_DBBLKDS_EN			BIT0	//0/0/x/x Block Downstream Cycle if Doorbell Queue is Not Empty
#define OPTCFGXHCI_XHCIOPTION_RX0E		0x0E	//xHCI Option RX0E
    #define OPTCFGXHCI_DSMCUSELHDL_CFG0			BIT15	//0/0/x/x MCU Selective Handle Downstream Cycle 0
    #define OPTCFGXHCI_RESERVED_Z2			(BIT12 + BIT13 + BIT14)	//0/R/x/x Reserved
    #define OPTCFGXHCI_DSMCUSELHDL_ADDR0			0xFFF	//0/0/x/x MCU Selective Handle Downstream Cycle Address 0
#define OPTCFGXHCI_XHCIOPTION_RX10		0x10	//xHCI Option RX10
    #define OPTCFGXHCI_DSMCUSELHDL_CFG1			BIT15	//0/0/x/x MCU Selective Handle Downstream Cycle 1
    #define OPTCFGXHCI_RESERVED_Z3			(BIT12 + BIT13 + BIT14)	//0/R/x/x Reserved
    #define OPTCFGXHCI_DSMCUSELHDL_ADDR1			0xFFF	//0/0/x/x MCU Selective Handle Downstream Cycle Address 1
#define OPTCFGXHCI_XHCIOPTION_RX12		0x12	//xHCI Option RX12
    #define OPTCFGXHCI_DSMCUSELHDL_CFG2			BIT15	//0/0/x/x MCU Selective Handle Downstream Cycle 2
    #define OPTCFGXHCI_RESERVED_Z4			(BIT12 + BIT13 + BIT14)	//0/R/x/x Reserved
    #define OPTCFGXHCI_DSMCUSELHDL_ADDR2			0xFFF	//0/0/x/x MCU Selective Handle Downstream Cycle Address 2
#define OPTCFGXHCI_XHCIOPTION_RX14		0x14	//xHCI Option RX14
    #define OPTCFGXHCI_DSMCUSELHDL_CFG3			BIT15	//0/0/x/x MCU Selective Handle Downstream Cycle3
    #define OPTCFGXHCI_RESERVED_Z5			(BIT12 + BIT13 + BIT14)	//0/R/x/x Reserved
    #define OPTCFGXHCI_DSMCUSELHDL_ADDR3			0xFFF	//0/0/x/x MCU Selective Handle Downstream Cycle Address 3
#define OPTCFGXHCI_XHCIOPTION_RX16		0x16	//xHCI Option RX16
    #define OPTCFGXHCI_SS_NFLSASYEP_EN			BIT15	//1b/1b/x/x Not Flush Last Async Endpoint Enable Bit
    #define OPTCFGXHCI_SS_PERASYPIPE_EN			BIT14	//0/0/1b/x xHCI SSBI Periodic and Async Pipe Enable
    #define OPTCFGXHCI_SS_2ASYNCSHARE_EN			BIT13	//1b/1b/1b/x xHCI SSBI 2 Async Control Share Mode Enable
    #define OPTCFGXHCI_SS_EPONEONLY_EN			BIT12	//1b/1b/1b/x xHCI SSBI Enable NOT Care SO if Only 1 Async Endpoint Active
    #define OPTCFGXHCI_SS_ASYNCSTP_PARM			0xFFF	//272h/272h/x/x xHCI SSBI Schedule Stop Async List Before SOF Boundary Timer Adjustment
#define OPTCFGXHCI_XHCIOPTION_RX18		0x18	//xHCI Option RX18
    #define OPTCFGXHCI_RESERVED_Z6			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_HS_PERASYPIPE_EN			BIT14	//0/0/0/x xHCI HSBI Periodic and Async Pipe Enable
    #define OPTCFGXHCI_HS_2ASYNCSHARE_EN			BIT13	//0/0/0/x xHCI HSBI 2 Async Control Share Mode Enable
    #define OPTCFGXHCI_HS_EPONEONLY_EN			BIT12	//0/0/1b/x xHCI HSBI Enable NOT Care SO if Only 1 Async Endpoint Active
    #define OPTCFGXHCI_HS_ASYNCSTP_PARM			0xFFF	//272h/272h/x/x xHCI HSBI Schedule Stop Async List Before SOF Boundary Timer Adjustment
#define OPTCFGXHCI_XHCIOPTION_RX1A		0x1A	//xHCI Option RX1A
    #define OPTCFGXHCI_SS_IN_LPTDTRB_EN			BIT7	//0/0/x/x SSBI Enable to Check ¡°Partial Completed TD¡± for IN Transaction
    #define OPTCFGXHCI_SS_OUT_LPTDTRB_EN			BIT6	//0/0/x/x SSBI Enable to Check ¡°Partial Completed TD¡± for OUT Transaction
    #define OPTCFGXHCI_SS_NUMPCHKEN			BIT5	//1b/1/x/x SSBI Enable Register for TRANS Checking the NUMP Field in the Device Response ACK TP to Decide Number of Following Burst out DPs
    #define OPTCFGXHCI_SS_BLKEP_RLTDLTRB_EN			BIT4	//0/0/x/x SSBI Bulk Endpoint Service to the Last TRB in the Transfer Ring at Last Service, Including Non-Transfer TD
    #define OPTCFGXHCI_SS_INTEP_TDDB_EN			BIT3	//0/0/x/x SSBI Interrupt Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wait for another Doorbell
    #define OPTCFGXHCI_SS_ISOEP_TDDB_EN			BIT2	//0/0/x/x SSBI Isoch Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wait for another Doorbell
    #define OPTCFGXHCI_SS_CTLEP_TDDB_EN			BIT1	//0/0/x/x SSBI Control Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wait for another Doorbell
    #define OPTCFGXHCI_SS_BLKEP_TDDB_EN			BIT0	//0/0/x/x SSBI Bulk Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wait for another Doorbell
#define OPTCFGXHCI_XHCIOPTION_RX1B		0x1B	//xHCI Option RX1B
    #define OPTCFGXHCI_HS_IN_LPTDTRB_EN			BIT7	//0/0/x/x HSBI Enable to Check ¡°Partial Completed TD¡± for IN Transaction
    #define OPTCFGXHCI_HS_OUT_LPTDTRB_EN			BIT6	//0/0/x/x HSBI Enable to Check ¡°Partial Completed TD¡± for OUT Transaction
    #define OPTCFGXHCI_RESERVED_Z7			(BIT4 + BIT5)	//0/R/x/x Reserved
    #define OPTCFGXHCI_HS_INTEP_TDDB_EN			BIT3	//0/0/x/x HSBI Interrupt Endpoint 1TD 1Doorbell Enable
    #define OPTCFGXHCI_HS_ISOEP_TDDB_EN			BIT2	//0/0/x/x HSBI Isoch Endpoint 1TD 1Doorbell Enable
    #define OPTCFGXHCI_HS_CTLEP_TDDB_EN			BIT1	//0/0/x/x HSBI Control Endpoint 1TD 1Doorbell Enable
    #define OPTCFGXHCI_HS_BLKEP_TDDB_EN			BIT0	//0/0/x/x HSBI Bulk Endpoint 1TD 1Doorbell Enable
#define OPTCFGXHCI_XHCIOPTION_RX1C		0x1C	//xHCI Option RX1C
    #define OPTCFGXHCI_RESERVED_Z8			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_SOVD			(BIT0 + BIT1)	//11b/11b/x/x XHRUT SRAM Overflow Depth
#define OPTCFGXHCI_XHCIOPTION_RX20		0x20	//xHCI Option RX20
    #define OPTCFGXHCI_RESERVED_Z9			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_TRBCACHE_BYPASS			BIT0	//0/x/x/x TRB Cache/Stream Context Cache Bypass Mode Enable
#define OPTCFGXHCI_XHCIOPTION_RX21		0x21	//xHCI Option RX21
    #define OPTCFGXHCI_RESERVED_Z10			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_STCDMARNA_OPTION			BIT0	//0/x/x/x STCDMARNA_OPTION
#define OPTCFGXHCI_XHCIOPTION_RX22		0x22	//xHCI Option RX22
    #define OPTCFGXHCI_RESERVED_Z11			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_TRBCACHE_HASHOPT0			0x7FFF	//1249h/1249h/x/x TRB Cache HASH Option for HASHOUT[0]
#define OPTCFGXHCI_XHCIOPTION_RX24		0x24	//xHCI Option RX24
    #define OPTCFGXHCI_RESERVED_Z12			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_TRBCACHE_HASHOPT1			0x7FFF	//2492h/2492h/x/x TRB Cache HASH Option for HASHOUT[1]
#define OPTCFGXHCI_XHCIOPTION_RX26		0x26	//xHCI Option RX26
    #define OPTCFGXHCI_RESERVED_Z13			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_TRBCACHE_HASHOPT2			0x7FFF	//4924h/4924h/x/x TRB Cache HASH Option for HASHOUT[2]
#define OPTCFGXHCI_XHCIOPTION_RX28		0x28	//xHCI Option RX28
    #define OPTCFGXHCI_RESERVED_Z14			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_STRCACHE_HASHOPT0			0x7FFF	//1111h/1111h/x/x Stream Context Cache HASH Option for HASHOUT[0]
#define OPTCFGXHCI_XHCIOPTION_RX2A		0x2A	//xHCI Option RX2A
    #define OPTCFGXHCI_RESERVED_Z15			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_STRCACHE_HASHOPT1			0x7FFF	//2222h/2222h/x/x Stream Context Cache HASH Option for HASHOUT[1]
#define OPTCFGXHCI_XHCIOPTION_RX2C		0x2C	//xHCI Option RX2C
    #define OPTCFGXHCI_RESERVED_Z16			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_STRCACHE_HASHOPT2			0x7FFF	//4444h/4444h/x/x Stream Context Cache HASH Option for HASHOUT[2]
#define OPTCFGXHCI_XHCIOPTION_RX2E		0x2E	//xHCI Option RX2E
    #define OPTCFGXHCI_RESERVED_Z17			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_STRCACHE_HASHOPT3			0x7FFF	//4888h/4888h/x/x Stream Context Cache HASH Option for HASHOUT[3]
#define OPTCFGXHCI_XHCIOPTION_RX30		0x30	//xHCI Option RX30
    #define OPTCFGXHCI_RESERVED_Z18			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_STRCACHE_HASHOPT4			0x7FFF	//1248h/1248h/x/x Stream Context Cache HASH Option for HASHOUT[4]
#define OPTCFGXHCI_XHCIOPTION_RX40		0x40	//xHCI Option RX40
    #define OPTCFGXHCI_RESERVED_Z19			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSP2_FORCEU1			BIT1	//0/0/x/x Force Link of SS Port 2 Issue LGO_U1 to Initiate U1 Entry Sequence
    #define OPTCFGXHCI_SSP1_FORCEU1			BIT0	//0/0/x/x Force Link of SS Port 1 Issue LGO_U1 to Initiate U1 Entry Sequence
#define OPTCFGXHCI_XHCIOPTION_RX41		0x41	//xHCI Option RX41
    #define OPTCFGXHCI_RESERVED_Z20			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSP2_FORCEU2			BIT1	//0/0/x/x Force Link of SS Port 2 Issue LGO_U2 to Initiate U2 Entry Sequence
    #define OPTCFGXHCI_SSP1_FORCEU2			BIT0	//0/0/x/x Force Link of SS Port 1 Issue LGO_U2 to Initiate U2 Entry Sequence
#define OPTCFGXHCI_XHCIOPTION_RX42		0x42	//xHCI Option RX42
    #define OPTCFGXHCI_RESERVED_Z21			0xFFF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSP2_BERTGEN			(BIT2 + BIT3)	//0/0/x/x SS Port 2 Generate Loopback Pattern BRST or BERC Control Signal in Loopback State
    #define OPTCFGXHCI_SSP1_BERTGEN			(BIT0 + BIT1)	//0/0/x/x SS Port 1 Generate Loopback Pattern BRST or BERC Control Signal in Loopback State
#define OPTCFGXHCI_XHCIOPTION_RX44		0x44	//xHCI Option RX44
    #define OPTCFGXHCI_RESERVED_Z22			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSP2_LOOPBACK			BIT1	//0/0/x/x SS Port 2 Loopback Mode Entry Enable
    #define OPTCFGXHCI_SSP1_LOOPBACK			BIT0	//0/0/x/x SS Port 1 Loopback Mode Entry Enable
#define OPTCFGXHCI_XHCIOPTION_RX45		0x45	//xHCI Option RX45
    #define OPTCFGXHCI_RESERVED_Z23			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSP2_SCRMBLEN			BIT1	//1b/1b/x/x Enable SS Port 2 Scrambling Function or Not
    #define OPTCFGXHCI_SSP1_SCRMBLEN			BIT0	//1b/1b/x/x Enable SS Port 1 Scrambling Function or Not
#define OPTCFGXHCI_XHCIOPTION_RX46		0x46	//xHCI Option RX46
    #define OPTCFGXHCI_RESERVED_Z24			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSIP_DYNPM			BIT0	//1b/1b/x/1b USB3-IP Dynamic Clock Enable
#define OPTCFGXHCI_XHCIOPTION_RX50		0x50	//xHCI Option RX50
    #define OPTCFGXHCI_RESERVED_Z25			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_XHCI_OVERALL_DYNCLKEN			BIT4	//0/0/x/1b XHCI  Overall Dynamic Clk Enable 
    #define OPTCFGXHCI_MCUBRG_INTC_CLK_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable  of MCUBRG_INTC Module
    #define OPTCFGXHCI_NORMALDMA_CLK_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_ CLK_U250 Dynamic Clk Enable of NORMALDMA Module
    #define OPTCFGXHCI_CDRING_CLK_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of CDRING Module 
    #define OPTCFGXHCI_BRIDGE_CLK_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of BRIDGE Module
#define OPTCFGXHCI_XHCIOPTION_RX51		0x51	//xHCI Option RX51
    #define OPTCFGXHCI_RESERVED_Z26			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_BUFM_CLKOUT_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of BUFM OUT  Module 
    #define OPTCFGXHCI_BUFM_CLKIN_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of BUFM IN Module
    #define OPTCFGXHCI_DMAMUX_CLKW_E_DYNCLKEN			BIT3	//0/0/x/1b CLK_E Dynamic Clk Enable of DMAW Module 
    #define OPTCFGXHCI_DMAMUX_CLKR_E_DYNCLKEN			BIT2	//0/0/x/1b CLK_E Dynamic Clk Enable of DMAR Module
    #define OPTCFGXHCI_DMAMUX_CLKW_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_250 Dynamic Clk Enable of DMAW Module
    #define OPTCFGXHCI_DMAMUX_CLKR_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_250 Dynamic Clk Enable of DMAR Module
#define OPTCFGXHCI_XHCIOPTION_RX52		0x52	//xHCI Option RX52
    #define OPTCFGXHCI_RESERVED_Z27			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSBI_CLKDEVN_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of SSBI DEVN  Module
    #define OPTCFGXHCI_RESERVED_Z28			BIT5	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCU_TIMERC_U25_DYNCLKEN			BIT4	//0/0/x/1b CLK_U25 Dynamic Clk Enable Of MCU TIMERC  Module
    #define OPTCFGXHCI_MCU_TIMERC_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of MCU TIMERC  Module
    #define OPTCFGXHCI_FMTIMER_CLK_U60_DYNCLKEN			BIT2	//0/0/x/1b CLK_U60 Dynamic Clk Enable Of FMTIMER Module 
    #define OPTCFGXHCI_RESERVED_Z29			BIT1	//0/R/x/x Reserved
    #define OPTCFGXHCI_FMTIMER_CLK_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of FMTIMER Module
#define OPTCFGXHCI_XHCIOPTION_RX53		0x53	//xHCI Option RX53
    #define OPTCFGXHCI_RESERVED_Z30			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_EVENTRING_CLKMSICTL_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable of MSICTL In EVENTRING Module
    #define OPTCFGXHCI_EVENTRING_CLKROUTE_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of EVENTROUTE  In EVENTRING Module
    #define OPTCFGXHCI_EVENTRING_CLKRCTL_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of EVENTRTL In EVENTRING Module 
    #define OPTCFGXHCI_RESERVED_Z31			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_EVENTRING_CLKMCUREG_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable of MCUREG In EVENTRING Module
    #define OPTCFGXHCI_EVENTRING_CLKDMAIF_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of DMAIF In EVENTRING Module
    #define OPTCFGXHCI_EVENTRING_CLKERST_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ERST In EVENTRING Module
#define OPTCFGXHCI_XHCIOPTION_RX54		0x54	//xHCI Option RX54
    #define OPTCFGXHCI_TRBCTXCACHE_CLKROUTE_U250_DYNCLKEN			BIT7	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ROUTE In TRBCTXCACHE Module
    #define OPTCFGXHCI_TRBCTXCACHE_CLKMCUREG_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable of MCUREG In TRBCTXCACHE Module 
    #define OPTCFGXHCI_TRBCTXCACHE_CLKTRBCACHE_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of TRBCACHE In TRBCTXCACHE Module
    #define OPTCFGXHCI_TRBCTXCACHE_CLKDMAIF_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of TRBCACHEROUTE In TRBCTXCACHE Module
    #define OPTCFGXHCI_TRBCTXCACHE_CLKSTRCTX_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable of DMAIF In TRBCTXCACHE Module 
    #define OPTCFGXHCI_RESERVED_Z32			(BIT1 + BIT2)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PIPETLB_CLK_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PIPETLB Module
#define OPTCFGXHCI_XHCIOPTION_RX55		0x55	//xHCI Option RX55
    #define OPTCFGXHCI_RESERVED_Z33			0xF8	//0/R/x/x Reserved
    #define OPTCFGXHCI_PCIS_CLK_E_DYNCLKEN			BIT2	//0/0/x/1b CLK_E Dynamic Clk Enable of PCIS Module
    #define OPTCFGXHCI_PCIS_SUS_CLK_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PCIS Module
    #define OPTCFGXHCI_PCIS_CLK_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PCIS_SUS Module
#define OPTCFGXHCI_XHCIOPTION_RX56		0x56	//xHCI Option RX56
    #define OPTCFGXHCI_RESERVED_Z34			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_HSBI_RBC_120M_DYNCLKEN			BIT6	//0/0/x/1b RBC_120M Dynamic Clk Enable of HSBI Module
    #define OPTCFGXHCI_HSSCHEDULE_CLKDMA_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of DMAIF in HSBI SCHEDULE Module
    #define OPTCFGXHCI_HSSCHEDULE_CLKMCUREG_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of MCUREG in HSBI SCHEDULE Module
    #define OPTCFGXHCI_HSSCHEDULE_CLKASYNC2_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ASYNC_CTL2 in HSBI SCHEDULE Module
    #define OPTCFGXHCI_HSSCHEDULE_CLKASYNC1_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ASYNC_CTL1 in HSBI SCHEDULE Module 
    #define OPTCFGXHCI_HSSCHEDULE_CLKPERIODIC_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PERIODIC_CTL In  HSBI SCHEDULE Module
    #define OPTCFGXHCI_HSSCHEDULE_CLK_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of HSBI SCHEDULE Module
#define OPTCFGXHCI_XHCIOPTION_RX57		0x57	//xHCI Option RX57
    #define OPTCFGXHCI_RESERVED_Z35			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSSCHEDULE_CLKDMA_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable of DMAIF in SSBI SCHEDULE Module
    #define OPTCFGXHCI_SSSCHEDULE_CLKMCUREG_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of MCUREG in SSBI SCHEDULE Module
    #define OPTCFGXHCI_SSSCHEDULE_CLKNERDY_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of NERDY_CTL in SSBI SCHEDULE Module
    #define OPTCFGXHCI_SSSCHEDULE_CLKASYNC2_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ASYNC_CTL2 in SSBI SCHEDULE Module
    #define OPTCFGXHCI_SSSCHEDULE_CLKASYNC1_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ASYNC_CTL1 In SSBI SCHEDULE Module
    #define OPTCFGXHCI_SSSCHEDULE_CLKPERIODIC_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PERIODIC_CTL In SSBI SCHEDULE Module
    #define OPTCFGXHCI_SSSCHEDULE_CLK_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of SSBI SCHEDULE Module
#define OPTCFGXHCI_XHCIOPTION_RX58		0x58	//xHCI Option RX58
    #define OPTCFGXHCI_SSTRANS_CLKTXIF_U250_DYNCLKEN			BIT7	//0/0/x/1b CLK_U250 Dynamic Clk Enable of TXIF in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKOUTCTL_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable of BUFMIF OUT in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKOUT2CTL_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of OUT2 in SSBI TRANS Module 
    #define OPTCFGXHCI_SSTRANS_CLKOUT1CTL_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of OUT1 in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKINCTL_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable of BUFMIF IN in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKIN2CTL_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable of IN2 in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKIN1CTL_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of IN1 in SSBI TRANS Module 
    #define OPTCFGXHCI_SSTRANS_CLKEPSEL_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of EPSEL in SSBI TRANS Module
#define OPTCFGXHCI_XHCIOPTION_RX59		0x59	//xHCI Option RX59
    #define OPTCFGXHCI_RESERVED_Z36			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSIPIF_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable of SSIPIF in SSBI Module
    #define OPTCFGXHCI_SSTRANS_CLKPTMCTL_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PTMCTL in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKSSROUTE_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable of SSROUTE in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKITPCTL_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable of ITPCTL in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKPINGCTL_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable of PINGCTL in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKCMDCTL_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable of CMDCTL in SSBI TRANS Module
    #define OPTCFGXHCI_SSTRANS_CLKRXIF_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable of RXIF in SSBI TRANS Module
#define OPTCFGXHCI_XHCIOPTION_RX5A		0x5A	//xHCI Option RX5A
    #define OPTCFGXHCI_RESERVED_Z37			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_XHMCU_ARB_CLK_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of XHC2MCU_DMAARB Module
    #define OPTCFGXHCI_XHMCU_ARB_CLK_E_DYNCLKEN			BIT5	//0/0/x/1b CLK_E Dynamic Clk Enable Of XHC2MCU_DMAARB Module
    #define OPTCFGXHCI_USB3SSIPMUX_CLK_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of USB3SSIPMUX Module
    #define OPTCFGXHCI_HSBIDMATRAN_CLK_U250_DYNCLKEN			BIT3	//0/0/x/1b Reserved
    #define OPTCFGXHCI_MCU_CLK_U250_DYNCLKEN			BIT2	//0/x/x/1b CLK_U250 Dynamic Clk Enable Of MCU Module
    #define OPTCFGXHCI_DCBUFM_CLKOUT_U250_DYNCLKEN			BIT1	//0/0/x/1b Reserved
    #define OPTCFGXHCI_DCBUFM_CLKIN_U250_DYNCLKEN			BIT0	//0/0/x/1b Reserved
#define OPTCFGXHCI_XHCIOPTION_RX5B		0x5B	//xHCI Option RX5B
    #define OPTCFGXHCI_RESERVED_Z38			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_DCEVENTRING_CLKERST_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of ERST In EVENTRING_DC Module
    #define OPTCFGXHCI_RESERVED_Z39			BIT5	//0/R/x/x Reserved
    #define OPTCFGXHCI_DCEVENTRING_CLKMCUREG_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of MCUREG In EVENTRING_DC Module
    #define OPTCFGXHCI_DCEVENTRING_CLKDMAIF_U250_DYNCLKEN			BIT3	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of DMAIF In EVENTRING_DC Module
    #define OPTCFGXHCI_DCEVENTRING_CLKRCTL_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of EVENTRCT In EVENTRING_DC Module
    #define OPTCFGXHCI_DCEVENTRING_CLKROUTE_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of ROUTE In EVENTRING_DC Module 
    #define OPTCFGXHCI_DCEVENTRING_CLKMSICTL_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of MSICTL In EVENTRING_DC Module
#define OPTCFGXHCI_XHCIOPTION_RX5C		0x5C	//xHCI Option RX5C
    #define OPTCFGXHCI_XHCI_DBC_SSIP_IF_U250_DYNCLKEN			BIT7	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of SSIPIF In DBC Module 
    #define OPTCFGXHCI_XHCI_DBC_CTLEP_U250_DYNCLKEN			BIT6	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of CTLEPCTL In DBC Module
    #define OPTCFGXHCI_XHCI_DBC_INEP_U250_DYNCLKEN			BIT5	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of INEPCTL In DBC Module
    #define OPTCFGXHCI_XHCI_DBC_OUTEP_U250_DYNCLKEN			BIT4	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of OUTEPCTL In DBC Module
    #define OPTCFGXHCI_RESERVED_Z40			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_XHCI_DBC_MCUIF_U250_DYNCLKEN			BIT2	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of MCUIF In DBC Module
    #define OPTCFGXHCI_XHCI_DBC_TXIF_U250_DYNCLKEN			BIT1	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of TXIF In DBC Module
    #define OPTCFGXHCI_XHCI_DBC_RXIF_U250_DYNCLKEN			BIT0	//0/0/x/1b CLK_U250 Dynamic Clk Enable Of RXIF In DBC Module 
#define OPTCFGXHCI_XHCIOPTION_RX60		0x60	//xHCI Option RX60
    #define OPTCFGXHCI_DPHRSPCHKEN			BIT7	//1b/1b/x/x SSTRANS Enabel to Check Device Response Before DPP  Sending Out
    #define OPTCFGXHCI_BUFRLSALL_EN			BIT6	//1b/1b/x/x SSTRANS Enable to Release All IN/OUT Buffer When IN/OUT TRANS Idle
    #define OPTCFGXHCI_INBUFREQ_RTY_EN			BIT5	//1b/1b/x/x SSTRANS Enable to Request IN Buffer Before Doing Retry
    #define OPTCFGXHCI_INRTY_MORE_EN			BIT4	//0/0/x/x SSTRANS Enable to Do 1 More Retry if No Service Opportunity at IN Transfer
    #define OPTCFGXHCI_NOPERACT_EN			BIT3	//1b/1b/1b/x SSTRANS Enable to Bypass Async EOF Requirement if No Periodic Endpoint Active
    #define OPTCFGXHCI_INCMPLFLSH_EN			BIT2	//0/0/0/x SSTRANS Enable to Send Back IN Data after Entire DP Receiving Successfully
    #define OPTCFGXHCI_INONEDP_EN			BIT1	//0/0/0/x SSTRANS Enable to IN One DP for Each Request  (Always NumP=1)
    #define OPTCFGXHCI_OUTONEDP_EN			BIT0	//0/0/0/x SSTRANS Enable to Out One DP Before Receiving ACK Response Enable Bit (OUT Bursting Enable/Disable)
#define OPTCFGXHCI_XHCIOPTION_RX61		0x61	//xHCI Option RX61
    #define OPTCFGXHCI_RESERVED_Z41			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_ISOOVERUNDERRUN_TRPTR_EN			BIT5	//0/0/x/0 ISOOVERUNDERRUN_TRPTR_EN
    #define OPTCFGXHCI_SSBI_BFEMPTY_BLKHIT_EN			BIT4	//1b/1b/x/x SSTRANS Enable to Check DPH HIT if No Buffer Valid
    #define OPTCFGXHCI_SSBI_TXIF_LINKUP_CHKEN			BIT3	//1b/1b/x/x SSTRANS Enable to Check LINKUP Information at TXIF
    #define OPTCFGXHCI_INTDREQONE_EN			BIT2	//0/0/x/x SSTRANS Enable to Request INPKTCTL One Time Only Each Service
    #define OPTCFGXHCI_INONETD_EN			BIT1	//0/0/0/x SSTRANS Enable to IN TDCTL Working One by One
    #define OPTCFGXHCI_OUTONETD_EN			BIT0	//0/0/0/x SSTRANS Enable to Out TDCTL Working One by One
#define OPTCFGXHCI_XHCIOPTION_RX62		0x62	//xHCI Option RX62
    #define OPTCFGXHCI_RESERVED_Z42			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_INBUFVALIDTIME			0x3F	//20h/20h/x/x IN Buffer Request Timeout Parameter (Unit: 8ns)
#define OPTCFGXHCI_XHCIOPTION_RX63		0x63	//xHCI Option RX63
    #define OPTCFGXHCI_INBUFLOOP_PARM			0xFF	//3h/03h/x/x IN Buffer Request Loop Parameter
#define OPTCFGXHCI_XHCIOPTION_RX64		0x64	//xHCI Option RX64
    #define OPTCFGXHCI_RESERVED_Z43			(BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGXHCI_SS_TMOUT_PARM			0x3FFF	//109Ah/109Ah/x/x SS Transaction TimeOut Parameter (Unit: 8ns)
#define OPTCFGXHCI_XHCIOPTION_RX66		0x66	//xHCI Option RX66
    #define OPTCFGXHCI_RESERVED_Z44			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PEREOF1_PARM			0x1F	//19h/19h/x/x Periodic EOF1 Parameter
#define OPTCFGXHCI_XHCIOPTION_RX67		0x67	//xHCI Option RX67
    #define OPTCFGXHCI_RESERVED_Z45			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PEREOF2_PARM			0x1F	//0Fh/0Fh/x/x Periodic EOF2 Parameter
#define OPTCFGXHCI_XHCIOPTION_RX68		0x68	//xHCI Option RX68
    #define OPTCFGXHCI_RESERVED_Z46			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_ASYEOF1_PARM			0x1F	//0Ah/0Ah/x/x Async EOF1 Parameter
#define OPTCFGXHCI_XHCIOPTION_RX69		0x69	//xHCI Option RX69
    #define OPTCFGXHCI_RESERVED_Z47			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_ASYEOF2_PARM			0x1F	//02h/02h/x/x Async EOF2 Parameter
#define OPTCFGXHCI_XHCIOPTION_RX6A		0x6A	//xHCI Option RX6A
    #define OPTCFGXHCI_RESERVED_Z48			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_ENDOFSI_PARM			0x1F	//0Ah/0Ah/x/x Periodic End of Service Interval Parameter
#define OPTCFGXHCI_XHCIOPTION_RX6B		0x6B	//XHCI Option RX6B
    #define OPTCFGXHCI_RESERVED_Z49			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PERPREFETCH_PARM			0x1F	//08h/08h/x/x Periodic Endpoint Pre-Fetch Parameter
#define OPTCFGXHCI_XHCIOPTION_RX6C		0x6C	//xHCI Option RX6C
    #define OPTCFGXHCI_RESERVED_Z50			0xF800	//0/R/x/x Reserved
    #define OPTCFGXHCI_NUMP0_ERDYTMOUT_PARM			0x7FF	//7h/7h/x/x SS Transaction OUTPKTCTL NUMP0 ERDY TimeOut Parameter (Unit: 8ns)
#define OPTCFGXHCI_XHCIOPTION_RX6E		0x6E	//xHCI Option RX6E
    #define OPTCFGXHCI_RESERVED_Z51			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS2			BIT4	//0/0/x/x Enable Port2 link State Go to RXSETECT when in DISABLE State
    #define OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS1			BIT3	//0/0/x/x Enable Port1 link State Go to RXSETECT when in DISABLE State
    #define OPTCFGXHCI_WRDY_NUM			(BIT0 + BIT1 + BIT2)	//0/0/x/x WRDY_NUM
#define OPTCFGXHCI_XHCIOPTION_RX6F		0x6F	//xHCI Option Rx6F
    #define OPTCFGXHCI_RESERVED_Z52			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_FLR_WRST_EN			BIT4	//1b/x/x/x FLR Warm Reset Enable
    #define OPTCFGXHCI_FLR_HCRST_EN			BIT3	//1b/x/x/x FLR HCRST Enable
    #define OPTCFGXHCI_FLR_CAP_EN			BIT2	//1b/x/x/x FLR Capbility Enable
    #define OPTCFGXHCI_BYPASS_FLR			BIT1	//0/0/x/x Bypass FLR for SSIP
    #define OPTCFGXHCI_FLR_EN			BIT0	//1b/1b/x/x FLR Enable
#define OPTCFGXHCI_XHCIOPTION_RX70		0x70	//xHCI Option RX70
    #define OPTCFGXHCI_RESERVED_Z53			0xFFFFFFFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_HS_ISOINHC4_EN			BIT1	//0/0/x/x xHCI HSBI ISO C4 Inhibit Enable
    #define OPTCFGXHCI_SS_EN			BIT0	//0/0/x/x xHCI SSBI ISO C4 Inhibit Enable
#define OPTCFGXHCI_XHCIOPTION_RX74		0x74	//xHCI Option RX74
    #define OPTCFGXHCI_RESERVED_Z54			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_S_SSPMODE_SS2			BIT6	//0/x/x/x Indicate Port2 Is 10G Mode
    #define OPTCFGXHCI_SSP_S_RCVOTG_SS2			BIT5	//0/x/x/x Indicate Port2 Receive Port Capability LMP with OTG Bit Is 1
    #define OPTCFGXHCI_RESERVED_Z55			(BIT3 + BIT4)	//0/R/x/x Reserved
    #define OPTCFGXHCI_S_SSPMODE_SS1			BIT2	//0/x/x/x Indicate Port1 Is 10G Mode
    #define OPTCFGXHCI_SSP_S_RCVOTG_SS1			BIT1	//0/x/x/x Indicate Port1 Receive Port Capability LMP with OTG Bit Is 1
    #define OPTCFGXHCI_RESERVED_Z56			BIT0	//0/R/x/x R_PORT_COMPLIANCE_SS1
#define OPTCFGXHCI_XHCIOPTION_RX77		0x77	//xHCI Option RX77
    #define OPTCFGXHCI_RESERVED_Z57			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_U1ENABLE_SS2			BIT1	//0/0/x/x Enable Port2 Support U1 When Port Is UFP
    #define OPTCFGXHCI_R_U1ENABLE_SS1			BIT0	//0/0/x/x Enable Port1 Support U1 When Port Is UFP
#define OPTCFGXHCI_XHCIOPTION_RX78		0x78	//xHCI Option RX78
    #define OPTCFGXHCI_RESERVED_Z58			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_U2ENABLE_SS2			BIT1	//0/0/x/x Enable Port2 Support U2 When Port Is UFP
    #define OPTCFGXHCI_R_U2ENABLE_SS1			BIT0	//0/0/x/x Enable Port1 Support U2 When Port Is UFP
#define OPTCFGXHCI_XHCIOPTION_RX79		0x79	//xHCI Option RX79
    #define OPTCFGXHCI_USB2P1_UPSIE_CLK_60M_DYNCLKEN			BIT7	//0/0/x/1b CLK_60M Dynamic Clk Enable Of UPSIE In HSTTX2_A Module
    #define OPTCFGXHCI_USB2P1_UPSIE_CLK_120M_DYNCLKEN			BIT6	//0/0/x/1b CLK_120M Dynamic Clk Enable Of UPSIE In HSTTX2_A Module 
    #define OPTCFGXHCI_USB2P1_TT_CLK_60M_DYNCLKEN			BIT5	//0/0/x/1b CLK_60M Dynamic Clk Enable Of HSTTX2_A Module
    #define OPTCFGXHCI_USB2P1_DN_CLK_120M_DYNCLKEN			BIT4	//0/0/x/1b CLK_120M Dynamic Clk Enable Of DN In HSTTX2_A Module
    #define OPTCFGXHCI_USB2P1_LPM_FS_CLK_120M_DYNCLKEN			BIT3	//0/0/x/1b CLK_120M Dynamic Clk Enable Of LPM_FS
    #define OPTCFGXHCI_USB2P1_LPM_FS_CLK_60M_DYNCLKEN			BIT2	//0/0/x/1b CLK_60M Dynamic Clk Enable Of LPM_FS
    #define OPTCFGXHCI_USB2P1_DNSIE_CLK_60M_DYNCLKEN			BIT1	//0/0/x/1b CLK_60M Dynamic Clk Enable Of DNSIE
    #define OPTCFGXHCI_USB2P1_DNSIE_CLK_120M_DYNCLKEN			BIT0	//0/0/x/1b CLK_120M Dynamic Clk Enable Of DNSIE
#define OPTCFGXHCI_XHCIOPTION_RX7A		0x7A	//xHCI Option RX7A
    #define OPTCFGXHCI_USB2P2_UPSIE_CLK_60M_DYNCLKEN			BIT7	//0/0/x/1b CLK_60M Dynamic Clk Enable Of UPSIE In HSTTX2_B Module
    #define OPTCFGXHCI_USB2P2_UPSIE_CLK_120M_DYNCLKEN			BIT6	//0/0/x/1b CLK_120M Dynamic Clk Enable Of UPSIE In HSTTX2_B Module
    #define OPTCFGXHCI_USB2P2_TT_CLK_60M_DYNCLKEN			BIT5	//0/0/x/1b CLK_60M Dynamic Clk Enable Of HSTTX2_B Module 
    #define OPTCFGXHCI_USB2P2_DN_CLK_120M_DYNCLKEN			BIT4	//0/0/x/1b CLK_120M Dynamic Clk Enable Of DN In HSTTX2_B Module
    #define OPTCFGXHCI_USB2P2_LPM_FS_CLK_120M_DYNCLKEN			BIT3	//0/0/x/1b CLK_120M Dynamic Clk Enable Of LPM_FS
    #define OPTCFGXHCI_USB2P2_LPM_FS_CLK_60M_DYNCLKEN			BIT2	//0/0/x/1b CLK_60M Dynamic Clk Enable Of LPM_FS
    #define OPTCFGXHCI_USB2P2_DNSIE_CLK_60M_DYNCLKEN			BIT1	//0/0/x/1b CLK_60M Dynamic Clk Enable Of DNSIE
    #define OPTCFGXHCI_USB2P2_DNSIE_CLK_120M_DYNCLKEN			BIT0	//0/0/x/1b CLK_120M Dynamic Clk Enable Of DNSIE
#define OPTCFGXHCI_XHCIOPTION_RX7E		0x7E	//xHCI Option RX7E
    #define OPTCFGXHCI_RESERVED_Z59			0xF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_USB2P2_DNSIE_CLK_1M5_DYNCLKEN			BIT3	//0/0/x/1b CLK_1M5 Dynamic Clk Enable Of DNSIE
    #define OPTCFGXHCI_USB2P2_DNSIE_CLK_12M_DYNCLKEN			BIT2	//0/0/x/1b CLK_12M Dynamic Clk Enable Of DNSIE
    #define OPTCFGXHCI_USB2P1_DNSIE_CLK_1M5_DYNCLKEN			BIT1	//0/0/x/1b CLK_1M5 Dynamic Clk Enable Of DNSIE
    #define OPTCFGXHCI_USB2P1_DNSIE_CLK_12M_DYNCLKEN			BIT0	//0/0/x/1b CLK_12M Dynamic Clk Enable Of DNSIE
#define OPTCFGXHCI_XHCIOPTION_RX7F		0x7F	//xHCI Option RX7F
    #define OPTCFGXHCI_RESERVED_Z60			0xF8	//0/R/x/x Reserved
    #define OPTCFGXHCI_UPSIE_MAC_60M_DYNCLKEN			BIT2	//0/0/x/1b CLK_60M Dynamic Clk Enable Of UPSIE_MAC
    #define OPTCFGXHCI_USB2P2_DNSIE_RCLK_DYNCLKEN			BIT1	//0/0/x/1b RCLK  Dynamic Clk Enable Of DNSIE
    #define OPTCFGXHCI_USB2P1_DNSIE_RCLK_DYNCLKEN			BIT0	//0/0/x/1b RCLK  Dynamic Clk Enable Of DNSIE
#define OPTCFGXHCI_XHCIOPTION_RX80		0x80	//xHCI Option RX80
    #define OPTCFGXHCI_RESERVED_Z61			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PCAPDIR_SEL_SS2			BIT5	//1b/1b/x/x PCAPDIR_SEL_SS2
    #define OPTCFGXHCI_PCAPDIR_SEL_SS1			BIT4	//1b/1b/x/x PCAPDIR_SEL_SS1
    #define OPTCFGXHCI_RESERVED_Z62			(BIT2 + BIT3)	//0/R/x/x Reserved
    #define OPTCFGXHCI_IPTYPE_SEL_SS2			BIT1	//1b/1b/x/x IPTYPE_SEL_SS2
    #define OPTCFGXHCI_IPTYPE_SEL_SS1			BIT0	//1b/1b/x/x IPTYPE_SEL_SS1
#define OPTCFGXHCI_XHCIOPTION_RX84		0x84	//xHCI Option RX84
    #define OPTCFGXHCI_RESERVED_Z63			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_U3DBC_EN			BIT0	//1b/1b/x/x U3DBC Enable
#define OPTCFGXHCI_XHCIOPTION_RX85		0x85	//xHCI Option RX85
    #define OPTCFGXHCI_RESERVED_Z64			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_SSP2_WAKEUPEN			BIT1	//1b/1b/x/x USB3.0 Port 2 Wakeup Enable
    #define OPTCFGXHCI_SSP1_WAKEUPEN			BIT0	//1b/1b/x/x USB3.0 Port 1 Wakeup Enable
#define OPTCFGXHCI_XHCIOPTION_RX87		0x87	//xHCI Option RX87
    #define OPTCFGXHCI_RESERVED_Z65			0xF8	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCUHOC_EN			BIT2	//0/0/x/x Enable MCU FW Handle Over-current Event 
    #define OPTCFGXHCI_WOE_FW			BIT1	//0/0/x/x Wake on Over-current Enable Set by MCU FW
    #define OPTCFGXHCI_WCE_FW			BIT0	//0/0/x/x Wake on Connect Enable Set by MCU FW 
#define OPTCFGXHCI_XHCIOPTION_RX88		0x88	//xHCI Option RX88
    #define OPTCFGXHCI_RESERVED_Z66			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_M30PHYPD_MASK			BIT5	//0/x/0/0 M30PHYPD_MASK
    #define OPTCFGXHCI_M20PHYPD_MASK			BIT4	//0/x/0/0 M20PHYPD_MASK
    #define OPTCFGXHCI_RESERVED_Z67			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_U2PHY_PDSUSMOD_REG			BIT2	//0/0/x/x U2PHY_PDSUSMOD_REG
    #define OPTCFGXHCI_U2PHY_PDAPLL_REG			BIT1	//0/0/x/x U2PHY_PDAPLL_REG
    #define OPTCFGXHCI_RESERVED_Z68			BIT0	//0/R/x/x Reserved
#define OPTCFGXHCI_XHCIOPTION_RX89		0x89	//xHCI Option RX89
    #define OPTCFGXHCI_RESERVED_Z69			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_SSPMODEN_SS2			BIT4	//0/0/x/x SSP Port2 10G Mode Enable
    #define OPTCFGXHCI_RESERVED_Z70			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_SSPMODEN_SS1			BIT0	//0/0/x/x SSP Port1 10G Mode Enable
#define OPTCFGXHCI_XHCIOPTION_RX8B		0x8B	//xHCI Option RX8B
    #define OPTCFGXHCI_RESERVED_Z71			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_REG_USB2P2_KEEP_LINK_NOT2L1			BIT1	//0/0/x/x REG_USB2P2_KEEP_LINK_NOT2L1
    #define OPTCFGXHCI_REG_USB2P1_KEEP_LINK_NOT2L1			BIT0	//0/0/x/x REG_USB2P1_KEEP_LINK_NOT2L1
#define OPTCFGXHCI_XHCIOPTION_RX8C		0x8C	//xHCI Option RX8C
    #define OPTCFGXHCI_R_SS_PLC_TST_OPT			BIT31	//1b/1b/x/x R_SS_PLC_TST_OPT
    #define OPTCFGXHCI_R_HCRST_WRST_EN			BIT30	//1b/1b/x/x R_HCRST_WRST_EN
    #define OPTCFGXHCI_OPTCFG_XHCI_RX8C_30_20			0x3FF00000	//3CFh/3CFh/x/x Reserved (Do Not Program)
    #define OPTCFGXHCI_REG_U2S0_WAKUP_SEL			BIT19	//1b/1b/x/x Reserved (Do Not Program)
    #define OPTCFGXHCI_WAKEUPSEL_EN			BIT18	//1b/1b/x/x Reserved (Do Not Program)
    #define OPTCFGXHCI_CRESUMEPATCH			BIT17	//1b/1b/x/x RESUME Patch Enable Bit
    #define OPTCFGXHCI_RESUMEBLK			BIT16	//1b/1b/x/x RESUME Block Enable
    #define OPTCFGXHCI_OPTCFG_XHCI_RX8C_15_5			0xFFE0	//7h/7h/x/x Reserved (Do Not Program)
    #define OPTCFGXHCI_R_USB2_PLS_RSM			BIT4	//1b/1b/x/x R_USB2_PLS_RSM
    #define OPTCFGXHCI_R_WRST_CPL_PR_EN			BIT3	//1b/1b/x/x R_WRST_CPL_PR_EN
    #define OPTCFGXHCI_R_USB2_PR_CPL_SEL			BIT2	//0/0/x/x R_USB2_PR_CPL_SEL
    #define OPTCFGXHCI_R_USB2_SYN_RFSEL			BIT1	//1b/1b/x/x R_USB2_SYN_RFSEL
    #define OPTCFGXHCI_R_CLRUX_EN			BIT0	//0/0/x/x R_CLRUX_EN
#define OPTCFGXHCI_XHCIOPTION_RX90		0x90	//xHCI Option RX90
    #define OPTCFGXHCI_RESERVED_Z72			0xFFFFFF80	//0/R/x/x Reserved
    #define OPTCFGXHCI_SS1_PORT_MODSTS			(BIT4 + BIT5 + BIT6)	//001b/001b/x/x SSPort Mode Select Status
    #define OPTCFGXHCI_RESERVED_Z73			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_SS1_PORT_MODSEL			(BIT0 + BIT1 + BIT2)	//101b/101b/x/x SSPort Mode Select
#define OPTCFGXHCI_XHCIOPTION_RX94		0x94	//xHCI Option RX94
    #define OPTCFGXHCI_RESERVED_Z74			0xFFFFFF80	//0/R/x/x Reserved
    #define OPTCFGXHCI_SS2_PORT_MODSTS			(BIT4 + BIT5 + BIT6)	//001b/001b/x/x SSPort Mode Select Status
    #define OPTCFGXHCI_RESERVED_Z75			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_SS2_PORT_MODSEL			(BIT0 + BIT1 + BIT2)	//101b/101b/x/x SSPort Mode Select
#define OPTCFGXHCI_XHCIOPTION_RXA0		0xA0	//xHCI Option RXA0
    #define OPTCFGXHCI_RESERVED_Z76			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCUFLTDB_EN			BIT1	//0/0/x/x MCU Set Filter Doorbell Enable
    #define OPTCFGXHCI_HWFLTDB_EN			BIT0	//1b/1b/x/x HW Filter Duplicate Doorbell Enable
#define OPTCFGXHCI_XHCIOPTION_RXA4		0xA4	//xHCI Option RXA4
    #define OPTCFGXHCI_MCUFLTDB_SLOT1			0xFF000000	//0/0/x/x MCU Filter Doorbell Slot 1
    #define OPTCFGXHCI_MCUFLTDB_DCI1			0xFF0000	//0/0/x/x MCU Filter Doorbell DCI 1
    #define OPTCFGXHCI_MCUFLTDB_SLOT0			0xFF00	//0/0/x/x MCU Filter Doorbell Slot 0
    #define OPTCFGXHCI_MCUFLTDB_DCI0			0xFF	//0/0/x/x MCU Filter Doorbell DCI 0
#define OPTCFGXHCI_XHCIOPTION_RXA8		0xA8	//xHCI Option RXA8
    #define OPTCFGXHCI_MCUFLTDB_SLOT3			0xFF000000	//0/0/x/x MCU Filter Doorbell Slot 3
    #define OPTCFGXHCI_MCUFLTDB_DCI3			0xFF0000	//0/0/x/x MCU Filter Doorbell DCI 3
    #define OPTCFGXHCI_MCUFLTDB_SLOT2			0xFF00	//0/0/x/x MCU Filter Doorbell Slot 2
    #define OPTCFGXHCI_MCUFLTDB_DCI2			0xFF	//0/0/x/x MCU Filter Doorbell DCI 2
#define OPTCFGXHCI_XHCIOPTION_RXAC		0xAC	//xHCI Option RXAC
    #define OPTCFGXHCI_MCUFLTDB_SLOT5			0xFF000000	//0/0/x/x MCU Filter Doorbell Slot 5
    #define OPTCFGXHCI_MCUFLTDB_DCI5			0xFF0000	//0/0/x/x MCU Filter Doorbell DCI 5
    #define OPTCFGXHCI_MCUFLTDB_SLOT4			0xFF00	//0/0/x/x MCU Filter Doorbell Slot 4
    #define OPTCFGXHCI_MCUFLTDB_DCI4			0xFF	//0/0/x/x MCU Filter Doorbell DCI 4
#define OPTCFGXHCI_XHCIOPTION_RXB0		0xB0	//xHCI Option RXB0
    #define OPTCFGXHCI_MCUFLTDB_SLOT7			0xFF000000	//0/0/x/x MCU Filter Doorbell Slot 7
    #define OPTCFGXHCI_MCUFLTDB_DCI7			0xFF0000	//0/0/x/x MCU Filter Doorbell DCI 7
    #define OPTCFGXHCI_MCUFLTDB_SLOT6			0xFF00	//0/0/x/x MCU Filter Doorbell Slot 6
    #define OPTCFGXHCI_MCUFLTDB_DCI6			0xFF	//0/0/x/x MCU Filter Doorbell DCI 6
#define OPTCFGXHCI_XHCIOPTION_RXB4		0xB4	//xHCI Option RXB4
    #define OPTCFGXHCI_MCUFLTDB_SLOT9			0xFF000000	//0/0/x/x MCU Filter Doorbell Slot 9
    #define OPTCFGXHCI_MCUFLTDB_DCI9			0xFF0000	//0/0/x/x MCU Filter Doorbell DCI 9
    #define OPTCFGXHCI_MCUFLTDB_SLOT8			0xFF00	//0/0/x/x MCU Filter Doorbell Slot 8
    #define OPTCFGXHCI_MCUFLTDB_DCI8			0xFF	//0/0/x/x MCU Filter Doorbell DCI 8
#define OPTCFGXHCI_XHCIOPTION_RXB8		0xB8	//xHCI Option RXB8
    #define OPTCFGXHCI_MCUFLTDB_SLOT11			0xFF000000	//0/0/x/x MCU Filter Doorbell Slot 11
    #define OPTCFGXHCI_MCUFLTDB_DCI11			0xFF0000	//0/0/x/x MCU Filter Doorbell DCI 11
    #define OPTCFGXHCI_MCUFLTDB_SLOT10			0xFF00	//0/0/x/x MCU Filter Doorbell Slot 10
    #define OPTCFGXHCI_MCUFLTDB_DCI10			0xFF	//0/0/x/x MCU Filter Doorbell DCI 10
#define OPTCFGXHCI_XHCIOPTION_RXBC		0xBC	//xHCI Option RxBC
    #define OPTCFGXHCI_DSRD_FLR			0xFFFFFFFF	//FFFFFFFFh/FFFFFFFFh/x/x The Data Return to C2P Read Cycle when Doing FLR
#define OPTCFGXHCI_XHCIOPTION_RXC0		0xC0	//xHCI Option RxC0
    #define OPTCFGXHCI_RESERVED_Z77			0xFFFFFF80	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCUCHKEN			BIT6	//0/0/x/x MCU Address Range Check En
    #define OPTCFGXHCI_MCUDMASEL			BIT5	//0/0/x/x MCU DMA Path Selection
    #define OPTCFGXHCI_UART_MSTREN			BIT4	//1b/1/x/x UART_MSTREN
    #define OPTCFGXHCI_MCUDMA_BMSTR_BLKDIS			BIT3	//1b/1/x/x MCUDMA_BMSTR_BLKDIS
    #define OPTCFGXHCI_R_MSIWBE_PATCH			BIT2	//1b/1/x/x MSI WBE Patch
    #define OPTCFGXHCI_MSI_BLOCK_EN			BIT1	//0/0/x/x MSI Block Enable
    #define OPTCFGXHCI_OVER64G_ADREN			BIT0	//0/0/x/x Over 64G Address Enable
#define OPTCFGXHCI_XHCIOPTION_RXC4		0xC4	//xHCI Option RxC4
    #define OPTCFGXHCI_RESERVED_Z78			0xF0000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCUDMABASE			0xFFFFFFF	//0/0/x/x MCU DMA Base
#define OPTCFGXHCI_XHCIOPTION_RXC8		0xC8	//xHCI Option RxC8
    #define OPTCFGXHCI_RESERVED_Z79			0xF0000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCUDMALIMIT			0xFFFFFFF	//0/0/x/x MCU DMA Limit
#define OPTCFGXHCI_XHCIOPTION_RXCC		0xCC	//xHCI Option RxCC
    #define OPTCFGXHCI_RESERVED_Z80			0xFFFFFFF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCU_HADDR_PATCH			0xF	//0/0/x/x MCU_HADDR_PATCH
#define OPTCFGXHCI_XHCIOPTION_RXD0		0xD0	//xHCI Option RXD0
    #define OPTCFGXHCI_OPTCFG_XHCI_RXD0_31_28			0xF0000000	//Eh/Eh/x/x OPTCFG_XHCI_RXD0_31_28
    #define OPTCFGXHCI_LOWPWR_DIS_PKTTIMER_EN			BIT27	//1b/1b/x/x Counting Enables  Of PKTTIMER Of SSBI PKTINCTL In Low Power State 
    #define OPTCFGXHCI_SAMSUNG_PATCH			BIT26	//1b/1b/x/x Patch Bit. 
    #define OPTCFGXHCI_ISOEDLTA_PATCH_EN			BIT25	//1b/1b/x/x EDTLA Update Enable When Not Success Of SSBI ISOEPCTL 
    #define OPTCFGXHCI_BABBLE_DETNEW_EN			BIT24	//1b/1b/x/x Enable To Report Babble Error If DP Received Is 
    #define OPTCFGXHCI_R_FWDISLINK_EN			BIT23	//1b/1b/x/x Enable F/W To Control Link Enter Disabled State
    #define OPTCFGXHCI_R_FAKER_PED1TO0			BIT22	//1b/1b/x/x Enable To Set SSLINK_FAKEDIS  =0 , When SW Set PED Bit Of DBC PORTSC To 0 
    #define OPTCFGXHCI_R_FAKER_DCE1TO0			BIT21	//1b/1b/x/x Enable To Set SSLINK_FAKEDIS  =0 , When SW Set DBC_DCE 0
    #define OPTCFGXHCI_R_DCE0_U0_FORCE_CCSPED1			BIT20	//1b/1b/x/x Enable To Set CCS And PED Of DBC PORTSC To 1 When SW Set DCE To1 And DBC PORT In U0 State 0: Disable
    #define OPTCFGXHCI_R_DEFER_STS_DET_EN			BIT19	//1b/1b/x/x Defer Status TP Detection Enable
    #define OPTCFGXHCI_OPTCFG_XHCI_RXD0_18_16			(BIT16 + BIT17 + BIT18)	//110b/110b/x/x OPTCFG_XHCI_RXD0_18_16
    #define OPTCFGXHCI_ISOEP_TMOUT_PARM			0xFFE0	//20h/20h/x/x ISOOUT EP Check Response Time-Out Timer
    #define OPTCFGXHCI_ISOOUT_DEFER_EN			BIT4	//0/0/x/x Enable ISOOUT EP Check Deferred DP Response
    #define OPTCFGXHCI_R_PED1TO0_CCSKEEP_EN			BIT3	//0/0/x/x When PED Is Written To 0, Link Enter Disabled State, Keep Current Connect Status As 1
    #define OPTCFGXHCI_R_DBC_DCE0_DISLINK			BIT2	//0/0/x/x Optioanl Register For DBC
    #define OPTCFGXHCI_R_DBC_PED0_DISLINK			BIT1	//0/0/x/x Optioanl Register For DBC
    #define OPTCFGXHCI_PTDQUEUE_NONEMPTY_STOP_EN			BIT0	//0/0/x/x Enable To STOP Periodic Transfer When PTDQUEUE Is Not Empty
#define OPTCFGXHCI_XHCIOPTION_RXD4		0xD4	//xHCI Option RXD4
    #define OPTCFGXHCI_OPTCFG_XHCI_RXD4_31_27			0xF0000000	//1111b/x/x/x OPTCFG_XHCI_RXD4_31_27
    #define OPTCFGXHCI_R_CTLSETADDR_EN			BIT27	//1b/1b/x/x Enable Of DFTCTLGONXTTD Valid  When Current TRB  Is Setup TRB  With"SetAddress" Request
    #define OPTCFGXHCI_ERBEIPATCH			BIT26	//1b/1b/x/x ER BEI Dessert Patch Bit
    #define OPTCFGXHCI_CTLEP_RXDP_DATAOUT_PATCH			BIT25	//1b/1b/x/x Fix For xHCI_DBC Control Out (Length>0) + Control Out Sequence
    #define OPTCFGXHCI_R_APISIDLE_LMP			BIT24	//1b/1b/x/x 1: Deassert SSIP APISIDLE Signal When Sending U2Inactiver LMP;
    #define OPTCFGXHCI_R_INTSTS_HALT			BIT23	//1b/1b/x/x Enable To Stop 1 Interrupt Enpoint SO When MCU  Handler Periodic Halt Interrupt
    #define OPTCFGXHCI_R_INTSTS_EMPTY			BIT22	//1b/1b/x/x Enable To Stop 1 Interrupt Enpoint SO When MCU  Handler Periodic TREmpty Interrupt
    #define OPTCFGXHCI_R_INTSTS_TRBERR			BIT21	//1b/1b/x/x Enable To Stop 1 Interrupt Enpoint SO When MCU  Handler Periodic TRB Error Interrupt
    #define OPTCFGXHCI_R_ASYTOPER_EN			BIT20	//1b/1b/x/x Enable To Restart Periodic Engine When Async Engine Stop At uFrame Boundary
    #define OPTCFGXHCI_OPTCFG_XHCI_RXD4_19_19			BIT19	//1b/1b/x/x OPTCFG_XHCI_RXD4_19_19
    #define OPTCFGXHCI_ERFULLBEI_EN			BIT18	//1b/1b/x/x Enable Of Set IPE =1 When Send EVENT RING FULL ERROR Event
    #define OPTCFGXHCI_R_64BITR_D3_PATCH			BIT17	//1b/1b/x/x Patch 64-Bit Read In D3 Mode
    #define OPTCFGXHCI_R_64BITW_PMREG_PATCH			BIT16	//1b/1b/x/x Patch 64-Bit Write To Rx80 (PMU Related Register) When Not In D3 Mode
    #define OPTCFGXHCI_OPTCFG_XHCI_RXD4_15_8			0xFF00	//1h/1h/x/x OPTCFG_XHCI_RXD4_15_8
    #define OPTCFGXHCI_R_1PKTERDY_EN			BIT7	//1b/1b/x/x Enable Of NRDYEP_MAXBSZ Equal To 0
    #define OPTCFGXHCI_OPTCFG_XHCI_RXD4_6_6			BIT6	//0/0/x/x Enable Of MCU_ACTIVE  To Gating HCHALTED 
    #define OPTCFGXHCI_R_DSREQ_SEL			BIT5	//0/0/x/x R_DSREQ_SEL
    #define OPTCFGXHCI_R_DNBLK_SEL			(BIT3 + BIT4)	//0/0/x/x R_DNBLK_SEL
    #define OPTCFGXHCI_R_ISOTDPC_CORNER_EN			BIT2	//0/0/x/x R_ISOTDPC_CORNER_EN
    #define OPTCFGXHCI_R_TRANSERR_NEW_EN			BIT1	//0/0/x/x R_TRANSERR_NEW_EN
    #define OPTCFGXHCI_FIX_OUT_STREAMSTSERROR_EN			BIT0	//0/0/x/x FIX_OUT_STREAMSTSERROR_EN
#define OPTCFGXHCI_XHCIOPTION_RXD8		0xD8	//xHCI Option RXD8
    #define OPTCFGXHCI_PATCHBITS4			0xFFFFFFFF	//FFFF0000h/x/x/x xHCI Patch Optional Bits 4 (Suspend Power Domain)
#define OPTCFGXHCI_XHCIOPTION_RXDC		0xDC	//xHCI Option RXDC
    #define OPTCFGXHCI_PATCHBITS5			0xFFFFFFFF	//FFFF0000h/x/x/x xHCI Patch Optional Bits 5 (Suspend Power Domain)
#define OPTCFGXHCI_XHCIOPTION_RXE0		0xE0	//xHCI Option RXE0
    #define OPTCFGXHCI_SWFWMSG0			0xFFFFFFFF	//0/0/x/x SW Debug Message to MCU FW DW0
#define OPTCFGXHCI_XHCIOPTION_RXE4		0xE4	//xHCI Option RXE4
    #define OPTCFGXHCI_SWFWMSG1			0xFFFFFFFF	//0/0/x/x SW Debug Message to MCU FW DW1
#define OPTCFGXHCI_XHCIOPTION_RXE8		0xE8	//xHCI Option RXE8
    #define OPTCFGXHCI_SWFWMSG2			0xFFFFFFFF	//0/0/x/x SW Debug Message to MCU FW DW2
#define OPTCFGXHCI_XHCIOPTION_RXEC		0xEC	//xHCI Option RXEC
    #define OPTCFGXHCI_SWFWMSG3			0xFFFFFFFF	//0/0/x/x SW Debug Message to MCU FW DW3
#define OPTCFGXHCI_XHCIOPTION_RXF0		0xF0	//xHCI Option RXF0
    #define OPTCFGXHCI_CTLEP_SETUPCMPL_CLR_PATCH			BIT31	//1b/1b/x/x CTLEP_SETUPCMPL_CLR_PATCH
    #define OPTCFGXHCI_R_ASYNCLIST_SEL			BIT30	//1b/1b/x/x R_ASYNCLIST_SEL
    #define OPTCFGXHCI_TXINPKT_REQ_SEL			BIT29	//1b/1b/x/x TXINPKT_REQ_SEL
    #define OPTCFGXHCI_BLKOUT_TRBERR_INBUFEDY_CLR_OPTION			BIT28	//1b/1b/x/x Enable of CTLEP_SETUPCMPL_CLRBLKOUT_INBUFRDY_CLR valid when TRBERR in DBC OUTEPCTL 
    #define OPTCFGXHCI_ERSTSZ_EQ0_PATCH			BIT27	//1b/1b/x/x ERSTSZ_EQ0_PATCH
    #define OPTCFGXHCI_RESERVED_Z81			0x7FFF000	//0/R/x/x Reserved
    #define OPTCFGXHCI_OUTPKT_REQ_GATE_EN			BIT11	//1b/1b/x/x OUTPKT_REQ_GATE_EN
    #define OPTCFGXHCI_RESERVED_Z82			BIT10	//0/R/x/x Reserved
    #define OPTCFGXHCI_INPKT_PP_CHK_EN			BIT9	//0/0/x/x INPKT_PP_CHK_EN
    #define OPTCFGXHCI_ISOBWOVERRUN_PATCH_EN			BIT8	//1b/1b/x/x ISOBWOVERRUN_PATCH_EN
    #define OPTCFGXHCI_CTLEP_ACKTP_NUMP_SEL			BIT7	//1b/1b/x/x CTLEP_ACKTP_NUMP_SEL
    #define OPTCFGXHCI_MCUDMAARB_OPT			BIT6	//0/0/x/x MCUDMAARB_OPT
    #define OPTCFGXHCI_MPT_CACHE_RSTEN			BIT5	//1b/1b/x/x MPT_CACHE_RSTEN
    #define OPTCFGXHCI_BLK_TRBRREQ_EN			BIT4	//0/0/x/x BLK_TRBRREQ_EN
    #define OPTCFGXHCI_DMARFULL_SEL			BIT3	//0/0/x/x DMARFULL_SEL
    #define OPTCFGXHCI_DMAMUXOC_EN			BIT2	//1b/1b/x/x DMAMUXOC_EN
    #define OPTCFGXHCI_OUTP_RB			BIT1	//0/0/x/x OUTP_RB
    #define OPTCFGXHCI_BFIN_RLSNEW			BIT0	//0/0/x/x BFIN_RLSNEW
#define OPTCFGXHCI_XHCIOPTION_RXF4		0xF4	//xHCI Option RXF4
    #define OPTCFGXHCI_RESERVED_Z83			BIT31	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_TDINRSPQUEUE_FULL_PATCH			BIT30	//1b/1b/x/x R_TDINRSPQUEUE_FULL_PATCH
    #define OPTCFGXHCI_RESERVED_Z84			0x3C000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_PTT_DN_MASK			BIT25	//1b/1b/x/x R_PTT_DN_MASK
    #define OPTCFGXHCI_R_BFINRLS_CASE4			BIT24	//0/0/x/x Reserved
    #define OPTCFGXHCI_R_BFINRLS_CASE3			BIT23	//0/0/x/x Reserved
    #define OPTCFGXHCI_R_BFINRLS_CASE2			BIT22	//0/0/x/x Reserved
    #define OPTCFGXHCI_R_BFINRLS_CASE1			BIT21	//0/0/x/x Reserved
    #define OPTCFGXHCI_SS_ISO_LPF_CHKEN			BIT20	//1b/1b/x/x SS_ISO_LPF_CHKEN
    #define OPTCFGXHCI_R_RAPOO_PATCH			BIT19	//1b/1b/x/x R_RAPOO_PATCH0: Original design1: Enable patch
    #define OPTCFGXHCI_R_MCUDMA_ALIGN			BIT18	//1b/1b/x/x R_MCUDMA_ALIGN0: Original design1: Fix MCU Instruction DMA data alignment bug
    #define OPTCFGXHCI_R_MCURST_SEL			BIT17	//1b/1b/x/x Reserved
    #define OPTCFGXHCI_R_HC_ENDP_EN			BIT16	//1b/1b/x/x R_HC_ENDP_EN
    #define OPTCFGXHCI_MCU_DMA_ADDR_PATCH			0xF000	//0/0/x/x Used as MCU_DMA_ADDR_PATCH [39:36]When scratchpad buffer address is over 64G, use these bits as MCU DMA R/W Address Bit [39:36]
    #define OPTCFGXHCI_RESERVED_Z85			(BIT10 + BIT11)	//0/R/x/x Reserved
    #define OPTCFGXHCI_AP_UFPU2REJ			BIT9	//0/0/x/x Enable of Reject to U2 of SS UFP Port
    #define OPTCFGXHCI_AP_UFPU1REJ			BIT8	//0/0/x/x Enable of Reject to U1 of SS UFP Port
    #define OPTCFGXHCI_R_TMORSP_RLSEN			BIT7	//0/0/x/x R_TMORSP_RLSEN0: Release OUT buffer when response timeout1: Fake release OUT buffer when response timeout
    #define OPTCFGXHCI_R_GATE_TDREQ_IN			BIT6	//0/0/x/x R_GATE_TDREQ_IN0: Enable, gating TDIN request to PKTIN1: Disable
    #define OPTCFGXHCI_R_GATE_TDREQ_OUT			BIT5	//0/0/x/x R_GATE_TDREQ_OUT0: Enable, gating TDOUT request to PKTOUT1: Disable
    #define OPTCFGXHCI_R_ISORXMDATA_SC_FIX			BIT4	//0/0/x/x R_ISORXMDATA_SC_FIX0: Disable 1: Enable, if fs ISO in transaction receive MDATA and this CS cause the last TRB done, SP_SC will toggle.
    #define OPTCFGXHCI_R_USELESSDPP_LSTPOP_GATE			BIT3	//0/0/x/x R_USELESSDPP_LSTPOP_GATE
    #define OPTCFGXHCI_R_FORCE_ISO			BIT2	//0/0/x/x Reserved
    #define OPTCFGXHCI_RESERVED_Z86			BIT1	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_RETRB_DONE_FIX			BIT0	//0/0/x/x R_RETRB_DONE_FIX
#define OPTCFGXHCI_XHCIOPTION_RXF8		0xF8	//xHCI Option RXF8
    #define OPTCFGXHCI_RESERVED_Z87			0xFFFFFE00	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_D0_PME_MASK			BIT8	//0/0/x/x R_D0_PME_MASK
    #define OPTCFGXHCI_REG_SOF_DISCONN_MUX			0xF0	//0/0/x/x Select of SOF_DISCONN_SEL 
    #define OPTCFGXHCI_R_PDRST_SYN_SEL			BIT3	//0/0/x/x Select of RESET_PD of HSTTX2 PWR_CTL
    #define OPTCFGXHCI_R_USB2_GORSM_SEL			BIT2	//0/0/x/x R_USB2_GORSM_SEL
    #define OPTCFGXHCI_R_HCRST_CCS_BLK			BIT1	//1b/1b/x/x R_HCRST_CCS_BLK
    #define OPTCFGXHCI_R_HCRST_WRST_SEL			BIT0	//1b/1b/x/x R_HCRST_WRST_SEL
#define OPTCFGXHCI_XHCIOPTION_RXFC		0xFC	//xHCI Option RXFC
    #define OPTCFGXHCI_RESERVED_Z88			BIT15	//0/R/x/x Reserved
    #define OPTCFGXHCI_MSI_TIMEOUT_VALUE			0x7F00	//0/0/x/x MSI Timeout Value
    #define OPTCFGXHCI_RESERVED_Z89			0xFE	//0/0/x/x Reserved
    #define OPTCFGXHCI_MSI_TIMEOUT_EN			BIT0	//0/0/x/x MSI Timeout Enable
#define OPTCFGXHCI_XHCIOPTION_RX100		0x100	//xHCI Option RX100
    #define OPTCFGXHCI_RESERVED_Z90			0xFF000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_HOSTTPFTIME			0xFFFFFF	//1CFDE0h/1CFDE0h/x/x The Host TPF Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX104		0x104	//xHCI Option RX104
    #define OPTCFGXHCI_ISO_BURST_EN			BIT7	//0/0/x/x ISO_BURST_EN
    #define OPTCFGXHCI_SSP_MULTIN_EN			BIT6	//0/0/0/0 SuperSpeedPlus Simultaneous IN Transactions Enable
    #define OPTCFGXHCI_SSP_PIPEISOIN_EN			BIT5	//0/0/0/0 SuperSpeedPlus Simultaneous IN Transactions Enable
    #define OPTCFGXHCI_WPA_EN_OUT			BIT4	//0/0/0/0 Will Ping Again Filed Setting for ISO OUT
    #define OPTCFGXHCI_SSI_EN_OUT			BIT3	//0/0/0/0 Support Smart Isochronous Filed Setting for ISO OUT
    #define OPTCFGXHCI_WPA_EN_IN			BIT2	//0/0/0/0 Will Ping Again Filed Setting for ISO IN
    #define OPTCFGXHCI_SSI_EN_IN			BIT1	//0/0/0/0 Support Smart Isochronous Filed Setting for ISO IN
    #define OPTCFGXHCI_SSP_PTM_EN			BIT0	//0/0/0/0 SuperSpeedPlus Precision Time Measurement Enable
#define OPTCFGXHCI_XHCIOPTION_RX105		0x105	//xHCI Option RX105
    #define OPTCFGXHCI_OBFF_OUTNOEPTCNT			0xF0	//0/0/0/0 Threshold Register
    #define OPTCFGXHCI_OBFF_INEPTCNT			0xF	//0/0/0/0 Threshold Register
#define OPTCFGXHCI_XHCIOPTION_RX106		0x106	//xHCI Option RX106
    #define OPTCFGXHCI_BLKEP_HSNAKSTP_EN			BIT7	//0/0/x/x BLKEP_HSNAKSTP_EN
    #define OPTCFGXHCI_BLKEP_HSNAKCNT			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x BLKEP_HSNAKCNT
    #define OPTCFGXHCI_DBRING_HW_EN			BIT3	//0/0/x/x Enable DB Ring HW Path (PCIS-->xxBI to Trigger TRB Fetch) for Good Performance
    #define OPTCFGXHCI_ISOCFC_EN			BIT2	//0/0/x/x (xHCI Errata 130424) Enable xHCI Isoch CFC Function
    #define OPTCFGXHCI_BYPASS_D3HOT2D0RST			BIT1	//1b/1b/x/x Bypass D3Hot to D0 Reset
    #define OPTCFGXHCI_SLOTID_DCI_CHK			BIT0	//1b/1b/x/x SLOT ID/DCI Check Enable
#define OPTCFGXHCI_XHCIOPTION_RX107		0x107	//xHCI Option RX107
    #define OPTCFGXHCI_RESERVED_Z91			0xF8	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCU_EPXC_SEL			BIT2	//1b/x/x/x EPXC Access Path Select
    #define OPTCFGXHCI_FW_USB_IDLE			BIT1	//0/x/x/x USB Host Controller is Idle, Set by FW
    #define OPTCFGXHCI_MCU_ACTIVE			BIT0	//0/x/x/x MCU Active
#define OPTCFGXHCI_XHCIOPTION_RX108		0x108	//xHCI Option RX108
    #define OPTCFGXHCI_UPREQADDR_HI			0xFFFF	//0/x/x/x Upstream R/W Request Cycle High Address ([63:48])
#define OPTCFGXHCI_XHCIOPTION_RX10A		0x10A	//xHCI Option RX10A
    #define OPTCFGXHCI_RESERVED_Z92			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_OBFF_EN			BIT6	//0/0/x/x OBFF Enable
    #define OPTCFGXHCI_DMAR_RTYEN			BIT5	//0/0/x/x DMAR_RTYEN
    #define OPTCFGXHCI_RETRY_HSE_EN			BIT4	//0/0/x/x RETRY_HSE_EN
    #define OPTCFGXHCI_LSTSPEVENT_EN			BIT3	//0/0/x/x LSTSPEVENT_EN
    #define OPTCFGXHCI_R_LOADNUMP_EN			BIT2	//1b/1b/x/x R_LOADNUMP_EN
    #define OPTCFGXHCI_ISOMISSSERVICE_TRPTR_EN			BIT1	//0/0/x/x ISOMISSSERVICE_TRPTR_EN
    #define OPTCFGXHCI_ISOBABBLE_EVENT_SEL			BIT0	//0/0/0/0 (xHCI Errate 131220) Isoch Endpoint Babble Detect Event Select
#define OPTCFGXHCI_XHCIOPTION_RX10B		0x10B	//xHCI Option RX10B
    #define OPTCFGXHCI_RESERVED_Z93			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_MCU_LTSSTBEN_SS2			BIT1	//0/0/x/x MCU_LTSSTBEN_SS2
    #define OPTCFGXHCI_MCU_LTSSTBEN_SS1			BIT0	//0/0/0/0 MCU_LTSSTBEN_SS1
#define OPTCFGXHCI_XHCIOPTION_RX10C		0x10C	//xHCI Option RX10C
    #define OPTCFGXHCI_LDM_SUBTYPE			0xF000	//7h/7h/x/x LDM_SUBTYPE
    #define OPTCFGXHCI_RESERVED_Z94			(BIT10 + BIT11)	//0/R/x/x Reserved
    #define OPTCFGXHCI_ISOCFC_FMWNDW			0x3FF	//14h/14h/0/0 ISOCFC_FMWNDW
#define OPTCFGXHCI_XHCIOPTION_RX10E		0x10E	//xHCI Option RX10E
    #define OPTCFGXHCI_R_TMOUTCNT_NONU0EN			BIT7	//1b/1b/x/x R_TMOUTCNT_NONU0EN
    #define OPTCFGXHCI_R_RXDPPDKERR_EN			BIT6	//1b/1b/x/x R_RXDPPDKERR_EN
    #define OPTCFGXHCI_R_DPPGATE_EN			BIT5	//0/0/x/x R_DPPGATE_EN
    #define OPTCFGXHCI_R_FAKERLS_FIX			BIT4	//1b/1b/x/x R_FAKERLS_FIX
    #define OPTCFGXHCI_R_NUMP0_RTY_FIX			BIT3	//1b/1b/x/x R_NUMP0_RTY_FIX
    #define OPTCFGXHCI_R_RLSBUF_FIX			BIT2	//1b/1b/x/x R_RLSBUF_FIX
    #define OPTCFGXHCI_R_NONEU0PASSASYN_OUT			BIT1	//1b/1b/x/x R_NONEU0PASSASYN_OUT
    #define OPTCFGXHCI_R_NONEU0PASSASYN_IN			BIT0	//1b/1b/x/x R_NONEU0PASSASYN_IN
#define OPTCFGXHCI_XHCIOPTION_RX10F		0x10F	//xHCI Option RX10F
    #define OPTCFGXHCI_RESERVED_Z95			0xF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_NRDYEOF_FIX			BIT3	//1b/1b/x/x R_NRDYEOF_FIX
    #define OPTCFGXHCI_TAG_REMAP_EN			BIT2	//1b/1b/x/x DMA Read TAG Remap Enable
    #define OPTCFGXHCI_PKTIN_BUFCNT_FIX			BIT1	//1b/1b/x/x PKTIN_BUFCNT_FIX
    #define OPTCFGXHCI_R_ISOLPFSHT			BIT0	//1b/1b/x/x R_ISOLPFSHT
#define OPTCFGXHCI_XHCIOPTION_RX110		0x110	//xHCI Option RX110
    #define OPTCFGXHCI_RESERVED_Z96			0xFF000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXHS_STOPCLK_TMOUT_PARM			0xFF0000	//Ch/x/x/x Stop Clock Timeout Parameter
    #define OPTCFGXHCI_PXHS_ENISO_TMOUT_PARM			0xFF00	//Ch/x/x/x Enable ISO Cell Timeout Parameter
    #define OPTCFGXHCI_PXHS_ASSERTRST_TMOUT_PARM			0xFF	//Ch/x/x/x Assert Reset Signal Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX114		0x114	//xHCI Option RX114
    #define OPTCFGXHCI_PXHS_ASSERTPD_TMOUT_PARM			0xFFFF0000	//3E8h/x/x/x Assert Power Down and Wait Power Down Finish Timeout Parameter
    #define OPTCFGXHCI_PXHS_DEASSERTPD_TMOUT_PARM			0xFFFF	//3E8h/x/x/x De-Assert Power Down and Wait Power Up Finish Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX118		0x118	//xHCI Option RX118
    #define OPTCFGXHCI_RESERVED_Z97			0xFF000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXHS_STARTCLK_TMOUT_PARM			0xFF0000	//Ch/x/x/x Start Clock Timeout Parameter
    #define OPTCFGXHCI_PXHS_DISISO_TMOUT_PARM			0xFF00	//Ch/x/x/x Disable ISO Cell Timeout Parameter
    #define OPTCFGXHCI_PXHS_DEASSERTRST_TMOUT_PARM			0xFF	//Ch/x/x/x De-Assert Reset Signal Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX11C		0x11C	//xHCI Option RX11C
    #define OPTCFGXHCI_RESERVED_Z98			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXHS_PS_EN			BIT0	//0/x/x/x xHCI Power Switch Enable
#define OPTCFGXHCI_XHCIOPTION_RX11D		0x11D	//xHCI Option RX11D
    #define OPTCFGXHCI_RESERVED_Z99			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXHS_FWREQ2PD			BIT4	//0/x/x/x FW Request to Power Down
    #define OPTCFGXHCI_RESERVED_Z100			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXHS_FWREQ2PU			BIT0	//0/x/x/x FW Request to Power Up
#define OPTCFGXHCI_XHCIOPTION_RX11E		0x11E	//xHCI Option RX11E
    #define OPTCFGXHCI_RESERVED_Z101			0xF000	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXHS_CURST			0xFFF	//0h/x/x/x xHCI Power G0iating Controller State Machine
#define OPTCFGXHCI_XHCIOPTION_RX120		0x120	//xHCI Option RX120
    #define OPTCFGXHCI_RESERVED_Z102			0xFF000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXSS_STOPCLK_TMOUT_PARM			0xFF0000	//Ch/x/x/x Stop Clock Timeout Parameter
    #define OPTCFGXHCI_PXSS_ENISO_TMOUT_PARM			0xFF00	//Ch/x/x/x Enable ISO Cell Timeout Parameter
    #define OPTCFGXHCI_PXSS_ASSERTRST_TMOUT_PARM			0xFF	//Ch/x/x/x Assert Reset Signal Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX124		0x124	//xHCI Option RX124
    #define OPTCFGXHCI_PXSS_ASSERTPD_TMOUT_PARM			0xFFFF0000	//3E8h/x/x/x Assert Power Down and Wait Power Down Finish Timeout Parameter
    #define OPTCFGXHCI_PXSS_DEASSERTPD_TMOUT_PARM			0xFFFF	//3E8h/x/x/x De-Assert Power Down and Wait Power Up Finish Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX128		0x128	//xHCI Option RX128
    #define OPTCFGXHCI_RESERVED_Z103			0xFF000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXSS_STARTCLK_TMOUT_PARM			0xFF0000	//Ch/x/x/x Start Clock Timeout Parameter
    #define OPTCFGXHCI_PXSS_DISISO_TMOUT_PARM			0xFF00	//Ch/x/x/x Disable ISO Cell Timeout Parameter
    #define OPTCFGXHCI_PXSS_DEASSERTRST_TMOUT_PARM			0xFF	//Ch/x/x/x De-Assert Reset Signal Timeout Parameter
#define OPTCFGXHCI_XHCIOPTION_RX12C		0x12C	//xHCI Option RX12C
    #define OPTCFGXHCI_RESERVED_Z104			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXSS_PS_EN			BIT0	//0/x/x/x xHCI Power Switch Enable
#define OPTCFGXHCI_XHCIOPTION_RX12D		0x12D	//xHCI Option RX12D
    #define OPTCFGXHCI_RESERVED_Z105			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXSS_FWREQ2PD			BIT4	//0/x/x/x FW Request to Power Down
    #define OPTCFGXHCI_RESERVED_Z106			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXSS_FWREQ2PU			BIT0	//0/x/x/x FW Request to Power Up
#define OPTCFGXHCI_XHCIOPTION_RX12E		0x12E	//xHCI Option RX12E
    #define OPTCFGXHCI_RESERVED_Z107			0xF000	//0/R/x/x Reserved
    #define OPTCFGXHCI_PXSS_CURST			0xFFF	//0h/x/x/x xHCI Power Gating Controller State Machine
#define OPTCFGXHCI_XHCIOPTION_RX130		0x130	//xHCI Option RX130
    #define OPTCFGXHCI_RESERVED_Z108			0xFFFFF000	//0/R/x/x Reserved
    #define OPTCFGXHCI_S1XRPRI			(BIT10 + BIT11)	//0/0/x/x SSBI Schedule Upstream Read Priority
    #define OPTCFGXHCI_S1XWPRI			(BIT8 + BIT9)	//0/0/x/x SSBI Schedule Upstream Write Priority
    #define OPTCFGXHCI_B2XRPRI			(BIT6 + BIT7)	//0/0/x/x Buffer Management Upstream Read Priority
    #define OPTCFGXHCI_B2XWPRI			(BIT4 + BIT5)	//0/0/x/x Buffer Management Upstream Write Priority
    #define OPTCFGXHCI_B3XRPRI			(BIT2 + BIT3)	//0/0/x/x Buffer Management Upstream Read Priority
    #define OPTCFGXHCI_B3XWPRI			(BIT0 + BIT1)	//0/0/x/x Buffer Management Upstream Write Priority
#define OPTCFGXHCI_XHCIOPTION_RX134		0x134	//xHCI Option Rx134
    #define OPTCFGXHCI_RESERVED_Z109			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_OCSEL2			(BIT4 + BIT5 + BIT6)	//0/0/x/x SS/HS Port 2 OC Input Driving Pad Selection
    #define OPTCFGXHCI_RESERVED_Z110			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_OCSEL1			(BIT0 + BIT1 + BIT2)	//0/0/x/x SS/HS Port 1 OC Input Driving Pad Selection
#define OPTCFGXHCI_XHCIOPTION_RX137		0x137	//xHCI Option Rx137
    #define OPTCFGXHCI_RESERVED_Z111			0xF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_U31PHY_EN			BIT3	//0b/0b/x/x Enable USB31PHY
    #define OPTCFGXHCI_EN_VPWRGD_PDAPLL			BIT2	//0/0/x/x Enable to Use VPWRGD to Control PDAPLL for USB2.0 PHY
    #define OPTCFGXHCI_CMBPHY_CFGDONE_BYPASS			BIT1	//0/0/x/x Bypass CMBPHY_CFGDONE in Reset Path
    #define OPTCFGXHCI_USB3EPHY_REFCLKOK_BYPASS			BIT0	//0/0/x/x Bypass USB3EPHY Referrence Clock PLLOK in Reset Path
#define OPTCFGXHCI_XHCIOPTION_RX138		0x138	//xHCI Option Rx138
    #define OPTCFGXHCI_RESERVED_Z112			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_DCMPS_XH			(BIT4 + BIT5 + BIT6)	//0/0/x/x Max Payload Size of xHCIWhen DMARS_XHCIEN=1, DMA Write Max Request Size Will Decode by this Reg
    #define OPTCFGXHCI_DCMRRS_XH			(BIT1 + BIT2 + BIT3)	//0/0/x/x Max Read Request Size of xHCIWhen DMARS_XHCIEN=1, DMA read max request size will decode by this reg
    #define OPTCFGXHCI_DMARS_XHCIEN			BIT0	//0/0/x/x DMA Request Size by xHCI Enable
#define OPTCFGXHCI_XHCIOPTION_RX13A		0x13A	//xHCI Option Rx13A
    #define OPTCFGXHCI_RESERVED_Z113			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_RXHZ_DIS_SS2			BIT1	//1b/1b/x/x R_RXHZ_DIS_SS2
    #define OPTCFGXHCI_R_RXHZ_DIS_SS1			BIT0	//1b/1b/x/x R_RXHZ_DIS_SS1
#define OPTCFGXHCI_XHCIOPTION_RX13B		0x13B	//xHCI Option Rx13B
    #define OPTCFGXHCI_RESERVED_Z114			BIT7	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_P2CRTABT_SETEN			BIT6	//0/0/x/x R_P2CRTABT_SETEN
    #define OPTCFGXHCI_NXTSPEVENT_EN			BIT5	//0/0/x/x Generate "Short Packet" CC for Subsequent Transfer Event with IOC=1 of the Same TD
    #define OPTCFGXHCI_TAG_REMAP_XHCIEN			BIT4	//0/0/x/x DMARTAG Remap Enable by XHCI
    #define OPTCFGXHCI_R_P2CRABT_INTEN			BIT3	//0/0/x/x R_P2CRABT_INTEN
    #define OPTCFGXHCI_R_FAKERLS_NEW			BIT2	//1b/1b/x/x R_FAKERLS_NEW
    #define OPTCFGXHCI_R_PING_ACK_SEL			BIT1	//0/0/x/x R_PING_ACK_SEL
    #define OPTCFGXHCI_R_TTCHK_MSK			BIT0	//0/0/x/x R_TTCHK_MSK
#define OPTCFGXHCI_XHCIOPTION_RX13C		0x13C	//xHCI Option Rx13C
    #define OPTCFGXHCI_R_DBGWCLK_SEL			0xF0	//0/0/x/x R_DBGWCLK_SEL
    #define OPTCFGXHCI_RESERVED_Z115			BIT3	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_D3HOT_MMIO_RD			BIT2	//0/0/x/x R_D3HOT_MMIO_RD
    #define OPTCFGXHCI_R_TSTPKT_HW			BIT1	//1b/1b/x/x R_TSTPKT_HW
    #define OPTCFGXHCI_FW_ISOINHC4_EN			BIT0	//0/0/x/x FW_ISOINHC4_EN
#define OPTCFGXHCI_XHCIOPTION_RX13D		0x13D	//xHCI Option Rx13D
    #define OPTCFGXHCI_RESERVED_Z116			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_RPTLPBK_SS1			BIT5	//0/0/x/x R_RPTLPBK_SS1,
    #define OPTCFGXHCI_R_RPTLPBK_SS2			BIT4	//0/0/x/x R_RPTLPBK_SS2
    #define OPTCFGXHCI_R_RPTCOMPLIANCE_SS1			BIT3	//0/0/x/x R_RPTCOMPLIANCE_SS1
    #define OPTCFGXHCI_R_RPTCOMPLIANCE_SS2			BIT2	//0/0/x/x R_RPTCOMPLIANCE_SS2
    #define OPTCFGXHCI_R_FORCEPM_SS2			BIT1	//0/0/x/x R_FORCEPM_SS2
    #define OPTCFGXHCI_R_FORCEPM_SS1			BIT0	//0/0/x/x R_FORCEPM_SS1
#define OPTCFGXHCI_XHCIOPTION_RX13E		0x13E	//xHCI Option RX13E
    #define OPTCFGXHCI_RESERVED_Z117			0xF0	//0/R/x/x Reserved
    #define OPTCFGXHCI_USB2P2_LPM_FS_CLK_1M5_DYNCLKEN			BIT3	//0/0/x/1b USB2P2_LPM_FS_CLK_1M5_DYNCLKEN
    #define OPTCFGXHCI_USB2P2_LPM_FS_CLK_12M_DYNCLKEN			BIT2	//0/0/x/1b USB2P2_LPM_FS_CLK_12M_DYNCLKEN
    #define OPTCFGXHCI_USB2P1_LPM_FS_CLK_1M5_DYNCLKEN			BIT1	//0/0/x/1b USB2P1_LPM_FS_CLK_1M5_DYNCLKEN
    #define OPTCFGXHCI_USB2P1_LPM_FS_CLK_12M_DYNCLKEN			BIT0	//0/0/x/1b USB2P1_LPM_FS_CLK_12M_DYNCLKEN
#define OPTCFGXHCI_XHCIOPTION_RX140		0x140	//xHCI Option Rx140
    #define OPTCFGXHCI_R_DEGLITCH_SEL			(BIT6 + BIT7)	//0/x/x/x R_DEGLITCH_SEL
    #define OPTCFGXHCI_TEST_U31FREQ			BIT5	//0/x/x/x TEST_U31FREQ
    #define OPTCFGXHCI_RESERVED_Z118			(BIT2 + BIT3 + BIT4)	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_DSPORT_WRST_SS2			BIT1	//0/0/x/x R_DSPORT_WRST_SS2
    #define OPTCFGXHCI_R_DSPORT_WRST_SS1			BIT0	//0/0/x/x R_DSPORT_WRST_SS1
#define OPTCFGXHCI_XHCIOPTION_RX141		0x141	//xHCI Option Rx141
    #define OPTCFGXHCI_RESERVED_Z119			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_USB3HC_DBG_SEL_MODE			BIT0	//0/0/x/x R_USB3HC_DBG_SEL_MODE
#define OPTCFGXHCI_XHCIOPTION_RX144		0x144	//xHCI Option Rx144
    #define OPTCFGXHCI_RESERVED_Z120			0xF0000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_USB3HC_DBG_SEL_G1			0xFFF0000	//0/0/x/x R_USB3HC_DBG_SEL_G1
    #define OPTCFGXHCI_RESERVED_Z121			0xF000	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_USB3HC_DBG_SEL_G0			0xFFF	//0/0/x/x R_USB3HC_DBG_SEL_G0
#define OPTCFGXHCI_XHCIOPTION_RX148		0x148	//xHCI Option Rx148
    #define OPTCFGXHCI_RESERVED_Z122			0xF0000000	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_USB3HC_DBG_SEL_G3			0xFFF0000	//0/0/x/x R_USB3HC_DBG_SEL_G3
    #define OPTCFGXHCI_RESERVED_Z123			0xF000	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_USB3HC_DBG_SEL_G2			0xFFF	//0/0/x/x R_USB3HC_DBG_SEL_G2
#define OPTCFGXHCI_XHCIOPTION_RX14C		0x14C	//xHCI Option Rx14C
    #define OPTCFGXHCI_RESERVED_Z124			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGXHCI_SPEVENT_HPEN			BIT5	//0/x/x/x Short Packet Event Hi Priority Enable
    #define OPTCFGXHCI_MCU_RST_SEL			BIT4	//0/x/x/x OpenRisc Reset Selection
    #define OPTCFGXHCI_R_HSISO_SPD_NXT_FIX			BIT3	//0/x/x/x R_HSISO_SPD_NXT_FIX
    #define OPTCFGXHCI_R_HSISO_SPD_CUR_FIX			BIT2	//0/x/x/x R_HSISO_SPD_CUR_FIX
    #define OPTCFGXHCI_R_TXSOF_SEL			BIT1	//0/0/x/x R_TXSOF_SEL
    #define OPTCFGXHCI_R_HS_TXSOF_EN			BIT0	//1b/1b/x/x R_HS_TXSOF_EN
#define OPTCFGXHCI_XHCIOPTION_RX14D		0x14D	//xHCI Option Rx14D
    #define OPTCFGXHCI_RESERVED_Z125			0xFC	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_UPU3FLAG_SS2			BIT1	//0/x/x/x Enable UFP Control DFP U3-TXP2
    #define OPTCFGXHCI_R_UPU3FLAG_SS1			BIT0	//0/x/x/x Enable UFP Control DFP U3-TXP1
#define OPTCFGXHCI_XHCIOPTION_RX14E		0x14E	//xHCI Option Rx14E
    #define OPTCFGXHCI_RESERVED_Z126			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_DSCDC_PMSTATE_OPTION			BIT0	//1b/1b/x/x DSCDC_PMSTATE_OPTION 
#define OPTCFGXHCI_XHCIOPTION_RX150		0x150	//xHCI Option Rx150
    #define OPTCFGXHCI_PATCHBITS0			0xFFFFFFFF	//FFFF0000h/FFFF0000h/x/x xHCI Patch Optional Bits 0
#define OPTCFGXHCI_XHCIOPTION_RX154		0x154	//xHCI Option Rx154
    #define OPTCFGXHCI_PATCHBITS1			0xFFFFFFFF	//FFFF0000h/FFFF0000h/x/x xHCI Patch Optional Bits 1
#define OPTCFGXHCI_XHCIOPTION_RX158		0x158	//xHCI Option Rx158
    #define OPTCFGXHCI_PATCHBITS2			0xFFFFFFFF	//FFFF0000h/FFFF0000h/x/x xHCI Patch Optional Bits 2 (Suspend Power Domain)
#define OPTCFGXHCI_XHCIOPTION_RX15C		0x15C	//xHCI Option RX15C
    #define OPTCFGXHCI_PATCHBITS3			0xFFFFFFFF	//FFFF0000h/x/x/x xHCI Patch Optional Bits 3 (Suspend Power Domain)
#define OPTCFGXHCI_XHCIOPTION_RX160		0x160	//xHCI Option Rx160
    #define OPTCFGXHCI_RESERVED_Z127			0xFE	//0/R/x/x Reserved
    #define OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN			BIT0	//0/0/x/x R_DMAWMUX_FLUSHEND_EN
#define OPTCFGXHCI_XHCIOPTION_RX161		0x161	//xHCI Option Rx161
    #define OPTCFGXHCI_DMAWMUX_FLUSHEND_OPTION			0xFFFF	//0/0/x/x DMAWMUX_FLUSHEND_OPTION
//OPTCFG_HSBI
#define OPTCFGHSBI_USB2_OPTION_RX00		0x00	//USB2 Option RX00
    #define OPTCFGHSBI_R_NEWHSBIRST			BIT7	//0/0/x/x New HSBI Reset
    #define OPTCFGHSBI_HSBI_PATCH0			BIT6	//0/0/x/x HSBI PATCH 0
    #define OPTCFGHSBI_HSBI_PATCH1			BIT5	//0/0/x/x HSBI PATCH 1
    #define OPTCFGHSBI_VALIDCLKEN			BIT4	//0/0/x/x HSTRANS Use VALID as Clock Enable
    #define OPTCFGHSBI_HSAUXCLKFREE			BIT3	//0/0/x/x HSAUX Clock Free Running
    #define OPTCFGHSBI_HSBI_DEBUGEN			BIT2	//1b/1b/x/x HS BI Debug Enable
    #define OPTCFGHSBI_HSBI_DYNCLKEN			BIT1	//0/0/x/1b HS BI Dynamic Clock Enable
    #define OPTCFGHSBI_ENHSBI			BIT0	//1b/1b/x/x HS BI Enable
#define OPTCFGHSBI_USB2_OPTION_RX01		0x01	//USB2 Option RX01
    #define OPTCFGHSBI_EN_ISOHANDCHK			BIT7	//0/0/x/x Check RXHAND in ISO Transaction or Not
    #define OPTCFGHSBI_EN_CHKTOGCRC			BIT6	//0/0/x/x Enable Check CRCERR Even TOG Mismatch
    #define OPTCFGHSBI_EN_UTM_RESET			BIT5	//1b/1b/x/x Enable UTM Reset if UTM Hang
    #define OPTCFGHSBI_EN_UTM_SPDUP			BIT4	//0/0/x/x Enable UTM Speedup
    #define OPTCFGHSBI_EN_REF_RVLD			BIT3	//1b/1b/x/x Enable Reference Squelch as Bus Idle
    #define OPTCFGHSBI_DIS_NARROW_SOF			BIT2	//0/0/x/x Options for SOF_DISCONN Speed up
    #define OPTCFGHSBI_DIS_CHKEOPERR			BIT1	//1b/1b/x/x Disable PHY eop='hFE Pattern Check
    #define OPTCFGHSBI_DIS_IMPRV_SQUELCH			BIT0	//1b/1b/x/x PHYOPT TMODE
#define OPTCFGHSBI_USB2_OPTION_RX02		0x02	//USB2 Option RX02
    #define OPTCFGHSBI_DIS_SOF_RUN			BIT7	//0/0/x/x DIS_SOF_RUN
    #define OPTCFGHSBI_TXDELAY_EN			BIT6	//0/0/x/x Insert Delay between Transactions
    #define OPTCFGHSBI_TXTMOUT_EN			BIT5	//0/0/x/x Provide TMOUT to Device if Error Detected
    #define OPTCFGHSBI_DIS_PDRCV			BIT4	//0/0/x/x Disable Power Down Enable
    #define OPTCFGHSBI_BABOPT			BIT3	//0/0/x/x EOF Babble Option
    #define OPTCFGHSBI_TEST_EYE_EN			BIT2	//0/0/x/x TEST_EYE Pattern Enable
    #define OPTCFGHSBI_SOF_DISCONN_CHK			BIT1	//1b/1b/x/x Check Disconnect in SOF EOP Period
    #define OPTCFGHSBI_FORCE_CRCERR			BIT0	//0/0/x/x FORCE_CRCERR
#define OPTCFGHSBI_USB2_OPTION_RX03		0x03	//USB2 Option RX03
    #define OPTCFGHSBI_TMOUT_PARM			0xFF	//FFh/FFh/x/x Parameter for TimeOut
#define OPTCFGHSBI_USB2_OPTION_RX04		0x04	//USB2 Option RX04
    #define OPTCFGHSBI_TXDELAY_PARM			0xFF	//0/0/x/x Insert Delay Parameter
#define OPTCFGHSBI_USB2_OPTION_RX05		0x05	//USB2 Option RX05
    #define OPTCFGHSBI_PORTRST_CNT_PARM			(BIT6 + BIT7)	//0/0/x/x Port Reset Counter Parameter
    #define OPTCFGHSBI_PORTRSM_CNT_PARM			(BIT4 + BIT5)	//0/0/x/x Port Resume Counter Parameter
    #define OPTCFGHSBI_TURN_PARM			0xF	//9h/9h/x/x Turn Around Time Parameter
#define OPTCFGHSBI_USB2_OPTION_RX06		0x06	//USB2 Option RX06
    #define OPTCFGHSBI_RESERVED			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_HSBI_FORCEU0			BIT6	//0/0/x/x Reserved
    #define OPTCFGHSBI_DIS_TERM_ON			BIT5	//0/0/x/x Termination Disable Feature
    #define OPTCFGHSBI_HSENFB_DIS			BIT4	//0/0/x/x HsEnFB_Dis
    #define OPTCFGHSBI_PDPHY_DIS			BIT3	//0/0/x/x Power Down EPHY Disable
    #define OPTCFGHSBI_EN_NEW_PDHSDRV			BIT2	//0/0/x/x EN_NEW_PDHSDRV
    #define OPTCFGHSBI_EN_NEW_PDAPLL			BIT1	//0/0/x/x Enable Power Down APLL as No Device is Connected
    #define OPTCFGHSBI_EN_PDPHY_INPDPLL			BIT0	//0/0/x/x Enable Power Down USBPHY when APLL is Power Down
#define OPTCFGHSBI_USB2_OPTION_RX07		0x07	//USB2 Option RX07
    #define OPTCFGHSBI_RESERVED_Z1			0xF8	//0/R/x/x Reserved
    #define OPTCFGHSBI_AUTOCHK_EN			BIT2	//0/0/x/x UTM Auto Check Enable
    #define OPTCFGHSBI_SYNC_JEND			BIT1	//1b/1b/x/x Used to Detect Sync Pattern with 2J¡¯s End
    #define OPTCFGHSBI_SYNC_FAST			BIT0	//0/0/x/x Sync Fast without rbc_120m Synchronizer
#define OPTCFGHSBI_HSBIOPTION_RX16		0x16	//HSBI Option RX16
    #define OPTCFGHSBI_RESERVED_Z2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_ASYEP1_CNAKSEL			(BIT4 + BIT5)	//0/0/x/x ASYEPCTL Consecutive NAK Count selection
    #define OPTCFGHSBI_ASYEP1_SLOWPSEL			(BIT2 + BIT3)	//0/0/x/x ASYEPCTL Slow Period Selection
    #define OPTCFGHSBI_ASYEP1_AUTOSLOW			BIT1	//0/0/x/x ASYEPCTL Auto Slow 
    #define OPTCFGHSBI_ASYEP1_SLOWEN			BIT0	//0/0/x/x ASYEPCTL Slow Enable
#define OPTCFGHSBI_HSBIOPTION_RX17		0x17	//HSBI Option RX17
    #define OPTCFGHSBI_RESERVED_Z3			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_ASYEP2_CNAKSEL			(BIT4 + BIT5)	//01b/01b/x/x ASYEPCTL Consecutive NAK Count Selection
    #define OPTCFGHSBI_ASYEP2_SLOWPSEL			(BIT2 + BIT3)	//01b/01b/x/x ASYEPCTL Slow Period Selection
    #define OPTCFGHSBI_ASYEP2_AUTOSLOW			BIT1	//1b/1b/x/x ASYEPCTL Auto Slow
    #define OPTCFGHSBI_ASYEP2_SLOWEN			BIT0	//1b/1b/x/x ASYEPCTL Slow Enable
#define OPTCFGHSBI_USB2_OPTION_RX18		0x18	//USB2 Option RX18
    #define OPTCFGHSBI_ASYEP1_HSTURBO			BIT7	//0/0/x/x ASYEPCTL1 HS Turbo Mode Enable
    #define OPTCFGHSBI_ASYEP2_HSTURBO			BIT6	//0/0/x/x ASYEPCTL2 HS Turbo Mode Enable
    #define OPTCFGHSBI_PEREP_HSTURBO			BIT5	//0/0/x/x PEREPCTL HS Turbo Mode Enable
    #define OPTCFGHSBI_HS_SSONLYISTEN			BIT4	//1b/1b/x/x Start Split at First Service Opportunity
    #define OPTCFGHSBI_PRESOFCHKEN			BIT3	//1b/1b/x/x PRESOFCHK Enable
    #define OPTCFGHSBI_R_ENPERINTURBO			BIT2	//1b/1b/x/x Enable PEREP IN Turbo Mode
    #define OPTCFGHSBI_BABBLE_FLUSH_EN			BIT1	//0/0/x/x BABBLE_FLUSH_EN
    #define OPTCFGHSBI_HS_REDUCE			BIT0	//0/0/x/x Frame Timer Reduce Mode
#define OPTCFGHSBI_USB2_OPTION_RX19		0x19	//USB2 Option RX19
    #define OPTCFGHSBI_LOCKTMOSEL			(BIT6 + BIT7)	//0/0/x/x LOCKTMOSEL
    #define OPTCFGHSBI_HALTRSTEN			BIT5	//1b/1b/x/x Reset Halted Endpoint Content
    #define OPTCFGHSBI_ASY_SPSOINTV_EN			BIT4	//0/0/x/x Async Split service opportunity interval enable
    #define OPTCFGHSBI_ASY_SPSOINTV_PARM			(BIT2 + BIT3)	//0/0/x/x Async Split transaction packet interval sel
    #define OPTCFGHSBI_QUICKCPM			BIT1	//1b/1b/x/x QUICKCPM
    #define OPTCFGHSBI_CMDPKTAUTO			BIT0	//0/0/x/x Command Packet Status Stage Auto Mode
#define OPTCFGHSBI_USB2_OPTION_RX1A		0x1A	//USB2 Option RX1A
    #define OPTCFGHSBI_PEREP_PRESOF_SEL			(BIT6 + BIT7)	//01b/01b/x/x PEREP Presof Offset Select
    #define OPTCFGHSBI_ASYEP2_PRESOF_SEL			(BIT4 + BIT5)	//01b/01b/x/x ASYEP2 Presof Offset Select
    #define OPTCFGHSBI_ASYEP1_PRESOF_SEL			(BIT2 + BIT3)	//01b/01b/x/x ASYEP1 Presof Offset Select
    #define OPTCFGHSBI_HSPRESOF_SEL			(BIT0 + BIT1)	//01b/01b/x/x HSPRESOF_SEL
#define OPTCFGHSBI_USB2_OPTION_RX1B		0x1B	//USB2 Option RX1B
    #define OPTCFGHSBI_R_ENFLSINTFIX			BIT7	//1b/1b/x/x Enable FS/LS INT IN Fix
    #define OPTCFGHSBI_R_ENFSISOFIX			BIT6	//0/0/x/x Enable FS ISO Fix
    #define OPTCFGHSBI_ECS_SPEAKER_FIX			BIT5	//1b/1b/x/x Enable ECS Speaker Fix
    #define OPTCFGHSBI_HUAWEI3G_FIX			BIT4	//1b/1b/x/x Enable HUAWEI 3G Fix
    #define OPTCFGHSBI_TV_TUNER_FIX			BIT3	//1b/1b/x/x Enable TV Tuner Fix
    #define OPTCFGHSBI_TX120MDYNDIS			BIT2	//0/0/x/x TX 120M Clock Dynamic Clock Control Enable
    #define OPTCFGHSBI_RX120MDYNDIS			BIT1	//0/0/x/x RX 120M Clock Dynamic Clock Control Enable
    #define OPTCFGHSBI_R_CV_RMUSBHUB			BIT0	//0/0/x/x Remove the Internal USBHUB Connection for CV Test
#define OPTCFGHSBI_USB2_OPTION_RX1C		0x1C	//USB2 Option RX1C
    #define OPTCFGHSBI_R_CRSM_STOPCNTPARM_SUS			0xFF	//9Ch/9Ch/x/x CResume Stop Parameter
#define OPTCFGHSBI_USB2_OPTION_RX1D		0x1D	//USB2 Option RX1D
    #define OPTCFGHSBI_HSBI_OPTW0			0xF0	//0/0/x/x HSBI OPTION Word 0
    #define OPTCFGHSBI_R_XHCVER10_SUS			BIT3	//1b/1b/x/x An Indicator Operating on xHCI 1.0 Mode
    #define OPTCFGHSBI_R_RMUSBHUB_SUS			BIT2	//0/0/x/x Remove Internal Integrated HUB
    #define OPTCFGHSBI_R_RSMJKEN_SUS			BIT1	//1b/1b/x/x Enable the Function of Reflecting Resume_JtoK Signal to Root Port
    #define OPTCFGHSBI_R_DISCRSMSTOP_SUS			BIT0	//0/0/x/x Disable the Stopping Function of CResume Counter in Resume State
#define OPTCFGHSBI_USB2_OPTION_RX1E		0x1E	//USB2 Option RX1E
    #define OPTCFGHSBI_HSBI_OPT0_SUS			0xFF	//0/0/x/x HSBI OPTION SUS 0
#define OPTCFGHSBI_USB2_OPTION_RX1F		0x1F	//USB2 Option RX1F
    #define OPTCFGHSBI_HSBI_OPT1_SUS			0xFF	//FFh/FFh/x/x HSBI OPTION SUS 1
#define OPTCFGHSBI_USB2_OPTION_RX20		0x20	//USB2 Option RX20
    #define OPTCFGHSBI_RESERVED_Z4			0xF8	//0/R/x/x Reserved
    #define OPTCFGHSBI_R_HS_CLKEN_EXT			BIT2	//0/0/x/x R_HS_CLKEN_EXT
    #define OPTCFGHSBI_HSBFOUTRLSALL_EN			BIT1	//0/0/x/x HSTRANS Enable to Release All OUT Buffer when OUT TRANS Idle
    #define OPTCFGHSBI_HSBFINRLSALL_EN			BIT0	//0/0/x/x HSTRANS Enable to Release All IN Buffer when IN TRANS Idle
#define OPTCFGHSBI_USB2_OPTION_RX21		0x21	//USB2 Option RX21
    #define OPTCFGHSBI_RESERVED_Z5			0xFE	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_INU2_PASS_ASYN_HS			BIT0	//1b/1b/x/x REG_INU2_PASS_ASYN_HS
#define OPTCFGHSBI_USB2_OPTION_RX24		0x24	//USB2 Option RX24
    #define OPTCFGHSBI_RESERVED_Z6			0xFE	//0/R/x/x Reserved
    #define OPTCFGHSBI_R_L1_EXT_RCVT_S			BIT0	//0b/0b/x/x R_L1_EXT_RCVT_S 
#define OPTCFGHSBI_USB2_OPTION_RX25		0x25	//USB2 Option RX25
    #define OPTCFGHSBI_RESERVED_Z7			0xF000	//0/R/x/x Reserved
    #define OPTCFGHSBI_R_L1_DEV_RCV_TM			0xFFF	//AFFh/AFFh/x/x R_L1_DEV_RCV_TM
#define OPTCFGHSBI_USB2_OPTION_RX27		0x27	//USB2 Option RX27
    #define OPTCFGHSBI_RESERVED_Z8			0xFE	//0/R/x/x Reserved
    #define OPTCFGHSBI_R_L1_EXT_DYNVLCLK_EN			BIT0	//1b/1b/x/x R_L1_EXT_DYNVLCLK_EN
#define OPTCFGHSBI_USB2_OPTION_RX28		0x28	//USB2 Option RX28
    #define OPTCFGHSBI_RESERVED_Z9			0xFE	//0/R/x/x Reserved
    #define OPTCFGHSBI_R_TEST_PKT_DLY			BIT0	//0b/0b/x/x R_TEST_PKT_DLY
#define OPTCFGHSBI_USB2_OPTION_RX100		0x100	//USB2 Option RX100
    #define OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_A			0xF0	//1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_A			0xF	//6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_A
#define OPTCFGHSBI_USB2_OPTION_RX101		0x101	//USB2 Option RX101
    #define OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_A			0xFF	//5Ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_A
#define OPTCFGHSBI_USB2_OPTION_RX102		0x102	//USB2 Option RX102
    #define OPTCFGHSBI_REG_RXCPLOPT_A			BIT7	//1b/1b/x/x REG_RXCPLOPT_A
    #define OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_A			BIT6	//1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_A
    #define OPTCFGHSBI_REG_L1_EN_A			BIT5	//0/0/x/x REG_L1_EN_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_A			BIT4	//0/0/x/x REG_UP_SIE_HC_SYNC_JEND_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_A			BIT3	//0/0/x/x REG_UP_SIE_HC_SYNC_FAST_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_A			BIT2	//0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_A			BIT1	//0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_A			BIT0	//1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_A
#define OPTCFGHSBI_USB2_OPTION_RX103		0x103	//USB2 Option RX103
    #define OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_A			0xFF	//24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_A
#define OPTCFGHSBI_USB2_OPTION_RX104		0x104	//USB2 Option RX104
    #define OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_A			0xF0	//6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_A
    #define OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_A			0xF	//1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_A
#define OPTCFGHSBI_USB2_OPTION_RX105		0x105	//USB2 Option RX105
    #define OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_A			BIT7	//1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_A
    #define OPTCFGHSBI_REG_NPTT_RCTB_DIR_A			BIT6	//0/0/x/x REG_NPTT_RCTB_DIR_A
    #define OPTCFGHSBI_REG_NPTT_RCHKHSH_A			BIT5	//1b/1b/x/x REG_NPTT_RCHKHSH_A
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_EN_A			BIT4	//1b/1b/x/x REG_NPTT_RRACKTM_EN_A
    #define OPTCFGHSBI_REG_NPTT_RCONTFST_A			BIT3	//1b/1b/x/x REG_NPTT_RCONTFST_A
    #define OPTCFGHSBI_REG_NPTT_RCHKDATAPID_A			BIT2	//0/0/x/x REG_NPTT_RCHKDATAPID_A
    #define OPTCFGHSBI_REG_NPTT_RMATCH_ALL_A			BIT1	//1b/1b/x/x REG_NPTT_RMATCH_ALL_A
    #define OPTCFGHSBI_REG_EOF_RST_TX_A			BIT0	//0/0/x/x REG_EOF_RST_TX_A
#define OPTCFGHSBI_USB2_OPTION_RX106		0x106	//USB2 Option RX106
    #define OPTCFGHSBI_RESERVED_Z10			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_A			BIT4	//1b/1b/x/x Reserved
    #define OPTCFGHSBI_REG_PTT_SEARCH_LEN_A			(BIT2 + BIT3)	//0/0/x/x REG_PTT_SEARCH_LEN_A
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_A			BIT1	//1b/1b/x/x REG_NPTT_RRACKTM_FWEN_A
    #define OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_A			BIT0	//1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_A
#define OPTCFGHSBI_USB2_OPTION_RX107		0x107	//USB2 Option RX107
    #define OPTCFGHSBI_RESERVED_Z11			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_A			0x7F	//1Dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_A
#define OPTCFGHSBI_USB2_OPTION_RX108		0x108	//USB2 Option RX108
    #define OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_A			0xFFFF0000	//DACh/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_A
    #define OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_A			0xFFFF	//1B58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_A
#define OPTCFGHSBI_USB2_OPTION_RX10C		0x10C	//USB2 Option RX10C
    #define OPTCFGHSBI_RESERVED_Z12			0xF0000000	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_FS_A			0xFFF0000	//2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_A
    #define OPTCFGHSBI_RESERVED_Z13			0xF000	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_LS_A			0xFFF	//F50h/f50h/x/x REG_NPTT_RRACKTM_LS_A
#define OPTCFGHSBI_USB2_OPTION_RX110		0x110	//USB2 Option RX110
    #define OPTCFGHSBI_RESERVED_Z14			0xF8000000	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_PTT_FULL_DELAY_A			0x7FF0000	//90h/90h/x/x REG_PTT_FULL_DELAY_A
    #define OPTCFGHSBI_RESERVED_Z15			0xF800	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_PTT_LOW_DELAY_A			0x7FF	//44Ch/44ch/x/x REG_PTT_LOW_DELAY_A
#define OPTCFGHSBI_USB2_OPTION_RX114		0x114	//USB2 Option RX114
    #define OPTCFGHSBI_RESERVED_Z16			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_EOF2_A			0x1FFF0000	//7h/7h/x/x REG_FR_HIGH_EOF2_A
    #define OPTCFGHSBI_RESERVED_Z17			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_EOF1_A			0x1FFF	//45h/45h/x/x REG_FR_HIGH_EOF1_A
#define OPTCFGHSBI_USB2_OPTION_RX118		0x118	//USB2 Option RX118
    #define OPTCFGHSBI_REG_FR_FULL_EOF2_A			0xFFFF0000	//31h/31h/x/x REG_FR_FULL_EOF2_A
    #define OPTCFGHSBI_REG_FR_FULL_EOF1_A			0xFFFF	//9Fh/9fh/x/x REG_FR_FULL_EOF1_A
#define OPTCFGHSBI_USB2_OPTION_RX11C		0x11C	//USB2 Option RX11C
    #define OPTCFGHSBI_RESERVED_Z18			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_INIT_A			0x1FFF0000	//1D4Ch/1d4ch/x/x REG_FR_HIGH_INIT_A
    #define OPTCFGHSBI_REG_FR_FULL_INIT_A			0xFFFF	//EA60h/ea60h/x/x REG_FR_FULL_INIT_A
#define OPTCFGHSBI_USB2_OPTION_RX120		0x120	//USB2 Option RX120
    #define OPTCFGHSBI_RESERVED_Z19			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_OVFL_A			0x1FFF	//1D57h/1d57h/x/x REG_FR_HIGH_OVFL_A
#define OPTCFGHSBI_USB2_OPTION_RX122		0x122	//USB2 Option RX122
    #define OPTCFGHSBI_RESERVED_Z20			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_EOP_FLAG_A			BIT6	//1b/1b/x/x Reserved 
    #define OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_A			BIT5	//1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_A
    #define OPTCFGHSBI_REG_PAMP_TX_EN_A			BIT4	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_SUSPEND_PROPAGATION_A			BIT3	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_DNCOLL_EOP_SEL_A			BIT2	//0/0/x/x REG_DNCOLL_EOP_SEL_A
    #define OPTCFGHSBI_REG_TT_COLL_DET_DIS_A			BIT1	//1b/1b/x/x REG_TT_COLL_DET_DIS_A
    #define OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_A			BIT0	//0/0/x/x REG_DN_LPM_MANUAL_EOR_A
#define OPTCFGHSBI_USB2_OPTION_RX123		0x123	//USB2 Option RX123
    #define OPTCFGHSBI_REG_DN_EOI_EOR1_A			0xFF	//64h/64h/x/x REG_DN_EOI_EOR1_A
#define OPTCFGHSBI_USB2_OPTION_RX124		0x124	//USB2 Option RX124
    #define OPTCFGHSBI_REG_DN_SUSDISABLE_A			BIT7	//1b/1b/x/x REG_DN_SUSDISABLE_A
    #define OPTCFGHSBI_REG_EOF1_EOF2_A			BIT6	//1b/1b/x/x REG_EOF1_EOF2_A
    #define OPTCFGHSBI_FS_LPBK_A			BIT5	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_DN_PORT_ERR_CHK_A			BIT4	//0/0/x/x REG_DN_PORT_ERR_CHK_A
    #define OPTCFGHSBI_REG_DN_PDPHYDIS_A			BIT3	//0/0/x/x REG_DN_PDPHYDIS_A
    #define OPTCFGHSBI_REG_DN_FORCEHSMOD_A			BIT2	//0/0/x/x REG_DN_FORCEHSMOD_A
    #define OPTCFGHSBI_REG_DN_NOCHIRP_A			BIT1	//0/0/x/x REG_DN_NOCHIRP_A
    #define OPTCFGHSBI_REG_DN_POWER_LOST_A			BIT0	//1b/1b/x/x Reserved (Do Not Program)
#define OPTCFGHSBI_USB2_OPTION_RX125		0x125	//USB2 Option RX125
    #define OPTCFGHSBI_REG_PDHSTRSE0_A			BIT7	//1b/1b/x/x REG_PDHSTRSE0_A
    #define OPTCFGHSBI_REG_STRICT_EOP_EN_A			BIT6	//1b/1b/x/x Reserved (Do Not Program)
    #define OPTCFGHSBI_REG_DN_L1_EN_A			BIT5	//1b/1b/x/x REG_DN_L1_EN_A
    #define OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_A			BIT4	//0/0/x/x REG_LONG_LOW_SPEED_DETECTION_A
    #define OPTCFGHSBI_REG_SE1_CONN_DIS_A			BIT3	//1b/1b/x/x REG_SE1_CONN_DIS_A
    #define OPTCFGHSBI_REG_DBG104EN_A			BIT2	//0/0/x/x High Speed Detection Handshake Needn¡¯t Wait the Chirp K that the Device Drive
    #define OPTCFGHSBI_REG_DISCONNECT_POWER_A			BIT1	//0/0/x/x REG_DISCONNECT_POWER_A
    #define OPTCFGHSBI_REG_DISCONNECT_OPTION_A			BIT0	//1b/1b/x/x REG_DISCONNECT_OPTION_A
#define OPTCFGHSBI_USB2_OPTION_RX126		0x126	//USB2 Option RX126
    #define OPTCFGHSBI_REG_FS_EOPVAL_A			0xF0	//3h/3h/x/x REG_FS_EOPVAL_A
    #define OPTCFGHSBI_REG_LS_EOPVAL_A			0xF	//8h/8h/x/x REG_LS_EOPVAL_A
#define OPTCFGHSBI_USB2_OPTION_RX127		0x127	//USB2 Option RX127
    #define OPTCFGHSBI_REG_LONG_BUS_IDLE_A			BIT7	//1b/1b/x/x REG_LONG_BUS_IDLE_A
    #define OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_A			BIT6	//0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_A
    #define OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_A			BIT5	//1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_A
    #define OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_A			BIT4	//1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_A
    #define OPTCFGHSBI_REG_RXRESET_DIS_A			BIT3	//0/0/x/x REG_RXRESET_DIS_A
    #define OPTCFGHSBI_PDSUSMOD_FW_A			BIT2	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_DISCVLD_FW_A			BIT1	//0/0/x/x REG_DISCVLD_FW_A
    #define OPTCFGHSBI_REG_DISCVLD_FW_OPT_A			BIT0	//0/0/x/x REG_DISCVLD_FW_OPT_A
#define OPTCFGHSBI_USB2_OPTION_RX128		0x128	//USB2 Option RX128
    #define OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_A			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_DCP_DEBOUNCE_A			(BIT4 + BIT5)	//01b/01b/x/x Reserved (Do Not Program)
    #define OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_A			BIT3	//0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_A
    #define OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_A			BIT2	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_CDPFLAG_FWCLR_A			BIT1	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_A			BIT0	//0/0/x/x Reserved
#define OPTCFGHSBI_USB2_OPTION_RX129		0x129	//USB2 Option RX129
    #define OPTCFGHSBI_RESERVED_Z21			0xFC	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_DN_RWU_EN_A			BIT1	//1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port A
    #define OPTCFGHSBI_REG_POWER_ON_A			BIT0	//0/0/x/x Reserved 
#define OPTCFGHSBI_USB2_OPTION_RX12A		0x12A	//USB2 Option RX12A
    #define OPTCFGHSBI_USB2P1_TMOUT_4MS_PARM			0xFF	//1Fh/1Fh/x/x USB2P1_TMOUT_4MS_PARM
#define OPTCFGHSBI_USB2_OPTION_RX200		0x200	//USB2 Option RX200
    #define OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_B			0xF0	//1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_B			0xF	//6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_B
#define OPTCFGHSBI_USB2_OPTION_RX201		0x201	//USB2 Option RX201
    #define OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_B			0xFF	//5Ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_B
#define OPTCFGHSBI_USB2_OPTION_RX202		0x202	//USB2 Option RX202
    #define OPTCFGHSBI_REG_RXCPLOPT_B			BIT7	//1b/1b/x/x REG_RXCPLOPT_B
    #define OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_B			BIT6	//1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_B
    #define OPTCFGHSBI_REG_L1_EN_B			BIT5	//0/0/x/x REG_L1_EN_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_B			BIT4	//0/0/x/x REG_UP_SIE_HC_SYNC_JEND_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_B			BIT3	//0/0/x/x REG_UP_SIE_HC_SYNC_FAST_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_B			BIT2	//0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_B			BIT1	//0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_B			BIT0	//1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_B
#define OPTCFGHSBI_USB2_OPTION_RX203		0x203	//USB2 Option RX203
    #define OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_B			0xFF	//24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_B
#define OPTCFGHSBI_USB2_OPTION_RX204		0x204	//USB2 Option RX204
    #define OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_B			0xF0	//6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_B
    #define OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_B			0xF	//1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_B
#define OPTCFGHSBI_USB2_OPTION_RX205		0x205	//USB2 Option RX205
    #define OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_B			BIT7	//1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_B
    #define OPTCFGHSBI_REG_NPTT_RCTB_DIR_B			BIT6	//0/0/x/x REG_NPTT_RCTB_DIR_B
    #define OPTCFGHSBI_REG_NPTT_RCHKHSH_B			BIT5	//1b/1b/x/x REG_NPTT_RCHKHSH_B
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_EN_B			BIT4	//1b/1b/x/x REG_NPTT_RRACKTM_EN_B
    #define OPTCFGHSBI_REG_NPTT_RCONTFST_B			BIT3	//1b/1b/x/x REG_NPTT_RCONTFST_B
    #define OPTCFGHSBI_REG_NPTT_RCHKDATAPID_B			BIT2	//0/0/x/x REG_NPTT_RCHKDATAPID_B
    #define OPTCFGHSBI_REG_NPTT_RMATCH_ALL_B			BIT1	//1b/1b/x/x REG_NPTT_RMATCH_ALL_B
    #define OPTCFGHSBI_REG_EOF_RST_TX_B			BIT0	//0/0/x/x REG_EOF_RST_TX_B
#define OPTCFGHSBI_USB2_OPTION_RX206		0x206	//USB2 Option RX206
    #define OPTCFGHSBI_RESERVED_Z22			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_B			BIT4	//1b/1b/x/x REG_UPRX_STOP_TT_GATE_B
    #define OPTCFGHSBI_REG_PTT_SEARCH_LEN_B			(BIT2 + BIT3)	//0/0/x/x REG_PTT_SEARCH_LEN_B
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_B			BIT1	//1b/1b/x/x REG_NPTT_RRACKTM_FWEN_B
    #define OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_B			BIT0	//1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_B
#define OPTCFGHSBI_USB2_OPTION_RX207		0x207	//USB2 Option RX207
    #define OPTCFGHSBI_RESERVED_Z23			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_B			0x7F	//1Dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_B
#define OPTCFGHSBI_USB2_OPTION_RX208		0x208	//USB2 Option RX208
    #define OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_B			0xFFFF0000	//DACh/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_B
    #define OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_B			0xFFFF	//1B58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_B
#define OPTCFGHSBI_USB2_OPTION_RX20C		0x20C	//USB2 Option RX20C
    #define OPTCFGHSBI_RESERVED_Z24			0xF0000000	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_FS_B			0xFFF0000	//2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_B
    #define OPTCFGHSBI_RESERVED_Z25			0xF000	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_NPTT_RRACKTM_LS_B			0xFFF	//F50h/f50h/x/x REG_NPTT_BUFA_TIMEOK_LS_B
#define OPTCFGHSBI_USB2_OPTION_RX210		0x210	//USB2 Option RX210
    #define OPTCFGHSBI_RESERVED_Z26			0xF8000000	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_PTT_FULL_DELAY_B			0x7FF0000	//90h/90h/x/x REG_PTT_FULL_DELAY_B
    #define OPTCFGHSBI_RESERVED_Z27			0xF800	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_PTT_LOW_DELAY_B			0x7FF	//44Ch/44ch/x/x REG_PTT_LOW_DELAY_B
#define OPTCFGHSBI_USB2_OPTION_RX214		0x214	//USB2 Option RX214
    #define OPTCFGHSBI_RESERVED_Z28			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_EOF2_B			0x1FFF0000	//7h/7h/x/x REG_FR_HIGH_EOF2_B
    #define OPTCFGHSBI_RESERVED_Z29			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_EOF1_B			0x1FFF	//45h/45h/x/x REG_FR_HIGH_EOF1_B
#define OPTCFGHSBI_USB2_OPTION_RX218		0x218	//USB2 Option RX218
    #define OPTCFGHSBI_REG_FR_FULL_EOF2_B			0xFFFF0000	//31h/31h/x/x REG_FR_FULL_EOF2_B
    #define OPTCFGHSBI_REG_FR_FULL_EOF1_B			0xFFFF	//9Fh/9fh/x/x REG_FR_FULL_EOF1_B
#define OPTCFGHSBI_USB2_OPTION_RX21C		0x21C	//USB2 Option RX21C
    #define OPTCFGHSBI_RESERVED_Z30			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_INIT_B			0x1FFF0000	//1D4Ch/1d4ch/x/X REG_FR_HIGH_INIT_B
    #define OPTCFGHSBI_REG_FR_FULL_INIT_B			0xFFFF	//EA60h/ea60h/x/x REG_FR_FULL_INIT_B
#define OPTCFGHSBI_USB2_OPTION_RX220		0x220	//USB2 Option RX220
    #define OPTCFGHSBI_RESERVED_Z31			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_FR_HIGH_OVFL_B			0x1FFF	//1D57h/1d57h/x/x REG_FR_HIGH_OVFL_B
#define OPTCFGHSBI_USB2_OPTION_RX222		0x222	//USB2 Option RX222
    #define OPTCFGHSBI_RESERVED_Z32			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_EOP_FLAG_B			BIT6	//1b/1b/x/x Reserved (Do Not Program)
    #define OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_B			BIT5	//1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_B
    #define OPTCFGHSBI_REG_PAMP_TX_EN_B			BIT4	//0/0/x/x Reserved 
    #define OPTCFGHSBI_REG_SUSPEND_PROPAGATION_B			BIT3	//0/0/x/x Reserved 
    #define OPTCFGHSBI_REG_DNCOLL_EOP_SEL_B			BIT2	//0/0/x/x REG_DNCOLL_EOP_SEL_B
    #define OPTCFGHSBI_REG_TT_COLL_DET_DIS_B			BIT1	//1b/1b/x/x REG_TT_COLL_DET_DIS_B
    #define OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_B			BIT0	//0/0/x/x REG_DN_LPM_MANUAL_EOR_B
#define OPTCFGHSBI_USB2_OPTION_RX223		0x223	//USB2 Option RX223
    #define OPTCFGHSBI_REG_DN_EOI_EOR1_B			0xFF	//64h/64h/x/x REG_DN_EOI_EOR1_B
#define OPTCFGHSBI_USB2_OPTION_RX224		0x224	//USB2 Option RX224
    #define OPTCFGHSBI_REG_DN_SUSDISABLE_B			BIT7	//1b/1b/x/x REG_DN_SUSDISABLE_B
    #define OPTCFGHSBI_REG_EOF1_EOF2_B			BIT6	//1b/1b/x/x REG_EOF1_EOF2_B
    #define OPTCFGHSBI_FS_LPBK_B			BIT5	//0/0/x/x Reserved 
    #define OPTCFGHSBI_REG_DN_PORT_ERR_CHK_B			BIT4	//0/0/x/x REG_DN_PORT_ERR_CHK_B
    #define OPTCFGHSBI_REG_DN_PDPHYDIS_B			BIT3	//0/0/x/x REG_DN_PDPHYDIS_B
    #define OPTCFGHSBI_REG_DN_FORCEHSMOD_B			BIT2	//0/0/x/x REG_DN_FORCEHSMOD_B
    #define OPTCFGHSBI_REG_DN_NOCHIRP_B			BIT1	//0/0/x/x REG_DN_NOCHIRP_B
    #define OPTCFGHSBI_REG_DN_POWER_LOST_B			BIT0	//1b/1b/x/x Reserved 
#define OPTCFGHSBI_USB2_OPTION_RX225		0x225	//USB2 Option RX225
    #define OPTCFGHSBI_REG_PDHSTRSE0_B			BIT7	//1b/1b/x/x REG_PDHSTRSE0_B
    #define OPTCFGHSBI_REG_STRICT_EOP_EN_B			BIT6	//1b/1b/x/x Reserved (Do Not Program)
    #define OPTCFGHSBI_REG_DN_L1_EN_B			BIT5	//1b/1b/x/x REG_DN_L1_EN_B
    #define OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_B			BIT4	//0/0/x/x REG_LONG_LOW_SPEED_DETECTION_B
    #define OPTCFGHSBI_REG_SE1_CONN_DIS_B			BIT3	//1b/1b/x/x REG_SE1_CONN_DIS_B
    #define OPTCFGHSBI_REG_DBG104EN_B			BIT2	//0/0/x/x High Speed Detection Handshake Needn¡¯t Wait the Chirp K that the Device Drive
    #define OPTCFGHSBI_REG_DISCONNECT_POWER_B			BIT1	//0/0/x/x REG_DISCONNECT_POWER_B
    #define OPTCFGHSBI_REG_DISCONNECT_OPTION_B			BIT0	//1b/1b/x/x REG_DISCONNECT_OPTION_B
#define OPTCFGHSBI_USB2_OPTION_RX226		0x226	//USB2 Option RX226
    #define OPTCFGHSBI_REG_FS_EOPVAL_B			0xF0	//3h/3h/x/x REG_FS_EOPVAL_B
    #define OPTCFGHSBI_REG_LS_EOPVAL_B			0xF	//8h/8h/x/x REG_LS_EOPVAL_B
#define OPTCFGHSBI_USB2_OPTION_RX227		0x227	//USB2 Option RX227
    #define OPTCFGHSBI_REG_LONG_BUS_IDLE_B			BIT7	//1b/1b/x/x REG_LONG_BUS_IDLE_B
    #define OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_B			BIT6	//0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_B
    #define OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_B			BIT5	//1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_B
    #define OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_B			BIT4	//1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_B
    #define OPTCFGHSBI_REG_RXRESET_DIS_B			BIT3	//0/0/x/x REG_RXRESET_DIS_B
    #define OPTCFGHSBI_PDSUSMOD_FW_B			BIT2	//0/0/x/x PDSUSMOD_FW_B
    #define OPTCFGHSBI_REG_DISCVLD_FW_B			BIT1	//0/0/x/x REG_DISCVLD_FW_B
    #define OPTCFGHSBI_REG_DISCVLD_FW_OPT_B			BIT0	//0/0/x/x REG_DISCVLD_FW_OPT_B
#define OPTCFGHSBI_USB2_OPTION_RX228		0x228	//USB2 Option RX228
    #define OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_B			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_DCP_DEBOUNCE_B			(BIT4 + BIT5)	//01b/01b/x/x Reserved
    #define OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_B			BIT3	//0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_B
    #define OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_B			BIT2	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_CDPFLAG_FWCLR_B			BIT1	//0/0/x/x Reserved
    #define OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_B			BIT0	//0/0/x/x Reserved
#define OPTCFGHSBI_USB2_OPTION_RX229		0x229	//USB2 Option RX229
    #define OPTCFGHSBI_RESERVED_Z33			0xFC	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_DN_RWU_EN_B			BIT1	//1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port B
    #define OPTCFGHSBI_REG_POWER_ON_B			BIT0	//0/0/x/x Reserved 
#define OPTCFGHSBI_USB2_OPTION_RX22A		0x22A	//USB2 Option RX22A
    #define OPTCFGHSBI_USB2P2_TMOUT_4MS_PARM			0xFF	//1Fh/1Fh/x/x USB2P2_TMOUT_4MS_PARM
#define OPTCFGHSBI_USB2_OPTION_RX600		0x600	//USB2 Option RX600
    #define OPTCFGHSBI_TEST_HTX_A			BIT7	//0/0/x/x HS TX Test Mode Register
    #define OPTCFGHSBI_TXHSRCTRL_A			(BIT4 + BIT5 + BIT6)	//100b/100b/x/x High Speed Driver Slew Rate Control
    #define OPTCFGHSBI_CTRL_A			0xF	//1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define OPTCFGHSBI_USB2_OPTION_RX601		0x601	//USB2 Option RX601
    #define OPTCFGHSBI_TEST_HTX_B			BIT7	//0/0/x/x HS TX Test Mode Register
    #define OPTCFGHSBI_TXHSRCTRL_B			(BIT4 + BIT5 + BIT6)	//100b/100b/x/x High Speed Driver Slew Rate Control
    #define OPTCFGHSBI_CTRL_B			0xF	//1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define OPTCFGHSBI_USB2_OPTION_RX605		0x605	//USB2 Option RX605
    #define OPTCFGHSBI_RXDATA_O_A			BIT7	//0/x/x/x RXDATA_O_A
    #define OPTCFGHSBI_SQUELCH_O_A			BIT6	//0/x/x/x SQUELCH_O_A
    #define OPTCFGHSBI_DISCONNECT_O_A			BIT5	//0/x/x/x DISCONNECT_O_A
    #define OPTCFGHSBI_TERM_ON_A			BIT4	//0/x/x/x TERM_ON_A
    #define OPTCFGHSBI_DISCNT_A			(BIT2 + BIT3)	//01b/01b/x/x 575mv Disconnection Level Fine Tune
    #define OPTCFGHSBI_SQSET_A			(BIT0 + BIT1)	//01b/01b/x/x 125mv Squelch Level Fine Tune
#define OPTCFGHSBI_USB2_OPTION_RX606		0x606	//USB2 Option RX606
    #define OPTCFGHSBI_RXDATA_O_B			BIT7	//0/x/x/x RXDATA_O_B
    #define OPTCFGHSBI_SQUELCH_O_B			BIT6	//0/x/x/x SQUELCH_O_B
    #define OPTCFGHSBI_DISCONNECT_O_B			BIT5	//0/x/x/x DISCONNECT_O_B
    #define OPTCFGHSBI_TERM_ON_B			BIT4	//0/x/x/x TERM_ON_B
    #define OPTCFGHSBI_DISCNT_B			(BIT2 + BIT3)	//01b/01b/x/x 575mv Disconnection Level Fine Tune
    #define OPTCFGHSBI_SQSET_B			(BIT0 + BIT1)	//01b/01b/x/x 125mv Squelch Level Fine Tune
#define OPTCFGHSBI_USB2_OPTION_RX60A		0x60A	//USB2 Option RX60A
    #define OPTCFGHSBI_RESERVED_Z34			0xF8	//0/R/x/x Reserved
    #define OPTCFGHSBI_SDP_A			BIT2	//0/x/x/x SDP_A
    #define OPTCFGHSBI_SDN_A			BIT1	//0/x/x/x SDN_A
    #define OPTCFGHSBI_RXD_A			BIT0	//0/x/x/x RXD_A
#define OPTCFGHSBI_USB2_OPTION_RX60B		0x60B	//USB2 Option RX60B
    #define OPTCFGHSBI_RESERVED_Z35			0xF8	//0/R/x/x Reserved
    #define OPTCFGHSBI_SDP_B			BIT2	//0/x/x/x SDP_B
    #define OPTCFGHSBI_SDN_B			BIT1	//0/x/x/x SDN_B
    #define OPTCFGHSBI_RXD_B			BIT0	//0/x/x/x RXD_B
#define OPTCFGHSBI_USB2_OPTION_RX60F		0x60F	//USB2 Option RX60F
    #define OPTCFGHSBI_RESERVED_Z36			0xF0	//0/R/x/x Reserved
    #define OPTCFGHSBI_TEST_HTX_A_LPM			BIT3	//0/0/x/x HS TX Test Mode Register for LPM
    #define OPTCFGHSBI_PULLDOWNR_ON_A			BIT2	//1b/1b/x/x Pull down 15K Resistor
    #define OPTCFGHSBI_TEST_FLRX_A			BIT1	//0/x/x/x FS/LS RX Receiver Comparator Output
    #define OPTCFGHSBI_TEST_FLTX_A			BIT0	//0/0/x/x FS/LS TX Test Mode Register
#define OPTCFGHSBI_USB2_OPTION_RX610		0x610	//USB2 Option RX610
    #define OPTCFGHSBI_RESERVED_Z37			0xF0	//0/R/x/x Reserved
    #define OPTCFGHSBI_TEST_HTX_B_LPM			BIT3	//0/0/x/x HS TX Test Mode Register for LPM
    #define OPTCFGHSBI_PULLDOWNR_ON_B			BIT2	//1b/1b/x/x Pull down 15K Resistor
    #define OPTCFGHSBI_TEST_FLRX_B			BIT1	//0/x/x/x FS/LS RX Receiver Comparator Output
    #define OPTCFGHSBI_TEST_FLTX_B			BIT0	//0/0/x/x FS/LS TX Test Mode Register
#define OPTCFGHSBI_USB2_OPTION_RX611		0x611	//USB2 Option RX611
    #define OPTCFGHSBI_RESERVED_Z38			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_TXFSRCTRL_A			(BIT4 + BIT5 + BIT6)	//011b/011b/x/x Full Speed Driver Slew Rate Control
    #define OPTCFGHSBI_RESERVED_Z39			BIT3	//0/R/x/x Reserved
    #define OPTCFGHSBI_TXLSRCTRL_A			(BIT0 + BIT1 + BIT2)	//011b/011b/x/x Low speed Driver Slew Rate Control
#define OPTCFGHSBI_USB2_OPTION_RX612		0x612	//USB2 Option RX612
    #define OPTCFGHSBI_RESERVED_Z40			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_TXFSRCTRL_B			(BIT4 + BIT5 + BIT6)	//011b/011b/x/x Full Speed Driver Slew Rate Control
    #define OPTCFGHSBI_RESERVED_Z41			BIT3	//0/0/x/x Reserved
    #define OPTCFGHSBI_TXLSRCTRL_B			(BIT0 + BIT1 + BIT2)	//011b/011b/x/x Low speed Driver Slew Rate Control
#define OPTCFGHSBI_USB2_OPTION_RX614		0x614	//USB2 Option RX614
    #define OPTCFGHSBI_RESERVED_Z42			0xFE	//0/R/x/x Reserved
    #define OPTCFGHSBI_TMODE			BIT0	//1b/1b/x/x Set the PLLTEST Output
#define OPTCFGHSBI_USB2_OPTION_RX615		0x615	//USB2 Option RX615
    #define OPTCFGHSBI_INDATADLY			(BIT6 + BIT7)	//0/0/x/x DPLL Input Data Delay Select
    #define OPTCFGHSBI_TRACKSPD			(BIT4 + BIT5)	//01b/01b/x/x DPLL Track Speed Select
    #define OPTCFGHSBI_LOCKSPD			(BIT2 + BIT3)	//11b/11b/x/x DPLL Lock Speed Select
    #define OPTCFGHSBI_FASTLOCK			BIT1	//1b/1b/x/x DPLL_LPF Lock Mode Set Register
    #define OPTCFGHSBI_FASTSTART			BIT0	//0/0/x/x DPLL_ZPS Double Sampling Set Register
#define OPTCFGHSBI_USB2_OPTION_RX616		0x616	//USB2 Option RX616
    #define OPTCFGHSBI_DPLL_BISTOK			BIT7	//0/x/x/x DPLL BIST Pattern Matching Flag
    #define OPTCFGHSBI_DPLL_BISTS2			BIT6	//0/0/x/x DPLL BIST Set Register for Different Test Pattern
    #define OPTCFGHSBI_DPLL_BISTS1			BIT5	//0/0/x/x DPLL BIST Set Register for Different Test Pattern
    #define OPTCFGHSBI_DPLL_BISTS0			BIT4	//0/0/x/x DPLL BIST Set Register for Different Test Pattern
    #define OPTCFGHSBI_DPLL_BISTRST			BIT3	//0/0/x/x Set Register to Reset DPLL for BIST
    #define OPTCFGHSBI_RDOUT_ENB			BIT2	//0/0/x/x DPLL RDOUT4:0 Output Enable
    #define OPTCFGHSBI_INDLY			(BIT0 + BIT1)	//0/0/x/x DPLL NSQ Offset set Register
#define OPTCFGHSBI_USB2_OPTION_RX617		0x617	//USB2 Option RX617
    #define OPTCFGHSBI_RESERVED_Z43			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_LBACK_ENB			BIT5	//0/0/x/x DPLL Loopback Enable
    #define OPTCFGHSBI_RDOUT			0x1F	//0/0/x/x DPLL Test Mode Observed Signals
#define OPTCFGHSBI_USB2_OPTION_RX618		0x618	//USB2 Option RX618
    #define OPTCFGHSBI_INDATADLY_LPM			(BIT6 + BIT7)	//0/0/x/x DPLL Input Data Delay Select for LPM
    #define OPTCFGHSBI_TRACKSPD_LPM			(BIT4 + BIT5)	//01b/01b/x/x DPLL Track Speed Select for LPM
    #define OPTCFGHSBI_LOCKSPD_LPM			(BIT2 + BIT3)	//11b/11b/x/x DPLL Lock Speed Select for LPM
    #define OPTCFGHSBI_FASTLOCK_LPM			BIT1	//1b/1b/x/x DPLL_LPF Lock Mode Set Register for LPM
    #define OPTCFGHSBI_FASTSTART_LPM			BIT0	//0/0/x/x DPLL_ZPS Double Sampling Set Register for LPM
#define OPTCFGHSBI_USB2_OPTION_RX619		0x619	//USB2 Option RX619
    #define OPTCFGHSBI_DPLL_BISTOK_LPM			BIT7	//0/X/x/x DPLL BIST Pattern Matching Flag for LPM
    #define OPTCFGHSBI_DPLL_BISTS2_LPM			BIT6	//0/0/x/x DPLL BIST Set Register for Different Test Pattern for LPM
    #define OPTCFGHSBI_DPLL_BISTS1_LPM			BIT5	//0/0/x/x DPLL BIST Set Register for Different Test Pattern for LPM
    #define OPTCFGHSBI_DPLL_BISTS0_LPM			BIT4	//0/0/x/x DPLL BIST Set Register for Different Test Pattern for LPM
    #define OPTCFGHSBI_DPLL_BISTRST_LPM			BIT3	//0/0/x/x Set Register to Reset DPLL for BIST for LPM
    #define OPTCFGHSBI_RDOUT_ENB_LPM			BIT2	//0/0/x/x DPLL RDOUT4:0 Output Enable for LPM
    #define OPTCFGHSBI_INDLY_LPM			(BIT0 + BIT1)	//0/0/x/x DPLL NSQ Offset Set Register for LPM
#define OPTCFGHSBI_USB2_OPTION_RX61A		0x61A	//USB2 Option RX61A
    #define OPTCFGHSBI_RESERVED_Z44			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_LBACK_ENB_LPM			BIT5	//0/0/x/x DPLL Loopback Enable
    #define OPTCFGHSBI_RDOUT_LPM			0x1F	//0/x/x/x DPLL Test Mode Observed Signals
#define OPTCFGHSBI_USB2_OPTION_RX61B		0x61B	//USB2 Option RX61B
    #define OPTCFGHSBI_RESERVED_Z45			0xFC	//0/R/x/x Reserved
    #define OPTCFGHSBI_ITRIM			(BIT0 + BIT1)	//0/0/x/x Reserved
#define OPTCFGHSBI_USB2_OPTION_RX61C		0x61C	//USB2 Option RX61C
    #define OPTCFGHSBI_REFDLY_SEL_APLL			(BIT5 + BIT6 + BIT7)	//0/0/x/x REFDLY_SEL_APLL[:0]
    #define OPTCFGHSBI_ICPSEL_APLL			0x1E	//0101b/0101b/x/x ICPSEL_APLL[3:0]
    #define OPTCFGHSBI_RESERVED_Z46			BIT0	//0/R/x/x Reserved
#define OPTCFGHSBI_USB2_OPTION_RX61D		0x61D	//USB2 Option RX61D
    #define OPTCFGHSBI_RESERVED_Z47			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGHSBI_REG_RSTAPLL_CTL			BIT4	//0/0/x/x REG_RSTAPLL_CTL
    #define OPTCFGHSBI_REG_RSTAPLL			BIT3	//1b/1b/x/x REG_RSTAPLL 
    #define OPTCFGHSBI_FBDLY_SEL_APLL			(BIT0 + BIT1 + BIT2)	//0/0/x/x FBDLY_SEL_APLL[2:0]
#define OPTCFGHSBI_USB2_OPTION_RX61E		0x61E	//USB2 Option RX61E
    #define OPTCFGHSBI_DIV_M_APLL			0xFF	//01001110b/01001110b/x/x DIV_M_APLL[7:0]
#define OPTCFGHSBI_USB2_OPTION_RX61F		0x61F	//USB2 Option RX61F
    #define OPTCFGHSBI_FVCO_TUNE_TC_APLL			0xF0	//0/0/x/x FVCO_TUNE_TC_APLL[3:0]
    #define OPTCFGHSBI_FVCO_TUNE_ABS_APLL			0xF	//0/0/x/x FVCO_TUNE_ABS_APLL[3:0]
#define OPTCFGHSBI_USB2_OPTION_RX620		0x620	//USB2 Option RX620
    #define OPTCFGHSBI_U2_TEST			0xFFFFFFFF	//0/0/x/x U2_TEST [31:0]
#define OPTCFGHSBI_USB2_OPTION_RX624		0x624	//USB2 Option RX624
    #define OPTCFGHSBI_RESERVED_Z48			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_AUXB_LS_A			BIT6	//0/0/x/x AUXB_LS_A 
    #define OPTCFGHSBI_DN_EN_LS_A			(BIT3 + BIT4 + BIT5)	//000b/0/x/x DN_EN _LS_A 
    #define OPTCFGHSBI_UP_EN_LS_A			(BIT0 + BIT1 + BIT2)	//000b/0/x/x UP_EN_LS_A 
#define OPTCFGHSBI_USB2_OPTION_RX625		0x625	//USB2 Option RX625
    #define OPTCFGHSBI_TXLSR_MODE_A			(BIT6 + BIT7)	//01b/01b/x/x TXLSR_MODE_A 
    #define OPTCFGHSBI_IDN_SEL_LS_A			(BIT3 + BIT4 + BIT5)	//000b/0/x/x IDN_SEL_LS_A 
    #define OPTCFGHSBI_IUP_SEL_LS_A			(BIT0 + BIT1 + BIT2)	//000b/0/x/x IUP_SEL_LS_A 
#define OPTCFGHSBI_USB2_OPTION_RX626		0x626	//USB2 Option RX626
    #define OPTCFGHSBI_RESL_DN_LS_A			(BIT6 + BIT7)	//00b/0/x/x RESL_DN_LS_A 
    #define OPTCFGHSBI_RESL_UP_LS_A			(BIT4 + BIT5)	//00b/0/x/x RESL_UP_LS_A 
    #define OPTCFGHSBI_VMID_TRIM_LS_A			0xF	//0111b/0111b/x/x VMID_TRIM_LS_A 
#define OPTCFGHSBI_USB2_OPTION_RX627		0x627	//USB2 Option RX627
    #define OPTCFGHSBI_RESERVED_Z49			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_AUXB_FS_A			BIT6	//0/0/x/x AUXB_FS_A 
    #define OPTCFGHSBI_DN_EN_FS_A			(BIT3 + BIT4 + BIT5)	//000b/0/x/x DN_EN _FS_A 
    #define OPTCFGHSBI_UP_EN_FS_A			(BIT0 + BIT1 + BIT2)	//000b/0/x/x UP_EN_FS_A 
#define OPTCFGHSBI_USB2_OPTION_RX628		0x628	//USB2 Option RX628
    #define OPTCFGHSBI_TXFSR_MODE_A			(BIT6 + BIT7)	//01b/01b/x/x TXFSR_MODE_A 
    #define OPTCFGHSBI_IDN_SEL_FS_A			(BIT3 + BIT4 + BIT5)	//000b/0/x/x IDN_SEL_FS_A 
    #define OPTCFGHSBI_IUP_SEL_FS_A			(BIT0 + BIT1 + BIT2)	//000b/0/x/x IUP_SEL_FS_A 
#define OPTCFGHSBI_USB2_OPTION_RX629		0x629	//USB2 Option RX629
    #define OPTCFGHSBI_RESL_DN_FS_A			(BIT6 + BIT7)	//00b/0/x/x RESL_DN_FS_A 
    #define OPTCFGHSBI_RESL_UP_FS_A			(BIT4 + BIT5)	//00b/0/x/x RESL_UP_FS_A 
    #define OPTCFGHSBI_VMID_TRIM_FS_A			0xF	//0111b/0111b/x/x VMID_TRIM_FS_A 
#define OPTCFGHSBI_USB2_OPTION_RX62A		0x62A	//USB2 Option RX62A
    #define OPTCFGHSBI_RESERVED_Z50			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_AUXB_LS_B			BIT6	//0/0/x/x AUXB_LS_B 
    #define OPTCFGHSBI_DN_EN_LS_B			(BIT3 + BIT4 + BIT5)	//000b/0/x/x DN_EN _LS_B 
    #define OPTCFGHSBI_UP_EN_LS_B			(BIT0 + BIT1 + BIT2)	//000b/0/x/x UP_EN_LS_B 
#define OPTCFGHSBI_USB2_OPTION_RX62B		0x62B	//USB2 Option RX62B
    #define OPTCFGHSBI_TXLSR_MODE_B			(BIT6 + BIT7)	//01b/01b/x/x TXLSR_MODE_B
    #define OPTCFGHSBI_IDN_SEL_LS_B			(BIT3 + BIT4 + BIT5)	//000b/0/x/x IDN_SEL_LS_B 
    #define OPTCFGHSBI_IUP_SEL_LS_B			(BIT0 + BIT1 + BIT2)	//000b/0/x/x IUP_SEL_LS_B 
#define OPTCFGHSBI_USB2_OPTION_RX62C		0x62C	//USB2 Option RX62C
    #define OPTCFGHSBI_RESL_DN_LS_B			(BIT6 + BIT7)	//00b/0/x/x RESL_DN_LS_B 
    #define OPTCFGHSBI_RESL_UP_LS_B			(BIT4 + BIT5)	//00b/0/x/x RESL_UP_LS_B 
    #define OPTCFGHSBI_VMID_TRIM_LS_B			0xF	//0111b/0111b/x/x VMID_TRIM_LS_B 
#define OPTCFGHSBI_USB2_OPTION_RX62D		0x62D	//USB2 Option RX62D
    #define OPTCFGHSBI_RESERVED_Z51			BIT7	//0/R/x/x Reserved
    #define OPTCFGHSBI_AUXB_FS_B			BIT6	//0/0/x/x AUXB_FS_B 
    #define OPTCFGHSBI_DN_EN_FS_B			(BIT3 + BIT4 + BIT5)	//000b/0/x/x DN_EN _FS_B 
    #define OPTCFGHSBI_UP_EN_FS_B			(BIT0 + BIT1 + BIT2)	//000b/0/x/x UP_EN_FS_B 
#define OPTCFGHSBI_USB2_OPTION_RX62E		0x62E	//USB2 Option RX62E
    #define OPTCFGHSBI_TXFSR_MODE_B			(BIT6 + BIT7)	//01b/01b/x/x TXFSR_MODE_B 
    #define OPTCFGHSBI_IDN_SEL_FS_B			(BIT3 + BIT4 + BIT5)	//000b/0/x/x IDN_SEL_FS_B 
    #define OPTCFGHSBI_IUP_SEL_FS_B			(BIT0 + BIT1 + BIT2)	//000b/0/x/x IUP_SEL_FS_B 
#define OPTCFGHSBI_USB2_OPTION_RX62F		0x62F	//USB2 Option RX62F
    #define OPTCFGHSBI_RESL_DN_FS_B			(BIT6 + BIT7)	//00b/0/x/x RESL_DN_FS_B 
    #define OPTCFGHSBI_RESL_UP_FS_B			(BIT4 + BIT5)	//00b/0/x/x RESL_UP_FS_B 
    #define OPTCFGHSBI_VMID_TRIM_FS_B			0xF	//0111b/0111b/x/x VMID_TRIM_FS_B 
#define OPTCFGHSBI_USB2_OPTION_RX630		0x630	//USB2 Option RX630
    #define OPTCFGHSBI_RESERVED_Z52			0xFE00	//0/R/x/x Reserved
    #define OPTCFGHSBI_IPTUNE			(BIT6 + BIT7 + BIT8)	//100b/100b/x/x IPTUNE
    #define OPTCFGHSBI_IPTATUNE			(BIT3 + BIT4 + BIT5)	//000b/0/x/x IPTATUNE
    #define OPTCFGHSBI_BG_TRIM			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x BG_TRIM
//U3IP_SSCFG_C
#define U3IPSSCFGC_SSIP_COMMON_OPTIONAL_REG		0x000	//SSIP_Common_optional_register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_000_12			0xF000	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_PTMFLD			0xF00	//0/x/x/x Reserved
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_000_7			BIT7	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_SSCFGRISEWE			BIT6	//1b/x/x/x Sample the rising edge of WE to write data
    #define U3IPSSCFGC_R_PBD2TDRIVE			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_TIEH			BIT3	//1b/x/x/x Tie cell: always be 1
    #define U3IPSSCFGC_R_TIEL			BIT2	//0/x/x/x Tie cell: always be 0
    #define U3IPSSCFGC_R_DYNSUSCFGCLK			BIT1	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_DYNCORECFGCLK			BIT0	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_02		0x002	//SSIP_Common_Reserved_02
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_002			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_04		0x004	//SSIP_Common_Reserved_04
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_004			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_06		0x006	//SSIP_Common_Reserved_06
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_006			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_08		0x008	//SSIP_Common_Reserved_08
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_008			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_0A		0x00A	//SSIP_Common_Reserved_0A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_00A			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_0C		0x00C	//SSIP_Common_Reserved_0C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_00C			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_0E		0x00E	//SSIP_Common_Reserved_0E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_00E			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_10		0x010	//SSIP_Common_Reserved_10
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_10			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_12		0x012	//SSIP_Common_Reserved_12
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_12			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_14		0x014	//SSIP_Common_Reserved_14
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_14			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_16		0x016	//SSIP_Common_Reserved_16
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_16			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_18		0x018	//SSIP_Common_Reserved_18
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_18			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_1A		0x01A	//SSIP_Common_Reserved_1A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_1A			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_1C		0x01C	//SSIP_Common_Reserved_1C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_1C			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_1E		0x01E	//SSIP_Common_Reserved_1E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_1E			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_20		0x020	//SSIP_Common_Reserved_20
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_20			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_22		0x022	//SSIP_Common_Reserved_22
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_22			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_24		0x024	//SSIP_Common_Reserved_24
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_24			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_26		0x026	//SSIP_Common_Reserved_26
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_26			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_28		0x028	//SSIP_Common_Reserved_28
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_28			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_2A		0x02A	//SSIP_Common_Reserved_2A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_2A			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_2C		0x02C	//SSIP_Common_Reserved_2C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_2C			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_2E		0x02E	//SSIP_Common_Reserved_2E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_2E			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_30		0x030	//SSIP_Common_Reserved_30
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_30			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_32		0x032	//SSIP_Common_Reserved_32
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_32			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_34		0x034	//SSIP_Common_Reserved_34
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_34			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_36		0x036	//SSIP_Common_Reserved_36
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_36			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_38		0x038	//SSIP_Common_Reserved_38
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_38			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_3A		0x03A	//SSIP_Common_Reserved_3A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_3A			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_3C		0x03C	//SSIP_Common_Reserved_3C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_3C			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_3E		0x03E	//SSIP_Common_Reserved_3E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_3E			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_40		0x040	//SSIP_Common_Reserved_40
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_40			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_42		0x042	//SSIP_Common_Reserved_42
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_42			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_44		0x044	//SSIP_Common_Reserved_44
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_44			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_46		0x046	//SSIP_Common_Reserved_46
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_46			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_48		0x048	//SSIP_Common_Reserved_48
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_48			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_4A		0x04A	//SSIP_Common_Reserved_4A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_4A			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_4C		0x04C	//SSIP_Common_Reserved_4C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_4C			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_4E		0x04E	//SSIP_Common_Reserved_4E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_4E			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_50		0x050	//SSIP_Common_Reserved_50
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_50			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_52		0x052	//SSIP_Common_Reserved_52
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_52			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_54		0x054	//SSIP_Common_Reserved_54
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_54			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_56		0x056	//SSIP_Common_Reserved_56
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_56			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_58		0x058	//SSIP_Common_Reserved_58
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_58			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_5A		0x05A	//SSIP_Common_Reserved_5A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_5A			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_5C		0x05C	//SSIP_Common_Reserved_5C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_5C			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_5E		0x05E	//SSIP_Common_Reserved_5E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_5E			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_60		0x060	//SSIP_Common_Reserved_60
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_60			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_62		0x062	//SSIP_Common_Reserved_62
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_62			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_64		0x064	//SSIP_Common_Reserved_64
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_64			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_66		0x066	//SSIP_Common_Reserved_66
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_66			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_68		0x068	//SSIP_Common_Reserved_68
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_68			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_6A		0x06A	//SSIP_Common_Reserved_6A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_6A			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_6C		0x06C	//SSIP_Common_Reserved_6C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_6C			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_6E		0x06E	//SSIP_Common_Reserved_6E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_6E			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_70		0x070	//SSIP_Common_Reserved_70
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_70			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_72		0x072	//SSIP_Common_Reserved_72
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_72			0xFFFF	//HwInit/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_NEW_EPHY_REG0		0x074	//SSIP_Common_NEW_EPHY_ Register0
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_074			0xF800	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_IPTATUNE			(BIT8 + BIT9 + BIT10)	//0/x/x/x Internal Current Source Value Tuning
    #define U3IPSSCFGC_FHU_IPTUNE			(BIT5 + BIT6 + BIT7)	//0/x/x/x Internal Current Source Value Tuning
    #define U3IPSSCFGC_FHU_BG_TRIM			(BIT2 + BIT3 + BIT4)	//100b/x/x/x Fine Tune Bandgap Setting
    #define U3IPSSCFGC_FHU_CTSCLKSEL			BIT1	//0/x/x/x Select CTSCLK Source
    #define U3IPSSCFGC_FHU_EPHYMSTEN			BIT0	//0/x/x/x Force to turn on All Functions in Master Block when EPHY Testing
#define U3IPSSCFGC_SSIP_COMMON_NEW_EPHY_REG1		0x076	//SSIP_Common_NEW_EPHY_ Register1
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_076			0xF000	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_MPLL_FSEL			(BIT9 + BIT10 + BIT11)	//0/x/x/x MPLL VCO Frequency Tuning
    #define U3IPSSCFGC_FHU_MPLL_FLAGCK_EN			BIT8	//0/x/x/x Enable MPLL Flag Function when Debug Mode
    #define U3IPSSCFGC_FHU_MPLL_DELAY			(BIT6 + BIT7)	//01b/x/x/x MPLL Feedback Divider Delay Setting
    #define U3IPSSCFGC_FHU_MPLL_LOCK_EN			BIT5	//0/x/x/x Overwrite MPLL Lock Flag Setting
    #define U3IPSSCFGC_FHU_MPLL_OP			BIT4	//0/x/x/x MPLL Operation Mode for Debugging
    #define U3IPSSCFGC_FHU_MPLL_CP			0xF	//0011b/x/x/x MPLL CP Current Setting. 
#define U3IPSSCFGC_SSIP_COMMON_NEW_EPHY_REG2		0x078	//SSIP_Common_NEW_EPHY_ Register2
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_078			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_TPLL0_BDSET			0x7800	//0/x/x/x TPLL0 Manual Tuning Setting. Changing for Debug
    #define U3IPSSCFGC_FHU_TPLL0_BDSET_EN			BIT10	//0/x/x/x Enable TPLL0 Band Manual Tuning
    #define U3IPSSCFGC_FHU_TPLL0_FTUNE_EN			BIT9	//0/x/x/x Enable TPLL0 Frequency Manual Tuning
    #define U3IPSSCFGC_FHU_TPLL0_GATECLK_EN			BIT8	//0/x/x/x Enable Gating TPLL0 Clock
    #define U3IPSSCFGC_FHU_TPLL_BAND			(BIT6 + BIT7)	//0/x/x/x TPLL0 VCO Operation Frequency
    #define U3IPSSCFGC_FHU_TPLL0_FLAGCK_EN			BIT5	//0/x/x/x Enable TPLL0 Flag Function when Debug Mode
    #define U3IPSSCFGC_FHU_TPLL0_LOCK_EN			BIT4	//0/x/x/x Overwrite TPLL0 Lock Flag Setting
    #define U3IPSSCFGC_FHU_TPLL0_CP			0xF	//1111b/x/x/x TPLL0 CP Current Setting. 
#define U3IPSSCFGC_SSIP_COMMON_NEW_EPHY_REG3		0x07A	//SSIP_Common_NEW_EPHY_ Register3
    #define U3IPSSCFGC_FHU_TPLL0_VCRST			(BIT13 + BIT14 + BIT15)	//0/x/x/x TPLL0 Initial Vcontrol Selection
    #define U3IPSSCFGC_FHU_TPLL0_FTUNE			0x1FF8	//0/x/x/x TPLL0 Manual Tuning Setting.
    #define U3IPSSCFGC_FHU_TPLL0_DIV			(BIT0 + BIT1 + BIT2)	//0/x/x/x TPLL0 Feedback Frequency Dividers M0, M1,M2,N Selection and Settings 
#define U3IPSSCFGC_SSIP_COMMON_NEW_EPHY_REG4		0x07C	//SSIP_Common_NEW_EPHY_ Register4
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_07C			0xFF00	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_MPLL_SETEN			BIT7	//0/x/x/x MPLLPDB Set Enable
    #define U3IPSSCFGC_R_MPLL_SET			BIT6	//0/x/x/x MPLLPDB Set
    #define U3IPSSCFGC_FHU_TPLL0_CKBUFDUTY			(BIT3 + BIT4 + BIT5)	//0/x/x/x TPLL0 Clock Buffer Duty Selection
    #define U3IPSSCFGC_FHU_TPLL0_CKBUFVREG			(BIT0 + BIT1 + BIT2)	//0/x/x/x TPLL0 Clock Buffer Regulator Voltage Selection
#define U3IPSSCFGC_SSIP_COMMON_NEW_EPHY_REG5		0x07E	//SSIP_Common_NEW_EPHY_ Register5
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_07F			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define U3IPSSCFGC_EPU_TPLL0_OK			BIT13	//0/x/x/x TPLL0 Lock Flag Lock 
    #define U3IPSSCFGC_EPU_RTNTXOUT			0x1E00	//0/x/x/x TX Resistance Output
    #define U3IPSSCFGC_FHU_RTNBIST			(BIT7 + BIT8)	//0/x/x/x BIST Selection
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_07E			(BIT5 + BIT6)	//0/x/x/x Reserved
    #define U3IPSSCFGC_RSVU3IP_SSCFG_P_07E_SS			0x1F	//10000b/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_EPHY_BG_RTN_REG		0x080	//SSIP_Common_EPHY_BG_RTN_Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_80			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_RTNTXSET_10G			0x7800	//1000b/x/x/x TX Resistance Manual Setting (TT corner)
    #define U3IPSSCFGC_FHU_RTNTXSETEN_10G			BIT10	//0/x/x/x TX Resistance Set Enable
    #define U3IPSSCFGC_FHU_RTNVCSEL_10G			(BIT8 + BIT9)	//0/x/x/x RTN Comparator Voltage Tuning
    #define U3IPSSCFGC_EPU_RTNOUT			0xF0	//0/x/x/x RTN Codes Output
    #define U3IPSSCFGC_FHU_ITRIM_NP_10G			(BIT2 + BIT3)	//0/x/x/x For I-source Trimming of N-poly Resistor Type Use.
    #define U3IPSSCFGC_FHU_ITRIM_PP_10G			(BIT0 + BIT1)	//0/x/x/x For I-source Trimming of P-poly Resistor Type Use.
#define U3IPSSCFGC_SSIP_COMMON_EPHY_MPLL_TPLL_REG		0x082	//SSIP_Common_EPHY_MPLL_TPLL_Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_082			0xFF00	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_PLLTESTSEL_10G			(BIT6 + BIT7)	//0/x/x/x PLLTEST Output Setting
    #define U3IPSSCFGC_FHU_MPLLCPISEL_10G			(BIT3 + BIT4 + BIT5)	//011b/x/x/x MPLL Charge Pump Current Setting
    #define U3IPSSCFGC_FHU_MPLLRSEL_10G			(BIT1 + BIT2)	//10b/x/x/x MPLL Loop Filter Resistance Setting
    #define U3IPSSCFGC_FHU_FTMODE_10G			BIT0	//0/x/x/x Only Enable on FT
#define U3IPSSCFGC_SSIP_COMMON_EPHY_SPLL_REG_1		0x084	//SSIP_Common_EPHY_SPLL_Register_1
    #define U3IPSSCFGC_FHU_SDMDIGEN			BIT15	//0/x/x/x SSCPLL Digital Part Clock Enable
    #define U3IPSSCFGC_FHU_SDMDITHEREN			BIT14	//0/x/x/x Enable SDM Dithering
    #define U3IPSSCFGC_FHU_SDMSSCEN			BIT13	//0/x/x/x SSCPLL SSC Function in Digital Top 
    #define U3IPSSCFGC_FHU_SPLLINDIV			0x1F00	//01000b/x/x/x SPLL Input Divider
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_084			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_SPLLCP2I			BIT5	//0/x/x/x SSCPLL Charge Pump Current Option
    #define U3IPSSCFGC_FHU_SPLLFNEN			BIT4	//0/x/x/x SSCPLL Enable Fractional-N mode, Choose MMD Input 6b Control from FNDIV[5:0] or INDIV[5:0]
    #define U3IPSSCFGC_FHU_SPLLPDB			BIT3	//1b/x/x/x SSCPLL Power up by Register 
    #define U3IPSSCFGC_FHU_SPLLRSTB			BIT2	//1b/x/x/x SSCPLL Reset Control by Register
    #define U3IPSSCFGC_FHU_SPLLSSCSETEN			BIT1	//0/x/x/x Enable SSCPLL SSC
    #define U3IPSSCFGC_FHU_BYPASSOSC			BIT0	//0/x/x/x Oscillator Bypass Enable
#define U3IPSSCFGC_SSIP_COMMON_EPHY_SPLL_REG_2		0x086	//SSIP_Common_EPHY_SPLL_Register_2
    #define U3IPSSCFGC_FHU_RANGESEL_10G			(BIT14 + BIT15)	//0/x/x/x Locking frequency detect range.
    #define U3IPSSCFGC_FHU_DFCOW			0x3C00	//1000b/x/x/x DFC Overwrite Code for VREGSEL
    #define U3IPSSCFGC_FHU_SPLLBW			(BIT8 + BIT9)	//0/x/x/x SSCPLL Bandwidth Options 
    #define U3IPSSCFGC_FHU_SPLLSSCOS			(BIT5 + BIT6 + BIT7)	//001b/x/x/x SSC Mean Value Shift for Down Spread Profile
    #define U3IPSSCFGC_FHU_SPLLSSCMAG			(BIT2 + BIT3 + BIT4)	//100b/x/x/x SSC Management
    #define U3IPSSCFGC_FHU_SDMASYMSSC			BIT1	//1b/x/x/x Enable SSCPLL Asymmetry SSC
    #define U3IPSSCFGC_FHU_SDMREFCLKSEL			BIT0	//0/x/x/x SSCPLL Digital Part System Clock From 
#define U3IPSSCFGC_SSIP_COMMON_SPLL_DBG_REG		0x088	//SSIP_Common_SPLL_DBG_Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_088_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_DBGSEL			0x3F00	//0/x/x/x Debug Signal Selection Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_088_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define U3IPSSCFGC_EPU_SDMFNDIVO			0x1F	//0/x/x/x Readout SSCPLL SDM Output Codes Value
#define U3IPSSCFGC_SSIP_COMMON_SPLL_STA_PLLC_REG		0x08A	//SSIP_Common_SPLL_Status_PLLC_Register
    #define U3IPSSCFGC_R_UPCTPLLEN			BIT15	//1b/x/x/x Select Which Set Controls TPLL Enable Only for Hub Mode. 
    #define U3IPSSCFGC_R_DYNTPLLEN			BIT14	//0/x/x/x Reserved. Separate to each port
    #define U3IPSSCFGC_R_DYNBGEN			BIT13	//0/x/x/x Enable Dynamic Band Gap Function. 
    #define U3IPSSCFGC_R_TPLLPD			BIT12	//1b/x/x/x Firmware Control if TPLL Turn on or Not when No Device Connected
    #define U3IPSSCFGC_R_TPLLPDEN			BIT11	//1b/x/x/x Enable Firmware Control TPLL on Signal.
    #define U3IPSSCFGC_R_PLLCDYNEN			BIT10	//0/x/x/1b Enable PLLC dynamic clock in PLL power down. 
    #define U3IPSSCFGC_R_PLLCSSCEN			BIT9	//1b/x/x/x PLLC Control SSC Enable
    #define U3IPSSCFGC_R_PLLPDSEL			BIT8	//0/x/x/x Select to Turn Off SPLL or MPLL
    #define U3IPSSCFGC_EPU_DFCVREGSELO			0xF0	//0/x/x/x SSCPLL VCO Regulator Voltage Control Selection Mux
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_08A			0xF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_CLK_OPTION_REG		0x08C	//SSIP_Common_Clock_Option_Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_08C			0xFFC0	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_EXTSSCTM			BIT5	//0/x/x/x Extend SSC Time
    #define U3IPSSCFGC_R_RTNRTEN			BIT4	//0/x/x/x Re-tuning RTN Function when Firmware Modifies RTN Parameters
    #define U3IPSSCFGC_R_SCFGOF			BIT3	//1b/x/x/x When Enabled, SSCFG Clock will be Turned Off in Suspend State
    #define U3IPSSCFGC_R_DYNLDCLKEN			BIT2	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_DYNSDCLKEN			BIT1	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_RCVDETIP2			BIT0	//0/x/x/x Enable Receiver Detection Always in P2
#define U3IPSSCFGC_SSIP_COMMON_5G_PLLC_CTRL_REG		0x08E	//SSIP_Common_5G_PLLC_CTRL_Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_08E			0xFE00	//0/x/x/x Reserved
    #define U3IPSSCFGC_R_TPLL_SET_5G			BIT8	//0/x/x/x Register Set the TPLL Power on when R_TPLL_SETEN =1
    #define U3IPSSCFGC_R_TPLL_SETEN_5G			BIT7	//0/x/x/x Enable Register Control TPLLPDB when MPLL Power on
    #define U3IPSSCFGC_R_BGOFFRCVEN_5G			BIT6	//0/x/x/x USB3.0 EPHY Enable Register for LPHY Makes EPHY do RCVDET when BG is off
    #define U3IPSSCFGC_R_MPLLDYNOFFEN_5G			BIT5	//0/x/x/x USB3.0 EPHY Enable Register for LPHY Dynamically Control MPLL off
    #define U3IPSSCFGC_R_TPLLDYNOFFEN_5G			BIT4	//0/x/x/x USB3.0 EPHY Enable Register for LPHY Dynamically Control TPLL off
    #define U3IPSSCFGC_R_RTNTUNE_RST_5G			BIT3	//0/x/x/x USB3.0 EPHY RTN Function Reset
    #define U3IPSSCFGC_R_TPLLPDENB_5G			BIT2	//1b/x/x/x USB3.0 EPHY Enable to Turn off TPLL when MPLL on with No Device Connected
    #define U3IPSSCFGC_R_DYNBGEN_5G			BIT1	//0/x/x/x USB3.0 EPHY Enable Dynamic Bandgap Power on
    #define U3IPSSCFGC_R_PLLCDYNEN_5G			BIT0	//0/x/x/1b USB3.0 EPHY PLLC Dynamic Clock Enable
#define U3IPSSCFGC_SSIP_COMMON_EPHY_NWE_REG		0x090	//SSIP_Common_EPHY_NWE_Register
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_090			0xFFF0	//0/x/x/x Reserved
    #define U3IPSSCFGC_FHU_MPLLVCOREG_10G			(BIT1 + BIT2 + BIT3)	//100b/x/x/x VCO Regulator Voltage Fine Tune 
    #define U3IPSSCFGC_FHU_SLICERCTL_10G			BIT0	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_5G_EPHY_REG		0x092	//SSIP_Common_5G_EPHY_ Register
    #define U3IPSSCFGC_FHU_TPLLBW_5G			(BIT14 + BIT15)	//01b/x/x/x TPLL Close Loop Bandwidth Selection
    #define U3IPSSCFGC_FHU_MPLLBW_5G			(BIT12 + BIT13)	//01b/x/x/x MPLL Close Loop Bandwidth Selection
    #define U3IPSSCFGC_FHU_PLLFBRATIO_5G			BIT11	//0/x/x/x Feedback Clock Ratio for Test (also for all TPLL)
    #define U3IPSSCFGC_FHU_RTNTXSET_5G			0x780	//1000b/x/x/x TX Resistance Manual Setting (TT corner)
    #define U3IPSSCFGC_FHU_RTNTXSETEN_5G			BIT6	//0/x/x/x TX Resistance Set Enable
    #define U3IPSSCFGC_FHU_ITRIM_PP_5G			(BIT4 + BIT5)	//0/x/x/x For I-source Trimming of P-poly Resistor Type Use.
    #define U3IPSSCFGC_FHU_ITRIM_NP_5G			(BIT2 + BIT3)	//0/x/x/x For I-source Trimming of N-poly Resistor Type Use.
    #define U3IPSSCFGC_FHU_PLLTESTSEL_5G			(BIT0 + BIT1)	//0/x/x/x PLLTEST Output Setting
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_94		0x094	//SSIP_Common_Reserved_94
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_094			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_96		0x096	//SSIP_Common_Reserved_96
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_096			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_98		0x098	//SSIP_Common_Reserved_98
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_098			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_9A		0x09A	//SSIP_Common_Reserved_9A
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_09A			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_9C		0x09C	//SSIP_Common_Reserved_9C
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_09C			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGC_SSIP_COMMON_RESERVED_9E		0x09E	//SSIP_Common_Reserved_9E
    #define U3IPSSCFGC_RSVU3IP_SSCFG_C_09E			0xFFFF	//FFFFh/x/x/x Reserved
//U3IP_SSCFG_P
#define U3IPSSCFGP_SSIP_PORT_BASIC_FEATURE_REGS		0x000	//SSIP_PORT_Basic_Feature_Registers
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_000_6_SS			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_NUMHP_SS			0x3FC0	//04h/x/x/x Number of HP Buffer
    #define U3IPSSCFGP_R_SSPOTG_SS			BIT5	//0/x/x/x SSP OTG Function 
    #define U3IPSSCFGP_R_SPDSEL_SS			(BIT2 + BIT3 + BIT4)	//000b/x/x/x Link Speed Selection
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_000_0_SS			(BIT0 + BIT1)	//0/x/x/x Reserved
#define U3IPSSCFGP_SSIP_PORT_DYNAMIC_CLK_CTL_REGS		0x002	//SSIP_PORT_Dynamic_Clock_Control_Registers
    #define U3IPSSCFGP_R_PLTX250DYNPMEN_SS			BIT15	//0/x/x/X Enable SSP PL TX clock
    #define U3IPSSCFGP_R_RXDPDYNEN_SS			BIT14	//0/x/x/1b Enable RXDPP Dynamic Clock Function. 
    #define U3IPSSCFGP_R_RXHRDYNEN_SS			BIT13	//0/x/x/1b Enable RXHDR Dynamic Clock Function. 
    #define U3IPSSCFGP_R_LPBKDYNEN_SS			BIT12	//0/x/x/1b Enable loop-back Dynamic Clock Function. 
    #define U3IPSSCFGP_R_AGRSVLPHYRXDYNPMEN_SS			BIT11	//0/x/x/1b PHYLS RX Aggressive Dynamic Clock Enable
    #define U3IPSSCFGP_R_AGRSVLPHYTXDYNPMEN_SS			BIT10	//0/x/x/1b PHYLS TX Aggressive Dynamic Clock Enable
    #define U3IPSSCFGP_R_LPHYRXDYNPMEN_SS			BIT9	//0/x/x/1b PHYLS 2nd Level RX Dynamic Clock Enable
    #define U3IPSSCFGP_R_LPHYTXDYNPMEN_SS			BIT8	//0/x/x/1b PHYLS 2nd Level TX Dynamic Clock Enable
    #define U3IPSSCFGP_R_PHYDYNCLKEN_SS			BIT7	//0/x/x/1b PHYLS 1st Level Dynamic Clock Enable
    #define U3IPSSCFGP_R_LNRXDYNPMEN_SS			BIT6	//0/x/x/1b Link Layer 2nd Level RX Dynamic Clock Enable
    #define U3IPSSCFGP_R_LNTXDYNPMEN_SS			BIT5	//0/x/x/1b Link Layer 2nd level TX Dynamic Clock Enable
    #define U3IPSSCFGP_R_LNDYNCLKEN_SS			BIT4	//0/x/x/1b Link Layer 1st Level Dynamic Clock Enable
    #define U3IPSSCFGP_R_PLRXDYNPMEN_SS			BIT3	//0/x/x/1b Protocol Layer 2nd Level RX Dynamic Clock Enable
    #define U3IPSSCFGP_R_PLTXDYNPMEN_SS			BIT2	//0/x/x/1b Protocol Layer 2nd Level TX Dynamic Clock Enable
    #define U3IPSSCFGP_R_PLDYNCLKEN_SS			BIT1	//0/x/x/1b Protocol Layer 1st Level Dynamic Clock Enable
    #define U3IPSSCFGP_R_DYNPM_SS			BIT0	//0/x/x/1b Dynamic Power Management Control Enable
#define U3IPSSCFGP_SSIP_PORT_PGAR_OPTION_REGS1		0x004	//SSIP_PORT_PGAR_Option_Registers1
    #define U3IPSSCFGP_R_PCAPDIR_SS			(BIT14 + BIT15)	//01b/x/x/x FW control Direction Filed in Port Capability LMP
    #define U3IPSSCFGP_R_RTYDPHONLY_SS			BIT13	//1b/x/x/x Retransmit DPH only when DP Retry
    #define U3IPSSCFGP_R_RTYDPP_SS			BIT12	//0/x/x/x Re-transmit DPP when DP Retry
    #define U3IPSSCFGP_R_TIEBREAKER_SS			0xF00	//0/x/x/x Tiebreaker Value
    #define U3IPSSCFGP_R_FWTBRKEN_SS			BIT7	//0/x/x/x FW Control Tiebreaker Value
    #define U3IPSSCFGP_R_DLYMRKEN_SS			BIT6	//1b/x/x/x Enable Delayed Bit Marking
    #define U3IPSSCFGP_R_TIEBRKEN_SS			BIT5	//0/x/x/x Enable Tiebreaker Negotiation 
    #define U3IPSSCFGP_R_ITSQCTL_SS			BIT4	//0/x/x/x Update ITS Field in ITP after Retry
    #define U3IPSSCFGP_R_HDBUFRSTEN_SS			BIT3	//0/x/x/x HCI Purge Isochronous Packets in TXHDBUF During Training State
    #define U3IPSSCFGP_R_PCFGSMEN_SS			BIT2	//1b/x/x/x Automatic Port Configuration Generation 
    #define U3IPSSCFGP_R_ITSSEL_SS			(BIT0 + BIT1)	//00b/x/x/x ITS Delta Counter Estimation
#define U3IPSSCFGP_SSIP_PORT_PGAR_OPTION_REGS2		0x006	//SSIP_PORT_PGAR_Option_Registers2
    #define U3IPSSCFGP_R_DEVNTFERREN_SS			BIT15	//1b/x/x/x DEVNTF Error Check
    #define U3IPSSCFGP_R_SLFERREN_SS			BIT14	//1b/x/x/x SLF Error Check
    #define U3IPSSCFGP_R_PCFGU0EN_SS			BIT13	//1b/x/x/x Enable PCFG Timer Counting Only In U0 State
    #define U3IPSSCFGP_R_DLENDIFF_SS			BIT12	//0/x/x/x Data Length Mismatch Error
    #define U3IPSSCFGP_R_CRC32ERR_SS			BIT11	//0/x/x/x Payload CRC32 Error
    #define U3IPSSCFGP_R_CRC16ERR_SS			BIT10	//0/x/x/x Header CRC16 Error
    #define U3IPSSCFGP_R_LCWCRC5ERR_SS			BIT9	//0/x/x/x Link Control Word CRC5 Error
    #define U3IPSSCFGP_R_HSQERR_SS			BIT8	//0/x/x/x Header Sequence Number Error
    #define U3IPSSCFGP_R_SPDNHFCHK_SS			BIT7	//0/x/x/x Enable SPD Number Check 
    #define U3IPSSCFGP_R_ENSSVA_SS			BIT6	//0/x/x/x Enable SS Value Available 
    #define U3IPSSCFGP_R_SSPEQLCW_SS			BIT5	//0/x/x/x Enable Both Link Command Word Check In The Same Link Command. 
    #define U3IPSSCFGP_R_RXDP250DYNEN_SS			BIT4	//0/x/x/x Enable SSP PL RX Data Dynamic Clock 
    #define U3IPSSCFGP_R_RXHR250DYNEN_SS			BIT3	//0/x/x/x Enable SSP LN RX Header Dynamic Clock 
    #define U3IPSSCFGP_R_LNRX250DYNPMEN_SS			BIT2	//0/x/x/x Enable SSP LN RX Dynamic Clock 
    #define U3IPSSCFGP_R_LNTX250DYNPMEN_SS			BIT1	//0/x/x/x Enable SSP LN TX Dynamic Clock 
    #define U3IPSSCFGP_R_PLRX250DYNPMEN_SS			BIT0	//0/x/x/x Enable SSP PL RX Dynamic Clock 
#define U3IPSSCFGP_SSIP_PORT_LTSSM_OPTION_REGS_1		0x008	//SSIP_PORT_LTSSM_Option_Registers_1
    #define U3IPSSCFGP_R_PLNOTMO_SS			BIT15	//0/x/x/x Disable Polling-LFPS State Negotiation Timer
    #define U3IPSSCFGP_R_DETRST_SS			BIT14	//0/x/x/x Reset Link State To Rx.Detect.Reset State
    #define U3IPSSCFGP_R_SWLPSTEN_SS			BIT13	//0/x/x/x Enable Samples Woke Up LFPS Signal During Power State Transition Time
    #define U3IPSSCFGP_R_U2TXP1EN_SS			BIT12	//0/x/x/x Enable U2 State To Enter P1 State In TX
    #define U3IPSSCFGP_R_WRSTCPLEN_SS			BIT11	//1b/x/x/x Enable LTSSM Response SC_WRST_CPL In RX.Detect State When No Device Connected
    #define U3IPSSCFGP_R_POLFPSSKIP_SS			BIT10	//0/x/x/x For Test Mode, If This Register Asserted, LTSSM Will Skip Polling LFPS Negotiation In Training Link
    #define U3IPSSCFGP_R_U0KEEP_SS			BIT9	//0/x/x/x For Test Mode, If This Register Asserted, LTSSM Will Keep In U0 Until This Register De-Asserted
    #define U3IPSSCFGP_R_LPBK_MSTREN_SS			BIT8	//1b/x/x/x When Loopback Bit Asserted In TS2 Concurrent Condition Occurred, This Register Will Control LTSSM To Be Master Or Not
    #define U3IPSSCFGP_R_RDLNCTL_SS			0xF0	//0001b/x/x/x Receiver Detection Limitation Number Control
    #define U3IPSSCFGP_R_DISCPOP_SS			BIT3	//0/x/x/x Indicate Disable Core-Power Off Resumption Path From Rx.Detect To U3 Or Not
    #define U3IPSSCFGP_R_DPLCEN_SS			BIT2	//0/x/x/x Enable Double Ping LFPS Cycle To 4T Only For UFP
    #define U3IPSSCFGP_R_PLWRSTEN_SS			BIT1	//0/x/x/x Enable To Automatically Generate Warm Reset By LTSSM When None The First Time Polling-LFPS State Timeout
    #define U3IPSSCFGP_R_PORTPRTYEN_SS			BIT0	//0/x/x/x Port Register Priority Enable
#define U3IPSSCFGP_SSIP_PORT_LTSSM_OPTION_REGS_2		0x00A	//SSIP_PORT_LTSSM_Option_Registers_2
    #define U3IPSSCFGP_R_TXTS2E_SS			(BIT14 + BIT15)	//00b/x/x/x Enable TS2 Number Extension For Polling And Recovery State. 
    #define U3IPSSCFGP_R_TXTS1E_SS			(BIT12 + BIT13)	//00b/x/x/x Enable TS1 Number Extension For Polling And Recovery State.
    #define U3IPSSCFGP_R_RXHZ_DISTEST_SS			BIT11	//0/x/x/x RX HZ Disable(For Test Mode) 
    #define U3IPSSCFGP_R_DIRU0_SS			BIT10	//0/x/x/x Direct LTSSM To U0 From Any State (For Test Mode) 
    #define U3IPSSCFGP_R_UPDISEN_SS			BIT9	//1b/x/x/x XHCI Control UFP Disable State Enable
    #define U3IPSSCFGP_R_CMPSCRM_SS			BIT8	//0/x/x/x Enable Register To Control Scramble Function In Compliance Mode For Test Mode Issue
    #define U3IPSSCFGP_R_IGNTS2RST_SS			BIT7	//0/x/x/x Ignore The Constrain Of Received TS2 With Reset Bit Asserted In Hot Reset State
    #define U3IPSSCFGP_R_U0LPDBEN_SS			BIT6	//0/x/x/x Enable U0 LFPS Power Down Function
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_00A_5_SS			BIT5	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_NOLTMO_SS			BIT4	//0/x/x/x Disable LUP/LDN Detecting Timer
    #define U3IPSSCFGP_R_IA2CEN_SS			BIT3	//0/x/x/x Enable IDLE State To CFG State When Detecting Consecutive TS
    #define U3IPSSCFGP_R_CA2IEN_SS			BIT2	//1b/x/x/x Enable CFG State To IDLE State When Detecting Consecutive Logic Idle
    #define U3IPSSCFGP_R_RXPASSEN_SS			BIT1	//0/x/x/x Port Configuration Done Pass Enable
    #define U3IPSSCFGP_R_FU3CLREN_SS			BIT0	//0/x/x/x Enable Clear FU3 Flag In U3 State Function
#define U3IPSSCFGP_SSIP_PORT_LTSSM_OPTION_REGS_3		0x00C	//SSIP_PORT_LTSSM_Option_Registers_3
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_00C_SS			0xF000	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_RXTSEQCLR_SS			BIT11	//0/x/x/x Clear D_RXTSEQ_SS Value
    #define U3IPSSCFGP_R_RXLBADCLR_SS			BIT10	//0/x/x/x Clear D_RXLBAD_SS Value
    #define U3IPSSCFGP_R_RXRCVYCLR_SS			BIT9	//0/x/x/x Clear D_RXRCVY_SS Value
    #define U3IPSSCFGP_R_TXLBADCLR_SS			BIT8	//0/x/x/x Clear D_TXLBAD_SS Value
    #define U3IPSSCFGP_R_TXRCVYCLR_SS			BIT7	//0/x/x/x Clear D_TXRCVY_SS Value
    #define U3IPSSCFGP_R_RXRSTOFF_SS			BIT6	//0/x/x/x Power Off PLL And Power In Rx.Detect.Reset State
    #define U3IPSSCFGP_R_CMPLEXIT_SS			BIT5	//1b/x/x/x Exit Compliance State When Receiving 2 Polling-LFPS
    #define U3IPSSCFGP_R_PRXRSTEN_SS			BIT4	//0/x/x/x Enable RX Reset In Polling State
    #define U3IPSSCFGP_R_PTXRSTEN_SS			BIT3	//0/x/x/x Enable TX Reset In Polling State
    #define U3IPSSCFGP_R_TXSTRST_SS			BIT2	//0/x/x/x Enable PISO Short Interval Reset
    #define U3IPSSCFGP_R_PLRTYRYEN_SS			BIT1	//0/x/x/x Clear RX Polarity Control Signal
    #define U3IPSSCFGP_R_PLRTYCHGEN_SS			BIT0	//0/x/x/x Enable Detect TS Polarity Every Time When RX TS1/2
#define U3IPSSCFGP_SSIP_PORT_LTSSM_ERR_INJECTION_REGS		0x00E	//SSIP_PORT_LTSSM_Error_Injection_Registers
    #define U3IPSSCFGP_R_DPHEDBEN_SS			BIT15	//1b/x/x/x DPH With EDB Function
    #define U3IPSSCFGP_R_SHSYNCEN_SS			BIT14	//0/x/x/x Short SYNC Interval Enable
    #define U3IPSSCFGP_R_DPHLERR_SS			BIT13	//1b/x/x/x DPH Lenth Replica Field Check
    #define U3IPSSCFGP_R_TSDCBCHK_SS			BIT12	//1b/x/x/x Check DC Balance Field Of TS OS
    #define U3IPSSCFGP_R_U12EX2RE_SS			BIT11	//0/x/x/x Transition Link State From U1/U2 Exit To Recovery.Entry When No LFPS Detected
    #define U3IPSSCFGP_R_U1NOPL_SS			BIT10	//0/x/x/x UFP U1 State PING LFPS Mask
    #define U3IPSSCFGP_R_HRNOLI_SS			BIT9	//0/x/x/x Hot Reset Idle State LI Mask
    #define U3IPSSCFGP_R_HRNOTS2_SS			BIT8	//0/x/x/x Hot Reset-Active State TS2 Mask
    #define U3IPSSCFGP_R_RPNOLFPS_SS			BIT7	//0/x/x/x U1/U2/U3 Sate EXIT LFPS Mask
    #define U3IPSSCFGP_R_RCVYNOLI_SS			BIT6	//0/x/x/x Recovery-Idle Sate LI Mask
    #define U3IPSSCFGP_R_RCVYNOTS2_SS			BIT5	//0/x/x/x Recovery-Configuration State TS2 Mask
    #define U3IPSSCFGP_R_RCVYNOTS1_SS			BIT4	//0/x/x/x Recovery-Active State TS1 Mask
    #define U3IPSSCFGP_R_PONOLI_SS			BIT3	//0/x/x/x Polling -Idle Sate LI Mask
    #define U3IPSSCFGP_R_PONOTS2_SS			BIT2	//0/x/x/x Polling -Configuration State TS2 Mask
    #define U3IPSSCFGP_R_PONOTS1_SS			BIT1	//0/x/x/x Polling -Active State TS1 Mask
    #define U3IPSSCFGP_R_PONOLFPS_SS			BIT0	//0/x/x/x Polling-LFPS Sate LFPS Mask
#define U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_1		0x010	//SSIP_PORT_PHYLS_Option_Registers_1
    #define U3IPSSCFGP_R_CPMODE_EN_SS			BIT15	//0/x/x/x Register Control Compliance Pattern Enable
    #define U3IPSSCFGP_R_CMPL_SCRMBLENCTL_SS			BIT14	//1b/x/x/x Compliance Pattern 0 Scramble Enable Control
    #define U3IPSSCFGP_R_SMBLCKRTN_SS			BIT13	//0/x/x/x Symbol Lock Retain
    #define U3IPSSCFGP_R_BERCERRTLR_SS			BIT12	//1b/x/x/x BERC 1 Symbol Error Tolerate Enable
    #define U3IPSSCFGP_R_TXD_MASK_EN_SS			BIT11	//0/x/x/x Mask Data Before LFPS
    #define U3IPSSCFGP_R_LPBK_SEL_SS			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Loopback Mode Select
    #define U3IPSSCFGP_R_EQLZ_TM_SS			(BIT6 + BIT7)	//10b/x/x/x Equalization Duration Timer Mode
    #define U3IPSSCFGP_R_EARLY_U1EXITLFPS_SS			BIT5	//0/x/x/x Send U1 LFPS Do Not Wait TX P1 To P0 Waiting Time
    #define U3IPSSCFGP_R_EB_BASE_SS			0x1E	//0110b/x/x/x Elastic Buffer Base
    #define U3IPSSCFGP_R_SKPCNT_MODE_SS			BIT0	//0/x/x/x Elastic Buffer SKP Add Display Mode
#define U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_2		0x012	//SSIP_PORT_PHYLS_Option_Registers_2
    #define U3IPSSCFGP_R_EPHYTST_SS			BIT15	//0/x/x/x EPHYTST
    #define U3IPSSCFGP_R_CPCOMLEADLEN_SS			(BIT12 + BIT13 + BIT14)	//101b/x/x/x Length Of COM Symbol Lead Compliance Pattern
    #define U3IPSSCFGP_R_CP7801DUR_SS			0xF00	//0100b/x/x/x Compliance Pattern CP7/CP8 Continuous 0/1 Length
    #define U3IPSSCFGP_R_CPMODE_SS			0xF8	//00000b/x/x/x Register Control Compliance Pattern
    #define U3IPSSCFGP_R_TSPOLDET_SS			(BIT0 + BIT1 + BIT2)	//011b/x/x/x TSOS Polarity Inversion Detection Mode
#define U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_3		0x014	//SSIP_PORT_PHYLS_Option_Registers_3
    #define U3IPSSCFGP_R_DEEMPSETEN_SS			BIT15	//0/x/x/x De-Emphasis Set Enable
    #define U3IPSSCFGP_R_TXLSW_SS			BIT14	//0/x/x/x TX Low Swing Mode (Low Power Transmitter)
    #define U3IPSSCFGP_R_CLRTBEBERRCNT_SS			BIT13	//0/x/x/x Clear TBTOEB Error Counter
    #define U3IPSSCFGP_R_POLARDEGLEN_SS			BIT12	//1b/x/x/x Enable RX TSEQ Polarity Deglitch Function
    #define U3IPSSCFGP_R_CMWK_TM_SS			(BIT10 + BIT11)	//11b/x/x/x Common Mode Driver Wake Up Timer Mode
    #define U3IPSSCFGP_R_PASSRCVDET_SS			BIT9	//0/x/x/x Receiver Detection Force Pass
    #define U3IPSSCFGP_R_RXP1PHYSTATUS_SS			BIT8	//1b/x/x/x Include RXP1 EPHY Status In PHYLS_PHYSTATUS
    #define U3IPSSCFGP_R_PTNGEN_MODE_SS			0xF0	//0010b/x/x/x Pattern Generation Mode
    #define U3IPSSCFGP_R_DLYTXEIDLE_SS			BIT3	//0/x/x/x Delay To Assert TXEIDLEB When Enter Non-P0 State
    #define U3IPSSCFGP_R_DEEMPSET_SS			BIT2	//1b/x/x/x De-Emphasis Set
    #define U3IPSSCFGP_R_SKPERRCOR_SS			BIT1	//1b/x/x/x SKP Symbol Error Correction
    #define U3IPSSCFGP_R_SKPINTST_SS			BIT0	//0/x/x/x Insert SKP OS Between Pattern Enable
#define U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_4		0x016	//SSIP_PORT_PHYLS_Option_Registers_4
    #define U3IPSSCFGP_R_RXFULLTSEQCHK_SS			BIT15	//0/x/x/x RX TSEQ Fully Check Enable
    #define U3IPSSCFGP_R_TSEQRDCHK_SS			BIT14	//0/x/x/x RX TSEQ Running Disparity Check
    #define U3IPSSCFGP_R_TSEQPOLCNT_SS			(BIT12 + BIT13)	//01b/x/x/x Suspend Domain. The Deglitch Number Of RX Polarity. 
    #define U3IPSSCFGP_R_TRERRCNTCLR_SS			BIT11	//0/x/x/x TR Loopback ERRCNT Clear
    #define U3IPSSCFGP_R_LSRTLPBKECCLR_SS			BIT10	//0/x/x/x LPHY RT Loopback EC Clear
    #define U3IPSSCFGP_R_RXPWRDNSET_SS			(BIT8 + BIT9)	//10b/x/x/x LPHY RX Power Status Set
    #define U3IPSSCFGP_R_RXPWRDNSETEN_SS			BIT7	//0/x/x/x LPHY RX Power Status Set Enable
    #define U3IPSSCFGP_R_TXEIDLEBSET_SS			BIT6	//0/x/x/x TX Electrical Idle Set
    #define U3IPSSCFGP_R_TXPWRDNSET_SS			(BIT4 + BIT5)	//10b/x/x/x LPHY TX Power Status Set
    #define U3IPSSCFGP_R_TXPWRDNSETEN_SS			BIT3	//0/x/x/x LPHY TX Power Status Set Enable
    #define U3IPSSCFGP_R_EPHYTSTDYNPMEN_SS			BIT2	//0/x/x/1b EPHYTST Dynamic Power Enable
    #define U3IPSSCFGP_R_LSRTLPBKDYNPMEN_SS			BIT1	//0/x/x/1b PHYLS RT Loopback Dynamic Power Enable
    #define U3IPSSCFGP_R_CMPLNCDYNPMEN_SS			BIT0	//0/x/x/1b Compliance Pattern Dynamic Power Enable
#define U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_5		0x018	//SSIP_PORT_PHYLS_Option_Registers_5
    #define U3IPSSCFGP_R_DLRCVY_SS			BIT15	//0/x/x/x Enable Entry Recovery State When Data Length Error 
    #define U3IPSSCFGP_R_DPSFERCVY_SS			BIT14	//1b/x/x/x Enable Entry Recovery State When SDP Error
    #define U3IPSSCFGP_R_BCNTERR_SS			BIT13	//0/x/x/x Error BCNT Symbol Injection
    #define U3IPSSCFGP_R_TXPOL_SS			BIT12	//0/x/x/x TX Data Polarity Inversion
    #define U3IPSSCFGP_R_RDERR_SS			BIT11	//0/x/x/x Error Disparity Symbol Injection
    #define U3IPSSCFGP_R_EBTBERR_SS			BIT10	//0/x/x/x Invalid 8b/10b Symbol Injection
    #define U3IPSSCFGP_R_ERRINTVL_SS			(BIT8 + BIT9)	//00b/x/x/x Error Symbol Injection Interval
    #define U3IPSSCFGP_R_TS132FN_SS			BIT7	//0/x/x/x Enable Finish TS1 Pre 32 Transmitted
    #define U3IPSSCFGP_R_HRFWINT_SS			BIT6	//0/x/x/x FW Initial Hot Reset Finish
    #define U3IPSSCFGP_R_HRFWEN_SS			BIT5	//0/x/x/x Enable FW Control Hot Reset Finish
    #define U3IPSSCFGP_R_HRKPEN_SS			BIT4	//0/x/x/x Enable Hot Reset Keep Function
    #define U3IPSSCFGP_R_WALIGN_TSEQCOMARE_SS			BIT3	//0/x/x/x WALIGN Always Detect TSEQ Symbol
    #define U3IPSSCFGP_R_LPHYACONVDYNPMEN_SS			BIT2	//0/x/x/1b Reserved
    #define U3IPSSCFGP_R_LPHYWALIGNDYNPMEN_SS			BIT1	//0/x/x/1b Reserved
    #define U3IPSSCFGP_R_TSEQPOLDETALON_SS			BIT0	//0/x/x/x Always Turn On TSEQ Polarity Detection
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_1		0x01A	//SSIP_PORT_PHYLS_Pattern_Generation_Register_1
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_01A_SS			0xF800	//0/x/x/x Reserved
    #define U3IPSSCFGP_EPHYBISTER_CLRAR_EACH_PAT_SS			BIT10	//0/x/x/x EPHYBISTER CLRAR EACH PATTERN
    #define U3IPSSCFGP_EPHYBISTER_NOCOMP_FIRST_SS			BIT9	//0/x/x/x EPHYBISTER NO COM PATTERN FIRST
    #define U3IPSSCFGP_EPHYBISTER_CLRAR_SS			BIT8	//0/x/x/x EPHYBISTER CLRAR
    #define U3IPSSCFGP_R_PTNLEN_SS			0xFF	//10h/x/x/x Pattern Length
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_2		0x01C	//SSIP_PORT_PHYLS_Pattern_Generation_Register_2
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_01C_SS			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_3		0x01E	//SSIP_PORT_PHYLS_Pattern_Generation_Register_3
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_01E_SS			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS		0x020	//SSIP_PORT_PMULINK_Option_Registers
    #define U3IPSSCFGP_R_BADEDBEN_SS			BIT15	//0/x/x/x Enable TX Bad EDB
    #define U3IPSSCFGP_R_CDROFF_SS			BIT14	//0/x/x/x Trun Off CDR When Link Partner Triggered Retrain
    #define U3IPSSCFGP_R_LCWCRCCHK_SS			BIT13	//1b/x/x/x Link Command Word CRC5 Checking Control
    #define U3IPSSCFGP_R_CRC32CHK_SS			BIT12	//1b/x/x/x Data Payload CRC32 Checking Control
    #define U3IPSSCFGP_R_CRC5CHK_SS			BIT11	//1b/x/x/x Header CRC5 Checking Control
    #define U3IPSSCFGP_R_CRC16CHK_SS			BIT10	//1b/x/x/x Header CRC16 Checking Control
    #define U3IPSSCFGP_R_HSQNCHK_SS			BIT9	//1b/x/x/x Header Sequence Number Control
    #define U3IPSSCFGP_R_WAIT2SKP_SS			BIT8	//1b/x/x/x Wait 2 SKP OS Being Scheduled, Only Effective In Training State
    #define U3IPSSCFGP_R_RCVPOFF_SS			BIT7	//0/x/x/x Enable Power Off In Detection State
    #define U3IPSSCFGP_R_DFTU2TMOEN_SS			BIT6	//1b/x/x/x Enable DFP U2 Inactive Timer In U0 State
    #define U3IPSSCFGP_R_DEVU2TMOFF_SS			BIT5	//1b/x/x/x U2 Inactive Timer For UFP
    #define U3IPSSCFGP_R_DEVU1TMOFF_SS			BIT4	//1b/x/x/x U1 Inactive Timer For UFP
    #define U3IPSSCFGP_R_U12ITE_SS			BIT3	//0/x/x/x Enable The U1/2 Inactive Timer Extending When Receiving LXU
    #define U3IPSSCFGP_R_U2LKPMEN_SS			BIT2	//1b/x/x/x U2 Link PM Enable 
    #define U3IPSSCFGP_R_U1LKPMEN_SS			BIT1	//1b/x/x/x U1 Link PM Enable 
    #define U3IPSSCFGP_R_FU3LAU_SS			BIT0	//0/x/x/x Force SS_PMU Responses LAU When Receiving LGO_U3 Not Matter If The TXISIDLE Is High Or Not. 
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1		0x022	//SSIP_PORT_LINK_Option_Registers_1
    #define U3IPSSCFGP_R_EIRTN_SS			BIT15	//1b/x/x/x Electrical Idle Triggered Retrain
    #define U3IPSSCFGP_R_TXMAXLC_SS			(BIT13 + BIT14)	//11b/x/x/x TX Max Consecutive Link Command Numbers
    #define U3IPSSCFGP_R_REPISOEN_SS			BIT12	//1b/x/x/x Enable PISO Reset When Entry Recovery -Entry From U0
    #define U3IPSSCFGP_R_U3PLEN_SS			BIT11	//0/x/x/x Enable Polling-LFPS Detection In U3 State. 
    #define U3IPSSCFGP_R_UPCTLU3P1_SS			BIT10	//0/x/x/x Enable UFP Control DFP U3-TXP1. 
    #define U3IPSSCFGP_R_FWDISEN_SS			BIT9	//0/x/x/x FW Control  Port Disable Generate
    #define U3IPSSCFGP_R_FWRSTEN_SS			BIT8	//0/x/x/x FW Control Warm Reset Generate
    #define U3IPSSCFGP_R_LCQPRI_SS			(BIT6 + BIT7)	//00b/x/x/x TX Link Command Priority
    #define U3IPSSCFGP_R_SKPFREQ_SS			(BIT4 + BIT5)	//01b/x/x/x Schedule SKP Ordered Set Frequency
    #define U3IPSSCFGP_R_LCIGNORE_SS			BIT3	//0/x/x/x Ignore Link Command When Any K-Symbol Appears In LCW
    #define U3IPSSCFGP_R_HRTYMAXT_SS			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Header Retry Max. Times.
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_2		0x024	//SSIP_PORT_LINK_Option_Registers_2
    #define U3IPSSCFGP_R_LKUCLREN_SS			BIT15	//1b/x/x/x Enable Link Up Down Reset AP_FORCEUx
    #define U3IPSSCFGP_R_HRSTCLREN_SS			BIT14	//1b/x/x/x Enable Hot-Reset Clear AP_FORCEUx
    #define U3IPSSCFGP_R_HRSTLKUEN_SS			BIT13	//1b/x/x/x Enable Hot-Reset Reset Link-Up
    #define U3IPSSCFGP_R_REPTEN_SS			(BIT11 + BIT12)	//00b/x/x/x Select Pattern Type Generated In Recovery Entry State. Only For Resuming From Power Saving State.
    #define U3IPSSCFGP_R_INSKINHP_SS			BIT10	//0/x/x/x Insert K-Symbol Into HP
    #define U3IPSSCFGP_R_NOU3RCV_SS			BIT9	//0/x/x/x Disable Entry U3_RCVDET State When LFPS Handshake Timeout In U3
    #define U3IPSSCFGP_R_BDATERR_SS			BIT8	//0/x/x/x BDAT OS Error
    #define U3IPSSCFGP_R_LDNON_SS			BIT7	//1b/x/x/x Enable TX To Transmit LDN
    #define U3IPSSCFGP_R_LRTYLINUM_SS			(BIT5 + BIT6)	//00b/x/x/x Reserved
    #define U3IPSSCFGP_R_DPTOHPS_SS			(BIT2 + BIT3 + BIT4)	//000b/x/x/x Data Payload To Next Header Packet Spacing Interval
    #define U3IPSSCFGP_R_HPTOHPS_SS			(BIT0 + BIT1)	//00b/x/x/x Header Packet To Next Header Packet Spacing Interval
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_3		0x026	//SSIP_PORT_LINK_Option_Registers_3
    #define U3IPSSCFGP_R_TMVMAXEN_SS			BIT15	//0/x/x/x Enable SSLINK Layer Timer Value Max. 
    #define U3IPSSCFGP_R_HRSTCPLEN_SS			BIT14	//1b/x/x/x Enable LTSSM Response SC_HRST_CPL In RX.Detect State When No Device Connected. 
    #define U3IPSSCFGP_R_DNTCHKLF_SS			BIT13	//0/x/x/x Disable LTSSM Check Link Function Bit Reserved. 
    #define U3IPSSCFGP_R_EQLCW_SS			BIT12	//1b/x/x/x Enable Both Link Command Word Check In The Same Link Command. 
    #define U3IPSSCFGP_R_DPSKPLEN_SS			BIT11	//1b/x/x/x Adding SKP Order Set When DPP Length Is Larger Than This Definition
    #define U3IPSSCFGP_R_DPSKPNUM_SS			(BIT9 + BIT10)	//00b/x/x/x If Enable Adding SKP Before DPH Function, These Registers Will Control The Number Of SKP Order Set. 
    #define U3IPSSCFGP_R_DPSKPEN_SS			BIT8	//0/x/x/x Enable Adding SKP Order Set Before Transmitting DPH. 
    #define U3IPSSCFGP_R_FULLLBADEN_SS			BIT7	//0/x/x/x Enable RUTC Patch When Queue Full To Assert R_LBADEN
    #define U3IPSSCFGP_R_P2TP3EN_SS			BIT6	//1b/x/x/x Enable LTSSM Power Down Signal To P3 When In P2. 
    #define U3IPSSCFGP_R_SILIMEN_SS			BIT5	//0/x/x/x Enable RCVDET Counter In SS.Inactive State
    #define U3IPSSCFGP_R_PLEIMAX_SS			BIT4	//0/x/x/x Enable Polling-LFPS E-Idle Max Margin. 
    #define U3IPSSCFGP_R_UXTOFLEN_SS			(BIT2 + BIT3)	//00b/x/x/x Enable U1 TPLL Latency Time. 
    #define U3IPSSCFGP_R_INSKINDPP_SS			BIT1	//0/x/x/x Insert K-Symbol Into DPP
    #define U3IPSSCFGP_R_EXCDHP_SS			BIT0	//0/x/x/x Transmit Exceed Header Packet
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_4		0x028	//SSIP_PORT_LINK_Option_Registers_4
    #define U3IPSSCFGP_R_RPISORTEN_SS			BIT15	//0/x/x/x Enable Automatic Reset PISO In P0 When Staying In Recovery A Long Time. 
    #define U3IPSSCFGP_R_RACDRP2EN_SS			BIT14	//0/x/x/x Enable CDR Re-Start To P2 In Recovery-Active State
    #define U3IPSSCFGP_R_PLRTYNUM_SS			(BIT12 + BIT13)	//00b/x/x/x Select Decision Number Of Polarity. 
    #define U3IPSSCFGP_R_PLRTYCLR_SS			BIT11	//0/x/x/x Clear RX TS Polarity Control Signal.
    #define U3IPSSCFGP_R_TS1LFEN_SS			BIT10	//0/x/x/x Link Function Filed In TS1
    #define U3IPSSCFGP_R_U2INADIS_SS			BIT9	//0/x/x/x Enable U1 Exit 900ns Timeout When U2 Inactivity Timer Disabled. 
    #define U3IPSSCFGP_R_LFPS80EXT_SS			BIT8	//0/x/x/x Enable 80us LFPS To 131us. 
    #define U3IPSSCFGP_R_ACWTS2EN_SS			BIT7	//0/x/x/x Enable Wait For TS2 In Polling/Recovery-Active 
    #define U3IPSSCFGP_R_PGUXSEN_SS			BIT6	//1b/x/x/x Enable UX State Mask SSPGAR Read Strobe. 
    #define U3IPSSCFGP_R_LAUDEFEREN_SS			BIT5	//0/x/x/x Enable PMU_PORT_DEFER Asserted After Receiving LAU.
    #define U3IPSSCFGP_R_SYNCOSDETOPT_SS			BIT4	//0/x/x/x SYNC OS Error Detect Mode
    #define U3IPSSCFGP_R_RACDRTEN_SS			BIT3	//0/x/x/x Enable CDR Retrain In Recovery-Active. 
    #define U3IPSSCFGP_R_SKPTS2LI_SS			BIT2	//0/x/x/x Enable SKP Order Set Not Generated Between TS2 And LI
    #define U3IPSSCFGP_R_REP1LKSEN_SS			BIT1	//1b/x/x/x Enable Recovery-Entry P1 Link State. 
    #define U3IPSSCFGP_R_U0SKPDLY_SS			BIT0	//0/x/x/x Enable Delay SKP Order Set When Entry U0. 
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_5		0x02A	//SSIP_PORT_LINK_Option_Registers_5
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_02A_SS			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_IPIHRST_SS			BIT14	//1b/x/x/x Enable IP Type Inverter Reset When In Hot Reset State
    #define U3IPSSCFGP_R_PODYNTPLLEN_SS			BIT13	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_PO1STEXT_SS			BIT12	//0/x/x/x Extend Polling-LFPS Number Sent After Receiving 1st Polling-LFPS
    #define U3IPSSCFGP_R_PISORST_SS			BIT11	//0/x/x/x Enable Firmware Reset PISO In P0
    #define U3IPSSCFGP_R_ATSIPEN_SS			BIT10	//1b/x/x/x Enable Automatic Switch IP Type. 
    #define U3IPSSCFGP_R_LFPS2TRST_SS			BIT9	//0/x/x/x Reset LFPS Counter Without 2T LFPS. 
    #define U3IPSSCFGP_R_U3TXP1EN_SS			BIT8	//0/x/x/x Enable TX-P1 In U3 State. 
    #define U3IPSSCFGP_R_BRKDPP_EDB_LBAD_SS			BIT7	//1b/x/x/x Insert EDB When Breaking DPP Due To LBAD Received.
    #define U3IPSSCFGP_R_BRKDPP_EDB_RTN_SS			BIT6	//1b/x/x/x Insert EDB When Breaking DPP Due To Link Retrain
    #define U3IPSSCFGP_R_BRKDPP_SS			(BIT4 + BIT5)	//10b/x/x/x Break DPP Mode
    #define U3IPSSCFGP_R_U2RXP1EN_SS			BIT3	//0/x/x/x Enable RX P2 In U2 State
    #define U3IPSSCFGP_R_U2RCVP0EN_SS			BIT2	//0/x/x/x Enable TX P0 In U2_RCVDET State
    #define U3IPSSCFGP_R_BRKDPP_LBAD_SS			BIT1	//0/x/x/x Break DPP That Is Transmitting When Receive LBAD
    #define U3IPSSCFGP_R_BRKDPP_LRTN_SS			BIT0	//0/x/x/x Break DPP That Is Transmitting When Self Retrain
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_6		0x02C	//SSIP_PORT_LINK_Option_Registers_6
    #define U3IPSSCFGP_R_DATACHG_SS			(BIT14 + BIT15)	//0/x/x/x Change The Last Data From SSPGAR
    #define U3IPSSCFGP_R_HBEDBEND_SS			BIT13	//0/x/x/x Truncate DP Payload With END Framing When Upper Layer Uses HB_DPPEDB
    #define U3IPSSCFGP_R_LIEXTEN_SS			BIT12	//0/x/x/x Extend Transmitted Logic Idle In LI State
    #define U3IPSSCFGP_R_VPCHKL_SS			BIT11	//0/x/x/x Enable VLI Product Check In LDN/LUP
    #define U3IPSSCFGP_R_VPCHKT_SS			BIT10	//0/x/x/x Enable VLI Product Check In TieBreaker.
    #define U3IPSSCFGP_R_LDTMO2SI_SS			BIT9	//0/x/x/x Enable LTSSM To SS.Inactive State When LCRD Timeout
    #define U3IPSSCFGP_R_HNORLI_SS			BIT8	//0/x/x/x Mask Logic Idle In Hot Reset-Exit State
    #define U3IPSSCFGP_R_HNORTS2_SS			BIT7	//0/x/x/x Mask TS2 In Hot Reset-Active State
    #define U3IPSSCFGP_R_RNORLI_SS			BIT6	//0/x/x/x Mask Logic Idle In Recovery State
    #define U3IPSSCFGP_R_RNORTS2_SS			BIT5	//0/x/x/x Mask TS2 In Recovery State
    #define U3IPSSCFGP_R_RNORTS1_SS			BIT4	//0/x/x/x Mask TS1 In Recovery State
    #define U3IPSSCFGP_R_PNORLI_SS			BIT3	//0/x/x/x Mask Logic Idle In Polling State
    #define U3IPSSCFGP_R_PNORTS2_SS			BIT2	//0/x/x/x Mask TS2 In Polling State
    #define U3IPSSCFGP_R_PNORTS1_SS			BIT1	//0/x/x/x Mask TS1 In Polling State
    #define U3IPSSCFGP_R_TMVEXTEN_SS			BIT0	//1b/x/x/x Extend Link Layer Protocol Timer
#define U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_7		0x02E	//SSIP_PORT_LINK_Option_Registers_7
    #define U3IPSSCFGP_R_NOLRTY_SS			BIT15	//0/x/x/x No LRTY
    #define U3IPSSCFGP_R_NOLPMA_SS			BIT14	//0/x/x/x No LPMA
    #define U3IPSSCFGP_R_NOLAXU_SS			BIT13	//0/x/x/x No LAU/LXU
    #define U3IPSSCFGP_R_NOLCRD_SS			BIT12	//0/x/x/x No LCRD_x
    #define U3IPSSCFGP_R_NOLGOOD_SS			BIT11	//0/x/x/x No LGOOD_n And LBAD
    #define U3IPSSCFGP_R_LBADEN_SS			BIT10	//0/x/x/x LBAD Enable
    #define U3IPSSCFGP_R_LCMD2CRC5ERR_SS			BIT9	//0/x/x/x Link Command Word 2 CRC5 Error
    #define U3IPSSCFGP_R_LCMD1CRC5ERR_SS			BIT8	//0/x/x/x Link Command Word 1 CRC5 Error
    #define U3IPSSCFGP_R_RECEDB_SS			BIT7	//1b/x/x/x Enable DP With EDB When Entry Recovery State
    #define U3IPSSCFGP_R_RETCDP_SS			BIT6	//0/x/x/x Enable DP Truncated When Entry Recovery State
    #define U3IPSSCFGP_R_BLKTSCHK_SS			BIT5	//0/x/x/x Enable Block Header Check For TS OS
    #define U3IPSSCFGP_R_MASKIDLE_SS			BIT4	//1b/x/x/x Mask APISIDLE In Ux Power State
    #define U3IPSSCFGP_R_CMPCTLEN_SS			BIT3	//1b/x/x/x Enable CTE Compliance Control Function
    #define U3IPSSCFGP_R_UFPU1DET_SS			BIT2	//0/x/x/x Enable UFP Detection In U1
    #define U3IPSSCFGP_R_LCRDSTMO_SS			BIT1	//0/x/x/x Shorten The LCRD Timeout Value To 5u
    #define U3IPSSCFGP_R_FORCEMUX_SS			BIT0	//0/x/x/x Mask FORCE U1/2
#define U3IPSSCFGP_SSIP_PORT_LINK_ERR_INJECTION_REGS_1		0x030	//SSIP_PORT_LINK_Error_Injection_Registers_1
    #define U3IPSSCFGP_R_TS2ERR_SS			BIT15	//0/x/x/x TS2 OS Error
    #define U3IPSSCFGP_R_TS1ERR_SS			BIT14	//0/x/x/x TS1 OS Error
    #define U3IPSSCFGP_R_CRDADVERR_SS			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Rx Header Buffer Credit Advertisement Error
    #define U3IPSSCFGP_R_SQNADVERR_SS			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Header Sequence Number Advertisement Error
    #define U3IPSSCFGP_R_BERCERR_SS			BIT7	//0/x/x/x BERC OS Error
    #define U3IPSSCFGP_R_BRSTERR_SS			BIT6	//0/x/x/x BRST OS Error
    #define U3IPSSCFGP_R_SKPERR_SS			BIT5	//0/x/x/x SKP OS Error
    #define U3IPSSCFGP_R_LCRDERR_SS			BIT4	//0/x/x/x LCRD_x Error
    #define U3IPSSCFGP_R_LGOODERR_SS			BIT3	//0/x/x/x LGOOD_n Error
    #define U3IPSSCFGP_R_NOCRDADV_SS			BIT2	//0/x/x/x No Rx Header Buffer Credit Advertisement
    #define U3IPSSCFGP_R_NOSQNADV_SS			BIT1	//0/x/x/x No Header Sequence Number Advertisement
    #define U3IPSSCFGP_R_NOLUP_SS			BIT0	//0/x/x/x No LUP
#define U3IPSSCFGP_SSIP_PORT_LINK_ERR_INJECTION_REGS_2		0x032	//SSIP_PORT_LINK_Error_Injection_Registers_2
    #define U3IPSSCFGP_R_SLCFRMERR_SS			0xF000	//0000b/x/x/x SLC Framing Error
    #define U3IPSSCFGP_R_ENDFRMERR_SS			0xF00	//0000b/x/x/x END Framing Error
    #define U3IPSSCFGP_R_SDPFRMERR_SS			0xF0	//0000b/x/x/x SDP Framing Error
    #define U3IPSSCFGP_R_SHPFRMERR_SS			0xF	//0000b/x/x/x SHP Framing Error
#define U3IPSSCFGP_SSIP_PORT_COMPLIANCELFPS_PRBS_OPTION_REG		0x034	//SSIP_PORT_ComplianceLFPS_PRBS_Option_Register
    #define U3IPSSCFGP_R_SDS2IEN_SS			BIT15	//0/x/x/x Enable Transition State When Receiving SDS
    #define U3IPSSCFGP_R_NO20PL_SS			BIT14	//0/x/x/x No 20 PL Transmitted
    #define U3IPSSCFGP_R_PLES16DIS_SS			BIT13	//0/x/x/x Polling.LFPS E-Ilde Enable 16-PL Received
    #define U3IPSSCFGP_R_PHYCNTEXT_SS			BIT12	//0/x/x/x PHY Counter Extend
    #define U3IPSSCFGP_R_LDILFSRV_SS			BIT11	//0/x/x/x Enable To Load LFSR Initial Value.
    #define U3IPSSCFGP_R_PRBSRST_SS			BIT10	//0/x/x/x Reset LFSR Value In PRBS
    #define U3IPSSCFGP_R_PRBSEN_SS			BIT9	//0/x/x/x Enable PRBS Function
    #define U3IPSSCFGP_R_PRBS931_SS			BIT8	//0/x/x/x Select PRBS9 Or PRBS31 Function
    #define U3IPSSCFGP_R_RXEBUFADJOPT_SS			BIT7	//1b/x/x/x RX EBUF Adjust Mode
    #define U3IPSSCFGP_R_NOMAXCMPINLFPS_SS			BIT6	//1b/x/x/x No High Bound Limit For Ping LFPS In Compliance Mode
    #define U3IPSSCFGP_R_CMPLFPS_H_SS			(BIT3 + BIT4 + BIT5)	//010b/x/x/x The Ping LFPS Period High Bound In Compliance Mode
    #define U3IPSSCFGP_R_CMPLFPS_L_SS			(BIT0 + BIT1 + BIT2)	//010b/x/x/x The Ping LFPS Period Low Bound In Compliance Mode
#define U3IPSSCFGP_SSIP_PORT_PRBS_OPTION_REGS_1		0x036	//SSIP_PORT_PRBS_Option_Registers_1
    #define U3IPSSCFGP_R_ILFSRV_15_0_SS			0xFFFF	//0/x/x/x Initial LFSR Value
#define U3IPSSCFGP_SSIP_PORT_PRBS_OPTION_REGS_2		0x038	//SSIP_PORT_PRBS_Option_Registers_2
    #define U3IPSSCFGP_R_DPTPHDL_SS			BIT15	//0/x/x/x Discard TP When Receiving A DP With TPH And Without Deferred
    #define U3IPSSCFGP_R_ILFSRV_30_16_SS			0x7FFF	//0/x/x/x Initial LFSR Value.
#define U3IPSSCFGP_SSIP_PORT_LPBK_ERR_CNTER_REGS		0x03A	//SSIP_PORT_LPBK_Error_Counter_Registers
    #define U3IPSSCFGP_D_LPBSLV_LCEC_SS			0xFF00	//HwInit/x/x/x LPBK Slave Error Counter
    #define U3IPSSCFGP_D_LPBMST_RMEC_SS			0xFF	//HwInit/x/x/x LPBK Master Remote Error Counter
#define U3IPSSCFGP_SSIP_PORT_EPHYTST_ERR_CNTER_REGS		0x03C	//SSIP_PORT_EPHYTST_Error_Counter_Registers
    #define U3IPSSCFGP_D_EPHYTST_ERRCNT_SS			0xFFFF	//HwInit/x/x/x Display The Data Mismatch Count Number When Do EPHYBIST
#define U3IPSSCFGP_SSIP_PORT_LPBKMST_LOCAL_ERR_CNTER_REGS		0x03E	//SSIP_PORT_LPBKMST_Local_Error_Counter_Registers
    #define U3IPSSCFGP_D_LPBMST_LCEC_SS			0xFFFF	//HwInit/x/x/x LPBK Master Local Error Counter
#define U3IPSSCFGP_SSIP_PORT_TX_RECOVERY_CNTER_REGS		0x040	//SSIP_PORT_TX_Recovery_Counter_Registers
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_040_SS			BIT15	//HwInit/x/x/x Reserved
    #define U3IPSSCFGP_D_TXRCVY_SS			0x7FFF	//HwInit/x/x/x The Number LTSSM Go To Recovery
#define U3IPSSCFGP_SSIP_PORT_TX_LBAD_CNTER_REGS		0x042	//SSIP_PORT_TX_LBAD_Counter_Registers
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_042_SS			BIT15	//HwInit/x/x/x Reserved
    #define U3IPSSCFGP_D_TXLBAD_SS			0x7FFF	//HwInit/x/x/x TX LBAD Counter
#define U3IPSSCFGP_SSIP_PORT_RX_RECOVERY_CNTER_REGS		0x044	//SSIP_PORT_RX_Recovery_Counter_Registers
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_044_SS			BIT15	//HwInit/x/x/x Reserved
    #define U3IPSSCFGP_D_RXRCVY_SS			0x7FFF	//HwInit/x/x/x The Number That Link Partner Go To Recovery
#define U3IPSSCFGP_SSIP_PORT_RX_LBAD_CNTER_REGS		0x046	//SSIP_PORT_RX_LBAD_Counter_Registers
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_046_SS			BIT15	//HwInit/x/x/x Reserved
    #define U3IPSSCFGP_D_RXLBAD_SS			0x7FFF	//HwInit/x/x/x RX LBAD Counter
#define U3IPSSCFGP_SSIP_PORT_RX_TSEQ_CNTER_REGS		0x048	//SSIP_PORT_RX_TSEQ_Counter_Registers
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_048_SS			BIT15	//HwInit/x/x/x Reserved
    #define U3IPSSCFGP_D_RXTSEQ_SS			0x7FFF	//HwInit/x/x/x RX 5G TSEQ Counter
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_1_VT3515A0		0x04A	//SSIP_PORT_NEW_Register_1 ((VT3515A0))
    #define U3IPSSCFGP_R_PHYSCHK_SS			BIT15	//0/x/x/x PHY Single Check
    #define U3IPSSCFGP_R_SCDSCHK_SS			BIT14	//0/x/x/x SCD Single Check
    #define U3IPSSCFGP_R_TRPLEXT_SS			BIT13	//0/x/x/x T-Repeat Low Extend
    #define U3IPSSCFGP_R_TRPHEXT_SS			BIT12	//0/x/x/x T-Repeat High Extend
    #define U3IPSSCFGP_R_NO1P85USHB_SS			BIT11	//0/x/x/x No 1.85us High Boundary
    #define U3IPSSCFGP_R_NO2P2USHB_SS			BIT10	//0/x/x/x No 2.2us High Boundary
    #define U3IPSSCFGP_R_NO2USLB_SS			BIT9	//0/x/x/x No 2us Low Boundary
    #define U3IPSSCFGP_R_NO14USHB_SS			BIT8	//0/x/x/x No 14us Hogh Boundary
    #define U3IPSSCFGP_R_NO1USHB_SS			BIT7	//0/x/x/x No 1us High Boundary
    #define U3IPSSCFGP_R_DCSRATE_SS			BIT6	//0/x/x/x Decrease The Link Speed To 5G
    #define U3IPSSCFGP_R_PLOLDSET_SS			BIT5	//0/x/x/x Polling.LFPS Switch To Old Setting
    #define U3IPSSCFGP_R_PHYCRSHT_SS			BIT4	//0/x/x/x PHY Capability Short
    #define U3IPSSCFGP_R_PHYCREXT_SS			BIT3	//0/x/x/x PHY Capability Extend
    #define U3IPSSCFGP_R_SCDL1SHT_SS			BIT2	//1b/x/x/x SCD L1 Short
    #define U3IPSSCFGP_R_SCDL0EXT_SS			BIT1	//1b/x/x/x SCD L0 Extend 
    #define U3IPSSCFGP_R_PLTMOEN_SS			BIT0	//1b/x/x/x Polling State Timeout Counter
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_2_VT3515A0		0x04C	//SSIP_PORT_NEW_Register_2 (VT3515A0)
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_04C_SS			0xF800	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_DEEMPH_FW_SS			BIT10	//0/x/x/x FW Set DEEMPH
    #define U3IPSSCFGP_R_PRESHOOT_FW_SS			BIT9	//0/x/x/x FW Set PRESHOOT
    #define U3IPSSCFGP_R_CP13TOCP16_FWSET_EN_SS			BIT8	//0/x/x/x FW Set CP13 
    #define U3IPSSCFGP_R_EB_BASE_10G_SS			0xF0	//1000b/x/x/x Elastic Buffer Base of 10G
    #define U3IPSSCFGP_R_GDPHLERR_SS			BIT3	//1b/x/x/x Increase Soft Error Counter When Good DPH With Length Replica Error
    #define U3IPSSCFGP_R_SSPTS2SKP_SS			BIT2	//0/x/x/x Wait to Generate 2 SKP When TS OS in SSP Mode
    #define U3IPSSCFGP_R_BHERR_SS			BIT1	//1b/x/x/x Enable Link Retrained When Uncorrectable Block Header Detected
    #define U3IPSSCFGP_R_DISISKP_SS			BIT0	//0/x/x/x Disable Inserting SKP OS
#define U3IPSSCFGP_SSIP_PORT_SOFTERRCNTER_REG		0x04E	//SSIP_PORT_SoftErrorCounter_Register
    #define U3IPSSCFGP_D_SSP_SFERRCNT_SS			0xFFFF	//HwInit/x/x/x Soft Error Counter Value
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_3_VT3515A0		0x050	//SSIP_PORT_NEW_Register_3 ((VT3515A0))
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_050_SS			0xFF80	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_DWPCLR_SS			BIT6	//0/x/x/x Device Mode Warm Reset Without PCFG
    #define U3IPSSCFGP_R_HDRLOC_SS			BIT5	//0/x/x/x Reserved In VT3515 C0
    #define U3IPSSCFGP_R_SYNC_SKP_PATCH_DIS_SS			BIT4	//0/x/x/x Enable SYNC And SKP Patch
    #define U3IPSSCFGP_R_SSPLPBK_SS			BIT3	//0/x/x/x SSP Loopback Mode Enable
    #define U3IPSSCFGP_R_TSOSDETOPT_SS			BIT2	//0/x/x/x Detect Header Block In TS OS
    #define U3IPSSCFGP_R_CMPHDRC_SS			BIT1	//1b/x/x/x Reserved
    #define U3IPSSCFGP_R_CPCOMLEAD_SS			BIT0	//0/x/x/x COM Symbol Lead Compliance Pattern Enable
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_4_VT3515B0		0x052	//SSIP_PORT_NEW_Register_4 ((VT3515B0))
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_052_SS			0xFF80	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_MSDPRDY_SS			BIT6	//0/x/x/x Mask RX DP Ready
    #define U3IPSSCFGP_R_STOP_ADD_IF_NO_VLD_SS			BIT5	//0/x/x/x Stop Adding Pointer When There Is No Valid Signal In RXEBUF
    #define U3IPSSCFGP_R_R2TLPBK_ECEN_SS			BIT4	//0/x/x/x LPHY R2T Loopback
    #define U3IPSSCFGP_R_EQTNEN_SS			BIT3	//0/x/x/x Option Register For LPU_EQTNEN
    #define U3IPSSCFGP_R_EQTNRST_SS			BIT2	//1b/x/x/x Option Register For LPU_EQTNRST
    #define U3IPSSCFGP_R_NOCPLSCD_SS			BIT1	//0/x/x/x Transition State Without Complete SCD
    #define U3IPSSCFGP_R_EQTNSETEN_SS			BIT0	//0/x/x/x Option To Manual Control LPU_EQTNRSTB And LPU_EQTNEN
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_5_VT3515C0		0x054	//SSIP_PORT_NEW_Register_5 ((VT3515C0))
    #define U3IPSSCFGP_R_RXDBGSEL_SS			0xF000	//0/x/x/x RXBUF RXD Debug Signal Selection
    #define U3IPSSCFGP_R_USB3TXINV_SS			BIT11	//0/x/x/x Invert TXD To EPHY
    #define U3IPSSCFGP_R_RXDLFPSDET_SS			BIT10	//0/x/x/x Disable RX LFPS During Suspend
    #define U3IPSSCFGP_R_SSPEN_SS			BIT9	//0/x/x/x SSP Mode Enable Control By SSCFG
    #define U3IPSSCFGP_R_CDRNVLDR_SS			BIT8	//0/x/x/x Enable CDR Reset When Receive No Valid LI, TS1, TS2 In Polling Or Recovery State
    #define U3IPSSCFGP_R_CDRINTVR_SS			BIT7	//0/x/x/x Enable CDR Reset When Receive LFPS In Polling Or Recovery State
    #define U3IPSSCFGP_R_DSPRGEN_SS			BIT6	//0/x/x/x DFP MCU Directly Warm Reset Enable. Enable R_DSPORT_WRST Function
    #define U3IPSSCFGP_R_LOCALLPBK_SS			BIT5	//0/x/x/x For USB3 Re-Timer, Host Does Not Need This Function. Detail Information Describe In USB3 SPEC Link Function Part
    #define U3IPSSCFGP_R_PTMDL_SS			BIT4	//0/x/x/x PTM Delay Bit Mask When Manual Mode
    #define U3IPSSCFGP_R_PTMRSP_SS			BIT3	//0/x/x/x Enable Manual Mode PTM Response
    #define U3IPSSCFGP_R_PMRSTSW_SS			BIT2	//0/x/x/x Fix U1/U2 Timer Reset Bug, Reset U1/U2 Timer When PL Pop DP Or TP (Without ITP)
    #define U3IPSSCFGP_R_LDMREQ_SS			BIT1	//0/x/x/x LDM Manual Mode Send Request
    #define U3IPSSCFGP_R_LDMEN_SS			BIT0	//0/x/x/x LDM Manual Mode Function Enable In SSPIP
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_6_VT3515C0		0x056	//SSIP_PORT_NEW_Register_6 ((VT3515C0))
    #define U3IPSSCFGP_R_U2TMRV_SS			0xFF00	//01h/x/x/x U2 State 256us Timer Value
    #define U3IPSSCFGP_R_U1TMRV_SS			0xFF	//7Ch/x/x/x U1 State 1us Timer Value
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_7_VT3515C0		0x058	//SSIP_PORT_NEW_Register_7 ((VT3515C0))
    #define U3IPSSCFGP_R_WLGN_TSDET_EN_SS			BIT15	//0/x/x/x Enable TS1/TS2 Detection In WALIGN.
    #define U3IPSSCFGP_R_RXP0ENTRYTMR_SS			0x7800	//0100b/x/x/x Wait For A Period Of Time After Entry Of RXP0. By EPHY Spec, Data Is Not Valid During This Period Of Time. 
    #define U3IPSSCFGP_R_LPBKSIEXT_SS			BIT10	//0/x/x/x The Interval Of Inserting SYNC In SSP LPBK Mode
    #define U3IPSSCFGP_R_LPBKCNTCLR_SS			BIT9	//0/x/x/x Clear Error Counter Of SSP LPBK
    #define U3IPSSCFGP_R_LPBKCNTRO_SS			BIT8	//0/x/x/x Enable Roll Over Of LPBK Counter
    #define U3IPSSCFGP_R_LPBKCNTEN_SS			BIT7	//0/x/x/x Enable Error Counter Increased When No Pop
    #define U3IPSSCFGP_R_LKREBFERR_SS			BIT6	//0/x/x/x Retrain Link When RXEBUF Error Occurred
    #define U3IPSSCFGP_R_LPBKSYNC_SS			BIT5	//0/x/x/x Insert SYNC OS In SSP LPBK Mode
    #define U3IPSSCFGP_R_SSPBRKDPP_SS			(BIT3 + BIT4)	//00b/x/x/x Enable Break DPP Function
    #define U3IPSSCFGP_R_SYNCBFTS_SS			BIT2	//0/x/x/x Insert SYNC OS Before Transmitting TS OS
    #define U3IPSSCFGP_R_EQDISKP_SS			BIT1	//0/x/x/x Disable SKP OS During TSEQ
    #define U3IPSSCFGP_R_RSTCLR_SS			BIT0	//0/x/x/x Enable Synchronous Reset In TX Path When Ready to Gen2
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_8_VT3515C0		0x05A	//SSIP_PORT_NEW_Register_8 ((VT3515C0))
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_05A_SS			0xF800	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_MSDPFRCV_SS			BIT10	//0/x/x/x Enable DPP End Lost To Recovery State
    #define U3IPSSCFGP_R_UNLCKPOP_SS			BIT9	//0/x/x/x Enable POP Data From LPHY When Symbol Lock Lost In U0 State
    #define U3IPSSCFGP_R_EQSKPSET_SS			BIT8	//0/x/x/x Set SKP Interval In TSEQ State
    #define U3IPSSCFGP_R_DPHEDBAD_SS			BIT7	//0/x/x/x When DPH With EDB Condition Occurred, RXDBAD Will Be Asserted
    #define U3IPSSCFGP_R_PLREQALWS_SS			BIT6	//0/x/x/x Enable Always Allow Request from PL to Link Layer
    #define U3IPSSCFGP_R_TXDLBEN_SS			BIT5	//0/x/x/x Enable DLB Queue Function
    #define U3IPSSCFGP_R_ALSRTYDPP_SS			BIT4	//0/x/x/x Always Retry DPP Payload Of SSP Mode When This SP Needed to Be Retried
    #define U3IPSSCFGP_R_SSPRTYDPP_SS			BIT3	//0/x/x/x Re-Transmit DPP When DP Retry
    #define U3IPSSCFGP_R_RBFDBGSEL_SS			(BIT1 + BIT2)	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_TS1TS2_DET_LOC_SS			BIT0	//0/x/x/x Detect The Location Of The TS1/2 To Align The Block In LPHY
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_9_VT3483_AND_VT3456		0x05C	//SSIP_PORT_NEW_Register_9 ((VT3483 and VT3456))
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_05C_SS			0xFF00	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_RXHZ_DIS_SEL_SS			BIT7	//0/x/x/x Select Which One Control RXHZ_DISEN Signal
    #define U3IPSSCFGP_R_EPHYTST_PSTBEB_SS			BIT6	//0/x/x/x Gating The TBTOEB Data To Up Layer T ((VT3456))
    #define U3IPSSCFGP_R_HRSTS12TMOEN_SS			BIT5	//0/x/x/x Clear PR When Polling/Recovery Timeout (VT3456)
    #define U3IPSSCFGP_R_HRSTCPLEN_NEW_SS			BIT4	//0/x/x/x Enable LTSSM Response SC_HRST_CPL When Device Disconnect. 
    #define U3IPSSCFGP_R_EMTYPASSEN_SS			BIT3	//0/x/x/x Enable TX DPH And TPH When TX Header Queue Is Empty ((VT3483) )
    #define U3IPSSCFGP_R_PASSDPEN_SS			BIT2	//0/x/x/x Enable TX DPH  ((VT3483)) 
    #define U3IPSSCFGP_R_PASSTPEN_SS			BIT1	//0/x/x/x Enable TX TPH  ((VT3483)) 
    #define U3IPSSCFGP_R_TXREQACK_EN_SS			BIT0	//0/x/x/x Enable R_PASSTPEN_SS, R_PASSDPEN_SS And R_EMTYPASSEN_SS ((VT3483)) 
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_10_CND003_NEW		0x05E	//SSIP_PORT_NEW_Register_10 ((CND003 NEW))
    #define U3IPSSCFGP_R_U3GATESW_SS			BIT15	//1b/x/x/x Enable U3 Exit When SW Direct
    #define U3IPSSCFGP_R_U3GATE_SS			BIT14	//0/x/x/x Enable Gating U3 EXIT When Ring Doorbell In U3 State
    #define U3IPSSCFGP_R_UXLFPSEXTEN_SS			BIT13	//0/x/x/x Enable Extending UX LFPS EXIT (T12-T11) Min To 600ns For Simultaneous Ux
    #define U3IPSSCFGP_R_PMUDEFEREN_SS			BIT12	//1b/x/x/x Enable PMU_PORT_DEFER 
    #define U3IPSSCFGP_R_UXDFPLAUTMOEN_SS			BIT11	//0/x/x/x Enable Host Transmit LAU When Inactive Timeout 
    #define U3IPSSCFGP_R_LCQPOP_RXLBAD_SS			BIT10	//0/x/x/x Enable LCQRPTR Advance When RX LBAD, Only For HUB
    #define U3IPSSCFGP_R_UXDFPLAUEN_SS			BIT9	//0/x/x/x Enable DFP Send LAU When RX LGO_Ux
    #define U3IPSSCFGP_R_SSPLPBK_USR_SS			BIT8	//0/x/x/x SSP 10G BIST User Mode Enable
    #define U3IPSSCFGP_R_SSPLPBK_USR_MODE_SS			0xF0	//0/x/x/x SSP 10G BIST User Mode
    #define U3IPSSCFGP_R_POLFPS_EXT_SS			BIT3	//1b/x/x/x Enable Send Polling LFPS Until Device Don¡¯ T Send LFPS
    #define U3IPSSCFGP_R_LPHY_ALIGN_SS			BIT2	//0/x/x/x Enable LPHY Lock, Do Not Care Input Symbol
    #define U3IPSSCFGP_R_APFORCEU3_MSK_SS			BIT1	//0/x/x/x Mask AP_FORCEU3, Link Can¡¯ T Go To U3
    #define U3IPSSCFGP_R_APISIDLE_MSK_SS			BIT0	//0/x/x/x Mask APISIDEL Signal, Link Can¡¯ T Go To U1/U2/U3
#define U3IPSSCFGP_SSIP_10B_DATA_ERR_CNTER		0x060	//SSIP_10B_DATA_ERR_COUNTER
    #define U3IPSSCFGP_D_SSP_LPBK_USRINDN_SS			BIT15	//HwInit/x/x/x SSP 10G BIST User Mode Initial Done
    #define U3IPSSCFGP_D_TBEBERRCNT_SS			0x7FFF	//HwInit/x/x/x RX 10B Data Error Counter
#define U3IPSSCFGP_SSIP_LN_RX_ERR		0x062	//SSIP_LN_RX_ERROR
    #define U3IPSSCFGP_D_LNERRCNT_SS			0xFFFF	//HwInit/x/x/x Link Error Counter, Add 1 When:
#define U3IPSSCFGP_SSIP_R2T_LPBK_MST_ERR		0x064	//SSIP_ R2T_LPBK_MST_ERROR
    #define U3IPSSCFGP_D_SSP_LPBKERR_SS			0xFFFF	//HwInit/x/x/x Error Counter Add 1 Per 32bit If RX Is Not LI Or SYNC Symbol 
#define U3IPSSCFGP_SSIP_LDM_LMP_RESPONSE_DELAY		0x066	//SSIP_LDM_LMP_RESPONSE_DELAY
    #define U3IPSSCFGP_D_SSP_LPBKINDN_SS			BIT15	//HwInit/x/x/x Indicate SSP TX To RX Loopback Initial Done
    #define U3IPSSCFGP_D_SSP_LPHYULK_SS			BIT14	//HwInit/x/x/x Indicate SSP LPHY Unlock
    #define U3IPSSCFGP_D_SSP_LPBKULK_SS			BIT13	//HwInit/x/x/x Indicate LPHY Unlock When Do SSP TX To RX Loopback
    #define U3IPSSCFGP_D_RXPOLINV_SS			BIT12	//HwInit/x/x/x RX Polarity Status
    #define U3IPSSCFGP_D_LDMDLY_SS			0xFFF	//HwInit/x/x/x Response Delay Value Of LDM LMP
#define U3IPSSCFGP_SSIP_STA		0x068	//SSIP_STATUS
    #define U3IPSSCFGP_LTSSM_SS			0xFE00	//HwInit/x/x/x USB3.1 LINK STATE
    #define U3IPSSCFGP_D_CP912_FLAG_SS			BIT8	//HwInit/x/x/x Indicate TX CP9 To CP12
    #define U3IPSSCFGP_D_CP_VALUE_SS			0xF8	//HwInit/x/x/x TX CP Pattern Mode
    #define U3IPSSCFGP_D_LPBMST_LCECERR_SS			BIT2	//HwInit/x/x/x Indicate LPBK Master Local Error Counter Is Not 0
    #define U3IPSSCFGP_D_EPHYBISTER_SS			BIT1	//HwInit/x/x/x Display The Data Mismatch Happen When Do EPHYBIST
    #define U3IPSSCFGP_D_RMACWK_SS			BIT0	//HwInit/x/x/x Indicate Remote Link Partner Actively Issues Wake Up To Resume Link. (Status Register)
#define U3IPSSCFGP_SSIP_PORT_NEW_REG_10_VT3518_C0		0x06A	//SSIP_PORT_NEW_Register_10 ((VT3518_C0))
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_06A_SS			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_PMTMEXTEN_SS			BIT14	//0/x/x/x Extend The Timeout Value Of PM_LC_TIMER And PM_ENTRY_TIMER To 4us And 8us
    #define U3IPSSCFGP_R_PMTMEXT_SS			BIT13	//0/x/x/x Extend The Timeout Value Of PM_LC_timer To 6us
    #define U3IPSSCFGP_R_U1STMEXT_SS			BIT12	//0/x/x/x Extend Value Of The U1 Short Timeout To 6us
    #define U3IPSSCFGP_R_PHDTMEXT_SS			BIT11	//0/x/x/x Extend The Timeout Value Of Pending Header Timer To 30us
    #define U3IPSSCFGP_R_DLYTXOFT_SS			(BIT9 + BIT10)	//01b/x/x/x Delay TX Off Time
    #define U3IPSSCFGP_R_P3_TXHZ_SS			BIT8	//0/x/x/x Enable TXHZ When In TX P2 State.
    #define U3IPSSCFGP_R_P2_TXHZ_SS			BIT7	//0/x/x/x Enable TXHZ When In TX P3 State.
    #define U3IPSSCFGP_R_ADVNDONE_SS			BIT6	//0/x/x/x Enable The Arc Of Active To Idle When Advertisement Not Done
    #define U3IPSSCFGP_R_PLUSRST_SS			BIT5	//1b/x/x/x Disable Switch To SS When Receiving SCD1 In LFPSPLUS
    #define U3IPSSCFGP_R_DPABORT_SS			BIT4	//0/x/x/x Enable DP Abort Function Only Used for Hub Mode
    #define U3IPSSCFGP_R_PLEIMIN_SS			BIT3	//0/x/x/x Minimal The E-Ilde Interval To 20us In Polling.LFPS
    #define U3IPSSCFGP_R_TESTPWR_SS			BIT2	//0/x/x/x Enbale Power State Auto Tuning for Test Mode.
    #define U3IPSSCFGP_R_PKTDLYEN_SS			BIT1	//0/x/x/x Delay To Transfer Packet After Advertisement Done
    #define U3IPSSCFGP_R_LSTPOPEN_SS			BIT0	//0/x/x/x Assert DBXLSTPOP When Nullified Packet Only for Hub Mode
#define U3IPSSCFGP_SSIP_COMMAN_RESERVED_6C		0x06C	//SSIP_Comman_Reserved_6C
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_06C_SS			0xFF00	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_DIRECT_SS			BIT7	//0/x/x/x Set LTSS By Register When R_DIRECT = 1
    #define U3IPSSCFGP_R_LTSSNXT_SS			0x7F	//0/x/x/x Set LTSS By Register
#define U3IPSSCFGP_SSIP_COMMAN_RESERVED_6E		0x06E	//SSIP_Comman_Reserved_6E
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_06E_SS			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_1		0x070	//SSP 10G BIST User Mode Pattern Word 1
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W1_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 1
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_2		0x072	//SSP 10G BIST User Mode Pattern Word 2
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W2_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 2
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_3		0x074	//SSP 10G BIST User Mode Pattern Word 3
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W3_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 3
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_4		0x076	//SSP 10G BIST User Mode Pattern Word 4
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W4_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 4
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_5		0x078	//SSP 10G BIST User Mode Pattern Word 5
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W5_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 5
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_6		0x07A	//SSP 10G BIST User Mode Pattern Word 6
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W6_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 6
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_7		0x07C	//SSP 10G BIST User Mode Pattern Word 7
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W7_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 7
#define U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_8		0x07E	//SSP 10G BIST User Mode Pattern Word 8
    #define U3IPSSCFGP_R_SSPLPBK_USR_PTN_W8_SS			0xFFFF	//5555h/x/x/x SSP 10G BIST User Mode Pattern Word 8
#define U3IPSSCFGP_SSIP_PORT_SUSPEND_OPTION_REGS		0x080	//SSIP_PORT_Suspend_Option_Registers
    #define U3IPSSCFGP_R_SLFPSLEN_SS			(BIT14 + BIT15)	//0/x/x/x Select Filter LFPS Length For Wake Up Condition
    #define U3IPSSCFGP_R_UXETPLLOFF_SS			BIT13	//1b/x/x/x Enable Power State TPLL Off Function In Exit And Detection 
    #define U3IPSSCFGP_R_U1TPLLOFF_SS			BIT12	//0/x/x/x Enable U1 State TPLL Off Function 
    #define U3IPSSCFGP_R_DETIME_SS			(BIT10 + BIT11)	//0/x/x/x Indicate Receiver Detection Time.
    #define U3IPSSCFGP_R_LSDYNEN_SS			BIT9	//0/x/x/1b Enable LFPSC Suspend Dynamic Clock. 
    #define U3IPSSCFGP_R_LFPSDGEN_SS			BIT8	//1b/x/x/x Enable LFPS De-Glitch Function. 
    #define U3IPSSCFGP_R_DEVRCVTSEN_SS			BIT7	//0/x/x/x Device Receiver Detection Limit Timer Shorter Enable.
    #define U3IPSSCFGP_R_D3HOTEN_SS			BIT6	//1b/x/x/x Enable Suspend Domain Receiver Detection In D3-Hot Condition.
    #define U3IPSSCFGP_R_LKCWEN_SS			BIT5	//0/x/x/x Enable Link Trained After Compliance Mode Warm Reset
    #define U3IPSSCFGP_R_PSWRSTRCVEN_SS			BIT4	//1b/x/x/x Enable UFP Receiving Warm Reset In Polling State To Avoid Entry Disable State Due To Timeout.
    #define U3IPSSCFGP_R_QKTMOEN_SS			BIT3	//0/x/x/x Quick Timeout Mode Enable
    #define U3IPSSCFGP_R_IPTYPE_SS			(BIT1 + BIT2)	//10b/x/x/x Device / Port Type Selection
    #define U3IPSSCFGP_R_RCVDET_MODE_SS			BIT0	//1b/x/x/x Receiver Detection Decision Mode0: TxD+ && TxD-
#define U3IPSSCFGP_SSIP_PORT_LFPSC_OPTION_REGS_1		0x082	//SSIP_PORT_LFPSC_Option_Registers_1
    #define U3IPSSCFGP_R_RCVDET_SS			BIT15	//0/x/x/x Receiver Detection Control Start
    #define U3IPSSCFGP_R_RCVDETSETEN_SS			BIT14	//0/x/x/x Receiver Detection Control Set Enable
    #define U3IPSSCFGP_R_DISOFF_SS			BIT13	//0/x/x/x Disable PMU Wake Signal Function In Disable State. 
    #define U3IPSSCFGP_R_RCVTMOTMR_SS			(BIT11 + BIT12)	//0/x/x/x Receiver Detection Period
    #define U3IPSSCFGP_R_DYNLPHYRCVEN_SS			BIT10	//0/x/x/1b Dynamic Power Enable For Receiver Detection
    #define U3IPSSCFGP_R_DYNLPHYSUSEN_SS			BIT9	//0/x/x/1b Dynamic Power Enable In LPHY SUSPOW Domain
    #define U3IPSSCFGP_R_RCVDET_NONE_SS			BIT8	//0/x/x/x Let Receiver Result Always Be None
    #define U3IPSSCFGP_R_RMCNTEN_SS			BIT7	//0/x/x/x Enable Remote Counter Function. 
    #define U3IPSSCFGP_R_DYNSUSPM_SS			BIT6	//0/x/x/1b Dynamic Power Management Control Enable
    #define U3IPSSCFGP_R_PASSU3RCVDET_SS			BIT5	//0/x/x/x Pass Receiver Detection In Suspend Domain
    #define U3IPSSCFGP_R_PLLEN_SS			(BIT3 + BIT4)	//11b/x/x/x Select The Low Bound Of Polling-LFPS Margin.
    #define U3IPSSCFGP_R_RXLFPSEN_SS			BIT2	//1b/x/x/x Enable Receiver LFPS Detection.
    #define U3IPSSCFGP_R_DISRDCLREN_SS			BIT1	//1b/x/x/x Clear RCV_DETECTED Value In Disable State. 
    #define U3IPSSCFGP_R_DISRDEN_SS			BIT0	//0/x/x/x Enable Receiver Detection In Disable State.
#define U3IPSSCFGP_SSIP_PORT_LFPSC_OPTION_REGS_2		0x084	//SSIP_PORT_LFPSC_Option_Registers_2
    #define U3IPSSCFGP_R_LPHYRCVTMOTMR_SS			(BIT14 + BIT15)	//0/x/x/x Receiver Detection Discharge Period
    #define U3IPSSCFGP_R_EXTDETQTM_SS			BIT13	//0/x/x/x Extend Detection Interval To 120ms From 12ms
    #define U3IPSSCFGP_R_SSCTSRST_SS			BIT12	//0/x/x/x Enable SSC Reset When More Than 2ms In TS States Of Polling Or Recovery State
    #define U3IPSSCFGP_R_SSCPRST_SS			BIT11	//0/x/x/x Enable SSC Reset When Entry Polling State
    #define U3IPSSCFGP_R_FLFPSPDB_SS			BIT10	//0/x/x/x FW Power Down LFPSRCV
    #define U3IPSSCFGP_R_HLFPSPDB_SS			BIT9	//0/x/x/1b HW Automatic Power Down LFPSRCV
    #define U3IPSSCFGP_R_DPU23NDET_SS			BIT8	//0/x/x/x DFP Disable Receiver Detection In U2/3
    #define U3IPSSCFGP_R_WRSTCDET_SS			BIT7	//0/x/x/x Clear Connection Flag When Generating Warm Reset
    #define U3IPSSCFGP_R_EXTRSTEN_SS			BIT6	//0/x/x/x Extend Recovery State TRX Reset Interval
    #define U3IPSSCFGP_R_DISCONEN_SS			(BIT4 + BIT5)	//0/x/x/x Enable Dis-Connection Multi-Time Sample
    #define U3IPSSCFGP_R_WRSTRCVMIN_SS			BIT3	//0/x/x/x Enable Minimal LFPS Length When Receiving Warm Reset LFPS. 
    #define U3IPSSCFGP_R_UFPDETEN_SS			BIT2	//0/x/x/x Enable UFP Receiver Detection In U2/3 State 
    #define U3IPSSCFGP_R_LKTRADCLR_SS			BIT1	//0/x/x/x Clear Link Trained Bit (Link Has Gone Polling RXEQ From Polling LFPS)
    #define U3IPSSCFGP_R_TXLFPSEN_SS			BIT0	//0/x/x/x LFPS Generation Enable
#define U3IPSSCFGP_SSIP_PORT_LFPSC_STA_REGS		0x086	//SSIP_PORT_LFPSC_Status_Registers
    #define U3IPSSCFGP_FHU_RXTERM			0xF000	//1000b/x/x/x Manual Setting For RX Termination
    #define U3IPSSCFGP_FHU_RX100K			BIT11	//0/x/x/x Control RX At High R State (Default 0, Active 1)
    #define U3IPSSCFGP_FHU_RCVDETS			(BIT8 + BIT9 + BIT10)	//100b/x/x/x Rcvdet Detection Level Control
    #define U3IPSSCFGP_R_DETCNT_SS			(BIT6 + BIT7)	//0/x/x/x Enable Receiver Detection De-Bounce
    #define U3IPSSCFGP_LFPSC_TBKV_SS			0x3C	//0/x/x/x TieBreaker Value Received From Link Partner
    #define U3IPSSCFGP_LFPSC_VPLN_SS			BIT1	//0/x/x/x The indicator of VLI Product Check and Matching LDN/LUP Check Function  Is Enabling
    #define U3IPSSCFGP_LFPSC_VPPL_SS			BIT0	//0/x/x/x The indicator of VLI Product Check and Matching  The TBK Check Function Is Enabling
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS1		0x088	//SSIP_PORT_EPHY_Control_Registers1
    #define U3IPSSCFGP_FHU_NONP2			BIT15	//0/x/x/x The Function Of Interface Is For Solving TX
    #define U3IPSSCFGP_FHU_RXPWRSET			(BIT13 + BIT14)	//10b/x/x/x RX Power Status Set
    #define U3IPSSCFGP_FHU_RXPWRSETEN			BIT12	//0/x/x/x RX Power Status Set Enable
    #define U3IPSSCFGP_FHU_TXEIDLESETB			BIT11	//0/x/x/x TX Electrical Idle Set
    #define U3IPSSCFGP_FHU_TXPWRSET			(BIT9 + BIT10)	//10b/x/x/x TX Power Status Set 
    #define U3IPSSCFGP_FHU_TXPWRSETEN			BIT8	//0/x/x/x TX Power Status Set Enable
    #define U3IPSSCFGP_FHU_TXEIDLESEL			BIT7	//0/x/x/x TXEIDLEB Control By LPHY Or Register Setting
    #define U3IPSSCFGP_FHU_RXRTNIN			BIT6	//0/x/x/x Control RX Term From RTN Output 
    #define U3IPSSCFGP_FHU_LFPS_SW			(BIT3 + BIT4 + BIT5)	//100b/x/x/x Set Bias Current For LFPS Swing
    #define U3IPSSCFGP_FHU_LFPSVTH			(BIT1 + BIT2)	//10b/x/x/x Set LFPS REV Detection Threshold 
    #define U3IPSSCFGP_FHU_LFPSBPFPD			BIT0	//0/x/x/x Disables The Band-Pass Function Of LFPS RCV
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS2		0x08A	//SSIP_PORT_EPHY_Control_Registers2
    #define U3IPSSCFGP_FHU_LOWPOWER_SS			BIT15	//1b/x/x/x Low Power Control
    #define U3IPSSCFGP_FHU_IVCPSEL_SS			0x7800	//1010b/x/x/x Port0 IV Gain Select, Set Charge Pump Current
    #define U3IPSSCFGP_FHU_RXCLKSEL_SS			(BIT8 + BIT9 + BIT10)	//000b/x/x/x RXCLK Phase Select  1 Period= 1/500MHz
    #define U3IPSSCFGP_FHU_RXDFETAP_SS			(BIT6 + BIT7)	//11b/x/x/x RX DEF TAP Control
    #define U3IPSSCFGP_FHU_TDCIS_SS			(BIT3 + BIT4 + BIT5)	//100b/x/x/x Port0 Bias Current Set (Default 100: +2 mA)
    #define U3IPSSCFGP_FHU_TDNCIS_SS			(BIT0 + BIT1 + BIT2)	//011b/x/x/x De-Emphasis Set 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS3		0x08C	//SSIP_PORT_EPHY_Control_Registers3
    #define U3IPSSCFGP_FHU_EQTNMODE_SS			0xFF00	//0/x/x/x Equalizer Tuning Mode Select
    #define U3IPSSCFGP_FHU_RGLVREFSET_SS			0xF0	//0/x/x/x Regulator Voltage Option
    #define U3IPSSCFGP_FHU_CDRRGLSEL_SS			0xF	//0/x/x/x CDR Power Control 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS4		0x08E	//SSIP_PORT_EPHY_Control_Registers4
    #define U3IPSSCFGP_FHU_EQTNOSBW_SS			0xF000	//0001b/x/x/x LEQ Offset Tuning Bandwidth Set 
    #define U3IPSSCFGP_FHU_EQTNHFMAX_SS			(BIT10 + BIT11)	//00b/x/x/x LEQ HF Max. Gain
    #define U3IPSSCFGP_FHU_EQTNDCMAX_SS			(BIT8 + BIT9)	//00b/x/x/x LEQ DC Max. Gain
    #define U3IPSSCFGP_FHU_EQTNHFBW_SS			0xF0	//0001b/x/x/x LEQ HF Gain Tuning Bandwidth Set 
    #define U3IPSSCFGP_FHU_EQTNDCBW_SS			0xF	//0001b/x/x/x LEQ DC Gain Tuning Bandwidth Set 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS5		0x090	//SSIP_PORT_EPHY_Control_Registers5
    #define U3IPSSCFGP_FHU_HFSET_SS			0xF000	//1111b/x/x/x LEQ HF Gain Initial Or Set Value 
    #define U3IPSSCFGP_FHU_HFSETEN_SS			BIT11	//0/x/x/x LEQ HF Gain Manual Set Enable
    #define U3IPSSCFGP_FHU_EQTNVTH_SS			(BIT8 + BIT9 + BIT10)	//101b/x/x/x Equalizer Tuning Threshold (CDR Input Eye opening reference) 
    #define U3IPSSCFGP_FHU_EQTNSPDSWEN_SS			BIT7	//0/x/x/x Enable Low Speed Operation Under
    #define U3IPSSCFGP_FHU_EQTNALWY_SS			BIT6	//0/x/x/x Equalizer Always Tuning Mode Enable
    #define U3IPSSCFGP_FHU_EQTNDFE_SS			(BIT4 + BIT5)	//01b/x/x/x DFE Tap Selection 
    #define U3IPSSCFGP_FHU_EQTNWTBW_SS			0xF	//0001b/x/x/x DFE Weight Tuning Bandwidth Set
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS6		0x092	//SSIP_PORT_EPHY_Control_Registers6
    #define U3IPSSCFGP_FHU_W1SET_SS			0xF000	//0000b/x/x/x DFE Weight1 Initial Or Set Value
    #define U3IPSSCFGP_FHU_OSSET_SS			0xF00	//0000b/x/x/x LEQ Offset Initial Or Set Value
    #define U3IPSSCFGP_FHU_OSSETEN_SS			BIT7	//0/x/x/x LEQ Offset Manual Set Enable
    #define U3IPSSCFGP_FHU_DCSET_SS			0x7C	//11111b/x/x/x LEQ DC Gain Initial Or Set Value
    #define U3IPSSCFGP_FHU_DCSETEN_SS			BIT1	//0/x/x/x LEQ (Linear Equalizer) DC Gain Manual Set Enable
    #define U3IPSSCFGP_FHU_EQTNDFETRN_SS			BIT0	//1b/x/x/x Enable DFE In Training Mode 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS7		0x094	//SSIP_PORT_EPHY_Control_Registers7
    #define U3IPSSCFGP_FHU_TDPCIS_SS			(BIT13 + BIT14 + BIT15)	//011b/x/x/x Pre-Emphasis Set
    #define U3IPSSCFGP_FHU_PRESHOOT_SS			BIT12	//0/x/x/x TXpre-Shoot Enable For Pre-Cursor Described By Gen 2 Spec
    #define U3IPSSCFGP_FHU_EQTNBISTEVT			(BIT9 + BIT10 + BIT11)	//000b/x/x/x Tuning Function BIST: Event Selection
    #define U3IPSSCFGP_FHU_EQTNBISTEN			BIT8	//0/x/x/x Tuning Function BIST Enable
    #define U3IPSSCFGP_FHU_TXCMFT			(BIT6 + BIT7)	//01b/x/x/x TX Common Mode Voltage Fine Tune.
    #define U3IPSSCFGP_FHU_W2SET_SS			0x3C	//0000b/x/x/x DFE Weight2 Initial Or Set Value
    #define U3IPSSCFGP_FHU_W2SETEN_SS			BIT1	//0/x/x/x DFE Weight2 Manual Set Enable
    #define U3IPSSCFGP_FHU_W1SETEN_SS			BIT0	//0/x/x/x DFE Weight1 Manual Set Enable
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS8		0x096	//SSIP_PORT_EPHY_Control_Registers8
    #define U3IPSSCFGP_EPU_HFOUT			0xF000	//0/x/x/x LEQ HF Gain Output
    #define U3IPSSCFGP_EPU_W2OUT			0xF00	//0/x/x/x DFE Weight2 Output
    #define U3IPSSCFGP_EPU_W1OUT			0xF0	//0/x/x/x DFE Weight1 Output
    #define U3IPSSCFGP_EPU_OSOUT			0xF	//0/x/x/x LEQ Offset Output
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS9		0x098	//SSIP_PORT_EPHY_Control_Registers9
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_098_SS			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_OCPHGSEL_SS			BIT14	//1b/x/x/x Open Or Close Loop Phase Generation Selection
    #define U3IPSSCFGP_FHU_FTSRATIO_SS			(BIT11 + BIT12 + BIT13)	//011b/x/x/x PD Training Mode Ratio During P1 to P0
    #define U3IPSSCFGP_FHU_FDRATIO_SS			(BIT8 + BIT9 + BIT10)	//100b/x/x/x FD (Frequency Detector) Mode Ratio During P2 to P1 to P0
    #define U3IPSSCFGP_FHU_TX_DUTY_SS			(BIT5 + BIT6 + BIT7)	//000b/x/x/x TX Duty Cycle Fine Tune
    #define U3IPSSCFGP_EPU_DCOUT			0x1F	//0/x/x/x LEQ DC Gain Output
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS10		0x09A	//SSIP_PORT_EPHY_Control_Registers10
    #define U3IPSSCFGP_FHU_KTSEL_SS			BIT15	//0/x/x/x Update Time During Tracking Mode 
    #define U3IPSSCFGP_FHU_NTSEL_SS			BIT14	//1b/x/x/x Update Time During Training Mode 
    #define U3IPSSCFGP_FHU_KIPCSEL_SS			(BIT12 + BIT13)	//00b/x/x/x Gain2 During Tracking Mode 
    #define U3IPSSCFGP_FHU_NIPCSEL_SS			(BIT10 + BIT11)	//01b/x/x/x Gain2 During Training Mode 
    #define U3IPSSCFGP_FHU_KIPRSEL_SS			(BIT8 + BIT9)	//01b/x/x/x Gain1 During Tracking Mode
    #define U3IPSSCFGP_FHU_NIPRSEL_SS			(BIT6 + BIT7)	//10b/x/x/x Gain1 During Training Mode
    #define U3IPSSCFGP_FHU_P2EXT_SS			(BIT3 + BIT4 + BIT5)	//010b/x/x/x P2 Exit Latency
    #define U3IPSSCFGP_FHU_P1EXT_SS			(BIT0 + BIT1 + BIT2)	//100b/x/x/x P1 Exit Latency 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS11		0x09C	//SSIP_PORT_EPHY_Control_Registers11
    #define U3IPSSCFGP_FHU_RXDFETAP_SSP			(BIT14 + BIT15)	//11b/x/x/x Gen2 RX DEF TAP Control
    #define U3IPSSCFGP_FHU_W3SET_SS			0x3C00	//0000b/x/x/x DFE Weight3 Initial Or Set Value 
    #define U3IPSSCFGP_FHU_W3SETEN_SS			BIT9	//0/x/x/x DFE Weight3 Manual Set 
    #define U3IPSSCFGP_R_DETRXLFPS_SS			BIT8	//0/x/x/x Enable RX-LFPS 2us Deglitch When Dis-Connection
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_09D_SS			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_RXBW_SS			(BIT4 + BIT5)	//11b/x/x/x LEQ, VGA Band-Width Option : [1:0] VGA LEQ
    #define U3IPSSCFGP_FHU_KLFSEL_SS			(BIT2 + BIT3)	//10b/x/x/x LF Select During Tracking Mode 
    #define U3IPSSCFGP_FHU_NLFSEL_SS			(BIT0 + BIT1)	//01b/x/x/x LF Select During Training Mode 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS12		0x09E	//SSIP_PORT_EPHY_Control_Registers12
    #define U3IPSSCFGP_FHU_RXBW_SSP			(BIT14 + BIT15)	//11b/x/x/x LEQ, VGA Band-Width Option : [1:0] VGA LEQ
    #define U3IPSSCFGP_FHU_TX_DUTY_SSP			(BIT11 + BIT12 + BIT13)	//000b/x/x/x TX Duty Cycle Fine Tune
    #define U3IPSSCFGP_FHU_TDPCIS_SSP			(BIT8 + BIT9 + BIT10)	//011b/x/x/x Pre-Emphasis Set
    #define U3IPSSCFGP_FHU_LOWPOWER_SSP			BIT7	//1b/x/x/x Low Power Control 
    #define U3IPSSCFGP_FHU_PRESHOOT_SSP			BIT6	//0/x/x/x TXpre-Shoot Enable For Pre-Cursor Described By Gen 2 Spec
    #define U3IPSSCFGP_FHU_TDCIS_SSP			(BIT3 + BIT4 + BIT5)	//100b/x/x/x Port0 Bias Current Set (Default 100: +2 mA)
    #define U3IPSSCFGP_FHU_TDNCIS_SSP			(BIT0 + BIT1 + BIT2)	//011b/x/x/x De-Emphasis Set 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS13		0x0A0	//SSIP_PORT_EPHY_Control_Registers13
    #define U3IPSSCFGP_FHU_RGLVREFSET_SSP			0xF000	//0/x/x/x Regulator Voltage Option
    #define U3IPSSCFGP_FHU_CDRRGLSEL_SSP			0xF00	//0/x/x/x CDR Power Control 
    #define U3IPSSCFGP_FHU_EQTNALWY_SSP			BIT7	//1b/x/x/x Equalizer Always Tuning Mode Enable
    #define U3IPSSCFGP_FHU_IVCPSEL_SSP			0x78	//1010b/x/x/x Port0 IV Gain Select, Set Charge Pump Current
    #define U3IPSSCFGP_FHU_RXCLKSEL_SSP			(BIT0 + BIT1 + BIT2)	//000b/x/x/x RXCLK Phase Select  1 Period= 1/500MHz
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS14		0x0A2	//SSIP_PORT_EPHY_Control_Registers14
    #define U3IPSSCFGP_FHU_EQTNMODE_SSP			0xFF00	//0/x/x/x Equalizer Tuning Mode Select 
    #define U3IPSSCFGP_FHU_EQTNDCMAX_SSP			(BIT6 + BIT7)	//00b/x/x/x LEQ DC Max Gain
    #define U3IPSSCFGP_FHU_EQTNDCBW_SSP			0x3C	//0001b/x/x/x LEQ DC Gain Tuning Bandwidth Set 
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0A2_SS			(BIT0 + BIT1)	//0/x/x/x Reserved
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS15		0x0A4	//SSIP_PORT_EPHY_Control_Registers15
    #define U3IPSSCFGP_FHU_EQTNDFE_SSP			(BIT14 + BIT15)	//10b/x/x/x DFE Tap Selection 
    #define U3IPSSCFGP_FHU_EQTNWTBW_SSP			0x3C00	//0111b/x/x/x DFE Weight Tuning Bandwidth Set 
    #define U3IPSSCFGP_FHU_EQTNHFMAX_SSP			(BIT8 + BIT9)	//00b/x/x/x LEQ HF Max Gain 
    #define U3IPSSCFGP_FHU_EQTNOSBW_SSP			0xF0	//0001b/x/x/x LEQ Offset Tuning Bandwidth Set 
    #define U3IPSSCFGP_FHU_EQTNHFBW_SSP			0xF	//0111b/x/x/x LEQ HF Gain Tuning Bandwidth Set 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS16		0x0A6	//SSIP_PORT_EPHY_Control_Registers16
    #define U3IPSSCFGP_FHU_W3SETEN_SSP			BIT15	//0/x/x/x DFE Weight3 Manual Set Enable
    #define U3IPSSCFGP_FHU_W2SETEN_SSP			BIT14	//0/x/x/x DFE Weight2 Manual Set Enable
    #define U3IPSSCFGP_FHU_W1SETEN_SSP			BIT13	//0/x/x/x DFE Weight1 Manual Set Enable
    #define U3IPSSCFGP_FHU_DCSET_SSP			0x1F00	//11111b/x/x/x LEQ DC Gain Initial Or Set Value
    #define U3IPSSCFGP_FHU_OSSETEN_SSP			BIT7	//0/x/x/x LEQ Offset Manual Set Enable
    #define U3IPSSCFGP_FHU_HFSETEN_SSP			BIT6	//0/x/x/x LEQ HF Gain Manual Set Enable
    #define U3IPSSCFGP_FHU_DCSETEN_SSP			BIT5	//0/x/x/x LEQ (Linear Equalizer) DC Gain Manual Set
    #define U3IPSSCFGP_FHU_EQTNDFETRN_SSP			BIT4	//1b/x/x/x Enable DFE In Training Mode
    #define U3IPSSCFGP_FHU_EQTNVTH_SSP			(BIT1 + BIT2 + BIT3)	//101b/x/x/x Equalizer Tuning Threshold (CDR Input Eye opening reference)
    #define U3IPSSCFGP_FHU_EQTNSPDSWEN_SSP			BIT0	//1b/x/x/x Enable Low Speed Operation Under
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS17		0x0A8	//SSIP_PORT_EPHY_Control_Registers17
    #define U3IPSSCFGP_FHU_W2SET_SSP			0xF000	//0000b/x/x/x DFE Weight2 Initial Or Set Value
    #define U3IPSSCFGP_FHU_W1SET_SSP			0xF00	//0000b/x/x/x DFE Weight1 Initial Or Set Value 
    #define U3IPSSCFGP_FHU_OSSET_SSP			0xF0	//0000b/x/x/x LEQ Offset Initial Or Set Value 
    #define U3IPSSCFGP_FHU_HFSET_SSP			0xF	//1111b/x/x/x LEQ HF Gain Initial Or Set Value 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS18		0x0AA	//SSIP_PORT_EPHY_Control_Registers18
    #define U3IPSSCFGP_FHU_NIPCSEL_SSP			(BIT14 + BIT15)	//01b/x/x/x Gain2 During Training Mode 
    #define U3IPSSCFGP_FHU_FTSRATIO_SSP			(BIT11 + BIT12 + BIT13)	//100b/x/x/x PD Training Mode Ratio During P1 to P0
    #define U3IPSSCFGP_FHU_FDRATIO_SSP			(BIT8 + BIT9 + BIT10)	//101b/x/x/x FD (Frequency Detector) Mode Ratio During P2 toP1 To P0
    #define U3IPSSCFGP_FHU_KIPRSEL_SSP			(BIT6 + BIT7)	//00b/x/x/x Gain1 During Tracking Mode
    #define U3IPSSCFGP_FHU_NIPRSEL_SSP			(BIT4 + BIT5)	//10b/x/x/x Gain1 During Training Mode
    #define U3IPSSCFGP_FHU_W3SET_SSP			0xF	//0000b/x/x/x DFE Weight3 Initial Or Set Value
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS19		0x0AC	//SSIP_PORT_EPHY_Control_Registers19
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0AC_SS			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_OCPHGSEL_SSP			BIT14	//1b/x/x/x Open Or Close Loop Phase Generation Selection
    #define U3IPSSCFGP_FHU_KLFSEL_SSP			(BIT12 + BIT13)	//11b/x/x/x LF Select During Tracking Mode 
    #define U3IPSSCFGP_FHU_NLFSEL_SSP			(BIT10 + BIT11)	//01b/x/x/x LF Select During Training Mode 
    #define U3IPSSCFGP_FHU_KTSEL_SSP			BIT9	//0/x/x/x Update Time During Tracking Mode 
    #define U3IPSSCFGP_FHU_NTSEL_SSP			BIT8	//1b/x/x/x Update Time During Training Mode 
    #define U3IPSSCFGP_FHU_KIPCSEL_SSP			(BIT6 + BIT7)	//00b/x/x/x Gain2 During Tracking Mode 
    #define U3IPSSCFGP_FHU_P2EXT_SSP			(BIT3 + BIT4 + BIT5)	//010b/x/x/x P2 Exit Latency
    #define U3IPSSCFGP_FHU_P1EXT_SSP			(BIT0 + BIT1 + BIT2)	//110b/x/x/x P1 Exit Latency
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS20		0x0AE	//SSIP_PORT_EPHY_Control_Registers20
    #define U3IPSSCFGP_FHU_COMPVCMSEL			(BIT14 + BIT15)	//01b/x/x/x USB3TPLL Vcont Comparator Comman Mode Voltage Setting
    #define U3IPSSCFGP_FHU_TPLLCPISEL			(BIT11 + BIT12 + BIT13)	//011b/x/x/x TPLL Charge Pump Current Setting
    #define U3IPSSCFGP_FHU_TPLLRSEL			(BIT8 + BIT9 + BIT10)	//011b/x/x/x TPLL Loop Filter Resistance Setting
    #define U3IPSSCFGP_LFPSC_RX8LI_SS			BIT7	//0/x/x/x Indicate 8 LI Receivied
    #define U3IPSSCFGP_LFPSC_RX8TS2_SS			BIT6	//0/x/x/x Indicate 8 TS2 Receivied
    #define U3IPSSCFGP_LFPSC_RX8TS1_SS			BIT5	//0/x/x/x Indicate 8 TS1 Receivied
    #define U3IPSSCFGP_LFPSC_LITMO_SS			BIT4	//0/x/x/x LI State Timeout Flage
    #define U3IPSSCFGP_LFPSC_TS2TMO_SS			BIT3	//0/x/x/x TS2 State Timeout Flage
    #define U3IPSSCFGP_LFPSC_TS1TMO_SS			BIT2	//0/x/x/x TS1 State Timeout Flage
    #define U3IPSSCFGP_R_TMOFCLR_SS			BIT1	//0/x/x/x Clear TMO Flage When Writing 1¡¯ B1
    #define U3IPSSCFGP_R_RETMOEN_SS			BIT0	//1b/x/x/x Enable Recovery-Entry 12ms Timeout Function
#define U3IPSSCFGP_SSIP_PORT_SUS_NEW_REG0		0x0B0	//SSIP_PORT_SUS_NEW_Register0
    #define U3IPSSCFGP_R_LFPSDYNEN_SS			BIT15	//0/x/x/1b LFPSC Detect Rxlfps Counter Dynamic Clock Enable
    #define U3IPSSCFGP_R_DFPU2WKEN_SS			BIT14	//0/x/x/x DFP Will Wake Up In U2 When Device Disconnect
    #define U3IPSSCFGP_R_CBANKCLR_SS			BIT13	//0/x/x/x Clear Calibration Result
    #define U3IPSSCFGP_R_DYNTPLLEN_SS			BIT12	//0/x/x/1b Enable Dynamic TPLL Function. 
    #define U3IPSSCFGP_R_CCDETEN_SS			BIT11	//0/x/x/x Use External CC Detect Result To Judge RCVDET Result
    #define U3IPSSCFGP_R_2RCVDETEN_SS			BIT10	//0/x/x/x EPHY 2 RCVDET Module Work At The Same Time When Link State In U2/U3
    #define U3IPSSCFGP_R_CBANKITV_SS			(BIT8 + BIT9)	//0/x/x/x FW Set CBANK Interval
    #define U3IPSSCFGP_R_CBANK_SS			0xF0	//0/x/x/x FW Set CBANK Value
    #define U3IPSSCFGP_R_CBANKSETEN_SS			BIT3	//0/x/x/x FW Set CBANK Enable
    #define U3IPSSCFGP_R_CBEN_SS			BIT2	//1b/x/x/x Enable TPLLPDB Reset CBANK Control
    #define U3IPSSCFGP_EPU_VCOMP			(BIT0 + BIT1)	//0/x/x/x US3TPLL Vcont Settle Down Area
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_NEW1_REG		0x0B2	//SSIP_PORT_EPHY_Control_NEW1_Register
    #define U3IPSSCFGP_FHU_EQBOOSTTUNE			BIT15	//0/x/x/x EQBOOST Auto Tune. 
    #define U3IPSSCFGP_FHU_CMP2ON			BIT14	//0/x/x/x CM-OP On At P2 State
    #define U3IPSSCFGP_FHU_TPLLVCOREG			(BIT11 + BIT12 + BIT13)	//100b/x/x/x VCO Regulator Voltage Fine Tune. 
    #define U3IPSSCFGP_FHU_EQTNHFVTH			(BIT8 + BIT9 + BIT10)	//101b/x/x/x Equalizer HF Tuning Threshold 
    #define U3IPSSCFGP_FHU_EQTNOPT			0xFF	//0/x/x/x Equalizer Tuning Function Options 
#define U3IPSSCFGP_SSIP_PORT_EPHY_CTL_NEW2_REG		0x0B4	//SSIP_PORT_EPHY_Control_NEW2_Register
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0B4_SS			(BIT13 + BIT14 + BIT15)	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_CBANKDETEN			BIT12	//0/x/x/x Detect CBANK[3:0]=4¡¯ B0 Or 4¡¯ B1
    #define U3IPSSCFGP_FHU_FDETEN			BIT11	//0/x/x/x PLL Locking Frequency Detector Enable
    #define U3IPSSCFGP_FHU_EQBOOST_SSP			(BIT8 + BIT9 + BIT10)	//101b/x/x/x LEQ Rs Boost Adjustment
    #define U3IPSSCFGP_FHU_EQBOOST_SS			(BIT5 + BIT6 + BIT7)	//101b/x/x/x LEQ Rs Boost Adjustment
    #define U3IPSSCFGP_FHU_TXSKEWFT			(BIT2 + BIT3 + BIT4)	//0/x/x/x Clock Skew Fine Tune
    #define U3IPSSCFGP_FHU_TCPOSSETEN			BIT1	//0/x/x/x Type-C Channel Set Enable 
    #define U3IPSSCFGP_FHU_TCPOSSET			BIT0	//0/x/x/x Type-C Channel Set Enable 
#define U3IPSSCFGP_SSIP_PORT_SUS_RCVDET		0x0B6	//SSIP_PORT_SUS_RCVDET
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0B6_SS			0xF800	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_UXLFPSEXTENSUS_SS			BIT10	//0/x/x/x Enable Extending UX LFPS EXIT (T12-T11) Min To 600ns For Simultaneous Ux In Sus Domain
    #define U3IPSSCFGP_R_TPYEA_SEL_SS			BIT9	//0/x/x/x TYPE-A Port Lane Selection
    #define U3IPSSCFGP_R_TPYEA_EN_SS			BIT8	//0/x/x/x Enable TYPE-A Selection
    #define U3IPSSCFGP_R_RCVDET_CHK_PARM_SS			0xFF	//C8h/x/x/x Receiver Detection Check Parameter
#define U3IPSSCFGP_SSIP_PORT_SUS_EPHY_TEST_CTL		0x0B8	//SSIP_PORT_SUS EPHY Test Control
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0B8_SS			0xFC00	//0/x/x/x Reserved
    #define U3IPSSCFGP_R_FDETEN_SS			BIT9	//1b/x/x/x PLL Locking Frequency Detector Enable
    #define U3IPSSCFGP_R_GEN2EN_SET_SS			BIT8	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_RCVDETBEN_SET_SS			BIT7	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_RCVDETAEN_SET_SS			BIT6	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_RCVDETBPDB_SET_SS			BIT5	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_RCVDETAPDB_SET_SS			BIT4	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_TXLFPS_SET_SS			BIT3	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_RXHZ_SET_SS			BIT2	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_TXHZ_SET_SS			BIT1	//0/x/x/x When R_USB31_TST_MODE =1
    #define U3IPSSCFGP_R_USB31_TST_MODE_SS			BIT0	//0/x/x/x USB3.1 EPHY Test Mode Enable
#define U3IPSSCFGP_SSIP_PORT_SUS_EPHY_TEST_STA		0x0BA	//SSIP_PORT_SUS EPHY Test Status
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0BA_SS			0xFF80	//0/x/x/x Reserved
    #define U3IPSSCFGP_EPU_CBANKERROR			BIT6	//0/x/x/x TPLL CBANK[3:0] ERROR Flag
    #define U3IPSSCFGP_EPU_FREQERR			BIT5	//0/x/x/x PLL Un-Locked Flag
    #define U3IPSSCFGP_EPU_LFPSDET			BIT4	//0/x/x/x EPHY LFPSDET Output
    #define U3IPSSCFGP_EPU_RCVDETPA			BIT3	//0/x/x/x EPHY RCVDETP Of A Side Result Output
    #define U3IPSSCFGP_EPU_RCVDETNA			BIT2	//0/x/x/x EPHY RCVDETN Of A Side Result Output
    #define U3IPSSCFGP_EPU_RCVDETPB			BIT1	//0/x/x/x EPHY RCVDETP Of B Side Result Output
    #define U3IPSSCFGP_EPU_RCVDETNB			BIT0	//0/x/x/x EPHY RCVDETN Of B Side Result Output
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS1		0x0BC	//SSIP_PORT_NEW_EPHY_Control_Registers1
    #define U3IPSSCFGP_FHU_TXEIDLESETEN			BIT15	//0/x/x/x External Register of TX Electrical Idle Register Set
    #define U3IPSSCFGP_FHU_RCV_HBW			BIT14	//0/x/x/x RCV HBW Option For VGA/BUF/VGA_BUF Respectively
    #define U3IPSSCFGP_FHU_RCVEQ_POW			(BIT12 + BIT13)	//0/x/x/x RCV EQ Power Consumption Tuning
    #define U3IPSSCFGP_FHU_LFPSVTH_NEW			(BIT9 + BIT10 + BIT11)	//010b/x/x/x LFPS Detection Threshold
    #define U3IPSSCFGP_FHU_TDNCIS_DATA_NEW			0x1F0	//01011b/x/x/x TX De-Emphasis Set
    #define U3IPSSCFGP_FHU_TXSW			(BIT2 + BIT3)	//11b/x/x/x Tx Output Swing Control Set
    #define U3IPSSCFGP_FHU_TXPWRSW			(BIT0 + BIT1)	//11b/x/x/x TX Power Supply Switch
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS2		0x0BE	//SSIP_PORT_NEW_EPHY_Control_Registers2
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0BE_SS			0xF000	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_EQTNMODE_NEW_HI			0xF00	//1110b/x/x/x External Register of Equalizer tuning mode select
    #define U3IPSSCFGP_FHU_EQTNMODE_NEW_LO			0xFF	//10000001b/x/x/x External Register of Equalizer tuning mode select
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS3		0x0C0	//SSIP_PORT_NEW_EPHY_Control_Registers3
    #define U3IPSSCFGP_FHU_HFSET_NEW			0xF800	//11111b/x/x/x LEQ HF Gain Initial Or Set Value
    #define U3IPSSCFGP_FHU_DCSET_NEW			0x7C0	//11111b/x/x/x LEQ DC Gain Initial Or Set Value
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0C0_SS			BIT5	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_EQTNVTH_NEW			0x1F	//01111b/x/x/x Equalizer Tuning Threshold (CDR Input Eye opening reference) 
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS4		0x0C2	//SSIP_PORT_NEW_EPHY_Control_Registers4
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0C2_SS			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_W2SET_NEW			0x7C00	//00000b/x/x/x DFE Weight2 Initial Or Set Value
    #define U3IPSSCFGP_FHU_W1SET_NEW			0x3E0	//00000b/x/x/x DFE Weight1 Initial Or Set Value
    #define U3IPSSCFGP_FHU_OSSET_NEW			0x1F	//00000b/x/x/x LEQ Offset Initial Or Set Value
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS5		0x0C4	//SSIP_PORT_NEW_EPHY_Control_Registers5
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0C4_SS			BIT15	//0/x/x/x Reserved
    #define U3IPSSCFGP_EPU_OSOUT_NEW			0x7C00	//0/x/x/x LEQ Weight2 Output
    #define U3IPSSCFGP_EPU_HFOUT_NEW			0x3E0	//0/x/x/x LEQ HF Gain Output
    #define U3IPSSCFGP_EPU_DCOUT_NEW			0x1F	//0/x/x/x LEQ DC Gain Output
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS6		0x0C6	//SSIP_PORT_NEW_EPHY_Control_Registers6
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0C6_SS			0xFC00	//0/x/x/x Reserved
    #define U3IPSSCFGP_EPU_W2OUT_NEW			0x3E0	//0/x/x/x LEQ Offset Output
    #define U3IPSSCFGP_EPU_W1OUT_NEW			0x1F	//0/x/x/x LEQ Weight1 Output
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS7		0x0C8	//SSIP_PORT_NEW_EPHY_Control_Registers7
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0C8_SS			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_BPFBW			0x3C00	//0/x/x/x PI Bandwidth Tuning
    #define U3IPSSCFGP_FHU_CKBUFSEL_CDR			(BIT8 + BIT9)	//0/x/x/x PI Clock Buffer Selection (00)
    #define U3IPSSCFGP_FHU_ABCSEL_CDR			(BIT6 + BIT7)	//0/x/x/x Loop Bandwidth Mode Selection (00)
    #define U3IPSSCFGP_FHU_CDR_VT_SW			BIT5	//1b/x/x/x CDR IV Control Source Select
    #define U3IPSSCFGP_FHU_RCVPDSEL			BIT4	//1b/x/x/x RCV Power Off Method
    #define U3IPSSCFGP_FHU_VCOPDSEL			BIT3	//0/x/x/x VCO Power Off Method At P1
    #define U3IPSSCFGP_FHU_IVCPSEL_NEW			(BIT0 + BIT1 + BIT2)	//0/x/x/x IV Gain Select
#define U3IPSSCFGP_SSIP_PORT_NEW_EPHY_CTL_REGS8		0x0CA	//SSIP_PORT_NEW_EPHY_Control_Registers8
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0CA_SS			0xFFF0	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_RTNRXSET			0xF	//1000b/x/x/x Manual Setting Of RX Termination  value
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_1_Z1		0x0CC	//SSIP_PORT_PHYLS_Pattern_Generation_Register_1
    #define U3IPSSCFGP_R_USRPTN_15_0_SS			0xFFFF	//0/x/x/x User Defined Pattern Byte 0 And 1
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_2_Z1		0x0CE	//SSIP_PORT_PHYLS_Pattern_Generation_Register_2
    #define U3IPSSCFGP_R_USRPTN_31_16_SS			0xFFFF	//0/x/x/x User Defined Pattern Byte 2 And 3
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_3_Z1		0x0D0	//SSIP_PORT_PHYLS_Pattern_Generation_Register_3
    #define U3IPSSCFGP_R_USRPTN_47_32_SS			0xFFFF	//0/x/x/x User Defined Pattern Byte4 And 5
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_4		0x0D2	//SSIP_PORT_PHYLS_Pattern_Generation_Register_4
    #define U3IPSSCFGP_R_USRPTN_63_48_SS			0xFFFF	//0/x/x/x User Defined Pattern Byte6 And 7
#define U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_5		0x0D4	//SSIP_PORT_PHYLS_Pattern_Generation_Register_5
    #define U3IPSSCFGP_R_USRPTN_79_64_SS			0xFFFF	//0/x/x/x User Defined Pattern Byte8 And 9
#define U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_D6		0x0D6	//SSIP_PORT_SUS_Reserved_D6
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0D6_SS			0xFFE0	//0/x/x/x Reserved
    #define U3IPSSCFGP_FHU_TDNCIS_LFPS_NEW			0x1F	//00100b/x/x/x TX Swing for LPFS
#define U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_D8		0x0D8	//SSIP_PORT_SUS_Reserved_D8
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0D8_SS			0xFFFF	//FFFFh/x/x/x Reserved
#define U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_DA		0x0DA	//SSIP_PORT_SUS_Reserved_DA
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0DA_SS			0xFFFF	//0/x/x/x Reserved
#define U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_DC		0x0DC	//SSIP_PORT_SUS_Reserved_DC
    #define U3IPSSCFGP_RSVU3IP_SSCFG_P_0DC_SS			0xFFFF	//FFFFh/x/x/x Reserved
//OPTCFG_MCU
#define OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_CTL		0x08	//MCU Instruction Auto-fill Control
    #define OPTCFGMCU_RESERVED			0xFE	//0/R/x/x Reserved
    #define OPTCFGMCU_INST_AUTOFILL_EN			BIT0	//0/x/x/x MCU Instruction Auto-Fill Enable
#define OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_STA		0x09	//MCU Instruction Auto-fill Status
    #define OPTCFGMCU_RESERVED_Z1			0xFE	//0/R/x/x Reserved
    #define OPTCFGMCU_INST_AUTOFILL_DONE			BIT0	//0/x/x/x MCU Instruction Auto-Fill Done
#define OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_LEN		0x0A	//MCU Instruction Auto-fill Length
    #define OPTCFGMCU_RESERVED_Z2			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGMCU_INST_AUTOFILL_LENGTH			0x1FFF	//0/x/x/x MCU Instruction Auto-Fill Length
#define OPTCFGMCU_START_ADR_OF_AUTO_FILL_INSTRUCTION		0x0C	//Start Address of Auto-fill Instruction
    #define OPTCFGMCU_INST_AUTOFILL_SADDR			0xFFFFFFFF	//0/x/x/x Start Address Of Auto-Fill Instruction
#define OPTCFGMCU_HUB2_0_8051_FW_DOWNLOAD_CTL		0x10	//Hub2.0 8051 Firmware Download Control
    #define OPTCFGMCU_RESERVED_Z3			0xFC	//0/R/x/x Reserved
    #define OPTCFGMCU_HUB2_DMA_EN			BIT1	//0/0/x/x Hub2.0 8051 Firmware Download Enable
    #define OPTCFGMCU_HUB2_NON_REPLACE			BIT0	//0/0/x/x Hub2.0 8051 Cirmware Non-Replace
#define OPTCFGMCU_HUB2_0_8051_FW_DOWNLOAD_STA		0x11	//Hub2.0 8051 Firmware Download Status
    #define OPTCFGMCU_RESERVED_Z4			0xFE	//0/R/x/x Reserved
    #define OPTCFGMCU_HUB2_DMA_DONE			BIT0	//0/0/x/x Hub2.0 8051 Firmware Download Done
#define OPTCFGMCU_HUB2_0_8051_FW_DOWNLOAD_LEN		0x12	//Hub2.0 8051 Firmware Download Length
    #define OPTCFGMCU_RESERVED_Z5			(BIT14 + BIT15)	//0/R/x/x Reserved
    #define OPTCFGMCU_HUB2_DMA_LEN			0x3FFF	//0/x/x/x Hub2.0 8051 Firmware Download Length
#define OPTCFGMCU_LOWER_BASE_ADR_OF_HUB2_0_8051_FW_DOWNLOAD		0x14	//Lower Base Address of Hub2.0 8051 Firmware Download
    #define OPTCFGMCU_HUB2_DMA_LBASE			0xFFFFFFFC	//0/0/x/x Lower Start Address Of  Hub2.0 8051 Firmware Download In System Memory
    #define OPTCFGMCU_RESERVED_Z6			(BIT0 + BIT1)	//0/R/x/x Reserved
#define OPTCFGMCU_UPPER_BASE_ADR_OF_HUB2_0_8051_FW_DOWNLOAD		0x18	//Upper Base Address of Hub2.0 8051 Firmware Download
    #define OPTCFGMCU_HUB2_DMA_UBASE			0xFFFFFFFF	//0/0/x/x Upper Start Address Of  Hub2.0 8051 Firmware Download In System Memory
#define OPTCFGMCU_MCU_SW_RESET		0x20	//MCU Software Reset
    #define OPTCFGMCU_RESERVED_Z7			0xFE	//0/R/x/x Reserved
    #define OPTCFGMCU_MCU_SW_RST			BIT0	//0b/0b/x/x MCU Software Reset Controlled By BIOS
#define OPTCFGMCU_BASE_ADR_OF_MCU_FW_IN_SYSTEM_MEM_LOW		0x28	//Base Address of MCU Firmware in System Memory Low
    #define OPTCFGMCU_MCU_INSTDAT_SYSMEM_BASE_LO			0xFFFFFFC0	//0/x/x/x Base Address Of MCU Firmware (Instruction And Data) Space In System Memory (Bit 47:6)
    #define OPTCFGMCU_RESERVED_Z8			0x3F	//0/R/x/x Reserved
#define OPTCFGMCU_BASE_ADR_OF_MCU_FW_IN_SYSTEM_MEM_HIGH		0x2C	//Base Address of MCU Firmware in System Memory High
    #define OPTCFGMCU_RESERVED_Z9			0xFFFF0000	//0/R/x/x Reserved
    #define OPTCFGMCU_MCU_INSTDAT_SYSMEM_BASE_HI			0xFFFF	//0/x/x/x Base Address Of MCU Firmware (Instruction And Data) Space In System Memory (Bit 47:6)
#define OPTCFGMCU_MCU_DATA_AUTO_FILL_LEN		0x30	//MCU Data Auto-fill Length
    #define OPTCFGMCU_RESERVED_Z10			0xFFFFC000	//0/R/x/x Reserved
    #define OPTCFGMCU_DATA_AUTOFILL_LENGTH			0x3FFF	//0/x/x/x MCU Data Auto-Fill Length
#define OPTCFGMCU_START_ADR_OF_AUTO_FILL_DATA		0x34	//Start Address of Auto-fill Data
    #define OPTCFGMCU_DATA_AUTOFILL_SADDR			0xFFFFFFFF	//0/x/x/x Start Address Of Auto-Fill Data
#define OPTCFGMCU_MCU_CLK_DIVIDER_PARAMETER		0x38	//MCU Clock Divider Parameter
    #define OPTCFGMCU_RESERVED_Z11			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define OPTCFGMCU_MCU_SUSCLK_DIV			0x1F	//Ah/Ah/x/x Parameterfor 25M Clock Divider
#endif
