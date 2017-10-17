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

    iStart = startIndex(mt);
    iDestination = destinationIndex(mt);

    grid[iStart].setStatus(START);
    grid[iDestination].setStatus(DESTINATION);

    unsigned long index {0};
    while(index<=N) {
        grid[index].calH(grid[iDestination]);
        ++index;
    }
}


void Grid::printGrid() {

    int colCount {1};
    for(auto point : grid) {

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
        

        if(colCount%gridSize == 0)
            std::cout << std::endl;

        ++colCount;

    }
}

int Grid::findIndex(GridPoint &p) {

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

    closedList.push_back(std::make_shared<GridPoint>(grid[iStart]));
    bool pathfound {false};
    
    GridPoint x(1,0);
    GridPoint y(0,1);


    std::shared_ptr<GridPoint> p;
    int index {15};
    int ii {0};

    do {
        int i = findIndex(*closedList[ii]);
         p = std::make_shared<GridPoint>(grid[i]);
    
        std::vector<GridPoint> children {GridPoint(*p+x), GridPoint(*p-x),GridPoint(*p+y), GridPoint(*p-y)};

        std::shared_ptr<GridPoint> e = std::make_shared<GridPoint>(grid[findIndex(children[0])]);
        e->calF();
        openList.push_back(e);

        std::shared_ptr<GridPoint> w = std::make_shared<GridPoint>(grid[findIndex(children[1])]);
        w->calF();
        openList.push_back(w);
    
        std::shared_ptr<GridPoint> n = std::make_shared<GridPoint>(grid[findIndex(children[2])]);
        n->calF();
        openList.push_back(n);
    
        std::shared_ptr<GridPoint> s = std::make_shared<GridPoint>(grid[findIndex(children[3])]);
        s->calF();
        openList.push_back(s);

        std::sort (openList.begin(), openList.end(), myFunc);

        for(auto point : openList) {
            if(point->getStatus() == DESTINATION)
                pathfound = true;
        }


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
        return (a->getF() < b->getF());
}



