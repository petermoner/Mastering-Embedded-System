/*
 * Fourth_Task.c
 *
 * Created: 6/11/2023 4:18:25 AM
 * Author : Peter Moner
 */

 #include "LBIT_MATH.h"
 #include "LSTD_TYPES.h"
 #include "MDIO_interface.h"
 #define F_CPU 8000000UL
 #include <util/delay.h>

 int main(void)
 {
	 u8_t i=0,j=0,counter=0;
	 MDIO_voidSetPortDirection(PORTC,OUTPUT);
	 
	 while (1)
	 {
		for (counter=0;counter<100;counter++)
		{
					 for (i=0;i<10;i++)
					 {
						 for (j=0;j<10;j++)
						 {
							 MDIO_voidSetPinValue(PORTC,PIN2,HIGH);
							 MDIO_voidSetPinValue(PORTC,PIN3,LOW);
							 _delay_ms(200);

							 MDIO_voidSetPinValue(PORTC,PIN4,GET_BIT(i,0));
							 MDIO_voidSetPinValue(PORTC,PIN5,GET_BIT(i,1));
							 MDIO_voidSetPinValue(PORTC,PIN6,GET_BIT(i,2));
							 MDIO_voidSetPinValue(PORTC,PIN7,GET_BIT(i,3));

							 MDIO_voidSetPinValue(PORTC,PIN2,LOW);
							 MDIO_voidSetPinValue(PORTC,PIN3,HIGH);
							 _delay_ms(200);
							 
							 MDIO_voidSetPinValue(PORTC,PIN4,GET_BIT(j,0));
							 MDIO_voidSetPinValue(PORTC,PIN5,GET_BIT(j,1));
							 MDIO_voidSetPinValue(PORTC,PIN6,GET_BIT(j,2));
							 MDIO_voidSetPinValue(PORTC,PIN7,GET_BIT(j,3));
						 }
					 }
		}
	 }
 }



