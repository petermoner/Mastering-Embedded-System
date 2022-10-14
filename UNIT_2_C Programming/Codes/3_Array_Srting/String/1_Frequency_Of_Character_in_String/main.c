/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>

int main(void)
{
    char str[50],ch=0,i=0,counter=0;
    printf("enter a string : ");
    gets(str);
    printf("enter a character to find frequency : ");
    ch=getchar();
    while(str[i] != '\0')
    {
        if(ch==str[i])
        {
            counter++;
        }
        i++;
    }
    printf("frequency of %c is : %d",ch,counter);
}

