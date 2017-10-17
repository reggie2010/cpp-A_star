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
  START,
  DESTINATION,
  BLOCKED,
  PATH,
  NONE
};

class GridPoint : public Point {
  public:
    GridPoint();
    GridPoint(int x, int y);
    void calG(GridPoint &);
    void calF();
    void calH(GridPoint &);
    int getG();
    int getF();
    int getH();
    GridPoint operator+(GridPoint p);
    GridPoint operator-(GridPoint p);
    friend std::ostream& operator<<(std::ostream &, GridPoint &);
    friend bool operator==(GridPoint &, GridPoint &);
    void setStatus(gridPointStatus);
    int getStatus();

  private:
    std::shared_ptr<GridPoint> parent;
    gridPointStatus status;
    int f;
    int g {10};
    int h;
};

#endif