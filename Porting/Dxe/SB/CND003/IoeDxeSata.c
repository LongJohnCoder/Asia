/** @file
   ZX-E(CHX002) Asia SbDxe library functions : IoeDxeSata.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************
#include "EfiCommon.h"
//#include "AsiaSbDxe.h"
#include "AsiaIoSaveLib.h"
#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include "EfiDriverLib.h"
#include EFI_GUID_DEFINITION(Hob)
#include "EfiHobLib.h"

#include "EfiBootScript.h"
#include "EfiScriptLib.h"

//#include "Protocol\AsiaSbProtocol\AsiaSbProtocol.h"
//#include "HdAc.h"
#include "AsiaCommon.h" //define ASIA_XXX_CFG_HOB_GUID

#include "IoeDxeSata.h" 

#define MAX_PCI_BUSS                   40
#define IOESPEValue_MANUAL             0
#define IOESPEValue_S                  1
#define IOESPEValue_PS                 2
#define IOESPEValue_EPS                3

#define IOESATASPEValue_S              0
#define IOESATASPEValue_PS             1
#define IOESATASPEValue_EPS            2


STATIC ASIA_IO_TABLE_6408_REV IOESata_Performance_TBL[]={
    {0x00,  0xFF,   (CND003_SATA|0x81), 0xf0,   0xf0},

    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x00},  //Port0
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x1f,   0x0f},
    
    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x01},  //Port1
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x1f,   0x0f},
    
    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x02},  //Port2
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x1f,   0x0f},
    
    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x03},  //Port3
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x1f,   0x0f},

    {0x00,  0xFF,   (CND003_SATA|0x8D), 0x02,   0x02},

    {0x00,  0xFF,   (CND003_SATA|0xD3), 0x40,   0x40},

    {0xFF,  0x00,   0x00,   0x00,   0x00}
};
    
STATIC ASIA_IO_TABLE_6408_REV IOESata_Energy_TBL[]={
    {0x00,  0xFF,   (CND003_SATA|0x44), 0xc0,   0xc0},
    {0x00,  0xFF,   (CND003_SATA|0x45), 0x60,   0x60},
    {0x00,  0xFF,   (CND003_SATA|0x46), 0xf4,   0xf4},

    {0x00,  0xFF,   (CND003_SATA|0x48), 0x0f,   0x0f},

    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x00},  //Port0
    {0x00,  0xFF,   (CND003_SATA|0x49), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x5c), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x7f,   0x4f},
    {0x00,  0xFF,   (CND003_SATA|0xDD), 0x0f,   0x07}, //20171226-patch for win10 reboot BSOD 7B
    
    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x01},  //Port1
    {0x00,  0xFF,   (CND003_SATA|0x49), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x5c), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x7f,   0x4f},
    {0x00,  0xFF,   (CND003_SATA|0xDD), 0x0f,   0x07}, //20171226-patch for win10 reboot BSOD 7B
    
    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x02},  //Port2
    {0x00,  0xFF,   (CND003_SATA|0x49), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x5c), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x7f,   0x4f},
    {0x00,  0xFF,   (CND003_SATA|0xDD), 0x0f,   0x07}, //20171226-patch for win10 reboot BSOD 7B
    
    {0x00,  0xFF,   (CND003_SATA|0x42), 0x0f,   0x03},  //Port3
    {0x00,  0xFF,   (CND003_SATA|0x49), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x5c), 0x01,   0x01},
    {0x00,  0xFF,   (CND003_SATA|0x84), 0x7f,   0x4f},
    {0x00,  0xFF,   (CND003_SATA|0xDD), 0x0f,   0x07}, //20171226-patch for win10 reboot BSOD 7B

    {0x00,  0xFF,   (CND003_SATA|0x4A), 0xf0,   0xf0},
    {0x00,  0xFF,   (CND003_SATA|0x63), 0x03,   0x03},
    {0x00,  0xFF,   (CND003_SATA|0x8D), 0x02,   0x02},
    {0x00,  0xFF,   (CND003_SATA|0xd0), 0xc0,   0xc0},
    
    {0xFF,  0x00,   0x00,   0x00,   0x00}
};

STATIC ASIA_IO_TABLE_6408_REV IOESata_Energy_TBL_IDE[]= {
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x00},
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),    0x0C, 0x00},
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00},
    {0x00, 0xFF, (CND003_SATA|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),  0x0C, 0x00},
    
    {0xFF, 0x00, 0x00, 0x00, 0x00}
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IOESataDump_DXE()
{
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;

    DEBUG((EFI_D_ERROR, "DXE Dump CND003 D15F0:\n"));
    DEBUG((EFI_D_ERROR, "   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
    DEBUG((EFI_D_ERROR, "--+-----------------------------------------------\n"));
    for(Index1=0;Index1<0x10;Index1++){
        DEBUG((EFI_D_ERROR, "%02x|", Index1*16));
        for(Index2=0;Index2<0x10;Index2++){
            Data = AsiaPciRead8(CND003_SATA|(Index1*16+Index2));;
            DEBUG((EFI_D_ERROR, "%02x ", Data));
            if(Index2==0x0F){
                DEBUG((EFI_D_ERROR, "\n"));
            }
        }
        if((Index1%0x10)==0x0F){
            DEBUG((EFI_D_ERROR, "--------------------------------------------------\n"));
        }
    }
    DEBUG((EFI_D_ERROR, "\n")); 
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IOESataDump_Preboot(
    IN UINT8      SataBusNum
)
{
    UINT8        Index1;
    UINT8        Index2;
    UINT8        Data;
    UINT64       CND003_SATA_Preboot;

    CND003_SATA_Preboot = ASIA_PCI_ADDRESS(SataBusNum, CND003_SATA_DEV, 0, 0);
    DEBUG((EFI_D_ERROR, "PreBoot Dump CND003 D15F0:\n"));
    DEBUG((EFI_D_ERROR, "   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
    DEBUG((EFI_D_ERROR, "--+-----------------------------------------------\n"));
    for(Index1=0;Index1<0x10;Index1++){
        DEBUG((EFI_D_ERROR, "%02x|", Index1*16));
        for(Index2=0;Index2<0x10;Index2++){
            Data = AsiaPciRead8(CND003_SATA_Preboot|(Index1*16+Index2));;
            DEBUG((EFI_D_ERROR, "%02x ", Data));
            if(Index2==0x0F){
                DEBUG((EFI_D_ERROR, "\n"));
            }
        }
        if((Index1%0x10)==0x0F){
            DEBUG((EFI_D_ERROR, "--------------------------------------------------\n"));
        }
    }
    DEBUG((EFI_D_ERROR, "\n")); 
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
IOESataExist_DXE()
{
    UINT16        VendorID;
    UINT16        DeviceID;
    
    DEBUG((EFI_D_ERROR,"[Lex]: CHECK SATA CONTROLLER EXIST OR NOT\n"));
    VendorID = AsiaPciRead16(CND003_SATA|0x0);
    DeviceID = AsiaPciRead16(CND003_SATA|0x2);
    if((VendorID==0x1106 || VendorID==0x1d17) && (DeviceID==0x9002 || DeviceID==0x9083)){
        return EFI_SUCCESS;
    }
    return EFI_NOT_FOUND;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

UINT8
EFIAPI
IOESataScanPciBus()
{
    UINT8         PciBusNum;
    UINT16        VendorID;
    UINT16        DeviceID;

    for (PciBusNum = 1; PciBusNum < MAX_PCI_BUSS; PciBusNum++) {
        VendorID = AsiaPciRead16(ASIA_PCI_ADDRESS(PciBusNum, CND003_SATA_DEV, 0, 0)|0x0);
        DeviceID = AsiaPciRead16(ASIA_PCI_ADDRESS(PciBusNum, CND003_SATA_DEV, 0, 0)|0x2);
        if((VendorID==0x1106 || VendorID==0x1d17) && (DeviceID==0x9002 || DeviceID==0x9083)){
            return PciBusNum;
        }
    }
    return 0;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
IOESataSpeInit(
    IN UINT8   IOESataSpe,
    IN UINT8   IOESataCfg
)
{   
    if(IOESataSpe >= DEVICE_SPE_VALUE_PERFORMANCE){
        IOE_PROCESS_SB_R6408M_TABLE_SAVE(IOESata_Performance_TBL, sizeof(IOESata_Performance_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(IOESataSpe == DEVICE_SPE_VALUE_ENERGY){
            IOE_PROCESS_SB_R6408M_TABLE_SAVE(IOESata_Energy_TBL, sizeof(IOESata_Energy_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
            if (IOESataCfg == SATA_CFG_IDE){
                IOE_PROCESS_SB_R6408M_TABLE_SAVE(IOESata_Energy_TBL_IDE, sizeof(IOESata_Energy_TBL_IDE)/sizeof(ASIA_IO_TABLE_6408_REV));    
            }
        }
    }
    
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
IOESataDxeInit(
    ASIA_SB_CONFIGURATION* SbCfg
)
{
    EFI_STATUS   Status;
    UINT8        IOESataSpe;
   
    if(!IoeExist()){
        DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [IOESataDxeInit()]\n"));
        return EFI_SUCCESS;
    }
    
    IoeDxeTempAssignment();

    Status = IOESataExist_DXE();
    if (EFI_ERROR (Status)) {
        DEBUG((EFI_D_ERROR,"[Lex]: NO SATA CONTROLLER FOUND AT D15F0!\n"));
        IoeDxeClearTempAssignment();
        return EFI_SUCCESS;
    }

    DEBUG((EFI_D_ERROR, "[Lex]: CND003 SATA DXE Init Start\n"));
    
    // Process IOE SPE tables
    switch(SbCfg->IOESPEValue){
        case CHIP_SPE_VALUE_MANUAL:
            IOESataSpe = SbCfg->IOESATASPEValue;
            break;
        case CHIP_SPE_VALUE_STABLE:
            IOESataSpe = DEVICE_SPE_VALUE_STABLE;
            break;
        case CHIP_SPE_VALUE_PERFORMANCE:
            IOESataSpe = DEVICE_SPE_VALUE_PERFORMANCE;
            break;
        case CHIP_SPE_VALUE_ENERGY:
            IOESataSpe = DEVICE_SPE_VALUE_ENERGY;
            break;
        default:
            IOESataSpe = DEVICE_SPE_VALUE_STABLE;
    }
      
    IOESataDump_DXE();
    
    IOESataSpeInit(IOESataSpe,SbCfg->IOESataCfg); 
    
    IOESataDump_DXE();
        
    DEBUG((EFI_D_ERROR, "[Lex]: CND003 SATA DXE Init End\n"));
    
    IoeDxeClearTempAssignment();
    
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
IOESataPreBootInit(
    IN ASIA_SB_CONFIGURATION* SbCfg,
    IN UINT8                  SataBusNum
)
{   
    UINT64        CND003_SATA_Preboot;

    CND003_SATA_Preboot = ASIA_PCI_ADDRESS(SataBusNum, CND003_SATA_DEV, 0, 0);

    if(SbCfg->IOESataCfg == SATA_CFG_IDE)
    {
              if(SbCfg->CRBPlatformSelection == CRB_PLATFORM_MODE_SELECTION_DESKTOP)
        {
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x10, 0x00); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),  0x0C, 0x0C); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x70);
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x00); 

            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x20, 0x00); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x0C);  
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x70);
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x00); 

            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x40, 0x00); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),0x0C, 0x0C); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x02); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x70);
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x00); 

            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x00);  
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x0C); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x03); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x70); 
            AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x00); 
        }else{  
        if((SbCfg->IOESPEValue != IOESPEValue_EPS)&&((SbCfg->IOESPEValue != IOESPEValue_MANUAL) || (SbCfg->IOESATASPEValue != IOESATASPEValue_EPS)))
        {
            if(SbCfg->IOESataCapSelect == IOE_SATA_CAP_LINKPM)
            {
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x10, 0x10);
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00); 

                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x20, 0x20); 
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00);

                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x40, 0x40);        
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00); 

                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x80); 
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x00);

                if(SbCfg->IOESataHIPMEn)
                {
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00);    
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x05);  
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x03); 
                
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x05);    
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x03);  

                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x02);    
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x05);   
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x03); 
                
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x03); 
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x7F, 0x05);    
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_CTL_REG_4),   0x03, 0x03);                             
                }else{
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x00); 
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x60, 0x60);
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x01); 
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x60, 0x60);
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x02); 
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x60, 0x60);
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL), 0x0F, 0x03); 
                    AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_PM_MODE), 0x60, 0x60); 
                }
            }else if(SbCfg->IOESataCapSelect == IOE_SATA_CAP_HOTPLUG){
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x10, 0x00); 
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),   0x0C, 0x0C); 

                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x20, 0x00); 
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),    0x0C, 0x0C);  

                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x40, 0x00); 
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION), 0x0C, 0x0C); 

                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1), 0x80, 0x00);  
                AsiaPciModifySave8((CND003_SATA_Preboot|CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION),  0x0C, 0x0C);          
            }
        }
   
    }
  }
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
IOESataDxePreBootInit(
    ASIA_SB_CONFIGURATION* SbCfg
)
{
    UINT8        SataBusNum = 0;

    SataBusNum = IOESataScanPciBus();
    if (SataBusNum == 0) {
        DEBUG((EFI_D_ERROR,"[Lex]: NO SATA CONTROLLER FOUND AT BUSX D15F0!\n"));
        return EFI_SUCCESS;
    }

    DEBUG((EFI_D_ERROR, "[Lex]: CND003 SATA(Bus 0x%x D15F0) PreBoot Init Start\n",SataBusNum));
        
    IOESataDump_Preboot(SataBusNum);
    
    IOESataPreBootInit(SbCfg,SataBusNum); 
    
    IOESataDump_Preboot(SataBusNum);
    
    DEBUG((EFI_D_ERROR, "[Lex]: CND003 SATA PreBoot Init End\n"));
      
    return EFI_SUCCESS;
}

