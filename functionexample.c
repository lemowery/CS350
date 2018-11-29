#include <stdio.h>
#include <math.h>
//Declaration of function
int AddIntegers(const int a, const int b); //protect input information
//dont need to name input arguments for declaration, just definition

float AddFloats(const float a, const float b); //no overloading in C

void PrintHello(){
  printf("Hello!\n");
}
int main(){
  printf("Sum %d\n", AddIntegers(0,1));
  printf("Sqrt of %f = %f\n", 2.0, sqrt(2.0));
  printf("%f raised to the power of %f is %f\n", 2.0, 2.0, pow(2.0,2.0));
  PrintHello();
  return 0;
}

//Definition of function
int AddIntegers(int a, int b){
  return a + b;
}
