/** @file
   ZX-E(CHX002) Asia SbDxe library functions : AsiaSbDxeInit.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
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
#include "EfiDriverLib.h"
#include EFI_GUID_DEFINITION(Hob)
#include "EfiHobLib.h"

#include "EfiBootScript.h"
#include "EfiScriptLib.h"

#include "Protocol\AsiaSbProtocol\AsiaSbProtocol.h"
#include "HdAc.h"
#include "AsiaCommon.h"
#include "AsiaPlatform.h"
#include "SataDxe.h"
#include "UsbDxe.h"
#ifdef IOE_EXIST
#include "..\CND003\IoeDxeUsb.h"
#include "..\CND003\IoeDxeSata.h"
#include "..\CND003\IoeDxeGnic.h"
#endif

//ASIA_SB_CONFIGURATION gDefaultSbCfg = ASIA_SB_DEFAULT_CONFIGURATION;

STATIC ASIA_IO_TABLE_6408_REV SB_Safe_TBL[]= {
            //  mVer MVer Reg Offset          Mask  Value
            {0xFF, 0x00, 0x00,                       0x00,    0x00}
        };

STATIC ASIA_IO_TABLE_6408_REV BusCtrl_Performance_TBL[]= {
            //  mVer MVer Reg Offset          Mask  Value
            {0x00, 0xFF, (CHX002_BUSC|D17F0_DMA_BANDWIDTH_CTL), 0xFF,   0xFF},
//			{0x00, 0xFF, (CHX002_BUSC|D17F0_SM_DEBUG_CTL), 0x04,	0x04}, //D17F0 RxB7[2]=1:TMRC Dynamic clock enable           
			{0x00, 0xFF, (CHX002_BUSC|D17F0_MISC_CTL_Z1), 0x10,	0x10}, //D17F0 Rx5B[4]=1           
			{0xFF, 0x00, 0x00,                       0x00,    0x00}
        };

STATIC ASIA_IO_TABLE_6408_REV Pmu_Performance_TBL[]= {
            //  mVer MVer Reg Offset          Mask  Value
            {0xFF, 0x00, 0x00,                       0x00,    0x00}
        };

STATIC ASIA_IO_TABLE_6408_REV Pcca_Performance_TBL[]= {
            //mVer MVer Reg Offset                           Mask  Value
            {0x00, 0xFF, (CHX002_PCCA|D17F7_CPU_TO_PCI_FLOW_CTL_1),     D17F7_RC2PWB|D17F7_RDLYT1,   D17F7_RC2PWB|D17F7_RDLYT1 },
            {0xFF, 0x00, 0x00,           0x00,    0x00}
        };

////
STATIC ASIA_IO_TABLE_6408_REV Hdac_Performance_TBL[]= {
            //  mVer MVer Reg Offset          Mask  Value
            {0x00, 0xFF, (CHX002_HDAC|D20F0_HDAC_CTL), 0x01, 0x01},// Enable HDAC dynamic stop clock.
            {0x00, 0xFF, (CHX002_HDAC|D20F0_DEBUG_SIGNAL_SEL), 0x20, 0x20},
            {0xFF, 0x00, 0x00,                         0x00, 0x00}
        };

STATIC ASIA_IO_TABLE_6408_REV BusCtrl_Energy_TBL[]= {
            //mVer MVer   Reg   |  Offset         Mask  Value
            { 0xFF, 0x00, 0x00,                          0x00,   0x00}
        };

STATIC ASIA_IO_TABLE_6408_REV Pmu_Energy_TBL[]= {
            //mVer MVer   Reg   |  Offset         Mask  Value
            { 0xFF, 0x00, 0x00,                       0x00,    0x00}
        };

STATIC ASIA_IO_TABLE_6408_REV Pcca_Energy_TBL[]= {
            //  mVer MVer Reg Offset          Mask    Value
            {0xFF, 0x00, 0x00,           0x00,    0x00}
        };

/////
STATIC ASIA_IO_TABLE_6408_REV Hdac_Energy_TBL[]= {
            //  mVer MVer Reg Offset          Mask  Value
            {0xFF, 0x00, 0x00,                         0x00, 0x00}
        };

//STATIC ASIA_IO_TABLE_6408_REV CardReader_Energy_TBL[]= {
            //  mVer MVer Reg Offset          Mask  Value
//            {0xFF, 0x00, 0x00,                       0x00,    0x00}
//        };

STATIC ASIA_PCI_DEV_ID PciDevTbl[]=
{
	//{Vendor ID, Device ID}
	{0x0E11, 0xF003},         //Meat Grinder
};

ASIA_VID_DID_RID_LOCK SbVidDidLockTbl[]=
{
    //  Device        Function			VL_Reg  DL_Reg, VL_Bit, DL_Bit
  	{CHX002_UART_DEV, CHX002_UART0_FUN, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, BIT1, BIT3},
	{CHX002_UART_DEV, CHX002_UART1_FUN, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, BIT1, BIT3},
	//{CHX002_UART_DEV, CHX002_UART2_FUN, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, BIT1, BIT3},
	//{CHX002_UART_DEV, CHX002_UART3_FUN,	D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1 + 2, BIT1, BIT3},
	{CHX002_ESPI_DEV, CHX002_ESPI_FUN,	D11F0_BACK_DOOR_ENABLE,	D11F0_BACK_DOOR_ENABLE,	D11F0_SW_VID_LOCK,	D11F0_SW_DID_RID_LOCK},
  	{CHX002_BUSC_DEV, CHX002_BUSC_FUN,	D17F0_SM_DEBUG_CTL,			D17F0_SM_DEBUG_CTL,			D17F0_VID_LOCK,			D17F0_DID_RID_LOCK},
   	{CHX002_BUSC_DEV, CHX002_PCCA_FUN,	D17F7_PCI_BUS_CTL,			D17F7_PCI_BUS_CTL,			D17F7_VID_DID_LOCK,		D17F7_RDIDLOCK_BIT},
    //D14F0 UHCI
    {CHX002_UHCI0_DEV, 0,	            D14F0_FLR_AND_VID_OPTIONAL_REG,			D14F0_CTL_REG_8,			D14F0_VID_OPTIONAL_SET,		D14F0_REVID_BACKEN},
    //D14F7 EHCI
    {CHX002_EHCI0_DEV, 7,	            D14F7_FLR_AND_VID_OPTIONAL_REG,			D14F7_REV_ID_OPTIONAL_CTL,			D14F7_VID_OPTIONAL,		D14F7_BACK_EN},
    //D16F0 UHCI
    {CHX002_UHCI1_DEV, 0,	            D16F0F1_FLR_AND_VID_OPTIONAL_REG,			D16F0F1_CTL_REG_8,			D16F0F1_VID_OPTIONAL_SET,		D16F0F1_REVID_BACKEN},
    //D16F1 UHCI
    {CHX002_UHCI1_DEV, 1,	            D16F0F1_FLR_AND_VID_OPTIONAL_REG,			D16F0F1_CTL_REG_8,			D16F0F1_VID_OPTIONAL_SET,		D16F0F1_REVID_BACKEN},
    //D16F7 EHCI
    {CHX002_EHCI1_DEV, 7,	            D16F7_FLR_AND_VID_OPTIONAL_REG,			D16F7_REV_ID_OPTIONAL_CTL,			D16F7_VID_OPTIONAL,		D16F7_BACK_EN},
    //D18F0 XHCI
    {CHX002_XHCI_DEV, 0,	            D18F0_XHCIOPTION_BITS_RX45_XHCOPTRX45,			D18F0_XHCIOPTION_BITS_RX45_XHCOPTRX45,			D18F0_VID_LOCK,		D18F0_DID_RID_LOCK},

  	{CHX002_HDAC_DEV, CHX002_HDAC_FUN,	D20F0_BACK_DOOR_ENABLE,		D20F0_DEBUG_SIGNAL_SEL,		D20F0_CFGRX40H_7,		D20F0_SW_DID_RID_LOCK}
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS GetAsiaSbCfgFromHob(
    OUT VOID** SbCfg
)
{
    EFI_STATUS Status;
    EFI_HOB_GENERIC_HEADER *HobList;
    EFI_GUID EfiHobListGuid = EFI_HOB_LIST_GUID;
    EFI_GUID SbCfgHobGuid = ASIA_SB_CFG_HOB_GUID;
    VOID* pSbCfg = NULL;

    Status = EfiLibGetSystemConfigurationTable(&EfiHobListGuid, &HobList);
    if(!EFI_ERROR(Status))
        Status = GetNextGuidHob(&HobList, &SbCfgHobGuid, &pSbCfg, NULL);

    if(EFI_ERROR(Status))
    {
        //gBS->AllocatePool(EfiBootServicesData, sizeof(ASIA_SB_CONFIGURATION), &pSbCfg);
        //gBS->CopyMem(pSbCfg, &gDefaultSbCfg, sizeof(ASIA_SB_CONFIGURATION));
        DEBUG((EFI_D_ERROR, "\n\n ASIA_SB_CFG HOB lost, Bug! Bug! Bug!\n\n"));	
        ASSERT(FALSE); // should not come here. TGR-20180509001
    }

    *SbCfg = pSbCfg;
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
SbPolicyInit (
    IN EFI_ASIA_SB_PROTOCOL *AsiaSb
)
{
    ASIA_SB_CONFIGURATION* SbCfg = AsiaSb->SbCfg;
    UINT8  BusCtrlSpe, PmuSpe, PccaSpe,  VartSpe, HdacSpe,SpiSpe;
    UINT8  EspiSpe;	//HYL-20160501 	
    UINT16 PmioBar = SbCfg->PmioBar;
    UINT16 Data16 = 0;
    UINT8  X,Y,Z;
	UINT64 Addr;

	UINT8 RTE_Index;
	UINT32 RTE_Hi, RTE_Lo;
	 
//HYL-2018062901-start
#ifdef ZX_SECRET_CODE
	if(SbCfg->WDTClear==1)
	{
		AsiaMemoryWrite8(0xFEB41000, 0x00);	
		DEBUG((EFI_D_ERROR|EFI_D_INFO, "Disable WDT Timer\n"));
    	}
#endif
//HYL-2018062901-end  	
	 
    // Process SPE tables
    switch(SbCfg->SBSPEValue)
    {
	    case CHIP_SPE_VALUE_MANUAL:
	        VartSpe = SbCfg->VARTSPEValue;
	        EspiSpe = SbCfg->ESPISPEValue;	//HYL-20160501		
	        BusCtrlSpe = SbCfg->BusCtrlSPEValue;
	        PmuSpe = SbCfg->PMUSPEValue;
	        PccaSpe = SbCfg->PCCASPEValue;
	        HdacSpe = SbCfg->HDACSPEValue;
			SpiSpe=SbCfg->SPISPEValue;
	        break;
	    case CHIP_SPE_VALUE_STABLE: // Setup UI's default value
	        SpiSpe=VartSpe = EspiSpe = BusCtrlSpe = PmuSpe = PccaSpe 
	                                         = HdacSpe = DEVICE_SPE_VALUE_STABLE;		//HYL-20160501
	        break;
	    case CHIP_SPE_VALUE_PERFORMANCE:
	        SpiSpe=VartSpe = EspiSpe =  BusCtrlSpe = PmuSpe = PccaSpe 
	                                         = HdacSpe = DEVICE_SPE_VALUE_PERFORMANCE;	//HYL-20160501
	        break;
	    case CHIP_SPE_VALUE_ENERGY:
	        SpiSpe=VartSpe = EspiSpe = BusCtrlSpe = PmuSpe = PccaSpe 
	                                         = HdacSpe = DEVICE_SPE_VALUE_ENERGY;	//HYL-20160501
	        break;
	    default:
	        SpiSpe=VartSpe = EspiSpe = BusCtrlSpe = PmuSpe = PccaSpe 
	                                         = HdacSpe = DEVICE_SPE_VALUE_STABLE;	//HYL-20160501
    }


    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 1!\n"));

    if(BusCtrlSpe >= DEVICE_SPE_VALUE_PERFORMANCE)
    {
        PROCESS_SB_R6408M_TABLE_SAVE(BusCtrl_Performance_TBL, sizeof(BusCtrl_Performance_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        PROCESS_SB_R6408M_TABLE_SAVE(BusCtrl_Energy_TBL, sizeof(BusCtrl_Energy_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        //MMIO part
        AsiaMemoryModifySave8(SbCfg->D17F0MmioBar + D17F0MMIO_BACKDOOR_REG,  0x02, 0x02 );//D17F0 MMIO Rx50[1]
        
		if(ASIA_SB_REVISION!=0){
		AsiaIoModifySave8(PmioBar + PMIO_RTCOSC_CTL_REG, 0x10, 0x00);//Enable SB RTC  Dynamic Clock,suppress because of CHX002 A0 RTC design bug
		AsiaPciModifySave8((CHX002_BUSC|D17F0_SM_DEBUG_CTL), D17F0_ENTMRCCLK, D17F0_ENTMRCCLK); ///Enable TMRC Dynamic Clock 
		}
    }
	if(SpiSpe>=DEVICE_SPE_VALUE_PERFORMANCE){		
        AsiaMemoryModifySave8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x0C, 0x0C);//Enable Spi spe value
		}
	
	if(EspiSpe>=DEVICE_SPE_VALUE_PERFORMANCE){
            AsiaPciModifySave8((CHX002_ESPI|D11F0_ESPI_CTL),  0x7E, 0x7E); //HYL-20180122
            AsiaPciModifySave8((CHX002_ESPI|D11F0_ESPI_CTL_Z1),  0x7B, 0x7B);     //HYL-20160822    			
		}

#ifdef IOE_EXIST
    // IOE SATA SPE Init
	IOESataDxeInit(SbCfg);
    
    // IOE USB SPE Init
    IOEUsbDxeInit(SbCfg);

    // IOE GNIC SPE Init
	IOEGnicDxeInit(SbCfg);
#endif

    if(PccaSpe >= DEVICE_SPE_VALUE_PERFORMANCE)
    {
        PROCESS_SB_R6408M_TABLE_SAVE(Pcca_Performance_TBL, sizeof(Pcca_Performance_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(PccaSpe == DEVICE_SPE_VALUE_ENERGY)
        {
            PROCESS_SB_R6408M_TABLE_SAVE(Pcca_Energy_TBL, sizeof(Pcca_Energy_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }

    if(PmuSpe >= DEVICE_SPE_VALUE_PERFORMANCE)
    {
        PROCESS_SB_R6408M_TABLE_SAVE(Pmu_Performance_TBL, sizeof(Pmu_Performance_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(PmuSpe == DEVICE_SPE_VALUE_ENERGY)
        {
            PROCESS_SB_R6408M_TABLE_SAVE(Pmu_Energy_TBL, sizeof(Pmu_Energy_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 2!\n")); 
   if(HdacSpe >= DEVICE_SPE_VALUE_PERFORMANCE)
    {
        PROCESS_SB_R6408M_TABLE_SAVE(Hdac_Performance_TBL, sizeof(Hdac_Performance_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(HdacSpe == DEVICE_SPE_VALUE_ENERGY)
        {
            PROCESS_SB_R6408M_TABLE_SAVE(Hdac_Energy_TBL, sizeof(Hdac_Energy_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }
    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 2-1!\n")); 

    SataInitDxe(SbCfg);
	UsbInitDxe(SbCfg);
    //Process APIC config
    if (SbCfg->ApicEnable)
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_SOUTH_MODULE_MISC_CTL_1), D17F0_ENIAPIC, BIT6);

		//Set SB IOAPIC Address to D0F5 for dual socket purpose.
		Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_SB_APIC_ADR_XY);
		
        X= (UINT8)(RShiftU64(SbCfg->ApicBar, 16) & 0xF);
		AsiaPcieModifySave8(0xE0000000, Addr, D0F5_RLGAX_SB_19_16, X << 4);

        Y = (UINT8)(RShiftU64(SbCfg->ApicBar, 12) & 0xF);
		AsiaPcieModifySave8(0xE0000000, Addr, D0F5_RLGAY_SB_15_12, Y);

        Z = (UINT8)(RShiftU64(SbCfg->ApicBar, 8) & 0xF);

		Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_SB_APIC_ADR_Z);
		AsiaPcieModifySave8(0xE0000000, Addr, D0F5_RLGAZ_SB_11_8, Z);

		//set SB APIC ID ;
        AsiaMemoryWriteSave8(SbCfg->ApicBar, 0x00);
        AsiaMemoryWriteSave32(SbCfg->ApicBar + 0x10, SbCfg->SbApicID<<24);
		//set SB APIC use FSB
        AsiaMemoryWriteSave8(SbCfg->ApicBar, 0x03);
        AsiaMemoryWriteSave32(SbCfg->ApicBar + 0x10, 0x01);

		//For debug, dump all RT entry
		//RTE index from 0x10 - 0x3E, total 24 entry
		 
		for(RTE_Index = 0x10 ; RTE_Index < 0x40 ; RTE_Index += 2)
		{	
			AsiaMemoryWrite8(SbCfg->ApicBar, RTE_Index);
			RTE_Lo = AsiaMemoryRead32(SbCfg->ApicBar + 0x10);
			AsiaMemoryWrite8(SbCfg->ApicBar, RTE_Index + 1);
			RTE_Hi = AsiaMemoryRead32(SbCfg->ApicBar + 0x10);
			DEBUG((EFI_D_ERROR|EFI_D_INFO, "WIC SB RET%d Hi:%X Lo:%X\n",(RTE_Index - 0x10)/2, RTE_Hi, RTE_Lo));
		}
		 

		//Clear bit 48 for each I/O Redirection Table Entry due to design issue cause default value randomly
		for(RTE_Index = 0x10 ; RTE_Index < 0x40 ; RTE_Index += 2)
		{	
			AsiaMemoryWriteSave8(SbCfg->ApicBar, RTE_Index + 1);

			AsiaMemoryModifySave32(SbCfg->ApicBar + 0x10, 0x10000 , 0);

			RTE_Hi = AsiaMemoryRead32(SbCfg->ApicBar + 0x10);
			DEBUG((EFI_D_ERROR|EFI_D_INFO, "WIC SB RET%d Hi:%X\n",(RTE_Index - 0x10)/2, RTE_Hi));
		}

		
    }
    else
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_SOUTH_MODULE_MISC_CTL_1), D17F0_ENIAPIC, 0x00);
    }

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 2-2!\n"));

    //Process PMU_ACPI_Other - mobile center/Ac adapter/usbs4wakeup
    if(SbCfg->ACAdapterControl)
    {
        AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_8 + 1, BIT1, BIT1);
    }
    if(SbCfg->MobileCenterControl)
    {
        AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_8 + 1, BIT0, BIT0);
    }

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 2-3!\n")); 
	//Disable C states in desktop mode.
    if(SbCfg->CRBPlatformSelection == CRB_PLATFORM_MODE_SELECTION_DESKTOP) {
      SbCfg->ProcessorCState = PROCESSOR_CSTATE_DISABLED;
      SbCfg->C5Control = 0;
      SbCfg->ConditionalC4 = 0;
    }

    AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13+2, 0x0F,0x00);
	
    //Process CPU - C5 Control Scratch
    if(SbCfg->C5Control && (SbCfg->ProcessorCState >= PROCESSOR_CSTATE_C2_C4))
    {
        AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13+2, 0x0F,0x05);
    }
    else
    {
        switch(SbCfg->ProcessorCState)
        {
            case PROCESSOR_CSTATE_DISABLED:
                 // Disable in ACPI table, we don't do anything here
              break;
            case PROCESSOR_CSTATE_C2:
                AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13+2,0x0F, 0x02);			
                break;
            case PROCESSOR_CSTATE_C2_C3:

            case PROCESSOR_CSTATE_C2_C3_UPDOWN_MODE:
                AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13+2,0x0F, 0x03);			
                break;
            case PROCESSOR_CSTATE_C2_C4:

            case PROCESSOR_CSTATE_C2_C4_UPDOWN_MODE:
                AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13+2,0x0F, 0x04);			
                break;
            default:
                break;			
        }
    }
	
    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 3!\n")); 
    //
    //DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 4!\n")); 
    // Process P2P Bridge policy
    //DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 5!\n")); 

    // Process Hda policy
    if(SbCfg->Azalia)
    {
        AsiaPciModifySave8((CHX002_PCCA|D17F7_HDAC_AND_P2P_RELATED_CTL), 0x04, 0x00); // 0=Enable HDAC.
        
        if(SbCfg->GoNonSnoopPath)
        {
            AsiaPciModifySave8((CHX002_HDAC|D20F0_BACK_DOOR), 0x80, 0x00); // Non-Snoop path.
        }
        else
        {
            AsiaPciModifySave8((CHX002_HDAC|D20F0_BACK_DOOR), 0x80, 0x80); // Snoop path.
        }
        if(SbCfg->HDACFLREn)
        {
            AsiaPciModifySave8(CHX002_HDAC|D20F0_BACK_DOOR_ENABLE, 0x40, 0x00); // Enable FLR 
        }
	 else
	 {
	  	AsiaPciModifySave8(CHX002_HDAC|D20F0_BACK_DOOR_ENABLE, 0x40, 0x40);       // Disable FLR 
        }		
    }   
    else
    {
        AsiaPciModifySave8((CHX002_PCCA|D17F7_HDAC_AND_P2P_RELATED_CTL), 0x04, 0x04); // 1=Disable HDAC.
    }

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 6!\n")); 
    
	
    // Process UART policy
    if(SbCfg->OnChipUartMode == ON_CHIP_UART_MODE_DISABLED)
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL), 0x0F, 0x00);
    }    
    else 
    {
        //while((AsiaIoRead8(0x03F8 + 0x05)&(BIT5|BIT6))!=(BIT5|BIT6));  //HAPS ONLY
        AsiaPciModifySave8((CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL), 0x0F, 0x00);		
	 	
	 	
        if (SbCfg->Uart0Enable)
        {
        	if(SbCfg->Uart0_8PinEnable)
			{	
	        	//Enable 8Pin UART0
	          	AsiaIoModifySave16(PmioBar + PMIO_PAD_CTL_REG_Z1,PMIO_P2G_GPIO37_2_1_0,0x04); //Enable SOUT0
	        	AsiaIoModifySave32(PmioBar + PMIO_CR_GPIO_PAD_CTL,PMIO_PAD_GPIO13_2_1_0|PMIO_PAD_GPIO12_2_1_0,0x13000000); //Enable CTS0/SIN0
	        	AsiaIoModifySave32(PmioBar + PMIO_GPIO_PAD_CTL,PMIO_PAD_GPIO14_2_1_0|PMIO_PAD_GPO37_2_1_0|PMIO_PAD_GPO38_2_1_0|PMIO_PAD_GPO39_2_1_0|PMIO_PAD_GPO40_2_1_0,0x09090002);  //Enable DSR0/DRT0/DCD0/RI0/RTS0	
			}
			else
			{
				//Enable 4Pin UART0
	        	AsiaIoModifySave16(PmioBar + PMIO_PAD_CTL_REG_Z1,PMIO_P2G_GPIO37_2_1_0,0x04); //Enable SOUT0
	        	AsiaIoModifySave32(PmioBar + PMIO_CR_GPIO_PAD_CTL,PMIO_PAD_GPIO13_2_1_0|PMIO_PAD_GPIO12_2_1_0,0x13000000); //Enable CTS0/SIN0
	        	AsiaIoModifySave32(PmioBar + PMIO_GPIO_PAD_CTL,PMIO_PAD_GPIO14_2_1_0,0x00000002); //Enable TRS0
			}
			switch(SbCfg->Uart0IoBaseSelection)
            {
                case UART_IO_BASE_SEL_3F8:
                    Data16 = 0x3F8;
                    break;		
                case UART_IO_BASE_SEL_2F8:
                    Data16 = 0x2F8;
                    break;		
                case UART_IO_BASE_SEL_3E8:
                    Data16 = 0x3E8;
                    break;		
                case UART_IO_BASE_SEL_2E8:
                    Data16 = 0x2E8;
                    break;		
            }
            if (SbCfg->UartModuleSelection == UART_MODULE_SEL_PCIDMA)                
            {   
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_0_IO_BASE_ADR, 0x80, 0x00);	    // disable Legacy mode
                AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x01, 0x01);	        // Vart 0 enable
                AsiaPciModifySave8(CHX002_UART0|D10F0F1_UARTCFG_BAKUP_REG, 0x01, 0x00);       // enable DMA mode 
                if(SbCfg->UartFLREn)
                {
                	AsiaPciModifySave32(CHX002_UART0|D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1, 0x00010000, 0x00010000);       // enable FLR 
                }
		  		else
		  		{
		  			AsiaPciModifySave32(CHX002_UART0|D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1, 0x00010000, 0x00000000);       // Disable FLR 
                }
            }
            else if(SbCfg->UartModuleSelection == UART_MODULE_SEL_LEGACY)
            {                
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_0_IO_BASE_ADR, 0x80, 0x80);	    // enable Legacy mode 
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_0_IO_BASE_ADR, 0x7F, (UINT8)(Data16>>3));
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_IRQ_ROUTING_LOW, 0x0F, SbCfg->Uart0IRQSelection);
                AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x01, 0x01);	        // Vart 0 enable
            }
			else
			{
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_0_IO_BASE_ADR, 0x80, 0x00);	// disable Legacy mode
                AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x01, 0x01);	    // Vart 0 enable
                AsiaPciModifySave8(CHX002_UART0|D10F0F1_UARTCFG_BAKUP_REG, 0x01, 0x01);   // enable PCI Compatible mode
			}
        }
        else
        {
            if(SbCfg->UartModuleSelection == UART_MODULE_SEL_LEGACY)
        	{
				AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_0_IO_BASE_ADR, 0xFF, 0);
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_IRQ_ROUTING_LOW, 0x0F, 0);
			}
           AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x01, 0x00);	        // Vart 0 disable
        }
	    
        if (SbCfg->Uart1Enable)
        {
        	//Enable 4Pin UART1
        	//Enable SIN1/SOUT1/RTS1/CTS1
	        AsiaIoModifySave32(PmioBar + PMIO_GPIO_PAD_CTL,PMIO_PAD_GPO40_2_1_0|PMIO_PAD_GPO39_2_1_0|PMIO_PAD_GPO38_2_1_0|PMIO_PAD_GPO37_2_1_0,0x242D0000);
            switch(SbCfg->Uart1IoBaseSelection)
            {
                case UART_IO_BASE_SEL_3F8:
                    Data16 = 0x3F8;
                    break;		
                case UART_IO_BASE_SEL_2F8:
                    Data16 = 0x2F8;
                    break;		
                case UART_IO_BASE_SEL_3E8:
                    Data16 = 0x3E8;
                    break;		
                case UART_IO_BASE_SEL_2E8:
                    Data16 = 0x2E8;
                    break;		
            }
            if (SbCfg->UartModuleSelection == UART_MODULE_SEL_LEGACY)
            {           
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_1_IO_BASE_ADR, 0x80, 0x80);	// enable Legacy mode 
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_1_IO_BASE_ADR, 0x7F, (UINT8)(Data16>>3));
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_IRQ_ROUTING_LOW, 0xF0, (SbCfg->Uart1IRQSelection<<4));
                AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x02, 0x02);	// Vart 1 enable
            }
            else if(SbCfg->UartModuleSelection == UART_MODULE_SEL_PCIDMA)
            {  
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_1_IO_BASE_ADR, 0x80, 0x00);	// disable Legacy mode
                AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x02, 0x02);	    // Vart 1 enable
                AsiaPciModifySave8(CHX002_UART1|D10F0F1_UARTCFG_BAKUP_REG, 0x01, 0x00);   // enable DMA mode

                if(SbCfg->UartFLREn)
                {
                	AsiaPciModifySave32(CHX002_UART1|D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1, 0x00010000, 0x00010000);       // enable FLR 
                }
		 		else
		 		{
		  			AsiaPciModifySave32(CHX002_UART1|D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1, 0x00010000, 0x00000000);       // Disable FLR 
                }
            }
			else
			{
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_1_IO_BASE_ADR, 0x80, 0x00);	// disable Legacy mode
                AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x02, 0x02);	    // Vart 1 enable
                AsiaPciModifySave8(CHX002_UART1|D10F0F1_UARTCFG_BAKUP_REG, 0x01, 0x01);   // enable PCI Compatible mode
			}
        }
        else
        {	
        	if(SbCfg->UartModuleSelection == UART_MODULE_SEL_LEGACY)
        	{
				AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_1_IO_BASE_ADR, 0xFF, 0);
                AsiaPciModifySave8(CHX002_BUSC|D17F0_PCI_UART_IRQ_ROUTING_LOW, 0xF0, 0);
			}
            AsiaPciModifySave8(CHX002_BUSC|D17F0_APIC_FSB_DATA_CTL, 0x02, 0x00);	// Vart 1 disable              
        }
   	}        

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 8!\n")); 

    // Process SNMI policy
    if (SbCfg->IsoLPC == 1)
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN, D17F7_MISO, D17F7_MISO);
	else
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN, D17F7_MISO, 0x00);
	
	if (SbCfg->IsoVART == 1)
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN, D17F7_VARTISO, D17F7_VARTISO);
	else
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN, D17F7_VARTISO, 0x00);
	if (SbCfg->IsoAZALIA == 1)
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN, D17F7_AZISO, D17F7_AZISO);
	else
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN, D17F7_AZISO, 0x00);

	if (SbCfg->IsoESPI == 1)
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN_Z1, D17F7_VIOD, D17F7_VIOD);
	else
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN_Z1, D17F7_VIOD, 0x00);

	if (SbCfg->IsoSPI== 1)
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN_Z1, D17F7_SPIISO, D17F7_SPIISO);
	else
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN_Z1, D17F7_SPIISO, 0x00);
    ///MTN_0317
	if (SbCfg->IsoAPIC== 1)
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN_Z1, D17F7_APICISO, D17F7_APICISO);
	else
		AsiaPciModifySave8(CHX002_PCCA|D17F7_ISO_FUN_Z1, D17F7_APICISO, 0x00);

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 9!\n")); 
	
    // Process Others policy
    if(SbCfg->EnableMultimediaTimer) // HPET
    {
    	if(SbCfg->MultimediaTimerMode)
    	{
		 AsiaPciModifySave32((CHX002_BUSC|D17F0_HPET_CTL), 0xFFFFFC90, (SbCfg->HpetBar|0x90));	//INTxxx mode
	}
	else
	{
       	 AsiaPciModifySave32((CHX002_BUSC|D17F0_HPET_CTL), 0xFFFFFC80, (SbCfg->HpetBar|0x80));		//ZX mode
	}	

	if(SbCfg->EnableMultimediaTimerMsi==0)//timer  MIS feature support?
    	{
		 AsiaPciModifySave8((CHX002_BUSC|D17F0_APIC_C4P_STATE_MODE_CTL), 0x70, 0x70);	//timer  MIS feature support disabled
	}
    }
    else
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_HPET_CTL), 0x80, 0x00);
    }

    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - 10!\n")); 

    if(SbCfg->KBMouseWakeupControl)
    {
#ifdef EC_PS2KBC_SUPPORT
#else
        AsiaPciModifySave8((CHX002_BUSC|D17F0_FUN_CTL_2), 0x02, 0x02);
        AsiaIoWriteSave8(0x2E, 0xE0);
        AsiaIoModifySave8(0x2F, 0x03, 0x03);
        AsiaIoWriteSave8(0x2E, 0xE1);
        AsiaIoWriteSave8(0x2F, 0x00);
        AsiaIoWriteSave8(0x2E, 0xE9);
        AsiaIoWriteSave8(0x2F, 0x00);
        AsiaPciModifySave8((CHX002_BUSC|D17F0_FUN_CTL_2), 0x02, 0x00);
#endif
    }
    else
    {
#ifdef EC_PS2KBC_SUPPORT
#else
        AsiaPciModifySave8((CHX002_BUSC|D17F0_FUN_CTL_2), 0x02, 0x02);
        AsiaIoWriteSave8(0x2E, 0xE0);
        AsiaIoModifySave8(0x2F, 0x03, 0x00);
        AsiaPciModifySave8((CHX002_BUSC|D17F0_FUN_CTL_2), 0x02, 0x00);
#endif
    }

//hurry-0420-start
	if (SbCfg->ESPI == 1)
		AsiaIoModifySave8(PmioBar + PMIO_ESPI_SUSPEND_DOMAIN_CTL_REG, 0x01, 0x01);
	else
		AsiaIoModifySave8(PmioBar + PMIO_ESPI_SUSPEND_DOMAIN_CTL_REG, 0x01, 0x00);
//IVS-20180925-LPT or 80Port Select for HX002EH0
#if defined(HX002EH0_01)||defined(HX002EL0_05)
	AsiaIoWriteSave8(0x2E,0x87);
	AsiaIoWriteSave8(0x2E,0x01);
	AsiaIoWriteSave8(0x2E,0x55);
	AsiaIoWriteSave8(0x2E,0x55);

	AsiaIoWriteSave8(0x2E,0x07);
	AsiaIoWriteSave8(0x2F,0x03);

	if(SbCfg->LPTControl)
	{
		AsiaIoWriteSave8(0x2E,0xF0); //Diable 80Port
		AsiaIoWriteSave8(0x2F,0x0B);
		
		AsiaIoWriteSave8(0x2E,0x30);
		AsiaIoWriteSave8(0x2F,0x01); // Enable LPT
	}
	else
	{
		AsiaIoWriteSave8(0x2E,0xF0); //Enable 80Port
		AsiaIoWriteSave8(0x2F,0x00);
		
		AsiaIoWriteSave8(0x2E,0x30);
		AsiaIoWriteSave8(0x2F,0x00); // Disable LPT
	}
	AsiaIoWriteSave8(0x2E,0x02);
	AsiaIoWriteSave8(0x2F,0x02);
#endif
	    DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit - end!\n"));
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS 
AsiaSbLockVidDidRid(
//YKN-20151025 -s
	ASIA_SB_CONFIGURATION* SbCfg
//YKN-20151025 -e
)
{
	//ASIA_SB_CONFIGURATION* SbCfg = AsiaSb->SbCfg;
	UINT8 		Index, Tmp8;
	BOOLEAN		VidNeedChange = FALSE, VidNeedLock=FALSE;
	UINT16		TmpVid = 0;
	UINT64		Address;

	Tmp8 = AsiaPciRead8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13);

	//VID_Lock_Default is 0, BIOS can change VID if needed. We must lock VID after change.
	if((Tmp8 & 0x02) == 0) {
		VidNeedLock = TRUE;
#ifdef ZX_SECRET_CODE
		//If default VID is different from user selected, change it.
		if((Tmp8 & 0x1) != SbCfg->VidSelect) {
			VidNeedChange = TRUE;
			TmpVid = SbCfg->VidSelect ? PCI_VID_VIA : PCI_VID_ZX;
		}	
#endif			
	}

	//DEBUG((EFI_D_ERROR|EFI_D_INFO, "%a: Tmp8=%x, VidNeedLock=%x,VidNeedChange=%d\n", __FUNCTION__, Tmp8, VidNeedLock, VidNeedChange));
	for(Index = 0; Index < sizeof(SbVidDidLockTbl)/sizeof(SbVidDidLockTbl[0]); Index++) {
		Address = ASIA_PCI_ADDRESS(0, SbVidDidLockTbl[Index].Device, SbVidDidLockTbl[Index].Function, 0);
		//In case some functions are disabled.
		if(AsiaPciRead16(Address) == 0xFFFF)
			continue;
		//Lock VID
		if(VidNeedLock) {
			if(VidNeedChange) {
				AsiaPciWriteSave16(Address, TmpVid);
			}
			Address = AsiaPciAddress(0,SbVidDidLockTbl[Index].Device, 
									SbVidDidLockTbl[Index].Function, 
									SbVidDidLockTbl[Index].VIDLockReg);
									AsiaPciModifySave8(Address, SbVidDidLockTbl[Index].VIDLockBit, SbVidDidLockTbl[Index].VIDLockBit);
		}
		//Lock DID/RID
		Address = AsiaPciAddress(0,SbVidDidLockTbl[Index].Device, 
								SbVidDidLockTbl[Index].Function, 
								SbVidDidLockTbl[Index].DIDLockReg);
								AsiaPciModifySave8(Address, SbVidDidLockTbl[Index].DIDLockBit, SbVidDidLockTbl[Index].DIDLockBit); 
	}

	//Lock HPET VID if needed.
	if(SbCfg->EnableMultimediaTimer && VidNeedLock) {
		AsiaPciModifySave8(CHX002_BUSC|D17F0_SM_DEBUG_CTL, D17F0_HPET_VID_LOCK, D17F0_HPET_VID_LOCK);
	}

	return EFI_SUCCESS;
}

 //YKN-20161025-02 -s
 /**
  Function description.
  
  @param  VOID

  @return VOID.

**/
VOID
UpdateSbSVIDSSID()
{
    UINTN Index;
     UINT64  Address;
    //UART0~1
    for(Index=0; Index < 2; Index++) {
	  Address = ASIA_PCI_ADDRESS(0, CHX002_UART_DEV, Index, 0);
        if(AsiaPciRead16(Address)  != 0xFFFF) {
            AsiaPciModifySave8(Address|D10F0F1_BACK_DOOR_CTL_REG, D10F0F1_SVIDEN|D10F0F1_SSIDEN, D10F0F1_SVIDEN|D10F0F1_SSIDEN);
            AsiaPciWriteSave32((Address|D10F0F1_SVID), AsiaPciRead32(Address|D10F0F1_VID));
	     AsiaPciModifySave8(Address|D10F0F1_BACK_DOOR_CTL_REG, D10F0F1_SVIDEN|D10F0F1_SSIDEN, 0);
	}
    }
    //eSPI
     if(AsiaPciRead16(CHX002_ESPI|D11F0_VID) != 0xFFFF) {
	  AsiaPciModifySave8(CHX002_ESPI|D11F0_BACK_DOOR_ENABLE, D11F0_EN2CW, D11F0_EN2CW);
        AsiaPciWriteSave32((CHX002_ESPI|D11F0_SVID), AsiaPciRead32(CHX002_ESPI|D11F0_VID));
	 AsiaPciModifySave8(CHX002_ESPI|D11F0_BACK_DOOR_ENABLE, D11F0_EN2CW, 0);  
    }
	 
    //BUSC
    AsiaPciWriteSave32((CHX002_BUSC|D17F0_SVID_BACKDOOR_REGS), AsiaPciRead32(CHX002_BUSC|D17F0_VID));

    //PCCA
    AsiaPciWriteSave32(CHX002_PCCA|D17F7_BACKDOOR_REG_FOR_SVID, AsiaPciRead32(CHX002_PCCA|D17F7_VID));
    AsiaPciModifySave8(CHX002_PCCA|D17F7_PCI_IO_CYCLE_CTL_Z2, D17F7_RX2C_SEL, D17F7_RX2C_SEL); //Always use backdoor
	
    //HDAC
    if(AsiaPciRead16(CHX002_HDAC|D20F0_VID) != 0xFFFF) {
        AsiaPciModifySave8(CHX002_HDAC|D20F0_BACK_DOOR_ENABLE, D20F0_EN2CW, D20F0_EN2CW);
        AsiaPciWriteSave32((CHX002_HDAC|D20F0_SVID), AsiaPciRead32(CHX002_HDAC|D20F0_VID));
	 AsiaPciModifySave8(CHX002_HDAC|D20F0_BACK_DOOR_ENABLE, D20F0_EN2CW, 0);  
    }
	//USB [ALJ20181025]
	AsiaPciModifySave8(CHX002_D14F0UHCI|D14F0_CTL_REG_3,BIT4,BIT4);//Rx42 bit4 =1
	AsiaPciWriteSave32(CHX002_D14F0UHCI|D14F0_SVID,AsiaPciRead32(CHX002_D14F0UHCI|D14F0_VID));
	AsiaPciModifySave8(CHX002_D14F0UHCI|D14F0_CTL_REG_3,BIT4,0);//Rx42 bit4 =0
	
	AsiaPciModifySave8(CHX002_D14F7EHCI|D14F7_CTL_REG_2,BIT4,BIT4);//Rx42 bit4 =1
	AsiaPciWriteSave32(CHX002_D14F7EHCI|D14F7_SVID,AsiaPciRead32(CHX002_D14F7EHCI|D14F7_VID));
	AsiaPciModifySave8(CHX002_D14F7EHCI|D14F7_CTL_REG_2,BIT4,0);//Rx42 bit4 =0

	AsiaPciModifySave8(CHX002_D16F0UHCI|D16F0F1_CTL_REG_3,BIT4,BIT4);//Rx42 bit4 =1
	AsiaPciWriteSave32(CHX002_D16F0UHCI|D16F0F1_SVID,AsiaPciRead32(CHX002_D16F0UHCI|D16F0F1_VID));
	AsiaPciModifySave8(CHX002_D16F0UHCI|D16F0F1_CTL_REG_3,BIT4,0);//Rx42 bit4 =0

	AsiaPciModifySave8(CHX002_D16F1UHCI|D16F0F1_CTL_REG_3,BIT4,BIT4);//Rx42 bit4 =1
	AsiaPciWriteSave32(CHX002_D16F1UHCI|D16F0F1_SVID,AsiaPciRead32(CHX002_D16F1UHCI|D16F0F1_VID));
	AsiaPciModifySave8(CHX002_D16F1UHCI|D16F0F1_CTL_REG_3,BIT4,0);//Rx42 bit4 =0

	AsiaPciModifySave8(CHX002_D16F7EHCI|D16F7_CTL_REG_2,BIT4,BIT4);//Rx42 bit4 =1
	AsiaPciWriteSave32(CHX002_D16F7EHCI|D16F7_SVID,AsiaPciRead32(CHX002_D16F7EHCI|D16F7_VID));
	AsiaPciModifySave8(CHX002_D16F7EHCI|D16F7_CTL_REG_2,BIT4,0);//Rx42 bit4 =0
}
   //YKN-20161025-02 -e

   /**
	 Function description.
	 
	 @param  PeiServices   EFI_PEI_SERVICES pointer.
	 @param SbCfg Point to ASIA_SB_CONFIGURATION struct.
   
	 @return EFI_STATUS.
   
   **/

VOID AsiaSbDxeSidLock(ASIA_SB_CONFIGURATION* SbCfg)
{   
#ifdef ZX_DUALSOCKET
	UINT8 SlaveBusNum = SbCfg->ZxeSlaveBusNum;
#endif
		   
	//Master: program SID reigster of SB devices    
	AsiaMemoryModifySave16(SbCfg->D17F0MmioBar | D17F0MMIO_APIC_SRC_ID, 0xFFFF, 0x0088);//0x0088 	
	AsiaMemoryModifySave16(SbCfg->D17F0MmioBar | D17F0MMIO_LPC_SPI_SRC_ID, 0xFFFF, 0x0088);//0x0088
	AsiaMemoryModifySave16(SbCfg->D17F0MmioBar | D17F0MMIO_HPET_SRC_ID, 0xFFFF, 0x8080);//0x8080
			 
	AsiaPciModifySave16(CHX002_D14F0UHCI | D14F0_CCA_BUS_SRC_ID, D14F0_UBDF, 0x0070);//0x0070
	AsiaPciModifySave16(CHX002_D14F7EHCI | D14F7_CCA_BUS_SRC_ID, D14F7_U2BDF, 0x0077);//0x0077
		 
	AsiaPciModifySave16(CHX002_SATA | D15F0_SID_DEV_FUN, ((UINT16)D15F0_BUSNUM << 8)|D15F0_DEVNUM|D15F0_FUNNUM, 0x0078);//0x0078
		   
	AsiaPciModifySave16(CHX002_D16F0UHCI | D16F0F1_CCA_BUS_SRC_ID_D16F0, D16F0F1_UBDF, 0x0080);//0x0080
	AsiaPciModifySave16(CHX002_D16F1UHCI | D16F0F1_CCA_BUS_SRC_ID_D16F0, D16F0F1_UBDF, 0x0081);//0x0081
	AsiaPciModifySave16(CHX002_D16F7EHCI | D16F7_CCA_BUS_SRC_ID, D16F7_U2BDF, 0x0087);//0x0087
			 
	AsiaPciModifySave16(CHX002_XHCI | D18F0_XHCI_SRC_ID_BACKDOOR, D18F0_SID, 0x0090);//0x0090
			 
	AsiaPciModifySave8(CHX002_BUSC | D17F0_APIC_FSB_DATA_CTL, D17F0_EN_VART1|D17F0_EN_VART0, D17F0_EN_VART1|D17F0_EN_VART0);
	AsiaPciModifySave8(CHX002_BUSC | D17F0_PCI_UART_1_IO_BASE_ADR, D17F0_VART1_COMPTBL, 0x0);//disalbe legacy mode
	AsiaPciModifySave8(CHX002_BUSC | D17F0_PCI_UART_0_IO_BASE_ADR, D17F0_VART0_COMPTBL, 0x0);//disalbe legacy mode
	AsiaPciModifySave16(CHX002_UART0 | D10F0_UART0_SID, 0xFFFF, 0x0050);
	AsiaPciModifySave16(CHX002_UART1 | D10F1_UART1_SID, 0xFFFF, 0x0051);
	AsiaPciModifySave8(CHX002_BUSC | D17F0_PCI_UART_1_IO_BASE_ADR, D17F0_VART1_COMPTBL, D17F0_VART1_COMPTBL);//enable legacy mode
	AsiaPciModifySave8(CHX002_BUSC | D17F0_PCI_UART_0_IO_BASE_ADR, D17F0_VART0_COMPTBL, D17F0_VART0_COMPTBL);//enable legacy mode
			
	AsiaIoModifySave8(SbCfg->PmioBar + PMIO_ESPI_SUSPEND_DOMAIN_CTL_REG, PMIO_ENESPI_SW, PMIO_ENESPI_SW);//enable espi  
	AsiaPciModifySave16(CHX002_ESPI | D11F0_ESPI_SRC_ID, D11F0_ESPI_SOURCEID, 0x0058);//0x0058
	AsiaIoModifySave8(SbCfg->PmioBar + PMIO_ESPI_SUSPEND_DOMAIN_CTL_REG, PMIO_ENESPI_SW, 0x0);//disable espi 		 
			 
	AsiaPciModifySave16(CHX002_HDAC | D20F0_HDAC_SRC_ID, D20F0_HDAC_SOURCEID, 0x00A0);//0x00A0
			 
	//Lock the SID register of all SB device 	 
	AsiaPciModifySave8(CHX002_BUSC | D17F0_SB_SRC_ID_LOCK_CTL, D17F0_SID_LOCK, D17F0_SID_LOCK);
	   
#ifdef ZX_DUALSOCKET
	//Slave: program SID reigster of SB devices	
	AsiaMemoryModifySave16(SbCfg->D17F0MmioBarSlave | D17F0MMIO_APIC_SRC_ID, 0xFFFF, ((UINT16)SlaveBusNum << 8)|0x88);//0x0088	
	AsiaMemoryModifySave16(SbCfg->D17F0MmioBarSlave | D17F0MMIO_LPC_SPI_SRC_ID, 0xFFFF, ((UINT16)SlaveBusNum << 8)|0x88);//0x0088
	   
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_UHCI0_DEV, 0, D14F0_CCA_BUS_SRC_ID), D14F0_UBDF, ((UINT16)SlaveBusNum << 8)|0x70);//0x0070
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_EHCI0_DEV, 7, D14F7_CCA_BUS_SRC_ID), D14F7_U2BDF, ((UINT16)SlaveBusNum << 8)|0x77);//0x0077
	   
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_SATA_DEV, 0, D15F0_SID_DEV_FUN), ((UINT16)D15F0_BUSNUM << 8)|D15F0_DEVNUM|D15F0_FUNNUM, ((UINT16)SlaveBusNum << 8)|0x78);//0x0078
	   
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_UHCI1_DEV, 0, D16F0F1_CCA_BUS_SRC_ID_D16F0), D16F0F1_UBDF, ((UINT16)SlaveBusNum << 8)|0x80);//0x0080
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_UHCI1_DEV, 1, D16F0F1_CCA_BUS_SRC_ID_D16F0), D16F0F1_UBDF, ((UINT16)SlaveBusNum << 8)|0x81);//0x0081
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_EHCI1_DEV, 7, D16F7_CCA_BUS_SRC_ID), D16F7_U2BDF, ((UINT16)SlaveBusNum << 8)|0x87);//0x0087
	   
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_XHCI_DEV, 0, D18F0_XHCI_SRC_ID_BACKDOOR), D18F0_SID, ((UINT16)SlaveBusNum << 8)|0x90);//0x0090
	   
	AsiaPciModifySave8(AsiaPciAddress(SlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_APIC_FSB_DATA_CTL), D17F0_EN_VART1|D17F0_EN_VART0, D17F0_EN_VART1|D17F0_EN_VART0);
	AsiaPciModifySave8(AsiaPciAddress(SlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_PCI_UART_0_IO_BASE_ADR), D17F0_VART0_COMPTBL, 0);//disable legacy mode.
	AsiaPciModifySave8(AsiaPciAddress(SlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_PCI_UART_1_IO_BASE_ADR), D17F0_VART1_COMPTBL, 0);//disable legacy mode.
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_UART_DEV, CHX002_UART0_FUN, D10F0_UART0_SID), 0xFFFF, ((UINT16)SlaveBusNum << 8)|0x50);
	AsiaPciModifySave16(AsiaPciAddress(SlaveBusNum, CHX002_UART_DEV, CHX002_UART1_FUN, D10F1_UART1_SID), 0xFFFF, ((UINT16)SlaveBusNum << 8)|0x51);
	AsiaPciModifySave8(AsiaPciAddress(SlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_PCI_UART_0_IO_BASE_ADR), D17F0_VART0_COMPTBL, D17F0_VART0_COMPTBL);//enable legacy mode.
	AsiaPciModifySave8(AsiaPciAddress(SlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_PCI_UART_1_IO_BASE_ADR), D17F0_VART1_COMPTBL, D17F0_VART1_COMPTBL);//enable legacy mode.
	   
	//Lock the SID register of all SB device    
	AsiaPciModifySave8(AsiaPciAddress(SlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_SB_SRC_ID_LOCK_CTL), D17F0_SID_LOCK, D17F0_SID_LOCK);
#endif 
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaSbDxePrePciInit (
    IN EFI_ASIA_SB_PROTOCOL *This
)
{
    DEBUG((EFI_D_ERROR|EFI_D_INFO, "AsiaSbPrePciInit!\n"));


    // Process Safe table, NULL now
    PROCESS_SB_R6408M_TABLE_SAVE(SB_Safe_TBL, sizeof(SB_Safe_TBL)/sizeof(ASIA_IO_TABLE_6408_REV));
	
	//JRZ: this function must be invoked before ESPI/UART initialization.
	AsiaSbDxeSidLock(This->SbCfg);  

	DEBUG((EFI_D_ERROR|EFI_D_INFO, "SbPolicyInit!\n")); 
    SbPolicyInit(This);   

    //YKN-20161025 -s
    // Temp disable VID/DID lock for S3 resume
    //	AsiaSbLockVidDidRid(This);
    //YKN-20161024 -e
	AsiaSbLockVidDidRid(This->SbCfg);
	UpdateSbSVIDSSID();
	//YKN-20161025 -e
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaSbDxePreprocessPciController (
    IN EFI_ASIA_SB_PROTOCOL *This,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
    IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
)
{   
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaSbDxePostPciInit (
    IN EFI_ASIA_SB_PROTOCOL *This,
    IN EFI_PCI_IO_PROTOCOL *PciIo
)
{
    //this is not the asia scope
    UINTN Segment, Bus, Device, Function;
    //UINT32 AhciMMIOBase;
    EFI_STATUS Status;
    ASIA_SB_CONFIGURATION* SbCfg = This->SbCfg;

    PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);
    if(Segment != 0)
    {
        return EFI_SUCCESS;
    }
    switch(AsiaPciAddress((UINT8)Bus, (UINT8)Device, (UINT8)Function, 0))
    {
    case CHX002_HDAC:
        if(SbCfg->Azalia)
        {
            Status = InitAzaliaAudio (SbCfg);

            if(EFI_ERROR(Status))
            {
                return Status;
            }
        }
        break;

    case CHX002_BUSC:
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PCI_CMD), 0x03, 0x03); 
        break;
    case CHX002_PCCA:
        AsiaPciModifySave8((CHX002_PCCA|D17F7_LATENCY_TIMER), 0xF8, 0x08);
        break;		
    default:
        break;
    }

    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaSbDxePreBootInit (
    IN EFI_ASIA_SB_PROTOCOL *This
)
{
    ASIA_SB_CONFIGURATION* SbCfg = This->SbCfg;
    UINT16 PmioBar = SbCfg->PmioBar;
    UINT16 SmbusBar;
    //UINT16 Data16 = 0;
        
	//Set D15F0 Revision ID to 1 for driver request
    // SCI IRQ
    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_ACPI_INTR_SEL), 0x0F, (SbCfg->AcpiIrq&0x0F));

    // Process PMU & ACPI policy
    switch(SbCfg->ProcessorCState)
    {
	    case PROCESSOR_CSTATE_DISABLED:
	        // Disable in ACPI table, we don't do anything here
	        break;
	    case PROCESSOR_CSTATE_C2:
	        // Enable/Disable in ACPI table, we don't do anything here
	        break;
	    case PROCESSOR_CSTATE_C2_C3:
	        AsiaIoModifySave8(PmioBar + PMIO_PROCESSOR_CTL_Z1, 0x07, 0x06);
		AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x4, 0x4);
		AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PULL_UP_OPTION), 0xB8, 0xB8);///MTN_20170922
		AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_MULTI_FUN_SEL_2), 0x4C, 0x4C);///MTN_20170922
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1_Z1), 0xE7, 0xE7);///MTN_20160722 Add eSPI Break Event		
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_3), 0x9F, 0x9F);///MTN_20160722 Add PCIEG1  Break Event
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_4), 0x7, 0x7);///MTN_20160420
	        break;
	    case PROCESSOR_CSTATE_C2_C3_UPDOWN_MODE:
	        AsiaIoModifySave8(PmioBar + PMIO_PROCESSOR_CTL_Z1, 0x07, 0x06);
	        // Enable PopUp/PopDown
	            AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x1D, 0x1D);
	        break;
	    case PROCESSOR_CSTATE_C2_C4:
	        AsiaIoModifySave8(PmioBar + PMIO_PROCESSOR_CTL_Z1, 0x07, 0x06);
		    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x4, 0x4);
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PULL_UP_OPTION), 0xB8, 0xB8);///MTN_20170922
		AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_MULTI_FUN_SEL_2), 0x4C, 0x4C);///MTN_20170922
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1_Z1), 0xE7, 0xE7);///MTN_20160722 Add eSPI Break Event		
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_3), 0x9F, 0x9F);///MTN_20160722 Add PCIEG1  Break Event
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_4), 0x7, 0x7);///MTN_20160420
	        break;
	    case PROCESSOR_CSTATE_C2_C4_UPDOWN_MODE:
	    default:
	        AsiaIoModifySave8(PmioBar + PMIO_PROCESSOR_CTL_Z1, 0x07, 0x06);
	        // Enable PopUp/PopDown
	        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x9D, 0x9D);
	        break;
    }

    SataInitPreBoot(SbCfg);

#ifdef IOE_EXIST
    // CND003 SATA
    IOESataDxePreBootInit(SbCfg);
#endif

    if(SbCfg->C5Control && (SbCfg->ProcessorCState >= PROCESSOR_CSTATE_C2_C4))
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x60, 0x60);//;D17F0_Rx8A[6:5]=11
    }
    else
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x60, 0x00);//;D17F0_Rx8A[6:5]=00
    }
	
    if(SbCfg->ProcessorCState > PROCESSOR_CSTATE_C2)
    {
		//Inhibit C3/C4 when HD Audio Big Format Data
        if(SbCfg->GoNonSnoopPath == FALSE)
        {
            AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_INTERNAL_NM_PLL_CTL), 0x01, 0x01);
        }
        if(SbCfg->C3BusMasterIdleTimer)
        {
            AsiaIoModifySave8(PmioBar + PMIO_C2_DOWN_TO_C3_IDLE_TIMER, 0x0F, (SbCfg->C3BusMasterIdleTimer)&0x0F);          
        }
		else
        {
            AsiaIoModifySave8(PmioBar + PMIO_C2_DOWN_TO_C3_IDLE_TIMER, 0x0F, 0x00);
        }     
		
        switch(SbCfg->FixedFreeCxLatency)
        {
        case FIX_FREE_CX_LATENCY_FIXED:
            AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_WATCHDOG_TIMER_CTL_C3_LATENCY_CTL), 0x04, 0x00);
            AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PROCESSOR_CTL), 0x06, ((SbCfg->DPSLPtoSLP)<<1));    
            if(SbCfg->ShortC3C4Mode)
            {
                AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_MULTI_FUN_SEL_2), 0x80, 0x80);
                AsiaIoModifySave8(PmioBar + PMIO_SLOW_C4_C5_WAKEUP_EVENT_CTL_Z1, 0x40, 0x40);
                AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x80, 0x80);
                switch(SbCfg->VRDSLPtoDPSLP)
                {
                case VRDSLP_TO_DPSLP_11:
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1), 0x80, 0x80);
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PULL_UP_OPTION), 0x40, 0x40);
                    break;
                case VRDSLP_TO_DPSLP_00:
                case VRDSLP_TO_DPSLP_01:
                default:
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1), 0x80, 0x00);
                    break;			
                }
            }
            else
            {
                AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_MULTI_FUN_SEL_2), 0x80, 0x00);
                switch(SbCfg->VRDSLPtoDPSLP)
                {
                case VRDSLP_TO_DPSLP_11:
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1), 0x80, 0x80);
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PULL_UP_OPTION), 0x40, 0x40);
                    break;
                case VRDSLP_TO_DPSLP_10:
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1), 0x80, 0x80);
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PULL_UP_OPTION), 0x40, 0x00);
                    break;				
                case VRDSLP_TO_DPSLP_00:
                case VRDSLP_TO_DPSLP_01:
                default:
                    AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1), 0x80, 0x00);
                    break;			
                }			
            }
			break;
        case FIX_FREE_CX_LATENCY_FREE_WITH_SLOW_MODE:
        case FIX_FREE_CX_LATENCY_FREE:	
            AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_WATCHDOG_TIMER_CTL_C3_LATENCY_CTL), 0x04, 0x04);
            AsiaIoWriteSave8 (PmioBar + PMIO_C4_EXIT_LATENCY_CTL_TIMER, 0x2A);		
            AsiaIoWriteSave8 (PmioBar + PMIO_C5_EXIT_LATENCY_CTL_TIMER, 0x2A);		
            AsiaIoWriteSave8 (PmioBar + PMIO_CX_STATE_ENTRY_LATENCY_CTL_TIMER, 0xFF);	
	    ///MTN-20181120 -S to Patch for P state + Cx state Enable Toggther Win10 x32 USB camera preview and six USB copy/compare randomly hang issue
	    if ((SbCfg->ProcessorCState == PROCESSOR_CSTATE_C2_C4_UPDOWN_MODE) || (SbCfg->ProcessorCState == PROCESSOR_CSTATE_C2_C3_UPDOWN_MODE))	
	   {
		  AsiaIoWriteSave8 (PmioBar + PMIO_CX_STATE_EXIT_LATENCY_CTL_TIMER,  0xFF);
	   }
	   else
	   {
		   AsiaIoWriteSave8 (PmioBar + PMIO_CX_STATE_EXIT_LATENCY_CTL_TIMER,  0xF4);
	   }
	  ///MTN-20181120 -E
	
			if((SbCfg->DynamicT05) && (SbCfg->ProcessorCState >= PROCESSOR_CSTATE_C2_C4))
            {
                AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PROCESSOR_CTL), 0x08, 0x08);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_1_1,   0x0A);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_1_2, 0x0A);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_2,   0x12);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_2+1, 0x0C);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_3,   0x1E);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_3+1, 0x12);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_4,   0x3C);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_4+1, 0x18);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_5_1, 0x5A);
                AsiaIoWriteSave8 (PmioBar + PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_5_2, 0x21);
			}
			else
			{
                AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PROCESSOR_CTL), 0x08, 0x00);
			}
			break;		 	
        default:
			break;
        }		
		
        if(SbCfg->ProcessorCState > PROCESSOR_CSTATE_C2_C3_UPDOWN_MODE)
        {
      		//Inhibit C3/C4 when HD Audio Big Format Data
            if(SbCfg->GoNonSnoopPath == FALSE)
            {
                AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_PROCESSOR_CTL), 0x20, 0x20); 
            }
            if(SbCfg->C4BusMasterIdleTimer)
            { 
                AsiaIoWriteSave8(PmioBar + PMIO_C2_DOWN_TO_C4_IDLE_TIMER, SbCfg->C4BusMasterIdleTimer); 
            }
            else
            {
                AsiaIoWriteSave8(PmioBar + PMIO_C2_DOWN_TO_C4_IDLE_TIMER, 0x00); 
            }	
        }
    }

    if(SbCfg->SBDynamicClkControl)
    {
		if(SbCfg->Uart0Enable == TRUE)
		{   
		    //PCI UART FLR Limitation:D10Fx Rx70[7] Must be free run when PCCA D17F7 RxE2[1]=1(Free Run),
		    //D10Fx Rx70[7] don't be cared when PCCA D17F7 RxE2[1]=0(Dynamic Run)
			if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
                 		AsiaPciModifySave32((CHX002_UART0|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x0000);
 			}
             	}
		if(SbCfg->Uart1Enable == TRUE)
		{
			if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
                 		AsiaPciModifySave32((CHX002_UART1|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x0000);
 			}
             	}
		////if(SbCfg->Uart2Enable == TRUE)
		///{
		///	if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
         ///        		AsiaPciModifySave32((CHX002_UART2|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x0000);
 		///	}
        ///     	}
		///if(SbCfg->Uart3Enable == TRUE)
		///{
		///	if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
        ///         		AsiaPciModifySave32((CHX002_UART3|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x0000);
 		////	}
        ////     	}			

        // SB
        AsiaPciModifySave8((CHX002_BUSC|D17F0_MISC_CTL_Z1), 0x01, 0x01);//D17F0 Rx5B[0]=1
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CLK_SEL_ENABLE), 0x4, 0x0); ///HOST_SMB, Cklatch DNT_SMBRAMCK33 output dynamic clock.
        
        // SNMI
        AsiaPciModifySave8((CHX002_PCCA|D17F7_SOUTH_NORTH_MODULE_IF_CTL_Z1), 0xC0, 0x00);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_DYNAMIC_CLK_CTL_1), 0xC0, 0x80);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_PCI1_INTERNAL_33_66MHZ_DYNAMIC_CLK_CTL), 0x60, 0x60);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_DYNAMIC_CLK_CTL_3), 0x1E, 0x00);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_CCA_DYNAMIC_CLK_DEBUG), 0x3F, 0x00);
        if(SbCfg->Azalia == TRUE){
	        AsiaPciModifySave8((CHX002_HDAC|D20F0_BACK_DOOR), 0x40, 0x00);//D20F0 Rx42[6]=0 Enable the gating
        }
	
    }
    else
    {
        // UART
		if(SbCfg->Uart0Enable == TRUE)
		{
		 // PCI UART FLR Limitation:D10Fx Rx70[7] Must be free run when PCCA D17F7 RxE2[1]=1(Free Run),
		 //D10Fx Rx70[7] don't be cared when PCCA D17F7 RxE2[1]=0(Dynamic Run)
			if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
				AsiaPciModifySave32((CHX002_UART0|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x8080);
 			}
             	}
		if(SbCfg->Uart1Enable == TRUE)
		{
			if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
				AsiaPciModifySave32((CHX002_UART1|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x8080); 
 			}
             	}
		///if(SbCfg->Uart2Enable == TRUE)
		///{
		///	if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
		///		AsiaPciModifySave32((CHX002_UART2|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x8080); 
 		////	}
        ///     	}
		////if(SbCfg->Uart3Enable == TRUE)
		///{
		///	if(SbCfg->UartModuleSelection== UART_MODULE_SEL_PCIDMA){
		///		AsiaPciModifySave32((CHX002_UART3|D10F0F1_UARTCFG_BAKUP_REG), 0x8080, 0x8080); 
 		///	}
       ///      	}			

        // SB
        AsiaPciModifySave8((CHX002_BUSC|D17F0_MISC_CTL_Z1), 0x01, 0x00);//D17F0 Rx5B[0]=0
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CLK_SEL_ENABLE), 0x4, 0x4); ///HOST_SMB, Cklatch DNT_SMBRAMCK33 output free clock.
        // SNMI
        AsiaPciModifySave8((CHX002_PCCA|D17F7_SOUTH_NORTH_MODULE_IF_CTL_Z1), 0xC0, 0xC0);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_DYNAMIC_CLK_CTL_1), 0xC0, 0x40);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_PCI1_INTERNAL_33_66MHZ_DYNAMIC_CLK_CTL), 0x60, 0x00);
        AsiaPciModifySave8((CHX002_PCCA|D17F7_DYNAMIC_CLK_CTL_3), 0x1E, 0x1E); //Bit1=1 Must Be Sync With D10Fx Rx70[7]=1.Bit1=0,don't care.
        AsiaPciModifySave8((CHX002_PCCA|D17F7_CCA_DYNAMIC_CLK_DEBUG), 0x3F, 0x3F);
        if(SbCfg->Azalia == TRUE){
	        AsiaPciModifySave8((CHX002_HDAC|D20F0_BACK_DOOR), 0x40, 0x40);//D20F0 Rx42[6]=1 Disable the gating
        }

    }	    

	//if(SbCfg->TMRCDynamicClkControl)
	//{
		//AsiaPciModifySave8((CHX002_BUSC|D17F0_SM_DEBUG_CTL), 0x4, D17F0_ENTMRCCLK); ///Enable TMRC Dynamic Clock 
	//}
    //else
	//{
        //AsiaPciModifySave8((CHX002_BUSC|D17F0_SM_DEBUG_CTL), 0x4, 0x0); ///Disable TMRC Dynamic Clock 
    //}
	



    if(SbCfg->SMBusControllerUnderOS)
    {
        SmbusBar = AsiaPciRead16(CHX002_BUSC|D17F0_PMU_SMBUS_IO_BASE);
		SmbusBar &= D17F0_PMU_SMBIOA;
		AsiaIoWriteSave8(SmbusBar + SMIO_SMBUS_HOST_STA,0xDE);
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CFG),0x0A, 0x0A);	
	}
	else
    {
        AsiaPciModifySave8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CFG),0x0A, 0x00);	    
    }

//MTN-20170420-Start
	//Data16 = AsiaIoRead16(PmioBar + PMIO_SME_PWR_GATING);
	//if ((Data16 & BIT0) == 0)
	//{
	//	AsiaIoModifySave8(PmioBar + PMIO_SME_PWR_GATING, 0x20, 0x00);//Disable SME clock	
	//} else {
	//	if ((Data16 & BIT5) == 0)
	//	{
	//		AsiaIoModifySave8(PmioBar + PMIO_SME_PWR_GATING, 0x20, 0x20);//Enable SME clock	
	 //   }
		
	//}
	//MTN-20170420-END

	
    return EFI_SUCCESS;
}
