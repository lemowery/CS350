#include "double_linked_list.h"

//1. Construct a linked list
DoubleLinkedList* CreateDoubleLinkedList(){
  DoubleLinkedList* list = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
  if (list == NULL){
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}
//2. Destructor
void DestroyDoubleLinkedList(DoubleLinkedList**);
//3. Add element
void Add(const coid* data, const int index, DoubleLinkedList* list){
  if (data == NULL || index < 0 || index > list->size || list == NULL){
    return;
  }
  Node* node = CreateNode(data);
  if (node == NULL){
    return;
  }
    // 1. Inserting at the begining of list
  if (index == 0){
    // 1.a List is empty
    if (list->size == 0){
      list->head = node;
      list->tail = node;
      ++(list->size);
      return;
    }
    // 1.b List is not empty
    list->head->previous = node;
    node->next = list->head;
    list->head = node;
    ++(list->size);
    return;
  }
  // 2. Inserting at the end
  if (index == list->size){
    list->tail->next = node;
    node->previous = list->tail;
    list->tail = node;
    ++(list->size);
    return;
  }
  // 3. Inserting in the middle
  int current_idx = 0;
  for (Node* current = list->head; current_idx < index; ++current_idx){
    current = current->next;
  }
  node->previous = current->previous;
  node->previous->next = node;
  node->next = current;
  current->previous = node;
  }
//4. Remove element
const void* Remove(const int index, DoubleLinkedList* list){
  if(list == NULL || index < 0 || index >= list->size){
    return NULL;
  }
  //1. Delete node at the begining
  if(index == 0){
    Node* temp = list->head;
    list->head = temp->next;
    list->head->previous = NULL;
    temp->next = NULL;
    const void* data = temp->data;
    free(temp);
    --(list->size);
    retrun data;
  }
  //2. Delete a node at the end
  if(index == (list->size) - 1){
    Node* temp = list->tail;
    list->tail = temp->previous;
    list->tail->next = NULL;
    temp->previous = NULL;
    const void* data = temp->data;
    free(temp);
    --(list->size);
    return data;
  }
  //3. Removing from the middle
  Node* node = GetNode(index, list);
  Node* previous = node->previous;
  Node* next = node->next;
  previous->next = next;
  next->previous = previous;
  node->next = NULL;
  node->previous = NULL;
  const void* data = node->data;
  free(node);
  --(list->size);
  return data;
}
