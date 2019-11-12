#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void callback1()
{
	printf("------callback1-------\n");
}
static void callback2()
{
	printf("------callback2-------\n");
}
static void __attribute__((constructor)) before_main(void)
{
	printf("----------before main---------\n");
}
static void __attribute__((destructor)) after_main(void)
{
	printf("----------after main---------\n");
}
int main(int argc,char *argv[])
{
	FILE *fp;
	char buf[]={"hello world"};
	atexit(callback1);
	atexit(callback2);
if((fp=fopen("test.txt","w+"))==NULL)
{
	perror("fail to create file\n");	
}
if(fputs(buf,fp)==EOF)
{
	perror("fail to fputs file\n");
}
	printf("test message!");
	//exit(0);
	//_exit(0);
	return 0;
}
