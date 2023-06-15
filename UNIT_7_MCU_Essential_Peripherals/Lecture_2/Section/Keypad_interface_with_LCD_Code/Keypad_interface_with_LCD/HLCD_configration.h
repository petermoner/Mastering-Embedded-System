/*
 * HLCD_configration.h
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 


#ifndef HLCD_CONFIGRATION_H_
#define HLCD_CONFIGRATION_H_


#define FOUR_BIT_MODE		
#define Display_Data_Port (PORTA)
#define Control_Port      (PORTB)

/************************************************************************/
/* ENTRY MODE SELECTIONS
*  1.SHIFT CURSOR TO LEFT    0X04
*  2.SHIFT DISPLAY TO RIGHT  0X05
*  3.SHIFT CURSOR TO RIGHT   0X06
*  4.SHIFT DISPLAY TO LEFT   0X07
*/
/************************************************************************/
#define ENTRY_MODE 0X06

/************************************************************************/
/* DISPLAY_CURSOR_CONTROL SELECTIONS
*  1.DISPLAY OFF , CURSOR OFF		0X08
*  2.DISPLAY ON , CURSOR OFF		0X0C
*  3.DISPLAY OFF , CURSOR ON		0X0A
*  4.DISPLAY ON , CURSOR ON			0X0E
*  5.DISPLAY ON , CURSOR BLINKING   0X0F
*/
/************************************************************************/
#define DISPLAY_CURSOR_CONTROL  0X0E







#endif /* HLCD_CONFIGRATION_H_ */