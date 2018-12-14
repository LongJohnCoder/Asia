//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************



#include "IoeConfig.h"



//
//	IOE DN port PHYCFG
//
CND003_PEXPHYCFG IoePhyCfg = {2, 3};

//
// IOE Capability CFG
//
CND003_PEXCAP IoePecap = {
	3,	//PEEP
	2,	//PEA0
	2,
	2,
	2,
	2,	//PEA4
	2,	//PEB0
	2,
	1 //PESB
};


CND003_PINMUX_CFG IoePinMuxCfg = {
	0,//GPIO7 
	0,// 6
	1,// 5 - PERST
	2,// 4 - USB_BLK_C4
	1,// 3 - PERST
	1,// 2 - PERST
	1,// 1 - PERST
	1,// 0 - PERST

	0,// 9
	0,// 8
	1,// GPO5 SATALED
	1,// 4 - SATALED
	1,// 3 - SATALED
	1,// 2 - SATALED
	0,// 1
	0,// 0
};



CND003_XHCI_SSP IoeXhciSspPortCfg = {CND003_TYPEC, CND003_TYPEC, 7};   //SSP port1:TypeC   port2:TypeC FWVersion:7





