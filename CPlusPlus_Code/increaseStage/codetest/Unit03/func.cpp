// 3. �������

#include <iostream>
using namespace std;

// 3.1 ������Ĭ�ϲ���

// int  functest(int a, int b = 10, int c = 20);    // ע��������Ĭ�ϲ���������������ʵ����ֻ�ܴ���һ����Ĭ�ϲ��������

int  functest(int a, int b = 10, int c = 20)    // ������Ĭ�ϲ���
{
    return a + b + c;
}

// int  functest1(int a = 20, int b, int c)    // ע�������β���һ����Ĭ�ϲ�������Ӹ��βο�ʼ���ҵĸ���������Ҫ��Ĭ�ϲ���
// {
//     return a + b + c;
// }


// 3.2 ������ռλ��
int funcTest(int a, int = 10)    //����ռλ��Ҳ������Ĭ�ϲ���
{
    return a;
}

// 3.3 ����������   ��������ͬ����߸�����
//������Ҫ�أ�
// 1. ������������ͬ��
// 2.��������ͬ��
// 3.�����ββ�ͬ��������ͬ�����Ͳ�ͬ��˳��ͬ��
// 4.��������ֵ������Ϊ����������
int funTest()
{
    return 0;
}

int funTest(int a)
{
    return 0;
}

int funTest(double a)
{
    return 0;
}

int funTest(int a, double b)
{
    return 0;
}

int funTest(double b, int a)
{
    return 0;
}

// ������Ϊ���ص�����
int funTest(int &a)
{
    return 0;
}

int funTest(const int &a)
{
    return 0;
}

// Ĭ�ϲ�������������
// int funTest(int a, double b = 0.0)
// {
//     return 0;
// }

int main()
{
    int x = 0;
    x = functest(10);
    cout << x << endl;
    // x= functest1(20, 30);
    int &y = x;
    funcTest(y);
    funcTest(10);

    cout << x << endl;
    system("pause");
    return 0;
}