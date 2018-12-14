//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

///
///
#include "Pei.h"
#include "Draminit.h"
#include "AsiaNbPeim.h"
#include "DRAMInitTable.h"


STATIC ASIA_IO_TABLE_6432_REV D0F3_SafeTBL[]={
	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x218<<32)),	0xffff3c00,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x21c<<32)),	0xffffffff,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x220<<32)),	0x3cffff,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x224<<32)),	0xffffffff,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x228<<32)),	0xffffffff,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x22c<<32)),	0x3f,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x234<<32)),	0x1ff0000,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|((UINT64)0x238<<32)),	0x1ff,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x170),	0x0900,	0x0900},

	{0xFF,	0x00,	0x00,	0x00,	0x00} 
};


STATIC ASIA_IO_TABLE_6416_REV mPCIEDRAMInitTbl[] = {
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK0_ENDING_ADR_37_26) << 32),				D0F3_RDVR0END_37_26, 0x0001,		//0x100
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK1_ENDING_ADR_37_26) << 32),				D0F3_RDVR1END_37_26, 0x0002,		//0x101
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK2_ENDING_ADR_37_26) << 32),				D0F3_RDVR2END_37_26, 0x0003,		//0x102
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK3_ENDING_ADR_37_26) << 32),				D0F3_RDVR3END_37_26, 0x0004,		//0x103
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK4_ENDING_ADR_37_26) << 32),				D0F3_RDVR4END_37_26, 0x0005,		//0x104
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK5_ENDING_ADR_37_26) << 32),				D0F3_RDVR5END_37_26, 0x0006,		//0x105
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK6_ENDING_ADR_37_26) << 32),				D0F3_RDVR6END_37_26, 0x0007,		//0x106
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK7_ENDING_ADR_37_26) << 32),				D0F3_RDVR7END_37_26, 0x0008,		//0x107
	
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK0_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR0BEG_37_26, 0x0000,		//0x108
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK1_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR1BEG_37_26, 0x0001,		//0x109
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK2_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR2BEG_37_26, 0x0002,		//0x10a
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK3_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR3BEG_37_26, 0x0003,		//0x10B
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK4_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR4BEG_37_26, 0x0004,		//0x10C
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK5_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR5BEG_37_26, 0x0005,		//0x10D
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK6_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR6BEG_37_26, 0x0006,		//0x10E
	0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_RANK7_BEGINNING_ADR_37_26) << 32),			D0F3_RDVR7BEG_37_26, 0x0007,		//0x10F
	
	/*0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_MA_MAP_TYPE) << 32),						0xFC, 0xD8, 	//0x11c Rank 0~3 MA Type 6 */
	/*0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_DRAM_MA_MAP_TYPE+1) << 32),					    0x7C, 0x6C, 	//0x11d Rank 4~7 MA Type 6 */
	/*0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_BANK_INTERLEAVE) << 32),			                0x77, 0x11,		//0x120  BA1=A14, BA0=A13*/
	/*0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_BANK_INTERLEAVE+1) << 32),		                0x87, 0x81,		//0x121 BA2 enabled, BA2=A15*/
	/*0x00, 0xFF, CHX002_DRAM|((UINT64)(D0F3_RANK_INTERLEAVE_ADR_SEL_BANK_SCRAMBLE+1) << 32),	0xF0, 0x50      //0x11F  RA0=A17, RA1=A16,   */
};

EFI_STATUS DRAMInitTable(
    IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN DRAM_ATTRIBUTE *DramAttr)
{
   
   PROCESS_NB_PCIE_R6432M_TABLE(DramAttr->PcieBaseAddress,D0F3_SafeTBL,sizeof(D0F3_SafeTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
   PROCESS_NB_PCIE_R6416M_TABLE(DramAttr->PcieBaseAddress,mPCIEDRAMInitTbl,sizeof(mPCIEDRAMInitTbl)/sizeof(ASIA_IO_TABLE_6416_REV));

	
   return EFI_SUCCESS;
}
