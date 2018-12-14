#include"DramDebug.h"
//#include"debug\string.h"
#include "Pei.h"
#include "PeiDebug.h"
#include "../Draminit.h"
#include "spd.h"
#include "DramUtil.h"
#include "PeiLib.h"
#include "zxstring.h"



#include EFI_PPI_CONSUMER(AsiaNbPpi)

/////
//#define MEMTST_LEN 0x100000 // 1MB
//#define MEMTST_LEN 0x1000 // 4KB
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



//These are the Mtrr MSR Addresses.
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



#define SYS_CONFIG_PROMPT "MEMTEST #"
#define CONFIG_SYS_CBSIZE  256
#define CONFIG_SYS_MAXARGS 256
#define TEST_RESULT_BUFFER 0x20000000


#define CONFIG_CMD_NUM 30


#if 0

static int current_device_num ;
static struct test_data *global_test_data[CONFIG_CMD_NUM];
static char *cur_test_result_buffer = (char*)(TEST_RESULT_BUFFER + sizeof(int)*3);
static int result_buffer_size = sizeof(int)*3;
#endif



extern VOID do_mem_mw(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID do_mem_mr(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID do_mem_mw64(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID do_mem_mw32(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID do_mem_mw16(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID do_mem_mw8(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID SetDQSI(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID SetTNI(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID SetDQO(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID SetDQSO(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
/*extern VOID CmdSetDQSO(EFI_PEI_SERVICES **PeiServices,DRAM_ATTRIBUTE *DramAttr, int argc, char *argv[]);*/
/*extern	VOID CmdSetDQO(EFI_PEI_SERVICES **PeiServices,DRAM_ATTRIBUTE *DramAttr, int argc, char *argv[]);*/


extern VOID map64page(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID turnaround(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID patrol_scrub(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID ReadWriteEngine(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID ByRankSRE(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern void addr_test(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern void PciDump(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);	
extern void PciWriteByte(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);	

extern VOID ZXMemoryTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID JumpMemoryRead(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID ZXBurstTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID BurnInMemoryTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID BurstMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID CalCheckSum(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID ClearRXTiming(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID ClearTXTiming(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID DumpAllTimingReg(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID TestVrToPr(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID TgrMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID BurstWrite(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID BurstRead(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID DisCache(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID EnCache(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID do_io_read(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID do_io_write(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

//LGE20160428
/*extern VOID SetTx(EFI_PEI_SERVICES **PeiServices,DRAM_ATTRIBUTE *DramAttr, int argc, char *argv[]);*/

/*extern VOID SetRX(IN EFI_PEI_SERVICES **PeiServices, int argc, char *argv[]);*/


extern VOID ZxJumpMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern	VOID ZxRandMemTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID CmpByte(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern	VOID CopyByte(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID ZxJumpAddrTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID CmdWrite2ReadTest(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID ECC_ErrorInjection(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID ECC_ErrorStatusCheck(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID RCD_Test_Function(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID ECC_ErrorInjectionOneBit(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID ECC_ErrorInjectionMultiBit(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID CheckPREA(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID CmdAttr(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern unsigned long simple_strtoul(const char *cp,char **endp,unsigned int base);

extern VOID CmdSwSetTxVref(
	IN EFI_PEI_SERVICES **PeiServices,	 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);

extern VOID CmdMemTest(
	IN EFI_PEI_SERVICES **PeiServices,	 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);

extern VOID CmdRWEngineTest(
	IN EFI_PEI_SERVICES **PeiServices,	 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);

extern VOID CmdSwSetRxVref(
	IN EFI_PEI_SERVICES **PeiServices,	 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);
extern VOID CmdPDA(
	IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);

extern VOID CmdMprRead(
	IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);



extern VOID CmdMprWrite(
	IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	int argc, char *argv[]);


VOID Force_Rx_Scan(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern BOOLEAN HwMemtestEngine(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif     
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex,
	IN UINT64 StartAddr,
    IN UINT64 TestLen,
    IN UINT32 Pattern
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



extern VOID CmdTxScanIndexSw(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);



extern VOID CmdTxScanIndexRWEngine(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID ClsAllSetting(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID DumpAllSetting(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID SetAllSetting(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID CmdTxScan(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID CmdRxScan(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID CmdRxScanIndexRWEngine(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);



extern VOID CmdRxScanIndexSw(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID CmdRxScanIndexSwBaseTx(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);



//calibration releted -- add by RKD :BEG
extern VOID TX_DQSO_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID TX_DQO_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID TX_WLVL_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID RX_TNI_ReadLeveling_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID RX_TNI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID RX_DQSI_ReadLeveling_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID RX_DQSI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID RX_DQSI_Preamble_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID HW_TNI_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

VOID HW_RX_2Dscan_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

VOID HW_RX_3Dscan_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

VOID TNI_RX_3Dscan_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);



extern VOID HW_TNI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID HW_DQSI_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID HW_DQSI_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID HW_DQO_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID HW_TxVref_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID HW_RxVref_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID HW_DQSO_LCU_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID HW_DQSO_WLVL_Debug(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

//calibration releted -- add by RKD :END

#if 0
VOID Rx_Scan(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
	);

VOID Tx_Scan(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);
extern VOID Tx_Scan(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

VOID Tx_Scanold(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);



extern VOID CmdRxVrefScan(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID CmdTxVrefScan(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID CmdHwTNI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID HW_DQSI(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN  PERBIT_DESKEW);
extern VOID HW_DQSO_LCU(
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
	IN DRAM_ATTRIBUTE *DramAttr,
	IN BOOLEAN  PERBIT_DESKEW);


extern EFI_STATUS SwVrefCalibration(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,			 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT8 RankIndex);
#endif

extern VOID SetDCLKOP(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID SetDCLKO(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID Set_Dimm_Clk(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
/*extern VOID SetCLK0(*/
		/*IN EFI_PEI_SERVICES **PeiServices,		 */
/*#if (PI_SPECIFICATION_VERSION < 0x00010000) */
		/*IN PEI_PCI_CFG_PPI *pPCIPPI,*/
/*#else*/
		/*IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,*/
/*#endif*/
		/*IN DRAM_ATTRIBUTE *DramAttr,*/
		/*int argc, char *argv[]);*/

/*extern VOID SetCLK1(*/
		/*IN EFI_PEI_SERVICES **PeiServices,		 */
/*#if (PI_SPECIFICATION_VERSION < 0x00010000) */
		/*IN PEI_PCI_CFG_PPI *pPCIPPI,*/
/*#else*/
		/*IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,*/
/*#endif*/
		/*IN DRAM_ATTRIBUTE *DramAttr,*/
		/*int argc, char *argv[]);*/

extern VOID SetCMD(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID SetCS(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);


extern VOID SetCKE(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID DCLKO_Scan(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID Debug_Signal(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID TxVref_Hardcode(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID RxVref_Hardcode(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);

extern VOID HW_DQSO_2DSCAN_Debug(
			IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
extern VOID HW_TX_WriteLeveling_Debug(
				IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
			IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
			IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
			IN DRAM_ATTRIBUTE *DramAttr,
			int argc, char *argv[]);


CMD_INFO cmdinfo[]=
{
	//commom debug functions
	{"pci"					,PciDump,					"pci "},
	{"pciw"					,PciWriteByte,				"pci "},
	{"discache"				,DisCache,					"pci "},
	{"encache"				,EnCache,					"pci "},
	{"mw"					,do_mem_mw,					"pci "},
	{"addr_test"			,addr_test,					"pci "},
	{"memtest"				,ZXMemoryTest,				"pci "},
	{"bursttest"			,ZXBurstTest,				"pci "},
	{"burn_in"				,BurnInMemoryTest,			"pci "},
	{"burstasm"				,BurstMemTest,				"pci "},
	{"tgr500loop"			,TgrMemTest,				"pci "},
	{"burstwrite"			,BurstWrite,				"pci "},
	{"burstread"			,BurstRead,					"pci "},
	{"jumpread"				,JumpMemoryRead,			"pci "},
	{"jmptest"				,ZxJumpMemTest,				"pci "},
	{"randtest"				,ZxRandMemTest,				"pci "},
	{"jmpaddr"				,ZxJumpAddrTest,			"pci "},
	{"w2rtest"				,CmdWrite2ReadTest,         "pci "},
	{"mr"					,do_mem_mr,					"pci "},
	{"mw64"					,do_mem_mw64,				"pci "},
	{"mw32"					,do_mem_mw32,				"pci "},
	{"mw16"					,do_mem_mw16,				"pci "},
	{"mw8"					,do_mem_mw8,				"pci "},
	{"ior"					,do_io_read	,				"pci "},	
	{"iow"					,do_io_write,				"pci "},
	{"cmp"					,CmpByte,					"pci "},
	{"cp"					,CopyByte,					"pci "},
	{"checksum"				,CalCheckSum,				"pci "},		
	{"clsrxtim"			    ,ClearRXTiming,				"pci "},		
	{"clstxtim"			    ,ClearTXTiming,				"pci "},		
	{"dumpreg"			    ,DumpAllTimingReg,			"pci "},		
	{"ptest"			    ,TestVrToPr,				"pci "},		
	
	//Project Releted
	//iotiming set/read function
	{"dqsi"					,SetDQSI,					"pci "},
	{"tni"					,SetTNI,					"pci "},
	{"dqso"					,SetDQSO,					"pci "},
	{"dqo"					,SetDQO,					"pci "},

	//iotiming scan function
	{"txscan"				,CmdTxScan,					"pci "},
	{"rxscan"				,CmdRxScan,					"pci "}, 

	{"rxscanindexgt"		,CmdRxScanIndexSwBaseTx,	"pci "},  //RxScan by index, use MemoryTest(base good Tx Timing)
	{"rxscanindexsw"		,CmdRxScanIndexSw,			"pci "},  //RxScan by index, use MemoryReadTest(Read Pattern)
	{"rxscanindexre"		,CmdRxScanIndexRWEngine,	"pci "},  //RxScan by index, use RW_Engine(Read MPR Pattern)
	{"txscanindexsw"		,CmdTxScanIndexSw,			"pci "},  //TxScan by index, use MemoryTest
	{"txscanindexre"		,CmdTxScanIndexRWEngine,	"pci "},  //TxScan by index, use RW_Engine
	{"clssetting"		    ,ClsAllSetting,          	"pci "},  
	{"setsetting"		    ,SetAllSetting,          	"pci "},  
	{"dumpsetting"		    ,DumpAllSetting,          	"pci "},  
	
	{"txvref"				,CmdSwSetTxVref,			"pci "},		
	{"mt"					,CmdMemTest,				"pci "},		
	{"ret"					,CmdRWEngineTest,			"pci "},		
	
	//calibration related
	{"iocaldqso"			,TX_DQSO_Debug,				"pci "},
	{"iocaldqo"				,TX_DQO_Debug,				"pci "},
	{"iocalwlvl"			,TX_WLVL_Debug,				"iocalwlvl(io timing write leveling calibration) "},
	
	{"iocaltni"				,RX_TNI_ReadLeveling_Debug,	"pci "},
	{"tnilcu"				,RX_TNI_LCU_Debug,			"pci "},
	{"iocaldqsi"			,RX_DQSI_ReadLeveling_Debug,"pci "},
	{"dqsilcu"				,RX_DQSI_LCU_Debug,			"pci "},
	{"dqsipre"				,RX_DQSI_Preamble_Debug,	"pci "},

	//for silicon debug
	{"hwtni"				,HW_TNI_Debug,				"pci "},	
	{"hwrx2d"				,HW_RX_2Dscan_Debug,				"pci "},
	{"hwrx3d"				,HW_RX_3Dscan_Debug,				"pci "},	
	{"hwtnirx3d"			,TNI_RX_3Dscan_Debug,				"pci "},	
	{"hwtnilcu"				,HW_TNI_LCU_Debug,    		"pci "},
	{"hwdqsi"				,HW_DQSI_Debug,				"pci "},
	{"hwdqsilcu"			,HW_DQSI_LCU_Debug,			"pci "},
	{"hwdqso"				,HW_DQSO_LCU_Debug,			"pci "},
	{"hwdqo"				,HW_DQO_LCU_Debug,			"pci "},
	{"hwdqso2d"				,HW_DQSO_2DSCAN_Debug,			"hwdqso2d 0 "},	
	{"hwtxscan"				,HW_TX_WriteLeveling_Debug,			"hwtxscan 0 "},
	{"hwtxvref"				,HW_TxVref_Debug,			"pci "},
	{"hwrxvref"				,HW_RxVref_Debug,			"pci "},	
	{"hwwlvl"				,HW_DQSO_WLVL_Debug,		"hwwlvl(HW write leveling calibration) "},
	//Checklist reled function
	{"byranksre"			,ByRankSRE,					"pci "},
	{"map64page"			,map64page,					"pci "},
	{"checkprea"			,CheckPREA,					"pci "},
	{"attribute"			,CmdAttr,					"attribute [DEV NAME](d0f31/d0f32/d0f2...attribute TEST) "},
	{"turnaround"			,turnaround,				"pci "},
	{"patrol"				,patrol_scrub,				"pci "},
	{"errstatus"			,ECC_ErrorStatusCheck,      "pci "},
	{"rcd_test"				,RCD_Test_Function,			"pci "},
	{"ecc_in"				,ECC_ErrorInjection,        "pci "},
	{"one_eccin"			,ECC_ErrorInjectionOneBit,  "pci "},
	{"mlt_eccin"			,ECC_ErrorInjectionMultiBit,"pci "},		
	{"rw_engine"			,ReadWriteEngine,		    "pci "},
	{"pdaset"				,CmdPDA,				    "pci "},
	{"mprread"				,CmdMprRead,				"pci "},
	{"mprwrite"				,CmdMprWrite,				"pci "},
	
	//daisy add for SI basic
	{"dclkop"				,SetDCLKOP, 				"pci "},
	{"dclkon"				,SetDCLKO,					"pci "},
	{"dimmclk" 				,Set_Dimm_Clk,				"pci "},
	{"cmd"					,SetCMD,					"pci "},
	{"cs"					,SetCS, 					"pci "},
	{"cke"					,SetCKE,					"pci "},
	{"forcerx"				,Force_Rx_Scan,				"pci "},
	{"scan_dclko"			,DCLKO_Scan,				"pci "},
	{"debugsignal"			,Debug_Signal,				"pci "},
	{"txvrefhardcode"		,TxVref_Hardcode,			"pci "},
	{"rxvrefhardcode"		,RxVref_Hardcode,			"pci "},
};

UINT32 cmdinfolength = sizeof(cmdinfo)/sizeof(CMD_INFO);


INTN
EFIAPI
AsiaStrnCmp (
  IN      CONST CHAR8               *FirstString,
  IN      CONST CHAR8               *SecondString,
  IN      UINTN                     Length
  )
{
  if (Length == 0) {
    return 0;
  }
  //
  // ASSERT both strings are less long than PcdMaximumAsciiStringLength
  //
  

  while ((*FirstString != '\0') &&
         (*FirstString == *SecondString) &&
         (Length > 1)) {
    FirstString++;
    SecondString++;
    Length--;
  }
  return *FirstString - *SecondString;
}



UINTN
EFIAPI
zx_strlen ( IN      CONST CHAR8               *String)
{
  UINTN                             Length;

  //ASSERT (String != NULL);

  for (Length = 0; *String != '\0'; String++, Length++) {
    //
    // If PcdMaximumUnicodeStringLength is not zero,
    // length should not more than PcdMaximumUnicodeStringLength
    //
    
  }
  return Length;
}



CHAR8 *
EFIAPI
zx_strcpy (
  OUT     CHAR8                     *Destination,
  IN      CONST CHAR8               *Source)
{
  CHAR8                             *ReturnValue;

  //
  // Destination cannot be NULL
  //
  //ASSERT (Destination != NULL);

  //
  // Destination and source cannot overlap
  //
  //ASSERT ((UINTN)(Destination - Source) > strlen (Source));
  //ASSERT ((UINTN)(Source - Destination) > strlen (Source));

  ReturnValue = Destination;
  while (*Source) {
    *(Destination++) = *(Source++);
  }
  *Destination = 0;
  return ReturnValue;
}



INTN
EFIAPI
zx_strcmp (
  IN      CONST CHAR8               *FirstString,
  IN      CONST CHAR8               *SecondString)
{
  //
  // ASSERT both strings are less long than PcdMaximumAsciiStringLength
  //
 

  while ((*FirstString != '\0') && (*FirstString == *SecondString)) {
    FirstString++;
    SecondString++;
  }

  return *FirstString - *SecondString;
}

char ReConf_DRAMCLK[8][16]={
        "Undefined", "400 MHz", "566 MHz", "667 MHz",\
        "800 MHz", "933 MHz", "1066 MHz", "1200 MHz"
        };
UINT8  ReConf_BL[2][16]={"On the fly", "BL8"};
UINT8 ReConf_ECCDIMM[2][16]={"Disable", "Enable"};
char ReConf_CRC[2][16]={"Disable", "Enable"};
char ReConf_PAR[2][16]={"Disable", "Enable"};
char ReConf_CAL[2][16]={"Disable", "Enable"};
char ReConf_CRCRetry[2][16]={"Disable", "Enable"};
char ReConf_VR[2][16]={"Enable", "Disable"};
char ReConf_BR[2][16]={"Enable", "Disable"};

static UINT8 DCLKString(UINT32 DCLKSetting)
{
	UINT8 DCLKValue;

	if(DCLKSetting == DRAM_FREQ_800)			DCLKValue = 0x01;
	else if (DCLKSetting == DRAM_FREQ_1066)		DCLKValue = 0x02;		
	else if (DCLKSetting == DRAM_FREQ_1333)		DCLKValue = 0x03;		
	else if (DCLKSetting == DRAM_FREQ_1600)		DCLKValue = 0x04;	
	else if (DCLKSetting == DRAM_FREQ_1866)		DCLKValue = 0x05;	
	else if (DCLKSetting == DRAM_FREQ_2133)		DCLKValue = 0x06;	
	else if (DCLKSetting == DRAM_FREQ_2400)		DCLKValue = 0x07;	
	else DCLKValue = 0x00;
	
	return DCLKValue;
}

void show_config(IN EFI_PEI_SERVICES **PeiServices,IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8 index=1;
	
	index = 1; // fixed for release ver compiling error.
	//DramClk -1
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,DramClk:%a\n", index++,ReConf_DRAMCLK[DCLKString(DramAttr->DramFreq)]));

	//Ecc -2
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,ECC:%a\n",index++,ReConf_ECCDIMM[DramAttr->ECCSupport])); 
	//BC-3
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,Burst Length:%a\n",index++, ReConf_BL[DramAttr->BurstLength8])); 
	//rank interlevel-4
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,Rank Interlevel:%a\n",index++, ReConf_VR[DramAttr->ConfigData.VRIntlv])); 
	//bank interlevel-5
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,Mulitpage:%a\n",index++, ReConf_BR[DramAttr->ConfigData.BankIntlv])); 
	//CRC-6
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,CRC:%a\n",index++,ReConf_CRC[DramAttr->ConfigData.CRCEn])); 
	//CRCretry-7
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,CRCRetry:%a\n",index++,ReConf_CRCRetry[DramAttr->ConfigData.CRCParRetryEn])); 
	//PAR-8
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,CA/Parity:%a\n",index++,ReConf_PAR[DramAttr->ConfigData.CAParEn])); 
	//CAL-9
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%d,CAL:%a\n",index++,ReConf_CAL[DramAttr->ConfigData.CALEn])); 
	//
}

int re_config(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		const char *cmd)
{
	//	cmd_tbl_t *cmdtp;
	char cmdbuf[CONFIG_SYS_CBSIZE];	  /* working copy of cmd		*/

	char *str = cmdbuf;
	char *argv[CONFIG_SYS_MAXARGS + 1];	/* NULL terminated	*/
	int argc;
	int rc = 0;
	//int index = 0;

	if (!cmd || !*cmd)
	{
		return -1;	                 /* empty command */
	}

	if (zx_strlen(cmd) >= CONFIG_SYS_CBSIZE)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO,"## Command too long!\n"));
		return -1;
	}

	zx_strcpy (cmdbuf, cmd);

	/* Process separators and check for invalid
	 * repeatable commands
	 */

	while (*str)
	{
		if ((argc = parse_line (PeiServices,str, argv)) == 0)
		{
			rc = -1;	    /* no command at all */
			break;
		}
		if(zx_strcmp(cmd,"help") == 0)
		{    
			show_config(PeiServices,DramAttr);
			break;
		}
		if(zx_strcmp(cmd,"1") == 0)
		{    //show_help(argc,argv);
			DramAttr->DramFreq = DramAttr->DramFreq + 8;
			if(DramAttr->DramFreq > 70)
				DramAttr->DramFreq = 22;
			show_config(PeiServices,DramAttr);
			break;
		}
		//ECC
		if(zx_strcmp(cmd,"2") == 0)
		{
			DramAttr->ECCSupport = !DramAttr->ECCSupport;
			show_config(PeiServices,DramAttr);
				break;
		}
		//BC
		if(zx_strcmp(cmd,"3") == 0)
		{
			DramAttr->BurstLength8 = !DramAttr->BurstLength8;
			show_config(PeiServices,DramAttr);
				break;
		}
		//Vrankinterleave
		if(zx_strcmp(cmd,"4") == 0)
		{
			DramAttr->ConfigData.VRIntlv = !DramAttr->ConfigData.VRIntlv;
			show_config(PeiServices,DramAttr);
				break;
		}
		//multipage
		if(zx_strcmp(cmd,"5") == 0)
		{
			DramAttr->ConfigData.BankIntlv = !DramAttr->ConfigData.BankIntlv;
			show_config(PeiServices,DramAttr);
				break;
		}
		//CRC
		if(zx_strcmp(cmd,"6") == 0)
		{
			DramAttr->ConfigData.CRCEn = !DramAttr->ConfigData.CRCEn;
			show_config(PeiServices,DramAttr);
				break;
		}
		//CRCParRetryEn
		if(zx_strcmp(cmd,"7") == 0)
		{
			DramAttr->ConfigData.CRCParRetryEn = !DramAttr->ConfigData.CRCParRetryEn;
			show_config(PeiServices,DramAttr);
				break;
		}
		//CAParEn
		if(zx_strcmp(cmd,"8") == 0)
		{
			DramAttr->ConfigData.CAParEn = !DramAttr->ConfigData.CAParEn;
			show_config(PeiServices,DramAttr);
				break;
		}
		//CALEn
		if(zx_strcmp(cmd,"9") == 0)
		{
			DramAttr->ConfigData.CALEn = !DramAttr->ConfigData.CALEn;
			show_config(PeiServices,DramAttr);
				break;
		}
		

		if(zx_strcmp(cmd,"exit") == 0)
		{
			return -3;
		}

	}
			return rc;
}
void configure_loop(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8 lastcommand[256];
	UINT8 input[256];
	int len;
	int rc = 1;

	(*PeiServices)->SetMem(lastcommand, 256, 0);
	(*PeiServices)->SetMem(input, 256, 0);

	/*show_help(PeiServices);*/
	show_config(PeiServices,DramAttr);
	for (;;)
	{

		len = DramDebug(PeiServices,input);

		zx_strcpy (lastcommand, input);

		rc = re_config(PeiServices, pPCIPPI, DramAttr,lastcommand);

		if (rc == -3)
			break;
		else if(rc == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"done\r\n"));
		else if ((rc != -3) && (rc <= 0))
		{
			/* invalid command or not repeatable, forget it */
			lastcommand[0] = 0;
		}

		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "input lastcommand is %a\r\n",lastcommand ));
	}
}

void main_loop (
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT8 lastcommand[256];
	UINT8 input[256];
	int len;
	int rc = 1;

	(*PeiServices)->SetMem(lastcommand, 256, 0);
	(*PeiServices)->SetMem(input, 256, 0);

	/*
	 * Main Loop for Monitor Command Processing
	 */
	show_help(PeiServices);
	for (;;)
	{


		len = DramDebug(PeiServices,input);


		zx_strcpy (lastcommand, input);

		rc = run_command (PeiServices, pPCIPPI, DramAttr,lastcommand);

		if (rc == -3)
			break;
		else if(rc == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"done\r\n"));
		else if ((rc != -3) && (rc <= 0))
		{
			/* invalid command or not repeatable, forget it */
			lastcommand[0] = 0;
		}

		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "input lastcommand is %a\r\n",lastcommand ));
	}
}



EFI_STATUS DramDebug(
			 IN EFI_PEI_SERVICES **PeiServices,
			 UINT8 *input)
{
	BOOLEAN dramdebugflag=TRUE, repeat=TRUE;
	#if defined(HX002EH0_01)||defined(HX002EL0_05)
	UINT16 UART_BASE=0x3F8;
	#else
	UINT16 UART_BASE=0x2F8;
	#endif
	UINT8 InputChar;
	//UINT8 input[300]={0};
	UINT8 c=0;
	int i=0;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n DramDebug console\r\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "please input#"));
	while(repeat)
	{
		dramdebugflag=TRUE; 
		while(dramdebugflag)
		{
			InputChar=AsiaIoRead8(UART_BASE+5) & 0x01;
			if(InputChar)
				switch(c=AsiaIoRead8(UART_BASE))
				{

					case '\n':       // Enter	
						dramdebugflag=FALSE, repeat=FALSE;
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\ninput is %a\r\n", input));
						input[i] = '\0';
						break;  			           

					default:

						if (i < CONFIG_SYS_CBSIZE-2)
						{
							//PEI_DEBUG((PeiServices, EFI_D_ERROR, "please input:\r\n"));
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "%c",c));  
							input[i++]=c;

						}
						else  			
						{
							PEI_DEBUG((PeiServices, EFI_D_ERROR, "ERROR:Buffer full!\r\n")); 
						}
						break; 
				}
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Exit DramDebug\n"));
	return EFI_SUCCESS;
}


int run_command (
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	const char *cmd)
{
	//	cmd_tbl_t *cmdtp;
	char cmdbuf[CONFIG_SYS_CBSIZE];	  /* working copy of cmd		*/
	char *str = cmdbuf;
	char *argv[CONFIG_SYS_MAXARGS + 1];	/* NULL terminated	*/
	int argc;
	int rc = 0;
	UINT32 CmdIndex;

	if (!cmd || !*cmd)
	{
		return -1;	                 /* empty command */
	}

	if (zx_strlen(cmd) >= CONFIG_SYS_CBSIZE)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO,"## Command too long!\n"));
		return -1;
	}

	zx_strcpy (cmdbuf, cmd);
	/* Process separators and check for invalid
	 * repeatable commands
	 */
	if(*str)
	{
		if ((argc = parse_line (PeiServices,str, argv)) == 0)
		{
			rc = -1;	    /* no command at all */
			return rc;
		}



		if(AsiaStrnCmp(cmd,"help",4) == 0)
		{    //show_help(argc,argv);
			show_help(PeiServices);
			rc = 0;
			return rc;
		}
		else if(AsiaStrnCmp(cmd,"exit",4) == 0)
		{
			return -3;
		}

		for(CmdIndex = 0; CmdIndex < cmdinfolength; CmdIndex++)
		{
			if(zx_strcmp(argv[0], cmdinfo[CmdIndex].cmd_name) == 0)
			{	
				cmdinfo[CmdIndex].test_func(PeiServices, pPCIPPI, DramAttr,argc,argv);
				break;
			}		

		}
		if(CmdIndex == cmdinfolength)
		{
			rc = -1;
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Unknown command '%a' - try 'help'\r\n", argv[0]));

		}		

	}
	return rc;
}

int parse_line (IN EFI_PEI_SERVICES **PeiServices,UINT8 *line, UINT8 *argv[])
{
	int nargs = 0;

	while (nargs < CONFIG_SYS_MAXARGS)
	{

		/* skip any white space */
		while ((*line == ' ') || (*line == '\t'))
		{
			++line;
		}

		if (*line == '\0')  	/* end of line, no more args	*/
		{
			argv[nargs] = NULL;
			return (nargs);
		}

		argv[nargs++] = line;	/* begin of argument string	*/

		/* find end of string */
		while (*line && (*line != ' ') && (*line != '\t'))
		{
			++line;
		}

		if (*line == '\0')  	/* end of line, no more args	*/
		{
			argv[nargs] = NULL;
			return (nargs);
		}

		*line++ = '\0';		/* terminate current arg	 */
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"** Too many args (max. %d) **\r\n", CONFIG_SYS_MAXARGS));

	return (nargs);
}    

#if 0
int search_for_cmd(const char * cmd)
{
	int index;
	//int len = strlen(cmd);
	int found = 0;


	if(strcmp(cmd,"help") == 0)
		return -2;
	if(strcmp(cmd,"exit") == 0)
		return -3;
	for (index = 0; index < current_device_num; index++)
	{

		if(strcmp(cmd, global_test_data[index]->cmd_name)==0)
		{
			found = 1;
			break;
		}
	}
	if(found)
		return index;
	else
		return -1;
}


int register_test(IN EFI_PEI_SERVICES **PeiServices,struct test_data * td)
{
	//int i;


	if ((current_device_num+1) > CONFIG_CMD_NUM)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Register failed! Exceed max device number.\r\n"));
		return -1;
	}

	if (td->cmd_name == NULL)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"Register failed! Need a cmand name for your test!\r\n"));
		return -1;
	}

	td->test_id = current_device_num;

#if 0
	td->test_result = (struct test_result*)cur_test_result_buffer;

	cur_test_result_buffer += sizeof(struct test_result);

	result_buffer_size += sizeof(struct test_result);

	for (i = 0; i < td->total_vectors; i++)
	{
		td->vectors[i].test_result = (int*)cur_test_result_buffer;
		cur_test_result_buffer += sizeof(int);
		result_buffer_size += sizeof(int);
	}
#endif
	global_test_data[current_device_num++]= td;


	PEI_DEBUG((PeiServices, EFI_D_ERROR,"current_device_num = %d\r\n",current_device_num));


	return 0;
}
void manual_test(IN EFI_PEI_SERVICES **PeiServices,int index, int argc, char *argv[])
{

	int ret;

	ret = global_test_data[index]->vectors[0].test_func(PeiServices,argc, argv);


	if (ret == STATUS_PASS)

		PEI_DEBUG((PeiServices, EFI_D_ERROR,"done\r\n"));

	if (ret == STATUS_HANG)
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"status: hang\r\n"));

	if (ret == STATUS_FAIL)
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"something went wrong during last command!\r\n"));

}
#endif

void show_help(IN EFI_PEI_SERVICES **PeiServices)
{
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n exit Exit\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n pci [BusNo] [DevNo] [FunNo] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n pciw  [BusNo] [DevNo] [FunNo] [Register] [value] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mw(memory write)  [startaddress] [value] [length] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mw64(memory write)  [startaddress] [value] [length] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mw32(memory write)  [startaddress] [value] [length] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mw16(memory write)  [startaddress] [value] [length] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mw8(memory write)  [startaddress] [value] [length] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mr(memory read)    [startaddress] [length] \n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n ior(memory write)  [address]  \n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iow(memory write)  [address] [value] \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n dramftr(dram feature test)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n pagecft(read page conflict)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n reorder(reorder/inorder test)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n addr_test [BaseAddr] [TestLength]                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iocaldqso(io timing DQSO calibration)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iocaldqo(io timing dqo calibration)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iocalwlvl(io timing write leveling calibration)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iocaldqsi(io timing dqsi calibration)                 \n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iocalTNI(io timing TNI calibration)				   \n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n pret(io timing TNI calibration)				   \n"));
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\n iowrmpr(io timing MPR write )				   \n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n memtest [BaseAddr][testlength] 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n bursttest(burst Memory TEST) [BaseAddr] [EndAddr] 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n burn_in(burn in Memory TEST) 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n burstasm(ASM code burst Memory TEST) 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n tgr500loop(Tiger's 500loop Memory and SPIROM TEST); 				\n"));
    
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n burstwrite(burstwrite to dram) 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n burstread(burstread from dram) 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n encache(enable cache) 				\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n discache(disable checksum) 				\n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n checksum(calculate checksum) 				\n"));	

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n jumpread [StartAddress] [Length] [jumpstep]		\n"));	

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n SPIROM Test\n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n settx [Regvalue]\n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n setrx [Regvalue]\n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n setdqso [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n setdqo [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n settni [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n setdqsi [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n setnewrx [wholet/phase/dlycomp/clkinv][RankIndex][Regvalue][low/high]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n setnewtx [wholet/phase/dlycomp/clkinv][RankIndex][Regvalue][low/high]\n"));
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\n crcsingle [Error address] (crc inject single error) \n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n crcmulti  [Error address](crc inject multi error) \n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n crcuc     [Error address](crc inject Uncorrect error) \n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n parsingle [Error address](par inject single error) \n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n parmulti  [Error address] (par inject multi error) \n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n paruc     [Error address] (par inject Uncorrect error) \n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n jumpread  [StartAddress] [Length] [jumpstep]		\n"));
	
		
   PEI_DEBUG((PeiServices, EFI_D_INFO, "\n jmptest [StartAddress] [Length] [jumpstep](Bankmiss JumpStep=0x8000,Pagemiss JumpStep=0X20000)\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n randtest [StartAddress] [Length]		\n"));
    
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\n cmp [SRC] [DST] [Length]		\n"));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n cp [SRC] [DST] [Length] 		\n"));
	    
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n jmpaddr [StartAddress] [Length] [jumpstep](Bankmiss JumpStep=0x8000,Pagemiss JumpStep=0X20000)\n"));
    
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n ecc_in (ecc error injection test)\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n one_eccin [BitIndex] (ecc error injection test)\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mlt_eccin (ecc Multi bit error injection test)\n"));
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\n w2rtest(write to read test) [StartAddress] [Length] [jumpstep](Bankmiss JumpStep=0x8000,Pagemiss JumpStep=0X20000)\n"));
     
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n txvref [RankNo] [Vref] (Set Tx Vref)		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n rxvref [RankNo] [Vref] (Set Rx Vref)		\n"));
	  
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n pdaset [RankNo] [ChipNo] [VrefDQ]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n mprread [RankNo] [PageNo] [true/false]	\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hwengine 		\n"));
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "\n txscan 		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n txoldscan 		\n"));	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n rxscan [RankIndex] [ByteIndex] 		\n"));
		
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n rxvrefscan  [Address] [Pattern0-7] (RX Vref scan) 		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n txvrefscan(TX Vref scan) 		\n"));	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hw2dscan  		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hw3dscan		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n tni3dscan 		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hwtni [RankNo][RxVrefStart][RxVrefEnd] (TNI Calibration) 		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hwdqsi(DQSI Calibration) 		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hwdqso(DQSO Calibration) 		\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n hwdqo(DQO Calibration) 		\n"));

	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n checkprea(Checklist verify 5.6 Support page close/page close all request)\n"));	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n map64page(Checklist verify 5.5 Support 64-entry direct mapped page table)\n"));	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n turnaround(Checklist verify 5.16 check turn around 0T/1T/2T)\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n patrol(Checklist verify 6.9.1 check Patrol Scrub mode)\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n rw_engine [BeginAddress] [Burstlength] [DIMMType] [Flag]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n clear_mem\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n byranksre\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n attribute [DEV NAME](d0f31/d0f32/d0f2...attribute TEST)\n"));	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n swvrefscan(SW Vref Calibration) 		\n"));	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n please switch to Char Mode\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n errstatus\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n rcd_test\n"));


	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n SI Basic Set\n"));
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n dclkop A/B [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n dclko A/B [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n clk0 A/B [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n clk1 A/B [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n cmd A/B [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n cs A/B [Regvalue]\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n cke A/B [Regvalue]\n"));
	
}

VOID DumpD0F3(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr
		)
{
	UINT64   Address;
	UINT8    Data;
	UINT16	Index1, Index2;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump D0F3:\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "---+-----------------------------------------------\n"));
	 //00-300
	for(Index1=0;Index1<0x100;Index1++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%03x|", Index1*16));
		for(Index2=0;Index2<0x10;Index2++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, Index1*16+Index2);
			Data = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
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

////
VOID DumpD0F2(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr
		)
{
	UINT64   Address;
	UINT8    Data;
	UINT16	Index1, Index2;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump D0F2:\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "---+-----------------------------------------------\n"));
	for(Index1=0;Index1<0x20;Index1++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%03x|", Index1*16));
		for(Index2=0;Index2<0x10;Index2++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, Index1*16+Index2);
			Data = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
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
VOID VDump_MTRR( IN EFI_PEI_SERVICES **PeiServices)
{

	UINT8 NumMtrrs,i;
	UINT64 MtrrBase,MtrrMask;
	////	
	PEI_DEBUG((PeiServices, EFI_D_INFO,"WC: Dump VARIABLE_MTRRS\n"));
	NumMtrrs = (UINT8)__readmsr(MSR_IA32_MTRR_CAP);
	for(i=0; i <NumMtrrs; ++i) {
		MtrrBase = __readmsr(gVariableMtrrAddress[i]);
		MtrrMask = __readmsr(gVariableMtrrAddress[i]+1);
		PEI_DEBUG((PeiServices, EFI_D_INFO,"WC: Variable MTRR[%i]\n", i));
		PEI_DEBUG((PeiServices, EFI_D_INFO,"WC: Base = %08x\n",MtrrBase));
		PEI_DEBUG((PeiServices, EFI_D_INFO,"WC: Mask = %08x\n",MtrrMask));
	}
	////
}

//daisy add for check SI value
VOID DumpD0F3Perbit(
		IN EFI_PEI_SERVICES **PeiServices,
		IN DRAM_ATTRIBUTE *DramAttr
		)
{
	UINT64   Address;
	UINT8    Data;
	UINT8    i;
	UINT16	Index1, Index2;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump D0F3Perbit:\n"));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "---+-----------------------------------------------\n"));

	for(Index1=0;Index1<0x100;Index1++)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%03x:", Index1*16));
		for(Index2=0;Index2<0x10;Index2++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, Index1*16+Index2);
			Data = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02x ", Data));
			for(i = 7; i > 0; i--)
       		{
				if((Data >> i) & 0x01) 
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "1"));
				else
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "0"));
       	    }
			if(Data & 0x01)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "1"));
			else
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "0"));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " "));
			if(Index2==0x0F)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
		}
		if((Index1%0x10)==0x0F)
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "---------------------------------------------------\n"));
	}

	return;
}


