#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

char buf[]={"write to stdout\n"};
int main(){
	pid_t id;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		perror("can'write");
	printf("printf       ");
	id=fork();
	if(id<0)
	perror("fork error");
	if(id=0)
	printf("son I am your father");
	exit(0);
}
