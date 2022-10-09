// 静态成员变量和静态成员函数

// 对于静态成员变量：
/*
①所有对象共享一份静态成员变量（可以通过创建对象或类来访问）
②在编译阶段就已经分配了内存；
③需要在类内定义，在类外进行初始化；
④静态成员变量也是有权限限制的；
*/

//对于静态成员函数:
/*
①所有对象共享同一静态成员函数；（可以通过创建对象或类来访问）
②静态成员函数只能操作静态成员变量；（因为如果用类来访问静态成员函数，则不知道对象哪个对象的非静态成员变量）
*/

#include <iostream>

using namespace std;

class Person
{

public:
    static int age;
    int weight;

    static void func1()
    {
        age++;
        height++;
    }

private:
    static int height;
};

int Person ::age = 20;
int Person ::height = 170;

void func()
{
    Person p1;
    cout << p1.age << endl; //20
    cout << Person::age << endl;    //20
    p1.func1();
    Person::func1();
    cout << p1.age << endl; //22
    cout << Person::age << endl; //22
}

int main()
{
    func();
    system("pause");
    return 0;
}