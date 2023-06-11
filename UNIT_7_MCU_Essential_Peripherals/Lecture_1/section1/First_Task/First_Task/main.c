/*
 * First_Task.c
 *
 * Created: 6/11/2023 3:11:43 AM
 * Author : Peter Moner
 */ 

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	u32_t i=0;
	MDIO_voidSetPortDirection(PORTA,OUTPUT);

    while (1) 
    {
		
		for (i=0;i<8;i++)
		{
			MDIO_voidSetPinValue(PORTA,i,HIGH);
			_delay_ms(100);
		}
		
		for (i=8;i>0;i--)
		{
			MDIO_voidSetPinValue(PORTA,i,LOW);
			_delay_ms(100);
		}
		
    }
}

