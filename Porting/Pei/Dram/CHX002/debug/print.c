#include"DramDebug.h"


UINT32 MemoryRead32(UINT64 Address)
{ return *((volatile UINT32*)(UINTN)Address); }


void print_buffer(EFI_PEI_SERVICES **PeiServices,unsigned long buf, unsigned long length)
{

        PEI_DEBUG((PeiServices, EFI_D_ERROR,"%08x:  ", (unsigned int)buf));
        while(length){

                PEI_DEBUG((PeiServices, EFI_D_ERROR,"%08x ",MemoryRead32(buf)));
                buf+=4;
				
               if((length+3)%4 == 0){ 
                          PEI_DEBUG((PeiServices, EFI_D_ERROR,"\r\n"));
                          PEI_DEBUG((PeiServices, EFI_D_ERROR,"%08x:  ", (unsigned int)buf));
                }

                length--;
        }

        PEI_DEBUG((PeiServices, EFI_D_INFO,"\r\n"));
}






