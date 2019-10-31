// Write a C program called array.c that has an array of 400 integers in the function of main.
#include <stdio.h>

int main(){
	int myArray[400];
	myArray[3] = 45;
	myArray[29] = 111;
	myArray[30] = 0;

	printf("%d %d %d\n", myArray[3], myArray[29],myArray[30]);

	return 0;
}
