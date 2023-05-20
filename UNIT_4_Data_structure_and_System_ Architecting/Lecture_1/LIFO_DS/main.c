/*
 * main.c
 *
 *  Created on: May 17, 2023
 *      Author: Peter Moner
 */
#include"LIFO.h"

lifo_buffer_t Uart;


int main(void)
{
    ret_status_t ret =R_NOK;
    uint32_t temp;
    ret=stack_create(&Uart);
    if(R_NOK==ret)
    {
        printf("creating uart lifo buffer is failed !!!");
    }
    else{
        printf("creating uart lifo buffer is Done");
    }

    ret=stack_push(&Uart,11);
    ret=stack_push(&Uart,22);
    ret=stack_push(&Uart,33);
    ret=stack_push(&Uart,44);
    ret=stack_push(&Uart,55);
    ret=stack_push(&Uart,66);
    ret=stack_push(&Uart,77);
    printf("**************************************\n");
    ret=stack_display(&Uart);
    printf("**************************************\n");
    ret=stack_pop(&Uart,&temp);
    ret=stack_pop(&Uart,&temp);
    ret=stack_pop(&Uart,&temp);
    printf("**************************************\n");
    ret=stack_display(&Uart);
    printf("**************************************\n");
    ret=stack_top(&Uart,&temp);
    printf("**************************************\n");
    ret=stack_size(&Uart,&temp);
    printf("**************************************\n");
	return 0;
}
