#include <stdio.h>
int main(){
  int counter = 0;
  do {
    if (counter % 2){
      continue; //goes to end of loop
    }
    printf("%d\n", counter);
  } while (++counter <= 10);
  return 0;
}
