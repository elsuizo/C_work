/* -------------------------------------------------------------------------
@file array_of_function_pointers2.c

@date 11/17/16 16:47:04
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
int main(void)
{
   int vec[3] = {10, 2, 3};
   int* ptr_v = vec;
   int value = 7;

   for (int i = 0; i < 5; i++) {
      *ptr_v++ *= value;
   }

   for (int i = 0; i < ARRAY_SIZE(vec); i++) {
      printf("%d\n",vec[i]);
   }
   return 0;
}



