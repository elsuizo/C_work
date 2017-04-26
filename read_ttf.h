/* -------------------------------------------------------------------------
@file read_ttf.h

@date 04/12/17 23:19:11
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail
Example reading a ttf file from: Allen Webster
https://www.youtube.com/watch?v=uR6lBsRaT-o
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
#ifndef READ_TTF_H
#define READ_TTF_H

typedef unsigned int Fixes16_16;

/**
 * @brief Header information
 */
struct Offset_Table {
   Fixes16_16 version;
   unsigned short num_tables;
   unsigned short search_range;
   unsigned short entry_selector;
   unsigned short range_shift;
};

struct Table_directory_Entry {
   unsigned long tag;
   unsigned long check_sum;
   unsigned long offset;
   unsigned long length;
};

struct Data {
   char* data;
   int size;
};

#endif
