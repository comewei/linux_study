#include "my.h"

int g=10;

int main()
{
	int status;
	int l=20;
	static int s=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
	perror("failed to fork\n");
	return -1;
	}
	else if(pid==0)
	{
	//int p=99;
	printf("--------address of var-------\n");
	printf("child pid=%d\n&g=%16p\n&l=%16p\n&s=%16p\n",getpid(),&g,&l,&s);
	g=100;
	l=200;
	s=300;
	//p=99999;
	excel("./test3","test3","NULL");
	printf("value in child\n");
	printf("child pid=%d\ng=%d\nl=%d\ns=%d\n",getpid(),g,l,s);
	return 0;
	}
	else
	{
	//wait(&status);
	//printf("exit code form child is %d\n",WEXITSTATUS(status));
	//int p=99;
	printf("--------address of var in parent-------\n");
	printf("parent pid =%d\n&g=%16p\n&l=%16p\n&s=%16p\n",getpid(),&g,&l,&s);
	/*g=100;
	l=200;
	s=300;
	p=99999;*/
	printf("value in parent\n");
	printf("parent g=%d\nl=%d\ns=%d\n",g,l,s);
	return 0;
	}
}
