#include <pthread.h>
#include <stdio.h>

typedef struct JobArgs{
  int* first_idx;
  int* last_idx;
  float* sum;
  pthread_mutex_t* mutex;
} JobArgs;

void * Sum (void* args){
  JobArgs* job_args = (JobArgs*) args;
  int sum = 0;
  for (int* i = job_args->first_idx; i < job_args->last_idx; ++i){
    sum += *i;
  }
  //Critical section
  pthread_mutex_lock(job_args->mutex);
  *(job_args->sum) += sum; // Shared resource
  pthread_mutex_unlock(job_args->mutex);
  pthread_exit(NULL);
}

int main(){
  // Mutex stands for mutual exclusion
  // Assume you have a shared resource
  // A mutex instance guards a resource to control the usage of such resource
  pthread_t workers[4];
  pthread_attr_t attributes;
  // Create and initialize attributes
  if (pthread_attr_init(&attributes)){
    printf("ERROR: Unable to initialize attributes.\n");
    return 1;
  }
  // Create threads that can inform the parent thread that it has finished
  pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_JOINABLE);
  // Array of numbers
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  float average = 0.0f;
  JobArgs args[4];
  pthread_mutex_t mutex; // Guard the shared resource
  pthread_mutex_init(&mutex, NULL); // Initialize the guard
  // Mapping
  for (int i = 0; i < 4; ++i){
    args[i].first_idx = &array[i * 3]; // array + i * 3
    args[i].last_idx = args[i].first_idx + 2;
    args[i].mutex = &mutex;
    args[i].sum = &average;
    pthread_create(&workers[i], &attributes, Sum, &args[i]);
  }
  // Reduce
  for (int i = 0; i < 4; ++i){
    pthread_join(workers[i], NULL);
  }
  //Finish the average
  average /= 12;
  printf("Average is: %f", average);
  return 0;
}
