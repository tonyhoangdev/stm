## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## v3.0 - 20170223
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES and ASMSOURCES
CSOURCES:=main.c
CSOURCES+=pins.c
CSOURCES+=stm8_interrupt_vector.c

# ASMSOURCES:=startup_S32K148.S

## Define SOURCEDIRSDK or SOURCEDIR_LIB
BASEDIR:=../../../../
SOURCEDIRSDK:=platform/devices
SOURCEDIRSDK+=platform/drivers/inc
SOURCEDIRSDK+=platform/drivers/src/pins

SOURCEDIR_LIB:=
# SOURCEDIRSDK+="path not slash"

## Location of objects
OBJECTDIR_NAME:=obj
SOURCEDIR_NAME:=src

# Assenbler file extension
ASM_EXT:=s

# Map file names
MAP_FLASH:=app_flash.map
MAP_RAM:=app_ram.map

## Execute file ##
EXECUTABLE_FLASH:=app_flash.elf
EXECUTABLE_RAM:=app_ram.elf

## OBJ FILE file ##
OBJ_FILE_FLASH:=app_flash.sm8
OBJ_FILE_RAM:=app_ram.sm8

## Toolchain executables ##
CC:=cxstm8
AS:=castm8
LD:=clnk
CV:=cvdwarf
RM:=rm -f
CCSIZE:=cobj

## Toolchain C flags ##
CFLAGS:= +warn +mods0 +debug -pxp -pp -pc99 -l -dSTM8S103F3P
# CFLAGS:=-mcpu=cortex-m4 -mthumb
# CFLAGS+=-DCPU_S32K148
# CFLAGS+=-O1 -g3 -Wall
# CFLAGS+=-c -fmessage-length=0 -ffunction-sections -fdata-sections 
# CFLAGS+=-nostartfiles -nodefaultlibs
#CFLAGS+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
#CFLAGS+=-mfloat-abi=hard -mfpu=fpv4-sp-d16

## Assembly flags
# ASFLAGS:=-mcpu=cortex-m4 -mthumb
# ASFLAGS+=-x assembler-with-cpp
# ASFLAGS+=-O0 -g3
# ASFLAGS+=-nostartfiles -nodefaultlibs
#ASFLAGS+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs

## Linker flags
LDFLAGS_FLASH:= -m $(MAP_FLASH)
LDFLAGS_FLASH+= "blinking_led_mkf.lkf"
# LDFLAGS_FLASH:=-mcpu=cortex-m4 -mthumb
# LDFLAGS_FLASH+=-Wl,-Map=$(MAP_FLASH) -Xlinker --gc-sections
# LDFLAGS_FLASH+=-T"Project_Settings/Linker_Files/S32K1xx_flash.ld" --entry=Reset_Handler
# LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs
#LDFLAGS_FLASH+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
#LDFLAGS_FLASH+=-mfloat-abi=hard -mfpu=fpv4-sp-d16

# LDFLAGS_RAM:=-mcpu=cortex-m4 -mthumb
# LDFLAGS_RAM+=-Wl,-Map=$(MAP_RAM) -Xlinker --gc-sections
# LDFLAGS_RAM+=-T"Project_Settings/Linker_Files/S32K1xx_ram.ld" --entry=Reset_Handler
# LDFLAGS_RAM+=-nostartfiles -nodefaultlibs
#LDFLAGS_RAM+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
#LDFLAGS_RAM+=-mfloat-abi=hard -mfpu=fpv4-sp-d16


## Internal variables
OBJECTS=$(CSOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.$(ASM_EXT)=%.o)

OBJECTDIR=$(OBJECTDIR_NAME)/
COBJECTS=$(addprefix $(OBJECTDIR),$(OBJECTS))

SOURCEDIR=$(SOURCEDIR_NAME)
SOURCEDIR+=$(SOURCEDIR_LIB)
SOURCEDIR+=$(addprefix $(BASEDIR),$(SOURCEDIRSDK))

INCLUDES=$(addprefix -i,$(SOURCEDIR))

SEPARATOR=========================================

## Targets
all: print dir $(EXECUTABLE_FLASH) size build_complete

# Target used to compile C source files
# $<: dependency (%.c)
# $@: target (%.o)
$(OBJECTDIR)%.o: %.c
	@echo -e '$(SEPARATOR)\nCompiling $@'
	@$(CC) $(CFLAGS) $(INCLUDES) -co$(OBJECTDIR) $<
# Target used to compile assembler files
$(OBJECTDIR)%.o: %.s
	@echo -e '$(SEPARATOR)\nCompiling $@'
	@$(AS) $(ASFLAGS) $(INCLUDES) -o$(OBJECTDIR)/$(notdir $@) $<
# Target used to link compiled sources
$(OBJ_FILE_RAM): $(COBJECTS)
	@echo -e '$(SEPARATOR)\nLinking to $(OBJ_FILE_RAM)'
	@$(LD) -o $(OBJ_FILE_RAM) $(LDFLAGS_RAM) $(COBJECTS)
# Target used to link compiled sources
$(OBJ_FILE_FLASH): $(COBJECTS)
	@echo -e '$(SEPARATOR)\nLinking to $(OBJ_FILE_FLASH)'
	@$(LD) -o $(OBJ_FILE_FLASH) $(LDFLAGS_FLASH) $(COBJECTS)
# Target used to convert to elf
$(EXECUTABLE_FLASH): $(OBJ_FILE_FLASH)
	@echo -e '$(SEPARATOR)\nConverting to $(EXECUTABLE_FLASH)'
	@$(CV) $(CVFLAGS) -o $(EXECUTABLE_FLASH) $(OBJ_FILE_FLASH)
# Target used to convert to elf
$(EXECUTABLE_RAM): $(OBJ_FILE_RAM)
	@echo -e '$(SEPARATOR)\nConverting to $(EXECUTABLE_RAM)'
	@$(CV) $(CVFLAGS) -o $(EXECUTABLE_RAM) $(OBJ_FILE_RAM)
# Target used to print executables sizes
size: print $(OBJ_FILE_FLASH)
	@echo '$(SEPARATOR)'
	@echo 'Size of $(OBJ_FILE_FLASH)'
	@$(CCSIZE) -h $(OBJ_FILE_FLASH)

	# @echo 'Size of $(OBJ_FILE_RAM)'
	# @$(CCSIZE) -h $(OBJ_FILE_RAM)
# Target used to print compile informations
print:
	@echo $(SEPARATOR)
	@echo -e '_____Compile C options_____:\n    $(CFLAGS)\n'
	@echo -e '_____Compile ASM options_____:\n    $(ASFLAGS)\n'
	@echo -e '_____LDFLAGS_FLASH options_____:\n    $(LDFLAGS_FLASH)\n'
	@echo -e '_____LDFLAGS_RAM options_____:\n    $(LDFLAGS_RAM)\n'
	@echo -e '_____Includes_____:\n    $(INCLUDES)\n'
build_complete: size
	@echo $(SEPARATOR)
	@echo 'Build completed!'
#Target used to create folder used to store temporary objects
dir:
	@mkdir -p $(OBJECTDIR)
#Target used to remove files and folders
clean:
	@echo $(SEPARATOR)
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(EXECUTABLE_RAM) $(MAP_FLASH) $(MAP_RAM) $(OBJ_FILE_FLASH) $(OBJ_FILE_RAM)

.PHONY: all print dir size clean
