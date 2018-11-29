// Levi Mowery
// lemowery@mix.wvu.edu
// 800096308

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assignment_4.h"

Queue* CreateQueue(){
  // Constructs a queue
  Queue* q1 = (Queue*) malloc(sizeof(Queue));
  if(q1 == NULL){
    return NULL;
  }
  q1->front = NULL;
  return q1;
}

void DestroyQueue(Queue** q1){
  // Destructs a queue
  // No NULL input
  if (q1 == NULL){
    return;
  }
  while(Dequeue(*q1) != NULL);
  free(*q1);
  *q1 = NULL;
}

void Enqueue(const char* str, Queue* q1){
  // Add item to the queue
  // No NULL inputs
  if(str == NULL || q1 == NULL){
    return;
  }
  Node* new = CreateNode(str);
  if(q1->front == NULL){
    q1->front = new;
    new->next = NULL;
    return;
  }
  Node* current = q1->front;
  while(current->next != NULL){
    current = current->next;
  }
  current->next = new;
}

char* Dequeue(Queue* q1){
  // Dequeue item from front of queue and return the string it held
  // No NULL inputs
  if(q1 == NULL || q1->front == NULL){
    return NULL;
  }
  Node* node = q1->front;
  char* str = node->string;
  q1->front = node->next;
  free(node);
  node = NULL;
  return str;
}

Node* CreateNode(const char* str){
  // Extra function for creating a node
  if(str == NULL){
    return NULL;
  }
  Node* new = (Node*) malloc(sizeof(Node));
  if (new == NULL){
    return NULL;
  }
  new->string = (char*) malloc(strlen(str) + 1 * sizeof(char));
  if (new->string == NULL){
    return NULL;
  }
  strcpy(new->string, str);
  new->next = NULL;
  return new;
}
