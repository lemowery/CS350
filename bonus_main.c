#include "bonus_points.h"
#include <stdio.h>
#include <string.h>

int main(){
  int array[] = {5, 6, 4, 3, 2, 1, 5};
  MergeSort(array, array + 6);
  for (int i = 0; i < 7; ++i){
   printf("%d ", array[i]);
  }
   printf("\n ");
  return 0;
}
