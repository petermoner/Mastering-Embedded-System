/*
 * HKEYPAD_interface.h
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 


#ifndef HKEYPAD_INTERFACE_H_
#define HKEYPAD_INTERFACE_H_

#define KEYPAD_ROWS_NUMBER		(4)
#define KEYPAD_COLUMNS_NUMBER   (4)

#define KROW_1 PIN0
#define KROW_2 PIN1
#define KROW_3 PIN2
#define KROW_4 PIN3
#define KCOL_1 PIN4
#define KCOL_2 PIN5
#define KCOL_3 PIN6
#define KCOL_4 PIN7

void HKEYPAD_voidInit(void);
u8_t HKEYPAD_voidCheckPress(void);

#endif /* HKEYPAD_INTERFACE_H_ */