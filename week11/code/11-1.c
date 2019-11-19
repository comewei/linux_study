#include "my.h"

int main()
{
	pid_t pid;
	int r,status;
 	pid=fork();
	if(pid<0)
	{
	perror("failed fork!\n");
	return -1;
	}
	else if(pid==0)
	{
	printf("child %d is running\n",getpid());
	printf("child will exit!\n");	
	//while(1);
	exit(200);
	}
    else {
	printf("parent is waitting child's  %d exit!\n",pid);
	sleep(100);
	printf("parent %d is running\n",getpid());
	return 0;
	}
}
