#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// create_random_points
int main(int argc, char* argv[]){
  if (argc != 2){
    fprintf(stderr, "Usage: %s <file to open>\n", argv[0]);
  }
  char* output_filepath = argv[1];
  FILE* output_file = fopen(output_filepath, "w");
  if (output_file == NULL){
    // stderr has a larger buffer than stdout
    fprintf(stderr, "Could not open file. %s\n", output_filepath);
    return 1;
  }
  // Need a random number generator
  // Initializing or seed the num generator
  srand(time(NULL));
  for (int i = 0; i < 100; i++){
    fprintf(output_file, "%d %d\n", rand() % 100, rand() % 100);
  }
  fclose(output_file);
  return 0;
}
