#include"DramDebug.h"

typedef unsigned long uintptr_t;

/* Display values from last command.
 * Memory modify remembered values are different from display memory.
 */

static unsigned int	dp_last_length = 0x40;

static	unsigned long base_address = 0;
#define DISP_LINE_LEN	16

extern unsigned long simple_strtoul(const char *cp,char **endp,unsigned int base);
extern void print_buffer(EFI_PEI_SERVICES **PeiServices,unsigned long buf, unsigned long length);

//extern void print_buffer(unsigned int buf, unsigned int length);
static void *map_sysmem(UINT64 paddr, UINT64 len)
{
	return (void *)(uintptr_t)paddr;
}

static void unmap_sysmem(const void *vaddr)
{
    return;
}

#if 0
int cmd_get_data_size(char* arg, int default_size)
{
	/* Check for a size specification .b, .w or .l.
	 */
	int len = strlen(arg);
	if (len > 2 && arg[len-2] == '.') {
		switch(arg[len-1]) {
		case 'b':
			return 1;
		case 'w':
			return 2;
		case 'l':
			return 4;
		case 's':
			return -2;
		default:
			return -1;
		}
	}
	return default_size;
}

#endif


int do_mem_mr(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	unsigned long	addr, length;
	int rc = 0;

	/* We use the last specified parameters, unless new ones are
	 * entered.
	 */

	length = dp_last_length;
	if (argc < 2){

		//printf("%s %s [%d]: parameters less than 2!\r\n", __FILE__, __func__, __LINE__);
		return -2;
	}

	/* New command specified.  Check for a size specification.
	 * Defaults to long if no or incorrect specification.
	 */

	/* Address is specified since argc > 1
	*/
	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	/* If another parameter, it is the length to display.
	 * Length is the number of objects, not number of bytes.
	 */
	if (argc > 2)
		length = simple_strtoul(argv[2], NULL, 16);
	print_buffer(PeiServices,addr, length);
	return (rc);
}



int do_mem_mw64(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 addr, writeval, count;

    
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"call do_mem_mw64\r\n")); 
	if ((argc < 3) || (argc > 4))
		return -2;
	
	/* Address is specified since argc > 1
	*/
	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	/* Get the value to write.
	*/
	writeval = simple_strtoul(argv[2], NULL, 16);

	/* Count ? */
	if (argc == 4) {
		count = simple_strtoul(argv[3], NULL, 16);
	} else {
		count = 1;
	}

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"addr = %08x\r\n",addr));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"writeval = %08x\r\n",writeval));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"count = %08x\r\n",count));
	

	while (count-- > 0) {
		*((VOLATILE UINT64*)(UINTN)(addr))= writeval;
		addr=addr+8;
	}
	return 0;
}

int do_mem_mw32(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 addr, writeval, count;

    
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"call do_mem_mw32\r\n")); 
	if ((argc < 3) || (argc > 4))
		return -2;
	
	/* Address is specified since argc > 1
	*/
	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	/* Get the value to write.
	*/
	writeval = simple_strtoul(argv[2], NULL, 16);

	/* Count ? */
	if (argc == 4) {
		count = simple_strtoul(argv[3], NULL, 16);
	} else {
		count = 1;
	}

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"addr = %08x\r\n",addr));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"writeval = %08x\r\n",writeval));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"count = %08x\r\n",count));
	

	while (count-- > 0) {
		*((VOLATILE UINT32*)(UINTN)(addr))= writeval;
		addr=addr+4;
	}
	return 0;
}
int do_mem_mw16(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 addr, count;
	UINT16 writeval;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"call do_mem_mw16\r\n")); 
	if ((argc < 3) || (argc > 4))
		return -2;
	
	/* Address is specified since argc > 1
	*/
	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	/* Get the value to write.
	*/
	writeval = (UINT16)simple_strtoul(argv[2], NULL, 16);

	/* Count ? */
	if (argc == 4) {
		count = simple_strtoul(argv[3], NULL, 16);
	} else {
		count = 1;
	}

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"addr = %08x\r\n",addr));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"writeval = %08x\r\n",writeval));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"count = %08x\r\n",count));
	

	while (count-- > 0) {
		*((VOLATILE UINT16*)(UINTN)(addr))= writeval;
		addr=addr+2;
	}
	return 0;
}

int do_mem_mw8(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
	UINT32 addr,  count;
	UINT8 writeval;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"call do_mem_mw8\r\n")); 
	if ((argc < 3) || (argc > 4))
		return -2;
	
	/* Address is specified since argc > 1
	*/
	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	/* Get the value to write.
	*/
	writeval = (UINT8)simple_strtoul(argv[2], NULL, 16);

	/* Count ? */
	if (argc == 4) {
		count = simple_strtoul(argv[3], NULL, 16);
	} else {
		count = 1;
	}

    PEI_DEBUG((PeiServices, EFI_D_ERROR,"addr = %08x\r\n",addr));
    PEI_DEBUG((PeiServices, EFI_D_ERROR,"writeval = %08x\r\n",writeval));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"count = %08x\r\n",count));
	

	while (count-- > 0) {
		*((VOLATILE UINT8*)(UINTN)(addr))= writeval;
		addr++;
	}
	return 0;
}


//default do 32bit memory write
int do_mem_mw(
		IN EFI_PEI_SERVICES **PeiServices,		 
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr,
		int argc, char *argv[])
{
    do_mem_mw32(PeiServices, pPCIPPI, DramAttr,argc,argv); 
	return 0;
}




///
///

