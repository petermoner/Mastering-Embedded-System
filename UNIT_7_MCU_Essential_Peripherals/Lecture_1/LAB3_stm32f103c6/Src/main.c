/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Peter Moner
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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Platform_Types.h"
#include "LBIT_MATH.h"

//RCC

#define RCC_BASE 		(0x40021000)
#define APB2ENR 		*((vuint32*)(RCC_BASE + 0x18))

//GPIOA
#define PORTA_BASE  	(0x40010800)
#define GPIOA_CRL 		*(vuint32 *)(PORTA_BASE + 0x00)
#define GPIOA_CRH 		*(vuint32 *)(PORTA_BASE + 0x04)
#define GPIOA_IDR 		*(vuint32 *)(PORTA_BASE + 0x08)
#define GPIOA_ODR 		*(vuint32 *)(PORTA_BASE + 0x0C)

//GPIOB
#define PORTB_BASE  	(0x40010C00)
#define GPIOB_CRL 		*(vuint32 *)(PORTB_BASE + 0x00)
#define GPIOB_CRH 		*(vuint32 *)(PORTB_BASE + 0x04)
#define GPIOB_IDR 		*(vuint32 *)(PORTB_BASE + 0x08)
#define GPIOB_ODR 		*(vuint32 *)(PORTB_BASE + 0x0C)

void clock_init()
{
	SET_BIT(APB2ENR,2);
	SET_BIT(APB2ENR,3);
}

void GPIOA_Input_init()
{
	GPIOA_CRL = 0x0;
	GPIOA_CRH = 0x0;

	//A1 >> floating input
	SET_BIT(GPIOA_CRL,6);

	//A13 >> floating input
	SET_BIT(GPIOA_CRH,22);
}

void GPIOA_Output_init()
{
	//B1 >> Push Pull Output Pin
	GPIOB_CRL |= (0b1<<4);
	GPIOB_CRL &= ~(0b111<<5);

	//B13 >> Push Pull Output Pin
	GPIOB_CRH |= (0b1<<20);
	GPIOB_CRH &= ~(0b111<<21);
}

void my_wait(int time)
{
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<255;j++);
	}
}

int main(void)
{
	clock_init();
	GPIOA_Input_init();
	GPIOA_Output_init();

	while(1)
	{
		if(GET_BIT(GPIOA_IDR,1)==0)
		{
			TOGGLE_BIT(GPIOB_ODR,1);
			while(GET_BIT(GPIOA_IDR,1)==0);
		}

		if(GET_BIT(GPIOA_IDR,13)==1)
		{
			TOGGLE_BIT(GPIOB_ODR,13);
		}
		my_wait(2);
	}
	return 0;
}


