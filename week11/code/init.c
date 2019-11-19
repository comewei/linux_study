#include "my.h"

void init_daemon(void)
{
	pid_t child1,child2;
	int i;
	child1=fork();
	if(child1>0)
	{
	exit(0);
	}
	else if(child1<0)
	{
	perror("make the process of children child");
	exit(1);	
	}
	setsid();
	chdir("/tmp");
	umask(0);
	for(i=0;i<NOFILE;++i)
	close(i);
	return;
}
