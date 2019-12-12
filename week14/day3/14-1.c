#include "my.h"

int arg=0;
void foo(void *v)
{
	int n=(int)v;
	arg++;
	printf("%d :global arg=%d\n",n,arg);
	int arg;
	arg=n*100;
	printf("%d:local arg=%d\n",n,arg);

}

int main()
{
	pthread_t tid[NUM];
	int ret[NUM];
	int i;
	for(i=0;i<NUM;i++)
	{
	ret[i]=pthread_create(&tid[i],NULL,(void *(*)())foo,(void*)i);
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
