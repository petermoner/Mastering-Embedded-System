#include"uart.h"
unsigned char string_buffer[100]="learn_in_depth: <Peter>";
unsigned char const string_buffer2[100]="create .rodata section";

void main(void)
{
	uart_send_string(string_buffer);
}