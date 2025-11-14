#include<stdio.h>
#include<signal.h>

void f1 (int i) {	printf("F1 --> [%d] \n", i);	}
void f2 (int i) {	printf("F2 --> [%d] \n", i);	}

typedef void (*sighandler_t)(int);
int main()
{
	sighandler_t	fptr;
	fptr = f2;
	(*fptr)(2);

	signal (SIGINT, f1);
	fptr = signal(SIGINT, f2);
	(*fptr)(3);
}

