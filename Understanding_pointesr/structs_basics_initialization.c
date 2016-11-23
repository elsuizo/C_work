/* -------------------------------------------------------------------------
@file structs_basics_initialization.c

@date 11/22/16 17:19:14
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
typedef struct _person{
   char* first_name;
   char* last_name;
   char* title;
   uint  age;
}Person;

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void initilize_Person(Person* person, const char* fn, const char* ln, const char* title, uint age);

void deallocate_Person(Person* person);

int main(void)
{
   Person* ptr_Person;
   ptr_Person = (Person*)malloc(sizeof(Person));
   initilize_Person(ptr_Person, "Martin", "Noblia", "Ing", 34);
   deallocate_Person(ptr_Person);
   free(ptr_Person);
   return 0;
}


void initilize_Person(Person* person, const char* fn, const char* ln, const char* title, uint age){

   person->first_name = (char*)malloc(strlen(fn) + 1);
   strcpy(person->first_name, fn);

   person->last_name = (char*)malloc(strlen(ln) + 1);
   strcpy(person->last_name, ln);

   person->title = (char*)malloc(strlen(title) + 1);
   strcpy(person->title, title);

   person->age = age;
}

void deallocate_Person(Person* person){
   free(person->first_name);
   free(person->last_name);
   free(person->title);

}

