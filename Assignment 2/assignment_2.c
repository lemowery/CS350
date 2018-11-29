/* 
Levi Mowery
lemowery@mix.wvu.edu
800096308
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "assignment_2.h"
int IsPalindrome(const char* str1){
  /*
    Function checks the non-mutable string to see if it is a palindrome
    Case-sensistive
    Strings of length 0 are not palindromes
    Strings of length 1 are palindromes
   */
  int length = strlen(str1);
  int endIndex = strlen(str1) - 1;
  if (length == 1){
    return TRUE;
  }
  if (length == 0){
    return FALSE;
  }
  for(int i = 0; i < (length / 2); ++i){
    if(tolower(str1[i]) != tolower(str1[endIndex - i])){
      return FALSE;
    }
  }
  return TRUE;
}

void ConcatenateStrings(const char* str1, const char* str2, char* newString){
  /*
Concatenates two strings into another character pointer
If either input  strings are null, no changes are made
*/
  int length1 = strlen(str1);
  int length2 = strlen(str2);
  if (str1 == NULL || str2 == NULL){
    return;
  }
  for (int i = 0; i < length1; ++i){
    *newString++ = *str1++;
  }
  for(int j = 0; j < length2; ++j){
    *newString++ = *str2++;
  }
  *newString = '\0';
 }

void TransposeMatrix(const int col, float* topLeft){
  /*
Transposes Matrix
If the number of columns = 0, no changes are made
   */
  if (col == 0 || topLeft == NULL){
    return;
  }
  for (int i = 0; i < col; ++i){
    for(int j = 0; j <= i; ++j){
      int index1 = (col * i) + j;
      int flipIndex = (col * j) + i;
      float temp = *(topLeft + index1);
      *(topLeft + index1) = *(topLeft + flipIndex);
      *(topLeft + flipIndex) = temp;
    }
  }
}

void SortRowsOfMatrix(const int row, const int col, float* topLeft){
  /*
Sorts each matrix row
Cant input an empty matrix or null pointer
*/
  if(row == 0 || col == 0 || (row == 1 && col == 1) || topLeft == NULL){
    return;
  }
  for (int i = 0; i < row; ++i){
    int f = 0;
    while(!IsSorted(i, col, topLeft)){
      for(int j = 0; j < col - 1; ++j){
	int index = (i * col) + j;
	if(topLeft[index] > topLeft[index + 1]){
	  float temp = *(topLeft + index);
	  *(topLeft + index) = *(topLeft + index + 1);
	  *(topLeft + index + 1) = temp;
	}
      }
    }
  }
}

void MultiplyMatrices(const int row1, const int col1, const float* topLeft,
		      const int row2, const int col2, const float* topLeft2,
		      float* newTopLeft){
  /*
Multiplies two matrices
Must obey normal matrix multiplication rules
Cant be given NULL pointers
*/
  if (col1 !=row2 || row1 == 0 || col1 == 0 || row2 == 0 || col2 == 0 ||
      topLeft == NULL || topLeft2 == NULL){
    return;
  }
  float* newIndex = newTopLeft;
  for (int i = 0; i < row1; ++i){
    for (int j = 0; j < col2; ++j){
      float sum = 0.0;
      for (int k = 0; k < col1; ++k){
	int leftIndex = i * col1 + k;
	int rightIndex = k * col2 + j;
	sum = sum + topLeft[leftIndex] * topLeft2[rightIndex];
      }
      *(newTopLeft + (i * col2) + j) = sum;
    }
  }
}

int BinarySearch(const int* firstSorted, const int* lastSorted, const int searchNum){
  /*
Method searches array for integer value using 
binary search method
Can use null pointers
*/
  if (firstSorted == NULL || lastSorted == NULL){
    return FALSE;
  }
  while (firstSorted <= lastSorted){
    const int* middle = (firstSorted +(lastSorted - firstSorted) / 2);
    if (*middle == searchNum){
      return TRUE;
    }
    if (searchNum < *middle){
      lastSorted = --middle;
    }
    if (searchNum > *middle){
      firstSorted = ++middle;
    }
  }
  return FALSE;
}

int IsSorted(const int currentRow, const int size, const float* array){
  /*
Extra function to determine of a row in an array was sorted
*/
  for (int i = 0; i < size - 1; ++i){
    int startIndex = (currentRow * size) + i;
    if (array[startIndex] > array[startIndex + 1]){
      return FALSE;
    }
  }
  return TRUE;
}

void PrintMatrix(const int row, const int col, const float* array){
  /*
Function for printing a matrix
*/
  for (int i = 0; i < row; ++i){
    for (int j = 0; j < col; j++){
      printf("%f ", *(array + (i * col) + j));
    }
    printf("\n");
  }
}
