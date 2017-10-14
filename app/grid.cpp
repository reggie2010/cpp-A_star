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

    auto N {grid.size()-1};

    std::random_device rand;
    std::mt19937 mt(rand());
    std::uniform_int_distribution<int> randomIndex(0, N);

    start = std::make_shared<GridPoint>(grid[randomIndex(mt)]);
    start->setStatus(OPEN);

    destination = std::make_shared<GridPoint>(grid[randomIndex(mt)]);
    destination->setStatus(CLOSED);

    unsigned long index {0};
    while(index<=N) {
        grid[index].calH(*destination);
        ++index;
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