PROJECT 	= MicroKit
SRCDIR   	= Src
OBJDIR  	= obj 
BINDIR   	= bin 
SRCs     	= $(wildcard ${SRCDIR}/*.c)
START           = $(wildcard ${SRCDIR}/*.s)
OBJs     	= $(SRCs:src/%.c=obj/%.o)		
OBJs     	+= $(START:src/%.s=obj/%.o)		
BIN             = ${BINDIR}/${PROJECT}.bin
ELF             = ${BINDIR}/${PROJECT}.elf
HEX             = ${BINDIR}/${PROJECT}.hex
LIST            = ${BINDIR}/${PROJECT}.lst
DFU             = ${BINDIR}/${PROJECT}.dfu
DFU_ADDR        = 0x08000000
   
#
# library
#
LIB_ROOT = .
DEVICE = $(LIB_ROOT)/Drivers/CMSIS/Device/ST/STM32F1xx
CORE = $(LIB_ROOT)/Drivers/CMSIS/Include
PERIPH = $(LIB_ROOT)/Drivers/STM32F1xx_HAL_Driver
USBCORE  = $(LIB_ROOT)/Middlewares/ST/STM32_USB_Device_Library/Core
USBCLASS = $(LIB_ROOT)/Middlewares/ST/STM32_USB_Device_Library/Class/CDC
DRIVER_LIB = ${LIB_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/lib
#
# search path
#


vpath %.c $(DEVICE)
vpath %.c $(CORE)
vpath %.c $(PERIPH)/Src
vpath %.c $(DISCOVERY)
vpath %.c $(SYSTEM_FILE)
vpath %.s $(STARTUP_FILE)


OBJDIR = obj
BINDIR = bin
#
# toolchain
#
TOOL_ROOT = /usr/bin
CC = $(TOOL_ROOT)/arm-none-eabi-gcc
LD = $(TOOL_ROOT)/arm-none-eabi-gcc
AR = $(TOOL_ROOT)/arm-none-eabi-ar
OBJCOPY = $(TOOL_ROOT)/arm-none-eabi-objcopy
OBJDUMP = $(TOOL_ROOT)/arm-none-eabi-objdump
DFUTOOL = ../../tools/dfu/dfuse-pack.py

#
# C flags
#
CFLAGS  = -O0 -g -Wall -fdata-sections -ffunction-sections -I.      \
   -mcpu=cortex-m3 -mthumb \
   -I$(DEVICE) -I$(DEVICE)/Include -I$(CORE) -IInc -iquoteInc \
   -I$(PERIPH)/Inc -I$(DISCOVERY) -I$(USBCORE)/Inc -iquote$(USBCORE)/Inc -I$(USBCLASS)/Inc -iquote$(USBCLASS)/Inc \
   -DUSE_STDPERIPH_DRIVER -DSTM32F105xC

#
# loader script
#
LDSCRIPT = ld/STM32F105XC_FLASH.ld

#
# loader flags
#
LDFLAGS+= -T$(LDSCRIPT) -mthumb -mcpu=cortex-m3 -nostdlib 
LDFLAGS+= -L${DRIVER_LIB}
LDFLAGS+= -lSTM32_API
LDFLAGS+= -lrdimon
LDFLAGS+= -Wl,--gc-sections


all: ${OBJDIR} ${BINDIR} ${ELF} ${BIN} ${HEX} ${LIST} ${DFU}

${DRIVER_LIB}/libSTM32_API.a: 
	make -C Drivers/STM32F1xx_HAL_Driver/Src/

#
# .o .c target
#
obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

#
# .o .s target
#
obj/%.o: src/%.s
	$(CC) -c $(CFLAGS) $< -o $@

#
# .elf target
#          
${ELF}: ${OBJs} ${DRIVER_LIB}/libSTM32_API.a
	$(CC) $(LDFLAGS) $(OBJs) -lSTM32_API -o $(ELF)
#
# .bin target
#
${BIN}: ${ELF}
	$(OBJCOPY) -O binary bin/MicroKit.elf bin/MicroKit.bin

#
# .hex target
#
$(HEX): ${ELF}
	$(OBJCOPY) -O ihex ${ELF} ${HEX}

${LIST}: ${ELF}
	$(OBJDUMP) -dSt ${ELF} > ${LIST}

$(DFU): ${HEX}
	${DFUTOOL} -b ${DFU_ADDR}:${HEX} ${DFU}
#
# clean
#
clean:
	make clean -C Drivers/STM32F1xx_HAL_Driver/Src/
	rm -f obj/*
	rm -f bin/*

${OBJDIR}:  
	mkdir -p obj 

${BINDIR}: 
	mkdir -p bin
