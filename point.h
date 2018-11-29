#ifndef POINT_H_
#define POINT_H_

typedef struct Point2d {
  int x;
  int y;
} Point2d ;

//void InitializePoint2d(const int x, const int y, Point2d* point);
Point2d CreatePoint2d(const int x, const int y);
//Print members of Point2d
void PrintPoint(const Point2d point);
//Function to add two Point2d int a third one
Point2d AddVectors(const Point2d point1, const Point2d point2);


#endif
