//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef _IOE_PHY_CFG_
#define _IOE_PHY_CFG_

#include "Tiano.h"


//
// if not present this on this platform, must define as FF
//
#define GPIO_RESET_PEA0 IOE_GPIO5
#define GPIO_RESET_PEA1 0xFF
#define GPIO_RESET_PEA2 0xFF
#define GPIO_RESET_PEA3 0xFF
#define GPIO_RESET_PEA4 IOE_GPIO0
#define GPIO_RESET_PEB0 0xFF
#define GPIO_RESET_PEB1 0xFF

#define HOST_LANE_REVERSAL_EN  0
#define HOST_LANE_REVERSAL_BUS 0xFF  // means nothing
#define HOST_LANE_REVERSAL_DEV 0xFF  // means nothing
#define HOST_LANE_REVERSAL_FUN 0xFF  // means nothing

//#define RP_CONNECTED_TO_IOE  CHX001_PEG

/**
CND003 code execution rules:
	All CND003 codes will check SCRATCH registers 
	CND001/CHX001: D0F6 Rx47[0]
	if [D0F6 Rx47[0] = 1]
	then 	
		CND003 related code run 	
	Else
		Not run
	Endif
	
**/
//#define CND003_CODE_EXECUTE  1

typedef struct{
	UINT8 gpio7;
	UINT8 gpio6;
	UINT8 gpio5;
	UINT8 gpio4;
	UINT8 gpio3;
	UINT8 gpio2;
	UINT8 gpio1;
	UINT8 gpio0;

	UINT8 gpio9;
	UINT8 gpio8;
	UINT8 gpo5;
	UINT8 gpo4;
	UINT8 gpo3;
	UINT8 gpo2;
	UINT8 gpo1;
	UINT8 gpo0;
}CND003_PINMUX_CFG;



#define CND003_TYPEA 0
#define CND003_TYPEC 1
typedef struct{
	UINT8 ssp_port1;	//corresponding to the setting of XHCI D18F0 Rx5B
	UINT8 ssp_port2;
    UINT8 FwVersion;    //0~12
}CND003_XHCI_SSP;



/**
CND003 PCIE capability configure rules:
	Example for PEEP:
	If [CND003_PEXCAP.CapPEEP = 0]
	then
		Read PCIE capability setting from Setup Menu
	Else
		Set PEEP capability as CND003_PEXCAP.CapPEEP
	Endif
**/
typedef struct{
	UINT8 CapPEEP;
		// 1/2/3 -> Gen1/2/3
		// 0 -> Read PCIE capability setting from Setup Menu
	UINT8 CapPEA0;
		// 1/2 -> Gen1/Gen2
	UINT8 CapPEA1;
	UINT8 CapPEA2;
	UINT8 CapPEA3;
	UINT8 CapPEA4;
	UINT8 CapPEB0;
	UINT8 CapPEB1;
	UINT8 CapPESB;
}CND003_PEXCAP;

/**
CND003 PHY CONFIG rules:
	If [Setup Menu Setting as CFG0/CFG1/CFG2/CFG3]
	then
		Set PHY config as the setting we set
	Elseif [Setup Menu Setting as FIXED ]
		Read CND003_PEXPHYCFG struct as PHY config 
	Endif
**/
typedef struct{
	UINT8 PhyACfg;		// 0 - 3
	UINT8 PhyBCfg;		// 0 - 3
}CND003_PEXPHYCFG;


#define HOST_PEXRST_FOR_CND003()  PeiNbResetPciePortx(PeiServices, CHX002_PE0)



extern CND003_PEXPHYCFG IoePhyCfg;
extern CND003_PEXCAP IoePecap;

extern CND003_PINMUX_CFG IoePinMuxCfg;

extern CND003_XHCI_SSP IoeXhciSspPortCfg;
#endif
