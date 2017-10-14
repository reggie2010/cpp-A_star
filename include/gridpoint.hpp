/**
 *
 * @file    gridpoint.cpp
 * @brief   GridPoint class header file
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#ifndef GRIDPOINT_H
#define GRIDPOINT_H

#include <iostream>
#include <memory>
#include "point.hpp"

enum gridPointStatus {
  OPEN,
  CLOSED,
  NONE
};

class GridPoint : public Point {
  public:
    GridPoint();
    GridPoint(int x, int y);
    void calGScore();
    void calFScore();
    void calHScore(GridPoint &);
    int getH();
    GridPoint operator+(GridPoint p);
    GridPoint operator-(GridPoint p);
    friend std::ostream& operator<<(std::ostream &, Point &);
    friend bool operator==(GridPoint &, GridPoint &);
    void setStatus(gridPointStatus);
    int getStatus();
    void setParent(GridPoint);

  private:
    std::shared_ptr<GridPoint> parent;
    gridPointStatus status;
    int f;
    int g;
    int h;
};

#endif