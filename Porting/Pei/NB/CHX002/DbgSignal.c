/** @file
   ZX-E(CHX002) Asia NbPei library functions : DbgSignal.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

#include "Pei.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaNbPeim.h"
#include "AsiaIoLib.h"
#include "CPUIA32.h"

/**
   This Function will program SB Debug signal.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param  GroupIndex  Debug signal group index value
  @param IsSusDebug  Sus domain debug signal flag

  @return The value from this function.

**/
void
ProgramSbDebugSignal(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINTN	GroupIndex,
    IN  BOOLEAN   IsSusDebug
)
{
    UINT32	SbMmioBar;
    UINT16 PmioBar;
    UINT32     D17F0_MMIO_BaseAddress;
    UINT32     SPI_BaseAddress;

    // PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n"));
    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA:ProgramSbDebugSignal()\n"));

    SbMmioBar = (AsiaPciRead32(CHX002_BUSC|D17F0_MMIO_SPACE_BASE_ADR))<<8;
    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA:SbMmioBar=0x%x\n",SbMmioBar));

    PmioBar = AsiaPciRead16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE) & 0xFF00;
    D17F0_MMIO_BaseAddress = ((UINT32)(AsiaPciRead32(CHX002_BUSC|D17F0_MMIO_SPACE_BASE_ADR)))<<8;
    SPI_BaseAddress        = AsiaMemoryRead32(D17F0_MMIO_BaseAddress + 0x00)&(0xFFFFFF00);

    if (NbConfig->DebugSBselectByNB == SB_SELECT_BY_NB)	{
        // SB select by NB
        if( !IsSusDebug ) {
            //normal debug mode
            //	PEI_DEBUG((PeiServices, EFI_D_ERROR, " if SB_SELECT_BY_NB\n"));
            if(GroupIndex==0) {
                switch(NbConfig->SBTopDbgMux1) {
                    case SB_TOP_DEBUG_MUX_1_RTC:
                        AsiaIoModify8(PmioBar + PMIO_CHX002_VDDOFF_GRP_DEBUG_SIGNAL_SEL_REG, PMIO_RDBGVDDOFF_GRP_SEL7_0, (UINT8)NbConfig->SBGroup0ModuleSubSelect); //PMIO RxF8[7:0]
                        AsiaIoModify8(PmioBar + PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_ENABLE_REG, PMIO_RDBGVDDOFFMODE, BIT0); //PMIO RxFA[0]=1
                        break;
                    case SB_TOP_DEBUG_MUX_1_D14_USBC_SUS:
                    case SB_TOP_DEBUG_MUX_1_D16_USBC_SUS:
                        AsiaIoModify8(PmioBar+PMIO_CHX002_VDDOFF_GRP_DEBUG_SIGNAL_SEL_REG,PMIO_RDBGVDDOFF_GRP_SEL7_0,(UINT8)NbConfig->SBGroup0ModuleSubSelect);//PMIO RxF8[7:0]
                        break;
                    default:
                        break;
                }
                //Group 0 SB SubModule select
                AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,(D0F4_RDBGMX_NBTOP_G0_RSP_5 |D0F4_RDBGMX_NBTOP_G0_RSP_4 | D0F4_RDBGMX_NBTOP_G0_RSP_3_0),NbConfig->SBTopDbgMux1<<20);
                AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,D0F4_RDBGMX_MODULE_G0_RSP_19_0,NbConfig->SBGroup0ModuleSubSelect);
            } else {
                switch(NbConfig->SBTopDbgMux2) {
                    case SB_TOP_DEBUG_MUX_2_RTC_G2:
                        AsiaIoModify8(PmioBar + PMIO_CHX002_VDDOFF_GRP_DEBUG_SIGNAL_SEL_REG, PMIO_RDBGVDDOFF_GRP_SEL7_0, (UINT8)NbConfig->SBGroup1ModuleSubSelect); //PMIO RxF8[7:0]
                        AsiaIoModify8(PmioBar + PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_ENABLE_REG, PMIO_RDBGVDDOFFMODE, BIT0); //PMIO RxFA[0]=1
                        break;
                    case SB_TOP_DEBUG_MUX_2_D14_USBC_SUS_G2:
                    case SB_TOP_DEBUG_MUX_2_D16_USBC_SUS_G2:
                        AsiaIoModify8(PmioBar+PMIO_CHX002_VDDOFF_GRP_DEBUG_SIGNAL_SEL_REG,PMIO_RDBGVDDOFF_GRP_SEL7_0,(UINT8)NbConfig->SBGroup1ModuleSubSelect);//PMIO RxF8[7:0]
                        break;
                    default:
                        break;
                }
                //Group 1  SB SubModule  select
                AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RDBGMX_NBTOP_G1_RSP_5_0,NbConfig->SBTopDbgMux2<<20);
                AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RDBGMX_MODULE_G1_RSP_19_0,NbConfig->SBGroup1ModuleSubSelect);
            }
            // disable SB debug signal.
            AsiaIoModify16(PmioBar|PMIO_DEBUG_SIGNAL_SEL_REG,PMIO_DBGSEL_SBG, 0);//PMIO RxD5[15]=0 disable SB debug signal
        } else {
            //sus debug mode
            // PEI_DEBUG((PeiServices, EFI_D_ERROR, "  if SB_SELECT_BY_NB\n"));

            if(GroupIndex==0) {
                //Group 0 SB SubModule select
                AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_1,D0F4_RDBGMX_NBTOP_G0_SUS_4_0,NbConfig->SBTopDbgMux1);//RxA9[4:0] G0

                AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_3,D0F4_RDBGMX_MODULE_G0_SUS_19_12,(UINT8) (NbConfig->SBGroup0ModuleSubSelect>>12));//RxAB[7:0]
                AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,D0F4_RDBGMX_MODULE_G0_SUS_11_0,NbConfig->SBGroup0ModuleSubSelect << 20 );//RxAC[31:20]
            } else if(GroupIndex==1) {
                //Group 1  SB SubModule  select
                AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_2,D0F4_RDBGMX_NBTOP_G1_SUS_4_0,NbConfig->SBTopDbgMux2);//RxAA[4:0] G1 Module
                AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,D0F4_RDBGMX_MODULE_G1_SUS_19_0,NbConfig->SBGroup1ModuleSubSelect);//RxAC[19:0] G1 group
            }
        }
    } else {
        // SB select by SB
        // PEI_DEBUG((PeiServices, EFI_D_ERROR, " else if SB_SELECT_BY_SB\n"));
        if(GroupIndex==0) {
            AsiaIoModify8(PmioBar+PMIO_DEBUG_SIGNAL_SEL_REG,0x1F, (UINT8)(NbConfig->SBTopDbgMux1));//PMIO RxD5[4:0] select module
            switch(NbConfig->SBTopDbgMux1) {
                case SB_TOP_DEBUG_MUX_1_CCA:
                    AsiaPciModify8(CHX002_PCCA|D17F7_CCA_TEST_MODE_ADR_SEL_Z1,D17F7_RCCADBG_MODE_3_0,(UINT8)NbConfig->SBGroup0ModuleSubSelect);	//D17F7 Rx83[3:0]=XXX
                    break;
                case SB_TOP_DEBUG_MUX_1_PCI1:
                    AsiaPciModify8(CHX002_PCCA|D17F7_PCI1_DEBUG_SIGNAL_SEL,D17F7_RPCI1DBG_MODE1_3_0,(UINT8)NbConfig->SBGroup0ModuleSubSelect);//D17F7 RxFD[3:0]=XXX
                    break;
                case SB_TOP_DEBUG_MUX_1_SPI:
                    AsiaMemoryModify8(SPI_BaseAddress+SPI0MMIO_SPI_DEBUG_SIGNAL_SEL_REG,SPI0MMIO_DBG_GRP_SEL_REG,((UINT8)NbConfig->SBGroup0ModuleSubSelect));//SPI MMIO RxE4[7:0]=XX
                    AsiaMemoryModify32(SPI_BaseAddress+SPI0MMIO_SPI_DEBUG_SIGNAL_SEL_REG,BIT8,BIT8);//SPI MMIO RxE4[8]=1
                    break;
                case SB_TOP_DEBUG_MUX_1_PMU:
                    AsiaPciModify8(CHX002_BUSC|D17F0_PMU_PMU_DEBUG_SIGNAL_SEL_CTL, 0x0F, (UINT8)NbConfig->SBGroup0ModuleSubSelect);//D17F0 RxDE[3:0] Select group
                    break;
                case SB_TOP_DEBUG_MUX_1_AZ:
                    AsiaPciModify8(CHX002_HDAC|D20F0_BACK_DOOR_Z1,D20F0_AZDBG_SEL1,((UINT8)NbConfig->SBGroup0ModuleSubSelect)<<3);//D20F0 Rx433[7:3]
                    break;
                case SB_TOP_DEBUG_MUX_1_eBMC_OUT1:
                    AsiaIoModify8(PmioBar|PMIO_SME_DEBUG_PIN_DEV_ENABLE_REG_Z1, PMIO_EBMC_DBGEN, PMIO_EBMC_DBGEN);//PMIO RxD2[0]=1
                    AsiaIoModify8(PmioBar|PMIO_SME_DEBUG_PIN_DEV_ENABLE_REG, PMIO_EBMCD_DBGS, ((UINT8)NbConfig->SBGroup0ModuleSubSelect));//PMIO RxD0[7:0]
                    break;
                case SB_TOP_DEBUG_MUX_1_PNP:
                    AsiaMemoryModify8(SbMmioBar + D17F0MMIO_PNP_DEBUG_PIN_SEL,D17F0MMIO_PNP_DBGS,((UINT8)NbConfig->SBGroup0ModuleSubSelect)<<2);//D17F0 MMIO Rx12[4:2]=xx
                    break;
                case SB_TOP_DEBUG_MUX_1_NEW_KBDC:
                    AsiaIoWrite8(0x64,0x61);//IO Rx64=61
                    AsiaIoWrite8(0x60, ((UINT8)NbConfig->SBGroup0ModuleSubSelect));//IO Rx60=XX
                    break;
                case SB_TOP_DEBUG_MUX_1_NEW_PIC:
                    AsiaMemoryModify8(SbMmioBar + D17F0MMIO_PIC_DEBUG_SEL_REG,D17F0MMIO_PIC_DBG1_SEL,((UINT8)NbConfig->SBGroup0ModuleSubSelect));//D17F0 MMIO Rx70[3:0]=xx
                    break;
                case SB_TOP_DEBUG_MUX_1_ESPI_IO:
                    AsiaMemoryModify8(SbMmioBar + 0x6E,0x03,((UINT8)NbConfig->SBGroup0ModuleSubSelect));//D17F0 MMIO Rx6E[1:0]=xx
                    break;
                default:
                    break;
            }
        } else {
            AsiaIoModify8(PmioBar+PMIO_DEBUG_SIGNAL_SEL_REG+1,0x1F, (UINT8)(NbConfig->SBTopDbgMux2));//PMIO RxD5[12:8] select module
            switch(NbConfig->SBTopDbgMux2) {
                case SB_TOP_DEBUG_MUX_2_CCA_G2:
                    AsiaPciModify8(CHX002_PCCA|D17F7_CCA_TEST_MODE_ADR_SEL_Z1,D17F7_RCCADBG_MODE2_3_0,((UINT8) NbConfig->SBGroup1ModuleSubSelect)<<4);//D17F7 Rx83[7:4]=XX
                    break;
                case SB_TOP_DEBUG_MUX_2_PCI1_G2:
                    AsiaPciModify8(CHX002_PCCA|D17F7_PCI1_DEBUG_SIGNAL_SEL,D17F7_RPCI1DBG_MODE2_3_0,((UINT8) NbConfig->SBGroup1ModuleSubSelect)<<4);//D17F7 RxFD[7:4]=XX
                    break;
                case SB_TOP_DEBUG_MUX_2_SPI_G2:
                    AsiaMemoryModify32(SPI_BaseAddress+SPI0MMIO_SPI_DEBUG_SIGNAL_SEL_REG,SPI0MMIO_RESERVED_Z22,SPI0MMIO_RESERVED_Z22);//SPI MMIO RxE4[24]=1
                    AsiaMemoryModify32(SPI_BaseAddress+SPI0MMIO_SPI_DEBUG_SIGNAL_SEL_REG,SPI0MMIO_DBG_GRP_G2_SEL_REG,((UINT8) NbConfig->SBGroup1ModuleSubSelect)<<16); 	//SPI MMIO RxE4[23:16]=XX
                    break;
                case SB_TOP_DEBUG_MUX_2_PMU_G2:
                    AsiaPciModify8(CHX002_BUSC|D17F0_PMU_PMU_DEBUG_SIGNAL_SEL_CTL, 0xF0,((UINT8) NbConfig->SBGroup1ModuleSubSelect)<<4);//D17F0 RxDE[7:4] Select group
                    break;
                case SB_TOP_DEBUG_MUX_2_AZ_G2:
                    AsiaPciModify8(CHX002_HDAC|D20F0_DEBUG_SIGNAL_SEL,0x1F,((UINT8) NbConfig->SBGroup1ModuleSubSelect));//D20F0 Rx48[4:0]=xx
                    break;
                case SB_TOP_DEBUG_MUX_2_eBMC_OUT2:
                    AsiaIoModify8(PmioBar|PMIO_SME_DEBUG_PIN_DEV_ENABLE_REG_Z1, PMIO_EBMC_DBGEN, PMIO_EBMC_DBGEN);//PMIO RxD2[0]=1
                    AsiaIoModify8(PmioBar|PMIO_SME_DEBUG_PIN_DEV_ENABLE_REG, PMIO_EBMCD_DBGS, ((UINT8) NbConfig->SBGroup1ModuleSubSelect));//PMIO RxD0[7:0]=XX;
                    break;
                case SB_TOP_DEBUG_MUX_2_PNP_G2:
                    AsiaMemoryModify8(SbMmioBar + D17F0MMIO_PNP_DEBUG_PIN_AND_SW_INTR,D17F0MMIO_PNP_DBGS_G2,((UINT8) NbConfig->SBGroup1ModuleSubSelect)<<5);//D17F0 MMIO Rx0B[7:5]=xx
                    break;
                case SB_TOP_DEBUG_MUX_2_NEW_KBDC_G2:
                    AsiaIoWrite8(0x64,0x62);//IO Rx64=62
                    AsiaIoWrite8(0x60, ((UINT8) NbConfig->SBGroup1ModuleSubSelect));// IO Rx60=XX
                    break;
                case SB_TOP_DEBUG_MUX_2_NEW_PIC_G2:
                    AsiaMemoryModify8(SbMmioBar + D17F0MMIO_PIC_DEBUG_SEL_REG,D17F0MMIO_PIC_DBG2_SEL,((UINT8) NbConfig->SBGroup1ModuleSubSelect)<<4);//D17F0 MMIO Rx70[7:4]=xx
                    break;
                case SB_TOP_DEBUG_MUX_2_ESPI_IO_G2:
                    AsiaMemoryModify8(SbMmioBar + 0x6E,0x03,((UINT8)NbConfig->SBGroup1ModuleSubSelect));//D17F0 MMIO Rx6E[1:0]=xx
                    break;
                default:
                    break;
            }
        }
        // Enable SB debug signal.
        AsiaIoModify16(PmioBar|PMIO_DEBUG_SIGNAL_SEL_REG,PMIO_DBGSEL_SBG, PMIO_DBGSEL_SBG);//PMIO RxD5[15]=1 Enable SB debug signal
    }
}

/**
   This Function will program Debug signal.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/
void
ProgramDebugSignal(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    UINT16	SbPmioBar;
    UINT32 SbMmioBar,Value;
    UINT64 SBHS_PCIESelect=0;

    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n"));
    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA_0622:ProgramDebugSignal()\n"));

    SbPmioBar = (AsiaPciRead16(CHX002_BUSC|D17F0_PMU_PM_IO_BASE)) & 0xFF00 ;//acpi io base
    SbMmioBar = (AsiaPciRead32(CHX002_BUSC|D17F0_MMIO_SPACE_BASE_ADR))<<8;

    /*PEI_DEBUG((PeiServices, EFI_D_ERROR, "bf:Rx42=0x%02x;\n",AsiaPciRead8(CHX002_NPMC|0x42)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "bf:Rx44=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0x44)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "bf:Rx48=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0x48)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "bf:RxA8=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0xA8)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "bf:RxAC=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0xAC)));*/

    //keep romsip debug signal configuration
    if ((NbConfig->DebugMode == SkipDebug) );

    //disable chip debug mode,
    else if (NbConfig->DebugMode == DisabledDebug){
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":disable Debug\n"));

        AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0, D0F4_RRDBGMODE,0x00); // Disable Debug mode
        AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGMODE_SUS,0x00); // Disable SUS Debug mode
    }
    //normal debug or sus debug
    else {
        if(NbConfig->DebugMode == NormalDebug) {
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGMODE_SUS,0);  // RxA8[7]=0 Disable SUS Debug mode

            //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":NormalDebug\n"));
            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,D0F4_RRDBGCHSEL_1_0,NbConfig->DebugOutputSelect << 26);//Rx48[27:26]
            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,D0F4_RRDBGCHDVPSEL,BIT28);//RX48[28]=1
            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RRGFXDBGSEL_G0,NbConfig->DebugSignalSelect0<<26);//Rx44[26]
            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RRDBGNBSBSEL_G0_1_0,NbConfig->DebugModuleSelect0<<28);//Rx44[29:28]
            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RRGFXDBGSEL_G1,NbConfig->DebugSignalSelect1<<27);//Rx44[27]
            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,D0F4_RRDBGNBSBSEL_G1_1_0,NbConfig->DebugModuleSelect1<<29);//RX48[30:29]
            if( (NbConfig->DebugSignalSelect0==GroupNBSB_Signal)||(NbConfig->DebugSignalSelect1==GroupNBSB_Signal)) {
                if(NbConfig->DebugModuleSelect0==DEBUG_SELECT_NB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":SDebugModuleSelect0=DEBUG_SELECT_NB\n"));

                    //Group 0 NB SubModule select
                    AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,(D0F4_RDBGMX_NBTOP_G0_RSP_5 |D0F4_RDBGMX_NBTOP_G0_RSP_4 | D0F4_RDBGMX_NBTOP_G0_RSP_3_0),NbConfig->NBGroup0TopSelect<<20);//Rx48[25:20]
                    AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1, D0F4_RDBGMX_MODULE_G0_RSP_19_0, (NbConfig->NBGroup0ModuleSubSelect2<<10)|NbConfig->NBGroup0ModuleSubSelect1);
                } else if(NbConfig->DebugModuleSelect0==DEBUG_SELECT_SB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":SDebugModuleSelect0=DEBUG_SELECT_SB\n"));

                    AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,NbConfig->DebugSBselectByNB<<2);//D0F4 Rx42[2] = 1
                    ProgramSbDebugSignal(PeiServices,NbConfig,0,FALSE);
                } else if (NbConfig->DebugModuleSelect0 == DEBUG_SELECT_TOP) {
                    if(NbConfig->TOPGroup0TopSelcet ==TOP_DEBUG_XHCI) {
                        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
                        AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, BIT14);

                        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,0);//D0F4 Rx42[2] =0
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX65_XHCOPTRX65, D18F0_MCU_DBGEN,D18F0_MCU_DBGEN);//XHCOPTRx65[0] = 1b

                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX56_XHCOPTRX56, D18F0_R_XHCI_PTN_DBG_SEL_G0,NbConfig->TOPGroup0XhciModule0Selcet);//G0:Rx56[3:0]
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX56_XHCOPTRX56, D18F0_R_XHCI_PTN_DBG_SEL_G1,NbConfig->TOPGroup0XhciModule1Selcet<<4);//G1:Rx56[7:4]

                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,D18F0_CPU_OPTCFG);//D18F0 PCI Rx43[0] = 1b Enable Level 2 Access
                        //G0 group ->Rx144[11:0]
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x144); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0xFFF,NbConfig->TOPGroup0XhciGroup0Selcet); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        //G1 group ->Rx144[27:16]
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x144); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0xFFF0000,NbConfig->TOPGroup0XhciGroup1Selcet<<16); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,0);//D18F0 PCI Rx43[0] = 1b Disable  Level 2 Access

                        //MCU group ->Rx64[3:0]
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX64_XHCOPTRX64, D18F0_MCU_DBG_SEL,NbConfig->TOPGroup0XhciMCUSelcet);//Rx64[3:0] =xxx
                    } else if(NbConfig->TOPGroup0TopSelcet ==TOP_DEBUG_XHCI_TXCDC) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,D0F4_RRDBGSBSELBYNB);//D0F4 Rx42[2] =1
                        AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,0x1F00000,NbConfig->TOPGroup0ModuleSubSelcet<<20);//Rx48[24:20]
                    } else if(NbConfig->TOPGroup0TopSelcet ==TOP_DEBUG_SATA) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,0);//D0F4 Rx42[2] =0 sel by sb
                        AsiaPciModify8(CHX002_SATA|D15F0_SATA_PHY_DATA_PATH_DEBUG_SIGNALS_GRPING_AND_RAM_BIST_CTL, D15F0_DBG_GRP_CFGIDX,0);//D15F0 Rx5E[7:5] =0 bus0
                        AsiaPciModify8(CHX002_SATA|D15F0_PHY_CTL_REG_2, D15F0_DBG_GRPSEL_14_8,(UINT8)((NbConfig->TOPGroup0ModuleSubSelcet)>>8));//D15F0 Rx5D =XX  Select group high 8 bit
                        AsiaPciModify8(CHX002_SATA|D15F0_DEBUG_CTL_SEL, D15F0_DBG_GRPSEL_7_0,(UINT8)(NbConfig->TOPGroup0ModuleSubSelcet));//D15F0 Rx5F =XX  Select group low 8 bit
                    } else {
                        AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,0x1FFFF,NbConfig->TOPGroup0ModuleSubSelcet);//Rx48[16:0]
                    }
                    AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_1,BIT17|BIT18|BIT19,NbConfig->TOPGroup0TopSelcet<<17);//Rx48[19:17]
                }

                if(NbConfig->DebugModuleSelect1==DEBUG_SELECT_NB) {
                    //Group 1  NB SubModule  select

                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":DebugModuleSelect1=DEBUG_SELECT_NB\n"));
                    AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RDBGMX_NBTOP_G1_RSP_5_0,NbConfig->NBGroup1TopSelect<<20);
                    AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,D0F4_RDBGMX_MODULE_G1_RSP_19_0,(NbConfig->NBGroup1ModuleSubSelect2<<10)|NbConfig->NBGroup1ModuleSubSelect1);//Rx44[19:10]
                } else if(NbConfig->DebugModuleSelect1==DEBUG_SELECT_SB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":DebugModuleSelect1=DEBUG_SELECT_SB\n"));

                    AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,NbConfig->DebugSBselectByNB<<2);
                    ProgramSbDebugSignal(PeiServices,NbConfig,1,FALSE);
                } else if (NbConfig->DebugModuleSelect1 == DEBUG_SELECT_TOP) {
                    if(NbConfig->TOPGroup1TopSelcet ==TOP_DEBUG_XHCI) {
                        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
                        AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, BIT14);

                        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,0);//D0F4 Rx42[2] =0
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX65_XHCOPTRX65, D18F0_MCU_DBGEN,D18F0_MCU_DBGEN);//XHCOPTRx65[0] = 1b
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX57_XHCOPTRX56, D18F0_R_XHCI_PTN_DBG_SEL_G2,NbConfig->TOPGroup1XhciModule2Selcet);//G2:Rx57[3:0]
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX57_XHCOPTRX56, D18F0_R_XHCI_PTN_DBG_SEL_G3,NbConfig->TOPGroup1XhciModule3Selcet<<4);//G2:Rx57[7:4]

                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,D18F0_CPU_OPTCFG);//D18F0 PCI Rx43[0] = 1b Enable Level 2 Access
                        //G2 group ->Rx148[11:0]
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x148); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0xFFF,NbConfig->TOPGroup1XhciGroup2Selcet); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        //G3 group ->Rx148[27:16]
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x148); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0xFFF0000,NbConfig->TOPGroup1XhciGroup3Selcet<<16); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,0);//D18F0 PCI Rx43[0] = 1b Disable  Level 2 Access

                        //MCU group ->Rx64[7:4]
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX64_XHCOPTRX64, D18F0_MCU_DBG_SEL2,NbConfig->TOPGroup1XhciMCUSelcet<<4);//Rx64[7:4] =xxx
                    } else if(NbConfig->TOPGroup1TopSelcet ==TOP_DEBUG_XHCI_TXCDC) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,D0F4_RRDBGSBSELBYNB);//D0F4 Rx42[2] =1
                        AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,0x1F00000,NbConfig->TOPGroup1ModuleSubSelcet<<20);//Rx44[24:20]
                    } else if(NbConfig->TOPGroup1TopSelcet ==TOP_DEBUG_SATA) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RRDBGSBSELBYNB,0);//D0F4 Rx42[2] =0 sel by sb
                        AsiaPciModify8(CHX002_SATA|D15F0_SATA_PHY_DATA_PATH_DEBUG_SIGNALS_GRPING_AND_RAM_BIST_CTL, D15F0_DBG_GRP_CFGIDX,BIT5);//D15F0 Rx5E[7:5] =1 bus1
                        AsiaPciModify8(CHX002_SATA|D15F0_PHY_CTL_REG_2, D15F0_DBG_GRPSEL_14_8,(UINT8)((NbConfig->TOPGroup1ModuleSubSelcet)>>8));//D15F0 Rx5D =XX  Select group high 8 bit
                        AsiaPciModify8(CHX002_SATA|D15F0_DEBUG_CTL_SEL, D15F0_DBG_GRPSEL_7_0,(UINT8)(NbConfig->TOPGroup1ModuleSubSelcet));//D15F0 Rx5F =XX	Select group low 8 bit
                    } else {
                        AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,0x1FFFF,NbConfig->TOPGroup1ModuleSubSelcet);//Rx44[16:0]
                    }
                    AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0,BIT17|BIT18|BIT19,NbConfig->TOPGroup1TopSelcet<<17);//Rx44[19:17]
                }
                AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0, D0F4_RRDBGMODE,D0F4_RRDBGMODE); //  Rx44[30]=1 Enable normal Debug mode
            } else if( (NbConfig->DebugSignalSelect0==GroupGFX_Signal)||(NbConfig->DebugSignalSelect1==GroupGFX_Signal)) {

            }
        } else {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "Suspend Debug\n"));

            AsiaPciModify32(CHX002_NPMC|D0F4_DEBUG_SEL_SIGNAL_0, D0F4_RRDBGMODE,0); // Rx44[30]=0 Disable normal Debug mode
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0,D0F4_RDBGCHSEL_SUS_1_0,NbConfig->DebugOutputSelect << 5);
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_1,D0F4_RDBGCHDVPSEL_SUS,BIT7);//RXA9[7]=1
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0,D0F4_RGFXDBGSEL_G0_SUS,NbConfig->DebugSignalSelect0<<3);//dla modify
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0,D0F4_RGFXDBGSEL_G1_SUS,NbConfig->DebugSignalSelect1<<4);//dla modify
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0,D0F4_RDBGNBSBSEL_G0_SUS_1_0,NbConfig->DebugModuleSelect0<<1);//dla modify
            AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_1,D0F4_RDBGNBSBSEL_G1_SUS_1_0,NbConfig->DebugModuleSelect1<<5);//dla modify

            if ( (NbConfig->DebugSignalSelect0==GroupNBSB_Signal)||(NbConfig->DebugSignalSelect1==GroupNBSB_Signal)) {
                if(NbConfig->DebugModuleSelect0==DEBUG_SELECT_NB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "G0:DEBUG_SELECT_NB\n"));
                    // Sub Module selection
                    AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_1,D0F4_RDBGMX_NBTOP_G0_SUS_4_0,NbConfig->NBGroup0TopSelect);
                    AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_3,D0F4_RDBGMX_MODULE_G0_SUS_19_12,(UINT8) (NbConfig->NBGroup0ModuleSubSelect2>>2));//RxAB[7:0]
                    AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,D0F4_RDBGMX_MODULE_G0_SUS_11_0,(NbConfig->NBGroup0ModuleSubSelect2<<30)|NbConfig->NBGroup0ModuleSubSelect1 << 20 );//RxAC[31:20]
                } else if(NbConfig->DebugModuleSelect0==DEBUG_SELECT_SB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "G0:DEBUG_SELECT_SB\n"));
                    AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,NbConfig->DebugSBselectByNB);//RxA8[0]
                    ProgramSbDebugSignal(PeiServices,NbConfig,0,TRUE);
                } else if (NbConfig->DebugModuleSelect0 == DEBUG_SELECT_TOP) {
                    // PEI_DEBUG((PeiServices, EFI_D_ERROR, "G0:DEBUG_SELECT_TOP\n"));

                    if(NbConfig->TOPGroup0TopSelcet ==TOP_DEBUG_XHCI) {
                        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
                        AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, BIT14);

                        AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,0);//RxA8[0]=0

                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,D18F0_CPU_OPTCFG);//D18F0 PCI Rx43[0] = 1b Enable Level 2 Access
                        //  XHCI Level2 OPTCFG Rx141[0]=1
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x140); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0x0100,0x0100); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        //	XHCI Level2 OPTCFG Rx144[27:16] select
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x144); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0xFFF0000,NbConfig->TOPGroup0SUSXhciSelcet); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,0);//D18F0 PCI Rx43[0] = 0b Disable Level 2 Access
                    } else if(NbConfig->TOPGroup0TopSelcet ==TOP_DEBUG_XHCI_TXCDC) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,D0F4_RDBGSBSELBYNB_SUS);//RxA8[0]=1
                        AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_1,D0F4_RDBGMX_NBTOP_G0_SUS_4_0,NbConfig->TOPGroup0ModuleSubSelcet);//RxA9[4:0]
                    } else if(NbConfig->TOPGroup0TopSelcet ==TOP_DEBUG_SATA) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,D0F4_RDBGSBSELBYNB_SUS);//RxA8[0]=1
                        AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_3,0x1F,NbConfig->TOPGroup0ModuleSubSelcet>>12);//RxAB[4:0]
                        AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,D0F4_RDBGMX_MODULE_G0_SUS_11_0,NbConfig->TOPGroup0ModuleSubSelcet<<20);//RxAC[30:20]
                    } else {
                        AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_3,0x1F,NbConfig->TOPGroup0ModuleSubSelcet>>12);//RxAB[4:0]
                        AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,D0F4_RDBGMX_MODULE_G0_SUS_11_0,NbConfig->TOPGroup0ModuleSubSelcet<<20);//RxAC[30:20]
                    }
                    AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_3,BIT7|BIT6|BIT5,NbConfig->TOPGroup0TopSelcet<<5);//RxAB[7:5]
                }

                if(NbConfig->DebugModuleSelect1==DEBUG_SELECT_NB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "G1:DEBUG_SELECT_NB\n"));
                    AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_2,D0F4_RDBGMX_NBTOP_G1_SUS_4_0,NbConfig->NBGroup1TopSelect);
                    AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,D0F4_RDBGMX_MODULE_G1_SUS_19_0,(NbConfig->NBGroup1ModuleSubSelect2<<10)|NbConfig->NBGroup1ModuleSubSelect1);
                } else if(NbConfig->DebugModuleSelect1==DEBUG_SELECT_SB) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "G1:DEBUG_SELECT_SB\n"));
                    AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,NbConfig->DebugSBselectByNB);//RxA8[0]
                    ProgramSbDebugSignal(PeiServices,NbConfig,1,TRUE);
                } else if (NbConfig->DebugModuleSelect1 == DEBUG_SELECT_TOP) {
                    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "G1:DEBUG_SELECT_TOP\n"));
                    if(NbConfig->TOPGroup1TopSelcet ==TOP_DEBUG_XHCI) {
                        // Set U3EPHY_CFGDONE, to make sure that xHCI is accessible.
                        AsiaPciModify16((CHX002_GFXAX|D0F0_EPHY_CTL_Z1), BIT14, BIT14);

                        AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,0);//RxA8[0]=0

                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,D18F0_CPU_OPTCFG);//D18F0 PCI Rx43[0] = 1b Enable Level 2 Access
                        //  XHCI Level2 OPTCFG Rx141[0]=1
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x140); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0x0100,0x0100); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        //	XHCI Level2 OPTCFG Rx144[27:16] select
                        AsiaPciWrite32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_ADR),0x144); // D18F0_XHCIOPTIONAL_BITS_CFG_ADR=0x78
                        AsiaPciModify32((CHX002_XHCI | D18F0_XHCIOPTIONAL_BITS_CFG_DATA),0xFFF0000,NbConfig->TOPGroup1SUSXhciSelcet); // D18F0_XHCIOPTIONAL_BITS_CFG_DATA=0x7C
                        AsiaPciModify8(CHX002_XHCI|D18F0_XHCIOPTION_BITS_RX43_XHCOPTRX43, D18F0_CPU_OPTCFG,0);//D18F0 PCI Rx43[0] = 0b Disable Level 2 Access
                    } else if(NbConfig->TOPGroup1TopSelcet ==TOP_DEBUG_XHCI_TXCDC) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,D0F4_RDBGSBSELBYNB_SUS);//RxA8[0]=1
                        AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_2,D0F4_RDBGMX_NBTOP_G1_SUS_4_0,NbConfig->TOPGroup1ModuleSubSelcet);//RxAA[4:0]
                    } else if(NbConfig->TOPGroup1TopSelcet ==TOP_DEBUG_SATA) {
                        AsiaPciModify8(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGSBSELBYNB_SUS,D0F4_RDBGSBSELBYNB_SUS);//RxA8[0]=1
                        AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,0x1FFFF,NbConfig->TOPGroup1ModuleSubSelcet);//RxAC[16:0]
                    }
                    else{
                        AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,0x1FFFF,NbConfig->TOPGroup1ModuleSubSelcet);//RxAC[16:0]
                    }
                    AsiaPciModify32(CHX002_NPMC|D0F4_RESERVED_Z16,BIT19|BIT18|BIT17,NbConfig->TOPGroup1TopSelcet<<17);//RxAC[19:17]
                }
                AsiaPciModify32(CHX002_NPMC|D0F4_SUSPEND_DEBUG_CTL_0, D0F4_RDBGMODE_SUS,D0F4_RDBGMODE_SUS);  // Enable Debug mode
            } else if( (NbConfig->DebugSignalSelect0==GroupGFX_Signal)||(NbConfig->DebugSignalSelect1==GroupGFX_Signal)) {

            }
        }
    }

    //SB HighSpeed Controller Debug
    //SB HighSpeed Controller Debug
    //PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA:SB HighSpeed Controller Debug\n"));
    if(NbConfig->SB_HS_DBG_SEL == SB_HS_DBG_SEL_DISABLE) {
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "Disable:\n1.disable SB HighSpeed Controller Debug\n"));
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBG, 0<<7);
    } else {
        //Disable RSBDBG_CLKEN
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBG_CLKEN, 1<<3);

        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "Enable:\n1.disable RSBDBG_CLKEN\nD0F4 Rx42[3]=0x%x(should be 1)\n",(AsiaPciRead8(CHX002_NPMC|D0F4_CHIP_TEST_MODE)&BIT3)));
        AsiaMemoryModify8(0xE0005141, BIT2+BIT3,BIT3);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "2.Configure D0F5Rx141[3:2]=0x%x(should be BIT3-0x08)\n",(AsiaMemoryRead8(0xE0005141)&(BIT2+BIT3))));
        // step1  D0F4 Rx42[6:5]=00 PCCA;	01 XHCI;  10 AHCI;
        // BJ CV Report: this step shoud write other item first than write target item twice.
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "SB_HS_DBG_SEL=0x%x\nto select one of the three devices.((00 PCCA; 01 XHCI;  10 AHCI;))\n",NbConfig->SB_HS_DBG_SEL));
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBGSEL_1_0, ~((NbConfig->SB_HS_DBG_SEL) -1) << 5  );
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBGSEL_1_0, ((NbConfig->SB_HS_DBG_SEL) -1) << 5 );
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBGSEL_1_0, ((NbConfig->SB_HS_DBG_SEL) -1) << 5  );

        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "3.Configure D0F4 Rx42[6:5]=0x%x\n",(AsiaPciRead8(CHX002_NPMC|D0F4_CHIP_TEST_MODE)&D0F4_RSBDBGSEL_1_0)));
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "SB_HS_DBG_CH_SEL=0x%x\n->toConfigure one of RPCCAOUTARB, RXHCIOUTARB, RAHCIOUTARB.\n",NbConfig->SB_HS_DBG_CH_SEL));
        switch(NbConfig->SB_HS_DBG_SEL) {
            case SB_HS_DBG_SEL_PCCA:
                AsiaPciModify8(CHX002_APIC |D0F5_RESERVED_SBDBGC_DEBUG_MODE_SEL,D0F5_RPCCAOUTARB_1_0,(NbConfig->SB_HS_DBG_CH_SEL) << 6 );
                break;
            case SB_HS_DBG_SEL_AHCI:
                AsiaPciModify8(CHX002_APIC |D0F5_RESERVED_SBDBGC_DEBUG_MODE_SEL,D0F5_RAHOUTARB_1_0,(NbConfig->SB_HS_DBG_CH_SEL) << 2 );
                break;
            case SB_HS_DBG_SEL_XHCI:
                AsiaPciModify8(CHX002_APIC |D0F5_RESERVED_SBDBGC_DEBUG_MODE_SEL,D0F5_RXHOUTARB_1_0,(NbConfig->SB_HS_DBG_CH_SEL) << 4 );
                break;
            default:
                break;
        }

        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "4.Configure D0F5 Rx8F=0x%x\n",AsiaPciRead8(CHX002_APIC |D0F5_RESERVED_SBDBGC_DEBUG_MODE_SEL)));

        // step 2: enable SBDBG modes;
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBG, BIT7);

        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "5: D0F4 Rx42[7]=0x%x(should be BIT7:0x80)->to	enable SBDBG.\n",(AsiaPciRead8(CHX002_NPMC |D0F4_CHIP_TEST_MODE)&BIT7)));

        // step 3 Configure RCRBH Rx260[0] ( RPE0DBG_PEXC ) or RCRBH Rx260[1]  ( RPE4DBG_PEXC ) to select Port0 or Port4
        if(NbConfig->SB_HS_PCIE_PORT_SEL== PORT0) {
            //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":Port0\n"));
            AsiaMemoryModify8(0xFEB12260,(BIT0+BIT1),BIT0);

            //PEI_DEBUG((PeiServices, EFI_D_ERROR, "0xFEB12260=0x%x\nConfigure RCRBH Rx260[0] ( RPE0DBG_PEXC )to select Port0\n",AsiaMemoryRead8(0xFEB12260)));
            SBHS_PCIESelect = CHX002_PE0;
        } else {
            //PEI_DEBUG((PeiServices, EFI_D_ERROR, ":Port4\n"));
            AsiaMemoryModify8(0xFEB12260,(BIT0+BIT1),BIT1);
            //PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read 0xFEB12260=0x%x\nnConfigure RCRBH Rx260[1]  ( RPE4DBG_PEXC ) to select Port4",AsiaMemoryRead8(0xFEB12260)));
            //CJW_20170510 no PEG						SBHS_PCIESelect = CHX002_PEG;
            SBHS_PCIESelect = CHX002_PE4;
        }

        // step 3:Set D3F0/D4F0 Rx50[1:0]=00;
        AsiaPciModify8(SBHS_PCIESelect |D3D5F1_LINK_CTL_1, D3D5F1_LCAPMS ,0x00);

        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "6:Read D3F0/D4F0 Rx50[1:0]=0x%x(should be 0)\nConfigure LCAPMS _[1:0] = 2'b00\n",(AsiaPciRead8(SBHS_PCIESelect |D3D5F1_LINK_CTL_1)& D3D5F1_LCAPMS )));
        //	step 4: D0F4 RxF5[0]=1;
        AsiaPciModify8(CHX002_NPMC|D0F4_PCIE_SLOT_PWR_LIMIT_MSG_CTL, D0F4_RDISSSPL ,D0F4_RDISSSPL);

        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "7:Read D0F4 RxF5[0]=0x%x(should be BIT0-0x01)\nConfigure D0F4 RxF5[0]=1\n",(AsiaPciRead8(CHX002_NPMC|D0F4_PCIE_SLOT_PWR_LIMIT_MSG_CTL)& BIT0 )));
        // step 5 Check PCIE LINK D2F0 Rx1C3[7:0] = 8A
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "8: Check PCIE LINK D2F0 Rx1C3[7:0] = 8A;\n"));

        do {
            Value = AsiaPcieRead8(NbConfig->PcieBar, SBHS_PCIESelect |(((UINT64)D3D5F1_PHYLS_LTSSM_STATE) << 32));
            //PEI_DEBUG((PeiServices, EFI_D_INFO, "Read D2/D3F0_Rx1C3[7:0](Should be 0x8A)=0x%x\n",Value));
        } while(Value != 0x8A);

        //	step 8 :do hot reset
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "9:do hot reset;\n"));
        //a:set D3F0/D4F0 Rx3E[6]=1;

        AsiaPciModify8(SBHS_PCIESelect |D3D5F1_BRIDGE_CTL, D3D5F1_RSRST ,D3D5F1_RSRST);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "a:Read D3F0/D4F0 Rx3E[6]=0x%x(should be BIT6-0x40);\nset D3F0/D4F0 Rx3E[6]=1\n",AsiaPciRead8(SBHS_PCIESelect |D3D5F1_BRIDGE_CTL)));

        //b:Read to D3F0/D4F0 Rx1C3[7:0] PHYLS_STATE till PHYLS_STATE_PEG[7:0]==8'h60, Write Rx3E[6] = 1'b0
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "b_1:Read to D3F0/D4F0 Rx1C3[7:0]=0x%x(should be 0x60)\n PHYLS_STATE till PHYLS_STATE_PEG[7:0]==8'h60\n"));

        do {
            Value = AsiaPcieRead8(NbConfig->PcieBar, SBHS_PCIESelect |(((UINT64)D3D5F1_PHYLS_LTSSM_STATE) << 32));
            //PEI_DEBUG((PeiServices, EFI_D_INFO, "D3F0/D4F0_Rx1C3[7:0]=0x%x(Should be 0x60)\n",Value));
        } while(Value != 0x60);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "b:Read to D3F0/D4F0 Rx1C3=0x%x(should be 0x60)\n PHYLS_STATE till PHYLS_STATE_PEG[7:0]==8'h60\n"));

        // c:set  D2F0 Rx3E[6]=0;

        AsiaPciModify8(SBHS_PCIESelect |D3D5F1_BRIDGE_CTL, 0x40,0x00);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "c:Read D3F0/D4F0 Rx3E[6]=0x%x(should be 0);\nset D3F0/D4F0 Rx3E[6]=0\n",AsiaPciRead8(SBHS_PCIESelect |D3D5F1_BRIDGE_CTL)));

        // step 5 Check PCIE LINK D2F0 Rx1C3[7:0] = 8A

        do {
            Value = AsiaPcieRead8(NbConfig->PcieBar, SBHS_PCIESelect |(((UINT64)D3D5F1_PHYLS_LTSSM_STATE) << 32));
            //PEI_DEBUG((PeiServices, EFI_D_INFO, "D2/D3F0_Rx1C3[7:0](Should be 0x8A)=0x%x\n",Value));
        } while(Value != 0x8A);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "10: Check PCIE LINK D2F0 Rx1C3[7:0] =0x%x(should be 8A);\n",Value));

        //Enable RSBDBG_CLKEN
        AsiaPciModify8(CHX002_NPMC|D0F4_CHIP_TEST_MODE, D0F4_RSBDBG_CLKEN, 0<<3);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "11.D0F4 Rx42[3]=0x%x(should be BIT3-0)\nEnable RSBDBG_CLKEN\n",(AsiaPciRead8(CHX002_NPMC|D0F4_CHIP_TEST_MODE)&BIT3)));
    }

    //VDD OFF debug signal
    if(NbConfig->VDD_OFF_EN == VDD_OFF_DBG_SEL_DISABLE) {
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA:disable VDD OFF Debug\n"));
        AsiaIoModify8(SbPmioBar + PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_ENABLE_REG, PMIO_RDBGVDDOFFMODE, 0); //PMIO RxFA[0]=0
    } else {
        //PEI_DEBUG((PeiServices, EFI_D_ERROR, "DLA:VDD OFF Controller Debug\n"));
        AsiaIoModify8(SbPmioBar + PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_SEL_REG, PMIO_RDBGVDDOFF_MOD_SEL7_0, NbConfig->VDD_OFF_Module_Sel); //PMIO RxF9[7:0]
        AsiaIoModify8(SbPmioBar + PMIO_CHX002_VDDOFF_GRP_DEBUG_SIGNAL_SEL_REG, PMIO_RDBGVDDOFF_GRP_SEL7_0, NbConfig->VDD_OFF_Group_Sel); //PMIO RxF8[7:0]
        AsiaIoModify8(SbPmioBar + PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_ENABLE_REG, PMIO_RDBGVDDOFFMODE, BIT0); //PMIO RxFA[0]=1
    }

    /*PEI_DEBUG((PeiServices, EFI_D_ERROR, "af:Rx42=0x%02x;\n",AsiaPciRead8(CHX002_NPMC|0x42)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "af:Rx44=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0x44)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "af:Rx48=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0x48)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "af:RxA8=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0xA8)));
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "af:RxAC=0x%08x;\n",AsiaPciRead32(CHX002_NPMC|0xAC)));*/

}


