#include <pthread.h>
#include <stdio.h>

// Worker starts here
void* PrintHello(void* args){ // Input to create must have this form
  int* thread_id = (int*) args;
  printf("Hello world from thread %d!\n", *thread_id);
  pthread_exit(NULL);
}

//Main function is executed by the main thread
int main(){
  pthread_t worker[4];
  pthread_attr_t attributes;
  // Create and initialize attributes
  if (pthread_attr_init(&attributes)){
    printf("ERROR: Unable to initialize attributes.\n");
    return 1;
  }
  // Create threads that can inform the parent thread that it has finished
  pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_JOINABLE);
  // Launch the threads
  int thread_ids[4] = {0};
  for (int i = 0; i < 4; ++i){
    thread_ids[i] = i;
    pthread_create(&worker[i], &attributes, PrintHello, &thread_ids[i]);
  }
  // Main executes this
  // Join tell the parent to wait for thread to finish
  for(int i = 0; i < 4; ++i){
    pthread_join(worker[i], NULL);
  }
  return 0;
}
