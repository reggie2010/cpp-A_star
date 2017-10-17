/**
 *
 * @file    gridpoint.cpp
 * @brief   Implementation of GridPoint class functions
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#include <iostream>
#include "gridpoint.hpp"

GridPoint::GridPoint() {};

GridPoint::GridPoint(int x, int y) : Point(x,y) {
    // GridPoint conwtructor calls Point constructor
    // to initialize points x and y
    status = NONE;
}

void GridPoint::calG(GridPoint &gp) {
    // Function that calculates g (Cost per block move)
    g = g+gp.getG();
}

void GridPoint::calF() {
    // Calculates f
    f = g+h;
}

void GridPoint::calH(GridPoint &gp) {
    // Calculates the h heurestic
    // the distance of the point from destination
    int deltaX {abs(x-gp.getX())};
    int deltaY {abs(y-gp.getY())};

    h = 10*(deltaX+deltaY);
}

int GridPoint::getG() { return g; }

int GridPoint::getF() { return f; }

int GridPoint::getH() { return h; }

GridPoint GridPoint::operator+(GridPoint p) {
    // Function allows for the adding of two GridPoints
    GridPoint newPoint;
    newPoint.setX(x + p.getX());
    newPoint.setY(y + p.getY());

    return newPoint;
}

GridPoint GridPoint::operator-(GridPoint p) {
    // Function allows for subtracting two GridPoints
    GridPoint newPoint;
    newPoint.setX(x - p.getX());
    newPoint.setY(y - p.getY());

    return newPoint;
}

std::ostream& operator<<(std::ostream &output, GridPoint &p) {
    // Function for printing a GridPoint with normal c++ cout
    output << "GridPoint(" << p.getX() << "," << p.getY() << ",f:" << p.getF() \
    << ", g:" << p.getG() << ", h:" << p.getH() << ")";
    return output;
}

bool operator==(GridPoint &gp1, GridPoint &gp2) {
    // Functionto use == to compare to GridPoints 
    return (gp1.getX()==gp2.getX() && gp1.getY()==gp2.getY());
}

void GridPoint::setStatus(gridPointStatus s) {
    // Sets the status of a GridPoint
    status = s;
}

int GridPoint::getStatus() {
    // returns the status of a GridPoint
    return status;
}

















