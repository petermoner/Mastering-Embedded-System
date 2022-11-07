#include<stdio.h>
#include<string.h>

int main()
{
char name[30],count=0,i=0;
char *ptr=name;
printf("-------------------------------------------------\n");
printf("enter string: ");
gets(name);
while(*ptr)
{
	count++;
	ptr++;
}

printf("string is : ");
ptr=name;
for(i=count;i>=0;i--)
{
	printf("%c",*(ptr+i));
}
printf("\n-------------------------------------------------\n");

	return 0;
}