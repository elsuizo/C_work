/* -------------------------------------------------------------------------
@file test_ccv.c

@date 04/27/17 22:52:45
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
#include <ccv.h>

int main(int args, char** argv)
{
   ccv_dense_matrix_t* image = 0;
   ccv_read(argv[1], &image, CCV_IO_GRAY, CCV_IO_ANY_FILE);
   ccv_write(image, argv[2], 0, CCV_IO_PNG_FILE, 0);

   return 0;
}

