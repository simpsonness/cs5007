// Write a C program that calls an add function(long add(long a, long b).
#include<stdio.h>

long add(long, long);

int main() {
	long sum;
	long a = 12;
	long b = 100;
	sum = add(a,b);
	printf("%ld\n", sum);
	return (0);
}


long add(long a, long b){
	long num;
	num = a + b;
	return (num);
}
