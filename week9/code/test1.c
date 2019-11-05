#include "my.h"

int main(int argc,char *argv[])
{
	int i;
	printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
	
	for(i=0;i<argc;i++)
	{
	printf("test1:	%d:argv=%s\n",i,argv[i]);
}
	 return 0;
}
