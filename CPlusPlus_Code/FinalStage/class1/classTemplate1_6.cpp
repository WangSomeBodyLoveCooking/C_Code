#include "Template.h"

// 类模板中的成员函数类外实现添加：template参数列表;模板参数列表

// 1. 类模板
template <class T1, class T2>
class Person
{
    public:
        // 类模板函数类内声明
        Person(T1 name, T2 age);
        void showPerson();
    private:
        T1 name;
        T2 age;
};

// 类模板函数类外实现
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