#include <stdio.h>


 char prime(unsigned short num_1,unsigned short num_2); 

int main(void)
{
	unsigned short num_1=0,num_2=0;
	char result=0;
	
	printf("enter two numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%hu%hu",&num_1,&num_2);
	printf("prime numbers between %hu and %hu is : ",num_1,num_2);
	result = prime(num_1,num_2);
	
	return 0;
}


 char prime(unsigned short num_1,unsigned short num_2)
{
	char flag=0,i=0,j=0;
	

	
	for(i=num_1;i<=num_2;i++)
	{
		for(j=2;j<=(i/2);j++)
		{
			if(i==0 || i==1)
			{
				flag=1;
			}
			
			if(i%j == 0)
			{
				flag=1;
				break;
			}
		}
		if(flag == 0)
		{
			printf(" %d",i);
		}
		
		flag=0;
	}
	
	
	
}