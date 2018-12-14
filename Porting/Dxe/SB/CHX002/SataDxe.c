/** @file
   ZX-E(CHX002) Asia SbDxe library functions : SataDxe.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "EfiCommon.h"
#include "AsiaSbDxe.h"
#include "AsiaIoSaveLib.h"
#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include EFI_GUID_DEFINITION(Hob)
#include "EfiDriverLib.h"
#include "EfiHobLib.h"
#include "EfiBootScript.h"
#include "EfiScriptLib.h"
#include "AsiaCommon.h"
#include "SataDxe.h" 

#define MAX_PCI_BUSS                40
#define SPEValue_MANUAL             0
#define SPEValue_S                  1
#define SPEValue_SP                 2
#define SPEValue_SPE                3

#define SATASPEValue_S              0
#define SATASPEValue_SP             1
#define SATASPEValue_SPE            2


#define  SATA_PORT   2


STATIC ASIA_IO_TABLE_6408_REV Sata_Performance_TBL[]={
	{0x00, 0xFF, (CHX002_SATA|D15F0_MISC_CTL_1),						  0x80, 0x80}, //Rx44
    {0x00, 0xFF, (CHX002_SATA|D15F0_MISC_CTL_2),                          0x60, 0x60}, //Rx45
    {0x00, 0xFF, (CHX002_SATA|D15F0_MISC_CTL_3),                          0x34, 0x34}, //Rx46
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_DMAC_ECLK150_GATING),            0x03, 0x03}, //Rx48
    //{0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PERFORMANCE_CTL),                0x01, 0x00}, //Rx52 same with default value
    //{0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CMD_CTL_REG),                    0x20, 0x20}, //Rx53 same with default value
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_TRANSPORT_MISC_CTL),             0x30, 0x30}, //Rx81
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_TXCDC_CTL),                      0x02, 0x02}, //Rx8D
    {0x00, 0xFF, (CHX002_SATA|D15F0_MISC_REGS_382_RX49),                  0xC0, 0xC0}, //RxD0
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_TRANSPORT_MISC_CTL_382_RX52),    0x40, 0x40}, //RxD3
    
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00}, // Rx42
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG),         0x01, 0x01}, // Rx49
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_CTL_REG_1),                       0x01, 0x01}, // Rx5C
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_PM_MODE),                    0x1F, 0x0F}, // Rx84
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_DYNAMIC_CLK_CTL_REG_2),          0x0F, 0x0F}, // RxDD 

    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01}, // Rx42
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG),         0x01, 0x01}, // Rx49
    {0x00, 0xFF, (CHX002_SATA|D15F0_PHY_CTL_REG_1),                       0x01, 0x01}, // Rx5C
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_PM_MODE),                    0x1F, 0x0F}, // Rx84
    {0x00, 0xFF, (CHX002_SATA|D15F0_AHCI_DYNAMIC_CLK_CTL_REG_2),          0x0F, 0x0F}, // RxDD 
    
   
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};

    
STATIC ASIA_IO_TABLE_6408_REV Sata_Energy_TBL[]={
	
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1),      0x80, 0x80}, //Rx4A
	{0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1),      0x03, 0x03}, //Rx4A
	{0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1),      0x80, 0x00}, //Rx4A
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_CTL_REG_4),                      0x03, 0x03}, //Rx63

    
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_PM_MODE),                    0x60, 0x40}, // Rx84


    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01},
    {0x00, 0xFF, (CHX002_SATA|D15F0_SATA_PHY_PM_MODE),                    0x60, 0x40}, // Rx84 

    
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};


STATIC ASIA_IO_TABLE_6408_REV Sata_Energy_TBL_IDE[]= {
    {0x00, 0xFF, (CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x00},
    {0x00, 0xFF, (CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),    0x0C, 0x00},   
    
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
SataDumpMmioPreboot(
  IN  ASIA_SB_CONFIGURATION    *SbCfg
  )
{
    UINT8        i;
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;
    UINT8        Value;
    UINT32       BaseAddress;
    
    if(SbCfg->SataCfg==SATA_CFG_AHCI){
        DEBUG((EFI_D_ERROR, "[D15F0]: SATA MMIO\n"));
        DEBUG((EFI_D_ERROR, "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
        DEBUG((EFI_D_ERROR, "--------+-----------------------------------------------\n"));
        
        Value = AsiaPciRead8(CHX002_SATA|0x04);
        AsiaPciWrite8((CHX002_SATA|0x04),0x7);
        
        BaseAddress = AsiaPciRead32(CHX002_SATA|0x24);
        for(Index1=0;Index1<0x10;Index1++){
            DEBUG((EFI_D_ERROR, "%08x|", BaseAddress+Index1*16));
            for(Index2=0;Index2<0x10;Index2++){
                Data = AsiaMemoryRead8(BaseAddress+(Index1*16+Index2));
                DEBUG((EFI_D_ERROR, "%02x ", Data));
                if(Index2==0x0F){
                    DEBUG((EFI_D_ERROR, "\n"));
                }
            }
        }
        DEBUG((EFI_D_ERROR, "--------------------------------------------------------\n"));
        
        for(i=0;i<SATA_PORT;i++){
            for(Index1=0;Index1<0x05;Index1++){
                DEBUG((EFI_D_ERROR, "%08x|", BaseAddress+0x100+0x80*i+Index1*16));
                for(Index2=0;Index2<0x10;Index2++){
                    Data = AsiaMemoryRead8(BaseAddress+0x100+0x80*i+(Index1*16+Index2));
                    DEBUG((EFI_D_ERROR, "%02x ", Data));
                    if(Index2==0x0F){
                        DEBUG((EFI_D_ERROR, "\n"));
                    }
                }
            }
            DEBUG((EFI_D_ERROR, "--------------------------------------------------------\n"));
        }
        
        AsiaPciWrite8((CHX002_SATA|0x04),Value);
    }
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
SataDumpMmioDxe(
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
        DEBUG((EFI_D_ERROR, "[D15F0]: SATA MMIO\n"));
        DEBUG((EFI_D_ERROR, "         00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
        DEBUG((EFI_D_ERROR, "--------+-----------------------------------------------\n"));
        
        Value = AsiaPciRead8(CHX002_SATA|0x04);
        AsiaPciWrite8((CHX002_SATA|0x04),0x7);
        
        BaseAddress = AsiaPciRead32(CHX002_SATA|0x24);
        AsiaPciWrite32((CHX002_SATA|0x24),(0xD0200000|(BaseAddress&0xFF)));
        BaseAddress02 = AsiaPciRead32(CHX002_SATA|0x24);
        
        for(Index1=0;Index1<0x10;Index1++)
        {
            DEBUG((EFI_D_ERROR, "%08x|", BaseAddress02+Index1*16));
            for(Index2=0;Index2<0x10;Index2++){
                Data = AsiaMemoryRead8(BaseAddress02+(Index1*16+Index2));
                DEBUG((EFI_D_ERROR, "%02x ", Data));
                if(Index2==0x0F){
                    DEBUG((EFI_D_ERROR, "\n"));
                }
            }
        }
        DEBUG((EFI_D_ERROR, "--------------------------------------------------------\n"));
        
        for(i=0;i<SATA_PORT;i++){
            for(Index1=0;Index1<0x05;Index1++){
                DEBUG((EFI_D_ERROR, "%08x|", BaseAddress02+0x100+0x80*i+Index1*16));
                for(Index2=0;Index2<0x10;Index2++){
                    Data = AsiaMemoryRead8(BaseAddress02+0x100+0x80*i+(Index1*16+Index2));
                    DEBUG((EFI_D_ERROR, "%02x ", Data));
                    if(Index2==0x0F){
                        DEBUG((EFI_D_ERROR, "\n"));
                    }
                }
            }
            DEBUG((EFI_D_ERROR, "--------------------------------------------------------\n"));
        }

        AsiaPciWrite32((CHX002_SATA|0x24),BaseAddress);
        AsiaPciWrite8((CHX002_SATA|0x04),Value);
    }
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
SataDumpConfig(
  IN  ASIA_SB_CONFIGURATION    *SbCfg
  )
{
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;

    DEBUG((EFI_D_ERROR, "[D15F0]: SATA\n"));
    DEBUG((EFI_D_ERROR, "   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
    DEBUG((EFI_D_ERROR, "--+-----------------------------------------------\n"));
    for(Index1=0;Index1<0x10;Index1++){
        DEBUG((EFI_D_ERROR, "%02x|", Index1*16));
        for(Index2=0;Index2<0x10;Index2++){
            Data = AsiaPciRead8(CHX002_SATA|(Index1*16+Index2));
            DEBUG((EFI_D_ERROR, "%02x ", Data));
            if(Index2==0x0F){
                DEBUG((EFI_D_ERROR, "\n"));
            }
        }
    }
    DEBUG((EFI_D_ERROR, "--------------------------------------------------\n"));
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
SataDxe(
  ASIA_SB_CONFIGURATION* SbCfg
  )
{
    UINT8         SataSpe;
    UINT16        VendorID;
    UINT16        DeviceID;

    VendorID = AsiaPciRead16(CHX002_SATA|D15F0_VID);
    DeviceID = AsiaPciRead16(CHX002_SATA|D15F0_DID);
    if((VendorID!=0x1106 && VendorID!=0x1d17) || (DeviceID!=0x9002 && DeviceID!=0x9003 && DeviceID!=0x9083)){
        return EFI_SUCCESS;
    }

    SataDumpConfig(SbCfg);
    
    // Process IOE SPE tables
    switch(SbCfg->SBSPEValue){
        case CHIP_SPE_VALUE_MANUAL:
            SataSpe = SbCfg->SATASPEValue;
            break;
        case CHIP_SPE_VALUE_STABLE:
            SataSpe = DEVICE_SPE_VALUE_STABLE;
            break;
        case CHIP_SPE_VALUE_PERFORMANCE:
            SataSpe = DEVICE_SPE_VALUE_PERFORMANCE;
            break;
        case CHIP_SPE_VALUE_ENERGY:
            SataSpe = DEVICE_SPE_VALUE_ENERGY;
            break;
        default:
            SataSpe = DEVICE_SPE_VALUE_STABLE;
    }

    if(SataSpe >= DEVICE_SPE_VALUE_PERFORMANCE){
        PROCESS_SB_R6408M_TABLE_SAVE(Sata_Performance_TBL, sizeof(Sata_Performance_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(SataSpe == DEVICE_SPE_VALUE_ENERGY){
            PROCESS_SB_R6408M_TABLE_SAVE(Sata_Energy_TBL, sizeof(Sata_Energy_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
            if (SbCfg->SataCfg == SATA_CFG_IDE){
                PROCESS_SB_R6408M_TABLE_SAVE(Sata_Energy_TBL_IDE, sizeof(Sata_Energy_TBL_IDE)/sizeof(ASIA_IO_TABLE_6408_REV));  
            }
        }
    }

    SataDumpConfig(SbCfg);
    
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
SataPreBoot(
  IN ASIA_SB_CONFIGURATION* SbCfg
  )
{ 
    UINT16        VendorID;
    UINT16        DeviceID;
    
    VendorID = AsiaPciRead16(CHX002_SATA|D15F0_VID);
    DeviceID = AsiaPciRead16(CHX002_SATA|D15F0_DID);
    if((VendorID!=0x1106 && VendorID!=0x1d17) || (DeviceID!=0x9002 && DeviceID!=0x9003 && DeviceID!=0x9083)){
        return EFI_SUCCESS;
    }
   
    SataDumpConfig(SbCfg);

    if(SbCfg->SataCfg == SATA_CFG_IDE){
	    if(SbCfg->CRBPlatformSelection == CRB_PLATFORM_MODE_SELECTION_DESKTOP)
        {
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x80);
			
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x01, 0x00); 
            AsiaPciModifySave8((CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),  0x0C, 0x0C); 
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00); 
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_PM_MODE), 0x7F, 0x70);
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_CTL_REG_4),   0x03, 0x00); 

            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x02, 0x00); 
            AsiaPciModifySave8((CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x0C);  
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_PM_MODE), 0x7F, 0x70);
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_CTL_REG_4),   0x03, 0x00); 

			AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x00);

        }else{
        if((SbCfg->SBSPEValue != SPEValue_SPE)&&((SbCfg->SBSPEValue != SPEValue_MANUAL) || (SbCfg->SATASPEValue != SATASPEValue_SPE))){
            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x80); 
            
            if(SbCfg->IDECapSelect == IDE_CAP_LINKPM){
                AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x01, 0x01);
                AsiaPciModifySave8((CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00); 

                AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x02, 0x02); 
                AsiaPciModifySave8((CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00);

                if(SbCfg->IDEHIPMEn){
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00);    
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_PM_MODE), 0x7F, 0x05);  
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_CTL_REG_4), 0x03, 0x03); 
                
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_PM_MODE), 0x7F, 0x05);    
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_CTL_REG_4), 0x03, 0x03);                             
                }else{
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00); 
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_PM_MODE), 0x60, 0x60);
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
                    AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_PM_MODE), 0x60, 0x60);
                }
            }else if(SbCfg->IDECapSelect == IDE_CAP_HOTPLUG){
                AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x01, 0x00); 
                AsiaPciModifySave8((CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x0C); 

                AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x02, 0x00); 
                AsiaPciModifySave8((CHX002_SATA|D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x0C);          
            }

            AsiaPciModifySave8((CHX002_SATA|D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x00); 
        }
    }
   }
    SataDumpConfig(SbCfg);
    
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
SataInitDxe(
  ASIA_SB_CONFIGURATION* SbCfg
  )
{
    DEBUG((EFI_D_ERROR, "[SATA-DXE]: SATA DXE Init Start\n"));
    
    if(SbCfg->SataEn){
        SataDxe(SbCfg); 
    }
     
    DEBUG((EFI_D_ERROR, "[SATA-DXE]: SATA DXE Init End\n"));
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
SataInitPreBoot(
  ASIA_SB_CONFIGURATION* SbCfg
  )
{
    DEBUG((EFI_D_ERROR, "[SATA-Preboot]: SATA PreBoot Init Start\n"));
    
    if(SbCfg->SataEn){
        SataPreBoot(SbCfg); 
    }

    DEBUG((EFI_D_ERROR, "[SATA-Preboot]: SATA PreBoot Init End\n"));
    return EFI_SUCCESS;
}
