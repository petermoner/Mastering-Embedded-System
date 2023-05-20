/*
 * main.c
 *
 *  Created on: May 17, 2023
 *      Author: Peter Moner
 */
#include "FIFO.h"

int main(void)
{
	ret_status_t ret=R_NOK;
	fifo_buffer uart;
	element_type temp;
	ret=fifo_creat(&uart);
	ret=fifo_enqueue(&uart,11);
	ret=fifo_enqueue(&uart,22);
	ret=fifo_enqueue(&uart,33);
	ret=fifo_enqueue(&uart,44);
	ret=fifo_enqueue(&uart,55);
	ret=fifo_enqueue(&uart,66);
	ret=fifo_enqueue(&uart,77);
	printf("============================================================================\n");
	ret=fifo_dequeue(&uart, &temp);
	ret=fifo_dequeue(&uart, &temp);
	printf("============================================================================\n");
	ret=fifo_display(&uart);
	printf("============================================================================\n");
	ret=fifo_size(&uart, &temp);
	printf("\n============================================================================\n");
	ret=fifo_front_print(&uart, &temp);
	printf("\n============================================================================\n");
	ret=fifo_back_print(&uart, &temp);
	return 0;
}
