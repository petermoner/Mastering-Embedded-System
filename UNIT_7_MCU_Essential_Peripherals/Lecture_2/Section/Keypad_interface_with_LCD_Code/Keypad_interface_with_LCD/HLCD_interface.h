/*
 * HLCD_interface.h
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 


#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

#define FIRST_ROW	(1)
#define SECOND_ROW	(2)


#define COL_1		(0)
#define COL_2		(1)
#define COL_3		(2)
#define COL_4		(3)
#define COL_5		(4)
#define COL_6		(5)
#define COL_7		(6)
#define COL_8		(7)
#define COL_9		(8)
#define COL_10		(9)
#define COL_11		(10)
#define COL_12		(11)
#define COL_13		(12)
#define COL_14		(13)
#define COL_15		(14)
#define COL_16		(15)


#define RS_PIN (PIN0)
#define RW_PIN (PIN1)
#define	E_PIN  (PIN2)

#define D0     (PIN0)
#define D1     (PIN1)
#define D2     (PIN2)
#define D3     (PIN3)
#define D4     (PIN4)
#define D5     (PIN5)
#define D6     (PIN6)
#define D7     (PIN7)


#define CLEAR_SCREEN 0X01
#define RETURN_HOME  0X02
#define EIGHT_BITS   0X38
#define FOUR_BITS    0X28


void HLCD_voidInit(void);
void HLCD_voidSendCmd(u8_t A_u8Cmd);
void HLCD_voidDisplayCharacter(u8_t A_u8Char);
void HLCD_voidDisplayString(u8_t* P_u8String);
void HLCD_voidEnable(void);
void HLCD_voidClearScreen(void);
void HLCD_voidMoveCursor(u8_t A_u8Row,u8_t A_u8Column);
void HLCD_voidReturnHome(void);


#endif /* HLCD_INTERFACE_H_ */