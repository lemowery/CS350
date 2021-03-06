// Implement the following data structure named vector
//
// An array that:
// 1. Knows its size
// 2. Allows a user to keep storing information
#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct Vector{
  int size; // Size of the vector, i.e. how many elements are stored.
  int capacity; // This tells how much memory I have available for storage
  int* array; // Our memory block in the heap
} Vector;

// Constructor
// void InitializeVector(const int capacity, Vector* array);
Vector* CreateVector(const int capacity);

// Add to end of array
void Add(const int value, Vector* vector);

// Destructor
void DestroyVector(Vector** vector);

#endif
