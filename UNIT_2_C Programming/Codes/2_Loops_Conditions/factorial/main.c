/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */


#include <stdio.h>
#include <stdlib.h>

int main (void)
{	signed int x=0,i=0,factorial=1;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	again:
	printf("Enter an integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%i",&x);

	if(x>0)
		{
			for (i=1 ; i<=x ; i++)
			{
				factorial*=i;
			}
			printf("factorial = %i\n",factorial);
		}
		else if(x<0)
		{
			printf("Error!!! Factorial of negative number doesn't exist\n");
		}
		else
		{
			printf("Factorial is 1\n");
		}

	printf("\n\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n");
	goto again;
	return 0;
}


