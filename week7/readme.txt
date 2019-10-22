教学第七周知识点梳理：
分类：系统I/O、标准I/O库
系统I/O：不带缓冲的I/O（即缓冲建立管理均需用户完成）
标准I/O库：带缓冲的I/O


系统I/O
	函数：create()、read（）、write()、open()
	由OS内核提供的，供用户使用
	调用系统I/O，即访管指令。--------

	可以范文任何类型的文件
	程序中出现相应函数，则立即发生I/O操作，速度快
	效率低、速度快

标准I/O库
	对系统I/O的封装
	运行在用户态
	程序中的包含相关函数不会立即执行I/O，仅当缓冲满足一些特殊条件才批量I/O，满了则批量I/O
	效率高、速度慢




两者之间的差别和关系
	系统IO——>posix
	标准IO（语言）C标准


标准I/O定义
	struct FILE{
	//中间使用到了结构体如何定义面向对象的类
	char buf[];  //缓冲区
	int fd;  //文件描述符
	int opsition;	//文件指针位置
	(File*)(*fopen)(const char*path,option);//函数指针实现类
	}

标准I/O设定：
	缓冲类型：全缓冲、行缓冲、无缓冲（类似于OS的系统I/O方式使用文件（立即））
	标准I/O（ms)不直接读/写外设，而是使用内存中的缓冲ns级，只当缓冲满足特定条件时才会访问外设进行I/O
	

标准I/O中默认缓冲类型
	全缓冲->缓冲慢
	行缓冲->遇到行结束符   段缓冲实则不存在，是特殊的行缓冲
	fflush()  冲刷
	fclose  隐藏有fflush()
	进程结束符
	

C-标准IO库函数
	fgetc函数从任意文件流中读取一个字符
	getc 宏编译
	仅能从stdin中获取一个字符getchar

	fputc
	putc
	putchar

	fprintf向任意文件流中输出
	sprintf向字符数组中输出
	printf向stdout中输出


	scanf
	fscanf
	sscanf
	fgets向文件流里面输入n个字符  推荐使用

系统IO和用户标准IO之间的对比


全缓冲
	
	
	
	











































