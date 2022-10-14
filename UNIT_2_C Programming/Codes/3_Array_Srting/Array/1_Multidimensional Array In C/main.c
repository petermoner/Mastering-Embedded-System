/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Peter Moner
 */

#include <stdio.h>

int main(void)
{
	int i=0,j=0;
	float arr1[2][2];
	float arr2[2][2];
	float sum[2][2];
	printf("enter the elements of first matrix:");
	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
				{
					scanf("%f",&arr1[i][j]);
				}
		}
	printf("enter the elements of second matrix:");
	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
				{
					scanf("%f",&arr2[i][j]);
				}
		}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum[i][j]=arr1[i][j]+arr2[i][j];
			printf("%f\t",sum[i][j]);
		}
		printf("\n");
	}

}

