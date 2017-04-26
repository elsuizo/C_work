/* -------------------------------------------------------------------------
@file temps.c

@date 04/26/17 13:07:13
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Como resultado de un experimento un laboratorio obtuvo 18 valores de temperatura,
todos distintos de cero. Se debe realizar un programa para ingresar dichos
valores y luego determinar e informar:

a) La mayor temperatura ingresada y cual fue su número de orden durante el ingreso.

b) Ídem para la menor temperatura.

c) El promedio de las temperaturas negativas. Si no hubiera temperaturas negativas indicarlo con un cartel aclaratorio.

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
#include <ctype.h>

struct Temperatures {
   int* data;
   int data_length;
   int indice_max;
   int indice_min;
   float mean;
};

static void
print_temps(struct Temperatures* temps) {
   int i;
   for (i = 0; i < temps->data_length; i++) {
      printf("temperatura: %d ---> %d\n", i, temps->data[i]);
   }
}
int main(void)
{
   const int numero_muestras = 18;
   int i = 0;
   struct Temperatures temps = {};
   temps.data = (int*)malloc(sizeof(int) * numero_muestras);
   printf("ingrese los valores de las temperaturas: \n");
   /* ingresa las temperaturas hasta 18 esta permitidas
    * notemos que en C se comienza a contar desde cero*/
   for (i = 0; i < numero_muestras; i++) {
      scanf("%d", &temps.data[i]);
   }
   temps.data_length = i;
   print_temps(&temps);
   free(temps.data);
   return 0;
}



