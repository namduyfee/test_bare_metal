
.PHONY: clean build run

PRO_NAME := toggle_led

PRO_DIR := .
OUT_DIR := $(PRO_DIR)/Output
EXE_DIR := $(PRO_DIR)/Bin

SRC_DIRS := $(PRO_DIR)/Application
SRC_DIRS += $(PRO_DIR)/Application_User/Control_Led/Src
SRC_DIRS += $(wildcard $(PRO_DIR)/Driver/*/Src)

INC_DIRS := $(wildcard $(PRO_DIR)/Driver/*/Inc)
INC_DIRS += $(PRO_DIR)/Application_User/Control_Led/Inc

INC_FILES_PATH := $(foreach dir,$(INC_DIRS),$(wildcard $(dir)/*.h))
SRC_FILES_PATH := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
LINK_FILE_PATH := $(PRO_DIR)/Linker/stm32f103c8t6.ld
OBJ_FILES_PATH := $(foreach dir, $(OUT_DIR), $(wildcard $(dir)/*.o))

INC_FILES := $(notdir $(INC_FILES_PATH))
SRC_FILES := $(notdir $(SRC_FILES_PATH))
OBJ_FILES := $(subst .c,.o,$(SRC_FILES))

COMPILER_DIR := D:/GCC_arm_msys2
CC           := $(COMPILER_DIR)/bin/arm-none-eabi-gcc
ASM          := $(COMPILER_DIR)/bin/arm-none-eabi-as
LD           := $(COMPILER_DIR)/bin/arm-none-eabi-ld
INC_DIRS_OPT := $(foreach dir, $(INC_DIRS), -I$(dir))
CC_OPT       := -mcpu=cortex-m3 -O0 -g -mfloat-abi=soft -std=gnu11 -mthumb $(INC_DIRS_OPT)
LD_OPT		 :=	-T $(LINK_FILE_PATH) -Map $(OUT_DIR)/$(PRO_NAME).map

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)

build: $(OBJ_FILES)
	$(LD) $(LD_OPT) $(OBJ_FILES_PATH) -o $(EXE_DIR)/$(PRO_NAME).elf
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$(EXE_DIR)/$(PRO_NAME).elf" "$(EXE_DIR)/$(PRO_NAME).hex"

%.o: %.c $(INC_FILES_PATH)
	$(CC) -c -o $(OUT_DIR)/$@ $< $(CC_OPT)
	echo "completed $@"

run: 
	$(PRO_DIR)/ST-LinkUtility/ST-LINK_CLI.exe -p "$(EXE_DIR)/$(PRO_NAME).hex" 0x08000000
	$(PRO_DIR)/ST-LinkUtility/ST-LINK_CLI.exe -rst
printvalof-%: ; @echo $($(subst printvalof-,,$@))

print-%: ; @echo $(subst print-,,$@)

clean: ; rm $(OUT_DIR)/*
