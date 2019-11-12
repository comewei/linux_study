#include <unistd.h>

 

int main(int argc,char *argv[])

{

printf("start to execle.\n");

char * const envp[] = {"B=hello",NULL};

 

if(execle("./A.out","A.out",NULL,envp) < 0)

{

perror("Fail to execl");

return -1;

}

 

printf("end of execl.\n");

 

return 0;

}
