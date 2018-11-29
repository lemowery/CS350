#include <stdio.h>

int main(){
  int a = 5;
  switch (a){
  case 1:
    {
    printf("I have a 1\n");
    break;
    }
  case 5:
    {
    printf("I have a 5\n");
    break;
    }
  default:
    {
    printf("?\n");
    }
  }
  return 0;
}
