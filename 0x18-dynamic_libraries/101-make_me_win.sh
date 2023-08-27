#!bin/bash
gcc -shared -o libtest.so -fPIC test.c
export LD_PRELOAD=./libtest.so:$LD_LIBRARY_PATH
