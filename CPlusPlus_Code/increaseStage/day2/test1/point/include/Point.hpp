#pragma once
#include <iostream>
using namespace std;

class Point
{
    public:
        void setX (int x);

        int getX ();

        void setY (int y);

        int getY ();
    // ÊôĞÔ£ºXÓëY×ø±ê
    private:
        int m_x;
        int m_y;
};