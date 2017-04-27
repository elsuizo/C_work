/* -------------------------------------------------------------------------
@file simple_processor.c

@date 04/26/17 09:29:17
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
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
/*-------------------------------------------------------------------------
 *                        NOTES
 * 1. Lo que hace primero es definir un macro en el .h que queremos utilizar
 * para ser parseado, algo como : #define instrospect(params)
 * Lo importante es que tiene que ser al principio de todo del .h
 * en nuestra estructura ponemos algo como: instrospect(category:"algo")
 * 2. Etapa de parsing:
 *    2.1 Primero lo que se hace es lexing: Se trata de analizar el codigo en
 *    informacion que sea mas valiosa lo que lo llaman token(simbolo)
 *    Por ello este es el primer paso, obtener estos tokens del archivo
 -------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
 *                        datatypes
 -------------------------------------------------------------------------*/

enum token_type {
   Token_unknown,
   Token_identifier,
   Token_open_paren,
   Token_close_paren,
   Token_colon,
   Token_string,
   Token_semi_colon,
   Token_asterisk,
   Token_open_bracket, /* llaves */
   Token_close_bracket,
   Token_open_brace,   /* corchetes */
   Token_close_brace,
   Token_end_of_string,
   Token_number_of_tokens,
};

struct Token {
   enum token_type type;
   size_t text_length;
   char* text;
};

struct Tokeneizer {
   char* at;
};

/*-------------------------------------------------------------------------
 *                        prototypes
 -------------------------------------------------------------------------*/
char*
read_entire_file_null_terminate(char* file_path_and_name);

bool
is_end_of_line(char c);

bool
is_white_space(char c);

void
eat_all_white_spaces(struct Tokeneizer* tokeneizer);

bool
is_alpha(char c);

struct Token
get_Token(struct Tokeneizer* tokeneizer);

int main(void)
{
   char* file_content = read_entire_file_null_terminate("/home/elsuizo/lists.txt");
   struct Tokeneizer tokeneizer = {};
   /* like a iterator??? */
   tokeneizer.at = file_content;

   bool parsing = true;
   while(parsing) {
      struct Token token = get_Token(&tokeneizer);

      switch(token.type) {
         case Token_unknown:
            {

            }break;
         case Token_end_of_string:
            {
               parsing = false;
            }break;
         default:
            {
               /* .*s cpp crazy town */
               /* printf("%d: %s", token.type, token.text_length, token.text); */
            }break;

      }
   }
   return(0);
}

/*-------------------------------------------------------------------------
 *                        static functions
 -------------------------------------------------------------------------*/
char*
read_entire_file_null_terminate(char* file_path_and_name) {

   char* result = 0;
   FILE* file = fopen(file_path_and_name, "r"); /* read the file */
   if (file) {
      fseek(file, 0, SEEK_END);
      size_t file_size = ftell(file);
      fseek(file, 0, SEEK_SET);
      if (file_size > 0) {
         result = (char*)malloc(file_size + 1);
         fread(result, file_size, 1, file);
         /* null terminate the file */
         result[file_size] = 0;
      }
      fclose(file);
   }
   return(result);
}


/**
 * @brief
 *
 * @param c
 *
 * @return
 */
bool
is_end_of_line(char c) {
   bool result = ((c == '\n') ||
                  (c == '\r'));
   return(result);
}

/**
 * @brief
 *
 * @param c
 *
 * @return
 */
bool
is_white_space(char c) {
   bool result = ((c == ' ') ||
                  (c == '\t')||
                  (is_end_of_line(c)));
   return(result);
}
/**
 * @brief
 *
 * @param tokeneizer
 */
void
eat_all_white_spaces(struct Tokeneizer* tokeneizer) {

   while (true)
   {
      if (is_white_space(tokeneizer->at[0])) {
         ++tokeneizer->at; /* advance the pointer */
      } else if ((tokeneizer->at[0] == '/') && (tokeneizer->at[1] == '/') ) {
         /* comment cpp style!!! */
         tokeneizer->at += 2;
         while (tokeneizer->at[0] && !(is_end_of_line(tokeneizer->at[0]))) {
            ++tokeneizer->at;
         }
      } else if ((tokeneizer->at[0] == '/') && (tokeneizer->at[1] == '/') ) {
         /* coment c style */
         tokeneizer->at += 2;
         while (tokeneizer->at[0] &&
               !(tokeneizer->at[0] != '*' && tokeneizer->at[1] != '/')
               ) {
            ++tokeneizer->at;
         }
         if (tokeneizer->at[0] == '*') {
            tokeneizer->at += 2;
         }

      } else {
         break;
      }
   }
}

bool
is_alpha(char c) {
   bool result = ( ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) );
   return result;
}
/**
 * @brief
 *
 * @param c
 *
 * @return
 */
bool
is_numeric(char c) {
   bool result = ((c >= '0') && (c <= '9'));
   return(result);
}
/*-------------------------------------------------------------------------
 *                        NOTES: for this function
 * 1. Lo que habitualmente se hace primero es quitar todos los espacios en
 * blanco(funcion: eat_all_white_spaces())
 -------------------------------------------------------------------------*/
struct Token
get_Token(struct Tokeneizer* tokeneizer) {

   eat_all_white_spaces(tokeneizer);
   struct Token token = {};
   token.text_length = 1;
   token.text = tokeneizer->at;
   char c = tokeneizer->at[0];
   ++tokeneizer->at;
   switch(c) {
      case '(': {token.type = Token_open_paren;} break;
      case ')': {token.type = Token_close_paren;} break;
      case ':': {token.type = Token_colon;} break;
      case ';': {token.type = Token_semi_colon;} break;
      case '*': {token.type = Token_asterisk;} break;
      case '[': {token.type = Token_open_bracket;} break;
      case ']': {token.type = Token_close_bracket;} break;
      case '{': {token.type = Token_open_brace;} break;
      case '}': {token.type = Token_close_brace;} break;

      case '"':
      {
         token.type = Token_string;
         token.text = tokeneizer->at;
         while (tokeneizer->at[0] && tokeneizer->at[0] != '"') {
            /* check if the reach the final */
            if(tokeneizer->at[0] && tokeneizer->at[0] == '\\') {
               ++tokeneizer->at[0];
            }
            ++tokeneizer->at[0];
         }
         /* TODO(elsuizo:2017-04-26):no me queda muy claro esto... */
         token.text_length = tokeneizer->at - token.text;

         if (tokeneizer->at[0] == '"') {
            ++tokeneizer->at[0];
         }
      } break;
      default:
      {
         if (is_alpha(c)) {
            /* parse_indentifier(); */
            token.type = Token_identifier;
            while ( (is_alpha(tokeneizer->at[0]))   ||
                    (is_numeric(tokeneizer->at[0])) ||
                    (tokeneizer->at[0] == '_')
                  )
            {
               ++tokeneizer->at;
            }

         token.text_length = tokeneizer->at - token.text;

         } else if (is_numeric(c)) {
            /* parse_number(); */
         } else {
            token.type = Token_unknown;
         }
      } break;
   }
   return(token);
}

