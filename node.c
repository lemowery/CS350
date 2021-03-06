#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node* CreateNode(const void* data_to_store){
  // Additional function to create a node
  if (data_to_store == NULL){
    return NULL;
  }
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == NULL){
    return NULL;
  }
  node->data = data_to_store;
  node->previous = NULL;
  node->next = NULL;
  return node;
}
