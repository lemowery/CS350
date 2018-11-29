#include <stdio.h>
#include "vector.h"

int main (){
  const int kInitialCapacity = 8;
  const int kMaxNumber = 10;
  // Testing construction of vector
  printf("Testing Constructor.\n");
  Vector* vector = CreateVector(kInitialCapacity);
  if (vector == NULL){
    printf("Could not allocate vector!\n");
    return 1;
  }
  printf("Capacity: %d\n", vector->capacity);
  if (vector->capacity != 8 || vector->size != 0 || vector->array == NULL){
    printf("Wrong initial capacity or size or array pointer!\n");
    return 1;
  }
    printf("Testing corner cases.\n");
  // Corner case for constructor
  Vector* test_vector = CreateVector(-1);
  if (test_vector != NULL){
    puts("Not handling corner case.\n");
    DestroyVector(&vector);				
  }
  printf("Testing Add.\n");
  // Test if we can insert values in the array
  for (int i = 0; i < kMaxNumber; ++i){
    Add(i, vector);
    if (vector->array[vector->size - 1] != i){
      printf("Add() is not working correctly.\n");
      return 1;
    }
    if (vector->size > vector->capacity){
      printf("Not updating size and capacity correctly.\n");
      return 1;
    }
        // Check if we copied information correctly
    for (int i = 0; i < vector->size; ++i){
      if(vector->array[i] != i){
	printf("Not copying array correctly.\n");
	return 1;
      }
    }
  }
  printf("Testing destructor.\n");
  // Test the destructor
  DestroyVector(&vector);
  if (vector != NULL){
    puts("Not NULLING the vector pointer correctly.\n");
    return 1;
  }
  printf("Testing corner case for destroy vector.\n");
  DestroyVector(NULL);
  return 0;
}
