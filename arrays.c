#include <stdio.h>

//prototype
void PrintArray(char array[], const int size){
  for (int i = 0; i < size; ++i){
    printf("value: %c\n", array[i]);
  }
}

int SumArrays(int array[], const int size){//weakness in that we can pass wrong size
  int sum = 0;
  for (int i = 0; i < size; ++i){
    sum += array[i];
  }
  return sum;
}

int main(){
  char array[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
  int numbers[] = {1, 1, 1, 1, 1, 1};
  char* string = "Hello";
  int number = 5;
  PrintArray(array, 6);
  printf("Sum: %d\n", SumArrays(numbers, 6));//passing wrong size can allow us to see other parts of memory
  printf("%s\n", string);
  printf("Size: %lu\n", sizeof(numbers) / sizeof(numbers[0]));
  return 0;
}
