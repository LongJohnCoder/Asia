
/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbHif.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/


#ifndef _ASIA_NBHIF_PPI_INTERFACE_H_
#define _ASIA_NBHIF_PPI_INTERFACE_H_

#include "pei.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaNbPeim.h"
#include "AsiaIoLib.h"
#include "PeiLib.h"

//#include EFI_PPI_DEFINITION(AsiaNBPpi)
//#include EFI_PPI_DEFINITION(AsiaSBPpi)
//#include EFI_PPI_DEFINITION(AsiaCpuPpi)



EFI_STATUS
PeiHIFInit(
    IN EFI_PEI_SERVICES **,
    IN ASIA_NB_CONFIGURATION *
);

#endif //_ASIA_NBHIF_PPI_INTERFACE_H_
