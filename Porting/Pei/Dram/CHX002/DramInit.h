//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

//----------------------------------------------------------------------------
//Ver	Date			Name	Note
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef __DRAMINIT_H_
#define __DRAMINIT_H_

#include "Pei.h"
#include "PeiDebug.h"
#include EFI_PPI_CONSUMER(Smbus)
#include EFI_PPI_CONSUMER(CpuIo)
#include EFI_PPI_CONSUMER(PciCfg)
#include EFI_PPI_CONSUMER(ReadOnlyVariable2)
#include EFI_PPI_CONSUMER(ReadOnlyVariable)

   
#include "Ppi\AsiaDramPPi\AsiaDramPpi.h"
#include "AsiaDramPeim.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaIoLib.h"
#include "Ppi\AsiaNbPpi\AsiaNbPpi.h"	
#include "VirtualSPD.h"

#define DRAMATTR_NUM 1
#define ASIA_NB_REVISION AsiaPciRead8(ASIA_PCI_ADDRESS(0, 0, 4, 0xF6))

//Only use for bring up 
//#define DDR4_800 1
//#define RXVREF_DDR3MODE 1




#define CHANNELA 0
#define CHANNELB 1

#define POS 1
#define NEG 0

#define IO_POS	  1
#define IO_NEG	  0
#define IO_IGNORE 0

//Dram Freq
#define DIMMFREQ_800	400
#define DIMMFREQ_667	333
#define DIMMFREQ_533	266
#define DIMMFREQ_400	200
#define DIMMFREQ_333	166
#define DIMMFREQ_266	133
#define DIMMFREQ_200	100

#define F_200 		0	// 200 MHz
#define F_266 		1 	// 266 MHz
#define F_333 		2 	// 333 MHz
#define F_400 		3 	// 400 MHz
#define F_533 		4 	// 533 MHz
#define F_667 		5 	// 667 MHz
#define F_800 		6 	// 800 MHz
#define F_SPD 		7   // refer to SPD

//Dram Type
#define  RAMTYPE_FPMDRAM   1
#define  RAMTYPE_EDO       2
#define  RAMTYPE_PipelinedNibble 3
#define  RAMTYPE_SDRAM     4
#define  RAMTYPE_ROM       5
#define  RAMTYPE_SGRAMDDR  6
#define  RAMTYPE_SDRAMDDR  7
#define  RAMTYPE_SDRAMDDR2 8
#define  RAMTYPE_SDRAMDDR3 11
#define  RAMTYPE_SDRAMDDR4 12

//Module Type 02: UDIMM, 03: SO-DIMM. 
#define RDIMM_MODULE  (1)
#define UDIMM_MODULE  (2) 
#define SODIMM_MODULE (3)


/* CAS latency constant */
#define CASLAN_2           20
#define CASLAN_3           30
#define CASLAN_4           40
#define CASLAN_5           50
#define CASLAN_NULL        00

#define MAA_BITMAP		0x0F
#define MAB_BITMAP		0xF0
#define CHA_BITMAP		MAA_BITMAP
#define CHB_BITMAP		MAB_BITMAP
#define ALL_BITMAP		CHA_BITMAP + CHB_BITMAP
#define ALL_EVEN		((ALL_BITMAP) & 0x55)
#define CHA_EVEN_BANK	( CHA_BITMAP & 0x55 )
#define CHB_EVEN_BANK	( CHB_BITMAP & 0x55 )

#define SPD_MEMORY_TYPE              2   /*Memory type FPM,EDO,SDRAM,DDR,DDR2, DDR3*/





//DDR4 SPD offset
#define DDR4_SPD_MODULE_TYPE                   3
#define DDR4_SPD_DENSITY_BANKS            4
#define DDR4_SPD_ADDRESSING               5
#define DDR4_SPD_PACKAGE_TYPE             6
#define DDR4_SPD_NOMINAL_VOLTAGE          11
#define DDR4_SPD_MODULE_ORG               12
#define DDR4_SPD_BUS_WIDTH                13
#define DDR4_SPD_TIMEBASE                 17

#define DDR4_SPD_MIN_CYCLE_TIME           18
#define DDR4_SPD_MAX_CYCLE_TIME           19
#define DDR4_SPD_SUPPORTED_CL_FIRST_BYTE  20
#define DDR4_SPD_SUPPORTED_CL_SECOND_BYTE 21
#define DDR4_SPD_SUPPORTED_CL_THIRD_BYTE  22
#define DDR4_SPD_SUPPORTED_CL_FOURTH_BYTE 23

#define DDR4_SPD_MIN_CL_TIME              24

#define DDR4_SPD_MIN_TRCD                 25
#define DDR4_SPD_MIN_TRRD_SHORT           38
#define DDR4_SPD_MIN_TRRD_LONG            39
#define DDR4_SPD_MIN_TCCD_LONG            40

#define DDR4_SPD_MIN_TRP	              26
#define DDR4_SPD_UPPER_NIBBLE_TRAS_TRC    27
#define DDR4_SPD_MIN_TRAS_LSB             28
#define DDR4_SPD_MIN_TRC_LSB              29
#define DDR4_SPD_MIN_TRFC1_LSB            30
#define DDR4_SPD_MIN_TRFC1_MSB            31
#define DDR4_SPD_MIN_TRFC2_LSB            32
#define DDR4_SPD_MIN_TRFC2_MSB            33
#define DDR4_SPD_MIN_TRFC3_LSB            34
#define DDR4_SPD_MIN_TRFC3_MSB            35


#define DDR4_SPD_UPPER_NIBBLE_TFAW        36
#define DDR4_SPD_MIN_TFAW                 37
#define DDR4_SPD_OPTIONAL_FEATURE         7
#define DDR4_SPD_OPTIONAL_OTHER_FEATURE   9


#define DDR4_SPD_DQ_NIBBLE_MAP0            60 
#define DDR4_SPD_DQ_NIBBLE_MAP32           70
#define DDR4_SPD_DQ_NIBBLE_MAPCB0          68
#define DDR4_SPD_DQ_NIBBLE_MAPCB4          69

#define DDR4_SPD_TCCD_LONG_FINE_OFFSET     117
#define DDR4_SPD_TRRD_LONG_FINE_OFFSET     118
#define DDR4_SPD_TRRD_SHORT_FINE_OFFSET    119
#define DDR4_SPD_TRC_FINE_OFFSET           120 
#define DDR4_SPD_TRP_FINE_OFFSET           121
#define DDR4_SPD_TRCD_FINE_OFFSET              122  
#define DDR4_SPD_CL_FINE_OFFSET               123
#define DDR4_SPD_MIN_CYCLE_TIME_FINE_OFFSET              125
#define DDR4_SPD_MAX_CYCLE_TIME_FINE_OFFSET              124



#define DDR4_SPD_THERMAL_REFRESH          8
#define DDR4_SPD_THERMAL_SENSOR           14

#define DDR4_SPD_REFERENCE_RAW_CARD  130
#define DDR4_UDIMM_SPD_RANK1_ADDRMAPPING  131
#define DDR4_RDIMM_SPD_RANK1_ADDRMAPPING  136
#define DDR4_RDIMM_SPD_RCD_CA_DRIVE           137
#define DDR4_RDIMM_SPD_RCD_CLK_DRIVE          138


#define DDR4_DPD_MODULE_MANUFACTURING_ID_LSB        320
#define DDR4_DPD_MODULE_MANUFACTURING_ID_MSB        321 
#define DDR4_SPD_MODULE_MANUFACTURING_YEAR    		323 
#define DDR4_SPD_MODULE_MANUFACTURING_WEEK		    324 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE00			325
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE01			326 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE02			327 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE03			328 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE04			329
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE05			330 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE06			331 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE07			332
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE08			333
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE09			334 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE0A			335 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE0B			336
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE0C			337
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE0D			338 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE0E			339 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE0F			340
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE10			341
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE11			342 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE12			343 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE13			344 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE14			345
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE15			346 
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE16			347
#define DDR4_SPD_MODULE_SERIAL_NUMBER_BYTE17			348










#define ROW_COLUMN_PATTERN		0x012345678		

#define	TEST_PATTERN6			0x80008000
#define	TEST_PATTERN7			0x7FFF7FFF
#define	LINE_SIZE				0x40

#define RANK1_MAPPING_STANDARD 	0
#define RANK1_MAPPING_MIRRORED 	1

#define SINGLE_CHANNEL 			0x00
#define DUAL_CHANNEL 			0x01
                                
#define CMD_2T 					0x00
#define CMD_1T 					0x01
                                
#define DRAM_FREQ_800 	4	
#define DRAM_FREQ_1066	6
#define DRAM_FREQ_1333  8	
#define DRAM_FREQ_1600	10	
#define DRAM_FREQ_1866	12	
#define DRAM_FREQ_2133	14	
#define DRAM_FREQ_2400	16	
#define DRAM_FREQ_2666	18
#define DRAM_FREQ_2933  20           //2933 min clock time = 0.682ns
#define DRAM_FREQ_3200	22	
                                
#define DRAM_CYCLE_800 	    2500
#define DRAM_CYCLE_1066 	1875	
#define DRAM_CYCLE_1333 	1500	
#define DRAM_CYCLE_1600 	1250
#define DRAM_CYCLE_1866     1071
#define DRAM_CYCLE_2133     938
#define DRAM_CYCLE_2400     833
#define DRAM_CYCLE_2666     750 
#define DRAM_CYCLE_2933     682
#define DRAM_CYCLE_3200     625 
#define BL_ONTHEFLY			0x00
#define BL8 					0x01

#define NOT_REG_DIMM 		0x00
#define IS_REG_DIMM 		0x01

#define NO_ECC 				0x00
#define Support_ECC 		0x01

#define NO_ThermalSensor 				0x00
#define Support_ThermalSensor 			0x01

#define NOT_3DS             0x00
#define DRAM_3DS            0x01

#define FSB_SPEED_400  		0x01	
#define FSB_SPEED_533  		0x02
#define FSB_SPEED_667  		0x03
#define FSB_SPEED_800  		0x04
#define FSB_SPEED_1066 		0x05
#define FSB_SPEED_1333 		0x06

#define FIRST_SLOT			0x00
#define SECOND_SLOT		0x01






//---------------------------------------//
// 		 DDR4 MSR setting 				 //
//---------------------------------------//

//Typical MA mapping for a MRS command

//MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//                  23    22,   21,     20,    12,    11,    10,    9,    8,    7,       6,     5,      4,     3 

#define MA00 (3)
#define MA01 (4)
#define MA02 (5)
#define MA03 (6)
#define MA04 (7) 
#define MA05 (8)
#define MA06 (9)
#define MA07 (10)
#define MA08 (11)
#define MA09 (12)
#define MA10 (20)
#define MA11 (21)
#define MA12 (22)
#define MA13 (23)



// DDR4 MR0 (BG0=0  BA1=0, BA0=0)
// MA[17]	-  0
// MA[13:12]  - 0
// MA[11:9]	- TWR and RTP
// MA[8]		- DLL Reset
// MA[7]		- Mode
// MA[3]		- Read Burst Type
// MA[6:4,2]  - CAS LAtency
// MA[1:0]  	- BL 
//

#define DDR4_MR0_INIT    0x00
//                                                             BG0              BA1            BA0                   
//#define DDR4_MR0                     (0 << 6) + (0 << 16) +(0 << 15)


//                                                       MA13		   MA11              MA10           MA9
#define MR0_DDR4_WR_RTP_10_5     (0 << MA13)+ (0 << MA11) + (0 <<MA10) + (0 <<MA09)
#define MR0_DDR4_WR_RTP_12_6     (0 << MA13)+ (0 << MA11) + (0 <<MA10) + (1 <<MA09)
#define MR0_DDR4_WR_RTP_14_7     (0 << MA13)+ (0 << MA11) + (1 <<MA10) + (0 <<MA09)
#define MR0_DDR4_WR_RTP_16_8     (0 << MA13)+ (0 << MA11) + (1 <<MA10) + (1 <<MA09)
#define MR0_DDR4_WR_RTP_18_9     (0 << MA13)+ (1 << MA11) + (0 <<MA10) + (0 <<MA09)
#define MR0_DDR4_WR_RTP_20_10    (0 << MA13)+ (1 << MA11) + (0 <<MA10) + (1 <<MA09)
#define MR0_DDR4_WR_RTP_24_12    (0 << MA13)+ (1 << MA11) + (1 <<MA10) + (0 <<MA09)
#define MR0_DDR4_WR_RTP_22_11    (0 << MA13)+ (1 << MA11) + (1 <<MA10) + (1 <<MA09) 
#define MR0_DDR4_WR_RTP_26_13    (1 << MA13)+ (0 << MA11) + (0 <<MA10) + (0 <<MA09)

//                                                            MA8
#define MR0_DDR4_DLL_RESET           (1 <<MA08)

//                                                            MA7
#define MR0_DDR4_TEST_MODE           (1 <<MA07)

//                                                            MA3
#define MR0_DDR4_READ_BURST_INVL     (1 <<MA03)



//                                               MA12             MA6               MA5           MA4           MA2
#define MR0_DDR4_CL9         (0 << MA12) + (0 <<MA06) + (0 <<MA05) + (0 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL10        (0 << MA12) + (0 <<MA06) + (0 <<MA05) + (0 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL11        (0 << MA12) + (0 <<MA06) + (0 <<MA05) + (1 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL12        (0 << MA12) + (0 <<MA06) + (0 <<MA05) + (1 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL13        (0 << MA12) + (0 <<MA06) + (1 <<MA05) + (0 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL14        (0 << MA12) + (0 <<MA06) + (1 <<MA05) + (0 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL15        (0 << MA12) + (0 <<MA06) + (1 <<MA05) + (1 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL16        (0 << MA12) + (0 <<MA06) + (1 <<MA05) + (1 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL18        (0 << MA12) + (1 <<MA06) + (0 <<MA05) + (0 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL20        (0 << MA12) + (1 <<MA06) + (0 <<MA05) + (0 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL22        (0 << MA12) + (1 <<MA06) + (0 <<MA05) + (1 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL24        (0 << MA12) + (1 <<MA06) + (0 <<MA05) + (1 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL23        (0 << MA12) + (1 <<MA06) + (1 <<MA05) + (0 <<MA04) + (0 <<MA02) 
#define MR0_DDR4_CL17        (0 << MA12) + (1 <<MA06) + (1 <<MA05) + (0 <<MA04) + (1 <<MA02) 
#define MR0_DDR4_CL19		 (0 << MA12) + (1 <<MA06) + (1 <<MA05) + (1 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL21		 (0 << MA12) + (1 <<MA06) + (1 <<MA05) + (1 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL25		 (1 << MA12) + (0 <<MA06) + (0 <<MA05) + (0 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL26		 (1 << MA12) + (0 <<MA06) + (0 <<MA05) + (0 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL27		 (1 << MA12) + (0 <<MA06) + (0 <<MA05) + (1 <<MA04) + (0 <<MA02)
#define MR0_DDR4_CL28		 (1 << MA12) + (0 <<MA06) + (0 <<MA05) + (1 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL30		 (1 << MA12) + (0 <<MA06) + (1 <<MA05) + (0 <<MA04) + (1 <<MA02)
#define MR0_DDR4_CL32		 (1 << MA12) + (0 <<MA06) + (1 <<MA05) + (1 <<MA04) + (1 <<MA02)


//                                                            MA1                  MA0
#define MR0_DDR4_BL8                 (0 <<MA01)  +   (0 <<MA00)     
#define MR0_DDR4_ON_THE_FLY          (0 <<MA01)  +   (1 <<MA00)
#define MR0_DDR4_BL4                 (1 <<MA01)  +   (0 <<MA00)  





//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                       23    22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 


// DDR4 MR1 (BG0=0  BA1=0, BA0=1)
// MA[17]	-  0
// MA[13]      - 0
// MA[12]	- Qoff
// MA[11]      - TDQS enable
// MA[10:8]	- RTT_NOM
// MA[7]		- Write leveling Enable
// MA[6:5]	- 0
// MA[4:3]	- AL
// MA[2:1]     - Output Driver Impedance Control
// MA[0]  	- DLL Enable 
//					

#define DDR4_MR1_INIT    0x00
#define MR1_WLVL_UNDERCALPR 0x01
#define MR1_WLVL_OTHERPR    0x02


//                                                            BG0            BA1           BA0                   
//#define DDR4_MR1                    (0 <<6) + (0  <<16) +(1 <<15)

//                                                           MA12
#define MR1_DDR4_QOff_DIS           (1 <<MA12) 
//                                                           MA11   
#define MR1_DDR4_TDQS_ENABLE        (1 << MA11)
//                                                           MA10               MA9                 MA8                                 
#define MR1_DDR4_RTT_NOM_DIS        (0 <<MA10) + (0 <<MA09) + (0 <<MA08)
#define MR1_DDR4_RTT_NOM_60OHM      (0 <<MA10) + (0 <<MA09) + (1 <<MA08)
#define MR1_DDR4_RTT_NOM_120OHM     (0 <<MA10) + (1 <<MA09) + (0 <<MA08)
#define MR1_DDR4_RTT_NOM_40OHM      (0 <<MA10) + (1 <<MA09) + (1 <<MA08)
#define MR1_DDR4_RTT_NOM_240OHM     (1 <<MA10) + (0 <<MA09) + (0 <<MA08)
#define MR1_DDR4_RTT_NOM_48OHM      (1 <<MA10) + (0 <<MA09) + (1 <<MA08)
#define MR1_DDR4_RTT_NOM_80OHM      (1 <<MA10) + (1 <<MA09) + (0 <<MA08)
#define MR1_DDR4_RTT_NOM_34OHM      (1 <<MA10) + (1 <<MA09) + (1 <<MA08)

//                                                           MA7
#define MR1_DDR4_WLVL_EN            (1 <<MA07) 


//                                                           MA4                MA3
#define MR1_DDR4_AL_DIS              (0 <<MA04) + (0 <<MA03)
#define MR1_DDR4_AL_CL1              (0 <<MA04) + (1 <<MA03)      
#define MR1_DDR4_AL_CL2              (1 <<MA04) + (0 <<MA03)

//                                                           MA2                MA1
#define MR1_DDR4_RZQ7                (0 <<MA02) + (0 <<MA01)
#define MR1_DDR4_RZQ5                (0 <<MA02) + (1 <<MA01)

//                                                           MA0
#define MR1_DDR4_DLL_EN              (1 <<MA00)
#define MR1_DDR4_DLL_DIS             (0 <<MA00)








//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                       23    22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 


// DDR4 MR2 (BG0=0  BA1=1, BA0=0)
// MA[17]	-  0
// MA[13]      - 0
// MA[12]	- Write CRC Enable
// MA[11:9]	- RTT_WR
// MA[8]		- 0
// MA[7:6]	- Low Power Array Self Refresh
// MA[5:3]	- CWL
// MA[2:0]     - 0 
//					

#define DDR4_MR2_INIT    0x00
#define MR2_RTTWR_DIS    0x01 

//                                                              BG0            BA1           BA0                   
//#define DDR4_MR2                     (0 <<6) + (1 <<16) +(0 <<15)


//                                                            MA12
#define MR2_DDR4_CRC_EN              (1 <<MA12) 
//                                                            MA11                MA10               MA9
#define MR2_DDR4_RTT_WR_DIS          (0 << MA11) + (0 <<MA10) + (0 <<MA09)
#define MR2_DDR4_RTT_WR_120OHM       (0 << MA11) + (0 <<MA10) + (1 <<MA09)
#define MR2_DDR4_RTT_WR_240OHM       (0 << MA11) + (1 <<MA10) + (0 <<MA09)
#define MR2_DDR4_RTT_WR_HIGHZ        (0 << MA11) + (1 <<MA10) + (1 <<MA09)
#define MR2_DDR4_RTT_WR_80OHM        (1 << MA11) + (0 <<MA10) + (0 <<MA09)

//                                                            MA7                 MA6
#define MR2_DDR4_LPASR_NOM           (0 <<MA07) +  (0 <<MA06)
#define MR2_DDR4_LPASR_REDUCED       (0 <<MA07) +  (1 <<MA06)
#define MR2_DDR4_LPASR_EXTEND        (1 <<MA07) +  (0 <<MA06)
#define MR2_DDR4_LPASR_ASR           (1 <<MA07) +  (1 <<MA06)


//                                                             MA5                MA4              MA3
#define MR2_DDR4_CWL_9               (0 <<MA05) + (0 <<MA04) +(0 <<MA03)
#define MR2_DDR4_CWL_10              (0 <<MA05) + (0 <<MA04) +(1 <<MA03)
#define MR2_DDR4_CWL_11              (0 <<MA05) + (1 <<MA04) +(0 <<MA03)
#define MR2_DDR4_CWL_12              (0 <<MA05) + (1 <<MA04) +(1 <<MA03)
#define MR2_DDR4_CWL_14              (1 <<MA05) + (0 <<MA04) +(0 <<MA03)
#define MR2_DDR4_CWL_16              (1 <<MA05) + (0 <<MA04) +(1 <<MA03)
#define MR2_DDR4_CWL_18              (1 <<MA05) + (1 <<MA04) +(0 <<MA03)
#define MR2_DDR4_CWL_20              (1 <<MA05) + (1 <<MA04) +(1 <<MA03)





//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                       23    22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 



// DDR4 MR3 (BG0=0  BA1=1, BA0=1)
// MA[17]	-  0
// MA[13]      - 0
// MA[12:11]	- MPR Read Format
// MA[10:9]	- Write CMD Latency when CRC and DM are enabled
// MA[8:6]	- Fine Granularity Refresh Mode
// MA[5]		- Temperature sensor readout enable
// MA[4]		- Per DRAM Addressability
// MA[3]        - Geardown mode
// MA[2]        - MPR Enable
// MA[1:0]  	- MPR page Selection 
//				

#define DDR4_MR3_INIT    0x00
#define MR3_MPR_EN       0x01
#define MR3_MPR_SERIAL   0x02
#define MR3_MPR_PARALLEL 0x04
#define MR3_MPR_STAGGER  0x08
#define MR3_MPR_PAGE0    0x10
#define MR3_MPR_PAGE1    0x20
#define MR3_MPR_PAGE2    0x40
#define MR3_MPR_PAGE3    0x80
#define MR3_MPR_PDA      0x100

//                                                               BG0            BA1           BA0                   
//#define DDR4_MR3                     (0 <<6) + (1 <<16) +(1 <<15)

//                                                              MA12             MA11   
#define MR3_DDR4_SERIAL              (0 <<MA12) + (0 << MA11)
#define MR3_DDR4_PARALLEL            (0 <<MA12) + (1 << MA11) 
#define MR3_DDR4_STAGGER             (1 <<MA12) + (0 << MA11) 


//                                                             MA10               MA9
#define MR3_DDR4_CRC_RWCL4            (0 <<MA10) + (0 <<MA09)
#define MR3_DDR4_CRC_RWCL5            (0 <<MA10) + (1 <<MA09)
#define MR3_DDR4_CRC_RWCL6            (1 <<MA10) + (0 <<MA09)

//                                                             MA8                 MA7               MA6
#define MR3_DDR4_FGRM_1X             (0 <<MA08) + (0 <<MA07) + (0 <<MA06)
#define MR3_DDR4_FGRM_2X             (0 <<MA08) + (0 <<MA07) + (1 <<MA06)
#define MR3_DDR4_FGRM_4X             (0 <<MA08) + (1 <<MA07) + (0 <<MA06)
#define MR3_DDR4_ON_THE_FLY_2X       (1 <<MA08) + (0 <<MA07) + (1 <<MA06) 
#define MR3_DDR4_ON_THE_FLY_4X       (1 <<MA08) + (1 <<MA07) + (0 <<MA06)

//                                                             MA5
#define MR3_DDR4_TEMP_EN             (1 <<MA05) 

//                                                             MA4
#define MR3_DDR4_PDA_EN              (1 <<MA04)  

//                                                             MA3
#define MR3_DDR4_GEARDOWN_DIV2       (0 <<MA03) 
#define MR3_DDR4_GEARDOWN_DIV4       (1 <<MA03) 

//                                                             MA2
#define MR3_DDR4_MPR_EN              (1 <<MA02)

//                                                             MA1                  MA0
#define MR3_DDR4_MPR_PAGE0           (0 <<MA01)  +  (0 <<MA00)
#define MR3_DDR4_MPR_PAGE1           (0 <<MA01)  +  (1 <<MA00)
#define MR3_DDR4_MPR_PAGE2           (1 <<MA01)  +  (0 <<MA00)
#define MR3_DDR4_MPR_PAGE3           (1 <<MA01)  +  (1 <<MA00)




//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                       23    22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 

// DDR4 MR4 (BG0=1  BA1=0, BA0=0)
// MA[17]	-  0
// MA[13]      - PPR
// MA[12]	- Write preamble
// MA[11]	- Read preamble
// MA[10]	- Read preamble Training
// MA[9]		- Self refresh Abort
// MA[8:6]	- CAL mode
// MA[5]        - 0
// MA[4]        - Internal Vref Monitor
// MA[3]        - Tempreature Controlled Refresh Mode
// MA[2]        - Tempreature Controlled Refresh Range
// MA[1]        - Maximum Power Down Mode
// MA[0]  	- 0
//					

#define DDR4_MR4_INIT          0x00
#define MR4_RD_PREAMBLE_TRAIN  0x01
#define MR4_MPDM_EN            0x02
#define MR4_CALEN              0X04 
//                                                             BG0            BA1           BA0                   
//#define DDR4_MR4                     (1 <<6) + (0 <<16) +(0 <<15)

//                                                             MA13
#define MR4_DDR4_PPR_EN              (1 << MA13)    
//                                                             MA12 
#define MR4_DDR4_WR_PREAMBLE_1       (0 <<MA12)
#define MR4_DDR4_WR_PREAMBLE_2       (1 <<MA12) 

//                                                             MA11
#define MR4_DDR4_RD_PREAMBLE_1       (0 << MA11)
#define MR4_DDR4_RD_PREAMBLE_2       (1 << MA11)

//                                                             MA10
#define MR4_DDR4_RD_PREAMBLE_TRAIN   (1 <<MA10)

//                                                             MA9 
#define MR4_DDR4_SELFREF_ABORT_EN    (1 <<MA09)

//                                                             MA8                 MA7                MA6
#define MR4_DDR4_CAL_DIS             (0 <<MA08)  + (0 <<MA07) + (0 <<MA06)
#define MR4_DDR4_CAL_3               (0 <<MA08)  + (0 <<MA07) + (1 <<MA06)
#define MR4_DDR4_CAL_4               (0 <<MA08)  + (1 <<MA07) + (0 <<MA06)
#define MR4_DDR4_CAL_5               (0 <<MA08)  + (1 <<MA07) + (1 <<MA06)
#define MR4_DDR4_CAL_6               (1 <<MA08)  + (0 <<MA07) + (0 <<MA06)
#define MR4_DDR4_CAL_8               (1 <<MA08)  + (0 <<MA07) + (1 <<MA06)


//                                                                   MA4
#define MR4_DDR4_VREF_MONITOR_EN       (1 <<MA04)
  
//                                                                   MA3
#define MR4_DDR4_TEMP_CTL_REF_EN       (1 <<MA03)

//                                                                  MA2
#define MR4_DDR4_TEMP_CTL_REF_NOM      (0 <<MA02)
#define MR4_DDR4_TEMP_CTL_REF_EXTEND   (1 <<MA02)

//                                                                  MA1
#define MR4_DDR4_MPDM_EN               (1 <<MA01)





//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                       23    22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 



// DDR4 MR5 (BG0=1  BA1=0, BA0=1)
// MA[17]	-  0
// MA[13]      - 0
// MA[12]	- Read DBI Enable
// MA[11]	- Write DBI Enable
// MA[10]	- Data Mask Enable
// MA[9]		- CA parity Persistent Error
// MA[8:6]	- RTT_PARK
// MA[5]        - ODT Input Buffer during Power Down Mode
// MA[4]  	- C/A Parity Error Status Clear
// MA[3]        - CRC Error Clear
// MA[2:0]     - C/A Parity Latency Mode
//					

#define DDR4_MR5_INIT    0x00
#define ODT_PWD_ACT      0x01
#define ODT_PWD_DE_ACT   0x02
//                                                               BG0            BA1           BA0                   
//#define DDR4_MR5                     (1 <<6) + (0 <<16) +(1 <<15)
//                                                               MA12
#define MR5_DDR4_RD_DBI_EN           (1 <<MA12)
//                                                               MA11
#define MR5_DDR4_WR_DBI_EN           (1 << MA11)
//                                                               MA10
#define MR5_DDR4_DM_EN               (1 << MA10)
//                                                               MA9
#define MR5_DDR4_CA_PAR_PERSISTENT   (1 <<MA09)
//                                                               MA8              MA7                MA6
#define MR5_DDR4_RTT_PARK_DIS        (0 <<MA08) + (0 <<MA07 ) + (0 <<MA06)
#define MR5_DDR4_RTT_PARK_60OHM      (0 <<MA08) + (0 <<MA07 ) + (1 <<MA06)
#define MR5_DDR4_RTT_PARK_120OHM     (0 <<MA08) + (1 <<MA07 ) + (0 <<MA06)
#define MR5_DDR4_RTT_PARK_40OHM      (0 <<MA08) + (1 <<MA07 ) + (1 <<MA06)
#define MR5_DDR4_RTT_PARK_240OHM     (1 <<MA08) + (0 <<MA07 ) + (0 <<MA06)
#define MR5_DDR4_RTT_PARK_48OHM      (1 <<MA08) + (0 <<MA07 ) + (1 <<MA06)
#define MR5_DDR4_RTT_PARK_80OHM      (1 <<MA08) + (1 <<MA07 ) + (0 <<MA06)
#define MR5_DDR4_RTT_PARK_34OHM      (1 <<MA08) + (1 <<MA07 ) + (1 <<MA06)


//                                                               MA5
#define MR5_DDR4_ODT_PWD_ACT         (0 <<MA05)
#define MR5_DDR4_ODT_PWD_DE_ACT      (1 <<MA05)
//                                                               MA4
#define MR5_DDR4_CA_PATITY_CLR       (1 <<MA04)
//                                                               MA3
#define MR5_DDR4_CRC_CLR             (1 <<MA03)
//                                                               MA2            MA1               MA0
#define MR5_DDR4_PL_DIS              (0 <<MA02) + (0 <<MA01) + (0 <<MA00)
#define MR5_DDR4_PL4                 (0 <<MA02) + (0 <<MA01) + (1 <<MA00)
#define MR5_DDR4_PL5                 (0 <<MA02) + (1 <<MA01) + (0 <<MA00)
#define MR5_DDR4_PL6                 (0 <<MA02) + (1 <<MA01) + (1 <<MA00)
#define MR5_DDR4_PL8                 (1 <<MA02) + (0 <<MA01) + (0 <<MA00)






//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                      23     22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 



// DDR4 MR6 (BG0=1  BA1=1, BA0=0)
// MA[17]	-  0
// MA[13]      - 0
// MA[12:10]	- tCCD_L
// MA[9:8]	- 0
// MA[7]		- Vref Training Enable
// MA[6]		- Vref Training Range
// MA[5:0]	- Vref Training Value 
//					
#define DDR4_MR6_INIT    0x00
#define VREF_TRAIN_EN    0x01
#define VREF_RANGE1      0x02
#define VREF_RANGE2      0x04 
//                                                               BG0             BA1           BA0                   
//#define DDR4_MR6                      (1 <<6) + (1 <<16) +(0 <<15)

//                                                              MA12             MA11            MA10                            
#define MR6_DDR4_TCCDL4               (0 <<MA12) + (0 << MA11) + (0 <<MA10)
#define MR6_DDR4_TCCDL5               (0 <<MA12) + (0 << MA11) + (1 <<MA10)
#define MR6_DDR4_TCCDL6               (0 <<MA12) + (1 << MA11) + (0 <<MA10)
#define MR6_DDR4_TCCDL7               (0 <<MA12) + (1 << MA11) + (1 <<MA10)
#define MR6_DDR4_TCCDL8               (1 <<MA12) + (0 << MA11) + (0 <<MA10)

//                                                               MA7
#define MR6_DDR4_VREF_TRAIN_EN        (1 <<MA07)
//                                                               MA6
#define MR6_DDR4_VREF_RANGE1          (0 <<MA06)
#define MR6_DDR4_VREF_RANGE2          (1 <<MA06)

//                                                              MA5           MA4            MA3            MA2              MA1             MA0




//Typical MA mapping for a MRS command
//BG1 BG0  BA1  BA0	MA17 MA14 MA13 MA12 MA11 MA10 MA09 MA08 MA07 MA06 MA05 MA04 MA03 MA02 MA01 MA00
//  7,   6,    16,   15,                      23     22,   21,     20,    14,    13,    12,    11,    10,    9,       8,     5,      4,     3 
//
#define DDR4_MR7_INIT    0x00

//                                                               BG0             BA1           BA0                   
//#define DDR4_MR7                      (1 <<6) + (1 <<16) +(1 <<15)

//                                                               MA7               MA6             MA5              MA4      
#define  MR7_RC00                    (0 << MA07) + (0 << MA06) + (0 << MA05) + (0 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC00_INVERSION_EN                                            (0 << MA00)
#define MR7_RC00_INVERSION_DIS                                           (1 << MA00)
#define MR7_RC00_WEAK_DRIVE_DIS                              (0 << MA01)    
#define MR7_RC00_WEAK_DRIVE_EN                               (1 << MA01)
#define MR7_RC00_A_OUTPUT_EN                     (0 << MA02)
#define MR7_RC00_A_OUTPUT_DIS                    (1 << MA02)
#define MR7_RC00_B_OUTPUT_EN         (0 << MA03)   
#define MR7_RC00_B_OUTPUT_DIS        (1 << MA03) 

//                                                               MA7               MA6             MA5              MA4   
#define  MR7_RC01                    (0 << MA07) + (0 << MA06) + (0 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC01_Y0CLK_EN                                                (0 << MA00)
#define MR7_RC01_Y0CLK_DIS                                               (1 << MA00)    
#define MR7_RC01_Y1CLK_EN                                     (0 << MA01)                                    
#define MR7_RC01_Y1CLK_DIS                                    (1 << MA01)  
#define MR7_RC01_Y2CLK_EN                         (0 << MA02)  
#define MR7_RC01_Y2CLK_DIS                        (1 << MA02)
#define MR7_RC01_Y3CLK_EN             (0 << MA03)    
#define MR7_RC01_Y3CLK_DIS            (1 << MA03) 

//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC02                    (0 << MA07) + (0 << MA06) + (1 << MA05) + (0 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC02_DA17_IBT_EN                                              (0 << MA00)  
#define MR7_RC02_DA17_IBT_DIS                                             (1 << MA00)   
#define MR7_RC02_DPAR_IBT_EN                                  (0 << MA01)                
#define MR7_RC02_DPAR_IBT_DIS                                 (1 << MA01)                 
#define MR7_RC02_TRANSPARENT_DIS                   (0 << MA02)                                                
#define MR7_RC02_TRANSPARENT_EN                    (1 << MA02)                            
#define MR7_RC02_FREQ_OPER            (0 << MA03)                                            
#define MR7_RC02_FREQ_TEST            (1 << MA03)                                          




//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC03                    (0 << MA07) + (0 << MA06) + (1 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC03_ADDR_LIGHT_DRIVE                            (0 << MA01) +  (0 << MA00)        
#define MR7_RC03_ADDR_MODERATE_DRIVE                         (0 << MA01) +  (1 << MA00)                 
#define MR7_RC03_ADDR_STRONG_DRIVE                           (1 << MA01) +  (0 << MA00) 
#define MR7_RC03_ADDR_VSTRONG_DRIVE                          (1 << MA01) +  (1 << MA00) 
#define MR7_RC03_CS_LIGHT_DRIVE      (0 << MA03)  + (0 << MA02)    
#define MR7_RC03_CS_MODERATE_DRIVE   (0 << MA03)  + (1 << MA02) 
#define MR7_RC03_CS_STRONG_DRIVE     (1 << MA03)  + (0 << MA02)
#define MR7_RC03_CS_VSTRONG_DRIVE    (1 << MA03)  + (1 << MA02)






//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC04                    (0 << MA07) + (1 << MA06) + (0 << MA05) + (0 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC04_ODT_LIGHT_DRIVE                              (0 << MA01) +  (0 << MA00)                 
#define MR7_RC04_ODT_MODERATE_DRIVE                           (0 << MA01) +  (1 << MA00)                 
#define MR7_RC04_ODT_STRONG_DRIVE                             (1 << MA01) +  (0 << MA00)                    
#define MR7_RC04_CKE_LIGHT_DRIVE     (0 << MA03)  + (0 << MA02)                                                   
#define MR7_RC04_CKE_MODERATE_DRIVE  (0 << MA03)  + (1 << MA02)                                                       
#define MR7_RC04_CKE_STRONG_DRIVE    (1 << MA03)  + (0 << MA02)                                                      




//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC05                    (0 << MA07) + (1 << MA06) + (0 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC05_ACLK_LIGHT_DRIVE                             (0 << MA01) +  (0 << MA00)                            
#define MR7_RC05_ACLK_MODERATE_DRIVE                          (0 << MA01) +  (1 << MA00)                               
#define MR7_RC05_ACLK_STRONG_DRIVE                            (1 << MA01) +  (0 << MA00)                               

#define MR7_RC05_BCLK_LIGHT_DRIVE     (0 << MA03)  + (0 << MA02)                                              
#define MR7_RC05_BCLK_MODERATE_DRIVE  (0 << MA03)  + (1 << MA02)                                                         
#define MR7_RC05_BCLK_STRONG_DRIVE    (1 << MA03)  + (0 << MA02)                                                          





//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC06                    (0 << MA07) + (1 << MA06) + (1 << MA05) + (0 << MA04)

//                                                               MA3               MA2             MA1              MA0



//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC07                    (0 << MA07) + (1 << MA06) + (1 << MA05) + (1 << MA04)


//                                                               MA3               MA2             MA1              MA0





//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC08                    (1 << MA07) + (0 << MA06) + (0 << MA05) + (0 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC08_CHIP_ID_DIS                                 (1 << MA01) +  (1 << MA00) 
#define MR7_RC08_PAR_EN                           (0 << MA02)               
#define MR7_RC08_PAR_DIS                          (1 << MA02)

#define MR7_RC08_A17_EN              (0 << MA03)  
#define MR7_RC08_A17_DIS             (1 << MA03)


//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC09                    (1 << MA07) + (0 << MA06) + (0 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC09_CKE_POWER_DOWN_DIS  (0 << MA03)  
#define MR7_RC09_CKE_POWER_DOWN_EN   (1 << MA03)



//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC0A                    (1 << MA07) + (0 << MA06) + (1 << MA05) + (0 << MA04)


//                                                               MA3               MA2             MA1              MA0
#define  MR7_RC0A_DDR41600                        (0 << MA02) +  (0 << MA01) +  (0 << MA00)
#define  MR7_RC0A_DDR41866                        (0 << MA02) +  (0 << MA01) +  (1 << MA00)
#define  MR7_RC0A_DDR42133                        (0 << MA02) +  (1 << MA01) +  (0 << MA00) 
#define  MR7_RC0A_DDR42400                        (0 << MA02) +  (1 << MA01) +  (1 << MA00) 
#define  MR7_RC0A_DDR42666                        (1 << MA02) +  (0 << MA01) +  (0 << MA00)
#define  MR7_RC0A_DDR42933                        (1 << MA02) +  (0 << MA01) +  (1 << MA00)
#define  MR7_RC0A_DDR43200                        (1 << MA02) +  (1 << MA01) +  (0 << MA00)
#define  MR7_RC0A_PLL_BYPASS                      (1 << MA02) +  (1 << MA01) +  (1 << MA00)  



//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC0B                    (1 << MA07) + (0 << MA06) + (1 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC0B_VDD12                                                   (0 << MA00)   
#define MR7_RC0B_INTER_VREF          (0 << MA03)   


//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC0C                    (1 << MA07) + (1 << MA06) + (0 << MA05) + (0 << MA04)


//                                                               MA3               MA2             MA1              MA0
#define  MR7_RC0C_NOMAL_MODE                     (0 << MA02) +  (0 << MA01) +  (0 << MA00)  



//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC0D                    (1 << MA07) + (1 << MA06) + (0 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_RC0D_DUALCS_MODE                                 (0 << MA01) +  (0 << MA00)       
#define MR7_RC0D_LRDIMM                           (0 << MA02) 
#define MR7_RC0D_RDIMM                            (1 << MA02)   
#define MR7_RC0D_ADD_MIRROR_DIS      (0 << MA03)
#define MR7_RC0D_ADD_MIRROR_EN       (1 << MA03)   


//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC0E                    (1 << MA07) + (1 << MA06) + (1 << MA05) + (0 << MA04)


//                                                               MA3               MA2             MA1              MA0
#define MR7_RC0E_PAR_DIS                                                 (0 << MA00)                                            
#define MR7_RC0E_PAR_EN                                                  (1 << MA00)  


//                                                               MA7               MA6             MA5              MA4    
#define  MR7_RC0F                    (1 << MA07) + (1 << MA06) + (1 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define  MR7_RC0F_CLA_1CLK                        (0 << MA02) +  (0 << MA01) +  (0 << MA00)
#define  MR7_RC0F_CLA_2CLK                        (0 << MA02) +  (0 << MA01) +  (1 << MA00)
#define  MR7_RC0F_CLA_3CLK                        (0 << MA02) +  (1 << MA01) +  (0 << MA00) 
#define  MR7_RC0F_CLA_4CLK                        (0 << MA02) +  (1 << MA01) +  (1 << MA00)
#define  MR7_RC0F_CLA_0CLK                        (1 << MA02) +  (0 << MA01) +  (0 << MA00) 



//                                                            MA12              MA11               MA10            MA9              MA8    
#define  MR7_RC3X                   (0 << MA12) +  (0 << MA11) +  (0 << MA10) + (1 << MA09) + (1 << MA08)
//                                                              MA6             MA5              MA4             MA3               MA2             MA1              MA0
//0010001
#define  MR7_RC3X_DDR41600           (0 << MA06) + (0 << MA05) + (1 << MA04) + (0 << MA03) +  (0 << MA02) +  (0 << MA01) + (1 << MA00)
//0011111
#define  MR7_RC3X_DDR41866           (0 << MA06) + (0 << MA05) + (1 << MA04) + (1 << MA03) +  (1 << MA02) +  (1 << MA01) + (1 << MA00) 
//0101100
#define  MR7_RC3X_DDR42133           (0 << MA06) + (1 << MA05) + (0 << MA04) + (1 << MA03) +  (1 << MA02) +  (0 << MA01) + (0 << MA00)
//0111001
#define  MR7_RC3X_DDR42400           (0 << MA06) + (1 << MA05) + (1 << MA04) + (1 << MA03) +  (0 << MA02) +  (0 << MA01) + (1 << MA00)
//1000111
#define  MR7_RC3X_DDR42666			 (1 << MA06) + (0 << MA05) + (0 << MA04) + (0 << MA03) +  (1 << MA02) +  (1 << MA01) + (1 << MA00)
//1010100
#define  MR7_RC3X_DDR42933			 (1 << MA06) + (0 << MA05) + (1 << MA04) + (0 << MA03) +  (1 << MA02) +  (0 << MA01) + (0 << MA00)
//1100001
#define  MR7_RC3X_DDR43200			 (1 << MA06) + (1 << MA05) + (0 << MA04) + (0 << MA03) +  (0 << MA02) +  (0 << MA01) + (1 << MA00)


//                                                            MA12                     MA11               MA10                  MA9              MA8    
#define  MR7_RC4X                   (0 << MA12) +  (0 << MA11) +  (1 << MA10) + (0 << MA09) + (0 << MA08)

//                                                           MA7                  MA6             MA5              
#define  FUN_SPACE1               (0 << MA07)+  (0 << MA06) + (1 << MA05)    
#define  FUN_SPACE2               (0 << MA07)+  (1 << MA06) + (0 << MA05) 
#define  FUN_SPACE3               (0 << MA07)+  (1 << MA06) + (1 << MA05) 
#define  FUN_SPACE4               (1 << MA07)+  (0 << MA06) + (0 << MA05) 
#define  FUN_SPACE5               (1 << MA07)+  (0 << MA06) + (1 << MA05) 


//                                                            MA12                    MA11               MA10                   MA9              MA8    
#define  MR7_RC6X                   (0 << MA12) +  (0 << MA11) +  (1 << MA10) + (1 << MA09) + (0 << MA08)
//                                                            MA6             MA5              MA4             MA3               MA2             MA1              MA0





#define SPACE1 1
#define SPECE2 2
#define SPECE3 3
#define SPECE4 4
#define SPECE5 5
#define SPECE6 6
#define SPECE7 7


//F1RC01
//                                                               MA7               MA6             MA5              MA4   
#define  MR7_F1RC01                    (0 << MA07) + (0 << MA06) + (0 << MA05) + (1 << MA04)

//                                                               MA3               MA2             MA1              MA0
#define MR7_F1RC01_CALSNOOP_EN                                                (1 << MA00)
#define MR7_F1RC01_CALSNOOP_DIS                                               (0 << MA00)    


//========================================
// define structure
//========================================
typedef struct {
  UINT8                                 DqsiLowBound;
  UINT8                                 DqsiHighBound;
} CHANNEL_INFO;

// According to SPD byte 7 to define.
#define	RAW_CARD_A	 0x00 
#define	RAW_CARD_B	 0x01 
#define	RAW_CARD_C	 0x02 
#define	RAW_CARD_D	 0x03 

#define	RAW_CARD_E	 0x04 
#define	RAW_CARD_F	 0x05 
#define	RAW_CARD_G	 0x06

#define	RAW_CARD_J	 0x08
#define RAW_CARD_ZZ  0x1F

#define	RAW_CARD_O	 0x0F //other

//card type combination of DIMM1:DIMM0
#define RAW_CARD_AO ((RAW_CARD_A << 4) | RAW_CARD_O)
#define RAW_CARD_AA ((RAW_CARD_A << 4 )| RAW_CARD_A)
#define RAW_CARD_AB ((RAW_CARD_A << 4 )| RAW_CARD_B)
#define RAW_CARD_AC ((RAW_CARD_A << 4 )| RAW_CARD_C)
#define RAW_CARD_AD ((RAW_CARD_A << 4 )| RAW_CARD_D)
#define RAW_CARD_AE ((RAW_CARD_A << 4 )| RAW_CARD_E)
#define RAW_CARD_AF ((RAW_CARD_A << 4 )| RAW_CARD_F)
#define RAW_CARD_AG ((RAW_CARD_A << 4 )| RAW_CARD_G)
#define RAW_CARD_BO ((RAW_CARD_B << 4 )| RAW_CARD_O)
#define RAW_CARD_BA ((RAW_CARD_B << 4 )| RAW_CARD_A)
#define RAW_CARD_BB ((RAW_CARD_B << 4 )| RAW_CARD_B)
#define RAW_CARD_BC ((RAW_CARD_B << 4 )| RAW_CARD_C)
#define RAW_CARD_BD ((RAW_CARD_B << 4 )| RAW_CARD_D)
#define RAW_CARD_BE ((RAW_CARD_B << 4 )| RAW_CARD_E)
#define RAW_CARD_BF ((RAW_CARD_B << 4 )| RAW_CARD_F)
#define RAW_CARD_BG ((RAW_CARD_B << 4 )| RAW_CARD_G)
#define RAW_CARD_CO ((RAW_CARD_C << 4) | RAW_CARD_O)
#define RAW_CARD_CA ((RAW_CARD_C << 4 )| RAW_CARD_A)
#define RAW_CARD_CB ((RAW_CARD_C << 4 )| RAW_CARD_B)
#define RAW_CARD_CC ((RAW_CARD_C << 4 )| RAW_CARD_C)
#define RAW_CARD_CD ((RAW_CARD_C << 4 )| RAW_CARD_D)
#define RAW_CARD_CE ((RAW_CARD_C << 4 )| RAW_CARD_E)
#define RAW_CARD_CF ((RAW_CARD_C << 4 )| RAW_CARD_F)
#define RAW_CARD_CG ((RAW_CARD_C << 4 )| RAW_CARD_G)

#define RAW_CARD_DO ((RAW_CARD_D << 4) | RAW_CARD_O)
#define RAW_CARD_DA ((RAW_CARD_D << 4 )| RAW_CARD_A)
#define RAW_CARD_DB ((RAW_CARD_D << 4 )| RAW_CARD_B)
#define RAW_CARD_DC ((RAW_CARD_D << 4 )| RAW_CARD_C)
#define RAW_CARD_DD ((RAW_CARD_D << 4 )| RAW_CARD_D)
#define RAW_CARD_DE ((RAW_CARD_D << 4 )| RAW_CARD_E)
#define RAW_CARD_DF ((RAW_CARD_D << 4 )| RAW_CARD_F)
#define RAW_CARD_DG ((RAW_CARD_D << 4 )| RAW_CARD_G)

#define RAW_CARD_EO ((RAW_CARD_E << 4) | RAW_CARD_O)
#define RAW_CARD_EA ((RAW_CARD_E << 4 )| RAW_CARD_A)
#define RAW_CARD_EB ((RAW_CARD_E << 4 )| RAW_CARD_B)
#define RAW_CARD_EC ((RAW_CARD_E << 4 )| RAW_CARD_C)
#define RAW_CARD_ED ((RAW_CARD_E << 4 )| RAW_CARD_D)
#define RAW_CARD_EE ((RAW_CARD_E << 4 )| RAW_CARD_E)
#define RAW_CARD_EF ((RAW_CARD_E << 4 )| RAW_CARD_F)
#define RAW_CARD_EG ((RAW_CARD_E << 4 )| RAW_CARD_G)

#define RAW_CARD_FO ((RAW_CARD_F << 4 )| RAW_CARD_O)
#define RAW_CARD_FA ((RAW_CARD_F << 4 )| RAW_CARD_A)
#define RAW_CARD_FB ((RAW_CARD_F << 4 )| RAW_CARD_B)
#define RAW_CARD_FC ((RAW_CARD_F << 4 )| RAW_CARD_C)
#define RAW_CARD_FF ((RAW_CARD_F << 4 )| RAW_CARD_F)

#define RAW_CARD_GO ((RAW_CARD_G << 4 )| RAW_CARD_O)
#define RAW_CARD_GE ((RAW_CARD_G << 4 )| RAW_CARD_E)
#define RAW_CARD_GG ((RAW_CARD_G << 4 )| RAW_CARD_G)

#define RAW_CARD_OO ((RAW_CARD_O << 4 )| RAW_CARD_O)
#define RAW_CARD_OA ((RAW_CARD_O << 4 )| RAW_CARD_A)
#define RAW_CARD_OB ((RAW_CARD_O << 4 )| RAW_CARD_B)
#define RAW_CARD_OC ((RAW_CARD_O << 4 )| RAW_CARD_C)
#define RAW_CARD_OD ((RAW_CARD_O << 4 )| RAW_CARD_D)
#define RAW_CARD_OE ((RAW_CARD_O << 4 )| RAW_CARD_E)
#define RAW_CARD_OF ((RAW_CARD_O << 4 )| RAW_CARD_F)
#define RAW_CARD_OG ((RAW_CARD_O << 4 )| RAW_CARD_G)

#define CAL_FIRST_DIMM  0
#define CAL_SECOND_DIMM 1

#define VREF_FINE_MODE        0
#define VREF_COARSE_MODE      1

#define MODULE_TYPE_UDIMM 	0x02
#define MODULE_TYPE_SODIMM 	0x03
typedef struct{
	UINT8	SiTNIRefFreq1600;
	UINT8	SiTNIRefFreq1333;
	UINT8 	SiTNIRefFreq1066;
	UINT8	SiTNIRefFreq800;
}TNI_REF_DRAM;

#define WLVL_Repeat_MAX 8

//TX_IO_CALIBRATION_INFO, 19byte
typedef struct{	
    //CalResult
    BOOLEAN CalResult;
	//DQSI
	//UINT8 DQSI_LOW;	
	//UINT8 DQSI_HIGH;
	//UINT8 DQSI_Setting;		
	//TNI
	UINT16 TNI_LOW;	
	UINT16 TNI_HIGH;
	UINT16 TNI_Setting;		
	//DQO
	UINT16 DQO_HIGH;	
	UINT16 DQO_LOW;
	UINT16 DQO_Setting;

	//DQSO
	UINT16 DQSO_LOW;	
	UINT16 DQSO_HIGH;
	UINT16 DQSO_Setting;
}IO_CALIBRATION_INFO;


typedef struct{	
	UINT8 DQSI_LOW;	
	UINT8 DQSI_HIGH;
	UINT8 DQSI_Setting;		
}DQSI_IO_CALIBRATION_INFO;

typedef struct{
	DQSI_IO_CALIBRATION_INFO ByteInfo[ASIA_MAX_BYTES][ASIA_MAX_BIT][2];
	BOOLEAN CalResult;
}DQSI_IO_CALIBRATION_INFO_PerRank;

#define DQO_SAVE_NUM  0x04
//#define DQSO_SAVE_NUM  0x02
#define TXVREFRANGEQLTOTAL 0x10

typedef struct{	
	//DQO
	UINT8 DQO_LOW;
	UINT8 DQO_HIGH;
	UINT8 DQOPT;
	UINT8 DQOEndIndex;
   	
	//DQSO
	UINT8 DQSO_WLVL;	
	UINT8 DQSOPT;
	
	
}TX_INFO;

typedef struct
{
	UINT16 DQO_LOW;
	UINT16 DQO_HIGH;
	UINT16 DQORange;
	UINT8 TxVrefValue;
}TX_VREF_DQO_INFO;


/* -------DKS-debug-20170330--------- */
typedef struct
{
	UINT8 DQSI_LOW;
	UINT8 DQSI_HIGH;
	UINT16 DQSIRange;
	UINT8 RxVrefValue;
}RX_VERF_DQSI_INFO;
/* ---------------------------------- */

//#define CAL_RELEASE_TIME_NO_S3  //Using for calculate release bios calibration time

typedef struct
{
	//RX
	//TNI 0x46C-0x4BA
	UINT16 TNIVAL[40];
	//DQSI 0x4FC-0x97A
	UINT16 DQSIVAL[576];  //8bit * 9Byte * 8Rank
	//RXWholeT 0xA0C-0xA3A
	UINT16 RXWholeT[24];
	//RxVref 0xA98-0xB02
	UINT16 RxVref[54];
	//TX    
	//DQSO Phase 0x438-0x44A  
	UINT16 DQSOPhase[10];
	//DQO Phase 0x424-0x436 
	UINT16 DQOPhase[10]; 	
	//TXWholeT 0xA3C-0xA4E
	UINT16 TXWholeT[10];
	//TxVref
	UINT8 TxVref[ASIA_MAX_RANKS];
	UINT16        CHAOverlap;
	UINT16        CHBOverlap;
	UINT16        CHACoarseMode;
	UINT16        CHBCoarseMode;
}IO_TIMING;




typedef struct
{
   
    UINT8 DQSI_PERBIT_LOW;
	UINT8 DQSI_PERBIT_HIGH;
	UINT8 DQSI_PERBIT_DELAY;

	UINT8 DQO_PERBIT_LOW;
	UINT8 DQO_PERBIT_HIGH;
	UINT8 DQO_PERBIT_DELAY;

}PER_BIT_DESKEW_INFO;

typedef struct
{
   UINT8 RxVrefLOW;
   UINT8 RxVrefCENTER[ASIA_MAX_BYTES*2];
   UINT8 RxVrefHIGH;  
   UINT8 RxVrefDisplay;
   
}RX_VREF_INFO;

typedef struct
{
   UINT8 TxVrefLOW;
   UINT8 TxVrefCENTER;
   UINT8 TxVrefHIGH;
   UINT8 TxVrefDisplay;   //DKS -20161219 add

   UINT8 TxVrefCHASI;   //DKS -20161220 add
   UINT8 TxVrefCHBSI;   //DKS -20161220 add
   UINT16 DQO_LOW;
   UINT16 DQO_HIGH;
   UINT16 DQORange;
/*
   BOOLEAN TxVref_Result;
   //DQSO
	UINT8 DQSO_DLYCOMP_LOW;
	UINT8 DQSO_DLYCOMP_CENTER;
	UINT8 DQSO_DLYCOMP_HIGH;
	UINT8 DQSO_DLYCOMP_RANGE;
	

	//DQSO
	UINT8 DQSO_QUATER_T_LOW;
	UINT8 DQSO_QUATER_T_CENTER;
	UINT8 DQSO_QUATER_T_HIGH;
	UINT8 DQSO_QUATER_T_RANGE;

	//DQSO
	UINT8 DQSO_WHOLE_T_LOW;
	UINT8 DQSO_WHOLE_T_CENTER;
	UINT8 DQSO_WHOLE_T_HIGH;
	UINT8 DQSO_WHOLE_T_RANGE;
	*/
}TX_VREF_INFO;


//DIMM Manufacturer  Info
typedef struct
{
	UINT16  MFR_ID;
	UINT32  SERIAL_NO;
}DIMM_MFR_INFO; 

typedef struct{
	UINT16 WholeT;
	UINT16 Phase;
}SETTINGVal;

typedef  struct
{
	DIMM_MFR_INFO     MfrInfo[DRAMATTR_NUM][ASIA_MAX_SOCKETS];
	UINT8     WPREA;  //Write preamble	   
	UINT8     RPREA;  //read preamble
	UINT8	 DramFreq;
	BOOLEAN CAParEn;  //CA Parity check Enable
	BOOLEAN CRCEn;   //CRC Enable
	BOOLEAN DramFastBoot;
	UINT8 TxIoTimingMethod;
	UINT8 RxIoTimingMethod;
	UINT8 RxVref;
	UINT16 TxVref;
	BOOLEAN DramECC;
	UINT8 DQSIByRank; 
	UINT8 TxVrefAllByte;
	UINT8 MemoryChipODTDebug;
	UINT8 MemoryChipODTWRDebug;
	UINT8 MemoryChipODTParkDebug;

}DRAM_INFO_SAVE;

typedef struct {

  ASIA_SPD_DATA             SpdData[DRAMATTR_NUM][ASIA_MAX_SOCKETS];	
  DIMM_MFR_INFO             MfrInfo[DRAMATTR_NUM][ASIA_MAX_SOCKETS];  
  UINT8     RankPresent[DRAMATTR_NUM];
 UINT16	CHAWholeT[ASIA_MAX_BYTES];
  UINT16	CHBWholeT[ASIA_MAX_BYTES];
  										// Bit[3:0] indicates Rank Presence of Channel A
  										// Bit[7:4] indicates Rank Presence of Channel B								
  UINT8		ChADIMMNumber[DRAMATTR_NUM]; 			//range:0~2												  
  UINT8		ChARankNumber[DRAMATTR_NUM];			//range: 0~4
  UINT8		ChADRAMChipDataWidth[DRAMATTR_NUM];		//8: x8 chip, 16: x16 chip
  UINT8		ChAChipNumber[DRAMATTR_NUM]; 			//range:0~32
  
  UINT8		ChBRankNumber[DRAMATTR_NUM]; 			//range: 0~4
  UINT8		ChBDRAMChipDataWidth[DRAMATTR_NUM];		//8: x8 chip, 16: x16 chip
  UINT8		ChBDIMMNumber[DRAMATTR_NUM]; 			//range:0~2
  UINT8		ChBChipNumber[DRAMATTR_NUM]; 				//range:0~32
  
  UINT8		Twr[DRAMATTR_NUM]; 					
  UINT8		CL[DRAMATTR_NUM]; 					
  UINT8		CWL[DRAMATTR_NUM];                     
 // UINT8     CRC_RWCL;              
  UINT8     TRRD_S[DRAMATTR_NUM];
  UINT8     TCCD_S[DRAMATTR_NUM];
  UINT8     TWTR_S[DRAMATTR_NUM];
 // UINT8     PL;                    
  UINT8     CAL[DRAMATTR_NUM];                   //000:disable, 011:3T,0100: 4T,0101: 5T,110:6T,1000:8T
 
  UINT8		BASelect;

  UINT8		Dram1TCommandRate; 		//0: 2T command, 1:1T command
  UINT8		DramFreq;		
  										// 0~3: Reserved
										// 04: 400MHz, 05: 466MHz, 06: 533MHz,07: 600MHz
										// 08: 666MHz,09: 733MHz, 0A: 800MHz, 0B: 866MHz
										// 0C: 933MHz, 0D: 1000MHz, 0E: 1066MHz, 0F: 1133MHz, 10:1200MHz.
  UINT16	DramCycle;					//Unit: 0.001ns
  BOOLEAN	BurstLength8;				//0: On the fly, 1: BL8
  BOOLEAN	RegDimm;					//0: Not registered DIMM, 1: Registered DIMM
  UINT8     DramType; 
  BOOLEAN	ECCSupport;
  BOOLEAN	TSDIMM;					//0: Thermal Sensor is not supported, 1: Thermal Sensor is supported
  BOOLEAN   Dram3DS;                    //0: Not 3DS, 1: 3DS
  UINT8     WPREA;  //Write preamble	   
  UINT8     RPREA;  //read preamble
	    
  UINT8     DieCount;
  BOOLEAN	VRInterleave;				//0: disable VRInterleave,1: Enable VRInterleave
  BOOLEAN	PrimaryDqDimm[ASIA_MAX_SOCKETS];
  UINT8		CPUBusSpeed;		
  										//0001: 100MHz     0010: 133MHz	0011: 166MHz     0100: 200MHz	
										//0101: 266MHz     0110: 333MHz	0111: 352MHz     1000: 367MHz
										//1001: 384MHz     1010: 400MHz	1011: 433MHz     1100: 466MHz
										//1101: 500MHz     1110: 533MHz
  UINT64	PcieBaseAddress;  
  UINT8     CHX002_BUS_NUM;
  UINT8     AttrNo;
  UINT8		OutputDriver[DRAMATTR_NUM][ASIA_MAX_SOCKETS]; //00: RZQ/6, 01: RZQ/7
  UINT8		Rank1Mapping[DRAMATTR_NUM][ASIA_MAX_RANKS]; //00: Standard, 01: Mirror
  UINT32	RttNominal[DRAMATTR_NUM][ASIA_MAX_RANKS]; 
  										// 000: ODT Disabled, 001: RZQ/4, 010: RZQ/2
										// 011: RZQ/6, 100: RZQ/12, 101: RZQ/8
  UINT32 	RttWR[DRAMATTR_NUM][ASIA_MAX_RANKS]; 		//000: ODT Disabled, 001: RZQ/4, 010: RZQ/2
  UINT32    RttPark[DRAMATTR_NUM][ASIA_MAX_RANKS];
  UINT8		ChARawCardType[DRAMATTR_NUM];
  UINT8		ChBRawCardType[DRAMATTR_NUM];
  UINT8     ChipMode;
  UINT8     ModuleType;   				//02: UDIMM, 03: SO-DIMM. They are defined by SPD byte 3
  BOOLEAN	MixDimmType;
  ASIA_RANK_INFO		RankInfo[DRAMATTR_NUM][ASIA_MAX_RANKS];		
  IO_CALIBRATION_INFO		DramAutoCal[ASIA_MAX_RANKS][ASIA_MAX_BYTES];
  DQSI_IO_CALIBRATION_INFO_PerRank  DramAutoCal_DQSI[ASIA_MAX_RANKS];
  PER_BIT_DESKEW_INFO           DramPerBit[ASIA_MAX_BYTES][8];
  RX_VREF_INFO          RxVrefInfo[ASIA_MAX_RANKS];
  TX_VREF_INFO          TxVrefInfo[ASIA_MAX_RANKS];
  TX_VREF_DQO_INFO	TxVrefDQOInfo[ASIA_MAX_RANKS][ASIA_MAX_BYTES][TXVREFRANGEQLTOTAL];
  UINT8                 WLVL_Result[WLVL_Repeat_MAX][ASIA_MAX_BYTES];
  CHANNEL_INFO			Channel; 										
  ASIA_DRAM_CONFIGURATION    ConfigData;	//Setup data value 
  UINT8 		Dimm0Type[DRAMATTR_NUM];
  UINT8 		Dimm1Type[DRAMATTR_NUM];
  UINT8         Dimm2Type[DRAMATTR_NUM];
  UINT8         Dimm3Type[DRAMATTR_NUM];
  UINT8         DramFastBoot;   
  UINT32        EfuseData[2];

  SETTINGVal TNI_Value[8][9];
  SETTINGVal DQSI_Value[8][9];
  SETTINGVal DQSO_Value[2][9];
  SETTINGVal DQO_Value[2][9];
  UINT16 CHAOverlap;
  UINT16 CHBOverlap;
  UINT16 CHACoarseMode;
  UINT16 CHBCoarseMode;
  
} DRAM_ATTRIBUTE;

//DKS -20161220 add -s
typedef struct{
	UINT8   TxVrefRange;
	UINT8   TxVrefValue;
	UINT16  TxVrefValuePercent;
}TX_VREF_TBL;
//DKS -20161220 add -e



#define IO_DQSI_PHASE   (0)
#define IO_TNI_PHASE    (1)
#define IO_TNI_WHOLE_T  (2)
#define IO_DQO_PHASE    (3)
#define IO_DQO_WHOLE_T  (4)
#define IO_DQSO_PHASE   (5)
#define IO_DQSO_WHOLE_T (6)
#define IO_DQSO_WLVL    (7)

//used in DumpTXRX
#define IO_TNI          (0x07)
#define IO_DQSI         (0x08)
#define IO_DQO          (0x09)
#define IO_DQSO         (0x0A)
#define IO_MANUAL       (0x0B)
#define IO_RXVREF       (0x0C)
#define IO_TXVREF       (0x0D)
#define IO_WLVL			(0x0E)
#define IO_2D_ByDQSI    (0x0F)




#define IOCTL_MANUAL (0)
#define IOCTL_LOW    (1)
#define IOCTL_HIGH   (2)
#define IOCTL_CENTER (3)
#define IOCTL_LOWHIGH (4)

#define WRITE	TRUE
#define READ   FALSE
#define ALLBYTE 0xFF


VOID DumpD0F3(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
    );
VOID DumpD0F2(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
    );

VOID VDump_MTRR( IN EFI_PEI_SERVICES **PeiServices);

VOID DumpD0F3Perbit(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
    );


#define NVINFO_IO_VAR_NAME           L"IOTIMING"
#define NVINFO_DRAMINFO_VAR_NAME     L"DRAMINFOSAVE"

#define EFI_PEI_READ_ONLY_VARIABLE2_PPI_GUID \
  { 0x2ab86ef5, 0xecb5, 0x4134, { 0xb5, 0x56, 0x38, 0x54, 0xca, 0x1f, 0xe1, 0xb4 } }

#define EFI_PEI_READ_ONLY_VARIABLE_PPI_GUID \
  { 0x3cdc90c6, 0x13fb, 0x4a75, { 0x9e, 0x79, 0x59, 0xe9, 0xdd, 0x78, 0xb9, 0xfa } }

///
#endif //__DRAMINIT_H_
