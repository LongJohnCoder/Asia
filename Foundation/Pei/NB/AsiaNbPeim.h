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
#ifndef __ASIA_NB_PEIM_H
#define __ASIA_NB_PEIM_H
#include "Pei.h"
#include "Ppi\AsiaNbPpi\AsiaNbPpi.h"

#define ASIA_NB_PEI_PRIVATE_DATA_SIGNATURE  EFI_SIGNATURE_32 ('N', 'V', 'I', 'S')
typedef struct __ASIA_NB_PEI_PRIVATE_DATA
{
    UINT32  Signature;
    /*internal parameter*/
    UINT16  DeviceID;
    UINT8   ChipsetVersion;
//    UINT8   FsbType; // 0-P4, 1-V4, 2-V4 Lite
//	#define FSB_TYPE_P6 0x01
//	#define FSB_TYPE_V4 0x02
//	#define FSB_TYPE_V4_LITE 0x03
//    UINT16  FsbFrequency; // MHz
//    BOOLEAN MaxFsb1066MHz; // False: 800MHz
//    BOOLEAN Notebook; // False: Desktop
    /*PPI*/
    EFI_ASIA_NB_PPI AsiaNbPpi;
    EFI_PEI_PPI_DESCRIPTOR PpiDesc[2];
} ASIA_NB_PEI_PRIVATE_DATA;

#define GET_PRIVATE_DATA_FROM_ASIANBPPI(a) PEI_CR(a, ASIA_NB_PEI_PRIVATE_DATA, AsiaNbPpi, ASIA_NB_PEI_PRIVATE_DATA_SIGNATURE)

/*init internal data*/
EFI_STATUS InitNbPrivateData(
    IN EFI_PEI_SERVICES **PeiServices,
    OUT ASIA_NB_PEI_PRIVATE_DATA *PrivateData
);

/*Interface function*/
// Instance of AsiaNbPpi->PreMemoryInit()
EFI_STATUS
PeiNbPreMemoryInit (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_NB_PPI *This
  );
// Instance of AsiaNbPpi->PostMemoryInit()
EFI_STATUS
PeiNbPostMemoryInit (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_NB_PPI *This
  );
// Instance of AsiaNbPpi->PostMemoryInitS3()
EFI_STATUS
PeiNbPostMemoryInitS3 (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_NB_PPI *This
  );

#define EFI_ASIA_NB_LIB_PPI_GUID \
{ \
  0x2d263955, 0xf453, 0x441a, 0xb5, 0x29, 0x4a, 0x1c, 0xad, 0x4d, 0xf, 0xb \
}

#define ASIA_NB_REVISION AsiaPciRead8(ASIA_PCI_ADDRESS(0, 0, 4, 0xF6))

#define PROCESS_NB_R6408M_TABLE(tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify8((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_R6432M_TABLE(tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6408M_TABLE(Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModify8(Addr,(tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

//DKS-20170515 add -s
#define PROCESS_NB_PCIE_R6416M_TABLE(Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModify16(Addr,(tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)
//DKS-20170515 add -e

#define PROCESS_NB_PCIE_R6432M_TABLE(Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModify32(Addr,(tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)


#ifdef ZX_DUALSOCKET
#define PROCESS_NB_R6408M_TABLE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify8(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_R6432M_TABLE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6408M_TABLE_SLAVE(bus, Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModify8(Addr,((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6416M_TABLE_SLAVE(bus, Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModify16(Addr,((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(bus, Addr, tbl, len) \
do{ \
  UINT8 nBrEvIsion = (ASIA_NB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((nBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPcieModify32(Addr,((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#endif

#endif