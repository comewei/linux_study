共享资源：宏观上共享，微观上互斥

 通信（互斥）
	数据传输——字节流、消息——实际上是结构体
		字节流包括管道、命名管道、流式套接字（UNIX)		消息包括SystemV消息队列、POSIX消息队列、数据报套接字
	共享内存
		SystemV共享内存、内存映射mmap（文件映射、匿名映射）、POSIX共享内存



 同步
	文件锁（文件锁flock、记录锁fcntl）
	信号量（SystemV 信号量、POSIX信号量（有名、无名））
	eventfd事件
	与线程相关的（互斥量、条件变量、读/写锁）



   星期三：
进程<——>共享<——>进程

     文件  外设、速度慢
	内核缓冲区
	ELF文件
	
	操作系统三大特性：多道、共享、异步

	同步机制——互斥（排它、独占使用的资源）
	同步——（有序排它使用逻辑）

