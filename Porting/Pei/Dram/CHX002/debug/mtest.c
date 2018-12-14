//#include "loop_core.h"
//#include "Pei.h"
//#include "PeiDebug.h"

////
unsigned int c_iter;
#define TEST_STEP 0x10000
/// unsigned int = 4 bytes
unsigned int gp1 = 0, gp2 = 0;
#define write_l(value,address) *(volatile unsigned int *)(address)=(value)
#define read_l(address)  *(volatile unsigned int *)(address)
////
/******************************************************************/
/* concatenation of following two 16-bit multiply with carry generators */
/* x(n)=a*x(n-1)+carry mod 2^16 and y(n)=b*y(n-1)+carry mod 2^16, */
/* number and carry packed within the same 32 bit integer.        */
/******************************************************************/
/* return a random float >= 0 and < 1 */
//#define rand_float          ((double)viarand() / 4294967296.0)

#define TESTTRUE 1
#define TESTFALSE 0



//#ifndef __MEM_SCAN__
static unsigned int SEED_X = 521288629;
static unsigned int SEED_Y = 362436069;

static unsigned int delay_count = 1;

unsigned long get_timer_masked(void)
{
     return (unsigned long)1000; 
}

void init_rand_seed(int seed)
{
	SEED_X = 521288629+seed;
	SEED_Y = 362436069-seed;
}

unsigned int viarand (void)
{
    static unsigned int a = 18000, b = 30903;

    SEED_X = a*(SEED_X&65535) + (SEED_X>>16);
    SEED_Y = b*(SEED_Y&65535) + (SEED_Y>>16);

    return ((SEED_X<<16) + (SEED_Y&65535));
}
//#endif 
/*
 * Memory address test, walking ones
 */
void addr_tst1(EFI_PEI_SERVICES **PeiServices,
                 unsigned long test_base_maddr, unsigned long test_length)
{
	int i, j, k;
	volatile unsigned long *pt, *p;
	volatile unsigned long *end;
	unsigned long bad, mask, bank;
	unsigned long p1 = 0;

	/* Test the global address bits */
	for (p1=0, j=0; j<2; j++) {

		/* Set pattern in our lowest multiple of 0x20000 */
		p = (unsigned long*)test_base_maddr;
		*p = p1;

		/* Now write pattern compliment */
		p1 = ~p1;
		end = (unsigned long*)(test_base_maddr+test_length);
		mask = 4;
		for (i=0; i<100; i++) {
			pt = (unsigned long *)((unsigned long)p | mask);
			if (pt == p) {
				mask = mask << 1;
				continue;
			}
			if (pt >= end) {
				break;
			}
			*pt = p1;
			if ((bad = *p) != ~p1) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",
					(unsigned long)p,(unsigned long)bad,(unsigned long)p1));
				i = 1000;
			}
			mask = mask << 1;
		}
	}

	/* Now check the address bits in each bank */
	/* If we have more than 8mb of memory then the bank size must be */
	/* bigger than 256k.  If so use 1mb for the bank size. */
	bank = 0x100000;
	for (p1=0, k=0; k<2; k++) {
		p = (unsigned long*)test_base_maddr;
		/* Force start address to be a multiple of 256k */
		end = (unsigned long*)(test_base_maddr+test_length);
		while ((unsigned int)p < (unsigned int)end) {
			*p = p1;

			p1 = ~p1;
			for (i=0; i<200; i++) {
				mask = 4;
				do {
					pt = (unsigned long *)((unsigned long)p | mask);
					if (pt == p) {
						mask = mask << 1;
						continue;
					}
					if (pt >= end) {
						break;
					}
					*pt = p1;
					if ((bad = *p) != ~p1) {
						PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",
							(unsigned long)p,(unsigned long)bad,(unsigned long)p1));
						i = 200;
					}
					mask = mask << 1;
				} while(mask);
			}
			if ((p + bank/4) > p) {
				p += bank/4;
			} else {
				p = end;
			}
			p1 = ~p1;
		}
		p1 = ~p1;
	}
}

/*
 * Memory address test, own address
 */
void addr_tst2(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length)
{
	volatile unsigned long *pe, *p;
//	volatile unsigned long bad;
    unsigned int tmp1, tmp2;
	unsigned int read_error = 0;

	/* Write each address with it's own address */

	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);

	/* Original C code replaced with hand tuned assembly code*/
	for (; p < pe; p++) {
		*p = (unsigned long)p;
		//WaitForMicroSec(PeiServices,delay_count);
//		printf("address 0x%lx = 0x%lx\r\n",(unsigned long)p,*p);
	}
 
	/* Each address should have its own address */
			
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);

			
	/* Original C code replaced with hand tuned assembly code */
	for (; p < pe; p++) {
		tmp1 = read_l((unsigned long)p);
		//WaitForMicroSec(PeiServices,delay_count);
		tmp2 = read_l((unsigned long)p);
        //WaitForMicroSec(PeiServices,delay_count);
		if(tmp1 != tmp2)
		{
		    read_error=1;
			AsiaIoWrite8(0x80,0x2E);
			//LGE20160322
			AsiaMemoryWrite32(tmp1,tmp1);
			AsiaMemoryWrite32((unsigned long)p,(unsigned long)p);
			AsiaMemoryRead32((unsigned long)p);
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error! address 0x%8x = 0x%8x, should be %8x\r\n",
				(unsigned long)p,(unsigned long)tmp1,(unsigned long)p));
		}
		else 
			  read_error=0;
		if(read_error == 0 && tmp1!= (unsigned long)p){
			AsiaIoWrite8(0x80,0x2E);
			//LGE20160322
			AsiaMemoryWrite32(tmp1,tmp1);
			AsiaMemoryWrite32((unsigned long)p,(unsigned long)p);
			AsiaMemoryRead32((unsigned long)p);

			
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error! address 0x%8x = 0x%8x, should be %8x\r\n",
				(unsigned long)p,(unsigned long)tmp1,(unsigned long)p));

			}
		//// print ... for indicating not hang, is running. tiger. 2014-11-19+S
		   if(((UINTN)p%0x10000)==0) 
		        PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		//// End of 2014-11-19+E			

		}
	
}

/*
 * Test all of memory using a "half moving inversions" algorithm using random
 * numbers and their complment as the data pattern. Since we are not able to
 * produce random numbers in reverse order testing is only done in the forward
 * direction.
 */
void movinvr(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length)
{
	int i;
	volatile unsigned long *pe, *p;
	unsigned long num;
	unsigned long bad; 
	int seed = get_timer_masked() & 0xff;
	
	/* Initialize memory with initial sequence of random numbers.  */
	init_rand_seed(seed);
//	printf("init seedx = 0x%x, seedy = 0x%x\r\n",SEED_X,SEED_Y);
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);
/* Original C code replaced with hand tuned assembly code */
	for (; p < pe; p++) {
		*p = viarand();
//		printf("address 0x%lx = 0x%lx\r\n",(unsigned long)p,(unsigned long)*p);
	}


	/* Do moving inversions test. Check for initial pattern and then
	 * write the complement for each memory location. Test from bottom
	 * up and then from the top down.  */
	for (i=0; i<2; i++) {
		
		p = (unsigned long*)test_base_maddr;
		pe = (unsigned long*)(test_base_maddr+test_length);

/* Original C code replaced with hand tuned assembly code */
		init_rand_seed(seed);
//		printf("use seedx = 0x%x, seedy = 0x%x\r\n",SEED_X,SEED_Y);
		for (; p < pe; p++) {
			
			num = viarand();
//			printf("num = 0x%lx\r\n",num);
			if (i) {
				num = ~num;
			}
			if ((bad=*p) != num) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",
					(unsigned long)p,(unsigned long)bad,(unsigned long)num));
			}
			*p = ~num;
		}

	}
}
////
/*
 * Test all of memory using a "moving inversions" algorithm using the
 * pattern in p1 and it's complement in p2.
 */
#define __READ_WRITE_ERROR__
#define READ_CMP_TIMES 6
void movinv1(EFI_PEI_SERVICES **PeiServices,unsigned int test_base, unsigned int test_length, int iter, unsigned int p1, unsigned int p2)
{
    volatile unsigned int test_addr;
    volatile unsigned int start, end;
    unsigned int	bad;
#ifdef __READ_WRITE_ERROR__
	unsigned int tmp1, tmp2;
	unsigned int read_error = 0 ;
	unsigned int read;
#else
	unsigned int tmp;
#endif
	int i = 0;
	
    //printf("movinv1: 1\r\n");

    /* Initialize memory with the initial pattern.  */
	for(i=0;i<iter;i++){
	    start = test_base;
	    end = test_base+test_length;
	    test_addr = start;

	    for (; test_addr < end; test_addr+=4)
	    {
	        /// write 4 bytes every time.
	        write_l(p1,test_addr);
			//WaitForMicroSec(PeiServices,delay_count);
	    }
	    ////
  	    PEI_DEBUG((PeiServices, EFI_D_INFO, "\n Delay some time, then do read test \n"));
	    VSoft_Delay(0x7000000);		    
	    ////
	    /* Do moving inversions test. Check for initial pattern and then
	     * write the complement for each memory location. Test from bottom
	     * up and then from the top down.  */
	   
		test_addr = start;

	    bad=p1;
	    for (; test_addr < end; test_addr+=4)
	    {
	    #ifdef __READ_WRITE_ERROR__
			read_error = 0;
			
			tmp1 = read_l(test_addr);
			//WaitForMicroSec(PeiServices,delay_count);
			tmp2 = read_l(test_addr);
			//WaitForMicroSec(PeiServices,delay_count);
			for(read = 0; read < READ_CMP_TIMES; read++){
				if(tmp1 != tmp2){
					read_error = 1;
					PEI_DEBUG((PeiServices, EFI_D_ERROR,"%s(%d)read error: address %8x = %8x, should be %8x, iter = %x\r\n", __FILE__, __LINE__, test_addr, tmp1, p1, i));
					break;
				}else{
					read_error = 0;
					tmp2 = read_l(test_addr);
				}
			}
			if((read_error == 0) && bad != tmp1){
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"%s(%d)write error: address %8x = %8x, should be %8x, iter = %x\r\n", __FILE__, __LINE__, test_addr, tmp1, p1, i));
			}
		#else 
			tmp = read_l(test_addr);
	        if (bad != tmp)
	            PEI_DEBUG((PeiServices, EFI_D_ERROR,"error: address %8x = %8x, should be %8x\r\n", test_addr, tmp, p1));
			////
	       
		#endif
			 write_l(p2,test_addr);
		    //// print ... for indicating not hang, is running. tiger. 2014-11-19+S
    		   if((test_addr%0x10000)==0) 
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "."));
		    //// End of 2014-11-19+E			
	    }
	}
    return;
}

////
void moving_inversions(EFI_PEI_SERVICES **PeiServices,unsigned int test_base, unsigned int test_length)
{
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"Hello, Reter @ moving_inversions\r\n"));

    gp1 = 0;
    gp2 = ~gp1;
    movinv1(PeiServices,test_base, test_length, 1, gp1,gp2);

    /* Switch patterns */
#if 0
	gp2 = gp1;
    gp1 = ~gp2;
    movinv1(test_base, test_length, 1, gp1,gp2);
#endif
    return;
}

unsigned long rotate_left(unsigned long pat, int shift)
{
	int i = 0, tmp = 0;
		
	i = 0;
	while(i<shift){
		if(0x80000000 & pat)
			tmp = 1;
		else
			tmp = 0;
		pat <<= 1;
		pat |= tmp;
		i++;
	}
	return pat;
}

void movinv32(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length, 
	int iter, unsigned long p1, unsigned long lb, unsigned long hb, int sval, int off)
{
	int i, k=0;
	volatile unsigned long *pe, *p;
	unsigned long pat = 0, bad = 0;
	unsigned long p3 = sval<<31;

	/* Initialize memory with the initial pattern.  */
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr + test_length);
	k = off;
	pat = p1;


	/* Do a SPINSZ section of memory */
	/* Original C code replaced with hand tuned assembly code */
	while (p < pe) {
		*p = pat;
//		printf("address 0x%lx, pat = 0x%lx\r\n",(unsigned long)p,pat);
		if (++k >= 32) {
			pat = lb;
			k = 0;
		} else {
			pat = pat << 1;
			pat |= sval;
		}
		p++;
	}



	/* Do moving inversions test. Check for initial pattern and then
	 * write the complement for each memory location. Test from bottom
	 * up and then from the top down.  */
	for (i=0; i<iter; i++) {
		
		p = (unsigned long*)test_base_maddr;
		pe = (unsigned long*)(test_base_maddr+test_length);
		k = off;
		pat = p1;

		/* Original C code replaced with hand tuned assembly code */
		while (p < pe) {
			if ((bad=*p) != pat) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",
					(unsigned long)p, (unsigned long)bad, (unsigned long)pat));
			}
			*p = ~pat;
//			printf("address 0x%lx, pat = 0x%lx\r\n",(unsigned long)p,~pat);
			if (++k >= 32) {
				pat = lb;
				k = 0;
			} else {
				pat = pat << 1;
				pat |= sval;
			}
			p++;
		}
	}
	
		/* Since we already adjusted k and the pattern this
		 * code backs both up one step
		 */
		 /*
		if(0 != (k = (k-1) & 31)){
	 		pat = lb<<off;
			if(pat==0)
				pat = lb;
			if(sval)
				pat |= ((sval<<off)-1);
		}else
			pat = lb;
		k++;*/
		pat = rotate_left(lb, off);
		/*
		pat = lb;
 		if ( 0 != (k = (k-1) & 31) ) {
 			pat = (pat << k);
 			if ( sval ) 
 			pat |= ((sval << k) - 1);
 		}
 		k++;*/
// 		printf("pat = %lx, k = %x\r\n",pat,k);
		
		p = (unsigned long*)test_base_maddr;
		pe = (unsigned long*)(test_base_maddr+test_length);	
		/* Original C code replaced with hand tuned assembly code */
		do {
			if ((bad=*p) != ~pat) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",
					(unsigned long)p, (unsigned long)bad, (unsigned long)~pat));
			}
			*p = pat;
			if (--k <= 0) {
				pat = hb;
				k = 32;
			} else {
				pat = pat >> 1;
				pat |= p3 ;
			}
		} while (p-- > pe);
}


#define MOD_SZ 20
/*
 * Test all of memory using modulo X access pattern.
 */
void modtst(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length, int 
	offset, int iter, unsigned long p1, unsigned long p2)
{
	int i,k;
	volatile unsigned long *pe, *p;
	unsigned long bad;

	/* Write every nth location with pattern */
	p = (unsigned long*)test_base_maddr+offset;
	pe = (unsigned long*)(test_base_maddr+test_length);

	for(; p < pe; p += MOD_SZ){
		*p = p1;
		
	}
//	printf("wrong\r\n");
	/* Write the rest of memory "iter" times with the pattern complement */
	for (i=0; i<iter; i++) {
		p = (unsigned long*)test_base_maddr;
		pe = (unsigned long*)(test_base_maddr+test_length);
		k = 0;
		
	/* Original C code replaced with hand tuned assembly code */
		for (; p < pe; p++) {
			if (k != offset) {
				*p = p2;
			}
//			printf("address 0x%lx = 0x%lx\r\n",(unsigned long)p,*p);
			if (++k > MOD_SZ-1) {
				k = 0;
			}
		}
	}
	/*
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);
	for(;p<pe;p++)
		printf("address 0x%lx = 0x%lx\r\n",(unsigned long)p,*p);
	printf("over\r\n");*/
	/* Now check every nth location */

	p = (unsigned long*)test_base_maddr+offset;
	pe = (unsigned long*)(test_base_maddr+test_length);

	/* Original C code replaced with hand tuned assembly code */
	for (; p < pe; p += MOD_SZ) {
		if ((bad=*p) != p1) {
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",
				(unsigned long)p, (unsigned long)bad, (unsigned long)p1));
		}
	}

}


/*
 * Test memory using block moves
 * Adapted from Robert Redelmeier's burnBX test
 */
void block_move(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length, 
	int iter)
{
	int i;
	unsigned long len;
	volatile unsigned long *p, *pe, *pp;
	unsigned long pat = 1;

	
	/* Initialize memory with the initial pattern.  */

		
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);
	len = test_length/64;
//	len  = ((unsigned long)pe - (unsigned long)p) / 64;
	
	while(len){
		*p = pat;
		*(p+1) = pat;
		*(p+2) = pat;
		*(p+3) = pat;
		*(p+4) = ~pat;
		*(p+5) = ~pat;
		*(p+6) = pat;
		*(p+7) = pat;
		*(p+8) = pat;
		*(p+9) = pat;
		*(p+10) = ~pat;
		*(p+11) = ~pat;
		*(p+12) = pat;
		*(p+13) = pat;
		*(p+14) = ~pat;
		*(p+15) = ~pat;
		pat<<=1;
		if(pat==0)
			pat = 1;
		p = p+64/sizeof(unsigned long);
		len--;
	};
/*	
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);	
	while(p<pe){
		
		printf("address 0x%lx = 0x%lx \r\n",(unsigned long)p,*p);
		p++;

	}
	*/
	/* Now move the data around
	 * First move the data up half of the segment size we are testing
	 * Then move the data to the original location + 32 bytes
	 */
	
	
	for(i=0; i<iter; i++) {
		p = (unsigned long*)test_base_maddr;
		pe = (unsigned long*)(test_base_maddr+test_length);

			
		pp = p + ((pe - p) / 2);
		len  = ((unsigned long)pe - (unsigned long)p) / 8;
//		printf("pp = 0x%lx, p = 0x%lx, len = 0x%lx\r\n", (unsigned long)pp, (unsigned long)p, 
//			(unsigned long)len);
		
		while(len--){
			*pp++ = *p++;
		}
		
		len = test_length/8;
//		len  = ((unsigned long)pe - (unsigned long)p) / 8;
		p = (unsigned long*)test_base_maddr;
		pp = p + ((pe - p) / 2);
		p += 8;
		len -= 8;
		while(len--){
			*p++ = *pp++;
		}

		len=8;
		p = (unsigned long*)test_base_maddr;
		while(len--){
			*p++ = *pp++;
		}
		/*
		p = (unsigned long*)test_base_maddr;
		pe = (unsigned long*)(test_base_maddr+test_length);	
		while(p<pe){
			
			printf("address 0x%lx = 0x%lx \r\n",(unsigned long)p,*p);
			p++;

		}
		while(1);*/
	}
	/* Now check the data
	 * The error checking is rather crude.  We just check that the
	 * adjacent words are the same.
	 */
	p = (unsigned long*)test_base_maddr;
	pe = (unsigned long*)(test_base_maddr+test_length);
	L120:
	if(*p!=*(p+1)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%8lx = 0x%8lx, should be %8lx\r\n",(unsigned long)p,(unsigned long)*p,*p));
		p += 2;
		if(p<pe){
//			printf("p = 0x%lx, pe = 0x%lx\r\n",(unsigned long)p,(unsigned long)pe);
			goto L120;
		}
		
	}
	
}
void bit_fade(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length)
{

	volatile unsigned long bad;
	volatile unsigned long *start,*end;
	volatile unsigned long *p;
	unsigned long p1 = 0;

	start = (unsigned long*)test_base_maddr;
	end = (unsigned long*)(test_base_maddr+test_length);
	

	/* Do -1 and 0 patterns */
	p1 = 0;

	while(1){	
		for (p=start; p<end; p++) {
			*p = p1;
		}
		
		/* Snooze for 30 minutes */
		//udelay(30*60*1000*1000);

		/* Make sure that nothing changed while sleeping */
		start = (unsigned long*)test_base_maddr;
		end = (unsigned long*)(test_base_maddr+test_length);
		for (p=start; p<end; p++) {
			if ((bad=*p) != p1) {
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"error! address 0x%lx = 0x%lx, should be %lx\r\n",
					(unsigned long)p,(unsigned long)bad,(unsigned long)p1));
			}
		}

		if (p1 == 0) {
			p1= (unsigned long)(-1);
		}else
			break;
	}
}

////

void random_pattern(EFI_PEI_SERVICES **PeiServices,unsigned int test_base, unsigned int test_length)
{
#if 0

    int i;
    c_iter=4;

    for(i=0;i<c_iter;i++)
    {
        gp1 = viarand();
        gp2 = ~gp1;
        movinv1(PeiServices,test_base, test_length, 1, gp1,gp2);
        PEI_DEBUG((PeiServices, EFI_D_ERROR,"random_pattern No.%d: %8x\r\n",i, gp1));
        //printf("random_pattern %x: %x\r\n",i, ReadMemDword(test_base));
    }
#endif
    return;
}
void shift_pattern(EFI_PEI_SERVICES **PeiServices,unsigned int test_base, unsigned int test_length, unsigned int test_pattern)
{
    volatile unsigned int test_addr;
    volatile unsigned int start, end;
//    unsigned int	pattern;
    //unsigned int	bad;
    unsigned int record_bit32;
    record_bit32=0;
    start = test_base;
    end = test_base+test_length;
    test_addr = start;
//    pattern=test_pattern;

    for (; test_addr < end; test_addr+=4)
    {
        //left shift (Arithmetic)
        record_bit32=test_pattern>>31;
        test_pattern=test_pattern<<1;
        test_pattern|=record_bit32;
        write_l(test_pattern,test_addr);
    }

    record_bit32=0;
    test_addr = start;
//    pattern=test_pattern;
    for (; test_addr < end; test_addr+=4)
    {
        //left shift (Arithmetic)
        record_bit32=test_pattern>>31;
        test_pattern=test_pattern<<1;
        test_pattern|=record_bit32;
        if (test_pattern !=  read_l(test_addr))
            PEI_DEBUG((PeiServices, EFI_D_ERROR,"%x is incorrect: %x\r\n", test_addr, read_l(test_addr)));
    }

}
void address_is_pattern(EFI_PEI_SERVICES **PeiServices,unsigned int test_base, unsigned int test_length)
{
    volatile unsigned int test_addr;
    volatile unsigned int start, end;
#ifdef __READ_WRITE_ERROR__
	unsigned int tmp1, tmp2;
	unsigned int read, read_error; 
#else
	unsigned int tmp;
#endif
    //unsigned int bad;

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"Hello, Reter @ address_is_pattern\r\n"));

    start = test_base;
    end = test_base+test_length;
    test_addr = start;

//print_TSC();
    for (; test_addr < end; test_addr+=4)
    {
        write_l(test_addr, test_addr);
    }
//print_TSC();

    test_addr = start;
    for (; test_addr < end; test_addr+=4)
    {
    #ifdef __READ_WRITE_ERROR__	
		read_error = 0;
		tmp1 = read_l(test_addr);
		tmp2 = read_l(test_addr);
		for(read = 0; read < READ_CMP_TIMES; read++){
			if(tmp1 != tmp2){
				read_error = 1;
				PEI_DEBUG((PeiServices, EFI_D_ERROR,"read error: address %8x = %8x, should be %8x\r\n", test_addr, tmp1, test_addr));
				break;
			}else{
				read_error = 0;
				tmp2 = read_l(test_addr);
			}
		}
		if((read_error == 0) && test_addr != tmp1){
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"write error: address %8x = %8x, should be %8x\r\n", test_addr, tmp1, test_addr));
		}
	#else 
		tmp = read_l(test_addr);
        if (test_addr !=  tmp)
            PEI_DEBUG((PeiServices, EFI_D_ERROR,"error: address%8x = %8x, should be %8x\r\n", test_addr, tmp, test_addr));
	#endif
	}


}

////
void write_4stream_32K(unsigned int test_base)
{
    int loop_32K;
	unsigned int addr_0000;
    unsigned int addr_2FFC;
    unsigned int addr_4000;
    unsigned int addr_6FFC;
    addr_0000=test_base;
    addr_2FFC=test_base+0x2000+0x1FFC;;
    addr_4000=test_base+0x4000;
    addr_6FFC=test_base+0x6000+0x1FFC;

    /*
     *	 32 (Kbytes) / 64 (bytes/loop)  = 512 loops (4 stream)
     * or 0x2000 (Kbytes) / 0x0010 (bytes/loop) = 0x200 loops per stream = 512 loops per stream
     */
    for(loop_32K=0; loop_32K<512; loop_32K++)
    {
        write_l(addr_0000, addr_0000);
        write_l(addr_2FFC, addr_2FFC);
        write_l(addr_4000, addr_4000);
        write_l(addr_6FFC, addr_6FFC);
        write_l(addr_0000+4, addr_0000+4);
        write_l(addr_2FFC-4, addr_2FFC-4);
        write_l(addr_4000+4, addr_4000+4);
        write_l(addr_6FFC-4, addr_6FFC-4);
        write_l(addr_0000+8, addr_0000+8);
        write_l(addr_2FFC-8, addr_2FFC-8);
        write_l(addr_4000+8, addr_4000+8);
        write_l(addr_6FFC-8, addr_6FFC-8);
        write_l(addr_0000+12, addr_0000+12);
        write_l(addr_2FFC-12, addr_2FFC-12);
        write_l(addr_4000+12, addr_4000+12);
        write_l(addr_6FFC-12, addr_6FFC-12);
        addr_0000+=16;
        addr_2FFC-=16;
        addr_4000+=16;
        addr_6FFC-=16;
    }
    return;
}

////
void write_4stream(unsigned int test_base, unsigned int test_length)
{
    
    int count_32k, total_count_32k;
    int test_addr;
	total_count_32k=test_length/0x8000;
	test_addr = test_base;
    for(count_32k=0; count_32k<total_count_32k; count_32k++)
    {
        write_4stream_32K(test_addr);//wrtie every 32k bytes = 0x8000
        test_addr+=0x8000;
    }
    return;
}

////
unsigned int get_cyclecount (void)
{
    unsigned int value;
    // Read CCNT Register
    value=1;
    return value;
}

////
static void init_perfcounters (int do_reset, int enable_divider)
{
// in general enable all counters (including cycle counter)
    int value = 1;

// peform reset:
    if (do_reset)
    {
        value |= 2;     // reset all counters to zero.
        value |= 4;     // reset cycle counter to zero.
    }

    if (enable_divider)
        value |= 8;     // enable "by 64" divider for CCNT.

    value |= 16;


}

////
void read_range(unsigned int test_base, unsigned int test_length)
{
    unsigned int index_dw;
	index_dw = 0;
//    unsigned int tmp_dw1 = 0;

    for(index_dw = 0; index_dw < test_length; index_dw+=4)
    {
//        tmp_dw1 = read_l(test_base+index_dw);
		read_l(test_base+index_dw);
//        if(index_dw%16 == 0)		
//			printf("%8x: ", test_base+index_dw);
		
//        printf("%8x ", tmp_dw1);
//        if(index_dw%16 == 12)		
//			printf("\r\n");
    }
    return;
}
void write_range(unsigned int test_base, unsigned int test_length, unsigned int test_pattern)
{
    unsigned int index_dw ;
	index_dw = 0;
    for(index_dw = 0; index_dw < test_length; index_dw+=4)
    {
    	write_l(test_pattern, test_base + index_dw);
//        if(index_dw%16 == 0)		
//			printf("%8x: ", test_base+index_dw);
		////
//        printf("%8x ", tmp_dw1);
//        if(index_dw%16 == 12)		
//			printf("\r\n");
    }
    return;
}

void forever_write(unsigned int test_address, unsigned int test_pattern)
{
    for(;;)
    {
        write_l(test_pattern,test_address);
        //PEI_DEBUG((PeiServices, EFI_D_ERROR,"."));
    }
    return;
}

struct tseq {
	short cache;
	short item;
	short iter;
	short errors;
	char *msg;
};

///
const struct tseq tseq[] = {
	{1,  0,   4, 0, "[Moving inversions, ones & zeros]     "},
	{1,  1,   2, 0, "[Moving inversions, 8 bit pattern]    "},
	{1,  2,   1, 0, "[Moving inversions, 32 bit pattern]   "},
	{1,  3,   1, 0, "[mov, 90 min, 2 patterns]   "},
	{1,  4,   1, 0, "[Bit fade test, 90 min, 2 patterns]   "},
	{1,  5,   4, 0, "[Address test, walking ones]          "},
	{1,  6,   4, 0, "[Address test, own address]           "},
	{1,  7,  80, 0, "[Block move, 80 moves]                "},
	{1,  8,   1, 0, "[Bit fade test, 90 min, 2 patterns]   "},
	{1,  9,  30, 0, "[Random number sequence]              "},
	{1, 10,  50, 0, "[Moving inversions, random pattern]   "},
  	{1, 11,   1, 0, "[Modulo 20, Random pattern]           "}
};

#if 0
int do_mem_test(EFI_PEI_SERVICES **PeiServices,unsigned long test_base_maddr, unsigned long test_length)
{
	unsigned long p1,p2,p0,i,item,j;
//	unsigned long test_base_maddr, test_length;

//	test_base_maddr = 0;
//	test_length = 0;
//	printf("sizeof tseq = %x\r\n",sizeof(tseq)/(sizeof(struct tseq)));
	for(item=0;item<sizeof(tseq)/(sizeof(struct tseq));item++){
		switch(tseq[item].item) {

		/* Now do the testing according to the selected pattern */
		case 0:	/* Moving inversions, all ones and zeros (test #2) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"moving inversions, all ones and zeros (test #2)\r\n"));
			p1 = 0;
			p2 = ~p1;
			movinv1(PeiServices,test_base_maddr,test_length,tseq[item].iter,p1,p2);
			

			/* Switch patterns */
			p2 = p1;
			p1 = ~p2;
			movinv1(PeiServices,test_base_maddr,test_length,tseq[item].iter,p1,p2);
			
			break;
			
		case 1: /* Moving inversions, 8 bit walking ones and zeros (test #3) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Moving inversions, 8 bit walking ones and zeros (test #3)\r\n"));
			p0 = 0x80;
			for (i=0; i<8; i++, p0=p0>>1) {
				p1 = p0 | (p0<<8) | (p0<<16) | (p0<<24);
				p2 = ~p1;
				movinv1(PeiServices,test_base_maddr,test_length,tseq[item].iter,p1,p2);
				
		
				/* Switch patterns */
				p2 = p1;
				p1 = ~p2;
				movinv1(PeiServices,test_base_maddr,test_length,tseq[item].iter,p1,p2);
			
			}
			break;

		case 2: /* Moving inversions, 32 bit shifting pattern (test #6) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Moving inversions, 32 bit shifting pattern (test #6)\r\n"));
			for (i=0, p1=1; p1; p1=p1<<1, i++) {
				movinv32(PeiServices,test_base_maddr, test_length, tseq[item].iter, p1, 
					1, 0x80000000, 0, i);
				
				
				movinv32(PeiServices,test_base_maddr,test_length,tseq[item].iter,~p1, 0xfffffffe,
					0x7fffffff, 1, i);
				
			}

			break;

		case 3: /* Modulo 20 check, all ones and zeros (unused) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Modulo 20 check, all ones and zeros (test #10)\r\n"));
			p1=0;
			for (i=0; i<MOD_SZ; i++) {
				p2 = ~p1;
				
				modtst(PeiServices,test_base_maddr,test_length,i, tseq[item].iter, p1, p2);
				

				/* Switch patterns */
				p2 = p1;
				p1 = ~p2;
				modtst(PeiServices,test_base_maddr,test_length,i, tseq[item].iter, p1,p2);
				
			}
			break;

		case 4: /* Modulo 20 check, 8 bit pattern (unused) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Modulo 20 check, 8 bit pattern (test #11)\r\n"));
			p0 = 0x80;
			for (j=0; j<8; j++, p0=p0>>1) {
				p1 = p0 | (p0<<8) | (p0<<16) | (p0<<24);
				for (i=0; i<MOD_SZ; i++) {
					p2 = ~p1;
					modtst(PeiServices,test_base_maddr,test_length,i, tseq[item].iter, 
						p1, p2);
					

					/* Switch patterns */
					p2 = p1;
					p1 = ~p2;
					modtst(PeiServices,test_base_maddr,test_length,i, tseq[item].iter, 
						p1, p2);
					
				}
			}
			break;
		case 5: /* Address test, walking ones (test #0) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Address test, walking ones (test #0)\r\n"));
			addr_tst1(PeiServices,test_base_maddr,test_length);
			
			break;

		case 6: /* Address test, own address (test #1) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Address test, own address (test #1)\r\n"));
//			address_is_pattern(test_base_maddr, test_length);
			addr_tst2(PeiServices,test_base_maddr,test_length);
			break;

		case 7: /* Block move (test #5) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Block move (test #5)\r\n"));
			block_move(PeiServices,test_base_maddr,test_length,tseq[item].iter));
//			while(1);
			break;
		case 8: /* Bit fade test (test #9) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Bit fade test (test #9)\r\n"));
	//		printf("Bit fade test disabled (test #9)\r\n");
	//		bit_fade(test_base_maddr,test_length);
			
			
			break;
		case 9: /* Random Data Sequence (test #7) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Random Data Sequence (test #7)\r\n"));
			for (i=0; i < tseq[item].iter; i++) {
				movinvr(PeiServices,test_base_maddr,test_length);			
			}
			break;
		case 10: /* Random Data (test #4) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Random Data (test #4)\r\n"));
			init_rand_seed(get_timer_masked()&0xff);
			for (i=0; i < tseq[item].iter; i++) {
				p1 = viarand();
				p2 = ~p1;
				movinv1(PeiServices,test_base_maddr,test_length,2,p1,p2);
				
			}
			break;

		case 11: /* Modulo 20 check, Random pattern (test #8) */
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"Modulo 20 check, Random pattern (test #8)\r\n"));
			for (j=0; j<tseq[item].iter; j++) {
				init_rand_seed(get_timer_masked() & 0xff);
				p1 = viarand();
				for (i=0; i < MOD_SZ; i++) {
					p2 = ~p1;
					modtst(PeiServices,test_base_maddr,test_length,i, 1, p1, p2);
					

					/* Switch patterns */
					p2 = p1;
					p1 = ~p2;
					modtst(PeiServices,test_base_maddr,test_length,i, 1, p1, p2);				
				}
			}
			
			break;
		}
	}
	return 0;
}
#endif
void MTest_Fun0(EFI_PEI_SERVICES **PeiServices,unsigned int dwBaseAddr, unsigned int dwLen)
{
    unsigned int test_base; // 256MB
    //unsigned int test_length = 0x100000; // 1MB
    unsigned int test_4k;//4  //4K
    //unsigned int test_pattern;
    //unsigned int test_address;
    test_base = dwBaseAddr;
	test_4k = dwLen;//4  
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"MTest_Fun0 -- read test !!\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));


    //init_perfcounters(1,0);
    read_range(test_base, test_4k);
    //print_TSC();

   PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"Hello, End of MTest_Fun0!!\r\n"));

}

///
void MTest_Fun1(EFI_PEI_SERVICES **PeiServices,unsigned int dwBaseAddr, unsigned int dwLen)
{
    unsigned int test_base ;
    //unsigned int test_length = 0x100000; // 1MB
    unsigned int test_4k ;//4  //4K
    //unsigned int test_pattern;
    //unsigned int test_address;
    test_base = dwBaseAddr;
	test_4k = dwLen;//4  
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"MTest_Fun1 -- moving-inversion test!!\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));


    //init_perfcounters(1,0);

    //test_address=0x10000000;
    //test_pattern=0xFFFFFFFF;
//	forever_write(test_address, test_pattern);

    moving_inversions(PeiServices,test_base, test_4k);

    //print_TSC();

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of MTest_Fun1!!\r\n"));
}

////
void MTest_Fun2(EFI_PEI_SERVICES **PeiServices,unsigned int dwBaseAddr, unsigned int dwLen)
{
    unsigned int test_base;
    //unsigned int test_length = 0x100000; // 1MB
    unsigned int test_4k;//4  //4K
    //unsigned int test_pattern;
    //unsigned int test_address;
    test_base = dwBaseAddr;
	test_4k = dwLen;//4  
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"MTest_Fun2 --- Random pattern test!!\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));


    //init_perfcounters(1,0);

    //test_address=0x10000000;
    //test_pattern=0xFFFFFFFF;

    random_pattern(PeiServices,test_base, test_4k);

    //print_TSC();

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of MTest_Fun2!!\r\n"));
}

////
void MTest_Fun3(EFI_PEI_SERVICES **PeiServices,unsigned int dwBaseAddr, unsigned int dwLen)
{
    unsigned int test_base;
    //unsigned int test_length = 0x100000; // 1MB
    unsigned int test_4k;//4  //4K
    //unsigned int test_pattern;
    //unsigned int test_address;
    test_base = dwBaseAddr;
	test_4k = dwLen;//4  
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"MTest_Fun3 -- Address is pattern test!!\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));


    //init_perfcounters(1,0);

    //test_address=0x10000000;
    //test_pattern=0xFFFFFFFF;

    address_is_pattern(PeiServices,test_base, test_4k);
//	test_pattern=0x11111111;
//	shift_pattern(test_base, test_4k, test_pattern);

    //print_TSC();

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of MTest_Fun3!!\r\n"));
}

////
void MTest_Fun4(EFI_PEI_SERVICES **PeiServices,unsigned int dwBaseAddr, unsigned int dwLen)
{
    //unsigned int test_pattern;
    //unsigned int test_address;

    unsigned int test_base; 
    unsigned int test_length;
    //unsigned int test_4k = 0x1000;//4  //4K

    test_base   = dwBaseAddr;
    test_length = dwLen; // 1MB

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"MTest_Fun4 -- Write_4stream test!!\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));


    //init_perfcounters(1,0);

    //test_address=0x10000000;
    //test_pattern=0xFFFFFFFF;

    //print_TSC();
    write_4stream(test_base, test_length);
    //print_TSC();

   PEI_DEBUG((PeiServices, EFI_D_ERROR,"==============================\r\n"));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"End of MTest_Fun4!!\r\n"));
    //return status;
}

