// ��ģ���еĳ�Ա��������ͨ���г�Ա����������
// ��ģ���еĳ�Ա����ֻ���ڵ��õ�ʹ�òŴ��ڣ�����ͨ���еĳ�Ա�������ඨ��ʱ�ͷ����ڴ��ˣ�

#include <iostream>
using namespace std;
#include <string>

class Person1
{
    public:
        void func1()
        {

        }
};

class Person2
{
    public:
        void func2()
        {

        }
};

template <class T>
class Person    //���м�ʹ���� Person1��Person2�еĳ�Ա�����������ǲ������ģ���Ϊ��ģ���еĳ�Ա�����ڵ��òŷ����ڴ棻
{
public: //Ҫ�У���Ȼp���ܷ���fun1();
    T m;
    void fun1()
    {
        m.func1();
    }

    void fun2()
    {
        m.func2();
    }
};

void test()
{
    Person <Person1> p;
    p.fun1();
    // p.fun2();   //���뱨����Ϊһ�����øú������ͻᴴ���ڴ�
}

int main()
{
    test();
    system("pause");
    return 0;
}

