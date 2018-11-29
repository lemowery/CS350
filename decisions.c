#include <stdio.h>

int main (){

  int a = 6;
  int b = 5;

  if (a < b){
    printf("Code: %d\n", a);
    if (a - a){
      printf("A false statement!\n");
    }
  }
  
  else if (a == b){
    printf("A equals b\n");
  }

  else{
    printf("Cool case\n");
  }
  
  return 0;
}
