/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{	 float i=0 ,x=0,multi=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	printf("Enter Two Integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&i,&x);
	multi=i*x;
	printf("multi : %f\n",multi);
	printf("\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#");
	return 0;
}
