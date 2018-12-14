//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "MonitorMWait.h"
/*===================================================================
Function   : IsMonitorMWaitSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support Monitor/MWait instruction
                          FALSE: this cpu does not support Monitor/MWait instruction
Purpose    : judge if cpu support Monitor/MWait instruction
Reference  : None
note:       
===================================================================*/

BOOLEAN IsMonitorMWaitSupport()
{
      EFI_CPUID_REGISTER CpuidInfo;

	 
     //Monitor/MWait flag in CPUID[1].ECX[8]
     EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
     if((CpuidInfo.RegEcx & ACPU_MONITOR_MWAIT_FLAG)!=0)
	    return TRUE;
    else
          return FALSE;
}

/*===================================================================
Function   : MonitorMWaitInitialize()
Precondition :
Input      :  EpsEnable:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS MonitorMWaitInitialize(BOOLEAN Monitor)
{
     UINT64   MsrVal;

    if(!IsMonitorMWaitSupport())
	    return EFI_UNSUPPORTED;

    //Monitor/MWait enable bit in MSR[0x1A0].bit[18]
    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
     if(Monitor)
	    MsrVal |= ACPU_MONITOR_MWAIT_ENABLE;
     else
	   MsrVal &= ~ACPU_MONITOR_MWAIT_ENABLE;

    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

     return EFI_SUCCESS;
}
