#include "bubble_sort.h"
#include <stdio.h>

int IsSorted(int array[], const int size, int (*compare_fn)(const int, const int)){
  //Making sure we get proper input
  if (size < 2 || compare_fn == NULL){
    return TRUE;
  }
  //Actual solution
  for (int i = 0; i < (size - 1); ++i){
    if(!compare_fn(array[i], array[i + 1])){
      return FALSE;
    }
  }
  return TRUE;
}

void Swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int array[], const int size, int (*compare_fn)(const int, const int)){
  if(size < 2 || compare_fn == NULL){
    return;
  }
  // Bubble sort
  while(!IsSorted(array, size, compare_fn)){
      for (int i = 0; i < (size - 1); ++i){
	//	if(array[i] > array[i + 1]){
	if(!compare_fn(array[i], array[i + 1])){
	// Swap numbers
	  Swap(&array[i], &array[i + 1]);
	}
      }
  }
}
