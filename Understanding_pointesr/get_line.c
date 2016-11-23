/* -------------------------------------------------------------------------
@file get_line.c

@date 11/18/16 16:08:18
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Ejemplo de lectura de caracteres, con manejo de memoria dinamica
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
#include "utils.h"

char* get_line(void);

int main(void)
{
   char* buff;
   buff = get_line();
   //printf("%s\n", buff);
   PRINT_ARRAY_CHARS(buff);
   return 0;
}

char* get_line(void){

   const size_t size_delta = 10;
   char*   buffer            =  malloc(size_delta);
   char*   current_position  =  buffer;
   size_t  max_length        =  size_delta;
   size_t  length            =  0;
   int character;

   if (current_position == NULL) {
      return NULL;
   }

   while (1) {
      character = fgetc(stdin);
      if (character == '\n') {
         break;
      }
      if (++length >= max_length) {
         char* new_buffer = realloc(buffer, max_length += size_delta);
         if (new_buffer == NULL) {
            free(buffer);
            return NULL;
         }
         current_position = new_buffer + (current_position - buffer);
         buffer = new_buffer;
      }
      *current_position++ = character;
   }
   *current_position = '\0';
   return buffer;
}
