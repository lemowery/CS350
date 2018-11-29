#include <stdio.h>

int main(){
  /* While loop example
     I can put extra comments here
   */
  //Single line comment
  int counter = 1;
  while (counter <= 10){
    printf("%d\n", counter);
    ++counter;//This is faster than counter++
  }
  return 0;
}
