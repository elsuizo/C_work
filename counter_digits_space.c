/* -------------------------------------------------------------------------
@file counter_digits_space.c

@date 04/13/17 21:06:44
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
counter digits, white spaces and others
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
/* NOTE(elsuizo:2017-04-22):para pasar como argumento un texto cualquier
 * debemos hacer un pipe operation como sigue:
 * cat counter_digits_space.c | ./counter_digits_space
 */

int main(void)
{
   int c, i, number_white, number_other;
   int number_digits[10];
   number_white = number_other = 0;
   for(i = 0; i < 10; ++i) {
      number_digits[i] = 0;
   }
   while((c = getchar()) != EOF) {
      if(c >= '0' && c <= '9') {
         ++number_digits[c - '0'];
      } else if (c == ' ' || c == '\n' || c == '\t') {
         ++number_white;
      } else {
         ++number_other;
      }
   }
   printf("digits:");
   for(i = 0; i < 10; ++i) {
      printf(" %d", number_digits[i]);
   }
   printf(", white spaces = %d, other = %d\n", number_white, number_other);

   return 0;
}



