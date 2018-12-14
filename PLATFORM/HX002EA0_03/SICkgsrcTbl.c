//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/* 

CKGSRC Si related setting

*/
#include "AsiaIoLib.h"
#include "CHX002Reg.h"


ASIA_IO_TABLE_6408_REV	CKGSRC_SI_TBL[]=
{
	
	{0x00,	0xFF,	(CHX002_NPMC|D0F4_CKGSRC_IO_CTL_5),	D0F4_RSRC_RFTIME_1_0, 0x18} // D0F4 RxC2[4:3], CKGSRC IO Rise/Fall Time Control

};

UINTN CKGSRC_SI_TBL_Items = sizeof(CKGSRC_SI_TBL)/sizeof(ASIA_IO_TABLE_6408_REV);



