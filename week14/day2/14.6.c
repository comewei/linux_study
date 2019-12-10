#include "my.h"

void* fun (void *arg)
{	
	int k=(int)arg;
	//int TID=pthread_self();
	printf("worker-----%d:pthread_self return  %p\n",k,(void*)pthread_self());//返回线程值

	pthread_exit(NULL);
	return NULL;
}
int main()
{
	pthread_t tid[NUM];
	int ret[NUM];
	int i;
	for(i=0;i<NUM;i++)
	{
	
	ret[i]=pthread_create(&tid[i],NULL,fun,(void*)i);
	if(ret[i]!=0)
	{
	perror("create failed\n");
	return -1;	
	}
	pthread_join(tid[i],NULL);
	}
	printf("Master %d:All Done\n",getpid());
	return 0;
}
