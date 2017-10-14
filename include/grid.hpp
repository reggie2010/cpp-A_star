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

class Grid {
  public:
    Grid(int size);
    void printGrid();
    std::vector<GridPoint> findPath();

  private:
    int gridSize;
    std::vector<GridPoint> grid;
    std::shared_ptr<GridPoint> start;
    std::shared_ptr<GridPoint> destination;

  	
};


#endif