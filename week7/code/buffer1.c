#include <stdio.h>

int main(int argc,char *argv[])
{	
	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello");
	while(1);
}
