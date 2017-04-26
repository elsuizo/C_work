/* -------------------------------------------------------------------------
@file matrix_test.c

@date 04/12/17 13:00:15
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

int main(void)
{
   int matrix[3][3];
   for (int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
         matrix[i][j] = rand() % 10;
      }
   }
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
         printf("matrix[%d][%d] = %d\n", i , j, matrix[i][j]);
      }
   }
   return 0;
}
