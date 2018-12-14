//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef __ASIA_SB_PEIM_H 
#define __ASIA_SB_PEIM_H
#include "Pei.h"
#include "Ppi\AsiaSbPpi\AsiaSbPpi.h"

#define ASIA_SB_PEI_PRIVATE_DATA_SIGNATURE  EFI_SIGNATURE_32 ('S', 'V', 'I', 'S')
typedef struct __ASIA_SB_PEI_PRIVATE_DATA{
    UINT32  Signature;
	/*internal parameter*/
	UINT16  DeviceID;
	UINT8   ChipsetVersion;  
	/*PPI*/
	EFI_ASIA_SB_PPI AsiaSbPpi;
	EFI_PEI_PPI_DESCRIPTOR PpiDesc[2];
}ASIA_SB_PEI_PRIVATE_DATA;

#define GET_PRIVATE_DATA_FROM_ASIASBPPI(a) PEI_CR(a, ASIA_SB_PEI_PRIVATE_DATA, AsiaSbPpi, ASIA_SB_PEI_PRIVATE_DATA_SIGNATURE)

EFI_STATUS InitSbPrivateData(
    IN EFI_PEI_SERVICES **PeiServices,
    OUT ASIA_SB_PEI_PRIVATE_DATA *PrivateData
);

EFI_STATUS
PeiSbPreMemoryInit (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_SB_PPI *This
//  IN VOID *Configuration
  );

EFI_STATUS
PeiSbPostMemoryInitS3 (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_SB_PPI *This
//  IN VOID *Configuration
  );

EFI_STATUS
PeiSbPostMemoryInit (
  IN EFI_PEI_SERVICES **PeiServices,
  IN EFI_ASIA_SB_PPI *This
//  IN VOID *Configuration
  );

#define EFI_ASIA_SB_LIB_PPI_GUID \
{ \
  0x7fb485c5, 0x4c5, 0x4fce, 0xa7, 0xd2, 0x10, 0x1a, 0x7d, 0x1c, 0x2d, 0xa6 \
}
/*Ppi struct define in Porting\Pei\$(SBTYPE)\SbLibPpi.h file*/
#define ASIA_SB_REVISION AsiaPciRead8(ASIA_PCI_ADDRESS(0, 0, 4, 0xF6))

#define PROCESS_SB_R6408M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify8((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_SB_R6416M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify16((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)


#define BIT(x) (1<<(x))
#define PROCESS_SB_R64326408M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32((tbl)[tAbLeIdx].idx_Address, (tbl)[tAbLeIdx].idx_Mask, (tbl)[tAbLeIdx].idx_Value); \
    AsiaPciModify8((tbl)[tAbLeIdx].data_Address, (tbl)[tAbLeIdx].data_Mask, (tbl)[tAbLeIdx].data_Value); \
  } \
} while(0)

#define PROCESS_SB_R64326408M_TABLE_IOE(tbl, len) \
        do{ \
          UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
          UINT32 tAbLeIdx; \
          for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
          { \
            if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
              continue; \
            AsiaPciModify32((tbl)[tAbLeIdx].idx_Address, (tbl)[tAbLeIdx].idx_Mask, (tbl)[tAbLeIdx].idx_Value); \
            AsiaPciModify8((tbl)[tAbLeIdx].data_Address, (tbl)[tAbLeIdx].data_Mask, (tbl)[tAbLeIdx].data_Value); \
          } \
        } while(0)


#define PROCESS_SB_R6432M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)


#ifdef ZX_DUALSOCKET
#define PROCESS_SB_R6408M_TABLE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify8(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_SB_R6416M_TABLE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify16(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define PROCESS_SB_R64326408M_TABLE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  UINT8 val;\
  UINT8 shiftbit;\
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32(((((tbl)[tAbLeIdx].idx_Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].idx_Mask, (tbl)[tAbLeIdx].idx_Value); \
    val=(tbl)[tAbLeIdx].data_Mask;\
    for (shiftbit=0;shiftbit<8;shiftbit++)\
    {\
        if (val & BIT(shiftbit)) \
          break;\
    }\
    AsiaPciModify8(((((tbl)[tAbLeIdx].data_Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].data_Mask, (tbl)[tAbLeIdx].data_Value << shiftbit); \
  } \
} while(0)

#define PROCESS_SB_R64326408M_TABLE_IOE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32(((((tbl)[tAbLeIdx].idx_Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].idx_Mask, (tbl)[tAbLeIdx].idx_Value); \
    AsiaPciModify8(((((tbl)[tAbLeIdx].data_Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].data_Mask, (tbl)[tAbLeIdx].data_Value); \
  } \
} while(0)

#define PROCESS_SB_R6432M_TABLE_SLAVE(bus, tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_SB_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32(((((tbl)[tAbLeIdx].Address)&(~((UINT64)0xFF000000)))+(ASIA_PCI_ADDRESS(bus,0,0,0))), (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#endif

#endif
