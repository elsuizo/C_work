/* -------------------------------------------------------------------------
@file 1-6.c

@date 04/29/17 10:16:09
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

Verify that the expression `getchar() != EOF is 0 or 1`

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
   int result = (getchar() != EOF);
   switch(result) {
      case 0:
         {
            printf("es 0!!!");
         }break;
      case 1:
         {
            printf("es 1!!!");
         }break;
      default:
         {
            printf("no es ninguno de los dos!!!");
         }
   }
   return 0;
}


