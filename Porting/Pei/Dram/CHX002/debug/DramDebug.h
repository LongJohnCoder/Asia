#ifndef __DRAMDEBUG_H_
#define __DRAMDEBUG_H_



#include "Pei.h"
#include "PeiDebug.h"
#include "../Draminit.h"
#include "DramUtil.h"




#define STATUS_PASS 0
#define STATUS_FAIL 1
#define STATUS_HANG 2


#define MAX_NAME_SIZE 30


struct test_result {
	UINT8 test_name[64];
	int  total;
	int  pass;
	int  fail;
	int  hang;
	int  time;
};

struct test_vector {
	UINT8 vector_name[64];
	int (*test_func)(EFI_PEI_SERVICES **PeiServices,int argc, char *argv[]);	
	int *test_result;                //pass : 0 , fail: 1 , hang: 2
};


/*
* Note: device test shuold implement EACH field of the following struct
*       or the registration will FAIL!
*/
struct test_data {
	UINT8	 test_name[64];
	UINT8	 cmd_name[MAX_NAME_SIZE];  //name of your test command
	void   	 (*device_init)(void);     //device init function
	struct test_vector *vectors;
	int 	total_vectors;
	int	    test_id;
	struct  test_result *test_result;
};

typedef struct{
    UINT32 ReadAddr;
	UINT32 Pattern[8];
}ReadTest;

EFI_STATUS DramDebug(
	EFI_PEI_SERVICES **PeiServices,
	UINT8 *input
);


typedef struct{
	UINT16 TNIIndex;
	UINT8 DQSIBeg;
	UINT8 DQSIEnd;
}RXSCANSET;

typedef struct{
	UINT16 DQSOIndex;
	UINT16 DQOBeg;
	UINT16 DQOEnd;
}TXSCANSET;



int register_test(IN EFI_PEI_SERVICES **PeiServices,struct test_data * td);


//main_loop.c

void main_loop (
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr);

void configure_loop(
		IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr);

int parse_line (IN EFI_PEI_SERVICES **PeiServices,UINT8 *line, UINT8 *argv[]);
int run_command (
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000)
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr,
	const char *cmd);

int search_for_cmd(const char * cmd);

void manual_test(IN EFI_PEI_SERVICES **PeiServices,int index, int argc, char *argv[]);

void show_help(IN EFI_PEI_SERVICES **PeiServices);

void hang (void);



#define NAME_SIZE 20
#define MAX_CMD 255

typedef struct{
	char	 cmd_name[NAME_SIZE];//name of your test command	
    void (*test_func)(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[]);
	char     help[200];
}CMD_INFO;



#endif
