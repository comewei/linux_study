#include "my.h"


void urand(int *a,int n){
   int i=0;
   srand((unsigned)time(0));
   for(i=0;i<n;i++){
   a[i]=(int)1000.0*rand()/(RAND_MAX+1.0);
   }
}

