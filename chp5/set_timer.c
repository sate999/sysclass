#include <stdio.h> 
#include <sys/time.h> 
#include <signal.h>

void sigalrm_signalhandler (int);
int call_count = 0;

int main() 
{
	struct itimerval t_val;
	signal (SIGALRM, sigalrm_signalhandler);
	t_val.it_value.tv_sec = 5L; t_val.it_value.tv_usec = 0L;
	t_val.it_interval.tv_sec = 1L; t_val.it_interval.tv_usec = 0L;
	
	setitimer (ITIMER_REAL, &t_val, NULL);// 5초후 최초 타임아웃, 이후 1초마다
	while (call_count <= 5)
		;
	printf ("Terminate process!!! \n");
}

void sigalrm_signalhandler (int sig) 
{
	struct itimerval o_val;
	if (sig == SIGALRM ) 
	{
		printf ("Receive SIGALRM\n");
		call_count++;
		getitimer (ITIMER_REAL, &o_val);
		printf ("tv_sec : %ld, \t tv_usec : %ld\n",
			o_val.it_value.tv_sec, o_val.it_value.tv_usec);
			// 다음번 타임아웃까지 남은 시간
	}
}
