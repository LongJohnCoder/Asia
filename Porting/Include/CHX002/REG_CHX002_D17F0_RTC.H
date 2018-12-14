//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		RTC					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D17F0_RTC_R090(A0) .doc(final)MOD_RTC.xls
#ifndef _CHX002_D17F0_RTC_H
#define _CHX002_D17F0_RTC_H
//CMOS
#define CMOS_SECONDS_REG		0x00	//SECONDS Register
    #define CMOS_SEC7			BIT7	//0/x/x/x SECONDS
    #define CMOS_SEC6			BIT6	//0/x/x/x SECONDS
    #define CMOS_SEC5			BIT5	//0/x/x/x SECONDS
    #define CMOS_SEC4			BIT4	//0/x/x/x SECONDS
    #define CMOS_SEC3			BIT3	//0/x/x/x SECONDS
    #define CMOS_SEC2			BIT2	//0/x/x/x SECONDS
    #define CMOS_SEC1			BIT1	//0/x/x/x SECONDS
    #define CMOS_SEC0			BIT0	//0/x/x/x SECONDS
#define CMOS_SECONDS_ALARM_REG		0x01	//SECONDS ALARM Register
    #define CMOS_SEC_ALM			0xFF	//0/x/x/x SECONDS ALARM
#define CMOS_MINUTES_REG		0x02	//MINUTES Register
    #define CMOS_MIN7			BIT7	//0/x/x/x MINUTES
    #define CMOS_MIN6			BIT6	//0/x/x/x MINUTES
    #define CMOS_MIN5			BIT5	//0/x/x/x MINUTES
    #define CMOS_MIN4			BIT4	//0/x/x/x MINUTES
    #define CMOS_MIN3			BIT3	//0/x/x/x MINUTES
    #define CMOS_MIN2			BIT2	//0/x/x/x MINUTES
    #define CMOS_MIN1			BIT1	//0/x/x/x MINUTES
    #define CMOS_MIN0			BIT0	//0/x/x/x MINUTES
#define CMOS_MINUTES_ALARM_REG		0x03	//MINUTES ALARM Register
    #define CMOS_MIN_ALM			0xFF	//0/x/x/X MINUTES Alarm
#define CMOS_HOURS_REG		0x04	//HOURS Register
    #define CMOS_HRS7			BIT7	//0/x/x/x HOURS
    #define CMOS_HRS6			BIT6	//0/x/x/x HOURS
    #define CMOS_HRS5			BIT5	//0/x/x/x HOURS
    #define CMOS_HRS4			BIT4	//0/x/x/x HOURS
    #define CMOS_HRS3			BIT3	//0/x/x/x HOURS
    #define CMOS_HRS2			BIT2	//0/x/x/x HOURS
    #define CMOS_HRS1			BIT1	//0/x/x/x HOURS
    #define CMOS_HRS0			BIT0	//0/x/x/x HOURS
#define CMOS_HOURS_ALARM_REG		0x05	//HOURS ALARM Register
    #define CMOS_HRS_ALM			0xFF	//0/x/x/x HOURS ALARM 
#define CMOS_DAY_OF_THE_WEEK_REG		0x06	//DAY of THE WEEK Register
    #define CMOS_DAY_WEK7			BIT7	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK6			BIT6	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK5			BIT5	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK4			BIT4	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK3			BIT3	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK2			BIT2	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK1			BIT1	//0/x/x/x Day of the Week
    #define CMOS_DAY_WEK0			BIT0	//1b/x/x/x Day of the Week
#define CMOS_DAY_OF_THE_MONTH_REG		0x07	//DAY of the MONTH Register
    #define CMOS_DAY_MON7			BIT7	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON6			BIT6	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON5			BIT5	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON4			BIT4	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON3			BIT3	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON2			BIT2	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON1			BIT1	//0/x/x/x Day of the Month
    #define CMOS_DAY_MON0			BIT0	//1b/x/x/x Day of the Month
#define CMOS_MONTH_REG		0x08	//MONTH Register
    #define CMOS_MON7			BIT7	//0/x/x/x MONTH
    #define CMOS_MON6			BIT6	//0/x/x/x MONTH
    #define CMOS_MON5			BIT5	//0/x/x/x MONTH
    #define CMOS_MON4			BIT4	//0/x/x/x MONTH
    #define CMOS_MON3			BIT3	//0/x/x/x MONTH
    #define CMOS_MON2			BIT2	//0/x/x/x MONTH
    #define CMOS_MON1			BIT1	//0/x/x/x MONTH
    #define CMOS_MON0			BIT0	//1b/x/x/x MONTH
#define CMOS_YEAR_REG		0x09	//YEAR Register
    #define CMOS_YRS7			BIT7	//0/x/x/x YEAR
    #define CMOS_YRS6			BIT6	//0/x/x/x YEAR
    #define CMOS_YRS5			BIT5	//0/x/x/x YEAR
    #define CMOS_YRS4			BIT4	//1b/x/x/x YEAR
    #define CMOS_YRS3			BIT3	//0/x/x/x YEAR
    #define CMOS_YRS2			BIT2	//1b/x/x/x YEAR
    #define CMOS_YRS1			BIT1	//0/x/x/x YEAR
    #define CMOS_YRS0			BIT0	//0/x/x/x YEAR
#define CMOS_REG_A		0x0A	//Register A
    #define CMOS_UIP			BIT7	//0/x/x/x Update in Progress (UIP)
    #define CMOS_DV			(BIT4 + BIT5 + BIT6)	//0/x/x/x DV0, DV1, DV2
    #define CMOS_RS			0xF	//0/x/x/x RS3, RS2, RS1, RS0
#define CMOS_REG_B		0x0B	//Register B
    #define CMOS_SET			BIT7	//0/x/x/x SET 
    #define CMOS_PIE			BIT6	//0/x/x/x Periodic Interrupt Enable (PIE)
    #define CMOS_AIE			BIT5	//0/x/x/x Alarm Interrupt Enable (AIE)
    #define CMOS_UIE			BIT4	//0/x/x/x Update Ended Interrupt Enable (UIE)
    #define CMOS_SQWE			BIT3	//0/x/x/x Square Wave Enable (SQWE)
    #define CMOS_DM			BIT2	//0/x/x/x Data Mode (DM)
    #define CMOS_HRSM			BIT1	//0/x/x/x HRS 24/12 Mode
    #define CMOS_RB_REV0			BIT0	//0/R/x/x Reserved
#define CMOS_REG_C		0x0C	//Register C
    #define CMOS_IRQF			BIT7	//0/R/x/x Interrupt Request Flag (IRQF)
    #define CMOS_PF			BIT6	//0/R/x/x Periodic Interrupt Flag (PF)
    #define CMOS_AF			BIT5	//0/R/x/x Alarm Interrupt Flag (AF)
    #define CMOS_UF			BIT4	//0/R/x/x Update Ended Interrupt Flag (UF)
    #define CMOS_RC_REV3_0			0xF	//0/R/x/x Reserved
#define CMOS_REG_D		0x0D	//Register D
    #define CMOS_VRT			BIT7	//1b/R/x/x VRT
    #define CMOS_RD_REV6_0			0x7F	//0/R/x/x Reserved
#define CMOS_DAY_OF_THE_MONTH_ALARM_REG		0x7D	//Day of the Month Alarm Register
    #define CMOS_DAYMON_ALM			0xFF	//01h/x/X/x Day of the Month Alarm 
#define CMOS_MONTH_ALARM_REG		0x7E	//Month Alarm Register
    #define CMOS_MON_ALM			0xFF	//01h/x/x/X Month Alarm
#define CMOS_CENTURY_REG		0x7F	//Century Register
    #define CMOS_CEN7			BIT7	//0/x/x/x Century 
    #define CMOS_CEN6			BIT6	//0/x/x/x Century 
    #define CMOS_CEN5			BIT5	//1b/x/x/x Century 
    #define CMOS_CEN4			BIT4	//0/x/x/x Century 
    #define CMOS_CEN3			BIT3	//0/x/x/x Century 
    #define CMOS_CEN2			BIT2	//0/x/x/x Century 
    #define CMOS_CEN1			BIT1	//0/x/x/x Century 
    #define CMOS_CEN0			BIT0	//0/x/x/x Century 
#endif
