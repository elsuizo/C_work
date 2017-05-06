/* -------------------------------------------------------------------------
@file main.c

@date 04/27/17 10:03:40
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
#include "../inc/simple_processor.h"

/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main(void)
{
   /* char* file_name = "/home/elsuizo/lists.h"; */
   char* file_name = "/home/elsuizo/C_work/Metaprogramming/inc/simple_processor.h";

   char* file_content = read_entire_file_null_terminate(file_name);
   if (file_content == 0) {
      printf("could not open: %s\n", file_name);
      return(1);
   }
   struct Tokeneizer tokeneizer = {};
   /* like a iterator??? */
   tokeneizer.at = file_content;

   bool parsing = true;
   while(parsing) {
      struct Token token = get_Token(&tokeneizer);

      switch(token.type) {
         case Token_end_of_string:
            {
               parsing = false;
            }break;
         case Token_identifier:
            {
               /* printf("identifier!!!\n"); */
               if (tokens_equals(token, "instrospect")) {
                  parse_instrospectable(&tokeneizer);
               }
            }break;
         case Token_unknown:
            {
               /* printf("Unknown token!!!\n"); */
            }break;
         default:
            {
               /* .*s cpp crazy town */
               /* printf("%d: %.*s\n", token.type, token.text_length, token.text); */
            }break;

      }
   }

   return(0);
}

