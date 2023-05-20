/*
 * LIFO.c
 *
 *  Created on: May 17, 2023
 *      Author: Peter Moner
 */

#include "LIFO.h"

static stack_status_t IS_EMPTY(lifo_buffer_t * buffer)
{
	stack_status_t status;
	if((buffer->stack_pointer)== -1)
	{
		status=STACK_EMPTY;
	}
	else{
		status=STACK_NOTEMPTY;
	}
	return status;
}

static stack_status_t IS_FULL(lifo_buffer_t * buffer)
{
	stack_status_t status;
	if(buffer->stack_pointer >= (buffer->length)-1 ){
		status=STACK_FULL;
	}
	else{
		status=STACK_NOTFULL;
	}
	return status;
}


ret_status_t stack_create(lifo_buffer_t * buffer)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer){
		ret=R_NOK;
	}
	else{
		buffer->stack_pointer = -1;
		buffer->length=MAX_SIZE;
#ifdef stack_Debug
printf("stack is created successfully\n");
#endif // stack_Debug
ret=R_OK;
	}
	return ret;
}
ret_status_t stack_push(lifo_buffer_t * buffer,uint32_t item)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||STACK_FULL==IS_FULL(buffer)){
#ifdef stack_Debug
		printf("Erorr!!...pushing %d is failed\n",item);
#endif // stack_Debug
		ret=R_NOK;
	}
	else{
		(buffer->stack_pointer)++;
		(buffer->buf[buffer->stack_pointer])=item;
#ifdef stack_Debug
		printf("item %d is pushed successfully\n",item);
#endif // stack_Debug
		ret=R_OK;
	}
	return ret;

}
ret_status_t stack_pop(lifo_buffer_t * buffer,uint32_t * popped_item)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||STACK_EMPTY==IS_EMPTY(buffer)||NULL==popped_item){
#ifdef stack_Debug
		printf("Erorr!!...popping %d is failed\n",*popped_item);
#endif // stack_Debug
		ret=R_NOK;
	}
	else{
		*popped_item=(buffer->buf[buffer->stack_pointer]);
		(buffer->stack_pointer)--;
#ifdef stack_Debug
		printf("item %d is popped successfully\n",*popped_item);
#endif // stack_Debug
		ret=R_OK;
	}
	return ret;
}
ret_status_t stack_display(lifo_buffer_t * buffer)
{
	int i=0;
	ret_status_t ret=R_NOK;
	if(NULL==buffer||STACK_EMPTY==IS_EMPTY(buffer)){
#ifdef stack_Debug
		printf("Erorr!!...Displaying buffer is failed\n");
#endif // stack_Debug
		ret=R_NOK;
	}
	else{
		for(i=0;i<=(buffer->stack_pointer);i++)
		{
			printf("\n %d \n",(buffer->buf[i]));
		}
		ret=R_OK;
	}
	return ret;
}
ret_status_t stack_top(lifo_buffer_t * buffer,uint32_t * top_item)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||STACK_EMPTY==IS_EMPTY(buffer)||NULL==top_item){
#ifdef stack_Debug
		printf("Erorr!!...printing stack_top %d is failed\n",*top_item);
#endif // stack_Debug
		ret=R_NOK;
	}
	else{
		*top_item=(buffer->buf[buffer->stack_pointer]);
#ifdef stack_Debug
		printf("stack_top item is: %d \n",*top_item);
#endif // stack_Debug
		ret=R_OK;
	}
	return ret;
}

ret_status_t stack_size(lifo_buffer_t * buffer,uint32_t * size)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||NULL==size){
#ifdef stack_Debug
		printf("Erorr!!...printing stack_size is failed\n");
#endif // stack_Debug
		ret=R_NOK;
	}
	else{
		*size=(buffer->stack_pointer)+1;
#ifdef stack_Debug
		printf("stack_size is: %d items\n",*size);
#endif // stack_Debug
		ret=R_OK;
	}
	return ret;
}
