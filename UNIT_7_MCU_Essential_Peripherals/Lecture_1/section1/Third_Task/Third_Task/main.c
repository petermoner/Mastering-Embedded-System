/*
 * Third_Task.c
 *
 * Created: 6/11/2023 4:03:30 AM
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
	 MDIO_voidSetPortDirection(PORTD,OUTPUT);
	 
	 while (1)
	 {
		 for (i=7;i>3;i--)
		 {
			 MDIO_voidSetPinValue(PORTD,i,HIGH);
			 _delay_ms(1000);
			 MDIO_voidSetPinValue(PORTD,i,LOW);			 
		 }
		 
	 }
 }

