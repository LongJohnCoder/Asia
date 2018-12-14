#include"DramDebug.h"
#include "PeiLib.h"


#define MEMTST_LEN 0x4000 // 16KB
#define MSR_IA32_MTRR_CAP        0xFE
#define	MTRR_PHYS_BASE_0		0x200
#define	MTRR_PHYS_MASK_0		0x201
#define	MTRR_PHYS_BASE_1		0x202
#define	MTRR_PHYS_MASK_1		0x203
#define	MTRR_PHYS_BASE_2		0x204
#define	MTRR_PHYS_MASK_2		0x205
#define	MTRR_PHYS_BASE_3		0x206
#define	MTRR_PHYS_MASK_3		0x207
#define	MTRR_PHYS_BASE_4		0x208
#define	MTRR_PHYS_MASK_4		0x209
#define	MTRR_PHYS_BASE_5		0x20A
#define	MTRR_PHYS_MASK_5		0x20B
#define	MTRR_PHYS_BASE_6		0x20C
#define	MTRR_PHYS_MASK_6		0x20D
#define	MTRR_PHYS_BASE_7		0x20E
#define	MTRR_PHYS_MASK_7		0x20F
static UINT16 gVariableMtrrAddress[] = {
	MTRR_PHYS_BASE_0,
	MTRR_PHYS_BASE_1,
	MTRR_PHYS_BASE_2,
	MTRR_PHYS_BASE_3,
	MTRR_PHYS_BASE_4,
	MTRR_PHYS_BASE_5,
	MTRR_PHYS_BASE_6,
	MTRR_PHYS_BASE_7
};
extern VOID Rx_Scan_byRank_Index_RWEngine_OnlyWholeT(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 MprNo);

extern VOID ReadMPR_Select(
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

extern BOOLEAN MemoryReadTest_ByRWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8    RankIndex,
	IN UINT8	ByteIndex,
	IN UINT8    MprNo);

extern VOID TriggerLoadReg(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
	);
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

extern VOID Rx_Scan_byRank_Index_Sw_BaseGoodTx(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex);

extern VOID DumpTXRX(
  IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
  IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
  IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
  IN DRAM_ATTRIBUTE *DramAttr,	
  IN UINT8 IOTimingMode,
  IN UINT16 *Range,
  IN UINT8 RankNo,
  IN UINT8 MarkNo);

extern VOID DRAMIOCTL(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8   IOTimingMode,
	IN UINT8   IOSelectionMode,// manul mode(W/R) or calibration mode(R)
	IN BOOLEAN IsWrite,
	IN UINT8   RankIndex,//RankIndex cha:(0->3) chb:(4->7)
	IN UINT8   ByteIndex,
	IN UINT8   BitSelect, //mask!!! 0x01 for bit0, 0x02 for bit1,0x03 for bit0 and bit1 ....
	IN UINT8   IsPos,   //only use  for TX_DQSO RX_DQSI phase select
	IN OUT UINT16  *Value16);

extern unsigned long simple_strtoul(const char *cp,char **endp,unsigned int base);
extern INTN EFIAPI
AsiaStrnCmp (
  IN      CONST CHAR8               *FirstString,
  IN      CONST CHAR8               *SecondString,
  IN      UINTN                     Length
  );

extern VOID WriteMprPattern(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 NewPattern,
		IN UINT8 MprNo);

extern BOOLEAN MemoryTest(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,	
	IN UINT8	ByteIndex);

VOID VDump_MTRR( IN EFI_PEI_SERVICES **PeiServices);
VOID VSoft_Delay(UINTN nCount)
{
	UINTN index,tmp;
	tmp =0;
	for(index = 0 ; index < nCount; index++)
	{
		tmp++;
		AsiaIoWrite8(0x84, 0x11);
	}
}
#include "mtest.c"
#include "DramBurstTest.c"
#include "Vspiromtest.c"

void PciDump(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64   Address;
	UINT8    Data;
	UINT16	Index1, Index2;
	UINT8 BusNo, DevNo, FunNo;
	UINT16 RegBegin = 0;
	if (argc < 4)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ERROR,too few arguments"));
		return;
	}
	BusNo = (UINT8)simple_strtoul(argv[1], NULL, 16);
	DevNo = (UINT8)simple_strtoul(argv[2], NULL, 16);
	FunNo = (UINT8)simple_strtoul(argv[3], NULL, 16);

	if(argc == 5){
		RegBegin = (UINT16)simple_strtoul(argv[4], NULL, 16);
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"BusNo = %02x\r\n",BusNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"DevNo = %02x\r\n",DevNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"FunNo = %02x\r\n",FunNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"RegBegin = %04x\r\n",RegBegin));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump Bus %2x, Dev %2x, Fun %2x\n", BusNo, DevNo, FunNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "---+-----------------------------------------------\n"));
	for(Index1=0;Index1<0x20;Index1++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%03x|", Index1*16 + RegBegin));
		for(Index2=0;Index2<0x10;Index2++)
		{
			Address = AsiaPciAddress(BusNo, DevNo, FunNo, Index1*16 + Index2 + RegBegin);
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
void PciWriteByte(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64   Address;
	UINT8 BusNo, DevNo, FunNo,WriteData;
	UINT16 RegNo;
	if (argc < 6)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ERROR,too few arguments"));
		return;
	}
	BusNo = (UINT8)simple_strtoul(argv[1], NULL, 16);
	DevNo = (UINT8)simple_strtoul(argv[2], NULL, 16);
	FunNo = (UINT8)simple_strtoul(argv[3], NULL, 16);
	RegNo = (UINT16)simple_strtoul(argv[4], NULL, 16);
	WriteData = (UINT8)simple_strtoul(argv[5], NULL, 16);

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"BusNo:%02x\r",BusNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"DevNo:%02x\r",DevNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"FunNo : %02x\r",FunNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"RegNo : %08x\r",RegNo));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"WriteData : %02x\r\n",WriteData));

	Address = AsiaPciAddress(BusNo, DevNo, FunNo, RegNo);
	AsiaPcieWrite8(0xE0000000, Address, WriteData);
	return;
}
void addr_test(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	unsigned long test_base_maddr=0;
	unsigned long test_length=0;
	volatile unsigned long *pe, *p;    
	unsigned int tmp1, tmp2;
	unsigned int read_error = 0;

	/* Write each address with it's own address */
	if(argc == 3)
	{
		test_base_maddr = (unsigned long)simple_strtoul(argv[1], NULL, 16);
		test_length = (unsigned long)simple_strtoul(argv[2], NULL, 16);

	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"test_base_maddr = %08x\r\n",test_base_maddr));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"test_length = %08x\r\n",test_length));

	p = (UINT32*)test_base_maddr;
	pe = (UINT32*)(test_base_maddr+test_length);

	/* Original C code replaced with hand tuned assembly code*/
	for (; p < pe; p++) {
		*p = (UINT32)p;

	}

	/* Each address should have its own address */

	p = (UINT32*)test_base_maddr;
	pe = (UINT32*)(test_base_maddr+test_length);

	/* Original C code replaced with hand tuned assembly code */
	for (; p < pe; p++) {
		tmp1 = read_l((unsigned long)p);
		//WaitForMicroSec(PeiServices,delay_count);
		tmp2 = read_l((unsigned long)p);
		//WaitForMicroSec(PeiServices,delay_count);
		if(tmp1 != tmp2)
		{
			read_error=1;
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
						(UINT32)p,(UINT32)tmp1,(UINT32)p));
		}
		else 
			read_error=0;
		if(read_error == 0 && tmp1!= (unsigned long)p)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
						(UINT32)p,(UINT32)tmp1,(UINT32)p));
		//// print ... for indicating not hang, is running. tiger. 2014-11-19+S
		if(((UINT32)p%0x10000)==0) 
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		//// End of 2014-11-19+E			

	}

}

VOID V8bitDram_Test(IN EFI_PEI_SERVICES **PeiServices,UINT32 BaseAddr,UINT32 Length,UINT8 Data8)
{
	UINT8    Data;
	UINT32	Index1;
	UINT32    EndAddr;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Single Byte Memory Test.........\n"));
	EndAddr = BaseAddr + Length;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Single Byte Memory Test(0x%x--0x%x) Pattern = 0x%x.........\n",BaseAddr,EndAddr,Data8));
	for(Index1=BaseAddr;Index1<EndAddr;Index1++)
	{
		AsiaMemoryWrite8(Index1, Data8);
		if(Index1%0x10000==0) 
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n Delay some time, then do read test \n"));
	VSoft_Delay(0x8000000);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Begin to do Single Byte Read Memory Test(0x%8x--0x%8x).........\n",BaseAddr,EndAddr));
	for(Index1=BaseAddr;Index1<EndAddr;Index1++)
	{
		Data=AsiaMemoryRead8(Index1);
		if(Data != Data8)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "error! address 0x%8x = 0x%8x, should be 0x%8x\n", Index1, Data,Data8));	 
			break;
		}
		if((Index1%0x10000)==0) 
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "End of Single Byte Memory Test\n"));
}

VOID ZXMemoryTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 i;
	UINT32 Pattern,tstlen;
	UINT32 BaseAddr;
	BOOLEAN bRet;

	tstlen = MEMTST_LEN;
	BaseAddr = 0X100000;

	if(argc == 3){
		BaseAddr = (UINT32)simple_strtoul(argv[1], NULL, 16);	
		tstlen = (UINT32)simple_strtoul(argv[2], NULL, 16);
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"test_base_maddr = %08x\r\n",BaseAddr));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"test_length = %08x\r\n",tstlen));

	for(i=1;i<2;i++)
	{
		Pattern = TEST_PATTERN1;
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern); // Offset (i*1MB +64KB) ---- i*1MB+68KB Byte
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
		Pattern = rotate_left(Pattern,1);
		bRet = VT_DramBaseTest( PeiServices, BaseAddr, tstlen,Pattern);
		if( bRet )
		{
		}
	} 
#if 0       
	tstlen = VIA_MEMTST_LEN ; // 1MB / 4kb/ 16kb
	do
	{
		nLoop++;
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n SingleByte Read-Write Test ---- nLoop = 0x%08x \n",nLoop))	;
		for(i=1;i<2000;i++)
		{
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0x5A); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xA5); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xFE); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xFD); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xFB); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xF7); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xEF); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xDF); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xBF); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0x7F); // 		  
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "begin to do addr_tst1() \n"));
			addr_tst1(PeiServices,(i*0x100000+0x10000),tstlen);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "begin to do addr_tst2() \n"));	  
			addr_tst2(PeiServices,(i*0x100000+0x10000),tstlen);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "begin to do moving_inversions() \n"));	  
			moving_inversions(PeiServices,(i*0x100000+0x10000),tstlen);
		}
	}while(nLoop<50);
#endif	  

	return;
}

VOID JumpMemoryRead(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 i;
	UINT32 StartAddr, TestLen, JumpStep;
	UINT32 buf;
	if(argc < 4){
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ERROR,too few arguments\r\n"));	
		return;
	}
	StartAddr = (UINT32)simple_strtoul(argv[1], NULL, 16);
	TestLen= (UINT32)simple_strtoul(argv[2], NULL, 16);
	JumpStep= (UINT32)simple_strtoul(argv[3], NULL, 16);

	for(i = 0; i < TestLen; i+= JumpStep)
	{buf = AsiaMemoryRead32(StartAddr + i);
		//PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
	} 

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Read Done!\r\n"));

}

BOOLEAN ZXMemBurstTest(IN struct _EFI_PEI_SERVICES **PeiServices,
		IN UINT32                        BaseAddrMB, // unit of MB
		IN UINT32                        EndAddrMB,  // unit of MB
		IN UINT32		Pattern)
{
	UINT32 i,j;
	UINT32 testlen;
	UINT32 Buf;
	UINT32 Rdata,Rdata1;
	BOOLEAN bret = FALSE;

	testlen = 0x10000;  //64KB

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"BaseAddress = 0x%x EndAddress = 0x%x    Length = 0x%x   ,Pattern = 0x%x \n",
				BaseAddrMB * 0x100000 + 0x10000,EndAddrMB * 0x100000,  testlen, Pattern));	
	//write pattern
	for(i = BaseAddrMB; i< EndAddrMB; i++){
		Buf = i * 0x100000 + 0x10000;
		for(j = Buf; j < Buf + testlen; j+=4)
			AsiaMemoryWrite32(j, Pattern);
	}

	//read pattern 
	for(i = BaseAddrMB; i< EndAddrMB; i++){
		Buf = i * 0x100000 + 0x10000;
		for(j = Buf; j < Buf + testlen; j+=4){
			Rdata = AsiaMemoryRead32(j);
			if (Rdata != Pattern)
			{
				AsiaIoWrite8(0x80,0x2e);
				AsiaMemoryWrite32(j, Pattern);
				Rdata1 = AsiaMemoryRead32(j);	
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "1.ERROR !!!!! %08x : %08x\n", j, Rdata));
				bret = TRUE;		        
				goto Error;	

			}

			AsiaMemoryWrite32(j, ~Pattern);
		}
	} 

	//read ~pattern
	for(i = BaseAddrMB; i< EndAddrMB; i++){
		Buf = i * 0x100000 + 0x10000;
		for(j = Buf; j < Buf + testlen; j+=4){
			Rdata = AsiaMemoryRead32(j);
			if (Rdata != ~Pattern)
			{
				AsiaIoWrite8(0x80,0x2e);
				AsiaMemoryWrite32(j, ~Pattern);
				Rdata1 = AsiaMemoryRead32(j);
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "2.ERROR !!!!! %08x : %08x\n", j, Rdata));
				bret = TRUE;		        
				goto Error;	

			}

			AsiaMemoryWrite32(j, ~Pattern);
		}
	} 

Error:
	return bret;
}
////
void ZXMemAddrTest(EFI_PEI_SERVICES **PeiServices,UINT32 test_base_maddr, UINT32 test_length)
{
    //unsigned long test_base_maddr=0;
	//unsigned long test_length=0;
	volatile unsigned long *pe, *p;    
    unsigned int tmp1, tmp2;
	unsigned int read_error = 0;
	UINT32 Rdata1;
	
	/* Write each address with it's own address */
	#if 0
    if(argc == 3)
    {
       test_base_maddr = (unsigned long)simple_strtoul(argv[1], NULL, 16);
	   test_length = (unsigned long)simple_strtoul(argv[2], NULL, 16);
 
    }
	#endif
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"test_base_maddr = %08x\r\n",test_base_maddr));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"test_length = %08x\r\n",test_length));
	
	
	p = (UINT32*)test_base_maddr;
	pe = (UINT32*)(test_base_maddr+test_length);

	/* Original C code replaced with hand tuned assembly code*/
	for (; p < pe; p++) {
		*p = (UINT32)p;
		
	}
 
	/* Each address should have its own address */
			
	p = (UINT32*)test_base_maddr;
	pe = (UINT32*)(test_base_maddr+test_length);

			
	/* Original C code replaced with hand tuned assembly code */
	for (; p < pe; p++) {
		tmp1 = read_l((unsigned long)p);
		//WaitForMicroSec(PeiServices,delay_count);
		tmp2 = read_l((unsigned long)p);
        //WaitForMicroSec(PeiServices,delay_count);
		if(tmp1 != tmp2)
		{
		    read_error=1;

			AsiaIoWrite8(0x80,0x2d);
			AsiaMemoryWrite32((UINT64)p, (UINT32)p);
			Rdata1 = AsiaMemoryRead32((UINT64)p);
				
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
				(UINT32)p,(UINT32)tmp1,(UINT32)p));
		}
		else 
			  read_error=0;
		
		if(read_error == 0 && tmp1!= (unsigned long)p)
		{
			AsiaIoWrite8(0x80,0x2d);
			AsiaMemoryWrite32((UINT64)p, (UINT32)p);
			Rdata1 = AsiaMemoryRead32((UINT64)p);

			PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
				(UINT32)p,(UINT32)tmp1,(UINT32)p));
		}
			
		//// print ... for indicating not hang, is running. tiger. 2014-11-19+S
		   if(((UINT32)p%0x10000)==0) 
		        PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		//// End of 2014-11-19+E			

		}
	
}

void MemTestAsm(UINT32 StartAddr, UINT32 Len, UINT32 Pattern)
{

	Len >>= 2;
	__asm{
		push esi
			push ecx
			mov ecx, Len
			mov esi, StartAddr
			mov eax, Pattern 
			WriteLoop:
			mov [esi],eax
			add esi,4
			loop WriteLoop
			wbinvd                      ;Flush to DRAM
			mov ecx, Len
			mov esi, StartAddr
			ReadLoop:
			cmp [esi],eax
			jnz ReportError
			add esi,4
			loop ReadLoop 
			pop ecx
			pop esi
			ret
			ReportError:
			mov	al, 0EEh
			out	080h, al
			jmp ReadLoop

	}
}

extern VOID MemTest();

VOID BurstMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 MtrrBase;
	UINT64 MtrrMask;

	//// Set Cache Attributes
	MtrrBase = 0x00000006;
	MtrrMask = 0x80000800;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask);
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Enable cache 0-2GB \n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin 8 quad word test \n"));

	MemTest();
}

VOID ZXBurstTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 MtrrBase;
	UINT64 MtrrMask;
	UINT32 Pattern;

	IN UINT32                        BaseAddrMB; // unit of MB
	IN UINT32                        EndAddrMB;
	////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"into VBurst_Test() : Double Word(4bytes) write every time \n"));

	BaseAddrMB = 1;
	EndAddrMB  = 100;

	if(argc == 3)
	{
		BaseAddrMB = (UINT32)simple_strtoul(argv[1], NULL, 16);
		BaseAddrMB /= 0x100000;
		EndAddrMB  = (UINT32)simple_strtoul(argv[2], NULL, 16);
		EndAddrMB  /= 0x100000;
	}

	//// Set Cache Attributes
	MtrrBase = 0x00000006;
	MtrrMask = 0x80000800;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask);	

	Pattern = TEST_PATTERN1;
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	Pattern = rotate_left(Pattern,1);
	ZXMemBurstTest(PeiServices, BaseAddrMB, EndAddrMB,Pattern);		

	//// disable 0- 2GB Cacheable. (turn off Cache will cause HAPS hang??!!)
	MtrrBase = 0x00000000;
	MtrrMask = 0x00000000;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask);	      
	////
}

////
VOID VBurst_Test(IN EFI_PEI_SERVICES **PeiServices)
{
	UINT64 MtrrBase;
	UINT64 MtrrMask;
	UINT32 i;
	UINT32 Pattern,tstlen;

	UINT32 nLoop;

	////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"into VBurst_Test() : Double Word(4bytes) write every time \n"));
	//// Set Cache Attributes
	MtrrBase = 0x00000006;
	MtrrMask = 0x80000800;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask);	

	//// Burst test (occupied 64*2000 = 128KB)
	//VT_DramBaseTest( PeiServices, (0x10000), 0x10,0x5A5A5A5A);	
	//#if 1	
	//tstlen = 0x400;
	//for(i=0;i<1;i++)
	nLoop = 0;
	tstlen = 0x1000; // 4KB
	do
	{
		nLoop++;
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Double Word(4Bytes) Burst ---- nLoop = 0x%08x \n",nLoop));	  
		///
		for(i=1;i<2000;i+=9)
		{
			Pattern = TEST_PATTERN1;
			VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern); // Offset (i*1MB +64KB) ---- i*1MB+68KB Byte

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+1)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+2)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+3)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+4)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+5)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+6)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+7)*0x100000+0x10000), tstlen,Pattern);

			Pattern = rotate_left(Pattern,1);
			VT_DramBaseTest( PeiServices, ((i+8)*0x100000+0x10000), tstlen,Pattern);

		}
		////
	}while(nLoop<50);
	//#endif	

	//// disable 0- 2GB Cacheable. (turn off Cache will cause HAPS hang??!!)
	MtrrBase = 0x00000000;
	MtrrMask = 0x00000000;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask);	      
	////
}

VOID BurnInMemoryTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 i;
	UINT32 Pattern,tstlen;
	UINT32 nLoop;
	BOOLEAN bRet;

	//// DWORD Read/Write Test
	nLoop = 0;
	tstlen = MEMTST_LEN ; // 1MB / 4KB / 16KB
	do
	{
		nLoop++;
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Double Word Read-Write Test ---- nLoop = 0x%08x \n",nLoop));	  
		///
		for(i=1;i<2000;i++)
		{
			Pattern = TEST_PATTERN1;
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern); // Offset (i*1MB +64KB) ---- i*1MB+68KB Byte
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			Pattern = rotate_left(Pattern,1);
			bRet = VT_DramBaseTest( PeiServices, (i*0x100000+0x10000), tstlen,Pattern);
			if( bRet )
			{
				////
				//PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n Error : \n"));
			}

			///
		} 
		////
	}while(nLoop<50);

	/// Single Byte Read-Write test
#if 1       
	tstlen = MEMTST_LEN ; // 1MB / 4kb/ 16kb
	do
	{
		nLoop++;
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"\n SingleByte Read-Write Test ---- nLoop = 0x%08x \n",nLoop))	;
		for(i=1;i<2000;i++)
		{
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0x5A); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xA5); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xFE); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xFD); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xFB); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xF7); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xEF); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xDF); // 		  
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0xBF); // 
			V8bitDram_Test(PeiServices,(i*0x100000+0x10000),tstlen,0x7F); // 		  

			////
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "begin to do addr_tst1() \n"));
			addr_tst1(PeiServices,(i*0x100000+0x10000),tstlen);

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "begin to do addr_tst2() \n"));	  
			addr_tst2(PeiServices,(i*0x100000+0x10000),tstlen);

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "begin to do moving_inversions() \n"));	  
			moving_inversions(PeiServices,(i*0x100000+0x10000),tstlen);
		}
		////
	}while(nLoop<50);
#endif	  

	//// do Burst test
#if 1	
	VBurst_Test(PeiServices);
	//#if 0 
	//#endif
#endif

	////
	return;
}


VOID TestVrToPr(
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
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "VR-->PR : %02X\r\n", RankIndex)); 

		//Clear all VRank size
		ClearAllRankSize(DramAttr);
		
		//set PRn to VRn and set size to 0~1024MB
		SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);

		//Then do memtest and check the cycle sent to the rank which you want
	}
}

VOID DumpAllTimingReg(
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
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump Rank %02X RX/TX All IOTiming Register!!!\r\n", RankIndex)); 
		
		DumpTXRX(PeiServices, pPCIPPI, DramAttr, IO_MANUAL, NULL, RankIndex, 0x52);
	}
}	


VOID ClearTXTiming(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	//UINT16 RegIndex;
	//UINT64 Address;

	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	UINT16 DQSO_WholeT = 0;
	UINT16 DQSO_Phase = 0;
	UINT16 DQO_WholeT = 0;
	UINT16 DQO_Phase = 0;
	
#if 0
	//Tx DQSO WHOLE T = 1T
	//D0F3_Rx A3C~A4E
	for (RegIndex = D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A; RegIndex <= D0F3_TX_WHOLE_T_TIMING_CTL_B8_CHN_B; RegIndex += 2)
	{
		if (RegIndex == D0F3_TX_WHOLE_T_TIMING_CTL_A8_CHN_A || RegIndex == D0F3_TX_WHOLE_T_TIMING_CTL_B8_CHN_B)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (BIT4 + BIT5 + BIT6), 0x10);
		}
		else
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,(BIT12 + BIT13 + BIT14) | (BIT4 + BIT5 + BIT6) , 0x1010);
		}
	}

	//DQO WHOLET = 2T
	for (RegIndex = D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A; RegIndex <= D0F3_TX_WHOLE_T_TIMING_CTL_B8_CHN_B; RegIndex += 2)
	{
		if (RegIndex == D0F3_TX_WHOLE_T_TIMING_CTL_A8_CHN_A || RegIndex == D0F3_TX_WHOLE_T_TIMING_CTL_B8_CHN_B)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (BIT0 + BIT1 + BIT2) , 0x01);
		}
		else
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,(BIT8 + BIT9 + BIT10) | (BIT0 + BIT1 + BIT2), 0x0101);
		}
	}
#endif

	if(argc == 3){
		DQSO_WholeT = (UINT16)simple_strtoul(argv[1], NULL, 16);
		DQO_WholeT  = (UINT16)simple_strtoul(argv[2], NULL, 16);
	}
	

	//DQSO_WholeT = 1;
	DQSO_Phase = 0;
	//DQO_WholeT = 1;
	DQO_Phase = 0;
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
		{
			//Setting Value Tx
			//DQSO
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSO_WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DQSO_Phase);

			//DQO
			DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DQO_WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DQO_Phase);
		}
	}

	TriggerLoadReg(PeiServices, DramAttr);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Clear Tx Timing Done!!!\r\n")); 

}

VOID ClearRXTiming(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	//UINT16 RegIndex;
	//UINT64 Address;

	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	UINT16 TNI_WholeT = 0;
	UINT16 TNI_Phase = 0;
	UINT16 DQSI_Phase = 0;
	
#if 0
	//DKS-20170515 -add -s	
	//RX TNI WHOLE T = 2T
	//D0F3_Rx A0C~A3A
	for (RegIndex = D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A0_A1_A2_A3_CHN_A; RegIndex <= D0F3_RX_WHOLE_T_TIMING_CTL_RANK7_B8_CHN_B; RegIndex += 2)
	{
		if (RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A8_CHN_A || RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK1_A8_CHN_A || 
				RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK2_A8_CHN_A || RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK3_A8_CHN_A ||
				RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK4_B8_CHN_B || RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK5_B8_CHN_B ||
				RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK6_B8_CHN_B || RegIndex == D0F3_RX_WHOLE_T_TIMING_CTL_RANK7_B8_CHN_B)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (BIT0 + BIT1 + BIT2), 0x01);
		}
		else
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,(BIT12 + BIT13 + BIT14) | (BIT8 + BIT9 + BIT10) |
					(BIT4 + BIT5 + BIT6) | (BIT0 + BIT1 + BIT2), 0x1111);
		}
	}
#endif

	if(argc == 2){
		TNI_WholeT = (UINT16)simple_strtoul(argv[1], NULL, 16);
	}
	
	//TNI_WholeT = 1;
	TNI_Phase = 0;
	DQSI_Phase = 0;
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
		{
			//setting value Rx
			//TNI 
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &TNI_WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &TNI_Phase);

			//DQSI
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &DQSI_Phase);
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &DQSI_Phase);
		}
	}
		
	TriggerLoadReg(PeiServices, DramAttr);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Clear Rx Timing Done!!!\r\n")); 
}

VOID CalCheckSum(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 checksum  =0;
	UINT32 i;
	for(i = 0x10000000; i < 0x20000000; i += 2)
	{
		checksum += AsiaMemoryRead16(i);
	}

	checksum = (checksum >> 16) + (checksum & 0xffff);
	checksum += (checksum >> 16);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "checksum = %08x \r\n", ~checksum)); 

}
VOID PutFuncToMemory(
		IN EFI_PEI_SERVICES **PeiServices	 
		)
{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Put memcpy function to 0x1000 0000 \n"));
	VPutFunc2Mem(PeiServices);
	///
	VDumpMem8(PeiServices,(VOID*)0x10000000,0x40);	
	///
}
VOID SpiromTest(
		IN EFI_PEI_SERVICES **PeiServices    
		)
{
	//UINT32 cnt;

	//cnt=0;
	//VSpi_ReadTest(PeiServices);// Read SPIROM 3 times, and write to different DRAM region      
	//VSpi_DumpRegs(PeiServices);
	// VSpi_ReadTest1(PeiServices); // Read SPIROM once, write to 3 different DRAM region.	
#if 0
	VSpi_ReadTest(PeiServices);// Read SPIROM 3 times, and write to different DRAM region     
	VSpi_ReadTest1(PeiServices);
	VSpi_ReadTest2(PeiServices);	
#else
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "cnt = 0x%x \n",cnt));
	//VSpi_HWReadTst(PeiServices);             
	VSpi_CacheCpyTst(PeiServices);
	///
#endif
}
//
VOID TgrMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Tiger's 500 loop Memory and SPIROM Test\n"));
	PutFuncToMemory(PeiServices);
	SpiromTest(PeiServices);
}
//IoRead8
UINT8 do_io_read(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT16 addr;
	//int rc = 0;

	/* We use the last specified parameters, unless new ones are
	 * entered.
	 */

	//length = dp_last_length;
	if (argc > 2){

		//printf("%s %s [%d]: parameters more than 1!\r\n", __FILE__, __func__, __LINE__);
		return 0;
	}

	/* New command specified.  Check for a size specification.
	 * Defaults to long if no or incorrect specification.
	 */

	/* Address is specified since argc > 1
	*/
	addr = (UINT16)simple_strtoul(argv[1], NULL, 16);

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Io Read:\r\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"addr = %02x\r\n",addr));

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"%02x \r\n",AsiaIoRead8(addr)));

	return (AsiaIoRead8(addr));
}

//IoWrite8
UINT8 do_io_write(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT16 addr;
	UINT8 dat;
	//int rc = 0;

	/* We use the last specified parameters, unless new ones are
	 * entered.
	 */

	//length = dp_last_length;
	if (argc > 3){

		//printf("%s %s [%d]: parameters more than 2!\r\n", __FILE__, __func__, __LINE__);
		return 0;
	}

	/* New command specified.  Check for a size specification.
	 * Defaults to long if no or incorrect specification.
	 */

	/* Address is specified since argc > 1
	*/
	addr = (UINT16)simple_strtoul(argv[1], NULL, 16);
	dat =  (UINT8)simple_strtoul(argv[2], NULL, 16);

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Io Write:\r\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"addr = %02x\r\n",addr));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"data = %02x\r\n",dat));

	//PEI_DEBUG((PeiServices, EFI_D_ERROR,"%08x ",AsiaIoWrite8(addr,dat)));
	AsiaIoWrite8(addr,dat);

	return (1);
}

#define Test_Size 0x1000	// 4K
#define Test_Start 0x210000 //	2M +64K
#define RW_repeat_Number	64

VOID BurstWrite(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{

	UINT32	WriteAddress_Start = Test_Start;
	UINT32	WriteAddress;
	UINT32	Data32	= 0;
	UINT32	Repeat;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Burst_Write 0x210000~64MB \n"));

	//Memory test in 1M + N*64K + (32-64K) range only
	for(Repeat = 0; Repeat<RW_repeat_Number;  Repeat++)
	{
		Data32 = 0;
		for(WriteAddress = WriteAddress_Start; WriteAddress< (WriteAddress_Start+Test_Size);  WriteAddress+=0x40)
		{
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x00) = 0x00000000;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x04) = 0x00000000;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x08) = 0xffffffff;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x0C) = 0xffffffff;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x10) = 0x00000000;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x14) = 0x00000000;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x18) = 0xffffffff;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x1C) = 0xffffffff;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x20) = 0x00000000;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x24) = 0x00000000;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x28) = 0xffffffff;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x2C) = 0xffffffff;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x30) = 0x00000000;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x34) = 0x00000000;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x38) = 0xffffffff;	
			*(UINT32 volatile *)(UINT32)(WriteAddress+0x3C) = 0xffffffff;	
			//			Data32 = LShiftU64(Data32, 1);
			Data32 = ((Data32&0x80000000)>>31)|(Data32<<1);
		}
		WriteAddress_Start += 0x100000;
	}

}

VOID BurstRead(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32	ReadAddress_Start = Test_Start;
	UINT32	ReadAddress;
	UINT32	Data32;

	UINT32	Repeat;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Burst_Read 0x210000~64MB\n"));

	ReadAddress_Start = Test_Start;
	//Memory test in 1M + N*64K + (32-64K) range only
	for(Repeat = 0; Repeat<RW_repeat_Number;  Repeat++)
	{

		for(ReadAddress = ReadAddress_Start; ReadAddress< (ReadAddress_Start+Test_Size);  ReadAddress+=0x40)
		{

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x00);				

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x04);				

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x08);	

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x0C);

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x10);					

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x14);				

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x18);	

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x1C);

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x20);				

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x24);					

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x28);	

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x2C);

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x30);	

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x34);					

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x38);	

			Data32 = *(UINT32 volatile *)(UINT32)(ReadAddress+0x3C);

		}
		ReadAddress_Start += 0x100000;
	}

}

VOID DisCache(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 MtrrBase;
	UINT64 MtrrMask;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Disable cache 0-2GB\n"));
	//// disable 0- 2GB Cacheable. (turn off Cache will cause HAPS hang??!!)
	MtrrBase = 0x00000000;
	MtrrMask = 0x00000000;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask);	      
	////
}

VOID EnCache(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 MtrrBase;
	UINT64 MtrrMask;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Enable cache 0-2GB \n"));
	//// Set Cache Attributes
	MtrrBase = 0x00000006;
	MtrrMask = 0x80000800;
	__writemsr(MTRR_PHYS_BASE_2, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_2 + 1, MtrrMask); 
}



void  Zxrand (UINT32 *SEED_X, UINT32 *SEED_Y)
{
	UINT32 a = 18000, b = 30903;

	*SEED_X = a*((*SEED_X)&65535) + (*SEED_X>>16);
	*SEED_Y = b*((*SEED_Y)&65535) + (*SEED_Y>>16);

}

VOID RandMemTest(IN EFI_PEI_SERVICES **PeiServices,UINT32 StartAddr,UINT32  TestLength)
{
	UINT32 i; 
	UINT32 SEED_X = 521288629, SEED_Y = 362436069;
	UINT32 TestAddr;
	UINT32 ReadData;
	UINT32 EndAddr;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Random Memory Test"));
	//Init SEED
	SEED_X = 521288629; 
	SEED_Y = 362436069;

	EndAddr = StartAddr + TestLength;
	//Write 
	for(i = 0;i < TestLength; i+=4)
	{

		Zxrand(&SEED_X, &SEED_Y);

		TestAddr = ((SEED_X<<16) + (SEED_Y&65535));

		//Ensure   StartAddr   <= TestAddr <= EndAddr
		TestAddr &= (EndAddr-1);		   		   
		TestAddr |= StartAddr;
		//Ensure   TestAddr%4 = 0
		TestAddr &= 0xFFFFFFF4;
		AsiaMemoryWrite32(TestAddr, TestAddr);

	}

	//Init SEED
	SEED_X = 521288629; 
	SEED_Y = 362436069;
	//Read
	for(i = 0;i < TestLength; i+=4)
	{

		Zxrand(&SEED_X, &SEED_Y);

		TestAddr = ((SEED_X<<16) + (SEED_Y&65535));
		//Ensure   StartAddr   <= TestAddr <= EndAddr
		TestAddr &= (EndAddr-1);		   		   
		TestAddr |= StartAddr;
		//Ensure   TestAddr%4 = 0
		TestAddr &= 0xFFFFFFF4;
		ReadData = AsiaMemoryRead32(TestAddr);

		if(ReadData != TestAddr){
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
						(UINT32)TestAddr,(UINT32)ReadData,(UINT32)TestAddr));}

		if(i % 0x400 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Test Address = 0x%08x\r\n", TestAddr));
	} 	

}

VOID ZxRandMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32  TestLength;
	UINT32 StartAddr;

	StartAddr = 0x100000;
	TestLength = 0x20000000;

	if(argc == 3){
		StartAddr = (UINT32)simple_strtoul(argv[1], NULL, 16);
		TestLength = (UINT32)simple_strtoul(argv[2], NULL, 16);
	}
	RandMemTest(PeiServices, StartAddr, TestLength);

}

VOID JumpMemTest(IN EFI_PEI_SERVICES **PeiServices,UINT32 StartAddr, UINT32 TestLen, UINT32 JumpStep)
{

	UINT32 i,j;

	UINT32 Pattern = 0X3c3c3c3c;
	UINT32 ReadData;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin Jump Memory Test: StartAddr=0x%08x, TestLen=0x%08x, JumpStep=0x%08x",StartAddr, TestLen, JumpStep));

	//write
	for(i = 0;i < JumpStep; i += 4){

		for(j = i; j < TestLen; j+= JumpStep)
		{
			AsiaMemoryWrite32(StartAddr + j, Pattern);

		} 
		Pattern = rotate_left(Pattern,1); 
		if(i % 0x400 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
	}

	//read
	Pattern = 0X3c3c3c3c;
	for(i = 0;i < JumpStep; i += 4){

		for(j = i; j < TestLen; j+= JumpStep)
		{
			ReadData = AsiaMemoryRead32(StartAddr + j);

			if(ReadData != Pattern){
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
							(UINT32)(StartAddr + j),(UINT32)ReadData,(UINT32)Pattern));}

			//write ~pattern
			AsiaMemoryWrite32(StartAddr + j, ~Pattern);

		} 
		Pattern = rotate_left(Pattern,1);
		if(i % 0x400 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
	}

	//read ~pattern
	Pattern = 0X3c3c3c3c;
	for(i = 0;i < JumpStep; i += 4){

		for(j = i; j < TestLen; j+= JumpStep)
		{
			ReadData = AsiaMemoryRead32(StartAddr + j);

			if(ReadData != ~Pattern){
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
							(UINT32)(StartAddr + j),(UINT32)ReadData,(UINT32)Pattern));}

		}
		Pattern = rotate_left(Pattern,1); 	
		if(i % 0x400 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
	}

}

VOID ZxJumpMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{

	UINT32 StartAddr, TestLen, JumpStep;
	StartAddr = 0x10000000;
	TestLen = 0x1000000;

	//Make Bank miss JumpStep = 0x8000,    Make Page miss JumpStep = 0X20000
	JumpStep = 0x8000;

	if(argc == 4){
		StartAddr = (UINT32)simple_strtoul(argv[1], NULL, 16);
		TestLen= (UINT32)simple_strtoul(argv[2], NULL, 16);
		JumpStep= (UINT32)simple_strtoul(argv[3], NULL, 16);
	}

	JumpMemTest(PeiServices, StartAddr, TestLen, JumpStep);

}

VOID JumpAddrTest(IN EFI_PEI_SERVICES **PeiServices,UINT32 StartAddr, UINT32 TestLen, UINT32 JumpStep)
{

	UINT32 i,j;
	UINT32 ReadData,ReadData1;
	UINT8 readerror;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin Jump Address Test: StartAddr=0x%08x, TestLen=0x%08x, JumpStep=0x%08x",StartAddr, TestLen, JumpStep));

	//write
	for(i = 0;i < JumpStep; i += 4){

		for(j = i; j < TestLen; j+= JumpStep)
		{
			AsiaMemoryWrite32(StartAddr + j, StartAddr + j);

		} 

		if(i % 0x400 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
	}

	//read   
	for(i = 0;i < JumpStep; i += 4){

		for(j = i; j < TestLen; j+= JumpStep)
		{
			ReadData = AsiaMemoryRead32(StartAddr + j);
			ReadData1 = AsiaMemoryRead32(StartAddr + j);
			if(ReadData != ReadData1)
			{
				AsiaIoWrite8(0x80, 0x14);

				//trigger write 0x100000
				AsiaMemoryWrite32(0x100000, 0x5A5A5A5A);   
				readerror = 1;
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
							(UINT32)(StartAddr + j),(UINT32)ReadData,(UINT32)(StartAddr + j)));
			}
			else 
				readerror = 0;

			if((readerror == 0) && (ReadData != (StartAddr + j))){
				AsiaIoWrite8(0x80, 0x13);

				//trigger write 0x110000
				AsiaMemoryWrite32(0x110000, 0x5A5A5A5A); 
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
							(UINT32)(StartAddr + j),(UINT32)ReadData,(UINT32)(StartAddr + j)));}           		   

		} 

		if(i % 0x400 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
	}

}
VOID ZxJumpAddrTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{

	UINT32 StartAddr, TestLen, JumpStep;
	//UINT32 Pattern = 0X3c3c3c3c;

	StartAddr = 0x10000000;
	TestLen = 0x1000000;

	//Make Bank miss JumpStep = 0x8000,    Make Page miss JumpStep = 0X20000
	JumpStep = 0x8000;

	if(argc == 4){
		StartAddr = (UINT32)simple_strtoul(argv[1], NULL, 16);
		TestLen= (UINT32)simple_strtoul(argv[2], NULL, 16);
		JumpStep= (UINT32)simple_strtoul(argv[3], NULL, 16);
	}

	JumpAddrTest(PeiServices, StartAddr, TestLen, JumpStep);

}

VOID CopyByte(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 Source, Destination, Length;
	UINT32 i;
	Source = (UINT32)simple_strtoul(argv[1], NULL, 16);
	Destination= (UINT32)simple_strtoul(argv[2], NULL, 16);
	Length= (UINT32)simple_strtoul(argv[3], NULL, 16);

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin Copy: Source= 0x%08x, Destination= 0x%08x, Length= 0x%08x\r\n",Source, Destination, Length));

	for(i = 0; i < Length; i++ )
	{
		*(volatile UINT8 *)(Destination + i) = *(volatile UINT8 *)(Source + i);
	}

}

VOID CmpByte(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{

	UINT32 Source, Destination, Length;
	UINT32 i;
	UINT8 Temp1,Temp2;
	Source = (UINT32)simple_strtoul(argv[1], NULL, 16);
	Destination= (UINT32)simple_strtoul(argv[2], NULL, 16);
	Length= (UINT32)simple_strtoul(argv[3], NULL, 16);

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin Compare: Source= 0x%08x, Destination= 0x%08x, Length= 0x%08x\r\n",Source, Destination, Length));

	for(i = 0; i < Length; i++ )
	{
		Temp2 = *(volatile UINT8 *)(Destination + i);
		Temp1 = *(volatile UINT8 *)(Source + i); 
		if(Temp1 != Temp2)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Compare Fail: address = 0x%08x, Data =0x%08x, should = 0x%08x \r\n",Destination + i, Temp2,Temp1 ));

	} 

}

VOID Write2ReadTest(IN EFI_PEI_SERVICES **PeiServices, UINT32 StartAddr, UINT32 TestLen, UINT32 JumpStep)
{

	UINT32 i,j;
	UINT32 Pattern = 0X5A5A5A5A;
	UINT32 ReadData;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin Write to Read Test: StartAddr = 0x%08x, TestLen = 0x%08x\r\n",StartAddr,TestLen));

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Simple Write to Read test\r\n")); 
	for(i = 0;i < TestLen; i += 4)
	{

		AsiaMemoryWrite32(StartAddr + i, Pattern);
		ReadData = AsiaMemoryRead32(StartAddr + i);
		if(ReadData != Pattern)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
						StartAddr + i, ReadData, Pattern));
		}	  

		Pattern = rotate_left(Pattern,1); 
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Cross Bank  Write to Read test\r\n"));
	//Init Pattern
	Pattern = 0X5A5A5A5A;
	for(j = 0; j< JumpStep; j+= 4)
	{

		AsiaMemoryWrite32(StartAddr + j, Pattern);
		Pattern = rotate_left(Pattern,1);

	}

	for(i = JumpStep; i < TestLen; i += JumpStep)
	{
		//Init Pattern
		Pattern = 0X5A5A5A5A;
		for(j = i; j < i+JumpStep; j+= 4)
		{
			//Write  i --- i  + JumpStep
			AsiaMemoryWrite32(StartAddr + j, Pattern);

			//Read   i-JumpStep --i
			ReadData = AsiaMemoryRead32( StartAddr + j - JumpStep);
			if(ReadData != Pattern){

				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%08x = 0x%08x, should be 0x%08x\r\n",
							StartAddr + j - JumpStep, ReadData, Pattern));
			}
			Pattern = rotate_left(Pattern,1);  	

		}
	}

}

VOID CmdWrite2ReadTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{

	UINT32 StartAddr = 0X1000000;
	UINT32 TestLen = 0X100000;
	UINT32 JumpStep = 0x8000;

	if(argc == 4){
		StartAddr = (UINT32)simple_strtoul(argv[1], NULL, 16);
		TestLen= (UINT32)simple_strtoul(argv[2], NULL, 16);
		JumpStep= (UINT32)simple_strtoul(argv[3], NULL, 16);
	}

	Write2ReadTest(PeiServices, StartAddr, TestLen, JumpStep);

}

extern VOID FlushCfgWrite(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT64 Address);

//CHX002 doesn't support CRC/Parity
VOID CRCInjectSingleError(IN EFI_PEI_SERVICES **PeiServices, IN DRAM_ATTRIBUTE *DramAttr,int argc, char *argv[])
{}
//Inject multi error
VOID CRCInjectMultiError(IN EFI_PEI_SERVICES **PeiServices, IN DRAM_ATTRIBUTE *DramAttr,int argc, char *argv[])
{}
//Inject Uncorrectable error
VOID CRCInjectUCError(IN EFI_PEI_SERVICES **PeiServices, IN DRAM_ATTRIBUTE *DramAttr,int argc, char *argv[])
{}
VOID ParInjectSingleError(IN EFI_PEI_SERVICES **PeiServices, IN DRAM_ATTRIBUTE *DramAttr,int argc, char *argv[])
{}
//Inject multi error
VOID ParInjectMultiError(IN EFI_PEI_SERVICES **PeiServices, IN DRAM_ATTRIBUTE *DramAttr,int argc, char *argv[])
{}
//Inject Uncorrectable error
VOID ParInjectUCError(IN EFI_PEI_SERVICES **PeiServices, IN DRAM_ATTRIBUTE *DramAttr,int argc, char *argv[])
{}

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

VOID CmdSwSetTxVref(
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
	UINT32 VrefDQ;
	UINT8 VrefRange;
	
	RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
	VrefRange = (UINT8)simple_strtoul(argv[2], NULL, 16);
	VrefDQ = (UINT32)simple_strtoul(argv[3], NULL, 16); 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set TxVref RankIndex = %d, TxVref Range = %d, TxVref Value =%d \r\n", RankIndex, VrefRange, VrefDQ));

	if (VrefRange == 1)
		SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE1, VrefDQ);
	else
		SwSetTxVref(PeiServices, pPCIPPI, DramAttr, RankIndex, VREF_RANGE2, VrefDQ);
}


VOID CmdRWEngineTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	BOOLEAN CheckResult = 0;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CmdRWEngineTest!!! ByteIndex = %d, RankIndex = %d\r\n", 0, 0));

	ReadMPR_Select(PeiServices, pPCIPPI, DramAttr, 0, 0, 1);  //enable MPR mode
	
	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, 0);
	
	CheckResult = MemoryReadTest_ByRWEngine(PeiServices, pPCIPPI, DramAttr, 0, 0, 0);    //memtest by RW_Engine

	if(CheckResult)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
	}

	ReadMPR_Select(PeiServices, pPCIPPI, DramAttr, 0, 0, 0);  //disable MPR mode
}

VOID CmdMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 ByteIndex;
	UINT8 RankIndex;
	BOOLEAN CheckResult = 0;

	RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
	ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CmdMemTest!!! ByteIndex = %d, RankIndex = %d\r\n", ByteIndex, RankIndex));
	
	//Clear all VRank size
	ClearAllRankSize(DramAttr);
	
	//set PRn to VRn and set size to 0~1024MB
	SetTargetRankToFirst256MB(PeiServices, pPCIPPI, DramAttr, RankIndex);
	
	CheckResult = MemoryTest(PeiServices, pPCIPPI, DramAttr, ByteIndex);	//memtest normal
	
	if(CheckResult)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "O"));	
	}
	else
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "_"));	
	}
}


#if 0

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

VOID CmdSwSetRxVref(
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
	UINT8 VrefDQ;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RxVref\r\n"));

	RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
	VrefDQ = (UINT8)simple_strtoul(argv[2], NULL, 16); 

	Rx_Vref_SetVal(PeiServices, pPCIPPI, DramAttr, RankIndex,VrefDQ);
}
#endif

extern VOID PDASetMRS(
		IN EFI_PEI_SERVICES **PeiServices,	 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		IN UINT8 RankIndex,
		IN UINT8 ChipNo,
		IN UINT32 VrefDQ);

VOID CmdPDA(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ChipNo = 0;
	UINT32 VrefDQ = 0x32;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "PDA SET VREF\r\n"));

	if(argc == 4){
		RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ChipNo = (UINT8)simple_strtoul(argv[2], NULL, 16);
		VrefDQ = (UINT32)simple_strtoul(argv[3], NULL, 16); 
	}

	PDASetMRS(PeiServices, pPCIPPI, DramAttr, RankIndex, ChipNo, VrefDQ);

}

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
	IN UINT8 MPR);


VOID CmdMprRead(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 MPRPAGE = 2;
	UINT8 MPR =0x00;

	if(argc >= 3){
		RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		MPRPAGE = (UINT8)simple_strtoul(argv[2], NULL, 16);		
		MPR = (UINT8)simple_strtoul(argv[3], NULL, 16);		
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read MPR RankIndex =%d,page=%x, MPR =%d\r\n",RankIndex, MPRPAGE,MPR));

	ReadMPR(PeiServices, pPCIPPI, DramAttr, RankIndex, MPRPAGE, MPR);
}



VOID CmdMprWrite(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 NewPattern = 2;
	UINT8 MprNo = 0x00;

	if(argc >= 4){
		RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		NewPattern = (UINT8)simple_strtoul(argv[2], NULL, 16); 	
		MprNo = (UINT8)simple_strtoul(argv[3], NULL, 16); 	
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read MPR RankIndex = %d, NewPattern = %x, MprNo = %d	\r\n", RankIndex, NewPattern, MprNo));

	WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankIndex, NewPattern, MprNo);
}

VOID ECC_ErrorInjectionOneBit(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 BitIndex = 0;
	UINT64 Address;
	UINT16 DATA;
	//UINT32 i;
	UINT32 err_address;
	UINT32 err_base = 0x2000000;
	
	if(argc == 2)
	{
		BitIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
	}

	//////////////////////(2) Injection Test --- Ecc 1 bit Error at all address//////////////////////////
	//Enable ECC and injecion 1 bit error
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin:Injection Test --- Ecc 1 bit Error at all address \r\n"));
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN | D0F3_RERREN, D0F3_RECCEN | D0F3_RERREN);  
	AsiaPcieRead16(0XE0000000, Address);

	//Enable ECC Error report  and  clear ECC error status
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);   
	AsiaPcieRead16(0XE0000000, Address);


	//disable error injection
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

	//clear memory 
	 {
		 UINT32 Memindex = 0;
		for(Memindex = 0; Memindex < 0x10000; Memindex+=4)
		{
            AsiaMemoryWrite32(err_base + Memindex, 0); 
			if(Memindex/0x400 == 0)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	 }
	
	//KEEP Clear error report
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
	}
	
	//Injection 1 bit error 0-63 then write/read and read out the syndrome bit
	{
		WaitForMicroSec(PeiServices, 200);
		
		//enable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, D0F3_RERREN);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_3);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)BitIndex);  
		AsiaPcieRead8(0XE0000000, Address);

		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1BE= 0x%02x\r\n", DATA));

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1B6= 0x%02x\r\n", DATA));

		AsiaMemoryWrite32(0x200000 + BitIndex * 0x10, BitIndex);
		
		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}
		
		AsiaMemoryRead32(0x200000 + BitIndex * 0x10);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_PATTERN);
		DATA = ((AsiaPcieRead16(0XE0000000, Address)) & 0xFF00 ) >> 8;  
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"error bit: %d , the syndrome bit is 0x%02x\r\n", BitIndex, (UINT8)DATA));

		//Readout the ECC error status and then clear it
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"shoud be 1 bit error Rx1B6 = 0x%04x\r\n", DATA));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}
		
		//readout the rank info--CHA
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RANK_INF_FOR_CHA_CHB);
		DATA = AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CHA Error Rank info  Rx22C = 0x%02x\r\n", DATA));

		//disable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

		//Clear memory
		AsiaMemoryWrite32(err_base + BitIndex * 0x10, BitIndex);
		AsiaMemoryWrite32(err_base + BitIndex * 0x10, BitIndex);
		AsiaMemoryWrite32(err_base + BitIndex * 0x10, BitIndex);
		AsiaMemoryWrite32(err_base + BitIndex * 0x10, BitIndex);
		AsiaMemoryWrite32(err_base + BitIndex * 0x10, BitIndex);
		
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"End:Injection Test ---Ecc 1 bit Error at all address\r\n"));





	/////////////////////(3) Injection Test --- Ecc 1 bit Error at specified address/////////////////////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin :Injection Test --- Ecc 1 bit Error at specified address\r\n"));
	// Enable ECC and injection 1 bit error at speified address
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN | D0F3_RERREN | D0F3_RERRADDREN, D0F3_RECCEN | D0F3_RERREN | D0F3_RERRADDREN);  
	AsiaPcieRead16(0XE0000000, Address);

	//Enable ECC Error report and clear ECC Error status
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
	AsiaPcieRead16(0XE0000000, Address);



    //disable error injection
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);
	//clear memory 
	 {
		 UINT32 Memindex = 0;
		for(Memindex = 0; Memindex < 0x10000; Memindex+=4)
		{
            AsiaMemoryWrite32(err_base + Memindex, 0); 
			if(Memindex/0x400 == 0)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	 }
	//KEEP Clear error report
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
	}


	//Injection 1 bit error 0-63 then write/read and read out the syndrome bit
	{   
		WaitForMicroSec(PeiServices, 200);
			
	    //enable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, D0F3_RERREN);
		
		//err bit
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_3);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)BitIndex);  
		AsiaPcieRead8(0XE0000000, Address);

		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1BE = 0x%02x\r\n", DATA));

		//err address
		err_address = err_base + BitIndex * 0x3456;
		err_address = err_address >> 4;

		//err_address =((err_address & 0xFF)<<24 )|(((err_address>>8) & 0xFF ) << 16)|(((err_address >>16)& 0xFF)<<8) |(((err_address >>24) &0xFF));

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2_Z1);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)(err_address & 0xFFFF));  

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)((err_address >> 16) & 0xFFFF));
		
		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);

		
		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}

		// read the spec address
		AsiaMemoryRead32(err_base + BitIndex * 0x3456);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_PATTERN);
		DATA = ((AsiaPcieRead16(0XE0000000, Address)) & 0xFF00 ) >> 8;  
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"error bit: %d , the syndrome bit is 0x%02x\r\n", BitIndex, (UINT8)DATA));

		// read out the error address
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA_Z1);
		err_address = (UINT32)(AsiaPcieRead16(0XE0000000, Address) << 16); 

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA);
		err_address = (UINT32)AsiaPcieRead16(0XE0000000, Address) | err_address;
			
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx21A-->Rx21D = 0x%08x\r\n", err_address));

		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Set error address: 0x%08x , Register show error address: 0x%08x\r\n", (err_base + BitIndex * 0x3456) >> 3, err_address));

		//Enable ECC Error report 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));


		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
			AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}


		//readout the rank info--CHA
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RANK_INF_FOR_CHA_CHB);
		DATA = AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CHA Error Rank info  Rx22C = 0x%04x\r\n", DATA));


		 //disable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

#if 0
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Write 1st..."));
		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Write 2nd..."));

		
		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));
#endif

#if 1
		//Clear memory
 		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);
 		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);
 		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);
 		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);
 		AsiaMemoryWrite32(err_base + BitIndex * 0x3456, BitIndex);
#endif
	}

 	//disable error injection address
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RERRADDREN, 0);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"END :Injection Test --- Ecc 1 bit Error at specified address\r\n"));
}


VOID ECC_ErrorInjectionMultiBit(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;
	UINT16 DATA;
	//UINT32 i;
	UINT32 err_address;
	UINT32 err_base = 0x2000000;
	

	/////////////////////(3) Injection Test --- Ecc 1 bit Error at specified address/////////////////////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin : ECC_ErrorInjectionMultiBit at specified address\r\n"));
	// Enable ECC and injection 1 bit error at speified address
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN | D0F3_RERREN | D0F3_RERRADDREN, D0F3_RECCEN | D0F3_RERREN | D0F3_RERRADDREN);  
	AsiaPcieRead16(0XE0000000, Address);

	//Enable ECC Error report and clear ECC Error status
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
	AsiaPcieRead16(0XE0000000, Address);



    //Injection multi bit error
	//enable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, D0F3_RERREN);
		
		//err bit
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_3);
		AsiaPcieWrite8(0XE0000000, Address, D0F3_RERR2B);  
		AsiaPcieRead8(0XE0000000, Address);

		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1BE = 0x%02x\r\n", DATA));

		//err address
		err_address = err_base + 0x3456;
		err_address = err_address >> 4;

		//err_address =((err_address & 0xFF)<<24 )|(((err_address>>8) & 0xFF ) << 16)|(((err_address >>16)& 0xFF)<<8) |(((err_address >>24) &0xFF));

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2_Z1);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)(err_address & 0xFFFF));  

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)((err_address >> 16) & 0xFFFF));
		
		AsiaMemoryWrite32(err_base + 0x3456,0);

		
		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}

		// read the spec address
		AsiaMemoryRead32(err_base + 0x3456);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_SYNDROME_MULIT_BIT);
		DATA = ((AsiaPcieRead16(0XE0000000, Address)) & 0xFF00 ) >> 8;  
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"multi bit0&1, the syndrome bit is 0x%02x\r\n", (UINT8)DATA));

		// read out the error address
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA_Z1);
		err_address = (UINT32)(AsiaPcieRead16(0XE0000000, Address) << 16); 

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA);
		err_address = (UINT32)AsiaPcieRead16(0XE0000000, Address) | err_address;
			
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx21A-->Rx21D = 0x%08x\r\n", err_address));

		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Set error address: 0x%08x , Register show error address: 0x%08x\r\n", (err_base + 0x3456) >> 3, err_address));

		//Enable ECC Error report 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));


		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
			AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}


		//readout the rank info--CHA
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RANK_INF_FOR_CHA_CHB);
		DATA = AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CHA Error Rank info  Rx22C = 0x%04x\r\n", DATA));


		//disable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

#if 0
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Write 1st..."));
		AsiaMemoryWrite32(err_base + 0x3456,0);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Write 2nd..."));

		
		AsiaMemoryWrite32(err_base + 0x3456,0);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));
#endif

#if 1
		//Clear memory
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
#endif

	
 	//disable error injection address
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RERRADDREN, 0);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"END : ECC_ErrorInjectionMultiBit at specified address\r\n"));
}



VOID ECC_ErrorStatusCheck(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;
	UINT16 DATA;
	UINT32 index;
	UINT32 base = 0x2000000;

	//first of all, don't clear memory!!!

	// Enable ECC
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN, D0F3_RECCEN);  
	AsiaPcieRead16(0XE0000000, Address);


	//Enable ECC Error report
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS);   
	AsiaPcieRead16(0XE0000000, Address);

	
	for (index = 0; index < 50; index++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Read %d ...\r\n", index));
		AsiaMemoryRead32(base + index * 0x80);
		
		// read out the Ecc Error Status
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"read out the Ecc Error Status...\r\n"));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1B6 = 0x%04x\r\n", DATA));


		PEI_DEBUG((PeiServices, EFI_D_ERROR,"clear Ecc Error Status...\r\n"));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  

		WaitForMicroSec(PeiServices, 200);
		
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6 = 0x%04x\r\n", DATA));
	}
	
}


VOID RCD_Test_Function(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"RCD_Test_Function begin.......\r\n"));
	
	////////////////////////////////////RCD patch////////////////////////////////////////////
	//RDCLKOAPM = 1
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRIO_CHN_A_B_DYNAMIC_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDCLKOAPM, D0F3_RDCLKOAPM);

	//RDCLKOBPM = 1
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRIO_CHN_A_B_DYNAMIC_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDCLKOBPM, D0F3_RDCLKOBPM);

	//RDYNPM = 1
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_PM_MODE);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDYNPM, D0F4_RDYNPM);

	//RDRAMCPM = 1
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_DRAMC_PM_REG_3);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDRAMCPM, D0F4_RDRAMCPM);

	//RDIMM_STAB = 02
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PDA_MODE_CTL_ECC);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDIMM_STAB_7_0, 0x02 << 8);

	//RFLOATDIMCLK = 0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFLOATDIMCLK, 0);
	/////////////////////////////////////////////////////////////////////////////////////////

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"RCD_Test_Function Done!.......\r\n"));
}


VOID ECC_ErrorInjection(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;
	UINT16 DATA;
	UINT32 i;
	UINT32 err_address;
	UINT32 err_base = 0x2000000;


	//////////////////(1) Basic ECC TEST///////////////////////////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin:Basic ECC TEST \r\n"));
	// Enable ECC
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN, D0F3_RECCEN);  
	AsiaPcieRead16(0XE0000000, Address);

	// Enable ECC Error report and clear Ecc Error Status
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
	AsiaPcieRead16(0XE0000000, Address);

	// Write a data in a address
	AsiaMemoryWrite32(0x200600 ,0x5a5a5a5a);

	// read out the Ecc Error Status---should be 1/2 bit Error
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	DATA=AsiaPcieRead16(0XE0000000, Address); 
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"should be 1/2 bit Error : Rx1B6 = 0x%04x\r\n", DATA));
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
	DATA=AsiaPcieRead16(0XE0000000, Address);
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

	// Write to the same address
	AsiaMemoryWrite32(0x200600 ,0x5a5a5a5a);

	//read out the Ecc Error status-- No Error report
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	DATA=AsiaPcieRead16(0XE0000000, Address); 
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"No Error : Rx1B6 = 0x%04x\r\n", DATA));
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
	DATA=AsiaPcieRead16(0XE0000000, Address);
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"END:Basic ECC TEST \r\n"));





	//////////////////////(2) Injection Test --- Ecc 1 bit Error at all address//////////////////////////
	//Enable ECC and injecion 1 bit error
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin:Injection Test --- Ecc 1 bit Error at all address \r\n"));
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN | D0F3_RERREN, D0F3_RECCEN | D0F3_RERREN);  
	AsiaPcieRead16(0XE0000000, Address);

	//Enable ECC Error report  and  clear ECC error status
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);   
	AsiaPcieRead16(0XE0000000, Address);

	//disable error injection
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);
	//clear memory 
	 {
		 UINT32 Memindex = 0;
		for(Memindex = 0; Memindex < 0x10000; Memindex+=4)
		{
            AsiaMemoryWrite32(err_base + Memindex, 0); 
			if(Memindex/0x400 == 0)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	 }
	//KEEP Clear error report
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
	}
	
	//Injection 1 bit error 0-63 then write/read and read out the syndrome bit
	for(i = 0 ; i < 64 ; i++ )
	{
		WaitForMicroSec(PeiServices, 200);
		
		//enable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, D0F3_RERREN);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_3);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)i);  
		AsiaPcieRead8(0XE0000000, Address);

		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1BE= 0x%02x\r\n", DATA));

		AsiaMemoryWrite32(0x200000 + i * 0x10,i);
		
		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}

		AsiaMemoryRead32(0x200000 + i * 0x10);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_PATTERN);
		DATA = ((AsiaPcieRead16(0XE0000000, Address)) & 0xFF00 ) >> 8;  
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"error bit: %d , the syndrome bit is 0x%02x\r\n", i, (UINT8)DATA));

		//Readout the ECC error status and then clear it
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"shoud be 1 bit error Rx1B6 = 0x%04x\r\n", DATA));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6 = 0x%04x\r\n", DATA));

		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}
		
		//readout the rank info--CHA
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RANK_INF_FOR_CHA_CHB);
		DATA = AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CHA Error Rank info  Rx22C = 0x%02x\r\n", DATA));

		//disable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

		//Clear memory
		AsiaMemoryWrite32(err_base + i* 0x10,i);
		AsiaMemoryWrite32(err_base + i* 0x10,i);
		AsiaMemoryWrite32(err_base + i* 0x10,i);
		AsiaMemoryWrite32(err_base + i* 0x10,i);
		AsiaMemoryWrite32(err_base + i* 0x10,i);
		
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"End:Injection Test ---Ecc 1 bit Error at all address\r\n"));





	/////////////////////(3) Injection Test --- Ecc 1 bit Error at specified address/////////////////////
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Begin :Injection Test --- Ecc 1 bit Error at specified address\r\n"));
	// Enable ECC and injection 1 bit error at speified address
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN | D0F3_RERREN | D0F3_RERRADDREN, D0F3_RECCEN | D0F3_RERREN | D0F3_RERRADDREN);  
	AsiaPcieRead16(0XE0000000, Address);

	//Enable ECC Error report and clear ECC Error status
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
	AsiaPcieRead16(0XE0000000, Address);



    //disable error injection
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);
	//clear memory 
	 {
		 UINT32 Memindex = 0;
		for(Memindex = 0; Memindex < 0x10000; Memindex+=4)
		{
            AsiaMemoryWrite32(err_base + Memindex, 0); 
			if(Memindex/0x400 == 0)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	 }
	//KEEP Clear error report
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
	}


	//Injection 1 bit error 0-63 then write/read and read out the syndrome bit
	for(i = 0 ; i < 64 ; i++ )
	{   
		WaitForMicroSec(PeiServices, 200);
			
	    //enable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, D0F3_RERREN);
		
		//err bit
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_3);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)i);  
		AsiaPcieRead8(0XE0000000, Address);

		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1BE = 0x%02x\r\n", DATA));

		//err address
		err_address = err_base + i* 0x3456;
		err_address = err_address >> 4;

		//err_address =((err_address & 0xFF)<<24 )|(((err_address>>8) & 0xFF ) << 16)|(((err_address >>16)& 0xFF)<<8) |(((err_address >>24) &0xFF));

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2_Z1);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)(err_address & 0xFFFF));  

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)((err_address >> 16) & 0xFFFF));
		
		AsiaMemoryWrite32(err_base + i* 0x3456,i);

		
		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}

		// read the spec address
		AsiaMemoryRead32(err_base + i* 0x3456);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_PATTERN);
		DATA = ((AsiaPcieRead16(0XE0000000, Address)) & 0xFF00 ) >> 8;  
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"error bit: %d , the syndrome bit is 0x%02x\r\n", i, (UINT8)DATA));

		// read out the error address
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA_Z1);
		err_address = (UINT32)(AsiaPcieRead16(0XE0000000, Address) << 16); 

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA);
		err_address = (UINT32)AsiaPcieRead16(0XE0000000, Address) | err_address;
			
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx21A-->Rx21D = 0x%08x\r\n", err_address));

		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Set error address: 0x%08x , Register show error address: 0x%08x\r\n", (err_base + i* 0x3456) >> 3, err_address));

		//Enable ECC Error report 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));


		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
			AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}


		//readout the rank info--CHA
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RANK_INF_FOR_CHA_CHB);
		DATA = AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CHA Error Rank info  Rx22C = 0x%04x\r\n", DATA));


		 //disable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

		//Clear memory
		AsiaMemoryWrite32(err_base + i* 0x3456,i);
		AsiaMemoryWrite32(err_base + i* 0x3456,i);
		AsiaMemoryWrite32(err_base + i* 0x3456,i);
		AsiaMemoryWrite32(err_base + i* 0x3456,i);
		AsiaMemoryWrite32(err_base + i* 0x3456,i);
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"END :Injection Test --- Ecc 1 bit Error at specified address\r\n"));



	//Injection multi bit error
	 //enable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, D0F3_RERREN);
		
		//err bit
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_3);
		AsiaPcieWrite8(0XE0000000, Address, D0F3_RERR2B);  
		AsiaPcieRead8(0XE0000000, Address);

		DATA=AsiaPcieRead8(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx1BE = 0x%02x\r\n", DATA));

		//err address
		err_address = err_base + 0x3456;
		err_address = err_address >> 4;

		//err_address =((err_address & 0xFF)<<24 )|(((err_address>>8) & 0xFF ) << 16)|(((err_address >>16)& 0xFF)<<8) |(((err_address >>24) &0xFF));

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2_Z1);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)(err_address & 0xFFFF));  

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_2);
		AsiaPcieWrite16(0XE0000000, Address, (UINT16)((err_address >> 16) & 0xFFFF));
		
		AsiaMemoryWrite32(err_base + 0x3456,0);

		
		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}

		// read the spec address
		AsiaMemoryRead32(err_base + 0x3456);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_SYNDROME_MULIT_BIT);
		DATA = ((AsiaPcieRead16(0XE0000000, Address)) & 0xFF00 ) >> 8;  
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"multi bit0&1, the syndrome bit is 0x%02x\r\n", (UINT8)DATA));

		// read out the error address
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA_Z1);
		err_address = (UINT32)(AsiaPcieRead16(0XE0000000, Address) << 16); 

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_ERR_REPORT_ADR_CHA);
		err_address = (UINT32)AsiaPcieRead16(0XE0000000, Address) | err_address;
			
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Rx21A-->Rx21D = 0x%08x\r\n", err_address));

		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Set error address: 0x%08x , Register show error address: 0x%08x\r\n", (err_base + 0x3456) >> 3, err_address));

		//Enable ECC Error report 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		DATA=AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"ECC error status:Rx1B6 = 0x%04x\r\n", DATA));
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
											D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		DATA=AsiaPcieRead16(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"After Clear ECC error status:Rx1B6= 0x%04x\r\n", DATA));


		//KEEP Clear error report
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(0xE0000000, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
			AsiaPcieModify16(0xE0000000, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
		}


		//readout the rank info--CHA
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RANK_INF_FOR_CHA_CHB);
		DATA = AsiaPcieRead16(0XE0000000, Address); 
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CHA Error Rank info  Rx22C = 0x%04x\r\n", DATA));


		 //disable error injection
	    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RERREN, 0);

		//Clear memory
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);
		AsiaMemoryWrite32(err_base + 0x3456,0);

}





/******************************************/
//   TX RX  IOTIMING  SCAN CODE--- BEGIN  //
/******************************************/



extern VOID Tx_Scan_byRank_Index_Sw(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex);


extern VOID Tx_Scan_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex);

extern VOID Tx_Scan_byRank_Index_RWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex);



VOID CmdTxScan(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	if(argc >= 3)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
    }
    Tx_Scan_byRank(PeiServices, pPCIPPI, DramAttr,RankIndex,ByteIndex);

}

VOID CmdTxScanIndexRWEngine(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	if(argc >= 3)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
    }
    Tx_Scan_byRank_Index_RWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex);

}


VOID ClsAllSetting(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;

	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
		{
			DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT = 0;
			DramAttr->TNI_Value[RankIndex][ByteIndex].Phase = 0;

			DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase = 0;

			DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT = 0;
			DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase = 0;

			DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT = 0;
			DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase  = 0;
		}
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "ClsAllSetting Done!!!\r\n")); 
}


VOID DumpAllSetting(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n############### TNI ##############\r\n")); 
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(WholeT: %02X | Phase: %02X) ", 
				DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT, 
				DramAttr->TNI_Value[RankIndex][ByteIndex].Phase)); 
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n")); 
	}


	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n############### DQSI ##############\r\n"));
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "(Phase: %02X) ", DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
	}


	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n############### DQSO ##############\r\n"));
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		if (RankIndex == 0 || RankIndex == 4)
		{
			for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(WholeT: %02X | Phase: %02X) ", 
					DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT, 
					DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
		}
	}


	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n############### DQO ##############\r\n"));
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		if (RankIndex == 0 || RankIndex == 4)
		{
			for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
			{
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "(WholeT: %02X | Phase: %02X) ", 
					DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT, 
					DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase));
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\n"));
		}
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DumpAllSetting Done!!!\r\n")); 
}

VOID SetAllSetting(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	
	for (RankIndex = 0; RankIndex < 8; RankIndex++)
	{
		for (ByteIndex = 0; ByteIndex < 9; ByteIndex++)
		{
			//setting value Rx
			//TNI
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_TNI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->TNI_Value[RankIndex][ByteIndex].Phase);

			//DQSI
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_POS, &DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase);
			DRAMIOCTL(PeiServices,DramAttr, IO_DQSI_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, 0xFF, IO_NEG, &DramAttr->DQSI_Value[RankIndex][ByteIndex].Phase);

			//Setting Value Tx
			//DQSO
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQSO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->DQSO_Value[RankIndex / 4][ByteIndex].Phase);

			//DQO
			DRAMIOCTL(PeiServices, DramAttr, IO_DQO_WHOLE_T, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->DQO_Value[RankIndex / 4][ByteIndex].WholeT);
			DRAMIOCTL(PeiServices, DramAttr, IO_DQO_PHASE, IOCTL_MANUAL, WRITE, RankIndex, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->DQO_Value[RankIndex / 4][ByteIndex].Phase);
		}
	}

	//Set other Rank in same TNI T for a Channel(only using for bringup 1Rx8 DIMM in one Channel)
	for (ByteIndex = 0; ByteIndex < 9; ByteIndex++){
		for (RankIndex = 0; RankIndex < 4; RankIndex++){
			if (DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT != 0){
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 0, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT);
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 1, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT);
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 2, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT);
				DRAMIOCTL(PeiServices, DramAttr, IO_TNI_WHOLE_T, IOCTL_MANUAL, WRITE, 3, ByteIndex, IO_IGNORE, IO_IGNORE, &DramAttr->TNI_Value[RankIndex][ByteIndex].WholeT);
				break;
			}
		}
	}
	
	TriggerLoadReg(PeiServices, DramAttr);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "SetAllSetting Done!!!\r\n")); 
}

VOID CmdTxScanIndexSw(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	
	if(argc >= 3)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
    }
	
    Tx_Scan_byRank_Index_Sw(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex);

}



extern VOID Rx_Scan_byRank(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 MprNo);

extern VOID Rx_Scan_byRank_Index_RWEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN UINT8 MprNo);




extern VOID Rx_Scan_byRank_Index_Sw(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT8 ByteIndex,
	IN ReadTest *readtest);





VOID ReadMPR_Select(
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



	


VOID CmdRxScan(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	UINT8 MprNo = 0;
	UINT8 MprValue = MR3_MPR_PAGE0;
	
	if(argc >= 3)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
		MprNo = (UINT8)simple_strtoul(argv[3], NULL, 16);
    }

	switch (MprNo)
	{	
		case 0:
			MprValue = MR3_MPR_PAGE0;
			break;
		case 1:
			MprValue = MR3_MPR_PAGE1;
			break;
		case 2:
			MprValue = MR3_MPR_PAGE2;
			break;
		case 3:
			MprValue = MR3_MPR_PAGE3;
			break;
	}
	
	ReadMPR_Select(PeiServices, pPCIPPI, DramAttr, RankIndex, MprValue, 1);  //enable MPR mode
    Rx_Scan_byRank(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, MprNo);
	ReadMPR_Select(PeiServices, pPCIPPI, DramAttr, RankIndex, MprValue, 0);  //disable MPR mode
	

}


VOID CmdRxScanIndexRWEngine(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	UINT8 MprNo = 0;
	
	UINT8 MPRPAGE = 0;
	
	UINT8 NewPattern = 0x55; //01010101
	
	MprNo = 3;
		
	if(argc == 3)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
		//MprNo = (UINT8)simple_strtoul(argv[3], NULL, 16);
    }
	
	//RankIndex = 4;
	//ByteIndex = 2;
	WriteMprPattern(PeiServices, pPCIPPI, DramAttr, RankIndex, NewPattern, MprNo);
	ReadMPR_Select(PeiServices, pPCIPPI, DramAttr, RankIndex, MPRPAGE, 1);  //enable MPR mode
#if 1
    Rx_Scan_byRank_Index_RWEngine(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, 0);
#else
	Rx_Scan_byRank_Index_RWEngine_OnlyWholeT(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, MprNo);
#endif
	ReadMPR_Select(PeiServices, pPCIPPI, DramAttr, RankIndex, MPRPAGE, 0);  //disable MPR mode
	
}




VOID CmdRxScanIndexSwBaseTx(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	
	if(argc >= 3)
    {
        RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);
    }
	
	Rx_Scan_byRank_Index_Sw_BaseGoodTx(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex);
	
}


VOID CmdRxScanIndexSw(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[])
{
	UINT8 RankIndex = 0;
	UINT8 ByteIndex = 0;
	UINT8 index;

	ReadTest *readtest;

	(*PeiServices)->AllocatePool(
		PeiServices,
		sizeof(ReadTest),
		&readtest
	);  
  
	//Clear 0
	(*PeiServices)->SetMem(readtest, sizeof(ReadTest), 0);
	
	if(argc == 12)
	{
		RankIndex = (UINT8)simple_strtoul(argv[1], NULL, 16);
		ByteIndex = (UINT8)simple_strtoul(argv[2], NULL, 16);

		readtest->ReadAddr   = (UINT32)simple_strtoul(argv[3], NULL, 16);
		readtest->Pattern[0] = (UINT32)simple_strtoul(argv[4], NULL, 16);
		readtest->Pattern[1] = (UINT32)simple_strtoul(argv[5], NULL, 16);
		readtest->Pattern[2] = (UINT32)simple_strtoul(argv[6], NULL, 16);
		readtest->Pattern[3] = (UINT32)simple_strtoul(argv[7], NULL, 16);
		readtest->Pattern[4] = (UINT32)simple_strtoul(argv[8], NULL, 16);
		readtest->Pattern[5] = (UINT32)simple_strtoul(argv[9], NULL, 16);
		readtest->Pattern[6] = (UINT32)simple_strtoul(argv[10], NULL, 16);
		readtest->Pattern[7] = (UINT32)simple_strtoul(argv[11], NULL, 16);
	}
	//RankIndex = 4;
	//ByteIndex = 2;

	for (index = 0; index < 8; index++)
		PEI_DEBUG((PeiServices, EFI_D_INFO, "readtest->Pattern[%d] = %08x\r\n", index, readtest->Pattern[index]));
	
	Rx_Scan_byRank_Index_Sw(PeiServices, pPCIPPI, DramAttr, RankIndex, ByteIndex, readtest);
	
}


/******************************************/
//   TX RX  IOTIMING  SCAN CODE--- END  //
/******************************************/




/******************************************/
//   CHECLOST  CODE--- BEGIN  //
/******************************************/
VOID CheckPREA(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
   UINT64 Address;

   PEI_DEBUG((PeiServices, EFI_D_ERROR,"Checklist verify 5.6 Support page close/page close all request\n"));
   
   //Disable REF	
   Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
   AsiaPcieModify16(0xE0000000, Address,D0F3_REFC_7_0, 0);

   //Enable page mode
   Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
   AsiaPcieModify16(0xE0000000, Address, D0F3_RPGEN, D0F3_RPGEN);
   //RPGTIM = 01
   AsiaPcieModify16(0xE0000000, Address, D0F3_RPGTIM_3_0, 0x01 << 12);
   //RPGSCLSAL = 01
   AsiaPcieModify16(0xE0000000, Address, D0F3_RPGSCLSAL_6_0, 0x01);

}

VOID map64page(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;
	//UINT16 DATA;
	//UINT32 i;
	//UINT32 err_address;
	//UINT32 err_base = 0x2000000;

	//Disable Interleave

	
	//Disable SelfRefresh Counter
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
	AsiaPcieModify16(0XE0000000, Address, D0F3_REFC_7_0, 0 << 8);

	//Multiple page mode Enable
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RPGEN, D0F3_RPGEN);

	//RPGTIM[3:0] = 0000
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RPGTIM_3_0, 0 << 12);


	//send 16 different page Address
	/* haps DIMM x8 2R */
	/*
	  *
	  *  BG1              BG0              BA1            BA0        A16    A15    A14    A13    A12    A11    A10    A9     A8     A7     A6     A5     A4     A3     A2     A1     A0
		                  19^24 		                                 34       33      32      31      30       29      28      27     26     25     24      23     22     21     20      16     13
	     15^20          14^7	           18^23       17^22 						                                 AP      12     11     10      9       8        7       6       5       4        3
	  */
	AsiaMemoryRead32(0x1000000);
	AsiaMemoryRead32(0x1020000);
	AsiaMemoryRead32(0x1040000);
	AsiaMemoryRead32(0x1060000);
	AsiaMemoryRead32(0x1004000);
	AsiaMemoryRead32(0x1024000);
	AsiaMemoryRead32(0x1044000);
	AsiaMemoryRead32(0x1064000);
	AsiaMemoryRead32(0x1008000);
	AsiaMemoryRead32(0x1028000);
	AsiaMemoryRead32(0x1048000);
	AsiaMemoryRead32(0x1068000);
	AsiaMemoryRead32(0x100C000);
	AsiaMemoryRead32(0x102C000);
	AsiaMemoryRead32(0x104C000);
	AsiaMemoryRead32(0x106C000);

	//send the same page address like before 16 address
	
}

VOID turnaround(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT8 Value;
	UINT64 Address;
	
	if(argc == 2)
    {
        Value = (UINT8)simple_strtoul(argv[1], NULL, 16);
    }
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!\n"));
		return;
	}

	switch(Value)
	{
		case 0: //Test 0T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 0T!!!\n"));
			
			//RFR2W=000b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0);

			//RFW2W=000b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0);

			//RFR2R=000b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0);

			//RFW2R=000b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0);
			
			break;
		}
		case 1: //Test 1T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 1T!!!\n"));
			
			//RFR2W=001b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x01 << 4);

			//RFW2W=001b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x01 << 12);

			//RFR2R=001b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x01 << 8);

			//RFW2R=001b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x01);
			
			break;
		}	
		case 2: //Test 2T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 2T!!!\n"));
			
			//RFR2W=010b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x02 << 4);

			//RFW2W=010b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x02 << 12);

			//RFR2R=010b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x02 << 8);

			//RFW2R=010b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x02);
			
			break;
		}
		case 3: //Test 3T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 3T!!!\n"));
			
			//RFR2W=011b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x03 << 4);

			//RFW2W=011b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x03 << 12);

			//RFR2R=011b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x03 << 8);

			//RFW2R=011b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x03);
			
			break;
		}
		case 4: //Test 4T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 4T!!!\n"));
			
			//RFR2W=100b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x04 << 4);

			//RFW2W=100b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x04 << 12);

			//RFR2R=100b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x04 << 8);

			//RFW2R=100b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x04);
			
			break;
		}
		case 5: //Test 5T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 5T!!!\n"));
			
			//RFR2W=101b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x05 << 4);

			//RFW2W=101b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x05 << 12);

			//RFR2R=101b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x05 << 8);

			//RFW2R=101b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x05);
			
			break;
		}
		case 6: //Test 6T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 6T!!!\n"));
			
			//RFR2W=110b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x06 << 4);

			//RFW2W=110b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x06 << 12);

			//RFR2R=110b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x06 << 8);

			//RFW2R=110b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x06);
			
			break;
		}
		case 7: //Test 7T turn around
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Setting Turn Around 7T!!!\n"));
			
			//RFR2W=111b
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2W_2_0, 0x07 << 4);

			//RFW2W=111b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2W_2_0, 0x07 << 12);

			//RFR2R=111b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFR2R_2_0, 0x07 << 8);

			//RFW2R=111b
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFW2R_2_0, 0x07);
			
			break;
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"Set Turn Around %xT Done!!!\n", Value));
}


VOID patrol_scrub(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"patrol_scrub test begin!!!\n"));

	// Enable ECC
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN, D0F3_RECCEN);  
	AsiaPcieRead16(0XE0000000, Address);

	//Set D0F3Rx24E[15:5](CHA) = 00, Patrol Begin Address Part 0 Channel A =00
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_BEG_36_26, 0);  
	AsiaPcieRead16(0XE0000000, Address);
	
	//Set D0F3Rx250[15:5](CHA) = 0X0400, Patrol End Address Part 0 Channel A =2GB
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_END_ADR_CHN_A);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_END_36_26, 0X0400 << 5);  
	AsiaPcieRead16(0XE0000000, Address);
	
	//Set D0F3Rx24E[4]=1, RSCREN = 1£¬Enable Patrol Scrub Control
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RSCREN, D0F3_RSCREN);  
	AsiaPcieRead16(0XE0000000, Address);
	
	//enable Rx24E[2]=1 (scurb on CHA), Patrol address enable Channel A
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
	AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_EN, D0F3_RPATROL_ADDR_EN);  
	AsiaPcieRead16(0XE0000000, Address);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"patrol_scrub test Done!!!\n"));
}




VOID ReadWriteEngine_DealCore(EFI_PEI_SERVICES **PeiServices, DRAM_ATTRIBUTE *DramAttr, UINT64 BeginAddress, UINT32 Burstlength, UINT8 DIMMType, UINT8 Flag)
{
	UINT64 Address;
	UINT8  Index;
	UINT64 BeginAddressTmp;
	UINT64 ErrorAddress;
	UINT8 EndIndex;
	UINT8 AddrTmp;
	
	if (DIMMType == 1)  //ECC DIMM or RDIMM
	{
		EndIndex = 9;
	}
	else                //UDIMM
	{
		EndIndex = 8;
	}

	
	if (DIMMType == 1)  //ECC DIMM or RDIMM
	{
		//(1)Enable ECC
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RECCEN, D0F3_RECCEN);  
		AsiaPcieRead16(0XE0000000, Address);

		//(2)Enable ECC Error report and clear Ecc Error Status
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(0XE0000000, Address, D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA, 
												D0F3_RSUE_STATUS | D0F3_RSCE_STATUS | D0F3_RMEFS_CHB | D0F3_RSEFS_CHB | D0F3_RMEFS_CHA | D0F3_RSEFS_CHA);  
		AsiaPcieRead16(0XE0000000, Address);


		///////////////Use DRAMC or Use SW/////////////////
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		if (Flag == 1)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Use DRAMC to calculate value fill in byte 8!!!\r\n"));
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_D0F3_RX1B7B9, D0F3_D0F3_RX1B7B9);
		}
		else
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Use SW to calculate value fill in byte 8!!!\r\n"));
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_D0F3_RX1B7B9, 0);
		}
		//////////////////////////////////////////////////
	}


	//Set RSRW_ADDR[37:3] for start address
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_ADDR[37:3] for start address!!!\r\n")); 
	BeginAddressTmp = RShiftU64(BeginAddress, 3);
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(BeginAddressTmp, 8 * Index) & 0xFF));
	}

	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z4);
	AsiaPcieModify8(0XE0000000, Address, D0F3_RSRW_ADDR_37_35, (UINT8)(RShiftU64(BeginAddress, 35) & 0x07));


	//////////////DKS:::dump information 0x296-0x29A/////////////////
	for (Index = 0; Index < 5; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE + Index);
		AddrTmp = AsiaPcieRead8(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[ 0x%03x ] = 0x%02x\r\n", 0x296 + Index, AddrTmp));
	}
	//////////////////////////////////////////////////////////////


	//Set RSRW_LENGTH[31:0] for burst length
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_LENGTH[31:0] for burst length!!!\r\n"));
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(Burstlength, 8 * Index) & 0xFF));
	}


	//////////////DKS:::dump information 0x29B-0x29E/////////////////
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE + Index);
		AddrTmp = AsiaPcieRead8(0XE0000000, Address);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[ 0x%03x ] = 0x%02x\r\n", 0x29B + Index, AddrTmp));
	}
	//////////////////////////////////////////////////////////////



	//Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern!!!\r\n"));
	for (Index = 0; Index < 8; Index++)
	{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x5A);
		
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x3C);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x2D);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x4B);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x87);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x96);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x2E);

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x3F);
	}



	if (DIMMType == 1)   //ECC DIMM or RDIMM
	{
		if (Flag == 0)   //Use SW to calculate value fill in byte 8
		{
			///////////////////add ECC Byte patern///////////////////
			/* AA     BB     CC     DD     EE     FF     33     00 */
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSDATAPAT0[71:64], RSDATAPAT1[71:64], RSDATAPAT2[71:64], RSDATAPAT3[71:64], RSDATAPAT4[71:64], RSDATAPAT5[71:64], RSDATAPAT6[71:64], RSDATAPAT7[71:64] for write data pattern!!!\r\n"));
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RESULT_OF_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x99);
				
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RESULT_OF_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x00);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x66);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0xFF);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x66);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z1);
			AsiaPcieWrite8(0XE0000000, Address, 0x00);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z2);
			AsiaPcieWrite8(0XE0000000, Address, 0x99);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0xFF);
		}
		else  //Use DRAMC to calculate value fill in byte 8
		{ 
			///////////////////add ECC Byte patern///////////////////
			/* 99     00     66      FF     66     00     99     FF */
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSDATAPAT0[71:64], RSDATAPAT1[71:64], RSDATAPAT2[71:64], RSDATAPAT3[71:64], RSDATAPAT4[71:64], RSDATAPAT5[71:64], RSDATAPAT6[71:64], RSDATAPAT7[71:64] for write data pattern!!!\r\n"));
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RESULT_OF_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x99);
				
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_RESULT_OF_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x00);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x66);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0xFF);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0x66);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z1);
			AsiaPcieWrite8(0XE0000000, Address, 0x00);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z2);
			AsiaPcieWrite8(0XE0000000, Address, 0x99);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_ECC_RESULT_OF_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE);
			AsiaPcieWrite8(0XE0000000, Address, 0xFF);
		}
	}
	

	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0)
	{
		//Trigger reg_RSWR to active DRAMCA write engine
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger reg_RSWR to active DRAMCA write engine!!!\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSWR, D0F3_REG_RSWR);

		//Wait for reg_RSWR being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT0)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSWR done!!!\r\n"));
	}

#if 1
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0)
	{
		//Trigger  reg_RSWR_CHB to active DRAMCB write engine
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger  reg_RSWR_CHB to active DRAMCB write engine!!!\r\n"));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSWR_CHB, D0F3_REG_RSWR_CHB);

		//Wait for reg_RSWR_CHB being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT2)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSWR_CHB done!!!\r\n"));
	}
#endif


	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0)
	{
		//Trigger reg_RSRD to active DRAMCA read engine
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger reg_RSRD to active DRAMCA read engine!!!\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSRD, D0F3_REG_RSRD);

		//Wait for reg_RSRD being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT1)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD done!!!\r\n"));
	}


#if 1
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0)
	{
		//Trigger reg_RSRD_CHB to active DRAMCB read engine
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD_CHB to active DRAMCB read engine!!!\r\n"));
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSRD_CHB, D0F3_REG_RSRD_CHB);


		//Wait for reg_RSRD_CHB being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT3)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSRD_CHB done!!!\r\n"));
	}
#endif



	//Read RSER_ADDR[37:3] which stands for the QW address where error occurs
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Read RSER_ADDR[37:3] which stands for the QW address where error occurs!!!\r\n"));
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ERR_ADR_FOR_MEM_READ_ENGINE_Z1);
	//ErrorAddress = (UINT64)(AsiaPcieRead8(0XE0000000, Address) & 0x07) << 35;
	ErrorAddress = LShiftU64((UINT64)(AsiaPcieRead8(0XE0000000, Address) & 0x07), 35);
		
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ERR_ADR_FOR_MEM_READ_ENGINE);
	//ErrorAddress = ((UINT64)AsiaPcieRead32(0XE0000000, Address) << 3) | ErrorAddress;
	ErrorAddress = LShiftU64((UINT64)AsiaPcieRead32(0XE0000000, Address), 3) | ErrorAddress;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"The Error Address is 0x%08x", RShiftU64(ErrorAddress, 32) & 0xFFFFFFFF));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"%08x\r\n", ErrorAddress & 0xFFFFFFFF));


	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0)
	{
		//Read RSCHK0[7:0], RSCHK1[7:0], RSCHK2[7:0], RSCHK3[7:0], RSCHK4[7:0], RSCHK5[7:0], RSCHK6[7:0], RSCHK7[7:0], RSCHK8[7:0] which stand for the bits where error occurs among the QW address.
		//CHA
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHA-->Read RSCHK0[7:0], RSCHK1[7:0], RSCHK2[7:0], RSCHK3[7:0], RSCHK4[7:0], RSCHK5[7:0], RSCHK6[7:0], RSCHK7[7:0], RSCHK8[7:0] which stand for the bits where error occurs among the QW address!!!\r\n"));
		for (Index = 0; Index < EndIndex; Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ERR_BIT_FOR_MEM_READ_ENGINE + Index);
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Read RSCHK%d[7:0] = 0x%02x\r\n", Index, AsiaPcieRead8(0XE0000000, Address)));
		}
	}

#if 1
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0)
	{
		//CHB
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "CHB-->Read RSCHK0[7:0]_CHB, RSCHK1[7:0]_CHB, RSCHK2[7:0]_CHB, RSCHK3[7:0]_CHB, RSCHK4[7:0]_CHB, RSCHK5[7:0]_CHB, RSCHK6[7:0]_CHB, RSCHK7[7:0]_CHB, RSCHK8[7:0]_CHB which stand for the bits where error occurs among the QW address!!!\r\n"));
		for (Index = 0; Index < EndIndex; Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE + Index);
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Read RSCHK%d[7:0]_CHB = 0x%02x\r\n", Index, AsiaPcieRead8(0XE0000000, Address)));
		}
	}
#endif

}





/* 
  * Usage :
  * 
  * UDIMM
  * rw_engine 100000 10 0 0
  * rw_engine 100000 10 0 1
  *
  * RDIMM
  * rw_engine 100000 10 1 0
  * rw_engine 100000 10 1 1
  *
  */
VOID ReadWriteEngine(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 BeginAddress;
	UINT32 Burstlength;
	UINT8 Flag;
	UINT8 DIMMType;

#if 0
	UINT64 Address;
	UINT64 DramEnd;
	UINTN  Remainder;
#endif

	/*
	UINT8 WriteDataPattern[8] = {
		0xAA,0xBB,0xCC,0xDD,
		0xEE,0xFF,0x5A,0x3C,
	};
	*/
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "ReadWriteEngine begin!!!\r\n"));

	/* 
	  * DIMMType == 0 --> UDIMM
	  * DIMMType == 1 --> ECC DIMM or RDIMM
	  *
	  * Flag == 0 --> Use SW to calculate value fill in byte 8
	  * Flag == 1 --> Use DRAMC to calculate value fill in byte 8
	  */
	if(argc == 5)
	{
		BeginAddress = (UINT64)simple_strtoul(argv[1], NULL, 16);
		Burstlength = (UINT32)simple_strtoul(argv[2], NULL, 16); 
		Flag = (UINT8)simple_strtoul(argv[3], NULL, 16);
		DIMMType = (UINT8)simple_strtoul(argv[4], NULL, 16);
	}
	else	
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Input Error!!!\r\n"));
		return;
	}



#if 0
	//BeginAddress = 0x140000000;   //5G
	BeginAddress = 0x3C0000000; //15G

	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
    DramEnd = (UINT64)(AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F2_RTOPA_39_20);			
	DramEnd = RShiftU64(DramEnd, 12);
	DramEnd = LShiftU64(DramEnd, 20);   //RTopA
	
	Burstlength = (UINT32)DivU64x32(DramEnd - BeginAddress, 64, &Remainder);
#endif

	ReadWriteEngine_DealCore(PeiServices, DramAttr, BeginAddress, Burstlength, DIMMType, Flag);



	PEI_DEBUG((PeiServices, EFI_D_ERROR, "ReadWriteEngine end!!!\r\n"));
}



VOID ByRankSRE(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT64 Address;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "By Rank SelfRefresh Begin!!!\r\n"));

	//(1) D0F4_Rx71[7] = 0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_DRAMC_PM_REG_1);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDYNCKE, 0);

	//(2) D0F3_Rx176[7:0] = 0xFF(RSFREFRKxEN = 1), Enable Self-Refresh
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BY_RANK_SELF_REFRESH_RELATED_REGS_II_I);
	AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, 0xFF);

	//(3) D0F3_Rx178[5:3] = 111b(RENTERREF[2:0] = 111b)
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PM_DURING_SELF_REFRESH_BY_RANK_SELF_REFRESH_RELATED_REGS_III);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RENTERREF_2_0, D0F3_RENTERREF_2_0);

	//(4)make sure 17B[6] = 0

#if 0
	//(5)REFC[7:0] = 10h
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_REFC_7_0, 0x10 << 8);
#endif

	//(6)D0F4_Rx73[7] = 1
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_DRAMC_PM_REG_3);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDRAMCPM, D0F4_RDRAMCPM);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "By Rank SelfRefresh End!!!\r\n"));
}



