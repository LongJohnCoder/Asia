//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/* 

platform related setting

*/
#include "AsiaIoSaveLib.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"

EFI_STATUS
AsiaPlatformPrePciInit(
    IN ASIA_SB_CONFIGURATION *SbCfg )
{      
    ////
    //if(SbCfg->OnBoard1394Enable)
    //{
    //    AsiaPciModifySave8((CHX001_P2PB|D19F0_EXTERNAL_PCI_DEV_ENABLE_CTL), 0x40, 0x00);
    //}
    //else
    //{
    //    AsiaPciModifySave8((CHX001_P2PB|D19F0_EXTERNAL_PCI_DEV_ENABLE_CTL), 0x40, 0x40);
    //}
    ////
    
    return EFI_SUCCESS;
}

