/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoeSata.c

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
#include "SbDriving.h"

#include "SIPcieDriving.h"
#include "IoeSata.h"
#include "IoeSbDriving.h"

 
#define IOE_D15F0_GEN_1                BIT4
#define IOE_D15F0_GEN_2                BIT5
#define IOE_D15F0_GEN_3                (BIT4|BIT5)


STATIC ASIA_IO_TABLE_6408_REV IOESata_Safe_TBL[] =
{
    {0x00, 0xFF, (CHX002_SATA|D15F0_EPHY_DE_GLITCH_FUN_CTL),	  0x80, 0x80}, //RxFF
    {0xFF,  0x00,   0x00,   0x00,   0x00}
};


STATIC ASIA_IO_TABLE_6408_REV IOESata_Safe_Tbl_IDE[] =
{
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x0C},
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),    0x0C, 0x0C}, 
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x0C},
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),  0x0C, 0x0C},
    
    {0xFF, 0x00, 0x00,   0x00,   0x00}
};

/**
   IoeSATA used delay function.
   
  @param  Count

  @return VOID.

**/

void 
Delay(
  IN UINT32 count
  )
{
    UINT32 i, j;

    for(i=0; i < count; i++)
    {
        for(j=0; j < 100; j++)
        AsiaIoWrite8(0x80, 0x11);
    }
}

/**
   IOE SATA Config space dump.
      
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return VOID.

**/

VOID
IOESataDump_PEI(
    IN  EFI_PEI_SERVICES  **PeiServices
)
{
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PEI Dump CND003 D15F0:\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "--+-----------------------------------------------\n"));
    for(Index1=0;Index1<0x10;Index1++){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x|", Index1*16));
        for(Index2=0;Index2<0x10;Index2++){
            Data = AsiaPciRead8(CND003_SATA|(Index1*16+Index2));;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ", Data));
            if(Index2==0x0F){
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
            }
        }
        if((Index1%0x10)==0x0F){
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "--------------------------------------------------\n"));
        }
    }
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
}

/**
   IOE SATA PEI detect exist or not.

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
IOESataExist_PEI(
    IN  EFI_PEI_SERVICES  **PeiServices
)
{
    UINT16        VendorID;
    UINT16        DeviceID;
    
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Lex]: CHECK SATA CONTROLLER EXIST OR NOT\n"));
    VendorID = AsiaPciRead16(CND003_SATA|0x0);
    DeviceID = AsiaPciRead16(CND003_SATA|0x2);
    if((VendorID==0x1106 || VendorID==0x1d17) && (DeviceID==0x9002 || DeviceID==0x9083)){
        return EFI_SUCCESS;
    }
    return EFI_NOT_FOUND;
}

/**
   IOE SATA PEI Init function.
   Called by IoeSataPeiInit()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return EFI_SUCCESS.

**/

EFI_STATUS
EFIAPI
IOESataInit(
    IN EFI_PEI_SERVICES      **PeiServices,
    IN ASIA_SB_CONFIGURATION *SbCfg
    )
{
#ifdef CND003_FPGA
    // Disable Port 1/2/3 for HAPS Verify
    if(SbCfg->IOESataCfg == SATA_CFG_AHCI){  
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0xFF, 0x01); 
        AsiaPciModify8((CND003_SATA|CND003_D15F0_AHCI_PORT_IMPLEMENT_REGS), 0x01, 0x00);
        
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0xFF, 0x02); 
        AsiaPciModify8((CND003_SATA|CND003_D15F0_AHCI_PORT_IMPLEMENT_REGS), 0x01, 0x00);
        
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0xFF, 0x03); 
        AsiaPciModify8((CND003_SATA|CND003_D15F0_AHCI_PORT_IMPLEMENT_REGS), 0x01, 0x00);

        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0xFF, 0x00); 
    }

    // Disable Secondary Channel for HAPS Verify
    AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_CHN_ENABLE), 0x01, 0x00);
#endif

    // Process Sata Safe table
    PROCESS_SB_R6408M_TABLE(IOESata_Safe_TBL, sizeof(IOESata_Safe_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
    if (SbCfg->IOESataCfg == SATA_CFG_IDE){
        PROCESS_SB_R6408M_TABLE(IOESata_Safe_Tbl_IDE, sizeof(IOESata_Safe_Tbl_IDE)/sizeof(ASIA_IO_TABLE_6408_REV)); 
    }

    // Process SATA Driving Table
    IOE_PROCESS_SB_R64326408M_TABLE(IOED15Sata_Driving_TBL, IOED15Sata_Driving_TBL_Items);
     
    AsiaPciModify8((CND003_SATA|CND003_D15F0_MISC_CTL_2), 0x80, 0x80);
    if (SbCfg->IOESataCfg == SATA_CFG_AHCI){
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SUB_CLASS_CODE), 0xFF, 0x06);  
    }else if (SbCfg->IOESataCfg == SATA_CFG_IDE){
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SUB_CLASS_CODE), 0xFF, 0x01);  
    }
    AsiaPciModify8((CND003_SATA|CND003_D15F0_MISC_CTL_2), 0x80, 0x00);
   
    if(SbCfg->IOESataCfg == SATA_CFG_IDE){
       switch(SbCfg->IOESataGen){
           case 1: 
                AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_SPEED_CTL,          0xFF,    0x00); 
                AsiaPciWrite16(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_PTR,   0x108);
                AsiaPciWrite8(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3, 0x00); 
                break;
           
           case 2: 
                AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_SPEED_CTL,          0xFF,    0x55); 
                AsiaPciWrite16(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_PTR,   0x108);
                AsiaPciWrite8(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3, 0xAA); 
                break;
           
           case 3: 
           default:         
                AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_SPEED_CTL,          0xFF,    0xAA);
                AsiaPciWrite16(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_PTR,   0x108);
                AsiaPciWrite8(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3, 0xAA); 
       }
    }else if(SbCfg->IOESataCfg == SATA_CFG_AHCI){    
       switch(SbCfg->IOEAHCIGen){
           case 1: 
                AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_CACHE_BIST_CTL,     0xF0, IOE_D15F0_GEN_1); 
                AsiaPciWrite16(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_PTR,   0x108);
                AsiaPciWrite8(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3, 0x00); 
                break;
           
           case 2: 
                AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_CACHE_BIST_CTL,     0xF0, IOE_D15F0_GEN_2); 
                AsiaPciWrite16(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_PTR,   0x108);
                AsiaPciWrite8(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3, 0xAA); 
                break;
           
           case 3: 
           default:         
                AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_CACHE_BIST_CTL,     0xF0, IOE_D15F0_GEN_3); 
                AsiaPciWrite16(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_PTR,   0x108);
                AsiaPciWrite8(CND003_SATA|CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3, 0xAA); 
       }         
    }

    if (SbCfg->IOESataCfg == SATA_CFG_AHCI){
        if (SbCfg->IOEAHCI_MSI == FALSE){      // Enable/Disable MSI
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS, 0x02, 0x02); 
        }else{
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS, 0x02, 0x00);
        }
            
        if (SbCfg->IOEAHCI_MSIX == FALSE){     // Enable/Disable MSIX
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_SPEED_STA_CTL, 0x40, 0x40);
        }else        {
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_SPEED_STA_CTL, 0x40, 0x00);
        }
        
        if(SbCfg->IOESataHpcpEn){
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x00); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x01);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x01); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x01);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x02); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x01);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x03); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x01);   
        }else{
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x00); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x00);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x01); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x00);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x02); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x00);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL, 0x0F, 0x03); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,     0x01, 0x00);   
        }
 
        if(SbCfg->IOESataALPMEn == FALSE|| SbCfg->CRBPlatformSelection == CRB_PLATFORM_MODE_SELECTION_DESKTOP){
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_GHC_CAP_OPTIONAL_REG_0,      CND003_D15F0_SUP_LKPWR, 0x00); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1, CND003_D15F0_SUP_PART,  0x00);    
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1, CND003_D15F0_SUP_SLUM,  0x00);
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,  CND003_D15F0_SUP_DEVSLP,0x00); 
        }else{
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_GHC_CAP_OPTIONAL_REG_0,      CND003_D15F0_SUP_LKPWR, CND003_D15F0_SUP_LKPWR); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1, CND003_D15F0_SUP_PART,  CND003_D15F0_SUP_PART);   
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1, CND003_D15F0_SUP_SLUM,  CND003_D15F0_SUP_SLUM); 
            AsiaPciModify8(CND003_SATA|CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS,  CND003_D15F0_SUP_DEVSLP,CND003_D15F0_SUP_DEVSLP); 
        }
        
        AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_SPEED_NEGOTIATION_CTL, 0x08, 0x08);
        
        AsiaPciModify8(CND003_SATA|CND003_D15F0_SATA_CMD_CTL_REG, 0x01, 0x00);
    }

    if(SbCfg->IOEFunctionLevelEnabled){
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_FUN_LEVEL_RESET_FLR_2), 0x03, 0x03);    
    }else{
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_FUN_LEVEL_RESET_FLR_2), 0x03, 0x00);     
    }

	//20180504 -Enable RX EIDLE signal filter function RxFF[7]
	AsiaPciModify8((CND003_SATA|CND003_D15F0_EPHY_DE_GLITCH_FUN_CTL), CND003_D15F0_RXEIDLE_FILTER_EN, CND003_D15F0_RXEIDLE_FILTER_EN); 

    AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_CTL_REG_5_Z1), 0x40, 0x40);

    AsiaPciModify8((CND003_SATA|CND003_D15F0_MISC_CTL_2), 0x10, 0x10); // Enable Rx3C
    
    AsiaPciModify8((CND003_SATA|CND003_D15F0_LEGACY_SATA_OOB_KICK_OFF_CTL), 0x0F, 0x0F); // Start OOB 
    
    return EFI_SUCCESS;
}

/**
   IOE SATA PEI Init function.

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
IOESataPeiInit(
    IN EFI_PEI_SERVICES      **PeiServices, 
    IN ASIA_SB_CONFIGURATION *SbCfg
)
{
    EFI_STATUS               Status;
    
    if(!IoeExist()){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [IOESataPeiInit()]\n"));
        return EFI_SUCCESS;
    }
    
    IoePeiTempAssignment(PeiServices);

    Status = IOESataExist_PEI(PeiServices);
    if (EFI_ERROR (Status)) {
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"[Lex]: NO SATA CONTROLLER FOUND AT D15F0!\n"));
        IoePeiClearTempAssignment(PeiServices);
        return EFI_SUCCESS;
    }

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Lex]: CND003 SATA PEI Init Start\n"));
    
    if(!SbCfg->IOESataEn){
        AsiaPciModify8((ASIA_PCI_ADDRESS(4, 0, 0, 0) | CND003_EPTRFC_D0F0_SM_DEV_ENABLE_2), BIT1, 0);
    }else{
        IOESataDump_PEI(PeiServices);
        IOESataInit(PeiServices, SbCfg);     
        IOESataDump_PEI(PeiServices);
    }
    
    IoePeiClearTempAssignment(PeiServices);
    
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Lex]: CND003 SATA PEI Init End\n"));
    return EFI_SUCCESS;
}

/**
   IOE SATA PEI Init function in S3 Resume phase.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return EFI_SUCCESS.

**/

EFI_STATUS
EFIAPI
IOESataPeiInitS3(
    IN EFI_PEI_SERVICES      **PeiServices, 
    IN ASIA_SB_CONFIGURATION *SbCfg
)
{
    EFI_STATUS               Status;

    if(!IoeExist()){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [IOESataPeiInit()]\n"));
        return EFI_SUCCESS;
    }
    
    IoePeiTempAssignment(PeiServices);

    Status = IOESataExist_PEI(PeiServices);
    if (EFI_ERROR (Status)) {
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"[Lex]: NO SATA CONTROLLER FOUND AT D15F0!\n"));
        IoePeiClearTempAssignment(PeiServices);
        return EFI_SUCCESS;
    }

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Lex]: CND003 SATA S3 PEI Init Start\n"));
    
    if(!SbCfg->IOESataEn){
        AsiaPciModify8((ASIA_PCI_ADDRESS(4, 0, 0, 0) | CND003_EPTRFC_D0F0_SM_DEV_ENABLE_2), BIT1, 0);
    }else{
        IOESataDump_PEI(PeiServices);
        AsiaPciModify8((CND003_SATA|CND003_D15F0_SATA_CHN_ENABLE), CND003_D15F0_SA_HBA_RST, CND003_D15F0_SA_HBA_RST);
        Delay(100);
        IOESataInit(PeiServices, SbCfg);     
        IOESataDump_PEI(PeiServices);
    }
    
    IoePeiClearTempAssignment(PeiServices);
    
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Lex]: CND003 SATA S3 PEI Init End\n"));
    return EFI_SUCCESS;
}

