#include "my.h"

int g=10;
int main(int argc,char *argv[])
{
	int status;
	int t=20;
	static int  s=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
	perror("vfork failed\n");
	exit(-1);
	}
	else if(pid==0)
	{
	printf("child pid =%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);	
	g=100;
	t=200;
	s=300;
	printf("after child change pid =%d:g=%d,t=%d,s=%d\n",getpid(),g,t,s);	
	printf("\n");
	//sleep(3);
	_exit(0);
	}
	else
	{
	wait(&status);
	printf("exit code form child is %d\n",WEXITSTATUS(status));
	printf("parent pid =%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
	printf("parent pid =%d:g=%d,t=%d,s=%d\n",getpid(),g,t,s);
	printf("\n");
	return 0;
	}
}
