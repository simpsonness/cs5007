// Write a C program using a switch statement
#include <stdio.h>

int main(){
	int x = 1;
	switch (x){
		case 1: printf("Choice is 1\n");
			break;
		case 2: printf("Choice is 2\n");
			break;
		default: printf("Choice other than 1 and 2\n");
			break;
	}
	return 0;
}
