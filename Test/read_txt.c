/* -------------------------------------------------------------------------
@file read_txt.c

@date 10/31/16 18:19:34
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
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* input = fopen("sample.txt", "r");
    int i, size = 10;
    int array[size];
    printf("\'hola como va\n");

    if(input != NULL){

       // This func stores the values of sample.txt into array[size]
        for(i = 0; i<size; i++){
            fscanf(input, "%d", &array[i]);
            printf("The value of %d is %d\n", i, array[i]);

        }
    }
    return 0;
}

