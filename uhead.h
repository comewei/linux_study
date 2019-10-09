#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define RAND_MAXs 1000
struct arg{
	float ave;
	int sum;
};


void show(int *a,int n);
void urand(int *a,int n);
void operate(struct arg * avsum);
void qsort1(int* a);


