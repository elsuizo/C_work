/* -------------------------------------------------------------------------
@file bool_test.c

@date 04/24/17 20:47:02
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Si asigno un int a una expresion booleana siempre obtengo on cero o un 1???
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
   int a = 0;
   int b = 7;
   int c = 1;
   c = (a == b);
   printf("c:%d", c);
   return 0;
}


