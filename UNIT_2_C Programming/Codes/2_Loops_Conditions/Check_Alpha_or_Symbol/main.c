/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */


#include <stdio.h>
#include <stdlib.h>

int main (void)
{	unsigned int x=0,i=0,sum=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	printf("Enter an integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u",&x);
	for (i=1 ; i<=x ; i++)
	{
		sum+=i;
	}
	printf("sum = %u",sum);
	printf("\n\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n");
	return 0;
}

