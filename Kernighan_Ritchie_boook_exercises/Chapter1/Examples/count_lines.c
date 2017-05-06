/* -------------------------------------------------------------------------
@file count_lines.c

@date 04/29/17 10:48:49
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Exaple: count the number of lines in a text stream. pag:19
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
   char c;
   long number_of_lines = 0;

   while ((c = getchar()) != EOF) {
      if (c == '\n') {
         ++number_of_lines;
      }
   }
   printf("The number of line in the text stream is: %ld", number_of_lines);
   return 0;
}
