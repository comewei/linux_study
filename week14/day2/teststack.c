#include "my.h"
int i=0;
void func()
{
	int buffer[256];
	printf("%d\n",i);
	i++;
	func();
}

int main()
{
	func();
	sleep(10);
	return 0;
}
