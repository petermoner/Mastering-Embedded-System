#include <stdio.h>

long int fact(unsigned short num);

int main(void)
{
	unsigned short num=0;
	
	printf("enter a positive integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%hu",&num);
	printf("factorial of %hu = %ld",num,fact(num));

	return 0;
}


long int fact(unsigned short num)
{
	if(num >= 1)
	{
		return num*fact(num-1);	
	}
	else
	{
		return 1;
	}
}