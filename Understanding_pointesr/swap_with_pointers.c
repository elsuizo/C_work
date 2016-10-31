/* -------------------------------------------------------------------------
@file swap_with_pointers.c

@date 10/31/16 02:09:39
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

void swap_with_pointers(int* ptr_iNum1, int* ptr_iNum2);

int main(void)
{
   int n1 = 3;
   int n2 = 7;
   printf("number1:%d , number2:%d\n", n1, n2);
   swap_with_pointers(&n1, &n2);
   printf("number1:%d , number2:%d\n", n1, n2);

   return 0;
}

void swap_with_pointers(int* ptr_iNum1, int* ptr_iNum2){
   int temp;
   temp        =  *ptr_iNum1;
   *ptr_iNum1  =  *ptr_iNum2;
   *ptr_iNum2  =  temp;
}

