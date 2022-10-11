/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */


#include <stdio.h>
#include <stdlib.h>

int main (void)
{	signed int x=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	again :
	printf("Enter an Number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%i",&x);
	if(x>0)
	{
		printf("%i is Positive",x);
	}
	else if(x<0)
	{
		printf("%i is Negative",x);
	}
	else
	{
		printf("You entered Zero");
	}
	printf("\n\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n");
	goto again;
	return 0;
}

