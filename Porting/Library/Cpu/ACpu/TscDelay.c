//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Tiano.h"
#include "CpuIA32.h"
#include <Ppi\AsiaCpuPpi\AsiaCpuPpi.h>

extern void GetACpuSpeedInfo(ACPU_SPEED_INFO * SpeedInfo);

VOID
TscDelay(
  IN UINTN      Microseconds
)
{  
  ACPU_SPEED_INFO						  SpeedInfo;
  UINT32                                  CoreFreq;
  UINT64                                  CurrentTSC;
  UINT64                                  OriginalTSC;
  UINT64                                  EndTSC;

   //get cpu speed
   GetACpuSpeedInfo(&SpeedInfo);
   //CurrentBusRatio is double of the real BusRatio
   CoreFreq = SpeedInfo.CurrentBusRatio * SpeedInfo.CPUBusSpeed;
   CoreFreq = CoreFreq >> 1;
   
   OriginalTSC =  EfiReadTsc();
   EndTSC = OriginalTSC  + Microseconds * CoreFreq;
   
   do{
   	  CurrentTSC = EfiReadTsc();
   	}while(CurrentTSC < EndTSC);

  return ;
}
