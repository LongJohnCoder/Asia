////
#define   QW_TEST_PATTERN1    0xFEFEFEFEFEFEFEFE             //the test pattern 
////
UINT64 VTShl64(
	IN UINT64 Value,
	IN UINT8 Shift
	)
{
	_asm {
		mov	edx, dword ptr Value[4]
		mov	eax, dword ptr Value
		mov	cl, Shift

		cmp	cl, 64
		jb	less_64
		xor	eax, eax
		xor	edx, edx
		jmp	exit
less_64:
		cmp	cl, 32			//Shift is 32 modulo
		jb less_32

		mov		edx, eax
		xor		eax, eax
less_32:
		shld	edx, eax, cl
		shl		eax, cl
exit:
	}
}

////
BOOLEAN VT_Dram8ByteTest(IN struct _EFI_PEI_SERVICES **PeiServices,
                     IN UINT32                        BaseAdd, 
                     IN UINT32                        Length,
                     IN UINT64		Pattern
)
{
    UINT64  Data;
    UINT32  Address;
    INT32 i;
    INT32 TestCount;


    // the test mode is step and test some unit
    TestCount = (Length/8); // read 4 bytes every time, so need 16 times.

    Address = BaseAdd;
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"BaseAddress = 0x%x    Length = 0x%x   , TestCount = 0x%x Pattern = 0x%lx \n",
		 Address, Length,TestCount,Pattern));	
    //write each test unit the value with TEST_PATTERN
    for ( i = 0; i < TestCount; i++)
    {
    	     //PEI_DEBUG((PeiServices, EFI_D_ERROR,"1.Write addr = 0x%x , Data = 0x%lx \n",(Address + i *8),Pattern));        
            //AsiaMemoryWrite32(Address + i *4, 0x5A5A5A5A);
            AsiaMemoryWrite64(Address + i *8, Pattern);
    }

    //compare each test unit with the value of TEST_PATTERN
    //and write it with compliment of TEST_PATTERN
        for ( i = 0; i < TestCount; i++)
        {
            Data = AsiaMemoryRead64(Address + i * 8);
	     //PEI_DEBUG((PeiServices, EFI_D_ERROR, "1.cmp !!!!! %08x : %lx\n", (UINT32)(Address + i*8), Data));		
            AsiaMemoryWrite64(Address + i * 8, ~Pattern);
	     ///		
            if (Data != Pattern)
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "1.ERROR !!!!! %08x : %lx\n", (UINT32)(Address + i*8), Data));
		 goto Bst_Error;		
                break;  //3410-36-LNA-04
            }
        }
	////	

	//PEI_DEBUG((PeiServices, EFI_D_ERROR,"%a(%d)+++++++++++++++++++ \r",__FILE__,__LINE__));
    //compare each test unit with the value of ~TEST_PATTERN
        for (i=(TestCount - 1); i >= 0; i--)
        {
            Data = AsiaMemoryRead64(Address + i * 8);
	     //PEI_DEBUG((PeiServices, EFI_D_ERROR, "2. i = %d Addr %08x : Data 0x%lx , should : 0x%lx \n", i,
	     //		(Address + i*8), Data,~Pattern));
	     ////			
            if (Data != ~Pattern)
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "2.ERROR !!!!! Addr %08x : Data %lx , should : %lx \n", 
					(Address + i*8), Data,~Pattern));
		 ////		
                goto Bst_Error;
                break;  //3410-36-LNA-04
            }
        }

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"%a(%d) End-Burst-Test \n",__FILE__,__LINE__));

Bst_Error:
    return TRUE;
}
////
///
#define   TEST_PATTERN1    0xFEFEFEFE             //the test pattern 
///
BOOLEAN VT_DramBaseTest(IN struct _EFI_PEI_SERVICES **PeiServices,
                     IN UINT32                        BaseAdd, 
                     IN UINT32                        Length,
                     IN UINT32		Pattern
)
{
    UINT32 Data,Data1,Address;
    INT32 i;
    INT32 TestCount;
	UINT8 read_error;
    BOOLEAN bRet;

    bRet = FALSE;
    // the test mode is step and test some unit
    TestCount = (Length/4); // read 4 bytes every time, so need 16 times.

    Address = BaseAdd;
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"BaseAddress = 0x%x    Length = 0x%x   , TestCount = 0x%x Pattern = 0x%x \n",
		 Address, Length,TestCount,Pattern));	
    //write each test unit the value with TEST_PATTERN
    for ( i = 0; i < TestCount; i++)
    {
    	     //PEI_DEBUG((PeiServices, EFI_D_ERROR,"1.Write addr = 0x%x , Data = 0x%x \n",(Address + i *4),Pattern));        
            //AsiaMemoryWrite32(Address + i *4, 0x5A5A5A5A);
            AsiaMemoryWrite32(Address + i *4, Pattern);
    }

    //compare each test unit with the value of TEST_PATTERN
    //and write it with compliment of TEST_PATTERN
        for ( i = 0; i < TestCount; i++)
        {
            Data = AsiaMemoryRead32(Address + i * 4);
	        Data1 = AsiaMemoryRead32(Address + i * 4);
			if(Data != Data1)
				{
				  read_error=1;
			      PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error! address 0x%08x = 0x%08x, should be %08x\r\n",
				(UINT32)(Address + i*4),Data,Pattern));
				  bRet = TRUE;
				  AsiaIoWrite8(0x80,0x2E);
				  goto Bst_Error;		
                  break;  //3410-36-LNA-04
				}
			else
				read_error = 0;
			
            if (read_error == 0 && Data != Pattern)
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error! address 0x%08x = 0x%08x, should be %08x\r\n",
				(UINT32)(Address + i*4),Data,Pattern));
				 bRet = TRUE;
				 AsiaIoWrite8(0x80,0x2E);
				 goto Bst_Error;		
                break;  //3410-36-LNA-04
            }
	    		
            AsiaMemoryWrite32(Address + i * 4, (UINT32)(~Pattern));	

	    	 
        }
	////	

	//PEI_DEBUG((PeiServices, EFI_D_ERROR,"%a(%d)+++++++++++++++++++ \r",__FILE__,__LINE__));
    //compare each test unit with the value of ~TEST_PATTERN
        for (i=(TestCount - 1); i >= 0; i--)
        {
            Data = AsiaMemoryRead32(Address + i * 4);
	        Data1 = AsiaMemoryRead32(Address + i * 4);
            if(Data != Data1)
				{
				  read_error=1;
			      PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error! address 0x%08x = 0x%08x, should be %08x\r\n",
				(UINT32)(Address + i*4),Data,~Pattern));
				  bRet = TRUE;
				  AsiaIoWrite8(0x80,0x2E);
				  goto Bst_Error;		
                  break;  //3410-36-LNA-04
				}
			else
				read_error = 0;
			
            if (read_error == 0 && Data != ~Pattern)
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error! address 0x%08x = 0x%08x, should be %08x\r\n",
				(UINT32)(Address + i*4),Data,~Pattern));
				 bRet = TRUE;
				 AsiaIoWrite8(0x80,0x2E);
				 goto Bst_Error;		
                break;  //3410-36-LNA-04
            }
        }

	//PEI_DEBUG((PeiServices, EFI_D_ERROR,"%a(%d) End-Burst-Test \n",__FILE__,__LINE__));

Bst_Error:
    return bRet;
}


////
