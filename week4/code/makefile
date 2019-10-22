rand:	main.o fun2.o fun1.o  qsort.o
	gcc	main.o fun2.o fun1.o qsort.o -o rand8
main.o:main.c
	gcc	main.c -c
fun2.o:fun2.c
	gcc	fun2.c -c
fun1.o:fun1.c
	gcc	fun1.c -c
qsort.o:qsort.c
	gcc qsort.c -c
clean:
	rm	-f  *.o
