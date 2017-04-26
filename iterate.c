/* -------------------------------------------------------------------------
@file iterate.c

@date 04/05/17 00:51:35
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Iterate over string
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
   /* pointer to char */
   char* data = "aaalaalla";
   while (*data++) {
      printf("%c\n", *data);
   }
   return 0;

}



