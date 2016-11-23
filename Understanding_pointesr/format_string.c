/* -------------------------------------------------------------------------
@file format_string.c

@date 11/22/16 11:43:13
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

char* format(
      char* buffer,
      size_t size,
      const char* name,
      size_t quantity,
      size_t weight);

int main(void)
{
   char* buffer = "Buffer";
   printf("%s\n", format(buffer, sizeof(buffer), "Axle", 37, 73));
   return 0;
}

char* format(
      char* buffer,
      size_t size,
      const char* name,
      size_t quantity,
      size_t weight){

snprintf(buffer, size, "Item: %s Quantity: %ld Weight: %ld", name, quantity, weight);

return buffer;
}
