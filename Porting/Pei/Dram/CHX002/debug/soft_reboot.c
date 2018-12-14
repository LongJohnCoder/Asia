//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "PeiLib.h"
#include "AsiaIoLib.h"

UINT8 DecToBCD(UINT8 Dec)
{
	UINT8 FirstDigit = Dec % 10;
	UINT8 SecondDigit = Dec / 10;

	return (SecondDigit << 4) + FirstDigit;
}

UINT8 BCDToDec(UINT8 BCD)
{
	UINT8 FirstDigit = BCD & 0xf;
	UINT8 SecondDigit = BCD >> 4;;

	return SecondDigit * 10  + FirstDigit;
}

void WriteRtcIndex(IN UINT8 Index, IN UINT8 Value)
{
	AsiaIoWrite8(0x70,Index);
	if (Index <= 9 ) Value = DecToBCD(Value);
	// Write Register
	AsiaIoWrite8(0x71,Value);
}


UINT8 ReadRtcIndex(IN UINT8 Index)
{
	UINT8 volatile Value;

	// Check if Data Time is valid
	if(Index <= 9) do {
		AsiaIoWrite8(0x70, 0x0A);
		Value = AsiaIoRead8(0x71);	
	} while (Value & 0x80); 
	AsiaIoWrite8(0x70, Index);
	// Read register
	Value = AsiaIoRead8(0x71);               
	if (Index <= 9) Value = BCDToDec(Value);	
	return (UINT8)Value;
}

void InitRTCWakeup( IN EFI_TIME     *Time)
{	
	Time->Hour = ReadRtcIndex(0x4);
	Time->Minute = ReadRtcIndex(0x2);
	Time->Second = ReadRtcIndex(0x0);  
}


void SetWakeupTimeKO ( IN EFI_TIME     *Time)
{  
	UINT8 Value;
	WriteRtcIndex(0x5,Time->Hour);
	WriteRtcIndex(0x3,Time->Minute);
	WriteRtcIndex(0x1,Time->Second);
	//Set Enable
	Value = ReadRtcIndex(0xB);
	Value |= 1 << 5;
	Value &= 0xEF; //3456-05-NIH-22
	WriteRtcIndex(0xB,Value);
}

UINT8 CMOSData_In (UINT8 index)
{
	AsiaIoWrite8(0x70, index);
	return AsiaIoRead8(0x71);
}

void CMOSData_Out (UINT8 index, UINT8 data)
{
	AsiaIoWrite8(0x70, index);
	AsiaIoWrite8(0x71, data);
}

void Power_On_Off (IN EFI_PEI_SERVICES **PeiServices)
{
	EFI_TIME Time;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "Set RTC and Sleep IOtiming\n"));

	//Get current Timer
	InitRTCWakeup(&Time);

	//After 2 second wakeup
	Time.Second += 20;
	//Check the second overflow
	if(Time.Second >= 60)
	{
		Time.Second -= 60;
		Time.Minute++;
	}

	//Check the minute overflow
	if(Time.Minute >= 60)
	{
		Time.Minute -= 60;
		Time.Hour++;
	}                 
	//Set Alarm
	SetWakeupTimeKO(&Time);

	//Clear RTC PM1 status
	AsiaIoWrite16(0x800 , ( AsiaIoRead8(0x800) | (1 << 10) ));
	AsiaIoWrite16(0x800 , ( AsiaIoRead8(0x800) | (1 << 15) )); //bit15//

	//set RTC_EN bit in PM1_EN to wake up from the alarm
	AsiaIoWrite8(0x803, ( AsiaIoRead8(0x803) | (1 << 2) ));

	PEI_DEBUG((PeiServices, EFI_D_INFO,  "H=%2X\n ", CMOSData_In (0x04)));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "M=%2X \n", CMOSData_In (0x02)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "S=%2X \n", CMOSData_In (0x00)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "H_a_2=%2X \n", CMOSData_In (0x05)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "M_a=%2X \n", CMOSData_In (0x03)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "S_a=%2X \n", CMOSData_In (0x01)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "AIE(0xB)=%2X \n", CMOSData_In (0x0B)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "Koen0x801=%2X\n ", AsiaIoRead8(0x801)));
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "Koen0x803=%2X \n", AsiaIoRead8(0x803)));

	AsiaIoWrite8(0x84, 0x04);
	//S4 second, execute for 4 mins
	AsiaIoWrite8(0x805, 0x28);

	//pci reset
	//AsiaIoWrite8(0xcf9, 0x06);
	PEI_DEBUG((PeiServices, EFI_D_INFO,  "Koentest \n"));
}
