/* -------------------------------------------------------------------------
@file pool_persons.c

@date 11/22/16 21:35:41
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
                              Globals
-------------------------------------------------------------------------*/
#define POOL_SIZE 10 /* pool size */

/*-------------------------------------------------------------------------
                              custom types
-------------------------------------------------------------------------*/
typedef struct {
   char* first_name;
   char* last_name;
   char* title;
   uint age;
}Person;

Person* ptr_vPerson[POOL_SIZE]; /* pool of Person pointers */
/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
void initialize_Person(Person* person, const char* fn, const char* ln, const char* title, uint age);
/* function for initilize the pool */
void initilize_list();
/* get a Person from the pool */
Person* get_Person();
/*  */
Person* return_Person(Person* person);
/* */
void deallocate_Person(Person* person);
void display_Person(Person* person);
/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main(void)
{
   initilize_list();
   Person* ptr_Person;
   ptr_Person = get_Person();
   initialize_Person(ptr_Person, "Martin", "Noblia", "Ing", 34);
   display_Person(ptr_Person);
   return_Person(ptr_Person);

   return 0;
}

void initilize_list(){
   for (int i = 0; i < POOL_SIZE; i++) {
     ptr_vPerson[i] = NULL;
   }
}

Person* get_Person() {

   for (int i = 0; i < POOL_SIZE; i++) {
     if (ptr_vPerson[i] != NULL) {
       Person* ptr_Person = ptr_vPerson[i];
       ptr_vPerson[i] = NULL;
       return ptr_Person;
     }
   }
   Person* ptr_Person2 = (Person*)malloc(sizeof(Person));
   return ptr_Person2;
}

Person* return_Person(Person* person){

   for (int i = 0; i < POOL_SIZE; i++) {
      if (ptr_vPerson[i] == NULL) {
        ptr_vPerson[i] = person;
        return person;
      }
   }
   deallocate_Person(person);
   free(person);
   return NULL;
}

void deallocate_Person(Person* person) {

   free(person->first_name);
   free(person->last_name);
   free(person->title);
}

void initialize_Person(Person* person, const char* fn, const char* ln, const char* title, uint age){

   person->first_name = (char*)malloc(strlen(fn) + 1);
   strcpy(person->first_name, fn);

   person->last_name = (char*)malloc(strlen(ln) + 1);
   strcpy(person->last_name, ln);

   person->title = (char*)malloc(strlen(title) + 1);
   strcpy(person->title, title);

   person->age = age;
}

void display_Person(Person* person) {

   printf("Name: %s  Last Name: %s Title: %s  Age: %d \n",
         person->first_name,
         person->last_name,
         person->title,
         person->age);
}
