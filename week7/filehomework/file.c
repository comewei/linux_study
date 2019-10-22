#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n=9;
printf("**********************\n");
printf("0.退出\n");
printf("1.退出\n");
printf("2.退出\n");
printf("3.退出\n");
printf("4.退出\n");
printf("5.退出\n");
printf("***********************");
printf("Please input your choice(0-5):	");
scanf("%d",&n);
switch(n){
	case 0: exit(0);
	case 1:system("bin/ls");break;
	case 2:break;
	case 3:break;
	case 4:break;
	case 5:break;
}
}
