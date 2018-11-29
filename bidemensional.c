#include <stdio.h>

//macro defining number of columns
#define COLUMNS 2

void PrintMatrix(int matrix[2][COLUMNS], const int rows){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < COLUMNS; ++j){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int matrix [2][2] = {{1, 2}, {4, 5}};
  PrintMatrix(matrix, 2);
  return 0;
}
