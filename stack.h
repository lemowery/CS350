#ifndef STACK_H_
#define STACK_H_

#include "node.h"

typedef struct {
  // Generic pointer to the top
  Node* top;
} Stack;

Stack* CreateStack();
void DestroyStack(Stack** stack_ptr);
void Push(const void* data_to_store, Stack* stack);
const void* Pop(Stack* stack);


#endif
