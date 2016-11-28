/* -------------------------------------------------------------------------
@file utils.h

@date 10/30/16 19:18:07
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Macros and definitions utils
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
#ifndef _UTILS_
#define _UTILS_

/*-------------------------------------------------------------------------
                        defines
-------------------------------------------------------------------------*/
#define printf_dec_format(x) _Generic((x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")

#define print(x) printf(printf_dec_format(x), x)
#define printnl(x) printf(printf_dec_format(x), x), printf("\n");


/* number of elements in array */
#define ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

#define safeFree(p) safer_free((void**)&(p))

#define  STD_OK         0
#define  STD_ERR        -1
#define  STD_NOT_FOUND  -2
/*-------------------------------------------------------------------------
                        macros
-------------------------------------------------------------------------*/
/* print elements of a array(ints) */
#define PRINT_ARRAY_INTS(array) \
for(int i = 0; i < (int)ARRAY_SIZE(array); i++) \
    printf("%d\n", array[i]);

/* print elements of a array(floats)*/
#define PRINT_ARRAY_FLOATS(array) \
for(int i = 0; i < (int)ARRAY_SIZE(array); i++) \
    printf("%f\n", array[i]);

#define PRINT_ARRAY_CHARS(array) \
for(int i = 0; i < (int)ARRAY_SIZE(array); i++) \
    printf("%c\n", array[i]);

/*-------------------------------------------------------------------------
                        global data types
-------------------------------------------------------------------------*/
typedef enum{FALSE, TRUE}bool_t;
typedef unsigned int uint;

#endif
