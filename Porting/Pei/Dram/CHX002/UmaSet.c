//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "DramInit.h"
#include "UmaSet.h"

void OpenUMApath()
{
	//Enable IO Cycle
	AsiaPciModify8(CHX002_EUMA|0x04, BIT0, BIT0);
	return;
}
void CloseUMApath()
{
	AsiaPciModify8(CHX002_EUMA|0x04, BIT0, 0x00);
	return;
}
void EUMAPowerDown()
{
	OpenUMApath();

	// VGA Enable, 3C3[0]=1, 3C2 = 67H
	AsiaIoModify8(0x03C3, 0x00, 0x01);
	AsiaIoWrite8(0x3C2, 0x67);

	// Unlock accessing of IO space.
	AsiaIoWrite16(0x3D4, 0x4838);//access CR registers CR2D~3F
	AsiaIoWrite16(0x3D4, 0xa539);//access CR registers higher than CR40
	AsiaIoWrite16(0x3C4, 0x0608);//accessing SR registers higher than SR09

	// Power Down DCLK2 PLL, SR0B[0]=1
	AsiaIoWrite8(0x3C4, 0x0B);
	AsiaIoModify8(0x3C5, 0x01,0x01);

	// SR1C[4:2] = 111b
	AsiaIoWrite8(0x3C4, 0x1C);
	AsiaIoModify8(0x3C5, 0x1C,0x1C);

	// SR1D[6:3,0] = 11111b
	AsiaIoWrite8(0x3C4, 0x1D);
	AsiaIoModify8(0x3C5, 0x79,0x79);

	// SR1E[4:0] = 11111b
	AsiaIoWrite8(0x3C4, 0x1E);
	AsiaIoModify8(0x3C5, 0x1F,0x1F);

	// Power Down DCLK1 PLL, EOCLK PLL, EICLK PLL, CRFC_B[2:0]=7
	//; To access CRC2_B/CRC2_C, must set SR2a[1:3,6]=0010b ; {sr2A[7],sr2A[3]} 01: Select CR Registers Alternate group ��B�� (CRxx_B) for DIU from CR92_B to CRFF_B.
	AsiaIoWrite8(0x3C4, 0x2A);
	AsiaIoModify8(0x3C5, 0x08,0x08);

	// CRFC_B[2:0]= 111b
	AsiaIoWrite8(0x3D4, 0xFC);
	AsiaIoModify8(0x3D5, 0x07,0x07);

	// CRF2_B[2] = 0b
	AsiaIoWrite8(0x3D4, 0xF2);
	AsiaIoModify8(0x3D5, 0x04,0x00);

	// To access standard CR/SR, set SR26=0 and SR2A=0
	AsiaIoWrite16(0x3C4, 0x0026);
	AsiaIoWrite16(0x3C4, 0x002A);

	// Disable 3C3[0]
	AsiaIoModify8(0x3C3,0x01,0);

	CloseUMApath();

	return;
}

/* Return value will be  64 128 256 512 1024 */
UINT16 GetRealUmaSize(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN ASIA_NB_CONFIGURATION *SetupData
    )
{
	UINT8 D8;
	// UINT8 RankIdx8;
	UINT16 DramSize = 0, RealUmaSize;
	// UINT16 MaxUmaSize;
    UINT64 Address;
	
	if(SetupData->UMAEn){
        
		// Get FB_Size user want to set = RealUmaSize
		D8= DramAttr->ConfigData.VGAShareMemory;
		if(DramAttr->ConfigData.VGAShareMemory == VGA_SHARE_MEM_AUTO){
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ENDING_ADR);
	    	DramSize = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_REND7_37_24) << 4;
			if(DramSize >= 4096)
				D8 = 4;//ex. value=1 means 2^6=64, value=2 means 2^7=128, etc.
			else
				D8 = 3;
		}

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "DramSize= 0x%08x D8= 0x%08x\n", DramSize,D8));
		RealUmaSize = 1;
		RealUmaSize <<= (D8+5);
	        
		// Get FB_Size system can set = MaxUmaSize
		/*
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ENDING_ADR);
	    DramSize = (AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)&D0F3_REND7_37_24) << 4;
	        
		if (DramSize < 512)         
			MaxUmaSize = 64;
		else if (DramSize < 1024)    
			MaxUmaSize = 128;
		else if (DramSize < 2048)    
			MaxUmaSize = 256;
		else if (DramSize < 4096)    
			MaxUmaSize = 512;
		else 
			MaxUmaSize = 1024;
	        
		if (RealUmaSize > MaxUmaSize) 
			RealUmaSize = MaxUmaSize;
		*/
		return RealUmaSize;
	}
	else{
		return 0;
	}
}

EFI_STATUS GetDramInfoForUma(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
    )
{
	AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0xFF, 0x0);

	if((DramAttr->RankPresent[DramAttr->AttrNo]&0x0f)&&(DramAttr->RankPresent[DramAttr->AttrNo]&0xf0))//DIMMs on two channel
	{	
		//Dual Channel 0x4F[0] = 1
		AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0x01, 0x01);	
		
		if(DramAttr->ConfigData.VRIntlv==0&&DramAttr->VRInterleave)
		{
			//support non-snoop path 0x4F[2] = 0		
			AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0x04, 0x0);//support both snoop/non-snoop path
		}
		else
		{
			//only support snoop path 0x4F[2] = 1	
			AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0x04, 0x04);//only support snoop path
		}
	}
	else
	{
		//Single Channel 0x4F[0] = 0
		AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0x01, 0x0);	
		//support non-snoop path 0x4F[2] = 0
		AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0x04, 0x0);//support both snoop/non-snoop path
	}
	
	//Interleave Enable 0x4F[1] = 0
	AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_4+3), 0x02, ((~(UINT8)DramAttr->VRInterleave)&0x01) << 1);

	return EFI_SUCCESS;
}

EFI_STATUS UmaEnable(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN ASIA_NB_CONFIGURATION *SetupData
	)
{

	UINT16 Value;
	UINT16 RealUmaSize;//(unit of MB)
    UINT64 Address;
	UINT32 DVADTop = 0;//(unit of MB)
	UINT16 Temp16 = 0;

	 
	RealUmaSize = GetRealUmaSize(PeiServices, DramAttr, SetupData);
    
	switch (RealUmaSize){
		case 64:
			Value = D0F3_RFBSZ_64M;
			break;
		case 128:
			Value = D0F3_RFBSZ_128M;
			break;
		case 256:
			Value = D0F3_RFBSZ_256M;
			break;
		case 512:
			Value = D0F3_RFBSZ_512M;
			break;
		default:
			return EFI_INVALID_PARAMETER;
	}

	//Enable Internal GFX & Set frame buffer size
	//RX154[7] & RX154[6:4]
 	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RGFXEN|D0F3_RFBSZ_2_0, D0F3_RGFXEN|Value);

	//Set RFBBS[39:21]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL);
	Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RFBBS_35_21;
		
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	DVADTop = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RFBBS_39_36;

	DVADTop = (DVADTop << 16)|Temp16;
	DVADTop = DVADTop - RealUmaSize;	
 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFBBS_35_21, (UINT16)(DVADTop & D0F3_RFBBS_35_21));  
	
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RFBBS_39_36, (UINT16)(DVADTop >> 16));
	
    //RX1F8[5]
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RVGAEN, D0F3_RVGAEN);
	
/*
	OpenUMApath();

	// scratch register setting
	// VGA Enable, 3C3[0]=1 (MM850C[1])
	// Enable Video Subsystem
	AsiaIoModify8(0x03C3, 0x00, 0x01);
	AsiaIoWrite8(0x3c2, 0x67);

	// Unlock accessing of IO space.
	// Write 3d4 = 0x38, 3d5= 0x48
	AsiaIoWrite16(0x3d4, 0x4838);
	AsiaIoWrite16(0x3d4, 0xa539);
	AsiaIoWrite16(0x3c4, 0x0608);

	// To access CRxx_C, set SR2A[6,3:1]=0010b
	AsiaIoWrite16(0x3C4, 0x042A);

	// set SSID and SVID
	// CR88_C[3:0] = 0
	AsiaIoWrite8(0x3D4, 0x88);
	AsiaIoModify8(0x3D5, 0x0F, 0x00);
	// SSID{CR87_C, CR86_C}, SVID{CR85_C, CR84_C} = 3A01, 1106
	AsiaIoWrite16(0x3d4, 0x3A87);
	AsiaIoWrite16(0x3D4, 0x0186);
	AsiaIoWrite16(0x3D4, 0x1185);
	AsiaIoWrite16(0x3D4, 0x0684);

	//To access standard CR/SR, set SR26=0 and SR2A=0
	AsiaIoWrite16(0x3C4, 0x0026);
	AsiaIoWrite16(0x3C4, 0x002A);

	//Set 0x3C3[0]=0, fix S3 issue that ECK is wrong when S3 resume 
	//When finish config the UMA register, we should clear this bit to disable chip function
	AsiaIoModify8(0x03C3, 0x01, 0x00);
	
	CloseUMApath();



	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RVGAEN, D0F3_RVGAEN);
  */
	return EFI_SUCCESS;
}

EFI_STATUS UmaEnableS3(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN ASIA_NB_CONFIGURATION *SetupData
	)
{

    UINT64 Address;
	
	//RX1F8[5]
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RVGAEN, D0F3_RVGAEN);

	return EFI_SUCCESS;
}

EFI_STATUS UmaDisable(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN ASIA_NB_CONFIGURATION *SetupData
	)
{
    UINT64 Address;
	
	EUMAPowerDown();
    //Disable UMA
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RGFXEN|D0F3_RFBSZ_2_0, 0);	

    //disable UMA IO port
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RVGAEN, 0);

	return EFI_SUCCESS;
}

