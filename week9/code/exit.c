#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	FILE *fp;
	char buf[]="hello world\n";
	if((fp=fopen("exit.txt","w"))==NULL)
	{
	perror("fail to fopen");
	return -1;	
	}
	if(fputs(buf,fp)==EOF)
	{
	perror("fail to puts");
	}
	exit(0);
	return 0;
}
