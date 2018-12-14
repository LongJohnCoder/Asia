/** @file
   ZX-E(CHX002) Asia SbPei library functions : SbInit.c

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
#include EFI_PPI_DEFINITION(AsiaSbPpi)
#include "CHX002Reg.h"
#include "AsiaSbPeim.h"
#include "AsiaIoLib.h"
#include "CHX002Cfg.h"
#include "SbLibPpi.h"
#include "SbDriving.h"
#include "AsiaCommon.h"
#include "SataPei.h"
#include "UsbPei.h"
#include "CpuIA32.h"
#include "LegacybusSI.h"
#ifdef IOE_EXIST
#include "..\CND003\IoePreInit.h"
#include "..\CND003\IoeSata.h"
#include "..\CND003\IoeUsb.h"
#include "CND003Reg.h"
#endif

#include "AsiaInitCfgStructDefval.h"


EFI_STATUS
PeiSbSetGpo (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_GPIO Index,
    IN BOOLEAN Value
);

EFI_STATUS
PeiSbGetGpi (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_GPIO Index,
    OUT BOOLEAN* Value
);

EFI_STATUS
EFIAPI
PeiGetAcpiTimerValue(
  IN EFI_PEI_SERVICES **PeiServices,
  IN ASIA_SB_LIB_PPI *This,
  OUT UINT32 *Value,
  OUT BOOLEAN *Extended OPTIONAL
);


//ASIA_SB_CONFIGURATION mDefaultSbConfiguration = ASIA_SB_DEFAULT_CONFIGURATION;

/////
STATIC ASIA_IO_TABLE_6408_REV mSbPeiInitTbl[] =
{ 
    //mVer MVer	        Reg Offset                  Mask  Value	
    ///////////////////////D17F0BusCtrl///////////////////////
    {0x00, 0xFF, (CHX002_BUSC|D17F0_ISA_BUS_CTL),               0x44,   0x44}, // Rx40 bit[6]0->1,bit[2] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_LINE_BUFFER_CTL),           0xf4,   0xf4}, // Rx42 bit[7] 0->1,bit[6:4] 000->111,bit[2] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_DELAY_TRANSACTION_CTL),     0x03,   0x03}, // Rx43 bit[1:0] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_IDE_INTR_SEL),              0xC0,   0x40}, // Rx4C bit[7:6] 00->01     
    {0x00, 0xFF, (CHX002_BUSC|D17F0_INTERNAL_RTC_TEST_MODE_AND_EXTRA_FEATURE_CTL), 0x08,   0x08}, // Rx4E bit[3] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_SERIAL_IRQ_PCI_DMA_CTL_AND_LPC_CTL),           0x0B,   0x09}, // Rx52 bit[3] 0->1 , bit[1:0] 00->01
    {0x00, 0xFF, (CHX002_BUSC|D17F0_SOUTH_MODULE_MISC_CTL_1),   0x02,   0x02}, // Rx58 bit[1] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_SOUTH_MODULE_MISC_CTL_2),   0x80,   0x80}, // Rx59 bit[7] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_MISC_CTL_Z1),               0x0A,   0x0A}, // Rx5B bit[3,1] 0->1
    {0x00, 0xFF, (CHX002_BUSC|D17F0_MISC_CTL_2),                0x02,   0x02}, // Rx6E bit[1] 0->1

    ///////////////////////D17F0 PMU //////////////////////////
    {0x00, 0xFF, (CHX002_BUSC|D17F0_PMU_IRQN_AS_PRIMARY_INTR),      0xFF,   0xCA}, // Rx84
    {0x00, 0xFF, (CHX002_BUSC|D17F0_PMU_IRQN_AS_PRIMARY_INTR + 1),  0xFF,   0x50}, // Rx85
    {0x00, 0xFF, (CHX002_BUSC|D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE), 0x02,	 0x02}, // Rx8A MTN_20160420
    {0x00, 0xFF, (CHX002_BUSC|D17F0_PMU_MISC_CFG_2_PWR_WELL), 0x04,	 0x04}, // Rx95 MTN_20161014
    {0x00, 0xFF, (CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CFG),            0x01,   0x01}, // RxD2 MTN_20160420


    ///////////////////////D17F7///////////////////////

#ifdef EC_PS2KBC_SUPPORT
    {0x00, 0xFF, (CHX002_BUSC|D17F0_FUN_CTL_2),           0x05, 0x00}, // Rx51           // Disable Internal KBC/Mouse
    {0x00, 0xFF, (CHX002_BUSC|D17F0_SOUTH_MODULE_MISC_CTL_2), 0x1C,   0x1C}, // Rx59   // Enable LPC EC Decode
#endif
};

////
STATIC ASIA_IO_TABLE_6408_REV SB_Pmio_Safe_TBL[]= {
    //mVer MVer	Reg Offset		             Mask	    Value
    {0x00, 0xFF, PMIO_GLOBAL_TRIGGER_MODE_CTL,	PMIO_PBTN_POL,    BIT0},
};

/**
  Create ASIA_SB_CFG Struct hob
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Buffer point to ASIA_SB_CONFIG struct buffer

  @return EFI_STATUS.

**/
EFI_STATUS CreateAsiaSbCfgHob (
  IN EFI_PEI_SERVICES **PeiServices,
  OUT VOID **Buffer
  )
{
  EFI_STATUS Status;
  VOID* pSbCfgHob;
  EFI_PEI_HOB_POINTERS SbCfgHobPtr;
  EFI_GUID AsiaSbCfgGuid = ASIA_SB_CFG_HOB_GUID;
  ASIA_SB_CONFIGURATION* SbCfg;
  // Create Hob for SbCfg, link the buffer in the Hob to SbPpi.
  Status = (*PeiServices)->CreateHob(
    PeiServices,
    EFI_HOB_TYPE_GUID_EXTENSION,
    sizeof(EFI_HOB_GUID_TYPE) + sizeof(ASIA_SB_CONFIGURATION),
    &pSbCfgHob
    );
  if(EFI_ERROR(Status))
    return Status;
  
  SbCfgHobPtr.Raw = pSbCfgHob;
  SbCfgHobPtr.Guid->Name = AsiaSbCfgGuid; // Use ASIA_SB_CFG_HOB_GUID
  // Output content pointer of the hob
  *Buffer = (VOID*)((UINT8*)(&(SbCfgHobPtr.Guid->Name)) + sizeof(EFI_GUID));
  SbCfg = (ASIA_SB_CONFIGURATION*)(*Buffer);

  // Initialize SbCfg to all 0
  (*PeiServices)->SetMem(*Buffer, sizeof(ASIA_SB_CONFIGURATION), 0);

  return EFI_SUCCESS;
}

////
/**
  Dump ASIA_SB_CONFIG struct.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param pSbCfg point to ASIA_SB_CONFIG struct buffer

  @return EFI_STATUS.

**/

VOID DumpAsiaSbCfgStructDefaultValue(
       IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_SB_CONFIGURATION* pSbCfg)
{
	//// Dump ASIA SB Cfg struct's default value
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n\n Begin to dump Asia SB Cfg Struct default value \n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"************************ \n"));

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->Signature = %x \n",pSbCfg->Signature));
	//Chipset
	////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SOCXHCISPEValue = %x \n",pSbCfg->SOCXHCISPEValue));
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SOCEHCISPEValue = %x \n",pSbCfg->SOCEHCISPEValue));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SOCUHCISPEValue = %x \n",pSbCfg->SOCUHCISPEValue));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOVEnable = %x \n",pSbCfg->IOVEnable));

	//UART
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->Uart3Enable = %x \n",pSbCfg->Uart3Enable));
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->Uart3IoBaseSelection = %x \n",pSbCfg->Uart3IoBaseSelection));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->Uart3IRQSelection = %x \n",pSbCfg->Uart3IRQSelection));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->UartFLREn = %x \n",pSbCfg->UartFLREn));	


	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMVCLKControl = %x \n",pSbCfg->SVIDMVCLKControl));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMPeriodicIoutControl = %x \n",pSbCfg->SVIDMPeriodicIoutControl));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMC3Control = %x \n",pSbCfg->SVIDMC3Control));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMC4C5Control = %x \n",pSbCfg->SVIDMC4C5Control));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->VRMStableBD = %x \n",pSbCfg->VRMStableBD));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMC4SetPS = %x \n",pSbCfg->SVIDMC4SetPS));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->CPU2SVIDCmdGate = %x \n",pSbCfg->CPU2SVIDCmdGate));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->CPUPStateTOCounter = %x \n",pSbCfg->CPUPStateTOCounter));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->CPUPStateSetVIDDone = %x \n",pSbCfg->CPUPStateSetVIDDone));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->VRM0VIDFSSelect = %x \n",pSbCfg->VRM0VIDFSSelect));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMC4SetPSSel = %x \n",pSbCfg->SVIDMC4SetPSSel));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMC4DecayOP = %x \n",pSbCfg->SVIDMC4DecayOP));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->SVIDMC4SetVIDSel = %x \n",pSbCfg->SVIDMC4SetVIDSel));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->VRM0IoutTimer = %x \n",pSbCfg->VRM0IoutTimer));

	
	//PMU_ACPI
	//C-State Control
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->ShortC3C4Mode = %x \n",pSbCfg->ShortC3C4Mode));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->DPSLPtoSLP = %x \n",pSbCfg->DPSLPtoSLP));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->VRDSLPtoDPSLP = %x \n",pSbCfg->VRDSLPtoDPSLP));	
	
	///
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->UsbS4WakeupCtrl = %x \n",pSbCfg->UsbS4WakeupCtrl));
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->XhcC4BlockCtrl = %x \n",pSbCfg->XhcC4BlockCtrl));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->UsbOCCtrl = %x \n",pSbCfg->UsbOCCtrl));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->XhcEITRNCtrl = %x \n",pSbCfg->XhcEITRNCtrl));	
		
	//HDAC 
	//pSbCfg->Azalia=FALSE;
	//pSbCfg->GoNonSnoopPath=FALSE;
	//pSbCfg->HDACFLREn=TRUE;
	//SNMI
	//pSbCfg->IsoLPC=FALSE;
	//pSbCfg->IsoVART=FALSE;
	//pSbCfg->IsoAZALIA=FALSE;
	//pSbCfg->IsoESPI=FALSE;
	//pSbCfg->IsoSPI=FALSE;
	//pSbCfg->IsoAPIC=FALSE;
	//Others
	//pSbCfg->EnableMultimediaTimer=TRUE;
	//pSbCfg->MultimediaTimerMode=0;
	//pSbCfg->EnableMultimediaTimerMsi=0;
	//pSbCfg->WatchDogTimer=TRUE;
	//pSbCfg->WatchDogTimerRunStop=WATCHDOG_TIMER_STOP;
	//pSbCfg->WatchDogTimerAction=WATCHDOG_TIMER_ACTION_POWEROFF;
	//pSbCfg->WatchDogTimerCount=WATCHDOG_TIMER_COUNT_1023S;
	//pSbCfg->KBMouseWakeupControl=TRUE;
	//pSbCfg->SMBusControllerUnderOS=FALSE;
	//pSbCfg->SMBHostClockFrequencySelect=FALSE;
	//pSbCfg->SMBHostClockFrequency=0x16;
	//pSbCfg->SPIBus0ClockSelect=SPI_BUS0_CLK_48MHZ;
	//pSbCfg->ESPI=FALSE;
	//pSbCfg->FsbcMemSize=0;
	//pSbCfg->ApicEnable=TRUE;
	//pSbCfg->AcpiIrq=0x9;
	//pSbCfg->PmioBar=0x800;
	//pSbCfg->ApicBar=0xFEC00000;
	//pSbCfg->SbApicID=0x09;
	//pSbCfg->HpetBar=0xFEB40000;
	//pSbCfg->WatchDogBar=0xFEB41000;
	//pSbCfg->D17F0MmioBar=0xFEB32000;
	//pSbCfg->SpiBar=0xFEB30000;
	//pSbCfg->VidSelect=VID_OTHER;
	//pSbCfg->ZxeDualSocket=ZX_SINGLE_SOCKET_MODE;
	//CND003/IOE related
	//pSbCfg->IOESPEValue=CHIP_SPE_VALUE_STABLE;
	//pSbCfg->IOEGNICSPEValue=DEVICE_SPE_VALUE_STABLE;
	//pSbCfg->IOESATASPEValue=DEVICE_SPE_VALUE_STABLE;
	//pSbCfg->IOEXHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	//pSbCfg->IOEEHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	//pSbCfg->IOEUHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	//CND003 TOP
	//pSbCfg->IoeChipRevision=0;
	//pSbCfg->Cnd003ModeSel=0;
	//pSbCfg->Cnd003DebugFromCpu=0;
	//pSbCfg->Cnd003ModuleG0=0;
	//pSbCfg->Cnd003ModuleG1=0;
	//pSbCfg->Cnd003DebugG0=0;
	//pSbCfg->Cnd003DebugG1=0;
	//pSbCfg->Cnd003DebugG2=0;
	//pSbCfg->Cnd003DebugG3=0;
	//pSbCfg->Cnd003DebugG0_XHCI=0;
	//pSbCfg->Cnd003DebugG1_XHCI=0;
	//pSbCfg->Cnd003DebugG2_XHCI=0;
	//pSbCfg->Cnd003DebugG3_XHCI=0;
	//pSbCfg->Cnd003HighSpeed=0;
	//pSbCfg->Cnd003DebugSuspend=0;
	//pSbCfg->Cnd003HighSpeedModuleSel=0;
	//pSbCfg->Cnd003HighSpeedDbgSel=0;
	//pSbCfg->Cnd003CorePowerOff=0;
	//pSbCfg->Cnd003DbgPadG0En=1;
	//pSbCfg->Cnd003DbgPadG1En=1;
	//pSbCfg->Cnd003DbgPadG2En=1;
	//pSbCfg->Cnd003DbgPadG3En=1;
	//pSbCfg->Cnd003UartPinEn=0;
	//DBGCAP
	//pSbCfg->Cnd003DC=0;
	//pSbCfg->Cnd003DCModule=0;
	//pSbCfg->Cnd003DCTrans=0;
	//pSbCfg->Cnd003DCCfgPath=0;
	//pSbCfg->Cnd003DCChannel=0;
	//pSbCfg->Cnd003DCDbg0Mask=0;
	//pSbCfg->Cnd003DCDbg1Mask=0;
	//pSbCfg->Cnd003DCTriggerMode=0;
	//pSbCfg->Cnd003DCReqPtn=0;
	//pSbCfg->Cnd003DCReqPtnMask=0;
	//pSbCfg->Cnd003DCDataPtnMask=0;
	//pSbCfg->Cnd003DCPlusTimer=0;
	//pSbCfg->Cnd003DCStartTimer=0;
	//pSbCfg->Cnd003DCPeriodTimer=0;
	//pSbCfg->Cnd003DCOutput=1;
	//pSbCfg->Cnd003HideXbctl=0;
	//pSbCfg->Cnd003HideEptrfc=0;
	//IOE_GNIC
	//pSbCfg->IOEGnicTXDC1=0;
	//pSbCfg->IOEGnicTXDC2=0;
	//pSbCfg->IOEGnicRXDCS=1;
	//pSbCfg->IOEGnicRXDC0=0xFF;
	//pSbCfg->IOEGnicRXDC1=0;
	//pSbCfg->IOEGnicRXDC2=0;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEGnicEn = %x \n",pSbCfg->IOEGnicEn));
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEGnicVEEPROM = %x \n",pSbCfg->IOEGnicVEEPROM));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEGnicTXDCS = %x \n",pSbCfg->IOEGnicTXDCS));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEGnicTXDC0 = %x \n",pSbCfg->IOEGnicTXDC0));	
	
	//pSbCfg->IOEGnicDPDC64=0;
	//pSbCfg->IOEGnicDPDC128=0;
	//pSbCfg->IOEGnicDPDC256=0;
	//pSbCfg->IOEGnicForceSizeEn=0;
	//pSbCfg->IOEGnicForceRDR=0;
	//pSbCfg->IOEGnicForcePayload=0;
	//pSbCfg->IOEGnicEventCtrl=0;
	//pSbCfg->IOEGnicPendingCtrl=0;
	//pSbCfg->IOEGnicMsiCtrl=TRUE;
	//pSbCfg->IOEGnicMsiXCtrl=TRUE;
	//pSbCfg->IOEGnicD0PME=TRUE;
	//IOE_SATA
	//pSbCfg->IOESataEn=TRUE;
	//pSbCfg->IOESataCfg=0;
	//pSbCfg->IOEAHCIGen=1;
	//pSbCfg->IOESataGen=1;
	//pSbCfg->IOEAHCI_MSI=0;
	//pSbCfg->IOEAHCI_MSIX=0;
	//pSbCfg->IOESataCapSelect=0;
	//pSbCfg->IOESataHIPMEn=0;
	//pSbCfg->IOESataHpcpEn=0;
	//pSbCfg->IOESataALPMEn=1;
	//pSbCfg->IOEFunctionLevelEnabled=0;
	// CND003 USB
	//pSbCfg->IOEUsbModeSelect=IOEUSB_MODE_SEL_MODEC;
	//pSbCfg->IOETRBCacheBypass=IOETRB_CACHE_NOT_BYPASS;
	//pSbCfg->IOEXhciOutBurstEn=IOEUSB_OUTBURST_ENABLE;
	//pSbCfg->IOEXhciMaxBurstSize=IOEUSB_MAXBURSTSIZE_DISABLE;
	//pSbCfg->IOEUSBCFLRControl=IOEUSBC_FLR_ENABLE;
	//pSbCfg->IOEXHCIFLRControl=IOEXHCI_FLR_ENABLE;
	//pSbCfg->IOERTD3Control=IOERTD3_ENABLE;
	//pSbCfg->IOEUsbS4Wakeup=FALSE;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEUsbC4Block = %x \n",pSbCfg->IOEUsbC4Block));
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEUsb10GSupport = %x \n",pSbCfg->IOEUsb10GSupport));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEUsbOCEn = %x \n",pSbCfg->IOEUsbOCEn));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pSbCfg->IOEUsbEITRN = %x \n",pSbCfg->IOEUsbEITRN));	

       ////
       PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n ************************ \n"));
       PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of dump Asia SB Cfg Struct default value \n"));	 
	/////
}

////

/**
  Init ASIA SB Private Struct hob
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param PrvData point to ASIA_SB_PEI_PRIVATE_DATA struct buffer

  @return EFI_STATUS.

**/

EFI_STATUS
InitSbPrivateData(
    IN EFI_PEI_SERVICES **PeiServices,
    OUT ASIA_SB_PEI_PRIVATE_DATA *PrvData
)
{
    EFI_STATUS Status;
    VOID* pSbCfg=NULL; 
    ASIA_SB_LIB_PPI *SbLibPpi=NULL;

    if (NULL == PrvData || ASIA_SB_PEI_PRIVATE_DATA_SIGNATURE != PrvData->Signature)
        return EFI_INVALID_PARAMETER;
    PrvData->DeviceID = AsiaPciRead16( CHX002_BUSC | D17F0_DID); 
    ////PrvData->ChipsetVersion = AsiaPciRead8( CHX002_BUSC | D17F0_PMU_INTERNAL_REV_ID);///MTN_0317
	/*set default param*/
    Status = CreateAsiaSbCfgHob(PeiServices, &pSbCfg);
    PrvData->AsiaSbPpi.SbCfg = pSbCfg;
    //(*PeiServices)->CopyMem(PrvData->AsiaSbPpi.SbCfg,&mDefaultSbConfiguration, sizeof(ASIA_SB_CONFIGURATION));
    InitSbCfgStructDefaultValue(pSbCfg); // AsiaPlatformLib implement it. TGR-20180509001
    DumpAsiaSbCfgStructDefaultValue(PeiServices,pSbCfg);
	/*init sb lib ppi*/
    Status = (*PeiServices)->AllocatePool(
                 PeiServices,
                 sizeof(ASIA_SB_LIB_PPI),
                 &(SbLibPpi)
             );
    if (NULL == SbLibPpi)
        return EFI_OUT_OF_RESOURCES;

    //SbLibPpi->PmioBaseAddress = ((ASIA_SB_CONFIGURATION*)SbCfg)->PmioBar;
	SbLibPpi->GetGpi = PeiSbGetGpi;
	SbLibPpi->SetGpo = PeiSbSetGpo;
    SbLibPpi->GetAcpiTimerValue = PeiGetAcpiTimerValue;
	PrvData->PpiDesc[0].Ppi = SbLibPpi;

    return EFI_SUCCESS;
}

/**
  Disable USB Related functions.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Buffer point to ASIA_SB_CONFIG struct buffer

  @return VOID.

**/

VOID SB_Disable_Func(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_SB_CONFIGURATION *SbCfg)
{
    
    AsiaIoModify8(0x880,0x8,0x0); //disable XHCI PMIO Rx80[3]
    PEI_DEBUG((PeiServices, EFI_D_INFO, "Disable xHCI Function: PMIORx80=%x\n", AsiaIoRead8(0x880)));
    AsiaPciModify8((CHX002_BUSC | D17F0_FUN_CTL_1), BIT2|BIT4|BIT5, 0x0);//disable UHCI: D17F0 Rx50
    PEI_DEBUG((PeiServices, EFI_D_INFO, "Disable UHCI Function: D17F0 PCI Rx50=%x\n",  AsiaPciRead8(CHX002_BUSC | D17F0_FUN_CTL_1)));
    AsiaMemoryModify8(SbCfg->D17F0MmioBar+D17F0MMIO_DEV_FUN_ENABLE,BIT0|BIT3,0x0);//disable EHCI
    PEI_DEBUG((PeiServices, EFI_D_INFO, "Disable EHCI Function: D17F0 MMIO Rx40=%x\n",   AsiaMemoryRead8(SbCfg->D17F0MmioBar+D17F0MMIO_DEV_FUN_ENABLE)));

}

/**
  PeiSbTALinkageInit.

  TA related init.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Buffer point to ASIA_SB_CONFIG struct buffer

  @return VOID.

**/
VOID PeiSbTALinkageInit(IN EFI_PEI_SERVICES **PeiServices,ASIA_SB_CONFIGURATION* SbCfg)
{
#ifdef ZX_DUALSOCKET
	UINT8 SlaveBusNum = SbCfg->ZxeSlaveBusNum;
#endif

	//if TACTL is enabled, SW must make sure the PCCA's prefetch will not cross 4K boundary.
	if(SbCfg->IOVEnable)
	{
    	PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]PeiSbTALinkageInit()\n"));
		//Control CCA cross 4K prefetch for internal device P2C read cycle
    	AsiaPciModify8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, CHX002_BUSC_DEV, CHX002_PCCA_FUN, D17F7_PCI_MASTER_CTL), D17F7_PRFH_4K_DISABLE, D17F7_PRFH_4K_DISABLE);
#ifdef ZX_DUALSOCKET
		AsiaPciModify8(ASIA_PCI_ADDRESS(SlaveBusNum, CHX002_BUSC_DEV, CHX002_PCCA_FUN, D17F7_PCI_MASTER_CTL), D17F7_PRFH_4K_DISABLE, D17F7_PRFH_4K_DISABLE);
#endif

		//the declaration for SPIC in ACPI namespace will occur if IOV is enabled, so SW should config SPIC Interrupt IRQ 5 here.
		//spi acpi device
		AsiaMemoryModify8(SbCfg->D17F0MmioBar + D17F0MMIO_SPI_BUS_INTR_ROUTING_CTL, D17F0MMIO_SPIRQSEL_3_0, 5);
	}
}


/**
  SVID related init funciton.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Buffer point to ASIA_SB_CONFIG struct buffer

  @return EFI_STATUS.

**/

VOID PeiSbSVIDInit(IN EFI_PEI_SERVICES **PeiServices,ASIA_SB_CONFIGURATION* SbCfg)
{

	///JYZ_Added_Svid
#if defined(HX002EA0_03)||defined(HX002EC0_01)||defined(HX002EC0_10)||defined(HX002ED0_02)||defined(HX002ED0_10)||defined(HX002EE0_04)||defined(HX002EE0_05)||defined(HX002EH0_01)||defined(HX002EL0_05)
	 ///UINT64	 MsrVal =0;
	 UINT8   Iout8 =0;
	 UINT16 PmioBaseAddress;

	 PEI_DEBUG((PeiServices, EFI_D_INFO, "[MTN]: PeiSbSVIDInit()\n"));

	 PmioBaseAddress =SbCfg->PmioBar;
	  ///JYZ_201803126 Start
	  if (SbCfg->SVIDMVCLKControl == 1)
	  {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_CTL_REG, MMIO_SVIDM_CG, MMIO_SVIDM_CG);
	  }
	  else
	  {
		  AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_CTL_REG, MMIO_SVIDM_CG, 0);
	  }
	  
	  if (SbCfg->SVIDMPeriodicIoutControl == 1)
	  {
		  AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_CTL_REG, MMIO_VRM0_IOUT_EN, MMIO_VRM0_IOUT_EN);
		  Iout8 = SbCfg->VRM0IoutTimer;//HYL-2016110701  
		  AsiaMemoryWrite8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_PERIOD_READ_TIMER_REG,Iout8);
		  
	  }
	  else
	  {
		  AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_CTL_REG, MMIO_VRM0_IOUT_EN, 0);
	  }

	 if (SbCfg->SVIDMC3Control == 1)
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C3_CTL_REG, MMIO_SVID_C3_CTRL_DIS, MMIO_SVID_C3_CTRL_DIS);
	 }
	 else
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C3_CTL_REG, MMIO_SVID_C3_CTRL_DIS, 0);
	 }
	 
	 if (SbCfg->SVIDMC4C5Control == 1)
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_CTRL_DIS,MMIO_SVID_C4_CTRL_DIS);
		 
	 }
	 else
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG,MMIO_SVID_C4_CTRL_DIS,0);
	 }

	 if (SbCfg->VRM0VIDFSSelect == 1)
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_CTL_REG, MMIO_VRM0_VIDS, MMIO_VRM0_VIDS);
	 }
	 else
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_CTL_REG, MMIO_VRM0_VIDS, 0);
	 }

	 
	 if (SbCfg->SVIDMC4SetPS == 1)
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_PS_OP, 0);
		 if (SbCfg->SVIDMC4SetPSSel == 0)
		 {
			 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG,MMIO_SVID_C4_SETPS_SEL, 0);
		 }
		 else if(SbCfg->SVIDMC4SetPSSel == 0x01)
		 {
			 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_SETPS_SEL, 0x04);
		 }
		 
		 else if(SbCfg->SVIDMC4SetPSSel == 0x02)
		 {
			 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_SETPS_SEL, 0x08);
		 }
		 else 
		 {
			 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_SETPS_SEL, 0x0C);
		 }
		 
	 }
	 else
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_PS_OP, MMIO_SVID_C4_PS_OP);

	 }
	 
	 if (SbCfg->SVIDMC4DecayOP == 1)
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_DECAY_OP, MMIO_SVID_C4_DECAY_OP);
		 if (SbCfg->SVIDMC4SetVIDSel == 0)
		 {
			 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_SETVID_SEL,0);
			 
		 }
		 else
		 {
			 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG,MMIO_SVID_C4_SETVID_SEL,MMIO_SVID_C4_SETVID_SEL);
		 }
	 }
	 else
	 {
		 AsiaMemoryModify8(SbCfg->D17F0MmioBar + MMIO_SVID_MASTER_VRM0_C4_CTL_REG, MMIO_SVID_C4_DECAY_OP, 0);
		 
	 }

	 if (SbCfg->VRMStableBD == 1)
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_CHX002_DESIGN_BACKDOOR_REG_1, PMIO_VRM_STABLE_BD, PMIO_VRM_STABLE_BD);
	 }
	 else
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_CHX002_DESIGN_BACKDOOR_REG_1, PMIO_VRM_STABLE_BD, 0);
	 }

///MTN-20180725 -S
///Delete this According to CV John's Request  
#if 0	 
	 if (SbCfg->CPU2SVIDCmdGate == 0)
	 {
	 
	 //Set 0x1690 Bit8=0
		 MsrVal = EfiReadMsr(0x1690);
		 MsrVal &= (~0x100);
		 EfiWriteMsr(0X1690,MsrVal);
	 }
	 else
	 {
	 //Set 0x1690 Bit8=1
		 MsrVal = EfiReadMsr(0x1690);
		 MsrVal |=(1<<8);
		 EfiWriteMsr(0X1690,MsrVal);
	 }
	 
	 if (SbCfg->CPUPStateTOCounter == 1)
	 {
		  //Set 0x1690 Bit0=0
		   MsrVal = EfiReadMsr(0x1690);
		   MsrVal &=(~0x01);
		   EfiWriteMsr(0X1690,MsrVal);
	 }
	 else
	 {
		 //Set 0x1690 Bit0=1
		  MsrVal = EfiReadMsr(0x1690);
		  MsrVal |=0x01;
		  EfiWriteMsr(0X1690,MsrVal);
	 }
	 
	 if (SbCfg->CPUPStateSetVIDDone == 1)
	 {
		 //Set 0x1690 Bit7=0
		  MsrVal = EfiReadMsr(0x1690);
		  MsrVal &=(~0x80);
		  EfiWriteMsr(0X1690,MsrVal);
	 }
	 else
	 {
		 //Set 0x1690 Bit7=1
		  MsrVal = EfiReadMsr(0x1690);
		  MsrVal |=(1<<7);
		  EfiWriteMsr(0X1690,MsrVal);
	 }
#endif
///MTN-20180725 -E
	 
	 ///JYZ_20180326 End
#endif

}

/**
  Pei SB pre memory init function.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param This point to EFI_ASIA_SB_PPI

  @return EFI_STATUS.

**/

EFI_STATUS
PeiSbPreMemoryInit (
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_ASIA_SB_PPI *This
)
{
    ASIA_SB_PEI_PRIVATE_DATA *pPrvData = NULL;
    UINT16 PmioBaseAddress;
    ASIA_SB_CONFIGURATION *SbCfg;
    //UINT8 Data8;
    //UINT16 Data16;
//HYL-2018062901-start
#ifdef ZX_SECRET_CODE
    UINT32 temp32;	
#endif
//HYL-2018062901-end  
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiSbPreMemoryInit()\n"));
    pPrvData = GET_PRIVATE_DATA_FROM_ASIASBPPI(This);
    SbCfg = (ASIA_SB_CONFIGURATION *)(This->SbCfg);

  
    // Enable Pmio
    PmioBaseAddress =SbCfg->PmioBar;
    AsiaPciWrite16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE, PmioBaseAddress);
    AsiaPciModify8(CHX002_BUSC | D17F0_PMU_PM_GENERAL_CFG_2, D17F0_PMU_RENIO, D17F0_PMU_RENIO);///MTN_0317
    ((ASIA_SB_LIB_PPI *)(pPrvData->PpiDesc[0].Ppi))->PmioBaseAddress = PmioBaseAddress;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));

    // Set D17F0 MMIO Base Address and SPI Base Address
    AsiaPciModify32(CHX002_BUSC | D17F0_MMIO_SPACE_BASE_ADR,D17F0_F0MMIOBA_31_12, (UINT32)(SbCfg->D17F0MmioBar>>8));
    PEI_DEBUG((PeiServices, EFI_D_INFO, "D17F0 MMIOBar = 0x%8x \n",SbCfg->D17F0MmioBar ));
    PEI_DEBUG((PeiServices, EFI_D_INFO, "D17F0 SPI MMIOBar = 0x%8x \n",SbCfg->SpiBar ));
	// SATA Init
	SataInitPei(PeiServices, SbCfg);

		//USB Init
	UsbInitPei(PeiServices, SbCfg);
#ifdef IOE_EXIST
	IOEUsbPeiInit(PeiServices,SbCfg);
#endif

    //#ifdef CHX002_PXP
    //SB_Disable_Func(PeiServices, SbCfg);
    //#endif
    ///	
    AsiaMemoryModify32(SbCfg->D17F0MmioBar+D17F0MMIO_SPI_BUS_0_CTL, 0xFFFFFF00, (UINT32)(SbCfg->SpiBar));
    // Enable SPI
    AsiaMemoryModify8(SbCfg->D17F0MmioBar + D17F0MMIO_SPI_BUS_0_CTL, BIT0, BIT0);

	{
		UINT8 tmp8;
		// determine SEC phase set it ok or not.
      		tmp8 = AsiaMemoryRead8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_CLK_DIVIDER);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n **BF** \n SPI_MMIO : Rx6C = 0x%x \n",tmp8));	
	} 
	//disable spi interrupt and clear spi interrupt status because of sus dormain
	AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x12, 0x00); // Spi Mmio Rx6D[4]=0 ;Spi Mmio 6D[1]=0 
	AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_INTR_CTL, 0xFF, 0x00); // Spi Mmio 70[7:0]=0 
	AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_INTR_STA, 0xFF, 0xFF); // Spi Mmio 73[7:0]=0 ,write 1 to clear
	
	#ifndef ZX_SPICLK_SLOWDOWN

    // DLA_Dbg_20161011_S
     if(SbCfg->SPIBus0ClockSelect == SPI_BUS0_CLK_13MHZ)
    {
       AsiaMemoryModify8(SbCfg->SpiBar + 0x63, BIT0,0);// 63[0]=0.clock divide aviliable
       AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_CLK_DIVIDER, 0xFF, 0x01);// 6C
       AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x20, 0x00); // 6D[5]     	
       AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x80, 0x00);// 6D[7] 
    }	
    if(SbCfg->SPIBus0ClockSelect == SPI_BUS0_CLK_27MHZ)
    {
       AsiaMemoryModify8(SbCfg->SpiBar + 0x63, BIT0,0);// 63[0]=0,fast read disable ,read max frequency is 40Mhz
       AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_CLK_DIVIDER, 0xFF, 0x00);// 6C
       AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x20, 0x00);// 6D[5]       	
       AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x80, 0x00);// 6D[7] 
    }
	// DLA_Dbg_20161011_E
    if(SbCfg->SPIBus0ClockSelect == SPI_BUS0_CLK_48MHZ)
    {
	AsiaMemoryModify8(SbCfg->SpiBar + 0x63, BIT0, BIT0);// 63[0]=1;fast read enable
        AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_CLK_DIVIDER, 0xFF, 0x00);//SPI_MMIO_6C
        AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x20, 0x00);// 6D[5]        
        AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x80, 0x80);// 6D[7]
    }
	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113

    if(SbCfg->SPIBus0ClockSelect == SPI_BUS0_CLK_66MHZ)
    {
	AsiaMemoryModify8(SbCfg->SpiBar + 0x63, BIT0, BIT0);// 63[0]=1;fast read enable
        AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_CLK_DIVIDER, 0xFF, 0x00);//SPI_MMIO_6C
        AsiaMemoryModify8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_MISC_CTL_1, 0x20, 0x20);// 6D[5]
    }	
	#endif

	{
		UINT8 tmp8;
		tmp8 = AsiaMemoryRead8(SbCfg->SpiBar + SPI0MMIO_SPI_BUS_0_CLK_DIVIDER);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n **AF** \n SPI_MMIO : Rx6C = 0x%x \n",tmp8));	
	}

    PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113

    // Process SB Safe table
    PROCESS_SB_R6408M_TABLE(mSbPeiInitTbl, sizeof(mSbPeiInitTbl)/sizeof(ASIA_IO_TABLE_6408_REV));
    PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113
	
    // Init Pmio registers
    AsiaIoModify8(PmioBaseAddress + PMIO_EXTEND_SMI_IO_TRAP_STA, 0xFF, 0x0C);	//PMIO Rx40
    AsiaIoModify8(PmioBaseAddress + PMIO_SUSPEND_PWR_DOMAIN, 0x04, 0x04); 	//PMIO Rx6F, Enable soft resume	 	
    AsiaIoModify8(Misc_Func_SP_Ctl, 0x0C, 0x0C); //Rx61 // Disable IOCHK#, SERR#

	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));
	
    //dla_dbg_s
   /*
    //Patch HW Bug that time and calendar information of RTC are not BCD format default.
	 AsiaIoWrite8(CMOS_INDEX, 0x0B);
    Data8 = AsiaIoRead8(CMOS_DATA);
    Data8 &= ~0x04;
    AsiaIoWrite8(CMOS_DATA, Data8);
    */
	//dla_dbg_e
	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113

///#ifdef ZX_TPM_SUPPORT
///    AsiaPciModify8 ((CHX002_BUSC|D17F0_MISC_CTL),   0x01,       0x01); // Enable TPM function
///#endif

	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113

//;New SMBus Frequency Selection
    if(SbCfg->SMBHostClockFrequencySelect)
    {
	AsiaPciModify8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CLK_SEL_ENABLE), 0x01, 0x01);	// Enable SMBus Host Clock Select
	AsiaPciWrite8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CLK_SEL), SbCfg->SMBHostClockFrequency);	//Setup SMBus Host Clock
    }
    else
    {
	AsiaPciModify8((CHX002_BUSC|D17F0_PMU_SMBUS_HOST_CLK_SEL_ENABLE), 0x01, 0x00);	// Disable SMBus Host Clock Select
    }

	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113
	
	 ///MTN_20161018 Start
#ifdef ZX_SECRET_CODE
	 if (SbCfg->KBDCLegacySelControl == 1)
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x8, 0x8);
	 }
	 else
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x8, 0x0);
	 }
#endif

	 if (SbCfg->INTCLegacySelControl == 1)
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x4, 0x4);
	 }
	 else
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x4, 0x0);
	 }	 

	  if (SbCfg->DMACLegacySelControl == 1)
	 {
		  AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x2, 0x2);
	 }
	 else
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x2, 0x0);
	 }	  

#ifdef ZX_SECRET_CODE
	 if (SbCfg->TMRCLegacySelControl == 1)
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x1, 0x1);
	 }
	 else
	 {
		 AsiaIoModify8(PmioBaseAddress + PMIO_LGY_SEL_CTL_REG, 0x1, 0x0);
	 }	 
#endif
	 ///MTN_20161018 End
	 
	 PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113
	 
	 PeiSbSVIDInit(PeiServices, SbCfg);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113

	//;SME Power Gating
     //MTN-2016122901-Start
	//Data16=AsiaIoRead16(PmioBaseAddress + PMIO_SME_PWR_GATING);//HYL-2016110701
	//if ((Data16 & BIT0) != 0)
	//{
	//	Data16 = Data16 | ((SbCfg->eBMCSettleTime) << 8) ;//HYL-2016110701	
	//	AsiaIoWrite16(PmioBaseAddress + PMIO_SME_PWR_GATING, Data16);	
	//}
	//MTN-2016122901-End
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));//reter debug 1113

	//MTN-20170719 -s
    ///Disable GP3 Timer Start and Auto Reload Bit
	AsiaPciWrite8(CHX002_BUSC|D17F0_PMU_GP2_GP3_TIMER_CTL,0x10);
	//MTN-20170719 -e

	//JRZ:IOV related
	PeiSbTALinkageInit(PeiServices, SbCfg);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "%a(%d) ---\n",__FILE__,__LINE__));
	
	UpdateLegacySISetting();

//HYL-2018062901-start
#ifdef ZX_SECRET_CODE
	if((SbCfg->WDTClear == 1)|(SbCfg->WDTClear == 2)){
		//WDT base is 0xFEB41000
		AsiaPciWrite32((CHX002_BUSC|D17F0_PMU_WATCHDOG_TIMER_MEM_BASE), 0xFEB41000);
		//D17F0 RxEC[1:0]=11b
		AsiaPciModify8((CHX002_BUSC|D17F0_PMU_WATCHDOG_TIMER_CTL_C3_LATENCY_CTL), 0x03, 0x03);

		AsiaMemoryWrite32(0xFEB41004, 240);// 240sec
		AsiaMemoryWrite8(0xFEB41000, 0x03);	
		AsiaMemoryWrite8(0xFEB41000, 0x81); 
		while(1){
			temp32=AsiaMemoryRead32(0xFEB41004);
			if(temp32==240){
				break;
			}
		}	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Enable WDT Timer with 240 sec\n"));
	}
#endif
//HYL-2018062901-end  		

    return EFI_SUCCESS;
}

/**
  SB PEIM used 80 port output function.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Data target 80 port value.

  @return VOID.

**/

void PEI_PCIE_SB_80_PORT(IN EFI_PEI_SERVICES **PeiServices, UINT8 Data)
{
    UINT8 PostCodeValue=Data;
	AsiaIoWrite8(0x80,PostCodeValue);
	PEI_DEBUG((PeiServices,EFI_D_INFO, "POSTCODE=<%02x>\n", AsiaIoRead8(0x80)));
}

/**
  PeiSbPostMemoryInitS3()
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param This point to EFI_ASIA_SB_PPI

  @return EFI_STATUS.

**/

EFI_STATUS
PeiSbPostMemoryInitS3 (
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_ASIA_SB_PPI *This
)
{
#ifdef IOE_EXIST 
	ASIA_SB_CONFIGURATION *SbCfg;
#endif

    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiSbPostMemoryInitS3()\n"));
#ifdef IOE_EXIST 
	SbCfg = (ASIA_SB_CONFIGURATION *)(This->SbCfg);
  
	if(SbCfg->Cnd003ModeSel == BIOS_MODE){
		IOESataPeiInitS3(PeiServices, SbCfg);
	}
#endif 

	//JennyChen add for CHX002 80 port
	PEI_PCIE_SB_80_PORT(PeiServices, PEI_SB_POST_MEMORY_S3);   
    return EFI_SUCCESS;
}

/**
  PeiSbPostMemoryInit()
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param This point to EFI_ASIA_SB_PPI

  @return EFI_STATUS.

**/

EFI_STATUS
PeiSbPostMemoryInit (
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_ASIA_SB_PPI *This
)
{
    UINT16  PmioAddr;
    UINT8   i;
#ifdef IOE_EXIST	
	ASIA_SB_CONFIGURATION *SbCfg;	
#endif

    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiSbPostMemoryInit()\n"));

#ifdef IOE_EXIST
	SbCfg = (ASIA_SB_CONFIGURATION *)(This->SbCfg);
	if(SbCfg->Cnd003ModeSel == BIOS_MODE){
		IOESataPeiInit(PeiServices, SbCfg);
    }		
#endif

    // Process PMIO Safe table
    PmioAddr =( (ASIA_SB_CONFIGURATION* )(This->SbCfg))->PmioBar;
    for(i=0; i < sizeof(SB_Pmio_Safe_TBL)/sizeof(ASIA_IO_TABLE_6408_REV); i++)
    {
        AsiaIoModify8((UINT16)(SB_Pmio_Safe_TBL[i].Address+PmioAddr), (UINT8)(SB_Pmio_Safe_TBL[i].Mask), (UINT8)SB_Pmio_Safe_TBL[i].Value);
    }

    return EFI_SUCCESS;
}

