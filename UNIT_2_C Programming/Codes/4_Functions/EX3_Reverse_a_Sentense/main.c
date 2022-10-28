#include <stdio.h>


void reverseSentence();

int main() {
	
	short num=0,power=0;
    printf("Enter base number: ");
	scanf("%hi",&num);
    reverseSentence();
    return 0;
}

void reverseSentence() {
    char c;
    scanf("%c", &c);
    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}