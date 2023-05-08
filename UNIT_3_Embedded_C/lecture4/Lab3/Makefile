#prepared by Peter Moner
 
CC=arm-none-eabi-
CFLAGS= -g -gdwarf-2 -mcpu=cortex-m4 -mthumb
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name = Unit3_lab4_cortex_m4


$(Project_name).bin: $(Project_name).elf
		$(CC)objcopy.exe -O binary $< $@
		@echo ">>>>>>Build is Done<<<<<<"

%.o: %.s
		$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
		$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@  

$(Project_name).elf: $(OBJ) $(ASOBJ)
		$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_File.map
		cp $(Project_name).elf  $(Project_name).axf 
clean:
	rm *.elf *.bin	
	
clean_all:
	rm *.o *.elf *.bin
	@echo "Everything is clean"