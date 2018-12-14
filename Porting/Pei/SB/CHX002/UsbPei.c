/** @file
   ZX-E(CHX002) Asia SbPei library functions : UsbPei.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "AsiaCommon.h"
#include "AsiaIoLib.h"

#include EFI_PPI_DEFINITION(AsiaSbPpi)
#include "AsiaSbPeim.h"
#include "SbLibPpi.h"
#include "SbDriving.h"
#include "CHX002Cfg.h"
#include "UsbPei.h"

STATIC ASIA_IO_TABLE_6432_REV D18F0Xhci_SbPeiInit_TBL[]= {
    //Link Layer TD7.04 XHCOPTRC55[0] = 0b USB3EPHY
    {0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX54_XHCOPTRX54),	0x100,	0x000}, 

    {0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX40_XHCOPTRX40),	0x01000000,	0x01000000},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x0c},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x40,	0x40},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x64},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x3fff,	0x222e},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0xc0},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x10,	0x0},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x158},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x1,	0x1},

    {0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10110},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x7ff07ff,	0xb405a0},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x1001C},       // Patch for KB will miss key value under hub that has a camera attached also issue

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x4000,	0x4000},            // Patch for KB will miss key value under hub that has a camera attached also issue

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10614},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0xc00,	0x0},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10620},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0xffffffff,	0xa0000000},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x20078},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0xc0,	0x40},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x20114},       // R_RXP1PHYSTATUS = 0

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x100,	0x0},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x20214},       // R_RXP1PHYSTATUS = 0

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x100,	0x0},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20128},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x8,	0x8},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20228},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x8,	0x8},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20154},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x100,	0x100},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20254},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x100,	0x100},

    {0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2015C},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x20000000,	0x20000000},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2025C},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0x20000000,	0x20000000},


	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20168},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x8000000,	0x8000000},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20268},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTIONAL_BITS_CFG_DATA),	0x8000000,	0x8000000},

	{0x00,	0xFF,	(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX40_XHCOPTRX40),	0x01000000,	0x00000000},

	{0xFF,	0x00,	0x00,	0x00,	0x00} 
};


STATIC ASIA_IO_TABLE_6432_REV D14F0Uhci_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CHX002_D14F0UHCI|0x48),	0x8020000,	0x0},//for ellis comment this bit need to be set to 0 for s4 mouse issue
    {0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV D16F0Uhci_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CHX002_D16F0UHCI|0x48),	0x8020000,	0x0},//Rx4a bit 1 =0,Rx4b bit3=0
    {0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV D16F1Uhci_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CHX002_D16F1UHCI|0x48),	0x8020000,	0x0},//Rx4a bit 1 =0,Rx4b bit3=0
    {0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV D14F7Ehci_SbPeiInit_TBL[]={
	{0x00,  0xFF,   (CHX002_D14F7EHCI|D14F7_PHY_CTL_1),     0x10000000,    0x10000000}, //ellis comment 0914,need set Rx4F bit4 to 1.
	{0x00,  0xFF,   (CHX002_D14F7EHCI|D14F7_USB_CP4_CTL_1),     0x33000,    0x30000},      //PMU WakeUp Control for S1s;,Rx65 bit4 for lenovo s4 issue patch
    {0x00,  0xFF,   (CHX002_D14F7EHCI|D14F7_EHCIOPTIONAL_BITS_CFG_ADR),     0xFFFFF,    0x00000},      //LockSpd
    {0x00,  0xFF,   (CHX002_D14F7EHCI|D14F7_EHCIOPTIONAL_BITS_CFG_DATA),    0x0300,     0x0},

    {0x00,  0xFF,   (CHX002_D14F7EHCI|D14F7_EHCIOPTIONAL_BITS_CFG_ADR),     0xFFFFF,    0x0000C},      //U2PHY_TEST
    {0x00,  0xFF,   (CHX002_D14F7EHCI|D14F7_EHCIOPTIONAL_BITS_CFG_DATA),    0xF0000000, 0xA0000000},
    {0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV D16F7Ehci_SbPeiInit_TBL[]={
    {0x00,  0xFF,   (CHX002_D16F7EHCI|D16F7_PHY_CTL_1),     0x10000000,    0x10000000}, //ellis comment 0914,need set Rx4F bit4 to 1.
	{0x00,  0xFF,   (CHX002_D16F7EHCI|D16F7_USB_CP4_CTL_1),     0x33000,    0x30000},      //PMU WakeUp Control for S1s,Rx65 bit4 for lenovo s4 issue patch
    {0x00,  0xFF,   (CHX002_D16F7EHCI|D16F7_EHCIOPTIONAL_BITS_CFG_ADR),     0xFFFFF,    0x00000},      //LockSpd
    {0x00,  0xFF,   (CHX002_D16F7EHCI|D16F7_EHCIOPTIONAL_BITS_CFG_DATA),    0x0300,     0x0},

    {0x00,  0xFF,   (CHX002_D16F7EHCI|D16F7_EHCIOPTIONAL_BITS_CFG_ADR),     0xFFFFF,    0x0000C},      //U2PHY_TEST
    {0x00,  0xFF,   (CHX002_D16F7EHCI|D16F7_EHCIOPTIONAL_BITS_CFG_DATA),    0xF0000000, 0xA0000000},
    {0xFF,	0x00,	0x00,	0x00,	0x00}
};


EFI_STATUS
EFIAPI
UsbPeiInit (
    IN  EFI_PEI_SERVICES        **PeiServices,
        ASIA_SB_CONFIGURATION   *SbCfg
    )
{
    UINT8 mXHCI18_EN = 0;
    UINT8 mUSBC14_EN = 0;
    UINT8 mUSBC16_EN = 0;

    UINT32 D17F0MMIOBar;
    UINT16 PmioBar;

    UINT32 TempData32   = 0;

    D17F0MMIOBar    = AsiaPciRead32(CHX002_BUSC | D17F0_MMIO_SPACE_BASE_ADR) << 8;
    PmioBar         = AsiaPciRead16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE);
    PmioBar         &= D17F0_PMU_PMIOBA;

    // ALJ20180305,add scratch register for DRT tool use only. Remove when for release version
    AsiaPciModify8((CHX002_SCRCH | D0F6_BIOS_SCRATCH_REG_7 + 1),   BIT3|BIT2|BIT1|BIT0,    SbCfg->UsbModeSelect);

    // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
    AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, BIT14);

    //
    // Process patches here
    //
    // Patch for Mode1 cannot recognize USB3.0 device on USB3.0 port
    AsiaIoModify8(  (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN,       PMIO_XHCI_EN);
    if (SbCfg->UsbModeSelect == USB_MODE_SEL_MODEA) {
        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),   D18F0_CPU_OPTCFG,                                           D18F0_CPU_OPTCFG);
        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX13A);
        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA_Byte2),  (OPTCFGXHCI_R_RXHZ_DIS_SS2|OPTCFGXHCI_R_RXHZ_DIS_SS1),      0);
        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),   D18F0_CPU_OPTCFG,                                           0);
    } else {
        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),   D18F0_CPU_OPTCFG,                                           D18F0_CPU_OPTCFG);
        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX13A);
        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA_Byte2),  (OPTCFGXHCI_R_RXHZ_DIS_SS2|OPTCFGXHCI_R_RXHZ_DIS_SS1),      (OPTCFGXHCI_R_RXHZ_DIS_SS2|OPTCFGXHCI_R_RXHZ_DIS_SS1));
        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),   D18F0_CPU_OPTCFG,                                           0);
    }

    //
    // Process Function Enable/Disable
    //
    switch (SbCfg->UsbModeSelect) {
        case USB_MODE_SEL_DISABLE:
            // disable xHCI
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN,                               0x0);
            // disable uHCI
            AsiaPciModify8(   (CHX002_BUSC | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, 0x0);
            // disable eHCI
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      0x0);
            break;

        case USB_MODE_SEL_MODEA:
            // disable xHCI & USBC own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              0x0);
            // enable uHCI D14&D16
            AsiaPciModify8(   (CHX002_BUSC | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3);
            // enable eHCI D14&D16
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2);
            mUSBC14_EN  = 1;
            mUSBC16_EN  = 1;
            break;

        case USB_MODE_SEL_MODEB:
            // enable xHCI & USBC own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              PMIO_XHCI_EN);
            // enable uHCI D14&D16
            AsiaPciModify8(   (CHX002_BUSC | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3);
            // enable eHCI D14&D16
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2);
            mXHCI18_EN  = 1;
            mUSBC14_EN  = 1;
            mUSBC16_EN  = 1;
            break;

        case USB_MODE_SEL_MODEC:
            // enable xHCI & xHCI own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              PMIO_XHCI_EN | PMIO_U2SEL_SUS);
            // disable uHCI
            AsiaPciModify8(   (CHX002_BUSC | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, 0x00);
            // disable eHCI
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      0x00);
            mXHCI18_EN  = 1;
            break;

        case USB_MODE_SEL_MODED:
            // enable xHCI & xHCI own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              PMIO_XHCI_EN | PMIO_U2SEL_SUS);
            // enable uHCI D16
            AsiaPciModify8(   (CHX002_BUSC | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, D17F0_ENUSB1 | D17F0_ENUSB2);
            // enable eHCI D16
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      D17F0MMIO_ENEHCI1);
            mXHCI18_EN  = 1;
            mUSBC16_EN  = 1;
            break;
    }

    if (mUSBC14_EN || mUSBC16_EN || mXHCI18_EN) {
        AsiaIoModify8( (PmioBar + PMIO_USB_AND_XHCI_WAKEUP_TRIGGER_MODE_CTL_REG),  PMIO_WUSB_TRGM,     PMIO_WUSB_TRGM);    // USB and XHCI Wakeup Status trigger mode control
        AsiaPciModify8((CHX002_BUSC + D17F0_PMU_MISC_CFG_2_PWR_WELL),              D17F0_PMU_ENUSBUP,  D17F0_PMU_ENUSBUP); // USB Wakeup for POS / STR / STD / Soft Off

        //
        // Process onboard Usb S4 wakeup
        //
        if (SbCfg->UsbS4WakeupCtrl == USB_S4WAKEUP_ENABLE) {
            AsiaPciModify8((CHX002_SCRCH | D0F6_BIOS_SCRATCH_REG_8 + 1),    BIT6,   BIT6);
        } else {
            AsiaPciModify8((CHX002_SCRCH | D0F6_BIOS_SCRATCH_REG_8 + 1),    BIT6,   0x0);
        }
    }

    if (mUSBC14_EN) {
        PROCESS_SB_R6432M_TABLE(D14F0Uhci_SbPeiInit_TBL,  sizeof(D14F0Uhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        PROCESS_SB_R6432M_TABLE(D14F7Ehci_SbPeiInit_TBL,  sizeof(D14F7Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

        PROCESS_SB_R64326408M_TABLE(D14F7Ehci_Driving_TBL, D14F7Ehci_Driving_TBL_Items);

        //
        // Process OC Pin Mux
        //
        if (SbCfg->UsbOCCtrl == USB_OC_ENABLE) {
            AsiaPciModify32((CHX002_D14F7EHCI | D14F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D14F7_PORTA_OC_MUX | D14F7_PORTB_OC_MUX,    0x1000);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT2 | BIT1 | BIT0);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        } else {
            AsiaPciModify32((CHX002_D14F7EHCI | D14F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D14F7_PORTA_OC_MUX | D14F7_PORTB_OC_MUX,    0xBB00);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= BIT27;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT2 | BIT1 | BIT0);
            TempData32  |= BIT0;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        }

        //
        // Process USBC FLR Control
        //
        if (SbCfg->USBCFLRCtrl == USBC_FLR_ENABLE) {
            AsiaPciModify8((CHX002_D14F0UHCI | D14F0_FLR_AND_VID_OPTIONAL_REG),     D14F0_FLR_OPTIONAL,     D14F0_FLR_OPTIONAL);
            AsiaPciModify8((CHX002_D14F7EHCI | D14F7_FLR_AND_VID_OPTIONAL_REG),     D14F7_FLR_OPTIONAL,     D14F7_FLR_OPTIONAL);
        } else {
            AsiaPciModify8((CHX002_D14F0UHCI | D14F0_FLR_AND_VID_OPTIONAL_REG),     D14F0_FLR_OPTIONAL,     0x00);
            AsiaPciModify8((CHX002_D14F7EHCI | D14F7_FLR_AND_VID_OPTIONAL_REG),     D14F7_FLR_OPTIONAL,     0x00);
        }
    } else {

    }

    if (mUSBC16_EN) {
        PROCESS_SB_R6432M_TABLE(D16F0Uhci_SbPeiInit_TBL,  sizeof(D16F0Uhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        PROCESS_SB_R6432M_TABLE(D16F1Uhci_SbPeiInit_TBL,  sizeof(D16F1Uhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        PROCESS_SB_R6432M_TABLE(D16F7Ehci_SbPeiInit_TBL,  sizeof(D16F7Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

        PROCESS_SB_R64326408M_TABLE(D16F7Ehci_Driving_TBL, D16F7Ehci_Driving_TBL_Items);

        //
        // Process OC Pin Mux
        //
        if (SbCfg->UsbOCCtrl == USB_OC_ENABLE) {
            AsiaPciModify32((CHX002_D16F7EHCI | D16F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D16F7_PORTA_OC_MUX | D16F7_PORTB_OC_MUX | D16F7_PORTC_OC_MUX | D16F7_PORTD_OC_MUX,  0x321000);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC3#/USBHOC2#/USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11 | BIT10 | BIT9 | BIT8 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        } else {
            AsiaPciModify32((CHX002_D16F7EHCI | D16F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D16F7_PORTA_OC_MUX | D16F7_PORTB_OC_MUX | D16F7_PORTC_OC_MUX | D16F7_PORTD_OC_MUX,  0xBBBB00);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= BIT27;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC3#/USBHOC2#/USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11 | BIT10 | BIT9 | BIT8 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0);
            TempData32  |= BIT16 |  BIT11 | BIT4 | BIT0;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        }

        //
        // Process USBC FLR Control
        //
        if (SbCfg->USBCFLRCtrl == USBC_FLR_ENABLE) {
            AsiaPciModify8((CHX002_D16F0UHCI | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   D16F0F1_FLR_OPTIONAL);
            AsiaPciModify8((CHX002_D16F1UHCI | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   D16F0F1_FLR_OPTIONAL);
            AsiaPciModify8((CHX002_D16F7EHCI | D16F7_FLR_AND_VID_OPTIONAL_REG),     D16F7_FLR_OPTIONAL,     D16F7_FLR_OPTIONAL);
        } else {
            AsiaPciModify8((CHX002_D16F0UHCI | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   0x00);
            AsiaPciModify8((CHX002_D16F1UHCI | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   0x00);
            AsiaPciModify8((CHX002_D16F7EHCI | D16F7_FLR_AND_VID_OPTIONAL_REG),     D16F7_FLR_OPTIONAL,     0x00);
        }
    } else {

    }

    if (mXHCI18_EN) {
        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
        // AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, BIT14);
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[USB-PEI]: D0F0::PCICFG::EPHY Control[U3EPHY_CFGDONE] = %x\n", AsiaPciRead16(CHX002_GFXAX|D0F0_EPHY_CTL_Z1) & BIT14 ));

        PROCESS_SB_R6432M_TABLE(D18F0Xhci_SbPeiInit_TBL, sizeof(D18F0Xhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),    D18F0_CPU_OPTCFG,  D18F0_CPU_OPTCFG);  // Enable Access
        PROCESS_SB_R64326408M_TABLE(D18F0Xhci_Driving_TBL, D18F0Xhci_Driving_TBL_Items);

        //
        // Process MCU DMA Path selection
        //
        if ( SbCfg->XhcMcuDmaPathCtrl == XHC_MCUDMAPATH_SNOOP ) {
            AsiaPciModify8( (CHX002_APIC | D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_SM_1),  D0F5_REBMCBLOCK,    D0F5_REBMCBLOCK);     // Block XHCIMCU DMA Cycles

            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXC0);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_MCUDMASEL,       OPTCFGXHCI_MCUDMASEL);
        } else {
            AsiaPciModify8( (CHX002_APIC | D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_SM_1),  D0F5_REBMCBLOCK,    0x00);        // Do not block XHCIMCU DMA Cycles

            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXC0);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_MCUDMASEL,       0x00);
        }

        //
        // Process XhcTRBCacheBypassCtrl
        //
        if (SbCfg->XhcTRBCacheBypassCtrl == XHC_TRB_CACHE_BYPASS) {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX20);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),    OPTCFGXHCI_TRBCACHE_BYPASS,     OPTCFGXHCI_TRBCACHE_BYPASS);
        } else {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX20);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),    OPTCFGXHCI_TRBCACHE_BYPASS,     0x00);
        }

        //
        // Process XhcBurstCtrl
        //
        if (SbCfg->XhcBurstCtrl == XHC_OUTBURST_ENABLE) {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX60);
            AsiaPciModify8( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_INONEDP_EN | OPTCFGXHCI_OUTONEDP_EN,  0x00);
        } else {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX60);
            AsiaPciModify8( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_INONEDP_EN | OPTCFGXHCI_OUTONEDP_EN,  OPTCFGXHCI_INONEDP_EN | OPTCFGXHCI_OUTONEDP_EN);
        }

        //
        // Process xHCI UART GPIO EN
        //
        if (SbCfg->XhcUartCtrl == XHC_XHCIUART_ENABLE) {
            AsiaIoModify16 (PmioBar + PMIO_PAD_CTL_REG_Z1,      PMIO_P2G_GPIO37_2_1_0,      BIT1 | BIT0);   // PinMux for xHCI MCU UART - TX
            AsiaIoModify32 (PmioBar + PMIO_CR_GPIO_PAD_CTL,     PMIO_PAD_GPIO12_2_1_0,      BIT26 );        // PinMux for xHCI MCU UART - RX
        } else {
            AsiaIoModify16 (PmioBar + PMIO_PAD_CTL_REG_Z1,      PMIO_P2G_GPIO37_2_1_0,      0x0);           // PinMux for xHCI MCU UART - TX
            AsiaIoModify32 (PmioBar + PMIO_CR_GPIO_PAD_CTL,     PMIO_PAD_GPIO12_2_1_0,      0x0 );          // PinMux for xHCI MCU UART - RX
        }

        //
        // Process XhcFLRCtrl
        //
        if (SbCfg->XhcFLRCtrl == XHC_FLR_ENABLE) {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX6C);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 4),    OPTCFGXHCI_FLR_CAP_EN,      OPTCFGXHCI_FLR_CAP_EN);
        } else {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX6C);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 4),    OPTCFGXHCI_FLR_CAP_EN,      0x00);
        }

        //
        // Process onboard xHCI RTD3
        //
        if (SbCfg->XhcRTD3Ctrl== XHC_RTD3_ENABLE) {
           AsiaPciModify8((CHX002_SCRCH | D0F6_BIOS_SCRATCH_REG_8 + 1),     BIT7,   BIT7);
        } else {
           AsiaPciModify8((CHX002_SCRCH | D0F6_BIOS_SCRATCH_REG_8 + 1),     BIT7,   0x0);
        }

        //
        // Process  USB C4 Block
        //
        if (SbCfg->XhcC4BlockCtrl == XHC_C4BLOCK_ENABLE) {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX70);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_SS_EN | OPTCFGXHCI_HS_ISOINHC4_EN,  OPTCFGXHCI_SS_EN | OPTCFGXHCI_HS_ISOINHC4_EN);
        } else {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX70);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_SS_EN | OPTCFGXHCI_HS_ISOINHC4_EN,  0x00);
        }

        // BIOS inform FW that current chip revision
        AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXE0);
        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   (BIT1 | BIT2),              ((ASIA_SB_REVISION) & (BIT1 | BIT2)));

        //
        // Process OC Pin Mux
        //
        if (SbCfg->UsbOCCtrl == USB_OC_ENABLE) {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX134);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_OCSEL1 | OPTCFGXHCI_OCSEL2,  0x21);

            // Pad select for USBHOC5#/USBHOC4#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        } else {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX134);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_OCSEL1 | OPTCFGXHCI_OCSEL2,  0x00);

            // Pad select for USBHOC5#/USBHOC4#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11);
            TempData32  |= BIT16 | BIT11;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        }

        //
        // Process xHCI Performance Mode
        //
        if (SbCfg->XhcPerfModeCtrl == XHC_PERF_MODE_ENABLE) {
            // SbCfg->XhcU1U2Ctrl   = XHC_PORTU1U2_DISABLE;
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXE0);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   BIT0,               BIT0);
        } else {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXE0);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   BIT0,               0x00);
        }

        //
        // Process xHCI U1U2
        //
        if (SbCfg->XhcU1U2Ctrl == XHC_PORTU1U2_ENABLE) {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20100 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS);
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20200 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS);
        } else {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20100 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  0x00);
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20200 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  0x00);
        }

        //
        // Process xHCI MSI Flush P2CW
        //
        if (SbCfg->XhcMsiFlushCtrl == XHC_MSIFLUSH_ENABLE) {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX160);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),        OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN,   OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 1),    BIT0,                               BIT0);
        } else {
            AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX160);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),        OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN,   0x00);
            AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 1),    BIT0,                               0x00);
        }


        //
        // Process Usb Electrical Idle Triggered Retrain Enable/Disable
        //
        if (SbCfg->XhcEITRNCtrl == XHC_EITRN_DISABLE) {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20100 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  0);
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20200 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  0);
        } else {
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20100 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  U3IPSSCFGP_R_EIRTN_SS);
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20200 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  U3IPSSCFGP_R_EIRTN_SS);
        }

        //
        // Process xHCI Preftech (IOV)
        //
        if (SbCfg->IOVEnable) {
            // Disable xHCI prefetch under IOV Enable
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        OPTCFGXHCI_XHCIOPTION_RX150);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),       BIT0,                       BIT0);
        } else {
            // Enable xHCI prefetch under IOV Disnable
            AsiaPciWrite32( (CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        OPTCFGXHCI_XHCIOPTION_RX150);
            AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),       BIT0,                       0x00);
        }

        AsiaPciModify8((CHX002_XHCI | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),   D18F0_CPU_OPTCFG,                   0x00);  // Disable Access
    } else {
        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
        AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, 0);
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[USB-PEI]: D0F0::PCICFG::EPHY Control[U3EPHY_CFGDONE] = %x\n", AsiaPciRead16(CHX002_GFXAX|D0F0_EPHY_CTL_Z1) & BIT14 ));
    }
	   //
	   // Process patches here
	   //
	   if (SbCfg->UsbModeSelect == USB_MODE_SEL_MODEB) {
		   if(ASIA_SB_REVISION!=0){
		   	 //PEI_DEBUG((PeiServices, EFI_D_INFO, "[USB-PEI]:CHX002A2 USBC D14F7 High Speed Device patch for ASUS AC1300 WIFI issue\n" ));
			 // With USB mode 2, connect ASUS AC1300 USB WiFi device and run ACPI S4 burn-in would cause black screen and hang at post "40" in WIN10 x64
			 AsiaPciModify8((CHX002_D14F7EHCI | D14F7_PORT_CTL_REG_2), D14F7_DISPD_EPHY, D14F7_DISPD_EPHY);
			 }
		   else
			   {
			  //[ALJ20180616]CHX002A0 USBC D14F7 High Speed Device Fail,remove for now
			  PEI_DEBUG((PeiServices, EFI_D_INFO, "[USB-PEI]:CHX002A0 USBC D14F7 High Speed Device Fail,remove for A0 chip \n" ));
			   }
	   }

    return EFI_SUCCESS;
}

#ifdef ZX_DUALSOCKET
EFI_STATUS
EFIAPI
UsbPeiInitSlave (
    IN  EFI_PEI_SERVICES        **PeiServices,
        ASIA_SB_CONFIGURATION   *SbCfg
    )
{
    UINT8 mXHCI18_EN = 0;
    UINT8 mUSBC14_EN = 0;
    UINT8 mUSBC16_EN = 0;

    UINT32 D17F0MMIOBar;
    UINT16 PmioBar;

    UINT32 TempData32   = 0;

    D17F0MMIOBar    = AsiaPciRead32(CHX002_BUSC_SLAVE | D17F0_MMIO_SPACE_BASE_ADR) << 8;
    PmioBar         = AsiaPciRead16(CHX002_BUSC_SLAVE | D17F0_PMU_PM_IO_BASE);
    PmioBar         &= D17F0_PMU_PMIOBA;

    // ALJ20180305,add scratch register for DRT tool use only. Remove when for release version
    AsiaPciModify8((CHX002_SCRCH_SLAVE | D0F6_BIOS_SCRATCH_REG_7 + 1),   BIT3|BIT2|BIT1|BIT0,    SbCfg->UsbModeSelectSlave);

    //
    // Process Function Enable/Disable
    //
    switch (SbCfg->UsbModeSelectSlave) {
        case USB_MODE_SEL_DISABLE:
            // disable xHCI
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN,                               0x0);
            // disable uHCI
            AsiaPciModify8(   (CHX002_BUSC_SLAVE | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, 0x0);
            // disable eHCI
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      0x0);
            break;

        case USB_MODE_SEL_MODEA:
            // disable xHCI & USBC own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              0x0);
            // enable uHCI D14&D16
            AsiaPciModify8(   (CHX002_BUSC_SLAVE | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3);
            // enable eHCI D14&D16
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2);
            mUSBC14_EN  = 1;
            mUSBC16_EN  = 1;
            break;

        case USB_MODE_SEL_MODEB:
            // enable xHCI & USBC own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              PMIO_XHCI_EN);
            // enable uHCI D14&D16
            AsiaPciModify8(   (CHX002_BUSC_SLAVE | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3);
            // enable eHCI D14&D16
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2);
            mXHCI18_EN  = 1;
            mUSBC14_EN  = 1;
            mUSBC16_EN  = 1;
            break;

        case USB_MODE_SEL_MODEC:
            // enable xHCI & xHCI own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              PMIO_XHCI_EN | PMIO_U2SEL_SUS);
            // disable uHCI
            AsiaPciModify8(   (CHX002_BUSC_SLAVE | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, 0x00);
            // disable eHCI
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      0x00);
            mXHCI18_EN  = 1;
            break;

        case USB_MODE_SEL_MODED:
            // enable xHCI & xHCI own U2EPHY
            AsiaIoModify8(    (PmioBar + PMIO_SUSPEND_PWR_DOMAIN_Z1),     PMIO_XHCI_EN | PMIO_U2SEL_SUS,              PMIO_XHCI_EN | PMIO_U2SEL_SUS);
            // enable uHCI D16
            AsiaPciModify8(   (CHX002_BUSC_SLAVE | D17F0_FUN_CTL_1),            D17F0_ENUSB1 | D17F0_ENUSB2 | D17F0_ENUSB3, D17F0_ENUSB1 | D17F0_ENUSB2);
            // enable eHCI D16
            AsiaMemoryModify8((D17F0MMIOBar + D17F0MMIO_DEV_FUN_ENABLE),  D17F0MMIO_ENEHCI1 | D17F0MMIO_ENEHCI2,      D17F0MMIO_ENEHCI1);
            mXHCI18_EN  = 1;
            mUSBC16_EN  = 1;
            break;
    }

    if (mUSBC14_EN || mUSBC16_EN || mXHCI18_EN) {
        AsiaIoModify8( (PmioBar + PMIO_USB_AND_XHCI_WAKEUP_TRIGGER_MODE_CTL_REG),  PMIO_WUSB_TRGM,     PMIO_WUSB_TRGM);    // USB and XHCI Wakeup Status trigger mode control
        AsiaPciModify8((CHX002_BUSC_SLAVE + D17F0_PMU_MISC_CFG_2_PWR_WELL),              D17F0_PMU_ENUSBUP,  D17F0_PMU_ENUSBUP); // USB Wakeup for POS / STR / STD / Soft Off

        //
        // Process onboard Usb S4 wakeup
        //
        if (SbCfg->UsbS4WakeupCtrl == USB_S4WAKEUP_ENABLE) {
            AsiaPciModify8((CHX002_SCRCH_SLAVE | D0F6_BIOS_SCRATCH_REG_8 + 1),    BIT6,   BIT6);
        } else {
            AsiaPciModify8((CHX002_SCRCH_SLAVE | D0F6_BIOS_SCRATCH_REG_8 + 1),    BIT6,   0x0);
        }
    }

    if (mUSBC14_EN) {
        PROCESS_SB_R6432M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D14F0Uhci_SbPeiInit_TBL,  sizeof(D14F0Uhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        PROCESS_SB_R6432M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D14F7Ehci_SbPeiInit_TBL,  sizeof(D14F7Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

        PROCESS_SB_R64326408M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D14F7Ehci_Driving_TBL, D14F7Ehci_Driving_TBL_Items);

        //
        // Process OC Pin Mux
        //
        if (SbCfg->UsbOCCtrl == USB_OC_ENABLE) {
            AsiaPciModify32((CHX002_D14F7EHCI_SLAVE | D14F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D14F7_PORTA_OC_MUX | D14F7_PORTB_OC_MUX,    0x1000);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT2 | BIT1 | BIT0);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        } else {
            AsiaPciModify32((CHX002_D14F7EHCI_SLAVE | D14F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D14F7_PORTA_OC_MUX | D14F7_PORTB_OC_MUX,    0xBB00);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= BIT27;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT2 | BIT1 | BIT0);
            TempData32  |= BIT0;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        }

        //
        // Process USBC FLR Control
        //
        if (SbCfg->USBCFLRCtrl == USBC_FLR_ENABLE) {
            AsiaPciModify8((CHX002_D14F0UHCI_SLAVE | D14F0_FLR_AND_VID_OPTIONAL_REG),     D14F0_FLR_OPTIONAL,     D14F0_FLR_OPTIONAL);
            AsiaPciModify8((CHX002_D14F7EHCI_SLAVE | D14F7_FLR_AND_VID_OPTIONAL_REG),     D14F7_FLR_OPTIONAL,     D14F7_FLR_OPTIONAL);
        } else {
            AsiaPciModify8((CHX002_D14F0UHCI_SLAVE | D14F0_FLR_AND_VID_OPTIONAL_REG),     D14F0_FLR_OPTIONAL,     0x00);
            AsiaPciModify8((CHX002_D14F7EHCI_SLAVE | D14F7_FLR_AND_VID_OPTIONAL_REG),     D14F7_FLR_OPTIONAL,     0x00);
        }
    } else {

    }

    if (mUSBC16_EN) {
        PROCESS_SB_R6432M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D16F0Uhci_SbPeiInit_TBL,  sizeof(D16F0Uhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        PROCESS_SB_R6432M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D16F1Uhci_SbPeiInit_TBL,  sizeof(D16F1Uhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        PROCESS_SB_R6432M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D16F7Ehci_SbPeiInit_TBL,  sizeof(D16F7Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

        PROCESS_SB_R64326408M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D16F7Ehci_Driving_TBL, D16F7Ehci_Driving_TBL_Items);

        //
        // Process OC Pin Mux
        //
        if (SbCfg->UsbOCCtrl == USB_OC_ENABLE) {
            AsiaPciModify32((CHX002_D16F7EHCI_SLAVE | D16F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D16F7_PORTA_OC_MUX | D16F7_PORTB_OC_MUX | D16F7_PORTC_OC_MUX | D16F7_PORTD_OC_MUX,  0x321000);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC3#/USBHOC2#/USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11 | BIT10 | BIT9 | BIT8 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        } else {
            AsiaPciModify32((CHX002_D16F7EHCI_SLAVE | D16F7_PORT_OC_PIN_MUX_SEL_AND_CCS_GATING_REGS), D16F7_PORTA_OC_MUX | D16F7_PORTB_OC_MUX | D16F7_PORTC_OC_MUX | D16F7_PORTD_OC_MUX,  0xBBBB00);

            // Pad select for USBHOC0#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x40000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT29 | BIT28 | BIT27);
            TempData32  |= BIT27;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
            // Pad select for USBHOC3#/USBHOC2#/USBHOC1#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11 | BIT10 | BIT9 | BIT8 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0);
            TempData32  |= BIT16 |  BIT11 | BIT4 | BIT0;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        }

        //
        // Process USBC FLR Control
        //
        if (SbCfg->USBCFLRCtrl == USBC_FLR_ENABLE) {
            AsiaPciModify8((CHX002_D16F0UHCI_SLAVE | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   D16F0F1_FLR_OPTIONAL);
            AsiaPciModify8((CHX002_D16F1UHCI_SLAVE | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   D16F0F1_FLR_OPTIONAL);
            AsiaPciModify8((CHX002_D16F7EHCI_SLAVE | D16F7_FLR_AND_VID_OPTIONAL_REG),     D16F7_FLR_OPTIONAL,     D16F7_FLR_OPTIONAL);
        } else {
            AsiaPciModify8((CHX002_D16F0UHCI_SLAVE | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   0x00);
            AsiaPciModify8((CHX002_D16F1UHCI_SLAVE | D16F0F1_FLR_AND_VID_OPTIONAL_REG),   D16F0F1_FLR_OPTIONAL,   0x00);
            AsiaPciModify8((CHX002_D16F7EHCI_SLAVE | D16F7_FLR_AND_VID_OPTIONAL_REG),     D16F7_FLR_OPTIONAL,     0x00);
        }
    } else {

    }

    if (mXHCI18_EN) {
        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
        AsiaPciModify16((CHX002_GFXAX_SLAVE|D0F0_EPHY_CTL_Z1), BIT14, BIT14);
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[USB-PEI]: Slave D0F0::PCICFG::EPHY Control[U3EPHY_CFGDONE] = %x\n", AsiaPciRead16(CHX002_GFXAX_SLAVE|D0F0_EPHY_CTL_Z1) & BIT14 ));

        PROCESS_SB_R6432M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D18F0Xhci_SbPeiInit_TBL, sizeof(D18F0Xhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

        AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),    D18F0_CPU_OPTCFG,  D18F0_CPU_OPTCFG);  // Enable Access
        PROCESS_SB_R64326408M_TABLE_SLAVE(SLAVE_SK_BUS_NUM, D18F0Xhci_Driving_TBL, D18F0Xhci_Driving_TBL_Items);

        //
        // Process MCU DMA Path selection
        //
        if ( SbCfg->XhcMcuDmaPathCtrlSlave == XHC_MCUDMAPATH_SNOOP ) {
            AsiaPciModify8( (CHX002_APIC_SLAVE | D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_SM_1),  D0F5_REBMCBLOCK,    D0F5_REBMCBLOCK);     // Block XHCIMCU DMA Cycles

            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXC0);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_MCUDMASEL,       OPTCFGXHCI_MCUDMASEL);
        } else {
            AsiaPciModify8( (CHX002_APIC_SLAVE | D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_SM_1),  D0F5_REBMCBLOCK,    0x00);        // Do not block XHCIMCU DMA Cycles

            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXC0);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_MCUDMASEL,       0x00);
        }

        //
        // Process XhcTRBCacheBypassCtrl
        //
        if (SbCfg->XhcTRBCacheBypassCtrl == XHC_TRB_CACHE_BYPASS) {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX20);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),    OPTCFGXHCI_TRBCACHE_BYPASS,     OPTCFGXHCI_TRBCACHE_BYPASS);
        } else {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX20);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),    OPTCFGXHCI_TRBCACHE_BYPASS,     0x00);
        }

        //
        // Process XhcBurstCtrl
        //
        if (SbCfg->XhcBurstCtrl == XHC_OUTBURST_ENABLE) {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX60);
            AsiaPciModify8( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_INONEDP_EN | OPTCFGXHCI_OUTONEDP_EN,  0x00);
        } else {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),     OPTCFGXHCI_XHCIOPTION_RX60);
            AsiaPciModify8( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_INONEDP_EN | OPTCFGXHCI_OUTONEDP_EN,  OPTCFGXHCI_INONEDP_EN | OPTCFGXHCI_OUTONEDP_EN);
        }

        //
        // Process xHCI UART GPIO EN
        //
        if (SbCfg->XhcUartCtrl == XHC_XHCIUART_ENABLE) {
            AsiaIoModify16 (PmioBar + PMIO_PAD_CTL_REG_Z1,      PMIO_P2G_GPIO37_2_1_0,      BIT1 | BIT0);   // PinMux for xHCI MCU UART - TX
            AsiaIoModify32 (PmioBar + PMIO_CR_GPIO_PAD_CTL,     PMIO_PAD_GPIO12_2_1_0,      BIT26 );        // PinMux for xHCI MCU UART - RX
        } else {
            AsiaIoModify16 (PmioBar + PMIO_PAD_CTL_REG_Z1,      PMIO_P2G_GPIO37_2_1_0,      0x0);           // PinMux for xHCI MCU UART - TX
            AsiaIoModify32 (PmioBar + PMIO_CR_GPIO_PAD_CTL,     PMIO_PAD_GPIO12_2_1_0,      0x0 );          // PinMux for xHCI MCU UART - RX
        }

        //
        // Process XhcFLRCtrl
        //
        if (SbCfg->XhcFLRCtrl == XHC_FLR_ENABLE) {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX6C);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 4),    OPTCFGXHCI_FLR_CAP_EN,      OPTCFGXHCI_FLR_CAP_EN);
        } else {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX6C);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 4),    OPTCFGXHCI_FLR_CAP_EN,      0x00);
        }

        //
        // Process onboard xHCI RTD3
        //
        if (SbCfg->XhcRTD3Ctrl== XHC_RTD3_ENABLE) {
           AsiaPciModify8((CHX002_SCRCH_SLAVE | D0F6_BIOS_SCRATCH_REG_8 + 1),     BIT7,   BIT7);
        } else {
           AsiaPciModify8((CHX002_SCRCH_SLAVE | D0F6_BIOS_SCRATCH_REG_8 + 1),     BIT7,   0x0);
        }

        //
        // Process  USB C4 Block
        //
        if (SbCfg->XhcC4BlockCtrl == XHC_C4BLOCK_ENABLE) {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX70);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_SS_EN | OPTCFGXHCI_HS_ISOINHC4_EN,  OPTCFGXHCI_SS_EN | OPTCFGXHCI_HS_ISOINHC4_EN);
        } else {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX70);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_SS_EN | OPTCFGXHCI_HS_ISOINHC4_EN,  0x00);
        }

        // BIOS inform FW that current chip revision
        AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXE0);
        AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   (BIT1 | BIT2),              ((ASIA_SB_REVISION) & (BIT1 | BIT2)));

        //
        // Process OC Pin Mux
        //
        if (SbCfg->UsbOCCtrl == USB_OC_ENABLE) {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX134);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_OCSEL1 | OPTCFGXHCI_OCSEL2,  0x21);

            // Pad select for USBHOC5#/USBHOC4#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11);
            TempData32  |= 0x00;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        } else {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RX134);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   OPTCFGXHCI_OCSEL1 | OPTCFGXHCI_OCSEL2,  0x00);

            // Pad select for USBHOC5#/USBHOC4#
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    0x00);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_ADDR,                  0x80000);
            TempData32  = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA);
            TempData32  &= ~(BIT18 | BIT17 | BIT16 | BIT13 | BIT12 | BIT11);
            TempData32  |= BIT16 | BIT11;
            AsiaIoWrite32( (PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA), TempData32);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR,                    PMIO_PAD_WR);
            AsiaIoModify32((PmioBar + PMIO_PAD_CTL_REG),            PMIO_PAD_WR | PMIO_PAD_ADDR,    0x00);
        }

        //
        // Process xHCI Performance Mode
        //
        if (SbCfg->XhcPerfModeCtrl == XHC_PERF_MODE_ENABLE) {
            // SbCfg->XhcU1U2Ctrl   = XHC_PORTU1U2_DISABLE;
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXE0);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   BIT0,               BIT0);
        } else {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    OPTCFGXHCI_XHCIOPTION_RXE0);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   BIT0,               0x00);
        }

        //
        // Process xHCI U1U2
        //
        if (SbCfg->XhcU1U2Ctrl == XHC_PORTU1U2_ENABLE) {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20100 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS);
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20200 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS);
        } else {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20100 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  0x00);
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),    0x20200 + U3IPSSCFGP_SSIP_PORT_PMULINK_OPTION_REGS);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),   U3IPSSCFGP_R_U1LKPMEN_SS | U3IPSSCFGP_R_U2LKPMEN_SS,  0x00);
        }

        //
        // Process xHCI MSI Flush P2CW
        //
        if (SbCfg->XhcMsiFlushCtrl == XHC_MSIFLUSH_ENABLE) {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX160);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),        OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN,   OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 1),    BIT0,                               BIT0);
        } else {
            AsiaPciWrite32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),         OPTCFGXHCI_XHCIOPTION_RX160);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),        OPTCFGXHCI_R_DMAWMUX_FLUSHEND_EN,   0x00);
            AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 1),    BIT0,                               0x00);
        }


        //
        // Process Usb Electrical Idle Triggered Retrain Enable/Disable
        //
        if (SbCfg->XhcEITRNCtrl == XHC_EITRN_DISABLE) {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20100 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  0);
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20200 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  0);
        } else {
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20100 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  U3IPSSCFGP_R_EIRTN_SS);
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        0x20200 + U3IPSSCFGP_SSIP_PORT_LINK_OPTION_REGS_1 - 2);
            AsiaPciModify16((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA + 2),   U3IPSSCFGP_R_EIRTN_SS,  U3IPSSCFGP_R_EIRTN_SS);
        }

        //
        // Process xHCI Preftech (IOV)
        //
        if (SbCfg->IOVEnable) {
            // Disable xHCI prefetch under IOV Enable
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        OPTCFGXHCI_XHCIOPTION_RX150);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),       BIT0,                       BIT0);
        } else {
            // Enable xHCI prefetch under IOV Disnable
            AsiaPciWrite32( (CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),        OPTCFGXHCI_XHCIOPTION_RX150);
            AsiaPciModify32((CHX002_XHCI_SLAVE | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),       BIT0,                       0x00);
        }

        AsiaPciModify8((CHX002_XHCI_SLAVE | D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43),   D18F0_CPU_OPTCFG,                   0x00);  // Disable Access
    } else {

    }
	//[ALJ20180616]CHX002A0 USBC D14F7 High Speed Device Fail,remove for now
#if 0
    //
    // Process patches here
    //
    if (SbCfg->UsbModeSelectSlave == USB_MODE_SEL_MODEB) {
        // With USB mode 2, connect ASUS AC1300 USB WiFi device and run ACPI S4 burn-in would cause black screen and hang at post "40" in WIN10 x64
        AsiaPciModify8((CHX002_D14F7EHCI_SLAVE | D14F7_PORT_CTL_REG_2), D14F7_DISPD_EPHY, D14F7_DISPD_EPHY);
    }
#endif
    return EFI_SUCCESS;
}
#endif


EFI_STATUS
EFIAPI
UsbInitPei (
    IN  EFI_PEI_SERVICES        **PeiServices,
        ASIA_SB_CONFIGURATION   *SbCfg
    )
{
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[USB-PEI]: USB PEI Init Start...\n"));
    UsbPeiInit(PeiServices, SbCfg);

#ifdef ZX_DUALSOCKET
    if(SbCfg->ZxeDualSocket == 1) {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[USB-PEI]: Slave USB PEI Init Start...\n"));
        UsbPeiInitSlave(PeiServices, SbCfg);
    }
#endif

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[USB-PEI]: USB PEI Init End\n"));
    return EFI_SUCCESS;
}
