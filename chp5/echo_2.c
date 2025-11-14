#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void signalhandler(int);

int main()
{
	int size = 0;
	char temp[BUFSIZ];

	signal(SIGINT, signalhandler);
	signal(SIGQUIT, signalhandler);

	while(1)
	{
		size = read(0, temp, BUFSIZ);
		write(1, temp, size);
	}
	exit(0);
}
void signalhandler(int sig)
{
	if (sig == SIGINT) 
	{
		printf("SIGINT received and exit\n");
		exit(1);
	}
	else if(sig == SIGQUIT)
	{
		printf("SIGQUIT received and process continue.\n");
	}
}

