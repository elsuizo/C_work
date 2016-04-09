/* -------------------------------------------------------------------------
@file generic_swap.c

@date 04/05/16 10:10:15
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
This program show how with generic pointers we can use for generic input
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

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int swap(void *x, void *y, int size)
{
    void *tmp;
    if((tmp = malloc(size)) == NULL)
        return -1;

    memcpy(tmp, x, size); memcpy(x, y, size); memcpy(y, tmp, size);
    free(tmp);

    return 0;
}


int main()
{
    int s;
    int a = 3;
    int b = 7;
    printf("a:%d\n", a);
    printf("b:%d\n", b);
    s = sizeof(s);
    swap(&a, &b, s);
    printf("a:%d\n", a);
    printf("b:%d\n", b);
}
