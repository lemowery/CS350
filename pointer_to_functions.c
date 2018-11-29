#include <stdio.h>

int SumIntegers(const int a, const int b){
  return a + b;
}

void PrintString(const char* const str1){
  printf("%s\n", str1);
}

int main(){
  //Can reuse pointers
  // Return type (pointer name) (input args)
  int (*pointer_fn)(const int, const int) = NULL;
  //pointer to string function
  void (*string_fn)(const char* const) = PrintString;
  pointer_fn = &SumIntegers;
  int result = pointer_fn(5, 5);
  printf("Result is %d\n", result);
  return 0;
}
