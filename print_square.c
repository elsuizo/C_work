/* -------------------------------------------------------------------------
@file print_square.c

@date 04/24/17 21:14:58
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

#define WIDTH 7
int main(void)
{
   int i, j;
   for (i = 0; i < WIDTH; i++) {
      printf("\n");
      for (j = 0; j < WIDTH; j++) {
         printf("*");
      }
   }
   return 0;
}

