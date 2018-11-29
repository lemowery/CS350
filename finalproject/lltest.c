#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  LinkedList* list = CreateLinkedList();
  Insert("hello", list);
  if (list->first->next == NULL){
    printf("%s\n", list->first->string);
  }
}
