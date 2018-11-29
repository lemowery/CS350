#include <stdio.h>
#include "stack.h"

int main(){
  // Create stack
  Stack* stack = CreateStack();
  if (stack == NULL){
    fprintf(stderr, "Could not create stack.\n");
  }

  stack = CreateStack();
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
  for (int i = 0; i < 8; ++i){
    Push(&number[i], stack);
  }
  for (int i = 7; i >= 0; --i){
    int* value = (int*) Pop(stack);
    if(numbers[i] != *value){
      fprintf(stderr, "Values mismatch\n.");
    }
  }
  char* str = "hello";
  Push(str, stack);
  puts((char*)Pop(stack));
  DestroyStack(&stack);
  }
  
