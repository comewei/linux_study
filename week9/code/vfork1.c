#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	int cnt=1;
	pid_t pid =vfork();
	if(pid<0)
	{
	printf("process error!\n");	
	return 1;
	}
	else if(pid==0)
	{
	printf("this is a child process,id=%d,count=%d\n",getpid(),cnt++);	
	}
	else
	{
	printf("this is a parent process,id=%d,count=%d\n",getpid(),cnt++);
	}
	return 0;
}
