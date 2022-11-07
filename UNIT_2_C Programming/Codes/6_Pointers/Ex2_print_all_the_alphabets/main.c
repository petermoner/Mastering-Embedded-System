#include<stdio.h>

int main()
{
	char alpha[27];
	char *ptr=NULL,i=0;
	ptr=alpha;
	for(i=0;i<=26;i++)
	{
		*ptr='A'+i;
		ptr++;
	}
	ptr=alpha;
	printf("The Alphabets are : \n");
	for(i=0;i<26;i++)
	{
		printf("%c\t",*(ptr+i));
	}
	return 0;
}