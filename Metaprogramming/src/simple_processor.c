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
#include "../inc/simple_processor.h"


/*-------------------------------------------------------------------------
 *                       functions implementations
 -------------------------------------------------------------------------*/

/**
 * @brief comparacion de strings para saber si llegamos a un token que nos
 * interesa, en este caso seria el nombre de match_name que estamos buscando
 *
 * @param tokeneizer
 * @param match_name
 *
 * @return true, false
 */
bool
tokens_equals(struct Token token, char* match_name) {
   size_t i;
   char* at = match_name;
   for(i = 0; i < token.text_length; ++i, ++at) {
      if ((*at == 0 ) || (token.text[i] != *at)) {
         return(false);
      }
   }
   bool result = (*at == 0);

   return(result);
}

void
parse_instrospection_params(struct Tokeneizer* tokeneizer) {

   while(true) {
      struct Token token = get_Token(tokeneizer);
      if ((token.type == Token_close_paren) || (token.type == Token_end_of_string)) {
         break;
      }
   }
}

void
parse_member_Token(struct Tokeneizer* tokeneizer, struct Token member_type_Token) {

   bool parse = true;
   bool is_pointer = false;

   while(parse) {
      struct Token token_name = get_Token(tokeneizer);
      switch(token_name.type)
      {
         case Token_asterisk:
            {
               is_pointer = true;
            } break;
         case Token_identifier:
            {
               printf("DEBUG_VALUE(%.*s);\n", token_name.text_length, token_name.text);
            } break;
         case Token_semi_colon:
         case Token_end_of_string:
            {
               parse = false;
            } break;

      }
   }
}

void
parse_struct(struct Tokeneizer* tokeneizer) {

   if (require_Token(tokeneizer, Token_open_brace)) {
      printf("comienzo!!!");
      while (true) {
         struct Token member_Token = get_Token(tokeneizer);
         if (member_Token.type == Token_close_brace) {
            break;
         } else {
            parse_member_Token(tokeneizer, member_Token);
         }
      }
   } else {
      printf("No ha entrado!!!");
   }

}

void
parse_instrospectable(struct Tokeneizer* tokeneizer) {

   if (require_Token(tokeneizer, Token_open_paren)) {
      parse_instrospection_params(tokeneizer);

      printf("token antes:%s", tokeneizer->at);
      struct Token token = get_Token(tokeneizer);
      printf("token despues:%s", token.text);

      if (tokens_equals(token, "struct")) {
         parse_struct(tokeneizer);
      } else {
         fprintf(stderr, "ERROR: instrospection is only soported for struct :(\n");
      }
   } else {
      fprintf(stderr, "ERROR: missing parentheses!!!\n");
   }
}

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
         while ((tokeneizer->at[0]) &&
               !(tokeneizer->at[0] != '*' && (tokeneizer->at[1] != '/'))
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
      case '\0': {token.type = Token_end_of_string;} break; /* the most important!!! */
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

bool
require_Token(struct Tokeneizer* tokeneizer, enum token_type desire_type) {

   struct Token token = get_Token(tokeneizer);
   bool result = (token.type == desire_type);

   return(result);
}
