#include "my.h"

int main()
{
	pid_t pid;
	int r,status;
	pid=fork();
	if(pid<0)
	{
	perror("failed fork\n");
	return -1;	
	}
	else if(pid==0)
	{
	printf("child %d is running\n",getpid());
	printf("child will exit!\n");	
	while(1);
	exit(200);
	}
    else {
	printf("parent is waitting child's  %d exit!\n",pid);
	//sleep(100);
	while((r=wait(&status))!=-1)
	{
	if(WIFEXITED(status))
	{
	printf("child %d is finished,return code =%d\n",r,WEXITSTATUS(status));
	}
	else if(WIFSIGNALED(status))
	{
	printf("child %d is finished with siganle mode, signal code =%d\n",r,WTERMSIG(status));	
	}
	printf("Unknown mode!\n");

	}
	printf("\n");
	printf("parent %d is running\n",getpid());
	return 0;
	}
}
