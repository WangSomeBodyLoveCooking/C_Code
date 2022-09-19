#include "cDistance.hpp"
#include "Point.hpp"

/// 计算两点间的距离
double cDistance (Point p1, Point p2)
{
    double d1 = sqrt(((p1.getX() - p2.getX()) * (p1.getX() - p2.getX())) + ((p1.getY() - p2.getY()) * (p1.getY() - p2.getY())));
    return d1;
}