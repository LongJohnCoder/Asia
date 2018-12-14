//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "Draminit.h"
#include "spd.h"
#include "DRAMTimingProgramming.h"





//The minimum CL-RP-RCD values vary with dram working frequency according to DDR4 spec. 
//Add code to change CL-RP-RCD values when these values are smaller than allowed lower bound.
UINT16 CheckMinClRpRcdValue(IN EFI_PEI_SERVICES * * PeiServices, 
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI * pPCIPPI, 
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE * DramAttr,
		IN UINT16 ClRpRcdFromSpd)
{
	UINT16 minClRpRcd=0;

	switch(DramAttr->DramFreq){
		
		case DRAM_FREQ_3200:
			minClRpRcd=(ClRpRcdFromSpd>=22)?ClRpRcdFromSpd:22;
			break;
		case DRAM_FREQ_2933:
			minClRpRcd=(ClRpRcdFromSpd>=21)?ClRpRcdFromSpd:21;
			break; 
		case DRAM_FREQ_2666:
			minClRpRcd=(ClRpRcdFromSpd>=19)?ClRpRcdFromSpd:19;
			break; 			
		case DRAM_FREQ_2400:
			minClRpRcd=(ClRpRcdFromSpd>=17)?ClRpRcdFromSpd:17;
			break; 
		case DRAM_FREQ_2133:
			minClRpRcd=(ClRpRcdFromSpd>=15)?ClRpRcdFromSpd:15;
			break;
		case DRAM_FREQ_1866:
			minClRpRcd=(ClRpRcdFromSpd>=13)?ClRpRcdFromSpd:13;
			break; 
		case DRAM_FREQ_1600:
			minClRpRcd=(ClRpRcdFromSpd>=11)?ClRpRcdFromSpd:11;
			break;
		case DRAM_FREQ_1333:
			minClRpRcd=(ClRpRcdFromSpd>=8)?ClRpRcdFromSpd:8;
			break;
		case DRAM_FREQ_1066:
			minClRpRcd=(ClRpRcdFromSpd>=7)?ClRpRcdFromSpd:7;
			break;
		case DRAM_FREQ_800:
			minClRpRcd=(ClRpRcdFromSpd>=6)?ClRpRcdFromSpd:6;
			break;
		default:
			minClRpRcd=(ClRpRcdFromSpd>=6)?ClRpRcdFromSpd:6;
			break;
	}
	return minClRpRcd;
}

EFI_STATUS DRAMTimingProgramming(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	//DRAM Timing for all Ranks  
	DRAMTimingStab(PeiServices, pPCIPPI, DramAttr);//add for RDIMM
	DRAMTimingCL(PeiServices, pPCIPPI, DramAttr);   
	DRAMTimingTrp(PeiServices, pPCIPPI, DramAttr);	
	DRAMTimingTrcd(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingTras(PeiServices, pPCIPPI, DramAttr); 
	DRAMTimingTrfc(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingTrrd(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingTwr(PeiServices, pPCIPPI, DramAttr);  
	DRAMTimingTwtr(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingTrtp(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingCWL(PeiServices, pPCIPPI, DramAttr);  
	DRAMTimingTfawx(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingTcke(PeiServices, pPCIPPI, DramAttr);  
	DRAMTimingTxp(PeiServices, pPCIPPI, DramAttr);   

	DRAMTimingRTXSREXT(PeiServices, pPCIPPI, DramAttr);  
	DRAMTimingTrrd_SG(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingTccd_SG(PeiServices, pPCIPPI, DramAttr);   
	DRAMTimingTwtr_SG(PeiServices, pPCIPPI, DramAttr);   
	DRAMTimingCAL(PeiServices, pPCIPPI, DramAttr);       	
	DRAMTimingPreamble(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingODT(PeiServices, pPCIPPI, DramAttr);

	DRAMTimingBankInterleave(PeiServices, pPCIPPI, DramAttr);
	DRAMTimingBurstLength(PeiServices, pPCIPPI, DramAttr);

	DRAMTimingTurnAround(PeiServices, pPCIPPI, DramAttr);

	DRAMTimingDynamicclock(PeiServices, pPCIPPI, DramAttr);
	
	return EFI_SUCCESS;
}

#define DDR4_MIN_Stab 16//DYS
VOID DRAMTimingStab(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN OUT DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16 Tmp=0;
	UINT16 Stab;//keep stable 5us
	if(DramAttr->RegDimm == IS_REG_DIMM)
	{
		switch(DramAttr->DramFreq){           
        case DRAM_FREQ_1600: 
        	Tmp=0x10;     
        break;
        case DRAM_FREQ_1866:
        	Tmp=0x13;    
        	break;
        case DRAM_FREQ_2133:
        	Tmp=0x15;   
        	break;
        case DRAM_FREQ_2400:
        	Tmp=0x18;    
        	break;
        case DRAM_FREQ_2666:
        	Tmp=0x1A;       
        	break;
        case DRAM_FREQ_2933:
        	Tmp=0x1D;      
        	break;
        case DRAM_FREQ_3200:
        	Tmp=0x20;     
        	break;
        default:
        	Tmp=0x10;   
        	break;
        }


		Stab = 16+Tmp*128;
		if(Stab < DDR4_MIN_Stab){
			 ACTimingError(PeiServices,MIN_ERROR,Stab,DDR4_MIN_Stab,"Tstab");
			Stab = DDR4_MIN_Stab;
			}	
	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Stab = %d\n",(UINT16)Stab));  

		//D0F3Rx1C7[7:0]
		Tmp <<= 8;
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIMM_STAB_7_0, Tmp);
		return;
	}
	else
	{
		return;
	}

}


#define DDR4_MAX_CL 32
#define DDR4_MIN_CL 9
#define DDR4_CL_GAP 9
#define DDR4_CL_MASK 0x40000000
VOID DRAMTimingCL(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)

{ 
	UINT32 CLSupported=0, Mask=0;
	UINT16 Tmp=0;
	UINT64 Address;
	UINT8  Index;
	INT8   FineOffset = 0;
	ASIA_SPD_DATA  *CurrentSpdData;
	//BOOLEAN DimmsAreManuByAdata=TRUE;	

	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){

		//DDR4
		for (Index = 0; Index < ASIA_MAX_DIMMS; Index++){
			CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
			if (CurrentSpdData->SpdPresent) {	
				//Get common supported CL
				if (CLSupported == 0)
					CLSupported = ((CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_FOURTH_BYTE] << 24)|(CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_THIRD_BYTE] << 16)
							|(CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_SECOND_BYTE] << 8)|(CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_FIRST_BYTE]));
				else
					CLSupported = CLSupported & ((CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_FOURTH_BYTE] << 24)|(CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_THIRD_BYTE] << 16)
							|(CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_SECOND_BYTE] << 8)|(CurrentSpdData->Buffer[DDR4_SPD_SUPPORTED_CL_FIRST_BYTE]));

				//Get common CAS latency time
				if (CurrentSpdData->Buffer[DDR4_SPD_MIN_CL_TIME] > Tmp){
					Tmp = CurrentSpdData->Buffer[DDR4_SPD_MIN_CL_TIME];
					FineOffset = CurrentSpdData->Buffer[DDR4_SPD_CL_FINE_OFFSET];
				}
			}
		}

		//Calculate desired CL
		//LGE-20160223 Add SPD Fine Offset control
		Tmp = (Tmp * 125 + FineOffset + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
		Tmp = CheckMinClRpRcdValue(PeiServices,pPCIPPI,DramAttr,(UINT16)Tmp);

		//Check if the desired CL is supported.
		//if not, search the (desired CL)+1 until supported CL is found
		Mask = 1 << (Tmp - 7); 
		while (Mask != DDR4_CL_MASK){
			if (CLSupported & Mask){ //matched
				break;
			} 
			else { //not matched
				Mask <<= 1;
			}
		}
		//search SPD fail.
		if(Mask==DDR4_CL_MASK){
			switch(DramAttr->DramFreq){		
				case DRAM_FREQ_1600: 
					Mask=0x000020;    //CL =  12
					break;
				case DRAM_FREQ_1866:
					Mask=0x000080;    //CL = 14
					break;
				case DRAM_FREQ_2133:
					Mask=0x000200;    //CL = 16
					break;
				case DRAM_FREQ_2400:
					Mask=0x000800;    //CL = 18
					break;
				case DRAM_FREQ_2666:
					Mask=0x000800;	  //CL = 18
					break;
				case DRAM_FREQ_2933:
					Mask=0x002000;	  //CL = 20
					break;
				case DRAM_FREQ_3200:
					Mask=0x008000;    //CL = 22 
					break;
				default:
					Mask=0x000800;    //CL = 18
					break;
			}


          PEI_DEBUG((PeiServices, EFI_D_ERROR, "*****AC Timing error, CL match fail*****\r\n"));    
			
		}

		for (Index = 0; Index < 32; Index++){
			if (Mask == 0x01){
				Tmp = Index + 7;
				break;
			} else {
				Mask >>= 1;
			}
		}
	}
	else
		Tmp = DramAttr->ConfigData.DramCL;

	if(Tmp > DDR4_MAX_CL){		
		ACTimingError(PeiServices,MAX_ERROR,Tmp,DDR4_MAX_CL,"CL");
		Tmp = DDR4_MAX_CL;	
		}
	else if(Tmp < DDR4_MIN_CL){	
	    ACTimingError(PeiServices,MIN_ERROR,Tmp,DDR4_MIN_CL,"CL");
		Tmp = DDR4_MIN_CL;
		}
	////////////DKS:::Design-Limitation-Patch////////
	//Design limitation Item 8 +s
	//Not support RCL 9/10T
	if (Tmp == 9 || Tmp == 10)
	{
		Tmp = 11;
	}
	//Design limitation Item 8 +e
	/////////////////////////////////////////////
	DramAttr->CL[DramAttr->AttrNo] = (UINT8)Tmp;	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CL = %d\n",(UINT8)Tmp));        
	
		
	Tmp -= DDR4_CL_GAP;
	
	

	//D0F3Rx180[12:8]
	Tmp <<= 8;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCL_4_0, Tmp);
	return;
}

#define DDR4_MAX_TRP 35 
#define DDR4_MIN_TRP 4 
#define DDR4_TRP_GAP 4
VOID DRAMTimingTrp(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)

{ 
	UINT64 Address;
	UINT32 Max, Tmp = 0;
	UINT8 Index;
	INT8   FineOffset = 0;
	ASIA_SPD_DATA   *CurrentSpdData;

	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
		Max = 0;
		for (Index = 0; Index< ASIA_MAX_DIMMS; Index++){			
			CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
			if (CurrentSpdData->SpdPresent){
				Tmp = (UINT16)CurrentSpdData->Buffer[DDR4_SPD_MIN_TRP];
				if (Tmp > Max){
					FineOffset = CurrentSpdData->Buffer[DDR4_SPD_TRP_FINE_OFFSET];
					Max = Tmp;
				}
			}
		}

		//Calculate clock
		//LGE-20160223 Add SPD Fine Offset control
		Tmp = (Max * 125 + FineOffset + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
		Tmp = CheckMinClRpRcdValue(PeiServices,pPCIPPI,DramAttr,(UINT16)Tmp);
	}
	else
		Tmp = DramAttr->ConfigData.DramTrp;

	if (Tmp > DDR4_MAX_TRP){		
		ACTimingError(PeiServices,MAX_ERROR,Tmp, DDR4_MAX_TRP,"TRP");
		Tmp = DDR4_MAX_TRP;
		}
	else if(Tmp < DDR4_MIN_TRP){		
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TRP,"TRP");
		Tmp = DDR4_MIN_TRP;
		}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trp = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TRP_GAP; //00->4T, 01->5T, 10->6T, 11->7T, ..., nh->(4+n)T, ..., 111->11T

	//D0F3Rx180[22:18]
	Tmp <<= 18;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTRP_4_0, Tmp);

	//set D0F3Rx15E[5:3] RTRPA = 00b	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV_V);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTRPA_2_0, 0X00);
	return;
}

#define DDR4_MAX_TRCD 36 
#define DDR4_MIN_TRCD 6
#define DDR4_TRCD_GAP 6
VOID DRAMTimingTrcd(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)           
{     
	UINT64 Address;
	UINT32 Max;
	UINT32 Tmp = 0;
	UINT8  Index;
	INT8   FineOffset = 0;
	ASIA_SPD_DATA	 *CurrentSpdData;

	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
		//DDR4
		Max = 0; 
		for (Index = 0; Index < ASIA_MAX_DIMMS; Index++){			
			CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
			if (CurrentSpdData->SpdPresent){
				Tmp = (UINT16)CurrentSpdData->Buffer[DDR4_SPD_MIN_TRCD];
				if (Tmp > Max){
					Max = Tmp;
					FineOffset = CurrentSpdData->Buffer[DDR4_SPD_TRCD_FINE_OFFSET];
				}
			}
		}

		//Calculate clock
		//LGE-20160223 Add SPD Fine Offset control
		Tmp = (Max * 125 + FineOffset + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
		Tmp=CheckMinClRpRcdValue(PeiServices,pPCIPPI,DramAttr,(UINT16)Tmp);
	}
	else
		Tmp = DramAttr->ConfigData.DramTrcd;

	if(Tmp > DDR4_MAX_TRCD){
		ACTimingError(PeiServices,MAX_ERROR,Tmp, DDR4_MAX_TRCD,"TRCD");
		Tmp = DDR4_MAX_TRCD;
		}
	else if(Tmp < DDR4_MIN_TRCD){
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TRCD,"TRCD");
		Tmp = DDR4_MIN_TRCD;
		}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trcd = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TRCD_GAP;
	Tmp <<= 13;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTRCD_4_0, Tmp);
	return;
}

#define DDR4_MAX_TRAS 95
#define DDR4_MIN_TRAS 15
#define DDR4_TRAS_GAP 15
VOID DRAMTimingTras(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)

{     

	UINT64 Address;
	UINT16 Max, Tmp = 0;
	UINT16 TrasMin = 0;
	UINT8  Index;
	ASIA_SPD_DATA *CurrentSpdData;

    switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:
			TrasMin = 0x118;//35ns
			break;
		case DRAM_FREQ_1866://34ns
			TrasMin = 0x110;
			break;
		case DRAM_FREQ_2133://33ns
			TrasMin = 0x108;
			break;
		case DRAM_FREQ_2400://32ns
			TrasMin = 0x100;
			break;
		case DRAM_FREQ_2666://32ns
			TrasMin = 0x100;				
			break;
		case DRAM_FREQ_2933://32ns
			TrasMin = 0x100;
			break;
		case DRAM_FREQ_3200://32ns
			TrasMin = 0x100;   		
			break;
		default:
			TrasMin = 0x118;
			break; 	
    }		
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
		//DDR4	
		Max = 0;
		for (Index = 0; Index < ASIA_MAX_DIMMS; Index++){			
			CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
			if (CurrentSpdData->SpdPresent){			   
				Tmp = ((CurrentSpdData->Buffer[DDR4_SPD_UPPER_NIBBLE_TRAS_TRC] & 0x0F)<<8)|(CurrentSpdData->Buffer[DDR4_SPD_MIN_TRAS_LSB]);
				if (Tmp > Max)
					Max = Tmp;
			}
		}

		//LGE20170215 Check tRAS_SPD Base on DDR4 SPEC
        if(Max <= TrasMin)
			Max = TrasMin;

		 
		//Calculate clock
		Tmp = (Max*125 + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
	}
	else
		Tmp = DramAttr->ConfigData.DramTras;


	if(Tmp > DDR4_MAX_TRAS){
		ACTimingError(PeiServices,MAX_ERROR,Tmp, DDR4_MAX_TRAS,"TRAS");
		Tmp = DDR4_MAX_TRAS;
		}
	else if(Tmp < DDR4_MIN_TRAS){
		ACTimingError(PeiServices,MIN_ERROR,Tmp,  DDR4_MIN_TRAS,"TRAS");
		Tmp = DDR4_MIN_TRAS;
		}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Tras = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TRAS_GAP;

     
	//D0F3Rx184[7:1]
	Tmp <<= 1;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTRAS_6_0, Tmp);
	return;
}

#define DDR4_MAX_TRFC 1006
#define DDR4_MIN_TRFC 30
#define DDR4_TRFC_GAP 30
VOID DRAMTimingTrfc(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)

{     

	UINT64 Address;
	UINT32 Max, Tmp = 0;
	UINT8  Index;
	ASIA_SPD_DATA *CurrentSpdData;

	//DDR4
	/*get the max Trfc value from SPD data*/
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){	
	Max = 0;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++ ){			
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if (CurrentSpdData->SpdPresent){
			Tmp = (CurrentSpdData->Buffer[DDR4_SPD_MIN_TRFC1_MSB] << 8)|(CurrentSpdData->Buffer[DDR4_SPD_MIN_TRFC1_LSB]);
			if (Tmp > Max)
				Max = Tmp;
		}
	}
	//Calculate clock	
	Tmp = (Max*125 + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
#ifdef	DDR4_800
	Tmp = (Max*125 + DRAM_CYCLE_800 - 1)/DRAM_CYCLE_800;	
#endif 
		

	if (Tmp & 0x01) //odd
		Tmp++; //add 1 to be even
	}
	//else
		//Tmp = DramAttr->ConfigData.DramTrfc;		
	if(Tmp > DDR4_MAX_TRFC){
		ACTimingError(PeiServices,MAX_ERROR,Tmp, DDR4_MAX_TRFC,"TRFC");
		Tmp = DDR4_MAX_TRFC;
		}
	else if(Tmp < DDR4_MIN_TRFC){
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TRFC,"TRFC");
		Tmp = DDR4_MIN_TRFC;
		}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trfc = %d\n", Tmp));
	Tmp -= (DDR4_TRFC_GAP - 7);
	Tmp >>= 3;		//tRFC = (30+8n)T, thus n = (tRFC-30)/8

	//D0F3Rx186[14:8]
	Tmp <<= 8;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV_V);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTRFC_6_0, (UINT16)Tmp);
	return;
}

#define DDR4_MAX_TRRD 12
#define DDR4_MIN_TRRD 6
#define DDR4_TRRD_GAP 5
VOID DRAMTimingTrrd(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)

{     
	UINT64 Address;
	UINT16 Max, Tmp = 0;
	UINT8  Index;
	INT8   FineOffset = 0;
	ASIA_SPD_DATA  *CurrentSpdData;

	//DDR4 tRRD short		
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){		
	Max = 0;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++){			
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if (CurrentSpdData->SpdPresent){
			Tmp = (UINT16)(CurrentSpdData->Buffer[DDR4_SPD_MIN_TRRD_SHORT]);
			if (Tmp > Max){
				Max = Tmp;
				FineOffset = CurrentSpdData->Buffer[DDR4_SPD_TRRD_SHORT_FINE_OFFSET];
			}
		}
	}
	//Calculate clock
	//LGE-20160223 Add SPD Fine Offset control
	Tmp = (Max * 125 + FineOffset + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
	}
	//else
		//Tmp = DramAttr->ConfigData.DramTrrd;	
	if (Tmp > DDR4_MAX_TRRD){
		ACTimingError(PeiServices,MAX_ERROR,Tmp, DDR4_MAX_TRRD,"TRRD");
		Tmp = DDR4_MAX_TRRD;
		}
	else if(Tmp < DDR4_MIN_TRRD){
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TRRD,"TRRD");
		Tmp = DDR4_MIN_TRRD;
		}


	DramAttr->TRRD_S[DramAttr->AttrNo] = (UINT8)Tmp;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trrd = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TRRD_GAP;
	

	//D0F3Rx184[10:8]
	Tmp <<= 8;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTRRD_2_0, Tmp);
	return;
}

#define DDR4_MAX_TWR 26 
#define DDR4_MIN_TWR 10
#define DDR4_TWR_GAP 9
VOID DRAMTimingTwr(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{     

	UINT64 Address;
	UINT16 Max;
	UINT32 Tmp = 0;

	//DDR4  Twr = 15ns for 1600/1866/2133/2400 MHZ
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:				   
		case DRAM_FREQ_1866:
		case DRAM_FREQ_2133:	
		case DRAM_FREQ_2400:
			Max = 120;
			break;
		case DRAM_FREQ_2666:
			Max = 120;				 
			break;
		case DRAM_FREQ_2933:
			Max = 120; 
			break;
		case DRAM_FREQ_3200:
			Max = 120;   		  
			break;
		default: 
			Max = 120;
			break;
	}
	//Calculate clock
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	Tmp = (Max*125 + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTwr;
	if(Tmp > DDR4_MAX_TWR){
		ACTimingError(PeiServices,MAX_ERROR,Tmp,DDR4_MAX_TWR, "TWR");
		Tmp = DDR4_MAX_TWR;
		}
	else if(Tmp < DDR4_MIN_TWR){		
		ACTimingError(PeiServices,MIN_ERROR,Tmp,DDR4_MIN_TWR,"TWR");
		Tmp = DDR4_MIN_TWR;
		}

	//write preamble=2 
	if(DramAttr->WPREA == WPREA2CLK)
		Tmp += 2;

	    
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Twr = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TWR_GAP;	
	Tmp >>= 1;          //twr = (10+2n)T, thus n = (tWR-10)/2
	if(Tmp == 7)        //if twr =  24T,tmp =6 instead of 7 
		Tmp = 6;
	else if(Tmp == 6)  //if twr =  22T,tmp =7 instead of 6  
		Tmp = 7;

	DramAttr->Twr[DramAttr->AttrNo] = (UINT8)(Tmp); 
	//D0F3Rx15C[2:0]
	Tmp <<= 28;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RWRCOV_3_0, Tmp);
	return;
}

#define DDR4_MAX_TWTR 9
#define DDR4_MIN_TWTR 3
#define DDR4_TWTR_GAP 2
VOID DRAMTimingTwtr(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{     
	UINT64 Address;
	UINT16 Tmp = 0;
	UINT8 TWTR_S = 0;

	//max(2nck,2.5 ns)
	//DDR4
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:
			TWTR_S = 3;
			break;
		case DRAM_FREQ_1866:
			TWTR_S = 3;
			break;
		case DRAM_FREQ_2133:
			TWTR_S = 3;
			break;
		case DRAM_FREQ_2400:
			TWTR_S = 4;
			break;
		case DRAM_FREQ_2666:
			TWTR_S = 4;
			break;
		case DRAM_FREQ_2933:
			TWTR_S = 4;
			break;
		case DRAM_FREQ_3200:
			TWTR_S = 4;
			break;
		default:
			TWTR_S = 4;
			break;
	}
	//write preamble=2 
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
		if(DramAttr->WPREA == WPREA2CLK) 
			TWTR_S++;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Twtr = %d\n", TWTR_S));		
		
	}
	//else{
	///Tmp = DramAttr->ConfigData.DramTwtr;
	
	//}
	DramAttr->TWTR_S[DramAttr->AttrNo] = TWTR_S;
	Tmp =TWTR_S - DDR4_TWTR_GAP;
	
	//D0F3Rx186[2:0]
	//Tmp <<= 0;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV_V);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTWTR_2_0, Tmp);
	return;
}

#define DDR4_MAX_TRTP 13
#define DDR4_MIN_TRTP 5
#define DDR4_TRTP_GAP 5
VOID DRAMTimingTrtp(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{     
	UINT64 Address;
	UINT32 Tmp = 0;
	UINT8 TWR;
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	TWR	= DramAttr->Twr[DramAttr->AttrNo];
	//DDR4
	switch(TWR){
		case 0:     //tWR = 10
			Tmp = 5;
			break;    
		case 1:     //tWR = 12
			Tmp = 6;
			break;
		case 2:     //tWR = 14 
			Tmp = 7;
			break;
		case 3:     //tWR = 16
			Tmp = 8;
			break;
		case 4:     //tWR = 18
			Tmp = 9;
			break;
		case 5:     //tWR = 20
			Tmp = 10;
			break;
		case 6:     //tWR = 24
			Tmp = 12;
			break;
		case 7:     //tWR = 22  
			Tmp = 11;
			break;
		case 8:     //tWR = 26
			Tmp = 13;
			break;
		default:
			Tmp = 5;
			break;
	}
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTrtp;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trtp = %d\n",(UINT8)Tmp));

	
	Tmp -= DDR4_TRTP_GAP;
	
	//D0F3Rx180[27:24]
	Tmp <<= 24; 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RTRTP_3_0, Tmp);
	return;
}

#define DDR4_MAX_CWL 20
#define DDR4_MIN_CWL 9
#define DDR4_CWL_GAP 9
VOID DRAMTimingCWL(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{     
	UINT64 Address;
	UINT16  Tmp = 0;
	BOOLEAN SECONDSET = FALSE;
	UINT8 CL = 0;
	UINT8 CWL = 0;

    CL = DramAttr->CL[DramAttr->AttrNo];
	
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:
			if(CL < 12){   //CL < 12T 
				CWL = 9; //CWL=9T				
			}
			else{
				CWL = 11; //CWL=11T				
				SECONDSET = TRUE;
			}
			break;
		case DRAM_FREQ_1866:
			if(CL < 13){   //CL < 13T
				CWL = 10;  //CWL=10T				
				}
			else{
				CWL = 12; //CWL=12T				
				SECONDSET = TRUE;
			}
		case DRAM_FREQ_2133:
			if(CL < 15)    //CL <15T
				CWL = 11; //CWL=11T				
			else{
				CWL = 14; //CWL=14T				
				SECONDSET = TRUE;
			}
			break;
		case DRAM_FREQ_2400:
			if(CL < 15){   //CL< 15T
				CWL = 12; //CWL=12T				
				}	
			else{
				CWL = 16; //CWL=16T				
				SECONDSET = TRUE;
			}
			break;
		case DRAM_FREQ_2666:
			if(CL < 19){   //CL< 19T
				CWL = 14; //CWL=14T				
				}	
			else{
				CWL = 18; //CWL=18T				
				SECONDSET = TRUE;
			}
			break;
		case DRAM_FREQ_2933:
			if(CL < 21){   //CL< 21T
				CWL = 16; //CWL=16T				
				}	
			else{
				CWL = 20; //CWL=20T				
				SECONDSET = TRUE;
			}
			break;
		case DRAM_FREQ_3200:
			if(CL < 22){   //CL< 22T
				CWL = 16; //CWL=16T				
				}	
			else{
				CWL = 20; //CWL=20T				
				SECONDSET = TRUE;
			}
			break;
		default:
			CWL = 16;  //CWL=16T			
			break;			
	}
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	//write preamble=2 
	if(DramAttr->WPREA == WPREA2CLK && !SECONDSET)
	{	  
		CWL += 2;

	}

#if 0
	//Ensure CL >= CWL
	if(DramAttr->CWL > DramAttr->CL)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR, CWL > CL\r\n"));
		DramAttr->CL++;
		//D0F3Rx159[4:0]
		//Tmp <<= 0;
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
		Tmp = (UINT8)DramAttr->CL;
		Tmp <<= 8;
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCL_4_0, Tmp);

	}
#endif

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CWL = %d\n",CWL));
	//D0F3Rx180[4:0] 


	////////////DKS:::Design-Limitation-Patch////////
	//Design limitation Item 10 +s
	if (CWL == 9)
	{
		if (DramAttr->BurstLength8 == BL_ONTHEFLY)
			DramAttr->ConfigData.DataScmb = FALSE;
	}
	//Design limitation Item 10 +e
	/////////////////////////////////////////////	

	}
	//else{
	//	CWL = DramAttr->ConfigData.DramCWL ;
	
	//}

	DramAttr->CWL[DramAttr->AttrNo] = CWL;
	Tmp = CWL - DDR4_CWL_GAP;   //DKS-20170928 change Tmp = DramAttr->CWL tmp

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCWL_4_0, Tmp);

	

	return;
}

#define DDR4_MAX_TFAWX 15
#define DDR4_MIN_TFAWX 0
#define DDR4_TFAWX_GAP 0
VOID DRAMTimingTfawx(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{     
	UINT64 Address;
	UINT16 Max, Tmp = 0;
	UINT8  Index;
    UINT16 Data;
	ASIA_SPD_DATA  *CurrentSpdData;

	//DDR4
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	Max = 0;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++){			
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if (CurrentSpdData->SpdPresent){
			Tmp = (UINT16)((CurrentSpdData->Buffer[DDR4_SPD_UPPER_NIBBLE_TFAW] & 0x0F) << 8)|(CurrentSpdData->Buffer[DDR4_SPD_MIN_TFAW]);
			if (Tmp > Max)
				Max = Tmp;
		}
	}

	//Calculate clock
	Tmp = (Max*125 + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "tFAW = %d\n", Tmp));
	
    Data = DramAttr->TRRD_S[DramAttr->AttrNo] *4; //Data = 4*TRRD
	if (Tmp < Data) //TFAW < 4*TRRD
		Tmp = DDR4_MIN_TFAWX;
	else
		Tmp = Tmp - Data; //TFAWX = TFAW - 4*TRRD
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTfawx;
	if(Tmp > DDR4_MAX_TFAWX){
		ACTimingError(PeiServices,MAX_ERROR,Tmp,DDR4_MAX_TFAWX, "TFAWX");
		Tmp = DDR4_MAX_TFAWX;
		}	
	else if(Tmp < DDR4_MIN_TFAWX){
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TFAWX,"TFAWX");
		Tmp = DDR4_MIN_TFAWX;
		}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Tfawx = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TFAWX_GAP;

	//D0F3Rx184[15:12]
	Tmp <<= 12; 	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTFAWX_3_0, Tmp);
	return;
}

#define DDR4_MAX_TCKE 10
#define DDR4_MIN_TCKE 2
#define DDR4_TCKE_GAP 1
VOID DRAMTimingTcke(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16 Tmp = 0;

	//max(3nck, 5ns) 
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:	
			Tmp = 4;
			break;
		case DRAM_FREQ_1866:
			Tmp = 6;
			break;
		case DRAM_FREQ_2133:
			Tmp = 6;
			break;
		case DRAM_FREQ_2400:
			Tmp = 6;
			break;
		case DRAM_FREQ_2666:
			Tmp = 7;
			break;
		case DRAM_FREQ_2933:
			Tmp = 8;
			break;
		case DRAM_FREQ_3200:
			Tmp = 8;
			break;
		default: 
			Tmp = 6;
			break;
	}
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Tcke = %d\n",(UINT8)Tmp));
	Tmp = (Tmp+1) / 2; 
	Tmp -=DDR4_TCKE_GAP; //tCKE = (n + 1) *2, thus n = tCKE/2 -1

	//D0F3RX180[7:5]
	Tmp <<= 5;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTCKE_2_0, Tmp);
}

//#define DDR4_MAX_TXP 8
//#define DDR4_MIN_TXP 2
VOID DRAMTimingTxp(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16  Tmp = 0;

	//max(4nck, 6ns)
	//LGE20160804 Update for IRS Change
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:	
			Tmp = 0;       //6T
			break;
		case DRAM_FREQ_1866:
			Tmp = 0;       //6T
			break;
		case DRAM_FREQ_2133:
			Tmp = 1;       //8T
			break;
		case DRAM_FREQ_2400:
			Tmp = 1;       //8T   
			break;
		case DRAM_FREQ_2666:
			Tmp = 1;       //8T 
			break;
		case DRAM_FREQ_2933:
			Tmp = 2;       //10T 
			break;
		case DRAM_FREQ_3200:
			Tmp = 2;       //10T
			break;
		default: 
			Tmp = 1;       //8T
			break;
	}    
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTxp;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Txp = %d\n",(UINT8)((Tmp+3)*2)));

	//D0F3RX18A[14:12]
	Tmp <<= 12;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_X);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTXPD_2_0, Tmp);
}

VOID DRAMTimingRTXSREXT(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16  Tmp = 0;   

    switch(DramAttr->DramFreq){
    	case DRAM_FREQ_1600:      
        	Tmp = 0x5;
        break;
        case DRAM_FREQ_1866:
        	Tmp = 0x5;
        break;
        case DRAM_FREQ_2133:
        	Tmp = 0x10;
        break;
        case DRAM_FREQ_2400:
        	Tmp = 0x10;
        break;
        case DRAM_FREQ_2666:   
        	Tmp = 0x15;
        break;
        case DRAM_FREQ_2933:
        	Tmp = 0x1b;//27
        break;
        case DRAM_FREQ_3200:
        	Tmp = 0x20;
        break;
        default: 
        	Tmp = 0x5;
        break;
    }      


	//D0F3 RX188[5:0]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTXSREXT_5_0, Tmp);

}

#define DDR4_MAX_TRRD_SG  7
#define DDR4_MIN_TRRD_SG  1
#define DDR4_TRRD_SG_GAP  0
//DRAM Timing Only for DDR4
VOID DRAMTimingTrrd_SG(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16 Max, Tmp = 0;
	UINT16 TRRD_L,TRRD_S;
	UINT8  Index;
	INT8   FineOffset = 0;
	ASIA_SPD_DATA  *CurrentSpdData;
	//DDR4
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	Max = 0;
	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++){			
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if (CurrentSpdData->SpdPresent){
			Tmp = (UINT16)(CurrentSpdData->Buffer[DDR4_SPD_MIN_TRRD_LONG]);
			if (Tmp > Max){
				Max = Tmp;
				FineOffset = CurrentSpdData->Buffer[DDR4_SPD_TRRD_LONG_FINE_OFFSET];
			}
		}
	}

	//Calculate clock
	//LGE-20160223 Add SPD Fine Offset control
	Tmp = (Max * 125 + FineOffset + (DramAttr->DramCycle) - 1)/(DramAttr->DramCycle);
	TRRD_L = Tmp;
	TRRD_S = DramAttr->TRRD_S[DramAttr->AttrNo];
	
	if(TRRD_L < TRRD_S)
		TRRD_L = TRRD_S; 
	Tmp = TRRD_L - TRRD_S;  	
	if (Tmp > DDR4_MAX_TRRD_SG){
		ACTimingError(PeiServices,MAX_ERROR,Tmp,  DDR4_MAX_TRRD_SG,"TRRDSG");
		Tmp = DDR4_MAX_TRRD_SG;
		}
	else if(Tmp < DDR4_MIN_TRRD_SG){
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TRRD_SG,"TRRDSG");
		Tmp = DDR4_MIN_TRRD_SG;
		}
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTrrd_SG;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trrd_SG = %d\n",Tmp)); 
	Tmp -= DDR4_TRRD_SG_GAP;
	//D0F3 RX18C[5:3]
	Tmp <<= 3;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTRRD_SG_2_0, Tmp);

}


#define DDR4_MAX_TCCD_SG 7
#define DDR4_MIN_TCCD_SG 0
#define DDR4_TCCD_SG_GAP 0
VOID DRAMTimingTccd_SG(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16 Tmp = 0;
	// tCCD_L= tCCD_S + RTCCD_SG.
	// tCCD_S = 4
	// DDR4
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
			
		switch(DramAttr->DramFreq){
			case DRAM_FREQ_1600: 
			case DRAM_FREQ_1866: 
				Tmp = 1;      //tCCD_L = 5 
				break;
			case DRAM_FREQ_2133: 
			case DRAM_FREQ_2400: 
				Tmp = 2;      //tCCD_L = 6
				break;
			case DRAM_FREQ_2666:
				Tmp = 3;       //tCCD_L = max(5nck, 5ns)=7, tCCD_S = 4
				break; 
			case DRAM_FREQ_2933:
				Tmp = 4;       //tCCD_L = max(5nck, 5ns)=8, tCCD_S = 4
				break;
			case DRAM_FREQ_3200:
				Tmp = 4;        //tCCD_L = max(5nck, 5ns)=8, tCCD_S = 4
				break;
			default:
				Tmp = 2;
				break;		
		}
	
		if(DramAttr->RPREA == RPREA2CLK)
		{
            if(Tmp <= 2)
				Tmp = 2;   //tCCD_L = 6
		}
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTccd_SG;
  Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II_I);
    //tccd_L = 6
	if(Tmp == 2 || DramAttr->RPREA == RPREA2CLK || DramAttr->WPREA == WPREA2CLK)
	{
        AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, BIT6, BIT6);
	}
	//tccd_L = 7
    if(Tmp == 3 && DramAttr->WPREA == WPREA2CLK)
    {
    	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, BIT7, BIT7);
    }

	//tccd_L = 8
	if(Tmp == 4)
    {
    	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, BIT7, BIT7);
    }
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Tccd_SG = %d\n",(UINT8)Tmp)); 
	Tmp -= DDR4_TCCD_SG_GAP;	
	//D0F3 RX18C[2:0]
	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTCCD_SG_2_0, Tmp);
}

//DYS  
#define DDR4_MAX_TWTR_SG 8
#define DDR4_MIN_TWTR_SG 3
#define DDR4_TWTR_SG_GAP 0
VOID DRAMTimingTwtr_SG(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)/* need-->done */
{ 
	UINT64 Address;
	UINT16 Tmp = 0;
	UINT8  TWTR_L=0,TWTR_S;

	//max(4nCK,7.5ns)		
	//DDR4
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	switch(DramAttr->DramFreq){
		case DRAM_FREQ_1600:
			TWTR_L = 6;
			break;
		case DRAM_FREQ_1866:
			TWTR_L = 7;
			break;
		case DRAM_FREQ_2133:
			TWTR_L = 8;
			break;
		case DRAM_FREQ_2400:
			TWTR_L = 10;
			break;
		case DRAM_FREQ_2666:
			TWTR_L = 10;
			break;
		case DRAM_FREQ_2933:
			TWTR_L = 11;
			break;
		case DRAM_FREQ_3200:
			TWTR_L = 12;
			break;
		default:
			TWTR_L = 10;
			break;

	}
		TWTR_S = DramAttr->TWTR_S[DramAttr->AttrNo];
	if(TWTR_L < TWTR_S)
		TWTR_L = TWTR_S;
	Tmp = (TWTR_L - TWTR_S);
		
	if (Tmp > DDR4_MAX_TWTR_SG){
		ACTimingError(PeiServices,MAX_ERROR,Tmp,  DDR4_MAX_TWTR_SG,"TWTRSG");
		Tmp = DDR4_MAX_TWTR_SG;
		}
	else if(Tmp < DDR4_MIN_TWTR_SG){
		ACTimingError(PeiServices,MIN_ERROR,Tmp, DDR4_MIN_TWTR_SG,"TWTRSG");
		Tmp = DDR4_MIN_TWTR_SG;
		}
	}
	//else
	//Tmp = DramAttr->ConfigData.DramTwtr_SG;
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "Twtr_SG = %d\n",(UINT8)Tmp));
	Tmp -= DDR4_TWTR_SG_GAP;
	//D0F3 RX18c[15:12]
	Tmp <<= 12;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTWTR_SG_3_0, Tmp);
}

#define DDR4_MIN_CAL 0
#define DDR4_MAX_CAL 8
#define DDR4_CAL_GAP 2
VOID DRAMTimingCAL(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT16 Tmp = 0;

	//DDR4
	//max(3nCK, 3.748ns)
	if(DramAttr->ConfigData.ACTimingOption == ACTIMING_AUTO){
	if(!DramAttr->ConfigData.CALEn)
		Tmp = 0;
	else{

		switch(DramAttr->DramFreq){
			case DRAM_FREQ_1600:
				Tmp = 4;
				break;
			case DRAM_FREQ_1866:
			case DRAM_FREQ_2133:
				Tmp = 4;
				break;
			case DRAM_FREQ_2400:
				Tmp = 6;
				break;
			case DRAM_FREQ_2666:
				Tmp = 6;
				break;
			case DRAM_FREQ_2933:
				Tmp = 6;
				break;
			case DRAM_FREQ_3200:
				Tmp = 6;
				break;
			default:
				Tmp = 6;
				break;			
		}
	}
	}
	//else
	//Tmp = DramAttr->ConfigData.DramCAL;

	DramAttr->CAL[DramAttr->AttrNo] = (UINT8)Tmp;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CAL = %d\n",(UINT8)Tmp)); 
	if(Tmp > DDR4_CAL_GAP)
		Tmp -= DDR4_CAL_GAP;
	//if CAL == 8T, Tmp =5 instead of 6
	if(Tmp == 6)
		Tmp = 5;

	
	//D0F3 RX18c[10:8]
	Tmp <<= 8;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II_I);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCAL_2_0, Tmp);
}






VOID DRAMTimingPreamble(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{

	UINT16 Temp =0;
	UINT64 Address;

	//LGE20160527 Must Set before DramInit, or SWinit will Miss setting this register
	//MR4[A12],Write Preamble
	//RX170[2]
	if(DramAttr->WPREA == WPREA1CLK)
		Temp = 0;
	else if(DramAttr->WPREA == WPREA2CLK)
		Temp = BIT2;		
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RWPRE, Temp);

	//MR4[A11],Read Preamble
	//RX170[1]
	if(DramAttr->RPREA == RPREA1CLK)
		Temp = 0;
	else if(DramAttr->RPREA == RPREA2CLK)
		Temp = BIT1;
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, 
			D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RRPRE, Temp);


	if(DramAttr->WPREA == WPREA2CLK)
	{
       Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
       AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x02 << 12);		
	   AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x03 << 4);
		
	}
	if(DramAttr->RPREA == RPREA2CLK)
	{

        Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
       
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x02 << 8);		
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x03 << 0); 
	}

}

#define BankIntlv_Disabled   	0x00
#define BankIntlv_8PG        	0x30
VOID DRAMTimingBankInterleave(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN OUT DRAM_ATTRIBUTE *DramAttr)
{
	
	UINT64 		Address;
	UINT8		BankInterleave;

	switch(DramAttr->ConfigData.BankIntlv){
		case BANK_INTERLEAVE_SPD: 
			BankInterleave = BankIntlv_8PG; //DDR4 only support Be set 11 which means 16 page interleave
			break;
		case BANK_INTERLEAVE_NONPAGE: 
			BankInterleave = BankIntlv_Disabled; 
			break;		
		case BANK_INTERLEAVE_8PAGES: 
			BankInterleave = BankIntlv_8PG; 
			break;
		default: 
			BankInterleave = BankIntlv_Disabled; 
			break;
	}

	//D0F3Rx16E[11]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
   
	if(BankInterleave == BankIntlv_8PG){
		 AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, D0F3_RPGEN);
		 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Enable multipage mode\r\n")); 
	}
	else{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RPGEN, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Disable multipage mode\r\n"));
	}


	//D0F3Rx14E[5:4]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RANK_INTERLEAVE_ADR_SEL_BANK_SCRAMBLE);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBKEN_1_0, BankInterleave);

	return;	
}

VOID DRAMTimingBurstLength(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)           
{   
	UINT64 Address;

	if(ASIA_NB_REVISION == 0)
	{
		//Design limitation item12: when RCL <= 3(CL <= 12T) , disable BC4-S
		if(DramAttr->CL[DramAttr->AttrNo] <= 12)	DramAttr->BurstLength8 =  BL8;	
		//Design limitation item12: when RCL <= 3(CL <= 12T) , disable BC4-E
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "A0 Limitation\r\n"));

	}
	//D0F3RX172[4]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);
	if (DramAttr->BurstLength8 == BL8)
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMBCOTF, 0);
	else
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDMBCOTF, D0F3_RDMBCOTF);
	return;
}

VOID DRAMTimingODT(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;

//LGE20161014DDR4 ODT control In 2T read preamble
	if(DramAttr->RPREA == RPREA2CLK)
	{
         Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING);
		 AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RRPRE_ODT, D0F3_RRPRE_ODT);
	}


	//////////////////////////////////DKS:::Design-Limitation-Patch/////////////////////////////////////////////
	//Register limitation Item 3 +s
	//RRPRE_ODT_2T = 1'b1
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRIO_CHN_A_B_DYNAMIC_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RRPRE_ODT_2T, D0F3_RRPRE_ODT_2T);

	//a. 1T preamble & RCL-RCWL  < 1
	if ((DramAttr->RPREA == RPREA1CLK) && (DramAttr->CL[DramAttr->AttrNo] - DramAttr->CWL[DramAttr->AttrNo] < 1))
	{
		//D0F3_RX610 = 1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_ODT_CTL_DDR_AUTO_COMPENSATION_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, BIT0, BIT0);

		if (DramAttr->RegDimm == NOT_REG_DIMM)  //UDIMM
		{
			//RODTTAR = b10
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x02 << 2);
		}
		else  //RDIMM
		{
			//RODTTAR = b11
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x03 << 2);
		}
		
	}
	//b. 2T preamble & RCL-RCWL  < 2
	else if ((DramAttr->RPREA == RPREA2CLK) && (DramAttr->CL[DramAttr->AttrNo] - DramAttr->CWL[DramAttr->AttrNo] < 2))
	{
		//D0F3_RX610 = 1
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_ODT_CTL_DDR_AUTO_COMPENSATION_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, BIT0, BIT0);

		if (DramAttr->RegDimm == NOT_REG_DIMM)  //UDIMM
		{
			//RODTTAR = b10
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x02 << 2);
		}
		else  //RDIMM
		{
			//RODTTAR = b11
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x03 << 2);
		}
	}
	//c. others
	else
	{
		//D0F3_RX610 = 0
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_INTERNAL_ODT_CTL_DDR_AUTO_COMPENSATION_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, BIT0, 0);

		if (DramAttr->RegDimm == NOT_REG_DIMM)  //UDIMM
		{
			//RODTTAR = b01
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x01 << 2);
		}
		else  //RDIMM
		{
			//RODTTAR = b10
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x02 << 2);
		}
	}
	//Register limitation Item 3 +e
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	//LGE20180807 Patch DDR43200
	//if(DramAttr->DramFreq >= DRAM_FREQ_2933)
	{
		//RODTTAR = b11
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x03 << 2);
	}
	if(DramAttr->ConfigData.Perf_Turnaround == PERF_TURNAROUND_ENABLE){ // turn around setting for performance 
		if(DramAttr->DramFreq == DRAM_FREQ_2400){ // 2400Mhz RODTTAR = 1
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x01 << 2);	
		}
		if(DramAttr->DramFreq == DRAM_FREQ_2666){ //2666Mhz RODTTAR = 1
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x01 << 2);			
		}
	}
}


VOID DRAMTimingTurnAround(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)           
{   
	UINT64 Address;

	//Register limitation Item 4 +S
	/* 1TPreamble TurnAroundSetting is same as PCLMSI-->
	_____________________________________
	  {RFW2W2, RFW2W1, RFW2W0} = 3'b001;
	  {RFR2R2, RFR2R1, RFR2R0}       = 3'b000;
	  {RFR2W2, RFR2W1, RFR2W0}    = 3'b001;
	  {RFW2R2, RFW2R1, RFW2R0}    = 3'b010;
	  {RODTTAR1, RODTTAR0}	       = 2'b01;
       _____________________________________
	  */
#if 0
	//RFW2W[2:0] = 001
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x1 << 12);

	//RFR2R[2:0] = 000
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x0);

	//RFR2W[2:0] = 001
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x1 << 4);

	//RFW2R[2:0] = 010
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x2);

	//*RODTTAR[2:0] = 01
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTTAR_2_0, 0x1 << 2);
	//Register limitation Item 4 +E  
	//RCMDFLAGDIS default is 0
#endif
#if 1
	//RFW2W[2:0] = 001
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x3 << 12);

	//RFR2R[2:0] = 000
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x2<<8);

	//RFR2W[2:0] = 001
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x3 << 4);

	//RFW2R[2:0] = 010
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x4);
	
	//Register limitation Item 4 +E

	if(DramAttr->ConfigData.Perf_Turnaround == PERF_TURNAROUND_ENABLE){ // turn around setting for performance 
		if(DramAttr->DramFreq == DRAM_FREQ_2400){ // 2400Mhz [ RFR2R = 0; RFR2W = 4; RFW2R = 5; RFW2W = 3;]
			//RFR2R[2:0] = 000
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x0<<8);

			//RFR2W[2:0] = 001
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x4 << 4);

			//RFW2R[2:0] = 010
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x5);
			
			//RFW2W[2:0] = 001
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x3 << 12);	
		}
		if(DramAttr->DramFreq == DRAM_FREQ_2666){// 2666Mhz [ RFR2R = 1; RFR2W = 4; RFW2R = 5; RFW2W = 3;]
			//RFR2R[2:0] = 000
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x1<<8);

				if(DramAttr->ConfigData.DQSIByRank == BYRANK_DISABLE){
					//RFR2R[2:0] = 000
					Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
					AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x0<<8);

					}		

			//RFR2W[2:0] = 001
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x4 << 4);

			//RFW2R[2:0] = 010
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x5);
			
			//RFW2W[2:0] = 001
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x3 << 12);				
		}
	}
#endif
}


VOID DRAMTimingDynamicclock(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)           
{   
	UINT64 Address;

	//Register limitation Item 7 +S
	//D0F3_Rx1DA[15:0] = 0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_SUBMODULE_DYNAMIC_CLK_CTL);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0);
	//Register limitation Item 7 +E
}


VOID ACTimingError(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Errortype,
	UINT32 Calvalue,
	UINT32 Limitvalue,
	char *ErrorInfo
	)
{
    AsiaIoWrite8(0x80, 0x2C);
	if(Errortype == MAX_ERROR){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*****DRAM ERROR: AC Timing error, %a > MAX(%d>%d)*****\r\n",ErrorInfo,Calvalue,Limitvalue ));
		while(1);
	}	
	else if(Errortype == MIN_ERROR){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*****DRAM ERROR: AC Timing error, %a < MIN(%d<%d)*****\r\n",ErrorInfo, Calvalue,Limitvalue));
	}	
	
}

