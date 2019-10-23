#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
char buf[]={"write to stdout\n"};
int main(){
	pid_t id;
	File *fp;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
	perror("can'write");
	
	fp=fopen("a.txt","w");
	(FILE*)fprintf(fp,"HELLO\n");
	id=fork();
	if(id<0)
	perror("fork error");
	if(id=0)
	printf("son I am your father");
	exit(0);
}
