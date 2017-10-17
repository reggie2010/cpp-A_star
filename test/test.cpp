#include <gtest/gtest.h>

#include "gridpoint.hpp"

TEST(Point, gribpoint_check) {
    GridPoint p1(2,2);
    GridPoint p2(3,3);
    GridPoint p3(5,5);

    GridPoint a = p1+p2;
    GridPoint b = p3-p1;

    ASSERT_TRUE(p3==a);
    ASSERT_TRUE(p2==b);

    p1.calH(p3);
    p1.calG(p2);
    p1.calF();

    ASSERT_GE(p1.getG(), 10);
    ASSERT_GT(p1.getH(), 0);
    ASSERT_GT(p1.getF(), 0);
}
