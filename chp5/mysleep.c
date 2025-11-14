#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int);
void sigalrm_handler(int);
int mysleep (int);

void main (int argc, char *argv[]) 
{
	int ret=0;
	signal (SIGINT, sigint_handler);
	ret = mysleep (atoi(argv[1]));
	printf ("remaining time : %d\n", ret);
	exit(0);
}

void sigint_handler (int sig) 
{
	if (sig == SIGINT)
	printf ("Receive SIGINT signal\n");
}
int mysleep (int sec) 
{
	int remain_sec=0;
	void *old_set;
	old_set = signal(SIGALRM, sigalrm_handler); // set & 이전 처리함수 저장
	alarm(sec);
	pause();
	remain_sec = alarm(0);
	signal (SIGALRM, old_set); // 저장된 시그널 처리함수를 원래대로 설정
	return remain_sec;
}

void sigalrm_handler (int sig) 
{
	printf ("Receive SIGALRM signal\n");
}
