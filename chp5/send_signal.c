#include <stdio.h> 
#include <sys/wait.h>
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>

int main() 
{
	int pid=0, status=0;
	if ((pid = fork()) == 0) 
	{ /* child */
		execlp ("rcv_signal", "rcv_signal", (char *)NULL);
		perror ("execlp() : "); exit(2);
	}
	else if (pid > 0) 
	{ /* parent */
		sleep (2);
		kill (pid, SIGINT); // send SIGINT to child process
		printf ("[Parent]: Send SIGINT\n");
		wait (&status);
		printf ("[Parent]: Child killed by Parent. [%x] \n", status);
	}
}

