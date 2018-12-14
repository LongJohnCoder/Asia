//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

#include "raida.h"
#include "DramInit.h"
#include "PeiLib.h"

void delay(UINT32 count)
{
	UINT32 i, j;
	
	for(i=0; i < count; i++)
	{
		for(j=0; j < 100; j++)
		AsiaIoWrite8(0x80, 0x29);
	}
}

void set_add_desc(UINT32 raida_mmio_ptr,UINT32 number)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_ADD_DSCP) = number;
	return;
	
}

void zx_chan_activate(UINT32 raida_mmio_ptr,UINT32 addnumber)
{

	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_INFO)=*(volatile UINT32*)(raida_mmio_ptr + RAIDA_MMIO_CTL_INFO) & ~BIT_ACTIVE;


	set_add_desc(raida_mmio_ptr,addnumber);


	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_INFO)=*(volatile UINT32*)(raida_mmio_ptr + RAIDA_MMIO_CTL_INFO) | BIT_ACTIVE;


}


int raida_reset(UINT32 raida_mmio_ptr)
{
	
	/*do hot reset*/
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_CTL_REG, BIT_HOT_RESET, BIT_HOT_RESET);
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_CTL_INFO, BIT_ACTIVE, 0); 		


	
	delay(100);
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_FSTADD_UPPER, 0xFF, 0);
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_FSTADD_LOW, 0xFFFFFFFF, 0); 		
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_CTL_INFO, 0x1F, 0);
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_CTL_REG, 0xF8, 0); 		
	AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_ADD_DSCP, 0xFFFFFFFF, 0); 		


	return 0;

}

void disable_chain_resume(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) & ~BIT_CHAIN_RESUME;

	return;
}

void enable_flush_read(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) | BIT_FLUSH_READ_EN;

	return;
}

void disable_flush_read(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) & ~BIT_FLUSH_READ_EN;

	return;
}

void enable_wait_resume(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) |BIT_WAIT_RESUME;


	return;
}

void disable_wait_resume(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) & ~BIT_WAIT_RESUME;
	return;
}

void enable_dma_interrupt(UINT32 raida_mmio_ptr)
{
	/*en ch interrupts*/
		*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG)|BIT_INTR_EN;
	return;
}

void set_interrupt_mode_eod(UINT32 raida_mmio_ptr)
{
		*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG)|BIT_INTR_MODE;

    return;
}

void asia_chan_inactivate(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_INFO)=*(volatile UINT32*)(raida_mmio_ptr + RAIDA_MMIO_CTL_INFO) & ~BIT_ACTIVE;

	return;
}

void enable_update_desc_status(UINT32 raida_mmio_ptr)
{
	*(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) = *(volatile UINT32*)(raida_mmio_ptr+RAIDA_MMIO_CTL_REG) | BIT_UPDATE_DESC_STATUS_EN;

	return;
}

void clear_raida_interrupt_status(UINT32 raida_mmio_ptr)
{

	*(volatile UINT32*)(raida_mmio_ptr + RAIDA_MMIO_CTL_INFO) = *(volatile UINT32*)(raida_mmio_ptr + RAIDA_MMIO_CTL_INFO)|RDA0_MMIO_RAIDA0_IS;  //clear interrupt status.   RW1C
	return;
}
void asia_xor_set_first_desc_addr(IN EFI_PEI_SERVICES **PeiServices,UINT32 raida_mmio_ptr,UINT64 addr)
{
	asia_xor_upper_addr reg;
	
		reg = 0;//(addr>>32)&0xff;   //CKS copy from set below 4G for test only
		
		AsiaMemoryModify16(raida_mmio_ptr|RAIDA_MMIO_FSTADD_UPPER, 0xFF, reg);
		AsiaMemoryModify32(raida_mmio_ptr|RAIDA_MMIO_FSTADD_LOW, 0xffffffff, (UINT32)addr); 		
		
	return;
}

void asia_xor_config(UINT32 raida_mmio_ptr)
{
	//enable_flush_read(pdev);
	disable_flush_read(raida_mmio_ptr);

	
	enable_dma_interrupt(raida_mmio_ptr);
	
	clear_raida_interrupt_status(raida_mmio_ptr);
	set_interrupt_mode_eod(raida_mmio_ptr);
	
	
	asia_chan_inactivate(raida_mmio_ptr);
	
	
	enable_update_desc_status(raida_mmio_ptr);

}

void asia_xor_desc_init(asia_xor_desc *hw_desc, UINT64 flags, UINT64 DataPattern)
{
	hw_desc->DCS.dcs.Cmd = 0;
	hw_desc->DCS.dcs.Srcnumber = 0;
	hw_desc->DCS.dcs.Descriptor_Completion_Interrupt = !!(flags & DMA_PREP_INTERRUPT);
	hw_desc->DCS.dcs.dstnumber = 0;
	hw_desc->DCS.dcs.msi_sel = 0;
	hw_desc->DCS.dcs.reedsol_w = 0;
	hw_desc->DBC.dbc.Byte_Count = 0;
	hw_desc->DBC.dbc.Reserved = 0;	
	hw_desc->DBC.dbc.Descriptor_Status = 0;
	hw_desc->DBC.dbc.Non_Equivalent = 0;
	hw_desc->DBC.dbc.Non_zero = 0;
	hw_desc->pNDA.phy_u64 = 0;
	hw_desc->pDataSource1.phy_u64 = 0;

	hw_desc->DBC.dbc.Byte_Count = 0x1000000-1;
	hw_desc->DCS.dcs.Srcnumber = 0;
	hw_desc->DCS.dcs.Cmd = CMD_MEM_FILL;
	hw_desc->pDataSource1.phy_u64 = DataPattern;
}

void Raida(IN EFI_PEI_SERVICES **PeiServices,
			IN DRAM_ATTRIBUTE *DramAttr,
	         UINT64 StartAddr,
	         UINT64 EndAddr)
{
	asia_xor_desc *p_cmd_desc;
	UINT32 p_addr_table;
	UINT64 BaseAddr;
	UINT32 Upper32bit;
	UINT32 Lower32bit;
	UINT32 raida_mmio_ptr;
	DATA_SRC_ADDR *p_data_addr[4];
	
	p_cmd_desc = (asia_xor_desc *)(0x100000); 
	p_addr_table = 0x200000;

	  AsiaPciModify32(CHX002_RAIDA0|D8F0_MMIO_LOW_SPACE_BASE_ADR, 0xffffff00, 0xfe0c0000);
	  AsiaPciModify32(CHX002_RAIDA0|D8F0_PCI_CMD, 0x06, 0x6);	

//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "RAIDA CLEAR MEM,StartAddr = %08x,EndAddr = %08x\n", (UINT32)StartAddr, (UINT32)EndAddr)); 
	    raida_mmio_ptr=AsiaPciRead32(CHX002_RAIDA0|D8F0_MMIO_LOW_SPACE_BASE_ADR);
        raida_mmio_ptr &= 0xFFFFF000;
	raida_reset(raida_mmio_ptr);


	//set pci configuration space	
	asia_xor_config(raida_mmio_ptr);          

	//set address of descriptor in pci configuration space
	asia_xor_set_first_desc_addr(PeiServices,raida_mmio_ptr,(UINT64)p_cmd_desc);

	asia_xor_desc_init(p_cmd_desc, 0, 0x5a5a5a5a);
	
	p_cmd_desc->pDestinationAddr.phy_u64 = (UINT64)p_addr_table;
	p_cmd_desc->DCS.dcs.Descriptor_Completion_Interrupt = 1;     //enable radia desc interrupt.

	p_data_addr[0] = (DATA_SRC_ADDR*)p_addr_table;
	p_data_addr[1] = (DATA_SRC_ADDR*)(p_addr_table+sizeof(DATA_SRC_ADDR));
	p_data_addr[2] = (DATA_SRC_ADDR*)(p_addr_table+2*sizeof(DATA_SRC_ADDR));
	p_data_addr[3] = (DATA_SRC_ADDR*)(p_addr_table+3*sizeof(DATA_SRC_ADDR));
//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "StartAddr:%8x  EndAddr:%16x \n",StartAddr,EndAddr));
	
	for(BaseAddr = StartAddr; BaseAddr < EndAddr; BaseAddr += 0x1000000)
	{
		Lower32bit = (UINT32)(BaseAddr & 0xFFFFFFFF);
		Upper32bit = (UINT32)(RShiftU64(BaseAddr, 32));
//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "BaseAddr:%8x  EndAddr:%16x \n",BaseAddr,EndAddr));
		
		p_data_addr[0]->Data_Base_Address = Lower32bit>>1 ;
		p_data_addr[0]->Upper_Data_Base_Address = Upper32bit;
		p_data_addr[0]->Data_Byte_Count = 0x400000-1;
		p_data_addr[0]->End = 0;

		p_data_addr[1]->Data_Base_Address = (Lower32bit+0x400000)>>1;
		p_data_addr[1]->Upper_Data_Base_Address = Upper32bit;
		p_data_addr[1]->Data_Byte_Count = 0x400000-1;
		p_data_addr[1]->End = 0;
		
		p_data_addr[2]->Data_Base_Address = (Lower32bit+0x800000)>>1;
		p_data_addr[2]->Upper_Data_Base_Address = Upper32bit;
		p_data_addr[2]->Data_Byte_Count = 0x400000-1;
		p_data_addr[2]->End = 0;

		p_data_addr[3]->Data_Base_Address = (Lower32bit+0xc00000)>>1;
		p_data_addr[3]->Upper_Data_Base_Address = Upper32bit;
		p_data_addr[3]->Data_Byte_Count = 0x400000-1;
		p_data_addr[3]->End = 1;
//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Lower32bit:%8x || Upper32bit:%8x\n",Lower32bit,Upper32bit));



		zx_chan_activate(raida_mmio_ptr, 1);


		//while(!p_cmd_desc->DBC.dbc.Descriptor_Status);
		while(!(*(volatile UINT32*)(raida_mmio_ptr + RAIDA_MMIO_CTL_INFO) & RDA0_MMIO_RAIDA0_IS));
	 
		//p_cmd_desc->DBC.dbc.Descriptor_Status=0;
		clear_raida_interrupt_status(raida_mmio_ptr);
//		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Descriptor_Status:%8x\n",p_cmd_desc->DBC.dbc));
	}
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "CKS RAIDA CLEAR done !!!! \n"));  

}
