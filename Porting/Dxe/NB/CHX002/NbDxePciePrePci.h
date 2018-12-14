/** @file
   ZX-E(CHX002) Asia NbDxe library functions : NbDxePciePrePci.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef __NB_DXE_PCIE_PRE_PCI_H__
#define __NB_DXE_PCIE_PRE_PCI_H__

#include "NbDxePciePrePciCommon.h"

#if 1

EFI_STATUS
SetExitLatencyCapability(
    ASIA_NB_CONFIGURATION *NbCfg
);

EFI_STATUS
RPReProgramL1ExitLatency(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT64 Addr,
	RPL1SET_TBL *Ptx,
	UINT8 TblIndex
);

/*- DSZ_Porting -- (YSW-2017031701) Modify PCIE Module Code for RP L1 Exit Latency Capability calculation*/
EFI_STATUS
PciePrePciInit(ASIA_NB_CONFIGURATION *NbCfg);
#endif



#endif

