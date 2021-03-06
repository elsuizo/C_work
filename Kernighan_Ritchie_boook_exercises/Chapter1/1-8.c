/* -------------------------------------------------------------------------
@file 1-8.c

@date 04/19/17 21:53:53
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
 Write a program to count blancks, tabs, and newlines
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
   int c;
   long number_of_blanks = 0;
   long number_of_tabs = 0;
   long number_of_new_lines = 0;
   while((c = getchar()) != EOF) {
      switch(c)
      {
         case ' ':
            {
               ++number_of_blanks;
            }break;
         case '\t':
            {
               ++number_of_tabs;
            }break;
         case '\n':
            {
               ++number_of_new_lines;
            }break;

      }
   }
   printf("numero de blancos: %ld, numero de tabs: %ld, numero de new lines: %ld\n" ,number_of_blanks, number_of_tabs, number_of_new_lines);
   return 0;
}
