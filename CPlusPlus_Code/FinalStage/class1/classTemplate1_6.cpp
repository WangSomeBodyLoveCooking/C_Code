#include "Template.h"

// ��ģ���еĳ�Ա��������ʵ����ӣ�template�����б�;ģ������б�

// 1. ��ģ��
template <class T1, class T2>
class Person
{
    public:
        // ��ģ�庯����������
        Person(T1 name, T2 age);
        void showPerson();
    private:
        T1 name;
        T2 age;
};

// ��ģ�庯������ʵ��
template <class T1, class T2>
Person<T1, T2> :: Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

template <class T1, class T2>
void Person<T1, T2> :: showPerson()
{
    cout << "name "  << this->name << "age" << this->age <<endl;
}

void test()
{
    Person <string, int> p("Tom", 100);
    p.showPerson();
}


int main()
{
    test();
    system("pause");
    return 0;
}