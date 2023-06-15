/*
 * HKEYPAD_program.c
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 

#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "HKEYPAD_configration.h"
#include "HKEYPAD_interface.h"


void HKEYPAD_voidInit(void)
{
	MDIO_voidSetPinDirection(KEYPAD_PORT,KROW_1,OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KROW_2,OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KROW_3,OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KROW_4,OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KCOL_1,INPUT_PULLUP);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KCOL_2,INPUT_PULLUP);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KCOL_3,INPUT_PULLUP);
	MDIO_voidSetPinDirection(KEYPAD_PORT,KCOL_4,INPUT_PULLUP);
	
}


u8_t HKEYPAD_voidCheckPress(void)
{
	u8_t L_u8Row =0;
	u8_t L_u8COLUMN =0;
	u8_t L_u8ReadingValue =0;
	u8_t L_u8ReturnValue =NOT_PRESSED;
	u8_t L_u8Flag =0;

	u8_t A_u8Array[4][4]={  {'1','2','3','-'},
							{'4','5','6','*'},
							{'7','8','9','/'},
						    {'%','0','=','+'}  };
								
	for(L_u8Row=0 ; L_u8Row<KEYPAD_ROWS_NUMBER ;  L_u8Row++)
	{
		MDIO_voidSetLowNibbleValue(KEYPAD_PORT,0x0F);
		MDIO_voidSetPinValue(KEYPAD_PORT,L_u8Row,LOW);
		
		for( L_u8COLUMN =0 ;  L_u8COLUMN < KEYPAD_COLUMNS_NUMBER ;  L_u8COLUMN++)
		{
			L_u8ReadingValue=MDIO_voidGetPinValue(KEYPAD_PORT,(L_u8COLUMN+KEYPAD_ROWS_NUMBER));
			
			if(L_u8ReadingValue==0)
			{
				while(L_u8ReadingValue==0)
				{
					L_u8ReadingValue=MDIO_voidGetPinValue(KEYPAD_PORT,(L_u8COLUMN+KEYPAD_ROWS_NUMBER));
				}
				L_u8ReturnValue=A_u8Array[L_u8Row][L_u8COLUMN];
				L_u8Flag++;
				break;
			}
		}
		
		if(L_u8Flag != 0)
		{
			L_u8Flag=0;
		}
		
		if(L_u8ReadingValue==0)
		{
			break;
		}
	}
	
	return L_u8ReturnValue;
}