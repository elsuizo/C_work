/* -------------------------------------------------------------------------
@file input2output.c

@date 04/13/17 20:19:23
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
#include <stdlib.h>

int main(int argc, char* argv[])
{
   if (argc == 1) {
      printf("you must supply a filename to read's\n");
      exit(1);
   }
   char* input = argv[1];
   int c = atoi(input);
   while ((c = getchar()) != EOF) {
      putchar(c);
   }
   printf("el numero que has ingresado %d\n", c);
   return 0;
}

