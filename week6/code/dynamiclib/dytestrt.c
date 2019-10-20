#include <dlfcn.h>

#define LIB_CACULATE_PATH "./lib.so"


int main(int argc,char **argv){
	void *handle;
	void *hd;
	char *error;
	void (*f1)();
	int (*f2)(),(*f3)();
	hd=dlopen(LIB_CACULATE_PATH,RTLD_LAZY);
	if(!hd){
	fprintf(stderr,"%s",dlerror());
	exit(1);
	}
	dlerror();
	f1=dlsym(hd,"show");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",error);
	exit(1);
	}
	dlclose(hd);
	exit(0);
}
#include "dylib.h"

int main()
{	int a[10];
	initArray(a,10);
	showArray(a,10);
	printf("Max is %4d\n",max(a,10));
	printf("Sum is %4d\n",sum(a,10));
	return 0;
}
