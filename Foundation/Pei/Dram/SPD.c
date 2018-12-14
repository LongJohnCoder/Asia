//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "Pei.h"
#include "spd.h"
/*===================================================================
Function   : Read_SPD()
Precondition :
Input      :  PeiServices:pointer point to pointer that point to _EFI_PEI_SERVICES structor
		  pCPUPPI,
		  pSMBusPPI,
		  Slot,
		  Index
Output     : UINT8
Purpose    :
Reference  : rewrited by Jasonzhao at 2006-9-29
===================================================================*/

EFI_STATUS ReadSPDByte(IN EFI_PEI_SERVICES **PeiServices,
                       IN PEI_SMBUS_PPI *pSMBusPPI,
                       IN UINT8 Slot,
                       IN UINT16 Index,
                       OUT UINT8 *Val)
{
    EFI_STATUS Status = EFI_NOT_READY;
    EFI_SMBUS_DEVICE_COMMAND SMBCMD;
    EFI_SMBUS_DEVICE_ADDRESS SlaveAddress;
    UINTN SMBDataLength=1;

    if (NULL == Val)
        return EFI_INVALID_PARAMETER;
    *Val = 0;
    /*
    Channel A address  0x50
    Channel A address  0x51
    Channel B address  0x52
    Channel B address  0x53
    */
    switch (Slot)
    {
    case 0:
        SlaveAddress.SmbusDeviceAddress = SMBUS_ADDR_CH_A_1 >> 1;
        break;

    case 1:
        SlaveAddress.SmbusDeviceAddress = SMBUS_ADDR_CH_A_2 >> 1;
        break;

    case 2:
        SlaveAddress.SmbusDeviceAddress = SMBUS_ADDR_CH_B_1 >> 1;
        break;

    case 3:
        SlaveAddress.SmbusDeviceAddress = SMBUS_ADDR_CH_B_2 >> 1;
        break;

    default:
        return EFI_INVALID_PARAMETER;
    }
    SMBCMD=Index;
    Status= pSMBusPPI->Execute(PeiServices,pSMBusPPI,SlaveAddress,SMBCMD,EfiSmbusReadByte,0,&SMBDataLength,Val);

    return Status;
}

EFI_STATUS GetSPDData(IN EFI_PEI_SERVICES **PeiServices,
                      IN PEI_SMBUS_PPI *pSMBusPPI,
                      IN UINT8 Slot,
                      IN UINT16 Length,
                      OUT UINT8 *Buf)
{
    EFI_STATUS Status = EFI_NOT_READY;
    EFI_SMBUS_DEVICE_ADDRESS    SMAddress;
    UINT8 Val;
    UINT16 i;
	UINTN Bank0=0;	   
	UINTN Bank1=1;
	UINTN Len=1;
	UINTN ReadBank00=0;
	UINTN ReadBank01=0;
	UINTN ReadBank10=0;
	UINTN ReadBank11=0;

    if (1 > Length || NULL == Buf)
        return EFI_INVALID_PARAMETER;

    if (Length <= 256)
    {
        for (i=0; i< Length; i++)
        {
            Status = ReadSPDByte(PeiServices,pSMBusPPI,Slot,i,&Val);
            if (EFI_SUCCESS != Status)
    		//{
    			//if(i>0x20)
    				//Status = EFI_SUCCESS;
                         break;
    		//}
            //PEI_DEBUG(((*PeiServices),"Get SPD Data Byte%d = %x \r", i, Val));
            *(Buf+i) = Val;
        }
    }
    else
    {
        // Select bank 0.
        //SMAddress.SmbusDeviceAddress = 0x6C>>1;
        //Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusQuickWrite, 0, NULL, 0);	
		SMAddress.SmbusDeviceAddress = 0x6D>>1;
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusReadBankAddr, 0, &Len, (void *)&ReadBank00);  
		
		SMAddress.SmbusDeviceAddress = 0x6C>>1;
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusSetBankAddr, 0, &Len, (void *)&Bank0);

		SMAddress.SmbusDeviceAddress = 0x6D>>1;
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusReadBankAddr, 0, &Len, (void *)&ReadBank01);  

        for (i = 0; i < 256; i++)
        {
            Status = ReadSPDByte(PeiServices,pSMBusPPI,Slot,i,&Val);
            if (EFI_SUCCESS != Status)
                break;
            *(Buf+i) = Val;
        }

        // Select bank 1.
        SMAddress.SmbusDeviceAddress = 0x6D>>1;
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusReadBankAddr, 0, &Len, (void *)&ReadBank10);  
		
        SMAddress.SmbusDeviceAddress = 0x6E>>1;
       // Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusQuickWrite, 0, NULL, 0);
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusSetBankAddr, 0, &Len, (void *)&Bank1);

		SMAddress.SmbusDeviceAddress = 0x6D>>1;
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SMAddress, 0, EfiSmbusReadBankAddr, 0, &Len, (void *)&ReadBank11);  

		for (i = 0; i < (Length - 256); i++)
        {
            Status = ReadSPDByte(PeiServices,pSMBusPPI,Slot,i,&Val);
            if (EFI_SUCCESS != Status)
                break;
            *(Buf+256+i) = Val;
        }
    }
    
    return Status;
}
