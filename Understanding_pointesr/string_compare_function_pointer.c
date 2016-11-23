/* -------------------------------------------------------------------------
@file string_compare_function_pointer.c

@date 11/22/16 12:59:58
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
typedef int (fptr_operation)(const char*, const char*);

/*-------------------------------------------------------------------------
                        prototypes
-------------------------------------------------------------------------*/
int compare(const char* s1, const char* s2);
int compare_ignore_case(const char* s1, const char* s2);
char* string_to_lower(const char* string);
void sort(char* array[], int size, fptr_operation operation);
void display_names(char* names[], int size);

/*-------------------------------------------------------------------------
                        main
-------------------------------------------------------------------------*/
int main(void)
{
   char* names[] = {"Martin", "Alejandro", "Noblia", "Paul", "Erdos"};
   sort(names, 5, compare_ignore_case);
   display_names(names, 5);
   return 0;
}

int compare(const char* s1, const char* s2){
   return strcmp(s1, s2);
}

int compare_ignore_case(const char* s1, const char* s2){
   char* t1 = string_to_lower(s1);
   char* t2 = string_to_lower(s2);
   int result = strcmp(t1, t2);
   free(t1);
   free(t2);

   return result;

}

char* string_to_lower(const char* string){
   char* tmp = (char*)malloc(strlen(string) + 1);
   char* start = tmp;
   while (*string != 0) {
      *tmp++ = tolower(*string++);
   }
   *tmp = 0;
   return start;
}

void sort(char* array[], int size, fptr_operation operation){
   bool_t swap = TRUE;
   while (swap) {
      swap = FALSE;
      for (int i = 0; i < size - 1; i++) {
         if (operation(array[i], array[i+1]) > 0) {
           swap = TRUE;
           char* tmp = array[i];
           array[i] = array[i+1];
           array[i+1] = tmp;
         }
      }

   }
}

void display_names(char* names[], int size){
   for (int i = 0; i < size; i++) {
      printf("%s  ", names[i]);
   }
   printf("\n");
}
