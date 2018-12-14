//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_BUSxp1_D1-D7F0_R100(A1).doc.
#ifndef _REG_CND003_D1_D7F0_H_
#define _REG_CND003_D1_D7F0_H_
// D1-D7F0
#define CND003_BUSXP1_D1D7F0_VID_D1F0 0x0 // Vendor ID (D1F0)
    #define CND003_BUSXP1_D1D7F0_VENID_15 BIT15   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_14 BIT14   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_13 BIT13   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_12 BIT12   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_11 BIT11   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_10 BIT10   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_9  BIT9    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_8  BIT8    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_7  BIT7    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_6  BIT6    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_5  BIT5    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_4  BIT4    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_3  BIT3    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_2  BIT2    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_1  BIT1    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D1D7F0_VENID_0  BIT0    // HwInit/x/x/x Vendor ID
#define CND003_BUSXP1_D1D7F0_DID_D1F0 0x2 // Device ID (D1F0)
    #define CND003_BUSXP1_D1D7F0_DEVID D1D7F0_DID_D1F0 // 0710h/0710h/x/x Device ID
#define CND003_BUSXP1_D1D7F0_PCI_CMD 0x4 // PCI Command
    #define CND003_BUSXP1_D1D7F0_RSV_0    0xF800  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RINTDIS  BIT10   // 0/0/x/x Interrupt Disable
    #define CND003_BUSXP1_D1D7F0_RSV_1    BIT9    // 0/R/x/x Fast Back-to-back Transaction Enable
    #define CND003_BUSXP1_D1D7F0_RSERR    BIT8    // 0/x/x/x SERR# Enable
    #define CND003_BUSXP1_D1D7F0_RSV_2    BIT7    // 0/R/x/x Address / Data Stepping
    #define CND003_BUSXP1_D1D7F0_RPTYERR  BIT6    // 0/0/x/x Parity Error Response
    #define CND003_BUSXP1_D1D7F0_RSV_3    BIT5    // 0/R/x/x VGA Palette Snooping
    #define CND003_BUSXP1_D1D7F0_RX004_4  BIT4    // 0/x/x/x Memory Write and Invalidate
    #define CND003_BUSXP1_D1D7F0_RX004_3  BIT3    // 0/x/x/x Response to Special Cycle
    #define CND003_BUSXP1_D1D7F0_RMSTR    BIT2    // 0/x/x/x Bus Master Enable
    #define CND003_BUSXP1_D1D7F0_RENMEM   BIT1    // 0/x/x/x Memory Space
    #define CND003_BUSXP1_D1D7F0_RENIO    BIT0    // 0/x/x/x I/O Space
#define CND003_BUSXP1_D1D7F0_PCI_STA 0x6 // PCI Status
    #define CND003_BUSXP1_D1D7F0_SPERRS   BIT15                   // 0/0/x/x Detected Parity Error
    #define CND003_BUSXP1_D1D7F0_SERRS    BIT14                   // 0/0/x/x Signaled System Error
    #define CND003_BUSXP1_D1D7F0_SMABORT  BIT13                   // 0/R/x/x Received Master Abort
    #define CND003_BUSXP1_D1D7F0_STABORTM BIT12                   // 0/R/x/x Received Target Abort
    #define CND003_BUSXP1_D1D7F0_STABORTS BIT11                   // 0/R/x/x Signaled Target Abort
    #define CND003_BUSXP1_D1D7F0_RSV_5    (BIT9 + BIT10)          // 0/R/x/x DEVSEL# Timing
    #define CND003_BUSXP1_D1D7F0_SDPERRS  BIT8                    // 0/0/x/x Master Data Parity Error
    #define CND003_BUSXP1_D1D7F0_RSV_6    BIT7                    // 0/R/x/x Capability of Accepting Fast Back-to-back as a Target
    #define CND003_BUSXP1_D1D7F0_RX004_14 BIT6                    // 0/x/x/x User Definable Features
    #define CND003_BUSXP1_D1D7F0_RX004_13 BIT5                    // 0/x/x/x 66 MHz Capable
    #define CND003_BUSXP1_D1D7F0_RCAP     BIT4                    // 1b/R/x/x Capabilities List
    #define CND003_BUSXP1_D1D7F0_SINTSTT  BIT3                    // HwInit/x/x/x Interrupt Status
    #define CND003_BUSXP1_D1D7F0_RSV_7    (BIT0 + BIT1 + BIT2)    // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_REV_ID 0x8 // Revision ID
    #define CND003_BUSXP1_D1D7F0_TBD_4 D1D7F0_REV_ID // 0/0/x/x Revision Code
#define CND003_BUSXP1_D1D7F0_CLASS_CODE 0x9 // Class Code
    #define CND003_BUSXP1_D1D7F0_TBD_5_23_0 D1D7F0_CLASS_CODE // 06 0400h/R/x/x Class Code
#define CND003_BUSXP1_D1D7F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_BUSXP1_D1D7F0_RSV_8 D1D7F0_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define CND003_BUSXP1_D1D7F0_MASTER_LATENCY_TIMER 0xD // Master Latency Timer
    #define CND003_BUSXP1_D1D7F0_RSV_9 D1D7F0_MASTER_LATENCY_TIMER // 0/R/x/x Master Latency Timer
#define CND003_BUSXP1_D1D7F0_HDR_TYPE 0xE // Header Type
    #define CND003_BUSXP1_D1D7F0_RSV_0E D1D7F0_HDR_TYPE // 01h/x/x/x Header Type Code
#define CND003_BUSXP1_D1D7F0_BIST 0xF // Built In Self Test (BIST)
    #define CND003_BUSXP1_D1D7F0_TBD_7 D1D7F0_BIST // 0/R/x/x BIST Support
#define CND003_BUSXP1_D1D7F0_LOWER_BASE_ADR 0x10 // Lower Base Address
    #define CND003_BUSXP1_D1D7F0_TBD_8 D1D7F0_LOWER_BASE_ADR // 0/R/x/x Lower Base Address
#define CND003_BUSXP1_D1D7F0_UPPER_BASE_ADR 0x14 // Upper Base Address
    #define CND003_BUSXP1_D1D7F0_TBD_9 D1D7F0_UPPER_BASE_ADR // 0/R/x/x Upper Base Address
#define CND003_BUSXP1_D1D7F0_PRIMARY_BUS_NUM 0x18 // Primary Bus Number
    #define CND003_BUSXP1_D1D7F0_PBN D1D7F0_PRIMARY_BUS_NUM // 0/x/x/x Primary Bus Number
#define CND003_BUSXP1_D1D7F0_SECONDARY_BUS_NUM 0x19 // Secondary Bus Number
    #define CND003_BUSXP1_D1D7F0_SBN D1D7F0_SECONDARY_BUS_NUM // 0/x/x/x Secondary Bus Number
#define CND003_BUSXP1_D1D7F0_SUBORDINATE_BUS_NUM 0x1A // Subordinate Bus Number
    #define CND003_BUSXP1_D1D7F0_SSBN D1D7F0_SUBORDINATE_BUS_NUM // 0/x/x/x Subordinate Bus Number
#define CND003_BUSXP1_D1D7F0_SECONDARY_LATENCY_TIMER 0x1B // Secondary Latency Timer
    #define CND003_BUSXP1_D1D7F0_RX018_31_24 D1D7F0_SECONDARY_LATENCY_TIMER // 0/R/x/x Secondary Latency Timer
#define CND003_BUSXP1_D1D7F0_IO_BASE 0x1C // I/O Base
    #define CND003_BUSXP1_D1D7F0_RIOBS_15_12  0xF0    // Fh/x/x/x I/O Base (AD[15:12] - Inclusive)
    #define CND003_BUSXP1_D1D7F0_TBD_10       0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_BUSXP1_D1D7F0_IO_LIMIT 0x1D // I/O Limit
    #define CND003_BUSXP1_D1D7F0_RIOLM_15_12  0xF0    // 0/x/x/x I/O Limit (AD[15:12] - Inclusive)
    #define CND003_BUSXP1_D1D7F0_TBD_11       0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_BUSXP1_D1D7F0_SECONDARY_STA 0x1E // Secondary Status
    #define CND003_BUSXP1_D1D7F0_SSPERRS      BIT15           // 0/0/x/x Detected Parity Error
    #define CND003_BUSXP1_D1D7F0_SSERRS       BIT14           // 0/0/x/x Received System Error
    #define CND003_BUSXP1_D1D7F0_SSMABORT     BIT13           // 0/0/x/x Received Master Abort
    #define CND003_BUSXP1_D1D7F0_SSTABORTM    BIT12           // 0/0/x/x Received Target Abort
    #define CND003_BUSXP1_D1D7F0_RSV_1E_5     BIT11           // 0/x/x/x Signaled Target Abort
    #define CND003_BUSXP1_D1D7F0_RX01C_26_25  (BIT9 + BIT10)  // 0/x/x/x DEVSEL Timing
    #define CND003_BUSXP1_D1D7F0_SSDPERRS     BIT8            // 0/0/x/x Master Data Parity Error
    #define CND003_BUSXP1_D1D7F0_RX01C_23     BIT7            // 0/x/x/x Fast Back-to-Back Capable
    #define CND003_BUSXP1_D1D7F0_RX01C_22     BIT6            // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX01C_21     BIT5            // 0/x/x/x 66MHz Capability
    #define CND003_BUSXP1_D1D7F0_RX01C_20_16  0x1F            // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_MEM_BASE 0x20 // Memory Base
    #define CND003_BUSXP1_D1D7F0_RM1BS_31_20  0xFFF0  // FFFh/x/x/x Memory Base (AD[31:20] ? Inclusive)
    #define CND003_BUSXP1_D1D7F0_RSV_11       0xF     // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_MEM_LIMIT 0x22 // Memory Limit
    #define CND003_BUSXP1_D1D7F0_RM1LM_31_20  0xFFF0  // 0/x/x/x Memory Limit (AD[31:20] ? Inclusive)
    #define CND003_BUSXP1_D1D7F0_RSV_12       0xF     // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_PREFETCHABLE_MEM_BASE 0x24 // Prefetchable Memory Base
    #define CND003_BUSXP1_D1D7F0_RM2BS_31_20  0xFFF0                  // FFFh/x/x/x Prefetchable Memory Base AD[31:20]
    #define CND003_BUSXP1_D1D7F0_RSV_13       (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_12       BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory Base
#define CND003_BUSXP1_D1D7F0_PREFETCHABLE_MEM_LIMIT 0x26 // Prefetchable Memory Limit
    #define CND003_BUSXP1_D1D7F0_RM2LM_31_20  0xFFF0                  // 0/x/x/x Prefetchable Memory Limit AD[31:20]
    #define CND003_BUSXP1_D1D7F0_RSV_14       (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_13       BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory  Limit
#define CND003_BUSXP1_D1D7F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS 0x28 // Prefetchable Memory Base Upper 32 Bits
    #define CND003_BUSXP1_D1D7F0_RM3BS_63_32 D1D7F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS // 0/x/x/x Prefetchable Memory Base Upper bit[63:32]
#define CND003_BUSXP1_D1D7F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS 0x2C // Prefetchable Memory Limit Upper 32 Bits
    #define CND003_BUSXP1_D1D7F0_RM3LM_63_32 D1D7F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS // 0/x/x/x Prefetchable Memory Limit Upper Bit[63:32]
#define CND003_BUSXP1_D1D7F0_IO_BASE_UPPER 0x30 // I/O Base Upper
    #define CND003_BUSXP1_D1D7F0_TBD_14 D1D7F0_IO_BASE_UPPER // 0/R/x/x I/O Base Upper 16 Bits Address
#define CND003_BUSXP1_D1D7F0_IO_BASE_LIMIT 0x32 // I/O Base Limit
    #define CND003_BUSXP1_D1D7F0_TBD_15 D1D7F0_IO_BASE_LIMIT // 0/R/x/x I/O Limit Upper 16 Bits Address
#define CND003_BUSXP1_D1D7F0_CAP_PTR 0x34 // Capability Pointer
    #define CND003_BUSXP1_D1D7F0_TBD_16 D1D7F0_CAP_PTR // 40h/40h/x/x Capability Pointer
#define CND003_BUSXP1_D1D7F0_RESERVED 0x35 // Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_16_1 D1D7F0_RESERVED // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_INTR_LINE 0x3C // Interrupt Line
    #define CND003_BUSXP1_D1D7F0_RINTLN D1D7F0_INTR_LINE // 0/x/x/x Interrupt Line
#define CND003_BUSXP1_D1D7F0_INTR_PIN 0x3D // Interrupt Pin
    #define CND003_BUSXP1_D1D7F0_RX03C_15_11  0xF8                    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_INTPIN       (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Interrupt Pin
#define CND003_BUSXP1_D1D7F0_BRIDGE_CTL 0x3E // Bridge Control
    #define CND003_BUSXP1_D1D7F0_RSV_17       0xF000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX03C_27     BIT11   // 0/x/x/x Discard Timer SERR# Enable
    #define CND003_BUSXP1_D1D7F0_RX03C_26     BIT10   // 0/x/x/x Discard Timer Status
    #define CND003_BUSXP1_D1D7F0_RX03C_25     BIT9    // 0/x/x/x Secondary Discard Timer
    #define CND003_BUSXP1_D1D7F0_RX03C_24     BIT8    // 0/x/x/x Primary Discard Timer
    #define CND003_BUSXP1_D1D7F0_RX03C_23     BIT7    // 0/x/x/x Fast Back-to-Back Enable
    #define CND003_BUSXP1_D1D7F0_RSRST        BIT6    // 0/x/x/x Secondary Bus Reset
    #define CND003_BUSXP1_D1D7F0_RSV_18       BIT5    // 0/R/x/x Master Abort Mode
    #define CND003_BUSXP1_D1D7F0_RVGA16       BIT4    // 0/x/x/x Base VGA 16 Bits Decode
    #define CND003_BUSXP1_D1D7F0_RVGA         BIT3    // 0/x/x/x VGA Compatible I/O and Memory Address Range
    #define CND003_BUSXP1_D1D7F0_RISA         BIT2    // 0/x/x/x Block/Forward ISA I/O Cycles
    #define CND003_BUSXP1_D1D7F0_RSERRFWD     BIT1    // 0/x/x/x SERR Enable
    #define CND003_BUSXP1_D1D7F0_RPTYERRTLP   BIT0    // 0/x/x/x Parity Error Response Enable
#define CND003_BUSXP1_D1D7F0_PCI_EXPRESS_LIST 0x40 // PCI Express List
    #define CND003_BUSXP1_D1D7F0_TBD_24   0xFF00  // A0h/A0h/x/x Next Pointer
    #define CND003_BUSXP1_D1D7F0_TBD_25   0xFF    // 10h/10h/x/x Capability ID
#define CND003_BUSXP1_D1D7F0_PCI_EXPRESS_CAPS_D1F0 0x42 // PCI Express Capabilities (D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_42_15    BIT15   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RTCSEN       BIT14   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_XINTMNO      0x3E00  // 0/0/x/x Interrupt Message Number
    #define CND003_BUSXP1_D1D7F0_XSLIMP       BIT8    // 1b/1/x/x Slot Implemented
    #define CND003_BUSXP1_D1D7F0_XDPTYPE      0xF0    // 0110b/0110/x/x Device / Port Type
    #define CND003_BUSXP1_D1D7F0_PCIE_VER_3   BIT3    // 0/0/x/x Capability Version Bit 3
    #define CND003_BUSXP1_D1D7F0_PCIE_VER_2   BIT2    // 0/0/x/x Capability Version Bit 2 
    #define CND003_BUSXP1_D1D7F0_PCIE_VER_1   BIT1    // 1b/1b/x/x Capability Version Bit 1 
    #define CND003_BUSXP1_D1D7F0_PCIE_VER_0   BIT0    // 0/0/x/x Capability Version Bit 0 
#define CND003_BUSXP1_D1D7F0_DEV_CAPS_1 0x44 // Device Capabilities 1
    #define CND003_BUSXP1_D1D7F0_RSV_19   (BIT29 + BIT30 + BIT31) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_27   BIT28                   // 0/0/x/x Function Level Reset Capability
    #define CND003_BUSXP1_D1D7F0_RSV_20   (BIT26 + BIT27)         // 0/R/x/x Captured Slot Power Limit Scale
    #define CND003_BUSXP1_D1D7F0_RSV_21   0x3FC0000               // 0/R/x/x Captured Slot Power Limit Value
    #define CND003_BUSXP1_D1D7F0_RSV_22   (BIT16 + BIT17)         // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RRBERRP  BIT15                   // 1b/1/x/x Role-based Error Reporting
    #define CND003_BUSXP1_D1D7F0_RSV_23   BIT14                   // 0/R/x/x Power Indicator Present
    #define CND003_BUSXP1_D1D7F0_RSV_24   BIT13                   // 0/R/x/x Attention Indicator Present
    #define CND003_BUSXP1_D1D7F0_RSV_25   BIT12                   // 0/R/x/x Attention Button Present
    #define CND003_BUSXP1_D1D7F0_DAL1AL   (BIT9 + BIT10 + BIT11)  // 000b/0/x/x Endpoint L1 Acceptable Latency
    #define CND003_BUSXP1_D1D7F0_RSV_44   (BIT6 + BIT7 + BIT8)    // 0/R/x/x Endpoint L0s Acceptable Latency
    #define CND003_BUSXP1_D1D7F0_DAXTAGF  BIT5                    // 0/0/x/x Extended Tag Field Supported
    #define CND003_BUSXP1_D1D7F0_RSV_26   (BIT3 + BIT4)           // 0/R/x/x Phantom Functions Supported
    #define CND003_BUSXP1_D1D7F0_DAMPSS   (BIT0 + BIT1 + BIT2)    // 001b/001/x/x Max Payload Size Supported
#define CND003_BUSXP1_D1D7F0_DEV_CTL_1 0x48 // Device Control 1
    #define CND003_BUSXP1_D1D7F0_RSV_27   BIT15                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_DCMRRS   (BIT12 + BIT13 + BIT14) // 0/R/x/x Max Read Request Size
    #define CND003_BUSXP1_D1D7F0_DCENS    BIT11                   // 0/0/x/x Enable No Snoop
    #define CND003_BUSXP1_D1D7F0_DCAPPME  BIT10                   // 0/x/x/x Auxiliary Power PM Enable
    #define CND003_BUSXP1_D1D7F0_DCPFE    BIT9                    // 0/R/x/x Phantom Functions Enable
    #define CND003_BUSXP1_D1D7F0_DCETFE   BIT8                    // 0/0/x/x Extended Tag Field Enable
    #define CND003_BUSXP1_D1D7F0_DCMPS    (BIT5 + BIT6 + BIT7)    // 0/000*/001*/x Max Payload Size
    #define CND003_BUSXP1_D1D7F0_DCERO    BIT4                    // 1b/1/x/x Enable Relaxed Ordering
    #define CND003_BUSXP1_D1D7F0_DCURRE   BIT3                    // 0/0/x/x Unsupported Request Reporting Enable
    #define CND003_BUSXP1_D1D7F0_DCFERE   BIT2                    // 0/0/x/x Fatal Error Reporting Enable
    #define CND003_BUSXP1_D1D7F0_DCNFERE  BIT1                    // 0/0/x/x Non-Fatal Error Reporting Enable
    #define CND003_BUSXP1_D1D7F0_DCCERE   BIT0                    // 0/0/x/x Correctable Error Reporting Enable
#define CND003_BUSXP1_D1D7F0_DEV_STA_1 0x4A // Device Status 1
    #define CND003_BUSXP1_D1D7F0_RSV_4B   0xFFC0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_4B_5 BIT5    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_DSAPD    BIT4    // 0/0/x/x AUX Power Detected
    #define CND003_BUSXP1_D1D7F0_DSURD    BIT3    // 0/0/x/x Unsupported Request Detected (TL)
    #define CND003_BUSXP1_D1D7F0_DSFED    BIT2    // 0/0/x/x Fatal Error Detected (TL)
    #define CND003_BUSXP1_D1D7F0_DSNFED   BIT1    // 0/0/x/x Non-Fatal Error Detected (TL)
    #define CND003_BUSXP1_D1D7F0_DSCED    BIT0    // 0/0/x/x Correctable Error Detected (TL)
#define CND003_BUSXP1_D1D7F0_LINK_CAPS_1_D1F0 0x4C // Link Capabilities 1 (D1F0)
    #define CND003_BUSXP1_D1D7F0_LKPN         0xFF000000              // 02h/02h/x/x Port Number
    #define CND003_BUSXP1_D1D7F0_RSV_28G      BIT23                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_ASPMOPTCOMP  BIT22                   // 1b/1/x/x ASPM Optionality Compliance 
    #define CND003_BUSXP1_D1D7F0_RLBWNTFC     BIT21                   // 1b/1/x/x Link Bandwidth Notification Capability
    #define CND003_BUSXP1_D1D7F0_RDL_AR_CAP   BIT20                   // 1b/1/x/x Data Link Layer Link Active Reporting Capable
    #define CND003_BUSXP1_D1D7F0_RLCASDERC    BIT19                   // 1b/1/x/x Surprise Down Error Reporting Capable
    #define CND003_BUSXP1_D1D7F0_RLCACPM      BIT18                   // 0/0/x/x Clock Power Management
    #define CND003_BUSXP1_D1D7F0_LKL1EL       (BIT15 + BIT16 + BIT17) // HwInit/x/x/x L1 Exit Latency
    #define CND003_BUSXP1_D1D7F0_LKL0SE       (BIT12 + BIT13 + BIT14) // HwInit/x/x/x L0s Exit Latency
    #define CND003_BUSXP1_D1D7F0_LKAPMS       (BIT10 + BIT11)         // 11b/11/x/x Active State Link PM (ASPM) Support
    #define CND003_BUSXP1_D1D7F0_LKMLW_5      BIT9                    // 0/0/x/x Maximum Link Width Bit 5
    #define CND003_BUSXP1_D1D7F0_LKMLW_4      BIT8                    // 0/0/x/x Maximum Link Width Bit 4
    #define CND003_BUSXP1_D1D7F0_LKMLW_3      BIT7                    // 0/0/x/x Maximum Link Width Bit 3
    #define CND003_BUSXP1_D1D7F0_LKMLW_2      BIT6                    // HwInit/x/x/x Maximum Link Width Bit 2
    #define CND003_BUSXP1_D1D7F0_LKMLW_1      BIT5                    // HwInit/x/x/x Maximum Link Width Bit 1
    #define CND003_BUSXP1_D1D7F0_LKMLW_0      BIT4                    // HwInit/x/x/x Maximum Link Width Bit 0
    #define CND003_BUSXP1_D1D7F0_LKMAXLS_3    BIT3                    // 0/0/x/x Max Link Speed Bit 3 
    #define CND003_BUSXP1_D1D7F0_LKMAXLS_2    BIT2                    // 0/0/x/x Max Link Speed Bit 2  
    #define CND003_BUSXP1_D1D7F0_LKMAXLS_1    BIT1                    // HwInit/x/x/x Max Link Speed Bit 1
    #define CND003_BUSXP1_D1D7F0_LKMAXLS_0    BIT0                    // HwInit/x/x/x Max Link Speed Bit 0
#define CND003_BUSXP1_D1D7F0_LINK_CTL_1 0x50 // Link Control 1
    #define CND003_BUSXP1_D1D7F0_RSV_32       0xF000          // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLABITEN     BIT11           // 0/0/x/x Enable Link Autonom ous Bandwidth Interrupt
    #define CND003_BUSXP1_D1D7F0_RLBMITEN     BIT10           // 0/0/x/x Enable Link Bandwidth Management Interrupt
    #define CND003_BUSXP1_D1D7F0_RHATNMWD     BIT9            // 0/0/x/0 Hardware Autonomous Width Control
    #define CND003_BUSXP1_D1D7F0_RLCOCPMEN    BIT8            // 0/R/x/x Enable Clock Power Management
    #define CND003_BUSXP1_D1D7F0_LCES         BIT7            // 0/0/0/x Extended Synch
    #define CND003_BUSXP1_D1D7F0_LCCCC        BIT6            // 0/0/x/x Common Clock Configuration
    #define CND003_BUSXP1_D1D7F0_LCRL         BIT5            // 0/0/x/x Retrain Link
    #define CND003_BUSXP1_D1D7F0_LCLD         BIT4            // 0/0/x/x Link Disable
    #define CND003_BUSXP1_D1D7F0_LCRCB        BIT3            // 0/0/x/x Read Completion Boundary
    #define CND003_BUSXP1_D1D7F0_RSV_33       BIT2            // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_LCAPMS       (BIT0 + BIT1)   // 00b/00*/00*/11* Link Active State PM (ASPM) Control
#define CND003_BUSXP1_D1D7F0_LINK_STA_1 0x52 // Link Status 1
    #define CND003_BUSXP1_D1D7F0_RLATNMBW     BIT15   // 0/0/x/x Link Autonomous Bandwidth Status
    #define CND003_BUSXP1_D1D7F0_RLBWMNGT     BIT14   // 0/0/x/x Link Bandwidth Management Status
    #define CND003_BUSXP1_D1D7F0_DL_ACTIVE    BIT13   // HwInit/x/x/x Data Link Layer Link Active
    #define CND003_BUSXP1_D1D7F0_LSSCC        BIT12   // 1b/x/x/x Slot Clock Configuration
    #define CND003_BUSXP1_D1D7F0_LSLT         BIT11   // HwInit/x/x/x Link Training
    #define CND003_BUSXP1_D1D7F0_LSTE         BIT10   // HwInit/x/x/x Training Error
    #define CND003_BUSXP1_D1D7F0_TBD_28       BIT9    // 0/R/x/x Negotiated Link Width Bit 5
    #define CND003_BUSXP1_D1D7F0_LSNLW        0x1F0   // HwInit/x/x/x Negotiated Link Width Bits[4:0]
    #define CND003_BUSXP1_D1D7F0_LSLS         0xF     // HwInit/x/x/x Current Link Speed
#define CND003_BUSXP1_D1D7F0_SLOT_CAPS_1 0x54 // Slot Capabilities 1
    #define CND003_BUSXP1_D1D7F0_SLPSN    0xFFF80000      // 0/0/x/x Physical Slot Number; Reserved
    #define CND003_BUSXP1_D1D7F0_RSCANCCS BIT18           // 0/0/x/x No Command Completed Support
    #define CND003_BUSXP1_D1D7F0_RSCAEMIP BIT17           // 0/0/x/x Electromechanical Interlock Present
    #define CND003_BUSXP1_D1D7F0_RSPLS    (BIT15 + BIT16) // 0/0/x/x Slot Power Limit Scale
    #define CND003_BUSXP1_D1D7F0_RSPLV    0x7F80          // 0/0/x/x Slot Power Limit Value
    #define CND003_BUSXP1_D1D7F0_SCHP_CAP BIT6            // 0/0/x/x Hot-Plug Capable
    #define CND003_BUSXP1_D1D7F0_SCHPS    BIT5            // 1b/1/x/x Hot-Plug Surprise
    #define CND003_BUSXP1_D1D7F0_SCPIP    BIT4            // 0/0/x/x Power Indicator Present
    #define CND003_BUSXP1_D1D7F0_SCAIP    BIT3            // 0/0/x/x Attention Indicator Present
    #define CND003_BUSXP1_D1D7F0_RSV_36   BIT2            // 0/R/x/x MRL Sensor Present
    #define CND003_BUSXP1_D1D7F0_RSV_37   BIT1            // 0/R/x/x Power Controller Present
    #define CND003_BUSXP1_D1D7F0_SCABP    BIT0            // 0/0/x/x Attention Button Present
#define CND003_BUSXP1_D1D7F0_SLOT_CTL_1 0x58 // Slot Control 1
    #define CND003_BUSXP1_D1D7F0_RSV_39       (BIT13 + BIT14 + BIT15) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDLSCHGEN    BIT12                   // 0/0/x/x Enable Data Link Layer State Change
    #define CND003_BUSXP1_D1D7F0_RSCOEMIC     BIT11                   // 0/R/x/x Electromechanical Interlock Control
    #define CND003_BUSXP1_D1D7F0_SCPCC        BIT10                   // 0/0/x/x Power Controller Control
    #define CND003_BUSXP1_D1D7F0_SCPIC        (BIT8 + BIT9)           // 00b/0/x/x Power Indicator Control
    #define CND003_BUSXP1_D1D7F0_SCAIC        (BIT6 + BIT7)           // 00b/0/x/x Attention Indicator Control
    #define CND003_BUSXP1_D1D7F0_SCHPIE       BIT5                    // 0/0/x/x Enable Hot-Plug Interrupt
    #define CND003_BUSXP1_D1D7F0_SCCCIE       BIT4                    // 0/0/x/x Enable Command Completed Interrupt 
    #define CND003_BUSXP1_D1D7F0_SCPDCE       BIT3                    // 0/0/x/x Enable Presence Detect Change
    #define CND003_BUSXP1_D1D7F0_RSV_40       BIT2                    // 0/R/x/x Enable MRL Sensor Change
    #define CND003_BUSXP1_D1D7F0_RSV_41       BIT1                    // 0/R/x/x Enable Power Fault Detected
    #define CND003_BUSXP1_D1D7F0_SCABPE       BIT0                    // 0/0/x/x Enable Attention Button Pressed
#define CND003_BUSXP1_D1D7F0_SLOT_STA_1 0x5A // Slot Status 1
    #define CND003_BUSXP1_D1D7F0_RSV_42   0xFE00  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDLSCHG  BIT8    // 0/0/x/x Data Link Layer State Changed
    #define CND003_BUSXP1_D1D7F0_RSSEMIS  BIT7    // 0/R/x/x Electromechanical Interlock Status
    #define CND003_BUSXP1_D1D7F0_SPDCST   BIT6    // HwInit/x/x/x Presence Detect State
    #define CND003_BUSXP1_D1D7F0_RSV_43   BIT5    // 0/R/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define CND003_BUSXP1_D1D7F0_SSCC     BIT4    // 0/0/x/x Command Completed
    #define CND003_BUSXP1_D1D7F0_SPDC     BIT3    // 0/0/x/x Presence Detect Change
    #define CND003_BUSXP1_D1D7F0_TBD_29   BIT2    // 0/R/x/x MRL Sensor Change
    #define CND003_BUSXP1_D1D7F0_TBD_30   BIT1    // 0/R/x/x Power Fault Detected
    #define CND003_BUSXP1_D1D7F0_SSABP    BIT0    // 0/0/x/x Attention Button Pressed
#define CND003_BUSXP1_D1D7F0_ROOT_CTL 0x5C // Root Control
    #define CND003_BUSXP1_D1D7F0_RSV_5C_5 0xFFE0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCCRSSVE BIT4    // 0/0/x/x Enable CRS Software Visibility 
    #define CND003_BUSXP1_D1D7F0_RCPMEIE  BIT3    // 0/0/x/x Enable PME Interrupt
    #define CND003_BUSXP1_D1D7F0_RCSEFEE  BIT2    // 0/0/x/x Enable System Error on Fatal Error
    #define CND003_BUSXP1_D1D7F0_RCSENFEE BIT1    // 0/0/x/x Enable System Error on Non-Fatal Error
    #define CND003_BUSXP1_D1D7F0_RCSECEE  BIT0    // 0/0/x/x Enable System Error on Correctable Error
#define CND003_BUSXP1_D1D7F0_ROOT_CAPS 0x5E // Root Capabilities
    #define CND003_BUSXP1_D1D7F0_RSV_44_5E    0xFFFE  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSCRSSFV     BIT0    // 0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define CND003_BUSXP1_D1D7F0_ROOT_STA 0x60 // Root Status
    #define CND003_BUSXP1_D1D7F0_RSV_45   0xFFFC0000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSPP     BIT17       // HwInit/x/x/x PME Pending
    #define CND003_BUSXP1_D1D7F0_RSPS     BIT16       // 0/0/x/x PME Status
    #define CND003_BUSXP1_D1D7F0_RSV_60   0xFFFF      // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_DEV_CAPS_2 0x64 // Device Capabilities 2
    #define CND003_BUSXP1_D1D7F0_RSV_64_6     0xFFF00000      // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_ROBFFSP      (BIT18 + BIT19) // 01b/01b/x/x OBFF Supported
    #define CND003_BUSXP1_D1D7F0_RSV_64_12    0x3F000         // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLTRSP       BIT11           // 1b/1b/x/x LTR Mechanism Supported
    #define CND003_BUSXP1_D1D7F0_RSV_64_10    0x7C0           // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RARISP       BIT5            // 0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define CND003_BUSXP1_D1D7F0_TBD_31       BIT4            // 0/0/x/x Completion Timeout Disable Supported
    #define CND003_BUSXP1_D1D7F0_TBD_32       0xF             // 0/R/x/x Completion Timeout Ranges Supported
#define CND003_BUSXP1_D1D7F0_DEV_CTL_2 0x68 // Device Control 2
    #define CND003_BUSXP1_D1D7F0_RSV_46       BIT15           // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_ROBFFEN      (BIT13 + BIT14) // 0/0/x/x OBFF Enable
    #define CND003_BUSXP1_D1D7F0_RSV_68_11    (BIT11 + BIT12) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLTREN       BIT10           // 0/0/x/x LTR Mechanism Enable
    #define CND003_BUSXP1_D1D7F0_RSV_68_6     0x3C0           // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RARIEN       BIT5            // 0/0/x/x Enable ARI Forwarding
    #define CND003_BUSXP1_D1D7F0_RDISCPLTM    BIT4            // 0/0/0/x Completion Timeout Disable Control
    #define CND003_BUSXP1_D1D7F0_TBD_33       0xF             // 0/R/x/x Completion Timeout Value
#define CND003_BUSXP1_D1D7F0_DEV_STA_2 0x6A // Device Status 2
    #define CND003_BUSXP1_D1D7F0_RSV_47 D1D7F0_DEV_STA_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_LINK_CAPS_2_D1F0 0x6C // Link Capabilities 2 (D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_6C_31                0xFFF80000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_REC_SUPPORT_2   BIT18       // 0/0/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_REC_SUPPORT_1   BIT17       // HwInit/x/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_REC_SUPPORT_0   BIT16       // 1b/1b/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_BUSXP1_D1D7F0_RSV_6C_15                0xF000      // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_GEN_SUPPORT_2   BIT11       // 0/0/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_GEN_SUPPORT_1   BIT10       // HwInit/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_GEN_SUPPORT_0   BIT9        // 1b/1b/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_BUSXP1_D1D7F0_RSV_6C_8                 BIT8        // 0/R/x/x CrossLink Supported
    #define CND003_BUSXP1_D1D7F0_LKMLS_6                  BIT7        // 0b/R/x/x Supported Link Speed Vector Bit 6
    #define CND003_BUSXP1_D1D7F0_LKMLS_5                  BIT6        // 0b/R/x/x Supported Link Speed Vector Bit 5
    #define CND003_BUSXP1_D1D7F0_LKMLS_4                  BIT5        // 0b/R/x/x Supported Link Speed Vector Bit 4
    #define CND003_BUSXP1_D1D7F0_LKMLS_3                  BIT4        // 0b/R/x/x Supported Link Speed Vector Bit 3
    #define CND003_BUSXP1_D1D7F0_LKMLS_2                  BIT3        // 0b/0b/x/x Supported Link Speed Vector Bit 2, 8.0GT/s 
    #define CND003_BUSXP1_D1D7F0_LKMLS_1                  BIT2        // HwInit/x/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define CND003_BUSXP1_D1D7F0_LKMLS_0                  BIT1        // 1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s 
    #define CND003_BUSXP1_D1D7F0_RSV_6C_0                 BIT0        // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_LINK_CTL_2_D1F0 0x70 // Link Control 2 (D1F0)
    #define CND003_BUSXP1_D1D7F0_CMPPSDEEMPHS 0xF000  // 0/0/x/x Compliance Preset / De-emphasis
    #define CND003_BUSXP1_D1D7F0_RCMPSOS      BIT11   // 0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define CND003_BUSXP1_D1D7F0_PMDCMPSET    BIT10   // 0/0/x/x Modified Compliance Pattern Set Bit
    #define CND003_BUSXP1_D1D7F0_TXMGN_2      BIT9    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSXP1_D1D7F0_TXMGN_1      BIT8    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSXP1_D1D7F0_TXMGN_0      BIT7    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSXP1_D1D7F0_SELDEEMPHS   BIT6    // 0/*0/x/x Selectable De-emphasis
    #define CND003_BUSXP1_D1D7F0_RHATNMSD     BIT5    // 0/0/x/x Disable Hardware Autonomous Speed
    #define CND003_BUSXP1_D1D7F0_PCMPSET      BIT4    // 0/0/x/x Enter Compliance
    #define CND003_BUSXP1_D1D7F0_LKTGLS_3     BIT3    // 0/0/0/0 Target Link Speed Bit 3
    #define CND003_BUSXP1_D1D7F0_LKTGLS_2     BIT2    // 0/0/0/0 Target Link Speed Bit 2
    #define CND003_BUSXP1_D1D7F0_LKTGLS_1     BIT1    // HwInit/x/1/0 Target Link Speed Bit 1
    #define CND003_BUSXP1_D1D7F0_LKTGLS_0     BIT0    // HwInit/x/0/0 Target Link Speed Bit 0
#define CND003_BUSXP1_D1D7F0_LINK_STA_2 0x72 // Link Status 2
    #define CND003_BUSXP1_D1D7F0_RSV_49       0xFFC0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EQREQ        BIT5    // 0/0/x/x Request the Link Equalization Process
    #define CND003_BUSXP1_D1D7F0_EQCOMPLE3    BIT4    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define CND003_BUSXP1_D1D7F0_EQCOMPLE2    BIT3    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define CND003_BUSXP1_D1D7F0_EQCOMPLE1    BIT2    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define CND003_BUSXP1_D1D7F0_EQCOMPLE     BIT1    // 0/0/x/x Transmitter Equalization Procedure Completed
    #define CND003_BUSXP1_D1D7F0_CURDEEMPHS   BIT0    // 0/0/x/x Current Link De-emphasis Level
#define CND003_BUSXP1_D1D7F0_SLOT_CAPS_2 0x74 // Slot Capabilities 2
    #define CND003_BUSXP1_D1D7F0_RSV_50 D1D7F0_SLOT_CAPS_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_SLOT_CTL_2 0x78 // Slot Control 2
    #define CND003_BUSXP1_D1D7F0_RSV_51 D1D7F0_SLOT_CTL_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_SLOT_STA_2 0x7A // Slot Status 2
    #define CND003_BUSXP1_D1D7F0_RSV_52 D1D7F0_SLOT_STA_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0 0x7C // Vendor Control (D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_7C       0xFFFFFFFC  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_DID_RID_LOCK BIT1        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VID_LOCK     BIT0        // HwInit/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_PM_CAPS 0xA0 // Power Management Capabilities
    #define CND003_BUSXP1_D1D7F0_PMCPME   0xF8000000              // 11001b/19h/x/x PME Support
    #define CND003_BUSXP1_D1D7F0_PMCD2S   BIT26                   // 0/0/x/x D2 Support
    #define CND003_BUSXP1_D1D7F0_PMCD1S   BIT25                   // 0/0/x/x D1 Support
    #define CND003_BUSXP1_D1D7F0_PMCAUXC  (BIT22 + BIT23 + BIT24) // 0/0/x/x AUX Current
    #define CND003_BUSXP1_D1D7F0_PMCDSI   BIT21                   // 1b/1/x/x Device Specific Initialization
    #define CND003_BUSXP1_D1D7F0_RSV_53   (BIT19 + BIT20)         // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_34   (BIT16 + BIT17 + BIT18) // 011b/R/x/x Version
    #define CND003_BUSXP1_D1D7F0_TBD_35   0xFF00                  // B0h/R/x/x Next Capability Pointer
    #define CND003_BUSXP1_D1D7F0_TBD_36   0xFF                    // 01h/R/x/x Capability ID
#define CND003_BUSXP1_D1D7F0_PM_STA_CTL 0xA4 // Power Management Status / Control
    #define CND003_BUSXP1_D1D7F0_TBD_37       0xFF000000      // 0/R/x/x Power Management Data
    #define CND003_BUSXP1_D1D7F0_TBD_38       BIT23           // 0/x/x/x Enable Bus Power / Clock Control
    #define CND003_BUSXP1_D1D7F0_TBD_39       BIT22           // 0/x/x/x B2 / B3 Support
    #define CND003_BUSXP1_D1D7F0_RSV_54       0x3F0000        // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PMESD        BIT15           // 0/0/x/x PME Status
    #define CND003_BUSXP1_D1D7F0_TBD_40       (BIT13 + BIT14) // 0/R/x/x Data Scale
    #define CND003_BUSXP1_D1D7F0_TBD_41       0x1E00          // 0/R/x/x Data Select
    #define CND003_BUSXP1_D1D7F0_PMEEN        BIT8            // 0/0/x/x PME Enable
    #define CND003_BUSXP1_D1D7F0_RSV_55       0xF0            // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_NOSOFTRST    BIT3            // 1b/1b/x/x No_Soft_Reset
    #define CND003_BUSXP1_D1D7F0_RSV_55_2     BIT2            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PWSD         (BIT0 + BIT1)   // 00b/0/x/x Power State
#define CND003_BUSXP1_D1D7F0_MSI_CAP_SUPPORT 0xB0 // MSI Capability Support
    #define CND003_BUSXP1_D1D7F0_RSV_56   0xFE000000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_42   BIT24                   // 1b/1/x/x Supports Per-vector Masking Capability
    #define CND003_BUSXP1_D1D7F0_TBD_43   BIT23                   // 1b/1/x/x Supports 64-bit Message Address Only
    #define CND003_BUSXP1_D1D7F0_RMSINUM  (BIT20 + BIT21 + BIT22) // 000b/0/x/x Multiple Message Enable
    #define CND003_BUSXP1_D1D7F0_RMSICAP  (BIT17 + BIT18 + BIT19) // 011b/011b/x/x Multiple Message Capable 
    #define CND003_BUSXP1_D1D7F0_RMSIEN   BIT16                   // 0/0/x/x MSI Enable
    #define CND003_BUSXP1_D1D7F0_TBD_44   0xFF00                  // E0h/R/x/x Next Capability Pointer
    #define CND003_BUSXP1_D1D7F0_TBD_45   0xFF                    // 05h/R/x/x Capability ID
#define CND003_BUSXP1_D1D7F0_SYS_SPECIFIED_MSG_ADR_LOW 0xB4 // System-specified Message Address  Low
    #define CND003_BUSXP1_D1D7F0_RMSIA_31_2   0xFFFFFFFC      // 0/0/x/x System-specified Message Address Bit [31:2]
    #define CND003_BUSXP1_D1D7F0_TBD_46       (BIT0 + BIT1)   // 0/R/x/x System-specified Message Address Bit [1:0]
#define CND003_BUSXP1_D1D7F0_SYS_SPECIFIED_MSG_ADR_HIGH 0xB8 // System-specified Message Address High
    #define CND003_BUSXP1_D1D7F0_RMSIA_63_32 D1D7F0_SYS_SPECIFIED_MSG_ADR_HIGH // 0/0/x/x System-specified Message Address Bit [63:32]
#define CND003_BUSXP1_D1D7F0_MSG_DATA 0xBC // Message Data
    #define CND003_BUSXP1_D1D7F0_RMSID D1D7F0_MSG_DATA // 0/0/x/x Message Data
#define CND003_BUSXP1_D1D7F0_RESERVED_Z1 0xBE // Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_BFBE D1D7F0_RESERVED_Z1 // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_MSG_MASK_CTL 0xC0 // Message Mask Control
    #define CND003_BUSXP1_D1D7F0_RSV_57               0xFFFFFF00  // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_NONFATALERR  BIT7        // 0/0/x/x Mask Bit for Non-Fatal Error
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_FATALERR     BIT6        // 0/0/x/x Mask Bit for Fatal Error
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_CORERR       BIT5        // 0/0/x/x Mask Bit fo Correctable Error
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_DLSCHG       BIT4        // 0/0/x/x Mask Bit for DL State Change
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_CMDCPL       BIT3        // 0/0/x/x Mask Bit for Command Complete
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_PREDET       BIT2        // 0/0/x/x Mask Bit for Present Detect
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_ATTBTNPRESS  BIT1        // 0/0/x/x Mask Bit for ATTENTION Button Pressed
    #define CND003_BUSXP1_D1D7F0_RMSIMSK_LKBWCHG      BIT0        // 0/0/x/x Mask Bit for LKBWCHG
#define CND003_BUSXP1_D1D7F0_MSG_PENDING_STA 0xC4 // Message Pending Status
    #define CND003_BUSXP1_D1D7F0_RSV_58           0xFFFFFF00  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RMSI_NONFATALERR BIT7        // HwInit/x/x/x Pending Bit for NonFatal Error
    #define CND003_BUSXP1_D1D7F0_RMSI_FATALERR    BIT6        // HwInit/x/x/x Pending Bit for Fatal Error
    #define CND003_BUSXP1_D1D7F0_RMSI_CORERR      BIT5        // HwInit/x/x/x Pending Bit for Correctable Error
    #define CND003_BUSXP1_D1D7F0_RMSI_DLSCHG      BIT4        // HwInit/x/x/x Pending Bit for DL State Change
    #define CND003_BUSXP1_D1D7F0_RMSI_CMDCPL      BIT3        // HwInit/x/x/x Pending Bit for Command Complete
    #define CND003_BUSXP1_D1D7F0_RMSI_PREDET      BIT2        // HwInit/x/x/x Pending Bit for Present Detect
    #define CND003_BUSXP1_D1D7F0_RMSI_ATTBTNPRESS BIT1        // HwInit/x/x/x Pending Bit for Attention Button Pressed
    #define CND003_BUSXP1_D1D7F0_RMSI_LKBWCHG     BIT0        // HwInit/x/x/x Pending Bit for LKBWCHG
#define CND003_BUSXP1_D1D7F0_PRIMARY_BAR_SIZE 0xD0 // Primary BAR Size
    #define CND003_BUSXP1_D1D7F0_RSV_D3 D1D7F0_PRIMARY_BAR_SIZE // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_RESERVED_Z2 0xD4 // Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_D5 D1D7F0_RESERVED_Z2 // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_NEXT_PTR 0xE0 // Next Pointer
    #define CND003_BUSXP1_D1D7F0_TBD_47   0xFF00  // 0/R/x/x Next Pointer
    #define CND003_BUSXP1_D1D7F0_TBD_48   0xFF    // 0Dh/R/x/x Capability ID
#define CND003_BUSXP1_D1D7F0_RESERVED_Z3 0xE2 // Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_47_1 D1D7F0_RESERVED_Z3 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_SVID_CTL 0xE4 // Subsystem Vendor ID Control
    #define CND003_BUSXP1_D1D7F0_TBD_49 D1D7F0_SVID_CTL // 1106h/1106h/x/x Subsystem Vendor ID
#define CND003_BUSXP1_D1D7F0_SSID_CTL_D1F0 0xE6 // Subsystem ID Control (D1F0)
    #define CND003_BUSXP1_D1D7F0_TBD_50G D1D7F0_SSID_CTL_D1F0 // 0710h/0710h/x/X Subsystem ID
#define CND003_BUSXP1_D1D7F0_ADVANCED_ERR_REPORTING_ENHANCED_CAP_HDR 0x100 // Advanced Error Reporting Enhanced Capability Header
    #define CND003_BUSXP1_D1D7F0_TBD_54   0xFFF00000  // 140h/R/x/x Next Capability Offset
    #define CND003_BUSXP1_D1D7F0_TBD_55   0xF0000     // 1h/R/x/x Capability Version
    #define CND003_BUSXP1_D1D7F0_TBD_56   0xFFFF      // 0001h/R/x/x PCI Express Extended Capability ID
#define CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA 0x104 // Uncorrectable Error Status
    #define CND003_BUSXP1_D1D7F0_RSV_59       0xFFC00000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_UEACSVIO     BIT21                   // 0/R/x/x ACS Violation Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESUR        BIT20                   // 0/0/x/x Unsupported Request Error Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESECRC      BIT19                   // 0/0/x/x ECRC Error Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESMTLP      BIT18                   // 0/0/x/x Malformed TLP Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESRO        BIT17                   // 0/0/x/x Receiver Overflow Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESUC        BIT16                   // 0/0/x/x Unexpected Completion Status (TL) *
    #define CND003_BUSXP1_D1D7F0_UESCA        BIT15                   // 0/0/x/x Completer Abort Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESCT        BIT14                   // 0/0/x/x Completion Timeout Status (TL) *
    #define CND003_BUSXP1_D1D7F0_UESFCP       BIT13                   // 0/0/x/x Flow Control Protocol Error Status (TL)
    #define CND003_BUSXP1_D1D7F0_UESPTLP      BIT12                   // 0/0/x/x Poisoned TLP Status (TL) *
    #define CND003_BUSXP1_D1D7F0_RSV_60_Z1    0xFC0                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RUESSDES     BIT5                    // 0/0/x/x Surprise Down Error Status
    #define CND003_BUSXP1_D1D7F0_UESDLP       BIT4                    // 0/0/x/x Data Link Protocol Error Status (DLL)
    #define CND003_BUSXP1_D1D7F0_RSV_61       (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_UEST         BIT0                    // 0/0/x/x Training Error Status (PHY)
#define CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_MASK 0x108 // Uncorrectable Error Mask
    #define CND003_BUSXP1_D1D7F0_RSV_1100     0xFFC00000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_UEMACSVIO    BIT21                   // 0/R/x/x ACS Violation Mask (TL)
    #define CND003_BUSXP1_D1D7F0_UEMUR        BIT20                   // 0/0/x/x Unsupported Request Error Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_UEMECRC      BIT19                   // 0/0/x/x ECRC Error Mask (TL)
    #define CND003_BUSXP1_D1D7F0_UEMMTLP      BIT18                   // 0/0/x/x Malformed TLP Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_UEMRO        BIT17                   // 0/0/x/x Receiver Overflow Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_UEMUC        BIT16                   // 0/0/x/x Unexpected Completion Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_UEMCA        BIT15                   // 0/0/x/x Completed Abort Mask (TL)
    #define CND003_BUSXP1_D1D7F0_UEMCT        BIT14                   // 0/0/x/x Completion Timeout Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_UEMFCP       BIT13                   // 0/0/x/x Flow Control Protocol Error Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_UEMPTLP      BIT12                   // 0/0/x/x Poisoned TLP Mask (TL) *
    #define CND003_BUSXP1_D1D7F0_RSV_1101     0xFC0                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RUEMSDEM     BIT5                    // 0/0/x/x Surprise Down Error Mask (DLL) *
    #define CND003_BUSXP1_D1D7F0_UEMDLP       BIT4                    // 0/0/x/x Data Link Protocol Error Mask (DLL) *
    #define CND003_BUSXP1_D1D7F0_RSV_62       (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_UEMST        BIT0                    // 0/0/x/x Training Error Mask (PHY) *
#define CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_SEVERITY 0x10C // Uncorrectable Error Severity
    #define CND003_BUSXP1_D1D7F0_RSV_63       0xFFC00000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_USVACSVIO    BIT21                   // 0/R/x/x ACS Violation Severity (TL)
    #define CND003_BUSXP1_D1D7F0_USVUR        BIT20                   // 0/0/x/x Unsupported Request Error Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_USVECRC      BIT19                   // 0/0/x/x ECRC Error Severity (TL)
    #define CND003_BUSXP1_D1D7F0_USVMTLP      BIT18                   // 1b/1/x/x Malformed TLP Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_USVRO        BIT17                   // 1b/1/x/x Receiver Overflow Error Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_USVUC        BIT16                   // 0/0/x/x Unexpected Completion Error Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_USVCA        BIT15                   // 0/0/x/x Completed Abort Error Severity (TL)
    #define CND003_BUSXP1_D1D7F0_USVCT        BIT14                   // 0/0/x/x Completion Timeout Error Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_USVFCP       BIT13                   // 1b/1/x/x Flow Control Protocol Error Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_USVPTLP      BIT12                   // 0/0/x/x Poisoned TLP Severity (TL) *
    #define CND003_BUSXP1_D1D7F0_RSV_64       0xFC0                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RUSVSDES     BIT5                    // 1b/1/x/x Surprise Down Error Severity *
    #define CND003_BUSXP1_D1D7F0_USVDLP       BIT4                    // 1b/1/x/x Data Link Protocol Error Severity (DLL) *
    #define CND003_BUSXP1_D1D7F0_RSV_65       (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_USVT         BIT0                    // 1b/1/x/x Training Error Severity (PHY) *
#define CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA 0x110 // Correctable Error Status
    #define CND003_BUSXP1_D1D7F0_RSV_66       0xFFFFC000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCESANFES    BIT13                   // 0/0/x/x Advisory Non-Fatal Error Status
    #define CND003_BUSXP1_D1D7F0_CRRTT        BIT12                   // 0/0/x/x Replay Timer Timeout Status (DLL)
    #define CND003_BUSXP1_D1D7F0_RSV_67       (BIT9 + BIT10 + BIT11)  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_CRRR         BIT8                    // 0/0/x/x REPLAY_NUM Rollover Status (DLL)
    #define CND003_BUSXP1_D1D7F0_CRBDLLP      BIT7                    // 0/0/x/x Bad Data Link Layer Packet (DLLP) Status (DLL)
    #define CND003_BUSXP1_D1D7F0_CRBTLP       BIT6                    // 0/0/x/x Bad TLP Status (DLL)
    #define CND003_BUSXP1_D1D7F0_RSV_68       0x3E                    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_CRRCVR       BIT0                    // 0/0/x/x Receiver Error Status (PHY)
#define CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_MASK 0x114 // Correctable Error Mask
    #define CND003_BUSXP1_D1D7F0_RSV_69       0xFFFFC000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCEMANFEM    BIT13                   // 1b/1/x/x Advisory Non-Fatal Error Mask *
    #define CND003_BUSXP1_D1D7F0_CMRTT        BIT12                   // 0/0/x/x Replay Timer Timeout Mask (DLL) *
    #define CND003_BUSXP1_D1D7F0_RSV_70       (BIT9 + BIT10 + BIT11)  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_CMRR         BIT8                    // 0/0/x/x REPLAY_NUM Rollover Mask (DLL) *
    #define CND003_BUSXP1_D1D7F0_CMBDLLP      BIT7                    // 0/0/x/x Bad DLLP Mask (DLL) *
    #define CND003_BUSXP1_D1D7F0_CMBTLP       BIT6                    // 0/0/x/x Bad TLP Mask (DLL) *
    #define CND003_BUSXP1_D1D7F0_RSV_71       0x3E                    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_CMRCVR       BIT0                    // 0/0/x/x Receiver Error Mask (PHY) *
#define CND003_BUSXP1_D1D7F0_ADVANCED_ERR_CAPS_AND_CTL 0x118 // Advanced Error Capabilities and Control
    #define CND003_BUSXP1_D1D7F0_RSV_72       0xFFFFFE00  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_ECRCCHKEN    BIT8        // 0/0/x/x ECRC Check Enable (TL)
    #define CND003_BUSXP1_D1D7F0_ECRCCHKCA    BIT7        // 0/R/x/x ECRC Check Capable (TL)
    #define CND003_BUSXP1_D1D7F0_ECRCGENEN    BIT6        // 0/0/x/x ECRC Generation Enable (TL)
    #define CND003_BUSXP1_D1D7F0_ECRCGENCA    BIT5        // 0/R/x/x ECRC Generation Capable (TL)
    #define CND003_BUSXP1_D1D7F0_ECRCFEPTR    0x1F        // 0/0/x/x First Error Pointer (TL)
#define CND003_BUSXP1_D1D7F0_HDR_LOG_1ST_DW 0x11C // Header Log 1st DW
    #define CND003_BUSXP1_D1D7F0_HLR1 D1D7F0_HDR_LOG_1ST_DW // 0/R/x/x Header Log Register 1st DW
#define CND003_BUSXP1_D1D7F0_HDR_LOG_2ND_DW 0x120 // Header Log 2nd DW
    #define CND003_BUSXP1_D1D7F0_HLR2 D1D7F0_HDR_LOG_2ND_DW // 0/R/x/x Header Log Register 2nd DW
#define CND003_BUSXP1_D1D7F0_HDR_LOG_3RD_DW 0x124 // Header Log 3rd DW
    #define CND003_BUSXP1_D1D7F0_HLR3 D1D7F0_HDR_LOG_3RD_DW // 0/R/x/x Header Log Register 3rd DW
#define CND003_BUSXP1_D1D7F0_HDR_LOG_4TH_DW 0x128 // Header Log 4th DW
    #define CND003_BUSXP1_D1D7F0_HLR4 D1D7F0_HDR_LOG_4TH_DW // 0/R/x/x Header Log Register 4th DW
#define CND003_BUSXP1_D1D7F0_ROOT_ERR_CMD_RESERVED 0x12C // Root Error Command : Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_73   0xFFFFFFF8  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RECF     BIT2        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RECNF    BIT1        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RECC     BIT0        // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_ROOT_ERR_STA_RESERVED 0x130 // Root Error Status : Reserved
    #define CND003_BUSXP1_D1D7F0_RESAEIMN 0xF8000000  // 0/x/x/x Advanced Error Interrupt Message Number (TL)
    #define CND003_BUSXP1_D1D7F0_RSV_74   0x7FFFF80   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESFRV   BIT6        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESNFRV  BIT5        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESFFRV  BIT4        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESMF    BIT3        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESSF    BIT2        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESMC    BIT1        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RESSC    BIT0        // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_ERR_SRC_IDENTIFICATION 0x134 // Error Source Identification
    #define CND003_BUSXP1_D1D7F0_ESIF 0xFFFF0000  // 0/R/x/x ERR_FATAL / NONFATAL Source Identification (TL)
    #define CND003_BUSXP1_D1D7F0_ESIC 0xFFFF      // 0/R/x/x ERR_COR Source Identification (TL)
#define CND003_BUSXP1_D1D7F0_ERR_DLLP_LOG 0x138 // Error DLLP Log
    #define CND003_BUSXP1_D1D7F0_DL_ERR_DLLP D1D7F0_ERR_DLLP_LOG // 0/R/x/x Error DLLP Log
#define CND003_BUSXP1_D1D7F0_VIRTUAL_CHN_ENHANCED_CAP 0x140 // Virtual Channel Enhanced Capability
    #define CND003_BUSXP1_D1D7F0_RX140_31_20  0xFFF00000  // 2a0h/R/x/x Next Capability Offset
    #define CND003_BUSXP1_D1D7F0_RX140_19_16  0xF0000     // 1h/R/x/x Capability Version
    #define CND003_BUSXP1_D1D7F0_RX140_15_0   0xFFFF      // 0002h/R/x/x PCI Express Extended Capability ID
#define CND003_BUSXP1_D1D7F0_PORT_VC_CAP_1 0x144 // Port VC Capability 1
    #define CND003_BUSXP1_D1D7F0_RX144_31_12  0xFFFFF000              // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX144_11_10  (BIT10 + BIT11)         // 0/R/x/x Port Arbitration Table Entry Size
    #define CND003_BUSXP1_D1D7F0_RX144_9_8    (BIT8 + BIT9)           // 0/R/x/x Reference Clock
    #define CND003_BUSXP1_D1D7F0_RX144_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VCALPEC_2_0  (BIT4 + BIT5 + BIT6)    // 0/R/x/x Low Priority Extended VC Count
    #define CND003_BUSXP1_D1D7F0_RX144_3      BIT3                    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VCAEVCC_2_0  (BIT0 + BIT1 + BIT2)    // 0/0/x/x Extended VC Count
#define CND003_BUSXP1_D1D7F0_PORT_VC_CAP_2 0x148 // Port VC Capability 2
    #define CND003_BUSXP1_D1D7F0_RX148_31_24  0xFF000000  // 00h/R/x/x VC Arbitration Table Offset
    #define CND003_BUSXP1_D1D7F0_RX148_23_8   0xFFFF00    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX148_7_0    0xFF        // 0/R/x/x VC Arbitration Capability
#define CND003_BUSXP1_D1D7F0_PORT_VC_CTL 0x14C // Port VC Control
    #define CND003_BUSXP1_D1D7F0_RX14C_15_4   0xFFF0                  // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX14C_3_1    (BIT1 + BIT2 + BIT3)    // 0/0/x/x VC Arbitration Select
    #define CND003_BUSXP1_D1D7F0_RX14C_0      BIT0                    // 0/R/x/x Load VC Arbitration Table
#define CND003_BUSXP1_D1D7F0_PORT_VC_STA 0x14E // Port VC Status
    #define CND003_BUSXP1_D1D7F0_RX14C_31_17  0xFFFE  // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX14C_16     BIT0    // 0/R/x/x VC Arbitration Table Status
#define CND003_BUSXP1_D1D7F0_VC0_RESRC_CAP 0x150 // VC0 Resource Capability
    #define CND003_BUSXP1_D1D7F0_RX150_31_24  0xFF000000  // 00h/R/x/x Port Arbitration Table Offset (VC0)
    #define CND003_BUSXP1_D1D7F0_RX150_23     BIT23       // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VCRAMTS0_6_0 0x7F0000    // 0/R/x/x Maximum Time Slots (TL)
    #define CND003_BUSXP1_D1D7F0_VCRARST0     BIT15       // 0/R/x/x Reject Snoop Transactions
    #define CND003_BUSXP1_D1D7F0_RX150_14     BIT14       // 0/R/x/x Undefined
    #define CND003_BUSXP1_D1D7F0_RX150_13_8   0x3F00      // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX150_7_0    0xFF        // 0/R/x/x Port Arbitration Capability
#define CND003_BUSXP1_D1D7F0_VC0_RESRC_CTL 0x154 // VC0 Resource Control
    #define CND003_BUSXP1_D1D7F0_VCROEN0      BIT31                   // 1b/R/x/x VC Enable
    #define CND003_BUSXP1_D1D7F0_RX154_30_27  0x78000000              // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VCROID0_2_0  (BIT24 + BIT25 + BIT26) // 0/R/x/x VC ID
    #define CND003_BUSXP1_D1D7F0_RX154_23_20  0xF00000                // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX154_19_17  (BIT17 + BIT18 + BIT19) // 0/0/x/x Port Arbitration Select
    #define CND003_BUSXP1_D1D7F0_RX154_16     BIT16                   // 0/R/x/x Load Port Arbitration Table
    #define CND003_BUSXP1_D1D7F0_RX154_15_8   0xFF00                  // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VCROMAP0_7_1 0xFE                    // 7Fh/7Fh/7Fh/7Fh TC1/TC2/TC3/TC4/TC5/TC6/TC7 Mapping to VC0
    #define CND003_BUSXP1_D1D7F0_VCROMAP0_0   BIT0                    // 1b/R/x/x TC0 Mapping to VC0
#define CND003_BUSXP1_D1D7F0_VC0_RESRC_STA 0x158 // VC0 Resource Status
    #define CND003_BUSXP1_D1D7F0_RX158_31_18  0xFFFC0000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_VCRSNP0      BIT17       // HwInit/x/x/x VC Negotiation Pending (TL)
    #define CND003_BUSXP1_D1D7F0_RX158_16     BIT16       // 0/R/x/x Port Arbitration Table Status
    #define CND003_BUSXP1_D1D7F0_RX158_15_0   0xFFFF      // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_1 0x1A0 // Downstream Control 1
    #define CND003_BUSXP1_D1D7F0_RDNTC1       BIT7            // 0/0/x/x Downstream Cycles Have Traffic Class TC1
    #define CND003_BUSXP1_D1D7F0_RDNNS        BIT6            // 0/0/x/x Downstream Cycles Have Attribute ?No Snoop? Set
    #define CND003_BUSXP1_D1D7F0_RDNRO        BIT5            // 0/0/x/x Downstream Cycles Have Attribute ?Relaxed Ordering? Set
    #define CND003_BUSXP1_D1D7F0_RLOCK        BIT4            // 1b/1/1/1 Downstream Lock Cycle Support
    #define CND003_BUSXP1_D1D7F0_RDNRRA       BIT3            // 0/0/0/x Downstream Arbitration Scheme
    #define CND003_BUSXP1_D1D7F0_RX1A0_2_1    (BIT1 + BIT2)   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RPIPE        BIT0            // 1b/1/1/x Downstream Pipeline
#define CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_2 0x1A1 // Downstream Control 2
    #define CND003_BUSXP1_D1D7F0_RCRS         BIT7                    // 0/x/x/x Downstream Configuration Completion Status
    #define CND003_BUSXP1_D1D7F0_RX1A1_6      BIT6                    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDNCPLINFC   BIT5                    // 0/0/x/x For the Data Return of Upstream Read Requests
    #define CND003_BUSXP1_D1D7F0_RPOFFINFC    BIT4                    // 1b/1/1/x Disable Downstream PH Credit Check for PME_TURN_OFF Message
    #define CND003_BUSXP1_D1D7F0_RCPRTMTST    BIT3                    // 0/0/x/x Enable ?C2P Read Completion Timer for Vector Development Mode?
    #define CND003_BUSXP1_D1D7F0_RCPRTM       (BIT0 + BIT1 + BIT2)    // 010b/010/010/x C2P Read Completion Timeout Timer
#define CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_3 0x1A2 // Downstream Control 3
    #define CND003_BUSXP1_D1D7F0_RTRANS2TFIX  BIT7                    // 1b/1/*0/x Downstream Ordering Queue Timing Option
    #define CND003_BUSXP1_D1D7F0_RPDNARBTIM   (BIT4 + BIT5 + BIT6)    // 011b/011/011/x Waiting Time for GNT Timer in Priority Arbitration Mode
    #define CND003_BUSXP1_D1D7F0_RFASTRO      BIT3                    // 0/0/1/x Enable Fast Reorder
    #define CND003_BUSXP1_D1D7F0_RNPBLKL1     BIT2                    // 1b/1/0/0 Pending C2P NP Completion Cycle to Block L1 Entry
    #define CND003_BUSXP1_D1D7F0_RPDNARB      (BIT0 + BIT1)           // 00b/00/00/x Downstream Arbitration Parking
#define CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_4 0x1A3 // Downstream Control 4
    #define CND003_BUSXP1_D1D7F0_RRTYQSIZE_3_0    0xF0            // Fh/Fh/Fh/Fh Retry Buffer Level
    #define CND003_BUSXP1_D1D7F0_RRTYTMO          BIT3            // 1b/1/x/x Downstream Read Retry Time Out Control in DL_Down State
    #define CND003_BUSXP1_D1D7F0_RX1A3_2_1        (BIT1 + BIT2)   // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RRTYNPRD         BIT0            // 0/0/x/x Downstream Read Cycle Retry
#define CND003_BUSXP1_D1D7F0_UPSTREAM_CTL 0x1A4 // Upstream Control
    #define CND003_BUSXP1_D1D7F0_RUHIA0       BIT7    // 0/0/0/0 Upstream Address A39-A31 Forced to 0
    #define CND003_BUSXP1_D1D7F0_RRADSW4RDY   BIT6    // 1b/1/x/x Upstream Read wait till Upstream Write data send out
    #define CND003_BUSXP1_D1D7F0_RMALTLP      BIT5    // 0/0/0/x Upstream Checking Malformed TLP through ?Byte Enable Rule? and ?Over ...
    #define CND003_BUSXP1_D1D7F0_RPWFLSH      BIT4    // 1b/1/1/1 Downstream Read Wait till the Upstream Write Flushed
    #define CND003_BUSXP1_D1D7F0_RINFFC       BIT3    // 0/0/0/x Infinite Flow Control
    #define CND003_BUSXP1_D1D7F0_RPTLPUR      BIT2    // 0/0/0/0 Report Poison TLP as Uncorrectable Error
    #define CND003_BUSXP1_D1D7F0_RNSVC1       BIT1    // 0/0/1/x Reserved
    #define CND003_BUSXP1_D1D7F0_RRASW4RDY    BIT0    // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_CREDIT_ADVERTISEMENT_CTL_1_D1F0_D6F0 0x1A5 // Credit Advertisement Control 1 (D1F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_RPDCREDIT_3_0    0xF0    // Eh/Eh/Eh/x Upstream Posted (Write) Data FIFO Size and the Initial PD Credit V...
    #define CND003_BUSXP1_D1D7F0_RPHCREDIT_3_0    0xF     // Eh/Eh/Eh/x Upstream PH Header Queues Size and the Initial PH Credit
#define CND003_BUSXP1_D1D7F0_CREDIT_ADVERTISEMENT_CTL_2_D1F0_D6F0 0x1A6 // Credit Advertisement Control 2 (D1F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_RNPHCDINF        BIT7                    // 0/0/0/x Upstream Non-Posted Header Credit Infinite Mode Control
    #define CND003_BUSXP1_D1D7F0_RX1A4_22_20      (BIT4 + BIT5 + BIT6)    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RNPHCREDIT_3_0   0xF                     // Eh/Eh/Eh/x Upstream Non-Posted Request Queue Size and Initial NPH Credit Value
#define CND003_BUSXP1_D1D7F0_UPSTREAM_PERFORMANCE_CTL_1 0x1A7 // Upstream Performance Control 1
    #define CND003_BUSXP1_D1D7F0_RX1A7_7      (BIT6 + BIT7)   // 0/00/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RX1A7_5      BIT5            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RRFFPOPEARLY BIT4            // 0/x/x/x Upstream Read FIFO Entry Release Timing
    #define CND003_BUSXP1_D1D7F0_RCPLW4RDY    BIT3            // 1b/1/1/1 Downstream Read Data Wait for Previous Upstream Write Complete
    #define CND003_BUSXP1_D1D7F0_RUPINORDER   BIT2            // 1b/1/1/x No-Snoop Path Upstream Request Read and Write Orders
    #define CND003_BUSXP1_D1D7F0_RX1A7_0      (BIT0 + BIT1)   // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_COMPLETION_TIMEOUT_CTL 0x1A8 // Completion Timeout Control
    #define CND003_BUSXP1_D1D7F0_RPHYRSTMER   BIT7            // 0/0/x/x C2P Completion Timeout Method When PHY Retrains or Configures
    #define CND003_BUSXP1_D1D7F0_RX1A8_6      BIT6            // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCFGRTYTIM   (BIT4 + BIT5)   // 00b/00/00/x Downstream Configuration Retry Request Timing after Receiving CRS...
    #define CND003_BUSXP1_D1D7F0_RX1A8_3_2    (BIT2 + BIT3)   // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCFGTM       (BIT0 + BIT1)   // 01b/01/01/x Configuration Request Timeout Timer
#define CND003_BUSXP1_D1D7F0_CRS_RETRY_CTL 0x1A9 // CRS Retry Control
    #define CND003_BUSXP1_D1D7F0_RX1A9_7_1    0xFE    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RRTYCRSEN    BIT0    // 0/0/0/x Enable CRS Retry Mechanism
#define CND003_BUSXP1_D1D7F0_UPSTREAM_PERFORMANCE_CTL_2 0x1AA // Upstream Performance Control 2
    #define CND003_BUSXP1_D1D7F0_RX1AA_7      BIT7            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RPHFCUEN     BIT6            // 1b/1/x/1 UpdateFC-P Generation to The Endpoint for Upstream Write TLPs 
    #define CND003_BUSXP1_D1D7F0_RX1AA_5_4    BIT5            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RTANBYPASS   BIT4            // 1b/1/*0/x TA path enable
    #define CND003_BUSXP1_D1D7F0_RRTYQEMPNB   (BIT2 + BIT3)   // 00b/00/00/x Number of TLPs in Retry Buffer Header Queue for the Condition of ...
    #define CND003_BUSXP1_D1D7F0_RCPL2MERGE   BIT1            // 0/0/0/x The 1st and 2nd Completion Merge Control for PCI-to-CPU Read (P2CR)
    #define CND003_BUSXP1_D1D7F0_RMSI_MULV    BIT0            // 0/0/0/0 Multi-vector MSI Data Support
#define CND003_BUSXP1_D1D7F0_TRANS_BACKUP_REGS 0x1AB // TRANS Backup Registers
    #define CND003_BUSXP1_D1D7F0_RBAK_DLRXACT         BIT7    // 0/0/0/0 Backup UPECLK2X?s Behavior to Original Design in PEXC 
    #define CND003_BUSXP1_D1D7F0_RBAK_MSG_NA          BIT6    // 0/0/0/0 Bug Fixing
    #define CND003_BUSXP1_D1D7F0_RDIS_MESC_WK         BIT5    // 0/0/0/0 PCIE Wakeup C4P Control
    #define CND003_BUSXP1_D1D7F0_RUPCPL_DWPTR_RST     BIT4    // 0/0/0/0 UP CPL Backup for Link Downstream
    #define CND003_BUSXP1_D1D7F0_TRANS_RSV_REG_1_3_0  0xF     // 0/0/0/0 TRANS Reserve Registers
#define CND003_BUSXP1_D1D7F0_TRANS_RTA_PREFETCH_REGS 0x1AC // TRANS RTA PREFETCH Registers
    #define CND003_BUSXP1_D1D7F0_RX1AD_7_5    (BIT5 + BIT6 + BIT7)    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RTA_PFEN     BIT4                    // 0/0/0/0 TRANS RTA Prefetch enable Registers
    #define CND003_BUSXP1_D1D7F0_RTA_PFCNT    (BIT2 + BIT3)           // 0/0/0/0 TRANS RTA PFTCNT Registers
    #define CND003_BUSXP1_D1D7F0_RTA_PFTRIG   (BIT0 + BIT1)           // 0/0/0/0 TRANS RTA PFTRIG Registers
#define CND003_BUSXP1_D1D7F0_CREDIT_ADVERTISEMENT_CTL_3 0x1AD // Credit Advertisement Control 3
    #define CND003_BUSXP1_D1D7F0_RCPLDCREDIT_3_0  0xF0    // 6h/6h/6h/x Upstream Completion Data FIFO Size and the Initial CplD Credit Value
    #define CND003_BUSXP1_D1D7F0_RCPLHCREDIT_3_0  0xF     // 2h/2h/2h/x Upstream Completion Header Queues Size and the Initial CplH Credit
#define CND003_BUSXP1_D1D7F0_MSG_PENDING_STA_Z1 0x1AE // Message Pending Status
    #define CND003_BUSXP1_D1D7F0_RSV_1AE D1D7F0_MSG_PENDING_STA_Z1 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_MSG_PENDING_STA_Z2 0x1AF // Message Pending Status
    #define CND003_BUSXP1_D1D7F0_RSV_1AF D1D7F0_MSG_PENDING_STA_Z2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_UNRELIABLE_LINK_MANAGEMENT 0x1B0 // Unreliable Link Management
    #define CND003_BUSXP1_D1D7F0_RUNRLCLR     BIT7            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSPDUNRL     BIT6            // 1b/1/1/x Priority Control When the Link is Unstable
    #define CND003_BUSXP1_D1D7F0_RTLPRSCNT    (BIT4 + BIT5)   // 00b/00/00/x Limitation of Transmitter Replays the TLP with the Same Sequence ...
    #define CND003_BUSXP1_D1D7F0_RRXNAKCNT    (BIT2 + BIT3)   // 00b/00/00/X Limitation of Receiver Receives the TLP with the Same Sequence Nu...
    #define CND003_BUSXP1_D1D7F0_RUNRLEN_RX   BIT1            // 0/0/1/x Enable Receiver Link Unreliable Detection
    #define CND003_BUSXP1_D1D7F0_RUNRLEN_TX   BIT0            // 0/0/1/x Enable Transmitter Link Unreliable Detection
#define CND003_BUSXP1_D1D7F0_REPLAY_TIMER_LIMIT 0x1B1 // Replay Timer Limit
    #define CND003_BUSXP1_D1D7F0_RSV_118 D1D7F0_REPLAY_TIMER_LIMIT // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_FLOW_CTL_INIT_FCI_FLOW_CTL_UNIT_FCU_CTL_AND_STA 0x1B2 // Flow Control Initialization (FCI) / Flow Control Unit (FCU) Control and Status
    #define CND003_BUSXP1_D1D7F0_RFRTMDERR    BIT7            // 0/0/x/x FCI / FCU Timeout Status
    #define CND003_BUSXP1_D1D7F0_RFRTMEN      BIT6            // 1b/1/1/x FCI / FCU Receive Timer Enable
    #define CND003_BUSXP1_D1D7F0_RFRTMLM      BIT5            // 0/0/0/x FCI / FCU Receive Timer Limit
    #define CND003_BUSXP1_D1D7F0_RFRTMDLP     BIT4            // 0/0/1/x FCI / FCU Receive Timer Reset Control
    #define CND003_BUSXP1_D1D7F0_RSV_119      (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RASL1TMFCI   BIT1            // 1b/1/x/x FCI Finish with DL_ASL1 Control
    #define CND003_BUSXP1_D1D7F0_RDLFCUDMCLK  BIT0            // 0/0/x/1 FCU Dynamic Clock Stop Function Control
#define CND003_BUSXP1_D1D7F0_REPLAY_TIMER_CTL 0x1B3 // Replay Timer Control
    #define CND003_BUSXP1_D1D7F0_RRTCTL   (BIT6 + BIT7)           // 10b/10/10/x Replay Timer Control While Rewind
    #define CND003_BUSXP1_D1D7F0_RSV_120  (BIT3 + BIT4 + BIT5)    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RNREVLD  (BIT0 + BIT1 + BIT2)    // 001b/001/000/x Count of Replay Timer Expired during RxL0s (Receiver in L0s St...
#define CND003_BUSXP1_D1D7F0_ARBITRATION_CTL 0x1B4 // Arbitration Control
    #define CND003_BUSXP1_D1D7F0_RSV_121  0xF8                    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDLARB   (BIT0 + BIT1 + BIT2)    // 000b/000/111/x Data Link TX Packets Arbitration Scheme
#define CND003_BUSXP1_D1D7F0_FCU_CTL 0x1B5 // FCU Control
    #define CND003_BUSXP1_D1D7F0_RSV_122  BIT7            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RFCUCTL  BIT6            // 0/0/0/x FCU Timer Control
    #define CND003_BUSXP1_D1D7F0_RACKCLPS (BIT4 + BIT5)   // 01b/01/01/x ACK Minimum Latency Control
    #define CND003_BUSXP1_D1D7F0_RSV_123  (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RFCIENDC BIT1            // 0/0/0/x FCI Process End Condition
    #define CND003_BUSXP1_D1D7F0_RFCIFREQ BIT0            // 0/0/0/x VC1 FCI Data Link Layer Packet (DLLP) Transmission Scheme
#define CND003_BUSXP1_D1D7F0_TRANSACTION_LINK_LAYER_CHECKING_CTL 0x1B6 // Transaction / Link Layer Checking Control
    #define CND003_BUSXP1_D1D7F0_RNAKFLGEN        BIT7            // 0/0/0/x Nak_Scheduled Flag Control
    #define CND003_BUSXP1_D1D7F0_RRCVTLTM         (BIT5 + BIT6)   // 01b/01/01/x TLP Receiving Timer
    #define CND003_BUSXP1_D1D7F0_RFASTHPOP        BIT4            // 0/0/0/0 The First Downstream TLP Is Popped Out from TL 1T Earlier
    #define CND003_BUSXP1_D1D7F0_RDISPMCACKRST    BIT3            // 1b/1/x/x Enable the Receive Buffer Controller ((RXBCTL)) Reset Scheme When PM...
    #define CND003_BUSXP1_D1D7F0_RSV_124          (BIT1 + BIT2)   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLCRCCHK         BIT0            // 1b/1/1/x LCRC Check Control
#define CND003_BUSXP1_D1D7F0_FCU_CTL_Z1 0x1B7 // FCU Control
    #define CND003_BUSXP1_D1D7F0_RSV_125      (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCPLFCUCTL   (BIT4 + BIT5)   // 00b/00/10/x Update FCU According to TRANS FIFO Status
    #define CND003_BUSXP1_D1D7F0_RPFCUCTL     (BIT2 + BIT3)   // 00b/00/10/x Update FCU According to TRANS FIFO Status
    #define CND003_BUSXP1_D1D7F0_RNFCUCTL     (BIT0 + BIT1)   // 00b/00/11/x Update FCU According to TRANS FIFO Status
#define CND003_BUSXP1_D1D7F0_DATA_LINK_LAYER_HDR_POSITION 0x1B8 // Data Link Layer Header Position
    #define CND003_BUSXP1_D1D7F0_RSV_126  0xFE    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSDPLN0  BIT0    // 0/0/0/x Data Link Layer Header Position
#define CND003_BUSXP1_D1D7F0_RESERVED_Z4 0x1B9 // Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_126_1    0xFC    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RENDINVD     BIT1    // 0/0/x/x When miss END
    #define CND003_BUSXP1_D1D7F0_RTHDINVD     BIT0    // 1b/1b/x/x When two DHD/THD before END
#define CND003_BUSXP1_D1D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X16 0x1BA // Ack / Nak Latency Timer Limit for X16
    #define CND003_BUSXP1_D1D7F0_RACKLTLM_L D1D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X16 // 0Ch/0ch/x/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency Tim...
#define CND003_BUSXP1_D1D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X8_X4 0x1BB // Ack / Nak Latency Timer Limit for X8 / X4
    #define CND003_BUSXP1_D1D7F0_RACKLTLM_M D1D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X8_X4 // 12h/12h/12h/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency T...
#define CND003_BUSXP1_D1D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X2_X1 0x1BC // Ack / Nak Latency Timer Limit for X2 / X1
    #define CND003_BUSXP1_D1D7F0_RACKLTLM_S D1D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X2_X1 // 3Bh/3Bh/3Bh/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency T...
#define CND003_BUSXP1_D1D7F0_REPLAY_TIMER_LIMIT_FOR_X16 0x1BD // Replay Timer Limit for X16
    #define CND003_BUSXP1_D1D7F0_RRPLYTM_L D1D7F0_REPLAY_TIMER_LIMIT_FOR_X16 // 2Eh/2eh/2eh/x Replay Timer Limit  for X8 / X4 (in unit of 250MHz)
#define CND003_BUSXP1_D1D7F0_REPLAY_TIMER_LIMIT_FOR_X8_X4 0x1BE // Replay Timer Limit for X8 / X4
    #define CND003_BUSXP1_D1D7F0_RRPLYTM_M D1D7F0_REPLAY_TIMER_LIMIT_FOR_X8_X4 // 3Fh/3fh/3fh/x Replay Timer Limit  for X8 / X4 (in unit of 250MHz)
#define CND003_BUSXP1_D1D7F0_REPLAY_TIMER_LIMIT_FOR_X2_X1 0x1BF // Replay Timer Limit for X2 / X1
    #define CND003_BUSXP1_D1D7F0_RRPLYTM_S D1D7F0_REPLAY_TIMER_LIMIT_FOR_X2_X1 // AFh/afh/afh/x Replay Timer Limit  for X2 / X1 (in unit of 250MHz)
#define CND003_BUSXP1_D1D7F0_GENERAL_CTL_1 0x1C0 // General Control 1
    #define CND003_BUSXP1_D1D7F0_QKTMOUT          BIT7                    // 0/0/x/x Quick Timeout Counter Setting
    #define CND003_BUSXP1_D1D7F0_DIS_SCRMBL       BIT6                    // 0/0/x/x Disable Data Scrambling / Descrambling
    #define CND003_BUSXP1_D1D7F0_LPBK_SEL         (BIT3 + BIT4 + BIT5)    // 000b/0/x/x Loopback Mode Selection
    #define CND003_BUSXP1_D1D7F0_COMDET_WINDOW    (BIT0 + BIT1 + BIT2)    // 011b/011/x/x COMMA Detection Window
#define CND003_BUSXP1_D1D7F0_GENERAL_CTL_2 0x1C1 // General Control 2
    #define CND003_BUSXP1_D1D7F0_RTS1IS5PAD   BIT7    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RHATNMWE     BIT6    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RHATNMSE     BIT5    // 1b/1b/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_SKPNEGO      0x1F    // 0 0000b/0/x/x PHY Lane Configuration Setting
#define CND003_BUSXP1_D1D7F0_MAC_AND_PCS 0x1C2 // MAC and PCS
    #define CND003_BUSXP1_D1D7F0_REBRSTEN     BIT7    // 1b/1/x/x Enable Reset of Elastic Buffer When Rx1C3 (PHYLS_STATE) Is in the St...
    #define CND003_BUSXP1_D1D7F0_RSTRXEB      BIT6    // 0/0/x/x Reset Elastic Buffer
    #define CND003_BUSXP1_D1D7F0_RLNRDTOEN    BIT5    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RCVDOUT_SET  BIT4    // 0/0/x/x Bypass PHYES Device Detection in Detect Phase of LTSSM
    #define CND003_BUSXP1_D1D7F0_RPOLL24MS    BIT3    // 0/0/x/x State Machine LTSSM Exit Polling.Active
    #define CND003_BUSXP1_D1D7F0_RIGNIDL      BIT2    // 1b/1/x/x Wait IDL Ordered Set or Electrical Idle When L1/L23 Entry
    #define CND003_BUSXP1_D1D7F0_RRDCHKEN     BIT1    // 1b/1/x/x Enable Disparity Check
    #define CND003_BUSXP1_D1D7F0_RDET12MS     BIT0    // 1b/1/x/x State Machine ?Link Training and Status State Machine (LTSSM)? Control 
#define CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE 0x1C3 // PHYLS LTSSM State
    #define CND003_BUSXP1_D1D7F0_PHYLS_STATE D1D7F0_PHYLS_LTSSM_STATE // HwInit/x/x/x PHYLS LTSSM State
#define CND003_BUSXP1_D1D7F0_ELASTIC_BUFFER_BASE_REGS_FOR_LANE_0_TO_1_D1F0_D3F0_D6F0_D7F0 0x1C4 // Elastic Buffer Base Registers for Lane 0 to 1 (D1F0,D3F0,D6F0,D7F0)
    #define CND003_BUSXP1_D1D7F0_RSV_1C4_7    BIT7                    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EB_BASE_01   (BIT4 + BIT5 + BIT6)    // 110b/110/x/x Elastic Buffer Base Register for Lane 1
    #define CND003_BUSXP1_D1D7F0_RSV_1C4_3    BIT3                    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EB_BASE_00   (BIT0 + BIT1 + BIT2)    // 110b/110/x/x Elastic Buffer Base Register for Lane 0
#define CND003_BUSXP1_D1D7F0_ELASTIC_BUFFER_BASE_REGS_FOR_LANE_2_TO_3_D1F0_D6F0 0x1C5 // Elastic Buffer Base Registers for Lane 2 to 3 (D1F0,D6F0)
    #define CND003_BUSXP1_D1D7F0_RSV_1C5_7    BIT7                    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EB_BASE_03   (BIT4 + BIT5 + BIT6)    // 110b/110/x/x Elastic Buffer Base Register for Lane 3
    #define CND003_BUSXP1_D1D7F0_RSV_1C5_3    BIT3                    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EB_BASE_02   (BIT0 + BIT1 + BIT2)    // 110b/110/x/x Elastic Buffer Base Register for Lane 2
#define CND003_BUSXP1_D1D7F0_ELASTIC_BUFFER_BASE_REGS_FOR_LANE_4_TO_7 0x1C6 // Elastic Buffer Base Registers for Lane 4 to 7
    #define CND003_BUSXP1_D1D7F0_RSV_1C6_4 D1D7F0_ELASTIC_BUFFER_BASE_REGS_FOR_LANE_4_TO_7 // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_SKP_ORDERED_SET_CTL 0x1C8 // SKP Ordered Set Control
    #define CND003_BUSXP1_D1D7F0_RDEVDISCRMEN     BIT7    // 0/0/x/x It Is Used to Enable Device Issuing Disable Scrambling Capability
    #define CND003_BUSXP1_D1D7F0_R64TS2SEND       BIT6    // 0/0/x/x TS2 Send Control during Speed Change
    #define CND003_BUSXP1_D1D7F0_RSPEEDWAIT       BIT5    // 0/0/x/x Wait EIOS before Change State from Recovery_RcvrCfg to Recovery_Speed
    #define CND003_BUSXP1_D1D7F0_RDSKWERREN       BIT4    // 0/0/x/x Deskew Error Report Enable
    #define CND003_BUSXP1_D1D7F0_RDISRCVR         BIT3    // 1b/1/x/x Disable Receiver Error Report 
    #define CND003_BUSXP1_D1D7F0_RFIXSCRMBLDIS    BIT2    // 0/0/x/x Link Scramble Disable Bit Sampled Control
    #define CND003_BUSXP1_D1D7F0_R1530SKP         BIT1    // 0/0/x/x Enable SKP Ordered-Set Scheduling of 4.72us or 6.12us
    #define CND003_BUSXP1_D1D7F0_R118SKP          BIT0    // 0/0/x/x Enable SKP Ordered-Set Scheduling to Match the Clock Difference of 56...
#define CND003_BUSXP1_D1D7F0_UNRELIABLE_LINK_STA_D1F0_D6F0 0x1C9 // Unreliable Link Status (D1F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_TBD_1C9  0xF8    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_UNRL_X4  BIT2    // HwInit/x/x/x X4 Link Width Unreliable Status
    #define CND003_BUSXP1_D1D7F0_UNRL_X2  BIT1    // HwInit/x/x/x X2 Link Width Unreliable Status
    #define CND003_BUSXP1_D1D7F0_UNRL_G2  BIT0    // HwInit/x/x/x Gen2 Link Speed Unreliable Status
#define CND003_BUSXP1_D1D7F0_L12_THRESOULD_VALUE_AND_SCALE 0x1CA // L12 Thresould Value and Scale
    #define CND003_BUSXP1_D1D7F0_TBD_1CB              (BIT13 + BIT14 + BIT15) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_L12_THRESHOLD_SCALE  (BIT10 + BIT11 + BIT12) // 0/0/x/x Scale for L12 Entrance Thresould
    #define CND003_BUSXP1_D1D7F0_L12_THRESHOLD_VALUE  0x3FF                   // 0/0/x/X Value for L12 Entrance Threshold 
#define CND003_BUSXP1_D1D7F0_SYS_DEBUG_REG_D1F0_D5F0_D6F0 0x1CC // System Debug Register (D1F0,D5F0,D6F0)
    #define CND003_BUSXP1_D1D7F0_RSV_137  BIT7                    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDESKEW  (BIT4 + BIT5 + BIT6)    // HwInit/x/x/x The De-skew Result from the Lane Selected by D1-D7F0 Rx1F2[1:0]
    #define CND003_BUSXP1_D1D7F0_RSV_138  (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RTBEBERR BIT0                    // 0/0/x/x The 10b/8b Decode Error Status from the Lane Selected by D1-D7F0 Rx1F...
#define CND003_BUSXP1_D1D7F0_MAC 0x1CD // MAC
    #define CND003_BUSXP1_D1D7F0_RFTSTR       (BIT6 + BIT7)   // 0/0/x/x Number of FTS Ordered Sent in L0s Exit Sequence with N_FTS in the Rec...
    #define CND003_BUSXP1_D1D7F0_RSKPSPD      BIT5            // 0/0/x/x Skip Speed Negotiation and Get to Target Speed Directly
    #define CND003_BUSXP1_D1D7F0_RLNRVSL      BIT4            // 0/0/x/x Lane Reversal Support
    #define CND003_BUSXP1_D1D7F0_RWDCONFIG    BIT3            // 0/0/x/1 Support Width Change in Configuration State 
    #define CND003_BUSXP1_D1D7F0_RSV_1CD_2    BIT2            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RINFEIDL     BIT1            // 1b/1/x/x Inferred Electrical Idle in GEN2 State Transition
    #define CND003_BUSXP1_D1D7F0_RQKTXG       BIT0            // 0/0/1/x Downstream TX Arbitration between DLLM and PHYLS
#define CND003_BUSXP1_D1D7F0_PCS_AND_PMA_1 0x1CE // PCS and PMA 1
    #define CND003_BUSXP1_D1D7F0_RSPDP0   BIT7                    // 0/0/x/x Transmitter Power State Setting When Link Speed Is Changed
    #define CND003_BUSXP1_D1D7F0_RVCOSTB  (BIT4 + BIT5 + BIT6)    // 001b/001/x/x CDR VCO Stabilization Time
    #define CND003_BUSXP1_D1D7F0_DRTERM   BIT3                    // 0/0/x/x Receiver Termination Disable
    #define CND003_BUSXP1_D1D7F0_RLOWSWN  BIT2                    // 0/*0/x/x Enable Low Swing Mode 
    #define CND003_BUSXP1_D1D7F0_RQKALGN  BIT1                    // 0/0/1/x Quick Byte Alignment Support
    #define CND003_BUSXP1_D1D7F0_RQKCNV   BIT0                    // 0/0/1/x Quick Phase Conversion Support
#define CND003_BUSXP1_D1D7F0_PCS_AND_PMA_2 0x1CF // PCS and PMA 2
    #define CND003_BUSXP1_D1D7F0_RSV_159      0xFC    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_ENDEEMPHS    BIT1    // 0/*0/x/x Enforce De-emphasis Level with Selectable De-emphasis Value
    #define CND003_BUSXP1_D1D7F0_RFLOWSWN     BIT0    // 0/*0/x/x Far-end Low Swing Adjustment
#define CND003_BUSXP1_D1D7F0_PM_UNIT_PMU_CTL 0x1D0 // Power Management Unit (PMU) Control
    #define CND003_BUSXP1_D1D7F0_RATREQEN     BIT7                    // 0/0/x/x Enable PHY Layer Automatic Change Speed / Width Request
    #define CND003_BUSXP1_D1D7F0_RPTOFF       (BIT4 + BIT5 + BIT6)    // 101b/101/x/x Timeout Period
    #define CND003_BUSXP1_D1D7F0_RSPDCLRPM    BIT3                    // 1b/1/x/x Enable Clearing the PM Cycles Requested by the Device in Speed Negot...
    #define CND003_BUSXP1_D1D7F0_RBDLLPEN     BIT2                    // 1b/1/x/x Retrain Link When Bad DLLP Is Checked
    #define CND003_BUSXP1_D1D7F0_LCLPBK       BIT1                    // 0/0/x/x Link Loopback
    #define CND003_BUSXP1_D1D7F0_LCRCNFG      BIT0                    // 0/0/x/x Link Reconfigure Link Width
#define CND003_BUSXP1_D1D7F0_PMU_TIMEOUT_AND_PMU_CTL 0x1D1 // PMU Timeout and PMU Control
    #define CND003_BUSXP1_D1D7F0_UFTMERR          BIT7            // 0/x/x/x Error Status Report When Entering L1 Fails
    #define CND003_BUSXP1_D1D7F0_RSV_144          BIT6            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_UFTIME           (BIT4 + BIT5)   // 11b/11/x/x Electrical Idle Waiting Period before Moving to L1 State (after is...
    #define CND003_BUSXP1_D1D7F0_RPMUERRRETRAINEN BIT3            // 1b/1/x/x Enable PMU Initiate Error Recovery
    #define CND003_BUSXP1_D1D7F0_RPMACKL1         BIT2            // 0/0/x/x Enable PM_Request_Ack DLLP Generation When the CPL TLP Is Put Inside ...
    #define CND003_BUSXP1_D1D7F0_RSV_1D1_1_0      (BIT0 + BIT1)   // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_PMU_L0S_IDLE_TIMEOUT 0x1D2 // PMU L0s Idle Timeout
    #define CND003_BUSXP1_D1D7F0_L0SLIM D1D7F0_PMU_L0S_IDLE_TIMEOUT // 03h/03h/ffh/0 L0s Timer Limitation
#define CND003_BUSXP1_D1D7F0_PMU_L1_IDLE_TIMEOUT 0x1D3 // PMU L1 Idle Timeout
    #define CND003_BUSXP1_D1D7F0_ASL1LIM D1D7F0_PMU_L1_IDLE_TIMEOUT // 04h/04h/ffh/0 Active State L1 Timer Limitation
#define CND003_BUSXP1_D1D7F0_PMC_EXPRESS_MSG_STA 0x1D8 // PMC Express Message Status
    #define CND003_BUSXP1_D1D7F0_RR2AER   BIT7    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_146  0x7F    // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_RESERVED_Z5 0x1D9 // Reserved
    #define CND003_BUSXP1_D1D7F0_RX1D9    0xFC    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDISSSPL BIT1    // 0/0/0/x Downstream Set Slot Power Limit Message Control for PCIe Downstream P...
    #define CND003_BUSXP1_D1D7F0_RPMETOFF BIT0    // 0/0/0/x Inhibit Sending PME Turn Off
#define CND003_BUSXP1_D1D7F0_RESERVED_Z6 0x1DA // Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_1DB D1D7F0_RESERVED_Z6 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_TARGET_LINK_WIDTH_D1F0 0x1E0 // Target Link Width (D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_147  (BIT5 + BIT6 + BIT7)    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_LKTLW_4  BIT4                    // 0/0/x/x Target Link Width Bit 4
    #define CND003_BUSXP1_D1D7F0_LKTLW_3  BIT3                    // 0/0/x/x Target Link Width Bit 3
    #define CND003_BUSXP1_D1D7F0_LKTLW_2  BIT2                    // HwInit/x/x/x Target Link Width Bit 2
    #define CND003_BUSXP1_D1D7F0_LKTLW_1  BIT1                    // HwInit/x/x/x Target Link Width Bit 1
    #define CND003_BUSXP1_D1D7F0_LKTLW_0  BIT0                    // HwInit/x/x/x Target Link Width Bit 0
#define CND003_BUSXP1_D1D7F0_PERCENTAGE_OF_NON_IDLE_PNI_CNTER_SETTING 0x1E1 // Percentage of Non-Idle (PNI) Counter Setting
    #define CND003_BUSXP1_D1D7F0_RPNISTLM 0xF0    // 0001b/0001/x/x Delay Duration that the PNI Counter Will Start After Entering ...
    #define CND003_BUSXP1_D1D7F0_RPNIDUR  0xF     // 0010b/0010/x/x Evaluation Period of PNI Calculation
#define CND003_BUSXP1_D1D7F0_PNI_ALGORITHM_SETTINGS 0x1E2 // PNI Algorithm Settings
    #define CND003_BUSXP1_D1D7F0_RPNI90CL 0xF0    // 0010b/0010/0000/0011 Logic Idle Percentage of PNI_90 Calculation
    #define CND003_BUSXP1_D1D7F0_RPNI30CL 0xF     // 0010b/0010/0011/0000 Logic Idle Percentage of PNI_30 Calculation
#define CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT 0x1E3 // GEN2 MAC Enhancement
    #define CND003_BUSXP1_D1D7F0_RCMPRCV      BIT7            // 0/0/x/x Compliance Receive Bit Setting in Transmitting TS1 Ordered Sets
    #define CND003_BUSXP1_D1D7F0_RUPMAXCFG    BIT6            // 0/0/1/0 Link Width Selection
    #define CND003_BUSXP1_D1D7F0_REQLZTM      (BIT4 + BIT5)   // 10b/*10/x/x Equalizer Tuning Timeout Setting
    #define CND003_BUSXP1_D1D7F0_RPDDNCFG     BIT3            // 0/0/x/1 Power Down Unintended TX to Down Configure Link Width When LTSSM Is i...
    #define CND003_BUSXP1_D1D7F0_RDOWNCFG     BIT2            // 0/0/x/x Electrical Idle Detection Behavior in Inactive Lanes When LTSSM Is in...
    #define CND003_BUSXP1_D1D7F0_RIGNEQLZ     BIT1            // 0/0/x/x Waiting Condition of Equalizer Tuning Timeout When LTSSM Is to Be Cha...
    #define CND003_BUSXP1_D1D7F0_RWDEARLY     BIT0            // 1b/1/x/x Enable of TXs in Inactive Lanes to Upconfigure Link Width when LTSSM...
#define CND003_BUSXP1_D1D7F0_SPEED_MANAGEMENT 0x1E4 // Speed Management
    #define CND003_BUSXP1_D1D7F0_RSPFLCLR BIT7    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSCFLSET 0x7F    // 00h/0/x/x Number of Permitted Speed Negotiation
#define CND003_BUSXP1_D1D7F0_LINK_WIDTH_NEGOTIATION 0x1E5 // Link Width Negotiation
    #define CND003_BUSXP1_D1D7F0_RWDFLCLR BIT7    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RWCFLSET 0x7F    // 0/0/x/x Number of Permitted Link Width Negotiation
#define CND003_BUSXP1_D1D7F0_LINK_BANDWIDTH_CHANGE_FAIL_STA_D1F0_D6F0 0x1E6 // Link Bandwidth Change Fail Status (D1F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_RSV_1E6      (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_WDFLX4       BIT5                    // HwInit/x/x/x Internal ?width_fail_field? Status for X4 Link Width
    #define CND003_BUSXP1_D1D7F0_WDFLX2       BIT4                    // HwInit/x/x/x Internal ?width_fail_field? Status for X2 Link Width
    #define CND003_BUSXP1_D1D7F0_RSV_1E6_1    (BIT1 + BIT2 + BIT3)    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_SPFLG2       BIT0                    // HwInit/x/x/x Internal ?speed_fail_field? Status for Gen2 Link Speed
#define CND003_BUSXP1_D1D7F0_BANDWIDTH_PWR_ARBITRATION 0x1E7 // Bandwidth Power Arbitration
    #define CND003_BUSXP1_D1D7F0_RSV_1E7      0xFE    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RWIDLKHOT    BIT0    // 1b/1/x/x Priority Control when Hardware Auto Bandwidth Change Is Enabled for ...
#define CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM 0x1E8 // Aggressive Power Management
    #define CND003_BUSXP1_D1D7F0_RRXEIDPD     BIT7    // 0/0/x/1 PCIE EPHY Receiver Electrical Idle Detector Power Down Control
    #define CND003_BUSXP1_D1D7F0_RL1DYNPMG2   BIT6    // 0/0/x/1 Enable L1 MPLL Power Down in GEN2 Speed
    #define CND003_BUSXP1_D1D7F0_RLNCLKPM     BIT5    // 0/0/x/1 Enable Clock Gating on Unused Lanes in a Multilane Link
    #define CND003_BUSXP1_D1D7F0_RLNPWR       BIT4    // 0/0/x/1 Enable Power down on Unused Lanes in a Multilane Link
    #define CND003_BUSXP1_D1D7F0_RDSKWPM      BIT3    // 0/0/x/1 Enable Aggressive Power Management in RX Path to Data Link Layer Modu...
    #define CND003_BUSXP1_D1D7F0_RDEVDETPM    BIT2    // 0/0/x/1 Enable Aggressive Power Management when No Device Plug
    #define CND003_BUSXP1_D1D7F0_RPDL2        BIT1    // 0/0/x/x Enable PHYES Level 2 Power Down
    #define CND003_BUSXP1_D1D7F0_RL1TPLLPD    BIT0    // 0/0/0/*1 Turn off TPLL When in L1 State
#define CND003_BUSXP1_D1D7F0_LKTGLS_VIA_AND_NEED_EQTS 0x1E9 // LKTGLS_VIA and NEED_EQTS
    #define CND003_BUSXP1_D1D7F0_RSV_1EA      0xF8            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_LKTGLS_VIA   (BIT1 + BIT2)   // 10b/10b/x/x Real Target Link Speed
    #define CND003_BUSXP1_D1D7F0_NEED_EQTS    BIT0            // 0/0/x/x EQTS Control Register
#define CND003_BUSXP1_D1D7F0_RESERVED_Z7 0x1EA // Reserved
    #define CND003_BUSXP1_D1D7F0_TBD_1EA D1D7F0_RESERVED_Z7 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_REPEAT_CNTER_OF_THE_TEST_PATTERN 0x1F0 // Repeat Counter of the Test Pattern
    #define CND003_BUSXP1_D1D7F0_RPTNUM D1D7F0_REPEAT_CNTER_OF_THE_TEST_PATTERN // 00h/0/x/X Repeat Counter of the Test Pattern (as selected in Rx1F2[7:4] ((MOD...
#define CND003_BUSXP1_D1D7F0_TEST_PATTERN_SEL 0x1F1 // Test Pattern Selection
    #define CND003_BUSXP1_D1D7F0_MODESEL  0xF0                    // 0010b/0010/x/X Test Pattern Select
    #define CND003_BUSXP1_D1D7F0_RSV_152  BIT3                    // 0/0/x/X Reserved
    #define CND003_BUSXP1_D1D7F0_LANESEL  (BIT0 + BIT1 + BIT2)    // 000b/0/x/x Select Lane for Test and debug
#define CND003_BUSXP1_D1D7F0_USER_DEFINED_TEST_PATTERN_1 0x1F2 // User Defined Test Pattern 1
    #define CND003_BUSXP1_D1D7F0_SPTPTXD_15_0 D1D7F0_USER_DEFINED_TEST_PATTERN_1 // 0/0/x/x User Defined Test Pattern Bits [15:0]
#define CND003_BUSXP1_D1D7F0_USER_DEFINED_TEST_PATTERN_2 0x1F4 // User Defined Test Pattern 2
    #define CND003_BUSXP1_D1D7F0_SPTPTXD_31_16 D1D7F0_USER_DEFINED_TEST_PATTERN_2 // 0/0/x/x User Defined Test Pattern Bits [31:16]
#define CND003_BUSXP1_D1D7F0_USER_DEFINED_TEST_PATTERN_3 0x1F6 // User Defined Test Pattern 3
    #define CND003_BUSXP1_D1D7F0_SPTPTXD_39_32 D1D7F0_USER_DEFINED_TEST_PATTERN_3 // 0/0/x/x User Defined Test Pattern Bits [39:32]
#define CND003_BUSXP1_D1D7F0_USER_DEFINED_TEST_PATTERN_4 0x1F7 // User Defined Test Pattern 4
    #define CND003_BUSXP1_D1D7F0_RSV_1F7 D1D7F0_USER_DEFINED_TEST_PATTERN_4 // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_USER_DEFINED_TEST_PATTERN_5 0x1F8 // User Defined Test Pattern 5
    #define CND003_BUSXP1_D1D7F0_RSV_1F8 D1D7F0_USER_DEFINED_TEST_PATTERN_5 // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_TEST_MODE_CTL_1 0x1F9 // Test Mode Control 1
    #define CND003_BUSXP1_D1D7F0_EPHYTST      BIT7                    // 0/0/x/x Enable Electrical PHY Test Mode 
    #define CND003_BUSXP1_D1D7F0_RSV_153      (BIT4 + BIT5 + BIT6)    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_1F9_3_0  0xF                     // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_BIST_STA_RXD_1_D1F0_D5F0_D6F0 0x1FA // BIST Status RXD 1 (D1F0, D5F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_RSV_154          0xFFF0  // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TPHYRXD_19_16    0xF     // HwInit/x/x/x Received Symbol
#define CND003_BUSXP1_D1D7F0_BIST_STA_RXD_2_D1F0_D5F0_D6F0 0x1FC // BIST Status RXD 2 (D1F0, D5F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_TPHYRXD_15_0 D1D7F0_BIST_STA_RXD_2_D1F0_D5F0_D6F0 // HwInit/x/x/x Transmitted Symbol 
#define CND003_BUSXP1_D1D7F0_PHY_BIST_CNTER_TEST_MODE_D1F0_D5F0_D6F0 0x1FE // PHY BIST Counter Test Mode (D1F0, D5F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_EPHYERRCNT D1D7F0_PHY_BIST_CNTER_TEST_MODE_D1F0_D5F0_D6F0 // HwInit/x/x/x PHY BIST Period Electrical PHY Test Error
#define CND003_BUSXP1_D1D7F0_PHY_RECEIVER_ERR_CNTER_CTL 0x200 // PHY Receiver Error Counter Control
    #define CND003_BUSXP1_D1D7F0_RSV_200_7    BIT7            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_157      BIT6            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RECNTST      BIT5            // 0/0/x/x Receiver Error Counter Manual Start Control
    #define CND003_BUSXP1_D1D7F0_RECNTSTSET   BIT4            // 0/0/x/x Enable Receiver Error Counter Manual Start
    #define CND003_BUSXP1_D1D7F0_RSV_158      (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RECNTEND     BIT1            // 0/0/x/x Receiver Error Counter Manual End Control
    #define CND003_BUSXP1_D1D7F0_RECNTENDSET  BIT0            // 0/0/x/x Enable Receiver Error Counter Manual End
#define CND003_BUSXP1_D1D7F0_RESERVED_Z8 0x201 // Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_201 D1D7F0_RESERVED_Z8 // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_PHY_TRANSMIT_ERR_CNTER_CTL_D1F0_D5F0_D6F0 0x202 // PHY Transmit Error Counter Control (D1F0, D5F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_CMPTECNT D1D7F0_PHY_TRANSMIT_ERR_CNTER_CTL_D1F0_D5F0_D6F0 // HwInit/x/x/x Error Count in Transmitted Modified Compliance Pattern
#define CND003_BUSXP1_D1D7F0_PHY_RECEIVE_ERR_CNTER_CTL_D1F0_D5F0_D6F0 0x203 // PHY Receive Error Counter Control (D1F0, D5F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_CMPRECNT D1D7F0_PHY_RECEIVE_ERR_CNTER_CTL_D1F0_D5F0_D6F0 // HwInit/x/x/x Error Count in Received Modified Compliance Pattern
#define CND003_BUSXP1_D1D7F0_TEST_MODE_CTL_2 0x204 // Test Mode Control 2
    #define CND003_BUSXP1_D1D7F0_RSV_160      (BIT29 + BIT30 + BIT31) // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLPBKDIF     BIT28                   // 0/0/x/x All Lanes in a Link Loopback Configuration Setting Control
    #define CND003_BUSXP1_D1D7F0_RSKPINTST    BIT27                   // 0/0/x/x SKP Ordered Set Insertion Control in EPHYTST Data Test Pattern
    #define CND003_BUSXP1_D1D7F0_RECNTBIST    BIT26                   // 0/0/x/x Error Count Counts Option ? Data Mismatch Result or RXSTATUS Result
    #define CND003_BUSXP1_D1D7F0_PWRTRSET     (BIT24 + BIT25)         // 00b/0/x/x Transmit and Receiver Power State Setting Options
    #define CND003_BUSXP1_D1D7F0_RSV_204_23_0 0xFFFFFF                // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_TEST_PATTERN_SEL_2 0x208 // Test Pattern Selection 2
    #define CND003_BUSXP1_D1D7F0_MODESEL_DIF  0xF0    // 0000b/0/x/x Different Pattern Selection 
    #define CND003_BUSXP1_D1D7F0_RSV_163      0xF     // 0/x/x/x Reserved
#define CND003_BUSXP1_D1D7F0_TEST_PATTERN_SEL_3 0x209 // Test Pattern Selection 3
    #define CND003_BUSXP1_D1D7F0_LANESEL_DIF D1D7F0_TEST_PATTERN_SEL_3 // 0/0/x/x Select Lanes with Different Pattern
#define CND003_BUSXP1_D1D7F0_RESERVED_Z9 0x20A // Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_20A D1D7F0_RESERVED_Z9 // 0/x/x/X Reserved
// D1F0-D7F0
#define D1F0D7F0_EPHY_RCVDET_EIDLE_STA_D1F0 0x20B // EPHY RCVDET EIDLE Status (D1F0)
    #define D1F0D7F0_EP04_EIDLESQSDET   BIT7    // HwInit/x/x/x EPHYA Lane 04 Squelch Detect Status
    #define D1F0D7F0_EP03_EIDLESQSDET   BIT6    // HwInit/x/x/x EPHYA Lane 03 Squelch Detect Status
    #define D1F0D7F0_EP02_EIDLESQSDET   BIT5    // HwInit/x/x/x EPHYA Lane 02 Squelch Detect Status
    #define D1F0D7F0_EP01_EIDLESQSDET   BIT4    // HwInit/x/x/x EPHYA Lane 01 Squelch Detect Status
    #define D1F0D7F0_EP04_RCVDET        BIT3    // HwInit/x/x/x EPHYA Lane 04 RCV DET Status
    #define D1F0D7F0_EP03_RCVDET        BIT2    // HwInit/x/x/x EPHYA Lane 03 RCV DET Status
    #define D1F0D7F0_EP02_RCVDET        BIT1    // HwInit/x/x/x EPHYA Lane 02 RCV DET Status
    #define D1F0D7F0_EP01_RCVDET        BIT0    // HwInit/x/x/x EPHYA Lane 01 RCV DET Status
// D1-D7F0
#define CND003_BUSXP1_D1D7F0_BIST_STA_TXD_D1F0_D5F0_D6F0 0x20C // BIST Status TXD (D1F0, D5F0, D6F0)
    #define CND003_BUSXP1_D1D7F0_RSV_20C_31   0xFF000000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EPHYBISTER   BIT23                   // HwInit/x/x/x Electrical PHY Built-In Self Test Error of Symbol Comparison
    #define CND003_BUSXP1_D1D7F0_RSV_20C_22   (BIT20 + BIT21 + BIT22) // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_TPHYTXD      0xFFFFF                 // HwInit/x/x/x Transmitted Symbol 
#define CND003_BUSXP1_D1D7F0_PEXC_PM_CTL_1 0x230 // PEXC Power Management Control 1
    #define CND003_BUSXP1_D1D7F0_RPMUDMCLK    BIT7    // 0/0/x/1 Dynamic Clock Power Management for PMU Transmission
    #define CND003_BUSXP1_D1D7F0_RDLTXDMCLK   BIT6    // 0/0/x/1 Dynamic Stop for EDCLK for Downstream Packets in DLL
    #define CND003_BUSXP1_D1D7F0_RDLRXDMCLK   BIT5    // 0/0/x/1 Dynamic Stop for EDCLK for Upstream Packets in DLL of RP
    #define CND003_BUSXP1_D1D7F0_RTLRTYDBXPM  BIT4    // 0/0/x/1 Dynamic Stop for ETCLK_PEG for Downstream Retry FIFO of RP
    #define CND003_BUSXP1_D1D7F0_RTLSNOPPM    BIT3    // 0/0/x/1 Dynamic Stop for ETCLK for Upstream Snoop Data Handling of RP
    #define CND003_BUSXP1_D1D7F0_RTLNSNOPPM   BIT2    // 0/0/x/1 TL Dynamic Clock Control for Non-snoop Path
    #define CND003_BUSXP1_D1D7F0_RTLDNDBXPM   BIT1    // 0/0/x/1 Dynamic Stop for ETCLK for Downstream Data FIFO of RP
    #define CND003_BUSXP1_D1D7F0_RTLUPDBXPM   BIT0    // 0/0/x/1 Dynamic Stop for ETCLK for Upstream Data FIFO of RP
#define CND003_BUSXP1_D1D7F0_PEG_PM_CTL_2 0x231 // PEG Power Management Control 2
    #define CND003_BUSXP1_D1D7F0_RTLUPPM  BIT7    // 0/0/x/1 Dynamic Stop for ETCLK for Upstream Paths of RP
    #define CND003_BUSXP1_D1D7F0_RTLDNPM  BIT6    // 0/0/x/1 Dynamic Clock Power Management for Downstream
    #define CND003_BUSXP1_D1D7F0_RTLRTYPM BIT5    // 0/0/x/1 Dynamic Stop for ETCLK for Downstream Retry Path of RP
    #define CND003_BUSXP1_D1D7F0_RTLLNKPM BIT4    // 0/0/x/1 Dynamic Clock Power Management for Link up or down case 
    #define CND003_BUSXP1_D1D7F0_RPEPM    BIT3    // 0/0/x/1 Dynamic Clock Stop Control for ETCLK at PCIe Downstream port
    #define CND003_BUSXP1_D1D7F0_RTLRCVPM BIT2    // 0/0/x/1 Dynamic Stop for ETCLK for Upstream Interface of RP
    #define CND003_BUSXP1_D1D7F0_RMESCDPM BIT1    // 0/0/x/1 Dynamic Stop for ECLK in MSGC for PCIe RP
    #define CND003_BUSXP1_D1D7F0_RMESCGPM BIT0    // 0/0/x/1 Dynamic Stop for GCLK in MSGC for PCIe RP1
#define CND003_BUSXP1_D1D7F0_PEXC_PM_CTL_3 0x232 // PEXC Power Management Control 3
    #define CND003_BUSXP1_D1D7F0_RSV_232  0xFC    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RPHYPM   BIT1    // 0/0/x/1 Dynamic Stop for EPCLK at PCIe Physical Layer
    #define CND003_BUSXP1_D1D7F0_RL1DYNPM BIT0    // 0/0/x/1 Clock Stop at L1 state for PCIe Downstream Port 
#define CND003_BUSXP1_D1D7F0_PEXC_PM_CTL_4 0x233 // PEXC Power Management Control 4
    #define CND003_BUSXP1_D1D7F0_RSV_223      0xF0    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_223_3    BIT3    // 0/0/x/1 Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_223_2    BIT2    // 0/0/x/1 Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_223_1    BIT1    // 0/0/x/1 Reserved
    #define CND003_BUSXP1_D1D7F0_RSTPGNTPM    BIT0    // 0/0/x/1 Dynamic Stop for Clocks for Stop Grant Cycle Handling in MSGC
#define CND003_BUSXP1_D1D7F0_PCIE_ARBITRATION_CTL_D1F0 0x234 // PCIE Arbitration Control (D1F0)
    #define CND003_BUSXP1_D1D7F0_RDISP2PZLW   BIT7                    // 1b/1/x/x RDISP2PZLW
    #define CND003_BUSXP1_D1D7F0_RARBDYNPM    BIT6                    // 0/0/x/1 ((For internal verify reference: @((#DYNCLK=1))  ))
    #define CND003_BUSXP1_D1D7F0_RARBDYNPMUP  BIT5                    // 0/0/x/1 ((For internal verify reference: @((#DYNCLK=1))  ))
    #define CND003_BUSXP1_D1D7F0_RARBDYNPMDN  BIT4                    // 0/0/x/1 ((For internal verify reference: @((#DYNCLK=1))  ))
    #define CND003_BUSXP1_D1D7F0_RSV_234      (BIT1 + BIT2 + BIT3)    // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RTOTESTEN    BIT0                    // 0/0/x/x RTOTESTEN
#define CND003_BUSXP1_D1D7F0_ATS_INVALIDATE_TIMEOUT_CTL_D1F0 0x235 // ATS Invalidate Timeout Control(D1F0)
    #define CND003_BUSXP1_D1D7F0_RMSGINVTOV D1D7F0_ATS_INVALIDATE_TIMEOUT_CTL_D1F0 // 40h/40h/x/x ATS Invalidate Timeout Control
#define CND003_BUSXP1_D1D7F0_ATS_INVALIDATE_TIMEOUT_CTL_D1F0_Z1 0x236 // ATS Invalidate Timeout Control(D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_236      0xFC    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RDNCFGNFLUSH BIT1    // 0/0/x/x When the reg enable downstream read CFG cycle do not flush downstream...
    #define CND003_BUSXP1_D1D7F0_RARBDYNPMAT  BIT0    // 0/0/x/0 FACLK for TACTL Module ENABLE in PEARB
#define CND003_BUSXP1_D1D7F0_RESERVED_Z10 0x237 // Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_237 D1D7F0_RESERVED_Z10 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_PCIE_DEBUG_SIGNAL_SEL_FOR_GRP0_D1F0 0x240 // PCIE Debug Signal Selection for Group0 (D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_240_2            0xFC000000  // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PCIE_DBG_SEL0_19_10  0x3FF0000   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_240_1            0xFC00      // 0/X/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PCIE_DBG_SEL0_9_0    0x3FF       // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_PCIE_DEBUG_SIGNAL_SEL_FOR_GRP1_D1F0 0x244 // PCIE Debug Signal Selection for Group1 (D1F0)
    #define CND003_BUSXP1_D1D7F0_RSV_244_2            0xFC000000  // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PCIE_DBG_SEL1_19_10  0x3FF0000   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RSV_244_1            0xFC00      // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PCIE_DBG_SEL1_9_0    0x3FF       // 0/0/x/x Reserved
#define CND003_BUSXP1_D1D7F0_MISC_CTL 0x290 // MISC Control
    #define CND003_BUSXP1_D1D7F0_RSV_290_8        0xFFFFFF00      // 0/0/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EIDLEDET_EN      BIT7            // 0/0/x/x Rx Detect ElecIDLE to Wwitch Setting in Polling Compliance
    #define CND003_BUSXP1_D1D7F0_L11_EXIT_SEL     (BIT5 + BIT6)   // 00b/x/x/x L1 Substate Exit Select
    #define CND003_BUSXP1_D1D7F0_RWTEXEPH23       BIT4            // 1b/1/x/x Want Exe EQ Phase 2 and 3
    #define CND003_BUSXP1_D1D7F0_RXDEID_L1_SEL    0xF             // 0/x/x/x Rx Electrical Idle Detecter Periodical Power down Select in L1
#define CND003_BUSXP1_D1D7F0_SECONDARY_PCI_EXPRESS_EXTENDED_CAP 0x2A0 // Secondary PCI Express Extended Capability
    #define CND003_BUSXP1_D1D7F0_TBD_2A0_3120 0xFFF00000  // 2C0h/R/x/x Next Capability Offset
    #define CND003_BUSXP1_D1D7F0_TBD_2A0_1916 0xF0000     // 1h/R/x/x Capability Version
    #define CND003_BUSXP1_D1D7F0_TBD_2A0_1500 0xFFFF      // 0019h/R/x/x PCI Express Extended Capability ID
#define CND003_BUSXP1_D1D7F0_LINK_CTL_3_REG 0x2A4 // Link Control 3 Register
    #define CND003_BUSXP1_D1D7F0_TBD_2A4_12   0xFFFFF000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_RLOW_SKP_EN  (BIT9 + BIT10 + BIT11)  // 0/x/x/x Enable Lower SKP OS Generation Vector
    #define CND003_BUSXP1_D1D7F0_TBD_2A4_2    0x1FC                   // 0/x/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_EQINTEN      BIT1                    // 0/x/x/x Link Equalization Request Interrupt Enable
    #define CND003_BUSXP1_D1D7F0_PERFORMEQ    BIT0                    // 0/x/x/x Perform Equalization
#define CND003_BUSXP1_D1D7F0_LANE_ERR_STA_REG 0x2A8 // Lane Error Status Register
    #define CND003_BUSXP1_D1D7F0_TBD_2A8 D1D7F0_LANE_ERR_STA_REG // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_LANE_EQUALIZATION_CTL_REG 0x2AC // Lane Equalization Control Register
    #define CND003_BUSXP1_D1D7F0_TBD_2AC_31 D1D7F0_LANE_EQUALIZATION_CTL_REG // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_LANE_EQUALIZATION_CTL_REG_Z1 0x2B0 // Lane Equalization Control Register
    #define CND003_BUSXP1_D1D7F0_TBD_2B0_31 D1D7F0_LANE_EQUALIZATION_CTL_REG_Z1 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_LANE_EQUALIZATION_CTL_REG_Z2 0x2B4 // Lane Equalization Control Register
    #define CND003_BUSXP1_D1D7F0_TBD_2B4_31 D1D7F0_LANE_EQUALIZATION_CTL_REG_Z2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_LANE_EQUALIZATION_CTL_REG_Z3 0x2B8 // Lane Equalization Control Register
    #define CND003_BUSXP1_D1D7F0_TBD_2B8_31 D1D7F0_LANE_EQUALIZATION_CTL_REG_Z3 // 0/R/x/x Reserved
#define CND003_BUSXP1_D1D7F0_L1_PM_SUBSTATES_EXTENDED_CAP 0x2C0 // L1 PM Substates Extended Capability
    #define CND003_BUSXP1_D1D7F0_TBD_2B0_3120 0xFFF00000  // 0/R/x/x Next Capability Offset
    #define CND003_BUSXP1_D1D7F0_TBD_2B0_1916 0xF0000     // 1h/R/x/x Capability Version
    #define CND003_BUSXP1_D1D7F0_TBD_2B0_1500 0xFFFF      // 001Eh/R/x/x PCI Express Extended Capability ID
#define CND003_BUSXP1_D1D7F0_L1_PM_SUBSTATES_CAPS_REG 0x2C4 // L1 PM Substates Capabilities Register
    #define CND003_BUSXP1_D1D7F0_TBD_2C4_24               0xFF000000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PORT_T_POWER_ON_VALUE    0xF80000                // 00111b/x/x/x Port T_POWER_ON Value
    #define CND003_BUSXP1_D1D7F0_TBD_2C4_18               BIT18                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_PORT_T_POWER_ON_SCALE    (BIT16 + BIT17)         // 01b/x/x/x Port T_POWER_ON Scale
    #define CND003_BUSXP1_D1D7F0_PORT_CM_RESTORE_TIME     0xFF00                  // 4h/x/x/x Port Common_Mode_Restore_Time
    #define CND003_BUSXP1_D1D7F0_TBD_2C4_5                (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_L1_SUB_SUPPORT           BIT4                    // 1b/x/x/x L1 PM Substates Supported
    #define CND003_BUSXP1_D1D7F0_ASPML11_SUPPORT          BIT3                    // 1b/x/x/x ASPM L1.1 Supported
    #define CND003_BUSXP1_D1D7F0_ASPML12_SUPPORT          BIT2                    // 1b/x/x/x ASPM L1.2 Supported
    #define CND003_BUSXP1_D1D7F0_PML11_SUPPORT            BIT1                    // 1b/x/x/x PCI-PM L1.1 Supported
    #define CND003_BUSXP1_D1D7F0_PML12_SUPPORT            BIT0                    // 1b/x/x/x PCI-PM L1.2 Supported
#define CND003_BUSXP1_D1D7F0_L1_PM_SUBSTATES_CTL_1_REG 0x2C8 // L1 PM Substates Control 1 Register
    #define CND003_BUSXP1_D1D7F0_TBD_2C8_31   0xFFFFFFF0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D1D7F0_ASPML11_EN   BIT3        // 0/x/x/x ASPM L1.1 Enable
    #define CND003_BUSXP1_D1D7F0_ASPML12_EN   BIT2        // 0/R/x/x ASPM L1.2 Enable
    #define CND003_BUSXP1_D1D7F0_PML11_EN     BIT1        // 0/x/x/x PCI-PM L1.1 Enable
    #define CND003_BUSXP1_D1D7F0_PML12_EN     BIT0        // 0/R/x/x PCI-PM L1.2 Enable
// D0F0
#define D0F0_L1_PM_SUBSTATES_CTL_2_REG 0x2CC // L1 PM Substates Control 2 Register
    #define D0F0_TBD_2BD            0xFFFFFF00      // 0/R/x/x Reserved
    #define D0F0_T_POWER_ON_VALUE   0xF8            // 00111b/x/x/x T_POWER_ON Value
    #define D0F0_TBD_2BC            BIT2            // 0/R/x/x Reserved
    #define D0F0_T_POWER_ON_SCALE   (BIT0 + BIT1)   // 01b/x/x/x T_POWER_ON Scale
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
