信号：
	





1-31  不可靠、不保证信号一定送达
34-64  可靠、保证，但是不超过上限      ulimit -a

以下两种不可靠，现在改进后可靠
	signal((signa,sigfun(int))
	kill(pid,signo)

	sigaction(signo,struct void×)向用户定义的信号处理函数传递更多的信息
	raise(pidsigno)

PCB里面有一个为可处理的信号集合——分为三种：可立即处理的、可阻塞的、可屏蔽的









考试内容：
	17周考试
	1.考试程序填空题——50分
	2.考试简单题——30分
	3.考试填空——20分
