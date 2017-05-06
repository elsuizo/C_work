/* -------------------------------------------------------------------------
@file ejemplo_wc.c

@date 04/19/17 21:57:05
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Word count example: pag 20
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
/* NOTE(elsuizo:2017-04-19):para ingresar en EOF en linux Ctrl-d!!! */
#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outiside a word */
/* count lines, words, and characters in input */
int main(void)
{
   int c, nl, nw, nc, state;
   state = OUT;
   nl = nw = nc = 0;
   while((c = getchar()) != EOF) {
      ++nc;
      if (c == '\n') {
         ++nl;
      }
      if (c == ' ' || c == '\n' || c == '\t') {
         state = OUT;
      } else if (state == OUT) {
         state = IN;
         ++nw;
      }
   }
   printf("%d %d %d \n", nl, nw, nc);
   return 0;
}


