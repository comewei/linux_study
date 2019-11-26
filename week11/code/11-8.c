#include "my.h"

int main()
{
	pid_t pid1,pid2,pid3;
	int status,rv;
	pid1=fork();
	pid2=fork();
	//pid3=fork();
	if(pid1<0||pid2<0||pid3<0)
	{
	perror("failed to fork!");
	return -1;
	}
	else if(pid1==0)
	{
	printf("child1	pid=%d\n",getpid());
	sleep(3);
	exit(18);
	}
	else if(pid2==0)
	{
	printf("child2	pid=%d\n",getpid());
	sleep(5);
	exit(99);
	}
	else if(pid3==0)
	{
	printf("child3	pid=%d\n",getpid());
	sleep(2);
	exit(108);
	}
	else
	{
	//rv=wait(&status);
	printf("parent waiting child end!\n");	
	rv=wait(&status);
	printf("1:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
	rv=waitpid(pid1,&status,0);
	printf("2:child %d ends.exit code is %d\n",rv,WEXITSTATUS(status));
	rv=waitpid(pid2,&status,WNOHANG);
	printf("3:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
	//rv=waitpid(pid3,&status,0);
	//printf("child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
	}
	return 0;
}
