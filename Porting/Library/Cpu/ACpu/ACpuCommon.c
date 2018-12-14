//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/******************************************************************************
Functionality  : the CPU common fucntion
Function List  : GetCPUBaseClock()
******************************************************************************/

#include "CpuIA32.h"
#include "EfiCommonLib.h"

/*===================================================================
Function   : GetCPUBaseClock()
Precondition :None
Input      :  void
Output     : the Cpu's Base Clock frequence
Purpose    : Get CPU's CPU Base Clock
Reference  : None
===================================================================*/
UINT16 GetCPUBaseClock()
{
    UINT64       MsrVal;
    UINT16       ClockTable[]={0, 0, 0, 0, 0, 100, 0, 0};
    UINT8        CPUBusIndex;
    UINT16       Frequency;


	        MsrVal = EfiReadMsr(0xCD);
	        //MSR[0xCD]:[2:0]
	        CPUBusIndex = (UINT8)(MsrVal & 0x07);
	Frequency = ClockTable[CPUBusIndex];

    return Frequency;
}
