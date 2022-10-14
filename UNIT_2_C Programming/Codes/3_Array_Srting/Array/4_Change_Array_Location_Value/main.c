/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>

int main(void)
{
	int i=0,no=0,ins=0,loc=0;
	int arr[10];

	printf("enter number of elements:");
	scanf("%d",&no);

	for(i=0;i<no;i++)
		{
		    arr[i]=1+i;
            printf("%d  ",arr[i]);
		}

    printf("\n enter the element to be inserted: ");
    scanf("%d",&ins);
    printf("\n enter the location: ");
    scanf("%d",&loc);
	arr[loc-1]=ins;
    printf("\n");

	for(i=0;i<no;i++)
		{
            printf("%d  ",arr[i]);
		}
}

