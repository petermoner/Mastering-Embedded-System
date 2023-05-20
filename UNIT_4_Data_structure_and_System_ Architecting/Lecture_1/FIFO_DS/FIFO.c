/*
 * FIFO.c
 *
 *  Created on: May 17, 2023
 *      Author: Peter Moner
 */


#include "FIFO.h"

fifo_status_t IS_FULL(fifo_buffer * buffer)
{
	fifo_status_t ret;
	if((buffer->count)==(buffer->length))
	{
		ret=QUEUE_FULL;
	}
	else
	{
		ret=QUEUE_NOTFULL;
	}
	return ret;
}

fifo_status_t IS_EMPTY(fifo_buffer * buffer)
{
	fifo_status_t ret;
	if((buffer->count)==0)
	{
		ret=QUEUE_EMPTY;
	}
	else
	{
		ret=QUEUE_NOTEMPTY;
	}
	return ret;
}


ret_status_t fifo_creat(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer)
	{
#ifdef queue_Debug
		printf("Erorr!!...creating queue...is failed\n");
#endif // queue_Debug
		ret=R_NOK;
	}
	else{
		(buffer->base)=	(buffer->buf);
		(buffer->back)=	(buffer->buf);
		(buffer->front)=(buffer->buf);
		(buffer->count)=0;
		(buffer->length)=MAX_SIZE;
#ifdef queue_Debug
		printf("creating queue...is Done\n");
#endif // queue_Debug
		ret=R_OK;
	}
	return ret;
}
ret_status_t fifo_enqueue(fifo_buffer * buffer,element_type item)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_FULL==IS_FULL(buffer))
	{
#ifdef queue_Debug
		printf("Erorr!!...enqueue item %d...is failed\n",item);
#endif // queue_Debug
		ret=R_NOK;
	}
	else{
		*(buffer->back)=item;
		(buffer->count)++;
		if((buffer->back)==((buffer->base)+(buffer->length)*sizeof(element_type)))
		{
			(buffer->back)=	(buffer->base);
		}
		else
		{
			(buffer->back)++;
		}
#ifdef queue_Debug
		printf("\t enqueue item %d...is Done\n",item);
#endif // queue_Debug
		ret=R_OK;
	}
	return ret;
}
ret_status_t fifo_dequeue(fifo_buffer * buffer,element_type * item)
{

	ret_status_t ret=R_NOK;
	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||NULL==item||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
#ifdef queue_Debug
		printf("Erorr!!...dequeue item %d...is failed\n",*item);
#endif // queue_Debug
		ret=R_NOK;
	}
	else{

		*item=*(buffer->front);
		(buffer->count)--;
		if((buffer->front)==((buffer->base)+(buffer->length)*sizeof(element_type)))
		{
			(buffer->front)=	(buffer->buf);
		}
		else
		{
			(buffer->front)++;
		}
#ifdef queue_Debug
		printf("\t dequeue item %d...is Done\n",*item);
#endif // queue_Debug
		ret=R_OK;
	}
	return ret;
}
ret_status_t fifo_display(fifo_buffer * buffer)
{
	element_type* print=(buffer->front);
	ret_status_t ret=R_NOK;
	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
#ifdef queue_Debug
		printf("FIFO is EMPTY\n");
#endif // queue_Debug
		ret=R_NOK;
	}
	else{
		while(print != (buffer->back))
		{
			printf("%d \n",*print);
			print++;
		}
		ret=R_OK;
	}
	return ret;
}
ret_status_t fifo_size(fifo_buffer * buffer,element_type * item)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||NULL==item||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
#ifdef queue_Debug
		printf("Erorr!!...print size ... is failed\n");
#endif // queue_Debug
		ret=R_NOK;
	}
	else{
#ifdef queue_Debug
		*item=buffer->count;
		printf("size of FIFO is %d items",*item);
#endif // queue_Debug
		ret=R_OK;
	}
	return ret;
}
ret_status_t fifo_front_print(fifo_buffer * buffer,element_type * item)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||NULL==item||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
#ifdef queue_Debug
		printf("Erorr!!...print front item ... is failed\n");
#endif // queue_Debug
		ret=R_NOK;
	}
	else{
#ifdef queue_Debug
		*item=*(buffer->front);
		printf("front item of FIFO is %d items",*item);
#endif // queue_Debug
		ret=R_OK;
	}
	return ret;
}
ret_status_t fifo_back_print(fifo_buffer * buffer,element_type * item)
{
	ret_status_t ret=R_NOK;
	element_type * inc=(buffer->front)+((buffer->count)-1)*sizeof(element_type);

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||NULL==item||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
#ifdef queue_Debug
		printf("Erorr!!...print back item ... is failed\n");
#endif // queue_Debug
		ret=R_NOK;
	}
	else{
#ifdef queue_Debug
		*item=*inc;
		printf("back item of FIFO is %d items",*item);
#endif // queue_Debug
		ret=R_OK;
	}
	return ret;
}
