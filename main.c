/*
Levi Mowery
lemowery@mix.wvu.edu
800096308
*/

#include <stdio.h>
#include "assignment_2.h"

int main(){

  //Problem 1
  char* string1 = "kayak";
  char* string2 = "Levi";
  if (IsPalindrome(string1)){
    printf("%s is a palindrome.\n", string1);
    } else {
    printf("%s is not a palindrome.\n", string1);
    }
    if (IsPalindrome(string2)){
      printf("%s is a palindrome.\n", string2);
    } else {
      printf("%s is not a palindrome.\n", string2);
    }
    printf("\n");
    
    //Problem 2
    char* string3 = "Dog";
    char* string4 = "house";
    char string5[512] = {};
    char string6[512] = {};
    ConcatenateStrings(string1, string2, string5);
    ConcatenateStrings(string3, string4, string6);
    printf("%s concatenated with %s is %s\n", string1, string2, string5);
    printf("%s concatenated with %s is %s\n", string3, string4, string6);
    printf("\n");

    //Problem 3
    float matrix1[9] = {3, 2, 1, 6, 5, 4, 9, 8, 7};
    printf("Unsorted Matrix: \n");
    PrintMatrix(3, 3, matrix1);
    SortRowsOfMatrix(3, 3, matrix1);
    printf("Sorted Matrix: \n");
    PrintMatrix(3, 3, matrix1);
    float matrix2[12] = {5, 4, 3, 6, 9, 8, 0, 6, 2, 6, 4, 8};
    printf("Unsorted Matrix: \n");
    PrintMatrix(3, 4, matrix2);
    SortRowsOfMatrix(3, 4, matrix2);
    printf("Sorted Matrix: \n");
    PrintMatrix(3, 4, matrix2);
    printf("\n");

    //Problem 4
    float matrix3[12] = {0};
    printf("Matrix 1\n");
    PrintMatrix(3, 3, matrix1);
    printf("Multiplied by matrix 2\n");
    PrintMatrix(3, 4, matrix2);
    printf("Equals\n");
    MultiplyMatrices(3, 3, matrix1, 3, 4, matrix2, matrix3);
    PrintMatrix(3, 4, matrix3);

    float matrix4[4] = {1, 2, 3, 4};
    float matrix5[6] = {1, 2, 3, 4, 5, 6};
    float matrix6[6] = {0};
    printf("Matrix 1\n");
    PrintMatrix(2, 2, matrix4);
    printf("Multiplied by matrix 2\n");
    PrintMatrix(2, 3, matrix5);
    printf("Equals\n");
    MultiplyMatrices(2, 2, matrix4, 2, 3, matrix5, matrix6);
    PrintMatrix(2, 3, matrix6);
    printf("\n");
    
    //Bonus Problem
    int searchVal = 31;
    int matrix7[9] = {1, 4, 6, 7, 7, 8, 9, 10, 15};
    int matrix8[16] = {2, 3, 5, 6, 7, 8, 8, 10, 11, 12, 15, 19, 21, 22, 31};
    if (BinarySearch(&matrix7[0], &matrix7[8], searchVal)){
      printf("Matrix 7 contains %d\n", searchVal);
    }else {
      printf("Matrix 7 does not contain %d\n", searchVal);
    }

    if (BinarySearch(&matrix8[0], &matrix8[15], searchVal)){
      printf("Matrix 8 contains %d\n", searchVal);
    }else {
      printf("Matrix 8 does not contain %d\n", searchVal);
    }
  return 0;
}
