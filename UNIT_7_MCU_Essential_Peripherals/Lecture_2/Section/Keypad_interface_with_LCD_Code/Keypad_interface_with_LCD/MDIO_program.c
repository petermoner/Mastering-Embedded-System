/*
 *  Name   : MDIO_private.h
 *  Version: v1.0
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"



/************************************************************************************************/
/*                                        Functions' implementation                             */
/************************************************************************************************/


/*This function is responsible for setting a specific status [OUTPUT - INPUT_FLOAT - INPUT_PULLUP] to a specific port pin*/
void MDIO_voidSetPinDirection(u8_t A_u8PortName , u8_t A_u8PinNumber , u8_t A_u8PinStatus)
{
	switch(A_u8PortName)
	{
		//START of set pin direction of a specific pin in PORTA
		case PORTA:
			
			switch(A_u8PinStatus)
			{
				case OUTPUT:
					SET_BIT(MDIO_DDRA_REG,A_u8PinNumber);
					break;
				case INPUT_FLOAT:
					CLEAR_BIT(MDIO_DDRA_REG,A_u8PinNumber);
					break;
				case INPUT_PULLUP:
					CLEAR_BIT(MDIO_DDRA_REG,A_u8PinNumber);
					SET_BIT(MDIO_PORTA_REG,A_u8PinNumber);					
					break;
				
				default:
					break;
				}//END of set pin direction of a specific pin in PORTA
			break ;


		//START of set pin direction of a specific pin in PORTB
		case PORTB:
		
		switch(A_u8PinStatus)
		{
			case OUTPUT:
				SET_BIT(MDIO_DDRB_REG,A_u8PinNumber);
				break;
			case INPUT_FLOAT:
				CLEAR_BIT(MDIO_DDRB_REG,A_u8PinNumber);
				break;
			case INPUT_PULLUP:
				CLEAR_BIT(MDIO_DDRB_REG,A_u8PinNumber);
				SET_BIT(MDIO_PORTB_REG,A_u8PinNumber);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTB
		break ;
		
		

		//START of set pin direction of a specific pin in PORTC
		case PORTC:
		
		switch(A_u8PinStatus)
		{
			case OUTPUT:
				SET_BIT(MDIO_DDRC_REG,A_u8PinNumber);
				break;
			case INPUT_FLOAT:
				CLEAR_BIT(MDIO_DDRC_REG,A_u8PinNumber);
				break;
			case INPUT_PULLUP:
				CLEAR_BIT(MDIO_DDRC_REG,A_u8PinNumber);
				SET_BIT(MDIO_PORTC_REG,A_u8PinNumber);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTC
		break ;
		
		
		//START of set pin direction of a specific pin in PORTD
		case PORTD:
		
		switch(A_u8PinStatus)
		{
			case OUTPUT:
				SET_BIT(MDIO_DDRD_REG,A_u8PinNumber);
				break;
			case INPUT_FLOAT:
				CLEAR_BIT(MDIO_DDRD_REG,A_u8PinNumber);
				break;
			case INPUT_PULLUP:
				CLEAR_BIT(MDIO_DDRD_REG,A_u8PinNumber);
				SET_BIT(MDIO_PORTD_REG,A_u8PinNumber);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTD
		break ;
			
		default:   
				break ;
		
	}
}


/*This function is responsible for setting a specific value [HIGH - LOW] to a specific port pin*/
void MDIO_voidSetPinValue(u8_t A_u8PortName , u8_t A_u8PinNumber , u8_t A_u8PinValue)
{
	switch(A_u8PortName)
	{
		case PORTA:
				switch(A_u8PinValue)
				{
					case HIGH:
						SET_BIT(MDIO_PORTA_REG,A_u8PinNumber);
						break;
						
					case LOW:
						CLEAR_BIT(MDIO_PORTA_REG,A_u8PinNumber);
						break;
					
					default:
						break;
				}
				break;
		
		case PORTB:
				switch(A_u8PinValue)
				{
					case HIGH:
						SET_BIT(MDIO_PORTB_REG,A_u8PinNumber);
						break;
					
					case LOW:
						CLEAR_BIT(MDIO_PORTB_REG,A_u8PinNumber);
						break;
					
					default:
						break;
				}
				break;

		case PORTC:
				switch(A_u8PinValue)
				{
					case HIGH:
						SET_BIT(MDIO_PORTC_REG,A_u8PinNumber);
						break;
					
					case LOW:
						CLEAR_BIT(MDIO_PORTC_REG,A_u8PinNumber);
						break;
					
					default:
						break;
				}
				break;

		case PORTD:
				switch(A_u8PinValue)
				{
					case HIGH:
						SET_BIT(MDIO_PORTD_REG,A_u8PinNumber);
						break;
					
					case LOW:
						CLEAR_BIT(MDIO_PORTD_REG,A_u8PinNumber);
						break;
					
					default:
						break;
				}
				break;
		
		default:
				break;
	}
}


/*This function is responsible for toggling a specific port pin value [HIGH -> LOW, LOW -> HIGH]*/
void MDIO_voidTogglePinValue(u8_t A_u8PortName , u8_t A_u8PinNumber)
{
	switch(A_u8PortName)
	{
		case PORTA:
			TOGGLE_BIT(MDIO_PORTA_REG,A_u8PinNumber);
			break;
			
		case PORTB:
			TOGGLE_BIT(MDIO_PORTB_REG,A_u8PinNumber);
			break;

		case PORTC:
			TOGGLE_BIT(MDIO_PORTC_REG,A_u8PinNumber);
			break;

		case PORTD:
			TOGGLE_BIT(MDIO_PORTD_REG,A_u8PinNumber);
			break;
		
		default:
			break;
	}
	
	
}

/*This function is responsible for getting a specific port pin value [HIGH - LOW]*/
u8_t MDIO_voidGetPinValue(u8_t A_u8PortName , u8_t A_u8PinNumber)
{	u8_t Local_u8ReturnValue = 0;
	
	switch(A_u8PortName)
	{
		case PORTA:
			Local_u8ReturnValue = GET_BIT(MDIO_PINA_REG,A_u8PinNumber);
			break;
		case PORTB:
			Local_u8ReturnValue = GET_BIT(MDIO_PINB_REG,A_u8PinNumber);
			break;
		
		case PORTC:
			Local_u8ReturnValue = GET_BIT(MDIO_PINC_REG,A_u8PinNumber);
			break;
		
		case PORTD:
			Local_u8ReturnValue = GET_BIT(MDIO_PIND_REG,A_u8PinNumber);
			break;		
		default:
			break;
	}
	return Local_u8ReturnValue ;
}


/*This function is responsible for setting a specific status [OUTPUT - INPUT_FLOAT - INPUT_PULLUP] to a specific port */
void MDIO_voidSetPortDirection(u8_t A_u8PortName , u8_t A_u8PortStatus)
{
	switch(A_u8PortName)
	{
		//START of set pin direction of a specific pin in PORTA
		case PORTA:
		
		switch(A_u8PortStatus)
		{
			case OUTPUT:
				SET_BYTE(MDIO_DDRA_REG);
				break;
			case INPUT_FLOAT:
				CLEAR_BYTE(MDIO_DDRA_REG);
				break;
			case INPUT_PULLUP:
				CLEAR_BYTE(MDIO_DDRA_REG);
				SET_BYTE(MDIO_PORTA_REG);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTA
		break ;


		//START of set pin direction of a specific pin in PORTB
		case PORTB:
		
		switch(A_u8PortStatus)
		{
			case OUTPUT:
				SET_BYTE(MDIO_DDRB_REG);
				break;
			case INPUT_FLOAT:
				CLEAR_BYTE(MDIO_DDRB_REG);
				break;
			case INPUT_PULLUP:
				CLEAR_BYTE(MDIO_DDRB_REG);
				SET_BYTE(MDIO_PORTB_REG);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTB
		break ;
		
		

		//START of set pin direction of a specific pin in PORTC
		case PORTC:
		
		switch(A_u8PortStatus)
		{
			case OUTPUT:
				SET_BYTE(MDIO_DDRC_REG);
				break;
			case INPUT_FLOAT:
				CLEAR_BYTE(MDIO_DDRC_REG);
				break;
			case INPUT_PULLUP:
				CLEAR_BYTE(MDIO_DDRC_REG);
				SET_BYTE(MDIO_PORTC_REG);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTC
		break ;
		
		
		//START of set pin direction of a specific pin in PORTD
		case PORTD:
		
		switch(A_u8PortStatus)
		{
			case OUTPUT:
				SET_BYTE(MDIO_DDRD_REG);
				break;
			case INPUT_FLOAT:
				CLEAR_BYTE(MDIO_DDRD_REG);
				break;
			case INPUT_PULLUP:
				CLEAR_BYTE(MDIO_DDRD_REG);
				SET_BYTE(MDIO_PORTD_REG);
				break;
			
			default:
				break;
		}//END of set pin direction of a specific pin in PORTD
			break ;
		
		default:
			break ;
	}
}

/*This function is responsible for setting a specific value [HIGH - LOW] to a specific port*/
void MDIO_voidSetPortValue(u8_t A_u8PortName , u8_t A_u8PortValue)
{
	switch(A_u8PortName)
	{
		case PORTA:
		switch(A_u8PortValue)
		{
			case HIGH:
				SET_BYTE(MDIO_PORTA_REG);
				break;
			
			case LOW:
				CLEAR_BYTE(MDIO_PORTA_REG);
				break;
			
			default:
				MDIO_PORTA_REG = A_u8PortValue;
				break;
		}
		break;
		
		case PORTB:
		switch(A_u8PortValue)
		{
			case HIGH:
				SET_BYTE(MDIO_PORTB_REG);
				break;
			
			case LOW:
				CLEAR_BYTE(MDIO_PORTB_REG);
				break;
			
			default:
				MDIO_PORTB_REG = A_u8PortValue;
				break;
		}
		break;

		case PORTC:
		switch(A_u8PortValue)
		{
			case HIGH:
				SET_BYTE(MDIO_PORTC_REG);
				break;
			
			case LOW:
				CLEAR_BYTE(MDIO_PORTC_REG);
				break;
			
			default:
				MDIO_PORTC_REG = A_u8PortValue;
				break;
		}
		break;

		case PORTD:
		switch(A_u8PortValue)
		{
			case HIGH:
				SET_BYTE(MDIO_PORTD_REG);
				break;
			
			case LOW:
				CLEAR_BYTE(MDIO_PORTD_REG);
				break;
			
			default:
				MDIO_PORTD_REG = A_u8PortValue;
				break;
		}
		break;
		
		default:
			break;
	}
}


/*This function is responsible for toggling a specific port value [HIGH -> LOW, LOW -> HIGH]*/
void MDIO_voidTogglePortValue(u8_t A_u8PortName)
{
	switch(A_u8PortName)
	{
		case PORTA:
			TOGGLE_BYTE(MDIO_PORTA_REG);
			break;
		
		case PORTB:
			TOGGLE_BYTE(MDIO_PORTB_REG);
			break;

		case PORTC:
			TOGGLE_BYTE(MDIO_PORTC_REG);
			break;

		case PORTD:
			TOGGLE_BYTE(MDIO_PORTD_REG);
			break;
		
		default:
		break;
	}
	
}


/*This function is responsible for getting a specific port value [HIGH - LOW]*/
u8_t MDIO_voidGetPortValue(u8_t A_u8PortName)
{	u8_t Local_u8ReturnValue = 0;
	switch(A_u8PortName)
	{
		case PORTA:
			Local_u8ReturnValue=MDIO_PINA_REG;
			break;
		
		case PORTB:
			Local_u8ReturnValue=MDIO_PINB_REG;
			break;
		
		case PORTC:
			Local_u8ReturnValue=MDIO_PINC_REG;
			break;
		
		case PORTD:
			Local_u8ReturnValue=MDIO_PIND_REG;
			break;
		
		default:
		break;
	}
	return Local_u8ReturnValue;
} 


void MDIO_voidSetLowNibbleValue(u8_t A_u8PortName,u8_t A_u8Value)
{
	A_u8Value &= 0x0F;
	
	switch(A_u8PortName)
	{
		case PORTA:
			MDIO_PORTA_REG &= 0xF0;
			MDIO_PORTA_REG |= A_u8Value ;
		    break;
		
		case PORTB:
			MDIO_PORTB_REG &= 0xF0;
			MDIO_PORTB_REG |= A_u8Value ;
			break;
		
		case PORTC:
			MDIO_PORTC_REG &= 0xF0;
			MDIO_PORTC_REG |= A_u8Value ;
			break;
		
		case PORTD:
			MDIO_PORTD_REG &= 0xF0;
			MDIO_PORTD_REG |= A_u8Value ;
			break;
		
		default:
		break;
		
	}
}


void MDIO_voidSetHighNibbleValue(u8_t A_u8PortName,u8_t A_u8Value)
{
		A_u8Value <<= 4;
		
		switch(A_u8PortName)
		{
			case PORTA:
				MDIO_PORTA_REG &= 0x0F;
				MDIO_PORTA_REG |= A_u8Value ;
				break;
			
			case PORTB:
				MDIO_PORTB_REG &= 0x0F;
				MDIO_PORTB_REG |= A_u8Value ;
				break;
			
			case PORTC:
				MDIO_PORTC_REG &= 0x0F;
				MDIO_PORTC_REG |= A_u8Value ;
				break;
			
			case PORTD:
				MDIO_PORTD_REG &= 0x0F;
				MDIO_PORTD_REG |= A_u8Value ;
				break;
			
			default:
				break;
			
		}
}