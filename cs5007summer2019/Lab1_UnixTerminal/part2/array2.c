// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *myArray = malloc(400 * sizeof(int));
	myArray[3] = 45;
	myArray[29] = 111;
	myArray[30] = 0;
	printf("%d, %d, %d\n", myArray[3], myArray[29], myArray[30]);
	free(myArray);
	return 0;
} 
