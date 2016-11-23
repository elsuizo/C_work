/* -------------------------------------------------------------------------
@file matrix.c

@date 11/19/16 17:31:34
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
   int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
   for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 5; j++) {
         printf("matrix[%d][%d] Adress:%p --> Value:%d\n", i, j, &matrix[i][j] ,matrix[i][j]);
      }
   }
   return 0;
}

