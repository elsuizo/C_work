/* -------------------------------------------------------------------------
@file nested_function_and_func_pointers.c

@date 10/26/16 23:25:24
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Ejemplo loco que no conocia de C
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
#include "stdio.h"

void* adder(int number)
{
    int add(int value) { return value + number; }
    return &add; // & operator is optional here because the name of a function in C is a pointer pointing on itself
}

int main(void) {
    int (*add20)(int) = adder(20);
    printf("%d\n", add20(3));
    return 0;
}

