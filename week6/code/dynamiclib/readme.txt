一、运行时动态链接
1.动态编译
gcc -o ldtextlocal ldtextlocal.c ./libdylib.so

2.在上一次目录建立exam文件夹，
mkdir exam
cd exam
cp  ../dylib/ld*  ./复制文件到当前目录

gcc   ldtextremote -o  dytestremote.c  ../dynamiclib/libdylib.so -I ../dynamiclib 


二、装载时动态链接
dytestrt.c
		应该加入#include <dlfcn.h>
		加入函数指针	void *hd; void (*f1)();	int (*f2)(),(*f3)();
		hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);//LAZY不运行不加载
		一定要加入if判读语句
		if(!hd){ fprintf("stderr,"%s\n",dlerror());
			exit(1);
			}
			f1=dlsym(hd,"show");判断
			f2=dlsym(hd,"");
			f3=dlsym(hd,"show");
			f1(a,5);


链接的形式
	 gcc -rdynamic -o rttest  dytestrt.c  -ldl -I ../dynamiclib

cat 查看文件内容
