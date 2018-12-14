//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_BUSxp1D0F0_R100(A0).doc.
#ifndef _IRS_CND003_BUSXP1D0F0_R100_A0__H_
#define _IRS_CND003_BUSXP1D0F0_R100_A0__H_
// D0F0
#define CND003_MMIO_D0F0_VID 0x0 // Vendor ID
    #define CND003_MMIO_D0F0_VENID_15   BIT15   // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_14   BIT14   // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_13   BIT13   // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_12   BIT12   // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_11   BIT11   // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_10   BIT10   // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_9    BIT9    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_8    BIT8    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_7    BIT7    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_6    BIT6    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_5    BIT5    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_4    BIT4    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_3    BIT3    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_2    BIT2    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_1    BIT1    // HwInit/x/x/x Vendor ID
    #define CND003_MMIO_D0F0_VENID_0    BIT0    // HwInit/x/x/x Vendor ID
#define CND003_MMIO_D0F0_DID 0x2 // Device ID
    #define CND003_MMIO_D0F0_DEVID_15_0 D0F0_DID // 9100h/9100h/x/x Device ID
#define CND003_MMIO_D0F0_PCI_CMD 0x4 // PCI Command
    #define CND003_MMIO_D0F0_RX04_15_0  0xFC00  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RFBACK     BIT9    // 0/R/x/x Fast Back-to-back Cycle Enable
    #define CND003_MMIO_D0F0_RSERR      BIT8    // 0/0/x/x SERR# Enable
    #define CND003_MMIO_D0F0_RSETP      BIT7    // 0/R/x/x Address/Data Stepping
    #define CND003_MMIO_D0F0_RPTYERR    BIT6    // 0/0/x/x Parity Error Response
    #define CND003_MMIO_D0F0_RSV_3      BIT5    // 0/R/x/x VGA Palette Snooping
    #define CND003_MMIO_D0F0_RMWINV     BIT4    // 0/R/x/x Memory Write and Invalidate
    #define CND003_MMIO_D0F0_RSPCYC     BIT3    // 0/R/x/x Respond to Special Cycle
    #define CND003_MMIO_D0F0_RMSTR      BIT2    // 0b/R/x/x PCI Master Function
    #define CND003_MMIO_D0F0_RENMEM     BIT1    // 0b/R/x/x Memory Space Access
    #define CND003_MMIO_D0F0_RENIO      BIT0    // 0/R/x/x I/O Space Access
#define CND003_MMIO_D0F0_PCI_STA 0x6 // PCI Status
    #define CND003_MMIO_D0F0_SPERRS     BIT15           // 0/R/x/x Detected Parity Error
    #define CND003_MMIO_D0F0_SERRS      BIT14           // 0/R/x/x Signaled System Error (SERR# Asserted)
    #define CND003_MMIO_D0F0_SMABORT    BIT13           // 0/R/x/x Received Master-abort (Except Special Cycle)
    #define CND003_MMIO_D0F0_STABORTM   BIT12           // 0/R/x/x Received Target-abort
    #define CND003_MMIO_D0F0_STABORTS   BIT11           // 0/R/x/x Target-abort Assertion
    #define CND003_MMIO_D0F0_DEVS_1_0   (BIT9 + BIT10)  // 0/R/x/x DEVSEL# Timing
    #define CND003_MMIO_D0F0_SDPERRS    BIT8            // 0/R/x/x Master Data Parity Error
    #define CND003_MMIO_D0F0_RFBKS      BIT7            // 0/R/x/x Capable of Accepting Fast Back-to-back as a Target
    #define CND003_MMIO_D0F0_RUDF       BIT6            // 0/R/x/x User Definable Features
    #define CND003_MMIO_D0F0_R66M       BIT5            // 0/R/x/x 66MHz Capability
    #define CND003_MMIO_D0F0_RCAP       BIT4            // 1b/1b/x/x Support New Capability List
    #define CND003_MMIO_D0F0_RX04_19_16 0xF             // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_REV_ID 0x8 // Revision ID
    #define CND003_MMIO_D0F0_TBD_4 D0F0_REV_ID // 0/0/x/x Revision Code
#define CND003_MMIO_D0F0_CLASS_CODE 0x9 // Class Code
    #define CND003_MMIO_D0F0_RX08_31_8 D0F0_CLASS_CODE // 06 0400h/R/x/x Class Code
#define CND003_MMIO_D0F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_MMIO_D0F0_RX0C_7_0 D0F0_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define CND003_MMIO_D0F0_MASTER_LATENCY_TIMER 0xD // Master Latency Timer
    #define CND003_MMIO_D0F0_RX0D_7_0 D0F0_MASTER_LATENCY_TIMER // 0/R/x/x Master Latency Timer
#define CND003_MMIO_D0F0_HDR_TYPE 0xE // Header Type
    #define CND003_MMIO_D0F0_RSV_0E D0F0_HDR_TYPE // 01h/01h/x/x Header Type Code
#define CND003_MMIO_D0F0_BIST 0xF // Built In Self Test (BIST)
    #define CND003_MMIO_D0F0_RX0C_15_8 D0F0_BIST // 0/R/x/x BIST Support
#define CND003_MMIO_D0F0_BASE_ADR_REGS_0 0x10 // Base Address Registers 0
    #define CND003_MMIO_D0F0_RX10_31_0 D0F0_BASE_ADR_REGS_0 // 0/R/x/x Base Address 0
#define CND003_MMIO_D0F0_BASE_ADR_REGS_1 0x14 // Base Address Registers 1
    #define CND003_MMIO_D0F0_RX14_31_0 D0F0_BASE_ADR_REGS_1 // 0/R/x/x Base Address 1
#define CND003_MMIO_D0F0_PRIMARY_BUS_NUM 0x18 // Primary Bus Number
    #define CND003_MMIO_D0F0_PBN_XBAR D0F0_PRIMARY_BUS_NUM // 0/x/x/x Primary Bus Number
#define CND003_MMIO_D0F0_SECONDARY_BUS_NUM 0x19 // Secondary Bus Number
    #define CND003_MMIO_D0F0_SBN_XBAR D0F0_SECONDARY_BUS_NUM // 0/x/x/x Secondary Bus Number
#define CND003_MMIO_D0F0_SUBORDINATE_BUS_NUM 0x1A // Subordinate Bus Number
    #define CND003_MMIO_D0F0_SSBN_XBAR D0F0_SUBORDINATE_BUS_NUM // 0/x/x/x Subordinate Bus Number
#define CND003_MMIO_D0F0_SECONDARY_LATENCY_TIMER 0x1B // Secondary Latency Timer
    #define CND003_MMIO_D0F0_RX018_31_24 D0F0_SECONDARY_LATENCY_TIMER // 0/R/x/x Secondary Latency Timer
#define CND003_MMIO_D0F0_IO_BASE 0x1C // I/O Base
    #define CND003_MMIO_D0F0_RIOBS_XBAR_15_12   0xF0    // Fh/x/x/x I/O Base (AD[15:12] - Inclusive)
    #define CND003_MMIO_D0F0_TBD_10             0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_MMIO_D0F0_IO_LIMIT 0x1D // I/O Limit
    #define CND003_MMIO_D0F0_RIOLM_XBAR_15_12   0xF0    // 0/x/x/x I/O Limit (AD[15:12] - Inclusive)
    #define CND003_MMIO_D0F0_TBD_11             0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_MMIO_D0F0_SECONDARY_STA 0x1E // Secondary Status
    #define CND003_MMIO_D0F0_SSPERRS        BIT15           // 0/0/x/x Detected Parity Error
    #define CND003_MMIO_D0F0_SSERRS         BIT14           // 0/0/x/x Received System Error
    #define CND003_MMIO_D0F0_SSMABORT       BIT13           // 0/0/x/x Received Master Abort
    #define CND003_MMIO_D0F0_SSTABORTM      BIT12           // 0/0/x/x Received Target Abort
    #define CND003_MMIO_D0F0_RSV_1E_5       BIT11           // 0/x/x/x Signaled Target Abort
    #define CND003_MMIO_D0F0_RX01C_26_25    (BIT9 + BIT10)  // 0/x/x/x DEVSEL Timing
    #define CND003_MMIO_D0F0_SSDPERRS       BIT8            // 0/0/x/x Master Data Parity Error
    #define CND003_MMIO_D0F0_RX01C_23       BIT7            // 0/x/x/x Fast Back-to-Back Capable
    #define CND003_MMIO_D0F0_RX01C_22       BIT6            // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RX01C_21       BIT5            // 0/x/x/x 66MHz Capability
    #define CND003_MMIO_D0F0_RX01C_20_16    0x1F            // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_MEM_BASE 0x20 // Memory Base
    #define CND003_MMIO_D0F0_RM1BS_XBAR_31_20   0xFFF0  // FFFh/x/x/x Memory Base (AD[31:20] ? Inclusive)
    #define CND003_MMIO_D0F0_RSV_11             0xF     // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_MEM_LIMIT 0x22 // Memory Limit
    #define CND003_MMIO_D0F0_RM1LM_XBAR_31_20   0xFFF0  // 0/x/x/x Memory Limit (AD[31:20] ? Inclusive)
    #define CND003_MMIO_D0F0_RSV_12             0xF     // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_PREFETCHABLE_MEM_BASE 0x24 // Prefetchable Memory Base
    #define CND003_MMIO_D0F0_RM2BS_XBAR_31_20   0xFFF0                  // FFFh/x/x/x Prefetchable Memory Base AD[31:20]
    #define CND003_MMIO_D0F0_RSV_13             (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_TBD_12             BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory Base
#define CND003_MMIO_D0F0_PREFETCHABLE_MEM_LIMIT 0x26 // Prefetchable Memory Limit
    #define CND003_MMIO_D0F0_RM2LM_XBAR_31_20   0xFFF0                  // 0/x/x/x Prefetchable Memory Limit AD[31:20]
    #define CND003_MMIO_D0F0_RSV_14             (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_TBD_13             BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory  Limit
#define CND003_MMIO_D0F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS 0x28 // Prefetchable Memory Base Upper 32-bits
    #define CND003_MMIO_D0F0_RM3BS_XBAR_63_32 D0F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS // 0/x/x/x Prefetchable Memory Base Upper bit[63:32]
#define CND003_MMIO_D0F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS 0x2C // Prefetchable Memory Limit Upper 32-bits
    #define CND003_MMIO_D0F0_RM3LM_XBAR_63_32 D0F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS // 0/x/x/x Prefetchable Memory Limit Upper Bit[63:32]
#define CND003_MMIO_D0F0_IO_BASE_UPPER 0x30 // I/O Base Upper
    #define CND003_MMIO_D0F0_TBD_14 D0F0_IO_BASE_UPPER // 0/R/x/x I/O Base Upper 16 Bits Address
#define CND003_MMIO_D0F0_IO_BASE_LIMIT 0x32 // I/O Base Limit
    #define CND003_MMIO_D0F0_TBD_15 D0F0_IO_BASE_LIMIT // 0/R/x/x I/O Limit Upper 16 Bits Address
#define CND003_MMIO_D0F0_CAP_PTR 0x34 // Capability Pointer
    #define CND003_MMIO_D0F0_RX34_7_0 D0F0_CAP_PTR // 44h/44h/x/x Capability List Pointer
#define CND003_MMIO_D0F0_RESERVED 0x35 // Reserved
    #define CND003_MMIO_D0F0_RX35_7_0 D0F0_RESERVED // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_RESERVED_Z1 0x36 // Reserved
    #define CND003_MMIO_D0F0_RX36_7_0 D0F0_RESERVED_Z1 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_RESERVED_Z2 0x37 // Reserved
    #define CND003_MMIO_D0F0_RX37_7_0 D0F0_RESERVED_Z2 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_INTR_LINE_AND_INTR_PIN 0x3C // Interrupt Line and Interrupt Pin
    #define CND003_MMIO_D0F0_RX3C_15_8  0xFF00  // 0/R/x/x Interrupt Pin
    #define CND003_MMIO_D0F0_RX3C_7_0   0xFF    // 0/0/x/x Interrupt Line
#define CND003_MMIO_D0F0_BRIDGE_CTL 0x3E // Bridge Control
    #define CND003_MMIO_D0F0_RSV_17     0xF000  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RX03C_27   BIT11   // 0/x/x/x Discard Timer SERR# Enable
    #define CND003_MMIO_D0F0_RX03C_26   BIT10   // 0/x/x/x Discard Timer Status
    #define CND003_MMIO_D0F0_RX03C_25   BIT9    // 0/x/x/x Secondary Discard Timer
    #define CND003_MMIO_D0F0_RX03C_24   BIT8    // 0/x/x/x Primary Discard Timer
    #define CND003_MMIO_D0F0_RX03C_23   BIT7    // 0/x/x/x Fast Back-to-Back Enable
    #define CND003_MMIO_D0F0_RSRST      BIT6    // 0/x/x/x Secondary Bus Reset
    #define CND003_MMIO_D0F0_RSV_18     BIT5    // 0/R/x/x Master Abort Mode
    #define CND003_MMIO_D0F0_RVGA16     BIT4    // 0/x/x/x Base VGA 16 Bits Decode
    #define CND003_MMIO_D0F0_RVGA       BIT3    // 0/x/x/x VGA Compatible I/O and Memory Address Range
    #define CND003_MMIO_D0F0_RISA       BIT2    // 0/x/x/x Block/Forward ISA I/O Cycles
    #define CND003_MMIO_D0F0_RSERRFWD   BIT1    // 0/x/x/x SERR Enable
    #define CND003_MMIO_D0F0_RPTYERRTLP BIT0    // 0/x/x/x Parity Error Response Enable
#define CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0 0x40 // Backdoor Register Control 0
    #define CND003_MMIO_D0F0_RX40_7_5       (BIT5 + BIT6 + BIT7)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_DID_RID_LOCK   BIT4                    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_DBGMODE        BIT3                    // 0/0/x/x Enable internal Debug mode
    #define CND003_MMIO_D0F0_RDYNPM         BIT2                    // 0/0/x/x Dynamic Clock Stop Feature for the Clocks in NM Block
    #define CND003_MMIO_D0F0_VID_LOCK       BIT1                    // HwInit/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPEROWEN       BIT0                    // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_BACKDOOR_REG_CTL_1 0x41 // Backdoor Register Control 1
    #define CND003_MMIO_D0F0_RX41_7_2       0xF0    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RTXCDCDYNPM_EP BIT3    // 0/0/x/x TXCDC Upstream Port Dynamic Clock Control
    #define CND003_MMIO_D0F0_RTXCDCDYNPM_DN BIT2    // 0/0/x/x TXCDC Downstream Port Dynamic Clock Control
    #define CND003_MMIO_D0F0_RPEEPURDIS     BIT1    // 0/0/0/0 Unsupport Request returning Disable
    #define CND003_MMIO_D0F0_RPEEPCRSDIS    BIT0    // 0/0/0/0 CRS Returning Disable
#define CND003_MMIO_D0F0_BACKDOOR_REG_CTL_2 0x42 // Backdoor Register Control 2
    #define CND003_MMIO_D0F0_RX42 D0F0_BACKDOOR_REG_CTL_2 // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_TEST_MODE_REG 0x43 // Test Mode Register
    #define CND003_MMIO_D0F0_RPHYTSTS1G_1_0 (BIT6 + BIT7)   // 00b/00/00/00 Reserved
    #define CND003_MMIO_D0F0_RCNTPM         BIT5            // 0/0/x/x Dynamic Stop for Clocks for Internal Counters
    #define CND003_MMIO_D0F0_RSYNCPM        BIT4            // 0/0/x/x Dynamic Stop for Clocks for Configuration Registers Updates
    #define CND003_MMIO_D0F0_RFIXLPLT       BIT3            // 0/0/x/x Make Loop Back Latency Fixed 
    #define CND003_MMIO_D0F0_RLPLTCHK       BIT2            // 0/0/x/x Check Whether Multi-Lane Link Has Too Much Latency Skew
    #define CND003_MMIO_D0F0_RLKACTPM       BIT1            // 0/0/x/x Dynamic Stop for Clocks for Link Status Changes 
    #define CND003_MMIO_D0F0_REPHYRVSL_EP   BIT0            // 1b/1/x/x Revert Upstream Port EPHY Lane map
#define CND003_MMIO_D0F0_PM_CAPS 0x44 // Power Management Capabilities
    #define CND003_MMIO_D0F0_PMCPME     0xF8000000              // 11001b/19h/x/x PME Support
    #define CND003_MMIO_D0F0_PMCD2S     BIT26                   // 0/0/x/x D2 Support
    #define CND003_MMIO_D0F0_PMCD1S     BIT25                   // 0/0/x/x D1 Support
    #define CND003_MMIO_D0F0_PMCAUXC    (BIT22 + BIT23 + BIT24) // 0/0/x/x AUX Current
    #define CND003_MMIO_D0F0_PMCDSI     BIT21                   // 1b/1/x/x Device Specific Initialization
    #define CND003_MMIO_D0F0_RSV_53     (BIT19 + BIT20)         // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_TBD_34     (BIT16 + BIT17 + BIT18) // 011b/R/x/x Version
    #define CND003_MMIO_D0F0_TBD_35     0xFF00                  // 50h/R/x/x Next Capability Pointer
    #define CND003_MMIO_D0F0_TBD_36     0xFF                    // 01h/R/x/x Capability ID
#define CND003_MMIO_D0F0_PM_STA_CTL 0x48 // Power Management Status / Control
    #define CND003_MMIO_D0F0_TBD_37     0xFF000000      // 0/R/x/x Power Management Data
    #define CND003_MMIO_D0F0_TBD_38     BIT23           // 0/x/x/x Enable Bus Power / Clock Control
    #define CND003_MMIO_D0F0_TBD_39     BIT22           // 0/x/x/x B2 / B3 Support
    #define CND003_MMIO_D0F0_RSV_54     0x3F0000        // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_PMESD      BIT15           // 0/0/x/x PME Status
    #define CND003_MMIO_D0F0_TBD_40     (BIT13 + BIT14) // 0/R/x/x Data Scale
    #define CND003_MMIO_D0F0_TBD_41     0x1E00          // 0/R/x/x Data Select
    #define CND003_MMIO_D0F0_PMEEN      BIT8            // 0/0/x/x PME Enable
    #define CND003_MMIO_D0F0_RSV_55     0xF0            // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_NOSOFTRST  BIT3            // 1b/1b/x/x No_Soft_Reset
    #define CND003_MMIO_D0F0_RSV_55_2   BIT2            // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_PWSD       (BIT0 + BIT1)   // 00b/0/x/x Power State
#define CND003_MMIO_D0F0_PCI_EXPRESS_LIST 0x50 // PCI Express List
    #define CND003_MMIO_D0F0_TBD_51 0xFF00  // F8h/A0h/x/x Next Pointer
    #define CND003_MMIO_D0F0_TBD_50 0xFF    // 10h/10h/x/x Capability ID
#define CND003_MMIO_D0F0_PCI_EXPRESS_CAPS 0x52 // PCI Express Capabilities
    #define CND003_MMIO_D0F0_RSV_53_15  BIT15   // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RTCSEN     BIT14   // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_XINTMNO    0x3E00  // 0/0/x/x Interrupt Message Number
    #define CND003_MMIO_D0F0_XSLIMP     BIT8    // 0/0/x/x Slot Implemented
    #define CND003_MMIO_D0F0_XDPTYPE    0xF0    // 0110b/0110/x/x Device / Port Type
    #define CND003_MMIO_D0F0_PCIE_VER_3 BIT3    // 0/0/x/x Capability Version Bit 3
    #define CND003_MMIO_D0F0_PCIE_VER_2 BIT2    // 0/0/x/x Capability Version Bit 2
    #define CND003_MMIO_D0F0_PCIE_VER_1 BIT1    // 1b/1b/x/x Capability Version Bit 1
    #define CND003_MMIO_D0F0_PCIE_VER_0 BIT0    // 0/0/x/x Capability Version Bit 0
#define CND003_MMIO_D0F0_DEV_CAPS_1 0x54 // Device Capabilities 1
    #define CND003_MMIO_D0F0_TBD_57     (BIT29 + BIT30 + BIT31) // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_TBD_28     BIT28                   // 0/0/x/x Function Level Reset Capability
    #define CND003_MMIO_D0F0_RSV_20     (BIT26 + BIT27)         // 0/R/x/x Captured Slot Power Limit Scale
    #define CND003_MMIO_D0F0_RSV_21     0x3FC0000               // 0/R/x/x Captured Slot Power Limit Value
    #define CND003_MMIO_D0F0_RSV_22     (BIT16 + BIT17)         // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RRBERRP    BIT15                   // 0b/0/x/x Role-based Error Reporting
    #define CND003_MMIO_D0F0_RSV_23     BIT14                   // 0/R/x/x Power Indicator Present
    #define CND003_MMIO_D0F0_RSV_24     BIT13                   // 0/R/x/x Attention Indicator Present
    #define CND003_MMIO_D0F0_RSV_25     BIT12                   // 0/R/x/x Attention Button Present
    #define CND003_MMIO_D0F0_DAL1AL     (BIT9 + BIT10 + BIT11)  // 000b/0/x/x Endpoint L1 Acceptable Latency
    #define CND003_MMIO_D0F0_RSV_44     (BIT6 + BIT7 + BIT8)    // 0/R/x/x Endpoint L0s Acceptable Latency
    #define CND003_MMIO_D0F0_DAXTAGF    BIT5                    // 0/0/x/x Extended Tag Field Supported
    #define CND003_MMIO_D0F0_RSV_26     (BIT3 + BIT4)           // 0/R/x/x Phantom Functions Supported
    #define CND003_MMIO_D0F0_DAMPSS     (BIT0 + BIT1 + BIT2)    // 001b/001/x/x Max Payload Size Supported
#define CND003_MMIO_D0F0_DEV_CTL_1 0x58 // Device Control 1
    #define CND003_MMIO_D0F0_RSV_27     BIT15                   // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_DCMRRS     (BIT12 + BIT13 + BIT14) // 0/R/x/x Max Read Request Size
    #define CND003_MMIO_D0F0_DCENS      BIT11                   // 0/0/x/x Enable No Snoop
    #define CND003_MMIO_D0F0_DCAPPME    BIT10                   // 0/x/x/x Auxiliary Power PM Enable
    #define CND003_MMIO_D0F0_DCPFE      BIT9                    // 0/R/x/x Phantom Functions Enable
    #define CND003_MMIO_D0F0_DCETFE     BIT8                    // 0/0/x/x Extended Tag Field Enable
    #define CND003_MMIO_D0F0_DCMPS      (BIT5 + BIT6 + BIT7)    // 0/000*/001*/x Max Payload Size
    #define CND003_MMIO_D0F0_DCERO      BIT4                    // 1b/1/x/x Enable Relaxed Ordering
    #define CND003_MMIO_D0F0_DCURRE     BIT3                    // 0/0/x/x Unsupported Request Reporting Enable
    #define CND003_MMIO_D0F0_DCFERE     BIT2                    // 0/0/x/x Fatal Error Reporting Enable
    #define CND003_MMIO_D0F0_DCNFERE    BIT1                    // 0/0/x/x Non-Fatal Error Reporting Enable
    #define CND003_MMIO_D0F0_DCCERE     BIT0                    // 0/0/x/x Correctable Error Reporting Enable
#define CND003_MMIO_D0F0_DEV_STA_1 0x5A // Device Status 1
    #define CND003_MMIO_D0F0_RSV_4B 0xFFC0  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_DSTP   BIT5    // 0/0/x/x Transactions Pending
    #define CND003_MMIO_D0F0_DSAPD  BIT4    // 0/0/x/x AUX Power Detected
    #define CND003_MMIO_D0F0_DSURD  BIT3    // 0/0/x/x Unsupported Request Detected (TL)
    #define CND003_MMIO_D0F0_DSFED  BIT2    // 0/0/x/x Fatal Error Detected (TL)
    #define CND003_MMIO_D0F0_DSNFED BIT1    // 0/0/x/x Non-Fatal Error Detected (TL)
    #define CND003_MMIO_D0F0_DSCED  BIT0    // 0/0/x/x Correctable Error Detected (TL)
#define CND003_MMIO_D0F0_LINK_CAPS_1 0x5C // Link Capabilities 1
    #define CND003_MMIO_D0F0_LKPN           0xFF000000              // 01h/09h/x/x Port Number
    #define CND003_MMIO_D0F0_RSV_28G        BIT23                   // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_ASPMOPTCOMP    BIT22                   // 1b/1/x/x ASPM Optionality Compliance 
    #define CND003_MMIO_D0F0_RLBWNTFC       BIT21                   // 0b/0/x/x Link Bandwidth Notification Capability
    #define CND003_MMIO_D0F0_RDL_AR_CAP     BIT20                   // 0b/0/x/x Data Link Layer Link Active Reporting Capable
    #define CND003_MMIO_D0F0_RLCASDERC      BIT19                   // 0b/0/x/x Surprise Down Error Reporting Capable
    #define CND003_MMIO_D0F0_RLCACPM        BIT18                   // 0/0/x/x Clock Power Management
    #define CND003_MMIO_D0F0_LKL1EL         (BIT15 + BIT16 + BIT17) // 000b/0/x/x L1 Exit Latency
    #define CND003_MMIO_D0F0_LKL0SE         (BIT12 + BIT13 + BIT14) // 000b/0/x/x L0s Exit Latency
    #define CND003_MMIO_D0F0_LKAPMS         (BIT10 + BIT11)         // 00b/0/x/x Active State Link PM (ASPM) Support
    #define CND003_MMIO_D0F0_LKMLW_5        BIT9                    // 0/0/x/x Maximum Link Width Bit 5
    #define CND003_MMIO_D0F0_LKMLW_4        BIT8                    // 0/0/x/x Maximum Link Width Bit 4
    #define CND003_MMIO_D0F0_LKMLW_3        BIT7                    // 0/0/x/x Maximum Link Width Bit 3
    #define CND003_MMIO_D0F0_LKMLW_2        BIT6                    // 1b/1b/x/x Maximum Link Width Bit 2
    #define CND003_MMIO_D0F0_LKMLW_1        BIT5                    // 0/0/x/x Maximum Link Width Bit 1
    #define CND003_MMIO_D0F0_LKMLW_0        BIT4                    // 0/0/x/x Maximum Link Width Bit 0
    #define CND003_MMIO_D0F0_LKMAXLS_3      BIT3                    // 0/0/x/x Max Link Speed Bit 3 
    #define CND003_MMIO_D0F0_LKMAXLS_2      BIT2                    // 0/0/x/x Max Link Speed Bit 2 
    #define CND003_MMIO_D0F0_LKMAXLS_1      BIT1                    // 0/0/x/x Max Link Speed Bit 1
    #define CND003_MMIO_D0F0_LKMAXLS_0      BIT0                    // 1b/1b/x/x Max Link Speed Bit 0
#define CND003_MMIO_D0F0_LINK_CTL_1 0x60 // Link Control 1
    #define CND003_MMIO_D0F0_RSV_32     0xF000          // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RLABITEN   BIT11           // 0/0/x/x Enable Link Autonom ous Bandwidth Interrupt
    #define CND003_MMIO_D0F0_RLBMITEN   BIT10           // 0/0/x/x Enable Link Bandwidth Management Interrupt
    #define CND003_MMIO_D0F0_RHATNMWD   BIT9            // 0/0/x/0 Hardware Autonomous Width Control
    #define CND003_MMIO_D0F0_RLCOCPMEN  BIT8            // 0/R/x/x Enable Clock Power Management
    #define CND003_MMIO_D0F0_LCES       BIT7            // 0/0/0/x Extended Synch
    #define CND003_MMIO_D0F0_LCCCC      BIT6            // 0/0/x/x Common Clock Configuration
    #define CND003_MMIO_D0F0_LCRL       BIT5            // 0/0/x/x Retrain Link
    #define CND003_MMIO_D0F0_LCLD       BIT4            // 0/0/x/x Link Disable
    #define CND003_MMIO_D0F0_LCRCB      BIT3            // 0/0/x/x Read Completion Boundary
    #define CND003_MMIO_D0F0_RSV_33     BIT2            // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_LCAPMS     (BIT0 + BIT1)   // 00b/00*/00*/11* Link Active State PM (ASPM) Control
#define CND003_MMIO_D0F0_LINK_STA_1 0x62 // Link Status 1
    #define CND003_MMIO_D0F0_RLATNMBW   BIT15   // 0/0/x/x Link Autonomous Bandwidth Status
    #define CND003_MMIO_D0F0_RLBWMNGT   BIT14   // 0/0/x/x Link Bandwidth Management Status
    #define CND003_MMIO_D0F0_DL_ACTIVE  BIT13   // 0/0/x/x Data Link Layer Link Active
    #define CND003_MMIO_D0F0_LSSCC      BIT12   // 0/0/x/x Slot Clock Configuration
    #define CND003_MMIO_D0F0_LSLT       BIT11   // 0/x/x/x Link Training
    #define CND003_MMIO_D0F0_LSTE       BIT10   // 0/x/x/x Training Error
    #define CND003_MMIO_D0F0_TBD_63     BIT9    // 0/R/x/x Negotiated Link Width Bit 5
    #define CND003_MMIO_D0F0_LSNLW      0x1F0   // 0/x/x/x Negotiated Link Width Bits[4:0]
    #define CND003_MMIO_D0F0_LSLS       0xF     // 0000b/0000b/x/x Current Link Speed
#define CND003_MMIO_D0F0_SLOT_CAPS_1 0x64 // Slot Capabilities 1
    #define CND003_MMIO_D0F0_SLPSN      0xFFF80000      // 0/0/x/x Physical Slot Number; Reserved
    #define CND003_MMIO_D0F0_RSCANCCS   BIT18           // 0/0/x/x No Command Completed Support
    #define CND003_MMIO_D0F0_RSCAEMIP   BIT17           // 0/0/x/x Electromechanical Interlock Present
    #define CND003_MMIO_D0F0_RSPLS      (BIT15 + BIT16) // 0/0/x/x Slot Power Limit Scale
    #define CND003_MMIO_D0F0_RSPLV      0x7F80          // 0/0/x/x Slot Power Limit Value
    #define CND003_MMIO_D0F0_SCHP_CAP   BIT6            // 0/0/x/x Hot-Plug Capable
    #define CND003_MMIO_D0F0_SCHPS      BIT5            // 0b/0/x/x Hot-Plug Surprise
    #define CND003_MMIO_D0F0_SCPIP      BIT4            // 0/0/x/x Power Indicator Present
    #define CND003_MMIO_D0F0_SCAIP      BIT3            // 0/0/x/x Attention Indicator Present
    #define CND003_MMIO_D0F0_RSV_36     BIT2            // 0/R/x/x MRL Sensor Present
    #define CND003_MMIO_D0F0_RSV_37     BIT1            // 0/R/x/x Power Controller Present
    #define CND003_MMIO_D0F0_SCABP      BIT0            // 0/0/x/x Attention Button Present
#define CND003_MMIO_D0F0_SLOT_CTL_1 0x68 // Slot Control 1
    #define CND003_MMIO_D0F0_RSV_39     (BIT13 + BIT14 + BIT15) // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RDLSCHGEN  BIT12                   // 0/0/x/x Enable Data Link Layer State Change
    #define CND003_MMIO_D0F0_RSCOEMIC   BIT11                   // 0/R/x/x Electromechanical Interlock Control
    #define CND003_MMIO_D0F0_SCPCC      BIT10                   // 0/0/x/x Power Controller Control
    #define CND003_MMIO_D0F0_SCPIC      (BIT8 + BIT9)           // 00b/0/x/x Power Indicator Control
    #define CND003_MMIO_D0F0_SCAIC      (BIT6 + BIT7)           // 00b/0/x/x Attention Indicator Control
    #define CND003_MMIO_D0F0_SCHPIE     BIT5                    // 0/0/x/x Enable Hot-Plug Interrupt
    #define CND003_MMIO_D0F0_SCCCIE     BIT4                    // 0/0/x/x Enable Command Completed Interrupt 
    #define CND003_MMIO_D0F0_SCPDCE     BIT3                    // 0/0/x/x Enable Presence Detect Change
    #define CND003_MMIO_D0F0_RSV_40     BIT2                    // 0/R/x/x Enable MRL Sensor Change
    #define CND003_MMIO_D0F0_RSV_41     BIT1                    // 0/R/x/x Enable Power Fault Detected
    #define CND003_MMIO_D0F0_SCABPE     BIT0                    // 0/0/x/x Enable Attention Button Pressed
#define CND003_MMIO_D0F0_SLOT_STA_1 0x6A // Slot Status 1
    #define CND003_MMIO_D0F0_RSV_42     0xFE00  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RDLSCHG    BIT8    // 0/0/x/x Data Link Layer State Changed
    #define CND003_MMIO_D0F0_RSSEMIS    BIT7    // 0/R/x/x Electromechanical Interlock Status
    #define CND003_MMIO_D0F0_SPDCST     BIT6    // 0/0/x/x Presence Detect State
    #define CND003_MMIO_D0F0_RSV_43     BIT5    // 0/R/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define CND003_MMIO_D0F0_SSCC       BIT4    // 0/0/x/x Command Completed
    #define CND003_MMIO_D0F0_SPDC       BIT3    // 0/0/x/x Presence Detect Change
    #define CND003_MMIO_D0F0_TBD_29     BIT2    // 0/R/x/x MRL Sensor Change
    #define CND003_MMIO_D0F0_TBD_30     BIT1    // 0/R/x/x Power Fault Detected
    #define CND003_MMIO_D0F0_SSABP      BIT0    // 0/0/x/x Attention Button Pressed
#define CND003_MMIO_D0F0_ROOT_CTL 0x6C // Root Control
    #define CND003_MMIO_D0F0_RSV_5C_5   0xFFE0  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RCCRSSVE   BIT4    // 0/0/x/x Enable CRS Software Visibility 
    #define CND003_MMIO_D0F0_RCPMEIE    BIT3    // 0/0/x/x Enable PME Interrupt
    #define CND003_MMIO_D0F0_RCSEFEE    BIT2    // 0/0/x/x Enable System Error on Fatal Error
    #define CND003_MMIO_D0F0_RCSENFEE   BIT1    // 0/0/x/x Enable System Error on Non-Fatal Error
    #define CND003_MMIO_D0F0_RCSECEE    BIT0    // 0/0/x/x Enable System Error on Correctable Error
#define CND003_MMIO_D0F0_ROOT_CAPS 0x6E // Root Capabilities
    #define CND003_MMIO_D0F0_RSV_44_5E  0xFFFE  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RSCRSSFV   BIT0    // 0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define CND003_MMIO_D0F0_ROOT_STA 0x70 // Root Status
    #define CND003_MMIO_D0F0_RSV_45 0xFFFC0000  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RSPP   BIT17       // 0/x/x/x PME Pending
    #define CND003_MMIO_D0F0_RSPS   BIT16       // 0/0/x/x PME Status
    #define CND003_MMIO_D0F0_RSPRID 0xFFFF      // 0/x/x/x PME Requester ID
#define CND003_MMIO_D0F0_DEV_CAPS_2 0x74 // Device Capabilities 2
    #define CND003_MMIO_D0F0_RSV_64_6   0xFFF00000      // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_ROBFFSP    (BIT18 + BIT19) // 0/0/x/x OBFF Supported
    #define CND003_MMIO_D0F0_RSV_64_12  0x3F000         // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RLTRSP     BIT11           // 0/0/x/x LTR Mechanism Supported
    #define CND003_MMIO_D0F0_RSV_64_10  0x7C0           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RARISP     BIT5            // 0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define CND003_MMIO_D0F0_TBD_31     BIT4            // 0/0/x/x Completion Timeout Disable Supported
    #define CND003_MMIO_D0F0_TBD_32     0xF             // 0/R/x/x Completion Timeout Ranges Supported
#define CND003_MMIO_D0F0_DEV_CTL_2 0x78 // Device Control 2
    #define CND003_MMIO_D0F0_RSV_46     BIT15           // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_ROBFFEN    (BIT13 + BIT14) // 0/0/x/x OBFF Enable
    #define CND003_MMIO_D0F0_RSV_68_11  (BIT11 + BIT12) // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RLTREN     BIT10           // 0/0/x/x LTR Mechanism Enable
    #define CND003_MMIO_D0F0_RSV_68_6   0x3C0           // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RARIEN     BIT5            // 0/0/x/x Enable ARI Forwarding
    #define CND003_MMIO_D0F0_RDISCPLTM  BIT4            // 0/0/0/x Completion Timeout Disable Control
    #define CND003_MMIO_D0F0_TBD_33     0xF             // 0/0/x/x Completion Timeout Value
#define CND003_MMIO_D0F0_DEV_STA_2 0x7A // Device Status 2
    #define CND003_MMIO_D0F0_RSV_47 D0F0_DEV_STA_2 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_LINK_CAPS_2 0x7C // Link Capabilities 2
    #define CND003_MMIO_D0F0_RSV_6C_31              0xFFF80000  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RLOW_SKP_REC_SUPPORT_2 BIT18       // 0/x/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_MMIO_D0F0_RLOW_SKP_REC_SUPPORT_1 BIT17       // 0/x/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_MMIO_D0F0_RLOW_SKP_REC_SUPPORT_0 BIT16       // 1b/1b/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_MMIO_D0F0_RSV_6C_15              0xF000      // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_RLOW_SKP_GEN_SUPPORT_2 BIT11       // 0/0/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_MMIO_D0F0_RLOW_SKP_GEN_SUPPORT_1 BIT10       // 0/0/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_MMIO_D0F0_RLOW_SKP_GEN_SUPPORT_0 BIT9        // 1b/1b/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_MMIO_D0F0_RSV_6C_8               BIT8        // 0/R/x/x CrossLink Supported
    #define CND003_MMIO_D0F0_LKMLS_6                BIT7        // 0b/R/x/x Supported Link Speed Vector Bit 6
    #define CND003_MMIO_D0F0_LKMLS_5                BIT6        // 0b/R/x/x Supported Link Speed Vector Bit 5
    #define CND003_MMIO_D0F0_LKMLS_4                BIT5        // 0b/R/x/x Supported Link Speed Vector Bit 4
    #define CND003_MMIO_D0F0_LKMLS_3                BIT4        // 0b/R/x/x Supported Link Speed Vector Bit 3
    #define CND003_MMIO_D0F0_LKMLS_2                BIT3        // 0/0/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define CND003_MMIO_D0F0_LKMLS_1                BIT2        // 0/0/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define CND003_MMIO_D0F0_LKMLS_0                BIT1        // 1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define CND003_MMIO_D0F0_RSV_6C_0               BIT0        // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_LINK_CTL_2 0x80 // Link Control 2
    #define CND003_MMIO_D0F0_CMPPSDEEMPHS   0xF000  // 0/0/x/x Compliance Preset / De-emphasis
    #define CND003_MMIO_D0F0_RCMPSOS        BIT11   // 0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define CND003_MMIO_D0F0_PMDCMPSET      BIT10   // 0/0/x/x Modified Compliance Pattern Set Bit
    #define CND003_MMIO_D0F0_TXMGN_2        BIT9    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_MMIO_D0F0_TXMGN_1        BIT8    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_MMIO_D0F0_TXMGN_0        BIT7    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_MMIO_D0F0_SELDEEMPHS     BIT6    // 0/*0/x/x Selectable De-emphasis
    #define CND003_MMIO_D0F0_RHATNMSD       BIT5    // 0/1/x/0 Disable Hardware Autonomous Speed
    #define CND003_MMIO_D0F0_PCMPSET        BIT4    // 0/0/x/x Enter Compliance
    #define CND003_MMIO_D0F0_LKTGLS_3       BIT3    // 0/0/0/0 Target Link Speed Bit 3
    #define CND003_MMIO_D0F0_LKTGLS_2       BIT2    // 0/0/0/0 Target Link Speed Bit 2
    #define CND003_MMIO_D0F0_LKTGLS_1       BIT1    // 0/x/0/0 Target Link Speed Bit 1
    #define CND003_MMIO_D0F0_LKTGLS_0       BIT0    // 1b/1b/0/0 Target Link Speed Bit 0
#define CND003_MMIO_D0F0_LINK_STA_2 0x82 // Link Status 2
    #define CND003_MMIO_D0F0_RSV_49     0xFFC0  // 0/R/x/x Reserved
    #define CND003_MMIO_D0F0_EQREQ      BIT5    // 0/0/x/x Request the Link Equalization Process
    #define CND003_MMIO_D0F0_EQCOMPLE3  BIT4    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define CND003_MMIO_D0F0_EQCOMPLE2  BIT3    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define CND003_MMIO_D0F0_EQCOMPLE1  BIT2    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define CND003_MMIO_D0F0_EQCOMPLE   BIT1    // 0/0/x/x Transmitter Equalization Procedure Completed
    #define CND003_MMIO_D0F0_CURDEEMPHS BIT0    // 0/0/x/x Current Link De-emphasis Level
#define CND003_MMIO_D0F0_SLOT_CAPS_2 0x84 // Slot Capabilities 2
    #define CND003_MMIO_D0F0_RSV_50 D0F0_SLOT_CAPS_2 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_SLOT_CTL_2 0x88 // Slot Control 2
    #define CND003_MMIO_D0F0_RSV_51 D0F0_SLOT_CTL_2 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_SLOT_STA_2 0x8A // Slot Status 2
    #define CND003_MMIO_D0F0_RSV_52 D0F0_SLOT_STA_2 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_XBCTL_CTL_0 0x8C // XBCTL Control 0
    #define CND003_MMIO_D0F0_RENDYNCLK_XBCTL    BIT31   // 0/0/0/0 Dynamic Clock Gating Enable for XBCTL
    #define CND003_MMIO_D0F0_RENLOCK            BIT30   // 1b/1/0/0 Enable Lock Support
    #define CND003_MMIO_D0F0_RENUPMSTINLOCK     BIT29   // 0/0/0/0 Option for Upstream Port Blocking TLP While Locked
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PESB BIT28   // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEB1 BIT27   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEB1 Port
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEB0 BIT26   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEB0 Port
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEA4 BIT25   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEA4 Port
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEA3 BIT24   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEA3 Port
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEA2 BIT23   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEA2 Port
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEA1 BIT22   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEA1 Port
    #define CND003_MMIO_D0F0_RRSTOUTSTDCNT_PEA0 BIT21   // 0/0/0/0 Reset Read Data Outstanding Counter to 0 for PEA0 Port
    #define CND003_MMIO_D0F0_RENRDSPACING_PED1  BIT20   // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RENRDSPACING_PED0  BIT19   // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RENRDSPACING_PESB  BIT18   // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RENRDSPACING_PEB1  BIT17   // 0/0/0/0 Read Spacing Enable for PEB1 Port
    #define CND003_MMIO_D0F0_RENRDSPACING_PEB0  BIT16   // 0/0/0/0 Read Spacing Enable for PEB0 Port 
    #define CND003_MMIO_D0F0_RENRDSPACING_PEA4  BIT15   // 0/0/0/0 Read Spacing Enable for PEA4 Port
    #define CND003_MMIO_D0F0_RENRDSPACING_PEA3  BIT14   // 0/0/0/0 Read Spacing Enable for PEA3 Port
    #define CND003_MMIO_D0F0_RENRDSPACING_PEA2  BIT13   // 0/0/0/0 Read Spacing Enable for PEA2 Port
    #define CND003_MMIO_D0F0_RENRDSPACING_PEA1  BIT12   // 0/0/0/0 Read Spacing Enable for PEA1 Port
    #define CND003_MMIO_D0F0_RENRDSPACING_PEA0  BIT11   // 0/0/0/0 Read Spacing Enable for PEA0 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PED1  BIT10   // 1b/1b/1b/1b Reserved
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PED0  BIT9    // 1b/1b/1b/1b Reserved
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PESB  BIT8    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEB1  BIT7    // 1b/1b/1b/1b Read Threshold Control Enable for PEB1 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEB0  BIT6    // 1b/1b/1b/1b Read Threshold Control Enable for PEB0 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEA4  BIT5    // 1b/1b/1b/1b Read Threshold Control Enable for PEA4 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEA3  BIT4    // 1b/1b/1b/1b Read Threshold Control Enable for PEA3 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEA2  BIT3    // 1b/1b/1b/1b Read Threshold Control Enable for PEA2 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEA1  BIT2    // 1b/1b/1b/1b Read Threshold Control Enable for PEA1 Port
    #define CND003_MMIO_D0F0_RENRDTHRSHLD_PEA0  BIT1    // 1b/1b/1b/1b Read Threshold Control Enable for PEA0 Port
    #define CND003_MMIO_D0F0_RENBDWCTL          BIT0    // 0/0/0/0 Enable Bandwidth Control
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_0 0x90 // XBCTL BW Control 0
    #define CND003_MMIO_D0F0_RP1TOP0_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P1 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP2TOP0_BDW_NP 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P2 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP3TOP0_BDW_NP 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P3 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP4TOP0_BDW_NP 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P4 to P0 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_1 0x94 // XBCTL BW Control 1
    #define CND003_MMIO_D0F0_RP5TOP0_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P5 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP6TOP0_BDW_NP 0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP7TOP0_BDW_NP 0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP8TOP0_BDW_NP 0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_2 0x98 // XBCTL BW Control 2
    #define CND003_MMIO_D0F0_RP9TOP0_BDW_NP     0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P9 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP10TOP0_BDW_NP    0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P10 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP11TOP0_BDW_NP    0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P11 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP11TOP0_BDW_NP_HI 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P11 to P0 Non-posted Cycle When P11 ...
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_3 0x9C // XBCTL BW Control 3
    #define CND003_MMIO_D0F0_RP1TOP0_BDW_PW 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P1 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP2TOP0_BDW_PW 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P2 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP3TOP0_BDW_PW 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P3 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP4TOP0_BDW_PW 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P4 to P0 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_4 0xA0 // XBCTL BW Control 4
    #define CND003_MMIO_D0F0_RP5TOP0_BDW_PW 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P5 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP6TOP0_BDW_PW 0xFF0000    // 0h/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP7TOP0_BDW_PW 0xFF00      // 0h/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP8TOP0_BDW_PW 0xFF        // 0h/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_5 0xA4 // XBCTL BW Control 5
    #define CND003_MMIO_D0F0_RP9TOP0_BDW_PW     0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P9 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP10TOP0_BDW_PW    0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P10 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP11TOP0_BDW_PW    0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P11 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_RP11TOP0_BDW_PW_HI 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P11 to P0 Posted Cycle When P11 Asse...
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_6 0xA8 // XBCTL BW Control 6
    #define CND003_MMIO_D0F0_RP0TOP1_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P0 to P1 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP1_BDW_NP 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P9 to P1 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP1_BDW_PW 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P0 to P1 Posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP1_BDW_PW 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P9 to P1 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_7 0xAC // XBCTL BW Control 7
    #define CND003_MMIO_D0F0_RP0TOP2_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P0 to P2 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP2_BDW_NP 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P1 to P2 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP2_BDW_NP 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P9 to P2 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP2_BDW_PW 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P0 to P2 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_8 0xB0 // XBCTL BW Control 8
    #define CND003_MMIO_D0F0_RP1TOP2_BDW_PW 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P1 to P2 Posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP2_BDW_PW 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P9 to P2 Posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP3_BDW_NP 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P0 to P3 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP3_BDW_NP 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P1 to P3 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_9 0xB4 // XBCTL BW Control 9
    #define CND003_MMIO_D0F0_RP9TOP3_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P9 to P3 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP3_BDW_PW 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P0 to P3 Posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP3_BDW_PW 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P1 to P3 Posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP3_BDW_PW 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P9 to P3 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_10 0xB8 // XBCTL BW Control 10
    #define CND003_MMIO_D0F0_RP0TOP4_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P0 to P4 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP4_BDW_NP 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P1 to P4 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP4_BDW_NP 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P9 to P4 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP4_BDW_PW 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P0 to P4 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_11 0xBC // XBCTL BW Control 11
    #define CND003_MMIO_D0F0_RP1TOP4_BDW_PW 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P1 to P4 Posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP4_BDW_PW 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P9 to P4 Posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP5_BDW_NP 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P0 to P5 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP5_BDW_NP 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P1 to P5 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_12 0xC0 // XBCTL BW Control 12
    #define CND003_MMIO_D0F0_RP9TOP5_BDW_NP 0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P9 to P5 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP5_BDW_PW 0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P0 to P5 Posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP5_BDW_PW 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P1 to P5 Posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP5_BDW_PW 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P9 to P5 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_13 0xC4 // XBCTL BW Control 13
    #define CND003_MMIO_D0F0_RP0TOP6_BDW_NP 0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP1TOP6_BDW_NP 0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP9TOP6_BDW_NP 0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP0TOP6_BDW_PW 0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_14 0xC8 // XBCTL BW Control 14
    #define CND003_MMIO_D0F0_RP1TOP6_BDW_PW 0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP9TOP6_BDW_PW 0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP0TOP7_BDW_NP 0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP1TOP7_BDW_NP 0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_15 0xCC // XBCTL BW Control 15
    #define CND003_MMIO_D0F0_RP9TOP7_BDW_NP 0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP0TOP7_BDW_PW 0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP1TOP7_BDW_PW 0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP9TOP7_BDW_PW 0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_16 0xD0 // XBCTL BW Control 16
    #define CND003_MMIO_D0F0_RP0TOP8_BDW_NP 0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP1TOP8_BDW_NP 0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP9TOP8_BDW_NP 0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP0TOP8_BDW_PW 0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_17 0xD4 // XBCTL BW Control 17
    #define CND003_MMIO_D0F0_RP1TOP8_BDW_PW 0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP9TOP8_BDW_PW 0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RP0TOP9_BDW_NP 0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P0 to P9 Non-Posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP9_BDW_NP 0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P1 to P9 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_18 0xD8 // XBCTL BW Control 18
    #define CND003_MMIO_D0F0_RP0TOP9_BDW_PW     0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P0 to P9 Posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP9_BDW_PW     0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P1 to P9 Posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP10_BDW_NP    0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P0 to P10 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP10_BDW_NP    0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P1 to P10 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_19 0xDC // XBCTL BW Control 19
    #define CND003_MMIO_D0F0_RP9TOP10_BDW_NP    0xFF000000  // 64h/64h/64h/64h Bandwidth Limitation for P9 to P10 Non-posted Cycle
    #define CND003_MMIO_D0F0_RP0TOP10_BDW_PW    0xFF0000    // 64h/64h/64h/64h Bandwidth Limitation for P0 to P10 Posted Cycle
    #define CND003_MMIO_D0F0_RP1TOP10_BDW_PW    0xFF00      // 64h/64h/64h/64h Bandwidth Limitation for P1 to P10 Posted Cycle
    #define CND003_MMIO_D0F0_RP9TOP10_BDW_PW    0xFF        // 64h/64h/64h/64h Bandwidth Limitation for P9 to P10 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_20 0xE0 // XBCTL BW Control 20
    #define CND003_MMIO_D0F0_RRDSPC_GEN2_X4 0xFF000000  // 0h/0h/0h/0h Read spacing threshold in the unit of DW for X4 port in Gen2, the...
    #define CND003_MMIO_D0F0_RRDSPC_GEN2_X2 0xFF0000    // 0h/0h/0h/0h Read spacing threshold in the unit of DW for X2 port in Gen2 or X...
    #define CND003_MMIO_D0F0_RRDSPC_GEN2_X1 0xFF00      // 0h/0h/0h/0h Read spacing threshold in the unit of DW for X1 port in Gen2 or X...
    #define CND003_MMIO_D0F0_RRDSPC_GEN1_X1 0xFF        // 0h/0h/0h/0h Read spacing threshold in the unit of DW for X1 port in Gen1, the...
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_21 0xE4 // XBCTL BW Control 21
    #define CND003_MMIO_D0F0_RSV_A4_31_20       0xFF000000      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RUPNPARBCNT        (BIT22 + BIT23) // 00b/00b/00b/00b Upstream NP Arbitration Counter
    #define CND003_MMIO_D0F0_RUPPWARBCNT        (BIT20 + BIT21) // 00b/00b/00b/00b Upstream PW Arbitration Counter
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEA0  (BIT18 + BIT19) // 00b/00b/00b/00b Adjust Read Spacing Timer for Port PEA0
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEA1  (BIT16 + BIT17) // 00b/00b/00b/00b Adjust Read Spacing Timer for Port PEA1
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEA2  (BIT14 + BIT15) // 00b/00b/00b/00b Adjust Read Spacing Timer for Port PEA2
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEA3  (BIT12 + BIT13) // 00b/00b/00b/00b Adjust Read Spacing Timer for Port PEA3
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEA4  (BIT10 + BIT11) // 00b/00b/00b/00b Adjust Read Spacing Timer for Port PEA4
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEB0  (BIT8 + BIT9)   // 00b/00b/00b/00b Adjust Read Spacing Timer for Port PEB0
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PEB1  (BIT6 + BIT7)   // 00b/00b/00b/00b Adjust Read Spacing Timer for Port B1
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PESB  (BIT4 + BIT5)   // 00b/00b/00b/00b Reserved
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PED0  (BIT2 + BIT3)   // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RRDSPC_ADJTM_PED1  (BIT0 + BIT1)   // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_22 0xE8 // XBCTL BW Control 22
    #define CND003_MMIO_D0F0_RSV_A8_31_29   (BIT29 + BIT30 + BIT31) // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RRDTHR_GEN2_X1 0x1FFF0000              // 0200h/0200h/0200h/0200h Read Threshold in the Unit of DW for X1 Port in Gen2 ...
    #define CND003_MMIO_D0F0_RSV_A8_15_13   (BIT13 + BIT14 + BIT15) // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RRDTHR_GEN1_X1 0x1FFF                  // 0100h/0100h/0100h/0100h Read Threshold in the Unit of DW for X1 Port in Gen1
#define CND003_MMIO_D0F0_XBCTL_BW_CTL_23 0xEC // XBCTL BW Control 23
    #define CND003_MMIO_D0F0_RSV_AC_31_29   (BIT29 + BIT30 + BIT31) // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RRDTHR_GEN2_X4 0x1FFF0000              // 0400h/0400h/0400h/0400h Read Threshold in the Unit of DW for X4 Port in Gen2
    #define CND003_MMIO_D0F0_RSV_AC_15_13   (BIT13 + BIT14 + BIT15) // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_RRDTHR_GEN2_X2 0x1FFF                  // 0300h/0300h/0300h/0300h Read Threshold in the Unit of DW for X2 Port in Gen2 ...
#define CND003_MMIO_D0F0_XBCTL_BW_STA_0 0xF0 // XBCTL BW Status 0
    #define CND003_MMIO_D0F0_CUR_P1TOP0_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P1 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P2TOP0_BDW_NP  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P2 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P3TOP0_BDW_NP  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P3 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P4TOP0_BDW_NP  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P4 to P0 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_1 0xF4 // XBCTL BW Status 1
    #define CND003_MMIO_D0F0_CUR_P5TOP0_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P5 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P6TOP0_BDW_NP  0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P7TOP0_BDW_NP  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P8TOP0_BDW_NP  0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_NEXT_PTR 0xF8 // Next Pointer
    #define CND003_MMIO_D0F0_TBD_F9 0xFF00  // 0/R/x/x Next Pointer
    #define CND003_MMIO_D0F0_TBD_F8 0xFF    // 0Dh/R/x/x Capability ID
#define CND003_MMIO_D0F0_RESERVED_Z3 0xFA // Reserved
    #define CND003_MMIO_D0F0_TBD_FA D0F0_RESERVED_Z3 // 0/R/x/x Reserved
#define CND003_MMIO_D0F0_SVID_CTL 0xFC // Subsystem Vendor ID Control
    #define CND003_MMIO_D0F0_TBD_FC D0F0_SVID_CTL // 1106h/1106h/x/x Subsystem Vendor ID
#define CND003_MMIO_D0F0_SSID_CTL 0xFE // Subsystem ID Control
    #define CND003_MMIO_D0F0_TBD_FF D0F0_SSID_CTL // 9100h/9100h/x/x Subsystem ID
#define CND003_MMIO_D0F0_PCI_EXPRESS_EXTENDED_CAP_HDR 0x100 // PCI Express Extended Capability Header
    #define CND003_MMIO_D0F0_TBD_103    0xFFF00000  // 000h/R/x/x Next Capability Offset
    #define CND003_MMIO_D0F0_TBD_102    0xF0000     // 0/0/x/x Capability Version
    #define CND003_MMIO_D0F0_TBD_100    0xFFFF      // 0000h/R/x/x PCI Express Extended Capability ID
#define CND003_MMIO_D0F0_XBCTL_BW_STA_2 0x108 // XBCTL BW Status 2
    #define CND003_MMIO_D0F0_CUR_P9TOP0_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P9 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P10TOP0_BDW_NP 0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P10 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P11TOP0_BDW_NP 0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P11 to P0 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP0_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P1 to P0 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_3 0x10C // XBCTL BW Status 3
    #define CND003_MMIO_D0F0_CUR_P2TOP0_BDW_PW  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P2 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P3TOP0_BDW_PW  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P3 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P4TOP0_BDW_PW  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P4 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P5TOP0_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P5 to P0 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_4 0x110 // XBCTL BW Status 4
    #define CND003_MMIO_D0F0_CUR_P6TOP0_BDW_PW  0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P7TOP0_BDW_PW  0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P8TOP0_BDW_PW  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P9TOP0_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P9 to P0 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_5 0x114 // XBCTL BW Status 5
    #define CND003_MMIO_D0F0_CUR_P10TOP0_BDW_PW 0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P10 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P11TOP0_BDW_PW 0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P11 to P0 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP1_BDW_NP  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P0 to P1 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP1_BDW_NP  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P9 to P1 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_6 0x118 // XBCTL BW Status 6
    #define CND003_MMIO_D0F0_CUR_P0TOP1_BDW_PW  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P0 to P1 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP1_BDW_PW  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P9 to P1 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP2_BDW_NP  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P0 to P2 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP2_BDW_NP  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P1 to P2 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_7 0x11C // XBCTL BW Status 7
    #define CND003_MMIO_D0F0_CUR_P9TOP2_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P9 to P2 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP2_BDW_PW  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P0 to P2 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP2_BDW_PW  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P1 to P2 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP2_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P9 to P2 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_8 0x120 // XBCTL BW Status 8
    #define CND003_MMIO_D0F0_CUR_P0TOP3_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P0 to P3 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP3_BDW_NP  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P1 to P3 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP3_BDW_NP  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P9 to P3 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP3_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P0 to P3 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_9 0x124 // XBCTL BW Status 9
    #define CND003_MMIO_D0F0_CUR_P1TOP3_BDW_PW  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P1 to P3 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP3_BDW_PW  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P9 to P3 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP4_BDW_NP  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P0 to P4 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP4_BDW_NP  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P1 to P4 Non-posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_10 0x128 // XBCTL BW Status 10
    #define CND003_MMIO_D0F0_CUR_P9TOP4_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P9 to P4 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP4_BDW_PW  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P0 to P4 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP4_BDW_PW  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P1 to P4 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP4_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P9 to P4 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_11 0x12C // XBCTL BW Status 11
    #define CND003_MMIO_D0F0_CUR_P0TOP5_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P0 to P5 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP5_BDW_NP  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P1 to P5 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP5_BDW_NP  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P9 to P5 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP5_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P0 to P5 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_12 0x130 // XBCTL BW Status 12
    #define CND003_MMIO_D0F0_CUR_P1TOP5_BDW_PW  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P1 to P5 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP5_BDW_PW  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P9 to P5 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP6_BDW_NP  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P1TOP6_BDW_NP  0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_STA_13 0x134 // XBCTL BW Status 13
    #define CND003_MMIO_D0F0_CUR_P9TOP6_BDW_NP  0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P0TOP6_BDW_PW  0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P1TOP6_BDW_PW  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P9TOP6_BDW_PW  0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_STA_14 0x138 // XBCTL BW Status 14
    #define CND003_MMIO_D0F0_CUR_P0TOP7_BDW_NP  0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P1TOP7_BDW_NP  0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P9TOP7_BDW_NP  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P0TOP7_BDW_PW  0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_STA_15 0x13C // XBCTL BW Status 15
    #define CND003_MMIO_D0F0_CUR_P1TOP7_BDW_PW  0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P9TOP7_BDW_PW  0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P0TOP8_BDW_NP  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P1TOP8_BDW_NP  0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_STA_16 0x140 // XBCTL BW Status 16
    #define CND003_MMIO_D0F0_CUR_P9TOP8_BDW_NP  0xFF000000  // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P0TOP8_BDW_PW  0xFF0000    // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P1TOP8_BDW_PW  0xFF00      // 0/0/0/0 Reserved
    #define CND003_MMIO_D0F0_CUR_P9TOP8_BDW_PW  0xFF        // 0/0/0/0 Reserved
#define CND003_MMIO_D0F0_XBCTL_BW_STA_17 0x144 // XBCTL BW Status 17
    #define CND003_MMIO_D0F0_CUR_P0TOP9_BDW_NP  0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P0 to P9 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP9_BDW_NP  0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P1 to P9 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP9_BDW_PW  0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P0 to P9 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP9_BDW_PW  0xFF        // HwInit/x/x/x Current Bandwidth Usage for P1 to P9 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_18 0x148 // XBCTL BW Status 18
    #define CND003_MMIO_D0F0_CUR_P0TOP10_BDW_NP 0xFF000000  // HwInit/x/x/x Current Bandwidth Usage for P0 to P10 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P1TOP10_BDW_NP 0xFF0000    // HwInit/x/x/x Current Bandwidth Usage for P1 to P10 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP10_BDW_NP 0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P9 to P10 Non-posted Cycle
    #define CND003_MMIO_D0F0_CUR_P0TOP10_BDW_PW 0xFF        // HwInit/x/x/x Current Bandwidth Usage for P0 to P10 Posted Cycle
#define CND003_MMIO_D0F0_XBCTL_BW_STA_19 0x14C // XBCTL BW Status 19
    #define CND003_MMIO_D0F0_RSV_10F            0xFF000000  // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RSV_10E            0xFF0000    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_CUR_P1TOP10_BDW_PW 0xFF00      // HwInit/x/x/x Current Bandwidth Usage for P1 to P10 Posted Cycle
    #define CND003_MMIO_D0F0_CUR_P9TOP10_BDW_PW 0xFF        // HwInit/x/x/x Current Bandwidth Usage for P9 to P10 Posted Cycle
#define CND003_MMIO_D0F0_INTR_MAP_FOR_PEA0_PEA1_PEA2_PEA3 0x150 // Interrupt Map for PEA0, PEA1, PEA2, PEA3
    #define CND003_MMIO_D0F0_RINTD_PEA3_INTSEL  (BIT30 + BIT31) // 11b/11b/x/x PCIE PEA3 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEA3_INTSEL  (BIT28 + BIT29) // 10b/10b/x/x PCIE PEA3 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEA3_INTSEL  (BIT26 + BIT27) // 01b/01b/x/x PCIE PEA3 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEA3_INTSEL  (BIT24 + BIT25) // 00b/00b/x/x PCIE PEA3 INTA_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTD_PEA2_INTSEL  (BIT22 + BIT23) // 10b/10b/x/x PCIE PEA2 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEA2_INTSEL  (BIT20 + BIT21) // 01b/01b/x/x PCIE PEA2 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEA2_INTSEL  (BIT18 + BIT19) // 00b/00b/x/x PCIE PEA2 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEA2_INTSEL  (BIT16 + BIT17) // 11b/11b/x/x PCIE PEA2 INTA_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTD_PEA1_INTSEL  (BIT14 + BIT15) // 01b/01b/x/x PCIE PEA1 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEA1_INTSEL  (BIT12 + BIT13) // 00b/00b/x/x PCIE PEA1 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEA1_INTSEL  (BIT10 + BIT11) // 11b/11b/x/x PCIE PEA1 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEA1_INTSEL  (BIT8 + BIT9)   // 10b/10b/x/x PCIE PEA1 INTA_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTD_PEA0_INTSEL  (BIT6 + BIT7)   // 00b/00b/x/x PCIE PEA0 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEA0_INTSEL  (BIT4 + BIT5)   // 11b/11b/x/x PCIE PEA0 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEA0_INTSEL  (BIT2 + BIT3)   // 10b/10b/x/x PCIE PEA0 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEA0_INTSEL  (BIT0 + BIT1)   // 01b/01b/x/x PCIE PEA0 INTA_ Interrupt Selection
#define CND003_MMIO_D0F0_INTR_MAP_FOR_PEA4_PEB0_PEB1 0x154 // Interrupt Map for PEA4, PEB0, PEB1
    #define CND003_MMIO_D0F0_RINTD_PESB_INTSEL  (BIT30 + BIT31) // 11b/11b/x/x PCIE PESB INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PESB_INTSEL  (BIT28 + BIT29) // 10b/10b/x/x PCIE PESB INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PESB_INTSEL  (BIT26 + BIT27) // 01b/01b/x/x PCIE PESB INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PESB_INTSEL  (BIT24 + BIT25) // 00b/00b/x/x PCIE PESB INTA_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTD_PEB1_INTSEL  (BIT22 + BIT23) // 10b/10b/x/x PCIE PEB1 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEB1_INTSEL  (BIT20 + BIT21) // 01b/01b/x/x PCIE PEB1 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEB1_INTSEL  (BIT18 + BIT19) // 00b/00b/x/x PCIE PEB1 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEB1_INTSEL  (BIT16 + BIT17) // 11b/11b/x/x PCIE PEB1 INTA_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTD_PEB0_INTSEL  (BIT14 + BIT15) // 01b/01b/x/x PCIE PEB0 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEB0_INTSEL  (BIT12 + BIT13) // 00b/00b/x/x PCIE PEB0 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEB0_INTSEL  (BIT10 + BIT11) // 11b/11b/x/x PCIE PEB0 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEB0_INTSEL  (BIT8 + BIT9)   // 10b/10b/x/x PCIE PEB0 INTA_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTD_PEA4_INTSEL  (BIT6 + BIT7)   // 00b/00b/x/x PCIE PEA4 INTD_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTC_PEA4_INTSEL  (BIT4 + BIT5)   // 11b/11b/x/x PCIE PEA4 INTC_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTB_PEA4_INTSEL  (BIT2 + BIT3)   // 10b/10b/x/x PCIE PEA4 INTB_ Interrupt Selection
    #define CND003_MMIO_D0F0_RINTA_PEA4_INTSEL  (BIT0 + BIT1)   // 01b/01b/x/x PCIE PEA4 INTA_ Interrupt Selection
#define CND003_MMIO_D0F0_CLKREQ_SEL_0 0x158 // CLKREQ Selection 0
    #define CND003_MMIO_D0F0_RSV_143            0xF0000000              // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEB1   (BIT25 + BIT26 + BIT27) // 0/0/x/x CLKREQ Selection for PEB1
    #define CND003_MMIO_D0F0_RCLKREQEN_PEB1     BIT24                   // 0/0/x/x CLKREQ input enable for PEB1
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEB0   (BIT21 + BIT22 + BIT23) // 0/0/x/x CLKREQ Selection for PEB0
    #define CND003_MMIO_D0F0_RCLKREQEN_PEB0     BIT20                   // 0/0/x/x CLKREQ Input Enable for PEB0
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEA4   (BIT17 + BIT18 + BIT19) // 0/0/x/x CLKREQ Selection for PEA4
    #define CND003_MMIO_D0F0_RCLKREQEN_PEA4     BIT16                   // 0/0/x/x CLKREQ input enable for PEA4
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEA3   (BIT13 + BIT14 + BIT15) // 0/0/x/x CLKREQ Selection for PEA3
    #define CND003_MMIO_D0F0_RCLKREQEN_PEA3     BIT12                   // 0/0/x/x CLKREQ Input Enable for PEA3
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEA2   (BIT9 + BIT10 + BIT11)  // 0/0/x/x CLKREQ Selection for PEA2
    #define CND003_MMIO_D0F0_RCLKREQEN_PEA2     BIT8                    // 0/0/x/x CLKREQ Input Enable for PEA2
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEA1   (BIT5 + BIT6 + BIT7)    // 0/0/x/x CLKREQ Selection for PEA1
    #define CND003_MMIO_D0F0_RCLKREQEN_PEA1     BIT4                    // 0/0/x/x CLKREQ Input Enable for PEA1
    #define CND003_MMIO_D0F0_RCLKREQ_SEL_PEA0   (BIT1 + BIT2 + BIT3)    // 0/0/x/x CLKREQ Selection for PEA0
    #define CND003_MMIO_D0F0_RCLKREQEN_PEA0     BIT0                    // 0/0/x/x CLKREQ Input Enable for PEA0
#define CND003_MMIO_D0F0_REFCLK_0_CTL 0x160 // REFCLK_0 Control
    #define CND003_MMIO_D0F0_RREFCLK0_HWEN  BIT7                    // 0/0/x/x REFCLK_0 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK0_SWON  BIT6                    // 0/0/x/x REFCLK_0 SW Control On
    #define CND003_MMIO_D0F0_RSV_150        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK0_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_0 Control Source
#define CND003_MMIO_D0F0_REFCLK_1_CTL 0x161 // REFCLK_1 Control
    #define CND003_MMIO_D0F0_RREFCLK1_HWEN  BIT7                    // 0/0/x/x REFCLK_1 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK1_SWON  BIT6                    // 0/0/x/x REFCLK_1 SW Control On
    #define CND003_MMIO_D0F0_RSV_151        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK1_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_1 Control Source
#define CND003_MMIO_D0F0_REFCLK_2_CTL 0x162 // REFCLK_2 Control
    #define CND003_MMIO_D0F0_RREFCLK2_HWEN  BIT7                    // 0/0/x/x REFCLK_2 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK2_SWON  BIT6                    // 0/0/x/x REFCLK_2 SW Control On
    #define CND003_MMIO_D0F0_RSV_152        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK2_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_2 Control Source
#define CND003_MMIO_D0F0_REFCLK_3_CTL 0x163 // REFCLK_3 Control
    #define CND003_MMIO_D0F0_RREFCLK3_HWEN  BIT7                    // 0/0/x/x REFCLK_3 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK3_SWON  BIT6                    // 0/0/x/x REFCLK_3 SW Control On
    #define CND003_MMIO_D0F0_RSV_153        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK3_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_3 Control Source
#define CND003_MMIO_D0F0_REFCLK_4_CTL 0x164 // REFCLK_4 Control
    #define CND003_MMIO_D0F0_RREFCLK4_HWEN  BIT7                    // 0/0/x/x REFCLK_4 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK4_SWON  BIT6                    // 0/0/x/x REFCLK_4 SW Control On
    #define CND003_MMIO_D0F0_RSV_154        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK4_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_4 Control Source
#define CND003_MMIO_D0F0_REFCLK_5_CTL 0x165 // REFCLK_5 Control
    #define CND003_MMIO_D0F0_RREFCLK5_HWEN  BIT7                    // 0/0/x/x REFCLK_5 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK5_SWON  BIT6                    // 0/0/x/x REFCLK_5 SW Control On
    #define CND003_MMIO_D0F0_RSV_155        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK5_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_5 Control Source
#define CND003_MMIO_D0F0_REFCLK_6_CTL 0x166 // REFCLK_6 Control
    #define CND003_MMIO_D0F0_RREFCLK6_HWEN  BIT7                    // 0/0/x/x REFCLK_6 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK6_SWON  BIT6                    // 0/0/x/x REFCLK_6 SW Control On
    #define CND003_MMIO_D0F0_RSV_156        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK6_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_6 Control Source
#define CND003_MMIO_D0F0_REFCLK_7_CTL 0x167 // REFCLK_7 Control
    #define CND003_MMIO_D0F0_RREFCLK7_HWEN  BIT7                    // 0/0/x/x REFCLK_7 HW Control Enable
    #define CND003_MMIO_D0F0_RREFCLK7_SWON  BIT6                    // 0/0/x/x REFCLK_7 SW Control On
    #define CND003_MMIO_D0F0_RSV_157        (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RREFCLK7_HWOPT (BIT0 + BIT1 + BIT2)    // 0/0/x/x REFCLK_7 Control Source
#define CND003_MMIO_D0F0_SBDBG_DES_PORT_ASSIGNMENT 0x168 // SBDBG Destination Port Assignment
    #define CND003_MMIO_D0F0_RSV_161        BIT15   // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RSBDBG_PEB1    BIT14   // 0/0/x/x Enable PEB1 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSBDBG_PEB0    BIT13   // 0/0/x/x Enable PEB0 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSBDBG_PEA4    BIT12   // 0/0/X/x Enable PEA4 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSBDBG_PEA3    BIT11   // 0/0/x/x Enable PEA3 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSBDBG_PEA2    BIT10   // 0/0/x/x Enable PEA2 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSBDBG_PEA1    BIT9    // 0/0/x/x Enable PEA1 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSBDBG_PEA0    BIT8    // 0/0/x/x Enable PEA0 as Debug Capture Output Port
    #define CND003_MMIO_D0F0_RSV_160        BIT7    // 0/0/x/X Reserved
    #define CND003_MMIO_D0F0_RRCVECNTEN     BIT6    // 0/0/x/x Enable Receiver Error Counter
    #define CND003_MMIO_D0F0_RDISPEXC_PHYB  BIT5    // 0/0/x/x Disable PEB0, PEB1
    #define CND003_MMIO_D0F0_RDISPEXC_PHYA  BIT4    // 0/0/x/x Disable PEA0, PEA1, PEA2, PEA3, PEA4
    #define CND003_MMIO_D0F0_RSBDBGDESID    0xF     // 1h/1h/x/x SBDBG Destination ID
#define CND003_MMIO_D0F0_MALFORMTLP_FORWARD_OPTION 0x16A // MalformTLP Forward Option
    #define CND003_MMIO_D0F0_RMALTLPFWD_EP      BIT7    // 0/0/x/x Forward Malform TLP on EP
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEB1    BIT6    // 0/0/x/x Forward Malform TLP on PEB1
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEB0    BIT5    // 0/0/x/x Forward Malform TLP on PEB0
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEA4    BIT4    // 0/0/x/x Forward Malform TLP on PEA4
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEA3    BIT3    // 0/0/x/x Forward Malform TLP on PEA3
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEA2    BIT2    // 0/0/x/x Forward Malform TLP on PEA2
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEA1    BIT1    // 0/0/x/x Forward Malform TLP on PEA1
    #define CND003_MMIO_D0F0_RMALTLPFWD_PEA0    BIT0    // 0/0/x/x Forward Malform TLP on PEA0
#define CND003_MMIO_D0F0_MALFORMTLP_FORWARD_OPTION_Z1 0x16B // MalformTLP Forward Option
    #define CND003_MMIO_D0F0_RSV_16B        BIT7    // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_RDISRTY_PEB1   BIT6    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEB1
    #define CND003_MMIO_D0F0_RDISRTY_PEB0   BIT5    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEB0
    #define CND003_MMIO_D0F0_RDISRTY_PEA4   BIT4    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEA4
    #define CND003_MMIO_D0F0_RDISRTY_PEA3   BIT3    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEA3
    #define CND003_MMIO_D0F0_RDISRTY_PEA2   BIT2    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEA2
    #define CND003_MMIO_D0F0_RDISRTY_PEA1   BIT1    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEA1
    #define CND003_MMIO_D0F0_RDISRTY_PEA0   BIT0    // 0/0/x/x SBDBG Mode Retry Buffur Disenable on PEA0
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_CTL 0x170 // Shadow Registers for SubsystemID and SubVendorID Control
    #define CND003_MMIO_D0F0_RSV_170            0xFFFFFC00  // 0/0/x/x Reserved
    #define CND003_MMIO_D0F0_SSID_SHADOW_PESB   BIT9        // 0/0/x/x Downstream Port PESB SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEB1   BIT8        // 0/0/x/x Downstream Port PEB1 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEB0   BIT7        // 0/0/x/x Downstream Port PEB0 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEA4   BIT6        // 0/0/x/x Downstream Port PEA4 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEA3   BIT5        // 0/0/x/x Downstream Port PEA3 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEA2   BIT4        // 0/0/x/x Downstream Port PEA2 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEA1   BIT3        // 0/0/x/x Downstream Port PEA1 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_PEA0   BIT2        // 0/0/x/x Downstream Port PEA0 SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_XBAR   BIT1        // 0/0/x/x Downstream Port XBAR SSID Shadow Enable 
    #define CND003_MMIO_D0F0_SSID_SHADOW_EP     BIT0        // 0/0/x/x Upstream Port SSID Shadow Enable 
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_EP 0x174 // Shadow Registers for SubsystemID and SubVendorID for EP
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_EP     0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of EP
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_EP    0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of EP
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_XBCTL 0x178 // Shadow Registers for SubsystemID and SubVendorID for XBCTL
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_XBAR   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of XBCTL
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_XBAR  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of XBCTL
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEA0 0x17C // Shadow Registers for SubsystemID and SubVendorID for PEA0
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEA0   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEA0
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEA0  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEA0
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEA1 0x180 // Shadow Registers for SubsystemID and SubVendorID for PEA1
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEA1   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEA1
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEA1  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEA1
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEA2 0x184 // Shadow Registers for SubsystemID and SubVendorID for PEA2
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEA2   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEA2
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEA2  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEA2
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEA3 0x188 // Shadow Registers for SubsystemID and SubVendorID for PEA3
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEA3   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEA3
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEA3  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEA3
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEA4 0x18C // Shadow Registers for SubsystemID and SubVendorID for PEA4
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEA4   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEA4
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEA4  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEA4
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEB0 0x190 // Shadow Registers for SubsystemID and SubVendorID for PEB0
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEB0   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEB0
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEB0  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEB0
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PEB1 0x194 // Shadow Registers for SubsystemID and SubVendorID for PEB1
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PEB1   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PEB1
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PEB1  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PEB1
#define CND003_MMIO_D0F0_SHADOW_REGS_FOR_SUBSYSID_AND_SUBVENID_FOR_PESB 0x198 // Shadow Registers for SubsystemID and SubVendorID for PESB
    #define CND003_MMIO_D0F0_SSID_SHADOW_REG_PESB   0xFFFF0000  // 0/0/x/x Subsystem ID Shadow Register of PESB
    #define CND003_MMIO_D0F0_SSVID_SHADOW_REG_PESB  0xFFFF      // 0/0/x/x Subsystem Vendor ID Shadow Register of PESB
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
