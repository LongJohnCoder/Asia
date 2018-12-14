//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
//Ver	Date				Note
//----------------------------------------------------------------------------

#include "Pei.h"
#include "Draminit.h"
#include "SIDRAMTbl.h"
#include "DramUtil.h"
#include "SIValueProgramming.h"
#include "IOTimingControl.h"
#include "VrefCalibration.h"









EFI_STATUS SIValueProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8	FreqIdx;
	UINT16  Registertemp;
    UINT64  Address;


	//save DRAM SI version to D0F6Rx45   
	AsiaPciWrite8( CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_2+1), SIDRAM_VER);

	switch (DramAttr->DramFreq) {
		case DRAM_FREQ_1600: 
			FreqIdx = SI_DRAM_FREQ_1600; 
			break;
		case DRAM_FREQ_2133: 
			FreqIdx = SI_DRAM_FREQ_2133; 
			break;
		case DRAM_FREQ_2400:
			FreqIdx = SI_DRAM_FREQ_2400; 
			break;
		case DRAM_FREQ_2666:
			FreqIdx = SI_DRAM_FREQ_2666; 
			break;
		case DRAM_FREQ_2933:
			FreqIdx = SI_DRAM_FREQ_2933; 
			break;
		case DRAM_FREQ_3200:
			FreqIdx = SI_DRAM_FREQ_3200; 
			break;
		default:			
			FreqIdx = SI_DRAM_FREQ_1600; 
			break;
	}

	ODTProgramming(PeiServices, FreqIdx, DramAttr);
	BasicIOTimingProgramming(PeiServices, FreqIdx, DramAttr);
	DrivingProgramming(PeiServices, FreqIdx, DramAttr);
	DrivingSelectionProgramming(PeiServices, FreqIdx, DramAttr);
	ClkPhaseProgramming(PeiServices, FreqIdx, DramAttr);
	ClkDutyProgramming(PeiServices, FreqIdx, DramAttr);
	EQPCtrlProgramming(PeiServices, FreqIdx, DramAttr);
	RxEqProgramming(PeiServices, FreqIdx, DramAttr);
	VrefProgramming(PeiServices, FreqIdx, DramAttr);
	//daisy add for set rxvrefrangeselect register only for SI rxvrefvalue
	SetVrefRange(PeiServices,pPCIPPI,DramAttr);
	DdrPhyProgramming(PeiServices, FreqIdx, DramAttr);
	VcdlOutputClkProgramming(PeiServices, FreqIdx, DramAttr);

       //daisy patch RX PerBit Delay depend on DramFreq
       switch (DramAttr->DramFreq){
       case DRAM_FREQ_1600: 
       case DRAM_FREQ_2133: 
       case DRAM_FREQ_2400:
       case DRAM_FREQ_2666:
       case DRAM_FREQ_2933:
           for(Registertemp = D0F3_RX_PER_BIT_DELAY_A0_BIT_0_1_2_3_CHN_A;Registertemp<=D0F3_RX_PER_BIT_DELAY_B8_BIT_4_5_6_7_CHN_B;Registertemp+=2)
           {                           
                  Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,Registertemp);
       
                  AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPH_A0_DQ0_2_0|D0F3_RPH_A0_DQ1_2_0|D0F3_RPH_A0_DQ2_2_0|D0F3_RPH_A0_DQ3_2_0, 0x3333);
           }
           break;
       case DRAM_FREQ_3200:
              for(Registertemp = D0F3_RX_PER_BIT_DELAY_A0_BIT_0_1_2_3_CHN_A;Registertemp<=D0F3_RX_PER_BIT_DELAY_B8_BIT_4_5_6_7_CHN_B;Registertemp+=2)
           {                           
                  Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,Registertemp);
       
                  AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPH_A0_DQ0_2_0|D0F3_RPH_A0_DQ1_2_0|D0F3_RPH_A0_DQ2_2_0|D0F3_RPH_A0_DQ3_2_0, 0x4444);
           }
           break;
       }



#ifdef RXVREF_DDR3MODE
{
	UINT64 Address;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "NOTE: Rxvref USE DDR3 MODE\r\n"));
	
	//CHA
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_A0_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DDRMODE_1_0_A, 0x0000);

	//CHB
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BDDDRDQ_CTL_REG_B0_CHN_B);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_DDRMODE_1_0_B, 0x0000);


    //VREF External mode
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,	D0F3_BDDDRDQ_CTL_REG_A0_CHN_A_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_SEL_A, 0);

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,	D0F3_BDDDRDQ_CTL_REG_B0_CHN_B_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_VREF_SEL_B, 0);
}
#endif

	return EFI_SUCCESS;
}

VOID ODTProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;

	for (RegIdx = 0; RegIdx < OdtSiTblItems; RegIdx++){		
		switch (OdtSiTbl[RegIdx].Attribute) {
			
			case NORMAL:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				break;

			case ChA_Setting|R1xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R1xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;

			case ChA_Setting|R2xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R2xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;

			case ChB_Setting|R1xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R1xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;

			case ChB_Setting|R2xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R2xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &OdtSiTbl[RegIdx]);
				}
				break;

			default:			
				break;
		}		
	}
}


VOID BasicIOTimingProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
	UINT64  Address;

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MDQS_OUTPUT_CTL_MD_MDQS_OUTPUT_TIMING_CTL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDSOLNGPRE_1_0, 0x0300);

	for (RegIdx=0; RegIdx < BasicIOTimingTblItems; RegIdx++){
		switch (BasicIOTimingTbl[RegIdx].Attribute) {
			case NORMAL:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &BasicIOTimingTbl[RegIdx]);
				break;
			case NORMAL|RDIMM:
				if (DramAttr->RegDimm  == IS_REG_DIMM)
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &BasicIOTimingTbl[RegIdx]);
				break;
				
			default:			
				break;
		}
	}

}

VOID DrivingProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;

	for (RegIdx = 0; RegIdx < DrivingTblItems; RegIdx++){		
		switch (DrivingTbl[RegIdx].Attribute) {	
			
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				break;
								
			case ChA_Setting|R1xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R1xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;

			case ChA_Setting|R2xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R2xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;

			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				break;

			case ChB_Setting|R1xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R1xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;

			case ChB_Setting|R2xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R2xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingTbl[RegIdx]);
				}
				break;

			default:			
				break;
		}		
	}

}

VOID DrivingSelectionProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
	
	for (RegIdx = 0; RegIdx < DrivingSelectionTblItems; RegIdx++){		
		switch (DrivingSelectionTbl[RegIdx].Attribute) {
			
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				break;
				
			case ChA_Setting|R1xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R1xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;

			case ChA_Setting|R2xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R2xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;
					
			case ChB_Setting:
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
					break;

			case ChB_Setting|R1xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R1xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;

			case ChB_Setting|R2xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R2xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DrivingSelectionTbl[RegIdx]);
				}
				break;

			default:			
				break;
		}		
	}

}


VOID ClkPhaseProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;

	for (RegIdx=0; RegIdx < ClkPhaseTblItems; RegIdx++){
		switch (ClkPhaseTbl[RegIdx].Attribute) {
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &ClkPhaseTbl[RegIdx]);
				break;
				
			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &ClkPhaseTbl[RegIdx]);
				break;
				
			default:			
				break;
		}
	}

}

VOID ClkDutyProgramming(
		IN EFI_PEI_SERVICES **PeiServices,
		IN UINT8 FreqIdx,
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
	
	for (RegIdx=0; RegIdx < ClkDutyTblItems; RegIdx++){
		switch (ClkDutyTbl[RegIdx].Attribute) {
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &ClkDutyTbl[RegIdx]);
				break;
				
			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &ClkDutyTbl[RegIdx]);
				break;
					
			default:			
				break;
		}
	}
	
}



VOID EQPCtrlProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)

{
	UINT16	RegIdx;
	
	for (RegIdx=0; RegIdx < EQPCtrlTblItems; RegIdx++){
		switch (EQPCtrlTbl[RegIdx].Attribute) {
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &EQPCtrlTbl[RegIdx]);
				break;
				
			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &EQPCtrlTbl[RegIdx]);
				break;
					
			default:			
				break;
		}
	}
	
}


VOID RxEqProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
	
	for (RegIdx=0; RegIdx < RxEqTblItems; RegIdx++){
		switch (RxEqTbl[RegIdx].Attribute) {
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &RxEqTbl[RegIdx]);
				break;
				
			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &RxEqTbl[RegIdx]);
				break;
					
			default:			
				break;
		}
	}
	
}

VOID VrefProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
	
	for (RegIdx = 0; RegIdx < VrefTblItems; RegIdx++){	
		switch (VrefTbl[RegIdx].Attribute) {
			
			case ChA_Setting|R1xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R1xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;

			case ChA_Setting|R2xD1:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;
				
			case ChA_Setting|R2xD2:
				if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChARankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;

			case ChB_Setting|R1xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R1xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;

			case ChB_Setting|R2xD1:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;
				
			case ChB_Setting|R2xD2:
				if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					(DramAttr->ChBRankNumber[DramAttr->AttrNo] == 4)){
					ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VrefTbl[RegIdx]);
				}
				break;

			default:			
				break;
		}		
	}

}

VOID DdrPhyProgramming(
		IN EFI_PEI_SERVICES **PeiServices,
		IN UINT8 FreqIdx,
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
		
	for (RegIdx=0; RegIdx < DdrPhyTblItems; RegIdx++){
		switch (DdrPhyTbl[RegIdx].Attribute) {
			
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DdrPhyTbl[RegIdx]);
				break;
				
			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &DdrPhyTbl[RegIdx]);
				break;
						
			default:			
				break;
		}
	}
		
}

VOID VcdlOutputClkProgramming(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8 FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT16	RegIdx;
			
	for (RegIdx=0; RegIdx < VcdlOutputClkTblItems; RegIdx++){
		switch (VcdlOutputClkTbl[RegIdx].Attribute) {
			case ChA_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VcdlOutputClkTbl[RegIdx]);
				break;
				
			case ChB_Setting:
				ProgramDramcRegister(PeiServices, FreqIdx, DramAttr, &VcdlOutputClkTbl[RegIdx]);
				break;
							
			default:			
				break;
		}
	}
			
}

VOID ProgramDramcRegister(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8              FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr,
    IN SI_DRAMC_REGISTER_SETTING    *Item
    )
{
	UINT64   Address;
	UINT16    Data;

	Data =  ShiftToMaskBit(Item->Mask, (UINT16)Item->RegVal[FreqIdx]);//use UINT16 ShiftToMaskBit()
	
	if(Item->Register <= 0xFF){
		Address = CHX002_DRAM | Item->Register;
		AsiaPciModify16(Address, Item->Mask, Data);
		return;
	}
	else{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, Item->Register);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, Item->Mask, Data);
		return;
	}
}

VOID SetDramcRegister(
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8              FreqIdx,
    IN DRAM_ATTRIBUTE *DramAttr,
    IN SI_DRAMC_REGISTER_SETTING   *Item
    )
{
	UINT64   Address;
	UINT16   Data;
	UINT16   Registertemp;


	Data =  ShiftToMaskBit(Item->Mask, (UINT16)Item->RegVal[FreqIdx]);//use UINT16 ShiftToMaskBit()

	for(Registertemp = Item->Register;Registertemp <= Item->Register + 0x0F;Registertemp++)
	{
		if(Registertemp <= 0xFF){
			Address = CHX002_DRAM | Registertemp;
			AsiaPciModify16(Address, Item->Mask, Data);
		}
		else{
		
				Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,Registertemp);
				AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, Item->Mask, Data);		
			}

	
	}
	return;

}

UINT8 FreqIdxInTable(	
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr)
{
  UINT8 FreqIdx = 0;

  switch (DramAttr->DramFreq) {
    case DRAM_FREQ_1600: 	FreqIdx = SI_DRAM_FREQ_1600;		break;
	case DRAM_FREQ_2133: 	FreqIdx = SI_DRAM_FREQ_2133;		break;
    case DRAM_FREQ_2400: 	FreqIdx = SI_DRAM_FREQ_2400;		break;
    case DRAM_FREQ_2666: 	FreqIdx = SI_DRAM_FREQ_2666;		break;
	case DRAM_FREQ_2933: 	FreqIdx = SI_DRAM_FREQ_2933;		break;
    case DRAM_FREQ_3200: 	FreqIdx = SI_DRAM_FREQ_3200;		break;

    default:				FreqIdx = SI_DRAM_FREQ_1600; 		break;
  }

  return FreqIdx;
}


VOID SI_DQSI(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr,
    IN SI_DRAMC_REGISTER_SETTING ReadTimingTbl[],
    IN UINT32 ReadTimingTblItems)

{
  UINT16 	RegIdx;
  UINT8	FreqIdx;

  PEI_DEBUG((PeiServices, EFI_D_INFO, "SI RX DQSI\r\n"));

  FreqIdx = FreqIdxInTable(PeiServices, pPCIPPI, DramAttr);


  for (RegIdx=0; RegIdx< ReadTimingTblItems; RegIdx++)
  {
    switch (ReadTimingTbl[RegIdx].Attribute)
    {
    	case ChA_Setting|DIMM_1|DQSI|RAWCARD_A:
        	if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
           	 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        	{
         		SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        	}
        break;	


      	case ChA_Setting|DIMM_1|DQSI|RAWCARD_B:
       	 	if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
           	 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        	{
         	 	SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        	}
        break;


      	case ChA_Setting|DIMM_1|DQSI|RAWCARD_C:
        	if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
           	 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        	{
          		SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        	}
        break;

	   case ChA_Setting|DIMM_1|DQSI|RAWCARD_UD:
       	   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
        	{
          		SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        	}
       break;
		
	   case ChA_Setting|DIMM_1|DQSI|RAWCARD_RD:
		   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
			  ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		  	{
				SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  	}
	  break;
		  
	  case ChA_Setting|DIMM_1|DQSI|RAWCARD_UE:
          if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
        	{
          		SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        	}
      break;
		
	  case ChA_Setting|DIMM_1|DQSI|RAWCARD_RE:
		  if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
			  ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
		  break;

      case ChA_Setting|DIMM_2|DQSI|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;	

	
      case ChA_Setting|DIMM_2|DQSI|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;


      case ChA_Setting|DIMM_2|DQSI|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;
		
		case ChA_Setting|DIMM_2|DQSI|RAWCARD_UD:
		  if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
			  ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
		break;
		
		

		  
		 case ChA_Setting|DIMM_2|DQSI|RAWCARD_RD:
			if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				 (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				 (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			{
			  SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			}
		break;
			
		case ChA_Setting|DIMM_2|DQSI|RAWCARD_UE:
		  if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
			  ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
			   (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
		break;
		  
		case ChA_Setting|DIMM_2|DQSI|RAWCARD_RE:
			if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				 (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				 (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			{
			  SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			}
		break;


      case ChB_Setting|DIMM_1|DQSI|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }

        break;	


      case ChB_Setting|DIMM_1|DQSI|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }

        break;


      case ChB_Setting|DIMM_1|DQSI|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

		case ChB_Setting|DIMM_1|DQSI|RAWCARD_UD:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;


		 case ChB_Setting|DIMM_1|DQSI|RAWCARD_RD:
		  if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
			  ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
		  break;
	
      case ChB_Setting|DIMM_1|DQSI|RAWCARD_UE:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;
			
		
		case ChB_Setting|DIMM_1|DQSI|RAWCARD_RE:
		  if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
			  ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
		  break;
	 
      case ChB_Setting|DIMM_2|DQSI|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;	

	
      case ChB_Setting|DIMM_2|DQSI|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;


      case ChB_Setting|DIMM_2|DQSI|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

	  case ChB_Setting|DIMM_2|DQSI|RAWCARD_UD:
		  if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
			  ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
	 break;		
		  
	  case ChB_Setting|DIMM_2|DQSI|RAWCARD_RD:
			if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				 (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				 (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			{
			  SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			}
		break;
		
		case ChB_Setting|DIMM_2|DQSI|RAWCARD_UE:
		  if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
			  ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
			   (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		  {
			SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		  }
		  break;		  
		  
		case ChB_Setting|DIMM_2|DQSI|RAWCARD_RE:
			if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				 (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				 (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			{
			  SetDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			}
		break;

      default:			
        break;
    }
  }

  //trigger Load Register 		
  TriggerLoadReg(PeiServices, DramAttr);
}

VOID SI_TNI(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr,
    IN SI_DRAMC_REGISTER_SETTING ReadTimingTbl[],
    IN UINT32 ReadTimingTblItems)
{
  UINT16 	   RegIdx;
  UINT8	FreqIdx;

  PEI_DEBUG((PeiServices, EFI_D_INFO, "SI RX TNI\r\n"));
  FreqIdx = FreqIdxInTable(PeiServices, pPCIPPI, DramAttr);
  
  for (RegIdx=0; RegIdx< ReadTimingTblItems; RegIdx++)
  {
    switch (ReadTimingTbl[RegIdx].Attribute)
    {
      case ChA_Setting|DIMM_1|TNI|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;	

      case ChA_Setting|DIMM_1|TNI|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

      case ChA_Setting|DIMM_1|TNI|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

	  case ChA_Setting|DIMM_1|TNI|RAWCARD_UD:
		   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
			   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		   {
			 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		   }
	  break;	 
		   
	   case ChA_Setting|DIMM_1|TNI|RAWCARD_RD:
			 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
				 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		 break;
		 
		 case ChA_Setting|DIMM_1|TNI|RAWCARD_UE:
		   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
			   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		   {
			 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		   }
		   break;		   
		   
		 case ChA_Setting|DIMM_1|TNI|RAWCARD_RE:
			 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
				 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		 break;

		
      case ChA_Setting|DIMM_2|TNI|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;	
	
      case ChA_Setting|DIMM_2|TNI|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

      case ChA_Setting|DIMM_2|TNI|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

	  case ChA_Setting|DIMM_2|TNI|RAWCARD_UD:
		   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
			   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		   {
			 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		   }
	  break;	 
		   
	   case ChA_Setting|DIMM_2|TNI|RAWCARD_RD:
			 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		 break;
		 
		 case ChA_Setting|DIMM_2|TNI|RAWCARD_UE:
		   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
			   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		   {
			 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		   }
		   break;		   
		   
		 case ChA_Setting|DIMM_2|TNI|RAWCARD_RE:
			 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		 break;



      case ChB_Setting|DIMM_1|TNI|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;	


      case ChB_Setting|DIMM_1|TNI|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;


      case ChB_Setting|DIMM_1|TNI|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

	  case ChB_Setting|DIMM_1|TNI|RAWCARD_UD:
		   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
			   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
		   {
			 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		   }
	  break;	 
		   
	   case ChB_Setting|DIMM_1|TNI|RAWCARD_RD:
			 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
				 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		 break;
		 
		 case ChB_Setting|DIMM_1|TNI|RAWCARD_UE:
		   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
			   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
		   {
			 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
		   }
		   break;		   
		   
		 case ChB_Setting|DIMM_1|TNI|RAWCARD_RE:
			 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
				 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		 break;



      case ChB_Setting|DIMM_2|TNI|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;	

	
      case ChB_Setting|DIMM_2|TNI|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;

  
      case ChB_Setting|DIMM_2|TNI|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
        }
        break;
		
		case ChB_Setting|DIMM_2|TNI|RAWCARD_UD:
			 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
		break;	   
			 
		 case ChB_Setting|DIMM_2|TNI|RAWCARD_RD:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			   }
		   break;
		   
		   case ChB_Setting|DIMM_2|TNI|RAWCARD_UE:
			 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
				  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			 {
			   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			 }
			 break; 		 
			 
		   case ChB_Setting|DIMM_2|TNI|RAWCARD_RE:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &ReadTimingTbl[RegIdx]);
			   }
		   break;

      default:			
        break;
    }
  }

  //trigger Load Register 	
	//trigger Load Register 	  
	TriggerLoadReg(PeiServices, DramAttr);
	return;
 }

VOID SI_DQSO(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN SI_DRAMC_REGISTER_SETTING OutputTimingTbl[],
  IN UINT32 OutputTimingTblItems)
{
  UINT16 	RegIdx;
  UINT8	FreqIdx;


  PEI_DEBUG((PeiServices, EFI_D_INFO, "SI TX DQSO\r\n"));

  FreqIdx = FreqIdxInTable(PeiServices, pPCIPPI, DramAttr);
  
  for (RegIdx = 0; RegIdx < OutputTimingTblItems; RegIdx++) { 
    switch (OutputTimingTbl[RegIdx].Attribute)
    {

      case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	


      case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;


      case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_UD:
			   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
				   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		break;	 
			   
		case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_RD:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_UE:
			   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
				   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChA_Setting|DIMM_1|TX_DQS|RAWCARD_RE:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;


      case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	
	
      case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;


      case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_UD:
			   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		  break;	 
			   
		   case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_RD:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_UE:
			   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChA_Setting|DIMM_2|TX_DQS|RAWCARD_RE:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;


      case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	

      case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

      case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_UD:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		  break;	 
			   
		   case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_RD:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_UE:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChB_Setting|DIMM_1|TX_DQS|RAWCARD_RE:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;


      case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	
	
      case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;
		
      case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_UD:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		  break;	 
			   
		   case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_RD:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_UE:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChB_Setting|DIMM_2|TX_DQS|RAWCARD_RE:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;


      default:			
        break;
    }
  } 

  //trigger Load Register 		
  TriggerLoadReg(PeiServices, DramAttr);
}

VOID SI_DQO(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN SI_DRAMC_REGISTER_SETTING OutputTimingTbl[],
  IN UINT32 OutputTimingTblItems)
{
  UINT16 	  RegIdx;
  UINT8	  FreqIdx;

  PEI_DEBUG((PeiServices, EFI_D_INFO, "SI TX DQO\r\n"));
  FreqIdx = FreqIdxInTable(PeiServices, pPCIPPI, DramAttr);


  for (RegIdx = 0; RegIdx < OutputTimingTblItems; RegIdx++)
  {            
    switch (OutputTimingTbl[RegIdx].Attribute)
    {
      case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	

      case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

      case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

		case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_UD:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
		  break;   
				 
		  case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_RD:
				   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
						(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
						(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				   {
					 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				   }
			   break;
			   
			   case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_UE:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
				 break; 		 
				 
			   case ChA_Setting|DIMM_1|TX_DQ|RAWCARD_RE:
				   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
					   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
						(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
						(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				   {
					 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				   }
			   break;

      case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_A:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	
	
      case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_B:	
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

      case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_C:
        if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_UD:
			   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		break;	 
			   
		case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_RD:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_UE:
			   if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChA_Setting|DIMM_2|TX_DQ|RAWCARD_RE:
				 if ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChARawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;

      case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	

      case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

      case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_UD:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		break;	 
			   
		case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_RD:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_UE:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChB_Setting|DIMM_1|TX_DQ|RAWCARD_RE:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;

      case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_A:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OA) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_AA)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;	
	
      case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_B:	
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OB) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BO) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_BB)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

      case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_C:
        if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
            ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OC) || 
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CO) ||
             (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_CC)))
        {
          ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
        }
        break;

	  case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_UD:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
		break;	 
			   
		case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_RD:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OD) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_DD)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;
			 
			 case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_UE:
			   if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
				   ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					(DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
			   {
				 ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
			   }
			   break;		   
			   
			 case ChB_Setting|DIMM_2|TX_DQ|RAWCARD_RE:
				 if ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
					 ((DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_OE) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EO) ||
					  (DramAttr->ChBRawCardType[DramAttr->AttrNo] == RAW_CARD_EE)))
				 {
				   ProgramDramcRegister( PeiServices, FreqIdx, DramAttr, &OutputTimingTbl[RegIdx]);
				 }
			 break;

      default:			
        break;
    }
  } 
	
  TriggerLoadReg(PeiServices, DramAttr);
  
}



//***********************daisy add for setting SI iotiming -E***************************//
//SI advice value
SI_DRAMC_REGISTER_SETTING TxVrefManualtbl[] =
{
//Refer to DDR4 spec, Table 15 - VrefDQ Training: Values
//e.g. 0x02 = 00 0010b = 61.30% (for range 1)
//Attribute                               Register BitMask  3200 2933 2666    2400  2133   1600
{ChA_Setting|R1xD1,                       0xFFF,        0xFF,    0x0A,    0x0, 0x0D,    0x0A,    0x0E,    0x0A},
{ChA_Setting|R2xD1,                       0xFFF,        0xFF,    0x18,    0x0, 0x17,    0x16,    0x16,    0x16},
{ChA_Setting|R1xD2,                       0xFFF,        0xFF,    0x1C,    0x0, 0x1C,    0x1E,    0x20,    0x20},
{ChA_Setting|R2xD2,                       0xFFF,        0xFF,    0x26,    0x0, 0x25,    0x28,    0x26,    0x22},

{ChB_Setting|R1xD1,                       0xFFF,        0xFF,    0x0A,    0x0, 0x0D,    0x0A,    0x0E,    0x0A},
{ChB_Setting|R2xD1,                       0xFFF,        0xFF,    0x18,    0x0, 0x17,    0x16,    0x16,    0x16},
{ChB_Setting|R1xD2,                       0xFFF,        0xFF,    0x1C,    0x0, 0x1C,    0x1E,    0x20,    0x20},
{ChB_Setting|R2xD2,                       0xFFF,        0xFF,    0x26,    0x0, 0x25,    0x28,    0x26,    0x22},
};

UINT32 TxVrefManualtblItems = sizeof(TxVrefManualtbl)/sizeof(SI_DRAMC_REGISTER_SETTING);


VOID Tx_Manual_Vref(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr)  
{
  UINT8	RankIndex, FreqIdx, TxVrefCHASelected=0, TxVrefCHBSelected=0;
  UINT16	RegIdx;
  UINT8 Index = 0;
  //PEI_DEBUG((PeiServices, EFI_D_INFO, "SI TXVREF \r\n"));
  FreqIdx = FreqIdxInTable(PeiServices, pPCIPPI, DramAttr);


  for (RegIdx = 0; RegIdx < TxVrefManualtblItems; RegIdx++){		
    switch (TxVrefManualtbl[RegIdx].Attribute) {
      case ChA_Setting|R1xD1:
        if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
          (DramAttr->ChARankNumber[DramAttr->AttrNo] == 1)){
          TxVrefCHASelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;
        
      case ChA_Setting|R1xD2:
        if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
          (DramAttr->ChARankNumber[DramAttr->AttrNo]== 2)){
          TxVrefCHASelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;

      case ChA_Setting|R2xD1:
        if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 1) &&
          (DramAttr->ChARankNumber[DramAttr->AttrNo] == 2)){
          TxVrefCHASelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;
        
      case ChA_Setting|R2xD2:
        if  ((DramAttr->ChADIMMNumber[DramAttr->AttrNo] == 2) &&
          (DramAttr->ChARankNumber[DramAttr->AttrNo] == 4)){
          TxVrefCHASelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;
      
      case ChB_Setting|R1xD1:
        if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 1) &&
          (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 1)){
          TxVrefCHBSelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;
        
      case ChB_Setting|R1xD2:
        if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo]== 2) &&
          (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
          TxVrefCHBSelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;

      case ChB_Setting|R2xD1:
        if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo]== 1) &&
          (DramAttr->ChBRankNumber[DramAttr->AttrNo] == 2)){
          TxVrefCHBSelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;
        
      case ChB_Setting|R2xD2:
        if  ((DramAttr->ChBDIMMNumber[DramAttr->AttrNo] == 2) &&
          (DramAttr->ChBRankNumber [DramAttr->AttrNo]== 4)){
          TxVrefCHBSelected = TxVrefManualtbl[RegIdx].RegVal[FreqIdx];	
        }
        break;
      default:			
        break;
    }		
  }
  PEI_DEBUG((PeiServices, EFI_D_INFO, "Daisy-debug:TxVref for CHA=%2x\r\n", TxVrefCHASelected));	
  PEI_DEBUG((PeiServices, EFI_D_INFO, "Daisy-debug:TxVref for CHB=%2x\r\n", TxVrefCHBSelected));	
  for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
  {
    if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
    {	
      if(RankIndex<4){
        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefCHASelected);
        for (Index = 0; Index < 74; Index++)
        {
            if (TxVrefTable[Index] == TxVrefCHASelected)
                break;
        }
        DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = Index;
      }

      else{
        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefCHBSelected);
        for (Index = 0; Index < 74; Index++)
        {
            if (TxVrefTable[Index] == TxVrefCHBSelected)
                break;
        }
        DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = Index;       
      }
    }
  }
}


void Setup_SetTxVref(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr)
{
  UINT8 Temp;
  UINT8 TxVrefStep = 13;
  UINT8 RankIndex=0;
	UINT8 Index;
  
  PEI_DEBUG((PeiServices, EFI_D_INFO, "Daisy-debug:TX VREF=%0d\r\n",DramAttr->ConfigData.TxVref));
  for(RankIndex=0; RankIndex<ASIA_MAX_RANKS; RankIndex++) 
  {
    if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIndex)) 
    {					
      if(DramAttr->ConfigData.TxVref > 600)//range1
      {
        Temp=(UINT8)((DramAttr->ConfigData.TxVref - 600)/TxVrefStep *2);
        PEI_DEBUG((PeiServices, EFI_D_INFO, "Daisy-debug:SetTxvref Range=%0d,SetTxvref Value=%d\r\n",VREF_RANGE1/2,Temp));
        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex,VREF_RANGE1, Temp);
        for (Index = 0; Index < 74; Index++)
        {
            if (TxVrefTable[Index] == Temp)
                break;
        }
        DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = Index;  
      }
      else
      {
        Temp=0x16 - (UINT8)((593 - DramAttr->ConfigData.TxVref)/TxVrefStep*2);
        PEI_DEBUG((PeiServices, EFI_D_INFO, "Daisy-debug:SetTxvref Range=%0d,SetTxvref Value=%d\r\n",VREF_RANGE2/2,Temp));				
        SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex,VREF_RANGE2, Temp);
        for (Index = 0; Index < 74; Index++)
        {
            if (TxVrefTable[Index] == Temp)
                break;
        }
        DramAttr->TxVrefInfo[RankIndex].TxVrefCENTER = Index;  
      }
    }
  }
}



