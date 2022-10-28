#include <stdio.h>


int pow(int num,int power);

int main() {
	
	int num=0,power=0;
	int result=0;
    printf("Enter base number: ");
	scanf("%i",&num);
    printf("Enter power number (positive integer): ");
	scanf("%i",&power);
    result = pow(num,power);
	printf("%i ^ %i = %i",num,power,result);
    return 0;
}

int pow(int num,int power)
{	
	if(power>=1)
	{
		return (num*pow(num,power-1));
	}
	else 
	{
		return 1;
	}
}
