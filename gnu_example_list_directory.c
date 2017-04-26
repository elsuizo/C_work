/* -------------------------------------------------------------------------
@file gnu_example_list_directory.c

@date 04/25/17 10:07:28
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
List the directories
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
#include <sys/types.h>
#include <dirent.h>



int
main (void)
{
   DIR *dp;
   struct dirent *ep;
   dp = opendir("./");
   if (dp != NULL)
   {
      while ((ep = readdir(dp)))
         puts (ep->d_name);
      (void)closedir (dp);
   }
   else
      perror ("Couldn't open the directory");

   return 0;
}

