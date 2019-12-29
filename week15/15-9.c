#include "my.h"

int tickets=100;

sem_t empty,full;
pthread_mutex_t mutex;
void *worker0(void *arg)
{
  while(1)
  {
     pthread_mutex_lock(&mutex);
	     
	if(tickets>0)
     {
        //usleep(1000);
        printf("worker0 read ticket:%d\n",tickets--);
		sem_post(&full);//相当于v原语        
	//pthread_mutex_unlock(&mutex);
     }
     else
     {
        sem_post(&full);
        break;
     }
     
  }
  return NULL;
}

void *worker1(void *arg)
{
  //pthread_mutex_lock(&mutex);
	sem_wait(&full);  
	while(1)
  {
     if(tickets>0)
     {
       
        printf("worker1 read ticket:%d\n",tickets--);
		sem_post(&empty);
        
     }
     else
     {
        sem_post(&empty);
        break;
     }
    
  }
  return NULL;
}


int main()
{
   pthread_t tid[2];
   int i,ret;
   void *(*pt[2])();
        pt[0]=worker0;
        pt[1]=worker1;
	ret=sem_init(&empty,0,1);
	ret=sem_init(&full,0,0);//同步信号量
   for(i=0;i<2;i++)
   {
      ret=pthread_create(&tid[i],NULL,pt[i],NULL);
      if(ret!=0)
      {
         perror("create thread!\n");
         exit(1);
      }
   }
   for(i=0;i<2;i++)
   {
      pthread_join(tid[i],NULL);    
   }
   return 0;
}


