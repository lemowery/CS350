/*
  Testing compilation code. This program does not test all the possible corner
  cases that your solution should consider.

  To compile with your solution:
  $ gcc test_main.c assignment_3.c -o test -lm

  Execute with testing binary points example.
  $ ./test classifier_params.dat
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assignment_3.h"

#define NUM_POINTS 256

float GenerateRandomFloat() {
  static const float kRandMax = (float) RAND_MAX;
  return rand() / kRandMax;
}

void GenerateRandomPoints(const int num_points_per_class,
                          Point* points_ptr,
                          int* labels) {
  if (!points_ptr) {
    return;
  }
  // Points for class 1.
  for (int i = 0; i < num_points_per_class; ++i) {
    points_ptr->x = 2.0f + GenerateRandomFloat();
    points_ptr->y = 2.0f + GenerateRandomFloat();
    points_ptr->z = 2.0f + GenerateRandomFloat();
    points_ptr->w = 2.0f + GenerateRandomFloat();
    *labels++ = 1;
    points_ptr++;
  }
  // Points for class 1.
  for (int i = 0; i < num_points_per_class; ++i) {
    points_ptr->x = GenerateRandomFloat() - 2.0f;
    points_ptr->y = GenerateRandomFloat() - 2.0f;
    points_ptr->z = GenerateRandomFloat() - 2.0f;
    points_ptr->w = GenerateRandomFloat() - 2.0f;
    *labels++ = -1;
    points_ptr++;
  }  
}

float ComputeAccuracy(const int num_points_per_class,
                      const int* labels) {
  int num_total_points = 2 * num_points_per_class;
  float acc = 0.0f;
  // Positive class.
  for (int i = 0; i < num_points_per_class; ++i) {
    if (labels[i] == 1) {
      acc += 1.0f;
    }
  }
  for (int i = 0; i < num_points_per_class; ++i) {
    if (labels[i + num_points_per_class] == -1) {
      acc += 1.0f;
    }
  }  
  return acc / num_total_points;
}

ClassifierParams GetDefaultClassifier() {
  ClassifierParams params;
  params.wx = 1.0f;
  params.wy = 1.0f;
  params.wz = 1.0f;
  params.ww = 1.0f;
  params.bias = 0.0f;
  return params;
}

int AreParamsDifferent(const ClassifierParams* params) {
  ClassifierParams baseline = GetDefaultClassifier();
  if (fabs(params->wx - baseline.wx) < 1e-3 ||
      fabs(params->wy - baseline.wy) < 1e-3 ||
      fabs(params->wz - baseline.wz) < 1e-3 ||
      fabs(params->ww - baseline.ww) < 1e-3 ||
      fabs(params->bias - baseline.bias) < 1e-3) {
    return FALSE;
  }
  return TRUE;
}

/* Entry point. */
int main(int argc, char** argv) {
  Point points[NUM_POINTS];
  int labels[NUM_POINTS];
  ClassifierParams params = GetDefaultClassifier();
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <classifier params>\n", argv[0]);
    return 1;
  }
  // Load classifier.
  if (!LoadClassifierParams(argv[1], &params)) {
    fprintf(stderr, "Could load file: %s\n", argv[1]);
    return 1;
  }
  // Test the loaded params.
  if (!AreParamsDifferent(&params)) {
    fprintf(stderr, "Classifier parameters were not loaded correctly\n");
    return 1;    
  }
  // Generate random points.
  GenerateRandomPoints(NUM_POINTS / 2, points, labels);
  // Test.
  srand(time(NULL));
  ClassifyPoints(points, NUM_POINTS, &params, labels);
  // Measure accuracy.
  const float acc = ComputeAccuracy(NUM_POINTS / 2, labels);
  if (acc < 0.95f) {
    printf("ERROR: Classifier accuracy is less than 95 pct. Accuracy=%f\n",
           acc);
    return 1;
  }
  return 0;
}
