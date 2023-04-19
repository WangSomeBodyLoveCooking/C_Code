#include "Template.h"

//  类模板与继承
// 子类继承父类，需要指定父类中模板的类型；
// 如果不指定，编译器无法确定为子类分配多大内存;
// 如果需要父类的类型参数化，则子类也需要成为模板类;

// 1. 定义一个模板类
template <class T>
class Base
{
    T a;
};

// 2. 定义一个子类继承父类
class Son : public Base<int>    // 子类继承模板父类，需要指定父类中模板类型；如果不指定，编译器无法确定子类的大小
{

};

// 3. 定义一个子类继承父类
template <class T, class T1>    // 如果需要将父类中的类型参数化，则子类也要成为模板类
class Girl : public Base<T>
{
    public: 
    void print()
    {
        cout << "T类型:" << typeid(T).name() << "\nT1类型" << typeid(T1).name() << endl;
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