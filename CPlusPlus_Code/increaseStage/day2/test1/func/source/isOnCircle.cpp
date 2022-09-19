#include "isOnCircle.hpp"
// 计算圆与点的关系:点在圆上为0，点在圆外为1，点在圆内为-1；
int isOnCircle(Point p1, Circle c1)
{
    int isFlag = cDistance(p1, c1.getPoint()) * cDistance(p1, c1.getPoint()) - c1.getRadius() * c1.getRadius();
    if (isFlag == 0)
    {
        return 0;
    }else if (isFlag > 0)
    {
        return 1;
    }
    return -1;
};