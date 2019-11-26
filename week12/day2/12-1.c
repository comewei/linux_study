#include "my.h"
/*
	pipe(fd);fd[0]读、fd[1]写
	生产消费者模型

*/








int main()
{
	pid_t p;
	int fd[2],rn,wn;
	char rbuf[20],wbuf[20];
	memset(rbuf,0,sizeof(rbuf));
	memset(wbuf,0,sizeof(wbuf));
	pipe(fd);
	p=fork();
	if(p<0)
	{
		perror("fork failed");
	}
	else if(p==0)
	{
		close(fd[0]);
		sprintf(rbuf,"[child %d] is running .\n",getpid());	
		while(1)
		{
			wn=write(fd[1],wbuf,sizeof(wbuf));
			printf("[child] write to pipe %d byte.\n",wn);
			if(wn==-1)
				{
					//perror("write error");
					printf("[child] write error.\n");
					break;
				}
		}
			close(fd[1]);
			exit(0);
	}
	else{
	close(fd[1]);
	while(1)
	{
		rn=read(fd[0],rbuf,sizeof(rbuf));
		printf("[parent] read from pipe %d byte. context of pipe is %s .\n",rn,rbuf);
		if(rn==0)
			{
				printf("[parent] read error\n");
				break;
			}
	
	}
	close(fd[0]);
	return 0;
	}

}














































