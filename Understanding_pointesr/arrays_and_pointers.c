/* -------------------------------------------------------------------------
@file arrays_and_pointers.c

@date 11/17/16 13:45:10
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

int main(void)
{
   int vec[3] = {1, 2, 3};
   printf("La direccion de memoria del primer elemento es:%p\n", vec);
   printf("La direccion de memoria del primer elemento es:%p\n", &vec[0]);
   return 0;
}


