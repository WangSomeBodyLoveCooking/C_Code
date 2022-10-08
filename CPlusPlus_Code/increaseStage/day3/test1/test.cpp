#include <iostream>

using namespace std;

class Person
{
    public:
        Person()
        {
            cout << "Person默认构造函数" << endl;
        }

        Person(int age)
        {   
            cout << "Person有参构造函数" << endl;
        }

        Person(const Person &p)
        {
            cout << "Person拷贝构造函数" << endl;
        }

        ~Person()
        {
            cout << "Person析构函数" << endl;
        }

    private:
        int m_age;
};

// 析构函数调用三大场景
// ①用一个已经存在的对象来创建另一个对象
void test1()
{
    Person p1(10); //调用有参构造函数
    Person p2 = Person(p1); //调用拷贝构造函数
}

// ②作为函数形参传入
void dowork1(Person p)
{

}

void test2()
{
    Person p1 = 10; //调用有参构造函数
    dowork1(p1); //调用拷贝构造函数
}

// ③作为函数返回值
Person dowork2()
{
    Person p;   // 调用默认构造函数
    cout << (int)&p << endl;
    return p;   
}

void test3()
{
    Person p3 = dowork2();  //调用拷贝构造函数
    cout << (int)&p3 << endl;

}

int main()
{

    // test1();
    // test2();
    test3();
    system("pause");
    return 0;
}