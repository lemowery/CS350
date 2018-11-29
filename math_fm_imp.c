// Implementation of our math function
#include <stdio.h>
#include "math_fm.h"
int AddIntegers(const int a, const int b) {
  return a + b;
}

void PrintHello(){
  printf("Hello\n");
}

int IsEven(const int numtotest){
  return !(numtotest % 2);
}

int CalculateFactorial(const int number){
  //Check for negative numbers
  if(number < 0){
    return 0;
  }
  //Base case 
  if(number == 0 || number == 1){
    return 1;
  } 
  return number * CalculateFactorial(number - 1);
}
