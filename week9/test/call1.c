#include "my.h"

int main()
{
	char *vector[]={"test4","abc","123",NULL};
	printf("call1:pid=%d,ppid=%d\n",getpid(),getppid());
	execvp("test4",vector);
	printf("----after calling----\n");
  	return 0;
}
