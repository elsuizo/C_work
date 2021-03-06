/* -------------------------------------------------------------------------
@file pointer_function_as_parameter.c

@date 10/31/16 13:53:01
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

int add(int num1, int num2){
   return num1 + num2;
}

int substract(int num1, int num2){
   return num1 - num2;
}

/* pointer function alias */
typedef int (*fptrOperation)(int, int);

int compute(fptrOperation operation, int num1, int num2){
   return operation(num1, num2);
}

int main(void)
{
   printf("suma:%d\n", compute(add, 3,7));
   printf("resta:%d\n", compute(substract, 7, 3));
   return 0;
}

