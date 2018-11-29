/*
Levi Mowery
lemowery@mix.wvu.edu
800096308
 */
#include <stdio.h>
#include <stdlib.h>
#include "assignment_3.h"

int main(int argc, char* argv[]){
  if (argc != 4){
    fprintf(stderr, "Usage: %s <input_file> <classifier_parameter_file> <output_file>\n",
	    argv[0]);
    return -1;
  }
  char* inputfilepath = argv[1];
  char* paramfilepath = argv[2];
  char* outputfilepath = argv[3];
  int number_of_points =  ReadSizeOfArrayOfPoints(inputfilepath);
  int* labels = (int*) malloc(number_of_points * sizeof(int));
  if (labels == NULL){
    fprintf(stderr, "Could not allocate memory for labels.\n");
    return -1;
  }
  Point* points = (Point*) malloc(number_of_points * sizeof(Point));
  if (points == NULL){
    fprintf(stderr, "Could not allocate memory for points.\n");
    free(labels);
    labels = NULL;
    return -1;
  }
  ClassifierParams* cp;
  if (!LoadClassifierParams(paramfilepath, cp)){
      fprintf(stderr, "Could not load parameter file.\n");
      free(points);
      points = NULL;
      free(labels);
      labels = NULL;
      return -1;
  }
  if (!ReadPoints(inputfilepath, number_of_points, points)){
    fprintf(stderr, "Could not read points.\n");
    free(points);
    points = NULL;
    free(labels);
    labels = NULL;
    return -1;
  }
  ClassifyPoints(points, number_of_points, cp, labels);
  FILE* outputfile = fopen(outputfilepath, "w");
  if (outputfile == NULL){
    fprintf(stderr, "Could not open outputfile.\n");
    free(points);
    points = NULL;
    free(labels);
    labels = NULL;
    return -1;
  }
  for (int i = 0; i < number_of_points; ++i){
    fprintf(outputfile, "%d\n", labels[i]);
  }
  fclose(outputfile);
  outputfile = NULL;
  free(labels);
  free(points);
  labels = NULL;
  points = NULL;
  return 0;
}
