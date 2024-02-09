#******************************************************************************
# Copyright (C) 2024 by Jesus Chris
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the cortex-M4 build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES] (PLATFORM=MSP432/ PLATFORM=HOST)
#
# Build Targets:
#      build - Will build executable
#	   address-map - Will build c1m2.map file
#	   <FILE.o> - Will build object files
#	   compile-all - Will build all object file
#	   <FILE>.i - Will build preproccessor files
#	   <FILE>.asm - WIll build assembly files
#	   <FILE>.d - WIll build dependency files
#	   clean - removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#	   ARCH - ARM Architecture (arm, thumb)
#	   SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = "$(LDS)"
CPU = cortex-m4
ARCH = arm
SPECS = nosys.specs
CSTD = c99

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
BASENAME = c1m2
TARGET = $(BASENAME).out
MAP = $(BASENAME).map
LDFLAGS = -Wl,-Map=$(MAP)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -D$(PLATFORM)
CPPFLAGS = -E

#Files
OBJ = main.o memory.o interrupts_msp432p401r_gcc.o startup_msp432p401r_gcc.o system_msp432p401r.o 
PP = main.i memory.i interrupts_msp432p401r_gcc.i startup_msp432p401r_gcc.i system_msp432p401r.i
ASM = main.asm memory.asm interrupts_msp432p401r_gcc.asm startup_msp432p401r_gcc.asm system_msp432p401r.asm
DEP = main.d memory.d interrupts_msp432p401r_gcc.d startup_msp432p401r_gcc.d system_msp432p401r.d 

ifeq ($(PLATFORM),MSP432)
# This PHONY of build was created to prevent any errors that may occur if there is a file \
named build
.PHONY : build
# The cross comipled executable will be compiled here
build : $(OBJ) 
	$(CC) $(INCLUDES) -T$(LINKER_FILE) $(OBJ) $(CFLAGS) -o $(TARGET) 
	size $(TARGET) $(OBJ)


else
# The host compiled executable will be compiled here
build : main.c memory.c 
	gcc -Wall -g -DHOST $(INCLUDES) main.c memory.c -o $(TARGET)
	size $(TARGET)
endif


# This PHONY of address-map was created to prevent any eror that may occur if there is a file \
name address-map
.PHONY : address-map 

ifeq ($(PLATFORM),MSP432)
# This will make the c1m2.map file
address-map : $(OBJ)
	$(CC) $(INCLUDES) $(LDFLAGS) $(OBJ)

else
# This will make the c1m2.map file
address-map : main.o memory.o
	gcc $(INCLUDES) $(LDFLAGS) main.o memory.o
endif


ifeq ($(PLATFORM),MSP432)
# Object files for MSP432 will be compiled preceeding this comment
main.o : main.c
	$(CC) $(INCLUDES) -c -v main.c

memory.o : memory.c
	$(CC) $(INCLUDES) -c memory.c

interrupts_msp432p401r_gcc.o : interrupts_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -c -mcpu=$(CPU) interrupts_msp432p401r_gcc.c

startup_msp432p401r_gcc.o : startup_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -c startup_msp432p401r_gcc.c 

system_msp432p401r.o : system_msp432p401r.c
	$(CC) $(INCLUDES) -c system_msp432p401r.c 

else
# Object files for HOST will be compiled preceeding this comment
main.o : main.c
	gcc $(INCLUDES) -c -v main.c

memory.o : memory.c
	gcc $(INCLUDES) -c memory.c
endif


# This PHONY of compile-all was create to prevent any errors that may occur if there is a file \
name compile-all
.PHONY : compile-all

ifeq ($(PLATFORM),MSP432)
# This will compile all source files into object files for MSP432
compile-all : $(SOURCES)
	$(CC) $(INCLUDES) -c -mcpu=$(CPU) $(SOURCES)

else
# This will compile all source files into object file for HOST
compile-all : $(SOURCES)
	gcc $(INCLUDES) -c main.c memory.c
endif

ifeq ($(PLATFORM), MSP432)
# Preprocessor files will be generated for MSP432 preceeding this comment
main.i : main.c 
	$(CC) $(INCLUDES) -E main.c -o main.i

memory.i : memory.c 
	$(CC) $(INCLUDES) -E memory.c -o memory.i

interrupts_msp432p401r_gcc.i : interrupts_msp432p401r_gcc.i 
	$(CC) $(INCLUDES) -E interrupts_msp432p401r_gcc.c -o interrupts_msp432p401r_gcc.i

startup_msp432p401r_gcc.i : startup_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -E startup_msp432p401r_gcc.c -o startup_msp432p401r_gcc.i

system_msp432p401r.i : system_msp432p401r.c 
	$(CC) $(INCLUDES) -E system_msp432p401r.c -o system_msp432p401r.i

else
# Preprocessor files will be generated for HOST preceeding this comment
main.i : main.c 
	gcc $(INCLUDES) -E main.c -o main.i

memory.i : memory.c 
	gcc $(INCLUDES) -E memory.c -o memory.i

interrupts_msp432p401r_gcc.i : interrupts_msp432p401r_gcc.i 
	gcc $(INCLUDES) -E interrupts_msp432p401r_gcc.c -o interrupts_msp432p401r_gcc.i

startup_msp432p401r_gcc.i : startup_msp432p401r_gcc.c 
	gcc $(INCLUDES) -E startup_msp432p401r_gcc.c -o startup_msp432p401r_gcc.i

system_msp432p401r.i : system_msp432p401r.c 
	gcc $(INCLUDES) -E system_msp432p401r.c -o system_msp432p401r.i
endif

ifeq ($(PLATFORM),MSP432)
# Assembly fileS will be generated for MSP432 preceeding this comment
main.asm : main.c 
	$(CC) $(INCLUDES) -S main.c -o main.asm

memory.asm : memory.c 
	$(CC) $(INCLUDES) -S memory.c -o memory.asm 

interrupts_msp432p401r_gcc.asm : interrupts_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -S interrupts_msp432p401r_gcc.c -o interrupts_msp432p401r_gcc.asm 

startup_msp432p401r_gcc.asm : startup_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -S startup_msp432p401r_gcc.c -o startup_msp432p401r_gcc.asm 

system_msp432p401r.asm : system_msp432p401r.c 
	$(CC) $(INCLUDES) -S system_msp432p401r.c -o system_msp432p401r.asm 

# This will produce a Assembly for MSP432 c1m2.out executable
$(BASENAME).asm : $(TARGET)
	arm-none-eabi-objdump -D $(TARGET) > $(BASENAME).asm

else 
# Assembly files will be generated for HOST preceeding this comment
main.asm : main.c 
	gcc $(INCLUDES) -S main.c -o main.asm

memory.asm : memory.c 
	gcc $(INCLUDES) -S memory.c -o memory.asm 

interrupts_msp432p401r_gcc.asm : interrupts_msp432p401r_gcc.c 
	gcc $(INCLUDES) -S interrupts_msp432p401r_gcc.c -o interrupts_msp432p401r_gcc.asm 

startup_msp432p401r_gcc.asm : startup_msp432p401r_gcc.c 
	gcc $(INCLUDES) -S startup_msp432p401r_gcc.c -o startup_msp432p401r_gcc.asm 

system_msp432p401r.asm : system_msp432p401r.c 
	gcc $(INCLUDES) -S system_msp432p401r.c -o system_msp432p401r.asm

# This will produce a Assembly for HOST c1m2.out executable
$(BASENAME).asm : $(TARGET)
	objdump -D $(TARGET) > $(BASENAME).asm 
endif


# Dependency files will be generated preceeding this comment
main.d : main.c 
	$(CC) $(INCLUDES) -M main.c -MF main.d 

memory.d : memory.c 
	$(CC) $(INCLUDES) -M memory.c -MF memory.d 

interrupts_msp432p401r_gcc.d : interrupts_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -M interrupts_msp432p401r_gcc.c -MF interrupts_msp432p401r_gcc.d

startup_msp432p401r_gcc.d : startup_msp432p401r_gcc.c 
	$(CC) $(INCLUDES) -M startup_msp432p401r_gcc.c -MF startup_msp432p401r_gcc.d 

system_msp432p401r.d : system_msp432p401r.c 
	$(CC) $(INCLUDES) -M system_msp432p401r.c -MF system_msp432p401r.d


# This PHONY of clean was created to prevent any errors that may occur if there is a file \
named clean.
.PHONY : clean
# All .out, .o, .s, .asm and .i will be deleted from the directory
clean :
	-rm -r *.out *.o *.map *.i *.asm *.d