/* -------------------------------------------------------------------------
@file pointers_and_vectors.c

@date 10/28/16 16:06:02
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

int main()
{
   char vector[] = {37, 73, 77};
   char* ptr_i = vector; // point to the first element
   printf("%d\n", *ptr_i);
   ptr_i += 1;
   printf("%d\n", *ptr_i);
   ptr_i += 1;
   printf("%d\n", *ptr_i);

}


