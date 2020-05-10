/* -------------------------------------------------------------------------
@file serial.c

@date 04/24/17 11:43:04
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
#include <fcntl.h> /* Files control definitions */
#include <termios.h> /* Posix terminal control definitions */
#include <unistd.h> /* UNIX standar definitions */
#include <errno.h> /* ERROR numbers definitions */

int main(void) {
   int fd;
   /* open the file */
   fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
   char* message = (fd < 0) ? "Error opening the port!!!\n": "ttyACMO opened succesfully\n";
   printf("%s", message);
   /* close the file */
   close(fd);
}
