#!bin/bash
gcc -shared -o libtest.so -fPIC test.o
export LD_PRELOAD=./libtest.so:$LD_LIBRARY_PATH
