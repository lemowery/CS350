#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

// Constructor
// void InitializeVector(const int capacity, Vector* array);
Vector* CreateVector(const int capacity){
  if (capacity < 1){
    return NULL;
  }
  Vector* vector = (Vector*) malloc(sizeof(Vector));
  if (vector == NULL){
    return NULL;
  }
  vector->array = (int*) malloc(capacity * sizeof(int));
  if (vector->array == NULL){
    free(vector);
    vector = NULL;
    return NULL;
  }
  vector->size = 0;
  vector->capacity = capacity;
  return vector;
}



// Destructor
void DestroyVector(Vector** vector_ptr){
  if (vector_ptr == NULL){
    return;
  }
  Vector* vector = *vector_ptr;
  free(vector->array);
  vector->array = NULL;
  free(vector);
  *vector_ptr = NULL;
}

void Add(const int value, Vector* vector){
  if (vector == NULL){
    return;
  }
  // Allocate more memory when not enough capacity
  if (vector->size == vector->capacity){
    // Double the capacity
    int* new_array = (int*) malloc(2 * vector->capacity * sizeof(int));
    vector->capacity *= 2;
    memcpy(new_array, vector->array, vector->size * sizeof(int));
    // Deallocate array
    free(vector->array);
    // Pointing to the new array
    vector->array = new_array;
  }
  // General case
  vector->array[vector->size] = value;
  vector->size++;
}
