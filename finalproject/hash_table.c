// Levi Mowery
// 800096308
// lemowery@mix.wvu.edu

#include "hash_table.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

HashTable* CreateHashTable(){
  // Initializes HashTable
  HashTable* table = (HashTable*) malloc(sizeof(HashTable));
  if (table == NULL){
    return NULL;
  }
  table->keys = "abcdefghijklmnopqrstuvwxyz";
  table->values = (LinkedList**) malloc(26 * sizeof(LinkedList));
  if(table->values == NULL){
    return NULL;
  }
  for (int i = 0; i < 26; ++i){
    (table->values)[i] = CreateLinkedList();
  }
  return table;
}

void DestroyHashTable(HashTable** table){
  // Destroys a HashTable
  if(table == NULL){
    return;
  }
  for (int i = 0; i < 26; ++i){
    DestroyLinkedList(&((*table)->values[i]));
  }
  free((*table)->values);
  (*table)->values = NULL;
  (*table)->keys = NULL;
  free(*table);
  *table = NULL;
}

int Put(const char* string, HashTable* table){
  // Inserts string into table under the appropriate key
  if (string == NULL || table == NULL){
    return FALSE;
  }
  int index = GetIndex(tolower(*string));
  if(Insert(string, (table->values)[index])){
    return TRUE;
  }
  return FALSE;
}

LinkedList* GetList(char key, HashTable* table){
  // Returns appropriate linked list, given key
  if (table == NULL){
    return NULL;
  }
  return table->values[GetIndex(key)];
}

pthread_mutex_t* GetMutex(char key, HashTable* table){
  // Returns mutex of list of given key
  if (table == NULL){
    return NULL;
  }
  LinkedList* list = GetList(key, table);
  return list->mutex;
}

int GetIndex(char key){
  // Returns index of given key
  char* keys = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  while (i < 26){
    if (keys[i] == tolower(key)){
      return i;
    }
    ++i;
  }
  return -1;
}
