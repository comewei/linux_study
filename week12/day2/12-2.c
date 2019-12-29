#include "my.h"
/*
	pipe(fd);fd[0]读、fd[1]写
	生产消费者模型

*/








int main()
{
	pid_t p;
	int fd[2],rn,wn;
	char rbuf[65536],wbuf[4097];
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
		sprintf(rbuf,"1");
		for(int i=0;i<1;i++)
			write(fd[1],rbuf,sizeof(rbuf));	
		close(fd[1]);
		exit(0);
	}
	else{
	//wait(NULL);
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














































