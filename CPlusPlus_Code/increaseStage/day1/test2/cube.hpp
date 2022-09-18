// �����������(Cube)
// ������������������
#pragma once
#include <iostream>
using namespace std;

class Cube
{
    public:
        int getSpace ();

        int getVolume ();

        bool isEqual (Cube c1);
        
        void setLength (int length);

        int getLength ();

        void setWidth (int width);

        int getWidth ();

        void setHeight (int height);
     
        int getHeight ();
    
    private:
        int m_length;
        int m_width;
        int m_height;
};
