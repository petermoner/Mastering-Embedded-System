/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: Peter Moner
 */

#include "linked_list.h"

SStudent *ListHead = NULL;


int main()
{
	uint32 UserChoice = 0;
	uint32 student_number = 0;
	setbuf(stdout,NULL);
	printf("-> Hello to Single Linked List \n");
	while(1){
		printf("\n");
		printf("==============================================================\n");
		printf("\t\t\tChoose in the following options \n");
		printf("==============================================================\n");
		printf("-> 1) Add_Student \n");
		printf("-> 2) Delete_Student \n");
		printf("-> 3) View_Students \n");
		printf("-> 4) Delete_All \n");
		printf("-> 5) Get_Students_Number \n");
		printf("-> 6) Quit from application \n");
		printf("===============================\n");

		printf("\n");
		printf("UserChoice : ");
		scanf("%i", &UserChoice);

		switch(UserChoice){
		case 1:
			Insert_Student();
			break;
		case 2:
			Delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			student_number = Get_Students_Number();
			DPRINTF("\nNumber of students is: %i",student_number);
			break;
		case 6:
			printf("Quit from application \n");
			exit(1);
			break;
		default:
			printf("User Choice out of range !!\n");
			break;
		}
	}
	return 0;
}




