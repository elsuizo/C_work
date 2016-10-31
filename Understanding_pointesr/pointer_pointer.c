/* -------------------------------------------------------------------------
@file pointer_pointer.c

@date 10/31/16 12:27:38
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

void allocateArray(int** array, int size, int value);

int main(void)
{
   int* vector = NULL;
   int num_elem = 7;
   allocateArray(&vector, num_elem, 3);
   for (int i = 0; i < num_elem; i++) {
      printf("vector[%d]:%d\n", i, vector[i]);
   }
   free(vector);
   return 0;
}

void allocateArray(int** array, int size, int value){
   *array = (int*) malloc(size * sizeof(int));
   if(*array != NULL){
      for (int i = 0; i < size; i++) {
         *(*array + i) = value;
      }
   }
}
