/*
Levi Mowery
lemowery@mix.wvu.edu
800096308
 */

#include <stdio.h>
#include "assignment_1.h"
#include <stdlib.h>
#include <time.h>

/*
Problem 1: Factorial Calculator
Uses for loop to continously multiply
by next lowest number until 0
*/
int CalculateFactorial(int number){
  int answer = 1;
  if(number < 0){
    return 0;
  }
  for(int i = number; i > 0; --i){
    answer *= i;
  }
  return answer;
}

/*
Problem 2: Fibonacci Calculator
Uses set rules for 0 and 1
For the rest, simply adds previous two numbers together
*/
int CalculateFibonacci(int number){
  if(number <= 0){
    return 0;
  }
  if(number == 1){
    return 1;
  }
  return((number - 1) + (number - 2));
}

/*Problem 3: Array Reverser
switches corresponding symmetric values until middle is reached
*/
void ReverseArray(int size, int array[]){
  for(int i = 0; i < (size / 2); ++i){
    int temp = array[i];
    array[i] = array[(size - 1) - i];
    array[(size - 1) - i] = temp;
  }
}

/*Problem 4: Array Shuffler
generates new random location for current value to be placed in
flips all values in array
*/
void ShuffleArray(int size, int array[]){
  srand(time(NULL));//Seed for random generator
  for(int i = 0; i < size; ++i){
    int newSpot = rand() % size;
    int temp = array[newSpot];
    array[newSpot] = array[i];
    array[i] = temp;
  }
}

//Array Printer
void PrintArray(int size, int array[]){
  for(int i = 0; i < size; ++i){
    printf("%d ", array[i]);
  }
  printf("\n");
}
