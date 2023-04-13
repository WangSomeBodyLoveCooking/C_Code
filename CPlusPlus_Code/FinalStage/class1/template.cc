#include <iostream>
using namespace std;
//模板
//1. 函数模板语法
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
    swapFunc(a, b); //自动类型推导
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    char c = 'c';
    char d = 'd';
    swapFunc<char>(c, d);   //显示指定类型
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

//2. 函数模板的注意事项
template <class T>
void func()
{
    cout << "这是一个模板" <<endl;
}

void test2()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    // swapFunc(a. c); // 自动类型推导必须要确定一个统一类型！！！

    // func(); //显示指定类型必须指定类型；
    func<int>();
}

int main()
{
    // test1();
    test2();
    system("pause");
    return 0;
}