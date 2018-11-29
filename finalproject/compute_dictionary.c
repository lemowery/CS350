#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "thread_utils.h"

#define MAX_CHARS 512

char** ReadFilepaths(const char* filepath, int* num_lines) {
  if (!filepath || !num_lines) {
    return NULL;
  }
  FILE* file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "ERROR: Unable to open file [%s]", filepath);
    return NULL;
  }
  char line[MAX_CHARS];
  int line_counter = 0;
  while (fgets(line, MAX_CHARS, file) != NULL) {
    ++line_counter;
  }
  // Reset file.
  rewind(file);
  char** filepaths = (char**) malloc(--line_counter * sizeof(char*));
  if (!filepaths) {
    fprintf(stderr, "ERROR: Could not allocate array for filepaths.");
    fclose(file);
    return NULL;
  }
  int index = 0;
  while (fgets(line, MAX_CHARS, file) != NULL) {
    int length = strlen(line);
    if (length > 1 && line[length - 1] == '\n') {
      line[length - 1] = '\0';
      filepaths[index] = (char*) malloc((length + 1) * sizeof(char));
      strcpy(filepaths[index++], line);
    }
  }
  fclose(file);
  *num_lines = line_counter;
  return filepaths;
}

void DeleteFilePaths(const int num_lines, char*** filepaths_ptr) {
  if (!filepaths_ptr) {
    return;
  }
  char** filepaths = *filepaths_ptr;
  // Destroy filepaths.
  for (int i = 0; i < num_lines; ++i) {
    free(filepaths[i]);
    filepaths[i] = NULL;
  }
  free(*filepaths);
  filepaths = NULL;
}

int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Usage: %s <filepaths_file> <output_filename> <num_threads>\n",
           argv[0]);
    return 1;
  }
  int num_lines;
  char** filepaths = ReadFilepaths(argv[1], &num_lines);
  // Process files!
  HashTable* table = ProcessFiles(
      atoi(argv[3]), (const char**) filepaths, num_lines);
  if (!table) {
    DeleteFilePaths(num_lines, &filepaths);
    return 1;
  }
  CreateOutputFile(table, argv[2]);
  DeleteFilePaths(num_lines, &filepaths);
  DestroyHashTable(&table);
  return 0;
}
