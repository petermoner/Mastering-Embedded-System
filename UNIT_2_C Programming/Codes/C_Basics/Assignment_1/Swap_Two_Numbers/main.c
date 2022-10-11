/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{	 float x=0 ,y=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	printf("Enter value of a: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&x);

	printf("Enter value of b: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&y);

	x=x+y;
	y=x-y;
	x=x-y;

	printf("after swapping,value of a: %.2f\n",x);
	printf("after swapping,value of b: %.2f\n",y);
	printf("\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#");
	return 0;
}
