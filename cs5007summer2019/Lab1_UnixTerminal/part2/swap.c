// Write a C program that swaps two integers in a function
#include<stdio.h>

void swap(int*, int*);

int main(){
	int a = 2;
	int b = 3;
	printf("before: a, %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("after: a, %d, b: %d\n", a, b);
	return 0;
}

void swap(int *a, int *b){
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
