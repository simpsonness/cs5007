// Write a C program that swaps two integers(in the main body of code)
#include<stdio.h>

int main () {
	int x = 2;
	int y = 3;
	int temp;

	printf("before x: %d, y: %d\n", x, y);
	temp = x;
	x = y;
	y = temp;
	printf("after x: %d, b: %d\n", x, y);
	return 0;
}
