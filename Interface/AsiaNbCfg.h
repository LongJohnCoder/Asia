/*******************************************************************************
Copyright(C) 2018 Shanghai Zhaoxin Technologies, Inc. All Rights Reserved.

Information in this file is the intellectual property of Shanghai Zhaoxin Technologies, Inc.,
and may contains trade secrets that must be stored and viewed confidentially.

\file AsiaNbCfg.h
\brief ASIA NB Configuration Structure definition for CHX002.
\date 2018-05-07

Modification History:
    
*******************************************************************************/

#ifndef CHX002_ASIA_NB_CFG_H
#define CHX002_ASIA_NB_CFG_H

////
typedef struct _ASIA_NB_CONFIGURATION{
    UINT32 Signature;
        #define ASIA_NB_CONFIGURATION_SIGNATURE EFI_SIGNATURE_32('N','C','F','G')
    UINT64 BiosVersion;
        #define ASIA_BIOS_VERSION_STRING EFI_SIGNATURE_64('$', 'V', 'C', 'H', 'I', '0', '1', '6')
    // Chipset Sheet
	UINT8 CRBPlatformSelection;
		#define CRB_PLATFORM_MODE_SELECTION_NOTEBOOK 0
		#define CRB_PLATFORM_MODE_SELECTION_DESKTOP 1
    UINT8 NBSPEValue;
        UINT8 D0F0SPEValue;
        UINT8 D0F1SPEValue;
        UINT8 D0F2SPEValue;
        UINT8 D0F3SPEValue;
        UINT8 D0F4SPEValue;
        UINT8 D0F5SPEValue;
        UINT8 D0F6SPEValue;
        UINT8 D0F7SPEValue;
//        UINT8 D2F0SPEValue;		//PEG  CHX001-CJW-20151014
        UINT8 D3F0SPEValue;		//PE0
        UINT8 D3F1SPEValue;		//PE1
        UINT8 D3F2SPEValue;		//PE2
        UINT8 D3F3SPEValue;		//PE3
        UINT8 D4F0SPEValue;		//PE4
        UINT8 D4F1SPEValue;		//PE5
        UINT8 D5F0SPEValue;		//PE6	
	UINT8 D5F1SPEValue;		//PE7  CHX001-CJW-20151014
 	UINT8 RCRBHSPEValue; 	
 	UINT8 PCIEEPHYSPEValue;
    UINT8 D1F0SPEValue;
    UINT8  D8F0SPEValue;
	UINT8  D9F0SPEValue;
	
    // PCIE Sheet
    UINT64 PcieBar;
    UINT64 PcieEPHYBar;
    UINT64 RcrbhBar;
    UINT64 RcrbvBar;
    BOOLEAN PcieRst;
 //   BOOLEAN PcieRstPEG;
    BOOLEAN PcieRstPE0;
    BOOLEAN PcieRstPE1;
    BOOLEAN PcieRstPE2;
    BOOLEAN PcieRstPE3;
   BOOLEAN PcieRstPE4;
    BOOLEAN PcieRstPE5;
	BOOLEAN PcieRstPE6;
	BOOLEAN PcieRstPE7;
    BOOLEAN PcieRP;
 //   BOOLEAN PciePEG;
    BOOLEAN PciePE0;
    BOOLEAN PciePE1;
    BOOLEAN PciePE2;
    BOOLEAN PciePE3;
	BOOLEAN	PciePE4;
    BOOLEAN PciePE5;
	BOOLEAN PciePE6;
	BOOLEAN PciePE7;
   UINT8 PcieForceLinkWidth;
   	#define PcieForceLinkWidth_default 0
   	#define PcieForceLinkWidth_x1 1
    BOOLEAN PcieHotReset;   
   BOOLEAN PEMCU_LoadFW_WhenBoot; // JIH-2016081102 - PEMCU load FW option
   UINT8 SelectableDeEmphasis;
   	#define Gen2_DeEmphasis_SItable 0
   	#define Gen2_DeEmphasis_Force3p5 1
   	#define Gen2_DeEmphasis_Force6p0 2
   UINT8 PcieLinkSpeed;	
//	UINT8 PciePEGLinkSpeed;		//RP Speed Select
	UINT8 PciePE0LinkSpeed;
	UINT8 PciePE1LinkSpeed;
	UINT8 PciePE2LinkSpeed;
	UINT8 PciePE3LinkSpeed;
	UINT8 PciePE4LinkSpeed;
	UINT8 PciePE5LinkSpeed;
	UINT8 PciePE6LinkSpeed;
	UINT8 PciePE7LinkSpeed;
        #define PCIE_LINK_SPEED_AUTO 	   0
        #define PCIE_LINK_SPEED_FORCE_GEN1 1
	 	#define PCIE_LINK_SPEED_FORCE_GEN2 2    
	 	#define PCIE_LINK_SPEED_FORCE_GEN3 3
		#define PCIE_LINK_SPEED_BY_PORT    4	//
	UINT8 PcieOptimalTLS;
	UINT8 PcieDevCapPE0;
	UINT8 PcieDevCapPE1;
	UINT8 PcieDevCapPE2;
	UINT8 PcieDevCapPE3;
	UINT8 PcieDevCapPE4;
	UINT8 PcieDevCapPE5;
	UINT8 PcieDevCapPE6;
	UINT8 PcieDevCapPE7;
	UINT8 PcieCrsMech;
//;cjw_debug_pcie -start
		UINT8 PcieEQ;
			#define DOEQ				0
			#define SKPEQ_TABLE 		1
			#define SKPEQ_MANUAL		2
		UINT8 PcieEQPE0;
		UINT8 PcieEQPE1;
		UINT8 PcieEQPE2;
		UINT8 PcieEQPE3;
		UINT8 PcieEQPE4;
		UINT8 PcieEQPE5;
		UINT8 PcieEQPE6;
		UINT8 PcieEQPE7;
		UINT8 PcieEMEQDebug;
		UINT8 PcieEMEQScanTime;
		UINT8 PcieDoEqMethod;
			#define METHOD_TXEQ     	0
			#define METHOD_RXEQ 		1
			#define METHOD_FIXED_EQ		2
		UINT8 PcieEQTS2;
		UINT8     EQTxPreset;
			#define TxPreset0	0
			#define TxPreset1	1
			#define TxPreset2	2
			#define TxPreset3	3
			#define TxPreset4	4
			#define TxPreset5	5
			#define TxPreset6	6
			#define TxPreset7	7
			#define TxPreset8	8
			#define TxPreset9	9
			#define TxPreset10	0xA
			
		UINT16 PcieEqCtlOrgValL0;
		UINT16 PcieEqCtlOrgValL1;
		UINT16 PcieEqCtlOrgValL2;
		UINT16 PcieEqCtlOrgValL3;
		UINT16 PcieEqCtlOrgValL4;
		UINT16 PcieEqCtlOrgValL5;
		UINT16 PcieEqCtlOrgValL6;
		UINT16 PcieEqCtlOrgValL7;
		UINT16 PcieEqCtlOrgValL8;
		UINT16 PcieEqCtlOrgValL9;
		UINT16 PcieEqCtlOrgValL10;
		UINT16 PcieEqCtlOrgValL11;
		UINT16 PcieEqCtlOrgValL12;
		UINT16 PcieEqCtlOrgValL13;
		UINT16 PcieEqCtlOrgValL14;
		UINT16 PcieEqCtlOrgValL15;
		UINT8 PciePHYA_SSC_EN;
		UINT8 PciePHYB_SSC_EN;
//;cjw_debug_pcie -end

    // Kernel Controlled Items
    UINT8 MaxPayloadSize;
        #define MAX_PAYLOAD_SIZE_128B 0
        #define MAX_PAYLOAD_SIZE_256B 1
    BOOLEAN PcieASPM;
    BOOLEAN RelaxedOrder;
    UINT8 ExtTag;
//#define EXT_TAG_AUTO 0
//#define EXT_TAG_DISABLED 1
//#define EXT_TAG_ENABLED 2
        #define EXT_TAG_DISABLED 0		
		#define EXT_TAG_ENABLED 1		
    BOOLEAN ExtSync;
		BOOLEAN PcieFPGAMode;		//;cjw_debug_pcie
//lana_debug_pcie-start
//	UINT8 PEG_ID_Lock;
//		#define VID_UNLOCK	0
//		#define VID_LOCK 	1
//	UINT8 PE0_ID_Lock;
//	UINT8 PE1_ID_Lock;
//	UINT8 PE2_ID_Lock;
//	UINT8 PE3_ID_Lock;
//	UINT8 PE4_ID_Lock;
//	UINT8 PE5_ID_Lock;
//	UINT8 PE6_ID_Lock;
//	UINT8 PE7_ID_Lock;
	UINT8 PcieRoutingCtrl;
//	UINT8 PEG_Msgc2PcieIntx;
	UINT8 PE0_Msgc2PcieIntx;
	UINT8 PE1_Msgc2PcieIntx;
	UINT8 PE2_Msgc2PcieIntx;
	UINT8 PE3_Msgc2PcieIntx;
	UINT8 PE4_Msgc2PcieIntx;
	UINT8 PE5_Msgc2PcieIntx;
	UINT8 PE6_Msgc2PcieIntx;
	UINT8 PE7_Msgc2PcieIntx;
		#define PCIE_INTA	0
		#define PCIE_INTB	1
		#define PCIE_INTC	2
		#define PCIE_INTD	3
//	UINT8 PEG_PcieIntx2Nb2sbIntx;
	UINT8 PE0_PcieIntx2Nb2sbIntx;
	UINT8 PE1_PcieIntx2Nb2sbIntx;
	UINT8 PE2_PcieIntx2Nb2sbIntx;
	UINT8 PE3_PcieIntx2Nb2sbIntx;
	UINT8 PE4_PcieIntx2Nb2sbIntx;
	UINT8 PE5_PcieIntx2Nb2sbIntx;
	UINT8 PE6_PcieIntx2Nb2sbIntx;
	UINT8 PE7_PcieIntx2Nb2sbIntx;
		#define NB2SB_INTA	0
		#define NB2SB_INTB	1
		#define NB2SB_INTC	2
		#define NB2SB_INTD	3
	//UINT8 PegApciIrq;
		//#define INA_IRQ8	0
		//#define INA_IRQ9	1
		//#define INA_IRQ10	2
		//#define INA_IRQ11	3
	UINT8 Pe6ApciIrq;
		#define INA_IRQ0	0
		#define INA_IRQ1	1
		#define INA_IRQ2	2
		#define INA_IRQ3	3
	UINT8 Pe7ApciIrq;
		#define INA_IRQ4	0
		#define INA_IRQ5	1
		#define INA_IRQ6	2
		#define INA_IRQ7	3
    UINT8 PcieASPMBootArch;
//lana_debug_pcie-end		
//LNA-2016122701-S
		UINT8 PcieOBFFCtrl_PCIE;
		#define OBFF_DISABLE	0
		#define OBFF_PEXWAKE	1
		#define OBFF_MSGA		2
		#define OBFF_MSGB		3
					UINT8 PcieOBFFCtrl_PMU;
		#define Cx_COMMAND_MONITOR	0
		#define Cx_SIGNAL_MONITOR	1
//LNA-2016122701-E
    ///
    UINT8 PcieRpDisplaySwitch;
	#define PCIE_PE4_DISPLAY_SWTICH 0x01
	#define PCIE_PE0_DISPLAY_SWTICH 0x02 	
	#define PCIE_PE1_DISPLAY_SWTICH 0x04
	#define PCIE_PE2_DISPLAY_SWTICH 0x08
	#define PCIE_PE3_DISPLAY_SWTICH 0x10
	#define PCIE_PE5_DISPLAY_SWTICH 0x20
    UINT8 PcieSpeedDisplaySwitch;
	#define PCIE_SPEED_DISPLAY_SWITCH_GEN1 0x01
	#define PCIE_SPEED_DISPLAY_SWITCH_GEN2 0x02
	#define PCIE_SPEED_DISPLAY_SWITCH_AUTO 0x04
    ///
	 
	//Apic related features
	BOOLEAN  NbApicEnable;
	UINT64   NbApicBaseAddress;
	//3456-09-PDZ-04 +S
	UINT8    NbApicID;
	//3456-09-PDZ-04 +E
	// 3456-R21-SHC-02+S //
	// DRAM Sheet
	BOOLEAN	DramSelfRefresh;
	// 3456-R21-SHC-02+E //
    
    // UMA Sheet
    BOOLEAN UMAEn;
    BOOLEAN DisableHDAC1;
    BOOLEAN DisableHDAC2;
    BOOLEAN DualVGA;
	//3456-06-PDZ-03 +S
	UINT8 PrimaryGraphicAdapter;
	    #define PCIE_PCI_UMA 0
		#define UMA_PCIE_PCI 1
	//3456-06-PDZ-03 +E
    UINT8 SelectDisplayDevice;
        #define SELECT_DISPLAY_DEVICE_AUTO 0
        #define SELECT_DISPLAY_DEVICE_MANUAL 1
    UINT8 DP1;
        #define DISPLAY_NONE_DISPLAY 0
		#define DISPLAY_CRT 0x1
		#define DISPLAY_DVI 0x2
		#define DISPLAY_HDMI 0x4
		#define DISPLAY_LCD 0x20
		#define DISPLAY_DP 0x40
    UINT8 DP2;
	UINT8 DVO;
	UINT8 CRT;
		#define DISPLAY_DISPLAY 1        
    BOOLEAN ECLKCtrl;
    UINT16 ECLKFreq;
//3456-R28-TYL-01+S
    BOOLEAN VCLKCtrl;
    UINT16 VCLKFreq;
	BOOLEAN ICLKCtrl;
    UINT16 ICLKFreq;
//3456-R28-TYL-01+E
	//3456-R09-WLY-01     BOOLEAN ProgramClock;
//3456-R09-WLY-01 - s
	BOOLEAN	DP1SSCEn;
	BOOLEAN	DP2SSCEn;	
	UINT8 DP1SSCMode;
	UINT8 DP2SSCMode;
//3456-R09-WLY-01 - e
//3456-R09-WLY-01    UINT8 SSCPath;
        #define SSC_PATH_INTERNAL 0
        #define SSC_PATH_EXTERNAL 1
//3456-R09-WLY-01    UINT8 SSCFIFOOrg;
//3456-R09-WLY-01        #define SSC_FIFO_ORG_ORIGINAL 0
//3456-R09-WLY-01        #define SSC_FIFO_ORG_FIFOMODE 1
//3456-R09-WLY-01    UINT8 DisplayClockSSC;
        #define DISPLAY_CLK_SSC_MODE0 0
        #define DISPLAY_CLK_SSC_MODE1 1
        #define DISPLAY_CLK_SSC_MODE2 2
        #define DISPLAY_CLK_SSC_MODE3 3
    UINT8 LinuxVideoIP;
        #define LINUX_VIDEO_IP_ENABLE_ALL 0
        #define LINUX_VIDEO_IP_ENABLE_MPEG2 1
        #define LINUX_VIDEO_IP_ENABLE_WMV9_VC1 2
        #define LINUX_VIDEO_IP_ENABLE_MPEG4_DIVX_XVID 3
        #define LINUX_VIDEO_IP_ENABLE_MPEG4_H264 4
        #define LINUX_VIDEO_IP_DISABLE_ALL 4
    
    // NB Debug Sheet
    UINT8 CpuClockControl;
        #define CPU_CLK_CTL_DC10  0
        #define CPU_CLK_CTL_DC5 1
        #define CPU_CLK_CTL_NO_OC 2
        #define CPU_CLK_CTL_OC1 3
        #define CPU_CLK_CTL_OC2 4
        #define CPU_CLK_CTL_OC3 5
        #define CPU_CLK_CTL_OC4 6
        #define CPU_CLK_CTL_OC5 7
        #define CPU_CLK_CTL_OC6 8
        #define CPU_CLK_CTL_OC7 9
        #define CPU_CLK_CTL_OC8 10
        #define CPU_CLK_CTL_OC9 11
        #define CPU_CLK_CTL_OC10 12
    UINT8 PcieClockControl;
        #define PCIE_CLK_CTL_NO_OC 0
        #define PCIE_CLK_CTL_OC1 1
        #define PCIE_CLK_CTL_OC2 2
        #define PCIE_CLK_CTL_OC3 3
        #define PCIE_CLK_CTL_OC4 4
        #define PCIE_CLK_CTL_OC5 5
        #define PCIE_CLK_CTL_OC6 6
        #define PCIE_CLK_CTL_OC7 7
        #define PCIE_CLK_CTL_OC8 8
        #define PCIE_CLK_CTL_OC9 9
        #define PCIE_CLK_CTL_OC10 10
        #define PCIE_CLK_CTL_OC11 11
        #define PCIE_CLK_CTL_OC12 12
        #define PCIE_CLK_CTL_OC13 13
        #define PCIE_CLK_CTL_OC14 14
        #define PCIE_CLK_CTL_OC15 15
        #define PCIE_CLK_CTL_OC16 16
        #define PCIE_CLK_CTL_OC17 17
        #define PCIE_CLK_CTL_OC18 18
        #define PCIE_CLK_CTL_OC19 19
        #define PCIE_CLK_CTL_OC20 20
        #define PCIE_CLK_CTL_DC1 21
        #define PCIE_CLK_CTL_DC2 22
        #define PCIE_CLK_CTL_DC3 23
        #define PCIE_CLK_CTL_DC4 24
        #define PCIE_CLK_CTL_DC5 25
    UINT8 ZXCpuBclkControl;
        #define ZX_CPU_BCLK_CTL_FREE_RUNNING 0
        #define ZX_CPU_BCLK_CTL_STOPPABLE 1


	//Error Reporting Sheet
//LGE-20160309-S	
	// Error Reporting Sheet
	UINT8	SERRNBControl;
		#define ERR_Disable	0
		#define ERR_SMI		1
		#define ERR_NMI		2
		#define ERR_SCI		3
//LGE-20160309-E
	UINT8 HIFErrControl;
//	UINT8 PEGErrControl;
	UINT8 PE0ErrControl;
	UINT8 PE1ErrControl;
	UINT8 PE2ErrControl;
	UINT8 PE3ErrControl;
	UINT8 PE4ErrControl;
	UINT8 PE5ErrControl;
	UINT8 PE6ErrControl;
	UINT8 PE7ErrControl;
		#define ERR_Disable			0
		#define ERR_Uncorrectable	1
		#define ERR_Correctable		2
		#define ERR_Both			3		

    // Debug Signal Sheet
		//della_add_s

    // Debug Signal Sheet
	UINT8 	DebugMode;
		#define DisabledDebug  0
	  	#define NormalDebug 1
	  	#define SusDebug 2
		#define SkipDebug 3
	UINT8	DebugOutputSelect; 	
	  	#define	OutputMDA		0 
	  	#define	OutputMDB		1 
	  	#define	OutputDVPLow17Bits		2 
	  	#define	OutputDVPHigh17Bits		3 
	UINT8	DebugSignalSelect0; 	// #string STR_DBG_SIGNAL_SELECT_PROMT
	UINT8   DebugSignalSelect1;	  // #string STR_DBG_SIGNAL_SELECT_PROMT
		#define	GroupNBSB_Signal	0
	         #define	GroupGFX_Signal		1
	UINT8	DebugModuleSelect0; 
	UINT8	DebugModuleSelect1; 
		#define DEBUG_SELECT_NB 0
		#define DEBUG_SELECT_SB 1
		#define DEBUG_SELECT_TOP 2
		//#define DEBUG_SELECT_CPU 3
        UINT8   DebugSBselectByNB;
        		#define SB_SELECT_BY_SB 0
       		#define SB_SELECT_BY_NB 1
       UINT8   NBGroup0TopSelect;
            #define NB_GROUP_0_TOP_SELECT_MCUTRFC 	0
            #define NB_GROUP_0_TOP_SELECT_CPUIF		1
            #define NB_GROUP_0_TOP_SELECT_DRAMCA 	2
            #define NB_GROUP_0_TOP_SELECT_DRAMCB		3
            #define NB_GROUP_0_TOP_SELECT_PXPTRF  		4
            #define NB_GROUP_0_TOP_SELECT_RAIDA0   	5
            #define NB_GROUP_0_TOP_SELECT_TATCL    		6
            #define NB_GROUP_0_TOP_SELECT_RAIDA1    	7
            #define NB_GROUP_0_TOP_SELECT_GMINTA     	8
            #define NB_GROUP_0_TOP_SELECT_APICX    		9
            #define NB_GROUP_0_TOP_SELECT_NB_PMU   	10
            #define NB_GROUP_0_TOP_SELECT_FSBC     		11
            #define NB_GROUP_0_TOP_SELECT_GMINTB   	12
            #define NB_GROUP_0_TOP_SELECT_SBDBG    		13
	   		#define NB_GROUP_0_TOP_SELECT_PCIE     		14
	   		#define NB_GROUP_0_TOP_SELECT_CRMCA     		15
			#define NB_GROUP_0_TOP_SELECT_DDRIO			16
			#define NB_GROUP_0_TOP_SELECT_VPIL			17

        UINT32   NBGroup0ModuleSubSelect1;
		UINT32	 NBGroup0ModuleSubSelect2;
			
        UINT8   NBGroup1TopSelect;
		#define NB_GROUP_1_TOP_SELECT_MCUTRFC	0
		#define NB_GROUP_1_TOP_SELECT_CPUIF 		1
		#define NB_GROUP_1_TOP_SELECT_DRAMCA		2
		#define NB_GROUP_1_TOP_SELECT_DRAMCB		3
		#define NB_GROUP_1_TOP_SELECT_PXPTRF		4
		#define NB_GROUP_1_TOP_SELECT_RAIDA0		5
		#define NB_GROUP_1_TOP_SELECT_TATCL		6
		#define NB_GROUP_1_TOP_SELECT_RAIDA1		7
		#define NB_GROUP_1_TOP_SELECT_GMINTA		8
		#define NB_GROUP_1_TOP_SELECT_APICX		9
		#define NB_GROUP_1_TOP_SELECT_NB_PMU		10
		#define NB_GROUP_1_TOP_SELECT_FSBC		11
		#define NB_GROUP_1_TOP_SELECT_GMINTB		12
		#define NB_GROUP_1_TOP_SELECT_SBDBG		13
		#define NB_GROUP_1_TOP_SELECT_PCIE			14
		#define NB_GROUP_1_TOP_SELECT_CRMCA 			15
		#define NB_GROUP_1_TOP_SELECT_DDRIO 		16
		#define NB_GROUP_1_TOP_SELECT_VPIL			17

        UINT32   NBGroup1ModuleSubSelect1;
        UINT32   NBGroup1ModuleSubSelect2;

        UINT8   SBTopDbgMux1;
            #define SB_TOP_DEBUG_MUX_1_MIXSB			0
            #define SB_TOP_DEBUG_MUX_1_CCA			1
            #define SB_TOP_DEBUG_MUX_1_PCI1			2
			#define SB_TOP_DEBUG_MUX_1_D14_USBC_SUS 		3
            #define SB_TOP_DEBUG_MUX_1_SMB			4
            #define SB_TOP_DEBUG_MUX_1_D16_USBC_SUS			5
            #define SB_TOP_DEBUG_MUX_1_ESPI			6
            #define SB_TOP_DEBUG_MUX_1_SPI				7
            #define SB_TOP_DEBUG_MUX_1_LEGACY		8
            #define SB_TOP_DEBUG_MUX_1_PMU			9
            #define SB_TOP_DEBUG_MUX_1_AZ				10
            #define SB_TOP_DEBUG_MUX_1_HPET			11
            #define SB_TOP_DEBUG_MUX_1_PCIBUS			12
            #define SB_TOP_DEBUG_MUX_1_eBMC_OUT1		13
            #define SB_TOP_DEBUG_MUX_1_VART			14
            #define SB_TOP_DEBUG_MUX_1_SBGB2_SBGB1	16
            #define SB_TOP_DEBUG_MUX_1_32h5A5A5A5A	17
            #define SB_TOP_DEBUG_MUX_1_32hA5A5A5A5	18
	   		#define SB_TOP_DEBUG_MUX_1_DMAC_DBG_GRP1		19
            #define SB_TOP_DEBUG_MUX_1_PNP			20
            #define SB_TOP_DEBUG_MUX_1_D14_USBC			21
            #define SB_TOP_DEBUG_MUX_1_D16_USBC			22
	   		#define SB_TOP_DEBUG_MUX_1_NEW_KBDC			24
	   		#define SB_TOP_DEBUG_MUX_1_NEW_TMRC			25
	   		#define SB_TOP_DEBUG_MUX_1_NEW_PIC			26
            #define SB_TOP_DEBUG_MUX_1_PCIBUS_MIXSB 	27
	   		#define SB_TOP_DEBUG_MUX_1_LPC 			28
	   		#define SB_TOP_DEBUG_MUX_1_BUSC_MIXSC 	29	
			#define SB_TOP_DEBUG_MUX_1_RTC	 30 
			#define SB_TOP_DEBUG_MUX_1_ESPI_IO	 31 

			UINT32	SBGroup0ModuleSubSelect;
         UINT8   SBTopDbgMux2;
            #define SB_TOP_DEBUG_MUX_2_CCA_G2			1
            #define SB_TOP_DEBUG_MUX_2_PCI1_G2			2
			#define SB_TOP_DEBUG_MUX_2_D14_USBC_SUS_G2			3
            #define SB_TOP_DEBUG_MUX_2_SMB_G2		4
            #define SB_TOP_DEBUG_MUX_2_D16_USBC_SUS_G2		5
            #define SB_TOP_DEBUG_MUX_2_ESPI_G2		6
            #define SB_TOP_DEBUG_MUX_2_SPI_G2			7
            #define SB_TOP_DEBUG_MUX_2_LEGACY		8
            #define SB_TOP_DEBUG_MUX_2_PMU_G2			9
            #define SB_TOP_DEBUG_MUX_2_AZ_G2			10
            #define SB_TOP_DEBUG_MUX_2_HPET_G2			11
            #define SB_TOP_DEBUG_MUX_2_PCIBUS			12
            #define SB_TOP_DEBUG_MUX_2_eBMC_OUT2		13
            #define SB_TOP_DEBUG_MUX_2_VART_G2		14
            #define SB_TOP_DEBUG_MUX_2_SBGB2_SBGB1	16
            #define SB_TOP_DEBUG_MUX_2_32h5A5A5A5A	17
            #define SB_TOP_DEBUG_MUX_2_32hA5A5A5A5	18
            #define SB_TOP_DEBUG_MUX_2_DMAC_DBG_GRP2		19
	   		#define SB_TOP_DEBUG_MUX_2_PNP_G2		20
            #define SB_TOP_DEBUG_MUX_2_D14_USBC_G2		21
            #define SB_TOP_DEBUG_MUX_2_D16_USBC_G2		22
            #define SB_TOP_DEBUG_MUX_2_MIXSB			23
	   		#define SB_TOP_DEBUG_MUX_2_NEW_KBDC_G2 		24
            #define SB_TOP_DEBUG_MUX_2_NEW_TMRC_G2		25
	  		#define SB_TOP_DEBUG_MUX_2_NEW_PIC_G2 			26
	 		#define SB_TOP_DEBUG_MUX_2_PCIBUS_MIXSB	27
	  		#define SB_TOP_DEBUG_MUX_2_LPC_G2			28
	  		#define SB_TOP_DEBUG_MUX_2_BUSC_MISC_G2		29
			#define SB_TOP_DEBUG_MUX_2_RTC_G2	  30
			#define SB_TOP_DEBUG_MUX_2_ESPI_IO_G2	  30

			UINT32	SBGroup1ModuleSubSelect;
	UINT8	TOPGroup0TopSelcet;
	//UINT8	TOPGroup0XhciModuleSelcet;
	UINT8  TOPGroup0XhciModule0Selcet;
	UINT8  TOPGroup0XhciModule1Selcet;
	UINT16 TOPGroup0XhciGroup0Selcet;
	UINT16 TOPGroup0XhciGroup1Selcet;
	UINT8	TOPGroup0XhciMCUSelcet;
	UINT16	TOPGroup0SUSXhciSelcet;

	UINT32 TOPGroup0ModuleSubSelcet;
	UINT8	TOPGroup1TopSelcet;
			#define TOP_DEBUG_TOP  0
			#define TOP_DEBUG_PCIE_PHY  1
			#define TOP_DEBUG_SATA  4
			#define TOP_DEBUG_XHCI  5
			#define TOP_DEBUG_SATA_TXCDC  6
			#define TOP_DEBUG_XHCI_TXCDC  7
	//UINT8	TOPGroup1XhciModuleSelcet;
	UINT8  TOPGroup1XhciModule2Selcet;
	UINT8  TOPGroup1XhciModule3Selcet;
	UINT16 TOPGroup1XhciGroup2Selcet;
	UINT16 TOPGroup1XhciGroup3Selcet;
	UINT8	TOPGroup1XhciMCUSelcet;
	UINT16	TOPGroup1SUSXhciSelcet;
	
	UINT32 TOPGroup1ModuleSubSelcet;

	/*
	UINT8	FSBCGroup0TopSelcet;
	UINT8	FSBCGroup1TopSelcet; 
	
	UINT64	 CPU_FSBC_DBG_04;
	UINT64	CPU_FSBC_DBG_05;
	UINT64	CPU_FSBC_DBG_06;
	UINT64	CPU_FSBC_DBG_07;
	UINT64	CPU_FSBC_DBG_08;
	UINT64	 CPU_FSBC_DBG_09;
	UINT64	CPU_FSBC_DBG_0A;
	UINT64	CPU_FSBC_DBG_0B;
	UINT64	CPU_FSBC_DBG_0C;	
	UINT8	SOCCAP_Mem_Size;
	*/
	
	UINT8   CPU_FSBC_EN;
	UINT8	CPU_FSBC_PCIE_ON;
	UINT8	CPU_FSBC_TOPCIE;
	   #define	FSBC_PortG0	0
	   #define	FSBC_Port0	1

	UINT8	 CPU_FSBC_STREAM_EN;
	UINT8	 CPU_FSBC_MISSPACKE_EN;
	UINT8	 CPU_FSBC_TIGPULSE_EN;
	UINT8	 CPU_FSBC_IFSBCSTP_EN;
#ifdef ZX_SECRET_CODE
       UINT8     C2P2FlushC2M;
#endif
	UINT8	SB_HS_DBG_CH_SEL;
		#define SB_HS_DBG_CH_SEL_NORMAL_MODE		0	
		#define SB_HS_DBG_CH_SEL_DOWN_STREAM		1
		#define SB_HS_DBG_CH_SEL_UPSTREAM_READ	2
		#define SB_HS_DBG_CH_SEL_UPSTREAM_WRITE	 3
	UINT8	 SB_HS_DBG_SEL;
		#define SB_HS_DBG_SEL_DISABLE	0
		#define SB_HS_DBG_SEL_PCCA	   1
		#define SB_HS_DBG_SEL_XHCI	   2
		#define SB_HS_DBG_SEL_AHCI	   3

	UINT8	SB_HS_PCIE_PORT_SEL;
		#define	PORT0	0
		#define	PORT4  1

	//VDD OFF debug
	UINT8	VDD_OFF_EN;
			#define VDD_OFF_DBG_SEL_DISABLE	0
			#define VDD_OFF_DBG_SEL_ENABLE	1
	UINT8	VDD_OFF_Module_Sel;
	UINT8	VDD_OFF_Group_Sel;	
	UINT8	MCU_UART_SEL; 

	//della_add_e

    UINT32 VcpFileBaseAddr; 
    UINT16 VcpFileSize;        
    //Virtualization Sheet
    BOOLEAN	IOVEnable;
    BOOLEAN IOVQIEnable;
	BOOLEAN IOVINTREnable;
    UINT64	TABar;

	//Round-Robin Mechanism
	BOOLEAN RoundRobin;

	//CRMCA
	UINT32	CRMCABar;

    //RAIDA
	BOOLEAN RAIDA0Enable;
	BOOLEAN RAIDA1Enable;
	/*
	UINT8 ChangeVendorID_D0F0;
	UINT8 ChangeVendorID_D0F1;
	UINT8 ChangeVendorID_D0F2;
	UINT8 ChangeVendorID_D0F3;
	UINT8 ChangeVendorID_D0F4;
	UINT8 ChangeVendorID_D0F5;
	UINT8 ChangeVendorID_D0F6;
	*/
	////
	UINT8 ZxeDualSocket;
	////
	UINT8 IoeChipRevision;
    // PCIE Sheet
	UINT8 Cnd003ModeSel;	
		#define BIOS_MODE 0
		#define SPI_MODE 1
	UINT8 Cnd003PhyCfg;
	UINT8 Cnd003PhyACfg;
	UINT8 Cnd003PhyBCfg;
	UINT8 Cnd003EpCap;
	UINT8 Cnd003CapPEA0;
 	UINT8 Cnd003CapPEA1;
	UINT8 Cnd003CapPEA2;
 	UINT8 Cnd003CapPEA3;
 	UINT8 Cnd003CapPEA4;
 	UINT8 Cnd003CapPEB0;
 	UINT8 Cnd003CapPEB1;
	UINT8 Cnd003CapPESB;
	BOOLEAN Cnd003PcieRstTest;
	BOOLEAN Cnd003PEA0RstTest;
	BOOLEAN Cnd003PEA1RstTest;
	BOOLEAN Cnd003PEA2RstTest;
	BOOLEAN Cnd003PEA3RstTest;
	BOOLEAN Cnd003PEA4RstTest;
	BOOLEAN Cnd003PEB0RstTest;
	BOOLEAN Cnd003PEB1RstTest;
	UINT8 Cnd003LinkWidth;	
  	UINT8 Cnd003PcieEq;
  	UINT8 Cnd003Autofill;	
	UINT8 Cnd003BootErrorClear;
	UINT8 Cnd003ForceMPS128B;
	UINT8 Cnd003SwCtlDnPortLinkup;
	
	//DebugSignal Sel
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
#ifdef ZX_SECRET_CODE
	UINT8 Cnd003DIDVIDChoose;
#endif
	UINT8 Cnd003ChangeSIDForISB;
	UINT32 Cnd003SwDbg1;
	UINT32 Cnd003SwDbg2;
	
	//DBGCAp
	UINT8 Cnd003DC;			//DBGCAP
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
	
	//Hide XBCTL&EPTRFC [CJW_IOE]
	UINT8 Cnd003HideXbctl;
 	UINT8 Cnd003HideEptrfc;  
  	//CND003 TCx favor mechanism
  	UINT8 Cnd003TCxFavor;
	//CND003 SPE value 
	UINT8 IOESPEValue;
		UINT8 IOEXSPEValue;
		UINT8 IOEXp1D0F0SPEValue;
		UINT8 IOEXp1D1F0SPEValue;
		UINT8 IOEXp1D2F0SPEValue;
		UINT8 IOEXp1D3F0SPEValue;
		UINT8 IOEXp1D4F0SPEValue;
		UINT8 IOEXp1D5F0SPEValue;
		UINT8 IOEXp1D6F0SPEValue;
		UINT8 IOEXp1D7F0SPEValue;
		UINT8 IOEXp1D8F0SPEValue;
		UINT8 IOEXp2D0F0SPEValue;
		UINT8 IOEXp3D0F0SPEValue;
		UINT8 IOEEphySPEValue;
		UINT8 IOEMmioISBSPEValue;
  //CND003 DN ports Control
  	BOOLEAN IoeDnPortCtl;
  		BOOLEAN IoePEA0Ctl;
  		BOOLEAN IoePEA1Ctl;
		BOOLEAN IoePEA2Ctl;
		BOOLEAN IoePEA3Ctl;
		BOOLEAN IoePEA4Ctl;
		BOOLEAN IoePEB0Ctl;
		BOOLEAN IoePEB1Ctl;
	UINT8 IoeDnPortPEXRST;
		UINT8 IoePEA0PEXRST;
		UINT8 IoePEA1PEXRST;
		UINT8 IoePEA2PEXRST;
		UINT8 IoePEA3PEXRST;
		UINT8 IoePEA4PEXRST;
		UINT8 IoePEB0PEXRST;
		UINT8 IoePEB1PEXRST;
	UINT8 CND003PLLPCIEASSCEn;
	UINT8 CND003PLLPCIEASSCMagnitude;
	UINT8 CND003CKGSRCPLLPCIEASSCSpread;
	UINT8 CND003PLLPCIEBSSCEn;
	UINT8 CND003PLLPCIEBSSCMagnitude;
	UINT8 CND003CKGSRCPLLPCIEBSSCSpread;	
	UINT8 CND003USBCLKSEL;
	UINT8 CND003SATACLKSEL;
	UINT16 CND003_RPCIE_PU_IO;
	UINT16 CND003_RPCIE_TNO_IO;
} ASIA_NB_CONFIGURATION;

////
#endif
