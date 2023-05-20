/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: Peter Moner
 */

#include "linked_list.h"

int main()
{
	struct Node *ListHead = NULL;
	uint32 UserChoice = 0;
	uint32 ListLength = 0;
	uint32 nodes_number=0;
	setbuf(stdout,NULL);
	printf("-> Hello to Single Linked List \n");
	while(1){
		printf("\n");
		printf("===============================\n");
		printf("-> 1)  Insert_Node_At_Beginning \n");
		printf("-> 2)  Insert_Node_At_End \n");
		printf("-> 3)  Insert_Node_After \n");
		printf("-> 4)  Delete_Node_At_Beginning \n");
		printf("-> 5)  Delete_Node \n");
		printf("-> 6)  Display_All_Nodes \n");
		printf("-> 7)  Get_Length \n");
		printf("-> 8)  print nth() node Data \n");
		printf("-> 9)  print_middle_node \n");
		printf("-> 10) count_from_end_then_print_data_of_node \n");
		printf("-> 11) get_nodes_number_recursive_way \n");
		printf("-> 12) detect_loop in linked list \n");
		printf("-> 13) Reverse_list \n");
		printf("-> 14) Quit from application \n");
		printf("===============================\n");

		printf("\n");
		printf("UserChoice : ");
		scanf("%i", &UserChoice);

		switch(UserChoice){
		case 1:
			Insert_Node_At_Beginning(&ListHead);
			break;
		case 2:
			Insert_Node_At_End(&ListHead);
			break;
		case 3:
			Insert_Node_After(ListHead);
			break;
		case 4:
			Delete_Node_At_Beginning(&ListHead);
			break;
		case 5:
			Delete_Node(ListHead);
			break;
		case 6:
			Display_All_Nodes(ListHead);
			break;
		case 7:
			ListLength = Get_Length(ListHead);
			printf("List Length : << %i >> Nodes\n", ListLength);
			break;
		case 8:
			print_nth_node(ListHead);
			break;
		case 9:
			print_middle_node(ListHead);
			break;
		case 10:
			count_from_end_then_print(ListHead);
			break;
		case 11:
			nodes_number=get_count_recursive(ListHead);
			printf("\n>>>>>>> Number of nodes Using Recursion Way is : %i",nodes_number);
			break;
		case 12:
			detect_loop(ListHead);
			break;
		case 13:
			Reverse_list(&ListHead);
			break;
		case 14:
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




