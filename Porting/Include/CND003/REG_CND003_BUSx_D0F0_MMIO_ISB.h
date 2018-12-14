//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_BUSxD0F0_MMIO_ISB_R103(A0).doc.
#ifndef _REG_CND003_BUSX_D0F0_MMIO_ISB_H_
#define _REG_CND003_BUSX_D0F0_MMIO_ISB_H_
// D0F0
#define CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_INPUT 0x0 // Vcore General Purpose Input
    #define CND003_MMIO_D0F0_REG00_RSV0 0xFFFFF800  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_GPIONI   0x7FF       // 0/x/x/x General Purpose Input Status
#define CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT 0x4 // Vcore General Purpose Output
    #define CND003_MMIO_D0F0_REG04_RSV0 0xFFFFF800  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_GPIONO   0x7FF       // 7FFh/x/x/x Reads from this register return the last value written (held on ch...
#define CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING 0x8 // Vcore GPO Mode Setting
    #define CND003_MMIO_D0F0_REG08_RSV0 0xFFFFC000  // 0/x/x/x Reserve
    #define CND003_MMIO_D0F0_R_GPONO    0x3FFF      // 3FFFh/x/x/x General Purpose Output
#define CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL 0xC // Vcore GPIO PAD Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO7    (BIT14 + BIT15) // 0/x/x/x GPIO 7 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO6    (BIT12 + BIT13) // 0/x/x/x GPIO 6 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO5    (BIT10 + BIT11) // 0/x/x/x GPIO 5 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO4    (BIT8 + BIT9)   // 0/x/x/x GPIO 4 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO3    (BIT6 + BIT7)   // 0/x/x/x GPIO 3 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO2    (BIT4 + BIT5)   // 0/x/x/x GPIO 2 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO1    (BIT2 + BIT3)   // 0/x/x/x GPIO 1 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO0    (BIT0 + BIT1)   // 0/x/x/x GPIO 0 Pad Mux Selection
#define CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL 0xE // Vcore GPO PAD Selection
    #define CND003_MMIO_D0F0_REG0E_RSV4     BIT15           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_PAD_GPIO9_0  BIT14           // 0/x/x/x GPIO9 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPIO8    (BIT12 + BIT13) // 0/x/x/x GPIO8 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPO5     (BIT10 + BIT11) // 0/x/x/x GPO5 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPO4     (BIT8 + BIT9)   // 0/x/x/x GPO4 PAD Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPO3     (BIT6 + BIT7)   // 0/x/x/x GPO3 Pad Mux Selection
    #define CND003_MMIO_D0F0_REG0E_RSV1     BIT5            // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_PAD_GPO2     BIT4            // 0/x/x/x GPO2 Pad Mux Selection
    #define CND003_MMIO_D0F0_REG0E_RSV0     BIT3            // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_PAD_GPO1_0   BIT2            // 0/x/x/x GPO1 Pad Mux Selection
    #define CND003_MMIO_D0F0_R_PAD_GPO0     (BIT0 + BIT1)   // 0/x/x/x GPO0 Pad Mux Selection
#define CND003_MMIO_D0F0_VCORE_PAD_SETTING 0x10 // Vcore PAD Setting
    #define CND003_MMIO_D0F0_REG10_RSV2         0xFFF00000              // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RCKBUF_CLKRX_ADJ   0xF0000                 // 0000b/x/x/x BUFFER_ PHYB Buffer Option
    #define CND003_MMIO_D0F0_REG10_RSV5         BIT15                   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_DEBUGPAD_DPCTL   (BIT12 + BIT13 + BIT14) // 100b/x/x/x PMOS Debug Pad Setting (R_DEBUGPAD_DPCTL[2:0])
    #define CND003_MMIO_D0F0_REG10_RSV1         BIT11                   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_DEBUGPAD_DNCTL   (BIT8 + BIT9 + BIT10)   // 100b/x/x/x NMOS Debug Pad Setting (R_DEBUGPAD_DNCTL[2:0])
    #define CND003_MMIO_D0F0_R_IOEDEBUGPAD_EN   BIT7                    // 0/x/x/x High Speed Debug IO Output Enable (R_IOEDEBUGPAD_EN)
    #define CND003_MMIO_D0F0_REG10_RSV3         (BIT5 + BIT6)           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_DBGINGPIOGRP_EN  BIT4                    // 0/x/x/x GPIO Related IOs Used as Debug Signal Enable
    #define CND003_MMIO_D0F0_REG10_RSV0         BIT3                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_SGPIO_EN         BIT2                    // 0/x/x/x Not Used in Current Design. Reserved
    #define CND003_MMIO_D0F0_REG10_RSV4         (BIT0 + BIT1)           // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_VCORE_PMU_SETTING_GRP_0 0x14 // Vcore PMU Setting Group 0
    #define CND003_MMIO_D0F0_REG14_RSV0 0xFFFFFFF8  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SCI_EN     BIT2        // 0/x/x/x SCI Function Enable (SCI_EN)
    #define CND003_MMIO_D0F0_USB_SMISTS BIT1        // 0/x/x/x USB SMI Status Including xHCI/UHCI (USB_SMISTS)
    #define CND003_MMIO_D0F0_USB_SMIEN  BIT0        // 0/x/x/x USB SMI Enable Including xHCI/UHCI (USB_SMIEN)
#define CND003_MMIO_D0F0_VCORE_PMU_SETTING_GRP_1 0x18 // Vcore PMU Setting Group 1
    #define CND003_MMIO_D0F0_OBFF_MAX_7_0       0xFF000000  // 17h/x/x/x Maximum Time between Two Falling WAKE# Edges When Signaling CPU Active
    #define CND003_MMIO_D0F0_OBFF_MIN_7_0       0xFF0000    // 0Fh/x/x/x Minimum Time between Two Falling WAKE# Edges When Signaling CPU Active
    #define CND003_MMIO_D0F0_OBFF_IDLE_7_0      0xFF00      // F0h/x/x/x Minimum WAKE# Pulse Width
    #define CND003_MMIO_D0F0_REG18_RSV0         0xFE        // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_OBFF_MSGTOPA_EN    BIT0        // 0/x/x/x Enable TOPPMU to Translate OBFF Message to OBFF Pattern over WAKE#
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_PCIE_SATA_COMBO_PHY_CFG 0x30 // Strapping Pin Read Back Register PCIE/SATA Combo PHY Configuration
    #define CND003_MMIO_D0F0_REG30_RSV1             0xFE00  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_XH_SPICLK_EDGE_SEL   BIT8    // Dip/x/x/x OPRISC SPI Sample Data Clock Edge Control
    #define CND003_MMIO_D0F0_REG30_RSV0             0xFF    // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_0 0x32 // Strapping Pin Read Back Register Group 0
    #define CND003_MMIO_D0F0_REG32_RSV1     0xFFE0          // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPHYB_M2SEL    BIT4            // Dip/x/x/x RO Register to Reflect the Latch Value of Strapping Pin PHYB_M2SEL
    #define CND003_MMIO_D0F0_REG32_RSV0     (BIT2 + BIT3)   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPHYB_M2EN     BIT1            // Dip/x/x/x Strapping Pin Value of PHYB_M2EN
    #define CND003_MMIO_D0F0_STRAP_SEL      BIT0            // 1b/x/x/x Select Strapping Value Source
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1 0x34 // Strapping Pin Read Back Register Group 1
    #define CND003_MMIO_D0F0_RJTAG_SEL51        BIT15           // 0/x/x/x JTAG Pad Select 
    #define CND003_MMIO_D0F0_R_JTAG_EN          BIT14           // 0/x/x/x JTAG Function Uses GPIO Related Pads
    #define CND003_MMIO_D0F0_R_UART_EN          BIT13           // 0/x/x/x UART Use GPIO Related Pads Enable
    #define CND003_MMIO_D0F0_R_UART_SEL         BIT12           // 0/x/x/x Control 8051 or OpenRISC Use UART Port
    #define CND003_MMIO_D0F0_RPHYB_CFG1         BIT11           // Dip/x/x/x SPI Strapping Value Register of PHYB Configuration Bit 1
    #define CND003_MMIO_D0F0_RPHYB_CFG0         BIT10           // Dip/x/x/x SPI Strapping Value Register of PHYB Configuration Bit 0
    #define CND003_MMIO_D0F0_RPHYA_CFG          (BIT8 + BIT9)   // Dip/x/x/x Control Register of PHYA Configuration
    #define CND003_MMIO_D0F0_RPHYA_REFCLK_SEL   BIT7            // Dip/x/x/x PHYA Reference Clock Selection
    #define CND003_MMIO_D0F0_RPHYB_REFCLK_SEL   BIT6            // Dip/x/x/x PHYB Reference Clock Selection
    #define CND003_MMIO_D0F0_RU31PHY_REFCLK_SEL BIT5            // Dip/x/x/x USB31EPHY Reference Clock Selection
    #define CND003_MMIO_D0F0_ISB2XH_U31PHY_EN   BIT4            // Dip/x/x/x USBH3C Clock Source Selection
    #define CND003_MMIO_D0F0_RIPPLLOK_EN        BIT3            // Dip/x/x/x Detect PLLOK from CKG (RIPPLLOK_EN)
    #define CND003_MMIO_D0F0_RCLK66BK_EN        BIT2            // 0/x/x/x Enable Use 48MHz Clock as 66MHz Backup Clock
    #define CND003_MMIO_D0F0_RXTAL_SWMODE       BIT1            // Dip/x/x/x Reflect the Latch Value of Strapping Pin XTAL_SWMODE
    #define CND003_MMIO_D0F0_RCLK24M_SEL        BIT0            // Dip/x/x/x Reflect the Latch Value of Strapping Pin CLK24M_SEL
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2 0x36 // Strapping Pin Read Back Register Group 2
    #define CND003_MMIO_D0F0_RPEXWAKE_PU        BIT15           // 0/x/x/x Control Register for Pull up of PEXWAKE_ IO Pad
    #define CND003_MMIO_D0F0_RSMI_PU            BIT14           // 0/x/x/x Control Register for Pull up of PEXWAKE_ IO Pad
    #define CND003_MMIO_D0F0_RCMBPHY_CFGDONE    BIT13           // 0/x/x/x Combo PHYB Is Configured Done
    #define CND003_MMIO_D0F0_REEDIS             BIT12           // Dip/x/x/x EEDIS Strapping Pin Latch Value Register
    #define CND003_MMIO_D0F0_RSPIHDR_DBGSEL_SUS 0xFFC           // Dip/x/x/x Suspend Debug Signal Selection
    #define CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL  (BIT0 + BIT1)   // Dip/x/x/x Debug Signal Control Source Selection Control
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_3 0x38 // Strapping Pin Read Back Register Group 3
    #define CND003_MMIO_D0F0_REG38_RSV1             0xF000          // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSPIHDR_DBGSEL_CORE    0xFFC           // Dip/x/x/x Core Debug Signal Selection
    #define CND003_MMIO_D0F0_REG38_RSV0             (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_4 0x3A // Strapping Pin Read Back Register Group 4
    #define CND003_MMIO_D0F0_R8051_AUTOFILL_LEN D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_4 // 0/x/x/x 8051 MCU Auto Fill Length
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_5 0x3C // Strapping Pin Read Back Register Group 5
    #define CND003_MMIO_D0F0_ROP_AUTOFILL_SADR D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_5 // 0/x/x/x Open RISC Auto Fill Instruction Address
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_6 0x3E // Strapping Pin Read Back Register Group 6
    #define CND003_MMIO_D0F0_ROP_AUTOFILL_LEN D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_6 // 0/x/x/x Open RISC Auto Fill Instruction Length
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_7 0x40 // Strapping Pin Read Back Register Group 7
    #define CND003_MMIO_D0F0_ROP_AUTOFILL_DATA_SADR D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_7 // 0/x/x/x Open RISC Auto Fill Data Address
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_8 0x44 // Strapping Pin Read Back Register Group 8
    #define CND003_MMIO_D0F0_ROP_AUTOFILL_DATA_LEN D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_8 // 0/x/x/x Open RISC Auto Fill Data Length
#define CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_PD_SMBUS_SLAVE_ADR 0x46 // Strapping Pin Read Back Register PD SMBus Slave Address
    #define CND003_MMIO_D0F0_RSPI_CLK_EN        BIT15   // 0/x/x/x xHCI OpenRISC SPI Sample Clock Edge Selection
    #define CND003_MMIO_D0F0_RPD_SMB_ADDR_P1    0x7F00  // Dip/x/x/x PD SMBus Slave Address for Port 1
    #define CND003_MMIO_D0F0_RCLK48M_SEL        BIT7    // 0/x/x/x USBC 48MHz Logic Clock Source Select 
    #define CND003_MMIO_D0F0_RPD_SMB_ADDR_P0    0x7F    // Dip/x/x/x PD SMBus Slave Address for Port 0
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_0 0x50 // CKGSRC Setting Group 0
    #define CND003_MMIO_D0F0_REG50_RSV1         BIT7    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_DISSPI             BIT6    // Dip/x/x/x Strapping Pin SPIROM Detection Function 
    #define CND003_MMIO_D0F0_REPHY_CLK100_EN    BIT5    // 1b/x/x/x 100M Differential Clock Output Control
    #define CND003_MMIO_D0F0_STRAP_SEL_SUS      BIT4    // 0/x/x/x Strapping Value Source Select
    #define CND003_MMIO_D0F0_REG50_RSV0         BIT3    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_INSUS    BIT2    // 1b/x/x/x Set PLLRGMII during Core Power off
    #define CND003_MMIO_D0F0_RPLLPCIEAON_INSUS  BIT1    // Dip/x/x/x Set PLLPCIEA during Core Power off
    #define CND003_MMIO_D0F0_RPLLPCIEBON_INSUS  BIT0    // 0b/x/x/x Set PLLPCIEB  during Core Power off
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1 0x51 // CKGSRC Setting Group 1
    #define CND003_MMIO_D0F0_REG51_RSV1     BIT7                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSRC_CP        (BIT4 + BIT5 + BIT6)    // Dip/x/x/x PLLPCIEA/B CP Current Setting
    #define CND003_MMIO_D0F0_REG51_RSV0     (BIT2 + BIT3)           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RUSBCLK_SEL    BIT1                    // 0/x/x/x USB Clock Selection 
    #define CND003_MMIO_D0F0_RSATACLK_SEL   BIT0                    // 0/x/x/x SATA Clock Selection 
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2 0x52 // CKGSRC Setting Group2
    #define CND003_MMIO_D0F0_RSRC_M_A           0xFF00                  // Dip/x/x/x PLLPCIEA Output Frequency Setting
    #define CND003_MMIO_D0F0_R_BUSXP3D0F0_HIDE  BIT7                    // 0/x/x/x Bus X+3 D0F0 Hide or Not Control Register
    #define CND003_MMIO_D0F0_RSRC_SSCMA_A       (BIT4 + BIT5 + BIT6)    // 101b/x/x/x CKGSRC PLLPCIEA SSC Magnitude
    #define CND003_MMIO_D0F0_REG52_RSV0         (BIT2 + BIT3)           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSRC_SSCSPRD_A     BIT1                    // 0/x/x/x CKGSRC PLLPCIEA SSC Spread Mode
    #define CND003_MMIO_D0F0_RSRC_SSCEN_A       BIT0                    // 1b/x/x/x CKGSRC PLLPCIEA SSC Enable
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_3 0x54 // CKGSRC Setting Group 3
    #define CND003_MMIO_D0F0_RSRC_M_B       0xFF00                  // Dip/x/x/x PLLPCIEB Output Frequency Setting
    #define CND003_MMIO_D0F0_REG54_RSV1     BIT7                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSRC_SSCMA_B   (BIT4 + BIT5 + BIT6)    // 101b/x/x/x CKGSRC PLLPCIEB SSC Magnitude
    #define CND003_MMIO_D0F0_REG54_RSV0     (BIT2 + BIT3)           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSRC_SSCSPRD_B BIT1                    // 0/x/x/x CKGSRC PLLPCIEB SSC Spread Mode
    #define CND003_MMIO_D0F0_RSRC_SSCEN_B   BIT0                    // 1b/x/x/x CKGSRC PLLPCIEB SSC Enable
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_4 0x56 // CKGSRC Setting Group 4
    #define CND003_MMIO_D0F0_RSRC_DRVSTR_P  0xF0    // 1000b/x/x/x CKGSRC IO P-driving Strength Setting Input
    #define CND003_MMIO_D0F0_RSRC_DRVSTR_N  0xF     // 1000b/x/x/x CKGSRC IO N-driving Strength Setting Input
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_5 0x57 // CKGSRC Setting Group 5
    #define CND003_MMIO_D0F0_REG57_RSV0 0xF8                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSRC_VDDIO (BIT0 + BIT1 + BIT2)    // 100b/x/x/x CKGSRC IO Voltage Setting
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_6 0x58 // CKGSRC Setting Group 6
    #define CND003_MMIO_D0F0_REG58_RSV1     BIT15           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSATA_PU_IO    BIT14           // 1b/x/x/x SATACLKN/P0 IO Power up
    #define CND003_MMIO_D0F0_RUSB_PU_IO     (BIT12 + BIT13) // 11b/x/x/x USBCLKN/P[1:0] IO Power up
    #define CND003_MMIO_D0F0_REG58_RSV0     (BIT10 + BIT11) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPCIE_PU_IO    0x3FF           // 3ffh/x/x/x PCIECLKN/P[9:0] IO Power up
#define CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_7 0x5A // CKGSRC Setting Group 7
    #define CND003_MMIO_D0F0_REG5A_RSV1     BIT15           // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RSATA_TNO_IO   BIT14           // 1b/x/x/x SATACLKN/P0 IO Power up
    #define CND003_MMIO_D0F0_RUSB_TNO_IO    (BIT12 + BIT13) // 11b/x/x/x USBCLKN/P[1:0] IO Power up
    #define CND003_MMIO_D0F0_REG5A_RSV0     (BIT10 + BIT11) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPCIE_TNO_IO   0x3FF           // 3FFh/x/x/x PCIECLKN/P[9:0] IO Power up
#define CND003_MMIO_D0F0_REFCLK_HWEN 0x60 // REFCLK*_HWEN
    #define CND003_MMIO_D0F0_REG60_RSV0     0xFF00  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_REFCLK7_HWEN   BIT7    // 0b/x/x/x REFCLK7_HWEN
    #define CND003_MMIO_D0F0_REFCLK6_HWEN   BIT6    // 0b/x/x/x REFCLK6_HWEN
    #define CND003_MMIO_D0F0_REFCLK5_HWEN   BIT5    // 0b/x/x/x PCIECLK5[P|N] Is Controlled by HW Enable
    #define CND003_MMIO_D0F0_REFCLK4_HWEN   BIT4    // 0b/x/x/x PCIECLK4[P|N] Is Controlled by HW Enable
    #define CND003_MMIO_D0F0_REFCLK3_HWEN   BIT3    // 0b/x/x/x PCIECLK3[P|N] Is Controlled by HW Enable
    #define CND003_MMIO_D0F0_REFCLK2_HWEN   BIT2    // 0b/x/x/x PCIECLK2[P|N] Is Controlled by HW Enable
    #define CND003_MMIO_D0F0_REFCLK1_HWEN   BIT1    // 0b/x/x/x PCIECLK1[P|N] Is Controlled by HW Enable
    #define CND003_MMIO_D0F0_REFCLK0_HWEN   BIT0    // 0b/x/x/x PCIECLK0[P|N] Is Controlled by HW Enable
#define CND003_MMIO_D0F0_STATIC_CLK_ENABLE 0x62 // Static Clock Enable
    #define CND003_MMIO_D0F0_REG62_RSV0     0xFFFE  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_ENCFGREG_FECLK BIT0    // 1b/x/x/x Enable CFGREG_FECLK
#define CND003_MMIO_D0F0_MIX_REG_CFG 0x64 // Mix Register Configuration
    #define CND003_MMIO_D0F0_REG64_RSV0         0xFE00  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_CKBUFTX_MODE_SEL BIT8    // 0/x/x/x BUFFER_ CKG Mode Select 
    #define CND003_MMIO_D0F0_RCKBUF_CLKTX_ADJ   0xFF    // 00h/x/x/x BUFFER_ CKG Buffer Option
#define CND003_MMIO_D0F0_VSUS_GENERAL_PURPOSE_INPUT 0x70 // Vsus General Purpose Input
    #define CND003_MMIO_D0F0_REG70_RSV0 0xFFF0  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_GPIONI     0xF     // 0/x/x/x General Purpose Input Status
#define CND003_MMIO_D0F0_VSUS_GENERAL_PURPOSE_OUTPUT 0x72 // Vsus General Purpose Output
    #define CND003_MMIO_D0F0_REG72_RSV0 0xFFF0  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_GPIONO     0xF     // 1111b/x/x/x Reads from this register return the last value written (held on c...
#define CND003_MMIO_D0F0_VSUS_PAD_SETTING_GRP_0 0x74 // Vsus Pad Setting Group 0
    #define CND003_MMIO_D0F0_REG74_RSV3 0xFF000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_REG74_RSV2 0xFF0000    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_REG74_RSV1 0xFF00      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_REG74_RSV0 0xFF        // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_VSUS_PAD_SETTING_GRP_1 0x78 // Vsus Pad Setting Group 1
    #define CND003_MMIO_D0F0_REG78_RSV0             0xF800  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_PAD_USB31P_CTRL_P0   BIT10   // 0/x/x/x USB31_P_CTRL_P0 Pin Mux Control
    #define CND003_MMIO_D0F0_R_PAD_USB31P_CTRL_P1   BIT9    // 0/x/x/x USB31P_CTRL_P1 Pin Mux Control
    #define CND003_MMIO_D0F0_REG78_RSV1             0x1F8   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_PAD_CCBMCGPIO8       BIT2    // 0/x/x/x CCBMCGPIO8 Pin Mux Control
    #define CND003_MMIO_D0F0_R_PAD_CCBMCGPIO9       BIT1    // 0/x/x/x CCBMCGPIO9 Pin Mux Control
    #define CND003_MMIO_D0F0_REG78_RSV2             BIT0    // 0/x/x/x Reserved
#define CND003_MMIO_D0F0_VSUS_PAD_SETTING_GRP_2 0x7A // Vsus Pad Setting Group 2
    #define CND003_MMIO_D0F0_R_PAD_USBHOC0      (BIT14 + BIT15) // 0/x/x/x USBHCO0 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_USBHOC1      (BIT12 + BIT13) // 0/x/x/x USBHCO1 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_USBHOC2      (BIT10 + BIT11) // 0/x/x/x USBHCO2 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_GNIC_PMEB    (BIT8 + BIT9)   // 0/x/x/x USBHCO3 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_EEPROM_CS    (BIT6 + BIT7)   // 0/x/x/x USBHCO4 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_EEPROM_SK    (BIT4 + BIT5)   // 0/x/x/x USBHCO5 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_EEPROM_SI    (BIT2 + BIT3)   // 0/x/x/x USBHCO6 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_EEPROM_SO    (BIT0 + BIT1)   // 0/x/x/x USBHCO7 Pin Mux Control Register
#define CND003_MMIO_D0F0_VSUS_PAD_SETTING_GRP_3 0x7C // Vsus Pad Setting Group 3
    #define CND003_MMIO_D0F0_REG7C_RSV2         (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_I2CM_EN          BIT12                   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_DBGINRGGRP_EN    BIT11                   // 0/x/x/x RGMII Related IO Used for Debug Signal Enable
    #define CND003_MMIO_D0F0_REG7C_RSV1         BIT10                   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_DBGINOCGRP_EN    BIT9                    // 0/x/x/x USBOC Related IO Used for Debug Signal Enable
    #define CND003_MMIO_D0F0_R_DBGINCCGRP_EN    BIT8                    // 0/x/x/x CCPHY Related IO Used for Debug Signal Enable
    #define CND003_MMIO_D0F0_REG7C_RSV0         0xFC                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_PAD_USBHOC_9     BIT1                    // 0/x/x/x USBHOC_9 Pin Mux Control Register
    #define CND003_MMIO_D0F0_R_PAD_USBHOC_8     BIT0                    // 0/x/x/x USBHOC_8 Pin Mux Control Register
#define CND003_MMIO_D0F0_VSUS_PMU_GENERAL_SETTING 0x80 // Vsus PMU General Setting
    #define CND003_MMIO_D0F0_SPEED_32K      BIT15   // 0/x/x/x SPEED 32K Clock
    #define CND003_MMIO_D0F0_REG80_RSV0     0x7FF8  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_LDRSTEN        BIT2    // 0b/x/x/x Enable to Qualify PCIe RC Link down Reset to GLBRST_
    #define CND003_MMIO_D0F0_EIDLE_WAKEEN   BIT1    // 0/x/x/x Enable PCIe GEN3 EPHY Electric-idle Falling Edge to Wake up
    #define CND003_MMIO_D0F0_PCIERST_WAKEEN BIT0    // 0/x/x/x Enable RC PEXRST# Rising Edge to Wake up
#define CND003_MMIO_D0F0_VSUS_PMU_XHCI_SETTING 0x82 // Vsus PMU xHCI Setting
    #define CND003_MMIO_D0F0_REG82_RSV1     (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_XHCI_STMR      0x1F00                  // 1Fh/x/x/x xHCI Power Chain Settle Time Bits[10:0]
    #define CND003_MMIO_D0F0_REG82_RSV0     (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_XHCI_PWRSTS    (BIT3 + BIT4)           // 11b/x/x/x Power State of xHCI
    #define CND003_MMIO_D0F0_RXHCI_PWRON    BIT2                    // 0/x/x/x Indication of the Power ON Sequence
    #define CND003_MMIO_D0F0_RXHCI_PWROFF   BIT1                    // 0/x/x/x Indication of the Power OFF Sequence
    #define CND003_MMIO_D0F0_XHCI_PWRCTL    BIT0                    // 1b/x/x/x Power Control for xHCI
#define CND003_MMIO_D0F0_VSUS_PMU_SATAD15F0_SETTING 0x84 // Vsus PMU SATAD15F0 Setting
    #define CND003_MMIO_D0F0_REG84_RSV1         (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SAD15F0_STMR       0x1F00                  // 1Fh/x/x/x SATAD15F0 Power Chain Settle Time Bits[10:0]
    #define CND003_MMIO_D0F0_REG84_RSV0         (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SAD15F0_PWRSTS     (BIT3 + BIT4)           // 11b/x/x/x Power State of SATAD15F0
    #define CND003_MMIO_D0F0_RSAD15F0_PWRON     BIT2                    // 0/x/x/x Indication of the Power ON Sequence
    #define CND003_MMIO_D0F0_RSAD15F0_PWROFF    BIT1                    // 0/x/x/x Indication of the Power OFF Sequence
    #define CND003_MMIO_D0F0_SAD15F0_PWRCTL     BIT0                    // 1b/x/x/x Power Control for SATAD15F0
#define CND003_MMIO_D0F0_VSUS_PMU_PHYA_SETTING 0x86 // Vsus PMU PHYA Setting
    #define CND003_MMIO_D0F0_REG86_RSV1     (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_PHYA_STMR      0x1F00                  // 1Fh/x/x/x PHYA Power Chain Settle Time Bits[10:0]
    #define CND003_MMIO_D0F0_REG86_RSV0     (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_PHYA_PWRSTS    (BIT3 + BIT4)           // 11b/x/x/x Power State of PHYA
    #define CND003_MMIO_D0F0_RPHYA_PWRON    BIT2                    // 0/x/x/x Indication of the Power On Sequence
    #define CND003_MMIO_D0F0_RPHYA_PWROFF   BIT1                    // 0/x/x/x Indication of the Power Off Sequence
    #define CND003_MMIO_D0F0_PHYA_PWRCTL    BIT0                    // 1b/x/x/x Power Control for PHYA
#define CND003_MMIO_D0F0_VSUS_PMU_PHYB_SETTING 0x88 // Vsus PMU PHYB Setting
    #define CND003_MMIO_D0F0_REG88_RSV1     (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_PHYB_STMR      0x1F00                  // 1Fh/x/x/x PHYB Power Chain Settle Time Bits[10:0]
    #define CND003_MMIO_D0F0_REG88_RSV0     (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_PHYB_PWRSTS    (BIT3 + BIT4)           // 11b/x/x/x Power State of PHYB
    #define CND003_MMIO_D0F0_RPHYB_PWRON    BIT2                    // 0/x/x/x Indication of the Power On Sequence
    #define CND003_MMIO_D0F0_RPHYB_PWROFF   BIT1                    // 0/x/x/x Indication of the Power Off Sequence
    #define CND003_MMIO_D0F0_PHYB_PWRCTL    BIT0                    // 1b/x/x/x Power Control for PHYB
#define CND003_MMIO_D0F0_EFUSE_SETTING 0x90 // EFUSE Setting
    #define CND003_MMIO_D0F0_REG90_RSV1     0xFE000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_DRV_EFUSE_REQ  BIT24       // 0/x/x/x Request of Software to Read EFUSE Data of ZX-200 ((CND003)) Transmitter
    #define CND003_MMIO_D0F0_DRV_EFUSE_DATA 0xFF0000    // 0/x/x/x EFUSE 8-bit Data
    #define CND003_MMIO_D0F0_REG90_RSV0     0xF800      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_DRV_EFUSE_ADDR 0x7FF       // 0/x/x/x Efuse Read Address (8-bit Align) from Driver
#define CND003_MMIO_D0F0_USB2EPHY2_SETTING 0x94 // USB2EPHY2 Setting
    #define CND003_MMIO_D0F0_REG94_RSV0 0xFFFFFFFE  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_USB_MODE   BIT0        // 1b/x/x/x USB2EPHY2 Control Mode Selection
#define CND003_MMIO_D0F0_RGMII_PAD_SETTING_GRP_0 0x98 // RGMII Pad Setting Group 0
    #define CND003_MMIO_D0F0_REG98_RSV1         (BIT13 + BIT14 + BIT15) // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_RGMII_O_DPCTL    0x1F00                  // 0 1010b/x/x/x Control bd8rt_rgm_O Pad PMOS Driver Strength (RGMII_O_DPCTL[4:0])
    #define CND003_MMIO_D0F0_REG98_RSV0         (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_RGMII_O_DNCTL    0x1F                    // 0 0110b/x/x/x Control bd8rt_rgm_O Pad NMOS Driver Strength (RGMII_O_DNCTL[4:0])
#define CND003_MMIO_D0F0_RGMII_PAD_SETTING_GRP_1 0x9A // RGMII PAD Setting Group 1
    #define CND003_MMIO_D0F0_REG9A_RSV3         BIT15                   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_RGMII_IO_DPCTL   (BIT12 + BIT13 + BIT14) // 100b/x/x/x Control bd8rt_rgm_IO Pad PMOS Driver Strength (RGMII_IO_DPCTL[2:0])
    #define CND003_MMIO_D0F0_REG9A_RSV2         BIT11                   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_RGMII_IO_DNCTL   (BIT8 + BIT9 + BIT10)   // 100b/x/x/x Control bd8rt_rgm_IO Pad NMOS Driver Strength (RGMII_IO_DNCTL[2:0])
    #define CND003_MMIO_D0F0_REG9A_RSV1         BIT7                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_RGMII_I_DPCTL    (BIT4 + BIT5 + BIT6)    // 100b/x/x/x Control bd8rt_rgm_I Pad PMOS Driver Strength (RGMII_I_DPCTL[2:0]
    #define CND003_MMIO_D0F0_REG9A_RSV0         BIT3                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_RGMII_I_DNCTL    (BIT0 + BIT1 + BIT2)    // 100b/x/x/x Control bd8rt_rgm_I Pad NMOS Driver Strength (RGMII_I_DNCTL[2:0])
#define CND003_MMIO_D0F0_RGMII_PAD_SETTING_GRP_2 0x9C // RGMII PAD Setting Group 2
    #define CND003_MMIO_D0F0_REG9C_RSV0                 0xFFFC0000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_TEST_REG_CORE_ISOEN        BIT17       // 0/x/x/x The TD3 Control Register to Control CORE_ISOEN (TEST_REG_CORE_ISOEN)
    #define CND003_MMIO_D0F0_TEST_REG_PHYA_PWR_ISOEN    BIT16       // 0/x/x/x The TD3 Control Register to Control PHYA_PWR_ISOEN (TEST_REG_PHYA_PWR...
    #define CND003_MMIO_D0F0_TEST_REG_PHYB_PWR_ISOEN    BIT15       // 0/x/x/x The TD3 Control Register to Control PHYB_PWR_ISOEN (TEST_REG_PHYB_PWR...
    #define CND003_MMIO_D0F0_TEST_REG_XHCI_PWR_ISOEN    BIT14       // 0/x/x/x The TD3 Control Register to Control XHCI_PWR_ISOEN
    #define CND003_MMIO_D0F0_TEST_REG_SATA_PWR_ISOEN    BIT13       // 0/x/x/x The TD3 Control Register to Control SATA_PWR_ISOEN (TEST_REG_SATA_PWR...
    #define CND003_MMIO_D0F0_TEST_PWR_PSO_EN            BIT12       // 0/x/x/x TD3 Control ISOEN/PSO Enable (TEST_PWR_PSO_EN)
    #define CND003_MMIO_D0F0_TEST_PHYA_PWR_PSO          BIT11       // 0/x/x/x TD3 Control PHYA PSO Signal (TEST_PHYA_PWR_PSO)
    #define CND003_MMIO_D0F0_TEST_PHYB_PWR_PSO          BIT10       // 0/x/x/x TD3 Control PHYB PSO Signal (TEST_PHYB_PWR_PSO)
    #define CND003_MMIO_D0F0_TEST_XHCI_PWR_PSO          BIT9        // 0/x/x/x TD3 Control XHCI PSO Signal (TEST_XHCI_PWR_PSO)
    #define CND003_MMIO_D0F0_TEST_SATA_PWR_PSO          BIT8        // 0/x/x/x TD3 Control SATA PSO Signal (TEST_SATA_PWR_PSO)
    #define CND003_MMIO_D0F0_PE2ISB_PHYA_PWR_PSOACK     BIT7        // 1/x/x/x PCe PHYA Part PSO ACK (PE2ISB_PHYA_PWR_PSOACK)
    #define CND003_MMIO_D0F0_PE2ISB_PHYB_PWR_PSOACK     BIT6        // 1/x/x/x PCIe PHYB Part PSO ACK (PE2ISB_PHYB_PWR_PSOACK)
    #define CND003_MMIO_D0F0_XH2ISB_XHCI_PWR_PSOACK     BIT5        // 1/x/x/x USB3HC PSO ACK (XH2ISB_XHCI_PWR_PSOACK)
    #define CND003_MMIO_D0F0_SAD15F0_PWR_PSOACK         BIT4        // 1/x/x/x SATA D15F0 PSO ACK (SAD15F0_PWR_PSOACK)
    #define CND003_MMIO_D0F0_R_RGMIO_PDB_RXBIAS         BIT3        // 0/x/x/x RGMIO_PDB_RXBIAS
    #define CND003_MMIO_D0F0_R_RGMIO_PDB_RXVREF         BIT2        // 0/x/x/x RGMIO_PDB_RXVREF
    #define CND003_MMIO_D0F0_R_RGMIO_RX_SEL             BIT1        // 0/x/x/x Control RGMII IO Use SCHMITT Trigger or Comparator (RGMIO_RX_SEL)
    #define CND003_MMIO_D0F0_R_RGMII_VSEL               BIT0        // 1b/x/x/x RGMII IO Voltage Select  (R_RGMII_VSEL)
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_0 0xA0 // PLLRGMII Setting Group 0
    #define CND003_MMIO_D0F0_REGA0_RSV0         0xFC    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_SSCSPRD  BIT1    // 0/x/x/x SSC Spread Mode
    #define CND003_MMIO_D0F0_RPLLRGMII_SSCEN    BIT0    // 0/x/x/x SSC Enable
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_1 0xA1 // PLLRGMII Setting Group 1
    #define CND003_MMIO_D0F0_RPLLRGMII_SSCMA    0xF0                    // 0111b/x/x/x SSC Magnitude
    #define CND003_MMIO_D0F0_REGA1_RSV0         BIT3                    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_CP       (BIT0 + BIT1 + BIT2)    // 100b/x/x/x CP Current Setting
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_2 0xA2 // PLLRGMII Setting Group 2
    #define CND003_MMIO_D0F0_REGA2_RSV0     0xFF00  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_M    0xFF    // 12h/x/x/x Fckout=Frefclk*(M+2+N/2^20)/2
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_3 0xA4 // PLLRGMII Setting Group 3
    #define CND003_MMIO_D0F0_REGA4_RSV0     0xFFF00000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_N    0xFFFFF     // D 5555h/x/x/x Fckout=Frefclk*(M+2+N/2^20)/2
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_4 0xA8 // PLLRGMII Setting Group 4
    #define CND003_MMIO_D0F0_REGA8_RSV0             0xFF000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_SSCOFFSET    0xFFFFFF    // 01 5555h/x/x/x PLLRGMII's Parameter (RPLLRGMII_SSCOFFSET[23:0])
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_5 0xAC // PLLRGMII Setting Group 5
    #define CND003_MMIO_D0F0_REGAC_RSV0         0xFF000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_SSCSTEP  0xFFFFFF    // 00 01C7h/x/x/x PLLRGMII's Parameter (RPLLRGMII_SSCSTEP]23:0])
#define CND003_MMIO_D0F0_PLLRGMII_SETTING_GRP_6 0xB0 // PLLRGMII Setting Group 6
    #define CND003_MMIO_D0F0_REGB0_RSV0             0xF000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RPLLRGMII_SSCSTPSUM    0xFFF   // 180h/x/x/x PLLRGMII's Parameter (RPLLRGMII_SSCSTPSUM[11:0])
#define CND003_MMIO_D0F0_PLLRGMII_TEST_SETTING 0xB2 // PLLRGMII Test Setting
    #define CND003_MMIO_D0F0_REGB2_RSV0     0xFC    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_TEST_RGMII_IO  BIT1    // 0/x/x/x RGMII_IO Pad Enable Used by TD3
    #define CND003_MMIO_D0F0_TEST_RGMII_A   BIT0    // 0/x/x/x Control the Output Value of RGMII_IO by TD3
#define CND003_MMIO_D0F0_DEBUG_SEL_SETTING_0 0xC0 // Debug Select Setting 0
    #define CND003_MMIO_D0F0_REGC0_RSV1     0xF0000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_SEL_G1    0xFFF0000   // 0/x/x/x Group 1 16-bit Debug Signal Group Selection (RDBG_SEL_G1[11:0])
    #define CND003_MMIO_D0F0_REGC0_RSV0     0xF000      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_SEL_G0    0xFFF       // 0/x/x/x Group 0 16-bit Debug Signal Group Selection (RDBG_SEL_G0[11:0])
#define CND003_MMIO_D0F0_DEBUG_SEL_SETTING_1 0xC4 // Debug Select Setting 1
    #define CND003_MMIO_D0F0_REGC4_RSV1     0xF0000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_SEL_G3    0xFFF0000   // 0/x/x/x Group 3 16-bit Debug Signal Group Selection (RDBG_SEL_G3[11:0])
    #define CND003_MMIO_D0F0_REGC4_RSV0     0xF000      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_SEL_G2    0xFFF       // 0/x/x/x Group 2 16-bit Debug Signal Group Selection (RDBG_SEL_G2[11:0])
#define CND003_MMIO_D0F0_DEBUG_SEL_SETTING_2 0xC8 // Debug Select Setting 2
    #define CND003_MMIO_D0F0_REGC8_RSV3             0xF0000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_HIGH_MODULE_SEL   0xF000000   // 0/x/x/x High Speed Debug Signal Module Selection (RDBG_HIGH_MODULE_SEL[3:0])
    #define CND003_MMIO_D0F0_REGC8_RSV2             0xF00000    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_SUS_MODULE_SEL    0xF0000     // 0/x/x/x Suspend Module Debug Signal Module Selection
    #define CND003_MMIO_D0F0_REGC8_RSV1             0xF000      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_MODULE_SEL_G1     0xF00       // 0/x/x/x Low Speed Debug Signal Module Selection (High 32-bit) (RDBG_MODULE_SE...
    #define CND003_MMIO_D0F0_REGC8_RSV0             0xF0        // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_MODULE_SEL_G0     0xF         // 0/x/x/x Low Speed Debug Signal Module Selection (Low 32-bit) (RDBG_MODULE_SEL...
#define CND003_MMIO_D0F0_DEBUG_SEL_SETTING_3 0xCC // Debug Select Setting 3
    #define CND003_MMIO_D0F0_REGCC_RSV0     0xF000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_RDBG_HIGH_SEL  0xFFF   // 0/x/x/x High Speed Debug Signal Group Selection (RDBG_HIGH_SEL[11:0])
#define CND003_MMIO_D0F0_DEBUG_SEL_SETTING_4 0xCE // Debug Select Setting 4
    #define CND003_MMIO_D0F0_REGCE_RSV0         0xFFFC  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_R_SUS_DBG_EN       BIT1    // 0/x/x/x 16-bit Suspend Debug Signal Output Enable (R_SUS_DBG_EN)
    #define CND003_MMIO_D0F0_R_DBGBYPASS_CDC    BIT0    // 1b/x/x/x (R_DBGBYPASS_CDC)
#define CND003_MMIO_D0F0_SPIROM_DEBUG_SETTING_0 0xD0 // SPIROM Debug Setting 0
    #define CND003_MMIO_D0F0_REGD0_RSV1     0xF0000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_SEL_G1 0xFFF0000   // Dip/x/x/x The SPI Strapping Value of Group 1 16-bit Debug Signal Selection (S...
    #define CND003_MMIO_D0F0_REGD0_RSV0     0xF000      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_SEL_G0 0xFFF       // Dip/x/x/x The SPI Strapping Value of Group 0 16-bit Debug Signal Selection (S...
#define CND003_MMIO_D0F0_SPIROM_DEBUG_SETTING_1 0xD4 // SPIROM Debug Setting 1
    #define CND003_MMIO_D0F0_REGD4_RSV1     0xF0000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_SEL_G3 0xFFF0000   // Dip/x/x/x The SPI Strapping Value of Group 1 16-bit Debug Signal Selection (S...
    #define CND003_MMIO_D0F0_REGD4_RSV0     0xF000      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_SEL_G2 0xFFF       // Dip/x/x/x The SPI Strapping Value of Group 2 16-bit Debug Signal Selection (S...
#define CND003_MMIO_D0F0_SPIROM_DEBUG_SETTING_2 0xD8 // SPIROM Debug Setting 2
    #define CND003_MMIO_D0F0_REGD8_RSV3                 0xF0000000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_HIGH_MODULE_SEL    0xF000000   // Dip/x/x/x The SPI Strapping Value of High speed Debug Signal Module Selection...
    #define CND003_MMIO_D0F0_REGD8_RSV2                 0xF00000    // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_SUS_MODULE_SEL     0xF0000     // Dip/x/x/x The SPI Strapping Value of Debug Signal Suspend Module Selection (S...
    #define CND003_MMIO_D0F0_REGD8_RSV1                 0xF000      // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_MODULE_SEL_G1      0xF00       // Dip/x/x/x The SPI Strapping Value of High 32-bit Low Speed Debug Signal Modul...
    #define CND003_MMIO_D0F0_REGD8_RSV0                 0xF0        // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_MODULE_SEL_G0      0xF         // Dip/x/x/x The SPI Strapping Value of Low 32-bit Low Speed Debug Signal Module...
#define CND003_MMIO_D0F0_SPIROM_DEBUG_SETTING_3 0xDC // SPIROM Debug Setting 3
    #define CND003_MMIO_D0F0_REGDC_RSV0         0xF000  // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBG_HIGH_SEL   0xFFF   // Dip/x/x/x The SPI Strapping Value of High Speed Debug Signal Group Selection ...
#define CND003_MMIO_D0F0_SPIROM_DEBUG_SETTING4 0xDE // SPIROM Debug setting4
    #define CND003_MMIO_D0F0_REGDE_RSV0             (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_MMIO_D0F0_SPI_DBGINGPIOGRP_EN    BIT5            // Dip/x/x/x The SPI Strapping Value of GPIO IO Group Used as Debug Signal Enabl...
    #define CND003_MMIO_D0F0_SPI_DBGINCCGRP_EN      BIT4            // Dip/x/x/x The SPI Strapping Value of U3CC IO Group Used as Debug Signal Enabl...
    #define CND003_MMIO_D0F0_SPI_DBGINOCGRP_EN      BIT3            // Dip/x/x/x The SPI Strapping Value of U3CC IO Group Used as Debug Signal Enabl...
    #define CND003_MMIO_D0F0_SPI_DBGINRGGRP_EN      BIT2            // Dip/x/x/x The SPI Strapping Value of RGMII IO Group Used as Debug Signal Enab...
    #define CND003_MMIO_D0F0_REGDE_RSV              (BIT0 + BIT1)   // 0/x/x/x Reserved
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
