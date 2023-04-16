// 类模板中的成员函数与普通类中成员函数的区别
// 类模板中的成员函数只有在调用的使用才存在，而普通类中的成员函数在类定义时就分配内存了；

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
class Person    //类中既使用了 Person1与Person2中的成员函数，编译是不会出错的，因为类模板中的成员函数在调用才分配内存；
{
public: //要有，不然p不能访问fun1();
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
    // p.fun2();   //编译报错，因为一旦调用该函数，就会创建内存
}

int main()
{
    test();
    system("pause");
    return 0;
}

