#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "hash_table.h"
#include "linked_list.h"
#include "thread_utils.h"

void TestNonExistingFiles() {
  puts("INFO: >>>>>>>>>>>>>> Test 1");
  pthread_t thread;
  pthread_attr_t attr;
  char* non_existent_files[] = {"random_file.txt", "another_file.txt"};
  // Initialize thread attributes.
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  // Initialize the job arguments.
  JobArguments job_args;
  job_args.hash_table = CreateHashTable();
  job_args.filepaths = non_existent_files;
  job_args.start_index = 0;
  job_args.end_index = 1;
  // Launch thread.
  puts("INFO: Launching single thread with non existent files to process ...");
  pthread_create(&thread, &attr, BuildDictionaryFromFiles, &job_args);
  // Wait for the thread to finish.
  pthread_join(thread, NULL);
  puts("INFO: Thread finished!");
  DestroyHashTable(&job_args.hash_table);
}

void TestExistingFiles() {
  puts("INFO: >>>>>>>>>>>>>> Test 2");
  pthread_t thread;
  pthread_attr_t attr;
  char* non_existent_files[] = {"file_1.txt", "file_2.txt"};
  // Initialize thread attributes.
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  // Initialize the job arguments.
  JobArguments job_args;
  job_args.hash_table = CreateHashTable();
  job_args.filepaths = non_existent_files;
  job_args.start_index = 0;
  job_args.end_index = 1;
  // Launch thread.
  puts("INFO: Launching single thread with existent files to process ...");
  pthread_create(&thread, &attr, BuildDictionaryFromFiles, &job_args);
  // Wait for the thread to finish.
  pthread_join(thread, NULL);
  puts("INFO: Thread finished!");
  DestroyHashTable(&job_args.hash_table);
}

void TestMultipleExistingFiles() {
  puts("INFO: >>>>>>>>>>>>>> Test 3");
  pthread_t threads[2];
  pthread_attr_t attr;
  char* existent_files[] = {
    "file_3.txt", "file_3.txt", "file_3.txt", "file_3.txt"
  };
  // Initialize thread attributes.
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  // Initialize the job arguments.
  JobArguments job_args[2];
  HashTable* table = CreateHashTable();
  job_args[0].hash_table = table;
  job_args[0].filepaths = existent_files;
  job_args[0].start_index = 0;
  job_args[0].end_index = 1;
  job_args[1].hash_table = table;
  job_args[1].filepaths = existent_files;
  job_args[1].start_index = 2;
  job_args[1].end_index = 3;
  // Launch thread.
  puts("INFO: Launching single thread with existent files to process ...");
  pthread_create(&threads[0], &attr, BuildDictionaryFromFiles, &job_args[0]);
  pthread_create(&threads[1], &attr, BuildDictionaryFromFiles, &job_args[1]);
  // Wait for the thread to finish.
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  puts("INFO: Thread finished!");
  // Test if the hash table has a single entry with the word 'word'.
  const LinkedList* list = GetList('w', table);
  if (list == NULL) {
    puts("ERROR: Could not retrieve list for 'w' character.");
    return;
  }
  if (IsEmpty(list)) {
    puts("ERROR: List for key character 'w' is empty!");
  }
  if (strcmp("word", list->front->string)) {
    printf("ERROR: Expected string in list [word] but list contains [%s]",
           list->front->string);
  }
  DestroyHashTable(&table);
}

void TestProcessFiles() {
  puts("INFO: >>>>>>>>>>>>>> Test 4");
  char* existent_files[] = {
    "file_3.txt", "file_3.txt", "file_3.txt", "file_3.txt"
  };
  const int kNumThreads = 2;
  const int num_files = sizeof(existent_files) / sizeof(existent_files[0]);
  printf("INFO: Processing %d files with %d threads...\n", num_files, kNumThreads);
  HashTable* table = ProcessFiles(
      kNumThreads, (const char**) existent_files, num_files);
  if (table == NULL) {
    puts("ERROR: Could not process files.");
    return;
  }
  // Writing dictionary to disk.
  CreateOutputFile(table, "output_dictionary.txt");
  DestroyHashTable(&table);
  puts("INFO: Done!");
}

int main() {
  TestNonExistingFiles();
  TestExistingFiles();
  TestMultipleExistingFiles();
  TestProcessFiles();
  return 0;
}
