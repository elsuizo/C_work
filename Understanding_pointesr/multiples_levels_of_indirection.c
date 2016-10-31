/* -------------------------------------------------------------------------
@file multiples_levels_of_indirection.c

@date 10/28/16 16:54:24
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

int main(void)
{
   char* titles[] = {"libro1", "libro2", "libro3", "libro4"};
   int number_of_best = 3;
   char** best_books[number_of_best];

   best_books[0] = &titles[0];
   best_books[1] = &titles[1];
   best_books[2] = &titles[3];
   printf("%s\n", *best_books[0]);
   return 0;
}


