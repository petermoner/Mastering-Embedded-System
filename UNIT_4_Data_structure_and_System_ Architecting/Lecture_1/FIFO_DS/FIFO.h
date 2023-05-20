/*
 * FIFO.h
 *
 *  Created on: May 17, 2023
 *      Author: Peter Moner
 */

#ifndef _FIFO_H_
#define _FIFO_H_
#include "platform_types.h"
#include "stdio.h"

#define element_type uint8_t
#define MAX_SIZE 5
#define queue_Debug

typedef struct {
	uint8_t count;
	uint8_t length;
	element_type * base;
	element_type * back;
	element_type * front;
	element_type buf[MAX_SIZE];
}fifo_buffer;


typedef enum{
	QUEUE_EMPTY,
	QUEUE_NOTEMPTY,
	QUEUE_FULL,
	QUEUE_NOTFULL
}fifo_status_t;

typedef enum{
	R_OK,
	R_NOK
}ret_status_t;

//APIS
ret_status_t fifo_creat(fifo_buffer * buffer);
ret_status_t fifo_enqueue(fifo_buffer * buffer,element_type item);
ret_status_t fifo_dequeue(fifo_buffer * buffer,element_type * item);
ret_status_t fifo_display(fifo_buffer * buffer);
ret_status_t fifo_size(fifo_buffer * buffer,element_type * item);
ret_status_t fifo_front_print(fifo_buffer * buffer,element_type * item);
ret_status_t fifo_back_print(fifo_buffer * buffer,element_type * item);


#endif /* _FIFO_H_ */
