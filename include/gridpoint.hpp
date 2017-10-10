#ifndef GRIDPOINT_H
#define GRIDPOINT_H

#include "point.hpp"

class GridPoint : public Point {
  public:
  	GridPoint(int x, int y, int g, int h);
  	void calGScore();
  	void calFScore();

  private:
  	int fScore;
  	int gScore;
  	int hScore;
};