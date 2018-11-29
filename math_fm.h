#ifndef MATH_FM_H_ // header guard
#define MATH_FM_H_

//src1 --> includes header 1
//src2 --> includes header 1
//src1 src2 --> compilation

//this causes two declarations of header causing illegal overloading
//guard only allows one declaration

//Header for our math library
//Contains only prototypes of functions, only declarations

int AddIntegers(const int, const int);//names of variables not needed

void PrintHello();

int IsEven(const int);
//factorial function using recursion
int CalculateFactorial(const int number);


#endif // MATH_FM_H_
