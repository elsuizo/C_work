#!/bin/bash
gcc -o $1 -std=c11 -O3 "./$1.c" && ./$1
#gcc -o $1 -O3 "./$1.c" && ./$1 # witout c11
