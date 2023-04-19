#include "Template.h"

//  ��ģ����̳�
// ����̳и��࣬��Ҫָ��������ģ������ͣ�
// �����ָ�����������޷�ȷ��Ϊ����������ڴ�;
// �����Ҫ��������Ͳ�������������Ҳ��Ҫ��Ϊģ����;

// 1. ����һ��ģ����
template <class T>
class Base
{
    T a;
};

// 2. ����һ������̳и���
class Son : public Base<int>    // ����̳�ģ�常�࣬��Ҫָ��������ģ�����ͣ������ָ�����������޷�ȷ������Ĵ�С
{

};

// 3. ����һ������̳и���
template <class T, class T1>    // �����Ҫ�������е����Ͳ�������������ҲҪ��Ϊģ����
class Girl : public Base<T>
{
    public: 
    void print()
    {
        cout << "T����:" << typeid(T).name() << "\nT1����" << typeid(T1).name() << endl;
    }
    T1 t;
};

void test()
{
    Son s;
    Girl<int, char> g;
    g.print();
}

int main()
{
    test();
    system("pause");
    return 0;
}