#include <stdio.h>

int main(){
  // malloc
  char* string;
  int* array_in_heap;
  // Space for 50 chars = 50 bytes, 1 char = 1 byte
  // This memory allocation in the *heap*
  // malloc returns a void* which is a generic pointer
  string = (char*) malloc(50 * sizeof(char));
  array_in_heap = (int*) malloc(100 * sizeof(int));
  if (array_in_heap == NULL){
    fprintf(stderr, "Culd not allocate memory.\n");
    return 1;
  }
  for (int i = 0; i < 100; ++i){
    array_in_heap[i] = 0;
  }
  free(array_in_heap);
  array_in_heap = NULL;
  if (string == NULL){
    fprintf(stderr, "Could not allocate memory.\n");
    return 1;
  }
  // String with 50 chars
  char* hello_str = "hello";
  memcpy(string, hello_str, strlen(hello_str) + 1 * sizeof(char));
  // puts(str) <=> printf("%s", str);
  puts(string);
  // Release memory
  free(string);
  string = NULL;
  // String still has the address of the memory I allocated
  return 0;
}
