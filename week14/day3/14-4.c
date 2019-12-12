#include "my.h"

void *foo(void *arg)
{
	printf("thread is runing !\n");
	return (void*)0;
}

int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,foo,NULL);
	if(ret)
	{
	perror("create failed");
	exit(1);
	}
	//ret=pthread_join(tid,NULL);
	pthread_detach(tid);
	printf("Master done!!!\n");	
	sleep(5);
	
	return 0;
}

