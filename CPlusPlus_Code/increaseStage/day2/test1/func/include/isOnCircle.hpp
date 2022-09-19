#pragma once
#include "Circle.hpp"
#include "Point.hpp"
#include "cDistance.hpp"
// 计算圆与点的关系:点在圆上为0，点在圆外为1，点在圆内为-1；
int isOnCircle(Point p1, Circle c1);
