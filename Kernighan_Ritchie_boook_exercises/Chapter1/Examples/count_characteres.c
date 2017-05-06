/* -------------------------------------------------------------------------
@file count_characteres.c

@date 04/29/17 10:37:45
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Count characters in a text stream
@detail
NOTE: for count the characters of a text file do:
less text.txt | ./count_characters
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
   long number_of_chars = 0;
   while (getchar() != EOF) {
      ++number_of_chars;
   }
   printf("The number of characters in the text stream is: %ld", number_of_chars);
   return 0;
}



