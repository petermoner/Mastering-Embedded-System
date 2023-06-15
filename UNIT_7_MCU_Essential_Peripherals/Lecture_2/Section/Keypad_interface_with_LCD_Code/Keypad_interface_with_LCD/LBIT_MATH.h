/*
 * LBIT_MATH.h
 *
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 


#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

/************************************************************************************************/
/*                                    Bit math operations                                       */
/************************************************************************************************/

/*Setting a specific register bit to 1*/
#define SET_BIT(REG, BIT)       REG |= (1 << BIT)

/*Setting a specific register bit to 0*/
#define CLEAR_BIT(REG, BIT)     REG &= ~(1 << BIT)

/*Toggling a specific register bit*/
#define TOGGLE_BIT(REG, BIT)    REG ^= (1 << BIT)

/*Getting a specific register bit value*/
#define GET_BIT(REG, BIT)       ((REG >> BIT) & 1)

/*Setting a specific register byte to 0xFF */
#define SET_BYTE(REG)       REG |= 0xFF 

/*Setting a specific register byte to 0x00*/
#define CLEAR_BYTE(REG)     REG &= 0x00 

/*Toggling a specific register byte*/
#define TOGGLE_BYTE(REG)    REG ^= 0xFF






#endif /* LBIT_MATH_H_ */