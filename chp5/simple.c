#include <signal.h> 
#include <stdio.h>
#include <unistd.h>

void child (int sig) 
{
	printf ("Child: signal [%d] occurred. \n", sig);
}

int main () 
{
	int childPid;
	if ((childPid=fork()) == 0) { /* child */
		signal (SIGQUIT, child); /* SIGQUIT=3 */
		while (1) {
			sleep (1);
		}
	}
	/* parent */
	sleep (2);
	kill (childPid, SIGQUIT);
}
