#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() 
{ 
	int stat; pid_t pid;
	if ((pid=fork()) == 0) 
	{ // child
		alarm (1); while (1);
	}
	else wait(&stat); // parent
	if (WIFSIGNALED(stat)) 
	{
		printf ("Child exit signal # = [%d]\n", WTERMSIG(stat));
		psignal(WTERMSIG(stat), "Child exit signal");
	}
}
