/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */


#include <stdio.h>
#include <stdlib.h>

int main (void)
{	 float x=0 ,y=0,z=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	printf("Enter Three Numbers : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f &f",&x,&y,&z);
	if(x>y)
	{
		if(x>z)
		{
			printf("Largest Number is: %.3f ",x);
		}
		else
		{
			printf("Largest Number is: %.3f ",z);
		}
	}
	else
	{
		if(y>z)
		{
			printf("Largest Number is: %.3f ",y);
		}
		else
		{
			printf("Largest Number is: %.3f ",z);
		}
	}
	printf("\n\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#");
	return 0;
}

