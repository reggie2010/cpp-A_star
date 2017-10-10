#ifndef POINT_H
#define POINT_H

class Point {
  public:
  	Point(int x, int y);
  	int getX();
  	int getY();

  private:
  	int x {0};
  	int y {0};
};


#endif