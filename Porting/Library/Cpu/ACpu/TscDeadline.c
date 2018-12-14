//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************



#include "TscDeadLine.h"
#include "EfiCommonLib.h"

/*===================================================================
Function   : TSCDeadLineInitialize()
Precondition :
Input      :  
Output     : EFI_STATUS
             EFI_SUPPORTED: this cpu don't support this function
             EFI_SUCCESS:     initialized this feature
Purpose    : Enable or disable APIC timer TSC dead line mode
Reference  : None
note:
===================================================================*/
EFI_STATUS TSCDeadLineInitialize(BOOLEAN TscDeadLineModeEnable)
{
    UINT64    MsrVal;

	MsrVal = EfiReadMsr(0x1200);

    if(TscDeadLineModeEnable) {
	    MsrVal |= TSC_DEAD_LINE_SUPPORT_BIT;
    } else {
        MsrVal &= ~TSC_DEAD_LINE_SUPPORT_BIT;
    }
	EfiWriteMsr(0x1200, MsrVal);
    
    return EFI_SUCCESS;
} 

