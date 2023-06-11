/*
 *  Name   : MDIO_private.h
 *  Version: v1.0
 *  Created: 6/29/2022 11:48:40 PM
 *  Author : peter moner
 */ 


#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_

/*--------------------------------------------------- MDIO REGISTERS ADDRESSES ---------------------------------------------------*/
#define MDIO_PORTA_REG *((volatile unsigned char *)(0x003B))
#define MDIO_DDRA_REG  *((volatile unsigned char *)(0x003A))
#define MDIO_PINA_REG  *((volatile unsigned char *)(0x0039))

#define MDIO_PORTB_REG *((volatile unsigned char *)(0x0038))
#define MDIO_DDRB_REG  *((volatile unsigned char *)(0x0037))
#define MDIO_PINB_REG  *((volatile unsigned char *)(0x0036))

#define MDIO_PORTC_REG *((volatile unsigned char *)(0x0035))
#define MDIO_DDRC_REG  *((volatile unsigned char *)(0x0034))
#define MDIO_PINC_REG  *((volatile unsigned char *)(0x0033))

#define MDIO_PORTD_REG *((volatile unsigned char *)(0x0032))
#define MDIO_DDRD_REG  *((volatile unsigned char *)(0x0031))
#define MDIO_PIND_REG  *((volatile unsigned char *)(0x0030))
/*-------------------------------------------------------------------------------------------------------------------------------*/

#endif /* MDIO_PRIVATE_H_ */