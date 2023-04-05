// 3. 函数提高

#include <iostream>
using namespace std;

// 3.1 函数的默认参数

// int  functest(int a, int b = 10, int c = 20);    // 注：函数的默认参数，函数声明和实现中只能存在一个有默认参数的情况

int  functest(int a, int b = 10, int c = 20)    // 函数的默认参数
{
    return a + b + c;
}

// int  functest1(int a = 20, int b, int c)    // 注：函数形参中一个有默认参数，则从该形参开始往右的各个参数都要有默认参数
// {
//     return a + b + c;
// }


// 3.2 函数的占位符
int funcTest(int a, int = 10)    //函数占位符也可以有默认参数
{
    return a;
}

// 3.3 函数的重载   函数名相同，提高复用性
//重载三要素：
// 1. 函数作用域相同；
// 2.函数名相同；
// 3.函数形参不同：个数不同，类型不同，顺序不同；
// 4.函数返回值不能作为重载条件；
int funTest()
{
    return 0;
}

int funTest(int a)
{
    return 0;
}

int funTest(double a)
{
    return 0;
}

int funTest(int a, double b)
{
    return 0;
}

int funTest(double b, int a)
{
    return 0;
}

// 引用作为重载的条件
int funTest(int &a)
{
    return 0;
}

int funTest(const int &a)
{
    return 0;
}

// 默认参数做重载条件
// int funTest(int a, double b = 0.0)
// {
//     return 0;
// }

int main()
{
    int x = 0;
    x = functest(10);
    cout << x << endl;
    // x= functest1(20, 30);
    int &y = x;
    funcTest(y);
    funcTest(10);

    cout << x << endl;
    system("pause");
    return 0;
}