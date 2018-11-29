#include <stdio.h>

int main(){
  int array[] ={1, 2, 3, 4, 5};
  //The array is pointer to the first element of the array
  //1. array_ptr can be treated as an array
  //2. 
  int* array_ptr = array;
  for(int i = 0; i < 5; ++i){
    //array[i] <=> *(array + i)
    printf("%d\n", *array_ptr++);
  }
  for(int i = 5; i > 0; --i){
    //array[i] <=> *(array + i)
    printf("%d\n", *--array_ptr);
  }
  return 0;
}
