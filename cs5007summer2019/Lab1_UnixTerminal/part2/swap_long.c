// Now modify your program to swap two long's.
#include <stdio.h>

int main() {
	long int a = 2;
	long int b = 3;
	long int temp;

	printf("before a: %ld, b: %ld\n", a, b);
	temp = a;
	a = b;
	b = temp;
	printf("after a: %ld, b: %ld\n", a, b);
	
	return 0;
}
