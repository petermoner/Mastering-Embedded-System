/*
 * LAB3_atmega32.c
 *
 * Created: 6/8/2023 9:27:13 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "Platform_Types.h"
#include "LBIT_MATH.h"

/*#define SREG	*((vuint32*)(0x005F))
#define MCUCR	*((vuint32*)(0x0055))
#define GICR	*((vuint32*)(0x005B))
#define GIFR	*((vuint32*)(0x005A))

#define PORTD	*((vuint32*)(0x0032))
#define DDRD	*((vuint32*)(0x0031))
#define PIND	*((vuint32*)(0x0030))*/

void INT0_init()
{
	//Enable INT0
	SET_BIT(GICR,6);

	//Activate INT0 At any edge difference occurs
	SET_BIT(MCUCR,0);
	
	//Enable Global interrupt bit  
	SET_BIT(SREG,7);
}

void PORTD_init(void)
{
	CLEAR_BIT(DDRD,2);
	SET_BIT(PORTD,2);
	SET_BIT(DDRD,7);
}

int main(void)
{
	INT0_init();
	PORTD_init();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	SET_BIT(PORTD,7);
	_delay_ms(1000);
	CLEAR_BIT(PORTD,7);	
	SET_BIT(GIFR,6);
}