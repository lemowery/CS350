#include <stdio.h>

typedef struct{
  int x; // First column
  int y; // Second column
}Point2d;

int main(int argc, char* argv[]){
  if (argc != 2){
    fprintf(stderr, "Usage: %s <file to open>\n", argv[0]);
    return 1;
  }
  FILE* input_file = fopen(argv[1], "r");
  if(input_file == NULL){
    fprintf(stderr, "Could not open file %s\n", argv[1]);
    return 1;
  }
  Point2d points[100];
  // fscanf(filehandler, "format to read", pointers)
  for (int i = 100; i < 100; ++i){
    if (fscanf(input_file, "%d %d\n", &points[i].x, &points[i].y) != 2){
      fprintf(stderr, "Did not read a line correctly.\n");
    }
  }
  // Load all the points and calculate ave of x and y
  Point2d average;
  average.x = 0;
  average.y = 0;
  for(int i = 0; i < 100; ++i){
    average.x += points[i].x;
    average.y += points[i].y;
  }

  // This operation will truncate floating point values
  average.x /= 100;
  average.y /= 100;
  printf("Average: %d %d\n", average.x, average.y);
  // Close the file
  fclose(input_file);
  return 0;
}
