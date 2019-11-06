#include "my.h"
static void __attribute__((constructor)) before_main()
{
	printf("------Before Main!\n");
}
static void __attribute__((destructor)) after_main()//before，after main函数不一定知道，存在一定的危险性
{
	printf("------After Main!\n");
}
//回调函数，main函数是知道的
static void callback1(void)
{
	printf("----------callback1-----------\n");
}

static void callback2(void)
{
	printf("----------callback2-----------\n");
}

static void callback3(void)
{
	printf("----------callback3-----------\n");
}
int main(void)
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("\n");
	while(1);
	return 0;
}
