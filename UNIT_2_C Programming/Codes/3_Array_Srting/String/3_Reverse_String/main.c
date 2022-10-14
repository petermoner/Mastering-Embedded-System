/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>

int main(void)
{
	char str[50],j;
	unsigned char i=0;
    printf("enter a string : ");
    gets(str);

    while(str[i] != '\0')
    {
        i++;
    }
    for(j=i;j>0;j--)
    {
        printf("%c",str[j-1]);
    }
}

