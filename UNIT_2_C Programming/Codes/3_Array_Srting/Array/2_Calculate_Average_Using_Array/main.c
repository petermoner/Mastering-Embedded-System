
	/*
	 * main.c
	 *
	 *  Created on: Oct 14, 2022
	 *      Author: Peter Moner
	 */


	#include <stdio.h>

	int main(void)
	{
		int i=0;
		float arr[100],sum=0;
		int index=0;
		printf("enter the elements number :");
		scanf("%d",&index);
		for(i=0;i<index;i++)
			{	printf("\n enter the element %d: ",i+1);
				scanf("%f",(arr+i));
				sum+=arr[i];
			}
			sum/=index;
			printf("\n sum is :%.2f",sum);
			return 0;
	}





