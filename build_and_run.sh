#!/bin/bash
gcc -o $1 -std=c11 "./$1.c" && ./$1
#clang-3.8 -o $1 -std=c11 "./$1.c" && ./$1 # con esto tampoco compila
