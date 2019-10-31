// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	char* myargv[5];
	int choice;
	int child_status;
	if (fork() == 0) {
		printf("Please the number to choose\n \
				1 - are you child\n \
				2 - Show me the present working directory\n \
				3 - Show me disk usage.\n");
		scanf("%d", &choice);
		if (choice == 1) {
			myargv[0] = "/bin/echo";
			myargv[1] = "I am the child";
			myargv[2] = NULL;
			execve(myargv[0], myargv, NULL);
			}
		else if (choice == 2) {
			myargv[0] = "/bin/pwd";
			myargv[1] = NULL;
			execve(myargv[0], myargv, NULL);
			}
		else if (choice == 3) {
			myargv[0] = "/bin/du";
			myargv[1] = NULL;
			execve(myargv[0], myargv, NULL);
			}
		printf("Child: Should never get here\n");
		exit(1);
	} else {
		wait(NULL);
		printf("This always prints last\n");
	}

 	return 0;
}


