/* -------------------------------------------------------------------------
@file serial_read.c

@date 04/24/17 13:34:54
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Read a message from the serial port
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
#include <fcntl.h> /* File control definition */
#include <termios.h> /* POSIX terminal control definitions */
#include <unistd.h> /* UNIX standard definitions */
#include <errno.h> /* ERROR numbers defintions */
#include <inttypes.h>
#include <stdint.h>

int main(void)
{
   int file_descriptor;

   /* open the serial port */
   /* TODO(elsuizo:2017-04-24):change this for open any port */
   char* serial_port_path = "/dev/ttyACM0";
   file_descriptor = open(serial_port_path, O_RDWR | O_NOCTTY);
   char* status_message = (file_descriptor < 0) ? "Error opening the port!!!": "port opened succesfully";
   printf("%s\n", status_message);
   /* setting the serial port communication using termios struct */
   struct termios serial_port_settings;
   tcgetattr(file_descriptor, &serial_port_settings);	/* Get the current attributes of the Serial port */
   /* setting the baud rate = 9600*/
   cfsetispeed(&serial_port_settings, B9600); /* read speed 9600 */
   cfsetospeed(&serial_port_settings, B9600); /* write speed 9600 */
   /* 8N1 mode */
   serial_port_settings.c_cflag &= ~PARENB; /* Disable the bit parity */
   serial_port_settings.c_cflag &= ~CSTOPB; /* CSTOP=2 bits is cleared ===> 1 bit STOP*/
   serial_port_settings.c_cflag &= ~CSIZE; /* Clear the mask for setting the data size*/
   serial_port_settings.c_cflag |= CS8; /* Clear the mask for setting the data size*/

   /* NOTE(elsuizo:2017-04-24):caution */
   /* this only compile with the compiler flag -std=gnu99
    * view: http://stackoverflow.com/questions/26944217/crtscts-not-define-when-compiling-as-c99 
    * */
   serial_port_settings.c_cflag &= ~CRTSCTS; /* No hardware flow control */
   serial_port_settings.c_cflag |= CREAD | CLOCAL; /* Enable receiber, ignore modem control lines*/

   serial_port_settings.c_iflag &= ~(IXON | IXOFF | IXANY); /* Disable XON and XOFF flow control */
   serial_port_settings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG); /* Non canonical mode */
   serial_port_settings.c_oflag &= ~OPOST; /* No output processing */
   /* settings timeouts */
   serial_port_settings.c_cc[VMIN] = 10; /* read at least 10 characters */
   serial_port_settings.c_cc[VTIME] = 0; /* wait indefinetly */
   /* Set the attributes to the termios structure*/
   if((tcsetattr(file_descriptor,TCSANOW, &serial_port_settings)) != 0) {
      printf("ERROR ! in Setting attributes");
   } else {
      /* printf("BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none"); */
      printf("Stop bits: %b", ~CSTOPB);
   }

   tcflush(file_descriptor, TCIFLUSH); /* discard the old data in rx buffer */
   char read_buffer[32]; /* buffer to store the receive data */
   uint32_t bytes_read;
   uint32_t i;

   bytes_read = read(file_descriptor, &read_buffer, 32); /* read the data!!! */
   printf("Bytes received: %d\n", bytes_read);

   /* TODO(elsuizo:2017-04-25):cambiar esto para que se quede escuchando el puerto */
   for (i = 0; i < bytes_read; i++) {
      printf("%c", read_buffer[i]);
   }
   printf("\n-------------------------------------------------------------------------\n");
   close(file_descriptor);

   return 0;
}

