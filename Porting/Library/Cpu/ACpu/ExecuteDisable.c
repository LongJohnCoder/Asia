//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "ExecuteDisable.h"
/*===================================================================
Function   : IsExecuteDisableSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support NX(Execute disable) function
                          FALSE: this cpu does not support NX(Execute disable) function
Purpose    : judge if cpu support NX function
Reference  : None
note:       
===================================================================*/

BOOLEAN IsExecuteDisableSupport()
{
     EFI_CPUID_REGISTER CpuidInfo;

     EfiCpuid(EFI_CPUID_EXTENDED_FUNCTION, &CpuidInfo);
     if(CpuidInfo.RegEax <= EFI_CPUID_EXTENDED_FUNCTION)
         // Entended CPUID functions are not supported on this processor.
         return FALSE;

    //NX flag bit in cpuid[0x80000001].EDX[20]
    EfiCpuid(EFI_CPUID_EXTENDED_CPU_SIG, &CpuidInfo);
    if((CpuidInfo.RegEdx & ACPU_EXECUTE_DISABLE_FLAG)!=0)
	return TRUE;
   else
   	return FALSE;
}

/*===================================================================
Function   : ExecuteDisableInitialize()
Precondition :
Input      :  ExecuteDisable:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS ExecuteDisableInitialize(BOOLEAN ExecuteDisable)
{
    UINT64   MsrVal;

    if(!IsExecuteDisableSupport())
	  return EFI_UNSUPPORTED;

   //Nx enable bit in MSR[0x1A0].bit[34]
   MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
   if(ExecuteDisable)
   	MsrVal &= ~ACPU_EXECUTE_DISABLE_ENABLE;
   else
   	MsrVal |= ACPU_EXECUTE_DISABLE_ENABLE;
   EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);


   return EFI_SUCCESS;
}
