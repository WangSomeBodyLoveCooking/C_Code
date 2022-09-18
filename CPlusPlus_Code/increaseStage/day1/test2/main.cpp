// 练习案例1：设计立方体类
// 设计立方体类(Cube)
// 求出立方体的面积和体积
// 分别用全局函数和成员函数判断两个立方体是否相等。
#include <iostream>
using namespace std;
#include "cube.hpp"

bool judgeEqual (Cube c1, Cube c2)
{
    bool flag = (c2.getLength() == c1.getLength() && c2.getWidth() == c1.getWidth() && c2.getHeight() == c1.getHeight());
    return flag;
}
int main()
{
    Cube c1;
    c1.setLength(10);
    c1.setWidth(10);
    c1.setHeight(10);
    Cube c2;
    c2.setLength(10);
    c2.setWidth(10);
    c2.setHeight(10);
    cout << "c1的面积为" << c1.getSpace() << endl;
    cout << "c1的体积为" << c1.getVolume() << endl;
    cout << "c2的面积为" << c2.getSpace() << endl;
    cout << "c2的体积为" << c2.getVolume() << endl;
    cout << "c1和c2是否相等?答案是" << c2.isEqual(c1) << endl; 
    cout << "c1和c2是否相等?答案是" << judgeEqual(c1, c2) << endl; 
    system ("pause");
    return 0;
}