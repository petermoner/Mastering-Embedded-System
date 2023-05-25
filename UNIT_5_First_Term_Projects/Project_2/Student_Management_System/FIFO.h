/*
 * FIFO.h
 *
 *  Created on: May 24, 2023
 *      Author: Peter Moner
 */

#ifndef _FIFO_H_
#define _FIFO_H_
#include "platform_types.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


#define DPRINTF(...) fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);

#define element_type Sstudent
#define MAX_SIZE 55

typedef struct{
	char fname[12];
	char lname[12];
	int roll;
	float gpa;
	int course_id[10];
}Sstudent;

typedef struct {
	int count;
	int length;
	element_type * base;
	element_type * back;
	element_type * front;
	element_type buf[MAX_SIZE];
}fifo_buffer;


typedef enum{
	R_OK,
	R_NOK
}ret_status_t;

/*********************** APIS **************************/

/**
 * @brief  This algorithm creates an empty Student Buffer by allocating the base
            pointer,front poiter and back pointer at first location of array of
            student data buffer.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_System_Create(fifo_buffer * buffer);


/**
 * @brief  This algorithm add one student data manually.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_Add_Student_Manually(fifo_buffer * buffer);


/**
 * @brief  This algorithm add one student data automatically by scanning data from a text file.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_Add_Students_From_File(fifo_buffer * buffer);


/**
 * @brief  This algorithm Search about specific student by it's own id.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_find_by_id(fifo_buffer * buffer);


/**
 * @brief  This algorithm Search about specific student by it's own first name.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_find_by_first_name(fifo_buffer * buffer);


/**
 * @brief  This algorithm Detects How many students Registered in this course.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_How_many_students_in_course(fifo_buffer * buffer);


/**
 * @brief  This algorithm Detects How many students Exists in the School.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_number_of_students(fifo_buffer * buffer);


/**
 * @brief  This algorithm Delete a specific student by it's own id .
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_delete_student(fifo_buffer * buffer);


/**
 * @brief  This algorithm Update a specific student Data by it's own id .
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_update_student(fifo_buffer * buffer);


/**
 * @brief  This algorithm Print all school student data.
 * @param  (Buffer address)
 * @retval (ret_status) Status returned while performing this operation
 */
ret_status_t School_print_students(fifo_buffer * buffer);

#endif /* _FIFO_H_ */
