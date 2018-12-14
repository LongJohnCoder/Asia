//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "ThermalMonitor.h"
#include "CpuIa32.h"
//#include "ACpuCommon.h"
//#include "Math.h"
#include "EfiCommonLib.h"

/*===================================================================
Function   : ACPUThermalMonitorInit()
Precondition :None
Input      :       
Output     :                 
Purpose    : ACPU Thermal monitor init
Reference  : None
===================================================================*/
EFI_STATUS ACPUThermalMonitorInit()
{
     UINT64  TempQword;

     //enable powersaver
     TempQword = EfiReadMsr(0x1A0);
     TempQword |= 0x10000;
     EfiWriteMsr(0x1A0, TempQword);

    //select TM3 MSR 1A0 bit[3] and bit[13]
     TempQword = EfiReadMsr(0x1A0);

   TempQword |= 0x2008;
   //TempQword &= ~(UINT64)0x2008;
     EfiWriteMsr(0x1A0, TempQword);


     //lock powersaver MSR 1A0 bit[20]
     TempQword = EfiReadMsr(0x1A0);
     TempQword |= 0x100000;
     EfiWriteMsr(0x1A0, TempQword);

     return EFI_SUCCESS;
}

/*===================================================================
Function   : ThermalMonitorInit()
Precondition :None
Input      :       
Output     :                 
Purpose    : according to CPU type to init thermal monitor
Reference  : None
===================================================================*/

void ThermalMonitorInit()
{
			ACPUThermalMonitorInit();
	return;
}

