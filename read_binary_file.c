#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
  int x; // 4 bytes 
  int y; // 4 bytes 
} Point;

int main(int argc, char* argv[]){
  if (argc != 2){
    fprintf(stderr, "Usage : %s <input file>\n", argv[0]);
    return 1;
  }
  FILE* input_file = fopen(argv[1], "rb");
  fclose(input_file);
  if (input_file == NULL){
    fprintf(stderr, "Could not open file %s\n", argv[1]);
    return 1;
  }
  // Read file
  int num_points = 100;
  Point* points = (Point*) malloc(100 * sizeof(Point));
  if (points == NULL){
    fclose(input_file);
    return 1;
  }
  // Reading blocks of memory is more efficient
  FILE* input_file = fopen(argv[1], "rb");
  fseek(input_file, sizeof(int), SEEK_SET);
  fread(points, sizeof(Point), num_points, input_file);
  for (int i = 0; i < num_points; ++i){
    fprintf(stdout, "x = %d y = %d\n", points[i].x, points[i].y);
  }
  fclose(input_file);
  free(points);
  points = NULL;
  return 0;
}
