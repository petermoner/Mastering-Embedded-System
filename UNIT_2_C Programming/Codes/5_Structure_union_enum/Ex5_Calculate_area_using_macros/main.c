#include<stdio.h>

#define pi 3.14
#define area(rad) (pi)*(rad)*(rad)

int main()
{
	int radius=0;
	float area=0;
	printf("enter radius :");
	scanf("%i",&radius);
	area=area(radius);
	printf("Area is : %.2f",area);
	
	
	return 0;
}