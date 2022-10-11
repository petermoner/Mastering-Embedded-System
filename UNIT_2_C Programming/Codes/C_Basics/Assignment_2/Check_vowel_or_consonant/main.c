/*
 * main.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{	 char x=0;
	printf("\#\#\#\#\#\#\#\#\#\#Console-output\#\#\#\n");
	again :
	printf("Enter an character you want to check : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&x);

	if(x=='a' ||x=='e' ||x=='i' ||x=='o' ||x=='u')
	{
		printf("%c is a vowel",x);
	}
	else
	{
		printf("%c is a consonant",x);
	}
	/*switch(x)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		printf("%c is a vowel",x);
		break;
	default:
		printf("%c is a consonant",x);
		break;
	}*/
	printf("\n\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\n");
	goto again;
	return 0;
}
