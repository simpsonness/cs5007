// Write a C program using the goto command and a label.
#include <stdio.h>

int main(){
	int num;
	num = 1;

repeat:
	printf("%d\n", num);
	num ++;

	if(num <= 10)
		goto repeat;

	return 0;
}
