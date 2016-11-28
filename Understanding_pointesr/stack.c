/* -------------------------------------------------------------------------
@file stack.c

@date 11/23/16 21:50:40
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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<ctype.h>
#include "utils.h"

/*-------------------------------------------------------------------------
                              custom types
-------------------------------------------------------------------------*/
typedef struct _document {
   char* name;
   char* path;
   int   size;
}Document;

typedef struct _node {
   void* data;
   struct _node* next;
}Node;

typedef struct _slinked_list {
   Node* head;
   Node* tail;
   Node* current;
}Slinked_list;

typedef Slinked_list Stack;

typedef void(*DISPLAY)(void*);

typedef int(*COMPARE)(void*, void*);

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
/* Documents functions */
int compare_Documents(Document* d1, Document* d2);
void display_Documents(Document* document);
void deallocate_Documents(Document* document);
void init_Document(Document* d, const char* name, const char* path, int size);
/* linked list functions */
void init_Slinked_list(Slinked_list* list);
void add_head(Slinked_list* list, void* data);
void add_tail(Slinked_list* list, void* data);
void delete_Node(Slinked_list* list, Node* node);
Node* get_Node(Slinked_list* list, COMPARE compare_func, void* data);
void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name);
/* Stack functions */
void init_Stack(Stack* stack);
void push(Stack* stack, void* data);
void* pop(Stack* stack);

/*-------------------------------------------------------------------------
                              main
-------------------------------------------------------------------------*/
int main(void)
{
   Stack documents_stack;

   init_Stack(&documents_stack);
   /* add somes Documents */
   /* document1 */
   Document* document1 = (Document*)malloc(sizeof(Document));
   init_Document(document1, "baboon.jpg", "/home/elsuizo/Images", 173);
   /* document2 */
   Document* document2 = (Document*)malloc(sizeof(Document));
   init_Document(document2, "lena.png", "/home/elsuizo/Images", 273);
   /* document3 */
   Document* document3 = (Document*)malloc(sizeof(Document));
   init_Document(document3, "paper.pdf", "/home/elsuizo/Dropbox", 137);
   push(&documents_stack, document1);
   push(&documents_stack, document2);
   push(&documents_stack, document3);

   display_Slinked_list(&documents_stack, (DISPLAY)display_Documents, "Documents");
   void* data_out = (Document*)pop(&documents_stack);
   printf("Document pop:%s\n", ((Document*)data_out)->name);
   display_Slinked_list(&documents_stack, (DISPLAY)display_Documents, "Documents");

   /* free the pointers */
   deallocate_Documents(document1);
   deallocate_Documents(document2);
   deallocate_Documents(document3);
   free(document1);
   free(document2);
   free(document3);
   return 0;
}

void init_Document(Document* d, const char* name, const char* path, int size) {
   /* set name */
   d->name = (char*)malloc(strlen(name) + 1);
   strcpy(d->name, name);
   /* set path */
   d->path = (char*)malloc(strlen(path) + 1);
   strcpy(d->path, path);
   /* set size */
   d->size = size;
}

int compare_Documents(Document* d1, Document* d2) {
   return strcmp(d1->name, d2->name);
}

void display_Documents(Document* document) {
   printf("%s\t%s\t%d\n", document->name, document->path, document->size);
}

void deallocate_Documents(Document* document) {
   free(document->name);
   free(document->path);
}

void init_Slinked_list(Slinked_list* list) {
   list->head     =  NULL;
   list->tail     =  NULL;
   list->current  =  NULL;
}

void add_head(Slinked_list* list, void* data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   /* the list is empty */
   if(list->head == NULL) {
      list->tail = node;
      node->next = list->head;
   }else {
      node->next = list->head;
   }
   list->head = node;
}

void add_tail(Slinked_list* list, void* data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   node->next = NULL; /* condition fo add tail */
   /* list is empty */
   if(list->head == NULL) {
      list->head = node;
   } else {
      list->tail->next = node;
   }
   list->tail = node;
}

Node* get_Node(Slinked_list* list, COMPARE compare_func, void* data) {
   /* go to the first element of the list */
   Node* node = list->head;
   /* iterate over nodes */
   while (node != NULL) {
      if (compare_func(node->data, data) == 0) {
         /* return the Node match */
         return node;
      }
      /* point to the next element for keep iterating */
      node = node->next;
   }
   /* the node is not in the list */
   return NULL;
}

void delete_Node(Slinked_list* list, Node* node) {
   if (node == list->head) {
      /* the list go to empty */
      if (list->head->next == NULL) {
         list->head = list->tail = NULL;
      } else {
         list->head = list->head->next;
      }
   } else {
      Node* tmp = list->head;
      while (tmp != NULL && tmp->next != node) {
         tmp = tmp->next;
      }
      if (tmp != NULL) {
         tmp->next = node->next;
      }
   }
   free(node);
}

void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name) {
   printf("\n =======%s=======\n", name);
   Node* current = list->head;
   while(current != NULL) {
      display_func(current->data);
      current = current->next;
   }

}

void init_Stack(Stack* stack) {
   init_Slinked_list(stack);
}

void push(Stack* stack, void* data) {
   add_head(stack, data);
}

void* pop(Stack* stack) {
   Node* node = stack->head;
   if (node == NULL) {
      return NULL;
   } else if (node == stack->tail){
      stack->head = stack->tail = NULL;
      void* data = node->data;
      free(node);
      return data;
   } else {
      stack->head = stack->head->next;
      void* data = node->data;
      free(node);
      return data;
   }

}

