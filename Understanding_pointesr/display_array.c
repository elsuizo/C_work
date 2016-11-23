/* -------------------------------------------------------------------------
@file display_array.c

@date 11/18/16 21:08:18
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

void display_array(int array[], int size);
void display_array2(int* array, int size);

int main(void)
{
   int vector[] = {1, 2, 3, 7, 2, 1, 2,7};
   display_array2(vector, (int)ARRAY_SIZE(vector));
   //display_array(vector, (int)ARRAY_SIZE(vector));
   return 0;
}

void display_array(int array[], int size){
   for (int i = 0; i < size; i++) {
      printf("element:%d --> value:%d\n", i, array[i]);
   }
}

void display_array2(int* array, int size){
   for (int i = 0; i < size; i++) {
      printf("element:%d --> value:%d\n", i, array[i]);
   }
}
