#include <iostream>
using namespace std;

#define DAY 7
int main()
{
    //���峣����ʽ��1. �궨��ı�ʶ������ 2.const���εĳ�����
    //1.
    //  DAY = 3;  error  ����
    cout << "һ��һ����" << DAY << "��"  << endl;
    //2.
    const int year = 12;
    // year = 13;   error  ����
    cout << "һ��һ����" << year << "��" << endl;
    system("pause");
    return 0;
}