#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() 
{
	int stat;
	if (fork() == 0) // child
		exit(1);
	else
		wait(&stat); // parent
	if (WIFEXITED(stat))
		printf("Child exit status: %d\n", WEXITSTATUS(stat));
}

