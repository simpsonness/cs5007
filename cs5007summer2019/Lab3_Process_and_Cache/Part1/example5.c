// Type in and try example5.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	char* myargv[16];	//we can stroe up to 16 arguments.
	myargv[0]="/bin/ls";	//our first argument is the program we want to launch.
	myargv[1]="-F";		//Anly additional arguments(i.e.flags) we want to make use of.
	myargv[2]=NULL;		//Terminate the argument list--similar to how we would terminate a character string.
				//(i.e. Set the last argument to NULL if we have no more flags.)

	if(fork()==0){
		// Executes command from child then teminates our process
		// Note: There are other 'exec' functions that may be helpful.
		execve(myargv[0],myargv,NULL);
		printf("Child: Should never get here\n");
		exit(1);
	}else{
		wait(NULL); // handy synchronization function again!
		printf("This always prints last\n");
	}

	return 0;
}
