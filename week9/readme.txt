在内核中查看kelnel
cat /proc/sys/kernel/pid_max
sysctl kernel.pid_max
cat pid_max  同时运行进程的个数
cat /proc/sys/kernel/threads_max
cat threads-max  同时运行的线程个数

sudo sysctl -w kernel.pid_max=4194304  	求改运行进程个数
运行test1.c 和  caller1.c 程序


env 2>err.dat


子进程和父进程运行顺序和调度算法有关
