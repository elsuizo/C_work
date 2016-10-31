/* -------------------------------------------------------------------------
@file array_of_function_pointers.c

@date 10/31/16 16:44:07
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
int (*operations[128])(int, int) = {NULL};

void initializeOperationsArray(){
   operations['+'] = add;
   operations['-'] = substract;
}

int evaluateOperationsArray(char opcode, int num1, int num2){
   fptrOperation operation;
   operation = operations[opcode];
   return operation(num1, num2);
}

int compute(fptrOperation operation, int num1, int num2){
   return operation(num1, num2);
}



int main(void)
{
   initializeOperationsArray();
   printf("suma:%d\n", evaluateOperationsArray('+', 3,7));
   printf("resta:%d\n", evaluateOperationsArray('-', 7, 3));
   return 0;
}

