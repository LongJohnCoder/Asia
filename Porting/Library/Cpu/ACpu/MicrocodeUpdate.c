//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "MicrocodeUpdate.h"
#include "EfiCommonLib.h"
//#include "ACpuCommon.h"
#include "Ppi\AsiaCpuPpi\AsiaCpuPpiProtocol.h"

UINT32   CheckSum(UINT32 *Buffer, UINT32 Length)
{
       UINT32  Sum;
       UINT32  Index;
	UINT32  Count;

	Count = Length >> 2;

	for(Sum=0, Index=0; Index < Count; Index++)
	    {
	        Sum += *(Buffer + Index);
	    }

      return Sum;
}

/*===================================================================
Function   : GetUpdateID()
Precondition :
Input      :  void
Output     : 
                 return update level
Purpose    :  get update level
Reference  : None
note:       
===================================================================*/

UINT32 GetUpdateID()
{
      EFI_CPUID_REGISTER  CpuidInfo;
      UINT64   MsrVal;

     //execute a CpuID instruction sub-function of 1, and then  read
     //IA32_BIOS_SIGN_ID(MSR 0x8B).The high 32-bits of the MSR will
     //be the update's ID value
     EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
     MsrVal = EfiReadMsr(EFI_MSR_IA32_BIOS_SIGN_ID);

     MsrVal = RShiftU64(MsrVal, 32);
     return (UINT32)MsrVal;
}

/*===================================================================
Function   : VerifyHeader()
Precondition :
Input      :  
               Header: point to ACPU_MICROCODE_UPDATE_HEADER
Output     : EFI_STATUS
                         EFI_NOT_FOUND: there is no more microcode
                         EFI_INVALID_PARAMETER:this microcode has invalid header
                         EFI_SUCCESS: this microcode is correct and right
Purpose    :  judge this mircocode is correct and right
Reference  : None
note:       
===================================================================*/

EFI_STATUS VerifyHeader(ACPU_MICROCODE_UPDATE_HEADER *Header)
{
      EFI_CPUID_REGISTER  CpuidInfo;
      UINT32  *Buffer;

      if((Header->TotalSize == 0)||(Header->TotalSize ==0xFFFFFFFF))
	  return EFI_NOT_FOUND;
	  
      //verify signature
      if(Header->Signature != ACPU_MICROCODE_UPDATE_SIGNATURE)
	  return EFI_INVALID_PARAMETER;

      //verify cpuid
      EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
      if(CpuidInfo.RegEax != Header->ProcessorId)
	    return EFI_INVALID_PARAMETER;
	  
    Buffer = (UINT32*)(UINTN)Header;
    if(CheckSum(Buffer, Header->TotalSize) != 0)	   
	   return EFI_INVALID_PARAMETER;
   
    return EFI_SUCCESS;    
}

/*===================================================================
Function   : TrigerUpdate()
Precondition :
Input      :  void
Output     : void
Purpose    :  triger microcode update
Reference  : None
note:       
===================================================================*/

void TrigerUpdate(ACPU_MICROCODE_UPDATE_HEADER *Header)
{
     UINT64 MsrVal;

     //init update level to 0
    EfiWriteMsr(EFI_MSR_IA32_BIOS_SIGN_ID, 0);
	 
    MsrVal = (EFI_PHYSICAL_ADDRESS)(UINTN)(Header + 1);
    EfiWriteMsr(EFI_MSR_IA32_BIOS_UPDT_TRIG, MsrVal);
}

/*===================================================================
Function   : CheckUpdate()
Precondition :
Input      :  void
Output     : EFI_STATUS
                         EFI_NOT_STARTED: microcode update has not start since reset
                         EFI_SUCCESS:    microcode has trigered
                         EFI_ABORTED:   occured error when microcode update
Purpose    :  check update state
Reference  : None
note:       
===================================================================*/

EFI_STATUS CheckUpdate()
{
     UINT64 MsrVal;

     MsrVal=EfiReadMsr(0x1205);
     MsrVal = MsrVal & 0xFF;
 
     if (MsrVal == 0x00)
	   return EFI_NOT_STARTED;
      else if (MsrVal == 0x01)
	   return EFI_SUCCESS;
      else
	  return EFI_ABORTED;
}


/*===================================================================
Function   : MicrocodeCheckAndTriger()
Precondition :
Input      : 
             MicrocodeHeader: pointer to ACPU_MICROCODE_UPDATE_HEADER
             UpdateRevision:
Output     : EFI_STATUS
                EFI_SUCCESS: this is a cpu microcode header and is correctly trigered
                EFI_INVALID_PARAMETER: this is not a cpu microcode or the header
                                                        has corrupt
               EFI_NOT_FOUND: this is the end of microcode block
              EFI_NOT_STARTED:  microcode update has not start since reset
              EFI_ABORTED:      occured error when microcode update
Purpose    : load and triger Cpu microupdate code
Reference  : None
note:       
===================================================================*/

EFI_STATUS  MicrocodeCheckAndTriger(
                     IN ACPU_MICROCODE_UPDATE_HEADER  *MicrocodeHeader,
                     OUT UINT32 *UpdateRevision
)
{
      ACPU_MICROCODE_UPDATE_HEADER     *ACpuMicroHeader;
       EFI_STATUS                                         Status;

	ACpuMicroHeader = (ACPU_MICROCODE_UPDATE_HEADER *)MicrocodeHeader;

        Status = VerifyHeader(ACpuMicroHeader);
	if (Status == EFI_SUCCESS){
                TrigerUpdate(ACpuMicroHeader);
                Status = CheckUpdate();
               if (Status != EFI_SUCCESS)
	              return Status;

               *UpdateRevision = GetUpdateID();
		}
	return Status;
}

