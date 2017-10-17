/**
 *
 * @file    grid.cpp
 * @brief   Grid class header file
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#ifndef GRID_H
#define GRID_H

#include "gridpoint.hpp"
#include <memory>
#include "vector"

bool myFunc(std::shared_ptr<GridPoint> a, std::shared_ptr<GridPoint> b);

class Grid {
  public:
    Grid();
    void printGrid();
    int findIndex(GridPoint &);
    void findPath();

  private:
    int gridSize;
    std::vector<GridPoint> grid;
    std::vector<std::shared_ptr<GridPoint>> openList;
    std::vector<std::shared_ptr<GridPoint>> closedList;
    int iStart;
    int iDestination;


  	
};


#endif