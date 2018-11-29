/*
  To compile, execute:
  gcc test_main.c assignment_2.c -o test -lm
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "assignment_2.h"
#include "input_data.h"

void TestInvalidPalindrome() {
  const char* non_palindrome_words[] = {"Hello", "World", "Dell", "", "wvu"};
  int i;
  for (i = 0; i < 5; ++i) {
    if (IsPalindrome(non_palindrome_words[i])) {
      printf("ERROR: %s is not plindrome!\n", non_palindrome_words[i]);
    }
  }
}

void TestValidPalindrome() {
  const char* non_palindrome_words[] =
      {"abBA", "AnNa", "a", "CiVIc", "RePAper"};
  int i;
  for (i = 0; i < 5; ++i) {
    if (!IsPalindrome(non_palindrome_words[i])) {
      printf("ERROR: %s is plindrome!\n", non_palindrome_words[i]);
    }
  }
}

void TestConcatenateStringsValidInput() {
  const char* words[] =
      {"Hello", "World", "Good Job", "Students", "", "Nothing 23!"};
  char output[512] = {0};
  int i;
  for (i = 0; i < 5; i += 2) {
    char expected_output[512] = {0};
    strcat(expected_output, &words[i][0]);
    strcat(expected_output, &words[i + 1][0]);
    ConcatenateStrings(&words[i][0], &words[i + 1][0], output);
    if (strcmp(expected_output, output)) {
      printf("ERROR: Expected output: %s Returned Output: %s\n",
             expected_output, output);
    }
  }
}

void TestTransposeMatrix() {
  const int kNumColumns = 32;
  const int num_entries = kNumColumns * kNumColumns;
  int i;
  float error = 0.0f;
  TransposeMatrix(kNumColumns, input_matrix);
  for (i = 0; i < num_entries; ++i) {
    error += fabs(input_matrix[i] - transposed_matrix[i]);
  }
  if (error > 1e-6) {
    printf("ERROR: Transpose matrix does not match.");
  }
}

void TestNegativeNumColumnsToTransposeMatrix() {
  float matrix[] = {
    000-0.999984,000-0.736924,00000.511211,00-0.0826997,
    0000.0655345,000-0.562082,000-0.905911,00000.357729,
    00000.358593,00000.869386,000-0.232996,0000.0388328,
    00000.661931,000-0.930856,000-0.893077,0000.0594004,
  };
  const float original_matrix[] = {
    000-0.999984,000-0.736924,00000.511211,00-0.0826997,
    0000.0655345,000-0.562082,000-0.905911,00000.357729,
    00000.358593,00000.869386,000-0.232996,0000.0388328,
    00000.661931,000-0.930856,000-0.893077,0000.0594004,
  };
  const int size = sizeof(matrix) / sizeof(matrix[0]);
  int i;
  float error = 0.0f;
  TransposeMatrix(-size, matrix);
  for (i = 0; i < size; ++i) {
    error += fabs(matrix[i] - original_matrix[i]);
  }
  if (error > 1e-6) {
    printf("ERROR: Negative size input not handled properly.");
  }
}

int wvuIsSorted(const float* begin, const float* end) {
  while (begin < end) {
    if (*begin > *(begin + 1)) {
      return 0;
    }
    ++begin;
  }
  return 1;
}

void TestValidInputToSortRowsMatrix() {
  const int kMaxTrials = 3;
  int i = 0;
  for (; i < kMaxTrials; ++i) {
    int row;
    SortRowsOfMatrix(16, 32, &trials[i][0]);
    float* row_ptr = &trials[i][0];
    for (row = 0; row < 16; ++row) {
      if (!wvuIsSorted(row_ptr, row_ptr + 31)) {
        puts("Found row not sorted!");
      }
      row_ptr += 32;
    }
  }
}

void TestInvalidNumRowsAndNumColsToSortRowsMatrix() {
  float input[64] = {0.0f};
  input[0] = -3.0f;
  SortRowsOfMatrix(-5, -5, input);
  if (!wvuIsSorted(input, input + 63)) {
    puts("Invalid num. rows or cols not handled properly!");
  }
}

void TestValidInputToMultiplyMatrices() {
  const int kNumColumns = 10;
  const int kNumRows = 8;
  float result[kNumRows * kNumRows];
  float product[kNumRows * kNumColumns];
  int i;
  float error;
  /* result = identity x matrix_1 = matrix_1. */
  MultiplyMatrices(kNumRows, kNumRows, identity,
                   kNumRows, kNumRows, matrix_1,
                   result);
  error = 0.0;
  for (i = 0; i < kNumRows * kNumRows; ++i) {
    error += fabs(result[i] - matrix_1[i]);
  }
  if (error > 1e-6) {
    puts("ERROR: Invalid matrix multiplication result.");
  }
  /* result = matrix_1 x matrix_2. */
  MultiplyMatrices(kNumRows, kNumRows, matrix_1,
                   kNumRows, kNumColumns, matrix_2,
                   product);
  error = 0.0;
  for (i = 0; i < kNumColumns * kNumRows; ++i) {
    printf("%f\n", product[i]);
    error += fabs(product[i] - expected_result[i]);
  }
  if (error > 1e-3) {
    printf("ERROR1: Invalid matrix multiplication result.\n");
  }
}

void TestIncompatibleMatrixDimensionsToToMultiplyMatrices() {
  const int kNumColumns = 10;
  const int kNumRows = 8;
  float product[80] = {0.0f};
  int i;
  float error;
  MultiplyMatrices(kNumRows - 1, kNumRows - 1, matrix_1,
                   kNumRows, kNumColumns - 2, matrix_2,
                   product);
  error = 0.0f;
  for (i = 0; i < kNumRows * kNumColumns; ++i) {
    error += product[i];
  }
  if (error > 1e-8) {
    printf("ERROR: Invalid matrix multiplication.\n");
  }
}

int main() {
  /* Palindrome. */
  TestInvalidPalindrome();
  TestValidPalindrome();

  /* Concatenate strings. */
  TestConcatenateStringsValidInput();

  /* Transpose matrix. */
  TestTransposeMatrix();
  TestNegativeNumColumnsToTransposeMatrix();

  /* SortRowsOfMatrix. */
  TestValidInputToSortRowsMatrix();
  TestInvalidNumRowsAndNumColsToSortRowsMatrix();

  /* Matrix multiplication. */
  TestValidInputToMultiplyMatrices();
  TestIncompatibleMatrixDimensionsToToMultiplyMatrices();

  return 0;
}
