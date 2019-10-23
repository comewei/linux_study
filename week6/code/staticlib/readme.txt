gcc -c aoperand.c base.c 
ar -rc libstatic.a  base.o  aoperand.o
gcc localtest.c -o localtest -L . -lstatic
./localtest 
gcc remotetest.c  -o remotetest1 -L..//staticlib  -lstatic  -I../staticlib/
./remotetest1 

