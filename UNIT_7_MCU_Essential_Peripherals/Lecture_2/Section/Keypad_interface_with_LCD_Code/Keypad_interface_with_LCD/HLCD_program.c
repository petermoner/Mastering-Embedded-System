/*
 * HLCD_program.c
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_configration.h"

#define F_CPU 8000000
#include<util/delay.h>

void HLCD_voidInit(void)
{
	_delay_ms(200);

	#if defined EIGHT_BIT_MODE
	
	MDIO_voidSetPortDirection(Display_Data_Port,OUTPUT);
	MDIO_voidSetPinDirection(Control_Port,RS_PIN,OUTPUT);
	MDIO_voidSetPinDirection(Control_Port,RW_PIN,OUTPUT);
	MDIO_voidSetPinDirection(Control_Port,E_PIN,OUTPUT);
	MDIO_voidSetPinValue(Control_Port,RW_PIN,LOW);
	//FUNCTION SET
	HLCD_voidSendCmd(EIGHT_BITS);
	_delay_ms(1);
	HLCD_voidSendCmd(DISPLAY_CURSOR_CONTROL);
	_delay_ms(1);
	HLCD_voidSendCmd(CLEAR_SCREEN);
	_delay_ms(10);
	HLCD_voidSendCmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE	
		MDIO_voidSetPinDirection(Display_Data_Port,D4,OUTPUT);
		MDIO_voidSetPinDirection(Display_Data_Port,D5,OUTPUT);
		MDIO_voidSetPinDirection(Display_Data_Port,D6,OUTPUT);
		MDIO_voidSetPinDirection(Display_Data_Port,D7,OUTPUT);
		MDIO_voidSetPinDirection(Control_Port,RS_PIN,OUTPUT);
		MDIO_voidSetPinDirection(Control_Port,RW_PIN,OUTPUT);
		MDIO_voidSetPinDirection(Control_Port,E_PIN,OUTPUT);
		MDIO_voidSetPinValue(Control_Port,RW_PIN,LOW);
		//FUNCTION SET
		HLCD_voidReturnHome();
		HLCD_voidSendCmd(FOUR_BITS);
		_delay_ms(1);
		HLCD_voidSendCmd(DISPLAY_CURSOR_CONTROL);
		_delay_ms(1);
		HLCD_voidSendCmd(CLEAR_SCREEN);
		_delay_ms(10);
		HLCD_voidSendCmd(ENTRY_MODE);
		_delay_ms(1);
	#endif
	
}


void HLCD_voidSendCmd(u8_t A_u8Cmd)
{
	#if defined EIGHT_BIT_MODE

	MDIO_voidSetPortValue(Display_Data_Port,A_u8Cmd);
	MDIO_voidSetPinValue(Control_Port,RS_PIN,LOW);
	HLCD_voidEnable();
	
	#elif defined FOUR_BIT_MODE
	MDIO_voidSetHighNibbleValue(Display_Data_Port,(A_u8Cmd>>4));
	MDIO_voidSetPinValue(Control_Port,RS_PIN,LOW);
	HLCD_voidEnable();

	MDIO_voidSetHighNibbleValue(Display_Data_Port,A_u8Cmd);
	MDIO_voidSetPinValue(Control_Port,RS_PIN,LOW);
	HLCD_voidEnable();
	#endif
	_delay_ms(1);

}




void HLCD_voidDisplayCharacter(u8_t A_u8Char)
{
	#if defined EIGHT_BIT_MODE

	MDIO_voidSetPortValue(Display_Data_Port,A_u8Char);
	MDIO_voidSetPinValue(Control_Port,RS_PIN,HIGH);
	HLCD_voidEnable();

	#elif defined FOUR_BIT_MODE
	MDIO_voidSetHighNibbleValue(Display_Data_Port,(A_u8Char>>4));
	MDIO_voidSetPinValue(Control_Port,RS_PIN,HIGH);
	HLCD_voidEnable();
	MDIO_voidSetHighNibbleValue(Display_Data_Port,A_u8Char);
	MDIO_voidSetPinValue(Control_Port,RS_PIN,HIGH);
	HLCD_voidEnable();
	#endif
	_delay_ms(1);
}


void HLCD_voidDisplayString(u8_t* P_u8String)
{
	while((*P_u8String) != '\0')
	{
		HLCD_voidDisplayCharacter(*P_u8String++);
	}
}


void HLCD_voidEnable()
{
	MDIO_voidSetPinValue(Control_Port,E_PIN,HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(Control_Port,E_PIN,LOW);
	_delay_ms(2);
}


void HLCD_voidClearScreen()
{
	HLCD_voidSendCmd(CLEAR_SCREEN);
	_delay_ms(10);
}

void HLCD_voidReturnHome()
{
	HLCD_voidSendCmd(RETURN_HOME);
	_delay_ms(10);
}


void HLCD_voidMoveCursor(u8_t A_u8Row,u8_t A_u8Column)
{
	u8_t A_u8Address = 0 ;
	
	if(A_u8Row == FIRST_ROW)
	{
		A_u8Address = DDRAM_FIRST_ADDRESS + A_u8Column;
	}
	else if (A_u8Row == SECOND_ROW)
	{
		A_u8Address = DDRAM_SECOND_ADDRESS + A_u8Column;
	}
	else
	{
		
	}
	
	HLCD_voidSendCmd(A_u8Address);
	_delay_ms(1);

}