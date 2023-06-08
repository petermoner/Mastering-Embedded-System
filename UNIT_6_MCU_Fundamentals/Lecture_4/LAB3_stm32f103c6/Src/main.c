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


//AFIO
#define AFIO_BASE 		(0x40010000)
#define AFIO_EXTICR1 	*(vuint32 *)(AFIO_BASE +  0x08)


//GPIOA
#define PORTA_BASE  	(0x40010800)
#define GPIOA_CRL 		*(vuint32 *)(PORTA_BASE + 0x00)
#define GPIOA_CRH 		*(vuint32 *)(PORTA_BASE + 0x04)
#define GPIOA_ODR 		*(vuint32 *)(PORTA_BASE + 0x0C)

//EXTI0
#define EXTI_BASE  		(0x40010400)
#define EXTI_IMR 		*((vuint32*)(EXTI_BASE + 0x00))
#define EXTI_RTSR 		*((vuint32*)(EXTI_BASE + 0x08))
#define EXTI_PR 		*((vuint32*)(EXTI_BASE + 0x14))
#define NVIC_ISER0 		*((vuint32*)(0xE000E100))

void clock_init()
{
	SET_BIT(APB2ENR,2);
	SET_BIT(APB2ENR,0);
}

void GPIOA_Input_init()
{
	SET_BIT(GPIOA_CRL,2);
}

void GPIOA_Output_init()
{
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
}

void EXTI0_init()
{
	//make EXTI0 connected With PortA_PIN0
	AFIO_EXTICR1 &= ~(1111<<0);

	//make EXTI0 activated by rising edge
	SET_BIT(EXTI_RTSR,0);

	//make EXTI0 masking line is on
	SET_BIT(EXTI_IMR,0);

	//make EXTI0 NVIC line is on
	SET_BIT(NVIC_ISER0,6);
}

int main(void)
{
	clock_init();
	GPIOA_Input_init();
	GPIOA_Output_init();
	EXTI0_init();

	/* Loop forever */
	while(1);

	return 0;
}

void EXTI0_IRQHandler(void)
{
	TOGGLE_BIT(GPIOA_ODR,13);

	//clear pending bit request to avoid infinite interrupt
	SET_BIT(EXTI_PR,0);
}

