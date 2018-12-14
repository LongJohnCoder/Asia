//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_D18F0_xHCICtrl_R103_A0.doc.
#ifndef IRS_CND003_D18F0_XHCICTRL_R103_A0_H
#define IRS_CND003_D18F0_XHCICTRL_R103_A0_H
// D18F0
#define CND003_D18F0_VID 0x0 // Vendor ID
    #define CND003_D18F0_VID_Z1 CND003_D18F0_VID // HwInit/1106h/x/x Vendor ID
#define CND003_D18F0_DID 0x2 // Device ID
    #define CND003_D18F0_DEVID CND003_D18F0_DID // 9203h/9203h/x/x Device ID Code
#define CND003_D18F0_PCI_CMD 0x4 // PCI Command
    #define CND003_D18F0_INTRDIS   BIT10   // 0/0/x/x Interrupt Disable
    #define CND003_D18F0_SERREN    BIT8    // 0/0/x/x SERR Enable
    #define CND003_D18F0_RPTYERR   BIT6    // 0/0/x/x Parity Error Response
    #define CND003_D18F0_MWRMEN    BIT4    // 0/0/x/x Memory Write and Invalidate
    #define CND003_D18F0_BMASTREN  BIT2    // 0/0/x/x Bus Master
    #define CND003_D18F0_MMSPACE   BIT1    // 0/0/x/x Memory Space
    #define CND003_D18F0_IOSPACE   BIT0    // 0/0/x/x I/O Space
#define CND003_D18F0_PCI_STA 0x6 // PCI Status
    #define CND003_D18F0_DPRTYERR  BIT15                   // 0/0/x/x Detected Parity Error
    #define CND003_D18F0_SSYSERR   BIT14                   // 0/0/x/x Signaled System Error
    #define CND003_D18F0_TMABORTS  BIT13                   // 0/0/x/x Received Master Abort (Except Special Cycle)
    #define CND003_D18F0_TTABORTR  BIT12                   // 0/0/x/x Received Target Abort
    #define CND003_D18F0_STABORT   BIT11                   // 0/0/x/x Signaled Target Abort
    #define CND003_D18F0_DEVSELTM  (BIT9 + BIT10)          // 0/0/x/x DEVSEL# Timing
    #define CND003_D18F0_MDPRTYERR BIT8                    // 0/0/x/x Master Data Parity Error
    #define CND003_D18F0_INTRSTS   BIT3                    // 0/0/x/x Interrupt Status
#define CND003_D18F0_REV_ID 0x8 // Revision ID
    #define CND003_D18F0_REVID CND003_D18F0_REV_ID // 00h/0/x/x Revision ID
#define CND003_D18F0_CLASS_CODE 0x9 // Class Code
    #define CND003_D18F0_CLSCODE CND003_D18F0_CLASS_CODE // 0C0330h/0C0330h/x/x Class Code for USB3.0 xHCI Host Controller
#define CND003_D18F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_D18F0_CACHLINE CND003_D18F0_CACHE_LINE_SIZE // 0/0/x/x Cache Line Size
#define CND003_D18F0_LATENCY_TIMER 0xD // Latency Timer
    #define CND003_D18F0_LATTM CND003_D18F0_LATENCY_TIMER // 0/0/x/x Latency Timer
#define CND003_D18F0_HDR_TYPE 0xE // Header Type
    #define CND003_D18F0_HDTYPE CND003_D18F0_HDR_TYPE // 00h/0/x/x Header Type
#define CND003_D18F0_BIST 0xF // Built In Self Test (BIST)
    #define CND003_D18F0_BIST_Z1 CND003_D18F0_BIST // 0/0/x/x BIST
#define CND003_D18F0_XHCI_MEM_MAPPED_IO_LOW_BASE_ADR 0x10 // xHCI Memory Mapped I/O Low Base Address
    #define CND003_D18F0_BASEADDR0_LO  0xFFFFF000      // 0/0/x/x xHCI Memory Mapped I/O Registers Low Base Address
    #define CND003_D18F0_BARTYPE0      (BIT1 + BIT2)   // 10b/10b/x/x Base Address Type
#define CND003_D18F0_XHCI_MEM_MAPPED_IO_HIGH_BASE_ADR 0x14 // xHCI Memory Mapped I/O High Base Address
    #define CND003_D18F0_BASEADDR0_HI CND003_D18F0_XHCI_MEM_MAPPED_IO_HIGH_BASE_ADR // 0/x/x/x xHCI Memory Mapped I/O Registers High Base Address
#define CND003_D18F0_SVID 0x2C // Subsystem Vendor ID
    #define CND003_D18F0_SYSVID CND003_D18F0_SVID // 1106h/1106h/x/x Subsystem Vendor ID
#define CND003_D18F0_SSID 0x2E // Subsystem ID
    #define CND003_D18F0_SUBSID CND003_D18F0_SSID // 9203h/9203h/x/x Subsystem ID
#define CND003_D18F0_CAP_PTR 0x34 // Capability Pointer
    #define CND003_D18F0_CAPPTR CND003_D18F0_CAP_PTR // 80h/80h/x/x Capability Pointer
#define CND003_D18F0_INTR_LINE 0x3C // Interrupt Line
    #define CND003_D18F0_INTLN CND003_D18F0_INTR_LINE // 0/0/x/x USB Interrupt Routing
#define CND003_D18F0_INTR_PIN 0x3D // Interrupt Pin
    #define CND003_D18F0_INTPIN CND003_D18F0_INTR_PIN // 01h/01h/x/x Interrupt Pin
#define CND003_D18F0_XHCI_OPTION_BITS_RX40_XHCOPTRX40 0x40 // xHCI Option Bits Rx40 (XHCOPTRX40)
    #define CND003_D18F0_XHCI_DBG_SEL CND003_D18F0_XHCI_OPTION_BITS_RX40_XHCOPTRX40 // 0/0/x/x xHCI Debug Signal Group Select Low 32 Bits
#define CND003_D18F0_XHCI_OPTION_BITS_RX41_XHCOPTRX41 0x41 // xHCI Option Bits Rx41 (XHCOPTRX41)
    #define CND003_D18F0_TOP_DBG_SEL CND003_D18F0_XHCI_OPTION_BITS_RX41_XHCOPTRX41 // 0/0/x/x TOP Debug Signal Group Select
#define CND003_D18F0_XHCI_OPTION_BITS_RX42_XHCOPTRX42 0x42 // xHCI Option Bits Rx42 (XHCOPTRX42)
    #define CND003_D18F0_XHCI_DBG_SEL2 CND003_D18F0_XHCI_OPTION_BITS_RX42_XHCOPTRX42 // 0/0/x/x xHCI Debug Signal Group Select High 32 Bits
#define CND003_D18F0_XHCI_OPTION_BITS_RX43_XHCOPTRX43 0x43 // xHCI Option Bits Rx43 (XHCOPTRX43)
    #define CND003_D18F0_XHCI_DBG_SEL_EXT  BIT4                    // 0/0/x/x xHCI_DBG_SEL Extend to 512 Groups
    #define CND003_D18F0_CPU_CND003_OPTCFG        BIT0                    // 0/0/x/x CPU Configure Optional Register Enable (BIOS Configure)
#define CND003_D18F0_XHCI_OPTION_BITS_RX44_XHCOPTRX44 0x44 // xHCI Option Bits Rx44 (XHCOPTRX44)
    #define CND003_D18F0_FLRCAPWE      BIT4                    // 0/0/x/x Reserved
    #define CND003_D18F0_SVID_SID_SEL  BIT0                    // 0/0/x/x Reserved
#define CND003_D18F0_XHCI_OPTION_BITS_RX45_XHCOPTRX45 0x45 // xHCI Option Bits Rx45 (XHCOPTRX45)
    #define CND003_D18F0_DID_RID_LOCK  BIT4                    // 0/0/x/x Reserved
    #define CND003_D18F0_VID_LOCK      BIT0                    // 0/0/x/x Reserved
#define CND003_D18F0_XHCI_SYS_ENTER_SUSPEND_STA 0x46 // xHCI System Enter Suspend Status
    #define CND003_D18F0_SWSYSTEMSUS   BIT0    // 0/x/x/x xHCI System Enter Suspend (S3/S4/S5) Status
#define CND003_D18F0_XHCI_MIRROR_REG_FOR_SW_WRITE_XHCI_OPTION_RXE0_EF_INTR_STA 0x47 // xHCI Mirror Register for SW Write XHCI Option RxE0~EF Interrupt Status
    #define CND003_D18F0_SW_WR_INT_STS BIT0    // 0/x/x/x xHCI Mirror Register for SW Write XHCI Option RxE0~EF Status
// D0F3
#define D0F3_XHCI_CRCR_MIRROR_LOW_REG 0x48 // xHCI CRCR Mirror Low Register
    #define D0F3_CRCR_MIRROR_LO D0F3_XHCI_CRCR_MIRROR_LOW_REG // 0/x/x/x xHCI CRCR Mirror Low Register
#define D0F3_XHCI_CRCR_MIRROR_HIGH_REG 0x4C // xHCI CRCR Mirror High Register
    #define D0F3_CRCR_MIRROR_HI D0F3_XHCI_CRCR_MIRROR_HIGH_REG // 0/x/x/x xHCI CRCR Mirror High Register
#define D0F3_XHCI_MCU_FW_VER 0x50 // xHCI MCU Firmware Version
    #define D0F3_FW_VERSION D0F3_XHCI_MCU_FW_VER // 0/x/x/x xHCI MCU Firmware Version
// CND003_D18F0
#define CND003_D18F0_XHCI_OPTION_BITS_RX54_XHCOPTRX54 0x54 // xHCI Option Bits Rx54 (XHCOPTRX54)
    #define CND003_D18F0_FWNOTE CND003_D18F0_XHCI_OPTION_BITS_RX54_XHCOPTRX54 // 0/0/x/x Used for FW to Store Some Internal Information
#define CND003_D18F0_XHCI_OPTION_BITS_RX55_XHCOPTRX55 0x55 // xHCI Option Bits Rx55 (XHCOPTRX55)
    #define CND003_D18F0_R_PLLOK_SEL   (BIT1 + BIT2)   // 0/0/x/x USB3.0/USB3.1 PHY PLLOK Selection
    #define CND003_D18F0_SUSCLKSEL     BIT0            // 1b/1b/x/x Suspend Clock Selection
#define CND003_D18F0_XHCI_OPTION_BITS_RX56_XHCOPTRX56 0x56 // xHCI Option Bits Rx56 (XHCOPTRX56)
    #define CND003_D18F0_R_XHCI_PTN_DBG_SEL_G1 0xF0    // 0/0/x/x xHCI PTN Top Debug Signal G1 Selection
    #define CND003_D18F0_R_XHCI_PTN_DBG_SEL_G0 0xF     // 0/0/x/x XHCI PTN Top Debug Signal G0 Selection
#define CND003_D18F0_XHCI_OPTION_BITS_RX57_XHCOPTRX56 0x57 // xHCI Option Bits Rx57 (XHCOPTRX56)
    #define CND003_D18F0_R_XHCI_PTN_DBG_SEL_G3 0xF0    // 0/0/x/x xHCI PTN Top Debug Signal G3 Selection
    #define CND003_D18F0_R_XHCI_PTN_DBG_SEL_G2 0xF     // 0/0/x/x xHCI PTN Top Debug Signal G2 Selection
#define CND003_D18F0_XHCI_OPTION_BITS_RX58_XHCOPTRX54 0x58 // xHCI Option Bits Rx58 (XHCOPTRX54)
    #define CND003_D18F0_HSTTX5_DBG_SEL CND003_D18F0_XHCI_OPTION_BITS_RX58_XHCOPTRX54 // 0/0/x/x HSTTX5 Debug Signal Group Select
#define CND003_D18F0_XHCI_OPTION_BITS_RX59 0x59 // xHCI Option Bits Rx59
    #define CND003_D18F0_U2P5DISABLE   BIT4                    // 0/x/x/x USB2.0 Port 5 Disable
    #define CND003_D18F0_U2P4DISABLE   BIT3                    // 0/x/x/x USB2.0 Port 4 Disable
    #define CND003_D18F0_U2P3DISABLE   BIT2                    // 0/x/x/x USB2.0 Port 3 Disable
    #define CND003_D18F0_U2P2DISABLE   BIT1                    // 0/x/x/x USB2.0 Port 2 Disable
    #define CND003_D18F0_U2P1DISABLE   BIT0                    // 0/x/x/x USB2.0 Port 1 Disable
#define CND003_D18F0_XHCI_OPTION_BITS_RX5A 0x5A // xHCI Option Bits Rx5A
    #define CND003_D18F0_U31P2DISABLE  BIT4                    // 0/x/x/x USB3.1 Port 2 Disable
    #define CND003_D18F0_U31P1DISABLE  BIT3                    // 0/x/x/x USB3.1 Port 1 Disable
    #define CND003_D18F0_U3P3DISABLE   BIT2                    // 0/x/x/x USB3.0 Port 3 Disable
    #define CND003_D18F0_U3P2DISABLE   BIT1                    // 0/x/x/x USB3.0 Port 2 Disable
    #define CND003_D18F0_U3P1DISABLE   BIT0                    // 0/x/x/x USB3.0 Port 1 Disable
#define CND003_D18F0_XHCI_OPTION_BITS_RX5B 0x5B // xHCI Option Bits Rx5B
    #define CND003_D18F0_BIOSFWMSG CND003_D18F0_XHCI_OPTION_BITS_RX5B // 0/x/x/x BIOSFWMSG
#define CND003_D18F0_SVID_FOR_SW 0x5C // Subsystem Vendor ID For SW
    #define CND003_D18F0_SYSVID_OPT CND003_D18F0_SVID_FOR_SW // 1106h/1106h/x/x Subsystem Vendor ID (SW/FW can update)
#define CND003_D18F0_SSID_FOR_SW 0x5E // Subsystem ID For SW
    #define CND003_D18F0_SUBSID_OPT CND003_D18F0_SSID_FOR_SW // 9203h/9203h/x/x Subsystem ID (SW/FW can update)
#define CND003_D18F0_SERIAL_BUS_RELEASE_NUM_SBRN 0x60 // Serial Bus Release Number (SBRN)
    #define CND003_D18F0_SBRN CND003_D18F0_SERIAL_BUS_RELEASE_NUM_SBRN // 31h/31h/x/x Serial Bus Specification Release Number
#define CND003_D18F0_FRAME_LEN_ADJ_FLADJ 0x61 // Frame Length Adjustment (FLADJ)
    #define CND003_D18F0_NFC   BIT6    // 0/0/x/x No Frame Length Timing Capability (NFC)
    #define CND003_D18F0_FLADJ 0x3F    // 20h/20h/x/x Frame Length Timing Value
#define CND003_D18F0_DBESLD_AND_DBESL 0x62 // DBESLD and DBESL
    #define CND003_D18F0_DBESLD    0xF0    // 0/0h/x/x Default Best Effort Service Latency Deep
    #define CND003_D18F0_DBESL     0xF     // 0/0/x/x Default Best Effort Service Latency 
#define CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR 0x78 // xHCI Optional Bits Configuration Address
    #define CND003_D18F0_CND003_OPTCFGADDR    0xFFFFF     // 0/0/x/x xHCI Option Bits Configuration Address
#define CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA 0x7C // xHCI Optional Bits Configuration Data
    #define CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA_Byte0 0x7C
    #define CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA_Byte1 0x7D
    #define CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA_Byte2 0x7E
    #define CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA_Byte3 0x7F

    #define CND003_D18F0_CND003_OPTCFGDATA CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA // 0/0/x/x xHCI Option Bits Configuration Data
#define CND003_D18F0_PM_CAP_ID 0x80 // Power Management Capability ID
    #define CND003_D18F0_PMCAPID CND003_D18F0_PM_CAP_ID // 01h/01h/x/x Power Management Capability ID
#define CND003_D18F0_NEXT_ITEM_PTR_1 0x81 // Next Item Pointer 1
    #define CND003_D18F0_PMNXTPTR CND003_D18F0_NEXT_ITEM_PTR_1 // 90h/90h/x/x Next Item Pointer 1
#define CND003_D18F0_PM_CAP 0x82 // Power Management Capability
    #define CND003_D18F0_PMCAP CND003_D18F0_PM_CAP // F9C3h/F9C3h/x/x Power Management Capability
#define CND003_D18F0_PM_CAP_CTL_STA 0x84 // Power Management Capability Control / Status
    #define CND003_D18F0_PMESTATUS BIT15           // 0/0/x/x PME Status
    #define CND003_D18F0_PMEEN     BIT8            // 0/0/x/x PME Enable
    #define CND003_D18F0_PMSTATE   (BIT0 + BIT1)   // 00b/00b/x/11b Power State
#define CND003_D18F0_MSI_CAP_ID 0x90 // MSI Capability ID
    #define CND003_D18F0_MSIID CND003_D18F0_MSI_CAP_ID // 05h/05h/x/x MSI Capability ID
#define CND003_D18F0_NEXT_ITEM_PTR_2 0x91 // Next Item Pointer 2
    #define CND003_D18F0_MSINXTPTR CND003_D18F0_NEXT_ITEM_PTR_2 // A0h/A0h/x/x Next Item Pointer 2
#define CND003_D18F0_MSI_MSG_CTL 0x92 // MSI Message Control
    #define CND003_D18F0_MSIMSKCAP     BIT8                    // 0/0/x/x Per-vector Masking Capable
    #define CND003_D18F0_MSIADDR64CAP  BIT7                    // 1b/1/x/x 64 Bit Address Capable
    #define CND003_D18F0_MSIMLTEN      (BIT4 + BIT5 + BIT6)    // 0/0/x/x Multiple Message Enable
    #define CND003_D18F0_MSIMULCAP     (BIT1 + BIT2 + BIT3)    // 010b/010b/x/x Multiple Message Capable
    #define CND003_D18F0_MSIEN         BIT0                    // 0/0/x/x MSI Enable
#define CND003_D18F0_MSI_MSG_ADR_LOW 0x94 // MSI Message Address Low
    #define CND003_D18F0_MSIADDRLO 0xFFFFFFFC      // 0/0/x/x Message Address (Low 32 Bits).
#define CND003_D18F0_MSI_MSG_ADR_HIGH 0x98 // MSI Message Address High
    #define CND003_D18F0_MSIADDRHI CND003_D18F0_MSI_MSG_ADR_HIGH // 0/0/x/x Message Address (High 32 Bits)
#define CND003_D18F0_MSI_DATA 0x9C // MSI Data
    #define CND003_D18F0_MSIDATA CND003_D18F0_MSI_DATA // 0/0/x/x Message Data
#define CND003_D18F0_FUN_LEVEL_RESET_CAP_ID 0xA0 // Function Level Reset Capability ID
    #define CND003_D18F0_FLRID CND003_D18F0_FUN_LEVEL_RESET_CAP_ID // 13h/13h/x/x Function Level Reset Capability ID
#define CND003_D18F0_NEXT_ITEM_PTR_3 0xA1 // Next Item Pointer 3
    #define CND003_D18F0_FLRNXTPTR CND003_D18F0_NEXT_ITEM_PTR_3 // 00h/0/x/x Next Item Pointer 3
#define CND003_D18F0_FUN_LEVEL_RESET_CAP_LEN_AND_VER 0xA2 // Function Level Reset Capability Length and Version
    #define CND003_D18F0_FLRCAP    BIT9    // 1b/x/x/x FLR Capability
    #define CND003_D18F0_FLRTXPCAP BIT8    // 1b/x/x/x TXP Capability
    #define CND003_D18F0_FLRLENGTH 0xFF    // 06h/x/x/x Capability Length
#define CND003_D18F0_FUN_LEVEL_RESET_CTL_REG 0xA4 // Function Level Reset Control Register
    #define CND003_D18F0_FLRINIT   BIT0    // 0/x/x/x Initiate FLR
#define CND003_D18F0_FUN_LEVEL_RESET_STA_REG 0xA5 // Function Level Reset Status Register
    #define CND003_D18F0_FLRTXP    BIT0    // 0/x/x/x Transaction Pending (TXP)
#define CND003_D18F0_FW_TO_SW_MSG_DW0 0xB0 // FW to SW Message DW0
    #define CND003_D18F0_FWSWMSG0 CND003_D18F0_FW_TO_SW_MSG_DW0 // 0/0/x/x MCU FW Debug Message to SW DW0
#define CND003_D18F0_FW_TO_SW_MSG_DW1 0xB4 // FW to SW Message DW1
    #define CND003_D18F0_FWSWMSG1 CND003_D18F0_FW_TO_SW_MSG_DW1 // 0/0/x/x MCU FW Debug Message to SW DW1
#define CND003_D18F0_FW_TO_SW_MSG_DW2 0xB8 // FW to SW Message DW2
    #define CND003_D18F0_FWSWMSG2 CND003_D18F0_FW_TO_SW_MSG_DW2 // 0/0/x/x MCU FW Debug Message to SW DW2
#define CND003_D18F0_FW_TO_SW_MSG_DW3 0xBC // FW to SW Message DW3
    #define CND003_D18F0_FWSWMSG3 CND003_D18F0_FW_TO_SW_MSG_DW3 // 0/0/x/x MCU FW Debug Message to SW DW3
// USB3.0-MMIO
#define CND003_USB30MMIO_CAP_REGS_LEN_CAPLEN 0x0 // Capability Registers Length (CAPLENGTH)
    #define CND003_USB30MMIO_CAPLENGTH CND003_USB30MMIO_CAP_REGS_LEN_CAPLEN // 20h/20h/x/x Capability Registers Length
// USB3.0?MMIO
#define CND003_USB30MMIO_HC_IF_VER_NUM_HCIVER 0x2 // Host Controller Interface Version Number (HCIVERSION)
    #define CND003_USB30MMIO_HCIVERSION CND003_USB30MMIO_HC_IF_VER_NUM_HCIVER // 0110h/0110h/x/x Host Controller Interface Version Number
#define CND003_USB30MMIO_STRUCTURAL_PARAMS_1_HCSPARAMS1 0x4 // Structural Parameters 1 (HCSPARAMS1)
    #define CND003_USB30MMIO_MAXPORTS          0xFF000000  // 0Ah/0Ah/x/x Number of Ports (MaxPorts)
    #define CND003_USB30MMIO_HCSP1_RSVD_BIT_23 BIT23       // 0/x/x/x HCSPARAMS1 Reserved Bit 23
    #define CND003_USB30MMIO_HCSP1_RSVD_BIT_22 BIT22       // 0/x/x/x HCSPARAMS1 Reserved Bit 22
    #define CND003_USB30MMIO_HCSP1_RSVD_BIT_21 BIT21       // 0/x/x/x HCSPARAMS1 Reserved Bit 21
    #define CND003_USB30MMIO_HCSP1_RSVD_BIT_20 BIT20       // 0/x/x/x HCSPARAMS1 Reserved Bit 20
    #define CND003_USB30MMIO_HCSP1_RSVD_BIT_19 BIT19       // 0/x/x/x HCSPARAMS1 Reserved Bit 19
    #define CND003_USB30MMIO_MAXINTRS          0x7FF00     // 04h/04h/x/x Number of Interrupters (MaxIntrs)
    #define CND003_USB30MMIO_MAXSLOTS          0xFF        // 20h/20h/x/x Number of Device Slots (MaxSlots) 
#define CND003_USB30MMIO_STRUCTURAL_PARAMS_2_HCSPARAMS2 0x8 // Structural Parameters 2 (HCSPARAMS2)
    #define CND003_USB30MMIO_MAXSCRBUF_LO      0xF8000000  // 1Fh/1Fh/x/x Max Scratchpad Buffers (Max Scratchpad Bufs Lo)
    #define CND003_USB30MMIO_SPR               BIT26       // 1b/1b/x/x Scratchpad Restore (SPR)
    #define CND003_USB30MMIO_MAXSCRBUF_HI      0x3E00000   // 0/x/x/x Max Scratchpad Buffers (Max Scratchpad Bufs Hi)
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_20 BIT20       // 0/x/x/x HCSPARAMS2 Reserved Bit 20
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_19 BIT19       // 0/x/x/x HCSPARAMS2 Reserved Bit 19
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_18 BIT18       // 0/x/x/x HCSPARAMS2 Reserved Bit 18
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_17 BIT17       // 0/x/x/x HCSPARAMS2 Reserved Bit 17
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_16 BIT16       // 0/x/x/x HCSPARAMS2 Reserved Bit 16
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_15 BIT15       // 0/x/x/x HCSPARAMS2 Reserved Bit 15
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_14 BIT14       // 0/x/x/x HCSPARAMS2 Reserved Bit 14
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_13 BIT13       // 0/x/x/x HCSPARAMS2 Reserved Bit 13
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_12 BIT12       // 0/x/x/x HCSPARAMS2 Reserved Bit 12
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_11 BIT11       // 0/x/x/x HCSPARAMS2 Reserved Bit 11
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_10 BIT10       // 0/x/x/x HCSPARAMS2 Reserved Bit 10
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_9  BIT9        // 0/x/x/x HCSPARAMS2 Reserved Bit 9
    #define CND003_USB30MMIO_HCSP2_RSVD_BIT_8  BIT8        // 0/x/x/x HCSPARAMS2 Reserved Bit 8
    #define CND003_USB30MMIO_MAXERST           0xF0        // 3h/3h/x/x Event Ring Segment Table Max (ERST Max)
    #define CND003_USB30MMIO_IST               0xF         // 1h/1h/x/x Isochronous Scheduling Threshold (IST)
#define CND003_USB30MMIO_STRUCTURAL_PARAMS_3_HCSPARAMS3 0xC // Structural Parameters 3 (HCSPARAMS3)
    #define CND003_USB30MMIO_U2DEVEXTLT        0xFFFF0000  // 00E7h/00E7h/x/x U2 Device Exit Latency
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_15 BIT15       // 0/x/x/x HCSPARAMS3 Reserved Bit 15
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_14 BIT14       // 0/x/x/x HCSPARAMS3 Reserved Bit 14
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_13 BIT13       // 0/x/x/x HCSPARAMS3 Reserved Bit 13
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_12 BIT12       // 0/x/x/x HCSPARAMS3 Reserved Bit 12
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_11 BIT11       // 0/x/x/x HCSPARAMS3 Reserved Bit 11
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_10 BIT10       // 0/x/x/x HCSPARAMS3 Reserved Bit 10
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_9  BIT9        // 0/x/x/x HCSPARAMS3 Reserved Bit 9
    #define CND003_USB30MMIO_HCSP3_RSVD_BIT_8  BIT8        // 0/x/x/x HCSPARAMS3 Reserved Bit 8
    #define CND003_USB30MMIO_U1DEVEXTLT        0xFF        // 04h/04h/x/x U1 Device Exit Latency
#define CND003_USB30MMIO_CAP_PARAMS_1_HCCPARAMS1 0x10 // Capability Parameters 1 (HCCPARAMS1)
    #define CND003_USB30MMIO_XECP          0xFFFF0000  // 0020h/0020h/x/x xHCI Extended Capabilities Pointer (xECP) 
    #define CND003_USB30MMIO_MAXPSASIZE    0xF000      // 5h/5h/x/x Maximum Primary Stream Array Size (MaxPSASize)
    #define CND003_USB30MMIO_CFC           BIT11       // 1b/1b/x/x Contiguous Frame ID Capability (CFC)
    #define CND003_USB30MMIO_SEC           BIT10       // 1b/1b/x/x Stopped EDLTA Capability (SEC)
    #define CND003_USB30MMIO_SPC           BIT9        // 1b/1b/x/x Stopped ? Short Packet Capability (SPC)
    #define CND003_USB30MMIO_PAE           BIT8        // 1b/1b/x/x Parse All Event Data (PAE)
    #define CND003_USB30MMIO_NSS           BIT7        // 1b/1b/x/x No Secondary SID Support (NSS)
    #define CND003_USB30MMIO_LTC           BIT6        // 1b/1b/x/x Latency Tolerance Messaging Capability (LTC)
    #define CND003_USB30MMIO_LHRC          BIT5        // 1b/1b/x/x Light HC Reset Capability (LHRC)
    #define CND003_USB30MMIO_PIND          BIT4        // 0/0/x/x Port Indicators (PIND)
    #define CND003_USB30MMIO_PPC           BIT3        // 0/0/x/x Port Power Control (PPC)
    #define CND003_USB30MMIO_CSZ           BIT2        // 0/0/x/x Context Size (CSZ)
    #define CND003_USB30MMIO_BNC           BIT1        // 1b/1b/x/x BW Negotiation Capability (BNC)
    #define CND003_USB30MMIO_AC64          BIT0        // 1b/1b/x/x 64-bit Addressing Capabilitya (AC64)
#define CND003_USB30MMIO_DOORBELL_OFS_DBOFF 0x14 // Doorbell Offset (DBOFF)
    #define CND003_USB30MMIO_DBOFF 0xFFFFFFFC      // 40h/40h/x/x Doorbell Array Offset
#define CND003_USB30MMIO_RUNTIME_REG_SPACE_OFS_RTSOFF 0x18 // Runtime Register Space Offset (RTSOFF)
    #define CND003_USB30MMIO_RTSOFF    0xFFFFFFE0  // 10h/10h/x/x Runtime Register Space Offset
#define CND003_USB30MMIO_CAP_PARAMS_2_HCCPARAMS2 0x1C // Capability Parameters 2 (HCCPARAMS2)
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_31 BIT31   // 0/x/x/x HCCPARAMS2 Reserved Bit 31
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_30 BIT30   // 0/x/x/x HCCPARAMS2 Reserved Bit 30
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_29 BIT29   // 0/x/x/x HCCPARAMS2 Reserved Bit 29
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_28 BIT28   // 0/x/x/x HCCPARAMS2 Reserved Bit 28
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_27 BIT27   // 0/x/x/x HCCPARAMS2 Reserved Bit 27
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_26 BIT26   // 0/x/x/x HCCPARAMS2 Reserved Bit 26
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_25 BIT25   // 0/x/x/x HCCPARAMS2 Reserved Bit 25
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_24 BIT24   // 0/x/x/x HCCPARAMS2 Reserved Bit 24
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_23 BIT23   // 0/x/x/x HCCPARAMS2 Reserved Bit 23
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_22 BIT22   // 0/x/x/x HCCPARAMS2 Reserved Bit 22
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_21 BIT21   // 0/x/x/x HCCPARAMS2 Reserved Bit 21
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_20 BIT20   // 0/x/x/x HCCPARAMS2 Reserved Bit 20
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_19 BIT19   // 0/x/x/x HCCPARAMS2 Reserved Bit 19
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_18 BIT18   // 0/x/x/x HCCPARAMS2 Reserved Bit 18
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_17 BIT17   // 0/x/x/x HCCPARAMS2 Reserved Bit 17
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_16 BIT16   // 0/x/x/x HCCPARAMS2 Reserved Bit 16
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_15 BIT15   // 0/x/x/x HCCPARAMS2 Reserved Bit 15
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_14 BIT14   // 0/x/x/x HCCPARAMS2 Reserved Bit 14
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_13 BIT13   // 0/x/x/x HCCPARAMS2 Reserved Bit 13
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_12 BIT12   // 0/x/x/x HCCPARAMS2 Reserved Bit 12
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_11 BIT11   // 0/x/x/x HCCPARAMS2 Reserved Bit 11
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_10 BIT10   // 0/x/x/x HCCPARAMS2 Reserved Bit 10
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_9  BIT9    // 0/x/x/x HCCPARAMS2 Reserved Bit 9
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_8  BIT8    // 0/x/x/x HCCPARAMS2 Reserved Bit 8
    #define CND003_USB30MMIO_HCCP2_RSVD_BIT_7  BIT7    // 0/x/x/x HCCPARAMS2 Reserved Bit 7
    #define CND003_USB30MMIO_ETC               BIT6    // 1b/1b/x/x Extended TBC Capability (ETC) ? RO
    #define CND003_USB30MMIO_CIC               BIT5    // 1b/1b/x/x Configuration Information Capability (CIC)
    #define CND003_USB30MMIO_LEC               BIT4    // 1b/1b/x/x Large ESIT Payload Capability (LEC)
    #define CND003_USB30MMIO_CTC               BIT3    // 1b/1b/x/x Compliance Transition Capability (CTC)
    #define CND003_USB30MMIO_FSC               BIT2    // 1b/1b/x/x Force Save Context Capability (FSC)
    #define CND003_USB30MMIO_CMC               BIT1    // 1b/1b/x/x Configure Endpoint Command Max Exit Latency Too Large Capability (CMC)
    #define CND003_USB30MMIO_U3C               BIT0    // 1b/1b/x/x U3 Entry Capability (U3C)
#define CND003_USB30MMIO_USB_CMD_REG_USBCMD 0x20 // USB Command Register (USBCMD)
    #define CND003_USB30MMIO_ETE       BIT14                   // 0/0/x/x Extended TBC Enable (ETE)
    #define CND003_USB30MMIO_CME       BIT13                   // 0/0/x/x CEM Enable (CME)
    #define CND003_USB30MMIO_EU3S      BIT11                   // 0/0/x/x Enable U3 MFINDEX Stop (EU3S) ? RW
    #define CND003_USB30MMIO_EWE       BIT10                   // 0/0/x/x Enable Wrap Event (EWE) ? RW
    #define CND003_USB30MMIO_CRS       BIT9                    // 0/0/x/x Controller Restore State (CRS) ? RW
    #define CND003_USB30MMIO_CSS       BIT8                    // 0/0/x/x Controller Save State (CSS) ? RWS
    #define CND003_USB30MMIO_LHCRST    BIT7                    // 0/0/x/x Light Host Controller Reset (LHCRST) ? RW
    #define CND003_USB30MMIO_HSEE      BIT3                    // 0/0/x/x Host System Error Enable (HSEE) ? RW
    #define CND003_USB30MMIO_INTE      BIT2                    // 0/0/x/x Interrupter Enable (INTE) ? RW
    #define CND003_USB30MMIO_HCRST     BIT1                    // 0/0/x/x Host Controller Reset (HCRST) ? RW
    #define CND003_USB30MMIO_RUNSTOP   BIT0                    // 0/0/x/x Run/Stop (R/S) ? RW
#define CND003_USB30MMIO_USB_STA_REG_USBSTS 0x24 // USB Status Register (USBSTS)
    #define CND003_USB30MMIO_HCE       BIT12                   // 0/0/x/x Host Controller Error (HCE) ? RO
    #define CND003_USB30MMIO_CNR       BIT11                   // 1b/1b/x/x Controller Not Ready (CNR) ? RO
    #define CND003_USB30MMIO_SRE       BIT10                   // 0/0/x/x Save/Restore Error (SRE) ? RW1C
    #define CND003_USB30MMIO_RSS       BIT9                    // 0/0/x/x Restore State Status (RSS) ? RO
    #define CND003_USB30MMIO_SSS       BIT8                    // 0/0/x/x Save State Status (SSS) ? RO
    #define CND003_USB30MMIO_PCD       BIT4                    // 0/0/x/x Port Change Detect (PCD) ? RW1C
    #define CND003_USB30MMIO_EINT      BIT3                    // 0/0/x/x Event Interrupt (EINT) ? RW1C
    #define CND003_USB30MMIO_HSE       BIT2                    // 0/0/x/x Host System Error (HSE) ? RW1C
    #define CND003_USB30MMIO_HCHALTED  BIT0                    // 1b/0/x/x HCHalted (HCH) ? RO
#define CND003_USB30MMIO_PAGE_SIZE_REG_PAGESIZE 0x28 // Page Size Register (PAGESIZE)
    #define CND003_USB30MMIO_PAGESIZE  0xFFFF      // 0001h/0001h/x/x Page Size ? RO
#define CND003_USB30MMIO_DEV_NOTIFICATION_CTL_REG_DNCTRL 0x34 // Device Notification Control Register (DNCTRL)
    #define CND003_USB30MMIO_DNCTRL    0xFFFF      // 0/0/x/x Notification Enable (N0-N15) ? RW
#define CND003_USB30MMIO_CMD_RING_CTL_REG_0_CRCR0 0x38 // Command Ring Control Register 0 (CRCR0)
    #define CND003_USB30MMIO_CDRINGPOINTERLO   0xFFFFFFC0      // 0/0/x/x Command Ring Pointer (Low 32 Bits) ? RW
    #define CND003_USB30MMIO_CRR               BIT3            // 0/0/x/x Command Ring Running (CRR) ? RO
    #define CND003_USB30MMIO_CA                BIT2            // 0/0/x/x Command Abort (CA) ? RW
    #define CND003_USB30MMIO_CS                BIT1            // 0/0/x/x Command Stop (CS) ? RW
    #define CND003_USB30MMIO_RCS               BIT0            // 0/0/x/x Ring Cycle State (RCS) ? RW
#define CND003_USB30MMIO_CMD_RING_CTL_REG_1_CRCR1 0x3C // Command Ring Control Register 1 (CRCR1)
    #define CND003_USB30MMIO_CDRINGPOINTERHI CND003_USB30MMIO_CMD_RING_CTL_REG_1_CRCR1 // 0/0/x/x Command Ring Pointer (High 32 Bits) ? RW
#define CND003_USB30MMIO_DEV_CONTEXT_BASE_ADR_ARRAY_PTR_REG_0_DCBAAP0 0x50 // Device Context Base Address Array Pointer Register 0 (DCBAAP0)
    #define CND003_USB30MMIO_DCBAAPLO  0xFFFFFFC0  // 0/0/x/x Device Context Base Address Array Pointer (Low 32 Bits) ? RW
#define CND003_USB30MMIO_DEV_CONTEXT_BASE_ADR_ARRAY_PTR_REG_1_DCBAAP1 0x54 // Device Context Base Address Array Pointer Register 1 (DCBAAP1)
    #define CND003_USB30MMIO_DCBAAPHI CND003_USB30MMIO_DEV_CONTEXT_BASE_ADR_ARRAY_PTR_REG_1_DCBAAP1 // 0/0/x/x Device Context Base Address Array Pointer (High 32 Bits) ? RW
#define CND003_USB30MMIO_CFG_REG_CFG 0x58 // Configure Register (CONFIG)
    #define CND003_USB30MMIO_CIE       BIT9        // 0/0/x/x Configuration Information Enable (CIE)
    #define CND003_USB30MMIO_U3E       BIT8        // 0/0/x/x U3 Entry Enable (U3E)
    #define CND003_USB30MMIO_MAXSLOTEN 0xFF        // 0/0/x/x Max Device Slots Enabled (MaxSlotsEn) ? RW
#define CND003_USB30MMIO_USB_LEGACY_SUPPORT_CAP_REG_USBLEGSUP 0x80 // USB Legacy Support Capability Register (USBLEGSUP)
    #define CND003_USB30MMIO_HCOSOWNS      BIT24       // 0/0/x/x HC OS Owned Semaphore ? RW
    #define CND003_USB30MMIO_HCBIOSOWNS    BIT16       // 0/0/x/x HC BIOS Owned Semaphore ? RW
    #define CND003_USB30MMIO_USBLEGNXTPTR  0xFF00      // 08h/0/x/x Next Capability Pointer ? RO
    #define CND003_USB30MMIO_USBLEGID      0xFF        // 01h/0/x/x Capability ID ? RO
#define CND003_USB30MMIO_USB_LEGACY_SUPPORT_CTL_AND_STA_REG_USBLEGCTLSTS 0x84 // USB Legacy Support Control and Status Register (USBLEGCTLSTS)
    #define CND003_USB30MMIO_SMIONBAR      BIT31                   // 0/0/x/x SMI on BAR ? RW1C
    #define CND003_USB30MMIO_SMIONPCMD     BIT30                   // 0/0/x/x SMI on PCI Command ? RW1C
    #define CND003_USB30MMIO_SMIOSOWNCHG   BIT29                   // 0/0/x/x SMI on OS Ownership Change ? RW1C
    #define CND003_USB30MMIO_SMIHSERR      BIT20                   // 0/0/x/x SMI on Host System Error ? RO
    #define CND003_USB30MMIO_SMIEVENTINT   BIT16                   // 0/0/x/x SMI on Event Interrupt ? RO
    #define CND003_USB30MMIO_SMIONBAREN    BIT15                   // 0/0/x/x SMI on BAR Enable ? RW
    #define CND003_USB30MMIO_SMIONPCMDEN   BIT14                   // 0/0/x/x SMI on PCI Command Enable ? RW
    #define CND003_USB30MMIO_SMIOSOWNEN    BIT13                   // 0/0/x/x SMI on OS Ownership Enable ? RW
    #define CND003_USB30MMIO_SMIHSERREN    BIT4                    // 0/0/x/x SMI on Host System Error Enable ? RW
    #define CND003_USB30MMIO_USBSMIEN      BIT0                    // 0/0/x/x USB SMI Enable ? RW
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_EXTENDED_CAP_USB2PROTOCOLCAP 0xA0 // xHCI Supported USB2.0 Protocol Extended Capability (USB2PROTOCOLCAP)
    #define CND003_USB30MMIO_USB2PRTMAJREV 0xFF000000  // 02h/02h/x/x Major Revision ? RO
    #define CND003_USB30MMIO_USB2PRTMINREV 0xFF0000    // 00h/0/x/x Minor Revision ? RO
    #define CND003_USB30MMIO_USB2PRTNXTPTR 0xFF00      // 08h/08h/x/x Next Capability Pointer ? RO
    #define CND003_USB30MMIO_USB2PRTID     0xFF        // 02h/02h/x/x Capability ID ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_NAMING_STRING_USB2PROTOCOLNAMESTR 0xA4 // xHCI Supported USB2.0 Protocol Naming String (USB2PROTOCOLNAMESTR)
    #define CND003_USB30MMIO_USB2NAMESTR CND003_USB30MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_NAMING_STRING_USB2PROTOCOLNAMESTR // 20425355h/20425355h/x/x Name String ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_CAP_USB2PROTOCOLCAP 0xA8 // xHCI Supported USB2.0 Protocol Capability (USB2PROTOCOLCAP)
    #define CND003_USB30MMIO_USB2PSIC              0xF0000000              // 3h/3h/x/x Protocol Speed ID Count (PSIC) ? RO
    #define CND003_USB30MMIO_USB2MHD               (BIT25 + BIT26 + BIT27) // 0/0/x/x Hub Depth (MHD) ? RO
    #define CND003_USB30MMIO_USB2PC2_RSVD_BIT_24   BIT24                   // 0/x/x/x USB2.0 Protocol Capability Reserved Bit 24
    #define CND003_USB30MMIO_USB2PC2_RSVD_BIT_23   BIT23                   // 0/x/x/x USB2.0 Protocol Capability Reserved Bit 23
    #define CND003_USB30MMIO_USB2PC2_RSVD_BIT_22   BIT22                   // 0/x/x/x USB2.0 Protocol Capability Reserved Bit 22
    #define CND003_USB30MMIO_USB2PC2_RSVD_BIT_21   BIT21                   // 0/x/x/x USB2.0 Protocol Capability Reserved Bit 21
    #define CND003_USB30MMIO_BLC                   BIT20                   // 1b/1b/x/x BESL LPM Capability (BLC) ? RO
    #define CND003_USB30MMIO_HLC                   BIT19                   // 1b/1b/x/x Hardware LMP Capability (HLC) ? RO
    #define CND003_USB30MMIO_IHI                   BIT18                   // 0b/0/x/x Integrated Hub Implemented (IHI) ? RO
    #define CND003_USB30MMIO_HSO                   BIT17                   // 0b/0/x/x High-speed Only (HSO) ? RO
    #define CND003_USB30MMIO_USB2PC2_RSVD_BIT_16   BIT16                   // 0b/0/x/x USB2.0 Protocol Capability Reserved Bit 16
    #define CND003_USB30MMIO_USB2PORTCNT           0xFF00                  // 05h/02h/x/x Compatible Port Count ? RO
    #define CND003_USB30MMIO_USB2PORTOFF           0xFF                    // 01h/01h/x/x Compatible Port Offset ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB2_0_PROTOCOL_CAP_USB2PROTOCOLPST 0xAC // xHCI Supported USB2.0 Protocol Capability (USB2PROTOCOLPST)
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_31   BIT31   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 31
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_30   BIT30   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 30
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_29   BIT29   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 29
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_28   BIT28   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 28
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_27   BIT27   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 27
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_26   BIT26   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 26
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_25   BIT25   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 25
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_24   BIT24   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 24
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_23   BIT23   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 23
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_22   BIT22   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 22
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_21   BIT21   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 21
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_20   BIT20   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 20
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_19   BIT19   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 19
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_18   BIT18   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 18
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_17   BIT17   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 17
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_16   BIT16   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 16
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_15   BIT15   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 15
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_14   BIT14   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 14
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_13   BIT13   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 13
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_12   BIT12   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 12
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_11   BIT11   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 11
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_10   BIT10   // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 10
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_9    BIT9    // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 9
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_8    BIT8    // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 8
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_7    BIT7    // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 7
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_6    BIT6    // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 6
    #define CND003_USB30MMIO_USB2PC3_RSVD_BIT_5    BIT5    // 0/x/x/x USB2.0 Protocol Capability 3 Reserved Bit 5
    #define CND003_USB30MMIO_USB2PST               0x1F    // 0/x/x/x Protocol Slot Type
#define CND003_USB30MMIO_XHCI_USB2PSI1_HIGH_SPEED 0xB0 // xHCI USB2PSI1 (High Speed)
    #define CND003_USB30MMIO_USB2PSIM1             0xFFFF0000      // 1E0h/1E0h/x/x Protocol Speed ID Mantissa (PSIM)
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_15  BIT15           // 0/0/x/x USB2PSI1 Reserved Bit 15
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_14  BIT14           // 0/0/x/x USB2PSI1 Reserved Bit 14
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_13  BIT13           // 0/0/x/x USB2PSI1 Reserved Bit 13
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_12  BIT12           // 0/0/x/x USB2PSI1 Reserved Bit 12
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_11  BIT11           // 0/0/x/x USB2PSI1 Reserved Bit 11
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_10  BIT10           // 0/0/x/x USB2PSI1 Reserved Bit 10
    #define CND003_USB30MMIO_USB2PSI1_RSVD_BIT_9   BIT9            // 0/0/x/x USB2PSI1 Reserved Bit 9
    #define CND003_USB30MMIO_USB2PFD1              BIT8            // 0/0/x/x PSI Full-duplex (PFD)
    #define CND003_USB30MMIO_USB2PLT1              (BIT6 + BIT7)   // 0/0/x/x PSI Type (PLT)
    #define CND003_USB30MMIO_USB2PSIE1             (BIT4 + BIT5)   // 10b/10b/x/x Protocol Speed ID Exponent (PSIE)
    #define CND003_USB30MMIO_USB2PSIV1             0xF             // 3h/3h/x/x Protocol Speed ID Value (PSIV)
#define CND003_USB30MMIO_XHCI_USB2PSI2_FULL_SPEED 0xB4 // xHCI USB2PSI2 (Full Speed)
    #define CND003_USB30MMIO_USB2PSIM2             0xFFFF0000      // 000Ch/Ch/x/x Protocol Speed ID Mantissa (PSIM)
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_15  BIT15           // 0/0/x/x USB2PSI2 Reserved Bit 15
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_14  BIT14           // 0/0/x/x USB2PSI2 Reserved Bit 14
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_13  BIT13           // 0/0/x/x USB2PSI2 Reserved Bit 13
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_12  BIT12           // 0/0/x/x USB2PSI2 Reserved Bit 12
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_11  BIT11           // 0/0/x/x USB2PSI2 Reserved Bit 11
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_10  BIT10           // 0/0/x/x USB2PSI2 Reserved Bit 10
    #define CND003_USB30MMIO_USB2PSI2_RSVD_BIT_9   BIT9            // 0/0/x/x USB2PSI2 Reserved Bit 9
    #define CND003_USB30MMIO_USB2PFD2              BIT8            // 0/0/x/x PSI Full-duplex (PFD)
    #define CND003_USB30MMIO_USB2PLT2              (BIT6 + BIT7)   // 0/0/x/x PSI Type (PLT)
    #define CND003_USB30MMIO_USB2PSIE2             (BIT4 + BIT5)   // 10b/10b/x/x Protocol Speed ID Exponent (PSIE)
    #define CND003_USB30MMIO_USB2PSIV2             0xF             // 1h/1h/x/x Protocol Speed ID Value (PSIV)
#define CND003_USB30MMIO_XHCI_USB2PSI3_LOW_SPEED 0xB8 // xHCI USB2PSI3 (Low Speed)
    #define CND003_USB30MMIO_USB2PSIM3             0xFFFF0000      // 05DCh/05DCh/x/x Protocol Speed ID Mantissa (PSIM)
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_15  BIT15           // 0/0/x/x USB2PSI3 Reserved Bit 15
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_14  BIT14           // 0/0/x/x USB2PSI3 Reserved Bit 14
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_13  BIT13           // 0/0/x/x USB2PSI3 Reserved Bit 13
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_12  BIT12           // 0/0/x/x USB2PSI3 Reserved Bit 12
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_11  BIT11           // 0/0/x/x USB2PSI3 Reserved Bit 11
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_10  BIT10           // 0/0/x/x USB2PSI3 Reserved Bit 10
    #define CND003_USB30MMIO_USB2PSI3_RSVD_BIT_9   BIT9            // 0/0/x/x USB2PSI3 Reserved Bit 9
    #define CND003_USB30MMIO_USB2PFD3              BIT8            // 0/0/x/x PSI Full-duplex (PFD)
    #define CND003_USB30MMIO_USB2PLT3              (BIT6 + BIT7)   // 0/0/x/x PSI Type (PLT)
    #define CND003_USB30MMIO_USB2PSIE3             (BIT4 + BIT5)   // 01b/01b/x/x Protocol Speed ID Exponent (PSIE)
    #define CND003_USB30MMIO_USB2PSIV3             0xF             // 2h/2h/x/x Protocol Speed ID Value (PSIV)
#define CND003_USB30MMIO_XHCI_RESERVED_USB2PSI4 0xBC // xHCI Reserved USB2PSI4
    #define CND003_USB30MMIO_USB2PSI4 CND003_USB30MMIO_XHCI_RESERVED_USB2PSI4 // 0/0h/x/x USB2PSI4
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_EXTENDED_CAP_USB3PROTOCOLCAP 0xC0 // xHCI Supported USB3.0 Protocol Extended Capability (USB3PROTOCOLCAP)
    #define CND003_USB30MMIO_USB3PRTMAJREV 0xFF000000  // 03h/03h/x/x Major Revision ? RO
    #define CND003_USB30MMIO_USB3PRTMINREV 0xFF0000    // 00h/00h/x/x Minor Revision ? RO
    #define CND003_USB30MMIO_USB3PRTNXTPTR 0xFF00      // 08h/8Ch/x/x Next Capability Pointer ? RO
    #define CND003_USB30MMIO_USB3PRTID     0xFF        // 02h/02h/x/x Capability ID ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_NAMING_STRING_USB3PROTOCOLNAMESTR 0xC4 // xHCI Supported USB3.0 Protocol Naming String (USB3PROTOCOLNAMESTR)
    #define CND003_USB30MMIO_USB3NAMESTR CND003_USB30MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_NAMING_STRING_USB3PROTOCOLNAMESTR // 20425355h/20425355h/x/x Name String ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_CAP_USB3PROTOCOLCAP 0xC8 // xHCI Supported USB3.0 Protocol Capability (USB3PROTOCOLCAP)
    #define CND003_USB30MMIO_USB3PSIC              0xF0000000              // 1h/1h/x/x Protocol Speed ID Count (PSIC) ? RO
    #define CND003_USB30MMIO_USB3MHD               (BIT25 + BIT26 + BIT27) // 0/0/x/x Hub Depth (MHD) ? RO
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_24   BIT24                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 24
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_23   BIT23                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 23
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_22   BIT22                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 22
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_21   BIT21                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 21
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_20   BIT20                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 20
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_19   BIT19                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 19
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_18   BIT18                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 18
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_17   BIT17                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 17
    #define CND003_USB30MMIO_USB3PC2_RSVD_BIT_16   BIT16                   // 0/0/x/x USB3.0 Protocol Capability Reserved Bit 16
    #define CND003_USB30MMIO_USB3PORTCNT           0xFF00                  // 03h/02h/x/x Compatible Port Count ? RO
    #define CND003_USB30MMIO_USB3PORTOFF           0xFF                    // 06h/03h/x/x Compatible Port Offset ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_0_PROTOCOL_CAP_USB3PROTOCOLPST 0xCC // xHCI Supported USB3.0 Protocol Capability (USB3PROTOCOLPST)
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_31   BIT31   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 31
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_30   BIT30   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 30
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_29   BIT29   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 29
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_28   BIT28   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 28
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_27   BIT27   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 27
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_26   BIT26   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 26
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_25   BIT25   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 25
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_24   BIT24   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 24
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_23   BIT23   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 23
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_22   BIT22   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 22
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_21   BIT21   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 21
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_20   BIT20   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 20
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_19   BIT19   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 19
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_18   BIT18   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 18
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_17   BIT17   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 17
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_16   BIT16   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 16
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_15   BIT15   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 15
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_14   BIT14   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 14
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_13   BIT13   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 13
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_12   BIT12   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 12
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_11   BIT11   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 11
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_10   BIT10   // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 10
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_9    BIT9    // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 9
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_8    BIT8    // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 8
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_7    BIT7    // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 7
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_6    BIT6    // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 6
    #define CND003_USB30MMIO_USB3PC3_RSVD_BIT_5    BIT5    // 0/x/x/x USB3.0 Protocol Capability Reserved Bit 5
    #define CND003_USB30MMIO_USB3PST               0x1F    // 0/x/x/x Protocol Slot Type
#define CND003_USB30MMIO_XHCI_USB3PSI1_SUPER_SPEED 0xD0 // xHCI USB3PSI1 (Super Speed)
    #define CND003_USB30MMIO_USB3PSIM1             0xFFFF0000      // 5h/5h/x/x Protocol Speed ID Mantissa (PSIM)
    #define CND003_USB30MMIO_USB3LP1               (BIT14 + BIT15) // 0/0/x/x Link Protocol (LP) ? RO. 
    #define CND003_USB30MMIO_USB3PSI1_RSVD_BIT_13  BIT13           // 0/0/x/x USB3PSI1 Reserved Bit 13
    #define CND003_USB30MMIO_USB3PSI1_RSVD_BIT_12  BIT12           // 0/0/x/x USB3PSI1 Reserved Bit 12
    #define CND003_USB30MMIO_USB3PSI1_RSVD_BIT_11  BIT11           // 0/0/x/x USB3PSI1 Reserved Bit 11
    #define CND003_USB30MMIO_USB3PSI1_RSVD_BIT_10  BIT10           // 0/0/x/x USB3PSI1 Reserved Bit 10
    #define CND003_USB30MMIO_USB3PSI1_RSVD_BIT_9   BIT9            // 0/0/x/x USB3PSI1 Reserved Bit 9
    #define CND003_USB30MMIO_USB3PFD1              BIT8            // 1b/1b/x/x PSI Full-duplex (PFD)
    #define CND003_USB30MMIO_USB3PLT1              (BIT6 + BIT7)   // 0/0/x/x PSI Type (PLT)
    #define CND003_USB30MMIO_USB3PSIE1             (BIT4 + BIT5)   // 11b/11b/x/x Protocol Speed ID Exponent (PSIE)
    #define CND003_USB30MMIO_USB3PSIV1             0xF             // 4h/4h/x/x Protocol Speed ID Value (PSIV)
#define CND003_USB30MMIO_XHCI_RESERVED_USB3PSI2 0xD4 // xHCI Reserved USB3PSI2
    #define CND003_USB30MMIO_USB3PSI2 CND003_USB30MMIO_XHCI_RESERVED_USB3PSI2 // 0h/0h/x/x USB3PSI2
#define CND003_USB30MMIO_XHCI_RESERVED_USB3PSI3 0xD8 // xHCI Reserved USB3PSI3
    #define CND003_USB30MMIO_USB3PSI3 CND003_USB30MMIO_XHCI_RESERVED_USB3PSI3 // 0h/0h/x/x USB3PSI3
#define CND003_USB30MMIO_XHCI_RESERVED_USB3PSI4 0xDC // xHCI Reserved USB3PSI4
    #define CND003_USB30MMIO_USB3PSI4 CND003_USB30MMIO_XHCI_RESERVED_USB3PSI4 // 0h/0h/x/x USB3PSI4
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_1_PROTOCOL_EXTENDED_CAP_USB31PROTOCOLCAP 0xE0 // xHCI Supported USB3.1 Protocol Extended Capability (USB31PROTOCOLCAP)
    #define CND003_USB30MMIO_USB31PRTMAJREV    0xFF000000  // 03h/03h/x/x Major Revision ? RO
    #define CND003_USB30MMIO_USB31PRTMINREV    0xFF0000    // 01h/01h/x/x Minor Revision ? RO
    #define CND003_USB30MMIO_USB31PRTNXTPTR    0xFF00      // 88h/88h/x/x Next Capability Pointer ? RO
    #define CND003_USB30MMIO_USB31PRTID        0xFF        // 02h/02h/x/x Capability ID ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_1_PROTOCOL_NAMING_STRING_USB31PROTOCOLNAMESTR 0xE4 // xHCI Supported USB3.1 Protocol Naming String (USB31PROTOCOLNAMESTR)
    #define CND003_USB30MMIO_USB31NAMESTR CND003_USB30MMIO_XHCI_SUPPORTED_USB3_1_PROTOCOL_NAMING_STRING_USB31PROTOCOLNAMESTR // 20425355h/20425355h/x/x Name String ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_1_PROTOCOL_CAP_USB31PROTOCOLCAP 0xE8 // xHCI Supported USB3.1 Protocol Capability (USB31PROTOCOLCAP)
    #define CND003_USB30MMIO_USB31PSIC             0xF0000000              // 2h/1h/x/x Protocol Speed ID Count (PSIC) ? RO
    #define CND003_USB30MMIO_USB31MHD              (BIT25 + BIT26 + BIT27) // 0/0/x/x Hub Depth (MHD) ? RO
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_24  BIT24                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 24
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_23  BIT23                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 23
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_22  BIT22                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 22
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_21  BIT21                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 21
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_20  BIT20                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 20
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_19  BIT19                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 19
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_18  BIT18                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 18
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_17  BIT17                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 17
    #define CND003_USB30MMIO_USB31PC2_RSVD_BIT_16  BIT16                   // 0/0/x/x USB3.1 Protocol Capability Reserved Bit 16
    #define CND003_USB30MMIO_USB31PORTCNT          0xFF00                  // 02h/02h/x/x Compatible Port Count ? RO
    #define CND003_USB30MMIO_USB31PORTOFF          0xFF                    // 09h/03h/x/x Compatible Port Offset ? RO
#define CND003_USB30MMIO_XHCI_SUPPORTED_USB3_1_PROTOCOL_CAP_USB31PROTOCOLPST 0xEC // xHCI Supported USB3.1 Protocol Capability (USB31PROTOCOLPST)
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_31  BIT31   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 31
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_30  BIT30   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 30
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_29  BIT29   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 29
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_28  BIT28   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 28
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_27  BIT27   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 27
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_26  BIT26   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 26
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_25  BIT25   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 25
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_24  BIT24   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 24
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_23  BIT23   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 23
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_22  BIT22   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 22
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_21  BIT21   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 21
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_20  BIT20   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 20
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_19  BIT19   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 19
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_18  BIT18   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 18
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_17  BIT17   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 17
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_16  BIT16   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 16
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_15  BIT15   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 15
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_14  BIT14   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 14
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_13  BIT13   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 13
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_12  BIT12   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 12
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_11  BIT11   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 11
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_10  BIT10   // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 10
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_9   BIT9    // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 9
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_8   BIT8    // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 8
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_7   BIT7    // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 7
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_6   BIT6    // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 6
    #define CND003_USB30MMIO_USB31PC3_RSVD_BIT_5   BIT5    // 0/x/x/x USB3.1 Protocol Capability Reserved Bit 5
    #define CND003_USB30MMIO_USB31PST              0x1F    // 0/x/x/x Protocol Slot Type
#define CND003_USB30MMIO_XHCI_USB31PSI1_SUPER_SPEED 0xF0 // xHCI USB31PSI1 (Super Speed)
    #define CND003_USB30MMIO_USB31PSIM1            0xFFFF0000      // 5h/5h/x/x Protocol Speed ID Mantissa (PSIM)
    #define CND003_USB30MMIO_USB31LP1              (BIT14 + BIT15) // 0/0/x/x Link Protocol (LP) ? RO
    #define CND003_USB30MMIO_USB31PSI1_RSVD_BIT_13 BIT13           // 0/0/x/x USB31PSI1 Reserved Bit 13
    #define CND003_USB30MMIO_USB31PSI1_RSVD_BIT_12 BIT12           // 0/0/x/x USB31PSI1 Reserved Bit 12
    #define CND003_USB30MMIO_USB31PSI1_RSVD_BIT_11 BIT11           // 0/0/x/x USB31PSI1 Reserved Bit 11
    #define CND003_USB30MMIO_USB31PSI1_RSVD_BIT_10 BIT10           // 0/0/x/x USB31PSI1 Reserved Bit 10
    #define CND003_USB30MMIO_USB31PSI1_RSVD_BIT_9  BIT9            // 0/0/x/x USB31PSI1 Reserved Bit 9
    #define CND003_USB30MMIO_USB31PFD1             BIT8            // 1b/1b/x/x PSI Full-duplex (PFD)
    #define CND003_USB30MMIO_USB31PLT1             (BIT6 + BIT7)   // 0/0/x/x PSI Type (PLT)
    #define CND003_USB30MMIO_USB31PSIE1            (BIT4 + BIT5)   // 11b/11b/x/x Protocol Speed ID Exponent (PSIE)
    #define CND003_USB30MMIO_USB31PSIV1            0xF             // 4h/4h/x/x Protocol Speed ID Value (PSIV)
#define CND003_USB30MMIO_XHCI_USB31PSI2_SUPER_SPEED_PLUS 0xF4 // xHCI USB31PSI2 (Super Speed Plus)
    #define CND003_USB30MMIO_USB31PSIM2            0xFFFF0000      // Ah/Ah/x/x Protocol Speed ID Mantissa (PSIM)
    #define CND003_USB30MMIO_USB31LP2              (BIT14 + BIT15) // 01b/01b/x/x Link Protocol (LP) ? RO
    #define CND003_USB30MMIO_USB31PSI2_RSVD_BIT_13 BIT13           // 0/0/x/x USB31PSI2 Reserved Bit 13
    #define CND003_USB30MMIO_USB31PSI2_RSVD_BIT_12 BIT12           // 0/0/x/x USB31PSI2 Reserved Bit 12
    #define CND003_USB30MMIO_USB31PSI2_RSVD_BIT_11 BIT11           // 0/0/x/x USB31PSI2 Reserved Bit 11
    #define CND003_USB30MMIO_USB31PSI2_RSVD_BIT_10 BIT10           // 0/0/x/x USB31PSI2 Reserved Bit 10
    #define CND003_USB30MMIO_USB31PSI2_RSVD_BIT_9  BIT9            // 0/0/x/x USB31PSI2 Reserved Bit 9
    #define CND003_USB30MMIO_USB31PFD2             BIT8            // 1b/1b/x/x PSI Full-duplex (PFD)
    #define CND003_USB30MMIO_USB31PLT2             (BIT6 + BIT7)   // 0/0/x/x PSI Type (PLT)
    #define CND003_USB30MMIO_USB31PSIE2            (BIT4 + BIT5)   // 11b/11b/x/x Protocol Speed ID Exponent (PSIE)
    #define CND003_USB30MMIO_USB31PSIV2            0xF             // 5h/5h/x/x Protocol Speed ID Value (PSIV)
#define CND003_USB30MMIO_XHCI_RESERVED_USB31PSI3 0xF8 // xHCI Reserved USB31PSI3
    #define CND003_USB30MMIO_USB31PSI3 CND003_USB30MMIO_XHCI_RESERVED_USB31PSI3 // 0h/0h/x/x USB31PSI3
#define CND003_USB30MMIO_XHCI_RESERVED_USB31PSI4 0xFC // xHCI Reserved USB31PSI4
    #define CND003_USB30MMIO_USB31PSI4 CND003_USB30MMIO_XHCI_RESERVED_USB31PSI4 // 0h/0h/x/x USB31PSI4
#define CND003_USB30MMIO_CMD_RING_DOORBELL_REG 0x100 // Command Ring Doorbell Register
    #define CND003_USB30MMIO_DBSTMID0  0xFFFF0000  // 0/0/x/x DB Stream ID ? RW
    #define CND003_USB30MMIO_DBTARGET0 0xFF        // 0/0/x/x DB Target ? RW
#define CND003_USB30MMIO_DEV_SLOT_1_DOORBELL_REG 0x104 // Device Slot 1 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID1  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET1 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_2_DOORBELL_REG 0x108 // Device Slot 2 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID2  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET2 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_3_DOORBELL_REG 0x10C // Device Slot 3 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID3  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET3 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_4_DOORBELL_REG 0x110 // Device Slot 4 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID4  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET4 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_5_DOORBELL_REG 0x114 // Device Slot 5 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID5  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET5 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_6_DOORBELL_REG 0x118 // Device Slot 6 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID6  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET6 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_7_DOORBELL_REG 0x11C // Device Slot 7 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID7  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET7 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_8_DOORBELL_REG 0x120 // Device Slot 8 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID8  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET8 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_9_DOORBELL_REG 0x124 // Device Slot 9 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID9  0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET9 0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_10_DOORBELL_REG 0x128 // Device Slot 10 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID10     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET10    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_11_DOORBELL_REG 0x12C // Device Slot 11 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID11     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET11    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_12_DOORBELL_REG 0x130 // Device Slot 12 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID12     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET12    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_13_DOORBELL_REG 0x134 // Device Slot 13 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID13     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET13    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_14_DOORBELL_REG 0x138 // Device Slot 14 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID14     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET14    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_15_DOORBELL_REG 0x13C // Device Slot 15 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID15     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET15    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_16_DOORBELL_REG 0x140 // Device Slot 16 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID16     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET16    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_17_DOORBELL_REG 0x144 // Device Slot 17 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID17     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET17    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_18_DOORBELL_REG 0x148 // Device Slot 18 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID18     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET18    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_19_DOORBELL_REG 0x14C // Device Slot 19 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID19     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET19    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_20_DOORBELL_REG 0x150 // Device Slot 20 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID20     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET20    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_21_DOORBELL_REG 0x154 // Device Slot 21 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID21     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET21    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_22_DOORBELL_REG 0x158 // Device Slot 22 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID22     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET22    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_23_DOORBELL_REG 0x15C // Device Slot 23 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID23     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET23    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_24_DOORBELL_REG 0x160 // Device Slot 24 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID24     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET24    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_25_DOORBELL_REG 0x164 // Device Slot 25 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID25     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET25    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_26_DOORBELL_REG 0x168 // Device Slot 26 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID26     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET26    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_27_DOORBELL_REG 0x16C // Device Slot 27 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID27     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET27    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_28_DOORBELL_REG 0x170 // Device Slot 28 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID28     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET28    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_29_DOORBELL_REG 0x174 // Device Slot 29 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID29     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET29    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_30_DOORBELL_REG 0x178 // Device Slot 30 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID30     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET30    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_31_DOORBELL_REG 0x17C // Device Slot 31 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID31     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET31    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_DEV_SLOT_32_DOORBELL_REG 0x180 // Device Slot 32 Doorbell Register
    #define CND003_USB30MMIO_DBSTMID32     0xFFFF0000  // 0/0/x/x DB Stream ID
    #define CND003_USB30MMIO_DBTARGET32    0xFF        // 0/0/x/x DB Target
#define CND003_USB30MMIO_MICROFRAME_INDEX_REG_MFINDEX 0x200 // Microframe Index Register (MFINDEX)
    #define CND003_USB30MMIO_MFINDEX   0x3FFF      // 0/0/x/x Microframe Index ? RO
#define CND003_USB30MMIO_INTRER_0_MANAGEMENT_REG_IMAN0 0x220 // Interrupter 0 Management Register (IMAN0)
    #define CND003_USB30MMIO_INTEN0        BIT1        // 0/0/x/x Interrupt Enable (IE) ? RW 
    #define CND003_USB30MMIO_INTPENDING0   BIT0        // 0/0/x/x Interrupt Pending (IP) ? RW1C
#define CND003_USB30MMIO_INTRER_0_MODERATION_REG_IMOD0 0x224 // Interrupter 0 Moderation Register (IMOD0)
    #define CND003_USB30MMIO_IMODC0    0xFFFF0000  // 0/0/x/x Interrupt Moderation Counter (IMODC) ? RW
    #define CND003_USB30MMIO_IMODI0    0xFFFF      // 0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) ? RW
#define CND003_USB30MMIO_EVENT_RING_0_SEGMENT_TABLE_SIZE_REG_ER0STSZ 0x228 // Event Ring 0 Segment Table Size Register (ER0STSZ)
    #define CND003_USB30MMIO_ER0STSZ   0xFFFF      // 0/0/x/x Event Ring Segment Table Size ? RW
#define CND003_USB30MMIO_EVENT_RING_0_SEGMENT_TABLE_BASE_ADR_REG_0_ER0STBA0 0x230 // Event Ring 0 Segment Table Base Address Register 0 (ER0STBA0)
    #define CND003_USB30MMIO_ER0STBALO 0xFFFFFFC0  // 0/0/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_0_SEGMENT_TABLE_BASE_ADR_REG_1_ER0STBA1 0x234 // Event Ring 0 Segment Table Base Address Register 1 (ER0STBA1)
    #define CND003_USB30MMIO_ER0STBAHI CND003_USB30MMIO_EVENT_RING_0_SEGMENT_TABLE_BASE_ADR_REG_1_ER0STBA1 // 0/0/x/x Event Ring Segment Table Base Address Register (High 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_0_DEQUEUE_PTR_REG_0_ER0DP0 0x238 // Event Ring 0 Dequeue Pointer Register 0 (ER0DP0)
    #define CND003_USB30MMIO_ER0DPLO   0xFFFFFFF0              // 0/0/x/x Dequeue Pointer (Low 32 Bits) ? RW
    #define CND003_USB30MMIO_EHB0      BIT3                    // 0/0/x/x Event Handler Busy (EHB) ? RW1C
    #define CND003_USB30MMIO_DESI0     (BIT0 + BIT1 + BIT2)    // 0/0/x/x Dequeue ERST Segment Index (DESI)
#define CND003_USB30MMIO_EVENT_RING_0_DEQUEUE_PTR_REG_1_ER0DP1 0x23C // Event Ring 0 Dequeue Pointer Register 1 (ER0DP1)
    #define CND003_USB30MMIO_ER0DPHI CND003_USB30MMIO_EVENT_RING_0_DEQUEUE_PTR_REG_1_ER0DP1 // 0/0/x/x Dequeue Pointer (High 32 Bits) ? RW
#define CND003_USB30MMIO_INTRER_1_MANAGEMENT_REG_IMAN1 0x240 // Interrupter 1 Management Register (IMAN1)
    #define CND003_USB30MMIO_INTEN1        BIT1        // 0/0/x/x Interrupt Enable (IE) ? RW
    #define CND003_USB30MMIO_INTPENDING1   BIT0        // 0/0/x/x Interrupt Pending (IP) - RW1C
#define CND003_USB30MMIO_INTRER_1_MODERATION_REG_IMOD1 0x244 // Interrupter 1 Moderation Register (IMOD1)
    #define CND003_USB30MMIO_IMODC1    0xFFFF0000  // 0/0/x/x Interrupt Moderation Counter (IMODC) ? RW
    #define CND003_USB30MMIO_IMODI1    0xFFFF      // 0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) ? RW. 
#define CND003_USB30MMIO_EVENT_RING_1_SEGMENT_TABLE_SIZE_REG_ER1STSZ 0x248 // Event Ring 1 Segment Table Size Register (ER1STSZ)
    #define CND003_USB30MMIO_ER1STSZ   0xFFFF      // 0/0/x/x Event Ring Segment Table Size ? RW
#define CND003_USB30MMIO_EVENT_RING_1_SEGMENT_TABLE_BASE_ADR_REG_0_ER1STBA0 0x250 // Event Ring 1 Segment Table Base Address Register 0 (ER1STBA0)
    #define CND003_USB30MMIO_ER1STBALO 0xFFFFFFC0  // 0/0/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_1_SEGMENT_TABLE_BASE_ADR_REG_1_ER1STBA1 0x254 // Event Ring 1 Segment Table Base Address Register 1 (ER1STBA1)
    #define CND003_USB30MMIO_ER1STBAHI CND003_USB30MMIO_EVENT_RING_1_SEGMENT_TABLE_BASE_ADR_REG_1_ER1STBA1 // 0/0/x/x Event Ring Segment Table Base Address Register (High 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_1_DEQUEUE_PTR_REG_0_ER1DP0 0x258 // Event Ring 1 Dequeue Pointer Register 0 (ER1DP0)
    #define CND003_USB30MMIO_ER1DPLO   0xFFFFFFF0              // 0/0/x/x Dequeue Pointer (Low 32 Bits) ? RW
    #define CND003_USB30MMIO_EHB1      BIT3                    // 0/0/x/x Event Handler Busy (EHB) ? RW1C
    #define CND003_USB30MMIO_DESI1     (BIT0 + BIT1 + BIT2)    // 0/0/x/x Dequeue ERST Segment Index (DESI)
#define CND003_USB30MMIO_EVENT_RING_1_DEQUEUE_PTR_REG_1_ER1DP1 0x25C // Event Ring 1 Dequeue Pointer Register 1 (ER1DP1)
    #define CND003_USB30MMIO_ER1DPHI CND003_USB30MMIO_EVENT_RING_1_DEQUEUE_PTR_REG_1_ER1DP1 // 0/0/x/x Dequeue Pointer (High 32 Bits) ? RW
#define CND003_USB30MMIO_INTRER_2_MANAGEMENT_REG_IMAN2 0x260 // Interrupter 2 Management Register (IMAN2)
    #define CND003_USB30MMIO_INTEN2        BIT1        // 0/0/x/x Interrupt Enable (IE) ? RW
    #define CND003_USB30MMIO_INTPENDING2   BIT0        // 0/0/x/x Interrupt Pending (IP) ? RW1C
#define CND003_USB30MMIO_INTRER_2_MODERATION_REG_IMOD2 0x264 // Interrupter 2 Moderation Register (IMOD2)
    #define CND003_USB30MMIO_IMODC2    0xFFFF0000  // 0/0/x/x Interrupt Moderation Counter (IMODC) ? RW
    #define CND003_USB30MMIO_IMODI2    0xFFFF      // 0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) ? RW. 
#define CND003_USB30MMIO_EVENT_RING_2_SEGMENT_TABLE_SIZE_REG_ER2STSZ 0x268 // Event Ring 2 Segment Table Size Register (ER2STSZ)
    #define CND003_USB30MMIO_ER2STSZ   0xFFFF      // 0/0/x/x Event Ring Segment Table Size ? RW
#define CND003_USB30MMIO_EVENT_RING_2_SEGMENT_TABLE_BASE_ADR_REG_0_ER2STBA0 0x270 // Event Ring 2 Segment Table Base Address Register 0 (ER2STBA0)
    #define CND003_USB30MMIO_ER2STBALO 0xFFFFFFC0  // 0/0/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_2_SEGMENT_TABLE_BASE_ADR_REG_1_ER2STBA1 0x274 // Event Ring 2 Segment Table Base Address Register 1 (ER2STBA1)
    #define CND003_USB30MMIO_ER2STBAHI CND003_USB30MMIO_EVENT_RING_2_SEGMENT_TABLE_BASE_ADR_REG_1_ER2STBA1 // 0/0/x/x Event Ring Segment Table Base Address Register (High 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_2_DEQUEUE_PTR_REG_0_ER2DP0 0x278 // Event Ring 2 Dequeue Pointer Register 0 (ER2DP0)
    #define CND003_USB30MMIO_ER2DPLO   0xFFFFFFF0              // 0/0/x/x Dequeue Pointer (Low 32 Bits) ? RW
    #define CND003_USB30MMIO_EHB2      BIT3                    // 0/0/x/x Event Handler Busy (EHB) ? RW1C
    #define CND003_USB30MMIO_DESI2     (BIT0 + BIT1 + BIT2)    // 0/0/x/x Dequeue ERST Segment Index (DESI)
#define CND003_USB30MMIO_EVENT_RING_2_DEQUEUE_PTR_REG_1_ER2DP1 0x27C // Event Ring 2 Dequeue Pointer Register 1 (ER2DP1)
    #define CND003_USB30MMIO_ER2DPHI CND003_USB30MMIO_EVENT_RING_2_DEQUEUE_PTR_REG_1_ER2DP1 // 0/0/x/x Dequeue Pointer (High 32 Bits) ? RW
#define CND003_USB30MMIO_INTRER_3_MANAGEMENT_REG_IMAN3 0x280 // Interrupter 3 Management Register (IMAN3)
    #define CND003_USB30MMIO_INTEN3        BIT1        // 0/0/x/x Interrupt Enable (IE) ? RW
    #define CND003_USB30MMIO_INTPENDING3   BIT0        // 0/0/x/x Interrupt Pending (IP) ? RW1C
#define CND003_USB30MMIO_INTRER_3_MODERATION_REG_IMOD3 0x284 // Interrupter 3 Moderation Register (IMOD3)
    #define CND003_USB30MMIO_IMODC3    0xFFFF0000  // 0/0/x/x Interrupt Moderation Counter (IMODC) ? RW
    #define CND003_USB30MMIO_IMODI3    0xFFFF      // 0FA0h/0FA0h/x/x Interrupt Moderation Interval (IMODI) ? RW
#define CND003_USB30MMIO_EVENT_RING_3_SEGMENT_TABLE_SIZE_REG_ER3STSZ 0x288 // Event Ring 3 Segment Table Size Register (ER3STSZ)
    #define CND003_USB30MMIO_ER3STSZ   0xFFFF      // 0/0/x/x Event Ring Segment Table Size ? RW
#define CND003_USB30MMIO_EVENT_RING_3_SEGMENT_TABLE_BASE_ADR_REG_0_ER3STBA0 0x290 // Event Ring 3 Segment Table Base Address Register 0 (ER3STBA0)
    #define CND003_USB30MMIO_ER3STBALO 0xFFFFFFC0  // 0/0/x/x Event Ring Segment Table Base Address Register (Low 32 Bits) ? RW
#define CND003_USB30MMIO_EVENT_RING_3_SEGMENT_TABLE_BASE_ADR_REG_1_ER3STBA1 0x294 // Event Ring 3 Segment Table Base Address Register 1 (ER3STBA1)
    #define CND003_USB30MMIO_ER3STBAHI CND003_USB30MMIO_EVENT_RING_3_SEGMENT_TABLE_BASE_ADR_REG_1_ER3STBA1 // 0/0/x/x Event Ring Segment Table Base Address Register (High 32 Bits)? RW
#define CND003_USB30MMIO_EVENT_RING_3_DEQUEUE_PTR_REG_0_ER3DP0 0x298 // Event Ring 3 Dequeue Pointer Register 0 (ER3DP0)
    #define CND003_USB30MMIO_ER3DPLO   0xFFFFFFF0              // 0/0/x/x Dequeue Pointer (Low 32 Bits) ? RW
    #define CND003_USB30MMIO_EHB3      BIT3                    // 0/0/x/x Event Handler Busy (EHB) ? RW1C
    #define CND003_USB30MMIO_DESI3     (BIT0 + BIT1 + BIT2)    // 0/0/x/x Dequeue ERST Segment Index (DESI)
#define CND003_USB30MMIO_EVENT_RING_3_DEQUEUE_PTR_REG_1_ER3DP1 0x29C // Event Ring 3 Dequeue Pointer Register 1 (ER3DP1)
    #define CND003_USB30MMIO_ER3DPHI CND003_USB30MMIO_EVENT_RING_3_DEQUEUE_PTR_REG_1_ER3DP1 // 0/0/x/x Dequeue Pointer (High 32 Bits) - RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_ID_REG_DCID 0x300 // xHCI Debug Capability ID Register (DCID)
    #define CND003_USB30MMIO_DCERSTMAX     0x1F0000    // 03h/03h/x/x Debug Capability Event Ring Segment Table Max (DCERST Max) ? RO. ...
    #define CND003_USB30MMIO_DCPRTNXTPTR   0xFF00      // 00h/0/x/x Next Capability Pointer ? RO
    #define CND003_USB30MMIO_DCPRTID       0xFF        // 0Ah/0Ah/x/x Capability ID ? RO
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_DOORBELL_REG_DCDB 0x304 // xHCI Debug Capability Doorbell Register (DCDB)
    #define CND003_USB30MMIO_DCDBTGT   0xFF00      // 0/0/x/x Doorbell Target (DB Target) ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_SIZE_REG_DCERSTSZ 0x308 // xHCI Debug Capability Event Ring Segment Table Size Register (DCERSTSZ)
    #define CND003_USB30MMIO_DCERSTSZ  0xFFFF      // 0/0/x/x Event Ring Segment Table Size ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_BASE_ADR_REG_DCERSTBALO 0x310 // xHCI Debug Capability Event Ring Segment Table Base Address Register (DCERSTBALO)
    #define CND003_USB30MMIO_DCERSTBALO    0xFFFFFFF0  // 0/0/x/x Event Ring Segment Table Base Address Register ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_BASE_ADR_REG_DCERSTBAHI 0x314 // xHCI Debug Capability Event Ring Segment Table Base Address Register (DCERSTBAHI)
    #define CND003_USB30MMIO_DCERSTBAHI CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_SEGMENT_TABLE_BASE_ADR_REG_DCERSTBAHI // 0/0/x/x Event Ring Segment Table Base Address Register ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_DEQUEUE_PTR_RESITER_DCERDPLO 0x318 // xHCI Debug Capability Event Ring Dequeue Pointer Resiter (DCERDPLO)
    #define CND003_USB30MMIO_DCERDPLO  0xFFFFFFF0              // 0/0/x/x Dequeue Pointer ? RW
    #define CND003_USB30MMIO_DCDESI    (BIT0 + BIT1 + BIT2)    // 0/0/x/x Dequeue ERST Segment Index (DESI) ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_DEQUEUE_PTR_RESITER_DCERDPHI 0x31C // xHCI Debug Capability Event Ring Dequeue Pointer Resiter (DCERDPHI)
    #define CND003_USB30MMIO_DCERDPHI CND003_USB30MMIO_XHCI_DEBUG_CAP_EVENT_RING_DEQUEUE_PTR_RESITER_DCERDPHI // 0/0/x/x Dequeue Pointer ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_CTL_REG_DCCTRL 0x320 // xHCI Debug Capability Control Register (DCCTRL)
    #define CND003_USB30MMIO_DBC_DCE       BIT31       // 0/0/x/x Debug Capability Enable (DCE) ? RW
    #define CND003_USB30MMIO_DBC_DEVADDR   0x7F000000  // 0/0/x/x Device Address ? RO
    #define CND003_USB30MMIO_DBC_MAXBSZ    0xFF0000    // 0/0/x/x Debug Max Burst Size ? RO
    #define CND003_USB30MMIO_DBC_DRC       BIT4        // 0/0/x/x DbC Run Change (DRC) ? RW1C
    #define CND003_USB30MMIO_DBC_HIT       BIT3        // 0/0/x/x Halt IN TR (HIT) ? RW1S
    #define CND003_USB30MMIO_DBC_HOT       BIT2        // 0/0/x/x Halt OUT TR (HOT) ? RW1S
    #define CND003_USB30MMIO_DBC_LSE       BIT1        // 0/0/x/x Link Status Event Enable (LSE) ? RW
    #define CND003_USB30MMIO_DBC_DCR       BIT0        // 0/0/x/x DbC Run (DCR) ? RO
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_STA_REG_DCST 0x324 // xHCI Debug Capability Status Register (DCST)
    #define CND003_USB30MMIO_DBC_PORTNUM       0xFF000000  // 0/0/x/x Debug Port Number ? RO
    #define CND003_USB30MMIO_DBC_SBR           BIT1        // 0/0/x/x DbC System Bus Reset (SBR) ? RO
    #define CND003_USB30MMIO_DBC_ERNOTEMPTY    BIT0        // 0/0/x/x Event Ring Not Empty (ER) ? RO
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_PORT_STA_AND_CTL_REG_DCPORTSC 0x328 // xHCI Debug Capability Port Status and Control Register (DCPORTSC)
    #define CND003_USB30MMIO_DBC_CEC       BIT23                   // 0/0/x/x Port Config Error Change (CEC) ? RW1C
    #define CND003_USB30MMIO_DBC_PLC       BIT22                   // 0/0/x/x Port Link Status Change (PLC) = RW1C
    #define CND003_USB30MMIO_DBC_PRC       BIT21                   // 0/0/x/x Port Reset Change (PRC) ? RW1C
    #define CND003_USB30MMIO_DBC_CSC       BIT17                   // 0/0/x/x Connect Status Change (CSC) ? RW1C
    #define CND003_USB30MMIO_DBC_PORTSPEED 0x3C00                  // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_DBC_PLS       0x1E0                   // 0101b/0101b/x/x Port Link State (PLS) ? RO
    #define CND003_USB30MMIO_DBC_PR        BIT4                    // 0/0/x/x Port Reset (PR) ? RO
    #define CND003_USB30MMIO_DBC_PED       BIT1                    // 0/0/x/x Port Enabled/Disabled (PED) ? RW
    #define CND003_USB30MMIO_DBC_CCS       BIT0                    // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_CONTEXT_PTR_REG_DCCPLO 0x330 // xHCI Debug Capability Context Pointer Register (DCCPLO)
    #define CND003_USB30MMIO_DCCPLO    0xFFFFFFF0  // 0/0/x/x Debug Capability Context Pointer Register ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_CONTEXT_PTR_REG_DCCPHI 0x334 // xHCI Debug Capability Context Pointer Register (DCCPHI)
    #define CND003_USB30MMIO_DCCPHI CND003_USB30MMIO_XHCI_DEBUG_CAP_CONTEXT_PTR_REG_DCCPHI // 0/0/x/x Debug Capability Context Pointer Register ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_DEV_DESCRIPTOR_INFO_REG_1_DCDDI1 0x338 // xHCI Debug Capability Device Descriptor Info Register 1(DCDDI1)
    #define CND003_USB30MMIO_DCVID         0xFFFF0000  // 0h/0h/x/x Vendor ID ? RW
    #define CND003_USB30MMIO_DCDBGPROTOCOL 0xFF        // 0/0/x/x DbC Protocol ? RW
#define CND003_USB30MMIO_XHCI_DEBUG_CAP_DEV_DESCRIPTOR_INFO_REG_2_DCDDI2 0x33C // xHCI Debug Capability Device Descriptor Info Register 2(DCDDI2)
    #define CND003_USB30MMIO_DCDEVREV      0xFFFF0000  // 0h/0h/x/x Device Revision ? RW. This field is presented by the Debug Device i...
    #define CND003_USB30MMIO_DCPRODUCTID   0xFFFF      // 0/0/x/x Product ID ? RW. This field is presented by the Debug Device in the U...
#define CND003_USB30MMIO_USB2_PORT_1_STA_AND_CTL_REG_PORTSC 0x420 // USB2 Port 1 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_DR1           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE1          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE1          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE1          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_PLC1          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC1          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC1          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_PEC1          BIT18           // 0/0/x/x Port Enabled/Disabled Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC1          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS1          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC1          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED1    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP1           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS1          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR1           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA1          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED1          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS1          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB2_PORT_1_PM_STA_AND_CTL_REG_PORTPMSC 0x424 // USB2 Port 1 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_PTESTCTL1 0xF0000000              // 0/0/x/x Port Test Control ? RW
    #define CND003_USB30MMIO_HLE1      BIT16                   // 0/0/x/x Hardware LPM Enable (HLE)
    #define CND003_USB30MMIO_L1DEVSLT1 0xFF00                  // 0/0/x/x L1 Device Slot ? RW
    #define CND003_USB30MMIO_BESL1     0xF0                    // 0/0/x/x Best Effort Service Latency (BESL) ? RW
    #define CND003_USB30MMIO_RWE1      BIT3                    // 0/0/x/x Remote Wake Enable (RWE) ? RW
    #define CND003_USB30MMIO_L1S1      (BIT0 + BIT1 + BIT2)    // 0/0/x/x L1 Status (L1S) ? RO
#define CND003_USB30MMIO_USB2_PORT_1_USB2_PROTOCOL_PORTHLPMC 0x42C // USB2 Port 1 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define CND003_USB30MMIO_BESLD1    0x3C00          // 0/0/x/x Best Effort Service Latency Deep (BESLD) ? RWS 
    #define CND003_USB30MMIO_L1TMOUT1  0x3FC           // 0/0/x/x L1 Timeout ? RWS
    #define CND003_USB30MMIO_HIRDM1    (BIT0 + BIT1)   // 0/0/x/x Host Initiated Resume Duration Mode (HIRDM)
#define CND003_USB30MMIO_USB2_PORT_2_STA_AND_CTL_REG_PORTSC 0x430 // USB2 Port 2 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_DR2           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE2          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE2          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE2          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_PLC2          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC2          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC2          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_PEC2          BIT18           // 0/0/x/x Port Enabled/Disabled Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC2          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS2          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC2          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED2    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP2           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS2          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR2           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA2          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED2          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS2          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB2_PORT_2_PM_STA_AND_CTL_REG_PORTPMSC 0x434 // USB2 Port 2 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_PTESTCTL2 0xF0000000              // 0/0/x/x Port Test Control ? RW
    #define CND003_USB30MMIO_HLE2      BIT16                   // 0/0/x/x Hard ware LPM Enable (HLE)
    #define CND003_USB30MMIO_L1DEVSLT2 0xFF00                  // 0/0/x/x L1 Device Slot ? RW
    #define CND003_USB30MMIO_BESL2     0xF0                    // 0/0/x/x Best Effort Service Latency (BESL) ? RW
    #define CND003_USB30MMIO_RWE2      BIT3                    // 0/0/x/x Remote Wake Enable (RWE) ? RW
    #define CND003_USB30MMIO_L1S2      (BIT0 + BIT1 + BIT2)    // 0/0/x/x L1 Status (L1S) ? RO
#define CND003_USB30MMIO_USB2_PORT_2_USB2_PROTOCOL_PORTHLPMC 0x43C // USB2 Port 2 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define CND003_USB30MMIO_BESLD2    0x3C00          // 0/0/x/x Best Effort Service Latency Deep (BESLD) ? RWS
    #define CND003_USB30MMIO_L1TMOUT2  0x3FC           // 0/0/x/x L1 Timeout ? RWS
    #define CND003_USB30MMIO_HIRDM2    (BIT0 + BIT1)   // 0/0/x/x Host Initiated Resume Duration Mode (HIRDM) 
#define CND003_USB30MMIO_USB2_PORT_3_STA_AND_CTL_REG_PORTSC 0x440 // USB2 Port 3 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_DR3           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE3          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE3          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE3          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_PLC3          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC3          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC3          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_PEC3          BIT18           // 0/0/x/x Port Enabled/Disabled Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC3          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS3          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC3          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED3    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP3           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS3          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR3           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA3          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED3          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS3          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB2_PORT_3_PM_STA_AND_CTL_REG_PORTPMSC 0x444 // USB2 Port 3 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_PTESTCTL3 0xF0000000              // 0/0/x/x Port Test Control ? RW
    #define CND003_USB30MMIO_HLE3      BIT16                   // 0/0/x/x Hard ware LPM Enable (HLE)
    #define CND003_USB30MMIO_L1DEVSLT3 0xFF00                  // 0/0/x/x L1 Device Slot ? RW
    #define CND003_USB30MMIO_BESL3     0xF0                    // 0/0/x/x Best Effort Service Latency (BESL) ? RW
    #define CND003_USB30MMIO_RWE3      BIT3                    // 0/0/x/x Remote Wake Enable (RWE) ? RW
    #define CND003_USB30MMIO_L1S3      (BIT0 + BIT1 + BIT2)    // 0/0/x/x L1 Status (L1S) ? RO
#define CND003_USB30MMIO_USB2_PORT_3_USB2_PROTOCOL_PORTHLPMC 0x44C // USB2 Port 3 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define CND003_USB30MMIO_BESLD3    0x3C00          // 0/0/x/x Best Effort Service Latency Deep (BESLD) - RWS 
    #define CND003_USB30MMIO_L1TMOUT3  0x3FC           // 0/0/x/x L1 Timeout - RWS
    #define CND003_USB30MMIO_HIRDM3    (BIT0 + BIT1)   // 0/0/x/x Host Initiated Resume Duration Mode (HIRDM)
#define CND003_USB30MMIO_USB2_PORT_4_STA_AND_CTL_REG_PORTSC 0x450 // USB2 Port 4 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_DR4           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE4          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE4          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE4          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_PLC4          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC4          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC4          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_PEC4          BIT18           // 0/0/x/x Port Enabled/Disabled Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC4          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS4          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC4          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED4    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP4           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS4          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR4           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA4          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED4          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS4          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB2_PORT_4_PM_STA_AND_CTL_REG_PORTPMSC 0x454 // USB2 Port 4 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_PTESTCTL4 0xF0000000              // 0/0/x/x Port Test Control ? RW
    #define CND003_USB30MMIO_HLE4      BIT16                   // 0/0/x/x Hard ware LPM Enable (HLE)
    #define CND003_USB30MMIO_L1DEVSLT4 0xFF00                  // 0/0/x/x L1 Device Slot  ? RW
    #define CND003_USB30MMIO_BESL4     0xF0                    // 0/0/x/x Best Effort Service Latency (BESL) ? RW
    #define CND003_USB30MMIO_RWE4      BIT3                    // 0/0/x/x Remote Wake Enable (RWE) ? RW
    #define CND003_USB30MMIO_L1S4      (BIT0 + BIT1 + BIT2)    // 0/0/x/x L1 Status (L1S) ? RO
#define CND003_USB30MMIO_USB2_PORT_4_USB2_PROTOCOL_PORTHLPMC 0x45C // USB2 Port 4 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define CND003_USB30MMIO_BESLD4    0x3C00          // 0/0/x/x Best Effort Service Latency Deep (BESLD) ? RWS
    #define CND003_USB30MMIO_L1TMOUT4  0x3FC           // 0/0/x/x L1 Timeout ? RWS
    #define CND003_USB30MMIO_HIRDM4    (BIT0 + BIT1)   // 0/0/x/x Host Initiated Resume Duration Mode (HIRDM)
#define CND003_USB30MMIO_USB2_PORT_5_STA_AND_CTL_REG_PORTSC 0x460 // USB2 Port 5 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_DR5           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE5          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE5          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE5          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_PLC5          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC5          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC5          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_PEC5          BIT18           // 0/0/x/x Port Enabled/Disabled Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC5          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS5          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC5          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED5    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP5           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS5          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR5           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA5          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED5          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS5          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB2_PORT_5_PM_STA_AND_CTL_REG_PORTPMSC 0x464 // USB2 Port 5 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_PTESTCTL5 0xF0000000              // 0/0/x/x Port Test Control ? RW
    #define CND003_USB30MMIO_HLE5      BIT16                   // 0/0/x/x Hard ware LPM Enable (HLE)
    #define CND003_USB30MMIO_L1DEVSLT5 0xFF00                  // 0/0/x/x L1 Device Slot ? RW
    #define CND003_USB30MMIO_BESL5     0xF0                    // 0/0/x/x Best Effort Service Latency (BESL) ? RW
    #define CND003_USB30MMIO_RWE5      BIT3                    // 0/0/x/x Remote Wake Enable (RWE) ? RW
    #define CND003_USB30MMIO_L1S5      (BIT0 + BIT1 + BIT2)    // 0/0/x/x L1 Status (L1S) ? RO
#define CND003_USB30MMIO_USB2_PORT_5_USB2_PROTOCOL_PORTHLPMC 0x46C // USB2 Port 5 USB2 Protocol PORTHLPMC (PORTHLPMC)
    #define CND003_USB30MMIO_BESLD5    0x3C00          // 0/0/x/x Best Effort Service Latency Deep (BESLD) ? RWS
    #define CND003_USB30MMIO_L1TMOUT5  0x3FC           // 0/0/x/x L1 Timeout ? RWS
    #define CND003_USB30MMIO_HIRDM5    (BIT0 + BIT1)   // 0/0/x/x Host Initiated Resume Duration Mode (HIRDM)
#define CND003_USB30MMIO_USB3_PORT_1_STA_AND_CTL_REG_PORTSC 0x470 // USB3 Port 1 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_WPR6          BIT31           // 0/x/x/x Warm Port Reset (WPR) ? RW1S/RsvdZ
    #define CND003_USB30MMIO_DR6           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE6          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE6          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE6          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_CAS6          BIT24           // 0/0/x/x Cold Attach Status (CAS) ? RO
    #define CND003_USB30MMIO_CEC6          BIT23           // 0/x/x/x Port Config Error Change (CEC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PLC6          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC6          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC6          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_WRC6          BIT19           // 0/x/x/x Warm Port Reset Change (WRC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PEC6          BIT18           // 0/0/x/x Port Enable/Disable Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC6          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS6          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC6          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED6    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP6           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS6          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR6           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA6          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED6          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS6          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB3_PORT_1_PM_STA_AND_CTL_REG_PORTPMSC 0x474 // USB3 Port 1 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_FLA6          BIT16       // 0/0/x/x Force Link PM Accept (FLA) ? RW
    #define CND003_USB30MMIO_U2TIMEOUT6    0xFF00      // 0/0/x/x U2 Timeout ? RWS
    #define CND003_USB30MMIO_U1TIMEOUT6    0xFF        // 0/0/x/x U1 Timeout ? RWS
#define CND003_USB30MMIO_USB3_PORT_1_PORT_LINK_INFO_REG_PORTLI 0x478 // USB3 Port 1 Port Link Info Register (PORTLI)
    #define CND003_USB30MMIO_LINKERRCNT6   0xFFFF      // 0/0/x/x Link Error Count ? RO
#define CND003_USB30MMIO_USB3_PORT_2_STA_AND_CTL_REG_PORTSC 0x480 // USB3 Port 2 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_WPR7          BIT31           // 0/x/x/x Warm Port Reset (WPR) ? RW1S/RsvdZ
    #define CND003_USB30MMIO_DR7           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE7          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE7          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE7          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_CAS7          BIT24           // 0/0/x/x Cold Attach Status (CAS) ? RO
    #define CND003_USB30MMIO_CEC7          BIT23           // 0/x/x/x Port Config Error Change (CEC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PLC7          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC7          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC7          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_WRC7          BIT19           // 0/x/x/x Warm Port Reset Change (WRC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PEC7          BIT18           // 0/0/x/x Port Enable/Disable Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC7          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS7          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC7          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED7    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP7           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS7          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR7           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA7          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED7          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS7          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB3_PORT_2_PM_STA_AND_CTL_REG_PORTPMSC 0x484 // USB3 Port 2 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_FLA7          BIT16       // 0/0/x/x Force Link PM Accept (FLA) ? RW
    #define CND003_USB30MMIO_U2TIMEOUT7    0xFF00      // 0/0/x/x U2 Timeout ? RWS
    #define CND003_USB30MMIO_U1TIMEOUT7    0xFF        // 0/0/x/x U1 Timeout ? RWS
#define CND003_USB30MMIO_USB3_PORT_2_PORT_LINK_INFO_REG_PORTLI 0x488 // USB3 Port 2 Port Link Info Register (PORTLI)
    #define CND003_USB30MMIO_LINKERRCNT7   0xFFFF      // 0/0/x/x Link Error Count ? RO
#define CND003_USB30MMIO_USB3_PORT_3_STA_AND_CTL_REG_PORTSC 0x490 // USB3 Port 3 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_WPR8          BIT31           // 0/x/x/x Warm Port Reset (WPR) ? RW1S/RsvdZ
    #define CND003_USB30MMIO_DR8           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE8          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE8          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE8          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_CAS8          BIT24           // 0/0/x/x Cold Attach Status (CAS) ? RO
    #define CND003_USB30MMIO_CEC8          BIT23           // 0/X/x/x Port Config Error Change (CEC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PLC8          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC8          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC8          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_WRC8          BIT19           // 0/x/x/x Warm Port Reset Change (WRC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PEC8          BIT18           // 0/0/x/x Port Enable/Disable Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC8          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS8          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC8          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED8    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP8           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS8          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR8           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA8          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED8          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS8          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB3_PORT_3_PM_STA_AND_CTL_REG_PORTPMSC 0x494 // USB3 Port 3 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_FLA8          BIT16       // 0/0/x/x Force Link PM Accept (FLA) ? RW
    #define CND003_USB30MMIO_U2TIMEOUT8    0xFF00      // 0/0/x/x U2 Timeout ? RWS
    #define CND003_USB30MMIO_U1TIMEOUT8    0xFF        // 0/0/x/x U1 Timeout ? RWS
#define CND003_USB30MMIO_USB3_PORT_3_PORT_LINK_INFO_REG_PORTLI 0x498 // USB3 Port 3 Port Link Info Register (PORTLI)
    #define CND003_USB30MMIO_LINKERRCNT8   0xFFFF      // 0/0/x/x Link Error Count ? RO
#define CND003_USB30MMIO_USB3_1_PORT_1_STA_AND_CTL_REG_PORTSC 0x4A0 // USB3.1 Port 1 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_WPR9          BIT31           // 0/x/x/x Warm Port Reset (WPR) ? RW1S/RsvdZ
    #define CND003_USB30MMIO_DR9           BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE9          BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE9          BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE9          BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_CAS9          BIT24           // 0/0/x/x Cold Attach Status (CAS) ? RO
    #define CND003_USB30MMIO_CEC9          BIT23           // 0/x/x/x Port Config Error Change (CEC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PLC9          BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC9          BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC9          BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_WRC9          BIT19           // 0/x/x/x Warm Port Reset Change (WRC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PEC9          BIT18           // 0/0/x/x Port Enable/Disable Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC9          BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS9          BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC9          (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED9    0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP9           BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS9          0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR9           BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA9          BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED9          BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS9          BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB3_1_PORT_1_PM_STA_AND_CTL_REG_PORTPMSC 0x4A4 // USB3.1 Port 1 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_FLA9          BIT16       // 0/0/x/x Force Link PM Accept (FLA) ? RW
    #define CND003_USB30MMIO_U2TIMEOUT9    0xFF00      // 0/0/x/x U2 Timeout ? RWS
    #define CND003_USB30MMIO_U1TIMEOUT9    0xFF        // 0/0/x/x U1 Timeout ? RWS
#define CND003_USB30MMIO_USB3_1_PORT_1_PORT_LINK_INFO_REG_PORTLI 0x4A8 // USB3.1 Port 1 Port Link Info Register (PORTLI)
    #define CND003_USB30MMIO_LINKERRCNT9   0xFFFF      // 0/0/x/x Link Error Count ? RO
#define CND003_USB30MMIO_USB3_1_PORT_2_STA_AND_CTL_REG_PORTSC 0x4B0 // USB3.1 Port 2 Status and Control Register (PORTSC)
    #define CND003_USB30MMIO_WPR10         BIT31           // 0/x/x/x Warm Port Reset (WPR) ? RW1S/RsvdZ
    #define CND003_USB30MMIO_DR10          BIT30           // 0/0/x/x Device Removable (DR) ? RO
    #define CND003_USB30MMIO_WOE10         BIT27           // 0/0/x/x Wake on Over-current Enable (WOE) ? RWS
    #define CND003_USB30MMIO_WDE10         BIT26           // 0/0/x/x Wake on Disconnect Enable (WDE) ? RWS
    #define CND003_USB30MMIO_WCE10         BIT25           // 0/0/x/x Wake on Connect Enable (WCE) ? RWS
    #define CND003_USB30MMIO_CAS10         BIT24           // 0/0/x/x Cold Attach Status (CAS) ? RO
    #define CND003_USB30MMIO_CEC10         BIT23           // 0/x/x/x Port Config Error Change (CEC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PLC10         BIT22           // 0/0/x/x Port Link State Change (PLC) ? RW1CS
    #define CND003_USB30MMIO_PRC10         BIT21           // 0/0/x/x Port Reset Change (PRC) ? RW1CS
    #define CND003_USB30MMIO_OCC10         BIT20           // 0/0/x/x Over-current Change (OCC) ? RW1CS
    #define CND003_USB30MMIO_WRC10         BIT19           // 0/x/x/x Warm Port Reset Change (WRC) ? RW1CS/RsvdZ
    #define CND003_USB30MMIO_PEC10         BIT18           // 0/0/x/x Port Enable/Disable Change (PEC) ? RW1CS
    #define CND003_USB30MMIO_CSC10         BIT17           // 0/0/x/x Connect Status Change (CSC) ? RW1CS
    #define CND003_USB30MMIO_LWS10         BIT16           // 0/0/x/x Port Link State Write Strobe (LWS) ? RW
    #define CND003_USB30MMIO_PIC10         (BIT14 + BIT15) // 0/0/x/x Port Indicator Control (PIC) ? RWS
    #define CND003_USB30MMIO_PORTSPEED10   0x3C00          // 0/0/x/x Port Speed (Port Speed) ? RO
    #define CND003_USB30MMIO_PP10          BIT9            // 1b/1b/x/x Port Power (PP) ? RWS
    #define CND003_USB30MMIO_PLS10         0x1E0           // 5h/5h/x/x Port Link State (PLS) ? RWS
    #define CND003_USB30MMIO_PR10          BIT4            // 0/0/x/x Port Reset (PR) ? RW1S
    #define CND003_USB30MMIO_OCA10         BIT3            // 0/0/x/x Over-current Active (OCA) ? RO
    #define CND003_USB30MMIO_PED10         BIT1            // 0/0/x/x Port Enabled/Disabled (PED) ? RW1CS
    #define CND003_USB30MMIO_CCS10         BIT0            // 0/0/x/x Current Connect Status (CCS) ? RO
#define CND003_USB30MMIO_USB3_1_PORT_2_PM_STA_AND_CTL_REG_PORTPMSC 0x4B4 // USB3.1 Port 2 PM Status and Control Register (PORTPMSC)
    #define CND003_USB30MMIO_FLA10         BIT16       // 0/0/x/x Force Link PM Accept (FLA) ? RW
    #define CND003_USB30MMIO_U2TIMEOUT10   0xFF00      // 0/0/x/x U2 Timeout ? RWS
    #define CND003_USB30MMIO_U1TIMEOUT10   0xFF        // 0/0/x/x U1 Timeout ? RWS
#define CND003_USB30MMIO_USB3_1_PORT_2_PORT_LINK_INFO_REG_PORTLI 0x4B8 // USB3.1 Port 2 Port Link Info Register (PORTLI)
    #define CND003_USB30MMIO_LINKERRCNT10  0xFFFF      // 0/0/x/x Link Error Count ? RO
// CND003_OPTCFG_XHCI
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX01 0x1 // xHCI Option RX01
    #define CND003_OPTCFGXHCI_SS_REDUCE    BIT3            // 0/0/x/x Frame Timer Reduce Mode
    #define CND003_OPTCFGXHCI_CROSSMF_EN   BIT2            // 0/0/x/x Cross microFrame Enable
    #define CND003_OPTCFGXHCI_CROSSMF_CNT  (BIT0 + BIT1)   // 0/0/x/x Cross microFrame Count
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX03 0x3 // xHCI Option RX03
    #define CND003_OPTCFGXHCI_DCERXRPRI    (BIT6 + BIT7)   // 0/0/x/x Debug Capability Event Ring Upstream Read Priority
    #define CND003_OPTCFGXHCI_DCERXWPRI    (BIT4 + BIT5)   // 0/0/x/x Debug Capability Event Ring Upstream Write Priority
    #define CND003_OPTCFGXHCI_DCBMXRPRI    (BIT2 + BIT3)   // 0/0/x/x Debug Capability Buffer Management Upstream Read Priority
    #define CND003_OPTCFGXHCI_DCBMXWPRI    (BIT0 + BIT1)   // 0/0/x/x Debug Capability Buffer Management Upstream Write Priority
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX04 0x4 // xHCI Option RX04
    #define CND003_OPTCFGXHCI_HDXRPRI  (BIT30 + BIT31) // 0/0/x/x HSBI Data Upstream Read Priority
    #define CND003_OPTCFGXHCI_HDXWPRI  (BIT28 + BIT29) // 0/0/x/x HSBI Data Upstream Write Priority
    #define CND003_OPTCFGXHCI_HBXRPRI  (BIT26 + BIT27) // 0/0/x/x HSBI Schedule Upstream Read Priority
    #define CND003_OPTCFGXHCI_HBXWPRI  (BIT24 + BIT25) // 0/0/x/x HSBI Schedule Upstream Write Priority
    #define CND003_OPTCFGXHCI_S0XRPRI  (BIT22 + BIT23) // 0/0/x/x SSBI Schedule Upstream Read Priority
    #define CND003_OPTCFGXHCI_S0XWPRI  (BIT20 + BIT21) // 0/0/x/x SSBI Schedule Upstream Write Priority
    #define CND003_OPTCFGXHCI_B0XRPRI  (BIT18 + BIT19) // 0/0/x/x Buffer Management Upstream Read Priority
    #define CND003_OPTCFGXHCI_B0XWPRI  (BIT16 + BIT17) // 0/0/x/x Buffer Management Upstream Write Priority
    #define CND003_OPTCFGXHCI_PTXRPRI  (BIT14 + BIT15) // 0/0/x/x PIPETLB Upstream Read Priority
    #define CND003_OPTCFGXHCI_PTXWPRI  (BIT12 + BIT13) // 0/0/x/x PIPETLB Upstream Write Priority
    #define CND003_OPTCFGXHCI_ERXRPRI  (BIT10 + BIT11) // 0/0/x/x Event Ring Upstream Read Priority
    #define CND003_OPTCFGXHCI_ERXWPRI  (BIT8 + BIT9)   // 0/0/x/x Event Ring Upstream Write Priority
    #define CND003_OPTCFGXHCI_DAXRPRI  (BIT6 + BIT7)   // 0/0/x/x Normal DMA Upstream Read Priority
    #define CND003_OPTCFGXHCI_DAXWPRI  (BIT4 + BIT5)   // 0/0/x/x Normal DMA Upstream Write Priority
    #define CND003_OPTCFGXHCI_CDXRPRI  (BIT2 + BIT3)   // 0/0/x/x Command Ring Upstream Read Priority
    #define CND003_OPTCFGXHCI_CDXWPRI  (BIT0 + BIT1)   // 0/0/x/x Command Ring Upstream Write Priority
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX08 0x8 // xHCI Option RX08
    #define CND003_OPTCFGXHCI_SSISOPRI (BIT14 + BIT15) // 01b/01b/x/x SSBI ISO Transaction Upstream Request Priority
    #define CND003_OPTCFGXHCI_HSISOPRI (BIT12 + BIT13) // 01b/01b/x/x HSBI ISO Transaction Upstream Request Priority
    #define CND003_OPTCFGXHCI_TCXRPRI  (BIT10 + BIT11) // 01b/01b/x/x TRB Cache Upstream Read Priority
    #define CND003_OPTCFGXHCI_TCXWPRI  (BIT8 + BIT9)   // 0/0/x/x TRB Cache Upstream Write Priority
    #define CND003_OPTCFGXHCI_MDXRPRI  (BIT6 + BIT7)   // 0/0/x/x MCU Data Upstream Read Priority 
    #define CND003_OPTCFGXHCI_MDXWPRI  (BIT4 + BIT5)   // 0/0/x/x MCU Data Upstream Write Priority
    #define CND003_OPTCFGXHCI_MIXRPRI  (BIT2 + BIT3)   // 0/0/x/x MCU Instruction Upstream Read Priority
    #define CND003_OPTCFGXHCI_MIXWPRI  (BIT0 + BIT1)   // 0/0/x/x MCU Instruction Upstream Write Priority
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX0A 0xA // xHCI Option RX0A
    #define CND003_OPTCFGXHCI_B1XRPRI          (BIT6 + BIT7)   // 0/0/x/x Buffer Management Upstream Read (Path 1) Priority
    #define CND003_OPTCFGXHCI_B1XWPRI          (BIT4 + BIT5)   // 0/0/x/x Buffer Management Upstream Write (Path 0) Priority
    #define CND003_OPTCFGXHCI_DTKEEPEN         BIT3            // 0b/0b/0b/x Data Keep Enable
    #define CND003_OPTCFGXHCI_NONESNOOPEN      BIT2            // 1b/1b/X/x xHCI Non-Snoop Enable
    #define CND003_OPTCFGXHCI_XHCIPW256B_EN    BIT1            // 1b/1b/1b/x xHCI Upstream Write Max 256Bytes Capability Enable
    #define CND003_OPTCFGXHCI_XHCIPR256B_EN    BIT0            // 1b/1b/1b/x xHCI Upstream Read Max 256Bytes Capability Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX0B 0xB // xHCI Option RX0B
    #define CND003_OPTCFGXHCI_NRDYNOEMPTY_THRESH   (BIT3 + BIT4 + BIT5)    // 0/0/x/x NRDY Address List Not Empty Interrupt MCU Threshold Setting
    #define CND003_OPTCFGXHCI_NRDYLIST_THRESH      (BIT0 + BIT1 + BIT2)    // 100b/100b/x/x NRDY Address List Full Threshold Setting
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX0C 0xC // xHCI Option RX0C
    #define CND003_OPTCFGXHCI_ERDYNUMP_CHKEN       BIT7    // 0/0/x/x SS ERDY NumP Field Check Enable
    #define CND003_OPTCFGXHCI_ISOFRAMEID_BYPASS    BIT6    // 0/0/x/x ISO TRB ?Frame ID? Bypass Check Enable
    #define CND003_OPTCFGXHCI_CTRLDIR_CHKEN        BIT5    // 0/0/x/x Enable to Check DIR bit in Control Transfer TP/DP
    #define CND003_OPTCFGXHCI_TUSTMOUT_CHKEN       BIT4    // 1b/1b/x/x Enable to Check 10 us TimeOut
    #define CND003_OPTCFGXHCI_SCHATMFBNDRY         BIT3    // 0/0/x/x Schedule Async Transaction at microFrame Boundary
    #define CND003_OPTCFGXHCI_NTRBTD1SO_EN         BIT2    // 1b/1b/x/x Enable to Combine ISO Non-Transfer TD with next TD in 1 SO
    #define CND003_OPTCFGXHCI_PIPEPREFETCH_EN      BIT1    // 0/0/x/x Enable to Pre-Fetch Pipe
    #define CND003_OPTCFGXHCI_TDQEMPTY_CHKEN       BIT0    // 0/0/x/x Periodic TD Queue Empty Check Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX0D 0xD // xHCI Option RX0D
    #define CND003_OPTCFGXHCI_BLKENT_EN        BIT7    // 0/0/x/x Enable to Block Event TRB Send to System Memory Before S/W Clearing E...
    #define CND003_OPTCFGXHCI_MCUHWRST_EN      BIT6    // 0/0/x/x MCU HW Reset Enable if HCRST/LHCRST
    #define CND003_OPTCFGXHCI_DMAMUXRST_EN     BIT5    // 1b/1b/x/x DMAMUX Reset Enable if HCRST/LHCRST
    #define CND003_OPTCFGXHCI_PSCEG_PENDING_EN BIT4    // 0/0/x/x Generate another ?Port Status Change? Event for Pending Status Change...
    #define CND003_OPTCFGXHCI_BYPASS_IPLHCRST  BIT3    // 1b/1b/x/x Bypass LHCRST to SSIP XH_RESET_
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_EN   BIT2    // 0/0/x/x MCU Selective Handle Downstream Cycle
    #define CND003_OPTCFGXHCI_DSMCUHDL_EN      BIT1    // 0/0/x/x MCU Handle Downstream Cycle
    #define CND003_OPTCFGXHCI_DBBLKDS_EN       BIT0    // 0/0/x/x Block Downstream Cycle if Doorbell Queue is not Empty.
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX0E 0xE // xHCI Option RX0E
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_CFG0     BIT15                   // 0/0/x/x MCU Selective Handle Downstream Cycle 0
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_ADDR0    0xFFF                   // 0/0/x/x MCU Selective Handle Downstream Cycle Address 0
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX10 0x10 // xHCI Option RX10
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_CFG1     BIT15                   // 0/0/x/x MCU Selective Handle Downstream Cycle 1
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_ADDR1    0xFFF                   // 0/0/x/x MCU Selective Handle Downstream Cycle Address 1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX12 0x12 // xHCI Option RX12
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_CFG2     BIT15                   // 0/0/x/x MCU Selective Handle Downstream Cycle 2
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_ADDR2    0xFFF                   // 0/0/x/x MCU Selective Handle Downstream Cycle Address 2
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX14 0x14 // xHCI Option RX14
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_CFG3     BIT15                   // 0/0/x/x MCU Selective Handle Downstream Cycle3
    #define CND003_OPTCFGXHCI_DSMCUSELHDL_ADDR3    0xFFF                   // 0/0/x/x MCU Selective Handle Downstream Cycle Address 3
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX16 0x16 // xHCI Option RX16
    #define CND003_OPTCFGXHCI_SS_NFLSASYEP_EN      BIT15   // 1b/1b/x/x Not Flush Last Async Endpoint Enable Bit
    #define CND003_OPTCFGXHCI_SS_PERASYPIPE_EN     BIT14   // 0/0/1b/x xHCI SSBI Periodic and Async Pipe Enable
    #define CND003_OPTCFGXHCI_SS_2ASYNCSHARE_EN    BIT13   // 1b/1b/1b/x xHCI SSBI 2 Async Control Share Mode Enable
    #define CND003_OPTCFGXHCI_SS_EPONEONLY_EN      BIT12   // 1b/1b/1b/x xHCI SSBI Enable NOT Care SO if Only 1 Async Endpoint Active
    #define CND003_OPTCFGXHCI_SS_ASYNCSTP_PARM     0xFFF   // 272h/272h/x/x xHCI SSBI Schedule Stop Async List Before SOF Boundary Timer Ad...
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX18 0x18 // xHCI Option RX18
    #define CND003_OPTCFGXHCI_HS_PERASYPIPE_EN     BIT14   // 0b/0/0/x xHCI HSBI Periodic and Async Pipe Enable
    #define CND003_OPTCFGXHCI_HS_2ASYNCSHARE_EN    BIT13   // 0b/0/0/x xHCI HSBI 2 Async Control Share Mode Enable
    #define CND003_OPTCFGXHCI_HS_EPONEONLY_EN      BIT12   // 0/0/1b/x xHCI HSBI Enable NOT Care SO if Only 1 Async Endpoint Active
    #define CND003_OPTCFGXHCI_HS_ASYNCSTP_PARM     0xFFF   // 272h/272h/x/x xHCI HSBI Schedule Stop Async List Before SOF Boundary Timer Ad...
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX1A 0x1A // xHCI Option RX1A
    #define CND003_OPTCFGXHCI_SS_IN_LPTDTRB_EN     BIT7    // 0/0/x/x SSBI Enable to Check ?Partial Completed TD? for IN Transaction
    #define CND003_OPTCFGXHCI_SS_OUT_LPTDTRB_EN    BIT6    // 0/0/x/x SSBI Enable to Check ?Partial Completed TD? for OUT Transaction
    #define CND003_OPTCFGXHCI_SS_NUMPCHKEN         BIT5    // 1b/1/x/x SSBI Enable Register for TRANS Checking the NUMP Field in the Device...
    #define CND003_OPTCFGXHCI_SS_BLKEP_RLTDLTRB_EN BIT4    // 0/0/x/x SSBI Bulk Endpoint Service to the Last TRB in the Transfer Ring at La...
    #define CND003_OPTCFGXHCI_SS_INTEP_TDDB_EN     BIT3    // 0/0/x/x SSBI Interrupt Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then W...
    #define CND003_OPTCFGXHCI_SS_ISOEP_TDDB_EN     BIT2    // 0/0/x/x SSBI Isoch Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wait ...
    #define CND003_OPTCFGXHCI_SS_CTLEP_TDDB_EN     BIT1    // 0/0/x/x SSBI Control Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wai...
    #define CND003_OPTCFGXHCI_SS_BLKEP_TDDB_EN     BIT0    // 0/0/x/x SSBI Bulk Endpoint 1TD 1Doorbell Enable. SSBI Do 1 TD and then Wait f...
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX1B 0x1B // xHCI Option RX1B
    #define CND003_OPTCFGXHCI_HS_IN_LPTDTRB_EN     BIT7            // 0/0/x/x HSBI Enable to Check ?Partial Completed TD? for IN Transaction
    #define CND003_OPTCFGXHCI_HS_OUT_LPTDTRB_EN    BIT6            // 0/0/x/x HSBI Enable to Check ?Partial Completed TD? for OUT Transaction
    #define CND003_OPTCFGXHCI_HS_INTEP_TDDB_EN     BIT3            // 0/0/x/x HSBI Interrupt Endpoint 1TD 1Doorbell Enable
    #define CND003_OPTCFGXHCI_HS_ISOEP_TDDB_EN     BIT2            // 0/0/x/x HSBI Isoch Endpoint 1TD 1Doorbell Enable
    #define CND003_OPTCFGXHCI_HS_CTLEP_TDDB_EN     BIT1            // 0/0/x/x HSBI Control Endpoint 1TD 1Doorbell Enable
    #define CND003_OPTCFGXHCI_HS_BLKEP_TDDB_EN     BIT0            // 0/0/x/x HSBI Bulk Endpoint 1TD 1Doorbell Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX1C 0x1C // xHCI Option RX1C
    #define CND003_OPTCFGXHCI_SOVD (BIT0 + BIT1)   // 11b/11b/x/x XHRUT SRAM Overflow Depth
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX20 0x20 // xHCI Option RX20
    #define CND003_OPTCFGXHCI_TRBCACHE_BYPASS  BIT0    // 0/0/0/0 TRB Cache/Stream Context Cache Bypass Mode Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX22 0x22 // xHCI Option RX22
    #define CND003_OPTCFGXHCI_TRBCACHE_HASHOPT0    0x7FFF  // 1249h/1249h/x/x TRB Cache HASH Option for HASHOUT[0]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX24 0x24 // xHCI Option RX24
    #define CND003_OPTCFGXHCI_TRBCACHE_HASHOPT1    0x7FFF  // 2492h/2492h/x/x TRB Cache HASH Option for HASHOUT[1]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX26 0x26 // xHCI Option RX26
    #define CND003_OPTCFGXHCI_TRBCACHE_HASHOPT2    0x7FFF  // 4924h/4924h/x/x TRB Cache HASH Option for HASHOUT[2]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX28 0x28 // xHCI Option RX28
    #define CND003_OPTCFGXHCI_STRCACHE_HASHOPT0    0x7FFF  // 1111h/1111h/x/x Stream Context Cache HASH Option for HASHOUT[0]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX2A 0x2A // xHCI Option RX2A
    #define CND003_OPTCFGXHCI_STRCACHE_HASHOPT1    0x7FFF  // 2222h/2222h/x/x Stream Context Cache HASH Option for HASHOUT[1]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX2C 0x2C // xHCI Option RX2C
    #define CND003_OPTCFGXHCI_STRCACHE_HASHOPT2    0x7FFF  // 4444h/4444h/x/x Stream Context Cache HASH Option for HASHOUT[2]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX2E 0x2E // xHCI Option RX2E
    #define CND003_OPTCFGXHCI_STRCACHE_HASHOPT3    0x7FFF  // 4888h/4888h/x/x Stream Context Cache HASH Option for HASHOUT[3]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX30 0x30 // xHCI Option RX30
    #define CND003_OPTCFGXHCI_STRCACHE_HASHOPT4    0x7FFF  // 1248h/1248h/x/x Stream Context Cache HASH Option for HASHOUT[4]
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX40 0x40 // xHCI Option RX40
    #define CND003_OPTCFGXHCI_SSP5_FORCEU1 BIT4                    // 0/0/x/x Force Link of SS Port 5 Issue LGO_U1 to Initiate U1 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP4_FORCEU1 BIT3                    // 0/0/x/x Force Link of SS Port 4 Issue LGO_U1 to Initiate U1 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP3_FORCEU1 BIT2                    // 0/0/x/x Force Link of SS Port 3 Issue LGO_U1 to Initiate U1 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP2_FORCEU1 BIT1                    // 0/0/x/x Force Link of SS Port 2 Issue LGO_U1 to Initiate U1 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP1_FORCEU1 BIT0                    // 0/0/x/x Force Link of SS Port 1 Issue LGO_U1 to Initiate U1 Entry Sequence
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX41 0x41 // xHCI Option RX41
    #define CND003_OPTCFGXHCI_SSP5_FORCEU2 BIT4                    // 0/0/x/x Force Link of SS Port 5 Issue LGO_U2 to Initiate U2 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP4_FORCEU2 BIT3                    // 0/0/x/x Force Link of SS Port 4 Issue LGO_U2 to Initiate U2 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP3_FORCEU2 BIT2                    // 0/0/x/x Force Link of SS Port 3 Issue LGO_U2 to Initiate U2 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP2_FORCEU2 BIT1                    // 0/0/x/x Force Link of SS Port 2 Issue LGO_U2 to Initiate U2 Entry Sequence
    #define CND003_OPTCFGXHCI_SSP1_FORCEU2 BIT0                    // 0/0/x/x Force Link of SS Port 1 Issue LGO_U2 to Initiate U2 Entry Sequence
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX42 0x42 // xHCI Option RX42
    #define CND003_OPTCFGXHCI_SSP5_BERTGEN (BIT8 + BIT9)   // 0/0/x/x SS Port 5 Generate Loopback Pattern BRST or BERC Control Signal in Lo...
    #define CND003_OPTCFGXHCI_SSP4_BERTGEN (BIT6 + BIT7)   // 0/0/x/x SS Port 4 Generate Loopback Pattern BRST or BERC Control Signal in Lo...
    #define CND003_OPTCFGXHCI_SSP3_BERTGEN (BIT4 + BIT5)   // 0/0/x/x SS Port 3 Generate Loopback Pattern BRST or BERC Control Signal in Lo...
    #define CND003_OPTCFGXHCI_SSP2_BERTGEN (BIT2 + BIT3)   // 0/0/x/x SS Port 2 Generate Loopback Pattern BRST or BERC Control Signal in Lo...
    #define CND003_OPTCFGXHCI_SSP1_BERTGEN (BIT0 + BIT1)   // 0/0/x/x SS Port 1 Generate Loopback Pattern BRST or BERC Control Signal in Lo...
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX44 0x44 // xHCI Option RX44
    #define CND003_OPTCFGXHCI_SSP5_LOOPBACK    BIT4                    // 0/0/x/x SS Port 5 Loopback mMode Entry Enable
    #define CND003_OPTCFGXHCI_SSP4_LOOPBACK    BIT3                    // 0/0/x/x SS Port 4 Loopback Mode Entry Enable
    #define CND003_OPTCFGXHCI_SSP3_LOOPBACK    BIT2                    // 0/0/x/x SS Port 3 Loopback Mode Entry Enable
    #define CND003_OPTCFGXHCI_SSP2_LOOPBACK    BIT1                    // 0/0/x/x SS Port 2 Loopback Mode Entry Enable
    #define CND003_OPTCFGXHCI_SSP1_LOOPBACK    BIT0                    // 0/0/x/x SS Port 1 Loopback Mode Entry Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX45 0x45 // xHCI Option RX45
    #define CND003_OPTCFGXHCI_SSP5_SCRMBLEN    BIT4                    // 1b/1b/x/x Enable SS Port 5 Scrambling Function or Not
    #define CND003_OPTCFGXHCI_SSP4_SCRMBLEN    BIT3                    // 1b/1b/x/x Enable SS Port 4 Scrambling Function or Not
    #define CND003_OPTCFGXHCI_SSP3_SCRMBLEN    BIT2                    // 1b/1b/x/x Enable SS Port 3 Scrambling Function or Not
    #define CND003_OPTCFGXHCI_SSP2_SCRMBLEN    BIT1                    // 1b/1b/x/x Enable SS Port 2 Scrambling Function or Not
    #define CND003_OPTCFGXHCI_SSP1_SCRMBLEN    BIT0                    // 1b/1b/x/x Enable SS Port 1 Scrambling Function or Not
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX46 0x46 // xHCI Option RX46
    #define CND003_OPTCFGXHCI_SSIP_DYNPM   BIT0    // 1b/1b/x/1b USB3-IP Dynamic Clock Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX50 0x50 // xHCI Option RX50
    #define CND003_OPTCFGXHCI_XHCI_OVERALL_DYNCLKEN            BIT4                    // 0/0/x/0 XHCI_OVERALL_DYNCLKEN
    #define CND003_OPTCFGXHCI_MCUBRG_INTC_CLK_U250_DYNCLKEN    BIT3                    // 0/0/x/0 MCUBRG_INTC_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_NORMALDMA_CLK_U250_DYNCLKEN      BIT2                    // 0/0/x/0 NORMALDMA_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_CDRING_CLK_U250_DYNCLKEN         BIT1                    // 0/0/x/0 CDRING_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_BRIDGE_CLK_U250_DYNCLKEN         BIT0                    // 0/0/x/0 BRIDGE_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX51 0x51 // xHCI Option RX51
    #define CND003_OPTCFGXHCI_BUFM_CLKOUT_U250_DYNCLKEN    BIT5            // 0/0/x/0 BUFM_CLKOUT_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_BUFM_CLKIN_U250_DYNCLKEN     BIT4            // 0/0/x/0 BUFM_CLKIN_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DMAMUX_CLKW_E_DYNCLKEN       BIT3            // 0/0/x/0 DMAMUX_CLKW_E_DYNCLKEN
    #define CND003_OPTCFGXHCI_DMAMUX_CLKR_E_DYNCLKEN       BIT2            // 0/0/x/0 DMAMUX_CLKR_E_DYNCLKEN
    #define CND003_OPTCFGXHCI_DMAMUX_CLKW_U250_DYNCLKEN    BIT1            // 0/0/x/0 DMAMUX_CLKW_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DMAMUX_CLKR_U250_DYNCLKEN    BIT0            // 0/0/x/0 DMAMUX_CLKR_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX52 0x52 // xHCI Option RX52
    #define CND003_OPTCFGXHCI_SSBI_CLKDEVN_U250_DYNCLKEN   BIT6    // 0/0/x/0 SSBI_CLKDEVN_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPBI_CLKDEVN_U250_DYNCLKEN  BIT5    // 0/x/x/x SSPBI_CLKDEVN_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_MCU_TIMERC_U25_DYNCLKEN      BIT4    // 0/0/x/x MCU_TIMERC_U25_DYNCLKEN
    #define CND003_OPTCFGXHCI_MCU_TIMERC_U250_DYNCLKEN     BIT3    // 0/0/x/x MCU_TIMERC_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_FMTIMER_CLK_U60_DYNCLKEN     BIT2    // 0/0/x/0 FMTIMER_CLK_U60_DYNCLKEN
    #define CND003_OPTCFGXHCI_FMTIMER_CLK_U250_DYNCLKEN    BIT0    // 0/0/x/0 FMTIMER_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX53 0x53 // xHCI Option RX53
    #define CND003_OPTCFGXHCI_EVENTRING_CLKMSICTL_U250_DYNCLKEN    BIT6    // 0/0/x/0 EVENTRING_CLKMSICTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_EVENTRING_CLKROUTE_U250_DYNCLKEN     BIT5    // 0/0/x/0 EVENTRING_CLKROUTE_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_EVENTRING_CLKRCTL_U250_DYNCLKEN      BIT4    // 0/0/x/0 EVENTRING_CLKRCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_EVENTRING_CLKMCUREG_U250_DYNCLKEN    BIT2    // 0/0/x/0 EVENTRING_CLKMCUREG_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_EVENTRING_CLKDMAIF_U250_DYNCLKEN     BIT1    // 0/0/x/0 EVENTRING_CLKDMAIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_EVENTRING_CLKERST_U250_DYNCLKEN      BIT0    // 0/0/x/0 EVENTRING_CLKERST_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX54 0x54 // xHCI Option RX54
    #define CND003_OPTCFGXHCI_TRBCTXCACHE_CLKROUTE_U250_DYNCLKEN       BIT7            // 0/0/x/0 TRBCTXCACHE_CLKROUTE_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_TRBCTXCACHE_CLKMCUREG_U250_DYNCLKEN      BIT6            // 0/0/x/0 TRBCTXCACHE_CLKMCUREG_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_TRBCTXCACHE_CLKTRBCACHE_U250_DYNCLKEN    BIT5            // 0/0/x/0 TRBCTXCACHE_CLKTRBCACHE_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_TRBCTXCACHE_CLKDMAIF_U250_DYNCLKEN       BIT4            // 0/0/x/0 TRBCTXCACHE_CLKDMAIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_TRBCTXCACHE_CLKSTRCTX_U250_DYNCLKEN      BIT3            // 0/0/x/0 TRBCTXCACHE_CLKSTRCTX_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_PIPETLB_CLK_U250_DYNCLKEN                BIT0            // 0/0/x/0 PIPETLB_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX55 0x55 // xHCI Option RX55
    #define CND003_OPTCFGXHCI_PCIS_CLK_E_DYNCLKEN      BIT2    // 0/0/x/0 PCIS_CLK_E_DYNCLKEN
    #define CND003_OPTCFGXHCI_PCIS_CLK_U250_DYNCLKEN   BIT0    // 0/0/x/0 PCIS_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX56 0x56 // xHCI Option RX56
    #define CND003_OPTCFGXHCI_HSSCHEDULE_CLKDMA_U250_DYNCLKEN      BIT5            // 0/0/x/0 HSSCHEDULE_CLKDMA_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_HSSCHEDULE_CLKMCUREG_U250_DYNCLKEN   BIT4            // 0/0/x/0 HSSCHEDULE_CLKMCUREG_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_HSSCHEDULE_CLKASYNC2_U250_DYNCLKEN   BIT3            // 0/0/x/0 HSSCHEDULE_CLKASYNC2_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_HSSCHEDULE_CLKASYNC1_U250_DYNCLKEN   BIT2            // 0/0/x/0 HSSCHEDULE_CLKASYNC1_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_HSSCHEDULE_CLKPERIODIC_U250_DYNCLKEN BIT1            // 0/0/x/0 HSSCHEDULE_CLKPERIODIC_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_HSSCHEDULE_CLK_U250_DYNCLKEN         BIT0            // 0/0/x/0 HSSCHEDULE_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX57 0x57 // xHCI Option RX57
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLKDMA_U250_DYNCLKEN      BIT6    // 0/0/x/0 SSSCHEDULE_CLKDMA_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLKMCUREG_U250_DYNCLKEN   BIT5    // 0/0/x/0 SSSCHEDULE_CLKMCUREG_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLKNERDY_U250_DYNCLKEN    BIT4    // 0/0/x/0 SSSCHEDULE_CLKNERDY_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLKASYNC2_U250_DYNCLKEN   BIT3    // 0/0/x/0 SSSCHEDULE_CLKASYNC2_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLKASYNC1_U250_DYNCLKEN   BIT2    // 0/0/x/0 SSSCHEDULE_CLKASYNC1_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLKPERIODIC_U250_DYNCLKEN BIT1    // 0/0/x/0 SSSCHEDULE_CLKPERIODIC_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSSCHEDULE_CLK_U250_DYNCLKEN         BIT0    // 0/0/x/0 SSSCHEDULE_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX58 0x58 // xHCI Option RX58
    #define CND003_OPTCFGXHCI_SSTRANS_CLKTXIF_U250_DYNCLKEN    BIT7    // 0/0/x/0 SSTRANS_CLKTXIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKOUTCTL_U250_DYNCLKEN  BIT6    // 0/0/x/0 SSTRANS_CLKOUTCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKOUT2CTL_U250_DYNCLKEN BIT5    // 0/0/x/0 SSTRANS_CLKOUT2CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKOUT1CTL_U250_DYNCLKEN BIT4    // 0/0/x/0 SSTRANS_CLKOUT1CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKINCTL_U250_DYNCLKEN   BIT3    // 0/0/x/0 SSTRANS_CLKINCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKIN2CTL_U250_DYNCLKEN  BIT2    // 0/0/x/0 SSTRANS_CLKIN2CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKIN1CTL_U250_DYNCLKEN  BIT1    // 0/0/x/0 SSTRANS_CLKIN1CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKEPSEL_U250_DYNCLKEN   BIT0    // 0/0/x/0 SSTRANS_CLKEPSEL_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX59 0x59 // xHCI Option RX59
    #define CND003_OPTCFGXHCI_SSIPIF_U250_DYNCLKEN             BIT6    // 0/0/x/0 SSIPIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKPTMCTL_U250_DYNCLKEN  BIT5    // 0/0/x/0 SSTRANS_CLKPTMCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKSSROUTE_U250_DYNCLKEN BIT4    // 0/0/x/0 SSTRANS_CLKSSROUTE_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKITPCTL_U250_DYNCLKEN  BIT3    // 0/0/x/0 SSTRANS_CLKITPCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKPINGCTL_U250_DYNCLKEN BIT2    // 0/0/x/0 SSTRANS_CLKPINGCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKCMDCTL_U250_DYNCLKEN  BIT1    // 0/0/x/0 SSTRANS_CLKCMDCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSTRANS_CLKRXIF_U250_DYNCLKEN    BIT0    // 0/0/x/0 SSTRANS_CLKRXIF_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX5A 0x5A // xHCI Option RX5A
    #define CND003_OPTCFGXHCI_XHMCU_ARB_CLK_U250_DYNCLKEN      BIT6    // 0/0/x/0 XHMCU_ARB_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_XHMCU_ARB_CLK_E_DYNCLKEN         BIT5    // 0/0/x/0 XHMCU_ARB_CLK_E_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB3SSIPMUX_CLK_U250_DYNCLKEN    BIT4    // 0/0/x/0 USB3SSIPMUX_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_HSBIDMATRAN_CLK_U250_DYNCLKEN    BIT3    // 0/0/x/0 HSBIDMATRAN_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_MCU_CLK_U250_DYNCLKEN            BIT2    // 0/x/x/x MCU_CLK_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCBUFM_CLKOUT_U250_DYNCLKEN      BIT1    // 0/0/x/0 DCBUFM_CLKOUT_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCBUFM_CLKIN_U250_DYNCLKEN       BIT0    // 0/0/x/0 DCBUFM_CLKIN_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX5B 0x5B // xHCI Option RX5B
    #define CND003_OPTCFGXHCI_DCEVENTRING_CLKERST_U250_DYNCLKEN    BIT6    // 0/0/x/0 DCEVENTRING_CLKERST_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCEVENTRING_CLKMCUREG_U250_DYNCLKEN  BIT4    // 0/0/x/0 DCEVENTRING_CLKMCUREG_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCEVENTRING_CLKDMAIF_U250_DYNCLKEN   BIT3    // 0/0/x/0 DCEVENTRING_CLKDMAIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCEVENTRING_CLKRCTL_U250_DYNCLKEN    BIT2    // 0/0/x/0 DCEVENTRING_CLKRCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCEVENTRING_CLKROUTE_U250_DYNCLKEN   BIT1    // 0/0/x/0 DCEVENTRING_CLKROUTE_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_DCEVENTRING_CLKMSICTL_U250_DYNCLKEN  BIT0    // 0/0/x/0 DCEVENTRING_CLKMSICTL_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX5C 0x5C // xHCI Option RX5C
    #define CND003_OPTCFGXHCI_XHCI_DBC_CTLEP_U250_DYNCLKEN BIT6    // 0/0/x/0 XHCI_DBC_CTLEP_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_XHCI_DBC_INEP_U250_DYNCLKEN  BIT5    // 0/0/x/0 XHCI_DBC_INEP_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_XHCI_DBC_OUTEP_U250_DYNCLKEN BIT4    // 0/0/x/0 XHCI_DBC_OUTEP_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_XHCI_DBC_MCUIF_U250_DYNCLKEN BIT2    // 0/0/x/0 XHCI_DBC_MCUIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_XHCI_DBC_TXIF_U250_DYNCLKEN  BIT1    // 0/0/x/0 XHCI_DBC_TXIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_XHCI_DBC_RXIF_U250_DYNCLKEN  BIT0    // 0/0/x/0 XHCI_DBC_RXIF_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX5D 0x5D // xHCI Option RX5D
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLKDMA_U250_DYNCLKEN         BIT6    // 0/0/x/0 SSPSCHEDULE_CLKDMA_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLKMCUREG_U250_DYNCLKEN      BIT5    // 0/0/x/0 SSPSCHEDULE_CLKMCUREG_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLKNERDY_U250_DYNCLKEN       BIT4    // 0/0/x/0 SSPSCHEDULE_CLKNERDY_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLKASYNC2_U250_DYNCLKEN      BIT3    // 0/0/x/0 SSPSCHEDULE_CLKASYNC2_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLKASYNC1_U250_DYNCLKEN      BIT2    // 0/0/x/0 SSPSCHEDULE_CLKASYNC1_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLKPERIODIC_U250_DYNCLKEN    BIT1    // 0/0/x/0 SSPSCHEDULE_CLKPERIODIC_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPSCHEDULE_CLK_U250_DYNCLKEN            BIT0    // 0/0/x/0 SSPSCHEDULE_CLK_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX5E 0x5E // xHCI Option RX5E
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKTXIF_U250_DYNCLKEN       BIT7    // 0/0/x/0 SSPTRANS_CLKTXIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKOUTCTL_U250_DYNCLKEN     BIT6    // 0/0/x/0 SSPTRANS_CLKOUTCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKOUT2CTL_U250_DYNCLKEN    BIT5    // 0/0/x/0 SSPTRANS_CLKOUT2CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKOUT1CTL_U250_DYNCLKEN    BIT4    // 0/0/x/0 SSPTRANS_CLKOUT1CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKINCTL_U250_DYNCLKEN      BIT3    // 0/0/x/0 SSPTRANS_CLKINCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKIN2CTL_U250_DYNCLKEN     BIT2    // 0/0/x/0 SSPTRANS_CLKIN2CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKIN1CTL_U250_DYNCLKEN     BIT1    // 0/0/x/0 SSPTRANS_CLKIN1CTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKEPSEL_U250_DYNCLKEN      BIT0    // 0/0/x/0 SSPTRANS_CLKEPSEL_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX5F 0x5F // xHCI Option RX5F
    #define CND003_OPTCFGXHCI_SSPIPIF_U250_DYNCLKEN                BIT6    // 0/0/x/0 SSPIPIF_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKPTMCTL_U250_DYNCLKEN     BIT5    // 0/0/x/0 SSPTRANS_CLKPTMCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKSSROUTE_U250_DYNCLKEN    BIT4    // 0/0/x/0 SSPTRANS_CLKSSROUTE_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKITPCTL_U250_DYNCLKEN     BIT3    // 0/0/x/0 SSPTRANS_CLKITPCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKPINGCTL_U250_DYNCLKEN    BIT2    // 0/0/x/0 SSPTRANS_CLKPINGCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKCMDCTL_U250_DYNCLKEN     BIT1    // 0/0/x/0 SSPTRANS_CLKCMDCTL_U250_DYNCLKEN
    #define CND003_OPTCFGXHCI_SSPTRANS_CLKRXIF_U250_DYNCLKEN       BIT0    // 0/0/x/0 SSPTRANS_CLKRXIF_U250_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX60 0x60 // xHCI Option RX60
    #define CND003_OPTCFGXHCI_DPHRSPCHKEN      BIT7    // 1b/1b/x/x SSTRANS Enabel to Check Device Response Before DPP  Sending Out
    #define CND003_OPTCFGXHCI_BUFRLSALL_EN     BIT6    // 1b/1b/x/x SSTRANS Enable to Release All IN/OUT Buffer when IN/OUT TRANS Idle
    #define CND003_OPTCFGXHCI_INBUFREQ_RTY_EN  BIT5    // 1b/1b/x/x SSTRANS Enable to Request IN Buffer Before Doing Retry.
    #define CND003_OPTCFGXHCI_INRTY_MORE_EN    BIT4    // 0b/0/x/x SSTRANS Enable to Do 1 More Retry if No Service Opportunity at IN Tr...
    #define CND003_OPTCFGXHCI_NOPERACT_EN      BIT3    // 1b/1b/1b/x SSTRANS Enable to Bypass Async EOF Requirement if No Periodic Endp...
    #define CND003_OPTCFGXHCI_INCMPLFLSH_EN    BIT2    // 0/0/0/x SSTRANS Enable to Send Back IN Data after Entire DP Receiving Success...
    #define CND003_OPTCFGXHCI_INONEDP_EN       BIT1    // 0/0/0/x SSTRANS Enable to IN One DP for Each Request  (Always NumP=1)
    #define CND003_OPTCFGXHCI_OUTONEDP_EN      BIT0    // 0/0/0/x SSTRANS Enable to Out One DP Before Receiving ACK Response Enable Bit...
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX61 0x61 // xHCI Option RX61
    #define CND003_OPTCFGXHCI_ISOOVERUNDERRUN_TRPTR_EN BIT5            // 0/0/x/0 ISOOVERUNDERRUN_TRPTR_EN
    #define CND003_OPTCFGXHCI_SSBI_BFEMPTY_BLKHIT_EN   BIT4            // 1b/1b/x/x SSTRANS Enable to Check DPH HIT if No Buffer Valid
    #define CND003_OPTCFGXHCI_SSBI_TXIF_LINKUP_CHKEN   BIT3            // 1b/1b/x/x SSTRANS Enable to Check LINKUP Information at TXIF
    #define CND003_OPTCFGXHCI_INTDREQONE_EN            BIT2            // 0/0/x/x SSTRANS Enable to Request INPKTCTL One Time Only Each Service.
    #define CND003_OPTCFGXHCI_INONETD_EN               BIT1            // 0/0/0/x SSTRANS Enable to IN TDCTL Working One by One
    #define CND003_OPTCFGXHCI_OUTONETD_EN              BIT0            // 0/0/0/x SSTRANS Enable to Out TDCTL Working One by One
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX62 0x62 // xHCI Option RX62
    #define CND003_OPTCFGXHCI_INBUFVALIDTIME   0x3F            // 20h/20h/x/x IN Buffer Request Timeout Parameter (Unit: 8ns)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX63 0x63 // xHCI Option RX63
    #define CND003_OPTCFGXHCI_INBUFLOOP_PARM CND003_OPTCFGXHCI_XHCI_OPTION_RX63 // 3h/03h/x/x IN Buffer Request Loop Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX64 0x64 // xHCI Option RX64
    #define CND003_OPTCFGXHCI_SS_TMOUT_PARM    0x3FFF          // 109Ah/109Ah/x/x SS Transaction TimeOut Parameter (Unit: 8ns)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX66 0x66 // xHCI Option RX66
    #define CND003_OPTCFGXHCI_PEREOF1_PARM 0x1F                    // 19h/19h/x/x Periodic EOF1 Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX67 0x67 // xHCI Option RX67
    #define CND003_OPTCFGXHCI_PEREOF2_PARM 0x1F                    // 0Fh/0Fh/x/x Periodic EOF2 Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX68 0x68 // xHCI Option RX68
    #define CND003_OPTCFGXHCI_ASYEOF1_PARM 0x1F                    // 0Ah/0Ah/x/x Async EOF1 Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX69 0x69 // xHCI Option RX69
    #define CND003_OPTCFGXHCI_ASYEOF2_PARM 0x1F                    // 02h/02h/x/x Async EOF2 Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX6A 0x6A // xHCI Option RX6A
    #define CND003_OPTCFGXHCI_ENDOFSI_PARM 0x1F                    // 0Ah/0Ah/x/x Periodic End of Service Interval Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX6B 0x6B // XHCI Option RX6B
    #define CND003_OPTCFGXHCI_PERPREFETCH_PARM 0x1F                    // 08h/08h/x/x Periodic Endpoint Pre-Fetch Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX6C 0x6C // xHCI Option RX6C
    #define CND003_OPTCFGXHCI_NUMP0_ERDYTMOUT_PARM 0x7FF   // 7h/7h/x/x SS Transaction OUTPKTCTL NUMP0 ERDY TimeOut Parameter (Unit: 8ns)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX6E 0x6E // xHCI Option RX6E
    #define CND003_OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS5    BIT7                    // 0/0/x/x Enable port5 link state go to RXSETECT when in?DISABLE state
    #define CND003_OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS4    BIT6                    // 0/0/x/x Enable port4 link state go to RXSETECT when in?DISABLE state
    #define CND003_OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS3    BIT5                    // 0/0/x/x Enable port3 link state go to RXSETECT when in?DISABLE state
    #define CND003_OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS2    BIT4                    // 0/0/x/x Enable port2 link state go to RXSETECT when in?DISABLE state
    #define CND003_OPTCFGXHCI_R_LTSSMDIS_EXITEN_SS1    BIT3                    // 0/0/x/x Enable port1 link state go to RXSETECT when in?DISABLE state
    #define CND003_OPTCFGXHCI_WRDY_NUM                 (BIT0 + BIT1 + BIT2)    // 0/0/x/x WRDY_NUM
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX6F 0x6F // xHCI Option Rx6F
    #define CND003_OPTCFGXHCI_FLR_WRST_EN  BIT4                    // 1b/x/x/x FLR Warm Reset Enable
    #define CND003_OPTCFGXHCI_FLR_HCRST_EN BIT3                    // 1b/x/x/x FLR HCRST Enable
    #define CND003_OPTCFGXHCI_FLR_CAP_EN   BIT2                    // 1b/x/x/x FLR Capbility Enable
    #define CND003_OPTCFGXHCI_BYPASS_FLR   BIT1                    // 0/0/x/x Bypass FLR for SSIP
    #define CND003_OPTCFGXHCI_FLR_EN       BIT0                    // 1b/1b/x/x FLR Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX70 0x70 // xHCI Option RX70
    #define CND003_OPTCFGXHCI_SSP_ISOINHC4_EN  BIT2        // 0/0/x/x xHCI SSPBI ISO C4 Inhibit Enable
    #define CND003_OPTCFGXHCI_HS_ISOINHC4_EN   BIT1        // 0/0/x/x xHCI HSBI ISO C4 Inhibit Enable
    #define CND003_OPTCFGXHCI_SS_ISOINHC4_EN   BIT0        // 0/0/x/x xHCI SSBI ISO C4 Inhibit Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX74 0x74 // xHCI Option RX74
    #define CND003_OPTCFGXHCI_S_SSPMODE_SS2    BIT6            // 0/0/x/x Indicate Port2 Is 10G Mode
    #define CND003_OPTCFGXHCI_SSP_S_RCVOTG_SS2 BIT5            // 0/0/x/x Indicate Port2 Receive Port Capability LMP with OTG Bit Is 1
    #define CND003_OPTCFGXHCI_S_SSPMODE_SS1    BIT2            // 0/0/x/x Indicate Port1 is 10G Mode
    #define CND003_OPTCFGXHCI_SSP_S_RCVOTG_SS1 BIT1            // 0/0/x/x Indicate Port1 Receive Port Capability LMP with OTG Bit Is 1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX75 0x75 // xHCI Option RX75
    #define CND003_OPTCFGXHCI_S_SSPMODE_SS4    BIT6            // 0/0/x/x Indicate Port4 Is 10G Mode
    #define CND003_OPTCFGXHCI_SSP_S_RCVOTG_SS4 BIT5            // 0/0/x/x Indicate Port4 Receive Port Capability LMP with OTG Bit Is 1
    #define CND003_OPTCFGXHCI_S_SSPMODE_SS3    BIT2            // 0/0/x/x Indicate Port3 Is 10G Mode
    #define CND003_OPTCFGXHCI_SSP_S_RCVOTG_SS3 BIT1            // 0/0/x/x Indicate Port3 Receive Port Capability LMP with OTG Bit Is 1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX76 0x76 // xHCI Option RX76
    #define CND003_OPTCFGXHCI_S_SSPMODE_SS5    BIT2    // 0/0/x/x Indicate Port5 Is 10G Mode
    #define CND003_OPTCFGXHCI_SSP_S_RCVOTG_SS5 BIT1    // 0/0/x/x Indicate Port5 Receive Port Capability LMP with OTG Bit Is 1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX77 0x77 // xHCI Option RX77
    #define CND003_OPTCFGXHCI_R_U1ENABLE_SS5   BIT4                    // 0/0/x/x Enable Port5 Support U1 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U1ENABLE_SS4   BIT3                    // 0/0/x/x Enable Port4 Support U1 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U1ENABLE_SS3   BIT2                    // 0/0/x/x Enable Port3 Support U1 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U1ENABLE_SS2   BIT1                    // 0/0/x/x Enable Port2 Support U1 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U1ENABLE_SS1   BIT0                    // 0/0/x/x Enable Port1 Support U1 When Port Is UFP
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX78 0x78 // xHCI Option RX78
    #define CND003_OPTCFGXHCI_R_U2ENABLE_SS5   BIT4                    // 0/0/x/x Enable Port5 Support U2 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U2ENABLE_SS4   BIT3                    // 0/0/x/x Enable Port4 Support U2 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U2ENABLE_SS3   BIT2                    // 0/0/x/x Enable Port3 Support U2 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U2ENABLE_SS2   BIT1                    // 0/0/x/x Enable Port2 Support U2 When Port Is UFP
    #define CND003_OPTCFGXHCI_R_U2ENABLE_SS1   BIT0                    // 0/0/x/x Enable Port1 Support U2 When Port Is UFP
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX79 0x79 // xHCI Option RX79
    #define CND003_OPTCFGXHCI_USB2P1_UPSIE_CLK_60M_DYNCLKEN    BIT7    // 0/0/x/x USB2P1_UPSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_UPSIE_CLK_120M_DYNCLKEN   BIT6    // 0/0/x/0 USB2P1_UPSIE_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_TT_CLK_60M_DYNCLKEN       BIT5    // 0/0/x/0 USB2P1_TT_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_DN_CLK_120M_DYNCLKEN      BIT4    // 0/0/x/0 USB2P1_DN_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_LPM_FS_CLK_120M_DYNCLKEN  BIT3    // 0/0/x/0 USB2P1_LPM_FS_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_LPM_FS_CLK_60M_DYNCLKEN   BIT2    // 0/0/x/0 USB2P1_LPM_FS_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_DNSIE_CLK_60M_DYNCLKEN    BIT1    // 0/0/x/0 USB2P1_DNSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_DNSIE_CLK_120M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P1_DNSIE_CLK_120M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX7A 0x7A // xHCI Option RX7A
    #define CND003_OPTCFGXHCI_USB2P2_UPSIE_CLK_60M_DYNCLKEN    BIT7    // 0/0/x/x USB2P2_UPSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_UPSIE_CLK_120M_DYNCLKEN   BIT6    // 0/0/x/0 USB2P2_UPSIE_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_TT_CLK_60M_DYNCLKEN       BIT5    // 0/0/x/0 USB2P2_TT_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_DN_CLK_120M_DYNCLKEN      BIT4    // 0/0/x/0 USB2P2_DN_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_LPM_FS_CLK_120M_DYNCLKEN  BIT3    // 0/0/x/0 USB2P2_LPM_FS_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_LPM_FS_CLK_60M_DYNCLKEN   BIT2    // 0/0/x/0 USB2P2_LPM_FS_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_DNSIE_CLK_60M_DYNCLKEN    BIT1    // 0/0/x/0 USB2P2_DNSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_DNSIE_CLK_120M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P2_DNSIE_CLK_120M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX7B 0x7B // xHCI Option RX7B
    #define CND003_OPTCFGXHCI_USB2P3_UPSIE_CLK_60M_DYNCLKEN    BIT7    // 0/0/x/x USB2P3_UPSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_UPSIE_CLK_120M_DYNCLKEN   BIT6    // 0/0/x/0 USB2P3_UPSIE_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_TT_CLK_60M_DYNCLKEN       BIT5    // 0/0/x/0 USB2P3_TT_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_DN_CLK_120M_DYNCLKEN      BIT4    // 0/0/x/0 USB2P3_DN_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_LPM_FS_CLK_120M_DYNCLKEN  BIT3    // 0/0/x/0 USB2P3_LPM_FS_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_LPM_FS_CLK_60M_DYNCLKEN   BIT2    // 0/0/x/0 USB2P3_LPM_FS_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_DNSIE_CLK_60M_DYNCLKEN    BIT1    // 0/0/x/0 USB2P3_DNSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_DNSIE_CLK_120M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P3_DNSIE_CLK_120M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX7C 0x7C // xHCI Option RX7C
    #define CND003_OPTCFGXHCI_USB2P4_UPSIE_CLK_60M_DYNCLKEN    BIT7    // 0/0/x/x USB2P4_UPSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_UPSIE_CLK_120M_DYNCLKEN   BIT6    // 0/0/x/0 USB2P4_UPSIE_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_TT_CLK_60M_DYNCLKEN       BIT5    // 0/0/x/0 USB2P4_TT_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_DN_CLK_120M_DYNCLKEN      BIT4    // 0/0/x/0 USB2P4_DN_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_LPM_FS_CLK_120M_DYNCLKEN  BIT3    // 0/0/x/0 USB2P4_LPM_FS_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_LPM_FS_CLK_60M_DYNCLKEN   BIT2    // 0/0/x/0 USB2P4_LPM_FS_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_DNSIE_CLK_60M_DYNCLKEN    BIT1    // 0/0/x/0 USB2P4_DNSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_DNSIE_CLK_120M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P4_DNSIE_CLK_120M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX7D 0x7D // xHCI Option RX7D
    #define CND003_OPTCFGXHCI_USB2P5_UPSIE_CLK_60M_DYNCLKEN    BIT7    // 0/0/x/x USB2P5_UPSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_UPSIE_CLK_120M_DYNCLKEN   BIT6    // 0/0/x/0 USB2P5_UPSIE_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_TT_CLK_60M_DYNCLKEN       BIT5    // 0/0/x/0 USB2P5_TT_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_DN_CLK_120M_DYNCLKEN      BIT4    // 0/0/x/0 USB2P5_DN_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_LPM_FS_CLK_120M_DYNCLKEN  BIT3    // 0/0/x/0 USB2P5_LPM_FS_CLK_120M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_LPM_FS_CLK_60M_DYNCLKEN   BIT2    // 0/0/x/0 USB2P5_LPM_FS_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_DNSIE_CLK_60M_DYNCLKEN    BIT1    // 0/0/x/0 USB2P5_DNSIE_CLK_60M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_DNSIE_CLK_120M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P5_DNSIE_CLK_120M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX7E 0x7E // xHCI Option RX7E
    #define CND003_OPTCFGXHCI_USB2P4_DNSIE_CLK_1M5_DYNCLKEN    BIT7    // 0/0/x/x USB2P4_DNSIE_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_DNSIE_CLK_12M_DYNCLKEN    BIT6    // 0/0/x/0 USB2P4_DNSIE_CLK_12M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_DNSIE_CLK_1M5_DYNCLKEN    BIT5    // 0/0/x/0 USB2P3_DNSIE_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_DNSIE_CLK_12M_DYNCLKEN    BIT4    // 0/0/x/0 USB2P3_DNSIE_CLK_12M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_DNSIE_CLK_1M5_DYNCLKEN    BIT3    // 0/0/x/0 USB2P2_DNSIE_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_DNSIE_CLK_12M_DYNCLKEN    BIT2    // 0/0/x/0 USB2P2_DNSIE_CLK_12M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_DNSIE_CLK_1M5_DYNCLKEN    BIT1    // 0/0/x/0 USB2P1_DNSIE_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_DNSIE_CLK_12M_DYNCLKEN    BIT0    // 0/0/x/0 USB2P1_DNSIE_CLK_12M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX7F 0x7F // xHCI Option RX7F
    #define CND003_OPTCFGXHCI_USB2P5_DNSIE_RCLK_DYNCLKEN       BIT6    // 0/0/x/x USB2P5_DNSIE_RCLK_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_DNSIE_RCLK_DYNCLKEN       BIT5    // 0/0/x/x USB2P4_DNSIE_RCLK_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_DNSIE_RCLK_DYNCLKEN       BIT4    // 0/0/x/x USB2P3_DNSIE_RCLK_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_DNSIE_RCLK_DYNCLKEN       BIT3    // 0/0/x/x USB2P2_DNSIE_RCLK_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_DNSIE_RCLK_DYNCLKEN       BIT2    // 0/0/x/x USB2P1_DNSIE_RCLK_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_DNSIE_CLK_1M5_DYNCLKEN    BIT1    // 0/0/x/0 USB2P5_DNSIE_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_DNSIE_CLK_12M_DYNCLKEN    BIT0    // 0/0/x/0 USB2P5_DNSIE_CLK_12M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX80 0x80 // xHCI Option RX80
    #define CND003_OPTCFGXHCI_PCAPDIR_SEL_SS2  BIT5            // 1b/1b/x/x PCAPDIR_SEL_SS2
    #define CND003_OPTCFGXHCI_PCAPDIR_SEL_SS1  BIT4            // 1b/1b/x/x PCAPDIR_SEL_SS1
    #define CND003_OPTCFGXHCI_IPTYPE_SEL_SS2   BIT1            // 1b/1b/x/x IPTYPE_SEL_SS2
    #define CND003_OPTCFGXHCI_IPTYPE_SEL_SS1   BIT0            // 1b/1b/x/x IPTYPE_SEL_SS1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX81 0x81 // xHCI Option RX81
    #define CND003_OPTCFGXHCI_PCAPDIR_SEL_SS4  BIT5            // 1b/1b/x/x PCAPDIR_SEL_SS4
    #define CND003_OPTCFGXHCI_PCAPDIR_SEL_SS3  BIT4            // 1b/1b/x/x PCAPDIR_SEL_SS3
    #define CND003_OPTCFGXHCI_IPTYPE_SEL_SS4   BIT1            // 1b/1b/x/x IPTYPE_SEL_SS4
    #define CND003_OPTCFGXHCI_IPTYPE_SEL_SS3   BIT0            // 1b/1b/x/x IPTYPE_SEL_SS3
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX82 0x82 // XHCI Option RX82
    #define CND003_OPTCFGXHCI_PCAPDIR_SEL_SS5  BIT1    // 1b/1b/x/x PCAPDIR_SEL_SS5
    #define CND003_OPTCFGXHCI_IPTYPE_SEL_SS5   BIT0    // 1b/1b/x/x IPTYPE_SEL_SS5
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX84 0x84 // xHCI Option RX84
    #define CND003_OPTCFGXHCI_TYPEC_EN BIT1    // 1b/1b/x/x TYPEC Enable
    #define CND003_OPTCFGXHCI_U3DBC_EN BIT0    // 1b/1b/x/x U3DBC Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX85 0x85 // xHCI Option RX85
    #define CND003_OPTCFGXHCI_SSP5_WAKEUPEN    BIT4                    // 1b/1b/x/x USB3.0 Port 5 Wakeup Enable
    #define CND003_OPTCFGXHCI_SSP4_WAKEUPEN    BIT3                    // 1b/1b/x/x USB3.0 Port 4 Wakeup Enable
    #define CND003_OPTCFGXHCI_SSP3_WAKEUPEN    BIT2                    // 1b/1b/x/x USB3.0 Port 3 Wakeup Enable
    #define CND003_OPTCFGXHCI_SSP2_WAKEUPEN    BIT1                    // 1b/1b/x/x USB3.0 Port 2 Wakeup Enable
    #define CND003_OPTCFGXHCI_SSP1_WAKEUPEN    BIT0                    // 1b/1b/x/x USB3.0 Port 1 Wakeup Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX87 0x87 // xHCI Option RX87
    #define CND003_OPTCFGXHCI_MCUHOC_EN    BIT2    // 0/0/x/x Enable MCU FW Handle Over-current Event 
    #define CND003_OPTCFGXHCI_WOE_FW       BIT1    // 0/0/x/x Wake on Over-current Enable Set by MCU FW
    #define CND003_OPTCFGXHCI_WCE_FW       BIT0    // 0/0/x/x Wake on Connect Enable Set by MCU FW 
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX88 0x88 // xHCI Option RX88
    #define CND003_OPTCFGXHCI_M31PHYPD_MASK        BIT6    // 0/x/0/0 M31PHYPD_MASK
    #define CND003_OPTCFGXHCI_M30PHYPD_MASK        BIT5    // 0/x/0/0 M30PHYPD_MASK
    #define CND003_OPTCFGXHCI_M20PHYPD_MASK        BIT4    // 0/x/0/0 M20PHYPD_MASK
    #define CND003_OPTCFGXHCI_U2PHY_PDSUSMOD_REG   BIT2    // 0/0/x/x U2PHY_PDSUSMOD_REG
    #define CND003_OPTCFGXHCI_U2PHY_PDAPLL_REG     BIT1    // 0/0/x/x U2PHY_PDAPLL_REG
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX89 0x89 // xHCI Option RX89
    #define CND003_OPTCFGXHCI_R_SSPMODEN_SS2   BIT4                    // 0/0/x/x SSP Port2 10G Mode Enable
    #define CND003_OPTCFGXHCI_R_SSPMODEN_SS1   BIT0                    // 0/0/x/x SSP Port1 10G Mode Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX8A 0x8A // xHCI Option RX8A
    #define CND003_OPTCFGXHCI_R_SSPMODEN_SS4   BIT4                    // 1b/1b/x/x SSP Port4 10G Mode Enable
    #define CND003_OPTCFGXHCI_R_SSPMODEN_SS3   BIT0                    // 0/0/x/x SSP Port3 10G Mode Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX8B 0x8B // xHCI Option RX8B
    #define CND003_OPTCFGXHCI_R_SSPMODEN_SS5   BIT0    // 1b/1b/x/x SSP Port5 10G Mode Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX8C 0x8C // xHCI Option RX8C
    #define CND003_OPTCFGXHCI_R_SS_PLC_TST_OPT         BIT31       // 1b/1b/x/x R_SS_PLC_TST_OPT
    #define CND003_OPTCFGXHCI_R_HCRST_WRST_EN          BIT30       // 1b/1b/x/x R_HCRST_WRST_EN
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RX8C_30_20   0x3FF00000  // 3CFh/x/x/x CND003_OPTCFG_XHCI_RX8C_30_20
    #define CND003_OPTCFGXHCI_REG_U2S0_WAKUP_SEL       BIT19       // 1b/1b/x/x REG_U2S0_WAKUP_SEL
    #define CND003_OPTCFGXHCI_WAKEUPSEL_EN             BIT18       // 1b/1b/x/x WAKEUPSEL_EN
    #define CND003_OPTCFGXHCI_CRESUMEPATCH             BIT17       // 1b/1b/x/x 0:When receiving remote wakeup, reflect resume K truly.
    #define CND003_OPTCFGXHCI_RESUMEBLK                BIT16       // 1b/1b/x/x 0: Do not block resume signal from internal hub.
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RX8C_15_5    0xFFE0      // 7h/x/x/x CND003_OPTCFG_XHCI_RX8C_15_5
    #define CND003_OPTCFGXHCI_R_USB2_PLS_RSM           BIT4        // 1b/1b/x/x R_USB2_PLS_RSM
    #define CND003_OPTCFGXHCI_R_WRST_CPL_PR_EN         BIT3        // 1b/1b/x/x R_WRST_CPL_PR_EN
    #define CND003_OPTCFGXHCI_R_USB2_PR_CPL_SEL        BIT2        // 0/0b/x/x R_USB2_PR_CPL_SEL
    #define CND003_OPTCFGXHCI_R_USB2_SYN_RFSEL         BIT1        // 1b/1b/x/x R_USB2_SYN_RFSEL
    #define CND003_OPTCFGXHCI_R_CLRUX_EN               BIT0        // 0/0b/x/x R_CLRUX_EN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX90 0x90 // xHCI Option RX90
    #define CND003_OPTCFGXHCI_SS1_PORT_MODSTS  (BIT4 + BIT5 + BIT6)    // 001b/001b/x/x SSPort Mode Select Status
    #define CND003_OPTCFGXHCI_SS1_PORT_MODSEL  (BIT0 + BIT1 + BIT2)    // 101b/101b/x/x SSPort Mode Select
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX94 0x94 // xHCI Option RX94
    #define CND003_OPTCFGXHCI_SS2_PORT_MODSTS  (BIT4 + BIT5 + BIT6)    // 001b/001b/x/x SSPort Mode Select Status
    #define CND003_OPTCFGXHCI_SS2_PORT_MODSEL  (BIT0 + BIT1 + BIT2)    // 101b/101b/x/x SSPort Mode Select
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX98 0x98 // xHCI Option RX98
    #define CND003_OPTCFGXHCI_SS3_PORT_MODSTS  (BIT4 + BIT5 + BIT6)    // 001b/001b/x/x SSPort Mode Select Status
    #define CND003_OPTCFGXHCI_SS3_PORT_MODSEL  (BIT0 + BIT1 + BIT2)    // 101b/101b/x/x SSPort Mode Select
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX9C 0x9C // xHCI Option RX9C
    #define CND003_OPTCFGXHCI_SS5_PORT_MODSTS  (BIT12 + BIT13 + BIT14) // 001b/001b/x/x SSPort Mode Select Status
    #define CND003_OPTCFGXHCI_SS5_PORT_MODSEL  (BIT8 + BIT9 + BIT10)   // 101b/101b/x/x SSPort Mode Select
    #define CND003_OPTCFGXHCI_SS4_PORT_MODSTS  (BIT4 + BIT5 + BIT6)    // 001b/001b/x/x SSPort Mode Select Status
    #define CND003_OPTCFGXHCI_SS4_PORT_MODSEL  (BIT0 + BIT1 + BIT2)    // 101b/101b/x/x SSPort Mode Select
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXA0 0xA0 // xHCI Option RXA0
    #define CND003_OPTCFGXHCI_MCUFLTDB_EN  BIT1    // 0/0/x/x MCU Set Filter Doorbell Enable
    #define CND003_OPTCFGXHCI_HWFLTDB_EN   BIT0    // 1b/1b/x/x HW Filter Duplicate Doorbell Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXA4 0xA4 // xHCI Option RXA4
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT1   0xFF000000  // 0/0/x/x MCU Filter Doorbell Slot 1
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI1    0xFF0000    // 0/0/x/x MCU Filter Doorbell DCI 1
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT0   0xFF00      // 0/0/x/x MCU Filter Doorbell Slot 0
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI0    0xFF        // 0/0/x/x MCU Filter Doorbell DCI 0
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXA8 0xA8 // xHCI Option RXA8
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT3   0xFF000000  // 0/0/x/x MCU Filter Doorbell Slot 3
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI3    0xFF0000    // 0/0/x/x MCU Filter Doorbell DCI 3
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT2   0xFF00      // 0/0/x/x MCU Filter Doorbell Slot 2
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI2    0xFF        // 0/0/x/x MCU Filter Doorbell DCI 2
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXAC 0xAC // xHCI Option RXAC
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT5   0xFF000000  // 0/0/x/x MCU Filter Doorbell Slot 5
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI5    0xFF0000    // 0/0/x/x MCU Filter Doorbell DCI 5
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT4   0xFF00      // 0/0/x/x MCU Filter Doorbell Slot 4
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI4    0xFF        // 0/0/x/x MCU Filter Doorbell DCI 4
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXB0 0xB0 // xHCI Option RXB0
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT7   0xFF000000  // 0/0/x/x MCU Filter Doorbell Slot 7
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI7    0xFF0000    // 0/0/x/x MCU Filter Doorbell DCI 7
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT6   0xFF00      // 0/0/x/x MCU Filter Doorbell Slot 6
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI6    0xFF        // 0/0/x/x MCU Filter Doorbell DCI 6
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXB4 0xB4 // xHCI Option RXB4
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT9   0xFF000000  // 0/0/x/x MCU Filter Doorbell Slot 9
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI9    0xFF0000    // 0/0/x/x MCU Filter Doorbell DCI 9
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT8   0xFF00      // 0/0/x/x MCU Filter Doorbell Slot 8
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI8    0xFF        // 0/0/x/x MCU Filter Doorbell DCI 8
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXB8 0xB8 // xHCI Option RXB8
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT11  0xFF000000  // 0/0/x/x MCU Filter Doorbell Slot 11
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI11   0xFF0000    // 0/0/x/x MCU Filter Doorbell DCI 11
    #define CND003_OPTCFGXHCI_MCUFLTDB_SLOT10  0xFF00      // 0/0/x/x MCU Filter Doorbell Slot 10
    #define CND003_OPTCFGXHCI_MCUFLTDB_DCI10   0xFF        // 0/0/x/x MCU Filter Doorbell DCI 10
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXBC 0xBC // xHCI Option RxBC
    #define CND003_OPTCFGXHCI_DSRD_FLR CND003_OPTCFGXHCI_XHCI_OPTION_RXBC // FFFFFFFFh/FFFFFFFFh/x/x The Data Return to C2P Read Cycle When Doing FLR
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXD0 0xD0 // xHCI Option RXD0
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RXD0_31_28       0xF0000000              // Eh/Eh/x/x CND003_OPTCFG_XHCI_RXD0_31_28
    #define CND003_OPTCFGXHCI_LOWPWR_DIS_PKTTIMER_EN       BIT27                   // 1b/1b/x/x LOWPWR_DIS_PKTTIMER_EN
    #define CND003_OPTCFGXHCI_SAMSUNG_PATCH                BIT26                   // 1b/1b/x/x SAMSUNG_PATCH
    #define CND003_OPTCFGXHCI_ISOEDLTA_PATCH_EN            BIT25                   // 1b/1b/x/x ISOEDLTA_PATCH_EN
    #define CND003_OPTCFGXHCI_BABBLE_DETNEW_EN             BIT24                   // 1b/1b/x/x BABBLE_DETNEW_EN
    #define CND003_OPTCFGXHCI_R_FWDISLINK_EN               BIT23                   // 1b/1b/x/x Enable F/W to Control Link Enter Disabled State
    #define CND003_OPTCFGXHCI_R_FAKER_PED1TO0              BIT22                   // 1b/1b/x/x R_FAKER_PED1TO0
    #define CND003_OPTCFGXHCI_R_FAKER_DCE1TO0              BIT21                   // 1b/1b/x/x R_FAKER_DCE1TO0
    #define CND003_OPTCFGXHCI_R_DCE0_U0_FORCE_CCSPED1      BIT20                   // 1b/1b/x/x R_DCE0_U0_FORCE_CCSPED1
    #define CND003_OPTCFGXHCI_R_DEFER_STS_DET_EN           BIT19                   // 1b/1b/x/x Defer Status TP Detection Enable
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RXD0_18_16       (BIT16 + BIT17 + BIT18) // 110b/110b/x/x CND003_OPTCFG_XHCI_RXD0_18_16
    #define CND003_OPTCFGXHCI_ISOEP_TMOUT_PARM             0xFFE0                  // 20h/20h/x/x ISOOUT EP Check Response time-out timer
    #define CND003_OPTCFGXHCI_ISOOUT_DEFER_EN              BIT4                    // 0/0/x/x Enable ISOOUT EP Check Deferred DP Response
    #define CND003_OPTCFGXHCI_R_PED1TO0_CCSKEEP_EN         BIT3                    // 0/0/x/x When PED Is Written to 0, Link Enter Disabled State, Keep Current Con...
    #define CND003_OPTCFGXHCI_R_DBC_DCE0_DISLINK           BIT2                    // 0/0/x/x Optioanl Register for DBC
    #define CND003_OPTCFGXHCI_R_DBC_PED0_DISLINK           BIT1                    // 0/0/x/x Optioanl Register for DBC
    #define CND003_OPTCFGXHCI_PTDQUEUE_NONEMPTY_STOP_EN    BIT0                    // 0/0/x/x PTDQUEUE_NONEMPTY_STOP_EN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXD4 0xD4 // xHCI Option RXD4
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RXD4_31_27       0xF0000000      // 1111b/x/x/x CND003_OPTCFG_XHCI_RXD4_31_27
    #define CND003_OPTCFGXHCI_R_CTLSETADDR_EN              BIT27           // 1b/1b/x/x R_CTLSETADDR_EN
    #define CND003_OPTCFGXHCI_ERBEIPATCH                   BIT26           // 1b/1b/x/x ERBEIPATCH
    #define CND003_OPTCFGXHCI_CTLEP_RXDP_DATAOUT_PATCH     BIT25           // 1b/1b/x/x Fix for xHCI_DBC Control out (length>0) + Control out Sequence
    #define CND003_OPTCFGXHCI_R_APISIDLE_LMP               BIT24           // 1b/1b/x/x 1: Deassert SSIP APISIDLE signal when sending U2Inactiver LMP;
    #define CND003_OPTCFGXHCI_R_INTSTS_HALT                BIT23           // 1b/1b/x/x Enable to Stop 1 Interrupt Enpoint SO when MCU  Handler Periodic Ha...
    #define CND003_OPTCFGXHCI_R_INTSTS_EMPTY               BIT22           // 1b/1b/x/x Enable to Stop 1 Interrupt Enpoint SO when MCU  Handler Periodic TR...
    #define CND003_OPTCFGXHCI_R_INTSTS_TRBERR              BIT21           // 1b/1b/x/x Enable to Stop 1 Interrupt Enpoint SO when MCU  Handler Periodic TR...
    #define CND003_OPTCFGXHCI_R_ASYTOPER_EN                BIT20           // 1b/1b/x/x Enable to Restart Periodic Engine when Async Engine Stop at uFrame ...
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RXD4_19_19       BIT19           // 1b/1b/x/x CND003_OPTCFG_XHCI_RXD4_19_19
    #define CND003_OPTCFGXHCI_ERFULLBEI_EN                 BIT18           // 1b/1b/x/x ERFULLBEI_EN
    #define CND003_OPTCFGXHCI_R_64BITR_D3_PATCH            BIT17           // 1b/1b/x/x Patch 64-bit Read in D3 Mode
    #define CND003_OPTCFGXHCI_R_64BITW_PMREG_PATCH         BIT16           // 1b/1b/x/x Patch 64-bit Write to Rx80 (PMU Related Register) When Not in D3 Mode
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RXD4_15_8        0xFF00          // 1h/1h/x/x CND003_OPTCFG_XHCI_RXD4_15_8
    #define CND003_OPTCFGXHCI_R_1PKTERDY_EN                BIT7            // 0/0/x/x R_1PKTERDY_EN
    #define CND003_OPTCFGXHCI_CND003_OPTCFG_XHCI_RXD4_6_6         BIT6            // 0/0/x/x CND003_OPTCFG_XHCI_RXD4_6_6
    #define CND003_OPTCFGXHCI_R_DSREQ_SEL                  BIT5            // 0/0/x/x R_DSREQ_SEL
    #define CND003_OPTCFGXHCI_R_DNBLK_SEL                  (BIT3 + BIT4)   // 0/0/x/x R_DNBLK_SEL
    #define CND003_OPTCFGXHCI_R_ISOTDPC_CORNER_EN          BIT2            // 0/0/x/x R_ISOTDPC_CORNER_EN
    #define CND003_OPTCFGXHCI_R_TRANSERR_NEW_EN            BIT1            // 0/0/x/x R_TRANSERR_NEW_EN
    #define CND003_OPTCFGXHCI_FIX_OUT_STREAMSTSERROR_EN    BIT0            // 0/0/x/x FIX_OUT_STREAMSTSERROR_EN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXD8 0xD8 // xHCI Option RXD8
    #define CND003_OPTCFGXHCI_PATCHBITS4 CND003_OPTCFGXHCI_XHCI_OPTION_RXD8 // FFFF0000h/x/x/x xHCI Patch Optional Bits 4 (Suspend Power Domain)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXDC 0xDC // xHCI Option RXDC
    #define CND003_OPTCFGXHCI_PATCHBITS5 CND003_OPTCFGXHCI_XHCI_OPTION_RXDC // FFFF0000h/x/x/x xHCI Patch Optional Bits 5 (Suspend Power Domain)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXE0 0xE0 // xHCI Option RXE0
    #define CND003_OPTCFGXHCI_SWFWMSG0 CND003_OPTCFGXHCI_XHCI_OPTION_RXE0 // 0/0/x/x SW Debug Message to MCU FW DW0
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXE4 0xE4 // xHCI Option RXE4
    #define CND003_OPTCFGXHCI_SWFWMSG1 CND003_OPTCFGXHCI_XHCI_OPTION_RXE4 // 0/0/x/x SW Debug Message to MCU FW DW1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXE8 0xE8 // xHCI Option RXE8
    #define CND003_OPTCFGXHCI_SWFWMSG2 CND003_OPTCFGXHCI_XHCI_OPTION_RXE8 // 0/0/x/x SW Debug Message to MCU FW DW2
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXEC 0xEC // xHCI Option RXEC
    #define CND003_OPTCFGXHCI_SWFWMSG3 CND003_OPTCFGXHCI_XHCI_OPTION_RXEC // 0/0/x/x SW Debug Message to MCU FW DW3
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXF0 0xF0 // XHCI Option RXF0
    #define CND003_OPTCFGXHCI_PATCHBITS0 CND003_OPTCFGXHCI_XHCI_OPTION_RXF0 // FFFF0DA4h/FFFF0DA4h/x/x xHCI Patch Optional Bits 0
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXF4 0xF4 // xHCI Option RXF4
    #define CND003_OPTCFGXHCI_PATCHBITS1 CND003_OPTCFGXHCI_XHCI_OPTION_RXF4 // FE1F0000h/FE1F0000h/x/x xHCI Patch Optional Bits 1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXF8 0xF8 // xHCI Option RXF8
    #define CND003_OPTCFGXHCI_PATCHBITS2 CND003_OPTCFGXHCI_XHCI_OPTION_RXF8 // FFFF0003h/FFFF0003h/x/x xHCI Patch Optional Bits 2 (Suspend Power Domain)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RXFC 0xFC // xHCI Option RXFC
    #define CND003_OPTCFGXHCI_PATCHBITS3 CND003_OPTCFGXHCI_XHCI_OPTION_RXFC // FFFF0000h/x/x/x xHCI Patch Optional Bits 3 (Suspend Power Domain)
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX100 0x100 // xHCI Option RX100
    #define CND003_OPTCFGXHCI_HOSTTPFTIME  0xFFFFFF    // 1CFDE0h/1CFDE0h/x/x The Host TPF Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX104 0x104 // xHCI Option RX104
    #define CND003_OPTCFGXHCI_ISO_BURST_EN     BIT7    // 0/0/x/x ISO_BURST_EN
    #define CND003_OPTCFGXHCI_SSP_MULTIN_EN    BIT6    // 0/0/0/0 SuperSpeedPlus Simultaneous IN Transactions Enable
    #define CND003_OPTCFGXHCI_SSP_PIPEISOIN_EN BIT5    // 0/0/0/0 SuperSpeedPlus Simultaneous IN Transactions Enable
    #define CND003_OPTCFGXHCI_WPA_EN_OUT       BIT4    // 0/0/0/0 Will Ping Again Filed Setting for ISO OUT
    #define CND003_OPTCFGXHCI_SSI_EN_OUT       BIT3    // 0/0/0/0 Support Smart Isochronous Filed Setting for ISO OUT
    #define CND003_OPTCFGXHCI_WPA_EN_IN        BIT2    // 0/0/0/0 Will Ping Again Filed Setting for ISO IN
    #define CND003_OPTCFGXHCI_SSI_EN_IN        BIT1    // 0/0/0/0 Support Smart Isochronous Filed Setting for ISO IN
    #define CND003_OPTCFGXHCI_SSP_PTM_EN       BIT0    // 0/0/0/0 SuperSpeedPlus Precision Time Measurement Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX105 0x105 // xHCI Option RX105
    #define CND003_OPTCFGXHCI_OBFF_OUTNOEPTCNT 0xF0    // 0/0/0/0 Threshold Register
    #define CND003_OPTCFGXHCI_OBFF_INEPTCNT    0xF     // 0/0/0/0 Threshold Register
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX106 0x106 // xHCI Option RX106
    #define CND003_OPTCFGXHCI_BLKEP_HSNAKSTP_EN    BIT7                    // 0/0/x/x BLKEP_HSNAKSTP_EN
    #define CND003_OPTCFGXHCI_BLKEP_HSNAKCNT       (BIT4 + BIT5 + BIT6)    // 111b/111b/x/x BLKEP_HSNAKCNT
    #define CND003_OPTCFGXHCI_DBRING_HW_EN         BIT3                    // 0/0/x/x Enable DB Ring HW Path (PCIS-->xxBI to Trigger TRB Fetch) for Good Pe...
    #define CND003_OPTCFGXHCI_ISOCFC_EN            BIT2                    // 0/0/x/x (xHCI Errata 130424) Enable xHCI Isoch CFC Function
    #define CND003_OPTCFGXHCI_BYPASS_D3HOT2D0RST   BIT1                    // 1b/1b/x/x Bypass D3Hot to D0 Reset
    #define CND003_OPTCFGXHCI_SLOTID_DCI_CHK       BIT0                    // 1b/1b/0/0 SLOT ID/DCI Check Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX107 0x107 // xHCI Option RX107
    #define CND003_OPTCFGXHCI_MCU_EPXC_SEL BIT2    // 1b/1b/x/x EPXC Access Path Select
    #define CND003_OPTCFGXHCI_FW_USB_IDLE  BIT1    // 0/0/x/x USB Host Controller is Idle, Set by FW
    #define CND003_OPTCFGXHCI_MCU_ACTIVE   BIT0    // 0/0/x/x MCU Active
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX108 0x108 // xHCI Option RX108
    #define CND003_OPTCFGXHCI_UPREQADDR_HI CND003_OPTCFGXHCI_XHCI_OPTION_RX108 // 0/0/x/x Upstream R/W Request Cycle High Address ([63:48])
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX10A 0x10A // xHCI Option RX10A
    #define CND003_OPTCFGXHCI_OBFF_EN                  BIT6    // 0/0/x/x OBFF Enable
    #define CND003_OPTCFGXHCI_DMAR_RTYEN               BIT5    // 0/0/x/x DMAR_RTYEN
    #define CND003_OPTCFGXHCI_RETRY_HSE_EN             BIT4    // 0/0/x/x RETRY_HSE_EN
    #define CND003_OPTCFGXHCI_LSTSPEVENT_EN            BIT3    // 0/0/x/x LSTSPEVENT_EN
    #define CND003_OPTCFGXHCI_R_LOADNUMP_EN            BIT2    // 0/0/x/x R_LOADNUMP_EN
    #define CND003_OPTCFGXHCI_ISOMISSSERVICE_TRPTR_EN  BIT1    // 0/0/x/x ISOMISSSERVICE_TRPTR_EN
    #define CND003_OPTCFGXHCI_ISOBABBLE_EVENT_SEL      BIT0    // 0/0/0/0 (xHCI Errate 131220) Isoch Endpoint Babble Detect Event Select
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX10B 0x10B // xHCI Option RX10B
    #define CND003_OPTCFGXHCI_MCU_LTSSTBEN_SS5 BIT4                    // 0/0/x/x MCU_LTSSTBEN_SS5
    #define CND003_OPTCFGXHCI_MCU_LTSSTBEN_SS4 BIT3                    // 0/0/x/x MCU_LTSSTBEN_SS4
    #define CND003_OPTCFGXHCI_MCU_LTSSTBEN_SS3 BIT2                    // 0/0/x/x MCU_LTSSTBEN_SS3
    #define CND003_OPTCFGXHCI_MCU_LTSSTBEN_SS2 BIT1                    // 0/0/x/x MCU_LTSSTBEN_SS2
    #define CND003_OPTCFGXHCI_MCU_LTSSTBEN_SS1 BIT0                    // 0/0/0/0 MCU_LTSSTBEN_SS1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX10C 0x10C // xHCI Option RX10C
    #define CND003_OPTCFGXHCI_LDM_SUBTYPE      0xF000          // 7h/7h/x/x LDM_SUBTYPE
    #define CND003_OPTCFGXHCI_ISOCFC_FMWNDW    0x3FF           // 14h/14h/0/0 ISOCFC_FMWNDW
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX10E 0x10E // xHCI Option RX10E
    #define CND003_OPTCFGXHCI_R_TMOUTCNT_NONU0EN   BIT7    // 0/0/x/x R_TMOUTCNT_NONU0EN
    #define CND003_OPTCFGXHCI_R_RXDPPDKERR_EN      BIT6    // 1b/1b/x/x R_RXDPPDKERR_EN
    #define CND003_OPTCFGXHCI_R_DPPGATE_EN         BIT5    // 0/0/x/x R_DPPGATE_EN
    #define CND003_OPTCFGXHCI_R_FAKERLS_FIX        BIT4    // 0/0/x/x R_FAKERLS_FIX
    #define CND003_OPTCFGXHCI_R_NUMP0_RTY_FIX      BIT3    // 0/0/x/x R_NUMP0_RTY_FIX
    #define CND003_OPTCFGXHCI_R_RLSBUF_FIX         BIT2    // 0/0/x/x R_RLSBUF_FIX
    #define CND003_OPTCFGXHCI_R_NONEU0PASSASYN_OUT BIT1    // 0/0/x/x R_NONEU0PASSASYN_OUT
    #define CND003_OPTCFGXHCI_R_NONEU0PASSASYN_IN  BIT0    // 0/0/x/x R_NONEU0PASSASYN_IN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX10F 0x10F // xHCI Option RX10F
    #define CND003_OPTCFGXHCI_R_NRDYEOF_FIX    BIT3    // 1b/1b/x/x R_NRDYEOF_FIX
    #define CND003_OPTCFGXHCI_TAG_REMAP_EN     BIT2    // 1b/1b/x/x DMA Read TAG Remap Enable
    #define CND003_OPTCFGXHCI_PKTIN_BUFCNT_FIX BIT1    // 0/0/x/x PKTIN_BUFCNT_FIX
    #define CND003_OPTCFGXHCI_R_ISOLPFSHT      BIT0    // 0/0/x/x R_ISOLPFSHT
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX110 0x110 // xHCI Option RX110
    #define CND003_OPTCFGXHCI_PXHS_STOPCLK_TMOUT_PARM      0xFF0000    // Ch/x/x/x Stop Clock Timeout Parameter
    #define CND003_OPTCFGXHCI_PXHS_ENISO_TMOUT_PARM        0xFF00      // Ch/x/x/x Enable ISO Cell Timeout Parameter
    #define CND003_OPTCFGXHCI_PXHS_ASSERTRST_TMOUT_PARM    0xFF        // Ch/x/x/x Assert Reset Signal Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX114 0x114 // xHCI Option RX114
    #define CND003_OPTCFGXHCI_PXHS_ASSERTPD_TMOUT_PARM     0xFFFF0000  // 3E8h/x/x/x Assert Power Down and Wait Power Down Finish Timeout Parameter
    #define CND003_OPTCFGXHCI_PXHS_DEASSERTPD_TMOUT_PARM   0xFFFF      // 3E8h/x/x/x De-Assert Power Down and Wait Power Up Finish Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX118 0x118 // xHCI Option RX118
    #define CND003_OPTCFGXHCI_PXHS_STARTCLK_TMOUT_PARM     0xFF0000    // Ch/x/x/x Start Clock Timeout Parameter
    #define CND003_OPTCFGXHCI_PXHS_DISISO_TMOUT_PARM       0xFF00      // Ch/x/x/x Disable ISO Cell Timeout Parameter
    #define CND003_OPTCFGXHCI_PXHS_DEASSERTRST_TMOUT_PARM  0xFF        // Ch/x/x/x De-Assert Reset Signal Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX11C 0x11C // xHCI Option RX11C
    #define CND003_OPTCFGXHCI_PXHS_PS_EN   BIT0    // 0/x/x/x xHCI Power Switch Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX11D 0x11D // xHCI Option RX11D
    #define CND003_OPTCFGXHCI_PXHS_FWREQ2PD    BIT4                    // 0/x/x/x FW Request to Power Down
    #define CND003_OPTCFGXHCI_PXHS_FWREQ2PU    BIT0                    // 0/x/x/x FW Request to Power Up
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX11E 0x11E // xHCI Option RX11E
    #define CND003_OPTCFGXHCI_PXHS_CURST   0xFFF   // 0h/x/x/x xHCI Power G0iating Controller State Machine
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX120 0x120 // xHCI Option RX120
    #define CND003_OPTCFGXHCI_PXSS_STOPCLK_TMOUT_PARM      0xFF0000    // Ch/x/x/x Stop Clock Timeout Parameter
    #define CND003_OPTCFGXHCI_PXSS_ENISO_TMOUT_PARM        0xFF00      // Ch/x/x/x Enable ISO Cell Timeout Parameter
    #define CND003_OPTCFGXHCI_PXSS_ASSERTRST_TMOUT_PARM    0xFF        // Ch/x/x/x Assert Reset Signal Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX124 0x124 // xHCI Option RX124
    #define CND003_OPTCFGXHCI_PXSS_ASSERTPD_TMOUT_PARM     0xFFFF0000  // 3E8h/x/x/x Assert Power Down and Wait Power Down finish Timeout Parameter
    #define CND003_OPTCFGXHCI_PXSS_DEASSERTPD_TMOUT_PARM   0xFFFF      // 3E8h/x/x/x De-Assert Power Down and Wait Power Up finish Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX128 0x128 // xHCI Option RX128
    #define CND003_OPTCFGXHCI_PXSS_STARTCLK_TMOUT_PARM     0xFF0000    // Ch/x/x/x Start Clock Timeout Parameter
    #define CND003_OPTCFGXHCI_PXSS_DISISO_TMOUT_PARM       0xFF00      // Ch/x/x/x Disable ISO Cell Timeout Parameter
    #define CND003_OPTCFGXHCI_PXSS_DEASSERTRST_TMOUT_PARM  0xFF        // Ch/x/x/x De-Assert Reset Signal Timeout Parameter
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX12C 0x12C // xHCI Option RX12C
    #define CND003_OPTCFGXHCI_PXSS_PS_EN   BIT0    // 0/x/x/x xHCI Power Switch Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX12D 0x12D // xHCI Option RX12D
    #define CND003_OPTCFGXHCI_PXSS_FWREQ2PD    BIT4                    // 0/x/x/x FW Request to Power Down
    #define CND003_OPTCFGXHCI_PXSS_FWREQ2PU    BIT0                    // 0/x/x/x FW Request to Power Up
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX12E 0x12E // xHCI Option RX12E
    #define CND003_OPTCFGXHCI_PXSS_CURST   0xFFF   // 0h/x/x/x xHCI Power Gating Controller State Machine
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX130 0x130 // xHCI Option RX130
    #define CND003_OPTCFGXHCI_S1XRPRI  (BIT10 + BIT11) // 0/0/x/x SSPBI Schedule Upstream Read Priority
    #define CND003_OPTCFGXHCI_S1XWPRI  (BIT8 + BIT9)   // 0/0/x/x SSPBI Schedule Upstream Write Priority
    #define CND003_OPTCFGXHCI_B2XRPRI  (BIT6 + BIT7)   // 0/0/x/x Buffer Management Upstream Read Priority
    #define CND003_OPTCFGXHCI_B2XWPRI  (BIT4 + BIT5)   // 0/0/x/x Buffer Management Upstream Write Priority
    #define CND003_OPTCFGXHCI_B3XRPRI  (BIT2 + BIT3)   // 0/0/x/x Buffer Management Upstream Read Priority
    #define CND003_OPTCFGXHCI_B3XWPRI  (BIT0 + BIT1)   // 0/0/x/x Buffer Management Upstream Write Priority
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX134 0x134 // xHCI Option Rx134
    #define CND003_OPTCFGXHCI_OCSEL2   (BIT4 + BIT5 + BIT6)    // 0/0/x/x SS/HS Port 2 OC input Driving Pad Selection
    #define CND003_OPTCFGXHCI_OCSEL1   (BIT0 + BIT1 + BIT2)    // 0/0/x/x SS/HS Port 1 OC input Driving Pad Selection
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX135 0x135 // xHCI Option Rx135
    #define CND003_OPTCFGXHCI_OCSEL4   (BIT4 + BIT5 + BIT6)    // 0/0/x/x SS/HS Port 4 OC input Driving Pad Selection
    #define CND003_OPTCFGXHCI_OCSEL3   (BIT0 + BIT1 + BIT2)    // 0/0/x/x SS/HS Port 3 OC input Driving Pad Selection
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX136 0x136 // xHCI Option Rx136
    #define CND003_OPTCFGXHCI_OCSEL5   (BIT0 + BIT1 + BIT2)    // 000b/0/x/x SS/HS Port 5 OC input Driving Pad Selection
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX137 0x137 // xHCI Option Rx137
    #define CND003_OPTCFGXHCI_R_U31PHY_EN              BIT3    // 1b/1b/x/x Enable USB31PHY
    #define CND003_OPTCFGXHCI_EN_VPWRGD_PDAPLL         BIT2    // 0/0/x/x Enable to use VPWRGD to control PDAPLL for USB2.0 PHY
    #define CND003_OPTCFGXHCI_CMBPHY_CFGDONE_BYPASS    BIT1    // 0/0/x/x Bypass CMBPHY_CFGDONE in reset path
    #define CND003_OPTCFGXHCI_USB3EPHY_REFCLKOK_BYPASS BIT0    // 0/0/x/x Bypass USB3EPHY Referrence Clock PLLOK in reset path
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX138 0x138 // xHCI Option Rx138
    #define CND003_OPTCFGXHCI_DCMPS_XH     (BIT4 + BIT5 + BIT6)    // 0/0/x/x Max Payload Size of xHCI
    #define CND003_OPTCFGXHCI_DCMRRS_XH    (BIT1 + BIT2 + BIT3)    // 0/0/x/x Max Read Request Size of xHCI
    #define CND003_OPTCFGXHCI_DMARS_XHCIEN BIT0                    // 0/0/x/x DMA Request Size by xHCI Enable
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX139 0x139 // xHCI Option Rx139
    #define CND003_OPTCFGXHCI_SSPISOPRI    (BIT0 + BIT1)   // 01b/01b/x/x SSPBI ISO Transaction Upstream Request Priority
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX13A 0x13A // xHCI Option Rx13A
    #define CND003_OPTCFGXHCI_R_RXHZ_DIS_SS5   BIT4                    // 1b/1b/x/x R_RXHZ_DIS_SS5
    #define CND003_OPTCFGXHCI_R_RXHZ_DIS_SS4   BIT3                    // 1b/1b/x/x R_RXHZ_DIS_SS4
    #define CND003_OPTCFGXHCI_R_RXHZ_DIS_SS3   BIT2                    // 1b/1b/x/x R_RXHZ_DIS_SS3
    #define CND003_OPTCFGXHCI_R_RXHZ_DIS_SS2   BIT1                    // 1b/1b/x/x R_RXHZ_DIS_SS2
    #define CND003_OPTCFGXHCI_R_RXHZ_DIS_SS1   BIT0                    // 1b/1b/x/x R_RXHZ_DIS_SS1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX13B 0x13B // xHCI Option Rx13B
    #define CND003_OPTCFGXHCI_R_P2CRTABT_SETEN BIT6    // 0/0/x/x R_P2CRTABT_SETEN
    #define CND003_OPTCFGXHCI_NXTSPEVENT_EN    BIT5    // 0/0/x/x Generate "Short Packet" CC for Subsequent Transfer Event with IOC=1 o...
    #define CND003_OPTCFGXHCI_TAG_REMAP_XHCIEN BIT4    // 0/0/x/x DMARTAG Remap Enable by XHCI
    #define CND003_OPTCFGXHCI_R_P2CRABT_INTEN  BIT3    // 0/0/x/x R_P2CRABT_INTEN
    #define CND003_OPTCFGXHCI_R_FAKERLS_NEW    BIT2    // 1b/1b/x/x R_FAKERLS_NEW
    #define CND003_OPTCFGXHCI_R_PING_ACK_SEL   BIT1    // 0/0/x/x R_PING_ACK_SEL
    #define CND003_OPTCFGXHCI_R_TTCHK_MSK      BIT0    // 0/0/x/x R_TTCHK_MSK
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX13C 0x13C // xHCI Option Rx13C
    #define CND003_OPTCFGXHCI_R_DBGWCLK_SEL    0xF0    // 0/0/x/x R_DBGWCLK_SEL
    #define CND003_OPTCFGXHCI_R_D3HOT_MMIO_RD  BIT2    // 0/0/x/x R_D3HOT_MMIO_RD
    #define CND003_OPTCFGXHCI_R_TSTPKT_HW      BIT1    // 1b/1b/x/x R_TSTPKT_HW
    #define CND003_OPTCFGXHCI_FW_ISOINHC4_EN   BIT0    // 0/0/x/x FW_ISOINHC4_EN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX13D 0x13D // xHCI Option Rx13D
    #define CND003_OPTCFGXHCI_R_FORCEPM_SS5    BIT4                    // 0/0/x/x R_FORCEPM_SS5
    #define CND003_OPTCFGXHCI_R_FORCEPM_SS4    BIT3                    // 0/0/x/x R_FORCEPM_SS4
    #define CND003_OPTCFGXHCI_R_FORCEPM_SS3    BIT2                    // 0/0/x/x R_FORCEPM_SS3
    #define CND003_OPTCFGXHCI_R_FORCEPM_SS2    BIT1                    // 0/0/x/x R_FORCEPM_SS2
    #define CND003_OPTCFGXHCI_R_FORCEPM_SS1    BIT0                    // 0/0/x/x R_FORCEPM_SS1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX13E 0x13E // xHCI Option RX13E
    #define CND003_OPTCFGXHCI_USB2P4_LPM_FS_CLK_1M5_DYNCLKEN   BIT7    // 0/0/x/x USB2P4_LPM_FS_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P4_LPM_FS_CLK_12M_DYNCLKEN   BIT6    // 0/0/x/0 USB2P4_LPM_FS_CLK_12M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_LPM_FS_CLK_1M5_DYNCLKEN   BIT5    // 0/0/x/0 USB2P3_LPM_FS_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P3_LPM_FS_CLK_12M_DYNCLKEN   BIT4    // 0/0/x/0 USB2P3_LPM_FS_CLK_12M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_LPM_FS_CLK_1M5_DYNCLKEN   BIT3    // 0/0/x/0 USB2P2_LPM_FS_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P2_LPM_FS_CLK_12M_DYNCLKEN   BIT2    // 0/0/x/0 USB2P2_LPM_FS_CLK_12M_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_LPM_FS_CLK_1M5_DYNCLKEN   BIT1    // 0/0/x/0 USB2P1_LPM_FS_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P1_LPM_FS_CLK_12M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P1_LPM_FS_CLK_12M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX13F 0x13F // xHCI Option RX13F
    #define CND003_OPTCFGXHCI_USB2P5_LPM_FS_CLK_1M5_DYNCLKEN   BIT1    // 0/0/x/0 USB2P5_LPM_FS_CLK_1M5_DYNCLKEN
    #define CND003_OPTCFGXHCI_USB2P5_LPM_FS_CLK_12M_DYNCLKEN   BIT0    // 0/0/x/0 USB2P5_LPM_FS_CLK_12M_DYNCLKEN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX140 0x140 // xHCI Option Rx140
    #define CND003_OPTCFGXHCI_R_DEGLITCH_SEL       (BIT6 + BIT7)   // 0/x/x/x R_DEGLITCH_SEL
    #define CND003_OPTCFGXHCI_TEST_U31FREQ         BIT5            // 0/x/x/x TEST_U31FREQ
    #define CND003_OPTCFGXHCI_R_DSPORT_WRST_SS5    BIT4            // 0/0/x/x R_DSPORT_WRST_SS5
    #define CND003_OPTCFGXHCI_R_DSPORT_WRST_SS4    BIT3            // 0/0/x/x R_DSPORT_WRST_SS4
    #define CND003_OPTCFGXHCI_R_DSPORT_WRST_SS3    BIT2            // 0/0/x/x R_DSPORT_WRST_SS3
    #define CND003_OPTCFGXHCI_R_DSPORT_WRST_SS2    BIT1            // 0/0/x/x R_DSPORT_WRST_SS2
    #define CND003_OPTCFGXHCI_R_DSPORT_WRST_SS1    BIT0            // 0/0/x/x R_DSPORT_WRST_SS1
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX141 0x141 // xHCI Option Rx141
    #define CND003_OPTCFGXHCI_R_USB3HC_DBG_SEL_MODE    BIT0    // 0/0/x/x R_USB3HC_DBG_SEL_MODE
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX144 0x144 // xHCI Option Rx144
    #define CND003_OPTCFGXHCI_R_USB3HC_DBG_SEL_G1  0xFFF0000   // 0/0/x/x R_USB3HC_DBG_SEL_G1
    #define CND003_OPTCFGXHCI_R_USB3HC_DBG_SEL_G0  0xFFF       // 0/0/x/x R_USB3HC_DBG_SEL_G0
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX148 0x148 // xHCI Option Rx148
    #define CND003_OPTCFGXHCI_R_USB3HC_DBG_SEL_G3  0xFFF0000   // 0/0/x/x R_USB3HC_DBG_SEL_G3
    #define CND003_OPTCFGXHCI_R_USB3HC_DBG_SEL_G2  0xFFF       // 0/0/x/x R_USB3HC_DBG_SEL_G2
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX14C 0x14C // xHCI Option Rx14C
    #define CND003_OPTCFGXHCI_SPEVENT_HPEN         BIT5            // 0/x/x/x Short Packet Event Hi Priority Enable
    #define CND003_OPTCFGXHCI_MCU_RST_SEL          BIT4            // 0/x/x/x OpenRisc Reset Selection
    #define CND003_OPTCFGXHCI_R_HSISO_SPD_NXT_FIX  BIT3            // 0/x/x/x R_HSISO_SPD_NXT_FIX
    #define CND003_OPTCFGXHCI_R_HSISO_SPD_CUR_FIX  BIT2            // 0/x/x/x R_HSISO_SPD_CUR_FIX
    #define CND003_OPTCFGXHCI_R_TXSOF_SEL          BIT1            // 0/0/x/x R_TXSOF_SEL
    #define CND003_OPTCFGXHCI_R_HS_TXSOF_EN        BIT0            // 1b/1b/x/x R_HS_TXSOF_EN
#define CND003_OPTCFGXHCI_XHCI_OPTION_RX14D 0x14D // xHCI Option Rx14D
    #define CND003_OPTCFGXHCI_R_UPU3FLAG_SS5   BIT4                    // 0/x/x/x Enable UFP Control DFP U3-TXP5
    #define CND003_OPTCFGXHCI_R_UPU3FLAG_SS4   BIT3                    // 0/x/x/x Enable UFP Control DFP U3-TXP4
    #define CND003_OPTCFGXHCI_R_UPU3FLAG_SS3   BIT2                    // 0/x/x/x Enable UFP Control DFP U3-TXP3
    #define CND003_OPTCFGXHCI_R_UPU3FLAG_SS2   BIT1                    // 0/x/x/x Enable UFP Control DFP U3-TXP2
    #define CND003_OPTCFGXHCI_R_UPU3FLAG_SS1   BIT0                    // 0/x/x/x Enable UFP Control DFP U3-TXP1
// CND003_OPTCFG_HSBI
#define CND003_OPTCFGHSBI_USB2_OPTION_RX00 0x0 // USB2 Option RX00
    #define CND003_OPTCFGHSBI_R_NEWHSBIRST     BIT7    // 0/0/x/x New HSBI Reset
    #define CND003_OPTCFGHSBI_HSBI_PATCH0      BIT6    // 0/0/x/x HSBI PATCH 0
    #define CND003_OPTCFGHSBI_HSBI_PATCH1      BIT5    // 0/0/x/x HSBI PATCH 1
    #define CND003_OPTCFGHSBI_VALIDCLKEN       BIT4    // 0/0/x/x HSTRANS Use VALID as Clock Enable
    #define CND003_OPTCFGHSBI_HSAUXCLKFREE     BIT3    // 0/0/x/x HSAUX Clock Free Running
    #define CND003_OPTCFGHSBI_HSBI_DEBUGEN     BIT2    // 1b/1b/x/x HS BI Debug Enable
    #define CND003_OPTCFGHSBI_HSBI_DYNCLKEN    BIT1    // 0/0/x/x HS BI Dynamic Clock Enable
    #define CND003_OPTCFGHSBI_ENHSBI           BIT0    // 1b/1b/x/x HS BI Enable
#define CND003_OPTCFGHSBI_USB2_OPTION_RX01 0x1 // USB2 Option RX01
    #define CND003_OPTCFGHSBI_EN_ISOHANDCHK        BIT7    // 0/0/x/x Check RXHAND in ISO Transaction or Not
    #define CND003_OPTCFGHSBI_EN_CHKTOGCRC         BIT6    // 0/0/x/x Enable Check CRCERR Even TOG Mismatch
    #define CND003_OPTCFGHSBI_EN_UTM_RESET         BIT5    // 1b/1b/x/x Enable UTM Reset if UTM Hang
    #define CND003_OPTCFGHSBI_EN_UTM_SPDUP         BIT4    // 0/0/x/x Enable UTM Speedup
    #define CND003_OPTCFGHSBI_EN_REF_RVLD          BIT3    // 1b/1b/x/x Enable Reference Squelch as Bus Idle
    #define CND003_OPTCFGHSBI_DIS_NARROW_SOF       BIT2    // 0/0/x/x Options for SOF_DISCONN Speed up
    #define CND003_OPTCFGHSBI_DIS_CHKEOPERR        BIT1    // 1b/1b/x/x Disable PHY eop='hFE Pattern Check
    #define CND003_OPTCFGHSBI_DIS_IMPRV_SQUELCH    BIT0    // 1b/1b/x/x PHYOPT TMODE
#define CND003_OPTCFGHSBI_USB2_OPTION_RX02 0x2 // USB2 Option RX02
    #define CND003_OPTCFGHSBI_DIS_SOF_RUN      BIT7    // 0/0/x/x DIS_SOF_RUN
    #define CND003_OPTCFGHSBI_TXDELAY_EN       BIT6    // 0/0/x/x Insert Delay between Transactions
    #define CND003_OPTCFGHSBI_TXTMOUT_EN       BIT5    // 0/0/x/x Provide TMOUT to Device if Error Detected
    #define CND003_OPTCFGHSBI_DIS_PDRCV        BIT4    // 0/0/x/x Disable Power down Enable
    #define CND003_OPTCFGHSBI_BABOPT           BIT3    // 0/0/x/x EOF Babble Option
    #define CND003_OPTCFGHSBI_TEST_EYE_EN      BIT2    // 0/0/x/x TEST_EYE Pattern Enable
    #define CND003_OPTCFGHSBI_SOF_DISCONN_CHK  BIT1    // 1b/1b/x/x Check Disconnect in SOF EOP Period
    #define CND003_OPTCFGHSBI_FORCE_CRCERR     BIT0    // 0/0/x/x FORCE_CRCERR
#define CND003_OPTCFGHSBI_USB2_OPTION_RX03 0x3 // USB2 Option RX03
    #define CND003_OPTCFGHSBI_TMOUT_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX03 // FFh/FFh/x/x Parameter for TimeOut
#define CND003_OPTCFGHSBI_USB2_OPTION_RX04 0x4 // USB2 Option RX04
    #define CND003_OPTCFGHSBI_TXDELAY_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX04 // 0/0/x/x Insert Delay Parameter
#define CND003_OPTCFGHSBI_USB2_OPTION_RX05 0x5 // USB2 Option RX05
    #define CND003_OPTCFGHSBI_PORTRST_CNT_PARM (BIT6 + BIT7)   // 0/0/x/x Port Reset Counter Parameter
    #define CND003_OPTCFGHSBI_PORTRSM_CNT_PARM (BIT4 + BIT5)   // 0/0/x/x Port Resume Counter Parameter
    #define CND003_OPTCFGHSBI_TURN_PARM        0xF             // 9h/9h/x/x Turn Around Time Parameter
#define CND003_OPTCFGHSBI_USB2_OPTION_RX06 0x6 // USB2 Option RX06
    #define CND003_OPTCFGHSBI_HSBI_FORCEU0     BIT6    // 0/0/x/x Reserved
    #define CND003_OPTCFGHSBI_DIS_TERM_ON      BIT5    // 0/0/x/x Termination Disable Feature
    #define CND003_OPTCFGHSBI_HSENFB_DIS       BIT4    // 0/0/x/x HsEnFB_Dis
    #define CND003_OPTCFGHSBI_PDPHY_DIS        BIT3    // 0/0/x/x Power down EPHY Disable
    #define CND003_OPTCFGHSBI_EN_NEW_PDHSDRV   BIT2    // 0/0/x/x EN_NEW_PDHSDRV
    #define CND003_OPTCFGHSBI_EN_NEW_PDAPLL    BIT1    // 0/0/x/x Enable Power down APLL as No Device Is Connected
    #define CND003_OPTCFGHSBI_EN_PDPHY_INPDPLL BIT0    // 0/0/x/x Enable Power down USBPHY when APLL Is Power down
#define CND003_OPTCFGHSBI_USB2_OPTION_RX07 0x7 // USB2 Option RX07
    #define CND003_OPTCFGHSBI_AUTOCHK_EN   BIT2    // 0/0/x/x UTM Auto Check Enable
    #define CND003_OPTCFGHSBI_SYNC_JEND    BIT1    // 1b/1b/x/x Used to Detect Sync Pattern with 2J?s End
    #define CND003_OPTCFGHSBI_SYNC_FAST    BIT0    // 0/0/x/x Sync Fast without rbc_120m Synchronizer
#define CND003_OPTCFGHSBI_HSBI_OPTION_RX16 0x16 // HSBI Option RX16
    #define CND003_OPTCFGHSBI_ASYEP1_CNAKSEL   (BIT4 + BIT5)   // 0/0/x/x ASYEPCTL Consecutive NAK Count selection
    #define CND003_OPTCFGHSBI_ASYEP1_SLOWPSEL  (BIT2 + BIT3)   // 0/0/x/x ASYEPCTL Slow Period Selection
    #define CND003_OPTCFGHSBI_ASYEP1_AUTOSLOW  BIT1            // 0/0/x/x ASYEPCTL Auto Slow 
    #define CND003_OPTCFGHSBI_ASYEP1_SLOWEN    BIT0            // 0/0/x/x ASYEPCTL Slow Enable
#define CND003_OPTCFGHSBI_HSBI_OPTION_RX17 0x17 // HSBI Option RX17
    #define CND003_OPTCFGHSBI_ASYEP2_CNAKSEL   (BIT4 + BIT5)   // 01b/01b/x/x ASYEPCTL Consecutive NAK Count Selection
    #define CND003_OPTCFGHSBI_ASYEP2_SLOWPSEL  (BIT2 + BIT3)   // 01b/01b/x/x ASYEPCTL Slow Period Selection
    #define CND003_OPTCFGHSBI_ASYEP2_AUTOSLOW  BIT1            // 1b/1b/x/x ASYEPCTL Auto Slow
    #define CND003_OPTCFGHSBI_ASYEP2_SLOWEN    BIT0            // 1b/1b/x/x ASYEPCTL Slow Enable
#define CND003_OPTCFGHSBI_USB2_OPTION_RX18 0x18 // USB2 Option RX18
    #define CND003_OPTCFGHSBI_ASYEP1_HSTURBO   BIT7    // 0/0/x/x ASYEPCTL1 HS Turbo Mode Enable
    #define CND003_OPTCFGHSBI_ASYEP2_HSTURBO   BIT6    // 0/0/x/x ASYEPCTL2 HS Turbo Mode Enable
    #define CND003_OPTCFGHSBI_PEREP_HSTURBO    BIT5    // 0/0/x/x PEREPCTL HS Turbo Mode Enable
    #define CND003_OPTCFGHSBI_HS_SSONLYISTEN   BIT4    // 1b/1b/x/x Start Split at First Service Opportunity
    #define CND003_OPTCFGHSBI_PRESOFCHKEN      BIT3    // 1b/1b/x/x PRESOFCHK Enable
    #define CND003_OPTCFGHSBI_R_ENPERINTURBO   BIT2    // 1b/1b/x/x Enable PEREP IN Turbo Mode
    #define CND003_OPTCFGHSBI_BABBLE_FLUSH_EN  BIT1    // 0/0/x/x BABBLE_FLUSH_EN
    #define CND003_OPTCFGHSBI_HS_REDUCE        BIT0    // 0/0/x/x Frame Timer Reduce Mode
#define CND003_OPTCFGHSBI_USB2_OPTION_RX19 0x19 // USB2 Option RX19
    #define CND003_OPTCFGHSBI_LOCKTMOSEL           (BIT6 + BIT7)   // 0/0/x/x LOCKTMOSEL
    #define CND003_OPTCFGHSBI_HALTRSTEN            BIT5            // 1b/1b/x/x Reset Halted Endpoint Content
    #define CND003_OPTCFGHSBI_ASY_SPSOINTV_EN      BIT4            // 0/0/x/x Async Split service opportunity interval enable
    #define CND003_OPTCFGHSBI_ASY_SPSOINTV_PARM    (BIT2 + BIT3)   // 0/0/x/x Async Split transaction packet interval sel
    #define CND003_OPTCFGHSBI_QUICKCPM             BIT1            // 1b/1b/x/x QUICKCPM
    #define CND003_OPTCFGHSBI_CMDPKTAUTO           BIT0            // 0/0/x/x Command Packet Status Stage Auto Mode
#define CND003_OPTCFGHSBI_USB2_OPTION_RX1A 0x1A // USB2 Option RX1A
    #define CND003_OPTCFGHSBI_PEREP_PRESOF_SEL     (BIT6 + BIT7)   // 01b/01b/x/x PEREP Presof Offset Select
    #define CND003_OPTCFGHSBI_ASYEP2_PRESOF_SEL    (BIT4 + BIT5)   // 01b/01b/x/x ASYEP2 Presof Offset Select
    #define CND003_OPTCFGHSBI_ASYEP1_PRESOF_SEL    (BIT2 + BIT3)   // 01b/01b/x/x ASYEP1 Presof Offset Select
    #define CND003_OPTCFGHSBI_HSPRESOF_SEL         (BIT0 + BIT1)   // 01b/01b/x/x HSPRESOF_SEL
#define CND003_OPTCFGHSBI_USB2_OPTION_RX1B 0x1B // USB2 Option RX1B
    #define CND003_OPTCFGHSBI_R_ENFLSINTFIX    BIT7    // 1b/1b/x/x Enable FS/LS INT IN Fix
    #define CND003_OPTCFGHSBI_R_ENFSISOFIX     BIT6    // 0/0/x/x Enable FS ISO Fix
    #define CND003_OPTCFGHSBI_ECS_SPEAKER_FIX  BIT5    // 1b/1b/x/x Enable ECS Speaker Fix
    #define CND003_OPTCFGHSBI_HUAWEI3G_FIX     BIT4    // 1b/1b/x/x Enable HUAWEI 3G Fix
    #define CND003_OPTCFGHSBI_TV_TUNER_FIX     BIT3    // 1b/1b/x/x Enable TV Tuner Fix
    #define CND003_OPTCFGHSBI_TX120MDYNDIS     BIT2    // 0/0/x/x TX 120M Clock Dynamic Clock Control Enable
    #define CND003_OPTCFGHSBI_RX120MDYNDIS     BIT1    // 0/0/x/x RX 120M Clock Dynamic Clock Control Enable
    #define CND003_OPTCFGHSBI_R_CV_RMUSBHUB    BIT0    // 0/0/x/x Remove the internal USBHUB connection for CV Test
#define CND003_OPTCFGHSBI_USB2_OPTION_RX1C 0x1C // USB2 Option RX1C
    #define CND003_OPTCFGHSBI_R_CRSM_STOPCNTPARM_SUS CND003_OPTCFGHSBI_USB2_OPTION_RX1C // 9Ch/9Ch/x/x CResume Stop Parameter
#define CND003_OPTCFGHSBI_USB2_OPTION_RX1D 0x1D // USB2 Option RX1D
    #define CND003_OPTCFGHSBI_HSBI_OPTW0           0xF0    // 0/0/x/x HSBI OPTION Word 0
    #define CND003_OPTCFGHSBI_R_XHCVER10_SUS       BIT3    // 1b/1b/x/x An Indicator Operating on xHCI 1.0 Mode
    #define CND003_OPTCFGHSBI_R_RMUSBHUB_SUS       BIT2    // 0/0/x/x Remove Internal Integrated HUB
    #define CND003_OPTCFGHSBI_R_RSMJKEN_SUS        BIT1    // 1b/1b/x/x Enable the Function of Reflecting Resume_JtoK Signal to Root Port
    #define CND003_OPTCFGHSBI_R_DISCRSMSTOP_SUS    BIT0    // 0/0/x/x Disable the Stopping Function of CResume Counter in Resume State
#define CND003_OPTCFGHSBI_USB2_OPTION_RX1E 0x1E // USB2 Option RX1E
    #define CND003_OPTCFGHSBI_HSBI_OPT0_SUS CND003_OPTCFGHSBI_USB2_OPTION_RX1E // 0/0/x/x HSBI OPTION SUS 0
#define CND003_OPTCFGHSBI_USB2_OPTION_RX1F 0x1F // USB2 Option RX1F
    #define CND003_OPTCFGHSBI_HSBI_OPT1_SUS CND003_OPTCFGHSBI_USB2_OPTION_RX1F // FFh/FFh/x/x HSBI OPTION SUS 1
#define CND003_OPTCFGHSBI_USB2_OPTION_RX20 0x20 // USB2 Option RX20
    #define CND003_OPTCFGHSBI_R_HS_CLKEN_EXT   BIT2    // 0/0/x/x R_HS_CLKEN_EXT
    #define CND003_OPTCFGHSBI_HSBFOUTRLSALL_EN BIT1    // 0/0/x/x HSTRANS Enable to Release All OUT Buffer when OUT TRANS Idle
    #define CND003_OPTCFGHSBI_HSBFINRLSALL_EN  BIT0    // 0/0/x/x HSTRANS Enable to Release All IN Buffer when IN TRANS Idle
#define CND003_OPTCFGHSBI_USB2_OPTION_RX100 0x100 // USB2 Option RX100
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_A     0xF0    // 1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_A   0xF     // 6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX101 0x101 // USB2 Option RX101
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_A CND003_OPTCFGHSBI_USB2_OPTION_RX101 // 5ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX102 0x102 // USB2 Option RX102
    #define CND003_OPTCFGHSBI_REG_RXCPLOPT_A                   BIT7    // 1b/1b/x/x REG_RXCPLOPT_A
    #define CND003_OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_A   BIT6    // 1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_A
    #define CND003_OPTCFGHSBI_REG_L1_EN_A                      BIT5    // 0/0/x/x REG_L1_EN_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_A        BIT4    // 0/0/x/x REG_UP_SIE_HC_SYNC_JEND_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_A        BIT3    // 0/0/x/x REG_UP_SIE_HC_SYNC_FAST_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_A     BIT2    // 0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_A        BIT1    // 0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_A     BIT0    // 1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX103 0x103 // USB2 Option RX103
    #define CND003_OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_A CND003_OPTCFGHSBI_USB2_OPTION_RX103 // 24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX104 0x104 // USB2 Option RX104
    #define CND003_OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_A  0xF0    // 6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_A
    #define CND003_OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_A    0xF     // 1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX105 0x105 // USB2 Option RX105
    #define CND003_OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_A   BIT7    // 1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RCTB_DIR_A              BIT6    // 0/0/x/x REG_NPTT_RCTB_DIR_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKHSH_A               BIT5    // 1b/1b/x/x REG_NPTT_RCHKHSH_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_EN_A            BIT4    // 1b/1b/x/x REG_NPTT_RRACKTM_EN_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RCONTFST_A              BIT3    // 1b/1b/x/x REG_NPTT_RCONTFST_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKDATAPID_A           BIT2    // 0/0/x/x REG_NPTT_RCHKDATAPID_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RMATCH_ALL_A            BIT1    // 1b/1b/x/x REG_NPTT_RMATCH_ALL_A
    #define CND003_OPTCFGHSBI_REG_EOF_RST_TX_A                 BIT0    // 0/0/x/x REG_EOF_RST_TX_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX106 0x106 // USB2 Option RX106
    #define CND003_OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_A      BIT4                    // 1b/1b/x/x REG_UPRX_STOP_TT_GATE_A
    #define CND003_OPTCFGHSBI_REG_PTT_SEARCH_LEN_A         (BIT2 + BIT3)           // 0/0/x/x REG_PTT_SEARCH_LEN_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_A      BIT1                    // 1b/1b/x/x REG_NPTT_RRACKTM_FWEN_A
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_A  BIT0                    // 1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX107 0x107 // USB2 Option RX107
    #define CND003_OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_A    0x7F    // 1Dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX108 0x108 // USB2 Option RX108
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_A    0xFFFF0000  // DACh/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_A
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_A    0xFFFF      // 1B58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX10C 0x10C // USB2 Option RX10C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FS_A    0xFFF0000   // 2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_A
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_LS_A    0xFFF       // F50h/f50h/x/x REG_NPTT_RRACKTM_LS_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX110 0x110 // USB2 Option RX110
    #define CND003_OPTCFGHSBI_REG_PTT_FULL_DELAY_A 0x7FF0000   // 90h/90h/x/x REG_PTT_FULL_DELAY_A
    #define CND003_OPTCFGHSBI_REG_PTT_LOW_DELAY_A  0x7FF       // 44ch/44ch/x/x REG_PTT_LOW_DELAY_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX114 0x114 // USB2 Option RX114
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF2_A   0x1FFF0000              // 7h/7h/x/x REG_FR_HIGH_EOF2_A
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF1_A   0x1FFF                  // 45h/45h/x/x REG_FR_HIGH_EOF1_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX118 0x118 // USB2 Option RX118
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF2_A   0xFFFF0000  // 31h/31h/x/x REG_FR_FULL_EOF2_A
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF1_A   0xFFFF      // 9Fh/9fh/x/x REG_FR_FULL_EOF1_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX11C 0x11C // USB2 Option RX11C
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_INIT_A   0x1FFF0000              // 1D4Ch/1d4ch/x/x REG_FR_HIGH_INIT_A
    #define CND003_OPTCFGHSBI_REG_FR_FULL_INIT_A   0xFFFF                  // EA60h/ea60h/x/x REG_FR_FULL_INIT_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX120 0x120 // USB2 Option RX120
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_OVFL_A   0x1FFF                  // 1D57h/1d57h/x/x REG_FR_HIGH_OVFL_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX122 0x122 // USB2 Option RX122
    #define CND003_OPTCFGHSBI_REG_EOP_FLAG_A               BIT6    // 1b/1b/x/x REG_EOP_FLAG_A
    #define CND003_OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_A  BIT5    // 1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_A
    #define CND003_OPTCFGHSBI_REG_PAMP_TX_EN_A             BIT4    // 0/0/x/x REG_PAMP_TX_EN_A
    #define CND003_OPTCFGHSBI_REG_SUSPEND_PROPAGATION_A    BIT3    // 0/0/x/x REG_SUSPEND_PROPAGATION_A
    #define CND003_OPTCFGHSBI_REG_DNCOLL_EOP_SEL_A         BIT2    // 0/0/x/x REG_DNCOLL_EOP_SEL_A
    #define CND003_OPTCFGHSBI_REG_TT_COLL_DET_DIS_A        BIT1    // 1b/1b/x/x REG_TT_COLL_DET_DIS_A
    #define CND003_OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_A      BIT0    // 0/0/x/x REG_DN_LPM_MANUAL_EOR_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX123 0x123 // USB2 Option RX123
    #define CND003_OPTCFGHSBI_REG_DN_EOI_EOR1_A CND003_OPTCFGHSBI_USB2_OPTION_RX123 // 64h/64h/x/x REG_DN_EOI_EOR1_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX124 0x124 // USB2 Option RX124
    #define CND003_OPTCFGHSBI_REG_DN_SUSDISABLE_A      BIT7    // 1b/1b/x/x REG_DN_SUSDISABLE_A
    #define CND003_OPTCFGHSBI_REG_EOF1_EOF2_A          BIT6    // 1b/1b/x/x REG_EOF1_EOF2_A
    #define CND003_OPTCFGHSBI_FS_LPBK_A                BIT5    // 0/0/x/x FS_LPBK_A
    #define CND003_OPTCFGHSBI_REG_DN_PORT_ERR_CHK_A    BIT4    // 0/0/x/x REG_DN_PORT_ERR_CHK_A
    #define CND003_OPTCFGHSBI_REG_DN_PDPHYDIS_A        BIT3    // 0/0/x/x REG_DN_PDPHYDIS_A
    #define CND003_OPTCFGHSBI_REG_DN_FORCEHSMOD_A      BIT2    // 0/0/x/x REG_DN_FORCEHSMOD_A
    #define CND003_OPTCFGHSBI_REG_DN_NOCHIRP_A         BIT1    // 0/0/x/x REG_DN_NOCHIRP_A
    #define CND003_OPTCFGHSBI_REG_DN_POWER_LOST_A      BIT0    // 1b/1b/x/x REG_DN_POWER_LOST_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX125 0x125 // USB2 Option RX125
    #define CND003_OPTCFGHSBI_REG_PDHSTRSE0_A                  BIT7    // 1b/1b/x/x REG_PDHSTRSE0_A
    #define CND003_OPTCFGHSBI_REG_STRICT_EOP_EN_A              BIT6    // 1b/1b/x/x REG_STRICT_EOP_EN_A
    #define CND003_OPTCFGHSBI_REG_DN_L1_EN_A                   BIT5    // 1b/1b/x/x REG_DN_L1_EN_A
    #define CND003_OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_A   BIT4    // 0/0/x/x REG_LONG_LOW_SPEED_DETECTION_A
    #define CND003_OPTCFGHSBI_REG_SE1_CONN_DIS_A               BIT3    // 1b/1b/x/x REG_SE1_CONN_DIS_A
    #define CND003_OPTCFGHSBI_REG_DBG104EN_A                   BIT2    // 0/0/x/x REG_DBG104EN_A
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_POWER_A           BIT1    // 0/0/x/x REG_DISCONNECT_POWER_A
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_OPTION_A          BIT0    // 1b/1b/x/x REG_DISCONNECT_OPTION_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX126 0x126 // USB2 Option RX126
    #define CND003_OPTCFGHSBI_REG_FS_EOPVAL_A  0xF0    // 3h/3h/x/x REG_FS_EOPVAL_A
    #define CND003_OPTCFGHSBI_REG_LS_EOPVAL_A  0xF     // 8h/8h/x/x REG_LS_EOPVAL_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX127 0x127 // USB2 Option RX127
    #define CND003_OPTCFGHSBI_REG_LONG_BUS_IDLE_A          BIT7    // 1b/1b/x/x REG_LONG_BUS_IDLE_A
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_A    BIT6    // 0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_A
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_A      BIT5    // 1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_A
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_A      BIT4    // 1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_A
    #define CND003_OPTCFGHSBI_REG_RXRESET_DIS_A            BIT3    // 0/0/x/x REG_RXRESET_DIS_A
    #define CND003_OPTCFGHSBI_PDSUSMOD_FW_A                BIT2    // 0/0/x/x PDSUSMOD_FW_A
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_A             BIT1    // 0/0/x/x REG_DISCVLD_FW_A
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_OPT_A         BIT0    // 0/0/x/x REG_DISCVLD_FW_OPT_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX128 0x128 // USB2 Option RX128
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_A            (BIT6 + BIT7)   // 0/0/x/x REG_DCP_DEBOUNCE_UP_A
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_A               (BIT4 + BIT5)   // 01b/01b/x/x REG_DCP_DEBOUNCE_A
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_A    BIT3            // 0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_A
    #define CND003_OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_A   BIT2            // 0/0/x/x REG_EXTEND_CDP_FLAG_DEBOUNCE_A
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLR_A              BIT1            // 0/0/x/x REG_CDPFLAG_FWCLR_A
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_A          BIT0            // 0/0/x/x REG_CDPFLAG_FWCLRONLY_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX129 0x129 // USB2 Option RX129
    #define CND003_OPTCFGHSBI_REG_DN_RWU_EN_A  BIT1    // 1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port A
    #define CND003_OPTCFGHSBI_REG_POWER_ON_A   BIT0    // 0/0/x/x REG_POWER_ON_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX12A 0x12A // USB2 Option RX12A
    #define CND003_OPTCFGHSBI_USB2P1_TMOUT_4MS_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX12A // 1Fh/1Fh/x/x USB2P1_TMOUT_4MS_PARM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX200 0x200 // USB2 Option RX200
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_B     0xF0    // 1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_B   0xF     // 6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX201 0x201 // USB2 Option RX201
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_B CND003_OPTCFGHSBI_USB2_OPTION_RX201 // 5Ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX202 0x202 // USB2 Option RX202
    #define CND003_OPTCFGHSBI_REG_RXCPLOPT_B                   BIT7    // 1b/1b/x/x REG_RXCPLOPT_B
    #define CND003_OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_B   BIT6    // 1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_B
    #define CND003_OPTCFGHSBI_REG_L1_EN_B                      BIT5    // 0/0/x/x REG_L1_EN_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_B        BIT4    // 0/0/x/x REG_UP_SIE_HC_SYNC_JEND_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_B        BIT3    // 0/0/x/x REG_UP_SIE_HC_SYNC_FAST_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_B     BIT2    // 0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_B        BIT1    // 0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_B     BIT0    // 1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX203 0x203 // USB2 Option RX203
    #define CND003_OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_B CND003_OPTCFGHSBI_USB2_OPTION_RX203 // 24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX204 0x204 // USB2 Option RX204
    #define CND003_OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_B  0xF0    // 6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_B
    #define CND003_OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_B    0xF     // 1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX205 0x205 // USB2 Option RX205
    #define CND003_OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_B   BIT7    // 1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RCTB_DIR_B              BIT6    // 0/0/x/x REG_NPTT_RCTB_DIR_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKHSH_B               BIT5    // 1b/1b/x/x REG_NPTT_RCHKHSH_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_EN_B            BIT4    // 1b/1b/x/x REG_NPTT_RRACKTM_EN_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RCONTFST_B              BIT3    // 1b/1b/x/x REG_NPTT_RCONTFST_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKDATAPID_B           BIT2    // 0/0/x/x REG_NPTT_RCHKDATAPID_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RMATCH_ALL_B            BIT1    // 1b/1b/x/x REG_NPTT_RMATCH_ALL_B
    #define CND003_OPTCFGHSBI_REG_EOF_RST_TX_B                 BIT0    // 0/0/x/x REG_EOF_RST_TX_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX206 0x206 // USB2 Option RX206
    #define CND003_OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_B      BIT4                    // 1b/1b/x/x REG_UPRX_STOP_TT_GATE_B
    #define CND003_OPTCFGHSBI_REG_PTT_SEARCH_LEN_B         (BIT2 + BIT3)           // 0/0/x/x REG_PTT_SEARCH_LEN_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_B      BIT1                    // 1b/1b/x/x REG_NPTT_RRACKTM_FWEN_B
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_B  BIT0                    // 1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX207 0x207 // USB2 Option RX207
    #define CND003_OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_B    0x7F    // 1Dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX208 0x208 // USB2 Option RX208
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_B    0xFFFF0000  // DACh/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_B
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_B    0xFFFF      // 1B58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX20C 0x20C // USB2 Option RX20C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FS_B    0xFFF0000   // 2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_B
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_LS_B    0xFFF       // F50h/f50h/x/x REG_NPTT_BUFA_TIMEOK_LS_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX210 0x210 // USB2 Option RX210
    #define CND003_OPTCFGHSBI_REG_PTT_FULL_DELAY_B 0x7FF0000   // 90h/90h/x/x REG_PTT_FULL_DELAY_B
    #define CND003_OPTCFGHSBI_REG_PTT_LOW_DELAY_B  0x7FF       // 44Ch/44ch/x/x REG_PTT_LOW_DELAY_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX214 0x214 // USB2 Option RX214
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF2_B   0x1FFF0000              // 7h/7h/x/x REG_FR_HIGH_EOF2_B
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF1_B   0x1FFF                  // 45h/45h/x/x REG_FR_HIGH_EOF1_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX218 0x218 // USB2 Option RX218
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF2_B   0xFFFF0000  // 31h/31h/x/x REG_FR_FULL_EOF2_B
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF1_B   0xFFFF      // 9Fh/9fh/x/x REG_FR_FULL_EOF1_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX21C 0x21C // USB2 Option RX21C
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_INIT_B   0x1FFF0000              // 1D4Ch/1d4ch/x/X REG_FR_HIGH_INIT_B
    #define CND003_OPTCFGHSBI_REG_FR_FULL_INIT_B   0xFFFF                  // EA60h/ea60h/x/x REG_FR_FULL_INIT_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX220 0x220 // USB2 Option RX220
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_OVFL_B   0x1FFF                  // 1D57h/1d57h/x/x REG_FR_HIGH_OVFL_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX222 0x222 // USB2 Option RX222
    #define CND003_OPTCFGHSBI_REG_EOP_FLAG_B               BIT6    // 1b/1b/x/x REG_EOP_FLAG_B
    #define CND003_OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_B  BIT5    // 1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_B
    #define CND003_OPTCFGHSBI_REG_PAMP_TX_EN_B             BIT4    // 0/0/x/x REG_PAMP_TX_EN_B
    #define CND003_OPTCFGHSBI_REG_SUSPEND_PROPAGATION_B    BIT3    // 0/0/x/x REG_SUSPEND_PROPAGATION_B
    #define CND003_OPTCFGHSBI_REG_DNCOLL_EOP_SEL_B         BIT2    // 0/0/x/x REG_DNCOLL_EOP_SEL_B
    #define CND003_OPTCFGHSBI_REG_TT_COLL_DET_DIS_B        BIT1    // 1b/1b/x/x REG_TT_COLL_DET_DIS_B
    #define CND003_OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_B      BIT0    // 0/0/x/x REG_DN_LPM_MANUAL_EOR_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX223 0x223 // USB2 Option RX223
    #define CND003_OPTCFGHSBI_REG_DN_EOI_EOR1_B CND003_OPTCFGHSBI_USB2_OPTION_RX223 // 64h/64h/x/x REG_DN_EOI_EOR1_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX224 0x224 // USB2 Option RX224
    #define CND003_OPTCFGHSBI_REG_DN_SUSDISABLE_B      BIT7    // 1b/1b/x/x REG_DN_SUSDISABLE_B
    #define CND003_OPTCFGHSBI_REG_EOF1_EOF2_B          BIT6    // 1b/1b/x/x REG_EOF1_EOF2_B
    #define CND003_OPTCFGHSBI_FS_LPBK_B                BIT5    // 0/0/x/x FS_LPBK_B
    #define CND003_OPTCFGHSBI_REG_DN_PORT_ERR_CHK_B    BIT4    // 0/0/x/x REG_DN_PORT_ERR_CHK_B
    #define CND003_OPTCFGHSBI_REG_DN_PDPHYDIS_B        BIT3    // 0/0/x/x REG_DN_PDPHYDIS_B
    #define CND003_OPTCFGHSBI_REG_DN_FORCEHSMOD_B      BIT2    // 0/0/x/x REG_DN_FORCEHSMOD_B
    #define CND003_OPTCFGHSBI_REG_DN_NOCHIRP_B         BIT1    // 0/0/x/x REG_DN_NOCHIRP_B
    #define CND003_OPTCFGHSBI_REG_DN_POWER_LOST_B      BIT0    // 1b/1b/x/x REG_DN_POWER_LOST_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX225 0x225 // USB2 Option RX225
    #define CND003_OPTCFGHSBI_REG_PDHSTRSE0_B                  BIT7    // 1b/1b/x/x REG_PDHSTRSE0_B
    #define CND003_OPTCFGHSBI_REG_STRICT_EOP_EN_B              BIT6    // 1b/1b/x/x REG_STRICT_EOP_EN_B
    #define CND003_OPTCFGHSBI_REG_DN_L1_EN_B                   BIT5    // 1b/1b/x/x REG_DN_L1_EN_B
    #define CND003_OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_B   BIT4    // 0/0/x/x REG_LONG_LOW_SPEED_DETECTION_B
    #define CND003_OPTCFGHSBI_REG_SE1_CONN_DIS_B               BIT3    // 1b/1b/x/x REG_SE1_CONN_DIS_B
    #define CND003_OPTCFGHSBI_REG_DBG104EN_B                   BIT2    // 0/0/x/x REG_DBG104EN_B
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_POWER_B           BIT1    // 0/0/x/x REG_DISCONNECT_POWER_B
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_OPTION_B          BIT0    // 1b/1b/x/x REG_DISCONNECT_OPTION_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX226 0x226 // USB2 Option RX226
    #define CND003_OPTCFGHSBI_REG_FS_EOPVAL_B  0xF0    // 3h/3h/x/x REG_FS_EOPVAL_B
    #define CND003_OPTCFGHSBI_REG_LS_EOPVAL_B  0xF     // 8h/8h/x/x REG_LS_EOPVAL_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX227 0x227 // USB2 Option RX227
    #define CND003_OPTCFGHSBI_REG_LONG_BUS_IDLE_B          BIT7    // 1b/1b/x/x REG_LONG_BUS_IDLE_B
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_B    BIT6    // 0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_B
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_B      BIT5    // 1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_B
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_B      BIT4    // 1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_B
    #define CND003_OPTCFGHSBI_REG_RXRESET_DIS_B            BIT3    // 0/0/x/x REG_RXRESET_DIS_B
    #define CND003_OPTCFGHSBI_PDSUSMOD_FW_B                BIT2    // 0/0/x/x PDSUSMOD_FW_B
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_B             BIT1    // 0/0/x/x REG_DISCVLD_FW_B
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_OPT_B         BIT0    // 0/0/x/x REG_DISCVLD_FW_OPT_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX228 0x228 // USB2 Option RX228
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_B            (BIT6 + BIT7)   // 0/0/x/x REG_DCP_DEBOUNCE_UP_B
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_B               (BIT4 + BIT5)   // 01b/01b/x/x REG_DCP_DEBOUNCE_B
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_B    BIT3            // 0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_B
    #define CND003_OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_B   BIT2            // 0/0/x/x REG_EXTEND_CDP_FLAG_DEBOUNCE_B
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLR_B              BIT1            // 0/0/x/x REG_CDPFLAG_FWCLR_B
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_B          BIT0            // 0/0/x/x REG_CDPFLAG_FWCLRONLY_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX229 0x229 // USB2 Option RX229
    #define CND003_OPTCFGHSBI_REG_DN_RWU_EN_B  BIT1    // 1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port B
    #define CND003_OPTCFGHSBI_REG_POWER_ON_B   BIT0    // 0/0/x/x REG_POWER_ON_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX22A 0x22A // USB2 Option RX22A
    #define CND003_OPTCFGHSBI_USB2P2_TMOUT_4MS_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX22A // 1Fh/1Fh/x/x USB2P2_TMOUT_4MS_PARM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX300 0x300 // USB2 Option RX300
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_C     0xF0    // 1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_C   0xF     // 6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX301 0x301 // USB2 Option RX301
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_C CND003_OPTCFGHSBI_USB2_OPTION_RX301 // 5Ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX302 0x302 // USB2 Option RX302
    #define CND003_OPTCFGHSBI_REG_RXCPLOPT_C                   BIT7    // 1b/1b/x/x REG_RXCPLOPT_C
    #define CND003_OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_C   BIT6    // 1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_C
    #define CND003_OPTCFGHSBI_REG_L1_EN_C                      BIT5    // 0/0/x/x REG_L1_EN_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_C        BIT4    // 0/0/x/x REG_UP_SIE_HC_SYNC_JEND_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_C        BIT3    // 0/0/x/x REG_UP_SIE_HC_SYNC_FAST_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_C     BIT2    // 0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_C        BIT1    // 0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_C     BIT0    // 1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX303 0x303 // USB2 Option RX303
    #define CND003_OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_C CND003_OPTCFGHSBI_USB2_OPTION_RX303 // 24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX304 0x304 // USB2 Option RX304
    #define CND003_OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_C  0xF0    // 6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_C
    #define CND003_OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_C    0xF     // 1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX305 0x305 // USB2 Option RX305
    #define CND003_OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_C   BIT7    // 1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RCTB_DIR_C              BIT6    // 0/0/x/x REG_NPTT_RCTB_DIR_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKHSH_C               BIT5    // 1b/1b/x/x REG_NPTT_RCHKHSH_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_EN_C            BIT4    // 1b/1b/x/x REG_NPTT_RRACKTM_EN_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RCONTFST_C              BIT3    // 1b/1b/x/x REG_NPTT_RCONTFST_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKDATAPID_C           BIT2    // 0/0/x/x REG_NPTT_RCHKDATAPID_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RMATCH_ALL_C            BIT1    // 1b/1b/x/x REG_NPTT_RMATCH_ALL_C
    #define CND003_OPTCFGHSBI_REG_EOF_RST_TX_C                 BIT0    // 0/0/x/x REG_EOF_RST_TX_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX306 0x306 // USB2 Option RX306
    #define CND003_OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_C      BIT4                    // 1b/1b/x/x REG_UPRX_STOP_TT_GATE_C
    #define CND003_OPTCFGHSBI_REG_PTT_SEARCH_LEN_C         (BIT2 + BIT3)           // 0/0/x/x REG_PTT_SEARCH_LEN_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_C      BIT1                    // 1b/1b/x/x REG_NPTT_RRACKTM_FWEN_C
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_C  BIT0                    // 1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX307 0x307 // USB2 Option RX307
    #define CND003_OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_C    0x7F    // 1dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX308 0x308 // USB2 Option RX308
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_C    0xFFFF0000  // dach/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_C
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_C    0xFFFF      // 1b58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX30C 0x30C // USB2 Option RX30C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FS_C    0xFFF0000   // 2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_LS_C    0xFFF       // F50h/f50h/x/x REG_NPTT_BUFA_TIMEOK_LS_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX310 0x310 // USB2 Option RX310
    #define CND003_OPTCFGHSBI_REG_PTT_FULL_DELAY_C 0x7FF0000   // 90h/90h/x/x REG_PTT_FULL_DELAY_C
    #define CND003_OPTCFGHSBI_REG_PTT_LOW_DELAY_C  0x7FF       // 44Ch/44ch/x/x REG_PTT_LOW_DELAY_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX314 0x314 // USB2 Option RX314
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF2_C   0x1FFF0000              // 7h/7h/x/x REG_FR_HIGH_EOF2_C
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF1_C   0x1FFF                  // 45h/45h/x/x REG_FR_HIGH_EOF1_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX318 0x318 // USB2 Option RX318
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF2_C   0xFFFF0000  // 31h/31h/x/x REG_FR_FULL_EOF2_C
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF1_C   0xFFFF      // 9Fh/9fh/x/x REG_FR_FULL_EOF1_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX31C 0x31C // USB2 Option RX31C
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_INIT_C   0x1FFF0000              // 1D4Ch/1d4ch/x/x REG_FR_HIGH_INIT_C
    #define CND003_OPTCFGHSBI_REG_FR_FULL_INIT_C   0xFFFF                  // EA60h/ea60h/x/x REG_FR_FULL_INIT_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX320 0x320 // USB2 Option RX320
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_OVFL_C   0x1FFF                  // 1D57h/1d57h/x/x REG_FR_HIGH_OVFL_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX322 0x322 // USB2 Option RX322
    #define CND003_OPTCFGHSBI_REG_EOP_FLAG_C               BIT6    // 1b/1b/x/x REG_EOP_FLAG_C
    #define CND003_OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_C  BIT5    // 1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_C
    #define CND003_OPTCFGHSBI_REG_PAMP_TX_EN_C             BIT4    // 0/0/x/x REG_PAMP_TX_EN_C
    #define CND003_OPTCFGHSBI_REG_SUSPEND_PROPAGATION_C    BIT3    // 0/0/x/x REG_SUSPEND_PROPAGATION_C
    #define CND003_OPTCFGHSBI_REG_DNCOLL_EOP_SEL_C         BIT2    // 0/0/x/x REG_DNCOLL_EOP_SEL_C
    #define CND003_OPTCFGHSBI_REG_TT_COLL_DET_DIS_C        BIT1    // 1b/1b/x/x REG_TT_COLL_DET_DIS_C
    #define CND003_OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_C      BIT0    // 0/0/x/x REG_DN_LPM_MANUAL_EOR_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX323 0x323 // USB2 Option RX323
    #define CND003_OPTCFGHSBI_REG_DN_EOI_EOR1_C CND003_OPTCFGHSBI_USB2_OPTION_RX323 // 64h/64h/x/x REG_DN_EOI_EOR1_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX324 0x324 // USB2 Option RX324
    #define CND003_OPTCFGHSBI_REG_DN_SUSDISABLE_C      BIT7    // 1b/1b/x/x REG_DN_SUSDISABLE_C
    #define CND003_OPTCFGHSBI_REG_EOF1_EOF2_C          BIT6    // 1b/1b/x/x REG_EOF1_EOF2_C
    #define CND003_OPTCFGHSBI_FS_LPBK_C                BIT5    // 0/0/x/x FS_LPBK_C
    #define CND003_OPTCFGHSBI_REG_DN_PORT_ERR_CHK_C    BIT4    // 0/0/x/x REG_DN_PORT_ERR_CHK_C
    #define CND003_OPTCFGHSBI_REG_DN_PDPHYDIS_C        BIT3    // 0/0/x/x REG_DN_PDPHYDIS_C
    #define CND003_OPTCFGHSBI_REG_DN_FORCEHSMOD_C      BIT2    // 0/0/x/x REG_DN_FORCEHSMOD_C
    #define CND003_OPTCFGHSBI_REG_DN_NOCHIRP_C         BIT1    // 0/0/x/x REG_DN_NOCHIRP_C
    #define CND003_OPTCFGHSBI_REG_DN_POWER_LOST_C      BIT0    // 1b/1b/x/x REG_DN_POWER_LOST_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX325 0x325 // USB2 Option RX325
    #define CND003_OPTCFGHSBI_REG_PDHSTRSE0_C                  BIT7    // 1b/1b/x/x REG_PDHSTRSE0_C
    #define CND003_OPTCFGHSBI_REG_STRICT_EOP_EN_C              BIT6    // 1b/1b/x/x REG_STRICT_EOP_EN_C
    #define CND003_OPTCFGHSBI_REG_DN_L1_EN_C                   BIT5    // 1b/1b/x/x REG_DN_L1_EN_C
    #define CND003_OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_C   BIT4    // 0/0/x/x REG_LONG_LOW_SPEED_DETECTION_C
    #define CND003_OPTCFGHSBI_REG_SE1_CONN_DIS_C               BIT3    // 1b/1b/x/x REG_SE1_CONN_DIS_C
    #define CND003_OPTCFGHSBI_REG_DBG104EN_C                   BIT2    // 0/0/x/x REG_DBG104EN_C
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_POWER_C           BIT1    // 0/0/x/x REG_DISCONNECT_POWER_C
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_OPTION_C          BIT0    // 1b/1b/x/x REG_DISCONNECT_OPTION_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX326 0x326 // USB2 Option RX326
    #define CND003_OPTCFGHSBI_REG_FS_EOPVAL_C  0xF0    // 3h/3h/x/x REG_FS_EOPVAL_C
    #define CND003_OPTCFGHSBI_REG_LS_EOPVAL_C  0xF     // 8h/8h/x/x REG_LS_EOPVAL_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX327 0x327 // USB2 Option RX327
    #define CND003_OPTCFGHSBI_REG_LONG_BUS_IDLE_C          BIT7    // 1b/1b/x/x REG_LONG_BUS_IDLE_C
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_C    BIT6    // 0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_C
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_C      BIT5    // 1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_C
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_C      BIT4    // 1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_C
    #define CND003_OPTCFGHSBI_REG_RXRESET_DIS_C            BIT3    // 0/0/x/x REG_RXRESET_DIS_C
    #define CND003_OPTCFGHSBI_PDSUSMOD_FW_C                BIT2    // 0/0/x/x PDSUSMOD_FW_C
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_C             BIT1    // 0/0/x/x REG_DISCVLD_FW_C
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_OPT_C         BIT0    // 0/0/x/x REG_DISCVLD_FW_OPT_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX328 0x328 // USB2 Option RX328
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_C            (BIT6 + BIT7)   // 0/0/x/x REG_DCP_DEBOUNCE_UP_C
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_C               (BIT4 + BIT5)   // 01b/01b/x/x REG_DCP_DEBOUNCE_C
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_C    BIT3            // 0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_C
    #define CND003_OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_C   BIT2            // 0/0/x/x REG_EXTEND_CDP_FLAG_DEBOUNCE_C
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLR_C              BIT1            // 0/0/x/x REG_CDPFLAG_FWCLR_C
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_C          BIT0            // 0/0/x/x REG_CDPFLAG_FWCLRONLY_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX329 0x329 // USB2 Option RX329
    #define CND003_OPTCFGHSBI_REG_DN_RWU_EN_C  BIT1    // 1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port C
    #define CND003_OPTCFGHSBI_REG_POWER_ON_C   BIT0    // 0/0/x/x REG_POWER_ON_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX32A 0x32A // USB2 Option RX32A
    #define CND003_OPTCFGHSBI_USB2P3_TMOUT_4MS_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX32A // 1Fh/FFh/x/x USB2P3_TMOUT_4MS_PARM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX400 0x400 // USB2 Option RX400
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_D     0xF0    // 1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_D   0xF     // 6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX401 0x401 // USB2 Option RX401
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_D CND003_OPTCFGHSBI_USB2_OPTION_RX401 // 5Ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX402 0x402 // USB2 Option RX402
    #define CND003_OPTCFGHSBI_REG_RXCPLOPT_D                   BIT7    // 1b/1b/x/x REG_RXCPLOPT_D
    #define CND003_OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_D   BIT6    // 1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_D
    #define CND003_OPTCFGHSBI_REG_L1_EN_D                      BIT5    // 0/0/x/x REG_L1_EN_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_D        BIT4    // 0/0/x/x REG_UP_SIE_HC_SYNC_JEND_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_D        BIT3    // 0/0/x/x REG_UP_SIE_HC_SYNC_FAST_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_D     BIT2    // 0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_D        BIT1    // 0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_D     BIT0    // 1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX403 0x403 // USB2 Option RX403
    #define CND003_OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_D CND003_OPTCFGHSBI_USB2_OPTION_RX403 // 24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX404 0x404 // USB2 Option RX404
    #define CND003_OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_D  0xF0    // 6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_D
    #define CND003_OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_D    0xF     // 1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX405 0x405 // USB2 Option RX405
    #define CND003_OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_D   BIT7    // 1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RCTB_DIR_D              BIT6    // 0/0/x/x REG_NPTT_RCTB_DIR_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKHSH_D               BIT5    // 1b/1b/x/x REG_NPTT_RCHKHSH_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_EN_D            BIT4    // 1b/1b/x/x REG_NPTT_RRACKTM_EN_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RCONTFST_D              BIT3    // 1b/1b/x/x REG_NPTT_RCONTFST_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKDATAPID_D           BIT2    // 0/0/x/x REG_NPTT_RCHKDATAPID_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RMATCH_ALL_D            BIT1    // 1b/1b/x/x REG_NPTT_RMATCH_ALL_D
    #define CND003_OPTCFGHSBI_REG_EOF_RST_TX_D                 BIT0    // 0/0/x/x REG_EOF_RST_TX_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX406 0x406 // USB2 Option RX406
    #define CND003_OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_D      BIT4                    // 1b/1b/x/x REG_UPRX_STOP_TT_GATE_D
    #define CND003_OPTCFGHSBI_REG_PTT_SEARCH_LEN_D         (BIT2 + BIT3)           // 0/0/x/x REG_PTT_SEARCH_LEN_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_D      BIT1                    // 1b/1b/x/x REG_NPTT_RRACKTM_FWEN_D
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_D  BIT0                    // 1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX407 0x407 // USB2 Option RX407
    #define CND003_OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_D    0x7F    // 1Dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX408 0x408 // USB2 Option RX408
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_D    0xFFFF0000  // DACh/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_D
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_D    0xFFFF      // 1B58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX40C 0x40C // USB2 Option RX40C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FS_D    0xFFF0000   // 2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_D
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_LS_D    0xFFF       // F50h/f50h/x/x REG_NPTT_BUFA_TIMEOK_LS_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX410 0x410 // USB2 Option RX410
    #define CND003_OPTCFGHSBI_REG_PTT_FULL_DELAY_D 0x7FF0000   // 90h/90h/x/x REG_PTT_FULL_DELAY_D
    #define CND003_OPTCFGHSBI_REG_PTT_LOW_DELAY_D  0x7FF       // 44Ch/44ch/x/x REG_PTT_LOW_DELAY_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX414 0x414 // USB2 Option RX414
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF2_D   0x1FFF0000              // 7h/7h/x/x REG_FR_HIGH_EOF2_D
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF1_D   0x1FFF                  // 45h/45h/x/x REG_FR_HIGH_EOF1_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX418 0x418 // USB2 Option RX418
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF2_D   0xFFFF0000  // 31h/31h/x/x REG_FR_FULL_EOF2_D
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF1_D   0xFFFF      // 9Fh/9fh/x/x REG_FR_FULL_EOF1_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX41C 0x41C // USB2 Option RX41C
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_INIT_D   0x1FFF0000              // 1D4Ch/1d4ch/x/x REG_FR_HIGH_INIT_D
    #define CND003_OPTCFGHSBI_REG_FR_FULL_INIT_D   0xFFFF                  // EA60h/ea60h/x/x REG_FR_FULL_INIT_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX420 0x420 // USB2 Option RX420
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_OVFL_D   0x1FFF                  // 1D57h/1d57h/x/x REG_FR_HIGH_OVFL_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX422 0x422 // USB2 Option RX422
    #define CND003_OPTCFGHSBI_REG_EOP_FLAG_D               BIT6    // 1b/1b/x/x REG_EOP_FLAG_D
    #define CND003_OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_D  BIT5    // 1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_D
    #define CND003_OPTCFGHSBI_REG_PAMP_TX_EN_D             BIT4    // 0/0/x/x REG_PAMP_TX_EN_D
    #define CND003_OPTCFGHSBI_REG_SUSPEND_PROPAGATION_D    BIT3    // 0/0/x/x REG_SUSPEND_PROPAGATION_D
    #define CND003_OPTCFGHSBI_REG_DNCOLL_EOP_SEL_D         BIT2    // 0/0/x/x REG_DNCOLL_EOP_SEL_D
    #define CND003_OPTCFGHSBI_REG_TT_COLL_DET_DIS_D        BIT1    // 1b/1b/x/x REG_TT_COLL_DET_DIS_D
    #define CND003_OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_D      BIT0    // 0/0/x/x REG_DN_LPM_MANUAL_EOR_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX423 0x423 // USB2 Option RX423
    #define CND003_OPTCFGHSBI_REG_DN_EOI_EOR1_D CND003_OPTCFGHSBI_USB2_OPTION_RX423 // 64h/64h/x/x REG_DN_EOI_EOR1_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX424 0x424 // USB2 Option RX424
    #define CND003_OPTCFGHSBI_REG_DN_SUSDISABLE_D      BIT7    // 1b/1b/x/x REG_DN_SUSDISABLE_D
    #define CND003_OPTCFGHSBI_REG_EOF1_EOF2_D          BIT6    // 1b/1b/x/x REG_EOF1_EOF2_D
    #define CND003_OPTCFGHSBI_FS_LPBK_D                BIT5    // 0/0/x/x FS_LPBK_D
    #define CND003_OPTCFGHSBI_REG_DN_PORT_ERR_CHK_D    BIT4    // 0/0/x/x REG_DN_PORT_ERR_CHK_D
    #define CND003_OPTCFGHSBI_REG_DN_PDPHYDIS_D        BIT3    // 0/0/x/x REG_DN_PDPHYDIS_D
    #define CND003_OPTCFGHSBI_REG_DN_FORCEHSMOD_D      BIT2    // 0/0/x/x REG_DN_FORCEHSMOD_D
    #define CND003_OPTCFGHSBI_REG_DN_NOCHIRP_D         BIT1    // 0/0/x/x REG_DN_NOCHIRP_D
    #define CND003_OPTCFGHSBI_REG_DN_POWER_LOST_D      BIT0    // 1b/1b/x/x REG_DN_POWER_LOST_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX425 0x425 // USB2 Option RX425
    #define CND003_OPTCFGHSBI_REG_PDHSTRSE0_D                  BIT7    // 1b/1b/x/x REG_PDHSTRSE0_D
    #define CND003_OPTCFGHSBI_REG_STRICT_EOP_EN_D              BIT6    // 1b/1b/x/x REG_STRICT_EOP_EN_D
    #define CND003_OPTCFGHSBI_REG_DN_L1_EN_D                   BIT5    // 1b/1b/x/x REG_DN_L1_EN_D
    #define CND003_OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_D   BIT4    // 0/0/x/x REG_LONG_LOW_SPEED_DETECTION_D
    #define CND003_OPTCFGHSBI_REG_SE1_CONN_DIS_D               BIT3    // 1b/1b/x/x REG_SE1_CONN_DIS_D
    #define CND003_OPTCFGHSBI_REG_DBG104EN_D                   BIT2    // 0/0/x/x REG_DBG104EN_D
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_POWER_D           BIT1    // 0/0/x/x REG_DISCONNECT_POWER_D
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_OPTION_D          BIT0    // 1b/1b/x/x REG_DISCONNECT_OPTION_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX426 0x426 // USB2 Option RX426
    #define CND003_OPTCFGHSBI_REG_FS_EOPVAL_D  0xF0    // 3h/3h/x/x REG_FS_EOPVAL_D
    #define CND003_OPTCFGHSBI_REG_LS_EOPVAL_D  0xF     // 8h/8h/x/x REG_LS_EOPVAL_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX427 0x427 // USB2 Option RX427
    #define CND003_OPTCFGHSBI_REG_LONG_BUS_IDLE_D          BIT7    // 1b/1b/x/x REG_LONG_BUS_IDLE_D
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_D    BIT6    // 0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_D
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_D      BIT5    // 1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_D
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_D      BIT4    // 1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_D
    #define CND003_OPTCFGHSBI_REG_RXRESET_DIS_D            BIT3    // 0/0/x/x REG_RXRESET_DIS_D
    #define CND003_OPTCFGHSBI_PDSUSMOD_FW_D                BIT2    // 0/0/x/x PDSUSMOD_FW_D
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_D             BIT1    // 0/0/x/x REG_DISCVLD_FW_D
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_OPT_D         BIT0    // 0/0/x/x REG_DISCVLD_FW_OPT_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX428 0x428 // USB2 Option RX428
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_D            (BIT6 + BIT7)   // 0/0/x/x REG_DCP_DEBOUNCE_UP_D
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_D               (BIT4 + BIT5)   // 01b/01b/x/x REG_DCP_DEBOUNCE_D
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_D    BIT3            // 0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_D
    #define CND003_OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_D   BIT2            // 0/0/x/x REG_EXTEND_CDP_FLAG_DEBOUNCE_D
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLR_D              BIT1            // 0/0/x/x REG_CDPFLAG_FWCLR_D
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_D          BIT0            // 0/0/x/x REG_CDPFLAG_FWCLRONLY_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX429 0x429 // USB2 Option RX429
    #define CND003_OPTCFGHSBI_REG_DN_RWU_EN_D  BIT1    // 1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port D
    #define CND003_OPTCFGHSBI_REG_POWER_ON_D   BIT0    // 0/0/x/x REG_POWER_ON_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX42A 0x42A // USB2 Option RX42A
    #define CND003_OPTCFGHSBI_USB2P4_TMOUT_4MS_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX42A // 1Fh/1Fh/x/x USB2P4_TMOUT_4MS_PARM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX500 0x500 // USB2 Option RX500
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_RXENDLY_PARM_E     0xF0    // 1h/1h/x/x REG_UP_SIE_HC_RXENDLY_PARM_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TXRXENDLY_PARM_E   0xF     // 6h/6h/x/x REG_UP_SIE_HC_TXRXENDLY_PARM_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX501 0x501 // USB2 Option RX501
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_HS_TMOUT_PARM_E CND003_OPTCFGHSBI_USB2_OPTION_RX501 // 5ah/5ah/x/x REG_UP_SIE_HC_HS_TMOUT_PARM_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX502 0x502 // USB2 Option RX502
    #define CND003_OPTCFGHSBI_REG_RXCPLOPT_E                   BIT7    // 1b/1b/x/x REG_RXCPLOPT_E
    #define CND003_OPTCFGHSBI_REG_CTRL_ENP_PING_SUPPORT_EN_E   BIT6    // 1b/1b/x/x REG_CTRL_ENP_PING_SUPPORT_EN_E
    #define CND003_OPTCFGHSBI_REG_L1_EN_E                      BIT5    // 0/0/x/x REG_L1_EN_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_JEND_E        BIT4    // 0/0/x/x REG_UP_SIE_HC_SYNC_JEND_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SYNC_FAST_E        BIT3    // 0/0/x/x REG_UP_SIE_HC_SYNC_FAST_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_TKNCRCHK_DIS_E     BIT2    // 0/0/x/x REG_UP_SIE_HC_TKNCRCHK_DIS_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_CRCHK_DIS_E        BIT1    // 0/0/x/x REG_UP_SIE_HC_CRCHK_DIS_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_EN_CHKTOGCRC_E     BIT0    // 1b/1b/x/x REG_UP_SIE_HC_EN_CHKTOGCRC_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX503 0x503 // USB2 Option RX503
    #define CND003_OPTCFGHSBI_REG_LPM_HC_FS_TMOUT_PARM_E CND003_OPTCFGHSBI_USB2_OPTION_RX503 // 24h/24h/x/x REG_LPM_HC_FS_TMOUT_PARM_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX504 0x504 // USB2 Option RX504
    #define CND003_OPTCFGHSBI_REG_LPM_HC_TXRXENDLY_PARM_E  0xF0    // 6h/6h/x/x REG_LPM_HC_TXRXENDLY_PARM_E
    #define CND003_OPTCFGHSBI_REG_LPM_HC_RXENDLY_PARM_E    0xF     // 1h/1h/x/x REG_LPM_HC_RXENDLY_PARM_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX505 0x505 // USB2 Option RX505
    #define CND003_OPTCFGHSBI_REG_NPTT_DONT_RTY_IF_NO_TIME_E   BIT7    // 1b/1b/x/x REG_NPTT_DONT_RTY_IF_NO_TIME_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RCTB_DIR_E              BIT6    // 0/0/x/x REG_NPTT_RCTB_DIR_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKHSH_E               BIT5    // 1b/1b/x/x REG_NPTT_RCHKHSH_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_EN_E            BIT4    // 1b/1b/x/x REG_NPTT_RRACKTM_EN_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RCONTFST_E              BIT3    // 1b/1b/x/x REG_NPTT_RCONTFST_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RCHKDATAPID_E           BIT2    // 0/0/x/x REG_NPTT_RCHKDATAPID_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RMATCH_ALL_E            BIT1    // 1b/1b/x/x REG_NPTT_RMATCH_ALL_E
    #define CND003_OPTCFGHSBI_REG_EOF_RST_TX_E                 BIT0    // 0/0/x/x REG_EOF_RST_TX_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX506 0x506 // USB2 Option RX506
    #define CND003_OPTCFGHSBI_REG_UPRX_STOP_TT_GATE_E      BIT4                    // 1b/1b/x/x REG_UPRX_STOP_TT_GATE_E
    #define CND003_OPTCFGHSBI_REG_PTT_SEARCH_LEN_E         (BIT2 + BIT3)           // 0/0/x/x REG_PTT_SEARCH_LEN_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FWEN_E      BIT1                    // 1b/1b/x/x REG_NPTT_RRACKTM_FWEN_E
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FWEN_E  BIT0                    // 1b/1b/x/x REG_NPTT_BUFA_TIMEOK_FWEN_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX507 0x507 // USB2 Option RX507
    #define CND003_OPTCFGHSBI_REG_UPRX_INTER_PACKET_DELAY_E    0x7F    // 1Dh/1dh/x/x REG_UPRX_INTER_PACKET_DELAY_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX508 0x508 // USB2 Option RX508
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_FS_E    0xFFFF0000  // DACh/dach/x/x REG_NPTT_BUFA_TIMEOK_FS_E
    #define CND003_OPTCFGHSBI_REG_NPTT_BUFA_TIMEOK_LS_E    0xFFFF      // 1B58h/1b58h/x/x REG_NPTT_BUFA_TIMEOK_LS_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX50C 0x50C // USB2 Option RX50C
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_FS_E    0xFFF0000   // 2FFh/2ffh/x/x REG_NPTT_RRACKTM_FS_E
    #define CND003_OPTCFGHSBI_REG_NPTT_RRACKTM_LS_E    0xFFF       // F50h/f50h/x/x REG_NPTT_BUFA_TIMEOK_LS_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX510 0x510 // USB2 Option RX510
    #define CND003_OPTCFGHSBI_REG_PTT_FULL_DELAY_E 0x7FF0000   // 90h/90h/x/x REG_PTT_FULL_DELAY_E
    #define CND003_OPTCFGHSBI_REG_PTT_LOW_DELAY_E  0x7FF       // 44Ch/44ch/x/x REG_PTT_LOW_DELAY_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX514 0x514 // USB2 Option RX514
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF2_E   0x1FFF0000              // 7h/7h/x/x REG_FR_HIGH_EOF2_E
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_EOF1_E   0x1FFF                  // 45h/45h/x/x REG_FR_HIGH_EOF1_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX518 0x518 // USB2 Option RX518
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF2_E   0xFFFF0000  // 31h/31h/x/x REG_FR_FULL_EOF2_E
    #define CND003_OPTCFGHSBI_REG_FR_FULL_EOF1_E   0xFFFF      // 9Fh/9fh/x/x REG_FR_FULL_EOF1_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX51C 0x51C // USB2 Option RX51C
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_INIT_E   0x1FFF0000              // 1D4Ch/1d4ch/x/x REG_FR_HIGH_INIT_E
    #define CND003_OPTCFGHSBI_REG_FR_FULL_INIT_E   0xFFFF                  // EA60h/ea60h/x/x REG_FR_FULL_INIT_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX520 0x520 // USB2 Option RX520
    #define CND003_OPTCFGHSBI_REG_FR_HIGH_OVFL_E   0x1FFF                  // 1D57h/1d57h/x/x REG_FR_HIGH_OVFL_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX522 0x522 // USB2 Option RX522
    #define CND003_OPTCFGHSBI_REG_EOP_FLAG_E               BIT6    // 1b/1b/x/x REG_EOP_FLAG_E
    #define CND003_OPTCFGHSBI_REG_DSCNNT_DET_ONLY_IN_TX_E  BIT5    // 1b/1b/x/x REG_DSCNNT_DET_ONLY_IN_TX_E
    #define CND003_OPTCFGHSBI_REG_PAMP_TX_EN_E             BIT4    // 0/0/x/x REG_PAMP_TX_EN_E
    #define CND003_OPTCFGHSBI_REG_SUSPEND_PROPAGATION_E    BIT3    // 0/0/x/x REG_SUSPEND_PROPAGATION_E
    #define CND003_OPTCFGHSBI_REG_DNCOLL_EOP_SEL_E         BIT2    // 0/0/x/x REG_DNCOLL_EOP_SEL_E
    #define CND003_OPTCFGHSBI_REG_TT_COLL_DET_DIS_E        BIT1    // 1b/1b/x/x REG_TT_COLL_DET_DIS_E
    #define CND003_OPTCFGHSBI_REG_DN_LPM_MANUAL_EOR_E      BIT0    // 0/0/x/x REG_DN_LPM_MANUAL_EOR_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX523 0x523 // USB2 Option RX523
    #define CND003_OPTCFGHSBI_REG_DN_EOI_EOR1_E CND003_OPTCFGHSBI_USB2_OPTION_RX523 // 64h/64h/x/x REG_DN_EOI_EOR1_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX524 0x524 // USB2 Option RX524
    #define CND003_OPTCFGHSBI_REG_DN_SUSDISABLE_E      BIT7    // 1b/1b/x/x REG_DN_SUSDISABLE_E
    #define CND003_OPTCFGHSBI_REG_EOF1_EOF2_E          BIT6    // 1b/1b/x/x REG_EOF1_EOF2_E
    #define CND003_OPTCFGHSBI_FS_LPBK_E                BIT5    // 0/0/x/x FS_LPBK_E
    #define CND003_OPTCFGHSBI_REG_DN_PORT_ERR_CHK_E    BIT4    // 0/0/x/x REG_DN_PORT_ERR_CHK_E
    #define CND003_OPTCFGHSBI_REG_DN_PDPHYDIS_E        BIT3    // 0/0/x/x REG_DN_PDPHYDIS_E
    #define CND003_OPTCFGHSBI_REG_DN_FORCEHSMOD_E      BIT2    // 0/0/x/x REG_DN_FORCEHSMOD_E
    #define CND003_OPTCFGHSBI_REG_DN_NOCHIRP_E         BIT1    // 0/0/x/x REG_DN_NOCHIRP_E
    #define CND003_OPTCFGHSBI_REG_DN_POWER_LOST_E      BIT0    // 1b/1b/x/x REG_DN_POWER_LOST_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX525 0x525 // USB2 Option RX525
    #define CND003_OPTCFGHSBI_REG_PDHSTRSE0_E                  BIT7    // 1b/1b/x/x REG_PDHSTRSE0_E
    #define CND003_OPTCFGHSBI_REG_STRICT_EOP_EN_E              BIT6    // 1b/1b/x/x REG_STRICT_EOP_EN_E
    #define CND003_OPTCFGHSBI_REG_DN_L1_EN_E                   BIT5    // 1b/1b/x/x REG_DN_L1_EN_E
    #define CND003_OPTCFGHSBI_REG_LONG_LOW_SPEED_DETECTION_E   BIT4    // 0/0/x/x REG_LONG_LOW_SPEED_DETECTION_E
    #define CND003_OPTCFGHSBI_REG_SE1_CONN_DIS_E               BIT3    // 1b/1b/x/x REG_SE1_CONN_DIS_E
    #define CND003_OPTCFGHSBI_REG_DBG104EN_E                   BIT2    // 0/0/x/x REG_DBG104EN_E
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_POWER_E           BIT1    // 0/0/x/x REG_DISCONNECT_POWER_E
    #define CND003_OPTCFGHSBI_REG_DISCONNECT_OPTION_E          BIT0    // 1b/1b/x/x REG_DISCONNECT_OPTION_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX526 0x526 // USB2 Option RX526
    #define CND003_OPTCFGHSBI_REG_FS_EOPVAL_E  0xF0    // 3h/3h/x/x REG_FS_EOPVAL_E
    #define CND003_OPTCFGHSBI_REG_LS_EOPVAL_E  0xF     // 8h/8h/x/x REG_LS_EOPVAL_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX527 0x527 // USB2 Option RX527
    #define CND003_OPTCFGHSBI_REG_LONG_BUS_IDLE_E          BIT7    // 1b/1b/x/x REG_LONG_BUS_IDLE_E
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_CRCHK_DIS_E    BIT6    // 0/0/x/x REG_DN_SIE_HC_CRCHK_DIS_E
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DEV_RUN_E      BIT5    // 1b/1b/x/x REG_DN_SIE_HC_DEV_RUN_E
    #define CND003_OPTCFGHSBI_REG_UP_SIE_HC_SIE_RUN_E      BIT4    // 1b/1b/x/x REG_UP_SIE_HC_SIE_RUN_E
    #define CND003_OPTCFGHSBI_REG_RXRESET_DIS_E            BIT3    // 0/0/x/x REG_RXRESET_DIS_E
    #define CND003_OPTCFGHSBI_PDSUSMOD_FW_E                BIT2    // 0/0/x/x PDSUSMOD_FW_E
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_E             BIT1    // 0/0/x/x REG_DISCVLD_FW_E
    #define CND003_OPTCFGHSBI_REG_DISCVLD_FW_OPT_E         BIT0    // 0/0/x/x REG_DISCVLD_FW_OPT_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX528 0x528 // USB2 Option RX528
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_UP_E            (BIT6 + BIT7)   // 0/0/x/x REG_DCP_DEBOUNCE_UP_E
    #define CND003_OPTCFGHSBI_REG_DCP_DEBOUNCE_E               (BIT4 + BIT5)   // 01b/01b/x/x REG_DCP_DEBOUNCE_E
    #define CND003_OPTCFGHSBI_REG_DN_SIE_HC_DIS_PATCH_EOP_E    BIT3            // 0/0/x/x REG_DN_SIE_HC_DIS_PATCH_EOP_E
    #define CND003_OPTCFGHSBI_REG_EXTEND_CDP_FLAG_DEBOUNCE_E   BIT2            // 0/0/x/x REG_EXTEND_CDP_FLAG_DEBOUNCE_E
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLR_E              BIT1            // 0/0/x/x REG_CDPFLAG_FWCLR_E
    #define CND003_OPTCFGHSBI_REG_CDPFLAG_FWCLRONLY_E          BIT0            // 0/0/x/x REG_CDPFLAG_FWCLRONLY_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX529 0x529 // USB2 Option RX529
    #define CND003_OPTCFGHSBI_REG_DN_RWU_EN_E  BIT1    // 1b/1b/x/x Remote Wakeup and Connect / Disconnect Event of Device in Port E
    #define CND003_OPTCFGHSBI_REG_POWER_ON_E   BIT0    // 0/0/x/x REG_POWER_ON_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX52A 0x52A // USB2 Option RX52A
    #define CND003_OPTCFGHSBI_USB2P5_TMOUT_4MS_PARM CND003_OPTCFGHSBI_USB2_OPTION_RX52A // 1Fh/1Fh/x/x USB2P5_TMOUT_4MS_PARM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX600 0x600 // USB2 Option RX600
    #define CND003_OPTCFGHSBI_TEST_HTX_A   BIT7                    // 0/0/x/x HS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXHSRCTRL_A  (BIT4 + BIT5 + BIT6)    // 100b/100b/x/x High Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_CTRL_A       0xF                     // 1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX601 0x601 // USB2 Option RX601
    #define CND003_OPTCFGHSBI_TEST_HTX_B   BIT7                    // 0/0/x/x HS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXHSRCTRL_B  (BIT4 + BIT5 + BIT6)    // 100b/100b/x/x High Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_CTRL_B       0xF                     // 1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX602 0x602 // USB2 Option RX602
    #define CND003_OPTCFGHSBI_TEST_HTX_C   BIT7                    // 0/0/x/x HS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXHSRCTRL_C  (BIT4 + BIT5 + BIT6)    // 100b/100b/x/x High Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_CTRL_C       0xF                     // 1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX603 0x603 // USB2 Option RX603
    #define CND003_OPTCFGHSBI_TEST_HTX_D   BIT7                    // 0/0/x/x HS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXHSRCTRL_D  (BIT4 + BIT5 + BIT6)    // 100b/100b/x/x High Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_CTRL_D       0xF                     // 1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX604 0x604 // USB2 Option RX604
    #define CND003_OPTCFGHSBI_TEST_HTX_E   BIT7                    // 0/0/x/x HS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXHSRCTRL_E  (BIT4 + BIT5 + BIT6)    // 100b/100b/x/x High Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_CTRL_E       0xF                     // 1000b/1000b/x/x Control Bits for HS Termination Resistor Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX605 0x605 // USB2 Option RX605
    #define CND003_OPTCFGHSBI_RXDATA_O_A       BIT7            // 0/0/x/x RXDATA_O_A
    #define CND003_OPTCFGHSBI_SQUELCH_O_A      BIT6            // 0/0/x/x SQUELCH_O_A
    #define CND003_OPTCFGHSBI_DISCONNECT_O_A   BIT5            // 0/0/x/x DISCONNECT_O_A
    #define CND003_OPTCFGHSBI_TERM_ON_A        BIT4            // 0/0/x/x TERM_ON_A
    #define CND003_OPTCFGHSBI_DISCNT_A         (BIT2 + BIT3)   // 10b/10b/x/x 575mv Disconnection Level Fine Tune
    #define CND003_OPTCFGHSBI_SQSET_A          (BIT0 + BIT1)   // 10b/10b/x/x 125mv Squelch Level Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX606 0x606 // USB2 Option RX606
    #define CND003_OPTCFGHSBI_RXDATA_O_B       BIT7            // 0/0/x/x RXDATA_O_B
    #define CND003_OPTCFGHSBI_SQUELCH_O_B      BIT6            // 0/0/x/x SQUELCH_O_B
    #define CND003_OPTCFGHSBI_DISCONNECT_O_B   BIT5            // 0/0/x/x DISCONNECT_O_B
    #define CND003_OPTCFGHSBI_TERM_ON_B        BIT4            // 0/0/x/x TERM_ON_B
    #define CND003_OPTCFGHSBI_DISCNT_B         (BIT2 + BIT3)   // 10b/10b/x/x 575mv Disconnection Level Fine Tune
    #define CND003_OPTCFGHSBI_SQSET_B          (BIT0 + BIT1)   // 10b/10b/x/x 125mv Squelch Level Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX607 0x607 // USB2 Option RX607
    #define CND003_OPTCFGHSBI_RXDATA_O_C       BIT7            // 0/0/x/x RXDATA_O_C
    #define CND003_OPTCFGHSBI_SQUELCH_O_C      BIT6            // 0/0/x/x SQUELCH_O_C
    #define CND003_OPTCFGHSBI_DISCONNECT_O_C   BIT5            // 0/0/x/x DISCONNECT_O_C
    #define CND003_OPTCFGHSBI_TERM_ON_C        BIT4            // 0/0/x/x TERM_ON_C
    #define CND003_OPTCFGHSBI_DISCNT_C         (BIT2 + BIT3)   // 10b/10b/x/x 575mv Disconnection Level Fine Tune
    #define CND003_OPTCFGHSBI_SQSET_C          (BIT0 + BIT1)   // 10b/10b/x/x 125mv Squelch Level Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX608 0x608 // USB2 Option RX608
    #define CND003_OPTCFGHSBI_RXDATA_O_D       BIT7            // 0/0/x/x RXDATA_O_D
    #define CND003_OPTCFGHSBI_SQUELCH_O_D      BIT6            // 0/0/x/x SQUELCH_O_D
    #define CND003_OPTCFGHSBI_DISCONNECT_O_D   BIT5            // 0/0/x/x DISCONNECT_O_D
    #define CND003_OPTCFGHSBI_TERM_ON_D        BIT4            // 0/0/x/x TERM_ON_D
    #define CND003_OPTCFGHSBI_DISCNT_D         (BIT2 + BIT3)   // 10b/10b/x/x 575mv Disconnection Level Fine Tune
    #define CND003_OPTCFGHSBI_SQSET_D          (BIT0 + BIT1)   // 10b/10b/x/x 125mv Squelch Level Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX609 0x609 // USB2 Option RX609
    #define CND003_OPTCFGHSBI_RXDATA_O_E       BIT7            // 0/0/x/x RXDATA_O_E
    #define CND003_OPTCFGHSBI_SQUELCH_O_E      BIT6            // 0/0/x/x SQUELCH_O_E
    #define CND003_OPTCFGHSBI_DISCONNECT_O_E   BIT5            // 0/0/x/x DISCONNECT_O_E
    #define CND003_OPTCFGHSBI_TERM_ON_E        BIT4            // 0/0/x/x TERM_ON_E
    #define CND003_OPTCFGHSBI_DISCNT_E         (BIT2 + BIT3)   // 10b/10b/x/x 575mv Disconnection Level Fine Tune
    #define CND003_OPTCFGHSBI_SQSET_E          (BIT0 + BIT1)   // 10b/10b/x/x 125mv Squelch Level Fine Tune
#define CND003_OPTCFGHSBI_USB2_OPTION_RX60A 0x60A // USB2 Option RX60A
    #define CND003_OPTCFGHSBI_SDP_A    BIT2    // 0/0/x/x SDP_A
    #define CND003_OPTCFGHSBI_SDN_A    BIT1    // 0/0/x/x SDN_A
    #define CND003_OPTCFGHSBI_RXD_A    BIT0    // 0/0/x/x RXD_A
#define CND003_OPTCFGHSBI_USB2_OPTION_RX60B 0x60B // USB2 Option RX60B
    #define CND003_OPTCFGHSBI_SDP_B    BIT2    // 0/0/x/x SDP_B
    #define CND003_OPTCFGHSBI_SDN_B    BIT1    // 0/0/x/x SDN_B
    #define CND003_OPTCFGHSBI_RXD_B    BIT0    // 0/0/x/x RXD_B
#define CND003_OPTCFGHSBI_USB2_OPTION_RX60C 0x60C // USB2 Option RX60C
    #define CND003_OPTCFGHSBI_SDP_C    BIT2    // 0/0/x/x SDP_C
    #define CND003_OPTCFGHSBI_SDN_C    BIT1    // 0/0/x/x SDN_C
    #define CND003_OPTCFGHSBI_RXD_C    BIT0    // 0/0/x/x RXD_C
#define CND003_OPTCFGHSBI_USB2_OPTION_RX60D 0x60D // USB2 Option RX60D
    #define CND003_OPTCFGHSBI_SDP_D    BIT2    // 0/0/x/x SDP_D
    #define CND003_OPTCFGHSBI_SDN_D    BIT1    // 0/0/x/x SDN_D
    #define CND003_OPTCFGHSBI_RXD_D    BIT0    // 0/0/x/x RXD_D
#define CND003_OPTCFGHSBI_USB2_OPTION_RX60E 0x60E // USB2 Option RX60E
    #define CND003_OPTCFGHSBI_SDP_E    BIT2    // 0/0/x/x SDP_E
    #define CND003_OPTCFGHSBI_SDN_E    BIT1    // 0/0/x/x SDN_E
    #define CND003_OPTCFGHSBI_RXD_E    BIT0    // 0/0/x/x RXD_E
#define CND003_OPTCFGHSBI_USB2_OPTION_RX60F 0x60F // USB2 Option RX60F
    #define CND003_OPTCFGHSBI_TEST_HTX_A_LPM   BIT7            // 0/0/x/x HS TX Test Mode Register for LPM
    #define CND003_OPTCFGHSBI_PULLDOWNR_ON_A   BIT6            // 1b/1b/x/x 1: Enable pull down 15K resistor
    #define CND003_OPTCFGHSBI_TEST_FLRX_A      BIT5            // 0/0/x/x FS/LS RX Receiver Comparator Output
    #define CND003_OPTCFGHSBI_TEST_FLTX_A      BIT4            // 0/0/x/x FS/LS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXFSRCTRL_A      (BIT2 + BIT3)   // 10b/10b/x/x Full Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_TXLSRCTRL_A      (BIT0 + BIT1)   // 10b/10b/x/x Low speed Driver Slew Rate Control
#define CND003_OPTCFGHSBI_USB2_OPTION_RX610 0x610 // USB2 Option RX610
    #define CND003_OPTCFGHSBI_TEST_HTX_B_LPM   BIT7            // 0/0/x/x HS TX Test Mode Register for LPM
    #define CND003_OPTCFGHSBI_PULLDOWNR_ON_B   BIT6            // 1b/1b/x/x 1: Enable pull down 15K resistor
    #define CND003_OPTCFGHSBI_TEST_FLRX_B      BIT5            // 0/0/x/x FS/LS RX Receiver Comparator Output
    #define CND003_OPTCFGHSBI_TEST_FLTX_B      BIT4            // 0/0/x/x FS/LS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXFSRCTRL_B      (BIT2 + BIT3)   // 10b/10b/x/x Full Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_TXLSRCTRL_B      (BIT0 + BIT1)   // 10b/10b/x/x Low Speed Driver Slew Rate Control
#define CND003_OPTCFGHSBI_USB2_OPTION_RX611 0x611 // USB2 Option RX611
    #define CND003_OPTCFGHSBI_TEST_HTX_C_LPM   BIT7            // 0/0/x/x HS TX Test Mode Register for LPM
    #define CND003_OPTCFGHSBI_PULLDOWNR_ON_C   BIT6            // 1b/1b/x/x 1: Enable pull down 15K resistor
    #define CND003_OPTCFGHSBI_TEST_FLRX_C      BIT5            // 0/0/x/x FS/LS RX Receiver Comparator Output
    #define CND003_OPTCFGHSBI_TEST_FLTX_C      BIT4            // 0/0/x/x FS/LS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXFSRCTRL_C      (BIT2 + BIT3)   // 10b/10b/x/x Full Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_TXLSRCTRL_C      (BIT0 + BIT1)   // 10b/10b/x/x Low Speed Driver Slew Rate Control
#define CND003_OPTCFGHSBI_USB2_OPTION_RX612 0x612 // USB2 Option RX612
    #define CND003_OPTCFGHSBI_TEST_HTX_D_LPM   BIT7            // 0/0/x/x HS TX Test Mode Register for LPM
    #define CND003_OPTCFGHSBI_PULLDOWNR_ON_D   BIT6            // 1b/1b/x/x 1: Enable pull down 15K resistor 
    #define CND003_OPTCFGHSBI_TEST_FLRX_D      BIT5            // 0/0/x/x FS/LS RX Receiver Comparator Output
    #define CND003_OPTCFGHSBI_TEST_FLTX_D      BIT4            // 0/0/x/x FS/LS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXFSRCTRL_D      (BIT2 + BIT3)   // 10b/10b/x/x Full Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_TXLSRCTRL_D      (BIT0 + BIT1)   // 10b/10b/x/x Low Speed Driver Slew Rate Control
#define CND003_OPTCFGHSBI_USB2_OPTION_RX613 0x613 // USB2 Option RX613
    #define CND003_OPTCFGHSBI_TEST_HTX_E_LPM   BIT7            // 0/0/x/x HS TX Test Mmode Register for LPM
    #define CND003_OPTCFGHSBI_PULLDOWNR_ON_E   BIT6            // 1b/1b/x/x 1: Enable pull down 15K resistor
    #define CND003_OPTCFGHSBI_TEST_FLRX_E      BIT5            // 0/0/x/x FS/LS RX Receiver Comparator Output
    #define CND003_OPTCFGHSBI_TEST_FLTX_E      BIT4            // 0/0/x/x FS/LS TX Test Mode Register
    #define CND003_OPTCFGHSBI_TXFSRCTRL_E      (BIT2 + BIT3)   // 10b/10b/x/x Full Speed Driver Slew Rate Control
    #define CND003_OPTCFGHSBI_TXLSRCTRL_E      (BIT0 + BIT1)   // 10b/10b/x/x Low Speed Driver Slew Rate Control
#define CND003_OPTCFGHSBI_USB2_OPTION_RX614 0x614 // USB2 Option RX614
    #define CND003_OPTCFGHSBI_TMODE    BIT0    // 1b/1b/x/x Set the PLLTEST Output
#define CND003_OPTCFGHSBI_USB2_OPTION_RX615 0x615 // USB2 Option RX615
    #define CND003_OPTCFGHSBI_INDATADLY    (BIT6 + BIT7)   // 0/0/x/x DPLL Input Data Delay Select
    #define CND003_OPTCFGHSBI_TRACKSPD     (BIT4 + BIT5)   // 01b/01b/x/x DPLL Track Speed Select
    #define CND003_OPTCFGHSBI_LOCKSPD      (BIT2 + BIT3)   // 11b/11b/x/x DPLL Lock Speed Select
    #define CND003_OPTCFGHSBI_FASTLOCK     BIT1            // 1b/1b/x/x DPLL_LPF Lock Mode Set Register
    #define CND003_OPTCFGHSBI_FASTSTART    BIT0            // 0/0/x/x DPLL_ZPS Double Sampling Set Register
#define CND003_OPTCFGHSBI_USB2_OPTION_RX616 0x616 // USB2 Option RX616
    #define CND003_OPTCFGHSBI_DPLL_BISTOK  BIT7            // 0/0/x/x DPLL BIST Pattern Matching Flag
    #define CND003_OPTCFGHSBI_DPLL_BISTS2  BIT6            // 0/0/x/x DPLL BIST Set Register for Different Test Pattern
    #define CND003_OPTCFGHSBI_DPLL_BISTS1  BIT5            // 0/0/x/x DPLL BIST Set Register for Different Test Pattern
    #define CND003_OPTCFGHSBI_DPLL_BISTS0  BIT4            // 0/0/x/x DPLL BIST Set Register for Different Test Pattern
    #define CND003_OPTCFGHSBI_DPLL_BISTRST BIT3            // 0/0/x/x Set Register to Reset DPLL for BIST
    #define CND003_OPTCFGHSBI_RDOUT_ENB    BIT2            // 0/0/x/x DPLL RDOUT4:0 Output Enable
    #define CND003_OPTCFGHSBI_INDLY        (BIT0 + BIT1)   // 0/0/x/x DPLL NSQ Offset set Register
#define CND003_OPTCFGHSBI_USB2_OPTION_RX617 0x617 // USB2 Option RX617
    #define CND003_OPTCFGHSBI_LBACK_ENB    BIT5            // 0/0/x/x DPLL Loopback Enable
    #define CND003_OPTCFGHSBI_RDOUT        0x1F            // 0/0/x/x DPLL Test Mode Observed Signals
#define CND003_OPTCFGHSBI_USB2_OPTION_RX618 0x618 // USB2 Option RX618
    #define CND003_OPTCFGHSBI_INDATADLY_LPM    (BIT6 + BIT7)   // 0/0/x/x DPLL Input Data Delay Select for LPM
    #define CND003_OPTCFGHSBI_TRACKSPD_LPM     (BIT4 + BIT5)   // 01b/01b/x/x DPLL Track Speed Select for LPM
    #define CND003_OPTCFGHSBI_LOCKSPD_LPM      (BIT2 + BIT3)   // 11b/11b/x/x DPLL Lock Speed Select for LPM
    #define CND003_OPTCFGHSBI_FASTLOCK_LPM     BIT1            // 1b/1b/x/x DPLL_LPF Lock Mode Set Register for LPM
    #define CND003_OPTCFGHSBI_FASTSTART_LPM    BIT0            // 0/0/x/x DPLL_ZPS Double Sampling Set Register for LPM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX619 0x619 // USB2 Option RX619
    #define CND003_OPTCFGHSBI_DPLL_BISTOK_LPM  BIT7            // 0/0/x/x DPLL BIST Pattern Matching Flag for LPM
    #define CND003_OPTCFGHSBI_DPLL_BISTS2_LPM  BIT6            // 0/0/x/x DPLL BIST Set Register for Different Test Pattern for LPM
    #define CND003_OPTCFGHSBI_DPLL_BISTS1_LPM  BIT5            // 0/0/x/x DPLL BIST Set Register for Different Test Pattern for LPM
    #define CND003_OPTCFGHSBI_DPLL_BISTS0_LPM  BIT4            // 0/0/x/x DPLL BIST Set Register for Different Test Pattern for LPM
    #define CND003_OPTCFGHSBI_DPLL_BISTRST_LPM BIT3            // 0/0/x/x Set Register to Reset DPLL for BIST for LPM
    #define CND003_OPTCFGHSBI_RDOUT_ENB_LPM    BIT2            // 0/0/x/x DPLL RDOUT4:0 Output Enable for LPM
    #define CND003_OPTCFGHSBI_INDLY_LPM        (BIT0 + BIT1)   // 0/0/x/x DPLL NSQ Offset Set Register for LPM
#define CND003_OPTCFGHSBI_USB2_OPTION_RX61A 0x61A // USB2 Option RX61A
    #define CND003_OPTCFGHSBI_LBACK_ENB_LPM    BIT5            // 0/0/x/x DPLL Loopback Enable
    #define CND003_OPTCFGHSBI_RDOUT_LPM        0x1F            // 0/0/x/x DPLL Test Mode Observed Signals
#define CND003_OPTCFGHSBI_USB2_OPTION_RX61B 0x61B // USB2 Option RX61B
    #define CND003_OPTCFGHSBI_ITRIM    (BIT0 + BIT1)   // 0/0/x/x ITRIM[2:1]
// U3IP_SSCFG_C
#define CND003_U3IPSSCFGC_SSIP_COMMON_OPTIONAL_REG 0x0 // SSIP_Common_optional_register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_000_12   0xF000          // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_PTMFLD                 0xF00           // 0/x/x/x Reserved ((in VT3515C0))
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_000_7    BIT7            // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_SSCFGRISEWE            BIT6            // 1b/x/x/x Sample the Rising Edge of WE to Write Data
    #define CND003_U3IPSSCFGC_R_PBD2TDRIVE             (BIT4 + BIT5)   // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_TIEH                   BIT3            // 1b/x/x/x Tie Cell
    #define CND003_U3IPSSCFGC_R_TIEL                   BIT2            // 0/x/x/x Tie Cell
    #define CND003_U3IPSSCFGC_R_DYNSUSCFGCLK           BIT1            // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_DYNCORECFGCLK          BIT0            // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_02 0x2 // SSIP_Common_Reserved_02
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_002 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_02 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_04 0x4 // SSIP_Common_Reserved_04
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_004 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_04 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_06 0x6 // SSIP_Common_Reserved_06
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_006 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_06 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_08 0x8 // SSIP_Common_Reserved_08
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_008 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_08 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_0A 0xA // SSIP_Common_Reserved_0A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_00A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_0A // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_0C 0xC // SSIP_Common_Reserved_0C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_00C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_0C // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_0E 0xE // SSIP_Common_Reserved_0E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_00E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_0E // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_10 0x10 // SSIP_Common_Reserved_10
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_10 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_10 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_12 0x12 // SSIP_Common_Reserved_12
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_12 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_12 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_14 0x14 // SSIP_Common_Reserved_14
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_14 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_14 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_16 0x16 // SSIP_Common_Reserved_16
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_16 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_16 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_18 0x18 // SSIP_Common_Reserved_18
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_18 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_18 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_1A 0x1A // SSIP_Common_Reserved_1A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_1A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_1A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_1C 0x1C // SSIP_Common_Reserved_1C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_1C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_1C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_1E 0x1E // SSIP_Common_Reserved_1E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_1E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_1E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_20 0x20 // SSIP_Common_Reserved_20
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_20 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_20 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_22 0x22 // SSIP_Common_Reserved_22
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_22 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_22 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_24 0x24 // SSIP_Common_Reserved_24
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_24 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_24 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_26 0x26 // SSIP_Common_Reserved_26
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_26 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_26 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_28 0x28 // SSIP_Common_Reserved_28
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_28 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_28 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_2A 0x2A // SSIP_Common_Reserved_2A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_2A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_2A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_2C 0x2C // SSIP_Common_Reserved_2C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_2C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_2C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_2E 0x2E // SSIP_Common_Reserved_2E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_2E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_2E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_30 0x30 // SSIP_Common_Reserved_30
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_30 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_30 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_32 0x32 // SSIP_Common_Reserved_32
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_32 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_32 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_34 0x34 // SSIP_Common_Reserved_34
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_34 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_34 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_36 0x36 // SSIP_Common_Reserved_36
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_36 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_36 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_38 0x38 // SSIP_Common_Reserved_38
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_38 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_38 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_3A 0x3A // SSIP_Common_Reserved_3A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_3A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_3A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_3C 0x3C // SSIP_Common_Reserved_3C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_3C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_3C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_3E 0x3E // SSIP_Common_Reserved_3E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_3E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_3E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_40 0x40 // SSIP_Common_Reserved_40
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_40 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_40 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_42 0x42 // SSIP_Common_Reserved_42
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_42 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_42 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_44 0x44 // SSIP_Common_Reserved_44
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_44 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_44 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_46 0x46 // SSIP_Common_Reserved_46
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_46 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_46 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_48 0x48 // SSIP_Common_Reserved_48
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_48 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_48 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_4A 0x4A // SSIP_Common_Reserved_4A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_4A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_4A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_4C 0x4C // SSIP_Common_Reserved_4C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_4C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_4C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_4E 0x4E // SSIP_Common_Reserved_4E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_4E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_4E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_50 0x50 // SSIP_Common_Reserved_50
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_50 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_50 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_52 0x52 // SSIP_Common_Reserved_52
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_52 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_52 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_54 0x54 // SSIP_Common_Reserved_54
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_54 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_54 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_56 0x56 // SSIP_Common_Reserved_56
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_56 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_56 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_58 0x58 // SSIP_Common_Reserved_58
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_58 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_58 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_5A 0x5A // SSIP_Common_Reserved_5A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_5A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_5A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_5C 0x5C // SSIP_Common_Reserved_5C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_5C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_5C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_5E 0x5E // SSIP_Common_Reserved_5E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_5E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_5E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_60 0x60 // SSIP_Common_Reserved_60
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_60 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_60 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_62 0x62 // SSIP_Common_Reserved_62
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_62 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_62 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_64 0x64 // SSIP_Common_Reserved_64
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_64 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_64 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_66 0x66 // SSIP_Common_Reserved_66
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_66 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_66 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_68 0x68 // SSIP_Common_Reserved_68
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_68 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_68 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_6A 0x6A // SSIP_Common_Reserved_6A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_6A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_6A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_6C 0x6C // SSIP_Common_Reserved_6C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_6C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_6C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_6E 0x6E // SSIP_Common_Reserved_6E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_6E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_6E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_70 0x70 // SSIP_Common_Reserved_70
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_70 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_70 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_72 0x72 // SSIP_Common_Reserved_72
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_72 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_72 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_74 0x74 // SSIP_Common_Reserved_74
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_74 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_74 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_76 0x76 // SSIP_Common_Reserved_76
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_76 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_76 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_78 0x78 // SSIP_Common_Reserved_78
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_78 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_78 // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_7A 0x7A // SSIP_Common_Reserved_7A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_7A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_7A // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_7C 0x7C // SSIP_Common_Reserved_7C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_7C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_7C // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_7E 0x7E // SSIP_Common_Reserved_7E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_RO_7E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_7E // HwInit/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_EPHY_BG_RTN_REG 0x80 // SSIP_Common_EPHY_BG_RTN_Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_80   BIT15           // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_FHU_RTNTXSET_10G     0x7800          // 1000b/x/x/x TX Resistance Manual Setting (TT Corner)
    #define CND003_U3IPSSCFGC_FHU_RTNTXSETEN_10G   BIT10           // 0/x/x/x TX Resistance Set Enable
    #define CND003_U3IPSSCFGC_FHU_RTNVCSEL_10G     (BIT8 + BIT9)   // 0/x/x/x RTN Comparator Voltage Tuning
    #define CND003_U3IPSSCFGC_EPU_RTNOUT           0xF0            // 0/x/x/x RTN Codes Output
    #define CND003_U3IPSSCFGC_FHU_ITRIM_NP_10G     (BIT2 + BIT3)   // 0/x/x/x For I-source Trimming of N-poly Resistor Type Use
    #define CND003_U3IPSSCFGC_FHU_ITRIM_PP_10G     (BIT0 + BIT1)   // 0/x/x/x For I-source trimming of P-poly resistor type use.
#define CND003_U3IPSSCFGC_SSIP_COMMON_EPHY_MPLL_TPLL_REG 0x82 // SSIP_Common_EPHY_MPLL_TPLL_Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_082  0xFF00                  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_FHU_PLLTESTSEL_10G   (BIT6 + BIT7)           // 0/x/x/x PLLTEST Output Setting
    #define CND003_U3IPSSCFGC_FHU_MPLLCPISEL_10G   (BIT3 + BIT4 + BIT5)    // 011b/x/x/x MPLL Charge Pump Current Setting
    #define CND003_U3IPSSCFGC_FHU_MPLLRSEL_10G     (BIT1 + BIT2)           // 10b/x/x/x MPLL Loop Filter Resistance Setting
    #define CND003_U3IPSSCFGC_FHU_FTMODE_10G       BIT0                    // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_EPHY_SPLL_REG_1 0x84 // SSIP_Common_EPHY_SPLL_Register_1
    #define CND003_U3IPSSCFGC_FHU_SDMDIGEN         BIT15           // 0/x/x/x SSCPLL Digital Part Clock Enable
    #define CND003_U3IPSSCFGC_FHU_SDMDITHEREN      BIT14           // 0/x/x/x Enable SDM Dithering
    #define CND003_U3IPSSCFGC_FHU_SDMSSCEN         BIT13           // 0/x/x/x SSCPLL SSC Function in Digital Top
    #define CND003_U3IPSSCFGC_FHU_SPLLINDIV        0x1F00          // 01000b/x/x/x SPLL Input Divider
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_084  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_FHU_SPLLCP2I         BIT5            // 0/x/x/x SSCPLL Charge Pump Current Option
    #define CND003_U3IPSSCFGC_FHU_SPLLFNEN         BIT4            // 0/x/x/x SSCPLL Enable Fractional-N mode, Choose MMD input 6b Control from FND...
    #define CND003_U3IPSSCFGC_FHU_SPLLPDB          BIT3            // 1b/x/x/x SSCPLL Power up by Register 
    #define CND003_U3IPSSCFGC_FHU_SPLLRSTB         BIT2            // 1b/x/x/x SSCPLL Reset Control by Register
    #define CND003_U3IPSSCFGC_FHU_SPLLSSCSETEN     BIT1            // 0/x/x/x Enable SSCPLL SSC
    #define CND003_U3IPSSCFGC_FHU_BYPASSOSC        BIT0            // 0/x/x/x Oscillator Bypass Enable
#define CND003_U3IPSSCFGC_SSIP_COMMON_EPHY_SPLL_REG_2 0x86 // SSIP_Common_EPHY_SPLL_Register_2
    #define CND003_U3IPSSCFGC_FHU_RANGESEL_10G (BIT14 + BIT15)         // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_FHU_DFCOW        0x3C00                  // 1000b/x/x/x DFC Overwrite code for VREGSEL
    #define CND003_U3IPSSCFGC_FHU_SPLLBW       (BIT8 + BIT9)           // 0/x/x/x SSCPLL Bandwidth Options 
    #define CND003_U3IPSSCFGC_FHU_SPLLSSCOS    (BIT5 + BIT6 + BIT7)    // 001b/x/x/x SSC Mean Value Shift for Down Spread Profile
    #define CND003_U3IPSSCFGC_FHU_SPLLSSCMAG   (BIT2 + BIT3 + BIT4)    // 100b/x/x/x SSC Management
    #define CND003_U3IPSSCFGC_FHU_SDMASYMSSC   BIT1                    // 1b/x/x/x Enable SSCPLL Asymmetry SSC
    #define CND003_U3IPSSCFGC_FHU_SDMREFCLKSEL BIT0                    // 0/x/x/x SSCPLL Digital Part System Clock from 
#define CND003_U3IPSSCFGC_SSIP_COMMON_SPLL_DBG_REG 0x88 // SSIP_Common_SPLL_DBG_Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_088_14   (BIT14 + BIT15)         // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_DBGSEL                 0x3F00                  // 0/x/x/x Debug Signal Selection Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_088_5    (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_EPU_SDMFNDIVO            0x1F                    // 0/x/x/x Readout SSCPLL SDM Output Codes Value
#define CND003_U3IPSSCFGC_SSIP_COMMON_SPLL_STA_PLLC_REG 0x8A // SSIP_Common_SPLL_Status_PLLC_Register
    #define CND003_U3IPSSCFGC_R_UPCTPLLEN          BIT15   // 1b/x/x/x Select Which Set Controls TPLL Enable Only for Hub Mode
    #define CND003_U3IPSSCFGC_R_DYNTPLLEN          BIT14   // 0/x/x/x Reserved 
    #define CND003_U3IPSSCFGC_R_DYNBGEN            BIT13   // 0/x/x/x Enable Dynamic Band Gap Function. 
    #define CND003_U3IPSSCFGC_R_TPLLPD             BIT12   // 1b/x/x/x Firmware Control If TPLL Turn on or Not When No Device Connected
    #define CND003_U3IPSSCFGC_R_TPLLPDEN           BIT11   // 1b/x/x/x Enable Firmware Control TPLL on Signal
    #define CND003_U3IPSSCFGC_R_PLLCDYNEN          BIT10   // 0/x/x/1b Enable PLLC Dynamic Clock in PLL Power down
    #define CND003_U3IPSSCFGC_R_PLLCSSCEN          BIT9    // 1b/x/x/x PLLC Control SSC Enable
    #define CND003_U3IPSSCFGC_R_PLLPDSEL           BIT8    // 0/x/x/x Select to Turn off SPLL or MPLL
    #define CND003_U3IPSSCFGC_EPU_DFCVREGSELO      0xF0    // 0/x/x/x SSCPLL VCO Regulator Voltage Control Selection Mux
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_08A  0xF     // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_CLK_OPTION_REG 0x8C // SSIP_Common_Clock_Option_Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_08C  0xFF80  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_FDETEN             BIT6    // 0/x/x/x PLL Locking Frequency Detector Enable
    #define CND003_U3IPSSCFGC_R_EXTSSCTM           BIT5    // 0/x/x/x Extend SSC Time
    #define CND003_U3IPSSCFGC_R_RTNRTEN            BIT4    // 0/x/x/x Re-tuning RTN Function when Firmware Modifies RTN Parameters
    #define CND003_U3IPSSCFGC_R_SCFGOF             BIT3    // 1b/x/x/x When Enabled, SSCFG Clock Will Be Turned off in Suspend State
    #define CND003_U3IPSSCFGC_R_DYNLDCLKEN         BIT2    // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_DYNSDCLKEN         BIT1    // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_RCVDETIP2          BIT0    // 0/x/x/x Enable Receiver Detection Always in P2
#define CND003_U3IPSSCFGC_SSIP_COMMON_5G_PLLC_CTRL_REG 0x8E // SSIP_Common_5G_PLLC_CTRL_Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_08E  0xFE00  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_R_TPLL_SET_5G        BIT8    // 0/x/x/x Register Set the TPLL Power on when R_TPLL_SETEN =1
    #define CND003_U3IPSSCFGC_R_TPLL_SETEN_5G      BIT7    // 0/x/x/x Enable Register Control TPLLPDB when MPLL Power on
    #define CND003_U3IPSSCFGC_R_BGOFFRCVEN_5G      BIT6    // 0/x/x/x USB3.0 EPHY Enable Register for LPHY Makes EPHY Do RCVDET when BG Is Off
    #define CND003_U3IPSSCFGC_R_MPLLDYNOFFEN_5G    BIT5    // 0/x/x/x USB3.0 EPHY Enable register for LPHY Dynamically Control MPLL Off
    #define CND003_U3IPSSCFGC_R_TPLLDYNOFFEN_5G    BIT4    // 0/x/x/x USB3.0 EPHY Enable Register for LPHY Dynamically Control TPLL Off
    #define CND003_U3IPSSCFGC_R_RTNTUNE_RST_5G     BIT3    // 0/x/x/x USB3.0 EPHY RTN Function Reset
    #define CND003_U3IPSSCFGC_R_TPLLPDENB_5G       BIT2    // 1b/x/x/x USB3.0 EPHY Enable to Turn off TPLL when MPLL On with no Device Conn...
    #define CND003_U3IPSSCFGC_R_DYNBGEN_5G         BIT1    // 0/x/x/x USB3.0 EPHY Enable Dynamic Bandgap Power on
    #define CND003_U3IPSSCFGC_R_PLLCDYNEN_5G       BIT0    // 0/x/x/1b USB3.0 EPHY PLLC Dynamic Clock Enable
#define CND003_U3IPSSCFGC_SSIP_COMMON_EPHY_NWE_REG 0x90 // SSIP_Common_EPHY_NWE_Register
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_090  0xFFF0                  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGC_FHU_MPLLVCOREG_10G   (BIT1 + BIT2 + BIT3)    // 100b/x/x/x VCO Regulator Voltage Fine Tune
    #define CND003_U3IPSSCFGC_FHU_SLICERCTL_10G    BIT0                    // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_5G_EPHY_REG 0x92 // SSIP_Common_5G_EPHY_ Register
    #define CND003_U3IPSSCFGC_FHU_TPLLBW_5G        (BIT14 + BIT15) // 01b/x/x/x TPLL Close Loop Bandwidth Selection
    #define CND003_U3IPSSCFGC_FHU_MPLLBW_5G        (BIT12 + BIT13) // 01b/x/x/x MPLL Close Loop Bandwidth Selection
    #define CND003_U3IPSSCFGC_FHU_PLLFBRATIO_5G    BIT11           // 0/x/x/x Feedback Clock Ratio for Test (Also for All TPLL)
    #define CND003_U3IPSSCFGC_FHU_RTNTXSET_5G      0x780           // 0110b/x/x/x TX Resistance Manual Setting (TT Corner)
    #define CND003_U3IPSSCFGC_FHU_RTNTXSETEN_5G    BIT6            // 0/x/x/x TX Resistance Set Enable
    #define CND003_U3IPSSCFGC_FHU_ITRIM_NP_5G      (BIT4 + BIT5)   // 0/x/x/x For I-source Trimming of P-poly Resistor Type Use
    #define CND003_U3IPSSCFGC_FHU_ITRIM_PP_5G      (BIT2 + BIT3)   // 0/x/x/x For I-source Trimming of N-poly Resistor Type Use
    #define CND003_U3IPSSCFGC_FHU_PLLTESTSEL_5G    (BIT0 + BIT1)   // 0/x/x/x PLLTEST Output Setting
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_94 0x94 // SSIP_Common_Reserved_94
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_094 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_94 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_96 0x96 // SSIP_Common_Reserved_96
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_096 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_96 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_98 0x98 // SSIP_Common_Reserved_98
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_098 CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_98 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_9A 0x9A // SSIP_Common_Reserved_9A
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_09A CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_9A // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_9C 0x9C // SSIP_Common_Reserved_9C
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_09C CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_9C // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_9E 0x9E // SSIP_Common_Reserved_9E
    #define CND003_U3IPSSCFGC_RSVU3IP_SSCFG_C_09E CND003_U3IPSSCFGC_SSIP_COMMON_RESERVED_9E // FFFFh/x/x/x Reserved
// U3IP_SSCFG_P
#define CND003_U3IPSSCFGP_SSIP_PORT_BASIC_FEATURE_REGS 0x0 // SSIP_PORT_Basic_Feature_Registers
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_000_6_SS (BIT14 + BIT15)         // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_NUMHP_SS               0x3FC0                  // 04h/x/x/x Number of HP Buffer
    #define CND003_U3IPSSCFGP_R_SSPOTG_SS              BIT5                    // 0/x/x/x SSP OTG Function 
    #define CND003_U3IPSSCFGP_R_SPDSEL_SS              (BIT2 + BIT3 + BIT4)    // 000b/x/x/x Link Speed Selection
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_000_0_SS (BIT0 + BIT1)           // 0/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSIP_PORT_DYNAMIC_CLK_CTL_REGS 0x2 // SSIP_PORT_Dynamic_Clock_Control_Registers
    #define CND003_U3IPSSCFGP_R_PLTX250DYNPMEN_SS      BIT15   // 0/x/x/1b Enable SSP PL TX Clock
    #define CND003_U3IPSSCFGP_R_RXDPDYNEN_SS           BIT14   // 0/x/x/1b Enable RXDPP Dynamic Clock Function
    #define CND003_U3IPSSCFGP_R_RXHRDYNEN_SS           BIT13   // 0/x/x/1b Enable RXHDR Dynamic Clock Function
    #define CND003_U3IPSSCFGP_R_LPBKDYNEN_SS           BIT12   // 0/x/x/1b Enable Loop-back Dynamic Clock Function
    #define CND003_U3IPSSCFGP_R_AGRSVLPHYRXDYNPMEN_SS  BIT11   // 0/x/x/1b PHYLS RX Aggressive Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_AGRSVLPHYTXDYNPMEN_SS  BIT10   // 0/x/x/1b PHYLS TX Aggressive Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_LPHYRXDYNPMEN_SS       BIT9    // 0/x/x/1b PHYLS 2nd Level RX Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_LPHYTXDYNPMEN_SS       BIT8    // 0/x/x/1b PHYLS 2nd Level TX Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_PHYDYNCLKEN_SS         BIT7    // 0/x/x/1b PHYLS 1st Level Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_LNRXDYNPMEN_SS         BIT6    // 0/x/x/1b Link Layer 2nd Level RX Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_LNTXDYNPMEN_SS         BIT5    // 0/x/x/1b Link Layer 2nd Level TX Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_LNDYNCLKEN_SS          BIT4    // 0/x/x/1b Link Layer 1st Level Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_PLRXDYNPMEN_SS         BIT3    // 0/x/x/1b Protocol Layer 2nd Level RX Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_PLTXDYNPMEN_SS         BIT2    // 0/x/x/1b Protocol Layer 2nd Level TX Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_PLDYNCLKEN_SS          BIT1    // 0/x/x/1b Protocol Layer 1st Level Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_DYNPM_SS               BIT0    // 0/x/x/1b Dynamic Power Management Control Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_PGAR_OPTION_REGS1 0x4 // SSIP_PORT_PGAR_Option_Registers1
    #define CND003_U3IPSSCFGP_R_PCAPDIR_SS     (BIT14 + BIT15) // 01b/x/x/x FW Control Direction Filed in Port Capability LMP
    #define CND003_U3IPSSCFGP_R_RTYDPHONLY_SS  BIT13           // 1b/x/x/x Retransmit DPH Only when DP Retry
    #define CND003_U3IPSSCFGP_R_RTYDPP_SS      BIT12           // 0/x/x/x Re-transmit DPP when DP Retry
    #define CND003_U3IPSSCFGP_R_TIEBREAKER_SS  0xF00           // 0/x/x/x Tiebreaker Value
    #define CND003_U3IPSSCFGP_R_FWTBRKEN_SS    BIT7            // 0/x/x/x FW Control Tiebreaker Value
    #define CND003_U3IPSSCFGP_R_DLYMRKEN_SS    BIT6            // 1b/x/x/x Enable Delayed Bit Marking
    #define CND003_U3IPSSCFGP_R_TIEBRKEN_SS    BIT5            // 0/x/x/x Enable Tiebreaker Negotiation 
    #define CND003_U3IPSSCFGP_R_ITSQCTL_SS     BIT4            // 0/x/x/x Update ITS Field in ITP after Retry
    #define CND003_U3IPSSCFGP_R_HDBUFRSTEN_SS  BIT3            // 0/x/x/x HCI Purge Isochronous Packets in TXHDBUF during Training State
    #define CND003_U3IPSSCFGP_R_PCFGSMEN_SS    BIT2            // 1b/x/x/x Automatic Port Configuration Generation
    #define CND003_U3IPSSCFGP_R_ITSSEL_SS      (BIT0 + BIT1)   // 00b/x/x/x ITS Delta Counter Estimation
#define CND003_U3IPSSCFGP_SSIP_PORT_PGAR_OPTION_REGS2 0x6 // SSIP_PORT_PGAR_Option_Registers2
    #define CND003_U3IPSSCFGP_R_DEVNTFERREN_SS     BIT15   // 1b/x/x/x DEVNTF Error Check
    #define CND003_U3IPSSCFGP_R_SLFERREN_SS        BIT14   // 1b/x/x/x SLF Error Check
    #define CND003_U3IPSSCFGP_R_PCFGU0EN_SS        BIT13   // 1b/x/x/x Enable PCFG Timer Counting Only in U0 State 
    #define CND003_U3IPSSCFGP_R_DLENDIFF_SS        BIT12   // 0/x/x/x Data Length Mismatch Error
    #define CND003_U3IPSSCFGP_R_CRC32ERR_SS        BIT11   // 0/x/x/x Payload CRC32 Error
    #define CND003_U3IPSSCFGP_R_CRC16ERR_SS        BIT10   // 0/x/x/x Header CRC16 Error
    #define CND003_U3IPSSCFGP_R_LCWCRC5ERR_SS      BIT9    // 0/x/x/x Link Control Word CRC5 Error
    #define CND003_U3IPSSCFGP_R_HSQERR_SS          BIT8    // 0/x/x/x Header Sequence Number Error
    #define CND003_U3IPSSCFGP_R_SPDNHFCHK_SS       BIT7    // 0/x/x/x Enable SPD Number Check 
    #define CND003_U3IPSSCFGP_R_ENSSVA_SS          BIT6    // 0/x/x/x Enable SS value available
    #define CND003_U3IPSSCFGP_R_SSPEQLCW_SS        BIT5    // 0/x/x/x Enable Both Link Command Word Check in the Same Link Command
    #define CND003_U3IPSSCFGP_R_RXDP250DYNEN_SS    BIT4    // 0/x/x/1b Enable SSP PL RX Data Dynamic Clock
    #define CND003_U3IPSSCFGP_R_RXHR250DYNEN_SS    BIT3    // 0/x/x/1b Enable SSP LN RX Header Dynamic Clock 
    #define CND003_U3IPSSCFGP_R_LNRX250DYNPMEN_SS  BIT2    // 0/x/x/1b Enable SSP LN RX Dynamic Clock
    #define CND003_U3IPSSCFGP_R_LNTX250DYNPMEN_SS  BIT1    // 0/x/x/1b Enable SSP LN TX Dynamic Clock
    #define CND003_U3IPSSCFGP_R_PLRX250DYNPMEN_SS  BIT0    // 0/x/x/1b Enable SSP PL RX Dynamic Clock
#define CND003_U3IPSSCFGP_SSIP_PORT_LTSSM_OPTION_REGS_1 0x8 // SSIP_PORT_LTSSM_Option_Registers_1
    #define CND003_U3IPSSCFGP_R_PLNOTMO_SS     BIT15   // 0/x/x/x Disable Polling-LFPS State Negotiation Timer
    #define CND003_U3IPSSCFGP_R_DETRST_SS      BIT14   // 0/x/x/x Reset Link State to Rx.Detect.Reset State
    #define CND003_U3IPSSCFGP_R_SWLPSTEN_SS    BIT13   // 0/x/x/x Enable Samples Wake up LFPS Signal during Power State Transition Time
    #define CND003_U3IPSSCFGP_R_U2TXP1EN_SS    BIT12   // 0/x/x/x Enable U2 State to Enter P1 State in TX
    #define CND003_U3IPSSCFGP_R_WRSTCPLEN_SS   BIT11   // 1b/x/x/x Enable LTSSM Response SC_WRST_CPL in RX.Detect State when No Device ...
    #define CND003_U3IPSSCFGP_R_POLFPSSKIP_SS  BIT10   // 0/x/x/x For Test Mode, If This Register Asserted, LTSSM Will Skip Polling LFP...
    #define CND003_U3IPSSCFGP_R_U0KEEP_SS      BIT9    // 0/x/x/x For Test mode, If This Register Asserted, LTSSM Will Keep in U0 until...
    #define CND003_U3IPSSCFGP_R_LPBK_MSTREN_SS BIT8    // 1b/x/x/x When Loopback Bit Asserted in TS2 Concurrent Condition Occurred, Thi...
    #define CND003_U3IPSSCFGP_R_RDLNCTL_SS     0xF0    // 0001b/x/x/x Receiver Detection Limitation Number Control
    #define CND003_U3IPSSCFGP_R_DISCPOP_SS     BIT3    // 0/x/x/x Disable Core-power off Resumption Path from Rx.Detect to U3 or Not
    #define CND003_U3IPSSCFGP_R_DPLCEN_SS      BIT2    // 0/x/x/x Enable Double Ping LFPS Cycle to 4T Only for UFP
    #define CND003_U3IPSSCFGP_R_PLWRSTEN_SS    BIT1    // 0/x/x/x Enable to Automatically Generate Warm Reset by LTSSM when None the Fi...
    #define CND003_U3IPSSCFGP_R_PORTPRTYEN_SS  BIT0    // 0/x/x/x Port Register Priority Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_LTSSM_OPTION_REGS_2 0xA // SSIP_PORT_LTSSM_Option_Registers_2
    #define CND003_U3IPSSCFGP_R_TXTS2E_SS              (BIT14 + BIT15) // 00b/x/x/x Enable TS2 Number Extension for Polling and Recovery State
    #define CND003_U3IPSSCFGP_R_TXTS1E_SS              (BIT12 + BIT13) // 00b/x/x/x Enable TS1 Number Extension for Polling and Recovery State
    #define CND003_U3IPSSCFGP_R_RXHZ_DISTEST_SS        BIT11           // 0/x/x/x RX HZ Disable (for Test Mode)
    #define CND003_U3IPSSCFGP_R_DIRU0_SS               BIT10           // 0/x/x/x Direct LTSSM to U0 from Any State (for Test Mode) 
    #define CND003_U3IPSSCFGP_R_UPDISEN_SS             BIT9            // 1b/x/x/x xHCI Control UFP Disable State Enable
    #define CND003_U3IPSSCFGP_R_CMPSCRM_SS             BIT8            // 0/x/x/x Enable Register to Control Scramble Function in Compliance Mode for T...
    #define CND003_U3IPSSCFGP_R_IGNTS2RST_SS           BIT7            // 0/x/x/x Ignore the Constrain of Received TS2 with Reset Bit Asserted in Hot R...
    #define CND003_U3IPSSCFGP_R_U0LPDBEN_SS            BIT6            // 0/x/x/x Enable U0 LFPS Power down Function
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_00A_5_SS BIT5            // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_NOLTMO_SS              BIT4            // 0/x/x/x Disable LUP/LDN Detecting Timer
    #define CND003_U3IPSSCFGP_R_IA2CEN_SS              BIT3            // 0/x/x/x Enable IDLE State to CFG State when Detecting Consecutive TS
    #define CND003_U3IPSSCFGP_R_CA2IEN_SS              BIT2            // 1b/x/x/x Enable CFG State to IDLE State when Detecting Consecutive Logic Idle
    #define CND003_U3IPSSCFGP_R_RXPASSEN_SS            BIT1            // 0/x/x/x Port Configuration Done Pass Enable
    #define CND003_U3IPSSCFGP_R_FU3CLREN_SS            BIT0            // 0/x/x/x Enable Clear FU3 Flag in U3 State Function
#define CND003_U3IPSSCFGP_SSIP_PORT_LTSSM_OPTION_REGS_3 0xC // SSIP_PORT_LTSSM_Option_Registers_3
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_00C_SS   0xF000  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_RXTSEQCLR_SS           BIT11   // 0/x/x/x Clear D_RXTSEQ_SS Value
    #define CND003_U3IPSSCFGP_R_RXLBADCLR_SS           BIT10   // 0/x/x/x Clear D_RXLBAD_SS Value
    #define CND003_U3IPSSCFGP_R_RXRCVYCLR_SS           BIT9    // 0/x/x/x Clear D_RXRCVY_SS Value
    #define CND003_U3IPSSCFGP_R_TXLBADCLR_SS           BIT8    // 0/x/x/x Clear D_TXLBAD_SS Value
    #define CND003_U3IPSSCFGP_R_TXRCVYCLR_SS           BIT7    // 0/x/x/x Clear D_TXRCVY_SS Value
    #define CND003_U3IPSSCFGP_R_RXRSTOFF_SS            BIT6    // 0/x/x/x Power off PLL and Power in Rx.Detect.Reset State
    #define CND003_U3IPSSCFGP_R_CMPLEXIT_SS            BIT5    // 1b/x/x/x Exit Compliance State when Receiving 2 Polling-LFPS
    #define CND003_U3IPSSCFGP_R_PRXRSTEN_SS            BIT4    // 0/x/x/x Enable RX Reset in Polling State
    #define CND003_U3IPSSCFGP_R_PTXRSTEN_SS            BIT3    // 0/x/x/x Enable TX Reset in Polling State
    #define CND003_U3IPSSCFGP_R_TXSTRST_SS             BIT2    // 0/x/x/x Enable PISO Short Interval Reset
    #define CND003_U3IPSSCFGP_R_PLRTYRYEN_SS           BIT1    // 0/x/x/x Clear RX Polarity Control Signal
    #define CND003_U3IPSSCFGP_R_PLRTYCHGEN_SS          BIT0    // 0/x/x/x Enable Detect TS Polarity Every Time when RX TS1/2
#define CND003_U3IPSSCFGP_SSIP_PORT_LTSSM_ERR_INJECTION_REGS 0xE // SSIP_PORT_LTSSM_Error_Injection_Registers
    #define CND003_U3IPSSCFGP_R_DPHEDBEN_SS    BIT15   // 1b/x/x/x DPH with EDB Function
    #define CND003_U3IPSSCFGP_R_SHSYNCEN_SS    BIT14   // 0/x/x/x Short SYNC Interval Enable
    #define CND003_U3IPSSCFGP_R_DPHLERR_SS     BIT13   // 1b/x/x/x DPH Lenth Replica Field Check
    #define CND003_U3IPSSCFGP_R_TSDCBCHK_SS    BIT12   // 1b/x/x/x Check DC Balance Field of TS OS
    #define CND003_U3IPSSCFGP_R_U12EX2RE_SS    BIT11   // 0/x/x/x Transition Link State from U1/U2 Exit to Recovery.Entry when No LFPS ...
    #define CND003_U3IPSSCFGP_R_U1NOPL_SS      BIT10   // 0/x/x/x UFP U1 State PING LFPS Mask
    #define CND003_U3IPSSCFGP_R_HRNOLI_SS      BIT9    // 0/x/x/x Hot Reset Idle State LI Mask
    #define CND003_U3IPSSCFGP_R_HRNOTS2_SS     BIT8    // 0/x/x/x Hot Reset-Active State TS2 Mask
    #define CND003_U3IPSSCFGP_R_RPNOLFPS_SS    BIT7    // 0/x/x/x U1/U2/U3 State EXIT LFPS Mask
    #define CND003_U3IPSSCFGP_R_RCVYNOLI_SS    BIT6    // 0/x/x/x Recovery-Idle State LI Mask
    #define CND003_U3IPSSCFGP_R_RCVYNOTS2_SS   BIT5    // 0/x/x/x Recovery-Configuration State TS2 Mask
    #define CND003_U3IPSSCFGP_R_RCVYNOTS1_SS   BIT4    // 0/x/x/x Recovery-Active State TS1 Mask
    #define CND003_U3IPSSCFGP_R_PONOLI_SS      BIT3    // 0/x/x/x Polling-Idle State LI Mask
    #define CND003_U3IPSSCFGP_R_PONOTS2_SS     BIT2    // 0/x/x/x Polling-Configuration State TS2 Mask
    #define CND003_U3IPSSCFGP_R_PONOTS1_SS     BIT1    // 0/x/x/x Polling-Active State TS1 Mask
    #define CND003_U3IPSSCFGP_R_PONOLFPS_SS    BIT0    // 0/x/x/x Polling-LFPS State LFPS Mask
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_1 0x10 // SSIP_PORT_PHYLS_Option_Registers_1
    #define CND003_U3IPSSCFGP_R_CPMODE_EN_SS           BIT15                   // 0/x/x/x Register control compliance pattern enable
    #define CND003_U3IPSSCFGP_R_CMPL_SCRMBLENCTL_SS    BIT14                   // 1b/x/x/x Compliance Pattern 0 Scramble Enable Control
    #define CND003_U3IPSSCFGP_R_SMBLCKRTN_SS           BIT13                   // 0/x/x/x Symbol Lock Retain
    #define CND003_U3IPSSCFGP_R_BERCERRTLR_SS          BIT12                   // 1b/x/x/x BERC 1 Symbol Error Tolerate Enable
    #define CND003_U3IPSSCFGP_R_TXD_MASK_EN_SS         BIT11                   // 0/x/x/x Mask Data before LFPS
    #define CND003_U3IPSSCFGP_R_LPBK_SEL_SS            (BIT8 + BIT9 + BIT10)   // 000b/x/x/x Loopback Mode Select
    #define CND003_U3IPSSCFGP_R_EQLZ_TM_SS             (BIT6 + BIT7)           // 10b/x/x/x Equalization Duration Timer Mode
    #define CND003_U3IPSSCFGP_R_EARLY_U1EXITLFPS_SS    BIT5                    // 0/x/x/x Send U1 LFPS Do Not Wait TX P1 to P0 Waiting Time
    #define CND003_U3IPSSCFGP_R_EB_BASE_SS             0x1E                    // 0110b/x/x/x Elastic Buffer Base
    #define CND003_U3IPSSCFGP_R_SKPCNT_MODE_SS         BIT0                    // 0/x/x/x Elastic Buffer SKP Add Display Mode
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_2 0x12 // SSIP_PORT_PHYLS_Option_Registers_2
    #define CND003_U3IPSSCFGP_R_EPHYTST_SS         BIT15                   // 0/x/x/x EPHYTST
    #define CND003_U3IPSSCFGP_R_CPCOMLEADLEN_SS    (BIT12 + BIT13 + BIT14) // 101b/x/x/x Length of COM Symbol Lead Compliance Pattern
    #define CND003_U3IPSSCFGP_R_CP7801DUR_SS       0xF00                   // 0100b/x/x/x Compliance Pattern CP7/CP8 Continuous 0/1 Length
    #define CND003_U3IPSSCFGP_R_CPMODE_SS          0xF8                    // 00000b/x/x/x Register Control Compliance Pattern
    #define CND003_U3IPSSCFGP_R_TSPOLDET_SS        (BIT0 + BIT1 + BIT2)    // 011b/x/x/x TSOS Polarity Inversion Detection Mode
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_3 0x14 // SSIP_PORT_PHYLS_Option_Registers_3
    #define CND003_U3IPSSCFGP_R_DEEMPSETEN_SS      BIT15           // 0/x/x/x De-emphasis Set Enable
    #define CND003_U3IPSSCFGP_R_TXLSW_SS           BIT14           // 0/x/x/x TX Low Swing Mode (Low Power Transmitter)
    #define CND003_U3IPSSCFGP_R_CLRTBEBERRCNT_SS   BIT13           // 0/x/x/x Clear TBTOEB Error Counter
    #define CND003_U3IPSSCFGP_R_POLARDEGLEN_SS     BIT12           // 1b/x/x/x Enable RX TSEQ Polarity Deglitch Function
    #define CND003_U3IPSSCFGP_R_CMWK_TM_SS         (BIT10 + BIT11) // 11b/x/x/x Common Mode Driver Wake Up Timer Mode
    #define CND003_U3IPSSCFGP_R_PASSRCVDET_SS      BIT9            // 0/x/x/x Receiver Detection Force Pass
    #define CND003_U3IPSSCFGP_R_RXP1PHYSTATUS_SS   BIT8            // 1b/x/x/x Include RXP1 EPHY Status in PHYLS_PHYSTATUS
    #define CND003_U3IPSSCFGP_R_PTNGEN_MODE_SS     0xF0            // 0010b/x/x/x Pattern Generation Mode
    #define CND003_U3IPSSCFGP_R_DLYTXEIDLE_SS      BIT3            // 0/x/x/x Delay to Assert TXEIDLEB when Enter Non-p0 State
    #define CND003_U3IPSSCFGP_R_DEEMPSET_SS        BIT2            // 1b/x/x/x De-emphasis Set
    #define CND003_U3IPSSCFGP_R_SKPERRCOR_SS       BIT1            // 1b/x/x/x SKP Symbol Error Correction
    #define CND003_U3IPSSCFGP_R_SKPINTST_SS        BIT0            // 0/x/x/x Insert SKP OS between Pattern Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_4 0x16 // SSIP_PORT_PHYLS_Option_Registers_4
    #define CND003_U3IPSSCFGP_R_RXFULLTSEQCHK_SS   BIT15           // 0/x/x/x RX TSEQ Fully Check Enable
    #define CND003_U3IPSSCFGP_R_TSEQRDCHK_SS       BIT14           // 0/x/x/x RX TSEQ Running Disparity Check
    #define CND003_U3IPSSCFGP_R_TSEQPOLCNT_SS      (BIT12 + BIT13) // 01b/x/x/x Suspend Domain. The Deglitch Number of RX Polarity
    #define CND003_U3IPSSCFGP_R_TRERRCNTCLR_SS     BIT11           // 0/x/x/x TR Loopback ERRCNT Clear
    #define CND003_U3IPSSCFGP_R_LSRTLPBKECCLR_SS   BIT10           // 0/x/x/x LPHY RT Loopback EC Clear
    #define CND003_U3IPSSCFGP_R_RXPWRDNSET_SS      (BIT8 + BIT9)   // 10b/x/x/x LPHY RX Power Status Set
    #define CND003_U3IPSSCFGP_R_RXPWRDNSETEN_SS    BIT7            // 0/x/x/x LPHY RX Power Status Set Enable
    #define CND003_U3IPSSCFGP_R_TXEIDLEBSET_SS     BIT6            // 0/x/x/x TX Electrical Idle Set
    #define CND003_U3IPSSCFGP_R_TXPWRDNSET_SS      (BIT4 + BIT5)   // 10b/x/x/x LPHY TX Power Status Set
    #define CND003_U3IPSSCFGP_R_TXPWRDNSETEN_SS    BIT3            // 0/x/x/x LPHY TX Power Status Set Enable
    #define CND003_U3IPSSCFGP_R_EPHYTSTDYNPMEN_SS  BIT2            // 0/x/x/1b EPHYTST Dynamic Power Enable
    #define CND003_U3IPSSCFGP_R_LSRTLPBKDYNPMEN_SS BIT1            // 0/x/x/1b PHYLS RT Loopback Dynamic Power Enable
    #define CND003_U3IPSSCFGP_R_CMPLNCDYNPMEN_SS   BIT0            // 0/x/x/1b Compliance Pattern Dynamic Power Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_OPTION_REGS_5 0x18 // SSIP_PORT_PHYLS_Option_Registers_5
    #define CND003_U3IPSSCFGP_R_DLRCVY_SS              BIT15           // 0/x/x/x Enable Entry Recovery State when Data Length Error 
    #define CND003_U3IPSSCFGP_R_DPSFERCVY_SS           BIT14           // 1b/x/x/x Enable Entry Recovery State when SDP Error
    #define CND003_U3IPSSCFGP_R_BCNTERR_SS             BIT13           // 0/x/x/x Error BCNT Symbol Injection
    #define CND003_U3IPSSCFGP_R_TXPOL_SS               BIT12           // 0/x/x/x TX Data Polarity Inversion
    #define CND003_U3IPSSCFGP_R_RDERR_SS               BIT11           // 0/x/x/x Error Disparity Symbol Injection
    #define CND003_U3IPSSCFGP_R_EBTBERR_SS             BIT10           // 0/x/x/x Invalid 8b/10b Symbol Injection
    #define CND003_U3IPSSCFGP_R_ERRINTVL_SS            (BIT8 + BIT9)   // 00b/x/x/x Error Symbol Injection Interval
    #define CND003_U3IPSSCFGP_R_TS132FN_SS             BIT7            // 0/x/x/x Enable Finish TS1 Pre 32 Transmitted
    #define CND003_U3IPSSCFGP_R_HRFWINT_SS             BIT6            // 0/x/x/x FW Initial Hot Reset Finish
    #define CND003_U3IPSSCFGP_R_HRFWEN_SS              BIT5            // 0/x/x/x Enable FW Control Hot Reset Finish
    #define CND003_U3IPSSCFGP_R_HRKPEN_SS              BIT4            // 0/x/x/x Enable Hot Reset Keep Function
    #define CND003_U3IPSSCFGP_R_WALIGN_TSEQCOMARE_SS   BIT3            // 0/x/x/x WALIGN Always Detect TSEQ Symbol
    #define CND003_U3IPSSCFGP_R_LPHYACONVDYNPMEN_SS    BIT2            // 0/x/x/1b Reserved ((in VT3518 C0))
    #define CND003_U3IPSSCFGP_R_LPHYWALIGNDYNPMEN_SS   BIT1            // 0/x/x/1b Reserved ((in VT3518 C0))
    #define CND003_U3IPSSCFGP_R_TSEQPOLDETALON_SS      BIT0            // 0/x/x/x Always Turn on TSEQ Polarity Detection
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_1 0x1A // SSIP_PORT_PHYLS_Pattern_Generation_Register_1
    #define CND003_U3IPSSCFGP_R_USRPTN_7_0_SS  0xFF00  // 0/x/x/x User Defined Pattern Byte 0
    #define CND003_U3IPSSCFGP_R_PTNLEN_SS      0xFF    // 10h/x/x/x Pattern Length
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_2 0x1C // SSIP_PORT_PHYLS_Pattern_Generation_Register_2
    #define CND003_U3IPSSCFGP_R_USRPTN_23_8_SS CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_2 // 0/x/x/x User Defined Pattern Byte 1 and 2
#define CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_3 0x1E // SSIP_PORT_PHYLS_Pattern_Generation_Register_3
    #define CND003_U3IPSSCFGP_R_USRPTN_39_24_SS CND003_U3IPSSCFGP_SSIP_PORT_PHYLS_PATTERN_GENERATION_REG_3 // 0/x/x/x User Defined Pattern Byte 3 and 4
#define CND003_U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS 0x20 // SSIP_PORT_PMULINK_Option_Registers
    #define CND003_U3IPSSCFGP_R_BADEDBEN_SS    BIT15   // 0/x/x/x Enable TX Bad EDB
    #define CND003_U3IPSSCFGP_R_CDROFF_SS      BIT14   // 0/x/x/x Trun off CDR when Link Partner Triggered Retrain
    #define CND003_U3IPSSCFGP_R_LCWCRCCHK_SS   BIT13   // 1b/x/x/x Link Command Word CRC5 Checking Control
    #define CND003_U3IPSSCFGP_R_CRC32CHK_SS    BIT12   // 1b/x/x/x Data Payload CRC32 Checking Control
    #define CND003_U3IPSSCFGP_R_CRC5CHK_SS     BIT11   // 1b/x/x/x Header CRC5 Checking Control
    #define CND003_U3IPSSCFGP_R_CRC16CHK_SS    BIT10   // 1b/x/x/x Header CRC16 Checking Control
    #define CND003_U3IPSSCFGP_R_HSQNCHK_SS     BIT9    // 1b/x/x/x Header Sequence Number Control
    #define CND003_U3IPSSCFGP_R_WAIT2SKP_SS    BIT8    // 1b/x/x/x Wait 2 SKP OS Being Scheduled, Only Effective in Training State
    #define CND003_U3IPSSCFGP_R_RCVPOFF_SS     BIT7    // 0/x/x/x Enable Power off in Detection State
    #define CND003_U3IPSSCFGP_R_DFTU2TMOEN_SS  BIT6    // 1b/x/x/x Enable DFP U2 Inactive Timer in U0 State
    #define CND003_U3IPSSCFGP_R_DEVU2TMOFF_SS  BIT5    // 1b/x/x/x U2 Inactive Timer for UFP
    #define CND003_U3IPSSCFGP_R_DEVU1TMOFF_SS  BIT4    // 1b/x/x/x U1 Inactive Timer for UFP
    #define CND003_U3IPSSCFGP_R_U12ITE_SS      BIT3    // 0/x/x/x Enable the U1/2 Inactive Timer Extending when Receiving LXU
    #define CND003_U3IPSSCFGP_R_U2LKPMEN_SS    BIT2    // 1b/x/x/x U2 Link PM Enable
    #define CND003_U3IPSSCFGP_R_U1LKPMEN_SS    BIT1    // 1b/x/x/x U1 Link PM Enable
    #define CND003_U3IPSSCFGP_R_FU3LAU_SS      BIT0    // 0/x/x/x Force SS_PMU Responses LAU when Receiving LGO_U3 No Matter If the TXI...
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 0x22 // SSIP_PORT_LINK_Option_Registers_1
    #define CND003_U3IPSSCFGP_R_EIRTN_SS       BIT15                   // 1b/x/x/x Electrical Idle Triggered Retrain
    #define CND003_U3IPSSCFGP_R_TXMAXLC_SS     (BIT13 + BIT14)         // 11b/x/x/x TX Max Consecutive Link Command Numbers
    #define CND003_U3IPSSCFGP_R_REPISOEN_SS    BIT12                   // 1b/x/x/x Enable PISO Reset when Entry Recovery ?Entry from U0
    #define CND003_U3IPSSCFGP_R_U3PLEN_SS      BIT11                   // 0/x/x/x Enable Polling-LFPS Detection in U3 State
    #define CND003_U3IPSSCFGP_R_UPCTLU3P1_SS   BIT10                   // 0/x/x/x Enable UFP Control DFP U3-TXP1
    #define CND003_U3IPSSCFGP_R_FWDISEN_SS     BIT9                    // 0/x/x/x FW Control Port Disable Generate
    #define CND003_U3IPSSCFGP_R_FWRSTEN_SS     BIT8                    // 0/x/x/x FW Control Warm Reset Ggenerate
    #define CND003_U3IPSSCFGP_R_LCQPRI_SS      (BIT6 + BIT7)           // 00b/x/x/x TX Link Command Priority
    #define CND003_U3IPSSCFGP_R_SKPFREQ_SS     (BIT4 + BIT5)           // 01b/x/x/x Schedule SKP Ordered Set Frequency
    #define CND003_U3IPSSCFGP_R_LCIGNORE_SS    BIT3                    // 0/x/x/x Ignore Link Command when any K-symbol Appears in LCW
    #define CND003_U3IPSSCFGP_R_HRTYMAXT_SS    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Header Retry Max. Times
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_2 0x24 // SSIP_PORT_LINK_Option_Registers_2
    #define CND003_U3IPSSCFGP_R_LKUCLREN_SS    BIT15                   // 1b/x/x/x Enable Link Up / Down Reset AP_FORCEUx
    #define CND003_U3IPSSCFGP_R_HRSTCLREN_SS   BIT14                   // 1b/x/x/x Enable Hot-reset Clear AP_FORCEUx
    #define CND003_U3IPSSCFGP_R_HRSTLKUEN_SS   BIT13                   // 1b/x/x/x Enable Hot-reset Reset Link-up
    #define CND003_U3IPSSCFGP_R_REPTEN_SS      (BIT11 + BIT12)         // 00b/x/x/x Select Pattern Type Generated in Recovery Entry State
    #define CND003_U3IPSSCFGP_R_INSKINHP_SS    BIT10                   // 0/x/x/x Insert K-symbol into HP
    #define CND003_U3IPSSCFGP_R_NOU3RCV_SS     BIT9                    // 0/x/x/x Disable Entry U3_RCVDET State when LFPS Handshake Timeout in U3
    #define CND003_U3IPSSCFGP_R_BDATERR_SS     BIT8                    // 0/x/x/x BDAT OS Error
    #define CND003_U3IPSSCFGP_R_LDNON_SS       BIT7                    // 1b/x/x/x Enable TX to Transmit LDN
    #define CND003_U3IPSSCFGP_R_LRTYLINUM_SS   (BIT5 + BIT6)           // 00b/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_DPTOHPS_SS     (BIT2 + BIT3 + BIT4)    // 000b/x/x/x Data Payload to Next Header Packet Spacing Interval
    #define CND003_U3IPSSCFGP_R_HPTOHPS_SS     (BIT0 + BIT1)           // 00b/x/x/x Header Packet to Next Header Packet Spacing Interval
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_3 0x26 // SSIP_PORT_LINK_Option_Registers_3
    #define CND003_U3IPSSCFGP_R_TMVMAXEN_SS    BIT15           // 0/x/x/x Enable SSLINK Layer Timer Value Max. 
    #define CND003_U3IPSSCFGP_R_HRSTCPLEN_SS   BIT14           // 1b/x/x/x Enable LTSSM Response SC_HRST_CPL in RX.Detect State when No Device ...
    #define CND003_U3IPSSCFGP_R_DNTCHKLF_SS    BIT13           // 0/x/x/x Disable LTSSM Check Link Function Bit Reserved
    #define CND003_U3IPSSCFGP_R_EQLCW_SS       BIT12           // 1b/x/x/x Enable Both Link Command Word Check in the Same Link Command
    #define CND003_U3IPSSCFGP_R_DPSKPLEN_SS    BIT11           // 1b/x/x/x Adding SKP Order Set when DPP Length Is Larger than This Definition
    #define CND003_U3IPSSCFGP_R_DPSKPNUM_SS    (BIT9 + BIT10)  // 00b/x/x/x If Enable adding SKP before DPH Function, These Registers Will Cont...
    #define CND003_U3IPSSCFGP_R_DPSKPEN_SS     BIT8            // 0/x/x/x Enable Adding SKP Order Set before Transmitting DPH
    #define CND003_U3IPSSCFGP_R_FULLLBADEN_SS  BIT7            // 0/x/x/x Enable RUTC Patch when Queue Full to Assert R_LBADEN
    #define CND003_U3IPSSCFGP_R_P2TP3EN_SS     BIT6            // 1b/x/x/x Enable LTSSM Power down Signal to P3 when in P2
    #define CND003_U3IPSSCFGP_R_SILIMEN_SS     BIT5            // 0/x/x/x Enable RCVDET Counter in SS.Inactive State
    #define CND003_U3IPSSCFGP_R_PLEIMAX_SS     BIT4            // 0/x/x/x Enable Polling-LFPS e-idle Max Margin
    #define CND003_U3IPSSCFGP_R_UXTOFLEN_SS    (BIT2 + BIT3)   // 00b/x/x/x Enable U1 TPLL Latency Time
    #define CND003_U3IPSSCFGP_R_INSKINDPP_SS   BIT1            // 0/x/x/x Insert K-symbol into DPP
    #define CND003_U3IPSSCFGP_R_EXCDHP_SS      BIT0            // 0/x/x/x Transmit Exceed Header Packet
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_4 0x28 // SSIP_PORT_LINK_Option_Registers_4
    #define CND003_U3IPSSCFGP_R_RPISORTEN_SS       BIT15           // 0/x/x/x Enable Automatic Reset PISO in P0 when Staying in Recovery a Long Time
    #define CND003_U3IPSSCFGP_R_RACDRP2EN_SS       BIT14           // 0/x/x/x Enable CDR Re-start to P2 in Recovery-Active State
    #define CND003_U3IPSSCFGP_R_PLRTYNUM_SS        (BIT12 + BIT13) // 00b/x/x/x Select Decision Number of Polarity
    #define CND003_U3IPSSCFGP_R_PLRTYCLR_SS        BIT11           // 0/x/x/x Clear RX TS Polarity Control Signal
    #define CND003_U3IPSSCFGP_R_TS1LFEN_SS         BIT10           // 0/x/x/x Link Function Filed in TS1
    #define CND003_U3IPSSCFGP_R_U2INADIS_SS        BIT9            // 0/x/x/x Enable U1 Exit 900ns Timeout when U2 Inactivity Timer Disabled
    #define CND003_U3IPSSCFGP_R_LFPS80EXT_SS       BIT8            // 0/x/x/x Enable 80us LFPS to 131us
    #define CND003_U3IPSSCFGP_R_ACWTS2EN_SS        BIT7            // 0/x/x/x Enable Wait for TS2 in Polling/Recovery-Active 
    #define CND003_U3IPSSCFGP_R_PGUXSEN_SS         BIT6            // 1b/x/x/x Enable UX State Mask SSPGAR Read Strobe
    #define CND003_U3IPSSCFGP_R_LAUDEFEREN_SS      BIT5            // 0/x/x/x Enable PMU_PORT_DEFER Asserted after Receiving LAU
    #define CND003_U3IPSSCFGP_R_SYNCOSDETOPT_SS    BIT4            // 0/x/x/x SYNC OS Error Detect Mode
    #define CND003_U3IPSSCFGP_R_RACDRTEN_SS        BIT3            // 0/x/x/x Enable CDR Retrain in Recovery-Active
    #define CND003_U3IPSSCFGP_R_SKPTS2LI_SS        BIT2            // 0/x/x/x Enable SKP Order Set Not Generated between TS2 and LI
    #define CND003_U3IPSSCFGP_R_REP1LKSEN_SS       BIT1            // 1b/x/x/x Enable Recovery-Entry P1 Link State
    #define CND003_U3IPSSCFGP_R_U0SKPDLY_SS        BIT0            // 0/x/x/x Enable Delay SKP Order Set when Entry U0
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_5 0x2A // SSIP_PORT_LINK_Option_Registers_5
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_02A_SS   BIT15           // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_IPIHRST_SS             BIT14           // 1b/x/x/x Enable IP Type inverter Reset when in Hot Reset State
    #define CND003_U3IPSSCFGP_R_PODYNTPLLEN_SS         BIT13           // 0/x/x/x Reserved ((in VT3515C0))
    #define CND003_U3IPSSCFGP_R_PO1STEXT_SS            BIT12           // 0/x/x/x Extend Polling-LFPS Number Sent after Receiving 1st Polling-LFPS
    #define CND003_U3IPSSCFGP_R_PISORST_SS             BIT11           // 0/x/x/x Enable Firmware Reset PISO in P0
    #define CND003_U3IPSSCFGP_R_ATSIPEN_SS             BIT10           // 1b/x/x/x Enable Automatic Switch IP Type
    #define CND003_U3IPSSCFGP_R_LFPS2TRST_SS           BIT9            // 0/x/x/x Reset LFPS Counter without 2T LFPS
    #define CND003_U3IPSSCFGP_R_U3TXP1EN_SS            BIT8            // 0/x/x/x Enable TX-P1 in U3 State
    #define CND003_U3IPSSCFGP_R_BRKDPP_EDB_LBAD_SS     BIT7            // 1b/x/x/x Insert EDB when Breaking DPP due to LBAD Received
    #define CND003_U3IPSSCFGP_R_BRKDPP_EDB_RTN_SS      BIT6            // 1b/x/x/x Insert EDB when Breaking DPP due to Link Retrain
    #define CND003_U3IPSSCFGP_R_BRKDPP_SS              (BIT4 + BIT5)   // 10b/x/x/x Break DPP Mode
    #define CND003_U3IPSSCFGP_R_U2RXP1EN_SS            BIT3            // 0/x/x/x Enable RX P2 in U2 State
    #define CND003_U3IPSSCFGP_R_U2RCVP0EN_SS           BIT2            // 0/x/x/x Enable TX P0 in U2_RCVDET State
    #define CND003_U3IPSSCFGP_R_BRKDPP_LBAD_SS         BIT1            // 0/x/x/x Break DPP That Is Transmitting when Receive LBAD
    #define CND003_U3IPSSCFGP_R_BRKDPP_LRTN_SS         BIT0            // 0/x/x/x Break DPP That Is Transmitting when Self Retrain
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_6 0x2C // SSIP_PORT_LINK_Option_Registers_6
    #define CND003_U3IPSSCFGP_R_DATACHG_SS     (BIT14 + BIT15) // 0/x/x/x Change the Last Data from SSPGAR
    #define CND003_U3IPSSCFGP_R_HBEDBEND_SS    BIT13           // 0/x/x/x Truncate DP Payload with END Framing when Upper Layer Uses HB_DPPEDB
    #define CND003_U3IPSSCFGP_R_LIEXTEN_SS     BIT12           // 0/x/x/x Extend Transmitted Logic Idle in LI State
    #define CND003_U3IPSSCFGP_R_VPCHKL_SS      BIT11           // 0/x/x/x Enable VLI Product Check in LDN/LUP
    #define CND003_U3IPSSCFGP_R_VPCHKT_SS      BIT10           // 0/x/x/x Enable VLI Product Check in TieBreaker
    #define CND003_U3IPSSCFGP_R_LDTMO2SI_SS    BIT9            // 0/x/x/x Enable LTSSM to SS.Inactive State when LCRD Timeout
    #define CND003_U3IPSSCFGP_R_HNORLI_SS      BIT8            // 0/x/x/x Mask Logic Idle in Hot Reset-Exit State
    #define CND003_U3IPSSCFGP_R_HNORTS2_SS     BIT7            // 0/x/x/x Mask TS2 in Hot Reset-Active State
    #define CND003_U3IPSSCFGP_R_RNORLI_SS      BIT6            // 0/x/x/x Mask Logic Idle in Recovery State
    #define CND003_U3IPSSCFGP_R_RNORTS2_SS     BIT5            // 0/x/x/x Mask TS2 in Recovery State
    #define CND003_U3IPSSCFGP_R_RNORTS1_SS     BIT4            // 0/x/x/x Mask TS1 in Recovery State
    #define CND003_U3IPSSCFGP_R_PNORLI_SS      BIT3            // 0/x/x/x Mask Logic Idle in Polling State
    #define CND003_U3IPSSCFGP_R_PNORTS2_SS     BIT2            // 0/x/x/x Mask TS2 in Polling State
    #define CND003_U3IPSSCFGP_R_PNORTS1_SS     BIT1            // 0/x/x/x Mask TS1 in Polling State
    #define CND003_U3IPSSCFGP_R_TMVEXTEN_SS    BIT0            // 1b/x/x/x Extend Link Layer Protocol Timer
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_7 0x2E // SSIP_PORT_LINK_Option_Registers_7
    #define CND003_U3IPSSCFGP_R_NOLRTY_SS          BIT15   // 0/x/x/x No LRTY
    #define CND003_U3IPSSCFGP_R_NOLPMA_SS          BIT14   // 0/x/x/x No LPMA
    #define CND003_U3IPSSCFGP_R_NOLAXU_SS          BIT13   // 0/x/x/x No LAU/LXU
    #define CND003_U3IPSSCFGP_R_NOLCRD_SS          BIT12   // 0/x/x/x No LCRD_x
    #define CND003_U3IPSSCFGP_R_NOLGOOD_SS         BIT11   // 0/x/x/x No LGOOD_n and LBAD
    #define CND003_U3IPSSCFGP_R_LBADEN_SS          BIT10   // 0/x/x/x LBAD Enable
    #define CND003_U3IPSSCFGP_R_LCMD2CRC5ERR_SS    BIT9    // 0/x/x/x Link Command Word 2 CRC5 Error
    #define CND003_U3IPSSCFGP_R_LCMD1CRC5ERR_SS    BIT8    // 0/x/x/x Link Command Word 1 CRC5 Error
    #define CND003_U3IPSSCFGP_R_RECEDB_SS          BIT7    // 1b/x/x/x Enable DP with EDB when Entry Recovery State
    #define CND003_U3IPSSCFGP_R_RETCDP_SS          BIT6    // 0/x/x/x Enable DP Truncated when Entry Recovery State
    #define CND003_U3IPSSCFGP_R_BLKTSCHK_SS        BIT5    // 0/x/x/x Enable Block Header Check for TS OS
    #define CND003_U3IPSSCFGP_R_MASKIDLE_SS        BIT4    // 1b/x/x/x Mask APISIDLE in Ux Power State
    #define CND003_U3IPSSCFGP_R_CMPCTLEN_SS        BIT3    // 1b/x/x/x Enable CTE Compliance Control Function
    #define CND003_U3IPSSCFGP_R_UFPU1DET_SS        BIT2    // 0/x/x/x Enable UFP Detection in U1
    #define CND003_U3IPSSCFGP_R_LCRDSTMO_SS        BIT1    // 0/x/x/x Shorten the LCRD Timeout Value to 5u
    #define CND003_U3IPSSCFGP_R_FORCEMUX_SS        BIT0    // 0/x/x/x Mask FORCE U1/2
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_ERR_INJECTION_REGS_1 0x30 // SSIP_PORT_LINK_Error_Injection_Registers_1
    #define CND003_U3IPSSCFGP_R_TS2ERR_SS      BIT15                   // 0/x/x/x TS2 OS Error
    #define CND003_U3IPSSCFGP_R_TS1ERR_SS      BIT14                   // 0/x/x/x TS1 OS Error
    #define CND003_U3IPSSCFGP_R_CRDADVERR_SS   (BIT11 + BIT12 + BIT13) // 000b/x/x/x Rx Header Buffer Credit Advertisement Error
    #define CND003_U3IPSSCFGP_R_SQNADVERR_SS   (BIT8 + BIT9 + BIT10)   // 000b/x/x/x Header Sequence Number Advertisement Error
    #define CND003_U3IPSSCFGP_R_BERCERR_SS     BIT7                    // 0/x/x/x BERC OS Error
    #define CND003_U3IPSSCFGP_R_BRSTERR_SS     BIT6                    // 0/x/x/x BRST OS Error
    #define CND003_U3IPSSCFGP_R_SKPERR_SS      BIT5                    // 0/x/x/x SKP OS Error
    #define CND003_U3IPSSCFGP_R_LCRDERR_SS     BIT4                    // 0/x/x/x LCRD_x Error
    #define CND003_U3IPSSCFGP_R_LGOODERR_SS    BIT3                    // 0/x/x/x LGOOD_n Error
    #define CND003_U3IPSSCFGP_R_NOCRDADV_SS    BIT2                    // 0/x/x/x No Rx Header Buffer Credit Advertisement
    #define CND003_U3IPSSCFGP_R_NOSQNADV_SS    BIT1                    // 0/x/x/x No Header Sequence Number Advertisement
    #define CND003_U3IPSSCFGP_R_NOLUP_SS       BIT0                    // 0/x/x/x No LUP
#define CND003_U3IPSSCFGP_SSIP_PORT_LINK_ERR_INJECTION_REGS_2 0x32 // SSIP_PORT_LINK_Error_Injection_Registers_2
    #define CND003_U3IPSSCFGP_R_SLCFRMERR_SS   0xF000  // 0000b/x/x/x SLC Framing Error
    #define CND003_U3IPSSCFGP_R_ENDFRMERR_SS   0xF00   // 0000b/x/x/x END Framing Error
    #define CND003_U3IPSSCFGP_R_SDPFRMERR_SS   0xF0    // 0000b/x/x/x SDP Framing Error
    #define CND003_U3IPSSCFGP_R_SHPFRMERR_SS   0xF     // 0000b/x/x/x SHP Framing Error
#define CND003_U3IPSSCFGP_SSIP_PORT_COMPLIANCELFPS_PRBS_OPTION_REG 0x34 // SSIP_PORT_ComplianceLFPS_PRBS_Option_Register
    #define CND003_U3IPSSCFGP_R_SDS2IEN_SS         BIT15                   // 0/x/x/x Enable Transition State when Receiving SDS
    #define CND003_U3IPSSCFGP_R_NO20PL_SS          BIT14                   // 0/x/x/x No 20 PL Transmitted
    #define CND003_U3IPSSCFGP_R_PLES16DIS_SS       BIT13                   // 0/x/x/x Polling.LFPS E-ilde Enable 16-PL Received
    #define CND003_U3IPSSCFGP_R_PHYCNTEXT_SS       BIT12                   // 0/x/x/x PHY Counter Extend
    #define CND003_U3IPSSCFGP_R_LDILFSRV_SS        BIT11                   // 0/x/x/x Enable to Load LFSR Initial Value
    #define CND003_U3IPSSCFGP_R_PRBSRST_SS         BIT10                   // 0/x/x/x Reset LFSR Value in PRBS
    #define CND003_U3IPSSCFGP_R_PRBSEN_SS          BIT9                    // 0/x/x/x Enable PRBS Function
    #define CND003_U3IPSSCFGP_R_PRBS931_SS         BIT8                    // 0/x/x/x Select PRBS9 or PRBS31 Function
    #define CND003_U3IPSSCFGP_R_RXEBUFADJOPT_SS    BIT7                    // 1b/x/x/x RX EBUF Adjust Mode
    #define CND003_U3IPSSCFGP_R_NOMAXCMPINLFPS_SS  BIT6                    // 1b/x/x/x No High Bound Limit for Ping LFPS in Compliance Mode
    #define CND003_U3IPSSCFGP_R_CMPLFPS_H_SS       (BIT3 + BIT4 + BIT5)    // 010b/x/x/x The Ping LFPS Period High Bound in Compliance Mode
    #define CND003_U3IPSSCFGP_R_CMPLFPS_L_SS       (BIT0 + BIT1 + BIT2)    // 010b/x/x/x The Ping LFPS Period Low Bound in Compliance Mode
#define CND003_U3IPSSCFGP_SSIP_PORT_PRBS_OPTION_REGS_1 0x36 // SSIP_PORT_PRBS_Option_Registers_1
    #define CND003_U3IPSSCFGP_R_ILFSRV_15_0_SS CND003_U3IPSSCFGP_SSIP_PORT_PRBS_OPTION_REGS_1 // 0/x/x/x Initial LFSR Value
#define CND003_U3IPSSCFGP_SSIP_PORT_PRBS_OPTION_REGS_2 0x38 // SSIP_PORT_PRBS_Option_Registers_2
    #define CND003_U3IPSSCFGP_R_DPTPHDL_SS         BIT15   // 0/x/x/x Discard TP when Receiving a DP with TPH and without Deferred
    #define CND003_U3IPSSCFGP_R_ILFSRV_30_16_SS    0x7FFF  // 0/x/x/x Initial LFSR Value
#define CND003_U3IPSSCFGP_SSIP_PORT_LPBK_ERR_CNTER_REGS 0x3A // SSIP_PORT_LPBK_Error_Counter_Registers
    #define CND003_U3IPSSCFGP_D_LPBSLV_LCEC_SS 0xFF00  // HwInit/x/x/x LPBK Slave Error Counter
    #define CND003_U3IPSSCFGP_D_LPBMST_RMEC_SS 0xFF    // HwInit/x/x/x LPBK Master Remote Error Counter
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHYTST_ERR_CNTER_REGS 0x3C // SSIP_PORT_EPHYTST_Error_Counter_Registers
    #define CND003_U3IPSSCFGP_D_EPHYTST_ERRCNT_SS CND003_U3IPSSCFGP_SSIP_PORT_EPHYTST_ERR_CNTER_REGS // HwInit/x/x/x Display the Data Mismatch Count Number when Do EPHYBIST
#define CND003_U3IPSSCFGP_SSIP_PORT_LPBKMST_LOCAL_ERR_CNTER_REGS 0x3E // SSIP_PORT_LPBKMST_Local_Error_Counter_Registers
    #define CND003_U3IPSSCFGP_D_LPBMST_LCEC_SS CND003_U3IPSSCFGP_SSIP_PORT_LPBKMST_LOCAL_ERR_CNTER_REGS // HwInit/x/x/x LPBK Master Local Error Counter
#define CND003_U3IPSSCFGP_SSIP_PORT_TX_RECOVERY_CNTER_REGS 0x40 // SSIP_PORT_TX_Recovery_Counter_Registers
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_040_SS    BIT15   // HwInit/x/x/x Reserved
    #define CND003_U3IPSSCFGP_D_TXRCVY_SS                  0x7FFF  // HwInit/x/x/x The number LTSSM Go to Recovery
#define CND003_U3IPSSCFGP_SSIP_PORT_TX_LBAD_CNTER_REGS 0x42 // SSIP_PORT_TX_LBAD_Counter_Registers
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_042_SS    BIT15   // HwInit/x/x/x Reserved
    #define CND003_U3IPSSCFGP_D_TXLBAD_SS                  0x7FFF  // HwInit/x/x/x TX LBAD Counter
#define CND003_U3IPSSCFGP_SSIP_PORT_RX_RECOVERY_CNTER_REGS 0x44 // SSIP_PORT_RX_Recovery_Counter_Registers
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_044_SS    BIT15   // HwInit/x/x/x Reserved
    #define CND003_U3IPSSCFGP_D_RXRCVY_SS                  0x7FFF  // HwInit/x/x/x The Number That Link Partner Go to Recovery
#define CND003_U3IPSSCFGP_SSIP_PORT_RX_LBAD_CNTER_REGS 0x46 // SSIP_PORT_RX_LBAD_Counter_Registers
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_046_SS    BIT15   // HwInit/x/x/x Reserved
    #define CND003_U3IPSSCFGP_D_RXLBAD_SS                  0x7FFF  // HwInit/x/x/x RX LBAD Counter
#define CND003_U3IPSSCFGP_SSIP_PORT_RX_TSEQ_CNTER_REGS 0x48 // SSIP_PORT_RX_TSEQ_Counter_Registers
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_048_SS    BIT15   // HwInit/x/x/x Reserved
    #define CND003_U3IPSSCFGP_D_RXTSEQ_SS                  0x7FFF  // HwInit/x/x/x RX 5G TSEQ Counter
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_1 0x4A // SSIP_PORT_NEW_Register_1 ((VT3515A0))
    #define CND003_U3IPSSCFGP_R_PHYSCHK_SS     BIT15   // 0/x/x/x PHY Single Check
    #define CND003_U3IPSSCFGP_R_SCDSCHK_SS     BIT14   // 0/x/x/x SCD Single Check
    #define CND003_U3IPSSCFGP_R_TRPLEXT_SS     BIT13   // 0/x/x/x T-repeat Low Extend
    #define CND003_U3IPSSCFGP_R_TRPHEXT_SS     BIT12   // 0/x/x/x T-repeat High Extend
    #define CND003_U3IPSSCFGP_R_NO1P85USHB_SS  BIT11   // 0/x/x/x No 1.85us High Boundary
    #define CND003_U3IPSSCFGP_R_NO2P2USHB_SS   BIT10   // 0/x/x/x No 2.2us High Boundary
    #define CND003_U3IPSSCFGP_R_NO2USLB_SS     BIT9    // 0/x/x/x No 2us Low Boundary
    #define CND003_U3IPSSCFGP_R_NO14USHB_SS    BIT8    // 0/x/x/x No 14us High Boundary
    #define CND003_U3IPSSCFGP_R_NO1USHB_SS     BIT7    // 0/x/x/x No 1us High Boundary
    #define CND003_U3IPSSCFGP_R_DCSRATE_SS     BIT6    // 0/x/x/x Decrease the Link Speed to 5G
    #define CND003_U3IPSSCFGP_R_PLOLDSET_SS    BIT5    // 0/x/x/x Polling.LFPS Switch to Old Setting
    #define CND003_U3IPSSCFGP_R_PHYCRSHT_SS    BIT4    // 0/x/x/x PHY Capability Short
    #define CND003_U3IPSSCFGP_R_PHYCREXT_SS    BIT3    // 0/x/x/x PHY Capability Extend
    #define CND003_U3IPSSCFGP_R_SCDL1SHT_SS    BIT2    // 1b/x/x/x SCD L1 Short
    #define CND003_U3IPSSCFGP_R_SCDL0EXT_SS    BIT1    // 1b/x/x/x SCD L0 Extend
    #define CND003_U3IPSSCFGP_R_PLTMOEN_SS     BIT0    // 1b/x/x/x Polling State Timeout Counter
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_2 0x4C // SSIP_PORT_NEW_Register_2 ((VT3515A0))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_04C_SS    0xF800  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_DEEMPH_FW_SS               BIT10   // 0/x/x/x FW Set DEEMPH
    #define CND003_U3IPSSCFGP_R_PRESHOOT_FW_SS             BIT9    // 0/x/x/x FW Set PRESHOOT
    #define CND003_U3IPSSCFGP_R_CP13TOCP16_FWSET_EN_SS     BIT8    // 0/x/x/x FW Set CP13 ~CP16
    #define CND003_U3IPSSCFGP_R_EB_BASE_10G_SS             0xF0    // 1000b/x/x/x Elastic Buffer Base of 10G
    #define CND003_U3IPSSCFGP_R_GDPHLERR_SS                BIT3    // 1b/x/x/x Increase Soft Error Counter when Good DPH with Length Replica Error
    #define CND003_U3IPSSCFGP_R_SSPTS2SKP_SS               BIT2    // 0/x/x/x Wait to Generate 2 SKP when TS OS in SSP Mode
    #define CND003_U3IPSSCFGP_R_BHERR_SS                   BIT1    // 1b/x/x/x Enable Link Retrained when Uncorrectable Block Header Detected
    #define CND003_U3IPSSCFGP_R_DISISKP_SS                 BIT0    // 0/x/x/x Disable Inserting SKP OS
#define CND003_U3IPSSCFGP_SSIP_PORT_SOFTERRCNTER_REG 0x4E // SSIP_PORT_SoftErrorCounter_Register
    #define CND003_U3IPSSCFGP_D_SSP_SFERRCNT_SS CND003_U3IPSSCFGP_SSIP_PORT_SOFTERRCNTER_REG // HwInit/x/x/x Soft error Counter Value
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_3 0x50 // SSIP_PORT_NEW_Register_3 ((VT3515A0))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_050_SS   0xFF80  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_DWPCLR_SS              BIT6    // 0/x/x/x Device Mode Warm Reset without PCFG
    #define CND003_U3IPSSCFGP_R_HDRLOC_SS              BIT5    // 0/x/x/x Reserved in ((VT3515 C0))
    #define CND003_U3IPSSCFGP_R_SYNC_SKP_PATCH_DIS_SS  BIT4    // 0/x/x/x Enable SYNC and SKP Patch
    #define CND003_U3IPSSCFGP_R_SSPLPBK_SS             BIT3    // 0/x/x/x SSP Loopback Mode Enable
    #define CND003_U3IPSSCFGP_R_TSOSDETOPT_SS          BIT2    // 0/x/x/x Detect Header Block in TS OS
    #define CND003_U3IPSSCFGP_R_CMPHDRC_SS             BIT1    // 1b/x/x/x Reserved in ((VT3515 C0))
    #define CND003_U3IPSSCFGP_R_CPCOMLEAD_SS           BIT0    // 0/x/x/x COM Symbol Lead Compliance Pattern Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_4 0x52 // SSIP_PORT_NEW_Register_4 ((VT3515B0))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_052_SS   0xFF80  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_MSDPRDY_SS             BIT6    // 0/x/x/x Mask RX DP Ready
    #define CND003_U3IPSSCFGP_R_STOP_ADD_IF_NO_VLD_SS  BIT5    // 0/x/x/x Stop Adding Pointer when There Is No Valid Signal in RXEBUF
    #define CND003_U3IPSSCFGP_R_R2TLPBK_ECEN_SS        BIT4    // 0/x/x/x LPHY R2T Loopback
    #define CND003_U3IPSSCFGP_R_EQTNEN_SS              BIT3    // 0/x/x/x Option Register for LPU_EQTNEN
    #define CND003_U3IPSSCFGP_R_EQTNRST_SS             BIT2    // 1b/x/x/x Option Register for LPU_EQTNRST
    #define CND003_U3IPSSCFGP_R_NOCPLSCD_SS            BIT1    // 0/x/x/x Transition State without Complete SCD
    #define CND003_U3IPSSCFGP_R_EQTNSETEN_SS           BIT0    // 0/x/x/x Option to Manual Control LPU_EQTNRSTB and LPU_EQTNEN
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_5 0x54 // SSIP_PORT_NEW_Register_5 ((VT3515C0))
    #define CND003_U3IPSSCFGP_R_RXDBGSEL_SS    0xF000  // 0/x/x/x RXBUF RXD Debug Signal Selection
    #define CND003_U3IPSSCFGP_R_USB3TXINV_SS   BIT11   // 0/x/x/x Invert TXD to EPHY
    #define CND003_U3IPSSCFGP_R_RXDLFPSDET_SS  BIT10   // 0/x/x/x Disable RX LFPS during Suspend
    #define CND003_U3IPSSCFGP_R_SSPEN_SS       BIT9    // 0/x/x/x SSP Mode Enable Control by SSCFG
    #define CND003_U3IPSSCFGP_R_CDRNVLDR_SS    BIT8    // 0/x/x/x Enable CDR Reset when Receive No Valid LI, TS1, TS2 in Polling or Rec...
    #define CND003_U3IPSSCFGP_R_CDRINTVR_SS    BIT7    // 0/x/x/x Enable CDR Reset when Receive LFPS in Polling or Recovery State
    #define CND003_U3IPSSCFGP_R_DSPRGEN_SS     BIT6    // 0/x/x/x DFP MCU Directly Warm Reset Enable
    #define CND003_U3IPSSCFGP_R_LOCALLPBK_SS   BIT5    // 0/x/x/x For USB3 Re-timer, Host Does Not Need This Function
    #define CND003_U3IPSSCFGP_R_PTMDL_SS       BIT4    // 0/x/x/x PTM Delay Bit Mask when Manual Mode
    #define CND003_U3IPSSCFGP_R_PTMRSP_SS      BIT3    // 0/x/x/x Enable Manual Mode PTM Response
    #define CND003_U3IPSSCFGP_R_PMRSTSW_SS     BIT2    // 0/x/x/x Fix U1/U2 Timer Reset Bug, Reset U1/U2 Timer when PL Pop DP or TP (wi...
    #define CND003_U3IPSSCFGP_R_LDMREQ_SS      BIT1    // 0/x/x/x LDM Manual Mode Send Request
    #define CND003_U3IPSSCFGP_R_LDMEN_SS       BIT0    // 0/x/x/x LDM Manual Mode Function Enable in SSPIP
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_6 0x56 // SSIP_PORT_NEW_Register_6 ((VT3515C0))
    #define CND003_U3IPSSCFGP_R_U2TMRV_SS  0xFF00  // 01h/x/x/x U2 State 256us Timer Value
    #define CND003_U3IPSSCFGP_R_U1TMRV_SS  0xFF    // 7Ch/x/x/x U1 state 1us timer value
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_7 0x58 // SSIP_PORT_NEW_Register_7 ((VT3515C0))
    #define CND003_U3IPSSCFGP_R_WLGN_TSDET_EN_SS   BIT15           // 0/x/x/x Enable TS1/TS2 detection in WALIGN
    #define CND003_U3IPSSCFGP_R_RXP0ENTRYTMR_SS    0x7800          // 0100b/x/x/x Wait for a Period of Time after Entry of RXP0
    #define CND003_U3IPSSCFGP_R_LPBKSIEXT_SS       BIT10           // 0/x/x/x The Interval of Inserting SYNC in SSP LPBK Mode
    #define CND003_U3IPSSCFGP_R_LPBKCNTCLR_SS      BIT9            // 0/x/x/x Clear Error Counter of SSP LPBK
    #define CND003_U3IPSSCFGP_R_LPBKCNTRO_SS       BIT8            // 0/x/x/x Enable Roll over of LPBK Counter
    #define CND003_U3IPSSCFGP_R_LPBKCNTEN_SS       BIT7            // 0/x/x/x Enable Error Counter Increased when No Pop
    #define CND003_U3IPSSCFGP_R_LKREBFERR_SS       BIT6            // 0/x/x/x Retrain Link when RXEBUF Error Occurred
    #define CND003_U3IPSSCFGP_R_LPBKSYNC_SS        BIT5            // 0/x/x/x Insert SYNC OS in SSP LPBK Mode
    #define CND003_U3IPSSCFGP_R_SSPBRKDPP_SS       (BIT3 + BIT4)   // 00b/x/x/x Enable Break DPP Function
    #define CND003_U3IPSSCFGP_R_SYNCBFTS_SS        BIT2            // 0/x/x/x Insert SYNC OS before Transmitting TS OS
    #define CND003_U3IPSSCFGP_R_EQDISKP_SS         BIT1            // 0/x/x/x Disable SKP OS during TSEQ
    #define CND003_U3IPSSCFGP_R_RSTCLR_SS          BIT0            // 0/x/x/x Enable Synchronous Reset in TX Path when Ready to Gen2
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_8 0x5A // SSIP_PORT_NEW_Register_8 ((VT3515C0))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_05A_SS   0xF800          // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_MSDPFRCV_SS            BIT10           // 0/x/x/x Enable DPP End Lost to Recovery State
    #define CND003_U3IPSSCFGP_R_UNLCKPOP_SS            BIT9            // 0/x/x/x Enable POP Data from LPHY when Symbol Lock Lost in U0 State
    #define CND003_U3IPSSCFGP_R_EQSKPSET_SS            BIT8            // 0/x/x/x Set SKP Interval in TSEQ State
    #define CND003_U3IPSSCFGP_R_DPHEDBAD_SS            BIT7            // 0/x/x/x When DPH with EDB Condition Occurred, RXDBAD Will Be Asserted
    #define CND003_U3IPSSCFGP_R_PLREQALWS_SS           BIT6            // 0/x/x/x Enable Always Allow Request from PL to Link Layer
    #define CND003_U3IPSSCFGP_R_TXDLBEN_SS             BIT5            // 0/x/x/x Enable DLB Queue Function
    #define CND003_U3IPSSCFGP_R_ALSRTYDPP_SS           BIT4            // 0/x/x/x Always Retry DPP Payload of SSP Mode when this SP Needed to Be Retried.
    #define CND003_U3IPSSCFGP_R_SSPRTYDPP_SS           BIT3            // 0/x/x/x Re-transmit DPP when DP Retry
    #define CND003_U3IPSSCFGP_R_RBFDBGSEL_SS           (BIT1 + BIT2)   // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_TS1TS2_DET_LOC_SS      BIT0            // 0/x/x/x Detect the Location of the TS1/2 toAalign the Block in LPHY
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_9 0x5C // SSIP_PORT_NEW_Register_9 ((VT3483 and VT3456))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_05C_SS   0xFF00  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_RXHZ_DIS_SEL_SS        BIT7    // 0/x/x/x Select Which One Control RXHZ_DISEN Signal
    #define CND003_U3IPSSCFGP_R_EPHYTST_PSTBEB_SS      BIT6    // 0/x/x/x Gating the TBTOEB Data to up Layer T ((VT3456))
    #define CND003_U3IPSSCFGP_R_HRSTS12TMOEN_SS        BIT5    // 0/x/x/x Clear PR when Polling/Recovery Timeout ((VT3456))
    #define CND003_U3IPSSCFGP_R_HRSTCPLEN_NEW_SS       BIT4    // 0/x/x/x Enable LTSSM Response SC_HRST_CPL when Device Disconnect ((VT3456))
    #define CND003_U3IPSSCFGP_R_EMTYPASSEN_SS          BIT3    // 0/x/x/x Enable TX DPH and TPH when TX Header Queue Is Empty ((VT3483))
    #define CND003_U3IPSSCFGP_R_PASSDPEN_SS            BIT2    // 0/x/x/x Enable TX DPH ((VT3483))
    #define CND003_U3IPSSCFGP_R_PASSTPEN_SS            BIT1    // 0/x/x/x Enable TX TPH ((VT3483))
    #define CND003_U3IPSSCFGP_R_TXREQACK_EN_SS         BIT0    // 0/x/x/x Enable R_PASSTPEN_SS, R_PASSDPEN_SS and R_EMTYPASSEN_SS ((VT3483))
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_10 0x5E // SSIP_PORT_NEW_Register_10 ((CND003 NEW))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_05E_SS   0xFC00  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_UXDFPLAUEN_SS          BIT9    // 0/x/x/x Enable DFP Send LAU when RX LGO_Ux
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_SS         BIT8    // 0/x/x/x SSP 10G BIST User Mode Enable
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_MODE_SS    0xF0    // 0/x/x/x SSP 10G BIST User Mode
    #define CND003_U3IPSSCFGP_R_POLFPS_EXT_SS          BIT3    // 1b/x/x/x Enable Send Polling LFPS until Device Does?t Send LFPS
    #define CND003_U3IPSSCFGP_R_LPHY_ALIGN_SS          BIT2    // 0/x/x/x Enable LPHY Lock
    #define CND003_U3IPSSCFGP_R_APFORCEU3_MSK_SS       BIT1    // 0/x/x/x Mask AP_FORCEU3
    #define CND003_U3IPSSCFGP_R_APISIDLE_MSK_SS        BIT0    // 0/x/x/x Mask APISIDEL Signal
#define CND003_U3IPSSCFGP_SSIP_10B_DATA_ERR_CNTER 0x60 // SSIP_10B_DATA_ERR_COUNTER
    #define CND003_U3IPSSCFGP_D_SSP_LPBK_USRINDN_SS    BIT15   // HwInit/x/x/x SSP 10G BIST User Mode Initial Done
    #define CND003_U3IPSSCFGP_D_TBEBERRCNT_SS          0x7FFF  // HwInit/x/x/x RX 10B Data Error Counter
#define CND003_U3IPSSCFGP_SSIP_LN_RX_ERR 0x62 // SSIP_LN_RX_ERROR
    #define CND003_U3IPSSCFGP_D_LNERRCNT_SS CND003_U3IPSSCFGP_SSIP_LN_RX_ERR // HwInit/x/x/x Link Error Counter, Add 1 When:
#define CND003_U3IPSSCFGP_SSIP_R2T_LPBK_MST_ERR 0x64 // SSIP_ R2T_LPBK_MST_ERROR
    #define CND003_U3IPSSCFGP_D_SSP_LPBKERR_SS CND003_U3IPSSCFGP_SSIP_R2T_LPBK_MST_ERR // HwInit/x/x/x Error Counter Add 1 Per 32 Bits if RX Is Not LI or SYNC Symbol
#define CND003_U3IPSSCFGP_SSIP_LDM_LMP_RESPONSE_DELAY 0x66 // SSIP_LDM_LMP_RESPONSE_DELAY
    #define CND003_U3IPSSCFGP_D_SSP_LPBKINDN_SS    BIT15   // HwInit/x/x/x SSP TX to RX Loopback Initial Done
    #define CND003_U3IPSSCFGP_D_SSP_LPHYULK_SS     BIT14   // HwInit/x/x/x SSP LPHY Unlock
    #define CND003_U3IPSSCFGP_D_SSP_LPBKULK_SS     BIT13   // HwInit/x/x/x LPHY Unlock When do SSP TX to RX Loopback
    #define CND003_U3IPSSCFGP_D_RXPOLINV_SS        BIT12   // HwInit/x/x/x RX Polarity Status
    #define CND003_U3IPSSCFGP_D_LDMDLY_SS          0xFFF   // HwInit/x/x/x Response Delay Value of LDM LMP
#define CND003_U3IPSSCFGP_SSIP_STA 0x68 // SSIP_STATUS
    #define CND003_U3IPSSCFGP_LTSSM_SS             0xFE00  // HwInit/x/x/x USB3.1 LINK STATE
    #define CND003_U3IPSSCFGP_D_CP912_FLAG_SS      BIT8    // HwInit/x/x/x TX CP9 to CP12
    #define CND003_U3IPSSCFGP_D_CP_VALUE_SS        0xF8    // HwInit/x/x/x TX CP Pattern Mode
    #define CND003_U3IPSSCFGP_D_LPBMST_LCECERR_SS  BIT2    // HwInit/x/x/x LPBK Master Local Error Counter Is Not 0
    #define CND003_U3IPSSCFGP_D_EPHYBISTER_SS      BIT1    // HwInit/x/x/x Display the Data Mismatch Happened When Do EPHYBIST
    #define CND003_U3IPSSCFGP_D_RMACWK_SS          BIT0    // HwInit/x/x/x Remote Link Partner Actively Issues Wake up to Resume Link. (Sta...
#define CND003_U3IPSSCFGP_SSIP_PORT_NEW_REG_10_Z1 0x6A // SSIP_PORT_NEW_Register_10 ((VT3518_C0))
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_06A_SS   (BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_PMTMEXT_SS             BIT13           // 0/x/x/x Extend the Timeout Value of PM_LC_timer to 6us
    #define CND003_U3IPSSCFGP_R_U1STMEXT_SS            BIT12           // 0/x/x/x Extend Value of the U1 Short Timeout to 6us
    #define CND003_U3IPSSCFGP_R_PHDTMEXT_SS            BIT11           // 0/x/x/x Extend the Timeout Value of Pending Header Timer to 30us
    #define CND003_U3IPSSCFGP_R_DLYTXOFT_SS            (BIT9 + BIT10)  // 01b/x/x/x Delay TX Off Time
    #define CND003_U3IPSSCFGP_R_P3_TXHZ_SS             BIT8            // 0/x/x/x Enable TXHZ When in TX P2 State
    #define CND003_U3IPSSCFGP_R_P2_TXHZ_SS             BIT7            // 0/x/x/x Enable TXHZ When in TX P3 State
    #define CND003_U3IPSSCFGP_R_ADVNDONE_SS            BIT6            // 0/x/x/x Enable the Arc of Active to Idle When Advertisement Not Done
    #define CND003_U3IPSSCFGP_R_PLUSRST_SS             BIT5            // 1b/x/x/x Disable Switch to SS When Receiving SCD1 in LFPSPLUS
    #define CND003_U3IPSSCFGP_R_DPABORT_SS             BIT4            // 0/x/x/x Enable DP Abort Function Only Used for Hub Mode
    #define CND003_U3IPSSCFGP_R_PLEIMIN_SS             BIT3            // 0/x/x/x Minimal the E-ilde Interval to 20us in Polling.LFPS
    #define CND003_U3IPSSCFGP_R_TESTPWR_SS             BIT2            // 0/x/x/x Enbale Power State Auto Tuning for Test Mode
    #define CND003_U3IPSSCFGP_R_PKTDLYEN_SS            BIT1            // 0/x/x/x Delay to Transfer Packet after Advertisement Done
    #define CND003_U3IPSSCFGP_R_LSTPOPEN_SS            BIT0            // 0/x/x/x Assert DBXLSTPOP When Nullified Packet Only for Hub Mode
#define CND003_U3IPSSCFGP_SSIP_COMMAN_RESERVED_6C 0x6C // SSIP_Comman_Reserved_6C
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_06C_SS CND003_U3IPSSCFGP_SSIP_COMMAN_RESERVED_6C // 0/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSIP_COMMAN_RESERVED_6E 0x6E // SSIP_Comman_Reserved_6E
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_RO_06E_SS CND003_U3IPSSCFGP_SSIP_COMMAN_RESERVED_6E // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_1 0x70 // SSP 10G BIST user mode pattern Word 1
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W1_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_1 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 1
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_2 0x72 // SSP 10G BIST user mode pattern Word 2
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W2_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_2 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 2
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_3 0x74 // SSP 10G BIST user mode pattern Word 3
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W3_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_3 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 3
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_4 0x76 // SSP 10G BIST user mode pattern Word 4
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W4_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_4 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 4
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_5 0x78 // SSP 10G BIST user mode pattern Word 5
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W5_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_5 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 5
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_6 0x7A // SSP 10G BIST user mode pattern Word 6
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W6_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_6 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 6
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_7 0x7C // SSP 10G BIST user mode pattern Word 7
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W7_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_7 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 7
#define CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_8 0x7E // SSP 10G BIST user mode pattern Word 8
    #define CND003_U3IPSSCFGP_R_SSPLPBK_USR_PTN_W8_SS CND003_U3IPSSCFGP_SSP_10G_BIST_USER_MODE_PATTERN_WORD_8 // 5555h/x/x/x SSP 10G BIST User Mode Pattern Word 8
#define CND003_U3IPSSCFGP_SSIP_PORT_SUSPEND_OPTION_REGS 0x80 // SSIP_PORT_Suspend_Option_Registers
    #define CND003_U3IPSSCFGP_R_SLFPSLEN_SS    (BIT14 + BIT15) // 0/x/x/x Select Filter LFPS Llength for Wake-up Condition
    #define CND003_U3IPSSCFGP_R_UXETPLLOFF_SS  BIT13           // 1b/x/x/x Enable Power State TPLL Off Function in Exit and Detection 
    #define CND003_U3IPSSCFGP_R_U1TPLLOFF_SS   BIT12           // 0/x/x/x Enable U1 State TPLL Off Function
    #define CND003_U3IPSSCFGP_R_DETIME_SS      (BIT10 + BIT11) // 0/x/x/x Receiver Detection Time
    #define CND003_U3IPSSCFGP_R_LSDYNEN_SS     BIT9            // 0/x/x/1b Enable LFPSC Suspend Dynamic Clock
    #define CND003_U3IPSSCFGP_R_LFPSDGEN_SS    BIT8            // 1b/x/x/x Enable LFPS De-glitch Function
    #define CND003_U3IPSSCFGP_R_DEVRCVTSEN_SS  BIT7            // 0/x/x/x Device Receiver Detection Limit Timer Shorter Enable
    #define CND003_U3IPSSCFGP_R_D3HOTEN_SS     BIT6            // 1b/x/x/x Enable Suspend Domain Receiver Detection in D3-Hot Condition
    #define CND003_U3IPSSCFGP_R_LKCWEN_SS      BIT5            // 0/x/x/x Enable Link Trained after Compliance Mode Warm Reset
    #define CND003_U3IPSSCFGP_R_PSWRSTRCVEN_SS BIT4            // 1b/x/x/x Enable UFP Receiving Warm Reset in Polling State to Avoid Entry Disa...
    #define CND003_U3IPSSCFGP_R_QKTMOEN_SS     BIT3            // 0/x/x/x Quick Timeout Mode Enable
    #define CND003_U3IPSSCFGP_R_IPTYPE_SS      (BIT1 + BIT2)   // 10b/x/x/x Device / Port Type Selection
    #define CND003_U3IPSSCFGP_R_RCVDET_MODE_SS BIT0            // 1b/x/x/x Receiver Detection Decision Mode
#define CND003_U3IPSSCFGP_SSIP_PORT_LFPSC_OPTION_REGS_1 0x82 // SSIP_PORT_LFPSC_Option_Registers_1
    #define CND003_U3IPSSCFGP_R_RCVDET_SS          BIT15           // 0/x/x/x Receiver Detection Control Start
    #define CND003_U3IPSSCFGP_R_RCVDETSETEN_SS     BIT14           // 0/x/x/x Receiver Detection Control Set Enable
    #define CND003_U3IPSSCFGP_R_DISOFF_SS          BIT13           // 0/x/x/x Disable PMU Wake Signal Function in Disable State
    #define CND003_U3IPSSCFGP_R_RCVTMOTMR_SS       (BIT11 + BIT12) // 0/x/x/x Receiver Detection Period
    #define CND003_U3IPSSCFGP_R_DYNLPHYRCVEN_SS    BIT10           // 0/x/x/1b Dynamic Power Enable for Receiver Detection
    #define CND003_U3IPSSCFGP_R_DYNLPHYSUSEN_SS    BIT9            // 0/x/x/1b Dynamic Power Enable in LPHY SUSPOW Domain
    #define CND003_U3IPSSCFGP_R_RCVDET_NONE_SS     BIT8            // 0/x/x/x Let Receiver Result Always Be None
    #define CND003_U3IPSSCFGP_R_RMCNTEN_SS         BIT7            // 0/x/x/x Enable Remote Counter Function
    #define CND003_U3IPSSCFGP_R_DYNSUSPM_SS        BIT6            // 0/x/x/1b Dynamic Power Management Control Enable
    #define CND003_U3IPSSCFGP_R_PASSU3RCVDET_SS    BIT5            // 0/x/x/x Pass Receiver Detection in Suspend Domain
    #define CND003_U3IPSSCFGP_R_PLLEN_SS           (BIT3 + BIT4)   // 11b/x/x/x Select the Low Bound of Polling-LFPS Margin
    #define CND003_U3IPSSCFGP_R_RXLFPSEN_SS        BIT2            // 1b/x/x/x Enable Receiver LFPS Detection
    #define CND003_U3IPSSCFGP_R_DISRDCLREN_SS      BIT1            // 1b/x/x/x Clear RCV_DETECTED Value in Disable State
    #define CND003_U3IPSSCFGP_R_DISRDEN_SS         BIT0            // 0/x/x/x Enable Receiver Detection in Disable State
#define CND003_U3IPSSCFGP_SSIP_PORT_LFPSC_OPTION_REGS_2 0x84 // SSIP_PORT_LFPSC_Option_Registers_2
    #define CND003_U3IPSSCFGP_R_LPHYRCVTMOTMR_SS   (BIT14 + BIT15) // 0/x/x/x Receiver Detection Discharge Period
    #define CND003_U3IPSSCFGP_R_EXTDETQTM_SS       BIT13           // 0/x/x/x Extend Detection Interval to 120ms from 12ms
    #define CND003_U3IPSSCFGP_R_SSCTSRST_SS        BIT12           // 0/x/x/x Enable SSC Reset When More Than 2ms in TS States of Polling or Recove...
    #define CND003_U3IPSSCFGP_R_SSCPRST_SS         BIT11           // 0/x/x/x Enable SSC Reset When Entry Polling State
    #define CND003_U3IPSSCFGP_R_FLFPSPDB_SS        BIT10           // 0/x/x/x FW Power down LFPSRCV
    #define CND003_U3IPSSCFGP_R_HLFPSPDB_SS        BIT9            // 0/x/x/x HW Automatic Power down LFPSRCV
    #define CND003_U3IPSSCFGP_R_DPU23NDET_SS       BIT8            // 0/x/x/x DFP Disable Receiver Detection in U2/3
    #define CND003_U3IPSSCFGP_R_WRSTCDET_SS        BIT7            // 0/x/x/x Clear Connection Flag When Generating Warm Reset
    #define CND003_U3IPSSCFGP_R_EXTRSTEN_SS        BIT6            // 0/x/x/x Extend Recovery State TRX Reset Interval
    #define CND003_U3IPSSCFGP_R_DISCONEN_SS        (BIT4 + BIT5)   // 0/x/x/x Enable Dis-connection Multi-time Sample
    #define CND003_U3IPSSCFGP_R_WRSTRCVMIN_SS      BIT3            // 0/x/x/x Enable Minimal LFPS Length When Receiving Warm Reset LFPS
    #define CND003_U3IPSSCFGP_R_UFPDETEN_SS        BIT2            // 0/x/x/x Enable UFP Receiver Detection in U2/3 State 
    #define CND003_U3IPSSCFGP_R_LKTRADCLR_SS       BIT1            // 0/x/x/x Clear Link Trained Bit
    #define CND003_U3IPSSCFGP_R_TXLFPSEN_SS        BIT0            // 0/x/x/x LFPS Generation Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_LFPSC_STA_REGS 0x86 // SSIP_PORT_LFPSC_Status_Registers
    #define CND003_U3IPSSCFGP_FHU_RXTERM       0xF000                  // 1000b/x/x/x Manual Setting for RX Termination
    #define CND003_U3IPSSCFGP_FHU_RX100K       BIT11                   // 0/x/x/x Control RX at High R State
    #define CND003_U3IPSSCFGP_FHU_RCVDETS      (BIT8 + BIT9 + BIT10)   // 100b/x/x/x Rcvdet Detection Level Control
    #define CND003_U3IPSSCFGP_R_DETCNT_SS      (BIT6 + BIT7)           // 0/x/x/x Enable Receiver Detection De-bounce
    #define CND003_U3IPSSCFGP_LFPSC_TBKV_SS    0x3C                    // 0/x/x/x TieBreaker Value Received from Link Partner
    #define CND003_U3IPSSCFGP_LFPSC_VPLN_SS    BIT1                    // 0/x/x/x When Enabling VLI Product Check and Matching the LDN/LUP Check Functi...
    #define CND003_U3IPSSCFGP_LFPSC_VPPL_SS    BIT0                    // 0/x/x/x When Enabling VLI Product Check and Matching The TBK Check Function, ...
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS1 0x88 // SSIP_PORT_EPHY_Control_Registers1
    #define CND003_U3IPSSCFGP_FHU_NONP2        BIT15                   // 0/x/x/x The Function of Interface Is for Solving TX
    #define CND003_U3IPSSCFGP_FHU_RXPWRSET     (BIT13 + BIT14)         // 10b/x/x/x RX Power Status Set
    #define CND003_U3IPSSCFGP_FHU_RXPWRSETEN   BIT12                   // 0/x/x/x RX Power Status Set Enable
    #define CND003_U3IPSSCFGP_FHU_TXEIDLESETB  BIT11                   // 0/x/x/x TX Electrical Idle Set
    #define CND003_U3IPSSCFGP_FHU_TXPWRSET     (BIT9 + BIT10)          // 10b/x/x/x TX Power Status Set 
    #define CND003_U3IPSSCFGP_FHU_TXPWRSETEN   BIT8                    // 0/x/x/x TX Power Status Set Enable
    #define CND003_U3IPSSCFGP_FHU_TXEIDLESEL   BIT7                    // 0/x/x/x TXEIDLEB Control by LPHY or Register Setting
    #define CND003_U3IPSSCFGP_FHU_RXRTNIN      BIT6                    // 0/x/x/x Control RX Term from RTN Output
    #define CND003_U3IPSSCFGP_FHU_LFPS_SW      (BIT3 + BIT4 + BIT5)    // 100b/x/x/x Set Bias Current for LFPS Swing
    #define CND003_U3IPSSCFGP_FHU_LFPSVTH      (BIT1 + BIT2)           // 10b/x/x/x Set LFPS REV Detection Threshold 
    #define CND003_U3IPSSCFGP_FHU_LFPSBPFPD    BIT0                    // 0/x/x/x Disables the Band-Pass Function of LFPS RCV
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS2 0x8A // SSIP_PORT_EPHY_Control_Registers2
    #define CND003_U3IPSSCFGP_FHU_LOWPOWER_SS  BIT15                   // 1b/x/x/x Low Power Control
    #define CND003_U3IPSSCFGP_FHU_IVCPSEL_SS   0x7800                  // 1010b/x/x/x Port0 IV Gain Select, Set Charge Pump Current
    #define CND003_U3IPSSCFGP_FHU_RXCLKSEL_SS  (BIT8 + BIT9 + BIT10)   // 000b/x/x/x RXCLK Phase Select 1 Period= 1/500MHz
    #define CND003_U3IPSSCFGP_FHU_RXDFETAP_SS  (BIT6 + BIT7)           // 11b/x/x/x RX DEF TAP Control
    #define CND003_U3IPSSCFGP_FHU_TDCIS_SS     (BIT3 + BIT4 + BIT5)    // 100b/x/x/x Port0 Bias Current Set
    #define CND003_U3IPSSCFGP_FHU_TDNCIS_SS    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x De-emphasis Set
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS3 0x8C // SSIP_PORT_EPHY_Control_Registers3
    #define CND003_U3IPSSCFGP_FHU_EQTNMODE_SS      0xFF00  // 0/x/x/x Equalizer Tuning Mode Select 
    #define CND003_U3IPSSCFGP_FHU_RGLVREFSET_SS    0xF0    // 0/x/x/x Regulator Voltage Option
    #define CND003_U3IPSSCFGP_FHU_CDRRGLSEL_SS     0xF     // 0/x/x/x CDR Power Control
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS4 0x8E // SSIP_PORT_EPHY_Control_Registers4
    #define CND003_U3IPSSCFGP_FHU_EQTNOSBW_SS  0xF000          // 0001b/x/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_U3IPSSCFGP_FHU_EQTNHFMAX_SS (BIT10 + BIT11) // 00b/x/x/x LEQ HF Max. Gain
    #define CND003_U3IPSSCFGP_FHU_EQTNDCMAX_SS (BIT8 + BIT9)   // 00b/x/x/x LEQ DC Max. Gain
    #define CND003_U3IPSSCFGP_FHU_EQTNHFBW_SS  0xF0            // 0111b/x/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_U3IPSSCFGP_FHU_EQTNDCBW_SS  0xF             // 0001b/x/x/x LEQ DC Gain Tuning Bandwidth Set
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS5 0x90 // SSIP_PORT_EPHY_Control_Registers5
    #define CND003_U3IPSSCFGP_FHU_HFSET_SS         0xF000                  // 1111b/x/x/x LEQ HF Gain Initial or Set Value 
    #define CND003_U3IPSSCFGP_FHU_HFSETEN_SS       BIT11                   // 0/x/x/x LEQ HF Gain Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_EQTNVTH_SS       (BIT8 + BIT9 + BIT10)   // 101b/x/x/x Equalizer Tuning Threshold (CDR Input Eye
    #define CND003_U3IPSSCFGP_FHU_EQTNSPDSWEN_SS   BIT7                    // 1b/x/x/x Enable Low Speed Operation under FHU_EQTNALWY=1 for Power Saving
    #define CND003_U3IPSSCFGP_FHU_EQTNALWY_SS      BIT6                    // 1b/x/x/x Equalizer Always Tuning Mode Enable
    #define CND003_U3IPSSCFGP_FHU_EQTNDFE_SS       (BIT4 + BIT5)           // 10b/x/x/x DFE Tap Selection
    #define CND003_U3IPSSCFGP_FHU_EQTNWTBW_SS      0xF                     // 0111b/x/x/x DFE Weight Tuning Bandwidth Set 
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS6 0x92 // SSIP_PORT_EPHY_Control_Registers6
    #define CND003_U3IPSSCFGP_FHU_W1SET_SS         0xF000  // 0000b/x/x/x DFE Weight1 Initial or Set Value
    #define CND003_U3IPSSCFGP_FHU_OSSET_SS         0xF00   // 0000b/x/x/x LEQ Offset Initial or Set Value
    #define CND003_U3IPSSCFGP_FHU_OSSETEN_SS       BIT7    // 0/x/x/x LEQ Offset Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_DCSET_SS         0x7C    // 11111b/x/x/x LEQ DC Gain Initial or Set Value
    #define CND003_U3IPSSCFGP_FHU_DCSETEN_SS       BIT1    // 0/x/x/x LEQ (Linear Equalizer) DC Gain Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_EQTNDFETRN_SS    BIT0    // 1b/x/x/x Enable DFE in Training Mode
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS7 0x94 // SSIP_PORT_EPHY_Control_Registers7
    #define CND003_U3IPSSCFGP_FHU_TDPCIS_SS    (BIT13 + BIT14 + BIT15) // 011b/x/x/x Pre-emphasis Set
    #define CND003_U3IPSSCFGP_FHU_PRESHOOT_SS  BIT12                   // 0/x/x/x TX Pre-shoot Enable for Pre-cursor
    #define CND003_U3IPSSCFGP_FHU_EQTNBISTEVT  (BIT9 + BIT10 + BIT11)  // 0/x/x/x Tuning Function BIST: Event Selection
    #define CND003_U3IPSSCFGP_FHU_EQTNBISTEN   BIT8                    // 0/x/x/x Tuning Function BIST Enable
    #define CND003_U3IPSSCFGP_FHU_TXCMFT       (BIT6 + BIT7)           // 01b/x/x/x TX Common Mode Voltage Fine Tune
    #define CND003_U3IPSSCFGP_FHU_W2SET_SS     0x3C                    // 0000b/x/x/x DFE Weight2 Initial or Set Value
    #define CND003_U3IPSSCFGP_FHU_W2SETEN_SS   BIT1                    // 0/x/x/x DFE Weight2 Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_W1SETEN_SS   BIT0                    // 0/x/x/x DFE Weight1 Manual Set Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS8 0x96 // SSIP_PORT_EPHY_Control_Registers8
    #define CND003_U3IPSSCFGP_EPU_HFOUT    0xF000  // 0/x/x/x LEQ HF Gain Output
    #define CND003_U3IPSSCFGP_EPU_W2OUT    0xF00   // 0/x/x/x DFE Weight2 Output
    #define CND003_U3IPSSCFGP_EPU_W1OUT    0xF0    // 0/x/x/x DFE Weight1 Output
    #define CND003_U3IPSSCFGP_EPU_OSOUT    0xF     // 0/x/x/x LEQ Offset Output
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS9 0x98 // SSIP_PORT_EPHY_Control_Registers9
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_098_SS   BIT15                   // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_FHU_OCPHGSEL_SS          BIT14                   // 1b/x/x/x Open or Close Loop Phase Generation Selection
    #define CND003_U3IPSSCFGP_FHU_FTSRATIO_SS          (BIT11 + BIT12 + BIT13) // 100b/x/x/x PD Training Mode Ratio during P1 to P0
    #define CND003_U3IPSSCFGP_FHU_FDRATIO_SS           (BIT8 + BIT9 + BIT10)   // 101b/x/x/x FD (Frequency Detector) Mode Ratio during P2 to P1 to P0
    #define CND003_U3IPSSCFGP_FHU_TX_DUTY_SS           (BIT5 + BIT6 + BIT7)    // 000b/x/x/x TX Duty Cycle Fine Tune
    #define CND003_U3IPSSCFGP_EPU_DCOUT                0x1F                    // 0/x/x/x LEQ DC Gain Output
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS10 0x9A // SSIP_PORT_EPHY_Control_Registers10
    #define CND003_U3IPSSCFGP_FHU_KTSEL_SS     BIT15                   // 0/x/x/x Update Time during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NTSEL_SS     BIT14                   // 1b/x/x/x Update Time during Training Mode
    #define CND003_U3IPSSCFGP_FHU_KIPCSEL_SS   (BIT12 + BIT13)         // 00b/x/x/x Gain2 during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NIPCSEL_SS   (BIT10 + BIT11)         // 01b/x/x/x Gain2 during Training Mode
    #define CND003_U3IPSSCFGP_FHU_KIPRSEL_SS   (BIT8 + BIT9)           // 00b/x/x/x Gain1 during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NIPRSEL_SS   (BIT6 + BIT7)           // 10b/x/x/x Gain1 during Training Mode
    #define CND003_U3IPSSCFGP_FHU_P2EXT_SS     (BIT3 + BIT4 + BIT5)    // 010b/x/x/x P2 Exit Latency
    #define CND003_U3IPSSCFGP_FHU_P1EXT_SS     (BIT0 + BIT1 + BIT2)    // 110b/x/x/x P1 Exit Latency
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS11 0x9C // SSIP_PORT_EPHY_Control_Registers11
    #define CND003_U3IPSSCFGP_FHU_RXDFETAP_SSP         (BIT14 + BIT15) // 11b/x/x/x Gen2 RX DEF TAP Control
    #define CND003_U3IPSSCFGP_FHU_W3SET_SS             0x3C00          // 0000b/x/x/x DFE Weight3 Initial or Set Value 
    #define CND003_U3IPSSCFGP_FHU_W3SETEN_SS           BIT9            // 0/x/x/x DFE Weight3 Manual Set 
    #define CND003_U3IPSSCFGP_R_DETRXLFPS_SS           BIT8            // 0/x/x/x Enable RX-LFPS 2us Deglitch When Dis-Connection
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_09D_SS   (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_FHU_RXBW_SS              (BIT4 + BIT5)   // 11b/x/x/x LEQ, VGA Band-width Option: [1:0] VGA LEQ
    #define CND003_U3IPSSCFGP_FHU_KLFSEL_SS            (BIT2 + BIT3)   // 11b/x/x/x LF Select during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NLFSEL_SS            (BIT0 + BIT1)   // 01b/x/x/x LF Select during Training Mode
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS12 0x9E // SSIP_PORT_EPHY_Control_Registers12
    #define CND003_U3IPSSCFGP_FHU_RXBW_SSP     (BIT14 + BIT15)         // 11b/x/x/x LEQ, VGA Band-width Option: [1:0] VGA LEQ
    #define CND003_U3IPSSCFGP_FHU_TX_DUTY_SSP  (BIT11 + BIT12 + BIT13) // 000b/x/x/x TX Duty Cycle Fine Tune
    #define CND003_U3IPSSCFGP_FHU_TDPCIS_SSP   (BIT8 + BIT9 + BIT10)   // 011b/x/x/x Pre-emphasis Set
    #define CND003_U3IPSSCFGP_FHU_LOWPOWER_SSP BIT7                    // 1b/x/x/x Low Power Control 
    #define CND003_U3IPSSCFGP_FHU_PRESHOOT_SSP BIT6                    // 0/x/x/x TX Pre-shoot Enable for Pre-cursor
    #define CND003_U3IPSSCFGP_FHU_TDCIS_SSP    (BIT3 + BIT4 + BIT5)    // 100b/x/x/x Port0 Bias Current Set
    #define CND003_U3IPSSCFGP_FHU_TDNCIS_SSP   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x De-emphasis Set
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS13 0xA0 // SSIP_PORT_EPHY_Control_Registers13
    #define CND003_U3IPSSCFGP_FHU_RGLVREFSET_SSP   0xF000                  // 0/x/x/x Regulator Voltage Option
    #define CND003_U3IPSSCFGP_FHU_CDRRGLSEL_SSP    0xF00                   // 0/x/x/x CDR Power Control
    #define CND003_U3IPSSCFGP_FHU_EQTNALWY_SSP     BIT7                    // 1b/x/x/x Equalizer Always Tuning Mode Enable
    #define CND003_U3IPSSCFGP_FHU_IVCPSEL_SSP      0x78                    // 1010b/x/x/x Port0 IV Gain Select, Set Charge Pump Current
    #define CND003_U3IPSSCFGP_FHU_RXCLKSEL_SSP     (BIT0 + BIT1 + BIT2)    // 000b/x/x/x RXCLK Phase Select 1 Period= 1/500MHz
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS14 0xA2 // SSIP_PORT_EPHY_Control_Registers14
    #define CND003_U3IPSSCFGP_FHU_EQTNMODE_SSP         0xFF00          // 0/x/x/x Equalizer Tuning Mode Select
    #define CND003_U3IPSSCFGP_FHU_EQTNDCMAX_SSP        (BIT6 + BIT7)   // 00b/x/x/x LEQ DC Max Gain
    #define CND003_U3IPSSCFGP_FHU_EQTNDCBW_SSP         0x3C            // 0001b/x/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0A2_SS   (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS15 0xA4 // SSIP_PORT_EPHY_Control_Registers15
    #define CND003_U3IPSSCFGP_FHU_EQTNDFE_SSP      (BIT14 + BIT15) // 10b/x/x/x DFE Tap selection
    #define CND003_U3IPSSCFGP_FHU_EQTNWTBW_SSP     0x3C00          // 0111b/x/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_U3IPSSCFGP_FHU_EQTNHFMAX_SSP    (BIT8 + BIT9)   // 00b/x/x/x LEQ HF Max Gain
    #define CND003_U3IPSSCFGP_FHU_EQTNOSBW_SSP     0xF0            // 0001b/x/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_U3IPSSCFGP_FHU_EQTNHFBW_SSP     0xF             // 0111b/x/x/x LEQ HF Gain Tuning Bandwidth Set
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS16 0xA6 // SSIP_PORT_EPHY_Control_Registers16
    #define CND003_U3IPSSCFGP_FHU_W3SETEN_SSP      BIT15                   // 0/x/x/x DFE Weight3 Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_W2SETEN_SSP      BIT14                   // 0/x/x/x DFE weight2 Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_W1SETEN_SSP      BIT13                   // 0/x/x/x DFE Weight1 manual set enable
    #define CND003_U3IPSSCFGP_FHU_DCSET_SSP        0x1F00                  // 11111b/x/x/x LEQ DC Gain Initial or Set Value
    #define CND003_U3IPSSCFGP_FHU_OSSETEN_SSP      BIT7                    // 0/x/x/x LEQ Offset Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_HFSETEN_SSP      BIT6                    // 0/x/x/x LEQ HF Gain Manual Set Enable
    #define CND003_U3IPSSCFGP_FHU_DCSETEN_SSP      BIT5                    // 0/x/x/x LEQ (Linear Equalizer) DC Gain Manual Set
    #define CND003_U3IPSSCFGP_FHU_EQTNDFETRN_SSP   BIT4                    // 1b/x/x/x Enable DFE in Training Mode
    #define CND003_U3IPSSCFGP_FHU_EQTNVTH_SSP      (BIT1 + BIT2 + BIT3)    // 101b/x/x/x Equalizer Tuning Threshold (CDR Input Eye
    #define CND003_U3IPSSCFGP_FHU_EQTNSPDSWEN_SSP  BIT0                    // 1b/x/x/x Enable Low Speed Operation under FHU_EQTNALWY=1 for Power Saving
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS17 0xA8 // SSIP_PORT_EPHY_Control_Registers17
    #define CND003_U3IPSSCFGP_FHU_W2SET_SSP    0xF000  // 0000b/x/x/x DFE Weight2 Initial or Set Value
    #define CND003_U3IPSSCFGP_FHU_W1SET_SSP    0xF00   // 0000b/x/x/x DFE Weight1 Initial or Set Value 
    #define CND003_U3IPSSCFGP_FHU_OSSET_SSP    0xF0    // 0000b/x/x/x LEQ Offset Initial or Set Value 
    #define CND003_U3IPSSCFGP_FHU_HFSET_SSP    0xF     // 1111b/x/x/x LEQ HF Gain Initial or Set Value
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS18 0xAA // SSIP_PORT_EPHY_Control_Registers18
    #define CND003_U3IPSSCFGP_FHU_NIPCSEL_SSP  (BIT14 + BIT15)         // 01b/x/x/x Gain2 during Training Mode 
    #define CND003_U3IPSSCFGP_FHU_FTSRATIO_SSP (BIT11 + BIT12 + BIT13) // 100b/x/x/x PD Training Mode Ratio during P1 to P0
    #define CND003_U3IPSSCFGP_FHU_FDRATIO_SSP  (BIT8 + BIT9 + BIT10)   // 101b/x/x/x FD (Frequency Detector) Mode Ratio during P2 to P1 to P0
    #define CND003_U3IPSSCFGP_FHU_KIPRSEL_SSP  (BIT6 + BIT7)           // 00b/x/x/x Gain1 during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NIPRSEL_SSP  (BIT4 + BIT5)           // 10b/x/x/x Gain1 during Training Mode
    #define CND003_U3IPSSCFGP_FHU_W3SET_SSP    0xF                     // 0000b/x/x/x DFE Weight3 Initial or Set Value
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS19 0xAC // SSIP_PORT_EPHY_Control_Registers19
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0AC_SS   BIT15                   // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_FHU_OCPHGSEL_SSP         BIT14                   // 1b/x/x/x Open or Close Loop Phase Generation Selection
    #define CND003_U3IPSSCFGP_FHU_KLFSEL_SSP           (BIT12 + BIT13)         // 11b/x/x/x LF Select during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NLFSEL_SSP           (BIT10 + BIT11)         // 01b/x/x/x LF Select during Training Mode
    #define CND003_U3IPSSCFGP_FHU_KTSEL_SSP            BIT9                    // 0/x/x/x Update Time during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_NTSEL_SSP            BIT8                    // 1b/x/x/x Update Time during Training Mode
    #define CND003_U3IPSSCFGP_FHU_KIPCSEL_SSP          (BIT6 + BIT7)           // 00b/x/x/x Gain2 during Tracking Mode
    #define CND003_U3IPSSCFGP_FHU_P2EXT_SSP            (BIT3 + BIT4 + BIT5)    // 010b/x/x/x P2 Exit Latency
    #define CND003_U3IPSSCFGP_FHU_P1EXT_SSP            (BIT0 + BIT1 + BIT2)    // 110b/x/x/x P1 Exit Latency
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_REGS20 0xAE // SSIP_PORT_EPHY_Control_Registers20
    #define CND003_U3IPSSCFGP_FHU_COMPVCMSEL   (BIT14 + BIT15)         // 01b/x/x/x USB3TPLL Vcont Comparator Comman Mode Voltage Setting
    #define CND003_U3IPSSCFGP_FHU_TPLLCPISEL   (BIT11 + BIT12 + BIT13) // 011b/x/x/x TPLL Charge Pump Current Setting
    #define CND003_U3IPSSCFGP_FHU_TPLLRSEL     (BIT8 + BIT9 + BIT10)   // 011b/x/x/x TPLL Loop Filter Resistance Setting
    #define CND003_U3IPSSCFGP_LFPSC_RX8LI_SS   BIT7                    // 0/x/x/x 8 LI Receivied
    #define CND003_U3IPSSCFGP_LFPSC_RX8TS2_SS  BIT6                    // 0/x/x/x 8 TS2 Receivied
    #define CND003_U3IPSSCFGP_LFPSC_RX8TS1_SS  BIT5                    // 0/x/x/x 8 TS1 Receivied
    #define CND003_U3IPSSCFGP_LFPSC_LITMO_SS   BIT4                    // 0/x/x/x LI State Timeout Flag
    #define CND003_U3IPSSCFGP_LFPSC_TS2TMO_SS  BIT3                    // 0/x/x/x TS2 State Timeout Flag
    #define CND003_U3IPSSCFGP_LFPSC_TS1TMO_SS  BIT2                    // 0/x/x/x TS1 State Timeout Flag
    #define CND003_U3IPSSCFGP_R_TMOFCLR_SS     BIT1                    // 0/x/x/x Clear TMO Flag When Writing 1
    #define CND003_U3IPSSCFGP_R_RETMOEN_SS     BIT0                    // 1b/x/x/x Enable Recovery-Entry 12ms Timeout Function
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_NEW_REG0 0xB0 // SSIP_PORT_SUS_NEW_Register0
    #define CND003_U3IPSSCFGP_R_LFPSDYNEN_SS   BIT15           // 0/x/x/1b LFPSC Detect RXLFPS Counter Dynamic Clock Enable
    #define CND003_U3IPSSCFGP_R_DFPU2WKEN_SS   BIT14           // 0/x/x/x DFP Will Wake up in U2 When Device Disconnect
    #define CND003_U3IPSSCFGP_R_CBANKCLR_SS    BIT13           // 0/x/x/x Clear Calibration Result
    #define CND003_U3IPSSCFGP_R_DYNTPLLEN_SS   BIT12           // 0/x/x/1b Enable Dynamic TPLL Function. 
    #define CND003_U3IPSSCFGP_R_CCDETEN_SS     BIT11           // 0/x/x/x Use External CC Detect Result to Judge RCVDET Result
    #define CND003_U3IPSSCFGP_R_2RCVDETEN_SS   BIT10           // 0/x/x/x EPHY 2 RCVDET Module Work at the Same Time When Link State in U2/U3
    #define CND003_U3IPSSCFGP_R_CBANKITV_SS    (BIT8 + BIT9)   // 0/x/x/x FW Set CBANK Iinterval
    #define CND003_U3IPSSCFGP_R_CBANK_SS       0xF0            // 0/x/x/x FW Set CBANK Value
    #define CND003_U3IPSSCFGP_R_CBANKSETEN_SS  BIT3            // 0/x/x/x FW Set CBANK Enable
    #define CND003_U3IPSSCFGP_R_CBEN_SS        BIT2            // 1b/x/x/x Enable TPLLPDB Reset CBANK Control
    #define CND003_U3IPSSCFGP_EPU_VCOMP        (BIT0 + BIT1)   // 0/x/x/x US3TPLL Vcont Settle Down Area
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_NEW1_REG 0xB2 // SSIP_PORT_EPHY_Control_NEW1_Register
    #define CND003_U3IPSSCFGP_FHU_EQBOOSTTUNE  BIT15                   // 0/x/x/x EQBOOST Auto Tune
    #define CND003_U3IPSSCFGP_FHU_CMP2ON       BIT14                   // 0/x/x/x CM-OP on at P2 State
    #define CND003_U3IPSSCFGP_FHU_TPLLVCOREG   (BIT11 + BIT12 + BIT13) // 100b/x/x/x VCO Regulator Voltage Fine Tune
    #define CND003_U3IPSSCFGP_FHU_EQTNHFVTH    (BIT8 + BIT9 + BIT10)   // 101b/x/x/x Equalizer HF Tuning Threshold
    #define CND003_U3IPSSCFGP_FHU_EQTNOPT      0xFF                    // 0/x/x/x Equalizer Tuning Function Options
#define CND003_U3IPSSCFGP_SSIP_PORT_EPHY_CTL_NEW2_REG 0xB4 // SSIP_PORT_EPHY_Control_NEW2_Register
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0B4_SS   (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_FHU_CBANKDETEN           BIT12                   // 0/x/x/x Detect CBANK[3:0]=4?b0 or 4?b1
    #define CND003_U3IPSSCFGP_FHU_FDETEN               BIT11                   // 0/x/x/x PLL Locking Frequency Detector Enable
    #define CND003_U3IPSSCFGP_FHU_EQBOOST_SSP          (BIT8 + BIT9 + BIT10)   // 101b/x/x/x LEQ Rs Boost Adjustment
    #define CND003_U3IPSSCFGP_FHU_EQBOOST_SS           (BIT5 + BIT6 + BIT7)    // 101b/x/x/x LEQ Rs Boost Adjustment
    #define CND003_U3IPSSCFGP_FHU_TXSKEWFT             (BIT2 + BIT3 + BIT4)    // 0/x/x/x Clock Skew Fine Tune
    #define CND003_U3IPSSCFGP_FHU_TCPOSSETEN           BIT1                    // 0/x/x/x Type-C Channel Set Enable 
    #define CND003_U3IPSSCFGP_FHU_TCPOSSET             BIT0                    // 0/x/x/x Type-C Channel Set Enable 
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_RCVDET 0xB6 // SSIP_PORT_SUS_RCVDET
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0B6_SS   0xFC00  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_TPYEA_SEL_SS           BIT9    // 0/x/x/x TYPE-A Port Lane Selection
    #define CND003_U3IPSSCFGP_R_TPYEA_EN_SS            BIT8    // 0/x/x/x Enable TYPE-A Selection
    #define CND003_U3IPSSCFGP_R_RCVDET_CHK_PARM_SS     0xFF    // C8h/x/x/x Receiver Detection Check Parameter
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_EPHY_TEST_CTL 0xB8 // SSIP_PORT_SUS EPHY Test Control
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0B8_SS   0xFC00  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_R_FDETEN_SS              BIT9    // 1b/x/x/x PLL Locking Frequency Detector Enable
    #define CND003_U3IPSSCFGP_R_GEN2EN_SET_SS          BIT8    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_RCVDETBEN_SET_SS       BIT7    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_RCVDETAEN_SET_SS       BIT6    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_RCVDETBPDB_SET_SS      BIT5    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_RCVDETAPDB_SET_SS      BIT4    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_TXLFPS_SET_SS          BIT3    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_RXHZ_SET_SS            BIT2    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_TXHZ_SET_SS            BIT1    // 0/x/x/x When R_USB31_TST_MODE =1
    #define CND003_U3IPSSCFGP_R_USB31_TST_MODE_SS      BIT0    // 0/x/x/x USB3.1 EPHY Test Mode Enable
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_EPHY_TEST_STA 0xBA // SSIP_PORT_SUS EPHY Test Status
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0BA_SS   0xFF80  // 0/x/x/x Reserved
    #define CND003_U3IPSSCFGP_EPU_CBANKERROR           BIT6    // 0/x/x/x TPLL CBANK[3:0] Error Flag
    #define CND003_U3IPSSCFGP_EPU_FREQERR              BIT5    // 0/x/x/x PLL Un-locked Flag
    #define CND003_U3IPSSCFGP_EPU_LFPSDET              BIT4    // 0/x/x/x EPHY LFPSDET Output
    #define CND003_U3IPSSCFGP_EPU_RCVDETPA             BIT3    // 0/x/x/x EPHY RCVDETP of A Side Result Output
    #define CND003_U3IPSSCFGP_EPU_RCVDETNA             BIT2    // 0/x/x/x EPHY RCVDETN of A Side Result Output
    #define CND003_U3IPSSCFGP_EPU_RCVDETPB             BIT1    // 0/x/x/x EPHY RCVDETP of B side Result Output
    #define CND003_U3IPSSCFGP_EPU_RCVDETNB             BIT0    // 0/x/x/x EPHY RCVDETN of B Side Result Output
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BC 0xBC // SSIP_PORT_SUS_Reserved_BC
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0BC_SS CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BC // 0/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BE 0xBE // SSIP_PORT_SUS_Reserved_BE
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0BE_SS CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BE // FFFFh/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BC_Z1 0xC0 // SSIP_PORT_SUS_Reserved_BC
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0C0_SS CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BC_Z1 // 0/x/x/x Reserved
#define CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BE_Z1 0xC2 // SSIP_PORT_SUS_Reserved_BE
    #define CND003_U3IPSSCFGP_RSVU3IP_SSCFG_P_0C2_SS CND003_U3IPSSCFGP_SSIP_PORT_SUS_RESERVED_BE_Z1 // FFFFh/x/x/x Reserved
// CND003_OPTCFG_MCU
#define CND003_OPTCFGMCU_MCU_ON_BOARD 0x4 // MCU On Board
    #define CND003_OPTCFGMCU_MCU_ON_BOARD_APP  BIT0    // 0/x/x/x MCU On-board Application Controlled by BIOS
#define CND003_OPTCFGMCU_MCU_SPIROM_ON_BOARD 0x5 // MCU SPIROM On Board
    #define CND003_OPTCFGMCU_MCU_RES           0xFC    // 0/x/x/x MCU Internal Reserved Option Bits
    #define CND003_OPTCFGMCU_MCU_INS_BUF_EN    BIT1    // 0/x/x/x MCU Instruction Buffer Enable
    #define CND003_OPTCFGMCU_SPIROM_ON_BOARD   BIT0    // 1b/x/x/x SPIROM on board flag controlled by BIOS
#define CND003_OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_CTL 0x8 // MCU Instruction Auto-fill Control
    #define CND003_OPTCFGMCU_INST_AUTOFILL_EN  BIT0    // 0/x/x/x MCU Instruction Auto-fill Enable
#define CND003_OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_STA 0x9 // MCU Instruction Auto-fill Status
    #define CND003_OPTCFGMCU_INST_AUTOFILL_DONE    BIT0    // 0/x/x/x MCU Instruction Auto-fill Done
#define CND003_OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_LEN 0xA // MCU Instruction Auto-fill Length
    #define CND003_OPTCFGMCU_INST_AUTOFILL_LENGTH CND003_OPTCFGMCU_MCU_INSTRUCTION_AUTO_FILL_LEN // 0/x/x/x MCU Instruction Auto-fill Length
#define CND003_OPTCFGMCU_START_ADR_OF_AUTO_FILL_INSTRUCTION 0xC // Start Address of Auto-fill Instruction
    #define CND003_OPTCFGMCU_INST_AUTOFILL_SADDR CND003_OPTCFGMCU_START_ADR_OF_AUTO_FILL_INSTRUCTION // 0/x/x/x Start Address of Auto-fill Instruction
#define CND003_OPTCFGMCU_HUB2_0_8051_FW_DOWNLOAD_CTL 0x10 // Hub2.0 8051 Firmware Download Control
    #define CND003_OPTCFGMCU_HUB2_DMA_EN       BIT1    // 0/0/x/x Hub2.0 8051 Firmware Download Enable
    #define CND003_OPTCFGMCU_HUB2_NON_REPLACE  BIT0    // 0/0/x/x Hub2.0 8051 Cirmware Non-replace
#define CND003_OPTCFGMCU_HUB2_0_8051_FW_DOWNLOAD_STA 0x11 // Hub2.0 8051 Firmware Download Status
    #define CND003_OPTCFGMCU_HUB2_DMA_DONE BIT0    // 0/0/x/x Hub2.0 8051 Firmware Download Done
#define CND003_OPTCFGMCU_HUB2_0_8051_FW_DOWNLOAD_LEN 0x12 // Hub2.0 8051 Firmware Download Length
    #define CND003_OPTCFGMCU_HUB2_DMA_LEN  0x3FFF          // 0/x/x/x Hub2.0 8051 Firmware Download Length
#define CND003_OPTCFGMCU_LOWER_BASE_ADR_OF_HUB2_0_8051_FW_DOWNLOAD 0x14 // Lower Base Address of Hub2.0 8051 Firmware Download
    #define CND003_OPTCFGMCU_HUB2_DMA_LBASE    0xFFFFFFFC      // 0/0/x/x Lower Start Address of  Hub2.0 8051 Firmware Download in System Memory
#define CND003_OPTCFGMCU_UPPER_BASE_ADR_OF_HUB2_0_8051_FW_DOWNLOAD 0x18 // Upper Base Address of Hub2.0 8051 Firmware Download
    #define CND003_OPTCFGMCU_HUB2_DMA_UBASE CND003_OPTCFGMCU_UPPER_BASE_ADR_OF_HUB2_0_8051_FW_DOWNLOAD // 0/0/x/x Upper Start Address of  Hub2.0 8051 Firmware Download in System Memory
#define CND003_OPTCFGMCU_MCU_SW_RESET 0x20 // MCU Software Reset
    #define CND003_OPTCFGMCU_MCU_SW_RST    BIT0    // 1b/1b/x/x MCU Software Reset Controlled by BIOS
#define CND003_OPTCFGMCU_BASE_ADR_OF_MCU_FW_IN_SYS_MEM_LOW 0x28 // Base Address of MCU Firmware in System Memory Low
    #define CND003_OPTCFGMCU_MCU_INSTDAT_SYSMEM_BASE_LO    0xFFFFFFC0  // 0/x/x/x Base Address of MCU Firmware (Instruction and Data) Space in System M...
#define CND003_OPTCFGMCU_BASE_ADR_OF_MCU_FW_IN_SYS_MEM_HIGH 0x2C // Base Address of MCU Firmware in System Memory High
    #define CND003_OPTCFGMCU_MCU_INSTDAT_SYSMEM_BASE_HI    0xFFFF      // 0/x/x/x Base Address of MCU Firmware (Instruction and Data) Space in System M...
#define CND003_OPTCFGMCU_MCU_DATA_AUTO_FILL_LEN 0x30 // MCU Data Auto-fill Length
    #define CND003_OPTCFGMCU_DATA_AUTOFILL_LENGTH  0x3FFF      // 0/x/x/x MCU Data Auto-fill Length
#define CND003_OPTCFGMCU_START_ADR_OF_AUTO_FILL_DATA 0x34 // Start Address of Auto-fill Data
    #define CND003_OPTCFGMCU_DATA_AUTOFILL_SADDR CND003_OPTCFGMCU_START_ADR_OF_AUTO_FILL_DATA // 0/x/x/x Start Address of Auto-fill Data
#define CND003_OPTCFGMCU_MCU_CLK_DIVIDER_PARAM 0x38 // MCU Clock Divider Parameter
    #define CND003_OPTCFGMCU_MCU_SUSCLK_DIV    0x1F                    // Ah/Ah/x/x Parameterfor 25M Clock Divider
// U3TYPEC_CFG
#define CND003_U3TYPECCFG_BANDGAP_CTL 0x0 // Bandgap Control
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_001  0xFE00                  // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_R_BG_TRIM_SEL    BIT8                    // 1b/x/x/x Band-gap Voltage Adjusting Control Bits Selection       
    #define CND003_U3TYPECCFG_R_BG_TRIM        (BIT5 + BIT6 + BIT7)    // 0/x/x/x Band-gap Voltage Adjusting Control Bits
    #define CND003_U3TYPECCFG_FHC_DET_ADJ      (BIT2 + BIT3 + BIT4)    // 001b/x/x/x Adjust Bandgap Voltage
    #define CND003_U3TYPECCFG_FHC_BG_TRIM_ENB  BIT1                    // 1b/x/x/x Band-gap Voltage Adjusting Enable Control Signal
    #define CND003_U3TYPECCFG_FHC_BG_ENB       BIT0                    // 1b/x/x/x Power down All EPHY Blocks
#define CND003_U3TYPECCFG_PORT0_RP_AND_RD_CTL 0x2 // Port0 Rp and Rd Control
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_003  BIT15                   // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_R_CC02_SM        (BIT12 + BIT13 + BIT14) // 001b/x/x/x MCU Config CC02_DFP State Machine
    #define CND003_U3TYPECCFG_R_CC01_SM        (BIT9 + BIT10 + BIT11)  // 001b/x/x/x MCU Config CC01_DFP State Machine
    #define CND003_U3TYPECCFG_FHC02_VCONN_EN   BIT8                    // 0/x/x/x Port0 VCONN Enable Control for CC2
    #define CND003_U3TYPECCFG_FHC02_RD_EN      BIT7                    // 0/x/x/x Port0 Rd Enable Control for CC2
    #define CND003_U3TYPECCFG_FHC02_RP_EN      BIT6                    // 0/x/x/x Port0 Rp Current Enable Control for CC2
    #define CND003_U3TYPECCFG_FHC01_VCONN_EN   BIT5                    // 0/x/x/x Port0 VCONN Enable Control for CC1
    #define CND003_U3TYPECCFG_FHC01_RD_EN      BIT4                    // 0/x/x/x Port0 Rd Enable Control for CC1
    #define CND003_U3TYPECCFG_FHC01_RP_EN      BIT3                    // 0/x/x/x Port0 Rp Current Enable control for CC1
    #define CND003_U3TYPECCFG_FHC0_RP_ADJ      (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port0 Rp Current Control
#define CND003_U3TYPECCFG_PORT0_RP_AND_RD_STA 0x4 // Port0 Rp and Rd Status
    #define CND003_U3TYPECCFG_CC02_DFP_SM      (BIT13 + BIT14 + BIT15) // HwInit/x/x/x Port1 CC2 DFP State Machine
    #define CND003_U3TYPECCFG_CC01_DFP_SM      (BIT10 + BIT11 + BIT12) // HwInit/x/x/x Port1 CC1 DFP State Machine
    #define CND003_U3TYPECCFG_EPC02_VRD_DFP    (BIT8 + BIT9)           // HwInit/x/x/x Port0 CC2 Voltage Monitor (Need Debounce)
    #define CND003_U3TYPECCFG_EPC02_VRD_UFP    (BIT5 + BIT6 + BIT7)    // HwInit/x/x/x Port0 CC2 Voltage Monitor (Need Debounce)
    #define CND003_U3TYPECCFG_EPC01_VRD_DFP    (BIT3 + BIT4)           // HwInit/x/x/x Port0 CC1Voltage Monitor (Need Debounce)
    #define CND003_U3TYPECCFG_EPC01_VRD_UFP    (BIT0 + BIT1 + BIT2)    // HwInit/x/x/x Port0 CC1 Voltage Monitor (Need Debounce)
#define CND003_U3TYPECCFG_PORT0_BMC_RESERVED 0x6 // Port0 BMC Reserved
    #define CND003_U3TYPECCFG_FHC0_BMC_RES_HI  0xFF00  // 0/x/x/x Port0 CC Reserved HI
    #define CND003_U3TYPECCFG_FHC0_BMC_RES_LO  0xFF    // 0/x/x/x Port0 CC Reserved LO
#define CND003_U3TYPECCFG_PORT0_CALIBRATION_RESERVED 0x8 // Port0 Calibration Reserved
    #define CND003_U3TYPECCFG_EPC0_CAL_RESO    0xFF00  // HwInit/x/x/x Port0 CC Calibration Reserved Input
    #define CND003_U3TYPECCFG_FHC0_CAL_RESI    0xFF    // 0/x/x/x Port0 CC Calibration Reserved Output
#define CND003_U3TYPECCFG_PORT1_RP_AND_RD_CTL 0xA // Port1 Rp and Rd Control
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_00B  BIT15                   // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_R_CC12_SM        (BIT12 + BIT13 + BIT14) // 001b/x/x/x MCU Config CC12_DFP State Machine
    #define CND003_U3TYPECCFG_R_CC11_SM        (BIT9 + BIT10 + BIT11)  // 001b/x/x/x MCU Config CC11_DFP State Machine
    #define CND003_U3TYPECCFG_FHC12_VCONN_EN   BIT8                    // 0/x/x/x Port1 VCONN Enable Control for CC2
    #define CND003_U3TYPECCFG_FHC12_RD_EN      BIT7                    // 0/x/x/x Port1 Rd Enable Control for CC2
    #define CND003_U3TYPECCFG_FHC12_RP_EN      BIT6                    // 0/x/x/x Port1 Rp Current Enable Control for CC2
    #define CND003_U3TYPECCFG_FHC11_VCONN_EN   BIT5                    // 0/x/x/x Port1 VCONN Enable Control for CC1
    #define CND003_U3TYPECCFG_FHC11_RD_EN      BIT4                    // 0/x/x/x Port1 Rd Enable Control for CC1
    #define CND003_U3TYPECCFG_FHC11_RP_EN      BIT3                    // 0/x/x/x Port1 Rp Current Enable Control for CC1
    #define CND003_U3TYPECCFG_FHC1_RP_ADJ      (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port1 Rp Current Control
#define CND003_U3TYPECCFG_PORT1_RP_AND_RD_STA 0xC // Port1 Rp and Rd Status
    #define CND003_U3TYPECCFG_CC12_DFP_SM      (BIT13 + BIT14 + BIT15) // HwInit/x/x/x Port1 CC2 DFP State Machine
    #define CND003_U3TYPECCFG_CC11_DFP_SM      (BIT10 + BIT11 + BIT12) // HwInit/x/x/x Port1 CC1 DFP State Machine
    #define CND003_U3TYPECCFG_EPC12_VRD_DFP    (BIT8 + BIT9)           // HwInit/x/x/x Port1 CC2 Voltage Monitor (Need Debounce)
    #define CND003_U3TYPECCFG_EPC12_VRD_UFP    (BIT5 + BIT6 + BIT7)    // HwInit/x/x/x Port1 CC2 Voltage Monitor (Need Debounce)
    #define CND003_U3TYPECCFG_EPC11_VRD_DFP    (BIT3 + BIT4)           // HwInit/x/x/x Port1 CC1Voltage Monitor (Need Debounce)
    #define CND003_U3TYPECCFG_EPC11_VRD_UFP    (BIT0 + BIT1 + BIT2)    // HwInit/x/x/x Port1 CC1 Voltage Monitor (Need Debounce)
#define CND003_U3TYPECCFG_PORT1_BMC_RESERVED 0xE // Port1 BMC Reserved
    #define CND003_U3TYPECCFG_FHC1_BMC_RES_HI  0xFF00  // 0/x/x/x Port1 CC Reserved HI
    #define CND003_U3TYPECCFG_FHC1_BMC_RES_LO  0xFF    // 0/x/x/x Port1 CC Reserved LO
#define CND003_U3TYPECCFG_PORT1_CALIBRATION_RESERVED 0x10 // Port1 Calibration Reserved
    #define CND003_U3TYPECCFG_EPC1_CAL_RESO    0xFF00  // HwInit/x/x/x Port1 CC Calibration Reserved Input
    #define CND003_U3TYPECCFG_FHC1_CAL_RESI    0xFF    // 0/x/x/X Port1 CC Calibration Reserved Output
#define CND003_U3TYPECCFG_RP_AND_RD_CTL 0x12 // Rp and Rd Control
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_013      0xFF00          // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_012      0xFC            // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_FHC_DET_CMP_I_ADJ    (BIT0 + BIT1)   // 0/x/x/x CC Detection Internal Comparator Bias Current Adjustment
#define CND003_U3TYPECCFG_CALIBRATION_CTL 0x14 // Calibration Control
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_015  0xFF00  // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_014  BIT7    // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_R_RD_CAL_RSTN    BIT6    // 0/x/x/x Initial Signal for RD Calibration Which Is Later than CLK
    #define CND003_U3TYPECCFG_R_RD_CAL_SEL     BIT5    // 1b/x/x/x RD Calibration Control Bits Select Control Signal 
    #define CND003_U3TYPECCFG_R_RD_CAL_MT      0x1E    // 0/x/x/x Manual Control Bits for RD Tuning
    #define CND003_U3TYPECCFG_FHC_RD_CAL_EN    BIT0    // 0/x/x/x RD Auto Calibration Enable Control Signal
#define CND003_U3TYPECCFG_CALIBRATION_STA 0x16 // Calibration Status
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_017      0xFF00                  // HwInit/x/x/x Reserved
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_016      (BIT5 + BIT6 + BIT7)    // HwInit/x/x/x Reserved
    #define CND003_U3TYPECCFG_EPC_RD_CAL_LOCK_FLAG BIT4                    // HwInit/x/x/x Flag Signal for Valid RD_CAL_LOCK [3:0]
    #define CND003_U3TYPECCFG_EPC_RD_CAL_LOCK      0xF                     // HwInit/x/x/x Calibration Bits Output to LPHY to Reserve for Further e-fuse Ke...
#define CND003_U3TYPECCFG_GLOBAL_CTL 0x18 // Global Control
    #define CND003_U3TYPECCFG_R_QKMODE             BIT15           // 0/x/x/x For Quick Simulation
    #define CND003_U3TYPECCFG_R_RETRAIN            BIT14           // 0/x/x/x Internal EPHY Counter Reset
    #define CND003_U3TYPECCFG_R_DUP_ONLY           BIT13           // 0/x/x/x Enable DUP
    #define CND003_U3TYPECCFG_R_CCDB_MODE          (BIT11 + BIT12) // 0/x/x/x CC Status De-bounce Timeout Parameter
    #define CND003_U3TYPECCFG_R_TYPEC_INT_P0       BIT10           // 0/x/x/x TYPE-C Port0 Interrupt Status
    #define CND003_U3TYPECCFG_R_TYPEC_INT_P1       BIT9            // 0/x/x/x TYPE-C Port1 Interrupt Status
    #define CND003_U3TYPECCFG_R_PDB                BIT8            // 0/x/x/x CC/BMC Dynamic Clock Enable
    #define CND003_U3TYPECCFG_FHC_RD_CAL_CLK_DIV   0xFF            // 06h/x/x/x 24MHz Clock Divider Control
#define CND003_U3TYPECCFG_GPIO_OUTPUT_CTL 0x1A // GPIO Output Control
    #define CND003_U3TYPECCFG_USB31P_CTRL_P1       BIT15   // 0/x/x/x Type-C Port1 VBUS Enable Signal
    #define CND003_U3TYPECCFG_USB31P_CTRL_P0       BIT14   // 0/x/x/x Type-C Port0 VBUS Enable Signal
    #define CND003_U3TYPECCFG_USB31_CCRESULT_P1_B  BIT13   // 0/x/x/x Type-C port1 CC2 Detect Result
    #define CND003_U3TYPECCFG_USB31_CCRESULT_P1_A  BIT12   // 0/x/x/x Type-C port1 CC1 Detect Result
    #define CND003_U3TYPECCFG_USB31_CCRESULT_P0_B  BIT11   // 0/x/x/x Type-C Port0 CC2 Detect Result
    #define CND003_U3TYPECCFG_USB31_CCRESULT_P0_A  BIT10   // 0/x/x/x Type-C Port0 CC1 Detect Result
    #define CND003_U3TYPECCFG_CCBMCGPIO9_O         BIT9    // 1b/x/x/x Type-C GPIO9 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO8_O         BIT8    // 1b/x/x/x Type-C GPIO8 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO7_O         BIT7    // 1b/x/x/x Type-C GPIO7 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO6_O         BIT6    // 1b/x/x/x Type-C GPIO6 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO5_O         BIT5    // 1b/x/x/x Type-C GPIO5 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO4_O         BIT4    // 1b/x/x/x Type-C GPIO4 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO3_O         BIT3    // 1b/x/x/x Type-C GPIO3 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO2_O         BIT2    // 1b/x/x/x Type-C GPIO2 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO1_O         BIT1    // 1b/x/x/x Type-C GPIO1 Output Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO0_O         BIT0    // 1b/x/x/x Type-C GPIO0 Output Signal
#define CND003_U3TYPECCFG_GPIO_INPUT_STA 0x1C // GPIO Input Status
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_01D  0xF000  // HwInit/x/x/x Reserved
    #define CND003_U3TYPECCFG_RCV_DETECTED_P1  BIT11   // HwInit/x/x/x Receiver Detection Result of Port1
    #define CND003_U3TYPECCFG_RCV_DETECTED_P0  BIT10   // HwInit/x/x/x Receiver Detection Result of Port0
    #define CND003_U3TYPECCFG_CCBMCGPIO9_I     BIT9    // HwInit/x/x/x Type-C GPIO9 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO8_I     BIT8    // HwInit/x/x/x Type-C GPIO8 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO7_I     BIT7    // HwInit/x/x/x Type-C GPIO7 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO6_I     BIT6    // HwInit/x/x/x Type-C GPIO6 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO5_I     BIT5    // HwInit/x/x/x Type-C GPIO5 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO4_I     BIT4    // HwInit/x/x/x Type-C GPIO4 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO3_I     BIT3    // HwInit/x/x/x Type-C GPIO3 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO2_I     BIT2    // HwInit/x/x/x Type-C GPIO2 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO1_I     BIT1    // HwInit/x/x/x Type-C GPIO1 Input Signal
    #define CND003_U3TYPECCFG_CCBMCGPIO0_I     BIT0    // HwInit/x/x/x Type-C GPIO0 Input Signal
#define CND003_U3TYPECCFG_CC_STA_DE_BOUNCE_PARAM 0x1E // CC Status De-bounce Parameter
    #define CND003_U3TYPECCFG_R_CCDG_TMO_PARM_HI   0xFF00  // 0/x/x/x CC Status De-glitch timeout Parameter
    #define CND003_U3TYPECCFG_R_CCDG_TMO_PARM_LO   0xFF    // 0fh/x/x/x CC Status De-glitch Timeout Parameter
#define CND003_U3TYPECCFG_GPIO_INTR_ENABLE 0x20 // GPIO Interrupt Enable
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_021  0xF000  // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_RCVDET_P1_INTEN  BIT11   // 0/x/x/x Type-C Port1 RCVDET Interrupt Enable
    #define CND003_U3TYPECCFG_RCVDET_P0_INTEN  BIT10   // 0/x/x/x Type-C Port0 RCVDET Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO9_INTEN BIT9    // 0/x/x/x Type-C GPIO9 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO8_INTEN BIT8    // 0/x/x/x Type-C GPIO8 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO7_INTEN BIT7    // 0/x/x/x Type-C GPIO7 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO6_INTEN BIT6    // 0/x/x/x Type-C GPIO6 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO5_INTEN BIT5    // 0/x/x/x Type-C GPIO5 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO4_INTEN BIT4    // 0/x/x/x Type-C GPIO4 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO3_INTEN BIT3    // 0/x/x/x Type-C GPIO3 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO2_INTEN BIT2    // 0/x/x/x Type-C GPIO2 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO1_INTEN BIT1    // 0/x/x/x Type-C GPIO1 Interrupt Enable
    #define CND003_U3TYPECCFG_CCBMCGPIO0_INTEN BIT0    // 0/x/x/x Type-C GPIO0 Interrupt Enable
#define CND003_U3TYPECCFG_GPIO_INTR_STA 0x22 // GPIO Interrupt Status
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_023  0xF000  // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_R_RCVDET_P1_INT  BIT11   // 0/x/x/x Type-C Port1 RCVDET Interrupt
    #define CND003_U3TYPECCFG_R_RCVDET_P0_INT  BIT10   // 0/x/x/x Type-C Port0 RCVDET Interrupt
    #define CND003_U3TYPECCFG_R_GPIO9_INT      BIT9    // 0/x/x/x Type-C GPIO9 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO8_INT      BIT8    // 0/x/x/x Type-C GPIO8 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO7_INT      BIT7    // 0/x/x/x Type-C GPIO7 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO6_INT      BIT6    // 0/x/x/x Type-C GPIO6 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO5_INT      BIT5    // 0/x/x/x Type-C GPIO5 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO4_INT      BIT4    // 0/x/x/x Type-C GPIO4 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO3_INT      BIT3    // 0/x/x/x Type-C GPIO3 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO2_INT      BIT2    // 0/x/x/x Type-C GPIO2 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO1_INT      BIT1    // 0/x/x/x Type-C GPIO1 Interrupt Status
    #define CND003_U3TYPECCFG_R_GPIO0_INT      BIT0    // 0/x/x/x Type-C GPIO0 Interrupt Status
#define CND003_U3TYPECCFG_GPIO_INTR_MODE 0x24 // GPIO Interrupt Mode
    #define CND003_U3TYPECCFG_CCBMCGPIO7_INT_MODE  (BIT14 + BIT15) // 0/x/x/x GPIO7 Interrupt 1 or 0Vvalid
    #define CND003_U3TYPECCFG_CCBMCGPIO6_INT_MODE  (BIT12 + BIT13) // 0/x/x/x GPIO6 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO5_INT_MODE  (BIT10 + BIT11) // 0/x/x/x GPIO6 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO4_INT_MODE  (BIT8 + BIT9)   // 0/x/x/x GPIO4 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO3_INT_MODE  (BIT6 + BIT7)   // 0/x/x/x GPIO3 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO2_INT_MODE  (BIT4 + BIT5)   // 0/x/x/x GPIO2 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO1_INT_MODE  (BIT2 + BIT3)   // 0/x/x/x GPIO1 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO0_INT_MODE  (BIT0 + BIT1)   // 0/x/x/x GPIO0 Interrupt 1 or 0 Valid
#define CND003_U3TYPECCFG_GPIO_INTR_MODE_Z1 0x26 // GPIO Interrupt Mode
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_027      0xFF00          // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_U3TYPEC_CFG_026      0xF0            // 0/x/x/x Reserved
    #define CND003_U3TYPECCFG_CCBMCGPIO9_INT_MODE  (BIT2 + BIT3)   // 0/x/x/x GPIO9 Interrupt 1 or 0 Valid
    #define CND003_U3TYPECCFG_CCBMCGPIO8_INT_MODE  (BIT0 + BIT1)   // 0/x/x/x GPIO8 Interrupt 1 or 0 Valid
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
