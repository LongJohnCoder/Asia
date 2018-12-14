/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoePreInit.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#ifndef __IOE_PRE_INIT__
#define __IOE_PRE_INIT__

#include "CND003Reg.h"
#include "IoeConfig.h"


// If define ASSIGN_DEBUG_EN, temp assignment related debug messages
// will dumped.  [#ifdef]
#define  ASSIGN_DEBUG_EN  1   

#define  IOE_PRE_INIT_LOCATION IOE_ASIA_PEI_NB
	#define IOE_ASIA_PEI_SB 0
	#define IOE_ASIA_PEI_NB 1









/*
        [MB]
-----------------------
  |    |    |(RP)   |
          ------------------------(Busx)
            |(D0F0)
   -------------------------------(Busx+1)
        |(D1_D7F0)      |(D8F0)
	                --------------(Busx+2)
                         |(PCIEIF)
                       -----------(Busx+3)
                       #(PCIE ISB)                   
*/



////80 port value
//0x79  IOE autofill fw delay to wait fw excute(not necessory) - Not in Visa
//0x80  IOE wait autofill done - Not in Visa
//0x81 82 83 84  Check IoeFw runing status(not necessory) - Not in Visa
//0xC0  SbInit.c to wait MCU patchdone in SPI mode
//0x37 Not found IOE NbPcie.c

//#define WAIT_MCU_PATCHDONE		0xC0
//#define NOT_FOUND_IOE_POST		0x37
//#define WAIT_LINK_UP_AFTER_LANE_REVERSAL 0x38
//#define WAIT_L0 0x23
#define SMBUS_CHIPVERSION_ERROR_1	0xAB
#define SMBUS_CHIPVERSION_ERROR_2	0xBA

#define PHYLS_State_L0 0x8A


/************************************/

// Those macors was not necessory 
// for normal functions


#define IOE_DO_EQ  				2
#define IOE_SKIP_EQ_MANUAL 		1
#define IOE_SKIP_EQ_TABLE 		0



//For NbConfig->Cnd003ModeSel 
//#define MODE_SEL_BIOS	0
//#define MODE_SEL_SPI	1


//CJW: I prefer to use  strategy B, 
//     it use less time to assign the bus number
#define ASSIGN_STRATEGY_A	1	//auto assign
//#define ASSIGN_STRATEGY_B	1	//simple assign directly


/**********************************/
//Those code sync with IOE_MCU


//#define BUSXP3_MMIO_BASE	0xFE018000 //not used - 
//#define BUSXP3_IO_BASE		0xF000		//not used 

#define PROCESS_TEMP_BUS_ASSIGNMENT(tbl,len) \
do{\
	UINT8 TblIndex;\
	for(TblIndex = 0; TblIndex < (len); TblIndex++){\
		AsiaPciWrite8(AsiaPciAddress((tbl)[TblIndex].BusNum,(tbl)[TblIndex].DevNum, (tbl)[TblIndex].FunNum,(tbl)[TblIndex].RegOff), (tbl)[TblIndex].Value);\
	}\
}while(0)

#define CLEAR_TEMP_BUS_ASSIGNMENT(tbl,len) \
do{\
	INT8 TblIndex;\
	for(TblIndex = (len-1); TblIndex >= 0; TblIndex--){	\
		AsiaPciWrite8(AsiaPciAddress((tbl)[TblIndex].BusNum,(tbl)[TblIndex].DevNum, (tbl)[TblIndex].FunNum,(tbl)[TblIndex].RegOff), 0);\
	}\
}while(0)


typedef struct TempAssign{
	UINT8 BusNum;
	UINT8 DevNum;
	UINT8 FunNum;
	UINT8 RegOff;
	UINT8 Value;
}TAS_TBL;



#define SET_1BYTE 0
#define SET_4BYTE 1
typedef struct RegisterSetting{
	UINT8 ByteCount;
	UINT8 Busx;
	UINT8 Devx;
	UINT8 Funx;
	UINT16 Offsetx;
	UINT32 Maskx;
	UINT32 Valuex;
} RegSet;


/**********************************/


//Those variable was used for clear the temp BusNumber assigment
//since the IOE's PCIE DownStream Port could inserted PCIE card,
//So we need to record the BusNumber of BusX & BusX+2
/*extern UINT8 BusNumberOfBusX;
extern UINT8 BUSNumberOfBusXp2;
extern UINT8 IoeSubBusNumber;
extern UINT8 IoeConnectDevNum; 
extern UINT8 IoeConnectFunNum;
*/

//#define IOEBUSXUSP_VIDDID 0x66131002
//#define IOEBUSXP2_VIDDID  0x66131002
#define IOEBUSXUSP_VIDDID 0x071F1106
#define IOEBUSXP2_VIDDID  0x07211106
#define IOEBUSXUSP_VIDDID_ZX 0x071F1D17
#define IOEBUSXP2_VIDDID_ZX  0x07211D17
#define IOEBUSXUSP_VIDDID_ZERO 0x071F0000   //Before ISB2PE_CMBPHY_DONE in BIOS mode, the default VID = 0
#define IOE_PCIEIF_VIDDID  0x07221106
#define IOE_PCIEIF_VIDDID_ZX  0x07221D17
#define IOE_PCIEIF_VIDDID_ZERO  0x07220000


#define IOE_VID_VIA	0x1106
#define IOE_VID_ZX	0x1D17
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


#define IoeExist() 	((BIT0 & AsiaPciRead8(AsiaPciAddress(0, 0, 6, 0x47)))?1:0)

/**********************************/
/*#define GPO_Reset_PEG0 GPIO_12
#define GPO_Reset_PE0 GPIO_26
#define GPO_Reset_PE1 GPIO_36
#define GPO_Reset_PE2 GPIO_13
#define GPO_Reset_PE3 GPIO_27
#define GPO_Reset_PEG1 GPIO_14*/








typedef struct PcieRpFlag{
	UINT8 BusNum;
	UINT8 DevNum;
	UINT8 FunNum;
}SEARCH_TBL;





#if MULTI_IOE_SUPPORT

STATIC UINT8 
IoeGetPortFlagBit(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun);

STATIC BOOLEAN
IoeIsUsablePort(
		IN EFI_PEI_SERVICES **PeiServices,
		UINT8 Bus, UINT8 Dev, UINT8 Fun);

STATIC VOID
IoeMaskSearchPort(
		IN EFI_PEI_SERVICES **PeiServices,
		UINT8 Bus, 
		UINT8 Dev, 
		UINT8 Fun);

STATIC VOID
IoeUnmaskSearchPort(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun);

VOID 
IoeUnmaskAllPort(VOID);

EFI_STATUS
IoeMaskInitializedPort(
	IN EFI_PEI_SERVICES **PeiServices);

#endif






VOID
IoePciePtnVerify(
	IN EFI_PEI_SERVICES **PeiServices
);





EFI_STATUS
IoePeiNbInit(
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_NB_CONFIGURATION *NbConfig);



#if IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_SB
EFI_STATUS
IoePeiSbPreInit(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_SB_CONFIGURATION *SbCfg);

#elif IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_NB
EFI_STATUS
IoePeiNbPreInit(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg);

#endif


EFI_STATUS
IoePeiTempAssignment(
	IN EFI_PEI_SERVICES **PeiServices);

VOID
IoePeiClearTempAssignment(
	IN EFI_PEI_SERVICES **PeiServices);

VOID
DebugDumpCfgSpace(
	IN EFI_PEI_SERVICES **PeiServices);


EFI_STATUS
IoeSmbusPreInit(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig
);

EFI_STATUS
IoePatchPeiNb(	
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg);

EFI_STATUS
PciePatchforIOE(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg,
	IN UINT64 BDFno);

EFI_STATUS
PciePatchforIoeAfterLinkup(	
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg);


UINT8 
IoeGetRpToFindIoe_GetDev(IN EFI_PEI_SERVICES **PeiServices);

UINT8 
IoeGetRpToFindIoe_GetFun(IN EFI_PEI_SERVICES **PeiServices);


#define ASIA_IOE_REVISION AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_INTERNAL_REV_ID))


#define IOE_PROCESS_SB_R6408M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_IOE_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify8((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)

#define IOE_PROCESS_SB_R6416M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_IOE_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify16((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)



#define IOE_PROCESS_SB_R64326408M_TABLE(tbl, len) \
        do{ \
          UINT8 sBrEvIsion = (ASIA_IOE_REVISION);\
          UINT32 tAbLeIdx; \
          for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
          { \
            if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
              continue; \
            AsiaPciModify32((tbl)[tAbLeIdx].idx_Address, (tbl)[tAbLeIdx].idx_Mask, (tbl)[tAbLeIdx].idx_Value); \
            AsiaPciModify8((tbl)[tAbLeIdx].data_Address, (tbl)[tAbLeIdx].data_Mask, (tbl)[tAbLeIdx].data_Value); \
          } \
        } while(0)


#define IOE_PROCESS_SB_R6432M_TABLE(tbl, len) \
do{ \
  UINT8 sBrEvIsion = (ASIA_IOE_REVISION);\
  UINT32 tAbLeIdx; \
  for(tAbLeIdx = 0; tAbLeIdx < (len); tAbLeIdx++) \
  { \
    if((sBrEvIsion) > (tbl)[tAbLeIdx].RevisionMax || (sBrEvIsion) < (tbl)[tAbLeIdx].RevisionMin) \
      continue; \
    AsiaPciModify32((tbl)[tAbLeIdx].Address, (tbl)[tAbLeIdx].Mask, (tbl)[tAbLeIdx].Value); \
  } \
} while(0)
	
#endif
