#include "uhead.h"

void operate(struct arg *avsum){
	FILE *fp;
	int i=0;
	int a[100]={0};
	fp=fopen("a.txt","r");
	for(i=0;i<100;i++)
	{
			fscanf(fp,"%d",&a[i]);
	}
	
	avsum->sum=0;
	for(i=0;i<100;i++){
	avsum->sum+=a[i];
	}
	avsum->ave=(float)avsum->sum/RAND_MAX;
	printf("average=%f,sum=%d\n",avsum->ave,avsum->sum);
}
