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

#define  IN   1
#define  OUT  0

int main(void)
{
   int c;
   int number_of_blanks = 0;
   int number_of_tabs = 0;
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
            }

      }
   }
   printf("numero de blancos: %d, numero de tabs%d" ,number_of_blanks, number_of_tabs);
   return 0;
}


