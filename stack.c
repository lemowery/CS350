#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/*
Node* CreateNode(const void* data_to_store){
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == NULL){
    return NULL;
  }
  node->data = data_to_store;
  node->previous = NULL;
  return node;
}
*/

Stack* CreateStack(){
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  return stack;
}

void Push(const void* data_to_store, Stack* stack){
  if (stack == NULL || data_to_store == NULL){
    return;
  }
  // If it is empty
  if (stack->top == NULL){
    Node* node = CreateNode(data_to_store);
    node->data = data_to_store;
    node->previous = NULL;
    stack->top = node;
    return;
  }
  // Stack not empty
  // top-> new element
  // new element  -> previous 
  Node*node = (Node*) malloc(sizeof(Node));
  node->previous = stack->top;
  stack->top = node;
}

int Pop(Stack* stack){
  if (stack == NULL){
    return NULL;
  }
  // Case 1: empty stack
  if (stack->top == NULL){
    return NULL;
  }
  Node* node = stack->top;
  stack->top = node->previous;
  int data = node->data;
  free(node);
  node = NULL;
  return data;
}

void DestroyStack(Stack** stack_ptr){
  if (stack_ptr == NULL){
    return;
  }
  while (Pop(*stack_ptr) != NULL);
  free(*stack_ptr);
  *stack_ptr = NULL;
}
