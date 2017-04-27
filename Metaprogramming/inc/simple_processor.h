/* -------------------------------------------------------------------------
@file simple_processor.h

@date 04/27/17 09:59:54
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
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>

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
#define instrospect(params)

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

instrospect() struct Token {
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

void
parse_instrospectable(struct Tokeneizer* tokeneizer);

bool
tokens_equals(struct Token token, char* match_name);

void
parse_instrospection_params(struct Tokeneizer* tokeneizer);

void
parse_member_Token(struct Tokeneizer* tokeneizer, struct Token member_type_Token);

void
parse_struct(struct Tokeneizer* tokeneizer);

bool
require_Token(struct Tokeneizer* tokeneizer, enum token_type desire_type);

