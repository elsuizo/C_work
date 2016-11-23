/* -------------------------------------------------------------------------
@file arrays_with_pointers.c

@date 11/19/16 00:19:39
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
#include <string.h>
#include "utils.h"

int main(void)
{
   int* array[5];
   for(int i = 0; i < 5; i++){
         *(array + i) = (int*)malloc(sizeof(int));
         **(array + i) = i; // get the content at that address
   }
   for (int i = 0; i < 5; i++) {
      printf("%d\n", *array[i]);
   }
   for (int i = 0; i < 5; i++) {
      free(array[i]);
   }
   return 0;
}
