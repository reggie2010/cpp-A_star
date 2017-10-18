/**
 *
 * @file    main.cpp
 * @brief   Applications main function
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#include <iostream>
#include "grid.hpp"

int main() {

    Grid grid;
    grid.printGrid();
    std::cout << std::endl;
    grid.findPath();
    grid.printGrid();

    return 0;

}
