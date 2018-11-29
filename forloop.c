#include <stdio.h>
int main(){
  for (int counter = 1, counter2 = 0; counter <= 10; ++counter, counter2 += 2){
    printf("Counter 1: %d\n", counter);
    printf("Coutner 2: %d\n", counter2);
  }
  return 0;
}
