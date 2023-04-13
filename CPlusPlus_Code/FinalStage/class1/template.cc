#include <iostream>
using namespace std;
//ģ��
//1. ����ģ���﷨
template <typename T>
void swapFunc(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test1()
{
    int a = 10;
    int b = 20;
    swapFunc(a, b); //�Զ������Ƶ�
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    char c = 'c';
    char d = 'd';
    swapFunc<char>(c, d);   //��ʾָ������
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

//2. ����ģ���ע������
template <class T>
void func()
{
    cout << "����һ��ģ��" <<endl;
}

void test2()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    // swapFunc(a. c); // �Զ������Ƶ�����Ҫȷ��һ��ͳһ���ͣ�����

    // func(); //��ʾָ�����ͱ���ָ�����ͣ�
    func<int>();
}

int main()
{
    // test1();
    test2();
    system("pause");
    return 0;
}