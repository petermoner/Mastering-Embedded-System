/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{	 int x=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	again :
	printf("Enter an integer you want to check : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u",&x);
	if((x%2)==0)
	{
		printf("%u is even\n",x);
	}
	else
	{
		printf("%u is odd\n",x);
	}
	printf("\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n");
	goto again;
	return 0;
}
