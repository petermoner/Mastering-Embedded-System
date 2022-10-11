/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{	unsigned int i=0 ,x=0,sum=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	printf("Enter Two Integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u %u",&i,&x);
	sum=i+x;
	printf("Sum : %d\n",sum);
	printf("\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#");
	return 0;
}
