/* -------------------------------------------------------------------------
@file 1-9.c

@date 04/19/17 23:19:30
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Write a program to copy its imput to its output, replacing each string of
one or more blanks by a single blanck
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

#define IN 1
#define OUT 0
int main(void)
{
   int input;
   int number_characters
   int number_blanck = 0;
   int state = OUT;
   while((c = getchar()) != EOF) {
      ++number_characters;
      if (c == ' ') {
         ++number_blanks;
      }
   }
   return 0;
}
