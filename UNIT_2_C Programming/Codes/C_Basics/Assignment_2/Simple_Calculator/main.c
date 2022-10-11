/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */


#include <stdio.h>
#include <stdlib.h>

int main (void)
{	 float x=0 ,y=0,result=0;
	char op=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	again:
	printf("Enter process: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %c %f",&x,&op,&y);
	switch (op) {
	case '+':
			printf("%.2f %c %.2f = %.2f\n",x,op,y,x+y);
			break;
	case '-':
				printf("%.2f %c %.2f = %.2f\n",x,op,y,x-y);
				break;
	case '*':
				printf("%.2f %c %.2f = %.2f\n",x,op,y,x*y);
				break;
	case '/':
				if(y != 0)
				{
					printf("%.2f %c %.2f = %.2f\n",x,op,y,x/y);
				}
				break;
	default:
			break;
	}
	printf("\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n");
	goto again;
	return 0;
}

