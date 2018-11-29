// Bubble sort header
#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

//Macros to deal with boolean values
#define TRUE 1
#define FALSE 0

/*
Bubble sort in place
array serves as input and output
 */
void BubbleSort(int array[], const int size, int (*compare_fn)(const int, const int));

// Is the array sorted?
int IsSorted(int array[], const int size, int (*compare_fn)(const int, const int));
#endif 
