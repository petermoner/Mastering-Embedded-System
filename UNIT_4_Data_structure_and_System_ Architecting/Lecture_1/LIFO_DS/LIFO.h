/*
 * LIFO.h
 *
 *  Created on: May 17, 2023
 *      Author: Peter Moner
 */

#ifndef _LIFO_H_
#define _LIFO_H_

#include "platform_types.h"
#include "stdio.h"
#define MAX_SIZE 5

#define stack_Debug

typedef struct {
	sint8_t stack_pointer;
	uint8_t length;
	uint32_t buf[MAX_SIZE];
}lifo_buffer_t;

typedef enum{
	STACK_EMPTY,
	STACK_NOTEMPTY,
	STACK_FULL,
	STACK_NOTFULL
}stack_status_t;

typedef enum{
	R_OK,
	R_NOK
}ret_status_t;

//APIS

ret_status_t stack_create(lifo_buffer_t * buffer);
ret_status_t stack_push(lifo_buffer_t * buffer,uint32_t item);
ret_status_t stack_pop(lifo_buffer_t * buffer,uint32_t * popped_item);
ret_status_t stack_display(lifo_buffer_t * buffer);
ret_status_t stack_top(lifo_buffer_t * buffer,uint32_t * top_item);
ret_status_t stack_size(lifo_buffer_t * buffer,uint32_t * size);



#endif /* _LIFO_H_ */
