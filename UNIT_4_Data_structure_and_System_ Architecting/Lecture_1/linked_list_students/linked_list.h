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
#include <string.h>
#include <conio.h>

#define DPRINTF(...) fflush(stdout);\
					 fflush(stdin);\
					 printf(__VA_ARGS__);\
					 fflush(stdout);\
					 fflush(stdin);

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef  char uint8;

typedef struct{
	uint32 id ;
	uint8 name[40];
	float height;
}SData;

typedef struct SStudent{
	SData Student ;
	struct SStudent *NodeLink;
}SStudent;


//APIS
void Insert_Student(void);
void Delete_student(void);
void view_students(void);
void Delete_All(void);
uint32 Get_Students_Number(void);

#endif /* LINKED_LIST_H_ */
