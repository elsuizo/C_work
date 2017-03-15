/* -------------------------------------------------------------------------
@file erf.c

@date 03/14/17 22:17:12
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Ejemplo del uso de funciones de la libreria math
para compilar tenemos que hacer uso de el flag -lm, osea:
gcc erf.c -o erf -lm -g -Wall -03 -std=gnu11
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
#include<math.h>
#include<stdio.h>

int main(void)
{
   printf("The integral of Normal(0,1) distribution between -1.96 and1.96 is: %g\n", erf(1.96 * sqrt(1/2.)));
   return 0;
}



