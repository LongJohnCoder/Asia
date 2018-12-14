/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoeUsb.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/


//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#include "Pei.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaCommon.h"
#include "AsiaIoLib.h"

#include EFI_PPI_DEFINITION(AsiaSbPpi)
#include "AsiaSbPeim.h"
#include "SbLibPpi.h"
#include "IoeSbDriving.h"

//#include "SIPcieDriving.h"
#include "IoeUsb.h"
#include "IoeConfig.h"



ASIA_IO_TABLE_6432_REV IOEXhci_SbPeiInit_TBL[]= {
	{0x00,	0xFF,	(CND003_XHCI|0x44),	0x1100,	0x1100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTION_BITS_RX43_XHCOPTRX43-3),	0x01000000,	0x01000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x64},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x3fff,	0x3a98},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0xd4},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x80,	0x80},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0xf0},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xffffffff,	0xffffada4},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x108},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x40000,	0x40000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x39f0000,	0x39f0000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x138},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x1000000,	0x1000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10104},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8100,	0x100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10204},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8100,	0x100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10304},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8100,	0x100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10328},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xff0000,	0xff0000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10404},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8100,	0x100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10504},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8100,	0x100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),	0xFFFFF,	0x10614},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xc00,	0x0},
	
	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2010C},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000010,	0x000010},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2020C},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000010,	0x000010},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2030C},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000010,	0x000010},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2040C},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000010,	0x000010},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2050C},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000010,	0x000010},
	
	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20154},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000100,	0x000100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20254},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000100,	0x000100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20354},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000100,	0x000100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20454},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000100,	0x000100},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20554},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x000100,	0x000100},
	
	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2044c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x0000002,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2054c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x0000002,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2015c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xa000000,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2025c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xa000000,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2035c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xa000000,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2045c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xa000000,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x2055c},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0xa000000,	0xa000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20168},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8000000,	0x8000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20268},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8000000,	0x8000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20368},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8000000,	0x8000000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20468},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8080000,	0x8080000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x20568},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x8080000,	0x8080000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x70000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x0070000,	0x0040000},
	
	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),		0xFFFFF,	0x70008},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTIONAL_BITS_CFG_DATA),	0x0070000,	0x0040000},

	{0x00,	0xFF,	(CND003_XHCI|CND003_D18F0_XHCI_OPTION_BITS_RX43_XHCOPTRX43-3),	0x01000000,	0x00000000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}

};
STATIC ASIA_IO_TABLE_6432_REV IOED14Uhci0_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D14UHC0|0x48),	0x8020000,	0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED14Uhci1_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D14UHC1|0x48),	0x8020000,	0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED14Uhci2_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D14UHC2|0x48),	0x8020000,	0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED16Uhci0_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D16UHC0|0x48),	0x8020000,	0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED16Uhci1_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D16UHC1|0x48),	0x8020000,	0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED16Uhci2_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D16UHC2|0x48),	0x8020000,	0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED14Ehci_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D14EHCI|0x50),	0xC0440000,	0xC0040000},
    {0x00,	0xFF,	(CND003_D14EHCI|0x54),	0x1B,	0x1B},
	{0x00,	0xFF,	(CND003_D14EHCI|0x58),	0x8000,	0x8000},
	{0x00,  0xFF,   (CND003_D14EHCI|0x64),  0x3000,   0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOED16Ehci_SbPeiInit_TBL[]={
	{0x00,	0xFF,	(CND003_D16EHCI|0x50),	0xC0440000,	0xC0040000},
    {0x00,  0xFF,   (CND003_D16EHCI|0x54),  0x1B,   0x1B},
	{0x00,  0xFF,   (CND003_D16EHCI|0x58),  0x8000,   0x8000},
	{0x00,  0xFF,   (CND003_D16EHCI|0x64),  0x3000,   0x0},
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

/**
   IOE Type-A Patch function
   
  @param  VOID
  
  @return VOID.

**/

////TypeC Usage Model 
VOID IOETypeAPatch(){
    AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
    switch (IoeXhciSspPortCfg.FwVersion) {
    case 0:// Port1(D) &Port2(E) both TypeA
        //Port1(D)& Port2(E) CCPHY GPIO 8 & 9 =0b: U3TYPEC_CFG Rx1B[1:0]=00b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x03000000, 0x00000000);
        //Port1(D)& Port2(E)VBUS enable:U3TYPEC_CFG Rx1B[7:6]=11b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0xC0000000, 0xC0000000);
        //Port1(D): Side A U3IP_SSP RxB7[9](0b) + Enable Type A Selection U3IP_SSP RxB7[8] (1b)
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x204B4);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x03000000, 0x01000000);
        //Port2(E) : Side A U3IP_SSP RxB7[9](0b) + Enable Type A Selection U3IP_SSP RxB7[8] (1b)
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x205B4);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x03000000, 0x01000000);
        break;
    case 2: //Port2(E)  is TypeA
        //CCPHY GPIO 9 =0b: U3TYPEC_CFG Rx1B[1]=0b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x02000000, 0x00000000);
        //VBUS enable:U3TYPEC_CFG Rx1B[7]=1b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x80000000, 0x80000000);
        //Side A U3IP_SSP RxB7[9](0b) + Enable Type A Selection U3IP_SSP RxB7[8] (1b)
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x205B4);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x03000000, 0x01000000);
        break;
    case 3: //Port1(D) is TypeA
        //CCPHY GPIO 8 =0b: U3TYPEC_CFG Rx1B[0]=0b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x01000000, 0x00000000);
        //VBUS enable :U3TYPEC_CFG Rx1B[6]=1b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x40000000, 0x40000000);
        //Side A U3IP_SSP RxB7[9](0b) + Enable Type A Selection U3IP_SSP RxB7[8] (1b)
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x204B4);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x03000000, 0x01000000);
        break;     
    case 5: //Port2(E)  is TypeA （EK3)
        //VBUS enable:U3TYPEC_CFG Rx1B[7]=1b
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x80000000, 0x80000000);
        //Side A U3IP_SSP RxB7[9](0b) + Enable Type A Selection U3IP_SSP RxB7[8] (1b)
        AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x205B4);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x03000000, 0x01000000);
        break;

    default:
        break;
    }
  
    AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x00); // Disable Access
}

/**
  IOE Type-C Patch function
  
  @param  VOID

  @return VOID.

**/

VOID IOETypeCPatch() {

    ////TypeC Usage Model
	if ( (IoeXhciSspPortCfg.ssp_port1 == 1) || (IoeXhciSspPortCfg.ssp_port2 == 1)) { //Type-C port exists
		AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
		
		AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x00000100, 0x00000000);
		
		AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70000);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x00000001, 0x00000001);
		
		AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70018);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0x00001800, 0x00000000);
		
		AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x7001C);
		AsiaPciModify32((CND003_XHCI | 0x7C), 0xFFFF0000, 0x000F0000);
		//TypeC Usage Model
		if ( (IoeXhciSspPortCfg.ssp_port1 == 1) && (IoeXhciSspPortCfg.ssp_port2 == 0)) {  //;Port 1(D) is Type-C
			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x204B0);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00000800, 0x00000000);

			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70000);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00480000, 0x00000000);
			}
        //TypeC Usage Model
		else if ( (IoeXhciSspPortCfg.ssp_port1 == 0) && (IoeXhciSspPortCfg.ssp_port2 == 1)) {  //;Port 2(E) is Type-C
			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x205B0);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00000800, 0x00000000);

			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70008);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00480000, 0x00000000);
			}
		else {  //;Both are Type-C
			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x204B0);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00000800, 0x00000000);

			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x205B0);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00000800, 0x00000000);

			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70000);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00480000, 0x00000000);

			AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70008);
			AsiaPciModify32((CND003_XHCI | 0x7C), 0x00480000, 0x00000000);
			}
		AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
		}
}

/**
  IOE USB PEI Init function
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

EFI_STATUS
EFIAPI
IOEUsbPeiInit(IN EFI_PEI_SERVICES **PeiServices,ASIA_SB_CONFIGURATION* SbCfg ) {

    UINT32 Membaseaddress;

    if(!IoeExist()){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [IOEUsbPeiInit()]\n"));
        return EFI_SUCCESS;
    }

    IoePeiTempAssignment(PeiServices);

	// Get Internal Chip Revision ID  - Chris J. Wang 20170117
	SbCfg->IoeChipRevision = AsiaPciRead8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN, CND003_BUSX_D0F0_INTERNAL_REV_ID));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IOE Internal Revision ID = 0x%02x(SB)\n",SbCfg->IoeChipRevision));


  	//
  	// Configure D18F0  XHCI SSP port1/2
  	//
  	AsiaPciModify8(CND003_XHCI|0x5B, 0x3F, IoeXhciSspPortCfg.FwVersion); //TypeC Usage Model
  	AsiaPciModify8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_2+3, BIT2|BIT1, ((IoeXhciSspPortCfg.ssp_port2 == 1)?BIT2:0) | ((IoeXhciSspPortCfg.ssp_port1 == 1)?BIT1:0));

	
    //Process IOEUSB policy
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[TTPAN_IOE] Usb Mode=%x\n",SbCfg->IOEUsbModeSelect));

	//2. Usb Mode Selection
	switch (SbCfg->IOEUsbModeSelect)
	{
	
	  case IOEUSB_MODE_SEL_DISABLE: 
		  AsiaPciModify8((CND003_EPTRFC | 0x45), 0x80, 0);//disable xhci
		  AsiaPciModify8((CND003_EPTRFC | 0x45), BIT3|BIT4|BIT5|BIT6, 0);//disable Ehci
		  AsiaPciModify8((CND003_EPTRFC | 0x46), BIT4|BIT5|BIT6|BIT7, 0);//disable Ehci
		  break;
	  case IOEUSB_MODE_SEL_MODEA:
		  AsiaPciModify8((CND003_EPTRFC | 0x45), 0x80, 0);//disable xhci
		  AsiaPciModify8((CND003_EPTRFC | 0x45), BIT3|BIT4|BIT5|BIT6, 0x78);//enable Ehci
		  AsiaPciModify8((CND003_EPTRFC | 0x46), BIT4|BIT5|BIT6|BIT7, 0xf0);//enable Ehci
		  Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
		  AsiaMemoryModify8(Membaseaddress+0x1194,BIT0,0x0);


		  // Process Uhci and EHCI Safe table
		  //PROCESS_SB_R6432M_TABLE(IOED14Uhci0_SbPeiInit_TBL, sizeof(IOED14Uhci0_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
		  //PROCESS_SB_R6432M_TABLE(IOED14Uhci1_SbPeiInit_TBL, sizeof(IOED14Uhci1_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  //PROCESS_SB_R6432M_TABLE(IOED14Uhci2_SbPeiInit_TBL, sizeof(IOED14Uhci2_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  IOE_PROCESS_SB_R6432M_TABLE(IOED14Ehci_SbPeiInit_TBL, sizeof(IOED14Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
		  
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci0_SbPeiInit_TBL, sizeof(IOED16Uhci0_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci1_SbPeiInit_TBL, sizeof(IOED16Uhci1_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci2_SbPeiInit_TBL, sizeof(IOED16Uhci2_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  IOE_PROCESS_SB_R6432M_TABLE(IOED16Ehci_SbPeiInit_TBL, sizeof(IOED16Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  // Process EHCI Driving Table
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED16Ehci_Driving_TBL, IOED16Ehci_Driving_TBL_Items);
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED14Ehci_Driving_TBL, IOED14Ehci_Driving_TBL_Items);

          if (SbCfg->IOEUSBCFLRControl == IOEUSBC_FLR_ENABLE) {
              AsiaPciModify8((CND003_D14UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D14UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D14UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D14EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);

          } else {

              AsiaPciModify8((CND003_D14UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D14UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D14UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D14EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);

         }

         if (SbCfg->IOEUsbOCEn == IOEUSBOC_ENABLE) { //Enable
                 //EHCI D16F7 Mapping
                 AsiaPciModify32((CND003_D16EHCI|0xA0), 0xFFFFFF00,   0x54321000);
                 //EHCI D14F7 Mapping
                 AsiaPciModify32((CND003_D14EHCI|0xA0), 0xFFFFFF00,   0x54321000);
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x03FF0000);
          } 
         else

         	{

           //EHCI D16F7 Mapping
                 AsiaPciModify32((CND003_D16EHCI|0xA0), 0xFFFFFF00,   0xBBBBBB00);
                 //EHCI D14F7 Mapping
                 AsiaPciModify32((CND003_D14EHCI|0xA0), 0xFFFFFF00,   0xBBBBBB00);
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x0);
		 }
		  break;
	  case IOEUSB_MODE_SEL_MODEB://Mode2
	  	  AsiaPciModify8((CND003_EPTRFC | 0x45), 0x80, 0x80);//enable xhci
		  AsiaPciModify8((CND003_EPTRFC | 0x45), BIT3|BIT4|BIT5|BIT6, 0x78);//enable Ehci D14
		  AsiaPciModify8((CND003_EPTRFC | 0x46), BIT4|BIT5|BIT6|BIT7, 0xf0);//enable Ehci D16
		  Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
		  AsiaMemoryModify8(Membaseaddress+0x1194,BIT0,0x0);
		  // Process Uhci and EHCI Safe table
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED14Uhci0_SbPeiInit_TBL, sizeof(IOED14Uhci0_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED14Uhci1_SbPeiInit_TBL, sizeof(IOED14Uhci1_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED14Uhci2_SbPeiInit_TBL, sizeof(IOED14Uhci2_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
		  IOE_PROCESS_SB_R6432M_TABLE(IOED14Ehci_SbPeiInit_TBL, sizeof(IOED14Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci0_SbPeiInit_TBL, sizeof(IOED16Uhci0_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci1_SbPeiInit_TBL, sizeof(IOED16Uhci1_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci2_SbPeiInit_TBL, sizeof(IOED16Uhci2_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
		  IOE_PROCESS_SB_R6432M_TABLE(IOED16Ehci_SbPeiInit_TBL, sizeof(IOED16Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));

		  
		  // Process EHCI Driving Table
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED16Ehci_Driving_TBL, IOED16Ehci_Driving_TBL_Items);
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED14Ehci_Driving_TBL, IOED14Ehci_Driving_TBL_Items);
		  // Process Xhci Safe table
		  IOE_PROCESS_SB_R6432M_TABLE(IOEXhci_SbPeiInit_TBL, sizeof(IOEXhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));		 
	    // Process XHCI Driving Table
	      AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED18Xhci_Driving_TBL, IOED18Xhci_Driving_TBL_Items);
	      AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
		//  IOETypeCPatch();
		  AsiaPciModify8((CND003_D14EHCI|IOEEHCI_PORT_CTL_REG_2), 0x20, 0x20);  //;ALWDBG030218

          if (SbCfg->IOEUSBCFLRControl == IOEUSBC_FLR_ENABLE) {
              AsiaPciModify8((CND003_D14UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D14UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D14UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D14EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);

          } else {

              AsiaPciModify8((CND003_D14UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D14UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D14UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D14EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);

         }

         if (SbCfg->IOEUsbOCEn == IOEUSBOC_ENABLE) { //Enable
                 //XHCI OC Mapping
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x134);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x077777, 0x54321);
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
                 //EHCI D16F7 Mapping
                 AsiaPciModify32((CND003_D16EHCI|0xA0), 0xFFFFFF00,   0x54321000);
                 
                 //EHCI D14F7 Mapping
                 AsiaPciModify32((CND003_D14EHCI|0xA0), 0xFFFFFF00,   0x54321000);
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x03FF0000);
          } 
          else
          	{

          //XHCI OC Mapping
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x134);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x077777, 0x00);
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
                 //EHCI D16F7 Mapping
                 AsiaPciModify32((CND003_D16EHCI|0xA0), 0xFFFFFF00,   0xBBBBBB00);
                 
                 //EHCI D14F7 Mapping
                 AsiaPciModify32((CND003_D14EHCI|0xA0), 0xFFFFFF00,   0xBBBBBB00);
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x0);
		  }
		  break;
          
       case IOEUSB_MODE_SEL_MODEC:   //Mode3
          AsiaPciModify8((CND003_EPTRFC | 0x45), 0x80, 0x80);//enable xhci
          AsiaPciModify8((CND003_EPTRFC | 0x45), BIT3|BIT4|BIT5|BIT6, 0x00);//disable Ehci D14
          AsiaPciModify8((CND003_EPTRFC | 0x46), BIT4|BIT5|BIT6|BIT7, 0x00);//disable Ehci D16
          Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
          AsiaMemoryModify8(Membaseaddress+0x1194,BIT0,0x01);
            
          // Process Xhci Safe table
          IOE_PROCESS_SB_R6432M_TABLE(IOEXhci_SbPeiInit_TBL, sizeof(IOEXhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
          //Process XHCI Driving Table
          AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
          IOE_PROCESS_SB_R64326408M_TABLE(IOED18Xhci_Driving_TBL, IOED18Xhci_Driving_TBL_Items);
		  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
		 // IOETypeCPatch();
          if (SbCfg->IOEUsbOCEn == IOEUSBOC_ENABLE) { //Enable
                 //XHCI OC Mapping
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x134);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x077777, 0x54321);
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x03FF0000);
          } 
          else
          	{

               //XHCI OC Mapping
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x134);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x077777, 0x00);
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x0);
		  }
          break;
		  
	  case IOEUSB_MODE_SEL_MODED:	//Mode4
	    AsiaPciModify8((CND003_EPTRFC | 0x45), 0x80, 0x80);//enable xhci
		  AsiaPciModify8((CND003_EPTRFC | 0x45), BIT3|BIT4|BIT5|BIT6, 0x00);//disable Ehci D14
		  AsiaPciModify8((CND003_EPTRFC | 0x46), BIT4|BIT5|BIT6|BIT7, 0xf0);//enable Ehci D16
		  Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
		  AsiaMemoryModify8(Membaseaddress+0x1194,BIT0,0x01);

		  //Process Uhci and EHCI Safe table
          //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci0_SbPeiInit_TBL, sizeof(IOED16Uhci0_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci1_SbPeiInit_TBL, sizeof(IOED16Uhci1_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		 //IOE_PROCESS_SB_R6432M_TABLE(IOED16Uhci2_SbPeiInit_TBL, sizeof(IOED16Uhci2_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));	
		  IOE_PROCESS_SB_R6432M_TABLE(IOED16Ehci_SbPeiInit_TBL, sizeof(IOED16Ehci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV));
      // Process EHCI Driving Table
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED16Ehci_Driving_TBL, IOED16Ehci_Driving_TBL_Items);
		  // Process Xhci Safe table
		  IOE_PROCESS_SB_R6432M_TABLE(IOEXhci_SbPeiInit_TBL, sizeof(IOEXhci_SbPeiInit_TBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
		  //Process XHCI Driving Table
		  AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
		  IOE_PROCESS_SB_R64326408M_TABLE(IOED18Xhci_Driving_TBL, IOED18Xhci_Driving_TBL_Items);
          AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
		//  IOETypeCPatch();

          if (SbCfg->IOEUSBCFLRControl == IOEUSBC_FLR_ENABLE) {
              AsiaPciModify8((CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);
              AsiaPciModify8((CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x01);

          } else {
              AsiaPciModify8((CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);
              AsiaPciModify8((CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG), 0x01, 0x00);

         }

                       
          if (SbCfg->IOEUsbOCEn == IOEUSBOC_ENABLE) { //Enable
                 //XHCI OC Mapping
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x134);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x077777, 0x54321);
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
                 //EHCI D16F7 Mapping
                 AsiaPciModify32((CND003_D16EHCI|0xA0), 0xFFFFFF00,   0x54321000);
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x03FF0000);
          } 
          else
          	{
                 //XHCI OC Mapping
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x134);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x077777, 0x00);
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
                 //EHCI D16F7 Mapping
                 AsiaPciModify32((CND003_D16EHCI|0xA0), 0xFFFFFF00,   0xBBBBBB00);
                 //ISB MMIO OC Pin Mux
                 Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
                 AsiaMemoryModify32(Membaseaddress+0x1178,0xFFFF0000,0x0);


		  }
	#if 0
		  //Improve xHCI TX signal, U3IP_SSCFG_Rx4C[14:12]=111b
		  AsiaPciModify32((CND001_XHCI|D18F0_XHCI_OPTIONAL_BITS_CFG_ADR),  0xFFFFF, 0x2004C);
		  AsiaPciModify8((CND001_XHCI|D18F0_XHCI_OPTIONAL_BITS_CFG_DATA_Byte1), 0x70,  0x70 );	
	#endif
		  break;
	  }

    //Process IOERTD3Control
    if (SbCfg->IOERTD3Control == IOERTD3_ENABLE) {
       AsiaPciModify8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_8 + 1, BIT3, BIT3);
    } 
    else
    	{
       AsiaPciModify8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_8 + 1, BIT3, 0x0);
	}
    //Process IOE USB S4 wakeup
    if (SbCfg->IOEUsbS4Wakeup) {
      AsiaPciModify8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_8 + 1, BIT2, BIT2);
    } 
	else
    	{
		AsiaPciModify8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_8 + 1, BIT2, 0x0);
	}
    
    //ttpandbg:gpi
    Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
    AsiaMemoryModify8(Membaseaddress+0x1114,BIT0,BIT0); 
	//ALJ20170511,set GPI level trigger mode
	AsiaIoModify8(0x800+0x80,BIT4,BIT4);
	AsiaMemoryModify8(Membaseaddress+0x1137,BIT6,BIT6); 


    switch (SbCfg->IOEUsbModeSelect) {
        case IOEUSB_MODE_SEL_MODEB:
        case IOEUSB_MODE_SEL_MODEC:
        case IOEUSB_MODE_SEL_MODED:
            IOETypeAPatch();
            IOETypeCPatch();
			if ((SbCfg->IoeChipRevision) == IOE_REVISION_A0){                
                AsiaPciModify8((CND003_XHCI | 0x5B),	  0x40,  0x40); // Enable USB2.0 flash downmode patch
            }
            
            //Process IOETRBCacheBypass
            if (SbCfg->IOETRBCacheBypass == IOETRB_CACHE_NOT_BYPASS) {
              AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x01); // Enable Access
        		  AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x20);
        		  AsiaPciModify8((CND003_XHCI | 0x7C), 0x01, 0x00);
        		  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
            } else {
              AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x01); // Enable Access
        		  AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x20);
        		  AsiaPciModify8((CND003_XHCI | 0x7C), 0x01, 0x01);
        		  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
            }

            
            //Process IOEXhciOutBurstEn
            if (SbCfg->IOEXhciOutBurstEn== IOEUSB_OUTBURST_ENABLE) {
              AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x01); // Enable Access
        		  AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x60);
        		  AsiaPciModify8((CND003_XHCI | 0x7C), 0x03, 0x00);
        		  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
            } else {
                  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x01); // Enable Access
        		  AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x60);
        		  AsiaPciModify8((CND003_XHCI | 0x7C), 0x03, 0x03);
        		  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
            }

            
            //Process IOEXHCIFLRControl
             if (SbCfg->IOEXHCIFLRControl == IOEXHCI_FLR_ENABLE) {
               AsiaPciModify8((CND003_XHCI | 0x43),    0x01,  0x01); // Enable Access
               AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x6C);
               AsiaPciModify8((CND003_XHCI | 0x7F), 0x04, 0x04);
               AsiaPciModify8((CND003_XHCI | 0x43),    0x01,  0x00); // Disable Access
             } else {
               AsiaPciModify8((CND003_XHCI | 0x43),    0x01,  0x01); // Enable Access
                   AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x6C);
                   AsiaPciModify8((CND003_XHCI | 0x7F), 0x04, 0x00);
                   AsiaPciModify8((CND003_XHCI | 0x43),    0x01,  0x00); // Disable Access
             }

            //Process IOE USB C4 Block
            if (SbCfg->IOEUsbC4Block) {

              PEI_DEBUG((PeiServices, EFI_D_ERROR, "Enter C4 Block\n")); 
              //CND003 Setting
              //BUSXD0F0 MMIO ISB Rx10[4]: R_DBGINGPIOGRP_EN = 0
              Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
              AsiaMemoryModify8(Membaseaddress+0x1110,BIT4,0x0); 

              //BUSXD0F0 MMIO ISB Rx34[14]: R_JTAG_EN=0
              AsiaMemoryModify32(Membaseaddress+0x1134,BIT14,0x0); 

              //BUSXD0F0 MMIO ISB Rx0C[9:8]: R_JTAG_EN=0R_PAD_GPIO4 = 2'b10
             // AsiaMemoryModify32(Membaseaddress+0x110C,BIT9|BIT8,BIT9);  //;cjw-A0-debug 20161215  This is platform related code, moved to /platform folder

              //
              //HS_ISOINHC4_EN
              //SS_ISOINHC4_EN
              //SSP_ISOINHC4_EN
              AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
              AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70);
              AsiaPciModify8((CND003_XHCI | 0x7C), BIT0|BIT1|BIT2, BIT0|BIT1|BIT2);
        	  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
             }
			else//ALJ20170713 add for disable blockc4 action
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Disable C4 Block\n")); 
              //CND003 Setting
              //BUSXD0F0 MMIO ISB Rx10[4]: R_DBGINGPIOGRP_EN = 0
              Membaseaddress=AsiaPciRead32(CND003_PEEP | 0x10);
              AsiaMemoryModify8(Membaseaddress+0x1110,BIT4,BIT4); 

              //BUSXD0F0 MMIO ISB Rx34[14]: R_JTAG_EN=0
              AsiaMemoryModify32(Membaseaddress+0x1134,BIT14,BIT14); 

              //BUSXD0F0 MMIO ISB Rx0C[9:8]: R_JTAG_EN=0R_PAD_GPIO4 = 2'b10
              //AsiaMemoryModify32(Membaseaddress+0x110C,BIT9|BIT8,BIT9);  //;cjw-A0-debug 20161215  This is platform related code, moved to /platform folder

              //
              //HS_ISOINHC4_EN
              //SS_ISOINHC4_EN
              //SSP_ISOINHC4_EN
              AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
              AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x70);
              AsiaPciModify8((CND003_XHCI | 0x7C), BIT0|BIT1|BIT2, 0x0);
        	  AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
			}

            #if 0
            // Only IOE need config PAD CTRL to upward C4 inhabit request
            if (SbCfg->IOEUsbC4Block == IOEUSB_C4BLOCK_ENABLE) {
                AsiaIoModify16((SbCfg->PmioBar + PMIO_PAD_CTL_REG_Z1),                     PMIO_P2G_GPIO36_2_1_0,                                  BIT9);
            } else {
                AsiaIoModify16((SbCfg->PmioBar + PMIO_PAD_CTL_REG_Z1),                     PMIO_P2G_GPIO36_2_1_0,                                  0x00);
            }
            #endif

              //Process IOE USB 10G Support
              if (SbCfg->IOEUsb10GSupport == IOEUSB10G_ENABLE) { //Enable

                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x88);
                 AsiaPciModify32((CND003_XHCI | 0x7C),       0x01100000, 0x01100000);
                 //disable u1/u2 
               #if 0
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20420);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20520);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
               #endif
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x00); // Disable Access
              
              
              } else { //Disable
                 AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x88);
                 AsiaPciModify32((CND003_XHCI | 0x7C), 0x01100000,0x00000000);
                 AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x00); // Disable Access
              }
			  #if 0
              //Disable U1U2
              if (SbCfg->CRBPlatformSelection == CRB_PLATFORM_MODE_SELECTION_DESKTOP) {
                 AsiaPciModify8((CND003_XHCI | 0x43),        0x01,       0x01); // Enable Access
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20120);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20220);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20320);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20420);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
                 AsiaPciModify32((CND003_XHCI | 0x78),       0xFFFFF,    0x20520);
                 AsiaPciModify8((CND003_XHCI | 0x7C),        0x06,       0x00);
                 AsiaPciModify8((CND003_XHCI | 0x43),      0x01,  0x00); // Disable Access
              }
			  #endif

			  
			   // EIRTN:Electrical Idle Triggled Retrain 
			   if (SbCfg->IOEUsbEITRN == IOEUSBEITRN_DISABLE) { //DISABLE
					 AsiaPciModify8((CND003_XHCI | 0x43),		  0x01, 	  0x01); // Enable Access
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20120);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x00000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20220);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x00000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20320);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x00000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20420);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x00000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20520);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x00000000);
					 AsiaPciModify8((CND003_XHCI | 0x43),		  0x01, 	  0x00); // Disable Access
			  } else {//ENABLE
					 AsiaPciModify8((CND003_XHCI | 0x43),		  0x01, 	  0x01); // Enable Access
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20120);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x80000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20220);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x80000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20320);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x80000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20420);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x80000000);
					 AsiaPciModify32((CND003_XHCI | 0x78),		  0xFFFFF,	  0x20520);
					 AsiaPciModify32((CND003_XHCI |0x7C),		  0x80000000, 0x80000000);
					 AsiaPciModify8((CND003_XHCI | 0x43),		  0x01, 	  0x00); // Disable Access
			  }
              break;
        
    }
  
  IoePeiClearTempAssignment(PeiServices);
  return EFI_SUCCESS;
}


