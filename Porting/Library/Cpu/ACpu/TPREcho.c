//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "TPREcho.h"
//#include "ACpuCommon.h"
extern UINT8 GetACpuCores();
/*===================================================================
Function   : IsTPREchoSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support TPR Echo function
                          FALSE: this cpu does not support TPR Echo function
Purpose    : judge if cpu support TPR Echo
Reference  : None
note:       
===================================================================*/

BOOLEAN IsTPREchoSupport()
{
    //if single core cpu returen FALSE
	if (GetACpuCores() == 1)
        return FALSE;
    //if double core cpu return TRUE 
    else
        return TRUE;
}

/*===================================================================
Function   : TPREchoInitialize()
Precondition :
Input      :  TPREcho:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS TPREchoInitialize(BOOLEAN TPREcho)
{

    UINT64 MsrVal;
    

    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
    if (GetACpuCores() == 1) {
      // single cpu, disable it
      //
		MsrVal |= ACPU_TPR_ECHO_DISABLE;
    }
    else {
      // multi-core, enable it
      //
      if(TPREcho) {
        MsrVal &= ~ACPU_TPR_ECHO_DISABLE;
      	} else {
         MsrVal |= ACPU_TPR_ECHO_DISABLE;
      	}
    }
    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

    return EFI_SUCCESS;
}

