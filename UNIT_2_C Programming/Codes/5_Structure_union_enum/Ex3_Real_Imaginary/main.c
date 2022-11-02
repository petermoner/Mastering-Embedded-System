#include<stdio.h>
#include<string.h>

struct Ssum{
	float real;
	float imag;
}s1,s2,result;

struct Ssum SUM_NUMBERS(struct Ssum *ptr1,struct Ssum *ptr2);

int main()
{
	printf("enter first complex number:\n\n");
	printf("enter real and imaginery respectively:");	
	scanf("%f%f",&s1.real,&s1.imag);
	printf("\nenter second complex number:\n\n");
	printf("\nenter real and imaginery respectively:");	
	scanf("%f%f",&s2.real,&s2.imag);
	
	result=SUM_NUMBERS(&s1,&s2);
	
	printf("\n\nsum = %.2f + %.2f i",result.real,result.imag);

	return 0;
}


struct Ssum SUM_NUMBERS(struct Ssum *ptr1,struct Ssum *ptr2)
{
	struct Ssum sum;
	sum.real=(ptr1->real)+(ptr2->real);
	sum.imag=(ptr1->imag)+(ptr2->imag);
	return sum;
	
	}