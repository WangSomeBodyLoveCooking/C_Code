// ȷ������Բ�Ĺ�ϵ
#include <iostream>
using namespace std;
#include "Circle.hpp"
#include "cDistance.hpp"
#include "isOnCircle.hpp"

int main()
{
    Point p1;
    p1.setX(6);
    p1.setY(0);
    Point p2;
    p2.setX(0);
    p2.setY(0);
    Circle c1;
    c1.setPoint(p2);
    c1.setRadius(5);
    double d1 = cDistance(p1, c1.getPoint());
    cout << "��������Ϊ" << d1 << endl;
    int i1 = isOnCircle(p1, c1);
    cout << "����Բ�Ĺ�ϵΪ" << i1 << endl;
    system("pause");
    return 0;
}