#include "isOnCircle.hpp"
// ����Բ���Ĺ�ϵ:����Բ��Ϊ0������Բ��Ϊ1������Բ��Ϊ-1��
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