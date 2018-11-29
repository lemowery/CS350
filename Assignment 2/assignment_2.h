/* 
Levi Mowery
lemowery@mix.wvu.edu
800096308
 */
#ifndef ASSIGNMENT_2
#define ASSIGNMENT_2
#define TRUE 1
#define FALSE 0


int IsPalindrome(const char* str1);

void ConcatenateStrings(const char* str1, const char* str2, char* newString);

void TransposeMatrix(const int col, float* topLeft);

void SortRowsOfMatrix(const int row, const int col, float* topLeft);

void MultiplyMatrices(const int row1, const int col1, const float* topLeft,
		      const int row2, const int col2, const float* topLeft2,
		      float* newTopLeft);

int BinarySearch(const int* firstSorted, const int* lastSorted, const int searchNum);

int IsSorted(const int currentRow, const int size, const float* array);

void PrintMatrix(const int row, const int col, const float* array);


#endif
