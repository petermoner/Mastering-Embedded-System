/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */


#include "Platform_Types.h"
#include "LBIT_MATH.h"


#define RCC_BASE 		(0x40021000)
#define RCC_CFGR 		*((vuint32*)(RCC_BASE + 0x04))
#define RCC_CR 			*((vuint32*)(RCC_BASE + 0x0))



void clock_init(void)
{
	//Store 10 in bits 1 : 0 = 10 for Selection PLL
	RCC_CFGR |= (0b10 << 0);

	//Store 0110 in bits 21 : 18 = 0110 for PLL MUX * 8 --> 4 * 8 = 32 MHZ
	RCC_CFGR |= (0b0110 << 18);

	//Store 101 in bits 13 : 11 = 101 for prescaler 4 --> APB2 = 32/4 = 8
	RCC_CFGR |= (0b101 << 11);

	//Store 100 in bits 10 : 8 = 100 for prescaler 2 --> APB1 = 32/2 = 16
	RCC_CFGR |= (0b100 << 8);

	//Store 1 in bit 24  = 1 to set PLLON
	RCC_CR |= (0b1 << 24);

}



int main(void)
{
	clock_init();


	return 0;
}
