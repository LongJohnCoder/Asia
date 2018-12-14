#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.               **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
#**********************************************************************
#<AMI_FHDR_START>
#
# Name:	<ComponentName>.mak
#
# Description:	
#
#<AMI_FHDR_END>
#**********************************************************************
all : AsiaCpuDxe

AsiaCpuDxe : $(BUILD_DIR)\AsiaCpuDxe.mak AsiaCpuDxeBin

$(BUILD_DIR)\AsiaCpuPortingLib.lib : AsiaCpuPortingLib

$(BUILD_DIR)\AsiaCpuDxe.mak : $(ASIA_DIR)\Foundation\Dxe\Cpu\$(@B).cif $(ASIA_DIR)\Foundation\Dxe\Cpu\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\Foundation\Dxe\Cpu\$(@B).cif $(CIF2MAK_DEFAULTS) 

AsiaCpuDxeBin : $(BUILD_DIR)\AsiaCpuPortingLib.lib
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaCpuDxe.mak all\
		GUID=10520025-70B2-4d3e-A0DF-40075C220F5A\
		ENTRY_POINT=AsiaCpuDxeEntry\
		TYPE=BS_DRIVER \
		COMPRESS=1\
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\IBV\Common\Include\Dxe \
		/I$(ASIA_DIR)\IBV\Common\Library\Dxe\Include \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\include \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Dxe\Nb \
		/I$(ASIA_DIR)\Interface" \
		"LIBRARIES= \
!IF "$(x64_BUILD)"=="1"
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiDriverLib.lib"
!ELSE
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiDriverLib.lib"
!ENDIF

#**********************************************************************
#**********************************************************************
#**                                                                  **
#**        (C)Copyright 1985-2012, American Megatrends, Inc.         **
#**                                                                  **
#**                       All Rights Reserved.                       **
#**                                                                  **
#**             6145-F Northbelt Pkwy, Norcross, GA 30071            **
#**                                                                  **
#**                       Phone: (770)-246-8600                      **
#**                                                                  **
#**********************************************************************
#**********************************************************************