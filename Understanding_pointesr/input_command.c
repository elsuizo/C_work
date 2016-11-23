/* -------------------------------------------------------------------------
@file input_command.c

@date 11/22/16 00:34:45
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

int main(void)
{
   char command[16];
   printf("Enter a command: ");
   scanf("%s", command);
   if(strcmp(command, "Quit") == 0){
      printf("The command was Quit");
   }else{
      printf("The command was not Quit");
   }

   return 0;
}




