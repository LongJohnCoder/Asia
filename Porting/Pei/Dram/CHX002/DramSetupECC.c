//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Pei.h"
#include "Draminit.h"
#include "PeiLib.h"
#include "DramSetupECC.h"

#define Address_1MB 0x100000
#define Address_4GB 0x100000000

//extern void Raida(IN EFI_PEI_SERVICES **PeiServices,
//	         UINT64 StartAddr,
//	         UINT64 EndAddr);
void Raida(IN EFI_PEI_SERVICES **PeiServices,
			IN DRAM_ATTRIBUTE *DramAttr,
	         UINT64 StartAddr,
	         UINT64 EndAddr);

VOID RW_Engine_DealCore(EFI_PEI_SERVICES **PeiServices, DRAM_ATTRIBUTE *DramAttr, UINT64 BeginAddress, UINT32 Burstlength);

VOID ECCErrorInterruptControl(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
);

VOID ECCScrub(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
);

VOID GetChannelSize(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	UINT16 *CHATotalSize,
	UINT16 *CHBTotalSize
);


VOID RW_Engine_DealCore(EFI_PEI_SERVICES **PeiServices, DRAM_ATTRIBUTE *DramAttr, UINT64 BeginAddress, UINT32 Burstlength)
{
	UINT64 Address;
	UINT8  Index;
	UINT64 BeginAddressTmp;
	
	//Set RSRW_ADDR[37:3] for start address
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_ADDR[37:3] for start address!!!\r\n")); 
	BeginAddressTmp = RShiftU64(BeginAddress, 3);
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(BeginAddressTmp, 8 * Index) & 0xFF));
	}

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z4);
	AsiaPcieModify8(0XE0000000, Address, D0F3_RSRW_ADDR_37_35, (UINT8)(RShiftU64(BeginAddress, 35) & 0x07));




	//Set RSRW_LENGTH[31:0] for burst length
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSRW_LENGTH[31:0] for burst length!!!\r\n"));
	for (Index = 0; Index < 4; Index++)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, (UINT8)(RShiftU64(Burstlength, 8 * Index) & 0xFF));
	}

	



	//Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Set RSDATAPAT0[71:0], RSDATAPAT1[71:0], RSDATAPAT2[71:0], RSDATAPAT3[71:0], RSDATAPAT4[71:0], RSDATAPAT5[71:0], RSDATAPAT6[71:0], RSDATAPAT7[71:0] for write data pattern!!!\r\n"));
	for (Index = 0; Index < 8; Index++)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x5A);
		
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x3C);

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x2D);

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x4B);

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x87);

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x96);

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x2E);

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE + Index);
		AsiaPcieWrite8(0XE0000000, Address, 0x3F);
	}





	//Trigger reg_RSWR to active DRAMCA write engine
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Trigger reg_RSWR to active DRAMCA write engine!!!\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSWR, D0F3_REG_RSWR);

		//Wait for reg_RSWR being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT0)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSWR done!!!\r\n"));
	}





	//Trigger  reg_RSWR_CHB to active DRAMCB write engine
	if ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0)
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger  reg_RSWR_CHB to active DRAMCB write engine!!!\r\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Loading: "));
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE);
		AsiaPcieModify8(0XE0000000, Address, D0F3_REG_RSWR_CHB, D0F3_REG_RSWR_CHB);

		//Wait for reg_RSWR_CHB being cleared by HW
		while (AsiaPcieRead8(0XE0000000, Address) & BIT2)
		{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\r\nTrigger reg_RSWR_CHB done!!!\r\n"));
	}
}


EFI_STATUS DramSetupECC(
	IN EFI_PEI_SERVICES **PeiServices,
	IN PEI_CPU_IO_PPI *pCPUPPI,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr
)
{
	if(DramAttr->ECCSupport)
	{
		if(DramAttr->ConfigData.DRAMECC)
		{
			AsiaIoWrite8(0x80, 0x29);
			ClearMem(PeiServices, DramAttr);
			ECCScrub(PeiServices, DramAttr);
			ECCErrorInterruptControl(PeiServices, DramAttr);
		}
	}
	else
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC: One of the dimms doesn't support ECC.\n"));

	   
	return EFI_SUCCESS;
}

VOID ECCErrorInterruptControl(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
)
{
	UINT64 Address;
	 
	if(DramAttr->ConfigData.DRAMErrControl == ECC_DISABLE)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (D0F3_RSUE|D0F3_RSCE), 0);
	}
	else if(DramAttr->ConfigData.DRAMErrControl == ECC_UNCORRECTABLE)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (D0F3_RSUE|D0F3_RSCE), D0F3_RSUE);

		//LGE20181113 Enable SMI ,NMI,SCI Report
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RETRY_ERR_ENABLE_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_SMI_SEFS | D0F3_RDRAMC_SMI_MEFS, D0F3_RDRAMC_SMI_MEFS);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_NMI_SEFS | D0F3_RDRAMC_NMI_MEFS, D0F3_RDRAMC_NMI_MEFS);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_SCI_SEFS | D0F3_RDRAMC_SCI_MEFS, D0F3_RDRAMC_SCI_MEFS);
	}
	else if(DramAttr->ConfigData.DRAMErrControl == ECC_CORRECTABLE)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (D0F3_RSUE|D0F3_RSCE), D0F3_RSCE);

		//LGE20181113 Enable SMI ,NMI,SCI Report
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RETRY_ERR_ENABLE_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_SMI_SEFS | D0F3_RDRAMC_SMI_MEFS, D0F3_RDRAMC_SMI_SEFS);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_NMI_SEFS | D0F3_RDRAMC_NMI_MEFS, D0F3_RDRAMC_NMI_SEFS);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_SCI_SEFS | D0F3_RDRAMC_SCI_MEFS, D0F3_RDRAMC_SCI_SEFS);
	}
	else if(DramAttr->ConfigData.DRAMErrControl == ECC_BOTH)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, (D0F3_RSUE|D0F3_RSCE), (D0F3_RSUE|D0F3_RSCE));

		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_RETRY_ERR_ENABLE_CTL);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_SMI_SEFS | D0F3_RDRAMC_SMI_MEFS, D0F3_RDRAMC_SMI_SEFS | D0F3_RDRAMC_SMI_MEFS);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_NMI_SEFS | D0F3_RDRAMC_NMI_MEFS, D0F3_RDRAMC_NMI_SEFS | D0F3_RDRAMC_NMI_MEFS);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address,D0F3_RDRAMC_SCI_SEFS | D0F3_RDRAMC_SCI_MEFS, D0F3_RDRAMC_SCI_SEFS | D0F3_RDRAMC_SCI_MEFS);
	}
}


void ClearMem(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
)
{

	UINT32 i, j, Buf;
	UINT64 Address;
	UINT32 PciStart;
	UINT64 DramEnd;
	UINT32 DvadLimit,DvadLimitSave;//uinit of M
	UINT32 MEM_ENTSave;
	UINT32 shadow_reg_save;
	UINT8  shadow_reg_save1;
	UINT32 UmaSave,UMAsize,UmaFBbaseSave;
	UINT8  SMMSave;	
	UINT32 RtopASave;
	UMAsize=0;
	MEM_ENTSave=0;
	RtopASave=0;
	DvadLimitSave=0;
	DvadLimit=0;
	UmaFBbaseSave=0;
	//save C-F seg shadow 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_C_D_E_F_SEG);
	shadow_reg_save = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
    //save A-B seg shadow
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_VGA_DECODING); 
	shadow_reg_save1 = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address);
	//set A-F seg shadow to RAM
    //A B seg
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_VGA_DECODING);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ABSEG_SEL, BIT1);
	//C seg
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_C_D_E_F_SEG);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0xFF, 0xFF);
    //D seg 
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_C_D_E_F_SEG + 1);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0xFF, 0xFF);
	//E seg
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_C_D_E_F_SEG + 2);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0xFF, 0xFF);
	//F seg
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_C_D_E_F_SEG + 3);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, 0x03, 0x03);

	//force enable RAIDA0
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address,	D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN,
	D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN);


	//Save UMA setting
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	UmaSave = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & (D0F3_RGFXEN|D0F3_RFBSZ_2_0);
//	UmaSave=0xb00000;

//	PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  UmaSave:%8x\n",UmaSave));
	if (UmaSave&D0F3_RFBSZ_2_0){
	switch(UmaSave&D0F3_RFBSZ_2_0){
		case 0x0010:
			UMAsize=0x40000;
			break;
		case 0x0020:
			UMAsize=0x80000;
			break;	
		case 0x0030:
			UMAsize=0x100000;
			break;	
		case 0x0040:
			UMAsize=0x200000;
			break;	
		case 0x0050:
			UMAsize=0x8000;
			break;	
		case 0x0060:
			UMAsize=0x10000;
			break;	
		case 0x0070:
			UMAsize=0x20000;
			break;		
		default:
			UMAsize=0x100000;			
			break;
		}

		}
	
	//Disable UMA
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F3_RGFXEN|D0F3_RFBSZ_2_0, 0x00);

	
	//Save Top SMM setting
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_SMM);
	SMMSave = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address) & D0F2_RTSMMEN;	

	//Disable SMM
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F2_RTSMMEN, 0);
	

	//Set ECC Status
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, (D0F3_RSUE_STATUS+D0F3_RSCE_STATUS), (D0F3_RSUE_STATUS+D0F3_RSCE_STATUS));

	

	//VDump_MTRR(PeiServices);
	
	//get Pci Start address
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
    PciStart = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);	
//	PciStart=0xe000;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  PCIStart:%8x\n",PciStart));

	PciStart = (PciStart & D0F2_RLOWTOPA_31_20);
	PciStart >>= 4;

	// if(DramAttr->ConfigData.DRAMECC)  //cleared by georgexue according to LiGe's suggestion.
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC: Clear Memory 0~%08xMB\n", PciStart));
		
		//Range: 0~16MB: Clear Memory by setting
		for(i = 0; i < 16; i++)
		{
			Buf = i * Address_1MB;
			for(j = Buf; j < Buf + Address_1MB; j += 4)
			{
				AsiaMemoryWrite32(j, 0x00);
			}
			if(i % 10 == 0)
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		}

		//Range: 16MB~PciStart
		Raida(PeiServices,DramAttr, 16*Address_1MB, PciStart*Address_1MB);
//		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
		//Update temp RtopA
		
			if (UmaSave&D0F3_RFBSZ_2_0){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
		RtopASave = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F2_RTOPA_39_20;
//		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL);
//		UmaFBbaseSave = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F3_RFBBS_39_21;
//		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RFBBS_39_21, UmaFBbaseSave+UMAsize/0x1000);
//		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDFBAEN, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  After UmaFBbase:%8x\n",AsiaPcieRead32(DramAttr->PcieBaseAddress, Address)));	
		
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F2_RTOPA_LOCK, 0x00);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address,D0F2_RTOPA_39_20, RtopASave+UMAsize);
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
		DvadLimitSave=AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F2_RDVAD1LIMIT_39_28;
//		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  DvadLimitSave:%8x\n",DvadLimitSave));

		//Base = LowTopA - 4GB	 	
		//Limit = RTOPA - 1
		DvadLimit = RtopASave+UMAsize- 0x100000; //unit of MB
//		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  DvadLimit:%8x\n",DvadLimit));	
//		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, D0F2_RDVAD1NXM);
		
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28, DvadLimit );
//		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 0);
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
		MEM_ENTSave=AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F2_RSVAD_ME1LADDR_39_28;
		
		for(i = 0; i < 19; i++){
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address+4*i, D0F2_RSVAD_ME1LADDR_39_28, MEM_ENTSave+UMAsize/0x100000);
			}


				}
				
//		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
//		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  RTopA:%8x\n",AsiaPcieRead32(DramAttr->PcieBaseAddress, Address)));
			
//		PEI_DEBUG((PeiServices, EFI_D_ERROR,"CKS  LowtopA:%8x \n",AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));
#if 1
		//Range: 4GB~End
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
        DramEnd = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F2_RTOPA_39_20;				
//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "before DramEnd:%4x \n", DramEnd));
		DramEnd = RShiftU64(DramEnd, 12);    
//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "After DramEnd:%4x \n", DramEnd));
//		DramEnd=0x4200;
		if(DramEnd > 4096){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC: Clear Memory 4GB~%dMB\n", DramEnd));
			Raida(PeiServices,DramAttr, Address_4GB, MultU64x32(DramEnd, Address_1MB));
		}
#endif		
	}
	//else
	//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "ECC: Don't Clear Memory\n"));   //cleared by georgexue according to LiGe's suggestion.

	//Keep clear the error status until no errors are generated
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	while(AsiaPcieRead8(DramAttr->PcieBaseAddress, Address) & (D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA))
	{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "*"));
		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA, D0F3_RMEFS_CHB|D0F3_RSEFS_CHB|D0F3_RMEFS_CHA|D0F3_RSEFS_CHA);
	};
  
	//Restore SMM setting
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_SMM);
	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F2_RTSMMEN, SMMSave);
	if (UmaSave&D0F3_RFBSZ_2_0){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28,DvadLimitSave);
		
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_39_20,RtopASave);
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_LOCK,D0F2_RTOPA_LOCK);
//	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL);
//	UmaFBbaseSave = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F3_RFBBS_39_21;
//	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RFBBS_39_21, UmaFBbaseSave);
//			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F3_RDFBAEN, D0F3_RDFBAEN);
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
//		MEM_ENTSave=AsiaPcieRead32(DramAttr->PcieBaseAddress, Address) & D0F2_RSVAD_ME1LADDR_39_28;
		
		for(i = 0; i < 19; i++){
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address+4*i, D0F2_RSVAD_ME1LADDR_39_28, MEM_ENTSave);
			}

		} 
	//Restore UMA setting
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RGFXEN|D0F3_RFBSZ_2_0, (UINT16)UmaSave);
   
	//restore A-F seg shadow
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_C_D_E_F_SEG);
	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, shadow_reg_save);
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_VGA_DECODING);
	AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, shadow_reg_save1);
      
}

VOID ECCScrub(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr
)
{
	UINT64 Address;
	
	UINT16 CHATotalSize = 0;
	UINT16 CHBTotalSize = 0;
	UINT16 TotalSize = 0;     //Uint 64MB

	UINT16 CHAAddrBegin = 0, CHAAddrEnd = 0;
	UINT16 CHBAddrBegin = 0, CHBAddrEnd = 0;   //Uint 64MB

	
	if(DramAttr->ConfigData.EccRetry)  //ECC Demand Scrub mode
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN, D0F3_RERRSCREN);	
	}

	
	if(DramAttr->ConfigData.EccPatrolScrub) //ECC Patrol Scrub mode
	{
		//LGE20160531 Add code here in future
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"patrol_scrub begin!!!\n"));
		
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ENDING_ADR);
	    TotalSize = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_REND7_37_24; //unit: 16MB      
		TotalSize >>= 2; //unit: 64MB
		
		if (((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0) && ((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) == 0))      //DIMM only in CHA
		{
			CHAAddrBegin = 0;
			CHAAddrEnd   = TotalSize;
			CHBAddrBegin = 0;
			CHBAddrEnd   = 0;
		}
		else if (((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) == 0) && 
			((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0))     //DIMM only in CHB
		{
			CHAAddrBegin = 0;
			CHAAddrEnd   = 0;
			CHBAddrBegin = 0;
			CHBAddrEnd   = TotalSize;
		}
		else if (((DramAttr->RankPresent[DramAttr->AttrNo] & 0x0F) != 0) && 
			((DramAttr->RankPresent[DramAttr->AttrNo] & 0xF0) != 0))     //DIMM  in CHA & CHB
		{
			if (DramAttr->ConfigData.VRIntlv == VRANK_INTERLEAVE_AUTO && DramAttr->VRInterleave == TRUE)  //Interleave Enable
			{
				CHAAddrBegin = 0;
				CHAAddrEnd   = TotalSize;
				CHBAddrBegin = 0;
				CHBAddrEnd   = TotalSize;
			}
			else if ((DramAttr->ConfigData.VRIntlv == VRANK_INTERLEAVE_AUTO && DramAttr->VRInterleave == FALSE) || 
				DramAttr->ConfigData.VRIntlv == VRANK_INTERLEAVE_DISABLED)   //Interleave Disable & Can't Interleave
			{
				GetChannelSize(PeiServices, DramAttr, &CHATotalSize, &CHBTotalSize); //Get CHA & CHB Total size 
				
				CHAAddrBegin = 0;
				CHAAddrEnd   = CHATotalSize;
				CHBAddrBegin = CHATotalSize;
				CHBAddrEnd   = CHATotalSize + CHBTotalSize;
			}
		}

		//sequence:
		//Enable demand scrub
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ALERT_RELATED);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RERRSCREN, D0F3_RERRSCREN);  //first must enable ECC demand scrub
		AsiaPcieRead16(0XE0000000, Address);

		if (CHAAddrEnd != 0) //CHA
		{
			//Set D0F3Rx24E[15:5](CHA), Patrol Begin Address Part 0 Channel A
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_BEG_36_26, CHAAddrBegin << 5);  
			AsiaPcieRead16(0XE0000000, Address);
			
			//Set D0F3Rx250[15:5](CHA) , Patrol End Address Part 0 Channel A
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_END_ADR_CHN_A);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_END_36_26, CHAAddrEnd << 5);  
			AsiaPcieRead16(0XE0000000, Address);

			//Set D0F3Rx24E[4]=1, RSCREN = 1¡ê?Enable Patrol Scrub Control CHA
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RSCREN, D0F3_RSCREN);  
			AsiaPcieRead16(0XE0000000, Address);

			//enable Rx24E[2]=1 (scurb on CHA), Patrol address enable Channel A
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_EN, D0F3_RPATROL_ADDR_EN);  
			AsiaPcieRead16(0XE0000000, Address);
		}

		if (CHBAddrEnd != 0)  //CHB
		{
			//Set D0F3Rx230[15:5](CHB), Patrol Begin Address Part 0 Channel B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_B);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_BEG_CHB_36_26, CHBAddrBegin << 5);  
			AsiaPcieRead16(0XE0000000, Address);
			
			//Set D0F3Rx232[15:5](CHB), Patrol End Address Part 0 Channel B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_END_ADR_CHN_B);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_END_CHB_36_26, CHBAddrEnd << 5);  
			AsiaPcieRead16(0XE0000000, Address);

			//Set D0F3Rx24E[3]=1, RSCREN_CHB = 1Enable Patrol Scrub Control CHB
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_A);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RSCREN_CHB, D0F3_RSCREN_CHB);  
			AsiaPcieRead16(0XE0000000, Address);

			//enable Rx230[4]=1 (scurb on CHB), Patrol address enable Channel B
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_B);
			AsiaPcieModify16(0XE0000000, Address, D0F3_RPATROL_ADDR_EN_CHB, D0F3_RPATROL_ADDR_EN_CHB);  
			AsiaPcieRead16(0XE0000000, Address);
		}
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"patrol_scrub Done!!!\n"));
	}

}

VOID GetChannelSize(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	UINT16 *CHATotalSize,
	UINT16 *CHBTotalSize
)
{
	UINT8  RankIndex;

	for (RankIndex = 0; RankIndex < 4; RankIndex++)
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex))
		{
			*CHATotalSize += DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize; //Unit MB
		}
	}
	*CHATotalSize = *CHATotalSize >> 6; //Unit 64MB
	
	for (RankIndex = 4; RankIndex < 8; RankIndex++)
	{
		if (DramAttr->RankPresent[DramAttr->AttrNo] & (1 << RankIndex))
		{
			*CHBTotalSize += DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize; //Unit MB
		}
	}
	*CHBTotalSize = *CHBTotalSize >> 6; //Unit 64MB
}

