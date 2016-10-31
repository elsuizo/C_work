/* -------------------------------------------------------------------------
@file average_example.c

@date 10/30/16 22:51:40
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

float average(int* array, int size);

int main(void)
{
   int a[] = {1, 2, 3, 4 ,5, 6, 7};
   float result;
   int size = GET_NUM_ELEMS_ARR(a);
   result = average(a, size);
   printf("el promedio de las muestras es:%f\n", result);
   return 0;
}

float average(int* array, int size)
{
   int sum = 0;
   printf("size:%d\n", size);
   for(int i = 0; i < size; i++){
      sum += array[i];
   }
   printf("sum:%d\n", sum);

   return (sum * 1.0f) / size;
}

