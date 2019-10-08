#include "uhead.h"

void operate(struct arg *avsum,int *a){
	int i=0;
	avsum->sum=0;
	for(i;i<100;i++){
	avsum->sum+=a[i];
}
	avsum->ave=(float)avsum->sum/RAND_MAX;
	printf("average=%f,sum=%d\n",avsum->ave,avsum->sum);
}
