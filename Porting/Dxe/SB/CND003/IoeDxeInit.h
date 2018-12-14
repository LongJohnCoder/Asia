/** @file
   ZX-E(CHX002) Asia SbDxe library functions : IoeDxeInit.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef __IOE_PCI_INIT__
#define __IOE_PCI_INIT__

#include "CND003Reg.h"



/**********************************/
#define IOEBUSXUSP_VIDDID 0x071F1106
#define IOEBUSXP2_VIDDID  0x07211106
#define IOEBUSXUSP_VIDDID_ZX 0x071F1D17
#define IOEBUSXP2_VIDDID_ZX  0x07211D17


#define IOE_VID_VIA		0x1106
#define IOE_VID_ZX		0x1D17
#define DID_PEEP	0x071F
#define DID_XBCTL	0x9100
#define DID_PEA0	0x0710
#define DID_PEA1	0x0711
#define DID_PEA2	0x0712
#define DID_PEA3	0x0713
#define DID_PEA4	0x0714
#define DID_PEB0	0x0715
#define DID_PEB1	0x0720
#define DID_PESB	0x0721
#define DID_PCIEIF	0x0722
#define DID_EPTRFC	0x9101



#define IOE_DO_EQ  				2
#define IOE_SKIP_EQ_MANUAL 		1
#define IOE_SKIP_EQ_TABLE 		0

#define IoeExist() 	((BIT0 & AsiaPciRead8(AsiaPciAddress(0, 0, 6, 0x47)))?1:0)



typedef struct RootPortList{
	UINT8 Bus;
	UINT8 Dev;
	UINT8 Func;
} RpList;

typedef struct PATH{
	UINT8 Dev;
	UINT8 Func;
} Path;

VOID IoeIsbSidLock();

/*Pre Pci Init Stage*/
//EFI_STATUS
//IoeFillSpeValue(ASIA_NB_CONFIGURATION *NbCfg);

EFI_STATUS
IoePrePciInit(ASIA_NB_CONFIGURATION *NbCfg);

typedef struct IoeL1ExitLatencyCorrespondingTbl{
	UINT16 PhyCfg;		// unique ID for PHYCFG, For CND003, the PHYCFG is ((PHYBCFG<<8)|(PHYACFG))
	UINT16 RegForPEA0;	// register offset in EPHY,indicate the register location for the corresponding port ,0 indicate the port was not exist in this PHYCFG
	UINT16 RegForPEA1;
	UINT16 RegForPEA2;
	UINT16 RegForPEA3;
	UINT16 RegForPEA4;
	UINT16 RegForPEB0;
	UINT16 RegForPEB1;
	UINT16 RegForPEEP;
}IOE_L1SET_TBL;




#define SET_1BYTE 0
#define SET_4BYTE 1
typedef struct DxeRegisterSetting{
	UINT8 ByteCount;
	UINT8 Busx;
	UINT8 Devx;
	UINT8 Funx;
	UINT16 Offsetx;
	UINT32 Maskx;
	UINT32 Valuex;
} DxeRegSet;

EFI_STATUS
IoeDxeTempAssignment(VOID);

VOID
IoeDxeClearTempAssignment(VOID);

#if 0
VOID
DebugDxeDumpCfgSpaceDxe(VOID);
#endif

VOID
IoeDumpMemDxe(
	UINT32 MemBase, 
	UINT16 DCount);

VOID
IoeDumpCfgDxe(
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount);




/*Post Pci Init Stage*/
VOID
IoeAerStatusClear(
	UINTN Bus, 
	UINTN Device, 
	UINTN Function);

VOID
IoeHideXbctlEptrfcDxe(
	ASIA_NB_CONFIGURATION *NbCfg);

VOID
DebugIoe_1(VOID);

EFI_STATUS
IoeSaveBusNumber2BootScript(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT8 DevBusNum);



#if MULTI_IOE_SUPPORT



STATIC UINT8 
IoeDxeGetPortFlagBit(
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun);

STATIC BOOLEAN
IoeDxeIsUsablePort(
	UINT8 Bus, UINT8 Dev, UINT8 Fun);

STATIC VOID
IoeDxeMaskSearchPort(
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun);

STATIC VOID
IoeDxeUnmaskSearchPort(
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun);


VOID 
IoeDxeUnmaskAllPort(VOID);


EFI_STATUS
IoeDxeMaskInitializedPort(VOID);


#endif






#define ASIA_IOE_REVISION AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_INTERNAL_REV_ID))


#define IOE_PROCESS_R6408M_TABLE_SAVE_1(tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_IOE_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave8(((tbl)[tAbLeIdx].Address), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)


#define IOE_PROCESS_PCIE_R6408M_TABLE_SAVE_1(BaseAddr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_IOE_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModifySave8(BaseAddr, ((tbl)[tAbLeIdx].Address), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

//ALJ-20160825
#define IOE_PROCESS_SB_R6408M_TABLE_SAVE(tbl, len) \
	do{ \
	  UINT8 sBrEvIsion = (ASIA_IOE_REVISION);\
	  UINT32 tAbLeIdx; \
	  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
	  { \
		if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
		  continue; \
		AsiaPciModifySave8((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
	  } \
	} while(0)

#define IOE_PROCESS_SB_R6432M_TABLE_SAVE(tbl, len) \
		do{ \
		  UINT8 sBrEvIsion = (ASIA_IOE_REVISION);\
		  UINT32 tAbLeIdx; \
		  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
		  { \
			if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
			  continue; \
			AsiaPciModifySave32((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
		  } \
		} while(0)

            
#define IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(BaseAddr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_IOE_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModifySave32(BaseAddr, ((tbl)[tAbLeIdx].Address), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)
#endif
