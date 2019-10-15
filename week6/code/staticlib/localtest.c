#include "staticlib.h"

int main()
{	int a[10];
	initArray(a,10);
	showArray(a,10);
	printf("Max is %4d\n",max(a,10));
	printf("Sum is %4d\n",sum(a,10));
	return 0;
}
