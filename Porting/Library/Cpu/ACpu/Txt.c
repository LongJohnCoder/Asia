//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Txt.h"
#include "Vt.h"
#include "AsiaIoLib.h"

#ifdef ZX_TXT_SUPPORT
/*===================================================================
Function   : IsTxtSupport()
Precondition :
Input      : VOID
Output     : BOOLEAN:
                          TRUE:  this cpu  support TXT function
                          FALSE: this cpu does not support TXT function
Purpose    : judge if cpu support TXT function
Reference  : None
note:       
===================================================================*/

BOOLEAN IsTxtSupport()
{
    EFI_CPUID_REGISTER CpuInfo;

    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuInfo);

    //SMX flag cpuid[1].RegEcx[6]
    if ((CpuInfo.RegEcx & ACPU_FEATURE_SMX) != 0)
        return TRUE;
    else
        return FALSE;
}

EFI_STATUS EnableVmxInSmx()
{
    UINT64 MsrVal;

    MsrVal = EfiReadMsr(ACPU_MSR_IA32_FEATURE_CONTROL);
    if (!(MsrVal & ACPU_MSR_IA32_FEATURE_CONTROL_LOCK)){
        if (!(MsrVal & ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_VMX_IN_SMX)){
            EfiWriteMsr(ACPU_MSR_IA32_FEATURE_CONTROL, MsrVal | 
                                                       ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_VMX_IN_SMX);
        }
    }else{
        if (!(MsrVal & ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_VMX_IN_SMX)){
            AsiaIoWrite8(0xcf9, SYSTEM_RESET_S5);
        }
    }

    return EFI_SUCCESS;
}

/*===================================================================
Function   : EnableTxt()
Precondition :
Input      : void
Output     : void
Purpose    : Enable  cpu's TXT function
Reference  : None
note:
===================================================================*/

EFI_STATUS EnableTxt()
{
    UINTN  Cr4;
    UINT64 MsrVal;
    
    // 1. Make sure SMX enable
    Cr4 = EfiReadCr4();
    if (!(Cr4 & ACPU_CR4_SMX_ENABLE)){
        EfiWriteCr4(Cr4 | ACPU_CR4_SMX_ENABLE);
    }

    // 2. Enable SENTER
    MsrVal = EfiReadMsr(ACPU_MSR_IA32_FEATURE_CONTROL);
    // lock bit for MSR_IA32_FEATURE_CONTROL
    if (!(MsrVal & ACPU_MSR_IA32_FEATURE_CONTROL_LOCK)){
        if (!(MsrVal & (ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_SENTER |
                        ACPU_MSR_IA32_FEATURE_CONTROL_SENTER_PARAM_CTL))){
            EfiWriteMsr(ACPU_MSR_IA32_FEATURE_CONTROL, MsrVal |
                                                       ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_SENTER |
                                                       ACPU_MSR_IA32_FEATURE_CONTROL_SENTER_PARAM_CTL);
        }
    }else{
        if (!(MsrVal & (ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_SENTER |
                        ACPU_MSR_IA32_FEATURE_CONTROL_SENTER_PARAM_CTL))){
            AsiaIoWrite8(0xcf9, SYSTEM_RESET_S5);
        }
    }
    
    // 3. Enable VMX in SMX, when VMX is supported.
    if (IsVtSupport())
        EnableVmxInSmx();

    return EFI_SUCCESS;
}

/*===================================================================
Function   : DisableTxt()
Precondition :
Input      : void
Output     : void
Purpose    : disable  cpu'sTXT function
Reference  : None
note:
===================================================================*/

EFI_STATUS DisableTxt()
{
    UINT64 Cr4;
    UINT64 MsrVal;

    // 1. Disable SENTER, VMX in SMX
    MsrVal = EfiReadMsr(ACPU_MSR_IA32_FEATURE_CONTROL);
    //if MSR_IA32_FEATURE_CONTROL_LOCK not set, we can disable SENTER
    if (!(MsrVal & ACPU_MSR_IA32_FEATURE_CONTROL_LOCK)){
        EfiWriteMsr(ACPU_MSR_IA32_FEATURE_CONTROL, MsrVal &
                                                    (~ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_VMX_IN_SMX) & 
                                                    (~ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_SENTER) &
                                                    (~ACPU_MSR_IA32_FEATURE_CONTROL_SENTER_PARAM_CTL) );
    }else{
        if (MsrVal & (ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_VMX_IN_SMX | 
                      ACPU_MSR_IA32_FEATURE_CONTROL_ENABLE_SENTER |
                      ACPU_MSR_IA32_FEATURE_CONTROL_SENTER_PARAM_CTL) ){
            AsiaIoWrite8(0xcf9, SYSTEM_RESET_S5);
        }
    }

    // 2. Disable SMX
    Cr4 = EfiReadCr4();
    if (Cr4 & ACPU_CR4_SMX_ENABLE){
        EfiWriteCr4(Cr4 & (~ACPU_CR4_SMX_ENABLE));
    }
    
    return EFI_SUCCESS;
}

/*===================================================================
Function   : TxtInitialize()
Precondition :
Input      :  TxtEnable:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED:   this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS TxtInitialize(BOOLEAN TxtEnable)
{
    if (!IsTxtSupport())
        return EFI_UNSUPPORTED;

    if (TxtEnable)
        EnableTxt();
    else
        DisableTxt();

    return EFI_SUCCESS;
}

#endif  // ZX_TXT_SUPPORT