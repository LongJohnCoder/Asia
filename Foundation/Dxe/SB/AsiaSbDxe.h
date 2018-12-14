//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
/*
\License
*/
#ifndef __ASIA_SB_DXE_H_
#define __ASIA_SB_DXE_H_

#include "EfiCommon.h"
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include EFI_PROTOCOL_DEFINITION(AsiaSbProtocol)

extern EFI_HANDLE gImageHandle;

EFI_STATUS GetAsiaSbCfgFromHob(
  OUT VOID** SbCfg
  );

EFI_STATUS AsiaSbDxePrePciInit (
  IN EFI_ASIA_SB_PROTOCOL *This
  );
  
EFI_STATUS AsiaSbDxePreprocessPciController (
  IN EFI_ASIA_SB_PROTOCOL *This,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
  IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
  );
  
EFI_STATUS AsiaSbDxePostPciInit (
  IN EFI_ASIA_SB_PROTOCOL *This,
  IN EFI_PCI_IO_PROTOCOL *PciIo
  );
  
EFI_STATUS AsiaSbDxePreBootInit (
  IN EFI_ASIA_SB_PROTOCOL *This
  );

#define ASIA_SB_REVISION AsiaPciRead8(ASIA_PCI_ADDRESS(0, 0, 4, 0xF6))
#define PROCESS_SB_R6408M_TABLE_SAVE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave8((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)
#define PROCESS_SB_R6432M_TABLE_SAVE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave32((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)
#define PROCESS_SB_IO_R6408M_TABLE_SAVE(tbl, len, PmioAddr) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaIoModifySave8((UINT16)((tbl)[tAbLeIdx].Address + PmioAddr), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)


#ifdef ZX_DUALSOCKET
#define PROCESS_SB_R6408M_TABLE_SAVE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave8(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_SB_R6432M_TABLE_SAVE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave32(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)
#endif

#endif
