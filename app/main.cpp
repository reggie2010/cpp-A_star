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
    grid.findPath();
    grid.printGrid();

    return 0;

}
