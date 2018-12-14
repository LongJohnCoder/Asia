//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Tiano.h"
#include  "PStates.h"
#include "CpuIA32.h"
#include "Ppi\AsiaCpuPpi\AsiaCpuPpi.h"
#include "EfiCommonLib.h"

extern UINT16 GetCPUBaseClock();


UINT64 GetPState(UINT32 MsrIndex, UINT8 count);

/*===================================================================
Function   : GetMaxBusRatio()
Precondition :None
Input      :
Output     :
Purpose    : get max FID
Reference  : None
===================================================================*/

UINT8 GetMaxBusRatio()
{
    UINT64 PStatus;
    UINT8  MaxFid;

    PStatus = EfiReadMsr(0x198);

    MaxFid = (UINT8)(RShiftU64(PStatus, 40) & 0xFF);
    if (MaxFid > MAX_FIXED_RATIO)
        MaxFid = MAX_FIXED_RATIO;

    return  MaxFid;
}


/*===================================================================
Function   : CreateHiState()
Precondition :None
Input      :  Header: point to FVID_HEADER
              CPUBusFreq: CPUBus
Output     :
Purpose    : Create one high P_STATE
Reference  : None
===================================================================*/

void CreateHiState(ACPU_PSTATE_TABLE *Header,
                   UINT16 CPUBusFreq)
{
    UINT64 PStatus;

    PStatus = EfiReadMsr(0x198);

    Header->StatesNum = 1;

    Header->PStateTable[0].State = 0;
    Header->PStateTable[0].VID = (UINT8)(RShiftU64(PStatus, 32) & 0xFF);
    Header->PStateTable[0].BusRatio = GetMaxBusRatio();
    Header->PStateTable[0].CoreFreq = CPUBusFreq * Header->PStateTable[0].BusRatio;
	    Header->PStateTable[0].CoreFreq >>= 1;

    Header->PStateTable[0].Power = Header->PStateTable[0].CoreFreq  * 2;	

}


/*===================================================================
Function   : CreateHiLowState()
Precondition :None
Input      :  Header: point to FVID_HEADER
                CPUBusFreq: CPUBus
Output     :
Purpose    : Create two high and Low P_STATE
Reference  : None
===================================================================*/
void CreateHiLowState(ACPU_PSTATE_TABLE *Header,
                      UINT16 CPUBusFreq)
{
    UINT64 PStatus;

    PStatus = EfiReadMsr(0x198);


    Header->StatesNum = 2;

    //High P_STATE
    Header->PStateTable[0].State = 0;
    Header->PStateTable[0].VID = (UINT8)(RShiftU64(PStatus, 32) & 0xFF);
    Header->PStateTable[0].BusRatio = GetMaxBusRatio();
    Header->PStateTable[0].CoreFreq = CPUBusFreq * Header->PStateTable[0].BusRatio;
	    Header->PStateTable[0].CoreFreq >>= 1; 
    Header->PStateTable[0].Power = Header->PStateTable[0].CoreFreq * 2;

    //Low P_STATE
    Header->PStateTable[1].State = 1;
    Header->PStateTable[1].VID =  (UINT8)(RShiftU64(PStatus, 48) & 0xFF) ;
    Header->PStateTable[1].BusRatio =  (UINT8)(RShiftU64(PStatus, 56) & 0xFF);
    Header->PStateTable[1].CoreFreq = CPUBusFreq * Header->PStateTable[1].BusRatio;
	    Header->PStateTable[1].CoreFreq >>= 1; 

    Header->PStateTable[1].Power = Header->PStateTable[1].CoreFreq * 2;

}


/*===================================================================
Function   : CreatePStatesMsr()
Precondition :None
Input      :  Header: point to FVID_HEADER
Output     :
Purpose    : using MSR create P_STATES
Reference  : None
===================================================================*/
void  CreatePStatesMsr(ACPU_PSTATE_TABLE  *Header, UINT16 CPUBusFreq)
{
  UINT16 MaxPVal, CurPVal;
  UINT8 p_cnt;
  UINT64 MsrVal;
  UINT8 Fid, Vid;

  UINT8 Old_Fid, Old_Vid;

  UINT8 StateNum;


  UINT16 Stack[32];   // Suppose only max 32 p-state.
  UINT8  Index;


  MsrVal = EfiReadMsr(0x198);
  MaxPVal = RShiftU64(MsrVal, 32) & 0xffff;

  p_cnt = 0xFF;

  Index = 0;
  CurPVal = 0xffff;
  Stack[Index++] = CurPVal;
  
  // find the max pstate
  do {

    p_cnt++;
    MsrVal = GetPState(0x1466, p_cnt);

    Fid = RShiftU64(MsrVal, 32) & 0xff;
    Vid = MsrVal & 0xff;
    CurPVal = (Fid<<8) | Vid;

    Stack[Index++] = CurPVal;
    // Notice!!: here, we not check the stack[] overflow

  }while (CurPVal < MaxPVal);


  StateNum = 0;
  Old_Fid = 0;
  Old_Vid = 0;


  while (TRUE) {
    CurPVal = Stack[--Index];
    if (CurPVal == 0xffff) {
      break;
    }
    Fid = (CurPVal>>8) & 0x0ff;
    Vid = CurPVal & 0xff;

  
    if (Fid == Old_Fid) {
      if (Vid < Old_Vid && StateNum != 0) {
        // modify the existing state
        Header->PStateTable[StateNum-1].VID = Vid;
      }
    }
    else {
      // New state
      Header->PStateTable[StateNum].State = StateNum;
      Header->PStateTable[StateNum].VID = Vid;
      Header->PStateTable[StateNum].BusRatio = Fid;
      Header->PStateTable[StateNum].CoreFreq = CPUBusFreq * Fid;
	  Header->PStateTable[StateNum].CoreFreq >>= 1;

      Header->PStateTable[StateNum].Power = Header->PStateTable[StateNum].CoreFreq* 2;

      StateNum++;  // next indexer
    }

    Old_Fid = Fid;
    Old_Vid = Vid;
    

  }

  Header->StatesNum = StateNum;

}


/*===================================================================
Function   : CreatePStates()
Precondition :None
Input      :  Header: point to FVID_HEADER
Output     :
Purpose    : according to CPU type create P_STATES
Reference  : None
===================================================================*/
EFI_STATUS  CreatePStates(ACPU_PSTATE_TABLE  *Header)
{

    UINT16                     CPUBus;

    CPUBus = GetCPUBaseClock();
	CreatePStatesMsr(Header, CPUBus);

    return EFI_SUCCESS;
}

/*===================================================================
Function   : GetCpuState()
Precondition :None
Input      :  Header: point to FVID_HEADER
Output     :
Purpose    : Get PStates from tables or Create it
Reference  : None
===================================================================*/

EFI_STATUS
GetCpuPState (IN ACPU_PSTATE_TABLE *Header)
{

    CreatePStates(Header);

    return EFI_SUCCESS;
}
