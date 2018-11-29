// Levi Mowery
// 80096308
// lemowery@mix.wvu.edu

#ifndef THREAD_UTILS_H_
#define THREAD_UTILS_H_
#include "hash_table.h"

typedef struct JobArguments {
  HashTable* hash_table;
  char** filepaths;
  int start_index;
  int end_index;
} JobArguments;

void* BuildDictionaryFromFiles(void* jobargs);
void CreateOutputFile(HashTable* table, char* output_path);
HashTable* ProcessFiles(int num_of_threads, const char** strings, int num_of_files);

#endif
