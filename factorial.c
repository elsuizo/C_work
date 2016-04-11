/* -------------------------------------------------------------------------
@file factorial.c

@date 04/09/16 13:48:29
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Implementation of factorial using recursive approach
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

#include<stdio.h>
int fact(int n)
{
    // Compute the factorial of n recusively
    if(n < 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int n      = 7;
    int result = 0;

    result = fact(n);
    printf("The factorial of: %d = %d\n", n, result);

    return 0;
}

