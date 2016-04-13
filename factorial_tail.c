/* -------------------------------------------------------------------------
@file factrorial_tail.c

@date 04/09/16 17:51:03
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Implementation of the factorial function with a tail recursion
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

//-------------------------------------------------------------------------
//      fact_tail() 
//-------------------------------------------------------------------------
unsigned int fact_tail(unsigned int n, unsigned int a)
{
    //-------------------------------------------------------------------------
    //      Compute the factorial of n in a tail-recursive manner
    //-------------------------------------------------------------------------
    if(n < 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(n == 1)
        return a;
    else
        return fact_tail(n - 1, n * a);

}

unsigned int main()
{
    unsigned int N = 100;
    unsigned int a = 1;
    unsigned int result = 0;
    result = fact_tail(N, a);
    // NOTE(put the fucking \n in prunsigned intf)
    printf("the factorial of: %u is %u\n", N, result);

    return 0;
}

