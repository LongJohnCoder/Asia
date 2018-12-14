
#include "Hardcode.h"


extern UINT8 TxVrefTable[];
extern TX_VREF_TBL TxVrefTableWholt[74];


extern VOID Rx_Vref_SetVal_ByByte(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 RxVrefValue[],
	IN UINT8 VrefMode);

extern VOID TriggerLoadReg(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
	);
VOID DumpRxVrefAndTxVref
	(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr);	

extern VOID DRAMIOCTL(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8   IOTimingMode,
	IN UINT8   IOSelectionMode,// manul mode(W/R) or calibration mode(R)
	IN BOOLEAN IsWrite,
	IN UINT8   RankIndex,//RankIndex cha:(0->3) chb:(4->7)
	IN UINT8   ByteIndex,
	IN UINT8   BitSelect, //mask!!! 0x01 for bit0, 0x02 for bit1,0x03 for bit0 and bit1 ....
	IN UINT8   IsPos,   // use for TX DQSO/DQSI phase select
	IN OUT UINT16  *Value16);

extern EFI_STATUS SwSetTxVref(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 VrefRange,
	IN UINT32 VrefDQ);
	
extern VOID Enable_Disable_Vref_Overlap(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN BOOLEAN Status);

extern VOID Enable_Disable_Vref_Coarse_Mode(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN BOOLEAN Status);

extern VOID SetVrefRange(
	IN EFI_PEI_SERVICES **PeiServices,
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
	#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
	#endif
	IN DRAM_ATTRIBUTE *DramAttr);


extern VOID Rx_Vref_ClearModeStatus(	
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);









void Setting_RxVref_Value_Rx(
	EFI_PEI_SERVICES **PeiServices, 
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
    PEI_PCI_CFG_PPI *pPCIPPI,
#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	DRAM_ATTRIBUTE *DramAttr)
{
	UINT32 Index;
	UINT8 ByteIndex;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Beginning RxVref HardCode\r\n"));
	DramAttr->CHAOverlap = VREF_Overlap_Tbl[0]; //for S52 print 
	DramAttr->CHBOverlap = VREF_Overlap_Tbl[1];
	DramAttr->CHACoarseMode = VREF_Coarse_Tbl[0]; //for S52 print 
	DramAttr->CHBCoarseMode = VREF_Coarse_Tbl[1];	
	Rx_Vref_ClearModeStatus(PeiServices,pPCIPPI,DramAttr); // clear for SIDRAMTbl May SET this bit.	
	for(ByteIndex = 0;ByteIndex < ASIA_MAX_BYTES;ByteIndex++){
		if(VREF_Overlap_Tbl[0]&(1<<ByteIndex)){
			Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,TRUE); // 0 indicate CHA.
		}
		if(VREF_Coarse_Tbl[0]&(1<<ByteIndex)){
			Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,0,ByteIndex,TRUE); // 0 indicate CHA.
		}
		if(VREF_Overlap_Tbl[1]&(1<<ByteIndex)){
			Enable_Disable_Vref_Overlap(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,TRUE); // 4 indicate CHB.
		}
		if(VREF_Coarse_Tbl[1]&(1<<ByteIndex)){
			Enable_Disable_Vref_Coarse_Mode(PeiServices, pPCIPPI, DramAttr,4,ByteIndex,TRUE); // 4 indicate CHB.
		}
	}	
	for (Index = 0; Index < Rx_RxVref_Value_Tbl_Items; Index++)
	{
		if (Rx_RxVref_Value_Tbl[Index].Channel == CHA_RXTXHARDCODE)
		{
			if (Rx_RxVref_Value_Tbl[Index].Flag == 0)
				continue;
			else
			{
				Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr, 
					0, 
					Rx_RxVref_Value_Tbl[Index].ByteIndex,
					&Rx_RxVref_Value_Tbl[Index].ValueBit[0],
					VREF_FINE_MODE);
			}
		}
		else
		{
			if (Rx_RxVref_Value_Tbl[Index].Flag == 0)
				continue;
			else
			{
				Rx_Vref_SetVal_ByByte(PeiServices, pPCIPPI, DramAttr, 
					4, 
					Rx_RxVref_Value_Tbl[Index].ByteIndex,
					&Rx_RxVref_Value_Tbl[Index].ValueBit[0],
					VREF_FINE_MODE);
			}
		}
	}
	SetVrefRange(PeiServices,pPCIPPI,DramAttr);
	TriggerLoadReg(PeiServices, DramAttr);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Beginning RxVref HardCode\r\n"));
}

void Setting_DQSI_Value_Rx(
	EFI_PEI_SERVICES **PeiServices, 
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
    PEI_PCI_CFG_PPI *pPCIPPI,
#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	DRAM_ATTRIBUTE *DramAttr)
{
	UINT32 Index;
	UINT8 BitIndex;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Beginning DQSI HardCode\r\n"));
	for (Index = 0; Index < Rx_DQSI_Value_Tbl_Items; Index++)
	{
		if (Rx_DQSI_Value_Tbl[Index].Channel == CHA_RXTXHARDCODE)
		{
			if (Rx_DQSI_Value_Tbl[Index].Flag == 0)
				continue;
			else
			{
				if (Rx_DQSI_Value_Tbl[Index].POSorNEG == 1) // POS
				{
					for (BitIndex = 0; BitIndex < 8; BitIndex++)
					{
						DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 
							Rx_DQSI_Value_Tbl[Index].RankIndex, 
							Rx_DQSI_Value_Tbl[Index].ByteIndex, 
							1 << BitIndex, 
							IO_POS, 
							&Rx_DQSI_Value_Tbl[Index].ValueBit[BitIndex]);
					}
				}
				else //NEG
				{
					for (BitIndex = 0; BitIndex < 8; BitIndex++) 
					{
						DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 
							Rx_DQSI_Value_Tbl[Index].RankIndex, 
							Rx_DQSI_Value_Tbl[Index].ByteIndex, 
							1 << BitIndex, 
							IO_NEG, 
							&Rx_DQSI_Value_Tbl[Index].ValueBit[BitIndex]);
					}
				}
			}
		}
		else
		{
			if (Rx_DQSI_Value_Tbl[Index].Flag == 0)
				continue;
			else
			{
				if (Rx_DQSI_Value_Tbl[Index].POSorNEG == 1) // POS
				{
					for (BitIndex = 0; BitIndex < 8; BitIndex++)
					{
						DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 
							Rx_DQSI_Value_Tbl[Index].RankIndex + 4, 
							Rx_DQSI_Value_Tbl[Index].ByteIndex, 
							1 << BitIndex, 
							IO_POS, 
							&Rx_DQSI_Value_Tbl[Index].ValueBit[BitIndex]);
					}
				}
				else //NEG
				{
					for (BitIndex = 0; BitIndex < 8; BitIndex++) 
					{
						DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 
							Rx_DQSI_Value_Tbl[Index].RankIndex + 4, 
							Rx_DQSI_Value_Tbl[Index].ByteIndex, 
							1 << BitIndex, 
							IO_NEG, 
							&Rx_DQSI_Value_Tbl[Index].ValueBit[BitIndex]);
					}
				}
			}
		}
	}

	TriggerLoadReg(PeiServices, DramAttr);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Ending DQSI HardCode\r\n"));
}


void Setting_Timing_Value_TxRx(
	EFI_PEI_SERVICES **PeiServices, 
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
    PEI_PCI_CFG_PPI *pPCIPPI,
#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	DRAM_ATTRIBUTE *DramAttr,
	RXTXTIMING Rx_Tx_Value_Tbl[],
	IN UINT32 Items)
{
	UINT32 Index;
	UINT8 ByteIndex;
	
	UINT16 Wholet;
	UINT16 Phase;

	UINT8 TotalByte;
	
	TotalByte = 9;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Beginning Using For TxRx Timing Value HardCode\r\n"));


	for (Index = 0; Index < Items; Index++)
	{
		if (Rx_Tx_Value_Tbl[Index].Channel == CHA_RXTXHARDCODE)
		{
			if (Rx_Tx_Value_Tbl[Index].Flag == 0)
				continue;
			else
			{
				switch (Rx_Tx_Value_Tbl[Index].Name)
				{
					case TNI_RXTXHARDCODE:
					{
						for (ByteIndex = 0; ByteIndex < TotalByte; ByteIndex++)
						{
							Wholet = ((Rx_Tx_Value_Tbl[Index].Value[ByteIndex]& 0xFF00) >> 8);	
							Phase  = (Rx_Tx_Value_Tbl[Index].Value[ByteIndex] & 0xFF);	
							DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Wholet);
							DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase);
						}
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
						break;
					}	
					case DQSO_RXTXHARDCODE:
					{
						for (ByteIndex = 0; ByteIndex < TotalByte; ByteIndex++)
						{
							Wholet = ((Rx_Tx_Value_Tbl[Index].Value[ByteIndex]& 0xFF00) >> 8);	
							Phase  = (Rx_Tx_Value_Tbl[Index].Value[ByteIndex] & 0xFF);	

							DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Wholet);
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase);
						}
						break;
					}
					case DQO_RXTXHARDCODE:
					{
						for (ByteIndex = 0; ByteIndex < TotalByte; ByteIndex++)
						{
							Wholet = ((Rx_Tx_Value_Tbl[Index].Value[ByteIndex]& 0xFF00) >> 8);	
							Phase  = (Rx_Tx_Value_Tbl[Index].Value[ByteIndex] & 0xFF);	

							DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Wholet);
							DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase);

						}
						break;
					}
					case TXVREF_RXTXHARDCODE:
					{					
						if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << (Rx_Tx_Value_Tbl[Index].RankIndex)) ){
							if(!(TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])] & 0x40)) 
								SwSetTxVref(PeiServices, pPCIPPI, DramAttr, Rx_Tx_Value_Tbl[Index].RankIndex, VREF_RANGE1, TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x3F);
							else 
								SwSetTxVref(PeiServices, pPCIPPI, DramAttr, Rx_Tx_Value_Tbl[Index].RankIndex, VREF_RANGE2, TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x3F);
						}
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "S20 Rank %02X TxVref Value is (TxVrefIndex %0x : TxVrefRange %0x : TxVrefValue %0x)<========>%d.%d%%  \n", //DKS -20161221 modify
									Rx_Tx_Value_Tbl[Index].RankIndex, 
									(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0]), 
									((TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x40)>>6) + 1, 
									TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x3F,
									TxVrefTableWholt[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])].TxVrefValuePercent / 100,
									TxVrefTableWholt[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])].TxVrefValuePercent % 100));
						DramAttr->TxVrefInfo[Rx_Tx_Value_Tbl[Index].RankIndex].TxVrefCENTER = (UINT8)Rx_Tx_Value_Tbl[Index].Value[0];		
						break;
					}
				}
			}
		}
		else
		{
			if (Rx_Tx_Value_Tbl[Index].Flag == 0)
				continue;
			else
			{
				switch (Rx_Tx_Value_Tbl[Index].Name)
				{
					case TNI_RXTXHARDCODE:
					{
						for (ByteIndex = 0; ByteIndex < TotalByte; ByteIndex++)
						{
							Wholet = ((Rx_Tx_Value_Tbl[Index].Value[ByteIndex]& 0xFF00) >> 8);	
							Phase  = (Rx_Tx_Value_Tbl[Index].Value[ByteIndex] & 0xFF);	

							DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex + 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Wholet);
							DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex + 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase);
						}
						break;
					}	
					case DQSO_RXTXHARDCODE:
					{
						for (ByteIndex = 0; ByteIndex < TotalByte; ByteIndex++)
						{
							Wholet =  (UINT8)((Rx_Tx_Value_Tbl[Index].Value[ByteIndex]& 0xFF00) >> 8);	
							Phase = (UINT8)(Rx_Tx_Value_Tbl[Index].Value[ByteIndex] & 0xFF);	

							DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex + 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Wholet);
							DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex + 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase);
						}
						break;
					}
					case DQO_RXTXHARDCODE:
					{
						
						for (ByteIndex = 0; ByteIndex < TotalByte; ByteIndex++)
						{
							Wholet =  (UINT8)((Rx_Tx_Value_Tbl[Index].Value[ByteIndex]& 0xFF00) >> 8);	
							Phase = (UINT8)(Rx_Tx_Value_Tbl[Index].Value[ByteIndex] & 0xFF);	

							DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex + 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Wholet);
							DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, Rx_Tx_Value_Tbl[Index].RankIndex + 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase);
						}
						break;
					}
					case TXVREF_RXTXHARDCODE:
					{
						if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << (Rx_Tx_Value_Tbl[Index].RankIndex + 4)) ){
							if(!(TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])] & 0x40)) 
								SwSetTxVref(PeiServices, pPCIPPI, DramAttr, Rx_Tx_Value_Tbl[Index].RankIndex + 4, VREF_RANGE1, TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x3F);
							else 
								SwSetTxVref(PeiServices, pPCIPPI, DramAttr, Rx_Tx_Value_Tbl[Index].RankIndex + 4, VREF_RANGE2, TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x3F);
						}
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "S20 Rank %02X TxVref Value is (TxVrefIndex %0x : TxVrefRange %0x : TxVrefValue %0x)<========>%d.%d%%  \n", //DKS -20161221 modify
									Rx_Tx_Value_Tbl[Index].RankIndex + 4, 
									(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0]), 
									((TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x40)>>6) + 1, 
									TxVrefTable[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])]&0x3F,
									TxVrefTableWholt[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])].TxVrefValuePercent / 100,
									TxVrefTableWholt[(UINT8)(Rx_Tx_Value_Tbl[Index].Value[0])].TxVrefValuePercent % 100));
						DramAttr->TxVrefInfo[Rx_Tx_Value_Tbl[Index].RankIndex+4].TxVrefCENTER = (UINT8)Rx_Tx_Value_Tbl[Index].Value[0];
						break;
					}
				}
			}
		}
	}
	
	TriggerLoadReg(PeiServices, DramAttr);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Ending Using For TxRx Timing Value HardCode\r\n"));
}
