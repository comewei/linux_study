#include "my.h"

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t rwlock;//设置读写锁，读者写者问题


#define n 1000

int a[n]={0};
int b[n]={0};

bool cmp(int a,int b)
{
	return a>b;
}


int gn=0;

void *fun(void *par)//
{
	int i;
	pthread_rwlock_rdlock(&rwlock);//读锁
	for(i=0;i<LOOP;i++)
	{
		pthread_mutex_lock(&mutex);
		gn++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_rwlock_unlock(&rwlock);//解锁
	return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int i,ret;
	ret=pthread_rwlock_init(&rwlock,NULL);
	if(ret)
	{
	perror("rwlock init failed!\n");
		//fprintf(stderr,"init rw lock failed %s\n",strerror_r(ret,err,sizeof(err)));
	exit(1);	
	}
	pthread_rwlock_wrlock(&rwlock);//自己加上写锁


	srand(a,n);
	srand(b,n);

	sort(a,a+1000,*cmp);
	sort(b,b+1000,*cmp);





	for(i=0;i<NUM;i++)
	{
		ret=pthread_create(&tid[i],NULL,fun,NULL);
		if(ret!=0)
			{
				perror("create failed");
				exit(2);		
			}
	
	}
	pthread_rwlock_unlock(&rwlock);
	for(i=0;i<NUM;i++)
	pthread_join(tid[i],NULL);
	pthread_rwlock_destroy(&rwlock);
	printf("thread number------------	:%d\n",NUM);
	printf("loop per thread----------	:%d\n",LOOP);
	printf("expect result----------	:%d\n",LOOP*NUM);
	printf("actual result  --------   :%d\n",gn);
	return 0;
}







