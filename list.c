/* -------------------------------------------------------------------------
@file list.c

@date 04/12/16 22:18:33
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Implementation of a linked list datatype
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
#include"list.h"

/*------------------------------------------------------------------------------
                                list_init
------------------------------------------------------------------------------*/
void list_init(List *list, void (*destroy)(void *data))
{
    // initialize the list
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return ;
}

/*------------------------------------------------------------------------------
                                list_destroy
------------------------------------------------------------------------------*/
void list_destroy(List *list)
{
    void *data;

    // remove each element of the list
    while(list_size(list) > 0)
    {
        if(list_remove_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
        {
            // call a user-defined function to free dinamically allocated data
            list->destroy(data);
        }
    }
    // no operation is allowed now, but clear the structure  as precaution
    memset(list, 0, sizeof(list));

    return ;
} 

/*------------------------------------------------------------------------------
                            list_ins_next
------------------------------------------------------------------------------*/

int list_insert_next(List *list, ListElement *element, const void *data)
{
    ListElement *new_element;
    // allocated storage for the element
    if((new_element = (ListElement *)malloc(sizeof(ListElement))) == NULL)
        return -1;

    // insert the element into the list
    new_element->data = (void *)data;

    if(element == NULL)
    {
        // handle insertion at the head of the list
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        // handle insertion somewhere other that the head
        if(element->next == NULL)
            list->tail = new_element;
        
        new_element->next = element->next;
        element->next = new_element;

    }
    // adjust the size of the list to account for  the inserted element
    list->size++;

    return 0;
}


/*------------------------------------------------------------------------------
                            list_remove_next
------------------------------------------------------------------------------*/
int list_remove_next(List *list, ListElement *element, void **data)
{
    ListElement *old_element;
    // do not allow removal from an empty list
    
    if(list_size(list) == 0)
        return -1;

    // remove the element from the list
    if(element == NULL)
    {
        // handle removal from the head of the list
        *data = list->head->data; // put the data in the head
        old_element = list->head;
        list->head = list->head->next;

        if(list_size(list) == 1)
            list->tail = NULL;
    }     
    else
    {
        // handle removal from somewhere other than the head
        if(element->next == NULL)
            return -1;

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if(element->next == NULL)
            list->tail = element;
    }


    // free the storage allocated by the  abstract datatype
    free(old_element);
    // adjust the size of list to account for the removed element
    list->size--;

    return 0;
}


