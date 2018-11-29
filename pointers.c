#include <stdio.h>

void Swap(int* ptr_1, int* ptr_2){
  //ptr_1 points to ptr_2
  //ptr_2 points to ptr_1
  int temp = *ptr_1;
  *ptr_1 = *ptr_2;
  *ptr_2 = temp;
}

int main(){
  int num = 5;
  int num_2 = 11;
  const int kConstant = 10;
  char letter = 'a';
  char letter2 = 'n';
  //pointer to integer
  const int* constant_ptr = &kConstant;
  int* num_ptr = NULL;
  char* letter_ptr = &letter;
  //Swap the values of num1 and num_2
  num_ptr = &num;
  int* num_2_ptr = &num_2;
  Swap(num_ptr, num_2_ptr);//or Swap(&num, &num_2)
  printf("Num 1: %d and Num 2: %d\n", *num_ptr, *num_2_ptr);
  // & gives address of num.
  printf("Address of num: %p with value: %d\n", num_ptr, *num_ptr);
  // *num_ptr gives value at the address
  printf("Address of letter: %p with value: %c\n",letter_ptr, *letter_ptr);
  letter_ptr = &letter2;//can reuse pointers
  printf("Address of letter: %p with value: %c\n",letter_ptr, *letter_ptr);
  //Modifying a variable indirectly
  *num_ptr = 10;
  printf("Address of num: %p with value: %d\n", num_ptr, *num_ptr);
  printf("Address of constant: %p with value: %d\n", constant_ptr, *constant_ptr);
  return 0;
}

