#include <stdio.h>
#include <string.h>

void CopyString(const char* string_ptr, char* copied_str);

int main(){
  const char* const str1 = "hello";
  char output[6];
  printf("%s\n", output);
  const int len_output = strlen(output);
  printf("%d\n", len_output);
  CopyString(str1, output);
  printf("%s\n", output);
  //scanf
  printf("What is your name?\n");
  char name[128];
  int age = 0;
  scanf("%s", name);
  printf("What is your age?\n");
  scanf("%d", age);
   return 0;
}

void CopyString(const char* string_ptr, char* copied_str){
  if(string_ptr == NULL || copied_str == NULL){
    return;
  }
  while(*string_ptr != '\0'){
    *copied_str++ = *string_ptr++;
  }
  *copied_str = '\0'; //terminates new string
}

