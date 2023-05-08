/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Peter Moner
 * @brief          : Main program body
 ******************************************************************************/
#include "LBIT_MATH.h"
#define SYSCTL_RCGC2_R 			(*((volatile unsigned long *)(0x400FE108)))
#define GPIO_PORTF_DIR_R 		(*((volatile unsigned long *)(0x40025400)))
#define GPIO_PORTF_DEN_R 		(*((volatile unsigned long *)(0x4002551c)))
#define GPIO_PORTF_DATA_R 		(*((volatile unsigned long *)(0x400253fc)))

int main(void)
{
	int i;
	 SYSCTL_RCGC2_R=0x00000020;
	 for(i=0;i<200;i++);
	 SET_BIT(GPIO_PORTF_DIR_R,3);
	 SET_BIT(GPIO_PORTF_DEN_R,3);
    /* Loop forever */
	while(1)
	{
		TOGGLE_BIT(GPIO_PORTF_DATA_R,3);
		for(i=0;i<200000;i++);
	}

	return 0;
}
