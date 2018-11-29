#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "linked_list.h"

#define NUM_LETTERS 26

int main() {
  // 1. Create hash table and destroy it.
  HashTable* table = CreateHashTable();
  if (table == NULL) {
    puts("ERROR: Could create hash table.");
    return 1;
  }
  DestroyHashTable(&table);
  if (table != NULL) {
    puts("ERROR: Table was not set to NULL.");
    return 1;
  }
  // 2. Insert words into the table.
  table = CreateHashTable();
  if (table == NULL) {
    puts("ERROR: Could create hash table.");
    return 1;
  }
  const char* unique_str[] = {"String 1", "Word", "Test", "longer"};
  const int size = sizeof(unique_str) / sizeof(unique_str[0]);
  for (int i = 0; i < size; ++i) {
    if (!Put(unique_str[i], table)) {
      printf("ERROR: Could not insert string [%s]\n", unique_str[i]);
    }
  }
  DestroyHashTable(&table);
  if (table != NULL) {
    puts("ERROR: Table was not set to NULL.");
    return 1;
  }
  // 3. Repeated words.
  const char* repeated_str[] = {"String", "strinG", "Word", "WoRd"};
  table = CreateHashTable();
  if (!Put(repeated_str[0], table)) {
    printf("ERROR: Unable to insert string: [%s] \n", repeated_str[0]);
  }
  if (!Put(repeated_str[2], table)) {
    printf("ERROR: Unable to insert string: [%s] \n", repeated_str[2]);
  }  
  if (Put(repeated_str[1], table)) {
    printf("ERROR: Inserted duplicate string: [%s].\n",
           repeated_str[1]);
  }
  if (Put(repeated_str[3], table)) {
    printf("ERROR: Inserted duplicate string: [%s].\n",
           repeated_str[3]);
  }
  // 3.a. Test that the Table is constructed correctly.
  LinkedList* list = GetList(repeated_str[0][0], table);
  
  if (IsEmpty(list)) {
    printf("ERROR: List must not be empty for character %c.",
           repeated_str[0][0]);
  }
  list = GetList(repeated_str[2][0], table);
  if (IsEmpty(list)) {
    printf("ERROR: List must not be empty for character %c.",
           repeated_str[2][0]);
  }
  const int index_for_s = GetIndex(repeated_str[0][0]);
  const int index_for_w = GetIndex(repeated_str[2][0]);
  for (char i = 0; i < NUM_LETTERS; ++i) {
    int query_index = GetIndex('a' + i);
    if (index_for_s == query_index || index_for_w == query_index) {
      continue;
    }
    list = GetList(table->keys[i], table);
    // Test that the list has been initialized.
    if (list == NULL) {
      printf("ERROR: List for key character %c is not initialized!\n",
             table->keys[i]);
    }
    // Test that the list is empty.
    if (!IsEmpty(list)) {
      printf("ERROR: List for key character %c is should be empty.\n",
             table->keys[i]);      
    }
  }
  DestroyHashTable(&table);
  if (table != NULL) {
    puts("ERROR: Table was not set to NULL.");
    return 1;
  }
  return 0;
}
