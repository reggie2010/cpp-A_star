/**
 *
 * @file    point.hpp
 * @brief   Point class hearder file
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
  public:
    Point();
    Point(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    int distance(Point);

  protected:
    int x {0};
    int y {0};
};


#endif