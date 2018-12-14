//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_BUS_x+2_D0F0_PCIEIF_R100(A3).doc.
#ifndef _IRS_CND003_BUS_X_2_D0F0_PCIEIF_R100_A3__H_
#define _IRS_CND003_BUS_X_2_D0F0_PCIEIF_R100_A3__H_
// D0F0
#define CND003_BUSX2_D0F0_VID 0x0 // Vendor ID
    #define CND003_BUSX2_D0F0_VENDORID_15_0 D0F0_VID // 1D17h/0/x/x Vendor ID
#define CND003_BUSX2_D0F0_DID_D0F0 0x2 // Device ID (D0F0)
    #define CND003_BUSX2_D0F0_DEVID_15_0 D0F0_DID_D0F0 // 0722h/0/x/x Device ID
#define CND003_BUSX2_D0F0_PCI_CMD 0x4 // PCI Command
    #define CND003_BUSX2_D0F0_RSV_0      0xF800  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RINTDIS    BIT10   // 0/0/x/x Interrupt Disable
    #define CND003_BUSX2_D0F0_RSV_1      BIT9    // 0/R/x/x Fast Back-to-back Transaction Enable
    #define CND003_BUSX2_D0F0_RSERR      BIT8    // 0/0/x/x SERR# Enable
    #define CND003_BUSX2_D0F0_RSV_2      BIT7    // 0/R/x/x Address / Data Stepping
    #define CND003_BUSX2_D0F0_RPTYERR    BIT6    // 0/0/x/x Parity Error Response
    #define CND003_BUSX2_D0F0_RSV_3      BIT5    // 0/R/x/x VGA Palette Snooping
    #define CND003_BUSX2_D0F0_RX004_4    BIT4    // 0/0/x/x Memory Write and Invalidate
    #define CND003_BUSX2_D0F0_RX004_3    BIT3    // 0/R/x/x Response to Special Cycle
    #define CND003_BUSX2_D0F0_RMSTR      BIT2    // 0/0/x/x Bus Master Enable
    #define CND003_BUSX2_D0F0_RENMEM     BIT1    // 0/0/x/x Memory Space Enable
    #define CND003_BUSX2_D0F0_RENIO      BIT0    // 0/0/x/x I/O Space Enable
#define CND003_BUSX2_D0F0_PCI_STA 0x6 // PCI Status
    #define CND003_BUSX2_D0F0_SPERRS     BIT15                   // 0/0/x/x Detected Parity Error
    #define CND003_BUSX2_D0F0_SERRS      BIT14                   // 0/0/x/x Signaled System Error
    #define CND003_BUSX2_D0F0_SMABORT    BIT13                   // 0/0/x/x Received Master Abort
    #define CND003_BUSX2_D0F0_STABORTM   BIT12                   // 0/0/x/x Received Target Abort
    #define CND003_BUSX2_D0F0_STABORTS   BIT11                   // 0/0/x/x Signaled Target Abort
    #define CND003_BUSX2_D0F0_RSV_5      (BIT9 + BIT10)          // 0/R/x/x DEVSEL# Timing
    #define CND003_BUSX2_D0F0_SDPERRS    BIT8                    // 0/0/x/x Master Data Parity Error
    #define CND003_BUSX2_D0F0_RSV_6      BIT7                    // 0/R/x/x Capability of Accepting Fast Back-to-back as a Target
    #define CND003_BUSX2_D0F0_RX004_14   BIT6                    // 0/R/x/x User Definable Features
    #define CND003_BUSX2_D0F0_RX004_13   BIT5                    // 0/R/x/x 66 MHz Capable
    #define CND003_BUSX2_D0F0_RCAP       BIT4                    // 1b/R/x/x Capabilities List
    #define CND003_BUSX2_D0F0_SINTSTT    BIT3                    // HwInit/x/x/x Interrupt Status
    #define CND003_BUSX2_D0F0_RSV_7      (BIT0 + BIT1 + BIT2)    // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_REV_ID 0x8 // Revision ID
    #define CND003_BUSX2_D0F0_REVID_7_0 D0F0_REV_ID // 03h/x/x/x Revision Code
#define CND003_BUSX2_D0F0_CLASS_CODE 0x9 // Class Code
    #define CND003_BUSX2_D0F0_TBD_5_23_0 D0F0_CLASS_CODE // 06 0400h/R/x/x Class Code
#define CND003_BUSX2_D0F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_BUSX2_D0F0_RSV_8 D0F0_CACHE_LINE_SIZE // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_MASTER_LATENCY_TIMER 0xD // Master Latency Timer
    #define CND003_BUSX2_D0F0_RSV_9 D0F0_MASTER_LATENCY_TIMER // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_HDR_TYPE_D0F0 0xE // Header Type (D0F0)
    #define CND003_BUSX2_D0F0_RSV_0E D0F0_HDR_TYPE_D0F0 // 01h/x/x/x Header Type Code
#define CND003_BUSX2_D0F0_BIST 0xF // Built In Self Test (BIST)
    #define CND003_BUSX2_D0F0_TBD_7_7    BIT7            // 0/R/x/x BIST Capable
    #define CND003_BUSX2_D0F0_TBD_7_6    BIT6            // 0/R/x/x Start BIST
    #define CND003_BUSX2_D0F0_TBD_7_5    (BIT4 + BIT5)   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_7      0xF             // 0/R/x/x BIST Result
#define CND003_BUSX2_D0F0_LOWER_BASE_ADR 0x10 // Lower Base Address
    #define CND003_BUSX2_D0F0_TBD_8 D0F0_LOWER_BASE_ADR // 0/R/x/x Lower Base Address 
#define CND003_BUSX2_D0F0_UPPER_BASE_ADR 0x14 // Upper Base Address
    #define CND003_BUSX2_D0F0_TBD_9 D0F0_UPPER_BASE_ADR // 0/R/x/x Upper Base Address
#define CND003_BUSX2_D0F0_PRIMARY_BUS_NUM 0x18 // Primary Bus Number
    #define CND003_BUSX2_D0F0_PBN D0F0_PRIMARY_BUS_NUM // 0/0/x/x Primary Bus Number
#define CND003_BUSX2_D0F0_SECONDARY_BUS_NUM 0x19 // Secondary Bus Number
    #define CND003_BUSX2_D0F0_SBN D0F0_SECONDARY_BUS_NUM // 0/0/x/x Secondary Bus Number
#define CND003_BUSX2_D0F0_SUBORDINATE_BUS_NUM 0x1A // Subordinate Bus Number
    #define CND003_BUSX2_D0F0_SSBN D0F0_SUBORDINATE_BUS_NUM // 0/0/x/x Subordinate Bus Number
#define CND003_BUSX2_D0F0_SECONDARY_LATENCY_TIMER 0x1B // Secondary Latency Timer
    #define CND003_BUSX2_D0F0_RX018_31_24 D0F0_SECONDARY_LATENCY_TIMER // 0/R/x/x Secondary Latency Timer
#define CND003_BUSX2_D0F0_IO_BASE 0x1C // I/O Base
    #define CND003_BUSX2_D0F0_RIOBS_15_12    0xF0    // Fh/Fh/x/x I/O Base (AD[15:12] - Inclusive)
    #define CND003_BUSX2_D0F0_TBD_10         0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_BUSX2_D0F0_IO_LIMIT 0x1D // I/O Limit
    #define CND003_BUSX2_D0F0_RIOLM_15_12    0xF0    // 0/0/x/x I/O Limit (AD[15:12] - Inclusive)
    #define CND003_BUSX2_D0F0_TBD_11         0xF     // 0/R/x/x I/O Addressing Capability
#define CND003_BUSX2_D0F0_SECONDARY_STA 0x1E // Secondary Status
    #define CND003_BUSX2_D0F0_SSPERRS        BIT15           // 0/0/x/x Detected Parity Error
    #define CND003_BUSX2_D0F0_SSERRS         BIT14           // 0/0/x/x Received System Error
    #define CND003_BUSX2_D0F0_RX01C_13       BIT13           // 0/R/x/x Received Master Abort
    #define CND003_BUSX2_D0F0_RX01C_12       BIT12           // 0/R/x/x Received Target Abort
    #define CND003_BUSX2_D0F0_SSTABORT       BIT11           // 0/0/x/x Signaled Target Abort
    #define CND003_BUSX2_D0F0_RX01C_26_25    (BIT9 + BIT10)  // 0/R/x/x DEVSEL Timing
    #define CND003_BUSX2_D0F0_SSDPERRS       BIT8            // 0/0/x/x Master Data Parity Error
    #define CND003_BUSX2_D0F0_RX01C_23       BIT7            // 0/R/x/x Fast Back-to-Back Capable
    #define CND003_BUSX2_D0F0_RX01C_22       BIT6            // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX01C_21       BIT5            // 0/R/x/x 66MHz Capability
    #define CND003_BUSX2_D0F0_RX01C_20_16    0x1F            // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_MEM_BASE 0x20 // Memory Base
    #define CND003_BUSX2_D0F0_RM1BS_31_20    0xFFF0  // FFFh/FFFh/x/x Memory Base (AD[31:20] ? Inclusive)
    #define CND003_BUSX2_D0F0_RSV_11         0xF     // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_MEM_LIMIT 0x22 // Memory Limit
    #define CND003_BUSX2_D0F0_RM1LM_31_20    0xFFF0  // 0/0/x/x Memory Limit (AD[31:20] ? Inclusive)
    #define CND003_BUSX2_D0F0_RSV_12         0xF     // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_PREFETCHABLE_MEM_BASE 0x24 // Prefetchable Memory Base
    #define CND003_BUSX2_D0F0_RM2BS_31_20    0xFFF0                  // FFFh/FFFh/x/x Prefetchable Memory Base AD[31:20]
    #define CND003_BUSX2_D0F0_RSV_13         (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_12         BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory Base
#define CND003_BUSX2_D0F0_PREFETCHABLE_MEM_LIMIT 0x26 // Prefetchable Memory Limit
    #define CND003_BUSX2_D0F0_RM2LM_31_20    0xFFF0                  // 0/0/x/x Prefetchable Memory Limit AD[31:20]
    #define CND003_BUSX2_D0F0_RSV_14         (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_13         BIT0                    // 1b/R/x/x 64 Bits Addressing for Prefetchable Memory  Limit
#define CND003_BUSX2_D0F0_PREFETCHABLE_MEM_BASE_UPPER_32_BITS 0x28 // Prefetchable Memory Base Upper 32 bits
    #define CND003_BUSX2_D0F0_RSV_15         0xFFFFFF00  // 0/0/x/x Prefetchable Memory Base Upper bit[63:40]
    #define CND003_BUSX2_D0F0_RM3BS_39_32    0xFF        // 0/0/x/x Prefetchable Memory Base Upper bit[39:32]
#define CND003_BUSX2_D0F0_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS 0x2C // Prefetchable Memory Limit Upper 32 Bits
    #define CND003_BUSX2_D0F0_RSV_16         0xFFFFFF00  // 0/0/x/x Prefetchable Memory Limit Upper Bit[63:40]
    #define CND003_BUSX2_D0F0_RM3LM_39_32    0xFF        // 0/0/x/x Prefetchable Memory Limit Upper Bit[39:32]
#define CND003_BUSX2_D0F0_IO_BASE_UPPER 0x30 // I/O Base Upper
    #define CND003_BUSX2_D0F0_TBD_14 D0F0_IO_BASE_UPPER // 0/R/x/x I/O Base Upper 16 Bits Address
#define CND003_BUSX2_D0F0_IO_BASE_LIMIT 0x32 // I/O Base Limit
    #define CND003_BUSX2_D0F0_TBD_15 D0F0_IO_BASE_LIMIT // 0/R/x/x I/O Limit Upper 16 Bits Address
#define CND003_BUSX2_D0F0_CAP_PTR 0x34 // Capability Pointer
    #define CND003_BUSX2_D0F0_TBD_16 D0F0_CAP_PTR // 40h/40h/x/x Capability Pointer
#define CND003_BUSX2_D0F0_RESERVED 0x35 // Reserved
    #define CND003_BUSX2_D0F0_TBD_16_1 D0F0_RESERVED // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_RESERVED_Z1 0x38 // Reserved
    #define CND003_BUSX2_D0F0_TBD_38_31 D0F0_RESERVED_Z1 // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_INTR_LINE 0x3C // Interrupt Line
    #define CND003_BUSX2_D0F0_RINTLN D0F0_INTR_LINE // 0/0/x/x Interrupt Line
#define CND003_BUSX2_D0F0_INTR_PIN 0x3D // Interrupt Pin
    #define CND003_BUSX2_D0F0_RX03C_15_11    0xF8                    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_17         (BIT0 + BIT1 + BIT2)    // 001b/R/x/x Interrupt Pin
#define CND003_BUSX2_D0F0_BRIDGE_CTL 0x3E // Bridge Control
    #define CND003_BUSX2_D0F0_RSV_17     0xF000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX03C_27   BIT11   // 0/0/x/x Discard Timer SERR# Enable
    #define CND003_BUSX2_D0F0_RX03C_26   BIT10   // 0/R/x/x Discard Timer Status
    #define CND003_BUSX2_D0F0_RX03C_25   BIT9    // 0/0/x/x Secondary Discard Timer
    #define CND003_BUSX2_D0F0_RX03C_24   BIT8    // 0/R/x/x Primary Discard Timer
    #define CND003_BUSX2_D0F0_RX03C_23   BIT7    // 0/R/x/x Fast Back-to-Back Enable
    #define CND003_BUSX2_D0F0_RSRST      BIT6    // 0/0/x/x Secondary Bus Reset
    #define CND003_BUSX2_D0F0_MABMODE    BIT5    // 0/0/x/x Master Abort Mode
    #define CND003_BUSX2_D0F0_RX03C_4    BIT4    // 0/R/x/x Base VGA 16 Bits Decode
    #define CND003_BUSX2_D0F0_RX03C_3    BIT3    // 0/R/x/x VGA Compatible I/O and Memory Address Range
    #define CND003_BUSX2_D0F0_RX03C_2    BIT2    // 0/0/x/x Block/Forward ISA I/O Cycles
    #define CND003_BUSX2_D0F0_RSERRFWD   BIT1    // 0/0/x/x SERR Enable
    #define CND003_BUSX2_D0F0_RX03C_0    BIT0    // 0/0/x/x Parity Error Response Enable
#define CND003_BUSX2_D0F0_PCI_EXPRESS_LIST 0x40 // PCI Express List
    #define CND003_BUSX2_D0F0_TBD_24 0xFF00  // A0h/A0h/x/x Next Pointer
    #define CND003_BUSX2_D0F0_TBD_25 0xFF    // 10h/10h/x/x Capability ID
#define CND003_BUSX2_D0F0_PCI_EXPRESS_CAPS_D0F0 0x42 // PCI Express Capabilities (D0F0)
    #define CND003_BUSX2_D0F0_RSV_42_15  BIT15   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_42_14  BIT14   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_XINTMNO    0x3E00  // 0/0/x/x Interrupt Message Number
    #define CND003_BUSX2_D0F0_RSV_42_8   BIT8    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_XDPTYPE    0xF0    // 0111b/0111/x/x Device / Port Type
    #define CND003_BUSX2_D0F0_PCIE_VER_3 BIT3    // 0/0/x/x Capability Version Bit 3
    #define CND003_BUSX2_D0F0_PCIE_VER_2 BIT2    // 0/0/x/x Capability Version Bit 2
    #define CND003_BUSX2_D0F0_PCIE_VER_1 BIT1    // 1b/1/x/x Capability Version Bit 1
    #define CND003_BUSX2_D0F0_PCIE_VER_0 BIT0    // 0/0/x/x Capability Version Bit 0
#define CND003_BUSX2_D0F0_DEV_CAPS_1 0x44 // Device Capabilities 1
    #define CND003_BUSX2_D0F0_RSV_19         (BIT29 + BIT30 + BIT31) // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_27         BIT28                   // 0/R/x/x Function Level Reset Capability
    #define CND003_BUSX2_D0F0_DCSPL_SCALE_1  BIT27                   // HwInit/x/x/x Captured Slot Power Limit Scale
    #define CND003_BUSX2_D0F0_DCSPL_SCALE_0  BIT26                   // HwInit/x/x/x Captured Slot Power Limit Scale
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_7  BIT25                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_6  BIT24                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_5  BIT23                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_4  BIT22                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_3  BIT21                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_2  BIT20                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_1  BIT19                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_DCSPL_VALUE_0  BIT18                   // HwInit/x/x/x Captured Slot Power Limit Value
    #define CND003_BUSX2_D0F0_RSV_22         (BIT16 + BIT17)         // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RRBERRP        BIT15                   // 1b/1/x/x Role-based Error Reporting
    #define CND003_BUSX2_D0F0_RSV_23         BIT14                   // 0/R/x/x Power Indicator Present
    #define CND003_BUSX2_D0F0_RSV_24         BIT13                   // 0/R/x/x Attention Indicator Present
    #define CND003_BUSX2_D0F0_RSV_25         BIT12                   // 0/R/x/x Attention Button Present
    #define CND003_BUSX2_D0F0_DAL1AL         (BIT9 + BIT10 + BIT11)  // 000b/0/x/x Endpoint L1 Acceptable Latency
    #define CND003_BUSX2_D0F0_RSV_44         (BIT6 + BIT7 + BIT8)    // 0/R/x/x Endpoint L0s Acceptable Latency
    #define CND003_BUSX2_D0F0_DAXTAGF        BIT5                    // 1b/1/x/x Extended Tag Field Supported
    #define CND003_BUSX2_D0F0_RSV_26         (BIT3 + BIT4)           // 0/R/x/x Phantom Functions Supported
    #define CND003_BUSX2_D0F0_DAMPSS         (BIT0 + BIT1 + BIT2)    // 001b/001/x/x Max Payload Size Supported
#define CND003_BUSX2_D0F0_DEV_CTL_1 0x48 // Device Control 1
    #define CND003_BUSX2_D0F0_CONREN     BIT15                   // 0/0/x/x PCI Express to PCI/PCI-X Bridges
    #define CND003_BUSX2_D0F0_DCMRRS     (BIT12 + BIT13 + BIT14) // 010b/010/x/x Max Read Request Size
    #define CND003_BUSX2_D0F0_DCENS      BIT11                   // 0/0/x/x Enable No Snoop
    #define CND003_BUSX2_D0F0_DCAPPME    BIT10                   // 0/x/x/x Auxiliary Power PM Enable
    #define CND003_BUSX2_D0F0_DCPFE      BIT9                    // 0/R/x/x Phantom Functions Enable
    #define CND003_BUSX2_D0F0_DCETFE     BIT8                    // 0/0/x/x Extended Tag Field Enable
    #define CND003_BUSX2_D0F0_DCMPS      (BIT5 + BIT6 + BIT7)    // 0/000/x/x Max Payload Size
    #define CND003_BUSX2_D0F0_DCERO      BIT4                    // 0/0/x/x Enable Relaxed Ordering
    #define CND003_BUSX2_D0F0_DCURRE     BIT3                    // 0/0/x/x Unsupported Request Reporting Enable
    #define CND003_BUSX2_D0F0_DCFERE     BIT2                    // 0/0/x/x Fatal Error Reporting Enable
    #define CND003_BUSX2_D0F0_DCNFERE    BIT1                    // 0/0/x/x Non-Fatal Error Reporting Enable
    #define CND003_BUSX2_D0F0_DCCERE     BIT0                    // 0/0/x/x Correctable Error Reporting Enable
#define CND003_BUSX2_D0F0_DEV_STA_1 0x4A // Device Status 1
    #define CND003_BUSX2_D0F0_RSV_4B 0xFFC0  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_DSTP   BIT5    // HwInit/x/x/x Transactions Pending
    #define CND003_BUSX2_D0F0_DSAPD  BIT4    // 0/R/x/x AUX Power Detected
    #define CND003_BUSX2_D0F0_DSURD  BIT3    // 0/0/x/x Unsupported Request Detected (TL)
    #define CND003_BUSX2_D0F0_DSFED  BIT2    // 0/0/x/x Fatal Error Detected (TL)
    #define CND003_BUSX2_D0F0_DSNFED BIT1    // 0/0/x/x Non-Fatal Error Detected (TL)
    #define CND003_BUSX2_D0F0_DSCED  BIT0    // 0/0/x/x Correctable Error Detected (TL)
#define CND003_BUSX2_D0F0_LINK_CAPS 0x4C // Link Capabilities
    #define CND003_BUSX2_D0F0_LKPN           0xFF000000              // 0/0/x/x Port Number
    #define CND003_BUSX2_D0F0_RSV_29         BIT23                   // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_ASPMOC         BIT22                   // 1b/1b/x/x ASPM Optionality Compliance? This bit must be set to 1b in all Func...
    #define CND003_BUSX2_D0F0_RLBWNTFC       BIT21                   // 0/0/x/x Link Bandwidth Notification Capability
    #define CND003_BUSX2_D0F0_RDL_AR_CAP     BIT20                   // 0/0/x/x Data Link Layer Link Active Reporting Capable
    #define CND003_BUSX2_D0F0_RLCASDERC      BIT19                   // 0/0/x/x Surprise Down Error Reporting Capable
    #define CND003_BUSX2_D0F0_RLCACPM_PE1    BIT18                   // 0/0/x/x Clock Power Management
    #define CND003_BUSX2_D0F0_LKL1EL         (BIT15 + BIT16 + BIT17) // 0/0/x/x L1 Exit Latency
    #define CND003_BUSX2_D0F0_LKL0SE         (BIT12 + BIT13 + BIT14) // 0/0/x/x L0s Exit Latency
    #define CND003_BUSX2_D0F0_LKAPMS         (BIT10 + BIT11)         // 0/0/x/x Active State Link PM (ASPM) Support
    #define CND003_BUSX2_D0F0_LKMLW_5        BIT9                    // 0/0/x/x Maximum Link Width Bit 5
    #define CND003_BUSX2_D0F0_LKMLW_4        BIT8                    // 0/0/x/x Maximum Link Width Bit 4
    #define CND003_BUSX2_D0F0_LKMLW_3        BIT7                    // 0/0/x/x Maximum Link Width Bit 3
    #define CND003_BUSX2_D0F0_LKMLW_2        BIT6                    // 0/0/x/x Maximum Link Width Bit 2
    #define CND003_BUSX2_D0F0_LKMLW_1        BIT5                    // 0/0/x/x Maximum Link Width Bit 1
    #define CND003_BUSX2_D0F0_LKMLW_0        BIT4                    // 1b/1b/x/x Maximum Link Width Bit 0 
    #define CND003_BUSX2_D0F0_LKMAXLS_3      BIT3                    // 0/0/x/x Max Link Speed Bit 3 
    #define CND003_BUSX2_D0F0_LKMAXLS_2      BIT2                    // 0/0/x/x Max Link Speed Bit 2
    #define CND003_BUSX2_D0F0_LKMAXLS_1      BIT1                    // 0/0/x/x Max Link Speed Bit 1
    #define CND003_BUSX2_D0F0_LKMAXLS_0      BIT0                    // 1b/1b/x/x Max Link Speed Bit 0
#define CND003_BUSX2_D0F0_LINK_CTL 0x50 // Link Control
    #define CND003_BUSX2_D0F0_RSV_32     0xF000          // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RLABITEN   BIT11           // 0/0/x/x Enable Link Autonom ous Bandwidth Interrupt
    #define CND003_BUSX2_D0F0_RLBMITEN   BIT10           // 0/0/x/x Enable Link Bandwidth Management Interrupt
    #define CND003_BUSX2_D0F0_RHATNMWD   BIT9            // 0/0/x/0 Hardware Autonomous Width Control
    #define CND003_BUSX2_D0F0_RLCOCPMEN  BIT8            // 0/0/x/x Enable Clock Power Management
    #define CND003_BUSX2_D0F0_LCES       BIT7            // 0/0/0/x Extended Synch
    #define CND003_BUSX2_D0F0_LCCCC      BIT6            // 0/0/x/x Common Clock Configuration
    #define CND003_BUSX2_D0F0_LCRL       BIT5            // 0/0/x/x Retrain Link
    #define CND003_BUSX2_D0F0_LCLD       BIT4            // 0/0/x/x Link Disable
    #define CND003_BUSX2_D0F0_LCRCB      BIT3            // 0/0/x/x Read Completion Boundary
    #define CND003_BUSX2_D0F0_RSV_33     BIT2            // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_LCAPMS     (BIT0 + BIT1)   // 00b/00/x/x Link Active State PM (ASPM) Control
#define CND003_BUSX2_D0F0_LINK_STA 0x52 // Link Status
    #define CND003_BUSX2_D0F0_RLATNMBW   BIT15   // 0/0/x/x Link Autonomous Bandwidth Status
    #define CND003_BUSX2_D0F0_RLBWMNGT   BIT14   // 0/0/x/x Link Bandwidth Management Status
    #define CND003_BUSX2_D0F0_DL_ACTIVE  BIT13   // 0/0/x/x Data Link Layer Link Active
    #define CND003_BUSX2_D0F0_LSSCC      BIT12   // 1b/1b/x/x Slot Clock Configuration
    #define CND003_BUSX2_D0F0_LSLT       BIT11   // 0/0/x/x Link Training
    #define CND003_BUSX2_D0F0_LSTE       BIT10   // 0/0/x/x Training Error
    #define CND003_BUSX2_D0F0_LSNLW      0x3F0   // 01h/01h/x/x Negotiated Link Width Bits[4:0]
    #define CND003_BUSX2_D0F0_LSLS       0xF     // 1h/1h/x/x Current Link Speed
#define CND003_BUSX2_D0F0_DEV_CAPS_2 0x64 // Device Capabilities 2
    #define CND003_BUSX2_D0F0_RSV_64_6   0xFFF00000      // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_ROBFFSP    (BIT18 + BIT19) // 0/R/x/x OBFF Supported
    #define CND003_BUSX2_D0F0_RSV_64_12  0x3F000         // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RLTRSP     BIT11           // 0/R/x/x LTR Mechanism Supported
    #define CND003_BUSX2_D0F0_RSV_64_10  0x7C0           // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RARISP     BIT5            // 0/R/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define CND003_BUSX2_D0F0_TBD_31     BIT4            // 1b/1b/x/x Completion Timeout Disable Supported
    #define CND003_BUSX2_D0F0_TBD_32     0xF             // 0/R/x/x Completion Timeout Ranges Supported
#define CND003_BUSX2_D0F0_DEV_CTL_2 0x68 // Device Control 2
    #define CND003_BUSX2_D0F0_RSV_46     BIT15           // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_ROBFFEN    (BIT13 + BIT14) // 0/R/x/x OBFF Enable
    #define CND003_BUSX2_D0F0_RSV_68_11  (BIT11 + BIT12) // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RLTREN     BIT10           // 0/R/x/x LTR Mechanism Enable
    #define CND003_BUSX2_D0F0_RSV_68_6   0x3C0           // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RARIEN     BIT5            // 0/R/x/x Enable ARI Forwarding
    #define CND003_BUSX2_D0F0_RDISCPLTM  BIT4            // 0/0/0/x Completion Timeout  Disable Control
    #define CND003_BUSX2_D0F0_RCPLTOV    0xF             // 0/0/x/x Completion Timeout Value
#define CND003_BUSX2_D0F0_DEV_STA_2 0x6A // Device Status 2
    #define CND003_BUSX2_D0F0_RSV_47 D0F0_DEV_STA_2 // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_LINK_CAPS_2 0x6C // Link Capabilities 2
    #define CND003_BUSX2_D0F0_RSV_6C_9   0xFFFFFE00  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_CROLINS    BIT8        // 0/0/x/x CrossLink Supported
    #define CND003_BUSX2_D0F0_LKMLS_6    BIT7        // 0/0/x/x Supported Link Speed Vector Bit 6
    #define CND003_BUSX2_D0F0_LKMLS_5    BIT6        // 0/0/x/x Supported Link Speed Vector Bit 5
    #define CND003_BUSX2_D0F0_LKMLS_4    BIT5        // 0/0/x/x Supported Link Speed Vector Bit 4
    #define CND003_BUSX2_D0F0_LKMLS_3    BIT4        // 0/0/x/x Supported Link Speed Vector Bit 3
    #define CND003_BUSX2_D0F0_LKMLS_2    BIT3        // 0/0/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define CND003_BUSX2_D0F0_LKMLS_1    BIT2        // 0/0/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define CND003_BUSX2_D0F0_LKMLS_0    BIT1        // 1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define CND003_BUSX2_D0F0_RSV_6C_0   BIT0        // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_LINK_CTL_2 0x70 // Link Control 2
    #define CND003_BUSX2_D0F0_CMPPSDEEMPHS   0xF000  // 0/0/x/x Compliance Preset / De-emphasis
    #define CND003_BUSX2_D0F0_RCMPSOS        BIT11   // 0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define CND003_BUSX2_D0F0_PMDCMPSET      BIT10   // 0/0/x/x Modified Compliance Pattern Set Bit
    #define CND003_BUSX2_D0F0_TXMGN_2        BIT9    // 0/0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSX2_D0F0_TXMGN_1        BIT8    // 0/0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSX2_D0F0_TXMGN_0        BIT7    // 0/0/x/x Transmit Voltage Margin Setting
    #define CND003_BUSX2_D0F0_SELDEEMPHS     BIT6    // 0/0/x/x Selectable De-emphasis
    #define CND003_BUSX2_D0F0_RHATNMSD       BIT5    // 0/0/x/0 Disable Hardware Autonomous Speed
    #define CND003_BUSX2_D0F0_PCMPSET        BIT4    // 0/0/x/x Enter Compliance
    #define CND003_BUSX2_D0F0_LKTGLS_3       BIT3    // 0/0/0/0 Target Link Speed Bit 3
    #define CND003_BUSX2_D0F0_LKTGLS_2       BIT2    // 0/0/0/0 Target Link Speed Bit 2
    #define CND003_BUSX2_D0F0_LKTGLS_1       BIT1    // 0/0/1/0 Target Link Speed Bit 1
    #define CND003_BUSX2_D0F0_LKTGLS_0       BIT0    // 0/0/1/1 Target Link Speed Bit 0
#define CND003_BUSX2_D0F0_LINK_STA_2 0x72 // Link Status 2
    #define CND003_BUSX2_D0F0_RSV_49     0xFFC0  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_EQREQ      BIT5    // 0/0/x/x Request the Link Equalization Process
    #define CND003_BUSX2_D0F0_EQCOMPLE3  BIT4    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define CND003_BUSX2_D0F0_EQCOMPLE2  BIT3    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define CND003_BUSX2_D0F0_EQCOMPLE1  BIT2    // 0/0/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define CND003_BUSX2_D0F0_EQCOMPLE   BIT1    // 0/0/x/x Transmitter Equalization Procedure Completed
    #define CND003_BUSX2_D0F0_CURDEEMPHS BIT0    // 0/0/x/x Current Link De-emphasis Level
#define CND003_BUSX2_D0F0_VEN_CTL 0x7C // Vendor Control
    #define CND003_BUSX2_D0F0_RSV_7C         0xFFFFFFFE  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_VENDOR_CHOOSE  BIT0        // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_IOCFG 0x80 // IOCFG
    #define CND003_BUSX2_D0F0_VID_LOCK       BIT31       // 0/0/x/x VID_Lock
    #define CND003_BUSX2_D0F0_DID_RID_LOCK   BIT30       // 0/0/x/x DID_RID_Lock
    #define CND003_BUSX2_D0F0_RSV_80         0x3FFFFFFF  // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_PM_CAPS 0xA0 // Power Management Capabilities
    #define CND003_BUSX2_D0F0_PMCPME     0xF8000000              // 11001b/19h/x/x PME Support
    #define CND003_BUSX2_D0F0_PMCD2S     BIT26                   // 0/0/x/x D2 Support
    #define CND003_BUSX2_D0F0_PMCD1S     BIT25                   // 0/0/x/x D1 Support
    #define CND003_BUSX2_D0F0_PMCAUXC    (BIT22 + BIT23 + BIT24) // 0/0/x/x AUX Current
    #define CND003_BUSX2_D0F0_PMCDSI     BIT21                   // 1b/1/x/x Device Specific Initialization
    #define CND003_BUSX2_D0F0_RSV_53     (BIT19 + BIT20)         // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_34     (BIT16 + BIT17 + BIT18) // 011b/011b/x/x Version
    #define CND003_BUSX2_D0F0_TBD_35     0xFF00                  // B0h/B0h/x/x Next Capability Pointer
    #define CND003_BUSX2_D0F0_TBD_36     0xFF                    // 01h/01h/x/x Capability ID
#define CND003_BUSX2_D0F0_PM_STA_CTL 0xA4 // Power Management Status / Control
    #define CND003_BUSX2_D0F0_TBD_37 0xFF000000      // 0/R/x/x Power Management Data
    #define CND003_BUSX2_D0F0_TBD_38 BIT23           // 0/R/x/x Enable Bus Power / Clock Control
    #define CND003_BUSX2_D0F0_TBD_39 BIT22           // 0/R/x/x B2 / B3 Support
    #define CND003_BUSX2_D0F0_RSV_54 0x3F0000        // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_PMESD  BIT15           // 0/0/x/x PME Status
    #define CND003_BUSX2_D0F0_TBD_40 (BIT13 + BIT14) // 0/R/x/x Data Scale
    #define CND003_BUSX2_D0F0_TBD_41 0x1E00          // 0/R/x/x Data Select
    #define CND003_BUSX2_D0F0_PMEEN  BIT8            // 0/x/x/x PME Enable
    #define CND003_BUSX2_D0F0_RSV_55 0xFC            // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_PWSD   (BIT0 + BIT1)   // 00b/0/x/x Power State
#define CND003_BUSX2_D0F0_GUARD_BIT_CTL 0xA8 // Guard Bit Control
    #define CND003_BUSX2_D0F0_RSV_A8     0xFFFE  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_GUADRBIT   BIT0    // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_MSI_CAP_SUPPORT 0xB0 // MSI Capability Support
    #define CND003_BUSX2_D0F0_RSV_56     0xFE000000              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_42     BIT24                   // 1b/1/x/x Supports Per-vector Masking Capability
    #define CND003_BUSX2_D0F0_TBD_43     BIT23                   // 1b/1/x/x Supports 64-bit Message Address Only
    #define CND003_BUSX2_D0F0_RMSINUM    (BIT20 + BIT21 + BIT22) // 000b/0/x/x Multiple Message Enable
    #define CND003_BUSX2_D0F0_RMSICAP    (BIT17 + BIT18 + BIT19) // 000b/0/x/x Multiple Message Capable 
    #define CND003_BUSX2_D0F0_RMSIEN     BIT16                   // 0/0/x/x MSI Enable
    #define CND003_BUSX2_D0F0_TBD_44     0xFF00                  // E0h/E0h/x/x Next Capability Pointer
    #define CND003_BUSX2_D0F0_TBD_45     0xFF                    // 05h/05h/x/x Capability ID
#define CND003_BUSX2_D0F0_SYS_SPECIFIED_MSG_ADR_LOW 0xB4 // System-specified Message Address Low
    #define CND003_BUSX2_D0F0_RMSIA_31_2 0xFFFFFFFC      // 0/0/x/x System-specified Message Address Bit [31:2]
    #define CND003_BUSX2_D0F0_TBD_46     (BIT0 + BIT1)   // 0/R/x/x System-specified Message Address Bit [1:0]
#define CND003_BUSX2_D0F0_SYS_SPECIFIED_MSG_ADR_HIGH 0xB8 // System-specified Message Address High
    #define CND003_BUSX2_D0F0_RMSIA_63_32 D0F0_SYS_SPECIFIED_MSG_ADR_HIGH // 0/0/x/x System-specified Message Address Bit [63:32]
#define CND003_BUSX2_D0F0_MSG_DATA 0xBC // Message Data
    #define CND003_BUSX2_D0F0_RMSID D0F0_MSG_DATA // 0/0/x/x Message Data
#define CND003_BUSX2_D0F0_MSG_MASK_CTL 0xC0 // Message Mask Control
    #define CND003_BUSX2_D0F0_RSV_57     0xFFFFFFFE  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RMSIMSK    BIT0        // 0/0/x/x Mask Bit for Message 0
#define CND003_BUSX2_D0F0_MSG_PENDING_STA 0xC4 // Message Pending Status
    #define CND003_BUSX2_D0F0_RSV_58     0xFFFFFFFE  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RMSIPDNG   BIT0        // HwInit/x/x/x Pending Bit for Message 0
#define CND003_BUSX2_D0F0_NEXT_PTR 0xE0 // Next Pointer
    #define CND003_BUSX2_D0F0_TBD_E0 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_TBD_47 0xFF00      // 0/0/x/x Next Pointer
    #define CND003_BUSX2_D0F0_TBD_48 0xFF        // 0Dh/0Dh/x/x Capability ID
#define CND003_BUSX2_D0F0_SVID_CTL 0xE4 // Subsystem Vendor ID Control
    #define CND003_BUSX2_D0F0_TBD_49 D0F0_SVID_CTL // 1D17h/1D17h/x/x Subsystem Vendor ID
#define CND003_BUSX2_D0F0_SSID_CTL_D0F0 0xE6 // Subsystem ID Control (D0F0)
    #define CND003_BUSX2_D0F0_TBD_50G D0F0_SSID_CTL_D0F0 // 0722h/0722h/x/x Subsystem ID
#define CND003_BUSX2_D0F0_ADVANCED_ERR_REPORTING_ENHANCED_CAP_HDR 0x100 // Advanced Error Reporting Enhanced Capability Header
    #define CND003_BUSX2_D0F0_TBD_54 0xFFF00000  // 160h/160h/x/x Next Capability Offset
    #define CND003_BUSX2_D0F0_TBD_55 0xF0000     // 1h/1h/x/x Capability Version
    #define CND003_BUSX2_D0F0_TBD_56 0xFFFF      // 0001h/0001h/x/x PCI Express Extended Capability ID
#define CND003_BUSX2_D0F0_UNCORRECTABLE_ERR_STA 0x104 // Uncorrectable Error Status
    #define CND003_BUSX2_D0F0_RSV_59     0xFFC00000              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_UEACSVIO   BIT21                   // 0/R/x/x ACS Violation Status (TL)
    #define CND003_BUSX2_D0F0_UESUR      BIT20                   // 0/0/x/x Unsupported Request Error Status (TL)
    #define CND003_BUSX2_D0F0_UESECRC    BIT19                   // 0/0/x/x ECRC Error Status (TL)
    #define CND003_BUSX2_D0F0_UESMTLP    BIT18                   // 0/0/x/x Malformed TLP Status (TL)
    #define CND003_BUSX2_D0F0_UESRO      BIT17                   // 0/0/x/x Receiver Overflow Status (TL)
    #define CND003_BUSX2_D0F0_UESUC      BIT16                   // 0/0/x/x Unexpected Completion Status (TL) *
    #define CND003_BUSX2_D0F0_UESCA      BIT15                   // 0/0/x/x Completer Abort Status (TL)
    #define CND003_BUSX2_D0F0_UESCT      BIT14                   // 0/0/x/x Completion Timeout Status (TL) *
    #define CND003_BUSX2_D0F0_UESFCP     BIT13                   // 0/0/x/x Flow Control Protocol Error Status (TL)
    #define CND003_BUSX2_D0F0_UESPTLP    BIT12                   // 0/0/x/x Poisoned TLP Status (TL) *
    #define CND003_BUSX2_D0F0_RSV_60     0xFC0                   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_104_5  BIT5                    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_104_4  BIT4                    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_61     (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_104_0  BIT0                    // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_UNCORRECTABLE_ERR_MASK 0x108 // Uncorrectable Error Mask
    #define CND003_BUSX2_D0F0_RSV_1100   0xFFC00000              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_UEMACSVIO  BIT21                   // 0/R/x/x ACS Violation Mask (TL)
    #define CND003_BUSX2_D0F0_UEMUR      BIT20                   // 0/0/x/x Unsupported Request Error Mask (TL) *
    #define CND003_BUSX2_D0F0_UEMECRC    BIT19                   // 0/R/x/x ECRC Error Mask (TL)
    #define CND003_BUSX2_D0F0_UEMMTLP    BIT18                   // 0/0/x/x Malformed TLP Mask (TL) *
    #define CND003_BUSX2_D0F0_UEMRO      BIT17                   // 0/0/x/x Receiver Overflow Mask (TL) *
    #define CND003_BUSX2_D0F0_UEMUC      BIT16                   // 0/0/x/x Unexpected Completion Mask (TL) *
    #define CND003_BUSX2_D0F0_UEMCA      BIT15                   // 0/0/x/x Completed Abort Mask (TL)
    #define CND003_BUSX2_D0F0_UEMCT      BIT14                   // 0/0/x/x Completion Timeout Mask (TL) *
    #define CND003_BUSX2_D0F0_UEMFCP     BIT13                   // 0/0/x/x Flow Control Protocol Error Mask (TL) *
    #define CND003_BUSX2_D0F0_UEMPTLP    BIT12                   // 0/0/x/x Poisoned TLP Mask (TL) *
    #define CND003_BUSX2_D0F0_RSV_1101   0xFC0                   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_108_5  BIT5                    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_UEMDLP     BIT4                    // 0/0/x/x Data Link Protocol Error Mask (DLL) *
    #define CND003_BUSX2_D0F0_RSV_62     (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_108_0  BIT0                    // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_UNCORRECTABLE_ERR_SEVERITY 0x10C // Uncorrectable Error Severity
    #define CND003_BUSX2_D0F0_RSV_63     0xFFC00000              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_USVACSVIO  BIT21                   // 0/R/x/x ACS Violation Severity (TL)
    #define CND003_BUSX2_D0F0_USVUR      BIT20                   // 0/0/x/x Unsupported Request Error Severity (TL) *
    #define CND003_BUSX2_D0F0_USVECRC    BIT19                   // 0/R/x/x ECRC Error Severity (TL)
    #define CND003_BUSX2_D0F0_USVMTLP    BIT18                   // 1b/1/x/x Malformed TLP Severity (TL) *
    #define CND003_BUSX2_D0F0_USVRO      BIT17                   // 1b/1/x/x Receiver Overflow Error Severity (TL) *
    #define CND003_BUSX2_D0F0_USVUC      BIT16                   // 0/0/x/x Unexpected Completion Error Severity (TL) *
    #define CND003_BUSX2_D0F0_USVCA      BIT15                   // 0/0/x/x Completed Abort Error Severity (TL)
    #define CND003_BUSX2_D0F0_USVCT      BIT14                   // 0/0/x/x Completion Timeout Error Severity (TL) *
    #define CND003_BUSX2_D0F0_USVFCP     BIT13                   // 1b/1/x/x Flow Control Protocol Error Severity (TL) *
    #define CND003_BUSX2_D0F0_USVPTLP    BIT12                   // 0/0/x/x Poisoned TLP Severity (TL) *
    #define CND003_BUSX2_D0F0_RSV_64     0xFC0                   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_10C_5  BIT5                    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_USVDLP     BIT4                    // 1b/1/x/x Data Link Protocol Error Severity (DLL) *
    #define CND003_BUSX2_D0F0_RSV_65     (BIT1 + BIT2 + BIT3)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_10C_0  BIT0                    // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_CORRECTABLE_ERR_STA 0x110 // Correctable Error Status
    #define CND003_BUSX2_D0F0_RSV_66     0xFFFFC000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RCESANFES  BIT13       // 0/0/x/x Advisory Non-Fatal Error Status
    #define CND003_BUSX2_D0F0_RSV_68     0x1FFF      // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_CORRECTABLE_ERR_MASK 0x114 // Correctable Error Mask
    #define CND003_BUSX2_D0F0_RSV_69     0xFFFFC000              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RCEMANFEM  BIT13                   // 1b/1/x/x Advisory Non-Fatal Error Mask *
    #define CND003_BUSX2_D0F0_CMRTT      BIT12                   // 0/0/x/x Replay Timer Timeout Mask (DLL) *
    #define CND003_BUSX2_D0F0_RSV_70     (BIT9 + BIT10 + BIT11)  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_CMRR       BIT8                    // 0/0/x/x REPLAY_NUM Rollover Mask (DLL) *
    #define CND003_BUSX2_D0F0_CMBDLLP    BIT7                    // 0/0/x/x Bad DLLP Mask (DLL) *
    #define CND003_BUSX2_D0F0_CMBTLP     BIT6                    // 0/0/x/x Bad TLP Mask (DLL) *
    #define CND003_BUSX2_D0F0_RSV_114_5  0x3F                    // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_ADVANCED_ERR_CAPS_AND_CTL 0x118 // Advanced Error Capabilities and Control
    #define CND003_BUSX2_D0F0_RSV_72     0xFFFFFE00  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_ECRCCHKEN  BIT8        // 0/0/x/x ECRC Check Enable (TL)
    #define CND003_BUSX2_D0F0_ECRCCHKCA  BIT7        // 0/R/x/x ECRC Check Capable (TL)
    #define CND003_BUSX2_D0F0_ECRCGENEN  BIT6        // 0/0/x/x ECRC Generation Enable (TL)
    #define CND003_BUSX2_D0F0_ECRCGENCA  BIT5        // 0/R/x/x ECRC Generation Capable (TL)
    #define CND003_BUSX2_D0F0_ECRCFEPTR  0x1F        // 0/0/x/x First Error Pointer (TL)
#define CND003_BUSX2_D0F0_HDR_LOG_1ST_DW 0x11C // Header Log 1st DW
    #define CND003_BUSX2_D0F0_HLR1 D0F0_HDR_LOG_1ST_DW // 0/R/x/x Header Log Register 1st DW
#define CND003_BUSX2_D0F0_HDR_LOG_2ND_DW 0x120 // Header Log 2nd DW
    #define CND003_BUSX2_D0F0_HLR2 D0F0_HDR_LOG_2ND_DW // 0/R/x/x Header Log Register 2nd DW
#define CND003_BUSX2_D0F0_HDR_LOG_3RD_DW 0x124 // Header Log 3rd DW
    #define CND003_BUSX2_D0F0_HLR3 D0F0_HDR_LOG_3RD_DW // 0/R/x/x Header Log Register 3rd DW
#define CND003_BUSX2_D0F0_HDR_LOG_4TH_DW 0x128 // Header Log 4th DW
    #define CND003_BUSX2_D0F0_HLR4 D0F0_HDR_LOG_4TH_DW // 0/R/x/x Header Log Register 4th DW
#define CND003_BUSX2_D0F0_SECONDARY_UNCORRECTABLE_ERR_STA 0x12C // Secondary Uncorrectable Error Status
    #define CND003_BUSX2_D0F0_RSV_12C_14 0xFFFFC000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SEINBES    BIT13       // 0/0/x/x Internal Bridge Error Status (No Header Log)
    #define CND003_BUSX2_D0F0_SESERRS    BIT12       // 0/0/x/x SERR# Assertion Detected (No Header Log)
    #define CND003_BUSX2_D0F0_SEPERRS    BIT11       // 0/0/x/x PERR# Assertion Detected
    #define CND003_BUSX2_D0F0_SEDTDTES   BIT10       // 0/0/x/x Delayed Transaction Discard Timer Expired 
    #define CND003_BUSX2_D0F0_SEUAES     BIT9        // 0/0/x/x Uncorrectable Address Error Status
    #define CND003_BUSX2_D0F0_SEUARES    BIT8        // 0/0/x/x Uncorrectable Attribute Error Status
    #define CND003_BUSX2_D0F0_SEUDES     BIT7        // 0/0/x/x Uncorrectable Data Error Status
    #define CND003_BUSX2_D0F0_SEUSCMDES  BIT6        // 0/0/x/x Uncorrectable Split Completion Message Data 
    #define CND003_BUSX2_D0F0_SEUSCES    BIT5        // 0/0/x/x Unexpected Split Completion Error Status
    #define CND003_BUSX2_D0F0_RSV_12C_4  BIT4        // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SERMABS    BIT3        // 0/0/x/x Received Master-Abort Status
    #define CND003_BUSX2_D0F0_SERTABS    BIT2        // 0/0/x/x Received Target-Abort Status (Optional)
    #define CND003_BUSX2_D0F0_SEMABSCS   BIT1        // 0/0/x/x Master-Abort on Split Completion Status
    #define CND003_BUSX2_D0F0_SETABSCS   BIT0        // 0/0/x/x Target-Abort on Split Completion Status 
#define CND003_BUSX2_D0F0_SECONDARY_UNCORRECTABLE_ERR_MASK 0x130 // Secondary Uncorrectable Error Mask
    #define CND003_BUSX2_D0F0_RSV_130_14 0xFFFFC000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SEINBEM    BIT13       // 0/0/x/x Internal Bridge Error Mask
    #define CND003_BUSX2_D0F0_SESERRM    BIT12       // 1b/1/x/x SERR# Assertion Detected Mask
    #define CND003_BUSX2_D0F0_SEPERRM    BIT11       // 0/0/x/x PERR# Assertion Detected Mask
    #define CND003_BUSX2_D0F0_SEDTDTEM   BIT10       // 1b/1/x/x Delayed Transaction Discard Timer Expired 
    #define CND003_BUSX2_D0F0_SEUAEM     BIT9        // 1b/1/x/x Uncorrectable Address Error Mask
    #define CND003_BUSX2_D0F0_SEUAREM    BIT8        // 1b/1/x/x Uncorrectable Attribute Error Mask
    #define CND003_BUSX2_D0F0_SEUDEM     BIT7        // 1b/1/x/x Uncorrectable Data Error Mask
    #define CND003_BUSX2_D0F0_SEUSCMDEM  BIT6        // 0/0/x/x Uncorrectable Split Completion Message Data 
    #define CND003_BUSX2_D0F0_SEUSCEM    BIT5        // 1b/1/x/x Unexpected Split Completion Error Mask
    #define CND003_BUSX2_D0F0_RSV_130_4  BIT4        // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SERMABM    BIT3        // 1b/1/x/x Received Master-Abort Mask
    #define CND003_BUSX2_D0F0_SERTABM    BIT2        // 0/0/x/x Received Target-Abort Mask (Optional)
    #define CND003_BUSX2_D0F0_SEMABSCM   BIT1        // 0/0/x/x Master-Abort on Split Completion Mask
    #define CND003_BUSX2_D0F0_SETABSCM   BIT0        // 0/0/x/x Target-Abort on Split Completion Mask 
#define CND003_BUSX2_D0F0_SECONDARY_UNCORRECTABLE_ERR_SEVERITY 0x134 // Secondary Uncorrectable Error Severity
    #define CND003_BUSX2_D0F0_RSV_134_14 0xFFFFC000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SEINBEV    BIT13       // 0/0/x/x Internal Bridge Error Severity
    #define CND003_BUSX2_D0F0_SESERRV    BIT12       // 1b/1/x/x SERR# Assertion Detected Severity 
    #define CND003_BUSX2_D0F0_SEPERRV    BIT11       // 0/0/x/x PERR# Assertion Detected Severity
    #define CND003_BUSX2_D0F0_SEDTDTEV   BIT10       // 0/0/x/x Delayed Transaction Discard Timer Expired 
    #define CND003_BUSX2_D0F0_SEUAEV     BIT9        // 1b/1/x/x Uncorrectable Address Error Severity
    #define CND003_BUSX2_D0F0_SEUAREV    BIT8        // 1b/1/x/x Uncorrectable Attribute Error Severity
    #define CND003_BUSX2_D0F0_SEUDEV     BIT7        // 0/0/x/x Uncorrectable Data Error Severity
    #define CND003_BUSX2_D0F0_SEUSCMDEV  BIT6        // 1b/1/x/x Uncorrectable Split Completion Message Data 
    #define CND003_BUSX2_D0F0_SEUSCEV    BIT5        // 0/0/x/x Unexpected Split Completion Error Severity
    #define CND003_BUSX2_D0F0_RSV_134_4  BIT4        // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SERMABV    BIT3        // 0/0/x/x Received Master-Abort Severity
    #define CND003_BUSX2_D0F0_SERTABV    BIT2        // 0/0/x/x Received Target-Abort Severity (Optional)
    #define CND003_BUSX2_D0F0_SEMABSCV   BIT1        // 0/0/x/x Master-Abort on Split Completion Severity
    #define CND003_BUSX2_D0F0_SETABSCV   BIT0        // 0/0/x/x Target-Abort on Split Completion Severity
#define CND003_BUSX2_D0F0_SECONDARY_ERR_CAPS_AND_CTL 0x138 // Secondary Error Capabilities and Control
    #define CND003_BUSX2_D0F0_RSV_138_5  0xFFFFFFE0  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SEUFEPT    0x1F        // 0/R/x/x Secondary Uncorrectable First Error Pointer
#define CND003_BUSX2_D0F0_SECONDARY_HDR_LOG_REG_0 0x140 // Secondary Header Log Register 0
    #define CND003_BUSX2_D0F0_SETAH_35_4 D0F0_SECONDARY_HDR_LOG_REG_0 // 0/R/x/x Transaction Attribute
#define CND003_BUSX2_D0F0_SECONDARY_HDR_LOG_REG_1 0x144 // Secondary Header Log Register 1
    #define CND003_BUSX2_D0F0_SETAH_3_0  0xF0000000  // 0/R/x/x Transaction Attribute
    #define CND003_BUSX2_D0F0_SECOMFAP   0xF000000   // 0/R/x/x Transaction Command Lower
    #define CND003_BUSX2_D0F0_SECOMSAP   0xF00000    // 0/R/x/x Transaction Command Upper
    #define CND003_BUSX2_D0F0_RSV_144_19 0xFFFFF     // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_SECONDARY_HDR_LOG_REG_2 0x148 // Secondary Header Log Register 2
    #define CND003_BUSX2_D0F0_SEADDFAPA D0F0_SECONDARY_HDR_LOG_REG_2 // 0/R/x/x Transaction Address
#define CND003_BUSX2_D0F0_SECONDARY_HDR_LOG_REG_3 0x14C // Secondary Header Log Register 3
    #define CND003_BUSX2_D0F0_SEADDSAPA D0F0_SECONDARY_HDR_LOG_REG_3 // 0/R/x/x Transaction Address
#define CND003_BUSX2_D0F0_VIRTUAL_CHN_ENHANCED_CAP 0x160 // Virtual Channel Enhanced Capability
    #define CND003_BUSX2_D0F0_RX140_31_20    0xFFF00000  // 0/0/x/x Next Capability Offset
    #define CND003_BUSX2_D0F0_RX140_19_16    0xF0000     // 1h/1h/x/x Capability Version
    #define CND003_BUSX2_D0F0_RX140_15_0     0xFFFF      // 0002h/0002h/x/x PCI Express Extended Capability ID
#define CND003_BUSX2_D0F0_PORT_VC_CAP_1 0x164 // Port VC Capability 1
    #define CND003_BUSX2_D0F0_RX144_31_12    0xFFFFF000              // 0/x/x/x Reserved
    #define CND003_BUSX2_D0F0_RX144_11_10    (BIT10 + BIT11)         // 0/R/x/x Port Arbitration Table Entry Size
    #define CND003_BUSX2_D0F0_RX144_9_8      (BIT8 + BIT9)           // 0/R/x/x Reference Clock
    #define CND003_BUSX2_D0F0_RX144_7        BIT7                    // 0/x/x/x Reserved
    #define CND003_BUSX2_D0F0_VCALPEC_2_0    (BIT4 + BIT5 + BIT6)    // 0/R/x/x Low Priority Extended VC Count
    #define CND003_BUSX2_D0F0_RX144_3        BIT3                    // 0/x/x/x Reserved
    #define CND003_BUSX2_D0F0_VCAEVCC_2_0    (BIT0 + BIT1 + BIT2)    // 0/0/x/x Extended VC Count
#define CND003_BUSX2_D0F0_PORT_VC_CAP_2 0x168 // Port VC Capability 2
    #define CND003_BUSX2_D0F0_RX148_31_24    0xFF000000  // 0/R/x/x VC Arbitration Table Offset
    #define CND003_BUSX2_D0F0_RX148_23_8     0xFFFF00    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX148_7_0      0xFF        // 0/0/x/x VC Arbitration Capability
#define CND003_BUSX2_D0F0_PORT_VC_CTL 0x16C // Port VC Control
    #define CND003_BUSX2_D0F0_RX14C_15_4 0xFFF0                  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX14C_3_1  (BIT1 + BIT2 + BIT3)    // 0/R/x/x VC Arbitration Select
    #define CND003_BUSX2_D0F0_RX14C_0    BIT0                    // 0/R/x/x Load VC Arbitration Table
#define CND003_BUSX2_D0F0_PORT_VC_STA 0x16E // Port VC Status
    #define CND003_BUSX2_D0F0_RX14C_31_17    0xFFFE  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX14C_16       BIT0    // 0/R/x/x VC Arbitration Table Status
#define CND003_BUSX2_D0F0_VC0_RESRC_CAP 0x170 // VC0 Resource Capability
    #define CND003_BUSX2_D0F0_RX150_31_24    0xFF000000  // 00h/R/x/x Port Arbitration Table Offset (VC0)
    #define CND003_BUSX2_D0F0_RX150_23       BIT23       // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_VCRAMTS0_6_0   0x7F0000    // 0/R/x/x Maximum Time Slots (TL)
    #define CND003_BUSX2_D0F0_VCRARST0       BIT15       // 0/R/x/x Reject Snoop Transactions
    #define CND003_BUSX2_D0F0_RX150_14       BIT14       // 0/R/x/x Undefined
    #define CND003_BUSX2_D0F0_RX150_13_8     0x3F00      // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX150_7_0      0xFF        // 0/R/x/x Port Arbitration Capability
#define CND003_BUSX2_D0F0_VC0_RESRC_CTL 0x174 // VC0 Resource Control
    #define CND003_BUSX2_D0F0_VCROEN0        BIT31                   // 1b/1b/x/x VC Enable
    #define CND003_BUSX2_D0F0_RX154_30_27    0x78000000              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_VCROID0_2_0    (BIT24 + BIT25 + BIT26) // 0/R/x/x VC ID
    #define CND003_BUSX2_D0F0_RX154_23_20    0xF00000                // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RX154_19_17    (BIT17 + BIT18 + BIT19) // 0/0/x/x Port Arbitration Select
    #define CND003_BUSX2_D0F0_RX154_16       BIT16                   // 0/R/x/x Load Port Arbitration Table
    #define CND003_BUSX2_D0F0_RX154_15_8     0xFF00                  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_VCROMAP0_7_1   0xFE                    // 7Fh/7Fh/7Fh/7Fh TC1/TC2/TC3/TC4/TC5/TC6/TC7 Mapping to VC0
    #define CND003_BUSX2_D0F0_VCROMAP0_0     BIT0                    // 1b/R/x/x TC0 Mapping to VC0
#define CND003_BUSX2_D0F0_VC0_RESRC_STA 0x178 // VC0 Resource Status
    #define CND003_BUSX2_D0F0_RX158_31_18    0xFFFC0000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_VCRSNP0        BIT17       // HwInit/x/x/x VC Negotiation Pending (TL)
    #define CND003_BUSX2_D0F0_RX158_16       BIT16       // 0/R/x/x Port Arbitration Table Status
    #define CND003_BUSX2_D0F0_RX158_15_0     0xFFFF      // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_FOR_ECO_VDD_DOMAIN1 0x180 // FOR ECO VDD Domain1
    #define CND003_BUSX2_D0F0_ECOVDD_RES1 D0F0_FOR_ECO_VDD_DOMAIN1 // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_FOR_ECO_VSUS_DOMAIN1 0x184 // FOR ECO VSUS Domain1
    #define CND003_BUSX2_D0F0_ECOVSUS_RES1 D0F0_FOR_ECO_VSUS_DOMAIN1 // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_COMPLETION_TIMEOUT_CTL 0x188 // Completion Timeout Control
    #define CND003_BUSX2_D0F0_RPHYRSTMER BIT7            // 0/0/x/x C2P Completion Timeout Method When PHY Retrains or Configures
    #define CND003_BUSX2_D0F0_RX1A8_6    BIT6            // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RCFGRTYTIM (BIT4 + BIT5)   // 00b/00/00/x Downstream Configuration Retry Request Timing after Receiving CRS...
    #define CND003_BUSX2_D0F0_RX1A8_3_2  (BIT2 + BIT3)   // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RCFGTM     (BIT0 + BIT1)   // 01b/01/01/x Configuration Request Timeout Timer
#define CND003_BUSX2_D0F0_CRS_RETRY_CTL 0x189 // CRS Retry Control
    #define CND003_BUSX2_D0F0_RX1A9_7_1  0xFE    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RRTYCRSEN  BIT0    // 0/0/0/x Enable CRS Retry Mechanism
#define CND003_BUSX2_D0F0_UPSTREAM_PERFORMANCE_CTL_2 0x18A // Upstream Performance Control 2
    #define CND003_BUSX2_D0F0_RX1AA_7    BIT7            // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RPHFCUEN   BIT6            // 1b/1/x/1 UpdateFC-P Generation to The Endpoint for Upstream Write TLPs 
    #define CND003_BUSX2_D0F0_RX1AA_5_4  BIT5            // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RTANBYPASS BIT4            // 1b/1/x/x TA Path Enable
    #define CND003_BUSX2_D0F0_RRTYQEMPNB (BIT2 + BIT3)   // 00b/00/00/x Number of TLPs in Retry Buffer Header Queue for the Condition of ...
    #define CND003_BUSX2_D0F0_RCPL2MERGE BIT1            // 0/0/0/x The 1st and 2nd Completion Merge Control for PCI-to-CPU Read (P2CR)
    #define CND003_BUSX2_D0F0_RMSI_MULV  BIT0            // 0/0/0/0 Multi-vector MSI Data Support
#define CND003_BUSX2_D0F0_TRANS_BACKUP_REGS 0x18B // TRANS Backup Registers
    #define CND003_BUSX2_D0F0_RBAK_DLRXACT           BIT7    // 0/R/x/x Backup UPECLK2X?s Behavior to Original Design in PEXC 
    #define CND003_BUSX2_D0F0_RBAK_MSG_NA            BIT6    // 0/R/x/x Bug Fixing
    #define CND003_BUSX2_D0F0_RDIS_MESC_WK           BIT5    // 0/R/x/x PCIE Wakeup C4P Control
    #define CND003_BUSX2_D0F0_RUPCPL_DWPTR_RST       BIT4    // 0/R/x/x UP CPL Backup for Link Downstream
    #define CND003_BUSX2_D0F0_TRANS_RSV_REG_1_3_0    0xF     // 0/R/x/x TRANS Reserve Registers
#define CND003_BUSX2_D0F0_TRANS_RTA_PREFETCH_REGS 0x18C // TRANS RTA PREFETCH Registers
    #define CND003_BUSX2_D0F0_RX1AD_7_5  (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RTA_PFEN   BIT4                    // 0/0/0/0 TRANS RTA Prefetch enable Registers
    #define CND003_BUSX2_D0F0_RTA_PFCNT  (BIT2 + BIT3)           // 0/0/0/0 TRANS RTA PFTCNT Registers
    #define CND003_BUSX2_D0F0_RTA_PFTRIG (BIT0 + BIT1)           // 0/0/0/0 TRANS RTA PFTRIG Registers
#define CND003_BUSX2_D0F0_MSG_PENDING_STA_Z1 0x18D // Message Pending Status
    #define CND003_BUSX2_D0F0_RSV_1AD D0F0_MSG_PENDING_STA_Z1 // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_MSG_PENDING_STA_Z2 0x18E // Message Pending Status
    #define CND003_BUSX2_D0F0_RSV_1AE D0F0_MSG_PENDING_STA_Z2 // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_MSG_PENDING_STA_Z3 0x18F // Message Pending Status
    #define CND003_BUSX2_D0F0_RSV_1AF D0F0_MSG_PENDING_STA_Z3 // 0/R/x/x Reserved
#define CND003_BUSX2_D0F0_TL_DYNAMIC_CLK_CTL_I 0x190 // TL Dynamic Clock Control I
    #define CND003_BUSX2_D0F0_RDYNPMUPCPL    BIT7    // 0/0/x/1 Upstream Completion Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMUPNP     BIT6    // 0/0/x/1 Upstream Non-Posted Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMUPP      BIT5    // 0/0/x/1 Upstream Posted Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMUP       BIT4    // 0/0/x/1 Upstream Arbitration Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMDNCPL    BIT3    // 0/0/x/1 Downstream Completion Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMDNNP     BIT2    // 0/0/x/1 Downstream Non-Posted Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMDNP      BIT1    // 0/0/x/1 Downstream Posted Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMDN       BIT0    // 0/0/x/1 Downstream Dispatch Controller Dynamic Clock Enable.
#define CND003_BUSX2_D0F0_TL_DYNAMIC_CLK_CTL_II 0x191 // TL Dynamic Clock Control II
    #define CND003_BUSX2_D0F0_RSV_1A5    0xF8    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RHRDY      BIT2    // 0/0/x/x FOR DISCARD TLP TAG
    #define CND003_BUSX2_D0F0_RDYNPMPME  BIT1    // 0/0/x/1 Event Controller Dynamic Clock Enable.
    #define CND003_BUSX2_D0F0_RDYNPMFC   BIT0    // 0/0/x/1 Flow Control Dynamic Clock Enable.
#define CND003_BUSX2_D0F0_TRANSACTION_LAYER_CTL 0x192 // Transaction Layer Control
    #define CND003_BUSX2_D0F0_RDNALLCRDINF   BIT7    // 0/0/x/x Downstream All Type of Flow Control Credits are Infinite
    #define CND003_BUSX2_D0F0_RDLDNRSTTRF    BIT6    // 1b/1/x/x DL_Down Resets Traffic Control Interface Logic
    #define CND003_BUSX2_D0F0_RCFGRFLSHPW    BIT5    // 1b/1/x/x Configuration Read (to PCIe Capability) Completion Flushes Upstream ...
    #define CND003_BUSX2_D0F0_RTOTESTEN      BIT4    // 0/0/x/x Timeout Mechanism Simulation Test Mode Enable
    #define CND003_BUSX2_D0F0_RLOCKEN        BIT3    // 0/0/x/x Locked Cycle Enable
    #define CND003_BUSX2_D0F0_RUPNPCHOP      BIT2    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RDNCPLCRDINF   BIT1    // 1b/1/x/x Endpoint Advertise Infinite Credit
    #define CND003_BUSX2_D0F0_RDNCPLPRO      BIT0    // 1b/1/x/x Downstream Relax Ordering between Completion and Posted Request
#define CND003_BUSX2_D0F0_COMPLETION_TIMEOUT_VALUE_OF_SMALL_RANGE 0x193 // Completion Timeout Value of Small Range
    #define CND003_BUSX2_D0F0_RCPLTOVS D0F0_COMPLETION_TIMEOUT_VALUE_OF_SMALL_RANGE // 20h/20h/x/x Completion Timeout Value of Small Range
#define CND003_BUSX2_D0F0_COMPLETION_TIMEOUT_VALUE_OF_LARGE_RANGE 0x194 // Completion Timeout Value of Large Range
    #define CND003_BUSX2_D0F0_RCPLTOVL D0F0_COMPLETION_TIMEOUT_VALUE_OF_LARGE_RANGE // 50h/50h/x/x Completion Timeout Value of Large Range 
#define CND003_BUSX2_D0F0_PME_TIMEOUT_VALUE 0x195 // PME Timeout Value
    #define CND003_BUSX2_D0F0_RPMETOV D0F0_PME_TIMEOUT_VALUE // 64h/64h/x/x PM_PME Timeout Value
#define CND003_BUSX2_D0F0_RESERVED_FOR_ECO 0x196 // Reserved for ECO
    #define CND003_BUSX2_D0F0_REPTLECO   BIT7    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_1B6_6  0x7E    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RND0REQEN  BIT0    // 0/0/x/x PCIe Passes by Upstream Request when Function Is in Non-D0 State
#define CND003_BUSX2_D0F0_RESERVED_Z2 0x197 // Reserved
    #define CND003_BUSX2_D0F0_RSV_1B7_7      (BIT5 + BIT6 + BIT7)    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_1B7_4      BIT4                    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RDNNPNCHK_F3   BIT3                    // 0/0/x/x PCIe TRANS Layer No Check the Downstream NP Request Address whether H...
    #define CND003_BUSX2_D0F0_RDNNPNCHK_F2   BIT2                    // 0/0/x/x PCIe TRANS Layer No Check the Downstream NP Request Address whether H...
    #define CND003_BUSX2_D0F0_RDNNPNCHK_F1   BIT1                    // 0/0/x/x PCIe TRANS Layer No Check the Downstream NP Request Address whether H...
    #define CND003_BUSX2_D0F0_RDNNPNCHK_F0   BIT0                    // 0/0/x/x PCIe TRANS Layer No Check the Downstream NP Request Address whether H...
#define CND003_BUSX2_D0F0_DYNAMIC_CLK_AND_OTHER_INTERNAL_CTL_SIGNALS 0x198 // Dynamic Clock and other Internal Control Signals
    #define CND003_BUSX2_D0F0_RDYNPM         BIT7    // 0/0/x/1 Global Dynamic Clock Enable
    #define CND003_BUSX2_D0F0_RPEPM          BIT6    // 0/0/x/1 EPXC Power Management Control Enable
    #define CND003_BUSX2_D0F0_RPMUDMCLK      BIT5    // 0/0/x/1 PMU Dynamic Clock Enable
    #define CND003_BUSX2_D0F0_DBGMODE        BIT4    // 0/0/x/1 Debug Mode for Test
    #define CND003_BUSX2_D0F0_RDYNPMSUS      BIT3    // 0/0/x/1 PCIEIF POWELL  Dynamic Clock Enable
    #define CND003_BUSX2_D0F0_RCLKREQ_ENB    BIT2    // 0/0/x/1 Reserved
    #define CND003_BUSX2_D0F0_RDYNPMMSG      BIT1    // 0/0/x/1 EP_MSGC Dynamic Clock Enable
    #define CND003_BUSX2_D0F0_RDYNPMCFG      BIT0    // 0/0/x/1 PCIEIF IOE CFG Dynamic Clock Enable
#define CND003_BUSX2_D0F0_SHADOW_AND_PRIORITY_CTL 0x199 // Shadow and Priority Control
    #define CND003_BUSX2_D0F0_RCHGID         BIT7    // 0/0/x/x Change SID
    #define CND003_BUSX2_D0F0_RSHADOWEN      BIT6    // 0/0/x/x Shadow Enable
    #define CND003_BUSX2_D0F0_RCFGMFRP       BIT5    // 0/0/x/x Report error or not when type0 cfg cycle header decode not sync with ...
    #define CND003_BUSX2_D0F0_RHDRCFGTYPE    BIT4    // 0/0/x/x Decode Type 1 CFG Use Bus Nnumber or Header
    #define CND003_BUSX2_D0F0_RNPPCPL        BIT3    // 0/0/x/x Downstream Non-posted and CPL Priority If They Come at the Same Time
    #define CND003_BUSX2_D0F0_RSV_1B9_2      BIT2    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_1B9_1      BIT1    // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_1B9_0      BIT0    // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_TRANSACTION_LAYER_CTL_2 0x19A // Transaction Layer Control 2
    #define CND003_BUSX2_D0F0_RPCIEIFNPPIPE  BIT7    // 0/0/x/x Downstream Non-post Cycle PIPE Control Enable 
    #define CND003_BUSX2_D0F0_RSV_19A_6      0x7F    // 0/0/x/x Reserved
#define CND003_BUSX2_D0F0_SHADOW_HIGH_DW_REG 0x1A0 // Shadow High DW Register
    #define CND003_BUSX2_D0F0_RSHADOW7   0xFF000000  // 0/0/x/x Shadow Register Byte 7
    #define CND003_BUSX2_D0F0_RSHADOW6   0xFF0000    // 0/0/x/x Shadow Register Byte 6
    #define CND003_BUSX2_D0F0_RSHADOW5   0xFF00      // 0/0/x/x Shadow Register Byte 5
    #define CND003_BUSX2_D0F0_RSHADOW4   0xFF        // 0/0/x/x Shadow Register Byte 4
#define CND003_BUSX2_D0F0_SHADOW_LOW_DW_REG 0x1A4 // Shadow Low DW Register
    #define CND003_BUSX2_D0F0_RSHADOW3   0xFF000000  // 0/0/x/x Shadow Register Byte 3
    #define CND003_BUSX2_D0F0_RSHADOW2   0xFF0000    // 0/0/x/x Shadow Register Byte 2
    #define CND003_BUSX2_D0F0_RSHADOW1   0xFF00      // 0/0/x/x Shadow Register Byte 1
    #define CND003_BUSX2_D0F0_RSHADOW0   0xFF        // 0/0/x/x Shadow Register Byte 0
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_0 0x1A8 // Shadow Register Byte 0
    #define CND003_BUSX2_D0F0_RSV_1A8_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE0EN  BIT20       // 0/0/x/x Shadow Register Byte 0 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL0   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR0  0xFFF       // 0/0/x/x Shadow Register Byte 0 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_1 0x1AC // Shadow Register Byte 1
    #define CND003_BUSX2_D0F0_RSV_1AC_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE1EN  BIT20       // 0/0/x/x Shadow Register Byte 1 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL1   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR1  0xFFF       // 0/0/x/x Shadow Register Byte 1 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_2 0x1B0 // Shadow Register Byte 2
    #define CND003_BUSX2_D0F0_RSV_1B0_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE2EN  BIT20       // 0/0/x/x Shadow Register Byte 2 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL2   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR2  0xFFF       // 0/0/x/x Shadow Register Byte 2 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_3 0x1B4 // Shadow Register Byte 3
    #define CND003_BUSX2_D0F0_RSV_1B4_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE3EN  BIT20       // 0/0/x/x Shadow Register Byte 3 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL3   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR3  0xFFF       // 0/0/x/x Shadow Register Byte 3 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_4 0x1B8 // Shadow Register Byte 4
    #define CND003_BUSX2_D0F0_RSV_1B8_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE4EN  BIT20       // 0/0/x/x Shadow Register Byte 4 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL4   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR4  0xFFF       // 0/0/x/x Shadow Register Byte 4 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_5 0x1BC // Shadow Register Byte 5
    #define CND003_BUSX2_D0F0_RSV_1BC_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE5EN  BIT20       // 0/0/x/x Shadow Register Byte 5 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL5   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR5  0xFFF       // 0/0/x/x Shadow Register Byte 5 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_6 0x1C0 // Shadow Register Byte 6
    #define CND003_BUSX2_D0F0_RSV_1C0_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE6EN  BIT20       // 0/0/x/x Shadow Register Byte 6 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL6   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR6  0xFFF       // 0/0/x/x Shadow Register Byte 6 Address
#define CND003_BUSX2_D0F0_SHADOW_REG_BYTE_7 0x1C4 // Shadow Register Byte 7
    #define CND003_BUSX2_D0F0_RSV_1C4_21     0xFFE00000  // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHAOWBTYE7EN  BIT20       // 0/0/x/x Shadow Register Byte 7 Enable
    #define CND003_BUSX2_D0F0_RSHADOW_VAL7   0xFF000     // 0/0/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHADOW_ADDR7  0xFFF       // 0/0/x/x Shadow register byte 7 address
#define CND003_BUSX2_D0F0_ISO_TRANSACTION_CTL 0x1C8 // ISO Transaction Control
    #define CND003_BUSX2_D0F0_RSV_1C8_3  0xFFFFFFF0              // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RISOEN     BIT3                    // 0/0/x/x TRANS ISO ENABLE Register
    #define CND003_BUSX2_D0F0_RISOTC     (BIT0 + BIT1 + BIT2)    // 111b/111/x/x TRANS ISO TC Register
#define CND003_BUSX2_D0F0_SHADOW_REG_READ_AND_WRITE_CTL 0x1CC // Shadow Register Read And Write Control
    #define CND003_BUSX2_D0F0_RSV_1CC_31 0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSHDREN_B7 BIT15       // 0/0/x/x Shadow Register Read Byte 7 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B6 BIT14       // 0/0/x/x Shadow Register Read Byte 6 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B5 BIT13       // 0/0/x/x Shadow Register Read Byte 5 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B4 BIT12       // 0/0/x/x Shadow Register Read Byte 4 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B3 BIT11       // 0/0/x/x Shadow Register Read Byte 3 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B2 BIT10       // 0/0/x/x Shadow Register Read Byte 2 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B1 BIT9        // 0/0/x/x Shadow Register Read Byte 1 Enable
    #define CND003_BUSX2_D0F0_RSHDREN_B0 BIT8        // 0/0/x/x Shadow Register Read Byte 0 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B7 BIT7        // 0/0/x/x Shadow Register Write Byte 7 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B6 BIT6        // 0/0/x/x Shadow Register Write Byte 6 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B5 BIT5        // 0/0/x/x Shadow Register Write Byte 5 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B4 BIT4        // 0/0/x/x Shadow Register Write Byte 4 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B3 BIT3        // 0/0/x/x Shadow Register Write Byte 3 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B2 BIT2        // 0/0/x/x Shadow Register Write Byte 2 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B1 BIT1        // 0/0/x/x Shadow Register Write Byte 1 Enable
    #define CND003_BUSX2_D0F0_RSHDWEN_B0 BIT0        // 0/0/x/x Shadow Register Write Byte 0 Enable
#define CND003_BUSX2_D0F0_PMC_EXPRESS_MSG_STA 0x1D0 // PMC Express Message Status
    #define CND003_BUSX2_D0F0_RR2AER     BIT7                    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_RSV_146    (BIT4 + BIT5 + BIT6)    // 0/R/x/x Reserved
    #define CND003_BUSX2_D0F0_SSPLDIS    0xF                     // 0/0/x/x Control for Set_Slot_Power_Limit Message
#define CND003_BUSX2_D0F0_RESERVED_Z3 0x1D1 // Reserved
    #define CND003_BUSX2_D0F0_RX1D9_3_0 D0F0_RESERVED_Z3 // 0/R/x/x Reserved
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
