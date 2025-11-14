#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>

#define LIMIT_TIME 20

int main()
{
	int rand_num;
	srand (getpid()); // set seed
	rand_num = rand(); // generate random number between 0 ~ (2^31-1)
	rand_num %= LIMIT_TIME; // rand_num = rand_num % LIMIT_TIME;
				// 
	printf ("\t[Child] : sleep random number : %d\n", rand_num);
	sleep (rand_num);
	printf ("\t[Child] : process terminate!\n");
	exit (0x35);
}

