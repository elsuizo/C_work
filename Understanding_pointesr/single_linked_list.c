/* -------------------------------------------------------------------------
@file single_linked_list.c

@date 11/22/16 23:55:26
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

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
                              includes
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

/*-------------------------------------------------------------------------
                              custom types
-------------------------------------------------------------------------*/
typedef struct _employee {
   char name[32];
   uint age;
}Employee;

/* node */
typedef struct _node {
   void* data;
   struct _node* next;
}Node;

/* single linked list */
typedef struct _linked_list {
   Node* head;
   Node* tail;
   Node* current;
}Linked_list;

/* function pointer */
typedef void(*DISPLAY)(void*); /* return void take void* */
typedef int(*COMPARE)(void*, void*); /* return int, take two void* */
/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
int compare_Employee(Employee* e1, Employee* e2);
void display_Employee(Employee* employee);
/* single linked list */
void init_list(Linked_list* list); /* initialize the linked list */
void add_head(Linked_list* list, void* data);
void add_tail(Linked_list* list, void* data);
void delete(Linked_list* list, Node* node); /* remove a node */
Node* get_Node(Linked_list* list, COMPARE compare_func, void* data);
void display_Linked_list(Linked_list* list, DISPLAY display_func); /* display the linked list */

int main(void)
{
   Linked_list linked_list_employees; /* created a linked list of employees */
   /* Samuel */
   Employee* samuel = (Employee*)malloc(sizeof(Employee));
   strcpy(samuel->name, "Samuel");
   samuel->age = 37;
   /* Sally */
   Employee* sally = (Employee*)malloc(sizeof(Employee));
   strcpy(sally->name, "Sally");
   sally->age = 73;
   /* Susan */
   Employee* susan = (Employee*)malloc(sizeof(Employee));
   strcpy(susan->name, "Susan");
   susan->age = 33;

   init_list(&linked_list_employees);

   add_head(&linked_list_employees, samuel);
   add_head(&linked_list_employees, sally);
   add_head(&linked_list_employees, susan);

   /* add_tail(&linked_list_employees, susan); */
   /* add_tail(&linked_list_employees, sally); */
   /* add_tail(&linked_list_employees, samuel); */
   display_Linked_list(&linked_list_employees, (DISPLAY)display_Employee);
   Node* node = get_Node(&linked_list_employees, (int(*)(void*, void*))compare_Employee, sally);

   delete(&linked_list_employees, node);
   display_Linked_list(&linked_list_employees, (DISPLAY)display_Employee);
   return 0;
}

/*-------------------------------------------------------------------------
                              implementation
-------------------------------------------------------------------------*/
int compare_Employee(Employee* e1, Employee* e2) {
   return strcmp(e1->name, e2->name);
}

/**
 * @brief Display the elements of Employee struct
 *
 * @param employee
 */
void display_Employee(Employee* employee) {
   printf("%s\t%d\n", employee->name, employee->age);
}
/* linked list functions */

void init_list(Linked_list* list) {
   list->head     =  NULL;
   list->tail     =  NULL;
   list->current  =  NULL;
}

/**
 * @brief Add data to head
 *
 * @param list
 * @param data
 */
void add_head(Linked_list* list, void* data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   /* the list is empty */
   if(list->head == NULL) {
      list->tail = node;
      node->next = NULL;
   }else {
      node->next = list->head;
   }
   list->head = node;
}

void add_tail(Linked_list* list, void* data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   node->next = NULL;

   if(list->head == NULL) {
      list->head = node;
   } else {
      list->tail->next = node;
   }
   list->tail = node;
}

Node* get_Node(Linked_list* list, COMPARE compare_func, void* data) {
   Node* node = list->head;
   while(node != NULL) {
      if(compare_func(node->data, data) == 0) {
         return node;
      }
      node = node->next;
   }
   return NULL;
}

void delete(Linked_list* list, Node* node) {
   if (node == list->head) {
      /* the list become empty */
      if(list->head->next == NULL) {
         list->head = list->tail = NULL;
      } else {
         list->head = list->head->next;
      }
   } else {
      Node* tmp = list->head;
      while (tmp != NULL && tmp->next != node) {
         tmp = tmp->next;
      }
      if(tmp != NULL) {
         tmp->next = node->next;
      }
   }
   free(node);
}

/**
 * @brief Display the linked list
 *
 * @param list
 * @param display_func
 */
void display_Linked_list(Linked_list* list, DISPLAY display_func) {
   printf("\n---Linked List---\n");
   Node* current = list->head;
   while (current != NULL) {
      display_func(current->data);
      current = current->next;
   }
}
