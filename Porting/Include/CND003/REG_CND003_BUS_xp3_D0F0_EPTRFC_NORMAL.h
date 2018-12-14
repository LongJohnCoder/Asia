//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_BUS_x+3_D0F0_EPTRFC_NORMAL_R100(A0).doc.
#ifndef _IRS_CND003_BUS_X_3_D0F0_EPTRFC_NORMAL_R100_A0__H_
#define _IRS_CND003_BUS_X_3_D0F0_EPTRFC_NORMAL_R100_A0__H_
// D0F0
#define CND003_EPTRFC_D0F0_VID 0x0 // Vendor ID
    #define CND003_EPTRFC_D0F0_VENDORID_15_0 D0F0_VID // 1106h/x/x/x Vendor ID
#define CND003_EPTRFC_D0F0_DID 0x2 // Device ID
    #define CND003_EPTRFC_D0F0_DEVID_15_0 D0F0_DID // 9101h/x/x/x Device ID
#define CND003_EPTRFC_D0F0_PCI_CMD 0x4 // PCI Command
    #define CND003_EPTRFC_D0F0_RX04_15_10 0xFC00  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RFBACK     BIT9    // 0/R/x/x Fast Back-to-back Cycle Enable
    #define CND003_EPTRFC_D0F0_RSERR      BIT8    // 0/R/x/x SERR# Enable
    #define CND003_EPTRFC_D0F0_RSETP      BIT7    // 0/R/x/x Address/Data Stepping
    #define CND003_EPTRFC_D0F0_RPTYERR    BIT6    // 0/R/x/x Parity Error Response
    #define CND003_EPTRFC_D0F0_RVGA       BIT5    // 0/R/x/x VGA Palette Snooping
    #define CND003_EPTRFC_D0F0_RMWINV     BIT4    // 0/R/x/x Memory Write and Invalidate
    #define CND003_EPTRFC_D0F0_RSPCYC     BIT3    // 0/R/x/x Respond to Special Cycle
    #define CND003_EPTRFC_D0F0_RMSTR      BIT2    // 0/R/x/x PCI Master Function
    #define CND003_EPTRFC_D0F0_RENMEM     BIT1    // 0/R/x/x Memory Space Access
    #define CND003_EPTRFC_D0F0_RENIO      BIT0    // 0/R/x/x I/O Space Access
#define CND003_EPTRFC_D0F0_PCI_STA 0x6 // PCI Status
    #define CND003_EPTRFC_D0F0_SPERRS     BIT15           // 0/R/x/x Detected Parity Error
    #define CND003_EPTRFC_D0F0_SERRS      BIT14           // 0/R/x/x Signaled System Error (SERR# Asserted)
    #define CND003_EPTRFC_D0F0_SMABORT    BIT13           // 0/R/x/x Received Master-abort (Except Special Cycle)
    #define CND003_EPTRFC_D0F0_STABORTM   BIT12           // 0/R/x/x Received Target-abort
    #define CND003_EPTRFC_D0F0_STABORTS   BIT11           // 0/R/x/x Target-abort Assertion
    #define CND003_EPTRFC_D0F0_DEVS_1_0   (BIT9 + BIT10)  // 0/R/x/x DEVSEL# Timing
    #define CND003_EPTRFC_D0F0_SDPERRS    BIT8            // 0/R/x/x Master Data Parity Error
    #define CND003_EPTRFC_D0F0_RFBKS      BIT7            // 0/R/x/x Capable of Accepting Fast Back-to-back as a Target
    #define CND003_EPTRFC_D0F0_RUDF       BIT6            // 0/R/x/x User Definable Features
    #define CND003_EPTRFC_D0F0_R66M       BIT5            // 0/R/x/x 66MHz Capability
    #define CND003_EPTRFC_D0F0_RCAP       BIT4            // 0/R/x/x Support New Capability List
    #define CND003_EPTRFC_D0F0_RX04_19_16 0xF             // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_REV_ID 0x8 // Revision ID
    #define CND003_EPTRFC_D0F0_RX08_7_0 D0F0_REV_ID // 00h/x/x/x Revision Code
#define CND003_EPTRFC_D0F0_CLASS_CODE 0x9 // Class Code
    #define CND003_EPTRFC_D0F0_RX08_31_8 D0F0_CLASS_CODE // FF 0000h/FF0000h/x/x Class Code
#define CND003_EPTRFC_D0F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_EPTRFC_D0F0_RX0C_7_0 D0F0_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define CND003_EPTRFC_D0F0_MASTER_LATENCY_TIMER 0xD // Master Latency Timer
    #define CND003_EPTRFC_D0F0_RX0C_15_8 D0F0_MASTER_LATENCY_TIMER // 0/R/x/x Maximum Time Slice for this Function as a Master on the PCI Bus
#define CND003_EPTRFC_D0F0_HDR_TYPE 0xE // Header Type
    #define CND003_EPTRFC_D0F0_RX0C_23_16 D0F0_HDR_TYPE // 00h/00h/x/x Header Type
#define CND003_EPTRFC_D0F0_BUILD_IN_SELF_TEST_BIST 0xF // Build In Self Test (BIST)
    #define CND003_EPTRFC_D0F0_RX0C_31_24 D0F0_BUILD_IN_SELF_TEST_BIST // 0/R/x/x BIST Support
#define CND003_EPTRFC_D0F0_BASE_ADR_REGS_0 0x10 // Base Address Registers 0
    #define CND003_EPTRFC_D0F0_RX10_31_0 D0F0_BASE_ADR_REGS_0 // 0/R/x/x Base Address 0
#define CND003_EPTRFC_D0F0_BASE_ADR_REGS_1 0x14 // Base Address Registers 1
    #define CND003_EPTRFC_D0F0_RX14_31_0 D0F0_BASE_ADR_REGS_1 // 0/R/x/x Base Address 1
#define CND003_EPTRFC_D0F0_BASE_ADR_REGS_2 0x18 // Base Address Registers 2
    #define CND003_EPTRFC_D0F0_RX18_31_0 D0F0_BASE_ADR_REGS_2 // 0/R/x/x Base Address 2
#define CND003_EPTRFC_D0F0_BASE_ADR_REGS_3 0x1C // Base Address Registers 3
    #define CND003_EPTRFC_D0F0_RX1C_31_0 D0F0_BASE_ADR_REGS_3 // 0/R/x/x Base Address 3
#define CND003_EPTRFC_D0F0_BASE_ADR_REGS_4 0x20 // Base Address Registers 4
    #define CND003_EPTRFC_D0F0_RX20_31_0 D0F0_BASE_ADR_REGS_4 // 0/R/x/x Base Address 4
#define CND003_EPTRFC_D0F0_BASE_ADR_REGS_5 0x24 // Base Address Registers 5
    #define CND003_EPTRFC_D0F0_RX24_31_0 D0F0_BASE_ADR_REGS_5 // 0/R/x/x Base Address 5
#define CND003_EPTRFC_D0F0_CARDBUS_CIS_PTR 0x28 // CardBus CIS Pointer
    #define CND003_EPTRFC_D0F0_RX28_31_0 D0F0_CARDBUS_CIS_PTR // 0/R/x/x CardBus CIS Pointer
#define CND003_EPTRFC_D0F0_SVID 0x2C // Subsystem Vendor ID
    #define CND003_EPTRFC_D0F0_RX2C_15_0 D0F0_SVID // 1106h/x/x/x Subsystem Vendor ID
#define CND003_EPTRFC_D0F0_SSID 0x2E // Subsystem ID
    #define CND003_EPTRFC_D0F0_RX2C_31_16 D0F0_SSID // 9101h/x/x/x Subsystem ID
#define CND003_EPTRFC_D0F0_HDR_REGS_RESERVED 0x30 // Header Registers Reserved
    #define CND003_EPTRFC_D0F0_RX30_31_0 D0F0_HDR_REGS_RESERVED // 0/R/x/x Reserved for PCI header registers
#define CND003_EPTRFC_D0F0_CAP_PTR 0x34 // Capability Pointer
    #define CND003_EPTRFC_D0F0_RX34_7_0 D0F0_CAP_PTR // 0/R/x/x Capability List Pointer
#define CND003_EPTRFC_D0F0_RESERVED 0x35 // Reserved
    #define CND003_EPTRFC_D0F0_RX35_7_0 D0F0_RESERVED // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_Z1 0x36 // Reserved
    #define CND003_EPTRFC_D0F0_RX36_7_0 D0F0_RESERVED_Z1 // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_Z2 0x37 // Reserved
    #define CND003_EPTRFC_D0F0_RX37_7_0 D0F0_RESERVED_Z2 // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_HDR_REGS_RESERVED2 0x38 // Header Registers Reserved2
    #define CND003_EPTRFC_D0F0_RX38_31_0 D0F0_HDR_REGS_RESERVED2 // 0/R/x/x Reserved for PCI header registers
#define CND003_EPTRFC_D0F0_INTR_LINE_AND_INTR_PIN 0x3C // Interrupt Line and Interrupt Pin
    #define CND003_EPTRFC_D0F0_RX3C_15_8  0xFF00  // 0/R/x/x Interrupt Pin
    #define CND003_EPTRFC_D0F0_RX3C_7_0   0xFF    // 0/R/x/x Interrupt Line
#define CND003_EPTRFC_D0F0_MIN_GRANT_AND_MAX_LATENCY 0x3E // Minimum Grant and Maximum Latency
    #define CND003_EPTRFC_D0F0_RX3C_31_24 0xFF00  // 0/R/x/x Maximum Latency
    #define CND003_EPTRFC_D0F0_RX3C_23_16 0xFF    // 0/R/x/x Minimum Grant
#define CND003_EPTRFC_D0F0_SM_INTR_MAPPING_CFG_REG 0x40 // SM Interrupt Mapping Configure Register
    #define CND003_EPTRFC_D0F0_XH_INTSEL      (BIT30 + BIT31) // 10b/x/x/x xHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_EH2_INTSEL     (BIT28 + BIT29) // 11b/x/x/x D16F7 EHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_UH23_INTSEL    (BIT26 + BIT27) // 10b/x/x/x D16F2 UHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_UH22_INTSEL    (BIT24 + BIT25) // 01b/x/x/x D16F1 UHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_UH21_INTSEL    (BIT22 + BIT23) // 00b/x/x/x D16F0 UHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_EH1_INTSEL     (BIT20 + BIT21) // 01b/x/x/x D14F7 EHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_UH13_INTSEL    (BIT18 + BIT19) // 00b/x/x/x D14F2 UHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_UH12_INTSEL    (BIT16 + BIT17) // 11b/x/x/x D14F1 UHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_UH11_INTSEL    (BIT14 + BIT15) // 10b/x/x/x D14F0 UHCI Interrupt Selection
    #define CND003_EPTRFC_D0F0_RX40_13_12     (BIT12 + BIT13) // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX40_11_10     (BIT10 + BIT11) // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX40_9_8       (BIT8 + BIT9)   // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_SA1NC_INTSEL   (BIT6 + BIT7)   // 11b/x/x/x SATA Non Compatible Mode Interrupt Selection (D15F0)
    #define CND003_EPTRFC_D0F0_RX40_5_4       (BIT4 + BIT5)   // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_GNIC_INT_SEL   (BIT2 + BIT3)   // 01b/x/x/x GNIC Interrupt Selection
    #define CND003_EPTRFC_D0F0_RX40_1_0       (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_MCU_UPSTREAM_MODE 0x44 // MCU Upstream Mode
    #define CND003_EPTRFC_D0F0_RX41_7_4       0xF0    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX41_3         BIT3    // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX41_2         BIT2    // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_CFGMCURNS      BIT1    // 0/0/x/x xHCI MCU Upstream Read Non-snoop Mode
    #define CND003_EPTRFC_D0F0_CFGMCURHPRI    BIT0    // 0/0/x/x xHCI MCU Upstream Read High Priority Mode
#define CND003_EPTRFC_D0F0_SM_DEV_ENABLE_1 0x45 // SM Device Enable 1
    #define CND003_EPTRFC_D0F0_ISB2XH_XHCI_EN_ECLK    BIT7    // 1b/x/x/x xHCI Enable (XHCI_EN)
    #define CND003_EPTRFC_D0F0_D14_ENEHCI             BIT6    // 1b/x/x/x D14F7 Function Enable (D14F7_ENEHCI)
    #define CND003_EPTRFC_D0F0_D14_ENUSB1             BIT5    // 1b/x/x/x D14F0 Function Enable (D14F0_ENEHCI)
    #define CND003_EPTRFC_D0F0_D14_ENUSB2             BIT4    // 1b/x/x/x D14F1 Function Enable (D14F1_ENEHCI)
    #define CND003_EPTRFC_D0F0_D14_ENUSB3             BIT3    // 1b/x/x/x D14F2 Function Enable (D14F2_ENEHCI)
    #define CND003_EPTRFC_D0F0_D14_ENUSB4             BIT2    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_D14_ENUSB5             BIT1    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_R_DBGCAPEN             BIT0    // 0/0/x/x Debug Cap Enable
#define CND003_EPTRFC_D0F0_SM_DEV_ENABLE_2 0x46 // SM Device Enable 2
    #define CND003_EPTRFC_D0F0_D16_ENEHCI     BIT7    // 1b/x/x/x D16F7 Function Enable (D16F7_ENEHCI)
    #define CND003_EPTRFC_D0F0_D16_ENUSB1     BIT6    // 1b/x/x/x D16F0 Function Enable (D16F0_ENEHCI)
    #define CND003_EPTRFC_D0F0_D16_ENUSB2     BIT5    // 1b/x/x/x D16F1 Function Enable (D16F1_ENEHCI)
    #define CND003_EPTRFC_D0F0_D16_ENUSB3     BIT4    // 1b/x/x/x D16F2 Function Enable (D16F2_ENEHCI)
    #define CND003_EPTRFC_D0F0_D16_ENUSB4     BIT3    // 0/x/x/x D16_ENUSB4
    #define CND003_EPTRFC_D0F0_D16_ENUSB5     BIT2    // 0/x/x/x D16_ENUSB5
    #define CND003_EPTRFC_D0F0_D15SA_ENSATA   BIT1    // 1b/x/x/x D15F0 Function Enable (D15SA_ENSATA)
    #define CND003_EPTRFC_D0F0_GNIC_EN        BIT0    // 1b/x/x/x GNIC Function Enable (GNIC_EN (D13F0))
#define CND003_EPTRFC_D0F0_LOWER_BASE_ADR_OF_SPI_8051_MCU_FW_IN_SYS_MEM 0x48 // Lower Base Address of SPI_8051_MCU Firmware in System Memory
    #define CND003_EPTRFC_D0F0_MCU_INSTDAT_SYSMEM_LBASE_31_6  0xFFFFFFC0  // 0/x/x/x Lower Base Address of SPI_8051_MCU Firmware
    #define CND003_EPTRFC_D0F0_RX4B_5_0                       0x3F        // 0/x/x/x Hardwired to 0 to Force 64-byte Alignment of Base Address
#define CND003_EPTRFC_D0F0_UPPER_BASE_ADR_OF_SPI_8051_MCU_FW_IN_SYS_MEM 0x4C // Upper Base Address of SPI_8051_MCU Firmware in System Memory
    #define CND003_EPTRFC_D0F0_MCU_INSTDAT_SYSMEM_UBASE_31_0 D0F0_UPPER_BASE_ADR_OF_SPI_8051_MCU_FW_IN_SYS_MEM // 0/x/x/x Upper Base Address of SPI_8051_MCU Firmware
#define CND003_EPTRFC_D0F0_START_ADR_OF_AUTO_FILL_INSTRUCTION 0x50 // Start Address of Auto-Fill Instruction
    #define CND003_EPTRFC_D0F0_INST_AUTOFILL_SADDR_31_0 D0F0_START_ADR_OF_AUTO_FILL_INSTRUCTION // 0/x/x/x Start Address of Auto-Fill SPI_8051_MCU Instruction
#define CND003_EPTRFC_D0F0_START_ADR_OF_AUTO_FILL_INSTRUCTION_0 0x54 // Start Address of Auto-Fill Instruction 0
    #define CND003_EPTRFC_D0F0_RX54_31_17                 0xFFFE0000  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_INST_AUTOFILL_LENGTH_15_0  0x1FFFE     // 0/x/x/x SPI_8051_MCU Instruction Auto-Fill Length (In Unit of Byte)
    #define CND003_EPTRFC_D0F0_INST_AUTOFILL_EN           BIT0        // 0/x/x/x SPI_8051_MCU Instruction Auto-Fill Enable
#define CND003_EPTRFC_D0F0_START_ADR_OF_AUTO_FILL_INSTRUCTION_1 0x58 // Start Address of Auto-Fill Instruction 1
    #define CND003_EPTRFC_D0F0_RX58_7_1               0xFE    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_INST_AUTOFILL_DONE_OUT BIT0    // 0/x/x/x SPI_8051_MCU Instruction Auto-Fill Done
#define CND003_EPTRFC_D0F0_START_ADR_OF_AUTO_FILL_INSTRUCTION_2 0x59 // Start Address of Auto-Fill Instruction 2
    #define CND003_EPTRFC_D0F0_RX59_7_2       0xFC    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RGATESWPRST    BIT1    // 0/0/x/x Gate USBC SW Port Reset 
    #define CND003_EPTRFC_D0F0_MCU_SW_RST     BIT0    // 1b/1/x/x SPI_8051_MCU Software Reset Controlled by BIOS
#define CND003_EPTRFC_D0F0_RESERVED_Z3 0x5A // Reserved
    #define CND003_EPTRFC_D0F0_RX5A_15_0 D0F0_RESERVED_Z3 // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_OPENRISC_FW_FORCE_TO_RELOAD_REG 0x5C // OpenRISC FW Force to Reload Register
    #define CND003_EPTRFC_D0F0_RX5C_31_1                  0xFFFFFFFE  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_ISB2XH_OPRISC_FORCE_RLD    BIT0        // 0b/x/x/x OPRISC_FORCE_RLD
#define CND003_EPTRFC_D0F0_CONVERT_CIRCUIT_BYPASS 0x60 // Convert Circuit Bypass
    #define CND003_EPTRFC_D0F0_RX60_7_6           (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2EHCIDNBYPASS    BIT5            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX60_4             BIT4            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2UHCIDNBYPASS    BIT3            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2XHCIDNBYPASS    BIT2            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2SATADNBYPASS    BIT1            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2VHCIDNBYPASS    BIT0            // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_CFG_CYCLE_CTL_2 0x61 // Configuration Cycle Control 2
    #define CND003_EPTRFC_D0F0_RX61_7_6           (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_REHCIDN2EBYPASS    BIT5            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX61_4             BIT4            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RUHCIDN2EBYPASS    BIT3            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RXHCIDN2EBYPASS    BIT2            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RSATADN2EBYPASS    BIT1            // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RVHCIDN2EBYPASS    BIT0            // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_DOWNSTREAM_CTL 0x62 // Downstream Control
    #define CND003_EPTRFC_D0F0_RX62_7_5           (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_DID_LOCK           BIT4                    // 0/1/x/x DID Lock Bit
    #define CND003_EPTRFC_D0F0_VID_LOCK           BIT3                    // 0/1/x/x VID Lock Bit
    #define CND003_EPTRFC_D0F0_RCLASSCODE_LOCK    BIT2                    // 0/1/x/x Help Lock Class Code Register at Rx08[31:8]
    #define CND003_EPTRFC_D0F0_RPSWPOP_DELAY_1T   BIT1                    // 1b/1/x/x Downstream Non-post Cycle Write POP 1T Delay
    #define CND003_EPTRFC_D0F0_RDSNPPIPE          BIT0                    // 0/0/1/x Downstream Non-post Cycle Pipe Control
#define CND003_EPTRFC_D0F0_SPI_CTL_LOGIC 0x63 // SPI Control Logic
    #define CND003_EPTRFC_D0F0_RX63_7         BIT7    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_SVID_LOCK      BIT6    // 0/x/x/x SVID Lock Bit
    #define CND003_EPTRFC_D0F0_SPIROM_WBEI    0x3C    // 0/x/x/x SPI Write Byte Enable
    #define CND003_EPTRFC_D0F0_SPIROM_WRI     BIT1    // 0/x/x/x SW Want to Issue Read or Write (SPIROM_WR)
    #define CND003_EPTRFC_D0F0_SPIROM_CREQI   BIT0    // 0/x/x/x SPIROM_CREQ
#define CND003_EPTRFC_D0F0_SPI_ADR 0x64 // SPI Address
    #define CND003_EPTRFC_D0F0_RX64_31_24         0xFF000000  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_SPIROM_ADDRI_23_0  0xFFFFFF    // 0/x/x/x SPIROM Address (SPIROM_ADDR)
#define CND003_EPTRFC_D0F0_SPI_WRITE_DATA 0x68 // SPI Write Data
    #define CND003_EPTRFC_D0F0_SPIROM_WDI D0F0_SPI_WRITE_DATA // 0/x/x/x SPIROM Write Data (SPIROM_WD)
#define CND003_EPTRFC_D0F0_SPI_READ_DATA 0x6C // SPI Read Data
    #define CND003_EPTRFC_D0F0_SPIREG_RDI D0F0_SPI_READ_DATA // 0/x/x/x SPIROM Read Data (SPIREG_RD)
#define CND003_EPTRFC_D0F0_CLASS_CODE_FAKE 0x70 // Class Code Fake
    #define CND003_EPTRFC_D0F0_RX70_31_8  0xFFFFFF00  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX70_7_0   0xFF        // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_GNIC_UPSTREAM_TIMER 0x80 // GNIC Upstream Timer
    #define CND003_EPTRFC_D0F0_GNICOCTM_3_0   0xF0    // 1000b/x/x/x GNIC Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_GNICPMTM_3_0   0xF     // 1000b/x/x/x GNIC Upstream Promote Timer
#define CND003_EPTRFC_D0F0_SATA_UPSTREAM_TIMER 0x81 // SATA Upstream Timer
    #define CND003_EPTRFC_D0F0_SATAOCTM_3_0   0xF0    // 1000b/x/x/x SATA Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_SATAPMTM_3_0   0xF     // 1000b/x/x/x SATA Upstream Promote Timer
#define CND003_EPTRFC_D0F0_XHCI_UPSTREAM_TIMER 0x82 // xHCI Upstream Timer
    #define CND003_EPTRFC_D0F0_XHCIOCTM_3_0   0xF0    // 1000b/x/x/x xHCI Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_XHCIPMTM_3_0   0xF     // 1000b/x/x/x xHCI Upstream Promote Timer
#define CND003_EPTRFC_D0F0_MCU_UPSTREAM_TIMER 0x83 // MCU Upstream Timer
    #define CND003_EPTRFC_D0F0_MCUOCTM_3_0    0xF0    // 1000b/x/x/x MCU Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_MCUPMTM_3_0    0xF     // 1000b/x/x/x MCU Upstream Promote Timer
#define CND003_EPTRFC_D0F0_D14F0_F1_F2_UPSTREAM_TIMER 0x84 // D14F0/F1/F2 Upstream Timer
    #define CND003_EPTRFC_D0F0_UHCIOCTM_3_0   0xF0    // 1000b/x/x/x D14F0/F1/F2 Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_UHCIPMTM_3_0   0xF     // 1000b/x/x/x D14F0/F1/F2 Upstream Promote Timer
#define CND003_EPTRFC_D0F0_D14F7_UPSTREAM_TIMER 0x85 // D14F7 Upstream Timer
    #define CND003_EPTRFC_D0F0_UHCI2OCTM_3_0  0xF0    // 1000b/x/x/x D14F7 Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_UHCI2PMTM_3_0  0xF     // 1000b/x/x/x D14F7 Upstream Promote Timer
#define CND003_EPTRFC_D0F0_D16F0_F1_F2_UPSTREAM_TIMER 0x86 // D16F0/F1/F2 Upstream Timer
    #define CND003_EPTRFC_D0F0_EHCIOCTM_3_0   0xF0    // 1000b/x/x/x D16F0/F1/F2 Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_EHCIPMTM_3_0   0xF     // 1000b/x/x/x D16F0/F1/F2 Upstream Promote Timer
#define CND003_EPTRFC_D0F0_D16F7_UPSTREAM_TIMER 0x87 // D16F7 Upstream Timer
    #define CND003_EPTRFC_D0F0_EHCI2OCTM_3_0  0xF0    // 1000b/x/x/x D16F7 Upstream Occupy Timer
    #define CND003_EPTRFC_D0F0_EHCI2PMTM_3_0  0xF     // 1000b/x/x/x D16F7 Upstream Promote Timer
#define CND003_EPTRFC_D0F0_UPSTREAM_ARBITRATION_TIMER1 0x88 // Upstream Arbitration Timer1
    #define CND003_EPTRFC_D0F0_MHOTTIM_3_0    0xF0    // 1000b/x/x/x Upstream Hot Timer
    #define CND003_EPTRFC_D0F0_MFEEDTIM_3_0   0xF     // 0010b/x/x/x Upstream Feed Timer
#define CND003_EPTRFC_D0F0_UPSTREAM_ARBITRATION_TIMER2 0x89 // Upstream Arbitration Timer2
    #define CND003_EPTRFC_D0F0_RX88_7_4       0xF0    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_MFREEZETIM_3_0 0xF     // 0/x/x/x Upstream Freeze Timer
#define CND003_EPTRFC_D0F0_UPSTREAM_CLK_BYPASS1 0x8A // Upstream Clock Bypass1
    #define CND003_EPTRFC_D0F0_RE2VHCIUPBYPASS    BIT7    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RVHCIUP2EBYPASS    BIT6    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RSATAUP2EBYPASS    BIT5    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2SATAUPBYPASS    BIT4    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RXHCIUP2EBYPASS    BIT3    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2XHCIUPBYPASS    BIT2    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2UHCIUPBYPASS    BIT1    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RUHCIUP2EBYPASS    BIT0    // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_UPSTREAM_CLK_BYPASS2 0x8B // Upstream Clock Bypass2
    #define CND003_EPTRFC_D0F0_RE2EHCIUPBYPASS    BIT7    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_REHCIUP2EBYPASS    BIT6    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2UHCI2UPBYPASS   BIT5    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RUHCI2UP2EBYPASS   BIT4    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2EHCI2UPBYPASS   BIT3    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_REHCI2UP2EBYPASS   BIT2    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RE2MCUUPBYPASS     BIT1    // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RMCUUP2EBYPASS     BIT0    // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_UPSTREAM_CLK_BYPASS3 0x8C // Upstream Clock Bypass3
    #define CND003_EPTRFC_D0F0_RP2PABT_REPORT BIT7    // 0/0/x/x Upstream P2P Abort Report Enable
    #define CND003_EPTRFC_D0F0_RUHCI2PIPE     BIT6    // 1b/x/1/x D14F7 Upstream Pre-fetch Enable
    #define CND003_EPTRFC_D0F0_REHCI2PIPE     BIT5    // 1b/x/1/x D16F7 Upstream Pre-fetch Enable
    #define CND003_EPTRFC_D0F0_RX8C_4         BIT4    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX8C_3         BIT3    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX8C_2         BIT2    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX8C_1         BIT1    // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX8C_0         BIT0    // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_DOWNSTREAM_DYNAMIC_CLK 0x8D // Downstream Dynamic clock
    #define CND003_EPTRFC_D0F0_REPTRFC_DNPATH_PM_EN       BIT7    // 0/0/x/1 Downstream Path Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNECLK_PM_EN       BIT6    // 0/0/x/1 Downstream Path ECLK Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNVHCICLK_PM_EN    BIT5    // 0/0/x/1 Downstream Path GN_GCLK Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNEHCICLK_PM_EN    BIT4    // 0/0/x/1 Downstream Path EHCI GCLK Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNDISCCLK_PM_EN    BIT3    // 0/0/x/1 Downstream Path Discard Path Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNSATACLK_PM_EN    BIT2    // 0/0/x/1 SATA Downstream Path Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNXHCICLK_PM_EN    BIT1    // 0/0/x/1 xHCI Downstream Path Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_DNUHCICLK_PM_EN    BIT0    // 0/0/x/1 UHCI Downstream Path Dynamic Clock Enable
#define CND003_EPTRFC_D0F0_UPSTREAM_DYNAMIC_CLK 0x8E // Upstream Dynamic Clock
    #define CND003_EPTRFC_D0F0_REPTRFC_UPPATH_PM_EN       BIT7    // 0/0/x/1 Upstream Path Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_UPECLK_PM_EN       BIT6    // 0/0/x/1 Upstream Path ECLK Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_RUPC2PRBLOCK_PSWD          BIT5    // 0/x/x/x RUPC2PRBLOCK_PSWD
    #define CND003_EPTRFC_D0F0_REPTRFC_UPEHCICLK_PM_EN    BIT4    // 0/0/x/1 Upstream EHCI (GCLK) Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_UPUHCICLK_PM_EN    BIT3    // 0/0/x/1 Upstream UHCI ( GCLK) Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_UPEHCI2CLK_PM_EN   BIT2    // 0/0/x/1 Upstream EHCI2(GCLK) Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_REPTRFC_UPUHCI2CLK_PM_EN   BIT1    // 0/0/x/1 Upstream UHCI2 (GCLK) Dynamic Clock Enable
    #define CND003_EPTRFC_D0F0_RUPC2PRBLOCK_SCRST         BIT0    // 0/x/x/x RUPC2PRBLOCK_SCRST
#define CND003_EPTRFC_D0F0_RESERVED_Z4 0x8F // Reserved
    #define CND003_EPTRFC_D0F0_RX8F_7_0 D0F0_RESERVED_Z4 // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_Z5 0x90 // Reserved
    #define CND003_EPTRFC_D0F0_RX90_7_0 D0F0_RESERVED_Z5 // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_Z6 0x91 // Reserved
    #define CND003_EPTRFC_D0F0_RX91_7_0 D0F0_RESERVED_Z6 // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_Z7 0x92 // Reserved
    #define CND003_EPTRFC_D0F0_RX92_7_0 D0F0_RESERVED_Z7 // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_Z8 0x93 // Reserved
    #define CND003_EPTRFC_D0F0_RX93_7_0 D0F0_RESERVED_Z8 // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_D15F0RX13_10_PROGRAMMING_IF0_FOR_IDE_NATIVE_MODE_OR_RAID_MODE 0x100 // D15F0Rx13-10 Programming Interface0: For IDE Native Mode or RAID Mode
    #define CND003_EPTRFC_D0F0_RX100_31_16        0xFFFF0000              // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_W1FXA_NATIVE_15_4  0xFFF0                  // 01Fh/x/x/x IO Port Address [15:4]
    #define CND003_EPTRFC_D0F0_W1FXA_NATIVE_3     BIT3                    // 0/x/x/x IO Port Address [3]
    #define CND003_EPTRFC_D0F0_W1FXA_NATIVE_2_0   (BIT0 + BIT1 + BIT2)    // 001b/R/x/x IO Port Address [2:0]
#define CND003_EPTRFC_D0F0_D15F0RX17_14_PROGRAMMING_IF1_FOR_IDE_NATIVE_MODE_OR_RAID_MODE 0x104 // D15F0Rx17-14 Programming Interface1: For IDE Native Mode or RAID Mode
    #define CND003_EPTRFC_D0F0_RX104_31_16        0xFFFF0000      // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_W3FXA_NATIVE_15_4  0xFFF0          // 03Fh/x/x/x IO Port Address [15:4]
    #define CND003_EPTRFC_D0F0_W3FXA_NATIVE_3_2   (BIT2 + BIT3)   // 01b/x/x/x IO Port Address [3:2]
    #define CND003_EPTRFC_D0F0_W3FXA_NATIVE_1_0   (BIT0 + BIT1)   // 01b/R/x/x IO Port Address [1:0]
#define CND003_EPTRFC_D0F0_D15F0RX1B_18_PROGRAMMING_IF2_FOR_AHCI_MODE 0x108 // D15F0Rx1B-18 Programming Interface2: For AHCI Mode
    #define CND003_EPTRFC_D0F0_MSIX_TBASE_31_6    0xFFFFFFC0  // 0/x/x/x MSI-X Table Structure Base Address
    #define CND003_EPTRFC_D0F0_RX108_5_0          0x3F        // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_D15F0RX1B_18_PROGRAMMING_IF3_FOR_IDE_NATIVE_MODE_OR_RAID_MODE 0x10C // D15F0Rx1B-18 Programming Interface3: For IDE Native Mode or RAID Mode
    #define CND003_EPTRFC_D0F0_RX10C_31_16        0xFFFF0000              // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_W1FXB_NATIVE_15_4  0xFFF0                  // 017h/x/x/x IO Port Address [15:4]
    #define CND003_EPTRFC_D0F0_W1FXB_NATIVE_3     BIT3                    // 0/x/x/x IO Port Address [3]
    #define CND003_EPTRFC_D0F0_W1FXB_NATIVE_2_0   (BIT0 + BIT1 + BIT2)    // 001b/R/x/x IO Port Address [2:0]
#define CND003_EPTRFC_D0F0_D15F0RX1F_1C_PROGRAMMING_IF4_FOR_AHCI_MODE 0x110 // D15F0Rx1F-1C Programming Interface4: For AHCI Mode
    #define CND003_EPTRFC_D0F0_MSIX_PBASE_31_4    0xFFFFFFF0  // 0/x/x/x MSI-X PBA Structure Base Address
    #define CND003_EPTRFC_D0F0_RX110_3_0          0xF         // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_D15F0RX1F_1C_PROGRAMMING_IF5_FOR_IDE_NATIVE_MODE_OR_RAID_MODE 0x114 // D15F0Rx1F-1C Programming Interface5: For IDE Native Mode or RAID Mode
    #define CND003_EPTRFC_D0F0_RX114_31_16        0xFFFF0000      // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_W3FXB_NATIVE_15_4  0xFFF0          // 037h/x/x/x IO Port Address [15:4]
    #define CND003_EPTRFC_D0F0_W3FXB_NATIVE_3_2   (BIT2 + BIT3)   // 01b/x/x/x IO Port Address [3:2]
    #define CND003_EPTRFC_D0F0_W3FXB_NATIVE_1_0   (BIT0 + BIT1)   // 01b/R/x/x IO Port Address [1:0]
#define CND003_EPTRFC_D0F0_D15F0RX23_20_PROGRAMMING_IF_FOR_IDE_MODE_RX0A_01H 0x118 // D15F0Rx23-20 Programming Interface: For IDE Mode (Rx0A = 01h)
    #define CND003_EPTRFC_D0F0_RX118_31_16    0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_WCTL_15_5      0xFFE0      // 660h/x/x/x IO Port Address (Random)
    #define CND003_EPTRFC_D0F0_WCTL_4_0       0x1F        // 00001b/R/x/x IO Port Address
#define CND003_EPTRFC_D0F0_D15F0RX27_24_PROGRAMMING_IF_FOR_AHCI_MODE_RX0A_06H 0x11C // D15F0Rx27-24 Programming Interface: For AHCI Mode (Rx0A = 06h)
    #define CND003_EPTRFC_D0F0_AHCIBASE_31_13 0xFFFFE000  // 0/x/x/x Base Address of Register Memory Space
    #define CND003_EPTRFC_D0F0_RX11C_12_0     0x1FFF      // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX123_120H 0x120 // Reserved Rx123-120h
    #define CND003_EPTRFC_D0F0_RX120_31_16    0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX120_15_0     0xFFFF      // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX127_124H 0x124 // Reserved Rx127-124h
    #define CND003_EPTRFC_D0F0_RX124_31_16    0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX124_15_0     0xFFFF      // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX12B_128H 0x128 // Reserved Rx12B-128h
    #define CND003_EPTRFC_D0F0_RX128_31_6 0xFFFFFFC0  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX128_5_0  0x3F        // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX12C_12FH 0x12C // Reserved Rx12C-12Fh
    #define CND003_EPTRFC_D0F0_RX12C_31_16    0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX12C_15_0     0xFFFF      // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX133_130H 0x130 // Reserved Rx133-130h
    #define CND003_EPTRFC_D0F0_RX130_31_4 0xFFFFFFF0  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX130_3_0  0xF         // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX137_134H 0x134 // Reserved Rx137-134h
    #define CND003_EPTRFC_D0F0_RX134_31_16    0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX134_15_0     0xFFFF      // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX13B_138H 0x138 // Reserved Rx13B-138h
    #define CND003_EPTRFC_D0F0_RX138_31_16    0xFFFF0000  // 0/R/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX138_15_0     0xFFFF      // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_RX13F_13C 0x13C // Reserved Rx13F-13C
    #define CND003_EPTRFC_D0F0_RX13C_31_13    0xFFFFE000  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX13C_12_0     0x1FFF      // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_GNIC_CSR_IO_MAPPED_BASE_ADDR_REGS_D13F0RX10_RX13 0x140 // (GNIC) CSR IO Mapped Base Addr Registers (D13F0Rx10-Rx13)
    #define CND003_EPTRFC_D0F0_GNIC_IOBA1_31_5    0xFFFFFFE0  // 0/x/x/x CSR IO Mapped Base Addr[31:5]?32Byte?
    #define CND003_EPTRFC_D0F0_RX140_4_0          0x1F        // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_GNIC_CSR_MEM_MAPPED_BASE_ADDR_REGS_D13F0RX14_RX17 0x144 // (GNIC)CSR MEM Mapped Base Addr Registers (D13F0Rx14-Rx17)
    #define CND003_EPTRFC_D0F0_GNIC_MMBLA3_31_12  0xFFFFF000  // 0/x/x/x CSR MEM Mapped Base Addr[31:12]?4K Byte?
    #define CND003_EPTRFC_D0F0_RX144_11_0         0xFFF       // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_GNIC_CSR_MEM_MAPPED_BASE_HIGH_ADDR_REGS_D13F0RX18_RX1B 0x148 // (GNIC) CSR MEM Mapped Base High Addr Registers (D13F0Rx18-Rx1B)
    #define CND003_EPTRFC_D0F0_GNIC_MMBHA D0F0_GNIC_CSR_MEM_MAPPED_BASE_HIGH_ADDR_REGS_D13F0RX18_RX1B // 0/0/x/x CSR MEM Mapped Base High Addr[63:32]
#define CND003_EPTRFC_D0F0_GNIC_MSI_X_MEM_MAPPED_BASE_ADDR_REGS_D14F0RX1C_RX1F 0x14C // (GNIC)MSI-X MEM Mapped Base Addr Registers (D14F0Rx1C-Rx1F)
    #define CND003_EPTRFC_D0F0_GNIC_MSIXMBAH_31_13    0xFFFFE000  // 0/x/x/x MSI-X MEM Mapped Base Addr[31:13]?8K Byte?
    #define CND003_EPTRFC_D0F0_RX14C_12_0             0x1FFF      // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_153_150H 0x150 // Reserved 153-150h
    #define CND003_EPTRFC_D0F0_RX150_31_9 0xFFFFFE00  // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX150_8_0  0x1FF       // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_RESERVED_157_154H 0x154 // Reserved 157-154h
    #define CND003_EPTRFC_D0F0_RX154_31_3 0xFFFFFFF8              // 0/x/x/x Reserved
    #define CND003_EPTRFC_D0F0_RX154_2_0  (BIT0 + BIT1 + BIT2)    // 0/x/x/x Reserved
#define CND003_EPTRFC_D0F0_D14F7_EHCI_MEM_MAPPED_IO_BASE_ADR_D14F7RX10_D14F7RX13 0x158 // D14F7 EHCI Memory Mapped I/O Base Address (D14F7Rx10-D14F7Rx13)
    #define CND003_EPTRFC_D0F0_D14F7_IOBASE_31_8  0xFFFFFF00  // 0/x/x/x EHCI Memory Mapped I/O Registers Base Address
    #define CND003_EPTRFC_D0F0_RX158_7_0          0xFF        // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_D16F7_EHCI_MEM_MAPPED_IO_BASE_ADR_D16F7RX10_D16F7RX13 0x15C // D16F7 EHCI Memory Mapped I/O Base Address (D16F7Rx10-D16F7Rx13)
    #define CND003_EPTRFC_D0F0_D16F7_IOBASE_31_8  0xFFFFFF00  // 0/x/x/x EHCI Memory Mapped I/O Registers Base Address
    #define CND003_EPTRFC_D0F0_RX15C_7_0          0xFF        // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_D14F0_USB_IO_REG_BASE_ADR_D14F0RX20_D14F0RX23 0x160 // D14F0 USB I/O Register Base Address (D14F0Rx20-D14F0Rx23)
    #define CND003_EPTRFC_D0F0_D14F0_IOBASE_31_16 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_D14F0_IOBASE_15_5  0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define CND003_EPTRFC_D0F0_D14F0_IOBASE_4_0   0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define CND003_EPTRFC_D0F0_D14F1_USB_IO_REG_BASE_ADR_D14F1RX20_D14F1RX23 0x164 // D14F1 USB I/O Register Base Address (D14F1Rx20-D14F1Rx23)
    #define CND003_EPTRFC_D0F0_D14F1_IOBASE_31_16 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_D14F1_IOBASE_15_5  0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define CND003_EPTRFC_D0F0_D14F1_IOBASE_4_0   0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define CND003_EPTRFC_D0F0_D14F2_USB_IO_REG_BASE_ADR_D14F2RX20_D14F2RX23 0x168 // D14F2 USB I/O Register Base Address (D14F2Rx20-D14F2Rx23)
    #define CND003_EPTRFC_D0F0_D14F2_IOBASE_31_16 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_D14F2_IOBASE_15_5  0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define CND003_EPTRFC_D0F0_D14F2_IOBASE_4_0   0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define CND003_EPTRFC_D0F0_D16F0_USB_IO_REG_BASE_ADR_D16F0RX20_D16F0RX23 0x16C // D16F0 USB I/O Register Base Address (D16F0Rx20-D16F0Rx23)
    #define CND003_EPTRFC_D0F0_D16F0_IOBASE_31_16 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_D16F0_IOBASE_15_5  0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define CND003_EPTRFC_D0F0_D16F0_IOBASE_4_0   0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define CND003_EPTRFC_D0F0_D16F1_USB_IO_REG_BASE_ADR_D16F0RX20_D16F0RX23 0x170 // D16F1 USB I/O Register Base Address (D16F0Rx20-D16F0Rx23)
    #define CND003_EPTRFC_D0F0_D16F1_IOBASE_31_16 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_D16F1_IOBASE_15_5  0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define CND003_EPTRFC_D0F0_D16F1_IOBASE_4_0   0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define CND003_EPTRFC_D0F0_D16F2_USB_IO_REG_BASE_ADR_D16F2RX20_D16F2RX23 0x174 // D16F2 USB I/O Register Base Address (D16F2Rx20-D16F2Rx23)
    #define CND003_EPTRFC_D0F0_D16F2_IOBASE_31_16 0xFFFF0000  // 0/0/x/x Reserved
    #define CND003_EPTRFC_D0F0_D16F2_IOBASE_15_5  0xFFE0      // 7E7h/x/x/x USB I/O Register Base Address [15:5]
    #define CND003_EPTRFC_D0F0_D16F2_IOBASE_4_0   0x1F        // 01h/R/x/x 32-Byte Aligned IO Space
#define CND003_EPTRFC_D0F0_XHCI_MEM_MAPPED_IO_LOW_BASE_ADR_D18F0RX10_RX13 0x178 // XHCI Memory Mapped I/O Low Base Address (D18F0Rx10-Rx13)
    #define CND003_EPTRFC_D0F0_XHCI_BASEADDR0_LO_31_12    0xFFFFF000  // 0/0/x/x XHCI Memory Mapped I/O Registers Low Base Address
    #define CND003_EPTRFC_D0F0_RX178_11_0                 0xFFF       // 0/R/x/x Reserved
#define CND003_EPTRFC_D0F0_XHCI_MEM_MAPPED_IO_HIGH_BASE_ADR_D18F0RX14_RX17 0x17C // xHCI Memory Mapped I/O High Base Address (D18F0Rx14-Rx17)
    #define CND003_EPTRFC_D0F0_XHCI_BASEADDR0_HI_31_0 D0F0_XHCI_MEM_MAPPED_IO_HIGH_BASE_ADR_D18F0RX14_RX17 // 0/0/x/x xHCI Memory Mapped I/O Registers High Base Address
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
