/*
 * main.c
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 

#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HKEYPAD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{

	u8_t L_u8Return=0;
	
	HLCD_voidInit();
    HKEYPAD_voidInit();
	HLCD_voidMoveCursor(FIRST_ROW,COL_1);

    while (1) 
    {
		L_u8Return=HKEYPAD_voidCheckPress();
		
		if(L_u8Return != 0xFF)
		{
			if(L_u8Return == '%')
			{
				HLCD_voidClearScreen();
			}
			else{
			HLCD_voidDisplayCharacter(L_u8Return);
			}
		}
		else
		{
		}
    }
}

