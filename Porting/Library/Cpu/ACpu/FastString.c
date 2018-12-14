//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "FastString.h"
//#include "ACpuCommon.h"
/*===================================================================
Function   : FastStringEnable()
Precondition: 
Input      :  FastString:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS FastStringEnable(BOOLEAN FastString)
{
     UINT64  MsrVal;
 
    //enable Fast String Msr 0x1A0 bit[0]
     MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
     if(FastString)
	 MsrVal |= 0x01;
     else
	MsrVal &= ~0x01;
     EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);
     return EFI_SUCCESS;
}
