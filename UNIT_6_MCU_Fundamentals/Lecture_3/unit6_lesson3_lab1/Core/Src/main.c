/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  */
#include "Platform_Types.h"
#include "LBIT_MATH.h"

#define RCC_BASE 		(0x40021000)
#define PORTA_BASE  	(0x40010800)
#define APB2ENR 		*((vuint32*)(RCC_BASE + 0x18))
#define GPIOA_CRH 		*(vuint32 *)(PORTA_BASE + 0x04)
#define GPIOA_ODR 		*(vuint32 *)(PORTA_BASE + 0x0C)

//Bit orders
#define IOPAEN 2
#define GPIOA_p13 13

int main(void)
{
	int i;
	SET_BIT(APB2ENR,IOPAEN);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

    /* Loop forever */
	while(1)
	{
		TOGGLE_BIT(GPIOA_ODR,GPIOA_p13);
		for(i=0;i<5000;i++);
	}

	return 0;
}
