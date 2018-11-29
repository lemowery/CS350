#include <stdio.h>
#include "bubble_sort.h"

int IsLessThan(const int a, const int b){
  return a < b;
}

int IsGreaterThan(const int a, const int b){
  return a > b;
}

int main(){
  int array[] = {5, 4, 3, 2, 1};
  //  int (*compare_fn)(const int, const int) = IsLessThan; either one works
  BubbleSort(array, 5, IsLessThan);
  for (int i = 0; i < 5; ++i){
    printf("%d\n", array[i]);
  }
  BubbleSort(array, 5, IsGreaterThan);
  for (int i = 0; i < 5; ++i){
    printf("%d\n", array[i]);
  }
  return 0;
}
