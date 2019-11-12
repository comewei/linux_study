#include<stdio.h>
int main(int argc,char *chgv[],char *env[])
{
	extern char **environ;
	int i=0;
	while(NULL!=environ[i])
{
	printf("%s\n",environ[i]);
	i++;
}
	return 0;
}
