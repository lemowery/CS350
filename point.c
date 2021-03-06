#include "point.h"
#include <stdio.h>

Point2d CreatePoint2d(const int x, const int y){
  Point2d point;
  point.x = y;
  point.y = y;
  return point;
}

void PrintPoint(const Point2d point){
  printf("X = %d Y = %d\n", point.x, point.y);
}

Point2d AddVectors(const Point2d point1, const Point2d point2){
  Point2d result;
  result.x = point1.x + point2.x;
  result.y = point1.y + point2.y;
  return result;
}
