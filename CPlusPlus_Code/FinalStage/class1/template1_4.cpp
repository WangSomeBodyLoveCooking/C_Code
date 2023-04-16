// 普通函数与函数模板的区别
//  普通函数可以发生隐式类型个转换；函数模板在使用自动类型推导时不会发生隐式类型转换，在使用显示指定类型时，会发生隐式类型转换，推荐使用显示指定类型

#include <iostream>

void func(int a)
{

}

template <typename T>
void func(T a, T b)
{

}

void test()
{
    int a = 10;
    int b = 10;
    char c = 'a';
    func(c);    //普通函数可以发生隐式类型转换
    // func(a, c);     // 函数模板，使用自动类型推导，无法发生隐式类型转换
    func<int>(a, c);    // 函数模板，使用显示指定类型，可以发生隐式类型转换，推荐使用！
}

int main()
{
    test();
    system("pause");
    return 0;
}