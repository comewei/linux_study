#include<stdio.h>
int main(int argc,char *chgv[],char *env[])
{
	extern char **environ;
	int i=0;
	for(;env[i];i++)
{
	printf("%s\n",environ[i]);
	
}
	return 0;
}
