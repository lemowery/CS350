#include "bonus_points.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int IsThereAPath(const int** adjacency_matrix,
		 const int num_nodes,
		 const int source,
		 const int destination){
  // NOT DONE
  if (adjacency_matrix == NULL || source > num_nodes || destination < 1){
    return FALSE;
  }
  Stack* stack = CreateStack();
  int path = FALSE;
  int current = source;
  Push(source, stack);
  while (path = FALSE){
    current = Pop(stack);
    for (int i = 0; i < num_nodes; i++){
      if (*(adjacency_matrix * current + i) == 1){
	if (i = destination){
	  return TRUE;
	}
	Push(*(adjacency_matrix * current + i));
	break;
    }
  }
}

char* DecimalToBinaryString(const int decimal_num);

char** FindUniqueWords(char* string);

int CountPrimeNumbersInRange(int lower, int upper);

int FindSubstring(const char* string, const char* substring);

int CountPairsWithSum(const int* first, const int* last, const int* sum);

Stack* CreateStack(){
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  return stack;
}

void Push(int data_to_store, Stack* stack){
  if (stack == NULL){
    return;
  }
  Node* node = CreateNode(data_to_store);
  if (node == NULL){
    stack->top = node;
    return;
  }
  node->next = stack->top;
  stack->top = node;
}

int Pop(Stack* stack){
  if (stack == NULL){
    return NULL;
  }
  if (stack->top == NULL){
    return NULL;
  }
  Node* node = stack->top;
  int data = node->data;
  free(node);
  node = NULL;
  return data;
}

void DestroyStack(Stack** stack_ptr){
  if (stack_ptr == NULL){
    return;
  }
  while ((*stack_ptr)->top != NULL);
  Pop(*stack_ptr);
  free(*stack_ptr);
  *stack_ptr = NULL;
}

Node* CreateNode(int data){
  Node* node = (Node*) malloc(sizeof(int));
  if (node == NULL){
    return NULL;
  }
  node->data = data;
  node->next = NULL;
}

