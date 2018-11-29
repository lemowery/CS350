#ifndef NODE_H_
#define NODE_H_

typedef struct {
  const void* data;
  struct Node* previous;
  struct Node* next;
} Node;

#endif
