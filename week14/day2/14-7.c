#include "my.h"

void* fun (void *arg)
{	
	struct sendval *k=(struct sendval *)arg;
	int i=0;
	int sum=0;
	for(i;i<k->s;i++)
	{
		sum+=i;
	}
	//int TID=pthread_self();
	printf("worker-----%d,sum is %d:pthread_self return  %p\n",k->n,sum,(void*)pthread_self());//返回线程值
	
	pthread_exit(NULL);
	return NULL;
}
int main()
{
	pthread_t tid[NUM];
	int ret[NUM];
	struct sendval d;
	int i;
	for(i=0;i<NUM;i++)
	{
	d.n=i;
	d.s=100*(i+1);
	ret[i]=pthread_create(&tid[i],NULL,fun,(void*)&d);
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
