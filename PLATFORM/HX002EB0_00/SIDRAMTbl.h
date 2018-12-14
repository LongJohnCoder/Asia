//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
// Board : 
//----------------------------------------------------------------------------
//Ver	Name				Note
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef _SI_DRAM_TBL_H_
#define _SI_DRAM_TBL_H_

#define SIDRAM_VER			0				

//SI_DRAMC_TABLE attribute value; Token in the same Group can not be "OR"
//Group: the first nibble
#define NORMAL 				0x00
#define DIMM_1				0x01
#define DIMM_2				0x02

//Group: the first(B) nibble 
#define R1xD1 				0x01
#define R1xD2				0x02
#define R2xD1				0x03
#define R2xD2				0x04

//Group: the second nibble
#define TNI					0x10
#define RDSIT				0x10
#define DQSI				0x20
#define TX_DQ				0x30
#define TX_DQS				0x40
#define RDIMM				0x50

//Group: the third nibble
#define RAWCARD_A			0x100
#define RAWCARD_B			0x200
#define RAWCARD_C			0x300
#define RAWCARD_UD			0x400
#define RAWCARD_RD			0x500
#define RAWCARD_UE			0x600
#define RAWCARD_RE			0x700


//#define RAWCARD_D			0x400
//#define RAWCARD_E			0x500
//#define RAWCARD_F			0x600

//Group: the forth nibble
#define ChA_Setting			0x1000
#define ChB_Setting			0x2000

//SIFREQ 3200/2933/2666/2400/2133/1600
#define SI_DRAM_FREQ_NUM	0x06
#define SI_DRAM_FREQ_3200	0x00
#define SI_DRAM_FREQ_2933	0x01
#define SI_DRAM_FREQ_2666	0x02
#define SI_DRAM_FREQ_2400	0x03
#define SI_DRAM_FREQ_2133	0x04
#define SI_DRAM_FREQ_1600	0x05

#define ChA	0x00
#define ChB	0x01
#define Write	TRUE
#define Read 	FALSE

typedef struct{
	UINT16   Attribute;
	UINT16   Register;
	UINT16   Mask;
	UINT8    RegVal[SI_DRAM_FREQ_NUM]; 
}SI_DRAMC_REGISTER_SETTING;


extern SI_DRAMC_REGISTER_SETTING OdtSiTbl[];
extern UINT32 OdtSiTblItems;

extern SI_DRAMC_REGISTER_SETTING BasicIOTimingTbl[];
extern UINT32 BasicIOTimingTblItems;

extern SI_DRAMC_REGISTER_SETTING DrivingTbl[];
extern UINT32 DrivingTblItems;

extern SI_DRAMC_REGISTER_SETTING DrivingSelectionTbl[];
extern UINT32 DrivingSelectionTblItems;

extern SI_DRAMC_REGISTER_SETTING ClkPhaseTbl[];
extern UINT32 ClkPhaseTblItems;

extern SI_DRAMC_REGISTER_SETTING OutputTimingTbl[];
extern UINT32 OutputTimingTblItems;

extern SI_DRAMC_REGISTER_SETTING ReadTimingTbl[];
extern UINT32 ReadTimingTblItems;

extern SI_DRAMC_REGISTER_SETTING ClkDutyTbl[];
extern UINT32 ClkDutyTblItems;

extern SI_DRAMC_REGISTER_SETTING EQPCtrlTbl[];
extern UINT32 EQPCtrlTblItems;

extern SI_DRAMC_REGISTER_SETTING RxEqTbl[];
extern UINT32 RxEqTblItems;

extern SI_DRAMC_REGISTER_SETTING VrefTbl[];
extern UINT32 VrefTblItems; 

//extern SI_DRAMC_REGISTER_SETTING RxVerfRDIMMTbl[];
//extern UINT32 RxVerfRDIMMTblItems;

extern SI_DRAMC_REGISTER_SETTING DdrPhyTbl[];
extern UINT32 DdrPhyTblItems;

extern SI_DRAMC_REGISTER_SETTING VcdlOutputClkTbl[];
extern UINT32 VcdlOutputClkTblItems;

#endif
