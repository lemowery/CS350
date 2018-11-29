#include <stdio.h>
#include <string.h>
#include "bubble_sort.h"

int main(){
  char string[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  printf("Length of string is %lu", strlen(string));
  //Test IsSorted()
  int array[] = {2, 3, 5, 4, 1};
  int sortedarray[] = {1, 2, 3, 4, 5};
  int singleelement[] = {1};
  if(IsSorted(array, 5) != FALSE){
    printf("ERROR: Error in IsSorted correctness.\n");
    return 1;
  }
  //Corner cases
  if(IsSorted(array, -1) != TRUE){
    printf("ERROR: Error in corner case of IsSorted.\n");
    return 1;
  }
  //correctness
  if(IsSorted(sortedarray, 5) != TRUE){
    printf("ERROR: IsSorted.\n");
    return 1;
  }
  //single element
  if(IsSorted(singleelement, 1) != TRUE){
    printf("ERROR: IsSorted.\n");
    return 1;
  }

  //Test BubbleSort()
  //Case 1: sorted array
  BubbleSort(sortedarray, sizeof(sortedarray) / sizeof(int));
  if(IsSorted(sortedarray, 5) == FALSE){
    printf("ERROR: BubbleSort not working.\n");
    return 1;
  }

  //Case 2: unsorted array
  BubbleSort(array, 5);
  if(IsSorted(array, 5) == FALSE){
    printf("ERROR: BubbleSort not working.\n");
    return 1;
  }
  return 0;
}
