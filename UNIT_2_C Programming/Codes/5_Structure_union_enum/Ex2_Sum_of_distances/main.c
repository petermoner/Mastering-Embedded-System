#include<stdio.h>
#include<string.h>

struct Sdistanse{
	float inch;
	unsigned int feet;
}s1,s2,sum;


int main()
{
	printf("enter information of 1st distance: \n\n");
	printf("enter feet:");
	scanf("%i",&s1.feet);
	printf("enter inch:");
	scanf("%f",&s1.inch);


	printf("enter information of 2nd distance: \n\n");
	printf("enter feet:");
	scanf("%i",&s2.feet);
	printf("enter inch:");
	scanf("%f",&s2.inch);

sum.inch=s1.inch+s2.inch;
sum.feet=s1.feet+s2.feet;
if(sum.inch>12)
{	sum.inch-=12;
	sum.feet++;
}
	printf("\n\nsum of distances : %i \'- %.1f \"",sum.feet,sum.inch);

	
	
	return 0;
}