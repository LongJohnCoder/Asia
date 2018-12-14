//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "CpuidMaximumLimit.h"
#include "CState.h"
#include "EpsInit.h"
#include "ExecuteDisable.h"
#include "FastString.h"
#include "Ferr.h"
#include "MachineCheck.h"
#include "MicrocodeUpdate.h"
#include "MonitorMWait.h"
#include "Prefetcher.h"
#include "ThermalMonitor.h"
#include "TPREcho.h"
#include "Txt.h"
#include "Vt.h"
#include "TscDeadLine.h"
#include "Ppi\AsiaCpuPpi\AsiaCpuPpi.h"
#include "CPUIA32.h"

void CpuFeatureInitialize(ASIA_CPU_CONFIGURATION *Feature)
{

  UINT64   MsrVal;
   //------------------------------------------------
   //-----TM Related initialize, sync BWG refer code
   //------------------------------------------------
   FerrInitialize(Feature->FerrInterruptReporting);
   EpsInitialize(Feature->EpsEnable, Feature->BootWithMaxFrequence);
   FastStringEnable(Feature->FastString);
   //if user disable EPS, so can not enable TM
   if(Feature->EpsEnable)
   	ThermalMonitorInit();

   //-------------------------------------------------
   //-----Setuputility part
   //-------------------------------------------------
#ifdef ZX_TXT_SUPPORT
   TxtInitialize(Feature->TxtEnable && Feature->Msr3AEnable);
#endif

   VtInitialize((Feature->VtEnable && Feature->Msr3AEnable));

   //-------------------------------------------------
   //-----Other initialize part, no setuputility part
   //-------------------------------------------------

   CpuidMaximumValueLimitEnable(Feature->LimitCpuidMaximumValue);

   CStatesInitialize(Feature);
   NAPSNAPInit(Feature->NAPSNAPEnalbe);
   ExecuteDisableInitialize(Feature->ExecuteDisableBit);
   //PrefetcherInitialize(Feature->HardwarePrefetcherEnable,Feature->AdjacentCacheLinePrefetchEnable);
   MonitorMWaitInitialize(Feature->MonitorMWaitEnable);
   TPREchoInitialize(Feature->TPREchoEnable);
   TSCDeadLineInitialize(Feature->TscDeadlineModeEnable);
   MachineCheckInitialize(Feature->MachineCheckEnable);
   
	 if(!Feature->MCASupport) {
		    //If MCA supported disable
		    //Set supported bank numbers to 0
		    MsrVal = EfiReadMsr(0x1616);
		    MsrVal &= (UINT64)~(0xFF);
		    EfiWriteMsr(0x1616, MsrVal);
	 }
   
   
   
#ifdef ZX_SECRET_CODE
   //Enable thermal trip
   //MsrVal = EfiReadMsr(0x1407);
   //MsrVal |= (UINT64)(1 << 18);
   //EfiWriteMsr(0x1407, MsrVal);

#endif
}
