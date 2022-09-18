#include "cube.hpp"

int Cube::getSpace()
{
    return 2 * (getLength() * getWidth() + getLength() * getHeight() + getHeight() * getWidth());
}

int Cube::getVolume()
{
    return getLength() * getWidth() * getHeight();
}

bool Cube::isEqual(Cube c1)
{
    bool flag = (getLength() == c1.getLength() && getWidth() == c1.getWidth() && getHeight() == c1.getHeight());
    return flag;
}

void Cube::setLength(int length)
{
    m_length = length;
}

int Cube::getLength()
{
    return m_length;
}

void Cube::setWidth(int width)
{
    m_width = width;
}

int Cube::getWidth()
{
    return m_width;
}

void Cube::setHeight(int height)
{
    m_height = height;
}

int Cube::getHeight()
{
    return m_height;
}