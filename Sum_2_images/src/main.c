/* -------------------------------------------------------------------------
@file main.c

@date 04/06/17 17:21:20
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Add two png images
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
/*-------------------------------------------------------------------------
Comentarios:
cuando leemos una imagen en este caso obtenemos una representacion en
memoria de ella, osea que lo podemos pensar como si fuera un array de 1D
por ello los parametros que nos dan de vuelta son el ancho, el largo y
la cantidad de bytes que bytes por pixels que se usan para representar
un pixel.
Por ello necesitamos saber como pasar de una fila a otra de la representacion
de la imagen. Ese numero se lo conoce como pitch o strides. que es el que
mediante simple aritmetica de punteros nos hace pasar de una fila a otra
de nuestra representacion de imagen.
-------------------------------------------------------------------------*/
/* NOTE(elsuizo: 2017-04-12) no hay padding en esta libreria
 * Las imagenes comienzan en la esquina superior izquierda
 * con una altura dada por height y un ancho dado por width
 * los pixels consisten en N componentes de 8 bits entrelazados
 * No hay padding entre las filas o entre pixels, sin importar el formato
 * si hacemos N=4 obtenemos una imagen RGBA*/
/* includes */

#define STB_IMAGE_IMPLEMENTATION
/* #define STB_DEFINE */
/* #include "../inc/stb.h" */
#include "../inc/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../inc/stb_image_write.h"

#include <stdio.h>
#include <stdlib.h>

static unsigned char* read_image(char* path, int* w, int* h) {
   unsigned char* image_output;
   image_output = stbi_load(path, w, h, 0, 3);
   return image_output;
}

static unsigned char* read_image_gray(char* path, int* w, int* h) {
   unsigned char* image_output;
   image_output = stbi_load(path, w, h, 0, 1);
   return image_output;
}

static void write_image(char* path, unsigned char* image, int w, int h) {

   stbi_write_png(path, w, h, 3, image, 0);
}

/* TODO(elsuizo:2017-04-20):como hago para verificar que me ingresaron bine la image??? */
static void write_image_gray(char* path, unsigned char* image, int w, int h) {

   stbi_write_png(path, w, h, 1, image, 0);
}
/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main(void)
{
   int width, height, h, w;
   unsigned char red, green, blue;
   unsigned char* image;
   unsigned char* image_gray;
   /* unsigned char* image = stbi_load("/home/elsuizo/Images/beagle1.png", */
                                                /* &width, &height, 0, 3); */
   image = read_image("/home/elsuizo/Images/beagle1.png", &width, &height);
   image_gray = read_image_gray("/home/elsuizo/Images/beagle1.png", &w, &h);


   for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
         red    =  image[3 * (i * width + j) + 0];
         green  =  image[3 * (i * width + j) + 1];
         blue   =  image[3 * (i * width + j) + 2];
         if(red == 255) {
            image[3 * (i * width + j) + 0] = 0;
         }
         /* printf("green: %u\n", green); */
      }
   }

   /* stbi_write_png("piola.png", width, height, 3, image, 0); */
   /* stbi_write_png("piola_gray.png", w, h, 1, image_gray, 0); */
   write_image("piola2.png", image, w, h);
   write_image_gray("piola2_gray.png", image_gray, w, h);
   printf("height: %d\n", height);
   printf("width: %d\n", width);
   stbi_image_free(image);
   return 0;
}


