//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "MachineCheck.h"

/*===================================================================
Function   : IsMceSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support Ferr as Machine Check function
                          FALSE: this cpu does not support Ferr as Machine Check function
Purpose    : judge if cpu support Ferr as MC(Machine Check) function
Reference  : None
note:       
===================================================================*/

BOOLEAN IsMceSupport()
{
    EFI_CPUID_REGISTER CpuidInfo;

    //Machine check flag in CPUID[0x01].Edx[7]
    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
    if((CpuidInfo.RegEdx & X86_FEATURE_MCE) && (CpuidInfo.RegEdx & X86_FEATURE_MCA))
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

BOOLEAN IsCmciSupport()
{
    UINT64          MsrVal;

    MsrVal = EfiReadMsr(MSR_IA32_MCG_CAP);

    if((MsrVal & MCG_CMCI_P) == 0)
    {
        return FALSE;
    }else{
        return TRUE;
    }
}

/*===================================================================
Function   : MachineCheckInitialize()
Precondition :
Input      :  MachineCheck:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS MachineCheckInitialize(BOOLEAN MachineCheck)
{
    UINT64              MsrVal;
    UINT8               SocketInfo;
#if 0    
    UINT8               Index;
    UINT8               Banks;
#endif
    if(!IsMceSupport())
        return EFI_UNSUPPORTED;

    //BJ_GLOBAL_STATUS_MSR
    //0: Chip is in dual socket mode
    //3: Socket ID: 1 means master socket, 0 means slave socket

    SocketInfo = (UINT8)EfiReadMsr(0x1610);
    
    if(MachineCheck)
    {
        // 0. First check the lock bit.
        MsrVal = EfiReadMsr(BJ_MCA_ZX_CTRL);
        //if non-lock, first program.
        if((MsrVal & CRMCA_MMIO_BASE_LOCK) == 0)
        {
            // 1. Fill the CRMCA MMIO Base Address
            if(SocketInfo & 0x01)
            {
                //Chip in dual socket mode
                if((SocketInfo >> 3) & 0x01)
                {
                    //============Master Socket===============
                    MsrVal &= ~((UINT64)CRMCA_MMIO_BASE_MASK);
                    MsrVal |= (CRMCA_MMIO_MASTER_BASE >> 12) & CRMCA_MMIO_BASE_MASK;                
                }else
                {
                    //============Slave Socket===============
                    MsrVal &= ~((UINT64)CRMCA_MMIO_BASE_MASK);
                    MsrVal |= (CRMCA_MMIO_SLAVE_BASE >> 12) & CRMCA_MMIO_BASE_MASK;
                }               
            }else
            {
                //Chip in single socket mode
                MsrVal &= ~((UINT64)CRMCA_MMIO_BASE_MASK);
                MsrVal |= (CRMCA_MMIO_BASE >> 12) & CRMCA_MMIO_BASE_MASK;
            }

            //Lock it
            MsrVal |= CRMCA_MMIO_BASE_LOCK;
            EfiWriteMsr(BJ_MCA_ZX_CTRL, MsrVal);            
        }
      #if 0
        // 2. Initial MCE/MCA
        //Fetch Bank number
        MsrVal = EfiReadMsr(MSR_IA32_MCG_CAP);
        Banks = (UINT8)(MsrVal & MCG_BANKCNT_MASK);

        //Clear all related registers
        for (Index = 0; Index < Banks; Index++)
        {
            EfiWriteMsr(MSR_IA32_MCx_CTL(Index),    0);
            EfiWriteMsr(MSR_IA32_MCx_STATUS(Index), 0);  //May need to report this error to EBMC.
            EfiWriteMsr(MSR_IA32_MCx_ADDR(Index),   0);
            EfiWriteMsr(MSR_IA32_MCx_MISC(Index),   0);
            EfiWriteMsr(MSR_IA32_MCx_CTL2(Index),   0);
        }

        // 3. Initial CMCI feature if supported
        if(IsCmciSupport())
        {
            //If supported, Set CMCI threshold for all banks by designer suggestion.
            //the thewshold may need to adjust by specided banks
            for (Index = 0; Index < Banks; Index++)
            {
                MsrVal = EfiReadMsr(MSR_IA32_MCx_CTL2(Index));
                MsrVal &= ~MCI_CTL2_CMCI_THRESHOLD_MASK;
                MsrVal |= CMCI_THRESHOLD;
                EfiWriteMsr(MSR_IA32_MCx_CTL2(Index), MsrVal);
            }
        }
    #endif
    }

    return EFI_SUCCESS;
}

