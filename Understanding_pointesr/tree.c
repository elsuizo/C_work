/* -------------------------------------------------------------------------
@file tree.c

@date 11/24/16 13:35:56
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Ejemplo de arbol binario, construccion basada en una lista enlazada simple. Tambien las maneras de recorrer el arbol. Para este
caso cuando se visita el nodo se imprimen sus datos.
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
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include "utils.h"

/*-------------------------------------------------------------------------
                              typedefs
-------------------------------------------------------------------------*/

/**
 * @brief Tree struct: modelling a tree datatype
 */
typedef struct _tree_node {
   void* data;
   struct _tree_node* left;
   struct _tree_node* right;
}Tree_node;

/**
 * @brief Document struct: modelling a file Document
 * name: name string
 * path: absolute path string
 * size: size of the document(bytes)
 */
typedef struct _document {
   char* name;
   char* path;
   int   size;
}Document;

/**
 * @brief Node: node for the linked list data type
 */
typedef struct _node {
   void* data;
   struct _node* next;
}Node;

/**
 * @brief Slinked_list: single linjked list data type
 */
typedef struct _slinked_list {
   Node* head;
   Node* tail;
   Node* current;
}Slinked_list;

/**
 * @brief DISPLAY: function pointer to point to function for display a custom data type
 *
 * @param custom data type
 */
typedef void(*DISPLAY)(void*);

/**
 * @brief function pointer point to functions to compare custom data types
 *
 * @param pointers to custom data type
 *
 * @return: 1, -1, 0
 */
typedef int(*COMPARE)(void*, void*);

/*-------------------------------------------------------------------------
                              prototypes
-------------------------------------------------------------------------*/
/* Documents function */
int compare_Documents(Document* d1, Document* d2);
void display_Documents(Document* document);
void deallocate_Documents(Document* document);
void init_Document(Document* d, const char* name, const char* path, int size);

/* linked list prototypes */
void init_Slinked_list(Slinked_list* list);
void add_head(Slinked_list* list, void* data);
void add_tail(Slinked_list* list, void* data);
void delete_Node(Slinked_list* list, Node* node);
Node* get_Node(Slinked_list* list, COMPARE compare_func, void* data);
void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name);

/* tree functions */
void insert_Tree_node(Tree_node** root, COMPARE compare_func, void* data);
void in_order(Tree_node* root, DISPLAY display_func);
void post_order(Tree_node* root, DISPLAY display_func);
void pre_order(Tree_node* root, DISPLAY display_func);

/*-------------------------------------------------------------------------
                              main
-------------------------------------------------------------------------*/
int main(void)
{
   Tree_node* tree = NULL;

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
   /* document4 */
   Document* document4 = (Document*)malloc(sizeof(Document));
   init_Document(document4, "hola_mundo.py", "/home/elsuizo/Dropbox", 137);

   insert_Tree_node(&tree, (COMPARE)compare_Documents, document1);
   insert_Tree_node(&tree, (COMPARE)compare_Documents, document2);
   insert_Tree_node(&tree, (COMPARE)compare_Documents, document3);
   insert_Tree_node(&tree, (COMPARE)compare_Documents, document4);

   pre_order(tree, (DISPLAY)display_Documents);
   in_order(tree, (DISPLAY)display_Documents);
   pre_order(tree, (DISPLAY)display_Documents);


   /*-------------------------------------------------------------------------
                              free memory
   -------------------------------------------------------------------------*/
   /* free the pointers */
   deallocate_Documents(document1);
   deallocate_Documents(document2);
   deallocate_Documents(document3);
   free(document1);
   free(document2);
   free(document3);
   free(document4);
   return 0;
}

void init_Document(Document* d, const char* name, const char* path, int size) {
   /* set name */
   d->name = (char*)malloc(strlen(name) + 1);
   strcpy(d->name, name);
   /* set path */
   d->path = (char*)malloc(strlen(path) + 1);
   strcpy(d->path, path);
   /* set size  */
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
   if (node == NULL) {
      printf("Failed to allocate memory\n");
   }
   node->data = data;
   /* the list become empty */
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
   node->next = NULL;
   /* list empty */
   if (list->head == NULL) {
      list->head = node;
   } else {
      list->tail->next = node;
   }
   list->tail = node;
}

/**
 * @brief:
 *
 * @param list
 * @param compare_func
 * @param data
 *
 * @return 
 */
Node* get_Node(Slinked_list* list, COMPARE compare_func, void* data) {
   /* go to the first element of the list */
   Node* node = list->head;
   /* iterate over nodes */
   while (node != NULL) {
      /* compare all the data nodes to data */
      if (compare_func(node->data, data) == 0) {
         /* return the match node */
         return node;
      }
      /* point to the next element for continuing iterating */
      node = node->next;
   }
   /* the node is not on the list */
   return NULL;
}

/**
 * @brief:
 *
 * @param list
 * @param node
 */
void delete_Node(Slinked_list* list, Node* node) {
   if (node == list->head) {
      /* the list become empty */
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

/**
 * @brief: Display the elements of the single linked list.
 *
 * @param list: Single linked list
 * @param display_func: function pointer to display the data
 * @param name: Name of the linked list for printing
 */
void display_Slinked_list(Slinked_list* list, DISPLAY display_func, char* name) {
   printf("\n =======%s=======\n", name);
   Node* current = list->head;
   while (current != NULL) {
      display_func(current->data);
      current = current->next;
   }
}

/*-------------------------------------------------------------------------
  En ese caso necesitamos un puntero a puntero ya que queremos cambiar el puntero  que le pasamos a la funcion.
-------------------------------------------------------------------------*/
void insert_Tree_node(Tree_node** root, COMPARE compare_func, void* data) {
   /* create the node */
   Tree_node* node = (Tree_node*)malloc(sizeof(Tree_node));
        node->data = data;
        node->left = NULL;
       node->right = NULL;

   /* if the the tree is empty add the node root */
   if (*root == NULL) {
    *root = node;
    return;
   }
   while(TRUE) {
      if (compare_func((*root)->data, data) > 0) {
         if ((*root)->left != NULL) {
            /* NOTE:en este caso *root es un puntero ya que root es un puntero a puntero */
            *root = (*root)->left;
         } else {
            (*root)->left = node;
            break;
         }
      } else {
         if ((*root)->right != NULL) {
            *root = (*root)->right;
         } else {
            (*root)->right = node;
            break;
         }
      }
   }
}

/**
 * @brief Trasverse the tree in order
 *
 * @param root:
 * @param display_func:
 */
void in_order(Tree_node* root, DISPLAY display_func) {
   if (root != NULL) {
      in_order(root->left, display_func);
      display_func(root->data);
      in_order(root->right, display_func);
   }
}

/**
 * @brief: Trasverse the tree in post_order
 *
 * @param root
 * @param display_func
 */
void post_order(Tree_node* root, DISPLAY display_func) {
   if (root != NULL) {
      post_order(root->left, display_func);
      post_order(root->right, display_func);
      display_func(root->data);
   }
}

/**
 * @brief: Trasverse the tree in pre-order
 *
 * @param root
 * @param display_func
 */
void pre_order(Tree_node* root, DISPLAY display_func) {
    if (root != NULL) {
       display_func(root->data);
       pre_order(root->left, display_func);
       pre_order(root->right, display_func);
    }
}
