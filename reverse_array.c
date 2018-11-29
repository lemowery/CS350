#include <stdio.h>

//Problem: Implement a function that reverses an array
void Swap(int* ptr1, int* ptr2);
void ReverseArray(int* begin, int* end);

int main(){
  int a = 5;
  int b = 4;
  printf("%d %d \n", a, b); //* is value, & is address
  Swap(&a, &b);
  printf("%d %d \n", a, b);
  int array[] = {1, 2, 3, 4, 5};
  for(int i = 0; i < 5; ++i){
    printf("%d\n", array[i]);
  }
  ReverseArray(array, &array[4]);
  for(int i = 0; i < 5; ++i){
    printf("%d\n", array[i]);
  }

  //Void pointers
  void* ptr = &a;//only worries about address, not type
  printf("%p\n", ptr);

  //String is array of chars
  const char* string = "hello"; //cant modify strings like this
  /*  printf("%c\n", string[1]);
  char* temp = string[0];
  string[0] = string[1];
  string[1] = temp;
  for(int i = 0; i < 5; ++i){
    printf("%c", *string);
    string++;
  }*/
  string = string+3;
  printf("%s", string);
  return 0;
}

void ReverseArray(int* begin, int* end){
  if(begin == NULL || end == NULL){
    return;
  }
  while(begin < end){
    Swap(begin++, end--);
  }
}

void Swap(int* ptr1, int* ptr2){
  if(ptr1 == NULL || ptr2 == NULL){
    return; 
  }
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

