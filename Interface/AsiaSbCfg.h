/*******************************************************************************
Copyright(C) 2018 Shanghai Zhaoxin Technologies, Inc. All Rights Reserved.

Information in this file is the intellectual property of Shanghai Zhaoxin Technologies, Inc.,
and may contains trade secrets that must be stored and viewed confidentially.

\file AsiaSbCfg.h
\brief ASIA SB Configuration Structure definition for CHX002.
\date 2018-05-07

Modification History:
    
*******************************************************************************/

#ifndef CHX002_ASIA_SB_CFG_H
#define CHX002_ASIA_SB_CFG_H

////
typedef struct _ASIA_SB_CONFIGURATION {
    UINT32 Signature;
        #define ASIA_SB_CONFIGURATION_SIGNATURE EFI_SIGNATURE_32('S','C','F','G')
    
    // Chipset Sheet
	UINT8 CRBPlatformSelection;
		#define CRB_PLATFORM_MODE_SELECTION_NOTEBOOK 0
		#define CRB_PLATFORM_MODE_SELECTION_DESKTOP 1
    UINT8 SBSPEValue;
	UINT8 SATASPEValue;
    UINT8 VARTSPEValue;
	UINT8 ESPISPEValue;	//HYL-20160501		
	
	UINT8 BusCtrlSPEValue;
	UINT8 PMUSPEValue;
	UINT8 PCCASPEValue;
	UINT8 HDACSPEValue;
	UINT8 SPISPEValue;
    UINT8 SOCXHCISPEValue;//[Add_GRW_20180413]
    UINT8 SOCEHCISPEValue;//[Add_GRW_20180413]
    UINT8 SOCUHCISPEValue;//[Add_GRW_20180413]
	//this varible is needed when some TACTL linkage configuration is added in the SBInit.c 2321
	BOOLEAN IOVEnable;

    // UART Sheet
    UINT8 OnChipUartMode;
        #define ON_CHIP_UART_MODE_DISABLED 0
        #define ON_CHIP_UART_MODE_PCIUART 1
    UINT8 UartModuleSelection;
        #define UART_MODULE_SEL_LEGACY 0
        #define UART_MODULE_SEL_PCIDMA 1
        #define UART_MODULE_SEL_PCICOMPATIBLE 2
    BOOLEAN Uart0Enable;
	BOOLEAN Uart0_8PinEnable;

    UINT8 Uart0IoBaseSelection;
        #define UART_IO_BASE_SEL_3F8 0
        #define UART_IO_BASE_SEL_2F8 1
        #define UART_IO_BASE_SEL_3E8 2
        #define UART_IO_BASE_SEL_2E8 3
    UINT8 Uart0IRQSelection;
        #define UART_IRQ_SEL_3 3
        #define UART_IRQ_SEL_4 4
        #define UART_IRQ_SEL_7 7
        #define UART_IRQ_SEL_11 11

    BOOLEAN Uart1Enable;
    UINT8 Uart1IoBaseSelection;
    UINT8 Uart1IRQSelection;

    BOOLEAN Uart2Enable;
    UINT8 Uart2IoBaseSelection;
    UINT8 Uart2IRQSelection;

    BOOLEAN Uart3Enable;
    UINT8 Uart3IoBaseSelection;
    UINT8 Uart3IRQSelection;
    BOOLEAN UartFLREn;				
    
    // PMU_ACPI Sheet
    // C-State Control
    UINT8 ProcessorCState;
        #define PROCESSOR_CSTATE_DISABLED 0
        #define PROCESSOR_CSTATE_C2 1
        #define PROCESSOR_CSTATE_C2_C3 2
        #define PROCESSOR_CSTATE_C2_C3_UPDOWN_MODE 3
        #define PROCESSOR_CSTATE_C2_C4 4
        #define PROCESSOR_CSTATE_C2_C4_UPDOWN_MODE 5
    UINT8 ConditionalC4;
        #define CONDITIONAL_C4_DISABLED 0
        #define CONDITIONAL_C4_AUTO 1
    BOOLEAN C5Control;
    UINT8 C4BusMasterIdleTimer;
    UINT8 C3BusMasterIdleTimer;
	//JYZ_ADD_SVID
	   BOOLEAN SVIDMVCLKControl;
	   BOOLEAN SVIDMPeriodicIoutControl;
	   BOOLEAN SVIDMC3Control;
	   BOOLEAN SVIDMC4C5Control;
	   BOOLEAN VRMStableBD;
	   BOOLEAN SVIDMC4SetPS;
	   BOOLEAN CPU2SVIDCmdGate;
	   BOOLEAN CPUPStateTOCounter;
	   BOOLEAN CPUPStateSetVIDDone;
	   UINT8 VRM0VIDFSSelect;
                   #define VRM0_VID_SLOW 0
                   #define VRM0_VID_FAST 1
	   UINT8 SVIDMC4SetPSSel;
                    #define C4_SETPS_PS0 0
                    #define C4_SETPS_PS1 1
                    #define C4_SETPS_PS2 2
                    #define C4_SETPS_PS3 3
	   UINT8 SVIDMC4DecayOP;
                    #define C4_SETDECAY 0
                    #define C4_SETVID 1
	   UINT8 SVIDMC4SetVIDSel;
                    #define C4_SETVID_FAST 0
                    #define C4_SETVID_SLOW 1
	   UINT8   VRM0IoutTimer;

    // Cx Latency Control
    //BOOLEAN FastC3Mode;
    BOOLEAN ShortC3C4Mode;
    //BOOLEAN SlowC4Recovery;
    //BOOLEAN SlowC5Recovery;
    UINT8 DPSLPtoSLP;
        #define DPSLP_TO_SLP_00 0
        #define DPSLP_TO_SLP_01 1
        #define DPSLP_TO_SLP_10 2
        #define DPSLP_TO_SLP_11 3
    UINT8 VRDSLPtoDPSLP;
        #define VRDSLP_TO_DPSLP_00 0
        #define VRDSLP_TO_DPSLP_01 1
        #define VRDSLP_TO_DPSLP_10 2
        #define VRDSLP_TO_DPSLP_11 3
    // Dynamic Clock Control
    BOOLEAN SBDynamicClkControl;
	//BOOLEAN TMRCDynamicClkControl;
    // Other Control
    BOOLEAN MobileCenterControl;
    BOOLEAN ACAdapterControl;
    UINT8 PLLOKSelectionControl;
        #define PLL_OK_SEL_CTL_LOGIC 0
        #define PLL_OK_SEL_CTL_CIRCUIT 1
	UINT8   CpuFanStartTemperature;   //IVS-20180711
    BOOLEAN MsiSupport; 
	BOOLEAN LPTControl;
    UINT8 FixedFreeCxLatency;
        #define FIX_FREE_CX_LATENCY_FIXED  0
        #define FIX_FREE_CX_LATENCY_FREE  1
        #define FIX_FREE_CX_LATENCY_FREE_WITH_SLOW_MODE  2
    BOOLEAN DynamicT05;
	//;Power Gating:
	UINT8 eBMCSettleTime;
#ifdef ZX_SECRET_CODE
	BOOLEAN KBDCLegacySelControl;
	BOOLEAN TMRCLegacySelControl;
#endif
	BOOLEAN INTCLegacySelControl;
	BOOLEAN DMACLegacySelControl;

    //SATA
    BOOLEAN SataEn;
    UINT8 SataCfg;
		#define SATA_CFG_IDE  0
		#define SATA_CFG_RAID 1
		#define SATA_CFG_AHCI 2 
    UINT8 IDEGen;
    UINT8 AHCIGen;
		#define SATA_GEN3 3
		#define SATA_GEN2 2
		#define SATA_GEN1 1 
	UINT8 IDECapSelect;
		#define IDE_CAP_HOTPLUG 0
		#define IDE_CAP_LINKPM	1
    UINT8 IDEHIPMEn;
    UINT8 AHCIMSI;	
    UINT8 AHCIMSIX;
    UINT8 AHCIHotplugEn;
	UINT8 AHCIALPMEn;
    UINT8 FuncLevelResetEn;
	UINT8 GBFlushendEn;

    //
    // USB
    //
    // Common
    UINT8 UsbModeSelect;
        #define USB_MODE_SEL_DISABLE 0
        #define USB_MODE_SEL_MODEA 1 //ehci only
        #define USB_MODE_SEL_MODEB 2 //mode 2
        #define USB_MODE_SEL_MODEC 3 //XHCI only
        #define USB_MODE_SEL_MODED 4 //mode 4
    BOOLEAN UsbS4WakeupCtrl;
	    #define USB_S4WAKEUP_ENABLE 1
		#define USB_S4WAKEUP_DISABLE 0
    BOOLEAN UsbOCCtrl;
        #define USB_OC_ENABLE 1
        #define USB_OC_DISABLE 0
    // USBC
    UINT8 USBCFLRCtrl;
	    #define USBC_FLR_ENABLE 1
		#define USBC_FLR_DISABLE 0
    // XHCI
    UINT8 XhcMcuDmaPathCtrl;
        #define XHC_MCUDMAPATH_SNOOP 1
        #define XHC_MCUDMAPATH_NONSNOOP 0
    UINT8 XhcTRBCacheBypassCtrl;
		#define XHC_TRB_CACHE_NOT_BYPASS 0
		#define XHC_TRB_CACHE_BYPASS 1
    UINT8 XhcBurstCtrl;
        #define XHC_OUTBURST_ENABLE 1
        #define XHC_OUTBURST_DISABLE 0
    UINT8 XhcPerfModeCtrl;
        #define XHC_PERF_MODE_ENABLE 1
        #define XHC_PERF_MODE_DISABLE 0
	UINT8 XhcU1U2Ctrl;
        #define XHC_PORTU1U2_ENABLE 1
        #define XHC_PORTU1U2_DISABLE 0	
    UINT8 XhcMsiFlushCtrl;
        #define XHC_MSIFLUSH_ENABLE 1
        #define XHC_MSIFLUSH_DISABLE 0
    UINT8 XhcUartCtrl;
        #define XHC_XHCIUART_ENABLE 1
        #define XHC_XHCIUART_DISABLE 0
    UINT8 XhcFLRCtrl;
		#define XHC_FLR_ENABLE 1
		#define XHC_FLR_DISABLE 0
    UINT8 XhcRTD3Ctrl;
		#define XHC_RTD3_ENABLE 1
		#define XHC_RTD3_DISABLE 0
    BOOLEAN XhcC4BlockCtrl;
		#define XHC_C4BLOCK_ENABLE 1
		#define XHC_C4BLOCK_DISABLE 0
	BOOLEAN XhcEITRNCtrl;
		#define XHC_EITRN_ENABLE 1
		#define XHC_EITRN_DISABLE 0

    // HDAC Sheet
    BOOLEAN Azalia;
    BOOLEAN GoNonSnoopPath;
    BOOLEAN HDACFLREn;	
    
    // SNMI Sheet
	BOOLEAN	IsoLPC;
	BOOLEAN IsoVART;
	BOOLEAN IsoAZALIA;
	BOOLEAN IsoESPI;
	BOOLEAN IsoSPI;
	BOOLEAN IsoAPIC;///MTN_0318

    // Others Sheet
    BOOLEAN EnableMultimediaTimer;
    BOOLEAN MultimediaTimerMode;		//jhcdbg++
    BOOLEAN EnableMultimediaTimerMsi;		
    BOOLEAN WatchDogTimer;
    UINT8 WatchDogTimerRunStop;
        #define WATCHDOG_TIMER_STOP 0
        #define WATCHDOG_TIMER_RUN 1
    UINT8 WatchDogTimerAction;
        #define WATCHDOG_TIMER_ACTION_RESET 0
        #define WATCHDOG_TIMER_ACTION_POWEROFF 1
    UINT8 WatchDogTimerCount;
        #define WATCHDOG_TIMER_COUNT_72S 0
        #define WATCHDOG_TIMER_COUNT_389S 1
        #define WATCHDOG_TIMER_COUNT_706S 2
        #define WATCHDOG_TIMER_COUNT_1023S 3
    BOOLEAN KBMouseWakeupControl;
    BOOLEAN SMBusControllerUnderOS;
    BOOLEAN SMBHostClockFrequencySelect;
    UINT8 SMBHostClockFrequency;
    UINT8 SPIBus0ClockSelect;
        #define SPI_BUS0_CLK_13MHZ 0//dla_1011
        #define SPI_BUS0_CLK_27MHZ 1//dla_1011
        #define SPI_BUS0_CLK_48MHZ 2
        #define SPI_BUS0_CLK_66MHZ 3
    BOOLEAN ESPI;	//hurry-0420	
//HYL-2018062901-start
#ifdef ZX_SECRET_CODE	
    UINT8 WDTClear;	
#endif
//HYL-2018062901-end		
	UINT8 FsbcMemSize;
    BOOLEAN ApicEnable;    
    UINT8 AcpiIrq;
    UINT16 PmioBar;
    UINT32 ApicBar;
    UINT8    SbApicID;
    UINT32 HpetBar;
    UINT32 WatchDogBar;
    UINT32 D17F0MmioBar;
    UINT32 SpiBar;
	UINT8 VidSelect;
	   #define VID_ZX   0
	   #define VID_OTHER  1
      /////
      UINT8 ZxeDualSocket;	
      /////
	// CJW_IOE_PORTING [20160922] - START
	// SPE value setting part
	  UINT8 IOESPEValue;
		  UINT8 IOEGNICSPEValue;  
		  UINT8 IOESATASPEValue;
		   UINT8 IOEXHCISPEValue; //TTP_IOE_02
		  UINT8 IOEEHCISPEValue; //[ALJ 0630 IOE]
		  UINT8 IOEUHCISPEValue; //[ALJ 0630 IOE]
  
	  // For TOP related copy(ModeSel & DebugSignalSel & Hide)
	  UINT8 IoeChipRevision;
	  UINT8 Cnd003ModeSel;	  
	#define BIOS_MODE 0
	#define SPI_MODE 1
	  UINT8 Cnd003DebugFromCpu;
	  UINT8 Cnd003ModuleG0;
	  UINT8 Cnd003ModuleG1;
	  UINT16 Cnd003DebugG0;
	  UINT16 Cnd003DebugG1;
	  UINT16 Cnd003DebugG2;
	  UINT16 Cnd003DebugG3;
	  UINT16 Cnd003DebugG0_XHCI;
	  UINT16 Cnd003DebugG1_XHCI;
	  UINT16 Cnd003DebugG2_XHCI;
	  UINT16 Cnd003DebugG3_XHCI;
	  UINT8 Cnd003HighSpeed;
	  UINT8 Cnd003DebugSuspend;
	  UINT8 Cnd003HighSpeedModuleSel;
	  UINT16 Cnd003HighSpeedDbgSel;
	   UINT8 Cnd003CorePowerOff;   
	  UINT8 Cnd003DbgPadG0En;
	  UINT8 Cnd003DbgPadG1En;
	  UINT8 Cnd003DbgPadG2En;
	  UINT8 Cnd003DbgPadG3En; 
  
	  UINT8 Cnd003UartPinEn;
	  
	  //DBGCAp
	  UINT8 Cnd003DC;		  //DBGCAP
	  UINT8 Cnd003DCModule;
	  UINT8 Cnd003DCTrans;
	  UINT8 Cnd003DCCfgPath;
	  UINT8 Cnd003DCChannel;
	  UINT32 Cnd003DCDbg0Mask;
	  UINT32 Cnd003DCDbg1Mask;
	  UINT16 Cnd003DCTriggerMode;
	  UINT32 Cnd003DCReqPtn;
	  UINT32 Cnd003DCReqPtnMask;
	  UINT32 Cnd003DCDataPtn;
	  UINT32 Cnd003DCDataPtnMask;
	  UINT32 Cnd003DCPlusTimer;
	  UINT32 Cnd003DCStartTimer;
	  UINT32 Cnd003DCPeriodTimer;
	  UINT32 Cnd003DCReqCnt;
	  UINT8 Cnd003DCOutput;
	  
	  UINT8 Cnd003HideXbctl;
	  UINT8 Cnd003HideEptrfc;  
  
	  // IOE_GNIC
	  UINT8   IOEGnicEn;
	  UINT8   IOEGnicVEEPROM; 
	  UINT8   IOEGnicTXDCS;
	  UINT8   IOEGnicTXDC0;
	  UINT8   IOEGnicTXDC1;
	  UINT8   IOEGnicTXDC2;
	  UINT8   IOEGnicRXDCS;
	  UINT8   IOEGnicRXDC0;
	  UINT8   IOEGnicRXDC1;
	  UINT8   IOEGnicRXDC2;
	  UINT8   IOEGnicDPDC64;
	  UINT8   IOEGnicDPDC128;
	  UINT8   IOEGnicDPDC256;
	  UINT8   IOEGnicForceSizeEn;
	  UINT8   IOEGnicForceRDR;
	  UINT8   IOEGnicForcePayload;
	  UINT8   IOEGnicEventCtrl;
	  UINT8   IOEGnicPendingCtrl;
	  UINT8   IOEGnicMsiCtrl;
	  UINT8   IOEGnicMsiXCtrl;
	  UINT8   IOEGnicD0PME;
  
	  //CND003 SATA
	  BOOLEAN IOESataEn;
	  UINT8 IOESataCfg;
    #define SATA_CFG_IDE  0
    #define SATA_CFG_RAID 1
    #define SATA_CFG_AHCI 2
	  UINT8 IOEAHCIGen; 
	  UINT8 IOESataGen;  
    #define SATA_GEN_3 3
    #define SATA_GEN_2 2
    #define SATA_GEN_1 1 
	  UINT8 IOEAHCI_MSI;  
	  UINT8 IOEAHCI_MSIX;
	  UINT8 IOESataCapSelect;
    #define IOE_SATA_CAP_HOTPLUG 0
    #define IOE_SATA_CAP_LINKPM  1
	  UINT8 IOESataHIPMEn;
	  UINT8 IOESataHpcpEn;
	  UINT8 IOESataALPMEn;
	  UINT8 IOEFunctionLevelEnabled;
	  
	  //CND003 USB Sheet
	  //UINT8 IOEUsbModeSelectMode;
	//#define IOEUSB_MODE_SEL_MODE_AT 0
	//#define IOEUSB_MODE_SEL_MODE_MT 1
	  UINT8 IOEUsbModeSelect;
    #define IOEUSB_MODE_SEL_DISABLE 0
    #define IOEUSB_MODE_SEL_MODEA 1
    #define IOEUSB_MODE_SEL_MODEB 2
    #define IOEUSB_MODE_SEL_MODEC 3
    #define IOEUSB_MODE_SEL_MODED 4
	  UINT8 IOETRBCacheBypass;
	#define IOETRB_CACHE_NOT_BYPASS 0
	#define IOETRB_CACHE_BYPASS 1
	  UINT8 IOEXhciOutBurstEn;
    #define IOEUSB_OUTBURST_ENABLE 1
    #define IOEUSB_OUTBURST_DISABLE 0
	  UINT8 IOEXhciMaxBurstSize;
    #define IOEUSB_MAXBURSTSIZE_ENABLE 1
    #define IOEUSB_MAXBURSTSIZE_DISABLE 0
	  UINT8 IOEUSBCFLRControl;
    #define IOEUSBC_FLR_ENABLE 1
	#define IOEUSBC_FLR_DISABLE 0
	  UINT8 IOEXHCIFLRControl;
	#define IOEXHCI_FLR_ENABLE 1
	#define IOEXHCI_FLR_DISABLE 0
	  UINT8 IOERTD3Control;
	#define IOERTD3_ENABLE   1
	#define IOERTD3_DISABLE   0
	  BOOLEAN IOEUsbS4Wakeup;
	  BOOLEAN IOEUsbC4Block;
	 #define IOEUSB_C4BLOCK_ENABLE 1
	 #define IOEUSB_C4BLOCK_DISABLE 0
	  BOOLEAN IOEUsb10GSupport;
    #define IOEUSB10G_ENABLE 1
    #define IOEUSB10G_DISABLE 0
	  BOOLEAN IOEUsbOCEn;
    #define IOEUSBOC_ENABLE 1
    #define IOEUSBOC_DISABLE 0
	  BOOLEAN IOEUsbEITRN;
	#define IOEUSBEITRN_ENABLE 1
	#define IOEUSBEITRN_DISABLE 0
  // CJW_IOE_PORTING [20160922] - END
} ASIA_SB_CONFIGURATION;

////
#endif
