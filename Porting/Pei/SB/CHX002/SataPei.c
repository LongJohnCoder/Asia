/** @file
   ZX-E(CHX002) Asia SbPei library functions : SataPei.c

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
#include "SataPei.h"


#define  SATA_PORT   2


STATIC ASIA_IO_TABLE_6408_REV Sata_Safe_TBL[] =
{
    //These S value are same with default value, remove it
	#if 0
	{0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CHN_ENABLE),                        0x02, 0x02},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_INTR),                              0x12, 0x12},
    {0x00, 0xFF, (CHX002_SATA|D15F0_MISC_CTL_1),                             0x90, 0x10},
    {0x00, 0xFF, (CHX002_SATA|D15F0_MISC_CTL_2),                             0x62, 0x02},
    {0x00, 0xFF, (CHX002_SATA|D15F0_MISC_CTL_3),                             0x34, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_DMAC_ECLK150_GATING),               0x03, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1),         0x03, 0x00}, 
    
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_MISC_CTL),                          0x08, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CMD_CTL_REG),                       0xF0, 0x20},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_CTL_REG_1),                    0xE3, 0xC1},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_CTL_REG_2),                    0xFF, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_TEST_MODE_CTL_2),                    0x80, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_TEST_MODE_CTL_3),                    0x80, 0x80},
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_CTL_REG_2),                          0x80, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CTL_REG_2_PROVIDE_OPTIONS_FOR_RX_RETIMED_LOOPBACK_BIST_L_TEST), 0x78, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CTL_REG_3),                         0xFC, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CTL_REG_4),                         0x23, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_STRFUP_CTL_AND_PMP_ERR_REG),        0x0C, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_TRANSPORT_MISC_CTL),                0x33, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_CHN_TRANSPORT_MISC_CTL),                 0x03, 0x00},
    
    {0x00, 0xFF, (CHX002_SATA|D15F0_PATA_SATA_MISC_CTLS),                    0x33, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CTL_REG_4_Z1),                      0x33, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CTL_REG_5_Z1),                      0x10, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_TXCDC_CTL),                         0x02, 0x00},

    {0x00, 0xFF, (CHX002_SATA|(D15F0_PM_IF_REV+1)),                          0xF8, 0x40},
    {0x00, 0xFF, (CHX002_SATA|D15F0_PM_CAP_STA),                             0x03, 0x00},
    {0x00, 0xFF, (CHX002_SATA|(D15F0_PM_CAP_STA+1)),                         0x01, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_MISC_REGS_382_RX4A),                0xDC, 0x04},
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_TRANSPORT_MISC_CTL_382_RX52),       0xF0, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS), 0x40, 0x40},
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_CACHE_BIST_CTL),                    0x01, 0x00}, 
    {0x00, 0xFF, (CHX002_SATA|D15F0_SID_DEV_FUN),                            0x07, 0x00}, 
    
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL),    0x0F, 0x00},  //Rx42
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG),            0x01, 0x00},  //Rx49
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_SPEED_NEGOTIATION_CTL),             0x10, 0x00},  //Rx4F
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_CTL_REG_1),                          0x01, 0x00},  //Rx5C
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_PM_MODE),                       0x60, 0x60},  //Rx84
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_DYNAMIC_CLK_CTL_REG_2),             0x0F, 0x00},  //RxDD 
    
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL),    0x0F, 0x01},  //Rx42
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG),            0x01, 0x00},  //Rx49
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_SPEED_NEGOTIATION_CTL),             0x10, 0x00},  //Rx4F
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_CTL_REG_1),                          0x01, 0x00},  //Rx5C
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_PM_MODE),                       0x60, 0x60},  //Rx84
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_DYNAMIC_CLK_CTL_REG_2),             0x0F, 0x00},  //RxDD
    #endif
	
    //{0x00, 0xFF, (CHX002_SATA|D15F0_EPHY_DE_GLITCH_FUN_CTL),	  0x80, 0x80}, //RxFF
    
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};


STATIC ASIA_IO_TABLE_6408_REV Sata_Safe_TBL_IDE[] =
{
    //{0x00, 0xFF, (CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x0C},
    //{0x00, 0xFF, (CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),    0x0C, 0x0C},
    
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};


STATIC ASIA_IO_TABLE_6408_REV Sata_Safe_TBL_AHCI[] =
{
    //{0x00, 0xFF, (CHX002_SATA|D15F0_MSG_SIGNALED_INTR_MSG_CTL_MC),   0x70, 0x00}, 
    
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};

/**
   Dump Sata MMIO Space.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

VOID
SataDumpMmioPei(
  IN  EFI_PEI_SERVICES        **PeiServices,
  IN  ASIA_SB_CONFIGURATION    *SbCfg
  )
{
    UINT8        i;
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;
    UINT8        Value;
    UINT32       BaseAddress;
    UINT32       BaseAddress02;
    
    if(SbCfg->SataCfg==SATA_CFG_AHCI){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[D15F0]: SATA MMIO\n"));
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "--------+-----------------------------------------------\n"));
        
        Value = AsiaPciRead8(CHX002_SATA|0x04);
        AsiaPciWrite8((CHX002_SATA|0x04),0x7);
        
        BaseAddress = AsiaPciRead32(CHX002_SATA|0x24);
        AsiaPciWrite32((CHX002_SATA|0x24),(0xD0200000|(BaseAddress&0xFF)));
        BaseAddress02 = AsiaPciRead32(CHX002_SATA|0x24);
        
        for(Index1=0;Index1<0x04;Index1++){
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%08x|", BaseAddress02+Index1*16));
            for(Index2=0;Index2<0x10;Index2++){
                Data = AsiaMemoryRead8(BaseAddress02+(Index1*16+Index2));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ", Data));
                if(Index2==0x0F){
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
                }
            }
        }
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "--------------------------------------------------------\n"));

        for(i=0;i<SATA_PORT;i++){
            for(Index1=0;Index1<0x05;Index1++){
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "%08x|", BaseAddress02+0x100+0x80*i+Index1*16));
                for(Index2=0;Index2<0x10;Index2++){
                    Data = AsiaMemoryRead8(BaseAddress02+0x100+0x80*i+(Index1*16+Index2));
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ", Data));
                    if(Index2==0x0F){
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
                    }
                }
            }
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "--------------------------------------------------------\n"));
        }
        
        AsiaPciWrite32((CHX002_SATA|0x24),BaseAddress);
        AsiaPciWrite8((CHX002_SATA|0x04),Value);
    }
}

/**
   Dump Sata Cfg Space.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

VOID
SataDumpConfigPei(
  IN  EFI_PEI_SERVICES         **PeiServices,
  IN  ASIA_SB_CONFIGURATION    *SbCfg
  )
{
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[D15F0]: SATA\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "--+-----------------------------------------------\n"));
    for(Index1=0;Index1<0x10;Index1++){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x|", Index1*16));
        for(Index2=0;Index2<0x10;Index2++){
            Data = AsiaPciRead8(CHX002_SATA|(Index1*16+Index2));
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ", Data));
            if(Index2==0x0F){
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
            }
        }    
    }
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "--------------------------------------------------\n"));
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

EFI_STATUS
EFIAPI
SataPei(
  IN  EFI_PEI_SERVICES         **PeiServices,
  IN  ASIA_SB_CONFIGURATION    *SbCfg
  )
{
    UINT16        VendorID;
    UINT16        DeviceID;

    VendorID = AsiaPciRead16(CHX002_SATA|D15F0_VID);
    DeviceID = AsiaPciRead16(CHX002_SATA|D15F0_DID);
    if((VendorID!=0x1106 && VendorID!=0x1d17) || (DeviceID!=0x9002 && DeviceID!=0x9003 && DeviceID!=0x9083)){
        return EFI_SUCCESS;
    }

    SataDumpConfigPei(PeiServices, SbCfg);
    
    // Modify Subclass Code
    AsiaPciModify8((CHX002_SATA|D15F0_MISC_CTL_2), 0x80, 0x80);
    if (SbCfg->SataCfg == SATA_CFG_AHCI){
        AsiaPciModify8((CHX002_SATA|D15F0_SUB_CLASS_CODE), 0xFF, 0x06); 
    }else if (SbCfg->SataCfg == SATA_CFG_IDE){
        AsiaPciModify8((CHX002_SATA|D15F0_SUB_CLASS_CODE), 0xFF, 0x01); 
    }
    AsiaPciModify8((CHX002_SATA|D15F0_MISC_CTL_2), 0x80, 0x00);

    // Process Sata Safe table
    PROCESS_SB_R6408M_TABLE(Sata_Safe_TBL, sizeof(Sata_Safe_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
    if (SbCfg->SataCfg == SATA_CFG_IDE){
        PROCESS_SB_R6408M_TABLE(Sata_Safe_TBL_IDE, sizeof(Sata_Safe_TBL_IDE)/sizeof(ASIA_IO_TABLE_6408_REV));   
    }else if(SbCfg->SataCfg == SATA_CFG_AHCI){
        PROCESS_SB_R6408M_TABLE(Sata_Safe_TBL_AHCI, sizeof(Sata_Safe_TBL_AHCI)/sizeof(ASIA_IO_TABLE_6408_REV));
    }

    // Process SATA Driving Table ZYC - 20180808 remove to NbInit.c
    //PROCESS_SB_R64326408M_TABLE(Sata_Driving_TBL, Sata_Driving_TBL_Items);

    // Set Gen Speed
    if(SbCfg->SataCfg == SATA_CFG_IDE){
       switch(SbCfg->IDEGen){
           case 1: 
                AsiaPciModify8((CHX002_SATA|D15F0_SATA_SPEED_CTL), 0x0F, 0x00); 
                break;
           
           case 2: 
                AsiaPciModify8((CHX002_SATA|D15F0_SATA_SPEED_CTL), 0x0F, 0x05); 
				AsiaPciModify8((CHX002_SATA|D15F0_SATA_CTL_REG_5), D15F0_W4ALIGNTOUT_EN, D15F0_W4ALIGNTOUT_EN);
                break;
           
           case 3: 
           default:         
                AsiaPciModify8((CHX002_SATA|D15F0_SATA_SPEED_CTL), 0x0F, 0x0A);
       }
    }else if(SbCfg->SataCfg == SATA_CFG_AHCI){    
       switch(SbCfg->AHCIGen){
           case 1: 
                AsiaPciModify8((CHX002_SATA|D15F0_AHCI_CACHE_BIST_CTL), 0xF0, 0x10); 
                break;
           
           case 2: 
                AsiaPciModify8((CHX002_SATA|D15F0_AHCI_CACHE_BIST_CTL), 0xF0, 0x20);
				AsiaPciModify8((CHX002_SATA|D15F0_SATA_CTL_REG_5), D15F0_W4ALIGNTOUT_EN, D15F0_W4ALIGNTOUT_EN);
                break;
           
           case 3: 
           default:         
                AsiaPciModify8((CHX002_SATA|D15F0_AHCI_CACHE_BIST_CTL), 0xF0, 0x30);   
       }         
    }
    
    // Enable/Disable AHCI MSI/MSIX/Hotplug
    if(SbCfg->SataCfg == SATA_CFG_AHCI){
        if(SbCfg->AHCIMSI){
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS), 0x02, 0x00); 
        }else{
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS), 0x02, 0x02);
        }
            
        if(SbCfg->AHCIMSIX){
            AsiaPciModify8((CHX002_SATA|D15F0_SATA_SPEED_STA_CTL), 0x40, 0x00);
        }else{
            AsiaPciModify8((CHX002_SATA|D15F0_SATA_SPEED_STA_CTL), 0x40, 0x40);
        }
        
        if(SbCfg->AHCIHotplugEn){
            AsiaPciModify8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS),     0x01, 0x01);  
            AsiaPciModify8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS),     0x01, 0x01);  
        }else{
            AsiaPciModify8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS),     0x01, 0x00);  
            AsiaPciModify8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS),     0x01, 0x00);  
        } 

        if(SbCfg->AHCIALPMEn == FALSE|| SbCfg->CRBPlatformSelection == CRB_PLATFORM_MODE_SELECTION_DESKTOP){
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_GHC_CAP_OPTIONAL_REG_0),      D15F0_SUP_LKPWR, 0x00); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1), D15F0_SUP_PART,  0x00);  
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1), D15F0_SUP_SLUM,  0x00);
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS),  D15F0_SUP_DEVSLP,0x00); 
        }else{
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_GHC_CAP_OPTIONAL_REG_0),      D15F0_SUP_LKPWR, D15F0_SUP_LKPWR); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1), D15F0_SUP_PART,  D15F0_SUP_PART);    
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1), D15F0_SUP_SLUM,  D15F0_SUP_SLUM); 
            AsiaPciModify8((CHX002_SATA|D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS),  D15F0_SUP_DEVSLP,D15F0_SUP_DEVSLP); 
        }
    }

    // Enable/Disable Function Level Reset
    if(SbCfg->FuncLevelResetEn){
        AsiaPciModify8((CHX002_SATA|D15F0_SATA_FUN_LEVEL_RESET_FLR_2), 0x03, 0x03);   
    }else{
        AsiaPciModify8((CHX002_SATA|D15F0_SATA_FUN_LEVEL_RESET_FLR_2), 0x03, 0x00);    
    }
	
    //Enable/Disable GB_FLUSHEND
    if(SbCfg->GBFlushendEn){
        AsiaPciModify8((CHX002_SATA|D15F0_SATA_INTR), 0x60, 0x60);   
    }else{
        AsiaPciModify8((CHX002_SATA|D15F0_SATA_INTR), 0x60, 0x00);    
    }

	//20180504 -Enable RX EIDLE signal filter function RxFF[7]
	AsiaPciModify8((CHX002_SATA|D15F0_EPHY_DE_GLITCH_FUN_CTL), D15F0_RXEIDLE_FILTER_EN, D15F0_RXEIDLE_FILTER_EN); 

    // Check Two Bursts to Judge COMMINIT and COMWAKE When OOB Is Received from Device
    AsiaPciModify8((CHX002_SATA|D15F0_SATA_CTL_REG_5_Z1), 0x40, 0x40);

    // Enable Rx3C Write
    AsiaPciModify8((CHX002_SATA|D15F0_MISC_CTL_2), 0x10, 0x10);


    // Start OOB
    AsiaPciModify8((CHX002_SATA|D15F0_LEGACY_SATA_OOB_KICK_OFF_CTL), 0x03, 0x03);

    SataDumpConfigPei(PeiServices, SbCfg);
    
    return EFI_SUCCESS;
}


/**
   SATA PEI Init function.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

EFI_STATUS
EFIAPI
SataInitPei(
  IN EFI_PEI_SERVICES       **PeiServices, 
  IN ASIA_SB_CONFIGURATION  *SbCfg
  )
{
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[SATA-PEI]: SATA PEI Init Start\n"));
    
    if(!SbCfg->SataEn){
        AsiaPciModify8((CHX002_BUSC|D17F0_FUN_CTL_1), D17F0_D15F0ENSATA, 0);
    }else{
        SataPei(PeiServices, SbCfg);     
    }
        
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[SATA-PEI]: SATA PEI Init End\n"));
    return EFI_SUCCESS;
}
