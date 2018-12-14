//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "Draminit.h"
#include "DramUtil.h"
#include EFI_PPI_CONSUMER(AsiaNbPpi)
#include "UmaSet.h"
#include "PeiLib.h"
#include "UpdateRankAddr.h"
#include "IOTimingControl.h"
#include "SvadDvad.h"





/*
 *Purpose: 
 *	1. Init Data for Enable VR
 *	2. Sorting Virtual Rank by size and allocation the in below 4G
 *	3. programming  starting & Ending addres and waste some memory if need
 *	4. Enable Virtual Ranks
 *	5. Programming  MA Type & BA2_EN
 *	6. Programming  BA0/1/2 & BaScmb by setup option
 *	7. Fill ending address mirror in NB & SB
 */

EFI_STATUS UpdateRankAddr(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN ASIA_NB_CONFIGURATION *NbCfg,
	IN DRAM_ATTRIBUTE *DramAttr)
{
		//Daiaysun20181121 -for ecc demand scrud hang issue -S
		if(DramAttr->ConfigData.EccRetry)  //ECC Demand Scrub mode
		{
			UINT64  Address;
			UINT8	RankIdx8;
			UINT16	EndAddr16=0, StartAddr16=0; 
			UINT16	NextStartAddr16=0;
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Daisy_patch for ECC retry hang.\n"));
			// Clear all VR starting & Ending address
			for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
									 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8*2);
				AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00); //RX108-RX10F		
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
									D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
				AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00); //RX100-RX107
			}
	
			// Set Start & End address
			for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
				//if ( RankSize[RankIdx8] )  {
					
					//the begin/end address unit is 64MB,
					StartAddr16 = NextStartAddr16;
					EndAddr16 = StartAddr16 + 0x04;//ranksize 256M
					NextStartAddr16 = EndAddr16;
						
					//Set Virtual Rank Start & End[33:26]
					Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
									 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8*2);
					AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, StartAddr16); //RX108-RX10F   
					
					Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
									 D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
					AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, EndAddr16); //RX100-RX107					
					//ChAbegin++;
					
				//}
					
			}
	
			// Set Virtual Rank Enable and map as Physical Rank
			for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++){
					
				if ( DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ){
					SetVrMap(PeiServices, pPCIPPI, DramAttr, RankIdx8, RankIdx8, TRUE);
				}
			}
		
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN, D0F3_RERRSCREN);	
	
			WaitForMicroSec(PeiServices, 100);	//delay 100us
	
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED); 
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN, 0x0);	
		}
		//Daiaysun20181121 -for ecc demand scrud hang issue -E



    // 1. programming  starting & Ending addres
    
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Enter SetDRAMSize\n"));
	SetDRAMSize(PeiServices, pPCIPPI,NbCfg,DramAttr);
	
	// 2. Enable Virtual Ranks
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Enter SetRankEnable\n"));
	SetRankEnable(PeiServices, pPCIPPI, DramAttr);

	// 3. set virtual rank interleave
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Enter SetVRInterleave\n"));
	SetVRInterleave(PeiServices, pPCIPPI, NbCfg, DramAttr);	
		

	//LGE-20160128 Add SVAD set code
    //UpdateSVAD(PeiServices, pPCIPPI, DramAttr);
    UpdateSVADMemEntry(PeiServices,DramAttr);
	
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"Enter UpdateDVAD\n"));
    UpdateDVAD(PeiServices,DramAttr);
	
  
	
	

     //LGE20161212 -ONLY FOR SCAN DRAM IOTiming -S 
    {
		
	     UINT64 Address;
		 if(DramAttr->ConfigData.ScanIOTiming){
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
		 AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0x2000);

		 PEI_DEBUG((PeiServices, EFI_D_INFO, "ScanIOTiming Enable, LOWTOPA = 512MB--LGE DEBUG\r\n"));
		 	}
    }
    //LGE20161212 -ONLY FOR SCAN DRAM IOTiming -S 

	
	return EFI_SUCCESS;
}

VOID FlushCfgWrite(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT64 Address)
{

    //LGE20160420 Excute a CFG read to flush CFG write for registers to
    //ensure Finish CFG write before any other cycle
    AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);

}

/*
 *Purpose: 
 *	programming  starting & Ending addres
 *	1. Clear all VR starting & Ending address
 *	2. Set Start & End address
 *	3. Set LowTOPA
 */

VOID SetDRAMSize(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN ASIA_NB_CONFIGURATION *NbCfg,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8	RankIdx8;
	UINT16	EndAddr16=0, StartAddr16=0; //unit of 64M
	UINT16	NextStartAddr16=0;
	UINT16	RankSize[ASIA_MAX_RANKS];	//unit of 64M
    UINT64  Address;
	UINT16  Temp16;
	UINT8	ChAbegin=0;
	 UINT8	 ChBbegin=4;
	// Clear all VR starting & Ending address
 	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8*2);
        AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00); //RX108-RX10F        
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                    D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8*2);
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0X00); //RX100-RX107
	}

	// copy rank size to local variable;
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++){
		RankSize[RankIdx8] = DramAttr->RankInfo[DramAttr->AttrNo][RankIdx8].RankSize >> 6;  // in unit of 64MB 
	}

    
	// CHA Set Start & End address
	for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++) {
	    if(RankIdx8<4)
		{
 			if ( RankSize[RankIdx8] )  {
				//the begin/end address unit is 64MB,
				StartAddr16 = NextStartAddr16;
				EndAddr16 = StartAddr16 + RankSize[RankIdx8];
				NextStartAddr16 = EndAddr16;
			    	
			    		//Set Virtual Rank Start & End[33:26]
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + ChAbegin*2);
                AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, StartAddr16); //RX108-RX10F   
				
                Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_ENDING_ADR_37_26 + ChAbegin*2);
		        AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, EndAddr16); //RX100-RX107					
				ChAbegin++;
			}
	   	}			
	    else
		{   
			if ( RankSize[RankIdx8] )  {
				//the begin/end address unit is 64MB,
				StartAddr16 = NextStartAddr16;
				EndAddr16 = StartAddr16 + RankSize[RankIdx8];
				NextStartAddr16 = EndAddr16;
					    		//Set Virtual Rank Start & End[33:26]
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + ChBbegin*2);
                AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, StartAddr16); //RX108-RX10F   
				
                Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                     D0F3_DRAM_RANK0_ENDING_ADR_37_26 + ChBbegin*2);
		        AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, EndAddr16); //RX100-RX107				
				ChBbegin++;
			}				
	   }	
	}	

	//Set RFBBS[39:21] = DVADTop if UMA disable
	Temp16 = EndAddr16 << 5;
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFBBS_35_21, (Temp16 << 1) & D0F3_RFBBS_35_21);
	Temp16 = EndAddr16 >> 10;
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFBBS_39_36, Temp16);

	SetSVADMMIOCFG(PeiServices,NbCfg,DramAttr,EndAddr16,0);


}


/*
 *Purpose: 
 *	Enable Virtual Ranks
 *	1. Clear all Virtual Rank Enable
 *	2. Enable Virtual Ranks
 */
	UINT8 RankMap[7][5] =
	{
	 //RANKMAP	   RANK0   RANK1   RANK2  RANK3
	 {0x0F, 	  0,	  1,	 2, 	3},
	 {0x05, 	  0,	  2,	 1, 	3},
	 {0x0C, 	  2,	  3,	 0, 	1},
	 {0x03, 	  0,	  1,	 2, 	3},
	 {0x04, 	  2,	  1,	 0, 	3},
	 {0x01, 	  0,	  1,	 2, 	3},
	 {0X00, 	  0,	  1,	 2, 	3}
	};
	UINT8 RankMapSize = sizeof(RankMap)/sizeof(RankMap[0]);
	VOID SetRankEnable(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
	{
		UINT8 RankIdx8;  
		UINT8 RankPresent = 0;
		UINT8  RankMapIndex = 0;
	
		// Set Virtual Rank Enable and map as Physical Rank
		RankPresent = DramAttr->RankPresent[DramAttr->AttrNo] & CHA_BITMAP;
		for(RankMapIndex = 0; RankMapIndex < RankMapSize; RankMapIndex++){
			if(RankPresent == RankMap[RankMapIndex][0]){
				for (RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS/2; RankIdx8++){
					
					if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ){
						SetVrMap(PeiServices, pPCIPPI, DramAttr,RankIdx8, RankMap[RankMapIndex][RankIdx8+1], TRUE); 									
					}
					else
					{
						SetVrMap(PeiServices, pPCIPPI, DramAttr,RankIdx8, RankMap[RankMapIndex][RankIdx8+1], FALSE);
					}
	
					
				}
			}
		}
	
	
		RankPresent = (DramAttr->RankPresent[DramAttr->AttrNo] & CHB_BITMAP)>>4;
	
		for(RankMapIndex = 0; RankMapIndex < RankMapSize; RankMapIndex++){
			if(RankPresent == RankMap[RankMapIndex][0]){
				for (RankIdx8 = 4; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++){				
					if (DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ){
						SetVrMap(PeiServices, pPCIPPI,DramAttr, RankIdx8, RankMap[RankMapIndex][RankIdx8 -3], TRUE);					
					}
					else
					{
						SetVrMap(PeiServices, pPCIPPI,DramAttr, RankIdx8, RankMap[RankMapIndex][RankIdx8 -3], FALSE);
					}
				}
			}
		}
		
	
	}


//to see if all the Rank have the same size
BOOLEAN CheckRankSizeEqual(IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8  RankIdx8;
	UINT16  RankSize;

	RankSize = 0;
	for(RankIdx8 = 0; RankIdx8 < ASIA_MAX_RANKS; RankIdx8++){
		if ( DramAttr->RankPresent[DramAttr->AttrNo] & ( 1 << RankIdx8) ){
			if(RankSize == 0){
				RankSize = DramAttr->RankInfo[DramAttr->AttrNo][RankIdx8].RankSize;
				continue;
			}
			if(RankSize != DramAttr->RankInfo[DramAttr->AttrNo][RankIdx8].RankSize)
				return FALSE;
		}
	}
	return TRUE;
}


/*
 *Purpose: 
 *	Set VR interleave
 */
VOID SetVRInterleave(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN ASIA_NB_CONFIGURATION *NbCfg,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8	   RankIdx8 = 0;
	UINT16     EndAddr = 0;
	BOOLEAN    SameRankSize;
	UINT64     Address;   

	
	//Set channel decode 
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
	//dual channel
	if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0 && DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0)
	{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSINGLECH, 0);
	}
	//single channel
	else
	{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSINGLECH, D0F3_RSINGLECH);
	}


	//set bankgroup bit 0 select function
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);
	if (DramAttr->ConfigData.BankGroupBit0Decode == BG_DECODE_A7_A14)
	{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBG0DEC, 0);
	}
	else
	{
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBG0DEC, D0F3_RBG0DEC);
	}



	//set VR Interleave disable
	DramAttr->VRInterleave = FALSE;
	SameRankSize = FALSE;
	if (DramAttr->ConfigData.VRIntlv == VRANK_INTERLEAVE_AUTO) {
		
		SameRankSize = CheckRankSizeEqual(PeiServices,DramAttr);
		if (SameRankSize){
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"VRInterleave Enable\n"));
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ENDING_ADR);
			EndAddr = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_REND7_37_24; //unit: 16MB      
			EndAddr >>= 2; //unit: 64MB

			switch (DramAttr->RankPresent[DramAttr->AttrNo]){			
			case 0x0F:			
				//set flag
				DramAttr->VRInterleave = TRUE;
				// Set VR Rank 0~3 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 4; RankIdx8++) {
					Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000); //RX108-RX10B        
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr); //RX100-RX103
				}

				// Set VR interleave address and enable               

				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R1C4RINLVEN, D0F3_R1C4RINLVEN);
				break;

			case 0x03:
			case 0x0C:
			case 0x05:
				DramAttr->VRInterleave = TRUE;      			
				// Set VR Rank 0~1 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 2; RankIdx8++) {
                    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000);   //RX108-RX109        
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr);//RX100-RX101
				}
				
				// Set VR interleave address and enable
               

				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R1C2RINLVEN, D0F3_R1C2RINLVEN);
				break;		
				
			case 0XF0:			
				//Channel B
                //set flag
				DramAttr->VRInterleave = TRUE;
				// Set VR Rank 4~7 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 4; RankIdx8++) {
					Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK4_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000); //RX10C-RX10F        
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK4_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr);//RX104-RX107
				}
				
				// Set VR interleave address and enable
              

				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R1C4RINLVEN, D0F3_R1C4RINLVEN);
				break;		
				
			case 0X30:
			case 0xC0:
			case 0x50:
				DramAttr->VRInterleave = TRUE;      			
				// Set VR Rank 4~5 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 2; RankIdx8++) {
                    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK4_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000);  //RX10C-RX10D        
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK4_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr); 
				}
				
				// Set VR interleave address and enable
              
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R1C2RINLVEN, D0F3_R1C2RINLVEN);
				break;			
				
			case 0x11:
			case 0x44:
				DramAttr->VRInterleave = TRUE;      			
				// Set VR Rank 0,4 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 8; RankIdx8 += 4) {
                    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000);   //RX10C-RX10D        
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr); 
				}
				
				// Set VR interleave address and enable               

				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R2C1RINLVEN, D0F3_R2C1RINLVEN);
				break;			
				
			case 0x33:
			case 0xCC:
			case 0x55:
				DramAttr->VRInterleave = TRUE;      			
				// Set VR Rank 0,1,4,5 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 2; RankIdx8++) {
                    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000);    
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr); 

					Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK4_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000);    
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK4_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr); 
				}
				
				// Set VR interleave address and enable
              
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R2C2RINLVEN, D0F3_R2C2RINLVEN);
				break; 				
			case 0xFF:
                //Channel A & Channel B exist  
                DramAttr->VRInterleave = TRUE;
				// Set VR Rank 0~7 to the same begin/end address
				for (RankIdx8 = 0; RankIdx8 < 8; RankIdx8++) {
					Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIdx8 * 2);
                    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0BEG_37_26, 0x0000);      
		            Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,
			                                 D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIdx8 * 2);
		            AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDVR0END_37_26, EndAddr);
				}
				// Set VR interleave address and enable
              

				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);  
                AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_R2C4RINLVEN, D0F3_R2C4RINLVEN);
				break;						
			
			default:
				break;					
			}
		}
		
	}


	if(DramAttr->VRInterleave == FALSE)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"VRInterleave Disable\r\n"));
	}
	

	//Set channel decode Based on GFX Enable or Not
	if(NbCfg->UMAEn)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"UMA Enable, Using A8^A9 as RA2\n"));
		//Channel Decode Use A8^A9
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);

		//Set Internal GFX channel ; If channel interleave disable, Set IGD channel as high address channel for Frame Buffer
		if(DramAttr->ChADIMMNumber[DramAttr->AttrNo] != 0 && DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0 && DramAttr->VRInterleave) 
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RCHLVCTL_1_0, 0x00);	
		else if(DramAttr->ChBDIMMNumber[DramAttr->AttrNo] != 0)
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RCHLVCTL_1_0, BIT5 | BIT4);
		else
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RCHLVCTL_1_0, BIT5); 

		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RNEWCHDEC, D0F3_RNEWCHDEC);
	}
	else
	{
		if (DramAttr->ConfigData.CHdecode == DRAM_CH_DECODE_A8_A9)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Using A8^A9 as RA2\n"));

			//Channel Decode Use A8^A9
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);

			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RNEWCHDEC, D0F3_RNEWCHDEC);
		}
		else if (DramAttr->ConfigData.CHdecode == DRAM_CH_DECODE_A8_A9_A12_A13_A18_A19 || DramAttr->ConfigData.CHdecode == DRAM_CH_DECODE_AUTO)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Using A8^A9^A12^A13^A18^A19 as RA2\n"));

			//Channel Decode A8^A9^A12^A13^A18^A19 as RA2
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
			AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RNEWCHDEC, 0);
		}
		
	}



 
	

}


