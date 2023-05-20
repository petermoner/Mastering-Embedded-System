/*
 * linked_list.c
 *
 *  Created on: May 20, 2023
 *      Author: Peter Moner
 */

#include "linked_list.h"



void Insert_Node_At_Beginning(struct Node **List){
	struct Node *TempNode = NULL;

	TempNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != TempNode){
		printf("Enter Node Data : ");
		scanf("%i", &TempNode->NodeData);

		/* Check if linked list is empty */
		if(NULL == *List){ /* Linked list is empty */
			TempNode->NodeLink = NULL;
			*List = TempNode;
		}
		else{ /* Linked list is not empty */
			TempNode->NodeLink = *List;
			*List = TempNode;
		}
	}
	else{
		/* Nothing */
	}
}

void Insert_Node_At_End(struct Node **List){
	struct Node *TempNode = NULL;
	struct Node *LastNode = NULL;

	TempNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != TempNode){
		printf("Enter Node Data : ");
		scanf("%i", &TempNode->NodeData);
		TempNode->NodeLink = NULL;

		/* Check if linked list is empty */
		if(NULL == *List){ /* Linked list is empty */
			*List = TempNode;
		}
		else{ /* Linked list is not empty */
			LastNode = *List;
			while(LastNode->NodeLink != NULL){
				LastNode = LastNode->NodeLink;
			}
			LastNode->NodeLink = TempNode;
		}
	}
	else{
		/* Nothing */
	}
}

void Insert_Node_After(struct Node *List){
	struct Node *TempNode = NULL;
	struct Node *NodeListCounter = NULL;
	uint32 NodePosition = 0;    /*  */
	uint32 ListLength = 0;      /*  */
	uint32 NodeCounter = 1;     /* Points to the first node */

	printf("Enter Node Position (First node is position = 1): ");
	scanf("%i", &NodePosition);

	ListLength = Get_Length(List);
	if(NodePosition > ListLength){
		printf("Invalid Node Position -> List has ( %i ) Nodes \n", ListLength);
	}
	else{
		NodeListCounter = List;
		while(NodeCounter < NodePosition){
			NodeCounter++;
			NodeListCounter = NodeListCounter->NodeLink;
		} /* TempNode points to the node where we have to insert after it */
		TempNode = (struct Node *)malloc(sizeof(struct Node));
		if(NULL != TempNode){
			printf("Enter Node Data : ");
			scanf("%i", &TempNode->NodeData);
			/* Connect the right side connection */
			TempNode->NodeLink = NodeListCounter->NodeLink;
			/* Connect the Left side connection */
			NodeListCounter->NodeLink = TempNode;
		}
		else{
			/* Nothing */
		}
	}
}

void Delete_Node_At_Beginning(struct Node **List){
	struct Node *TempNode = *List;
	uint32 ListLength = 0;      /*  */

	ListLength = Get_Length(*List);
	if(ListLength == 0){
		printf("List is Empty , nothing to be deleted !! \n");
	}
	else{
		*List = TempNode->NodeLink;
		TempNode->NodeLink = NULL; /* TempNode is a free node */
		free(TempNode);
	}
}

void Delete_Node(struct Node *List){
	struct Node *NodeListCounter = List;
	struct Node *NextNode = List;
	uint32 NodePosition = 0;    /*  */
	uint32 ListLength = 0;      /*  */
	uint32 NodeCounter = 1;     /* Points to the first node */

	printf("Enter Node Position (First node is position = 1): ");
	scanf("%i", &NodePosition);
	ListLength = Get_Length(List);
	if((NodePosition > ListLength) || (ListLength == 1)){
		printf("Please use Delete_Node_At_Beginning !! \n");
	}
	else{
		while(NodeCounter < (NodePosition - 1)){
			NodeCounter++;
			NodeListCounter = NodeListCounter->NodeLink;
		}
		NextNode = NodeListCounter->NodeLink;
		NodeListCounter->NodeLink = NextNode->NodeLink;
		free(NextNode);
	}
}

void Display_All_Nodes(struct Node *List){
	struct Node *TempNode = List;

	if(NULL == TempNode){
		printf("List is empty !! \n");
	}
	else{
		printf("Node Values : ");
		while(TempNode != NULL){
			printf("%i -> ", TempNode->NodeData);
			TempNode = TempNode->NodeLink;
		}
		if(NULL == TempNode){
			printf("NULL \n");
		}
	}
}

uint32 Get_Length(struct Node *List){
	struct Node *TempNode = List;
	uint32 NodeCount = 0;

	while(TempNode != NULL){
		NodeCount++;
		TempNode = TempNode->NodeLink;
	}

	return NodeCount;
}

void print_nth_node(struct Node *List)
{
	uint32 selected_node =0,nodes_length=0,counter_node=1;
	struct Node *Temp_node =NULL;

	if(NULL == List)
	{
		printf("List is Empty , nothing to be printed !! \n");
	}
	else
	{
		Temp_node = List;
		printf("\n Enter the desired node to be printed: ");
		scanf("%i",&selected_node);
		nodes_length=Get_Length(List);
		if(selected_node > nodes_length)
		{
			printf("\n >>>>>>>Invalid Node Position -> List has ( %i ) Nodes only \n",nodes_length);
		}
		else{
			while(counter_node < selected_node)
			{
				Temp_node = Temp_node->NodeLink;
				counter_node++;
			}
			printf("\n >>>>>>> Output : %i",Temp_node->NodeData);
		}
	}
}

uint32 get_count_recursive(struct Node *List)
{
	uint32 count=0;

	if(NULL == List)
	{
		count =0;
	}
	else
	{
		count = 1+get_count_recursive(List->NodeLink);
	}
	return count;
}


void count_from_end_then_print(struct Node *List)
{
	struct Node *Temp_node=List;
	uint32 list_length=Get_Length(Temp_node),counter_node=0,selected_node=0;
	if(NULL == List)
	{
		printf("List is Empty , nothing to be printed !! \n");
	}
	else{
		printf("\n Enter the desired number of nodes counted from the end: ");
		scanf("%i",&selected_node);

		if(selected_node > list_length)
		{
			printf("\n >>>>>>>Invalid Node Position -> List has ( %i ) Nodes only \n",list_length);
		}
		else{
			while(counter_node < (list_length - selected_node))
			{
				Temp_node = Temp_node->NodeLink;
				counter_node++;
			}
			printf("\n >>>>>>> Output : %i",Temp_node->NodeData);
		}
	}
}


void print_middle_node(struct Node *List)
{
	uint32 selected_node =0,nodes_length=0,counter_node=1;
	struct Node *Temp_node =NULL;

	if(NULL == List)
	{
		printf("List is Empty , nothing to be printed !! \n");
	}
	else
	{
		nodes_length=Get_Length(List);
		selected_node = (nodes_length/2)+1;
		Temp_node = List;
		while(counter_node < selected_node)
		{
			Temp_node = Temp_node->NodeLink;
			counter_node++;
		}
		printf("\n >>>>>>> Output : %i",Temp_node->NodeData);
	}
}


void detect_loop(struct Node *List)
{
	struct Node *fast = List,*slow = List;

	if(NULL == List)
	{
		printf("List is Empty , no list to be tested !! \n");
	}
	else{
		while(fast && slow && fast->NodeLink)
		{
			slow=slow->NodeLink;
			fast=(fast->NodeLink)->NodeLink;
			if(fast == slow)
			{
				printf("\n >>>>>>> loop is founded ");
				break;
			}
		}
		printf("\n >>>>>>> NO loop is founded..!! ");
	}
}


void Reverse_list(struct Node **List)
{
	struct Node *current=*List,*next=NULL,*prev=NULL;

	while (current != NULL) {
		// Store next
		next = current->NodeLink;

		// Reverse current node's pointer
		current->NodeLink = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*List = prev;
}






