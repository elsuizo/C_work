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

typedef unsigned char uchar;

struct Image {
   int width;
   int height;
   uchar* data;
};

struct Image_iterator {
   uchar* at;
};

static struct Image
read_Image(char* path_to_image) {
   struct Image image_output = {};
   image_output.data = stbi_load(path_to_image, &image_output.width, &image_output.height, 0, 3);
   return image_output;
}

static struct Image
read_Image_gray(char* path) {
   struct Image image_output = {};
   image_output.data = stbi_load(path, &image_output.width, &image_output.height, 0, 1);
   return image_output;
}

static void
write_Image(char* path, struct Image* image) {

   stbi_write_png(path, image->width, image->height, 3, image->data, 0);
}

static void
write_Image_gray(char* path, struct Image* image_gray) {

   stbi_write_png(path, image_gray->width, image_gray->height, 1, image_gray->data, 0);
}

static struct Image
sum_Images_gray(struct Image* image1, struct Image* image2) {
   /* check if the two images  */
   if ((image1->width == image2->width) && (image1->height == image2->height)) {
      int i, j;
      /* allocate image data output */
      uchar* data_output = (uchar*)malloc(sizeof(uchar) * image1->width * image2->height);
      /* initialize the struct */
      struct Image image_output = {.width = image1->width, .height = image1->height, .data = data_output};
      /* perform the sum */
      for (i = 0; i < image1->height; ++i) {
         for (j = 0; j < image1->width; ++j) {
            image_output.data[(i * image1->width + j)] = image1->data[(i * image1->width + j)]
                                                         + image1->data[(i * image1->width + j)];
            }
         }
      return(image_output);

   } else {
      printf("Erorr the images dont have the same dimentions");
      exit(1);
   }
}

/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main(void)
{
   struct Image img1 = {};
   struct Image img2 = {};
   struct Image img_sum_gray = {};
   struct Image img_sum = {};
   struct Image img1_gray = {};
   struct Image img2_gray= {};

   img1_gray = read_Image_gray("/home/elsuizo/Images/beagle1.png");
   img2_gray = read_Image_gray("/home/elsuizo/Images/beagle2.png");

   img1 = read_Image("/home/elsuizo/Images/beagle1.png");
   img2 = read_Image("/home/elsuizo/Images/beagle2.png");

   /*-------------------------------------------------------------------------
    *                        color
    -------------------------------------------------------------------------*/
   uchar* data = (uchar*)malloc(sizeof(uchar) * img1.width * img1.height * 3);
   img_sum.data = data;
   img_sum.width = img1.width;
   img_sum.height = img1.height;


   /* uchar* data_output = (uchar*)malloc(sizeof(uchar) * img1_gray.width * img2_gray.height); */
   /* img_sum_gray.data = data_output; */
   /* img_sum_gray.width = img1_gray.width; */
   /* img_sum_gray.height = img1_gray.height; */
   /* printf("img_sum_gray.width: %d\n", img_sum_gray.width); */
   /* printf("img_sum_gray.height: %d\n", img_sum_gray.height); */
   /* img_sum_gray.data = data_output; */
   /* iterator3.at = img_sum_gray.data; */

   /* while ((*iterator1.at++) && (iterator2.at++)) { */
   /*    (*iterator3.at) = (*iterator2.at) + (*iterator1.at); */
   /*    #<{(| printf("valor: %u\n", *iterator3.at); |)}># */
   /* } */
   /*-------------------------------------------------------------------------
    *                        gray
    -------------------------------------------------------------------------*/
   /* uchar* data_gray = (uchar*)malloc(sizeof(uchar) * img1_gray.width * img1_gray.height); */
   /* img_sum_gray.data = data_gray; */
   /* img_sum_gray.width = img1_gray.width; */
   /* img_sum_gray.height = img1_gray.height; */

   /* check if data exist */
   /* if ((img2.data == 0) && (img1.data == 0)) { */
   /*    printf("error!!!"); */
   /*    exit(1); */
   /* } */
   /* #<{(| check if data exist |)}># */
   /* if ((img2_gray.data == 0) && (img1_gray.data == 0)) { */
   /*    printf("error!!!"); */
   /*    exit(1); */
   /* } */

   /*-------------------------------------------------------------------------
    *                        sum images gray
    -------------------------------------------------------------------------*/
   /* for (int i = 0; i < img1_gray.height; ++i) { */
   /*    for (int j = 0; j < img1_gray.width; ++j) { */
   /*       img_sum_gray.data[(i * img1_gray.width + j)] = img1_gray.data[(i * img1_gray.width + j)] */
   /*                                                    + img2_gray.data[(i * img1_gray.width + j)]; */
   /*       } */
   /*    } */

   /*-------------------------------------------------------------------------
    *                        sum images
    -------------------------------------------------------------------------*/
   for (int i = 0; i < img1.height; ++i) {
      for (int j = 0; j < img1.width; ++j) {
         img_sum.data[3 * (i * img1.width + j) + 0] = img1.data[3 * (i * img1.width + j) + 0] + img2.data[3 * (i * img1.width + j) + 0];
         img_sum.data[3 * (i * img1.width + j) + 1] = img1.data[3 * (i * img1.width + j) + 1] + img2.data[3 * (i * img1.width + j) + 1];
         img_sum.data[3 * (i * img1.width + j) + 2] = img1.data[3 * (i * img1.width + j) + 2] + img2.data[3 * (i * img1.width + j) + 2];
      }
   }

   img_sum_gray = sum_Images_gray(&img1_gray, &img2_gray);
   /* save the results */
   write_Image_gray("piola_gray.png", &img_sum_gray);
   write_Image("piola.png", &img_sum);
   /* free!!! */
   stbi_image_free(img1_gray.data);
   stbi_image_free(img2_gray.data);
   /* stbi_image_free(img1.data); */
   /* stbi_image_free(img2.data); */
   stbi_image_free(img_sum_gray.data);
   /* stbi_image_free(img_sum.data); */


   return 0;
}
