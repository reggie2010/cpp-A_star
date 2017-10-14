/**
 *
 * @file    grid.cpp
 * @brief   Implementation of Grid class functions
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#include <iostream>
#include <vector>
#include <random>
#include "grid.hpp"

Grid::Grid(int size) : gridSize(size) {

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            GridPoint p(i,j);
            grid.push_back(p);
        }
    }

}

void Grid::printGrid() {
    unsigned index {1};

    while(index <= grid.size()){
        
        if(grid[index-1] == *start)
            std::cout << "O ";
        else if(grid[index-1] == *destination)
            std::cout << "X ";
        else
            std::cout << "- ";

        if((index % gridSize) == 0)
            std::cout << std::endl;

        ++index;

    }
}

std::vector<GridPoint> Grid::findPath() {
    std::vector<GridPoint> path;

    return path;
}