// Levi Mowery
// 800096308
// lemowery@mix.wvu.edu
#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "linked_list.h"

typedef struct HashTable{
  char* keys;
  LinkedList** values;
} HashTable;

HashTable* CreateHashTable();
void DestroyHashTable(HashTable** table);
int Put(const char* string, HashTable* table);
LinkedList* GetList(char key, HashTable* table);
pthread_mutex_t* GetMutex(char key, HashTable* table);
int GetIndex(char key);

#endif
