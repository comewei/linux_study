#include "my.h"

#define PROMPT "DO you want terminate program"

char *prompt=PROMPT;
void ctrl_c(signo)
{
	fprintf(stderr,prompt);
}
int main()
{
	struct sigaction act;
	act.sa_handler=ctrl_c;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigaction(SIGQUIT,&act,NULL)<0)
	{
		fprintf(stderr,"Install Signal Action Error:%s\n",strerror(errno));
		exit(1);
	}
	printf("process id is %d \n0",getpid());
	while(1);
	return 0;
}
