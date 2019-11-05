#include "my.h"

int main(int argc,char* argv[])
{
	char *arg[]={"./test1","abc","123","234",NULL};
	printf("caller 3 pid =%d, ppid =%d\n",getpid(),getppid());
	execlp("test1","abc","123","234",NULL);
	printf("execl after calling!\n");
	return 0;
}
