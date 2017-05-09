/* -------------------------------------------------------------------------
@file simple_compressor_RLE.c

@date 05/07/17 11:32:15
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Simple compressor implementing the RLE encoding
@detail
NOTE: Para comprobar primero se hizo una simple copia de los buffers
y se realizo la compresion y luego la descompresion volviendo al mismo
size como era de esperar
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
typedef unsigned char uchar;
/*-------------------------------------------------------------------------
  custom datatypes
 -------------------------------------------------------------------------*/
struct File_content
{
  size_t size;
  uchar* content;
};

/*-------------------------------------------------------------------------
 *                        statics functions
 -------------------------------------------------------------------------*/
static struct File_content
read_entire_file_bin(char* file_path) {
  struct File_content result = {};
   FILE* file = fopen(file_path, "rb"); /* read the file in binary */
   if(file) {
      fseek(file, 0, SEEK_END);
      /* TODO(elsuizo): 64 bit safe file size CRT */
      result.size = ftell(file); /* the problem with this is ftell */
      fseek(file, 0, SEEK_SET);
      result.content = (uchar*)malloc(result.size);
      fread(result.content, result.content, 1, file);
      fclose(file);
   } else {
     fprintf(stderr, "Unable to read the file: %s", file_path);
   }
   return(result);
}

static size_t
get_max_output_size(size_t in_size) {
   size_t out_size = 256 + 2 * in_size;
   return(out_size);
}
/* utiliza esto para probar que lo que penso esta bien
 * o se que si ponemos copy en compress y decompress
 * no deberia pasarle nada al archivo de entrada en cuanto
 * a su tamanio*/
static void
copy_buffer(size_t size, uchar* source, uchar* dest) {
   /* pointer magics */
   while (size--) {
      *dest++ = *source++;
   }
}

static size_t
compress(size_t in_size, uchar* in, size_t out_size, uchar* out) {
   copy_buffer(in_size, in , out);
   return(in_size);
}

static void
decompress(size_t in_size, uchar* in, size_t out_size, uchar* out) {
   copy_buffer(in_size, in , out);
}
/*-------------------------------------------------------------------------
 *                       main
 -------------------------------------------------------------------------*/
int main(int arg_count, char** args)
{
   if (arg_count == 4) {
      size_t final_output_size = 0;
      uchar* final_output_buffer = 0;
      /* parse the comand-line commands */
      char* command = args[1];
      char* in_file_name = args[2];
      char* out_file_name = args[3];
      struct File_content file_content = read_entire_file_bin(in_file_name);
      if (strcmp(command, "compress") == 0) {
         /* NOTE(elsuizo:2017-05-08): hace que el output contenga la informacion de size
          * por eso hace que malloc tenga 4 bytes mas y luego hace que compress vaya 4 bytes
          * mas alla... para luego guardarlo en el buffer de salida: out_buffer*/
         size_t out_buffer_size = get_max_output_size(file_content.size);
         uchar* out_buffer = (uchar*)malloc(out_buffer_size + 4);
         size_t compressed_size = compress(file_content.size,
                                          file_content.content,
                                          out_buffer_size,
                                          out_buffer + 4);
         /* claaaro pone int unsigned porque esta guardando un valor de 4 bytes
          * que es un realidad un numero de 32 bits!!!
          * o sea que es una manera super fancy de guardar un valor*/
         *(unsigned int*)out_buffer = (int unsigned)compressed_size; /* aca dice que es el primer puntero a donde lo asigna */
         final_output_size = compressed_size + 4;
         final_output_buffer = out_buffer;
         /* decompress */
         /* Notemos que ya que out_buffer esta declarado en otro bloque de codigo no es "visible"
          * para este bloque!!!*/
      } else if (strcmp(command, "decompress") == 0) {
         if(file_content.size > 4) {
            /* aca lee el valor que habia guardado en el buffer cuando hizo la compresion */
            size_t out_buffer_size = *(int unsigned*)file_content.content;
            uchar* out_buffer = (uchar*)malloc(out_buffer_size);
            decompress(file_content.size - 4, file_content.content + 4, out_buffer_size, out_buffer);
            final_output_size = out_buffer_size;
            final_output_buffer = out_buffer;
         } else {
            fprintf(stderr, "Invalid input file\n");

         }

      } else {
         fprintf(stderr, "Unrecognize command!!! %s\n", command);
      }
      if (final_output_buffer) {
         FILE* out_file = fopen(out_file_name, "wb");
         if (out_file) {
            fwrite(final_output_buffer, 1, final_output_size, out_file);
         } else {
            fprintf(stderr, "Unable to open output file %s\n", out_file_name);
         }
      }
   } else {
      fprintf(stderr, "Usage: %s compress [raw filename] [compressed filename]\n", args[0]);
      fprintf(stderr, "     : %s decompress [compressed filename] [raw filename]\n", args[0]);
   }
   return 0;
}


