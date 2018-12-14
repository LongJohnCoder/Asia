
#include "../Draminit.h"



////////////////////////////////Using For TxRx Timing Value HardCode////////////////////////////////
#define CHA_RXTXHARDCODE    0x00
#define CHB_RXTXHARDCODE    0x01

#define TNI_RXTXHARDCODE    0x04
#define DQSO_RXTXHARDCODE   0x06
#define DQO_RXTXHARDCODE    0x07
#define TXVREF_RXTXHARDCODE	0x08


//Rx Tx Timing except DQSI & RxVref
typedef struct RxTxTimingStruct{
	UINT8   Channel;
	UINT8   Name;
	UINT8   RankIndex;
	UINT16  Value[9];
	UINT8   Flag;
}RXTXTIMING;

typedef struct RxDQSIStruct{
	UINT8   Channel;
	UINT8   RankIndex;
	UINT8   ByteIndex;
	UINT16  ValueBit[8];
	UINT8   POSorNEG;  //POSorNEG = 1(POS),  POSorNEG = 0(NEG)
	UINT8   Flag;
}RXDQSITIMING;

typedef struct RxVrefStruct{
	UINT8   Channel;
	UINT8   ByteIndex;
	UINT8   ValueBit[8]; //RxVref GrayCode
	UINT8   Flag;
}RXVREFTIMING;

UINT16 VREF_Overlap_Tbl[];
UINT16 VREF_Coarse_Tbl[];

RXTXTIMING Rx_TNI_Value_Tbl[];
UINT32 Rx_TNI_Value_Tbl_Items;

RXVREFTIMING Rx_RxVref_Value_Tbl[];
UINT32 Rx_RxVref_Value_Tbl_Items;

RXDQSITIMING Rx_DQSI_Value_Tbl[];
UINT32 Rx_DQSI_Value_Tbl_Items;

RXTXTIMING TX_Value_Tbl[];
UINT32 TX_Value_Tbl_Items;

void Setting_RxVref_Value_Rx(
	EFI_PEI_SERVICES **PeiServices, 
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
    PEI_PCI_CFG_PPI *pPCIPPI,
#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	DRAM_ATTRIBUTE *DramAttr);

void Setting_DQSI_Value_Rx(
	EFI_PEI_SERVICES **PeiServices, 
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
    PEI_PCI_CFG_PPI *pPCIPPI,
#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	DRAM_ATTRIBUTE *DramAttr);

void Setting_Timing_Value_TxRx(
	EFI_PEI_SERVICES **PeiServices, 
	#if (PI_SPECIFICATION_VERSION < 0x00010000)
    PEI_PCI_CFG_PPI *pPCIPPI,
#else
    EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	DRAM_ATTRIBUTE *DramAttr,
	RXTXTIMING Rx_Tx_Value_Tbl[],
	IN UINT32 Items);		