/*******************************************************************************
Copyright(C) 2018 Shanghai Zhaoxin Technologies, Inc. All Rights Reserved.

Information in this file is the intellectual property of Shanghai Zhaoxin Technologies, Inc.,
and may contains trade secrets that must be stored and viewed confidentially.

\file AsiaDramCfg.h
\brief ASIA Dram Configuration Structure definition for CHX002.
\date 2018-05-07

Modification History:
    
*******************************************************************************/

#ifndef CHX002_ASIA_DRAM_CFG_H
#define CHX002_ASIA_DRAM_CFG_H

/////
typedef struct _ASIA_DRAM_CONFIGURATION {
    UINT32 Signature;
        #define ASIA_DRAM_CONFIGURATION_SIGNATURE EFI_SIGNATURE_32('D','C','F','G')
    UINT8 DramClk;
        #define DRAM_CLK_BY_SPD 0
		#define DRAM_CLK_400MHZ 4
		#define DRAM_CLK_466MHZ  5
		#define DRAM_CLK_533MHZ 6
		#define DRAM_CLK_600MHZ 7
		#define DRAM_CLK_666MHZ  8
 		#define DRAM_CLK_733MHZ  9
		#define DRAM_CLK_800MHZ  0x0A
		#define DRAM_CLK_866MHZ  0x0B
		#define DRAM_CLK_933MHZ  0X0C
		#define DRAM_CLK_1000MHZ 0X0D
		#define DRAM_CLK_1066MHZ 0X0E 
		#define DRAM_CLK_1133MHZ 0X0F
		#define DRAM_CLK_1200MHZ 0X10
		#define DRAM_CLK_1333MHZ 0X11    //DKS-20170515 add
		#define DRAM_CLK_1466MHZ 0X13
		#define DRAM_CLK_1600MHZ 0X14    //DKS-20170515 add
	UINT8 ACTimingOption;
		#define ACTIMING_AUTO 0
		#define ACTIMING_MANUAL 1
	UINT8	DramVoltageControl;//IVES-20180517 Add dram voltage control.
	UINT8 DramCL;
		#define CL_AUTO 0
	UINT8 DramTrcd;
		#define TRCD_AUTO 0
	UINT8 DramTrp;
		#define TRP_AUTO 0
	UINT8 DramTras;
		#define TRAS_AUTO 0
    UINT8 RxIoTimingMethod;
        #define RX_SI_SI       0
        #define RX_RLVL_SI     1
        #define RX_SI_RLVL     2
        #define RX_RLVL_RLVL   3
        #define RX_3D_SCAN     4
		#define RX_DQSI_READPREAMBLE	   5
    UINT8 DQSIByRank;
			#define BYRANK_AUTO       0	
		    #define BYRANK_DISABLE    1
		    #define BYRANK_ENABLE	  2        
    UINT8 TxIoTimingMethod;
		#define TX_SI_SI       0
        #define TX_WLVL_LCU       1
        #define TX_LCU_LCU       2
		#define TX_HARDCODEWLVL_LCU 3
	UINT8 LimitRankSize;
		#define LIMIT_SIZE_AUTO    0
		#define LIMIT_SIZE_128M    1
		#define LIMIT_SIZE_256M    2
		#define LIMIT_SIZE_512M    3
		#define LIMIT_SIZE_1024M   4	
    UINT8 BankIntlv;
        #define BANK_INTERLEAVE_SPD 0
        #define BANK_INTERLEAVE_NONPAGE 1
        #define BANK_INTERLEAVE_2PAGES 2
        #define BANK_INTERLEAVE_4PAGES 3
        #define BANK_INTERLEAVE_8PAGES 4
    UINT8 MemoryChipODTDebug;
        #define MEM_CHIP_ODT_DBG_AUTO 0
        #define MEM_CHIP_ODT_DBG_DISABLE 1
		#define MEM_CHIP_ODT_DBG_20OHM 2
		#define MEM_CHIP_ODT_DBG_30OHM 3
		#define MEM_CHIP_ODT_DBG_34OHM 4
		#define MEM_CHIP_ODT_DBG_40OHM 5
		#define MEM_CHIP_ODT_DBG_48OHM 6
        #define MEM_CHIP_ODT_DBG_60OHM 7
		#define MEM_CHIP_ODT_DBG_80OHM 8
        #define MEM_CHIP_ODT_DBG_120OHM 9       
        #define MEM_CHIP_ODT_DBG_240OHM 0x0A       
    UINT8 MemoryChipODTWRDebug;
	UINT8 MemoryChipODTParkDebug;
    UINT8 VRIntlv;
        #define VRANK_INTERLEAVE_AUTO 0
        #define VRANK_INTERLEAVE_DISABLED 1
    //UINT8 ChannelIntlv;		
	//	#define CHAN_INTERLEAVE_AUTO 0
	//	#define CHAN_INTERLEAVE_DISABLED 1
	UINT8 BASelect;
		#define SELECT_A16 0
		#define SELECT_A18 1
	BOOLEAN DataScmb;	
    UINT8 RDRDY;
        #define RDRDY_SLOWEST 0
        #define RDRDY_DEFAULT 1
    UINT8 ConversionCircuit;
        #define CONVERSION_CIRCUIT_AUTO 0
        #define CONVERSION_CIRCUIT_ASYNC 1
    UINT8 BurstLength;
        #define BURST_LENGTH_8B 0
        #define BURST_LENGTH_ON_THE_FLY 1
    UINT8 CmdRate;
        #define CMD_RATE_2T 0
        #define CMD_RATE_1T 1
    UINT8 VGAShareMemory;
        #define VGA_SHARE_MEM_64M 1
        #define VGA_SHARE_MEM_128M 2
        #define VGA_SHARE_MEM_256M 3
        #define VGA_SHARE_MEM_512M 4
		#define VGA_SHARE_MEM_AUTO 5
        //#define VGA_SHARE_MEM_1024M 5
    UINT8 DramInitMethod;
        #define DRAM_INIT_METHOD_AUTO 0
        #define DRAM_INIT_METHOD_FORCE_SW 1
    BOOLEAN DramSelfRefresh;
    BOOLEAN DynamicCKE;
    BOOLEAN RemapEn;
	UINT16  PCIMemoryStart;   //unit of MB
	BOOLEAN SwapByte78;
	BOOLEAN SwapChAB;
	BOOLEAN ScanIOTiming;
	BOOLEAN DRAMECC;
	BOOLEAN ECCClearMemory;
	BOOLEAN EccPatrolScrub;
	BOOLEAN EccRetry;
	UINT8 DRAMErrControl;
		#define ECC_DISABLE    0
		#define ECC_UNCORRECTABLE    1
		#define ECC_CORRECTABLE    2
		#define ECC_BOTH   3	
	BOOLEAN CRCEn;   //CRC Enable
	UINT8 CRCErrControl;
	    #define CRC_DISABLE    0
		#define CRC_ENABLE    1
	BOOLEAN CAParEn;  //CA Parity check Enable
	BOOLEAN CAParPerEn; //CA Parity persistent Enable
	UINT8 ParErrControl;
	    #define PAR_DISABLE    0
		#define PAR_ENABLE    1
	BOOLEAN CRCParRetryEn;
	UINT8 WPREA;  //Write preamble
	    #define WPREA1CLK 0
		#define WPREA2CLK 1
	UINT8 RPREA;  //read preamble
	    #define RPREA1CLK 0
		#define RPREA2CLK 1
	BOOLEAN CALEn; //CAL Latency enable
	//BOOLEAN CPU_FSBC_ON; //FSBC Debug Mode
	UINT8 DramFastBoot;
	    #define DRAM_FAST_BOOT_AUTO 0
		#define DRAM_FAST_BOOT_DISABLE 1
	UINT8 DramRxTxTimingHardCode;
	    #define DRAM_RXTX_TIMING_HARDCODE_AUTO 0
		#define DRAM_RXTX_TIMING_HARDCODE_DISABLE 1
	UINT8 CHdecode;                       //DKS -20161212 add
		#define DRAM_CH_DECODE_AUTO  0
		#define DRAM_CH_DECODE_A8_A9 1
		#define DRAM_CH_DECODE_A8_A9_A12_A13_A18_A19 2
	UINT8 BankGroupBit0Decode;
		#define BG_DECODE_A7_A14  0
		#define BG_DECODE_A6_A14 1
	UINT16 TxVref;
		#define TX_VREF_SI    0
		#define TX_VREF_CAL     1        //DKS -20161212 add   DKS -20161221 modify
		#define TX_VREF_502_PER 502
		#define TX_VREF_515_PER 515
		#define TX_VREF_528_PER 528
		#define TX_VREF_541_PER 541
		#define TX_VREF_554_PER 554
		#define TX_VREF_567_PER 567
		#define TX_VREF_580_PER 580
		#define TX_VREF_593_PER 593
		#define TX_VREF_600_PER 600
		#define TX_VREF_613_PER 613
		#define TX_VREF_626_PER 626
		#define TX_VREF_639_PER 639
		#define TX_VREF_652_PER 652
		#define TX_VREF_665_PER 665
		#define TX_VREF_678_PER 678
		#define TX_VREF_691_PER 691
		#define TX_VREF_704_PER 704
		#define TX_VREF_717_PER 717
		#define TX_VREF_730_PER 730
		#define TX_VREF_743_PER 743
		#define TX_VREF_756_PER 756
		#define TX_VREF_769_PER 769
		#define TX_VREF_782_PER 782
		#define TX_VREF_795_PER 795
		#define TX_VREF_808_PER 808
		#define TX_VREF_821_PER 821
		#define TX_VREF_834_PER 834
		#define TX_VREF_847_PER 847
		#define TX_VREF_860_PER 860
	UINT8 TxVrefAllByte;
		#define TX_VREFALLBYTE_AUTO    1
		#define TX_VREFALLBYTE_DISABLE 0
	UINT8 RxVref;
		#define RX_VREF_SI     0
		#define RX_VREF_CAL_BY_RANK    1
		#define RX_VREF_CAL_BY_CHANNEL    2
      UINT8  RRankRDelay;
		#define RRankRDLY_DEFAULT 0
      UINT8  RRankWDelay;
		#define RRankWDLY_DEFAULT 0
//daisy add 
	UINT8  TNIHighPulse;
		#define High_Pulse        1
		#define Low_Pulse         0
	UINT8  DDRComp;
		#define DDRCOMP_ENABLE		  1
		#define DDRCOMP_DISABLE      0	
	UINT8  Dram_Console;
		#define CONSOLE_ENABLE		  1
		#define CONSOLE_DISABLE      0	
	UINT8  Perf_Turnaround;
		#define PERF_TURNAROUND_ENABLE		  1
		#define PERF_TURN_AROUND_DISABLE      0	

      UINT8 ZxeDualSocket;	
	BOOLEAN MemoryTemperatureDetect;		
	BOOLEAN CriticalTemperatureEvent;
	UINT16  CriticalTemperatureValue;
	UINT8 	DramReduceRate;				
	BOOLEAN CriticalDDRIOTemperatureEvent;
		#define DDRIO_Event_AUTO    1
		#define DDRIO_Event_DISABLE 0
	UINT16  CriticalDDRIOTemperatureValue;
	UINT8 	DramDDRIOReduceRate;				
	UINT8   Above4GEnable;
	UINT8   Above4GLocation;
} ASIA_DRAM_CONFIGURATION;

/////
#define ASIA_MAX_Channels	2
#define ASIA_MAX_SOCKETS	4
#define ASIA_MAX_DIMMS	ASIA_MAX_SOCKETS
#define ASIA_MAX_RANKS		(ASIA_MAX_SOCKETS * 2)
#define ASIA_MAX_BYTES     9
#define ASIA_MAX_BIT       8
#define SPD_SIZE 512
/////

typedef struct{
	BOOLEAN  SpdPresent;
	UINT8    Buffer[SPD_SIZE];
} ASIA_SPD_DATA;

typedef struct {
	UINT8  BankGroupNumber;
	UINT8  BankNumber;
	UINT8  RowNumber;
	UINT8  ColNumber;
	UINT16 RankSize; //unit of M
	
} ASIA_RANK_INFO;

typedef struct _ASIA_DRAM_INFO{
	UINT8  RankMap;
	ASIA_SPD_DATA Spd[ASIA_MAX_SOCKETS];
	UINT16  FakeBegin;   //unit of M
	UINT16  FakeLength;  //unit of M
	ASIA_RANK_INFO  RankInfo[ASIA_MAX_RANKS];

	UINT16  DramFreq;   //unit of MHZ
	UINT16  PciStartAddress;    //unit of MB
	UINT16  UMASize;     //unit of M
	UINT16  SmmTSegSize;   //unit of M
#ifdef ZX_TXT_SUPPORT
	UINT16  DPRSize;
#endif

	UINT8   DramCL;
    UINT8   DramTrcd;
    UINT8   DramTrp;
    UINT8   DramTras;
    UINT32  EfuseData[2];
} ASIA_DRAM_INFO;

/////
#endif

