/** @file
   ZX-E(CHX002) Asia NbDxe library functions : NbDxePciePrePciCommon.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef __NB_DXE_PCIE_PRE_PCI_COMMON_H__
#define __NB_DXE_PCIE_PRE_PCI_COMMON_H__



/*+ DSZ_Porting -- (YSW-2017031701) Modify PCIE Module Code for RP L1 Exit Latency Capability calculation*/
typedef struct RPL1ExitLatencyCorrespondingTbl{
	UINT8 ECFG;		// PCIE ECFG Index, can be read from D0F0_RxFB[4:0]
	UINT16 RegForPE0;	// register offset in EPHY,indicate the register location for the corresponding port ,0 indicate the port was not exist in this ECFG
	UINT16 RegForPE1;
	UINT16 RegForPE2;
	UINT16 RegForPE3;
	UINT16 RegForPE4;
	UINT16 RegForPE5;
	UINT16 RegForPE6;
	UINT16 RegForPE7;
}RPL1SET_TBL;

typedef struct RPL1ExitLatencyCalTbl{
	UINT8 RegValue;		 
	UINT8 RealValue;	
}RPL1CAL_TBL;

/*
For FRPxx_P1EXT_Gx[2:0]
	3'b000: 1us
	3'b001: 2us
	3'b010: 4us
	3'b011: 8us
	3'b100: 16us (default)
	3'b101: 32us
	3'b110: 64us
	3'b111: 128us

*/
#define RPL1CapREG2REAL(x)  ((2<<x)>>1)
#define RPL1CapREAL2REG(y)  (((y>>1)==0)?0:\
	(((y>>2)==0)?1:\
	(((y>>3)==0)?2:\
	(((y>>4)==0)?3:\
	(((y>>5)==0)?4:\
	(((y>>6)==0)?5:\
	((y>>7)==0)?6:\
	(((y>>8)==0)?7:0xF)))))))

#define RPL1ExitSBDG   			0x20   	//Steps between different Gen speeds 
#define RP_LPHY_Rx_L1_Recovery_Time		4	//; us, defined by CHX001 Design Requirement; refer to "L1 Exit Latency Capability of PCIE RP IRS (RP_Rx4C[17:15])" for more details
#define RP_TPLL_POWERUP_AND_LOCK_Time   8  //us

#endif

