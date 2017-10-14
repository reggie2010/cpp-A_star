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
    status = NONE;
}

void GridPoint::calG(GridPoint &gp) {
    g = g+gp.getG();
}

void GridPoint::calF() {
    f = g+h;
}

void GridPoint::calH(GridPoint &gp) {
    int deltaX {abs(x-gp.getX())};
    int deltaY {abs(y-gp.getY())};

    h = 10*(deltaX+deltaY);
}

int GridPoint::getG() { return g; }

int GridPoint::getF() { return f; }

int GridPoint::getH() { return h; }

GridPoint GridPoint::operator+(GridPoint p) {
    GridPoint newPoint;
    newPoint.setX(x + p.getX());
    newPoint.setY(y + p.getY());

    return newPoint;
}

GridPoint GridPoint::operator-(GridPoint p) {
    GridPoint newPoint;
    newPoint.setX(x - p.getX());
    newPoint.setY(y - p.getY());

    return newPoint;
}

std::ostream& operator<<(std::ostream &output, Point &p) {
    output << "GridPoint(" << p.getX() << "," << p.getY() << ")";
    return output;
}

bool operator==(GridPoint &gp1, GridPoint &gp2) {
    return (gp1.getX()==gp2.getX() && gp1.getY()==gp2.getY());
}

void GridPoint::setStatus(gridPointStatus s) {
    status = s;
}

int GridPoint::getStatus() {
    return status;
}

void GridPoint::setParent(GridPoint gp) {
    parent = std::make_shared<GridPoint>(gp);
}

















