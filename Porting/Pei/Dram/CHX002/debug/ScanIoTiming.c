#include"DramDebug.h"
#include "PeiLib.h"


#define pattern456 0x02D58480
#define MemoryTest_Size (4 * 1024)	// 4K
#define MemoryTest_Start (0x100000	+ (32 * 1024)) //	1M +32K
#define MemoryRW_repeat_Number	1

#define DQSO_INDEX_MAX 8*0x40
#define DQO_INDEX_MAX 8*0x40
#define TNI_INDEX_MAX 15*0x40

extern unsigned long simple_strtoul(const char *cp,char **endp,unsigned int base);

extern INTN EFIAPI
AsiaStrnCmp (
  IN      CONST CHAR8               *FirstString,
  IN      CONST CHAR8               *SecondString,
  IN      UINTN                     Length
  );

extern VOID ReadMPR(
	IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 MPRPAGE,
	IN BOOLEAN Enable);

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

extern VOID TriggerLoadReg(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
	);

extern VOID DumpD0F3(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr
		);

/*extern EFI_STATUS SwSetTxVref(*/
	/*IN EFI_PEI_SERVICES **PeiServices,	 */
/*#if (PI_SPECIFICATION_VERSION < 0x00010000) */
	/*IN PEI_PCI_CFG_PPI *pPCIPPI,*/
/*#else*/
	/*IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,*/
/*#endif*/
	/*IN DRAM_ATTRIBUTE *DramAttr,*/
	/*IN UINT8 RankIndex,*/
	/*IN UINT8 VrefRange,*/
	/*IN UINT32 VrefDQ);*/
extern VOID Rx_Vref_SetVal(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 RxVrefValue);

UINT8 Binary2Gray(UINT8 Binary);

extern UINT8 TxVrefTable[74];

extern UINT16 Rx_TNI_Convert_To_Value(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16);

extern UINT16 Tx_DQSO_Convert_To_Value(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16);

extern UINT16 Tx_DQO_Convert_To_Value(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT16 Value16);

extern VOID IndexToValue(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	UINT16 Index, 
	UINT16 *pWholeT, 
	UINT16 *pPhase, 
	UINT16 Flag);



extern VOID HW_DQSO_LCU_2D(
       IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
       IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
       IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
       IN DRAM_ATTRIBUTE *DramAttr) ;

extern VOID HW_TX_WriteLeveling(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr);


VOID MemoryWrite_Test_shift(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN UINT32  TestPattern
)
{
  UINT32	WriteAddress_Start = MemoryTest_Start;
  UINT32	WriteAddress;
  UINT32	Data32;
  UINT32	Repeat;

//	PEI_DEBUG((PeiServices, EFI_D_INFO, "Write Address %02X, Data %02X \r\n", DummyReadBase, Buffer32));		
//	PEI_DEBUG((PeiServices, EFI_D_INFO, "Read Address %02X, Data %02X \r\n", DummyReadBase, Buffer32));		

  //Memory test in 1M + N*64K + (32-64K) range only
  for(Repeat = 0; Repeat<MemoryRW_repeat_Number;  Repeat++)
  {
    Data32 = TestPattern;
    for(WriteAddress = WriteAddress_Start; WriteAddress< (WriteAddress_Start+MemoryTest_Size);  WriteAddress+=0x40)
    {
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x00) = Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x04) = Data32;	

      //Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x08) = ~Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x0C) = ~Data32;	

      Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x10) = Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x14) = Data32;	

      //Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x18) = ~Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x1C) = ~Data32;	

      Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x20) = Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x24) = Data32;	

      //Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x28) = ~Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x2C) = ~Data32;	

      Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x30) = Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x34) = Data32;	

      //Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x38) = ~Data32;	
      *(UINT32 volatile *)(UINT32)(WriteAddress+0x3C) = ~Data32;	

      Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
    }
    WriteAddress_Start += 0x100000;
  }

}


BOOLEAN MemoryRead_Test_shift(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,
  IN UINT8	ByteIndex,
  IN UINT32  TestPattern)
{
  UINT32	ReadAddress_Start = MemoryTest_Start;
  UINT32	ReadAddress;
  UINT32	Data32;
  UINT32	Data32Verify;
  UINT32	Repeat;
  UINT32	CheckData32Mask = 0;

  switch(ByteIndex)
  {
    case 0x00:	CheckData32Mask = 0xFF;			break;
    case 0x01:	CheckData32Mask = 0xFF00;			break;
    case 0x02:	CheckData32Mask = 0xFF0000;		break;
    case 0x03:	CheckData32Mask = 0xFF000000;		break;
    case 0x04:	CheckData32Mask = 0xFF;			break;
    case 0x05:	CheckData32Mask = 0xFF00;			break;
    case 0x06:	CheckData32Mask = 0xFF0000;		break;
    case 0x07:	CheckData32Mask = 0xFF000000;		break;
    default:		break;
  }

//	PEI_DEBUG((PeiServices, EFI_D_INFO, "Write Address %02X, Data %02X \r\n", DummyReadBase, Buffer32));		
//	PEI_DEBUG((PeiServices, EFI_D_INFO, "Read Address %02X, Data %02X \r\n", DummyReadBase, Buffer32));		

  ReadAddress_Start = MemoryTest_Start;
  //Memory test in 1M + N*64K + (32-64K) range only
  for(Repeat = 0; Repeat<MemoryRW_repeat_Number;  Repeat++)
  {
    Data32Verify = TestPattern;
    for(ReadAddress = ReadAddress_Start; ReadAddress< (ReadAddress_Start+MemoryTest_Size);  ReadAddress+=0x40)
    {
      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x00);	
    
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x04);	
  
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
      
      //Data32Verify = ((Data32&0x80000000)>>31)|(Data32<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x08);	
    
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x0C);
    
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
  
      Data32Verify = ((Data32Verify&0x80000000)>>31)|(Data32Verify<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x10);	
    
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x14);
    
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
    
      //Data32Verify = ((Data32&0x80000000)>>31)|(Data32<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x18);	
      
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x1C);
      
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
  
      Data32Verify = ((Data32Verify&0x80000000)>>31)|(Data32Verify<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x20);	
    
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x24);
      
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
  
      //Data32Verify = ((Data32&0x80000000)>>31)|(Data32<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x28);	
      
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x2C);
    
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }

      Data32Verify = ((Data32Verify&0x80000000)>>31)|(Data32Verify<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x30);	
      
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x34);
    
        if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
          return FALSE;
      }

      //Data32Verify = ((Data32&0x80000000)>>31)|(Data32<<1);

      if(ByteIndex<4)
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x38);	
      
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
      else
      {
        Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x3C);
    
        if((Data32&CheckData32Mask) != ((~Data32Verify)&CheckData32Mask))
          return FALSE;
      }
    
      Data32Verify = ((Data32Verify&0x80000000)>>31)|(Data32Verify<<1);
    }
    ReadAddress_Start += 0x100000;
  }

  return TRUE;
}



BOOLEAN MemoryTest(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,	
  IN UINT8	ByteIndex)
{
   UINT32 DataPattern = pattern456;
   
   
   MemoryWrite_Test_shift(PeiServices, pPCIPPI, DramAttr, DataPattern);
   if(!MemoryRead_Test_shift(PeiServices, pPCIPPI, DramAttr, ByteIndex, DataPattern))
      return FALSE;
   
   //FIX Memory test BUG 
   //NOTE: Write ~pattern456 is very neccessary, Or else if write fail this time, Read Operation will read data from Last write, and
   // will believe write  success this time which is wrong.
   MemoryWrite_Test_shift(PeiServices, pPCIPPI, DramAttr, ~DataPattern);
   if(!MemoryRead_Test_shift(PeiServices, pPCIPPI, DramAttr, ByteIndex, ~DataPattern))
    return FALSE;

   return TRUE;

}

BOOLEAN MemoryReadTest(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN ReadTest *readtest,
	IN UINT8	ByteIndex)
{
	UINT32	ReadAddress;

	UINT32	Data32;
	UINT32	Data32Verify;
	UINT8   Index = 0;
	UINT32	CheckData32Mask = 0;
	switch(ByteIndex)
	{
		case 0x00:	CheckData32Mask = 0xFF;			break;
		case 0x01:	CheckData32Mask = 0xFF00;			break;
		case 0x02:	CheckData32Mask = 0xFF0000;		break;
		case 0x03:	CheckData32Mask = 0xFF000000;		break;
		case 0x04:	CheckData32Mask = 0xFF;			break;
		case 0x05:	CheckData32Mask = 0xFF00;			break;
		case 0x06:	CheckData32Mask = 0xFF0000;		break;
		case 0x07:	CheckData32Mask = 0xFF000000;		break;
		default:		break;
	}
	ReadAddress =  readtest->ReadAddr;

	for(Index = 0; Index < 0x20; Index += 8){
		if(ByteIndex<4)
		{
			Data32Verify = readtest->Pattern[Index/4];
			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress + Index);	

			if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
				return FALSE;
		}
		else
		{
			Data32Verify = readtest->Pattern[Index/4 + 1];	
			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress + Index + 0x04);	

			if((Data32&CheckData32Mask) != (Data32Verify&CheckData32Mask))
				return FALSE;
		}
	}	
	return TRUE;
}


BOOLEAN MemoryReadTest_ByRWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8    RankIndex,
	IN UINT8	ByteIndex,
	IN UINT8    MprNo)
{
	UINT64 Address;
	UINT8  Index;
	
	UINT64 BeginAddress = 0x0;
	UINT32 Burstlength;
	BOOLEAN ret;
	
#if 0
	UINT8 MprPatternSetting[8];
	UINT8 Bit_Index;
#endif

	UINT8 MprPattern = 0x0;
	UINT64 BeginAddressTmp;

#if 1
	UINT8 DKS_Setting_Tmp[8][8] = {
#if 0
		0x22, 0x84, 0x33, 0x95, 0x6A, 0xCC, 0x7B, 0xDD,      //Micron 2Rx8 16G UDIMM(write 0x55 to MPR3 then use stagger mode read MPR0)
		0x12, 0x88, 0x33, 0xA9, 0x56, 0xCC, 0x77, 0xED,
		0x22, 0x84, 0x33, 0x95, 0x6A, 0xCC, 0x7B, 0xDD,
		0x11, 0x48, 0x33, 0x6A, 0x91, 0xC8, 0xB3, 0xEA,
		0x12, 0x88, 0x33, 0xA9, 0x56, 0xCC, 0x77, 0xED,
		0x22, 0x44, 0x33, 0x55, 0xAA, 0xCC, 0xBB, 0xDD,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x21, 0x44, 0x33, 0x56, 0xA9, 0xCC, 0xBB, 0xDE,
#else
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,     //Micron 1Rx8 8G UDIMM(write 0x55 to MPR3 then use stagger mode read MPR0)
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
		0x11, 0x88, 0x33, 0xAA, 0x55, 0xCC, 0x77, 0xEE,
#endif
	};
#endif

	//Note: Only Use Serial Mode

	/* ***************************************************************************************
	  *	   BG1         BG0       BA1       BA0    A13  A12    A11   A10   A9     A8	 A7	  A6	   A5	A4	 A3 	 A2	 A1	  A0
	  *	15^20	   14^7	  18^23	  17^22	  23	   22	21	 20	   12	11	 10	   9	    8	        7	  6	  5	  4	   3
	  * ***************************************************************************************
	  */
	switch (MprNo)
	{
		case 0:
		{	
			BeginAddress = 0xC60000;   //read MPR0  -->[BA1:BA0] = 00,   [BA1:BA0] = {18^23, 17^22}

			//MprPattern = 0x55;

			if(DramAttr->RegDimm == IS_REG_DIMM)
			{
				//BeginAddress = 0x10060000;   //read MPR3 -->[BA1:BA0] = 11,   [BA1:BA0] = {18^23, 17^22}
				
				MprPattern = 0x00;
			}
			break;
		}
		case 1:
		{	
			BeginAddress = 0x860000;   //read MPR1 -->[BA1:BA0] = 01,   [BA1:BA0] = {18^23, 17^22}

			MprPattern = 0x33;
			
			if((DramAttr->RegDimm == IS_REG_DIMM) || (RankIndex % 2 != 0)) //RDIMM or mirror
			{
				//BeginAddress = 0x10460000;   //read MPR2 -->[BA1:BA0] = 10,   [BA1:BA0] = {18^23, 17^22}

				MprPattern = 0x0F;
			}

			if ((DramAttr->RegDimm == IS_REG_DIMM) && (RankIndex % 2 != 0))
			{
				//BeginAddress = 0x10860000;   //read MPR1 -->[BA1:BA0] = 01,   [BA1:BA0] = {18^23, 17^22}

				MprPattern = 0x33;
			}
			break;
		}
		case 2:
		{	
			BeginAddress = 0x460000;   //read MPR2 -->[BA1:BA0] = 10,   [BA1:BA0] = {18^23, 17^22}

			MprPattern = 0x0F;
			
			if((DramAttr->RegDimm == IS_REG_DIMM) || (RankIndex % 2 != 0))
			{
				//BeginAddress = 0x10860000;   //read MPR1 -->[BA1:BA0] = 01,   [BA1:BA0] = {18^23, 17^22}

				MprPattern = 0x33;
			}
			
			if ((DramAttr->RegDimm == IS_REG_DIMM) && (RankIndex % 2 != 0))
			{
				//BeginAddress = 0x10460000;   //read MPR2 -->[BA1:BA0] = 10,   [BA1:BA0] = {18^23, 17^22}

				MprPattern = 0x0F;
			}
			break;
		}
		case 3:
		{	
			BeginAddress = 0x60000;   //read MPR3 -->[BA1:BA0] = 11,   [BA1:BA0] = {18^23, 17^22}

			MprPattern = 0x00;
			
			if(DramAttr->RegDimm == IS_REG_DIMM)
			{
				//BeginAddress = 0x10C60000;   //read MPR0  -->[BA1:BA0] = 00,   [BA1:BA0] = {18^23, 17^22}

				MprPattern = 0x55;
			}
			break;
		}
	}

#if 0
	//Get the MPR Pattern
	for (Bit_Index = 0; Bit_Index < 8; Bit_Index++)
	{
		if (MprPattern & (1 << Bit_Index))
			MprPatternSetting[Bit_Index] = 0xFF;
		else
			MprPatternSetting[Bit_Index] = 0x00;
	}
#endif

	Burstlength = 0x10;          //burst length

	ret = TRUE;

	//Set RSRW_ADDR[37:3] for start address
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_ADDR[37:3] for start address!!!\r\n")); 
	BeginAddressTmp = RShiftU64(BeginAddress, 3);
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(BeginAddressTmp, 8 * Index) & 0xFF));
	}

	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z4);
	AsiaPcieModify8(0XE0000000, Address, D0F3_RSRW_ADDR_37_35, (UINT8)(RShiftU64(BeginAddress, 35) & 0x07));



	//Set RSRW_LENGTH[31:0] for burst length
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_LENGTH[31:0] for burst length!!!\r\n"));
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(Burstlength, 8 * Index) & 0xFF));
	}

	//Set RSWPATSTEP0 to 1, enabling DRAMC write engine dynamic clock to initialize the write pattern
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RTXSWPAT);
	AsiaPcieModify16(0XE0000000, Address, BIT0, BIT0);

	//Set RDMLCUEN to 1, clearing the RXDIO data before burst write/read
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RDMLCUEN, D0F3_RDMLCUEN);
	//AsiaPcieModify16(0XE0000000, Address, D0F3_RDMLCUEN, 0);
	
#if 0
	//Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern!!!\r\n"));
	for (Index = 0; Index < 8; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[7]);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[6]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[5]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[4]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[3]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[2]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[1]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, MprPatternSetting[0]);
	}
#endif

#if 1
	for (Index = 0; Index < 8; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][0]);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][1]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][2]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][3]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][4]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][5]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][6]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DKS_Setting_Tmp[7 - Index][7]);
	}
#endif

	//Trigger DRAMCA read
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0 && (RankIndex >= 0 && RankIndex <= 3))
	{
		//Trigger reg_RSRD to active DRAMCA read engine
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger reg_RSRD to active DRAMCA read engine!!!\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSRD, D0F3_REG_RSRD);

		//Wait for reg_RSRD being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT1)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD done!!!\r\n"));
	}


#if 1
	//Trigger DRAMCB read
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0 && (RankIndex >= 4 && RankIndex <= 7))
	{
		//Trigger reg_RSRD_CHB to active DRAMCB read engine
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD_CHB to active DRAMCB read engine!!!\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSRD_CHB, D0F3_REG_RSRD_CHB);


		//Wait for reg_RSRD_CHB being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT3)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD done!!!\r\n"));
	}
#endif


	//check CHA
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0 && (RankIndex >= 0 && RankIndex <= 3))
	{
		/* ---------check result------------- */
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ERR_BIT_FOR_MEM_READ_ENGINE + ByteIndex);
		if (AsiaPcieRead8(0XE0000000, Address) != 0x0)
		{
			ret = FALSE;
		}
		/* -------------------------------- */
	}

	//check CHB
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0 && (RankIndex >= 4 && RankIndex <= 7))
	{
		/* ---------check result------------- */
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE + ByteIndex);
		if (AsiaPcieRead8(0XE0000000, Address) != 0x0)
		{
			ret = FALSE;
		}
		/* -------------------------------- */
	}

	//Set RSWPATSTEP0 to 0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RTXSWPAT);
	AsiaPcieModify16(0XE0000000, Address, BIT0, 0);
	
	return ret;
	
}

BOOLEAN MemoryTest_ByRWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8          RankIndex,
	IN UINT8	      ByteIndex,
	IN UINT64      BeginAddress,
	IN UINT32       Burstlength,
	IN UINT8      DataPattern[][8])
{
	UINT64 Address;
	UINT8  Index;

	UINT64 BeginAddressTmp;
	BOOLEAN ret;

	ret = TRUE;

	if ((BeginAddress > 0x100000000) || (BeginAddress + 64 * Burstlength > 0x100000000))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "RW_Engine not support upper 4G!!!\r\n"));
		return 0;
	}
		
	//Set RSRW_ADDR[37:3] for start address
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_ADDR[37:3] for start address!!!\r\n")); 
	BeginAddressTmp = RShiftU64(BeginAddress, 3);
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(BeginAddressTmp, 8 * Index) & 0xFF));
	}

	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z4);
	AsiaPcieModify8(0XE0000000, Address, D0F3_RSRW_ADDR_37_35, (UINT8)(RShiftU64(BeginAddress, 35) & 0x07));


	//Set RSRW_LENGTH[31:0] for burst length
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_LENGTH[31:0] for burst length!!!\r\n"));
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(Burstlength, 8 * Index) & 0xFF));
	}

	//Set RSWPATSTEP0 to 1, enabling DRAMC write engine dynamic clock to initialize the write pattern
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RTXSWPAT);
	AsiaPcieModify16(0XE0000000, Address, BIT0, BIT0);

	//Set RDMLCUEN to 1, clearing the RXDIO data before burst write/read
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RM2IL_COMP);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RDMLCUEN, D0F3_RDMLCUEN);

	
	//Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern!!!\r\n"));
	for (Index = 0; Index < 8; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][0]);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][1]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][2]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][3]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][4]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][5]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][6]);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, DataPattern[Index][7]);
	
	}

	//Trigger DRAMCA write
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0 && (RankIndex >= 0 && RankIndex <= 3))
	{
		//Trigger reg_RSWR to active DRAMCA write engine
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger reg_RSWR to active DRAMCA write engine!!!\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSWR, D0F3_REG_RSWR);

		//Wait for reg_RSWR being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT0)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSWR done!!!\r\n"));
	}

#if 1
	//Trigger DRAMCB write
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0 && (RankIndex >= 4 && RankIndex <= 7))
	{
		//Trigger  reg_RSWR_CHB to active DRAMCB write engine
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger  reg_RSWR_CHB to active DRAMCB write engine!!!\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSWR_CHB, D0F3_REG_RSWR_CHB);

		//Wait for reg_RSWR_CHB being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT2)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSWR_CHB done!!!\r\n"));
	}
#endif

	//Trigger DRAMCA read
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0 && (RankIndex >= 0 && RankIndex <=3 ))
	{
		//Trigger reg_RSRD to active DRAMCA read engine
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger reg_RSRD to active DRAMCA read engine!!!\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSRD, D0F3_REG_RSRD);

		//Wait for reg_RSRD being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT1)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD done!!!\r\n"));
	}

	
#if 1
	//Trigger DRAMCB read
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0 && (RankIndex >=4 && RankIndex <=7))
	{
		//Trigger reg_RSRD_CHB to active DRAMCB read engine
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD_CHB to active DRAMCB read engine!!!\r\n"));
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSRD_CHB, D0F3_REG_RSRD_CHB);


		//Wait for reg_RSRD_CHB being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT3)
		{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD_CHB done!!!\r\n"));
	}
#endif


	//check CHA
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0 && (RankIndex >= 0 && RankIndex <= 3))
	{
		/* ---------check result------------- */
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ERR_BIT_FOR_MEM_READ_ENGINE + ByteIndex);
		if (AsiaPcieRead8(0XE0000000, Address) != 0x0)
		{
			ret = FALSE;
		}
		/* -------------------------------- */
	}

	//check CHB
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0 && (RankIndex >= 4 && RankIndex <= 7))
	{
		/* ---------check result------------- */
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE + ByteIndex);
		if (AsiaPcieRead8(0XE0000000, Address) != 0x0)
		{
			ret = FALSE;
		}
		/* -------------------------------- */
	}

	//Set RSWPATSTEP0 to 0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RTXSWPAT);
	AsiaPcieModify16(0XE0000000, Address, BIT0, 0);
	
	return ret;
}	

// wholet/phase rank reg value
VOID SetTNI(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	/*UINT64     Address;*/
	UINT16     RegValue = 0;
	UINT8      ByteIndex =0;
	UINT8      RankIndex = 0;

	if(argc == 5){
		RankIndex = (UINT8)simple_strtoul(argv[2], NULL, 16); 
		ByteIndex = (UINT8)simple_strtoul(argv[3], NULL, 16);
		RegValue = (UINT16)simple_strtoul(argv[4], NULL, 16);
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETTNI RANK = %x, BYTE = %x, Regvalue = %x\n",RankIndex,ByteIndex,RegValue));

	if(AsiaStrnCmp(argv[1],"t",1)==0){
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &RegValue);
#if 0
		//RX TNI WHOLE T 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*6 + ByteIndex/2 + D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A0_A1_A2_A3_CHN_A);
		if(ByteIndex %2 == 0)//mask  0x0F
		{
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x0F,ShiftToMaskBit(0x0F, RegValue)); 
		}
		if(ByteIndex %2 == 1)//mask  0xF0
		{
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xF0,ShiftToMaskBit(0xF0, RegValue));
		}
#endif
	}
	else if(AsiaStrnCmp(argv[1],"p",1)==0)
	{
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &RegValue);
#if 0
		//RX TNI Phase
		if(ByteIndex == 8)
			ByteIndex++;
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*0x0A + ByteIndex + D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,ShiftToMaskBit(0x3F, RegValue)); 
#endif
	}
	TriggerLoadReg(PeiServices, DramAttr);	
}


//command line:setdqsi p rankindex byteindex value
//set the same value in a byte(pos & neg)
VOID SetDQSI(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	/*UINT64  Address;*/
	UINT8   ByteIndex = 0;
	UINT8	RankIndex = 0;
	UINT8	i=0;
	UINT16 RegValue =0;
	// all 8-bit in a byte set the same value

	//dqsi p/t rankindex byteindex value
	if(argc == 5){
		RankIndex = (UINT8)simple_strtoul(argv[2], NULL, 16); 
		ByteIndex = (UINT8)simple_strtoul(argv[3], NULL, 16);
		RegValue = (UINT16)simple_strtoul(argv[4], NULL, 16);
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETDQSI RANK = %x,BYTE = %x, Regvalue = %x\n",RankIndex,ByteIndex, RegValue));

	if(AsiaStrnCmp(argv[1],"p",1)==0){
		for(i =0;i<8;i++)
		{
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, (1<<i), POS, &RegValue);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, (1<<i), NEG, &RegValue);
#if 0
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*(9*16) + ByteIndex*16 + D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_0_CHN_A + i*2);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F3F,ShiftToMaskBit(0x3F00, RegValue)|RegValue ); //DQSI_P & DQSI_N
#endif
		}
	}
	TriggerLoadReg(PeiServices, DramAttr);	
}

VOID SetDQSO(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	/*UINT64  Address;*/
	UINT16  RegValue = 0;
	UINT8   ByteIndex =0;
	UINT8   RankIndex = 0;

	//dqso p/t rankindex byteindex value
	if(argc == 5){
		RankIndex = (UINT8)simple_strtoul(argv[2], NULL, 16); //rankindex is useless for tx
		ByteIndex = (UINT8)simple_strtoul(argv[3], NULL, 16);
		RegValue = (UINT16)simple_strtoul(argv[4], NULL, 16);
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETDQSO RANK = %x,BYTE = %x, Regvalue = %x\n",RankIndex,ByteIndex, RegValue));

#if 0
	if(RankIndex <=3)
		RankIndex  = 0;//CHA
	else 
		RankIndex = 1; //CHB
#endif

	if(AsiaStrnCmp(argv[1],"t",1)==0){
		//TX DQSO WHOLE T 
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &RegValue);
#if 0
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*0xA + ByteIndex + D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0xF0,ShiftToMaskBit(0xF0, RegValue)); 
#endif
	}
	else if(AsiaStrnCmp(argv[1],"p",1)==0)
	{
		//TX DQSO PHASE 
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &RegValue);
#if 0
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*16 + ByteIndex*2 + D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F3F,ShiftToMaskBit(0x3F3F, RegValue)|RegValue ); 
#endif
	}
	TriggerLoadReg(PeiServices, DramAttr);	
}

VOID SetDQO(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	/*UINT64	   Address;*/
	UINT16	   RegValue = 0;
	UINT8	   ByteIndex = 0;
	UINT8      RankIndex = 0; //TX no need by rank

	//dqo p/t rankindex byteindex value
	if(argc == 5){
		RankIndex = (UINT8)simple_strtoul(argv[2], NULL, 16); 
		ByteIndex = (UINT8)simple_strtoul(argv[3], NULL, 16);
		RegValue = (UINT16)simple_strtoul(argv[4], NULL, 16);
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETDQO RANK = %x,BYTE = %x, Regvalue = %x\n",RankIndex,ByteIndex, RegValue));

	if(AsiaStrnCmp(argv[1],"t",1)==0){
		//TX DQO WHOLE T
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &RegValue);
#if 0
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*0xA + ByteIndex + D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x0F,ShiftToMaskBit(0x0F, RegValue)); 
#endif
	}
	else if(AsiaStrnCmp(argv[1],"p",1)==0)
	{
		//TX DQO PHASE 
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &RegValue);
#if 0
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RankIndex*0xA + ByteIndex + D0F3_TX_CLK_PI_PHASE_CTL_A0_A1_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,ShiftToMaskBit(0x3F, RegValue)); 
#endif
	}
	TriggerLoadReg(PeiServices, DramAttr);	
}


extern VOID ClearAllRankSize(IN DRAM_ATTRIBUTE *DramAttr);
extern VOID SetTargetRankToFirst256MB(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo);




VOID Tx_Scan_byRank_Index_RWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteNo)
{
	UINT8	ByteIndex;
	UINT8	ByteBegin;
	UINT8	ByteEnd;

	UINT16	Value16 = 0;
	BOOLEAN CheckResult = 0 ;	

	UINT16	DQSO_INDEX;
	UINT16	DQO_INDEX;
	UINT8	DQSO_INDEX_STEP = 4;
	UINT8	DQO_INDEX_STEP = 2;

	UINT16  DQO_Tmp[DQO_INDEX_MAX];
	INT16  Index_Tmp;
	UINT16	DQO_Start = 0;
	UINT16	DQO_End = 0;
	UINT16  End_Index_Note = 0;
	
	UINT64 BeginAddress = 0xC60000;	
	
	UINT32 Burstlength = 0x10; //0x10 * 8QW
	
	UINT8  DataPattern[8][8] = {
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF
	};

	TXSCANSET TxScanSet[100];
	UINT8 Index = 0;
	UINT8 Flag = 0;
	UINT8 Flag2 = 0;
	UINT16 DQSO_Set;
	UINT16 DQO_Set;
	UINT16 WholeT_DQSO;
	UINT16 Phase_DQSO;
	UINT16 WholeT_DQO;
	UINT16 Phase_DQO;

	UINT16 DQSO_Scan_Begin = 0x40;
	UINT16 DQSO_Scan_End = 7 * 0x40;
	UINT16 DQO_Scan_Begin = 0x40;
	UINT16 DQO_Scan_End = 7 * 0x40;
	
	if(ByteNo == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteNo;
		ByteEnd = ByteNo + 1;
	}
	
	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "TX DQS/DQ Scan - X for DQ, Y for DQS\n")); 	
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank	   %02X\n", RankIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Byte	   %02X\n", ByteIndex));	

		for(DQSO_INDEX = DQSO_Scan_Begin; DQSO_INDEX < DQSO_Scan_End; DQSO_INDEX += DQSO_INDEX_STEP)
		{ 
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n DQSO Index : %04X ", DQSO_INDEX));
			
			//DQSO WHOLE T
			Value16 = DQSO_INDEX / 0x40;
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, " (WholeT : %04X, ", Value16));
			
			//DQSO Phase
			Value16 = DQSO_INDEX % 0x40;
			Value16 = Tx_DQSO_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));

			(*PeiServices)->SetMem(DQO_Tmp, sizeof(DQO_Tmp), 0);
			DQO_Start = 0;
			DQO_End = 0;
	
			for(DQO_INDEX = DQO_Scan_Begin; DQO_INDEX  < DQO_Scan_End; DQO_INDEX += DQO_INDEX_STEP)
			{
				//DQO WHOLE T
				Value16 = DQO_INDEX / 0x40;
				DRAMIOCTL(PeiServices,DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//DQO Phase
				Value16 = DQO_INDEX % 0x40;
				Value16 = Tx_DQO_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//trigger Load Register 		
				TriggerLoadReg(PeiServices, DramAttr); 
				
				CheckResult = MemoryTest_ByRWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, BeginAddress, Burstlength, DataPattern);

				if(CheckResult)
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
					DQO_Tmp[DQO_INDEX] = 1;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
					DQO_Tmp[DQO_INDEX] = 0;
				}
			}

			End_Index_Note = DQO_INDEX - DQO_INDEX_STEP;
			
			for (Index_Tmp = 0; Index_Tmp < DQO_INDEX_MAX; Index_Tmp += DQO_INDEX_STEP)
			{
				if (DQO_Tmp[Index_Tmp] == 1)
				{
					DQO_Start = Index_Tmp;
					break;
				}
			}

			for (Index_Tmp = End_Index_Note; Index_Tmp >= 0; Index_Tmp -= DQO_INDEX_STEP)
			{
				if (DQO_Tmp[Index_Tmp] == 1)
				{
					DQO_End = Index_Tmp;
					break;
				}
			}

			PEI_DEBUG((PeiServices, EFI_D_INFO, "		DQO Index Low = %04X, DQO Index High = %04X, DQO Index Center = %04X", 
				DQO_Start, DQO_End, (DQO_Start + DQO_End) / 2));

			Value16 = ((DQO_Start + DQO_End) / 2) / 0x40;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "(WholeT : %04X, ", Value16));

			Value16 = ((DQO_Start + DQO_End) / 2) % 0x40;
			Value16 = Tx_DQO_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));

			///////////////DKS : Use Range 1 to find DQSO & DQO Setting//////////////
			if (DQO_End - DQO_Start > 0 && Flag == 0)
			{	
				Flag2 = 1;
				TxScanSet[Index].DQSOIndex = DQSO_INDEX;
				TxScanSet[Index].DQOBeg = DQO_Start;
				TxScanSet[Index].DQOEnd = DQO_End;
				Index++;
			}
			else if (DQO_End - DQO_Start == 0 && Flag2 == 1)
			{
				Flag = 1;
				continue;
			}
		}

		DQSO_Set = TxScanSet[(Index - 1) / 2].DQSOIndex;
		DQO_Set = (TxScanSet[(Index - 1) / 2].DQOEnd + TxScanSet[(Index - 1) / 2].DQOBeg) / 2;
		IndexToValue(PeiServices, DramAttr, RankIndex, DQSO_Set, &WholeT_DQSO, &Phase_DQSO, IO_DQSO);
		IndexToValue(PeiServices, DramAttr, RankIndex, DQO_Set, &WholeT_DQO, &Phase_DQO, IO_DQO);
	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQSO Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", DQSO_Set, WholeT_DQSO, Phase_DQSO));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQO Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", DQO_Set, WholeT_DQO, Phase_DQO));	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));

		DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT = WholeT_DQSO;
		DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase = Phase_DQSO;
		
		DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT = WholeT_DQO;
		DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase  = Phase_DQO;

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase));
		
#if 0
		//Setting Value
		//DQSO
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_DQSO);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_DQSO);
		
		//DQO
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_DQO);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_DQO);
#endif
	}	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}




VOID Tx_Scan_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteNo)
{
	UINT8	ByteIndex;
	UINT8	ByteBegin;
	UINT8	ByteEnd;

	UINT8	DQSO_START_WHOLET = 4;
	UINT8	DQSO_START_ENDT = 5;

	UINT8	DQO_START_WHOLET = 4;
	UINT8	DQO_START_ENDT = 5;

	UINT16  Value16 = 0;
	UINT16  DQO_PHASE_INDEX,DQSO_PHASE_INDEX;
	BOOLEAN CheckResult = 0 ;	

	UINT8	STEP =2;

	UINT64 BeginAddress = 0x10C60000;
	
	UINT32 Burstlength = 0x10; //0x10 * 8QW
	
	UINT8  DataPattern[8][8] = {
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
		0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF
	};
	
	if(ByteNo == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteNo;
		ByteEnd = ByteNo+1;
	}
	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "TX DQS/DQ Scan - X for DQ, Y for DQS\n"));		
	for(ByteIndex = ByteBegin; ByteIndex< ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank      %02X\n", RankIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Byte      %02X\n", ByteIndex));	

		for(DQSO_PHASE_INDEX =DQSO_START_WHOLET*(64/STEP); DQSO_PHASE_INDEX < (UINT16)(64*(DQSO_START_ENDT+1)/STEP); ){ //Y
			//Set DQSO
			//DQSO WHOLE T
			Value16 = DQSO_PHASE_INDEX /(64/STEP);
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			//DQSO Phase
			Value16 =STEP*(DQSO_PHASE_INDEX %(64/STEP));
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_POS, &Value16);
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_NEG, &Value16);

			//print related code start
			if(DQSO_PHASE_INDEX % (32/STEP) ==0 && ((DQSO_PHASE_INDEX/(32/STEP))%2==1))
			{
				PEI_DEBUG((PeiServices, EFI_D_INFO, "$"));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "%d",DQSO_PHASE_INDEX/(64/STEP)));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "$"));
			}
			else if(DQSO_PHASE_INDEX % (64/STEP) ==0 && DQSO_PHASE_INDEX !=0)
			{
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "%02d",DQSO_PHASE_INDEX %(64/STEP) *STEP));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "$"));
			}
			else
			{
				PEI_DEBUG((PeiServices, EFI_D_INFO, "%02d",DQSO_PHASE_INDEX %(64/STEP) *STEP));
				PEI_DEBUG((PeiServices, EFI_D_INFO, "$"));
			}
			//print related code end 

			for(DQO_PHASE_INDEX =DQO_START_WHOLET*(64/STEP); DQO_PHASE_INDEX  < (UINT16)(64*(DQO_START_ENDT+1)/STEP); ) //X
			{
				//DQO WHOLE T
				Value16 = DQO_PHASE_INDEX/(64/STEP);
				DRAMIOCTL(PeiServices,DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				/*Print(L"   DQO WholeT:%2x", Value16);*/

				//DQO Phase
				Value16 =STEP*(DQO_PHASE_INDEX%(64/STEP));
				DRAMIOCTL(PeiServices,DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				/*Print(L" DQO Phase:%2x\n" , Value16);*/
				if((DQO_PHASE_INDEX%(64/STEP) == 0 )&& (DQO_PHASE_INDEX!=0))
					PEI_DEBUG((PeiServices, EFI_D_INFO, " "));
				DQO_PHASE_INDEX= DQO_PHASE_INDEX+1;
#if 1
				CheckResult = MemoryTest_ByRWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, BeginAddress, Burstlength, DataPattern);
#else
				CheckResult = MemoryReadTest(PeiServices, pPCIPPI, DramAttr, readtest, ByteIndex);
#endif
				if(CheckResult){
					PEI_DEBUG((PeiServices, EFI_D_INFO, "0"));	
				}else{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
				}
			}
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\n "));
			DQSO_PHASE_INDEX=DQSO_PHASE_INDEX+1 ;
		}		
	}
}



VOID Tx_Scan_byRank_Index_Sw(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteNo)
{
	UINT8	ByteIndex;
	UINT8	ByteBegin;
	UINT8	ByteEnd;
	//UINT8   Bytetemp;

	UINT16  Value16 = 0;
	BOOLEAN CheckResult = 0 ;	

	UINT16  DQSO_INDEX;
	UINT16  DQO_INDEX;
	UINT16   DQSO_INDEX_STEP = 4;
	UINT16   DQO_INDEX_STEP = 2;

	UINT16  DQO_Tmp[DQO_INDEX_MAX];
	INT16   Index_Tmp;
	UINT16	DQO_Start = 0;
	UINT16	DQO_End = 0;
	UINT16  End_Index_Note = 0;

	TXSCANSET TxScanSet[100];
	UINT8 Index = 0;
	UINT8 Flag = 0;
	UINT8 Flag2 = 0;
	UINT16 DQSO_Set;
	UINT16 DQO_Set;
	UINT16 WholeT_DQSO;
	UINT16 Phase_DQSO;
	UINT16 WholeT_DQO;
	UINT16 Phase_DQO;

	UINT16 DQSO_Scan_Begin = 0x40;
	UINT16 DQSO_Scan_End = 0x200;
	
	UINT16 DQO_Scan_Begin = 0x40;
	UINT16 DQO_Scan_End = 0x200;

	if(ByteNo == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteNo;
		ByteEnd = ByteNo + 1;
	}
	
	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "TX DQS/DQ Scan - X for DQ, Y for DQS\n"));		
	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank      %02X\n", RankIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Byte      %02X\n", ByteIndex));	

		for(DQSO_INDEX = DQSO_Scan_Begin; DQSO_INDEX < DQSO_Scan_End; DQSO_INDEX += DQSO_INDEX_STEP)
		{ 
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n DQSO Index : %04X ", DQSO_INDEX));

			//DQSO WHOLE T
			Value16 = DQSO_INDEX / 0x40;
#if 0
			for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
			{
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
			}
#endif
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, " (WholeT : %04X, ", Value16));
			
			//DQSO Phase
			Value16 = DQSO_INDEX % 0x40;
			Value16 = Tx_DQSO_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
#if 0
			for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
			{
				DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
			}
#endif
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));
				
			(*PeiServices)->SetMem(DQO_Tmp, sizeof(DQO_Tmp), 0);
			DQO_Start = 0;
			DQO_End = 0;
	
			for(DQO_INDEX = DQO_Scan_Begin; DQO_INDEX  < DQO_Scan_End; DQO_INDEX += DQO_INDEX_STEP)
			{
				//DQO WHOLE T
				Value16 = DQO_INDEX / 0x40;
#if 0
				for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
				{
					DRAMIOCTL(PeiServices,DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				}
#endif
				DRAMIOCTL(PeiServices,DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//DQO Phase
				Value16 = DQO_INDEX % 0x40;				
				Value16 = Tx_DQO_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
#if 0
				for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
				{
					DRAMIOCTL(PeiServices,DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				}
#endif				
				DRAMIOCTL(PeiServices,DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//trigger Load Register 		
				TriggerLoadReg(PeiServices, DramAttr); 
				
				CheckResult = MemoryTest(PeiServices, pPCIPPI, DramAttr, ByteIndex);	//memtest normal

				if(CheckResult)
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
					DQO_Tmp[DQO_INDEX] = 1;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
					DQO_Tmp[DQO_INDEX] = 0;
				}
			}

			End_Index_Note = DQO_INDEX - DQO_INDEX_STEP;
				
			for (Index_Tmp = 0; Index_Tmp < DQO_INDEX_MAX; Index_Tmp += DQO_INDEX_STEP)
			{
				if (DQO_Tmp[Index_Tmp] == 1)
				{
					DQO_Start = Index_Tmp;
					break;
				}
			}

			for (Index_Tmp = End_Index_Note; Index_Tmp >= 0; Index_Tmp -= DQO_INDEX_STEP)
			{
				if (DQO_Tmp[Index_Tmp] == 1)
				{
					DQO_End = Index_Tmp;
					break;
				}
			}

			PEI_DEBUG((PeiServices, EFI_D_INFO, "		DQO Index Low = %04X, DQO Index High = %04X, DQO Index Center = %04X", 
				DQO_Start, DQO_End, (DQO_Start + DQO_End) / 2));

			Value16 = ((DQO_Start + DQO_End) / 2) / 0x40;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "(WholeT : %04X, ", Value16));

			Value16 = ((DQO_Start + DQO_End) / 2) % 0x40;
			Value16 = Tx_DQO_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));
			
			///////////////DKS : Use Range 1 to find DQSO & DQO Setting//////////////
			if (DQO_End - DQO_Start > 0 && Flag == 0)
			{	
				Flag2 = 1;
				TxScanSet[Index].DQSOIndex = DQSO_INDEX;
				TxScanSet[Index].DQOBeg = DQO_Start;
				TxScanSet[Index].DQOEnd = DQO_End;
				Index++;
			}
			else if (DQO_End - DQO_Start == 0 && Flag2 == 1)
			{
				Flag = 1;
				continue;
			}
		}	

		DQSO_Set = TxScanSet[(Index - 1) / 2].DQSOIndex;
		DQO_Set = (TxScanSet[(Index - 1) / 2].DQOEnd + TxScanSet[(Index - 1) / 2].DQOBeg) / 2;
		IndexToValue(PeiServices, DramAttr, RankIndex, DQSO_Set, &WholeT_DQSO, &Phase_DQSO, IO_DQSO);
		IndexToValue(PeiServices, DramAttr, RankIndex, DQO_Set, &WholeT_DQO, &Phase_DQO, IO_DQO);
	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQSO Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", DQSO_Set, WholeT_DQSO, Phase_DQSO));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQO Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", DQO_Set, WholeT_DQO, Phase_DQO));	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));

		DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT = WholeT_DQSO;
		DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase = Phase_DQSO;
		
		DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT = WholeT_DQO;
		DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase  = Phase_DQO;

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase));
		
#if 0
		//Setting Value
		//DQSO
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_DQSO);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_DQSO);
		
		//DQO
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_DQO);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_DQO);
#endif

	}	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}



VOID Rx_Scan_byRank_Index_Sw_BaseGoodTx(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex)
{
	UINT16	Value16 = 0;
	UINT16	TNI_WHOLE_T;
	UINT16	TNI_PHASE;
	UINT8	DQSI_PHASE;
	UINT8	TNI_INDEX_STEP = 4;
	UINT8	DQSI_PHASE_STEP = 2;
	UINT8	ByteBegin;
	UINT8	ByteEnd;
	BOOLEAN CheckResult = 0;	
	UINT16	TNI_Index;

	UINT8	DQSI_Tmp[0x40];
	INT8	Index_Tmp;
	UINT8	DQSI_Start = 0;
	UINT8	DQSI_End = 0;
	UINT8	End_Index_Note = 0;

	RXSCANSET RxScanSet[100];
	UINT8 Index = 0;
	UINT8 Flag = 0;
	UINT8 Flag2 = 0;
	UINT16 TNI_Set;
	UINT16 DQSI_Set;
	UINT16 WholeT_TNI;
	UINT16 Phase_TNI;

	UINT16 TNI_Scan_Begin = 0x40;
	UINT16 TNI_Scan_End = 9 * 0x40;
	UINT8 DQSI_Scan_Begin = 0;
	UINT8 DQSI_Scan_End = 0x40;
	
	if(ByteIndex == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteIndex;
		ByteEnd = ByteIndex + 1;
	}

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Rx DQSI/RDSIT Scan - X for DQSI, Y for TNI\r\n")); 	

	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "  (DQSI Phase 00-3F)\r\n"));

		for (TNI_Index = TNI_Scan_Begin; TNI_Index < TNI_Scan_End; TNI_Index += TNI_INDEX_STEP)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n TNI Index : %04X ", TNI_Index));
			
			//TNI  WHOLE T
			TNI_WHOLE_T = TNI_Index / 0x40; 
			Value16 = TNI_WHOLE_T;

			if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) && (RankIndex >= 0 && RankIndex <= 3))
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			else if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) && (RankIndex >= 4 && RankIndex <= 7))
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 5, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 6, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 7, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			
			PEI_DEBUG((PeiServices, EFI_D_INFO, " (WholeT : %04X, ", Value16));
			
			//TNI  Phase
			TNI_PHASE = TNI_Index % 0x40;
			Value16 = TNI_PHASE;
			Value16 = Rx_TNI_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));
			
			(*PeiServices)->SetMem(DQSI_Tmp, sizeof(DQSI_Tmp), 0);
			DQSI_Start = 0;
			DQSI_End = 0;
			
			for(DQSI_PHASE = DQSI_Scan_Begin; DQSI_PHASE < DQSI_Scan_End; DQSI_PHASE += DQSI_PHASE_STEP)
			{
				Value16 = DQSI_PHASE;
				
				DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &Value16);

				//trigger Load Register 		
				TriggerLoadReg(PeiServices, DramAttr); 

				CheckResult = MemoryTest(PeiServices, pPCIPPI, DramAttr, ByteIndex);	 //only read test

				if(CheckResult)
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
					DQSI_Tmp[DQSI_PHASE] = 1;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
					DQSI_Tmp[DQSI_PHASE] = 0;
				}
			}

			End_Index_Note = DQSI_PHASE - DQSI_PHASE_STEP;
			
			for (Index_Tmp = 0; Index_Tmp < 0x40; Index_Tmp += DQSI_PHASE_STEP)
			{
				if (DQSI_Tmp[Index_Tmp] == 1)
				{
					DQSI_Start = Index_Tmp;
					break;
				}
			}

			for (Index_Tmp = End_Index_Note; Index_Tmp >= 0; Index_Tmp -= DQSI_PHASE_STEP)
			{
				if (DQSI_Tmp[Index_Tmp] == 1)
				{
					DQSI_End = Index_Tmp;
					break;
				}
			}

			PEI_DEBUG((PeiServices, EFI_D_INFO, "		DQSI Index Low = %04X, DQSI Index High = %04X, DQSI Index Center = %04X", 
				DQSI_Start, DQSI_End, (DQSI_Start + DQSI_End) / 2));	

			///////////////DKS : Use Range 1 to find TNI & DQSI Setting//////////////
			if (DQSI_End - DQSI_Start > 0 && Flag == 0)
			{	
				Flag2 = 1;
				RxScanSet[Index].TNIIndex = TNI_Index;
				RxScanSet[Index].DQSIBeg = DQSI_Start;
				RxScanSet[Index].DQSIEnd = DQSI_End;
				Index++;
			}
			else if (DQSI_End - DQSI_Start == 0 && Flag2 == 1)
			{
				Flag = 1;
				continue;
			}
		}

		TNI_Set = RxScanSet[(Index - 1) / 2].TNIIndex;
		DQSI_Set = (RxScanSet[(Index - 1) / 2].DQSIEnd + RxScanSet[(Index - 1) / 2].DQSIBeg) / 2;
		IndexToValue(PeiServices, DramAttr, RankIndex, TNI_Set, &WholeT_TNI, &Phase_TNI, IO_TNI);
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The TNI Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", TNI_Set, WholeT_TNI, Phase_TNI)); 	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQSI Index Select is : %04X\r\n", DQSI_Set));	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));		

		DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT = WholeT_TNI;
		DramAttr->TNI_Value[RankIndex][ByteIndex].Phase = Phase_TNI;
		
		DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase = DQSI_Set;
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->TNI_Value[RankIndex][ByteIndex].Phase));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase));
#if 0
		//setting value
		//TNI
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_TNI);
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_TNI);

		//DQSI
		DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &DQSI_Set);
		DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &DQSI_Set);
#endif
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}


VOID Rx_Scan_byRank_Index_Sw(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN ReadTest *readtest)
{
	UINT16	Value16 = 0;
	UINT16	TNI_WHOLE_T;
	UINT16  TNI_PHASE;
	UINT8   DQSI_PHASE;
	UINT8   TNI_INDEX_STEP = 4;
	UINT8   DQSI_PHASE_STEP = 2;
	UINT8	ByteBegin;
	UINT8   ByteEnd;
	BOOLEAN CheckResult = 0;	
	UINT16  TNI_Index;

	UINT8   DQSI_Tmp[0x40];
	INT8    Index_Tmp;
	UINT8	DQSI_Start = 0;
	UINT8	DQSI_End = 0;
	UINT8   End_Index_Note = 0;

	RXSCANSET RxScanSet[100];
	UINT8 Index = 0;
	UINT8 Flag = 0;
	UINT8 Flag2 = 0;
	UINT16 TNI_Set;
	UINT16 DQSI_Set;
	UINT16 WholeT_TNI;
	UINT16 Phase_TNI;

	UINT16 TNI_Scan_Begin = 0x40;
	UINT16 TNI_Scan_End = 9 * 0x40;
	UINT8 DQSI_Scan_Begin = 0;
	UINT8 DQSI_Scan_End = 0x40;
	
	if(ByteIndex == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteIndex;
		ByteEnd = ByteIndex + 1;
	}


    //RankIndex = 4;
	//ByteBegin = 2;
	//ByteEnd = 3;


	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Rx DQSI/RDSIT Scan - X for DQSI, Y for TNI\r\n"));		

	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "  (DQSI Phase 00-3F)\r\n"));

		for (TNI_Index = TNI_Scan_Begin; TNI_Index < TNI_Scan_End; TNI_Index += TNI_INDEX_STEP)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n TNI Index : %04X ", TNI_Index));
			
			//TNI  WHOLE T
			TNI_WHOLE_T = TNI_Index / 0x40;	
			Value16 = TNI_WHOLE_T;

			if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) && (RankIndex >= 0 && RankIndex <= 3))
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			else if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) && (RankIndex >= 4 && RankIndex <= 7))
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 5, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 6, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 7, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			
			PEI_DEBUG((PeiServices, EFI_D_INFO, " (WholeT : %04X, ", Value16));
			
			//TNI  Phase
			TNI_PHASE = TNI_Index % 0x40;
			Value16 = TNI_PHASE;
			Value16 = Rx_TNI_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));
			
			(*PeiServices)->SetMem(DQSI_Tmp, sizeof(DQSI_Tmp), 0);
			DQSI_Start = 0;
			DQSI_End = 0;
			
			for(DQSI_PHASE = DQSI_Scan_Begin; DQSI_PHASE < DQSI_Scan_End; DQSI_PHASE += DQSI_PHASE_STEP)
			{
				Value16 = DQSI_PHASE;
				
				DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &Value16);

				//trigger Load Register 		
				TriggerLoadReg(PeiServices, DramAttr); 

				CheckResult = MemoryReadTest(PeiServices, pPCIPPI, DramAttr, readtest, ByteIndex);   //only read test

				if(CheckResult)
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
					DQSI_Tmp[DQSI_PHASE] = 1;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
					DQSI_Tmp[DQSI_PHASE] = 0;
				}
			}

			End_Index_Note = DQSI_PHASE - DQSI_PHASE_STEP;
			
			for (Index_Tmp = 0; Index_Tmp < 0x40; Index_Tmp += DQSI_PHASE_STEP)
			{
				if (DQSI_Tmp[Index_Tmp] == 1)
				{
					DQSI_Start = Index_Tmp;
					break;
				}
			}

			for (Index_Tmp = End_Index_Note; Index_Tmp >= 0; Index_Tmp -= DQSI_PHASE_STEP)
			{
				if (DQSI_Tmp[Index_Tmp] == 1)
				{
					DQSI_End = Index_Tmp;
					break;
				}
			}

			PEI_DEBUG((PeiServices, EFI_D_INFO, "		DQSI Index Low = %04X, DQSI Index High = %04X, DQSI Index Center = %04X", 
				DQSI_Start, DQSI_End, (DQSI_Start + DQSI_End) / 2));	

			///////////////DKS : Use Range 1 to find TNI & DQSI Setting//////////////
			if (DQSI_End - DQSI_Start > 0 && Flag == 0)
			{	
				Flag2 = 1;
				RxScanSet[Index].TNIIndex = TNI_Index;
				RxScanSet[Index].DQSIBeg = DQSI_Start;
				RxScanSet[Index].DQSIEnd = DQSI_End;
				Index++;
			}
			else if (DQSI_End - DQSI_Start == 0 && Flag2 == 1)
			{
				Flag = 1;
				continue;
			}
		}

		TNI_Set = RxScanSet[(Index - 1) / 2].TNIIndex;
		DQSI_Set = (RxScanSet[(Index - 1) / 2].DQSIEnd + RxScanSet[(Index - 1) / 2].DQSIBeg) / 2;
		IndexToValue(PeiServices, DramAttr, RankIndex, TNI_Set, &WholeT_TNI, &Phase_TNI, IO_TNI);
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The TNI Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", TNI_Set, WholeT_TNI, Phase_TNI));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQSI Index Select is : %04X\r\n", DQSI_Set));	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));		

		DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT = WholeT_TNI;
		DramAttr->TNI_Value[RankIndex][ByteIndex].Phase = Phase_TNI;
		
		DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase = DQSI_Set;
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->TNI_Value[RankIndex][ByteIndex].Phase));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase));
#if 0
		//setting value
		//TNI
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_TNI);
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_TNI);

		//DQSI
		DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &DQSI_Set);
		DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &DQSI_Set);
#endif
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}

VOID Rx_Scan_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 MprNo)
{
	UINT16	Value16 = 0;
	UINT8	TNI_WHOLE_T;
	UINT8   TNI_PHASE;
	UINT8   DQSI_PHASE;
	UINT8   TNI_PHASE_STEP = 4;
	UINT8   DQSI_PHASE_STEP = 1;
	UINT8	ByteBegin;
	UINT8   ByteEnd;
	BOOLEAN CheckResult = 0;	
	
	if(ByteIndex == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteIndex;
		ByteEnd = ByteIndex+1;
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "Rx DQSI/RDSIT Scan - X for DQSI, Y for TNI\r\n"));		

	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		

		PEI_DEBUG((PeiServices, EFI_D_INFO, "  (DQSI Phase 00-3F)\r\n"));

		for(TNI_WHOLE_T=0; TNI_WHOLE_T <= 0x07; TNI_WHOLE_T++)
		{
			for(TNI_PHASE = 0; TNI_PHASE <= 0x3F; TNI_PHASE+=TNI_PHASE_STEP){ 
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\nTNI:WHOLET%02X|PHASE%02X ",TNI_WHOLE_T,TNI_PHASE));
				//
				//TNI WHOLE T
				Value16 = TNI_WHOLE_T;
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				//TNI  Phase
				Value16 = TNI_PHASE;
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);

				for(DQSI_PHASE = 0; DQSI_PHASE <= 0X3F ; DQSI_PHASE += DQSI_PHASE_STEP){

					Value16 = DQSI_PHASE;
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &Value16);
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &Value16);

					//trigger Load Register 		
					TriggerLoadReg(PeiServices, DramAttr); 

#if 1
					CheckResult = MemoryReadTest_ByRWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, MprNo);    //memtest by RW_Engine
#else
					CheckResult = MemoryTest(PeiServices, pPCIPPI, DramAttr, ByteIndex);                   //memtest normal
#endif

					if(CheckResult){
						PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
					}else{
						PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
					}
				}
			}	
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}


VOID Rx_Scan_byRank_Index_RWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 MprNo)
{
	UINT16	Value16 = 0;
	UINT16	TNI_WHOLE_T;
	UINT16	TNI_PHASE;
	UINT8	DQSI_PHASE;
	UINT8	TNI_INDEX_STEP = 4;
	UINT8	DQSI_PHASE_STEP = 2;
	UINT8	ByteBegin;
	UINT8	ByteEnd;
	BOOLEAN CheckResult = 0;	
	UINT16	TNI_Index;

	UINT8   DQSI_Tmp[0x40];
	INT8    Index_Tmp;
	UINT8	DQSI_Start = 0;
	UINT8	DQSI_End = 0;
	UINT8   End_Index_Note = 0;

	RXSCANSET RxScanSet[100];
	UINT8 Index = 0;
	UINT8 Flag = 0;
	UINT8 Flag2 = 0;
	UINT16 TNI_Set;
	UINT16 DQSI_Set;
	UINT16 WholeT_TNI;
	UINT16 Phase_TNI;

	UINT16 TNI_Scan_Begin = 0x40;
	UINT16 TNI_Scan_End = 9 * 0x40;
	UINT8 DQSI_Scan_Begin = 0;
	UINT8 DQSI_Scan_End = 0x40;

	//UINT8  Bytetemp;

	if(ByteIndex == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteIndex;
		ByteEnd = ByteIndex + 1;
	}

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Rx DQSI/RDSIT Scan - X for DQSI, Y for TNI\r\n")); 	

	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		

		PEI_DEBUG((PeiServices, EFI_D_INFO, "  (DQSI Phase 00-3F)\r\n"));

		for (TNI_Index = TNI_Scan_Begin; TNI_Index < TNI_Scan_End; TNI_Index += TNI_INDEX_STEP)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n TNI Index : %04X ", TNI_Index));

			//TNI  WHOLE T
			TNI_WHOLE_T = TNI_Index / 0x40; 
			Value16 = TNI_WHOLE_T;
#if 0
			for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
			}
#endif

#if 1
			if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) && (RankIndex >= 0 && RankIndex <= 3))
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			else if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) && (RankIndex >= 4 && RankIndex <= 7))
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 4, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 5, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 6, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 7, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			}
			
#endif
			PEI_DEBUG((PeiServices, EFI_D_INFO, " (WholeT : %04X, ", Value16));


			//TNI  Phase
			TNI_PHASE = TNI_Index % 0x40;
			Value16 = TNI_PHASE;
			Value16 = Rx_TNI_Convert_To_Value(PeiServices, DramAttr, RankIndex, Value16);
#if 0
			for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, 0, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, 1, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, 2, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, 3, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
			}
#endif
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Phase : %04X) ", Value16));

			(*PeiServices)->SetMem(DQSI_Tmp, sizeof(DQSI_Tmp), 0);
			DQSI_Start = 0;
			DQSI_End = 0;
	
			for(DQSI_PHASE = DQSI_Scan_Begin; DQSI_PHASE < DQSI_Scan_End; DQSI_PHASE += DQSI_PHASE_STEP)
			{
				Value16 = DQSI_PHASE;

#if 0
				for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
				{
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 0, Bytetemp, 0xFF, IO_POS, &Value16);
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 0, Bytetemp, 0xFF, IO_NEG, &Value16);

					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 1, Bytetemp, 0xFF, IO_POS, &Value16);
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 1, Bytetemp, 0xFF, IO_NEG, &Value16);

					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 2, Bytetemp, 0xFF, IO_POS, &Value16);
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 2, Bytetemp, 0xFF, IO_NEG, &Value16);

					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 3, Bytetemp, 0xFF, IO_POS, &Value16);
					DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 3, Bytetemp, 0xFF, IO_NEG, &Value16);
				}
#endif
				DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &Value16);
	
				//trigger Load Register 		
				TriggerLoadReg(PeiServices, DramAttr); 
				
				CheckResult = MemoryReadTest_ByRWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, MprNo);    //memtest by RW_Engine

				if(CheckResult)
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
					DQSI_Tmp[DQSI_PHASE] = 1;
				}
				else
				{
					PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
					DQSI_Tmp[DQSI_PHASE] = 0;
				}

			}


			End_Index_Note = DQSI_PHASE - DQSI_PHASE_STEP;
			
			for (Index_Tmp = 0; Index_Tmp < 0x40; Index_Tmp += DQSI_PHASE_STEP)
			{
				if (DQSI_Tmp[Index_Tmp] == 1)
				{
					DQSI_Start = Index_Tmp;
					break;
				}
			}

			for (Index_Tmp = End_Index_Note; Index_Tmp >= 0; Index_Tmp -= DQSI_PHASE_STEP)
			{
				if (DQSI_Tmp[Index_Tmp] == 1)
				{
					DQSI_End = Index_Tmp;
					break;
				}
			}

			PEI_DEBUG((PeiServices, EFI_D_INFO, "		DQSI Index Low = %04X, DQSI Index High = %04X, DQSI Index Center = %04X", 
				DQSI_Start, DQSI_End, (DQSI_Start + DQSI_End) / 2));

			///////////////DKS : Use Range 1 to find TNI & DQSI Setting//////////////
			if (DQSI_End - DQSI_Start > 0 && Flag == 0)
			{	
				Flag2 = 1;
				RxScanSet[Index].TNIIndex = TNI_Index;
				RxScanSet[Index].DQSIBeg = DQSI_Start;
				RxScanSet[Index].DQSIEnd = DQSI_End;
				Index++;
			}
			else if (DQSI_End - DQSI_Start == 0 && Flag2 == 1)
			{
				Flag = 1;
				continue;
			}

		}

		TNI_Set = RxScanSet[(Index - 1) / 2].TNIIndex;
		DQSI_Set = (RxScanSet[(Index - 1) / 2].DQSIEnd + RxScanSet[(Index - 1) / 2].DQSIBeg) / 2;
		IndexToValue(PeiServices, DramAttr, RankIndex, TNI_Set, &WholeT_TNI, &Phase_TNI, IO_TNI);
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The TNI Index Select is : %04X (WholeT: %04X, Phase: %04X)\r\n", TNI_Set, WholeT_TNI, Phase_TNI));		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "The DQSI Index Select is : %04X\r\n", DQSI_Set));	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n###########################\r\n"));		

		DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT = WholeT_TNI;
		DramAttr->TNI_Value[RankIndex][ByteIndex].Phase = Phase_TNI;
		
		DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase = DQSI_Set;
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->TNI_Value[RankIndex][ByteIndex].Phase));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%04X\r\n", DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase));

#if 0
		//setting value
		//TNI
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_TNI);
		DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_TNI);

		//DQSI
		DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &DQSI_Set);
		DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &DQSI_Set);
#endif
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}


VOID Rx_Scan_byRank_Index_RWEngine_OnlyWholeT(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 MprNo)
{
	UINT16	Value16 = 0;
	UINT16	TNI_WHOLE_T;
	UINT8	TNI_INDEX_STEP = 4;
	UINT8	ByteBegin;
	UINT8	ByteEnd;
	BOOLEAN CheckResult = 0;	
	UINT16	TNI_Index;

	UINT16 TNI_Scan_Begin = 0x40;
	UINT16 TNI_Scan_End = 7 * 0x40;

	//UINT8  Bytetemp;

	if(ByteIndex == ALLBYTE){
		ByteBegin = 0;
		ByteEnd = 8;
	}
	else
	{
		ByteBegin = ByteIndex;
		ByteEnd = ByteIndex + 1;
	}

	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Rx DQSI/RDSIT Scan - X for DQSI, Y for TNI\r\n")); 	

	for(ByteIndex = ByteBegin; ByteIndex < ByteEnd; ByteIndex++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "Rank %02X Byte %02X\r\n", RankIndex, ByteIndex));		

		PEI_DEBUG((PeiServices, EFI_D_INFO, "  (DQSI Phase 00-3F)\r\n"));

		for (TNI_Index = TNI_Scan_Begin; TNI_Index < TNI_Scan_End; TNI_Index += TNI_INDEX_STEP)
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n TNI Index : %04X ", TNI_Index));

			//TNI  WHOLE T
			TNI_WHOLE_T = TNI_Index / 0x40; 
			Value16 = TNI_WHOLE_T;
#if 0
			for(Bytetemp = 0; Bytetemp < 8; Bytetemp++)
			{
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
				DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, Bytetemp, IO_IGNORE, IO_IGNORE, &Value16);
			}
#endif

#if 1
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
			DRAMIOCTL(PeiServices,DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, ByteIndex, IO_IGNORE, IO_IGNORE, &Value16);
#endif
			PEI_DEBUG((PeiServices, EFI_D_INFO, " (WholeT : %04X, ", Value16));

			//trigger Load Register 		
			TriggerLoadReg(PeiServices, DramAttr); 
			
			CheckResult = MemoryReadTest_ByRWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, MprNo);    //memtest by RW_Engine

			if(CheckResult)
			{
				PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
			}
			else
			{
				PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
			}
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
		}

	}

#if 0
	//setting value
	//TNI
	DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &WholeT_TNI);
	DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &Phase_TNI);

	//DQSI
	DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &DQSI_Set);
	DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &DQSI_Set);
#endif

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\r\n"));
}




//calibration releted -- add by RKD :BEG
//
extern VOID Tx_DQSO_LCU_Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsoStep);

extern VOID Tx_DQO_LCU_Sequence(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqoStep);

extern VOID Tx_DQSO_WriteLeveling(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsoStep);

extern VOID Rx_TNI_ReadLeveling(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 TniStep,
	IN BOOLEAN EccByte,
	IN UINT8 CmpEdge,
	IN UINT32 DataPattern);

extern VOID Rx_TNI_LCU(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 TniStep,
	IN UINT8 DataPattern);

extern VOID Rx_DQSI_ReadLeveling(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT32 DataPattern,
	IN BOOLEAN EccByte);

extern VOID Rx_DQSI_LCU(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT8 DataPattern);

extern VOID Rx_DQSI_Preamble_Training(
IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankNo,
	IN UINT8 DqsiStep,
	IN UINT32 DataPattern,
	IN BOOLEAN EccByte);

extern VOID HW_DQO_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr) ;

VOID HW_DQSO_WriteLeveling(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr);

VOID TX_DQSO_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!£¤n"));
		return;
	}

	Tx_DQSO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, 2);
	
}

VOID TX_DQO_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!\r\n"));
		return;
	}

	Tx_DQO_LCU_Sequence(PeiServices, pPCIPPI, DramAttr, RankIndex, 2);
}

VOID TX_WLVL_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!\r\n"));
		return;
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin Tx_DQSO_WriteLeveling\r\n"));

	Tx_DQSO_WriteLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, 0x02);

	
}

VOID RX_TNI_ReadLeveling_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"RankIndex=%d\n",RankIndex));
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!£¤n"));
		return;
	}

	Rx_TNI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, 3,  0x03,0, 0x000F3355);
}

VOID RX_TNI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!£¤n"));
		return;
	}

	Rx_TNI_LCU(PeiServices, pPCIPPI, DramAttr, RankIndex, 0x03, 0XAA);
}

VOID RX_DQSI_ReadLeveling_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!£¤n"));
		return;
	}


	Rx_DQSI_ReadLeveling(PeiServices, pPCIPPI, DramAttr, RankIndex, 2,  0x000F3355, FALSE);
}

VOID RX_DQSI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!£¤n"));
		return;
	}

	Rx_DQSI_LCU(PeiServices, pPCIPPI, DramAttr, RankIndex, 0x03, 0XAA);
}

VOID RX_DQSI_Preamble_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex;
	
	if(argc == 2)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!£¤n"));
		return;
	}

	Rx_DQSI_Preamble_Training(PeiServices, pPCIPPI, DramAttr, RankIndex, 0x03, 0x000F3355,0);
}


//Silicon calibration debug code
extern VOID RX_Scan_with_SI_Rxvref(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID RX_3DScan_By_DQSI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID RX_3DScan_By_TNI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID HW_TNI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID HW_TNI_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID HW_DQSI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID HW_DQSI_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

extern VOID HW_DQO_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr); 


extern VOID Tx_VrefDQO_Cal(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr); 

extern VOID Rx_VrefDQSI_Cal(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr); 

extern VOID HW_DQSO_LCU(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr); 

VOID HW_TNI_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 HW_TNI(PeiServices, pPCIPPI, DramAttr);
}
VOID HW_RX_2Dscan_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
//	 HW_TNI(PeiServices, pPCIPPI, DramAttr);
	 
	 RX_Scan_with_SI_Rxvref(PeiServices, pPCIPPI, DramAttr);//RX_2DSCAN
}

VOID HW_DQSO_2DSCAN_Debug(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{

	HW_DQSO_LCU_2D(PeiServices, pPCIPPI, DramAttr);


}

VOID HW_TX_WriteLeveling_Debug(
				IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
			IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
			IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
			IN DRAM_ATTRIBUTE *DramAttr,
			int argc, char *argv[])
	{
	
		HW_TX_WriteLeveling(PeiServices, pPCIPPI, DramAttr);
	
	
	}


VOID HW_RX_3Dscan_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
//	 HW_TNI(PeiServices, pPCIPPI, DramAttr);
	 
	 RX_3DScan_By_DQSI(PeiServices, pPCIPPI, DramAttr);
}
VOID TNI_RX_3Dscan_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
//	 HW_TNI(PeiServices, pPCIPPI, DramAttr);
	 
	 RX_3DScan_By_TNI(PeiServices, pPCIPPI, DramAttr);
}


VOID HW_TNI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 HW_TNI_LCU(PeiServices, pPCIPPI, DramAttr);
}

VOID HW_DQSI_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 HW_DQSI(PeiServices, pPCIPPI, DramAttr);
}

VOID HW_DQSI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 HW_DQSI_LCU(PeiServices, pPCIPPI, DramAttr);
}

VOID HW_DQO_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 HW_DQO_LCU(PeiServices, pPCIPPI, DramAttr);
}

VOID HW_TxVref_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 Tx_VrefDQO_Cal(PeiServices, pPCIPPI, DramAttr);
}
VOID HW_RxVref_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 Rx_VrefDQSI_Cal(PeiServices, pPCIPPI, DramAttr);
}

VOID HW_DQSO_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	 HW_DQSO_LCU(PeiServices, pPCIPPI, DramAttr);
}
VOID HW_DQSO_WLVL_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	HW_DQSO_WriteLeveling(PeiServices, pPCIPPI, DramAttr);
}
//calibration releted -- add by RKD :END

//daisy add for si basic set
//command line: dclkop A/B value
VOID SetDCLKOP(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT8	i=0;
	UINT16 RegValue =0;

	if(argc == 3){
		RegValue = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETDCLKOP Regvalue = %x\n", RegValue));

	if(AsiaStrnCmp(argv[1],"A",1)==0||AsiaStrnCmp(argv[1],"a",1)==0){
		for(i =0;i<=16;i+=2)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, (D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_A + i));
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		}
	}
	else if(AsiaStrnCmp(argv[1],"B",1)==0||AsiaStrnCmp(argv[1],"b",1)==0){
		for(i =0;i<=16;i+=2)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, (D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_B + i));
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		}
	}
	TriggerLoadReg(PeiServices, DramAttr);

}

//command line: dclko A/B value
VOID SetDCLKO(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT8	i=0;
	UINT16 RegValue =0;

	if(argc == 3){
		RegValue = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETDCLKO Regvalue = %x\n", RegValue));

	if(AsiaStrnCmp(argv[1],"A",1)==0||AsiaStrnCmp(argv[1],"a",1)==0){
		for(i =0;i<=16;i+=2)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, (D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_A + i));
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F00,ShiftToMaskBit(0x3F00, RegValue));
		}
	}
	else if(AsiaStrnCmp(argv[1],"B",1)==0||AsiaStrnCmp(argv[1],"b",1)==0){
		for(i =0;i<=16;i+=2)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, (D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_B + i));
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F00,ShiftToMaskBit(0x3F00, RegValue)); 
		}
	}
	TriggerLoadReg(PeiServices, DramAttr);

}

//command line: dimmclk 1/2/3/4 value 
VOID Set_Dimm_Clk(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT16 RegValue =0;


	if(argc == 3){
		RegValue = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETCLK0 Regvalue = %x\n", RegValue));

	if(AsiaStrnCmp(argv[1],"1",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCLKOA_PHASE_CTL_CHN_A);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		
	}
	else if(AsiaStrnCmp(argv[1],"2",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCLKOA_PHASE_CTL_CHN_A);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F00,ShiftToMaskBit(0x3F00, RegValue));
	}
	else if(AsiaStrnCmp(argv[1],"3",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCLKOB_PHASE_CTL_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		
	}
	else if(AsiaStrnCmp(argv[1],"4",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCLKOB_PHASE_CTL_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F00,ShiftToMaskBit(0x3F00, RegValue)); 
	}
	TriggerLoadReg(PeiServices, DramAttr);

}

//command line: cmd A/B value
VOID SetCMD(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT16 RegValue =0;


	if(argc == 3){
		RegValue = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETCMD Regvalue = %x\n", RegValue));

		if(AsiaStrnCmp(argv[1],"A",1)==0||AsiaStrnCmp(argv[1],"a",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCSA_PHASE_CTL_CHN_A);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		
	}
	else if(AsiaStrnCmp(argv[1],"B",1)==0||AsiaStrnCmp(argv[1],"b",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCSB_PHASE_CTL_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		
	}
	TriggerLoadReg(PeiServices, DramAttr);

}

//command line: cs A/B value
VOID SetCS(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT16 RegValue =0;


	if(argc == 3){
		RegValue = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETCS Regvalue = %x\n", RegValue));

	if(AsiaStrnCmp(argv[1],"A",1)==0||AsiaStrnCmp(argv[1],"a",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCSA_PHASE_CTL_CHN_A);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F00,ShiftToMaskBit(0x3F00, RegValue));
		
	}
	else if(AsiaStrnCmp(argv[1],"B",1)==0||AsiaStrnCmp(argv[1],"b",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCSB_PHASE_CTL_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F00,ShiftToMaskBit(0x3F00, RegValue));
		
	}
	TriggerLoadReg(PeiServices, DramAttr);

}

//command line: cke A/B value
VOID SetCKE(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT16 RegValue =0;


	if(argc == 3){
		RegValue = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"input error!\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"SETCKE Regvalue = %x\n", RegValue));

	if(AsiaStrnCmp(argv[1],"A",1)==0||AsiaStrnCmp(argv[1],"a",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCKEA_PHASE_CTL_CHN_A);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		
	}
	else if(AsiaStrnCmp(argv[1],"B",1)==0||AsiaStrnCmp(argv[1],"b",1)==0){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MCKEB_PHASE_CTL_CHN_B);
			AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,0x3F,RegValue);
		
	}
	TriggerLoadReg(PeiServices, DramAttr);

}


//use for bringup only
VOID Force_Rx_Scan(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT16 TNI_Start_Index = 0x40;//1T0P
	UINT16 TNI_End_Index = 5*0x40;//5T0P
	UINT16 TNI_STEP = 0x05;
	UINT16 DQSI_Start_Index = 0x0;//
	UINT16 DQSI_End_Index = 0x40;//
	UINT16 DQSI_STEP = 0x05;
	UINT16 TNI_Temp = 0 ;
	UINT16 DQSI_Temp = 0 ;

	UINT16 TX_WholeT_Start = 2;
	UINT16 TX_WholeT_End = 6;
	UINT16 TX_WholeT = 0;


	UINT8  ByteIndex =0;
	UINT32 Data32 = 0;
	UINT32 Pattern = 0x5A5A5A5A;

	UINT16 DQSO_PHASE, DQO_PHASE;
	UINT16 TNI_WholeT, TNI_PHASE;
	UINT64 Address = 0;


	/*Writeleveling;*/
	Tx_DQSO_WriteLeveling(PeiServices, pPCIPPI, DramAttr, 0, 0x02);
	//setdqso/dqo phase;
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES-1; ByteIndex++)
	{
		//read wlvl phase
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_DMIOSEL_4_0,  (0x8 << 0));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A + 2*ByteIndex);
		DQSO_PHASE = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&0x3F;

		DQO_PHASE = (DQSO_PHASE - 0x10)> 0?(DQSO_PHASE - 0x10):0 ;

		//convert
		DQSO_PHASE = Tx_DQSO_Convert_To_Value(PeiServices, DramAttr, 0, (UINT16)DQSO_PHASE);
		DQO_PHASE = Tx_DQO_Convert_To_Value(PeiServices, DramAttr, 0, (UINT16)DQO_PHASE);
		//comput dqo phase
		DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSO_PHASE);
		DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DQO_PHASE);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex:%d,DQSO_PHASE:%x, DQO_PHASE:%x\n",ByteIndex,DQSO_PHASE,DQO_PHASE)); 
	}
	TriggerLoadReg(PeiServices, DramAttr);	

	/*forloop set dqso/dqo wholeT*/
	/*write pattern*/
	/*forloop set tni/dqsi*/
	/*read pattern*/
	for(TX_WholeT = TX_WholeT_Start; TX_WholeT<TX_WholeT_End; TX_WholeT++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "TX WholeT : %d \n",TX_WholeT)); 

		for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES-1; ByteIndex++)
		{
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &TX_WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &TX_WholeT);
		}	
		//write pattern 
		*(UINT32 volatile *)(UINT32)(MemoryTest_Start+0x00) = Pattern;	
		*(UINT32 volatile *)(UINT32)(MemoryTest_Start+0x04) = Pattern;	

		//force read
		for(TNI_Temp = TNI_Start_Index; TNI_Temp < TNI_End_Index; )
		{
			for(DQSI_Temp = DQSI_Start_Index; DQSI_Temp < DQSI_End_Index;)
			{
				for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES-1; ByteIndex++)
				{
					TNI_WholeT = TNI_Temp/0x40;
					DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &TNI_WholeT);
					TNI_PHASE = TNI_Temp%0x40;
					DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &TNI_PHASE);

					DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, 0xFF, POS, &DQSI_Temp);
					DRAMIOCTL(PeiServices, DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, 0, ByteIndex, 0xFF, NEG, &DQSI_Temp);
				}
				TriggerLoadReg(PeiServices, DramAttr);	
				//read pattern
				Data32 = *(UINT32 volatile *)(UINT32)(MemoryTest_Start+0x00);	
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "TNI INDEX :%x ,DQSI PHASE:%x :Write Pattern:%08x Read Data: %08x(%08x) - ", TNI_Temp,DQSI_Temp,Pattern,Data32,Data32^Pattern)); 
				Data32 = *(UINT32 volatile *)(UINT32)(MemoryTest_Start+0x04);	
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "%08x(%08x)\n",Data32, Data32^Pattern)); 

				DQSI_Temp =  DQSI_Temp + DQSI_STEP;
			}
			TNI_Temp =  TNI_Temp + TNI_STEP;
		}
	}

}


//use for bringup only - only need scan under DDR4-3200
VOID DCLKO_Scan(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8  ByteIndex =0;
	UINT8  Dclko_index = 0;
	UINT64 Address = 0;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA DCLKO SCAN:\n")); 
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		for(Dclko_index = 0; Dclko_index <0x40; Dclko_index ++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_A + 2*ByteIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_PH_A0_DCLKO_5_0, ShiftToMaskBit(D0F3_PH_A0_DCLKO_5_0,Dclko_index));
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_DRIVING_TEST);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex:%d, Dclko_index:%d, Sync:%d\n",ByteIndex,Dclko_index,((AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&(1<<ByteIndex))>>ByteIndex))); 
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n")); 
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB DCLKO SCAN:\n")); 
	for(ByteIndex = 0; ByteIndex < ASIA_MAX_BYTES; ByteIndex++)
	{
		for(Dclko_index = 0; Dclko_index <0x40; Dclko_index ++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN,  D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_B + 2*ByteIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_PH_A0_DCLKO_5_0, ShiftToMaskBit(D0F3_PH_A0_DCLKO_5_0,Dclko_index));
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_DRIVING_TEST_Z1);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ByteIndex:%d, Dclko_index:%d, Sync:%d\n",ByteIndex,Dclko_index,((AsiaPcieRead8(DramAttr->PcieBaseAddress, Address)&(1<<ByteIndex))>>ByteIndex))); 
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n")); 
	}
}

//set debug signal for 
VOID Debug_Signal(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64  Address;
	UINT16 DebugGroup, SubModel_Selection, Signal_Selection;

	DebugGroup = (UINT16)simple_strtoul(argv[1], NULL, 16);
	SubModel_Selection = (UINT16)simple_strtoul(argv[2], NULL, 16);
	Signal_Selection = (UINT16)simple_strtoul(argv[3], NULL, 16);

	//output selection CHB
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_1);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RRDBGCHSEL_1_0, 0x01<<26);
	if(DebugGroup == 0)
	{
		//NBSB --hardcode only nbsb
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_0);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RRGFXDBGSEL_G0, 0);

		//select nb
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_0);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RRDBGNBSBSEL_G0_1_0, 0x00);

		//select submodule 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_1);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RDBGMX_NBTOP_G1_RSP_5_0, SubModel_Selection<<20);
		//select  Signal 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_1);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RDBGMX_MODULE_G0_RSP_19_0, Signal_Selection);
	}

	if(DebugGroup == 1)
	{
		//NBSB --hardcode only nbsb
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_0);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RRGFXDBGSEL_G1, 0);
		
		//select nb
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_1);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RRDBGNBSBSEL_G1_1_0, 0x00);
		
		//select submodule 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_0);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RDBGMX_NBTOP_G1_RSP_5_0, SubModel_Selection<<20);
		
		//select  Signal 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_0);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RDBGMX_MODULE_G1_RSP_19_0, Signal_Selection);
	}


	//Debug enable
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN,  D0F4_DEBUG_SEL_SIGNAL_0);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F4_RRDBGMODE, D0F4_RRDBGMODE);
}

//set debug signal for 
extern VOID Rx_Vref_SetVal_ByBit_WholeByte(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 RxVrefValue);//bit0 -> bit7

//hardcode rxvref
VOID RxVref_Hardcode(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0,ByteIndex = 0,RxVref_Value;
	UINT8 Temp_index = 0;

	RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
	ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
	RxVref_Value = (UINT8)simple_strtoul(argv[3], NULL, 16);

	if(ByteIndex == 9)
	{
		for(Temp_index = 0; Temp_index < ASIA_MAX_BYTES; Temp_index++)
			Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr, RankIndex, Temp_index, RxVref_Value);
	}
	else
		Rx_Vref_SetVal_ByBit_WholeByte(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, RxVref_Value);

}



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

extern UINT8 TxVrefTable[74];
//hardcode txvref
VOID TxVref_Hardcode(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0 , TxVrefIndex = 0;
	RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
	TxVrefIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
	//Set TX Vref 
	if(!(TxVrefTable[TxVrefIndex]&0x40)) 
		SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, TxVrefTable[TxVrefIndex]&0x3F);
	else 
		SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE2, TxVrefTable[TxVrefIndex]&0x3F);

}
