// Levi Mowery
// 800096308
// lemowery@mix.wvu.edu

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#define TRUE 1
#define FALSE 0

#include <pthread.h>

typedef struct StringNode{
  char* string;
  struct StringNode* next;
} StringNode;

typedef struct LinkedList{
  StringNode* front;
  pthread_mutex_t* mutex;
} LinkedList;

LinkedList* CreateLinkedList();
void DestroyLinkedList(LinkedList** l1);
int Insert(const char* string, LinkedList* l1);
int IsEmpty(LinkedList* l1);
StringNode* CreateNode(const char* string);
int strcmpi(const char* str1, const char* str2);
char* ToLowerStr(const char* str);
int ListContains(LinkedList* l1, const char* string);

#endif
