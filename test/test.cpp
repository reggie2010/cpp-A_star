#include <gtest/gtest.h>

#include "gridpoint.hpp"

Test(gridpoint, test1) {
    GridPoint p1(2,2);
    GridPoint p2(3,3);
    GridPoint p3(5,5);

    ASSERT_GE(p1.calG(p2), 10);
    ASSERT_GE(p1.calF(), 10);
    ASSERT_GT(p1.calH(p2), 0);

    ASSERT_EQ(p3, (p1+p2));
    ASSERT_EQ(p2, (p3-p1));
}
