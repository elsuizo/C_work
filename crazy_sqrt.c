/* -------------------------------------------------------------------------
@file crazy_sqrt.c

@date 11/30/16 01:02:28
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

float d_sqrt(float number);

int main(void)
{
   float num = 2;
   float result;
   result = d_sqrt(num);
   printf("La raiz cuadrada de:%f es:%f\n", num, result);
   return 0;
}


float d_sqrt(float number) {
   int i;
   float x, y;
   x = number * 0.5;
   y = number;
   i = *(int*) &y;
   i = 0x5f3759df - (i >> 1);
   y = *(float*) &i;
   x = y * (1.5 - (x * y * y));
   x = y * (1.5 - (x * y * y));

   return number * y;

}
