#include "my.h"
int main()
{
	pid_t pid1,pid2,pid3;
	int fd[2];
	char rbuf[65537],wbuf[65537];
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(wbuf));
	pipe(fd);
	printf("parent fork child1！\n");
	pid1=fork();
	if(pid1<0)	
		{
			perror("pid1 fork failed");
			return -1;
		}
	else if(pid1==0)
		{
			close(fd[0]);
			printf("[child1 %d]\t[parent %d]\n",getpid(),getppid());
			sprintf(rbuf,"1");
			for(int i=0;i<65536;i++)
			write(fd[1],rbuf,sizeof(rbuf));	
			close(fd[1]);
			exit(0);
		}
	else
	{
		printf("parent fork child2!\n");
		pid2=fork();
		if(pid2<0)
			{
				perror("pid2 fork failed");
				return -1;
			}
		else if(pid2==0)
			{
			close(fd[1]);
			printf("[child1 %d]\t[parent %d]\n",getpid(),getppid());
			sprintf(rbuf,"1");
			for(int i=0;i<65536;i++)
			{	
			if(read(fd[0],rbuf,sizeof(rbuf))==0)
			{
				printf("[parent] read error\n");
				break;
			}			
			}
			close(fd[0]);
			exit(0);
			}
		else
		{
			printf("parent fork child3!\n");
			pid3=fork();
			if(pid3<0)
			{
				perror("pid3 fork failed");
				return -1;			
			}	
			else if(pid3==0)
			{
				exit(0);
			}	
			else
			{
				return 0;
			}			
		}
	}
}











