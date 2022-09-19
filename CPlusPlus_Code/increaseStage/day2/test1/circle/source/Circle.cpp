#include "Circle.hpp"
#include "Point.hpp"

void Circle::setPoint(Point point)
{
    m_point = point;
}

Point Circle::getPoint()
{
    return m_point;
}

void Circle::setRadius(int radius)
{
    m_radius = radius;
}

int Circle::getRadius()
{
    return m_radius;
}
