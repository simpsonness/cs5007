// Modify this file for your assignment

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>
#include<signal.h>

#define BUFFER_SIZE 80
#define MAX_ARGS 10

char**journal;
int counter = 0;

pid_t worker1 = 0;
pid_t worker2 = 0;

void error(const char*msg){
	fprintf(stderr,"%s:%s\n", msg, strerror(errno));
	exit(1);
}

//signal handler
void sigint_handler(intsig){
	printf("\nmini-shell terminated by user\n");
	printf("PID%d:Over!", getpid());
	if(worker1 != 0)
	kill(worker1, SIGTERM);
	if(worker2 != 0)
	kill(worker2, SIGTERM);
	exit(0);
	}	

void execute(const char *command){
	//split command to command and arguments
	//command = "echo Hello world" -> args = {"echo","Hello","world"}
	const char *SEPARATORS = "\t\n";
	char *args[MAX_ARGS];
	char *p;
	int n = 0;

	p = strtok((char*)command, SEPARATORS);
	while(p!=NULL){
		//args[n] = p; n++
		args[n++] = p;
		p = strtok(NULL, SEPARATORS);
	}

	args[n] = NULL;

	if(execvp(args[0], args) == -1)
	error("Cannot find command.");
	}

void mysystem(const char *command){
	//fork process
	pid_t pid = fork();
	if(pid == -1)
	error("Invalid fork");

	if(pid == 0){
		execute(command);
	//parent
	}else{
		//printf("created child with pid = %d\n", pid);
		worker1 = pid;
		wait(NULL);
		//printf("finished child with pid = %d\n", pid);
		worker1 = 0;
	}
	}

void mysystem_with_pipe(const char *cmd1, const char *cmd2){
	//printf("create pipe\n");
	int fd[2];
	if(pipe(fd) == -1)
	error("cannot create pipe");

	//printf("fork #1\n");
	pid_t pid = fork();

	if(pid < 0)
	error("Invalid fort #1");

	if(pid == 0){
		//printf("child started %d\n", getpid());
		dup2(fd[1], 1);
		close(fd[0]);
		execute(cmd1);
		error("cannot excute #1");
	}
	//printf("Parent resumed%d\n", getpid());
	worker1 = pid;

	//printf("fork #2\n");
	pid_t pid2 = fork();

	if(pid < 2)
	error("Invalid fort #2");

	if(pid2 == 0){
		//printf("Child started%d\n", getpid());
		dup2(fd[0], 0);
		close(fd[1]);
		execute(cmd2);
		error("cannot execute#2");
	}
	//printf("parent resumed %d\n",getpid());
	worker2 = pid;

	int ch1 = wait(NULL);
	//printf("Child finished %d\n", ch1);
	worker1 = 0;
	char eof = EOF;
	write(fd[0], &eof, 1);
	close(fd[1]);

	int ch2 = wait(NULL);
	//printf("Child finished%d\n",ch2);
	worker2 = 0;
	close(fd[0]);
	}

void help(){
	printf("Buildit commands:\n");
	printf("cd\nexit\nhelp\nhistory\n");
}

void cd(const char *path){
	//printf(:path:%s", path);
	chdir(path);
}

void quit(){
	printf("Over!\n");
	exit(0);
	}

void history(){
	printf("Record:\n");
	int i;
	for(i = 0; i < counter; i++)
	printf("%d%s\n", i, journal[i]);
}

void process(const char *command){
	char *p = strchr(command,'|');
	if(p == NULL){
		mysystem(command);
	}else{
		// split command on two parts: cmd1 | cmd2
		// For example: command = "ls -l | wc" -> cmd1 = "ls -l", cmd2 = "wc"
		char cmd1[BUFFER_SIZE];
		char cmd2[BUFFER_SIZE];
		strncpy(cmd1, command,p-command);
		strcpy(cmd2, p+1);
		//printf("cmd1 = %s, cmd2 = %s\n", cmd1, cmd2);
		mysystem_with_pipe(cmd1, cmd2);
	}
	} 
	

int main(){
	char command[BUFFER_SIZE];
	signal(SIGINT, sigint_handler);
	
	journal = malloc(sizeof(char*));
	journal[0] = malloc(BUFFER_SIZE);

	while(1){
		printf("%s_mini-shell>", getlogin());
		fgets(command, BUFFER_SIZE, stdin);//"Hello\n\0"
		command[strlen(command)-1]='\0';//remove last '\n'from command

	//append to history
	strcpy(journal[counter++], command);
	journal = realloc(journal,(counter+1)*sizeof(char*));
	journal[counter] = malloc(BUFFER_SIZE);

	if(strcmp(command, "help") == 0)
	help();
	else if(strcmp(command, "exit") == 0)
	quit();
	else if(strcmp(command, "history") == 0)
	history();
	else if(strncmp(command,"cd", 3) == 0)
	cd(command + 3);
	else
	process(command);
	}

	//free memory
	int i;
	for(i = 0; i < counter; i++)
	free(journal[i]);
	free(journal);

	return 0;
}	
  

