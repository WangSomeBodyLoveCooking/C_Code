#pragma once
#include "Point.hpp"

class Circle
{
    // 方法
    public:
        void setPoint(Point point);
  
        Point getPoint();

        void setRadius(int radius);

        int getRadius();
  
    // 属性：圆心和半径
    private:
        Point m_point;
        int m_radius;
};