// ��ϰ����1�������������
// �����������(Cube)
// ������������������
// �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
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
    cout << "c1�����Ϊ" << c1.getSpace() << endl;
    cout << "c1�����Ϊ" << c1.getVolume() << endl;
    cout << "c2�����Ϊ" << c2.getSpace() << endl;
    cout << "c2�����Ϊ" << c2.getVolume() << endl;
    cout << "c1��c2�Ƿ����?����" << c2.isEqual(c1) << endl; 
    cout << "c1��c2�Ƿ����?����" << judgeEqual(c1, c2) << endl; 
    system ("pause");
    return 0;
}