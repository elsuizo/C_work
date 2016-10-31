/* -------------------------------------------------------------------------
@file show_pointer_value_consistently.c

@date 10/28/16 12:03:51
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Para mostrar el valor de un puntero(o sea a que direccion de memoria apunta)
y que sea robusto al cambio de compiladores
y hardware se usa castear a void
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
   int my_number = 37;
   int* iptr = &my_number;
   /* el %p se usa para mostrar direcciones de memoria */
   /* el %x se usa para mostrar valores en hexa */
   printf("La direccion de memoria de my_number es:%p\n",(void*)iptr);
   printf("El valor de my_number es:%d\n", *iptr);
   *iptr = 73;
   printf("El valor de my_number es:%d\n", *iptr);
}

