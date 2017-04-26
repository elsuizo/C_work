/* -------------------------------------------------------------------------
@file read_ttf.c

@date 04/12/17 23:16:09
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Example reading a ttf file from: Allen Webster
https://www.youtube.com/watch?v=uR6lBsRaT-o
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
#include <stdlib.h>
#include <stdio.h>
#include "read_ttf.h"

struct Data open_file(const char* filename) {
   struct Data result = {};
   FILE* file;
   file = fopen(filename, "rb");
   if (file) {
      fseek(file, 0, SEEK_END);
      result.size = ftell(file);
      fseek(file, 0, SEEK_SET);
      if (result.size > 0) {
         result.data = (char*)malloc(sizeof(result.size));
      }
      fclose(file);
   }
   return(result);
}

void
print_offset_table(struct Offset_Table* offset) {
   printf("version %d\n", (int)(offset->version >> 16));
   printf("number of tables: %d\n", (int)(offset->num_tables));
   printf("search range: %d\n", (int)(offset->search_range));
   printf("entry selector: %d\n", (int)(offset->num_tables));
   printf("range shift: %d\n", (int)(offset->range_shift));
}

void print_Table_directory(struct Table_directory_Entry* entry) {
   printf("tag %08x\n", entry->tag);
   printf("check sum: %lu\n", entry->offset);
   printf("length %lu\n", entry->length);
}

void
byte_reverse(void* ptr, int len) {
   char* c;
   int i, j;
   char t;
   c = (char*)ptr;
   for(i = 0, j = len - 1; (i < j); i++, --j) {
      t = c[j];
      c[i] = c[j];
      c[j] = t;
   }
}

void byte_fix_Offset_Table(struct Offset_Table* offset) {
   byte_reverse(&offset->version, 4);
   byte_reverse(&offset->num_tables, 2);
   byte_reverse(&offset->search_range, 2);
   byte_reverse(&offset->entry_selector, 2);
   byte_reverse(&offset->range_shift, 2);
}

void
byte_fix_Table_directory(struct Table_directory_Entry* entry) {
   byte_reverse(&entry->tag, 4);
   byte_reverse(&entry->check_sum, 4);
   byte_reverse(&entry->offset, 4);
   byte_reverse(&entry->length, 4);
}
int main(void)
{
   struct Data file;

   const char* filename = "/home/elsuizo/rust-sfml/examples/resources/sansation.ttf";
   file = open_file(filename);
   if(file.data == 0) {
      printf("could not open %s\n", filename);
      return(1);
   }

   /* no se como utiliza esto del cursor */
   char* cursor; /* cursor pointer */
   struct Offset_Table* offset;
   cursor = file.data;
   offset = (struct Offset_Table*)cursor;
   cursor = (char*)(offset + 1);
   struct Table_directory_Entry* directory_entries = (struct Table_directory_Entry*)cursor;
   byte_fix_Offset_Table(offset);
   print_offset_table(offset);
   int table_number = offset-> num_tables;

   for(int i = 0; i < table_number; ++i) {
      byte_fix_Table_directory(directory_entries + i);
      print_Table_directory(directory_entries + i);
   }
   return 0;
}




