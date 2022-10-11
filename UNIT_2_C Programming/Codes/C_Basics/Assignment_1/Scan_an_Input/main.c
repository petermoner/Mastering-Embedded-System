/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{	unsigned int i=0 ;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	printf("Enter an Integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u",&i);
	printf("You Entered : %d\n",i);
	printf("\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#");
	return 0;
}
