#include "uhead.h"

void qsort1(int* a)
{
	int i=0;
	int j=0;
	int temp=0;
	for(i=0;i<100;i++)
		for(j=i+1;j<100;j++)	
			{		
				if(a[i]>a[j])
					{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
					}
			}
}
