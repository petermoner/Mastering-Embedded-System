/**
 ******************************************
 * @file           : startup.s
 * @author         : Peter Moner
 * @processor      : ARM Cortex M3
 ******************************************/
MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128k
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text)
	}> FLASH
	
	.data :
	{
		*(.data*)
	}> SRAM AT> FLASH
	
	.rodata :
	{
		*(.rodata*)
	}> FLASH
	
	.bss :
	{

		*(.bss*)
		*(COMMON*)
	}> SRAM
}