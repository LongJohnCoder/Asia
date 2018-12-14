#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.             **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaPpiLib

AsiaPpiLib : $(BUILD_DIR)\AsiaPpiLib.mak AsiaPpiLibBin

$(BUILD_DIR)\AsiaPpiLib.mak : $(ASIA_DIR)\Interface\Ppi\$(@B).cif $(ASIA_DIR)\Interface\Ppi\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\Interface\Ppi\$(@B).cif $(CIF2MAK_DEFAULTS)

AsiaPpiLibBin : 
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaPpiLib.mak all\
		TYPE=PEI_LIBRARY \
		"CFLAGS=$(CFLAGS) /X" \
		"EXTRA_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32"