/* -------------------------------------------------------------------------
@file function_pointers.c

@date 10/31/16 13:40:05
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
#include "utils.h"
#include <stdlib.h>


int square(int n){
   return n*n;
}
int main(void)
{
   int (*fptr1)(int);
   int n = 7;
   fptr1 = square;
   printf("%d al cuadrado es:%d\n", n, fptr1(n));
   return 0;
}

