#include "staticlib.h"

void initArray(int *a,int n)
{
	int i=0;
   srand((unsigned)time(0));
   for(i=0;i<n;i++){
   a[i]=(int)1000.0*rand()/(1000+1.0);
}
}

void showArray(int *a,int n)
{
   int i=0;
	for(i;i<n;i++)
	{
	printf("%4d : %4d\n",i,a[i]);
	}
}

