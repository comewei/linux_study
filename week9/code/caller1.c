#include "my.h"

int main(int argc,char * argv[])
{
	int ret;
	printf("caller1:pid=%d	ppid=%d\n",getpid(),getppid());
	ret=system("./test1 123 456 hello world");
	printf("After calling!\n");
	printf("ret =%d\n",ret);
	sleep(100);
	return 0;

}
