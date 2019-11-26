#include "my.h"

int main()
{
	pid_t pid1,pid2,pid3;
	int status,rv;
	pid1=fork();
	FILE *fp;
	char num[]={'0','1','2','3','4','5','6','7','8','9'};
	fp=fopen("out.dat","w+");
	fwrite(num,sizeof(num),1,fp);
	if(pid1<0)
	{
	perror("failed to fork!");
	return -1;
	}
	//fwrite(fp,"a.txt");
	
	else if(pid1==0)
	{
	fwrite(num,sizeof(num),1,fp);
	printf("child1	pid=%d\n",getpid());
	sleep(3);
	exit(18);
	}	
	else{
	printf("parent fork child2!\n");
	pid2=fork();
	if(pid2<0)
	{
	perror("2:failed to fork");
	return -1;	
	}
	else if(pid2==0)
	{
	fwrite(num,sizeof(num),1,fp);
	//pid2=fork();
	printf("child2	pid=%d\n",getpid());
	sleep(5);
	exit(99);
	}
	else{
	printf("parent fork child3!\n");
	pid3=fork();
	if(pid3<0)
	{
	perror("3:failed to fork!");
	return -1;
	}
	else if(pid3==0)
	{
	fwrite(num,sizeof(num),1,fp);
	printf("child3	pid=%d\n",getpid());
	sleep(2);
	exit(108);
	}

	else
	{
	fwrite(num,sizeof(num),1,fp);
	printf("parent waiting child end!\n");	
	rv=wait(&status);
	printf("1:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
	rv=0;
	status=0;
	rv=waitpid(pid1,&status,0);
	printf("2:child %d ends.exit code is %d\n",rv,WEXITSTATUS(status));
	rv=0;
	status=0;
	rv=waitpid(pid2,&status,WNOHANG);
	printf("3:child %d end.exit code is %d\n",rv,WEXITSTATUS(status));
	return 0;
	}
	}
}
}
