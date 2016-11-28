/* -------------------------------------------------------------------------
@file menu_example.c

@date 11/24/16 02:59:57
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
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

void say_usage();

int main(void)
{
   say_usage();
   return 0;
}

void say_usage(){
    static const char *usage[] = {
        " ",
        "Decode an SPI bytestream to "", "", and the console",
        "Usage: spi_decode [-cn] [-f]",
        "  -cn  inputs from COM port n (default 5) and appends to " ,
        "  -f   inputs from file "" instead",
        "  -r   record 'receive enable' in the packet file",
        ""
    };
    int i=0;
    while (usage[i][0] != '\0') fprintf(stderr, "%s\n", usage[i++]);
}
