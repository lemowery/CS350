/*
 * This is just a sample of the tester for the first assignment.
 * Think about other corner cases that can break the execution
 * of your implementations.
 *
 * To compile this tester.
 * $ gcc test_main.c assignment_1.c -o test_main
 */ 
#include <stdio.h>
#include "assignment_1.h"

int main() {
  /****************** Problem 1 - Factorial.
   */
  /* a) Correctness. */
  int factorial = CalculateFactorial(0);
  if (factorial != 1) {
    printf("ERROR[%s]: Expected %d as the factorial of %d.",
           "CalculateFactorial", 1, 0);
    printf(" Returned instead %d.\n", factorial);
  }
  factorial = CalculateFactorial(1);
  if (factorial != 1) {
    printf("ERROR[%s]: Expected %d as the factorial of %d.",
           "CalculateFactorial", 1, 1);
    printf(" Returned instead %d.\n", factorial);
  }
  factorial = CalculateFactorial(7);
  if (factorial != 5040) {
    printf("ERROR[%s]: Expected %d as the factorial of %d.",
           "CalculateFactorial", 5040, 7);
    printf(" Returned instead %d.\n", factorial);  
  }
  /* b) Corner cases. */
  factorial = CalculateFactorial(-1);
  if (factorial > 0) {
    printf("ERROR[%s]: Expected a number less than 1.",
           "CalculateFactorial");
    printf(" Returned instead %d.\n", factorial);  
  }
  /****************** Problem 2 - Fibonacci. */
  int fibonacci = CalculateFibonacci(0);
  /* a) Correctness. */
  if (fibonacci != 0) {
    printf("ERROR[%s]: Expected %d as the Fibonacci of %d.",
           "CalculateFibonacci", 0, 0);
    printf(" Returned instead %d.\n", fibonacci);
  }
  fibonacci = CalculateFibonacci(1);
  if (fibonacci != 1) {
    printf("ERROR[%s]: Expected %d as the Fibonacci of %d.",
           "CalculateFibonacci", 1, 1);
    printf(" Returned instead %d.\n", fibonacci);
  }
  fibonacci = CalculateFibonacci(2);
  if (fibonacci != 1) {
    printf("ERROR[%s]: Expected %d as the Fibonacci of %d.",
           "CalculateFibonacci", 1, 2);
    printf(" Returned instead %d.\n", fibonacci);
  }
  /* b) Corner cases. */
  fibonacci = CalculateFibonacci(-1);
  if (fibonacci > 0) {
    printf("ERROR[%s]: Expected a number less than 1.",
           "CalculateFibonacci");
    printf(" Returned instead %d.\n", fibonacci);
  }
  /****************** Problem 3 - Reverse Array. */
  int array[] = {1, 2, 3, 4, 5};
  ReverseArray(5, array);
  for (int i = 0; i < 5; ++i) {
    if (array[i] != (5 - i)) {
      printf("ERROR[%s]: Array is not properly reversed.",
             "ReverseArray");
      break;
    }
  }
  /* Corner case. */
  ReverseArray(0, array);
  for (int i = 0; i < 5; ++i) {
    if (array[i] != (5 - i)) {
      printf("ERROR[%s]: Array is not properly reversed.",
             "ReverseArray");
      break;
    }
  }
  /****************** Problem 4 - Shuffle Array. */
  /* Copy array. */
  int array2[5];
  int diferent_order_count = 0;
  for (int i = 0; i < 5; ++i) {
    array2[i] = array[i];
  }
  ShuffleArray(5, array);
  for (int i = 0; i < 5; ++i) {
    if (array[i] == array2[i]) {
      ++diferent_order_count;
    }
  }
  if (diferent_order_count == 5) {
    printf("ERROR[%s]: Array was not shuffled.\n",
           "ShuffleArray");
  }
  return 0;
}
