#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assignment_4.h"

int main() {
  // 1. Test the creation of the Queue.
  const char* test_str[] = {"String 1", "", "3", "String 4, which is longer"};
  const int size = sizeof(test_str) / sizeof(test_str[0]);
  Queue* queue = CreateQueue();
  if (queue->front != NULL) {
    fprintf(stderr, "Queue front is not set to NULL.\n");
    return 1;
  }
  DestroyQueue(&queue);
  if (queue != NULL) {
    fprintf(stderr, "Queue pointer was not to null1.\n");
    return 1;
  }
  
  // 2. Enqueue data.
  queue = CreateQueue();
  for (int i = 0; i < size; ++i) {
    Enqueue(test_str[i], queue);
    if (queue->front == NULL) {
      fprintf(stderr, "The Enqueue function did not properly update the queue.\n");
      return 1;
    }
  }
  // 3. Dequeue data and check order.
  for (int i = 0; i < size; ++i) {
    const char* str = Dequeue(queue);
    if (str == (const char*) &test_str[i]) {
      fprintf(stderr, "Queue did not copy string in the heap.");
      return 1;
    }
    if (strcmp(str, test_str[i])) {
      fprintf(stderr, "Order does not match. Expected str=%s but got str=%s\n",
              test_str[i], str);
      return 1;
    }
    free((char*) str);
  }
  DestroyQueue(&queue);
  if (queue != NULL) {
    fprintf(stderr, "Queue pointer was not to null2.\n");
    return 1;
  }
  // 4. Create queue, insert data, and destroy it.
  queue = CreateQueue();
  for (int i = 0; i < size; ++i) {
    Enqueue(test_str[i], queue);
    if (queue->front == NULL) {
      fprintf(stderr, "The Enqueue function did not properly update the queue.\n");
      return 1;
    }
  }
  Node* node = queue->front;
  for (int i = 0; i < size; ++i){
     node = node->next;
  }
  DestroyQueue(&queue);
  if (queue != NULL) {
    fprintf(stderr, "Queue pointer was not to null3.\n");
    return 1;
  }
}
