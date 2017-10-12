#ifndef GRIDPOINT_H
#define GRIDPOINT_H

#include <iostream>
#include "point.hpp"

class GridPoint : public Point {
  public:
  	GridPoint();
  	GridPoint(int x, int y);
  	void calGScore();
  	void calFScore();
  	void calHScore();
  	GridPoint operator+(GridPoint p);
  	GridPoint operator-(GridPoint p);
  	friend std::ostream& operator<<(std::ostream &, Point &);

  private:
  	int fScore;
  	int gScore;
  	int hScore;
};

#endif