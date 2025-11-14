#include<unistd.h>

int main()
{
	int n;
	char buf[512];
	while(1)
	{
		n = read(0, buf, 512);
		write(1, buf, n);
	}
}
