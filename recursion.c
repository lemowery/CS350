#include <stdio.h>
//factorial funciton in header below
#include "math_fm.h"

int main(){
  //correctness
  //base case
  int input = 0;
  int result = CalculateFactorial(input);
  if(result != 1){
    printf("ERROR in base case");
  }
  input = 1;
  result = CalculateFactorial(input);

  input = 3;
  result = CalculateFactorial(input);
  if(result != 6){
    printf("ERROR in recursion part");
  }
  input = -1;
  result = CalculateFactorial(input);
  if(result != 0){
    printf("ERROR with negative values");
  }
  return 0;
}
