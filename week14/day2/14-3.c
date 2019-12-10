#include "my.h"

void fun (void *arg)
{
	printf("thread is running.pid=%d\n",getpid());

}
int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,(void *(*)())fun,NULL);
	if(ret!=0)
	{
	perror("create failed\n");
	return -1;	
	}
	printf("All Done\n");
	return 0;
}
