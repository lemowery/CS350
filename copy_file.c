#include <stdio.h> // all i/o

int main(int argc, char* argv[]){
  // Usage: copy_file <source_file> <destination>
  if(argc != 3){
    printf("Usage: %s copy_file <source_file> <destination>\n", argv[0]);
    //user did not command properly
    return 1;
  }
  // source and destination filepaths
  char* source_filepath = argv[1];
  char* destination_filepath = argv[2];
  // open for reading
  FILE* source_file = fopen(source_filepath, "r");
  if (source_file == NULL){
    printf("Could not open file %s\n", source_filepath);
    return 1;
  }
  // T0D0: open for writing
  FILE* dest_file = fopen(destination_filepath, "w");
  if (dest_file == NULL){
    printf("Could not open file %s\n", destination_filepath);
    fclose(source_file);
    return 1;
  }  
  char line[512];
  while (fgets(line, 512, source_file) != NULL){
    // 1. string to write
    // 2. file
    fputs(line, dest_file);
  }
  fclose(source_file);
  fclose(dest_file);
  return 0;
}

