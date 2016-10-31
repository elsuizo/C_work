/* -------------------------------------------------------------------------
@file char_names.c

@date 10/28/16 00:36:01
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Diferentes formas de acceder a un vector de chars
Esto quiere demostrar que no siempre la manera mas complicada 
es la que mejor se entiende
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
   char* names[] = {"Martin", "Alejandro", "Noblia"};
   printf("%c\n", names[2][0]);
   printf("%c\n", *(*(names + 1) + 2));
   return 0;
}



