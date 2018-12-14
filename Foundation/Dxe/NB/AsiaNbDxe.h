//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
/*
\license
*/
#ifndef __ASIA_NB_DXE_H_
#define __ASIA_NB_DXE_H_

#include "EfiCommon.h"
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include EFI_PROTOCOL_DEFINITION(AsiaNbProtocol)

extern EFI_HANDLE gImageHandle;   

EFI_STATUS GetAsiaNbCfgFromHob(
  OUT VOID** NbCfg
  );

EFI_STATUS AsiaNbDxePrePciInit (
  IN EFI_ASIA_NB_PROTOCOL *This
  );
  
EFI_STATUS AsiaNbDxePreprocessPciController (
  IN EFI_ASIA_NB_PROTOCOL *This,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
  IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
  );
  
EFI_STATUS AsiaNbDxePostPciInit (
  IN EFI_ASIA_NB_PROTOCOL *This,
  IN EFI_PCI_IO_PROTOCOL *PciIo
  );
  
EFI_STATUS AsiaNbDxePreBootInit (
  IN EFI_ASIA_NB_PROTOCOL *This
  );

#define ASIA_NB_REVISION AsiaPciRead8(ASIA_PCI_ADDRESS(0, 0, 4, 0xF6))

#define PROCESS_NB_R6408M_TABLE_SAVE(tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave8((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_R6432M_TABLE_SAVE(tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave32((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6408M_TABLE_SAVE(Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModifySave8(Addr,(tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

//DKS-20170725 add -s
#define PROCESS_NB_PCIE_R6416M_TABLE_SAVE(Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
	if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
	  continue; \
	AsiaPcieModifySave16(Addr,(tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

//DKS-20170725 add -e

#define PROCESS_NB_PCIE_R6432M_TABLE_SAVE(Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModifySave32(Addr,(tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)


#ifdef ZX_DUALSOCKET
#define PROCESS_NB_R6408M_TABLE_SAVE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave8(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_R6432M_TABLE_SAVE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModifySave32(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6408M_TABLE_SAVE_SLAVE(bus, Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModifySave8(Addr,((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6416M_TABLE_SAVE_SLAVE(bus, Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
	if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
	  continue; \
	AsiaPcieModifySave16(Addr,((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6432M_TABLE_SAVE_SLAVE(bus, Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModifySave32(Addr,((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#endif

#endif
