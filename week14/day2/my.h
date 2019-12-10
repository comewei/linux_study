#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <limits.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#define NUM 4


 struct sendval
{
	int n;
	int s;
};
