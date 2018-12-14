//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "Prochot.h"
//#include "ACpuCommon.h"
/*===================================================================
Function   : ProchotInitialize()
Precondition :
Input      :  Prochot:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS ProchotInitialize(BOOLEAN Prochot)
{
     UINT64 MsrVal;

    //Bi-Directional PROCHOT enable bit in Msr 0x1A0 bit[17]
     MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
     if(Prochot)
	 MsrVal |= ACPU_PROCHOT_ENABLE;
     else
	MsrVal &= ~ACPU_PROCHOT_ENABLE;
     EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);
     return EFI_SUCCESS;
}
