/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>

int main(void)
{
	int i=0,no=0,sr=0;
	int arr[10];

	printf("enter number of elements:");
	scanf("%d",&no);

	for(i=1;i<=no;i++)
		{
		    arr[i-1]=i*10+i;
            printf("%d  ",arr[i-1]);
		}

    printf("\n enter the element to be searched: ");
    scanf("%d",&sr);
    i=sr/10;
    printf("\n");
    printf("number found in the location : %d",i);
}

