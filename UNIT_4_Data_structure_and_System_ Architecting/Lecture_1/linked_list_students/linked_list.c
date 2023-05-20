/*
 * linked_list.c
 *
 *  Created on: May 20, 2023
 *      Author: Peter Moner
 */

#include "linked_list.h"

extern SStudent *ListHead;


static void fill_data(SStudent ** student)
{
	char text[40];
	DPRINTF("\nEnter Student Name: ");
	gets((*student)->Student.name);

	DPRINTF("\nEnter Student ID: ");
	gets(text);
	(*student)->Student.id=atoi(text);

	DPRINTF("\nEnter Student Height: ");
	gets(text);
	(*student)->Student.height=atof(text);
}


void Insert_Student(void){
	SStudent *TempNode = NULL;
	SStudent *LastNode = NULL;


	TempNode = (SStudent *)malloc(sizeof(SStudent));
	if(NULL != TempNode){

		TempNode->NodeLink = NULL;

		if(NULL == ListHead)
		{
			ListHead = TempNode;
		}
		else
		{
			LastNode=ListHead;
			while(NULL != LastNode->NodeLink)
			{
				LastNode = LastNode->NodeLink;
			}
			LastNode->NodeLink = TempNode;
		}
		fill_data(&TempNode);
	}
	else{
		/* Nothing */
	}

}


void Delete_student(void){
	uint32 id=0;
	SStudent* selectedNode=NULL;
	SStudent* prevNode=NULL;
	uint8 flag=0;

	if(NULL == ListHead)
	{
		DPRINTF("\n>>>>>>>>> NO Students exist..!!");
	}
	else
	{
		DPRINTF("\nEnter Student ID: ");
		scanf("%d",&id);
		selectedNode=ListHead;

		while(selectedNode)
		{
			if((selectedNode->Student.id) == id)
			{
				if(prevNode)
				{
					prevNode->NodeLink = selectedNode->NodeLink;
				}
				else{
					ListHead=selectedNode->NodeLink;
				}
				free(selectedNode);
				flag=1;
				break;
			}
			else
			{
				prevNode=selectedNode;
				selectedNode=selectedNode->NodeLink;
			}
		}

		if(!flag)
		{
			DPRINTF("\n >>>>>>>>> Cannot find student ID..!!");
		}
	}
}

void view_students(void){
	SStudent *TempNode = ListHead;
	uint32 count=1;

	if(NULL == TempNode){
		printf("\n>>>>>>>>> List is empty !! ");
	}
	else{
		DPRINTF("\n======= printing All Students Data =======");

		while(TempNode != NULL){
			DPRINTF("\n===============================");
			DPRINTF("\n\n Record number %d ",count);
			DPRINTF("\nStudent Name: %s",(TempNode->Student.name));
			DPRINTF("\nStudent ID: %i",(TempNode->Student.id));
			DPRINTF("\nStudent Height: %.2f",(TempNode->Student.height));
			TempNode = TempNode->NodeLink;
			count++;
		}
	}
}



void Delete_All(void){
	SStudent* TempNode=NULL;
	SStudent* NextNode=NULL;

	if(NULL == ListHead)
	{
		DPRINTF("\n>>>>>>>>> NO Students exist..!!");
	}
	else
	{
		NextNode=ListHead;
		ListHead=NULL;

		while(NextNode)
		{
			TempNode=NextNode;
			NextNode=NextNode->NodeLink;
			free(TempNode);
		}
	}
}





uint32 Get_Students_Number(void){
	SStudent  *TempNode = ListHead;
	uint32 NodeCount = 0;

	while(TempNode != NULL){
		NodeCount++;
		TempNode = TempNode->NodeLink;
	}

	return NodeCount;
}



