#include "my.h"

int main()
{
	int fd[2];
	pid_t pid;
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error. reason :[%s]",strerror(error));
		return -1;
	}
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"create child error. reason :[%s]",strerror(error));
		return -2;
	}
	else if(pid==0)
	{
		printf("[child]:pid=%d,ppid=%d\n",getpid(),getppid());
		close(fd[0]);
		exit(0);
	}
	else
	{
		close(fd[0]);
		wait(NULL);
		return 0;	
	}
}
