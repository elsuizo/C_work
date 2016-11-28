/* -------------------------------------------------------------------------
@file queue.c

@date 11/23/16 13:28:37
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Eejemplo de una queue hecha con una lista enlazada simple
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
typedef struct _document {
   char* name;
   char* path;
   int   size;
}Document;

/**
 * @brief Node struct
 * data: is the data contain in the Node
 * next: point to the next Node
 */
typedef struct _node {
   void* data;
   struct _node* next;
}Node;

/**
 * @brief Single linked list
 * head: Node point to the head of the list
 * tail: Node point to the tail of the list
 * current: Node point to the current Node
 */
typedef struct _slinked_list {
   Node* head;
   Node* tail;
   Node* current;
}Slinked_list;

typedef Slinked_list Queue;
/**
 * @brief function pointer for point to funtions to display a custom data type
 *
 * @param custom data type
 */
typedef void(*DISPLAY)(void*);

/**
 * @brief function pointer point to functions to compare custom data types
 *
 * @param pointers to custom data types
 *
 * @return 1, -1, 0
 */
typedef int(*COMPARE)(void*, void*);

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
/* Documents functions */
int compare_Documents(Document* d1, Document* d2);
void display_Documents(Document* document);
void deallocate_Documents(Document* document);
void init_Document(Document* document, const char* name, const char* path, int size);
/* linked list functions */
void init_Slinked_list(Slinked_list* list);
void add_head(Slinked_list* list, void* data);
void add_tail(Slinked_list* list, void* data);
void delete_Node(Slinked_list* list, Node* node);
Node* get_Node(Slinked_list* list, COMPARE compare_func, void* data);
void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name);
/* queue functions */
void init_Queue(Queue* queue);
void enqueue(Queue* queue, void* node);
void* dequeue(Queue* queue);

/*-------------------------------------------------------------------------
                              main
-------------------------------------------------------------------------*/
int main(void)
{
   Queue document_queue;
   init_Queue(&document_queue);
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
   enqueue(&document_queue, document1);
   enqueue(&document_queue, document2);
   enqueue(&document_queue, document3);

   display_Slinked_list(&document_queue, (DISPLAY)display_Documents, "Documents");
   void* data_out = dequeue(&document_queue);
   printf("Dequeue:%s\n", ((Document*)data_out)->name);
   display_Slinked_list(&document_queue, (DISPLAY)display_Documents, "Documents");

   /* free the pointers */
   deallocate_Documents(document1);
   deallocate_Documents(document2);
   deallocate_Documents(document3);
   free(document1);
   free(document2);
   free(document3);

   return 0;
}

/*-------------------------------------------------------------------------
                              implementations
-------------------------------------------------------------------------*/
void init_Document(Document* document, const char* name, const char* path, int size) {
   /* set name */
   document->name = (char*)malloc(strlen(name) + 1);
   strcpy(document->name, name);
   /* set path */
   document->path = (char*)malloc(strlen(path) + 1);
   strcpy(document->path, path);
   /* set size */
   document->size = size;
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
   if (list->head == NULL) {
      list->tail = node;
      node->next = NULL;
   } else {
      node->next = list->head;
   }
   list->head = node;
}

void add_tail(Slinked_list* list, void* data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   node->next = NULL; /* condition for add tail */
   /* list empty */
   if (list->head == NULL) {
      list->head = node;
   } else {
      list->tail->next = node;
   }
   list->tail = node;
}

Node* get_Node(Slinked_list* list, COMPARE compare_func, void* data) {
   /* go to the firs element of the list */
   Node* node = list->head;
   /* iterate over nodes */
   while(node != NULL) {
      /* compare all data nodes to data */
      if(compare_func(node->data, data) == 0) {
         /* return the node match */
         return node;
      }
      /* point to next element for continuing iterating */
      node = node->next;
   }
   /* the node is not on the list */
   return NULL;
}

void delete_Node(Slinked_list* list, Node* node) {
   if(node == list->head) {
      /* the list become empty */
      if (list->head->next == NULL) {
         list->head = list->tail = NULL;
      } else {
         list->head = list->head->next;
      }
   } else {
      Node* tmp = list->head;
      while(tmp != NULL && tmp->next != node){
         tmp = tmp->next;
      }
      if(tmp != NULL) {
         tmp->next = node->next;
      }
   }
   free(node);
}

/**
 * @brief display the data in the single linked list
 *
 * @param list
 * @param display_func
 * @param name
 */
void display_Slinked_list(Slinked_list* list,
      DISPLAY display_func,
      char* name ) {
   printf("\n---%s---\n", name);
   Node* current = list->head;
   while(current != NULL) {
      display_func(current->data);
      current = current->next;
   }

}

/**
 * @brief initilize the Queue
 *
 * @param queue
 */
void init_Queue(Queue* queue) {
   init_Slinked_list(queue);
}

/**
 * @brief push element in the Queue
 *
 * @param queue
 * @param node
 */
void enqueue(Queue* queue, void* node) {
   add_head(queue, node);
}

/**
 * @brief Pop element from queue
 *
 * @param queue
 *
 * @return the element popped
 */
void* dequeue(Queue* queue) {
   Node* tmp = queue->head;
   void* data;
   if(queue->head == NULL) {
      data = NULL;
   } else if(queue->head == queue->tail) {
      queue->head = queue->tail = NULL;
      data = tmp->data;
      free(tmp);
   } else {
      while(tmp->next != queue->tail) {
         tmp = tmp->next;
      }
      queue->tail = tmp;
      tmp = tmp->next;
      queue->tail->next = NULL;
      data = tmp->data;
      free(tmp);
   }
   return data;
}

