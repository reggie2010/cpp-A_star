/**
 *
 * @file    point.cpp
 * @brief   Implementation of Point class functions
 * @author  Vontrelle Collins
 * @copyright MIT License
 *
 **/

#include <iostream>
#include <cmath>
#include "point.hpp"


Point::Point(int x, int y) : x(x), y(y) {}

Point::Point() {}

int Point::getX() { return x; }

int Point::getY() { return y; }

void Point::setX(int newX) {
	x = newX;
}

void Point::setY(int newY) {
	y = newY;
}

int Point::distance(Point p) {
	return sqrt(pow((x - p.getX()), 2) + pow((y - p.getY()), 2));
}