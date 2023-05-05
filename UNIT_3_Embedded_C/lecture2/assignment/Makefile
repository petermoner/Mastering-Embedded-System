#prepared by Peter Moner
 
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)

run: final.bin
	qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel final.elf
	
%.o: %.s
		$(CC)as.exe -g $(CFLAGS) $< -o $@

%.o: %.c
		$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@  

final.elf: $(OBJ) $(ASOBJ)
		$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_File.map

final.bin: final.elf
		$(CC)objcopy.exe -O binary $< final.bin

clean:
	rm -rf *.o *~