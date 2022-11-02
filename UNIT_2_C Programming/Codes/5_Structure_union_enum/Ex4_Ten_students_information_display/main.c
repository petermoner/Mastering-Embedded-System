#include<stdio.h>
#include<string.h>

struct Sstudent{
	unsigned char name[30];
	unsigned short roll;
	unsigned short marks ;
}student[10];


int main()
{
	int i=0;
	for(i=0;i<10;i++)
	{
		printf("\n\nenter information of student[%d]: \n\n",i+1);
		printf("enter roll number:");
		scanf("%hu",&student[i].roll);
		fflush(stdin);fflush(stdout);
		printf("enter name:");
		gets(student[i].name);
		printf("enter marks:");
		scanf("%hu",&student[i].marks);
	}
	
	printf("\n\nDisplaying Information of students\n\n");
	
	for(i=0;i<10;i++)
	{		
		printf("\ninformation of roll number[%d]: ",i+1);
		printf("\nname: %s",student[i].name);
		printf("\nmarks: %hu",student[i].marks);
	}

	
	
	return 0;
}