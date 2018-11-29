#include "point.h"

#define SIZE 10

int main(){
  Point2d point[SIZE];
  //Constructs point and copies it into point
  point[0] = CreatePoint2d(5, 5);
  point[1] = CreatePoint2d(0, 0);
  PrintPoint(point[0]);
  PrintPoint(point[1]);
  point[2] = AddVectors(point[0], point[1]);
  PrintPoint(point[2]);
  return 0;
}
