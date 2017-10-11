#ifndef GRID_H
#define GRID_H

#include "gridpoint.hpp"
#include "vector"

class Grid {
  public:
  	Grid(int size);
  	std::vector<GridPoint> findPath();

  private:
  	int gridSize;
  	std::vector<GridPoint> openList;
  	std::vector<GridPoint> closedList;

};


#endif