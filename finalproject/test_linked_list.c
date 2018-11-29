#include <stdio.h>
#include "linked_list.h"

int main() {
  // 1. Create empty linked list and then destroy.
  LinkedList* list = CreateLinkedList();
  if (!IsEmpty(list)) {
    puts("ERROR: List is not empty.\n");
    return 1;
  }
  DestroyLinkedList(&list);
  if (list != NULL) {
    puts("ERROR: List pointer is not NULL after destruction.");
    return 1;
  }
  // 2. Insert a few unique words.
  const char* test_str[] = {"String 1", "Word", "3", "longer"};
  const int size = sizeof(test_str) / sizeof(test_str[0]);
  list = CreateLinkedList();
  for (int i = 0; i < size; ++i) {
    if (!Insert(test_str[i], list)) {
      puts("ERROR: Could not insert unique words.");
    }
  }
  if (IsEmpty(list)) {
    puts("ERROR: List is empty but inserted elements.");
  }
  DestroyLinkedList(&list);
  if (list != NULL) {
    puts("ERROR: List pointer is not NULL after destruction.");
    return 1;
  }
  // 3. Insert non-unique words.
  const char* repeated_str[] = {"String", "string", "WoRd", "woRD"};
  list = CreateLinkedList();
  if (!Insert(repeated_str[0], list)) {
    printf("Could not insert string: %s\n", repeated_str[0]);
  }
  if (Insert(repeated_str[1], list)) {
    printf("String [%s] was insert but string [%s] was already in the list.\n",
           repeated_str[0], repeated_str[1]);
  }
  if (!Insert(repeated_str[2], list)) {
    printf("Could not insert string: %s\n", repeated_str[2]);
  }
  if (Insert(repeated_str[3], list)) {
    printf("String [%s] was insert but string [%s] was already in the list.\n",
           repeated_str[2], repeated_str[3]);
  }
  DestroyLinkedList(&list);
  if (list != NULL) {
    puts("ERROR: List pointer is not NULL after destruction.");
    return 1;
  }
  return 0;
}
