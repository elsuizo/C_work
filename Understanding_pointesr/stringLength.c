/* -------------------------------------------------------------------------
@file stringLength.c

@date 11/22/16 03:00:29
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
#include <string.h>
#include "utils.h"

/* Remember use const!!! */
size_t string_length(const char* string);

int main(void)
{
   char* name = "Martin";
   size_t length = string_length(name);
   printf("The name:%s has Length: %ld\n", name, length);
   return 0;
}

size_t string_length(const char* string){
   size_t length = 0;
   while(*(string++)){
      length++;
   }
   return length;
}
