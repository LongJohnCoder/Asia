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

//////
VOID InitNbCfgStructDefaultValue(
	IN ASIA_NB_CONFIGURATION* pNbCfg)
{
	//// Init ASIA NB Cfg struct's default value
	pNbCfg->Signature=ASIA_NB_CONFIGURATION_SIGNATURE;
	pNbCfg->BiosVersion=ASIA_BIOS_VERSION_STRING;
	// Chipset Sheet
	pNbCfg->CRBPlatformSelection=0;
	pNbCfg->NBSPEValue=CHIP_SPE_VALUE_STABLE;
	pNbCfg->D0F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F1SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F2SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F3SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F4SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F5SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F6SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D0F7SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D3F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D3F1SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D3F2SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D3F3SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D4F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D4F1SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D5F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D5F1SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->RCRBHSPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->PCIEEPHYSPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D1F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D8F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->D9F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	//PCIE Sheet
	pNbCfg->PcieBar=0xE0000000;
	pNbCfg->PcieEPHYBar=0xFEB14000;
	pNbCfg->RcrbhBar=0xFEB12000;
	pNbCfg->RcrbvBar=0xFEB11000;
	pNbCfg->PcieRst=FALSE;	
	pNbCfg->PcieRstPE0=FALSE;
	pNbCfg->PcieRstPE1=FALSE;
	pNbCfg->PcieRstPE2=FALSE;
	pNbCfg->PcieRstPE3=FALSE;
	pNbCfg->PcieRstPE4=FALSE;
	pNbCfg->PcieRstPE5=FALSE;
	pNbCfg->PcieRstPE6=FALSE;
	pNbCfg->PcieRstPE7=FALSE;
	pNbCfg->PcieRP=TRUE;
	pNbCfg->PciePE0=TRUE;
	pNbCfg->PciePE1=FALSE;
	pNbCfg->PciePE2=FALSE;
	pNbCfg->PciePE3=FALSE;
	pNbCfg->PciePE4=FALSE;
	pNbCfg->PciePE5=FALSE;
	pNbCfg->PciePE6=TRUE;
	pNbCfg->PciePE7=FALSE;
	pNbCfg->PcieForceLinkWidth=PcieForceLinkWidth_default;
	pNbCfg->PcieHotReset=FALSE;
	pNbCfg->PEMCU_LoadFW_WhenBoot=FALSE;
	pNbCfg->SelectableDeEmphasis=Gen2_DeEmphasis_SItable;
	pNbCfg->PcieLinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE0LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE1LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE2LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE3LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE4LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE5LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE6LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PciePE7LinkSpeed=PCIE_LINK_SPEED_AUTO;
	pNbCfg->PcieOptimalTLS=1;
	pNbCfg->PcieDevCapPE0=0xFF;
	pNbCfg->PcieDevCapPE1=0xFF;
	pNbCfg->PcieDevCapPE2=0xFF;
	pNbCfg->PcieDevCapPE3=0xFF;
	pNbCfg->PcieDevCapPE4=0xFF;
	pNbCfg->PcieDevCapPE5=0xFF;
	pNbCfg->PcieDevCapPE6=0xFF;
	pNbCfg->PcieDevCapPE7=0xFF;
	pNbCfg->PcieCrsMech=0;
	//debug_pcie
	pNbCfg->PcieEQ=SKPEQ_MANUAL;
	pNbCfg->PcieEQPE0 = 0;
	pNbCfg->PcieEQPE1 = 0;
	pNbCfg->PcieEQPE2 = 0;
	pNbCfg->PcieEQPE3 = 0;
	pNbCfg->PcieEQPE4 = 0;
	pNbCfg->PcieEQPE5 = 0;
	pNbCfg->PcieEQPE6 = 0;
	pNbCfg->PcieEQPE7 = 0;
	pNbCfg->PcieEMEQDebug = 0;
	pNbCfg->PcieEMEQScanTime = 0x72;
	pNbCfg->PcieDoEqMethod = METHOD_TXEQ;
	pNbCfg->PcieEQTS2=0;
	pNbCfg->EQTxPreset=TxPreset7;
	pNbCfg->PcieEqCtlOrgValL0=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL1=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL2=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL3=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL4=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL5=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL6=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL7=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL8=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL9=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL10=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL11=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL12=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL13=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL14=0x7F7F;
	pNbCfg->PcieEqCtlOrgValL15=0x7F7F;
	pNbCfg->PciePHYA_SSC_EN = 1;
	pNbCfg->PciePHYB_SSC_EN = 1;
	//Kernel Controlled Items
	pNbCfg->MaxPayloadSize=MAX_PAYLOAD_SIZE_256B;
	pNbCfg->PcieASPM=TRUE;
	pNbCfg->RelaxedOrder=TRUE;
	pNbCfg->ExtTag=EXT_TAG_DISABLED;
	pNbCfg->ExtSync=FALSE;
	pNbCfg->PcieFPGAMode=TRUE;
	pNbCfg->PcieRoutingCtrl=0;
	pNbCfg->PE0_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE1_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE2_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE3_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE4_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE5_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE6_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE7_Msgc2PcieIntx=PCIE_INTD;
	pNbCfg->PE0_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE1_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE2_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE3_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE4_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE5_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE6_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	pNbCfg->PE7_PcieIntx2Nb2sbIntx=NB2SB_INTA;
	//pNbCfg->PegApciIrq=INA_IRQ8;
	pNbCfg->Pe6ApciIrq=INA_IRQ0;
	pNbCfg->Pe7ApciIrq=INA_IRQ4;
    pNbCfg->PcieASPMBootArch = 0;
	pNbCfg->PcieOBFFCtrl_PCIE=OBFF_DISABLE;
	pNbCfg->PcieOBFFCtrl_PMU=Cx_COMMAND_MONITOR;
	pNbCfg->PcieRpDisplaySwitch=0x3f;
	pNbCfg->PcieSpeedDisplaySwitch=0x07;
	//NB IO APIC
	pNbCfg->NbApicEnable=TRUE;
	pNbCfg->NbApicBaseAddress=0xFECC0000;
	pNbCfg->NbApicID=0x0A;
	//dram
	pNbCfg->DramSelfRefresh=TRUE;
	//UMA
	pNbCfg->UMAEn=FALSE; // Synch with current Setup UI's default value
  pNbCfg->DisableHDAC1 = FALSE;
  pNbCfg->DisableHDAC2 = FALSE;
	pNbCfg->DualVGA=FALSE;
	pNbCfg->PrimaryGraphicAdapter=PCIE_PCI_UMA;
	pNbCfg->SelectDisplayDevice=SELECT_DISPLAY_DEVICE_MANUAL;
	pNbCfg->DP1=DISPLAY_NONE_DISPLAY;
	pNbCfg->DP2=DISPLAY_NONE_DISPLAY;
	pNbCfg->DVO=DISPLAY_NONE_DISPLAY;
	pNbCfg->CRT=DISPLAY_NONE_DISPLAY;
	pNbCfg->ECLKCtrl=FALSE;
	pNbCfg->ECLKFreq=300;
	pNbCfg->VCLKCtrl=FALSE;
	pNbCfg->VCLKFreq=400;
	pNbCfg->ICLKCtrl=FALSE;
	pNbCfg->ICLKFreq=0;
	pNbCfg->DP1SSCEn=TRUE;
	pNbCfg->DP2SSCEn=TRUE;
	pNbCfg->DP1SSCMode=DISPLAY_CLK_SSC_MODE0;
	pNbCfg->DP2SSCMode=DISPLAY_CLK_SSC_MODE0;
	pNbCfg->LinuxVideoIP=LINUX_VIDEO_IP_ENABLE_ALL;
	// NB Debug
	pNbCfg->CpuClockControl=CPU_CLK_CTL_NO_OC;
	pNbCfg->PcieClockControl=PCIE_CLK_CTL_NO_OC;
	pNbCfg->ZXCpuBclkControl=ZX_CPU_BCLK_CTL_STOPPABLE;
	//Error Reporting
	pNbCfg->SERRNBControl=ERR_Disable;
	pNbCfg->HIFErrControl=0;
	pNbCfg->PE0ErrControl=ERR_Uncorrectable;
	pNbCfg->PE1ErrControl=ERR_Uncorrectable;
	pNbCfg->PE2ErrControl=ERR_Uncorrectable;
	pNbCfg->PE3ErrControl=ERR_Uncorrectable;
	pNbCfg->PE4ErrControl=ERR_Uncorrectable;
	pNbCfg->PE5ErrControl=ERR_Uncorrectable;
	pNbCfg->PE6ErrControl=ERR_Uncorrectable;
	pNbCfg->PE7ErrControl=ERR_Uncorrectable;
	//Debug Signal
	pNbCfg->DebugMode=DisabledDebug;
	pNbCfg->DebugOutputSelect=OutputMDA;
	pNbCfg->DebugSignalSelect0=GroupNBSB_Signal;
	pNbCfg->DebugSignalSelect1=GroupNBSB_Signal;
	pNbCfg->DebugModuleSelect0=DEBUG_SELECT_NB;
	pNbCfg->DebugModuleSelect1=DEBUG_SELECT_NB;
	pNbCfg->DebugSBselectByNB=SB_SELECT_BY_NB;
	pNbCfg->NBGroup0TopSelect=NB_GROUP_0_TOP_SELECT_MCUTRFC;
	pNbCfg->NBGroup0ModuleSubSelect1=0;
	pNbCfg->NBGroup0ModuleSubSelect2=0;
	pNbCfg->NBGroup1TopSelect=NB_GROUP_1_TOP_SELECT_MCUTRFC;
	pNbCfg->NBGroup1ModuleSubSelect1=0;
	pNbCfg->NBGroup1ModuleSubSelect2=0;
	pNbCfg->SBTopDbgMux1=SB_TOP_DEBUG_MUX_1_MIXSB;
	pNbCfg->SBGroup0ModuleSubSelect=0;
	pNbCfg->SBTopDbgMux2=SB_TOP_DEBUG_MUX_2_PMU_G2;
	pNbCfg->SBGroup1ModuleSubSelect=0;
	pNbCfg->TOPGroup0TopSelcet=0;
	pNbCfg->TOPGroup0XhciModule0Selcet=0;
	pNbCfg->TOPGroup0XhciModule1Selcet=0;
	pNbCfg->TOPGroup0XhciGroup0Selcet=0;
	pNbCfg->TOPGroup0XhciGroup1Selcet=0;
	pNbCfg->TOPGroup0XhciMCUSelcet=0;
	pNbCfg->TOPGroup0SUSXhciSelcet=0;
	pNbCfg->TOPGroup0ModuleSubSelcet=0;
	
	pNbCfg->TOPGroup1TopSelcet=0;
	pNbCfg->TOPGroup1XhciModule2Selcet=0;
	pNbCfg->TOPGroup1XhciModule3Selcet=0;
	pNbCfg->TOPGroup1XhciGroup2Selcet=0;
	pNbCfg->TOPGroup1XhciGroup3Selcet=0;
	pNbCfg->TOPGroup1XhciMCUSelcet=0;
	pNbCfg->TOPGroup1SUSXhciSelcet=0;
	pNbCfg->TOPGroup1ModuleSubSelcet=0;
	/*
	pNbCfg->FSBCGroup0TopSelcet=0;
	pNbCfg->FSBCGroup1TopSelcet=0;
	pNbCfg->CPU_FSBC_DBG_04=0;
	pNbCfg->CPU_FSBC_DBG_05=0;
	pNbCfg->CPU_FSBC_DBG_06=0;
	pNbCfg->CPU_FSBC_DBG_07=0;
	pNbCfg->CPU_FSBC_DBG_08=0;
	pNbCfg->CPU_FSBC_DBG_09=0;
	pNbCfg->CPU_FSBC_DBG_0A=0;
	pNbCfg->CPU_FSBC_DBG_0B=0;
	pNbCfg->CPU_FSBC_DBG_0C=0;	
	pNbCfg->SOCCAP_Mem_Size=0;
	*/
	pNbCfg->CPU_FSBC_EN=0;
	pNbCfg->CPU_FSBC_PCIE_ON=0;
	pNbCfg->CPU_FSBC_TOPCIE=FSBC_PortG0;
	pNbCfg->CPU_FSBC_STREAM_EN=0;
	pNbCfg->CPU_FSBC_MISSPACKE_EN=0;
	pNbCfg->CPU_FSBC_TIGPULSE_EN=0;
	pNbCfg->CPU_FSBC_IFSBCSTP_EN=0;
		
#ifdef ZX_SECRET_CODE	
		pNbCfg->C2P2FlushC2M=0;
#endif
	pNbCfg->SB_HS_DBG_CH_SEL=SB_HS_DBG_CH_SEL_NORMAL_MODE;
	pNbCfg->SB_HS_DBG_SEL=SB_HS_DBG_SEL_DISABLE;
	pNbCfg->SB_HS_PCIE_PORT_SEL=PORT0;
	pNbCfg->VDD_OFF_EN=VDD_OFF_DBG_SEL_DISABLE;
	pNbCfg->VDD_OFF_Module_Sel=0;
	pNbCfg->VDD_OFF_Group_Sel=0;
	pNbCfg->MCU_UART_SEL=0;
	pNbCfg->VcpFileBaseAddr=0;
	pNbCfg->VcpFileSize=0;
	pNbCfg->IOVEnable=0;
	pNbCfg->IOVQIEnable=0;
	pNbCfg->IOVINTREnable=0;
	pNbCfg->TABar=0xFEB11000;
	pNbCfg->RoundRobin=0;
	pNbCfg->CRMCABar=0xFE020000;
	pNbCfg->RAIDA0Enable=FALSE;
	pNbCfg->RAIDA1Enable=FALSE;	
	pNbCfg->ZxeDualSocket=ZX_SINGLE_SOCKET_MODE;
	pNbCfg->IoeChipRevision=0;
	//PCIE 
	pNbCfg->Cnd003ModeSel=BIOS_MODE;
	pNbCfg->Cnd003PhyCfg=0x1;//Fixed
	pNbCfg->Cnd003PhyACfg=0x3;
	pNbCfg->Cnd003PhyBCfg=0x2;
	pNbCfg->Cnd003EpCap=0x3;
	pNbCfg->Cnd003CapPEA0=0x2;
	pNbCfg->Cnd003CapPEA1=0x2;
	pNbCfg->Cnd003CapPEA2=0x2;
	pNbCfg->Cnd003CapPEA3=0x2;
	pNbCfg->Cnd003CapPEA4=0x2;
	pNbCfg->Cnd003CapPEB0=0x2;
	pNbCfg->Cnd003CapPEB1=0x2;
	pNbCfg->Cnd003CapPESB=0x1;
	pNbCfg->Cnd003PcieRstTest=0;
	pNbCfg->Cnd003PEA0RstTest=0;
	pNbCfg->Cnd003PEA1RstTest=0;
	pNbCfg->Cnd003PEA2RstTest=0;
	pNbCfg->Cnd003PEA3RstTest=0;
	pNbCfg->Cnd003PEA4RstTest=0;
	pNbCfg->Cnd003PEB0RstTest=0;
	pNbCfg->Cnd003PEB1RstTest=0;
	pNbCfg->Cnd003LinkWidth=0;
	pNbCfg->Cnd003PcieEq=0;
	pNbCfg->Cnd003Autofill=1;
	pNbCfg->Cnd003BootErrorClear=1;
	pNbCfg->Cnd003ForceMPS128B=0;
	pNbCfg->Cnd003SwCtlDnPortLinkup=1;
	pNbCfg->Cnd003DebugFromCpu=0;
	pNbCfg->Cnd003ModuleG0=0x0;
	pNbCfg->Cnd003ModuleG1=0x0;
	pNbCfg->Cnd003DebugG0=0x0;
	pNbCfg->Cnd003DebugG1=0x0;
	pNbCfg->Cnd003DebugG2=0x0;
	pNbCfg->Cnd003DebugG3=0x0;
	pNbCfg->Cnd003DebugG0_XHCI=0x0;
	pNbCfg->Cnd003DebugG1_XHCI=0x0;
	pNbCfg->Cnd003DebugG2_XHCI=0x0;
	pNbCfg->Cnd003DebugG3_XHCI=0x0;
	pNbCfg->Cnd003HighSpeed=0x0;	
	pNbCfg->Cnd003DebugSuspend=0x0;
	pNbCfg->Cnd003HighSpeedModuleSel=0x0;
	pNbCfg->Cnd003HighSpeedDbgSel=0x0;
	pNbCfg->Cnd003CorePowerOff=0x0;
	pNbCfg->Cnd003DbgPadG0En=0x1;
	pNbCfg->Cnd003DbgPadG1En=0x1;
	pNbCfg->Cnd003DbgPadG2En=0x1;
	pNbCfg->Cnd003DbgPadG3En=0x1;
	pNbCfg->Cnd003UartPinEn=0x0;
#ifdef ZX_SECRET_CODE
	pNbCfg->Cnd003DIDVIDChoose=0x1;
#endif
	pNbCfg->Cnd003ChangeSIDForISB=0x1;
	pNbCfg->Cnd003SwDbg1=0x0;
	pNbCfg->Cnd003SwDbg2=0x0;
	//DBGCAP	
	pNbCfg->Cnd003DC=0;
	pNbCfg->Cnd003DCModule=0;
	pNbCfg->Cnd003DCTrans=0;
	pNbCfg->Cnd003DCCfgPath=0;
	pNbCfg->Cnd003DCChannel=0;
	pNbCfg->Cnd003DCDbg0Mask=0;
	pNbCfg->Cnd003DCDbg1Mask=0;
	pNbCfg->Cnd003DCTriggerMode=0;
	pNbCfg->Cnd003DCReqPtn=0;
	pNbCfg->Cnd003DCReqPtnMask=0;
	pNbCfg->Cnd003DCDataPtn=0;
	pNbCfg->Cnd003DCDataPtnMask=0;
	pNbCfg->Cnd003DCPlusTimer=0;
	pNbCfg->Cnd003DCStartTimer=0;
	pNbCfg->Cnd003DCPeriodTimer=0;
	pNbCfg->Cnd003DCOutput=1;
	pNbCfg->Cnd003HideXbctl=0;
	pNbCfg->Cnd003HideEptrfc=0;
	pNbCfg->Cnd003TCxFavor=0;
	pNbCfg->IOESPEValue=CHIP_SPE_VALUE_STABLE;
	pNbCfg->IOEXSPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D0F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D1F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D2F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D3F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D4F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D5F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D6F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D7F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp1D8F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp2D0F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEXp3D0F0SPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IOEMmioISBSPEValue=DEVICE_SPE_VALUE_STABLE;
	pNbCfg->IoeDnPortCtl=TRUE;
	pNbCfg->IoePEA0Ctl=FALSE;
	pNbCfg->IoePEA1Ctl=FALSE;
	pNbCfg->IoePEA2Ctl=FALSE;
	pNbCfg->IoePEA3Ctl=FALSE;
	pNbCfg->IoePEA4Ctl=FALSE;
	pNbCfg->IoePEB0Ctl=FALSE;
	pNbCfg->IoePEB1Ctl=FALSE;
	pNbCfg->IoeDnPortPEXRST=0;
	pNbCfg->IoePEA0PEXRST=0;
	pNbCfg->IoePEA1PEXRST=0;
	pNbCfg->IoePEA2PEXRST=0;
	pNbCfg->IoePEA3PEXRST=0;
	pNbCfg->IoePEA4PEXRST=0;
	pNbCfg->IoePEB0PEXRST=0;
	pNbCfg->IoePEB1PEXRST=0;
	pNbCfg->CND003PLLPCIEASSCEn=0;
	pNbCfg->CND003PLLPCIEASSCMagnitude=0;
	pNbCfg->CND003CKGSRCPLLPCIEASSCSpread=0;
	pNbCfg->CND003PLLPCIEBSSCEn=0;
	pNbCfg->CND003PLLPCIEBSSCMagnitude=0;
	pNbCfg->CND003CKGSRCPLLPCIEBSSCSpread=0;
	pNbCfg->CND003USBCLKSEL=0;
	pNbCfg->CND003SATACLKSEL=0;
	pNbCfg->CND003_RPCIE_PU_IO=0x3FF;
	pNbCfg->CND003_RPCIE_TNO_IO=0x3FF;

}

//////
VOID InitSbCfgStructDefaultValue(
	IN ASIA_SB_CONFIGURATION* pSbCfg)
{
	//// Init ASIA SB Cfg struct's default value
	pSbCfg->Signature=ASIA_SB_CONFIGURATION_SIGNATURE;
	//Chipset
	pSbCfg->CRBPlatformSelection=0;
	pSbCfg->SBSPEValue=CHIP_SPE_VALUE_STABLE;
	pSbCfg->SATASPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->VARTSPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->ESPISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->BusCtrlSPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->PMUSPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->PCCASPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->HDACSPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->SPISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->SOCXHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->SOCEHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->SOCUHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->IOVEnable=0;
	//UART
	pSbCfg->OnChipUartMode=ON_CHIP_UART_MODE_DISABLED;
	pSbCfg->UartModuleSelection=UART_MODULE_SEL_LEGACY;
	pSbCfg->Uart0Enable=TRUE;
	pSbCfg->Uart0_8PinEnable=FALSE;
	pSbCfg->Uart0IoBaseSelection=UART_IO_BASE_SEL_3F8;
	pSbCfg->Uart0IRQSelection=UART_IRQ_SEL_4;
	pSbCfg->Uart1Enable=TRUE;
	pSbCfg->Uart1IoBaseSelection=UART_IO_BASE_SEL_2F8;
	pSbCfg->Uart1IRQSelection=UART_IRQ_SEL_3;
	pSbCfg->Uart2Enable=TRUE;
	pSbCfg->Uart2IoBaseSelection=UART_IO_BASE_SEL_3E8;
	pSbCfg->Uart2IRQSelection=UART_IRQ_SEL_4;
	pSbCfg->Uart3Enable=TRUE;
	pSbCfg->Uart3IoBaseSelection=UART_IO_BASE_SEL_2E8;
	pSbCfg->Uart3IRQSelection=UART_IRQ_SEL_3;
	pSbCfg->UartFLREn=FALSE;
	//PMU_ACPI
	//C-State Control
	pSbCfg->ProcessorCState=PROCESSOR_CSTATE_DISABLED;
	pSbCfg->ConditionalC4=CONDITIONAL_C4_AUTO;
	pSbCfg->C5Control=FALSE;
	pSbCfg->C4BusMasterIdleTimer=0;
	pSbCfg->C3BusMasterIdleTimer=0;
	// Cx Latency Control
	pSbCfg->SVIDMVCLKControl=FALSE;
	pSbCfg->SVIDMPeriodicIoutControl=FALSE;
	pSbCfg->SVIDMC3Control=FALSE;
	pSbCfg->SVIDMC4C5Control=FALSE;
	pSbCfg->VRMStableBD=TRUE;
	pSbCfg->SVIDMC4SetPS=TRUE;
	pSbCfg->CPU2SVIDCmdGate=FALSE;
	pSbCfg->CPUPStateTOCounter=TRUE;
	pSbCfg->CPUPStateSetVIDDone=TRUE;
	pSbCfg->VRM0VIDFSSelect=VRM0_VID_SLOW;
	pSbCfg->SVIDMC4SetPSSel=C4_SETPS_PS1;
	pSbCfg->SVIDMC4DecayOP=C4_SETDECAY;
	pSbCfg->SVIDMC4SetVIDSel=C4_SETVID_FAST;
	pSbCfg->VRM0IoutTimer=0;
	
	pSbCfg->ShortC3C4Mode=TRUE;
	pSbCfg->DPSLPtoSLP=DPSLP_TO_SLP_10;
	pSbCfg->VRDSLPtoDPSLP=VRDSLP_TO_DPSLP_00;
	// Dynamic Clock Control
	pSbCfg->SBDynamicClkControl=FALSE;
	//pSbCfg->TMRCDynamicClkControl=FALSE;
	//Other Control
	pSbCfg->MobileCenterControl=FALSE;
	pSbCfg->ACAdapterControl=FALSE;
	pSbCfg->PLLOKSelectionControl=PLL_OK_SEL_CTL_LOGIC;
	pSbCfg->CpuFanStartTemperature=2;
	pSbCfg->MsiSupport=FALSE;
	pSbCfg->LPTControl=FALSE;
	pSbCfg->FixedFreeCxLatency=FIX_FREE_CX_LATENCY_FREE;
	pSbCfg->DynamicT05=TRUE;
	//Power Gating
	pSbCfg->eBMCSettleTime=0;
#ifdef ZX_SECRET_CODE
	pSbCfg->KBDCLegacySelControl=FALSE;
	pSbCfg->TMRCLegacySelControl=FALSE;
#endif
	pSbCfg->INTCLegacySelControl=TRUE;
	pSbCfg->DMACLegacySelControl=TRUE;
	//SATA
	pSbCfg->SataEn=TRUE;
	pSbCfg->SataCfg=0;
	pSbCfg->IDEGen=1;
	pSbCfg->AHCIGen=1;
	pSbCfg->IDECapSelect=0;
	pSbCfg->IDEHIPMEn=0;
	pSbCfg->AHCIMSI=0;
	pSbCfg->AHCIMSIX=0;
	pSbCfg->AHCIHotplugEn=0;
	pSbCfg->AHCIALPMEn=0;
	pSbCfg->FuncLevelResetEn=0;
	pSbCfg->GBFlushendEn=0;
	// USB
	pSbCfg->UsbModeSelect=USB_MODE_SEL_MODED;
#ifdef ZX_DUALSOCKET
	pSbCfg->UsbModeSelectSlave  = USB_MODE_SEL_MODED;
#endif
	pSbCfg->UsbS4WakeupCtrl=USB_S4WAKEUP_DISABLE;
	pSbCfg->UsbOCCtrl=USB_OC_DISABLE;
	pSbCfg->USBCFLRCtrl=USBC_FLR_ENABLE;
	pSbCfg->XhcMcuDmaPathCtrl=XHC_MCUDMAPATH_SNOOP;
#ifdef ZX_DUALSOCKET
	pSbCfg->XhcMcuDmaPathCtrlSlave = XHC_MCUDMAPATH_SNOOP;
#endif
	pSbCfg->XhcTRBCacheBypassCtrl=XHC_TRB_CACHE_NOT_BYPASS;
	pSbCfg->XhcBurstCtrl=XHC_OUTBURST_DISABLE;
	pSbCfg->XhcPerfModeCtrl=XHC_PERF_MODE_DISABLE;
	pSbCfg->XhcU1U2Ctrl=XHC_PORTU1U2_ENABLE;
	pSbCfg->XhcMsiFlushCtrl=XHC_MSIFLUSH_DISABLE;
	pSbCfg->XhcUartCtrl=XHC_XHCIUART_DISABLE;
	pSbCfg->XhcFLRCtrl=XHC_FLR_ENABLE;
	pSbCfg->XhcRTD3Ctrl=XHC_RTD3_ENABLE;
	pSbCfg->XhcC4BlockCtrl=XHC_C4BLOCK_DISABLE;
	pSbCfg->XhcEITRNCtrl=XHC_EITRN_DISABLE;
	//HDAC 
	pSbCfg->Azalia=FALSE;
	pSbCfg->GoNonSnoopPath=FALSE;
	pSbCfg->HDACFLREn=TRUE;
	//SNMI
	pSbCfg->IsoLPC=FALSE;
	pSbCfg->IsoVART=FALSE;
	pSbCfg->IsoAZALIA=FALSE;
	pSbCfg->IsoESPI=FALSE;
	pSbCfg->IsoSPI=FALSE;
	pSbCfg->IsoAPIC=FALSE;
	//Others
	pSbCfg->EnableMultimediaTimer=TRUE;
	pSbCfg->MultimediaTimerMode=0;
	pSbCfg->EnableMultimediaTimerMsi=0;
	pSbCfg->WatchDogTimer=TRUE;
	pSbCfg->WatchDogTimerRunStop=WATCHDOG_TIMER_STOP;
	pSbCfg->WatchDogTimerAction=WATCHDOG_TIMER_ACTION_POWEROFF;
	pSbCfg->WatchDogTimerCount=WATCHDOG_TIMER_COUNT_1023S;
	pSbCfg->KBMouseWakeupControl=TRUE;
	pSbCfg->SMBusControllerUnderOS=FALSE;
	pSbCfg->SMBHostClockFrequencySelect=FALSE;
	pSbCfg->SMBHostClockFrequency=0x16;
	pSbCfg->SPIBus0ClockSelect=SPI_BUS0_CLK_48MHZ;
	pSbCfg->ESPI=FALSE;
//HYL-2018062901-start
#ifdef ZX_SECRET_CODE
	pSbCfg->WDTClear=0;	
#endif
//HYL-2018062901-end
	pSbCfg->FsbcMemSize=0;
	pSbCfg->ApicEnable=TRUE;
	pSbCfg->AcpiIrq=0x9;
	pSbCfg->PmioBar=0x800;
	pSbCfg->ApicBar=0xFEC00000;
	pSbCfg->SbApicID=0x09;
	pSbCfg->HpetBar=0xFEB40000;
	pSbCfg->WatchDogBar=0xFEB41000;
	pSbCfg->D17F0MmioBar=0xFEB32000;
	pSbCfg->SpiBar=0xFEB30000;
#ifdef ZX_SECRET_CODE
	pSbCfg->VidSelect=VID_OTHER;
#endif
	pSbCfg->ZxeDualSocket=ZX_SINGLE_SOCKET_MODE;
	//CND003/IOE related
	pSbCfg->IOESPEValue=CHIP_SPE_VALUE_STABLE;
	pSbCfg->IOEGNICSPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->IOESATASPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->IOEXHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->IOEEHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	pSbCfg->IOEUHCISPEValue=DEVICE_SPE_VALUE_STABLE;
	//CND003 TOP
	pSbCfg->IoeChipRevision=0;
	pSbCfg->Cnd003ModeSel=0;
	pSbCfg->Cnd003DebugFromCpu=0;
	pSbCfg->Cnd003ModuleG0=0;
	pSbCfg->Cnd003ModuleG1=0;
	pSbCfg->Cnd003DebugG0=0;
	pSbCfg->Cnd003DebugG1=0;
	pSbCfg->Cnd003DebugG2=0;
	pSbCfg->Cnd003DebugG3=0;
	pSbCfg->Cnd003DebugG0_XHCI=0;
	pSbCfg->Cnd003DebugG1_XHCI=0;
	pSbCfg->Cnd003DebugG2_XHCI=0;
	pSbCfg->Cnd003DebugG3_XHCI=0;
	pSbCfg->Cnd003HighSpeed=0;
	pSbCfg->Cnd003DebugSuspend=0;
	pSbCfg->Cnd003HighSpeedModuleSel=0;
	pSbCfg->Cnd003HighSpeedDbgSel=0;
	pSbCfg->Cnd003CorePowerOff=0;
	pSbCfg->Cnd003DbgPadG0En=1;
	pSbCfg->Cnd003DbgPadG1En=1;
	pSbCfg->Cnd003DbgPadG2En=1;
	pSbCfg->Cnd003DbgPadG3En=1;
	pSbCfg->Cnd003UartPinEn=0;
	//DBGCAP
	pSbCfg->Cnd003DC=0;
	pSbCfg->Cnd003DCModule=0;
	pSbCfg->Cnd003DCTrans=0;
	pSbCfg->Cnd003DCCfgPath=0;
	pSbCfg->Cnd003DCChannel=0;
	pSbCfg->Cnd003DCDbg0Mask=0;
	pSbCfg->Cnd003DCDbg1Mask=0;
	pSbCfg->Cnd003DCTriggerMode=0;
	pSbCfg->Cnd003DCReqPtn=0;
	pSbCfg->Cnd003DCReqPtnMask=0;
	pSbCfg->Cnd003DCDataPtnMask=0;
	pSbCfg->Cnd003DCPlusTimer=0;
	pSbCfg->Cnd003DCStartTimer=0;
	pSbCfg->Cnd003DCPeriodTimer=0;
	pSbCfg->Cnd003DCOutput=1;
	pSbCfg->Cnd003HideXbctl=0;
	pSbCfg->Cnd003HideEptrfc=0;
	//IOE_GNIC
	pSbCfg->IOEGnicEn=TRUE;
	pSbCfg->IOEGnicVEEPROM=TRUE;
	pSbCfg->IOEGnicTXDCS=0x1;
	pSbCfg->IOEGnicTXDC0=0xFF;
	pSbCfg->IOEGnicTXDC1=0;
	pSbCfg->IOEGnicTXDC2=0;
	pSbCfg->IOEGnicRXDCS=1;
	pSbCfg->IOEGnicRXDC0=0xFF;
	pSbCfg->IOEGnicRXDC1=0;
	pSbCfg->IOEGnicRXDC2=0;
	pSbCfg->IOEGnicDPDC64=0;
	pSbCfg->IOEGnicDPDC128=0;
	pSbCfg->IOEGnicDPDC256=0;
	pSbCfg->IOEGnicForceSizeEn=0;
	pSbCfg->IOEGnicForceRDR=0;
	pSbCfg->IOEGnicForcePayload=0;
	pSbCfg->IOEGnicEventCtrl=0;
	pSbCfg->IOEGnicPendingCtrl=0;
	pSbCfg->IOEGnicMsiCtrl=TRUE;
	pSbCfg->IOEGnicMsiXCtrl=TRUE;
	pSbCfg->IOEGnicD0PME=TRUE;
	//IOE_SATA
	pSbCfg->IOESataEn=TRUE;
	pSbCfg->IOESataCfg=0;
	pSbCfg->IOEAHCIGen=1;
	pSbCfg->IOESataGen=1;
	pSbCfg->IOEAHCI_MSI=0;
	pSbCfg->IOEAHCI_MSIX=0;
	pSbCfg->IOESataCapSelect=0;
	pSbCfg->IOESataHIPMEn=0;
	pSbCfg->IOESataHpcpEn=0;
	pSbCfg->IOESataALPMEn=1;
	pSbCfg->IOEFunctionLevelEnabled=0;
	// CND003 USB
	pSbCfg->IOEUsbModeSelect=IOEUSB_MODE_SEL_MODEC;
	pSbCfg->IOETRBCacheBypass=IOETRB_CACHE_NOT_BYPASS;
	pSbCfg->IOEXhciOutBurstEn=IOEUSB_OUTBURST_ENABLE;
	pSbCfg->IOEUSBCFLRControl=IOEUSBC_FLR_ENABLE;
	pSbCfg->IOEXHCIFLRControl=IOEXHCI_FLR_ENABLE;
	pSbCfg->IOERTD3Control=IOERTD3_ENABLE;
	pSbCfg->IOEUsbS4Wakeup=FALSE;
	pSbCfg->IOEUsbC4Block=FALSE;
	pSbCfg->IOEUsb10GSupport=IOEUSB10G_DISABLE;
	pSbCfg->IOEUsbOCEn=IOEUSBOC_DISABLE;
	pSbCfg->IOEUsbEITRN=IOEUSBEITRN_DISABLE;
	
}

//////
VOID InitDramCfgStructDefaultValue(
	IN ASIA_DRAM_CONFIGURATION* pDramCfg)
{
	//// Init ASIA DRAM Cfg struct's default value
	pDramCfg->Signature=ASIA_DRAM_CONFIGURATION_SIGNATURE;
	pDramCfg->DramClk=DRAM_CLK_BY_SPD;
	pDramCfg->ACTimingOption=ACTIMING_AUTO;
	pDramCfg->DramVoltageControl=0;
	pDramCfg->DramCL=CL_AUTO;
	pDramCfg->DramTrcd=TRCD_AUTO;
	pDramCfg->DramTrp=TRP_AUTO;
	pDramCfg->DramTras=TRAS_AUTO;
	pDramCfg->RxIoTimingMethod=RX_SI_SI;
	pDramCfg->DQSIByRank=BYRANK_ENABLE;
	pDramCfg->TxIoTimingMethod=TX_SI_SI;
	pDramCfg->LimitRankSize=LIMIT_SIZE_AUTO;
	pDramCfg->BankIntlv=BANK_INTERLEAVE_NONPAGE;
	pDramCfg->MemoryChipODTDebug=MEM_CHIP_ODT_DBG_AUTO;
	pDramCfg->MemoryChipODTWRDebug=MEM_CHIP_ODT_DBG_AUTO;
	pDramCfg->MemoryChipODTParkDebug=MEM_CHIP_ODT_DBG_AUTO;
	pDramCfg->VRIntlv=VRANK_INTERLEAVE_DISABLED;
//	pDramCfg->ChannelIntlv=CHAN_INTERLEAVE_DISABLED;
	pDramCfg->BASelect=SELECT_A16;
	pDramCfg->DataScmb=FALSE;
	pDramCfg->RDRDY=RDRDY_DEFAULT;
	pDramCfg->ConversionCircuit=CONVERSION_CIRCUIT_AUTO;
	pDramCfg->BurstLength=BURST_LENGTH_ON_THE_FLY;
	pDramCfg->CmdRate=CMD_RATE_2T;
	pDramCfg->VGAShareMemory=VGA_SHARE_MEM_AUTO;
	pDramCfg->DramInitMethod=DRAM_INIT_METHOD_AUTO;
	pDramCfg->DramSelfRefresh=TRUE;
	pDramCfg->DynamicCKE=TRUE;
	pDramCfg->RemapEn=TRUE;
	pDramCfg->PCIMemoryStart=0x800;
	pDramCfg->ScanIOTiming=FALSE;
	pDramCfg->DRAMECC=FALSE;
	pDramCfg->ECCClearMemory=FALSE;
	pDramCfg->EccPatrolScrub=FALSE;
	pDramCfg->EccRetry=FALSE;
	pDramCfg->DRAMErrControl=ECC_DISABLE;
	pDramCfg->CRCEn=FALSE;
	pDramCfg->CRCErrControl=CRC_DISABLE;
	pDramCfg->CAParEn=FALSE;
	pDramCfg->CAParPerEn=FALSE;
	pDramCfg->ParErrControl=PAR_DISABLE;
	pDramCfg->CRCParRetryEn=FALSE;
	pDramCfg->WPREA=WPREA1CLK;
	pDramCfg->RPREA=RPREA1CLK;
	pDramCfg->CALEn=FALSE;
	//pDramCfg->CPU_FSBC_ON=FALSE;
	pDramCfg->DramFastBoot=DRAM_FAST_BOOT_DISABLE;
	pDramCfg->DramRxTxTimingHardCode=DRAM_RXTX_TIMING_HARDCODE_DISABLE;
	pDramCfg->CHdecode=DRAM_CH_DECODE_AUTO;
	pDramCfg->BankGroupBit0Decode=BG_DECODE_A7_A14;
	pDramCfg->TxVref=TX_VREF_SI;
	pDramCfg->TxVrefAllByte=TX_VREFALLBYTE_DISABLE;
	pDramCfg->RxVref=RX_VREF_SI ;
	pDramCfg->RRankRDelay=RRankRDLY_DEFAULT;
	pDramCfg->RRankWDelay=RRankWDLY_DEFAULT;
	pDramCfg->ZxeDualSocket=ZX_SINGLE_SOCKET_MODE;
	pDramCfg->Above4GEnable = 0;
	pDramCfg->Above4GLocation = 0;
	
}
////

//////
