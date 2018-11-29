#include <stdio.h> // printf() or puts()

int main(int argc, char* argv[]){
  if (argc != 2){
    printf("Usage: %s <file to open>\n", argv[0]);
    // Reporting a bad finish!
    return 1;
  }
    char* input_file = argv[1];
    // Reports the exit status to the OS
    // second argument:
    // r: read the file
    // w: writing
    // rw: read and write
    // b: binary
    // you can combine these modes
    FILE* file_to_open = fopen(input_file, "r");
    if (file_to_open == NULL){
      printf("Unable to open file %s\n", input_file);
      return 1;
    }
    // I have opened a file
    // TODO: Read the file
    char line[100];
    // E0F: end of file
    // the idea is to keep reading until we reach E0F
    // in that case fgets() returns null
    while (fgets(line, 100, file_to_open) != NULL){
      printf("%s", line);
    }
    if (feof(file_to_open)){
      printf("End of File!\n");   
    }
    fclose(file_to_open);
  return 0;
}
