//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef __ATTRIBUTE_H
#define __ATTRIBUTE_H


#define IS_CHAR16 1

#define	RO			L'R'	
#define	RW			L'A'
#define W1C         L'C'
#define	RESERVED	L'X'
#define SRESERVED	L'S'	// reserved, and needs singel function check.
#define RW1			L'W'	// RW1 //dla_add_170620

#define WITNOUT_PARAM 0x01

#define R_UART_RXBUF          0
#define R_UART_TXBUF          0
#define R_UART_BAUD_LOW       0
#define R_UART_BAUD_HIGH      1
#define R_UART_FCR            2
#define   B_UART_FCR_FIFOE    BIT0
#define   B_UART_FCR_FIFO64   BIT5
#define R_UART_LCR            3
#define   B_UART_LCR_DLAB     BIT7
#define R_UART_MCR            4
#define   B_UART_MCR_RTS      BIT1
#define R_UART_LSR            5
#define   B_UART_LSR_RXRDY    BIT0
#define   B_UART_LSR_TXRDY    BIT5
#define   B_UART_LSR_TEMT     BIT6
#define R_UART_MSR            6
#define   B_UART_MSR_CTS      BIT4
#define   B_UART_MSR_DSR      BIT5


#define PCI_LIB_ADDRESS(Bus,Device,Function,Offset)   \
  (((Offset) & 0xfff) | (((Function) & 0x07) << 12) | (((Device) & 0x1f) << 15) | (((Bus) & 0xff) << 20))

typedef enum 
	{CFG, MEM, IO, LEVEL2
	}CYCLE;

typedef enum 
	{
	D0F0_CFG,
	D0F2_MMIO,
	D0F3_CFG,
	D0F3_MMIO1,
	D0F3_MMIO2,
	D0F3_MMIO3,
	D0F3_MMIO4,
	D0F3_MMIO5,
	D0F3_MMIO6,
	D0F5_CFG,
	D17F0_CFG,
	PMIO_IO,
	XHCI_MMIO,
	XHCI_LEVEL2
	}MODULE_NAME;
UINT64          CurPositon=0;
CHAR16 *gOutBuffer=NULL;
UINT16  gPmioStartPort = 0; //!< PMIO start port.
UINT16  gPmioEndPort = 0;   //!< PMIO end port.



const CHAR16 ROs[2]       = {RO, L'\0'};
const CHAR16 RWs[2]       = {RW, L'\0'};
const CHAR16 W1Cs[2]      = {W1C, L'\0'};
const CHAR16 RW1s[2] 		= {RW1, L'\0'}; //RW1 //dla_add_170620
const CHAR16 RESERVEDs[2] = {RESERVED, L'\0'};

typedef struct {
  CYCLE Cycle;
  UINT64 Offset;
  CHAR16 Attr[160]; 
}Attribute_Input;


#endif
