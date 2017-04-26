/* -------------------------------------------------------------------------
@file read_entire_file_to_memory.c

@date 04/25/17 20:18:16
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

char* read_file_and_null_terminate(char* file_path) {
   char* result = 0;
   FILE* file = fopen(file_path, "r"); /* open the file for read "r" */
   if (file) {
      fseek(file, 0, SEEK_END); /* move to point to the end of buffer */
      size_t file_size = ftell(file); /* obtein the file size */
      fseek(file, 0, SEEK_SET); /* come back the pointer */

      result = (char*)malloc(file_size + 1);
      fread(result, file_size, 1, file);
      result[file_size] = 0;
   }
   return result;
}

int main(void)
{
   
   return 0;
}


