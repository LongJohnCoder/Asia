/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbInit.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

#include "pei.h"
#include EFI_PPI_DEFINITION(AsiaNBPpi)
#include EFI_PPI_DEFINITION(AsiaSBPpi)
#include EFI_PPI_DEFINITION(AsiaCpuPpi)
#include "RegCommon.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaNbPeim.h"
#include "AsiaIoLib.h"
#include "NbPcie.h"
#include "NbHif.h"
#include "NbLibPpi.h"
#include "SbLibPpi.h"
#include <AsiaSbPeim.h>
#include "AsiaCommon.h"
#include "CpuIA32.h"
#include "PeiLib.h"
#include "SICkgsrcTbl.h"
/////
#ifdef ZX_DUALSOCKET
#include "NbVpi.h"
#include "NbPcieSlave.h"
#include "NbVpi.c"
#include "NbPcieSlave.c"
#endif
#include "NbPcieCommon.h"
#include "AsiaInitCfgStructDefval.h"
#include "SbDriving.h"

#ifdef ZX_TXT_SUPPORT
#include EFI_PPI_DEFINITION(ReadOnlyVariable2)
#include EFI_PPI_DEFINITION(ReadOnlyVariable)
#include "AsiaVariable.h"

EFI_GUID gEfiPeiReadOnlyVariablePpiGuid = EFI_PEI_READ_ONLY_VARIABLE_ACCESS_PPI_GUID;
EFI_GUID gEfiPeiReadOnlyVariable2PpiGuid = EFI_PEI_READ_ONLY_VARIABLE2_PPI_GUID;
EFI_GUID gAsiaVariableGuid = ASIA_VARIABLE_GUID;

#define TXT_PUBLIC_CONFIG_REGS_BASE 0xFED30000
#endif

//ROMSIP Table Version
#define Romsip_Ver	1
#define CPU_PLL_CLK_InKHz	100000
#define REFCLKIN_InKHz  27000
#define VCO_MAX_CHANGE_InMHz  4


//STATIC ASIA_NB_CONFIGURATION mDefaultNbConfiguration = ASIA_NB_DEFAULT_CONFIGURATION;



//;Set S value for NB D0F5 registers in PEI stage
STATIC ASIA_IO_TABLE_6408_REV mNBAPICPeiInitStableTbl[]= {
           //mVer MVer	Reg Offset					            Mask	Value
   			0xFF, 0x00,  0x00,                      0x00,  0x00
        };

void ProgramDebugSignal(
     IN EFI_PEI_SERVICES **PeiServices,
     IN ASIA_NB_CONFIGURATION *NbConfig
     );

/**
   This Function will cost 300 micro seconds at least.
   So if the MicroSecends is little than 300, the delay will be NOT exactly.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  Microseconds  The value to delay.

  @return The value from this function.

**/
EFI_STATUS
PeiNbPcieStallByMicrosec (
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINTN Microseconds
)
{

    EFI_STATUS               Status;

    UINTN                    Ticks;
    UINTN                    Counts;
    UINT32                   CurrentTick;
    UINT32                   OriginalTick;
    UINT32                   RemainingTick;
    BOOLEAN                  Extended;

    ASIA_SB_LIB_PPI          *pAsiaSbLibPpi;
    EFI_GUID                 AsiaSbLibPpiGuid = EFI_ASIA_SB_LIB_PPI_GUID;

    if (Microseconds == 0)
    {
        return EFI_SUCCESS;
    }
    //The following codes in this function are by Microseconds unit.
    //Locate ASIA_SB_LIB_PPI
    Status = (*PeiServices)->LocatePpi(PeiServices,
                                       &AsiaSbLibPpiGuid,
                                       0,
                                       NULL,
                                       &pAsiaSbLibPpi
                                      );
    ASSERT_PEI_ERROR(PeiServices, Status);

    pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &OriginalTick, &Extended);

    CurrentTick  = OriginalTick;

    //
    // The timer frequency is 3.579545 MHz, so 1 ms corresponds 3.58 clocks
    //
    Ticks = Microseconds * 358 / 100 + OriginalTick + 1;

    //
    // The loops needed by timer overflow
    //
    Counts = (Ticks & 0xFF000000)>>24;    // 24-bit Timer

    //
    // remaining clocks within one loop
    //
    RemainingTick = Ticks & 0xFFFFFF; // 24-bit Timer

    //
    // not intend to use TMROF_STS bit of register PM1_STS, because this adds extra
    // one I/O operation, and maybe generate SMI
    //
    while (Counts != 0)
    {
        pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &CurrentTick, NULL);

        if (CurrentTick <= OriginalTick)
        {
            Counts--;
        }

        OriginalTick = CurrentTick;
    }

    while ((RemainingTick > CurrentTick) && (OriginalTick <= CurrentTick))
    {
        OriginalTick  = CurrentTick;
        pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &CurrentTick, NULL);
    }

    return EFI_SUCCESS;
}

/**
   This Function will Create ASIA_NB_CFG Struct hob.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  Buffer  pointer to ASIA_NB_CONFIGURATION hob.

  @return The value from this function.

**/
EFI_STATUS CreateAsiaNbCfgHob (
    IN EFI_PEI_SERVICES **PeiServices,
    OUT VOID **Buffer
)
{
    EFI_STATUS Status;
    VOID* pNbCfgHob;
    EFI_PEI_HOB_POINTERS NbCfgHobPtr;
    EFI_GUID AsiaNbCfgGuid = ASIA_NB_CFG_HOB_GUID;
    ASIA_NB_CONFIGURATION* NbCfg;
    // Create Hob for NbCfg, link the buffer in the Hob to NbPpi.
    Status = (*PeiServices)->CreateHob(
                 PeiServices,
                 EFI_HOB_TYPE_GUID_EXTENSION,
                 sizeof(EFI_HOB_GUID_TYPE) + sizeof(ASIA_NB_CONFIGURATION),
                 &pNbCfgHob
             );
    if(EFI_ERROR(Status))
        return Status;

    NbCfgHobPtr.Raw = pNbCfgHob;
    NbCfgHobPtr.Guid->Name = AsiaNbCfgGuid; // Use ASIA_NB_CFG_HOB_GUID
    // Output content pointer of the hob
    *Buffer = (VOID*)((UINT8*)(&(NbCfgHobPtr.Guid->Name)) + sizeof(EFI_GUID));
    NbCfg = (ASIA_NB_CONFIGURATION*)(*Buffer);

    // Initialize NbCfg to all 0
    (*PeiServices)->SetMem(*Buffer, sizeof(ASIA_NB_CONFIGURATION), 0);

    return EFI_SUCCESS;
}

////
/**
   This Function dump ASIA_NB_CFG Struct.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbCfg  pointer to ASIA_NB_CONFIGURATION hob.

  @return The value from this function.

**/
VOID DumpAsiaNbCfgStructDefaultValue(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION* pNbCfg)
{
	//// Dump ASIA NB Cfg struct's default value
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n\n Begin to dump Asia NB Cfg Struct default value \n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"************************ \n"));
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->Signature = %x \n",pNbCfg->Signature));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->BiosVersion = %x \n",pNbCfg->BiosVersion));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->NBSPEValue = %x \n",pNbCfg->NBSPEValue));
	
	//PCIE Sheet
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->PcieBar = %x \n",pNbCfg->PcieBar));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->PcieEPHYBar = %x \n",pNbCfg->PcieEPHYBar));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->RcrbhBar = %x \n",pNbCfg->RcrbhBar));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->RcrbvBar = %x \n",pNbCfg->RcrbvBar));
	
	//debug_pcie
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->PcieEQ = %x \n",pNbCfg->PcieEQ));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->PcieEQTS2 = %x \n",pNbCfg->PcieEQTS2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->EQTxPreset = %x \n",pNbCfg->EQTxPreset));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->PcieEqCtlOrgValL0 = %x \n",pNbCfg->PcieEqCtlOrgValL0));
	
	//Debug Signal
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->DebugMode = %x \n",pNbCfg->DebugMode));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->DebugOutputSelect = %x \n",pNbCfg->DebugOutputSelect));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->DebugSignalSelect0 = %x \n",pNbCfg->DebugSignalSelect0));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->DebugSignalSelect1 = %x \n",pNbCfg->DebugSignalSelect1));
	

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->SB_HS_DBG_CH_SEL = %x \n",pNbCfg->SB_HS_DBG_CH_SEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->SB_HS_DBG_SEL = %x \n",pNbCfg->SB_HS_DBG_SEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->SB_HS_PCIE_PORT_SEL = %x \n",pNbCfg->SB_HS_PCIE_PORT_SEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->VDD_OFF_EN = %x \n",pNbCfg->VDD_OFF_EN));

	//PCIE 
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->Cnd003ModeSel = %x \n",pNbCfg->Cnd003ModeSel));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->Cnd003PhyCfg = %x \n",pNbCfg->Cnd003PhyCfg));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->Cnd003PhyACfg = %x \n",pNbCfg->Cnd003PhyACfg));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->Cnd003PhyBCfg = %x \n",pNbCfg->Cnd003PhyBCfg));
	
	//pNbCfg->Cnd003EpCap=;
	//pNbCfg->Cnd003CapPEA0=;
	//pNbCfg->Cnd003CapPESB=;
	//pNbCfg->Cnd003PcieRstTest=;
	//pNbCfg->Cnd003PcieEq=;
	//pNbCfg->Cnd003Autofill=;
	//pNbCfg->Cnd003BootErrorClear=;
	//pNbCfg->Cnd003ForceMPS128B=;
	//pNbCfg->Cnd003SwCtlDnPortLinkup=;
	//pNbCfg->Cnd003DebugFromCpu=;
	//pNbCfg->Cnd003DbgPadG0En=;
	//pNbCfg->Cnd003DbgPadG1En=;
	//pNbCfg->Cnd003DbgPadG2En=;
	//pNbCfg->Cnd003DbgPadG3En=;
	//pNbCfg->Cnd003UartPinEn=;
#ifdef ZX_SECRET_CODE
       PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->Cnd003DIDVIDChoose = %x \n",pNbCfg->Cnd003DIDVIDChoose));
#endif
	//pNbCfg->Cnd003ChangeSIDForISB=;
	//pNbCfg->Cnd003DCOutput=;
	//pNbCfg->IOESPEValue=;
	//pNbCfg->IOEXSPEValue=;
	//pNbCfg->IOEXp1D0F0SPEValue=;
	//pNbCfg->IoeDnPortCtl=;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->CND003_RPCIE_TNO_IO = %x \n",pNbCfg->CND003_RPCIE_TNO_IO));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->CND003USBCLKSEL = %x \n",pNbCfg->CND003USBCLKSEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->CND003SATACLKSEL = %x \n",pNbCfg->CND003SATACLKSEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"pNbCfg->CND003_RPCIE_PU_IO = %x \n",pNbCfg->CND003_RPCIE_PU_IO));

       PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n ************************ \n"));
       PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of dump Asia NB Cfg Struct default value \n"));  
	
}

////
/**
   This Function will init Nb Private Data.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  PrivateData  pointer to ASIA_NB_PEI_PRIVATE_DATA.

  @return The value from this function.

**/
EFI_STATUS
InitNbPrivateData (
    IN EFI_PEI_SERVICES **PeiServices,
    OUT ASIA_NB_PEI_PRIVATE_DATA *PrivateData
)
{
    EFI_STATUS Status = 0;
    VOID* pNbCfg;
    ASIA_NB_LIB_PPI *NbLibPpi = NULL;


    if (NULL == PrivateData || ASIA_NB_PEI_PRIVATE_DATA_SIGNATURE != PrivateData->Signature)
        return EFI_INVALID_PARAMETER;
    //init NB configuration structure
    Status = CreateAsiaNbCfgHob(PeiServices, &pNbCfg);
    PrivateData->AsiaNbPpi.NbCfg = pNbCfg;
    // Initialize NbCfg to Default value
    //(*PeiServices)->CopyMem(NbCfg, &mDefaultNbConfiguration, sizeof(ASIA_NB_CONFIGURATION));
    InitNbCfgStructDefaultValue(pNbCfg); // AsiaPlatformPkg implement it
    DumpAsiaNbCfgStructDefaultValue(PeiServices,pNbCfg);
	/*init nb lib ppi*/
    Status = (*PeiServices)->AllocatePool(
                 PeiServices,
                 sizeof(ASIA_NB_LIB_PPI),
                 &(NbLibPpi)
             );
    if (NULL == NbLibPpi)
        return EFI_OUT_OF_RESOURCES;
    PrivateData->PpiDesc[0].Ppi = NbLibPpi;
    return Status;
}

/**
   This Function will Check Warm Reboot.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.
**/
EFI_STATUS
CheckWarmReboot(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    EFI_BOOT_MODE   BootMode;
    UINT8   WarmReboot;
    

    (*PeiServices)->GetBootMode (PeiServices, &BootMode);

    if(BootMode != BOOT_ON_S3_RESUME)
    {
        WarmReboot = AsiaPciRead8(CHX002_SCRCH|D0F6_BIOS_EXTENDED_SCRATCH_REGS_8+3) & 0x01; // D0F6 Rx9F[0]
        if(WarmReboot == 0x01)
        {
            AsiaIoWrite8(0xCf9, 0x06);
            // Never come here...
        }
        AsiaPciWrite8(CHX002_SCRCH|D0F6_BIOS_EXTENDED_SCRATCH_REGS_8+3, 0x01);
    }
    
    return EFI_SUCCESS;
}

//YKN-20170509 -s
//Remove these code for PXP bringup
#if 1
/**
   This Function will init internal clock generator.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiNbInternalClkGen(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	UINT32	targetCpuFreq_InKHz;
	UINT32	freq_InKHz;
	UINT32	freqVCO_InKHz;
	UINT8	PLLCPU_Integer;
	UINT32	PLLCPU_Fraction;
	UINT32	PLLCPU_Fraction_2;
	#ifdef CHX002_A0
	EFI_ASIA_SB_PPI	      *pSbPpi;
	EFI_GUID               AsiaSbPpiGuid = EFI_ASIA_SB_PPI_GUID;
	EFI_STATUS             Status;
	ASIA_SB_CONFIGURATION *SbConfig;
	BOOLEAN                SataEn = TRUE;                    
	#endif
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "+++++ PeiNbInternalClkGen start+++++\n"));

	//get OC %
	PEI_DEBUG((PeiServices, EFI_D_INFO, "OC %d %%\n",NbConfig->CpuClockControl-2));

	//Chx002 Rule:
	//assume frequency from X to Y
	//Step 1. Disable CPU SSC
	//Step 2. set frequency X+1MHz, calculate fvco=REFCLKIN*(A(DIVM)+2+B(DIVN)/2^20)
	//Step 3.set RxDA[0]=1
	//Step 4.  Delay 2 us 
	//Step 5.  goto step 2 and repeat until Y
	//Step 6. Enable CPU SSC


	if(NbConfig->CpuClockControl > CPU_CLK_CTL_NO_OC )// means OC n% (n > 0)
    	{
    		//1.Disable CPU SSC D0F4  RxD9[3]
    	AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_5, D0F4_RPLLCPU_SSCEN, 0x00);
	
	    targetCpuFreq_InKHz = CPU_PLL_CLK_InKHz*(100+(NbConfig->CpuClockControl-CPU_CLK_CTL_NO_OC))/100;
		for(freq_InKHz=CPU_PLL_CLK_InKHz+250;freq_InKHz<=targetCpuFreq_InKHz;freq_InKHz+=250)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Increase 250KHz, freq_InKHz =  %d KHz\n",freq_InKHz));

			// Calculate PLLCPU Fractional and Integer Division Setting
			freqVCO_InKHz = freq_InKHz*16;//in KHz
			PEI_DEBUG((PeiServices, EFI_D_INFO, "freqVCO_InKHz =  %d kHz\n",freqVCO_InKHz));

			PLLCPU_Integer = (UINT8)(((freqVCO_InKHz*1000)/(REFCLKIN_InKHz*1000))-2);
			
				PLLCPU_Fraction = (freqVCO_InKHz*1000)/(REFCLKIN_InKHz/1000)-(PLLCPU_Integer+2)*1000000;
				PLLCPU_Fraction_2 = (freqVCO_InKHz*(1<<10))/REFCLKIN_InKHz*(1<<10)-(PLLCPU_Integer+2)*(1<<20);
			
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Integer Division Setting =  %d (%xh)\n",PLLCPU_Integer,PLLCPU_Integer));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Fractional Division Setting (1000000)=  %d (%xh)\n",PLLCPU_Fraction,PLLCPU_Fraction));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Fractional Division Setting =(2^10)  %d (%xh)\n",PLLCPU_Fraction_2,PLLCPU_Fraction_2));

			//2.program PLLCPU: RxD4-D7
			AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_2, D0F4_RPLLCPU_DIVM_7_0, PLLCPU_Integer);
			AsiaPciModify32(CHX002_NPMC|D0F4_PLLCPU_CTL_3, D0F4_RPLLCPU_DIVN_19_0, PLLCPU_Fraction);

			//3.set RxDA[0]=1			
			AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_6, D0F4_RPLLCPUMNOK, D0F4_RPLLCPUMNOK);

			//4.delay 2 microseconds (actually it delays 302 microseconds because opeation took 300 microseconds)
			PeiNbPcieStallByMicrosec(PeiServices,2);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Program CKGCPU Control  Register Done!!\n"));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
    		}

    	//6.Enable CPU SSC D0F4  RxD9[3]
		AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_5, D0F4_RPLLCPU_SSCEN, D0F4_RPLLCPU_SSCEN);

	}	
	else if(NbConfig->CpuClockControl < CPU_CLK_CTL_NO_OC )//means OC n% (n < 0)
	{
    	//1.Disable CPU SSC D0F4  RxD9[3]
    	AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_5, D0F4_RPLLCPU_SSCEN, 0x00);
	    targetCpuFreq_InKHz = CPU_PLL_CLK_InKHz*(100-5*(CPU_CLK_CTL_NO_OC-NbConfig->CpuClockControl))/100;

		for(freq_InKHz=CPU_PLL_CLK_InKHz-250;freq_InKHz>=targetCpuFreq_InKHz;freq_InKHz-=250)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Decrease 250kHz, freq_InKHz =  %d MHz\n",freq_InKHz));
			// Calculate PLLCPU Fractional and Integer Division Setting
			freqVCO_InKHz = freq_InKHz*16;//in KHz
			PEI_DEBUG((PeiServices, EFI_D_INFO, "freqVCO_InKHz =  %d kHz\n",freqVCO_InKHz));


			PLLCPU_Integer = (UINT8)(((freqVCO_InKHz*1000)/(REFCLKIN_InKHz*1000))-2);
			
	
	PLLCPU_Fraction = (freqVCO_InKHz*1000)/(REFCLKIN_InKHz/1000)-(PLLCPU_Integer+2)*1000000;
	PLLCPU_Fraction_2 = (freqVCO_InKHz*(1<<10))/REFCLKIN_InKHz*(1<<10)-(PLLCPU_Integer+2)*(1<<20);
				
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Integer Division Setting =  %d (%xh)\n",PLLCPU_Integer,PLLCPU_Integer));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Fractional Division Setting (1000000)=  %d (%xh)\n",PLLCPU_Fraction,PLLCPU_Fraction));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Fractional Division Setting =(2^10)  %d (%xh)\n",PLLCPU_Fraction_2,PLLCPU_Fraction_2));


		//2.program PLLCPU: RxD4-D7
		AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_2, D0F4_RPLLCPU_DIVM_7_0, PLLCPU_Integer);
		AsiaPciModify32(CHX002_NPMC|D0F4_PLLCPU_CTL_3, D0F4_RPLLCPU_DIVN_19_0, PLLCPU_Fraction);
		
		//3.set RxDA[0]=1			
		AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_6, D0F4_RPLLCPUMNOK, D0F4_RPLLCPUMNOK);
		
		//4.delay 2 microseconds (actually it delays 302 microseconds because opeation took 300 microseconds)
		PeiNbPcieStallByMicrosec(PeiServices,2);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Program CKGCPU Control  Register Done!!\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
		}

	//6.Enable CPU SSC D0F4  RxD9[3]
	AsiaPciModify8(CHX002_NPMC|D0F4_PLLCPU_CTL_5, D0F4_RPLLCPU_SSCEN, D0F4_RPLLCPU_SSCEN);

	}
	else
	{
		PLLCPU_Integer = AsiaPciRead8(CHX002_NPMC|D0F4_PLLCPU_CTL_2);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Integer Division Setting =  %d (%xh) MHz\n",PLLCPU_Integer,PLLCPU_Integer));
		PLLCPU_Fraction = AsiaPciRead32(CHX002_NPMC|D0F4_PLLCPU_CTL_3)&D0F4_RPLLCPU_DIVN_19_0;
		PEI_DEBUG((PeiServices, EFI_D_INFO, "PLLCPU Fractional Division Setting =  %d (%xh) MHz\n",PLLCPU_Fraction,PLLCPU_Fraction));
		freqVCO_InKHz = REFCLKIN_InKHz*(PLLCPU_Integer+2+(PLLCPU_Fraction>>20));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "freqVCO_InKHz =  %d kHz\n",freqVCO_InKHz));
		
		targetCpuFreq_InKHz = freqVCO_InKHz/16;
		PEI_DEBUG((PeiServices, EFI_D_INFO, "targetCpuFreq =  %d kHz\n",targetCpuFreq_InKHz));
	}

    //20180726- ZYC patch for AHCI mode S4 resume randomly read disk error issue s
	if(ASIA_NB_REVISION == 0){
		Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaSbPpiGuid, 0, NULL, &pSbPpi);
	    if(!EFI_ERROR(Status)){
	      SbConfig = pSbPpi->SbCfg;
	      SataEn   = SbConfig->SataEn;
		}
		if(SataEn){
		    AsiaPciModify8(CHX002_GFXAX|D0F0_X2_EPHY_CTL_Z1, D0F0_FHP0_MPLL_CP_X2_3_0, 0x5); //MPLL_CP
		    AsiaPciModify16(CHX002_GFXAX|D0F0_EPHY_CTL, D0F0_FHP0_REFCLKPS_SEL_X2, BIT15); //Select PLLEB of CKGSRC as SATA reference clock source
		   //AsiaPciModify8(CHX002_NPMC|0xBB, BIT2, 0x00); //disable PLLEB SSC
		}
	}
	//20180726- ZYC patch for AHCI mode S4 resume randomly read disk error issue e
	PEI_DEBUG((PeiServices, EFI_D_INFO, "----- PCIE SSC Related Setting-----\n"));
	if(NbConfig->PciePHYA_SSC_EN){
		PEI_DEBUG((PeiServices, EFI_D_INFO, "PHYA SSC [Enable]\n"));
		AsiaPcieModify8(NbConfig->PcieBar,CHX002_NPMC|((UINT64)(D0F4_CKGSRC_PLLEA_CTL_4) << 32),D0F4_RSRC_SSCEN_A,D0F4_RSRC_SSCEN_A);
	}else{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "PHYA SSC [Disable]\n"));
		AsiaPcieModify8(NbConfig->PcieBar,CHX002_NPMC|((UINT64)(D0F4_CKGSRC_PLLEA_CTL_4) << 32),D0F4_RSRC_SSCEN_A,0);
	}
	if(NbConfig->PciePHYB_SSC_EN){
		PEI_DEBUG((PeiServices, EFI_D_INFO, "PHYB SSC [Enable]\n"));
		AsiaPcieModify8(NbConfig->PcieBar,CHX002_NPMC|((UINT64)(D0F4_CKGSRC_PLLEB_CTL_4) << 32),D0F4_RSRC_SSCEN_B,D0F4_RSRC_SSCEN_B);
	}else{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "PHYB SSC [Disable]\n"));
		AsiaPcieModify8(NbConfig->PcieBar,CHX002_NPMC|((UINT64)(D0F4_CKGSRC_PLLEB_CTL_4) << 32),D0F4_RSRC_SSCEN_B,0);
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "----- PeiNbInternalClkGen end-----\n"));
	return EFI_SUCCESS;
}

#endif
//YKN-20170509 -e


/**
   This Function will init MCA.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiMCAInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	UINT64				Addr;
	UINT32				Value;
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiMCAInit()\n"));

	Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_MCA_REG_BASE_ADR);
	// 1. Program MCA register base address
	AsiaPcieWrite32(NbConfig->PcieBar, Addr, (NbConfig->CRMCABar >> 12) & D0F5_RMCAMMIO_BASE_39_12);
	// 2. Enable decode
	AsiaPcieModify32(NbConfig->PcieBar, Addr, D0F5_RMCAMMIO_BASE_EN, D0F5_RMCAMMIO_BASE_EN);
	// 3. Lock it.
	AsiaPcieModify32(NbConfig->PcieBar, Addr, D0F5_D0F5_RX14CB29, D0F5_D0F5_RX14CB29);
	
		//Program D0F3 Rx1A0[13-12] ,enable DRAM ECC Error report to MCA
	Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_DRAM_FUN,D0F3_RETRY_ERR_ENABLE_CTL);
	Value = D0F3_RMCAMBECC_EN | D0F3_RMCASBECC_EN;
	AsiaPcieModify32(NbConfig->PcieBar, Addr, Value, Value);
	
    return EFI_SUCCESS;

}


/**
   This Function will init RAIDA.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiRAIDAInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
#ifdef CHX002_PXP
	//Disable RAIDA realted setting due to PXP don't have RAIDA design
	//D0F5 Rx273[7,6,4,3,2,1] = 0
	UINT64				Addr;
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiRAIDAInit(): Disable RAIDA\n"));

	Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN, D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV);
	AsiaPcieModify8(NbConfig->PcieBar, Addr, D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN | D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN | D0F5_RD8F0_EN | D0F5_RD9F0_EN | D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN | D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN, 0);
#else
    UINT64 Addr;

	Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV);
    if(NbConfig->RAIDA0Enable) {
		AsiaPcieModify8(NbConfig->PcieBar, Addr,  D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN,
			D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN);

	//YKN-20170118 -s
	  AsiaPciModify8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, D0F5_RPEROWEN);
	  AsiaPciModify32(CHX002_RAIDA0|D8F0_RX08_7_0, 0xffffff00, 0x8800000);
	  AsiaPciModify8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
	//YKN-20170118 -e
    } else {
    	AsiaPcieModify8(NbConfig->PcieBar, Addr,  D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN,
			0);

    }

    if(NbConfig->RAIDA1Enable) {
		AsiaPcieModify8(NbConfig->PcieBar, Addr,  D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN|D0F5_RD9F0_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN,
			D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN|D0F5_RD9F0_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN);

	 //YKN-20170118 -s
	  AsiaPciModify8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, D0F5_RPEROWEN);
	  AsiaPciModify32(CHX002_RAIDA1|D9F0_RX08_7_0, 0xffffff00, 0x8800000);
	  AsiaPciModify8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
	  //YKN-20170118 -e
    } else {
    	AsiaPcieModify8(NbConfig->PcieBar, Addr,  D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN|D0F5_RD9F0_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN,
			0);
    }
#endif

    return EFI_SUCCESS;

}

/**
   This Function will init PM.

  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiNbPMInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    // Process PM init table
    //PROCESS_NB_R6408M_TABLE(mNBPMPeiInitStableTbl, sizeof(mNBPMPeiInitStableTbl)/sizeof(ASIA_IO_TABLE_6408_REV));
    return EFI_SUCCESS;
}

/**
   This Function will init Nb APIC.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiNbAPICInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	EFI_ASIA_SB_PPI	    *pSbPpi;
    EFI_GUID             AsiaSbPpiGuid = EFI_ASIA_SB_PPI_GUID;
    EFI_STATUS          Status;
	ASIA_SB_CONFIGURATION       *SbConfig;
    UINT16      Pmio=0x800;
    
#if 0
	   UINT64 Addr;
	   UINT8 Data8;
	   //UINT32 Data32;
		//Write D0F5 Rx273[0,1,2,6,7] = 00000b
		Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV);
		Data8 = AsiaPcieRead8(NbConfig->PcieBar, Addr);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "mike_Before_D0F5_0x273=%x\n",Data8));
	
		Data8 &= ~(D0F5_RNPEQ_C2TA_CFG_FLUSH_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN|D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN);
		AsiaPcieWrite8(NbConfig->PcieBar, Addr, Data8);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "mike_After_D0F5_0x273=%x\n",AsiaPcieRead8(NbConfig->PcieBar, Addr)));
	
	
		//Write D0F5_RxF4[10-4] = 0
		//Data32 = AsiaPciRead32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "mike_Before_D0F5_0xF4=%x\n",Data32));
		//Data32 &= ~(D0F5_RDV3F1EXST|D0F5_RDV3F3EXST|D0F5_RDV4F0EXST|D0F5_RDV4F1EXST|D0F5_RDV5F0EXST|D0F5_RDV5F1EXST);
		//AsiaPciWrite32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, Data32);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "mike_After_D0F5_0xF4=%x\n",AsiaPciRead32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE)));
		//Mike_Debug_E
#endif
	//#endif
#ifdef CHX002_PXP
#if 0
    UINT32 Data32;
    Data32 = AsiaPciRead32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "mike_Before_D0F5_0xF4=%x\n",Data32));
    Data32 &= ~(D0F5_RDV3F1EXST|D0F5_RDV3F2EXST|D0F5_RDV3F3EXST|D0F5_RDV4F0EXST|D0F5_RDV4F1EXST|D0F5_RDV5F0EXST|D0F5_RDV5F1EXST);
    AsiaPciWrite32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, Data32);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "mike_After_D0F5_0xF4=%x\n",AsiaPciRead32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE)));
#endif	
#endif

    // Process PM init table
    PROCESS_NB_R6408M_TABLE(mNBAPICPeiInitStableTbl, sizeof(mNBAPICPeiInitStableTbl)/sizeof(ASIA_IO_TABLE_6408_REV));

	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaSbPpiGuid, 0, NULL, &pSbPpi);
    //ASSERT_PEI_ERROR(PeiServices, Status);
    if(!EFI_ERROR(Status)) {
      SbConfig = pSbPpi->SbCfg;
      Pmio = SbConfig ->PmioBar;
    }

    AsiaPciWrite8(CHX002_APIC|D0F5_ACPI_IO_BASE_ADR_BIT_15_8, (UINT8)(Pmio >> 8));
	AsiaPciModify8(CHX002_APIC|D0F5_STPGNT_CYCLE_CTL,
		           D0F5_RIOWS345A_7,
		           (UINT8)(Pmio & 0x80));

 if(NbConfig->CPU_FSBC_EN){
		AsiaPciModify8(CHX002_APIC|D0F5_CPUIF_FUN,D0F5_RCREDI_UPFRQ_1_0,0);
	}

 #ifdef ZX_SECRET_CODE
     if(NbConfig->C2P2FlushC2M == 0) {
	 	UINT64 MsrValue;
	 	MsrValue = EfiReadMsr(0x168d);
		MsrValue |= 0x10;
	 	EfiWriteMsr(0x168d, MsrValue);
	 	AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_CPUIF_FUN), D0F5_RCPUIFC2P2FLUSHC2M_EN, 0);
     }
 #endif
    return EFI_SUCCESS;
}

/**
   This Function will init clock source.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiNbCkgsrcInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    UINTN Index;
    ASIA_IO_TABLE_6408_REV  *pItem;

    for (Index = 0; Index < CKGSRC_SI_TBL_Items; Index++) {
      pItem = &CKGSRC_SI_TBL[Index];  
      AsiaPciModify8(pItem->Address, pItem->Mask, pItem->Value);
    }

    return EFI_SUCCESS;
}

/**
   This Function will do TA Init.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiNbTAInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    UINT64 TABar = 0;
	UINT64 Addr = 0;
	UINT32 Temp32 = 0;

#ifdef ZX_DUALSOCKET
	UINT8 SlaveTABar = 0;
	UINT8 SlaveBusNum = NbConfig->ZxeSlaveBusNum;
#endif

    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiNbTAInit()\n"));

	if(NbConfig->IOVEnable)//Set TA MMIO space to TACTL Base Address register -------- master socket
	{
		TABar = NbConfig->TABar;
	}
	else//if SW will close TA, the base addr reg should also be cleared to close the MMIO space according to designer.
	{
		//Set TA MMIO space to TACTL Base Address register -------- master socket
		TABar = 0;
	}

	//set master TA register base addr
	Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_TACTL_BASE_ADR);
    AsiaPcieWrite32(NbConfig->PcieBar, Addr, (UINT32)(RShiftU64(TABar, 12)) & 0x0FFFFF);

	//lock the base address
	AsiaPcieModify32(NbConfig->PcieBar, Addr, D0F5_D0F5_RX26CB31, D0F5_D0F5_RX26CB31);

	Temp32 = AsiaPcieRead32(NbConfig->PcieBar, Addr);// for debug
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]master TA register base addr = 0x%08X\n", Temp32));// for debug
	
#ifdef ZX_DUALSOCKET
	if(NbConfig->IOVEnable)//Set TA MMIO space to TACTL Base Address register -------- slave socket
	{
		SlaveTABar = NbConfig->SlaveTABar;
	}
	else//if SW will close TA, the base addr reg should also be cleared to close the MMIO space according to designer.
	{
		//Set TA MMIO space to TACTL Base Address register -------- slave socket
		SlaveTABar = 0;
	}

	//set slave TA register base addr
	Addr = AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_TACTL_BASE_ADR);
    AsiaPcieWrite32(NbConfig->PcieBar, Addr, (UINT32)(RShiftU64(SlaveTABar, 12)) & 0x0FFFFF);

	//lock the base addr
	AsiaPcieModify32(NbConfig->PcieBar, Addr, D0F5_TACTL_BAR_LOCK, D0F5_TACTL_BAR_LOCK);

	Temp32 = AsiaPcieRead32(NbConfig->PcieBar, Addr);// for debug
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]slave TA register base addr = 0x%08X\n", Temp32));// for debug	
#endif	

	//Enable or Disable remapping hardware --------master/slave socket
	if(NbConfig->IOVEnable)
	{
		//20180614-JRZ: this bit must be programmed to 1b if TACTL is enabled according to designer
	    AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV), D0F5_RNPEQ_C2TA_CFG_FLUSH_EN, D0F5_RNPEQ_C2TA_CFG_FLUSH_EN);
		
		//Enable Master TACTL
	    AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_IOV_ENABLE), D0F5_RENIOVTL, D0F5_RENIOVTL);
		//set backdoor bit
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PMU_CTL), D0F5_RPEROWEN, D0F5_RPEROWEN);
			
		//clear the dma drain read & write bit in capability register, which are not supported by TACTL according to designer wenny yang. JRZ-20181120
		AsiaMemoryModify32(TABar|TACTL_CAP_REG_Z1, TACTL_RDRDS, 0);	
		AsiaMemoryModify32(TABar|TACTL_CAP_REG_Z1, TACTL_RDWDS, 0);	
			
		//Enable or Disable QI capability --------master socket
		if(NbConfig->IOVQIEnable)
		{
			AsiaMemoryModify16(TABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAQI, TACTL_RTAQI);	
		}
		else//JZ add: clear the QI support bit in extend capability register
		{			
			AsiaMemoryModify16(TABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAQI, 0);
		}

		//Enable or Disable INTR capability --------master socket
		if(NbConfig->IOVINTREnable)
		{
			AsiaMemoryModify16(TABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAIR, TACTL_RTAIR);
		}
		else//JZ add: clear the Interrupt Remapping support bit in extend capability register
		{			
			AsiaMemoryModify16(TABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAIR, 0);
		}
		
		//clear backdoor bit
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PMU_CTL), D0F5_RPEROWEN, 0);
		
		Temp32 = AsiaMemoryRead32(TABar|TACTL_EXTENDED_CAP_REG);//for debug
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]master TA extend capability reg = 0x%08X\tBit1,Bit3 for QI,INTR support!\n", Temp32));// for debug

#ifdef ZX_DUALSOCKET
		//20180614-JRZ: this bit must be programmed to 1b if TACTL is enabled according to designer
	    AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV), D0F5_RNPEQ_C2TA_CFG_FLUSH_EN, D0F5_RNPEQ_C2TA_CFG_FLUSH_EN);

		//Enable slave TACTL
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_IOV_ENABLE), D0F5_RENIOVTL, D0F5_RENIOVTL);
		//set backdoor bit
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PMU_CTL), D0F5_RPEROWEN, D0F5_RPEROWEN);
		
		//clear the dma drain read & write bit in capability register, which are not supported by TACTL according to designer wenny yang. JRZ-20181120
		AsiaMemoryModify32(SlaveTABar|TACTL_CAP_REG_Z1, TACTL_RDRDS, 0); 
		AsiaMemoryModify32(SlaveTABar|TACTL_CAP_REG_Z1, TACTL_RDWDS, 0); 

		//Enable or Disable QI capability --------slave socket
		if(NbConfig->IOVQIEnable)
		{	
			AsiaMemoryModify16(SlaveTABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAQI, TACTL_RTAQI);		
		}
		else//JZ add: clear the QI support bit in extend capability register
		{
			AsiaMemoryModify16(SlaveTABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAQI, 0);
		}

		//Enable or Disable INTR capability --------slave socket
		if(NbConfig->IOVINTREnable)
		{
			AsiaMemoryModify16(SlaveTABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAIR, TACTL_RTAIR);
		}
		else//JZ add: clear the Interrupt Remapping support bit in extend capability register
		{
			AsiaMemoryModify16(SlaveTABar|TACTL_EXTENDED_CAP_REG, TACTL_RTAIR, 0);
		}

		//clear backdoor bit
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PMU_CTL), D0F5_RPEROWEN, 0);

		Temp32 = AsiaMemoryRead32(SlaveTABar|TACTL_EXTENDED_CAP_REG);//for debug
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]slave TA extend capability reg = 0x%08X\tBit1,Bit3 for QI,INTR support!\n", Temp32));// for debug			
#endif
	}
	else
	{
		//Disable TACTL
	    AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_IOV_ENABLE), D0F5_RENIOVTL, 0);
		
		//20180614-JRZ: this bit must be programmed to 0b if TACTL is disabled according to designer
	    AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV), D0F5_RNPEQ_C2TA_CFG_FLUSH_EN, 0);

#ifdef ZX_DUALSOCKET		
	    AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_IOV_ENABLE), D0F5_RENIOVTL, 0);

		//20180614-JRZ: this bit must be programmed to 0b if TACTL is disabled according to designer
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV), D0F5_RNPEQ_C2TA_CFG_FLUSH_EN, 0);

#endif
	}

	Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN, D0F5_IOV_ENABLE);
	Temp32 = AsiaPcieRead32(NbConfig->PcieBar, Addr);// for debug
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]master D0F5 Rx16D[31:0] = 0x%08X\n", Temp32));// for debug read enable bit

#ifdef ZX_DUALSOCKET
	Addr = AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN, D0F5_IOV_ENABLE);
	Temp32 = AsiaPcieRead32(NbConfig->PcieBar, Addr);// for debug
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[JRZ]slave D0F5 Rx16D[31:0] = 0x%08X\n", Temp32));// for debug read enable bit
#endif


    return EFI_SUCCESS;

}

/**
   This Function will init FSBC.

  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiNbFSBCInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	EFI_ASIA_SB_PPI	    *pSbPpi;
	EFI_GUID            AsiaSbPpiGuid = EFI_ASIA_SB_PPI_GUID;
	EFI_STATUS          Status;
	ASIA_SB_CONFIGURATION       *SbConfig;
	UINT16	Pmio = 0x800;

	UINT8 Value8;
	UINT32 Value32;
	UINT64 Value64;
	UINT64 Address;
    
	//hxz-20171012 add fsbc en UI
	
	if(!NbConfig->CPU_FSBC_EN){
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"FSBC Disable(%d)!!!\n",NbConfig->CPU_FSBC_EN));
		return EFI_SUCCESS;
	}
	
	if((EfiReadMsr(0x16a7)&0x01)==0){
  		EfiWriteMsr(0x16a7, (EfiReadMsr(0x16a7)|0x01));
		
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"FSBC_MSR[%x]:%llx\n",0x16a7,EfiReadMsr(0x16a7)));
    }
	
	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaSbPpiGuid, 0, NULL, &pSbPpi);
    if(!EFI_ERROR(Status)){
      SbConfig = pSbPpi->SbCfg;
      Pmio = SbConfig ->PmioBar;
    }
	
    if (NbConfig->CPU_FSBC_PCIE_ON == 1)
	{
		//D0F4 Rx42 bit 4
		Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_CHIP_TEST_MODE);
		Value8 = AsiaPciRead8(Address);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Bf_D0F4_Rx42=%x\n",Value8));
		Value8 = Value8 | D0F4_RFSBCDBG;
		AsiaPciWrite8(Address,Value8);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_D0F4_Rx42=%x\n",AsiaPciRead8(Address)));

		//D0F4 Rx47 bit 7
		Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_DEBUG_SEL_SIGNAL_0 + 3);
		Value8 = AsiaPciRead8(Address);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Bf_D0F4_Rx47=%x\n",Value8));
		Value8 = Value8 | BIT7;
		AsiaPciWrite8(Address,Value8);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_D0F4_Rx47=%x\n",AsiaPciRead8(Address)));

		//D0F5 Read Rx268 for RCRB-H
		Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN, D0F5_RCRB_H_BASE_ADR);
		Value32 = AsiaPcieRead32(NbConfig->PcieBar,Address);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"D0F5_Rx268=%x\n",Value32));

		Value64 = (UINT64)(Value32 & 0x0FFFFFFF);
		Value64 = LShiftU64(Value64, 12);

		////HXZ-20170814 modify for CHX002 HAPS PE0(D3F0)/PE4(D4F0)
		
		Value64 += (UINT64)RCRBH_MISC_0; //0x260      CJW_20170512  PEG2 changed to PE6(D5F0)   
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"RPEGDBG_PEXC_Address=%llx\n",Value64));
		Value8 = AsiaMemoryRead8(Value64);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Bf_RPEGDBG_PEXC=%x\n",Value8));


		if (NbConfig->CPU_FSBC_TOPCIE == 0)//select port0 as the output port
		{
			//Set bit0, clear bit1

 //CJW_20170512 removed	
	//HXZ-20170814 Add
			Value8 |= RCRBH_RPE0DBG_PEXC;

  //DaisyZhang_20170622 removed
			Value8 &= ~RCRBH_RPE4DBG_PEXC;

  //CJW_20170510 removed  -- there was no PEG on CHX002
	//HXZ-20170814 Add For CHX002 HAPS PE0(D3F0)
			Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_PE0_3_DEV,CHX002_PE0_FUN,D3D5F1_BRIDGE_CTL);

		}
		else
		{
			//Set bit1, clear bit0
			//sellect port4
  //DaisyZhang_20170622 removed
			Value8 |= RCRBH_RPE4DBG_PEXC;

	//CJW_20170512 removed		
			Value8 &= ~RCRBH_RPE0DBG_PEXC;
			
			//HXZ-20170814 Add For CHX002 PXP PE4(D4F0)
			Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_PE4_5_DEV,CHX002_PE4_FUN,D3D5F1_BRIDGE_CTL);
		}
		
		AsiaMemoryWrite8(Value64,Value8);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_RPE0DBG_PEXC=%x\n",AsiaMemoryRead8((UINTN)Value64)));

		//PEG hot reset 0->1->0 dxf0 rx3e bit 6
		Value8 = AsiaPciRead8(Address);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Bf_DxF0_Rx3e=%x\n",Value8));
		Value8 |= D3D5F1_RSRST; //Bit 6
		AsiaPciWrite8(Address,Value8);//write 1
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_DxF0_Rx3e=%x\n",AsiaPciRead8(Address)));

		//Delay 
		PeiNbPcieStall(PeiServices, 0x14);	//20 ms	//delay 2ms

		Value8 &= ~D3D5F1_RSRST;
		AsiaPciWrite8(Address,Value8);//write 0
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_DxF0_Rx3e=%x\n",AsiaPciRead8(Address)));


		if(NbConfig->CPU_FSBC_MISSPACKE_EN)
		{
			//PMIO Rx94
			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG);
			Value32 &= 0xF0000000;
			Value32 |= PMIO_PAD_WR;
			Value32 |= BIT16;
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG,Value32);
			
			//PMIO Rx8C
			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA);
			Value32 &= (~BIT29);
			Value32 |= BIT28;
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA,Value32);
			PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_D17F0_Rx8c=%x\n",AsiaPciRead32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA)));

			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG);
			Value32 &= (~PMIO_PAD_WR);
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG,Value32);
		}

		if(NbConfig->CPU_FSBC_TIGPULSE_EN)
		{
			//FSBC_TIGPULSE
			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG);
			Value32 &= 0xF0000000;
			Value32 |= PMIO_PAD_WR;
			Value32 |= BIT17;
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG,Value32);

			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA);
			Value32 &= (~BIT12);
			Value32 &= (~BIT13);
			Value32 |= BIT11;
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA,Value32);
			PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_D17F0_Rx8c=%x\n",AsiaPciRead32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA)));

			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG);
			Value32 &= (~PMIO_PAD_WR);
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG,Value32);
		}
		// wait for PCIE link stable
	    //Delay 
		PeiNbPcieStall(PeiServices, 0x60);	//20 ms //delay 2ms
			
		if(NbConfig->CPU_FSBC_IFSBCSTP_EN)
		{
			//FSBC_IFSBCSTP
			Value32 = AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG);
			Value32 &= 0xF0000000;
			Value32 |= PMIO_PAD_WR;
			Value32 |= BIT17;
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG,Value32);

			Value32=AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA);
			Value32 &= (~BIT18);
			Value32 &= (~BIT17);
			Value32 |= BIT16;
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA,Value32);
			PEI_DEBUG((PeiServices,EFI_D_ERROR,"Af_D17F0_Rx8c=%x\n",AsiaPciRead32(Pmio + PMIO_PAD_CTL_REG_WRITE_DATA)));

			Value32=AsiaIoRead32(Pmio + PMIO_PAD_CTL_REG);
			Value32&=(~PMIO_PAD_WR);
			AsiaIoWrite32(Pmio + PMIO_PAD_CTL_REG,Value32);
		}
		
		if(NbConfig->CPU_FSBC_STREAM_EN==1)//CPU FSBC Stream Mode enable ,Dump to pcie, stream mode , snapshot mode
		{
			UINT64 MsrValue;
	
			MsrValue = 0x0001800050000000;
			EfiWriteMsr(0x160b, MsrValue);
			PEI_DEBUG((PeiServices,EFI_D_ERROR,"FSBC_MSR[%x]:%llx\n",0x160B,EfiReadMsr(0x160B)));
			
			MsrValue = 0x00008007;
			EfiWriteMsr(0x1609, MsrValue);
			PEI_DEBUG((PeiServices,EFI_D_ERROR,"FSBC_MSR[%x]:%llx\n",0x1609,EfiReadMsr(0x1609)));
		}
	}

    return EFI_SUCCESS;

}
#ifdef ZX_TXT_SUPPORT
/**
   This Function will enable DPR.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  pointer to ASIA_NB_CONFIGURATION.

  @return The value from this function.

**/
EFI_STATUS
PeiEnableDpr(
	IN EFI_PEI_SERVICES      **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	EFI_STATUS                      Status;
	ASIA_VARIABLE                   TxtVariable;
	ASIA_VARIABLE                   *AsiaVariable;
	VOID                            *TxtVariableHob;
	UINTN                           VarSize;
	UINT64                          Address;
	EFI_PEI_HOB_POINTERS            GuidHob;

#if (PI_SPECIFICATION_VERSION < 0x00010000)
	EFI_PEI_READ_ONLY_VARIABLE_PPI *VarPpi;
#else
	EFI_PEI_READ_ONLY_VARIABLE2_PPI *Var2Ppi;
#endif

	Status = (*PeiServices)->CreateHob(
                 PeiServices,
                 EFI_HOB_TYPE_GUID_EXTENSION,
                 sizeof(EFI_HOB_GUID_TYPE) + sizeof(ASIA_VARIABLE),
                 &TxtVariableHob
             );
	if (EFI_ERROR(Status))
		return Status;
	GuidHob.Raw = TxtVariableHob;
	GuidHob.Guid->Name = gAsiaVariableGuid;
	AsiaVariable = (ASIA_VARIABLE *)((VOID *)((UINT8 *)(&(GuidHob.Guid->Name)) + sizeof(EFI_GUID)));

#if (PI_SPECIFICATION_VERSION < 0x00010000)
	Status = (*PeiServices)->LocatePpi(PeiServices, &gEfiPeiReadOnlyVariablePpiGuid, 0, NULL, (VOID **)&VarPpi);
	VarSize = sizeof(ASIA_VARIABLE);
	Status = VarPpi->PeiGetVariable(
				PeiServices,
				ASIA_VARIABLE_NAME,
				&gAsiaVariableGuid,
				NULL,
				&VarSize,
				&TxtVariable);
#else
    Status = (*PeiServices)->LocatePpi(PeiServices, &gEfiPeiReadOnlyVariable2PpiGuid, 0, NULL, (VOID **)&Var2Ppi);
	VarSize = sizeof(ASIA_VARIABLE);
	Status = Var2Ppi->GetVariable(
				Var2Ppi,
				ASIA_VARIABLE_NAME,
				&gAsiaVariableGuid,
				NULL,
				&VarSize,
				&TxtVariable);
#endif
	ASSERT_PEI_ERROR(PeiServices, Status);
	AsiaVariable->TXT = TxtVariable.TXT;
	
	if (TxtVariable.TXT == 1)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "TXT function is enable. \n"));
		// Init DPR in D0F3_Rx15A
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DMA_PROTECTION_CTL);
		AsiaPcieModify16(NbConfig->PcieBar, Address, D0F3_DPR_SIZE_7_0 /*| D0F3_DPR_EN*/, BIT6 /*| BIT2*/); // set DPR_SIZE = 4 MB, enable DPR will result in boot OS fail
		// AsiaPcieModify8(NbConfig->PcieBar, Address, D0F3_DPR_LOCK, BIT0);  // set DPR_LOCK bit
	}
	return EFI_SUCCESS;
}
#endif

// Fill the sracth register MB type(D0F6 Rx41).
/**
   This Function will fill MB type to scratch register.
  
  @param  VOID

  @return The value from this function.

**/
EFI_STATUS
PeiFillMbType(VOID)
{
    UINT8  MbType = 0;
    // 
    // MB_CFG value:
    //
    // HX002EA: 1
    // HX002EB: 2
    // HX002EC: 3
    // HX002ED: 4
    // HX002EE: 5
    // HX002EF: 6
    // HX002EG: 7
    // HX002EH: 8
    // HX002EK: 9
    // HX002EL: 10
    //

    #if defined(MB_TYPE_HX002EA)
        MbType = 1;
    #elif defined(MB_TYPE_HX002EB)
        MbType = 2;
    #elif defined(MB_TYPE_HX002EC)
        MbType = 3;
    #elif defined(MB_TYPE_HX002ED)
        MbType = 4;
    #elif defined(MB_TYPE_HX002EE)
        MbType = 5;
    #elif defined(MB_TYPE_HX002EF)
        MbType = 6;
    #elif defined(MB_TYPE_HX002EG)
        MbType = 7;
    #elif defined(MB_TYPE_HX002EH)
        MbType = 8;
    #elif defined(MB_TYPE_HX002EK)
        MbType = 9;
    #elif defined(MB_TYPE_HX002EL)
        MbType = 10;
    #endif

    // Fill the MB type to the scratch register(D0F6 Rx41)
    AsiaPciWrite8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_1+1, MbType);

    return EFI_SUCCESS;
}

/**
   This Function will dump pci device.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  Bus  Target bus number.
  @param  Dev  Target device number.
  @param  Fun  Target function number.

  @return The value from this function.

**/
static VOID V_DumpPciDev(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 Bus, IN UINT8 Dev, IN UINT8 Fun
    )
{
	UINT64   Address;
	UINT8    Data;
	UINT16	Index1, Index2;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump Bus 0x%02x Dev 0x%02x Fun 0x%02x :\n",Bus,Dev,Fun));
	///
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "---+-----------------------------------------------\n"));
	for(Index1=0;Index1<0x20;Index1++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%03x|", Index1*16));
		for(Index2=0;Index2<0x10;Index2++)
		{
			Address = AsiaPciAddress(Bus, Dev, Fun, Index1*16+Index2);
			Data = AsiaPcieRead8(0xE0000000, Address);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ", Data));
			if(Index2==0x0F)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
		}
		if((Index1%0x10)==0x0F)
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "---------------------------------------------------\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
	return;
}

/**
   This Function will dump sec set.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.

  @return The value from this function.

**/
VOID V_DumpSecSet(IN EFI_PEI_SERVICES **PeiServices)
{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n ******** \n Dump Sec-Phase setting: \n"));
	V_DumpPciDev(PeiServices,0,0,5); // Dump D0F5
	V_DumpPciDev(PeiServices,0,0x11,0); // Dump D17F0	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n ******** \n End of Dump Sec-Phase setting: \n"));	
}

/**
   This Function will get efused vid policy.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.

  @return The value from this function.

**/
EFI_STATUS GetEfusedVidPolicy
	(
		IN EFI_PEI_SERVICES **PeiServices
		)
{
//YKN-20161024 -s
   // UINT32  HDABase32 = 0xFC000000;
UINT32  HDABase32 = 0xFB000000;
//YKN-20161024 -e

	UINT32  Index_Offset = 0x82B8;
	UINT32  Enable_Offset = 0x82C0, Data_Offset = 0x82BC;
	UINT32  Tmp_Index, Tmp_Enable, Tmp_Data;
    UINT8   Tmp8;
	EFI_BOOT_MODE   BootMode;
   
    

    (*PeiServices)->GetBootMode (PeiServices, &BootMode);

    if(BootMode == BOOT_ON_S3_RESUME)
        return EFI_SUCCESS;
	
	AsiaPciWrite32(CHX002_EUMA|0x10, HDABase32);
	AsiaPciWrite8(CHX002_EUMA|0x04, 0x03);

	Tmp_Index = AsiaMemoryRead32(HDABase32|Index_Offset);
	Tmp_Index &= ~0x007F0000;
	Tmp_Index |= (UINT32)(0x6F << 16);
	AsiaMemoryWrite32(HDABase32|Index_Offset, Tmp_Index);

	Tmp_Enable = AsiaMemoryRead32(HDABase32|Enable_Offset);
	Tmp_Enable &= ~0x72000000;
	Tmp_Enable |= 0x22000000; //A_READ mode
	AsiaMemoryWrite32(HDABase32|Enable_Offset, Tmp_Enable);

	do {
		  Tmp_Enable = AsiaMemoryRead32(HDABase32|Enable_Offset);
		}while((Tmp_Enable & 0x2000000) == 0x2000000);

	Tmp_Data = AsiaMemoryRead32(HDABase32|Data_Offset);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Tmp_Data = %X \n", Tmp_Data));


	// Clear BAR & Decode
	AsiaPciWrite32(CHX002_EUMA|0x10, 0);
	AsiaPciWrite8(CHX002_EUMA|0x04, 0);

	//VID_Lock_Default is at 6F byte 2[0], VID_Default is at 6F byte1 bit 0;
    Tmp_Data &= 0x10100;

    //D0F6 RX70 usage:
    // [0]-- VID_Default, 0=1D17, 1=1106
    // [1]-- VID_Lock_Default, 0=un-locked, 1=locked
    // [2]-- Bit0&1 valid
    //Tmp8 = AsiaPciRead8(CHX001_SCRCH|D0F6_BIOS_SCRATCH_REG_13);
	Tmp_Data >>= 8;
	Tmp8 = (UINT8)Tmp_Data;
	Tmp_Data >>= 7;
	Tmp8 |= (UINT8)Tmp_Data;
	Tmp8 |= 0x4;    //BIT2
	AsiaPciWrite8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13, Tmp8);

	return EFI_SUCCESS;
}

/**
   This Function will do Nb PreMemoryInit.
	
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  This  pointer to EFI_ASIA_NB_PPI.

  @return The value from this function.

**/	
EFI_STATUS
PeiNbPreMemoryInit (
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_ASIA_NB_PPI *This
)
{
    EFI_STATUS Status=EFI_SUCCESS;
    ASIA_NB_PEI_PRIVATE_DATA *PrvData;
    DISPLAY_DEVICE	PrimaryDisplay;
    ASIA_NB_CONFIGURATION * NbConfig;
	EFI_ASIA_SB_PPI	      *pSbPpi;
	EFI_GUID               AsiaSbPpiGuid = EFI_ASIA_SB_PPI_GUID;
	ASIA_SB_CONFIGURATION *SbConfig;
	BOOLEAN                SataEn = TRUE;   

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbPreMemoryInit()\n"));

    /// print Sec Phase's setting : D0F5_Rx60 / D17F0_Rx81/Rx88
    //V_DumpSecSet(PeiServices);
    ///
    PrvData = GET_PRIVATE_DATA_FROM_ASIANBPPI(This); //use internal param

    NbConfig = (ASIA_NB_CONFIGURATION *)(This->NbCfg);

#ifdef ZX_DUALSOCKET
	//Eric debug for dual socket
	if((AsiaPciRead8(CHX002_PCCA|0x59)) & BIT2)
		NbConfig->ZxeDualSocket = 1;
	else
		NbConfig->ZxeDualSocket = 0;
	/*
	if(NbConfig->ZxeDualSocket == 1) {
		switch((AsiaPciRead8(CHX002_HIF|D0F2_MMIOCFG_DECODER))&0x3) {
			case 0:	 NbConfig->ZxeSlaveBusNum=0x80;break;
			case 1:	 NbConfig->ZxeSlaveBusNum=0x40;break;
			case 2:	 NbConfig->ZxeSlaveBusNum=0x20;break;
			default: NbConfig->ZxeSlaveBusNum=0x80;break;
		}		
	}
	*/
	if(NbConfig->ZxeDualSocket == 1){
		PeiNbVpiLinkEarlyInit(PeiServices, NbConfig);
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Exit PeiNbVpiLinkEarlyInit()\n"));
	if((AsiaPciRead8(CHX002_SCRCH|0x4D)) & BIT2)
		NbConfig->ZxeDualSocket = 0; //After VPI linkup, and failed, update ZxeDualSocket	
	
	if(NbConfig->ZxeDualSocket == 1) {
		//Disable unused devices on SLAVE
		//TXT
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-TXT\n"));
		AsiaPciModify8(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_HB_DEV, CHX002_APIC_FUN, D0F5_LOCK_CTL_AND_OTHERS), D0F5_RTXTEN, 0);
		//RTC & KBDC
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-RTC & KBDC\n"));
		AsiaPciModify8(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_FUN_CTL_2), 
						D17F0_RRTC|D17F0_RPS2|D17F0_RKBC, 0);
		//HPET
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-HPET\n"));
		AsiaPciModify8(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_HPET_CTL), D17F0_ENHPET, 0);
		//HDAC
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-HDAC\n"));
		AsiaPciModify8(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_BUSC_DEV, CHX002_PCCA_FUN, D17F7_HDAC_AND_P2P_RELATED_CTL), D17F7_RDIS_AZ, D17F7_RDIS_AZ);
		Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaSbPpiGuid, 0, NULL, &pSbPpi);
		if(!EFI_ERROR(Status)) {
		  SbConfig = pSbPpi->SbCfg;
		  Pmio = SbConfig->SlavePmioBar;
		  PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-[D17F0 part]\n"));
		  
		  AsiaPciModify16(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_PMU_PM_IO_BASE), D17F0_PMU_PMIOBA,Pmio);
		  AsiaPciModify8(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_PMU_PM_GENERAL_CFG_2),D17F0_PMU_RENIO,D17F0_PMU_RENIO);
		  //ESPI
		  PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-ESPI\n"));
		  AsiaIoModify8(Pmio+PMIO_ESPI_SUSPEND_DOMAIN_CTL_REG,PMIO_ENESPI_SW,0);
		  
		  AsiaPciModify32 (ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_BUSC_DEV, CHX002_BUSC_FUN, D17F0_MMIO_SPACE_BASE_ADR),
		                    D17F0_F0MMIOBA_31_12, (UINT32)(SbConfig->D17F0MmioBarSlave>>8));
		  PEI_DEBUG((PeiServices, EFI_D_INFO, "D17F0 Slave MMIOBar = 0x%8x \n",SbConfig->D17F0MmioBarSlave ));
		  //TIMERC D17F0 MMIO RX78[3] = 0
		  AsiaMemoryModify8(SbConfig->D17F0MmioBarSlave+ D17F0MMIO_LPCCLK_PHASE_SEL_CTL_REG,  0x08, 0);
		  
		}
		#ifdef CHX002_PXP
		//Disable D4F0_PE4 D0F5 RxF6[0]=1
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable-PCIE PE4\n"));
		AsiaPciModify32(ASIA_PCI_ADDRESS(NbConfig->ZxeSlaveBusNum, CHX002_HB_DEV, CHX002_APIC_FUN, D0F5_DEV_EXIST_REG_SPACE),
				D0F5_RDV4F0CYCABT,0);
		#endif
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[Dual] Disable - All Completed\n"));
	}
#endif	
    //For FPGA bring up, do not call GetEfusedVidPolicy because there is no GFX.
    //MKE_20170220 PXP and Haps Not Need_S
	#if 0
		GetEfusedVidPolicy(PeiServices);
	#endif
	//MKE_20170220 PXP and Haps Not Need_E
	//YKN-20161024 -s
	AsiaPciWrite8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13, 0x04);
    //YKN-20161024 -e
    
	SyncConfigToRegsiter(PeiServices, NbConfig);	//lana_debug_pcie
	
    // NB Stage1
    
    //Save romsip version to D0F6Rx44
    AsiaPciWrite8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_2, Romsip_Ver);
    
    // Fill the sracth register MB type D0F6 Rx41.
    PeiFillMbType();

    CheckWarmReboot(PeiServices, NbConfig);
	//YKN-20170509 -s
	PeiNbInternalClkGen(PeiServices,NbConfig);
//YKN-20170509 -s


    //Initialize MCA registers
	PeiMCAInit(PeiServices,NbConfig);


	//Initialze RAIDA register
	//PeiRAIDAInit(PeiServices,NbConfig);

    //Initialize HIF registers
    PeiHIFInit(PeiServices,NbConfig);

    //Initialize NB PMU registers
    PeiNbPMInit(PeiServices,NbConfig);

    //Initialize NB APIC registers
    PeiNbAPICInit(PeiServices,NbConfig);

	// ZYC - 20180808 Process SATA Driving Table bfeore ephy cfg done
	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaSbPpiGuid, 0, NULL, &pSbPpi);
    if(!EFI_ERROR(Status)){
      SbConfig = pSbPpi->SbCfg;
      SataEn   = SbConfig->SataEn;
	}
	if(SataEn){
        PROCESS_SB_R64326408M_TABLE(Sata_Driving_TBL, Sata_Driving_TBL_Items);
	}

    //Initialize Pcie
    PEI_PCIE_NB_80_PORT(PeiServices, PEI_PCIE_INIT);//JennyChen add for Chx002 80 port
    PeiNbPcieInit(PeiServices, NbConfig);
	
#ifdef ZX_DUALSOCKET	
//#ifdef DUAL_SOCKET_CODE 
	if(NbConfig->ZxeDualSocket == 1){
		PeiNbPcieInitSlave(PeiServices, NbConfig);
	}
	
	//Initialize VPI
	if(NbConfig->ZxeDualSocket == 1){
		PeiNbVpiInit(PeiServices, NbConfig);
	}
#endif

	//Initialize CKGSRC
	PeiNbCkgsrcInit(PeiServices, NbConfig);

	//set debug signal
    //Please debug signal owner make sure the setting the setting is right.
	ProgramDebugSignal(PeiServices,NbConfig);

	//Initialize TA (Virtualization)
    PeiNbTAInit(PeiServices, NbConfig);
	
    PrimaryDisplay = IGD;

    CheckPcieVgaCard (PeiServices, NbConfig, &PrimaryDisplay);

    if ((PrimaryDisplay != IGD) && (!NbConfig->DualVGA) &&
		(NbConfig->PrimaryGraphicAdapter == PCIE_PCI_UMA)){
        NbConfig->UMAEn = FALSE;
    }
	  //IVS-20181015 Judge whether to Call INT15
	if(((NbConfig->UMAEn)&&(NbConfig->PrimaryGraphicAdapter == UMA_PCIE_PCI))||(NbConfig->UMAEn)&&(NbConfig->PrimaryGraphicAdapter == PCIE_PCI_UMA)&&(PrimaryDisplay == IGD))
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_SCRCH_FUN,D0F6_BIOS_SCRATCH_REG_12), BIT0, BIT0);
	else
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_SCRCH_FUN,D0F6_BIOS_SCRATCH_REG_12), BIT0, 0);

	//Initialize FSBC
//	PeiNbFSBCInit(PeiServices, NbConfig);
    
#ifdef ZX_TXT_SUPPORT
	//Initialize TXT Dpr
	PeiEnableDpr(PeiServices, NbConfig);
#endif

   //MTN-20180725-Start
   ///Patch For D0F3 Yellow mark in Win10 Device Manager
   AsiaPciWrite8(CHX002_APIC|D0F5_PMU_CTL, AsiaPciRead8(CHX002_APIC|D0F5_PMU_CTL) |D0F5_RPEROWEN);
   AsiaPciWrite8((CHX002_DRAM|D0F3_CAP_POINTER), 0x00);
   //MTN-20180725-End
    PEI_DEBUG((PeiServices, EFI_D_INFO, "Finish PeiNbPreMemoryInit()\n"));

    return Status;
}

/**
   This Function will do Post Memory Init.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  This  pointer to EFI_ASIA_NB_PPI.

  @return The value from this function.

**/
EFI_STATUS
PeiNbPostMemoryInit (
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_ASIA_NB_PPI *This
)
{
	ASIA_NB_CONFIGURATION * NbConfig;

	NbConfig = (ASIA_NB_CONFIGURATION *)(This->NbCfg);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbPostMemoryInit()\n"));
	
    return EFI_SUCCESS;
}

// Instance of AsiaNbPpi->PostMemoryInitS3()
/**
   This Function will do S3 Memory Init.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  This  pointer to EFI_ASIA_NB_PPI.

  @return The value from this function.

**/
EFI_STATUS
PeiNbPostMemoryInitS3 (
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_ASIA_NB_PPI *This
)
{
    ASIA_NB_CONFIGURATION * NbConfig;

    PEI_DEBUG((PeiServices, EFI_D_INFO, "PeiNbPostMemoryInitS3()\n"));

    NbConfig = (ASIA_NB_CONFIGURATION*)(This->NbCfg);
    PEI_PCIE_NB_80_PORT(PeiServices, PEI_NB_POST_MEMORY_S3);  //JennyChen add for Chx002 80 port


	if (NbConfig->PciePE0){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE0);
	}
	if (NbConfig->PciePE1){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE1);
	}
	if (NbConfig->PciePE2){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE2);
	}
	if (NbConfig->PciePE3){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE3);
	}
	if (NbConfig->PciePE4){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE4);
	}
	if (NbConfig->PciePE5){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE5);
	}
	if (NbConfig->PciePE6){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE6);
	}
	if (NbConfig->PciePE7){
		PeiNbPcieS3DoEQ(PeiServices,NbConfig,CHX002_PE7);
	}
	

    return EFI_SUCCESS;
}


