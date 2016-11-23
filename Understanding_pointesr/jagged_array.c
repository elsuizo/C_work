/* -------------------------------------------------------------------------
@file jagged_array.c

@date 11/21/16 17:26:48
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

int main(void)
{
   int (*(array1[])) = {
   (int[]){0, 1, 2},
   (int[]){3, 1},
   (int[]){6, 7, 8},
   };
   /* display the arra */
   for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 3; i++) {
         printf("array1:[%d][%d] --> Adress:%p --> Value:%d\n", j, i, &array1[j][i], array1[j][i]);
      }
      printf("\n");
   }
   return 0;
}

