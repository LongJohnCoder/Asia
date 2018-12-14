//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
//Ver	Date			Name	Note
//----------------------------------------------------------------------------


#include "DramInit.h" 
#include "DramInfo.h"

EFI_STATUS DramGetInfo(
    IN EFI_PEI_SERVICES           **PeiServices,
    IN EFI_ASIA_DRAM_PPI          *This,
    OUT VOID                      *DramInfo
) 
{ 
    UINT32                   Data;
    UINT8                   Index;
	//UINT32      FakeRegisterValue;
	//UINT16      FakeBegin,FakeEnd;
    UINT16      PciStartAddress;
	DRAM_ATTRIBUTE *pDramAttr;
    ASIA_DRAM_INFO  *pDramInfo = (ASIA_DRAM_INFO*)DramInfo;
	ASIA_DRAM_PEI_PRIVATE_DATA *pPrvData = NULL;
	UINT64 Address;
	
    pPrvData = GET_PRIVATE_DATA_FROM_THIS(This);
	pDramAttr = (DRAM_ATTRIBUTE *)pPrvData->DramAttr;

    if (pDramInfo == NULL)
        return EFI_INVALID_PARAMETER;

    (*PeiServices)->SetMem(pDramInfo, sizeof(ASIA_DRAM_INFO), 0x00);

	//LGE201707011 NO USE get rank map info
	//pDramInfo->RankMap = pDramAttr->RankPresent;

	//get spd data
	for (Index = 0; Index < ASIA_MAX_SOCKETS; Index++){
	   pDramInfo->Spd[Index].SpdPresent = pDramAttr->SpdData[0][Index].SpdPresent;
	   (*PeiServices)->CopyMem(pDramInfo->Spd[Index].Buffer,
	   	                       pDramAttr->SpdData[0][Index].Buffer,
	   	                       sizeof(UINT8) * SPD_SIZE);
	}

    //get rank Info
    for (Index = 0; Index < ASIA_MAX_RANKS; Index++){
		pDramInfo->RankInfo[Index].BankNumber = pDramAttr->RankInfo[0][Index].BankNumber;
		pDramInfo->RankInfo[Index].ColNumber = pDramAttr->RankInfo[0][Index].ColNumber;
		pDramInfo->RankInfo[Index].RowNumber = pDramAttr->RankInfo[0][Index].RowNumber;
		pDramInfo->RankInfo[Index].RankSize = pDramAttr->RankInfo[0][Index].RankSize;
		
    }


    //get DRAM Freq
    switch(pDramAttr->DramFreq){
		case DRAM_FREQ_800:
			pDramInfo->DramFreq = 800;
			break;
		case DRAM_FREQ_1066:
			pDramInfo->DramFreq = 1066;
			break;
		case DRAM_FREQ_1333:
			pDramInfo->DramFreq = 1333;
			break;
		case DRAM_FREQ_1600:
			pDramInfo->DramFreq = 1600;
			break;
		case DRAM_FREQ_1866:
			pDramInfo->DramFreq = 1866;
			break;
		case DRAM_FREQ_2133:
			pDramInfo->DramFreq = 2133;
			break;
		case DRAM_FREQ_2400:
			pDramInfo->DramFreq = 2400;
			break;
		case DRAM_FREQ_2666:
			pDramInfo->DramFreq = 2666;
			break;
		case DRAM_FREQ_2933:
			pDramInfo->DramFreq = 2933;
			break;
		case DRAM_FREQ_3200:
			pDramInfo->DramFreq = 3200;
			break;
		default:
			pDramInfo->DramFreq = 800;
	}

   //get Pci Start address
   PciStartAddress = AsiaPciRead16 (CHX002_HIF | D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
   PciStartAddress = (PciStartAddress & 0xFFF0) >> 4;
   PEI_DEBUG ((PeiServices, EFI_D_INFO, "Pci Start Address:%x\n",PciStartAddress));
   pDramInfo->PciStartAddress = PciStartAddress;
	
    //get UMA Size
   Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
   Data = AsiaPcieRead32(pDramAttr->PcieBaseAddress, Address);//D0F3Rx124
   
   pDramInfo->UMASize =0;
   //if UMA is  enable
   if (Data & D0F3_RGFXEN){
       Data = (Data & D0F3_RFBSZ_2_0) >> 4;	
      if (Data > 0x4)
         pDramInfo->UMASize = 1 << ((Data&0x3) + 2); //in unit of M
      else
         pDramInfo->UMASize = 1 << (Data + 5); //in unit of M
   }
   
   //get TSeg size
   Data = (AsiaPciRead8(CHX002_HIF|D0F2_SMM)&D0F2_SM_SIZE_1_0);
   if (Data == 0)
   	  pDramInfo->SmmTSegSize = 1; // 1M Smm
   else if (Data == 1)
   	  pDramInfo->SmmTSegSize = 2; // 2M Smm
   else if (Data == 2)
   	  pDramInfo->SmmTSegSize = 4; // 4M Smm
   else
   	  pDramInfo->SmmTSegSize = 8; // 8M Smm
	  
#ifdef ZX_TXT_SUPPORT
   Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DMA_PROTECTION_CTL);
   Data = (UINT32)(AsiaPcieRead16(pDramAttr->PcieBaseAddress, Address));
   pDramInfo->DPRSize = (UINT16)(Data & D0F3_DPR_SIZE_7_0) >> 4;
   PEI_DEBUG((PeiServices, EFI_D_INFO, "pDramInfo->DPRSize = 0x%x\n", pDramInfo->DPRSize));
#endif

#if 0
   //LGE20160619 Add 4 AC Timing report for SETUP   
   //CL ,D0F3Rx159[4:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_II); 
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RCL_4_0;
   pDramInfo->DramCL = Temp8 + DDR4_MIN_CL;
   
   //Trp
   //D0F3Rx15B[4:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRP_4_0;
   pDramInfo->DramTrp = Temp8 + DDR4_MIN_TRP;
   //TRCD
   //D0F3Rx15A[7:3]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_III);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRCD_4_0;
   Temp8 >>= 3;
   pDramInfo->DramTrcd = Temp8 + DDR4_MIN_TRCD;

   //TRAS
   //D0F3Rx15C[7:3]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_V);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRAS_4_0;
   Temp8 >>= 3;
   pDramInfo->DramTras = Temp8 + DDR4_MIN_TRAS;

   //DramTrfc
   //D0F3Rx15F[5:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_VIII);
   Temp16 = (UINT16)AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRFC_6_0;
   Temp16 <<= 3;
   pDramInfo->DramTrfc = Temp16 + DDR4_MIN_TRFC ; //(30+8n)T

   //DramTrrd
   //D0F3Rx15D[2:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_VI);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRRD_2_0;
   pDramInfo->DramTrrd = Temp8 + DDR4_MIN_TRRD;

   //DramTwr
   //D0F3Rx15C[2:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_V);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RWRCOV_2_0;
   Temp8 <<= 1;
   pDramInfo->DramTwr = Temp8 + DDR4_MIN_TWR;//(2n+10)T

   //DramTwtr
   //D0F3Rx15E[2:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_VII);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTWTR_2_0;
   pDramInfo->DramTwtr = Temp8 + DDR4_TWTR_GAP;

   //DramTrtp
   //D0F3Rx15B[7:5]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRTP_2_0;
   Temp8 >>= 5;
   pDramInfo->DramTrtp = Temp8 + DDR4_MIN_TRTP;

   //DramCWL
   //D0F3Rx158[4:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_I);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RCWL_4_0;
   pDramInfo->DramCWL = Temp8 + DDR4_MIN_CWL;

   //DramTfawx
   //D0F3Rx15D[7:4]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_VI);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTFAWX_3_0;
   Temp8 >>= 4;
   pDramInfo->DramTfawx = Temp8 + DDR4_MIN_TFAWX;

   //DramTcke
   //D0F3Rx15A[2:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_III);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTCKE_2_0;
   pDramInfo->DramTcke = (Temp8 + 1)*2;//2(n+1)T

   //DramTxp
   //D0F3Rx162[14:12]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_X);
   Temp16 = AsiaPcieRead16(pDramAttr->PcieBaseAddress, Address) & D0F3_RTXPD_2_0;
   Temp16 >>= 12;
   pDramInfo->DramTxp =(UINT8) (Temp16+2)*2;//2(n+2)T

   //DramTrrd_SG
   //D0F3Rx164[7:5]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_I);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTRRD_SG_2_0;
   Temp8 >>= 5;
   pDramInfo->DramTrrd_SG = Temp8 + DDR4_MIN_TRRD_SG;
   
   //DramTccd_SG
   //D0F3Rx164[4:2]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_I);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTCCD_SG_2_0;
   Temp8 >>= 2;
   pDramInfo->DramTccd_SG = Temp8 + DDR4_MIN_TCCD_SG;

   //DramTwtr_SG
   //D0F3 RX165[7:5]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTWTR_SG_2_0;
   Temp8 >>= 5;
   pDramInfo->DramTwtr_SG = Temp8 + DDR4_MIN_TWTR_SG;

   //DramCAL
   //D0F3Rx165[4:2]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DDR4_TIMING_FOR_ALL_RANKS_II);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RCAL_2_0;
   Temp8 >>= 2;
   if(Temp8 > 0)
   Temp8 += DDR4_CAL_GAP;
   if (Temp8 == 7)
   Temp8 = 8;
   pDramInfo->DramCAL = Temp8 ;   // 000:0T 001:3T 010:4T 011:5T 100:6T 101;8T

   //DramCRC_RWCL
   //D0F3Rx170[5:4]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_III);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RWCL_1_0;
   Temp8 >>= 4;
   pDramInfo->DramCRC_RWCL = Temp8 + DDR4_RWCL_GAP;

   //DramTCRC_Alert
   //D0F3Rx176[5:0]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_RETRY_CTL_I);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTCRC_ON_5_0;
   pDramInfo->DramTCRC_Alert = Temp8 + DDR4_MIN_CRC_ALERT;

   //DramTPAR_Alert
   //D0F3Rx177[7:3]
   Address = AsiaPciAddress(CHX001_HB_BUS, CHX001_HB_DEV, CHX001_DRAM_FUN, D0F3_DRAM_RETRY_CTL_II);
   Temp8 = AsiaPcieRead8(pDramAttr->PcieBaseAddress, Address) & D0F3_RTPAR_ALERT_ON_4_0;
   Temp8 >>= 3;
   pDramInfo->DramTPAR_Alert = Temp8 + DDR4_MIN_PAR_ALERT;
#endif
   pDramInfo->EfuseData[0] = pDramAttr->EfuseData[0];
   pDramInfo->EfuseData[1] = pDramAttr->EfuseData[1];

   return EFI_SUCCESS;
}
