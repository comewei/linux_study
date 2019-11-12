#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int pid;
	if((pid=fork())<0)
	{
	perror("Fail to fork");	
	return -1;
	}
	else if(pid==0)
	{
	printf("child exit now.\n");
	}
	else{
	while(1);
	}
	return 0;
}
