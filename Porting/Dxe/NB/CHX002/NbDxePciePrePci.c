/** @file
   ZX-E(CHX002) Asia NbDxe library functions : NbDxePciePrePci.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************




#include "AsiaIoSaveLib.h"

#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include "NbDxePcie.h"

#include "NbDxePciePrePci.h"

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID 
RpAggresivePmMode(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64    Addr
)
{
    UINT64 pciebase;
    UINT8 cardPresent;

    cardPresent = AsiaPciRead8(Addr|D3D5F1_SLOT_STA_1);
    cardPresent &= D3D5F1_SPDCST;

    pciebase = NbCfg->PcieBar;

    //PCIE_Aggresive_PM_Support start
    if(cardPresent != D3D5F1_SPDCST)
    {
        //Disable Aggressive Power Management When No Device Plug:[Bit2]
        //!!!: Bit2 must clear before Bit1 set to 1
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32), D3D5F1_RDEVDETPM, 0);
        //Rx1E8[1] Enable PHYES Level 2 Power Down when there is no device existing behind this root port
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32), D3D5F1_RPDL2, D3D5F1_RPDL2);
        //Rx1E8[7] For the Port that does not support Hot_Plug, program this bit to 1b to power off EPHY RX Electrical Idle Detector to save more power
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32), D3D5F1_RRXEIDPD, D3D5F1_RRXEIDPD);
    }
    else
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32), D3D5F1_RPDL2, 0);

    //Enable L1 MPLL power down in Gen2 speed:[Bit6]
    //Enable Clock Gating on Unused Lanes in a multilane Link:[Bit5]
    //Enable Power down on Unused lanes in a multilane Link:[Bit4]
    //Enable Aggressive Power Management in Rx Path to Data Link Layer Module(DLLM):[Bit3]
    //Turn off TPLL When in L1 state:[Bit0]
/*
    AsiaPcieModifySave8(pciebase, Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32), D3D5F1_RL1DYNPMG2 +
                        D3D5F1_RLNCLKPM +
                        D3D5F1_RLNPWR +
                        D3D5F1_RDSKWPM +
                        D3D5F1_RL1TPLLPD,

                        D3D5F1_RL1DYNPMG2 +
                        D3D5F1_RLNCLKPM +
                        D3D5F1_RLNPWR +
                        D3D5F1_RDSKWPM +
                        D3D5F1_RL1TPLLPD);
*/

    //Enable Aggressive Power Management When No Device Plug:[Bit2]
    AsiaPcieModifySave8(pciebase, Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32), D3D5F1_RDEVDETPM, D3D5F1_RDEVDETPM);

	DEBUG((EFI_D_ERROR, "[PCIE_DEBUG] Aggressive PM = 0x%02x\n",
		AsiaPcieRead8(pciebase,  Addr|((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32))));
	
}


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID	
PcieRpControl(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
	//For CHX002, PCIE Rx1E8 related registers will be set in both P mode and E mode
    if ((NbCfg->NBSPEValue >= CHIP_SPE_VALUE_PERFORMANCE)){
		
		RpAggresivePmMode(NbCfg, CHX002_PE0);
        RpAggresivePmMode(NbCfg, CHX002_PE1);
        RpAggresivePmMode(NbCfg, CHX002_PE2);
	 	RpAggresivePmMode(NbCfg, CHX002_PE3);
		
		RpAggresivePmMode(NbCfg, CHX002_PE4);
        RpAggresivePmMode(NbCfg, CHX002_PE5);

		RpAggresivePmMode(NbCfg, CHX002_PE6);
		RpAggresivePmMode(NbCfg, CHX002_PE7);
		
    }else if (NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
    

        if (NbCfg->D3F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE0);
        if (NbCfg->D3F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE1);
        if (NbCfg->D3F2SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE2);
	 	if (NbCfg->D3F3SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE3);

        if (NbCfg->D4F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE4);
		if (NbCfg->D4F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE5);
		if (NbCfg->D5F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE6);
		if (NbCfg->D5F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            RpAggresivePmMode(NbCfg, CHX002_PE7);
    }
	
    //JIH-2015091401 Comment out EphyAggresivePmMode in Logic Saving power stage.
    // EphyAggresivePmMode(NbCfg);

}




//By reading the RL1TPLLPD(Turn off TPLL When in L1 State) 
//to ensure the L1 Exit Latency
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID ProgramRpExitLatency(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64	Address
)
{
    UINT8 		iData1;
    UINT32	iData2;

    iData1 = AsiaPcieRead8(NbCfg->PcieBar, Address|(((UINT64)(D3D5F1_AGGRESSIVE_PM) << 32))) ;
    iData1 &= BIT0;
    if(iData1 == BIT0)
    {
        iData2 = AsiaPciRead32(Address|D3D5F1_LINK_CAPS_1_D4F0 );
        iData2 &= ~(D3D5F1_LKL0SE + D3D5F1_LKL1EL);
        iData2 |= 0x20000;
        AsiaPciWriteSave32(Address|D3D5F1_LINK_CAPS_1_D4F0, iData2);
    }
    else
    {
        iData2 = AsiaPciRead32(Address|D3D5F1_LINK_CAPS_1_D4F0 );
        iData2 &= ~(D3D5F1_LKL0SE + D3D5F1_LKL1EL);
        iData2 |= 0x18000;
        AsiaPciWriteSave32(Address|D3D5F1_LINK_CAPS_1_D4F0, iData2);
    }
}
/*+ DSZ_Porting -- (YSW-2017031701) Modify PCIE Module Code for RP L1 Exit Latency Capability calculation*/


/**
For CHX002:
Lane0 - Gen1: Rx20A[11:9]
Lane0 - Gen2: Rx22A[11:9]
Lane0 - Gen3: Rx24A[11:9]
Lane1 - Gen1: Rx28A[11:9]
...
Lane13-Gen1: Rx88A[11:9]
...
Lane14-Gen1:Rx300A[11:9]
Lane14-Gen2:Rx302A[11:9]
...
**/
RPL1SET_TBL RPL1ExitLatencyTblx[] = {
	//ECFG	PE0		PE1		PE2		PE3		PE4	       PE5		PE6		PE7
	{0x03,   0x70B,   0xFF,  0x80B,  0x88B,  0x30B,   0xFF,  0x20B,  0x28B},
	{0x00,   0x70B,   0xFF,  0x80B,  0x88B,  0x30B,   0xFF,  0x20B,  0xFF}
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
SetExitLatencyCapability(
    ASIA_NB_CONFIGURATION *NbCfg
)
{

	UINT8 PhyCfgFlag;
	UINT8 TblIndex;
	UINT8 ExistFlagx = 0;		
	RPL1SET_TBL *Ptx = RPL1ExitLatencyTblx;
	UINT8 TblSize = sizeof(RPL1ExitLatencyTblx)/sizeof(RPL1SET_TBL);


	AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, D0F5_RPEROWEN);

	// Get current PHYCFG
	PhyCfgFlag = (AsiaPcieRead8(NbCfg->PcieBar, CHX002_GFXAX |((UINT64)D0F0_PCIE_ROMSIP_REGS_Z1<<32)) & D0F0_RPCIESATACFG_3_0);

	DEBUG((EFI_D_ERROR, "[PCIE] Starting check and reprogram PCIE_RP_L1_EXIT_LATENCY: PHYCFG = 0x%04x\n", PhyCfgFlag));

	// Search the porpure item in table
	for(TblIndex = 0; TblIndex < TblSize; TblIndex++){
		if(Ptx[TblIndex].ECFG == PhyCfgFlag){
			ExistFlagx = 1;
			break;
		}
	}
	if(ExistFlagx != 1){
		DEBUG((EFI_D_ERROR, "                      Failed to reprgraming L1 Exit Latency!!!\n"));
		return EFI_NOT_FOUND;
	}
	
	DEBUG((EFI_D_ERROR, "                      Index = %d\n", TblIndex));

#if 1 
	if(NbCfg->PciePE0){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE0, Ptx, TblIndex);

	}
	if(NbCfg->PciePE1){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE1, Ptx, TblIndex);

	}
	if(NbCfg->PciePE2){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE2, Ptx, TblIndex);

	}
	if(NbCfg->PciePE3){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE3, Ptx, TblIndex);

	}
	if(NbCfg->PciePE4){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE4, Ptx, TblIndex);

	}
	if(NbCfg->PciePE5){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE5, Ptx, TblIndex);

	}
	if(NbCfg->PciePE6){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE6, Ptx, TblIndex);

	}
	if(NbCfg->PciePE7){
		RPReProgramL1ExitLatency(NbCfg, CHX002_PE7, Ptx, TblIndex);

	}
#endif 
    AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);

	return EFI_SUCCESS;

}

/**
@this function used to calculate the "Real" L1 Exit Latency
	for a specific root port
@Note1: Since the value of FRPxx_P1EXT_Gx_ must be same with 
		each lanes for a multi-lane port, so we just need to get 
		Lane0 to calculate the Real L1 Exit Latency
@Note2: for Gen1/2/3 speed, the L1 Exit latency was different.
		need to read different EPHY registers to get them
@For Reference:		
For FRPxx_P1EXT_Gx[2:0]
	3'b000: 1us
	3'b001: 2us
	3'b010: 4us
	3'b011: 8us
	3'b100: 16us (default)
	3'b101: 32us
	3'b110: 64us
	3'b111: 128us

**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
RPReProgramL1ExitLatency(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT64 Addr,
	RPL1SET_TBL *Ptx,
	UINT8 TblIndex)
{
	UINT8 ItemC,ItemC_us,ItemD_us,ItemA_us;
	UINT16 RegOff = 0;
	UINT32 ReprogramedValue_us,ReprogramedValue;
	UINT8 Cls;
	UINT64 PhyBaseAddr = NbCfg->PcieEPHYBar;
	UINT8 RegTPLLPD = 0;

	// IF VID/DID of target RP reflected as "0xFFFF_FFFF" then skip
	DEBUG((EFI_D_ERROR, "                      RP VID/DID: 0x%08x\n", AsiaPcieRead32(NbCfg->PcieBar, Addr|((UINT64)D3D5F1_VID<<32))));
	if(AsiaPcieRead32(NbCfg->PcieBar, Addr|((UINT64)D3D5F1_VID<<32)) == 0xFFFFFFFF)
		return EFI_NOT_FOUND;

	// Get the real register offset
	switch(Addr){
		case CHX002_PE0:
			RegOff = Ptx[TblIndex].RegForPE0;
			break;		
		case CHX002_PE1:
			RegOff = Ptx[TblIndex].RegForPE1;
			break;
		case CHX002_PE2:
			RegOff = Ptx[TblIndex].RegForPE2;
			break;
		case CHX002_PE3:
			RegOff = Ptx[TblIndex].RegForPE3;
			break;
		case CHX002_PE4:
			RegOff = Ptx[TblIndex].RegForPE4;
			break;	
		case CHX002_PE5:
			RegOff = Ptx[TblIndex].RegForPE5;
			break;
		case CHX002_PE6:
			RegOff = Ptx[TblIndex].RegForPE6;
			break;
		case CHX002_PE7:
			RegOff = Ptx[TblIndex].RegForPE7;
			break;			
		default:
			break;
	}

	DEBUG((EFI_D_ERROR, "                      RegOff = 0x%04x \n",RegOff));
	// Get Current Link Speed  and get the Real Reg offset in EPHY
	Cls = 0xF & AsiaPcieRead8(NbCfg->PcieBar, Addr|((UINT64)D3D5F1_LINK_STA_1<<32));
	DEBUG((EFI_D_ERROR, "                      CLS = %d \n",Cls));
	if(Cls == 2){
		RegOff += RPL1ExitSBDG;
	}else if(Cls == 3){
		RegOff += (RPL1ExitSBDG+RPL1ExitSBDG);
	}

	// Get the P1 Exit Latency use the Real Register Offset
	ItemC = AsiaMemoryRead8(PhyBaseAddr + RegOff);
	ItemC = (ItemC>>1)&(0x7);
	ItemC_us = RPL1CapREG2REAL(ItemC);
	DEBUG((EFI_D_ERROR, "                      ItemC_us = %d \n",ItemC_us));
	if(ItemC_us > 128){
		// invalid value
		DEBUG((EFI_D_ERROR, "                      Invalid EPHY P1 Exit Latency!!!\n"));
		return EFI_NOT_FOUND;
	}
	
	// Get the ItemD;
	ItemD_us = RP_LPHY_Rx_L1_Recovery_Time;	

	//Get the ItemA;
	ItemA_us = RP_TPLL_POWERUP_AND_LOCK_Time;

	//Rules:
	//	When RL1TPLLPD (D3F0_Rx1E8[0]) is set to "0b":
	//	L0s Exit Latency = Item B
	//	L1 Exit Latency = Item C + Item D
	//	When RL1TPLLPD (D3F0_Rx1E8[0]) is set to "1b":
	//	L0s Exit Latency = Item B
	//	L1 Exit Latency = Item A + Item C + Item D
	//Note: This register will be set in SPE table?
	RegTPLLPD = AsiaPcieRead8(NbCfg->PcieBar, Addr|((UINT64)D3D5F1_AGGRESSIVE_PM<<32));
	RegTPLLPD &= D3D5F1_RL1TPLLPD;
	if(RegTPLLPD){
		ReprogramedValue_us = ItemA_us +ItemC_us + ItemD_us;
		ReprogramedValue = RPL1CapREAL2REG(ReprogramedValue_us) + 1;
	}else{
		ReprogramedValue_us = ItemC_us + ItemD_us;
		ReprogramedValue = RPL1CapREAL2REG(ReprogramedValue_us) + 1;
	}
	
	DEBUG((EFI_D_ERROR, "                      ReprogramedValue = %d \n",ReprogramedValue));

	// Reprogram the evaluated result to RP L1 Exit Latency Capability (RP_Rx4C[17:15])
	AsiaPcieModifySave32(NbCfg->PcieBar, Addr|((UINT64)D3D5F1_LINK_CAPS_1_D4F0<<32), 
											D3D5F1_LKL1EL,ReprogramedValue<<15);

	return EFI_SUCCESS;
}
/*- DSZ_Porting -- (YSW-2017031701) Modify PCIE Module Code for RP L1 Exit Latency Capability calculation*/
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID 
ProgramRpSlotPowerLimit(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64	Address
)
{

	//Set "Slot Power Limut Value" and "Slot Power Limit Scale" to 75W meet the PCIE GEN3 SPEC
	AsiaPcieModifySave16(NbCfg->PcieBar, Address|((UINT64)(D3D5F1_SLOT_CAPS_1) << 32), D3D5F1_RSPLV, 0x2580);

}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID 
SetRPSlotPowerLimit(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
    AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, D0F5_RPEROWEN);
	if((NbCfg->PciePE0)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE0);}
	if((NbCfg->PciePE1)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE1);}
	if((NbCfg->PciePE2)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE2);}
	if((NbCfg->PciePE3)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE3);}
	if((NbCfg->PciePE4)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE4);}
	if((NbCfg->PciePE5)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE5);}
	if((NbCfg->PciePE6)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE6);}
	if((NbCfg->PciePE7)&&(NbCfg->PcieRP)) {ProgramRpSlotPowerLimit(NbCfg, CHX002_PE7);}
    AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
}



//Here is PCIE P-Mode Setting Point for Registers which needs to be set according to specific Rule before PCI Enumeration
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID PciePrePCIRuleSettingPMode(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64	Address
)
{

	//TA Path Enable Control (RP_Rx1AA[4], default as "1b")
	//Set to 0b in E-Mode only when TACTL not supported (D0F5_Rx16D[1] = 0b)
	if(NbCfg->IOVEnable == FALSE)
		AsiaPcieModifySave8(NbCfg->PcieBar, Address|(((UINT64)(D3D5F1_UPSTREAM_PERFORMANCE_CTL_2) << 32)), D3D5F1_RTANBYPASS, 0x00);

}

//Here is PCIE E-Mode Setting Point for Registers which needs to be set according to specific Rule before PCI Enumeration
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID PciePrePCIRuleSettingEMode(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64	Address
)
{

}


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID 
BeforePciSetPcie(
    ASIA_NB_CONFIGURATION *NbCfg
)
{ 
    //ClearRpSlotStatus(NbCfg);


	//Since default value of  L1 Exit latency can't reflect the  real L1 Exit Latency
	// so we need to calculate it by software
    SetExitLatencyCapability(NbCfg); 


    DEBUG((EFI_D_ERROR, "BeforePciSetPcie() -> SetRPSlotPowerLimit\n"));
    SetRPSlotPowerLimit(NbCfg);

    //Special Setting in P-Mode
    if (NbCfg->NBSPEValue >= CHIP_SPE_VALUE_PERFORMANCE){
		

		PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE0);
        PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE1);
        PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE2);
	 	PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE3);
		
		PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE4);
        PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE5);

		PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE6);
		PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE7);
		
    }else if (NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
    

        if (NbCfg->D3F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE0);
        if (NbCfg->D3F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE1);
        if (NbCfg->D3F2SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE2);
	 	if (NbCfg->D3F3SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE3);

        if (NbCfg->D4F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE4);
		if (NbCfg->D4F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE5);
		if (NbCfg->D5F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE6);
		if (NbCfg->D5F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE)
            PciePrePCIRuleSettingPMode(NbCfg, CHX002_PE7);
    }

	//Special Setting in E-Mode
    if (NbCfg->NBSPEValue == CHIP_SPE_VALUE_ENERGY){
		

		PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE0);
        PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE1);
        PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE2);
	 	PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE3);
		
		PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE4);
        PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE5);

		PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE6);
		PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE7);
		
    }else if (NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
    
        if (NbCfg->D3F0SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE0);
        if (NbCfg->D3F1SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE1);
        if (NbCfg->D3F2SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE2);
	 	if (NbCfg->D3F3SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE3);

        if (NbCfg->D4F0SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE4);
		if (NbCfg->D4F1SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE5);
		if (NbCfg->D5F0SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE6);
		if (NbCfg->D5F1SPEValue == DEVICE_SPE_VALUE_ENERGY)
            PciePrePCIRuleSettingEMode(NbCfg, CHX002_PE7);
    }

}

//JNY porting for CHX002-S
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID PowerDownUnusedEPHY(
    ASIA_NB_CONFIGURATION 	*NbCfg
)
{
    UINT64 pciebase, ephybase;
    UINT8 EPHYCFG;

    pciebase = NbCfg->PcieBar;
    ephybase = NbCfg->PcieEPHYBar;

    EPHYCFG = AsiaPcieRead8(pciebase, CHX002_GFXAX|((UINT64)(D0F0_PCIE_ROMSIP_REGS_Z1) << 32)) & D0F0_RPCIESATACFG_3_0;

    // for PHY_A 
    if((EPHYCFG == 0x00) ||(EPHYCFG == 0x0B) ){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
		  AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
    	}
	
    if((EPHYCFG == 0x01) ||(EPHYCFG == 0x0A)){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE7|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
		  AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
    	}
    if(EPHYCFG == 0x02){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE5|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE7|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
		  AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);

    	}
    if(EPHYCFG == 0x03){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE3|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE7|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
		  AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
    	}
    if(EPHYCFG == 0x04){
      if(((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE1|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE3|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE7|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
	  AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
	}
    if(EPHYCFG == 0x05){
      if(((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE1|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE3|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE5|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
		((AsiaPcieRead8(pciebase, CHX002_PE7|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
	  AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
	}
    // for PHY_A ,include VPI 
    /*if((EPHYCFG == 0x06) ||(EPHYCFG == 0x07)){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE7|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
		  AsiaPcieModify16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
    	}
    if((EPHYCFG == 0x08) ||(EPHYCFG == 0x09)){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE6|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE0|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE1|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE3|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00))
		  AsiaPcieModify16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X14, D0F0_RDISPEXC_X14);
    	}
	*/

    // for PHY_B
    if( (EPHYCFG == 0x00)){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE3|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)){
	 AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X2, D0F0_RDISPEXC_X2);
	    		}
    	}
    if( (EPHYCFG == 0x01)){
		if((AsiaPcieRead8(pciebase, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00){
	 AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X2, D0F0_RDISPEXC_X2);
			}

    	}
	 // for PHY_B,include VPI
    if( (EPHYCFG == 0x06)||(EPHYCFG == 0x08)){
	    if(((AsiaPcieRead8(pciebase, CHX002_PE4|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)&&
			((AsiaPcieRead8(pciebase, CHX002_PE5|((UINT64)(D3D5F1_SLOT_STA_1) << 32)) & D3D5F1_SPDCST)== 0x00)){
	 AsiaPcieModifySave16(pciebase,CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL_Z1 << 32), D0F0_RDISPEXC_X2, D0F0_RDISPEXC_X2);
	    		}
    	}


}

//JNY porting for CHX002-E



//CHX001-CJW-20151014:  Warning!!!
//In CHX001,Register's location of D0F5 had changed,
//but not change the setting now... will update later..
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID 
PowerDownUnusedRP(
    ASIA_NB_CONFIGURATION 	*NbCfg
)
{ 
	UINT64 PciePhyBase = NbCfg->PcieEPHYBar;

 /*//LNA-2016101901 - S   
 	UINT32 PcieFunc;

    //In order to access D4/D5 Configuration Space, need to enable function in D0F5
    PcieFunc = AsiaPciRead32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE);
	PcieFunc |= D0F5_RDV2F0EXST 
			  | D0F5_RDV3F0EXST ;
	//Mike_Debug_S
	//		  | D0F5_RDV3F1EXST 
	//		  | D0F5_RDV3F2EXST 
	//		  | D0F5_RDV3F3EXST 
	//		  | D0F5_RDV4F0EXST 
	//		  | D0F5_RDV4F1EXST 
	//		  | D0F5_RDV5F0EXST 
	//		  | D0F5_RDV5F1EXST; 	//CHX001-CJW-20151026
	//Mike_Debug_E
	AsiaPciWrite32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, PcieFunc);

*/	//LNA-2016101901 - E
 //JNY-20180419 Modify-S
 //D3F0
    if ((!NbCfg->PciePE0)||(!NbCfg->PcieRP)){
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
	        RpAggresivePmMode(NbCfg, CHX002_PE0); 
	    }
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){	
			if(NbCfg->D3F0SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE0); 
		}
	    AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F0EXST, 0);	//D3F0 is disabled
    }
	else{
	    AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F0EXST, D0F5_RDV3F0EXST);	
	}
//D3F1	
    if ((!NbCfg->PciePE1)||(!NbCfg->PcieRP)){
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
			RpAggresivePmMode(NbCfg, CHX002_PE1);
		}
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){		
			if(NbCfg->D3F1SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE1); 
		}
		AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F1EXST, 0);	//D3F1 is disabled	
	}
	else{
		AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F1EXST, D0F5_RDV3F1EXST);		
	}
//D3F2	
    if ((!NbCfg->PciePE2)||(!NbCfg->PcieRP)){ 
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
			RpAggresivePmMode(NbCfg, CHX002_PE2);
		}		
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){	
			if(NbCfg->D3F2SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE2); 
		}
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F2EXST, 0);	//D3F2 is disabled
	}
	else{
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F2EXST, D0F5_RDV3F2EXST);	
	}
//D3F3
    if ((!NbCfg->PciePE3)||(!NbCfg->PcieRP)){ 
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
			RpAggresivePmMode(NbCfg, CHX002_PE3);
		}
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
			
			if(NbCfg->D3F3SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE3); 
		}
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F3EXST, 0);	//D3F3 is disabled 	 
	}
	else{
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV3F3EXST, D0F5_RDV3F3EXST);
	}
//D4F0
    if ((!NbCfg->PciePE4)||(!NbCfg->PcieRP)){ 
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
			RpAggresivePmMode(NbCfg, CHX002_PE4);
		}
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
			
			if(NbCfg->D4F0SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE4); 
		}		
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV4F0EXST, 0); 	//D4F0 is disabled   
	}
	else{
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV4F0EXST, D0F5_RDV4F0EXST);  
	}
//D4F1	
    if ((!NbCfg->PciePE5)||(!NbCfg->PcieRP)){ 
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
			RpAggresivePmMode(NbCfg, CHX002_PE5);
		}
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
			
			if(NbCfg->D4F1SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE5); 
		}
		AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV4F1EXST, 0);	//D4F1 is disabled   
	}
	else{
		AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV4F1EXST, D0F5_RDV4F1EXST);  
		}
//D5F0	
    if ((!NbCfg->PciePE6)||(!NbCfg->PcieRP)){ 
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
		  RpAggresivePmMode(NbCfg, CHX002_PE6);
		}
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
			
			if(NbCfg->D5F0SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE6); 
		}		
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV5F0EXST, 0); 	//D5F0 is disabled		
    }
	else{
		AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV5F0EXST, D0F5_RDV5F0EXST);			
		}
//D5F1	
    if ((!NbCfg->PciePE7)||(!NbCfg->PcieRP)){ 
		if(NbCfg->NBSPEValue > CHIP_SPE_VALUE_STABLE){
			RpAggresivePmMode(NbCfg, CHX002_PE7);
		}
		else if(NbCfg->NBSPEValue == CHIP_SPE_VALUE_MANUAL){
			
			if(NbCfg->D5F1SPEValue > DEVICE_SPE_VALUE_STABLE)
			RpAggresivePmMode(NbCfg, CHX002_PE7); 
		}
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV5F1EXST, 0); 	//D5F1 is disabled  
	}
	else{
		AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV5F1EXST, D0F5_RDV5F1EXST);	
	}
	//JNY-20180419 Modify-E

    //when all RP disable or no PCIE device exist,Set the MPLL gating or off
    //AsiaPciModifySave8(CHX001_NPMC|D0F4_NEW_PMU_FUN_CTL, 0x1F, 0x1A);
    //if just no device exist on PCIE root port, EPHY still works
    
    //JIH-2015091401 Comment out EphyAggresivePmMode in Logic Saving power stage.
    //EphyAggresivePmMode(NbCfg); 
    //JNY add for CHX002 EPHY Used-S
    //PowerDownUnusedEPHY(NbCfg);
	//JNY add for CHX002 EPHY Used-E



	//Power down PEMCU clk ctl if not load FW for PEMCU
	AsiaMemoryModifySave8(PciePhyBase + PCIEPHYCFG_EQ_INT_TO_MCU_Z1 ,
					PCIEPHYCFG_PEMCU_CLOCK_GATING_CTL,
					(NbCfg->PEMCU_LoadFW_WhenBoot)?PCIEPHYCFG_PEMCU_CLOCK_GATING_CTL:0);

	
}


#define PARAM_OFFSET  0x1000

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
PciePemcuSetParam(ASIA_NB_CONFIGURATION *NbCfg)
{
	UINT64 EphyBaseAddr = NbCfg->PcieEPHYBar;
	UINT64 PemcuDsramBase;

	if(NbCfg->PEMCU_LoadFW_WhenBoot != 1){
		return EFI_SUCCESS;
	}

	
	//Get PEMCU DATA SRAM base address
	PemcuDsramBase = (UINT64)AsiaMemoryRead32(EphyBaseAddr+PCIEPHYCFG_BASE_ADR_OF_PEMCU_FW_FOR_DATA_SPACE);
	PemcuDsramBase = PemcuDsramBase<<16;//LShiftU64(PemcuDsramBase,16);

	//set the EQ Phase3 EM scan time for PEMCU FW 
	//AsiaMemoryWriteSave8(PemcuDsramBase+PARAM_OFFSET,NbCfg->PcieEMEQScanTime);
	//DEBUG((EFI_D_ERROR, "[PCIE] PEMCU DSRAM base = 0x%08x\n",PemcuDsramBase));



	return EFI_SUCCESS;
}


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
EFI_STATUS
PciePrePciInit(
	ASIA_NB_CONFIGURATION *NbCfg)
{


     //JIH-2015091401 Enable PCIE Logic AggresivePmMode.
    PcieRpControl(NbCfg);

	PCIE_DXE_80_PORT(DXE_NB_PCIE_AGGRESSIVE_PM );   //add by jenny 20170413
	
    BeforePciSetPcie(NbCfg);

     //JIH-2015091401 Enable PCIE Logic AggresivePmMode.
	PowerDownUnusedRP(NbCfg);

	PciePemcuSetParam(NbCfg);
	
	PCIE_DXE_80_PORT(DXE_NB_PCIE_POWER_CTL);   //add by jenny 20170413


	return  EFI_SUCCESS;
}



