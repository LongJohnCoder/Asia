/*******************************************************************************
Copyright(C) 2018 Shanghai Zhaoxin Technologies, Inc. All Rights Reserved.

Information in this file is the intellectual property of Shanghai Zhaoxin Technologies, Inc.,
and may contains trade secrets that must be stored and viewed confidentially.

\file CHX002Cfg.h
\brief ASIA Configuration Structure definition for CHX002.
\date 2017-05-17

Modification History:
    
*******************************************************************************/

#ifndef CHX002_CFG_H
#define CHX002_CFG_H

// General values
// Chip(e.g. Nb, Sb) SPE values
#define CHIP_SPE_VALUE_MANUAL 0
#define CHIP_SPE_VALUE_STABLE 1
#define CHIP_SPE_VALUE_PERFORMANCE 2
#define CHIP_SPE_VALUE_ENERGY 3
// Device(e.g. D0F0 or SATA) SPE values
#define DEVICE_SPE_VALUE_STABLE 0
#define DEVICE_SPE_VALUE_PERFORMANCE 1
#define DEVICE_SPE_VALUE_ENERGY 2

/////
#define ZX_SINGLE_SOCKET_MODE  0
#define ZX_DUAL_SOCKET_MODE  1
/////

// Combine two sockets' setupvariable into one
#define SETUPVALUE_MASK_LEN     4
#define SETUPVALUE_MASK         0x0F
#ifdef ZX_DUALSOCKET
#define SETUPVALUE_MASK_SLAVE   0xF0
#endif

	////
#include "AsiaNbCfg.h"
#include "AsiaDramCfg.h"
#include "AsiaSbCfg.h"
	////
	
#endif
