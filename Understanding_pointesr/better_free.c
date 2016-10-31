/* -------------------------------------------------------------------------
@file better_free.c

@date 10/31/16 12:43:58
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
#include "utils.h"
#include <stdlib.h>


void safer_free(void** pp);

int main(void)
{
   int* ptr_i;
   ptr_i = (int*) malloc(sizeof(int));
   *ptr_i = 7;
   printf("Antes de safer_free ptr_i:%p\n", ptr_i);
   safeFree(ptr_i);
   printf("Despues de safer_free ptr_i:%p\n", ptr_i);
   //safeFree(ptr_i);
   return 0;
}

void safer_free(void** pp){
   if(*pp != NULL && pp != NULL){
      free(*pp);
      *pp = NULL;
   }
}
