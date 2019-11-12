#include <stdio.h>

#include <stdlib.h>

 

int main()

{

int pid;

int status;

 

if((pid = fork()) < 0)

{

perror("Fail to fork");

exit(-1);

}else if(pid == 0){

printf("create child process : %d.\n",getpid());

printf("child process : %d calling exit(7).\n",getpid());

exit(7);

}else{

 

if((pid = fork()) < 0 ){

perror("Fail to fork");

exit(-1);

}else if(pid == 0){

printf("create child process : %d.\n",getpid());

while(1);

}else{

 

while((pid = wait(&status)) != -1)

{

if(WIFEXITED(status))

{

printf("child process %d is normal exit,the value is %d.\n",pid,WEXITSTATUS(status));

 

}else if(WIFSIGNALED(status)){

printf("child process %d is exit by signal,the signal num is %d.\n",pid,WTERMSIG(status));

}else{

printf("Not know.\n");

}

}

}

}

 

printf("All child process is exit,father is exit.\n");

exit(0);

}


