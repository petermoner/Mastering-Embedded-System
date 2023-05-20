/*
 * linked_list.h
 *
 *  Created on: May 20, 2023
 *      Author: Peter Moner
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

struct Node{
	uint32 NodeData;
	struct Node *NodeLink;
};

void Insert_Node_At_Beginning(struct Node **List);
void Insert_Node_At_End(struct Node **List);
void Insert_Node_After(struct Node *List);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node(struct Node *List);
void Display_All_Nodes(struct Node *List);

									/*
									 * >>>>>>>>>>>>>> Thinking question Tasks <<<<<<<<<<<<<<
									 * */
/*print nth() node Data*/
void print_nth_node(struct Node *List);

/*Find Length of a Linked List (Iterative)*/
uint32 Get_Length(struct Node *List);

/*Find Length of a Linked List (Recursive)*/
uint32 get_count_recursive(struct Node *List);

/*Program for print data of n’th node from the end of a Linked List*/
void count_from_end_then_print(struct Node *List);

/*Find the middle of a given linked list*/
void print_middle_node(struct Node *List);

/*Detect loop in a linked list*/
void detect_loop(struct Node *List);

/*Reverse a linked list*/
void Reverse_list(struct Node **List);
#endif /* LINKED_LIST_H_ */
