#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int pid;
	if((pid=fork())<0)
	{
	perror("Fail to fork");
	return -1;	
	}
	else if(pid==0)
	{
	printf("child running now -pid :%d\n",getpid());
	while(1);
	}
	else
	{
	getchar();
	printf("Father exit now -pid :%d\n",getpid());
	exit(0);
	}
	
}
