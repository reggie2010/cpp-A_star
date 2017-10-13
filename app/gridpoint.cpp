#include <iostream>
#include "gridpoint.hpp"

GridPoint::GridPoint() {};

GridPoint::GridPoint(int x, int y) : Point(x,y) {
	status = NONE;
}

void GridPoint::calGScore() {
	std::cout << "Needs Work" << std::endl;
}

void GridPoint::calFScore() {
	std::cout << "Needs Work" << std::endl;
}

void GridPoint::calHScore() {
	std::cout << "Needs Work" << std::endl;
}

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

void GridPoint::setStatus(gridPointStatus s) {
	status = s;
}

int GridPoint::getStatus() {
	return status;
}

















