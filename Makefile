#******************************************************************************
# Copyright (C) 2018 by Mohamed ABOUELGOUD
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      The supported targets are (see README.md also)
#		main.i
#		main.o
#		main.asm
#		main.d
#		compile-all
#		build
#		clean
#
# Platform Overrides:
#		PLATFORM=HOST
#		PLATFORM=MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Extend path to include GNU Tool Chain
PATH += :../../opt/gcc-arm-none-eabi-7-2018-q2-update/bin/

# Architectures Specific Flags
ifeq ($(PLATFORM),HOST)
LINKER_FILE := 
CPU := 
ARCH := 
SPECS := 
else
LINKER_FILE := -T ../msp432p401r.lds
CPU := cortex-m4
ARCH := thumb
ARCH_FLAGS := -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
SPECS := nosys.specs
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
CC := gcc
else
CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld
endif

TARGET = c1m2
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)

CFLAGS = -g -O0 -std=c99 -Wall -Werror
ifeq ($(PLATFORM),MSP432)
CFLAGS += -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)
endif
CPPFLAGS = $(INCLUDES) -D$(PLATFORM)

# Tool Specfic Defines
ifeq ($(PLATFORM),HOST)
DOSIZE = size
DOOBJDUMP = objdump
else
DOSIZE = arm-none-eabi-size
DOOBJDUMP = arm-none-eabi-objdump
endif

OBJS = $(SRCS:.c=.o)
OBJD = $(SRCS:.c=.d)
OBJI = $(SRCS:.c=.i)
OBJA = $(SRCS:.c=.asm)

# Generate the object output of ALL c-program implementation files.
# Do not link the objects.
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

# Generate the preprocessor output of the corresponding c-program implementation file.
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate the depency ouptut of the corresponding c-program implementation file.
%.d : %.c
	$(CC) -M $< $(CFLAGS) $(CPPFLAGS) -MF $@

# Generate the assembly output of the corresponding c-program implementation file.
%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate the object output of the corresponding c-program implementation file.
%.o:
	$(CC) -S -c $(SRCS) $(CFLAGS) $(CPPFLAGS)

# Compile all the object files and link into a final executable.
.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS) $(OBJD)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(DOSIZE) $(TARGET).out > $(TARGET)_$(PLATFORM).size
	$(DOOBJDUMP) -S $(TARGET).out > $(TARGET)_$(PLATFORM).asm

# Remove all compiled objects, preprocessed outputs, assembly outputs,
# executablefiles and build output etc.
#leaving only the source and make files.
.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJD) $(OBJI) $(OBJA) $(TARGET).out $(TARGET).map \ 			$(TARGET)_$(PLATFORM).*

# Compile all the object files but do not link.
.PHONY: compile-all
compile-all:
	$(CC) -c $(SRCS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)