/*
Levi Mowery
lemowery@mix.wvu.edu
800096308
 */
#ifndef ASSIGNMENT_3_
#define ASSIGNMENT_3_

#define TRUE 1
#define FALSE 0

typedef struct Point{
  float x;
  float y;
  float z;
  float w;
} Point;

typedef struct ClassifierParams{
  float wx;
  float wy;
  float wz;
  float ww;
  float bias;
} ClassifierParams;

int ClassifyPoint(const Point* point, const ClassifierParams* cp);

void ClassifyPoints(const Point* points, const int size, const ClassifierParams* cp,
		    int* labels);

int ReadSizeOfArrayOfPoints(const char* filepath);

int ReadPoints(const char* filepath, const int numberofpoints, Point* points);

int LoadClassifierParams(const char* filepath, ClassifierParams* cp);

#endif
