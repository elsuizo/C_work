/* -------------------------------------------------------------------------
@file map_range.c

@date 10/27/16 21:58:20
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
funcion para mapear rango de valores en otro rango.
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

double mapRange(double a1,double a2,double b1,double b2,double s)
{
	return b1 + (s-a1)*(b2-b1)/(a2-a1);
}

int main()
{
	int i;
	puts("Mapping [0,10] to [-1,0] at intervals of 1:");
 
	for(i=0;i<=10;i++)
	{
		printf("f(%d) = %g\n",i,mapRange(0,10,-1,0,i));
	}
 
	return 0;
}

