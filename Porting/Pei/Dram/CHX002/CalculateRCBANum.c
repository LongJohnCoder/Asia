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


#include "Pei.h"
#include "Draminit.h"
#include "PeiLib.h"
#include "CalculateRCBANum.h"

EFI_STATUS Sizing(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
)
{
	UINT8  RankIndex;
	ASIA_SPD_DATA *SpdData;
	UINT64 RankSize;
    //MCM-20180428 -ONLY FOR SCAN DRAM IOTiming -S
    if (DramAttr->ConfigData.ScanIOTiming)
    {
        PEI_DEBUG((PeiServices, EFI_D_INFO, "ScanIOTiming Enable--MCM DEBUG\r\n"));

        switch (DramAttr->RankPresent[DramAttr->AttrNo])
        {
        case 0x11:
        case 0x44: /* 00 01 00 01   &   01 00 01 00 */
        {
            DramAttr->ConfigData.LimitRankSize = LIMIT_SIZE_512M;
            DramAttr->ConfigData.VRIntlv = VRANK_INTERLEAVE_DISABLED;
           // DramAttr->ConfigData.ChannelIntlv = CHAN_INTERLEAVE_DISABLED;
            PEI_DEBUG((PeiServices, EFI_D_INFO, "Limit_Size= %d Rank_Interleave=%d \r\n", DramAttr->ConfigData.LimitRankSize, DramAttr->ConfigData.VRIntlv));
            break;
        }
        case 0x33:
        case 0xCC:
        case 0x55: /* 00 11 00 11   &   11 00 11 00    &   01 01 01 01 */
        {
            DramAttr->ConfigData.LimitRankSize = LIMIT_SIZE_256M;
            DramAttr->ConfigData.VRIntlv = VRANK_INTERLEAVE_DISABLED;
           // DramAttr->ConfigData.ChannelIntlv = CHAN_INTERLEAVE_DISABLED;
            PEI_DEBUG((PeiServices, EFI_D_INFO, "Limit_Size= %d Rank_Interleave=%d \r\n", DramAttr->ConfigData.LimitRankSize, DramAttr->ConfigData.VRIntlv));
            break;
        }
        case 0xFF: /* 11 11 11 11 */
        {
            DramAttr->ConfigData.LimitRankSize = LIMIT_SIZE_128M;
            DramAttr->ConfigData.VRIntlv = VRANK_INTERLEAVE_DISABLED;
            //DramAttr->ConfigData.ChannelIntlv = CHAN_INTERLEAVE_DISABLED;
            PEI_DEBUG((PeiServices, EFI_D_INFO, "Limit_Size= %d Rank_Interleave=%d \r\n", DramAttr->ConfigData.LimitRankSize, DramAttr->ConfigData.VRIntlv));
            break;
        }
        default:
        {
            PEI_DEBUG((PeiServices, EFI_D_INFO, "Slot - Error!\r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "Usage: \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "************************************ \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "1S1R - Slot1 + Slot3 \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "1S1R - Slot2 + Slot4 \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "1S1R - Slot1 + Slot2 + Slot3 + Slot4 \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "************************************ \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "1S2R - Slot1 + Slot3 \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "1S2R - Slot2 + Slot4 \r\n"));
            PEI_DEBUG((PeiServices, EFI_D_INFO, "1S2R - Slot1 + Slot2 + Slot3 + Slot4 \r\n"));
        }
        }
    }

	//clear DramAttr->Rank[RankIndex].RankSize to 0
	for (RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex++)
		DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize = 0;

	for (RankIndex = 0; RankIndex < ASIA_MAX_RANKS; RankIndex ++){
		if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex)){
			SpdData = &(DramAttr->SpdData[DramAttr->AttrNo][RankIndex >> 1]);
			//Row address bits SPD byte5[5:3]
			DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RowNumber = ((SpdData->Buffer[DDR4_SPD_ADDRESSING] >> 3 ) & 0x07) + 12;
			//Col address bits SPD byte5[2:0]
			DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].ColNumber = (SpdData->Buffer[DDR4_SPD_ADDRESSING] & 0x07) + 9;
			//Bank address bits SPD byte4[5:4]
			DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].BankNumber = ((SpdData->Buffer[DDR4_SPD_DENSITY_BANKS] >> 4) & 0x03) + 2;	
			//Bank Group address bits SPD byte4[7:6]
			DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].BankGroupNumber = ((SpdData->Buffer[DDR4_SPD_DENSITY_BANKS] >> 6) & 0x03);
			RankSize = LShiftU64(1, (DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RowNumber + \
			                        DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].ColNumber + \
			                        DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].BankNumber + \
			                        DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].BankGroupNumber + 3));
				     				DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize = (UINT16)RShiftU64(RankSize, 20); //unit of MB
			if (DramAttr->ConfigData.LimitRankSize == LIMIT_SIZE_128M){
				if (DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize > 128)
					DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize = 128;
			}		     				
			if (DramAttr->ConfigData.LimitRankSize == LIMIT_SIZE_256M){
				if (DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize > 256)
					DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize = 256;
			}
			else if (DramAttr->ConfigData.LimitRankSize == LIMIT_SIZE_512M){
				if (DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize > 512)
					DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize = 512;
			}
			else if (DramAttr->ConfigData.LimitRankSize == LIMIT_SIZE_1024M){
				if (DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize > 1024)
					DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize = 1024;
			}

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%x, BA pin number = %x\n",RankIndex, DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].BankNumber));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%x, CA pin number = %x\n",RankIndex, DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].ColNumber));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%x, RA pin number = %x\n",RankIndex, DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RowNumber));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rank:%x,  RankSize(Unit of M) = %x\n",RankIndex, DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize));
		}
	}

	return EFI_SUCCESS;
}
