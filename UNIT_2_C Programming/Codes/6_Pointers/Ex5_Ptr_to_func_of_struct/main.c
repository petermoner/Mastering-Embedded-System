#include<stdio.h>
#include<string.h>

struct employee
{
	char name[15];
	unsigned int id;
};

int main()
{
struct employee emp1={"peter",1},emp2={"moner",2},emp3={"goda",3};
struct employee* arr[]={&emp1,&emp2,&emp3};
struct employee *((*ptr)[3])=&arr;
printf("employee name is : %s\n",(**(*ptr+1)).name);
printf("employee name is : %d\n",(**(*ptr+1)).id);
	
	return 0;
}