


线程——>私有栈
可共享——>代码、全局（data,bss,stack)


线程在不同系统环境中不同的执行轨迹

windows——>派生进程慢
Linux/Unix——>进程派生慢


在linux里面，线程分为两种线程
	内核线程——>kthread——create		后台、内核函数
	用户线程——>pthread——>create    （clone)


	gcc 14-1.c -o 14-1 -lpthread

线程中不存在父子关系



14-6.c 14-7.c中的顺序要一致
