/* -------------------------------------------------------------------------
@file pointer_arrays.c

@date 11/18/16 13:24:43
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
#include "utils.h"

int main(void)
{
   int num_elem = 5;
   int* ptr_vi = (int*)malloc(num_elem * sizeof(int));
   for (int i = 0; i < num_elem; i++) {
      ptr_vi[i] = i + 1;
   }
   PRINT_ARRAY(ptr_vi, num_elem);
   free(ptr_vi);
   return 0;
}


