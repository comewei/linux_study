#include "my.h"

int arg=0;
void *foo(void *v)
{
	int *sum,i;
	int n=(int)v;
	arg++;
	sum=(int *)malloc(sizeof(int));
	for(i=0;i<(n+1)*100;i++)
	{
	*sum+=i;
	}
	printf("%d :global arg=%d\n",n,arg);
	int arg;
	arg=n*100;
	printf("%d:local arg=%d\n，sum=%d\n",n,arg,*sum);
	pthread_exit((void *)sum);

}

int main()
{
	pthread_t tid[NUM];
	int ret[NUM],**pt;
	int i;
	for(i=0;i<NUM;i++)
	{
	ret[i]=pthread_create(&tid[i],NULL,(void(*))foo,(void*)i);
	if(ret[i]!=0)
	{
	perror("create failed\n");
	return -1;	
	}
	pthread_join(tid[i],(void**)&pt);
	printf("Master %d: arg=%d,sum=%d\n`All Done\n",i,arg,*pt);
	}
	
	return 0;
}
