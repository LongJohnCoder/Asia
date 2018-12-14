//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_BUSxp1D8F0_R100(A0)_RD.doc.
#ifndef _IRS_CND003_BUSXP1D8F0_R100_A0_RD_H_
#define _IRS_CND003_BUSXP1D8F0_R100_A0_RD_H_
// D8F0
#define CND003_BUSXP1_D8F0_VID 0x0 // Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_15   BIT15   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_14   BIT14   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_13   BIT13   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_12   BIT12   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_11   BIT11   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_10   BIT10   // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_9    BIT9    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_8    BIT8    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_7    BIT7    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_6    BIT6    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_5    BIT5    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_4    BIT4    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_3    BIT3    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_2    BIT2    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_1    BIT1    // HwInit/x/x/x Vendor ID
    #define CND003_BUSXP1_D8F0_VENID_0    BIT0    // HwInit/x/x/x Vendor ID
#define CND003_BUSXP1_D8F0_DID 0x2 // Device ID
    #define CND003_BUSXP1_D8F0_DEVID D8F0_DID // 0721h/0721h/x/x Device ID
#define CND003_BUSXP1_D8F0_PCI_CMD 0x4 // PCI Command
    #define CND003_BUSXP1_D8F0_RX04_15_0  0xF800  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RINTDIS    BIT10   // 0/0/x/x Interrupt Disable
    #define CND003_BUSXP1_D8F0_RFBACK     BIT9    // 0/R/x/x Fast Back-to-back Cycle Enable
    #define CND003_BUSXP1_D8F0_RSERR      BIT8    // 0/x/x/x SERR# Enable
    #define CND003_BUSXP1_D8F0_RSETP      BIT7    // 0/R/x/x Address/Data Stepping
    #define CND003_BUSXP1_D8F0_RPTYERR    BIT6    // 0/0/x/x Parity Error Response
    #define CND003_BUSXP1_D8F0_RSV_3      BIT5    // 0/R/x/x VGA Palette Snooping
    #define CND003_BUSXP1_D8F0_RMWINV     BIT4    // 0/R/x/x Memory Write and Invalidate
    #define CND003_BUSXP1_D8F0_RSPCYC     BIT3    // 0/R/x/x Respond to Special Cycle
    #define CND003_BUSXP1_D8F0_RMSTR      BIT2    // 0b/x/x/x PCI Master Function
    #define CND003_BUSXP1_D8F0_RENMEM     BIT1    // 0b/x/x/x Memory Space Access
    #define CND003_BUSXP1_D8F0_RENIO      BIT0    // 0/x/x/x I/O Space Access
#define CND003_BUSXP1_D8F0_PCI_STA 0x6 // PCI Status
    #define CND003_BUSXP1_D8F0_SPERRS     BIT15                   // 0/0/x/x Detected Parity Error
    #define CND003_BUSXP1_D8F0_SERRS      BIT14                   // 0/0/x/x Signaled System Error (SERR# Asserted)
    #define CND003_BUSXP1_D8F0_SMABORT    BIT13                   // 0/0/x/x Received Master-abort (Except Special Cycle)
    #define CND003_BUSXP1_D8F0_STABORTM   BIT12                   // 0/0/x/x Received Target-abort
    #define CND003_BUSXP1_D8F0_STABORTS   BIT11                   // 0/0/x/x Target-abort Assertion
    #define CND003_BUSXP1_D8F0_DEVS_1_0   (BIT9 + BIT10)          // 0/0/x/x DEVSEL# Timing
    #define CND003_BUSXP1_D8F0_SDPERRS    BIT8                    // 0/0/x/x Master Data Parity Error
    #define CND003_BUSXP1_D8F0_RFBKS      BIT7                    // 0/0/x/x Capable of Accepting Fast Back-to-back as a Target
    #define CND003_BUSXP1_D8F0_RUDF       BIT6                    // 0/0/x/x User Definable Features
    #define CND003_BUSXP1_D8F0_R66M       BIT5                    // 0/0/x/x 66MHz Capability
    #define CND003_BUSXP1_D8F0_RCAP       BIT4                    // 1b/1b/x/x Support New Capability List
    #define CND003_BUSXP1_D8F0_SINTSTT    BIT3                    // HwInit/x/x/x Interrupt Status
    #define CND003_BUSXP1_D8F0_RSV_7      (BIT0 + BIT1 + BIT2)    // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_REV_ID 0x8 // Revision ID
    #define CND003_BUSXP1_D8F0_TBD_4 D8F0_REV_ID // 0/0/x/x Revision Code
#define CND003_BUSXP1_D8F0_CLASS_CODE 0x9 // Class Code
    #define CND003_BUSXP1_D8F0_RX08_31_8 D8F0_CLASS_CODE // 06 0400h/R/x/x Class Code
#define CND003_BUSXP1_D8F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_BUSXP1_D8F0_RX0C_7_0 D8F0_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define CND003_BUSXP1_D8F0_MASTER_LATENCY_TIMER 0xD // Master Latency Timer
    #define CND003_BUSXP1_D8F0_RX0D_7_0 D8F0_MASTER_LATENCY_TIMER // 0/R/x/x Master Latency Timer
#define CND003_BUSXP1_D8F0_HDR_TYPE 0xE // Header Type
    #define CND003_BUSXP1_D8F0_RSV_0E D8F0_HDR_TYPE // 01h/00h/x/x Header Type Code
#define CND003_BUSXP1_D8F0_BIST 0xF // Built In Self Test (BIST)
    #define CND003_BUSXP1_D8F0_RX0C_15_8 D8F0_BIST // 0/R/x/x BIST Support
#define CND003_BUSXP1_D8F0_BASE_ADR_REGS_0 0x10 // Base Address Registers 0
    #define CND003_BUSXP1_D8F0_RX10_31_0 D8F0_BASE_ADR_REGS_0 // 0/R/x/x Base Address 0
#define CND003_BUSXP1_D8F0_BASE_ADR_REGS_1 0x14 // Base Address Registers 1
    #define CND003_BUSXP1_D8F0_RX14_31_0 D8F0_BASE_ADR_REGS_1 // 0/R/x/x Base Address 1
#define CND003_BUSXP1_D8F0_PRIMARY_BUS_NUM 0x18 // Primary Bus Number
    #define CND003_BUSXP1_D8F0_PBN D8F0_PRIMARY_BUS_NUM // 0/x/x/x Primary Bus Number
#define CND003_BUSXP1_D8F0_SECONDARY_BUS_NUM 0x19 // Secondary Bus Number
    #define CND003_BUSXP1_D8F0_SBN D8F0_SECONDARY_BUS_NUM // 0/x/x/x Secondary Bus Number
#define CND003_BUSXP1_D8F0_SUBORDINATE_BUS_NUM 0x1A // Subordinate Bus Number
    #define CND003_BUSXP1_D8F0_SSBN D8F0_SUBORDINATE_BUS_NUM // 0/x/x/x Subordinate Bus Number
#define CND003_BUSXP1_D8F0_SECONDARY_LATENCY_TIMER 0x1B // Secondary Latency Timer
    #define CND003_BUSXP1_D8F0_RX018_31_24 D8F0_SECONDARY_LATENCY_TIMER // 0/R/x/x Secondary Latency Timer
#define CND003_BUSXP1_D8F0_IO_BASE 0x1C // I/O Base
    #define CND003_BUSXP1_D8F0_RIOBS_15_12    0xF0    // Fh/x/x/x I/O Base (AD[15:12] - Inclusive)
    #define CND003_BUSXP1_D8F0_TBD_10         0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_BUSXP1_D8F0_IO_LIMIT 0x1D // I/O Limit
    #define CND003_BUSXP1_D8F0_RIOLM_15_12    0xF0    // 0/x/x/x I/O Limit (AD[15:12] - Inclusive)
    #define CND003_BUSXP1_D8F0_TBD_11         0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_BUSXP1_D8F0_SECONDARY_STA 0x1E // Secondary Status
    #define CND003_BUSXP1_D8F0_SSPERRS        BIT15           // 0/0/x/x Detected Parity Error
    #define CND003_BUSXP1_D8F0_SSERRS         BIT14           // 0/0/x/x Received System Error
    #define CND003_BUSXP1_D8F0_SSMABORT       BIT13           // 0/0/x/x Received Master Abort
    #define CND003_BUSXP1_D8F0_SSTABORTM      BIT12           // 0/0/x/x Received Target Abort
    #define CND003_BUSXP1_D8F0_RSV_1E_5       BIT11           // 0/x/x/x Signaled Target Abort
    #define CND003_BUSXP1_D8F0_RX01C_26_25    (BIT9 + BIT10)  // 0/x/x/x DEVSEL Timing
    #define CND003_BUSXP1_D8F0_SSDPERRS       BIT8            // 0/0/x/x Master Data Parity Error
    #define CND003_BUSXP1_D8F0_RX01C_23       BIT7            // 0/x/x/x Fast Back-to-Back Capable
    #define CND003_BUSXP1_D8F0_RX01C_22       BIT6            // 0/x/x/x Reserved
    #define CND003_BUSXP1_D8F0_RX01C_21       BIT5            // 0/x/x/x 66MHz Capability
    #define CND003_BUSXP1_D8F0_RX01C_20_16    0x1F            // 0/x/x/x Reserved
#define CND003_BUSXP1_D8F0_MEM_BASE 0x20 // Memory Base
    #define CND003_BUSXP1_D8F0_RM1BS_31_20    0xFFF0  // FFFh/x/x/x Memory Base (AD[31:20] ? Inclusive)
    #define CND003_BUSXP1_D8F0_RSV_11         0xF     // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_MEM_LIMIT 0x22 // Memory Limit
    #define CND003_BUSXP1_D8F0_RM1LM_31_20    0xFFF0  // 0/x/x/x Memory Limit (AD[31:20] ? Inclusive)
    #define CND003_BUSXP1_D8F0_RSV_12         0xF     // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_PREFETCHABLE_MEM_BASE 0x24 // Prefetchable Memory Base
    #define CND003_BUSXP1_D8F0_RM2BS_31_20    0xFFF0                  // FFFh/x/x/x Prefetchable Memory Base AD[31:20]
    #define CND003_BUSXP1_D8F0_RSV_13         (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_TBD_12         BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory Base
#define CND003_BUSXP1_D8F0_PREFETCHABLE_MEM_LIMIT 0x26 // Prefetchable Memory Limit
    #define CND003_BUSXP1_D8F0_RM2LM_31_20    0xFFF0                  // 0/x/x/x Prefetchable Memory Limit AD[31:20]
    #define CND003_BUSXP1_D8F0_RSV_14         (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_TBD_13         BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory  Limit
#define CND003_BUSXP1_D8F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS 0x28 // Prefetchable Memory Base Upper 32 Bits
    #define CND003_BUSXP1_D8F0_RM3BS_63_32 D8F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS // 0/x/x/x Prefetchable Memory Base Upper bit[63:32]
#define CND003_BUSXP1_D8F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS 0x2C // Prefetchable Memory Limit Upper 32 Bits
    #define CND003_BUSXP1_D8F0_RM3LM_63_32 D8F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS // 0/x/x/x Prefetchable Memory Limit Upper Bit[63:32]
#define CND003_BUSXP1_D8F0_IO_BASE_UPPER 0x30 // I/O Base Upper
    #define CND003_BUSXP1_D8F0_TBD_14 D8F0_IO_BASE_UPPER // 0/R/x/x I/O Base Upper 16 Bits Address
#define CND003_BUSXP1_D8F0_IO_BASE_LIMIT 0x32 // I/O Base Limit
    #define CND003_BUSXP1_D8F0_TBD_15 D8F0_IO_BASE_LIMIT // 0/R/x/x I/O Limit Upper 16 Bits Address
#define CND003_BUSXP1_D8F0_CAP_PTR 0x34 // Capability Pointer
    #define CND003_BUSXP1_D8F0_TBD_16 D8F0_CAP_PTR // 40h/40h/x/x Capability Pointer
#define CND003_BUSXP1_D8F0_RESERVED 0x35 // Reserved
    #define CND003_BUSXP1_D8F0_TBD_16_1 D8F0_RESERVED // 0/x/x/x Reserved
#define CND003_BUSXP1_D8F0_INTR_LINE 0x3C // Interrupt Line
    #define CND003_BUSXP1_D8F0_RINTLN D8F0_INTR_LINE // 0/x/x/x Interrupt Line
#define CND003_BUSXP1_D8F0_INTR_PIN 0x3D // Interrupt Pin
    #define CND003_BUSXP1_D8F0_RX03C_15_11    0xF8                    // 0/x/x/x Reserved
    #define CND003_BUSXP1_D8F0_INTPIN         (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Interrupt Pin
#define CND003_BUSXP1_D8F0_BRIDGE_CTL 0x3E // Bridge Control
    #define CND003_BUSXP1_D8F0_RSV_17     0xF000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RX03C_27   BIT11   // 0/x/x/x Discard Timer SERR# Enable
    #define CND003_BUSXP1_D8F0_RX03C_26   BIT10   // 0/x/x/x Discard Timer Status
    #define CND003_BUSXP1_D8F0_RX03C_25   BIT9    // 0/x/x/x Secondary Discard Timer
    #define CND003_BUSXP1_D8F0_RX03C_24   BIT8    // 0/x/x/x Primary Discard Timer
    #define CND003_BUSXP1_D8F0_RX03C_23   BIT7    // 0/x/x/x Fast Back-to-Back Enable
    #define CND003_BUSXP1_D8F0_RSRST      BIT6    // 0/x/x/x Secondary Bus Reset
    #define CND003_BUSXP1_D8F0_RSV_18     BIT5    // 0/R/x/x Master Abort Mode
    #define CND003_BUSXP1_D8F0_RVGA16     BIT4    // 0/x/x/x Base VGA 16 Bits Decode
    #define CND003_BUSXP1_D8F0_RVGA       BIT3    // 0/x/x/x VGA Compatible I/O and Memory Address Range
    #define CND003_BUSXP1_D8F0_RISA       BIT2    // 0/x/x/x Block/Forward ISA I/O Cycles
    #define CND003_BUSXP1_D8F0_RSERRFWD   BIT1    // 0/x/x/x SERR Enable
    #define CND003_BUSXP1_D8F0_RPTYERRTLP BIT0    // 0/x/x/x Parity Error Response Enable
#define CND003_BUSXP1_D8F0_PCI_EXPRESS_LIST 0x40 // PCI Express List
    #define CND003_BUSXP1_D8F0_TBD_24 0xFF00  // A0h/A0h/x/x Next Pointer
    #define CND003_BUSXP1_D8F0_TBD_25 0xFF    // 10h/10h/x/x Capability ID
#define CND003_BUSXP1_D8F0_PCI_EXPRESS_CAPS 0x42 // PCI Express Capabilities
    #define CND003_BUSXP1_D8F0_RSV_42_15  BIT15   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RTCSEN     BIT14   // 0/0/x/x Reserved
    #define CND003_BUSXP1_D8F0_XINTMNO    0x3E00  // 0/0/x/x Interrupt Message Number
    #define CND003_BUSXP1_D8F0_XSLIMP     BIT8    // 0b/1/x/x Slot Implemented
    #define CND003_BUSXP1_D8F0_XDPTYPE    0xF0    // 0110b/0110/x/x Device / Port Type
    #define CND003_BUSXP1_D8F0_PCIE_VER_3 BIT3    // 0/0/x/x Capability Version Bit 3
    #define CND003_BUSXP1_D8F0_PCIE_VER_2 BIT2    // 0/0/x/x Capability Version Bit 2
    #define CND003_BUSXP1_D8F0_PCIE_VER_1 BIT1    // 1b/1b/x/x Capability Version Bit 1
    #define CND003_BUSXP1_D8F0_PCIE_VER_0 BIT0    // 0/x/x/x Capability Version Bit 0
#define CND003_BUSXP1_D8F0_DEV_CAPS_1 0x44 // Device Capabilities 1
    #define CND003_BUSXP1_D8F0_RSV_19     (BIT29 + BIT30 + BIT31) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_TBD_27     BIT28                   // 0/0/x/x Function Level Reset Capability
    #define CND003_BUSXP1_D8F0_RSV_20     (BIT26 + BIT27)         // 0/R/x/x Captured Slot Power Limit Scale
    #define CND003_BUSXP1_D8F0_RSV_21     0x3FC0000               // 0/R/x/x Captured Slot Power Limit Value
    #define CND003_BUSXP1_D8F0_RSV_22     (BIT16 + BIT17)         // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RRBERRP    BIT15                   // 1b/1b/x/x Role-based Error Reporting
    #define CND003_BUSXP1_D8F0_RSV_23     BIT14                   // 0/R/x/x Power Indicator Present
    #define CND003_BUSXP1_D8F0_RSV_24     BIT13                   // 0/R/x/x Attention Indicator Present
    #define CND003_BUSXP1_D8F0_RSV_25     BIT12                   // 0/R/x/x Attention Button Present
    #define CND003_BUSXP1_D8F0_DAL1AL     (BIT9 + BIT10 + BIT11)  // 000b/0/x/x Endpoint L1 Acceptable Latency
    #define CND003_BUSXP1_D8F0_RSV_44     (BIT6 + BIT7 + BIT8)    // 0/R/x/x Endpoint L0s Acceptable Latency
    #define CND003_BUSXP1_D8F0_DAXTAGF    BIT5                    // 0/0/x/x Extended Tag Field Supported
    #define CND003_BUSXP1_D8F0_RSV_26     (BIT3 + BIT4)           // 0/R/x/x Phantom Functions Supported
    #define CND003_BUSXP1_D8F0_DAMPSS     (BIT0 + BIT1 + BIT2)    // 001b/001/x/x Max Payload Size Supported
#define CND003_BUSXP1_D8F0_DEV_CTL_1 0x48 // Device Control 1
    #define CND003_BUSXP1_D8F0_RSV_27     BIT15                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_DCMRRS     (BIT12 + BIT13 + BIT14) // 0/R/x/x Max Read Request Size
    #define CND003_BUSXP1_D8F0_DCENS      BIT11                   // 0/0/x/x Enable No Snoop
    #define CND003_BUSXP1_D8F0_DCAPPME    BIT10                   // 0/x/x/x Auxiliary Power PM Enable
    #define CND003_BUSXP1_D8F0_DCPFE      BIT9                    // 0/R/x/x Phantom Functions Enable
    #define CND003_BUSXP1_D8F0_DCETFE     BIT8                    // 0/0/x/x Extended Tag Field Enable
    #define CND003_BUSXP1_D8F0_DCMPS      (BIT5 + BIT6 + BIT7)    // 0/000*/001*/x Max Payload Size
    #define CND003_BUSXP1_D8F0_DCERO      BIT4                    // 1b/1/x/x Enable Relaxed Ordering
    #define CND003_BUSXP1_D8F0_DCURRE     BIT3                    // 0/0/x/x Unsupported Request Reporting Enable
    #define CND003_BUSXP1_D8F0_DCFERE     BIT2                    // 0/0/x/x Fatal Error Reporting Enable
    #define CND003_BUSXP1_D8F0_DCNFERE    BIT1                    // 0/0/x/x Non-Fatal Error Reporting Enable
    #define CND003_BUSXP1_D8F0_DCCERE     BIT0                    // 0/0/x/x Correctable Error Reporting Enable
#define CND003_BUSXP1_D8F0_DEV_STA_1 0x4A // Device Status 1
    #define CND003_BUSXP1_D8F0_RSV_4B 0xFFC0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_DSTP   BIT5    // 0/0/x/x Transactions Pending
    #define CND003_BUSXP1_D8F0_DSAPD  BIT4    // 0/0/x/x AUX Power Detected
    #define CND003_BUSXP1_D8F0_DSURD  BIT3    // 0/0/x/x Unsupported Request Detected (TL)
    #define CND003_BUSXP1_D8F0_DSFED  BIT2    // 0/0/x/x Fatal Error Detected (TL)
    #define CND003_BUSXP1_D8F0_DSNFED BIT1    // 0/0/x/x Non-Fatal Error Detected (TL)
    #define CND003_BUSXP1_D8F0_DSCED  BIT0    // 0/0/x/x Correctable Error Detected (TL)
#define CND003_BUSXP1_D8F0_LINK_CAPS_1 0x4C // Link Capabilities 1
    #define CND003_BUSXP1_D8F0_LKPN           0xFF000000              // 09h/09h/x/x Port Number
    #define CND003_BUSXP1_D8F0_RSV_28G        BIT23                   // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_ASPMOPTCOMP    BIT22                   // 1b/1/x/x ASPM Optionality Compliance 
    #define CND003_BUSXP1_D8F0_RLBWNTFC       BIT21                   // 0b/0/x/x Link Bandwidth Notification Capability
    #define CND003_BUSXP1_D8F0_RDL_AR_CAP     BIT20                   // 0b/0/x/x Data Link Layer Link Active Reporting Capable
    #define CND003_BUSXP1_D8F0_RLCASDERC      BIT19                   // 0b/0/x/x Surprise Down Error Reporting Capable
    #define CND003_BUSXP1_D8F0_RLCACPM        BIT18                   // 0/0/x/x Clock Power Management
    #define CND003_BUSXP1_D8F0_LKL1EL         (BIT15 + BIT16 + BIT17) // 000b/0/x/x L1 Exit Latency
    #define CND003_BUSXP1_D8F0_LKL0SE         (BIT12 + BIT13 + BIT14) // 000b/0/x/x L0s Exit Latency
    #define CND003_BUSXP1_D8F0_LKAPMS         (BIT10 + BIT11)         // 00b/0/x/x Active State Link PM (ASPM) Support
    #define CND003_BUSXP1_D8F0_LKMLW_5        BIT9                    // 0/0/x/x Maximum Link Width Bit 5
    #define CND003_BUSXP1_D8F0_LKMLW_4        BIT8                    // 0/0/x/x Maximum Link Width Bit 4
    #define CND003_BUSXP1_D8F0_LKMLW_3        BIT7                    // 0/0/x/x Maximum Link Width Bit 3
    #define CND003_BUSXP1_D8F0_LKMLW_2        BIT6                    // 0/0/x/x Maximum Link Width Bit 2
    #define CND003_BUSXP1_D8F0_LKMLW_1        BIT5                    // 0/0/x/x Maximum Link Width Bit 1
    #define CND003_BUSXP1_D8F0_LKMLW_0        BIT4                    // 1b/1b/x/x Maximum Link Width Bit 0
    #define CND003_BUSXP1_D8F0_LKMAXLS_3      BIT3                    // 0/0/x/x Max Link Speed Bit 3 
    #define CND003_BUSXP1_D8F0_LKMAXLS_2      BIT2                    // 0/0/x/x Max Link Speed Bit 2 
    #define CND003_BUSXP1_D8F0_LKMAXLS_1      BIT1                    // 0/x/x/x Max Link Speed Bit 1
    #define CND003_BUSXP1_D8F0_LKMAXLS_0      BIT0                    // 1b/1b/x/x Max Link Speed Bit 0
#define CND003_BUSXP1_D8F0_LINK_CTL_1 0x50 // Link Control 1
    #define CND003_BUSXP1_D8F0_RSV_32     0xF000          // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RLABITEN   BIT11           // 0/0/x/x Enable Link Autonom ous Bandwidth Interrupt
    #define CND003_BUSXP1_D8F0_RLBMITEN   BIT10           // 0/0/x/x Enable Link Bandwidth Management Interrupt
    #define CND003_BUSXP1_D8F0_RHATNMWD   BIT9            // 0/0/x/0 Hardware Autonomous Width Control
    #define CND003_BUSXP1_D8F0_RLCOCPMEN  BIT8            // 0/R/x/x Enable Clock Power Management
    #define CND003_BUSXP1_D8F0_LCES       BIT7            // 0/0/0/x Extended Synch
    #define CND003_BUSXP1_D8F0_LCCCC      BIT6            // 0/0/x/x Common Clock Configuration
    #define CND003_BUSXP1_D8F0_LCRL       BIT5            // 0/0/x/x Retrain Link
    #define CND003_BUSXP1_D8F0_LCLD       BIT4            // 0/0/x/x Link Disable
    #define CND003_BUSXP1_D8F0_LCRCB      BIT3            // 0/0/x/x Read Completion Boundary
    #define CND003_BUSXP1_D8F0_RSV_33     BIT2            // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_LCAPMS     (BIT0 + BIT1)   // 00b/00*/00*/11* Link Active State PM (ASPM) Control
#define CND003_BUSXP1_D8F0_LINK_STA_1 0x52 // Link Status 1
    #define CND003_BUSXP1_D8F0_RLATNMBW   BIT15   // 0/0/x/x Link Autonomous Bandwidth Status
    #define CND003_BUSXP1_D8F0_RLBWMNGT   BIT14   // 0/0/x/x Link Bandwidth Management Status
    #define CND003_BUSXP1_D8F0_DL_ACTIVE  BIT13   // 0/0/x/x Data Link Layer Link Active
    #define CND003_BUSXP1_D8F0_LSSCC      BIT12   // 1b/x/x/x Slot Clock Configuration
    #define CND003_BUSXP1_D8F0_LSLT       BIT11   // 0/x/x/x Link Training
    #define CND003_BUSXP1_D8F0_LSTE       BIT10   // 0/x/x/x Training Error
    #define CND003_BUSXP1_D8F0_TBD_28     BIT9    // 0/R/x/x Negotiated Link Width Bit 5
    #define CND003_BUSXP1_D8F0_LSNLW      0x1F0   // 01h/01h/x/x Negotiated Link Width Bits[4:0]
    #define CND003_BUSXP1_D8F0_LSLS       0xF     // 0001b/0001b/x/x Current Link Speed
#define CND003_BUSXP1_D8F0_SLOT_CAPS_1 0x54 // Slot Capabilities 1
    #define CND003_BUSXP1_D8F0_SLPSN      0xFFF80000      // 0/0/x/x Physical Slot Number; Reserved
    #define CND003_BUSXP1_D8F0_RSCANCCS   BIT18           // 0/0/x/x No Command Completed Support
    #define CND003_BUSXP1_D8F0_RSCAEMIP   BIT17           // 0/0/x/x Electromechanical Interlock Present
    #define CND003_BUSXP1_D8F0_RSPLS      (BIT15 + BIT16) // 0/0/x/x Slot Power Limit Scale
    #define CND003_BUSXP1_D8F0_RSPLV      0x7F80          // 0/0/x/x Slot Power Limit Value
    #define CND003_BUSXP1_D8F0_SCHP_CAP   BIT6            // 0/0/x/x Hot-Plug Capable
    #define CND003_BUSXP1_D8F0_SCHPS      BIT5            // 0b/0/x/x Hot-Plug Surprise
    #define CND003_BUSXP1_D8F0_SCPIP      BIT4            // 0/0/x/x Power Indicator Present
    #define CND003_BUSXP1_D8F0_SCAIP      BIT3            // 0/0/x/x Attention Indicator Present
    #define CND003_BUSXP1_D8F0_RSV_36     BIT2            // 0/R/x/x MRL Sensor Present
    #define CND003_BUSXP1_D8F0_RSV_37     BIT1            // 0/R/x/x Power Controller Present
    #define CND003_BUSXP1_D8F0_SCABP      BIT0            // 0/0/x/x Attention Button Present
#define CND003_BUSXP1_D8F0_SLOT_CTL_1 0x58 // Slot Control 1
    #define CND003_BUSXP1_D8F0_RSV_39     (BIT13 + BIT14 + BIT15) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RDLSCHGEN  BIT12                   // 0/0/x/x Enable Data Link Layer State Change
    #define CND003_BUSXP1_D8F0_RSCOEMIC   BIT11                   // 0/R/x/x Electromechanical Interlock Control
    #define CND003_BUSXP1_D8F0_SCPCC      BIT10                   // 0/0/x/x Power Controller Control
    #define CND003_BUSXP1_D8F0_SCPIC      (BIT8 + BIT9)           // 00b/0/x/x Power Indicator Control
    #define CND003_BUSXP1_D8F0_SCAIC      (BIT6 + BIT7)           // 00b/0/x/x Attention Indicator Control
    #define CND003_BUSXP1_D8F0_SCHPIE     BIT5                    // 0/0/x/x Enable Hot-Plug Interrupt
    #define CND003_BUSXP1_D8F0_SCCCIE     BIT4                    // 0/0/x/x Enable Command Completed Interrupt 
    #define CND003_BUSXP1_D8F0_SCPDCE     BIT3                    // 0/0/x/x Enable Presence Detect Change
    #define CND003_BUSXP1_D8F0_RSV_40     BIT2                    // 0/R/x/x Enable MRL Sensor Change
    #define CND003_BUSXP1_D8F0_RSV_41     BIT1                    // 0/R/x/x Enable Power Fault Detected
    #define CND003_BUSXP1_D8F0_SCABPE     BIT0                    // 0/0/x/x Enable Attention Button Pressed
#define CND003_BUSXP1_D8F0_SLOT_STA_1 0x5A // Slot Status 1
    #define CND003_BUSXP1_D8F0_RSV_42     0xFE00  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RDLSCHG    BIT8    // 0/0/x/x Data Link Layer State Changed
    #define CND003_BUSXP1_D8F0_RSSEMIS    BIT7    // 0/R/x/x Electromechanical Interlock Status
    #define CND003_BUSXP1_D8F0_SPDCST     BIT6    // 1b/x/x/x Presence Detect State
    #define CND003_BUSXP1_D8F0_RSV_43     BIT5    // 0/R/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define CND003_BUSXP1_D8F0_SSCC       BIT4    // 0/0/x/x Command Completed
    #define CND003_BUSXP1_D8F0_SPDC       BIT3    // 0/0/x/x Presence Detect Change
    #define CND003_BUSXP1_D8F0_TBD_29     BIT2    // 0/R/x/x MRL Sensor Change
    #define CND003_BUSXP1_D8F0_TBD_30     BIT1    // 0/R/x/x Power Fault Detected
    #define CND003_BUSXP1_D8F0_SSABP      BIT0    // 0/0/x/x Attention Button Pressed
#define CND003_BUSXP1_D8F0_ROOT_CTL 0x5C // Root Control
    #define CND003_BUSXP1_D8F0_RSV_5C_5   0xFFE0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RCCRSSVE   BIT4    // 0/0/x/x Enable CRS Software Visibility
    #define CND003_BUSXP1_D8F0_RCPMEIE    BIT3    // 0/0/x/x Enable PME Interrupt
    #define CND003_BUSXP1_D8F0_RCSEFEE    BIT2    // 0/0/x/x Enable System Error on Fatal Error
    #define CND003_BUSXP1_D8F0_RCSENFEE   BIT1    // 0/0/x/x Enable System Error on Non-Fatal Error
    #define CND003_BUSXP1_D8F0_RCSECEE    BIT0    // 0/0/x/x Enable System Error on Correctable Error
#define CND003_BUSXP1_D8F0_ROOT_CAPS 0x5E // Root Capabilities
    #define CND003_BUSXP1_D8F0_RSV_44_5E  0xFFFE  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RSCRSSFV   BIT0    // 0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define CND003_BUSXP1_D8F0_ROOT_STA 0x60 // Root Status
    #define CND003_BUSXP1_D8F0_RSV_45 0xFFFC0000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RSPP   BIT17       // 0/x/x/x PME Pending
    #define CND003_BUSXP1_D8F0_RSPS   BIT16       // 0/0/x/x PME Status
    #define CND003_BUSXP1_D8F0_RSPRID 0xFFFF      // 0/x/x/x PME Requester ID
#define CND003_BUSXP1_D8F0_DEV_CAPS_2 0x64 // Device Capabilities 2
    #define CND003_BUSXP1_D8F0_RSV_64_6   0xFFF00000      // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_ROBFFSP    (BIT18 + BIT19) // 01b/01b/x/x OBFF Supported
    #define CND003_BUSXP1_D8F0_RSV_64_12  0x3F000         // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RLTRSP     BIT11           // 1b/1b/x/x LTR Mechanism Supported
    #define CND003_BUSXP1_D8F0_RSV_64_10  0x7C0           // 0/x/x/x Reserved
    #define CND003_BUSXP1_D8F0_RARISP     BIT5            // 0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define CND003_BUSXP1_D8F0_TBD_31     BIT4            // 0/0/x/x Completion Timeout Disable Supported
    #define CND003_BUSXP1_D8F0_TBD_32     0xF             // 0/R/x/x Completion Timeout Ranges Supported
#define CND003_BUSXP1_D8F0_DEV_CTL_2 0x68 // Device Control 2
    #define CND003_BUSXP1_D8F0_RSV_46     BIT15           // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_ROBFFEN    (BIT13 + BIT14) // 0/0/x/x OBFF Enable
    #define CND003_BUSXP1_D8F0_RSV_68_11  (BIT11 + BIT12) // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RLTREN     BIT10           // 0/0/x/x LTR Mechanism Enable
    #define CND003_BUSXP1_D8F0_RSV_68_6   0x3C0           // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RARIEN     BIT5            // 0/0/x/x Enable ARI Forwarding
    #define CND003_BUSXP1_D8F0_RDISCPLTM  BIT4            // 0/0/0/x Completion Timeout Disable Control
    #define CND003_BUSXP1_D8F0_TBD_33     0xF             // 0/R/x/x Completion Timeout Value
#define CND003_BUSXP1_D8F0_DEV_STA_2 0x6A // Device Status 2
    #define CND003_BUSXP1_D8F0_RSV_47 D8F0_DEV_STA_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_LINK_CAPS_2 0x6C // Link Capabilities 2
    #define CND003_BUSXP1_D8F0_RSV_6C_31              0xFFF80000  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RLOW_SKP_REC_SUPPORT_2 BIT18       // 0/0/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_BUSXP1_D8F0_RLOW_SKP_REC_SUPPORT_1 BIT17       // HwInit/x/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_BUSXP1_D8F0_RLOW_SKP_REC_SUPPORT_0 BIT16       // 1b/1b/x/x Lower SKP OS Reception Supported Speeds Vector
    #define CND003_BUSXP1_D8F0_RSV_6C_15              0xF000      // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RLOW_SKP_GEN_SUPPORT_2 BIT11       // 0/0/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_BUSXP1_D8F0_RLOW_SKP_GEN_SUPPORT_1 BIT10       // HwInit/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_BUSXP1_D8F0_RLOW_SKP_GEN_SUPPORT_0 BIT9        // 1b/1b/x/x Lower SKP OS Generation Supported Speeds Vector
    #define CND003_BUSXP1_D8F0_RSV_6C_8               BIT8        // 0/R/x/x CrossLink Supported
    #define CND003_BUSXP1_D8F0_LKMLS_6                BIT7        // 0b/R/x/x Supported Link Speed Vector Bit 6
    #define CND003_BUSXP1_D8F0_LKMLS_5                BIT6        // 0b/R/x/x Supported Link Speed Vector Bit 5
    #define CND003_BUSXP1_D8F0_LKMLS_4                BIT5        // 0b/R/x/x Supported Link Speed Vector Bit 4
    #define CND003_BUSXP1_D8F0_LKMLS_3                BIT4        // 0b/R/x/x Supported Link Speed Vector Bit 3
    #define CND003_BUSXP1_D8F0_LKMLS_2                BIT3        // 0/0/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define CND003_BUSXP1_D8F0_LKMLS_1                BIT2        // 0/0/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define CND003_BUSXP1_D8F0_LKMLS_0                BIT1        // 1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define CND003_BUSXP1_D8F0_RSV_6C_0               BIT0        // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_LINK_CTL_2 0x70 // Link Control 2
    #define CND003_BUSXP1_D8F0_CMPPSDEEMPHS   0xF000  // 0/0/x/x Compliance Preset / De-emphasis
    #define CND003_BUSXP1_D8F0_RCMPSOS        BIT11   // 0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define CND003_BUSXP1_D8F0_PMDCMPSET      BIT10   // 0/0/x/x Modified Compliance Pattern Set Bit
    #define CND003_BUSXP1_D8F0_TXMGN_2        BIT9    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSXP1_D8F0_TXMGN_1        BIT8    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSXP1_D8F0_TXMGN_0        BIT7    // 0/*0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSXP1_D8F0_SELDEEMPHS     BIT6    // 0/*0/x/x Selectable De-emphasis
    #define CND003_BUSXP1_D8F0_RHATNMSD       BIT5    // 0/1/x/0 Disable Hardware Autonomous Speed
    #define CND003_BUSXP1_D8F0_PCMPSET        BIT4    // 0/0/x/x Enter Compliance
    #define CND003_BUSXP1_D8F0_LKTGLS_3       BIT3    // 0/0/0/0 Target Link Speed Bit 3
    #define CND003_BUSXP1_D8F0_LKTGLS_2       BIT2    // 0/0/0/0 Target Link Speed Bit 2
    #define CND003_BUSXP1_D8F0_LKTGLS_1       BIT1    // HwInit/x/1/0 Target Link Speed Bit 1
    #define CND003_BUSXP1_D8F0_LKTGLS_0       BIT0    // HwInit/x/0/0 Target Link Speed Bit 0
#define CND003_BUSXP1_D8F0_LINK_STA_2 0x72 // Link Status 2
    #define CND003_BUSXP1_D8F0_RSV_49     0xFFC0  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_EQREQ      BIT5    // 0/0/x/x Request the Link Equalization Process
    #define CND003_BUSXP1_D8F0_EQCOMPLE3  BIT4    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define CND003_BUSXP1_D8F0_EQCOMPLE2  BIT3    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define CND003_BUSXP1_D8F0_EQCOMPLE1  BIT2    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define CND003_BUSXP1_D8F0_EQCOMPLE   BIT1    // 0/0/x/x Transmitter Equalization Procedure Completed
    #define CND003_BUSXP1_D8F0_CURDEEMPHS BIT0    // 0/0/x/x Current Link De-emphasis Level
#define CND003_BUSXP1_D8F0_SLOT_CAPS_2 0x74 // Slot Capabilities 2
    #define CND003_BUSXP1_D8F0_RSV_50 D8F0_SLOT_CAPS_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_SLOT_CTL_2 0x78 // Slot Control 2
    #define CND003_BUSXP1_D8F0_RSV_51 D8F0_SLOT_CTL_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_SLOT_STA_2 0x7A // Slot Status 2
    #define CND003_BUSXP1_D8F0_RSV_52 D8F0_SLOT_STA_2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_VEN_CTL 0x7C // Vendor Control
    #define CND003_BUSXP1_D8F0_RSV_7C         0xFFFFFFFC  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_DID_RID_LOCK   BIT1        // 0/0/x/x Reserved
    #define CND003_BUSXP1_D8F0_VID_LOCK       BIT0        // HwInit/x/x/x Reserved
#define CND003_BUSXP1_D8F0_PM_CAPS 0xA0 // Power Management Capabilities
    #define CND003_BUSXP1_D8F0_PMCPME     0xF8000000              // 11001b/19h/x/x PME Support
    #define CND003_BUSXP1_D8F0_PMCD2S     BIT26                   // 0/0/x/x D2 Support
    #define CND003_BUSXP1_D8F0_PMCD1S     BIT25                   // 0/0/x/x D1 Support
    #define CND003_BUSXP1_D8F0_PMCAUXC    (BIT22 + BIT23 + BIT24) // 0/0/x/x AUX Current
    #define CND003_BUSXP1_D8F0_PMCDSI     BIT21                   // 1b/1/x/x Device Specific Initialization
    #define CND003_BUSXP1_D8F0_RSV_53     (BIT19 + BIT20)         // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_TBD_34     (BIT16 + BIT17 + BIT18) // 011b/R/x/x Version
    #define CND003_BUSXP1_D8F0_TBD_35     0xFF00                  // B0h/R/x/x Next Capability Pointer
    #define CND003_BUSXP1_D8F0_TBD_36     0xFF                    // 01h/R/x/x Capability ID
#define CND003_BUSXP1_D8F0_PM_STA_CTL 0xA4 // Power Management Status / Control
    #define CND003_BUSXP1_D8F0_TBD_37     0xFF000000      // 0/R/x/x Power Management Data
    #define CND003_BUSXP1_D8F0_TBD_38     BIT23           // 0/x/x/x Enable Bus Power / Clock Control
    #define CND003_BUSXP1_D8F0_TBD_39     BIT22           // 0/x/x/x B2 / B3 Support
    #define CND003_BUSXP1_D8F0_RSV_54     0x3F0000        // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_PMESD      BIT15           // 0/0/x/x PME Status
    #define CND003_BUSXP1_D8F0_TBD_40     (BIT13 + BIT14) // 0/R/x/x Data Scale
    #define CND003_BUSXP1_D8F0_TBD_41     0x1E00          // 0/R/x/x Data Select
    #define CND003_BUSXP1_D8F0_PMEEN      BIT8            // 0/0/x/x PME Enable
    #define CND003_BUSXP1_D8F0_RSV_55     0xF0            // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_NOSOFTRST  BIT3            // 1b/1b/x/x No_Soft_Reset
    #define CND003_BUSXP1_D8F0_RSV_55_2   BIT2            // 0/0/x/x Reserved
    #define CND003_BUSXP1_D8F0_PWSD       (BIT0 + BIT1)   // 00b/0/x/x Power State
#define CND003_BUSXP1_D8F0_MSI_CAP_SUPPORT 0xB0 // MSI Capability Support
    #define CND003_BUSXP1_D8F0_RSV_56     0xFE000000              // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_TBD_42     BIT24                   // 1b/1/x/x Supports Per-vector Masking Capability
    #define CND003_BUSXP1_D8F0_TBD_43     BIT23                   // 1b/1/x/x Supports 64-bit Message Address Only
    #define CND003_BUSXP1_D8F0_RMSINUM    (BIT20 + BIT21 + BIT22) // 000b/0/x/x Multiple Message Enable
    #define CND003_BUSXP1_D8F0_RMSICAP    (BIT17 + BIT18 + BIT19) // 011b/011b/x/x Multiple Message Capable 
    #define CND003_BUSXP1_D8F0_RMSIEN     BIT16                   // 0/0/x/x MSI Enable
    #define CND003_BUSXP1_D8F0_TBD_44     0xFF00                  // E0h/R/x/x Next Capability Pointer
    #define CND003_BUSXP1_D8F0_TBD_45     0xFF                    // 05h/R/x/x Capability ID
#define CND003_BUSXP1_D8F0_SYS_SPECIFIED_MSG_ADR_LOW 0xB4 // System-specified Message Address  Low
    #define CND003_BUSXP1_D8F0_RMSIA_31_2 0xFFFFFFFC      // 0/0/x/x System-specified Message Address Bit [31:2]
    #define CND003_BUSXP1_D8F0_TBD_46     (BIT0 + BIT1)   // 0/R/x/x System-specified Message Address Bit [1:0]
#define CND003_BUSXP1_D8F0_SYS_SPECIFIED_MSG_ADR_HIGH 0xB8 // System-specified Message Address High
    #define CND003_BUSXP1_D8F0_RMSIA_63_32 D8F0_SYS_SPECIFIED_MSG_ADR_HIGH // 0/0/x/x System-specified Message Address Bit [63:32]
#define CND003_BUSXP1_D8F0_MSG_DATA 0xBC // Message Data
    #define CND003_BUSXP1_D8F0_RMSID D8F0_MSG_DATA // 0/0/x/x Message Data
#define CND003_BUSXP1_D8F0_RESERVED_Z1 0xBE // Reserved
    #define CND003_BUSXP1_D8F0_RSV_BFBE D8F0_RESERVED_Z1 // 0/x/x/x Reserved
#define CND003_BUSXP1_D8F0_MSG_MASK_CTL 0xC0 // Message Mask Control
    #define CND003_BUSXP1_D8F0_RSV_57                 0xFFFFFF00  // 0/0/x/x Reserved
    #define CND003_BUSXP1_D8F0_RMSIMSK_NONFATALERR    BIT7        // 0/0/x/x Mask Bit for Non-Fatal Error
    #define CND003_BUSXP1_D8F0_RMSIMSK_FATALERR       BIT6        // 0/0/x/x Mask Bit for Fatal Error
    #define CND003_BUSXP1_D8F0_MSIMSK_CORERR          BIT5        // 0/0/x/x Mask Bit fo Correctable Error
    #define CND003_BUSXP1_D8F0_RMSIMSK_DLSCHG         BIT4        // 0/0/x/x Mask Bit for DL State Change
    #define CND003_BUSXP1_D8F0_RMSIMSK_CMDCPL         BIT3        // 0/0/x/x Mask Bit for Command Complete
    #define CND003_BUSXP1_D8F0_RMSIMSK_PREDET         BIT2        // 0/0/x/x Mask Bit for Present Detect
    #define CND003_BUSXP1_D8F0_RMSIMSK_ATTBTNPRESS    BIT1        // 0/0/x/x Mask Bit for ATTENTION Button Pressed
    #define CND003_BUSXP1_D8F0_RMSIMSK_LKBWCHG        BIT0        // 0/0/x/x Mask Bit for LKBWCHG
#define CND003_BUSXP1_D8F0_MSG_PENDING_STA 0xC4 // Message Pending Status
    #define CND003_BUSXP1_D8F0_RSV_58             0xFFFFFF00  // 0/R/x/x Reserved
    #define CND003_BUSXP1_D8F0_RMSI_NONFATALERR   BIT7        // HwInit/x/x/x Pending Bit for NonFatal Error
    #define CND003_BUSXP1_D8F0_RMSI_FATALERR      BIT6        // HwInit/x/x/x Pending Bit for Fatal Error
    #define CND003_BUSXP1_D8F0_RMSI_CORERR        BIT5        // HwInit/x/x/x Pending Bit for Correctable Error
    #define CND003_BUSXP1_D8F0_RMSI_DLSCHG        BIT4        // HwInit/x/x/x Pending Bit for DL State Change
    #define CND003_BUSXP1_D8F0_RMSI_CMDCPL        BIT3        // HwInit/x/x/x Pending Bit for Command Complete
    #define CND003_BUSXP1_D8F0_RMSI_PREDET        BIT2        // HwInit/x/x/x Pending Bit for Present Detect
    #define CND003_BUSXP1_D8F0_RMSI_ATTBTNPRESS   BIT1        // HwInit/x/x/x Pending Bit for Attention Button Pressed
    #define CND003_BUSXP1_D8F0_RMSI_LKBWCHG       BIT0        // HwInit/x/x/x Pending Bit for LKBWCHG
#define CND003_BUSXP1_D8F0_NEXT_PTR 0xE0 // Next Pointer
    #define CND003_BUSXP1_D8F0_TBD_47 0xFF00  // 0/R/x/x Next Pointer
    #define CND003_BUSXP1_D8F0_TBD_48 0xFF    // 0Dh/R/x/x Capability ID
#define CND003_BUSXP1_D8F0_RESERVED_Z2 0xE2 // Reserved
    #define CND003_BUSXP1_D8F0_TBD_47_1 D8F0_RESERVED_Z2 // 0/R/x/x Reserved
#define CND003_BUSXP1_D8F0_SVID_CTL 0xE4 // Subsystem Vendor ID Control
    #define CND003_BUSXP1_D8F0_TBD_49 D8F0_SVID_CTL // 1106h/1106h/x/x Subsystem Vendor ID
#define CND003_BUSXP1_D8F0_SSID_CTL 0xE6 // Subsystem ID Control
    #define CND003_BUSXP1_D8F0_TBD_53 D8F0_SSID_CTL // 0721h/0721h/x/X Subsystem ID
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
