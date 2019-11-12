#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int pid;
	if((pid=fork())<0)
	{
	perror("Fail to work");
	return -1;
	}
	else if(pid==0)
	{
	printf("child running now -pid :%d\n.",getpid());
	exit(0);
	}
	else
	{
	printf("Father wait zombie now -pid :%d\n",getpid());
	wait(NULL);
	printf("Father exiting now -pid %d\n",getpid());
	exit(0);
	}
}
