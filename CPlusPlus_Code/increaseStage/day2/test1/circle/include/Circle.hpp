#pragma once
#include "Point.hpp"

class Circle
{
    // ����
    public:
        void setPoint(Point point);
  
        Point getPoint();

        void setRadius(int radius);

        int getRadius();
  
    // ���ԣ�Բ�ĺͰ뾶
    private:
        Point m_point;
        int m_radius;
};