/* -------------------------------------------------------------------------
@file list.h

@date 12/03/15 10:32:32
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Linked list declaration
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

#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

/*------------------------------------------------------------------------------
                define a structure for a linked list elements
------------------------------------------------------------------------------*/
typedef struct ListElement_
{
    void                *data;
    struct ListElement_ *next;
}ListElement;

/*------------------------------------------------------------------------------
                    define a structure for a linked list
------------------------------------------------------------------------------*/
typedef struct List_
{
    int size;

    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    ListElement *head;
    ListElement *tail;

}List;

/*------------------------------------------------------------------------------
                            public interface
------------------------------------------------------------------------------*/
// initialize the linked list, size=0, the head and tail poiter to NUL
// this opertion must realized before the list can be used
void list_init(List *list, void (*destroy)(void *data));

// destroy a linked list(removing all elements of the list)
void list_destroy(List *list);

// insert element just after specified element
int list_insert_next(List *list, ListElement *element, const void *data);

//
int list_remove_next(List *list, ListElement *element, void **data);

/*------------------------------------------------------------------------------
                            Macros 
------------------------------------------------------------------------------*/
#define list_size(list) ((list) -> size)
#define list_head(list) ((list) -> head)
#define list_tail(list) ((list) -> tail)
#define list_is_head(list, element) ((element) -> next == NULL ? 1 : 0)
#define list_data(element) ((element) -> data)
#define list_next(element) ((element) -> next)

#endif
