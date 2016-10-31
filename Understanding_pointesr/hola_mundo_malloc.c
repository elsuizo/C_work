/* -------------------------------------------------------------------------
@file hola_mundo_malloc.c

@date 10/30/16 15:40:45
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define printf_dec_format(x) _Generic((x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")

#define print(x) printf(printf_dec_format(x), x)
#define printnl(x) printf(printf_dec_format(x), x), printf("\n");

int main(void)
{
   /* un error comun es declarar asi:
    * int* pi;
    * *pi = (int*)malloc(sizeof(int));
    * */
   int* ptr_i = (int*)malloc(sizeof(int)); // allocate memory for a int i the heap
   ptr_i != NULL ? *ptr_i = 5 : printnl("Error the memory dont allocate");
   printf("*ptr_i: %d\n", *ptr_i);
   /* for every malloc one free!!! */
   free(ptr_i); // liberamos la memoria
   return 0;
}
