#include "uhead.h"
int main()
{
   int a[100];
	long begin,end;
	struct arg avsum;
   urand(a,100);
   show(a,100);
   operate(&avsum,a);
	begin=clock();
	qsort1(&a);
	end=clock();
	show(a,100);
	printf("%lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}
