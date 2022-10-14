/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Peter Moner*/


#include <stdio.h>

int main(void)
{
	int i=0,j=0,row=0,col=0;
	int arr[10][10];
	int trs[10][10];

	printf("enter rows and columns of matrix:");
	scanf("%d%d",&row,&col);
    printf("\n enter the elements of matrix :\n");

	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				{
				    printf("enter element a%d%d :",i,j);
					scanf("%d",&arr[i][j]);
				}
		}

    printf("entered matrix:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}



        for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				{
                    trs[j][i]=arr[i][j];
				}
		}


    printf("transpose of matrix:\n");
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d\t",trs[i][j]);
		}
		printf("\n");
	}


}

