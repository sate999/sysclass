#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void handler(int);
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage : %s command\n", argv[0]);
		exit(1);
	}
	
	signal	(SIGQUIT, SIG_IGN);
	signal	(SIGINT, handler);

	execl	(argv[1], argv[1], (char *)0);
	perror	("execl() : ");
	exit(2);
}

void handler(int sigNo)
{
	printf("Signal handler. \n");
}

