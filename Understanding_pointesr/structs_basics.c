/* -------------------------------------------------------------------------
@file structs_basics.c

@date 11/22/16 15:55:03
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
#include "utils.h"
/*-------------------------------------------------------------------------
                              custom types
-------------------------------------------------------------------------*/
typedef struct _person {
   char*  first_name;
   char*  last_name;
   char*  title;
   unsigned int age;
}Person;

struct agent {
   char*  first_name;
   char*  last_name;
   int    id;
   unsigned int age;
};

/*-------------------------------------------------------------------------
                              main
-------------------------------------------------------------------------*/
int main(void)
{
   Person* ptr_Person;
   struct agent* ptr_agent;
   ptr_Person->first_name = "Martin";
   ptr_Person->last_name = "Noblia";
   ptr_Person->title = "Ingeniero";
   ptr_Person->age = 34;

   ptr_agent->first_name = "Jose";
   ptr_agent->last_name = "Tiburcio";
   ptr_agent->id = 37373;
   ptr_agent->age = 37;

   Person* ptr_vPerson[2];
   ptr_vPerson[1] = ptr_Person;

   return 0;
}
