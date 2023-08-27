#!bin/bash
gcc -shared -o libtest.so test.o
LD_PRELOAD=/$PWD/libtest.so ./gm 9 8 10 24 75 9
