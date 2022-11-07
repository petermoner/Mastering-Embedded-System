#include<stdio.h>
#include<string.h>

int main()
{
char arr[15],input=0,i=0;
char *ptr=arr;
printf("-------------------------------------------------\n");
printf("enter number of elements of the array max(15): ");
scanf("%d",&input);
for(i=0;i<input;i++)
{
	printf("enter arr[%d] :",i);
	scanf("%d",ptr);
	ptr++;
}
printf("\n-------------------------------------------------\n");

for(i=0;i<input;i++)
{
	ptr--;
	printf("arr[%d] :%d\n",i,*ptr);

}

printf("\n-------------------------------------------------\n");

	return 0;
}