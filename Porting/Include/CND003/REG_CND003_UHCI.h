//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_D16F0F1F2_USB11_R091(A0).doc.
#ifndef IRS_CND003_D16F0F1F2_USB11_R100_A0__H
#define IRS_CND003_D16F0F1F2_USB11_R100_A0__H
// D16F0-F2
#define IOEUHCI_VID 0x0 // Vendor ID
    #define IOEUHCI_VID_Z1 IOEUHCI_VID // 1106h/R/x/x Vendor ID Code
#define IOEUHCI_DID 0x2 // Device ID
    #define IOEUHCI_DEVID IOEUHCI_DID // 3038h/R/x/x Device ID
#define IOEUHCI_PCI_CMD 0x4 // PCI Command
    #define IOEUHCI_INTR_DIS    BIT10   // 0/0/x/x Interrupt Control
    #define IOEUHCI_FB2BKENR    BIT9    // 0/R/x/x Reserved
    #define IOEUHCI_SERREN      BIT8    // 0/R/x/x Reserved
    #define IOEUHCI_RSTEP       BIT7    // 0/R/x/x Reserved
    #define IOEUHCI_RPTYERR     BIT6    // 0/R/x/x Reserved
    #define IOEUHCI_VGASNP      BIT5    // 0/R/x/x Reserved
    #define IOEUHCI_MWRMEN      BIT4    // 0/1/x/x Memory Write and Invalidate
    #define IOEUHCI_SPCYL       BIT3    // 0/R/x/x Respond To Special Cycle
    #define IOEUHCI_BMASTREN    BIT2    // 0/1/x/x Bus Master
    #define IOEUHCI_MMSPACE     BIT1    // 0/1/x/x Memory Space Access
    #define IOEUHCI_IOSPACE     BIT0    // 0/1/x/x I/O Space Access
#define IOEUHCI_PCI_STA 0x6 // PCI Status
    #define IOEUHCI_TSERRS      BIT14                   // 0/R/x/x Reserved
    #define IOEUHCI_TMABORTS    BIT13                   // 0/0/x/x Received Master Abort (Except Special Cycle)
    #define IOEUHCI_TTABORTR    BIT12                   // 0/0/x/x Received Target Abort
    #define IOEUHCI_STABORT     BIT11                   // 0/R/x/x Reserved
    #define IOEUHCI_DEVS        (BIT9 + BIT10)          // 01b/R/x/x DEVSEL# Timing
    #define IOEUHCI_PSTATUS_8_4 0x1F0                   // 01h/R/x/x Fixed at 01h (for PCI PMI)
    #define IOEUHCI_PSTATUS_3   BIT3                    // 0/0/x/x Interrupt Status
    #define IOEUHCI_PSTATUS_2_0 (BIT0 + BIT1 + BIT2)    // 0/R/x/x Fixed at 0 (for PCI PMI)
#define IOEUHCI_REV_ID 0x8 // Revision ID
    #define IOEUHCI_REVID_8 IOEUHCI_REV_ID // A0h/R/x/x Revision ID
#define IOEUHCI_CLASS_CODE 0x9 // Class Code
    #define IOEUHCI_CLS_COD IOEUHCI_CLASS_CODE // 0C 0300h/R/x/x Class Code
#define IOEUHCI_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define IOEUHCI_CACHLINE IOEUHCI_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define IOEUHCI_LATENCY_TIMER 0xD // Latency Timer
    #define IOEUHCI_LAT_TM IOEUHCI_LATENCY_TIMER // 0/x/x/x Latency Timer
#define IOEUHCI_HDR_TYPE 0xE // Header Type
    #define IOEUHCI_HDTYPE IOEUHCI_HDR_TYPE // 80h/R/x/x Header Type
#define IOEUHCI_BIST 0xF // Built In Self Test (BIST)
    #define IOEUHCI_BIST_Z1 IOEUHCI_BIST // 0/R/x/x BIST
#define IOEUHCI_USB_IO_REG_BASE_ADR 0x20 // USB I/O Register Base Address
    #define IOEUHCI_IOBASE_31_6 0xFFFF0000  // 0/0/x/x Reserved
    #define IOEUHCI_IOBASE_15_5 0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define IOEUHCI_IOBASE_4_0  0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define IOEUHCI_SVID 0x2C // Subsystem Vendor ID
    #define IOEUHCI_SUBVID IOEUHCI_SVID // 1106h/1106h/x/x Subsystem Vendor ID
#define IOEUHCI_SSID 0x2E // Subsystem ID
    #define IOEUHCI_SUBSID IOEUHCI_SSID // 3038h/3038h/x/x Subsystem ID
#define IOEUHCI_CAP_PTR 0x34 // Capability Pointer
    #define IOEUHCI_CAP_PTR_Z1 IOEUHCI_CAP_PTR // 80h/R/x/x Capability Pointer
#define IOEUHCI_INTR_LINE 0x3C // Interrupt Line
    #define IOEUHCI_INTLN_7_4   0xF0    // 0/0/x/x Reserved
    #define IOEUHCI_INTLN_3_0   0xF     // 0000b/x/x/x USB Interrupt Routing
#define IOEUHCI_INTR_PIN_D16F0 0x3D // Interrupt Pin (D16F0)
    #define IOEUHCI_RINTABCD IOEUHCI_INTR_PIN_D16F0 // 01h/R/x/x Interrupt Pin
#define IOEUHCI_CTL_REG_1 0x40 // Control Register 1
    #define IOEUHCI_CAHCFG              BIT7    // 0/0/x/x Reserved
    #define IOEUHCI_BABOPT              BIT6    // 1b/1/x/x Babble Option
    #define IOEUHCI_PAROPT              BIT5    // 0/0/x/x Reserved
    #define IOEUHCI_REDUCE              BIT4    // 0/0/x/x Frame Interval Select
    #define IOEUHCI_HCISPEC             BIT3    // 0/0/x/x USB Data Length Option
    #define IOEUHCI_DISIMPROVEFIFO      BIT2    // 0/0/x/x Improve FIFO Latency
    #define IOEUHCI_FCFG                BIT1    // 0/0/x/x DMA Option
    #define IOEUHCI_EN_FS_EYE_IMPROVE   BIT0    // 0/0/x/x Reserved ((Random))
#define IOEUHCI_CTL_REG_2 0x41 // Control Register 2
    #define IOEUHCI_DISSTUFF    BIT7    // 0/0/x/x USB 1.1 Improvement for EOP
    #define IOEUHCI_DISPRST     BIT6    // 0/0/x/x Reserved
    #define IOEUHCI_DISEOP      BIT5    // 0/0/x/x Reserved
    #define IOEUHCI_ENOCPY      BIT4    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEUHCI_TESTCNT     BIT3    // 0/0/x/x Reserved
    #define IOEUHCI_TRAPOPT     BIT2    // 0/0/x/x I/ O Port 60/64 Trap Option
    #define IOEUHCI_VIAPSS      BIT1    // 1b/1/x/x A20Gate Pass Through Option
    #define IOEUHCI_UIRQACT     BIT0    // 0/R/x/x Reserved
#define IOEUHCI_CTL_REG_3 0x42 // Control Register 3
    #define IOEUHCI_DISPRXDISCON    BIT7            // 0/0/x/x Reserved
    #define IOEUHCI_ENTXDLY         (BIT5 + BIT6)   // 0/0/x/x Reserved
    #define IOEUHCI_SUBIDWE         BIT4            // 0/0/x/x Enable Subsystem ID / Subsystem Vender ID Back DoorOPTIONAL
    #define IOEUHCI_DISPFUNDRN      BIT3            // 0/0/x/x Reserved
    #define IOEUHCI_DISTXDLY        BIT2            // 0/0/x/x Hold Data Transmission till FIFO Reaches Transmission Threshold
    #define IOEUHCI_OCUPY_SEL       (BIT0 + BIT1)   // 11b/11b/x/x Reserved (Do Not Program) ((Random))
#define IOEUHCI_CTL_REG_4 0x43 // Control Register 4
    #define IOEUHCI_ENBMUSMRST  BIT7    // 0/0/x/x Reserved
    #define IOEUHCI_DISRXZERO   BIT6    // 0/0/x/x Reserved
    #define IOEUHCI_DISPFIFO2   BIT5    // 0/0/x/x Reserved
    #define IOEUHCI_DISPFIFO    BIT4    // 0/0/x/x Reserved
    #define IOEUHCI_DISFFCRC1   BIT3    // 0/0/x/x Continue Transmitting Erroneous Data when FIFO Underrun ((Random))
    #define IOEUHCI_DISFFCRC0   BIT2    // 0/0/x/x Issue CRC Error Instead of Stuffing Error on FIFO Underrun ((Random))
    #define IOEUHCI_DISTXDLY2   BIT1    // 0/0/x/x Reserved
    #define IOEUHCI_ENTXDLY_1   BIT0    // 0/0/x/x Reserved
#define IOEUHCI_CTL_REG_5 0x48 // Control Register 5
    #define IOEUHCI_EN_NULLSOF_RSTNEW   BIT7            // 1b/1/x/x Reserved (Do Not Program)
    #define IOEUHCI_NULLSOF_SEL         (BIT5 + BIT6)   // 00b/010b/x/x Reserved ((Random))
    #define IOEUHCI_DISPLATSOF          BIT4            // 0/0/x/x Reserved
    #define IOEUHCI_DISPSTUFF           BIT3            // 0/0/x/x Reserved
    #define IOEUHCI_DISFFCRC3           BIT2            // 0/0/x/x Issue Bad CRC5 in SOF after FIFO Underrun
    #define IOEUHCI_ENLONGPRESOF        BIT1            // 0/0/x/x Lengthen PreSOF Time ((Random))
    #define IOEUHCI_DISFFCRC2           BIT0            // 0/0/x/x Issue Non-Zero Bad CRC Code on FIFO Underrun ((Random))
#define IOEUHCI_CTL_REG_6 0x49 // Control Register 6
    #define IOEUHCI_EHCI_RX_OUT BIT7    // 0/0/x/x Reserved
    #define IOEUHCI_EHCI_OUT_EN BIT6    // 0/0/x/x Reserved
    #define IOEUHCI_SELSCLK     BIT5    // 0/0/x/x Bypass 32KHz RTC Clock
    #define IOEUHCI_TESTSG      BIT4    // 0/0/x/x Reset USBC Internal 12MHz Clock for UHCI ((CLK12)) Divider from 48MHz...
    #define IOEUHCI_EN_EHCI     BIT3    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEUHCI_PAS_OSC     BIT2    // 0/0/x/x Reserved (Do Not Program)
    #define IOEUHCI_E_PME_EN    BIT1    // 1b/1/x/x EHCI Supports PME Assertion in D3 Cold State
    #define IOEUHCI_U_PME_EN    BIT0    // 1b/1/x/x UHCI Supports PME Assertion in D3 Cold State
#define IOEUHCI_CTL_REG_7 0x4A // Control Register 7
    #define IOEUHCI_TIMEOUT_PARM    0xF8    // 14h/14h/x/x USB 1.1 Bus Timeout Parameter
    #define IOEUHCI_DISPLSPRE       BIT2    // 0/0/x/x Reserved
    #define IOEUHCI_EN_STPBM_HALT   BIT1    // 1b0/1b1/x/x Enable Stop Bus Master Cycle If HALT Bit Is Asserted
    #define IOEUHCI_EXTCLK60M_EN    BIT0    // 0/0/x/x Use External 60 MHz Clock
#define IOEUHCI_CTL_REG_8 0x4B // Control Register 8
    #define IOEUHCI_NEW_CCA_EN          BIT7    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEUHCI_UHCI_PCLK66_PD_EN   BIT6    // 0/01/1/1 Enable 66MHz New UHCI Dynamic Scheme (UHCI_PCLK66_PD_EN)
    #define IOEUHCI_UHCI_PCLK33_PD_EN   BIT5    // 0/01/1/1 Enable 33MHz New UHCI Dynamic Scheme (UHCI_PCLK33_PD_EN)
    #define IOEUHCI_REVID_BACKEN        BIT4    // 0/0/x/x Reserved
    #define IOEUHCI_EN_PATCH_CLKSTOP    BIT3    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEUHCI_DEBUGB_2            BIT2    // 0/0/x/x Reserved
    #define IOEUHCI_EN_GLOBRST          BIT1    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEUHCI_CLKOFF_EN           BIT0    // 1b/1/1/1 Enable Clock Auto Stop 
#define IOEUHCI_CTL_REG_9 0x4C // Control Register 9
    #define IOEUHCI_REVID_BACK IOEUHCI_CTL_REG_9 // A0h0/a0h0h/x/x Reserved
#define IOEUHCI_CTL_REG_10 0x4D // Control Register 10
    #define IOEUHCI_DEBUGC_7_4      0xF0            // 0/0/x/x Reserved
    #define IOEUHCI_DEBUGC_3_2      (BIT2 + BIT3)   // 10b/10b/x/x UHCI FIFO Select
    #define IOEUHCI_BMASTREN_SEL    BIT1            // 1b/1/x/x Bus Master Enable Select
    #define IOEUHCI_DEBUGC_0        BIT0            // 0/x/x/x Reserved
// D14F0-F2
#define IOEUHCI_DID_OPTIONAL 0x4E // Device ID OPTIONAL
    #define IOEUHCI_VID_OPTIONAL IOEUHCI_DID_OPTIONAL // 1D17h/x/x/x Vendor ID OPTIONAL
// D16F0-F2
#define IOEUHCI_SERIAL_BUS_RELEASE_NUM 0x60 // Serial Bus Release Number
    #define IOEUHCI_USBSPEC0 IOEUHCI_SERIAL_BUS_RELEASE_NUM // 10h/R/x/x Serial Bus Release Number
#define IOEUHCI_PM_CAP 0x80 // Power Management Capability
    #define IOEUHCI_PMI_REG1 IOEUHCI_PM_CAP // FFC2 9801h/R/x/x Power Management Capability
#define IOEUHCI_PM_CAP_STA 0x84 // Power Management Capability Status
    #define IOEUHCI_PME_STS     BIT15           // 0/0/x/x PME Status
    #define IOEUHCI_PME_EN      BIT8            // 0/0/x/x PME Enable
    #define IOEUHCI_PWR_STATE   (BIT0 + BIT1)   // 0/00b/x/x Power Management Capability Status
#define IOEUHCI_FLR_CAP_ID 0x98 // FLR Capability ID
    #define IOEUHCI_FLR_CID IOEUHCI_FLR_CAP_ID // 13h/R/x/x FLR Capability ID
#define IOEUHCI_NEXT_ITEM_PTR_2 0x99 // Next Item Pointer 2
    #define IOEUHCI_CAP_PTR_FLR IOEUHCI_NEXT_ITEM_PTR_2 // 00h/R/x/x Next Item Pointer 2
#define IOEUHCI_FLR_CAP_LEN_AND_VER_REG 0x9A // FLR Capability Length and Version Register
    #define IOEUHCI_FLR_CAP     BIT9    // 1b/1/x/x FLR Capability:
    #define IOEUHCI_FLR_TXPCAP  BIT8    // 1b/1/x/x TXP Capability
    #define IOEUHCI_FLR_LEN     0xFF    // 06h/06h/x/x Capability Length
#define IOEUHCI_FLR_CTL_REG 0x9C // FLR Control Register
    #define IOEUHCI_INI_FLR BIT0    // 0/0/x/x Initiate FLR
#define IOEUHCI_FLR_CAP_LEN_AND_VER_REG_Z1 0x9D // FLR Capability Length and Version Register
    #define IOEUHCI_FLR_TXP BIT0    // 0/0/x/x Transactions Pending (TXP).
#define IOEUHCI_FLR_PENDING_STA_REG 0x9E // FLR pending status Register
    #define IOEUHCI_FLR_STS BIT0    // 0/0/x/x FLR Pending Status
#define IOEUHCI_FLR_AND_VID_OPTIONAL_REG 0x9F // FLR and VID OPTIONAL Register
    #define IOEUHCI_VID_OPTIONAL_Z1     BIT2    // 0/0/X/x Vendor ID OPTIONAL
    #define IOEUHCI_FLR_CAP_OPTIONAL    BIT1    // 0/0/x/x FLR Capability Attribute Change OPTIONAL Register
    #define IOEUHCI_FLR_OPTIONAL        BIT0    // 1b/1/x/x FLR OPTIONAL
#define IOEUHCI_PORT_CONNECT_STA_GATING_REG 0xA0 // Port Connect Status Gating Register
    #define IOEUHCI_TXSE0_26US_EN   BIT2    // 0/0/x/X Fix TXSE0 2.6us Bug
    #define IOEUHCI_PORT2_CCS_GATE  BIT1    // 0/0/x/x Port 2 Connect Status Gating Register
    #define IOEUHCI_PORT1_CCS_GATE  BIT0    // 0/0/x/x Port 1 Connect Status Gating Register
#define IOEUHCI_DID_OPTIONAL_Z1 0xA1 // Device ID OPTIONAL
    #define IOEUHCI_DID_OPTIONAL_Z2 IOEUHCI_DID_OPTIONAL_Z1 // 3038h/x/x/x Device ID OPTIONAL
#define IOEUHCI_FRAME_INTERVAL_CFG_VALUE 0xA4 // Frame Interval Configure Value
    #define IOEUHCI_REDUN_BIT       BIT15   // 0/0/x/x Reserved
    #define IOEUHCI_FMINTV_VAL_EN   BIT14   // 0/x/x/x Frame Interval Configure Value Enable
    #define IOEUHCI_FMINTV_VAL      0x3FFF  // 49Fh/x/x/x Frame Interval Configure Value
#define IOEUHCI_CCA_BUS_SRC_ID_D16F0 0xA6 // CCA BUS Source ID (D16F0)
    #define IOEUHCI_UBDF IOEUHCI_CCA_BUS_SRC_ID_D16F0 // 80h/x/x/x CCA BUS source ID
#define IOEUHCI_LEGACY_SUPPORT_FOR_UHCI_V1_1_COMPLIANT 0xC0 // Legacy Support (for UHCI v1.1 Compliant)
    #define IOEUHCI_A20PTS      BIT15   // 0/x/x/x End of A20Gate Pass Through Status (A20PTS)
    #define IOEUHCI_RESV_LEG    BIT14   // 0/R/x/x Reserved
    #define IOEUHCI_UIRQEN      BIT13   // 1b/x/x/x USB PIRQ Enable (USBPIRQDEN)
    #define IOEUHCI_LEGSUP_12   BIT12   // 0/R/x/x USB IRQ Status (USBIRQS)
    #define IOEUHCI_TBY64W      BIT11   // 0/x/x/x Trap By 64h Write Status (TBY64W)
    #define IOEUHCI_TBY64R      BIT10   // 0/x/x/x Trap By 64h Read Status (TBY64R)
    #define IOEUHCI_TBY60W      BIT9    // 0/x/x/x Trap By 60h Write Status (TBY60W)
    #define IOEUHCI_TBY60R      BIT8    // 0/x/x/x Trap By 60h Read Status (TBY60R)
    #define IOEUHCI_SMIEPTE     BIT7    // 0/x/x/x SMI At End Of Pass Through Enable (SMIEPTE)
    #define IOEUHCI_PSS         BIT6    // 0/R/x/x Pass Through Status (PSS)
    #define IOEUHCI_A20PTEN     BIT5    // 0/x/x/x A20Gate Pass Through Enable (A20PTEN)
    #define IOEUHCI_USMIEN      BIT4    // 0/x/x/x Trap / SMI ON IRQ Enable (USBSMIEN)
    #define IOEUHCI_U64WEN      BIT3    // 0/x/x/x Trap / SMI On 64h Write Enable (64WEN)
    #define IOEUHCI_U64REN      BIT2    // 0/x/x/x Trap / SMI On 64h Read Enable (64REN)
    #define IOEUHCI_U60WEN      BIT1    // 0/x/x/x Trap / SMI On 60h Write Enable (60WEN)
    #define IOEUHCI_U60REN      BIT0    // 0/x/x/x Trap / SMI On 60h Read Enable (60REN)
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
