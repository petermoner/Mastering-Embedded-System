#include<stdio.h>

int main()
{
	int *ab=NULL;
	int m=29;
	printf("-------------------------------------------------------\n\n");

	printf("Address of m : %d\n",&m);
	printf("Value of m : %d\n",m);
	printf("-------------------------------------------------------\n\n");
	printf("Now ab is assigned with the address of m.\n");
	
	ab=&m;
	printf("Address of pointer ab : %d\n",ab);
	printf("Value of pointer ab : %d\n",*ab);	
	printf("-------------------------------------------------------\n\n");
	*ab=34;
	printf("Address of pointer ab : %d\n",ab);
	printf("Value of pointer ab : %d\n",*ab);	
	printf("-------------------------------------------------------\n\n");
	*ab=7;
	printf("Address of pointer ab : %d\n",ab);
	printf("Value of pointer ab : %d\n",*ab);	
	return 0;
}