#include<stdio.h>
#include<string.h>

struct Sstudent{
	unsigned char name[30];
	unsigned short roll;
	float marks ;
}Sfirst;


int main()
{
	printf("enter information of student: \n\n");
	printf("enter name:");
	gets(Sfirst.name);
	printf("enter roll number:");
	scanf("%hu",&Sfirst.roll);
	printf("enter marks:");
	scanf("%f",&Sfirst.marks);
	printf("\nname:%s\nroll number: %hu\nmarks: %.2f",Sfirst.name,Sfirst.roll,Sfirst.marks);

	
	
	return 0;
}