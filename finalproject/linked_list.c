// Levi Mowery
// 80096308
// lemowery@mix.wvu.edu

#include "linked_list.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

LinkedList* CreateLinkedList(){
  // Linked List constructor
  LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
  if (list == NULL){
    return NULL;
  }
  list->front = NULL;
  pthread_mutex_t* mut = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
  if (mut == NULL){
    return NULL;
  }
  pthread_mutex_init(mut, NULL);
  list->mutex = mut;
  return list;
}
void DestroyLinkedList(LinkedList** l1){
  // Function to destroy linked list
  if (l1 == NULL){
    return;
  }
  // CRITICAL AREA
  pthread_mutex_lock((*l1)->mutex);
  while ((*l1)->front != NULL){
    StringNode* node = (*l1)->front;
    (*l1)->front = node->next;
    free(node);
    node = NULL;
  }
  pthread_mutex_unlock((*l1)->mutex);
  free((*l1)->mutex);
  (*l1)->mutex = NULL;
  free(*l1);
  *l1 = NULL;
  // END CRITICAL
}
int Insert(const char* string, LinkedList* l1){
  // Inserts string into linked list, given
  // it does not already contain the string
  if (string == NULL || l1 == NULL){
    return FALSE;
  }
  if (ListContains(l1, string)){
    return FALSE;
  }
  StringNode* node = CreateNode(string);
  // CRITICAL AREA
  pthread_mutex_lock(l1->mutex);
  if (IsEmpty(l1)){
      l1->front = node;
      pthread_mutex_unlock(l1->mutex);
      return TRUE;
    }
  StringNode* current = l1->front;
  while (current->next != NULL){
    current = current->next;
  }
  current->next = node;
  pthread_mutex_unlock(l1->mutex);
  return TRUE;
  // END CRITICAL
}
int IsEmpty(LinkedList* l1){
  // Checks to see if list is empty
  // TRUE if empty
  // FALSE otherwise
  if (l1 == NULL){
    return FALSE;
  }
  if (l1->front == NULL){
    return TRUE;
  }
  return FALSE;
}
StringNode* CreateNode(const char* string){
  // Function to create a string node
  // No null inputs
  if (string == NULL){
    return NULL;
  }
  StringNode* node = (StringNode*) malloc(sizeof(StringNode));
  if(node == NULL){
    return NULL;
  }
  node->string = (char*) malloc(strlen(string) * sizeof(char));
  if(node->string == NULL){
    free(node);
    node = NULL;
    return NULL;
  }
  strcpy(node->string, string);
  node->next = NULL;
  return node;
}

int strcmpi(const char* str1, const char* str2){
  // Compares tow strings
  // Case insensitive
  // Returns TRUE if the strings match
  // Returns FALSE otherwise
  if  (str1 == NULL || str2 == NULL){
    return FALSE;
  }
  char* new1 = ToLowerStr(str1);
  char* new2 = ToLowerStr(str2);
  if (!strcmp(new1, new2)){
    free(new1);
    free(new2);
    new1 = NULL;
    new2 = NULL;
    return TRUE;
  }
  return FALSE;
}

char* ToLowerStr(const char* str){
  // Returns lowercase copy of string
  if (str == NULL){
    return NULL;
  }
  char* lowerString = (char*) malloc(sizeof(char) * strlen(str));
  if (lowerString == NULL){
    return NULL;
  }
  for (int i = 0; i < strlen(str); ++i){
    *(lowerString + i) = tolower(*(str + i));
  }
  return lowerString;
}

int ListContains(LinkedList* l1, const char* string){
  // Searches list to see if it contains string
  // Returns TRUE if it exists in the list
  // FALSE otherwise
  if (l1 == NULL || string == NULL){
    return FALSE;
  }
  StringNode* node = l1->front;
  while (node != NULL){
      if (strcmpi(node->string, string)){
      return TRUE;
      }
      node = node->next;
    }
  return FALSE;
}
