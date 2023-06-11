/*
 * Second_Task.c
 *
 * Created: 6/11/2023 3:43:42 AM
 * Author : Peter Moner
 */

 #include "LBIT_MATH.h"
 #include "LSTD_TYPES.h"
 #include "MDIO_interface.h"
 #define F_CPU 8000000UL
 #include <util/delay.h>

 int main(void)
 {
	 u8_t i=0,flag=0;
	MDIO_voidSetPortDirection(PORTA,OUTPUT);
	MDIO_voidSetPinDirection(PORTD,PIN0,INPUT_PULLUP);
	 while (1)
	 {
		 if (MDIO_voidGetPinValue(PORTD,PIN0)==LOW&& flag==0)
		 {
			 if (i==8)
			 {
				i=0;
				MDIO_voidSetPortValue(PORTA,LOW);
			 }
			 MDIO_voidSetPinValue(PORTA,i,HIGH);
			 i++;
			 flag=1;	  
		 }
		 
		if (MDIO_voidGetPinValue(PORTD,PIN0)==HIGH)
		{
			flag=0;
		}
	 }
 }


