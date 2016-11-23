/* -------------------------------------------------------------------------
@file functor_test.c

@date 10/28/16 21:29:29
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
// NOTE(elsuizo): cuando compilamos con -O3 (optmizaciones) tira segmentation fault
typedef enum { false, true } bool;

void* lesser(int number)
{
   bool less_to(int value)
   {
      if(value < number)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   return &less_to;
}

int main(void)
{
   int num = 3;
   bool (*less_to_7)(int) = lesser(7);
   printf("Es %d menor que 7: %d\n", num, less_to_7(num));
   return 0;
}
