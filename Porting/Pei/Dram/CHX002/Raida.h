//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************
#ifndef _RAIDA_H
#define _RAIDA_H

#include "DramInit.h"

#define DRV_NAME "Asia_Xor"
#define ASIA_XOR_DRIVER_VERSION "1.0"

#define NEW_CHX_DESIGN
#define PAGE_SIZE   4096
#define MAX_CHAN    2 /*max ch across controllers*/
#define ASIA_XOR_DESC_SIZE 152

#define ASIA_XOR_SRC_ADDR_SIZE 16
#define MAX_DATA_SRC_ADDR 100

/*this macro is used to control the number of descriptors saved to trigger an operation
 *currently we set it to one. If we raise this value later, we should add time out mechanism
 *to flush saved descriptors to the device when timed out.
*/
#define ASIA_XOR_THRESHOLD 1

#define ASIA_XOR_MIN_BYTE_COUNT 0x1
#define ASIA_XOR_MAX_BYTE_COUNT 0xffffff


#define DESCS_PER_CHANNEL   16
#define SRC_ADDR_PER_DESC 16

#define DST_ADDR_PER_DESC   4
#define RAIDA_TOTAL_ADD (SRC_ADDR_PER_DESC + DST_ADDR_PER_DESC)

#define SIZE_SRC_ADDR 16
#define SIZE_PER_ADDR_TABLE MAX_DATA_SRC_ADDR * SIZE_SRC_ADDR

/*The capabilities of asia xor device*/
#define CAP_MEMCPY 0x1
#define CAP_XOR 0x2
#define CAP_MEMCMP 0x4
#define CAP_NON_ZERO 0x8
#define CAP_MEMFILL 0x10
#define CAP_INTERRUPT 0x20

/*The Command value of the Descriptor CMD field in the DCS*/
#define CMD_XOR 0x0
#define CMD_NONE_ZERO 0x1
#define CMD_MEM_FILL 0x2
#define CMD_MEMCPY 0x3
#define CMD_MEMCMP 0x4

/*DMA Registers*/
/*registers associated with channel programming*/
/*DMA channel control registers offset macro*/
#define REG_CTL         0x40
#define REG_INTR_EN     0x42
#define REG_UPPER_ADDR  0x43
#define REG_RAIDA_DESC_ADDR 0x44
#define REG_CUR_DESC_ADDR       0x48
#define REG_UPPER_CUR_DESC_ADDR 0x4C
#define REG_OUTPUT              0x4D


#define REG_PENDDESC  0xCC
#define REG_ADDDESC  0xD0
/*#define BIT_64_EN 0x1*/
#define BIT_REGISTER_SELECT 0x4000
#define BIT_WAIT_RESUME 0x100
#define BIT_CHAIN_RESUME 0x200
#define BIT_TIMER_SCALE 0x1
#define BIT_FLUSH_READ_EN 0x8
#define BIT_INTR_EN 0x10
#define BIT_INTR_MODE 0x20
#define BIT_HOT_RESET 0x40
#define BIT_UPDATE_DESC_STATUS_EN 0x80
#define BIT_ACTIVE 0x1
#define BIT_INTR_STATUS 0x1
#define BIT_TIME_OUT 0x2
#define BIT_ERR 0x4

//CHX001 output register or MMIO control information
#define BIT_FORMAT_ERR 0x10
#define BIT_INT_STS 0x4
#define BIT_CLR_STS  (BIT_FORMAT_ERR|BIT_INT_STS)

#ifdef  NEW_CHX_DESIGN
#define RAIDA_MMIO_FSTADD_UPPER 0
#define RAIDA_MMIO_FSTADD_LOW 0x4
#define RAIDA_MMIO_CURADD_LOW 0x8
#define RAIDA_MMIO_CURADD_UPPER  0xc
#define RAIDA_MMIO_ADD_DSCP 0x14
#define RAIDA_MMIO_CTL_INFO  0x18

#define RAIDA_MMIO_CTL_REG  0x20

#endif


enum time_out{
    FOR_EVER,
    HALF_OF_ONE,
    ONE,
    TWO
};

#define ENODEV  19    /* No such device */
#define DMA_PREP_INTERRUPT  (1 << 0)
#define	ENOMEM		12	/* Out of memory */
#define ASIA_XOR_NUM_SRC_TEST 16 /* must be <= 16 */
#define SLOTS_NDA_NUM 7

#define SG_PAGE_NUM_MAX 40
//#define DEBUG_DESC
//#define DEBUG_DATA_ADDR
//#define DEBUG_MEM_DATA
#define NEW_ADDER
#define ALIGN_BYTE  64

extern unsigned char  raida_mmio_ctl;
#ifdef NEW_CHX_DESIGN
extern unsigned char *raida_mmio_ptr;
#else
extern unsigned char *raida_mmio_ptr;
#endif
extern unsigned int sg_page_num_test;
extern unsigned int sg_page_len_test;
extern unsigned int asia_xor_src_num_test;
#define SG_PAGE_NUM_TEST sg_page_num_test
#define SG_PAGE_LEN_TEST sg_page_len_test
#define ASIA_XOR_VAL_NUM_SRC_TEST asia_xor_src_num_test

enum memcmp_check_result{
	MEMCMP_SAME=0,
	MEMCMP_DIFF =1
};

enum sum_check_flags {
	SUM_CHECK_P_RESULT = 1,
	SUM_CHECK_Q_RESULT = 2,
};

struct pci_dev{
	UINT8 Bus:8;
	UINT8 Device:5;
	UINT8 Function:3;
};
#if 0
struct scatterlist {
	UINT64	page_link;
	unsigned int	offset;
	unsigned int	length;
	UINT64	dma_address;
};

#define sg_dma_address(sg)	((sg)->dma_address)
#define sg_dma_len(sg)		((sg)->length)

#define for_each_sg(sglist, sg, nr, __i)	\
	for (__i = 0, sg = (sglist); __i < (nr); __i++, sg = sg_next(sg))

struct sg_table {
	struct scatterlist *sgl;	/* the list */
	unsigned int nents;		/* number of mapped entries */
	unsigned int orig_nents;	/* original size of list */
};
#endif
/*DMA channel control registers*/
typedef union _asia_xor_ctl_reg {
    struct {

        UINT16 raida_active:1;/*1: Enable 64 bit address mode*/
                          /*0: Disable 64 bit address mode*/
        UINT16 reserved1:7;

        UINT16 wait_resume_en:1;/*Set 1  When RAIDA completes a chain operation, if Chain Resume is zero, RAIDA will not enter inactive state in order to wait Chain Resume set to 1.*/
                             /*Set 0  When RAIDA completes a chain operation, if Chain Resume is zero, RAIDA will clear RAIDA Active bit and enter inactive state*/
        UINT16 chain_resume_en:1;/*Set 1  When RAIDA completes a chain operation, RAIDA will re-read the last descriptor of the chain to get the Next Descriptor Address by which to begin a new descriptor or a new chain.*/
                              /*Set 0  When RAIDA completes a chain operation, RAIDA will clear RAIDA.Active bit and enter inactive state.*/
        UINT16 dynamic_clock_en:1;/*1: Enable ; 0: Disable*/

        UINT16 reserved2:5;/*reserved*/

    }ctl_reg;
    UINT16 ctl_reg_u16;
}asia_xor_ctl_reg  ;



typedef union _asia_xor_timer_ctrl{
    struct{

        UINT8 time_scale:1;          /*1: 1ms  0: 1s*/

        UINT8 wait_resume_time_out:2;/*When Timer scale is setting to 1'b1*/
                                  /*00: wait forever; 01:0.5s; 10:1s; 11:2s*/
                                  /*When Timer scale is setting to 1'b0*/
                                  /*00: wait forever; 01:0.5us; 10:1us; 11:2us*/
        UINT8 flush_read_en:1;/*1: Enable; 0: disable*/

        UINT8 interrupt_en:1;/*1: Enable; 0: disable*/

        UINT8 interrupt_mode:1;/*1: RAIDA will issue interrupt at the end of each descriptor.*/
                             /*0: RAIDA will only issue interrupt at the end of descriptor chain.*/
        UINT8 hot_reset:1;/*1: Enable; 0: disable*/

        UINT8 update_desc_status_en:1;/*1: Enable; 0: disable*/
    }time_ctrl;
    UINT8 time_ctrl_u8;
}asia_xor_timer_ctrl;

typedef UINT8 asia_xor_upper_addr;
typedef UINT8 asia_xor_upper_cur_desc_addr;

typedef struct _desc_addr{
    UINT32 first_desc_addr_u32;/*The address of first descriptor*/
}desc_addr,*pdesc_addr;

typedef struct _cur_desc_addr{
    UINT32 current_desc_addr_u32;/*The address of first descriptor*/
}cur_desc_addr,*pcur_desc_addr;

typedef union _asia_xor_output_reg{
    struct{
	UINT8 set_interrupt_status:1;/*1: Set RAIDA_IS*/

        UINT8 set_rw4rstoerr:1;/*1: Set RW4RSTOERR*/

        UINT8 set_error:1;/*1: Set RAIDA_ERROR*/

        UINT8 reserved:5;
        }output_reg;
    UINT8 output_reg_u8;
}asia_xor_output_reg;


typedef struct _asia_xor_adddesc_reg{ 	
    UINT32 adddesc;//in CHX001 RRDA1ADDDSCP
}asia_xor_adddesc_reg;
/*union _RAIDA_DCS;
 *union _RAIDA_DBC;
 */
typedef union _RAIDA_DCS{
    struct{
        UINT32 Srcnumber:4;
        UINT32 Cmd:4;
        UINT32 Descriptor_Completion_Interrupt:1;
	//u32 msi_sel:1;
		UINT32 dstnumber:2;
		UINT32 msi_sel:1;
		UINT32 reedsol_w:1;
        UINT32 Reserved:19;
        }dcs;
    UINT32 AsU32;
}RAIDA_DCS,*PRAIDA_DCS;

typedef union _RAIDA_DBC{
    struct{
        UINT32 Byte_Count:24;
        UINT32 Reserved:5;
        volatile UINT32 Descriptor_Status:1;
        UINT32 Non_Equivalent:1;
        UINT32 Non_zero:1;
        }dbc;
    UINT32 AsU32;
}RAIDA_DBC,*PRAIDA_DBC;

typedef struct _DATA_SRC_ADDR{
    UINT32 End:1;/* if the bit is 1, it is the end of data address chain */
    UINT32 Data_Base_Address:31;
    UINT32 Upper_Data_Base_Address:32;
    UINT32 Reserved0;
    UINT32 Data_Byte_Count:22;
    UINT32 Reserved1:9;
    UINT32 Interrupt:1;
}DATA_SRC_ADDR,* PDATA_SRC_ADDR;

typedef union _phy_addr
{
    struct{
        UINT32 low_addr_u32;
        UINT32 high_addr_u32;
        }phy_addr;
    UINT64 phy_u64;
}phy_addr;

typedef struct _asia_xor_desc{
    RAIDA_DCS DCS;
    RAIDA_DBC DBC;
    phy_addr pDataSource1;
    phy_addr pDestinationAddr;
    phy_addr pNDA;
    phy_addr pDataSource2;
    phy_addr pDataSource3;
    phy_addr pDataSource4;
    phy_addr pDataSource5;
    phy_addr pDataSource6;
    phy_addr pDataSource7;
    phy_addr pDataSource8;
    phy_addr pDataSource9;
    phy_addr pDataSource10;
    phy_addr pDataSource11;
    phy_addr pDataSource12;
    phy_addr pDataSource13;
    phy_addr pDataSource14;
    phy_addr pDataSource15;
    phy_addr pDataSource16;
	phy_addr pDestinationAddr2;
	phy_addr pDestinationAddr3;
	phy_addr pDestinationAddr4;	
	UINT8 Matrix[16][4];
}asia_xor_desc;

typedef struct _asia_xor_desc_slot {
	void * hw_desc;
	PDATA_SRC_ADDR addr_table[RAIDA_TOTAL_ADD];
	enum sum_check_flags *result;
	enum memcmp_check_result *memcmp_result;
}asia_xor_desc_slot;


#endif

