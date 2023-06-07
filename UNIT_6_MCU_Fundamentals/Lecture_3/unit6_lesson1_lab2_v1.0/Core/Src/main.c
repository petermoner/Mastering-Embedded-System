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
#define RCC_CFGR 		*((vuint32*)(RCC_BASE + 0x04))



void clock_init(void)
{
	//Store 101 in bits 13 : 11 = 101 for prescaler 4 --> APB2 = AHB/4
	RCC_CFGR |= (0b101 << 11);

	//Store 100 in bits 10 : 8 = 100 for prescaler 2 --> APB1 = AHB/2
	RCC_CFGR |= (0b100 << 8);
}



int main(void)
{
	clock_init();


	return 0;
}
