#include <dlfcn.h>
#include "dylib.h"
#define LIB_CACULATE_PATH "../dynamiclib/libdylib.so"


int main(int argc,char **argv){
	void *hd;
	void (*f1)(),(*f2)();
	int (*f3)(),(*f4)();
	int a[10];
	char *error;
	
	hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd){
	fprintf(stderr,"%s",dlerror());
	exit(1);
	}
	f1=dlsym(hd,"initArray");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
	exit(1);
	}
	f2=dlsym(hd,"showArray");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
	exit(1);
	}
	f3=dlsym(hd,"max");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
	exit(1);
	}
	f4=dlsym(hd,"sum");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
	exit(1);
	}
	f1(a,10);
	f2(a,10);
	printf("Max is %4d\n",f3(a,10));
	printf("Sum is %4d\n",f4(a,10));
	if(dlclose(hd)<0){
	fprintf(stderr,"%s\n",dlerror());
	exit(1);
	}
	return 0;
}

