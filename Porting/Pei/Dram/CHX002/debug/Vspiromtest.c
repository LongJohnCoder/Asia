///
#define VT_SPI_ROM_BASE    0xFFC00000
///
static VOID SpiromMTRRSet(IN     EFI_PEI_SERVICES    **PeiServices)
{
	UINT64 MtrrBase;
	UINT64 MtrrMask;

       ///
       PEI_DEBUG ((PeiServices,EFI_D_ERROR, "\n Set SPIROM Un-Cacheable \n"));
	MtrrBase = 0xFFC00000;
	MtrrMask = 0xFFC00800;
	__writemsr(MTRR_PHYS_BASE_0, MtrrBase);
	__writemsr(MTRR_PHYS_BASE_0 + 1, MtrrMask);	
       ///
}
///
static VOID CND_MemCopy1(
      IN     EFI_PEI_SERVICES    **PeiServices,
      CHAR8 *DstBase,
      CHAR8 *DstBase1,
      CHAR8 *DstBase2,
      CHAR8*SrcBase, 
      UINTN Len)
{
	CHAR8 *Destination8;
	CHAR8 *Destination81;
	CHAR8 *Destination82;
	///
	CHAR8 *Source8;
	UINTN Length;
	UINT32 i;
	UINT8 D8;
	
	Destination8  =DstBase;
	Destination81  =DstBase1;	
	Destination82  =DstBase2;	
	////
	Source8 	      =SrcBase;
	Length	      = Len;
	///
	PEI_DEBUG ((PeiServices,EFI_D_ERROR, "\n CND_MemCopy  : from  0x%x , to 0x%x , 0x%x, 0x%x size = %x \n",
	                     (UINT32)Source8,(UINT32)Destination8,(UINT32)Destination81,(UINT32)Destination82,Len));
	///
	i=0;
	while (Length--) {
	  //PEI_DEBUG ((PeiServices,EFI_D_ERROR, "Dst : 0x%x , Src : 0x%x \n",(UINT32)Destination8,(UINT32)Source8));	
	  D8 =  *(Source8++);
	  *(Destination8++)   = D8;
	  *(Destination81++) = D8;
	  *(Destination82++) = D8;
	  ///
	  i++;
	  if(((i+1)%64)==0){
		PEI_DEBUG((PeiServices,EFI_D_ERROR, ".."));
	  }	  
	  ///
	}
	///
}

///
static VOID CND_MemCopy(IN     EFI_PEI_SERVICES    **PeiServices,CHAR8 *DstBase,CHAR8*SrcBase, UINTN Len)
{
	CHAR8 *Destination8;
	CHAR8 *Source8;
	UINTN Length;
	UINT32 i;
	//UINT8 Data8;
	
	Destination8  =DstBase;
	Source8 	      =SrcBase;
	Length	      = Len;
	///
	PEI_DEBUG ((PeiServices,EFI_D_ERROR, "\n CND_MemCopy  : from  0x%x , to 0x%x , size = %x \n",
	                     (UINT32)Source8,(UINT32)Destination8,Len));
	///
	i=0;
	while (Length--) {
	  //PEI_DEBUG ((PeiServices,EFI_D_ERROR, "Src : 0x%x , Data : 0x%x \n",(UINT32)Source8,*(Source8)));	
	  *(Destination8++) = *(Source8++);
	  ///
	  i++;
	  if(((i+1)%64)==0){
		PEI_DEBUG((PeiServices,EFI_D_ERROR, ".."));
	  }	  
	  ///
	}
	///
}
///
static VOID VDumpMem8(IN     EFI_PEI_SERVICES             **PeiServices,VOID *Base, UINTN Size)
{
  UINT8  *Data8;   
  UINTN  Index;
  
  PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Dump mem : 0x%x , size = %x \n",Base,Size));
  ///
  Data8 = (UINT8*)Base;
  for(Index=0; Index<Size; Index++){
    PEI_DEBUG((PeiServices,EFI_D_ERROR, "%02X ", Data8[Index]));
    if(((Index+1)%16)==0){
      PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n"));
    }
  }
  PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n"));
}

///
//#define VT_SPIROM_RANGE 0x1000
//#define VT_SPIROM_RANGE 0x400000
#define VT_SPIROM_RANGE 0x380000

///
VOID VSpi_ReadTest(IN     EFI_PEI_SERVICES             **PeiServices)
{
	UINT32 DstAddr1;
	UINT32 DstAddr2;
	UINT32 DstAddr3;
	///
	UINT32 SrcAddr;
	UINT32 i;
	UINT8 Data80;
	UINT8 Data81;
	//UINT8 Data82;

       PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n into VSpi_ReadTest() \n"));
       //SpiromMTRRSet(PeiServices);	 // Set SPIROM uncacheable.
       //VDump_MTRR(PeiServices);
       PEI_DEBUG((PeiServices,EFI_D_ERROR, "***************************  \n"));	   
	///
	DstAddr1 = 0x7FF00000 - VT_SPIROM_RANGE;
	DstAddr2 = 0x10000000; /// at 256MB 
	DstAddr3 = 0x20100000; /// at 512MB+64KB
	///
	SrcAddr = VT_SPI_ROM_BASE; // 0xFFC0 0000

        /// read SPIROM, and write to Dst1
        (*PeiServices)->SetMem((VOID*)DstAddr1, VT_SPIROM_RANGE, 0);
	CND_MemCopy(PeiServices,(CHAR8*)DstAddr1,(CHAR8*)SrcAddr,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr1),0x100);
        /// read SPIROM, and write to Dst2
	(*PeiServices)->SetMem((VOID*)DstAddr2, VT_SPIROM_RANGE, 0);
	CND_MemCopy(PeiServices,(CHAR8*)DstAddr2,(CHAR8*)SrcAddr,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr2),0x100);
        ///  read SPIROM, and write to Dst3
	(*PeiServices)->SetMem((VOID*)DstAddr3, VT_SPIROM_RANGE, 0);
	CND_MemCopy(PeiServices,(CHAR8*)DstAddr3,(CHAR8*)SrcAddr,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr3),0x100);
	   
	/// Compare DstAddr1 and DstAddr2's content
#if 1	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare Dst1=0x%x with Dst2= 0x%x \n",DstAddr1,DstAddr2));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));

	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(DstAddr2 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp12 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare Dst1=0x%x with Dst3= 0x%x \n",DstAddr1,DstAddr3));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	/// Compare DstAddr1 and DstAddr3's content
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(DstAddr3 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp13 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

       PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare Dst2=0x%x with Dst3= 0x%x \n",DstAddr2,DstAddr3));   
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
       /// Compare DstAddr2 and DstAddr3's content
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr2 + i);
		Data81 = AsiaMemoryRead8(DstAddr3 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp23 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}
#else	
	//// SPIROM read compare with 3 different DRAM content
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	SrcAddr = VT_SPI_ROM_BASE; // 0xFFC0 0000
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr1,SrcAddr));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	///  Compare DstAddr1 and SPIROM's content 
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp1 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

	///  Compare DstAddr2 and SPIROM's content 
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr2,SrcAddr));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr2 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp2 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

       ///   Compare DstAddr3 and SPIROM's content 
       PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr3,SrcAddr));   
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr3 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp3 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}	
#endif	
}

//// Read SPIROM one time, write to 3 different DRAM region.
VOID VSpi_ReadTest1(IN     EFI_PEI_SERVICES             **PeiServices)
{
	UINT32 DstAddr1;
	UINT32 DstAddr2;
	UINT32 DstAddr3;
	///
	UINT32 SrcAddr;
	UINT32 i;
	UINT8 Data80;
	UINT8 Data81;
	//UINT8 Data82;

       PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n into VSpi_ReadTest() \n"));
	DstAddr1 = 0x7FF00000 - VT_SPIROM_RANGE;
	DstAddr2 = 0x10000000; /// at 256MB 
	DstAddr3 = 0x20100000; /// at 512MB+64KB
	///
	SrcAddr = VT_SPI_ROM_BASE; // 0xFFC0 0000

        /// read SPIROM , write to DstAddr1
        (*PeiServices)->SetMem((VOID*)DstAddr1, VT_SPIROM_RANGE, 0);
	CND_MemCopy(PeiServices,(CHAR8*)DstAddr1,(CHAR8*)SrcAddr,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr1),0x100);

        /// Copy DstAddr1 to DstAddr2
	(*PeiServices)->SetMem((VOID*)DstAddr2, VT_SPIROM_RANGE, 0);
	CND_MemCopy(PeiServices,(CHAR8*)DstAddr2,(CHAR8*)DstAddr1,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr2),0x100);

	/// Copy DstAddr1 to DstAddr3
	(*PeiServices)->SetMem((VOID*)DstAddr3, VT_SPIROM_RANGE, 0);
	CND_MemCopy(PeiServices,(CHAR8*)DstAddr3,(CHAR8*)DstAddr1,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr3),0x100);
	   
	/// Compare DstAddr1 and DstAddr2's content
#if 1	
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(DstAddr2 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp12 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

	/// Compare DstAddr1 and DstAddr3's content
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(DstAddr3 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp13 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

       /// Compare DstAddr2 and DstAddr3's content
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr2 + i);
		Data81 = AsiaMemoryRead8(DstAddr3 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp23 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}
#endif

       ////
#if 0
	//// SPIROM read compare with DRAM content
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	SrcAddr = VT_SPI_ROM_BASE; // 0xFFC0 0000
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr1,SrcAddr));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	///  Compare DstAddr1 and SPIROM's content 
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp1 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

	///  Compare DstAddr2 and SPIROM's content 
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr2,SrcAddr));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr2 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp2 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

       ///   Compare DstAddr3 and SPIROM's content 
       PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr3,SrcAddr));   
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr3 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp3 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}
#endif
      ////
}

////
//// Read a byte from SPIROM one time, write to 3 different DRAM region.
VOID VSpi_ReadTest2(IN     EFI_PEI_SERVICES             **PeiServices)
{
	UINT32 DstAddr1;
	UINT32 DstAddr2;
	UINT32 DstAddr3;
	///
	UINT32 SrcAddr;
	UINT32 i;
	UINT8 Data80;
	UINT8 Data81;
	//UINT8 Data82;

       PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n into VSpi_ReadTest() \n"));
	DstAddr1 = 0x7FF00000 - VT_SPIROM_RANGE;
	DstAddr2 = 0x10000000; /// at 256MB 
	DstAddr3 = 0x20100000; /// at 512MB+64KB
	///
	SrcAddr = VT_SPI_ROM_BASE; // 0xFFC0 0000

        ///Clear DstAddr1 / DstAddr2 / DstAddr3
        (*PeiServices)->SetMem((VOID*)DstAddr1, VT_SPIROM_RANGE, 0);
        (*PeiServices)->SetMem((VOID*)DstAddr2, VT_SPIROM_RANGE, 0);
        (*PeiServices)->SetMem((VOID*)DstAddr3, VT_SPIROM_RANGE, 0);		
	 VDumpMem8(PeiServices,(VOID*)(DstAddr1),0x100);
	 VDumpMem8(PeiServices,(VOID*)(DstAddr2),0x100);
	 VDumpMem8(PeiServices,(VOID*)(DstAddr3),0x100);
		
	///	
	CND_MemCopy1(PeiServices,(CHAR8*)DstAddr1,(CHAR8*)DstAddr2,(CHAR8*)DstAddr3,(CHAR8*)SrcAddr,VT_SPIROM_RANGE);
       VDumpMem8(PeiServices,(VOID*)(DstAddr1),0x100);
       VDumpMem8(PeiServices,(VOID*)(DstAddr2),0x100);
	VDumpMem8(PeiServices,(VOID*)(DstAddr3),0x100);


	   
	/// Compare DstAddr1 and DstAddr2's content
#if 1	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare Dst1= 0x%x with Dst2=0x%x \n",DstAddr1,DstAddr2));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));

	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(DstAddr2 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp12 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare Dst1= 0x%x with Dst3=0x%x \n",DstAddr1,DstAddr3));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	/// Compare DstAddr1 and DstAddr3's content
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(DstAddr3 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp13 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

       PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare Dst2= 0x%x with Dst3=0x%x \n",DstAddr2,DstAddr3));   
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
       /// Compare DstAddr2 and DstAddr3's content
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr2 + i);
		Data81 = AsiaMemoryRead8(DstAddr3 + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n DramCmp23 error :i = 0x%x Data80 = 0x%x , Data81 = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}
#endif

       ////
#if 0
	//// SPIROM read compare with DRAM content
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n ************************************************ \n"));
	SrcAddr = VT_SPI_ROM_BASE; // 0xFFC0 0000
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr1,SrcAddr));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	///  Compare DstAddr1 and SPIROM's content 
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr1 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp1 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

	///  Compare DstAddr2 and SPIROM's content 
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr2,SrcAddr));	
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr2 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp2 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}

       ///   Compare DstAddr3 and SPIROM's content 
       PEI_DEBUG (( PeiServices,EFI_D_ERROR, "Compare 0x%x with 0x%x \n",DstAddr3,SrcAddr));   
	PEI_DEBUG (( PeiServices,EFI_D_ERROR, "************************************************ \n"));
	for(i=0;i < VT_SPIROM_RANGE;i++)
	{
		Data80 = AsiaMemoryRead8(DstAddr3 + i);
		Data81 = AsiaMemoryRead8(SrcAddr + i);
		if( Data80 != Data81 )
		{
			///
			PEI_DEBUG (( PeiServices,EFI_D_ERROR, "\n SPICmp3 error :i = 0x%x Data80 = 0x%x , should = 0x%x \n",i,Data80,Data81));
			//break;
			///
		}
	}
#endif
      ////
}

////
VOID VDump_PciDv(
	IN     EFI_PEI_SERVICES             **PeiServices, 
	UINT8 BusNo,
	UINT8 DevNo,
	UINT8 FunNo
)
{
	UINT32 Index1,Index2;
	UINT64   Address;
	UINT8 Data;

	PEI_DEBUG((PeiServices, EFI_D_INFO, "Dump Bus %2x, Dev %2x, Fun %2x\n", BusNo, DevNo, FunNo));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "---+-----------------------------------------------\n"));
	for(Index1=0;Index1<0x20;Index1++)
	{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%03x|", Index1*16));
		for(Index2=0;Index2<0x10;Index2++)
		{
			Address = AsiaPciAddress(BusNo, DevNo, FunNo, (UINT16)(Index1*16+Index2));
			Data = AsiaPcieRead8(0xE0000000, Address);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "%02x ", Data));
			if(Index2==0x0F)
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));
		}
		if((Index1%0x10)==0x0F)
			PEI_DEBUG((PeiServices, EFI_D_INFO, "---------------------------------------------------\n"));
	}
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n"));

}
////
VOID VSpi_DumpRegs(IN     EFI_PEI_SERVICES             **PeiServices)
{
	UINT32 Addr;
	UINT32 i;
	UINT8 D8;

	///
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Dump D17F0's registers \n"));
	VDump_PciDv(PeiServices,0,0x11,0); // Dump D17F0
	/// D17F0's MMIO Base Addr
	Addr =  0xFED12000; 
	for(i=0;i<0x0B;i++)
	{
		D8   = AsiaMemoryRead8(Addr + i);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Addr : 0x%8x , Data : 0x%8x \n",(Addr+i),D8));
	}
	///
	/// SPI Bus0: MMIO Base Addr
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n ********* \n Print SPI Bus0 MMIO Space \n"));
	///
	Addr =  0xFED10000; 
	for(i=0;i<0x8F;i++)
	{
		D8   = AsiaMemoryRead8(Addr + i);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Addr : 0x%8x , Data : 0x%8x \n",(Addr+i),D8));
	}
	
}
////
VOID VSpi_HWReadTst(IN     EFI_PEI_SERVICES             **PeiServices)
{
	UINT32 BaseAddr;
	////
	UINT32 Range1_Start,Range1_End;
	//UINT32 Range2_Start,Range2_End;
	//UINT32 Range3_Start,Range3_End;
	//UINT32 Range4_Start,Range4_End;
	////
	UINT32 i;
	UINT32 D32;
	UINT32 TargetD32;

	
	BaseAddr = 0xFFC00000; // SPIROM Base Address.

	do
	{
		Range1_Start = 0x3B0;
		Range1_End  = 0x1FFBF;
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n"));
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "Begin to test Range from 0x%8x to 0x%8x \n",
			(BaseAddr+Range1_Start),(BaseAddr+Range1_End)));	
		///
		for(i=Range1_Start ; i< Range1_End;i+=4)
		{
			D32 = AsiaMemoryRead32(BaseAddr + i);
			TargetD32 = BaseAddr + i;
			if( D32  != TargetD32 )
			{
				///
				AsiaIoWrite8(0x80,0x39);
				PEI_DEBUG((PeiServices,EFI_D_ERROR, "Error: Addr(0x%8x) = 0x%8x, should be 0x%8x \n",
					(BaseAddr+i), D32,TargetD32));
				///
				goto Error_End;
				break;
			}
			///
			  if(((i)%64)==0){
				PEI_DEBUG((PeiServices,EFI_D_ERROR, ".."));
			  }	  		
			///
		}

	       ////
		Range1_Start = 0x20030;
		Range1_End  = 0x4FFAF;
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n"));
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "Begin to test Range from 0x%8x to 0x%8x \n",
			(BaseAddr+Range1_Start),(BaseAddr+Range1_End)));	
		for(i=Range1_Start ; i< Range1_End;i+=4)
		{
			D32 = AsiaMemoryRead32(BaseAddr + i);
			TargetD32 = BaseAddr + i;
			if( D32  != TargetD32 )
			{
				//
				AsiaIoWrite8(0x80,0x39);
				PEI_DEBUG((PeiServices,EFI_D_ERROR, "Error: Addr(0x%8x) = 0x%8x, should be 0x%8x \n",
					(BaseAddr+i), D32,TargetD32));
				
				goto Error_End;
				break;
			}
			///
			  if(((i)%64)==0){
				PEI_DEBUG((PeiServices,EFI_D_ERROR, ".."));
			  }	  		
			///
		}       
		////

		Range1_Start = 0x1dcc60;
		Range1_End  = 0x37FFCF;
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n"));
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "Begin to test Range from 0x%8x to 0x%8x \n",
			(BaseAddr+Range1_Start),(BaseAddr+Range1_End)));	
		for(i=Range1_Start ; i< Range1_End;i+=4)
		{
			D32 = AsiaMemoryRead32(BaseAddr + i);
			TargetD32 = BaseAddr + i;
			if( D32  != TargetD32 )
			{
				//
				AsiaIoWrite8(0x80,0x39);
				PEI_DEBUG((PeiServices,EFI_D_ERROR, "Error: Addr(0x%8x) = 0x%8x, should be 0x%8x \n",
					(BaseAddr+i), D32,TargetD32));
				
				goto Error_End;
				break;
			}
			///
			  if(((i)%64)==0){
				PEI_DEBUG((PeiServices,EFI_D_ERROR, ".."));
			  }	  		
			///
		}
		////
	}while(1);
	////
	/*
	Range1_Start = 0x3CE260;
	Range1_End  = 0x3FF83F;
	PEI_DEBUG((PeiServices,EFI_D_ERROR, "\n"));
	PEI_DEBUG((PeiServices,EFI_D_ERROR, "Begin to test Range from 0x%8x to 0x%8x \n",
		(BaseAddr+Range1_Start),(BaseAddr+Range1_End)));	
	for(i=Range1_Start ; i< Range1_End;i+=4)
	{
		D32 = AsiaMemoryRead32(BaseAddr + i);
		TargetD32 = BaseAddr + i;
		if( D32  != TargetD32 )
		{
			//
			AsiaIoWrite8(0x80,0x39);
			PEI_DEBUG((PeiServices,EFI_D_ERROR, "Error: Addr(0x%8x) = 0x%8x, should be 0x%8x \n",
				(BaseAddr+i), D32,TargetD32));
			
			goto Error_End;
			break;
		}
		///
		  if(((i)%64)==0){
			PEI_DEBUG((PeiServices,EFI_D_ERROR, ".."));
		  }	  		
		///
	}
       */
	////
	
Error_End:
       return;
}
////
////

typedef
EFI_STATUS
(EFIAPI *EFI_PEI_TMP_TGR_READ_FILE) (
	IN CHAR8   *pDstBuffer,
	IN CHAR8   *pSrcAddr,
	IN UINTN   ReadSize  
  );

////
EFI_STATUS TgrMemCpy (
  IN CHAR8   *pDstBuffer,
  IN CHAR8   *pSrcAddr,
  IN UINTN   ReadSize
  )
{
  CHAR8 *Destination8;
  CHAR8 *Source8;
  UINTN Length;

  ///
  __asm {
              nop
	       nop
	       nop
		mov al, 036h
		mov dx, 080h
		nop
		out dx, al	  
  }
  ///
  
  Destination8  = pDstBuffer;
  Source8        = pSrcAddr;
  Length          = ReadSize;

  ///
  while (Length--) {
  	///
	__asm {
	         nop
		  mov al, 037h
		  mov dx, 080h
		  nop
		  out dx, al	
	}
      ///  	
    *(Destination8++) = *(Source8++);
	///
	__asm {
		  mov al, 039h
		  mov dx, 080h
		  out dx, al	
	}
	///
  }

  return EFI_SUCCESS;
}

////
VOID VPutFunc2Mem(IN     EFI_PEI_SERVICES             **PeiServices)
{
	//UINT32 DstAddr;
	//UINT32 SrcAddr;
	UINT32 McpyAddr;

	McpyAddr = 0x10000000; // at 256MB
	(*PeiServices)->SetMem((VOID*)McpyAddr, 0x200, 0);
	/// Put memcpy function to 256MB.
	CND_MemCopy (	PeiServices,
								 (VOID *) (UINTN) McpyAddr,
								 (VOID *) (UINTN) TgrMemCpy,
								 0x100 );	
	///
}
////
VOID VSpi_CacheCpyTst(IN     EFI_PEI_SERVICES             **PeiServices)
{
	UINT32 DstAddr;
	UINT32 SrcAddr;
	UINT32 McpyAddr;
	UINT8 Tmp[2064];
	UINT32 nLoop;
	////
       EFI_PEI_TMP_TGR_READ_FILE  TmpMemCpyFunc;	
       //TgrMemCpy TmpMemCpyFunc;
	////
	DstAddr = (UINT32)Tmp;
	//SrcAddr = 0xFFF83F80;
	SrcAddr = 0xFFC00010;
	//SrcAddr = 0xFFFFD010; // FOR bYO
	///
	McpyAddr = 0x10000000; // at 256MB
	//(*PeiServices)->SetMem((VOID*)McpyAddr, 0x200, 0);
	(*PeiServices)->SetMem((VOID*)DstAddr, 0x800, 0);
	///
#if 0	
	CND_MemCopy (	PeiServices,
	                             (VOID *) (UINTN) McpyAddr,
	                             (VOID *) (UINTN) TgrMemCpy,
	                             0x100 );	
#endif
	///
       //VDumpMem8(PeiServices,(VOID*)McpyAddr,0x50);	
	///
	nLoop = 0;
	TmpMemCpyFunc= (EFI_PEI_TMP_TGR_READ_FILE)McpyAddr;////
	do
	{
		nLoop++;
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "Copy SPIROM to Dst=0x%08x , Src=0x%08x, Cache Test - Loop :%d \n",
					DstAddr,SrcAddr,nLoop));
		///
		//AsiaIoWrite8(0x80,0x81);		
		//VDumpMem8(PeiServices,(VOID*)McpyAddr,0x50);	
		AsiaIoWrite8(0x80,0x82);
		(*PeiServices)->SetMem((VOID*)DstAddr, 0x800, 0);
		///
		AsiaIoWrite8(0x80,0x83);		
		TmpMemCpyFunc((CHAR8*)DstAddr,(CHAR8*)SrcAddr,0x800);
		///
		///
		VDumpMem8(PeiServices,(VOID*)DstAddr,0x50);	
		///
	}while(nLoop<500);

	
}
////

