Week6课程知识点


为什么要使用库——可重定位二进制文件
  1.代码复用
  2.构成运行环境——进程一定需要库的支持
  3.封闭细节，简化使用——如果不能达到简化的目的，不建议封闭

	链接器gcc首先做动态版，然后才找静态版

静态库（简单打包）、硬盘和内存均完整
	自足（不依赖环境）
	占空间，空间换时间
	升级需要重新链接，比较麻烦。



动态库	ELF
	运行时动态链接
	装载时动态链接
	硬盘中完整，在可执行文件中仅有一条关于动态库的路径
	在装入内存时，临时加载。

	

	dlopen——>HD映像入内存，handle——>库文件的基址
	dlsym——>HD+函数名


	映射区中先映射吗？







