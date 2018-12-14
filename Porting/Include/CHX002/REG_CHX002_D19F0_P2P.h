//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

///
#ifndef REG_CHX002_D19F0_P2P_H
#define REG_CHX002_D19F0_P2P_H
// D19F0
#define D19F0_VID 0x0 // Vendor ID
    #define D19F0_VENDORID D19F0_VID // 1106h/R/x/x VIA Technologies ID Code
#define D19F0_DID 0x2 // Device ID
    #define D19F0_DEVICEID D19F0_DID // 31B8h/R/x/x Device ID
#define D19F0_PCI_CMD 0x4 // PCI Command
    #define D19F0_RFBACK    BIT9            // 0/R/x/x Fast Back-to-Back Cycle Enable
    #define D19F0_RSERR2    BIT8            // 0/x/x/x SERR# Enable
    #define D19F0_RPTYERR1  BIT6            // 0/x/x/x Parity Error Response
    #define D19F0_RMSTR     BIT2            // 0/x/x/x Bus Master
    #define D19F0_RENMEM    BIT1            // 0/x/x/x Memory Space Access
    #define D19F0_RENIO     BIT0            // 0/x/x/x I/O Space Access
#define D19F0_PCI_STA 0x6 // PCI Status
    #define D19F0_VPERRS    BIT15           // 0/0/x/x Detected Parity Error
    #define D19F0_SSERRS    BIT14           // 0/0/x/x Detected SERR#
    #define D19F0_MABORTR   BIT13           // 0/x/x/x Received Master-Abort (Except Special Cycle)
    #define D19F0_TABORTR   BIT12           // 0/R/x/x Received Target-Abort
    #define D19F0_TABORTS   BIT11           // 0/R/x/x Target-Abort Assertion
    #define D19F0_DEVS10    (BIT9 + BIT10)  // 00b/R/x/x DEVSEL# Timing
    #define D19F0_DPERR     BIT8            // 0/0/x/x Master Data Parity Error
    #define D19F0_FBACKS    BIT7            // 0/R/x/x Capable of Accepting Fast Back-to-Back as a Target
#define D19F0_REV_ID 0x8 // Revision ID
#define D19F0_CLASS_CODE 0x9 // Class Code
#define D19F0_LATENCY_TIMER 0xD // Latency Timer
    #define D19F0_MLT_7_3 D19F0_LATENCY_TIMER // 0/R/x/x Latency Timer; Reserved
#define D19F0_HDR_TYPE 0xE // Header Type
#define D19F0_BIST 0xF // Built In Self Test (BIST)
#define D19F0_PRIMARY_BUS_NUM 0x18 // Primary Bus Number
    #define D19F0_VPBN_7_0 D19F0_PRIMARY_BUS_NUM // 0/x/x/x Primary Bus Number
#define D19F0_SECONDARY_BUS_NUM 0x19 // Secondary Bus Number
    #define D19F0_VSBN_7_0 D19F0_SECONDARY_BUS_NUM // 0/x/x/x Secondary Bus Number
#define D19F0_SUBORDINATE_BUS_NUM 0x1A // Subordinate Bus Number
    #define D19F0_VSSBN_7_0 D19F0_SUBORDINATE_BUS_NUM // 0/x/x/x Subordinate Bus Number
#define D19F0_MASTER_LATENCY_TIMER 0x1B // Master Latency Timer
    #define D19F0_MLT_7_0 D19F0_MASTER_LATENCY_TIMER // 0/R/x/x Master Latency Timer
#define D19F0_IO_BASE_ADR 0x1C // IO Base Address
    #define D19F0_RPIOBS_15_12  0xF0    // Fh/x/x/x IO Base Address
#define D19F0_IO_LIMIT_ADR 0x1D // IO Limit Address
    #define D19F0_RPIOLM_15_12  0xF0    // 0/x/x/x IO Limit Address
#define D19F0_SECONDARY_STA_REG_1 0x1E // Secondary Status Register 1
#define D19F0_SECONDARY_STA_REG_2 0x1F // Secondary Status Register 2
    #define D19F0_DPE   BIT7            // 0/0/x/x Detected Parity Error
    #define D19F0_SSE   BIT6            // 0/0/x/x Detected SERR#
    #define D19F0_RMA   BIT5            // 0/x/x/x Received Master-Abort (Except Special Cycle)
    #define D19F0_RTA   BIT4            // 0/0/x/x Received Target-Abort
    #define D19F0_MDPD  BIT0            // 0/0/x/x Master Data Parity Error
#define D19F0_MEM_LIMIT_AND_BASE 0x20 // Memory Limit and Base
    #define D19F0_RPM1LM_31_20  0xFFF00000  // 0/x/x/x Memory Limit [31:20]
    #define D19F0_RPM1BS_31_20  0xFFF0      // FFFh/x/x/x Memory Base [31:20]
#define D19F0_PREFETCHABLE_MEM_LIMIT_AND_BASE 0x24 // Prefetchable Memory Limit and Base
    #define D19F0_RPM2LM_31_20  0xFFF00000  // 0/x/x/x Prefetchable Memory Limit [31:20]
    #define D19F0_RPM2BS_31_20  0xFFF0      // FFFh/x/x/x Prefetchable Memory Base [31:20]
#define D19F0_PREFETCHABLE_UPPER_LIMIT 0x28 // Prefetchable Upper Limit
    #define D19F0_RPM2ULM_31_4  0xFFFFFFF0  // 0/x/x/x Prefetchable Upper Limit 32 Bits [31:4] (Not Supported)
    #define D19F0_RPM2ULM_3_0   0xF         // 0/x/x/x Prefetchable Upper Limit 32 Bits [3:0]
#define D19F0_PREFETCHABLE_UPPER_BASE 0x2C // Prefetchable Upper Base
    #define D19F0_RPM2UBS_31_4  0xFFFFFFF0  // 0/x/x/x Prefetchable Upper Base 32 Bits [31:4] (Not Supported)
    #define D19F0_RPM2UBS_3_0   0xF         // 0/x/x/x Prefetchable Upper Base 32 Bits [3:0]
#define D19F0_UPPER_IO_BASE_AND_LIMIT 0x30 // Upper IO Base and Limit
    #define D19F0_RPIOULM_15_0  0xFFFF0000  // 0/R/x/x Upper IO Limit [15:0]
    #define D19F0_RPIOUBS_15_0  0xFFFF      // 0/R/x/x Upper IO Base [15:0]
#define D19F0_CAP_PTR 0x34 // Capability Pointer
#define D19F0_BRIDGE_CTL 0x3E // Bridge Control
    #define D19F0_DTSE      BIT11   // 0/x/x/x Discard Timer SERR# Enable
    #define D19F0_DTS       BIT10   // 0/x/x/x Reserved 
    #define D19F0_SDT       BIT9    // 0/x/x/x Secondary Discard Timer
    #define D19F0_PDT       BIT8    // 0/x/x/x Primary Discard Timer
    #define D19F0_VGAEN     BIT3    // 0/x/x/x VGA Enable
    #define D19F0_SERREN    BIT1    // 0/x/x/x SERR# Enable
    #define D19F0_PERREN    BIT0    // 0/x/x/x Parity Error Response Enable
#define D19F0_EXTERNAL_PCI_DEV_ENABLE_CTL 0x40 // External PCI Device Enable Control
    #define D19F0_RHIDE_DEV6    BIT6    // 0/0/x/x Hide AD25 on External PCI Bus When Assert
    #define D19F0_RHIDE_DEV5    BIT5    // 0/0/x/x Hide AD24 on External PCI Bus When Assert
    #define D19F0_RHIDE_DEV4    BIT4    // 0/0/x/x Hide AD23 on External PCI Bus When Assert
    #define D19F0_RHIDE_DEV3    BIT3    // 0/0/x/x Hide AD22 on External PCI Bus When Assert
    #define D19F0_RHIDE_DEV2    BIT2    // 0/0/x/x Hide AD21 on External PCI Bus When Assert
    #define D19F0_RHIDE_DEV1    BIT1    // 0/0/x/x Hide AD20 on External PCI Bus When Assert
    #define D19F0_RHIDE_DEV0    BIT0    // 0/0/x/x Hide AD19 on External PCI Bus When Assert
#define D19F0_OLD_PCI_CAP_ID 0x60 // OLD PCI Capability ID
#define D19F0_CAP_ID_AND_PTR 0x70 // Capability ID and Pointer
#define D19F0_SSID_AND_SVID 0x74 // Subsystem ID and Subsystem Vendor ID
    #define D19F0_SSID  0xFFFF0000  // B353h/R/x/x Subsystem ID
    #define D19F0_SSVID 0xFFFF      // 1106h/R/x/x Subsystem Vendor ID
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX002(1.00)
// Pls contact PLW to report Irs2h bugs.
