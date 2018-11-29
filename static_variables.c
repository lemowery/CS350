#include <stdio.h>

//global variable
//dangerous because it makes important information vulnerable
static const int kMaxNumber = 5;
//static read only int which can only be used
//in file

void PrintfHello(){
  static int invocation_counter = 0;
  printf("Hello World!\n");
  printf("Num. of invocations: %d\n", ++invocation_counter); 
}

int main(){
  printf("Max number %d\n", kMaxNumber);
  {
    printf("%d\n", kMaxNumber);
  }
  PrintfHello();
  PrintfHello();
  return 0;
}
