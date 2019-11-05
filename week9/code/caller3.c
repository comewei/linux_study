#include "my.h"

int main(int argc,char* argv[])
{
	printf("caller 3 pid =%d, ppid =%d\n",getpid(),getppid());
	execl("/home/rlk/linuxprogram/week9/code/test1","./test1","abc","123","234",NULL);
	printf("execl after calling!\n");
	return 0;
}
