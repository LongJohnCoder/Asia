//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_IOEEHCI_USB20_R110(A0).doc.
#ifndef IRS_CND003_IOEEHCI_USB20_R110_A0__H
#define IRS_CND003_IOEEHCI_USB20_R110_A0__H
// IOEEHCI
#define IOEEHCI_VID 0x0 // Vendor ID
    #define IOEEHCI_VID_Z1 IOEEHCI_VID // 1106h/R/x/x Vendor ID
#define IOEEHCI_DID 0x2 // Device ID
    #define IOEEHCI_DEVID IOEEHCI_DID // 3104h/R/x/x Device ID Code
#define IOEEHCI_PCI_CMD 0x4 // PCI Command
    #define IOEEHCI_INTR_DIS  BIT10   // 0/0/x/x Interrupt Control
    #define IOEEHCI_MWRMEN    BIT4    // 0/1/x/x Memory Write and Invalidate
    #define IOEEHCI_SPCYL     BIT3    // 0/R/x/x Reserved 
    #define IOEEHCI_BMASTREN  BIT2    // 0/1/x/x Bus Master
    #define IOEEHCI_MMSPACE   BIT1    // 0/1/x/x Memory Space
    #define IOEEHCI_IOSPACE   BIT0    // 0/1/x/x I/O Space
#define IOEEHCI_PCI_STA 0x6 // PCI Status
    #define IOEEHCI_TMABORTS      BIT13                   // 0/x/x/x Received Master Abort (Except Special Cycle)
    #define IOEEHCI_TTABORTR      BIT12                   // 0/x/x/x Received Target Abort
    #define IOEEHCI_DEVS          (BIT9 + BIT10)          // 01b/R/x/x DEVSEL# Timing
    #define IOEEHCI_PSTATUS_8_4   0x1F0                   // 01h/R/x/x Fixed at 01h (for PCI PMI)
    #define IOEEHCI_PSTATUS_3     BIT3                    // 0/x/x/x Interrupt Status
#define IOEEHCI_REV_ID 0x8 // Revision ID
    #define IOEEHCI_REVID_08 IOEEHCI_REV_ID // 90h/R/x/x Revision ID
#define IOEEHCI_CLASS_CODE 0x9 // Class Code
    #define IOEEHCI_CLS_COD IOEEHCI_CLASS_CODE // 0C 0320h/R/x/x Class Code for USB2.0 EHCI Host Controller
#define IOEEHCI_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define IOEEHCI_CACHLINE IOEEHCI_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define IOEEHCI_LATENCY_TIMER 0xD // Latency Timer
    #define IOEEHCI_LAT_TM IOEEHCI_LATENCY_TIMER // 0/x/x/x Latency Timer
#define IOEEHCI_HDR_TYPE 0xE // Header Type
    #define IOEEHCI_HDTYPE IOEEHCI_HDR_TYPE // 80h/R/x/x Header Type
#define IOEEHCI_BIST 0xF // Built In Self Test (BIST)
    #define IOEEHCI_BIST_Z1 IOEEHCI_BIST // 0/R/x/x BIST
#define IOEEHCI_EHCI_MEM_MAPPED_IO_BASE_ADR 0x10 // EHCI Memory Mapped I/O Base Address
    #define IOEEHCI_IOBASE    0xFFFFFF00      // 0/x/x/x EHCI Memory Mapped I/O Registers Base Address
    #define IOEEHCI_CAP_64B   (BIT1 + BIT2)   // 00b/R/x/x Memory Mapping
#define IOEEHCI_EHCI_MEM_MAPPED_IO_BASE_ADR_HIGH_32_BIT 0x14 // EHCI Memory Mapped I/O Base Address (High 32-bit)
    #define IOEEHCI_IOBASE_H IOEEHCI_EHCI_MEM_MAPPED_IO_BASE_ADR_HIGH_32_BIT // 0/x/x/x EHCI Memory Mapped I/O Registers High 32-bit Base Address
#define IOEEHCI_SVID 0x2C // Subsystem Vendor ID
    #define IOEEHCI_SUBVID IOEEHCI_SVID // 1106h/1106h/x/x Subsystem Vendor ID
#define IOEEHCI_SSID 0x2E // Subsystem ID
    #define IOEEHCI_SUBSID IOEEHCI_SSID // 3104h/3104h/x/x Subsystem ID
#define IOEEHCI_CAP_PTR 0x34 // Capability Pointer
    #define IOEEHCI_CAP_PTR_Z1 IOEEHCI_CAP_PTR // 80h/R/x/x Capability Pointer
#define IOEEHCI_INTR_LINE 0x3C // Interrupt Line
    #define IOEEHCI_INTLN_7_4 0xF0    // 0/x/x/x Reserved
    #define IOEEHCI_INTLN_3_0 0xF     // 0000b/x/x/x USB Interrupt Routing
#define IOEEHCI_INTR_PIN 0x3D // Interrupt Pin
    #define IOEEHCI_RINTABCD IOEEHCI_INTR_PIN // 04h/R/x/x Interrupt Pin
#define IOEEHCI_MIN_GNT 0x3E // Min_Gnt
    #define IOEEHCI_MINGNT IOEEHCI_MIN_GNT // 0/R/x/x Minimal Burst Period
#define IOEEHCI_MAX_LAT 0x3F // Max_Lat
    #define IOEEHCI_MAXLAT IOEEHCI_MAX_LAT // 0/R/x/x Frequency for Gain PCI Bus
#define IOEEHCI_CTL_REG_1 0x40 // Control Register 1
    #define IOEEHCI_CAHCFG    BIT7    // 0/0/x/x EPHY PDSUSMOD / PDAPLL Control Mechanism Selection
    #define IOEEHCI_BABOPT    BIT6    // 0/0/x/x Babble Option
    #define IOEEHCI_PAROPT    BIT5    // 0/0/x/x Reserved
    #define IOEEHCI_REDUCE    BIT4    // 0/0/x/x Micro-Frame Interval Select
    #define IOEEHCI_HCISPEC   BIT3    // 0/0/x/x Reserved
    #define IOEEHCI_DAC_EN    BIT2    // 0/0/x/x DAC Enable
    #define IOEEHCI_FCFG      BIT1    // 0/0/1/0 DMA Option ((Random))
    #define IOEEHCI_C4P_REDU  BIT0    // 0/0/x/x Reserved
#define IOEEHCI_TEST_CTL_1 0x41 // Test Control 1
    #define IOEEHCI_DISSTUFF          BIT7    // 0/0/x/x Reserved
    #define IOEEHCI_CHK_NULLSOF_SEL   BIT6    // 0/0/x/x Reserved
    #define IOEEHCI_EN_CHKPERIODEN    BIT5    // 1b/1b/1/x Enable Evaluate PERIODIC Enable Bit only at the Beginning of Micro-...
    #define IOEEHCI_ENOCPY            BIT4    // 0/0/x/x Reserved
    #define IOEEHCI_TESTCNT           BIT3    // 0/0/x/x Reserved
    #define IOEEHCI_TRAPOPT           BIT2    // 0/0/x/x Reserved
    #define IOEEHCI_TST_SQUELCH_EN    BIT1    // 0/0/x/x Reserved
    #define IOEEHCI_UIRQACT           BIT0    // 0/R/x/x Reserved
#define IOEEHCI_CTL_REG_2 0x42 // Control Register 2
    #define IOEEHCI_SELEOF                BIT7                    // 0/0/x/x Reserved
    #define IOEEHCI_EN_PRESOFCHK          BIT6                    // 1b/1b/1/x Enable Check PRESOF for ITD (Isochronous Transfer Descriptor) OUT T...
    #define IOEEHCI_EN_ISOFF_RST_ANYTIME  BIT5                    // 0/0/x/x Reserved
    #define IOEEHCI_SUBIDWE               BIT4                    // 0/0/x/x Reserved
    #define IOEEHCI_ISOFF_RST_EN          BIT3                    // 0/0/x/x Reserved
    #define IOEEHCI_OCUPY_SEL             (BIT0 + BIT1 + BIT2)    // 011b/011b/011b/011b Reserved (Do Not Program)
#define IOEEHCI_CTL_REG_3 0x43 // Control Register 3
    #define IOEEHCI_DIS_TERM_ON_H BIT7    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_G BIT6    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_F BIT5    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_E BIT4    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_D BIT3    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_C BIT2    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_B BIT1    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_A BIT0    // 0/0/x/x Reserved
#define IOEEHCI_CTL_REG_4 0x44 // Control Register 4
    #define IOEEHCI_DEBUG31_7_2   0xFC    // 0/x/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_J BIT1    // 0/0/x/x Reserved
    #define IOEEHCI_DIS_TERM_ON_I BIT0    // 0/0/x/x Reserved
#define IOEEHCI_CTL_REG_45 0x45 // Control Register 45
    #define IOEEHCI_VIOD          0xFE    // 0/x/x/x Reserved
    #define IOEEHCI_HSRXACT_DLYEN BIT0    // 0/0/x/x EPHY HSTX/RXACT Delay Control
#define IOEEHCI_CTL_REG_5 0x48 // Control Register 5
    #define IOEEHCI_DISCHKEOPERR  BIT7    // 1b/1/x/x USB 2.0 EOP Pattern (FEh) Error Check
    #define IOEEHCI_ENISOHANDCHK  BIT6    // 0/0/x/x Extra Handshake Error Checking in Isochronous Transaction
    #define IOEEHCI_DIS_BURST     BIT5    // 1b/1/0/x DMA Burst Access((Random))
    #define IOEEHCI_EN_REF_RVLD   BIT4    // 1b/1/x/x USB 2.0 Reference Bus Idle Status
    #define IOEEHCI_EN_PATCH_HEAD BIT3    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEEHCI_EN_UTM_RESET  BIT2    // 1b/1/x/x Reserved (Do Not Program) 
    #define IOEEHCI_EN_CHKTOGCRC  BIT1    // 1b/1/x/x USB 2.0 CRC16 Check Enable for Toggle Mismatch
    #define IOEEHCI_HSENFB_DIS    BIT0    // 0/0/x/x HS (High Speed) Port Align to Micro-Frame Boundary
#define IOEEHCI_CTL_REG_6 0x49 // Control Register 6
    #define IOEEHCI_TXDELAY_EN            BIT7            // 0/0/x/x MAC Allows More Delay between Transactions
    #define IOEEHCI_TXTMOUT_EN            BIT6            // 1b/1/1/1 MAC Provides Timeout to Device When Receiver Detects Error
    #define IOEEHCI_CLKOFF_EN             BIT5            // 1b/1/x/1 EHCI Clock Auto Stop ((Random))
    #define IOEEHCI_DISPDRCV              BIT4            // 0/0/x/0 Auto Power Down Receiver Squelch Detector
    #define IOEEHCI_NEW_USB_C4P_EN        BIT3            // 1b/1/x/1 Enable New USB C4P State 
    #define IOEEHCI_C4P_48MPLLOFF         BIT2            // 0/0/x/x USB Analog PLL Control When Entering C4P State 
    #define IOEEHCI_NEW_USB_NULLSOF_SEL   (BIT0 + BIT1)   // 00b/00b/x/x USB HS NULL-SOF (Null Start Of Frame) Valid Time Selection (for C...
#define IOEEHCI_MAC_INTER_TRANSACTION_DELAY_PARAM 0x4A // MAC Inter-Transaction Delay Parameter
    #define IOEEHCI_TXDELAY_PARM IOEEHCI_MAC_INTER_TRANSACTION_DELAY_PARAM // 0/0/x/x MAC Inter-Transaction Delay Parameter
#define IOEEHCI_MAC_TURN_AROUND_TIME_PARAM 0x4B // MAC Turn Around Time Parameter
    #define IOEEHCI_DIS_NARROW_SOF    BIT7            // 0/0/x/x SOF (Start of Frame) Disconnects Detection Period
    #define IOEEHCI_SLEEPTIME_SEL     (BIT5 + BIT6)   // 00b/00b/*10b/*11b EHCI Sleep Time Select ((Random))
    #define IOEEHCI_DIS_SOF_RUN       BIT4            // 0/0/x/x Disable Sending UTM_SOF (Start of Frame of USB Transceiver Macrolcell...
    #define IOEEHCI_TURN_PARM         0xF             // 9h/9h/x/x USB 2.0 MAC Transmit Turn Around Time Parameter
#define IOEEHCI_PHY_CTL_1 0x4C // PHY Control 1
    #define IOEEHCI_C4PR_FASTACK      BIT7            // 0/0/x/x Resume ACK Control
    #define IOEEHCI_EN_BMASTR_AUTODIS BIT6            // 0/0/x/x Reserved
    #define IOEEHCI_EN_UTM_SPDUP      BIT5            // 0/0/x/x USB1.0 UTM (USB Transceiver Macrocell) Tx Speed Up
    #define IOEEHCI_EN_DBG_PORT       BIT4            // 1b/1/x/x USB2.0 EHCI Debug Port Support Enable
    #define IOEEHCI_SYNC_FAST         BIT3            // 0/0/x/x USB2.0 Receiver Fast Sync Pattern Detect 
    #define IOEEHCI_SYNC_JEND         BIT2            // 0/0/x/x Enable USB2.0 Receiver Sync Pattern Detect with ?J?_End 
    #define IOEEHCI_DEBUGC_1_0        (BIT0 + BIT1)   // 0/x/x/x Reserved
#define IOEEHCI_PHY_CTL_2 0x4D // PHY Control 2
    #define IOEEHCI_DBG_USBEN     BIT7                    // 1b/1/x/x Reserved (Do Not Program)
    #define IOEEHCI_DBGMOD_SEL    (BIT5 + BIT6)           // 0/0/x/x Reserved
    #define IOEEHCI_HSPRESOF_SEL  (BIT3 + BIT4)           // 10b/10b/10b/x Reserved ((Random))
    #define IOEEHCI_FIFOSIZE_SEL  (BIT0 + BIT1 + BIT2)    // 100b/100b/100b/x Reserved (Do Not Program)
#define IOEEHCI_USB_CP4_CTL_0 0x4E // USB CP4 Control 0
    #define IOEEHCI_SUSPEND_TIME_SEL      BIT7            // 0/0/x/x Suspend Time Select ((Random))
    #define IOEEHCI_RESUME_SEL            (BIT5 + BIT6)   // 0/00/x/x Reserved ((Random))
    #define IOEEHCI_EN_UCONNDET           BIT4            // 0/0/x/x Reserved ((Random))
    #define IOEEHCI_ASYNC_SLEEP_SEL       BIT3            // 0/0/x/x Long Time Sleep Method Selection to Get the New Asynchronous List
    #define IOEEHCI_ASYNC_IDLE_SEL        (BIT1 + BIT2)   // 01b/01b/x/x Standard of Asynchronous List IDLE
    #define IOEEHCI_EN_PATCH_GOLDENTREE   BIT0            // 1b/1b/x/x Enable Patch Golden Tree
#define IOEEHCI_USB_C4P_CTL_1 0x4F // USB C4P Control 1
    #define IOEEHCI_EN_RST_NULLSOF_AT_PORTRST BIT7    // 0/0/x/x Enable Reset NULLSOF Counter During PortRst  Process
    #define IOEEHCI_EN_C4P_LG1MF              BIT6    // 0/0/x/x Enable Waiting Over 1 microFrame After C4P 20ms Resume Time, Before S...
    #define IOEEHCI_C4P_RUNSET_SEL            BIT5    // 0/0/x/x Select When Recovering RUN Bit After C4P State
    #define IOEEHCI_EN_CLEAR_RUN              BIT4    // 0/0/x/x Enable Clear RUN Bit When EHCI_IDLE If S/W Clears RUN Bit
    #define IOEEHCI_EN_PORTRST_INC4P          BIT3    // 0/0/x/x Reserved
    #define IOEEHCI_NULLSOF_DET_SEL           BIT2    // 0/0/x/x Select Signal to Detect NULLSOF_VALID
    #define IOEEHCI_EN_HALT_C4PSWT            BIT1    // 0/0/x/x Enable HCHALT Bit in USBSTS S/W Transparent Under C4P State((Random))
    #define IOEEHCI_EN_PDPHY_INPDPLL          BIT0    // 0/0/x/x Reserved 
#define IOEEHCI_TEST_CMD 0x50 // Test Command
    #define IOEEHCI_EN_PATCH_DOORBELL BIT7    // 1b/1b/x/x USB 2.0 Doorbell Bit Function Patch
    #define IOEEHCI_FORCE_CRCERR      BIT6    // 0/0/x/x Reserved
    #define IOEEHCI_TEST_EYE_EN       BIT5    // 0/0/x/x Reserved
    #define IOEEHCI_UTM_CHKERR        BIT4    // 0/R/x/x Reserved
    #define IOEEHCI_BIST_ERROR        BIT3    // 0/R/x/x Reserved
    #define IOEEHCI_BIST_RUN          BIT2    // 0/R/x/x Reserved
    #define IOEEHCI_SWDBG             BIT1    // 0/0/x/x Reserved
    #define IOEEHCI_TEST_COMMAND_0    BIT0    // 0/R/x/x Reserved
#define IOEEHCI_USB_2_0_MAC_TIMEOUT_PARAM 0x51 // USB 2.0 MAC Timeout Parameter
    #define IOEEHCI_TMOUT_PARM IOEEHCI_USB_2_0_MAC_TIMEOUT_PARAM // 60h/60h/x/x USB 2.0 Receiver Timeout Parameter
#define IOEEHCI_CTL_REG_6_Z1 0x52 // Control Register 6
    #define IOEEHCI_SUS_DEBUG0            BIT7    // 1b/1/x/x C4P State Request Control
    #define IOEEHCI_SUS_DEBUG1            BIT6    // 1b/0/x/x PLLOK Selection Control
    #define IOEEHCI_EN_OUTC4P_NULLSOF_RST BIT4    // 1b/1/x/x Reset NULLSOF and NULLSOF Counter When Exiting C4P State
    #define IOEEHCI_EN_C4P_IOCINT         BIT3    // 0/0/x/x Send Out Interrupt of IOC (Interrupt On Complete) and Roll Over When ...
    #define IOEEHCI_EN_USB_C4P_NOD3       BIT2    // 0/1/x/x Enable USB Responding to PMU C4P State Request by Entering / Exiting ...
    #define IOEEHCI_EN_NEW_PDAPLL         BIT1    // 0/0/x/0 Enable New PLL Power Down Scheme 
    #define IOEEHCI_EN_NEW_PDHSDRV        BIT0    // 01b/01b/x/10 USB Physical Circuitry Power Down Condition
#define IOEEHCI_PORT_CTL_REG_1 0x53 // Port Control Register 1
    #define IOEEHCI_RESUME_EN8    BIT7    // 1b/1/x/x Reserved
    #define IOEEHCI_RESUME_EN7    BIT6    // 1b/1/x/x Reserved
    #define IOEEHCI_RESUME_EN6    BIT5    // 1b/1/x/x Port 6 Resume Enable
    #define IOEEHCI_RESUME_EN5    BIT4    // 1b/1/x/x Port 5 Resume Enable
    #define IOEEHCI_RESUME_EN4    BIT3    // 1b/1/x/x Port 4 Resume Enable
    #define IOEEHCI_RESUME_EN3    BIT2    // 1b/1/x/x Port 3 Resume Enable
    #define IOEEHCI_RESUME_EN2    BIT1    // 1b/1/x/x Port 2 Resume Enable
    #define IOEEHCI_RESUME_EN1    BIT0    // 1b/1/x/x Port 1 Resume Enable
#define IOEEHCI_PORT_CTL_REG_2 0x54 // Port Control Register 2
    #define IOEEHCI_SUS_DEBUG_15_11   0xF8    // 0/x/x/x Reserved
    #define IOEEHCI_CONN_EN_REG       BIT2    // 1b/1/x/x Detect Device Connection If D+/D- = 1/1
    #define IOEEHCI_RESUME_EN10       BIT1    // 1b/1/x/x Reserved
    #define IOEEHCI_RESUME_EN9        BIT0    // 1b/1/x/x Reserved
#define IOEEHCI_PHY_CTL_7 0x58 // PHY Control 7
    #define IOEEHCI_IAAD_INT          BIT7    // 1b/1/x/x Async Advance Interrupt Lost Issue Patch
    #define IOEEHCI_ASYEN_SEL         BIT6    // 1b/1b/x/x Async Enable Condition Selection
    #define IOEEHCI_RX_BLOCK_DIS      BIT5    // 0/0/x/x Reserved
    #define IOEEHCI_TSTMOD            BIT4    // 0/0/x/x Reserved
    #define IOEEHCI_SOF_DISCONN_LATE  BIT3    // 0b/0/x/x High-Speed Disconnect During SOF Period Time Select
    #define IOEEHCI_SOF_DISCONN_CHK   BIT2    // 1b/1/1/x Detect High-Speed Disconnect During SOF Period
    #define IOEEHCI_CP1               BIT1    // 0/0/x/x Reserved
    #define IOEEHCI_CP0               BIT0    // 0/0/x/x Reserved
#define IOEEHCI_PHY_CTL_8 0x59 // PHY Control 8
    #define IOEEHCI_PDPHY_DIS     BIT7    // 0/0/x/0 Disable PHY Auto Power-Down Feature
    #define IOEEHCI_SETPOWNER_DIS BIT6    // 0/0/x/x Transit POwner (Port Owner) Control
    #define IOEEHCI_AUTOCHK       BIT5    // 0/0/x/x Reserved
    #define IOEEHCI_PHYOPT2_4_1   0x1E    // 0/x/x/x Reserved
    #define IOEEHCI_BYPASSDIV4    BIT0    // 1b/1/x/x Reserved
#define IOEEHCI_PHY_CTL_9 0x5C // PHY Control 9
    #define IOEEHCI_RXDATADLY_2   BIT6            // 0/0/x/x High Speed Transmitter
    #define IOEEHCI_RXDATADLY_1_0 (BIT4 + BIT5)   // 00b/00b/x/x DPLL Input Data Delay Select
#define IOEEHCI_SERIAL_BUS_RELEASE_NUM 0x60 // Serial Bus Release Number
    #define IOEEHCI_USBSPEC IOEEHCI_SERIAL_BUS_RELEASE_NUM // 20h/R/x/x Serial Bus Release Number
#define IOEEHCI_FRAME_LEN_ADJ 0x61 // Frame Length Adjustment
    #define IOEEHCI_FLADJ 0x3F            // 20h/20h/x/x Frame Length Adjustment
#define IOEEHCI_PORT_WAKE_CAP 0x62 // Port Wake Capability
    #define IOEEHCI_PORTWAKECAP   0x7FE   // 0/0/x/x Port Wake Up Capability Mask
    #define IOEEHCI_PORTWAKECAP0  BIT0    // 1b/R/x/x Port Wake Capability Register Implementation
#define IOEEHCI_USB_CP4_CTL_1 0x64 // USB CP4 Control 1
    #define IOEEHCI_SELFWAKE_MFSEL    (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define IOEEHCI_SELFWAKE_TMSEL    (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define IOEEHCI_SELFWAKE_EN       BIT3            // 0/0/x/x Reserved ((Random))
    #define IOEEHCI_NULLSOF_SEL_2     BIT2            // 0/0/x/x USB HS NULL-SOF (Null Start Of Frame) Valid Time Selection Extend Bit...
    #define IOEEHCI_HSISO_C4INH_EN    BIT1            // 1b0/1b0/x/x Reserved
    #define IOEEHCI_UHCISO_C4INH_EN   BIT0            // 1b0/1b0/x/x Reserved
#define IOEEHCI_CTL_REG 0x65 // Control Register
    #define IOEEHCI_REDUN_BIT1        (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define IOEEHCI_NEW_PCLK33_PD_EN  BIT5            // 0/0/1/1 Enable 33MHz Dynamic Scheme ((Random))
    #define IOEEHCI_NEW_PCLK66_PD_EN  BIT4            // 0/0/1/1 Enable 66MHz Dynamic Scheme ((Random))
    #define IOEEHCI_QHCIGNT_SEL       BIT3            // 1b/1/x/x Async Controller Bus Authority Selection
    #define IOEEHCI_COMPL_EOT         BIT2            // 1b/1/x/x Reserved
    #define IOEEHCI_BMASTREN_SEL      BIT1            // 0/0/1/x Bus Master Enable Select
    #define IOEEHCI_DBGMODE_SEL_2     BIT0            // 0/0/x/x Reserved
#define IOEEHCI_USB_LEGACY_SUPPORT_EXTENDED_CAP 0x68 // USB Legacy Support Extended Capability
    #define IOEEHCI_OSOWNS            BIT24       // 0/x/x/x USB Host Controller ((HC)) OS-owned Semaphore
    #define IOEEHCI_BIOSOWNS          BIT16       // 0/x/x/x USB Host Controller ((HC)) BIOS-owned Semaphore
    #define IOEEHCI_USBLEGSUP_15_8    0xFF00      // 0/R/x/x Next EHCI Extended Capability Pointer
    #define IOEEHCI_USBLEGSUP_7_0     0xFF        // 01h/R/x/x Capability ID
#define IOEEHCI_USB_LEGACY_SUPPORT_CTL_STA 0x6C // USB Legacy Support Control / Status
    #define IOEEHCI_SMIONBAR      BIT31       // 0/x/x/x SMI on BAR
    #define IOEEHCI_SMIONPCMD     BIT30       // 0/x/x/x SMI on PCI Command
    #define IOEEHCI_SMIOSOWNCHG   BIT29       // 0/x/x/x SMI on OS Ownership Change
    #define IOEEHCI_USBSTS_5      BIT21       // 0/R/x/x SMI on Ssync Advance
    #define IOEEHCI_USBSTS_4      BIT20       // 0/R/x/x SMI on Host System Error
    #define IOEEHCI_USBSTS_3      BIT19       // 0/R/x/x SMI on Frame List Rollover
    #define IOEEHCI_USBSTS_2      BIT18       // 0/R/x/x SMI on Port Change Detect
    #define IOEEHCI_USBSTS_1      BIT17       // 0/R/x/x SMI on USB Error
    #define IOEEHCI_USBSTS_0      BIT16       // 0/R/x/x SMI on USB Complete
    #define IOEEHCI_SMIONBAR_EN   BIT15       // 0/x/x/x SMI on BAR Enable
    #define IOEEHCI_SMIONPCMD_EN  BIT14       // 0/x/x/x SMI on PCI Command Enable
    #define IOEEHCI_SMIOWN_EN     BIT13       // 0/x/x/x SMI on OS Ownership Enable
    #define IOEEHCI_SMIASYNC_EN   BIT5        // 0/x/x/x SMI on Async Advance Enable
    #define IOEEHCI_SMIHERR_EN    BIT4        // 0/x/x/x SMI on Host System Error Enable
    #define IOEEHCI_SMIFROVER_EN  BIT3        // 0/x/x/x SMI on Frame List Rollover Enable
    #define IOEEHCI_SMIPORTCHG_EN BIT2        // 0/x/x/x SMI on Port Change Enable
    #define IOEEHCI_SMIUSBERR_EN  BIT1        // 0/x/x/x SMI on USB Error Enable
    #define IOEEHCI_USBSMI_EN     BIT0        // 0/x/x/x USB SMI Enable
#define IOEEHCI_SRAM_DIRECT_ACCESS_ADR 0x70 // SRAM Direct Access Address
    #define IOEEHCI_SRAM_ADDR 0x1FF   // 0/0/x/x SRAM Direct Access Address
#define IOEEHCI_SRAM_DIRECT_ACCESS_CTL 0x73 // SRAM Direct Access Control
    #define IOEEHCI_SRAM_SEL  (BIT4 + BIT5)   // 0/0/x/x SRAM Select
    #define IOEEHCI_SRAM_RUN  BIT1            // 0/0/x/x SRAM Operation Start
    #define IOEEHCI_SRAM_WR   BIT0            // 0/0/x/x SRAM Read / Write Control
#define IOEEHCI_SRAM_DATA 0x74 // SRAM Data
    #define IOEEHCI_BIST_PATTERN IOEEHCI_SRAM_DATA // 0/0/x/x SRAM Data
#define IOEEHCI_EHCI_OPTIONAL_BITS_CFG_ADR 0x78 // EHCI Optional Bits Configuration Address
    #define IOEEHCI_EHCI_OPT_ADD_31_20    0xFFF00000  // 0/x/x/x Reserved
    #define IOEEHCI_OPTCFGADDR            0xFFFFF     // 0/0/x/x EHCI Optional Bits Configuration Address
#define IOEEHCI_EHCI_OPTIONAL_BITS_CFG_DATA 0x7C // EHCI Optional Bits Configuration Data
    #define IOEEHCI_OPTCFGDATA IOEEHCI_EHCI_OPTIONAL_BITS_CFG_DATA // 0100 10700h/010010700h/x/x EHCI Optional Bits Configuration Data
    #define IOEEHCI_EHCI_OPTIONAL_BITS_CFG_DATA_Byte0 0x7C
    #define IOEEHCI_EHCI_OPTIONAL_BITS_CFG_DATA_Byte1 0x7D
    #define IOEEHCI_EHCI_OPTIONAL_BITS_CFG_DATA_Byte2 0x7E
    #define IOEEHCI_EHCI_OPTIONAL_BITS_CFG_DATA_Byte3 0x7F

#define IOEEHCI_PM_CAP_ID 0x80 // Power Management Capability ID
    #define IOEEHCI_PMI_REG1_7_0 IOEEHCI_PM_CAP_ID // 01h/R/x/x Power Management Capability ID
#define IOEEHCI_NEXT_ITEM_PTR_1 0x81 // Next Item Pointer 1
    #define IOEEHCI_CAP_PTR2 IOEEHCI_NEXT_ITEM_PTR_1 // 88h/R/x/x Next Item Pointer 1
#define IOEEHCI_PM_CAP 0x82 // Power Management Capability
    #define IOEEHCI_PMI_REG1_31_16 IOEEHCI_PM_CAP // FFC2h/R/x/x Power Management Capability
#define IOEEHCI_PM_CAP_CTL_STA 0x84 // Power Management Capability Control / Status
    #define IOEEHCI_PME_STS   BIT15           // 0/x/x/x PME Status
    #define IOEEHCI_PME_EN    BIT8            // 0/0/x/x PME Enable
    #define IOEEHCI_PWR_STATE (BIT0 + BIT1)   // 00b/00b/x/x Power State
#define IOEEHCI_DEBUG_PORT_CAP_ID 0x88 // Debug Port Capability ID
    #define IOEEHCI_DBG_REG_7_0 IOEEHCI_DEBUG_PORT_CAP_ID // 0Ah/R/x/x Debug Port Capability ID
#define IOEEHCI_NEXT_ITEM_PTR_2 0x89 // Next Item Pointer 2
    #define IOEEHCI_DBG_REG_15_8 IOEEHCI_NEXT_ITEM_PTR_2 // 98h/R/x/x Next Item Pointer 2
#define IOEEHCI_DEBUG_PORT_BASE_OFS 0x8A // Debug Port Base Offset
    #define IOEEHCI_DBG_REG_31_16 IOEEHCI_DEBUG_PORT_BASE_OFS // 20A0h/R/x/x Debug Port Base Offset
#define IOEEHCI_FLR_CAP_ID 0x98 // FLR Capability ID
    #define IOEEHCI_FLR_CID IOEEHCI_FLR_CAP_ID // 13h/R/x/x FLR Capability ID
#define IOEEHCI_NEXT_ITEM_PTR_2_Z1 0x99 // Next Item Pointer 2
    #define IOEEHCI_CAP_PTR_FLR IOEEHCI_NEXT_ITEM_PTR_2_Z1 // 00h/R/x/x Next Item Pointer 2
#define IOEEHCI_FLR_CAP_LEN_AND_VER_REG 0x9A // FLR Capability Length and Version Register
    #define IOEEHCI_FLR_CAP       BIT9    // 1b/1/x/x FLR Capability:
    #define IOEEHCI_FLR_TXPCAP    BIT8    // 1b/1/x/x TXP Capability
    #define IOEEHCI_FLR_LEN       0xFF    // 06h/06h/x/x Capability Length
#define IOEEHCI_FLR_CTL_REG 0x9C // FLR Control Register
    #define IOEEHCI_INI_FLR   BIT0    // 0/0/x/x Initiate FLR. 
#define IOEEHCI_FLR_CAP_LEN_AND_VER_REG_Z1 0x9D // FLR Capability Length and Version Register
    #define IOEEHCI_FLR_TXP   BIT0    // 0/0/x/x Transactions Pending (TXP)
#define IOEEHCI_FLR_PENDING_STA_REG 0x9E // FLR Pending Status Register
    #define IOEEHCI_FLR_STS   BIT0    // 0/0/x/x FLR Pending Status
#define IOEEHCI_FLR_AND_VID_OPTIONAL_REG 0x9F // FLR and VID OPTIONAL Register
    #define IOEEHCI_DBGMOD_SEL3_2     0xF0    // 0/0/x/x Debug Signal Select 2
    #define IOEEHCI_DBGMOD_SEL3_1     BIT3    // 0/0/x/x Debug Signal Select 1
    #define IOEEHCI_VID_OPTIONAL      BIT2    // 0/0/X/x Vendor ID OPTIONAL
    #define IOEEHCI_FLR_CAP_OPTIONAL  BIT1    // 0/0/x/x FLR Capability Attribute Change OPTIONAL Register
    #define IOEEHCI_FLR_OPTIONAL      BIT0    // 1b/1/x/x FLR OPTIONAL
#define IOEEHCI_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS 0xA0 // Port OC Pin Mux Select and CCS Gating Registers
    #define IOEEHCI_PORTF_OC_MUX      0xF0000000      // 0101b/0/x/x Port 6 OC Pin Mux Select Register
    #define IOEEHCI_PORTE_OC_MUX      0xF000000       // 0100b/0/x/x Port 5 OC Pin Mux Select Register
    #define IOEEHCI_PORTD_OC_MUX      0xF00000        // 0011b/0/x/x Port 4 OC Pin Mux Select register
    #define IOEEHCI_PORTC_OC_MUX      0xF0000         // 0010b/0/x/x Port 3 OC Pin Mux Select Register
    #define IOEEHCI_PORTB_OC_MUX      0xF000          // 0001b/0/x/x Port 2 OC Pin Mux Select Register
    #define IOEEHCI_PORTA_OC_MUX      0xF00           // 0000b/0/x/x Port 1 OC Pin Mux Select Register
    #define IOEEHCI_REDUN_CELL        (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define IOEEHCI_PORT6_CCS_GATE    BIT5            // 0/0/x/x Port 6 Connect Status Gating Register
    #define IOEEHCI_PORT5_CCS_GATE    BIT4            // 0/0/x/x Port 5 Connect Status Gating Register
    #define IOEEHCI_PORT4_CCS_GATE    BIT3            // 0/0/x/x Port 4 Connect Status Gating Register
    #define IOEEHCI_PORT3_CCS_GATE    BIT2            // 0/0/x/x Port 3 Connect Status Gating Register
    #define IOEEHCI_PORT2_CCS_GATE    BIT1            // 0/0/x/x Port 2 Connect Status Gating Register
    #define IOEEHCI_PORT1_CCS_GATE    BIT0            // 0/0/x/x Port 1 Connect Status Gating Register
#define IOEEHCI_FRAME_INTERVAL_CFG_VALUE 0xA4 // Frame Interval Configure Value
    #define IOEEHCI_REDUN_BIT12   (BIT14 + BIT15) // 0/0/x/x Reserved
    #define IOEEHCI_FMINTV_VAL_EN BIT13           // 0/x/x/x Frame Interval Configure Value Enable
    #define IOEEHCI_FMINTV_VAL    0x1FFF          // 743h/x/x/x Frame Interval Configure Value
#define IOEEHCI_CCA_BUS_SRC_ID 0xA6 // CCA BUS Source ID
    #define IOEEHCI_U2BDF IOEEHCI_CCA_BUS_SRC_ID // 0087h/x/x/x CCA BUS Source ID
#define IOEEHCI_PORT_6_7_8_OC_PIN_MUX_REG 0xA8 // Port 6/7/8 OC Pin Mux Register
    #define IOEEHCI_JTOK_FILTER_SEL       (BIT8 + BIT9)   // 0/0/x/x SDP/SDN Filter Glitch Setting
    #define IOEEHCI_PDAPLL_DLYEN          BIT7            // 0/0/x/x PDAPLL Delay Control
    #define IOEEHCI_CRESUME_CDC_EN        BIT6            // 0/0/x/x Fix Port CResume CDC Bug
    #define IOEEHCI_DIS_FULL_HIGH_DEV6    BIT5            // 0/x/x/x Reserved
    #define IOEEHCI_DIS_FULL_HIGH_DEV5    BIT4            // 0/x/x/x Reserved
    #define IOEEHCI_DIS_FULL_HIGH_DEV4    BIT3            // 0/x/x/x Reserved
    #define IOEEHCI_DIS_FULL_HIGH_DEV3    BIT2            // 0/x/x/x Reserved
    #define IOEEHCI_DIS_FULL_HIGH_DEV2    BIT1            // 0/x/x/x Reserved
    #define IOEEHCI_DIS_FULL_HIGH_DEV1    BIT0            // 0/x/x/x Reserved
#define IOEEHCI_CCA_BUS_SRC_ID_Z1 0xAA // CCA BUS source ID
    #define IOEEHCI_REDUN_REG2 IOEEHCI_CCA_BUS_SRC_ID_Z1 // 0/x/x/x Redundant Registers 2
#define IOEEHCI_DID_OPTIONAL 0xAC // Device ID OPTIONAL
    #define IOEEHCI_DID_OPTIONAL_Z1 IOEEHCI_DID_OPTIONAL // 3104h/x/x/x Device ID OPTIONAL
#define IOEEHCI_DID_OPTIONAL_Z2 0xAE // Device ID OPTIONAL
    #define IOEEHCI_VID_OPTIONAL_Z1 IOEEHCI_DID_OPTIONAL_Z2 // 1d17h/x/x/x Vendor ID OPTIONAL
#define IOEEHCI_REV_ID_OPTIONAL 0xF5 // Revision ID OPTIONAL
    #define IOEEHCI_REVID_BACK IOEEHCI_REV_ID_OPTIONAL // 00h/0h/x/x Revision ID OPTIONAL
#define IOEEHCI_INTERNAL_REV_ID 0xF6 // Internal Revision ID
    #define IOEEHCI_REVID IOEEHCI_INTERNAL_REV_ID // B0h/R/x/x Internal Revision ID
#define IOEEHCI_REV_ID_OPTIONAL_CTL 0xFC // Revision ID OPTIONAL Control
    #define IOEEHCI_CCA_REQ_GATE_EN   BIT1    // 0/0/x/x CCA requeset gating enable for debug mode
    #define IOEEHCI_BACK_EN           BIT0    // 0/0/x/x Revision ID OPTIONAL Reflection Enable
// USB 2.0-MMIO
#define USB20MMIO_CAP_REG_LEN 0x0 // Capability Register Length
    #define USB20MMIO_CAPLENGTH USB20MMIO_CAP_REG_LEN // 10h/x/x/x Capability Register Length
#define USB20MMIO_IF_VER_NUM 0x2 // Interface Version Number
    #define USB20MMIO_HCIVERSION USB20MMIO_IF_VER_NUM // 0100h/0100h/x/x Interface Version Number
#define USB20MMIO_STRUCTURE_PARAMS 0x4 // Structure Parameters
    #define USB20MMIO_HCSPARAMS USB20MMIO_STRUCTURE_PARAMS // 0010 3206h/00003206h/x/x Structure Parameters
#define USB20MMIO_CAP_PARAMS 0x8 // Capability Parameters
    #define USB20MMIO_HCCPARAMS USB20MMIO_CAP_PARAMS // 0000 6872h/00006872h/x/x Capability Parameters
#define USB20MMIO_USB_CMD 0x10 // USB Command
    #define USB20MMIO_INTTHRESHOLD  0xFF0000        // 08h/08h/x/x Interrupt Threshold Control
    #define USB20MMIO_LIGHTRST      BIT7            // 0/0/x/x Light Host Controller Reset
    #define USB20MMIO_INTDOORBELL   BIT6            // 0/x/x/x Interrupt on Async Advance Doorbell
    #define USB20MMIO_ASYNC_EN_TMP  BIT5            // 0/x/x/x Asynchronous Schedule Enable
    #define USB20MMIO_PERIOD_EN_TMP BIT4            // 0/x/x/x Periodic Schedule Enable
    #define USB20MMIO_FRLSTSIZE     (BIT2 + BIT3)   // 0/x/x/x Frame List Size
    #define USB20MMIO_HCRESET       BIT1            // 0/0/x/x Host Controller Reset
    #define USB20MMIO_RUN_SW        BIT0            // 0/x/x/x Run / Stop
#define USB20MMIO_DEBUG_PORT_CTL_STA 0xA0 // Debug Port Control / Status
    #define USB20MMIO_DBG_OWNER     BIT30                   // 0/0/x/x Force the Ownership of the Debug Port to the EHCI Controller (Owner)
    #define USB20MMIO_DBG_ENABLE    BIT28                   // 0/x/x/x Enable Debug Port (Enabled)
    #define USB20MMIO_DBG_DONE      BIT16                   // 0/x/x/x Transaction Request Complete (Done)
    #define USB20MMIO_DBG_INUSE     BIT10                   // 0/x/x/x Port In Use (In Use)
    #define USB20MMIO_DBG_EXCEPTION (BIT7 + BIT8 + BIT9)    // 000b/R/x/x Exception Error Type (Exception)
    #define USB20MMIO_DBG_ERRGD     BIT6                    // 0/R/x/x Error Status (Error / Good#)
    #define USB20MMIO_DBG_GO        BIT5                    // 0/x/x/x Start a Request (Go)
    #define USB20MMIO_DBG_WR        BIT4                    // 0/x/x/x Current Request Type (Write / Read#)
    #define USB20MMIO_DBG_LENGTH    0xF                     // 0/x/x/x Data Length
#define USB20MMIO_DEBUG_PORT_USB_PIDS_PACKET_IDENTIFIER 0xA4 // Debug Port USB PIDs (Packet Identifier)
    #define USB20MMIO_DBG_RCVPID    0xFF0000    // 0/R/x/x Received PID
    #define USB20MMIO_DBG_TXPID     0xFF00      // 0/x/x/x Send PID
    #define USB20MMIO_DBG_TOKEN     0xFF        // 0/x/x/x Token PID
#define USB20MMIO_DEBUG_PORT_DATA_BUFFER 0xA8 // Debug Port Data Buffer
    #define USB20MMIO_DBGPORT_BUF USB20MMIO_DEBUG_PORT_DATA_BUFFER // FFFF FFFF FFFF FFFFh/x/x/x Debug Port Data Buffer. 
#define USB20MMIO_DEBUG_PORT_DEV_ADR 0xB0 // Debug Port Device Address
    #define USB20MMIO_DBG_ADDR  0x7F00      // 7Fh/x/x/x USB Address
    #define USB20MMIO_DBG_ENDP  0xF         // 1h/x/x/x USB Endpoint

#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
