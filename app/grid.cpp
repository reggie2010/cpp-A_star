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
#include <algorithm>
#include "grid.hpp"

Grid::Grid() : gridSize(20) {

    // Populates gridwith gridpoints
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<gridSize; j++) {
            GridPoint p(j,i);
            grid.push_back(p);
        }
    }

    auto N {grid.size()-1};

    std::random_device rand;
    std::mt19937 mt(rand());
    std::uniform_int_distribution<int> startIndex(0, (N/2)-1);
    std::uniform_int_distribution<int> destinationIndex(N/2, N);

    // Random start point of robot
    iStart = startIndex(mt);

    // Random destination of robot
    iDestination = destinationIndex(mt);

    grid[iStart].setStatus(START);
    grid[iDestination].setStatus(DESTINATION);


    // Calculate the h heurestic for each
    // gridpoint in the grid
    unsigned long index {0};
    while(index<=N) {
        grid[index].calH(grid[iDestination]);
        ++index;
    }
}


void Grid::printGrid() {
    // Print out any given state of the grid

    int colCount {1};
    for(auto point : grid) {

        // Chdcks status of each grippoint on the grid
        // prints correct symbol
        switch(point.getStatus()) {

            case START:
                std::cout << "O ";
                break;

            case DESTINATION:
                std::cout << "X ";
                break;

            case PATH:
                std::cout << "# ";
                break;

            default:
                std::cout << "- ";
        }
        
        // Prints newline every count of gridsize
        if(colCount%gridSize == 0)
            std::cout << std::endl;

        ++colCount;

    }
}

int Grid::findIndex(GridPoint &p) {
    // Returns the index of the given gridpoint in the grid
    // The grid is a vector grid
    int index {0};
    int i {0};
    for(auto gp : grid) {
        if(gp == p)
            index = i;

        ++i;
    }

    return index;
}

void Grid::findPath() {
    // Find the path from start to destination

    closedList.push_back(std::make_shared<GridPoint>(grid[iStart]));
    bool pathfound {false};
    
    GridPoint x(1,0);
    GridPoint y(0,1);

    // Parent gridpoint
    std::shared_ptr<GridPoint> p;
    int index {15};
    int ii {0};

    // Finds 4 surrounding gridpoints of the parent
    do {
        int i = findIndex(*closedList[ii]);
         p = std::make_shared<GridPoint>(grid[i]);
    
        std::vector<GridPoint> children {GridPoint(*p+x), GridPoint(*p-x),GridPoint(*p+y), GridPoint(*p-y)};

        std::shared_ptr<GridPoint> e = std::make_shared<GridPoint>(grid[findIndex(children[0])]);
        e->calF();

        if(!(findIndex(*e) < 0))
            openList.push_back(e);

        std::shared_ptr<GridPoint> w = std::make_shared<GridPoint>(grid[findIndex(children[1])]);
        w->calF();

        if(!(findIndex(*w) < 0))
            openList.push_back(w);

    
        std::shared_ptr<GridPoint> n = std::make_shared<GridPoint>(grid[findIndex(children[2])]);
        n->calF();
        
        if(!(findIndex(*n) < 0))
            openList.push_back(n);
    
        std::shared_ptr<GridPoint> s = std::make_shared<GridPoint>(grid[findIndex(children[3])]);
        s->calF();
        
        if(!(findIndex(*s) < 0))
            openList.push_back(s);

        std::sort (openList.begin(), openList.end(), myFunc);

        for(auto point : openList) {
            if(point->getStatus() == DESTINATION)
                pathfound = true;
        }

        // If gridpoint is not in grid
        // Don't add it to the open list
        if(pathfound == false) {
            grid[findIndex(*openList[0])].setStatus(PATH);
            closedList.push_back(openList[0]);
            openList.erase(openList.begin());
        }
        
        ++ii;
        --index;


    }while(!pathfound);
    

}


bool myFunc(std::shared_ptr<GridPoint> a, std::shared_ptr<GridPoint> b) {
    // Helper funtion used for sorting open list
    return (a->getF() < b->getF());
}



