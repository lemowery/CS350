/*
Levi Mowery
lemowery@mix.wvu.edu
800096308
 */
#ifndef BONUS_POINTS_H_
#define BONUS_POINTS_H_

#define TRUE 1
#define FALSE 0

typedef struct Node{
  int data;
  struct Node* next;
} Node;

typedef struct Stack{
  Node* top;
} Stack;

int IsThereAPath(const int** adjacency_matrix,
		 const int num_nodes,
		 const int source,
		 const int destination);

char* DecimalToBinaryString(const int decimal_num);

char** FindUniqueWords(char* string);

int CountPrimeNumbersInRange(int lower, int upper);

int FindSubstring(const char* string, const char* substring);

int CountPairsWithSum(const int* first, const int* last, const int* sum);

Stack* CreateStack();

void DestroyStack(Stack** stack_ptr);

void Push(int data_to_store, Stack* stack);

int Pop(Stack* stack);

Node* CreateNode(int data);

#endif
